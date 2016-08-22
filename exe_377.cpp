/*
	Exe_377: Tìm số nguyên tố lớn nhất trong ma trận nguyên
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

bool Check(int n)
{
	if(n == 2)
	{
		return true;
	}

	for(int i = 2; i < n; i++)
	{
		if(n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int Result(int a[][100], int m, int n)
{	
	int max = -1;
	for(int i = 0; i < m; i++)
	{
		int check = 1;
		for(int j = 0; j < n; j++)
		{
			if(Check(a[i][j]))
			{
				max = a[i][j];
				check = 0;
				break;
			}
		}
		if(check == 0)
		{
			break;
		}
	}

	if(max == -1)
	{
		return max;
	}

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n ; j++)
		{
			if(a[i][j] > max && Check(a[i][j]))
			{
				max = a[i][j];
			}
		}
	}

	return max;
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