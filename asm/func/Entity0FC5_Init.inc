	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0xf8
	movs r5, #0
	str r5, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x6b
	bl VM_GetKeywordValue
	adds r6, r4, #0
	adds r6, #0xf4
	str r0, [r6]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0821B148
	bl Script_GetValue
	movs r2, #0x86
	lsls r2, r2, #1
	adds r1, r4, r2
	lsls r0, r0, #0x10
	str r0, [r1]
	bl Script_GetValue
	movs r3, #0x88
	lsls r3, r3, #1
	adds r1, r4, r3
	lsls r0, r0, #0x10
	str r0, [r1]
_0821B148:
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0821B15E
	bl Script_GetValue
	movs r2, #0x92
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
_0821B15E:
	movs r0, #0x53
	movs r1, #0x40
	bl VM_GetKeywordValue
	adds r1, r4, #0
	adds r1, #0xfc
	str r5, [r1]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r4, r3
	str r5, [r1]
	movs r2, #0x82
	lsls r2, r2, #1
	adds r1, r4, r2
	str r5, [r1]
	adds r3, #8
	adds r1, r4, r3
	str r5, [r1]
	adds r2, #0x24
	adds r1, r4, r2
	movs r2, #0x40
	strh r2, [r1]
	adds r3, #0x22
	adds r1, r4, r3
	strh r2, [r1]
	adds r2, #0xec
	adds r1, r4, r2
	strh r5, [r1]
	adds r3, #4
	adds r1, r4, r3
	strh r5, [r1]
	adds r2, #4
	adds r1, r4, r2
	strh r0, [r1]
	adds r3, #4
	adds r1, r4, r3
	strh r0, [r1]
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
	adds r2, #6
	adds r0, r4, r2
	strh r5, [r0]
	adds r0, r4, #0
	bl FUN_0821aeb0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0821ae64
	ldr r1, _0821B1D8 @ =0x03002C98
	ldr r0, [r6]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r4, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0821B1D8: .4byte 0x03002C98
