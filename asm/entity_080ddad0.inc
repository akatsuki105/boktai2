	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080dd324
FUN_080dd324: @ 0x080DD324
	push {lr}
	adds r1, r0, #0
	adds r2, r1, #0
	cmp r1, #0
	beq _080DD35C
	ldr r3, _080DD358 @ =0x0000012F
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080DD35C
	movs r3, #0x99
	lsls r3, r3, #1
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _080DD35C
	movs r1, #0x97
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080DD35C
	movs r0, #1
	b _080DD35E
	.align 2, 0
_080DD358: .4byte 0x0000012F
_080DD35C:
	movs r0, #0
_080DD35E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080dd364
FUN_080dd364: @ 0x080DD364
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	movs r0, #0
	mov sb, r0
	mov sl, r0
	movs r0, #0x70
	bl VM_SeekToKeyword
	add r1, sp, #0x10
	mov r8, r1
	cmp r0, #0
	beq _080DD3E8
	bl VM_GetPC
	cmp r0, #0
	beq _080DD392
	bl Script_GetValue
	b _080DD394
_080DD392:
	movs r0, #0
_080DD394:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080DD3B0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	bl VM_GetPC
	cmp r0, #0
	beq _080DD3B4
	bl Script_GetValue
	b _080DD3B6
	.align 2, 0
_080DD3B0: .4byte 0xFFFF0000
_080DD3B4:
	movs r0, #0
