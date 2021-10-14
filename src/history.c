#include <stdio.h>
#include <stdlib.h>

s_List* init_history()
{
  s_List* history;
  history = malloc(sizeof(List));
  history->root = NULL;
  return history;
}

void add_history(s_List* list, char* str)
{
  s_Item *new = malloc(sizeof(Item));
  //if list is empty
  if (list->root == NULL){
    new->id = 1;
    list->root = new;
  }
  else {
    s_Item *currItem = list->root;
    while(currItem->next != NULL)
      {
	currItem = currItem->next;
      }
    //update id
    new->id = currItem->id + 1;
    currItem->next = new;
  }
  // new string is added to linked list
  new->str = str;
  new->next = NULL;
}

char *get_history(s_List* list, int id)
{
  if (list->root == NULL)
    {
    return "List is empty";
    }else
    {
      Item* temp = list->root;
      //traverse linked list
      while (temp != NULL)
	{
	  if (temp->id == id)
	    return temp->str;
	  temp = temp->next;
	}
    return "Item number not found\n";
  }
}

void print_history(s_List* list)
{
  s_Item* temp = (list->root);
  //traverse linked list and print id and string
  while (temp != NULL)
    {
      printf("History Item [%d]: %s \n", temp->id, temp->str);
      temp = temp->next;
    }
}

void free_history(s_List* list )
{
  s_Item* temp;
  s_Item* temp1;
  temp  = list -> root;
  while (temp != NULL)
    {
      temp1 = temp;
      temp = temp->next;
      free(temp1);
    }
  free(list);
}
