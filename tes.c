#include <stdio.h>
#include "binary_treee.c"
int main()
{
    binary_tree *arvore = NULL;
	FILE* arquivo;
	char letra;
	arquivo = fopen("teste.txt", "rt");
	if (arquivo == NULL)
	{
		printf("error\n");
		return 0;
	}
	
	while(fscanf(arquivo,"%c",&letra) != EOF)
	{
		printf("%c",letra);
	}
	add_sorted(arvore,5);
    add_sorted(arvore,5);
    add_sorted(arvore,5);
	printf("ok\n");
	fclose(arquivo);
    print_list(arvore);
	return 0;

}