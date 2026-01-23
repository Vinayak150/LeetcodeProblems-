import heapq

class Solution:
    def minimumPairRemoval(self, nums):
        n = len(nums)
        if n <= 1:
            return 0

        left = [i-1 for i in range(n)]
        right = [i+1 for i in range(n)]
        right[n-1] = -1

        alive = [True]*n
        vals = nums[:]  # current values at indices

        # initial inversion count (adjacent decreases)
        inv = 0
        for i in range(n-1):
            if vals[i] > vals[i+1]:
                inv += 1
        if inv == 0:
            return 0

        heap = []
        for i in range(n-1):
            heapq.heappush(heap, (vals[i] + vals[i+1], i))

        ops = 0

        while heap:
            s, i = heapq.heappop(heap)

            # validate pair (i, j)
            if i < 0 or i >= n or not alive[i]:
                continue
            j = right[i]
            if j == -1 or not alive[j]:
                continue

            # lazy check sum matches current values
            if vals[i] + vals[j] != s:
                continue

            # neighbors before merge
            li = left[i]
            rj = right[j]

            # remove old inversion contributions
            if li != -1 and alive[li] and vals[li] > vals[i]:
                inv -= 1
            if vals[i] > vals[j]:
                inv -= 1
            if rj != -1 and alive[rj] and vals[j] > vals[rj]:
                inv -= 1

            # merge into i
            vals[i] = s
            alive[j] = False
            right[i] = rj
            if rj != -1:
                left[rj] = i

            # add new inversion contributions
            if li != -1 and alive[li] and vals[li] > vals[i]:
                inv += 1
            if right[i] != -1 and alive[right[i]] and vals[i] > vals[right[i]]:
                inv += 1

            ops += 1
            if inv == 0:
                return ops

            # push updated adjacent pairs
            if li != -1 and alive[li]:
                heapq.heappush(heap, (vals[li] + vals[i], li))
            if right[i] != -1 and alive[right[i]]:
                heapq.heappush(heap, (vals[i] + vals[right[i]], i))

        return ops