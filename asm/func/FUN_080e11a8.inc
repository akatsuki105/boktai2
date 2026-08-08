	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _080E1208 @ =0x03002BE0
	lsls r2, r2, #2
	adds r0, r2, r0
	ldr r4, [r0]
	cmp r4, #0
	beq _080E1210
	movs r0, #8
	ldr r1, _080E120C @ =0x03002BC0
	adds r1, r2, r1
	ldr r1, [r1]
	ands r1, r0
	cmp r1, #0
	bne _080E1210
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r0, [r4, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _080E1210
	movs r0, #0
	ldrsh r3, [r5, r0]
	movs r7, #0
	ldrsh r2, [r6, r7]
	subs r0, r3, r2
	movs r7, #0x2c
	ldrsh r1, [r4, r7]
	cmp r0, r1
	bgt _080E1210
	adds r0, r3, r2
	cmp r0, r1
	blt _080E1210
	movs r0, #4
	ldrsh r3, [r5, r0]
	movs r5, #4
	ldrsh r1, [r6, r5]
	subs r0, r3, r1
	movs r7, #0x30
	ldrsh r2, [r4, r7]
	cmp r0, r2
	bgt _080E1210
	adds r0, r3, r1
	cmp r0, r2
	blt _080E1210
	adds r0, r4, #0
	b _080E1212
	.align 2, 0
_080E1208: .4byte 0x03002BE0
_080E120C: .4byte 0x03002BC0
_080E1210:
	movs r0, #0
_080E1212:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
