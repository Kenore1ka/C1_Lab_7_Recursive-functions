def invert_and_reverse(s: str) -> str:
    """Функция для инвертирования и переворачивания строки"""
    result = []
    for i in range(len(s)-1, -1, -1):
        result.append('1' if s[i] == '0' else '0')
    return ''.join(result)

def get_kth_bit(n: int, k: int) -> str:
    """Рекурсивная функция для получения k-того бита в строке S_n"""
    if n == 1:
        return '0'  # S1 всегда "0"
    
    length = (1 << n) - 1  # Длина строки S_n = 2^n - 1
    mid = length // 2       # Середина строки

    if k == mid:
        return '1'  # Средний элемент всегда '1'
    elif k < mid:
        return get_kth_bit(n - 1, k)  # Если k в первой половине, это элемент S_(n-1)
    else:
        # Иначе это инвертированный элемент из S_(n-1)
        return '1' if get_kth_bit(n - 1, length - k - 1) == '0' else '0'

def main():
    print("Enter values of n and k: ", end="")
    n, k = map(int, input().split())

    # Сдвигаем k на единицу назад, так как в задаче индексация идет с 1
    k -= 1

    if k < 0 or k >= (1 << n) - 1:
        print("Invalid k value")
        return

    result = get_kth_bit(n, k)
    print(f"The {k + 1}th bit of S{n} is: {result}")

if __name__ == "__main__":
    main()