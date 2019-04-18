def gcdp(a,b): 
    if(b==0): 
        return a 
    else: 
        return gcdp(b,a%b)
t=int(input())
for olo in range(t):
    y=input().split(' ')
    x=int(y[0])
    y=int(y[1])
    a=input().split(' ')
    obj=[]
    for i in range(len(a)):
        a[i]=int(a[i])
        if i!=0:
            if a[i] == a[i-1]:
                obj[len(obj)-1]["count"]=obj[len(obj)-1]["count"]+1
            else:
                obj.append({"value":a[i],"count":1})
        else:
            obj.append({"value":a[i],"count":1})
    mapmap={}
    for i in range(1,len(obj)):
        a=gcdp(obj[i-1]["value"],obj[i]["value"])
        mapmap[a//1]=1
        mapmap[obj[i-1]["value"]//a]=1
        mapmap[obj[i]["value"]//a]=1
    d=[]
    for i in mapmap:
        appendm=False;
        for j in mapmap:
            for k in mapmap:
                if j*k==i:
                    appendm=True
        if appendm!=True:
            d.append(i)

    m={}
    c={}
    d.sort()
    for o in range(len(d)):
        c[d[o]]=chr(ord('A')+o)
    for j in d:
        for k in d:
            m[j*k]=[c[j],c[k]]
    finalans=[]
    for i in range(1,len(obj)):
        a=gcdp(obj[i-1]["value"],obj[i]["value"])
        if i == 1:
            if a//obj[i-1]["value"]==1:
                finalans.append(m[j*k][0])
                finalans.append(m[j*k][1])
                while obj[i-1]["count"]>1:
                    finalans.insert(0,m[j*k][0])
                    obj[i-1]["count"]=obj[i-1]["count"]-1
            else:
                finalans.append(c[obj[i-1]["value"]//a])
                finalans.append(c[a])
                alt=False
                while obj[i-1]["count"]>1:
                    if not alt:
                        finalans.insert(0,c[a])
                    else:
                        finalans.insert(0,c[obj[i-1]["value"]//a])
                    alt= not alt
                    obj[i-1]["count"]=obj[i-1]["count"]-1
        else:
            start=len(finalans)
            if a//obj[i-1]["value"]==1:
                finalans.append(m[j*k][0])
                while obj[i-1]["count"]>1:
                    finalans.insert(start,m[j*k][0])
                    obj[i-1]["count"]=obj[i-1]["count"]-1
            else:
                finalans.append(c[a])
                alt=True
                while obj[i-1]["count"]>1:
                    if not alt:
                        finalans.insert(start,c[a])
                    else:
                        finalans.insert(start,c[obj[i-1]["value"]//a])
                    alt= not alt
                    obj[i-1]["count"]=obj[i-1]["count"]-1
    i=len(obj)-1
    a=gcdp(obj[i-1]["value"],obj[i]["value"])
    if a//obj[i]["value"]==1:
        finalans.append(m[j*k][1])
        while obj[i]["count"]>1:
            finalans.append(m[j*k][0])
            obj[i]["count"]=obj[i]["count"]-1
    else:
        finalans.append(c[obj[i]["value"]//a])
        alt=False
        while obj[i]["count"]>1:
            if not alt:
                finalans.append(c[a])
            else:
                finalans.append(c[obj[i]["value"]//a])
            alt= not alt
            obj[i]["count"]=obj[i]["count"]-1
    ans="Case #"+str(olo+1)+": "+"".join(finalans)
    print(ans)