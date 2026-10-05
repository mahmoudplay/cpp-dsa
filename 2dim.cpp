#include <iostream>

using namespace std;

class Two_dim_array {
    private:
        int arr_cols;
        int arr_rows;
        int arr[100][100];

    public:
        Two_dim_array(int ar[][100], int cols, int rows) {
            arr_cols = cols;
            arr_rows = rows;

            for (int i = 0; i < arr_rows; i++)
            {
                for (int j = 0; j < arr_cols; j++)
                {
                    arr[i][j] = ar[i][j];
                }
            }
        }

        void Sum(){
            int sum = 0;

            for (int i = 0; i < arr_rows; i++)
            {
                for (int j = 0; j < arr_cols; j++)
                {
                    sum += arr[i][j];
                }
            }

            cout << "The sum is " << sum << endl;
        }

        void Avg(){
            int sum = 0;

            for (int i = 0; i < arr_rows; i++)
            {
                for (int j = 0; j < arr_cols; j++)
                {
                    sum += arr[i][j];
                }
            }

            int avg = sum / (arr_rows * arr_cols);

            cout << "The avg is " << avg << endl;
        }

        void Sort_Asc(){
            for (int i = 0; i < arr_rows * arr_cols - 1; i++){
                int minIndex = i;

                for (int j = i + 1; j < arr_rows * arr_cols; j++)
                {
                    if (arr[j / arr_cols][j % arr_cols] < arr[minIndex / arr_cols][minIndex % arr_cols])
                    {
                        minIndex = j;
                    }
                }

                int r1 = i / arr_cols;
                int c1 = i % arr_cols;
                int r2 = minIndex / arr_cols;
                int c2 = minIndex % arr_cols;

                int temp = arr[r1][c1];
                arr[r1][c1] = arr[r2][c2];
                arr[r2][c2] = temp;
            }

            Display();
        }

        void Sort_Des(){
            for (int i = 0; i < arr_rows * arr_cols - 1; i++){
                int maxIndex = i;

                for (int j = i + 1; j < arr_rows * arr_cols; j++)
                {
                    if (arr[j / arr_cols][j % arr_cols] > arr[maxIndex / arr_cols][maxIndex % arr_cols])
                    {
                        maxIndex = j;
                    }
                }

                int r1 = i / arr_cols;
                int c1 = i % arr_cols;
                int r2 = maxIndex / arr_cols;
                int c2 = maxIndex % arr_cols;

                int temp = arr[r1][c1];
                arr[r1][c1] = arr[r2][c2];
                arr[r2][c2] = temp;
            }

            Display();
        }

        void Max(){
            int max = arr[0][0];

            for (int i = 0; i < arr_rows; i++)
            {
                for (int j = 0; j < arr_cols; j++)
                {
                    if (max < arr[i][j]){
                        max = arr[i][j];
                    }
                }
            }

            cout << "The max number is " << max << endl;
        }

        void Min(){
            int min = arr[0][0];

            for (int i = 0; i < arr_rows; i++)
            {
                for (int j = 0; j < arr_cols; j++)
                {
                    if (min > arr[i][j]){
                        min = arr[i][j];
                    }
                }
            }

            cout << "The min number is " << min << endl;
        }

        void Display() {
            for (int i = 0; i < arr_rows; i++) {
                for (int j = 0; j < arr_cols; j++) {
                    cout << arr[i][j] << " ";
                }

                cout << endl;
            }
        }
};

int main() {
    int rows;
    int cols;
    int choice;
    int arr2[100][100];

    cout << "Enter array's rows number: ";
    cin >> rows;

    cout << "Enter array's cols number: ";
    cin >> cols;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element number [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> arr2[i][j];
        }
    }

    Two_dim_array twoArr(arr2, cols, rows);

    bool lop = true;

    while (lop)
    {
        cout << "Select your opration:\n[1] Sum\n[2] Average\n[3] Sort Asc\n[4] Sort Des\n[5] Max value\n[6] Min value\n[7] Display\n[8] Exit\n\nYour choice: ";
        cin >> choice;

        cout << "\n";

        switch (choice){

        case 1:
            twoArr.Sum();
            break;
        case 2:
            twoArr.Avg();
            break;
        case 3:
            twoArr.Sort_Asc();
            break;
        case 4:
            twoArr.Sort_Des();
            break;
        case 5:
            twoArr.Max();
            break;
        case 6:
            twoArr.Min();
            break;
        case 7:
            twoArr.Display();
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
