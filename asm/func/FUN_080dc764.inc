	push {r4, r5, r6, lr}
	movs r3, #0
	ldr r1, _080DC788 @ =0x00000F68
	adds r4, r0, r1
	movs r5, #1
	adds r2, r0, #0
	adds r2, #0x38
	movs r6, #0xa2
	lsls r6, r6, #1
_080DC776:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080DC78C
	movs r0, #1
	b _080DC78E
	.align 2, 0
_080DC788: .4byte 0x00000F68
_080DC78C:
	movs r0, #0
_080DC78E:
	cmp r0, #0
	bne _080DC7AC
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r1, _080DC7A8 @ =0x0000012F
	adds r0, r2, r1
	strb r3, [r0]
	adds r0, r2, #0
	b _080DC7B6
	.align 2, 0
_080DC7A8: .4byte 0x0000012F
_080DC7AC:
	adds r2, r2, r6
	adds r3, #1
	cmp r3, #0xb
	ble _080DC776
	movs r0, #0
_080DC7B6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
