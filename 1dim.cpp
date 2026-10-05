#include <iostream>

using namespace std;

class One_dim_arr {
    private:
        int arr_size;
        int* arr = new int[arr_size];

    public:
        One_dim_arr(int ar[], int size) {
            arr_size = size;
            for (int i = 0; i < size; i++)
                arr[i] = ar[i];
        }

        void Sum(){
            int sum = 0;

            for (int i = 0; i < arr_size; i++)
            {
                sum += arr[i];
            }

            cout << "The sum is " << sum << endl;
        }

        void Avg(){
            int sum = 0;

            for (int i = 0; i < arr_size; i++)
            {
                sum += arr[i];
            }

            int avg = sum / arr_size;

            cout << "The avg is " << avg << endl;
        }

        void Sort_Asc(){
            for (int i = 0; i < arr_size - 1; i++){
                int minIndex = i;

                for (int j = i + 1; j < arr_size; j++)
                {
                    if (arr[j] < arr[minIndex])
                    {
                        minIndex = j;
                    }
                }

                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;            
            }

            cout << "Sort asc: ";
            Display();
        }

        void Sort_Des(){
            for (int i = 0; i < arr_size - 1; i++){
                int minIndex = i;

                for (int j = i + 1; j < arr_size; j++)
                {
                    if (arr[j] > arr[minIndex])
                    {
                        minIndex = j;
                    }
                }

                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;            
            }

            cout << "Sort des: ";
            Display();
        }

        void Max(){
            int max = arr[0];

            for (int i = 0; i < arr_size; i++) {
                if(max < arr[i]){
                    max = arr[i];
                }
            }

            cout << "The max number is " << max << endl;
        }

        void Min(){
            int min = arr[0];

            for (int i = 0; i < arr_size; i++) {
                if(min > arr[i]){
                    min = arr[i];
                }
            }

            cout << "The min number is " << min << endl;
        }

        void Display() {
            for (int i = 0; i < arr_size; i++) {
                cout << arr[i] << " ";
            }

            cout << endl;
        }
};

int main() {
    int size;
    int choice;
    int* arr1 = new int[size];
    cout << "Enter array's size: ";
    cin >> size;
    
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element number [" << i + 1 << "]: ";
        cin >> arr1[i];
    }

    One_dim_arr oneArr(arr1, size);

    bool lop = true;

    while (lop)
    {
        cout << "Select your opration:\n[1] Sum\n[2] Average\n[3] Sort Asc\n[4] Sort Des\n[5] Max value\n[6] Min value\n[7] Display\n[8] Exit\n\nYour choice: ";
        cin >> choice;

        cout << "\n";
        
        switch (choice){

        case 1:
            oneArr.Sum();
            break;
        case 2:
            oneArr.Avg();
            break;
        case 3:
            oneArr.Sort_Asc();
            break;
        case 4:
            oneArr.Sort_Des();
            break;
        case 5:
            oneArr.Max();
            break;
        case 6:
            oneArr.Min();
            break;
        case 7:
            oneArr.Display();
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
