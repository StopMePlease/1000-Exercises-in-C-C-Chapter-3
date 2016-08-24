/*
	Exe_401: Xóa 1 cột trong ma trận
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

void Result(int a[][100], int m, int &n)
{	
	int r;
	cout << "delete column :";
	cin >> r;

	if(r == n - 1)
	{
		n--;
		return;
	}

	for(int i = 0; i < m; i++)
	{
		a[i][r] = a[i][n - 1];
	}
	n--;
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
	cout << endl;
	Output(a, m, n);

	return 0;
}