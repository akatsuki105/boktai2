	push {lr}
	adds r1, r0, #0
	movs r2, #0xc
	ldr r3, _0806D004 @ =0x000004C5
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #2
	bne _0806CFF0
	adds r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806CFF0
	movs r2, #8
_0806CFF0:
	ldr r0, _0806D008 @ =0x00000402
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0806CFFC
	subs r2, r2, r0
_0806CFFC:
	cmp r2, #1
	ble _0806D00C
	adds r0, r2, #0
	b _0806D00E
	.align 2, 0
_0806D004: .4byte 0x000004C5
_0806D008: .4byte 0x00000402
_0806D00C:
	movs r0, #2
_0806D00E:
	pop {r1}
	bx r1
	.align 2, 0
