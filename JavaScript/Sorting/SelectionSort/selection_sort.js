function selection_sort(inputArray){

    for(let i = 0; i<inputArray.length;i++){
        let min = i;
        for(let j = i+1; j<inputArray.length;j++){
            if(inputArray[min] > inputArray[j]){
                min = j;
            }
        }
        if( min != i){
            let temp = inputArray[i];
            inputArray[i] = inputArray[min];
            inputArray[min] = temp;
        }
    }
    return inputArray;
}

var nums = [6, 3, 4, 5, 61, 2, 77];
console.log(selection_sort(nums));
