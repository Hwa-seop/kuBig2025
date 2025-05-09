def main():
    with open("data/text.txt", "r",encoding="utf-8") as f:
        #1번
        # str = f.read()
        # sentences= str.split("\n")
        # for line in sentences:
        #     print(line + "//per line")
        # print(str)
        
        #2번
        # lines= f.readlines()
        # for line in lines:
        #     print(line+"//per line")
        
        #3번
        while line := f.readline():
            print(line)
            
            
if __name__=="__main__":
    main()