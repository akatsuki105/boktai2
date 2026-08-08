	push {r4, r5, r6, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x10
	orrs r5, r1
	lsls r2, r2, #0x12
	orrs r5, r2
	lsls r3, r3, #0x14
	orrs r5, r3
	ldr r4, _0822E908 @ =0x003FFFFF
	ands r5, r4
	bl FUN_0822e8c8
	adds r2, r0, #0
	movs r3, #0
	adds r6, r4, #0
	movs r4, #0xff
	lsls r4, r4, #0x16
_0822E8F2:
	ldr r1, [r2]
	adds r0, r1, #0
	ands r0, r6
	cmp r0, r5
	bne _0822E90C
	ands r1, r4
	cmp r1, #0
	beq _0822E90C
	adds r0, r3, #0
	b _0822E918
	.align 2, 0
_0822E908: .4byte 0x003FFFFF
_0822E90C:
	adds r2, #4
	adds r3, #1
	cmp r3, #0xff
	ble _0822E8F2
	movs r0, #1
	rsbs r0, r0, #0
_0822E918:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
