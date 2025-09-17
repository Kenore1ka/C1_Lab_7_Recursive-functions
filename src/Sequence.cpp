#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int getFirstDigit(int num) {
    while (num >= 10) num /= 10;
    return num;
}

int getLastDigit(int num) { return num % 10; }

// Функция, которая ищет и выводит наиболее длинную возможную последовательность
void findSequence(const vector<int>& numbers) {
    queue<vector<int>> sequences;  // Очередь для хранения всех текущих последовательностей
    vector<int> longestSeq;  // Вектор для хранения наиболее длинной найденной последовательности

    // Инициализируем очередь, добавляя каждое число как начальную последовательность
    for (int num : numbers) {
        sequences.push({num});
    }

    // Цикл обработки всех текущих последовательностей
    while (!sequences.empty()) {
        vector<int> currentSeq = sequences.front();  // Получаем первую последовательность из очереди
        sequences.pop();  // Удаляем эту последовательность из очереди

        // Если текущая последовательность длиннее сохранённой, обновляем сохранённую
        if (currentSeq.size() > longestSeq.size()) {
            longestSeq = currentSeq;
        }

        // Получаем последнюю цифру последнего числа в текущей последовательности
        int lastNum = currentSeq.back();
        int lastDigit = getLastDigit(lastNum);

        // Пытаемся добавить к последовательности следующий подходящий элемент
        for (int num : numbers) {
            // Проверяем, не содержится ли число уже в последовательности и подходит ли оно по правилу
            if (find(currentSeq.begin(), currentSeq.end(), num) == currentSeq.end() &&
                getFirstDigit(num) == lastDigit) {
                vector<int> newSeq = currentSeq;  // Создаем новую последовательность на основе текущей
                newSeq.push_back(num);  // Добавляем подходящее число
                sequences.push(newSeq);  // Добавляем новую последовательность обратно в очередь
            }
        }
    }

    // Выводим наиболее длинную последовательность
    if (!longestSeq.empty()) {
        for (int num : longestSeq) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << "Не удалось найти подходящую последовательность." << endl;
    }
}

int main() {
    vector<int> numbers = {23, 56, 67, 72, 83};  // Инициализируем вектор чисел
    findSequence(numbers);  // Вызываем функцию поиска последовательности
    return 0;  // Возвращаем 0, что означает успешное выполнение программы
}
