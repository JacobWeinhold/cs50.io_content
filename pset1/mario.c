#include <stdio.h>
#include <cs50.h>

int main (void)
{
   int height=0;

   do
   {
       printf("Height:\n");
       height=get_int();
    }
    while(height<0 || height>=24);

    for(int i=0; i<height;i++)
    {
        int blanks=height-(i+1);

        for (int j=0;j<blanks;j++)
        {
            printf(" ");
        }

        for(int k=0;k<=i;k++)
        {
        printf("#");
        }

        printf("  ");

        for(int k = 0; k <= i; k++)
		{
			printf("#");
		}

      printf("\n");
    }
}


