func linearSearch(array:[Int], searchValue:Int) -> Int {
    
    var cost:Int = 0;
    
    for var i = 0 ; i < array.count ; i++ {
        cost++;
        if array[i] == searchValue {
            break;
        }
    }
    return cost;
    
}

func binarySearch(array:[Int], searchValue:Int) -> Int {
    
    var cost:Int = 0;
    var high:Int = array.count - 1;
    var low:Int = 0;
    var mid:Int;

    while low <= high {
        mid = (high+low)/2;
        cost++;
        if searchValue == array[mid] {
            break;
        }else if searchValue > array[mid]{
            low = mid+1;
            cost++;
        }else{
            high = mid-1;
            cost++;
        }
    }
    
    return cost; 
}

func shuffle(inout array:[Int]){

    var currentIndex:Int = array.count,
        temporaryValue:Int,
        randomIndex:Int,
        size:UInt32 = UInt32(array.count);

    while 0 != currentIndex {
        randomIndex = Int(arc4random_uniform(size));
        currentIndex -= 1;

        temporaryValue = array[currentIndex];
        array[currentIndex] = array[randomIndex];
        array[randomIndex] = temporaryValue;
    }
}
func populateArray(size:Int, sorted:Bool) -> [Int]{
    var searchArray:[Int] = [];

    for var i = 0; i<size; i++ {
        searchArray.append(i+1);
    }

    if !sorted {
        shuffle(&searchArray)
    }
    return searchArray;
}

var arraySize = 100,
    linearCost = 0,
    binaryCost = 0,
    sortedArray:[Int] = [];

sortedArray = populateArray(arraySize,true);

for var i = 0; i<arraySize; i++ {
    linearCost += linearSearch(sortedArray,(i+1));
}

println("LINEAR SEARCH COST IS "+String(linearCost/arraySize));

for var i = 0; i<arraySize; i++ {
    binaryCost += binarySearch(sortedArray,(i+1));
}

println("BINARY SEARCH COST IS "+String(binaryCost/arraySize));