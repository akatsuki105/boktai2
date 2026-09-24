	push {r4, lr}
	adds r3, r0, #0
	adds r0, #0xfe
	ldrh r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _081D7856
	movs r2, #0x20
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D783C
	movs r0, #1
	b _081D783E
_081D783C:
	movs r0, #0
_081D783E:
	cmp r0, #0
	beq _081D7856
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r3, r1
	bl FUN_082342a8
	movs r1, #0x21
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
_081D7856:
	pop {r4}
	pop {r0}
	bx r0
