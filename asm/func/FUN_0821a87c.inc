	push {r4, r5, r6, r7, lr}
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x6b
	bl VM_GetKeywordValue
	ldr r1, _0821A8CC @ =0x03002C98
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r6, [r0]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0821A8B2
	bl Script_GetValue
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r1, r6, r2
	str r0, [r1]
	bl Script_GetValue
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r1, r6, r2
	str r0, [r1]
_0821A8B2:
	movs r0, #0x50
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _0821A8D0
	bl Script_GetValue
	movs r2, #0x9c
	lsls r2, r2, #1
	adds r1, r6, r2
	str r0, [r1]
	b _0821A8D8
	.align 2, 0
_0821A8CC: .4byte 0x03002C98
_0821A8D0:
	movs r2, #0x9c
	lsls r2, r2, #1
	adds r0, r6, r2
	str r1, [r0]
_0821A8D8:
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	blt _0821A8E8
	asrs r1, r0, #0x10
	b _0821A8EE
_0821A8E8:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
_0821A8EE:
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	subs r7, r0, r1
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	blt _0821A908
	asrs r1, r0, #0x10
	b _0821A90E
_0821A908:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
_0821A90E:
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r4, [r0]
	subs r4, r4, r1
	adds r0, r7, #0
	muls r0, r7, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	bl Sqrt
	adds r5, r0, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r0, r7, #0x10
	adds r1, r5, #0
	bl Div
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r1, r6, r2
	str r0, [r1]
	lsls r4, r4, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	bl Div
	movs r2, #0x90
	lsls r2, r2, #1
	adds r1, r6, r2
	str r0, [r1]
	movs r1, #1
	subs r2, #0x1c
	adds r0, r6, r2
	str r1, [r0]
	movs r0, #0x84
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0
	str r0, [r1]
	movs r2, #2
	adds r1, r6, #0
	adds r1, #0xf8
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
