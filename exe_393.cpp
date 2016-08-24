/*
	Exe_393: Hoán vị 2 cột trên ma trận
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void Input(int a[][100], int m, int n)
{
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
	}
}

void Output(int a[][100], int m, int n)
{
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << setw(4) << a[i][j] ;
		}
		cout << endl;
	}
}

void HoanVi(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Result(int a[][100], int m, int n)
{	
	int r1, r2;
	cout << "Input column 1: ";
	cin >> r1;
	cout << "Input column 2: ";
	cin >> r2;

	for(int i = 0; i < m; i++)
	{
		HoanVi(a[i][r1], a[i][r2]);
	}
	cout << endl;
}

int main()
{
	int a[100][100];
	int n, m;
	cout << "Input rows: ";
	cin >> m;
	cout << "Input columns: ";
	cin >> n;

	Input(a, m, n);
	Output(a, m, n);
	Result(a, m, n);
	Output(a, m, n);

	return 0;
}