#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int PrimeiraSemanaNoMes(int ano) //Função do Stack Overflow, ainda tentando entender como funciona
{

    int PrimeiraSemana;
    PrimeiraSemana = (((ano - 1) * 365) + ((ano - 1) / 4) - ((ano - 1) / 100) + ((ano) / 400) + 1) % 7;

    return PrimeiraSemana;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int ano, mes, dia, diasNoMes, diaDaSemana = 0, DiaInicial;                                                                                     // Variavies usada no programa
    char *meses[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"}; //Declarando os meses do ano
    int diaMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};                                                                               //Declarando o ultimo dia de cada mes (Sem ano bissexto)

    system("cls"); //Comando para limpar o terminal, pois fica muito poluído
    printf("\nDigite o ano desejado: ");
    scanf("%d", &ano);

    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
        diaMes[1] = 29; // If usada para verifica se o ano é bissexto, se sim fevereiro recebe 29 no dia final

    DiaInicial = PrimeiraSemanaNoMes(ano);

    for (mes = 0; mes < 12; mes++) //For para imprimir os 12 meses do char *meses
    {

        diasNoMes = diaMes[mes]; //Pegando em qual dia o mes acaba para ver quantos dias tem no mes
        printf("\n\n---------------%s-------------------\n", meses[mes]);
        printf("\n  Dom  Seg  Ter  Qua  Qui  Sex  Sab\n");

        for (diaDaSemana = 0; diaDaSemana < DiaInicial; diaDaSemana++)
            printf("     "); //Espaçamento entre as datas

        for (dia = 1; dia <= diasNoMes; dia++) //For para printa dias do mes
        {
            printf("%5d", dia);

            if (++diaDaSemana > 6) //Quando chegar no sabado pula linha
            {
                printf("\n");
                diaDaSemana = 0;
            }
            DiaInicial = diaDaSemana;
        }
    }
}
