#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;
typedef struct priority_queue PQueue;

struct node
{
    int item;
    int priority;
    Node *next;
};

struct priority_queue
{
    Node *first;
    int size;
};

PQueue* initialize_PQueue()
{
    return NULL;
}

PQueue* create_PQueue()
{
    PQueue *queue = (PQueue*)malloc(sizeof(PQueue));
    queue -> first = NULL;
    queue -> size = 0;
    return queue;
}

 void enPQueue(PQueue *queue, int item, int priority)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode  -> item = item;
    newNode -> priority = priority;
    if(queue -> first == NULL)
    {
        queue -> first = newNode;
        newNode-> next = NULL;
         queue -> size ++;
    }
    else
    {
        Node *previous, *current = queue->first;
        while(current != NULL && current->priority > priority)
        {
            previous = current;
            current = current->next;
        }
        
        newNode -> next = previous->next;
        previous -> next = newNode;
        queue->size++;
    
    }
}

int dePQueue(PQueue *queue)
{
    if(queue == NULL || queue->first == NULL)
        return -1;
    else
    {
        Node *current = queue -> first;
        queue -> first = queue -> first-> next;
        queue -> size--;
        int aux = current -> item;
        free(current);
        return aux;
    }
} 

int is_empty(PQueue *queue)
{
    if(queue == NULL || queue->size == 0)
        return 1;
    else
        return 0;
}

int size_of_PQueue(PQueue *queue)
{
    if(queue == NULL)
        return 0;
    else
        return queue -> size;
}


int main()
{
    PQueue *fila;
    fila=initialize_PQueue();
    fila=create_PQueue();
    int n, pri, item;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d",&item,&pri); 
        enPQueue(fila,item,pri);
    }
    while(fila -> first != NULL)
        printf("%C\n",dePQueue(fila) );

    

}
