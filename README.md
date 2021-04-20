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
## Array Traversal
[go to here](../main/ArraySearchProblems/README.md)

## LinkedList Traversal
[go to here](../main/LinkedListTraversal/ReadMe.md)
