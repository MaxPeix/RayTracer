/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Rectangle3D
*/

#pragma once
#include "Point3D.hpp"
#include "Vector3D.hpp"
#include "Ray.hpp"
#include "Color.hpp"
#include "IPrimitives.hpp"
#include "ILights.hpp"

namespace RayTracer {
    namespace Primitives {
        class Rectangle3D : public IPrimitives {
            public:
                Rectangle3D();
                ~Rectangle3D();
                Rectangle3D(
                    Math::Point3D origin,
                    Math::Vector3D bottom_side,
                    Math::Vector3D left_side,
                    Render::Color color
                );
                Rectangle3D(const Rectangle3D &rectangle);
                Rectangle3D(Rectangle3D &&rectangle);
                Rectangle3D &operator=(const Rectangle3D &rectangle);
                Rectangle3D &operator=(Rectangle3D &&rectangle);
                double getIntersectionPoint(View::Ray ray) override;
                bool hits(View::Ray ray) override;
                Render::Color computeColor(
                    View::Ray ray,
                    std::vector<std::unique_ptr<ILights>> &lights
                ) override;
                Math::Point3D pointAt(double u, double v);
                void translate(Math::Vector3D translation) override;
                void rotate(Math::Vector3D rotation, double angle) override;
                void scale(double factor) override;

            protected:
            private:
                Math::Point3D origin;
                Math::Vector3D bottom_side;
                Math::Vector3D left_side;
                Render::Color color;
        };
    };
};
