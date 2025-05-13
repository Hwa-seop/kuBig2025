import os

def main():
    print(os.name)
    print(os.getcwd()) #current working directory 
    print(os.listdir()) #director의 list를 보여줌
    
    # os.mkdir("test_dir") #폴더 생성
    # input()
    # os.rmdir("test_dir")#폴더 제거
   
    
    # os.mkdir("test_dir") #폴더 생성
    # os.chdir(os.getcwd()+"/test_dir")
    # print(os.getcwd())
    # os.rmdir("test_dir") 
    
    print(os.system("ls -la"))
 
if __name__=="__main__":
    main()