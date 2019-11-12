def generate_primes(n):
    """
    generates prime numbers upto n {excluding n} using sieve of eratosthenes.
    
    Parameters
    ----------
    n : positive integer
       the maximum number upto which prime numbers are to be generated

    Returns
    -------
    Generator of all the prime numbers upto n
    """
    
    if n < 2:
        return ()
    sieve = set(range(2, n))
    while sieve:
        prime = min(sieve)
        yield prime
        sieve -= set(range(prime, n, prime))


if __name__ == '__main__':
    # Base Case
    assert tuple(generate_primes(2)) == tuple()

    # Invalid case
    assert tuple(generate_primes(-1)) == tuple()

    # valid case
    assert tuple(generate_primes(10)) == (2, 3, 5, 7)

