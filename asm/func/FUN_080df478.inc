	push {r4, r5, r6, lr}
	ldr r0, _080DF4A4 @ =0x03000178
	ldr r4, [r0]
	cmp r4, #0
	beq _080DF4BE
	ldr r0, [r4, #0x38]
	cmp r0, #0
	beq _080DF4BE
	movs r3, #0
	movs r5, #1
	ldr r0, _080DF4A8 @ =0x00000133
	adds r2, r4, r0
	movs r6, #3
_080DF492:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080DF4AC
	movs r0, #1
	b _080DF4AE
	.align 2, 0
_080DF4A4: .4byte 0x03000178
_080DF4A8: .4byte 0x00000133
_080DF4AC:
	movs r0, #0
_080DF4AE:
	cmp r0, #0
	beq _080DF4B6
	strb r6, [r2, #3]
	strb r5, [r2]
_080DF4B6:
	adds r2, #0xfc
	adds r3, #1
	cmp r3, #0x17
	ble _080DF492
_080DF4BE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
