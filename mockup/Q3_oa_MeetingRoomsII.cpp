#include<vector>
#include<algorithm>
#include<iostream>

using std::vector;
using std::sort;
using std::max;
using std::cout;
/*
Question
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] 
(si < ei), find the minimum number of conference rooms required.

For example, Given [[0, 30],[5, 10],[15, 20]], return 2.
*/

class MeetingInterval{
public:
    int minMeetingRoom(vector<vector<int>>meetings){
        auto comp = [](vector<int>n1, vector<int>n2){return n1[0] < n2[0];};
        //sort intervals by start time
        sort(meetings.begin(), meetings.end(),comp);
        int count = 1, i = 0, j = 1;
        vector<int> curinterval = meetings[0];//used to merge
        for(; j < meetings.size(); ++j){
            if(meetings[i][1] <= meetings[j][0]){
                i = j;
                curinterval[0] = meetings[j][0];
                curinterval[1] = meetings[j][1]; 
                count++;
            }else{
                curinterval[1] = max(curinterval[1],meetings[j][1]);
                meetings[i][0] = curinterval[0];
                meetings[i][1] = curinterval[1];
            }
        }
        return meetings.size() - count;
    }
};

int main(){
    vector<vector<int>> meeting = {{0, 30},{5, 10},{15, 20}};
    MeetingInterval mi;
    cout << mi.minMeetingRoom(meeting) << "\n";
    return 0;
}