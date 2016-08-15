/*
	Exe_360: Liệt kê các cột trong ma trận nguyên chứa số chính phương
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
	for(int i = 0; i < n; i++)
	{
		int check = 0;
		for(int j = 0; j < m; j++)
		{
			if(Check(a[j][i]))
			{
				check = 1;
				break;
			}
		}
		if(check == 1)
		{
			cout << "Column " << i << " : ";
			for(int j = 0 ; j < n; j++)
			{
				cout << setw(5) << a[j][i];
			}
			cout << endl;
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