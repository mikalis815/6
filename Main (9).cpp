#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr) {
    // Проходим по всем элементам массива
    for (size_t i = 0; i < arr.size(); i++) {
        // Предполагаем, что первый элемент - минимальный
        size_t minIndex = i;
        // Ищем минимальный элемент в оставшейся части массива
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Меняем найденный минимальный элемент с первым элементом в неотсортированной части
        swap(arr[i], arr[minIndex]);
    }
}

// Пример использования
int main() {
    // Создаем тестовый массив
    vector<int> testArray = {64, 25, 12, 22, 11};
    cout << "Исходный массив: ";
    for (int num : testArray) {
        cout << num << " ";
    }
    cout << endl;
    
    // Сортируем массив
    selectionSort(testArray);
    cout << "Отсортированный массив: ";
    for (int num : testArray) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}