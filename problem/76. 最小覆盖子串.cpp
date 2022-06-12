class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()){
            return "";
        }
        int slowIndex = 0;
        int fastIndex = 0;
        int min = INT32_MAX;    // 最小子串的大小
        string ret = "";
        bool flag = false;      // 表示最小子串中没有包含全部 t子串 的字符
        unordered_map<char,int> tMap;   // 记录t中个字符出现的个数
        unordered_map<char,int> sMap;
        for (int i = 0; i < t.size(); i++){
            tMap[t[i]]++;
        }
        for (; fastIndex < s.size(); fastIndex++){
            if(tMap.find(s[fastIndex]) != tMap.end()){
                sMap[s[fastIndex]]++;
                //cout<<"s[fastIndex]: "<<s[fastIndex]<<"  tMap[s[fastIndex]]: "<<tMap[s[fastIndex]]<<endl;
            }
            
            while(getStr(sMap, tMap)){   // 如果找到最小子串，则慢指针往前移动，缩小窗口
                //cout<<"进来啦"<<endl;
                if(min > (fastIndex - slowIndex + 1)){
                    min = fastIndex - slowIndex + 1;
                    //cout<<"min: "<<min<<endl;
                    ret = s.substr(slowIndex, min);
                    //cout<<"min: "<<min<<" ret: "<<ret<<endl;
                }
                
                if(tMap.find(s[slowIndex]) != tMap.end()){
                    sMap[s[slowIndex]]--;
                }  
                slowIndex++; 
            }
        }
        if(min == INT32_MAX){
            return "";
        }
        return ret;
    }

    // 找到满足题目条件的最小子串
    bool getStr(unordered_map<char,int> &sMap, unordered_map<char,int> &tMap){
        for(auto it = tMap.begin(); it != tMap.end(); it++){
            //cout<<it->second<<" ";
            if(sMap[it->first] < it->second){
                return false;
            }
            
        }
        //cout<<endl;
        // cout<<"flag: "<<flag<<endl;
        return true;
    }
};