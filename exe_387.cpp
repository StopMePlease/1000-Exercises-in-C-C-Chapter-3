/*
	Exe_387: Liệt kê các dòng có nhiều số chẵn nhất trong ma trận
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
	int dem = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[0][i] % 2 == 0)
		{
			dem++;
		}
	}

	for(int i = 0; i < m; i++)
	{
		int temp_dem = 0;
		for(int j = 0; j < n; j++)
		{
			if(a[i][j] % 2 == 0)
			{
				temp_dem += 1;
			}
		}
		if(temp_dem > dem)
		{
			dem = temp_dem;
		}
	}

	for(int i = 0; i < m; i++)
	{
		int temp_dem = 0;
		for(int j = 0; j < n; j++)
		{
			if(a[i][j] % 2 == 0)
			{
				temp_dem += 1;
			}
		}
		if(temp_dem == dem)
		{
			for(int j = 0; j < n; j++)
			{
				cout << setw(5) << a[i][j];
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