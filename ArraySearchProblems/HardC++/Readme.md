## The not so much fun part of C++
C++ is a beautiful language, but some concepts within C++ are very difficult for beginners to understand. Here I will share some notes about those I think are difficult to understand/memorize when I encountered them and try to explain them with (kind of) my own words. 

## The messy const 
__const key words applies to its immediate left, if none found then to its immediate right.__ for example 
`const int a = 96` here const describes int. this line of code means variable a is a const. it has to be initialise immediately and shall not be changed later ever. 
```c++
    const int * b = 1;
    int const* b = 1;
    int* mypointer = 2;
```
Applying the rule we know that the above 2 are the same. they both mean variable pointer to constant int. and thus `*b = 2` is not allowed however we are free to change the memory address `b = mypointer`. 
```c++
    int* a = 1;
    int* mypointer = 2;
    int* const c = a;
```
This means a const pointer to a variable int. thus `*c = 2` is ok but `c = mypointer` is not allowed. 

## const with functions
its pretty much the same see below:
```c++
    //const in function parameter passing
    functionA(const int val){}; //val is immutable within the function
    functionB(const char* val){}; //the val value can not be changed
    functionC(char* const val){};//the pointer point to val is const
    //const as function return 
    const int functionD(){return 1;};
```
## Array
Array is a list of variables in a given range of memory. There are 2 ways to define array: 1. On stack 2. On heap. they have different lifetime. if created by new key words, remember to deletep[] it. 
```c++
    int myArray[5];//created on stack
    int* p = myArray; //this indicates an array is a [type] pointer. 
    int* another = new int[5];//created on heap
    delete[] another;//remember to destory it to allocate memory. 
```
more array and pointer examples:
```c++
    int myArray[5];
    for(int i = 0; i < 5; i++)
        myArray[i] = 2;
    int* p = myArray;
    *(p + 2) = 6;// == myArray[2] = 6
    //here is a small take away
    *(int*)((char*)p + 8) = 6; //char is 1 byte while int is 4 byte thus 8. 
    //above (int*)8 = 2 
    std::cout << myArray[2];

```
So using an array one must alwasy maintain its size. If you want to have an array member in your class, you can maintain the size using static and const:
```c++
class ArrayEntity{
public:
    static const count = 5;
    int myArray[count];

};
```
after c++11 we have array in the STL see below:
```c++
#include<array>
std::array<int,5> myArray;
//now one can use size() like a container
for(int i = 0; i < myArray.size(); i++)
    myArray[i] = 2;
```
## Function pointer
Function pointer is way to assign a function to a variable. See below example to see the usages:
```c++
#include<vector>
#include<iostream>

void PrintValue(int value){
    std::cout << "Value: " << value << std::endl;
}

void ForEach(std::vector<int>& values, void(*func)(int)){
    for(int value : values){
        func(value);
    }
}

int main(){
    std::vector<int> values = {1,2,3,4,6};
    ForEach(values,PrintValue);
}
```
see how concise the expression become for the "might be" difficult idea at first thought. 

## 2D array
A 2D array is an array pointer of type array. 
```c++
#include<iostream>

int* array = new int[5];// 1D array of size 5
int** aray2D = new int*[5];// 1D array of array -> 2D array. 
for(int x = 0; x < 5; x ++){
    for(int y = 0; y < 5; y++){
        array2D[x][y] = 2;
    }
}
//to delete 2D array one should delete the 25 int data in the memory lake 
//then destory the pointer array:
for(int i = 0; int i < 5; i++){
    delete[] array2D[i];
}
delete[] array2D[];
```
The 2D array defined in above code only allocate 5 * 4 = 20 byte memory. The y loop just define the array int type data, the x loop defines the array each of those 5 pointers would point to. It causes memory fragement and poor in performance. 

One can actually use 1D array instead, see below:
```c++
int* array = new int[5*5];
for(int x = 0; x < 5*5; x++){
    for(int y = 0; y < 5; y++){
        array[x + y*5] = 2;
  }
}
```
With the idea above one can wrap it into a class to make it easier to understand. 
```c++
class Matrix
{
    
    size_t index( int x, int y ) const { return x + m_width * y; }
};
```
or use STL vector :) 
```c++
#include<vector>
using std::vector;

vector<vector<int>> array2D(5, vector<int>(5)); //a 5 * 5 2D array

```
Unless you are not allowed to use STL, just use vector container!

## Lambdas
Whenever you have a function pointer, you can use Lambdas, defines a function without define a function. 
```c++
auto lambda = [](int value){cout << "value" << value << endl;};
ForEach(values, lambda);

```
In previous example, we used function pointer in the definition of ForEach ```ForEach(vector<int>& values, void(*func)(int))```
now one can simply using a lambda to replace it. You don't need to write the function```PrintValue``` seperately.  