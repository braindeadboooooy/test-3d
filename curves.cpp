#define _USE_MATH_DEFINES
#include <cmath>
#include "curves.h"


std::vector<double> Circle::point(double t) const {
    double x = radius_ * cos(t);
    double y = radius_ * sin(t);
    double z = 0.0;
    return { x, y, z };
}

std::vector<double> Circle::derivative(double t) const {
    double x_dot = -radius_ * sin(t);
    double y_dot = radius_ * cos(t);
    double z_dot = 0.0;
    return { x_dot, y_dot, z_dot };
}

std::vector<double> Ellipse::point(double t) const {
    double x = bRad_ * cos(t);
    double y = smallRad_ * sin(t);
    double z = 0.0;
    return { x, y, z };
}

std::vector<double> Ellipse::derivative(double t) const {
    double x_dot = -bRad_ * sin(t);
    double y_dot = smallRad_ * cos(t);
    double z_dot = 0.0;
    return { x_dot, y_dot, z_dot };
}

std::vector<double> Helix::point(double t) const {
    double x = radius_ * cos(t);
    double y = radius_ * sin(t);
    double z = angle_ * t / (2 * M_PI);
    return { x, y, z };
}

std::vector<double> Helix::derivative(double t) const {
    double x_dot = -radius_ * sin(t);
    double y_dot = radius_ * cos(t);
    double z_dot = angle_ / (2 * M_PI);
    return { x_dot, y_dot, z_dot };
}
