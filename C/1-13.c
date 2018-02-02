#include <stdio.h>

#define MAX 30
#define IN 1
#define OUT 0

int main()
{
    int c,
        state=OUT;
        wcount=0, lcount=0;
        freq[MAX];
    
    for(int i=0; i<MAX; i++)
    {
        freq[i]=0;    
    }
    
    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\n' || c== '\t')
        {
            if(state==IN)
            {
                ++freq[lcount];
                wcount++, state=OUT;
                lcount=0;
            }
            
        }
        
        else if ((c>=65 && c<=90) ||( c>= 97 && c<=122))
        {
            state=IN;
            lcount++;   
        }
    }
    
    for(int i=0; i<MAX; i++)
    {
        if(i>0)   
        printf("%i\t",i);
    
        for(int n=0; n<freq[i];n++)
        {
            printf("*");
        }
        printf("\n");
    }
}