#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "binary_treee.h"

binary_tree* create_empty_binary_tree()

{

	return NULL;

}
/*preenche um array com os iten de uma arvore
current é o int que representa o indice do array
ele deve  ser 0 qnd adicionado*/
 void preenche(binary_tree *bt, int array[],int *current) 

{

	if (bt != NULL) 
	{


		array[*current] = bt->item;
		(*current)++;

		preenche(bt->left, array ,current);
		preenche(bt->right,array,current);

	}

}

/*compara 2 arvores para ver se sao iguais
inserir as duas arvores e um inteiro com valor zero
e o inteiro mudar de valor as arvores sao diferents*/
void compara_arvore(binary_tree *bt, binary_tree* aux, int *i)
{

		if (bt != NULL && aux != NULL && *i == 0)
		 {

			if(bt-> item != aux -> item)
			   (*i)++;

			compara_arvore(bt->left, aux-> left , i);

			compara_arvore(bt->right, aux->right, i);

		}

		else if (bt == NULL && aux != NULL || aux == NULL && bt != NULL)
		{
			(*i)++;
		}

}

binary_tree* create_binary_tree_queue(Queue *queue) 
{
  if(queue-> first == NULL) return NULL;
 
  int value = dequeue(queue);
 
  if(value == -1) return NULL;
 
  binary_tree *bt = malloc(sizeof(binary_tree));
  bt->value = value;
 
  bt->left = create_binary_tree(queue);
  bt->right = create_binary_tree(queue);
 
  return bt;
}

 bool is_empty(binary_tree *bt)
 {
 	return (bt == NULL);
 }
/*busca em arvore de busca binaria
se o elemento procurado estiver na arvore
retorna 1, casocontrario retorna 0*/
int search_binary(binary_tree *bt, int item)

{
	if(bt == NULL)
		return 0;

	else if ( (bt->item == item))
		      return 1;

    else if(bt != NULL)
    {

		 if (bt->item > item) 
			return search_binary(bt->left, item);
 
		 else 
			return search_binary(bt->right, item);
    }
}
/*calcula a profundidade de um no, inserir a arvore, o item que
 quer saber a profundidade e um int para receber a profundidade*/
int profundidade(binary_tree *bt, int num,int *profundidade)
{
   static int aux = 0;

	if (bt != NULL &&  *profundidade == 0 )
	   {
			if(bt->item == num)  *profundidade = aux;
				 
			    
		 aux ++;
		profundidade(bt -> left, num, &profundidade);
		profundidade(bt -> right, num, &profundidade);
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

 void print_in_order(binary_tree *bt)

{

	if (!is_empty(bt)) 
	{

		print_in_order(bt->left);

		printf("%d", bt->item);

		print_in_order(bt->right);

	}

}


void print_pre_order(binary_tree *bt)

{

		if (!is_empty(bt))
		 {

			printf("%d", bt->item);

			print_pre_order(bt->left);

			print_pre_order(bt->right);

		}

}

void print_post_order(binary_tree *bt)

{

	if (!is_empty(bt)) 
	{

		print_post_order(bt->left);

		print_post_order(bt->right);

		printf("%d", bt->item);

	}

}



void add(binary_tree **bt, int item)

{

	if (*bt == NULL)
		*bt = create_binary_tree(item, NULL, NULL);
	else if ((*bt)->item > item)
		add(&(*bt)->left, item);
	 else 
		add(&(*bt)->right, item);

}




















