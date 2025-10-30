#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Метод для слияния двух отсортированных массивов
vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> result;
    size_t i = 0, j = 0;
    
    // Пока есть элементы в обоих массивах
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            result.push_back(left[i++]);
        } else {
            result.push_back(right[j++]);
        }
    }
    
    // Добавляем оставшиеся элементы
    while (i < left.size()) {
        result.push_back(left[i++]);
    }
    
    while (j < right.size()) {
        result.push_back(right[j++]);
    }
    
    return result;
}

// Основной метод сортировки слиянием
vector<int> mergeSort(const vector<int>& arr) {
    // Базовый случай: массив длиной 0 или 1 уже отсортирован
    if (arr.size() <= 1) {
        return arr;
    }
    
    // Находим середину массива
    size_t mid = arr.size() / 2;
    
    // Делим массив на две части
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
    
    // Рекурсивно сортируем каждую часть
    left = mergeSort(left);
    right = mergeSort(right);
    
    // Сливаем отсортированные части
    return merge(left, right);
}

// Пример использования
int main() {
    vector<int> array = {38, 27, 43, 3, 9, 82, 10};
    
    cout << "Исходный массив: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<int> sortedArray = mergeSort(array);
    
    cout << "Отсортированный массив: ";
    for (int num : sortedArray) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}