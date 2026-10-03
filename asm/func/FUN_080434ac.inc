	push {r4, r5, lr}
	adds r3, r0, #0
	ldrb r0, [r1, #6]
	lsrs r2, r0, #4
	ldrh r4, [r1, #4]
	ldr r0, _080434D0 @ =0x00000FFF
	ands r0, r4
	ldr r5, _080434D4 @ =0x0000020E
	adds r1, r3, r5
	strh r0, [r1]
	cmp r2, #1
	beq _080434D8
	cmp r2, #1
	ble _08043508
	cmp r2, #2
	beq _08043504
	b _08043508
	.align 2, 0
_080434D0: .4byte 0x00000FFF
_080434D4: .4byte 0x0000020E
_080434D8:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x1c
	ldr r1, _08043500 @ =0x00000226
	adds r2, r3, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x61
	ldrb r0, [r0]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	ldrb r2, [r2]
	cmp r0, r2
	beq _08043508
	movs r0, #8
	b _0804350A
	.align 2, 0
_08043500: .4byte 0x00000226
_08043504:
	movs r0, #9
	b _0804350A
_08043508:
	movs r0, #7
_0804350A:
	pop {r4, r5}
	pop {r1}
	bx r1
