#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	string S;
	cout << "Enter string S:";
	cin >> S;

	int N, r = 0, i = 0, j = 0;
	cout << "Enter N:";
	cin >> N;

	int M = S.length();
	
	while( i < M)
	{
		if (S[i] == S[i + 1])
		{
			r++;
			if ( r == N)
			{
				if (i >=N)
				{
					S.erase(S.begin() + j, S.begin() + i+1);
					M = S.length();
					r = 0;
					i = j;
				}
				
				else if (i < N)
				{
					S.erase(S.begin(), S.begin() + N);
				
					M = S.length();
					i = 0;
					r = 0;
				}

			}

			else if (r != N)
			{
				i++;
			}
		}
		
		else if (S[i] != S[i + 1])
		{
			if (r == N - 1)
			{
				if (i >= N)
				{
					S.erase(S.begin() + j, S.begin()+i+1);
					M = S.length();
					r = 0;
					i = j;
				}

				else if (i < N)
				{
					S.erase(S.begin(), S.begin() + N);
					M = S.length();
					i = 0;
					r = 0;
				}
			}

			else if (r  != N - 1)
			{
				j = i + 1;
				r = 0;
				i++;
				
			}
	
		}

	}

	cout << S << endl;
	return 0;
}