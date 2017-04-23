#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "binary_treee.c"


int main()
{
	list *arvore = creat_list();
	FILE* arquivo;
    char letra;
	arquivo = fopen("imagem.jpg", "rt");
	if (arquivo == NULL)
	{
		printf("error\n");
		return 0;
	}
	FILE *teste = fopen("testando00.jpg", "w+");
	int i = 0;
	
	
	while(fscanf(arquivo,"%c",&letra) != EOF)
	{
		add_end(arvore,letra);
	} 
	fclose(arquivo);
	printf("arquivo lido.\n");
	
	//sort(arvore);

	print_list(arvore->first);
	/*while(size_of_List(arvore) >2)
	{
		arvore = merge_tree(arvore);
		;
	}*/
	binary_tree* bt = arvore->first;
	
	
    while(bt != NULL)
    {
    	fprintf(teste, "%c", bt->item );
    	bt = bt->next;
    }
	
    fclose(teste);
	
	return 0;
}
