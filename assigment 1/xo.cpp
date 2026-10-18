#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

char currentPlayer = 'X';

void drawBoard() {
    system("cls");
    cout << "\n========== TIC TAC TOE (X.O) ==========" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "  ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "  --+---+--" << endl;
    }
    cout << "\n========================================\n" << endl;
}

void resetBoard() {
    char positions[9] = {'1','2','3','4','5','6','7','8','9'};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = positions[i*3 + j];
        }
    }
    currentPlayer = 'X';
}

bool isEmpty(int position) {
    if (position < 1 || position > 9) return false;
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    return (board[row][col] != 'X' && board[row][col] != 'O');
}

void makeMove(int position, char player) {
    if (position >= 1 && position <= 9) {
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;
        board[row][col] = player;
    }
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
    }
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

int getComputerMove() {
    vector<int> empty;
    for (int pos = 1; pos <= 9; pos++) {
        if (isEmpty(pos)) empty.push_back(pos);
    }
    if (empty.empty()) return -1;
    return empty[rand() % empty.size()];
}

void playWithFriends() {
    resetBoard();
    bool gameOver = false;
    currentPlayer = 'X';
    while (!gameOver) {
        drawBoard();
        cout << "Player " << currentPlayer << "'s turn. Enter position (1-9): ";
        int choice;
        cin >> choice;
        if (!isEmpty(choice)) {
            cout << "\nInvalid move!\n";
            system("pause");
            continue;
        }
        makeMove(choice, currentPlayer);
        if (checkWin()) {
            drawBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
        } else if (checkDraw()) {
            drawBoard();
            cout << "It's a draw!\n";
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
    system("pause");
}

void playWithComputer() {
    resetBoard();
    int choice;
    char human, comp;
    system("cls");
    cout << "\n========== PLAY WITH COMPUTER ==========\n\n";
    cout << "1. Play as X (You go first)\n";
    cout << "2. Play as O (Computer goes first)\n";
    cout << "3. Back to main menu\n";
    cout << "\nYour choice: ";
    cin >> choice;
    if (choice == 3) return;
    if (choice == 1) {
        human = 'X'; comp = 'O';
    } else {
        human = 'O'; comp = 'X';
    }
    currentPlayer = 'X';
    bool gameOver = false;
    while (!gameOver) {
        drawBoard();
        if (currentPlayer == human) {
            cout << "Your turn (" << human << "): ";
            cin >> choice;
            if (!isEmpty(choice)) {
                cout << "\nInvalid move!\n";
                system("pause");
                continue;
            }
            makeMove(choice, currentPlayer);
        } else {
            cout << "Computer's turn (" << comp << ")...";
            int mv = getComputerMove();
            if (mv != -1) makeMove(mv, currentPlayer);
            system("pause");
        }
        if (checkWin()) {
            drawBoard();
            if (currentPlayer == human) {
                cout << "Congratulations! You win!\n";
            } else {
                cout << "Computer wins! Better luck next time.\n";
            }
            gameOver = true;
        } else if (checkDraw()) {
            drawBoard();
            cout << "It's a draw!\n";
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
    system("pause");
}

int main() {
    srand(time(0));
    int choice;
    while (true) {
        system("cls");
        cout << "\n========== X.O GAME ==========\n\n";
        cout << "1. Play with his friends\n";
        cout << "2. Play with his Computer\n";
        cout << "3. Exit\n";
        cout << "\nYour choice: ";
        cin >> choice;
        switch (choice) {
            case 1: playWithFriends(); break;
            case 2: playWithComputer(); break;
            case 3: cout << "\nThanks for playing!\n"; return 0;
            default: cout << "\nInvalid choice!\n"; system("pause"); break;
        }
    }
    return 0;
}