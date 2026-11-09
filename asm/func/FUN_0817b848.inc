	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r1, [r5, #0x44]
	ldr r0, _0817B8A4 @ =0x03002BE0
	mov r2, sp
	adds r4, r1, #0
	adds r4, #0x1c
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r1, #0x1c]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	adds r3, r0, #0
	ldr r2, _0817B8A8 @ =gSineTable
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0817B8AC
	asrs r1, r0, #0xc
	b _0817B8B2
	.align 2, 0
_0817B8A4: .4byte 0x03002BE0
_0817B8A8: .4byte gSineTable
_0817B8AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0817B8B2:
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldr r1, _0817B8D4 @ =gSineTable
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0817B8D8
	asrs r1, r0, #0xc
	b _0817B8DE
	.align 2, 0
_0817B8D4: .4byte gSineTable
_0817B8D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0817B8DE:
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r3, r5, r4
	strh r1, [r3]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, #0
	beq _0817B904
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #0
	ldrsh r1, [r2, r3]
	bl Div
	b _0817B91A
_0817B904:
	cmp r1, #0
	beq _0817B918
	mov r0, sp
	movs r4, #4
	ldrsh r0, [r0, r4]
	movs r2, #0
	ldrsh r1, [r3, r2]
	bl Div
	b _0817B91A
_0817B918:
	movs r0, #0
_0817B91A:
	cmp r0, #0
	blt _0817B922
	asrs r0, r0, #1
	b _0817B928
_0817B922:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0817B928:
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r1, r5, r3
	strh r0, [r1]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
