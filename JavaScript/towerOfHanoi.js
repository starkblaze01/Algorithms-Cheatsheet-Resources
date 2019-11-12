const towerOfHanoi = (n, fromRod, toRod, auxRod) => {
	if (n === 1) {
		console.log(`${fromRod} -> ${toRod}`);
	} else {
		towerOfHanoi(n - 1, fromRod, auxRod, toRod);
		console.log(`${fromRod} -> ${auxRod}`);
		towerOfHanoi(n - 1, auxRod, toRod, fromRod);
	}
};

towerOfHanoi(5, 'A', 'B', 'C');
