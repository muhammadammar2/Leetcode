class Solution {
private:
    unordered_map<int, string> below20{
        {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"},
        {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"},
        {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"},
        {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}  
    };
    unordered_map<int, string> tens{
        {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"},
        {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}
    };
    vector<string> thousands{"", "Thousand", "Million", "Billion"};
    
    string convertChunk(int num) {
        if (num == 0) return "";
        else if (num < 20) return below20[num] + " ";
        else if (num < 100) return tens[num / 10 * 10] + (num % 10 ? " " + below20[num % 10] : "") + " ";
        else return below20[num / 100] + " Hundred " + convertChunk(num % 100);
    }

public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        int i = 0;
        string words = "";
        while (num > 0) {
            if (num % 1000 != 0) {
                words = convertChunk(num % 1000) + thousands[i] + (words.empty() ? "" : " ") + words;
            }
            num /= 1000;
            ++i;
        }
        while (!words.empty() && words.back() == ' ') {
            words.pop_back();
        }
        return words;
    }
};
