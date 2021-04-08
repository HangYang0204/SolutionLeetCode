#include<iostream>
#include<set>
#include<string>

class solution{
public:
    bool IsStrLengthRepeat(std::string s, int n){
        std::set<std::string> memo;
        if(!memos.empty()){
            memos.clear();
        }

        for(int i = 0; i <= s.size() - n; i++){
            std::string substr = s.substr(i,n);
            if(memo.count(substr)){
                return true;
            }
            memo.insert(substr);
            memos.insert(substr);
        }
        return false;
    }

    void printmemos(){
        for(auto it = memos.begin(); it != memos.end(); ++it){
            std::cout << *it << std::endl;
        }
    }

    int LongestRepeatSubstring(std::string s){
        //ordered list is [1,s.length-1]; smart af!
        int l = 0;
        int r = s.size() - 1;
        while(l < r){
            int mid = l + (r - l + 1)/2; // this def will previent overflow
            if(IsStrLengthRepeat(s,mid)){
                l = mid;
            }
            else{
                r = mid - 1;
            }
        }
        return l;

    }


private:
    std::set<std::string> memos;

};




int main(){
    std::string s = "abcd"; //expect to return 3
 
    solution so;
    std::cout << so.IsStrLengthRepeat(s,3) << std::endl;
    so.printmemos();
    std::cout << so.LongestRepeatSubstring(s) << std::endl;


    return 0;
}