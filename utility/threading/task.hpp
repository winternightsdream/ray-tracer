#ifndef UTILITY_THREADING_TASK_HPP_
#define UTILITY_THREADING_TASK_HPP_
#include <functional>

namespace utility
{
namespace threading
{

class Task
{
 public:
    static Task run(const std::function<void()>& action);

    explicit Task(const std::function<void()>& action);
    ~Task();
    Task(const Task& other);
    Task(Task&& other);
    Task& operator=(const Task& other);
    Task& operator=(Task&& other);

    void start();
    bool is_done() const;
    bool is_running() const;

 private:
    friend class PoolThread;

    void execute();

    std::function<void()>   m_action;

    bool m_started;
    bool m_finished;
};

}  // namespace threading
}  // namespace utility

#endif  // UTILITY_THREADING_TASK_HPP_
