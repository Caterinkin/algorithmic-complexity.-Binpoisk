#include <iostream>

// Функция для поиска количества элементов, больших точки отсчёта
int countGreaterThan(int arr[], int size, int target) 
{
    int left = 0, right = size - 1;
    int position = size; // Изначально предполагаем, что все элементы больше

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] > target) 
        {
            position = mid; // Запоминаем позицию
            right = mid - 1; // Ищем левее
        }
        else 
        {
            left = mid + 1; // Ищем правее
        }
    }

    // Количество элементов, больших target
    return size - position;
}

int main() 
{
    setlocale(LC_ALL, "rus");

    int arr[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    std::cout << "Введите точку отсчёта: ";
    std::cin >> target;

    int result = countGreaterThan(arr, size, target);
    std::cout << "Количество элементов в массиве больших, чем " << target << ": " << result << std::endl;

    return EXIT_SUCCESS;
}