def isFascinating(n):
        temp=str(n)+str(2*n)+str(3*n)
        s=set()
        for i in temp:
            s.add(i)
        print(s)
        if(len(s)==9):
            return True
        return False

print(isFascinating(267))