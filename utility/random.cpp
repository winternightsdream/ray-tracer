#include "utility/random.hpp"
#include "math/geometric.hpp"

namespace utility
{
namespace random
{

math::vec3 random_in_sphere()
{
    math::vec3 p;
    do
    {
        p = 2.0f * math::vec3{math::random_real(), math::random_real(), math::random_real()} - math::vec3{1.0f};
    } while (p.squared_length() >= 1.0f);
    return p;
}

math::vec3 random_in_unit_disk() {
    math::vec3 p;
    do {
        p = 2.0f * math::vec3(math::random_real(), math::random_real(), 0.0f) - math::vec3(1.0f, 1.0f, 0.0f);
    } while (math::dot(p, p) >= 1.0f);
    return p;
}

}  // namespace random
}  // namespace utility
