#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXARQUIVOS 100

int tamString(char * str)
{
    if(str[0] == '\0') return 0;
    return 1 + tamString((str+1));
}

void GerarNomeArquivoLeitura(int numArq, char * nomeArquivo)
{
    nomeArquivo[0] = '\0';
    char charNumArq[10];
    itoa(numArq, charNumArq, 10);
    strcat(nomeArquivo,"./trabalho4/rev");
    strcat(nomeArquivo,charNumArq);
    strcat(nomeArquivo,".bin");
}

void GerarNomeArquivoImpressao(int numArq, char * nomeArquivo)
{
    nomeArquivo[0] = '\0';
    char charNumArq[10];
    itoa(numArq, charNumArq, 10);
    strcat(nomeArquivo,"./trabalho4texto/rev");
    strcat(nomeArquivo,charNumArq);
    strcat(nomeArquivo,".txt");
}

int LeturaArquivo(FILE * arquivo, char * maiorPalavra, char * menorPalavra)
{
    char caractere = 0, palavraLida[255];
    palavraLida[0]='\0';
    int qntCarac = 0, tamMaiorPalavra = 0, tamMenorPalavra = 255, qntPalavras = 0;


    while ((caractere = fgetc(arquivo)) != EOF)
    {
        if((caractere >= 'A' && caractere <='Z') || (caractere >='a' && caractere <='z') || (caractere >='0' && caractere <='9'))
        {
            palavraLida[qntCarac] = caractere;
            qntCarac++;
        }
        if(caractere == 32 || caractere == 46 || caractere == 10 || caractere == 9) // Espaço | . | \n | \t
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
    if(qntCarac != 0)
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
            qntPalavras++;
    }
    return qntPalavras;
}

int QuantidadeParagrafosArquivo(FILE * arquivo)
{
    char caractere = 0, caractereAnterior = 0;
    int qntParagrafos = 0;
    while ((caractere = fgetc(arquivo)) != EOF)
    {
        if(caractere == '\t'  && caractereAnterior == '\n')
            qntParagrafos++;
        caractereAnterior = caractere;
    }
    if(caractere == EOF)
        qntParagrafos++;
    return qntParagrafos;
}

void ReescreverArquivoTxt(FILE * arquivo, int numArquivo)
{
    char NomeNovoArquivo[100], caractere = 0, caractereAnterior = 0;
    FILE * novoArquivo;
    GerarNomeArquivoImpressao(numArquivo, NomeNovoArquivo);
    novoArquivo = fopen(NomeNovoArquivo, "w");
    if(novoArquivo == NULL)
    {
        printf("Foi impossivel reescrever o novo arquivo!\n");
        exit(EXIT_FAILURE);
    }
    while ((caractere = fgetc(arquivo)) != EOF)
    {
        // printf("C = %c %d\n", caractere, caractere);
        // printf("CA = %c %d\n", caractereAnterior, caractereAnterior);
        // system("pause");
        if(caractere == '\n')
        {
            continue;
        }
        caractereAnterior = caractere;
        fputc(caractere, novoArquivo);
    }
    fclose(novoArquivo);
}

int main()
{
    int qntArq = 0, qntPalavras = 0 ,qntParagrafos = 0, tamMaiorPalavra = 0, tamMenorPalavra = 255, check = 0;
    FILE *arquivo, *arquivoOut;
    char MenorPalavraGlobal[255], MaiorPalavraGlobal[255];

    check = mkdir("trabalho4texto");
    if(check)
    {
        printf("Nao foi possivel criar o diretorio trabalho4texto! Verifique se o diretorio ja existe.\n\n");

    }
    else
    {
        printf("Diretorio trabalho4texto criado com sucesso!\n\n");
    }

    do
    {
        qntArq++;
        char nomeArquivo[100], MaiorPalavraLocal[255], MenorPalavraLocal[255];
        GerarNomeArquivoLeitura(qntArq, nomeArquivo);
        arquivo = fopen(nomeArquivo, "rb");
        if(arquivo == NULL)
        {
            printf("INFO - Foram lidos %d arquvios\n", --qntArq);
            break;
        }
        qntPalavras += LeturaArquivo(arquivo, MaiorPalavraLocal, MenorPalavraLocal);
        fseek(arquivo, 0 ,SEEK_SET);
        qntParagrafos += QuantidadeParagrafosArquivo(arquivo);
        fseek(arquivo, 0 ,SEEK_SET);
        ReescreverArquivoTxt(arquivo,qntArq);

        printf("INFO - Maior palavra do arquivo %d: %s\n", qntArq, MaiorPalavraLocal);
        printf("INFO - Menor palavra do arquivo %d: %s\n\n", qntArq, MenorPalavraLocal);

        if(tamString(MaiorPalavraLocal) > tamMaiorPalavra)
        {
            tamMaiorPalavra = tamString(MaiorPalavraLocal);
            strcpy(MaiorPalavraGlobal, MaiorPalavraLocal);
        }

        if(tamString(MenorPalavraLocal) < tamMenorPalavra)
        {
            tamMenorPalavra = tamString(MaiorPalavraLocal);
            strcpy(MenorPalavraGlobal, MenorPalavraLocal);
        }
        fclose(arquivo);
    } while (1 && qntArq < MAXARQUIVOS);

    if(qntArq > MAXARQUIVOS)
    {
        printf("Voce ultrapassou o max de arquivos a serem lidos!\n");
        exit(EXIT_FAILURE);
    }

    //Debug visual do arquivo Out
    printf("\nDados arquivo out \n\n");
    printf("Media do numero de palavras por review: %.2f\n", qntPalavras/(float)qntArq);
    printf("Media de paragrafos por review: %.2f\n", qntParagrafos/(float)qntArq);
    printf("Maior palavra: %s\n", MaiorPalavraGlobal);
    printf("Menor palavra: %s\n", MenorPalavraGlobal);

    arquivoOut = fopen("relatorio.out", "wb");
    if(arquivoOut == NULL)
    {
        printf("Nao foi possivel criar o arquivo relatorio.out!\n");
        exit(EXIT_FAILURE);
    }

    //Escrevendo o arquivo Out
    fprintf(arquivoOut, "Media do numero de palavras por review: %.2f\n", qntPalavras/(float)qntArq);
    fprintf(arquivoOut, "Media de paragrafos por review: %.2f\n", qntParagrafos/(float)qntArq);
    fprintf(arquivoOut,"Maior palavra: %s\n", MaiorPalavraGlobal);
    fprintf(arquivoOut,"Menor palavra: %s\n", MenorPalavraGlobal);
    printf("Arquivo relatorio.out criado com sucesso!\n");
    fclose(arquivoOut);
    return 0;
}
