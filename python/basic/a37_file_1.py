def main():
    f = open("basic/text1.txt","w")
    print(f.fileno()) #file descripter
    f.write("hello, Python Programming 111\n")
    f.close()

    with open("data/text.txt","a", encoding="utf-8") as f:
        f.write("hello python 222")

if __name__=="__main__":
    main()