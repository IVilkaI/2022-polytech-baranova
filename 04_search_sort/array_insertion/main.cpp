#include <iostream>

int N = 5;
int* A = (int*)(malloc(N * sizeof(int)));

void insert(int x, int p, int* arr, int &n) {
    arr = (int*)(realloc(arr, (n + 1) * sizeof(int)));
    for (int i = n; i > p; i--) {
        arr[i] = arr[i - 1];
    }
    arr[p] = x;
    n += 1;
}

void print(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    for (int i = 0; i < N; i++) {
        A[i] = i;
    }

    print(A, N);
    insert(99, 3, A, N);
    print(A, N);
    return 0;
}