	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081ee2f8
FUN_081ee2f8: @ 0x081EE2F8
	bx lr
	.align 2, 0

	thumb_func_start FUN_081ee2fc
FUN_081ee2fc: @ 0x081EE2FC
	push {lr}
	movs r3, #0
	adds r1, r0, #0
	adds r1, #0x88
	adds r2, r0, #0
	adds r2, #0x1c
_081EE308:
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _081EE316
	strb r3, [r1]
	adds r0, r2, #0
	b _081EE322
_081EE316:
	adds r1, #0x70
	adds r2, #0x70
	adds r3, #1
	cmp r3, #0x2f
	ble _081EE308
	movs r0, #0
_081EE322:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081ee328
FUN_081ee328: @ 0x081EE328
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r2, r5, #0
	adds r2, #0x6e
	ldrh r0, [r2]
	cmp r0, #0
	beq _081EE348
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
	b _081EE4C8
_081EE348:
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r4, r5, #0
	adds r4, #0x48
	adds r0, r5, #0
	adds r0, #0x68
	ldrh r1, [r0]
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	movs r0, #0x5e
	adds r0, r0, r5
	mov ip, r0
	movs r1, #0
	ldrsh r2, [r0, r1]
	ldr r3, _081EE3B8 @ =0x085B0A08
	adds r6, r5, #0
	adds r6, #0x5a
	ldrb r0, [r6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	asrs r0, r0, #0xc
	ldrh r2, [r5, #0x1c]
	adds r0, r0, r2
	strh r0, [r5, #0x1c]
	mov r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	ldrh r1, [r5, #0x20]
	adds r0, r0, r1
	strh r0, [r5, #0x20]
	adds r2, r5, #0
	adds r2, #0x64
	ldrh r0, [r2]
	cmp r0, #0
	beq _081EE3BC
	subs r0, #1
	strh r0, [r2]
	b _081EE3DC
	.align 2, 0
_081EE3B8: .4byte 0x085B0A08
_081EE3BC:
	adds r0, r5, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	ldrh r2, [r5, #0x1e]
	adds r0, r0, r2
	strh r0, [r5, #0x1e]
	adds r2, r5, #0
	adds r2, #0x6d
	ldrb r0, [r2]
	cmp r0, #0
	beq _081EE3D8
	subs r0, #1
	strb r0, [r2]
	b _081EE3DC
_081EE3D8:
	movs r0, #2
	strb r0, [r5, #7]
_081EE3DC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081EE408
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081EE410
_081EE408:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081EE410:
	str r0, [r7]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081EE434
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081EE43C
_081EE434:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081EE43C:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081EE474 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081EE4BA
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081EE47E
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081EE478
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081EE494
	.align 2, 0
_081EE474: .4byte 0x0000FFFF
_081EE478:
	subs r0, #1
	strh r0, [r4, #8]
	b _081EE492
_081EE47E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081EE492
	strh r1, [r4, #8]
	movs r2, #1
	b _081EE494
_081EE492:
	movs r2, #0
_081EE494:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081EE4BC
	movs r0, #1
	strb r0, [r4, #7]
	b _081EE4BC
_081EE4BA:
	movs r2, #0
_081EE4BC:
	cmp r2, #0
	beq _081EE4C8
	adds r1, r5, #0
	adds r1, #0x58
	movs r0, #2
	strb r0, [r1]
_081EE4C8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081ee4d0
FUN_081ee4d0: @ 0x081EE4D0
	push {r4, lr}
	adds r4, r0, #0
	bl AuxSprite_Remove
	adds r1, r4, #0
	adds r1, #0x6c
	movs r0, #0xff
	strb r0, [r1]
	adds r4, #0x58
	movs r0, #0
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081ee4ec
FUN_081ee4ec: @ 0x081EE4EC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x38
	ldr r4, [sp, #0x4c]
	ldr r6, [sp, #0x50]
	ldr r5, [sp, #0x54]
	str r5, [sp, #8]
	ldr r7, [sp, #0x58]
	str r7, [sp, #0xc]
	ldr r5, [sp, #0x5c]
	str r5, [sp, #0x10]
	ldr r7, [sp, #0x60]
	str r7, [sp, #0x14]
	ldr r5, [sp, #0x64]
	ldr r7, [sp, #0x68]
	str r7, [sp, #0x1c]
	ldr r7, [sp, #0x6c]
	str r7, [sp, #0x20]
	str r4, [sp]
	str r6, [sp, #4]
	str r5, [sp, #0x18]
	ldr r4, _081EE534 @ =0x00004384
	str r4, [sp, #0x24]
	ldr r4, _081EE538 @ =0x0000F62B
	str r4, [sp, #0x28]
	movs r4, #0
	str r4, [sp, #0x2c]
	str r4, [sp, #0x30]
	adds r5, #0x7d
	str r5, [sp, #0x34]
	bl FUN_081ee5d0
	add sp, #0x38
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081EE534: .4byte 0x00004384
_081EE538: .4byte 0x0000F62B

	thumb_func_start FUN_081ee53c
FUN_081ee53c: @ 0x081EE53C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x38
	ldr r4, [sp, #0x4c]
	ldr r5, [sp, #0x50]
	ldr r6, [sp, #0x54]
	ldr r7, [sp, #0x58]
	str r7, [sp, #0xc]
	ldr r7, [sp, #0x5c]
	str r7, [sp, #0x10]
	ldr r7, [sp, #0x60]
	str r7, [sp, #0x14]
	ldr r7, [sp, #0x64]
	str r7, [sp, #0x18]
	ldr r7, [sp, #0x68]
	str r7, [sp, #0x1c]
	ldr r7, [sp, #0x6c]
	str r7, [sp, #0x20]
	ldr r7, [sp, #0x70]
	str r7, [sp, #0x24]
	ldr r7, [sp, #0x74]
	str r7, [sp, #0x28]
	ldr r7, [sp, #0x78]
	str r7, [sp, #0x2c]
	ldr r7, [sp, #0x7c]
	str r7, [sp, #0x30]
	ldr r7, [sp, #0x80]
	str r7, [sp, #0x34]
	str r4, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	bl FUN_081ee5d0
	add sp, #0x38
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081ee584
FUN_081ee584: @ 0x081EE584
	push {r4, r5, r6, r7, lr}
	sub sp, #0x38
	ldr r4, [sp, #0x4c]
	ldr r5, [sp, #0x50]
	ldr r6, [sp, #0x54]
	str r6, [sp, #8]
	ldr r7, [sp, #0x58]
	str r7, [sp, #0xc]
	ldr r6, [sp, #0x5c]
	str r6, [sp, #0x10]
	ldr r7, [sp, #0x60]
	str r7, [sp, #0x14]
	ldr r6, [sp, #0x64]
	ldr r7, [sp, #0x68]
	str r7, [sp, #0x1c]
	str r4, [sp]
	str r5, [sp, #4]
	str r6, [sp, #0x18]
	movs r5, #0
	str r5, [sp, #0x20]
	ldr r4, _081EE5C8 @ =0x00004384
	str r4, [sp, #0x24]
	ldr r4, _081EE5CC @ =0x0000F62B
	str r4, [sp, #0x28]
	str r5, [sp, #0x2c]
	str r5, [sp, #0x30]
	adds r6, #0x7d
	str r6, [sp, #0x34]
	bl FUN_081ee5d0
	add sp, #0x38
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081EE5C8: .4byte 0x00004384
_081EE5CC: .4byte 0x0000F62B

	thumb_func_start FUN_081ee5d0
FUN_081ee5d0: @ 0x081EE5D0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	mov sl, r1
	mov sb, r2
	mov r8, r3
	ldr r0, _081EE6F8 @ =0x030001D0
	ldr r6, [r0]
	cmp r6, #0
	bne _081EE5F6
	bl Entity081ee7a8_Create
	adds r6, r0, #0
	cmp r6, #0
	beq _081EE6E8
_081EE5F6:
	adds r0, r6, #0
	bl FUN_081ee2fc
	adds r7, r0, #0
	cmp r7, #0
	beq _081EE6E8
	adds r0, #0x58
	movs r5, #0
	movs r1, #1
	strb r1, [r0]
	adds r0, #0xe
	strh r5, [r0]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	adds r4, r7, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, [sp, #0x48]
	bl Video_GetAuxSprite
	ldr r0, _081EE6FC @ =0x0000922E
	ldr r1, [sp, #0x4c]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl GetFile
	str r0, [r6, #0x18]
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r7, #0
	adds r0, #0x48
	ldr r1, [r6, #0x18]
	ldr r2, [sp, #0x50]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r3, [sp, #0x54]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r5, [sp]
	bl AuxAnim_SetAnim
	adds r0, r4, #0
	ldr r1, [sp, #0x58]
	bl Video_SetAuxSpritePltt
	ldr r6, _081EE700 @ =0x0203B400
	ldr r4, _081EE704 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _081EE708 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	mov r1, sb
	bl Mod
	add r0, sl
	adds r1, r7, #0
	adds r1, #0x5c
	strh r0, [r1]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ldr r1, [sp, #0x24]
	bl Mod
	ldr r2, [sp, #0x24]
	asrs r1, r2, #1
	subs r0, r0, r1
	add r0, r8
	adds r2, r7, #0
	adds r2, #0x5e
	strh r0, [r2]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ldr r1, [sp, #0x30]
	bl Mod
	ldr r1, [sp, #0x2c]
	adds r1, r1, r0
	adds r0, r7, #0
	adds r0, #0x5a
	strb r1, [r0]
	adds r1, r7, #0
	adds r1, #0x64
	ldr r0, [sp, #0x28]
	strh r0, [r1]
	adds r1, #4
	ldr r0, [sp, #0x34]
	strh r0, [r1]
	adds r1, #5
	movs r0, #0xc
	strb r0, [r1]
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
	ldr r1, [sp, #0x40]
	orrs r0, r1
	str r0, [r7]
	ldr r0, [sp, #0x38]
	strb r0, [r7, #7]
	adds r1, r7, #0
	adds r1, #0x6e
	ldr r0, [sp, #0x44]
	strh r0, [r1]
_081EE6E8:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081EE6F8: .4byte 0x030001D0
_081EE6FC: .4byte 0x0000922E
_081EE700: .4byte 0x0203B400
_081EE704: .4byte 0x030046B8
_081EE708: .4byte 0x000003FF

	thumb_func_start Entity081ee7a8_Update
Entity081ee7a8_Update: @ 0x081EE70C
	push {r4, r5, r6, r7, lr}
	ldr r7, _081EE744 @ =0x085AE4D4
	adds r4, r0, #0
	adds r4, #0x74
	adds r5, r0, #0
	adds r5, #0x1c
	movs r6, #0x2f
_081EE71A:
	movs r0, #0x14
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _081EE730
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
_081EE730:
	adds r4, #0x70
	adds r5, #0x70
	subs r6, #1
	cmp r6, #0
	bge _081EE71A
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EE744: .4byte 0x085AE4D4

	thumb_func_start Entity081ee7a8_Destroy
Entity081ee7a8_Destroy: @ 0x081EE748
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r5, #0x88
	adds r4, r0, #0
	adds r4, #0x1c
	movs r6, #0x2f
_081EE754:
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	blt _081EE762
	adds r0, r4, #0
	bl AuxSprite_Remove
_081EE762:
	adds r5, #0x70
	adds r4, #0x70
	subs r6, #1
	cmp r6, #0
	bge _081EE754
	movs r1, #0
	ldr r0, _081EE77C @ =0x030001D0
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081EE77C: .4byte 0x030001D0

	thumb_func_start Entity081ee7a8_Init
Entity081ee7a8_Init: @ 0x081EE780
	push {lr}
	ldr r1, _081EE7A4 @ =0x030001D0
	str r0, [r1]
	movs r3, #0xff
	adds r1, r0, #0
	adds r1, #0x88
	movs r2, #0x2f
_081EE78E:
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r1, #0x70
	subs r2, #1
	cmp r2, #0
	bge _081EE78E
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_081EE7A4: .4byte 0x030001D0

	thumb_func_start Entity081ee7a8_Create
Entity081ee7a8_Create: @ 0x081EE7A8
	push {r4, lr}
	ldr r0, _081EE7DC @ =0x030001D0
	ldr r0, [r0]
	cmp r0, #0
	bne _081EE7EE
	ldr r1, _081EE7E0 @ =0x0000151C
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081EE7EC
	ldr r1, _081EE7E4 @ =Entity081ee7a8_Update
	ldr r2, _081EE7E8 @ =Entity081ee7a8_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081ee7a8_Init
	cmp r0, #0
	bge _081EE7EC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081EE7EE
	.align 2, 0
_081EE7DC: .4byte 0x030001D0
_081EE7E0: .4byte 0x0000151C
_081EE7E4: .4byte Entity081ee7a8_Update
_081EE7E8: .4byte Entity081ee7a8_Destroy
_081EE7EC:
	adds r0, r4, #0
_081EE7EE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ee7f4
FUN_081ee7f4: @ 0x081EE7F4
	ldr r1, _081EE7FC @ =0x030001D0
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081EE7FC: .4byte 0x030001D0
