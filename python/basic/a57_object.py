from collections.abc import Iterable    
import random

class TestClss:
    pass

def main():
    t1 = TestClss()

    if isinstance(t1,TestClss):
        print("t1은 TestClass의 객체이다.")
    if isinstance(1,TestClss):
        print("int(1)은 TestClass의 객체이다.")
    else:
        print("int(1)은 TestClass의 객체가 아니다.")

    if issubclass(int, TestClss):
        print("TestClass는 int를 상속받았다.")
    else:
        print("TestClass는 int를 상속 받지 않았다.")
        
    if issubclass(list, Iterable):
        print("list 는 iterable를 상속받았다.")
    else:
        print("list 는 iterable를 상속 받지 않았다.")
    
    if issubclass(TestClss,object):
        print("TestClass 는 object를 상속받았다.")
    else:
        print("TestClass 는 object를 상속받지 않았다.")
        
    print(issubclass(int,object),
          issubclass(float,object),
          issubclass(list,object),
          issubclass(dict,object),
          issubclass(tuple,object),
          issubclass(str,object),
          issubclass(random.Random,object),
          
          )
 
if __name__ == "__main__":
    main()