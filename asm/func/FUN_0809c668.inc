	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r2, _0809C6AC @ =0x00000283
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809C6BC
	ldr r0, _0809C6B0 @ =0x000009EE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _0809C6B4 @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0809C6BC
	ldr r1, _0809C6B8 @ =0x00000C0C
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0xa0
	adds r1, r4, #0
	movs r2, #0xc9
	movs r3, #1
	bl MainSprite_SetPose
	b _0809C6E4
	.align 2, 0
_0809C6AC: .4byte 0x00000283
_0809C6B0: .4byte 0x000009EE
_0809C6B4: .4byte 0x0000FFFF
_0809C6B8: .4byte 0x00000C0C
_0809C6BC:
	ldr r2, _0809C704 @ =0x00000C0C
	adds r0, r5, r2
	adds r4, r5, #0
	adds r4, #0xa0
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r1, r5, r2
	ldr r1, [r1]
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r1, r1, r2
	movs r2, #0
	ldrsb r2, [r1, r2]
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r4, #0
	movs r3, #1
	bl MainSprite_SetPose
_0809C6E4:
	ldr r1, _0809C708 @ =0x00000DA4
	adds r0, r5, r1
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r1, r5, r2
	ldr r1, [r1]
	adds r2, #0x94
	adds r1, r1, r2
	ldrb r2, [r1]
	adds r1, r4, #0
	movs r3, #1
	bl MainSprite_SetPose
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809C704: .4byte 0x00000C0C
_0809C708: .4byte 0x00000DA4
