def linear_search(arr, target):
    """
    Функция линейного поиска
    """
    # Проходим по всем элементам массива
    for i in range(len(arr)):
        # Если нашли искомый элемент
        if arr[i] == target:
            return i  # Возвращаем индекс найденного элемента
    return -1  # Возвращаем -1, если элемент не найден

def main():
    # Создаем массив
    array = [3, 5, 2, 7, 9, 1, 4]
    target = 7  # Искомое значение
    
    # Вызываем функцию поиска
    result = linear_search(array, target)
    
    # Выводим результат
    if result != -1:
        print(f"Элемент найден на позиции: {result}")
    else:
        print("Элемент не найден")

if __name__ == "__main__":
    main()