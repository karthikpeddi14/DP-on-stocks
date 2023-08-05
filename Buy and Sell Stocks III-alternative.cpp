// using trans no
// memo
class Solution {
public:
    int f(vector<int>& prices, int index, int transno, vector<vector<int>>& dp)
    {
        if(index==prices.size() || transno==4) return 0;
        if(dp[index][transno]!=-1) return dp[index][transno];
        if(transno%2==0)
        {
            return dp[index][transno] = max(-prices[index]+f(prices,index+1,transno+1,dp),f(prices,index+1,transno,dp));
        }
        return dp[index][transno] = max(prices[index]+f(prices,index+1,transno+1,dp), f(prices,index+1,transno,dp));

    }
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(4,-1));
        return f(prices,0,0,dp);
    }
};
// memo

// tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(5,0));
        
        for(int ind=n-1 ; ind>=0 ; ind--)
        {
            for(int transno=0 ; transno<4 ; transno++)
            {
                if(transno%2==0)
                dp[ind][transno] = max(-prices[ind] + dp[ind+1][transno+1],dp[ind+1][transno]);
                else
                dp[ind][transno] = max(prices[ind] + dp[ind+1][transno+1], dp[ind+1][transno]);
            }
        }
        return dp[0][0];
    }
};
// tabulation

// space opti
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<int> next(5,0),cur(5,0);
        
        for(int ind=n-1 ; ind>=0 ; ind--)
        {
            for(int transno=0 ; transno<4 ; transno++)
            {
                if(transno%2==0)
                cur[transno] = max(-prices[ind] + next[transno+1],next[transno]);
                else
                cur[transno] = max(prices[ind] + next[transno+1], next[transno]);
            }
            next = cur;
        }
        return next[0];
    }
};
// space opti
