class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double totalWaitingTime = 0;
        int currentTime = 0;
        int numberOfCustomers = customers.size();

        for(auto customer : customers) {
            int arrivalTime = customer[0];
            int prepTime = customer[1];

            if(arrivalTime < currentTime) {
                int extraWaitingTime = currentTime - arrivalTime;
                totalWaitingTime = totalWaitingTime + extraWaitingTime + prepTime;
                currentTime = currentTime + prepTime;
            }
            else {
                totalWaitingTime = totalWaitingTime + prepTime;
                currentTime = arrivalTime + prepTime;
            }
        }

        return totalWaitingTime / numberOfCustomers;
    }
};
