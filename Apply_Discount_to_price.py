class Solution:
    def applyDiscount(self, word: str, discount: int) -> int:
        if(word[0]!='$' or not word[1:].isdigit):
            return word
        
        val=float(word[1:])
        val=val-(discount*val/100.0)

        return "$%s"%format(val,".2f")
    def discountPrices(self, sentence: str, discount: int) -> str:
        l=sentence.split(" ")
        for i in range(len(l)):
            l[i]=self.applyDiscount(l[i],discount)

        return " ".join(l)


s = Solution()
print(s.discountPrices("1 2 $3 4 $5 $6 7 8$ $9 $10$", 100))
