#include <stdio.h>
#define MAXSIZE 10
void print (float matrix[MAXSIZE][MAXSIZE], int rows, int columns, char name){
    printf("Matrix %c (%d X %d):",name, rows, columns);
    for(int y = 0; y < rows; y++){
        printf("\n");
        for(int x = 0; x < columns; x++){
                printf("%8.2f",matrix[x][y]);
            }
            
        }
    

    printf("\n");
}
/*void add(
    float matrixA [MAXSIZE][MAXSIZE], int rowsA, int columnsA,
    float matrixB [MAXSIZE][MAXSIZE], int rowsB, int columnsB,
    float matrixC [MAXSIZE][MAXSIZE], int rowsC, int columnsC){
        if(rowsA == columnsA && rowsB == columnsB){
        for(int y = 0; y < rowsA; y++){
        for(int x = 0; x < columnsA; x++){
        matrixC[x][y] = matrixA[x][y] + matrixB[x][y];
        }}
        }else{
            printf("Dimensions of A & B do not match");
        }
    }*/
void add(
    float matrixA [MAXSIZE][MAXSIZE], int rowsA, int columnsA,
    float matrixB [MAXSIZE][MAXSIZE], int rowsB, int columnsB,
    float matrixC [MAXSIZE][MAXSIZE], int rowsC, int columnsC){
        if(rowsA == rowsB && columnsA == columnsB){
        for(int y = 0; y < rowsA; y++){
        for(int x = 0; x < columnsA; x++){
        matrixC[x][y] = matrixA[x][y] + matrixB[x][y];
        }}
        }else{
            printf("Dimensions of A & B do not match\n");
        }
    }
    
    void mult(float matrixA[MAXSIZE][MAXSIZE], int rowsA, int columnsA,
              float matrixB[MAXSIZE][MAXSIZE], int rowsB, int columnsB,
              float matrixC[MAXSIZE][MAXSIZE], int rowsC, int columnsC){
                             printf("%d %d", rowsA, columnsA);
                             float sum;
                             int m = rowsA;
                         //    int n = columnsA;
                             int p = rowsB;
                             int q = columnsB;
                              for (int i = 0; i <rowsA; i++){
                                  for (int j = 0; j < columnsB; j++){
                                      matrixC[i][j] = 0;
                                  }
                              }
                          if (columnsA == rowsB){
                          for (int i = 0; i < m; i++){
                              for (int j = 0; j < q; j++){
                                  for (int k = 0; k < p; k++){
                                      sum = sum + matrixA[i][k] * matrixB[k][j];
                                      printf("%f",sum);
                                  }
                              matrixC[i][j] = sum;
                              sum = 0;
                                  
                              }
                          }
                          }
                          for (int i = 0; i < rowsC; i++){
                              for (int j = 0; j < columnsC; j++){
                                  for (int k = 0; k < columnsA; k++){
                                      matrixC[i][j] = matrixC[i][j] + matrixA[i][k]*matrixB[k][j];
                                  }
                              }
                          }
}
/*void mult(
    float matrixA [MAXSIZE][MAXSIZE], int rowsA, int columnsA,
    float matrixB [MAXSIZE][MAXSIZE], int rowsB, int columnsB,
    float matrixC [MAXSIZE][MAXSIZE], int rowsC, int columnsC){
        if(rowsA == rowsB && columnsA == columnsB){
        for(int y = 0; y < rowsA; y++){
        for(int x = 0; x < columnsA; x++){
        matrixC[x][y] = matrixA[x][y] * matrixB[x][y];
        }}
        }else{
            printf("Dimensions of A & B do not match\n");
        }
    }*/

/*void mult(
    float matrixA [MAXSIZE][MAXSIZE], int rowsA, int columnsA,
    float matrixB [MAXSIZE][MAXSIZE], int rowsB, int columnsB,
    float matrixC [MAXSIZE][MAXSIZE], int rowsC, int columnsC){
        double[][] matrixC = new double [N][N];
        for (int i = 0; i < N; i++){
            for (int j =0; j < N; j++){
                for (int k = 0; k < N; k++){
                    matrixC[i][j] += matrixA[i][k] * b[k][j];
                }
            }
        }
    }*/
    



