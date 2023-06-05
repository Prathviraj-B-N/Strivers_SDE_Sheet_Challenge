#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){

    int buyidx = 0;
    int maxProfit = INT_MIN;
    int sellidx = -1;

    for(int i = 1; i< prices.size(); i++){
        if(prices[i] - prices[buyidx] > maxProfit){
            sellidx = i;
            maxProfit = prices[i] - prices[buyidx];
        }
        if(prices[i] < prices[buyidx]) buyidx = i;
    }

    return (maxProfit < 0)?0:maxProfit;
}