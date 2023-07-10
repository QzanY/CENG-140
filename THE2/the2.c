#include <stdio.h>
#include <stdlib.h>


int finish(char** grid,int height,int width,int posx,int posy)
{
	if((posx==0||posx==width-1||posy==0||posy==height-1))
	{   grid[posy][posx] = '*';
	    return 1;}
	
	else 
	{
		return 0;
	}

}

int finish2(char** grid,int height,int width,int posx,int posy)
{
    if(((grid[posy+1][posx]=='.')||(grid[posy+1][posx]=='X'))&&((grid[posy-1][posx]=='.')||(grid[posy-1][posx]=='X'))&&((grid[posy][posx+1]=='.')||(grid[posy][posx+1]=='X'))&&((grid[posy][posx-1]=='.')||(grid[posy][posx-1]=='X')))
    {return 1;}
    return 0;
	}



int solver(char** grid,int width,int height,int posx,int posy)
{
	if (finish(grid,height,width,posx,posy)==1) {
		return 1;
	}
	else
	{
		if(grid[posy-1][posx]==' ')
		{
			grid[posy-1][posx]='*';
			if (solver(grid,width,height,posx,posy-1)) 
			{
				return 1;
			}
		}
		
		if(grid[posy][posx+1]==' ')
		{
			grid[posy][posx+1]='*';
			if (solver(grid,width, height,posx+1, posy)) 
			{
				return 1;
			}
		}

		

		if(grid[posy][posx-1]==' ')
		{
			grid[posy][posx-1]='*';
			if (solver(grid,width, height, posx-1, posy)) 
			{
				return 1;
			}
		}
		if(grid[posy+1][posx]==' ')
		{
			grid[posy+1][posx]='*';
			if (solver(grid, width, height, posx, posy+1)) 
			{
				return 1;
			}
		}
		return 0;
	}
	
}


int solver2(char** grid,int width,int height,int posx,int posy)
{
    int a;
	if (finish2(grid,height,width,posx,posy)==1) {
		return 1;
	}
	else
	{
		if(grid[posy-1][posx]=='*')
		{
			grid[posy-1][posx]='.';
			a=(solver2(grid,width,height,posx,posy-1));
		}
		
		if(grid[posy][posx+1]=='*')
		{
			grid[posy][posx+1]='.';
			a=(solver2(grid,width, height,posx+1, posy)) ;
		
		}

		

		if(grid[posy][posx-1]=='*')
		{
			grid[posy][posx-1]='.';
			a=(solver2(grid,width, height, posx-1, posy)) ;
			

		}
		if(grid[posy+1][posx]=='*')
		{
			grid[posy+1][posx]='.';
			a=(solver2(grid, width, height, posx, posy+1)) ;
			

		}
		
	}
	
}




int main()
{
        char** grid;
        char c;
        int pos_x,pos_y;
        int i=0,j=0;
        int w,h;
        int res;
        scanf("%d %d\n",&pos_x,&pos_y);
        grid = malloc((i+1)*sizeof(char*));
        grid[0] = malloc((j+2)*sizeof(char));
        i=0;
        j=0;
        while((c = getchar())!=EOF)
        {
                if(c == '\n')
                {
                        grid[i][j]='\0';
                        w=j;
                        j = 0;
                        i++;
                        grid = realloc(grid,(i+1)*sizeof(char*));
                        grid[i] = malloc((j+2)*sizeof(char));

                }
                else
                {
                        grid[i] = realloc(grid[i],(j+2)*sizeof(char));
                        grid[i][j] = c;
                        j++;
                }
        }
        h=i;
        grid[pos_y][pos_x] = '*';
		res = solver(grid, w, h, pos_x, pos_y);
		
		grid[h] =0;
        if(res==0)
        {
            grid[pos_y][pos_x] = '.';
            res  = solver2(grid, w, h, pos_x, pos_y);
        }
        
        
        
        for(i = 0;grid[i]!=NULL;i++)
        {
            printf("%s\n",grid[i]);
            free(grid[i]);
        }
        free(grid);

}
