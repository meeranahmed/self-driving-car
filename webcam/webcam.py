from multiprocessing.connection import wait
import urllib
import numpy as np
import cv2
from urllib.request import urlopen
import time

while True:
    # videoURL = 'http://172.20.10.4:8080/shot.jpg?rnd=507232'
    videoURL = 'http://192.168.172.235:8080/shot.jpg?rnd=100227'
    Respons = urllib.request.urlopen(videoURL)
    numpy_img = np.array(bytearray(Respons.read()),dtype=np.uint8)
    image = cv2.imdecode(numpy_img ,-1)
    cv2.imwrite(r'E:\SBME\Elec\git\self-driving-car\server\img\auto.png',image)
    time.sleep(2)


 

