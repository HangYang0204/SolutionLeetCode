## Morris Tree Traversal
cur point to the tree root.
When cur == nullptr the program stops. 

1. If cur has left child, find the most right node of the left child. 
2. To find the most right, you just keep moving right until hit null or cur in a loop
3. If most right's right is null, point it to cur and move cur to right then check new cur (back to step 1)  
4. If most right's right is cur, point it back to null and move cur to right then check new cur (back to step 1) 
5. If cur has no left child, move cur to right.

Ofthen 4 and 5 can be consolidated together. Uisng continue dividing code blocks in following way
```cpp
while([condition z]) //cur not NULL
{
  //find most right and check if it has been borrowed or not
  if([condition y]) // has left child ?
  {
      if([condition x]) // still idle?
      {
        //Borrow it and move cur to left
        continue      
      }
      else  
      {
        //Return it  
      }
  }
  //move cur to right
}
```
More specific way writting it would be 
```cpp
while([condition z])
{
  //find most right and check if it has been borrowed or not
  if([condition y]) // has left child ?
  {
      if([condition x]) // still idle?
      {
        //Borrow it and move cur to left
        continue      
      }
      else  
      {
        //Return it and move cur to right
        continue
      }
  }
  //move cur to right
}
```


### Key point
We start from the root, using pointer cur as a marker, by moving cur we traverse the tree.
1. Morris algo is to make use of idle pointers of the tree to save space -- O(1)
2. Using most right node -> cur or "Borrow Tree pointer" is the timing you move your cur to the left and restart from the new position.
3. When you discovered the Node's right is already cur, then we point it back to Null or "Return Tree pointer", it is the timing you want to move the cur to right and restart from the new position
