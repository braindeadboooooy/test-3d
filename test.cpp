#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <vector>
#include "curves.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <omp.h>


int main() {
    srand(time(nullptr));
    

    // random filling
    std::vector<Curve*> curves;
    for (int i = 0; i < 10; ++i) {
        double rad = double(rand() % 10 + 1);
        double smallrad = double(rand() % 5 + 1);
        double pitch = double(rand() % 5 + 1);
        int choice = rand() % 3;

        if (choice == 0) {
            curves.push_back(new Circle(rad));
        }
        else if (choice == 1) {
            curves.push_back(new Ellipse(rad, smallrad));
        }
        else {
            curves.push_back(new Helix(rad, pitch));
        }
    }


    // Print coordinates of points and derivatives of all curves in the container at t=PI/4.
    double t = M_PI / 4.0;
    for (const auto& curve : curves) {
        std::vector<double> point = curve->point(t);
        std::vector<double> derivative = curve->derivative(t);
        std::cout << "curve type: " << curve->getType() << std::endl;
        std::cout << "curve radius: " << curve->radius() << std::endl;
        std::cout << "coordinates of points: {" << point[0] << ", " << point[1] << ", " << point[2] << "}" << std::endl;
        std::cout << "derivatives: (" << derivative[0] << ", " << derivative[1] << ", " << derivative[2] << ")" << std::endl;
        std::cout << std::endl;
    }


    // only circles
    std::vector<Circle*> circles;
    for (const auto& curve : curves) {
        if (dynamic_cast<Circle*>(curve)) {
            circles.push_back(static_cast<Circle*>(curve));
        }
    }

    // sort circles container
    std::sort(circles.begin(), circles.end(), [](const Circle* a, const Circle* b) {
        return a->radius() < b->radius();
        });

    // sum openmp? 
    double totalRadiusSum = 0.0;
#pragma omp parallel for reduction(+:totalSum)
    for (int i = 0; i < circles.size(); i++) {
        totalRadiusSum += circles[i]->radius();
    }

    std::cout << "total sum of radii: " << totalRadiusSum << std::endl;


    for (Curve* curve : curves) {
        delete curve;
    }

    return 0;
}