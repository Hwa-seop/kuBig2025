import math #모듈 명 명시 해야함 math.pi
# sudo python3 -m pip install numpy
# from math import * #math.pi 같이 쓰기싫어서 단순히 pi라고만 써도된다.

from math import e,pi,sin,tau
import numpy as np

def main():
    print(pi,e,tau)
    print(sin(30/180*pi)) #sin 30도

if __name__=="__main__":
    main()