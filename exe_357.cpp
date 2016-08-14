/*
	Exe_357: Liệt kê các dòng chứa số nguyên tố trong ma trận nguyên
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

void Result(int a[][100], int m, int n)
{			
	for(int i = 0; i < m; i++)
	{
		int check = 0;
		for(int j = 0; j < n; j++)
		{
			if(Check(a[i][j]))
			{
				check = 1;
				break;
			}
		}
		if(check == 1)
		{
			cout << "Row " << i << " : ";
			for(int j = 0 ; j < n; j++)
			{
				cout << setw(5) << a[i][j];
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