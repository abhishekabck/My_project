# import asyncio
# import sys

# async def get_input_with_timeout(prompt, timeout):
#     try:
#         return await asyncio.wait_for(asyncio.to_thread(input, prompt), timeout)
#     except asyncio.TimeoutError:
#         return None  # or handle the timeout as needed

# # Example usage
# async def main():
#     user_input = await get_input_with_timeout("Enter something: ", 10)
#     if user_input is None:
#         print("Input timed out!")
#         sys.exit(0)
#     else:
#         print(f"You entered: {user_input}")

# # Run the main function
# asyncio.run(main())

# import time
# import threading
# import sys

# def get_input_with_timeout(prompt, timeout):
#     print(prompt, end='', flush=True)
#     result = [None]
#     def input_thread():
#         result[0] = input()
#     thread = threading.Thread(target=input_thread)
#     thread.start()
#     thread.join(timeout)
#     if thread.is_alive():
#         print("\nInput timed out!")
#         sys.exit(0)
#     return result[0]

# # Example usage
# user_input = get_input_with_timeout("Enter something: ", 5)
# if user_input is not None:
#     print(f"You entered: {user_input}")

# import threading
# import time
# import sys

# def input_with_timeout(prompt, timeout):
#     print(prompt, end='', flush=True)
#     result = [None]
#     def get_input():
#         result[0] = input()
#     thread = threading.Thread(target=get_input)
#     thread.start()
#     thread.join(timeout)
#     if thread.is_alive():
#         print("\nTime's up!")
#         thread.join()  # Clean up the thread
#     return result[0]

# questions = ["What is 2 + 2?", "What is the capital of France?", "Who wrote '1984'?"]

# for question in questions:
#     answer = input_with_timeout(question + " (you have 5 seconds): ", 5)
#     if answer is None:
#         print("Moving to the next question...")
#     else:
#         print(f"Your answer: {answer}")


# import sys
# import select

# def input_with_timeout(prompt, timeout):
#     print(prompt, end='', flush=True)
#     i, o, e = select.select([sys.stdin], [], [], timeout)
#     if i:
#         return sys.stdin.readline().strip()
#     else:
#         print("\nTime's up!")
#         return None

# # Example usage
# questions = ["What is 2 + 2?", "What is the capital of France?", "Who wrote '1984'?"]

# for question in questions:
#     answer = input_with_timeout(question + " (you have 5 seconds): ", 5)
#     if answer is None:
#         print("Moving to the next question...")
#     else:
        # print(f"Your answer: {answer}")

import threading
import time
import sys

def input_with_timeout(prompt, timeout):
    result = [None]
    
    def get_input():
        try:
            result[0] = input(prompt)
        except EOFError:
            pass  # Handle end of file input

    def auto_enter():
        time.sleep(timeout)
        if result[0] is None:
            print("\nTime's up!")
            result[0] = ''

    input_thread = threading.Thread(target=get_input)
    timer_thread = threading.Thread(target=auto_enter)

    input_thread.start()
    timer_thread.start()

    input_thread.join()
    timer_thread.join()
    
    return result[0]

# Example usage
questions = ["What is 2 + 2?", "What is the capital of France?", "Who wrote '1984'?"]

for question in questions:
    answer = input_with_timeout(question + " (you have 5 seconds): ", 5)
    if answer == '':
        print("Moving to the next question...")
    else:
        print(f"Your answer: {answer}")
