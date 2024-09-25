import matplotlib.pyplot as plt

x = [1, 2, 3, 4, 5]
y = [2, 3, 5, 7, 11]

plt.plot(x, y, marker='o', linestyle='dashdot', color='b', label='Circle')
plt.plot(x, [i + 1 for i in y], marker='s', linestyle='dashed', color='r', label='Square')
plt.plot(x, [i + 2 for i in y], marker='^', linestyle='solid', color='g', label='Triangle Up')

plt.legend()
plt.show()
