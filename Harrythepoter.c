#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 struct person  {
        char *name;
        float height;
    };
    
  void printPersons(struct person persons[], int nrPersons, int from, int to){
        if(persons != NULL){
            printf("[");
        for(int i = from; i < nrPersons; i++){
            if(persons[i].name != NULL){
            printf("%d",nrPersons);
            
           printf("(\"%s,%0.3f\")",persons[i].name,persons[i].height);
                if(i < nrPersons)printf(",");}
            }
        }else printf("[]");
        
    }
  
  
  struct person *removeAllPersons(struct person *persons, int nrPersons){
      if (persons != NULL){
      for (int i = 0; i < nrPersons; i++){
        persons[i].name = NULL;
    }
    free(persons);
    persons = NULL; 
      }
    return persons;
  }
  

int main(void){
    
    int from = 0;
    struct person *persons = NULL;
    int nrPersons;
    //char *persons = NULL;
    char cmd = '0';
    //int to = 0;
   
   // struct person one_person;
   // struct person person[10];
    //int *intarray = (int *) malloc (nrPersons * sizeof(int));
    
    do{ printf("Command? ");
        scanf(" %c",  &cmd);
        switch (cmd){
        case 'n':
        removeAllPersons(persons, nrPersons);
        printf("Entries? ");
        scanf(" %i", &nrPersons);
        int to = nrPersons;
        if (nrPersons > 0){
            persons = (struct person*)malloc(nrPersons * sizeof(struct person));
            if (persons == NULL){
         printf("Malloc returned NULL");
         return 0;
            }else{
                
                    for(int i = 0; i < nrPersons; i++){
                        persons[i].name = NULL;
                        persons[i].height = 0.0;
                    }
                }
            }
        
        else persons = NULL;
        break;
        case 'p':
        //printf("y");
        
        to = nrPersons;
        printPersons(persons, nrPersons, from, to);
        break;
        default:
        if (cmd != 'q' && cmd != 'n') printf("Unknown command '%c'\n",cmd);
            break;
        }
    }while(cmd != 'q');
    removeAllPersons(persons, nrPersons);
    printf("Bye!\n");
}
