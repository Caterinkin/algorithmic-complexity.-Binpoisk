#include <iostream>

// ������� ��� ������ ���������� ���������, ������� ����� �������
int countGreaterThan(int arr[], int size, int target) 
{
    int left = 0, right = size - 1;
    int position = size; // ���������� ������������, ��� ��� �������� ������

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] > target) 
        {
            position = mid; // ���������� �������
            right = mid - 1; // ���� �����
        }
        else 
        {
            left = mid + 1; // ���� ������
        }
    }

    // ���������� ���������, ������� target
    return size - position;
}

int main() 
{
    setlocale(LC_ALL, "rus");

    int arr[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    std::cout << "������� ����� �������: ";
    std::cin >> target;

    int result = countGreaterThan(arr, size, target);
    std::cout << "���������� ��������� � ������� �������, ��� " << target << ": " << result << std::endl;

    return EXIT_SUCCESS;
}