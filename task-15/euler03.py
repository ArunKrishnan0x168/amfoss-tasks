#Author : Arun Krishnan(AM.EN.U4CSE22004)

def primes(n):
    factors = []
    divisor = 2
    while n > 1:
        while n % divisor == 0:
            factors.append(divisor)
            n /= divisor
        divisor = divisor + 1

    return factors

T = int(input())

for i in range(T):
    N = int(input())
    prime = primes(N)
    lar_prime = max(prime)

    print(lar_prime)


