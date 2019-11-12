const phi = n => {
	let total = n;

	for (let i = 2; i < Math.sqrt(n) + 1; i++) {
		if (n % i === 0) {
			while (n % i === 0) {
				n = Math.floor(n / i);
			}
			total *= 1 - 1 / i;
		}
	}

	if (n > 1) {
		total *= 1 - 1 / n;
	}

	return Math.floor(total);
};

for (let i = 1; i < 11; i++) {
	console.log(`Φ(${i}) = ${phi(i)}`);
}
