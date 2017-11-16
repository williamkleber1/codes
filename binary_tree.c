#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct _binary_tree binary_tree;
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

void enqueue(queue *n_queue, int item)
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

//dequeue the fist item of queue
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


//############## PARTE DA ARVORE BINARIA ##########	

struct _binary_tree
{
	int item;
	int h;
	binary_tree *left;
	binary_tree *right;
};

binary_tree* create_binary_tree(int item, binary_tree *left, binary_tree *right)
{
	binary_tree *new_tree = (binary_tree*) malloc(sizeof(binary_tree));
	new_tree -> item = item;
	new_tree -> left = left;
	new_tree -> right = right;
	return new_tree;
}

/*preenche um array com os iten de uma arvore
current é o int que representa o indice do array
ele deve  ser 0 qnd adicionado*/
 void preenche(binary_tree *bt, int *array) 

{

	if (bt != NULL) 
	{
		*array = bt->item;
		preenche(bt->left, ++array );
		preenche(bt->right, ++array );

	}

}

/*compara 2 arvores para ver se sao iguais
inserir as duas arvores, retorna -1 se forem diferentes*/
int equals_trees(binary_tree *bt, binary_tree* aux)
{

		if (bt != NULL && aux != NULL)
		 {

			if(bt-> item != aux -> item)
			   return -1;

			 int result = equals_trees(bt->left, aux-> left );
			 if (result == -1)
			 	return result;

			 equals_trees(bt->right, aux->right);

		}

		else if (bt == NULL && aux != NULL || aux == NULL && bt != NULL)
			return -1;
		

}


 bool is_empty(binary_tree *bt)
 {
 	return (bt == NULL);
 }
/*busca em arvore de busca binaria
se o elemento procurado estiver na arvore
retorna 1, casocontrario retorna 0*/
binary_tree* search_binary(binary_tree *bt, int item)

{
	if(bt == NULL)
		return NULL;

	else if ( (bt->item == item))
		      return bt;
    else 
    {

		if (bt->item > item) 
			return search_binary(bt->left, item);
 
		else 
			return search_binary(bt->right, item);
    }
}

/*calcula a profundidade de um no, inserir a arvore, o item que
 quer saber a profundidade e um int para receber a profundidade*/
int profundidade(binary_tree *bt, int num,int *profun)
{
   static int aux = 0;

	if (bt != NULL &&  *profundidade == 0 )
	   {
			if(bt->item == num)  *profun = aux;
				 
			    
		 aux ++;
		profundidade(bt -> left, num, profun);
		profundidade(bt -> right, num, profun);
		aux --;
	}

	
}


/* calcula a altura de um no na arvore*/
int altura_binary_tree( binary_tree *arvore)
{
	binary_tree *bt = arvore;
	if (bt != NULL)
	{
		int alt_left = altura_binary_tree(bt -> left);
		int alt_right = altura_binary_tree(bt -> right);
		if(alt_left >= alt_right)
			 return (alt_left + 1);

		else
			return (alt_right +1);
	}

}


void print_pre_order(binary_tree *bt)
{
		if (bt != NULL)
		 {
			printf("%d  ---  )", bt->item);

			print_pre_order(bt->left);

			print_pre_order(bt->right);

		}

}


void print(binary_tree *bt)
{
	if (bt != NULL )
		 {
		 	printf("  ( ");
			printf("%d", bt->item);
			print(bt->left);
			print(bt->right);
			printf(" )");
			
		}
	else
	  printf("  ()");
}



void add_abb(binary_tree **bt, int item)

{

	if (*bt == NULL)
		*bt = create_binary_tree(item, NULL, NULL);
	else if ((*bt)->item > item)
		add_abb(&(*bt)->left, item);
	 else 
		add_abb(&(*bt)->right, item);
}

void copy_tree(binary_tree* bt1, binary_tree **bt2)
{
	if(bt1 != NULL)
	{
		*bt2 = create_binary_tree(bt1->item, NULL,NULL);
		copy_tree(bt1->left, &(*bt2)->left);
		copy_tree(bt1->right,&(*bt2)->right);
	}
}

void free_tree(binary_tree *bt)
{
	if(bt != NULL)
	{
		free_tree(bt->left);
		free_tree(bt->right);
	}
}

binary_tree* create_binary_tree_queue(queue *queue) 
{
  if(queue-> first == NULL) return NULL;
 
  int value = dequeue(queue);
 
  if(value == -1) return NULL;
 
  binary_tree *bt = create_binary_tree(value,NULL,NULL);
  bt->left = create_binary_tree_queue(queue);
  bt->right = create_binary_tree_queue(queue);
 
  return bt;
}


int str_to_int(char *str)
{
	char number[10] = "\0";
	int i = 0;
	while(*str != ')' && *str != '\0')
	{
		number[i] = *str;
		++i;
		++str;
	}
	if(i == 0) 
		return -1;
	return atoi(number);

}

binary_tree* str_to_tree(char *str)
{
	queue* new_queue = create_queue();
	while(*str != '\0')
	{
		if(*str == '(')
		 enqueue(new_queue, str_to_int(++str));

		++str;
	}

	return create_binary_tree_queue(new_queue);
}

int main()
{
	binary_tree *tree = NULL;
	char str[] = "(12(7(3()())(10()(11()())))(23(17()())(31()())))";
	tree = str_to_tree(str);
	
	print(tree);
}
















