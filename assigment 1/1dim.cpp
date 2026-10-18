#include <iostream>

using namespace std;

void Sum(int arr[], int arr_size) {
    int sum = 0;
    for (int i = 0; i < arr_size; i++) {
        sum += arr[i];
    }
    cout << "The sum is " << sum << endl;
}

void Avg(int arr[], int arr_size) {
    int sum = 0;
    for (int i = 0; i < arr_size; i++) {
        sum += arr[i];
    }
    int avg = sum / arr_size;
    cout << "The avg is " << avg << endl;
}

void Display(int arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Sort_Asc(int arr[], int arr_size) {
    for (int i = 0; i < arr_size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < arr_size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    cout << "Sort asc: ";
    Display(arr, arr_size);
}

void Sort_Des(int arr[], int arr_size) {
    for (int i = 0; i < arr_size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < arr_size; j++) {
            if (arr[j] > arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    cout << "Sort des: ";
    Display(arr, arr_size);
}

void Max(int arr[], int arr_size) {
    int max = arr[0];
    for (int i = 0; i < arr_size; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    cout << "The max number is " << max << endl;
}

void Min(int arr[], int arr_size) {
    int min = arr[0];
    for (int i = 0; i < arr_size; i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
    }
    cout << "The min number is " << min << endl;
}

int main() {
    int size;
    int choice;
    cout << "Enter array's size: ";
    cin >> size;
    
    int* arr1 = new int[size];
    
    for (int i = 0; i < size; i++) {
        cout << "Enter element number [" << i + 1 << "]: ";
        cin >> arr1[i];
    }

    bool lop = true;

    while (lop) {
        cout << "Select your opration:\n[1] Sum\n[2] Average\n[3] Sort Asc\n[4] Sort Des\n[5] Max value\n[6] Min value\n[7] Display\n[8] Exit\n\nYour choice: ";
        cin >> choice;

        cout << "\n";
        
        switch (choice) {
        case 1:
            Sum(arr1, size);
            break;
        case 2:
            Avg(arr1, size);
            break;
        case 3:
            Sort_Asc(arr1, size);
            break;
        case 4:
            Sort_Des(arr1, size);
            break;
        case 5:
            Max(arr1, size);
            break;
        case 6:
            Min(arr1, size);
            break;
        case 7:
            Display(arr1, size);
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
    
    delete[] arr1;
    return 0;
}