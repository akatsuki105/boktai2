	push {lr}
	adds r3, r0, #0
	asrs r0, r3, #5
	adds r3, r0, #3
	movs r0, #7
	ands r3, r0
	cmp r3, #6
	beq _081E97B4
	cmp r3, #6
	bgt _081E97A6
	cmp r3, #5
	beq _081E97AC
	b _081E97C2
_081E97A6:
	cmp r3, #7
	beq _081E97BC
	b _081E97C2
_081E97AC:
	movs r0, #3
	strb r0, [r1]
	movs r0, #1
	b _081E97C6
_081E97B4:
	movs r0, #2
	strb r0, [r1]
	movs r0, #1
	b _081E97C6
_081E97BC:
	movs r0, #1
	strb r0, [r1]
	b _081E97C6
_081E97C2:
	strb r3, [r1]
	movs r0, #0
_081E97C6:
	strb r0, [r2]
	pop {r0}
	bx r0
