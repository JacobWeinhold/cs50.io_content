/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(int d);
void draw(int d);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init(d);

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw(d);

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            //usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(400000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init (int d)
{
    //initialize variable with the biggest number in the game and fill the board array counting down from it    
    int sq=d*d-1;
    
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<(d);j++)
        {
            board[i][j]=sq;
            sq--;
            
            //if the bord dimensions are of an even number swap the positions of 1 and 2 in the board
              if(board[i][j]==2&&(d%2==0)){
                  
                board[i][j]=1;
                
                board[i][++j]=2;
                
                j++;
        }
      }
    }
  
  }  

/**
 * Prints the board in its current state.
 */
    void draw (int d)
    {
    
    
    //iterate through board array and print field with number 0 as "-", rest as it is
        for(int i=0;i<d;i++)
        {
        
            for(int j=0;j<(d);j++)
            {
            
                if(board[i][j]==0)
                {
                    printf(" - ");
                }
                
                                    
                else
                    printf(" %2i ",board[i][j]);
                    
            }
                printf("\n");
        }
    }

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
 
bool move (int tile)
{
    int tilerow, tilecol;
    int spacerow, spacecol;
    
    //store values representing the position of tile and zero
    
            for(int i=0;i<d;i++){
    
        for(int j=0;j<d;j++){
    
    if(board[i][j]==tile){
        tilerow=i, tilecol=j;
                            }
    
    if(board[i][j]==0){
        
        spacerow=i, spacecol=j;
                        }
                            }
                                }
                                
                                
        if(tile==board[spacerow+1][spacecol]){
            board[spacerow][spacecol]=tile;
            board[tilerow][tilecol]=0;
            return true;
        }
        
    else if (tile==board[spacerow][spacecol+1]){
        board[spacerow][spacecol]=tile;
        board[tilerow][tilecol]=0;
        return true;
    }
    
    else if(tile==board[spacerow-1][spacecol]){
        board[spacerow][spacecol]=tile;
        board[tilerow][tilecol]=0;
        return true;
}

    else if(tile==board[spacerow][spacecol-1]){
        board[spacerow][spacecol]=tile;
        board[tilerow][tilecol]=0;
        return true;
    }
    
    else{
        return false;
    }
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int count=0;

    /** iterate through board array and check if it counts up one by one starting from top to bottom, left to right
      * except for the last position in board array which has to be zero, return true if it is
      */
      
    for(int row=0;row<d;row++)
    {
    
        for(int column=0;column<d;column++)
        {
        
            if( d-1 == row && d-1 == column && board[row][column] == 0)
            {
                return true;
            }
        
        
            if(board[row][column]!=(++count))
            {
            return false;
            }
        
        }
    }

    return false;
}