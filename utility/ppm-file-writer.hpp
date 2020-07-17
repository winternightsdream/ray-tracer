#ifndef UTILITY_PPM_FILE_WRITER_HPP_
#define UTILITY_PPM_FILE_WRITER_HPP_
#include <fstream>
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
    std::ofstream   m_file_handle;
    bool            m_open = false;
};

}  // namespace utility

#endif  // UTILITY_PPM_FILE_WRITER_HPP_
