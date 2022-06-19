#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()){
            return vector<int>();
        }
        int up = 0;
        int down = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        vector<int> ret;
        
        while(1){
            for(int i = left; i <= right; i++){
                ret.push_back(matrix[up][i]);
            }
            if(++up > down){
                break;
            }

            for(int j = up; j <= down; j++){
                ret.push_back(matrix[j][right]);
            }
            if(--right < left){
                break;
            }

            for(int i = right; i >= left; i--){
                ret.push_back(matrix[down][i]);
            }
            if(--down < up){
                break;
            }

            for(int j = down; j >= up; j--){
                ret.push_back(matrix[j][left]);
            }
            if(++left > right){
                break;
            }
        }
        return ret;
    }
};