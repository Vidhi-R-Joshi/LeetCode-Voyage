class Solution:
    def replaceWords(self, dictionary, sentence):
        root_set = set(dictionary)
        result = []
        words = sentence.split()
        for word in words:
            prefix = ''
            for i in range(1, len(word)+1):
                prefix = word[:i]
                if prefix in root_set:
                    break
            result.append(prefix)
        return ' '.join(result)
