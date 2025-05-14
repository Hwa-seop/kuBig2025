from dataclasses import dataclass

@dataclass
class Student:
    name : str
    korean : int
    math : int
    english : int
    science : int
    
    def get_sum(self):
        return self.korean+self.math+self.english+self.science    

    
    
def main():
    st1= Student("aaa",80,85,91,100)
    st2= Student("bbb",50,60,65,55)
    print(st1.name,st1.korean,st1.math,st1.english,st1.science)
    print(st2.name,st2.korean,st2.math,st2.english,st2.science)
    print(st1.get_sum())
    
if __name__=="__main__":
    main()