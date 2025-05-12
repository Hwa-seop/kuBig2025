from collections.abc import Iterable
    
class SimleIter:
    def __init__(self,start,end): #초기화 부분
        self.current=start
        self.end=end
    
    def __iter__(self):
        return self
    
    def __next__(self):
        if self.current >= self.end:
            raise StopIteration
        value = self.current
        self.current += 1
        return value
        

def main():
    iter_a = SimleIter(1,10)
    
    for i in iter_a:
        print(i)
    
    li = list()
    dict_A= dict()
    if isinstance(li,Iterable):
        print("li Iterable 하다")
    if isinstance(dict_A,Iterable):
        print("dict_A Iterable 하다")  
    if isinstance(iter_a,Iterable):
        print("iter_a Iterable 하다")  
        #두 메서드만 정의해도 상속받은것처럼 행동한다.
        
        
if __name__=="__main__":
    main()