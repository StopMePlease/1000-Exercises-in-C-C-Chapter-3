/*
	Exe_422: Hãy sắp xếp các dòng theo tiêu chuẩn sau: dòng có tổng nhỏ hơn nằm trên và dòng có tổng lớn nằm ở dưới
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

void HoanViDong(int a[][100], int r1, int r2, int n)
{
	for(int i = 0; i < n; i++)
	{
		HoanVi(a[r1][i], a[r2][i]);
	}
}

int SumDong(int a[][100], int r, int n)
{
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum+= a[r][i];
	}
	return sum;
}

void Result(int a[][100], int m, int n)
{	
	for(int i = 0; i < m; i++)
	{
		int sum1 = SumDong(a, i, n);
		for(int j = i + 1; j < n; j++)
		{
			int sum2 = SumDong(a, j, n);
			if(sum1 > sum2)
			{
				HoanViDong(a, i, j, n);
			}			
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