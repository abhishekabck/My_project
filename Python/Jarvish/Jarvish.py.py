import googlesearch
import pyttsx3
import speech_recognition as sr
import datetime
import wikipedia
import webbrowser
import os
import smtplib
import platform
import googlesearch

engine = pyttsx3.init("sapi5")
voices =engine.getProperty("voices")
engine.setProperty("voice" , voices[0].id)
result=0
res=0
code_word=""

Emails={"abhishek":"abhiabckchaurasiya@gamil.com","kirti":"kirtichaurasiya880@gmail.com","komal":"dkomal786@gmail.com","ashish":"ashishgchaurasiya786@gmail.com","divyanshu":"studiosthe03@gmail.com"}

def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def wishMe():
    hour = int(datetime.datetime.now().hour)
    if hour >=0 and hour<12:
        speak("Hello sir, Good Morning")
    elif hour>=12 and hour<18:
        speak("Hello sir, Good Afternoon")
    else:
        speak("Hello sir, Good Evening !")
    
def takeCommand():
    # It takes microphone input from the user and returns string output
    r=sr.Recognizer()
    with sr.Microphone() as source:
        print("Listning......")
        r.pause_threshold = 1
        audio= r.listen(source)

    try :
        print("Recognizing.....")
        query=r.recognize_google(audio, language ="en-in")
        if result ==1:
            print("User said: ",query)
    except Exception as e :
        print("Say that again please...")
        res=1
        return "None"
    return query



def sendEmail(to, content):
    server = smtplib.SMTP("smtp.gmail.com", 587)
    server.ehlo()
    server.starttls()
    server.login("abhishekchaurasiya079@gmail.com", "DEATH_KING")
    server.sendmail("abhishekchaurasiya079@gmail.com" , to , content)
    server.close()

def google_search(query):
    a=query.split(" ")
    if op==0:
        _1_=a.index("search")
        _2_=a.index("google")
        New_list=a[_1_+1:_2_-1]
    elif op ==1:
        _1_=a.index("open")
        New_list=a[_1_+1:]
    query=""
    for i in New_list:
        query=query+" "+i
    return query

def search(query):
    try:
        speak("searching google")
        Query=google_search(query)
        if result==1:
            print("you searched : ",Query)
        tld="com"
        lang="en"
        safe="off"
        county="India"
        for j in googlesearch.search(query=Query,tld=tld,lang=lang,safe=safe,country=county):
            webbrowser.open(j)
            break
    except Exception as e:
        print(e)
        speak("try again")

if __name__=="__main__":
    wishMe()
    while True:
        
        query=code_word+takeCommand().lower()
        print(query)
        if ("jac" or "jack") in query and query.index("jac"or "jack")==0:
            if "wikipedia" in query:
                try :
                    speak('Searching Wikipedia...')
                    query = query.replace("wikipedia","")
                    results = wikipedia.summary(query,sentences=3)
                    speak("According to wikipeadia : ")
                    print(results)
                    speak(results) 
                except :
                    speak("Please said your topic also with Wikipeadia")

            elif "open google" in query:
                webbrowser.open("google.com")


            elif "open youtube" in query:
                webbrowser.open("youtube.com")

            elif "time" and "current" in query:
                Current_Time="The Current time is ",datetime.datetime.now().strftime("%H hours %M minutes")
                speak(Current_Time)
                if result==1:
                    print("Current time")

                
            elif "created you" and "who" in query:
                speak("I am Jarvis and I am created by Abhishek Chaurasiya")
                if result==1:
                    print("I am Jarvis and I am created by Abhishek Chaurasiya")


            elif "which" and "processor" in query:
                Processor=platform.processor()
                speak(Processor)

            elif "send email" in query:
                for Email in Emails:
                    if Email in query:
                        try :
                            speak("What should I say ?")
                            if result==1:
                                print("What should I say?")
                            while True :
                                content = takeCommand()
                                while True:
                                    speak("Are you wan't to add more data")
                                    ty=takeCommand()
                                    if "yes" or "ya" in query:
                                        con=takeCommand()
                                        content = content+" "+con
                                        if result ==1:
                                            print("your updated email data is -------",content)
                                    elif "no" or "nahi" in query:
                                        break
                                    else :
                                        speak("please give answer in yes or no")            
                                if result==1:
                                    print("your email data is ------",content)
                                if res==0:
                                    break
                                else :
                                    speak("Sorry, I am unable to identify your words please send it again")
                            to = Emails[Email]
                            sendEmail(to, content)
                            speak("Email has been sent !")
                        except Exception as e:
                            print(e)
                            speak("Sorry, Sir unable to send this Email")
                    
         

            elif "python" and "version"  in query:
                speak(platform.python_version())

            elif "activate print function" in query:
                result=1
                speak("Print Function Activated")

            elif "thank you" in query:
                speak("Most Welcome sir")

            elif "create notepad file" in query:
                while True:
                    speak("please give name of text file")
                    text_name=takeCommand()
                    if res==0:
                        break
                fd=os.open(text_name+".txt",os.O_RDWR|os.O_CREAT)
                while True:
                    speak("plz give data")
                    content=takeCommand()
                    if res==0:
                        break
                    speak("Try again")
                os.write(fd,content.encode())
                os.close(fd)
                speak("your given data has been saved")

            elif "search" and "in google" in query:
                op=0
                query="jack "+query
                search(query)

            elif  "open project" in query:
                speak("Just a second sir")
                os.startfile(os.getcwd())

            elif "project folders" in query:
                speak("just a second sir !")
                os.startfile("C:\\Users\\AKChaurasiya\\Documents\\Abhishek's Programs\\Grate_working")

            elif "open cmd" in query :
                os.startfile("C:/Users/AKChaurasiya/AppData/Roaming/Microsoft/Windows/Start Menu/Programs/System Tools/Command Prompt.lnk")

            elif "open" in query:
                query="jack "+query
                op=1
                search(query)
                

            elif "quit" in query:
                speak("Thank you sir for giving your important time")
                exit()
            elif "shutdown" in query:
                if "for" not in query:
                    fd=os.open("shutdown.bat",os.O_RDWR|os.O_CREAT)
                    os.write(fd,"shutdown.exe -s -t 1 -c \" your computer will shut down in 2 seconds".encode())
                    os.close(fd)
                    speak("shut down completed")
                    os.startfile("shutdown.bat")
                    
            elif "wait" in query:
                while True:
                    query=takeCommand()
                    if "activate again" or "jack" or "jac" in query:
                        break

            elif "band ho jao" in query:
                speak("Thank you sir, for giving your important time")
                exit()
            
            elif "remove" and ("jac" or "jack") and "code" in query:
                speak("Sir, code word deactivated")
                code_word="jack"
                
