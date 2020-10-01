const mode = a => {
    const count = {};

    a.forEach(e => {
        if (!(e in count)) {
            count[e] = 0;
        }

        count[e]++;
    });

    let bestElement;
    let bestCount = 0;

    Object.entries(count).forEach(([k, v]) => {
        if (v > bestCount) {
            bestElement = k;
            bestCount = v;
        }
    });

    return bestElement;
};

console.log(mode([1,2,3,4,5,6,7,7]));
console.log(mode([1,1,1,4,5,6,7,7]));
console.log(mode([1,2,3,3,3,6,3,7]));
console.log(mode([1,3,3,4,5,2,2,1]));
