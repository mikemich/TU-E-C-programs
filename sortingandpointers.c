#include <stdio.h>
#include <string.h>
#define LENGTH 100

void printString(char str[]){
   int s = 1;
   // printf("\"");
    for (int i = 0; i < LENGTH; i++){
        if(str[i] == '\0') printf("\\0");
        else if(s == 1 && str[i] != '\n'){
            printf("%c",str[i]);
        }
      //  printf("\"");
        }printf("\n");
}

void insertName(char *startPos[], int *nrNames, char newName[]){
    strcpy(startPos[*nrNames],newName);
    startPos[*nrNames+1] = startPos[*nrNames] +strlen(newName) + 1;
    *nrNames += 1;
    
}
int totalLength(char *startPos[], int nrNames){
    int length = 0;
    for (int i = 0; i < nrNames; i++){
        length += strlen(startPos[i]) + 1;
    }return length;
}

void printNames(char names[], char *startPos[], int nrNames){
    for(int i = 0; i < nrNames; i++){
        int x = startPos[i]-names;
    printf("startPos[%d]=%02d",i,x);
    printf(" length=%02ld", strlen(startPos[i])+ 1);
    printf(" string=\"%s\"\n", startPos[i]);
       //char x = names[*startPos[i]];   
    //    printf("%s",x);
    }
}
 int lookupNamePos(char names[], char *startPos[], int nrNames, char name[]){
     int index= -1;
     int t = 0;
     for(int i = 0; i<nrNames; i++){
         if(strcmp(startPos[i], name)== 0){
             t = startPos[i] - names;
             index = t;
         }
     }return index;
 }
 void removeName(char *startPos[], int *nrNames, char remName[]){
     for(int i = 0; i<*nrNames; i++){
         if(strcmp(startPos[i], remName)== 0){
             startPos[i] = startPos[*nrNames - 1];
             startPos[*nrNames-1] = startPos[*nrNames];
             *nrNames = *nrNames -1;
             return;
         }
     }
 }

int main (void){
    char remName[LENGTH] = "\0";
    char name[LENGTH] = "\0";
    int nrNames = 0;
    char cmd = 0;
    char * startPos[LENGTH];
    char names[LENGTH] = {0};
    char newName[LENGTH] = {0};
    startPos[0] = names;
    while (cmd != 'q'){
        printf("Command? ");
        scanf(" %c",&cmd);
    if (cmd != 'p' && cmd != 'q' && cmd != 'b' && cmd != 'i' && cmd != 'n' && cmd != 'e' && cmd != 'l' && cmd != 'r') printf("Unknown command '%c'\n",cmd);
    if (cmd == 'p') printString(names);
    if (cmd == 'b'){
        for(int i = 0; i < LENGTH; i++){
         //   &startPos[1] = cmd;
            printf("[%d] = %p\n",i, &names[i]);
        }
    }
    if (cmd == 'i'){
        printf("Name? ");
        scanf("%s",newName);
        insertName(startPos,&nrNames,newName);
        //startPos[nrNames] = &names[]
       // strcpy(names,newName);
       // printf("%s", names);
    }
    if (cmd == 'n'){
        printNames(names,startPos,nrNames);
    }
    if (cmd == 'e'){
        printf("Total length is %d\n", totalLength(startPos, nrNames));
    }
    if (cmd == 'l'){
        printf("Name? ");
        scanf(" %s", name);
        printf("\"%s\" has index %d\n", name, lookupNamePos(names,startPos, nrNames, name));
        }
    if (cmd == 'r'){
        printf("Name? ");
        scanf(" %s", remName);
        removeName(startPos, &nrNames, remName);
    }
        
    }
    printf("Bye!\n");
    
}