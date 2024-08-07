from kivy.app import App
from kivy.uix.button import Button

class MyApp(App):
    def build(self):
        btn = Button(text = "Click Me", on_press = self.on_button_press)
        return btn
    
    def on_button_press(self, instance):
        print("Button Pressed!")

if __name__ == "__main__":
    MyApp().run()