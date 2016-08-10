/*
	Exe_334: Viết hàm đếm số lượng số dương trong ma trận thực
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
	int dem = 0;
	for(int i = 0; i < m; i++)
	{				
		for(int j = 0; j < n; j++)
		{				
			if(a[i][j] > 0)
			{
				dem++;
			}
		}			
	}	
	return dem;
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