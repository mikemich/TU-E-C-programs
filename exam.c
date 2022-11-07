#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "predefined.h"

//
//
//extern void predefined_printConcordance(entry_t concordance[]);
//
//---------------- FUNCTIONS -------------------------------------------------
void addWord(entry_t concordance[], char *word){
    entry_t temp;
    int i = 0;
    int s = 0;
        while(concordance[i].word != NULL){ 
           if(strcmp(concordance[i].word, word) == 0) s = 1;
         //  printf(" words:%s ",concordance[i].word);
           //printf("word:%s ",word);
           //printf("s is :%d",s);
            i++; 
    }
   // printf("%d",i);
    if(s == 0){
    concordance[i].word = (char*) malloc((strlen(word)+1)* sizeof(char));
    strcpy(concordance[i].word,word);}
    for(int x = 0; x < MAXWORDS; x++){
        for(int y = 0; y < MAXWORDS-1; y++){
            if(concordance[y].word != NULL && concordance[y+1].word != NULL)
            if(strcmp(concordance[y].word,concordance[y+1].word) > 0){
                temp = concordance[y];
                concordance[y] = concordance[y+1];
                concordance[y+1] = temp;
            }
        }
    }
  //  for(int i = 0; i < 3; i++){
   // printf("%s,",concordance[i].word);}
   
}
//
void printConcordance(entry_t concordance[]){
    int s = 0;
    for(int i = 0; i < MAXWORDS; i++){
        if (concordance[i].word != NULL) s = 1;
    }
    if(s == 1){
    printf("Concordance\n");
    for(int i = 0; i < MAXWORDS; i++){
        if(concordance[i].word != NULL){
            printf("%10s:",concordance[i].word);
            for(int j = 0; j < 10; j++){
            if(concordance[i].indices[j] > -1) printf(" %d",concordance[i].indices[j]);}
            printf("\n");
            }
    }
    }else printf("The concordance is empty\n");
    
}
//
void addIndex(entry_t concordance[], char *word, int index){
    int s = 0;
    for(int i = 0; i < MAXWORDS; i++){
        if(concordance[i].word != NULL){
        if(strcmp(concordance[i].word,word) == 0){
            for(int j = 0; j < 10; j++){
            if(concordance[i].indices[j] == -1 && s == 0) {
            concordance[i].indices[j] = index;
                s = 1;
    }}
                
            }
}
}if(s == 0) printf("Word %s not found\n",word);
}
//
void readFile(entry_t concordance[], char *filename, int *index){
    int i = *index;
    char tempword[100];
    char tempword2[100];
    FILE* fh;
    printf("File name? ");
    scanf(" %s",filename);
    fh = fopen(filename, "r");
    if (NULL == fh){
        printf("Cannot open file %s\n",filename);
        return;
        }
    //
    /*do { 
        while(1){
            c = fgetc(fh);
            if(c == EOF || c == ' ' || c == '\n') break;
            tempword[i] = c;
        }*/
        int l = 0;
    while (1){ 
        //fgets(tempword,99,fh);
        fscanf(fh," %s",tempword);
        if(strcmp(tempword,tempword2) == 0) break;
        if (tempword == tempword2) break;
        //printf("%s\n",tempword);
        addWord(concordance,tempword);
        addIndex(concordance,tempword,i);
        for(int s = 0; s < 100; s++){
            tempword2[s] = tempword[s];
        }
        i++;
        l++;
      *index = i;  
}
printf("Inserted %d words\n",l);
//
/*while(1){
    c = fgetc(fh);
    if(c == EOF) return;
    printf("%c",c);
}*/
}
//
void test(int *hehe){
    *hehe = 1;
}
//
void removeWord(entry_t concordance[], char *word){
    entry_t temp;
    int s = 0;
    int i = 0;
    while(i<MAXWORDS){ 
        if(concordance[i].word != NULL){
           if(strcmp(concordance[i].word, word) == 0){
               s = 1;
               free(concordance[i].word);
               concordance[i].word = NULL;
               for (int j = 0; j < 10; j++){
                   concordance[i].indices[j] = -1;
               }
             
               //concordance[i].word = NULL;
           }
         //  printf(" words:%s ",concordance[i].word);
           //printf("word:%s ",word);
           //printf("s is :%d",s);
            
            
}i++;}
//free(concordance[i].word);
for(int x = 0; x < MAXWORDS; x++){
        for(int y = 0; y < MAXWORDS-1; y++){
            if(concordance[y].word != NULL && concordance[y+1].word != NULL)
            if(strcmp(concordance[y].word,concordance[y+1].word) > 0){
                temp = concordance[y];
                concordance[y] = concordance[y+1];
                concordance[y+1] = temp;
            }
        }
    }
if (s == 0){
    printf("Word %s not found\n",word);
}
}
//
char *findWordAtIndex(entry_t concordance[], int index){
  //  printf("index:%d",index);
for(int x = 0; x < MAXWORDS; x++){
    if(concordance[x].word!= NULL){
        for(int y = 0; y < 10; y++){
      //     printf("x:%d:y:%d",x,y);
            if (index == concordance[x].indices[y]){
            return concordance[x].word;}
        
    }    
}
}
return NULL;
}
//
void printOriginalText(entry_t concordance[]){
    int maxindex = 0;
    for(int x = 0; x < MAXWORDS; x++){
    if(concordance[x].word!= NULL){
        for(int y = 0; y < 10; y++){
      //     printf("x:%d:y:%d",x,y);
            if (maxindex < concordance[x].indices[y]){
               maxindex = concordance[x].indices[y];  
            }
        
    }    
}
}
maxindex++;
int s;
int final = 0;
    while (final < maxindex){
        s = 0;
        for(int x = 0; x < MAXWORDS; x++){
    if(concordance[x].word!= NULL){
        for(int y = 0; y < 10; y++){
            if ( final == concordance[x].indices[y]){
               printf("%s",concordance[x].word);
               if(final < maxindex-1){
                   printf(" ");
               }
               s = 1;
            }
        
    }    
}
}
if(s != 1){ 
    printf("?");
    if(final < maxindex-1){
                   printf(" ");
               }
}
final++;
    }
printf("\n");

}
//
void sortConcordance(entry_t concordance[]){
entry_t temp;
/*
     int maxindex = 0;
    for(int x = 0; x < MAXWORDS; x++){
    if(concordance[x].word!= NULL){
        for(int y = 0; y < 10; y++){
      //     printf("x:%d:y:%d",x,y);
            if (maxindex < concordance[x].indices[y]){
               maxindex = concordance[x].indices[y];  
            }
        
    }    
}
}
maxindex++;
int s;
int final = 0;
    while (final < maxindex){
        s = 0;
        for(int x = 0; x < MAXWORDS; x++){
    if(concordance[x].word!= NULL){
        for(int y = 0; y < 10; y++){
            if ( final == concordance[x].indices[y]){
               printf("%s",concordance[x].word);
               if(final < maxindex-1){
                   printf(" ");
               }
               s = 1;
            }
        
    }    
}
}
if(s != 1){ 
    printf("?");
    if(final < maxindex-1){
                   printf(" ");
               }
}
final++;
    }
printf("\n");

}*/
/*for(int z = 1; z < MAXWORDS; z++){
    if(concordanz)
    if(concordance[z-1].word == NULL){
                temp = concordance[z];
                concordance[z] = concordance[z-1];
                concordance[z-1] = temp; 
}}*/
/*for(int x = 0; x < MAXWORDS; x++){
        for(int y = 1; y < MAXWORDS; y++){
            
            if(concordance[y].word < concordance[y-1].word){
                temp = concordance[y];
                concordance[y] = concordance[y-1];
                concordance[y-1] = temp;
            }
        }
    }*/
//for(int ee = 0; ee < 3; ee++){
 for(int x = 0; x < MAXWORDS; x++){
        for(int y = 0; y < MAXWORDS-1; y++){
            if(concordance[y].word != NULL)
            if(concordance[y].indices[0] > concordance[y+1].indices[0]){
                temp = concordance[y];
                concordance[y] = concordance[y+1];
                concordance[y+1] = temp;
            }
        }
    }
     /*for(int x = 0; x < MAXWORDS; x++){
        for(int y = 1; y < MAXWORDS; y++){
            if(concordance[y].word != NULL && concordance[y-1].word != NULL)
            if(concordance[]){
                temp = concordance[y];
                concordance[y] = concordance[y-1];
                concordance[y-1] = temp;
            }
        }
    }*/
 /*   temp.word = "xxx";
    if(concordance[0].word == temp.word){
        temp = concordance[1];
        concordance[1] = concordance[0];
        concordance[0] = temp;
    }*/
//}
}

