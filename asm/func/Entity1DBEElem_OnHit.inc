	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	adds r3, r2, #0
	adds r5, r3, #0
	adds r6, r7, #0
	adds r6, #0x44
	ldrh r0, [r6]
	cmp r0, #0
	bne _0809F7F6
	movs r1, #4
	ldr r0, [r4, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _0809F7F6
	ldr r2, [r4, #0x38]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0809F7BC
	adds r0, r3, #0
	adds r0, #0xdc
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809F7A0
	ldr r2, _0809F79C @ =FUN_0809f938
	adds r0, r3, #0
	movs r1, #2
	bl Entity1DBEElem_SetState
	b _0809F7AE
	.align 2, 0
_0809F79C: .4byte FUN_0809f938
_0809F7A0:
	cmp r0, #1
	bne _0809F7AE
	ldr r2, _0809F7B8 @ =FUN_0809f890
	adds r0, r3, #0
	movs r1, #0
	bl Entity1DBEElem_SetState
_0809F7AE:
	adds r1, r7, #0
	adds r1, #0x44
	movs r0, #0x1e
	strh r0, [r1]
	b _0809F7F6
	.align 2, 0
_0809F7B8: .4byte FUN_0809f890
_0809F7BC:
	movs r0, #8
	ands r2, r0
	cmp r2, #0
	beq _0809F7E4
	adds r0, r3, #0
	adds r0, #0xdc
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809F7D8
	ldr r2, _0809F7E0 @ =FUN_0809f840
	adds r0, r3, #0
	movs r1, #1
	bl Entity1DBEElem_SetState
_0809F7D8:
	movs r0, #0x1e
	strh r0, [r6]
	b _0809F7F6
	.align 2, 0
_0809F7E0: .4byte FUN_0809f840
_0809F7E4:
	adds r0, r5, #0
	adds r0, #0xdc
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809F7F6
	adds r1, r5, #0
	adds r1, #0xdf
	movs r0, #1
	strb r0, [r1]
_0809F7F6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
