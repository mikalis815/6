public class InterpolationSearch {
    
    /**
     * Рекурсивный метод интерполирующего поиска
     */
    public static int interpolationSearch(int[] arr, int lo, int hi, int x) {
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
    public static int interpolationSearchIterative(int[] arr, int x) {
        int lo = 0;
        int hi = arr.length - 1;
        
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
    
    public static void main(String[] args) {
        int[] arr = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
        int target = 18;
        
        // Рекурсивный поиск
        int result = interpolationSearch(arr, 0, arr.length - 1, target);
        
        if (result != -1) {
            System.out.println("Элемент найден на позиции: " + result);
        } else {
            System.out.println("Элемент не найден");
        }
        
        // Итеративный поиск
        int result2 = interpolationSearchIterative(arr, target);
        System.out.println("Итеративный поиск: " + result2);
    }
}