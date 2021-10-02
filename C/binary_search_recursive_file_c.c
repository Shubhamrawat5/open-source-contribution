#include <stdio.h>
#include <stdlib.h>
#define BYTE 10

int busca_binaria(FILE *arq, int inico, int fim, int num_procurado)
{
    int meio, valor_testado;
    if (fim - inico <= 0)
        return -1;
    meio = (fim + inico) / 2;

    fseek(arq, meio * BYTE, SEEK_SET);
    fscanf(arq, "%d", &valor_testado);

    if (num_procurado == valor_testado)
        return meio;
    else if (num_procurado < valor_testado)
        return busca_binaria(arq, inico, meio, num_procurado);
    else
        return busca_binaria(arq, meio + 1, fim, num_procurado);
}

int main()
{

    int numero_buscado, final_arq;
    char nome_arquivo[100];
    int posi;

    scanf("%s", nome_arquivo);
    scanf("%d", &numero_buscado);

    FILE *arq_d_pesquisa = fopen(nome_arquivo, "r");

    if ((arq_d_pesquisa == NULL))
    {
        fprintf(stderr, "Algum nome de arguivo de entrada invalido");
        return 4;
    }

    fseek(arq_d_pesquisa, 0, SEEK_END);

    final_arq = ftell(arq_d_pesquisa);

    fseek(arq_d_pesquisa, 0, SEEK_SET);

    final_arq = final_arq / BYTE;

    posi = busca_binaria(arq_d_pesquisa, 0, final_arq, numero_buscado);

    if (posi == -1)
    {
        printf("Valor nao encontrado");
    }
    else
    {
        printf("Valor encontrado na posicao %d", posi);
    }
    fclose(arq_d_pesquisa);
    return 0;
}