import functools


def get_digit(number, digit):
    return int((number % (10 ** digit)) / (10 ** (digit - 1)))


def lsd_radix_sort(array):
    MAX_DIGITS = 10
    for digit in range(1, MAX_DIGITS + 1):
        buckets = [[] for _ in range(10)]
        for number in array:
            buckets[get_digit(number, digit)].append(number)
        array = functools.reduce(lambda x, y: x + y, buckets, [])
    return array


if __name__ == '__main__':
    print (lsd_radix_sort([43, 1243, 354, 0, 1, 22]))
    print (lsd_radix_sort([2, 10]))
    print (lsd_radix_sort([1]))
    print (lsd_radix_sort([]))
