	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081869A0 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081869A4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081869A6
	.align 2, 0
_081869A0: .4byte 0x0000046C
_081869A4:
	movs r0, #0
_081869A6:
	cmp r0, #0
	beq _081869DA
	ldr r4, _08186A5C @ =Octopus_StateSubmerge
	movs r3, #0x22
	ldr r2, _08186A60 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _08186A64 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _08186A68 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r1, #0
	strh r2, [r0]
	adds r0, r5, r6
	strb r1, [r0]
_081869DA:
	ldr r6, _08186A64 @ =0x0000046B
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _08186A54
	ldr r3, _08186A6C @ =Enemy_ClearStateBegun
	movs r4, #1
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r5, r0
	adds r6, #0xe9
	adds r0, r5, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _08186A70 @ =0x00000551
	adds r0, r5, r3
	strb r2, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	movs r1, #3
	subs r3, #0xe9
	adds r0, r5, r3
	strb r1, [r0]
	subs r6, #0xe9
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _08186A74 @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	ldr r3, _08186A78 @ =FUN_080e68d8
	movs r1, #0xe
	adds r6, #1
	adds r0, r5, r6
	strb r4, [r0]
	ldr r4, _08186A64 @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
_08186A54:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08186A5C: .4byte Octopus_StateSubmerge
_08186A60: .4byte 0x0000046D
_08186A64: .4byte 0x0000046B
_08186A68: .4byte 0x00000553
_08186A6C: .4byte Enemy_ClearStateBegun
_08186A70: .4byte 0x00000551
_08186A74: .4byte 0x0000046A
_08186A78: .4byte FUN_080e68d8
