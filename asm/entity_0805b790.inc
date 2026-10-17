	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0805b1a0
FUN_0805b1a0: @ 0x0805B1A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r3, r5, #0
	adds r3, #0x24
	movs r4, #0
	movs r6, #1
	movs r1, #3
	mov r8, r1
	mov ip, r4
	movs r7, #0xe2
	lsls r7, r7, #1
_0805B1BA:
	adds r2, r6, #0
	lsls r2, r4
	ldr r1, [r5, #0x18]
	ands r1, r2
	cmp r1, #0
	beq _0805B1D6
	ldrb r1, [r3, #1]
	cmp r1, #2
	bhi _0805B1D6
	mov r1, r8
	strb r1, [r3, #1]
	strb r6, [r3]
	mov r1, ip
	strh r1, [r3, #6]
_0805B1D6:
	adds r4, #1
	adds r3, r3, r7
	cmp r4, #7
	ble _0805B1BA
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805b1e8
FUN_0805b1e8: @ 0x0805B1E8
	push {r4, r5, lr}
	adds r4, r1, #0
	movs r2, #0
	movs r5, #1
	ldr r1, [r0, #0x18]
	adds r3, r0, #0
	adds r3, #0x40
_0805B1F6:
	adds r0, r5, #0
	lsls r0, r2
	ands r0, r1
	cmp r0, #0
	bne _0805B206
	str r2, [r4]
	adds r0, r3, #0
	b _0805B210
_0805B206:
	adds r3, #0x8c
	adds r2, #1
	cmp r2, #0xf
	ble _0805B1F6
	movs r0, #0
_0805B210:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805b218
FUN_0805b218: @ 0x0805B218
	movs r0, #2
	movs r1, #0
	strb r0, [r2, #2]
	movs r0, #1
	strb r0, [r2, #1]
	strh r1, [r2, #4]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0805b228
FUN_0805b228: @ 0x0805B228
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	adds r2, r0, #0
	adds r7, r1, #0
	movs r0, #0
	movs r5, #0
	strb r0, [r7, #2]
	movs r6, #1
	strb r6, [r7, #1]
	strh r5, [r7, #4]
	strb r0, [r7, #3]
	adds r4, r7, #0
	adds r4, #0x60
	adds r2, #0x24
	adds r0, r4, #0
	adds r1, r2, #0
	movs r2, #3
	bl AuxSprite_Add
	strh r6, [r4, #0x10]
	movs r0, #2
	strb r0, [r4, #7]
	movs r0, #0x7c
	adds r0, r0, r7
	mov r8, r0
	str r5, [sp, #0xc]
	add r0, sp, #0xc
	mov r1, r8
	ldr r2, _0805B2E0 @ =0x05000002
	bl CpuSet
	subs r4, #0x50
	ldr r2, _0805B2E4 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r5, #0x1e
	orrs r0, r5
	ldr r1, _0805B2E8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x10]
	add r3, sp, #0x10
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r5
	str r0, [r3, #4]
	movs r0, #0xf0
	lsls r0, r0, #0xf
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0805B2EC @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0805B2F0 @ =FUN_0805b218
	adds r0, r4, #0
	adds r2, r7, #0
	bl Hitbox_SetHandler
	str r6, [sp]
	str r5, [sp, #4]
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0xa
	movs r3, #0x10
	bl Hitbox_SetAttack
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805B2E0: .4byte 0x05000002
_0805B2E4: .4byte 0xFFFF0000
_0805B2E8: .4byte 0x0000FFFF
_0805B2EC: .4byte 0x00002001
_0805B2F0: .4byte FUN_0805b218

	thumb_func_start FUN_0805b2f4
FUN_0805b2f4: @ 0x0805B2F4
	push {lr}
	adds r0, r1, #0
	adds r0, #0x60
	bl AuxSprite_Remove
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805b304
FUN_0805b304: @ 0x0805B304
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r3, [r1, #0x60]
	movs r4, #1
	orrs r3, r4
	str r3, [r1, #0x60]
	lsls r4, r2
	ldr r1, [r5, #0x18]
	bics r1, r4
	str r1, [r5, #0x18]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805b320
FUN_0805b320: @ 0x0805B320
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r4, #0
	adds r3, #0x7c
	ldr r2, [r4, #0xc]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r5, #0
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	movs r5, #4
	ldrsh r1, [r2, r5]
	movs r5, #4
	ldrsh r2, [r3, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	ldrb r1, [r4, #3]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	asrs r3, r0, #0x18
	ldrb r1, [r4, #8]
	rsbs r0, r1, #0
	cmp r3, r0
	bge _0805B35A
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	b _0805B360
_0805B35A:
	cmp r3, r1
	ble _0805B360
	adds r2, r1, #0
_0805B360:
	ldrb r0, [r4, #3]
	adds r0, r0, r2
	strb r0, [r4, #3]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805b36c
FUN_0805b36c: @ 0x0805B36C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	adds r6, r1, #0
	mov sl, r2
	adds r7, r6, #0
	adds r7, #0x60
	ldrb r0, [r6, #1]
	cmp r0, #0
	beq _0805B38C
	movs r0, #0
	strb r0, [r6, #1]
_0805B38C:
	mov r3, sp
	ldrb r4, [r6, #3]
	ldrh r5, [r6, #6]
	ldr r2, _0805B3B0 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805B3B4
	asrs r1, r0, #0xc
	b _0805B3BA
	.align 2, 0
_0805B3B0: .4byte gSineTable
_0805B3B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805B3BA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805B3D2
	asrs r0, r0, #0xc
	b _0805B3D8
_0805B3D2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805B3D8:
	strh r0, [r3, #4]
	adds r4, r7, #0
	adds r4, #0x1c
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r4, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	adds r5, r6, #0
	adds r5, #0x10
	adds r1, r6, #0
	adds r1, #0x7c
	adds r0, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	bl Hitbox_Register
	movs r0, #0x1e
	ldrsh r2, [r7, r0]
	mov r8, r2
	adds r5, r4, #0
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _0805B43C
	cmp r1, #0
	blt _0805B43C
	ldr r0, _0805B440 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0805B43C
	ldr r0, _0805B444 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0805B448
_0805B43C:
	movs r4, #0
	b _0805B456
	.align 2, 0
_0805B440: .4byte 0x030046A8
_0805B444: .4byte 0x030046AC
_0805B448:
	ldr r0, _0805B468 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0805B456:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0805B46C
	adds r0, #4
	b _0805B478
	.align 2, 0
_0805B468: .4byte 0x030046A4
_0805B46C:
	ldr r0, _0805B48C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0805B478:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0805B490
	cmp r2, #2
	beq _0805B494
	b _0805B498
	.align 2, 0
_0805B48C: .4byte 0x030046A4
_0805B490:
	ldrb r0, [r5, #4]
	b _0805B496
_0805B494:
	ldrb r0, [r5]
_0805B496:
	subs r1, r1, r0
_0805B498:
	cmp r8, r1
	bhi _0805B4AA
	movs r0, #2
	movs r1, #0
	strb r0, [r6, #2]
	movs r0, #1
	strb r0, [r6, #1]
	strh r1, [r6, #4]
	b _0805B4C0
_0805B4AA:
	ldrh r0, [r6, #4]
	cmp r0, #0x7f
	bls _0805B4BC
	mov r0, sb
	adds r1, r6, #0
	mov r2, sl
	bl FUN_0805b304
	b _0805B4C0
_0805B4BC:
	adds r0, #1
	strh r0, [r6, #4]
_0805B4C0:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805b4d0
FUN_0805b4d0: @ 0x0805B4D0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	adds r6, r1, #0
	mov sl, r2
	adds r7, r6, #0
	adds r7, #0x60
	ldrb r0, [r6, #1]
	cmp r0, #0
	beq _0805B4F0
	movs r0, #0
	strb r0, [r6, #1]
_0805B4F0:
	adds r0, r6, #0
	bl FUN_0805b320
	mov r3, sp
	ldrb r4, [r6, #3]
	ldrh r5, [r6, #6]
	ldr r2, _0805B518 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805B51C
	asrs r1, r0, #0xc
	b _0805B522
	.align 2, 0
_0805B518: .4byte gSineTable
_0805B51C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805B522:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0805B53C @ =gSineTable
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0805B540
	asrs r0, r0, #0xc
	b _0805B546
	.align 2, 0
_0805B53C: .4byte gSineTable
_0805B540:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805B546:
	strh r0, [r3, #4]
	adds r4, r7, #0
	adds r4, #0x1c
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r4, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	adds r5, r6, #0
	adds r5, #0x10
	adds r1, r6, #0
	adds r1, #0x7c
	adds r0, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	bl Hitbox_Register
	movs r0, #0x1e
	ldrsh r2, [r7, r0]
	mov r8, r2
	adds r5, r4, #0
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _0805B5AA
	cmp r1, #0
	blt _0805B5AA
	ldr r0, _0805B5B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0805B5AA
	ldr r0, _0805B5B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0805B5B8
_0805B5AA:
	movs r4, #0
	b _0805B5C6
	.align 2, 0
_0805B5B0: .4byte 0x030046A8
_0805B5B4: .4byte 0x030046AC
_0805B5B8:
	ldr r0, _0805B5D8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0805B5C6:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0805B5DC
	adds r0, #4
	b _0805B5E8
	.align 2, 0
_0805B5D8: .4byte 0x030046A4
_0805B5DC:
	ldr r0, _0805B5FC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0805B5E8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0805B600
	cmp r2, #2
	beq _0805B604
	b _0805B608
	.align 2, 0
_0805B5FC: .4byte 0x030046A4
_0805B600:
	ldrb r0, [r5, #4]
	b _0805B606
_0805B604:
	ldrb r0, [r5]
_0805B606:
	subs r1, r1, r0
_0805B608:
	cmp r8, r1
	bhi _0805B61A
	movs r0, #2
	movs r1, #0
	strb r0, [r6, #2]
	movs r0, #1
	strb r0, [r6, #1]
	strh r1, [r6, #4]
	b _0805B630
_0805B61A:
	ldrh r0, [r6, #4]
	cmp r0, #0x7f
	bls _0805B62C
	mov r0, sb
	adds r1, r6, #0
	mov r2, sl
	bl FUN_0805b304
	b _0805B630
_0805B62C:
	adds r0, #1
	strh r0, [r6, #4]
_0805B630:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805b640
FUN_0805b640: @ 0x0805B640
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r3, r4, #0
	adds r3, #0x60
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0805B658
	movs r0, #0
	strb r0, [r4, #1]
	movs r0, #4
	strh r0, [r3, #0x10]
_0805B658:
	ldrh r0, [r4, #4]
	cmp r0, #3
	bne _0805B6C4
	ldrb r0, [r4, #3]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _0805B67C
	movs r0, #7
	b _0805B68A
_0805B67C:
	asrs r0, r1, #1
	ands r0, r2
	cmp r0, #0
	beq _0805B688
	movs r0, #8
	b _0805B68A
_0805B688:
	movs r0, #6
_0805B68A:
	strh r0, [r3, #0x10]
	cmp r1, #2
	bgt _0805B698
	ldr r0, [r3]
	movs r1, #0xd
	rsbs r1, r1, #0
	b _0805B6BE
_0805B698:
	cmp r1, #4
	bgt _0805B6A8
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #8
	b _0805B6B0
_0805B6A8:
	cmp r1, #5
	bgt _0805B6B6
	ldr r0, [r3]
	movs r1, #0xc
_0805B6B0:
	orrs r0, r1
	str r0, [r3]
	b _0805B6D2
_0805B6B6:
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	subs r1, #0xd
_0805B6BE:
	ands r0, r1
	str r0, [r3]
	b _0805B6D2
_0805B6C4:
	cmp r0, #5
	bls _0805B6D2
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0805b304
	b _0805B6D8
_0805B6D2:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
_0805B6D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity0805b790_Update
Entity0805b790_Update: @ 0x0805B6E0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x40
	movs r5, #0
	ldr r7, _0805B71C @ =0x085ABA20
_0805B6EC:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0805B70A
	ldrb r0, [r4, #2]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r3, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl _call_via_r3
_0805B70A:
	adds r5, #1
	adds r4, #0x8c
	cmp r5, #0xf
	ble _0805B6EC
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805B71C: .4byte 0x085ABA20

	thumb_func_start Entity0805b790_Destroy
Entity0805b790_Destroy: @ 0x0805B720
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x40
	movs r4, #0
_0805B72A:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805b2f4
	adds r4, #1
	adds r5, #0x8c
	cmp r4, #0xf
	ble _0805B72A
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start Entity0805b790_Init
Entity0805b790_Init: @ 0x0805B744
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	movs r0, #0xa
	strh r0, [r6, #0x1c]
	strh r0, [r6, #0x1e]
	adds r5, r6, #0
	adds r5, #0x24
	ldr r1, _0805B78C @ =0x0000210E
	adds r0, r5, #0
	bl Video_GetAuxSprite
	str r4, [r6, #0x20]
	movs r1, #0x32
	cmp r4, #0
	bne _0805B766
	movs r1, #0x2c
_0805B766:
	adds r0, r5, #0
	bl Video_SetAuxSpritePltt
	adds r5, r6, #0
	adds r5, #0x40
	movs r4, #0
_0805B772:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805b228
	adds r4, #1
	adds r5, #0x8c
	cmp r4, #0xf
	ble _0805B772
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805B78C: .4byte 0x0000210E

	thumb_func_start Entity0805b790_Create
Entity0805b790_Create: @ 0x0805B790
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x90
	lsls r1, r1, #4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805B7CC
	ldr r1, _0805B7C4 @ =Entity0805b790_Update
	ldr r2, _0805B7C8 @ =Entity0805b790_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity0805b790_Init
	cmp r0, #0
	bge _0805B7CC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805B7CE
	.align 2, 0
_0805B7C4: .4byte Entity0805b790_Update
_0805B7C8: .4byte Entity0805b790_Destroy
_0805B7CC:
	adds r0, r4, #0
_0805B7CE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805b7d4
FUN_0805b7d4: @ 0x0805B7D4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov sb, r1
	mov r8, r2
	adds r4, r3, #0
	add r1, sp, #8
	bl FUN_0805b1e8
	adds r5, r0, #0
	cmp r5, #0
	bne _0805B7F8
	movs r0, #1
	rsbs r0, r0, #0
	b _0805B886
_0805B7F8:
	adds r6, r5, #0
	adds r6, #0x60
	movs r1, #0
	strb r4, [r5]
	ldrb r0, [r5]
	cmp r0, #1
	beq _0805B816
	cmp r0, #1
	bgt _0805B810
	cmp r0, #0
	beq _0805B81A
	b _0805B822
_0805B810:
	cmp r0, #2
	beq _0805B81A
	b _0805B822
_0805B816:
	strb r0, [r5, #2]
	b _0805B81E
_0805B81A:
	strb r1, [r5, #2]
	movs r0, #1
_0805B81E:
	strb r0, [r5, #1]
	strh r1, [r5, #4]
_0805B822:
	ldr r0, [sp, #0x2c]
	strh r0, [r5, #6]
	ldr r0, [sp, #0x28]
	strb r0, [r5, #3]
	movs r2, #1
	strb r2, [r5, #8]
	mov r0, r8
	str r0, [r5, #0xc]
	adds r1, r5, #0
	adds r1, #0x10
	ldr r0, [r7, #0x20]
	mov r8, r1
	cmp r0, #0
	bne _0805B842
	str r2, [sp]
	b _0805B846
_0805B842:
	movs r0, #2
	str r0, [sp]
_0805B846:
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r1, #0
	ldr r1, [sp, #0x30]
	ldr r2, [sp, #0x34]
	movs r3, #0x10
	bl Hitbox_SetAttack
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	movs r4, #1
	strh r4, [r6, #0x10]
	adds r1, r5, #0
	adds r1, #0x7c
	mov r0, r8
	movs r2, #0
	bl Hitbox_SetPos
	ldr r0, [sp, #8]
	lsls r4, r0
	ldr r0, [r7, #0x18]
	orrs r0, r4
	str r0, [r7, #0x18]
	movs r0, #0
_0805B886:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
