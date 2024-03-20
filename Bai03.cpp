#include <iostream>
#include <vector>

using namespace std;

// Hàm in ra mảng
void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Thuật toán sắp xếp chèn (Insertion Sort)
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Thuật toán sắp xếp chọn (Selection Sort)
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Thuật toán sắp xếp nổi bọt (Bubble Sort)
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Hàm hỗ trợ Merge Sort: hợp nhất hai mảng con arr[left...mid] và arr[mid+1...right]
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Thuật toán sắp xếp trộn (Merge Sort)
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Nhap " << n << " so nguyen: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Sắp xếp và in ra mảng sử dụng các thuật toán
    cout << "Mang truoc khi sap xep: ";
    printArray(arr);

    // Sử dụng Insertion Sort
    vector<int> arr_insertion = arr;
    insertionSort(arr_insertion);
    cout << "Mang sau khi sap xep bang Insertion Sort: ";
    printArray(arr_insertion);

    // Sử dụng Selection Sort
    vector<int> arr_selection = arr;
    selectionSort(arr_selection);
    cout << "Mang sau khi sap xep bang Selection Sort: ";
    printArray(arr_selection);

    // Sử dụng Bubble Sort
    vector<int> arr_bubble = arr;
    bubbleSort(arr_bubble);
    cout << "Mang sau khi sap xep bang Bubble Sort: ";
    printArray(arr_bubble);

    // Sử dụng Merge Sort
    vector<int> arr_merge = arr;
    mergeSort(arr_merge, 0, n - 1);
    cout << "Mang sau khi sap xep bang Merge Sort: ";
    printArray(arr_merge);

    return 0;
}
