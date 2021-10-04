var bubbleSort = (inputArray) => {
    let swap;
    var swapped;
    do{
        swapped = false;
        for(let i = 0; i<inputArray.length; i++){
            if(inputArray[i] > inputArray[i+1]){
                var temp = inputArray[i];
                inputArray[i] = inputArray[i+1];
                inputArray[i+1] = temp;
                swapped = true;
                }
            }
    }
    while(swapped);
    return inputArray;
};

a = [3,5,71,2,65,44];
console.log(bubbleSort(a));