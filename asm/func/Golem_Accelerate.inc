	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r4, _08115FB0 @ =0x00000256
	adds r0, r5, r4
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08115FB4
	adds r0, #4
	b _08115FC0
	.align 2, 0
_08115FB0: .4byte 0x00000256
_08115FB4:
	ldr r0, _08115FE0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08115FC0:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #0
	beq _08116002
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #1
	beq _08115FEC
	cmp r0, #1
	bgt _08115FE4
	cmp r0, #0
	beq _08115FF4
	b _08115FFA
	.align 2, 0
_08115FE0: .4byte 0x030046A4
_08115FE4:
	cmp r0, #3
	beq _08115FEC
	cmp r0, #5
	bne _08115FFA
_08115FEC:
	movs r2, #0xa0
	lsls r2, r2, #1
	movs r3, #0xb
	b _08116036
_08115FF4:
	movs r2, #0xa0
	movs r3, #5
	b _08116036
_08115FFA:
	movs r2, #0x80
	lsls r2, r2, #1
	movs r3, #8
	b _08116036
_08116002:
	movs r4, #0x90
	lsls r4, r4, #3
	adds r0, r5, r4
	ldrh r0, [r0]
	cmp r0, #1
	beq _08116020
	cmp r0, #1
	bgt _08116018
	cmp r0, #0
	beq _08116028
	b _08116030
_08116018:
	cmp r0, #3
	beq _08116020
	cmp r0, #5
	bne _08116030
_08116020:
	movs r2, #0xe0
	lsls r2, r2, #1
	movs r3, #0x16
	b _08116036
_08116028:
	movs r2, #0xa0
	lsls r2, r2, #1
	movs r3, #0xa
	b _08116036
_08116030:
	movs r2, #0xc0
	lsls r2, r2, #1
	movs r3, #0x10
_08116036:
	ldr r0, _0811604C @ =0x000006B6
	adds r1, r6, r0
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, r2
	bge _08116050
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	b _08116052
	.align 2, 0
_0811604C: .4byte 0x000006B6
_08116050:
	strh r2, [r1]
_08116052:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
