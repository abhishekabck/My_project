f=open("user.out",'w')
while True:
    try:
        n=input()
        if len(n)==2:
            print('[]',file=f)
            continue
        arr=list(map(int,n[1:-1].split(',')))
        arr=[str(i) for i in sorted(arr)]
        print('['+','.join(arr)+']',file=f)
    except:
        f.close()
    exit(0)