#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int show_path(int arr[4][5])
{
    int i=3,j=4;
    int cost =0;
    printf("Path-> ");
    while(i!=0 && j!=0)
    {
        
        int left = -1;
        int right = -1;
        int num = arr[i][j];
        if(j-1>=0)
            left = arr[i][j-1];
        if(i-1>=0)
            right = arr[i-1][j];
        if(left!=-1 && left<num)
        {
            printf(" left\n");
            j-=1;
        }
        else
        {
            printf(" up\n");
            i-=1;
        }
        cost += num;
    }
    return cost;
}
int main()
{
    int grid[4][5];
    for(int row=0 ; row<4 ; row++)
    {
        for(int col=0 ; col<5 ; col++)
            grid[row][col] = rand()%(9)+1;
    }
    int cost = show_path(grid);
    printf("\nIt's cost: %d",cost);
    return 0;
}