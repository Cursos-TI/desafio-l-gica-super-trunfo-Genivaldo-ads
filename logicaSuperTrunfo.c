#include <stdio.h>
#include <string.h>

struct Carta { // Definindo a estrutura das cartas
    char estado;
    char codigo[10];
    char nome_cidade[30];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
};

void lerCarta(struct Carta* carta, int numero) {  // Dados das Cartas
    printf("////CARTA//// %d\n", numero);
    printf("Forneça uma letra de 'A' a 'H' para o estado:\n");
    scanf(" %c", &carta->estado);
    
    printf("Forneça o código da carta (01 até 04):\n");
    scanf("%s", carta->codigo);
    
    printf("Forneça o nome da cidade:\n");
    getchar(); // limpar o buffer
    fgets(carta->nome_cidade, sizeof(carta->nome_cidade), stdin);
    carta->nome_cidade[strcspn(carta->nome_cidade, "\n")] = '\0';
    
    printf("Forneça a população da cidade:\n");
    scanf("%d", &carta->populacao);
    
    printf("Forneça a área da cidade(km²):\n");
    scanf("%f", &carta->area);
    
    printf("Forneça o PIB da cidade(R$):\n");
    scanf("%f", &carta->pib);
    
    printf("Forneça o número de pontos turísticos da cidade:\n");
    scanf("%d", &carta->pontos_turisticos);
}
            
void exibirCarta(struct Carta carta, int numero) {
    printf("\n==== Carta %d ====\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código da carta: %c%s\n", carta.estado, carta.codigo);
    printf("Nome da cidade: %s\n", carta.nome_cidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f\n", carta.pib);
    printf("Número de pontos turísticos: %d\n", carta.pontos_turisticos);
}

void compararCartas(struct Carta c1, struct Carta c2) {
    int escolha;

    //Escolha uma categoria para fazer a comparação
    printf("\nEscolha a categoria para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de pontos turísticos\n");
    printf("Digite o número da categoria: ");
    scanf("%d", &escolha);

    printf("\n Comparando Cartas \n");

    switch (escolha) {
        case 1:
            printf("População Carta 1: %d\n", c1.populacao);
            printf("População Carta 2: %d\n", c2.populacao);
            if (c1.populacao > c2.populacao)
                printf(">> Carta 1 vence!\n");
            else if (c1.populacao < c2.populacao)
                printf(">> Carta 2 vence!\n");
            else
                printf(">> Empate!\n");
            break;

        case 2:
            printf("Área Carta 1: %.2f km²\n", c1.area);
            printf("Área Carta 2: %.2f km²\n", c2.area);
            if (c1.area > c2.area)
                printf(">> Carta 1 vence!\n");
            else if (c1.area < c2.area)
                printf(">> Carta 2 vence!\n");
            else
                printf(">> Empate!\n");
            break;

        case 3:
            printf("PIB Carta 1: R$ %.2f\n", c1.pib);
            printf("PIB Carta 2: R$ %.2f\n", c2.pib);
            if (c1.pib > c2.pib)
                printf(">> Carta 1 vence!\n");
            else if (c1.pib < c2.pib)
                printf(">> Carta 2 vence!\n");
            else
                printf(">> Empate!\n");
            break;

        case 4:
            printf("Pontos turísticos Carta 1: %d\n", c1.pontos_turisticos);
            printf("Pontos turísticos Carta 2: %d\n", c2.pontos_turisticos);
            if (c1.pontos_turisticos > c2.pontos_turisticos)
                printf(">> Carta 1 vence!\n");
            else if (c1.pontos_turisticos < c2.pontos_turisticos)
                printf(">> Carta 2 vence!\n");
            else
                printf(">> Empate!\n");
            break;

        default:
            printf("Categoria inválida.\n");
    }
}

int main() {
    struct Carta carta1, carta2;

    printf("SUPER TRUNFO\n\n");   //Titulo do jogo

    lerCarta(&carta1, 1);   //Faz a leitura da carta 1
    lerCarta(&carta2, 2);   //Faz a leitura da carta 2

    exibirCarta(carta1, 1);  //Exibe a carta 1
    exibirCarta(carta2, 2);  //Exibe a carta 2

    compararCartas(carta1, carta2);  //compara as cartas

    return 0;
}
