# your code goes here
t=int(input())
for i in range (0,t):
	eq=raw_input()
	eq=eq.replace(" ","")
	tokens = eq.split("=")
	if "machula" in tokens[1]:
		leftTok = [int(x) for x in tokens[0].split("+")]
		rightTok = leftTok[0] + leftTok[1]
		print "%d + %d = %d" % (leftTok[0],leftTok[1],rightTok)
	else:
		leftTok = tokens[0].split("+")
		if "machula" in leftTok[0]:
			leftTokAns = int(tokens[1]) - int(leftTok[1])
			print "%d + %s = %s" % (leftTokAns,leftTok[1],tokens[1])
		else:
			leftTokAns = int(tokens[1]) - int(leftTok[0])
			print "%s + %d = %s" % (leftTok[0],leftTokAns,tokens[1])
