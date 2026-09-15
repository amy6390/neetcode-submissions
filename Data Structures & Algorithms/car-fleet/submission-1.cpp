class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back(make_pair(position[i], speed[i]));
        }
        sort(cars.begin(), cars.end());

        stack<double> times;
        for (int i = 0; i < cars.size(); i++) {
            int p = cars[i].first, s = cars[i].second;
            double time_to_finish = (double)(target - p) / (double)s;
            
            while (!times.empty() && times.top() <= time_to_finish) {
                times.pop();
            }
            times.push(time_to_finish);
        }

        return times.size();
    }
};
