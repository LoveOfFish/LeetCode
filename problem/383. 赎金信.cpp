#include<iostream>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int arr[26] = {0};
        for (int i = 0; i < ransomNote.size(); i++) {
            arr[ransomNote[i] - 'a']--;
        }
        for (int j = 0; j < magazine.size(); j++) {
            arr[magazine[j] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (arr[i] < 0) {
                return false;
            }
        }
        return true;
    }
};