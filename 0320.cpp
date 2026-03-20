#include <iostream>
using namespace std;

// ==================== Merge Function ====================
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
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

    delete[] L;
    delete[] R;
}

// ==================== Merge Sort ====================
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// ==================== Binary Search ====================
int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;
    }

    int mid = (left + right) / 2;

    if (arr[mid] == target) {
        return mid;
    } else if (target < arr[mid]) {
        return binarySearch(arr, left, mid - 1, target);
    } else {
        return binarySearch(arr, mid + 1, right, target);
    }
}

// ==================== 顯示陣列 ====================
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ==================== 主程式 ====================
int main() {
    int n;

    cout << "請輸入陣列元素個數: ";
    cin >> n;

    int* arr = new int[n];

    cout << "請輸入 " << n << " 個整數: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\n原始陣列: ";
    displayArray(arr, n);

    // Merge Sort
    mergeSort(arr, 0, n - 1);

    cout << "排序後陣列 (Merge Sort): ";
    displayArray(arr, n);
    cout << "Merge Sort 時間複雜度: O(n log n)" << endl;
    cout << "Recurrence: T(n) = 2T(n/2) + n" << endl;

    // Binary Search
    int target;
    cout << "\n請輸入要搜尋的數字: ";
    cin >> target;

    int index = binarySearch(arr, 0, n - 1, target);

    if (index != -1) {
        cout << "找到數字 " << target << "，位置索引為: " << index << endl;
    } else {
        cout << "找不到數字 " << target << endl;
    }

    cout << "Binary Search 時間複雜度: O(log n)" << endl;
    cout << "Recurrence: T(n) = T(n/2) + 1" << endl;

    delete[] arr;
    return 0;
}
