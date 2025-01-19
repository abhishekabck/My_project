from datetime import datetime, timedelta
from collections import defaultdict

def process_logs(logs):
    lockout_duration = timedelta(seconds=300)  # 5 minutes
    blacklist_duration = timedelta(seconds=1800)  # 30 minutes
    suspension_threshold = 10  # 10 failed attempts
    violation_logs = []

    user_failures = defaultdict(list)  # Tracks failed attempts for users
    ip_failures = defaultdict(list)  # Tracks failed attempts for IPs
    user_lockout = {}  # Tracks lockout end time for users
    ip_blacklist = {}  # Tracks blacklist end time for IPs
    suspended_users = set()  # Tracks suspended users

    def add_violation(violation_type, timestamp, username, ip):
        violation_logs.append(f"{violation_type} {timestamp} {username} {ip}")

    for log in logs:
        timestamp, username, ip, result = log.split()
        timestamp = datetime.fromisoformat(timestamp.replace("Z", "+00:00"))

        # Format the timestamp for output
        def format_timestamp(ts):
            return ts.isoformat().replace("+00:00", "Z")

        # Check for user suspension
        if username in suspended_users:
            add_violation("SUSPENSION_VIOLATION", format_timestamp(timestamp), username, ip)
            continue

        # Check for IP blacklist
        if ip in ip_blacklist and timestamp < ip_blacklist[ip]:
            add_violation("BLACKLIST_VIOLATION", format_timestamp(timestamp), username, ip)
            continue

        # Check for user lockout
        if username in user_lockout and timestamp < user_lockout[username]:
            add_violation("LOCKOUT_VIOLATION", format_timestamp(timestamp), username, ip)
            continue

        if result == "FAILURE":
            # Handle user failure tracking
            user_failures[username].append(timestamp)
            user_failures[username] = [
                t for t in user_failures[username] if t >= timestamp - timedelta(hours=24)
            ]
            if len(user_failures[username]) > suspension_threshold:
                suspended_users.add(username)
                add_violation("SUSPENSION_VIOLATION", format_timestamp(timestamp), username, ip)
                continue

            # Handle IP failure tracking
            ip_failures[ip].append(timestamp)
            ip_failures[ip] = [
                t for t in ip_failures[ip] if t >= timestamp - timedelta(minutes=20)
            ]
            if len(ip_failures[ip]) > 5:
                ip_blacklist[ip] = timestamp + blacklist_duration
                add_violation("BLACKLIST_VIOLATION", format_timestamp(timestamp), username, ip)

            # Handle user lockout
            if len(user_failures[username]) > 3:
                last_three = user_failures[username][-3:]
                if (last_three[-1] - last_three[0]).total_seconds() <= 300:
                    user_lockout[username] = last_three[-1] + lockout_duration
                    add_violation("LOCKOUT_VIOLATION", format_timestamp(timestamp), username, ip)
        elif result == "SUCCESS":
            # Reset user failures on success
            user_failures[username] = []

    return violation_logs if violation_logs else ["NO_VIOLATION"]

def main():
    n = int(input())
    logs = list()
    for i in range(n):
        logs.append(input())
        
        
    print("\n".join(process_logs(logs)))

if __name__=="__main__":
    main()
    
