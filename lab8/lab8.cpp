#include<iostream>
#include<Windows.h>
#include<algorithm>
#include<vector>
#include<ctime>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(0));

    int n;
    cout << "Введіть кількість елементів: ";
    cin >> n;

    vector<int> array;

    for (int i = 0; i < n; i++) {
        array.push_back(rand() % 201-100);
    }

    int sumOfOddIndices = 0;
    for (int i = 1; i < n; i += 2) {
        sumOfOddIndices += array[i];
    }

    cout << "Початковий масив: ";
    for (int element : array) {
        cout << element << " ";
    }
    cout << endl;

    auto firstNegative = find_if(array.begin(), array.end(), [](int x) { return x < 0; });

    if (firstNegative != array.end()) {
        auto lastNegative = find_if(array.rbegin(), array.rend(), [](int x) { return x < 0; }).base();

            int sumBetweenNegatives = 0;
            auto it = next(firstNegative);
            while (it != lastNegative) {
                sumBetweenNegatives += *it;
                ++it;
            }

            auto newEnd = remove_if(array.begin(), array.end(), [](int x) { return abs(x) <= 1; });

            fill(newEnd, array.end(), 0);

            cout << "Сума елементів масиву з непарними номерами: " << sumOfOddIndices << endl;
            cout << "Сума елементів масиву між першим і останнім від'ємними елементами: " << sumBetweenNegatives << endl;

            cout << "Масив після стиснення та заповнення нулями: ";
            for (int element : array) {
                cout << element << " ";
            }
    }

    return 0;
}

