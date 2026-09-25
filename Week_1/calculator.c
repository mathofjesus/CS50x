#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Exibir menu de operações
    printf("=== Calculadora ===\n");
    printf("Operações disponíveis:\n");
    printf("  +  Adição\n");
    printf("  -  Subtração\n");
    printf("  *  Multiplicação\n");
    printf("  /  Divisão\n");
    printf("===================\n\n");

    // Ler primeiro número
    float n1;
    printf("Digite o primeiro número: ");
    n1 = get_float("");

    // Ler operação
    char op;
    printf("Digite a operação (+, -, *, /): ");
    op = get_char("");

    // Validar operação
    if (op != '+' && op != '-' && op != '*' && op != '/')
    {
        printf("Erro: operação inválida! Use +, -, * ou /\n");
        return 1;
    }

    // Ler segundo número
    float n2;
    printf("Digite o segundo número: ");
    n2 = get_float("");

    // Calcular resultado
    float resultado;
    switch (op)
    {
        case '+':
            resultado = n1 + n2;
            break;
        case '-':
            resultado = n1 - n2;
            break;
        case '*':
            resultado = n1 * n2;
            break;
        case '/':
            if (n2 == 0)
            {
                printf("Erro: divisão por zero não é permitida!\n");
                return 1;
            }
            resultado = n1 / n2;
            break;
    }

    // Exibir resultado
    printf("\nResultado: %.2f %c %.2f = %.2f\n", n1, op, n2, resultado);

    return 0;
}
