#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
/*
There are 5 stops for trains with the following schedule
[0, 15, 25, 40, 60]
[10, -, 30, - , 50]
[15, -, - , - , 55]
Q1: From stop A to B, find the train with earliest arrival 
Q2: If we can transfer, from A to B, find best train(s) for eariliest arrival
*/
class SolutionQ1{
public:
	int TrainToTake(int fromStop, int toStop){
		std::unordered_map<int,std::vector<int>> ScheduleByTrain;
		ScheduleByTrain.insert({1, {0,15,25,40,60}});
		ScheduleByTrain.insert({2, {10,-1,30,-1,50}});
		ScheduleByTrain.insert({3, {15,-1,-1,-1,55}});	
		std::vector<int> TrainArrival = {100};
		for(int i = 0; i < 3; i++){
			std::vector<int> Schedule = ScheduleByTrain[i + 1];
			//make sure it is a valid path 
			if(Schedule[fromStop - 1] != -1 && Schedule[toStop - 1] != -1){
				TrainArrival.push_back(Schedule[toStop - 1]);
			}
		}
		
		auto TrainIdx = std::min_element(TrainArrival.begin(),TrainArrival.end()) - TrainArrival.begin();
		int minScheduleTime = *std::min_element(TrainArrival.begin(),TrainArrival.end());
		memo[TrainIdx] = minScheduleTime;
		// for(int v : TrainArrival){
		// 	std::cout << v << std::endl;
		// }
		return TrainIdx;
		
	}
private:
	std::unordered_map<int, int> memo;//stores (train with minimal arrival time : stop)
};
 
int main(){
	SolutionQ1 s;
	int fromstop;
	int tostop;
	std::cout << "Type in the start stop number(1-5): " << std::endl;
	std::cin >> fromstop;
	std::cout << "Now type in the end stop number(2-5):" << std::endl;
	std::cin >> tostop;
	std::cout << s.TrainToTake(fromstop,tostop) << std::endl;
	//s.TrainToTake(fromstop,tostop);
	return 0;
}