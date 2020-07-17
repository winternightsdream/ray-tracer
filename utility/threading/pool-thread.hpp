#ifndef UTILITY_THREADING_POOL_THREAD_HPP_
#define UTILITY_THREADING_POOL_THREAD_HPP_

#include <thread>
#include "./semaphore.hpp"

namespace utility
{
namespace threading
{

class Task;
class ThreadPool;

class PoolThread
{
private:
    friend class ThreadPool;

    PoolThread();
    ~PoolThread();

    PoolThread(const PoolThread&) = delete;
    PoolThread(PoolThread&&) = delete;
    PoolThread& operator=(const PoolThread&) = delete;
    PoolThread& operator=(PoolThread&&) = delete;

    bool initialize(ThreadPool* owner);
    void become_idle();
    void run();
    void assign_task(Task* task);
    void cancel();
    void finialize();

    Semaphore   m_sync_control;
    std::thread m_thread;
    Task*       m_task;
    ThreadPool* m_owner;
    bool        m_canceled;
};

}  // namespace threading
}  // namespace utility

#endif  // UTILITY_THREADING_POOL_THREAD_HPP_
