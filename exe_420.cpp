/*
	Exe_420: Sắp xếp các giá trị nằm trên biên ma trận tăng dần theo chiều kim đồng hồ
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
	int temp[100] = {0};
	int k = 0;
	for(int i = 0; i < n; i++)
	{
		temp[k] = a[0][i];
		k++;
	}
	for(int i = 1; i < m - 1; i++)
	{
		temp[k] = a[i][n - 1];
		k++;
	}
	for(int i = n - 1; i >= 0; i--)
	{
		temp[k] = a[m - 1][i];
		k++;
	}
	for(int i = m - 2; i >= 1; i--)
	{
		temp[k] = a[i][0];
		k++;
	}

	for(int i = 0; i < k; i++)
	{
		for(int j = i + 1; j < k; j++)
		{
			if(temp[i] > temp[j])
			{
				HoanVi(temp[i], temp[j]);
			}
		}
	}

	k = 0;

	for(int i = 0; i < n; i++)
	{
		a[0][i] = temp[k];
		k++;
	}
	for(int i = 1; i < m - 1; i++)
	{
		a[i][n - 1] = temp[k];
		k++;
	}
	for(int i = n - 1; i >= 0; i--)
	{
		a[m - 1][i] = temp[k];
		k++;
	}
	for(int i = m - 2; i >= 1; i--)
	{
		a[i][0] = temp[k];
		k++;
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