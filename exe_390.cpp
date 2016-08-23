/*
	Exe_390: Liệt kê các cột có nhiều chữ số nhất trong ma trận nguyên
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
	int sum = 0;
	for(int i = 0; i < m; i++)
	{
		sum += log10((double)a[i][0]) + 1;
	}

	for(int i = 0; i < n; i++)
	{
		int sum_temp = 0;
		for(int j = 0; j < m; j++)
		{
			sum_temp += log10((double)a[j][i]) + 1;
		}
		if(sum_temp > sum)
		{
			sum = sum_temp;
		}
	}

	for(int i = 0; i < n; i++)
	{
		int sum_temp = 0;
		for(int j = 0; j < m; j++)
		{
			sum_temp += log10((double)a[j][i]) + 1;
		}
		if(sum_temp == sum)
		{
			for(int j = 0; j < m; j++)
			{
				cout << setw(5) << a[j][i];
			}
			cout << "\n";
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

	return 0;
}