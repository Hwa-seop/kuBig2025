import datetime 
#PATH PYTHONPATH 에 있는.py 파일들 대상 불러온다.
#package 가 import, 폴더
# .so 파일을 import (dynamic loading) -< C모듈 만들기(cpython)
# (.pyi(stub) .so) -> 어딘가에 존재-> github에서 확인-> 실행속도가 빠르기 때문에 사용한다.|| 병렬처리
        # GIL global interpreter lock ->PWM
class Myclass:
    def __str__(self):
        return "test My class"

def main():
    ptime=datetime.datetime.now()
    print(ptime) #__str__오버라이딩이 되어서 나온다.
    myclass=Myclass()
    print(myclass)

    print(ptime.month)
    print(ptime.day)
    print(f"{ptime.year}년 {ptime.month}월 {ptime.day}일")
    
    
if __name__=="__main__":
    main()


