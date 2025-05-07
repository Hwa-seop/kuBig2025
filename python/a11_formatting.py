def main():
    string ='abc'
    string2 ='this is format test: {}'.format(10) 
    print(string)
    print(string2)
    string3='this is format test: {} {} {}'.format(10,20,30)
    print(string3)
    
    string3='this is format test: {2:d},{1:5d},{0:05d}'.format(10,20,30)
    print(string3)

    string3='this is format test: {2:+f},{1:+5f},{0:+05.2f}'.format(-10.123,20.53,-30)
    print(string3)

    string3=f'this is format test: {-30:+f},{20.53:+5f},{-10.256:+05.2f} {3+3:4.2f}' #fstring
    print(string3)

if __name__=="__main__":
    main()


