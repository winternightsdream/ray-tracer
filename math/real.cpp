#include "./real.hpp"
#include <chrono>
#include <random>

namespace math
{

real random_real()
{
	#ifndef _SEED_RANDOM_
	static unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	#else
	static unsigned seed = _SEED_RANDOM_;
	#endif
	static std::mt19937 s_gen(seed);
	return real(((double)s_gen()) / (((double)s_gen.max()) + 1.0));
}

real random_real(const real& max)
{
	#ifndef _SEED_RANDOM_MAX_
	static unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	#else
	static unsigned seed = _SEED_RANDOM_MAX_;
	#endif
	static std::mt19937 s_gen_max(seed);
	return real(((double)s_gen_max()) / (((double)s_gen_max.max()) + 1.0));
}

real random_real(const real& min, const real& max)
{
	#ifndef _SEED_RANDOM_MIN_MAX_
	static unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	#else
	static unsigned seed = _SEED_RANDOM_MIN_MAX_;
	#endif
	static std::mt19937 s_gen_min_max(seed);
	return real(((double)s_gen_min_max()) / (((double)s_gen_min_max.max()) + 1.0));
}

}//end math