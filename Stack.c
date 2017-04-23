#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
typedef struct stack Stack;

struct node
{
	int item;
	Node *next;
};

struct stack
{
	Node *top;
	int size;
};

Stack* create_Stack()
{
	return NULL;
}


void push(Stack *stack, int item)
{
	Node *newNode = (Node*) malloc(sizeof(Node));
	newNode -> item = item;
	newNode -> next = stack -> top;
	stack -> top = newNode;
	stack-> size++;

}

int pop(Stack *stack)
{
	if(stack==NULL || stack->top==NULL)
		return -1;
	else
	{
		Node *aux = stack -> top;
		stack -> top = aux->next;
		int aux2 = aux -> item;
		stack->size--;
		free(aux);
		return aux2;
	}
}

int peek(Stack *stack) 
{
	if(stack == NULL || stack -> top == NULL)
		return -1;
	else
		return stack-> top-> item;
}

int main ()
{
	Stack *pilha;
	pilha=create_Stack();
	
}
