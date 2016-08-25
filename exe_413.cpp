/*
	Exe_413: Viết hàm sắp xếp ma trận theo yêu cầu _Dòng có chỉ số chẵn tăng dần _Dòng có chỉ số lẻ giảm dần
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
	for(int i = 0; i < m; i++)
	{
		if(i % 2 == 0)
		{
			for(int j = 0; j < n; j++)
			{
				for(int k = j + 1; k < n; k++)
				{
					if(a[i][j] > a[i][k])
					{
						HoanVi(a[i][j], a[i][k]);
					}
				}
			}
		}
		else
		{
			for(int j = 0; j < n; j++)
			{
				for(int k = j + 1; k < n; k++)
				{
					if(a[i][j] < a[i][k])
					{
						HoanVi(a[i][j], a[i][k]);
					}
				}
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