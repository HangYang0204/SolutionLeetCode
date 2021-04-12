#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

class Solution{
public:
	void TrainToTake(int fromStop, int toStop){
		std::unordered_map<int,std::vector<int>> ScheduleByTrain;
		ScheduleByTrain.insert({1, {0,15,25,40,60}});
		ScheduleByTrain.insert({2, {10,-1,30,-1,50}});
		ScheduleByTrain.insert({3, {15,-1,-1,-1,55}});

		int TrainNumber = 0;
		std::unordered_map<int,int> TrainTime;
		int res[3];
		for(int i = 0; i < 3; i++){
			std::vector<int> schedule = ScheduleByTrain[i + 1];
			if(schedule[fromStop - 1] < 0 || schedule[toStop - 1] < 0){
				res[i] = 100 + i;
			}
			else{
				res[i] = schedule[toStop -1] - schedule[fromStop - 1];
			}
			if(TrainTime.count(res[i])){
				TrainTime[res[i]] = i + 1;
			}
		}
		for(int j = 0; j <  3; j++){
			std::string traveltime;
			if(res[j] > 100){
				traveltime = "NA";
			}
			else{
				traveltime = std::to_string(res[j]);
			}
			std::cout << "Train " + std::to_string(j+1) + " : Travel time = " + traveltime << std::endl;
		}
	}
};

int main(){
	Solution s;
	int fromstop;
	int tostop;
	std::cout << "Type in the start stop number(1-5): " << std::endl;
	std::cin >> fromstop;
	std::cout << "Now type in the end stop number(2-5):" << std::endl;
	std::cin >> tostop;
	s.TrainToTake(fromstop,tostop);
	return 0;
}