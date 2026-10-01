	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _0801C1FC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0801C1C0
	adds r1, r4, #0
	adds r1, #0x40
	ldrb r0, [r1]
	cmp r0, #1
	bne _0801C1C0
	movs r2, #0
	strb r2, [r1]
	ldr r1, _0801C200 @ =0x00000BC4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xf8
	str r2, [sp]
	movs r2, #4
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0xdc
	bl PlaySound_082406e0
_0801C1C0:
	ldr r0, _0801C1FC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0801C1F2
	adds r1, r4, #0
	adds r1, #0x40
	ldrb r2, [r1]
	cmp r2, #0
	bne _0801C1F2
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0801C200 @ =0x00000BC4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xf8
	str r2, [sp]
	movs r2, #5
	movs r3, #1
	bl MainSprite_SetAnim
	movs r0, #0xdc
	bl PlaySound_082406e0
_0801C1F2:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801C1FC: .4byte 0x030044E0
_0801C200: .4byte 0x00000BC4
