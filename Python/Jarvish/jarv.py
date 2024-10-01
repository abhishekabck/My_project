import pyttsx3
import speech_recognition as sr
import datetime
import wikipedia
import webbrowser
import os
import smtplib

engine = pyttsx3.init("sapi5")
voices =engine.getProperty("voices")
engine.setProperty("voice" , voices[0].id)

Emails={"abhishek":"abhiabckchaurasiya@gamil.com","kirti":"kirtichaurasiya880@gmail.com","komal":"dkomal786@gmail.com","ashish":"ashishgchaurasiya786@gmail.com","divyanshu":"studiosthe03@gmail.com"}

def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def wishMe():
    hour = int(datetime.datetime.now().hour)
    if hour >=0 and hour<12:
        speak("Good Morning")
    elif hour>=12 and hour<18:
        speak("Good Afternoon")
    else:
        speak("Good Evening !")
    speak("I am Jarvish sir Please tell me how may I help you")
    
def takeCommand():
    # It takes microphone input from the user and returns string output
    r=sr.Recognizer()
    with sr.Microphone() as source:
        print("Listning......")
        r.pause_threshold = 2
        audio= r.listen(source)
    try :
        print("Recognizing.....")
        query=r.recognize_google(audio, language="en-in")
        print("User said: ",query)
    except Exception as e :
        print("Say that again please...")
        return "None"
    return query

def sendEmail(to, content):
    server = smtplib.SMTP("smtp.gmail.com", 587)
    server.ehlo()
    server.starttls()
    server.login("abhishekchaurasiya079@gmail.com", "DEATH_KING")
    server.sendmail("abhishekchaurasiya079@gmail.com" , to , content)
    server.close()

    
if __name__=="__main__":
    wishMe()
    while True:
        query=takeCommand().lower()
        print(query)
        if "wikipedia" in query:
            try :
                speak('Searching Wikipedia...')
                query = query.replace("wikipedia","")
                results = wikipedia.summary(query,sentences=2)
                speak("According to wikipeadia : ")
                print(results)
                speak(results)
                
                
            except :
                speak("Please said your topic also with Wikipeadia")
        elif "open google" in query:
            webbrowser.open("google.com")
            

        elif "open youtube" in query:
            webbrowser.open("youtube.com")
            

        elif "open music" in query:
            music_dir="c:\\Users\\AKChaurasiya\\Music\\Songs\\"
            songs=os.listdir(music_dir)
            while True:
                try :
                    n=1
                    print("list of songs are")
                    speak("List of songs are")
                    for i in songs:
                        print(n,i,sep="       -------       ")
                    speak("please choose your song")
                    print("Listning.......")
                    query=takeCommand().lower()
                    Index=songs.index(query+".mp3")
                    os.startfile(os.path.join(music_dir, songs[Index]))
                    speak("Listen your song")
                    break
                except :
                    speak("unable to identify your song please said again")
                    
                

        elif "send email" in query:
            for Email in Emails:
                if Email in query:
                    try :
                        speak("What should I say ?")
                        content = takeCommand()
                        to = Emails[Email]
                        sendEmail(to, content)
                        speak("Email has been sent !")
                    except Exception as e:
                        print(e)
                        speak("Sorry, Sir unable to send this Email")
        
