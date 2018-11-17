from sys import stdin, stdout
def main():
    x, y = [int(x) for x in stdin.readline().split()] 
    arr =[None]*x;
    op=""
    for i in range(x):
        arr[i]=int(stdin.readline(),2)
    for j in range(y):
        a, b ,c = stdin.readline().split()
        a=int(a)
        b=int(b)
        c=int(c,2)
        index=a-1
        for k in range(a-1,b):
            if((arr[k]^c)>(arr[index]^c)):
                index=k
        op+=str(index+1)+"\n"
    stdout.write(op)


if __name__ == "__main__":
    main()