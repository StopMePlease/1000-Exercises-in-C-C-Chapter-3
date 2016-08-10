/*
	Exe_340: Đếm số lượng số âm trên 1 cột trong ma trận thực
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
	for(int i = 0; i < n; i++)
	{				
		int dem = 0;
		for(int j = 0; j < m; j++)
		{				
			if(a[i][j]< 0)
			{
				dem++;
			}
		}	
		cout << "Column " << i << " : " << dem << endl;
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