def per(message, bannedWords):
        count = dict()
        for i in message:
            if count.get(i,-1) != -1:
                count[i] += 1
            else:
                count[i] = 1
        
        s1 = {i for i in message}
        s2 = {i for i in bannedWords}
        s3 = s1.intersection(s2)
        total = 0
        for i in s3:
            if i in count:
                total+=count[i]
        if total<2:
            return False
        else:
            return True
print(per(["l","i","l","i","l"],["d","a","i","v","a"]))