	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	ldrh r0, [r5, #0xc]
	cmp r0, #0
	bne _0817BC6C
	ldrh r0, [r5, #0x14]
	cmp r0, #0
	beq _0817BC02
	cmp r0, #4
	bne _0817BC0A
_0817BC02:
	adds r0, r4, #0
	movs r1, #3
	bl FUN_0817db8c
_0817BC0A:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #1
	ldr r2, _0817BC34 @ =0x00000898
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817BC38
	movs r0, #1
	b _0817BC3A
	.align 2, 0
_0817BC34: .4byte 0x00000898
_0817BC38:
	movs r0, #0
_0817BC3A:
	cmp r0, #0
	beq _0817BC54
	ldr r2, _0817BC50 @ =0x085ADB6C
	ldrh r1, [r5, #0x14]
	movs r0, #7
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	b _0817BC6E
	.align 2, 0
_0817BC50: .4byte 0x085ADB6C
_0817BC54:
	ldr r1, _0817BC68 @ =0x085ADB6C
	ldrh r2, [r5, #0x14]
	movs r0, #7
	ands r0, r2
	lsls r0, r0, #1
	adds r1, #0x10
	adds r0, r0, r1
	ldrh r0, [r0]
	b _0817BC6E
	.align 2, 0
_0817BC68: .4byte 0x085ADB6C
_0817BC6C:
	movs r0, #0
_0817BC6E:
	pop {r4, r5}
	pop {r1}
	bx r1
