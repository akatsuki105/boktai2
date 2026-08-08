	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #9
	beq _0806899A
	ldr r2, _0806897C @ =0x00000951
	adds r0, r4, r2
	movs r1, #0
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #0x64
	bl FUN_08064d54
	cmp r0, #0
	beq _08068988
	ldr r0, _08068980 @ =0x03002BD0
	ldrh r0, [r0]
	cmp r0, #0
	bne _08068988
	ldr r3, _08068984 @ =0x000003FA
	adds r1, r4, r3
	movs r0, #1
	b _0806898E
	.align 2, 0
_0806897C: .4byte 0x00000951
_08068980: .4byte 0x03002BD0
_08068984: .4byte 0x000003FA
_08068988:
	ldr r0, _080689B0 @ =0x000003FA
	adds r1, r4, r0
	movs r0, #0
_0806898E:
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #9
	movs r2, #0
	bl FUN_08060b84
_0806899A:
	ldr r1, _080689B4 @ =0x0000037D
	adds r0, r4, r1
	ldrb r2, [r0]
	cmp r2, #1
	bne _080689A6
	b _08068B08
_080689A6:
	cmp r2, #1
	bgt _080689B8
	cmp r2, #0
	beq _080689C6
	b _08068C62
	.align 2, 0
_080689B0: .4byte 0x000003FA
_080689B4: .4byte 0x0000037D
_080689B8:
	cmp r2, #2
	bne _080689BE
	b _08068B9C
_080689BE:
	cmp r2, #3
	bne _080689C4
	b _08068C2C
_080689C4:
	b _08068C62
_080689C6:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r3, r4, r0
	ldrb r0, [r3]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _08068A28
	movs r1, #4
	strb r1, [r3]
	ldr r3, _08068A18 @ =0x000002E6
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _08068A1C @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
	movs r3, #0x93
	lsls r3, r3, #4
	adds r2, r4, r3
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	subs r0, #0x14
	strh r0, [r2]
	ldr r0, _08068A20 @ =0x00000932
	adds r1, r4, r0
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r0, _08068A24 @ =0x00000934
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x3c
	b _08068A62
	.align 2, 0
_08068A18: .4byte 0x000002E6
_08068A1C: .4byte 0x000002E7
_08068A20: .4byte 0x00000932
_08068A24: .4byte 0x00000934
_08068A28:
	strb r2, [r3]
	ldr r1, _08068A90 @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	ldr r3, _08068A94 @ =0x000002E7
	adds r0, r4, r3
	strb r2, [r0]
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	adds r0, #0x14
	strh r0, [r2]
	ldr r2, _08068A98 @ =0x00000932
	adds r1, r4, r2
	movs r3, #0xa5
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r3, _08068A9C @ =0x00000934
	adds r1, r4, r3
	ldrh r0, [r1]
	subs r0, #0x14
_08068A62:
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #4
	bne _08068AA0
	ldr r3, _08068A90 @ =0x000002E6
	adds r1, r4, r3
	movs r0, #1
	b _08068AA6
	.align 2, 0
_08068A90: .4byte 0x000002E6
_08068A94: .4byte 0x000002E7
_08068A98: .4byte 0x00000932
_08068A9C: .4byte 0x00000934
_08068AA0:
	ldr r0, _08068AF4 @ =0x000002E6
	adds r1, r4, r0
	movs r0, #0
_08068AA6:
	strb r0, [r1]
	ldr r1, _08068AF8 @ =0x000003FA
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08068AE6
	movs r0, #0x94
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r2, _08068AFC @ =0x0000095E
	adds r1, r4, r2
	ldr r0, _08068B00 @ =0x00000121
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	movs r0, #2
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0x2c
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r3, _08068B04 @ =0x000003BA
	adds r0, r4, r3
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_080abd14
_08068AE6:
	adds r0, r4, #0
	movs r1, #9
	movs r2, #1
	bl FUN_08060b84
	b _08068C62
	.align 2, 0
_08068AF4: .4byte 0x000002E6
_08068AF8: .4byte 0x000003FA
_08068AFC: .4byte 0x0000095E
_08068B00: .4byte 0x00000121
_08068B04: .4byte 0x000003BA
_08068B08:
	ldr r1, _08068B88 @ =0x000003FA
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08068B32
	ldr r2, _08068B8C @ =0x0000095E
	adds r1, r4, r2
	ldr r0, _08068B90 @ =0x00000121
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _08068B32
	movs r0, #0x20
	strh r0, [r1]
_08068B32:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #8
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _08068B5A
	b _08068C62
_08068B5A:
	movs r0, #0xcb
	bl PlaySound_082406e0
	ldr r2, _08068B88 @ =0x000003FA
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08068B7A
	ldr r3, _08068B94 @ =0x000003BA
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _08068B7A
	ldr r1, _08068B98 @ =0x03002BD0
	movs r0, #1
	strh r0, [r1]
_08068B7A:
	adds r0, r4, #0
	movs r1, #9
	movs r2, #2
	bl FUN_08060b84
	b _08068C62
	.align 2, 0
_08068B88: .4byte 0x000003FA
_08068B8C: .4byte 0x0000095E
_08068B90: .4byte 0x00000121
_08068B94: .4byte 0x000003BA
_08068B98: .4byte 0x03002BD0
_08068B9C:
	ldr r1, _08068BC8 @ =0x000003FA
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08068BD4
	ldr r2, _08068BCC @ =0x0000095E
	adds r1, r4, r2
	ldr r0, _08068BD0 @ =0x00000121
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _08068BE6
	movs r0, #0x20
	strh r0, [r1]
	b _08068BE6
	.align 2, 0
_08068BC8: .4byte 0x000003FA
_08068BCC: .4byte 0x0000095E
_08068BD0: .4byte 0x00000121
_08068BD4:
	ldr r1, _08068C28 @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08068BE6
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08068BE6:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0x1e
	strh r0, [r1]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	movs r1, #0xa
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _08068C28 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _08068C62
	adds r0, r4, #0
	movs r1, #9
	movs r2, #3
	bl FUN_08060b84
	b _08068C62
	.align 2, 0
_08068C28: .4byte 0x0000037E
_08068C2C:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	movs r1, #0xb
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08068C62
	adds r0, r4, #0
	bl FUN_080609dc
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_08068C62:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
