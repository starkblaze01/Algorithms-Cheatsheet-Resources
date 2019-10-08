// Sieve of Eratosthenes is an algorithm for generating all prime numbers
// less than or equal to a given number N

package main

import (
	"fmt"
)

func displayPrime(num int, prime []bool) {
	fmt.Printf("Primes less than %d : ", num)
	for i := 2; i <= num; i++ {
		if prime[i] == false {
			fmt.Printf("%d ", i)
		}
	}
	fmt.Println()
}

func sieve(num int) {
	prime := make([]bool, num+1)

	for i := 0; i < num+1; i++ {
		prime[i] = false
	}

	for i := 2; i*i <= num; i++ {
		if prime[i] == false {
			for j := i * 2; j <= num; j += i {
				prime[j] = true // cross
			}
		}

	}

	displayPrime(num, prime)
}

func main() {
	sieve(30)
	sieve(10)
	sieve(60)
}
