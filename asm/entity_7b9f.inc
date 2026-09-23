	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081d81c4
FUN_081d81c4: @ 0x081D81C4
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	movs r5, #0
	movs r0, #0xea
	lsls r0, r0, #2
	adds r6, r2, r0
	movs r7, #1
_081D81D2:
	adds r1, r7, #0
	lsls r1, r5
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D81E2
	movs r0, #1
	b _081D81E4
_081D81E2:
	movs r0, #0
_081D81E4:
	cmp r0, #0
	bne _081D821C
	movs r0, #0xdc
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x38
	adds r4, r2, r4
	adds r0, r4, #0
	movs r1, #0xdc
	bl ClearMemory
	adds r1, r7, #0
	lsls r1, r5
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	adds r0, r4, #0
	adds r0, #0xd0
	strh r5, [r0]
	adds r1, r4, #0
	adds r1, #0xd2
	ldr r0, _081D8218 @ =0x0000FFFF
	strh r0, [r1]
	adds r0, r4, #0
	b _081D8224
	.align 2, 0
_081D8218: .4byte 0x0000FFFF
_081D821C:
	adds r5, #1
	cmp r5, #3
	ble _081D81D2
	movs r0, #0
_081D8224:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d822c
FUN_081d822c: @ 0x081D822C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081D828C @ =0x030001A0
	ldr r2, [r0]
	cmp r2, #0
	beq _081D8286
	adds r1, r5, #0
	adds r1, #0xd8
	ldr r0, _081D8290 @ =FUN_081d8368
	str r0, [r1]
	adds r3, r5, #0
	adds r3, #0xd0
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r1, #0xea
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	movs r0, #1
	rsbs r0, r0, #0
	adds r6, r0, #0
	ldr r0, _081D8294 @ =0x0000FFFF
	strh r0, [r3]
	adds r0, r5, #0
	bl AuxSprite_Remove
	adds r4, r5, #0
	adds r4, #0xd2
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _081D8286
	adds r0, r5, #0
	adds r0, #0x8c
	bl ParticleShadow_Remove
	ldrh r0, [r4]
	orrs r0, r6
	strh r0, [r4]
_081D8286:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D828C: .4byte 0x030001A0
_081D8290: .4byte FUN_081d8368
_081D8294: .4byte 0x0000FFFF

	thumb_func_start FUN_081d8298
