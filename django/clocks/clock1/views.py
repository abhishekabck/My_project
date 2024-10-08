from django.shortcuts import render
from django.http import HttpResponse
from django.template import loader
from time import sleep

# Create your views here.
def main(request):
    template = loader.get_template("main.html")
    context = {
        "Greetings":"Welcome to my web Page"
    }
    return HttpResponse(template.render(context, request))

def clock1(request):
    timer = list(range(100))
    template = loader.get_template('clock1.html')
    context = {
        "timer" : timer
    }
    return HttpResponse(template.render(context, request))
