#include "render-application/renderer.hpp"
#include "utility/threading/thread-pool.hpp"

int main(int argc, char** argv)
{
    utility::threading::ThreadPool::initialize(4);

    render_application::renderer tracer;
    int ret = tracer.render();

    utility::threading::ThreadPool::finialize();
    return ret;
}
