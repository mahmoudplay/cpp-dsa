#include <iostream>

using namespace std;

void ReadMatrix(int ar[][100], int rows, int cols, const char* name) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter " << name << " element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> ar[i][j];
        }
    }
}

void DisplayMatrix(int ar[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << ar[i][j] << "\t";
        }
        cout << endl;
    }
}

void AddMatrix(int a[][100], int rows1, int cols1, int b[][100], int rows2, int cols2) {
    if (rows1 != rows2 || cols1 != cols2) {
        cout << "Matrices must have the same dimensions to be added" << endl;
        return;
    }

    int resArr[100][100];
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            resArr[i][j] = a[i][j] + b[i][j];
        }
    }

    cout << "The sum of the matrices is:" << endl;
    DisplayMatrix(resArr, rows1, cols1);
}

void MultiplyMatrix(int a[][100], int rows1, int cols1, int b[][100], int rows2, int cols2) {
    if (cols1 != rows2) {
        cout << "The cols of the first matrix must equal the rows of the second one" << endl;
        return;
    }

    int resArr[100][100];
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            int sum = 0;
            for (int k = 0; k < cols1; k++) {
                sum += a[i][k] * b[k][j];
            }
            resArr[i][j] = sum;
        }
    }

    cout << "The product of the matrices is:" << endl;
    DisplayMatrix(resArr, rows1, cols2);
}

int main() {
    int rows1, cols1, rows2, cols2;
    int ar1[100][100];
    int ar2[100][100];

    cout << "Enter the rows number of the first matrix: ";
    cin >> rows1;

    cout << "Enter the cols number of the first matrix: ";
    cin >> cols1;

    ReadMatrix(ar1, rows1, cols1, "the first matrix's");

    cout << "\n";

    cout << "Enter the rows number of the second matrix: ";
    cin >> rows2;

    cout << "Enter the cols number of the second matrix: ";
    cin >> cols2;

    ReadMatrix(ar2, rows2, cols2, "the second matrix's");

    int choice;
    bool lop = true;

    while (lop) {
        cout << "Select your opration:\n[1] Display the first matrix\n[2] Display the second matrix\n[3] Addition\n[4] Multiplication\n[5] Exit\n\nYour choice: ";
        cin >> choice;

        cout << "\n";

        switch (choice) {
        case 1:
            cout << "The first matrix is:" << endl;
            DisplayMatrix(ar1, rows1, cols1);
            break;
        case 2:
            cout << "The second matrix is:" << endl;
            DisplayMatrix(ar2, rows2, cols2);
            break;
        case 3:
            AddMatrix(ar1, rows1, cols1, ar2, rows2, cols2);
            break;
        case 4:
            MultiplyMatrix(ar1, rows1, cols1, ar2, rows2, cols2);
            break;
        case 5:
            cout << "Thanks for using" << endl;
            lop = false;
            break;
        default:
            cout << "error" << endl;
            break;
        }

        cout << "\n\n";
    }

    return 0;
}