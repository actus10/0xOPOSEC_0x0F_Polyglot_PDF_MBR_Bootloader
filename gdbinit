source /home/anon/.gdbinit-gef.py

target remote localhost:1234
set tdesc filename target.xml
# break on banner
b *0x861c
c
#bypass banner to rootkit login
set $eip=0x880a-$cs*0x10
b *0x8839
#skip login
set $eip=0x883b-$cs*0x10
#skip boot counter
b *0x96ab
c

#skip count verification to print flags and stuff
set $eip=0x96ad-$cs*0x10
#intercept decrypt method and change args
b *0x92de
c
########set $flag=*(short *)($sp)

#replace obfs flag addr
set {short}($sp) =0x9846 
#last method replace to begin of decrypt
del
b *0x9313
c

#jump again to decrypt flag
set $eip=0x92d3-$cs*0x10
b *0x92de
c
 set {short}($sp) =0x97f6
del
b *0x9313
c

set $eip=0x92d3-$cs*0x10
b *0x92de
c
set {short}($sp) =0x9874
del
b *0x9313
c

set $eip=0x92d3-$cs*0x10
b *0x92de
c
set {short}($sp) =0x98ab
del
b *0x9313
c
del
set $eip=0x9414-$cs*0x10
#b *0x9469
c

#set $eip=0x9028-$cs*0x10
#b *0x908f
#c


#set {short}($sp+4)=0x7c00
#set *(char [8] *) 0x7c00 = "bolorei"
#del
#b *0x90a2
#c


#c

