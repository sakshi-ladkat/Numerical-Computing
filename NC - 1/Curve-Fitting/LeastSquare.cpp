#include <iostream>
#include <cmath>
#include <fstream>
#include "Curve.hpp"

using namespace std;

double Curve::LeastSquare(const Curve second)
{
    Curve sqxi(row);
    Curve xifi(row);
    Curve yi(row);

    double sum_xi = 0;
    double sum_fi = 0;
    double sum_sqxi = 0;
    double sum_xifi = 0;

    ofstream dataFile("LeastSquare.txt");

    dataFile << "# xi fi fitted_y\n";

    for (int i = 0; i < row; i++)
    {
        sqxi[i] = values[i] * values[i];
        xifi[i] = values[i] * second.values[i];
        sum_xi += values[i];
        sum_fi += second.values[i];
        sum_sqxi += sqxi[i];
        sum_xifi += xifi[i];
    }

    double a = ((row * sum_xifi) - (sum_xi * sum_fi)) / ((row * sum_sqxi) - (sum_xi * sum_xi));
    double b = (sum_fi - (a * sum_xi)) / row;
    cout << "\n";
    cout << "Fitted Least Square model: y = " << a << "x + " << b << "\n";

    double rms_sum = 0;

    // Display table header
    cout << "\n------------------------------------------------------------\n";
    cout << "  xi\tfi\txi^2\txi*fi\test.yi\t(fi - yi)^2\n";
    cout << "------------------------------------------------------------\n";

    for (int i = 0; i < row; i++)
    {
        yi[i] = a * values[i] + b;                                      
        double diff_sq = (second.values[i] - yi[i]) * (second.values[i] - yi[i]); 
        rms_sum += diff_sq;

        dataFile << fixed;
        dataFile.precision(4);
        dataFile << values[i] << " " << second.values[i] << " " << yi[i] << "\n";

        cout << fixed;
        cout.precision(4);
        cout << values[i] << "\t" << second.values[i] << "\t" << sqxi[i] << "\t" << xifi[i] << "\t" << yi[i] << "\t" << diff_sq << endl;
    }

    dataFile.close();

    double RMS = sqrt(rms_sum / row); 

    cout << "------------------------------------------------------------\n";
    cout << "RMS Error = " << RMS << endl;

    return RMS;
}
