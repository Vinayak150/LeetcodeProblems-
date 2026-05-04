class Solution:
    def sumOfPrimesInRange(self, n: int) -> int:
        # Reverse n manually without using built-in reverse
        def reverse_num(x: int) -> int:
            rev = 0
            while x > 0:
                digit = x % 10
                rev = rev * 10 + digit
                x //= 10
            return rev

        # Check whether a number is prime
        def is_prime(x: int) -> bool:
            if x < 2:
                return False
            if x == 2:
                return True
            if x % 2 == 0:
                return False

            d = 3
            while d * d <= x:
                if x % d == 0:
                    return False
                d += 2
            return True

        r = reverse_num(n)

        left = min(n, r)
        right = max(n, r)

        total = 0

        # Check every number in the range [left, right]
        for num in range(left, right + 1):
            if is_prime(num):
                total += num

        return total