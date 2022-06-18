#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include<cmath>
using namespace std;

int main()
{
	//--------------------------------работа с файлом
	ifstream f;
	f.open("Вариант 19.txt");
	string Line;
	int p = 0;

	while (!f.eof())
	{
		getline(f, Line);
		if(Line.length() != 0)
		{
			p++;
		}
		else
		{
			continue;
		}
	}

	f.close();
	f.open("Вариант 19.txt");

	double* Xc = new double [p];
	double* Yc = new double[p];


	for (int i = 0; i < p; i++)
	{
		getline(f, Line);

		int find = Line.find(' ');
		string F = Line.substr(0, find);
		string G = Line.substr(find + 1);
		
		Xc[i] = stod(F);
		Yc[i] = stod(G);
		
	}
	f.close();
	//--------------------------------считаем функции
	double** Phi = new double*[31];
	double** A = new double* [31];
	double** Y = new double* [31];

	for (int i = 0; i < 31; i++)
	{
		Phi[i] = new double[p];
		A[i] = new double[32];
		Y[i] = new double[1];
	}

	clock_t t;

	for (int i = 0; i <31 ; i++)
	{
		for (int j = 0; j < p; j++)
		{
			if (i == 0)
			{
				Phi[0][j] = 1;
			}
			else if (i >= 1 && i <= 15)
			{
				Phi[i][j] = cos((i) * Xc[j]);
			}
			else if (i >= 16 && i <= 30)
			{
				Phi[i][j] = sin((i-15) * Xc[j]);
			}
			
		}
		
	}
	//--------------------------------метод наименьших квадратов
	double* T = new double[p];
	ofstream r;
	r.open("Свободные члены.txt");

	for (int i = 0; i < 31; i++)
	{
		for (int k = 0; k < p; k++)
		{
			T[k] = Phi[i][k];
		}
		
		for (int j = 0; j < 32; j++)
		{
			A[i][j] = 0;
			if (j <=30 )
			{
				for (int h = 0; h < p; h++)
				{
					A[i][j] +=T[h] * Phi[j][h];
					
				}
				

			}
			else if (j == 31)
			{
				for (int h = 0; h < p; h++)
				{

					A[i][j] += T[h] * Yc[h];
					

				}
				r<< "y[" << i + 1 << "]=" << A[i][j] << endl;
			}
		}
	}
	r.close();
	//--------------------------------метод якоби
	double* X = new double[31];
	double* X1 = new double[31];
	double* DiffX = new double[31];
	double Max;

	do
	{
		for (int i = 0; i <31; i++)
		{

			for (int j = 0; j < 32; j++)
			{
				if (i == j)
				{
					continue;
				}
				else if (j != 32 - 1)
				{
					X1[i] = (-1 * A[i][j] * X[j]) + X1[i];

				}

				if (j == 32 - 1)
				{
					X1[i] = ((A[i][j] + X1[i]) / A[i][i]);

				}
			}
			DiffX[i] = X1[i] - X[i];
		}
		Max = fabs(DiffX[0]);

		for (int i = 1; i < 31; i++)
		{
			if (fabs(DiffX[i]) > Max)
			{
				Max = fabs(DiffX[i]);
			}

		}

		swap(X, X1);
		for (int i = 0; i < 31; i++)
		{
			X1[i] = 0;

		}

	} while (Max > pow(10, -8));
	t = clock();
	//--------------------------------выводим
	ofstream u;
	u.open("Значения коэффицентов.txt");

	for (int i = 0; i < 31; i++)
	{
		if (i <= 15)
		{
			u << "A" << i  << "=" << X[i] << endl;;
		}
		else if (i > 15 && i < 31)
		{
			u << "B" << i-15 << "=" << X[i] << endl;;
		}
	}
	u << endl << "Runtime was:" << float(t) / CLOCKS_PER_SEC << "sec.";
	u.close();

	ofstream h;
	h.open("Проверка  свободных членов подстановкой коэффицентов.txt");

	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			Y[i][1] = 0;
			for (int k = 0; k < 31; k++)
			{
				Y[i][1] += A[i][k] * X[k];

			}
			h << "y[" << i + 1 << "]=" << Y[i][1] << "\t";
		}
		h << endl;
	}
	h.close();

	ofstream v;
	v.open("Искомая функция.txt");

	for (int i = 0; i < 31; i++)
	{
		if (i == 0)
		{
			v << X[i] ;
		}
		if (i > 0 && i <= 15)
		{
			if (X[i] >= 0)
			{
				v << "+" << X[i]<<"*Cos["<<i<<"*x]";
			}
			else if (X[i] < 0)
			{
				v << "-" << fabs(X[i]) << "*Cos[" << i << "*x]";
			}
	
		}
		else if (i > 15 && i < 31)
		{
			if (X[i] >= 0)
			{
				v << "+" << X[i] << "*Sin[" << i-15 << "*x]";
			}
			else if (X[i] < 0)
			{
				v << "-" << fabs(X[i]) << "*Sin[" << i-15 << "*x]";
			}
		}
	}
	v.close();
	//--------------------------------удаляем
	for (int i = 0; i < 31; i++)
	{
		delete[] Phi[i];
		delete[] A[i];
		

	}
	delete[] X;
	delete[] X1;
	delete[] DiffX;
	delete[] Xc;
	delete[] Yc;
	delete[] T;
	delete[] Phi;
	delete[] A;
	delete[] Y;

	return 0;
}