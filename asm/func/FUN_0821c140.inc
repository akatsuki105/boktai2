	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0xaf
	lsls r0, r0, #2
	adds r5, r4, r0
	movs r1, #0x10
	adds r0, r4, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0821C166
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _0821C174
_0821C166:
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_0821C174:
	str r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r4, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0821C192
	movs r1, #0xc7
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_080139a0
	b _0821C19C
_0821C192:
	movs r2, #0xc7
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_08013984
_0821C19C:
	ldr r0, [r4, #0x50]
	ldr r1, [r4, #0x54]
	str r0, [r5, #0x20]
	str r1, [r5, #0x24]
	movs r2, #0x80
	lsls r2, r2, #0xa
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	adds r3, r1, #0
	cmp r0, #0
	beq _0821C1D2
	movs r2, #0xef
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r2, [r1]
	adds r0, r2, #2
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xff
	ble _0821C1D2
	adds r0, r2, #0
	subs r0, #0xfe
	strh r0, [r1]
_0821C1D2:
	ldr r2, _0821C1F8 @ =0x085B0A08
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r0, #0xc0
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _0821C1FC
	asrs r0, r0, #0xc
	b _0821C202
	.align 2, 0
_0821C1F8: .4byte 0x085B0A08
_0821C1FC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0821C202:
	adds r0, #0x32
	ldrh r1, [r5, #0x22]
	adds r0, r0, r1
	strh r0, [r5, #0x22]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _0821C22E
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r2, r4, r0
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08022dfc
	ldr r2, _0821C234 @ =0x000003BA
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0821C22E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0821C234: .4byte 0x000003BA
