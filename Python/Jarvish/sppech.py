# sppech recognition
import speech_recognition as sr
r=sr.Recognizer()
with sr.Microphone() as source:
    print("Listning......")
    r.pause_threshold = 0.5
    audio= r.listen(source)
    print("Recognizing.....")
    query=r.recognize_google(audio, language="en-in")
    print("User said: ",query)
