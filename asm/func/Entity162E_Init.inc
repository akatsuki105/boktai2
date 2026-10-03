	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08089AD4 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0xae
	lsls r2, r2, #2
	adds r1, r0, r2
	ldr r0, [r1]
	cmp r0, #0
	bgt _08089AC4
	movs r0, #1
	str r0, [r1]
_08089AC4:
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08089AD8
	bl VM_GetValue
	b _08089ADA
	.align 2, 0
_08089AD4: .4byte 0x030046A0
_08089AD8:
	movs r0, #0x1e
_08089ADA:
	strh r0, [r4, #0x1a]
	movs r0, #0
	strh r0, [r4, #0x18]
	ldr r0, _08089B00 @ =0x030046A0
	ldr r1, [r0]
	movs r2, #0xae
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r0, [r0]
	adds r2, #4
	adds r1, r1, r2
	ldr r1, [r1]
	movs r2, #0
	bl FUN_0809c3c0
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08089B00: .4byte 0x030046A0
