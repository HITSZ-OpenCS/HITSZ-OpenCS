data	segment
	Y	dw	06F3CH
	count	dw	?
data	ends

prog	segment
	assume	cs: prog, ds: data
start:	mov	ds, data	
	mov	cx, 0	
	mov	ax, Y	
testing: 	and 	ax, ax	
	jz	exit	
	inc	cx	
shift: 	shl	ax, 1	
	jmp 	testing
exit: 	mov	count, cx
	mov 	ah, 4ch
	int 	21h
prog ends
	end