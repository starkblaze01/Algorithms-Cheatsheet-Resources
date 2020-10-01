const binarySearch = (arr, num) => {
	let [left, right] = [0, arr.length - 1];

	while (right >= left) {
		let mid = Math.floor((right + left) / 2);

		if (arr[mid] === num) return mid;
		else if (arr[mid] > num) right = mid - 1;
		else if (arr[mid] < num) left = mid + 1;
	}
};

(function () {
	const arr = [1, 6, 8, 12, 15, 20, 25, 32, 64];
	console.log(binarySearch(arr, 20));
})();
