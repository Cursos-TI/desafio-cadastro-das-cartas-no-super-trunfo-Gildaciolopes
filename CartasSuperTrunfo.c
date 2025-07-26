#include <stdio.h>
#include <string.h>

// Definição da struct para uma carta
typedef struct {
    char estado[3];
    char codigo[4];
    char nomeCidade[100];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;  // hab/km²
} Carta;

// Inicializa uma carta com dados fixos e calcula densidade
void inicializaCarta(Carta *c,
                     const char *estado,
                     const char *codigo,
                     const char *nomeCidade,
                     int populacao,
                     float area,
                     float pib,
                     int pontosTuristicos)
{
    strncpy(c->estado, estado, sizeof(c->estado)-1);
    c->estado[2] = '\0';
    strncpy(c->codigo, codigo, sizeof(c->codigo)-1);
    c->codigo[3] = '\0';
    strncpy(c->nomeCidade, nomeCidade, sizeof(c->nomeCidade)-1);
    c->nomeCidade[99] = '\0';

    c->populacao        = populacao;
    c->area             = area;
    c->pib              = pib;
    c->pontosTuristicos = pontosTuristicos;
    c->densidade        = populacao / area;
}

// Recupera o valor do atributo escolhido na carta
float getValorAtributo(const Carta *c, int atributo) {
    switch (atributo) {
        case 1: return (float)c->populacao;
        case 2: return c->area;
        case 3: return c->pib;
        case 4: return (float)c->pontosTuristicos;
        case 5: return c->densidade;
        default: return 0.0f;
    }
}

// Recupera o nome do atributo para exibição
const char* getNomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População (hab)";
        case 2: return "Área (km²)";
        case 3: return "PIB (bilhões R$)";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica (hab/km²)";
        default: return "Desconhecido";
    }
}

int main() {
    // Cartas pré-cadastradas
    Carta carta1, carta2;
    inicializaCarta(&carta1, "SP", "A01", "São Paulo",     12325000, 1521.11f, 699.28f, 50);
    inicializaCarta(&carta2, "RJ", "B02", "Rio de Janeiro",  6748000, 1200.25f, 300.50f, 30);

    int attr1, attr2;
    printf("=== Super Trunfo: Comparação Avançada ===\n\n");

    // Menu para primeiro atributo
    printf("Escolha o PRIMEIRO atributo para comparar:\n");
    printf(" 1. População\n");
    printf(" 2. Área\n");
    printf(" 3. PIB\n");
    printf(" 4. Pontos Turísticos\n");
    printf(" 5. Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &attr1);

    if (attr1 < 1 || attr1 > 5) {
        printf("Opção inválida!\n");
        return 1;
    }

    // Menu para segundo atributo, sem repetir o primeiro
    printf("\nEscolha o SEGUNDO atributo (diferente de %s):\n", getNomeAtributo(attr1));
    if (attr1 != 1) printf(" 1. População\n");
    if (attr1 != 2) printf(" 2. Área\n");
    if (attr1 != 3) printf(" 3. PIB\n");
    if (attr1 != 4) printf(" 4. Pontos Turísticos\n");
    if (attr1 != 5) printf(" 5. Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &attr2);

    if (attr2 < 1 || attr2 > 5 || attr2 == attr1) {
        printf("Opção inválida ou repetida!\n");
        return 1;
    }

    // Recupera nomes e valores
    const char *nome1 = getNomeAtributo(attr1);
    const char *nome2 = getNomeAtributo(attr2);
    float v1a = getValorAtributo(&carta1, attr1);
    float v2a = getValorAtributo(&carta2, attr1);
    float v1b = getValorAtributo(&carta1, attr2);
    float v2b = getValorAtributo(&carta2, attr2);

    // Exibe comparações individuais
    printf("\n--- Comparação de Atributos ---\n");
    printf("%s:\n", nome1);
    printf("  %s: %.2f\n", carta1.nomeCidade, v1a);
    printf("  %s: %.2f\n\n", carta2.nomeCidade, v2a);

    printf("%s:\n", nome2);
    printf("  %s: %.2f\n", carta1.nomeCidade, v1b);
    printf("  %s: %.2f\n\n", carta2.nomeCidade, v2b);

    // Soma dos valores brutos
    float soma1 = v1a + v1b;
    float soma2 = v2a + v2b;

    // Determina vencedor das somas
    int vencedor = (soma1 > soma2) ? 1
                 : (soma2 > soma1) ? 2
                 : 0;  // empate

    // Exibe soma e resultado
    printf("Soma de %s + %s:\n", nome1, nome2);
    printf("  %s: %.2f\n", carta1.nomeCidade, soma1);
    printf("  %s: %.2f\n\n", carta2.nomeCidade, soma2);

    if (vencedor == 1) {
        printf("Resultado FINAL: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (vencedor == 2) {
        printf("Resultado FINAL: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
