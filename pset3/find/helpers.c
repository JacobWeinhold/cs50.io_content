#include <cs50.h>
#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

 //binarysearch in an iterative way
 
bool search(int value, int values[], int n)
{
    
    int start=0, end=n, mid=0, midpos=0;
    
    while(end>=start)
    {
        
        midpos=(start+end)/2; 
    
        mid=values[midpos];
    
        if(mid==value)
            return true;
        
        if(mid<value)
            start=++midpos;
        
        if(mid>value)
            end=--midpos;
    
    }
    return false;
}   


void sort(int values[], int n)
{
    int count=0, zahl=0;
    int max=65536;
    int countarr [max];
 
    //make countarr[] all zeroes
    memset (countarr, 0, sizeof(countarr));
    
    //store the quantity of each number in values[] in countarr[]
    for(int i=0;i<n;i++)
    {
        zahl=values[i];
        countarr[zahl]++;                                                                     
    }
                                
    //iterate through countarr and fill values[] with the numbers stored sorted in countarr[]                            
    for(int i=0;i<max;i++)
    {
        while(countarr[i]>0)
        {
            values[count]=i;
            countarr[i]--;
            count++;
        }
    }
}   
    

