	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0822e8c8
	adds r1, r0, #0
	ldr r0, _0822EA40 @ =0xFFFFFF00
	adds r4, r4, r0
	cmp r4, #0xff
	bhi _0822EA58
	lsls r0, r4, #2
	adds r3, r0, r1
	ldr r2, [r3]
	movs r0, #0xff
	lsls r0, r0, #0x16
	ands r0, r2
	lsrs r1, r0, #0x16
	cmp r1, #0
	ble _0822EA58
	subs r1, #1
	cmp r1, #0
	bgt _0822EA44
	movs r0, #0
	str r0, [r3]
	b _0822EA4E
	.align 2, 0
_0822EA40: .4byte 0xFFFFFF00
_0822EA44:
	ldr r0, _0822EA54 @ =0xC03FFFFF
	ands r2, r0
	lsls r0, r1, #0x16
	orrs r2, r0
	str r2, [r3]
_0822EA4E:
	movs r0, #1
	b _0822EA5A
	.align 2, 0
_0822EA54: .4byte 0xC03FFFFF
_0822EA58:
	movs r0, #0
_0822EA5A:
	pop {r4}
	pop {r1}
	bx r1
