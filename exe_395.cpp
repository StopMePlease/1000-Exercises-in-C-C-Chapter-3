/*
	Exe_395: Dịch lên xoay vòng các hàng trong ma trận
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

void Result(int a[][100], int m, int n)
{	
	int temp[100];
	for(int i = 0; i < n; i++)
	{
		temp[i] = a[0][i];
	}
	
	for(int i = 0; i < m - 1; i++)
	{
		for(int j = 0; j < n; j++)
		{
			a[i][j] = a[i + 1][j];
		}
	}

	for(int i = 0; i < n; i++)
	{
		a[m - 1][i] = temp[i];
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