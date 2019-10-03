const npr = (n, r) => {
	if (r > n || n < 0 || r < 0) {
		return -1;
	} else {
		let ans = 1;

		for (let i = n; i > n - r; i--) {
			ans *= i;
		}

		return ans;
	}
};

console.log(`npr(15, 5) = ${npr(15, 5)}`);
