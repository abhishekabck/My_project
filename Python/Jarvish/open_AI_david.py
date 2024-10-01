import os
import speech_recognition as sr
list2=[]
Exceptions=[]
while True:
    r=sr.Recognizer()
    with sr.Microphone() as source:
        r.pause_threshold = 1
        audio= r.listen(source)
    try :
        query=r.recognize_google(audio, language ="en-in")
        list2.append()
    except Exception as e:
        Exceptions.append(e)
    if ("open" or "activate") and ("project" or "jarvish" or "jack" or "jac")  in query.lower():
        os.startfile("Jarvish.py.py")
        exit()
        break
    elif "hello" or ("jack" or "jac") in query.lower():
        print("yes sir")
        print("please provide commands".capitalize())
    elif "open project folder" in query.lower():
        a=os.getcwd
        os.startfile(a)
    else :
        print(" Function not found")
    
        


