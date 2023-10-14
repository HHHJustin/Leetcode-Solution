class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        
        dp = [True] + [False] * len(s)

        for index in range(1, len(s) + 1):
            for j in range(index):
                # dp[j] represent the s[:j] can be segmented in wordDict
                # s[j:index] in wordDict represent s[j:index] can be segmented in this time.
                if dp[j] and s[j:index] in wordDict:
                    dp[index] = True
                    break
        return dp[-1]

# s ="leetcode", wordDict = ["leet", "code"]
# declare a dp list that the list length is len(s) + 1
# ex: dp = [F, F, F, F, F, F, F, F, F]
# each represent the string ever appear
# that is say dp 
# -> "", "l", "le", "lee", "leet", "leetc", "leetco", "leetcod", "leetcode"
# and dp represent if the s can be segemented to sequence in wordDict.
# The 0-index("") is True initially because the empty string can be segmented.

# Then we can the word in wordDict appear in the s. 
# if the index (current - len(word)) == True -> 
# represent the word can be segmented and the string before can be segmented too.
# -> then dp[current index] = True

# finally, just to check the dp[-1] -> we can know the anwser
