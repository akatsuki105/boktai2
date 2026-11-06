	push {r4, r5, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r3, #6]
	ands r0, r1
	cmp r0, #0
	beq _0805DDFC
	adds r0, r3, #0
	adds r0, #0x42
	ldrb r0, [r0]
	b _0805DE14
_0805DDFC:
	movs r1, #0x24
	ldrsh r0, [r5, r1]
	movs r2, #0x24
	ldrsh r1, [r3, r2]
	subs r0, r0, r1
	movs r2, #0x28
	ldrsh r1, [r5, r2]
	movs r5, #0x28
	ldrsh r2, [r3, r5]
	subs r1, r1, r2
	bl ArcTan2_8
_0805DE14:
	strb r0, [r4]
	movs r0, #4
	movs r1, #0
	strb r0, [r4, #2]
	movs r0, #1
	strb r0, [r4, #3]
	str r1, [r4, #4]
	pop {r4, r5}
	pop {r0}
	bx r0
