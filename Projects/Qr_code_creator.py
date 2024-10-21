import qrcode
data = "Hello, QR Code!"

# Creating an instance of QR Code
qr = qrcode.QRCode(
    version=1,
    error_correction=qrcode.ERROR_CORRECT_L,
    box_size = 10,
    border = 4,
)

# Adding data to the instance
qr.add_data(data)
qr.make(fit = True)


# Creating an image of QR Code
img = qr.make_image(fill='black', back_color="red")

# Saving Qr code
img.save("./qr1.png")