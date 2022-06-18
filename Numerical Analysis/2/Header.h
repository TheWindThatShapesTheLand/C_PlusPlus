#include<cmath>

double m = 500;
double n = m + 1;
double c = pow(10,4);
int k;
double Max;

double** A = new double* [m]; 
double* X = new double [m];
double* X1 = new double [m];
double* DiffX = new double[m];
double** Y = new double* [m];