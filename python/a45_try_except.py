import traceback

def main():
    user_input = input("정수 입력: ")
    try:
        number = int(user_input)
    except ValueError as e:
        print("정수를 입력하지 않았습니다.")
        print(e) # error의 이유를 알려줌 
        traceback.print_exc() #에러가 일어난 코드를 보여줌

    else:    
        print("원의 반지름: ",number)
        print("원의 넓이: ",3.1414592*number**2)
    finally:
        print(f"리소스를 제거하고 프로그램을 종료합니다.")
        
if __name__=="__main__":
    main()