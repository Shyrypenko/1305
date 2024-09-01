#include <iostream>

//1
void sum_and_product(const int* arr, int size, int* sum, int* product) {
    *sum = 0;
    *product = 1;
    for (int i = 0; i < size; ++i) {
        *sum += arr[i];
        *product *= arr[i];
    }
}

//2
void sum_and_product(const int* arr, int size, int& sum, int& product) {
    sum = 0;
    product = 1;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
        product *= arr[i];
    }
}

//3
void count_elements(const int* arr, int size, int& negatives, int& positives, int& zeros) {
    negatives = positives = zeros = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) {
            negatives++;
        }
        else if (arr[i] > 0) {
            positives++;
        }
        else {
            zeros++;
        }
    }
}

//4
void average_and_count(const int* arr, int size, double& average, int& evens, int& odds) {
    int sum = 0;
    evens = odds = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
        if (arr[i] % 2 == 0) {
            evens++;
        }
        else {
            odds++;
        }
    }
    average = static_cast<double>(sum) / size;
}

//5
const int* is_subset(const int* A, int sizeA, const int* B, int sizeB) {
    if (sizeB == 0) return A;
    for (int i = 0; i <= sizeA - sizeB; ++i) {
        bool is_subset = true;
        for (int j = 0; j < sizeB; ++j) {
            if (A[i + j] != B[j]) {
                is_subset = false;
                break;
            }
        }
        if (is_subset) return &A[i];
    }
    return nullptr;
}

int main() {
    int choice;
    std::cout << "�������� ��������:\n";
    std::cout << "1. ���������\n";
    std::cout << "2. ������\n";
    std::cout << "3. ������� �������� �������\n";
    std::cout << "4. ������� ��������������\n";
    std::cout << "5. �������� ������� A\n";
    std::cout << "������� ����� ��������: ";
    std::cin >> choice;

    if (choice >= 1 && choice <= 4) {
        int size;
        std::cout << "������ �������: ";
        std::cin >> size;

        int* arr = new int[size];
        std::cout << "�������� �������: ";
        for (int i = 0; i < size; ++i) {
            std::cin >> arr[i];
        }

        if (choice == 1 || choice == 2) {
            int sum, product;
            if (choice == 1) {
                sum_and_product(arr, size, &sum, &product);
            }
            else {
                sum_and_product(arr, size, sum, product);
            }
            std::cout << "�����: " << sum << "\n������������: " << product << std::endl;
        }
        else if (choice == 3) {
            int negatives, positives, zeros;
            count_elements(arr, size, negatives, positives, zeros);
            std::cout << "�������������: " << negatives << "\n�������������: " << positives << "\n�������: " << zeros << std::endl;
        }
        else if (choice == 4) {
            double average;
            int evens, odds;
            average_and_count(arr, size, average, evens, odds);
            std::cout << "������� ��������������: " << average << "\n׸����: " << evens << "\n��������: " << odds << std::endl;
        }

        delete[] arr;
    }
    else if (choice == 5) {
        int sizeA, sizeB;
        std::cout << "������� ������ ������� A: ";
        std::cin >> sizeA;
        int* A = new int[sizeA];
        std::cout << "������� �������� ������� A: ";
        for (int i = 0; i < sizeA; ++i) {
            std::cin >> A[i];
        }

        std::cout << "������� ������ ������� B: ";
        std::cin >> sizeB;
        int* B = new int[sizeB];
        std::cout << "������� �������� ������� B: ";
        for (int i = 0; i < sizeB; ++i) {
            std::cin >> B[i];
        }

        const int* result = is_subset(A, sizeA, B, sizeB);
        if (result) {
            std::cout << "������ B �������� ������������� ������� A. ���������� � ��������: " << *result << std::endl;
        }
        else {
            std::cout << "������ B �� �������� ������������� ������� A." << std::endl;
        }

        delete[] A;
        delete[] B;
    }
    else {
        std::cout << "������������ ����� ��������." << std::endl;
    }

    return 0;
}
