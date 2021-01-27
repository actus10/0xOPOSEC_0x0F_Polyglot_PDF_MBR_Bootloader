import sys
import io
filename = sys.argv[1]
filename_output = sys.argv[2]

zeros_f=open(filename, "rb")
size=zeros_f.seek(0, io.SEEK_END)
zeros_f.seek(0)
index=0
while(zeros:=zeros_f.read(1)):
  if zeros[0]!=0:
    index=zeros_f.tell()
index+=1  
#print (hex(index))
#zeros_f.seek(index)
#print(zeros_f.read())
#print (zeros_f.read(1))
#sys.exit()

g = open(filename_output, 'wb')
key=[0xde,0xad,0xbe,0xef]
i=0
with open(filename, "rb") as f:
    while (byte := f.read(1)):
        # Do stuff with byte
        if f.tell()>index:
          a=byte[0]^0
        else:
          a=byte[0]^key[i%4]^i
        g.write(bytes([a]))
        i+=1
        if i==256:
          i=0
        #a=byte[0]^0xde
        #b=byte[1]^0xad
        #c=byte[2]^0xbe
        #d=byte[3]^0xef
        #g.write(bytes([a]))
        #g.write(bytes([b]))
        #g.write(bytes([c]))
        #g.write(bytes([d]))
g.close()
