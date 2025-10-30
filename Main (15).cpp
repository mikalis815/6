#include <iostream>
#include <vector>

using namespace std;

/**
 * Рекурсивный метод интерполирующего поиска
 */
int interpolationSearch(vector<int>& arr, int lo, int hi, int x) {
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        // Вычисляем позицию с помощью интерполяционной формулы
        int pos = lo + (((hi - lo) * (x - arr[lo])) / (arr[hi] - arr[lo]));
        
        // Если элемент найден
        if (arr[pos] == x) {
            return pos;
        }
        
        // Если x больше, x находится в правом подмассиве
        if (arr[pos] < x) {
            return interpolationSearch(arr, pos + 1, hi, x);
        }
        
        // Если x меньше, x находится в левом подмассиве
        if (arr[pos] > x) {
            return interpolationSearch(arr, lo, pos - 1, x);
        }
    }
    return -1;  // Элемент не найден
}

/**
 * Итеративный метод интерполирующего поиска
 */
int interpolationSearchIterative(vector<int>& arr, int x) {
    int lo = 0;
    int hi = arr.size() - 1;
    
    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        // Вычисляем позицию с помощью интерполяционной формулы
        int pos = lo + (((hi - lo) * (x - arr[lo])) / (arr[hi] - arr[lo]));
        
        // Если элемент найден
        if (arr[pos] == x) {
            return pos;
        }
        
        // Если x больше, ищем в правой части
        if (arr[pos] < x) {
            lo = pos + 1;
        } 
        // Если x меньше, ищем в левой части
        else {
            hi = pos - 1;
        }
    }
    return -1;  // Элемент не найден
}

int main() {
    vector<int> arr = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int target = 18;
    
    // Рекурсивный поиск
    int result = interpolationSearch(arr, 0, arr.size() - 1, target);
    
    if (result != -1) {
        cout << "Элемент найден на позиции: " << result << endl;
    } else {
        cout << "Элемент не найден" << endl;
    }
    
    // Итеративный поиск
    int result2 = interpolationSearchIterative(arr, target);
    cout << "Итеративный поиск: " << result2 << endl;
    
    return 0;
}