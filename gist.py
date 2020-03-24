import matplotlib.pyplot as plt
import numpy as np
from scipy.stats import chisquare

num = np.loadtxt("gist.txt")

plt.hist(num, color = 'aqua', edgecolor = 'black', bins = [0.,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.])

plt.title('Generator Histogram')
plt.show()

p = np.loadtxt("gg.txt")
a = chisquare(p, [100,100,100,100,100,100,100,100,100,100], ddof = -990)
print(a)