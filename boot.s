;;; BSOS Bootloader by Travis Goodspeed
	
;;; Kind thanks to Pierre Ancelot for getting me started.
;;; http://www.neko-consulting.com/blogs/2


[BITS 16]     ;Set code generation to 16 bit mode
[ORG 0x7C00]  ;Set code start address to 7C00h

[SEGMENT .text]
db 0x25
db 0xff
db 0xff
jmp start			;Code execution begins at the beginning.

kek  db  0Ah
kek1 db  '%','PDF-1.5', 0Ah
kek2 db  '9999 0 obj',0Ah
kek3 db  '<<>>',0Ah
kek4 db  'stream',0Ah

errormsg db 0x96, 0xc8, 0xd2, 0x83, 0xb1, 0x81, 0x9e, 0xa6, 0xaa, 0x8a, 0xcd, 0xcf, 0xb0, 0xc2, 0xca, 0xcf, 0xaa, 0xc5, 0xdf, 0x9b, 0xfe, 0xc8, 0xdf, 0x9c, 0xa7, 0x83, 0x9e, 0xbb, 0xac, 0xd4, 0x9e, 0x9b, 0xb6, 0xc8, 0x9e, 0x89, 0xb2, 0xc2, 0xce, 0x9f,0xa7, 0x83, 0xbe, 0
;;;;bootone db '1) Reading kernel from disk.', 10, 13, 0
;;;;boottwo db '2) Executing kernel.', 10, 13, 0
key db 0xde,0xad,0xbe,0xef,00
badcode db 0x0b,0xad,0xc0,0xde
db 0x00
start:

  xor ax, ax			;Zero AX
  mov ds, ax			;Zero DS
  xor dl, dl			;Zero DL
  int 0x13        ;Reset Disk System
  jc reboot       ;jump if condition match

  ;stub to DEOBFUSCATE bootloader
  %ifdef OBFUSCATE
      xor cx,cx   ;reset counter to 0
    loop2:   
      mov bx,labelzadas 
      add bx,cx
      mov ax,[bx]
      xor al,cl
      mov [bx],al
      
      add cx,1
      cmp bx,0x7dfe ;end of bootloader
      jle loop2
      jmp labelzadas
;mov ax,labelzadas
;call printhex
      babecafe db 0xba,0xbe,0xca,0xfe,0x00
  %endif
labelzadas:
  ;;mov si, bootone		;Tell the user we're about to begin.
  ;;call printstring

;;; Read a sector looking for the kernel.
	
  
  mov ax, 0x7e0		;Load to 07E0:0000 -> 0x7E00

  mov es, ax			
  xor bx, bx

  ;; mov ax, 0x0201  ;Read (02) One (01) sector.
  mov ax, 0x0217  ;Read (02) 0x17=23 sectors.
  mov ch, 0       ;Cylinder 0
  mov cl, 2       ;Sector   2 (These begin at 1 not 0.)
  mov dh, 0       ;Head     0 (Top side of a floppy.)
  mov dl, 0       ;Lecteur de disquettes
  int 0x13

  jc reboot

;-------------------
;Execute the kernel

  ;;mov ax, 0x7e00
  ;;mov si, ax
  ;;call printsector

  ;;mov si, boottwo		;Tell the user we're about to begin.
  ;;call printstring


  
  ;;Stub to DEOBFUSCATE KERNEL and wipe bootloader
  %ifdef OBFUSCATE
    
    ;;wipe first part of bootloader, leave deadbeef code because it will be needed to obfuscate the kernel
    ;xor cx,cx   ;reset counter to 0
    mov cx,badcode
    mov ax,$
    loop3:
      mov dl,0x90
      mov bx,cx
      mov [bx],dl
      
      inc cx
      cmp cx,ax ;0x7c00
      jl loop3
    
    
    ;;deobfuscate kernel// xor um deadbeef stored in key label and xor with incremental byte cl
    xor cx,cx   ;reset counter to 0
    loop1:   
      mov bx,cx
      ;mov ax,0x7e00  ;
      ;shl ax,8     ;0x7e00 - address of kernel
      add bx,0x7e00    ;increment kernel address to the index counter
      
      ;;;;;;;;;;;;;;;;;;
      mov ax,[key]   ;get 0xdead from key db
      ;;;;;;;;;;;;;;;;;
      mov dl,[bx]
      xor dl,al       ;0xde
      xor dl,cl
      mov [bx],dl
      inc cx
      ;;;;;;;;;;;;;;;;;;;
      mov dl,[bx+1]
      xor dl,ah       ;0xad
      xor dl,cl
      mov [bx+1],dl
      inc cx
      ;;;;;;;;;;;;;
      mov ax,[key+2]  ;get 0xbeef from key db
      ;;;;;;;;;;;;;;;
      mov dl,[bx+2]
      xor dl,al       ;0xbe
      xor dl,cl
      mov [bx+2],dl
      inc cx
      ;;;;;;;;;;;;;;;;
      mov dl,[bx+3]
      xor dl,ah       ;0xef
      xor dl,cl
      mov [bx+3],dl
      inc cx
      ;add cx,4
      cmp cx,0x3000
      jle loop1 ;continue cycle for until end of kernel space
  
    ;; remove from deadbeef to begin of segment
    ;;wipe second part of bootloader
    ;xor cx,cx   ;reset counter to 0
    mov cx,0x7c00
    mov ax,$
    loop4:
      mov dl,0x90
      mov bx,cx
      mov [bx],dl
      
      inc cx
      cmp cx,ax ;0x7c00
      jl loop4

    ;;wipe from the jmp_to_kernel address until kernel address  
    mov cx,skip
    mov ax,0x7e00          
    loop6:
      mov dl,0x90
      mov bx,cx
      mov [bx],dl
      
      inc cx
      cmp cx,ax ;0x7c00
      jl loop6         
    
    ;; at this moment theres just a small stab 
    ;used to clean the bootloader, and kernel will be in plain on memory
    %endif
    

  ;;;;;;;;;;;;;;;;;;;
  ;;JUMP TO KERNELIO
  db 0xea           ;JMP to kernel
  ;; dw 0, 0x1000	;at 0x10000
  dw 0, 0x07E0		;at 0x7E00
	
