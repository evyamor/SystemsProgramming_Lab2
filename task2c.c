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
  printf("the result in hex is: \n");
  ascii_printer(char_temp);
  printf("and in binary: \n");
  binary_printer(char_temp);
  }
}
int main(int argc, char **argv){
  /* TODO: Test your code */
  char c[10];
  printf("please enter input size<=10 chars:");
string_reader(c);
bitwise_or(c);
}
