	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	adds r6, r4, #0
	adds r6, #0xc4
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _0805E0D0
	movs r0, #0
	strb r0, [r4, #3]
	adds r2, r4, #0
	adds r2, #0x64
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r0, r3, #0
	adds r1, r4, #0
	movs r2, #0
	bl Entity0805e67c_SetElemAnim
	adds r3, r4, #0
	adds r3, #0xc
	ldrb r5, [r4]
	ldrb r7, [r4, #9]
	ldr r2, _0805E0A0 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0805E0A4
	asrs r1, r0, #0xc
	b _0805E0AA
	.align 2, 0
_0805E0A0: .4byte gSineTable
_0805E0A4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805E0AA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0805E0C4 @ =gSineTable
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0805E0C8
	asrs r0, r0, #0xc
	b _0805E0CE
	.align 2, 0
_0805E0C4: .4byte gSineTable
_0805E0C8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805E0CE:
	strh r0, [r3, #4]
_0805E0D0:
	adds r1, r6, #0
	adds r1, #0x1c
	adds r2, r4, #0
	adds r2, #0xc
	ldrh r0, [r4, #0xc]
	ldrh r3, [r6, #0x1c]
	adds r0, r0, r3
	strh r0, [r6, #0x1c]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	ldr r0, [r4, #4]
	ldrb r3, [r4, #8]
	cmp r0, r3
	blo _0805E104
	movs r0, #2
	strb r0, [r4, #2]
	movs r0, #1
	strb r0, [r4, #3]
	movs r0, #0
	b _0805E106
_0805E104:
	adds r0, #1
_0805E106:
	str r0, [r4, #4]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
