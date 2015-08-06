// http://swiftstub.com/ if you don't have a mac

var a = [1,2,3,4,6];
var searchValue = 3;

func search(array:[Int], searchValue:Int) -> Int {
    
    var result = -1;
    
    for var i = 0 ; i < array.count ; i++ {
        if array[i] == searchValue {
         result = i;
        }
    }
    return result;
    
}

var result = search(a,searchValue);

if result > -1 {
    // if you want it on string convert it to string or 
    var message = String(searchValue)+" found in index "+String(result);
    println(message);
}else{
    // you way use it this way also
    println("\(searchValue) not found in array");
}