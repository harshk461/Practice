class Solution:
    def isValid(self, s: str) -> bool:
        if (s.isalnum()):
            return False

        if (s[0].isalpha() == False or s[len(s)-1].isalpha() == False and len(s) > 1):
            return False

        hypen = 0
        punch = 0

        for i in s:
            if i == '-':
                hypen += 1
            if (i == '!' or i == '.' or i == ','):
                punch += 1

        if (hypen > 1 or punch > 1):
            return False

        return True

    def countValidWords(self, sentence: str) -> int:
        st = sentence.split(" ")
        count = 0
        for word in st:
            if (self.isValid(word)):
                count += 1

        return count


s = "sjdfd"
print(s[0].isalpha())
