#ifndef UTILITY_RANDOM_HPP_
#define UTILITY_RANDOM_HPP_
#include "math/vec3.hpp"

namespace utility
{
namespace random
{

    math::vec3 random_in_sphere();
    math::vec3 random_in_unit_disk();

}  // namespace random
}  // namespace utility

#endif  // UTILITY_RANDOM_HPP_
