	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r2, r1, #0
	ldr r0, [r2, #4]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0805DAC0
	adds r6, r2, #0
	adds r6, #0xc
	ldr r4, _0805DA5C @ =0x0203B400
	ldr r3, _0805DA60 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _0805DA64 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	ldrh r5, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	mov r3, sp
	adds r4, r1, #0
	adds r4, #0x10
	ldr r2, _0805DA68 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0805DA6C
	asrs r1, r0, #0xc
	b _0805DA72
	.align 2, 0
_0805DA5C: .4byte 0x0203B400
_0805DA60: .4byte 0x030046B8
_0805DA64: .4byte 0x000003FF
_0805DA68: .4byte gSineTable
_0805DA6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805DA72:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0805DA8E
	asrs r0, r0, #0xc
	b _0805DA94
_0805DA8E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805DA94:
	strh r0, [r3, #4]
	mov r2, sp
	mov r1, sp
	ldrh r0, [r6, #0x20]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r6, #0x22]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r6, #0x24]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r2, r7, #0
	adds r2, #0x3c
	movs r0, #0
	mov r1, sp
	bl Puff_Spawn
_0805DAC0:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
