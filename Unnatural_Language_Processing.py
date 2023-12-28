def isVowel(char):
    return char in ['a', 'e']


def breakInto(word):
    syl = []
    curr_syl = ""
    for char in word:
        if (len(curr_syl) == 0):
            curr_syl += char
        elif isVowel(char):
            curr_syl += char
        else:
            syl.append(curr_syl)
            curr_syl = char

    if (len(curr_syl)) > 0:
        syl.append(curr_syl)

    return syl


t = int(input())
while (t > 0):
    n = int(input())
    word = input()
    syl = breakInto(word)
    print(".".join(syl))
