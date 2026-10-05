#include <iostream>

using namespace std;

class Matrix {
    private:
        int rows;
        int cols;
        int arr[100][100];

    public:
        Matrix() {
            rows = 0;
            cols = 0;
        }

        Matrix(int ar[][100], int r, int c) {
            rows = r;
            cols = c;

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    arr[i][j] = ar[i][j];
                }
            }
        }

        void Set(int ar[][100], int r, int c) {
            rows = r;
            cols = c;

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    arr[i][j] = ar[i][j];
                }
            }
        }

        int Get_rows() {
            return rows;
        }

        int Get_cols() {
            return cols;
        }

        void Display() {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << arr[i][j] << "\t";
                }

                cout << endl;
            }
        }

        void Add(Matrix b) {
            if (rows != b.Get_rows() || cols != b.Get_cols()) {
                cout << "Matrices must have the same dimensions to be added" << endl;
                return;
            }

            Matrix res;
            int resArr[100][100];

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    resArr[i][j] = arr[i][j] + b.arr[i][j];
                }
            }

            res.Set(resArr, rows, cols);

            cout << "The sum of the matrices is:" << endl;
            res.Display();
        }

        void Multiply(Matrix b) {
            if (cols != b.Get_rows()) {
                cout << "The cols of the first matrix must equal the rows of the second one" << endl;
                return;
            }

            Matrix res;
            int resArr[100][100];

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < b.Get_cols(); j++)
                {
                    int sum = 0;

                    for (int k = 0; k < cols; k++)
                    {
                        sum += arr[i][k] * b.arr[k][j];
                    }

                    resArr[i][j] = sum;
                }
            }

            res.Set(resArr, rows, b.Get_cols());

            cout << "The product of the matrices is:" << endl;
            res.Display();
        }
};

void Read(int ar[][100], int rows, int cols, const char* name) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter " << name << " element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> ar[i][j];
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;
    int ar1[100][100];
    int ar2[100][100];

    cout << "Enter the rows number of the first matrix: ";
    cin >> rows1;

    cout << "Enter the cols number of the first matrix: ";
    cin >> cols1;

    Read(ar1, rows1, cols1, "the first matrix's");

    cout << "\n";

    cout << "Enter the rows number of the second matrix: ";
    cin >> rows2;

    cout << "Enter the cols number of the second matrix: ";
    cin >> cols2;

    Read(ar2, rows2, cols2, "the second matrix's");

    Matrix m1(ar1, rows1, cols1);
    Matrix m2(ar2, rows2, cols2);

    int choice;
    bool lop = true;

    while (lop)
    {
        cout << "Select your opration:\n[1] Display the first matrix\n[2] Display the second matrix\n[3] Addition\n[4] Multiplication\n[5] Exit\n\nYour choice: ";
        cin >> choice;

        cout << "\n";

        switch (choice){

        case 1:
            cout << "The first matrix is:" << endl;
            m1.Display();
            break;
        case 2:
            cout << "The second matrix is:" << endl;
            m2.Display();
            break;
        case 3:
            m1.Add(m2);
            break;
        case 4:
            m1.Multiply(m2);
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
