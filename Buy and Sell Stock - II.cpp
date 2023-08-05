// my memo approach
class Solution {
public:
    int f(vector<int>& prices, int index, int bought,vector<vector<int>>& dp)
    {
        if(index==prices.size()) return 0;
        if(dp[index][bought+1]!=-1) return dp[index][bought+1];
        int buy_now = 0;
        int sell_now = 0;
        if(bought==-1) buy_now = f(prices,index+1,prices[index],dp);
        if(bought!=-1) sell_now = prices[index]-bought + f(prices,index+1,-1,dp);
        int neither = f(prices,index+1,bought,dp);

        return dp[index][bought+1] = max(max(buy_now,sell_now),neither);
    }
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (10002,-1));
        return f(prices,0,-1,dp);
    }
};
// my memo approach

// striver memo
class Solution {
public:
    int f(vector<int>& prices, int index, int BuyOrSell,vector<vector<int>>& dp)
    {
        if(index==prices.size()) return 0;
        if(dp[index][BuyOrSell]!=-1) return dp[index][BuyOrSell];
        int profit = 0;

        if(BuyOrSell)
        profit = max(-prices[index] + f(prices,index+1,0,dp), f(prices,index+1,1,dp)); 
        else
        profit = max(prices[index]+f(prices,index+1,1,dp),f(prices,index+1,0,dp));

        return dp[index][BuyOrSell] = profit;
    }
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return f(prices,0,1,dp);
    }
};
// striver memo

// tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,0));
        
        for(int i=n-1; i>=0 ; i--)
        {
            int profit = 0;
            for(int j=0 ; j<2; j++)
            {
                if(j)
                profit = max(-prices[i]+dp[i+1][0],dp[i+1][1]); 
                else
                profit = max(prices[i]+dp[i+1][1],dp[i+1][0]);
                dp[i][j] = profit;
            }
        }
        return dp[0][1];
    }
};
// tabulation

 // space opti
class Solution {
public:
    int maxProfit(vector<int>& prices) 
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
                profit = max(prices[i]+next[1],next[0]);
                cur[j] = profit;
            }
            next = cur;
        }
        return next[1];
    }
};
// space opti;
