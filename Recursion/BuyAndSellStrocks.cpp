#include <iostream>
using namespace std;

class Solution {
public:

    void solve(vector<int>& prices, int i, int &minPrices, int &maxProfit){

        //base case
        if(i >= prices.size()){
            return ;
        }


        //processing  - 1 case
        if(prices[i] < minPrices) {
            minPrices = prices[i];
        }

        int todayProfit = prices[i] - minPrices;

        if(todayProfit > maxProfit){
            maxProfit = todayProfit;
        }

        // recursive call
        solve(prices, i+1, minPrices, maxProfit);


    }

    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;

        int i = 0;
        
        solve(prices, i , minPrice, maxProfit);

        return maxProfit;
    }
};