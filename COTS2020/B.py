def isPrime(n) : 
    # Corner cases 
    if (n <= 1) : 
        return False
    if (n <= 3) : 
        return True
  
    # This is checked so that we can skip  
    # middle five numbers in below loop 
    if (n % 2 == 0 or n % 3 == 0) : 
        return False
  
    i = 5
    while(i * i <= n) : 
        if (n % i == 0 or n % (i + 2) == 0) : 
            return False
        i = i + 6
  
    return True
t = int(input().strip())
for gg in range(t):
    x,y = list(map(int, input().strip().split()))
    if abs(y-x) == 1:
        if isPrime(x+y):
            print("YES")
        else:
            print("NO")
    else:
        print("NO")
