def main():
    a="leehwaseop"
    b="LEEHWASEOP"
    c="LeeHwaSeop"
    print(a.upper())
    print(a)
    print(b.lower())
    print(c.lower())
    c="    hwa    "
    print(c+"seop")
    print(c.strip()+'seop')
    print(c.lstrip()+'seop')
    print(c.rstrip()+'seop')
    
    d="this is a python class"
    print(d.find("a"))
    print(d[d.find("a")])
    print(d.rfind("a"))
    
    idx=int()
    while d.find("a",idx)!=-1:
        idx=d.find("a",idx)
        print(idx,end=' ')
        idx+=1
    
    f="TrainA10".isalnum()
    print(f)

    f="Train_A10".isalnum()
    print(f)
    
    f="10a".isdecimal()
    print(f)
    
    f="10ff".isspace()
    print(f)
    
    g=d.split()
    print(g)
    
    print("안녕" in "안녕하세요")
    print("유요" in "안녕하세요")
    
    
if __name__=="__main__":
    main()


