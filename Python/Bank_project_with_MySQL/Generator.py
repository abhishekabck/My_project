
def Genrate(name,email,typ):
    import os 
    import random
    import smtplib
    from email.mime.multipart import MIMEMultipart
    from email.mime.text import MIMEText
    import G_data
    if typ.strip() == "1":
        otp=random.randint(634325,999999)
        mail_content = '''Hello {},
Your UNION BANK OF INDIA's OTP is {}.'''.format(name,otp)
    elif typ.strip() == "2":
        mail_content = '''Hello {},
Anyone has login your Account on a device.'''.format(name)
    #The mail addresses and password
    sender_address = G_data.G_mail()
    sender_pass = G_data.G_pass()
    receiver_address = 'kirtichaurasiya880@gmail.com'
    #Setup the MIME
    message = MIMEMultipart()
    message['From'] = sender_address
    message['To'] = receiver_address
    message['Subject'] = 'A OTP FROM UNION BANK OF INDIA'
    #The body and the attachments for the mail
    message.attach(MIMEText(mail_content, 'plain'))
    #Create SMTP session for sending the mail
    session = smtplib.SMTP('smtp.gmail.com', 587) #use gmail with port
    session.starttls() #enable security
    session.login(sender_address, sender_pass) #login with mail_id and password
    text = message.as_string()
    session.sendmail(sender_address, receiver_address, text)
    session.quit()
    if typ.strip() == "1":
        print(' OTP SEND')
        return otp
    else :
        return None
    

