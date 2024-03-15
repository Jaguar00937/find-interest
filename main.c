#include <stdio.h>

char board[3][3];

// Function to print the Tic Tac Toe board
void print_board() {
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c\n", board[i][0], board[i][1], board[i][2]);
        if (i != 2) printf("---|---|---\n");
    }
}

// Function to check if a player has won
int check_winner(char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return 1;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return 1;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return 1;
    return 0;
}

// Function to check if the board is full
int is_board_full() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

// Function to play the game
void play_game() {
    char current_player = 'X';
    int row, col;

    // Initialize the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    while (1) {
        printf("\nCurrent board:\n");
        print_board();

        // Input move
        printf("Player %c, enter your move (row and column): ", current_player);
        scanf("%d %d", &row, &col);

        // Check if the move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        // Update the board with the move
        board[row][col] = current_player;

        // Check for a winner
        if (check_winner(current_player)) {
            printf("\nCurrent board:\n");
            print_board();
            printf("Player %c wins!\n", current_player);
            break;
        }

        // Check for a draw
        if (is_board_full()) {
            printf("\nCurrent board:\n");
            print_board();
            printf("It's a draw!\n");
            break;
        }

        // Switch player
        current_player = (current_player == 'X') ? 'O' : 'X';
    }
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    play_game();
    return 0;
}
