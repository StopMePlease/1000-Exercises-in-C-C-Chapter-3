/*
	Exe_391: Tìm ma trận con có tổng lớn nhất
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

int Kadane(int mt[], int n, int &s, int &f)
{
	int current_sum = 0;
	int sum_so_far = 0;
	s = -1,f = -1;
	for(int i = 0; i < n; i++)
	{
		current_sum += mt[i];
		if(s == -1)
		{
			s = i;
		}

		if(current_sum < 0)
		{
			current_sum = 0;
			s = -1;
		}
		else
		{
			if(sum_so_far < current_sum)
			{
				sum_so_far = current_sum;
				f = i;
			}
		}
	}
	return sum_so_far;
}

void Result(int a[][100], int m, int n)
{	
	int max_sum = 0;
	int max_left = -1, max_right = -1, max_up = -1, max_down = -1;
	int temp_max_up = -1, temp_max_down = -1;

	int left = 0, right = 0, current_sum = 0;

	int matrix_temp2[100];
	//matrix_temp2 = new int[m];
	for(int i = 0; i < m; i++)
	{
		matrix_temp2[i] = 0;
	}
	int check = 1;

	while(true)
	{
		if(check == 1)
		{		
			for(int i = 0; i < m; i++)
			{
				matrix_temp2[i] = a[i][right];
			}
			check = 0;
		}
		else
		{
			for(int i = 0; i < m; i++)
			{
				matrix_temp2[i] += a[i][right];
			}
		}
		

		current_sum = Kadane(matrix_temp2, m, max_up, max_down);
		if(current_sum > max_sum)
		{
			max_sum = current_sum;
			max_left = left;
			max_right = right;
			temp_max_up = max_up;
			temp_max_down = max_down;
		}
		else
		{
			max_up = -1;
			max_down = -1;
		}
		

		right++;
		if(right == n)
		{
			check = 1;
			left++;
			right = left;
			for(int k = 0; k < m; k++)
			{
				matrix_temp2[k] = 0;
			}
		}
		if(left == n)
		{
			break;
		}
	}

	cout << max_sum << "\n";
	cout << max_left << setw(5) << max_right << setw(5) << temp_max_up << setw(5) << temp_max_down;
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

	/*int a[] = {1, 14, -2, 4};
	int n = 4;
	int s = -1, f = -1;
	int max = Kadane(a, n, s, f);
	cout << max << "\n" << s << setw(5) << f;*/
	return 0;
}