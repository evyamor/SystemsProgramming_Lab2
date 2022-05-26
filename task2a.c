#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//TASK 2a :
/* TODO: task 2a functions here */
void echo_printer(char c){
	printf("%c\n",c);
} /* task 0 from lab1 - prints c to the standard output */
void ascii_printer(char c){
    printf("%d\n",c);
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
  }
  }

void string_reader(char* s){
  /* TODO: Complete during task 2c*/
}

 
void bitwise_or(char* s){
  /* TODO: Complete during task2c */
}

int main(int argc, char **argv){
  /* 
  char* input;
  char kb_input;
  char* option_4;
  input = fgets("Please enter a string (0<size<=10):");
  printDescs(&funArr);
  kb_input = getchar();
  while(kb_input != EOF){
    if(kb_input<'1' | kb_input > '4')
      printf("Please select 1-4 or CTRL-D to exit");
    else if(kb_input='4'){
          string_reader(option_4);
          string_printer(option_4,funArr[4]);
    }
    else 
       string_printer(input,funArr[kb_input]);
    printDescs(&funArr);
    kb_input = getchar();
}
printf("OPTION: DONE.")
}
*/
// Test T2a:
char c[]= {'L','a','b','2','\0'};
string_printer(c,ascii_printer);
string_printer(c,binary_printer);
string_printer(c,lower_to_upper_printer);
string_printer(c,echo_printer);

}
