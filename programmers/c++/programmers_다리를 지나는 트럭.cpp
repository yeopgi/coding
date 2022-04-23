#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, currentWeight = 0;
    queue<int> currentLength, truckCntInBridge;
    while (true) {
        int size = currentLength.size();
        for (int i = 0; i < size; i++){
            int length = currentLength.front();
            currentLength.pop();
            if (length <= 1) {
                currentWeight -= truckCntInBridge.front();
                truckCntInBridge.pop();
                continue;
            }
            currentLength.push(length - 1);
        }

        if (truck_weights.size() > 0 && currentWeight + truck_weights.at(0) <= weight) {
            truckCntInBridge.push(truck_weights.at(0));
            currentWeight += truck_weights.at(0);
            currentLength.push(bridge_length);
            truck_weights.erase(truck_weights.begin());
        }

        answer++;
        if (truck_weights.size() == 0 && truckCntInBridge.size() == 0) {
            break;
        }
    }
    return answer;
}