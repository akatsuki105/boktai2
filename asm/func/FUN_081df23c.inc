	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DF2C0
	adds r0, r5, #0
	bl FUN_081dd9f0
	adds r0, r5, #0
	bl FUN_081de02c
	adds r0, r5, #0
	bl FUN_081ddc04
	ldr r0, _081DF2D8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DF2AC
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081DF2AC
	ldr r2, _081DF2DC @ =0x030047E0
	ldrb r1, [r2, #6]
	lsls r0, r1, #4
	subs r0, r0, r1
	ldrb r2, [r2, #7]
	adds r0, r0, r2
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	ldr r1, _081DF2E0 @ =0x000002CE
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #2
	bls _081DF2A4
	ldr r2, _081DF2E4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081DF2E8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081DF2EC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
_081DF2A4:
	movs r2, #0xb9
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
_081DF2AC:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0x46
	bl FUN_081ddfb0
	movs r2, #0xd1
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
_081DF2C0:
	adds r0, r5, #0
	bl FUN_081ddab4
	cmp r0, #0
	bge _081DF2F0
	adds r0, r5, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF38C
	.align 2, 0
_081DF2D8: .4byte 0x03002C68
_081DF2DC: .4byte 0x030047E0
_081DF2E0: .4byte 0x000002CE
_081DF2E4: .4byte 0x030046B8
_081DF2E8: .4byte 0x000003FF
_081DF2EC: .4byte 0x0203B400
_081DF2F0:
	ldr r0, [r5, #0x44]
	ldrh r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #6
	ands r0, r1
	movs r1, #0xc0
	lsls r1, r1, #5
	cmp r0, r1
	bne _081DF306
	movs r0, #1
	b _081DF308
_081DF306:
	movs r0, #0
_081DF308:
	cmp r0, #0
	beq _081DF324
	adds r0, r5, #0
	bl FUN_081dde98
	ldr r2, _081DF320 @ =FUN_081df398
	adds r0, r5, #0
	movs r1, #0x13
	bl Entity9A9F_SetState
	movs r0, #0
	b _081DF38C
	.align 2, 0
_081DF320: .4byte FUN_081df398
_081DF324:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r5, r0
	adds r0, r5, #0
	movs r2, #0x48
	bl FUN_081ddb14
	movs r7, #0
	movs r6, #0
	ldrh r1, [r5, #0x1a]
	cmp r7, r1
	bge _081DF36C
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r4, r5, r2
_081DF342:
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	movs r3, #0x48
	bl FUN_081ddb5c
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #1
	bne _081DF362
	adds r0, r4, #0
	movs r1, #0x46
	bl FUN_081ddfb0
	adds r7, #1
_081DF362:
	adds r4, #0x48
	adds r6, #1
	ldrh r1, [r5, #0x1a]
	cmp r6, r1
	blt _081DF342
_081DF36C:
	ldrh r2, [r5, #0x1a]
	cmp r7, r2
	bne _081DF38C
	ldr r1, _081DF394 @ =0x03002C68
	ldr r1, [r1]
	cmp r1, #0
	beq _081DF38C
	movs r2, #0x18
	ldrsh r1, [r1, r2]
	cmp r1, #0
	bne _081DF38C
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r1, r5, #0
	adds r1, #0x42
	strh r2, [r1]
_081DF38C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081DF394: .4byte 0x03002C68
