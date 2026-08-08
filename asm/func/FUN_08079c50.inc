	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x14
	beq _08079C8E
	ldr r2, _08079CD0 @ =0x000003FF
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08079C8E
	adds r1, #0x58
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldr r2, _08079CD4 @ =0x000003F6
	adds r0, r5, r2
	strh r1, [r0]
	adds r0, r5, #0
	movs r1, #0x14
	movs r2, #0
	bl FUN_08060b84
_08079C8E:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r4, [r0]
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r6, r5, r2
	ldr r0, [r6]
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08079CB2
	adds r0, r5, #0
	bl FUN_08064db0
	adds r4, r0, #0
_08079CB2:
	ldr r1, _08079CD8 @ =0x00000387
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08079D20
	cmp r4, #1
	bhi _08079D38
	ldr r0, [r6]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08079CDC
	movs r4, #3
	b _08079D38
	.align 2, 0
_08079CD0: .4byte 0x000003FF
_08079CD4: .4byte 0x000003F6
_08079CD8: .4byte 0x00000387
_08079CDC:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08079CF2
	adds r0, r5, #0
	adds r0, #0x24
	bl FUN_08006194
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08079D18
_08079CF2:
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08079D18
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08079D1C
_08079D18:
	movs r4, #0
	b _08079D38
_08079D1C:
	movs r4, #1
	b _08079D38
_08079D20:
	cmp r4, #0
	bne _08079D38
	ldr r0, [r6]
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08079D38
	adds r0, r5, #0
	adds r0, #0x24
	bl FUN_08006194
_08079D38:
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
