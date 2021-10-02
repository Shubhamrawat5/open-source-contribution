function bubbleSort(arr) {

    for (var i = 0; i < arr.length; i++) {

        for (var j = 0; j < (arr.length - i - 1); j++) {

            if (arr[j] > arr[j + 1]) {

                var temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp
            }
        }
    }
}


var arr = [212, 32, 410, 12, 8, 45, 235];

console.log(bubbleSort(arr));