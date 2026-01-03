class Solution {
    public int numOfWays(int n) {
        int MOD =1_000_000_007;
        long same=6, diff=6;

        for(int i=2; i<=n ; i++){
            long news= (same * 3 + diff *2)% MOD;
            long newd= (same * 2 + diff *2)% MOD;
            same = news;
            diff = newd;
        }
        return (int)((same+diff) % MOD);
    }
}