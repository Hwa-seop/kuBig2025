import random #랜덤함수
def main():
    li=[random.randint(0,100) for _ in range(100)] #_-> 변수는 만들지만 이변수를 쓰지않겠다.
    
    print(li)
    print(max(li),min(li),sum(li), sum(li)/len(li))

if __name__=="__main__":
    main()