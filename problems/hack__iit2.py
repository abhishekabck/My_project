class Permissions:
    READ = 0b100
    WRITE = 0b010
    EXECUTE = 0b001
    
    def __init__(self):
        self.permissions = 0b000
    
    def allow(self, perm):
        self.permissions |= perm
    
    def disallow(self, perm):
        self.permissions &= ~perm
    
    def is_allowed(self, perm):
        return self.permissions & perm == perm

class AuditLog:
    def __init__(self):
        self.logs = []
        self.authorized_users = []
        self.unauthorized_users = []
    
    def AddLog(self, username, operation, target, result, permissions=None):
        log_entry = {
            "username": username,
            "operation": operation,
            "target": target,
            "users_and_permission": permissions,
            "result": result
        }
        self.logs.append(log_entry)
    
    def __list__(self):
        return self.logs
    
    def PrintLog(self):
        for log in self.logs:
            permissions = log["users_and_permission"] if log["users_and_permission"] else ""
            print(f"{log['username']} {log['operation']} {log['target']} {log['result']} {permissions}")


    
class FileInfo:
    def __init__(self, ftype, owner, users):
        self.ftype = ftype  # 'dir' or 'file'
        self.owner = {owner: Permissions()}
        self.owner[owner].allow(Permissions.READ | Permissions.WRITE | Permissions.EXECUTE)
        self.users = {u: Permissions() for u in users}
        for u in users:
            perms = users[u].lower()
            if 'r' in perms:
                self.users[u].allow(Permissions.READ)
            if 'w' in perms:
                self.users[u].allow(Permissions.WRITE)
            if 'x' in perms:
                self.users[u].allow(Permissions.EXECUTE)
        self.next = {}

class SecureFileSystem:
    READ = 0b100
    WRITE = 0b010
    EXECUTE = 0b001
    def __init__(self):
        self.home = {}
    
    def _get_target(self, folders, user):
        temp = self.home
        result = None
        for folder in folders:
            if folder:
                if folder in temp:
                    if not self.check_permissions(temp[folder], user, self.READ, ftype="dir"):
                        return None
                    temp = temp[folder]
                    result = temp
                    temp = temp.next
                else:
                    return None
        return result

    def CreateDir(self, path, owner, users_p) -> bool:
        folders = path.strip("/").split('/')
        dir_name = folders[-1]
        
        # handling edge case
        if len(folders) == 1:
            if dir_name in self.home: return False
            else:
                self.home[dir_name] = FileInfo("dir", owner, users_p)
                return True
        
        Obj = self._get_target(folders[:-1], owner)
        if not Obj:
            return False
        
        # checking if the user have permission to write
        if self.check_permissions(Obj, owner, self.WRITE) and not self.is_present(Obj.next, dir_name):
            # permission write Successful
            Obj.next[dir_name] = FileInfo("dir", owner, users_p)
            return True
        return False
    
    def CreateFile(self, path, owner, users_p) -> bool:
        folders = path.strip("/").split('/')
        file_name = folders[-1]
        # handling edge case
        if len(folders) == 1:
            if file_name in self.home: return False
            else:
                self.home[file_name] = FileInfo("file", owner, users_p)
                return True
        Obj = self._get_target(folders[:-1], owner)
        if not Obj:
            return False

        # checking if the user have permission to write
        if self.check_permissions(Obj, owner, self.WRITE) and not self.is_present(Obj.next, file_name):
            # permission write Successful
            Obj.next[file_name] = FileInfo("file", owner, users_p)
            return True
        return False
    
    def Delete(self, path, username) -> bool:
        folders = path.strip("/").split('/')
        target = folders[-1]
        
        if len(folders) == 1:
            if self.is_present(self.home, target) and self.check_permissions(self.home[target], username, self.WRITE):
                info = self.home[target]
                del self.home[target]
                del info
                return True
            return False
        
        Obj = self._get_target(folders[:-1], username)
        if not Obj or not self.is_present(Obj.next, target):
            return False
        
        if self.check_permissions(Obj.next[target], username, self.WRITE):
            info = Obj.next[target]
            del Obj.next[target]
            del info
            return True
        return False

    def ListDir(self, path, username) -> bool:
        folders = path.strip("/").split('/')
        dir_name = folders[-1]
        if len(folders) == 0: return True  #root checkup
        
        # Handling edge case for root level directory listing
        if len(folders) == 1:
            return self.check_permissions(self.home[dir_name], username, self.READ) if self.is_present(self.home, dir_name) else False
        
        Obj = self._get_target(folders[:-1], username)
        if Obj is not None and self.is_present(Obj.next, dir_name) and self.check_permissions(Obj, username, self.READ):
            return True
        return False

    def ReadFile(self, path, username) -> bool:
        folders = path.strip("/").split('/')
        file_name = folders[-1]
        
        if len(folders) == 1:
            if self.is_present(self.home, file_name) and self.check_permissions(self.home[file_name], username, self.READ, "file"):
                return True
            return False
        
        Obj = self._get_target(folders[:-1], username)
        if Obj and self.is_present(Obj.next, file_name) and self.check_permissions(Obj.next[file_name],  username, self.READ, "file"):
            return True
        return False
    
    def WriteFile(self, path, username) -> bool:
        folders = path.strip("/").split('/')
        file_name = folders[-1]
        
        if len(folders) == 1:
            if self.is_present(self.home, file_name) and self.check_permissions(self.home[file_name], username, self.WRITE, "file"):
                return True
            return False
        
        Obj = self._get_target(folders[:-1], username)
        if Obj and self.is_present(Obj.next, file_name) and self.check_permissions(Obj.next[file_name],  username, self.WRITE, "file"):
            return True
        return False
    
    def check_permissions(self, pointer: FileInfo, user: str, perm:int, ftype=None) -> bool:
        if ftype and pointer.ftype != ftype:
            return False
        if user in pointer.owner:
            return True
        return pointer.users.get(user, Permissions()).is_allowed(perm)

    def is_present(self, parent, entry):
        return entry in parent

