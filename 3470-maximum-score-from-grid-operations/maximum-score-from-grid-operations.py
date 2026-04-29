class Solution:
    def maximumScore(self, grid: List[List[int]]) -> int:
        n = len(grid)
        
        prefix = [[0] * (n + 1) for _ in range(n)]
        for j in range(n):
            for i in range(1, n + 1):
                prefix[j][i] = prefix[j][i-1] + grid[i-1][j]
        
        NEG_INF = float('-inf')
        dp = [[NEG_INF] * (n + 1) for _ in range(n + 1)]
        for hCur in range(n + 1):
            dp[0][hCur] = 0  # virtual left boundary col has height 0
        
        for j in range(1, n):
            new_dp = [[NEG_INF] * (n + 1) for _ in range(n + 1)]
            for hCur in range(n + 1):
                # suf_with_p[k] = max over hPrev>=k of (dp[hPrev][hCur] + prefix[j-1][hPrev])
                # suf_dp[k]     = max over hPrev>=k of  dp[hPrev][hCur]
                suf_with_p = [NEG_INF] * (n + 2)
                suf_dp     = [NEG_INF] * (n + 2)
                for hPrev in range(n, -1, -1):
                    v = dp[hPrev][hCur]
                    suf_with_p[hPrev] = suf_with_p[hPrev + 1]
                    suf_dp[hPrev]     = suf_dp[hPrev + 1]
                    if v != NEG_INF:
                        suf_with_p[hPrev] = max(suf_with_p[hPrev], v + prefix[j-1][hPrev])
                        suf_dp[hPrev]     = max(suf_dp[hPrev], v)
                
                # pre[k] = max over hPrev in [0,k) of dp[hPrev][hCur]
                pre = [NEG_INF] * (n + 2)
                for hPrev in range(n + 1):
                    pre[hPrev + 1] = pre[hPrev]
                    v = dp[hPrev][hCur]
                    if v != NEG_INF:
                        pre[hPrev + 1] = max(pre[hPrev + 1], v)
                
                for hNext in range(n + 1):
                    best = NEG_INF
                    
                    # Case A1: hPrev >= max(hNext, hCur+1) → score = prefix[j-1][hPrev] - prefix[j-1][hCur]
                    lo = max(hNext, hCur + 1)
                    if suf_with_p[lo] != NEG_INF:
                        best = max(best, suf_with_p[lo] - prefix[j-1][hCur])
                    
                    # Case A2: hNext <= hPrev <= hCur → score = 0, just propagate state
                    if hNext <= hCur and suf_dp[hNext] != NEG_INF:
                        best = max(best, suf_dp[hNext])
                    
                    # Case B: hPrev < hNext → score = prefix[j-1][hNext] - prefix[j-1][hCur]
                    if pre[hNext] != NEG_INF:
                        sc = prefix[j-1][hNext] - prefix[j-1][hCur] if hNext > hCur else 0
                        best = max(best, pre[hNext] + sc)
                    
                    if best != NEG_INF:
                        new_dp[hCur][hNext] = max(new_dp[hCur][hNext], best)
            dp = new_dp
        
        # Score last column: only left neighbor matters (right boundary = height 0)
        ans = 0
        for hPrev in range(n + 1):
            for hCur in range(n + 1):
                if dp[hPrev][hCur] == NEG_INF:
                    continue
                sc = prefix[n-1][hPrev] - prefix[n-1][hCur] if hPrev > hCur else 0
                ans = max(ans, dp[hPrev][hCur] + sc)
        return ans