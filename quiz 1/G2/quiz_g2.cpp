#include <iostream>

using namespace std;

// A: 6

// B: public

// C:
int main(){
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    int sum = 0;

    for (int i = 0; i < 3; i++)
    {
        sum += arr[i][3-1-i];
    }

    double avg = (double) sum / 3;

    cout << "Sum= " << sum << endl;
    cout << "Avg= " << avg << endl;
    
}