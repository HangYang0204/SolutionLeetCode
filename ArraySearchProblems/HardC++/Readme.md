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
