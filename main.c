#include <stdio.h>

// Definindo o tamanho do tabuleiro
#define BOARD_SIZE 8

// Função para inicializar o tabuleiro com peças padrão
void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int row, col;
    char pieces[] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
    
    for (row = 0; row < BOARD_SIZE; row++) {
        for (col = 0; col < BOARD_SIZE; col++) {
            if (row == 0 || row == BOARD_SIZE - 1) {
                board[row][col] = pieces[col];
            } else if (row == 1 || row == BOARD_SIZE - 2) {
                board[row][col] = 'P';
            } else {
                board[row][col] = ' ';
            }
        }
    }
}

// Função para imprimir o tabuleiro
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int row, col;
    printf("\n  a b c d e f g h\n");
    for (row = 0; row < BOARD_SIZE; row++) {
        printf("%d ", 8 - row);
        for (col = 0; col < BOARD_SIZE; col++) { 
            printf("%c ", board[row][col]);
        }
        printf("%d\n", 8 - row);
    }
    printf("  a b c d e f g h\n\n");
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];

    // Inicializando o tabuleiro
    initialize_board(board);

    // Imprimindo o tabuleiro
    print_board(board);

    return 0;
}

