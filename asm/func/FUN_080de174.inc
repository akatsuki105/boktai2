	push {r4, r5, lr}
	adds r2, r0, #0
	movs r3, #0
	movs r5, #1
	ldr r0, _080DE198 @ =0x00000137
	adds r0, r0, r2
	mov ip, r0
	adds r4, r2, #0
	adds r4, #0x40
_080DE186:
	adds r0, r5, #0
	lsls r0, r3
	ldr r1, [r2, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080DE19C
	movs r0, #1
	b _080DE19E
	.align 2, 0
_080DE198: .4byte 0x00000137
_080DE19C:
	movs r0, #0
_080DE19E:
	cmp r0, #0
	bne _080DE1B8
	adds r0, r5, #0
	lsls r0, r3
	orrs r0, r1
	str r0, [r2, #0x38]
	ldrh r0, [r2, #0x3e]
	adds r0, #1
	strh r0, [r2, #0x3e]
	mov r0, ip
	strb r3, [r0]
	adds r0, r4, #0
	b _080DE1C6
_080DE1B8:
	movs r0, #0xfc
	add ip, r0
	adds r4, #0xfc
	adds r3, #1
	cmp r3, #0x17
	ble _080DE186
	movs r0, #0
_080DE1C6:
	pop {r4, r5}
	pop {r1}
	bx r1
