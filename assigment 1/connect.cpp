#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

const int ROWS = 6;
const int COLS = 6;
char board[ROWS][COLS];
char currentPlayer = 'X';

void initializeBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X';
}

void displayBoard() {
    system("cls");
    cout << "\n============ CONNECT FOUR (6x6) ============\n" << endl;
    for (int i = 0; i < ROWS; i++) {
        cout << "  ";
        for (int j = 0; j < COLS; j++) {
            cout << "[" << board[i][j] << "]";
        }
        cout << endl;
    }
    cout << "  ";
    for (int j = 0; j < COLS; j++) {
        cout << " " << (j + 1) << " ";
    }
    cout << "\n\n============================================\n" << endl;
}

bool isValidMove(int col) {
    if (col < 1 || col > COLS) return false;
    if (board[0][col - 1] != ' ') return false;
    return true;
}

void makeMove(int col, char player) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col - 1] == ' ') {
            board[i][col - 1] = player;
            break;
        }
    }
}

bool checkWin() {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c <= COLS - 4; c++) {
            if (board[r][c] != ' ' && board[r][c] == board[r][c+1] &&
                board[r][c+1] == board[r][c+2] && board[r][c+2] == board[r][c+3]) {
                return true;
            }
        }
    }
    for (int c = 0; c < COLS; c++) {
        for (int r = 0; r <= ROWS - 4; r++) {
            if (board[r][c] != ' ' && board[r][c] == board[r+1][c] &&
                board[r+1][c] == board[r+2][c] && board[r+2][c] == board[r+3][c]) {
                return true;
            }
        }
    }
    for (int r = 0; r <= ROWS - 4; r++) {
        for (int c = 0; c <= COLS - 4; c++) {
            if (board[r][c] != ' ' && board[r][c] == board[r+1][c+1] &&
                board[r+1][c+1] == board[r+2][c+2] && board[r+2][c+2] == board[r+3][c+3]) {
                return true;
            }
        }
    }
    for (int r = 3; r < ROWS; r++) {
        for (int c = 0; c <= COLS - 4; c++) {
            if (board[r][c] != ' ' && board[r][c] == board[r-1][c+1] &&
                board[r-1][c+1] == board[r-2][c+2] && board[r-2][c+2] == board[r-3][c+3]) {
                return true;
            }
        }
    }
    return false;
}

bool checkDraw() {
    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == ' ') return false;
    }
    return true;
}

int getComputerMove() {
    vector<int> valid;
    for (int c = 1; c <= COLS; c++) {
        if (isValidMove(c)) valid.push_back(c);
    }
    if (valid.empty()) return -1;
    return valid[rand() % valid.size()];
}

void playWithFriends() {
    initializeBoard();
    bool gameOver = false;
    currentPlayer = 'X';
    while (!gameOver) {
        displayBoard();
        cout << "Player " << currentPlayer << "'s turn. Enter column (1-" << COLS << "): ";
        int col;
        cin >> col;
        if (!isValidMove(col)) {
            cout << "\nInvalid move!\n";
            system("pause");
            continue;
        }
        makeMove(col, currentPlayer);
        if (checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
        } else if (checkDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
    system("pause");
}

void playWithComputer() {
    initializeBoard();
    int choice;
    char human, comp;
    system("cls");
    cout << "\n1. Play as X (go first)\n2. Play as O (computer first)\n3. Back\nChoice: ";
    cin >> choice;
    if (choice == 3) return;
    human = (choice == 1) ? 'X' : 'O';
    comp = (choice == 1) ? 'O' : 'X';
    currentPlayer = 'X';
    bool gameOver = false;
    while (!gameOver) {
        displayBoard();
        if (currentPlayer == human) {
            cout << "Your turn (" << human << "): ";
            cin >> choice;
            if (!isValidMove(choice)) {
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
            displayBoard();
            if (currentPlayer == human) cout << "You win!\n";
            else cout << "Computer wins!\n";
            gameOver = true;
        } else if (checkDraw()) {
            displayBoard();
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
        cout << "\n========== CONNECT FOUR (6x6) ==========\n\n";
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