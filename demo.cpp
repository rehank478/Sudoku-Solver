#include <iostream>
#include <unistd.h>
using namespace std;

int sudoku[9][9];
bool mark[9][9] = {};

void print()
{
    for (int i = 0;i < 9;i++) {
        for (int j = 0;j < 9;j++)
            if (sudoku[i][j] == 0)
                cout << "- ";
            else if (mark[i][j] == 0)
                cout << "\033[1m\033[33m" << sudoku[i][j] << "\033[0m ";
            else
                cout << "\033[1m\033[34m" << sudoku[i][j] << "\033[0m ";
        cout << "\n";
    }
}

bool solve() {
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			if(sudoku[i][j] == 0) {
				bool arr[10] = {0};
				for(int k=0;k<9;k++)
					arr[sudoku[i][k]] = 1;
				for(int k=0;k<9;k++)
					arr[sudoku[k][j]] = 1;
				int sc = 3*(j/3);
				int sr = 3*(i/3);
				for(int x=sr;x<sr+3;x++)
					for(int y=sc;y<sc+3;y++)
						arr[sudoku[x][y]] = 1;
				for (int k = 1;k < 10;k++)
					if (arr[k] == 0) {
						sudoku[i][j] = k;
                        system("clear");
                        print();
                        usleep(200000);
						if(solve()==1)
							return 1;		
					}
				sudoku[i][j] = 0;
				return 0;
			}
	return 1;
}

int main()
{
    string input;
	for (int i = 0;i < 9;i++) {
        cin >> input;
        for (int j = 0;j < 9;j++) {
                sudoku[i][j] = input[j] - '0';
                if (sudoku[i][j] != 0)
                    mark[i][j] = 1;
        }
    }
	if (!solve())
        cout << "\033[1m\033[31mInvalid Input\033[0m\n";
}
