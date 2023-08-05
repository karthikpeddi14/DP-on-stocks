//memo
class Solution {
public:
    int f(vector<int>&prices, int index,int buy, vector<vector<int>>& dp)
    {
        if(index>=prices.size()) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy)
        {
            return dp[index][buy] = max(-prices[index]+f(prices,index+1,0,dp),f(prices,index+1,1,dp));
        }
        return dp[index][buy] = max(prices[index]+f(prices,index+2,1,dp),f(prices,index+1,0,dp));
    }
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(prices,0,1,dp);
    }
};
//memo

// tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int index=n-1 ; index>=0 ; index--)
        {
            for(int buy=0 ; buy<2; buy++)
            {
                if(buy)
                dp[index][buy] = max(-prices[index]+dp[index+1][0],dp[index+1][1]);
                else
                dp[index][buy] = max(prices[index]+dp[index+2][1],dp[index+1][0]);
            }
        }
        return dp[0][1];
    }
};
// tabulaion

// space opti
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<int> later(2,0), next(2,0),cur(2,0);
        for(int index=n-1 ; index>=0 ; index--)
        {
            for(int buy=0 ; buy<2; buy++)
            {
                if(buy)
                cur[buy] = max(-prices[index]+next[0],next[1]);
                else
                cur[buy] = max(prices[index]+later[1],next[0]);
            }
            later = next;
            next = cur;
        }
        return cur[1];
    }
};
//space opti
