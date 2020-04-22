// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/
#include<iostream>
#include<vector>
using namespace std;

// We iterate over the given array with index "i" and find the minimum price till "i"
// We check if the difference between prices[i] and the present minimum price is greater than the max profit
// if the present minimum price is greater than the max profit then we set the calculated difference as the new max profit
int maxProfit(vector<int> &prices){
	int min_price = INT_MAX;
	int max_profit = 0;
	for(int i=0;i<prices.size();i++){
		if(prices[i] < min_price){
			min_price = prices[i];
		}
		if(prices[i] - min_price > max_profit){
			max_profit = prices[i] - min_price;
		}
	}
	return max_profit;
}

int main(){
	vector<int> prices = {7,1,5,3,6,4};
	cout << maxProfit(prices);
}