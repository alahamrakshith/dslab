
/* C/C++ program to solve Rat in a Maze problem using
backtracking */
#include <stdio.h>
#include <stdbool.h>
int n;


bool solveMazeUtil(int maze[][n], int x, int y, int sol[][n],int size,int m,int n);

void printSolution(int sol[][n],int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			printf(" %d ", sol[i][j]);
		printf("\n");
	}
}

bool isSafe(int maze[][n], int x, int y,int size)
{

	if (x >= 0 && x < size && y >= 0 && y < size && maze[x][y] == 1)
		return true;

	return false;
}


bool solveMaze(int maze[][n],int size,int m,int n,int x,int y)
{
	int sol[size][size];

	if (solveMazeUtil(maze, x, y, sol,size,m,n) == false) {
		printf("Solution doesn't exist");
		return false;
	}

	printSolution(sol,size);
	return true;
}


bool solveMazeUtil(int maze[][n], int x, int y, int sol[][n],int size,int m, int n)
{

	if (x == m && y == n) {
		sol[x][y] = 1;
		return true;
	}

	if (isSafe(maze, x, y,size) == true) {

		sol[x][y] = 1;

		if (solveMazeUtil(maze, x + 1, y, sol,size,m,n) == true)
			return true;


		if (solveMazeUtil(maze, x, y + 1, sol,size,m,n) == true)
			return true;
		sol[x][y] = 0;
		return false;
	}

	return false;
}


int main()
{   int size,i,j,x,y,m,n;
    scanf("%d",&size);
	int maze[size][size];
	for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            scanf("%d",&maze[i][j]);
        }
    }
    scanf("%d%d",&x,&y);
    printf("\n");
    scanf("%d%d",&m,&n);
    size=size-1;
    n=size;
	solveMaze(maze,size,m,n,x,y);
	return 0;
}

