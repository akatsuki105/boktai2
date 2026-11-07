	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	ldr r1, _081654A8 @ =0x00000472
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _081654AC @ =0x0000065C
	adds r0, r4, r2
	ldrh r0, [r0]
	subs r1, r1, r0
	ldr r0, _081654B0 @ =0x000001FF
	cmp r1, r0
	ble _081654E6
	ldrh r0, [r4, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081654A2
	cmp r1, #0
	blt _081654A2
	ldr r0, _081654B4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081654A2
	ldr r0, _081654B8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081654BC
_081654A2:
	movs r0, #0
	b _081654CA
	.align 2, 0
_081654A8: .4byte 0x00000472
_081654AC: .4byte 0x0000065C
_081654B0: .4byte 0x000001FF
_081654B4: .4byte 0x030046A8
_081654B8: .4byte 0x030046AC
_081654BC:
	ldr r0, _081654FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081654CA:
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081654E6
	adds r0, r5, #0
	bl FUN_08165178
	ldr r1, _08165500 @ =0x0000065C
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _08165504 @ =0x00000472
	adds r0, r5, r2
	strh r1, [r0]
_081654E6:
	ldr r1, _08165504 @ =0x00000472
	adds r0, r5, r1
	ldrh r1, [r0]
	ldr r2, _08165500 @ =0x0000065C
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081654FC: .4byte 0x030046A4
_08165500: .4byte 0x0000065C
_08165504: .4byte 0x00000472
