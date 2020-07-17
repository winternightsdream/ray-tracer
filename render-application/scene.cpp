#include "render-application/scene.hpp"
#include "math/constants.hpp"
#include "math/geometric.hpp"
#include "objects/base/material-interface.hpp"
#include "objects/hitables/sphere.hpp"
#include "objects/hitables/moving-sphere.hpp"
#include "objects/materials/dielectric.hpp"
#include "objects/materials/lambertian.hpp"
#include "objects/materials/metal.hpp"
#include "utility/random.hpp"
using objects::base::hitable_interface;
using objects::hitables::hitable_list;
using objects::hitables::sphere;
using objects::hitables::moving_sphere;
using objects::materials::dielectric;
using objects::materials::lambertian;
using objects::materials::metal;
using objects::primitives::hit_record;

namespace render_application
{

scene::scene()
    : m_world{nullptr}, m_background_colour{0.5, 0.7, 1.0}
{ }

scene::~scene()
{
    if (m_world)
    {
        delete m_world;
        m_world = nullptr;
    }
}

void scene::init_material_spheres()
{
    m_world = new hitable_list{
        new hitable_interface*[5]{
            new sphere{
                math::vec3{0.0f, 0.0f, -1.0f},
                0.5f,
                new lambertian{
                    math::vec3{0.1f, 0.2f, 0.5f}
                }
            },
            new sphere{
                math::vec3{0.0f, -100.5f, -1.0f},
                100.0f,
                new lambertian{
                    math::vec3{0.8f, 0.8f, 0.0f}
                }
            },
            new sphere{
                math::vec3{1.0f, 0.0f, -1.0f},
                0.5f,
                new metal{
                    math::vec3{0.8f, 0.8f, 0.8f},
                    0.0f
                }
            },
            new sphere{
                math::vec3{-1.0f, 0.0f, -1.0f},
                0.5f,
                new dielectric{
                    1.5f
                }
            },
            new sphere{
                math::vec3{-1.0f, 0.0f, -1.0f},
                -0.45f,
                new dielectric{
                    1.5f
                }
            }
        },
        5
    };
}

void scene::init_test_spheres()
{
    math::real R = cos(math::REAL_PI / 4.0f);
    m_world = new hitable_list{
        new hitable_interface*[2]{
            new sphere{
                math::vec3{-R, 0.0f, -1.0f},
                R,
                new lambertian{
                    math::vec3{0.0f, 0.0f, 1.0f}
                }
            },
            new sphere{
                math::vec3{R, 0.0f, -1.0f},
                R,
                new lambertian{
                    math::vec3{1.0f, 0.0f, 0.0f}
                }
            },
        },
        2
    };
}

void scene::init_random_scene()
{
    int n = 50000;
    hitable_interface** list = new hitable_interface*[n + 1];
    list[0] = new sphere{
        math::vec3{0.0f, -1000.0f, 0.0f},
        1000.0f,
        new lambertian{math::vec3{0.7f}}
    };

    int i = 1;
    for (int a = -10; a < 10; ++a)
    {
        for (int b = -10; b < 10; ++b)
        {
            math::real choose_mat = math::random_real();
            math::vec3 center{
                a + 0.9f * math::random_real(),
                0.2f,
                b + 0.9f * math::random_real()
            };
            if ((center - math::vec3{4.0f, 0.2f, 0.0f}).length() > 0.9f)
            {
                if (choose_mat < 0.75f)
                {
                    list[i++] = new sphere{
                        center,
                        0.2f,
                        new lambertian{
                            math::vec3{
                                math::random_real() * math::random_real(),
                                math::random_real() * math::random_real(),
                                math::random_real() * math::random_real()
                            }
                        }
                    };
                }
                else if (choose_mat < 0.8f)
                {
                    list[i++] = new moving_sphere{
                        center,
                        center + math::vec3{0.0f, 0.5f * math::random_real(), 0.0f},
                        0.0f,
                        1.0f,
                        0.2f,
                        new lambertian{
                            math::vec3{
                                math::random_real() * math::random_real(),
                                math::random_real() * math::random_real(),
                                math::random_real() * math::random_real()
                            }
                        }
                    };
                }
                else if (choose_mat < 0.95f)
                {
                    list[i++] = new sphere{
                        center,
                        0.2f,
                        new metal{
                            math::vec3{
                                0.5f * (1.0f + math::random_real()),
                                0.5f * (1.0f + math::random_real()),
                                0.5f * (1.0f + math::random_real())
                            },
                            0.5f * math::random_real()
                        }
                    };
                }
                else
                {
                    list[i++] = new sphere{
                        center, 0.2f, new dielectric{1.5f}
                    };
                }
            }
        }
    }

    list[i++] = new sphere{
        math::vec3{0.0f, 1.0f, 0.0f},
        1.0f,
        new dielectric{1.5f}
    };
    list[i++] = new sphere{
        math::vec3{-4.0f, 1.0f, 0.0f},
        1.0f,
        new lambertian{math::vec3{0.4f, 0.2f, 0.1f}}
    };
    list[i++] = new sphere{
        math::vec3{4.0f, 1.0f, 0.0f},
        1.0f,
        new metal{math::vec3{0.7f, 0.6f, 0.5f}, 0.0f}
    };

    m_world = new hitable_list{list, i};
}

math::vec3 scene::colour(const math::ray& r, int depth) const
{
    if (m_world == nullptr)
        return math::vec3{};
    hit_record rec;
    if (m_world->hit(r, 0.001f, math::REAL_MAX, rec))
    {
        math::ray scattered;
        math::vec3 attenuation;
        if (depth < 50 && rec.m_material->scatter(r, rec, attenuation, scattered))
        {
            return attenuation * colour(scattered, depth + 1);
        }
        return math::vec3{};
    }
    math::vec3 unit_direction = math::normalize(r.direction());
    math::real t = 0.5f * (unit_direction.y + 1.0f);
    return math::real(1.0f - t) * math::vec3{1.0f} + t * m_background_colour;
}

}  // namespace render_application
