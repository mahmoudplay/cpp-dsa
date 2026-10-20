#include <iostream>

using namespace std;

void Insert(int arr[], int &arr_size){
    int index, num;
    cout << "Enter the index: ";
    cin >> index;
    cout << endl;

    if (index <= 0 || index > arr_size) {
        cout << "Invalid number" << endl;
        return;
    }

    cout << "Enter the number: ";
    cin >> num;
    cout << endl;


    for(int i = arr_size; i>index - 1; i--){
        arr[i] = arr[i-1];
    }

    arr[index] = num;
    arr_size++;

    cout << "Done!" << endl;
}

void Remove(int arr[], int &arr_size){
    int index, num;
    cout << "Enter the index: ";
    cin >> index;
    cout << endl;

    if (index <= 0 || index > arr_size) {
        cout << "Invalid number" << endl;
        return;
    }
    
    int newArr[arr_size];

    for(int i = 0; i<arr_size; i++){
        if(i == index - 1){
            continue;
        }

        newArr[i] = arr[i];
    }

    arr = newArr;
    arr_size--;

    cout << "Done!" << endl;
}

void Display(int arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
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
        cout << "Select your opration:\n[1] Insert number\n[2] Remove number\n[3] Display\n[4] Exit\n\nYour choice: ";
        cin >> choice;

        cout << "\n";
        
        switch (choice) {
        case 1:
            Insert(arr1, size);
            break;
        case 2:
            Remove(arr1, size);
            break;
        case 3:
            Display(arr1, size);
            break;
        case 4:
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