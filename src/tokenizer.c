#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if(c == ' '|| c == '\t')
    {
      return 1;
    }else
    {
      return 0;
    }
}

int non_space_char(char c)
{
  if(c == ' '|| c == '\t')
    {
      return 0;
    }else
    {
      return 1;
    }
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */

char *word_start(char *word)
{
  if(!word)
    {
      return 0;
    }

  int i = 0;
  while(non_space_char(*word))
    {
      word++;
    }
  word = word+i+1;
  return word;
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)
{
  if(!word)
    {
      return 0;
    }
  
  while(non_space_char(*word))
    {
      word++;
    }
  return word;
}

/* Counts the number of words in the string argument. */
int count_words(char *str)
{
  int count = 0;
  while(str)
    {
      str = word_terminator(str);
      str = word_start(str);
      count++;
    }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  char *s = (char*)malloc(len+1 * sizeof(char));
  int i = 0;
  while(i < len){
    s[i] = *inStr;
    inStr++;
    i++;
  }
  return s;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str)
{
  int count = count_words(str);
  char **tokens;
  tokens = malloc(count+1 * sizeof(char*));

  for(int i = 0; i < count; i++)
    {
      int len = word_terminator(str) - str;
      tokens[i] = copy_str(str,len);
      str = word_start(str);
    }
  
  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i] != 0)
    {
      printf("token %d: %s /n",i, tokens[i]);
      i++;
    }
}

/* Frees all tokens and the vector containing themx. 
void free_tokens(char **tokens);*/
void free_tokens(char **tokens){
  int i;
  for(i = 0; tokens[i] != NULL; i++)
    {
      free(tokens[i]);
    }
  free(tokens);
}
