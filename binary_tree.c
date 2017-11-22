#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX(a , b) a > b ? a : b

typedef struct _binary_tree binary_tree;
typedef struct _node node;
typedef struct _queue queue;

//################PARTE DA FILA #########################
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


//############################################## PARTE DA ARVORE AVL/ABB ###################################	

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
	new_tree-> h = 0;
	return new_tree;
}

/*insere em uma arvore binaria de busca
usa ponteiro duplo, entao no parametro
vai &bt, onde bt é a arvore onde desejamos adicionar*/
void add_abb(binary_tree **bt, int item)
{

	if (*bt == NULL)
		*bt = create_binary_tree(item, NULL, NULL);
	else if ((*bt)->item > item)
		add_abb(&(*bt)->left, item);
	 else 
		add_abb(&(*bt)->right, item);
}


//Calcula a altura da arvore Binaria
int height(binary_tree *bt) 
{
	if (bt == NULL)	return -1;
	else			
		return 1 + MAX( height(bt->left), height(bt->right) );
}


//calcula o banceamento da arvore
int is_balanced(binary_tree *bt) 
{
	int bf = height(bt->left) - height(bt->right);
	return ( (bf >= -1) && (bf <= 1) );
}


//rotaciona para esquerda
binary_tree* rotate_left(binary_tree *bt) 
{
	binary_tree *subtree_root = NULL;
	if (bt != NULL && bt->right != NULL) 
	{
		subtree_root = bt->right;
		bt->right = subtree_root->left;
		subtree_root->left = bt;
	}
	subtree_root->h = height(subtree_root);
	bt->h = height(bt);
	return subtree_root;
}

//rotaciona para direita
binary_tree* rotate_right(binary_tree *bt) 
{
	binary_tree *subtree_root = NULL;
	if (bt != NULL && bt->left != NULL) 
	{
		subtree_root = bt->left;
		bt->left = subtree_root->right;
		subtree_root->right = bt;
	}
	subtree_root->h = height(subtree_root);
	bt->h = height(bt);
	return subtree_root;
}

int balance_factor(binary_tree *bt) 
{
	if (bt == NULL)
		return 0;

	else if ((bt->left != NULL) && (bt->right != NULL))
		return (bt->left->h - bt->right->h);

	else if ((bt->left != NULL) && (bt->right == NULL))
		return (bt->left->h);

	else
		return (bt->right->h - 1);
}



binary_tree* add_node_avl(binary_tree *bt, int item) 
{

	if (bt == NULL)
		return create_binary_tree(item, NULL, NULL);

	else if (bt->item > item)
		bt->left = add_node_avl(bt->left, item);
	else 
		bt->right = add_node_avl(bt->right, item);
	
	bt->h = height(bt);
	binary_tree *child;

	if (balance_factor(bt) == 2 || balance_factor(bt) == -2)
	{
		if (balance_factor(bt) == 2) 
		{
			child = bt->left;
			if (balance_factor(child) == -1)
				bt->left = rotate_left(child);
			
			bt = rotate_right(bt);
		}
		else if (balance_factor(bt) == -2) 
		{
			child = bt->right;
			if (balance_factor(child) == 1) 
				bt->right = rotate_right(child);

			bt = rotate_left(bt);
		}
	}
	return bt;
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



//########################################### ARVORE BINARIA #####################################

// verifica se um no é folha
int is_leaf(binary_tree *bt)
{
	return (bt->left == NULL && bt-> right == NULL);
}

//calcula se a soma de todoa oa nós ate uma folha é igual a N
int sum_nodes(binary_tree* bt, int sum, int N)
{

	if(is_leaf(bt) && (sum + bt->item) == N) return -1;

	int result = sum_nodes(bt->left, sum + bt->item, N);

	if(result == -1) return -1;

	return sum_nodes(bt->right, sum + bt->item, N );
}

/*preenche um array com os iten de uma arvore
current é o int que representa o indice do array
ele deve  ser 0 qnd adicionado*/
 void preenche(binary_tree *bt, int *array, int *i) 

{

	if (bt != NULL) 
	{
		array[*i] = bt->item;
		*(i++);
		preenche(bt->left, array, i );
		preenche(bt->right, array, i );

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




void print_pre_order(binary_tree *bt)
{
		if (bt != NULL)
		 {
			printf("%d  ---  ", bt->item);

			print_pre_order(bt->left);

			print_pre_order(bt->right);

		}

}

//imprime uma arvore binaria no formato LISP
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




/*copia uma arvore em outra, o segundo parametro
é ponteiro duplo, então temos que colocar &bt2, onde bt2
é onde queremos guardar a copia da bt1*/
void copy_tree(binary_tree* bt1, binary_tree **bt2)
{
	if(bt1 != NULL)
	{
		*bt2 = create_binary_tree(bt1->item, NULL,NULL);
		copy_tree(bt1->left, &(*bt2)->left);
		copy_tree(bt1->right,&(*bt2)->right);
	}
}

//desaloca uma arvore
void free_tree(binary_tree *bt)
{
	if(bt != NULL)
	{
		free_tree(bt->left);
		free_tree(bt->right);
		free(bt);
	}
}

//recebe uma fila, e retorna uma arvore montada em pre-ordem
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

//recebe uma string e devolve seu correspondente em int
int str_to_int(char *str)
{
	char number[10] = "\0";
	int i = 0;
	while(*str != ')' && *str != '\0' )
	{
		number[i] = *str;
		++i;
		++str;
	}
	if(i == 0) 
		return -1;
	return atoi(number);

}

// retorna uma arvore criada de uma string no formato LISP 
binary_tree* str_to_tree(char *str)
{
	int i = 0;
	queue* new_queue = create_queue();
	while(*str != '\0' && i < strlen(str))
	{
		if(*str == '(') printf("%d\n", str_to_int(++str));
		 //enqueue(new_queue, str_to_int(++str));

		++str;
		++i;
	}

	//return create_binary_tree_queue(new_queue);
}

int main()
{
	binary_tree *arvore = NULL;

	char str1[500];
	gets(str1);


	char *str = str1;



	arvore = str_to_tree(str);
	print(arvore);

	if(sum_nodes(arvore,0,22) == -1) printf("\nsiiiiiiiiiiiiimmmmmmmmmm\n");
	else printf("naaaaaaaaaaaaaaaaaooooooooooooooooooo\n");
}
















