#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//TASK 2a :
/* TODO: task 2a functions here */
void echo_printer(char c){
	printf("%c",c);
} /* task 0 from lab1 - prints c to the standard output */
void ascii_printer(char c){
    printf("%d",c);
} /* task 1a from lab1 - print the ASCII code of c to the standard output*/
void binary_printer(char c){
    char c_arr[8];
        for (int bit = 7; bit>=0; --bit)
	{
		c_arr[ 7 - bit] = (c & (1 << bit)) ? '1' : '0';
	}
    printf("%s ", c_arr);
} /* task 1b from lab1 – print the binary representation of c to the standard output */
void lower_to_upper_printer(char c){
    	if(c >= 'A' && c<= 'Z')
	printf("%c",tolower(c));
	else
	printf("%c",toupper(c));
} /* task 1c from lab1 – print c to the standard output in upper case */
//TASK 2b :
void string_printer(char* str, void (*func_ptr) (char)){
  /* TODO: Complete during task 2b */
  int i;
  for(i=0;i<strlen(str);i++){
      func_ptr(str[i]);
      printf("\n");
  }
}
void string_reader(char* s){
  /* TODO: Complete during task 2c*/
  char str_buffer[10];
  char buffer;
  int read, counter;
  int zero=0;
  counter=0;
  for(read=0;read<10 && zero==0;read++){
    buffer=getchar();
    if(buffer!= 10){
      str_buffer[read]=buffer;
      counter++;
    }
    else
    zero=1;
  }
 // char output_buffer[counter+1];
  for(int j=0;j<counter;j++){
   s[j]=str_buffer[j];
  }
  s[counter]='\0';
}
 
void bitwise_or(char* s){
  /* TODO: Complete during task2c */
  int i;
  int temp;
  char char_temp;
  if(s!=NULL){
    char_temp=s[0];
  for ( i=0; i< (strlen(s)-1);i++){
     temp = (char_temp|s[i+1]);
     char_temp=temp;
  }
  binary_printer(char_temp);
  printf("\n");
  }
}
struct fun_desc {
	  char *name;
	  void (*fun)(char c);
};

void printMenu(){
  printf("please choose printer type:\n"
  " 0),echo_printer\n"
  " 1), ascii_printer\n"
  " 2), binary_printer\n"
  " 3)  lower_to_upper_printer\n"
  " 4)  bitwise or\n");
}
int main(int argc, char **argv){
  /* TODO: Test your code */
  struct fun_desc funArr[]={{"echo_printer",echo_printer},
   {"ascii_printer", ascii_printer},
   {"binary_printer", binary_printer},
   {"lower_to_upper_printer",lower_to_upper_printer}};
   
  char input[10];
  char kb_input;
  char option_4[10];
   printf("Please enter a string (0<size<=10):\n");
   string_reader(input);
  printMenu();
  kb_input = getchar();
  while(kb_input != EOF){
    if(kb_input >= '0' && kb_input <= '4'){
       if(kb_input == '4'){
          if(getchar()== 10)
         printf("please enter input of size up to 10 characters:");
          string_reader(option_4);
          bitwise_or(option_4);
        }else{ 
          string_printer(input,funArr[kb_input-'0'].fun);
    }}else{
       printf("Please select 1-4 or CTRL-D to exit\n");
    }
    if(kb_input != 10){
      printMenu();
      kb_input = getchar();
    }
    else 
    kb_input=getchar();
}
printf("OPTION: DONE.");
}
