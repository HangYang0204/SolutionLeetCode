#include <iostream>
#include <vector>
using namespace std;

int findMax(vector<int> nums, int left, int right)
{
    if(right < left)
        return -1;

    int result = INT_MIN;
    for(int i = left; i <= right; i++)
    {
        if(nums[i] > result)
            result = nums[i];
    }

    return result;
}


int processorSolver(vector<int> B, vector<int> P, long maxP)
{    
    if(B.size() <= 0 || P.size() <= 0)
        return 0;
    
    int left = 0, right = 0;
    long result = 0;

    while(right < B.size() && right >= left)
    {
        //window size
        int k = right - left;
        //add max boot power    
        long power = 0;
        power += findMax(B, left, right);
        //add the sum of processor power * k
        for(int i = left; i<= right; i++)
            power += P[i]*(right - left + 1);
        //expand window condition
        if(power <= maxP)
        {
            right++;
            result = result > power ? result : power;
        }
        //shrink window condition
        else 
            left++;
    }

    return result;
}



int main()
{
    static const int bP[] = {3, 6, 1, 3, 4};
    vector<int> bootingPower(bP, bP + sizeof(bP) / sizeof(bP[0]));
    static const int pP[] = {2, 1, 3, 4, 5};
    vector<int> processorPower(pP, pP + sizeof(pP) / sizeof(pP[0]));
    long maxPower = 25;
    long res = processorSolver(bootingPower, processorPower,maxPower);
    cout << res;

}