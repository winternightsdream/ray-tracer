#ifndef _UTILITY_PPM_FILE_WRITER_HPP_
#define _UTILITY_PPM_FILE_WRITER_HPP_
#include <fstream>
#include <mutex>
#include "math/vec3.hpp"

namespace utility
{

class PpmFileWriter
{
public:
	bool open_file(char const * const file_path, int width, int height);
	bool write(int x, int y, math::vec3 colour);
	bool flush();
	bool is_open();
	bool close_file();

private:
	std::ofstream	m_file_handle;
	bool			m_open = false;
};

}//end utility

#endif//end _UTILITY_PPM_FILE_WRITER_HPP_