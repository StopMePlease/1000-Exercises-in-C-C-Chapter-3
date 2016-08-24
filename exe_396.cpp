/*
	Exe_396: Dịch trái xoay vòng các cột trong ma trận
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
		temp[i] = a[i][0];
	}
	
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < m; j++)
		{
			a[j][i] = a[j][i + 1];
		}
	}

	for(int i = 0; i < n; i++)
	{
		a[i][n - 1] = temp[i];
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