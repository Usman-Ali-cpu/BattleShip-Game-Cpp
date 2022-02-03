import scipy.stats
import numpy as np


def computeSmoothing(x, point):
    values = np.empty(0)
    v = 0
    for xx in x:
        v = 0
        for ptt in point:
            val = scipy.stats.norm.pdf(xx, ptt, 0.5)
            v += val
        values = np.append(values, v)
    return values
