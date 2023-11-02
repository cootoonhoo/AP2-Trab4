#include <stdlib.h>
#include <stdio.h>

int main()
{
    FILE *arquivo;
    arquivo = fopen("./trabalho4/rev1.bin", "rb");
    char linha[255];
    if(arquivo == NULL)
    {
        printf("Erro ao ler o arquivo!\n");
        exit(-1);
    }

    while(fgets(linha, sizeof(linha), arquivo) != NULL) 
    {
        printf("%s", linha);
    }

    return 0;
}
