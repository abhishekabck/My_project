from django.urls import path
from . import views

urlpatterns = [
    path('', views.main, name = "main"),
    path('clock1/', views.clock1, name = "clock1")
]
