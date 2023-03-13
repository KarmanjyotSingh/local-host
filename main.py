# import required libraries
import numpy as np
import cv2
img = cv2.imread('OIP.jpeg')
z = img.reshape((-1,3))
z = np.float32(z)
criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 10, 1.0)
K = 8
ret,label,center=cv2.kmeans(z,K,None,criteria,10,cv2.KMEANS_RANDOM_CENTERS)
center = np.uint8(center)
res = center[label.flatten()]
res2 = res.reshape((img.shape))
cv2.imwrite('res2.png',res2)
z = res2.reshape((-1,3))
print(res2.shape)
# add the size of the image as the first row
sz = img.shape
print(sz)
np.savetxt('data.csv', z, delimiter=',', fmt='%d')
