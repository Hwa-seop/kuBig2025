def test():
    print("함수가 호출되었습니다.")
    yield "test"


def main():
    print("A")
    test() #return object 만들고 수행
    
    print("B")
    test()
    print(test())


if __name__=="__main__":
    main()