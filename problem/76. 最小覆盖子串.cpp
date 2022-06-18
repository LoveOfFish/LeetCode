#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";                // 结果
        unordered_map<char, int> sMap;  // 存放窗口中的符合条件的字符以及字符个数
        unordered_map<char, int> tMap;  // 记录t中出现的字符以及字符个数
        int min = INT32_MAX;            // 最小值
        if (s.size() < t.size()) {
            return res;
        }
        for (int i = 0; i < t.size(); i++) {
            tMap[t[i]]++;   
        }
        for (int leftIndex = 0, rightIndex = 0; rightIndex < s.size(); rightIndex++) {
            if (tMap.find(s[rightIndex]) != tMap.end()) { // 窗口中符合条件的入sMap
                sMap[s[rightIndex]]++;
            }
            while (getStr(sMap, tMap)) { // 符合条件的则缩小窗口
                if (min > (rightIndex - leftIndex + 1)) { // 是否改变结果
                    min = rightIndex - leftIndex + 1;
                    res = s.substr(leftIndex, min);
                }
                if (tMap.find(s[leftIndex]) != tMap.end()) { // 窗口缩小
                    sMap[s[leftIndex]]--;
                }
                leftIndex++;
            }
        }
        if (min == INT32_MAX) {
            return "";
        }
        return res;
    }

    // 找到满足题目条件的最小子串
    bool getStr(unordered_map<char,int> &sMap, unordered_map<char,int> &tMap){
        for (auto it = tMap.begin(); it != tMap.end(); it++) { 
            if (sMap[it->first] < it->second) { // 比较相同字符的个数是否大于t的，不大于则不符合
                return false;
            }
        }
        return true;
    }
};