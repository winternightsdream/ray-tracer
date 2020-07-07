#ifndef _UTILITY_THREADING_THREAD_POOL_HPP_
#define _UTILITY_THREADING_THREAD_POOL_HPP_

#include <queue>
#include <mutex>

namespace utility
{
namespace threading
{

class Task;
class PoolThread;

class ThreadPool
{
public:
	inline static ThreadPool& get_thread_pool() { return m_instance; }
	static bool initialize(int num_threads);
	static void finialize();

	void enque_task(Task* task);

private:
	friend class PoolThread;

	ThreadPool();
	ThreadPool(const ThreadPool&) = delete;
	ThreadPool(ThreadPool&&) = delete;
	~ThreadPool();

	ThreadPool& operator=(const ThreadPool&) = delete;
	ThreadPool& operator=(ThreadPool&&) = delete;

	bool init(int num_threads);
	void enque_available_thread(PoolThread*);
	void assign_task_to_thread(Task*, PoolThread*);
	void cleanup();
	
	static ThreadPool m_instance;

	std::queue<PoolThread*>	m_available_pool;
	std::queue<Task*>		m_waiting_tasks;
	PoolThread*				m_threads;
	std::mutex				m_access_control;
	int						m_num_threads;
};

} // namespace threading
} // namespace utility

#endif // _UTILITY_THREADING_THREAD_POOL_HPP_