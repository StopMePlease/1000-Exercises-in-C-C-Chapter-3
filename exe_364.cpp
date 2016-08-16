/*
	Exe_364: Cho hai ma trận A và B. Kiểm tra A có là con B?
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

void Input2(int b[][100], int m2, int n2)
{
	for(int i = 0; i < m2; i++)
	{
		for(int j = 0; j < n2; j++)
		{
			cout << "b[" << i << "][" << j << "]: ";
			cin >> b[i][j];
		}
	}
}

void Output2(int b[][100], int m2, int n2)
{
	for(int i = 0; i < m2; i++)
	{
		for(int j = 0; j < n2; j++)
		{
			cout << setw(4) << b[i][j] ;
		}
		cout << endl;
	}
}

int Result(int a[][100], int m, int n, int b[][100], int m2, int n2)
{			
	int temp_i = 0;
	int temp_j = 0;
	while(true)
	{
		int check = 0;
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(b[temp_i][temp_j] == a[i][j])
				{
					check = 1;
					break;
				}
			}
			if(check == 1)
			{
				break;
			}
		}

		if(check == 0)
		{
			return 0;
		}

		temp_j += 1;
		if(temp_j == n2)
		{
			temp_j = 0;
			temp_i += 1;
		}

		if(temp_i == m2 )
		{
			break;
		}
	}
	return 1;
}

int main()
{
	int a[100][100];
	int n, m;
	cout << "Input rows: ";
	cin >> m;
	cout << "Input columns: ";
	cin >> n;

	int b[100][100];
	int n2, m2;
	cout << "Input rows b: ";
	cin >> m2;
	cout << "Input columns b: ";
	cin >> n2;

	Input(a, m, n);
	Output(a, m, n);

	Input2(b, m2, n2);
	Output2(b, m2, n2);

	if((m2 * n2) > (m * n))
	{
		cout << "wrong";
	}
	else
	{
		int kq = Result(a, m, n, b, m2, n2);
		cout << kq;
	}
	
	return 0;
}