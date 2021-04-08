#include<iostream>
#include<thread>

void thread_function(){
    std::cout << "thread function \n";
}

int main(){
    std::thread t(&thread_function);
    std::cout << "main_thread\n";
    if(t.joinable()){
        t.join();
    }
    //t.detach();
    return 0;
}