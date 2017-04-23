int n;
void getm(int matriz[][n], int tam)
{
    int i,j;
    for(i=0;i<tam;i++)
	{
 		for (j=0;j<tam;j++)
		{
			scanf("%d",&matriz[i][j]);
		}
	}
}

void printmatriz(int matriz[][n], int tam)
{
    int i,j;
    for(i=0;i<tam;i++)
	{
 		for (j=0;j<tam;j++)
		{
			printf("%d ",matriz[i][j]);
		}
		printf("\n");
	}
}