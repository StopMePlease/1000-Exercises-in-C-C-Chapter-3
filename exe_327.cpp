/*
	Exe_327: Tính tổng các giá trị nằm trên biên của ma trận
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
	int sum = 0;
	for(int i = 0; i < m; i++)
	{		
		for(int j = 0; j < n; j++)
		{	
			if(i == 0 || j == 0 || i == m - 1 || j == n - 1)
				sum += a[i][j];			
		}		
	}
	return sum;
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