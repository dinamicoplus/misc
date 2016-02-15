"""
Demo of a line plot on a polar axis.
"""
import numpy as np
import matplotlib.pyplot as plt
import coorToDeg as ctd

ra = [];
de = [];
f = open("simbad(1).txt");
for l in f:
    d=l.split(" : ");
    if(len(d)>1):
        coor=d[1].split(" - ");
        ra.append(ctd.timeToDeg(coor[0]));
        de.append(ctd.degToDeg(coor[1]));

r = np.subtract(90,de);
theta = np.multiply(ra,np.pi/180);
ax = plt.subplot(111, polar=True)
ax.plot(theta, r, 'ro')
ax.set_rmax(130)
ax.grid(True)

ax.set_title("Equidistant Azimutal Projection", va='bottom')
plt.show()
