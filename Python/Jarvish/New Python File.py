import os
path=os.getcwd()
print(path)
a=path.split("\\")
a.index("Users")
New_Path=a[0]+"\\"+a[1]+"\\"+a[2]+"\\AppData\Local\Microsoft\WindowsApps\PythonSoftwareFoundation.Python.3.9_qbz5n2kfra8p0\\"
print(os.startfile(New_Path))
print("","","",sep="\n")
print("              >>>>>>>>>Now open cmd here by writing on top")
print("after opening of cmd write here")
print("python -m pip install --upgrade pip")
