def main():
    t = int(input())
    for i in range(t):
        x=input()
        x=x.split(" ")
        n=int(x[0])
        k=int(x[1])
        if(k>500):
            print(1)
        else: 
            for i in range(k):
                residue=n%2
                n>>=1
                n = n+residue
                if(n==0):
                    print(1)
                    break
            if(n!=0):
                print(1/n);

if __name__ == "__main__":
    main()