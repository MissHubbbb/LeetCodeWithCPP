#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;

void combinationChar(vector<string>& combinations, const unordered_map<char, string> &phoneMap, int index, string& digits, string& combination) {
    int n = digits.length();
    if (index == n) {
        combinations.push_back(combination);
    }
    else {
        string cur = phoneMap.at(digits[index]);
        for (char letter : cur) {
            combination.push_back(letter);
            combinationChar(combinations, phoneMap, index + 1, digits, combination);
            combination.pop_back();
        }
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> combinations;

    unordered_map<char, string> phoneMap = {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };

    string combination;
    combinationChar(combinations, phoneMap, 0, digits, combination);
    return combinations;
}

void main2() {
    string te = "23";
    vector<string> t(letterCombinations(te));
    for (string e : t) {
        cout << e << endl;
    }
}