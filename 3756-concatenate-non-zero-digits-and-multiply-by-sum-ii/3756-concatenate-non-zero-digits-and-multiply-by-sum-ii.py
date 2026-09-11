class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        MOD = 10**9 + 7
        n = len(s)

        # Prefix:
        # val[i] = number formed by non-zero digits in s[0:i]
        # cnt[i] = number of non-zero digits in s[0:i]
        # sm[i]  = sum of non-zero digits in s[0:i]
        val = [0] * (n + 1)
        cnt = [0] * (n + 1)
        sm = [0] * (n + 1)

        pow10 = [1] * (n + 1)

        for i in range(n):
            digit = int(s[i])

            val[i + 1] = val[i]
            cnt[i + 1] = cnt[i]
            sm[i + 1] = sm[i]

            if digit != 0:
                val[i + 1] = (val[i] * 10 + digit) % MOD
                cnt[i + 1] += 1
                sm[i + 1] += digit

            pow10[i + 1] = (pow10[i] * 10) % MOD

        ans = []

        for l, r in queries:
            # Number of non-zero digits in s[l:r+1]
            k = cnt[r + 1] - cnt[l]

            # Remove the prefix before l
            x = (val[r + 1] - val[l] * pow10[k]) % MOD

            # Sum of digits in the range
            total = sm[r + 1] - sm[l]

            ans.append((x * total) % MOD)

        return ans