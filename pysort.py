import numpy as np
from time import time

fi = open('test.inp', 'r')
fo = open('pysort.out', 'w')
lst = np.array(fi.readlines())
for i in range(10):
    a = np.copy(lst[i].split(' '))[:-1].astype(float)
    start = time()
    a = np.sort(a)
    elapse_time = round((time() - start) * 1000)
    fo.write(str(elapse_time)+'\n')

fi.close()
