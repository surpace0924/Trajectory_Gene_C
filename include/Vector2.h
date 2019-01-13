#ifndef Vector_2_h
#define Vector_2_h

//#include "GenericFunctions.h"
#include <math.h>
#define guard(x, min, max) (x > max ? max : x < min ? min : x)

class Vector2
{

  public:
    Vector2();
    Vector2(double vx, double vy);

    // function
    void set(double vx, double vy);
    void setPolarCoordinate(double radius, double angle);
    double getMagnitude();
    double getAngle();
    void normalize();
    Vector2 getNormalized();
    void rotate(double angle);
    Vector2 getRotated(double angle);

    // static function
    static double getDot(Vector2 a, Vector2 b);
    static double getAngle(Vector2 a, Vector2 b);
    static double getDistance(Vector2 a, Vector2 b); // = (b-a).getMagnitude()
    static Vector2 leap(Vector2 a, Vector2 b, double t);
    //static leapUnclamped(Vector2 a, Vector2 b, double t);
    //static Vector2 sLeap(Vector2 a, Vector2 b, double t);

    // constatnt vector
    static Vector2 zero()
    {
        return Vector2(0.0, 0.0);
    }

    static Vector2 up()
    {
        return Vector2(0.0, 1.0);
    }

    static Vector2 down()
    {
        return Vector2(0.0, -1.0);
    }

    static Vector2 right()
    {
        return Vector2(1.0, 0.0);
    }

    static Vector2 left()
    {
        return Vector2(-1.0, 0.0);
    }

    // operator
    Vector2 &operator=(const Vector2 &v)
    {
        x = v.x;
        y = v.y;

        return *this;
    }

    bool operator==(const Vector2 &v) const
    {
        return (x == v.x) && (y == v.y);
    }

    bool operator!=(const Vector2 &v) const
    {
        return !((x == v.x) && (y == v.y));
    }

    Vector2 operator+(const Vector2 &v)
    {
        return Vector2(x + v.x, y + v.y);
    }

    Vector2 operator-(const Vector2 &v)
    {
        return Vector2(x - v.x, y - v.y);
    }

    Vector2 operator*(double value)
    {
        return Vector2(x * value, y * value);
    }

    Vector2 operator/(double value)
    {
        return Vector2(x / value, y / value);
    }

    Vector2 &operator+=(const Vector2 &v)
    {
        x += v.x;
        y += v.y;

        return *this;
    }

    Vector2 &operator-=(const Vector2 &v)
    {
        x -= v.x;
        y -= v.y;

        return *this;
    }

    Vector2 &operator*=(double value)
    {
        x *= value;
        y *= value;

        return *this;
    }

    Vector2 &operator/=(double value)
    {
        x /= value;
        y /= value;

        return *this;
    }

  public:
    double x, y;
};

Vector2::Vector2()
{
    set(0.0f, 0.0f);
}

Vector2::Vector2(double vx, double vy)
{
    set(vx, vy);
}

void Vector2::set(double vx, double vy)
{
    x = vx;
    y = vy;
}

void Vector2::setPolarCoordinate(double radius, double angle)
{
    x = radius * cos(angle);
    y = radius * sin(angle);
}

double Vector2::getMagnitude()
{
    return sqrt(x * x + y * y);
}

double Vector2::getAngle()
{
    return atan2(y, x);
}

void Vector2::normalize()
{
    float m = getMagnitude();
    x /= m;
    y /= m;
}

Vector2 Vector2::getNormalized()
{
    Vector2 r(x, y);
    r.normalize();
    return r;
}

void Vector2::rotate(double angle)
{
    double v[2] = {x, y};
    x = v[0] * cos(angle) - v[1] * sin(angle);
    y = v[0] * sin(angle) + v[1] * cos(angle);
}

Vector2 Vector2::getRotated(double angle)
{
    Vector2 r(x, y);
    r.rotate(angle);
    return r;
}

double Vector2::getDot(Vector2 a, Vector2 b)
{
    return (a.x * b.x + a.y * b.y);
}

double Vector2::getAngle(Vector2 a, Vector2 b)
{
    double value = getDot(a, b) / (a.getMagnitude() * b.getMagnitude());
    return acos(value);
}

double Vector2::getDistance(Vector2 a, Vector2 b)
{
    Vector2 v = (b - a);
    return v.getMagnitude();
}

Vector2 Vector2::leap(Vector2 a, Vector2 b, double t)
{
    t = guard(t, 0.0, 1.0);
    Vector2 v = a;
    v.x = (b.x - a.x) * t;
    v.y = (b.y - a.y) * t;
    return v;
}
#endif //Vector_2_h
