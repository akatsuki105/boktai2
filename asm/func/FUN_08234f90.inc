	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	bl FUN_08234f44
	bl FUN_08234f6c
	adds r1, r0, #0
	cmp r1, #0
	beq _08234FB8
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_08234f80
	movs r0, #0
	b _08234FC0
_08234FB8:
	strh r1, [r4]
	strh r1, [r4, #4]
	movs r0, #1
	rsbs r0, r0, #0
_08234FC0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
