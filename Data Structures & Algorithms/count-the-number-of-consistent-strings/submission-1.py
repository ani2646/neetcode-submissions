class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        myset = {x for x in allowed}
        ans = len(words)
        for x in words:
            for y in x:
                if y not in myset:
                    ans -= 1
                    break
        return ans

        

        