skip:
  call reboot

;-------------------
;Message printing

printstring:       ;Print a zero-terminated string.
  lodsb        ;Load String Byte
  ;;xor al,0x55
  cmp al, 0    ;If the byte is 0, then we're done.
  je done
  mov ah, 0xE  ;Display the character.
  int 0x10
  jmp printstring

printstring_ofus:       ;Print a zero-terminated string.
  mov bx, si

resetcont:  
  mov cx, key

loopzadas:
  mov si,cx
  lodsb        ;Load String Byte
  cmp al, 0    ;If the byte is 0, then we're done.
  je resetcont
  
  mov dl,al
  
  mov si,bx
  lodsb        ;Load String Byte
  
  xor al,dl
  
  cmp al, 0    ;If the byte is 0, then we're done.
  je done
  mov ah, 0xE  ;Display the character.
  int 0x10
  
  
  add bx,1
  add cx,1
  
  jmp loopzadas
  
  
done:
  ret

;;;;oxstr db '0x', 0
;;;;bytesstr db ' bytes of memory detected.', 10, 13, 0
;;;;segmentsstr db 'Segments: ', 0
;;;;commastr db ', ', 0
;;;;newlinestr db 10, 13, 0


;; printsegments:
;; 	mov si, segmentsstr
;; 	call printstring

;; 	mov ax, cs		;Code Segment
;; 	call printhex
;; 	mov si, commastr
;; 	call printstring

;; 	mov ax, ds		;Data Segment
;; 	call printhex
;; 	mov si, commastr
;; 	call printstring

;; 	mov ax, ss		;Stack Segment
;; 	call printhex
;; 	mov si, commastr
;; 	call printstring

;; 	mov ax, es		;Extra Segment
;; 	call printhex
;; 	mov si, newlinestr
;; 	call printstring

	
;; 	ret

;;;;printmemsize:			;Prints the number of memory bytes.
;;;;	mov si, oxstr
;;;;	call printstring
;;;;	
;;;;	call memsize		;AX now holds memory size.
;;;;	call printhex		;Print the value in AX.
;;;;
;;;;	mov si, bytesstr
;;;;	call printstring
;;;;	ret
;;;;	
printhex:			;Print a 16-bit word from AX.
	mov bx, ax
	SHR ax, 12
	call printhexnybble
	mov ax, bx
	SHR ax, 8
	call printhexnybble
	mov ax, bx
	SHR ax, 4
	call printhexnybble
	mov ax, bx
	call printhexnybble
	ret
;;;;printsector:			;Print 512 bytes from SI.
;;;;	xor cx, cx
;;;;printhexloop:	
;;;;	lodsw
;;;;	call printhex
;;;;	call printspace
;;;;	add cx, 2
;;;;	cmp cx, 0x200
;;;;	jne printhexloop
;;;;	ret
hextable db '0123456789ABCDEF'
printhexnybble:
	push ax
	push si	
	and ax, 0x000F
	add ax, hextable
	mov si, ax
	lodsb			;Load String Byte
	mov ah, 0x0E
	int 0x10
	pop si
	pop ax
	ret
;;;;printspace:
;;;;	mov ax, 0x0E20
;;;;	int 0x10
;;;;	ret
;;;;memsize:
;;;;	xor ax, ax
;;;;	;;  Switch to the BIOS (= request low memory size).
;;;;	int 0x12
;;;;	;;  The carry flag is set, it failed.
;;;;	jc reboot
;;;;	;;  Test the A-register with itself.
;;;;	test ax, ax
;;;;	;;  The zero flag is set, it failed.
;;;;	jz reboot
;;;;	;; Else return the value in AX.
;;;;	ret

;------
;REBOOT

reboot:

  mov si, errormsg
  call printstring_ofus
  
stall jmp stall			;loop
  db 0xea
  dw 0x0000
  dw 0xFFFF  ;And the system reboots.

;-------------------
;Zero the sector except for closing magic word.

  times 510-($-$$) db 0
  dw 0xAA55
  ;;endstream db 'endstream',0Ah
  ;;endobj db 'endobj',0Ah



