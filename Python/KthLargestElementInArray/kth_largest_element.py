from heapq import heappush, heappop

def find_kth_largest(nums: list, k: int) -> int:
    h = []
    [heappush(h, -num) for num in nums]
    [heappop(h) for _ in range(k-1)]
    return -heappop(h)



if __name__ == "__main__":
    nums = list(map(int,input().split(' ')))
    k = int(input)
    largestElement = find_kth_largest(nums,k)

    print("The Kth ("+str(k)+") Largest element is",largestElement)
    