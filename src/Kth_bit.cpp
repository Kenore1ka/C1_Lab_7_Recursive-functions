#include <iostream>
#include <string>

using namespace std;

// Функция для инвертирования и переворачивания строки
string invertAndReverse(const string &s) {
    string result;

    for (int i = s.length() - 1; i >= 0; --i) {
        result += (s[i] == '0' ? '1' : '0');
    }
    return result;
}

// Рекурсивная функция для получения k-того бита в строке S_n
char getKthBit(int n, long long k) {
    if (n == 1) {
        return '0';  // S1 всегда "0"
    }
    long long len = (1LL << n) - 1;  // Длина строки S_n = 2^n - 1
    long long mid = len / 2;         // Середина строки

    if (k == mid) {
        return '1';  // Средний элемент всегда '1'
    } else if (k < mid) {
        return getKthBit(n - 1, k);  // Если k в первой половине, это элемент S_(n-1)
    } else {
        return getKthBit(n - 1, len - k - 1) == '0' ? '1'
                                                    : '0';  // Иначе это инвертированный элемент из S_(n-1)
    }
}

int main() {
    int n, k;
    cout << "Enter values of n and k: ";
    cin >> n >> k;

    // Сдвигаем k на единицу назад, так как в задаче индексация идет с 1
    k--;

    if (k < 0 || k >= (1 << n) - 1) {
        cout << "Invalid k value" << endl;
        return 1;
    }

    cout << "The " << k + 1 << "th bit of S" << n << " is: " << getKthBit(n, k) << endl;
    return 0;
}
