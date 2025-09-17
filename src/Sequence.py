from collections import deque

def get_first_digit(num):
    """Получить первую цифру числа"""
    while num >= 10:
        num //= 10
    return num

def get_last_digit(num):
    """Получить последнюю цифру числа"""
    return num % 10

def find_sequence(numbers):
    """Функция, которая ищет и выводит наиболее длинную возможную последовательность"""
    sequences = deque()  # Очередь для хранения всех текущих последовательностей
    longest_seq = []     # Список для хранения наиболее длинной найденной последовательности

    # Инициализируем очередь, добавляя каждое число как начальную последовательность
    for num in numbers:
        sequences.append([num])

    # Цикл обработки всех текущих последовательностей
    while sequences:
        current_seq = sequences.popleft()  # Получаем первую последовательность из очереди

        # Если текущая последовательность длиннее сохранённой, обновляем сохранённую
        if len(current_seq) > len(longest_seq):
            longest_seq = current_seq

        # Получаем последнюю цифру последнего числа в текущей последовательности
        last_num = current_seq[-1]
        last_digit = get_last_digit(last_num)

        # Пытаемся добавить к последовательности следующий подходящий элемент
        for num in numbers:
            # Проверяем, не содержится ли число уже в последовательности и подходит ли оно по правилу
            if num not in current_seq and get_first_digit(num) == last_digit:
                new_seq = current_seq.copy()  # Создаем новую последовательность на основе текущей
                new_seq.append(num)           # Добавляем подходящее число
                sequences.append(new_seq)     # Добавляем новую последовательность обратно в очередь

    # Выводим наиболее длинную последовательность
    if longest_seq:
        print(" ".join(str(num) for num in longest_seq))
    else:
        print("Не удалось найти подходящую последовательность.")

def main():
    numbers = [23, 56, 67, 72, 83]  # Инициализируем список чисел
    find_sequence(numbers)           # Вызываем функцию поиска последовательности

if __name__ == "__main__":
    main()