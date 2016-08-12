/*
	Exe_343: Đếm số lượng phần tử cực trị trong ma trận thực. Một phần tử gọi là cực trị khi nó lớn hơn hoặc nhỏ hơn các phần tử xung quanh
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
			if(i == 0)
			{
				if(j == 0)
				{
					if((a[i][j] > a[i][j + 1] && a[i][j] > a[i + 1][j]) || (a[i][j] < a[i][j + 1] && a[i][j] > a[i + 1][j]))
					{
						dem++;
					}
				}
				else if(j == n - 1)				
				{
					if((a[i][j] > a[i][j - 1] && a[i][j] > a[i + 1][j]) || (a[i][j] < a[i][j - 1] && a[i][j] < a[i + 1][j]))
					{
						dem++;
					}
				}
				else
				{
					if((a[i][j] > a[i][j + 1] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j - 1]) || (a[i][j] < a[i][j + 1] && a[i][j] < a[i + 1][j] && a[i][j] < a[i][j - 1]))
					{
						dem++;
					}
				}
			}	
			else if(i == m - 1)
			{
				if(j == 0)
				{
					if((a[i][j] > a[i][j + 1] && a[i][j] > a[i - 1][j]) || (a[i][j] < a[i][j + 1] && a[i][j] < a[i - 1][j]))
					{
						dem++;
					}
				}
				else if(j == n - 1)				
				{
					if(a[i][j] > a[i][j - 1] && a[i][j] > a[i - 1][j] || (a[i][j] < a[i][j - 1] && a[i][j] < a[i - 1][j]))
					{
						dem++;
					}
				}
				else
				{
					if((a[i][j] > a[i][j + 1] && a[i][j] > a[i - 1][j] && a[i][j] > a[i][j - 1]) || (a[i][j] < a[i][j + 1] && a[i][j] < a[i - 1][j] && a[i][j] < a[i][j - 1]))
					{
						dem++;
					}
				}
			}
			else if(j == 0 && i != 0 && i != m - 1)
			{
				if((a[i][j] > a[i - 1][j] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j + 1]) || (a[i][j] < a[i - 1][j] && a[i][j] < a[i + 1][j] && a[i][j] < a[i][j + 1]))
				{
					dem++;
				}
			}
			else if(j == n - 1 && i != 0 && i != m - 1)
			{
				if((a[i][j] > a[i - 1][j] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j - 1]) || (a[i][j] < a[i - 1][j] && a[i][j] < a[i + 1][j] && a[i][j] < a[i][j - 1]))
				{
					dem++;
				}
			}
			else
			{
				if((a[i][j] > a[i][j + 1] && a[i][j] > a[i][j - 1] && a[i][j] > a[i + 1][j] && a[i][j] > a[i - 1][j]) ||
					(a[i][j] < a[i][j + 1] && a[i][j] < a[i][j - 1] && a[i][j] < a[i + 1][j] && a[i][j] < a[i - 1][j]))
				{
					dem++;
				}
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