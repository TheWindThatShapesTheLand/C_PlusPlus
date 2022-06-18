#include<iostream>
#include<cstring>
using namespace std;

int Le(string S)
{
	int H = S.length();
	for (int k = 0; k < H; k++)
	{
		if (isdigit(S[k]) == 0)
		{
			continue;
		}
		else if (isdigit(S[k]) != 0)
		{
			return k;
		}
	}
	return H;
}
int El(string S)
{
	int H = S.length();
	for (int k = 0; k < H; k++)
	{
		if (isdigit(S[k]) != 0)
		{
			continue;
		}
		else if (isdigit(S[k]) == 0)
		{
			return k;
		}
	}
	return H;
}

bool Form(string& P)
{
	int r = 0;
	int H = P.length();
	for (int k = 0; k < H; k++)
	{
		if (isdigit(P[k]) == 0)
		{
			return false;
		}
		else if (isdigit(P[k]) != 0)
		{
			r++;
		}
	}

	if (r == P.length())
	{
		return true;
	}
	else return false;
}

int Prog(string& S)
{
	if (Le(S) != S.length())
	{
		
		if (S[Le(S)-1]== '+' || S[Le(S)-1] == '-')
		{
			
			int j = Le(S)-1;
			if (S.find('.') != string::npos)
			{
				int i = S.find('.');
				string P = S.substr(j+1, i - j -1);
				string p = S.substr(j, i- j );
				string y = S.substr(0, i);
				S.erase(0, i);
				string Y = y + S;
				
				for (int k = 0; k < P.length(); k++)
				{
					if (P[k] == '+' || P[k] == '-')
					{
						P = P.substr(k, P.length()-1);
					}
					else 
					{
						continue;
					}
				}
				
				string r = P.substr(0, 1);
				P.erase(0, 1);
				string v = p.substr(0, 1);
			
				

				if (Form(P) == true)
				{
					if (S.find('e') != string::npos)
					{
						if (isdigit(S.find('e') - 1) != 0 &&( S.find('e') + 1 != '+' || S.find('e') + 1 != '-'))
						{
							string w = S.substr(0, 1);
							S.erase(0, 1);
							string h = S.substr(0, El(S));

							if (Form(h) == true)
							{
								string s = r + p + w + h;
								cout << s << endl;
								S.erase(0, El(S));
								return Prog(S);

							}
							else if (Form(h) == false)
							{
								S.erase(0, S.find('e') + 1);
								return Prog(S);
							}

						}

						else if (isdigit(S.find('e') - 1) == 0 || S.find('e') + 1 == '+' || S.find('e') + 1 == '-')
						{
							S = r +P+S;
							int e = S.find('e');
							i = S.find('.');
							string B = S.substr(i+1, e-i-1 );
							string f = S.substr(S.find('e') + 1, S.length() - 1);
							string d = S.substr(0, e + 2);
							

							if (Form(B) == true)
							{
								
								f.erase(0, 1);
								string h = f.substr(0, El(f));
								

								if (Form(h) == true)
								{
									string l = v+ d + h;
									cout << l << endl;
									S.erase(0, l.length());
									return Prog(S);

								}
								else if (Form(h) == false)
								{
									S.erase(0, S.find('e') + 1);
									return Prog(S);
								}
								
							}

							else if (Form(B) == false)
							{
								S.erase(0, e + 1);
								return Prog(S);
							}
						}
					}

					else if (S.find('e') == string::npos)
					{
						string s = S.substr(0, 1);
						S.erase(0, 1);
						string q = S.substr(0, El(S));

						if (Form(q) == true)
						{
							string w = r+P+s + q;
							cout << w << endl;
							S.erase(0, El(S));
							return Prog(S);
						}

						if (Form(q) == false)
						{
							S.erase(0, El(S));
							return Prog(S);
						}
					}

				}

				else if (Form(P) == false)
				{
					S.erase(0, i + 1);
					return Prog(S);
				}
			}

			else if (S.find('.') == string::npos)
			{
				return 0;
			}
		}

		else if (S[Le(S)-1] != '+' && S[Le(S)-1] != '-')
		{
			S.erase(0, Le(S));
			if (S.find('.') != string::npos)
			{
				int i = S.find('.');
				string P = S.substr(0, i);
				string g = S.substr(0, i + 1);
				S.erase(0, i);

				if (Form(P) == true)
				{
					S.erase(0, 1);
					string q = S.substr(0, El(S));

					if (Form(q) == true)
					{
						string w = g + q;
						cout << w << endl;
						S.erase(0, El(S));
						return Prog(S);
					}

					if (Form(q) == false)
					{
						S.erase(0, El(S));
						return Prog(S);
					}

				}

				else if (Form(P) == false)
				{
					S.erase(0, i + 1);
					return Prog(S);
				}
			}

			else if (S.find('.') == string::npos)
			{
				return 0;
			}

			
		}
	}

	else if (Le(S) == S.length())
	{
		return 0;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string S;
	cout << "Enter S:";
	cin >> S;

	Prog(S);
		
	return 0;
}