	push {r4, r5, lr}
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x6b
	bl Script_GetKeywordValue
	ldr r1, _0821A9D4 @ =0x03002C98
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _0821A9A8
	movs r0, #0x95
	lsls r0, r0, #1
	adds r5, r4, r0
	ldrh r0, [r5]
	movs r2, #0x94
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	bl Script_GetValue
	strh r0, [r5]
_0821A9A8:
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _0821A9BE
	bl Script_GetValue
	movs r2, #0x96
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
_0821A9BE:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r2, #0x97
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0821A9D4: .4byte 0x03002C98
