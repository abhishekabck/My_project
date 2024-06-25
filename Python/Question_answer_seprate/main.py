Questions = """
1. What is the formula of Mohr's salt?
2. In which forms are chlorides present in water?
3. What is the concentration of chlorides which gives unacceptable tase to water?
4. At what pH can you determine the chloride contenet in water sample?
5. Why does ag2cro4 precipitate after agcl in the determination of chlorde content in water sample?
6. Why it is called Mohr's method?
6. Write the chemical formula of bleaching powder.
7. what is Idometry?
8. what is available chlorine?
9. What is the approximate percentrage of available chorine in commercial bleachinng powder?
10. Is this bleaching powder hygroscopic in nature?
11. What will be the reaction if bleaching poweder reachts with water?
12. What will be chmical name of Hypochlorous acid?
13. Write the chemical structural formula of bakelite?
14. what are thermosetting and thermoplastic polymers?
15. Substitution takes place in phenol on only at ortho and para positions, why?
16. Give various uses of bakelite.
17. Which type of polymerization does take place in the formation of bakelite?
"""
ls_qu = Questions.split("\n")
with open("Python\\Question_answer_seprate\\answers.txt","r") as file:
    data = file.read()
    for i in data:
        print(i)

di = {}
for i in range(len(ls_qu)):
    di[ls_qu[i]] = ls_ans[i]

print(di)
        
