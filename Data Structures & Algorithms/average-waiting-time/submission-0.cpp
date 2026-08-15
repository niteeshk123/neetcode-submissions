class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double avg_wait = 0;
        double chef_time = 0;
        double wait_time = 0;
        for(auto cust:customers){
            if(chef_time>cust[0])
                wait_time+=(chef_time-cust[0]);
            wait_time+=cust[1];
            if(chef_time<cust[0]){
                chef_time=cust[0];
            }
            chef_time+=cust[1];
        }

        avg_wait = wait_time/(customers.size());
        return avg_wait;
    }
};