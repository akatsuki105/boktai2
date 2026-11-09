	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _0818A7FC @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818A800
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818A802
	.align 2, 0
_0818A7FC: .4byte 0x0000046D
_0818A800:
	movs r0, #0
_0818A802:
	cmp r0, #0
	beq _0818A816
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0818A816:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r5, #0
	str r5, [sp]
	mov r0, sp
	ldr r2, _0818A860 @ =0x05000002
	bl CpuSet
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r1, r4, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0xff
	ble _0818A870
	ldr r3, _0818A864 @ =FUN_0818a904
	movs r2, #0x22
	ldr r0, _0818A868 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0818A86C @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r5, [r0]
	b _0818A8FC
	.align 2, 0
_0818A860: .4byte 0x05000002
_0818A864: .4byte FUN_0818a904
_0818A868: .4byte 0x0000046D
_0818A86C: .4byte 0x0000046B
_0818A870:
	ldr r3, _0818A884 @ =0x00000484
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0x1d
	bgt _0818A888
	movs r5, #1
	adds r0, r2, #0
	adds r0, #0xa
	b _0818A88E
	.align 2, 0
_0818A884: .4byte 0x00000484
_0818A888:
	movs r5, #2
	adds r0, r2, #0
	adds r0, #0x28
_0818A88E:
	strh r0, [r1]
	ldrb r0, [r4, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r1, #0xff
	ands r3, r1
	ldr r2, _0818A8B4 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0818A8B8
	asrs r1, r0, #0xc
	b _0818A8BE
	.align 2, 0
_0818A8B4: .4byte gSineTable
_0818A8B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818A8BE:
	ldrh r0, [r4, #0x10]
	adds r0, r0, r1
	strh r0, [r4, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _0818A8D6
	asrs r2, r0, #0xc
	b _0818A8DC
_0818A8D6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0818A8DC:
	ldrh r0, [r4, #0x14]
	adds r0, r0, r2
	strh r0, [r4, #0x14]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0xc
	bl FUN_0818fdd8
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0x18
	movs r3, #0
	bl FUN_0818faf0
_0818A8FC:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
