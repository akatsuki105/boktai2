	push {r4, r5, lr}
	adds r2, r0, #0
	movs r3, #0
	ldr r0, _080D9990 @ =0x000009FC
	adds r4, r2, r0
	movs r5, #1
_080D9980:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080D9994
	movs r0, #1
	b _080D9996
	.align 2, 0
_080D9990: .4byte 0x000009FC
_080D9994:
	movs r0, #0
_080D9996:
	cmp r0, #0
	bne _080D99B6
	movs r0, #0x9a
	lsls r0, r0, #1
	muls r0, r3, r0
	adds r0, #0x5c
	adds r0, r2, r0
	adds r2, r5, #0
	lsls r2, r3
	ldr r1, [r4]
	orrs r1, r2
	str r1, [r4]
	adds r1, r0, #0
	adds r1, #0x39
	strb r3, [r1]
	b _080D99BE
_080D99B6:
	adds r3, #1
	cmp r3, #7
	ble _080D9980
	movs r0, #0
_080D99BE:
	pop {r4, r5}
	pop {r1}
	bx r1
