#include <iostream>
#include <vector>

using namespace std;

// Функция для преобразования поддерева в кучу
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;  // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1;  // левый = 2*i + 1
    int right = 2 * i + 2;  // правый = 2*i + 2
    
    // Проверяем существует ли левый дочерний элемент больший, чем корень
    if (left < n && arr[i] < arr[left]) {
        largest = left;
    }
    
    // Проверяем существует ли правый дочерний элемент больший, чем корень
    if (right < n && arr[largest] < arr[right]) {
        largest = right;
    }
    
    // Меняем корень, если нужно
    if (largest != i) {
        swap(arr[i], arr[largest]);
        
        // Применяем heapify к корню
        heapify(arr, n, largest);
    }
}

// Основная функция для пирамидальной сортировки
void heapSort(vector<int>& arr) {
    int n = arr.size();
    
    // Построение max-heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    // Один за другим извлекаем элементы
    for (int i = n - 1; i > 0; i--) {
        // Меняем корень с последним элементом
        swap(arr[0], arr[i]);
        
        // Вызываем heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

// Пример использования:
int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    
    cout << "Исходный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    heapSort(arr);
    
    cout << "Отсортированный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}