FUN_081d8298: @ 0x081D8298
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r2, r0, #0
	ldr r6, _081D8350 @ =0xFFFF0000
	ldr r5, [sp, #0xc]
	ands r5, r6
	ldr r0, _081D8354 @ =0x0000FFF4
	mov sl, r0
	orrs r5, r0
	str r5, [sp, #0xc]
	ldr r3, _081D8358 @ =0x0203B400
	mov sb, r3
	ldr r7, _081D835C @ =0x030046B8
	ldr r1, [r7]
	adds r1, #1
	ldr r0, _081D8360 @ =0x000003FF
	mov r8, r0
	ands r1, r0
	lsls r0, r1, #1
	add r0, sb
	ldrh r3, [r0]
	movs r7, #7
	mov ip, r7
	mov r0, ip
	ands r3, r0
	lsls r3, r3, #0x10
	ldr r4, _081D8364 @ =0x0000FFFF
	adds r0, r4, #0
	ands r0, r5
	orrs r0, r3
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r6
	mov r3, sl
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r3, [sp, #0x14]
	ands r3, r6
	movs r5, #0x18
	orrs r3, r5
	str r3, [sp, #0x14]
	adds r1, #1
	mov r7, r8
	ands r1, r7
	lsls r0, r1, #1
	add r0, sb
	ldrh r0, [r0]
	mov r7, ip
	ands r0, r7
	adds r0, #3
	lsls r0, r0, #0x10
	ands r4, r3
	orrs r4, r0
	str r4, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r6
	orrs r0, r5
	str r0, [r3, #4]
	adds r1, #1
	mov r0, r8
	ands r1, r0
	ldr r7, _081D835C @ =0x030046B8
	str r1, [r7]
	lsls r1, r1, #1
	add r1, sb
	ldrh r0, [r1]
	movs r1, #3
	ands r0, r1
	adds r0, #3
	adds r2, #0x1c
	str r3, [sp]
	movs r1, #0x3c
	str r1, [sp, #4]
	movs r1, #0x3f
	str r1, [sp, #8]
	movs r1, #2
	add r3, sp, #0xc
	bl FUN_08014730
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D8350: .4byte 0xFFFF0000
_081D8354: .4byte 0x0000FFF4
_081D8358: .4byte 0x0203B400
_081D835C: .4byte 0x030046B8
_081D8360: .4byte 0x000003FF
_081D8364: .4byte 0x0000FFFF

	thumb_func_start FUN_081d8368
FUN_081d8368: @ 0x081D8368
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d836c
FUN_081d836c: @ 0x081D836C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldrh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D839A
	cmp r1, #0
	blt _081D839A
	ldr r0, _081D83A0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D839A
	ldr r0, _081D83A4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D83A8
_081D839A:
	movs r0, #0
	b _081D83B6
	.align 2, 0
_081D83A0: .4byte 0x030046A8
_081D83A4: .4byte 0x030046AC
_081D83A8:
	ldr r0, _081D8424 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081D83B6:
	mov r8, r0
	adds r0, r6, #0
	adds r0, #0xd4
	ldrb r1, [r0]
	mov sb, r0
	adds r7, r6, #0
	adds r7, #0xd6
	adds r4, r6, #0
	adds r4, #0x2c
	cmp r1, #0
	beq _081D83F6
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r0, r6, #0
	adds r0, #0x8c
	bl ParticleShadow_Show
	movs r1, #0
	movs r0, #0
	strh r0, [r7]
	mov r2, sb
	strb r1, [r2]
	adds r0, r6, #0
	adds r0, #0xd5
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_08237098
_081D83F6:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D8428
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081D8430
	.align 2, 0
_081D8424: .4byte 0x030046A4
_081D8428:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D8430:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D8454
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081D845C
_081D8454:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D845C:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D8494 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D84CC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D8498
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D848C
	ldrb r0, [r4, #5]
_081D848C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D84A8
	.align 2, 0
_081D8494: .4byte 0x0000FFFF
_081D8498:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D84A8
	strh r1, [r4, #8]
_081D84A8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _081D84CC
	movs r0, #1
	strb r0, [r4, #7]
_081D84CC:
	ldrh r0, [r6, #0x1e]
	ldrh r1, [r7]
	subs r0, r0, r1
	strh r0, [r6, #0x1e]
	adds r4, r6, #0
	adds r4, #0x3c
	adds r5, r6, #0
	adds r5, #0x1c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	mov r0, r8
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D84FC
	adds r0, #4
	b _081D850A
_081D84FC:
	ldr r0, _081D8520 @ =0x030046A4
	ldr r1, [r0]
	mov r2, r8
	lsls r0, r2, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D850A:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081D8524
	cmp r3, #2
	beq _081D8528
	b _081D852C
	.align 2, 0
_081D8520: .4byte 0x030046A4
_081D8524:
	ldrb r0, [r5, #4]
	b _081D852A
_081D8528:
	ldrb r0, [r5]
_081D852A:
	subs r2, r2, r0
_081D852C:
	movs r1, #0x1e
	ldrsh r0, [r6, r1]
	cmp r0, r2
	bgt _081D854C
	adds r0, r6, #0
	adds r0, #0xd8
	ldr r1, _081D8548 @ =FUN_081d85a8
	str r1, [r0]
	strh r2, [r6, #0x1e]
	movs r0, #1
	mov r2, sb
	strb r0, [r2]
	b _081D8552
	.align 2, 0
_081D8548: .4byte FUN_081d85a8
_081D854C:
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
_081D8552:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d8560
FUN_081d8560: @ 0x081D8560
	push {r4, r5, lr}
	sub sp, #0x20
	adds r5, r0, #0
	movs r4, #0
_081D8568:
	movs r0, #0xc
	str r0, [sp]
	movs r0, #0x12
	str r0, [sp, #4]
	lsls r0, r4, #5
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r0, #0x40
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	movs r0, #0
	str r0, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x1c]
	adds r0, r5, #0
	adds r0, #0x1c
	movs r1, #8
	movs r2, #0x10
	movs r3, #4
	bl FUN_081ee584
	adds r4, #1
	cmp r4, #2
	ble _081D8568
	add sp, #0x20
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d85a8
FUN_081d85a8: @ 0x081D85A8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _081D8640 @ =0x030001A0
	ldr r2, [r0]
	cmp r2, #0
	bne _081D85B8
	b _081D8706
_081D85B8:
	adds r1, r5, #0
	adds r1, #0xd4
	ldrb r0, [r1]
	adds r6, r5, #0
	adds r6, #0x2c
	cmp r0, #0
	beq _081D85E6
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	ldr r1, [r2, #0x34]
	movs r0, #1
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #6
	movs r3, #1
	bl FUN_08236fac
	adds r0, r6, #0
	movs r1, #0x20
	bl FUN_08237098
_081D85E6:
	adds r4, r5, #0
	adds r4, #0xd6
	ldrh r0, [r4]
	lsls r0, r0, #3
	movs r1, #0xa
	bl Div
	strh r0, [r4]
	ldrh r1, [r5, #0x1e]
	adds r1, r1, r0
	strh r1, [r5, #0x1e]
	subs r4, #0x9a
	adds r1, r5, #0
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	adds r4, r6, #0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
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
	beq _081D8644
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D864C
	.align 2, 0
_081D8640: .4byte 0x030001A0
_081D8644:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D864C:
	str r0, [r5]
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
	beq _081D8670
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D8678
_081D8670:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D8678:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D86B0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D86E8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D86B4
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D86A8
	ldrb r0, [r4, #5]
_081D86A8:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D86C4
	.align 2, 0
_081D86B0: .4byte 0x0000FFFF
_081D86B4:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D86C4
	strh r1, [r4, #8]
_081D86C4:
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
	bne _081D86E8
	movs r0, #1
	strb r0, [r4, #7]
_081D86E8:
	ldrh r0, [r5, #0x34]
	cmp r0, #3
	bne _081D8706
	adds r0, r5, #0
	bl FUN_081d8298
	adds r0, r5, #0
	bl FUN_081d8560
	adds r0, r5, #0
	bl FUN_081d822c
	ldr r0, _081D8710 @ =0x000001E1
	bl PlaySound_082406e0
_081D8706:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D8710: .4byte 0x000001E1

	thumb_func_start FUN_081d8714
FUN_081d8714: @ 0x081D8714
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, _081D8768 @ =0x030001A0
	ldr r5, [r0]
	cmp r5, #0
	beq _081D8760
	adds r4, r5, #0
	adds r4, #0x18
	ldr r1, _081D876C @ =0x00005290
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r0, _081D8770 @ =0x0000922E
	ldr r1, _081D8774 @ =0x00001E38
	bl GetFile
	adds r1, r0, #0
	str r1, [r5, #0x34]
	adds r0, r6, #0
	adds r0, #0x2c
	movs r2, #1
	str r2, [sp]
	movs r2, #8
	movs r3, #1
	bl FUN_08236fac
	ldr r0, _081D8778 @ =0x00000201
	adds r1, r7, r0
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
_081D8760:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D8768: .4byte 0x030001A0
_081D876C: .4byte 0x00005290
_081D8770: .4byte 0x0000922E
_081D8774: .4byte 0x00001E38
_081D8778: .4byte 0x00000201

	thumb_func_start Entity7B9F_Update
Entity7B9F_Update: @ 0x081D877C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r4, #0
	movs r0, #0xea
	lsls r0, r0, #2
	adds r6, r5, r0
_081D8788:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D8798
	movs r0, #1
	b _081D879A
_081D8798:
	movs r0, #0
_081D879A:
	cmp r0, #0
	beq _081D87B4
	movs r0, #0xdc
	muls r0, r4, r0
	movs r2, #0x88
	lsls r2, r2, #1
	adds r1, r5, r2
	adds r1, r1, r0
	adds r0, #0x38
	adds r0, r5, r0
	ldr r1, [r1]
	bl _call_via_r1
_081D87B4:
	adds r4, #1
	cmp r4, #3
	ble _081D8788
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity7B9F_Destroy
Entity7B9F_Destroy: @ 0x081D87C4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	movs r6, #0
	movs r7, #0xea
	lsls r7, r7, #2
	add r7, r8
	movs r0, #1
	rsbs r0, r0, #0
	mov sl, r0
	movs r1, #1
	mov sb, r1
_081D87E2:
	mov r1, sb
	lsls r1, r6
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081D87F2
	movs r0, #1
	b _081D87F4
_081D87F2:
	movs r0, #0
_081D87F4:
	cmp r0, #0
	beq _081D882A
	movs r0, #0xdc
	muls r0, r6, r0
	adds r0, #0x38
	mov r1, r8
	adds r4, r1, r0
	mov r1, sb
	lsls r1, r6
	ldr r0, [r7]
	bics r0, r1
	str r0, [r7]
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r5, r4, #0
	adds r5, #0xd2
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, sl
	beq _081D882A
	adds r0, r4, #0
	adds r0, #0x8c
	bl ParticleShadow_Remove
	ldr r0, _081D8844 @ =0x0000FFFF
	strh r0, [r5]
_081D882A:
	adds r6, #1
	cmp r6, #3
	ble _081D87E2
	ldr r1, _081D8848 @ =0x030001A0
	movs r0, #0
	str r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D8844: .4byte 0x0000FFFF
_081D8848: .4byte 0x030001A0

	thumb_func_start Entity7B9F_Init
Entity7B9F_Init: @ 0x081D884C
	ldr r1, _081D8854 @ =0x030001A0
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_081D8854: .4byte 0x030001A0

	thumb_func_start Entity7B9F_Create
Entity7B9F_Create: @ 0x081D8858
	push {r4, lr}
	ldr r0, _081D8890 @ =0x030001A0
	ldr r0, [r0]
	cmp r0, #0
	bne _081D889E
	movs r1, #0xeb
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D889C
	ldr r1, _081D8894 @ =Entity7B9F_Update
	ldr r2, _081D8898 @ =Entity7B9F_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity7B9F_Init
	cmp r0, #0
	bge _081D889C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D889E
	.align 2, 0
_081D8890: .4byte 0x030001A0
_081D8894: .4byte Entity7B9F_Update
_081D8898: .4byte Entity7B9F_Destroy
_081D889C:
	adds r0, r4, #0
_081D889E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d88a4
FUN_081d88a4: @ 0x081D88A4
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d88a8
FUN_081d88a8: @ 0x081D88A8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r7, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r4, r7, #0
	adds r4, #0x3c
	ldr r2, _081D8934 @ =0xFFFF0000
	ldr r1, _081D8938 @ =0x0000FFFF
	movs r0, #0xc8
	lsls r0, r0, #0xe
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r3, #0x54
	orrs r0, r3
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r1, #4]
	adds r0, r7, #0
	adds r0, #0xcc
	ldrh r0, [r0]
	strh r0, [r4, #4]
	ldr r2, _081D893C @ =0x00002001
	movs r0, #0x20
	str r0, [sp]
	str r1, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	movs r3, #0x80
	lsls r3, r3, #6
	ldr r0, _081D8940 @ =0x00440008
	str r0, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Hitbox_SetAttack
	adds r1, r7, #0
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _081D8944 @ =FUN_081d88a4
	adds r0, r4, #0
	adds r2, r7, #0
	bl Hitbox_SetHandler
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D8934: .4byte 0xFFFF0000
_081D8938: .4byte 0x0000FFFF
_081D893C: .4byte 0x00002001
_081D8940: .4byte 0x00440008
_081D8944: .4byte FUN_081d88a4

	thumb_func_start FUN_081d8948
FUN_081d8948: @ 0x081D8948
	push {r4, r5, r6, r7, lr}
	ldr r0, _081D89AC @ =0x030001A0
	ldr r0, [r0]
	cmp r0, #0
	bne _081D895A
	bl Entity7B9F_Create
	cmp r0, #0
	beq _081D89EC
_081D895A:
	bl FUN_081d81c4
	adds r5, r0, #0
	cmp r5, #0
	beq _081D89EC
	movs r1, #2
	bl FUN_081d8714
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D8986
	bl Script_GetValue
	strh r0, [r5, #0x1c]
	bl Script_GetValue
	strh r0, [r5, #0x1e]
	bl Script_GetValue
	strh r0, [r5, #0x20]
_081D8986:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0xcc
	strh r0, [r1]
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D89B0
	bl Script_GetValue
	adds r7, r0, #0
	bl Script_GetValue
	adds r6, r0, #0
	b _081D89B4
	.align 2, 0
_081D89AC: .4byte 0x030001A0
_081D89B0:
	movs r7, #0x64
	movs r6, #0x64
_081D89B4:
	adds r1, r5, #0
	adds r1, #0xd4
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xd5
	strb r2, [r0]
	adds r1, #4
	ldr r0, _081D89F4 @ =FUN_081d836c
	str r0, [r1]
	adds r4, r5, #0
	adds r4, #0x8c
	subs r1, #0xbc
	adds r0, r4, #0
	bl ParticleShadow_Init
	adds r1, r5, #0
	adds r1, #0xd2
	strh r0, [r1]
	adds r0, r4, #0
	bl ParticleShadow_Hide
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl FUN_081d88a8
_081D89EC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D89F4: .4byte FUN_081d836c

	thumb_func_start FUN_081d89f8
FUN_081d89f8: @ 0x081D89F8
	ldr r1, _081D8A00 @ =0x030001A0
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081D8A00: .4byte 0x030001A0