def main():
    sfs = SecureFileSystem()
    audit_log = AuditLog()
    
    # Taking inputs
    U = int(input())
    audit_log.authorized_users = [input().strip() for x in range(U)]
    
    NumOfOps = int(input())
    operations = [input().split() for i in range(NumOfOps)]
    
    for operation in operations:
        OprType = operation[0]
        username = operation[1]
        path = operation[2]
        result = "SUCCESS"
        user_p = dict()
        if OprType == "CREATE_FILE" and username in audit_log.authorized_users:
            for user_perm in operation[3].split(";")[1:]:
                up = user_perm.split(":")
                user_p[up[0]] = up[1]
            if not sfs.CreateFile(path, username,user_p):
                result = "DENY"
            audit_log.AddLog(username, OprType, path, result, permissions=operation[3])
            print(result)
        
        elif OprType == "CREATE_DIR" and username in audit_log.authorized_users:
            for user_perm in operation[3].split(";")[1:]:
                up = user_perm.split(":")
                user_p[up[0]] = up[1]
            if not sfs.CreateDir(path, username,user_p):
                result = "DENY"
            audit_log.AddLog(username, OprType, path, result, operation[3])
            print(result)
        
        elif OprType == "READ_FILE" and username in audit_log.authorized_users:
            if not sfs.ReadFile(path, username):
                result = "DENY"
            audit_log.AddLog(username, OprType, path, result)
            print(result)
        
        elif OprType == "WRITE_FILE" and username in audit_log.authorized_users:
            if not sfs.WriteFile(path, username):
                result = "DENY"
            audit_log.AddLog(username, OprType, path, result)
            print(result)
        
        elif OprType == "LIST_DIR" and username in audit_log.authorized_users:
            if not sfs.ListDir(path, username):
                result = "DENY"
            audit_log.AddLog(username, OprType, path, result)
            print(result)
        
        elif OprType == "DELETE" and username in audit_log.authorized_users:
            if not sfs.Delete(path, username):
                result = "DENY"
            audit_log.AddLog(username, OprType, path, result)
            print(result)
        else:
            result = "DENY"
            audit_log.AddLog(username, OprType, path, result)
            audit_log.unauthorized_users.append(username)
            print(result)
        del user_p
    audit_log.PrintLog()
if __name__ == "__main__":
    main()