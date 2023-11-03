#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void GerarNomeArquivo(int numArq, char * nomeArquivo)
{
    nomeArquivo[0] = '\0';
    char charNumArq[10];
    itoa(numArq, charNumArq, 10);
    strcat(nomeArquivo,"./trabalho4/rev");
    strcat(nomeArquivo,charNumArq);
    strcat(nomeArquivo,".bin");
}

int main()
{
    int qntArq = 0;
    FILE *arquivo;

    do
    {
    qntArq++;
    char nomeArquivo[100];
    GerarNomeArquivo(qntArq, nomeArquivo);
    printf("%s\n",nomeArquivo);
    arquivo = fopen(nomeArquivo, "rb");
    if(arquivo == NULL)
        {
            printf(" INFO - Foram lidos %d arquvios", qntArq - 1);
            break;
        }
    free(nomeArquivo);
    }while (1 || qntArq >100);
    return 0;
}
