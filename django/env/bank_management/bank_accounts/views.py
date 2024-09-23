from django.shortcuts import render
from django.http import HttpResponse
from django.template import loader
from .models import Students_record

# Create your views here.
def Show_list(request):
    records = Students_record.objects.all().values()
    template = loader.get_template("Student_List.html")
    context = {
        "records":records,
        }
    return HttpResponse(template.render(request, context))
