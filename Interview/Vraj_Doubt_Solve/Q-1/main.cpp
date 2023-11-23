#include <bits/stdc++.h>
using namespace std;
int main() {
    map<string, string> mp = {
        {"a", "India"},
        {"101", "USA"},
        {"231", "Pakistan"},
        {"arg", "Argentina"},
        {"c", "Bhutan"},
        {"X", "Sri Lanka"},
        {"D", "India"},
        {"34", "Australia"}
    };

    vector<string> numericKeys;
    vector<string> nonNumericKeys;

    for (const auto& pair : mp) {
        const std::string& key = pair.first;
        bool isNumeric = true;

        for (char c : key) {
            if (!std::isdigit(c)) {
                isNumeric = false;
                break;
            }
        }

        if (isNumeric) {
            numericKeys.push_back(key);
        } else {
            nonNumericKeys.push_back(key);
        }
    }


   sort(numericKeys.begin(), numericKeys.end(), [](const string& a, const string& b) {
        return stoi(a) < stoi(b);
    });


    sort(nonNumericKeys.begin(), nonNumericKeys.end());


    for (const auto& key : numericKeys) {
        cout << "Key: " << key << ", Value: " << mp[key] <<endl;
    }

    for (const auto& key : nonNumericKeys) {
        cout << "Key: " << key << ", Value: " << mp[key] << endl;
    }

    return 0;
}
