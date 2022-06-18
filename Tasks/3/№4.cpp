#include <iostream>
#include <cstring>
using namespace std;

void Sort(string& S)
{
	int N = S.length();
	int w;
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = N - 1; j > i; --j)
		{
			if (S[j] < S[j - 1])
			{
				w = S[j];
				S[j] = S[j - 1];
				S[j - 1] = w;
			}
		}
	}
}

bool Swaps(string S)
{
	for (int i = 0; i < S.length() - 1; ++i)
	{
		if (S[i] < S[i + 1]) return 1;
	}

	return 0;
}

void Create(string& S)
{
	string P = S;
	int i, j;

	Sort(P);

	for (i = 0; S[0] >= P[i]; ++i);
	for (j = 0; S[j] != P[i]; ++j);

	S.erase(j, 1);
	Sort(S);

	S = P[i] + S;
}

int main()
{
	string S, P;
	int k;
	int N = S.length();

	cout << "Enter string S:";
	cin >> S;

	Sort(S);
	cout << S << endl;

	while (Swaps(S))
	{
		for (int i = S.length() - 1; i > 0; --i)
		{
			if (S[i] > S[i - 1])
			{
				k = i - 1;
				break;
			}
		}

		P = S.substr(k, S.length() - k);//начало в к, конец в N-k

		S.erase(k, S.length() - k);//удаляем Р из S

		//Create(P);

		S += P;
		cout << S << endl;

	}

	return 0;
}