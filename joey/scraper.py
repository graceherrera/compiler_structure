#from lxml import html
#import requests
import sys
#page = requests.get('https://en.wikipedia.org/wiki/Korean_language')
#print(page.text)
#a = u'\uAC00'.encode('utf-8');
def unifind(st, end):
        enc = st
        enc2 = end
        p = False;
        for i in xrange(sys.maxunicode):
	        if unichr(i) == enc:
		        p=True
	        if p:
		        s =  unichr(i).encode('utf8')
		        print(s)
	        if unichr(i) == enc2:
		        p = False

unifind(u'\uAC00', u'\uD7A3')
#unifind(u'\u3131', u'\u318E')
