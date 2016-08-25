/*
	Exe_417: Sắp xếp các phần tử chẵn trong ma trận giảm dần theo hàng và cột theo 2 phương pháp dùng mảng phụ và k dùng mảng phụ
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
	cout << "Cach 1: \n";
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(a[i][j] % 2 != 0)
			{
				continue;
			}
			for(int k = j + 1; k < m; k++)
			{
				if(a[i][k] % 2 != 0)
				{
					continue;
				}
				if(a[i][j] < a[i][k])
				{
					HoanVi(a[i][j], a[i][k]);
				}
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(a[j][i] % 2 != 0)
			{
				continue;
			}
			for(int k = j + 1; k < m; k++)
			{
				if(a[k][i] % 2 != 0)
				{
					continue;
				}
				if(a[j][i] < a[k][i])
				{
					HoanVi(a[j][i], a[k][i]);
				}
			}
		}
	}
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