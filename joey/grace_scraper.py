# -*- encoding: utf-8 -*-
import sys

c = ["ㄱ", "ㄲ", "ㄳ", "ㄴ", "ㄵ", "ㄶ", "ㄷ", "ㄹ", "ㄺ", "ㄻ", "ㄼ", "ㄽ", "ㄾ", "ㄿ", "ㅀ", "ㅁ", "ㅂ", "ㅄ", "ㅅ", "ㅆ", "ㅇ", "ㅈ", "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ"]
v = ["ㅏ", "ㅐ", "ㅑ", "ㅒ", "ㅓ", "ㅔ", "ㅕ", "ㅖ", "ㅗ", "ㅘ", "ㅙ", "ㅚ", "ㅛ", "ㅜ", "ㅝ", "ㅞ", "ㅟ", "ㅠ", "ㅡ", "ㅢ", "ㅣ"]		
i = 0; 
j = 0;
k = 0;

for i in range(len(c) - 1):
	for j in range(len(v)):
		print(c[i], end="")
		print(v[j])
		print("");
	print("_______")
	#print(c[i])
	#print(v[k])
'''
	print(c[i], end=" ")
	print(v[k], end=" ")
	print("")
	
	for j in range(len(c)-1):
		print(c[j], end=" ")
		#print(v[cur], end=" ")
		#print(c[j], end= " ")
		print("")
	k = k + 1
'''

def unifind(st, end):
	c = ["ㄱ", "ㄲ", "ㄳ", "ㄴ", "ㄵ", "ㄶ", "ㄷ", "ㄹ", "ㄺ", "ㄻ", "ㄼ", "ㄽ", "ㄾ", "ㄿ", "ㅀ", "ㅁ", "ㅂ", "ㅄ", "ㅅ", "ㅆ", "ㅇ", "ㅈ", "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ"]
	v = ["ㅏ", "ㅐ", "ㅑ", "ㅒ", "ㅓ", "ㅔ", "ㅕ", "ㅖ", "ㅗ", "ㅘ", "ㅙ", "ㅚ", "ㅛ", "ㅜ", "ㅝ", "ㅞ", "ㅟ", "ㅠ", "ㅡ", "ㅢ", "ㅣ"]		
	ci = 0;
	vi = 0;
	enc = st
	enc2 = end
	p = False;
	j=0
	k=0;
	for i in xrange(sys.maxunicode):
		if unichr(i) == enc:
			p=True
		if p:
			s =  unichr(i).encode('utf8')
			if(j > 27):
				print("---------------------")
				j=0
				ci = ci+1
				vi = 0;
			print(s)
			k = k+1
			vi = vi + 1
			
		if unichr(i) == enc2:
			p = False
		j = j + 1
	print(k)
		
#unifind(u'\uAC00', u'\uD7A3')
#unifind(u'\u3131', u'\u318E')
