const gcd = (a, b) => (a === b ? a : a > b ? gcd(a - b, b) : gcd(a, b - a));

const lcm = (a, b) => (a * b) / gcd(a, b);

console.log(`LCM of 15 and 20 is ${lcm(15, 20)}`);
