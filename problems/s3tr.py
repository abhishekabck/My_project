
class Solution:
    def mostPopularCreator(self, creators: list[str], ids: list[str], views: list[int]) -> list[list[str]]:
        cr_view = {}
        for i in range(len(creators)):
            try:
                cr_view[creators[i]] +=  views[i]
            except:
                cr_view[creators[i]] =  views[i]
        Max = max(cr_view.values())
        popular_creators = []
        for i in cr_view:
            if cr_view[i] == Max:
                popular_creators.append(i)
        ar = []
        for i in range(len(creators)):
            if creators[i] in popular_creators:
                ar.append([creators[i],ids[i]])
        Max = 0
        id_v = {ids[i]:views[i] for i in range(len(ids))}
        ml_cr = [ar[i][1] for i in range(len(creators)) if creators.count(creators[i])>1]
        
        

s = Solution()
print(s.mostPopularCreator(creators = ["alice","alice","alice"], ids = ["a","b","c"], views = [1,2,2]))