_080DD3B6:
	lsls r2, r0, #0x10
	ldr r1, _080DD3D0 @ =0x0000FFFF
	ldr r0, [sp, #0x10]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x10]
	bl VM_GetPC
	cmp r0, #0
	beq _080DD3D4
	bl Script_GetValue
	b _080DD3D6
	.align 2, 0
_080DD3D0: .4byte 0x0000FFFF
_080DD3D4:
	movs r0, #0
_080DD3D6:
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _080DD400 @ =0xFFFF0000
	add r1, sp, #0x10
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	mov r8, r1
_080DD3E8:
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080DD41C
	bl VM_GetPC
	cmp r0, #0
	beq _080DD404
	bl Script_GetValue
	b _080DD406
	.align 2, 0
_080DD400: .4byte 0xFFFF0000
_080DD404:
	movs r0, #0
_080DD406:
	mov sl, r0
	bl VM_GetPC
	cmp r0, #0
	beq _080DD418
	bl Script_GetValue
	mov sb, r0
	b _080DD41C
_080DD418:
	movs r1, #0
	mov sb, r1
_080DD41C:
	movs r0, #0x76
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080DD490
	bl VM_GetPC
	cmp r0, #0
	beq _080DD434
	bl Script_GetValue
	b _080DD436
_080DD434:
	movs r0, #0
_080DD436:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080DD454 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	bl VM_GetPC
	cmp r0, #0
	beq _080DD458
	bl Script_GetValue
	b _080DD45A
	.align 2, 0
_080DD454: .4byte 0xFFFF0000
_080DD458:
	movs r0, #0
_080DD45A:
	lsls r2, r0, #0x10
	ldr r1, _080DD474 @ =0x0000FFFF
	ldr r0, [sp, #0x18]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x18]
	bl VM_GetPC
	cmp r0, #0
	beq _080DD478
	bl Script_GetValue
	b _080DD47A
	.align 2, 0
_080DD474: .4byte 0x0000FFFF
_080DD478:
	movs r0, #0
_080DD47A:
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _080DD48C @ =0xFFFF0000
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	b _080DD49A
	.align 2, 0
_080DD48C: .4byte 0xFFFF0000
_080DD490:
	ldr r2, _080DD4F4 @ =0xFFFF0000
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r2
_080DD49A:
	str r0, [r1, #4]
	adds r7, r1, #0
	movs r0, #0x6c
	movs r1, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r5, r0, #0
	add r4, sp, #0x20
	movs r0, #0
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	adds r1, r4, #0
	ldr r2, _080DD4F8 @ =0x05000002
	bl CpuSet
	mov r0, sb
	str r0, [sp]
	str r6, [sp, #4]
	str r5, [sp, #8]
	mov r0, r8
	adds r1, r7, #0
	adds r2, r4, #0
	mov r3, sl
	bl FUN_080dce8c
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r1, #1
	orrs r1, r2
	strh r1, [r0]
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DD4F4: .4byte 0xFFFF0000
_080DD4F8: .4byte 0x05000002

	thumb_func_start FUN_080dd4fc
FUN_080dd4fc: @ 0x080DD4FC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x24
	adds r6, r0, #0
	adds r0, #0x58
	ldrh r0, [r0]
	cmp r0, #5
	bls _080DD512
	b _080DD6E6
_080DD512:
	lsls r0, r0, #2
	ldr r1, _080DD51C @ =_080DD520
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DD51C: .4byte _080DD520
_080DD520: @ jump table
	.4byte _080DD538 @ case 0
	.4byte _080DD570 @ case 1
	.4byte _080DD5B4 @ case 2
	.4byte _080DD5FC @ case 3
	.4byte _080DD644 @ case 4
	.4byte _080DD6A4 @ case 5
_080DD538:
	ldr r0, [r6, #0x60]
	cmp r0, #0
	bne _080DD544
	ldr r0, _080DD56C @ =0x00000165
	bl PlaySound_082406e0
_080DD544:
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x50
_080DD54A:
	lsls r3, r5, #6
	movs r0, #0x54
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	ldr r0, [r6, #0x60]
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl FUN_081eec74
	adds r5, #1
	cmp r5, #5
	ble _080DD54A
	b _080DD6E6
	.align 2, 0
_080DD56C: .4byte 0x00000165
_080DD570:
	movs r5, #0
	adds r7, r6, #0
	adds r7, #0x50
	movs r0, #1
	mov r8, r0
_080DD57A:
	lsls r4, r5, #6
	movs r0, #0x22
	str r0, [sp]
	mov r1, r8
	str r1, [sp, #4]
	ldr r0, [r6, #0x60]
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r1, #1
	movs r2, #8
	adds r3, r4, #0
	bl FUN_081eec74
	movs r0, #0x40
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	ldr r0, [r6, #0x60]
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r1, #1
	movs r2, #0xe
	adds r3, r4, #0
	bl FUN_081eec74
	adds r5, #1
	cmp r5, #3
	ble _080DD57A
	b _080DD6E6
_080DD5B4:
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x50
	ldr r7, _080DD5F0 @ =0x030046B8
_080DD5BC:
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080DD5F4 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080DD5F8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #0xf
	ands r2, r0
	lsls r3, r5, #6
	movs r0, #0x96
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	ldr r0, [r6, #0x60]
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081eec74
	adds r5, #1
	cmp r5, #5
	ble _080DD5BC
	b _080DD6E6
	.align 2, 0
_080DD5F0: .4byte 0x030046B8
_080DD5F4: .4byte 0x000003FF
_080DD5F8: .4byte 0x0203B400
_080DD5FC:
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x50
	ldr r7, _080DD638 @ =0x030046B8
_080DD604:
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080DD63C @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080DD640 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #0x1f
	ands r2, r0
	lsls r3, r5, #5
	movs r0, #0x64
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	ldr r0, [r6, #0x60]
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081eec74
	adds r5, #1
	cmp r5, #7
	ble _080DD604
	b _080DD6E6
	.align 2, 0
_080DD638: .4byte 0x030046B8
_080DD63C: .4byte 0x000003FF
_080DD640: .4byte 0x0203B400
_080DD644:
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x50
	ldr r0, _080DD698 @ =0x0203B400
	mov sb, r0
	ldr r1, _080DD69C @ =0x030046B8
	mov r8, r1
	ldr r7, _080DD6A0 @ =0x000003FF
_080DD654:
	mov r0, r8
	ldr r1, [r0]
	adds r1, #1
	ands r1, r7
	lsls r0, r1, #1
	add r0, sb
	ldrh r2, [r0]
	movs r0, #0xf
	ands r2, r0
	adds r2, #5
	adds r1, #1
	ands r1, r7
	mov r0, r8
	str r1, [r0]
	lsls r1, r1, #1
	add r1, sb
	ldrh r1, [r1]
	movs r0, #0x3f
	ands r1, r0
	adds r1, #0x50
	lsls r3, r5, #4
	str r1, [sp]
	movs r0, #2
	str r0, [sp, #4]
	ldr r0, [r6, #0x60]
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081eec74
	adds r5, #1
	cmp r5, #0xf
	ble _080DD654
	b _080DD6E6
	.align 2, 0
_080DD698: .4byte 0x0203B400
_080DD69C: .4byte 0x030046B8
_080DD6A0: .4byte 0x000003FF
_080DD6A4:
	ldr r0, [r6, #0x60]
	cmp r0, #0
	bne _080DD6E6
	movs r7, #2
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x50
	movs r6, #8
_080DD6B4:
	movs r0, #0xc
	str r0, [sp]
	movs r0, #0x12
	str r0, [sp, #4]
	lsls r0, r5, #5
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	movs r0, #0x40
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	str r7, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x1c]
	str r6, [sp, #0x20]
	adds r0, r4, #0
	movs r1, #8
	movs r2, #0x10
	movs r3, #4
	bl FUN_081ee4ec
	adds r5, #1
	cmp r5, #7
	ble _080DD6B4
_080DD6E6:
	add sp, #0x24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080dd6f4
FUN_080dd6f4: @ 0x080DD6F4
	push {lr}
	adds r2, r0, #0
	ldr r0, _080DD740 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080DD73A
	ldr r0, [r2, #0x60]
	cmp r0, #0
	bne _080DD73A
	adds r0, r2, #0
	adds r0, #0x58
	ldrh r0, [r0]
	ldr r3, _080DD744 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r2, _080DD748 @ =0x000003FF
	ands r1, r2
	str r1, [r3]
	lsls r1, r1, #1
	ldr r2, _080DD74C @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #3
	ands r1, r2
	adds r1, #9
	bl Mod
	cmp r0, #0
	bne _080DD73A
	ldr r0, _080DD750 @ =0x00000339
	bl PlaySound_082406e0
_080DD73A:
	pop {r0}
	bx r0
	.align 2, 0
_080DD740: .4byte 0x030047A4
_080DD744: .4byte 0x030046B8
_080DD748: .4byte 0x000003FF
_080DD74C: .4byte 0x0203B400
_080DD750: .4byte 0x00000339

	thumb_func_start FUN_080dd754
FUN_080dd754: @ 0x080DD754
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	mov r8, r1
	mov sb, r2
	adds r7, r3, #0
	ldr r3, [sp, #0x38]
	adds r6, r5, #0
	ldr r2, _080DD7C8 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r4, #0x80
	lsls r4, r4, #1
	orrs r0, r4
	ldr r1, _080DD7CC @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r4
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _080DD7D0 @ =0x00002001
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	str r3, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r0, [r5, #0x60]
	cmp r0, #0
	bne _080DD7D8
	ldr r0, _080DD7D4 @ =0x00240004
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0x40
	bl Hitbox_SetAttack
	b _080DD7EC
	.align 2, 0
_080DD7C8: .4byte 0xFFFF0000
_080DD7CC: .4byte 0x0000FFFF
_080DD7D0: .4byte 0x00002001
_080DD7D4: .4byte 0x00240004
_080DD7D8:
	movs r0, #0x80
	lsls r0, r0, #0xb
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0x40
	bl Hitbox_SetAttack
_080DD7EC:
	ldr r0, _080DD814 @ =0x00003246
	strh r0, [r6, #4]
	adds r1, r5, #0
	adds r1, #0x50
	adds r0, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r6, #0
	movs r1, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DD814: .4byte 0x00003246

	thumb_func_start FUN_080dd818
FUN_080dd818: @ 0x080DD818
	bx lr
	.align 2, 0

	thumb_func_start FUN_080dd81c
FUN_080dd81c: @ 0x080DD81C
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_080dd4fc
	adds r0, r4, #0
	bl FUN_080dd6f4
	adds r5, r4, #0
	adds r5, #0x58
	ldrh r0, [r5]
	subs r0, #0xa
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _080DD842
	adds r0, r4, #0
	bl Hitbox_Register
_080DD842:
	ldrh r0, [r5]
	cmp r0, #0x28
	bls _080DD852
	adds r1, r4, #0
	adds r1, #0x5d
	movs r0, #2
	strb r0, [r1]
	b _080DD856
_080DD852:
	adds r0, #1
	strh r0, [r5]
_080DD856:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080dd85c
FUN_080dd85c: @ 0x080DD85C
	push {lr}
	adds r3, r1, #0
	adds r3, #0x5d
	movs r2, #0
	strb r2, [r3]
	movs r2, #0x5e
	adds r2, r2, r1
	mov ip, r2
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	movs r3, #1
	lsls r3, r2
	ldr r2, [r0, #0x18]
	bics r2, r3
	str r2, [r0, #0x18]
	movs r0, #0xff
	mov r3, ip
	strb r0, [r3]
	adds r0, r1, #0
	movs r1, #0x64
	bl ClearMemory
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080dd890
FUN_080dd890: @ 0x080DD890
	push {r4, lr}
	adds r3, r0, #0
	movs r4, #0
	movs r2, #1
_080DD898:
	adds r1, r2, #0
	lsls r1, r4
	ldr r0, [r3, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _080DD8A8
	movs r0, #1
	b _080DD8AA
_080DD8A8:
	movs r0, #0
_080DD8AA:
	cmp r0, #0
	bne _080DD8C6
	movs r0, #0x64
	muls r0, r4, r0
	adds r0, #0x1c
	adds r0, r3, r0
	adds r1, r0, #0
	adds r1, #0x5e
	strb r4, [r1]
	lsls r2, r4
	ldr r1, [r3, #0x18]
	orrs r1, r2
	str r1, [r3, #0x18]
	b _080DD8CE
_080DD8C6:
	adds r4, #1
	cmp r4, #4
	ble _080DD898
	movs r0, #0
_080DD8CE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080dd8d4
FUN_080dd8d4: @ 0x080DD8D4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	cmp r4, #0
	beq _080DD92C
	ldr r0, _080DD938 @ =0x03000170
	ldr r0, [r0]
	cmp r0, #0
	bne _080DD8F4
	bl Entity080ddad0_Create
	cmp r0, #0
	beq _080DD92C
_080DD8F4:
	bl FUN_080dd890
	adds r3, r0, #0
	cmp r3, #0
	beq _080DD92C
	adds r1, r3, #0
	adds r1, #0x5d
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x50]
	str r1, [r3, #0x54]
	adds r0, r3, #0
	adds r0, #0x58
	strh r2, [r0]
	adds r0, #4
	strb r5, [r0]
	str r6, [r3, #0x60]
	ldr r0, [sp, #0x20]
	str r0, [sp]
	adds r0, r3, #0
	adds r1, r7, #0
	ldr r2, [sp, #0x18]
	ldr r3, [sp, #0x1c]
	bl FUN_080dd754
_080DD92C:
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DD938: .4byte 0x03000170

	thumb_func_start FUN_080dd93c
FUN_080dd93c: @ 0x080DD93C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r0, _080DD978 @ =0x03000170
	ldr r0, [r0]
	cmp r0, #0
	bne _080DD954
	bl Entity080ddad0_Create
	cmp r0, #0
	beq _080DDA46
_080DD954:
	bl FUN_080dd890
	adds r5, r0, #0
	cmp r5, #0
	beq _080DDA46
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080DD9B2
	bl VM_GetPC
	cmp r0, #0
	beq _080DD97C
	bl Script_GetValue
	adds r1, r0, #0
	b _080DD97E
	.align 2, 0
_080DD978: .4byte 0x03000170
_080DD97C:
	movs r1, #0
_080DD97E:
	adds r0, r5, #0
	adds r0, #0x50
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _080DD992
	bl Script_GetValue
	b _080DD994
_080DD992:
	movs r0, #0
_080DD994:
	adds r1, r5, #0
	adds r1, #0x52
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _080DD9AA
	bl Script_GetValue
	adds r1, r0, #0
	b _080DD9AC
_080DD9AA:
	movs r1, #0
_080DD9AC:
	adds r0, r5, #0
	adds r0, #0x54
	strh r1, [r0]
_080DD9B2:
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080DDA0C
	bl VM_GetPC
	cmp r0, #0
	beq _080DD9CE
	bl Script_GetValue
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b _080DD9D0
_080DD9CE:
	movs r0, #0
_080DD9D0:
	mov r8, r0
	bl VM_GetPC
	cmp r0, #0
	beq _080DD9E4
	bl Script_GetValue
	lsls r0, r0, #0x10
	asrs r7, r0, #0x10
	b _080DD9E6
_080DD9E4:
	movs r7, #0
_080DD9E6:
	bl VM_GetPC
	cmp r0, #0
	beq _080DD9F8
	bl Script_GetValue
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	b _080DD9FA
_080DD9F8:
	movs r6, #0
_080DD9FA:
	bl VM_GetPC
	cmp r0, #0
	beq _080DDA14
	bl Script_GetValue
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	b _080DDA16
_080DDA0C:
	movs r0, #0
	mov r8, r0
	movs r7, #0
	movs r6, #0
_080DDA14:
	movs r4, #0
_080DDA16:
	movs r0, #0x63
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r5, #0x60]
	adds r2, r5, #0
	adds r2, #0x5d
	movs r1, #0
	movs r0, #1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r1, r5, #0
	adds r1, #0x5c
	movs r0, #2
	strb r0, [r1]
	str r4, [sp]
	adds r0, r5, #0
	mov r1, r8
	adds r2, r7, #0
	adds r3, r6, #0
	bl FUN_080dd754
_080DDA46:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity080ddad0_Update
Entity080ddad0_Update: @ 0x080DDA54
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _080DDAA0
	movs r5, #0
	ldr r6, _080DDA74 @ =0x085AD348
_080DDA62:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r4, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _080DDA78
	movs r0, #1
	b _080DDA7A
	.align 2, 0
_080DDA74: .4byte 0x085AD348
_080DDA78:
	movs r0, #0
_080DDA7A:
	cmp r0, #0
	beq _080DDA9A
	movs r0, #0x64
	adds r1, r5, #0
	muls r1, r0, r1
	adds r1, #0x1c
	adds r1, r4, r1
	adds r0, r1, #0
	adds r0, #0x5d
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r2, [r0]
	adds r0, r4, #0
	bl _call_via_r2
_080DDA9A:
	adds r5, #1
	cmp r5, #4
	ble _080DDA62
_080DDAA0:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start Entity080ddad0_Destroy
Entity080ddad0_Destroy: @ 0x080DDAA8
	ldr r1, _080DDAB0 @ =0x03000170
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080DDAB0: .4byte 0x03000170

	thumb_func_start FUN_080ddab4
FUN_080ddab4: @ 0x080DDAB4
	bx lr
	.align 2, 0

	thumb_func_start Entity080ddad0_Init
Entity080ddad0_Init: @ 0x080DDAB8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080ddab4
	ldr r0, _080DDACC @ =0x03000170
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080DDACC: .4byte 0x03000170

	thumb_func_start Entity080ddad0_Create
Entity080ddad0_Create: @ 0x080DDAD0
	push {r4, lr}
	ldr r0, _080DDB08 @ =0x03000170
	ldr r0, [r0]
	cmp r0, #0
	bne _080DDB16
	movs r1, #0x84
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080DDB14
	ldr r1, _080DDB0C @ =Entity080ddad0_Update
	ldr r2, _080DDB10 @ =Entity080ddad0_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	movs r1, #0
	bl Entity080ddad0_Init
	cmp r0, #0
	bge _080DDB14
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080DDB16
	.align 2, 0
_080DDB08: .4byte 0x03000170
_080DDB0C: .4byte Entity080ddad0_Update
_080DDB10: .4byte Entity080ddad0_Destroy
_080DDB14:
	adds r0, r4, #0
_080DDB16:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080ddb1c
FUN_080ddb1c: @ 0x080DDB1C
	ldr r1, _080DDB24 @ =0x03000170
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080DDB24: .4byte 0x03000170

	thumb_func_start Entity080de11c_Update
Entity080de11c_Update: @ 0x080DDB28
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #0xce
	lsls r0, r0, #4
	adds r1, r7, r0
	ldr r0, [r1]
	cmp r0, #0
	bne _080DDB42
	b _080DDC90
_080DDB42:
	movs r2, #1
	mov sb, r2
	movs r3, #2
	mov sl, r3
	adds r6, r7, #0
	adds r6, #0x58
	adds r4, r7, #0
	adds r4, #0x18
	mov ip, r1
	movs r0, #0x2f
	mov r8, r0
_080DDB58:
	ldrb r0, [r6]
	cmp r0, #0
	bne _080DDB60
	b _080DDC7E
_080DDB60:
	ldrh r0, [r4, #0x38]
	ldrh r1, [r4, #0x28]
	adds r0, r0, r1
	strh r0, [r4, #0x28]
	ldrh r0, [r4, #0x3a]
	ldrh r2, [r4, #0x2a]
	adds r0, r0, r2
	strh r0, [r4, #0x2a]
	ldrh r0, [r4, #0x3c]
	ldrh r3, [r4, #0x2c]
	adds r0, r0, r3
	strh r0, [r4, #0x2c]
	ldr r1, _080DDBBC @ =0x00000CDC
	adds r0, r7, r1
	ldr r3, [r0]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r2, [r5]
	lsrs r2, r2, #6
	ldrb r1, [r4, #0x1a]
	lsrs r1, r1, #3
	ldrb r0, [r4, #0x1b]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r4, #0x18]
	ldrb r0, [r4, #4]
	mov r2, sb
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r3, sb
	ands r0, r3
	cmp r2, r0
	beq _080DDBC0
	ldr r0, [r4, #0x10]
	movs r1, #4
	orrs r0, r1
	b _080DDBC8
	.align 2, 0
_080DDBBC: .4byte 0x00000CDC
_080DDBC0:
	ldr r0, [r4, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080DDBC8:
	str r0, [r4, #0x10]
	ldrb r0, [r4, #4]
	mov r1, sl
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sl
	ands r0, r2
	cmp r1, r0
	beq _080DDBEC
	ldr r0, [r4, #0x10]
	movs r1, #8
	orrs r0, r1
	b _080DDBF4
_080DDBEC:
	ldr r0, [r4, #0x10]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080DDBF4:
	str r0, [r4, #0x10]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _080DDC2C @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _080DDC64
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DDC36
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DDC30
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080DDC4C
	.align 2, 0
_080DDC2C: .4byte 0x0000FFFF
_080DDC30:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DDC4A
_080DDC36:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080DDC4A
	strh r1, [r4, #8]
	movs r2, #1
	b _080DDC4C
_080DDC4A:
	movs r2, #0
_080DDC4C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	b _080DDC66
_080DDC64:
	movs r2, #0
_080DDC66:
	cmp r2, #0
	beq _080DDC7E
	movs r0, #0
	strb r0, [r6]
	ldr r0, [r4, #0x10]
	mov r3, sb
	orrs r0, r3
	str r0, [r4, #0x10]
	mov r1, ip
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
_080DDC7E:
	adds r6, #0x44
	adds r4, #0x44
	movs r2, #1
	rsbs r2, r2, #0
	add r8, r2
	mov r3, r8
	cmp r3, #0
	blt _080DDC90
	b _080DDB58
_080DDC90:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity080de11c_Destroy
Entity080de11c_Destroy: @ 0x080DDCA0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x28
	movs r5, #0x2f
_080DDCA8:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x44
	subs r5, #1
	cmp r5, #0
	bge _080DDCA8
	movs r1, #0
	ldr r0, _080DDCC4 @ =0x03000174
	str r1, [r0]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080DDCC4: .4byte 0x03000174

	thumb_func_start FUN_080ddcc8
FUN_080ddcc8: @ 0x080DDCC8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	adds r6, r2, #0
	str r3, [sp, #0xc]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #8]
	ldr r0, _080DDCF8 @ =0x03000174
	ldr r0, [r0]
	str r0, [sp, #0x10]
	cmp r0, #0
	bne _080DDCFC
	bl Entity080de11c_Create
	str r0, [sp, #0x10]
	cmp r0, #0
	bne _080DDCFC
	movs r0, #0
	b _080DDF74
	.align 2, 0
_080DDCF8: .4byte 0x03000174
_080DDCFC:
	movs r0, #0
	str r0, [sp, #0x14]
	ldr r1, _080DDD34 @ =0x030046B8
	mov sb, r1
	ldr r2, [sp, #0x10]
	adds r2, #0x50
	mov sl, r2
	ldr r0, [sp, #0x10]
	adds r0, #0x28
	mov r8, r0
	mov r4, r8
	ldr r1, [sp, #0x10]
	adds r1, #0x18
	str r1, [sp, #0x18]
_080DDD18:
	mov r2, sl
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _080DDD22
	b _080DDF58
_080DDD22:
	cmp r6, #0
	beq _080DDE0E
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #0
	bne _080DDD38
	ldrh r0, [r7]
	b _080DDD78
	.align 2, 0
_080DDD34: .4byte 0x030046B8
_080DDD38:
	mov r2, sb
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080DDD64 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _080DDD68 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #0
	ldrsh r1, [r6, r2]
	bl Mod
	adds r1, r0, #0
	movs r2, #0
	ldrsh r0, [r6, r2]
	cmp r0, #0
	blt _080DDD6C
	asrs r0, r0, #1
	b _080DDD72
	.align 2, 0
_080DDD64: .4byte 0x000003FF
_080DDD68: .4byte 0x0203B400
_080DDD6C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080DDD72:
	subs r0, r1, r0
	ldrh r1, [r7]
	adds r0, r0, r1
_080DDD78:
	strh r0, [r4, #0x18]
	movs r2, #2
	ldrsh r0, [r6, r2]
	cmp r0, #0
	bne _080DDD86
	ldrh r0, [r7, #2]
	b _080DDDC4
_080DDD86:
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _080DDDB0 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r1, _080DDDB4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #2
	ldrsh r1, [r6, r2]
	bl Mod
	adds r1, r0, #0
	movs r2, #2
	ldrsh r0, [r6, r2]
	cmp r0, #0
	blt _080DDDB8
	asrs r0, r0, #1
	b _080DDDBE
	.align 2, 0
_080DDDB0: .4byte 0x000003FF
_080DDDB4: .4byte 0x0203B400
_080DDDB8:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080DDDBE:
	subs r0, r1, r0
	ldrh r1, [r7, #2]
	adds r0, r0, r1
_080DDDC4:
	strh r0, [r4, #0x1a]
	movs r2, #4
	ldrsh r0, [r6, r2]
	cmp r0, #0
	beq _080DDE16
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _080DDDF8 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r1, _080DDDFC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	adds r1, r0, #0
	movs r2, #4
	ldrsh r0, [r6, r2]
	cmp r0, #0
	blt _080DDE00
	asrs r0, r0, #1
	b _080DDE06
	.align 2, 0
_080DDDF8: .4byte 0x000003FF
_080DDDFC: .4byte 0x0203B400
_080DDE00:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080DDE06:
	subs r0, r1, r0
	ldrh r1, [r7, #4]
	adds r0, r0, r1
	b _080DDE18
_080DDE0E:
	ldrh r0, [r7]
	strh r0, [r4, #0x18]
	ldrh r0, [r7, #2]
	strh r0, [r4, #0x1a]
_080DDE16:
	ldrh r0, [r7, #4]
_080DDE18:
	strh r0, [r4, #0x1c]
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	add r2, sp, #0x48
	ldrb r2, [r2]
	strb r2, [r4, #0xf]
	movs r0, #1
	mov r1, sl
	strb r0, [r1, #8]
	movs r2, #0
	str r2, [sp, #4]
	add r0, sp, #4
	ldr r2, _080DDE64 @ =0x05000002
	bl CpuSet
	ldr r0, [sp, #0x3c]
	cmp r0, #0
	beq _080DDE9A
	mov r3, sl
	ldr r2, _080DDE68 @ =0x085B0A08
	ldr r0, [sp, #0xc]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, [sp, #0x3c]
	muls r0, r1, r0
	cmp r0, #0
	blt _080DDE6C
	asrs r0, r0, #0xc
	b _080DDE72
	.align 2, 0
_080DDE64: .4byte 0x05000002
_080DDE68: .4byte 0x085B0A08
_080DDE6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080DDE72:
	strh r0, [r3]
	movs r0, #0
	strh r0, [r3, #2]
	movs r0, #0xff
	ldr r1, [sp, #0xc]
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r1, [sp, #0x3c]
	muls r0, r1, r0
	cmp r0, #0
	blt _080DDE92
	asrs r0, r0, #0xc
	b _080DDE98
_080DDE92:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080DDE98:
	strh r0, [r3, #4]
_080DDE9A:
	ldr r2, [sp, #0x40]
	cmp r2, #0
	bne _080DDEC0
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _080DDEB8 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r1, _080DDEBC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x20
	b _080DDED6
	.align 2, 0
_080DDEB8: .4byte 0x000003FF
_080DDEBC: .4byte 0x0203B400
_080DDEC0:
	mov r2, sb
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080DDEEC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _080DDEF0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x40]
_080DDED6:
	bl Mod
	strh r0, [r4, #0x2a]
	ldr r0, [sp, #0x44]
	cmp r0, #1
	beq _080DDF00
	cmp r0, #1
	bgt _080DDEF4
	cmp r0, #0
	beq _080DDF00
	b _080DDF1C
	.align 2, 0
_080DDEEC: .4byte 0x000003FF
_080DDEF0: .4byte 0x0203B400
_080DDEF4:
	ldr r1, [sp, #0x44]
	cmp r1, #2
	beq _080DDF0C
	cmp r1, #3
	beq _080DDF10
	b _080DDF1C
_080DDF00:
	movs r5, #0xf
	mov r0, r8
	movs r1, #1
	bl FUN_0822dadc
	b _080DDF26
_080DDF0C:
	movs r5, #0x10
	b _080DDF12
_080DDF10:
	movs r5, #0x11
_080DDF12:
	mov r0, r8
	movs r1, #0
	bl FUN_0822dadc
	b _080DDF26
_080DDF1C:
	movs r5, #0xf
	mov r0, r8
	movs r1, #0
	bl FUN_0822dadc
_080DDF26:
	ldr r2, [sp, #0x10]
	ldr r1, _080DDF84 @ =0x00000CD8
	adds r0, r2, r1
	ldr r1, [r0]
	adds r2, r5, #0
	movs r0, #0
	str r0, [sp]
	ldr r0, [sp, #0x18]
	movs r3, #0
	bl FUN_08236fac
	ldr r2, [sp, #0x10]
	movs r0, #0xce
	lsls r0, r0, #4
	adds r1, r2, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, [sp, #8]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #8]
	cmp r0, #0
	beq _080DDF72
_080DDF58:
	movs r1, #0x44
	add sl, r1
	adds r4, #0x44
	add r8, r1
	ldr r2, [sp, #0x18]
	adds r2, #0x44
	str r2, [sp, #0x18]
	ldr r0, [sp, #0x14]
	adds r0, #1
	str r0, [sp, #0x14]
	cmp r0, #0x2f
	bgt _080DDF72
	b _080DDD18
_080DDF72:
	movs r0, #1
_080DDF74:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DDF84: .4byte 0x00000CD8

