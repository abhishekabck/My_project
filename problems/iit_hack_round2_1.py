import pandas as pd
import binascii
import sys

class SQLInjectionAnalyzer:
    def __init__(self, file_path):
        self.file_path = file_path
        self.data = pd.read_csv(file_path)
        self.attacker_ip = "NULL"
        self.sql_injection_count = 0
        self.first_payload = "NULL"
        self.last_payload = "NULL"
        self.formatting_symbol_count = 0
        self.sql_injection_attempts = []

    @staticmethod
    def is_sql_injection(info):
        sql_keywords = ["SELECT", "INSERT", "UPDATE", "DELETE", "DROP", "ALTER", "CREATE", "UNION", "OR 1=1"]
        sql_symbols = ["'", "\"", ";", "--", "/*", "*/", "xp_"]
        return any(keyword in info.upper() for keyword in sql_keywords) or any(symbol in info for symbol in sql_symbols)

    @staticmethod
    def contains_formatting_symbol(info):
        # Check for colon directly
        if ":" in info:
            return True
        # Check for colon in hex format
        try:
            decoded_info = binascii.unhexlify(info).decode('utf-8')
            if ":" in decoded_info:
                return True
        except (binascii.Error, UnicodeDecodeError):
            pass
        return False

    def analyze_traffic(self):
        first_time = float('inf')
        last_time = 0

        for index, row in self.data.iterrows():
            if self.is_sql_injection(row['Info']):
                self.sql_injection_count += 1
                self.sql_injection_attempts.append(row)

                # Enhanced check for colon (:) in the suspicious queries
                if self.contains_formatting_symbol(row['Info']):
                    self.formatting_symbol_count += 1

                time = float(row['Time'])
                if time < first_time:
                    first_time = time
                    self.first_payload = row['Info'].split(' ')[1]

                if time > last_time:
                    last_time = time
                    self.last_payload = row['Info'].split(' ')[1]

                if self.attacker_ip == "NULL":
                    self.attacker_ip = row['Source']

    def print_results(self):
        print(f"1A: {self.attacker_ip};")
        print(f"2A: {self.sql_injection_count};")
        print(f"3A: {self.first_payload};")
        print(f"4A: {self.last_payload};")
        print(f"5A: {self.formatting_symbol_count};")
        sys.stdout.flush()

def main():
    file_path = input()
    analyzer = SQLInjectionAnalyzer(file_path)
    analyzer.analyze_traffic()
    analyzer.print_results()

if __name__ == "__main__":
    main()
