class Solution:
    def maxNumOfSubstrings(self, s: str) -> list[str]:
        n = len(s)

        # Store first and last occurrence of every character
        first = {}
        last = {}

        for i, ch in enumerate(s):
            if ch not in first:
                first[ch] = i
            last[ch] = i

        intervals = []

        # Generate valid intervals
        for ch in first:
            l = first[ch]
            r = last[ch]

            i = l
            valid = True

            while i <= r:
                c = s[i]

                # character appears before current left boundary
                if first[c] < l:
                    valid = False
                    break

                r = max(r, last[c])
                i += 1

            if valid:
                intervals.append((r, l))

        # Choose maximum number of non-overlapping intervals
        intervals.sort()

        ans = []
        end = -1

        for r, l in intervals:
            if l > end:
                ans.append(s[l:r+1])
                end = r

        return ans