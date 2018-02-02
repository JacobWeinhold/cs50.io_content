#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main (void)
{
int i=0, ung=0, gr=0, tmp=0, check=0;
string cmp;
bool valid=false;
long long Data=0;

//get input 
    while(Data<=0)
    {
        printf("Card Number?\n");
        Data=get_long_long();
    }

    while(Data>0)
    {
        if(i%2==0)
        {
            gr+=Data%10;
        }
        
        else
        {
            tmp=(Data%10)*2;
            if(tmp>9)
            {
                ung+=(tmp%10)+1;
            }
            else
            {
                ung+=tmp;
            }
        }
        if(Data<10)
        {
            if(Data==4)
            {
                cmp="VISA";
                valid=true;
            }
            Data=0;
        }
        else
        {
            Data/=10;
            if(Data>=51 && Data<=55)
            {
                cmp="MASTERCARD";
                valid=true;
            }
            if(Data==34 || Data==37)
            {
                cmp="AMEX";
                valid=true;
            }
        }
        i++;
    }
    check=(ung+gr)%10;
    
    //check if the number of digits fits the selected company
    
    if(check==0 && valid==true)
    {
        if(i==15)
        {
            printf("%s\n",cmp);
        }
        
        if(i==16)
        {
            printf("%s\n",cmp);
        }
  
        if (i==13)
        {
        printf("%s\n",cmp);
        }
    }
    
    else
    {
        printf("INVALID\n");
    }
return 0;
}