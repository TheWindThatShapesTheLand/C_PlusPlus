#pragma once
#include<cmath>
extern double const eps = pow(10, -7);
extern double const delta = pow(10, -7.6507);
extern double const gamma = pow(10, -10);
extern const int  n = 10;

double Divdiff(double x1, double x2, double y1, double y2)
{
	return double((y1 - y2) / (x1 - x2));
}

double Bisection(double first, double x, double(&R)[10][10], double Eigva[10])
{

	return double(first + (x - Eigva[0]) * (R[0][0] + (x - Eigva[1]) * (R[1][0] + (x - Eigva[2]) * (R[2][0] + (x - Eigva[3]) * (R[3][0] + (x - Eigva[4]) * (R[4][0] + (x - Eigva[5]) * (R[5][0] + (x - Eigva[6]) * (R[6][0] + (x - Eigva[7]) * (R[7][0] + (x - Eigva[8]) * (R[8][0] + (x - Eigva[9] * (R[9][0]))))))))))));

}