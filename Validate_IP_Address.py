class Solution:
    def validIPAddress(self, queryIP: str) -> str:
        L=queryIP.split(".")
        size=len(L)

        if(size==4):
            for i in range(4):
                if(L[i].isnumeric()!=True):
                    return "Neither"
                
            return "IPv4"
        if(size==6):
            