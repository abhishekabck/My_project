import matplotlib.pyplot as plt
import numpy as np

# Downloading the digit dataset

from sklearn.datasets import load_digits
digits_dataset = load_digits()

# Printing total images and labels in the dataset
# print(digits_dataset.data.shape)
# print(digits_dataset.target.shape)

# Let's have a look at the training data
plt.figure(figsize=(20,4))
for index, (image, label) in enumerate(zip(digits_dataset.data[0:10], digits_dataset.target[0:10])):
    plt.subplot(1, 10, index+1)
    plt.imshow(np.reshape(image, (8, 8)), cmap=plt.cm.gray)
    plt.title("Training: %i\n" %label, fontsize = 20)