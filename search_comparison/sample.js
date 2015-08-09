// BINARY SEARCH

var binarySearch = function(searchArray,searchValue){
  'use strict';
  var cost = 0,
      high = searchArray.length -1,
      low = 0,
      mid;

  while(low <= high){
    mid = Math.floor( (high+low)/2 );
    cost++;

    if(searchValue == searchArray[mid]){
      break;
    }else if(searchValue > searchArray[mid]){
      low = mid+1;
      cost++;
    }else{
      high = mid-1;
      cost++;
    }
  }

  return cost;
}
var searchLinear = function(searchArray,searchValue){
  'use strict';
  var cost = 0;
  for(var i = 0; i < searchArray.length; i++){
    cost++;
    if(searchArray[i] == searchValue){
      break;
    }
  }
  return cost;
}

// Fisher-Yatest(aka Knuth) Shuffle
function shuffle(array) {
  'use strict';
  var currentIndex = array.length, temporaryValue, randomIndex ;

  // While there remain elements to shuffle...
  while (0 !== currentIndex) {

    // Pick a remaining element...
    randomIndex = Math.floor(Math.random() * currentIndex);
    currentIndex -= 1;

    // And swap it with the current element.
    temporaryValue = array[currentIndex];
    array[currentIndex] = array[randomIndex];
    array[randomIndex] = temporaryValue;
  }

  return array;
}
var populateArray = function(size,sorted){
  'use strict';
  var searchArray = [];

  for(var i = 0; i < size; i++){
    searchArray.push(i+1);
  }
  if(!sorted){
    shuffle(searchArray);
  }
  return searchArray;
}




var arraySize = 100,
    linearCost = 0,
    binaryCost = 0;

var sortedArray = populateArray(arraySize,true);


// SET A TEST

for(var i = 0; i < arraySize; i++){
  linearCost+= searchLinear(sortedArray,(i+1));
}

console.log("LINEAR SEARCH COST IS ", linearCost/arraySize );

for(var i = 0; i < arraySize; i++){
  binaryCost+= binarySearch(sortedArray,(i+1));
}

console.log("BINARY SEARCH COST IS ",binaryCost/arraySize);