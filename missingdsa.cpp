#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

// Function to detect if a string is a number
bool isNumber(string s) {
    return isdigit(s[0]) || (s.size() > 1 && isdigit(s[1]));
}

// Function to find the most common difference (for sequences like 2 4 6 10)
int getCommonDifference(const vector<int>& v) {
    vector<int> diffs;
    for (size_t i = 1; i < v.size(); i++) {
        diffs.push_back(v[i] - v[i - 1]);
    }
    // Choose the minimum frequency diff
    sort(diffs.begin(), diffs.end());
    return diffs[0];
}

// Function to find missing numbers
void findMissingNumbers(vector<int> nums) {
    sort(nums.begin(), nums.end());
    int diff = getCommonDifference(nums);

    for (int i = nums[0]; i <= nums.back(); i += diff) {
        if (find(nums.begin(), nums.end(), i) == nums.end()) {
            cout << i << " is missing." << endl;
        }
    }
}

// Function to find missing letters
void findMissingLetters(vector<char> chars) {
    sort(chars.begin(), chars.end());
    int diff = chars[1] - chars[0];

    for (char ch = chars[0]; ch <= chars.back(); ch += diff) {
        if (find(chars.begin(), chars.end(), ch) == chars.end()) {
            cout << ch << " is missing." << endl;
        }
    }
}

int main() {
    string input;
    cout << "Enter your sequence (space-separated, e.g., 2 4 6 10 or a c e): ";
    getline(cin, input);

    stringstream ss(input);
    string word;
    vector<int> numbers;
    vector<char> letters;

    while (ss >> word) {
        if (isNumber(word)) {
            numbers.push_back(stoi(word));
        } else if (isalpha(word[0])) {
            letters.push_back(word[0]);
        }
    }

    if (!numbers.empty()) {
        findMissingNumbers(numbers);
    } else if (!letters.empty()) {
        findMissingLetters(letters);
    } else {
        cout << "Invalid input!" << endl;
    }

    return 0;
}
