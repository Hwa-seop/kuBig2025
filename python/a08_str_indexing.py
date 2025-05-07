def main():
    print("화이팅")
    print("화이팅"[0])
    print("화이팅"[1])
    print("화이팅"[2])
    
    say_fighting="화이팅"
    print(say_fighting[0],end=' ')
    print(say_fighting[1],end=' ')
    print(say_fighting[2])
    
    for c in say_fighting:
        print(c,end='')
    print()

    say_fighting*=3
    
    print(say_fighting)
    print(say_fighting[2:5])
    print(say_fighting[-3:])
    print(say_fighting[0::3])
    print(say_fighting[-1::-1])
    print("say_fighting의 길이 : ",say_fighting.__len__()) #len() 함수 호출하면 .__len__()이 실행된다.
    
if __name__=="__main__":
    main()
