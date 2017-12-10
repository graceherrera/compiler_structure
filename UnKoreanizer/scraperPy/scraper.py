# -*- encoding: utf-8 -*-
import sys


def getAtomic(compound):
	q = ["ㄱ", "ㄲ", "ㄳ", "ㄴ", "ㄵ", "ㄶ", "ㄷ", "ㄹ", "ㄺ", "ㄻ", "ㄼ", "ㄽ", "ㄾ", "ㄿ", "ㅀ", "ㅁ", "ㅂ", "ㅄ", "ㅅ", "ㅆ", "ㅇ", "ㅈ", "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ"]
	c = ["ㄱ", "ㄲ", "ㄴ", "ㄷ", "ㄸ", "ㄹ", "ㅁ",  "ㅂ", "ㅃ", "ㅅ", "ㅆ", "ㅇ", "ㅈ", "ㅉ", "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ"]
	v = ["ㅏ", "ㅐ", "ㅑ", "ㅒ", "ㅓ", "ㅔ", "ㅕ", "ㅖ", "ㅗ", "ㅘ", "ㅙ", "ㅚ", "ㅛ", "ㅜ", "ㅝ", "ㅞ", "ㅟ", "ㅠ", "ㅡ", "ㅢ", "ㅣ"]		
	i = 0; 
	j = 0;
	k = 0;
	size = 0;
	a = 0
	for i in range(len(c)):
		for j in range(len(v)):
			if(size >= len(compound)):
				exit()
			print(compound[size], end=' ')
			print(c[i], end=' ')
			print(v[j], end=' ')
			print("");
			size = size+1
			for k in range(len(q)):
				if(size >= len(compound)):
					exit()
				print(compound[size], end=' ')
				print(c[i], end=" ")
				print(v[j], end=" ")
				print(q[k], end=" ")
				print("")
				size = size + 1


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


'''

start = ord(u'\uAC00')
end = ord(u'\uD7A3')

'''
start = ord(u'\u3131')
end = ord(u'\u318E')
'''
index = 0;
result = []
for i in range(start, end):
	result.append(chr(i))

#print(result)	
getAtomic(result)
#print(result)
#print(start, " ", end)
		
#unifind(u'\uAC00', u'\uD7A3')
#unifind(u'\u3131', u'\u318E')
#getAtomic();
