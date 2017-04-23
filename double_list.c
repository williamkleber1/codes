#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;

struct node
{
    int item;
    Node *previous;
    Node *next;
};


Node* create_list()
{
    return NULL;
}

void print_List(Node *head)
{
    Node *aux = head;
    for(aux; aux!=NULL; aux = aux->next)
    {
        printf("%d ",aux->item);
    }
}

int size_of_List(node *head)
{
    if(head == NULL)
        return 0;
    else
    {
        int count;
        count = 0;
        Node *aux  = head;
        while(aux != NULL)
        {
            count++;
            aux = aux -> next;

        }
        return count;
    }
}

int is_empty(Node *head)
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

void add_head(Node *head, int item)
{
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode -> item = item;
    newNode->previous = NULL;
    if(head == NULL)
    {
        newNode -> next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head -> previous  =newNode;
        head = newNode;
    }
}

void add_end(Node *head, int item)
{
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode -> item = item;
    newNode -> next = NULL;
    if(head == NULL)
    {
        newNode -> previous = NULL;
        head = newNode;
    }
    else
    {
        Node *aux = head;
        while(aux -> next !=NULL)
            aux = aux->next;
        aux -> next = newNode;
        newNode -> previous = aux;
    }
}

void add_sorted(Node *head, int item)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> item = item;
    if(head == NULL)
    {
        newNode -> next = NULL;
        newNode -> previous = NULL;
        head = newNode;
    }
    else
    {
        Node *previous, *current = head ;
        while(current!=NULL && current->item < item)
        {
            previous = current;
            current = current->next;
        }

        newNode->next = previous -> next;
        newNode-> previous = previous;
        previous -> next = newNode;
        if(current!=NULL)
            current-> previous = newNode;
    }
}

int remove_head(Node *head)
{
    if(head == NULL)
        return 0;
    Node *aux = head;
    head = aux -> next;
    if(head  != NULL)
    {
        head -> previous = NULL;
    }

    free(aux);
    return 1;
}
int remove_last_Node(Node *head)
{
    if(head == NULL)
        return 0;
    Node *aux = head;
    while(aux -> next != NULL)
        aux = aux -> next;
    
    if(aux -> previous == NULL)
    {
      int x = remove_head(head);
      return x;
    }
    
    aux -> previous -> next = NULL;
    free(aux);
    return 1;

}

int remove_by_item(Node *head, int item)
{
    if(head == NULL)
        return 0;
    Node *aux = head;
    while(aux!=NULL && aux->item!=item)
        aux=aux->next;
    if(aux->previous == NULL)
    {
        int x = remove_head(head);
        return x;
    }
    else
    {
        aux->previous->next = aux->next;
    }
    if(aux->next!=NULL)
        aux->next->previous= aux->previous;
    free(aux);
    return 1;
}
int search_in_List(Node *head, int item)
{
    Node *aux = head;
    for(aux ; aux != NULL ;aux = aux -> next)
    {
        if(aux->item==item)
            return 1;
    }
    return 0;
}

int main()
{
    printf("hello\n");

}
