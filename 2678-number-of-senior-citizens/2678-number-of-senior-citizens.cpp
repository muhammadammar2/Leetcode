class Solution {
public:
    int countSeniors(vector<string>& details) {
        int c = 0;
       for (const string& d : details) {
           char aa = d[11];
           char bb = d[12];
           int age = (aa - '0') * 10 + (bb - '0');
           if (age > 60) c++;
       }
        return c;
    }
};