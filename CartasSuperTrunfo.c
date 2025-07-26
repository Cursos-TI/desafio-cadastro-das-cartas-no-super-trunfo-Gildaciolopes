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
} Carta;

// Função para inicializar uma carta e calcular sua densidade populacional
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
    c->populacao        = populacao;
    c->area             = area;
    c->pib              = pib;
    c->pontosTuristicos = pontosTuristicos;

    // Calcula densidade populacional
    c->densidade = populacao / area;
}

int main() {
    // --- Cartas pré-definidas ---
    Carta carta1, carta2;
    inicializaCarta(&carta1,
                    "SP", "A01", "São Paulo",
                    12325000, 1521.11f, 699.28f, 50);
    inicializaCarta(&carta2,
                    "RJ", "B02", "Rio de Janeiro",
                    6748000, 1200.25f, 300.50f, 30);

    int opcao;
    char *nomeAtributo;
    float val1, val2;

    // --- Menu interativo ---
    printf("=== Super Trunfo: Comparação de Cartas ===\n");
    printf("Escolha o atributo para comparar:\n");
    printf(" 1. População\n");
    printf(" 2. Área\n");
    printf(" 3. PIB\n");
    printf(" 4. Pontos Turísticos\n");
    printf(" 5. Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    // --- Determina atributo e valores ---
    switch(opcao) {
        case 1:
            nomeAtributo = "População (hab)";
            val1 = carta1.populacao;
            val2 = carta2.populacao;
            break;
        case 2:
            nomeAtributo = "Área (km²)";
            val1 = carta1.area;
            val2 = carta2.area;
            break;
        case 3:
            nomeAtributo = "PIB (bilhões R$)";
            val1 = carta1.pib;
            val2 = carta2.pib;
            break;
        case 4:
            nomeAtributo = "Pontos Turísticos";
            val1 = carta1.pontosTuristicos;
            val2 = carta2.pontosTuristicos;
            break;
        case 5:
            nomeAtributo = "Densidade Demográfica (hab/km²)";
            val1 = carta1.densidade;
            val2 = carta2.densidade;
            break;
        default:
            printf("Opção inválida! Encerrando o jogo.\n");
            return 1;
    }

    // --- Exibe comparação ---
    printf("\n--- Comparação de Cartas (%s) ---\n", nomeAtributo);
    printf("1) %s: %.2f\n", carta1.nomeCidade, val1);
    printf("2) %s: %.2f\n\n", carta2.nomeCidade, val2);

    // --- Lógica de decisão ---
    if (opcao == 5) {
        // Para densidade, quem tiver VALOR MENOR vence
        if (val1 < val2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else {
            // aninhando para tratar empate
            if (val2 < val1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
            }
        }
    } else {
        // Para os demais, quem tiver VALOR MAIOR vence
        if (val1 > val2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else {
            // aninhando para tratar empate
            if (val2 > val1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
            } else {
                printf("Empate!\n");
            }
        }
    }

    return 0;
}
