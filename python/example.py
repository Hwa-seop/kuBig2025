#파이썬으로 구구단 출력하기
def main():
    dan=2
    while(dan<10):
        print(dan,"단")
        j=1
        while(j<10):
            print(dan,"*",j,"=",dan*j)
            j+=1
        dan+=1
if __name__ == "__main__":
    main()
         
    
# def main():
#     dan = "23456789"
#     num="123456789"
#     for i in dan:
#         print(f"{i} 단 입니다.")
#         for j in num:
#             print( i, "*", j, "=", int(i)*int(j))

# if __name__ == "__main__":
#     main()
         


