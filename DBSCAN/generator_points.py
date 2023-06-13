import matplotlib.pyplot as plt
import numpy as np
from sklearn.datasets import make_blobs

archivo=open("points.txt","w")

X, y = make_blobs(n_samples=100,centers=3,n_features=2)
#plt.scatter(X[:,0], X[:,1])
#np.set_printoptions(precision=4,suppress=True)

a = np.array(X)

for i in a:

    archivo.write(f"[{i[0]},{i[1]}]\n")

archivo.close()