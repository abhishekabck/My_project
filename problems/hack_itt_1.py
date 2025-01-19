from datetime import datetime, timedelta
from collections import defaultdict

class Log:
    def __init__(self, log):
        self.Time_stamp, self.username, self.ip, self.message = log.split()
    
    def __str__(self):
        return f"{self.Time_stamp} {self.username} {self.ip} {self.message}"


class Process_logs:
    def __init__(self, logs):
        self.logs = logs
        
        
def process_logs(logs):
    lockout_duration = timedelta(seconds=300)
    blacklist_duration = timedelta(seconds=1800)
    suspension_threshold = 10
    violation_types = [""]
    violation_logs = []

    user_failures = defaultdict(list)
    ip_failures = defaultdict(list)
    user_lockout = {}
    ip_blacklist = {}
    suspended_users = set()

    def add_violation(violation_type, timestamp, username, ip):
        violation_logs.append(f"{violation_type} {timestamp} {username} {ip}")
        