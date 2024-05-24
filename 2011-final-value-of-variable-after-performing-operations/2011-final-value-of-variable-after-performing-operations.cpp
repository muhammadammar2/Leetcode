class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int answer =0;
        for (int i=0; i<operations.size(); i++){
            if (operations[i] == "X++" || operations[i] == "++X") {answer++;}
            else if (operations[i] == "X--" || operations[i] == "--X") {answer--;}
        }
        return answer;
    }
};