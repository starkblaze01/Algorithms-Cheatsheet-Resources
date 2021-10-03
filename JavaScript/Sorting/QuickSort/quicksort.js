function quickSort(arr, start, end) {

    if (start >= end)
        return arr;

    //pivot is the partitioning index
    let pivot = partition(arr, start, end);

    // Separately sort elements before pivot and after pivot
    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);



}

function partition(arr, p, r) {

    let pivotValue = arr[r];
    let pivotIndex = p;
    for (let i = p; i < r; i++) {
        if (arr[i] < pivotValue) {
            swap(arr, i, pivotIndex);
            pivotIndex++;

        }
    }
    swap(arr, pivotIndex, r);
    return pivotIndex;
}


function swap(arr, x, y) {
    let temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;

}

//testing the algorithm with an input
let a = [4, 5, 2, 1, 6, 8]
quickSort(a, 0, a.length - 1)
console.log(a)