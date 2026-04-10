class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size();

        // Step 1: Pair position with time to reach target
        vector<pair<int, double>> cars;

        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Step 2: Sort by position
        sort(cars.begin(), cars.end());

        int fleets = 0;
        double prevTime = 0;

        // Step 3: Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            double currTime = cars[i].second;

            // If current car takes more time → new fleet
            if (currTime > prevTime) {
                fleets++;
                prevTime = currTime;
            }
        }

        return fleets;
    }
};
