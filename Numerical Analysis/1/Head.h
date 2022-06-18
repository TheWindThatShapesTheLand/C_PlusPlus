#pragma once

int n = 50;
double m = 2*n+1;
double N = 19;
double a = 1.37;
double b = 2.6;
double c = 3.15;
int k = 0;
double v = 0;
int r = 0;
int det = 0;
double DetA = 1;
double t =0;
double M;
int s;


double** A = new double* [n];
double* Mult = new double [m];
double* Dif  = new double [m];
double* Det = new double [n];
double* A1 = new double[n];
double* A2 = new double[n];
double** newA = new double* [n];
double** oldA = new double* [n];
double** E = new double* [n];
double** X = new double* [n];
double** O = new double* [n];
