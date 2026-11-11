	push {r4, lr}
	sub sp, #0x24
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, _080032C0 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080032C4 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080032C8
	movs r0, #1
	b _080032CA
	.align 2, 0
_080032C0: .4byte 0x030046A0
_080032C4: .4byte 0x00000934
_080032C8:
	movs r0, #0
_080032CA:
	cmp r0, #0
	beq _08003338
	ldr r0, _0800332C @ =0x00000145
	bl PlaySound_082406e0
	adds r0, r4, #0
	adds r0, #0xa8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	adds r4, r0, #0
	asrs r2, r4, #0x10
	movs r3, #0xdd
	lsls r3, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #0x10
	ldr r3, _08003330 @ =0x0000FFFF
	ands r4, r3
	adds r0, r4, #0
	orrs r0, r2
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	add r0, sp, #0x1c
	ldrh r1, [r0]
	adds r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08003334 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r0, sp, #0x1c
	ldrh r0, [r0, #4]
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x20]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x20]
	add r0, sp, #0x1c
	str r0, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0x1e
	bl FUN_08016110
	b _080033A2
	.align 2, 0
_0800332C: .4byte 0x00000145
_08003330: .4byte 0x0000FFFF
_08003334: .4byte 0xFFFF0000
_08003338:
	ldrb r0, [r4]
	cmp r0, #1
	beq _0800334C
	cmp r0, #1
	bgt _08003348
	cmp r0, #0
	beq _0800334C
	b _08003358
_08003348:
	cmp r0, #6
	bgt _08003358
_0800334C:
	ldr r0, _08003354 @ =0x00000143
	bl PlaySound_082406e0
	b _0800335E
	.align 2, 0
_08003354: .4byte 0x00000143
_08003358:
	ldr r0, _08003394 @ =0x00000143
	bl PlaySound_082406e0
_0800335E:
	adds r0, r4, #0
	bl MovableBlock_IsEnclosed
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08003398
	movs r0, #0
	str r0, [sp]
	movs r0, #0xff
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #4
	str r0, [sp, #0xc]
	movs r0, #6
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	adds r0, r4, #0
	adds r0, #0xa8
	str r0, [sp, #0x18]
	movs r0, #4
	movs r1, #1
	movs r2, #1
	movs r3, #0x40
	bl Puff_SpawnSprayEx
	b _080033A2
	.align 2, 0
_08003394: .4byte 0x00000143
_08003398:
	adds r0, r4, #0
	adds r0, #0x34
	movs r1, #0x90
	bl MovableBlock_SpawnDust
_080033A2:
	add sp, #0x24
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
