import java.util.Arrays;

public class MergeSort {
    
    // Основной метод сортировки слиянием
    public static int[] mergeSort(int[] arr) {
        // Базовый случай: массив длиной 0 или 1 уже отсортирован
        if (arr.length <= 1) {
            return arr;
        }
        
        // Находим середину массива
        int mid = arr.length / 2;
        
        // Делим массив на две части
        int[] left = Arrays.copyOfRange(arr, 0, mid);
        int[] right = Arrays.copyOfRange(arr, mid, arr.length);
        
        // Рекурсивно сортируем каждую часть
        left = mergeSort(left);
        right = mergeSort(right);
        
        // Сливаем отсортированные части
        return merge(left, right);
    }
    
    // Метод для слияния двух отсортированных массивов
    public static int[] merge(int[] left, int[] right) {
        int[] result = new int[left.length + right.length];
        int i = 0, j = 0, k = 0;
        
        // Пока есть элементы в обоих массивах
        while (i < left.length && j < right.length) {
            if (left[i] < right[j]) {
                result[k++] = left[i++];
            } else {
                result[k++] = right[j++];
            }
        }
        
        // Добавляем оставшиеся элементы из левого массива
        while (i < left.length) {
            result[k++] = left[i++];
        }
        
        // Добавляем оставшиеся элементы из правого массива
        while (j < right.length) {
            result[k++] = right[j++];
        }
        
        return result;
    }
    
    // Пример использования
    public static void main(String[] args) {
        int[] array = {38, 27, 43, 3, 9, 82, 10};
        System.out.println("Исходный массив: " + Arrays.toString(array));
        
        int[] sortedArray = mergeSort(array);
        System.out.println("Отсортированный массив: " + Arrays.toString(sortedArray));
    }
}