int main(void){
float matrixA[MAXSIZE][MAXSIZE] = { 0 };
float matrixB[MAXSIZE][MAXSIZE] = { 0 };
float matrixC[MAXSIZE][MAXSIZE] = { 0 };
float matrixTemp[MAXSIZE][MAXSIZE] = { 0 };
int rowsA, columnsA, rowsB, columnsB, rowsC, columnsC, rowst, columnst;
rowsA = columnsA = rowsB = columnsB = rowsC = columnsC = 1;
char cmd;
while(cmd != 'q'){
    printf("Command? ");
    scanf(" %c",&cmd);
    if(cmd == 'I' || cmd == 'q' || cmd == 'a' || cmd == 'A' || cmd =='b' || cmd =='c' || cmd =='B' || cmd =='+' || cmd == 't' || cmd == '*'){
    
    if(cmd == 'I'){
        int s = 1;
        rowst = rowsA;
        columnst = columnsA;
        printf("Size of matrix A (rows columns)? ");
        scanf("%d", &rowsA);
        scanf("%d", &columnsA);
        if(rowsA != columnsA || columnsA < 1 || columnsA > 10 || rowsA < 1 || rowsA > 10 || columnsB < 1 || columnsB > 10 || rowsB < 1 || rowsB > 10 ){ printf("Rows & columns must be equal and between 1 and 10\n");
        rowsA = rowst;
        columnsA = columnst;
        s = 0;
        }
        if(s != 0){for(int y = 0; y < rowsA; y++){
        for(int x = 0; x < columnsA; x++){
            matrixA[x][y] =  0;
            if(x == y){
                matrixA[x][y] = 1;
            }
        }
        }
    }
        
    }
    if(cmd == 'A'){
        int s = 1;
        rowst = rowsA;
        columnst = columnsA;
        printf("Size of matrix A (rows columns)? ");
        scanf("%d", &rowsA);
        scanf("%d", &columnsA);
        if(columnsA < 1 || columnsA > 10 || rowsA < 1 || rowsA > 10 || columnsB < 1 || columnsB > 10 || rowsB < 1 || rowsB > 10 ){ printf("Rows & columns must be between 1 and 10\n");
        rowsA = rowst;
        columnsA = columnst;
        s = 0;
        }
        float d;
        if(s != 0){
        for(int y = 0; y < rowsA; y++){
            printf("Row %d? ",y);
        for(int x = 0; x < columnsA; x++){
                scanf(" %f",&d);
                matrixA[x][y] = d;
        }
        }
    }
    }
    
    if(cmd == 'a'){
        print(matrixA,rowsA,columnsA,'A');
    }
    if(cmd == 'b'){
        print(matrixB,rowsB,columnsB,'B');
    }
    if(cmd == 'c'){
        print(matrixC,rowsC,columnsC,'C');
    }
    if(cmd == 'B'){
        rowsB = rowsA;
        columnsB = columnsA;
        for(int y = 0; y < rowsA; y++){
        for(int x = 0; x < columnsA; x++){
        matrixB[x][y] = matrixA[x][y];
        }
    }
    }
    if(cmd == '+'){
        if(rowsA == rowsB && columnsA == columnsB){
        rowsC = rowsA;
        columnsC = columnsA;}
        add(
    matrixA,rowsA,columnsA,
    matrixB,rowsB,columnsB,
    matrixC,rowsC,columnsC);
    }
    if(cmd == 't'){
        /*float tina[columnsA][rowsA];
        int a = columnsA; 
        int b = rowsA; 
        rowsA = a; 
        columnsA = b; 
        for (int i= 0; i < a; i++){
            for (int j= 0; j < b; j++){
                tina[i][j] = matrixA[j][i]; 
            }
        }
        for (int i = 0; i < a; i++){
            for (int j = 0; j < b; j++){
                matrixA[i][j] = tina[i][j];
            }
        }*/
        for(int y = 0; y < rowsA; y++){
        for(int x = 0; x < columnsA; x++){
        matrixTemp[x][y] = matrixA[x][y];
        }
    }
        int rowstemp = columnsA;
        int columnstemp = rowsA;
        rowsA = columnsA;
        columnsA = columnstemp;
        for(int y = 0; y < columnstemp; y++){
        for(int x = 0; x < rowstemp; x++){
        matrixA[y][x] = matrixTemp[x][y];
        }
    }
    //printf("%d %d",rowsA,columnsA);
    }
     if(cmd == '*'){
        if(columnsA == rowsB || rowsA == columnsB){
        rowsC = rowsA;
        columnsC = columnsB;
        mult(matrixA,rowsA,columnsA,
             matrixB,rowsB,columnsB,
             matrixC,rowsC,columnsC);
    }else printf("trSH");
    }
    }else if(cmd != 'q'){
        printf("Unknown command '%c'\n",cmd);
    }
    
    
}
printf("Bye!\n");
}