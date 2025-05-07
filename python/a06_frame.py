import sys
frame = sys._getframe()
abc=int()
abc=list()

print("현재 프레임: ", frame)
print("코드 객체: ", frame.f_code)
print("로컬 변수: ", frame.f_locals)
print(frame.__dict__.items())
print(frame.__dict__[__name__])

print(__dict__.items())
def main():
    main_frame=sys._getframe()
    print("main_frame.co name",main_frame.f_code.co_name)
    

if __name__=="__main__":
    main()


