	push {r4, r5, r6, lr}
	movs r1, #0
	ldr r6, _08240800 @ =gMPlayTable
	ldr r2, _08240804 @ =0x03004820
	adds r5, r2, #0
	ldr r4, _08240808 @ =0x0000FFFF
	movs r3, #0
_082407EE:
	cmp r1, #0xa
	bne _0824080C
	ldr r0, [r6, #0x78]
	ldr r0, [r0, #4]
	ands r0, r4
	cmp r0, #0
	bne _0824081A
	strh r0, [r5, #0x14]
	b _0824081A
	.align 2, 0
_08240800: .4byte gMPlayTable
_08240804: .4byte 0x03004820
_08240808: .4byte 0x0000FFFF
_0824080C:
	cmp r1, #0xc
	beq _0824081A
	cmp r1, #0x1d
	beq _0824081A
	cmp r1, #0x1e
	beq _0824081A
	strh r3, [r2]
_0824081A:
	adds r2, #2
	adds r1, #1
	cmp r1, #0x1f
	ble _082407EE
	bl m4aMPlayAllStop
	pop {r4, r5, r6}
	pop {r0}
	bx r0
