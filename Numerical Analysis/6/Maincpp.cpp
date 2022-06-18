#include "Power.h"
#include <iostream>
#include <fstream>
#include <utility>
#include <string>
using namespace std;

int main()
{
	//-----Работа с файлом-----

	ifstream f;
	f.open("Вариант 11.txt");
	string Line;

	double A[10][10];
	
	for (int i = 0; i < n; i++)
	{
		getline(f, Line);

		for (int j = 0; j < n; j++)
		{
			int find = Line.find(' ');
			string F = Line.substr(0, find);

			A[i][j] = stold(F);
			Line.erase(0, find + 1);
		}

	}
	f.close();

	//-----Степенной метод-----

	double* Zk0 = new double[n];
	double* Zk1 = new double[n];

	for (int i = 0; i < n; i++)
	{
		Zk0[i] = 1;
	}

	double Max_Eigva, Not_Max_Eigva, sum0 = 0, sum1 = 0, t;
	int p = 0;

	do {

		for (int i = 0; i < n; i++)
		{
			Zk1[i] = 0;
			for (int j = 0; j < n; j++)
			{

				Zk1[i] += A[i][j] * Zk0[j];

			}
			sum0 += pow(Zk0[i], 2);
			sum1 += pow(Zk1[i], 2);
		}

		Max_Eigva = sqrt(sum1 / sum0);
		p++;

		if (p == 1)
		{
			Not_Max_Eigva = 0;
		}
		else
		{
			Not_Max_Eigva = t;
		}
		t = Max_Eigva;

		swap(Zk0, Zk1);

	} while (Max_Eigva - Not_Max_Eigva >= eps);

	//-----Cетка-----

	double Knots[11];

	for (int i = 0; i <= n; i++)
	{
		if (i != n)
		{
			Knots[i] = 0 + (i * (fabs(Max_Eigva) / n));
		}
		else
		{
			Knots[i] = 0 + (i * (fabs(Max_Eigva + delta) / n));
		}
	}

		//-----Метод Гаусса-----

		int k = 0, m = 2 * n + 1, r = 0, det = 0;
		double v = 0;

		double* DetFunk = new double[n+1];
		double* Det = new double[n];
		double** F = new double* [n];
		for (int i = 0; i < n; i++)
		{
			F[i] = new double[m];
		}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (F[i][0] == 0 && F[i + 1][0] != 0)
			{
				if (F[i][j] != 0)
				{
					break;
				}

				k++;
			}
		}
	}

	for (int q = 0; q <= n; q++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (j < n && j != i)
				{
					F[i][j] = A[i][j];

				}
				else if (j < n && j == i)
				{
					F[i][j] = A[i][j] - Knots[q];
				}
				else if (j == n)
				{
					F[i][j] = 0;

				}
				else if (j > n)
				{
					if (i + n + 1 == j)
					{
						F[i][j] = 1;

					}

					else
					{
						F[i][j] = 0;

					}
				}

			}

		}

		double* Mult = new double[m];
		double* Dif = new double[m];

		while (k + 1 < n)
		{
			for (int i = 0; i <= k + 1; i++)
			{
				for (int j = 0; j < m; j++)
				{

					if (i < k + 1)
					{
						if (i == j && F[i][j] != 0)
						{
							v = F[i][j];

							if (det == 0)
							{
								Det[i] = v;

							}
						}

						F[i][j] = F[i][j] / v;
						Mult[r] = F[i][j] * F[k + 1][i];
						Dif[r] = F[k + 1][j] - Mult[r];
						r++;

					}
					else if (i == k + 1)
					{
						if (i == j)
						{
							v = F[i][i];
							Det[i] = v;
						}

						F[i][j] = F[i][j] / v;
						r = 0;

					}
				}
				if (i < k + 1)
				{
					swap(F[k + 1], Dif);
					r = 0;
				}

				else if (i == k + 1)
				{
					k++;
					det++;
					break;

				}

			}

		}
		r = 0;
		v = 0;
		k = 0;
		det = 0;

		while (k < n - 1)
		{
			for (int i = n - 1 - k; i > 0; i--)
			{
				for (int j = 0; j < m; j++)
				{
					Mult[r] = F[i + k][j] * F[i - 1][i + k];
					Dif[r] = F[i - 1][j] - Mult[r];
					r++;

				}

				swap(F[i - 1], Dif);
				r = 0;

			}

			k++;
			r = 0;

		}

		r = 0;
		v = 0;
		k = 0;

		delete[] Dif;
		delete[] Mult;

		double DetA = 1;

		for (int i = 0; i < n; i++)
		{
			DetA *= Det[i];

		}

		DetFunk[q] = DetA;
		DetA = 0;

	}


	r = 0;
	v = 0;
	k = 0;

	//-----Интерполяция-----
	double DiDi[10][10];
	double First = DetFunk[0];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (i == 0)
			{
				DiDi[i][j] = Divdiff(Knots[j], Knots[i + j + 1], DetFunk[j], DetFunk[j + 1]);

				
			}
			else
			{
				DiDi[i][j] = Divdiff(Knots[j], Knots[i + j + 1], DiDi[i - 1][j], DiDi[i - 1][j + 1]);
				
			}

		}
		
	}

	
	
	//-----Бисекция-----

	double x0 = 0, t0, Bisx1, X, x1, x2;
	int b, ch = 0;
	double* Eigva = new double[n];

	while (x0 <= Max_Eigva + 1)
	{
		b = 0;

		for (double i = x0 + 0.1; i <= Max_Eigva + 1; i++)
		{
			
			Bisx1 = Bisection(First, i, DiDi, Knots);
			if (Bisection(First, x0, DiDi, Knots) * Bisx1 == 0)
			{
				X = 0;
				Eigva[ch] = X;
				ch++;
				t0 = Bisection(First, X, DiDi, Knots);

				if (t0 < eps)
				{
					t0 = 0;
				}

				x1 = fabs(x1);
				x0 = fabs(x0);
				b++;

				break;

			}

			else if (Bisection(First, x0, DiDi, Knots) * Bisx1 < 0)
			{
				x1 = i + 0.1;

				break;
			}
			else continue;

		}
		if (Bisection(First, x0, DiDi, Knots) * Bisection(First, x1, DiDi, Knots) < 0)
		{

			while (fabs(Bisection(First, x1, DiDi, Knots)) >= eps && b == 0)
			{
				x2 = (x0 + x1) / 2;
				
				if (Bisection(First, x0, DiDi, Knots) * Bisection(First, x2, DiDi, Knots) < 0)
				{
					x1 = x2;
					

				}
				else if (Bisection(First, x0, DiDi, Knots) * Bisection(First, x2, DiDi, Knots) > 0)
				{
					x0 = x2;
					
				}

			}

			if (fabs(Bisection(First, x1, DiDi, Knots)) < eps && b == 0)
			{
				X = x1;
				Eigva[ch] = X;
				ch++;
				t0 = Bisection(First, X, DiDi, Knots);

				if (t0 < eps)
				{
					t0 = 0;
				}

				x0 += 0.1;
			}

		}
		else
		{
			x0 += 0.1;
		}
	
	}

	//-----Выводим собственные числа-----

	for (int i = 0; i < n; i++)
	{
		cout << "P" << i + 1 << "(L" << i + 1 << ")=" << Eigva[i] << endl;
	}
	system("pause");
	 //-----Cобственные вектора-----
	 
	double sum = 0, Norm = 0;

	double* G1 = new double[n];
	double** Vect = new double* [n];
	double** I = new double* [n];
	double** B = new double* [n];
	for (int i = 0; i < n; i++)
	{
		Vect[i] = new double[n];
		B[i] = new  double[m];
		I[i] = new  double[n];
		
	}
	double* G0 = new double[n];
	for (int i = 0; i < n; i++)
	{
		G0[i] = 1;
	}

	double V = 0, max = 0;
	int H = 0;
		
	
	for (int t = 0; t < n; t++)
	{
		for (int q = 0; q < n; q++)
		{

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (j < n && j != i)
					{
						B[i][j] = A[i][j];

					}
					else if (j < n && j == i)
					{
						B[i][j] = A[i][j] - Eigva[t];

					}
					else if (j == n)
					{
						B[i][j] = G0[i];

					}
					else if (j > n)
					{
						if (i + n + 1 == j)
						{
							B[i][j] = 0;

						}

						else
						{
							B[i][j] = 0;

						}
					}

				}

			}

			/*for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					cout << B[i][j] << " ";
				}
				cout << endl;
			}
			system("pause");*/

			for (int i = 0; i < n - 1; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (B[i][0] == 0 && B[i + 1][0] != 0)
					{
						if (B[i][j] != 0)
						{
							break;
						}

						k++;
					}
				}
			}

			double* Mult = new double[m];
			double* Dif = new double[m];

			while (k + 1 < n)
			{
				for (int i = 0; i <= k + 1; i++)
				{
					for (int j = 0; j < m; j++)
					{

						if (i < k + 1)
						{
							if (i == j && B[i][j] != 0)
							{
								v = B[i][j];

							}

							B[i][j] = B[i][j] / v;
							Mult[r] = B[i][j] * B[k + 1][i];
							Dif[r] = B[k + 1][j] - Mult[r];
							r++;

						}
						else if (i == k + 1)
						{
							if (i == j)
							{
								v = B[i][i];

							}

							B[i][j] = B[i][j] / v;
							r = 0;

						}
					}
					if (i < k + 1)
					{
						swap(B[k + 1], Dif);
						r = 0;
					}

					else if (i == k + 1)
					{
						k++;
						break;

					}

				}

			}

			r = 0;
			v = 0;
			k = 0;

			while (k < n - 1)
			{
				for (int i = n - 1 - k; i > 0; i--)
				{
					for (int j = 0; j < m; j++)
					{

						Mult[r] = B[i + k][j] * B[i - 1][i + k];
						Dif[r] = B[i - 1][j] - Mult[r];
						r++;

					}

					swap(B[i - 1], Dif);
					r = 0;

				}
				k++;
				r = 0;
			}
			r = 0;
			v = 0;
			k = 0;

			delete[] Dif;
			delete[] Mult;

			double* normX = new double[n];
			for (int i = 0; i < n; i++)
			{
				normX[i] = B[i][n];

			}

			for (int i = 0; i < n; i++)
			{
				sum += pow(normX[i], 2);
			}
			Norm = sqrt(sum);

			for (int i = 0; i < n; i++)
			{
				G1[i] = normX[i] / Norm;
				

			}

			swap(G0, G1);
			sum = 0;
			Norm = 0;
	
				for (int r = 0; r < n; r++)
				{
					V = abs(G1[r]) - abs(G0[r]);
					if (V <gamma)
					{
						Vect[t][r] = G1[r];
						
					}
					else
					{
						for (int b = 0; b < n; b++)
						{
							Vect[t][b] = NULL;
						}

						q--;
						break;
					}
				}


		}

	}


	
	system("pause");
	//-----Выводим собственные вектора-----
	for (int i = 0; i < n; i++)
	{
		cout << "X" << i + 1 << "= ";

		for (int j = 0; j < n; j++)
		{
			cout<< Vect[i][j];

			if (j == n - 1)
			{
				continue;
			}
			else
			{
				cout << " , ";
			}
		}
		cout << endl;
	}
	system("pause");

	//-----Проверка-----
	 
	double** Check = new double*[n];
	double** vod = new double* [n];
	for (int k = 0; k < n; k++)
	{
		vod[k] = new double[n];
		Check[k] = new double[n];
	}


	double number = 0;
	for (int z = 0; z < n; z++)
	{
		for (int i = 0; i < n; i++)
		{

			for (int j = 0; j <= n; j++)
			{

				if (j == n)
				{
					vod[z][i] = number;
					number = 0;
				}
				else
				{
					number += (A[i][j] * Vect[z][j]);
				}

			}

		}
	}

	int y = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Check[i][j] = vod[i][j] - Eigva[y] * Vect[i][j];
			/*if (Check[i][j] <= eps)
			{
				Check[i][j] = 0;
			}*/

			cout << Check[i][j] << " ";

		}

		y++;

		cout << endl;
	}
	system("pause");

	double bin = 0;
	for (int t = 0; t < n; t++)
	{
		for (int i = 0; i < n - t; i++)
		{
			for (int j = 0; j < n; j++)
			{
				bin += Vect[t][j] * Vect[i + t][j];
			}

			/*if (bin <= gamma)
			{
				bin = 0;
			}*/

			cout <<"X"<<t+1<<"*X"<<i+t+1<<"= "<< bin << endl;

			bin = 0;
			
		}
	}
	system("pause");
	return 0;
}