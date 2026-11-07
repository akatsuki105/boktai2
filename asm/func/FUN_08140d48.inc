	push {r4, r5, lr}
	adds r5, r0, #0
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08140DC6
	adds r1, #0xcc
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #2
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08140D88
	movs r0, #1
	b _08140D8A
_08140D88:
	movs r0, #0
_08140D8A:
	cmp r0, #0
	beq _08140DC6
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	movs r3, #0
	movs r4, #0
	orrs r0, r1
	strh r0, [r2]
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _08140DCC @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #2
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_08140DC6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08140DCC: .4byte 0x00000484
