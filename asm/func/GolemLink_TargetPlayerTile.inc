	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B8C4C
	cmp r1, #0
	blt _081B8C4C
	ldr r0, _081B8C50 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B8C4C
	ldr r0, _081B8C54 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B8C58
_081B8C4C:
	movs r4, #0
	b _081B8C66
	.align 2, 0
_081B8C50: .4byte 0x030046A8
_081B8C54: .4byte 0x030046AC
_081B8C58:
	ldr r0, _081B8C78 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B8C66:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B8C7C
	adds r0, #4
	b _081B8C88
	.align 2, 0
_081B8C78: .4byte 0x030046A4
_081B8C7C:
	ldr r0, _081B8CC8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B8C88:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _081B8CC2
	ldr r1, _081B8CCC @ =0x000004A4
	adds r0, r5, r1
	ldr r0, [r0]
	adds r1, r5, #0
	adds r1, #8
	movs r2, #0xec
	lsls r2, r2, #1
	adds r4, r5, r2
	ldr r2, [r4]
	adds r2, #8
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	beq _081B8CC2
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r4]
	ldr r2, [r1, #0xc]
	ldr r1, [r1, #8]
	str r1, [r0]
	str r2, [r0, #4]
	bl GolemLink_SnapToTileCenter
_081B8CC2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B8CC8: .4byte 0x030046A4
_081B8CCC: .4byte 0x000004A4
