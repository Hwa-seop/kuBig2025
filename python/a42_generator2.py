def test():
    print("test A")
    yield "1"
    print("test B")
    yield "2"
    print("test C")
    yield "3"


def main():
    print("main A")
    output = test() #return object 만들고 수행
    
    print("main B")
    for i in output:
        print(i)
    print("main C")
    
    test()
    print(test())


if __name__=="__main__":
    main()