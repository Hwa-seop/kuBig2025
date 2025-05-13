def main():
    print(a:=range(10)) # := -> 코끼리문. 수식안에서 a를 할당하고 값을 넣고 싶을때
    print(a.count(2))
    print(a.step) #증가 몇씩하나?
    print(a.index(1))
    print(list(a)) #list로 typecasting
    

    for i in range(10):
        print(f"{i}번째 출력입니다.")

    list_a=["lee",123,3.3]
    
    for i,ele in enumerate(list_a): #enumerate
        print(f"{i}번째 원소의 값은 {ele} 입니다.")
            
    num=[0,1,2]
    
    for ele, i in zip(list_a,num): #zip
        print(f"{i}번째 원소의 값은 {ele} 입니다.")

        
if __name__=="__main__":
    main()