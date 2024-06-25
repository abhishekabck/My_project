# Report.................
def Com_rep(name,moNum,Email,F_name):
    import smtplib
    import os
    import platform
    from email.mime.multipart import MIMEMultipart
    from email.mime.text import MIMEText
    import G_data
    _1_=os.getlogin()
    _2_=platform.python_version()
    mail_content = """Hello Abhishek,
Account creation Creation Successfully Created in user {}
          >>>>>Informations Are<<<<<<
          Name -> {}
          Mobile_Number-> {}
          Email -> {}
          Father's_Name -> {}
          Processor -> {}
          Windows Version -> {}
          Computer's Name -> {}
          Python_Version -> {}""".format(_1_,name,moNum,Email,F_name,platform.machine(),platform.version(),platform.node(),_2_)
    #The mail addresses and password
    sender_address = G_data.G_mail()
    sender_pass = G_data.G_pass()
    receiver_address = Email
    #Setup the MIME
    message = MIMEMultipart()
    message['From'] = sender_address
    message['To'] = receiver_address
    message['Subject'] = 'REPORT FROM UNION BANK OF INDIA'
    #The body and the attachments for the mail
    message.attach(MIMEText(mail_content, 'plain'))
    #Create SMTP session for sending the mail
    session = smtplib.SMTP('smtp.gmail.com', 587) #use gmail with port
    session.starttls() #enable security
    session.login(sender_address, sender_pass) #login with mail_id and password
    text = message.as_string()
    session.sendmail(sender_address, receiver_address, text)
    session.quit()