//------------------------------ FUNCTIONS END ---------------------------------------------
int main (void)
{
    //int hehe = 0;
   // char ind;
    int findex;
    int fileIndex = 0;
    char word[MAXWORDS];
    char filename[10];
    char cmd = '0';
    int index;
    entry_t concordance[MAXWORDS] = { { 0 } };
    for(int i = 0; i < MAXWORDS; i++){
        //concordance[i].word = NULL;
        for(int j = 0; j < 10; j++){
        concordance[i].indices[j] = -1;
        }
    }
       // printf("%d ",concordance[5].indices[5]);
    do{ //loop start
    printf("Command? ");
    scanf(" %c",&cmd);
        switch(cmd){
            case 'w':
            printf("Word? ");
            scanf(" %s",word);
            addWord(concordance,word);
            break;
            //
            case 'p':
            printConcordance(concordance);
            break;
            //
            case 'i':
            printf("Word index? ");
            scanf(" %s",word);
            scanf(" %d",&index);
            addIndex(concordance, word,index);
            index = 0;
            break;
            //
            case 'r':
            readFile(concordance,filename,&fileIndex);
            break;
            //
            case 'W':
            printf("Word? ");
            scanf("%s",word);
            removeWord(concordance,word);
            break;
            //
            case 'f':
            findex = 0;
            printf("Index? ");
            scanf("%d",&findex);
            if (findWordAtIndex(concordance,findex) != NULL){
            printf("The word at index %d is %s\n",findex,findWordAtIndex(concordance,findex));
            }else{
                printf("There is no word at index %d\n", findex);
            }
            break;
            //
            case 'o':
            //test(hehe);
           // printf("%d",hehe);
           printOriginalText(concordance);
            break;
            //
            case 's':
            sortConcordance(concordance);
            break;
        default: //def case
        if(cmd != 'q') printf("Unknown command '%c'\n",cmd);
        break;
        }//
    }while(cmd != 'q');
    //for(int i = 0; i < MAXWORDS; i++){
    int i = 0;
    while(i < MAXWORDS){
        if(concordance[i].word!= NULL){
          free(concordance[i].word);}
            i++;
    }
  //  concordance[i].word = NULL;
   // }
    printf("Bye!\n");
}
