#파이썬으로 구구단 출력하기
def main():
    # a=2
    # while(a<10):
    #     print(a,"단")
    #     index=1
    #     while(index<10):
    #         print(a,"*",index,"=",a*index)
    #         index+=1
    #     a+=1
    
    dan="23456789"
    for i in dan:
        print(f"{i}단 입니다.")
        for j in dan:
            print(i,"*",j,"=",i*j)
             
    
if __name__=="__main__":
    main()


