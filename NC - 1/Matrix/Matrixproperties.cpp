#include "Matrix.hpp"
using namespace std;

bool Matrix ::isSymmetric() const
{
    if (row != col)
    {
        return false;
    }
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            if (values[i][j] != values[j][i])
            {
                return false;
            }
    return true;
}

bool Matrix ::isIdentity() const
{
    if (row != col)
    {
        return false;
    }
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            if (i == j)
                if (values[i][j] != 1)
                {
                    return false;
                }
                else if (values[i][j] != 0)
                {
                    return false;
                }
    return true;
}

bool Matrix ::isDiagonallyDominant() const
{ int r,c;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            if (i != j)
            {
                sum += abs(values[i][j]);
            }
            if (abs(values[i][i]) < sum)
                return false;
        }
    }
    return true;
}
