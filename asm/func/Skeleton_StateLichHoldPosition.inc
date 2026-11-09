	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r2, _0810DBD0 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810DBD4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810DBD6
	.align 2, 0
_0810DBD0: .4byte 0x0000046D
_0810DBD4:
	movs r0, #0
_0810DBD6:
	cmp r0, #0
	beq _0810DBDC
	b _0810DD02
_0810DBDC:
	adds r0, r5, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r6, #0xfe
	lsls r6, r6, #1
	adds r0, r5, r6
	ldrb r1, [r0]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0810DC00
	ldr r0, _0810DBFC @ =0xFFFFFF00
	adds r1, r1, r0
	b _0810DC0E
	.align 2, 0
_0810DBFC: .4byte 0xFFFFFF00
_0810DC00:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0810DC0E
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0810DC0E:
	cmp r1, #0
	bge _0810DC14
	rsbs r1, r1, #0
_0810DC14:
	cmp r1, #0x20
	ble _0810DCD0
	movs r1, #0x80
	lsls r1, r1, #3
	movs r6, #0xe6
	lsls r6, r6, #3
	adds r0, r4, r6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0810DC2E
	movs r0, #1
	b _0810DC30
_0810DC2E:
	movs r0, #0
_0810DC30:
	cmp r0, #0
	bne _0810DD02
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _0810DC4C
	asrs r0, r1, #6
	b _0810DC52
_0810DC4C:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0810DC52:
	lsls r0, r0, #6
	cmp r0, #0
	blt _0810DC5C
	asrs r0, r0, #5
	b _0810DC62
_0810DC5C:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0810DC62:
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	movs r2, #0xee
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _0810DCC0 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r4, _0810DCC4 @ =0x0000046D
	adds r0, r5, r4
	movs r4, #1
	strb r4, [r0]
	ldr r6, _0810DCC8 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r2, [r0]
	movs r3, #0x14
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0810DCCC @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	b _0810DD02
	.align 2, 0
_0810DCC0: .4byte Enemy_ClearStateBegun
_0810DCC4: .4byte 0x0000046D
_0810DCC8: .4byte 0x0000046B
_0810DCCC: .4byte 0x0000046A
_0810DCD0:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r6, #0xec
	lsls r6, r6, #3
	adds r1, r4, r6
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhi _0810DCEE
	ldr r1, _0810DD08 @ =0x0000075C
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810DD02
_0810DCEE:
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r1, _0810DD0C @ =0xFFFFFEFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	adds r0, r5, #0
	bl Skeleton_LichRelocate
_0810DD02:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0810DD08: .4byte 0x0000075C
_0810DD0C: .4byte 0xFFFFFEFF
