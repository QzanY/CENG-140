#include <stdio.h>

double calculate_pressure_on_block(int row, int column, double block_weight)
{
    double zero = 0;
    if(row==0)
    {
        return zero;
    }
    else
    {
        if(column==0)
        {
            return calculate_pressure_on_block(row-1,column,block_weight)*0.15+block_weight/2;
        }
        else if(column == row)
        {
            return calculate_pressure_on_block(row-1,column-1,block_weight)*0.15+block_weight/2;
        }
        else
        {
            return calculate_pressure_on_block(row-1,column,block_weight)*0.15+block_weight/2+calculate_pressure_on_block(row-1,column-1,block_weight)*0.15+block_weight/2;
        }
    }
}

void helper(int n,int r,int c,double weight)
{
    if(r==n)
    {
        return;
    }
    printf("(%d,%d) %.8lf\n",r,c,calculate_pressure_on_block(r,c,weight));
    if(c+1 == r+1)
    {
        helper(n,r+1,0,weight);
    }
    else
    {
        helper(n,r,c+1,weight);
    }

}

int main() {
    
    int N,W;
    scanf("%d %d",&N,&W);
    helper(N,0,0,W);
    
        
    
    return 0;
}