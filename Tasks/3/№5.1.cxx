#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cout << "Enter s" << endl;
	cin >> s;                                       //������ ������
	int d = s.size();								//����� ������
	cout << endl << "d = " << d;
	
	int n;
	cout << endl << "Enter n" << endl;
	cin >> n;										//���������� �������� ���������
	
	string a;
	a = s.substr(0, n);								//���������
	int f, h = 0, g = 0;
	for(int k = 0; k < d - n ; )
    {
    	if(h > 0)
    	{
    		if(g == 1)
    		{
    			s.erase(k, n);						//�������� ���������, � ������� ����������
    			cout << endl << "New s:" << s << endl;
    			k--;
    			d -= n;
    			g = 0;
    		}
    		k++;
	        a = s.substr(k, n);
	        h = 0;
    	}
	    cout << endl << a << endl;
	    f = s.find(a, k + n);							//����� ������� ���������� ���������
														//� ������
	    cout << endl << "f = " << f << endl;
	    if(f >= 0)
	    {
	        s.erase(f, n);								//�������� ������������� ���������
	        cout << endl << "New s:" << endl << s << endl;
	        d -= n;
	        h = -1;
	        g = 1;
	    }
	    h++;
	    cout << endl << "h, k = " << h << k << endl;
	}
	    
	
	cout << endl << "New s:" << endl << s << endl;
	cin >> n;

	
	return 0;
}