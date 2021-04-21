# Purpose
solve code challenges and have fun. 

## Change Log
After April 8th 2021.. the work submitted would be in the format of the VSCode Leetcode extension. It is a very good addon to VSCode. 

## Permutation problems
Permutations of an array or any sequence like objects such as string, LinkedList etc. Lets take number array for example. 
Q1. Find all the permutations of a given array, like [1,2,3] the output should be [[1,2,3],[1,3,2],[2,1,3], [2,3,1], [3,1,2], [3,2,1]]. So we want to returns a collection of permutated arrays. 
We know the permutation formula is proved by using Mathematical induction which has similer nature to recursion. So we can take that approach. supposing we have the function that takes given array and return the collection of permuted arrays f. 
f([1,2])--> { 1, f([2]) = [[2]] &  2, f([1]) = [[1]] }
\
__Step 1__ : loop through the array [1,2], create a subarray as a copy of given array, remove the element of current iteration\
__Step 2__ : Pass the subarray to the function so that we can get a collection of permuted arrays with size N - 1. in our case is [[2]] for current element 1.\
__Step 3__ : loop through the result collection and add current element to the beginning of arrays\
__Step 4__ : Then we append arrays from Step2 in the result collection, this will be the current recursion level return\
By using c++ we need to review how to delete element by index(iterator)
```c++
#include<vector>
#include<iostream>
using std::vector;

int main()
{
    vector<int> vec = {1,2,5,6,9};
    //copy a vector is simple
    vector<int> res = vec;
    //vector<int> res(vec.begin(),vec.end());
    //remove i th element 
    int i = 3;
    std::cout << "original vector is: " << std::endl;
    for(int v : vec){
        if(v == vec.back()) std::cout << v << std::endl;
        if(v != vec.back()) std::cout << v << ", ";
    }
    vec.erase(vec.begin() + i);//6 will be removed.
    for(int v : vec){
        if(v == vec.back()) std::cout << v << std::endl;
        if(v != vec.back()) std::cout << v << ", ";
    }
    
}
```
Now we need to know how to reverse a given range of a vector, we will have 2 pointers at the begin and end of the vector, swap them then move towards each other, until they meet/cross
```c++
#include<vector>
#include<iostream>
using std::vector;

void reverse(vector<int>& vec,int i, int j){
    if(vec.size() <= 1 || i >= j) return;
    while(i< j){
        int temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
        i++;
        j--;
    }
}

int main(){
    vector<int>vec = {1,3,4,6,7,9};
    //now we print it in reverse order
    vector<int> res = vec;
    int i = 0;
    int j = vec.size() - 1;
    reverse(vec,i,j);
    for(int v : res){
        if(v == res.back()) std::cout << v << std::endl;
        if(v != res.back()) std::cout << v << ", ";
    }
    for(int v : vec){
        if(v == vec.back()) std::cout << v << std::endl;
        if(v != vec.back()) std::cout << v << ", ";
    }
}
```

## Find next Lexicographically greater permutation(LGP)
__Step 1__ find the position we want to increase.\
By observation, one can reason that if we can find the non-strick descreasing order of the whole or some right part of the array, then the next LGP is by changing the element in the left. For example:
1. [4,3,2,1] no such element can be found, this is already the last/greatest permutation.
2. [6,4,5,3,2,1] we can divide it into 2 parts [6,4] [5,3,2,1], since [5,3,2,1] does not have greater permutation itself, we must consider new elements in [6,4], since the further to the left,  greater the permutation, we should choose 4 in the example(rightmost in the left part).
> Divide the array into left|right parts. right part should be already sorted(descending oder) subarray. Let the rightmost element from the left be pivot.

__Step 2__ Lets give such element a name __pivot__. We should increase pivot by swap it with the smallest element from right part which is greater than the pivot, in our case is 5. Now we have [6,5][4,3,2,1].\

__Step 3__ In step 2 we increase the element in the position discovered in step 1. Now if possible to make the right part minimal, then the result array would be next LGP. And further observation reveals that the "sorting" is simply a reverse. in our example the array becomes [6,5,1,2,3,4]. And indeed is the result we are looking for. 
>If we keep finding the next LGP, eventually we will find last Permutation which is in a non-strick descreasing order. If we start from an unsorted array, then the alogrithm is actually a sorting. We can use the mirror process to get a non-strick increasing ordered array. 

__Step 4__ __(Improvement)__. for Step 2 We can use Binary search to find the smallest element from right part which is greater than the pivot because the right part is a sorted array. __BFS when we reduce size, we should never exclude the possible candidates__
```c++
#include<vector>
#include<iostream>
using std::vector;

//Create a function using BFS to find smallest element in certain range of an sorted array
//that is greater than a given key. Return the index of that element
int BFS(vector<int>&vec, int l, int r, int key){
    int index = 0;
    while(l <= r){
        int mid = l + (l - r)/2;
        if(vec[mid] <= key){
            r = mid - 1;
        }
        else{
            l = mid + 1;
            if(index == -1 || vec[index] >= vec[mid]){//if index too big reduce it 
                index = mid;
            }
        }
    }
    return index;
}
//driver code
int main(){
    vector<int>test = {9,0,4,6,5,3,2,1};
    int key = 4;
    int idx = BFS(test,3,7,key);
    std::cout << "the key is:" << key << " and the element is : " << test[idx] << std::endl;
}

```

## Array Traversal
[go to here](../main/ArraySearchProblems/README.md)

## LinkedList Traversal
[go to here](../main/LinkedListProblems/ReadMe.md)

## C++ the language
[go to here](../main/ArraySearchProblems/HardC++/Readme.md)