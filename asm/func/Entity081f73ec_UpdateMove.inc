	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r1, #0
	ldr r0, _081F6B74 @ =0x000006EA
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081F6BB2
	ldr r2, _081F6B78 @ =0x000006DC
	adds r1, r5, r2
	movs r4, #0
	str r4, [sp]
	mov r0, sp
	ldr r2, _081F6B7C @ =0x05000002
	bl CpuSet
	movs r3, #0xdd
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strh r4, [r0]
	strb r1, [r6]
	ldr r0, _081F6B80 @ =0x03002BE0
	add r2, sp, #4
	adds r4, r5, #0
	adds r4, #0x1c
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r5, #0x1c]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	ldr r2, _081F6B84 @ =0x000006DA
	adds r1, r5, r2
	strb r0, [r1]
	movs r1, #1
	ldr r3, _081F6B88 @ =0x000006E4
	adds r0, r5, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	ands r0, r1
	cmp r0, #0
	beq _081F6B8C
	movs r0, #1
	b _081F6B8E
	.align 2, 0
_081F6B74: .4byte 0x000006EA
_081F6B78: .4byte 0x000006DC
_081F6B7C: .4byte 0x05000002
_081F6B80: .4byte 0x03002BE0
_081F6B84: .4byte 0x000006DA
_081F6B88: .4byte 0x000006E4
_081F6B8C:
	movs r0, #0
_081F6B8E:
	cmp r0, #0
	beq _081F6BA2
	adds r0, r5, #0
	bl FUN_081f6458
	movs r3, #0xdb
	lsls r3, r3, #3
	adds r1, r5, r3
	movs r0, #0
	b _081F6BB0
_081F6BA2:
	adds r0, r5, #0
	bl FUN_081f6474
	movs r0, #0xdb
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r0, #5
_081F6BB0:
	strb r0, [r1]
_081F6BB2:
	movs r1, #1
	ldr r2, _081F6BC8 @ =0x000006E4
	adds r0, r5, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	ands r0, r1
	cmp r0, #0
	beq _081F6BCC
	movs r0, #1
	b _081F6BCE
	.align 2, 0
_081F6BC8: .4byte 0x000006E4
_081F6BCC:
	movs r0, #0
_081F6BCE:
	cmp r0, #0
	beq _081F6BE8
	adds r0, r5, #0
	bl FUN_081f6498
	ldr r2, _081F6BE4 @ =0x00006D60
	adds r0, r5, #0
	movs r1, #8
	bl Entity081f73ec_FollowHead
	b _081F6BF8
	.align 2, 0
_081F6BE4: .4byte 0x00006D60
_081F6BE8:
	adds r0, r5, #0
	bl FUN_081f65f4
	ldr r2, _081F6C28 @ =0x00004E20
	adds r0, r5, #0
	movs r1, #4
	bl Entity081f73ec_FollowHead
_081F6BF8:
	adds r0, r5, #0
	bl Entity081f73ec_UpdateBuried
	adds r0, r5, #0
	bl Entity081f73ec_UpdateHitbox
	adds r0, r5, #0
	bl Entity081f73ec_UpdateFlash
	ldr r1, _081F6C2C @ =0x000006E4
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081F6C38
	ldr r2, _081F6C30 @ =0x000006E6
	adds r1, r5, r2
	movs r0, #4
	strb r0, [r1]
	ldr r3, _081F6C34 @ =0x000006EA
	adds r1, r5, r3
	b _081F6C64
	.align 2, 0
_081F6C28: .4byte 0x00004E20
_081F6C2C: .4byte 0x000006E4
_081F6C30: .4byte 0x000006E6
_081F6C34: .4byte 0x000006EA
_081F6C38:
	movs r0, #0xdd
	lsls r0, r0, #3
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _081F6C54 @ =0x000006EB
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081F6C58
	subs r0, #1
	b _081F6C66
	.align 2, 0
_081F6C54: .4byte 0x000006EB
_081F6C58:
	ldr r3, _081F6C70 @ =0x000006E6
	adds r1, r5, r3
	movs r0, #5
	strb r0, [r1]
	ldr r0, _081F6C74 @ =0x000006EA
	adds r1, r5, r0
_081F6C64:
	movs r0, #1
_081F6C66:
	strb r0, [r1]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081F6C70: .4byte 0x000006E6
_081F6C74: .4byte 0x000006EA
