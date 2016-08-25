/*
	Exe_428: Cho ma trân A các số thực. Tạo ma trận B từ A sao cho b[i][j] = số lượng phần tử dương xung quanh A[i][j] trong A
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
	int b[100][100] = {0};
	int ib = 0, jb = 0;

	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i == 0)
			{
				if(j == 0)
				{
					b[ib][jb] = a[i][j + 1] + a[i + 1][j + 1] + a[i + 1][j];
					jb++;
				}
				else if(j == n - 1)
				{
					b[ib][jb] = a[i][j - 1] + a[i + 1][j - 1] + a[i + 1][j];
					jb = 0;
					ib++;
				}
				else
				{
					b[ib][jb] = a[i][j - 1] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 1][j - 1] + a[i + 1][j];
					jb++;
				}
			}
			else if(i == m - 1)
			{
				if(j == 0)
				{
					b[ib][jb] = a[i][j + 1] + a[i - 1][j + 1] + a[i - 1][j];
					jb++;
				}
				else if(j == n - 1)
				{
					b[ib][jb] = a[i][j - 1] + a[i - 1][j - 1] + a[i - 1][j];
					jb = 0;
					ib++;
				}
				else
				{
					b[ib][jb] = a[i][j - 1] + a[i][j + 1] + a[i - 1][j + 1] + a[i - 1][j - 1] + a[i - 1][j];
					jb++;
				}
			}
			else if(j == 0 && i != 0 && i != m - 1)
			{
				b[ib][jb] = a[i + 1][j] + a[i - 1][j] + a[i + 1][j + 1] + a[i - 1][j + 1] + a[i][j + 1];
				jb++;
			}
			else if(j == n - 1 && i != 0 && i != m - 1)
			{
				b[ib][jb] = a[i + 1][j] + a[i - 1][j] + a[i + 1][j - 1] + a[i - 1][j - 1] + a[i][j - 1];
				jb = 0;
				ib++;
			}
			else
			{
				b[ib][jb] = a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1] + a[i][j - 1] + a[i][j + 1] + a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1];
			}
		}
	}
	Output(b, m, n);
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