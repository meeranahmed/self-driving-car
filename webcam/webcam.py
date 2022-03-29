from multiprocessing.connection import wait
import urllib
import numpy as np
import cv2
from urllib.request import urlopen
import time

while True:
    videoURL = 'http://192.168.100.6:8080/shot.jpg?rnd=579668'
    Respons = urllib.request.urlopen(videoURL)
    numpy_img = np.array(bytearray(Respons.read()),dtype=np.uint8)
    image = cv2.imdecode(numpy_img ,-1)
    cv2.imwrite(r'E:\SBME4\2nd semester\electronics\Task3\client\webcam\auto.png',image)
    time.sleep(10)


 

