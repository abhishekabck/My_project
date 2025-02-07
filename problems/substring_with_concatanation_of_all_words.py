from collections import Counter
from typing import List
s = "barfoothefoobarman"
words = ["foo", "bar"]

def find_substring(s: str, words: List[str]) -> List[int]:
    word_length = len(words[0])
    window_size = len(words)*word_length
    n = len(s)


    def is_present(i):
        arr = Counter(words.copy())
        for x in range(i, i+window_size, word_length):
            word = s[x:x + word_length]
            if word not in arr or arr[word] <= 0:
                return False
            arr[word] -= 1
        return True
    
    result = []
    for i in range(n - window_size + 1):
        if is_present(i):
            result.append(i)
    return result
