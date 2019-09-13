#include<iostream>
#include<vector>
using namespace std;

bool solve(int sudoku[9][9])
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(sudoku[i][j] == 0)
			{
				bool arr[10] = {0};
				for(int k=0;k<9;k++)
				{
					arr[sudoku[i][k]] = 1;
				}
				for(int k=0;k<9;k++)
				{
					arr[sudoku[k][j]] = 1;
				}
				int sc = 3*(j/3);
				int sr = 3*(i/3);
				for(int x=sr;x<sr+3;x++)
				{
					for(int y=sc;y<sc+3;y++)
					{
						arr[sudoku[x][y]] = 1;
					}
				}
				
				for (int k = 1;k < 10;k++)
				{
					if (arr[k] == 0) {
						sudoku[i][j] = k;
						if(solve(sudoku)==1)
						{
							return 1;
						}
							
					}
				}
				sudoku[i][j] = 0;
				return 0;
			}
		}
		
	}
	return 1;
}

int main()
{
	int sudoku[9][9];
	cout << "Enter your sudoku here:\n";
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cin >> sudoku[i][j];
		}
	}
	solve(sudoku);
	cout << "\n\nSudoku solved:\n" ; 
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout << sudoku[i][j] << " " ;
		}
		cout << endl;
	}
}
