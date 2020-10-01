function merge(left_part,right_part) 
{
	var i = 0;
	var j = 0;
	var results = [];

	while (i < left_part.length || j < right_part.length) {
		if (i === left_part.length) {
			// j is the only index left_part
			results.push(right_part[j]);
			j++;
		} 
      else if (j === right_part.length || left_part[i] <= right_part[j]) {
			results.push(left_part[i]);
			i++;
		} else {
			results.push(right_part[j]);
			j++;
		}
	}
	return results;
}

function mergeSort(arr) {
    if(arr.length <= 1) return arr;
    var mid = Math.floor(arr.length/2);
    var left = mergeSort(arr.slice(0,mid));
    var right = mergeSort(arr.slice(mid));
    return merge(left, right);
}


console.log(mergeSort([2, 3, 3, 4, 6, 7, 12]));
