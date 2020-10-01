const mean = arr => arr.reduce((prev, current) => prev + current, 0) / arr.length;

console.log(mean([2, 4, 6, 8]));
