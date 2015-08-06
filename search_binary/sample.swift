// BINARY SEARCH
// http://swiftstub.com/ if you don't have a mac

var a = [15, 23, 24, -32, 7, 89, 64];
var searchValue = 24;

a = a.sorted(<); // you may also do it as sort(&a,<)

func binarySearch(array:[Int], searchValue:Int) -> Int {
    
    var result:Int = -1;
    var high:Int = array.count - 1;
    var low:Int = 0;
    var mid:Int;
    

    while low <= high {
        mid = (high+low)/2;
        
        if searchValue == array[mid] {
            result = mid;
            break;
        }else if searchValue > array[mid]{
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    
    return result;
    
}

var result = binarySearch(a,searchValue);

if result > -1 {
    // if you want it on string convert it to string or 
    var message = String(searchValue)+" found in index "+String(result);
    println(message);
}else{
    // you way use it this way also
    println("\(searchValue) not found in array");
}