from django.db import models

# Create your models here.
class Students_record(models.Model):
    S_id = models.IntegerField(null = False)
    firstname = models.CharField(max_length = 50)
    lastname = models.CharField(max_length = 50)
    Roll_no = models.IntegerField(null = False)
    
    def __str__(self):
        return f"{self.firstname} {self.lastname}"
