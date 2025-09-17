#include <iostream>
#include <cmath>
#include "Curve.hpp"

using namespace std;

double Curve::LeastSquareExponential(const Curve second)
{
    Curve sqxi(row);
    Curve zi(row);
    Curve xizi(row);
    Curve yi(row);

    double sum_xi = 0;
    double sum_zi = 0;
    double sum_sqxi = 0;
    double sum_xizi = 0;

    ofstream dataFile("LeastSquareExponential.txt");

    dataFile << "# xi fi fitted_y\n";

    for (int i = 0; i < row; i++)
    {
        zi[i] = log(second.values[i]);
        sqxi[i] = values[i] * values[i];
        xizi[i] = values[i] * zi[i];

        sum_xi += values[i];
        sum_zi += zi[i];
        sum_sqxi += sqxi[i];
        sum_xizi += xizi[i];
    }

    double a = ((row * sum_xizi) - (sum_xi * sum_zi)) / ((row * sum_sqxi) - (sum_xi * sum_xi));
    double b = (sum_zi - (a * sum_xi)) / row;
    double c = exp(b);

    cout << "\n";
    cout << "Fitted exponential model: y = " << c << " * e^(" << a << " * x)\n";

    double rms_sum = 0;

    cout << "\n------------------------------------------------------------\n";
    cout << "xi\tfi\tzi=ln(fi)\txi^2\txi*zi\tyi(est)\t(fi-yi)^2\n";
    cout << "------------------------------------------------------------\n";

    for (int i = 0; i < row; i++)
    {
         yi[i] = c * exp(a * values[i]);
        double diff_sq = pow(second.values[i] - yi[i], 2);
        rms_sum += diff_sq;

        dataFile << fixed;
        dataFile.precision(4);
        dataFile << values[i] << " " << second.values[i] << " " << yi[i] << "\n";

        cout << fixed;
        cout.precision(4);
        cout << values[i] << "\t" << second.values[i] << "\t" << zi[i] << "\t" << sqxi[i]
             << "\t" << xizi[i] << "\t" << yi[i]<< "\t" << diff_sq << endl;
    }

    double RMS = sqrt(rms_sum / row);
    cout << "------------------------------------------------------------\n";
    cout << "RMS Error = " << RMS << endl;

    return RMS;
}
