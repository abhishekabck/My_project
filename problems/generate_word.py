class Solution:
    def generate(self, s):
        ls = [chr(i) for i in range(97, 123)]
        new_word = s
        for i in s:
            new_word += ls[(ord(i)+1 - 97) % 26]
        return new_word
    def kthCharacter(self, k: int) -> str:
        word = "a"
        while len(word)<k:
            print(word)
            word = self.generate(word)
        return word[k-1]
    
print(Solution().kthCharacter(5))