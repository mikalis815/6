public class BubbleSort {
    
    /**
     * Сортировка массива методом пузырька
     */
    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        // Проходим по всем элементам массива
        for (int i = 0; i < n - 1; i++) {
            // Последний элемент на каждой итерации уже на своем месте
            for (int j = 0; j < n - i - 1; j++) {
                // Сравниваем соседние элементы
                if (arr[j] > arr[j + 1]) {
                    // Меняем местами, если они стоят в неправильном порядке
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    
    /**
     * Функция для вывода массива
     */
    public static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
    
    // Пример использования
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        System.out.println("Исходный массив:");
        printArray(arr);
        
        bubbleSort(arr);
        System.out.println("Отсортированный массив:");
        printArray(arr);
    }
}