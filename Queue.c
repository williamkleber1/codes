#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;
typedef struct queue Queue;

struct node
{
    int item;
    Node *next;
};

struct queue
{
    Node *first;
    int size;
};

Queue* initialize_Queue()
{
    return NULL;
}

Queue* create_Queue()
{
    Queue *queue=(Queue*)malloc(sizeof(Queue));
    queue -> first = NULL;
    queue -> size = 0;
    return queue;
}

int is_empty(Queue *queue)
{
    if(queue == NULL || queue -> size == 0)
        return 1;
    else
        return 0;
}

int size_of_Queue(Queue *queue)
{
    if(queue==NULL)
        return 0;
    else
        return queue -> size;
}

void enQueue(Queue *queue, int item)
{
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode -> item=item;
    newNode -> next = NULL;
    if(queue->first==NULL)
        queue -> first = newNode;
    else
    {
        Node *aux = queue -> first;
        while(aux -> next != NULL)
            aux = aux -> next;
        aux -> next = newNode;
    }
    queue -> size ++;
}

int deQueue(Queue *queue)
{
    if(queue == NULL||queue -> first == NULL)
        return -1;
    Node *aux = queue -> first;
    queue -> first = aux -> next;
    int dequeued = aux -> item;
    free(aux);
    queue -> size--;
    return dequeued;
}


int main()
{
    Queue *fila;
    fila=initialize_Queue();
    fila=create_Queue();


}
