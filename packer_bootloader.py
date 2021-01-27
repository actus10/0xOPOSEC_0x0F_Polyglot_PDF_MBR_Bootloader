import sys
filename = sys.argv[1]
filename_output = sys.argv[2]

with open(filename, 'rb') as f:
    s = f.read()
offset=s.find(b'\xba\xbe\xca\xfe')
f = open(filename, 'rb')
preamble=f.read(offset+5)
g = open(filename_output, 'wb')
g.write(preamble)
i=0
while (byte := f.read(1)):
    # Do stuff with byte
    if(g.tell()>=510):
      i=0
    a=byte[0]^i
    i+=1
    if i==256:
      i=0
    g.write(bytes([a]))
g.close()
