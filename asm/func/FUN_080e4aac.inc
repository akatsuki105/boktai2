	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	adds r4, r3, #0
	ldrh r0, [r6]
	ldrh r1, [r7]
	subs r0, r0, r1
	ldrh r1, [r6, #4]
	ldrh r2, [r7, #4]
	subs r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl FUN_0823785c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, _080E4B30 @ =0x085B0A08
	adds r1, r0, #0
	adds r1, #0x40
	movs r2, #0xff
	ands r1, r2
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r2, #0
	ldrsh r1, [r1, r2]
	ldr r2, [sp, #0x1c]
	muls r1, r2, r1
	asrs r1, r1, #0x10
	strh r1, [r5]
	lsls r1, r0, #1
	adds r1, r1, r3
	movs r2, #0
	ldrsh r1, [r1, r2]
	ldr r2, [sp, #0x1c]
	muls r1, r2, r1
	asrs r1, r1, #0x10
	strh r1, [r5, #4]
	strb r0, [r4]
	movs r0, #0
	ldrsh r1, [r7, r0]
	movs r2, #0
	ldrsh r0, [r6, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _080E4B0E
	rsbs r1, r1, #0
_080E4B0E:
	ldr r0, [sp, #0x14]
	cmp r1, r0
	bhi _080E4B34
	movs r0, #4
	ldrsh r1, [r7, r0]
	movs r2, #4
	ldrsh r0, [r6, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _080E4B24
	rsbs r1, r1, #0
_080E4B24:
	ldr r0, [sp, #0x18]
	cmp r1, r0
	bhi _080E4B34
	movs r0, #1
	b _080E4B36
	.align 2, 0
_080E4B30: .4byte 0x085B0A08
_080E4B34:
	movs r0, #0
_080E4B36:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
