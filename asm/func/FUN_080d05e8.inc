	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r6, r7, r0
	ldrb r0, [r6]
	cmp r0, #5
	beq _080D0606
	ldr r1, _080D06B8 @ =0x08DA9E68
	adds r0, r7, #0
	bl player_weapon_080ceafc
_080D0606:
	movs r1, #1
	mov r8, r1
	str r1, [r7, #0x1c]
	ldr r2, _080D06BC @ =0x00000366
	adds r0, r7, r2
	ldrh r1, [r0]
	subs r2, #2
	adds r0, r7, r2
	movs r2, #0
	mov sb, r2
	movs r5, #0
	strh r1, [r0]
	ldr r1, _080D06C0 @ =0x0000036A
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	ldr r1, _080D06C4 @ =0x0000044C
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r7, #0x2c]
	str r1, [r7, #0x30]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r4, r7, r2
	adds r1, r7, #0
	adds r1, #0x2c
	adds r0, r4, #0
	bl Map_InitMoverTile
	str r4, [r7, #0x3c]
	movs r1, #0xd5
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r5, [r0]
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	ldr r1, _080D06C8 @ =0x00000395
	adds r0, r7, r1
	mov r2, sb
	strb r2, [r0]
	movs r0, #0xd8
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0x5a
	strh r0, [r1]
	ldr r1, _080D06CC @ =0x000003F6
	adds r0, r7, r1
	strh r5, [r0]
	ldr r2, _080D06D0 @ =0x00000457
	adds r0, r7, r2
	mov r1, r8
	strb r1, [r0]
	subs r2, #3
	adds r0, r7, r2
	ldrb r1, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	adds r0, r7, #0
	bl PlayerLink_SetAnimFacing
	ldrb r0, [r6]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r7, #0
	movs r2, #0x40
	bl PlayerLink_PlayAnim
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl PlayerLink_SetAction
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D06B8: .4byte 0x08DA9E68
_080D06BC: .4byte 0x00000366
_080D06C0: .4byte 0x0000036A
_080D06C4: .4byte 0x0000044C
_080D06C8: .4byte 0x00000395
_080D06CC: .4byte 0x000003F6
_080D06D0: .4byte 0x00000457
