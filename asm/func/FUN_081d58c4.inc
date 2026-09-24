	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _081D58D4 @ =0x03000198
	ldr r1, [r0]
	cmp r1, #0
	bne _081D58DC
	b _081D591A
	.align 2, 0
_081D58D4: .4byte 0x03000198
_081D58D8:
	adds r0, r1, #0
	b _081D591C
_081D58DC:
	movs r2, #0
	ldr r3, _081D58F8 @ =0x0000057C
	adds r0, r1, r3
	ldr r3, [r0]
	movs r5, #1
	adds r1, #0x1c
_081D58E8:
	adds r0, r5, #0
	lsls r0, r2
	ands r0, r3
	cmp r0, #0
	beq _081D58FC
	movs r0, #1
	b _081D58FE
	.align 2, 0
_081D58F8: .4byte 0x0000057C
_081D58FC:
	movs r0, #0
_081D58FE:
	cmp r0, #0
	beq _081D590E
	movs r6, #0xa8
	lsls r6, r6, #1
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, r4
	beq _081D58D8
_081D590E:
	movs r0, #0xac
	lsls r0, r0, #1
	adds r1, r1, r0
	adds r2, #1
	cmp r2, #3
	ble _081D58E8
_081D591A:
	movs r0, #0
_081D591C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
