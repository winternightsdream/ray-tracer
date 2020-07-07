#include "./pool-thread.hpp"
#include <utility>
#include "./task.hpp"
#include "./thread-pool.hpp"

namespace utility
{
namespace threading
{

PoolThread::PoolThread() : m_owner{nullptr}, m_canceled{false}, m_task{nullptr}
{ }

PoolThread::~PoolThread()
{ }

bool PoolThread::initialize(ThreadPool* owner)
{
	m_owner = owner;

	become_idle();

	m_thread = std::thread(&PoolThread::run, this);

	return true;
}

void PoolThread::become_idle()
{
	m_owner->enque_available_thread(this);
}

void PoolThread::run()
{
	while (!m_canceled)
	{
		m_sync_control.wait();

		if (m_task && !m_canceled)
		{
			m_task->execute();
			m_task = nullptr;
		}

		if (!m_canceled)
			become_idle();
	}
}

void PoolThread::assign_task(Task* task)
{
	m_task = task;
}

void PoolThread::cancel()
{
	m_canceled = true;
}

void PoolThread::finialize()
{
	m_sync_control.notify();
	
	if (m_thread.joinable())
		m_thread.join();

	m_task = nullptr;
	m_owner = nullptr;
}

} // namespace threading
} // namespace utility
