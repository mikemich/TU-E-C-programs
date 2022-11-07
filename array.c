#define LENGTH 30
#include <stdio.h>
#include <string.h>
void readline(char str[], int length){
  int i=0;
  if(length < 1) return;
  while(1){
      str[i] = getchar();
      if(str[i] == '\n'){
          str[i] = '\0';
          return;
      }
      if (i < length -1){
          i++;
      }
  }
}

void printString(char str[]){
    int s = 1;
    printf("\"");
    for (int i=0; i < 30; i++){
        if(str[i] == '\0') s = 0;
      //  if(str[i] == '\n') printf("\\n");
        if(s == 1 && str[i] != '\n'){
        putchar(str[i]);}
    }
    printf("\"");
    printf("\n");
}
void printArray(char a[],int length){
    for (int i=0; i < length; i++){
    if(i == 0) printf("[");
    if(a[i] == '\n') printf("\\0");
    if (a[i]!='\n'&& a[i] == '\0'){ 
        printf("\\0");
        if (i != length-1){
            printf(",");
        }
    }
    else if(a[i] != '\n'){ 
        printf("%c", a[i]);}
        if ( i != 30 && a[i] != '\0'){
            printf(",");
        }
    }printf("]\n");
}
void findFirstOccurrence(char str[], char aChar){
    int s = 1;
    int ind = -1;
    for (int i=0; i<LENGTH; i++){
        if(s == 1){
            if(str[i] == aChar){
                s = 0;
                ind = i;
            }
        }
    }
    printf("The first occurrence of \'%c\' is at index ", aChar);
    printf("%d\n",ind);
}
int readInt(char str[], int length){
    char inter[LENGTH] = "";
    int s = 1;
    for (int i=0; i < LENGTH; i++){
        if(s == 1){
            if(str[i] == '0' || str[i] == '1' || str[i] == '2'|| str[i] == '3'|| str[i] == '4'|| str[i] == '5'|| str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9'){
                inter[i] = str[i];
            }else s= 0;
        }
    }
  int i, value, r;
  i = value = 0;
  for(i = 0; i< strlen(inter); ++i){
      r = inter[i] - '0';
      value = value * 10 +r;
  }
  if(value == 0) value = -1;
  return value;
    
}
void insertChar(char str[], char aChar, int index){
   int s = 1;
   char temp[30]= "\0";
   if(index == -1) index = 0;
   for(int i=0; i < 29; i++){
       if(i == index){
         s = 0;
       }
       if(s == 0){
           temp[i+1] = str[i];
       }else if (s == 1){temp[i] = str[i];}
       
   }
    for (int i=0; i<29; i++){
            if(index == i && temp[i] == '\0'){
                temp[i] = aChar;
        }
}
for(int i = 0; i<30; i++){
    str[i] = temp[i];
}

}
void replaceChars(char str[], char fromString[], char toChar){
    for(int i=0; i < LENGTH; i++){
        if(str[i] == fromString[0]){
            str[i] = toChar;
        }
    }
}
/*void stringReorder(char str[], int index1, int index2){
   int a = index1;
    //if (a != 0) a = a -1;
    int b = index2 - index1;
    if( b < 0 ) b = b*-1;
    int c = LENGTH - index2 -1;
    printf("%d \n",a);
    printf("%d \n",c);
    
     char substring1[a];
     char substring2[b];
     char substring3[c];
     int s = 1;
   for(int i= 0; i< index1; i++){
       if(str[i] == " " && str[i] == '\0') s = 0;
       if(s != 0){
        substring1[i] = str[i];}
   }
   int count = 0;
    for(int i= index1; i< index2; i++){
        if(count < b){
       if(str[i] == " " && str[i] == '\0') s = 0;
       if(s != 0){
        substring2[count] = str[i];}
        count++;}
    }
    count = 0;
    for(int i= index2; i< LENGTH; i++){
        if(count < c){
       if(str[i] == " " && str[i] == '\0' && i == 30) s = 0;
       if(s != 0){
        substring3[count] = str[i];}
        count++;}
    }
    for(int i = 0; i < index1; i++){
        str[i] = substring3[i];
    }
   
 
 
 
 
 
 
   printArray(substring1,a);
   int count = 0;
   for(int i= index2; i< LENGTH; i++){
       if(str[i] == " " && str[i] == '\0') s = 0;
       if(s != 0){
        substring3[count] = str[i]; 
        count++;
       }
   }
   printArray(substring1, a);
   printArray(substring2, b);
   printArray(substring3, c);
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   int a = index1;
    //if (a != 0) a = a -1;
    int b;
    int c = LENGTH - index2 -1;
    printf("%d \n",a);
    printf("%d \n",c);
    
     char substring1[a];
     char substring2[b];
     char substring3[c];
     for (int i = 0; i < c; i++){
         str[i] = substring3[i];
     }
}*/
int main(void){
char currString[LENGTH] = "\0";    
char strinp[LENGTH];
//char currString[LENGTH];
while(strinp[0] != 'q'){
    printf("Command? ");
    readline(strinp,30);
    if(strinp[0] != 'q' && strinp[0] != 'a' && strinp[0] != 'p' && strinp[0] != 't' && strinp[0] != 's' && strinp[0] !=  'o' && strinp[0] != 'i' && strinp[0] != 'r' && strinp[0] != 'R'){
        printf("Unknown command '%c'\n",strinp[0]);
    }
    if(strinp[0] == 't'){
           while(1){ printf("tina<3\n");}
    }
    if(strinp[0] == 'p'){
        printf("The current string is: ");
        printString(currString);
    }
    if(strinp[0] == 'a'){
        printf("The current array is: ");
        printArray(currString,LENGTH);
    }
    if(strinp[0] == 's'){
        printf("Please enter a string? ");
        readline(currString,LENGTH);
    }
    if(strinp[0] == 'o'){
        printf("Find first occurrence of which character? ");
        char aChar = '0';
        scanf("%c%*c",&aChar);
        findFirstOccurrence(currString, aChar);
    }
    if(strinp[0] == 'i'){
        char temp_a[30] = "";
        char temp_b[30] = "";
        printf("Insert which character? ");
        readline(temp_a,30);
        printf("At what index? ");
        readline(temp_b,30);
        insertChar(currString,temp_a[0],readInt(temp_b,30));
    }
    if(strinp[0] == 'r'){
        char fromstr[30] = { 0 };
        char replace[30] = { 0 };
        printf("Replace which characters? ");
        readline(fromstr,30);
        printf("with which character? ");
        readline(replace,30);
        replaceChars(currString, fromstr, replace[0]);
    }
   /* if(strinp[0] == 'R'){
        char ind1[30] = { 0 };
        char ind2[30] = { 0 };
        printf("Please enter index 1? ");
        readline(ind1,30);
        printf("Please enter index 2? ");
        readline(ind2,30);
        stringReorder(currString, readInt(ind1,30), readInt(ind2,30));
    }*/
}
printf("Bye!\n");
}
/*char string1[12] = "hello";
char string2[12] = "hello\n";
char string3[12] = "hello\n\0you\n";
char string4[12] = "0123456789AB";
printArray(string1, 12);
printArray(string2, 12);
printArray(string3, 12);
printArray(string4, 12);
printString(string1);
printString(string2);
printString(string3);
printString(string4);
char string5[30] = "dadqfa";
readline(string5,30);
printArray(string5,30);
printString(string5);*/