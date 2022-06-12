#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int k = 2;
        int leftIndex = 0;
        int ret = 0;
        unordered_map<int, int> basket;
        for (int rightIndex = 0; rightIndex < fruits.size(); rightIndex++) {
            basket[fruits[rightIndex]]++;
            while (basket.size() > k) {
                basket[fruits[leftIndex]]--;
                if(basket[fruits[leftIndex]] == 0){
                    basket.erase(fruits[leftIndex]);
                }
                leftIndex++;
            }
            ret = max(ret, rightIndex - leftIndex + 1);
        }
        return ret;
    }
};