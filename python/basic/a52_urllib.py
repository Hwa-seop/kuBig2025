from urllib import request

def main():
    target = request.urlopen("https://www.google.co.kr/")
    print(target.read())
    
if __name__=="__main__":
    main()