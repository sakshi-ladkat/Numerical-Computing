#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "Curve.hpp"

using namespace std;

double Curve::LeastSquarePowerFit(const Curve second)
{
    Curve ti(row);
    Curve zi(row);
    Curve sqti(row);
    Curve tizi(row);
    Curve yi(row);

    double sum_ti = 0;
    double sum_zi = 0;
    double sum_sqti = 0;
    double sum_tizi = 0;

    ofstream dataFile("LeastSquarePowerFit.txt");

    dataFile << "# xi fi fitted_y\n";

    for (int i = 0; i < row; i++)
    {
        ti[i] = log(values[i]);
        zi[i] = log(second.values[i]);
        sqti[i] = ti[i] * ti[i];
        tizi[i] = ti[i] * zi[i];

        sum_ti += ti[i];
        sum_zi += zi[i];
        sum_sqti += sqti[i];
        sum_tizi += tizi[i];
    }

    double b = (row * sum_tizi - sum_ti * sum_zi) / (row * sum_sqti - sum_ti * sum_ti);
    double a = (sum_zi - b * sum_ti) / row;
    double A = exp(a);

    cout << "\nFitted Power Model: y = " << A << " * x^" << b << "\n";

    double rms_sum = 0;

    cout << "\n------------------------------------------------------------\n";
    cout << "xi\tfi\tln(fi)\tln(xi)^2\tln(xi)*ln(fi)\tyi(est)\t(fi - yi)^2\n";
    cout << "------------------------------------------------------------\n";

    for (int i = 0; i < row; i++)
    {
        yi[i] = A * pow(values[i], b);
        double diff_sq = pow(second.values[i] - yi[i], 2);
        rms_sum += diff_sq;

        dataFile << fixed;
        dataFile.precision(4);
        dataFile << values[i] << " " << second.values[i] << " " << yi[i] << "\n";

        cout << fixed << setprecision(4)
             << values[i] << "\t" << second.values[i] << "\t" << zi[i] << "\t"
             << sqti[i] << "\t" << tizi[i] << "\t" << yi[i] << "\t" << diff_sq << endl;
    }

    dataFile.close();

    double RMS = sqrt(rms_sum / row);

    cout << "------------------------------------------------------------\n";
    cout << "RMS Error = " << RMS << endl;

    return RMS;
}
