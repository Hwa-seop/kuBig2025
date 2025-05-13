import random
from random import randint,uniform

def main():
    for _ in range(3):
        print("random()",random.random()) #0~1 사이 float값
        print("uniform(10,20) : ",uniform(10,20))
        print("randint() : ",randint(4,15))
        print(f"range(200) :  {random.randrange(200)}")
        print(f"choice : {random.choice([1,2,3,4,5])}")
        print(f"choices : ", random.choices([1,2,3,4,5],k=3))
        li=[1,2,3,4,5]
        random.shuffle(li)
        print("shuffle : ",li)
        print("sample : ",random.sample([1,2,3,4,5],k=5))

if __name__=="__main__":
    main()