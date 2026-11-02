	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _08148B68 @ =0x0000049C
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _08148B7C
	ldr r2, _08148B6C @ =0x000005CC
	adds r0, r5, r2
	ldr r3, [r0]
	movs r1, #0x12
	ldr r6, _08148B70 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r3, #0
	strh r2, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08148B74 @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _08148B78 @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	movs r0, #1
	b _08148BF6
	.align 2, 0
_08148B68: .4byte 0x0000049C
_08148B6C: .4byte 0x000005CC
_08148B70: .4byte 0x0000046D
_08148B74: .4byte 0x00000469
_08148B78: .4byte 0x0000046C
_08148B7C:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r5, r6
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08148BF4
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	movs r1, #1
	movs r6, #0xd2
	lsls r6, r6, #3
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08148BB4
	movs r0, #1
	b _08148BB6
_08148BB4:
	movs r0, #0
_08148BB6:
	cmp r0, #0
	bne _08148BCE
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r6, _08148BFC @ =0x00000546
	adds r0, r5, r6
	ldrh r0, [r0]
	cmp r1, r0
	bge _08148BF4
_08148BCE:
	movs r0, #0x80
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [r0]
	movs r6, #0xd2
	lsls r6, r6, #3
	adds r1, r1, r6
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
_08148BF4:
	movs r0, #0
_08148BF6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08148BFC: .4byte 0x00000546
