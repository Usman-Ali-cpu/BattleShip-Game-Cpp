import scipy.stats
import numpy as np
from matplotlib import pyplot as plt

def computesmoothing(x, point, scale):
    values = np.empty(0)
    v = 0
    for xx in x:
        v = 0
        for ptt in point:
            val = scipy.stats.norm.pdf(xx, ptt, scale)
            v += val
        values = np.append(values, v)
    return values


points = [2, 2, 5, 5, 2, 3, 4, 6, 7, 9]
x = np.linspace(0, 10, 1000)


n = computesmoothing(x, points, 0.5)
for m in n:
    print(m)

plt.plot(x, n)
plt.fill_between(x, n)
plt.show()
