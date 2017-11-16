#include <stdio.h>
#include <stdlib.h>
typedef struct _node node;
typedef struct _queue queue;

struct _node
{
    int item;
    int priority;
    node *next;
};

struct _queue
{
    node *first;
    node *last;
    int size;
};


queue* create_queue()
{
    queue *n_queue = (queue*) malloc(sizeof(queue));
    n_queue -> first = NULL;
    n_queue->last = NULL;
    n_queue -> size = 0;
    return n_queue;
}

int is_empty_queue(queue *queue)
{
    return (queue -> size == 0);
}

int size_queue(queue *queue)
{
    return queue -> size;
}

void enqueue_last(queue *n_queue, int item)
{
    node *newnode = (node*) malloc(sizeof(node));
    newnode -> item = item;
    newnode -> next = NULL;

    if(is_empty_queue(n_queue))
    {
        n_queue -> first = newnode;
        n_queue -> last = newnode;
    }

    else
    {
        n_queue-> last -> next = newnode;
        n_queue -> last = newnode;
    }

    n_queue -> size ++;
}

void enqueue_max(queue *n_queue, int item, int priority)
{
    node *newnode = (node*) malloc(sizeof(node));
    newnode -> item = item;
    newnode -> priority = priority;
    newnode -> next = NULL;

    if(is_empty_queue(n_queue))
    {
        n_queue -> first = newnode;
        n_queue -> last = newnode;
    }
    else if(priority > n_queue->first->priority)
    {
        newnode->next = n_queue->first;
        n_queue->first = newnode;
    }
    else
    {
        node *current = n_queue -> first;
        while ((current->next != NULL) && (current->next->priority > priority))
            current = current->next;

        newnode->next = current->next;
        current->next = newnode;

        if(priority < n_queue->last->priority)
            n_queue->last = newnode;
    }

    n_queue -> size ++;
}

void enqueue_min(queue *n_queue, int item, int priority)
{
    node *newnode = (node*) malloc(sizeof(node));
    newnode -> item = item;
    newnode -> priority = priority;
    newnode -> next = NULL;

    if(is_empty_queue(n_queue))
    {
        n_queue -> first = newnode;
        n_queue -> last = newnode;
    }
     else if(priority < n_queue->first->priority)
    {
        newnode->next = n_queue->first;
        n_queue->first = newnode;
    }
    else
    {
        node *current = n_queue -> first;
        while ((current->next != NULL) && (current->next->priority < priority))
            current = current->next;

        newnode->next = current->next;
        current->next = newnode;

        if(priority > n_queue->last->priority)
            n_queue->last = newnode;
    }

    n_queue -> size ++;
}

//dequeue the larger item at queue
int dequeue_max(queue *q)
{
    int larger = q -> first -> item;
    node* current = q->first, *aux;
    for(;current != NULL; current = current->next)
    {
        if (current->item > larger)
            larger = current->item;
    }

    if(q->first->item == larger)
        q->first = q->first->next;

    else
    {
        current = q->first;
        while(current->next->item != larger)
           current = current->next;
        aux = current->next;
        current->next = aux->next;
        free(aux);
    }
    q -> size--;
    return larger;
}

int dequeue(queue *queue)
{
    if(queue == NULL||queue -> first == NULL)
        return -1;

    node *aux = queue -> first;
    queue -> first = aux -> next;

    int dequeued = aux -> item;
    free(aux);
    queue -> size--;
    return dequeued;
}

//clean the queue
void free_queue(queue *q)
{
    node* aux;
    while(q->first != NULL)
    {
        aux = q->first;
        q->first = q->first->next;
        free(aux);
    }
    free(q);
}


int main()
{
   
    queue *fila = create_queue();

    int x = 1;

    while(x)
    {
        scanf("%d",&x);
        enqueue_min(fila, x, x);
    }

    while(!is_empty_queue(fila))
        printf("%d\n",dequeue_max(fila) );
}
