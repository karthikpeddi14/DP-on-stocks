// from prev codes
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n=prices.size();
        vector<int> next(2,0),cur(2,0);
        
        for(int i=n-1; i>=0 ; i--)
        {
            int profit = 0;
            for(int j=0 ; j<2; j++)
            {
                if(j)
                profit = max(-prices[i]+next[0],next[1]); 
                else
                profit = max(prices[i]+next[1]-fee,next[0]);
                cur[j] = profit;
            }
            next = cur;
        }
        return next[1];
    }
};
// from prev codes
