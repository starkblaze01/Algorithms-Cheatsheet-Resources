const gcd = (a, b) => (a === b ? a : a > b ? gcd(a - b, b) : gcd(a, b - a));

console.log(`GCD of 15 and 20 is ${gcd(15, 20)}`);
