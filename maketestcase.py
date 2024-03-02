import random
import numpy as np
import time

with open('test.inp', 'w') as fi:
    random.seed(time.time())
    lst = np.sort([random.uniform(-100_000_000, 100_000_000) for i in range(1_000_000)])
    for i in lst:
        fi.write(str(i) +' ')
    fi.write('\n')
    lst = reversed(lst)
    for i in lst:
        fi.write(str(i) + ' ')
    fi.write('\n')
    for i in range(8):
        lst = [random.uniform(-100_000_000, 100_000_000) for z in range(1_000_000)]
        for j in lst:
            fi.write(str(j) + ' ')
        fi.write('\n')
    fi.close()    

