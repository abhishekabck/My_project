import pyttsx3

voiceEngine=pyttsx3.init() 
rate = voiceEngine.getProperty('rate')
volume = voiceEngine.getProperty('volume')
voice = voiceEngine.getProperty('voice')
 
print(rate)
print(volume)
print(voice)
 
newVoiceRate = 50
while newVoiceRate <= 300:
    voiceEngine.setProperty('rate', newVoiceRate)
    voiceEngine.say('Testing different voice rates.')
    voiceEngine.runAndWait()
    newVoiceRate = newVoiceRate+50
    
voiceEngine.setProperty('rate', 125)
 
newVolume = 0.1
while newVolume <= 1:
    voiceEngine.setProperty('volume', newVolume)
    voiceEngine.say('Testing different voice volumes.')
    voiceEngine.runAndWait()
    newVolume = newVolume+0.3
