const factorial = n => (n === 0 ? 1 : n * factorial(n - 1));

(function () {
	console.log(factorial(5));
})();
