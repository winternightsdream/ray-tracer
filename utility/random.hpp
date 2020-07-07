#ifndef _UTILITY_RANDOM_HPP_
#define _UTILITY_RANDOM_HPP_
#include "math/vec3.hpp"

namespace utility
{
namespace random
{

	math::vec3 random_in_sphere();
	math::vec3 random_in_unit_disk();

}//end random
}//end utility

#endif//end _UTILITY_RANDOM_H_