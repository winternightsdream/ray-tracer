#ifndef _UTILITY_THREADING_SEMAPHORE_HPP_
#define _UTILITY_THREADING_SEMAPHORE_HPP_

#include <mutex>
#include <condition_variable>

namespace utility
{
namespace threading
{

class Semaphore
{
public:

	Semaphore() : m_cnt{0}
	{}

	inline void notify()
	{
		++m_cnt;
		m_cndt_var.notify_one();
	}

	inline void wait()
	{
		std::unique_lock<std::mutex> lock{m_mtx};
		while (0 == m_cnt)
			m_cndt_var.wait(lock);

		--m_cnt;
	}

private:

	std::mutex				m_mtx;
	std::condition_variable	m_cndt_var;
	uint8_t					m_cnt;
};

}// end namespace threading
}// end namespace utility

#endif // _UTILITY_THREADING_SEMAPHORE_HPP_