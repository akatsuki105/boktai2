	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	adds r0, r6, #0
	movs r1, #8
	bl ClearMemory
	ldr r2, [r4, #8]
	ldrh r1, [r2]
	movs r3, #8
	ldrsh r0, [r5, r3]
	subs r3, r1, r0
	ldrh r1, [r2, #2]
	movs r2, #0xc
	ldrsh r0, [r5, r2]
	subs r1, r1, r0
	adds r0, r3, #0
	cmp r3, #0
	bge _081D26C4
	rsbs r0, r3, #0
_081D26C4:
	cmp r0, r7
	bhi _081D26EA
	adds r2, r1, #0
	cmp r1, #0
	bge _081D26D0
	rsbs r2, r1, #0
_081D26D0:
	ldr r0, [sp, #0x14]
	cmp r2, r0
	bhi _081D26EA
	ldrh r0, [r5, #8]
	adds r0, r0, r3
	strh r0, [r5, #8]
	ldrh r0, [r5, #0xc]
	adds r0, r0, r1
	strh r0, [r5, #0xc]
	strh r3, [r6]
	strh r1, [r6, #4]
	movs r0, #1
	b _081D2764
_081D26EA:
	cmp r3, #0
	bne _081D26F2
	cmp r1, #0
	beq _081D2762
_081D26F2:
	adds r0, r3, #0
	bl ArcTan2_8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	lsls r3, r0, #6
	strb r3, [r5, #5]
	ldr r1, _081D2724 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x18]
	muls r0, r2, r0
	cmp r0, #0
	blt _081D2728
	asrs r0, r0, #0xc
	b _081D272E
	.align 2, 0
_081D2724: .4byte 0x085B0A08
_081D2728:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D272E:
	adds r2, r0, #0
	ldr r0, _081D2748 @ =0x085B0A08
	lsls r1, r3, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	ldr r1, [sp, #0x18]
	muls r0, r1, r0
	cmp r0, #0
	blt _081D274C
	asrs r1, r0, #0xc
	b _081D2752
	.align 2, 0
_081D2748: .4byte 0x085B0A08
_081D274C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D2752:
	ldrh r0, [r5, #8]
	adds r0, r0, r2
	strh r0, [r5, #8]
	ldrh r0, [r5, #0xc]
	adds r0, r0, r1
	strh r0, [r5, #0xc]
	strh r2, [r6]
	strh r1, [r6, #4]
_081D2762:
	movs r0, #0
_081D2764:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
