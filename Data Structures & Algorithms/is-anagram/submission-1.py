class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        s1 = defaultdict(int)
        for ch in s:
            s1[ch] += 1
        for ch in t:
            s1[ch] -= 1
        for it in s1.values():
            if(it != 0):
                return False
        return True