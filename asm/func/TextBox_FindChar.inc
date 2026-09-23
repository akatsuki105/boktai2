	push {lr}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	b _08048CD2
_08048CD0:
	adds r0, #1
_08048CD2:
	ldrb r2, [r0]
	cmp r2, r1
	beq _08048CDC
	cmp r2, #0
	bne _08048CD0
_08048CDC:
	pop {r1}
	bx r1
