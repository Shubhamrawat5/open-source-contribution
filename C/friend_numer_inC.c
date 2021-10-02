#include <stdio.h>

int soma_divisores(int a)
{
    int soma = 0, i;
    for (i = 1; i < a; i++)
    {
        (a % i) == 0 ? soma += i : 0;
    }
    return soma;
}

/** Define se a e b sao amigos. Dois inteiros sao amigos se a soma de
    todos os divisores próprios de um é igual ao outro e vice-versa.
    Exemplos: (220, 284), (1184, 1210), (2620, 2924).
    Retorna 0 se a e b nao sao amigos e 
    qualquer outro valor se a e b sao amigos. 
    Aluno: Breno Vambaster
*/
int amigos(int a, int b)
{
    return (soma_divisores(a) == b && soma_divisores(b) == a) ? 1 : 0;
}

int main()
{
    int A, B;
    scanf("%i%i", &A, &B);
    amigos(A, B) ? printf("amigos\n") : printf("nao amigos\n");

    return 0;
}
