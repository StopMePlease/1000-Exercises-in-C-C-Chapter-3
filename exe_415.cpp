/*
	Exe_415: Sắp xếp các phần tử trong ma trận tăng dần theo hàng và cột theo 2 phương pháp dùng mảng phụ và k dùng mảng phụ
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
	cout << "Cach 1: ";
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = j + 1; k < m; k++)
			{
				if(a[i][j] > a[i][k])
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
			for(int k = j + 1; k < m; k++)
			{
				if(a[j][i] > a[k][i])
				{
					HoanVi(a[j][i], a[k][i]);
				}
			}
		}
	}
	Output(a, m, n);
	cout << "Cach 2: ";
	int temp[100] = {0};
	int k = 0;

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			temp[k] = a[i][j];
			k++;
		}
	}

	for(int i = 0; i < k; i++)
	{
		for(int j = i + 1; j < k; j++)
		{
			if(temp[i] > temp[k])
			{
				HoanVi(temp[i], temp[k]);
			}
		}
	}

	for(int i = 0; i < k; i++)
	{
		cout << setw(5) << temp[i];
		if(n % (n + 1) == 0)
		{
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
	Output(a, m, n);

	return 0;
}