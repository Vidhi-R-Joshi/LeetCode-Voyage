class Solution(object):
    def reversePrefix(self, word, ch):
        if ch not in word:
            return word
        
        x = word.index(ch)
        rev = word[:x + 1][:: -1]
        word = word.replace(word[:x + 1], rev, 1)

        return word