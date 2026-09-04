#include <iostream>
#include <algorithm>
using namespace std;

void printArray(const char* name, const int arr[], int size);
void MAXM(const int A[], int B[], int a, int b);
int main() {
    setlocale(LC_ALL, "Russian");
    const int k = 6;
    int Y[k]{ 2,5,0,5,-1,6 };
    const int l = 4;
    int X[l]{ -2,0,3,1 };

    printArray("массив Y", Y, k);
    printArray("массив X", X, l);

    MAXM(X, Y,l,k);
    // вывод результата
    printArray("новый массив Y", Y, k);
}

void printArray(const char* name, const int arr[], int size) {
    cout << name << ": ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}
void MAXM(int A[], int B[],int a,int b) {
    /*
    находим максимум массива X
    int M = A[0];
    for (int i = 1; i < a; i++) {
        if (A[i] > M)
            M = A[i];
    }
    cout << "максимальный элемент массива Х:" << M << endl;
    // преобразуем массив Y (Если элемент массива Y(i) меньше максимального эл-а массива Х => Y(i)=макс +1)
    for (int i = 0; i < b; i++) {
        if (B[i] < M) B[i] = M + 1;
    }
    */
    cout << "Максимальный элемент массива X:" << max_element(A, A + a) << endl;
    // преобразуем массив Y (Если элемент массива Y(i) меньше максимального эл-а массива Х => Y(i)=макс +1)
    int M = max_element(A, A + a);
    int M = find (A, A + a, );
    for (int i = 0; i < b; i++) {
        if (B[i] < M) B[i] = M + 1;
    }
}


//14-17 января?