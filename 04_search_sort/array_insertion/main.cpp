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

int search_position(int x, const int* arr, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] >= x) {
            return i;
        }
    }
    return n;
}

void insert_sorted(int x, int* arr, int &n) {
    insert(x, search_position(x, arr, n), arr, n);
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
    std::cout << "insert function" << std::endl;
    std::cout << "Initial array: " << std::endl;
    print(A, N);
    insert(99, 4, A, N);
    std::cout << "Array after insertion: " << std::endl;
    print(A, N);
    std::cout << std::endl;

    std::cout << "search_position function" << std::endl;
    std::cout << "Initial array: " << std::endl;
    for (int i = 0; i < N; i++) {
        A[i] = i * 2;
    }
    print(A, N);
    std::cout << "99 must be on position " << search_position(99, A, N) << std::endl;
    std::cout << "3 must be on position " << search_position(3, A, N) << std::endl;
    std::cout << std::endl;

    std::cout << "insert_sorted function" << std::endl;
    std::cout << "Initial array: " << std::endl;
    for (int i = 0; i < N; i++) {
        A[i] = i * 2;
    }
    print(A, N);
    insert_sorted(99, A, N);
    std::cout << "Array after insertion: " << std::endl;
    print(A, N);
    insert_sorted(3, A, N);
    std::cout << "Array after insertion: " << std::endl;
    print(A, N);
    return 0;
}