# sending randomly/.
import os
import random


def Gen(Path, T):
    for i in range(10):
        T += 1
        dirl= os.listdir(Path)
        for j in range(10):
            if Path[-1] == "\\":
                r_path = Path+str(j)
            else:
                r_path = Path+"\\"+str(j)
            os.mkdir(r_path)
            print(r_path)
            LD=os.listdir(path)
            for x in dirl:
                if Path[-1] == "\\":
                    r_path = Path+str(x)
                else:
                    r_path = Path+"\\"+str(x)
                for a in range(10):
                    os.makedir(r_path+"\\"+str(a))
            for x in range(2):
                ld=os.listdir(Path)
                ran=random.randint(0,len(ld)-1)
                if Path[0]=="\\":
                    Path+=ld[ran]
                else:
                    Path+="\\"+ld[ran]
            
    L = (Path, T)
    print(L)
    return L


path = "C:\\Users\\Public\\Music\\Trial"
times = 0
while True:
     if "." in path:
         continue
     listd=os.listdir(path)
     Random=random.randint(0,len(listd)-1)
     path=path+"\\"+listd[Random]
     times+=1
     if times>10:
         print(path)
         print("success")
     else :
         Result=Gen(path,times)
         path=Result[0]
         times=Result[1]
Result = Gen(path, times)
print(Result)
