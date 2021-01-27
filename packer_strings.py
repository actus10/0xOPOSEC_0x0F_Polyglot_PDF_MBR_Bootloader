import sys
import os
import binascii

filename = sys.argv[1]
filename_output = sys.argv[2]

def encryptStrings(key,stringzadas):
  bolota = []
  keyzadas=[]
  for i in range(0,len(key),2):
    keyzadas.append(key[i])
  size=len(stringzadas)-1
  for i in range(size,-1,-1):
    shift =size-i
    index = shift%len(keyzadas)
    coco = bytes([ ord(stringzadas[i]) ^ keyzadas[index] ^ shift ]) 
    bolota+=coco
  return bolota


konami=[]
vault=[]

g = open(filename_output, 'w')
f = open(filename, "r")
for i in f.readlines():
  if i == '\n': #if line empty skip
    continue
  
  a=i.strip()
  b=a.split("=")
  
  if "//" in b[0]: #if it is a comment skip
    continue
  
  var_name=b[0].split("[")[0].split(" ")[1] #get var name
  
  if "codeKONAMI" in b[0]:     
    #keep konami in a var and it will be used as xor key to konami flag
    hex_array = b[1].split("{")[1].split("}")[0]
    for j in hex_array.split(","):
      konami.append(int(j,16))
    
    konami_out=' {} '.format(', '.join(hex(x) for x in konami))
    #print (konami_out)
    
    out_str = "char " + var_name + "[] = {" + konami_out +"};\n"
    g.write(out_str)
    
    konami.pop() #pop last element which is 0x00, else cipher will be messed up tih the sizes
    continue
  
  var_value=b[1].split('"')[1]
  
  if "vaultPwd" in b[0]:
    for j in var_value:
      vault.append(ord(j))
    
  
  key = os.urandom(6*2)
  #key=[0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa,0xbb]
  if var_name == "flagKONAMI":
    key=[]
    for j in konami:
      key.append(j)
      key.append(os.urandom(1)[0])
  #print (key)
  if var_name == "vaultFlag":
    key=[]
    for j in vault:
      key.append(j)
      key.append(os.urandom(1)[0])
    #print (key) 
   
   
  encrypted=encryptStrings(key,var_value)
  encrypted.reverse()
  
  if var_name == "flagKONAMI" or var_name == "vaultFlag":
    key = os.urandom(len(key)) #reset key to a random value. we know that the key is the konami code
  
  size_str=len(var_value)
  size_key=len(key)
  
  hex_encrypted = ' {} '.format(', '.join(hex(x) for x in encrypted))
  hex_key = ' {} '.format(', '.join(hex(x) for x in key))
  
  
  #print (binascii.hexlify(bytearray(key)))
  
  
  out_str = "char " + var_name + "[] = {" + str(hex(size_str)) + ", " + str(hex(size_key)) + ", " + hex_key + ","+ hex_encrypted +"};\n"
  
  g.write(out_str)
  
g.close()



#saida = encryptStrings(plain) 
#print (len(encryptStrings(plain)))
#print (saida)
