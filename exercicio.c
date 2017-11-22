#include <stdio.h>

void horas(int hora)
{
	if(hora >= 0 && hora <= 5) printf("madrugada\n");
	if(hora >= 6 && hora <= 12) printf("manha\n");
	if(hora >= 13 && hora <= 17) printf("tarde\n");
	if(hora >= 18 && hora <= 23 ) printf("noite\n");
	else printf("digite uma hora valida seu merda _|_\n");
}

int main()
{
	int hrs;
	scanf("%d",&hrs);
	horas(hrs);
	return 0;
}