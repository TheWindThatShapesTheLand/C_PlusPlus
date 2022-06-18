#include"Head.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <utility>
using namespace std;
double const eps = pow(10, -3);

double Bisection(double x)
{

	return double((sin(x) + 0.001 * pow(x, 2) + 0.01 * x));

}

int  main()
{
	setlocale(LC_ALL, "Russian");
	ofstream f,g;

	f.open("Корни нелинейного уравнения.txt");
	g.open("Проверка корней нелинейного уравнения.txt");
	clock_t w;
	x0 = -50;
	while (x0 <= 50)
	{
		b = 0;
		
		for (int i = x0+1; i <= 50; i++)
		{
			n++;
			Bisx1 = Bisection(i);
			if (Bisection(x0) * Bisx1 == 0)
			{
				X = 0;
				f << "x[" << k << "]= " << X << endl;
				t = Bisection(X);
				if (t < eps)
				{
					t = 0;
				}
				g << "y[" << k << "]= " << t << endl;
				x1 = fabs(x1);
				x0=fabs(x0);
				k++;
				b++;
				break;
			}
			
			else if (Bisection(x0) * Bisx1 < 0)
			{
				x1 = i;
				break;
			}
			else continue;
			
		}

		if (Bisection(x0) * Bisection(x1) < 0)
		{


			while (fabs(Bisection(x1)) >= eps && b == 0)
			{
				x2 = (x0 + x1) / 2;
				n++;

				if (Bisection(x0) * Bisection(x2) < 0)
				{
					x1 = x2;
				}
				else if (Bisection(x0) * Bisection(x2) > 0)
				{
					x0 = x2;
				}
			}

			if (fabs(Bisection(x1)) < eps && b == 0)
			{
				X = x1;
				f << "x[" << k << "]= " << X << endl;
				t = Bisection(X);
				if (t < eps)
				{
					t = 0;
				}
				g << "y[" << k << "]= " << t << endl;
				k++;
				x0++;

			}
		}
		else
		{
			x0++;
		}
		n++;

	} 
	w= clock();
	g << "Runtime was : " << float(w) / CLOCKS_PER_SEC << "sec." << endl;
	g << "Number of iterations : " << n;

	f.close();
	g.close();
	
	return 0;
}