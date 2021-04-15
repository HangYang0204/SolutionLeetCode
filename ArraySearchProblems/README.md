## Find maximum or minimum element from an Array
Iterate through an array with a while loop or for loop is great way will first come to mind. Now in order to find max/min element, we need to compare 2 elements when we loop through the array. Thus we should maintain 2 iterators. 

lf our goal is to find the maxmium, for example,set the 2 iterators to be i and j. Initially i = 0 and j = 1.We move j forward and update i conditonally:
if array[i] < array[j] then we update i = j and once the while loop ended, i will point to the maximum element in the array. 
```c++
    int i = 0, j = 1;
    while(j < nums.size()>){
       if(nums[i] < nums[j]){
           i = j;
           j++;
       }
       else{
           j++;
       }
    }
    return i
```

## Application example: buy and sell stock
Suppose we have historical stock prices data, we want to know when stock was bought and when it was sold would maxize the profit. supposing stock prices stored in an array such that at the element at index i is the price at time i. 
Algorithm:
1. The key point is to find the __latest__ maxmimum element of the array and that will out sell point j. 
2. Since buy point should happend befor sell, thus we only need to find the minimum element i in the subarray before sell point
3. return the index {i,j}


## Application example: slicing array for maximum
Slicing an array into 2 subarrays, find the maximum from each subarrays, now define delat = max(subarray Left) - max(subarray Right). Now find the slicing that make delta maximized. 

example: {0,4,6,7}  
slicing 1 : {0} {4,6,7} delta = 7 - 0 = 7
slicing 2 : {0,4} {6,7} delta = 7 - 4 = 3
slicing 3 : {0,4,6} {7} delta = 7 - 6 = 1
thus {{0},{4,6,7}} is returned
Algorithm:
1. Find maximum element MAX from the array, MAX would always be the Maximum of that subarray no matter how you slice it. 
2. Suppose you have MAX sliced into left part. We are going to reason that MAX - array[N - 1] is the maximized delta. If sliced the array such that the right subarray has a maximum element other than array[N - 1], for example arrray[k] > array[N - 1] then the delta = MAX - array[k] < MAX - array[N - 1]. So only if array[N - 1] the maximum element could we get the maximized delta. So the slicing would be just {a[0]...a[N-2]}, {a[N-1]}.
3. the same reasoning can be formed if MAX sliced into right part. {a[0]}, {a[1]....a[N-1]}
4. Now we need to compare the result from step 3 and 4 to find the global minimum then return the slicing scheme accordingly. 

__Note that : this solution can only give one possible way to slice it. the complete list of ways to slice need further efforts__
