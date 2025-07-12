#include <stdio.h>

int main() {
    // Variáveis para a Carta 1
    char estado1;
    char codigo1[4];        // 3 caracteres + '\0'
    char nome1[100];        // até 99 caracteres + '\0'
    int populacao1;
    float area1;
    float pib1;
    int pontosTur1;

    // Variáveis para a Carta 2
    char estado2;
    char codigo2[4];
    char nome2[100];
    int populacao2;
    float area2;
    float pib2;
    int pontosTur2;

    // --- Leitura dos dados da Carta 1 ---
    printf("Carta 1:\n");
    printf("Informe o Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Informe o Código da Carta (ex: A01): ");
    scanf(" %3s", codigo1);

    // Limpa o buffer antes de ler string com espaços
    getchar();

    printf("Informe o Nome da Cidade: ");
    scanf(" %[^\n]", nome1);

    printf("Informe a População: ");
    scanf("%d", &populacao1);

    printf("Informe a Área (km²): ");
    scanf("%f", &area1);

    printf("Informe o PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Informe o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTur1);

    // --- Leitura dos dados da Carta 2 ---
    printf("\nCarta 2:\n");
    printf("Informe o Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Informe o Código da Carta (ex: B02): ");
    scanf(" %3s", codigo2);

    getchar();

    printf("Informe o Nome da Cidade: ");
    scanf(" %[^\n]", nome2);

    printf("Informe a População: ");
    scanf("%d", &populacao2);

    printf("Informe a Área (km²): ");
    scanf("%f", &area2);

    printf("Informe o PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Informe o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTur2);

    // --- Exibição dos dados cadastrados ---
    printf("\n--- Dados das Cartas ---\n");

    // Carta 1
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código da Carta: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nome1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTur1);

    // Carta 2
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código da Carta: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nome2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTur2);

    return 0;
}

