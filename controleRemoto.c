#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TRUE 1
#define FALSE 0

//variáveis globais para fazer a comunicação entre funções:
int volGeral;
int chnGeral;
int pwrGeral;
int escolha;

//struct para utilizar na impressão da televisão
typedef struct TELEVISAO 
{
	int vol;
	int chn;
	int pwr;
	
} tv;

//funções que serão utilizadas no programa:
void ligaDesliga();
void volume();
void canal();
void teclado();
void cor();

int main()
{
	setlocale(LC_ALL, "");
	
	//atribuindo valores para as variáveis globais
	volGeral = 10;
	chnGeral = 10;
	pwrGeral = FALSE;
	char onOff[3];
	
	tv tela;
	
	//sessão de print do monitor:
	MONITOR:
	
	//variável que armazena o estado de energia da tv: ligada ou desligada
	tela.pwr = pwrGeral;
	
	//condicional que imprime que a televisão está desligada, além de zerar canal e volume
	if(tela.pwr == FALSE)
	{
		onOff[0] = 'O';
		onOff[1] = 'F';
		onOff[2] = 'F';
		
		tela.vol = 0;
		tela.chn = 0;
	}
	//condicional que informa que a televisão está ligada e informa os últimos valores para canal e volume
	else
	{
		onOff[0] = 'O';
		onOff[1] = 'N';
		onOff[2] = ' ';
		
		tela.vol = volGeral;
		tela.chn = chnGeral;
	}
	
	//print da tela:
	printf(" ---------------\n|%c%c%c            |\n|VOL = %d        |\n|CHN = %d        |\n ---------------\n\n",onOff[0], onOff[1], onOff[2], tela.vol, tela.chn);
	
	//print menu do controle:
	printf("(0) ON/OFF\n(1) + VOL\n(2) - VOL\n(3) + CHN\n(4) - CHN\n(5) TECLADO CHN\n(6) COR BACKGROUND\n(7) TOMADA\n\n");
	scanf("%d", &escolha);
	
	//comportamento dos botões:
	switch(escolha)
	{
		case 0:
		{
			ligaDesliga();
			system("cls");
			goto MONITOR;
		}break;
		
		case 1:
		{
			volume();
			system("cls");
			goto MONITOR;
		}break;
		
		case 2:
		{
			volume();
			system("cls");
			goto MONITOR;
		}break;
		
		case 3:
		{
			canal();
			system("cls");
			goto MONITOR;   	
		}break;
		
		case 4:
		{
			canal();
			system("cls");
			goto MONITOR;
		}break;
		
		case 5:
		{
			teclado();
			system("cls");
			goto MONITOR;
		}break;
		
		case 6:
		{
			cor();
			system("cls");
			goto MONITOR;
		}break;
		
		case 7:
		{
			exit(0);
		}break;
	}
	
	return 0;
}

//função que liga e desliga  a tv alterando o valor da variável global
void ligaDesliga()
{
	if(pwrGeral == FALSE)
	{
		pwrGeral = TRUE;
	}
	else
	{
		pwrGeral = FALSE;
	}
}

//função que altera o volume da tv caso esteja ligada
void volume()
{
	if(pwrGeral == TRUE)
	{	//aumenta o volume de 10 em 10 até o limite de 90
		if(escolha == 1)
		{
			volGeral += 10;
			
			if(volGeral > 90)
			{
				volGeral -= 10;
			}
		}
		//diminui o volume de 10 em 10 até o valor mínimo de 10
		else if(escolha == 2)
		{
			volGeral -= 10;
			
			if(volGeral < 10)
			{
				volGeral += 10;
			}
		}
	}
}

//função que altera o canal da televisão caso ela esteja ligada
void canal()
{
	if(pwrGeral == TRUE)
	{	//aumenta o canal de 5 em 5 até o máximo de 90
		if(escolha == 3)
		{
			chnGeral += 5;
			
			if(chnGeral > 90)
			{
				chnGeral -= 5;
			}
		}
		//diminui o canal de 5 em 5 até o mínimo de 10
		else if(escolha == 4)
		{
			chnGeral -= 5;
			
			if(chnGeral < 10)
			{
				chnGeral += 5;
			}
		}
	}
}

//função que altera o canal baseado no input do usuário
void teclado()
{
	if(pwrGeral == TRUE)
	{
		printf("\n\nDigite um canal: ");
		scanf("%d", &chnGeral);
		
		//o input não será aceito caso seja maior que 90 ou menor que 0
		while(chnGeral > 90 || chnGeral < 0)
		{
			printf("Canal inválido, digite outro: ");
			scanf("%d", &chnGeral);
		}
	}
}

//função que altera a cor de fundo do cmd baseado em input do usuário
void cor()
{
	if(pwrGeral == TRUE)
	{
		printf("\n\nEscolha uma das opções a seguir par cor de fundo:\n1 - Preto\n2 - Azul\n3 - Vermelho\n4 - Verde\n5 - Roxo\n");
		scanf("%d", &escolha);
		
		switch(escolha)
		{
			case 1:
			{
				system("color 07");
			}break;
			
			case 2:
			{
				system("color 17");
			}break;
			
			case 3:
			{
				system("color 47");
			}break;
			
			case 4:
			{
				system("color 27");
			}break;
			
			case 5:
			{
				system("color 57");
			}break;
		}
	}
}
