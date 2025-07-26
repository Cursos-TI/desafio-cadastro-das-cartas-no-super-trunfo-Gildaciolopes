#include <stdio.h>
#include <string.h>

// Define a struct para representar uma carta do Super Trunfo
typedef struct {
    char estado[3];           // ex: "SP"
    char codigo[4];           // ex: "A01"
    char nomeCidade[100];
    int populacao;            // habitantes
    float area;               // km²
    float pib;                // bilhões de reais
    int pontosTuristicos;
    float densidade;          // habitantes por km²
    float pibPerCapita;       // reais por habitante
} Carta;

// Inicializa uma carta com dados fixos e calcula densidade e PIB per capita
void inicializaCarta(Carta *c,
                     const char *estado,
                     const char *codigo,
                     const char *nomeCidade,
                     int populacao,
                     float area,
                     float pib,
                     int pontosTuristicos)
{
    // Copia strings garantindo terminação nula
    strncpy(c->estado, estado, sizeof(c->estado)-1);
    c->estado[sizeof(c->estado)-1] = '\0';
    strncpy(c->codigo, codigo, sizeof(c->codigo)-1);
    c->codigo[sizeof(c->codigo)-1] = '\0';
    strncpy(c->nomeCidade, nomeCidade, sizeof(c->nomeCidade)-1);
    c->nomeCidade[sizeof(c->nomeCidade)-1] = '\0';

    // Atribui valores
    c->populacao       = populacao;
    c->area            = area;
    c->pib             = pib;
    c->pontosTuristicos= pontosTuristicos;

    // Calcula atributos derivados
    c->densidade       = c->populacao / c->area;               // hab/km²
    c->pibPerCapita    = (c->pib * 1e9f) / c->populacao;      // reais por habitante
}

// Exibe todos os campos de uma carta
void exibeCarta(const Carta *c, int indice) {
    printf("Carta %d:\n", indice);
    printf("  Estado           : %s\n", c->estado);
    printf("  Código           : %s\n", c->codigo);
    printf("  Cidade           : %s\n", c->nomeCidade);
    printf("  População        : %d habitantes\n", c->populacao);
    printf("  Área             : %.2f km²\n", c->area);
    printf("  PIB              : %.2f bilhões de reais\n", c->pib);
    printf("  Pontos Turísticos: %d\n", c->pontosTuristicos);
    printf("  Densidade Pop.   : %.2f hab/km²\n", c->densidade);
    printf("  PIB per Capita   : %.2f reais/hab\n\n", c->pibPerCapita);
}

int main() {
    // --- Inicializa duas cartas pré-definidas ---
    Carta carta1, carta2;
    inicializaCarta(&carta1,
                    "SP", "A01", "São Paulo",
                    12325000, 1521.11f, 699.28f, 50);
    inicializaCarta(&carta2,
                    "RJ", "B02", "Rio de Janeiro",
                    6748000, 1200.25f, 300.50f, 30);

    // Exibe todas as informações calculadas
    printf("\n=== Dados das Cartas ===\n\n");
    exibeCarta(&carta1, 1);
    exibeCarta(&carta2, 2);

    // --- Comparação de atributo ---
    // Escolha do atributo: Densidade Populacional
    const char *atributoNome = "Densidade Populacional";
    float valor1 = carta1.densidade;
    float valor2 = carta2.densidade;

    printf("=== Comparação de Cartas (Atributo: %s) ===\n\n", atributoNome);
    printf("Carta 1 - %s: %.2f hab/km²\n", carta1.nomeCidade, valor1);
    printf("Carta 2 - %s: %.2f hab/km²\n\n", carta2.nomeCidade, valor2);

    // Para densidade, vence quem tiver valor menor
    if (valor1 < valor2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (valor2 < valor1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
