#include <iostream>
#include <cmath>
#include "Curve.hpp"
using namespace std;

double Curve::LeastSquareParabola(const Curve second)
{
    Curve sqxi(row);
    Curve cuxi(row);
    Curve quxi(row);
    Curve xifi(row);
    Curve xi2fi(row);
    Curve yi(row);

    double sum_xi = 0;
    double sum_fi = 0;
    double sum_sqxi = 0;
    double sum_xifi = 0;
    double sum_cuxi = 0;
    double sum_quxi = 0;
    double sum_xi2fi = 0;

    ofstream dataFile("LeastSquareParabola.txt");

    dataFile << "# xi fi fitted_y\n";

    for (int i = 0; i < row; i++)
    {
        sqxi[i] = values[i] * values[i];
        cuxi[i] = sqxi[i] * values[i];
        quxi[i] = cuxi[i] * values[i];
        xifi[i] = values[i] * second.values[i];
        xi2fi[i] = sqxi[i] * second.values[i];

        sum_xi += values[i];
        sum_fi += second.values[i];
        sum_sqxi += sqxi[i];
        sum_cuxi += cuxi[i];
        sum_quxi += quxi[i];
        sum_xifi += xifi[i];
        sum_xi2fi += xi2fi[i];
    }

    double denominator = (row * sum_quxi) - (sum_sqxi * sum_sqxi);
    double a = ((row * sum_xi2fi) - (sum_xi * sum_xifi)) / denominator;
    double b = ((sum_sqxi * sum_xifi) - (sum_xi * sum_xi2fi)) / denominator;
    double c = (sum_fi - (a * sum_sqxi) - (b * sum_xi)) / row;

    cout << "\n";
    cout << "Fitted Least Square Parabola model: y = " << a << "x^2 + " << b << "x + " << c << "\n";

    double rms_sum = 0;

    cout << "\n------------------------------------------------------------\n";
    cout << "  xi\tfi\txi^2\txi^3\txi^4\txi*fi\test.yi\t(fi - yi)^2\n";
    cout << "------------------------------------------------------------\n";

    for (int i = 0; i < row; i++)
    {
        yi[i] = a * sqxi[i] + b * values[i] + c;
        double diff_sq = (second.values[i] - yi[i]) * (second.values[i] - yi[i]);
        rms_sum += diff_sq;

        dataFile << fixed;
        dataFile.precision(4);
        dataFile << values[i] << " " << second.values[i] << " " << yi[i] << "\n";

        cout << fixed;
        cout.precision(4);
        cout << values[i] << "\t" << second.values[i] << "\t" << sqxi[i] << "\t" << cuxi[i] << "\t" << quxi[i] << "\t" << xifi[i] << "\t" << yi[i] << "\t" << diff_sq << endl;
    }

    dataFile.close();

    double RMS = sqrt(rms_sum / row);

    cout << "------------------------------------------------------------\n";
    cout << "RMS Error = " << RMS << endl;

    return RMS;
}
