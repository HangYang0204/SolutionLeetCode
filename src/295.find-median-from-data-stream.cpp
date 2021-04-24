/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
public:
    void addNum(int num) {
        //we will add numers to heaps
        lo.push(num);
        hi.push(lo.top());//lo top has maximal element
        lo.pop();
        if(hi.size() > lo.size()){ //balance the size allowing size(lo) = size(hi) + 1/0
            lo.push(hi.top()); //hi top has minimal element
            hi.pop();
        }
    }
    
    double findMedian() {
        return (lo.size() > hi.size())? lo.top() : ((double)lo.top() + hi.top())*0.5;
    }
private:
    priority_queue<int> lo; //max heap
    priority_queue<int, vector<int>, greater<int>> hi;//min heap
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

