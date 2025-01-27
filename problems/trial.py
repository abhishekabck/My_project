from typing import List, Optional

class Solution:
    def countMentions(self, numberOfUsers: int, events: List[List[str]]) -> List[int]:
        # Custom sorting function
        def custom_sort(event):
            timestamp = int(event[1])
            event_type = 0 if event[0] == "OFFLINE" else 1
            return (timestamp, event_type)

        # Sort events based on the custom sort function
        events.sort(key=custom_sort)

        # All users are initially online
        status = {i: 1 for i in range(numberOfUsers)}
        mentions = [0] * numberOfUsers
        
        for event in events:
            timestamp = int(event[1])
            if event[0] == "MESSAGE":
                if event[2] == "ALL":
                    for i in range(numberOfUsers):
                        mentions[i] += 1
                elif event[2] == "HERE":
                    for user_id in status:
                        if status[user_id] != 1 and status[user_id] <= timestamp:
                            status[user_id] = 1
                        if status[user_id] == 1:
                            mentions[user_id] += 1
                else:
                    for user_id in map(lambda x: int(x.lstrip("id")), event[2].split()):
                        mentions[user_id] += 1
            elif event[0] == "OFFLINE":
                status[int(event[2])] = timestamp + 60
        return mentions


Solution().countMentions(3, [["MESSAGE","2","HERE"],["OFFLINE","2","1"],["OFFLINE","1","0"],["MESSAGE","61","HERE"]])
    