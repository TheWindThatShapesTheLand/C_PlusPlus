#include <iostream>
using namespace std;

struct Node                      //��������� � ���������� � �������� �����
{
	int val;                             //��������. �������� �� x ����� ������������ � ������
	Node* nodes;                    //�������� ����
};

class List                          //����� ������
{
	Node* Head;                     //��������� �� ��������� �������� ������� ��� ������ ������ ������
public:
	List() { Head = NULL; }             //����������� � ������������� ��������� ������ ���������
	~List();                           //�������� �����������. ��� ���������� ������� �� �����
	void Add(int x);                   //�������� ������� ���������� �������� � ������
	void Show();                       //�������� ������������������ ������ �� ������
};

List::~List()                       //���������� ������� �� �����
{
	while (Head != NULL)            //���� �� ������ �� �����
	{
		Node* temp = Head->nodes; //��������� ���������� ��� �������� ������ ���������� ��������
		delete Head;                //����������� ����� ������������ ������
		Head = temp;                //������ ����� �� ���������
	}
}

void List::Add(int val)               //������� ���������� ��������� � ������
{
	Node* temp = new Node;       //��� ������ ������ ���������� ������
	temp->val = val;                        //���������� x � ������� ���������  element (� x ��������� element)
	temp->nodes = Head;                  //���������, ��� ����. ������� ��� ������ �� ������ Head
	Head = temp;                        //���������, ��� ��������� �������� ������� ��� ������ ��� ���������
}

void List::Show()                   //������� ����������� ������ �� ������
{
	Node* temp = Head;                //���������� ���������, ������� ���������� �� ����� ������ ������ ������

	while (temp != NULL)               //�� ��� ��� ���� �� �������� ������ ��������
	{
		cout << temp->val << " ";           //������� ������� x �� ������
		temp = temp->nodes;                //���������, ��� ����� ��� ����� ��������� �������
	}
}

int main()
{

	int N;                        //����� ��������� � ������
	int val;                        //�������� �������� � ������
	List lst;                     //����������, ��� ������� ������

	cout << "N = ";
	cin >> N;     //������� ������� ��������� ������� � ������

	val = N;

	for (int i = 0; i < N; i++)
	{
		             //���� x � ����������
		lst.Add(val);           //���������� �������� � ������
	}

	lst.Show(); 				//����� ������ �� �����		
	return 0;
}