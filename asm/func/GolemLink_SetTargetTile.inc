	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B8D02
	cmp r1, #0
	blt _081B8D02
	ldr r0, _081B8D08 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B8D02
	ldr r0, _081B8D0C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B8D10
_081B8D02:
	movs r4, #0
	b _081B8D1E
	.align 2, 0
_081B8D08: .4byte 0x030046A8
_081B8D0C: .4byte 0x030046AC
_081B8D10:
	ldr r0, _081B8D30 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B8D1E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B8D34
	adds r0, #4
	b _081B8D40
	.align 2, 0
_081B8D30: .4byte 0x030046A4
_081B8D34:
	ldr r0, _081B8D84 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B8D40:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _081B8D7E
	ldr r1, _081B8D88 @ =0x000004A4
	adds r0, r6, r1
	ldr r0, [r0]
	adds r1, r6, #0
	adds r1, #8
	adds r2, r5, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	beq _081B8D7E
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r5]
	ldr r2, [r5, #4]
	str r1, [r0]
	str r2, [r0, #4]
	bl GolemLink_SnapToTileCenter
	movs r2, #0x80
	lsls r2, r2, #0xc
	ldr r0, _081B8D8C @ =0x0000065C
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081B8D7E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B8D84: .4byte 0x030046A4
_081B8D88: .4byte 0x000004A4
_081B8D8C: .4byte 0x0000065C
