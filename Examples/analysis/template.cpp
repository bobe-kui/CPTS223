#include <iostream>
#include "Student.h"


using namespace std;


template <typename T>
T findMax(T a[], int size)
{
    T max = a[0];
    for (int i = 1; i < size; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

// int findMax(int a[], int size){
//     int max = a[0];
//     for (int i = 1; i < size; i++){
//         if (a[i] > max){
//             max = a[i];
//         }
//     }
//     return max;
// }

// double findMaxDouble(double a[], int size){
//     double max = a[0];
//     for (int i = 1; i < size; i++){
//         if (a[i] > max){
//             max = a[i];
//         }
//     }
//     return max;
// }

int main(){

    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Max: " << findMax(a, 9) << endl;

    double b[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    cout << "Max: " << findMax(b, 6) << endl;

    Student students[] = {Student("Alice", 3.5), Student("Bob", 3.0), Student("Charlie", 3.2)};

    cout << "Max: " << findMax(students, 3) << endl;

    return 0;
}