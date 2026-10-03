	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #0x22]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0804DD72
	ldr r0, _0804DCDC @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0, #3]
	cmp r0, #0
	bne _0804DD72
	ldr r1, _0804DCE0 @ =0x030057F0
	adds r2, r4, #0
	adds r2, #0x21
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r0, [r0, #0x34]
	adds r5, r2, #0
	cmp r0, #0x46
	bne _0804DCE4
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0804DCD2
	adds r0, r4, #0
	adds r0, #0xc4
	bl _call_via_r1
_0804DCD2:
	ldrb r1, [r5]
	movs r0, #8
	bl rfu_clearSlot
	b _0804DCFE
	.align 2, 0
_0804DCDC: .4byte 0x03005800
_0804DCE0: .4byte 0x030057F0
_0804DCE4:
	subs r0, #0x47
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0804DCFE
	movs r1, #0xe1
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0804DCFE
	bl _call_via_r0
_0804DCFE:
	ldrh r1, [r4, #0x22]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0804DD76
	ldrb r1, [r5]
	movs r0, #4
	bl rfu_clearSlot
	adds r0, r6, #0
	ldrb r1, [r5]
	lsls r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r4, #0
	adds r2, #0xb8
	movs r1, #0xe
	movs r3, #0xc
	bl rfu_NI_setSendData
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0804DD6C
	movs r1, #0
	ldr r2, _0804DD64 @ =0x03005800
	ldr r0, [r2]
	ldrb r0, [r0, #2]
	ands r0, r6
	cmp r0, #0
	bne _0804DD52
	adds r3, r2, #0
	movs r2, #1
_0804DD40:
	adds r1, #1
	cmp r1, #3
	bgt _0804DD52
	ldr r0, [r3]
	ldrb r0, [r0, #2]
	asrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _0804DD40
_0804DD52:
	strb r1, [r5]
	ldrh r0, [r4, #0x22]
	ldr r1, _0804DD68 @ =0x0000FFFE
	ands r1, r0
	movs r0, #2
	orrs r1, r0
	strh r1, [r4, #0x22]
	b _0804DD76
	.align 2, 0
_0804DD64: .4byte 0x03005800
_0804DD68: .4byte 0x0000FFFE
_0804DD6C:
	movs r0, #2
	bl FUN_0804e584
_0804DD72:
	movs r0, #0
	b _0804DD78
_0804DD76:
	movs r0, #1
_0804DD78:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
