import random
import pyautogui
import pyperclip
import time

emojis = "😒😂😊🤣❤😍👌😘💕😁🙌🤷‍♂️🤷‍♀️🤦‍♂️🤦‍♀️😉😎🎶🤷‍♂️😢💖✌️🤞😜😄😃🤣😂😁😀😅😍😚☺️😘😆😉🥰🙂🤗😗😊😋😙🤩🤔🥲😎🫥😶😑😐🤨🫡😶‍🌫️🙄😏😣😥😮😴😒🤤🥱😫😝😜😪😯🤐😌😛😓🤑😟😨😩😤😤😲😔😕☹️☹️😢🤯😬😭🙁🫤🫠🙃😖😞😧😦😮‍💨😰😱🥵🥶😳🤪😵😷🤬😡😠🥴😵‍💫🤒🤕🥸🥳🤥🫨🙂‍↔️🥺🤢😠😡🤮🥹🙂‍↕️🤫🤠🤧🤬😳🤪😵😷😇🤡🤭👿👽👻😈🤓☠️💀🧐🫣🫣🫢👹👺🤖👾😻😼😽💩😺🙀😿😸😹😾🐺🦝🦊🐶🐵🙊🙉🙈🐱🦁🐷🐮🐻🐨🐼🐭🐗🐻‍❄️🐗🐯🦒🦊🐹🐸🦓👇"  
emoji_list = list(emojis)
l = len(emoji_list)
time.sleep(5)

while True:
    length = random.randint(1, 13)
    st = ""
    for i in range(length):
        st += emoji_list[random.randint(0, l-1)]
    pyautogui.click()
    pyperclip.copy(st)
    time.sleep(0.5)
    pyautogui.hotkey("ctrl","v")
    pyautogui.press("enter")
    
    time.sleep(0.5)
    
