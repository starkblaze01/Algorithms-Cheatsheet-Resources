const isPrime = n => {
	if (n < 2) return false;
	if (n === 2 || n === 3) return true;
	if (n % 2 === 0 || n % 3 === 0) return false;

	const sqrt = Math.ceil(Math.sqrt(n));

	for (let i = 5; i <= sqrt; i += 6) {
		if (n % i === 0 || n % (i + 2) === 0) {
			return false;
		}
	}

	return true;
};

(function () {
	console.log(isPrime(37));
})();
