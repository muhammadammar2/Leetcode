class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector <pair <int , string>> Vv;
        int n = names.size();
        for (int i=0; i<n; ++i) {
            Vv.push_back({heights[i] , names[i]});
        }
        sort(Vv.rbegin() , Vv.rend());
        vector <string> vV;
        for (auto const& p : Vv) {
            vV.push_back(p.second);
        }
        return vV;
    }
};