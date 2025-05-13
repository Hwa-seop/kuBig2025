def main():

    li=[x for x in range(10)]
    # map 활용
    output=map(lambda x: x**2,li)
    print(list(output))
    print()
    #filter 활용
    output = filter(lambda x: x<50,li)
    print(list(output))
    
    output = filter(lambda x: x%2==0,li)
    print(list(output))
    
    
if __name__=="__main__":
    main()