	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0xea
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r0, [r4]
	cmp r0, #0
	ble _0814B4DC
	adds r0, r5, #0
	bl Enemy_Alert
	ldr r1, _0814B45C @ =0x00000222
	adds r2, r5, r1
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0x14
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrh r0, [r4]
	bl EnemyTargetManager_FindOwnerByID
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r5, r2
	str r0, [r1]
	ldrh r1, [r0, #8]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0814B456
	cmp r1, #0
	blt _0814B456
	ldr r0, _0814B460 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0814B456
	ldr r0, _0814B464 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814B468
_0814B456:
	movs r1, #0
	b _0814B476
	.align 2, 0
_0814B45C: .4byte 0x00000222
_0814B460: .4byte 0x030046A8
_0814B464: .4byte 0x030046AC
_0814B468:
	ldr r0, _0814B4D4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0814B476:
	ldr r3, _0814B4D8 @ =0x0000025E
	adds r0, r5, r3
	strh r1, [r0]
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	strb r0, [r5, #5]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r2, #0xd
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r0, #1
	b _0814B4F4
	.align 2, 0
_0814B4D4: .4byte 0x030046A4
_0814B4D8: .4byte 0x0000025E
_0814B4DC:
	movs r0, #8
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r3, [r1]
	ands r0, r3
	cmp r0, #0
	beq _0814B4F2
	ldr r0, _0814B4FC @ =0xF7FFFFFF
	ands r3, r0
	str r3, [r1]
_0814B4F2:
	movs r0, #0
_0814B4F4:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0814B4FC: .4byte 0xF7FFFFFF
