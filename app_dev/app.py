from kivy.app import App
from kivy.uix.label import Label

class MyApp(App):
    def build(self):
        # This method returns the root widget of the application
        return Label(text="Hello World")

if __name__ == '__main__':
    MyApp().run()
