/*
	Exe_382: Tìm số chính phương lớn nhất trong ma trận nguyên
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
	return n == pow(sqrt((double)n), 2);
}

void Result(int a[][100], int m, int n)
{	
	int count_even = -1;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(Check(a[i][j]))
			{
				count_even = a[i][j];
				break;
			}
		}
		if(count_even)
		{
			break;
		}
	}

	if(count_even == -1)
	{
		cout << 0;
		return ;
	}

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(Check(a[i][j]) && a[i][j] > count_even)
			{
				count_even = a[i][j];
			}
		}
	}

	int dem = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(a[i][j] == count_even)
			{
				dem++;
			}
		}
	}
	cout << endl << dem;
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

	return 0;
}