#include <iostream>

using namespace std;

void Sum2D(int arr[100][100], int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
    }
    cout << "The sum is " << sum << endl;
}

void Avg2D(int arr[100][100], int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
    }
    int avg = sum / (rows * cols);
    cout << "The avg is " << avg << endl;
}

void Display2D(int arr[100][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void Sort_Asc2D(int arr[100][100], int rows, int cols) {
    for (int i = 0; i < rows * cols - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < rows * cols; j++) {
            if (arr[j / cols][j % cols] < arr[minIndex / cols][minIndex % cols]) {
                minIndex = j;
            }
        }
        int r1 = i / cols;
        int c1 = i % cols;
        int r2 = minIndex / cols;
        int c2 = minIndex % cols;
        int temp = arr[r1][c1];
        arr[r1][c1] = arr[r2][c2];
        arr[r2][c2] = temp;
    }
    Display2D(arr, rows, cols);
}

void Sort_Des2D(int arr[100][100], int rows, int cols) {
    for (int i = 0; i < rows * cols - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < rows * cols; j++) {
            if (arr[j / cols][j % cols] > arr[maxIndex / cols][maxIndex % cols]) {
                maxIndex = j;
            }
        }
        int r1 = i / cols;
        int c1 = i % cols;
        int r2 = maxIndex / cols;
        int c2 = maxIndex % cols;
        int temp = arr[r1][c1];
        arr[r1][c1] = arr[r2][c2];
        arr[r2][c2] = temp;
    }
    Display2D(arr, rows, cols);
}

void Max2D(int arr[100][100], int rows, int cols) {
    int max = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (max < arr[i][j]) {
                max = arr[i][j];
            }
        }
    }
    cout << "The max number is " << max << endl;
}

void Min2D(int arr[100][100], int rows, int cols) {
    int min = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (min > arr[i][j]) {
                min = arr[i][j];
            }
        }
    }
    cout << "The min number is " << min << endl;
}

int main() {
    int rows;
    int cols;
    int choice;
    int arr2[100][100];

    cout << "Enter array's rows number: ";
    cin >> rows;

    cout << "Enter array's cols number: ";
    cin >> cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element number [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> arr2[i][j];
        }
    }

    bool lop = true;

    while (lop) {
        cout << "Select your opration:\n[1] Sum\n[2] Average\n[3] Sort Asc\n[4] Sort Des\n[5] Max value\n[6] Min value\n[7] Display\n[8] Exit\n\nYour choice: ";
        cin >> choice;

        cout << "\n";

        switch (choice) {
        case 1:
            Sum2D(arr2, rows, cols);
            break;
        case 2:
            Avg2D(arr2, rows, cols);
            break;
        case 3:
            Sort_Asc2D(arr2, rows, cols);
            break;
        case 4:
            Sort_Des2D(arr2, rows, cols);
            break;
        case 5:
            Max2D(arr2, rows, cols);
            break;
        case 6:
            Min2D(arr2, rows, cols);
            break;
        case 7:
            Display2D(arr2, rows, cols);
            break;
        case 8:
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