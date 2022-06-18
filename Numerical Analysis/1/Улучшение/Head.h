#pragma once

int n = 50;//число строк
double m = 2*n+1;//число столбцов
double N = 19;//номери варианта
double a = 1.37;
double b = 2.6;
double c = 3.15;
int k = 0;// подсчитываем количество строк, пока не встретится строка, у которой элементы начинаются с 0 и так далее, чтобы узнать, на какую строку свапать строки без нулей
double v;//константа, равная элементу, на который делим
int r = 0;//честно хз, зачем я сделал это так, но там, где мы её используем можно было бы на циклом заменить
int det = 0;//выцепляем диаогональные ненулевые элементы, чтобы подсчитать определитель(см. теорию)
double DetA = 1;//считаем определитель
double t =0;//переменная для подсчёта нормы
double M;//число обусловленности


double** A = new double* [n];//основная матрица
double* Mult = new double [m];//записываем произведение для нижней треугольной
double* Dif  = new double [m];//записываем разность
double* Det = new double [n];
double* A1 = new double[n];
double* A2 = new double[n];
double** newA = new double* [n];
double** oldA = new double* [n];
double** E = new double* [n];
double** X = new double* [n];
double** O = new double* [n];
