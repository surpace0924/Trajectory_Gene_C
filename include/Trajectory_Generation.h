#ifndef Trajectory_Generation_h
#define Trajectory_Generation_h
#include "Vector2.h"

class Trajectory_Generation
{
  public:
    Vector2 linearInterpolation(Vector2 s, Vector2 e, double t);
    Vector2 circularInterpolation(Vector2 s, Vector2 e, double r, int r_dir, double t);
};

Vector2 Trajectory_Generation::linearInterpolation(Vector2 s, Vector2 e, double t)
{
    Vector2 path(0, 0);
    path.x = s.x + (e.x - s.x) * t;
    path.y = s.y + (e.y - s.y) * t;
    return path;
}

// 始点，終点，半径，0:時計 1:反時計，時間
Vector2 Trajectory_Generation::circularInterpolation(Vector2 s, Vector2 e, double r, int r_dir, double t)
{
    Vector2 path(0, 0); // tでの経路上の座標
    Vector2 m(0, 0);    // 始点と終点の中点
    Vector2 c(0, 0);    // 円弧の中心点

    double arg_s, arg_e, omega, angle;

    double d, l1, dx, dy;
    m.x = (s.x + e.x) * 0.5;
    m.y = (s.y + e.y) * 0.5;
    l1 = (e.x - m.x) * (e.x - m.x) + (e.y - m.y) * (e.y - m.y);

    if (r * r >= l1)
    {
        d = sqrt(r * r / l1 - 1.0);
        dx = d * (e.y - m.y);
        dy = d * (e.x - m.x);

        // 円弧の中心点は2つ出るのでCW，CCWで振り分け
        if (r_dir == 0)
        {
            c.x = m.x + dx;
            c.y = m.y - dy;
        }
        else
        {
            c.x = m.x - dx;
            c.y = m.y + dy;
        }

        arg_s = atan2(s.y - c.y, s.x - c.x);
        arg_e = atan2(e.y - c.y, e.x - c.x);
        omega = arg_e - arg_s;
        angle = omega * t + arg_s;

        path.x = r * cos(angle) + c.x;
        path.y = r * sin(angle) + c.y;
    }
    else
    {
    }

    return path;
}

#endif