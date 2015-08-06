// BINARY SEARCH

var a = [15, 23, 24, -32, 7, 89, 64],
	searchValue = 24;

a = a.sort(); // necessary for binary search because search is dependent on its relationship interms of ordinal sequence

var binarySearch = function(searchArray,searchValue){
	var index = -1,
		high = searchArray.length -1,
		low = 0,
		mid;

	while(low <= high){
		mid = Math.floor( (high+low)/2 );
		
		if(searchValue == searchArray[mid]){
			index = mid;
			break;
		}else if(searchValue > searchArray[mid]){
			low = mid+1;
		}else{
			high = mid-1;
		}
	}

	return index;
}

var result = binarySearch(a,searchValue);

if(result > -1){
	console.log(searchValue+" has been found at "+result);
}else{
	console.log(searchValue+" not found");
}