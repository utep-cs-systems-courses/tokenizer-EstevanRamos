#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

int main()
{
  char userIn[100];

  while(1){
    putchar('$');
    fgets(userIn,100, stdin);
    printf("%s\n", userIn);
    break;
  }

  int w = space_char(userIn[0]);
  int k = non_space_char(userIn[0]);

  char *str = userIn; 
  char *beg = word_start(str);
  char *end = word_terminator(str);
  

  printf(beg);
  printf(end);
  printf("the first letter is %d %d \n", w , k);
}
