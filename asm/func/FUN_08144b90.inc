	push {r4, lr}
	adds r3, r0, #0
	movs r1, #8
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r4, r3, r0
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08144BD4
	movs r2, #0xa
	ldrsh r1, [r3, r2]
	ldr r0, _08144BD8 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x2e
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _08144BB8
	rsbs r1, r1, #0
_08144BB8:
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r1, r0
	bgt _08144BD4
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blo _08144BDC
_08144BD4:
	movs r0, #0
	b _08144BF6
	.align 2, 0
_08144BD8: .4byte 0x03002BE0
_08144BDC:
	movs r0, #0x80
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r3, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0x14
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r0, #1
_08144BF6:
	pop {r4}
	pop {r1}
	bx r1
