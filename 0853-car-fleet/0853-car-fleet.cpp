class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector <pair <int , double>> cars(n);
        
        for (int i =0; i<n; ++i) {
            double time = double (target - position[i]) / speed[i];
            cars[i] = {position[i] , time};
        }
        sort(cars.rbegin() , cars.rend());
        
        stack <double> Fleets;
        for (const auto& car : cars) {
            double time = car.second;
            if (Fleets.empty() || time > Fleets.top()) {
                Fleets.push(time);
            }
        }
        return Fleets.size();
    }
};