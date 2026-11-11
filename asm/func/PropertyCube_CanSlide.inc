	push {r4, r5, r6, lr}
	adds r3, r0, #0
	movs r0, #0x90
	lsls r0, r0, #1
	adds r6, r3, r0
	adds r0, r3, #0
	adds r0, #0x31
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r2, #3
	ldr r0, _0800CC64 @ =0x030046A4
	ldr r4, [r0]
	ands r1, r2
	lsls r1, r1, #1
	adds r0, r4, #0
	adds r0, #0x1c
	adds r0, r0, r1
	movs r1, #0
	ldrsh r5, [r0, r1]
	adds r1, r3, #0
	adds r1, #0x50
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800CC5E
	cmp r1, #0
	blt _0800CC5E
	ldr r0, _0800CC68 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800CC5E
	ldr r0, _0800CC6C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800CC70
_0800CC5E:
	movs r0, #0
	b _0800CC7C
	.align 2, 0
_0800CC64: .4byte 0x030046A4
_0800CC68: .4byte 0x030046A8
_0800CC6C: .4byte 0x030046AC
_0800CC70:
	lsls r0, r1, #1
	adds r1, r4, #0
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, r0, r2
_0800CC7C:
	adds r4, r0, r5
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0800CC8E
	adds r3, r0, #4
	b _0800CC9A
_0800CC8E:
	ldr r0, _0800CCC4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r3, r1, r0
_0800CC9A:
	cmp r3, #0
	beq _0800CCC8
	ldrb r4, [r3]
	lsrs r0, r4, #4
	cmp r0, #0
	bne _0800CCC8
	movs r0, #0xf
	ldrb r2, [r6]
	adds r1, r0, #0
	ands r1, r4
	ands r0, r2
	cmp r1, r0
	bhs _0800CCC8
	ldrh r1, [r3, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0800CCC8
	movs r0, #1
	b _0800CCCA
	.align 2, 0
_0800CCC4: .4byte 0x030046A4
_0800CCC8:
	movs r0, #0
_0800CCCA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
