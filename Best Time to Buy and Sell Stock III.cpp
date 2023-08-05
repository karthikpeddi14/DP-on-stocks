// my approach memo
class Solution {
public:
    int f(vector<int>& prices, int index, int count , int buy,vector<vector<vector<int>>>& dp)
    {
        if(index==prices.size()) return 0;
        if(dp[index][buy][count]!=-1) return dp[index][buy][count];
        int profit=0;
        if(count<2)
        {
            if(buy)
            profit = max(-prices[index]+f(prices,index+1,count,0,dp),f(prices,index+1,count,1,dp));
            else
            profit = max(prices[index]+f(prices,index+1,count+1,1,dp),f(prices,index+1,count,0,dp));
        }
        return dp[index][buy][count] = profit;
    }
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int>(3,-1)));
        return f(prices,0,0,1,dp);
    }
};
// memo

// striver memo
class Solution {
public:
    int f(vector<int>& prices, int index, int cap , int buy,vector<vector<vector<int>>>& dp)
    {
        if(cap==0 || index==prices.size()) return 0;
        if(dp[index][buy][cap]!=-1) return dp[index][buy][cap];
        if(buy) 
        return dp[index][buy][cap] = max(-prices[index]+f(prices,index+1,cap,0,dp),f(prices,index+1,cap,1,dp));

        return dp[index][buy][cap] = max(prices[index]+f(prices,index+1,cap-1,1,dp),f(prices,index+1,cap,0,dp));
    }
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int>(3,-1)));
        return f(prices,0,2,1,dp);
    }
};
// striver memo

// tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(3,0)));

        for(int ind=n-1; ind>=0 ; ind--)
        {
            for(int buy=0 ; buy<2 ; buy++)
            {
                for(int cap=1; cap<3 ; cap++)
                {
                    if(buy) 
                    dp[ind][buy][cap] = max(-prices[ind]+dp[ind+1][0][cap],dp[ind+1][1][cap]);
                    else
                    dp[ind][buy][cap] = max(prices[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
                }
            }
        }
        return dp[0][1][2];
    }
};
// tabulation

// space opti
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<vector<int>> next(2,vector<int>(3,0)), cur(2,vector<int>(3,0));

        for(int ind=n-1; ind>=0 ; ind--)
        {
            for(int buy=0 ; buy<2 ; buy++)
            {
                for(int cap=1; cap<3 ; cap++)
                {
                    if(buy) 
                    cur[buy][cap] = max(-prices[ind]+next[0][cap],next[1][cap]);
                    else
                    cur[buy][cap] = max(prices[ind]+next[1][cap-1],next[0][cap]);
                }
            }
            next = cur;
        }
        return next[1][2];
    }
};
// space opti
