	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0xe6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809FCC4
	adds r0, r4, #0
	adds r0, #0xe8
	ldrh r1, [r0]
	ldr r0, _0809FC40 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r1, r0
	bne _0809FC48
	adds r0, r4, #0
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809FC30
	adds r2, r4, #0
	adds r2, #0x92
	ldrh r1, [r2]
	ldr r0, _0809FC44 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
_0809FC30:
	adds r0, r4, #0
	adds r0, #0xf0
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	b _0809FCD0
	.align 2, 0
_0809FC40: .4byte 0x030046A0
_0809FC44: .4byte 0x0000FFFB
_0809FC48:
	adds r0, r4, #0
	adds r0, #0xe7
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _0809FCD0
	subs r0, #0xb
	ldrb r5, [r0]
	cmp r5, #0
	bne _0809FC7C
	ldr r2, _0809FC78 @ =FUN_0809fabc
	adds r0, r4, #0
	movs r1, #0
	bl Entity1DBEElem_SetState
	movs r0, #0
	strh r5, [r4, #0x10]
	adds r1, r4, #0
	adds r1, #0xe5
	strb r0, [r1]
	subs r1, #6
	strb r0, [r1]
	b _0809FCAE
	.align 2, 0
_0809FC78: .4byte FUN_0809fabc
_0809FC7C:
	cmp r5, #2
	bne _0809FC94
	ldr r2, _0809FC90 @ =FUN_0809f8e4
	adds r0, r4, #0
	movs r1, #2
	bl Entity1DBEElem_SetState
	movs r0, #8
	b _0809FCA4
	.align 2, 0
_0809FC90: .4byte FUN_0809f8e4
_0809FC94:
	cmp r5, #1
	bne _0809FCAE
	ldr r2, _0809FCC0 @ =FUN_0809f7fc
	adds r0, r4, #0
	movs r1, #2
	bl Entity1DBEElem_SetState
	movs r0, #5
_0809FCA4:
	strh r0, [r4, #0x10]
	adds r1, r4, #0
	adds r1, #0xe2
	movs r0, #0x10
	strh r0, [r1]
_0809FCAE:
	adds r3, r4, #0
	adds r3, #0x92
	ldrh r0, [r3]
	movs r1, #4
	movs r2, #0
	orrs r1, r0
	strh r1, [r3]
	strb r2, [r6]
	b _0809FCD0
	.align 2, 0
_0809FCC0: .4byte FUN_0809f7fc
_0809FCC4:
	adds r0, r4, #0
	adds r0, #0xf0
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0809FCD0:
	adds r1, r4, #0
	adds r1, #0xd0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0809FCDE
	subs r0, #1
	strh r0, [r1]
_0809FCDE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
