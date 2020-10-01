const mode = a => 
  Object.values(
    a.reduce((count, e) => {
      if (!(e in count)) {
        count[e] = [0, e];
      }
      
      count[e][0]++;
      return count;
    }, {})
  ).reduce((a, v) => v[0] < a[0] ? a : v, [0, null])[1];
;

console.log(mode([1,2,3,4,5,6,7,7]));
console.log(mode([1,1,1,4,5,6,7,7]));
console.log(mode([1,2,3,3,3,6,3,7]));
console.log(mode([1,3,3,4,5,2,2,1]));
console.log(mode([]));
