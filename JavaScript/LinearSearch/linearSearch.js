const linearSearch = (arr, num) => {
	let index = -1;

	arr.forEach((n, i) => {
		if (n == num) {
			index = i;
		}
	});

	return index;
};

(function () {
	const arr = [1, 15, 547, 1864, 531, 510, 5, 64];

	console.log(linearSearch(arr, 531));
})();
