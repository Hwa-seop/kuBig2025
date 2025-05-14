import time
from functools import wraps
  
def runtime_check(value):
    def mydecorator(func):
        @wraps(func)
        def wrapper(*argc,**kwargs):
            start_time = time.time()
            print("지금부터 시간을 체크하겠습니다.")
            result = func(*argc,**kwargs)
            end_time = time.time()
            print(f"실행 시간은{end_time-start_time}입니다.")
            return result
        
        return wrapper
    
    return mydecorator

@runtime_check("시간")
def print_hello(n:int, s:int):
    """n= 반복횟수, s=시작값"""
    for _ in range(n):
        s+=1
    return s
    
def main():
    re = print_hello(50_000_000,10_000_000)
    print(re)
    
if __name__=="__main__":
    main()