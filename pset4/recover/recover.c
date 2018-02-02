#include <stdio.h>
#include <cs50.h>
#include <stdint.h>

int main(int argc, char* argv[]){
    
    if(argc!=2)
    {
        fprintf(stderr, "Usage: ./recover filename\n");
        return 1;  
    }
    
    char *infile = argv[1];
    
    FILE *card=fopen(infile, "r");
    
    if (card==NULL)
    {
        fprintf(stderr, "Could not open file\n");
        return 2;
    }
    
    char filename [50];
    
    uint8_t buffer [512];
    
    int jpgcount=0, count=0;
    
    FILE *img;
    
    while(fread(buffer, 512, 1, card))
    {
        //start of a new JPG?
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
           (buffer[3] & 0xf0) == 0xe0)
        {
            
            if(jpgcount>0)
            {
            fclose(img);
            }
            
            sprintf(filename, "%03d.jpg", count++);
            img = fopen(filename, "w");
            jpgcount++;
        }

        if(jpgcount>0)
        {
        fwrite(buffer, sizeof(buffer), 1, img);
        }
    
    }
//close all files and exit
fclose(img);
fclose(card);
return 0;
}