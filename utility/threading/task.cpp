#include "utility/threading/task.hpp"
#include <utility>
#include "utility/threading/thread-pool.hpp"

namespace utility
{
namespace threading
{

Task Task::run(const std::function<void()>& action)
{
    Task task{action};
    task.start();
    return task;
}

Task::Task(const std::function<void()>& action) : m_action{action}, m_started{false}, m_finished{false}
{ }

Task::~Task()
{ }

Task::Task(const Task& other) : m_action{other.m_action}, m_started{other.m_started}, m_finished{other.m_finished}
{ }

Task::Task(Task&& task) : m_action{std::move(task.m_action)}, m_started{std::move(task.m_started)}, m_finished{std::move(task.m_finished)}
{ }

Task& Task::operator=(const Task& other)
{
    m_action = other.m_action;
    m_started = other.m_started;
    m_finished = other.m_finished;

    return *this;
}

Task& Task::operator=(Task&& task)
{
    m_action = std::move(task.m_action);
    m_started = std::move(task.m_started);
    m_finished = std::move(task.m_finished);

    return *this;
}

void Task::start()
{
    ThreadPool::get_thread_pool().enque_task(this);
}

bool Task::is_done() const
{
    return m_started && m_finished;
}

bool Task::is_running() const
{
    return m_started && !m_finished;
}

void Task::execute()
{
    m_started = true;
    m_action();
    m_finished = true;
}

}  // namespace threading
}  // namespace utility
