class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        from collections import Counter

        cnt = Counter(s)
        n = len(s)

        def fill_smallest(cnt):
            res = []
            for c in range(26):
                ch = chr(ord('a') + c)
                res.append(ch * cnt[ch])
            return ''.join(res)

        ans = []

        def dfs(i):
            if i == n:
                return ''.join(ans) > target

            cur = target[i]

            # Try same character first
            if cnt[cur] > 0:
                cnt[cur] -= 1
                ans.append(cur)

                if dfs(i + 1):
                    return True

                ans.pop()
                cnt[cur] += 1

            # Try a bigger character
            for c in range(ord(cur) + 1, ord('z') + 1):
                ch = chr(c)

                if cnt[ch] > 0:
                    cnt[ch] -= 1
                    ans.append(ch)

                    ans.append(fill_smallest(cnt))

                    return True

            return False

        if dfs(0):
            return ''.join(ans)

        return ""