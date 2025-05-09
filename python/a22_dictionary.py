def main():
    dict_a = dict()
    dict_b = {1:1,2:2,3:2} #정의 할때 set과 헷갈리지 않게 주의
    #dict_b={1,2,3}-> set class
    dict_c={1,2,3}
    
    print(type(dict_a),type(dict_b),type(dict_c)) 

    a="d"
    dict_d={"a":100,"b":200,"c":300,a:400}
    # dict_d={"a":100,"b":200,"c":300,a:400} #a가 name error 
    
    print(dict_d["a"])
    dict_d["d"]=500
    print(dict_d["d"])
    dict_d["e"]=600
    print(dict_d)
    # print(dict_d["f"]) #key error 발생
    print(dict_d.get("f")) #get은 키에 접근하기위한 함수, None 출력
    
if __name__=="__main__":
    main()