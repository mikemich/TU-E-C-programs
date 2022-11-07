#include <stdio.h>
#include <stdlib.h>
//
#define START 'S'
#define DESTINATION 'D'
#define PATH '+'
#define WALL '#'
#define UNSEEN '.'
#define SEEN '~'
//--------TYPEDEF-----------------------------------------//
typedef struct{
    char *grid;
    int maxX;
    int maxY;
} navigation_t;
//---------------//
typedef struct{
    int x;
    int y;
} position_t;
//---------------------TYPEDEF END---------------------//
//-------------------FUNCTIONS-------------------------//

//int isafe(navigation_t nav, int x, int y){
//    if(x >=)
//}


void newGrid(navigation_t *nav){
    int rows, columns;
    if(nav != NULL){
        nav->maxX = 0;
        nav->maxY = 0;
        free(nav->grid);
        nav->grid = NULL;
        
    }
    printf("Number of rows? ");
    scanf(" %d",&rows);
    printf("Number of columns? ");
    scanf("%d",&columns);
    int totalarr = rows * columns;
    if(rows >= 2 && columns >= 2){
    nav->grid = (char*) malloc(totalarr * sizeof(char));
    nav->maxX = columns;
    nav->maxY = rows;
    }else{
        printf("The number of rows and columns must be at least two\n");
    }
    
}
//
void inputGrid(navigation_t nav){
    //printf("xyz");
    int h = 0;
    for(int y = 0; y < nav.maxY; y++){
        if (h > 1){
            printf("Extra starting point\n");
            h = 1;
        }
            printf("Input row %d: ",y);
        for(int x = 0; x < nav.maxX; x++){
            scanf(" %c",&nav.grid[y*nav.maxX+x]);
            if (nav.grid[y*nav.maxX+x] == START){
                h += 1;
                if (h > 1){
                    nav.grid[y*nav.maxX+x] = WALL;
                }
            }
        }
    }
}
//
void printGrid(navigation_t nav){
    if(nav.grid != NULL){
        for(int y = 0; y < nav.maxY; y++){
           if(y>0) printf("\n");
            for(int x = 0; x < nav.maxX; x++){
                printf("%c",nav.grid[y*nav.maxX+x]);
            }
         }
        printf("\n");
    }
}
//
position_t findStart(navigation_t nav){
    position_t start = {-1,-1};
    int posx = -1;
    int posy = -1;
    int s = 0;
    int p = 0;
    if(nav.grid != NULL){
        for(int y = 0; y < nav.maxY; y++){
            for(int x = 0; x < nav.maxX; x++){
                if(nav.grid[y*nav.maxX+x] == START){
                    posx = x;
                    posy = y;
                    s=1;
                    
                }
                if(nav.grid[y*nav.maxX+x] == DESTINATION){
                    p=1;
                }
            }
        
      }
      if(s == 0 || p == 0){
          start.x = -1;
          start.y = -1;
      }else{
          start.x = posx;
          start.y = posy;
      }
      //if(s == 1 && p == 1) printf("The start is at x=%d and y=%d\n",posx,posy);
      if(s == 0) printf("Grid contains no starting point\n");
      if(p == 0) printf("Grid contains no destination\n");
   }
      return start;
}

//
int findPath(navigation_t nav, int x, int y, int length){
      // Go North (x,y-1)
     // Go east (x+1,y)
    // Go south (x, y+1)
   // Go west (x-1,y)
  int nlength, elength,slength,wlength;
   //printf("x=%d y=%d",x,y);
    if(nav.grid != NULL){
     if (x > nav.maxX-1 || y > nav.maxY-1 || x < 0 || y < 0) return 0; 
     //
     if (nav.grid[y*nav.maxX+x] == WALL) return 0;
     if (nav.grid[y*nav.maxX+x] == PATH) return 0;
     if (nav.grid[y*nav.maxX+x] == DESTINATION) return length;
     if(length > 0){if (nav.grid[y*nav.maxX+x] == START) return 0;}
     //
     if (nav.grid[y*nav.maxX+x] != START) nav.grid[y*nav.maxX+x] = PATH;
     //
     
     
     if((nlength = findPath(nav,x,y-1,length+1))) return nlength;
     if((elength = findPath(nav,x+1,y,length+1))) return elength;
     if((slength = findPath(nav,x,y+1,length+1))) return slength;
     if((wlength = findPath(nav,x-1,y,length+1))) return wlength;
     if(nav.grid[y*nav.maxX+x] != START) nav.grid[y*nav.maxX+x] = SEEN;
     return 0;
    }
    return 0;
}
//
void resetPath(navigation_t nav){
    for(int i = 0; i < nav.maxX * nav.maxY; i++){
        if (nav.grid[i] == PATH || nav.grid[i] == SEEN){
            nav.grid[i] = UNSEEN;
        }
    }
}
//
int longestPath(navigation_t nav, int x, int y, int length){
      // Go North (x,y-1)
     // Go east (x+1,y)
    // Go south (x, y+1)
   // Go west (x-1,y)
  int nlength, elength,slength,wlength;
   //printf("x=%d y=%d",x,y);
    if(nav.grid != NULL){
     if (x > nav.maxX-1 || y > nav.maxY-1 || x < 0 || y < 0) return 0; 
     //
     if (nav.grid[y*nav.maxX+x] == WALL) return 0;
     if (nav.grid[y*nav.maxX+x] == PATH) return 0;
     if (nav.grid[y*nav.maxX+x] == DESTINATION) return length;
     if(length > 0){if (nav.grid[y*nav.maxX+x] == START) return 0;}
     //
     if (nav.grid[y*nav.maxX+x] != START) nav.grid[y*nav.maxX+x] = PATH;
     //
     
     
     if((wlength = findPath(nav,x-1,y,length+1))) return wlength;
     if((slength = findPath(nav,x,y+1,length+1))) return slength;
     if((elength = findPath(nav,x+1,y,length+1))) return elength;
     if((nlength = findPath(nav,x,y-1,length+1))) return nlength;
    // if(nav.grid[y*nav.maxX+x] != START) nav.grid[y*nav.maxX+x] = SEEN;
     return 0;
    }
    return 0;
}
//--------------FUNCTIONS END---------------------------

int main(){
navigation_t nav = {NULL,0,0};
position_t start; 
char cmd;
int length = 0;
    do{               //loop start 
    printf ("Command? ");
    scanf(" %c",&cmd);
    switch(cmd){
        case 'i':
        newGrid(&nav);
        inputGrid(nav);
        break;
        //
        case 'p':
        printGrid(nav);
        break;
        //
        case 's':
         start = findStart(nav);
        if (start.x != -1 && start.y != -1)printf("The start is at x=%d and y=%d\n",start.x,start.y);
        break;
        //
        case 'f':
        start = findStart(nav);
         int x = findPath(nav,start.x,start.y,length);
         if(x > 0){
             printf("Found a path of length %d\n",x);
         }else printf("No path found\n");
        printGrid(nav); 
        break;
        //
        case 'r':
        resetPath(nav);
        break;
        //
        case 'l':
        start = findStart(nav);
        longestPath(nav,start.x,start.y,length);
        //printf("Found a path of length %d\n",y);
        break;
    default:
    if(cmd != 'q') printf("Unknown command '%c'\n",cmd);//default
    break;
    }
}while (cmd != 'q');{// loop end commands
free(nav.grid);
printf("Bye!\n");
}
}// main end bracket





// Go North (x,y-1)
// Go east (x+1,y)
// Go south (x, y+1)
// Go west (x-1,y)
