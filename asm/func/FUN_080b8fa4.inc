	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0x12
	movs r2, #3
	bl FUN_080b5b30
	adds r1, r0, #0
	movs r3, #0
	ldr r0, _080B901C @ =0x00001410
	adds r2, r4, r0
	ldrb r0, [r2]
	ldr r6, _080B9020 @ =0x0000141E
	adds r5, r4, r6
	adds r0, r5, r0
	ldrb r0, [r0]
	cmp r3, r0
	bge _080B8FEC
	ldr r0, _080B9024 @ =0x00001419
	adds r6, r4, r0
	ldr r0, _080B9028 @ =0xFFFFF000
	adds r7, r0, #0
	adds r4, r5, #0
_080B8FD2:
	ldrb r0, [r2]
	adds r0, r6, r0
	ldrb r0, [r0]
	adds r0, r0, r3
	orrs r0, r7
	strh r0, [r1]
	adds r1, #2
	adds r3, #1
	ldrb r0, [r2]
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r3, r0
	blt _080B8FD2
_080B8FEC:
	movs r2, #0
	ldr r6, _080B9028 @ =0xFFFFF000
	adds r4, r6, #0
_080B8FF2:
	adds r0, r2, #0
	adds r0, #0x60
	orrs r0, r4
	strh r0, [r1]
	adds r1, #2
	adds r3, #1
	adds r2, #1
	cmp r2, #2
	ble _080B8FF2
	cmp r3, #9
	bgt _080B9016
	ldr r2, _080B902C @ =0x0000F010
	adds r0, r2, #0
_080B900C:
	strh r0, [r1]
	adds r1, #2
	adds r3, #1
	cmp r3, #9
	ble _080B900C
_080B9016:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B901C: .4byte 0x00001410
_080B9020: .4byte 0x0000141E
_080B9024: .4byte 0x00001419
_080B9028: .4byte 0xFFFFF000
_080B902C: .4byte 0x0000F010
