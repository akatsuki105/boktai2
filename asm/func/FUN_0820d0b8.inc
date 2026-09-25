	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	bl FUN_0820cbfc
	adds r5, r0, #0
	adds r0, r4, #0
	bl FUN_0820cc0c
	adds r7, r0, #0
	movs r6, #0
	movs r4, #0
	cmp r6, r5
	bge _0820D0E4
_0820D0D2:
	adds r0, r7, r4
	bl FUN_0820d00c
	cmp r0, #1
	bne _0820D0DE
	adds r6, #1
_0820D0DE:
	adds r4, #1
	cmp r4, r5
	blt _0820D0D2
_0820D0E4:
	adds r0, r6, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
