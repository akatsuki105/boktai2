	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl FUN_080ec518
	cmp r0, #0
	bne _080EC60E
	bl FUN_080ec4ec
	cmp r0, #0
	beq _080EC60E
	movs r0, #1
	b _080EC610
_080EC60E:
	movs r0, #0
_080EC610:
	pop {r1}
	bx r1
