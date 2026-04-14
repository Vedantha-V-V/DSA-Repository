from array import *
import numpy as np

nparr = np.array([1,2,3,4,5,6],float)
linarr = np.linspace(10, 20)

arr = array('i',[1,2,3,4,5,6])

for i in range(0,6):
    print(arr[i],end="\t")

# Array Insertion
arr.insert(1,50)

arr.append(100)

arr[2] = 200

copy_arr = array(arr.typecode,(x*2 for x in arr))

copy_arr.reverse()

copy_arr.pop(1)
copy_arr.remove(100)

nparr.index(3)

ararr = np.arange(10,20,3)

zeroarr = np.zeros(10)

onearr = np.ones(10)

idarr = np.full(10,5)