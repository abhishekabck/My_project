# Importing Neccessary Packages
import numpy as np
import matplotlib.pyplot as plt


# Defining a function for calculating values needed for simple Linear Regression (SLR)

def coef_estimation(x, y):
    n = np.size(x) # calculating number of observations as 'n'.
    mean_x, mean_y = np.mean(x), np.mean(y) #calculating mean of x and y vectors
    cross_xy = np.sum(y*x) - n*mean_y*mean_x # Calculating cross-deviation and deviation about x
    cross_xx = np.sum(x*x) - n*mean_x*mean_x
    reg_b_1 = cross_xy / cross_xx # Calculating regressing coefficients, i.e., b
    reg_b_0 = mean_y - reg_b_1*mean_x
    return(reg_b_0, reg_b_1)

# Defining a function for plotting the regression line
def plot_regression_line(x, y, b):
    plt.scatter(x, y, color = "r", marker = "d", s = 20) # Plotting actual points as scatter plot
    y_pred = b[0] + b[1]*x # Predicting response vector
    plt.plot(x, y_pred, color = "g") #plotting the regression line and labels on it
    plt.xlabel('x')
    plt.ylabel('y')
    plt.show()

# Defining the main() function to provide dataset and calling preceding-defined functions
def main():
    x = np.array([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14])
    y = np.array([100, 300, 350, 500, 750, 850, 900, 950, 1250, 1350, 1400, 1550, 1600, 1650, 1700])
    b = coef_estimation(x, y)
    print("Estimated coefficients: \nreg_b_0 = {} \nreg_b_1 = {}".format(b[0], b[1]))
    plot_regression_line(x, y, b)

if __name__ == "__main__":
    main()
    