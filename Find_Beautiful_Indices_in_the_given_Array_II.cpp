#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> calculateLPS(string& pattern) {
    vector<int> lps(pattern.size(), 0);
    int len = 0;
    int i = 1;

    while (i < pattern.size()) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

vector<int> findAll(string& text, string& pattern) {
    vector<int> occurrences;
    vector<int> lps = calculateLPS(pattern);
    int i = 0, j = 0;

    while (i < text.size()) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == pattern.size()) {
            occurrences.push_back(i - j);
            j = lps[j - 1];
        } else if (i < text.size() && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return occurrences;
}
vector<int> helper(vector<int>& a, vector<int>& b, int k) {
    vector<int> result;

    for (int i = 0; i < a.size(); ++i) {
        int low = lower_bound(b.begin(), b.end(), a[i] - k) - b.begin();
        int high = upper_bound(b.begin(), b.end(), a[i] + k) - b.begin();

        // Check if there are elements in the range
        if (low < high) {
            result.push_back(a[i]);
        }
    }

    return result;
}
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>posA=findAll(s,a);
        vector<int>posB=findAll(s,b);
        vector<int>ans=helper(posA,posB,k);
        return ans;
        
    }
};

int main(){
	return 0;
}