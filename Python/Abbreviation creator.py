word = input("Enter word to be abbreviated: ").strip().split()
abbr = []
for x in word:
    for y in x:
        if y.isalpha():
            abbr.append(y.upper())
            break
        else:
            continue

print(".".join(abbr))
