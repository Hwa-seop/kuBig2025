def af():
    a=10
    b=20
    c=30
    return a,b,c

def main():
    a=tuple()
    b=123
    c=a,b #()소괄호는 생략가능
    print(type(c))
    #iteable 하고 list와 차이가 없다. 하지만 tuple은 불변 자료형이다.
    #swap
    a=10
    b=20
    a,b=b,a #콤마로 되어있기에 사실상 튜플임, 그렇기 때문에 가능
    print(a,b)
    print(af()) #튜플 형태로 출력
    for ele in af():
        print(ele)
    
if __name__=="__main__":
    main()