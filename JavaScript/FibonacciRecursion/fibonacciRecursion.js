const iterator = (n, prev, curr) => (n === 0 ? curr : iterator(n - 1, curr, prev + curr));

const fibonacci = n => iterator(n, 1, 0);

(function () {
	console.log(fibonacci(10));
})();
