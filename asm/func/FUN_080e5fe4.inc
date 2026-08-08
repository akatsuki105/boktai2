	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	mov ip, r3
	ldrh r0, [r4, #0x1c]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldrh r0, [r4, #0x20]
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r0, #0xc
	ldrsh r1, [r4, r0]
	movs r7, #8
	ldrsh r0, [r5, r7]
	subs r1, r1, r0
	cmp r1, #0
	bge _080E6010
	rsbs r1, r1, #0
_080E6010:
	cmp r1, r2
	bhi _080E602C
	movs r0, #0x10
	ldrsh r1, [r4, r0]
	movs r2, #0xc
	ldrsh r0, [r5, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _080E6024
	rsbs r1, r1, #0
_080E6024:
	cmp r1, ip
	bhi _080E602C
	movs r0, #1
	b _080E60B2
_080E602C:
	lsls r0, r6, #0x10
	asrs r2, r0, #0x10
	lsls r0, r3, #0x10
	cmp r2, #0
	bne _080E603A
	cmp r0, #0
	beq _080E60B0
_080E603A:
	asrs r1, r0, #0x10
	adds r0, r2, #0
	bl FUN_0823785c
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r2, _080E6064 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	ldr r1, [sp, #0x14]
	muls r0, r1, r0
	cmp r0, #0
	blt _080E6068
	asrs r1, r0, #0x10
	b _080E606E
	.align 2, 0
_080E6064: .4byte 0x085B0A08
_080E6068:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
_080E606E:
	movs r2, #0x83
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	adds r0, r0, r1
	ldrh r7, [r5, #0x10]
	adds r0, r0, r7
	strh r0, [r5, #0x10]
	ldr r1, _080E6094 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x14]
	muls r0, r2, r0
	cmp r0, #0
	blt _080E6098
	asrs r1, r0, #0x10
	b _080E609E
	.align 2, 0
_080E6094: .4byte 0x085B0A08
_080E6098:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
_080E609E:
	movs r7, #0x84
	lsls r7, r7, #2
	adds r0, r5, r7
	ldrh r0, [r0]
	adds r0, r0, r1
	ldrh r1, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
	strb r3, [r5, #5]
_080E60B0:
	movs r0, #0
_080E60B2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
