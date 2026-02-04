class Solution:
    def maxSumTrionic(self, nums):
        n = len(nums)
        if n < 4:
            return -1

        INF = 10**15

        # inc  : increasing subarray ending here (len >= 1)
        # up   : increasing subarray ending here (len >= 2)
        # down : up -> down ending here (down len >= 2)
        # tri  : up -> down -> up ending here (last up len >= 2)

        inc = nums[0]
        up = -INF
        down = -INF
        tri = -INF

        ans = -INF

        for i in range(1, n):
            val = nums[i]
            prev = nums[i - 1]

            next_inc = -INF
            next_up = -INF
            next_down = -INF
            next_tri = -INF

            # 1) inc: increasing len >= 1
            if val > prev:
                next_inc = max(val, inc + val)
            else:
                next_inc = val

            # 2) up: increasing len >= 2
            if val > prev:
                if inc > -INF:
                    next_up = inc + val

            # 3) down: up -> down, down len >= 2
            if val < prev:
                if down > -INF:
                    next_down = max(next_down, down + val)
                if up > -INF:
                    next_down = max(next_down, up + val)

            # 4) tri: up -> down -> up, last up len >= 2
            if val > prev:
                if tri > -INF:
                    next_tri = max(next_tri, tri + val)
                if down > -INF:
                    next_tri = max(next_tri, down + val)

            inc = next_inc
            up = next_up
            down = next_down
            tri = next_tri

            ans = max(ans, tri)

        return ans if ans != -INF else -1
