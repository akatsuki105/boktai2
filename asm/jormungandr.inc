	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080c5058
FUN_080c5058: @ 0x080C5058
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r1, [sp, #0x3c]
	mov sl, r6
	movs r0, #0x95
	adds r0, r0, r6
	mov r8, r0
	movs r0, #0
	mov sb, r0
	mov r0, r8
	strb r3, [r0]
	adds r7, r6, #0
	adds r7, #0x96
	strb r2, [r7]
	adds r0, r6, #0
	adds r0, #0x94
	strb r1, [r0]
	add r5, sp, #0x10
	mov r0, sb
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	adds r1, r5, #0
	ldr r2, _080C50C4 @ =0x05000002
	bl CpuSet
	cmp r4, #0
	bne _080C50D0
	ldr r1, _080C50C8 @ =0x00008203
	ldr r2, _080C50CC @ =0x00005C4D
	str r5, [sp]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_08055dac
	ldrb r1, [r7]
	mov r0, r8
	ldrb r2, [r0]
	movs r0, #1
	str r0, [sp]
	mov r0, sb
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_08055b5c
	b _080C50F6
	.align 2, 0
_080C50C4: .4byte 0x05000002
_080C50C8: .4byte 0x00008203
_080C50CC: .4byte 0x00005C4D
_080C50D0:
	ldr r1, _080C5120 @ =0x00009524
	adds r0, r6, #0
	movs r2, #0
	adds r3, r5, #0
	bl FUN_08055e34
	ldrb r1, [r7]
	mov r0, r8
	ldrb r2, [r0]
	movs r0, #1
	str r0, [sp]
	mov r0, sb
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_08055b5c
_080C50F6:
	mov r0, sl
	ldr r1, [sp, #0x38]
	bl FUN_08055f5c
	adds r0, r6, #0
	adds r0, #0x94
	ldrb r0, [r0]
	cmp r0, #0
	bne _080C5110
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08055ef8
_080C5110:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C5120: .4byte 0x00009524

	thumb_func_start FUN_080c5124
FUN_080c5124: @ 0x080C5124
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, _080C5154 @ =0x000025BD
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	ldr r0, _080C5158 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _080C515C @ =0x00002AA0
	adds r0, r0, r1
	ldr r2, _080C5160 @ =0x0000259C
	adds r1, r6, r2
	ldr r2, _080C5164 @ =0x04000008
	bl CpuSet
	movs r5, #0
_080C5146:
	cmp r5, #4
	bhi _080C51A2
	lsls r0, r5, #2
	ldr r1, _080C5168 @ =_080C516C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080C5154: .4byte 0x000025BD
_080C5158: .4byte 0x03003584
_080C515C: .4byte 0x00002AA0
_080C5160: .4byte 0x0000259C
_080C5164: .4byte 0x04000008
_080C5168: .4byte _080C516C
_080C516C: @ jump table
	.4byte _080C5180 @ case 0
	.4byte _080C5186 @ case 1
	.4byte _080C5190 @ case 2
	.4byte _080C519A @ case 3
	.4byte _080C51A2 @ case 4
_080C5180:
	movs r7, #1
	movs r2, #0
	b _080C518A
_080C5186:
	movs r7, #1
	movs r2, #0x18
_080C518A:
	movs r3, #0
	movs r1, #1
	b _080C51AA
_080C5190:
	movs r7, #0
	movs r2, #0
	movs r3, #0
	movs r1, #2
	b _080C51AA
_080C519A:
	movs r7, #0
	movs r2, #0
	movs r3, #0
	b _080C51A8
_080C51A2:
	movs r7, #0
	movs r2, #0
	movs r3, #1
_080C51A8:
	movs r1, #3
_080C51AA:
	movs r0, #0x98
	adds r4, r5, #0
	muls r4, r0, r4
	movs r0, #0xc0
	lsls r0, r0, #2
	adds r0, r0, r4
	mov ip, r0
	add ip, r6
	str r1, [sp]
	movs r1, #1
	str r1, [sp, #4]
	mov r0, ip
	adds r1, r7, #0
	bl FUN_080c5058
	cmp r7, #0
	bne _080C51D2
	movs r1, #0xc6
	lsls r1, r1, #2
	b _080C51D6
_080C51D2:
	movs r1, #0xdd
	lsls r1, r1, #2
_080C51D6:
	adds r0, r6, r1
	adds r0, r0, r4
	ldr r2, _080C5224 @ =0x0000259C
	adds r1, r6, r2
	str r1, [r0]
	adds r5, #1
	cmp r5, #4
	ble _080C5146
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r5, #2
	str r5, [sp]
	movs r4, #0
	str r4, [sp, #4]
	movs r1, #1
	movs r2, #0x2a
	movs r3, #0
	bl FUN_080c5058
	movs r2, #0xbf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r5, [sp]
	str r4, [sp, #4]
	movs r1, #1
	movs r2, #0x2e
	movs r3, #0
	bl FUN_080c5058
	movs r5, #0
_080C5214:
	cmp r5, #1
	beq _080C5232
	cmp r5, #1
	bgt _080C5228
	cmp r5, #0
	beq _080C522E
	b _080C523A
	.align 2, 0
_080C5224: .4byte 0x0000259C
_080C5228:
	cmp r5, #2
	beq _080C5236
	b _080C523A
_080C522E:
	movs r2, #0x21
	b _080C523C
_080C5232:
	movs r2, #0x1e
	b _080C523C
_080C5236:
	movs r2, #0x1b
	b _080C523C
_080C523A:
	movs r2, #0
_080C523C:
	movs r0, #0x98
	adds r4, r5, #0
	muls r4, r0, r4
	movs r1, #0xe5
	lsls r1, r1, #3
	adds r0, r4, r1
	adds r0, r6, r0
	movs r1, #2
	str r1, [sp]
	movs r1, #1
	str r1, [sp, #4]
	movs r3, #0
	bl FUN_080c5058
	ldr r2, _080C52D0 @ =0x0000079C
	adds r0, r6, r2
	adds r0, r0, r4
	ldr r2, _080C52D4 @ =0x0000259C
	adds r1, r6, r2
	str r1, [r0]
	adds r5, #1
	cmp r5, #2
	ble _080C5214
	movs r0, #0xbe
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #0xa0
	lsls r0, r0, #3
	strh r0, [r2]
	ldr r0, _080C52D8 @ =0x000002FA
	adds r1, r6, r0
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0xbf
	lsls r0, r0, #2
	adds r1, r6, r0
	subs r0, #0xfc
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r3, r6, r1
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r2, _080C52DC @ =0x000002EA
	adds r1, r6, r2
	subs r2, #0x6a
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r6, r0
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C52D0: .4byte 0x0000079C
_080C52D4: .4byte 0x0000259C
_080C52D8: .4byte 0x000002FA
_080C52DC: .4byte 0x000002EA

	thumb_func_start FUN_080c52e0
FUN_080c52e0: @ 0x080C52E0
	ldr r3, _080C52EC @ =0x000004BC
	adds r2, r0, r3
	str r1, [r2]
	movs r1, #0
	strh r1, [r0, #4]
	bx lr
	.align 2, 0
_080C52EC: .4byte 0x000004BC

	thumb_func_start FUN_080c52f0
FUN_080c52f0: @ 0x080C52F0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	ldrh r0, [r5, #4]
	cmp r0, #0
	bne _080C5308
	movs r0, #0x8b
	lsls r0, r0, #2
	bl PlaySound_082406e0
_080C5308:
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080C53B0
	movs r0, #0xff
	mov r8, r0
	movs r1, #0x97
	lsls r1, r1, #3
	adds r6, r5, r1
	ldr r2, _080C5358 @ =0x085B0A08
	mov sb, r2
	adds r4, r5, #0
	adds r4, #0x50
	movs r0, #0
	mov ip, r0
	adds r3, r5, #0
	adds r3, #8
	movs r7, #0xd
_080C5332:
	ldrh r0, [r5, #4]
	lsls r0, r0, #4
	mov r1, ip
	adds r2, r0, r1
	mov r0, r8
	ands r2, r0
	ldr r0, [r3]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
	ldrb r0, [r5, #2]
	cmp r0, #0
	bne _080C535C
	ldr r1, [r6]
	ldrh r0, [r4]
	ldrh r1, [r1]
	adds r0, r0, r1
	b _080C5364
	.align 2, 0
_080C5358: .4byte 0x085B0A08
_080C535C:
	ldr r0, [r6]
	ldrh r0, [r0]
	ldrh r1, [r4]
	subs r0, r0, r1
_080C5364:
	strh r0, [r3, #0x1c]
	ldrb r0, [r4, #4]
	mov r1, r8
	ands r2, r1
	lsls r1, r2, #1
	add r1, sb
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080C537E
	asrs r1, r0, #0xc
	b _080C5384
_080C537E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C5384:
	ldr r0, [r6]
	ldrh r0, [r0, #4]
	adds r0, r0, r1
	strh r0, [r3, #0x20]
	adds r4, #0x50
	movs r0, #0xc
	add ip, r0
	adds r3, #0x50
	subs r7, #1
	cmp r7, #0
	bge _080C5332
	ldrh r0, [r5, #4]
	cmp r0, #0x27
	bls _080C544C
	ldr r1, _080C53AC @ =FUN_080c5458
	adds r0, r5, #0
	bl FUN_080c52e0
	b _080C544C
	.align 2, 0
_080C53AC: .4byte FUN_080c5458
_080C53B0:
	ldrh r0, [r5, #4]
	movs r1, #0x16
	muls r0, r1, r0
	adds r0, #0x60
	mov r8, r0
	movs r1, #0x97
	lsls r1, r1, #3
	adds r6, r5, r1
	ldr r2, _080C53F8 @ =0x085B0A08
	mov sb, r2
	movs r0, #0
	mov ip, r0
	adds r4, r5, #0
	adds r4, #0x50
	adds r3, r5, #0
	adds r3, #8
	movs r7, #0xd
_080C53D2:
	ldrh r0, [r4]
	ldr r1, _080C53FC @ =0xFFFFFD44
	adds r0, r0, r1
	mov r1, r8
	adds r2, r1, r0
	cmp r2, #0x5f
	ble _080C5436
	ldr r0, [r3]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
	ldrb r0, [r5, #2]
	cmp r0, #0
	bne _080C5400
	ldr r0, [r6]
	ldrh r0, [r0]
	adds r0, r0, r2
	b _080C5406
	.align 2, 0
_080C53F8: .4byte 0x085B0A08
_080C53FC: .4byte 0xFFFFFD44
_080C5400:
	ldr r0, [r6]
	ldrh r0, [r0]
	subs r0, r0, r2
_080C5406:
	strh r0, [r3, #0x1c]
	ldrh r0, [r5, #4]
	lsls r0, r0, #4
	add r0, ip
	ldrb r2, [r4, #4]
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080C5426
	asrs r2, r0, #0xc
	b _080C542C
_080C5426:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C542C:
	ldr r0, [r6]
	ldrh r0, [r0, #4]
	adds r0, r0, r2
	strh r0, [r3, #0x20]
	b _080C543E
_080C5436:
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
_080C543E:
	movs r2, #0xc
	add ip, r2
	adds r4, #0x50
	adds r3, #0x50
	subs r7, #1
	cmp r7, #0
	bge _080C53D2
_080C544C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c5458
FUN_080c5458: @ 0x080C5458
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	ldrh r0, [r6, #4]
	cmp r0, #0
	bne _080C5472
	ldr r0, _080C5494 @ =0x0000022D
	bl PlaySound_082406e0
_080C5472:
	movs r0, #0
	str r0, [sp, #4]
	ldrh r2, [r6, #4]
	adds r0, r2, #0
	subs r0, #0x1c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x29
	bhi _080C54AA
	ldrb r0, [r6, #2]
	cmp r0, #0
	bne _080C5498
	movs r1, #0
	str r1, [sp]
	cmp r2, #0x23
	bls _080C54CC
	b _080C54C6
	.align 2, 0
_080C5494: .4byte 0x0000022D
_080C5498:
	movs r3, #1
	str r3, [sp]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x23
	bls _080C54CC
	ldrb r0, [r6, #3]
	adds r0, #4
	b _080C54CA
_080C54AA:
	ldrb r0, [r6, #2]
	cmp r0, #0
	bne _080C54BE
	movs r4, #1
	str r4, [sp]
	cmp r1, #0x31
	bls _080C54CC
	ldrb r0, [r6, #3]
	adds r0, #4
	b _080C54CA
_080C54BE:
	movs r5, #0
	str r5, [sp]
	cmp r1, #0x31
	bls _080C54CC
_080C54C6:
	ldrb r0, [r6, #3]
	adds r0, #0xfc
_080C54CA:
	strb r0, [r6, #3]
_080C54CC:
	movs r0, #0xff
	mov sl, r0
	adds r5, r6, #0
	adds r5, #0x24
	adds r7, r6, #0
	adds r7, #0x50
	movs r1, #8
	adds r1, r1, r6
	mov r8, r1
	movs r2, #0xd
	mov sb, r2
_080C54E2:
	ldr r3, [sp]
	cmp r3, #0
	beq _080C54FA
	movs r4, #0x32
	ldrsh r0, [r5, r4]
	lsls r1, r0, #1
	adds r1, r1, r0
	ldrb r0, [r7, #2]
	subs r0, r1, r0
	cmp r0, #0
	bge _080C550A
	b _080C550E
_080C54FA:
	movs r0, #0x32
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldrb r1, [r7, #2]
	adds r0, r0, r1
	cmp r0, #0
	blt _080C550E
_080C550A:
	asrs r0, r0, #2
	b _080C5514
_080C550E:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080C5514:
	strh r0, [r5, #0x32]
	mov r0, r8
	adds r0, #0x4e
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r0, r3
	ldrb r4, [r6, #3]
	adds r3, r0, r4
	mov r0, sl
	ands r3, r0
	ldrh r2, [r5, #0x2c]
	ldr r1, _080C5550 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	mov r4, sl
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r2, r0
	adds r4, r7, #0
	mov ip, r1
	cmp r0, #0
	blt _080C5554
	asrs r2, r0, #0xc
	b _080C555A
	.align 2, 0
_080C5550: .4byte 0x085B0A08
_080C5554:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C555A:
	movs r1, #0x97
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	ldrh r0, [r0]
	adds r0, r0, r2
	strh r0, [r5]
	ldrh r1, [r4]
	mov r2, sl
	ands r3, r2
	lsls r0, r3, #1
	add r0, ip
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080C5580
	asrs r1, r0, #0xc
	b _080C5586
_080C5580:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C5586:
	movs r4, #0x97
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	adds r0, r0, r1
	strh r0, [r5, #4]
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _080C55E0
	ldr r0, _080C5640 @ =0x03002BE0
	ldr r2, [r0]
	movs r3, #0x2c
	ldrsh r1, [r2, r3]
	movs r4, #0
	ldrsh r0, [r5, r4]
	subs r1, r1, r0
	cmp r1, #0
	bge _080C55AE
	rsbs r1, r1, #0
_080C55AE:
	cmp r1, #0x5f
	bgt _080C55E0
	movs r0, #0x30
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _080C55C2
	rsbs r0, r0, #0
_080C55C2:
	cmp r0, #0x5f
	bgt _080C55E0
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r6, r3
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	movs r4, #1
	str r4, [sp, #4]
_080C55E0:
	adds r5, #0x50
	adds r7, #0x50
	movs r0, #0x50
	add r8, r0
	movs r1, #1
	rsbs r1, r1, #0
	add sb, r1
	mov r2, sb
	cmp r2, #0
	blt _080C55F6
	b _080C54E2
_080C55F6:
	ldrh r0, [r6, #4]
	adds r0, #1
	strh r0, [r6, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x51
	bls _080C5664
	movs r4, #0
	ldrb r0, [r6, #6]
	cmp r0, #0
	bne _080C5652
	ldr r0, _080C5640 @ =0x03002BE0
	ldr r3, [r0]
	movs r5, #0x30
	ldrsh r1, [r3, r5]
	movs r2, #0x97
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r2, [r0]
	movs r5, #4
	ldrsh r0, [r2, r5]
	movs r5, #0xc0
	lsls r5, r5, #2
	adds r0, r0, r5
	cmp r1, r0
	bge _080C5652
	ldrb r0, [r6, #2]
	cmp r0, #0
	bne _080C5644
	movs r0, #0x2c
	ldrsh r1, [r3, r0]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	ble _080C5652
	b _080C5656
	.align 2, 0
_080C5640: .4byte 0x03002BE0
_080C5644:
	movs r5, #0x2c
	ldrsh r1, [r3, r5]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bge _080C5652
	movs r4, #1
_080C5652:
	cmp r4, #0
	beq _080C565C
_080C5656:
	movs r0, #0
	strh r0, [r6, #4]
	b _080C5664
_080C565C:
	ldr r1, _080C5674 @ =FUN_080c5678
	adds r0, r6, #0
	bl FUN_080c52e0
_080C5664:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C5674: .4byte FUN_080c5678

	thumb_func_start FUN_080c5678
FUN_080c5678: @ 0x080C5678
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	ldrh r0, [r5, #4]
	cmp r0, #0
	bne _080C5694
	movs r0, #0x8b
	lsls r0, r0, #2
	bl PlaySound_082406e0
_080C5694:
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	str r1, [sp, #8]
	ldrh r0, [r5, #4]
	movs r1, #0x20
	subs r1, r1, r0
	movs r2, #0x16
	muls r1, r2, r1
	adds r1, #0x60
	str r1, [sp, #4]
	adds r0, #1
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080C56D2
	movs r2, #1
	adds r1, r5, #0
	adds r1, #8
	movs r7, #0xd
_080C56BE:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x50
	subs r7, #1
	cmp r7, #0
	bge _080C56BE
	movs r0, #0
	strb r0, [r5, #1]
	b _080C5818
_080C56D2:
	movs r2, #0xff
	mov sb, r2
	movs r4, #0x97
	lsls r4, r4, #3
	adds r4, r4, r5
	mov sl, r4
	movs r6, #0x56
	adds r6, r6, r5
	mov ip, r6
	adds r0, r5, #0
	adds r0, #0x52
	str r0, [sp, #0x14]
	movs r1, #0x50
	adds r1, r1, r5
	mov r8, r1
	adds r3, r5, #0
	adds r3, #8
	movs r7, #0xd
_080C56F6:
	mov r2, r8
	ldrh r0, [r2]
	ldr r4, _080C5734 @ =0xFFFFFD44
	adds r0, r0, r4
	ldr r6, [sp, #4]
	adds r0, r6, r0
	str r0, [sp, #0x18]
	cmp r0, #0x5f
	ble _080C57FA
	ldr r0, [r3]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
	ldrh r0, [r5, #4]
	lsrs r0, r0, #3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080C5738
	mov r1, ip
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r1, r0, #1
	adds r1, r1, r0
	ldr r4, [sp, #0x14]
	ldrb r0, [r4]
	subs r0, r1, r0
	cmp r0, #0
	bge _080C574C
	b _080C5750
	.align 2, 0
_080C5734: .4byte 0xFFFFFD44
_080C5738:
	mov r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldr r4, [sp, #0x14]
	ldrb r4, [r4]
	adds r0, r0, r4
	cmp r0, #0
	blt _080C5750
_080C574C:
	asrs r0, r0, #2
	b _080C5756
_080C5750:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_080C5756:
	mov r6, ip
	strh r0, [r6]
	adds r0, r3, #0
	adds r0, #0x4e
	ldr r1, [sp]
	cmp r1, #0
	bne _080C5772
	movs r4, #0
	ldrsh r2, [r0, r4]
	str r2, [sp, #8]
	movs r2, #0
	movs r6, #1
	str r6, [sp]
	b _080C5782
_080C5772:
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r4, [sp, #8]
	ldr r6, _080C57AC @ =0xFFFFFF00
	adds r0, r4, r6
	subs r2, r1, r0
	mov r0, sb
	ands r2, r0
_080C5782:
	ldrb r1, [r5, #3]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r0, r2, r0
	adds r2, r1, r0
	mov r1, sb
	ands r2, r1
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	ldr r4, _080C57B0 @ =0x085B0A08
	adds r0, r0, r4
	movs r6, #0
	ldrsh r0, [r0, r6]
	ldr r1, [sp, #0x18]
	muls r0, r1, r0
	cmp r0, #0
	blt _080C57B4
	asrs r1, r0, #0xc
	b _080C57BA
	.align 2, 0
_080C57AC: .4byte 0xFFFFFF00
_080C57B0: .4byte 0x085B0A08
_080C57B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C57BA:
	mov r4, sl
	ldr r4, [r4]
	ldrh r6, [r4]
	mov r4, sp
	strh r6, [r4, #0x10]
	adds r1, r6, r1
	strh r1, [r3, #0x1c]
	mov r0, sb
	ands r2, r0
	lsls r0, r2, #1
	ldr r1, _080C57E4 @ =0x085B0A08
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r4, [sp, #0x18]
	muls r0, r4, r0
	cmp r0, #0
	blt _080C57E8
	asrs r1, r0, #0xc
	b _080C57EE
	.align 2, 0
_080C57E4: .4byte 0x085B0A08
_080C57E8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080C57EE:
	mov r6, sl
	ldr r0, [r6]
	ldrh r0, [r0, #4]
	adds r0, r0, r1
	strh r0, [r3, #0x20]
	b _080C5802
_080C57FA:
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
_080C5802:
	movs r0, #0x50
	add ip, r0
	ldr r1, [sp, #0x14]
	adds r1, #0x50
	str r1, [sp, #0x14]
	add r8, r0
	adds r3, #0x50
	subs r7, #1
	cmp r7, #0
	blt _080C5818
	b _080C56F6
_080C5818:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c5828
FUN_080c5828: @ 0x080C5828
	push {lr}
	adds r2, r0, #0
	ldr r1, _080C5848 @ =0x000008F9
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C5844
	ldr r3, _080C584C @ =0x00000DB4
	adds r1, r2, r3
	ldr r3, _080C5850 @ =0x000008F8
	adds r0, r2, r3
	ldr r1, [r1]
	bl _call_via_r1
_080C5844:
	pop {r0}
	bx r0
	.align 2, 0
_080C5848: .4byte 0x000008F9
_080C584C: .4byte 0x00000DB4
_080C5850: .4byte 0x000008F8

	thumb_func_start FUN_080c5854
FUN_080c5854: @ 0x080C5854
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	ldr r1, _080C5888 @ =0x000008F9
	adds r0, r4, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _080C5906
	ldr r0, _080C588C @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0xbe
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r5, #0x2c
	ldrsh r2, [r0, r5]
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r2, r0
	blt _080C5894
	ldr r1, _080C5890 @ =0x000008FA
	adds r0, r4, r1
	strb r3, [r0]
	b _080C589C
	.align 2, 0
_080C5888: .4byte 0x000008F9
_080C588C: .4byte 0x03002BE0
_080C5890: .4byte 0x000008FA
_080C5894:
	ldr r2, _080C5914 @ =0x000008FA
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
_080C589C:
	ldr r5, _080C5918 @ =0x000008F9
	adds r0, r4, r5
	movs r2, #1
	strb r2, [r0]
	ldr r7, _080C5914 @ =0x000008FA
	adds r3, r4, r7
	ldrb r0, [r3]
	lsls r0, r0, #7
	adds r5, #2
	adds r1, r4, r5
	strb r0, [r1]
	ldrb r0, [r3]
	subs r2, r2, r0
	lsls r2, r2, #1
	mov ip, r2
	ldr r7, _080C591C @ =FUN_080c52f0
	mov sb, r7
	movs r0, #0x90
	lsls r0, r0, #4
	adds r2, r4, r0
	adds r3, r4, #0
	movs r6, #0
	mov sl, r2
	movs r1, #2
	rsbs r1, r1, #0
	mov r8, r1
	movs r5, #0xd
_080C58D2:
	mov r7, sl
	adds r1, r7, r6
	ldr r0, [r1]
	mov r7, r8
	ands r0, r7
	str r0, [r1]
	ldr r0, _080C5920 @ =0x0000094E
	adds r1, r3, r0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _080C5924 @ =0x0000094B
	adds r0, r3, r1
	ldrb r0, [r0]
	add r0, ip
	strh r0, [r2, #0x10]
	adds r2, #0x50
	adds r3, #0x50
	adds r6, #0x50
	subs r5, #1
	cmp r5, #0
	bge _080C58D2
	ldr r2, _080C5928 @ =0x000008F8
	adds r0, r4, r2
	mov r1, sb
	bl FUN_080c52e0
_080C5906:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C5914: .4byte 0x000008FA
_080C5918: .4byte 0x000008F9
_080C591C: .4byte FUN_080c52f0
_080C5920: .4byte 0x0000094E
_080C5924: .4byte 0x0000094B
_080C5928: .4byte 0x000008F8

	thumb_func_start FUN_080c592c
FUN_080c592c: @ 0x080C592C
	push {r4, r5, lr}
	adds r1, r0, #0
	ldr r2, _080C5958 @ =0x000008F8
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C5950
	movs r0, #0x90
	lsls r0, r0, #4
	adds r4, r1, r0
	movs r5, #0xd
_080C5942:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _080C5942
_080C5950:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C5958: .4byte 0x000008F8

	thumb_func_start FUN_080c595c
FUN_080c595c: @ 0x080C595C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r4, r1, #0
	mov r8, r2
	mov sb, r3
	ldr r7, [sp, #0x38]
	ldr r2, _080C59E8 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r5, #0x40
	orrs r0, r5
	ldr r1, _080C59EC @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r5
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	adds r0, r6, #0
	adds r0, #0x48
	ldrh r1, [r0]
	ldr r2, _080C59F0 @ =0x00002101
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0x80
	lsls r0, r0, #0xb
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0
	bl FUN_082364f8
	adds r0, r4, #0
	adds r0, #0x42
	strb r5, [r0]
	adds r0, r4, #0
	movs r1, #0
	adds r2, r6, #0
	bl FUN_0823651c
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C59E8: .4byte 0xFFFF0000
_080C59EC: .4byte 0x0000FFFF
_080C59F0: .4byte 0x00002101

	thumb_func_start FUN_080c59f4
FUN_080c59f4: @ 0x080C59F4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sl, r0
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	ldr r0, _080C5A44 @ =0x000008F8
	add r0, sl
	mov sb, r0
	movs r1, #0
	movs r0, #1
	mov r2, sb
	strb r0, [r2]
	strb r1, [r2, #2]
	strb r1, [r2, #3]
	strb r1, [r2, #1]
	movs r1, #0xdb
	lsls r1, r1, #4
	add r1, sl
	movs r0, #0xbe
	lsls r0, r0, #2
	add r0, sl
	str r0, [r1]
	ldr r1, _080C5A48 @ =FUN_080c52f0
	mov r0, sb
	bl FUN_080c52e0
	movs r7, #0x60
	movs r3, #0
_080C5A36:
	cmp r3, #0xa
	bhi _080C5AAC
	lsls r0, r3, #2
	ldr r1, _080C5A4C @ =_080C5A50
	adds r1, r0, r1
	ldr r1, [r1]
	mov pc, r1
	.align 2, 0
_080C5A44: .4byte 0x000008F8
_080C5A48: .4byte FUN_080c52f0
_080C5A4C: .4byte _080C5A50
_080C5A50: @ jump table
	.4byte _080C5A7C @ case 0
	.4byte _080C5A7C @ case 1
	.4byte _080C5A7C @ case 2
	.4byte _080C5A7C @ case 3
	.4byte _080C5A8C @ case 4
	.4byte _080C5A8C @ case 5
	.4byte _080C5A8C @ case 6
	.4byte _080C5A8C @ case 7
	.4byte _080C5A9C @ case 8
	.4byte _080C5A9C @ case 9
	.4byte _080C5A9C @ case 10
_080C5A7C:
	ldr r2, _080C5A88 @ =0x00008206
	movs r4, #2
	mov r8, r4
	adds r7, #0x50
	movs r1, #0x20
	b _080C5AB8
	.align 2, 0
_080C5A88: .4byte 0x00008206
_080C5A8C:
	ldr r2, _080C5A98 @ =0x00008206
	movs r1, #3
	mov r8, r1
	adds r7, #0x40
	movs r1, #0x28
	b _080C5AB8
	.align 2, 0
_080C5A98: .4byte 0x00008206
_080C5A9C:
	ldr r2, _080C5AA8 @ =0x00008207
	movs r4, #2
	mov r8, r4
	adds r7, #0x20
	movs r1, #0x30
	b _080C5AB8
	.align 2, 0
_080C5AA8: .4byte 0x00008207
_080C5AAC:
	ldr r2, _080C5B60 @ =0x00008207
	movs r0, #3
	mov r8, r0
	adds r7, #0x14
	movs r1, #0x38
	lsls r0, r3, #2
_080C5AB8:
	adds r0, r0, r3
	lsls r0, r0, #4
	adds r0, #8
	mov r4, sb
	adds r6, r4, r0
	adds r5, r6, #0
	adds r5, #0x48
	strh r7, [r5]
	adds r0, r6, #0
	adds r0, #0x4b
	mov r4, r8
	strb r4, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _080C5B64 @ =0x085AD0DE
	lsls r0, r3, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0x4a
	strb r0, [r1]
	ldrb r0, [r1]
	adds r1, #4
	strh r0, [r1]
	adds r4, r6, #0
	adds r4, #0x2c
	adds r0, r4, #0
	adds r1, r2, #0
	str r3, [sp, #0x10]
	bl Video_GetActorSprite
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	bl FUN_0822a470
	movs r0, #2
	add r0, r8
	strh r0, [r6, #0x10]
	movs r0, #3
	strb r0, [r6, #7]
	ldr r0, _080C5B68 @ =0x0000259C
	add r0, sl
	str r0, [r4, #0xc]
	movs r0, #0xbe
	lsls r0, r0, #2
	add r0, sl
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	mov r0, sb
	ldrb r1, [r0, #2]
	ldrh r0, [r5]
	adds r2, r0, #0
	muls r2, r1, r2
	adds r0, r2, #0
	ldrh r4, [r6, #0x1c]
	adds r0, r0, r4
	strh r0, [r6, #0x1c]
	ldr r3, [sp, #0x10]
	adds r3, #1
	cmp r3, #0xd
	bgt _080C5B3A
	b _080C5A36
_080C5B3A:
	movs r1, #0x8d
	lsls r1, r1, #3
	add r1, sb
	ldr r0, [sp, #0xc]
	str r0, [sp]
	mov r0, sl
	ldr r2, [sp, #4]
	ldr r3, [sp, #8]
	bl FUN_080c595c
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C5B60: .4byte 0x00008207
_080C5B64: .4byte 0x085AD0DE
_080C5B68: .4byte 0x0000259C

	thumb_func_start FUN_080c5b6c
FUN_080c5b6c: @ 0x080C5B6C
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C5BDE
	movs r2, #0
	strb r2, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #1
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x38
	movs r3, #0
	bl FUN_08055b5c
	movs r2, #0xbe
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r1, [r0]
	movs r5, #0xba
	lsls r5, r5, #2
	adds r0, r4, r5
	movs r3, #0
	strh r1, [r0]
	ldr r1, _080C5BF4 @ =0x000002FA
	adds r0, r4, r1
	subs r2, #0xf8
	adds r1, r2, #0
	ldrh r0, [r0]
	adds r2, r1, r0
	adds r5, #2
	adds r0, r4, r5
	strh r2, [r0]
	movs r2, #0xbf
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	adds r1, r1, r0
	adds r5, #2
	adds r0, r4, r5
	strh r1, [r0]
	ldr r1, _080C5BF8 @ =0x000008F4
	adds r0, r4, r1
	strb r3, [r0]
	ldr r2, _080C5BFC @ =0x000008F5
	adds r0, r4, r2
	strb r3, [r0]
	ldr r5, _080C5C00 @ =0x000008F6
	adds r0, r4, r5
	strb r3, [r0]
_080C5BDE:
	movs r2, #0xd8
	lsls r2, r2, #0xd
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C5BF4: .4byte 0x000002FA
_080C5BF8: .4byte 0x000008F4
_080C5BFC: .4byte 0x000008F5
_080C5C00: .4byte 0x000008F6

	thumb_func_start FUN_080c5c04
FUN_080c5c04: @ 0x080C5C04
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r1, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C5C32
	movs r2, #0
	strb r2, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x39
	movs r3, #0
	bl FUN_08055b5c
_080C5C32:
	movs r2, #0xd8
	lsls r2, r2, #0xd
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	cmp r5, #0xa
	bne _080C5C50
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_080C5C50:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c5c58
FUN_080c5c58: @ 0x080C5C58
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r4, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C5C82
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r4, r0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
_080C5C82:
	movs r2, #0xd8
	lsls r2, r2, #0xd
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	cmp r5, #2
	bgt _080C5CB0
	ldr r2, _080C5CAC @ =0x000002F2
	adds r1, r4, r2
	ldrh r0, [r1]
	subs r0, #0x10
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x10
	b _080C5D04
	.align 2, 0
_080C5CAC: .4byte 0x000002F2
_080C5CB0:
	cmp r5, #3
	bne _080C5CBE
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080c4a54
	b _080C5D62
_080C5CBE:
	cmp r5, #0x1a
	ble _080C5D62
	cmp r5, #0x1d
	bgt _080C5CEC
	cmp r5, #0x1b
	bne _080C5CE0
	ldr r2, _080C5CE8 @ =0x000002F2
	adds r1, r4, r2
	ldrh r0, [r1]
	subs r0, #0x20
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x20
	strh r0, [r1]
_080C5CE0:
	adds r0, r4, #0
	bl FUN_080c4990
	b _080C5D62
	.align 2, 0
_080C5CE8: .4byte 0x000002F2
_080C5CEC:
	cmp r5, #0x20
	bgt _080C5D14
	ldr r2, _080C5D10 @ =0x000002F2
	adds r1, r4, r2
	ldrh r0, [r1]
	subs r0, #0x30
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x30
_080C5D04:
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080c4a2c
	b _080C5D62
	.align 2, 0
_080C5D10: .4byte 0x000002F2
_080C5D14:
	cmp r5, #0x21
	bne _080C5D58
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _080C5D54 @ =0x000002FA
	adds r1, r4, r0
	subs r2, #0x70
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r2, #0x72
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #0xbf
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	b _080C5D62
	.align 2, 0
_080C5D54: .4byte 0x000002FA
_080C5D58:
	cmp r5, #0x21
	ble _080C5D62
	adds r0, r4, #0
	bl FUN_080c4990
_080C5D62:
	cmp r5, #0x1a
	bne _080C5D76
	ldr r0, _080C5DB8 @ =0x00000232
	bl PlaySound_082406e0
	ldr r1, _080C5DBC @ =0x00001934
	adds r0, r6, r1
	ldr r1, _080C5DC0 @ =0x080C2825
	bl FUN_080c2680
_080C5D76:
	cmp r5, #0x1c
	bne _080C5D84
	ldr r2, _080C5DC4 @ =0x00001E84
	adds r0, r6, r2
	ldr r1, _080C5DC0 @ =0x080C2825
	bl FUN_080c2680
_080C5D84:
	cmp r5, #0x1e
	bne _080C5D92
	ldr r1, _080C5DC8 @ =0x0000212C
	adds r0, r6, r1
	ldr r1, _080C5DC0 @ =0x080C2825
	bl FUN_080c2680
_080C5D92:
	cmp r5, #0x20
	bne _080C5DA0
	ldr r2, _080C5DCC @ =0x00001BDC
	adds r0, r6, r2
	ldr r1, _080C5DC0 @ =0x080C2825
	bl FUN_080c2680
_080C5DA0:
	cmp r5, #0x28
	bne _080C5DB0
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_080C5DB0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C5DB8: .4byte 0x00000232
_080C5DBC: .4byte 0x00001934
_080C5DC0: .4byte 0x080C2825
_080C5DC4: .4byte 0x00001E84
_080C5DC8: .4byte 0x0000212C
_080C5DCC: .4byte 0x00001BDC

	thumb_func_start FUN_080c5dd0
FUN_080c5dd0: @ 0x080C5DD0
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r7, r1, #0
	adds r6, r5, #0
	adds r6, #0xa9
	ldrb r0, [r6]
	cmp r0, #0
	beq _080C5E38
	movs r4, #0
	strb r4, [r6]
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	ldr r3, _080C5E80 @ =0x000002FA
	adds r0, r5, r3
	subs r2, #0xf0
	adds r1, r2, #0
	ldrh r0, [r0]
	adds r2, r1, r0
	subs r3, #8
	adds r0, r5, r3
	strh r2, [r0]
	movs r2, #0xbf
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	adds r1, r1, r0
	adds r3, #2
	adds r0, r5, r3
	strh r1, [r0]
	ldr r0, _080C5E84 @ =0x00000231
	bl PlaySound_082406e0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #1
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #2
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C5E38:
	movs r2, #0xd8
	lsls r2, r2, #0xd
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r5, #0
	bl FUN_080c4990
	cmp r7, #0x53
	bgt _080C5E58
	adds r0, r5, #0
	movs r1, #0x10
	bl FUN_080c4a54
_080C5E58:
	cmp r7, #0x63
	ble _080C5E76
	ldr r2, _080C5E88 @ =FUN_080c5e8c
	movs r0, #0x2e
	adds r3, r5, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	movs r0, #1
	strb r0, [r6]
_080C5E76:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C5E80: .4byte 0x000002FA
_080C5E84: .4byte 0x00000231
_080C5E88: .4byte FUN_080c5e8c

	thumb_func_start FUN_080c5e8c
FUN_080c5e8c: @ 0x080C5E8C
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r4, #0
	adds r5, #0xa9
	ldrb r0, [r5]
	cmp r0, #0
	beq _080C5EF4
	movs r2, #0
	strb r2, [r5]
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	ldr r0, _080C5F3C @ =0x000002FA
	adds r1, r4, r0
	subs r3, #0x70
	adds r0, r3, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r3, #0x72
	adds r1, r4, r3
	strh r0, [r1]
	movs r0, #0xbf
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r1, r4, r3
	strh r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #3
	movs r3, #0
	bl FUN_08055b5c
_080C5EF4:
	movs r2, #0xd8
	lsls r2, r2, #0xd
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_080c4990
	cmp r6, #9
	ble _080C5F32
	ldr r2, _080C5F40 @ =FUN_080c5fd8
	movs r0, #0x30
	adds r3, r4, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	movs r0, #1
	strb r0, [r5]
	movs r3, #0x8c
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r1, #1
	bl FUN_08022488
_080C5F32:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C5F3C: .4byte 0x000002FA
_080C5F40: .4byte FUN_080c5fd8

	thumb_func_start FUN_080c5f44
FUN_080c5f44: @ 0x080C5F44
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r7, r1, #0
	adds r6, r5, #0
	adds r6, #0xa9
	ldrb r0, [r6]
	cmp r0, #0
	beq _080C5F98
	movs r4, #0
	strb r4, [r6]
	movs r0, #0xbf
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r2, #0xf4
	adds r1, r5, r2
	strh r0, [r1]
	ldr r0, _080C5FCC @ =0x000008F2
	adds r1, r5, r0
	movs r0, #0xc0
	strb r0, [r1]
	ldr r0, _080C5FD0 @ =0x00000225
	bl PlaySound_082406e0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #3
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C5F98:
	movs r2, #0xd8
	lsls r2, r2, #0xd
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	cmp r7, #9
	ble _080C5FC4
	ldr r2, _080C5FD4 @ =FUN_080c5fd8
	movs r0, #0x30
	adds r3, r5, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	movs r0, #1
	strb r0, [r6]
_080C5FC4:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C5FCC: .4byte 0x000008F2
_080C5FD0: .4byte 0x00000225
_080C5FD4: .4byte FUN_080c5fd8

	thumb_func_start FUN_080c5fd8
FUN_080c5fd8: @ 0x080C5FD8
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C603E
	movs r2, #0
	strb r2, [r1]
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	ldr r0, _080C605C @ =0x000002FA
	adds r1, r4, r0
	subs r3, #0x70
	adds r0, r3, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r3, #0x72
	adds r1, r4, r3
	strh r0, [r1]
	movs r0, #0xbf
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r1, r4, r3
	strh r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #1
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r3, #0
	bl FUN_08055b5c
_080C603E:
	movs r2, #0xd8
	lsls r2, r2, #0xd
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_080c4990
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080C605C: .4byte 0x000002FA

	thumb_func_start FUN_080c6060
FUN_080c6060: @ 0x080C6060
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C60D0
	movs r2, #0
	strb r2, [r1]
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r4, #0
	strh r1, [r0]
	ldr r1, _080C60E8 @ =0x000002FA
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strh r1, [r0]
	movs r0, #0xbf
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r3, #0xea
	adds r0, r3, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r3, #0xec
	adds r1, r5, r3
	strh r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #1
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x36
	movs r3, #0
	bl FUN_08055b5c
	ldr r3, _080C60EC @ =0x000008F4
	adds r0, r5, r3
	strb r4, [r0]
	ldr r1, _080C60F0 @ =0x000008F5
	adds r0, r5, r1
	strb r4, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r4, [r0]
_080C60D0:
	movs r2, #0xb6
	lsls r2, r2, #0xf
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C60E8: .4byte 0x000002FA
_080C60EC: .4byte 0x000008F4
_080C60F0: .4byte 0x000008F5

	thumb_func_start FUN_080c60f4
FUN_080c60f4: @ 0x080C60F4
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r4, #0
	adds r5, #0xa9
	ldrb r0, [r5]
	cmp r0, #0
	beq _080C612A
	movs r2, #0
	strb r2, [r5]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x37
	movs r3, #0
	bl FUN_08055b5c
	ldr r0, _080C6164 @ =0x000008F4
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_080C612A:
	movs r2, #0xb6
	lsls r2, r2, #0xf
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	cmp r6, #0x41
	ble _080C615A
	ldr r1, _080C6168 @ =0x000025FD
	adds r0, r4, r1
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r1, _080C616C @ =FUN_080c6170
	movs r0, #0x33
	movs r6, #0xa3
	strb r0, [r6, r4]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	strb r2, [r5]
_080C615A:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C6164: .4byte 0x000008F4
_080C6168: .4byte 0x000025FD
_080C616C: .4byte FUN_080c6170

	thumb_func_start FUN_080c6170
FUN_080c6170: @ 0x080C6170
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	mov sl, r1
	mov r7, r8
	movs r0, #0xa9
	adds r0, r0, r7
	mov sb, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C61F8
	movs r6, #0
	mov r1, sb
	strb r6, [r1]
	movs r2, #0xbe
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrh r1, [r0]
	subs r2, #8
	adds r0, r7, r2
	strh r1, [r0]
	movs r1, #0xbf
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	adds r0, #0x20
	adds r2, #4
	adds r1, r7, r2
	strh r0, [r1]
	ldr r1, _080C6240 @ =0x000002FA
	adds r0, r7, r1
	ldrh r0, [r0]
	adds r0, #0x80
	subs r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	movs r0, #0x89
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r5, #1
	str r5, [sp]
	str r6, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	movs r1, #2
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r7, r2
	str r5, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0x18
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C61F8:
	movs r2, #0xd8
	lsls r2, r2, #0xd
	mov r1, r8
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r0, r8
	bl FUN_080c4990
	mov r0, sl
	cmp r0, #0x3b
	ble _080C622E
	ldr r2, _080C6244 @ =FUN_080c6248
	movs r0, #0x34
	mov r3, r8
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	mov r0, r8
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	movs r0, #1
	mov r1, sb
	strb r0, [r1]
_080C622E:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C6240: .4byte 0x000002FA
_080C6244: .4byte FUN_080c6248

	thumb_func_start FUN_080c6248
FUN_080c6248: @ 0x080C6248
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r2, #0xd8
	lsls r2, r2, #0xd
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x60
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080c4a2c
	ldr r1, _080C6298 @ =0x000025FD
	adds r0, r4, r1
	ldrb r3, [r0]
	cmp r3, #0
	beq _080C62A0
	cmp r5, #7
	ble _080C62C0
	ldr r1, _080C629C @ =FUN_080c62cc
	movs r0, #0x35
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0x8c
	movs r0, #0
	str r0, [r1]
	adds r1, #0x1d
	b _080C62BC
	.align 2, 0
_080C6298: .4byte 0x000025FD
_080C629C: .4byte FUN_080c62cc
_080C62A0:
	cmp r5, #9
	ble _080C62C0
	ldr r1, _080C62C8 @ =FUN_080c5f44
	movs r0, #0x2f
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
_080C62BC:
	movs r0, #1
	strb r0, [r1]
_080C62C0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C62C8: .4byte FUN_080c5f44

	thumb_func_start FUN_080c62cc
FUN_080c62cc: @ 0x080C62CC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r6, r0, #0
	mov r8, r1
	adds r5, r6, #0
	adds r7, r5, #0
	adds r7, #0xa9
	ldrb r0, [r7]
	cmp r0, #0
	beq _080C6312
	movs r4, #0
	strb r4, [r7]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #1
	bl FUN_08022488
	ldr r0, _080C634C @ =0x00000225
	bl PlaySound_082406e0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C6312:
	movs r2, #0xd8
	lsls r2, r2, #0xd
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r0, r8
	cmp r0, #3
	ble _080C6340
	ldr r2, _080C6350 @ =FUN_080c6354
	movs r0, #0x36
	adds r3, r6, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r6, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	movs r0, #1
	strb r0, [r7]
_080C6340:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C634C: .4byte 0x00000225
_080C6350: .4byte FUN_080c6354

	thumb_func_start FUN_080c6354
FUN_080c6354: @ 0x080C6354
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r7, r0, #0
	adds r6, r1, #0
	adds r4, r7, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C638A
	movs r2, #0
	strb r2, [r1]
	ldr r1, _080C63F4 @ =0x0000192F
	adds r0, r4, r1
	strb r2, [r0]
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r1, #1
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #5
	movs r3, #0
	bl FUN_08055b5c
_080C638A:
	movs r2, #0xd8
	lsls r2, r2, #0xd
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080C63F4 @ =0x0000192F
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _080C63A8
	ldr r0, _080C63F8 @ =0x00000226
	bl PlaySound_082406e0
_080C63A8:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x27
	bls _080C63BA
	movs r0, #0
	strb r0, [r5]
_080C63BA:
	cmp r6, #0x20
	bne _080C6400
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r3, _080C63FC @ =0x000002FA
	adds r0, r4, r3
	subs r2, #0xf0
	adds r1, r2, #0
	ldrh r0, [r0]
	adds r2, r1, r0
	subs r3, #8
	adds r0, r4, r3
	strh r2, [r0]
	movs r2, #0xbf
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	adds r1, r1, r0
	adds r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	b _080C640A
	.align 2, 0
_080C63F4: .4byte 0x0000192F
_080C63F8: .4byte 0x00000226
_080C63FC: .4byte 0x000002FA
_080C6400:
	cmp r6, #0x20
	ble _080C640A
	adds r0, r7, #0
	bl FUN_080c4990
_080C640A:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c6414
FUN_080c6414: @ 0x080C6414
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r4, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C645E
	movs r2, #0
	strb r2, [r1]
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r3, r4, r0
	subs r1, #0xac
	adds r0, r4, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r1, _080C64E4 @ =0x000008F4
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_080c4a54
_080C645E:
	movs r2, #0xd8
	lsls r2, r2, #0xd
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	cmp r5, #0x28
	bne _080C647A
	ldr r1, _080C64E8 @ =0x00001934
	adds r0, r4, r1
	ldr r1, _080C64EC @ =FUN_080c2978
	bl FUN_080c2680
_080C647A:
	cmp r5, #0x3c
	bne _080C6488
	ldr r1, _080C64F0 @ =0x0000212C
	adds r0, r4, r1
	ldr r1, _080C64EC @ =FUN_080c2978
	bl FUN_080c2680
_080C6488:
	cmp r5, #0x50
	bne _080C6496
	ldr r1, _080C64F4 @ =0x00001E84
	adds r0, r4, r1
	ldr r1, _080C64EC @ =FUN_080c2978
	bl FUN_080c2680
_080C6496:
	cmp r5, #0x64
	bne _080C64A4
	ldr r1, _080C64F8 @ =0x00001BDC
	adds r0, r4, r1
	ldr r1, _080C64EC @ =FUN_080c2978
	bl FUN_080c2680
_080C64A4:
	adds r0, r4, #0
	bl FUN_080c4990
	cmp r5, #0x2c
	beq _080C64BA
	cmp r5, #0x40
	beq _080C64BA
	cmp r5, #0x54
	beq _080C64BA
	cmp r5, #0x68
	bne _080C64CC
_080C64BA:
	adds r0, r6, #0
	movs r1, #4
	bl FUN_080c4a54
	ldr r0, _080C64FC @ =0x000002EA
	adds r1, r6, r0
	ldrh r0, [r1]
	subs r0, #0x20
	strh r0, [r1]
_080C64CC:
	cmp r5, #0x78
	bne _080C64DC
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_080C64DC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C64E4: .4byte 0x000008F4
_080C64E8: .4byte 0x00001934
_080C64EC: .4byte FUN_080c2978
_080C64F0: .4byte 0x0000212C
_080C64F4: .4byte 0x00001E84
_080C64F8: .4byte 0x00001BDC
_080C64FC: .4byte 0x000002EA

	thumb_func_start FUN_080c6500
FUN_080c6500: @ 0x080C6500
	push {lr}
	sub sp, #0xc
	adds r3, r1, #0
	ldr r1, _080C6530 @ =0x00002608
	adds r0, r0, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080C652A
	ldr r1, _080C6534 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	str r3, [sp]
	add r1, sp, #4
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl Script_ExecById
_080C652A:
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_080C6530: .4byte 0x00002608
_080C6534: .4byte 0xFFFF0000

	thumb_func_start FUN_080c6538
FUN_080c6538: @ 0x080C6538
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	adds r2, r6, #0
	adds r2, #0xa9
	ldrb r0, [r2]
	cmp r0, #0
	beq _080C65A2
	movs r1, #0
	strb r1, [r2]
	ldr r2, _080C6698 @ =0x000025FE
	adds r0, r6, r2
	strb r1, [r0]
	ldr r3, _080C669C @ =0x00002602
	adds r0, r6, r3
	movs r2, #0
	strh r1, [r0]
	ldr r4, _080C66A0 @ =0x000025FF
	adds r0, r6, r4
	strb r2, [r0]
	movs r5, #0x98
	lsls r5, r5, #6
	adds r0, r6, r5
	strb r2, [r0]
	ldr r1, _080C66A4 @ =0x00002606
	adds r0, r6, r1
	bl FUN_0809c544
	ldr r2, _080C66A8 @ =0x00002604
	adds r0, r6, r2
	ldrh r0, [r0]
	adds r2, r6, #0
	adds r2, #0x90
	strh r0, [r2]
	ldr r3, _080C66AC @ =0x030046A0
	ldr r0, [r3]
	movs r4, #0xae
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r5, #0
	ldrsh r1, [r2, r5]
	str r1, [r0]
	ldr r0, [r3]
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r2, r3]
	str r1, [r0]
_080C65A2:
	movs r2, #0xd8
	lsls r2, r2, #0xd
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r4, #0
	mov sl, r4
	adds r0, r6, #0
	bl FUN_080c4114
	ldr r5, _080C66AC @ =0x030046A0
	ldr r0, [r5]
	ldr r1, _080C66B0 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r7, [r0, r2]
	ldr r0, _080C66B4 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080C66BC
	cmp r7, #0
	ble _080C66BC
	movs r3, #0x98
	lsls r3, r3, #6
	adds r4, r6, r3
	ldrb r0, [r4]
	cmp r0, #0
	bne _080C65F8
	ldr r1, _080C66B8 @ =0x085AD0FA
	ldr r2, _080C6698 @ =0x000025FE
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bl PlaySound_082406e0
	movs r0, #1
	strb r0, [r4]
_080C65F8:
	ldr r3, _080C669C @ =0x00002602
	adds r2, r6, r3
	ldrh r0, [r2]
	adds r0, r0, r7
	strh r0, [r2]
	ldr r1, [r5]
	movs r4, #0xaf
	lsls r4, r4, #2
	adds r1, r1, r4
	ldr r1, [r1]
	subs r1, r1, r0
	adds r0, r6, #0
	adds r0, #0x90
	strh r1, [r0]
	lsls r1, r1, #0x10
	cmp r1, #0
	bge _080C661E
	mov r5, sl
	strh r5, [r0]
_080C661E:
	ldrh r4, [r2]
	ldr r0, _080C6698 @ =0x000025FE
	adds r5, r6, r0
	ldrb r0, [r5]
	adds r0, #1
	ldr r2, _080C66A8 @ =0x00002604
	adds r1, r6, r2
	ldrh r1, [r1]
	muls r0, r1, r0
	movs r1, #6
	bl Div
	cmp r4, r0
	blt _080C667A
	movs r3, #1
	mov sl, r3
	ldrb r1, [r5]
	mov r0, sl
	ands r0, r1
	cmp r0, #0
	beq _080C665E
	cmp r1, #5
	beq _080C665E
	ldrb r0, [r5]
	adds r0, #1
	asrs r0, r0, #1
	ldr r1, _080C66B8 @ =0x085AD0FA
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bl PlaySound_082406e0
_080C665E:
	ldr r4, _080C669C @ =0x00002602
	adds r0, r6, r4
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r5, _080C66A8 @ =0x00002604
	adds r1, r6, r5
	ldrh r1, [r1]
	bl Div
	ldr r2, _080C6698 @ =0x000025FE
	adds r1, r6, r2
	strb r0, [r1]
_080C667A:
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_080c3fd0
	ldr r3, _080C66A0 @ =0x000025FF
	adds r4, r6, r3
	ldrb r0, [r4]
	cmp r0, #0
	bne _080C66CA
	movs r0, #0xd9
	bl PlaySound_082406e0
	movs r0, #1
	strb r0, [r4]
	b _080C66CA
	.align 2, 0
_080C6698: .4byte 0x000025FE
_080C669C: .4byte 0x00002602
_080C66A0: .4byte 0x000025FF
_080C66A4: .4byte 0x00002606
_080C66A8: .4byte 0x00002604
_080C66AC: .4byte 0x030046A0
_080C66B0: .4byte 0x00000942
_080C66B4: .4byte 0x030044E0
_080C66B8: .4byte 0x085AD0FA
_080C66BC:
	movs r0, #0xd9
	bl sound_08240740
	ldr r4, _080C67C4 @ =0x000025FF
	adds r1, r6, r4
	movs r0, #0
	strb r0, [r1]
_080C66CA:
	ldr r5, _080C67C8 @ =0x00002601
	adds r7, r6, r5
	ldr r0, _080C67CC @ =0x000025FE
	adds r0, r0, r6
	mov r8, r0
	ldrb r0, [r0]
	ldrb r1, [r7]
	adds r0, r0, r1
	movs r2, #0
	mov sb, r2
	strb r0, [r7]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _080C677A
	ldr r4, _080C67D0 @ =0xFFFF0000
	ldr r3, _080C67D4 @ =0x0000FFFF
	mov ip, r3
	str r2, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r4
	str r0, [sp, #0x14]
	ldr r2, _080C67D8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C67DC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _080C67E0 @ =0x0203B400
	adds r0, r0, r5
	ldrh r3, [r0]
	asrs r3, r3, #3
	movs r2, #0x7f
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r0, [r0]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x18]
	ands r1, r4
	orrs r1, r0
	ldr r5, _080C67E4 @ =0x000002EA
	adds r0, r6, r5
	ldrh r0, [r0]
	ands r3, r2
	adds r0, r3, r0
	lsls r0, r0, #0x10
	mov r2, ip
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x18]
	adds r5, #2
	adds r1, r6, r5
	ldr r2, _080C67E8 @ =0xFFFFFE00
	adds r0, r2, #0
	adds r3, r3, r0
	ldrh r2, [r1]
	subs r2, r2, r3
	subs r2, #0x40
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r0, sp, #0x18
	ldr r1, [r0, #4]
	ands r1, r4
	orrs r1, r2
	str r1, [r0, #4]
	mov r3, sb
	str r3, [sp]
	movs r1, #0x10
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	add r2, sp, #0x10
	movs r3, #0
	bl FUN_080ddcc8
	adds r0, r6, #0
	movs r1, #3
	bl FUN_080c4a54
	ldrb r0, [r7]
	subs r0, #0x10
	strb r0, [r7]
_080C677A:
	ldr r4, _080C67EC @ =0x00002606
	adds r0, r6, r4
	ldrh r1, [r0]
	subs r1, #1
	strh r1, [r0]
	mov r5, r8
	ldrb r0, [r5]
	cmp r0, #6
	bne _080C67F4
	bl FUN_0809c58c
	ldr r1, _080C67F0 @ =FUN_080c6a5c
	movs r0, #0x3a
	adds r2, r6, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	mov r1, sb
	str r1, [r0]
	adds r1, r6, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_080c4254
	movs r0, #0xd9
	bl sound_08240740
	ldrb r1, [r5]
	adds r0, r6, #0
	bl FUN_080c6500
	b _080C6840
	.align 2, 0
_080C67C4: .4byte 0x000025FF
_080C67C8: .4byte 0x00002601
_080C67CC: .4byte 0x000025FE
_080C67D0: .4byte 0xFFFF0000
_080C67D4: .4byte 0x0000FFFF
_080C67D8: .4byte 0x030046B8
_080C67DC: .4byte 0x000003FF
_080C67E0: .4byte 0x0203B400
_080C67E4: .4byte 0x000002EA
_080C67E8: .4byte 0xFFFFFE00
_080C67EC: .4byte 0x00002606
_080C67F0: .4byte FUN_080c6a5c
_080C67F4:
	lsls r0, r1, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _080C6830
	bl FUN_0809c58c
	adds r0, r6, #0
	bl FUN_080c4254
	movs r0, #0xd9
	bl sound_08240740
	ldr r1, _080C682C @ =FUN_080c6850
	movs r0, #0x39
	adds r2, r6, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	adds r1, r6, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
	b _080C6840
	.align 2, 0
_080C682C: .4byte FUN_080c6850
_080C6830:
	mov r2, sl
	cmp r2, #0
	beq _080C6840
	mov r3, r8
	ldrb r1, [r3]
	adds r0, r6, #0
	bl FUN_080c6500
_080C6840:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c6850
FUN_080c6850: @ 0x080C6850
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r1, #0
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C6896
	movs r4, #0
	strb r4, [r1]
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _080C68C0 @ =0x000008F4
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _080C68C4 @ =0x00000227
	bl PlaySound_082406e0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #7
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C6896:
	movs r2, #0xd8
	lsls r2, r2, #0xd
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	cmp r6, #0x10
	bne _080C68C8
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x1a
	b _080C6A2A
	.align 2, 0
_080C68C0: .4byte 0x000008F4
_080C68C4: .4byte 0x00000227
_080C68C8:
	cmp r6, #0x14
	bne _080C68E2
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	b _080C6A2A
_080C68E2:
	cmp r6, #0x18
	bne _080C6902
	movs r2, #0x86
	lsls r2, r2, #3
	adds r0, r5, r2
	adds r2, #0x95
	adds r1, r5, r2
	ldrb r2, [r1]
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #1
	b _080C6A2C
_080C6902:
	cmp r6, #0x1c
	bne _080C691C
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x18
	b _080C6A2A
_080C691C:
	cmp r6, #0x20
	bne _080C693C
	movs r2, #0x99
	lsls r2, r2, #3
	adds r0, r5, r2
	adds r2, #0x95
	adds r1, r5, r2
	ldrb r2, [r1]
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #1
	b _080C6A2C
_080C693C:
	cmp r6, #0x24
	bne _080C696C
	movs r1, #0x86
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r2, _080C6968 @ =0x000004C5
	adds r1, r5, r2
	ldrb r2, [r1]
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r3, #0
	bl FUN_08055b5c
	movs r0, #0xe7
	bl PlaySound_082406e0
	b _080C6A44
	.align 2, 0
_080C6968: .4byte 0x000004C5
_080C696C:
	cmp r6, #0x28
	bne _080C6990
	movs r1, #0xac
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r2, _080C698C @ =0x000005F5
	adds r1, r5, r2
	ldrb r2, [r1]
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #1
	b _080C6A2C
	.align 2, 0
_080C698C: .4byte 0x000005F5
_080C6990:
	cmp r6, #0x2c
	bne _080C69B4
	movs r1, #0x99
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r2, _080C69B0 @ =0x0000055D
	adds r1, r5, r2
	ldrb r2, [r1]
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	b _080C6A2C
	.align 2, 0
_080C69B0: .4byte 0x0000055D
_080C69B4:
	cmp r6, #0x34
	bne _080C69D8
	movs r1, #0xac
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r2, _080C69D4 @ =0x000005F5
	adds r1, r5, r2
	ldrb r2, [r1]
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	b _080C6A2C
	.align 2, 0
_080C69D4: .4byte 0x000005F5
_080C69D8:
	cmp r6, #0x46
	bne _080C69F2
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x16
	b _080C6A2A
_080C69F2:
	cmp r6, #0x9e
	bne _080C6A0C
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #1
	b _080C6A2A
_080C6A0C:
	cmp r6, #0xa8
	bne _080C6A38
	ldr r0, _080C6A34 @ =0x00000231
	bl PlaySound_082406e0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #1
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #2
_080C6A2A:
	movs r2, #0
_080C6A2C:
	movs r3, #0
	bl FUN_08055b5c
	b _080C6A44
	.align 2, 0
_080C6A34: .4byte 0x00000231
_080C6A38:
	cmp r6, #0xa8
	ble _080C6A44
	adds r0, r5, #0
	movs r1, #0x10
	bl FUN_080c4a54
_080C6A44:
	cmp r6, #0xaa
	bne _080C6A52
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r5, #0
	bl FUN_080c6500
_080C6A52:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c6a5c
FUN_080c6a5c: @ 0x080C6A5C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	adds r7, r0, #0
	mov r8, r1
	adds r6, r7, #0
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C6AD4
	movs r5, #0
	strb r5, [r1]
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r4, #1
	strb r4, [r0]
	movs r2, #0xbe
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r1, [r0]
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r1, [r0]
	ldr r1, _080C6B38 @ =0x000002FA
	adds r0, r6, r1
	subs r2, #0xf8
	adds r1, r2, #0
	ldrh r0, [r0]
	adds r2, r1, r0
	adds r3, #2
	adds r0, r6, r3
	strh r2, [r0]
	movs r2, #0xbf
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r0, [r0]
	adds r1, r1, r0
	adds r3, #2
	adds r0, r6, r3
	strh r1, [r0]
	movs r0, #0x8d
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r6, r1
	str r4, [sp]
	str r5, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xf
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C6AD4:
	movs r1, #0xd8
	lsls r1, r1, #0xd
	adds r4, r7, #0
	adds r4, #0x98
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	adds r0, r7, #0
	bl FUN_080c4990
	adds r0, r7, #0
	movs r1, #0x10
	bl FUN_080c4a54
	movs r1, #0x80
	lsls r1, r1, #0xe
	ldr r0, [r4]
	orrs r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [r4]
	mov r2, r8
	cmp r2, #0x3c
	bne _080C6B2A
	ldr r3, _080C6B3C @ =0x00002608
	adds r0, r7, r3
	ldr r4, [r0]
	cmp r4, #0
	beq _080C6B2A
	ldr r1, _080C6B40 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #0x10]
	str r1, [sp, #0xc]
	add r1, sp, #0x10
	add r0, sp, #0xc
	str r0, [r1, #4]
	adds r0, r4, #0
	bl Script_ExecById
_080C6B2A:
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C6B38: .4byte 0x000002FA
_080C6B3C: .4byte 0x00002608
_080C6B40: .4byte 0xFFFF0000

	thumb_func_start FUN_080c6b44
FUN_080c6b44: @ 0x080C6B44
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xc8
	lsls r1, r1, #5
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _080C6B58
	b _080C6C6E
_080C6B58:
	ldr r3, _080C6BB8 @ =0x000025FB
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080C6BCC
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	subs r0, #0xd0
	lsls r0, r0, #0x10
	ldr r2, _080C6BBC @ =0xFFFF0000
	lsrs r0, r0, #0x10
	movs r1, #0xc0
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #8]
	movs r3, #0xbb
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r3, #0xd8
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0xc]
	ldr r2, _080C6BC0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C6BC4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080C6BC8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x18
	bl Mod
	adds r6, r0, #0
	adds r6, #0x54
	b _080C6C1E
	.align 2, 0
_080C6BB8: .4byte 0x000025FB
_080C6BBC: .4byte 0xFFFF0000
_080C6BC0: .4byte 0x030046B8
_080C6BC4: .4byte 0x000003FF
_080C6BC8: .4byte 0x0203B400
_080C6BCC:
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r0, [r0]
	adds r0, #0x90
	lsls r0, r0, #0x10
	ldr r2, _080C6C78 @ =0xFFFF0000
	lsrs r0, r0, #0x10
	movs r1, #0xc0
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #8]
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r3, #0xd8
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0xc]
	ldr r2, _080C6C7C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C6C80 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080C6C84 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x18
	bl Mod
	adds r6, r0, #0
	adds r6, #0x14
_080C6C1E:
	movs r0, #0x8a
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r3, #0x86
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r4, [r0]
	ldr r2, _080C6C7C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C6C80 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080C6C84 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #6
	bl Mod
	adds r2, r0, #0
	movs r3, #0xc8
	lsls r3, r3, #5
	adds r0, r5, r3
	ldr r0, [r0]
	movs r1, #0x14
	str r1, [sp]
	str r2, [sp, #4]
	add r1, sp, #8
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_082464fc
	ldr r0, _080C6C88 @ =0x000025FB
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r2]
_080C6C6E:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C6C78: .4byte 0xFFFF0000
_080C6C7C: .4byte 0x030046B8
_080C6C80: .4byte 0x000003FF
_080C6C84: .4byte 0x0203B400
_080C6C88: .4byte 0x000025FB

	thumb_func_start FUN_080c6c8c
FUN_080c6c8c: @ 0x080C6C8C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	mov r8, r1
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C6D12
	movs r6, #0
	strb r6, [r1]
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080C6D68 @ =0x000002FA
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r0, #0x80
	ldr r3, _080C6D6C @ =0x000002F2
	adds r1, r7, r3
	movs r2, #0
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r1, _080C6D70 @ =0x000025FA
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r5, #1
	str r5, [sp]
	str r6, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	movs r3, #0xe6
	lsls r3, r3, #2
	adds r0, r7, r3
	str r5, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0x18
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C6D12:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _080C6D28
	b _080C716C
_080C6D28:
	movs r2, #0x80
	lsls r2, r2, #0xf
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _080C6D74 @ =0x0000191C
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _080C6D7C
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r4, #1
	str r4, [sp]
	str r3, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #8
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	ldr r3, _080C6D78 @ =0x000025E8
	adds r0, r7, r3
	b _080C6DA2
	.align 2, 0
_080C6D68: .4byte 0x000002FA
_080C6D6C: .4byte 0x000002F2
_080C6D70: .4byte 0x000025FA
_080C6D74: .4byte 0x0000191C
_080C6D78: .4byte 0x000025E8
_080C6D7C:
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080C6DA4
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, r1
	str r4, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xb
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	ldr r2, _080C6E00 @ =0x000025E8
	adds r0, r7, r2
_080C6DA2:
	strh r4, [r0]
_080C6DA4:
	ldr r3, _080C6E00 @ =0x000025E8
	adds r1, r7, r3
	ldrh r0, [r1]
	cmp r0, #0
	beq _080C6E44
	adds r0, #1
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _080C6E58
	strh r5, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r4, #1
	str r4, [sp]
	str r5, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	ldr r2, _080C6E04 @ =0x0000260C
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #2
	bne _080C6E10
	ldr r1, _080C6E08 @ =FUN_080c718c
	adds r0, r7, #0
	adds r0, #0xa3
	strb r4, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r5, [r0]
	adds r0, #0x1d
	strb r4, [r0]
	ldr r3, _080C6E0C @ =0x000025FA
	adds r1, r7, r3
	movs r0, #0
	b _080C6E56
	.align 2, 0
_080C6E00: .4byte 0x000025E8
_080C6E04: .4byte 0x0000260C
_080C6E08: .4byte FUN_080c718c
_080C6E0C: .4byte 0x000025FA
_080C6E10:
	ldr r1, _080C6E38 @ =0x00001909
	adds r0, r7, r1
	ldrb r1, [r0]
	ldr r2, _080C6E3C @ =0x00001908
	adds r0, r7, r2
	strb r1, [r0]
	ldr r1, _080C6E40 @ =FUN_080c73c0
	movs r0, #3
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r5, [r0]
	adds r0, #0x1d
	strb r4, [r0]
	b _080C6E58
	.align 2, 0
_080C6E38: .4byte 0x00001909
_080C6E3C: .4byte 0x00001908
_080C6E40: .4byte FUN_080c73c0
_080C6E44:
	ldr r3, _080C6E80 @ =0x0000260C
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #2
	bne _080C6E58
	ldr r0, _080C6E84 @ =0x000025FA
	adds r1, r7, r0
	ldrb r0, [r1]
	adds r0, #1
_080C6E56:
	strb r0, [r1]
_080C6E58:
	ldr r1, _080C6E84 @ =0x000025FA
	adds r4, r7, r1
	ldrb r0, [r4]
	cmp r0, #0x95
	bls _080C6E8C
	ldr r2, _080C6E88 @ =FUN_080c718c
	movs r3, #1
	adds r0, r7, #0
	adds r0, #0xa3
	movs r1, #0
	strb r3, [r0]
	adds r0, #0x55
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r0, #0x1d
	strb r3, [r0]
	strb r1, [r4]
	b _080C716C
	.align 2, 0
_080C6E80: .4byte 0x0000260C
_080C6E84: .4byte 0x000025FA
_080C6E88: .4byte FUN_080c718c
_080C6E8C:
	mov r2, r8
	cmp r2, #0x59
	ble _080C6EE4
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _080C6ED4 @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0x2c
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _080C6EAC
	rsbs r1, r1, #0
_080C6EAC:
	cmp r1, #0x3f
	bgt _080C6EE4
	ldr r1, _080C6ED8 @ =0x00001909
	adds r0, r7, r1
	ldrb r1, [r0]
	ldr r2, _080C6EDC @ =0x00001908
	adds r0, r7, r2
	movs r2, #0
	strb r1, [r0]
	ldr r1, _080C6EE0 @ =FUN_080c73c0
	movs r0, #3
	adds r3, r7, #0
	adds r3, #0xa3
	strb r0, [r3]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r2, [r0]
	b _080C6F04
	.align 2, 0
_080C6ED4: .4byte 0x03002BE0
_080C6ED8: .4byte 0x00001909
_080C6EDC: .4byte 0x00001908
_080C6EE0: .4byte FUN_080c73c0
_080C6EE4:
	ldr r3, _080C6F10 @ =0x000008F9
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C6F18
	ldr r2, _080C6F14 @ =FUN_080c72f4
	movs r0, #2
	adds r3, r7, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r7, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
_080C6F04:
	adds r1, r7, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
	b _080C716C
	.align 2, 0
_080C6F10: .4byte 0x000008F9
_080C6F14: .4byte FUN_080c72f4
_080C6F18:
	ldr r0, _080C6F48 @ =0x000025D6
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080C6FE8
	adds r3, r0, #0
	ldr r2, _080C6F4C @ =0x085B0A08
	ldr r1, _080C6F50 @ =0x000025D5
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _080C6F54
	asrs r3, r0, #0xc
	b _080C6F5A
	.align 2, 0
_080C6F48: .4byte 0x000025D6
_080C6F4C: .4byte 0x085B0A08
_080C6F50: .4byte 0x000025D5
_080C6F54:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080C6F5A:
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r3, _080C6F84 @ =0x000002EA
	adds r0, r7, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r3, #8
	adds r0, r7, r3
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, r0, r2
	cmp r0, #0
	blt _080C6F88
	asrs r1, r0, #3
	b _080C6F8E
	.align 2, 0
_080C6F84: .4byte 0x000002EA
_080C6F88:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r1, r0, #0
_080C6F8E:
	ldr r2, _080C6FB4 @ =0x000002EA
	adds r0, r7, r2
	strh r1, [r0]
	ldr r3, _080C6FB8 @ =0x000025D6
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r2, _080C6FBC @ =0x000025D5
	adds r0, r7, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080C6FC0
	asrs r2, r0, #0xc
	b _080C6FC6
	.align 2, 0
_080C6FB4: .4byte 0x000002EA
_080C6FB8: .4byte 0x000025D6
_080C6FBC: .4byte 0x000025D5
_080C6FC0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C6FC6:
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r1, _080C6FE4 @ =0x000025D6
	adds r2, r7, r1
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _080C716C
	.align 2, 0
_080C6FE4: .4byte 0x000025D6
_080C6FE8:
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	subs r2, #8
	adds r0, r7, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r2, r1, r0
	movs r1, #0xbd
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #0xbb
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	cmp r2, #0
	bne _080C701A
	cmp r1, #0
	beq _080C7052
_080C701A:
	adds r0, r2, #0
	bl FUN_0823785c
	ldr r1, _080C7040 @ =0x000008F2
	adds r3, r7, r1
	ldrb r2, [r3]
	subs r0, r0, r2
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	cmp r0, #0x7f
	bgt _080C7048
	ldr r1, _080C7044 @ =0x0000260D
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, r2, r0
	b _080C7050
	.align 2, 0
_080C7040: .4byte 0x000008F2
_080C7044: .4byte 0x0000260D
_080C7048:
	ldr r1, _080C707C @ =0x0000260D
	adds r0, r7, r1
	ldrb r0, [r0]
	subs r0, r2, r0
_080C7050:
	strb r0, [r3]
_080C7052:
	ldr r2, _080C7080 @ =0x0000260E
	adds r0, r7, r2
	ldrh r3, [r0]
	ldr r2, _080C7084 @ =0x085B0A08
	ldr r1, _080C7088 @ =0x000008F2
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _080C708C
	asrs r3, r0, #0xc
	b _080C7092
	.align 2, 0
_080C707C: .4byte 0x0000260D
_080C7080: .4byte 0x0000260E
_080C7084: .4byte 0x085B0A08
_080C7088: .4byte 0x000008F2
_080C708C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080C7092:
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r3, _080C70BC @ =0x000002EA
	adds r0, r7, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r3, #8
	adds r0, r7, r3
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, r0, r2
	cmp r0, #0
	blt _080C70C0
	asrs r1, r0, #3
	b _080C70C6
	.align 2, 0
_080C70BC: .4byte 0x000002EA
_080C70C0:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r1, r0, #0
_080C70C6:
	ldr r2, _080C70EC @ =0x000002EA
	adds r0, r7, r2
	strh r1, [r0]
	ldr r3, _080C70F0 @ =0x0000260E
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r2, _080C70F4 @ =0x000008F2
	adds r0, r7, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080C70F8
	asrs r2, r0, #0xc
	b _080C70FE
	.align 2, 0
_080C70EC: .4byte 0x000002EA
_080C70F0: .4byte 0x0000260E
_080C70F4: .4byte 0x000008F2
_080C70F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C70FE:
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r1, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	movs r0, #0x3f
	mov r2, r8
	ands r0, r2
	cmp r0, #0
	bne _080C716C
	ldr r6, _080C7178 @ =0x0203B400
	ldr r4, _080C717C @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r5, _080C7180 @ =0x000003FF
	ands r1, r5
	str r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r6
	ldr r2, _080C7184 @ =0x03002BE0
	ldr r2, [r2]
	ldrb r3, [r0]
	ldrh r0, [r2, #0x2c]
	adds r0, r0, r3
	subs r0, #0x7f
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r2, r7, r3
	strh r0, [r2]
	ldr r2, _080C7188 @ =0x000002FA
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r0, #0x80
	adds r3, #2
	adds r2, r7, r3
	strh r0, [r2]
	adds r1, #1
	ands r1, r5
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	movs r1, #0xbf
	lsls r1, r1, #2
	adds r2, r7, r1
	subs r3, #0xf3
	adds r1, r3, #0
	ands r0, r1
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
_080C716C:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C7178: .4byte 0x0203B400
_080C717C: .4byte 0x030046B8
_080C7180: .4byte 0x000003FF
_080C7184: .4byte 0x03002BE0
_080C7188: .4byte 0x000002FA

	thumb_func_start FUN_080c718c
FUN_080c718c: @ 0x080C718C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r7, r0, #0
	adds r6, r1, #0
	adds r5, r7, #0
	movs r0, #0xa9
	adds r0, r0, r5
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C71F8
	movs r2, #0
	mov r1, r8
	strb r2, [r1]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r1, [r0]
	adds r3, #8
	adds r0, r5, r3
	movs r4, #0
	strh r1, [r0]
	ldr r1, _080C7234 @ =0x000002FA
	adds r0, r5, r1
	ldrh r0, [r0]
	adds r0, #0x80
	adds r3, #2
	adds r1, r5, r3
	strh r0, [r1]
	movs r1, #0xbf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	adds r0, #0x60
	adds r3, #2
	adds r1, r5, r3
	strh r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #1
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r3, #0
	bl FUN_08055b5c
	ldr r2, _080C7238 @ =0x000025FA
	adds r0, r5, r2
	strb r4, [r0]
_080C71F8:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _080C72DC
	adds r0, r5, #0
	bl FUN_080c4990
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	bl FUN_080c4a40
	cmp r6, #0x23
	bne _080C723C
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x13
	b _080C72A8
	.align 2, 0
_080C7234: .4byte 0x000002FA
_080C7238: .4byte 0x000025FA
_080C723C:
	cmp r6, #0x3c
	bne _080C7268
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #1
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x14
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	adds r0, r5, #0
	bl FUN_080c6b44
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r1, r5, r2
	b _080C728A
_080C7268:
	cmp r6, #0x6e
	bne _080C727A
	adds r0, r5, #0
	bl FUN_080c6b44
	movs r3, #0xbb
	lsls r3, r3, #2
	adds r1, r5, r3
	b _080C728A
_080C727A:
	cmp r6, #0xa0
	bne _080C7292
	adds r0, r5, #0
	bl FUN_080c6b44
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r1, r5, r0
_080C728A:
	ldrh r0, [r1]
	subs r0, #0x60
	strh r0, [r1]
	b _080C72DC
_080C7292:
	cmp r6, #0xad
	bne _080C72B2
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x15
_080C72A8:
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	b _080C72DC
_080C72B2:
	cmp r6, #0xd2
	bne _080C72DC
	ldr r2, _080C72E8 @ =0x00001909
	adds r0, r7, r2
	ldrb r1, [r0]
	ldr r3, _080C72EC @ =0x00001908
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _080C72F0 @ =FUN_080c73c0
	movs r0, #3
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	movs r0, #1
	mov r1, r8
	strb r0, [r1]
_080C72DC:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C72E8: .4byte 0x00001909
_080C72EC: .4byte 0x00001908
_080C72F0: .4byte FUN_080c73c0

	thumb_func_start FUN_080c72f4
FUN_080c72f4: @ 0x080C72F4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r7, r0, #0
	movs r0, #0xa9
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C736E
	movs r5, #0
	mov r1, r8
	strb r5, [r1]
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080C73B4 @ =0x000002F2
	adds r1, r7, r2
	adds r2, #0x2e
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r6, #1
	str r6, [sp]
	str r5, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	movs r1, #0x12
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r7, r2
	str r6, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0x19
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C736E:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C73A6
	ldr r1, _080C73B8 @ =0x000008F9
	adds r0, r7, r1
	ldrb r2, [r0]
	cmp r2, #0
	bne _080C73A0
	ldr r1, _080C73BC @ =FUN_080c6c8c
	adds r0, r7, #0
	adds r0, #0xa3
	strb r2, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r2, [r0]
	movs r0, #1
	mov r2, r8
	strb r0, [r2]
_080C73A0:
	adds r0, r7, #0
	bl FUN_080c4990
_080C73A6:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C73B4: .4byte 0x000002F2
_080C73B8: .4byte 0x000008F9
_080C73BC: .4byte FUN_080c6c8c

	thumb_func_start FUN_080c73c0
FUN_080c73c0: @ 0x080C73C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	mov sl, r1
	adds r7, r6, #0
	movs r0, #0xa9
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C7450
	movs r1, #0
	mov sb, r1
	mov r0, sb
	mov r2, r8
	strb r0, [r2]
	ldr r0, _080C74A8 @ =0x03002BE0
	ldr r0, [r0]
	ldrh r1, [r0, #0x2c]
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	movs r1, #0xbf
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	adds r0, #0x20
	adds r2, #4
	adds r1, r7, r2
	strh r0, [r1]
	ldr r1, _080C74AC @ =0x000002FA
	adds r0, r7, r1
	ldrh r0, [r0]
	adds r0, #0x80
	subs r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	movs r0, #0x89
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r5, #1
	str r5, [sp]
	mov r2, sb
	str r2, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	movs r1, #2
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r7, r1
	str r5, [sp]
	mov r2, sb
	str r2, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0x18
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C7450:
	adds r0, r6, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _080C7498
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r6, #0
	bl FUN_080c4990
	mov r0, sl
	cmp r0, #0x25
	ble _080C7498
	ldr r1, _080C74B0 @ =FUN_080c74b4
	movs r0, #4
	adds r2, r6, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	movs r0, #1
	mov r1, r8
	strb r0, [r1]
_080C7498:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C74A8: .4byte 0x03002BE0
_080C74AC: .4byte 0x000002FA
_080C74B0: .4byte FUN_080c74b4

	thumb_func_start FUN_080c74b4
FUN_080c74b4: @ 0x080C74B4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x60
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080c4a2c
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _080C750E
	cmp r5, #9
	ble _080C750E
	ldr r1, _080C7514 @ =FUN_080c7518
	movs r0, #5
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_080C750E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080C7514: .4byte FUN_080c7518

	thumb_func_start FUN_080c7518
FUN_080c7518: @ 0x080C7518
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r6, r0, #0
	mov r8, r1
	adds r5, r6, #0
	adds r7, r5, #0
	adds r7, #0xa9
	ldrb r0, [r7]
	cmp r0, #0
	beq _080C7572
	movs r4, #0
	strb r4, [r7]
	movs r0, #0xbf
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r2, #0xf4
	adds r1, r5, r2
	strh r0, [r1]
	ldr r0, _080C75C0 @ =0x000008F2
	adds r1, r5, r0
	movs r0, #0xc0
	strb r0, [r1]
	ldr r0, _080C75C4 @ =0x00000225
	bl PlaySound_082406e0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #3
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C7572:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _080C75E8
	mov r2, r8
	cmp r2, #9
	ble _080C7592
	adds r0, r5, #0
	bl FUN_080c4990
_080C7592:
	mov r0, r8
	cmp r0, #0xf
	ble _080C75E8
	ldr r2, _080C75C8 @ =0x00001908
	adds r1, r5, r2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _080C75D0
	ldr r1, _080C75CC @ =FUN_080c73c0
	movs r0, #3
	adds r2, r5, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	b _080C75E4
	.align 2, 0
_080C75C0: .4byte 0x000008F2
_080C75C4: .4byte 0x00000225
_080C75C8: .4byte 0x00001908
_080C75CC: .4byte FUN_080c73c0
_080C75D0:
	ldr r1, _080C75F4 @ =FUN_080c75f8
	movs r0, #6
	adds r2, r6, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
_080C75E4:
	movs r0, #1
	strb r0, [r7]
_080C75E8:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C75F4: .4byte FUN_080c75f8

	thumb_func_start FUN_080c75f8
FUN_080c75f8: @ 0x080C75F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	mov r8, r1
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C7662
	movs r4, #0
	strb r4, [r1]
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	subs r0, #0x80
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	ldr r3, _080C76AC @ =0x000008F2
	adds r1, r7, r3
	movs r0, #0xc0
	strb r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r6, #1
	str r6, [sp]
	str r4, [sp, #4]
	movs r5, #4
	str r5, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r7, r2
	str r6, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0x18
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	ldr r3, _080C76B0 @ =0x000025CA
	adds r0, r7, r3
	strh r4, [r0]
_080C7662:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _080C7678
	b _080C788C
_080C7678:
	ldr r1, _080C76B4 @ =0x0000191C
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _080C76BC
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r4, #1
	str r4, [sp]
	str r3, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #8
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	ldr r3, _080C76B8 @ =0x000025E8
	adds r0, r7, r3
	b _080C76E2
	.align 2, 0
_080C76AC: .4byte 0x000008F2
_080C76B0: .4byte 0x000025CA
_080C76B4: .4byte 0x0000191C
_080C76B8: .4byte 0x000025E8
_080C76BC:
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080C76E4
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, r1
	str r4, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xb
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	ldr r2, _080C777C @ =0x000025E8
	adds r0, r7, r2
_080C76E2:
	strh r4, [r0]
_080C76E4:
	ldr r3, _080C777C @ =0x000025E8
	adds r4, r7, r3
	ldrh r0, [r4]
	cmp r0, #0
	beq _080C7718
	adds r0, #1
	movs r5, #0
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _080C7718
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r1, #1
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	strh r5, [r4]
_080C7718:
	adds r0, r7, #0
	bl FUN_080c4990
	mov r2, r8
	cmp r2, #0x1e
	beq _080C7726
	b _080C788C
_080C7726:
	ldr r3, _080C7780 @ =0x0000190A
	adds r2, r7, r3
	ldrb r0, [r2]
	adds r0, #1
	movs r4, #0
	strb r0, [r2]
	adds r3, #1
	adds r1, r7, r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _080C77FC
	strb r4, [r2]
	ldr r1, _080C777C @ =0x000025E8
	adds r0, r7, r1
	strh r4, [r0]
	ldr r2, _080C7784 @ =0x0000260C
	adds r0, r7, r2
	ldrb r3, [r0]
	cmp r3, #0
	bne _080C77A8
	ldr r3, _080C7788 @ =0x000025EC
	adds r0, r7, r3
	strh r4, [r0]
	ldr r2, _080C778C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C7790 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080C7794 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r3, #1
	ands r0, r3
	cmp r0, #0
	beq _080C779C
	ldr r1, _080C7798 @ =FUN_080c86ac
	movs r0, #0x14
	b _080C77CE
	.align 2, 0
_080C777C: .4byte 0x000025E8
_080C7780: .4byte 0x0000190A
_080C7784: .4byte 0x0000260C
_080C7788: .4byte 0x000025EC
_080C778C: .4byte 0x030046B8
_080C7790: .4byte 0x000003FF
_080C7794: .4byte 0x0203B400
_080C7798: .4byte FUN_080c86ac
_080C779C:
	ldr r1, _080C77A4 @ =FUN_080c898c
	movs r0, #0x17
	b _080C77CE
	.align 2, 0
_080C77A4: .4byte FUN_080c898c
_080C77A8:
	cmp r3, #1
	bne _080C77E8
	ldr r2, _080C77C0 @ =0x000025C9
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C77C8
	movs r0, #0
	strb r0, [r1]
	ldr r1, _080C77C4 @ =FUN_080c7e54
	movs r0, #0xb
	b _080C77CE
	.align 2, 0
_080C77C0: .4byte 0x000025C9
_080C77C4: .4byte FUN_080c7e54
_080C77C8:
	strb r3, [r1]
	ldr r1, _080C77E4 @ =FUN_080c81e0
	movs r0, #0xf
_080C77CE:
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	adds r0, #0x1d
	strb r3, [r0]
	b _080C788C
	.align 2, 0
_080C77E4: .4byte FUN_080c81e0
_080C77E8:
	ldr r1, _080C77F8 @ =FUN_080c8cc8
	movs r0, #0x1b
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	b _080C787E
	.align 2, 0
_080C77F8: .4byte FUN_080c8cc8
_080C77FC:
	ldr r3, _080C7840 @ =0x0000260C
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #2
	bne _080C7874
	ldr r2, _080C7844 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C7848 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080C784C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq _080C7858
	ldr r1, _080C7850 @ =FUN_080c718c
	adds r0, r7, #0
	adds r0, #0xa3
	strb r2, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	adds r0, #0x1d
	strb r2, [r0]
	ldr r2, _080C7854 @ =0x000025FA
	adds r0, r7, r2
	strb r4, [r0]
	b _080C788C
	.align 2, 0
_080C7840: .4byte 0x0000260C
_080C7844: .4byte 0x030046B8
_080C7848: .4byte 0x000003FF
_080C784C: .4byte 0x0203B400
_080C7850: .4byte FUN_080c718c
_080C7854: .4byte 0x000025FA
_080C7858:
	ldr r1, _080C7870 @ =FUN_080c6c8c
	adds r0, r7, #0
	adds r0, #0xa3
	strb r4, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	adds r0, #0x1d
	strb r2, [r0]
	b _080C788C
	.align 2, 0
_080C7870: .4byte FUN_080c6c8c
_080C7874:
	ldr r1, _080C7898 @ =FUN_080c6c8c
	adds r0, r7, #0
	adds r0, #0xa3
	strb r4, [r0]
	adds r0, #0x55
_080C787E:
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	adds r1, r7, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_080C788C:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C7898: .4byte FUN_080c6c8c

	thumb_func_start FUN_080c789c
FUN_080c789c: @ 0x080C789C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r6, r0, #0
	mov r8, r1
	adds r5, r6, #0
	adds r7, r5, #0
	adds r7, #0xa9
	ldrb r0, [r7]
	cmp r0, #0
	beq _080C78DC
	movs r4, #0
	strb r4, [r7]
	ldr r1, _080C7964 @ =0x00001908
	adds r0, r5, r1
	strb r4, [r0]
	ldr r0, _080C7968 @ =0x00000225
	bl PlaySound_082406e0
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C78DC:
	movs r2, #0x80
	lsls r2, r2, #0xb
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r6, r0
	ldr r3, _080C796C @ =0xFFFF0000
	ldr r1, _080C7970 @ =0x000002EA
	adds r0, r6, r1
	ldrh r1, [r0]
	subs r1, #0x80
	lsls r1, r1, #0x10
	ldrh r0, [r2]
	orrs r0, r1
	str r0, [sp, #0x14]
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r2, #0xd5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x18]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x18]
	ldr r0, _080C7974 @ =0x03002BE0
	ldr r0, [r0]
	movs r5, #1
	str r5, [sp]
	movs r4, #0
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	str r4, [sp, #0x10]
	add r1, sp, #0x14
	movs r2, #0
	movs r3, #2
	bl FUN_0807ab64
	mov r0, r8
	cmp r0, #3
	ble _080C7956
	ldr r1, _080C7978 @ =FUN_080c797c
	movs r0, #8
	adds r2, r6, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	strb r5, [r7]
_080C7956:
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C7964: .4byte 0x00001908
_080C7968: .4byte 0x00000225
_080C796C: .4byte 0xFFFF0000
_080C7970: .4byte 0x000002EA
_080C7974: .4byte 0x03002BE0
_080C7978: .4byte FUN_080c797c

	thumb_func_start FUN_080c797c
FUN_080c797c: @ 0x080C797C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	mov r8, r1
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C79CC
	movs r2, #0
	strb r2, [r1]
	ldr r0, _080C7A14 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r1, [r0]
	ldr r3, _080C7A18 @ =0x0000192C
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _080C7A1C @ =0x0000192E
	adds r0, r5, r1
	strb r2, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r2, [r0]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #1
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #5
	movs r3, #0
	bl FUN_08055b5c
_080C79CC:
	ldr r2, _080C7A1C @ =0x0000192E
	adds r4, r5, r2
	ldrb r6, [r4]
	cmp r6, #0
	beq _080C7A28
	cmp r6, #1
	bne _080C79E0
	ldr r0, _080C7A20 @ =0x00000226
	bl PlaySound_082406e0
_080C79E0:
	ldrb r0, [r4]
	adds r0, #1
	movs r6, #0
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x17
	bls _080C7A48
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r1, #1
	str r1, [sp]
	str r6, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #5
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	strb r6, [r4]
	ldr r1, _080C7A24 @ =0x0000192F
	adds r0, r5, r1
	strb r6, [r0]
	b _080C7A48
	.align 2, 0
_080C7A14: .4byte 0x03002BE0
_080C7A18: .4byte 0x0000192C
_080C7A1C: .4byte 0x0000192E
_080C7A20: .4byte 0x00000226
_080C7A24: .4byte 0x0000192F
_080C7A28:
	ldr r2, _080C7A8C @ =0x0000192F
	adds r4, r5, r2
	ldrb r0, [r4]
	cmp r0, #0
	bne _080C7A38
	ldr r0, _080C7A90 @ =0x00000226
	bl PlaySound_082406e0
_080C7A38:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x27
	bls _080C7A48
	strb r6, [r4]
_080C7A48:
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r5, r3
	ldr r3, _080C7A94 @ =0xFFFF0000
	ldr r1, _080C7A98 @ =0x000002EA
	adds r0, r5, r1
	ldrh r1, [r0]
	subs r1, #0x80
	lsls r1, r1, #0x10
	ldrh r0, [r2]
	orrs r0, r1
	str r0, [sp, #0x14]
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #0xd5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x18]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x18]
	movs r0, #0xf
	mov r3, r8
	ands r0, r3
	cmp r0, #0
	beq _080C7A9C
	movs r1, #0
	b _080C7AA2
	.align 2, 0
_080C7A8C: .4byte 0x0000192F
_080C7A90: .4byte 0x00000226
_080C7A94: .4byte 0xFFFF0000
_080C7A98: .4byte 0x000002EA
_080C7A9C:
	ldr r1, _080C7B34 @ =0x0000192A
	adds r0, r5, r1
	ldrh r1, [r0]
_080C7AA2:
	ldr r4, _080C7B38 @ =0x03002BE0
	ldr r0, [r4]
	movs r6, #1
	str r6, [sp]
	movs r7, #0
	str r7, [sp, #4]
	str r6, [sp, #8]
	str r1, [sp, #0xc]
	str r7, [sp, #0x10]
	add r1, sp, #0x14
	movs r2, #0
	movs r3, #2
	bl FUN_0807ab64
	ldr r2, _080C7B3C @ =0x0000192C
	adds r0, r5, r2
	ldrb r1, [r0]
	ldr r0, [r4]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r0, [r0]
	ldr r2, _080C7B40 @ =0xFFFFFF00
	adds r1, r1, r2
	subs r4, r0, r1
	movs r0, #0xff
	ands r4, r0
	ldr r3, _080C7B44 @ =0x0000192D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r4, r0
	beq _080C7B0E
	cmp r4, #8
	beq _080C7AEA
	cmp r4, #0x10
	bne _080C7B08
_080C7AEA:
	ldr r1, _080C7B48 @ =0x0000192E
	adds r0, r5, r1
	strb r6, [r0]
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r5, r2
	str r6, [sp]
	str r7, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #6
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C7B08:
	ldr r3, _080C7B44 @ =0x0000192D
	adds r0, r5, r3
	strb r4, [r0]
_080C7B0E:
	ldr r2, _080C7B38 @ =0x03002BE0
	ldr r1, _080C7B3C @ =0x0000192C
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrb r0, [r0]
	ldr r3, _080C7B40 @ =0xFFFFFF00
	adds r1, r1, r3
	subs r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	cmp r0, #0x13
	ble _080C7B50
	ldr r2, _080C7B4C @ =FUN_080c7b84
	movs r0, #9
	b _080C7B5A
	.align 2, 0
_080C7B34: .4byte 0x0000192A
_080C7B38: .4byte 0x03002BE0
_080C7B3C: .4byte 0x0000192C
_080C7B40: .4byte 0xFFFFFF00
_080C7B44: .4byte 0x0000192D
_080C7B48: .4byte 0x0000192E
_080C7B4C: .4byte FUN_080c7b84
_080C7B50:
	mov r0, r8
	cmp r0, #0xb3
	ble _080C7B74
	ldr r2, _080C7B80 @ =FUN_080c7c20
	movs r0, #0xa
_080C7B5A:
	adds r3, r5, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_080C7B74:
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C7B80: .4byte FUN_080c7c20

	thumb_func_start FUN_080c7b84
FUN_080c7b84: @ 0x080C7B84
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r5, r0, #0
	adds r6, r1, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C7C02
	movs r4, #0
	strb r4, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x2d
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	ldr r0, _080C7C18 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x2c]
	ldr r2, [r0, #0x30]
	str r1, [sp, #0x10]
	str r2, [sp, #0x14]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r2, [r1]
	ldr r3, _080C7C1C @ =0xFFFF0000
	ldr r1, [sp, #0x10]
	ands r1, r3
	orrs r1, r2
	str r1, [sp, #0x10]
	movs r7, #0xbb
	lsls r7, r7, #2
	adds r2, r5, r7
	movs r7, #0xd5
	lsls r7, r7, #1
	adds r1, r7, #0
	ldrh r2, [r2]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, [sp, #0x14]
	ands r2, r3
	orrs r2, r1
	str r2, [sp, #0x14]
	movs r1, #0x20
	str r1, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	add r1, sp, #0x10
	movs r2, #0x64
	movs r3, #0x40
	bl FUN_0807ac74
_080C7C02:
	cmp r6, #0x2b
	ble _080C7C0E
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_080C7C0E:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C7C18: .4byte 0x03002BE0
_080C7C1C: .4byte 0xFFFF0000

	thumb_func_start FUN_080c7c20
FUN_080c7c20: @ 0x080C7C20
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r1, #0
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C7C56
	movs r4, #0
	strb r4, [r1]
	ldr r0, _080C7C70 @ =0x00000227
	bl PlaySound_082406e0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #7
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C7C56:
	cmp r6, #0x10
	bne _080C7C74
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x1a
	b _080C7DE2
	.align 2, 0
_080C7C70: .4byte 0x00000227
_080C7C74:
	cmp r6, #0x14
	bne _080C7C8E
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	b _080C7DE2
_080C7C8E:
	cmp r6, #0x18
	bne _080C7CAE
	movs r2, #0x86
	lsls r2, r2, #3
	adds r0, r5, r2
	adds r2, #0x95
	adds r1, r5, r2
	ldrb r2, [r1]
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #1
	b _080C7DE4
_080C7CAE:
	cmp r6, #0x1c
	bne _080C7CC8
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x17
	b _080C7DE2
_080C7CC8:
	cmp r6, #0x20
	bne _080C7CE8
	movs r2, #0x99
	lsls r2, r2, #3
	adds r0, r5, r2
	adds r2, #0x95
	adds r1, r5, r2
	ldrb r2, [r1]
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #1
	b _080C7DE4
_080C7CE8:
	cmp r6, #0x24
	bne _080C7D28
	movs r1, #0x86
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r2, _080C7D20 @ =0x000004C5
	adds r1, r5, r2
	ldrb r2, [r1]
	movs r1, #2
	str r1, [sp]
	movs r4, #0
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	movs r3, #0
	bl FUN_08055b5c
	ldr r0, _080C7D24 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r0, r1
	strh r4, [r0]
	movs r0, #0xe7
	bl PlaySound_082406e0
	b _080C7DFC
	.align 2, 0
_080C7D20: .4byte 0x000004C5
_080C7D24: .4byte 0x03002BE0
_080C7D28:
	cmp r6, #0x28
	bne _080C7D48
	movs r2, #0xac
	lsls r2, r2, #3
	adds r0, r5, r2
	adds r2, #0x95
	adds r1, r5, r2
	ldrb r2, [r1]
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #1
	b _080C7DE4
_080C7D48:
	cmp r6, #0x2c
	bne _080C7D6C
	movs r1, #0x99
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r2, _080C7D68 @ =0x0000055D
	adds r1, r5, r2
	ldrb r2, [r1]
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	b _080C7DE4
	.align 2, 0
_080C7D68: .4byte 0x0000055D
_080C7D6C:
	cmp r6, #0x34
	bne _080C7D90
	movs r1, #0xac
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r2, _080C7D8C @ =0x000005F5
	adds r1, r5, r2
	ldrb r2, [r1]
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0
	b _080C7DE4
	.align 2, 0
_080C7D8C: .4byte 0x000005F5
_080C7D90:
	cmp r6, #0x46
	bne _080C7DAA
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x16
	b _080C7DE2
_080C7DAA:
	cmp r6, #0x9e
	bne _080C7DC4
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #1
	b _080C7DE2
_080C7DC4:
	cmp r6, #0xa8
	bne _080C7DF0
	ldr r0, _080C7DEC @ =0x00000231
	bl PlaySound_082406e0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #1
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #2
_080C7DE2:
	movs r2, #0
_080C7DE4:
	movs r3, #0
	bl FUN_08055b5c
	b _080C7DFC
	.align 2, 0
_080C7DEC: .4byte 0x00000231
_080C7DF0:
	cmp r6, #0xa8
	ble _080C7DFC
	adds r0, r5, #0
	movs r1, #0x10
	bl FUN_080c4a54
_080C7DFC:
	cmp r6, #0xbe
	bne _080C7E3A
	ldr r4, _080C7E44 @ =0x03002BE0
	ldr r0, [r4]
	bl FUN_0807e854
	ldr r0, [r4]
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r2, #0
	movs r1, #0x1a
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _080C7E48 @ =0x0000037D
	adds r0, r0, r1
	movs r1, #5
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _080C7E4C @ =0x0000037E
	adds r0, r0, r1
	strh r2, [r0]
	ldr r0, [r4]
	subs r1, #0x1a
	adds r0, r0, r1
	strh r2, [r0]
	ldr r2, _080C7E50 @ =0x030047A4
	ldr r0, [r2]
	adds r1, #0x9c
	orrs r0, r1
	str r0, [r2]
_080C7E3A:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C7E44: .4byte 0x03002BE0
_080C7E48: .4byte 0x0000037D
_080C7E4C: .4byte 0x0000037E
_080C7E50: .4byte 0x030047A4

	thumb_func_start FUN_080c7e54
FUN_080c7e54: @ 0x080C7E54
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	mov sl, r1
	mov r7, r8
	movs r0, #0xa9
	adds r0, r0, r7
	mov sb, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C7ED2
	movs r5, #0
	mov r1, sb
	strb r5, [r1]
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, _080C7F2C @ =0x000002F2
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #0x60
	strh r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r6, #1
	str r6, [sp]
	str r5, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r7, r1
	str r6, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0x18
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C7ED2:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _080C7F1C
	adds r0, r7, #0
	bl FUN_080c4990
	mov r0, sl
	cmp r0, #0x3c
	ble _080C7EFC
	adds r0, r7, #0
	movs r1, #0
	movs r2, #1
	bl FUN_080c4a40
_080C7EFC:
	mov r1, sl
	cmp r1, #0x59
	ble _080C7F1C
	ldr r1, _080C7F30 @ =FUN_080c7f34
	movs r0, #0xc
	mov r2, r8
	adds r2, #0xa3
	strb r0, [r2]
	mov r0, r8
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	movs r0, #1
	mov r1, sb
	strb r0, [r1]
_080C7F1C:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C7F2C: .4byte 0x000002F2
_080C7F30: .4byte FUN_080c7f34

	thumb_func_start FUN_080c7f34
FUN_080c7f34: @ 0x080C7F34
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov sb, r1
	adds r6, r7, #0
	movs r0, #0xa9
	adds r0, r0, r6
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C7FB2
	movs r4, #0
	mov r1, r8
	strb r4, [r1]
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, _080C8004 @ =0x000002F2
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #0x60
	strh r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	movs r5, #4
	str r5, [sp, #8]
	movs r1, #0x13
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #1
	str r1, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0x18
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C7FB2:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _080C7FF6
	adds r0, r7, #0
	bl FUN_080c4990
	adds r0, r7, #0
	movs r1, #0
	movs r2, #1
	bl FUN_080c4a40
	mov r0, sb
	cmp r0, #0x18
	ble _080C7FF6
	ldr r1, _080C8008 @ =FUN_080c800c
	movs r0, #0xd
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	movs r0, #1
	mov r1, r8
	strb r0, [r1]
_080C7FF6:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C8004: .4byte 0x000002F2
_080C8008: .4byte FUN_080c800c

	thumb_func_start FUN_080c800c
FUN_080c800c: @ 0x080C800C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	mov sb, r1
	adds r7, r0, #0
	movs r0, #0xa9
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C80A4
	movs r6, #0
	mov r1, r8
	strb r6, [r1]
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r2, r7, r3
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080C8138 @ =0x000002F2
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	adds r3, #4
	adds r1, r7, r3
	ldrh r0, [r1]
	adds r0, #0x60
	strh r0, [r1]
	ldr r2, _080C813C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C8140 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080C8144 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #6
	bl Mod
	ldr r2, _080C8148 @ =0x000025FC
	adds r1, r7, r2
	strb r0, [r1]
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r5, #1
	str r5, [sp]
	str r6, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	movs r1, #0x14
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r7, r1
	str r5, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0x18
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C80A4:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _080C8184
	mov r0, sb
	movs r1, #0x32
	bl Mod
	cmp r0, #0
	bne _080C80D6
	adds r0, r7, #0
	bl FUN_080c6b44
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r1, r7, r2
	ldrh r0, [r1]
	subs r0, #0x60
	strh r0, [r1]
_080C80D6:
	adds r0, r7, #0
	bl FUN_080c4990
	ldr r0, _080C814C @ =0x03002BE0
	ldr r2, [r0]
	movs r3, #0x2c
	ldrsh r1, [r2, r3]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _080C80F6
	rsbs r1, r1, #0
_080C80F6:
	cmp r1, #0x7f
	bgt _080C8160
	movs r0, #0x30
	ldrsh r1, [r2, r0]
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	ldr r0, _080C8150 @ =0x0000031F
	cmp r1, r0
	bgt _080C8160
	ldr r1, _080C8154 @ =0x00001909
	adds r0, r7, r1
	ldrb r1, [r0]
	ldr r2, _080C8158 @ =0x00001908
	adds r0, r7, r2
	strb r1, [r0]
	ldr r1, _080C815C @ =FUN_080c73c0
	movs r0, #3
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	movs r0, #1
	mov r3, r8
	strb r0, [r3]
	b _080C8184
	.align 2, 0
_080C8138: .4byte 0x000002F2
_080C813C: .4byte 0x030046B8
_080C8140: .4byte 0x000003FF
_080C8144: .4byte 0x0203B400
_080C8148: .4byte 0x000025FC
_080C814C: .4byte 0x03002BE0
_080C8150: .4byte 0x0000031F
_080C8154: .4byte 0x00001909
_080C8158: .4byte 0x00001908
_080C815C: .4byte FUN_080c73c0
_080C8160:
	ldr r0, _080C8194 @ =0x000001C1
	cmp sb, r0
	ble _080C8184
	ldr r2, _080C8198 @ =FUN_080c819c
	movs r0, #0xe
	adds r3, r7, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r7, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_080C8184:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C8194: .4byte 0x000001C1
_080C8198: .4byte FUN_080c819c

	thumb_func_start FUN_080c819c
FUN_080c819c: @ 0x080C819C
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r1, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C81CA
	movs r2, #0
	strb r2, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x15
	movs r3, #0
	bl FUN_08055b5c
_080C81CA:
	cmp r5, #0x24
	ble _080C81D6
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_080C81D6:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080c81e0
FUN_080c81e0: @ 0x080C81E0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	mov r8, r1
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C8266
	movs r6, #0
	strb r6, [r1]
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080C82B0 @ =0x000002F2
	adds r1, r7, r2
	movs r3, #0xa0
	lsls r3, r3, #2
	adds r0, r3, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r3, #0x74
	adds r1, r7, r3
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	movs r0, #0x8c
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r5, #1
	str r5, [sp]
	str r6, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r7, r2
	str r5, [sp]
	str r6, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0x19
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C8266:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C833E
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r2, r7, r3
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080C82B4 @ =0x085B0A08
	mov r3, r8
	lsls r0, r3, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _080C82B8
	asrs r3, r0, #0xc
	b _080C82BE
	.align 2, 0
_080C82B0: .4byte 0x000002F2
_080C82B4: .4byte 0x085B0A08
_080C82B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080C82BE:
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	mov r1, r8
	lsls r0, r1, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #6
	cmp r0, #0
	blt _080C82E4
	asrs r2, r0, #0xc
	b _080C82EA
_080C82E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C82EA:
	ldr r3, _080C834C @ =0x000002F2
	adds r1, r7, r3
	subs r3, #0x72
	adds r0, r3, #0
	ldrh r3, [r1]
	adds r0, r0, r3
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_080c4990
	ldr r1, _080C8350 @ =0x00000DBC
	adds r0, r7, r1
	movs r3, #1
	strb r3, [r0]
	mov r2, r8
	cmp r2, #0x7f
	ble _080C833E
	ldr r1, _080C8354 @ =FUN_080c8358
	movs r0, #0x10
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0x8c
	movs r0, #0
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xa9
	strb r3, [r0]
_080C833E:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C834C: .4byte 0x000002F2
_080C8350: .4byte 0x00000DBC
_080C8354: .4byte FUN_080c8358

	thumb_func_start FUN_080c8358
FUN_080c8358: @ 0x080C8358
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	mov sl, r1
	adds r7, r5, #0
	movs r0, #0xa9
	adds r0, r0, r7
	mov sb, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C83E0
	movs r1, #0
	mov r8, r1
	mov r0, r8
	mov r2, sb
	strb r0, [r2]
	movs r1, #0xbc
	lsls r1, r1, #2
	adds r2, r7, r1
	adds r1, #8
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080C842C @ =0x000002F2
	adds r1, r7, r2
	adds r2, #0x2e
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r6, #1
	str r6, [sp]
	mov r2, r8
	str r2, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	movs r1, #0x11
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r7, r1
	str r6, [sp]
	mov r2, r8
	str r2, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0x19
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C83E0:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _080C841A
	adds r0, r5, #0
	bl FUN_080c4990
	mov r0, sl
	cmp r0, #0x3b
	ble _080C841A
	ldr r1, _080C8430 @ =FUN_080c8434
	movs r0, #0x11
	adds r2, r5, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	movs r0, #1
	mov r1, sb
	strb r0, [r1]
_080C841A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C842C: .4byte 0x000002F2
_080C8430: .4byte FUN_080c8434

	thumb_func_start FUN_080c8434
FUN_080c8434: @ 0x080C8434
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov sb, r1
	adds r6, r7, #0
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C84CC
	movs r0, #0
	mov r8, r0
	mov r2, r8
	strb r2, [r1]
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r2, r6, r3
	ldr r0, _080C8518 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r4, _080C851C @ =0x000002FA
	adds r0, r6, r4
	ldrh r0, [r0]
	adds r0, #0x80
	ldr r2, _080C8520 @ =0x000002F2
	adds r1, r6, r2
	strh r0, [r1]
	adds r3, #4
	adds r2, r6, r3
	ldr r4, _080C8524 @ =0xFFFFFC00
	adds r0, r4, #0
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	adds r3, #8
	adds r1, r6, r3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r3, [r1]
	movs r4, #0
	ldrsh r1, [r1, r4]
	cmp r0, r1
	bge _080C8498
	strh r3, [r2]
_080C8498:
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r5, #1
	str r5, [sp]
	mov r2, r8
	str r2, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	movs r3, #0xe6
	lsls r3, r3, #2
	adds r0, r6, r3
	str r5, [sp]
	mov r1, r8
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0x18
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C84CC:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _080C8508
	adds r0, r6, #0
	bl FUN_080c4990
	mov r2, sb
	cmp r2, #0x11
	ble _080C8508
	ldr r1, _080C8528 @ =FUN_080c852c
	movs r0, #0x12
	adds r2, r6, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	adds r1, r6, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_080C8508:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C8518: .4byte 0x03002BE0
_080C851C: .4byte 0x000002FA
_080C8520: .4byte 0x000002F2
_080C8524: .4byte 0xFFFFFC00
_080C8528: .4byte FUN_080c852c

	thumb_func_start FUN_080c852c
FUN_080c852c: @ 0x080C852C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	mov sl, r1
	mov r7, sb
	movs r0, #0xa9
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C8588
	movs r4, #0
	mov r1, r8
	strb r4, [r1]
	movs r0, #0x89
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r6, #1
	str r6, [sp]
	str r4, [sp, #4]
	movs r5, #4
	str r5, [sp, #8]
	movs r1, #2
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r7, r1
	str r6, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0x18
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C8588:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
	cmp r0, #0
	bne _080C8618
	ldr r0, _080C8628 @ =0x03002BE0
	ldr r1, [r0]
	ldr r2, _080C862C @ =0x000002FA
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r0, #0x80
	lsls r0, r0, #0x10
	ldr r3, [r1, #0x2c]
	ldr r4, [r1, #0x30]
	ldrh r1, [r1, #0x2c]
	adds r3, r1, #0
	orrs r3, r0
	ldr r6, _080C8630 @ =0xFFFFFC00
	adds r1, r4, r6
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	ldr r5, _080C8634 @ =0xFFFF0000
	adds r2, r5, #0
	ands r2, r4
	orrs r2, r0
	adds r4, r2, #0
	movs r6, #0xbf
	lsls r6, r6, #2
	adds r0, r7, r6
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	cmp r1, r0
	bge _080C85DE
	lsrs r0, r0, #0x10
	ands r2, r5
	adds r4, r2, #0
	orrs r4, r0
_080C85DE:
	movs r1, #0xbc
	lsls r1, r1, #2
	adds r0, r7, r1
	str r3, [r0]
	str r4, [r0, #4]
	ldr r2, _080C8638 @ =0x00000DBC
	adds r1, r7, r2
	movs r0, #2
	strb r0, [r1]
	ldr r0, _080C863C @ =0x0000012B
	cmp sl, r0
	ble _080C8612
	ldr r1, _080C8640 @ =FUN_080c8644
	movs r0, #0x13
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	mov r6, ip
	str r6, [r0]
	movs r0, #1
	mov r1, r8
	strb r0, [r1]
_080C8612:
	mov r0, sb
	bl FUN_080c4990
_080C8618:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C8628: .4byte 0x03002BE0
_080C862C: .4byte 0x000002FA
_080C8630: .4byte 0xFFFFFC00
_080C8634: .4byte 0xFFFF0000
_080C8638: .4byte 0x00000DBC
_080C863C: .4byte 0x0000012B
_080C8640: .4byte FUN_080c8644

	thumb_func_start FUN_080c8644
FUN_080c8644: @ 0x080C8644
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	adds r1, r4, #0
	adds r5, r1, #0
	adds r5, #0xa9
	ldrb r0, [r5]
	cmp r0, #0
	beq _080C8674
	movs r2, #0
	strb r2, [r5]
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r0, r1, r3
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #3
	movs r3, #0
	bl FUN_08055b5c
_080C8674:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080C86A0
	cmp r6, #0xf
	ble _080C86A0
	ldr r1, _080C86A8 @ =FUN_080c6c8c
	adds r0, r4, #0
	adds r0, #0xa3
	strb r2, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r2, [r0]
	movs r0, #1
	strb r0, [r5]
_080C86A0:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C86A8: .4byte FUN_080c6c8c

	thumb_func_start FUN_080c86ac
FUN_080c86ac: @ 0x080C86AC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	mov sl, r1
	mov r6, r8
	movs r0, #0xa9
	adds r0, r0, r6
	mov sb, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C8730
	movs r4, #0
	mov r1, sb
	strb r4, [r1]
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080C87C0 @ =0x000002F2
	adds r1, r6, r2
	adds r2, #0x2e
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	movs r5, #4
	str r5, [sp, #8]
	movs r1, #0x2f
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r6, r2
	movs r1, #1
	str r1, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0x11
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C8730:
	adds r0, r6, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	bne _080C87AE
	movs r2, #0x80
	lsls r2, r2, #0x18
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r0, sl
	cmp r0, #5
	ble _080C8788
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r5, #1
	str r5, [sp]
	str r7, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	movs r1, #0x12
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r6, r2
	str r5, [sp]
	str r7, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0x19
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C8788:
	mov r0, r8
	bl FUN_080c4990
	mov r0, sl
	cmp r0, #0x29
	ble _080C87AE
	ldr r1, _080C87C4 @ =FUN_080c87c8
	movs r0, #0x15
	mov r2, r8
	adds r2, #0xa3
	strb r0, [r2]
	mov r0, r8
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r7, [r0]
	movs r0, #1
	mov r1, sb
	strb r0, [r1]
_080C87AE:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C87C0: .4byte 0x000002F2
_080C87C4: .4byte FUN_080c87c8

	thumb_func_start FUN_080c87c8
FUN_080c87c8: @ 0x080C87C8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r7, r1, #0
	adds r1, r4, #0
	adds r5, r1, #0
	adds r5, #0xa9
	ldrb r0, [r5]
	cmp r0, #0
	beq _080C87F8
	movs r2, #0
	strb r2, [r5]
	movs r3, #0xd2
	lsls r3, r3, #3
	adds r0, r1, r3
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x30
	movs r3, #0
	bl FUN_08055b5c
_080C87F8:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _080C883C
	movs r2, #0x80
	lsls r2, r2, #0x18
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_080c4990
	cmp r7, #0x64
	ble _080C883C
	ldr r1, _080C8844 @ =FUN_080c8848
	movs r0, #0x16
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	movs r0, #1
	strb r0, [r5]
_080C883C:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C8844: .4byte FUN_080c8848

	thumb_func_start FUN_080c8848
FUN_080c8848: @ 0x080C8848
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	mov r8, r0
	mov sb, r1
	mov r5, r8
	adds r7, r5, #0
	adds r7, #0xa9
	ldrb r0, [r7]
	cmp r0, #0
	beq _080C889E
	movs r4, #0
	strb r4, [r7]
	ldr r0, _080C8908 @ =0x03002BE0
	ldr r1, [r0]
	movs r2, #0x2c
	ldrsh r0, [r1, r2]
	ldr r2, _080C890C @ =0xFFFFFAEC
	adds r0, r0, r2
	movs r2, #0x30
	ldrsh r1, [r1, r2]
	ldr r2, _080C8910 @ =0xFFFFFE00
	adds r1, r1, r2
	bl FUN_0823785c
	ldr r2, _080C8914 @ =0x000025EE
	adds r1, r5, r2
	strh r0, [r1]
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x32
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C889E:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _080C897A
	movs r2, #0x80
	lsls r2, r2, #0x18
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r2, sb
	cmp r2, #5
	bne _080C88D4
	ldr r1, _080C8914 @ =0x000025EE
	adds r0, r5, r1
	ldrh r2, [r0]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080c35f0
_080C88D4:
	mov r2, sb
	cmp r2, #0x59
	ble _080C897A
	ldr r0, _080C8918 @ =0x000025EC
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _080C8920
	ldr r1, _080C891C @ =FUN_080c8c4c
	movs r0, #0x1a
	adds r2, r5, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	movs r0, #1
	strb r0, [r7]
	b _080C897A
	.align 2, 0
_080C8908: .4byte 0x03002BE0
_080C890C: .4byte 0xFFFFFAEC
_080C8910: .4byte 0xFFFFFE00
_080C8914: .4byte 0x000025EE
_080C8918: .4byte 0x000025EC
_080C891C: .4byte FUN_080c8c4c
_080C8920:
	ldr r2, _080C8954 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C8958 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080C895C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r3, r0, #3
	movs r4, #1
	ands r3, r4
	cmp r3, #0
	beq _080C8964
	ldr r1, _080C8960 @ =FUN_080c87c8
	movs r0, #0x15
	adds r2, r5, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	b _080C8978
	.align 2, 0
_080C8954: .4byte 0x030046B8
_080C8958: .4byte 0x000003FF
_080C895C: .4byte 0x0203B400
_080C8960: .4byte FUN_080c87c8
_080C8964:
	ldr r1, _080C8988 @ =FUN_080c8aa8
	movs r0, #0x18
	mov r2, r8
	adds r2, #0xa3
	strb r0, [r2]
	mov r0, r8
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
_080C8978:
	strb r4, [r7]
_080C897A:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C8988: .4byte FUN_080c8aa8

	thumb_func_start FUN_080c898c
FUN_080c898c: @ 0x080C898C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	mov sl, r1
	mov r6, r8
	movs r0, #0xa9
	adds r0, r0, r6
	mov sb, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C8A10
	movs r4, #0
	mov r1, sb
	strb r4, [r1]
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080C8AA0 @ =0x000002F2
	adds r1, r6, r2
	adds r2, #0x2e
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	movs r5, #4
	str r5, [sp, #8]
	movs r1, #0x2f
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r6, r2
	movs r1, #1
	str r1, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0x11
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C8A10:
	adds r0, r6, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	bne _080C8A8E
	movs r2, #0x80
	lsls r2, r2, #0x18
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r0, sl
	cmp r0, #5
	ble _080C8A68
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r5, #1
	str r5, [sp]
	str r7, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	movs r1, #0x12
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r6, r2
	str r5, [sp]
	str r7, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0x19
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C8A68:
	mov r0, r8
	bl FUN_080c4990
	mov r0, sl
	cmp r0, #0x29
	ble _080C8A8E
	ldr r1, _080C8AA4 @ =FUN_080c8aa8
	movs r0, #0x18
	mov r2, r8
	adds r2, #0xa3
	strb r0, [r2]
	mov r0, r8
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r7, [r0]
	movs r0, #1
	mov r1, sb
	strb r0, [r1]
_080C8A8E:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C8AA0: .4byte 0x000002F2
_080C8AA4: .4byte FUN_080c8aa8

	thumb_func_start FUN_080c8aa8
FUN_080c8aa8: @ 0x080C8AA8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r7, r1, #0
	adds r1, r4, #0
	adds r5, r1, #0
	adds r5, #0xa9
	ldrb r0, [r5]
	cmp r0, #0
	beq _080C8AD8
	movs r2, #0
	strb r2, [r5]
	movs r3, #0xd2
	lsls r3, r3, #3
	adds r0, r1, r3
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x31
	movs r3, #0
	bl FUN_08055b5c
_080C8AD8:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _080C8B1C
	movs r2, #0x80
	lsls r2, r2, #0x18
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_080c4990
	cmp r7, #0x64
	ble _080C8B1C
	ldr r1, _080C8B24 @ =FUN_080c8b28
	movs r0, #0x19
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	movs r0, #1
	strb r0, [r5]
_080C8B1C:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C8B24: .4byte FUN_080c8b28

	thumb_func_start FUN_080c8b28
FUN_080c8b28: @ 0x080C8B28
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r7, r0, #0
	adds r5, r1, #0
	adds r4, r7, #0
	movs r0, #0xa9
	adds r0, r0, r4
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C8B68
	movs r2, #0
	mov r1, r8
	strb r2, [r1]
	ldr r0, _080C8BD0 @ =0x000025EE
	adds r1, r4, r0
	movs r0, #8
	strh r0, [r1]
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x33
	movs r3, #0
	bl FUN_08055b5c
_080C8B68:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _080C8C3C
	movs r2, #0x80
	lsls r2, r2, #0x18
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	cmp r5, #5
	bne _080C8B9C
	ldr r1, _080C8BD0 @ =0x000025EE
	adds r0, r4, r1
	ldrh r2, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080c35f0
_080C8B9C:
	cmp r5, #0x59
	ble _080C8C3C
	ldr r0, _080C8BD4 @ =0x000025EC
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _080C8BDC
	ldr r1, _080C8BD8 @ =FUN_080c8c4c
	movs r0, #0x1a
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	movs r0, #1
	mov r1, r8
	strb r0, [r1]
	b _080C8C3C
	.align 2, 0
_080C8BD0: .4byte 0x000025EE
_080C8BD4: .4byte 0x000025EC
_080C8BD8: .4byte FUN_080c8c4c
_080C8BDC:
	ldr r2, _080C8C14 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C8C18 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080C8C1C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r3, r0, #3
	movs r5, #1
	ands r3, r5
	cmp r3, #0
	beq _080C8C24
	ldr r1, _080C8C20 @ =FUN_080c87c8
	movs r0, #0x15
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	mov r0, r8
	strb r5, [r0]
	b _080C8C3C
	.align 2, 0
_080C8C14: .4byte 0x030046B8
_080C8C18: .4byte 0x000003FF
_080C8C1C: .4byte 0x0203B400
_080C8C20: .4byte FUN_080c87c8
_080C8C24:
	ldr r1, _080C8C48 @ =FUN_080c8aa8
	movs r0, #0x18
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	mov r1, r8
	strb r5, [r1]
_080C8C3C:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C8C48: .4byte FUN_080c8aa8

	thumb_func_start FUN_080c8c4c
FUN_080c8c4c: @ 0x080C8C4C
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	adds r1, r4, #0
	adds r5, r1, #0
	adds r5, #0xa9
	ldrb r0, [r5]
	cmp r0, #0
	beq _080C8C7C
	movs r2, #0
	strb r2, [r5]
	movs r3, #0xd2
	lsls r3, r3, #3
	adds r0, r1, r3
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x34
	movs r3, #0
	bl FUN_08055b5c
_080C8C7C:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _080C8CBC
	movs r0, #0x80
	lsls r0, r0, #0x18
	adds r2, r4, #0
	adds r2, #0x98
	ldr r1, [r2]
	orrs r1, r0
	str r1, [r2]
	cmp r6, #0x2f
	ble _080C8CBC
	subs r0, #1
	ands r1, r0
	str r1, [r2]
	ldr r1, _080C8CC4 @ =FUN_080c6c8c
	adds r0, r4, #0
	adds r0, #0xa3
	strb r3, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	movs r0, #1
	strb r0, [r5]
_080C8CBC:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C8CC4: .4byte FUN_080c6c8c

	thumb_func_start FUN_080c8cc8
FUN_080c8cc8: @ 0x080C8CC8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	mov sb, r0
	mov r8, r1
	mov r6, sb
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C8D2C
	movs r3, #0
	strb r3, [r1]
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080C8DA8 @ =0x000002F2
	adds r1, r6, r2
	adds r2, #0x2e
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #1
	str r1, [sp]
	str r3, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x11
	movs r2, #0
	bl FUN_08055b5c
_080C8D2C:
	adds r0, r6, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	bne _080C8D98
	movs r2, #0x80
	lsls r2, r2, #0x18
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r2, r8
	cmp r2, #5
	ble _080C8D84
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r5, #1
	str r5, [sp]
	str r7, [sp, #4]
	movs r4, #4
	str r4, [sp, #8]
	movs r1, #0x12
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r6, r2
	str r5, [sp]
	str r7, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0x19
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C8D84:
	mov r0, r8
	cmp r0, #0x13
	ble _080C8D92
	adds r1, r6, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_080C8D92:
	mov r0, sb
	bl FUN_080c4990
_080C8D98:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C8DA8: .4byte 0x000002F2

	thumb_func_start FUN_080c8dac
FUN_080c8dac: @ 0x080C8DAC
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r5, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C8DDC
	movs r2, #0
	strb r2, [r1]
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x2a
	movs r3, #0
	bl FUN_08055b5c
_080C8DDC:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C8E0C
	movs r2, #0x80
	lsls r2, r2, #0x18
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	cmp r6, #0x83
	ble _080C8E06
	adds r1, #0xf
	movs r0, #1
	strb r0, [r1]
_080C8E06:
	adds r0, r5, #0
	bl FUN_080c4990
_080C8E0C:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c8e14
FUN_080c8e14: @ 0x080C8E14
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r1, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C8E62
	movs r4, #0
	strb r4, [r1]
	ldr r0, _080C8E90 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xf0
	bl FUN_0807ad60
	ldr r1, _080C8E94 @ =0x00001844
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x48
	ldrh r1, [r1]
	bl FUN_080c3528
	ldr r0, _080C8E98 @ =0x0000022B
	bl PlaySound_082406e0
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #1
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x2b
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C8E62:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C8EB0
	movs r2, #0x80
	lsls r2, r2, #0x18
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	cmp r6, #0x2f
	bgt _080C8E9C
	movs r0, #0x40
	bl FUN_0823b9cc
	b _080C8EA4
	.align 2, 0
_080C8E90: .4byte 0x03002BE0
_080C8E94: .4byte 0x00001844
_080C8E98: .4byte 0x0000022B
_080C8E9C:
	movs r0, #0x70
	subs r0, r0, r6
	bl FUN_0823b9cc
_080C8EA4:
	cmp r6, #0x4e
	ble _080C8EB0
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_080C8EB0:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c8eb8
FUN_080c8eb8: @ 0x080C8EB8
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r1, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C8EE6
	movs r2, #0
	strb r2, [r1]
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x2c
	movs r3, #0
	bl FUN_08055b5c
_080C8EE6:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C8F18
	movs r0, #0x80
	lsls r0, r0, #0x18
	adds r2, r4, #0
	adds r2, #0x98
	ldr r1, [r2]
	orrs r1, r0
	str r1, [r2]
	cmp r5, #0x90
	ble _080C8F18
	subs r0, #1
	ands r1, r0
	str r1, [r2]
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_080C8F18:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080c8f20
FUN_080c8f20: @ 0x080C8F20
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	mov r8, r1
	adds r4, r5, #0
	adds r6, r4, #0
	adds r6, #0xa9
	ldrb r0, [r6]
	cmp r0, #0
	beq _080C8F54
	movs r2, #0
	strb r2, [r6]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xb
	movs r3, #0
	bl FUN_08055b5c
_080C8F54:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	bne _080C8FCE
	movs r2, #0x80
	lsls r2, r2, #0xf
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080C8FA8 @ =0x000002EA
	adds r3, r4, r0
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080C8FAC @ =0x000002FA
	adds r2, r4, r0
	movs r4, #0
	ldrsh r0, [r2, r4]
	adds r0, #0x14
	cmp r1, r0
	ble _080C8FB0
	ldrh r1, [r3]
	subs r1, #0x1e
	strh r1, [r3]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r4, #0
	ldrsh r0, [r2, r4]
	adds r0, #0x14
	cmp r1, r0
	bge _080C8FCE
	ldrh r0, [r2]
	adds r0, #0x14
	strh r0, [r3]
	b _080C8FCE
	.align 2, 0
_080C8FA8: .4byte 0x000002EA
_080C8FAC: .4byte 0x000002FA
_080C8FB0:
	mov r0, r8
	cmp r0, #0x17
	ble _080C8FCE
	ldr r1, _080C8FDC @ =FUN_080c8fe0
	movs r0, #0x20
	adds r2, r5, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r7, [r0]
	movs r0, #1
	strb r0, [r6]
_080C8FCE:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C8FDC: .4byte FUN_080c8fe0

	thumb_func_start FUN_080c8fe0
FUN_080c8fe0: @ 0x080C8FE0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	mov r8, r1
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C903C
	movs r4, #0
	strb r4, [r1]
	ldr r1, _080C9174 @ =0x0000191E
	adds r0, r7, r1
	strh r4, [r0]
	movs r3, #0xc9
	lsls r3, r3, #5
	adds r2, r7, r3
	movs r0, #0xba
	lsls r0, r0, #2
	adds r3, r7, r0
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0xbc
	lsls r1, r1, #2
	adds r2, r7, r1
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r1, #1
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xc
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C903C:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _080C9052
	b _080C925E
_080C9052:
	movs r2, #0x80
	lsls r2, r2, #0xf
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r3, _080C9178 @ =0x0000191C
	adds r0, r7, r3
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080C90AA
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r4, #1
	str r4, [sp]
	str r5, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xd
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	ldr r2, _080C917C @ =0x000025E8
	adds r0, r7, r2
	strh r4, [r0]
	ldr r3, _080C9174 @ =0x0000191E
	adds r1, r7, r3
	movs r0, #0x20
	strh r0, [r1]
	movs r0, #0xc9
	lsls r0, r0, #5
	adds r2, r7, r0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
_080C90AA:
	ldr r2, _080C917C @ =0x000025E8
	adds r4, r7, r2
	ldrh r0, [r4]
	cmp r0, #0
	beq _080C90DC
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _080C90DC
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r0, r7, r3
	movs r1, #1
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xc
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	strh r5, [r4]
_080C90DC:
	movs r0, #0xf
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	bne _080C9136
	ldr r5, _080C9180 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r5
	movs r1, #0x60
	orrs r0, r1
	ldr r1, _080C9184 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #0xc]
	ldr r6, _080C9188 @ =0x0203B400
	ldr r4, _080C918C @ =0x030046B8
	ldr r2, [r4]
	adds r2, #1
	ldr r3, _080C9190 @ =0x000003FF
	ands r2, r3
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrb r1, [r0]
	adds r1, #0x80
	ldr r0, [sp, #0x10]
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #0x10]
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r7, r0
	adds r2, #1
	ands r2, r3
	str r2, [r4]
	lsls r2, r2, #1
	adds r2, r2, r6
	ldrh r3, [r2]
	movs r0, #0x1f
	ands r3, r0
	adds r3, #0xf1
	movs r0, #0xff
	ands r3, r0
	adds r0, r7, #0
	add r2, sp, #0xc
	bl FUN_080c3db4
_080C9136:
	movs r0, #0x3f
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	bne _080C914A
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0xc
	bl FUN_080c4a40
_080C914A:
	ldr r3, _080C9174 @ =0x0000191E
	adds r2, r7, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _080C9230
	subs r1, r0, #1
	strh r1, [r2]
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _080C9194
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r1, #0xc9
	lsls r1, r1, #5
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	b _080C9230
	.align 2, 0
_080C9174: .4byte 0x0000191E
_080C9178: .4byte 0x0000191C
_080C917C: .4byte 0x000025E8
_080C9180: .4byte 0xFFFF0000
_080C9184: .4byte 0x0000FFFF
_080C9188: .4byte 0x0203B400
_080C918C: .4byte 0x030046B8
_080C9190: .4byte 0x000003FF
_080C9194:
	movs r0, #7
	ands r1, r0
	cmp r1, #0
	bne _080C9230
	ldr r2, _080C91E8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C91EC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _080C91F0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	asrs r4, r0, #3
	movs r3, #0xff
	ands r4, r3
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r1, #0xc9
	lsls r1, r1, #5
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080C91F4 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _080C91F8
	asrs r3, r0, #0xc
	b _080C91FE
	.align 2, 0
_080C91E8: .4byte 0x030046B8
_080C91EC: .4byte 0x000003FF
_080C91F0: .4byte 0x0203B400
_080C91F4: .4byte 0x085B0A08
_080C91F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080C91FE:
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _080C921E
	asrs r2, r0, #0xc
	b _080C9224
_080C921E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C9224:
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r1, r7, r3
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_080C9230:
	adds r0, r7, #0
	bl FUN_080c4990
	ldr r0, _080C926C @ =0x00000167
	cmp r8, r0
	ble _080C925E
	ldr r1, _080C9270 @ =0x00001918
	adds r0, r7, r1
	movs r2, #0
	movs r3, #0
	strh r3, [r0]
	ldr r1, _080C9274 @ =FUN_080c6c8c
	adds r0, r7, #0
	adds r0, #0xa3
	strb r2, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r1, r7, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_080C925E:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C926C: .4byte 0x00000167
_080C9270: .4byte 0x00001918
_080C9274: .4byte FUN_080c6c8c

	thumb_func_start FUN_080c9278
FUN_080c9278: @ 0x080C9278
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	mov r8, r1
	adds r4, r5, #0
	adds r6, r4, #0
	adds r6, #0xa9
	ldrb r0, [r6]
	cmp r0, #0
	beq _080C92AC
	movs r2, #0
	strb r2, [r6]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #8
	movs r3, #0
	bl FUN_08055b5c
_080C92AC:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	bne _080C9326
	movs r2, #0x80
	lsls r2, r2, #0xf
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080C9300 @ =0x000002EA
	adds r3, r4, r0
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080C9304 @ =0x000002FA
	adds r2, r4, r0
	movs r4, #0
	ldrsh r0, [r2, r4]
	adds r0, #0x14
	cmp r1, r0
	ble _080C9308
	ldrh r1, [r3]
	subs r1, #0x1e
	strh r1, [r3]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r4, #0
	ldrsh r0, [r2, r4]
	adds r0, #0x14
	cmp r1, r0
	bge _080C9326
	ldrh r0, [r2]
	adds r0, #0x14
	strh r0, [r3]
	b _080C9326
	.align 2, 0
_080C9300: .4byte 0x000002EA
_080C9304: .4byte 0x000002FA
_080C9308:
	mov r0, r8
	cmp r0, #0x17
	ble _080C9326
	ldr r1, _080C9334 @ =FUN_080c9338
	movs r0, #0x23
	adds r2, r5, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r7, [r0]
	movs r0, #1
	strb r0, [r6]
_080C9326:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C9334: .4byte FUN_080c9338

	thumb_func_start FUN_080c9338
FUN_080c9338: @ 0x080C9338
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	mov r8, r1
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C9394
	movs r4, #0
	strb r4, [r1]
	ldr r1, _080C94C8 @ =0x0000191E
	adds r0, r7, r1
	strh r4, [r0]
	movs r3, #0xc9
	lsls r3, r3, #5
	adds r2, r7, r3
	movs r0, #0xba
	lsls r0, r0, #2
	adds r3, r7, r0
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0xbc
	lsls r1, r1, #2
	adds r2, r7, r1
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r1, #1
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #9
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C9394:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _080C93AA
	b _080C95B2
_080C93AA:
	movs r2, #0x80
	lsls r2, r2, #0xf
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r3, _080C94CC @ =0x0000191C
	adds r0, r7, r3
	ldrh r1, [r0]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _080C9402
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r7, r1
	str r6, [sp]
	str r5, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xa
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	ldr r2, _080C94D0 @ =0x000025E8
	adds r0, r7, r2
	strh r6, [r0]
	ldr r3, _080C94C8 @ =0x0000191E
	adds r1, r7, r3
	movs r0, #0x20
	strh r0, [r1]
	movs r0, #0xc9
	lsls r0, r0, #5
	adds r2, r7, r0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
_080C9402:
	ldr r2, _080C94D0 @ =0x000025E8
	adds r4, r7, r2
	ldrh r0, [r4]
	cmp r0, #0
	beq _080C9432
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _080C9432
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r0, r7, r3
	str r6, [sp]
	str r5, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #9
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	strh r5, [r4]
_080C9432:
	movs r0, #0xf
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	bne _080C9488
	ldr r5, _080C94D4 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r5
	ldr r1, _080C94D8 @ =0x0000FFC0
	orrs r0, r1
	adds r1, #0x3f
	ands r0, r1
	str r0, [sp, #0xc]
	ldr r6, _080C94DC @ =0x0203B400
	ldr r4, _080C94E0 @ =0x030046B8
	ldr r2, [r4]
	adds r2, #1
	ldr r3, _080C94E4 @ =0x000003FF
	ands r2, r3
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrb r1, [r0]
	adds r1, #0x80
	ldr r0, [sp, #0x10]
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #0x10]
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r7, r0
	adds r2, #1
	ands r2, r3
	str r2, [r4]
	lsls r2, r2, #1
	adds r2, r2, r6
	ldrh r3, [r2]
	movs r0, #0x1f
	ands r3, r0
	adds r3, #0x71
	adds r0, r7, #0
	add r2, sp, #0xc
	bl FUN_080c3db4
_080C9488:
	movs r0, #0x3f
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	bne _080C949C
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0xc
	bl FUN_080c4a40
_080C949C:
	ldr r3, _080C94C8 @ =0x0000191E
	adds r2, r7, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _080C9584
	subs r1, r0, #1
	strh r1, [r2]
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _080C94E8
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r1, #0xc9
	lsls r1, r1, #5
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	b _080C9584
	.align 2, 0
_080C94C8: .4byte 0x0000191E
_080C94CC: .4byte 0x0000191C
_080C94D0: .4byte 0x000025E8
_080C94D4: .4byte 0xFFFF0000
_080C94D8: .4byte 0x0000FFC0
_080C94DC: .4byte 0x0203B400
_080C94E0: .4byte 0x030046B8
_080C94E4: .4byte 0x000003FF
_080C94E8:
	movs r0, #7
	ands r1, r0
	cmp r1, #0
	bne _080C9584
	ldr r2, _080C953C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C9540 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _080C9544 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	asrs r4, r0, #3
	movs r3, #0xff
	ands r4, r3
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r1, #0xc9
	lsls r1, r1, #5
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080C9548 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _080C954C
	asrs r3, r0, #0xc
	b _080C9552
	.align 2, 0
_080C953C: .4byte 0x030046B8
_080C9540: .4byte 0x000003FF
_080C9544: .4byte 0x0203B400
_080C9548: .4byte 0x085B0A08
_080C954C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080C9552:
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _080C9572
	asrs r2, r0, #0xc
	b _080C9578
_080C9572:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080C9578:
	movs r3, #0xbd
	lsls r3, r3, #2
	adds r1, r7, r3
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_080C9584:
	adds r0, r7, #0
	bl FUN_080c4990
	ldr r0, _080C95C0 @ =0x00000167
	cmp r8, r0
	ble _080C95B2
	ldr r1, _080C95C4 @ =0x0000191A
	adds r0, r7, r1
	movs r2, #0
	movs r3, #0
	strh r3, [r0]
	ldr r1, _080C95C8 @ =FUN_080c6c8c
	adds r0, r7, #0
	adds r0, #0xa3
	strb r2, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r1, r7, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_080C95B2:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C95C0: .4byte 0x00000167
_080C95C4: .4byte 0x0000191A
_080C95C8: .4byte FUN_080c6c8c

	thumb_func_start FUN_080c95cc
FUN_080c95cc: @ 0x080C95CC
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	adds r1, r4, #0
	adds r5, r1, #0
	adds r5, #0xa9
	ldrb r0, [r5]
	cmp r0, #0
	beq _080C95FC
	movs r2, #0
	strb r2, [r5]
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r0, r1, r3
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xd
	movs r3, #0
	bl FUN_08055b5c
_080C95FC:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _080C963A
	movs r2, #0x80
	lsls r2, r2, #0xf
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	cmp r6, #0x17
	ble _080C963A
	ldr r1, _080C9644 @ =FUN_080c96c4
	movs r0, #0x25
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	movs r0, #1
	strb r0, [r5]
_080C963A:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C9644: .4byte FUN_080c96c4

	thumb_func_start FUN_080c9648
FUN_080c9648: @ 0x080C9648
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	adds r1, r4, #0
	adds r5, r1, #0
	adds r5, #0xa9
	ldrb r0, [r5]
	cmp r0, #0
	beq _080C9678
	movs r2, #0
	strb r2, [r5]
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r0, r1, r3
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xa
	movs r3, #0
	bl FUN_08055b5c
_080C9678:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _080C96B6
	movs r2, #0x80
	lsls r2, r2, #0xf
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	cmp r6, #0x17
	ble _080C96B6
	ldr r1, _080C96C0 @ =FUN_080c96c4
	movs r0, #0x25
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	movs r0, #1
	strb r0, [r5]
_080C96B6:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C96C0: .4byte FUN_080c96c4

	thumb_func_start FUN_080c96c4
FUN_080c96c4: @ 0x080C96C4
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r1, #0
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C96F2
	movs r2, #0
	strb r2, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xe
	movs r3, #0
	bl FUN_08055b5c
_080C96F2:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080C9764
	movs r2, #0x80
	lsls r2, r2, #0xf
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r6, _080C976C @ =0x000002EA
	adds r3, r4, r6
	movs r0, #0
	ldrsh r1, [r3, r0]
	adds r6, #0x10
	adds r2, r4, r6
	movs r6, #0
	ldrsh r0, [r2, r6]
	adds r0, #0x14
	cmp r1, r0
	ble _080C9742
	ldrh r1, [r3]
	subs r1, #0xa
	strh r1, [r3]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r6, #0
	ldrsh r0, [r2, r6]
	adds r0, #0x14
	cmp r1, r0
	bge _080C9742
	ldrh r0, [r2]
	adds r0, #0x14
	strh r0, [r3]
_080C9742:
	cmp r5, #0xe
	ble _080C9764
	ldr r2, _080C9770 @ =FUN_080c9774
	movs r0, #0x26
	adds r3, r4, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_080C9764:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C976C: .4byte 0x000002EA
_080C9770: .4byte FUN_080c9774

	thumb_func_start FUN_080c9774
FUN_080c9774: @ 0x080C9774
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	mov r8, r1
	adds r4, r5, #0
	adds r6, r4, #0
	adds r6, #0xa9
	ldrb r0, [r6]
	cmp r0, #0
	beq _080C97AE
	movs r2, #0
	strb r2, [r6]
	ldr r1, _080C9818 @ =0x000025F9
	adds r0, r4, r1
	strb r2, [r0]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #1
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xf
	movs r3, #0
	bl FUN_08055b5c
_080C97AE:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	bne _080C980C
	movs r2, #0xc0
	lsls r2, r2, #0xf
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x3f
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	bne _080C97E4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0xc
	bl FUN_080c4a40
_080C97E4:
	ldr r0, _080C981C @ =0x00000167
	cmp r8, r0
	bgt _080C97F4
	ldr r1, _080C9818 @ =0x000025F9
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _080C980C
_080C97F4:
	ldr r1, _080C9820 @ =FUN_080c9824
	movs r0, #0x27
	adds r2, r5, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r7, [r0]
	movs r0, #1
	strb r0, [r6]
_080C980C:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C9818: .4byte 0x000025F9
_080C981C: .4byte 0x00000167
_080C9820: .4byte FUN_080c9824

	thumb_func_start FUN_080c9824
FUN_080c9824: @ 0x080C9824
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov r8, r1
	adds r4, r7, #0
	adds r6, r4, #0
	adds r6, #0xa9
	ldrb r0, [r6]
	cmp r0, #0
	beq _080C9858
	movs r2, #0
	strb r2, [r6]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #2
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x10
	movs r3, #0
	bl FUN_08055b5c
_080C9858:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _080C993C
	movs r2, #0x80
	lsls r2, r2, #0xf
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r0, r8
	cmp r0, #0x1d
	ble _080C993C
	ldr r1, _080C98C0 @ =0x00001918
	adds r0, r4, r1
	strh r5, [r0]
	adds r1, #2
	adds r0, r4, r1
	strh r5, [r0]
	ldr r1, _080C98C4 @ =0x0000260C
	adds r0, r4, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _080C98E4
	subs r1, #0x20
	adds r0, r4, r1
	strh r5, [r0]
	ldr r2, _080C98C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C98CC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080C98D0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r3, #1
	ands r0, r3
	cmp r0, #0
	beq _080C98D8
	ldr r1, _080C98D4 @ =FUN_080c86ac
	movs r0, #0x14
	b _080C990A
	.align 2, 0
_080C98C0: .4byte 0x00001918
_080C98C4: .4byte 0x0000260C
_080C98C8: .4byte 0x030046B8
_080C98CC: .4byte 0x000003FF
_080C98D0: .4byte 0x0203B400
_080C98D4: .4byte FUN_080c86ac
_080C98D8:
	ldr r1, _080C98E0 @ =FUN_080c898c
	movs r0, #0x17
	b _080C990A
	.align 2, 0
_080C98E0: .4byte FUN_080c898c
_080C98E4:
	cmp r3, #1
	bne _080C9924
	ldr r0, _080C98FC @ =0x000025C9
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C9904
	movs r0, #0
	strb r0, [r1]
	ldr r1, _080C9900 @ =FUN_080c7e54
	movs r0, #0xb
	b _080C990A
	.align 2, 0
_080C98FC: .4byte 0x000025C9
_080C9900: .4byte FUN_080c7e54
_080C9904:
	strb r3, [r1]
	ldr r1, _080C9920 @ =FUN_080c81e0
	movs r0, #0xf
_080C990A:
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r5, [r0]
	strb r3, [r6]
	b _080C993C
	.align 2, 0
_080C9920: .4byte FUN_080c81e0
_080C9924:
	ldr r1, _080C9948 @ =FUN_080c8cc8
	movs r0, #0x1b
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r5, [r0]
	movs r0, #1
	strb r0, [r6]
_080C993C:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C9948: .4byte FUN_080c8cc8

	thumb_func_start FUN_080c994c
FUN_080c994c: @ 0x080C994C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x20
	mov r8, r0
	adds r5, r1, #0
	mov r6, r8
	movs r0, #0xa9
	adds r0, r0, r6
	mov sb, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _080C99CC
	movs r2, #0
	mov r1, sb
	strb r2, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #1
	str r1, [sp]
	str r2, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0xf
	movs r3, #0
	bl FUN_08055b5c
	movs r2, #0xbe
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r1, [r0]
	subs r2, #8
	adds r0, r6, r2
	strh r1, [r0]
	ldr r0, _080C9A6C @ =0x000002FA
	adds r1, r6, r0
	subs r2, #0x70
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r2, #0x72
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0xbf
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	strh r0, [r1]
	ldr r0, _080C9A70 @ =0x000025F8
	adds r1, r6, r0
	movs r0, #2
	strb r0, [r1]
	ldr r0, _080C9A74 @ =0x0000022F
	bl PlaySound_082406e0
_080C99CC:
	adds r0, r6, #0
	bl FUN_080c4990
	ldr r2, _080C9A78 @ =0x00600002
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r7, #3
	ands r7, r5
	cmp r7, #0
	bne _080C9A5E
	ldr r4, _080C9A7C @ =0xFFFF0000
	ldr r1, _080C9A80 @ =0x0000FFFF
	mov ip, r1
	str r7, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r4
	str r0, [sp, #0x14]
	ldr r2, _080C9A84 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C9A88 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _080C9A8C @ =0x0203B400
	adds r0, r0, r2
	ldrh r3, [r0]
	asrs r3, r3, #3
	movs r0, #0xff
	ands r3, r0
	movs r1, #0x9b
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r0, [sp, #0x18]
	ands r0, r4
	orrs r0, r1
	ldr r2, _080C9A90 @ =0x0000026E
	adds r1, r6, r2
	ldrh r1, [r1]
	subs r3, #0x80
	adds r1, r3, r1
	lsls r1, r1, #0x10
	mov r2, ip
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r2, [r0]
	subs r2, r2, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r0, sp, #0x18
	ldr r1, [r0, #4]
	ands r1, r4
	orrs r1, r2
	str r1, [r0, #4]
	str r7, [sp]
	movs r1, #0x18
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	add r2, sp, #0x10
	movs r3, #0
	bl FUN_080ddcc8
_080C9A5E:
	cmp r5, #0x4f
	bgt _080C9A94
	adds r0, r6, #0
	movs r1, #8
	bl FUN_080c4a54
	b _080C9AD8
	.align 2, 0
_080C9A6C: .4byte 0x000002FA
_080C9A70: .4byte 0x000025F8
_080C9A74: .4byte 0x0000022F
_080C9A78: .4byte 0x00600002
_080C9A7C: .4byte 0xFFFF0000
_080C9A80: .4byte 0x0000FFFF
_080C9A84: .4byte 0x030046B8
_080C9A88: .4byte 0x000003FF
_080C9A8C: .4byte 0x0203B400
_080C9A90: .4byte 0x0000026E
_080C9A94:
	cmp r5, #0x64
	bne _080C9AA4
	ldr r2, _080C9AA0 @ =0x000008F4
	adds r1, r6, r2
	movs r0, #0
	b _080C9AD6
	.align 2, 0
_080C9AA0: .4byte 0x000008F4
_080C9AA4:
	cmp r5, #0x96
	bne _080C9AD8
	movs r2, #0xba
	lsls r2, r2, #2
	add r2, r8
	movs r0, #0xbc
	lsls r0, r0, #2
	add r0, r8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080C9AE8 @ =FUN_080c9aec
	movs r0, #0x29
	mov r3, r8
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	mov r0, r8
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	movs r0, #1
	mov r1, sb
_080C9AD6:
	strb r0, [r1]
_080C9AD8:
	add sp, #0x20
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C9AE8: .4byte FUN_080c9aec

	thumb_func_start FUN_080c9aec
FUN_080c9aec: @ 0x080C9AEC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r6
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080C9B32
	movs r4, #0
	strb r4, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x35
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
	ldr r2, _080C9CA0 @ =0x000025F8
	adds r1, r6, r2
	movs r0, #3
	strb r0, [r1]
	ldr r5, _080C9CA4 @ =0x000025EA
	adds r0, r6, r5
	strh r4, [r0]
_080C9B32:
	cmp r7, #0x23
	bne _080C9B3C
	ldr r0, _080C9CA8 @ =0x0000022B
	bl PlaySound_082406e0
_080C9B3C:
	cmp r7, #0x36
	bne _080C9B5C
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #1
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x36
	movs r2, #0
	movs r3, #0
	bl FUN_08055b5c
_080C9B5C:
	ldr r2, _080C9CAC @ =0x00400002
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r7, #0
	subs r0, #0x23
	cmp r0, #0xf
	bhi _080C9B7A
	movs r0, #0x33
	subs r0, r0, r7
	lsls r0, r0, #1
	bl FUN_0823b9cc
_080C9B7A:
	adds r0, r7, #0
	subs r0, #0x47
	cmp r0, #0xf
	bhi _080C9B8C
	movs r0, #0x57
	subs r0, r0, r7
	lsls r0, r0, #1
	bl FUN_0823b9cc
_080C9B8C:
	adds r0, r7, #0
	subs r0, #0x50
	cmp r0, #0xf
	bhi _080C9C1C
	movs r5, #3
	ands r5, r7
	cmp r5, #0
	bne _080C9C1C
	ldr r4, _080C9CB0 @ =0xFFFF0000
	ldr r2, _080C9CB4 @ =0x0000FFFF
	mov ip, r2
	str r5, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r4
	str r0, [sp, #0x14]
	ldr r2, _080C9CB8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C9CBC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080C9CC0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r3, [r0]
	asrs r3, r3, #3
	movs r2, #0x7f
	mov sb, r2
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r0, [sp, #0x18]
	ands r0, r4
	orrs r0, r1
	ldr r2, _080C9CC4 @ =0x000002EA
	adds r1, r6, r2
	ldrh r1, [r1]
	mov r2, sb
	ands r3, r2
	adds r1, r3, r1
	lsls r1, r1, #0x10
	mov r2, ip
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r1, r6, r0
	ldr r2, _080C9CC8 @ =0xFFFFFE00
	adds r0, r2, #0
	adds r3, r3, r0
	ldrh r2, [r1]
	subs r2, r2, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r0, sp, #0x18
	ldr r1, [r0, #4]
	ands r1, r4
	orrs r1, r2
	str r1, [r0, #4]
	str r5, [sp]
	movs r1, #0x10
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	add r2, sp, #0x10
	movs r3, #0
	bl FUN_080ddcc8
_080C9C1C:
	ldr r4, _080C9CA4 @ =0x000025EA
	add r4, r8
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	movs r2, #0xbb
	lsls r2, r2, #2
	add r2, r8
	ldrh r1, [r2]
	adds r1, #2
	strh r1, [r2]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r3, #0xbf
	lsls r3, r3, #2
	add r3, r8
	movs r5, #0
	ldrsh r0, [r3, r5]
	movs r5, #0x80
	lsls r5, r5, #2
	adds r0, r0, r5
	cmp r1, r0
	blt _080C9C50
	ldrh r0, [r3]
	adds r0, r0, r5
	strh r0, [r2]
_080C9C50:
	ldr r2, _080C9CC4 @ =0x000002EA
	add r2, r8
	ldrh r0, [r4]
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	ldr r1, _080C9CCC @ =0x000002FA
	add r1, r8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r3, [r1]
	movs r5, #0
	ldrsh r1, [r1, r5]
	cmp r0, r1
	bge _080C9C82
	strh r3, [r2]
	ldrh r0, [r4]
	rsbs r0, r0, #0
	strh r0, [r4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #2
	bl Div
	strh r0, [r4]
_080C9C82:
	cmp r7, #0xf0
	bne _080C9C92
	movs r1, #0xba
	lsls r1, r1, #2
	add r1, r8
	adds r0, r6, #0
	bl FUN_08023024
_080C9C92:
	add sp, #0x20
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C9CA0: .4byte 0x000025F8
_080C9CA4: .4byte 0x000025EA
_080C9CA8: .4byte 0x0000022B
_080C9CAC: .4byte 0x00400002
_080C9CB0: .4byte 0xFFFF0000
_080C9CB4: .4byte 0x0000FFFF
_080C9CB8: .4byte 0x030046B8
_080C9CBC: .4byte 0x000003FF
_080C9CC0: .4byte 0x0203B400
_080C9CC4: .4byte 0x000002EA
_080C9CC8: .4byte 0xFFFFFE00
_080C9CCC: .4byte 0x000002FA

	thumb_func_start FUN_080c9cd0
FUN_080c9cd0: @ 0x080C9CD0
	push {lr}
	adds r1, r0, #0
	adds r3, r1, #0
	adds r2, r1, #0
	adds r2, #0xa7
	movs r0, #0
	strb r0, [r2]
	ldr r0, _080C9CFC @ =0x03002BE0
	ldr r0, [r0]
	ldr r0, [r0, #0x1c]
	cmp r0, #4
	bne _080C9CF2
	adds r0, r1, #0
	adds r0, #0xa3
	ldrb r0, [r0]
	cmp r0, #0xa
	bne _080C9CF8
_080C9CF2:
	adds r0, r3, #0
	bl FUN_08022f78
_080C9CF8:
	pop {r0}
	bx r0
	.align 2, 0
_080C9CFC: .4byte 0x03002BE0

	thumb_func_start FUN_080c9d00
FUN_080c9d00: @ 0x080C9D00
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	mov r8, r4
	ldr r0, _080C9D68 @ =0x0000190E
	adds r3, r4, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _080C9D84
	ldr r2, _080C9D6C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	movs r1, #0x80
	orrs r0, r1
	ldr r1, _080C9D70 @ =0x0000FFFF
	ands r0, r1
	ldr r1, _080C9D74 @ =0xFF800000
	orrs r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r1, #0xc0
	lsls r1, r1, #1
	orrs r0, r1
	str r0, [sp, #0xc]
	adds r1, #0x28
	adds r0, r4, r1
	ldrh r1, [r3]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r3, r4, r2
	add r5, sp, #8
	str r5, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0
	bl FUN_0805fe7c
	adds r0, r4, #0
	adds r0, #0xa3
	ldrb r0, [r0]
	cmp r0, #0x1f
	beq _080C9D60
	cmp r0, #0x24
	bne _080C9D7C
_080C9D60:
	ldr r0, _080C9D78 @ =0x0000022E
	bl PlaySound_082406e0
	b _080C9D84
	.align 2, 0
_080C9D68: .4byte 0x0000190E
_080C9D6C: .4byte 0xFFFF0000
_080C9D70: .4byte 0x0000FFFF
_080C9D74: .4byte 0xFF800000
_080C9D78: .4byte 0x0000022E
_080C9D7C:
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080C9D84:
	ldr r0, _080C9DD4 @ =0x00001910
	adds r3, r4, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _080C9DE8
	ldr r2, _080C9DD8 @ =0x0000FF80
	add r0, sp, #8
	strh r2, [r0]
	adds r1, r0, #0
	strh r2, [r1, #2]
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r1, #4]
	movs r1, #0xd4
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r1, [r3]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r3, r4, r2
	add r5, sp, #8
	str r5, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0
	bl FUN_0805fe7c
	adds r0, r4, #0
	adds r0, #0xa3
	ldrb r0, [r0]
	subs r0, #0x21
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080C9DE0
	ldr r0, _080C9DDC @ =0x0000022E
	bl PlaySound_082406e0
	b _080C9DE8
	.align 2, 0
_080C9DD4: .4byte 0x00001910
_080C9DD8: .4byte 0x0000FF80
_080C9DDC: .4byte 0x0000022E
_080C9DE0:
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080C9DE8:
	ldr r0, _080C9EE8 @ =0x00001914
	adds r0, r0, r4
	mov sb, r0
	ldrh r0, [r0]
	cmp r0, #0
	beq _080C9E28
	movs r2, #0
	add r0, sp, #8
	strh r2, [r0]
	adds r1, r0, #0
	ldr r0, _080C9EEC @ =0x0000FF80
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r1, #0xfc
	lsls r1, r1, #1
	adds r0, r4, r1
	mov r2, sb
	ldrh r1, [r2]
	movs r5, #0xbe
	lsls r5, r5, #2
	adds r3, r4, r5
	add r2, sp, #8
	str r2, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0
	bl FUN_0805fe7c
_080C9E28:
	ldr r5, _080C9EF0 @ =0x00001912
	adds r7, r4, r5
	ldrh r0, [r7]
	cmp r0, #0
	beq _080C9E66
	movs r1, #0
	add r0, sp, #8
	strh r1, [r0]
	adds r1, r0, #0
	ldr r0, _080C9EEC @ =0x0000FF80
	strh r0, [r1, #2]
	movs r0, #0xa0
	lsls r0, r0, #2
	strh r0, [r1, #4]
	movs r1, #0x92
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r7]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r3, r4, r2
	add r5, sp, #8
	str r5, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0
	bl FUN_0805fe7c
	ldr r0, _080C9EF4 @ =0x0000022E
	bl PlaySound_082406e0
_080C9E66:
	ldr r0, _080C9EF8 @ =0x0000190E
	adds r3, r4, r0
	ldrh r0, [r3]
	ldr r1, _080C9EFC @ =0x00001910
	adds r2, r4, r1
	ldrh r1, [r2]
	adds r0, r0, r1
	ldrh r5, [r7]
	adds r0, r0, r5
	mov r5, sb
	ldrh r1, [r5]
	adds r5, r0, r1
	movs r6, #0
	strh r6, [r3]
	strh r6, [r2]
	strh r6, [r7]
	mov r0, sb
	strh r6, [r0]
	cmp r5, #0
	bgt _080C9E90
	b _080C9FB0
_080C9E90:
	mov r1, r8
	adds r1, #0x90
	ldrh r0, [r1]
	subs r0, r0, r5
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _080C9F0C
	strh r6, [r1]
	movs r2, #2
	adds r1, #8
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _080C9F00 @ =FUN_080c994c
	movs r0, #0x28
	mov r2, r8
	adds r2, #0xa3
	strb r0, [r2]
	mov r0, r8
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	mov r1, r8
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	mov r0, r8
	bl FUN_08022fb8
	ldr r5, _080C9F04 @ =0x000025D0
	adds r0, r4, r5
	ldr r0, [r0]
	ldr r2, _080C9F08 @ =0x000025CE
	adds r1, r4, r2
	ldrh r1, [r1]
	bl FUN_0807a840
	movs r0, #1
	b _080C9FB2
	.align 2, 0
_080C9EE8: .4byte 0x00001914
_080C9EEC: .4byte 0x0000FF80
_080C9EF0: .4byte 0x00001912
_080C9EF4: .4byte 0x0000022E
_080C9EF8: .4byte 0x0000190E
_080C9EFC: .4byte 0x00001910
_080C9F00: .4byte FUN_080c994c
_080C9F04: .4byte 0x000025D0
_080C9F08: .4byte 0x000025CE
_080C9F0C:
	movs r5, #0
	ldrsh r1, [r1, r5]
	movs r0, #0x64
	muls r0, r1, r0
	mov r1, r8
	adds r1, #0x92
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl Div
	cmp r0, #0x1d
	bgt _080C9F54
	ldr r5, _080C9F44 @ =0x0000260C
	adds r1, r4, r5
	movs r0, #2
	strb r0, [r1]
	ldr r0, _080C9F48 @ =0x0000260E
	adds r1, r4, r0
	movs r0, #0xe
	strh r0, [r1]
	ldr r2, _080C9F4C @ =0x0000260D
	adds r1, r4, r2
	movs r0, #3
	strb r0, [r1]
	ldr r5, _080C9F50 @ =0x0000190B
	adds r1, r4, r5
	movs r0, #5
	b _080C9FA6
	.align 2, 0
_080C9F44: .4byte 0x0000260C
_080C9F48: .4byte 0x0000260E
_080C9F4C: .4byte 0x0000260D
_080C9F50: .4byte 0x0000190B
_080C9F54:
	cmp r0, #0x45
	bgt _080C9F88
	ldr r0, _080C9F78 @ =0x0000260C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _080C9F7C @ =0x0000260E
	adds r1, r4, r2
	movs r0, #0xa
	strh r0, [r1]
	ldr r5, _080C9F80 @ =0x0000260D
	adds r1, r4, r5
	movs r0, #2
	strb r0, [r1]
	ldr r0, _080C9F84 @ =0x0000190B
	adds r1, r4, r0
	b _080C9FA4
	.align 2, 0
_080C9F78: .4byte 0x0000260C
_080C9F7C: .4byte 0x0000260E
_080C9F80: .4byte 0x0000260D
_080C9F84: .4byte 0x0000190B
_080C9F88:
	ldr r2, _080C9FC0 @ =0x0000260C
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	ldr r5, _080C9FC4 @ =0x0000260E
	adds r1, r4, r5
	movs r0, #0xa
	strh r0, [r1]
	ldr r0, _080C9FC8 @ =0x0000260D
	adds r1, r4, r0
	movs r0, #2
	strb r0, [r1]
	ldr r2, _080C9FCC @ =0x0000190B
	adds r1, r4, r2
_080C9FA4:
	movs r0, #3
_080C9FA6:
	strb r0, [r1]
	ldr r5, _080C9FD0 @ =0x00001909
	adds r1, r4, r5
	movs r0, #3
	strb r0, [r1]
_080C9FB0:
	movs r0, #0
_080C9FB2:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080C9FC0: .4byte 0x0000260C
_080C9FC4: .4byte 0x0000260E
_080C9FC8: .4byte 0x0000260D
_080C9FCC: .4byte 0x0000190B
_080C9FD0: .4byte 0x00001909

	thumb_func_start FUN_080c9fd4
FUN_080c9fd4: @ 0x080C9FD4
	push {lr}
	adds r3, r0, #0
	movs r2, #2
	adds r1, r3, #0
	adds r1, #0x98
	ldr r1, [r1]
	ands r1, r2
	cmp r1, #0
	beq _080CA000
	movs r1, #1
	movs r2, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r2, [r0]
	subs r0, #0x14
	strb r1, [r0]
	movs r0, #1
_080CA000:
	pop {r1}
	bx r1

	thumb_func_start FUN_080ca004
FUN_080ca004: @ 0x080CA004
	bx lr
	.align 2, 0

	thumb_func_start FUN_080ca008
FUN_080ca008: @ 0x080CA008
	bx lr
	.align 2, 0

	thumb_func_start FUN_080ca00c
FUN_080ca00c: @ 0x080CA00C
	bx lr
	.align 2, 0

	thumb_func_start FUN_080ca010
FUN_080ca010: @ 0x080CA010
	bx lr
	.align 2, 0

	thumb_func_start FUN_080ca014
FUN_080ca014: @ 0x080CA014
	bx lr
	.align 2, 0

	thumb_func_start FUN_080ca018
FUN_080ca018: @ 0x080CA018
	bx lr
	.align 2, 0

	thumb_func_start FUN_080ca01c
FUN_080ca01c: @ 0x080CA01C
	bx lr
	.align 2, 0

	thumb_func_start FUN_080ca020
FUN_080ca020: @ 0x080CA020
	bx lr
	.align 2, 0

	thumb_func_start FUN_080ca024
FUN_080ca024: @ 0x080CA024
	bx lr
	.align 2, 0

	thumb_func_start FUN_080ca028
FUN_080ca028: @ 0x080CA028
	bx lr
	.align 2, 0

	thumb_func_start FUN_080ca02c
FUN_080ca02c: @ 0x080CA02C
	bx lr
	.align 2, 0

	thumb_func_start FUN_080ca030
FUN_080ca030: @ 0x080CA030
	bx lr
	.align 2, 0

	thumb_func_start FUN_080ca034
FUN_080ca034: @ 0x080CA034
	push {lr}
	ldr r2, _080CA04C @ =0x085AD100
	adds r1, r0, #0
	adds r1, #0xa6
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080CA04C: .4byte 0x085AD100

	thumb_func_start FUN_080ca050
FUN_080ca050: @ 0x080CA050
	push {lr}
	ldr r2, _080CA068 @ =0x085AD124
	adds r1, r0, #0
	adds r1, #0xa6
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080CA068: .4byte 0x085AD124

	thumb_func_start FUN_080ca06c
FUN_080ca06c: @ 0x080CA06C
	push {lr}
	ldr r2, _080CA084 @ =0x085AD12C
	adds r1, r0, #0
	adds r1, #0xa6
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080CA084: .4byte 0x085AD12C

	thumb_func_start FUN_080ca088
FUN_080ca088: @ 0x080CA088
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #4
	ldr r0, _080CA0BC @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080CA0B6
	adds r0, r4, #0
	bl FUN_080c9fd4
	cmp r0, #0
	bne _080CA0B6
	ldr r0, _080CA0C0 @ =0x085AD130
	adds r1, r4, #0
	adds r1, #0xa5
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_080CA0B6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CA0BC: .4byte 0x03002BC0
_080CA0C0: .4byte 0x085AD130

	thumb_func_start FUN_080ca0c4
FUN_080ca0c4: @ 0x080CA0C4
	push {lr}
	ldr r2, _080CA0DC @ =0x085AD134
	adds r1, r0, #0
	adds r1, #0xa5
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080CA0DC: .4byte 0x085AD134

	thumb_func_start FUN_080ca0e0
FUN_080ca0e0: @ 0x080CA0E0
	push {lr}
	ldr r2, _080CA0F8 @ =0x085AD138
	adds r1, r0, #0
	adds r1, #0xa5
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080CA0F8: .4byte 0x085AD138

	thumb_func_start FUN_080ca0fc
FUN_080ca0fc: @ 0x080CA0FC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	ldr r1, _080CA198 @ =0x000025C8
	adds r0, r6, r1
	ldrb r3, [r0]
	cmp r3, #1
	bne _080CA140
	ldr r2, _080CA19C @ =0x0000191A
	adds r0, r6, r2
	movs r2, #0
	strh r2, [r0]
	ldr r4, _080CA1A0 @ =0x00001918
	adds r0, r6, r4
	strh r2, [r0]
	adds r1, r6, #0
	adds r1, #0xa3
	ldrb r0, [r1]
	subs r0, #0x1f
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r7, r1, #0
	cmp r0, #8
	bhi _080CA140
	ldr r1, _080CA1A4 @ =FUN_080c6c8c
	movs r0, #0
	strb r0, [r7]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r2, [r0]
	adds r0, #0x1d
	strb r3, [r0]
_080CA140:
	movs r1, #4
	ldr r0, _080CA1A8 @ =0x03002BC0
	ldr r3, [r0]
	ands r3, r1
	cmp r3, #0
	beq _080CA14E
	b _080CA420
_080CA14E:
	adds r0, r6, #0
	adds r0, #0x90
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _080CA15C
	b _080CA420
_080CA15C:
	ldr r2, _080CA19C @ =0x0000191A
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #0x77
	bls _080CA1D8
	ldr r4, _080CA1A0 @ =0x00001918
	adds r0, r6, r4
	ldrh r0, [r0]
	cmp r0, #0x77
	bls _080CA1BC
	adds r0, r6, #0
	adds r0, #0xa3
	ldrb r2, [r0]
	adds r7, r0, #0
	cmp r2, #0x21
	beq _080CA20A
	cmp r2, #0x24
	beq _080CA20A
	cmp r2, #0x25
	beq _080CA20A
	cmp r2, #0x26
	beq _080CA20A
	cmp r2, #0x27
	beq _080CA20A
	cmp r2, #0x20
	bne _080CA1B0
	ldr r1, _080CA1AC @ =FUN_080c95cc
	movs r0, #0x21
	b _080CA1F6
	.align 2, 0
_080CA198: .4byte 0x000025C8
_080CA19C: .4byte 0x0000191A
_080CA1A0: .4byte 0x00001918
_080CA1A4: .4byte FUN_080c6c8c
_080CA1A8: .4byte 0x03002BC0
_080CA1AC: .4byte FUN_080c95cc
_080CA1B0:
	ldr r1, _080CA1B8 @ =FUN_080c9648
	movs r0, #0x24
	b _080CA1F6
	.align 2, 0
_080CA1B8: .4byte FUN_080c9648
_080CA1BC:
	adds r1, r6, #0
	adds r1, #0xa3
	ldrb r0, [r1]
	subs r0, #0x22
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r7, r1, #0
	cmp r0, #1
	bls _080CA20A
	ldr r1, _080CA1D4 @ =FUN_080c9278
	movs r0, #0x22
	b _080CA1F6
	.align 2, 0
_080CA1D4: .4byte FUN_080c9278
_080CA1D8:
	ldr r1, _080CA228 @ =0x00001918
	adds r0, r6, r1
	ldrh r0, [r0]
	adds r7, r6, #0
	adds r7, #0xa3
	cmp r0, #0x77
	bls _080CA20A
	ldrb r0, [r7]
	subs r0, #0x1f
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080CA20A
	ldr r1, _080CA22C @ =FUN_080c8f20
	movs r0, #0x1f
_080CA1F6:
	strb r0, [r7]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r1, r6, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_080CA20A:
	adds r3, r7, #0
	ldrb r0, [r3]
	cmp r0, #3
	bne _080CA234
	adds r1, r6, #0
	adds r1, #0xa7
	ldrb r0, [r1]
	cmp r0, #0
	bne _080CA21E
	b _080CA420
_080CA21E:
	movs r2, #0
	strb r2, [r1]
	ldr r1, _080CA230 @ =FUN_080c74b4
	movs r0, #4
	b _080CA3D8
	.align 2, 0
_080CA228: .4byte 0x00001918
_080CA22C: .4byte FUN_080c8f20
_080CA230: .4byte FUN_080c74b4
_080CA234:
	cmp r0, #4
	beq _080CA23A
	b _080CA334
_080CA23A:
	movs r5, #0
	ldr r2, _080CA2F8 @ =0x03002BE0
	ldr r4, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r4, #0x20]
	ands r0, r1
	mov ip, r2
	cmp r0, #0
	bne _080CA286
	movs r2, #0x2c
	ldrsh r3, [r4, r2]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r0, #0x30
	ldrsh r1, [r4, r0]
	movs r4, #0xbb
	lsls r4, r4, #2
	adds r0, r6, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r1, r1, r0
	subs r3, r3, r2
	cmp r3, #0
	bge _080CA274
	rsbs r3, r3, #0
_080CA274:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r3, r0
	bgt _080CA286
	ldr r2, _080CA2FC @ =0xFFFFFF00
	adds r0, r1, r2
	cmp r0, #0x80
	bhi _080CA286
	movs r5, #1
_080CA286:
	cmp r5, #0
	beq _080CA310
	movs r4, #0xba
	lsls r4, r4, #2
	adds r2, r6, r4
	ldr r3, _080CA300 @ =0xFFFF0000
	ldr r1, _080CA304 @ =0x000002EA
	adds r0, r6, r1
	ldrh r1, [r0]
	subs r1, #0x80
	lsls r1, r1, #0x10
	ldrh r0, [r2]
	orrs r0, r1
	str r0, [sp, #0x14]
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r4, #0xd5
	lsls r4, r4, #1
	adds r0, r4, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x18]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x18]
	mov r1, ip
	ldr r0, [r1]
	movs r5, #1
	str r5, [sp]
	movs r4, #0
	str r4, [sp, #4]
	str r4, [sp, #8]
	ldr r2, _080CA308 @ =0x00001928
	adds r1, r6, r2
	ldrh r1, [r1]
	str r1, [sp, #0xc]
	str r4, [sp, #0x10]
	add r1, sp, #0x14
	movs r2, #0
	movs r3, #2
	bl FUN_0807ab64
	ldr r1, _080CA30C @ =FUN_080c789c
	movs r0, #7
	strb r0, [r7]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	adds r0, #0x1d
	strb r5, [r0]
	b _080CA420
	.align 2, 0
_080CA2F8: .4byte 0x03002BE0
_080CA2FC: .4byte 0xFFFFFF00
_080CA300: .4byte 0xFFFF0000
_080CA304: .4byte 0x000002EA
_080CA308: .4byte 0x00001928
_080CA30C: .4byte FUN_080c789c
_080CA310:
	adds r1, r6, #0
	adds r1, #0xa7
	ldrb r0, [r1]
	cmp r0, #0
	bne _080CA31C
	b _080CA420
_080CA31C:
	strb r5, [r1]
	ldr r1, _080CA330 @ =FUN_080c7518
	movs r0, #5
	strb r0, [r7]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r5, [r0]
	b _080CA3E4
	.align 2, 0
_080CA330: .4byte FUN_080c7518
_080CA334:
	cmp r0, #9
	bne _080CA358
	adds r0, r6, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CA420
	ldr r2, _080CA354 @ =FUN_080c6c8c
	movs r1, #0
	strb r1, [r3]
	adds r0, r6, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	b _080CA3E4
	.align 2, 0
_080CA354: .4byte FUN_080c6c8c
_080CA358:
	cmp r0, #0xa
	bne _080CA370
	adds r0, r6, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CA420
	ldr r1, _080CA36C @ =FUN_080c7b84
	movs r0, #9
	b _080CA3D6
	.align 2, 0
_080CA36C: .4byte FUN_080c7b84
_080CA370:
	cmp r0, #0xe
	bne _080CA394
	adds r0, r6, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CA420
	ldr r2, _080CA390 @ =FUN_080c6c8c
	movs r1, #0
	strb r1, [r3]
	adds r0, r6, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	b _080CA3E4
	.align 2, 0
_080CA390: .4byte FUN_080c6c8c
_080CA394:
	cmp r0, #0x1b
	bne _080CA3AC
	adds r0, r6, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CA420
	ldr r1, _080CA3A8 @ =FUN_080c8dac
	movs r0, #0x1c
	b _080CA3D6
	.align 2, 0
_080CA3A8: .4byte FUN_080c8dac
_080CA3AC:
	cmp r0, #0x1c
	bne _080CA3C4
	adds r0, r6, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CA420
	ldr r1, _080CA3C0 @ =FUN_080c8e14
	movs r0, #0x1d
	b _080CA3D6
	.align 2, 0
_080CA3C0: .4byte FUN_080c8e14
_080CA3C4:
	cmp r0, #0x1d
	bne _080CA3F4
	adds r0, r6, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CA420
	ldr r1, _080CA3F0 @ =FUN_080c8eb8
	movs r0, #0x1e
_080CA3D6:
	movs r2, #0
_080CA3D8:
	strb r0, [r3]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r2, [r0]
_080CA3E4:
	adds r1, r6, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
	b _080CA420
	.align 2, 0
_080CA3F0: .4byte FUN_080c8eb8
_080CA3F4:
	cmp r0, #0x1e
	bne _080CA420
	adds r0, r6, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CA420
	ldr r4, _080CA428 @ =0x00001908
	adds r0, r6, r4
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r1, _080CA42C @ =FUN_080c73c0
	movs r0, #3
	strb r0, [r7]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r0, #0x1d
	strb r2, [r0]
_080CA420:
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CA428: .4byte 0x00001908
_080CA42C: .4byte FUN_080c73c0

	thumb_func_start FUN_080ca430
FUN_080ca430: @ 0x080CA430
	push {r4, lr}
	movs r0, #5
	bl FUN_08022a2c
	adds r4, r0, #0
	cmp r4, #0
	beq _080CA4CC
	movs r0, #0x74
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080CA458
	bl Script_GetValue
	ldr r2, _080CA454 @ =0x00002606
	adds r1, r4, r2
	b _080CA460
	.align 2, 0
_080CA454: .4byte 0x00002606
_080CA458:
	ldr r0, _080CA478 @ =0x00002606
	adds r1, r4, r0
	movs r0, #0x96
	lsls r0, r0, #2
_080CA460:
	strh r0, [r1]
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080CA480
	bl Script_GetValue
	ldr r2, _080CA47C @ =0x00002604
	adds r1, r4, r2
	b _080CA486
	.align 2, 0
_080CA478: .4byte 0x00002606
_080CA47C: .4byte 0x00002604
_080CA480:
	ldr r0, _080CA4A0 @ =0x00002604
	adds r1, r4, r0
	movs r0, #0xb4
_080CA486:
	strh r0, [r1]
	movs r0, #0x70
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080CA4A8
	bl Script_GetValue
	ldr r2, _080CA4A4 @ =0x00002608
	adds r1, r4, r2
	str r0, [r1]
	b _080CA4AE
	.align 2, 0
_080CA4A0: .4byte 0x00002604
_080CA4A4: .4byte 0x00002608
_080CA4A8:
	ldr r2, _080CA4D4 @ =0x00002608
	adds r0, r4, r2
	str r1, [r0]
_080CA4AE:
	ldr r2, _080CA4D8 @ =FUN_080c6538
	movs r0, #0x38
	adds r3, r4, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_080CA4CC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CA4D4: .4byte 0x00002608
_080CA4D8: .4byte FUN_080c6538

	thumb_func_start FUN_080ca4dc
FUN_080ca4dc: @ 0x080CA4DC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r5, #0
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r0, r0, r5
	mov r8, r0
	movs r7, #0
	ldr r0, _080CA500 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0x8f
	lsls r2, r2, #1
	adds r0, r5, r2
	b _080CA67E
	.align 2, 0
_080CA500: .4byte 0x03002B4C
_080CA504:
	ldr r0, _080CA538 @ =0x03002B4C
	ldr r0, [r0]
	lsls r1, r7, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, r8
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	mov r0, r8
	adds r1, r4, #0
	bl FUN_08022474
	ldrb r0, [r4, #6]
	subs r0, #0x12
	cmp r0, #0x1a
	bls _080CA52C
	b _080CA672
_080CA52C:
	lsls r0, r0, #2
	ldr r1, _080CA53C @ =_080CA540
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080CA538: .4byte 0x03002B4C
_080CA53C: .4byte _080CA540
_080CA540: @ jump table
	.4byte _080CA5F0 @ case 0
	.4byte _080CA672 @ case 1
	.4byte _080CA672 @ case 2
	.4byte _080CA672 @ case 3
	.4byte _080CA672 @ case 4
	.4byte _080CA672 @ case 5
	.4byte _080CA672 @ case 6
	.4byte _080CA672 @ case 7
	.4byte _080CA672 @ case 8
	.4byte _080CA672 @ case 9
	.4byte _080CA672 @ case 10
	.4byte _080CA672 @ case 11
	.4byte _080CA672 @ case 12
	.4byte _080CA672 @ case 13
	.4byte _080CA672 @ case 14
	.4byte _080CA672 @ case 15
	.4byte _080CA672 @ case 16
	.4byte _080CA672 @ case 17
	.4byte _080CA672 @ case 18
	.4byte _080CA672 @ case 19
	.4byte _080CA5AC @ case 20
	.4byte _080CA5B8 @ case 21
	.4byte _080CA5E4 @ case 22
	.4byte _080CA5FC @ case 23
	.4byte _080CA62C @ case 24
	.4byte _080CA648 @ case 25
	.4byte _080CA654 @ case 26
_080CA5AC:
	ldr r0, _080CA5B4 @ =0x000025C6
	adds r1, r6, r0
	b _080CA66E
	.align 2, 0
_080CA5B4: .4byte 0x000025C6
_080CA5B8:
	ldr r1, _080CA5DC @ =0x000008F4
	adds r0, r6, r1
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r1, _080CA5E0 @ =FUN_080c5c04
	movs r0, #0x2b
	adds r4, r5, #0
	adds r4, #0xa3
	strb r0, [r4]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r0, #0x1d
	strb r2, [r0]
	b _080CA672
	.align 2, 0
_080CA5DC: .4byte 0x000008F4
_080CA5E0: .4byte FUN_080c5c04
_080CA5E4:
	ldr r2, _080CA5EC @ =FUN_080c5c58
	movs r0, #0x2c
	b _080CA658
	.align 2, 0
_080CA5EC: .4byte FUN_080c5c58
_080CA5F0:
	ldr r2, _080CA5F8 @ =FUN_080c5dd0
	movs r0, #0x2d
	b _080CA658
	.align 2, 0
_080CA5F8: .4byte FUN_080c5dd0
_080CA5FC:
	ldr r2, _080CA624 @ =0x000025FD
	adds r0, r6, r2
	movs r2, #0
	strb r2, [r0]
	ldr r1, _080CA628 @ =FUN_080c6170
	movs r0, #0x33
	adds r3, r5, #0
	adds r3, #0xa3
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r2, [r0]
	adds r1, r5, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
	b _080CA634
	.align 2, 0
_080CA624: .4byte 0x000025FD
_080CA628: .4byte FUN_080c6170
_080CA62C:
	ldr r2, _080CA644 @ =0x000025BC
	adds r0, r6, r2
	movs r1, #1
	strb r1, [r0]
_080CA634:
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #1
	bl FUN_08022488
	b _080CA672
	.align 2, 0
_080CA644: .4byte 0x000025BC
_080CA648:
	ldr r2, _080CA650 @ =FUN_080c60f4
	movs r0, #0x32
	b _080CA658
	.align 2, 0
_080CA650: .4byte FUN_080c60f4
_080CA654:
	ldr r2, _080CA694 @ =FUN_080c6414
	movs r0, #0x37
_080CA658:
	adds r3, r5, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0xa9
_080CA66E:
	movs r0, #1
	strb r0, [r1]
_080CA672:
	adds r7, #1
	ldr r0, _080CA698 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, r8
	adds r0, #6
_080CA67E:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r7, r0
	bge _080CA68A
	b _080CA504
_080CA68A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CA694: .4byte FUN_080c6414
_080CA698: .4byte 0x03002B4C

	thumb_func_start FUN_080ca69c
FUN_080ca69c: @ 0x080CA69C
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_080ca4dc
	adds r2, r4, #0
	adds r2, #0x98
	ldrh r1, [r2]
	str r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080CA6C8
	movs r0, #0x80
	lsls r0, r0, #9
	orrs r1, r0
	str r1, [r2]
	ldr r0, _080CA74C @ =0x0000029E
	adds r2, r4, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_080CA6C8:
	ldr r1, _080CA750 @ =0x0000191C
	adds r5, r4, r1
	ldrh r1, [r5]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080CA6E0
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x10
	bl FUN_080c4a40
_080CA6E0:
	ldrh r1, [r5]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080CA6F4
	adds r0, r4, #0
	movs r1, #4
	movs r2, #0x10
	bl FUN_080c4a40
_080CA6F4:
	ldr r2, _080CA754 @ =0x000025E4
	adds r5, r4, r2
	ldrh r1, [r5]
	cmp r1, #0
	beq _080CA728
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _080CA722
	ldr r3, _080CA758 @ =0x000025D8
	adds r0, r4, r3
	ldr r1, [r0]
	ldr r0, _080CA75C @ =0x000025DC
	adds r2, r4, r0
	subs r3, #3
	adds r0, r4, r3
	ldrb r3, [r0]
	adds r3, #0x80
	movs r0, #0xff
	ands r3, r0
	adds r0, r4, #0
	bl FUN_080c3db4
_080CA722:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
_080CA728:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #0x50]
	str r1, [r4, #0x54]
	adds r1, r4, #0
	adds r1, #0x54
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CA74C: .4byte 0x0000029E
_080CA750: .4byte 0x0000191C
_080CA754: .4byte 0x000025E4
_080CA758: .4byte 0x000025D8
_080CA75C: .4byte 0x000025DC

	thumb_func_start FUN_080ca760
FUN_080ca760: @ 0x080CA760
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	bl FUN_08022ec0
	movs r0, #0xf6
	lsls r0, r0, #1
	adds r3, r5, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _080CA78A
	movs r2, #0x80
	lsls r2, r2, #0xb
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
_080CA78A:
	movs r1, #0x8f
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrh r0, [r2]
	adds r6, r5, #0
	adds r6, #0x98
	cmp r0, #0
	beq _080CA7AA
	movs r0, #0x80
	lsls r0, r0, #0xc
	ldr r1, [r6]
	orrs r1, r0
	str r1, [r6]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
_080CA7AA:
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080CA7BA
	subs r0, #1
	strh r0, [r1]
_080CA7BA:
	movs r0, #0x80
	lsls r0, r0, #0xe
	ldr r1, [r6]
	ands r0, r1
	cmp r0, #0
	beq _080CA7EC
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r1, r0
	str r1, [r6]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r1, #5
	rsbs r1, r1, #0
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #0
	bl FUN_082364c4
	b _080CA7FA
_080CA7EC:
	movs r3, #0x92
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
_080CA7FA:
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	bne _080CA820
	movs r0, #0xac
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_080CA820:
	movs r0, #0x80
	lsls r0, r0, #0xa
	ldr r7, [r6]
	ands r7, r0
	cmp r7, #0
	bne _080CA866
	movs r3, #0xa6
	lsls r3, r3, #2
	adds r4, r5, r3
	ldr r0, _080CA8AC @ =0x000008F3
	adds r6, r5, r0
	ldrb r0, [r6]
	adds r0, #1
	movs r1, #0x98
	muls r1, r0, r1
	movs r2, #0xe3
	lsls r2, r2, #2
	adds r0, r5, r2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080CA866
	strb r7, [r6]
_080CA866:
	movs r3, #0xd4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #0
	bl FUN_082364c4
	movs r3, #0xfc
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r2, #0xbe
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #0
	bl FUN_082364c4
	ldr r0, _080CA8B0 @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0x2c
	ldrsh r1, [r0, r3]
	movs r2, #0x30
	ldrsh r0, [r0, r2]
	adds r4, r1, r0
	ldr r0, _080CA8B4 @ =0x000005FF
	cmp r4, r0
	bgt _080CA904
	adds r0, #1
	subs r0, r0, r4
	cmp r0, #0
	blt _080CA8B8
	asrs r0, r0, #1
	b _080CA8BE
	.align 2, 0
_080CA8AC: .4byte 0x000008F3
_080CA8B0: .4byte 0x03002BE0
_080CA8B4: .4byte 0x000005FF
_080CA8B8:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080CA8BE:
	adds r4, r0, #0
	ldr r0, _080CA8FC @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x2c]
	ldr r2, [r0, #0x30]
	str r1, [sp]
	str r2, [sp, #4]
	mov r1, sp
	ldrh r2, [r1]
	adds r2, r2, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _080CA900 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r3
	orrs r1, r2
	str r1, [sp]
	mov r1, sp
	ldrh r1, [r1, #4]
	adds r1, r1, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, [sp, #4]
	ands r2, r3
	orrs r2, r1
	str r2, [sp, #4]
	mov r1, sp
	bl FUN_0807a91c
	b _080CA946
	.align 2, 0
_080CA8FC: .4byte 0x03002BE0
_080CA900: .4byte 0xFFFF0000
_080CA904:
	movs r0, #0xe8
	lsls r0, r0, #4
	cmp r4, r0
	ble _080CA946
	ldr r3, _080CA918 @ =0xFFFFF180
	adds r0, r4, r3
	cmp r0, #0
	blt _080CA91C
	asrs r0, r0, #1
	b _080CA922
	.align 2, 0
_080CA918: .4byte 0xFFFFF180
_080CA91C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080CA922:
	adds r4, r0, #0
	ldr r0, _080CA968 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x2c]
	ldr r2, [r0, #0x30]
	str r1, [sp]
	str r2, [sp, #4]
	mov r1, sp
	ldrh r1, [r1]
	subs r1, r1, r4
	mov r2, sp
	strh r1, [r2]
	ldrh r1, [r2, #4]
	subs r1, r1, r4
	strh r1, [r2, #4]
	mov r1, sp
	bl FUN_0807a91c
_080CA946:
	ldr r2, _080CA968 @ =0x03002BE0
	ldr r0, [r2]
	movs r3, #0x30
	ldrsh r1, [r0, r3]
	movs r3, #0x2c
	ldrsh r0, [r0, r3]
	subs r4, r1, r0
	ldr r0, _080CA96C @ =0xFFFFFB80
	adds r7, r2, #0
	cmp r4, r0
	bge _080CA99A
	subs r0, r0, r4
	cmp r0, #0
	blt _080CA970
	asrs r0, r0, #1
	b _080CA976
	.align 2, 0
_080CA968: .4byte 0x03002BE0
_080CA96C: .4byte 0xFFFFFB80
_080CA970:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080CA976:
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, r0, r4
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r1, #4]
	adds r0, r0, r4
	strh r0, [r1, #4]
	ldr r0, [r7]
	bl FUN_0807a91c
	b _080CA9DC
_080CA99A:
	movs r0, #0x90
	lsls r0, r0, #3
	cmp r4, r0
	ble _080CA9DC
	ldr r1, _080CA9B0 @ =0xFFFFFB80
	adds r0, r4, r1
	cmp r0, #0
	blt _080CA9B4
	asrs r0, r0, #1
	b _080CA9BA
	.align 2, 0
_080CA9B0: .4byte 0xFFFFFB80
_080CA9B4:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080CA9BA:
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, r0, r4
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r1, #4]
	subs r0, r0, r4
	strh r0, [r1, #4]
	ldr r0, [r7]
	bl FUN_0807a91c
_080CA9DC:
	ldr r2, _080CAA2C @ =0x0000191C
	adds r0, r5, r2
	movs r6, #0
	movs r1, #0
	strh r1, [r0]
	ldr r3, _080CAA30 @ =0x000025D0
	adds r0, r5, r3
	str r1, [r0]
	adds r0, r5, #0
	adds r0, #0xb4
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	ldr r0, _080CAA34 @ =0x000025F8
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #1
	bne _080CAACC
	ldr r0, _080CAA38 @ =0x03002BE0
	ldr r3, [r0]
	ldr r1, [r3, #0x1c]
	adds r7, r0, #0
	cmp r1, #4
	beq _080CAAC4
	movs r1, #0x2c
	ldrsh r2, [r3, r1]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xb
	muls r1, r2, r1
	adds r0, r0, r1
	cmp r0, #0
	blt _080CAA3C
	asrs r1, r0, #4
	b _080CAA42
	.align 2, 0
_080CAA2C: .4byte 0x0000191C
_080CAA30: .4byte 0x000025D0
_080CAA34: .4byte 0x000025F8
_080CAA38: .4byte 0x03002BE0
_080CAA3C:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r1, r0, #0
_080CAA42:
	ldr r2, _080CAA68 @ =0x000025F0
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, [r7]
	movs r3, #0x2e
	ldrsh r2, [r0, r3]
	ldr r1, _080CAA6C @ =0x000002EA
	adds r0, r5, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xb
	muls r1, r2, r1
	adds r0, r0, r1
	cmp r0, #0
	blt _080CAA70
	asrs r1, r0, #4
	b _080CAA76
	.align 2, 0
_080CAA68: .4byte 0x000025F0
_080CAA6C: .4byte 0x000002EA
_080CAA70:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r1, r0, #0
_080CAA76:
	ldr r2, _080CAAA0 @ =0x000025F2
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, [r7]
	movs r3, #0x30
	ldrsh r2, [r0, r3]
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xb
	muls r1, r2, r1
	adds r0, r0, r1
	cmp r0, #0
	blt _080CAAA4
	asrs r2, r0, #4
	b _080CAAAA
	.align 2, 0
_080CAAA0: .4byte 0x000025F2
_080CAAA4:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r2, r0, #0
_080CAAAA:
	ldr r1, _080CAABC @ =0x000025F4
	adds r0, r5, r1
	strh r2, [r0]
	ldr r2, _080CAAC0 @ =0x000025F0
	adds r0, r5, r2
	bl FUN_0823b8ac
	b _080CAB20
	.align 2, 0
_080CAABC: .4byte 0x000025F4
_080CAAC0: .4byte 0x000025F0
_080CAAC4:
	movs r0, #8
	bl FUN_0823b880
	b _080CAB1E
_080CAACC:
	cmp r0, #2
	bne _080CAAFC
	ldr r3, _080CAAF0 @ =0x000025F0
	adds r1, r5, r3
	movs r3, #0x80
	lsls r3, r3, #3
	strh r3, [r1]
	ldr r0, _080CAAF4 @ =0x000025F2
	adds r2, r5, r0
	movs r0, #0xa8
	lsls r0, r0, #1
	strh r0, [r2]
	ldr r2, _080CAAF8 @ =0x000025F4
	adds r0, r5, r2
	strh r3, [r0]
	movs r0, #8
	b _080CAB1A
	.align 2, 0
_080CAAF0: .4byte 0x000025F0
_080CAAF4: .4byte 0x000025F2
_080CAAF8: .4byte 0x000025F4
_080CAAFC:
	cmp r0, #3
	bne _080CAB20
	ldr r3, _080CAB30 @ =0x000025F0
	adds r1, r5, r3
	ldr r3, _080CAB34 @ =0x00000504
	strh r3, [r1]
	ldr r0, _080CAB38 @ =0x000025F2
	adds r2, r5, r0
	movs r0, #0xa8
	lsls r0, r0, #1
	strh r0, [r2]
	ldr r2, _080CAB3C @ =0x000025F4
	adds r0, r5, r2
	strh r3, [r0]
	movs r0, #0x10
_080CAB1A:
	bl FUN_0823b980
_080CAB1E:
	strb r6, [r4]
_080CAB20:
	adds r0, r5, #0
	bl FUN_080c2b24
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CAB30: .4byte 0x000025F0
_080CAB34: .4byte 0x00000504
_080CAB38: .4byte 0x000025F2
_080CAB3C: .4byte 0x000025F4

