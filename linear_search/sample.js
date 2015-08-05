var a = [15, 23, 24, 32, 7],
	searchValue = 24;

var search = function(searchArray,searchValue){
	var index = -1;
	for(var i = 0; i < searchArray.length; i++){
		if(searchArray[i] == searchValue){
			index = i;
			break;
		}
	}
	return index;
}

var result = search(a,searchValue);

if(result > -1){
	console.log(searchValue+" has been found at "+result);
}else{
	console.log(searchValue+" not found");
}