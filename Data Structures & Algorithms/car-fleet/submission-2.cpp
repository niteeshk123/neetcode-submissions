class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        int n = speed.size();
        for(int i=0; i<n; i++){
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), [](pair<int, int> a, pair<int,int> b){return a.first > b.first;});

        float prev = -1;
        int count = 0;
        for(auto car:cars){
            int d = target-car.first;
            int v = car.second;
            double  t = (double)d/v;
            // cout << " t = "<<t<<endl;
            if(prev == -1){
                count ++;
                prev = t;
            } else {
                if(t<=prev){
                    // do nothing
                } else {
                    count++;
                    prev = t;
                }
            }
        }

        return count;
    }

};
