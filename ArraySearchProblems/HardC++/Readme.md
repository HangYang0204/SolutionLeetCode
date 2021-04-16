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
