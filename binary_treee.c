#include <stdio.h>
#include <stdlib.h>
#include "binary_treee.h"
struct _binary_tree
{
    char item;
    int size;
   struct _binary_tree *prev;
   struct _binary_tree *next;
   struct _binary_tree *left;
   struct _binary_tree *right;
};

struct _list
{
    binary_tree* first;
    binary_tree* last;
    int size;
};

list *creat_list()
{
    list *new_list = (list *) malloc(sizeof(list));
    new_list -> first = NULL;
    new_list -> last = NULL;
    new_list -> size = 0;
}

binary_tree* create_binary_tree( char item, int size, binary_tree *left, binary_tree *right)
{
  binary_tree *new_binary_tree = (binary_tree*) malloc(sizeof(binary_tree));

  new_binary_tree->item = item;
  new_binary_tree->size = size;
  new_binary_tree->left = left;
  new_binary_tree->right = right;
  return new_binary_tree;
 }
binary_tree* start_tree()
{
    return NULL;
}

binary_tree* change_tree(binary_tree *a, binary_tree *b)
{
	binary_tree *b_next = b-> next,*a_prev = a -> prev;
    a->prev = b;
    a->next = b_next;
    b->next = a;
    b->prev = a_prev;

	if (a_prev != NULL)
		a_prev->next = b;
    if (b_next != NULL)
        b_next->prev = a;
    return b;


}

void print_list(binary_tree *head)
{
    binary_tree *aux = head;
    for(aux; aux!=NULL; aux = aux->next)
    {
        printf("%c | %d      ",aux->item,aux->size);
    }
    printf("\n");
}

void print_inverse(binary_tree *head)
{
    binary_tree *aux = head;
    for(aux; aux ->next !=NULL; aux = aux->next)
     for(aux; aux!=NULL; aux = aux->prev)
    {
        printf("%c | %d      ",aux->item,aux->size);
    }
    printf("\n");
}

int size_of_List(binary_tree *head)
{
    if(head == NULL)
        return 0;
    else
    {
        int count;
        count = 0;
        binary_tree *aux  = head;
        while(aux != NULL) {
            count++;
            aux = aux -> next;
        }
        return count;
    }
}


void print_pre_order(binary_tree *bt)

{

        if (bt != NULL)
         {

            printf("%c", bt->item);

            print_pre_order(bt->left);

            print_pre_order(bt->right);

        }

}

int is_empty(binary_tree *head)
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

binary_tree* add_head(binary_tree *head, int item)
{
    binary_tree *newbinary_tree=(binary_tree*)malloc(sizeof(binary_tree));
    newbinary_tree -> item = item;
    newbinary_tree->prev = NULL;
    if(head == NULL)
    {
        newbinary_tree -> next = NULL;
        return newbinary_tree;
    }
    else
    {
        newbinary_tree -> next = head;
        head -> prev  = newbinary_tree;
        return newbinary_tree;
    }
}

void add_end(list *head, char item)
{
    binary_tree *newbinary_tree = (binary_tree*) malloc(sizeof(binary_tree));
    newbinary_tree -> item = item;
    newbinary_tree -> next = NULL;
    if(head->first == NULL)
    {
        newbinary_tree -> prev = NULL;
        head ->first = newbinary_tree;
        head ->last = newbinary_tree;
        head->size++;
    }
    else
    {
        newbinary_tree->prev = head->last;
        head->last->next = newbinary_tree;
        head->last = newbinary_tree;
        head->size++;
    }
}

binary_tree* add_sorted(binary_tree *head, int item)
{
    binary_tree *newbinary_tree = (binary_tree*)malloc(sizeof(binary_tree));
    newbinary_tree -> item = item;
    if(head == NULL)
    {
        newbinary_tree -> next = NULL;
        newbinary_tree -> prev = NULL;
        head = newbinary_tree;
    }
    else
    {
        binary_tree *prev, *current = head ;
        while(current!=NULL && current->item < item)
        {
            prev = current;
            current = current->next;
        }

        newbinary_tree->next = prev -> next;
        newbinary_tree-> prev = prev;
        prev -> next = newbinary_tree;
        if(current!=NULL)
            current-> prev = newbinary_tree;
    }
    return head;

}
int its_smaller(binary_tree *a, binary_tree *b)
{
    if (a != NULL)
    {
        if (a->size <= b->size)
        {
            return 1;
        }
    }

    return 0;
}

 void add_sorted_tree(binary_tree *head, binary_tree *bt)
{
    
        binary_tree *previous, *current = head;
        while(current != NULL && current->size < bt->size)
    {
        previous = current;
        current = current->next;
    }
        
    bt -> next = previous->next;
    bt ->prev = previous;
    previous -> next = bt;
    if(current!=NULL)
      current-> prev = bt;

    
}

void sort(binary_tree *head)
{
    binary_tree* aux = head, *aux2;
    for (aux; aux != NULL; aux = aux->next )
    {
        for (aux2 = aux->next; aux2 != NULL; aux2 =  aux2-> next)
        {
            if (aux->size > aux2->size)
            {
                aux = change_tree(aux,aux2);
            }
        }
    }
}


int search_increment(binary_tree *head, int item)
{
    binary_tree *aux = head;
    for(aux ; aux != NULL ; aux  = aux -> next)
    {
        if(aux -> item == item)
        {
        	aux -> size++;
            return 1;
        }
    }

    return 0;
}

binary_tree* add_for_size(binary_tree *head, int item)
{
	if (search_increment(head, item))
		return head;
   
    head = add_head(head,item);
    head->size++;
    return head;

}
int remove_head(binary_tree *head)
{
    if(head == NULL)
        return 0;
    binary_tree *aux = head;
    head = aux -> next;
    if(head  != NULL)
    {
        head -> prev = NULL;
    }

    free(aux);
    return 1;
}
int remove_tail(binary_tree *head)
{
    if(head == NULL)
        return 0;
    binary_tree *aux = head;
    while(aux -> next != NULL)
        aux = aux -> next;
    
    if(aux -> prev == NULL)
    {
      int x = remove_head(head);
      return x;
    }
    
    aux -> prev -> next = NULL;
    free(aux);
    return 1;

}

int remove_item(binary_tree *head, int item)
{
    if(head == NULL)
        return 0;
    binary_tree *aux = head;
    while(aux!=NULL && aux->item!=item)
        aux=aux->next;
    if(aux->prev == NULL)
    {
        int x = remove_head(head);
        return x;
    }
    else
    {
        aux->prev->next = aux->next;
    }
    if(aux->next!=NULL)
        aux->next->prev= aux->prev;
    free(aux);
    return 1;
}


int search(binary_tree *head, int item)
{
    binary_tree *aux = head;
    for(aux ; aux != NULL ;aux = aux -> next)
    {
        if(aux->item==item)
            return 1;
    }
    return 0;
}

int tam(binary_tree *a, binary_tree* b)
{
      int i =0;
      if (a != NULL)
          i += a->size;
      if (b != NULL)
         i += b->size;
      return i;
}
        
binary_tree* merge_tree(binary_tree *bt)
{
    if(size_of_List(bt) > 0)
    {
        binary_tree* left, *right, *merge;
        left = bt;
        right = left->next;
        bt = right->next;
        if(bt != NULL)
            bt->prev = NULL;
        merge = create_binary_tree( '*',tam(left,right),left,right);
        add_sorted_tree(bt,merge);
        return bt;
    }
     
}