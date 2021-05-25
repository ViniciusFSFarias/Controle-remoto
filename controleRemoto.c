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

void ligaDesliga();
void volume();
void canal();
void teclado();
void cor();

int main()
{
	setlocale(LC_ALL, "");
	
	volGeral = 10;
	chnGeral = 10;
	pwrGeral = FALSE;
	char onOff[3];
	
	tv tela;
	
	//sessão de print do monitor:
	MONITOR:

	tela.pwr = pwrGeral;
	
	if(tela.pwr == FALSE)
	{
		onOff[0] = 'O';
		onOff[1] = 'F';
		onOff[2] = 'F';
		
		tela.vol = 0;
		tela.chn = 0;
	}
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

void volume()
{
	if(pwrGeral == TRUE)
	{
		if(escolha == 1)
		{
			volGeral += 10;
			
			if(volGeral > 90)
			{
				volGeral -= 10;
			}
		}
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

void canal()
{
	if(pwrGeral == TRUE)
	{
		if(escolha == 3)
		{
			chnGeral += 5;
			
			if(chnGeral > 90)
			{
				chnGeral -= 5;
			}
		}
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

void teclado()
{
	if(pwrGeral == TRUE)
	{
		printf("\n\nDigite um canal: ");
		scanf("%d", &chnGeral);
		
		while(chnGeral > 90 || chnGeral < 0)
		{
			printf("Canal inválido, digite outro: ");
			scanf("%d", &chnGeral);
		}
	}
}

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
