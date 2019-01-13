#ifndef _MY_CSV_H_
#define _MY_CSV_H_

#include <iostream>
#include <fstream>

class CSV
{
  public:
    void write(double *, int, int);
};

void CSV::write(double *a, int h, int w)
{
    std::ofstream ofs("Data.csv");

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            ofs << (double)a[i * w + j] << ",";
        }
        ofs << std::endl;
    }
}

#endif