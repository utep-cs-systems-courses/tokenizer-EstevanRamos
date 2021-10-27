#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


int count = 0;
int MAX = 3000;

int main()
{
  char user_input[300];
  List *history = init_history(); //Initialize History
  
  /* First Milestone: Simple functioning UI that echos user input */
  printf("\nEnter a String. Enter '!' to see history. Type 'x' to exit");
  while(user_input[0] != 'x')
    {
      printf(">");
      fgets(user_input, MAX, stdin);
      if(user_input[0] == 'x') { //close program
	break;
      }
      else if(user_input[0] == '?') { //print instructions
	printf("Enter string. ! for history. x to exit\n");
      }
      else if(user_input[0] == '!') { //history option
	printf("\nPrinting History");
	print_history(history);
      }else
	{
	  //case of string
	  int num_chars = 0;
       	  char* str = user_input;
	  while (*str != '\0')
	    {
	      num_chars++;
	      str++;
	    }
	  num_chars--;
	  char* copy = copy_str(user_input,num_chars);
	  //Print Tokens from string
	  printf("Tokens from String: \n");
	  char** tokens = tokenize(copy);
	  print_tokens(tokens);

	  //add to history
	  add_history(history,copy);
        }
     }
}
