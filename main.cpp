#include <iostream>
#include <fstream>
using namespace std;

#include "include/Vector2.h"
#include "include/Trajectory_Generation.h"
Trajectory_Generation tg;

#include "include/matplotlibcpp.h"
#include "include/My_CSV.h"
CSV csv;

void plot(double *_x, double *_y, int n);

#define DATA_WIDTH 3
#define DATA_HEIGHT 150

// dataformat: t, x, y
double data[DATA_HEIGHT][DATA_WIDTH] = {0};
double data_for_plot_x[DATA_HEIGHT] = {0};
double data_for_plot_y[DATA_HEIGHT] = {0};

Vector2 p_s(2, -4);  // 始点
Vector2 p_e(-10, 6); // 終点

int main(void)
{
    double pitch = 10;
    for (int i = 0; i <= pitch; i++)
    {
        double t = i * (1 / pitch);
        Vector2 trajectory(0, 0);

        // 直線補間
        // trajectory = tg.linearInterpolation(p_s, p_e, t);

        // 円弧補間
        trajectory = tg.circularInterpolation(p_s, p_e, 10, 1, t);

        data[i][0] = t;
        data[i][1] = trajectory.x;
        data[i][2] = trajectory.y;

        data_for_plot_x[i] = data[i][1];
        data_for_plot_y[i] = data[i][2];

        cout << t << "\t" << trajectory.x << "\t" << trajectory.y << endl;
    }

    csv.write(*data, DATA_HEIGHT, DATA_WIDTH);

    plot(data_for_plot_x, data_for_plot_y, pitch);
    return 0;
}

namespace plt = matplotlibcpp;
void plot(double *_x, double *_y, int n)
{
    plt::xlim(-15, 15);
    plt::ylim(-15, 15);

    std::vector<double>
        x(n),
        y(n);

    for (int i = 0; i < n; i++)
    {
        x[i] = _x[i];
        y[i] = _y[i];
    }

    plt::plot(x, y, "o");
    plt::show();
}