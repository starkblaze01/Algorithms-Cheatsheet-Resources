const ncr = (n, r) => {
	if (r > n || n < 0 || r < 0) {
		return -1;
	} else {
		if (r > Math.floor(n / 2)) {
			r = n - r;
		}

		let ans = 1;

		for (let i = 1; i <= r; i++) {
			ans *= n - r + i;
			ans = Math.floor(ans / i);
		}

		return ans;
	}
};

console.log(`ncr(15, 5) = ${ncr(15, 5)}`);
