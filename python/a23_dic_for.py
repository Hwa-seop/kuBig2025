def main():
    dict_a = dict()
    list_A=["사라질까??","음..."]
    dict_b = {1:1,2:2,3:list_A} #정의 할때 set과 헷갈리지 않게 주의
    #dict_b={1,2,3}-> set class
 
    print(type(dict_a),type(dict_b)) 

    a="d"
    dict_c={"a":100,"b":200,"c":300,a:400}
    
    for i in dict_c:
        print(i,dict_c[i],end=" ")
    print()        

    for k,v in dict_c.items():
        print(k,v,end=", ")
    print()
    
    dict_b.update(dict_c) #내부 데이터가 변하는 메소드!
    print(dict_b)
    
    del dict_b[3]
    print(dict_b)
    # del list_A
    print(list_A)
    print(dict_b.pop(2)) #제거와 동시에 쓰일때!
    print(dict_b)

if __name__=="__main__":
    main()