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

int LeturaArquivo(FILE * arquivo, char * maiorPalavra, char * menorPalavra)
{
    char caractere = 0, palavraLida[255];
    palavraLida[0]='\0';
    int qntCarac = 0, tamMaiorPalavra = 0, tamMenorPalavra = sizeof(int)*2, qntPalavras = 0;


    while ((caractere = fgetc(arquivo)) != EOF)
    {
        if((caractere >= 'A' && caractere <='Z') || (caractere >='a' && caractere <='z'))
        {
            palavraLida[qntCarac] = caractere;
            qntCarac++;
        }
        if(caractere == 32 || caractere == 46)
        {
            palavraLida[qntCarac] = '\0';
            if(qntCarac > tamMaiorPalavra && qntCarac > 0)
            {
                maiorPalavra[0]='\0';
                tamMaiorPalavra = qntCarac;
                strcpy(maiorPalavra, palavraLida);
            }
            if(qntCarac < tamMenorPalavra && qntCarac > 0)
            {
                menorPalavra[0]='\0';
                tamMenorPalavra = qntCarac;
                strcpy(menorPalavra, palavraLida);
            }
            if(qntCarac > 0)
                qntPalavras++;
            qntCarac = 0;
        }
    }
    return qntPalavras;
}

int main()
{
    int qntArq = 0, qntPalavras = 0;
    FILE *arquivo;
    char MenorPalavraGlobal[255], MaiorPalavraGlobal[255];

    do
    {
    qntArq++;
    char nomeArquivo[100], MaiorPalavraLocal[255], MenorPalavraLocal[255];
    GerarNomeArquivo(qntArq, nomeArquivo);
    arquivo = fopen(nomeArquivo, "rb");
    if(arquivo == NULL)
        {
            printf("INFO - Foram lidos %d arquvios", qntArq - 1);
            break;
        }
    qntPalavras += LeturaArquivo(arquivo, MaiorPalavraLocal, MenorPalavraLocal);
    printf("INFO - Maior palavra do arquivo %d: %s\n", qntArq, MaiorPalavraLocal);
    printf("INFO - Menor palavra do arquivo %d: %s\n\n", qntArq, MenorPalavraLocal);
    }while (1 || qntArq > 1);

    printf("Qnt palavras lidas: %d", qntPalavras);
    return 0;
}
