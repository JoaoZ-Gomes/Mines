#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wchar.h>
#include <unistd.h>

// Itens do tabuleiro 
#define LINHAS 5  // quantidade de linhas 
#define COLUNAS 5 // quantidade de colunas
#define MINAS 7 // quantidade de bombas
#define ODD 1.50  // odd dos ganhos

// Variáveis globais 
typedef struct{
    int minas;
    int aberto; // verificar se um local já foi aberto
    int lados;  // quantidade de bombas aos lados 
}celula;

celula tab[LINHAS][COLUNAS];

void clearScreen() {
    //limpa a tela
    printf("\033[H\033[J");
}
//imprime a bomba
void bomba(int segundos) {
    clearScreen();
    printf("BOMBA\n\n");


    printf("     _____\n");
    printf("   /      \\\n");
    printf("  |  BOMB  |\n");
    printf("   \\______/ \n");
    printf("    |    |\n");
    printf("    |    |\n");
    printf("    |____|\n");
    printf("     \\  /\n");
    printf("      ||\n");
    printf("      ||\n");
    printf("      ||\n");

    printf("\nTempo restante: %d segundos\n", segundos);
}
//explosão da bomba
void explosao(int stagio) {
    clearScreen();
    switch (stagio) {
        case 1:
            printf("                       $#     #     #¢ \n");
            printf("           #######       #¢   #   ø#   \n");
            printf("          ##    ø###      oø  ø  øo    \n");
            printf("          #7       ###      1   1    1o\n");
            printf("       #######       ###7        1o###ø\n");
            printf("       #######         ################  1     \n");
            printf("     o#########ø                  o$¢  \n");
            printf("   ###############          ¢  1ø   1##\n");
            printf("  #################o       1$   #      \n");
            printf(" ###################       #    o#     \n");
            printf(" ####################     ##           \n");
            printf("  ##################                   \n");
            printf("   ################                    \n");
            printf("     ############                      \n");
            printf("       ########                         \n");
            break;
        case 2:
            printf("\n\n\n");
            printf("                       $#     #     #¢ \n");
            printf("           #######       #¢   #   ø#   \n");
            printf("          ##    ø###      oø  ø  øo    \n");
            printf("          #7       ###      1   1    1o\n");
            printf("       #######       ###&       1o###ø\n");
            printf("       #######         #########1     \n");
            printf("     o#########ø                  o$¢  \n");
            printf("   ###############          ¢  1ø   1##\n");
            printf("  #################o       1$   #      \n");
            printf(" ###################       #    o#     \n");
            printf(" ####################     ##           \n");
            printf("  ##################                   \n");
            printf("   ################                    \n");
            printf("     ############                      \n");
            printf("       ########                         \n");
            break;
        case 3:
            printf("\n\n\n");
            printf("                       $#     #     #¢ \n");
            printf("           #######       #¢   #   ø#   \n");
            printf("          ##    ø###      oø  ø  øo    \n");
            printf("          #7       ###      1   1    1o\n");
            printf("       #######             1o###ø\n");
            printf("       #######           1     \n");
            printf("     o#########ø                  o$¢  \n");
            printf("   ###############          ¢  1ø   1##\n");
            printf("  #################o       1$   #      \n");
            printf(" ###################       #    o#     \n");
            printf(" ####################     ##           \n");
            printf("  ##################                   \n");
            printf("   ################                    \n");
            printf("     ############                      \n");
            printf("       ########                         \n");
            break;
        case 4:
         printf("\n\n\n");
         printf("               0    0    $#     #     #¢ \n");
         printf("           #######  0     #¢   #   ø#   \n");
         printf("          ##    ø##0#      oø  ø  øo    \n");
         printf("          #7  0       0 1   1    1o\n");
         printf("       #######   0          1o###ø\n");
         printf("       #######           1     \n");
         printf("     o#########ø                  o$¢  \n");
         printf("   ###=############          ¢  1ø   1##\n");
         printf("  ##########=#######o       1$   #      \n");
         printf(" ###################       #    o#     \n");
         printf(" ####################     ##           \n");
         printf("  #############=#####                   \n");
         printf("   ################                    \n");
         printf("     ##=##########                      \n");
         printf("       ########                         \n");
        break;
        case 5:
            printf("\n\n\n");
            printf("                       $#     #     #¢ \n");
            printf("                 #¢   #   ø#   \n");
            printf("              oø  ø  øo    \n");
            printf("                   1   1    1o\n");
            printf("       #######             1o###ø\n");
            printf("       #####--##          1     \n");
            printf("     o#####   ####ø                  o$¢  \n");
            printf("   #####=## ##  ######          ¢  1ø   1##\n");
            printf("  ##### ###### ######o       1$   #      \n");
            printf(" ##-########=#########       #    o#     \n");
            printf(" #####= ##### ### #######     ##           \n");
            printf("  ######=#=###########                   \n");
            printf("   #### ############                    \n");
            printf("     ####=#####=###                      \n");
            printf("       ##### ###                         \n");
        break;
        case 6:
            printf("░░░░▄▄▄▄▀▀▀▀▀▀▀▀▄▄▄▄▄▄\n");
            printf("░░░░█░░░░▒▒▒▒▒▒▒▒▒▒▒▒░░▀▀▄\n");
            printf("░░█░░░▒▒▒▒▒▒░░░░░░░░▒▒▒░░█\n");
            printf("░░█░░░░░░▄██▀▄▄░░░░░▄▄▄░░░█\n");
            printf("░▀▒▄▄▄▒░█▀▀▀▀▄▄█░░░██▄▄█░░░█\n");
            printf("█▒█▒▄░▀▄▄▄▀░░░░░░░░█░░░▒▒▒▒▒█\n");
            printf("█▒█░█▀▄▄░░░░░█▀░░░░▀▄░░▄▀▀▀▄▒█\n");
            printf("░█▀▄░█▄░█▀▄▄░▀░▀▀░▄▄▀░░░░█░░█\n");
            printf("░░█░░▀▄▀█▄▄░█▀▀▀▄▄▄▄▀▀█▀██░█\n");
            printf("░░░█░░██░░▀█▄▄▄█▄▄█▄████░█\n");
            printf("░░░░█░░░▀▀▄░█░░░█░███████░█\n");
            printf("░░░░░▀▄░░░▀▀▄▄▄█▄█▄█▄█▄▀░░█\n");
            printf("░░░░░░░▀▄▄░▒▒▒▒░░░░░░░░░░█\n");
            printf("░░░░░░░░░░▀▀▄▄░▒▒▒▒▒▒▒▒▒▒░█\n");
            printf("░░░░░░░░░░░░░░▀▄▄▄▄▄░░░░░█\n");
            break;
    }
}
// Função para inicializar o tabuleiro 
void inicializador(char tabuleiro[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = '0';
        }
    }

    // Srand foi adicionado para gerar minas aleatórias 
    srand(time(NULL));

    // Minas sendo adicionadas ao tabuleiro 
    int minas_novas = 0;
    while (minas_novas < MINAS) {
        int linha = rand() % LINHAS;
        int colunas = rand() % COLUNAS;

        // If usado para executar minas em posições diferentes 
        if (tabuleiro[linha][colunas] != '+') {
            tabuleiro[linha][colunas] = '+';
            minas_novas++;
        }
    }  
}

