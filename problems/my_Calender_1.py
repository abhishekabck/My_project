class My_Calender:
    def __init__(self) -> None:
        self.bookings = []
    
    def search_pos(self, key: int) -> int:
        if len(self.bookings) == 0:
            return 0
        low, high = 0, len(self.bookings) - 1
        while low <= high:
            mid = low + (high - low) // 2
            if self.bookings[mid] <= key:
                low = mid + 1
            else:
                high = mid - 1
        return low
    
    def book(self, start : int, end : int) -> bool:
        spos = self.search_pos(start)
        epos = self.search_pos(end)
        if spos % 2 == 1 or (spos < len(self.bookings) and self.bookings[spos] < end):
            return False
        self.bookings[spos:spos] = [start, end]
        return True

mc = My_Calender()
print(mc.book(47, 50))
print(mc.book(33, 41))
print(mc.book(39, 45))
print(mc.book(33, 42))
print(mc.book(25, 32))
print(mc.book(26, 35))
print(mc.bookings)
print(mc.book(19,25))
print(mc.bookings)