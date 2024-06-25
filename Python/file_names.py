import os

st = {}
d_path = "D:\\"

def scanner(d_path):
    ls = os.listdir(d_path)
    for name in ls:
        try :
            path = f"{d_path}{name}\\"
            st[name] = {os.listdir(path):""}
            for i in st[name]:
                p = f"{path}{i}\\"
                try :
                    el = os.listdir(p)
                    st[name][i]
                except :
                    pass
        except :
            pass


def if_folder(path):      # Return Bool whether path is folder or not
    try :
        os.listdir(path)
        return True
    except :
        return False


def F_store(path,st):
    if if_folder(path):
        folder = path.split("\\")[-1]
        st[folder] = os.listdir()

scanner(d_path)
print(st)
