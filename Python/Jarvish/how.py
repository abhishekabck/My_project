import os
path=os.getcwd()
print(path)
a=path.split("\\")
a.index("Users")
New_Path=a[0]+"\\"+a[1]+"\\"+a[2]+"\\AppData\Local\Programs\Python\Python39\Lib\site-packages"
print(New_Path)
