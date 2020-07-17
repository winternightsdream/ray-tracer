#ifndef RENDER_APPLICATION_SCENE_HPP_
#define RENDER_APPLICATION_SCENE_HPP_
#include "objects/hitables/hitable-list.hpp"

namespace render_application
{

class scene
{
public:
    scene();
    ~scene();
    void init_material_spheres();
    void init_test_spheres();
    void init_random_scene();
    math::vec3 colour(const math::ray& r, int depth = 0) const;

private:
    objects::hitables::hitable_list*    m_world;
    math::vec3                          m_background_colour;
};

}  // namespace render_application

#endif  // RENDER_APPLICATION_SCENE_HPP_
