def print_3_times(): #PyTypeObject 무조건 리턴됨
    print("안녕!")
    print("안녕!")
    print("안녕!")

def print_n_times(value: str, n: int):
    print("함수 정상 작동 중...")
    for _ in range(n):
        print(value)
        
        
def print_n_times_variable(n: int,*value: tuple[str]): #가변매개변수는 tuple로 들어간다
    """
    doc string, 설명 쓸때 사용
    """
    print("함수 정상 작동 중...")
    print(type(value))
    for _ in range(n):
        print(value)

def main():
    print_3_times()
    print_n_times("파이썬 최고!", 5)
    print_n_times_variable(5,"파이썬 최고!!")
    
    
if __name__=="__main__":
    main()