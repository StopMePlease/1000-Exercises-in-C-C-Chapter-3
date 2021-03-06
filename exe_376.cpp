﻿/*
	Exe_376: Tìm giá trị dương nhỏ nhất trong ma trận thực
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

int Result(int a[][100], int m, int n)
{	
	int min;
	for(int i = 0; i < m; i++)
	{
		int check = 1;
		for(int j = 0; j < n; j++)
		{
			if(a[i][j] > 0)
			{
				min = a[i][j];
				check = 0;
				break;
			}
		}
		if(check == 0)
		{
			break;
		}
	}

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n ; j++)
		{
			if(a[i][j] < min && a[i][j] > 0)
			{
				min = a[i][j];
			}
		}
	}

	return min;
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
	int kq = Result(a, m, n);
	cout << kq;

	return 0;
}