#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int item;
    int size;
    node *next;
    node *left;
    node *right;


}node;

node* creat_node()
{
    return NULL;
}

node* add_head(node *head, int item)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode -> item = item;
    newNode -> next = head;
    head = newNode;
    return head;

}

void print_List(node *list)
{
	node *aux = NULL;
	for(aux = list ; aux != NULL ; aux = aux->next)
	{
		printf("%d ",aux->item);
	}
	
}

int size_of_List(node *head)
{
    if(head == NULL )
        return 0;
    else
    {
        int count;
        count = 0;
        node *aux = head;
        while(aux != NULL)
        {
            count++;
            aux = aux -> next;
        }
        return count;
    }
}

int is_empty(node *head)
{
    if(head == NULL)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}
//Linkin Park
void add_tail(node* head, int item)
{
    node *newNode=(node*)malloc(sizeof(node));
    newNode -> item = item;
    newNode -> next = NULL;
    if(head == NULL)
         head = newNode;
 
    else
    {
        node *aux = head;
        while(aux -> next != NULL)
            aux=aux->next;

        aux -> next = newNode;
    }
}

int search(node *head, int item)
{
    node *aux = head;
    for(aux ; aux != NULL ; aux  = aux -> next)
    {
        if(aux -> item == item)
            return 1;
    }
    return 0;
}
node* change_nodes(node *a,node *b, node* a_prev)
{
    node *b_next = b-> next;
    a->next = b_next;
    b->next = a;

    if (a_prev != NULL)
        a_prev->next = b;
    return b;
}


void sort_list(node *head)
{
	node *aux = head;
	node *aux2 = NULL, *sucessor = NULL;

	for (aux; aux != NULL; aux = aux -> next)
	{
		for(aux2 = aux -> next; aux2 != NULL; aux2 = aux2 -> next)
		{
			if (aux -> item >= aux2 -> item)
			     aux = change_nodes(aux,aux->next,sucessor);
		}
        sucessor = aux;
	}
}
int remove_head(node *head)
{
    if(head == NULL)
    {
        return 0;
    }

    node *aux = head;
    head = aux -> next;
    free(aux);
    return 1;
}
int remove_tail(node *head)
{
    if(head == NULL)
        return 0;
    node *aux = head;
    node *aux2 = head -> next;
    while(aux2 -> next != NULL)
    {
    	aux = aux -> next;
    	aux2 = aux2 -> next;
    }
    aux -> next = NULL;
    free (aux2);
    return 1;
}
int remove(node *head, int item)
{
    if(head == NULL)
        return 0;
    if(item == head -> item)
    {
    	remove_head(head);
    	return 1;
    }


    node *previous, *current = head;
    while(current != NULL && current-> item != item)
    {
        previous  = current;
        current = current -> next;
    }
    previous -> next = current -> next;
    free(current);
    return 1;
}


int main()
{
  int i = 0;
  node* list = NULL;
  for (i; i< 5; ++i)
  {
      list = add_head(list,i);
  }
  printf("%d\n",is_empty(list) );
  print_List(list);
  printf("\n");
  sort_list(list);
  print_List(list);
}
