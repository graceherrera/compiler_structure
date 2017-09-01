import binascii

print hex(ord("c"))
print format(ord("c"), "x")
print "c".encode("hex")
hex_string = "c".encode("hex")
binary_string = binascii.unhexlify(hex_string)
print binary_string
N = raw_input()
print N.encode("hex")
print hex(ord(N))
print map(bin, bytearray(N))
print bin(int(N, 16))[2:]
print toBinary(N)
