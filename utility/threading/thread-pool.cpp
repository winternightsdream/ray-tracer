#include "./thread-pool.hpp"
#include "./pool-thread.hpp"

namespace utility
{
namespace threading
{

ThreadPool ThreadPool::m_instance;

bool ThreadPool::initialize(int num_threads)
{
	return m_instance.init(num_threads);
}

void ThreadPool::enque_task(Task* task)
{
	if (!m_available_pool.empty())
	{
		PoolThread* thread = m_available_pool.front();
		m_available_pool.pop();
		assign_task_to_thread(task, thread);
	}
	else
	{
		m_waiting_tasks.push(task);
	}
}

void ThreadPool::finialize()
{
	m_instance.cleanup();
}

ThreadPool::ThreadPool() : m_threads{ nullptr }, m_num_threads{ 0 }
{ }

ThreadPool::~ThreadPool()
{ }

bool ThreadPool::init(int num_threads)
{
	if (0 < m_num_threads || nullptr != m_threads)
		return false;

	m_num_threads = num_threads;

	m_threads = new PoolThread[m_num_threads];
	for (int i = 0; i < m_num_threads; ++i)
	{
		if (!m_threads[i].initialize(this))
		{
			cleanup();
			return false;
		}
	}

	return true;
}

void ThreadPool::enque_available_thread(PoolThread* thread_p)
{
	if (!m_waiting_tasks.empty())
	{
		std::lock_guard<std::mutex> lock(m_access_control);
		Task* task = m_waiting_tasks.front();
		m_waiting_tasks.pop();
		assign_task_to_thread(task, thread_p);
	}
	else
	{
		m_available_pool.push(thread_p);
	}
}

void ThreadPool::assign_task_to_thread(Task* task, PoolThread* thread_p)
{
	thread_p->assign_task(task);
	thread_p->m_sync_control.notify();
}

void ThreadPool::cleanup()
{
	for (int i = 0; i < m_num_threads; ++i)
		m_threads[i].cancel();

	for (int i = 0; i < m_num_threads; ++i)
		m_threads[i].finialize();

	delete[] m_threads;
	m_threads = nullptr;
	m_num_threads = 0;

	while (!m_available_pool.empty())
		m_available_pool.pop();

	while (!m_waiting_tasks.empty())
		m_waiting_tasks.pop();
}

} // namespace threading
} // namespace utility