// Função para contar quantas minas estão ao redor de uma célula 
int contarMinas(char tabuleiro[LINHAS][COLUNAS], int linha, int coluna) {
    int minasAoRedor = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int novaLinha = linha + i;
            int novaColuna = coluna + j;
            if (novaLinha >= 0 && novaLinha < LINHAS && novaColuna >= 0 && novaColuna < COLUNAS) {
                if (tabuleiro[novaLinha][novaColuna] == '+') {
                    minasAoRedor++;
                }
            }
        }
    }
    return minasAoRedor;
}

// Função para imprimir o tabuleiro 
void imprimirTabuleiro(char tabuleiro[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("  %c", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Tabuleiro visível
void tabuleirovisivel() {
    printf("       0");
      for (int i =1; i <5;i++){
       printf("         %d", i);
      }
       printf("\n");

     for (int i = 0; i < LINHAS; i++) {
            for (int j = 0; j < COLUNAS; j++) {
                printf("     +---+");
            }

            printf("\n");
            for (int j = 0; j < COLUNAS; j++) {


                if (tab[i][j].aberto == 1) {  // Se a célula foi marcada pelo usuário
                    printf("     | %d |", tab[i][j].lados); // Mostra o número de minas
                } else {
                    printf("     | - |");  // Célula ainda não escolhida
                }
            }
            printf(" %d", i);
            printf("\n");
            for (int j = 0; j < COLUNAS; j++) {
                printf("     +---+");
            }
            printf("\n");
        }

}


// Função para exibir a barra de progresso 
void exibir_barra_progresso(int progresso, int total) {
    int largura = 50; // Largura da barra de progresso
    int progresso_maximo = largura * progresso / total;

    printf("[");

// For usado para criar a barra
    for (int i = 0; i < largura; i++) {
        if (i < progresso_maximo) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("] %d%%\r", progresso * 100 / total);
    fflush(stdout); // Vai exibir a barra 
}

int main() {
    int stagios = 6;
    int contando = 3; 
    int linha, coluna;
    char continua;
    int progresso = 0; // Inicializa fora do loop para manter o progresso acumulado

    printf("\n                   BⷡEͤMͫ VͮIͥNⷫDͩOͦ\n\n");
    printf("      ███╗░░░███╗ ██╗ ███╗░░██╗ ███████╗ ░██████╗\n");
    printf("      ████╗░████║ ██║ ████╗░██║ ██╔════╝ ██╔════╝\n");
    printf("      ██╔████╔██║ ██║ ██╔██╗██║ █████╗░░ ╚█████╗░\n");
    printf("      ██║╚██╔╝██║ ██║ ██║╚████║ ██╔══╝░░ ░╚═══██╗\n");
    printf("      ██║░╚═╝░██║ ██║ ██║░╚███║ ███████╗ ██████╔╝\n");
    printf("      ╚═╝░░░░░╚═╝ ╚═╝ ╚═╝░░╚══╝ ╚══════╝ ╚═════╝░\n");
    printf("\n\n");


    char tabuleiro[LINHAS][COLUNAS];
    int total = 10;  // O total será 10 porque cada marcação correta vale 10%

    // Inicializa o tabuleiro
    inicializador(tabuleiro);
    int jogorodando = 1;
    while (jogorodando) {
        tabuleirovisivel();

        printf("\n\nDigite a coordenada da linha e da coluna, (0 a 4):\n");
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha >= LINHAS || coluna < 0 || coluna >= COLUNAS) {
            printf("Valor inválido\n");
            jogorodando = 0;
            continue;
        }

        // Verifica se a posição tem mina
        if (tabuleiro[linha][coluna] == '+') {
            for (int i = contando; i >= 0; i--) {
        bomba(i);

        sleep(1); // Espera 1 segundo
            }
            for (int i = 0; i < stagios; ++i) {
        explosao(i + 1);

    sleep(1);
    }
    clearScreen();
    printf("BOMBA EXPLODIU!\nVOCÊ PERDEU TUDO!\n");
            imprimirTabuleiro(tabuleiro);
            return 0;

        } else {
            int minasAoRedor = contarMinas(tabuleiro, linha, coluna);

            // atualiza o tab array
            tab[linha][coluna].lados = minasAoRedor;
            if (!tab[linha][coluna].aberto) { // so incrementa se nao for marcado antes 


            tabuleiro[linha][coluna] = minasAoRedor + '0';  // Armazena a quantidade de minas ao redor
            printf("Minas ao redor: %d\n", minasAoRedor);

            // Marcar a célula como aberta
            tab[linha][coluna].aberto = 1;  // A célula foi escolhida pelo jogador

            // Incrementa o progresso a cada célula marcada corretamente
            progresso += 1;

            // Exibe a barra de progresso com o novo valor de progresso
            exibir_barra_progresso(progresso, total);
            } else {
                printf("Está cedula ja foi escolhida\n");
                exibir_barra_progresso(progresso, total);
            }
        } 

        // Verifica se o jogador atingiu 100% de progresso
        if (progresso == total) {
            printf("\nParabéns! Você venceu!\n");
            return 0;
        }

        printf("\n\nDeseja continuar? (s/n): \n");
        scanf(" %c", &continua);
        if (continua == 'n') {
            printf("\nObrigado por jogar!!!\n");
            return 0;
        }
    }

    return 0;
}
