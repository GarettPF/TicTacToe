#include "ttt.h"

int display_menu() {
    int choice;

    do {
        __CLS_;
        cout << "Welcome to TicTacToe" << endl;
        cout << "1. Start game" << endl;
        cout << "2. Exit" << endl;
        cin >> choice;
    } while (choice < __PLAY_GAME_ || choice > __EXIT_);

    return choice;
}

void game_loop() {
    char board[__SIZE_][__SIZE_] = {{'\0'}},
        player = 'O';
    int choice;

    while (!is_winner(board, &player)) {
        __CLS_;
        display_board(board);
        
        if (player == 'O') 
            choice = player_choice(board);
        else
            choice = computer_choice(board);
        
        board[(choice - 1) / __SIZE_][(choice - 1) % __SIZE_] = player;

        player = (player == 'O') ? 'X' : 'O';
    }

    __CLS_;
    display_board(board);
    if (player == 'F')
        cout << "No one wins" << endl;
    else
        cout << player << " wins!" << endl;

    system("pause");
    
}

int is_winner(char board[][__SIZE_], char *winner) {
    int row, col;
    char player;

    // check for rows
    for (row = 0; row < __SIZE_; ++row) {
        col = 0;
        player = (board[row][col] == '\0') ? '0' : board[row][col];

        while (board[row][col++] == player) {
            if (col == __SIZE_) {
                *winner = player;
                return 1;
            }
        }
    }

    // check for cols
    for (col = 0; col < __SIZE_; ++col) {
        row = 0;
        player = (board[row][col] == '\0') ? '0' : board[row][col];

        while (board[row++][col] == player) {
            if (row == __SIZE_) {
                *winner = player;
                return 1;
            }
        }
    }

    // check for diag TL - BR
    col = 0;
    player = (board[col][col] == '\0') ? '0' : board[col][col];

    while (board[col][col] == player) {
        col++;
        if (col == __SIZE_) {
            *winner = player;
            return 1;
        }
    }

    // check for diag BL - TR
    col = 0;
    player = (board[__SIZE_ - 1 - col][col] == '\0') ? '0' : board[__SIZE_ - 1 - col][col];

    while (board[__SIZE_ - 1 - col][col] == player) {
        col ++;
        if (col == __SIZE_) {
            *winner = player;
            return 1;
        }
    }

    // check if full and no winners
    int flag = 0;
    for (row = 0; row < __SIZE_; ++row) {
        for (col = 0; col < __SIZE_; ++col) {
            if (board[row][col] == '\0')
                flag = 1;
        }
    }
    if (flag == 0) {
        *winner = 'F';
        return 1;
    }


    return 0;
}

void display_board(char board[][__SIZE_]) {
    int entry = 1;
    cout << "-- Welcome to TicTacToe --" << endl << endl;
    
    for (int row = 0; row < __SIZE_; ++row) {
        for (int col = 0; col < __SIZE_; ++col) {
            if (board[row][col] == '\0')
                cout << " " << entry << " ";
            else
                cout << " " << board[row][col] << " ";
            
            if (col == __SIZE_ - 1)
                cout << endl;
            else
                cout << "|";
            
            entry++;
        }
        
        if (row != __SIZE_ - 1) {
            for (int col = 0; col < __SIZE_ - 1; ++col) 
                cout << "---+";
            cout << "---" << endl;
        }
    }

    cout << endl;
}

int player_choice(char board[][__SIZE_]) {
    int choice, row, col;
    do {
        cout << "Player O enter a number: ";
        cin >> choice;
    } while (choice < 1 || choice > __SIZE_ * __SIZE_);

    row = (choice - 1) / __SIZE_;
    col = (choice - 1) % __SIZE_;

    if (board[row][col] != '\0') {
        cout << choice << " is already chosen" << endl;
        choice = player_choice(board);
    }
    return choice;
}

int computer_choice(char board[][__SIZE_]) {
    int choice, row, col;
    
    choice = rand() % (__RAND_MAX_) + 1;

    row = (choice - 1) / __SIZE_;
    col = (choice - 1) % __SIZE_;

    if (board[row][col] != '\0') {
        cout << choice << " is already chosen" << endl;
        choice = computer_choice(board);
    }
    return choice;
}