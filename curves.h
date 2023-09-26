#ifndef CURVES_H
#define CURVES_H

#include <vector>
#include <string>

class Curve {
public:
    virtual ~Curve() {}
    virtual double radius() const = 0;
    virtual std::vector<double> point(double t) const = 0;
    virtual std::vector<double> derivative(double t) const = 0;
    virtual std::string getType() const = 0;
};

class Circle : public Curve {
public:
    Circle(double radius) : radius_(radius) {}
    double radius() const override { return radius_; }
    std::vector<double> point(double t) const override;
    std::vector<double> derivative(double t) const override;
    std::string getType() const override { return "Circle"; };

private:
    double radius_;
};

class Ellipse : public Curve {
public:
    Ellipse(double bigRad, double smallRad) : bRad_(bigRad), smallRad_(smallRad) {}
    double radius() const override { return smallRad_; }
    std::vector<double> point(double t) const override;
    std::vector<double> derivative(double t) const override;
    std::string getType() const override { return "Ellipse"; };

private:
    double bRad_;
    double smallRad_;
};

class Helix : public Curve {
public:
    Helix(double radius, double angle) : radius_(radius), angle_(angle) {}
    double radius() const override { return radius_; }
    std::vector<double> point(double t) const override;
    std::vector<double> derivative(double t) const override;
    std::string getType() const override { return "Helix"; };


private:
    double radius_;
    double angle_;
};

#endif 
