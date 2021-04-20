/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /* input : 16875  output : 17568
        step 1: find pivot(6)   16|875
        step 2: find rightmost ele from right part greater than pivot(6)
        step 3: swap them 17|865
        step 4: reverse right part 17568
        special cases:
        1. empty array  do nothing
        2. size of array 1 do nothing
        3. duplicates. case by case
        */
        const int MAX = nums.size() - 1;
        if(MAX <= 0) return;
        //step 1. find pivot
        int i = MAX;
        while(i > 0 && nums[i - 1] >= nums[i]){ //if duplicates, walk over 
           i--;
        }
        //step 2. find rightmost ele greater than pivot nums[i - 1]
        if(i != 0){ 
            int pivot = nums[i - 1];
            int j = MAX;
            while(nums[j] <= pivot){//if dupliates 16|865 swap(6,6) leads wrong. 
               j--;
            }
        //step 3. swap the 2 eles we found
            nums[i - 1] = nums[j];
            nums[j] = pivot;
        }
        //step 4. reverse the right part of the array
        reverse(nums,i,MAX);
    } 
private:
    //will reverse the given range from vector. 
    void reverse(vector<int>&nums, int i, int j){
        if(nums.size() <= 0 || i >= j) return;
        while(i < j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
};
// @lc code=end

