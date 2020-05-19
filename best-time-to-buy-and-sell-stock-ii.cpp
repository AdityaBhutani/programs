#include <iostream>
#include <vector>
using namespace std;

// Compare the first price(ie., i=1 and prices[1-1]) with other prices[i+1:n-1]
// We iterate until we find a value which is greater than price(prices[0] for i=1)
// Here we will call the value greater than price as gtp
// At each iteration we also find the min value which will lie between price and gtp
// That min price will represent the buying value and gtp will represent the selling value
// This is because we want to sell at the lowest price and sell at highest price
// This process is continued till the array ends
int maxProfit(vector<int>& prices) {
	int min_bw_price_and_gtp, price, total_profit = 0;
	for(int i=1; i< prices.size(); i++){
		price = prices[i-1];
		min_bw_price_and_gtp = prices[i-1];
		min_bw_price_and_gtp = min(min_bw_price_and_gtp, prices[i]);
		if(prices[i] > price){
			total_profit += prices[i] - min_bw_price_and_gtp;
		}
	}
	return total_profit;
}

int main(){
	vector<int> prices = {7,1,5,3,6,4};
	cout << maxProfit(prices);
	return 0;
}