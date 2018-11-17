// O(mn)
#include <bits/stdc++.h>
using namespace std;

void spiralPrint(int ending_row, int ending_column, int a[3][6])
{
	int starting_row = 0, starting_column = 0;

	while(starting_row<ending_row && starting_column<ending_column)
	{
		/* Print the first row from the remaining rows */
		for (int i = starting_column; i < ending_column; ++i)
		{
			cout<<" "<<a[starting_row][i];
		}
		starting_row++;

		/* Print the last column from the remaining columns */
		for (int i = starting_row; i < ending_row; ++i)
		{
			cout<<" "<<a[i][ending_column-1];
		}
		ending_column--;

		/* Print the last row from the remaining rows */
		if ( starting_row < ending_row)
		{
			for (int i = ending_column-1; i >= starting_column; --i)
			{
				cout<<" "<<a[ending_row-1][i];
			}
			ending_row--;
		}

		/* Print the first column from the remaining columns */
		if (starting_column < ending_column)
		{
			for (int i = ending_row-1; i >= starting_row; --i)
			{
				cout<<" "<<a[i][starting_column];
			}
			starting_column++;
		}
	}
}

/* Driver program to test above functions */
int main()
{
	int a[3][6] = { {1, 2, 3, 4, 5, 6},
                    {7, 8, 9, 10, 11, 12},
                    {13, 14, 15, 16, 17, 18}
	};

	spiralPrint(3, 6, a);
	return 0;
}

