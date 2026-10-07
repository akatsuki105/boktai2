	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800D086
	movs r0, #0
	strb r0, [r4, #1]
_0800D086:
	movs r2, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _0800D122
	str r2, [r4, #0x1c]
	ldr r0, [r4, #0x24]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0800D0A4
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800ccd0
	adds r2, r0, #0
_0800D0A4:
	cmp r2, #0
	bne _0800D0EC
	ldr r0, [r4, #0x24]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0800D0BC
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800cd70
	adds r2, r0, #0
_0800D0BC:
	cmp r2, #0
	bne _0800D0EC
	ldr r0, [r4, #0x24]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800D0D4
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800cdb4
	adds r2, r0, #0
_0800D0D4:
	cmp r2, #0
	bne _0800D0EC
	ldr r0, [r4, #0x24]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800D0EC
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800ce24
	adds r2, r0, #0
_0800D0EC:
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _0800D0F6
	movs r0, #0x78
	b _0800D11C
_0800D0F6:
	movs r0, #8
	ldrb r1, [r4, #2]
	ands r0, r1
	cmp r0, #0
	beq _0800D104
	movs r0, #0x7b
	b _0800D11C
_0800D104:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800D110
	movs r0, #0x7c
	b _0800D11C
_0800D110:
	movs r0, #1
	ands r1, r0
	movs r0, #0x7a
	cmp r1, #0
	beq _0800D11C
	movs r0, #0x79
_0800D11C:
	strh r0, [r4, #0x2e]
	cmp r2, #0
	bne _0800D12C
_0800D122:
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_0800cf30
_0800D12C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
