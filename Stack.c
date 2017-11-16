#include <stdio.h>
#include <stdlib.h>

typedef struct _node node;
typedef struct _stack stack;

struct _node
{
	int item;
	node *next;
};

struct _stack
{
	node *top;
	int size;
};

stack* create_stack()
{
	stack *aux = (stack*) malloc(sizeof(stack));
	aux -> top = NULL;
	aux -> size = 0;
	return aux;
}

int is_empty_stack(stack *n_stack)
{
	return n_stack->size == 0;
}


void push(stack *stack, int item)
{
	node *newnode = (node*) malloc(sizeof(node));
	newnode -> item = item;
	newnode -> next = stack -> top;
	stack -> top = newnode;
	stack-> size++;

}

int pop(stack *stack)
{
	if(is_empty_stack(stack))
		return -1;
	else
	{
		node *aux = stack -> top;
		stack -> top = aux->next;
		int number = aux -> item;
		stack->size--;
		free(aux);
		return number;
	}
}

int peek(stack *stack) 
{
	if(stack == NULL || stack -> top == NULL)
		return -1;
	else
		return stack-> top-> item;
}

int main ()
{
	stack *new_stack = create_stack();
	int i = 0;
	for (; i <= 50; ++i)
		push(new_stack,i);

	while(!is_empty_stack(new_stack))
		printf("%d\n",pop(new_stack) );

	stack *aux = create_stack();
	new_stack = aux;

	printf("------%d---------\n",aux == new_stack );
}
