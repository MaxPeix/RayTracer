/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Camera
*/

#include "Camera.hpp"
#include <cmath>

RayTracer::Camera::Camera() : origin(0.5, 0.5, 0), screen(Math::Point3D(0, 0, -1), Math::Vector3D(1, 0, 0), Math::Vector3D(0, 1, 0))
{
}

RayTracer::Camera::~Camera()
{
}

RayTracer::Camera::Camera(Math::Point3D origin, Rectangle3D screen) : origin(origin), screen(screen)
{
}

RayTracer::Camera::Camera(const Camera &camera) : origin(camera.origin), screen(camera.screen)
{
}

RayTracer::Camera::Camera(Camera &&camera) : origin(camera.origin), screen(camera.screen)
{
}

RayTracer::Camera &RayTracer::Camera::operator=(const Camera &camera)
{
    this->origin = camera.origin;
    this->screen = camera.screen;
    return *this;
}

RayTracer::Camera &RayTracer::Camera::operator=(Camera &&camera)
{
    this->origin = camera.origin;
    this->screen = camera.screen;
    return *this;
}

RayTracer::Ray RayTracer::Camera::ray(double u, double v)
{
    Math::Point3D point = this->screen.pointAt(u, v);
    Math::Vector3D direction((point - this->origin).getX(), (point - this->origin).getY(), ((point - this->origin).getZ()));
    return Ray(this->origin, direction);
}

void RayTracer::Camera::translate(Math::Vector3D vector)
{
    this->origin = this->origin + vector;
    this->screen.translate(vector);
}
