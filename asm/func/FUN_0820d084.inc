	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_0820cbfc
	adds r5, r0, #0
	adds r0, r4, #0
	bl FUN_0820cc0c
	adds r6, r0, #0
	movs r4, #0
	cmp r4, r5
	bge _0820D0B0
_0820D09C:
	adds r0, r6, r4
	bl FUN_0820d00c
	cmp r0, #0
	bne _0820D0AA
	movs r0, #0
	b _0820D0B2
_0820D0AA:
	adds r4, #1
	cmp r4, r5
	blt _0820D09C
_0820D0B0:
	movs r0, #1
_0820D0B2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
