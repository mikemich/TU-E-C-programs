#include <stdio.h>
int main(void){
 printf("** Complex Calculator **\n");
 char cmd = 1;
 float curr_re = 0.0;
 float curr_im = 0.0;
 float new_re = 0.0;
 float new_im = 0.0;
 while (cmd != 'q') {
  printf("Operation [0+-*crpq]? ");
  scanf(" %c", &cmd);
  if (cmd == '+' || cmd == '-' || cmd == '*'){
    printf("Complex operand? ");
    scanf("%f",&new_re);
    scanf("%f",&new_im);
  }
  if (cmd == '+'){
      curr_re = curr_re + new_re;
      curr_im = curr_im + new_im;
  }
      else if (cmd == '-'){
        curr_re = curr_re - new_re;
        curr_im = curr_im - new_im;
  }
    else if (cmd == '*'){
      float tmp_re = curr_re;
      float tmp_im = curr_im;
      curr_re = tmp_re * new_re - tmp_im * new_im;
      curr_im = tmp_re * new_im + tmp_im * new_re;
  }
    else if (cmd == '0'){
      curr_re = 0;
      curr_im = 0;
  }
    else if (cmd == 'c'){
        curr_im = curr_im * -1;
    }
  else if (cmd == 'r'){
       float rpower = 0.0;
       printf("Natural operand? ");
       scanf("%f",&rpower);
       float tmp_re = curr_re;
       float tmp_im = curr_im;
       float counter = rpower;
       float pwr_re = 0;
       float pwr_im = 0;
     if (counter != 0.0){
       while (counter != 1){
          pwr_re = curr_re;
          pwr_im = curr_im;
          curr_re = tmp_re * pwr_re - tmp_im * pwr_im;
          curr_im = tmp_im * pwr_re + tmp_re * pwr_im;
          counter = counter - 1;
       }
       }
       if(rpower == 0){
           curr_re = 1 ;
           curr_im = 0 ;
       }
      } 
    else if (cmd == 'p'){
        int tmpre = curr_re;
        int tmpim = curr_im;
        float curr_re = tmpre;
        float curr_im = tmpim;
        for (int outer = -10; outer <= 10; outer++) {
            for (int inner = -10; inner <= 10; inner++){
                
                if (inner == 0 && outer == 0){
                    if(curr_re == 0 && curr_im == 0){printf("*");
                    }else {
                        printf("+");
                    }
                }else if (outer == 0){
                    if (curr_re == inner && curr_im == -outer){
                     printf("*");
                }
                    else printf("-");
                }else if (inner == 0){
                    if (curr_re == inner && curr_im == -outer){
                     printf("*");
                }
                   else printf("|");
                }
                else if (curr_re == inner && curr_im == -outer){
                     printf("*");
                }
                else{
                    printf(".");
                }
            }
            printf("\n");
        }
    }
  else if (cmd != 'q')
  {
      printf("Invalid command ");
      printf("'%c'\n",cmd);
  }
  printf("Current value is %f",curr_re);//1-1
  if(curr_im >= 0){
      printf("+");
  }
  printf("%fi\n",curr_im); //1-1 
 }
printf("Bye!\n");
return 0;
}
//if (cmd == '+' || cmd == '-'
//if (cmd == '+'){
//      printf("Complex operand? \n");
 //     scanf("%f",&new_re);
//      scanf("%f",&new_im);
 // }
 //(cmd != 'q' || cmd != '+' || cmd != '-')
 //printf("%f\n", out);
 //tina <3
 
// float tmp_re = curr_re * new_re - curr_im * new_im;
 //     float tmp_im = curr_re * new_im + curr_im * new_re;
  //    curr_re = tmp_re;
  //    curr_im = tmp_im;
   //   curr_re = tmp_re * new_re - tmp_im * new_im;
   //   curr_im = tmp_re * new_im + tmp_im * new_re;
 /*  else if (cmd == 'r'){
      float rpower = 0.0;
      printf("Natural operand? ");
      scanf("%f",&rpower);
      float tmp_re = curr_re;
      float tmp_im = curr_im;
      float counter = rpower;
     if (counter > 0.0){
       while (counter != 1){
          curr_re = curr_re * tmp_re;
          curr_im = curr_im * tmp_im;
          counter = counter - 1.0;
           
       }*/
       /* */