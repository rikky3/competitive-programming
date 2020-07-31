s = input()
vs = cs = s
for x in s:
	if x in ('a', 'e', 'i', 'o', 'u'):
		vs = vs.replace(x, "")
	else:
	    cs = cs.replace(x, "")
print(vs)
print(cs)