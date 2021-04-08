#include<iostream>
#include<vector>
#include<assert.h>
#include<queue>

int main(){
    std::vector<int> v;
    v.push_back(1);
    //assert(v[0] == 0);//the danger of using assert is "deinal of service"
    std::cout << v[0] << std::endl;
    priority_queue<int> pq;
    pq.push(3);
    pq.push(4);
    pq.push(1);
    pq.push(5);
 