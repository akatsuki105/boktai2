	.include "asm/macros.inc"

	.syntax unified
	
	.text

@ ファイルが巨大だったため適当に分割しています。

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
	bl FUN_0822b16c
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
	bl prepare_08231510
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
	bl prepare_08231510
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
	bl prepare_08231510
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

	thumb_func_start FUN_080cab40
FUN_080cab40: @ 0x080CAB40
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_080ca69c
	adds r0, r4, #0
	bl FUN_080ca0fc
	adds r0, r4, #0
	adds r0, #0xa3
	ldrb r0, [r0]
	cmp r0, #0x1e
	bhi _080CAB8C
	ldr r0, _080CAB84 @ =0x000008FE
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r0, _080CAB88 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x30
	ldrsh r1, [r0, r2]
	movs r5, #0xbf
	lsls r5, r5, #2
	adds r0, r4, r5
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r0, r5
	cmp r1, r0
	bge _080CAB94
	adds r0, r4, #0
	bl FUN_080c5854
	b _080CAB94
	.align 2, 0
_080CAB84: .4byte 0x000008FE
_080CAB88: .4byte 0x03002BE0
_080CAB8C:
	ldr r0, _080CABE4 @ =0x000008FE
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_080CAB94:
	adds r0, r4, #0
	bl FUN_080c9cd0
	adds r0, r4, #0
	bl FUN_080c4a74
	adds r0, r4, #0
	bl FUN_080c5828
	adds r0, r4, #0
	bl FUN_080c2d38
	adds r0, r4, #0
	bl FUN_080c373c
	ldr r1, _080CABE8 @ =0x000025BC
	adds r0, r4, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _080CABF8
	ldr r5, _080CABEC @ =0x000025BD
	adds r2, r4, r5
	ldrb r1, [r2]
	cmp r1, #2
	beq _080CAC6E
	adds r5, #1
	adds r0, r4, r5
	strb r1, [r0]
	ldr r0, _080CABF0 @ =0x000025BF
	adds r1, r4, r0
	movs r0, #2
	strb r0, [r1]
	strb r0, [r2]
	ldr r1, _080CABF4 @ =0x000025C1
	adds r0, r4, r1
	strb r3, [r0]
	movs r2, #0x97
	lsls r2, r2, #6
	adds r1, r4, r2
	b _080CAC6A
	.align 2, 0
_080CABE4: .4byte 0x000008FE
_080CABE8: .4byte 0x000025BC
_080CABEC: .4byte 0x000025BD
_080CABF0: .4byte 0x000025BF
_080CABF4: .4byte 0x000025C1
_080CABF8:
	ldr r0, _080CAC30 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _080CAC34 @ =0x00000942
	adds r0, r0, r5
	movs r1, #0
	ldrsh r3, [r0, r1]
	cmp r3, #0
	bne _080CAC44
	ldr r5, _080CAC38 @ =0x000025BD
	adds r2, r4, r5
	ldrb r1, [r2]
	cmp r1, #1
	beq _080CAC6E
	adds r5, #1
	adds r0, r4, r5
	strb r1, [r0]
	ldr r1, _080CAC3C @ =0x000025BF
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	strb r1, [r2]
	ldr r2, _080CAC40 @ =0x000025C1
	adds r0, r4, r2
	strb r3, [r0]
	adds r5, #2
	adds r0, r4, r5
	strb r1, [r0]
	b _080CAC6E
	.align 2, 0
_080CAC30: .4byte 0x030046A0
_080CAC34: .4byte 0x00000942
_080CAC38: .4byte 0x000025BD
_080CAC3C: .4byte 0x000025BF
_080CAC40: .4byte 0x000025C1
_080CAC44:
	ldr r0, _080CAC98 @ =0x000025BD
	adds r3, r4, r0
	ldrb r2, [r3]
	cmp r2, #0
	beq _080CAC6E
	ldr r1, _080CAC9C @ =0x000025BE
	adds r0, r4, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _080CACA0 @ =0x000025BF
	adds r0, r4, r2
	strb r1, [r0]
	strb r1, [r3]
	ldr r5, _080CACA4 @ =0x000025C1
	adds r0, r4, r5
	strb r1, [r0]
	movs r0, #0x97
	lsls r0, r0, #6
	adds r1, r4, r0
_080CAC6A:
	movs r0, #1
	strb r0, [r1]
_080CAC6E:
	adds r0, r4, #0
	bl FUN_080c3af4
	adds r0, r4, #0
	bl FUN_080c3bf0
	movs r1, #0x97
	lsls r1, r1, #6
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CACAC
	ldr r2, _080CAC98 @ =0x000025BD
	adds r0, r4, r2
	ldrb r1, [r0]
	cmp r1, #0
	bne _080CACAC
	ldr r5, _080CACA8 @ =0x000025C8
	adds r0, r4, r5
	strb r1, [r0]
	b _080CACB4
	.align 2, 0
_080CAC98: .4byte 0x000025BD
_080CAC9C: .4byte 0x000025BE
_080CACA0: .4byte 0x000025BF
_080CACA4: .4byte 0x000025C1
_080CACA8: .4byte 0x000025C8
_080CACAC:
	ldr r0, _080CACC4 @ =0x000025C8
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_080CACB4:
	adds r0, r4, #0
	bl FUN_080ca760
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080CACC4: .4byte 0x000025C8

	thumb_func_start FUN_080cacc8
FUN_080cacc8: @ 0x080CACC8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0xc0
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r5, #4
_080CACD4:
	adds r0, r4, #0
	bl FUN_08055d7c
	adds r4, #0x98
	subs r5, #1
	cmp r5, #0
	bge _080CACD4
	movs r1, #0xe5
	lsls r1, r1, #3
	adds r4, r6, r1
	movs r5, #2
_080CACEA:
	adds r0, r4, #0
	bl FUN_08055d7c
	adds r4, #0x98
	subs r5, #1
	cmp r5, #0
	bge _080CACEA
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r6, r1
	bl FUN_08055d7c
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r0, r6, r1
	bl FUN_08055d7c
	adds r0, r6, #0
	bl FUN_080c592c
	adds r0, r6, #0
	bl FUN_080c311c
	adds r0, r6, #0
	bl FUN_080c3764
	adds r0, r6, #0
	bl FUN_080c2b60
	adds r0, r6, #0
	bl FUN_080c3fa0
	adds r0, r6, #0
	bl FUN_08022b04
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080cad38
FUN_080cad38: @ 0x080CAD38
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r5, r0, #0
	str r1, [sp, #4]
	mov r8, r5
	movs r0, #0x74
	movs r1, #5
	bl Script_GetKeywordValue
	str r0, [sp, #8]
	adds r0, r5, #0
	ldr r1, [sp, #8]
	bl FUN_08022a0c
	ldr r0, _080CAD7C @ =0x03002BE0
	ldr r2, [r0]
	cmp r2, #0
	beq _080CAD80
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r5, r1
	str r2, [r0]
	movs r4, #0x86
	lsls r4, r4, #1
	adds r1, r5, r4
	adds r0, r2, #0
	adds r0, #0x2c
	str r0, [r1]
	b _080CAD90
	.align 2, 0
_080CAD7C: .4byte 0x03002BE0
_080CAD80:
	movs r6, #0x82
	lsls r6, r6, #1
	adds r0, r5, r6
	str r2, [r0]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	str r2, [r0]
_080CAD90:
	ldr r0, _080CADD0 @ =0x000092B3
	ldr r1, _080CADD4 @ =0x00005ABD
	bl GetFile
	ldr r2, _080CADD8 @ =0x00001904
	adds r1, r5, r2
	adds r0, #0x14
	str r0, [r1]
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _080CADE0
	bl Script_GetValue
	str r0, [sp, #0xc]
	bl Script_GetValue
	ldr r4, _080CADDC @ =0x00001916
	adds r1, r5, r4
	strh r0, [r1]
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r6, r0, #0
	bl Script_GetValue
	adds r7, r0, #0
	b _080CADF2
	.align 2, 0
_080CADD0: .4byte 0x000092B3
_080CADD4: .4byte 0x00005ABD
_080CADD8: .4byte 0x00001904
_080CADDC: .4byte 0x00001916
_080CADE0:
	ldr r6, _080CAE68 @ =0x00001388
	str r6, [sp, #0xc]
	ldr r0, _080CAE6C @ =0x00001916
	adds r1, r5, r0
	movs r0, #0x78
	strh r0, [r1]
	movs r4, #0x46
	movs r6, #0x32
	movs r7, #0x14
_080CADF2:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080c4520
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_080c468c
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_080c47a0
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _080CAE78
	bl Script_GetValue
	adds r7, r0, #0
	bl Script_GetValue
	adds r6, r0, #0
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	str r0, [sp, #0x10]
	bl Script_GetValue
	str r0, [sp, #0x14]
	bl Script_GetValue
	str r0, [sp, #0x18]
	bl Script_GetValue
	mov sb, r0
	bl Script_GetValue
	str r0, [sp, #0x1c]
	bl Script_GetValue
	str r0, [sp, #0x20]
	bl Script_GetValue
	ldr r2, _080CAE70 @ =0x00001928
	adds r1, r5, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _080CAE74 @ =0x0000192A
	adds r1, r5, r2
	strh r0, [r1]
	bl Script_GetValue
	mov sl, r0
	b _080CAEA6
	.align 2, 0
_080CAE68: .4byte 0x00001388
_080CAE6C: .4byte 0x00001916
_080CAE70: .4byte 0x00001928
_080CAE74: .4byte 0x0000192A
_080CAE78:
	movs r7, #0x64
	movs r6, #0x32
	movs r4, #0x1e
	movs r0, #0x96
	str r0, [sp, #0x10]
	movs r1, #0x96
	str r1, [sp, #0x14]
	movs r2, #0x1e
	str r2, [sp, #0x18]
	movs r0, #0x78
	mov sb, r0
	str r1, [sp, #0x1c]
	str r2, [sp, #0x20]
	ldr r1, _080CAEFC @ =0x00001928
	adds r0, r5, r1
	mov r2, sb
	strh r2, [r0]
	ldr r0, _080CAF00 @ =0x0000192A
	adds r1, r5, r0
	movs r0, #0x5a
	strh r0, [r1]
	movs r1, #0x50
	mov sl, r1
_080CAEA6:
	adds r0, r5, #0
	bl FUN_080c5124
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r6, #0
	adds r3, r4, #0
	bl FUN_080c4840
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r6, #0
	adds r3, r4, #0
	bl FUN_080c48ec
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	mov r1, r8
	adds r1, #0xab
	movs r6, #0
	strb r0, [r1]
	ldrb r4, [r1]
	cmp r4, #0
	bne _080CAEDC
	b _080CB078
_080CAEDC:
	movs r0, #0x44
	movs r1, #0
	bl Script_GetKeywordValue
	adds r4, r0, #0
	adds r0, r5, #0
	bl FUN_080c2ba8
	cmp r4, #1
	beq _080CAFA8
	cmp r4, #1
	bgt _080CAF04
	cmp r4, #0
	beq _080CAF0A
	b _080CB0F8
	.align 2, 0
_080CAEFC: .4byte 0x00001928
_080CAF00: .4byte 0x0000192A
_080CAF04:
	cmp r4, #2
	beq _080CAFEC
	b _080CB0F8
_080CAF0A:
	ldr r2, _080CAF78 @ =0x00001934
	adds r0, r5, r2
	ldr r4, _080CAF7C @ =0x080C26CD
	adds r1, r4, #0
	bl FUN_080c2680
	ldr r1, _080CAF80 @ =0x00001BDC
	adds r0, r5, r1
	adds r1, r4, #0
	bl FUN_080c2680
	ldr r2, _080CAF84 @ =0x00001E84
	adds r0, r5, r2
	adds r1, r4, #0
	bl FUN_080c2680
	ldr r1, _080CAF88 @ =0x0000212C
	adds r0, r5, r1
	adds r1, r4, #0
	bl FUN_080c2680
	ldr r2, _080CAF8C @ =0x000008F4
	adds r0, r5, r2
	strb r6, [r0]
	ldr r4, _080CAF90 @ =0x000008F5
	adds r0, r5, r4
	strb r6, [r0]
	ldr r1, _080CAF94 @ =0x000008F6
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _080CAF98 @ =0x000025C5
	adds r0, r5, r2
	movs r2, #1
	strb r2, [r0]
	ldr r4, _080CAF9C @ =0x000025C6
	adds r0, r5, r4
	strb r6, [r0]
	ldr r1, _080CAFA0 @ =0x000025C7
	adds r0, r5, r1
	strb r6, [r0]
	subs r4, #0xa
	adds r0, r5, r4
	strb r6, [r0]
	ldr r1, _080CAFA4 @ =FUN_080c5b6c
	movs r0, #0x2a
	mov r3, r8
	adds r3, #0xa3
	strb r0, [r3]
	mov r0, r8
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	b _080CB0F4
	.align 2, 0
_080CAF78: .4byte 0x00001934
_080CAF7C: .4byte 0x080C26CD
_080CAF80: .4byte 0x00001BDC
_080CAF84: .4byte 0x00001E84
_080CAF88: .4byte 0x0000212C
_080CAF8C: .4byte 0x000008F4
_080CAF90: .4byte 0x000008F5
_080CAF94: .4byte 0x000008F6
_080CAF98: .4byte 0x000025C5
_080CAF9C: .4byte 0x000025C6
_080CAFA0: .4byte 0x000025C7
_080CAFA4: .4byte FUN_080c5b6c
_080CAFA8:
	ldr r1, _080CAFDC @ =0x000008F4
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _080CAFE0 @ =0x000008F5
	adds r0, r5, r2
	strb r6, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _080CAFE4 @ =0x000025BC
	adds r0, r5, r2
	strb r4, [r0]
	ldr r1, _080CAFE8 @ =FUN_080c6060
	movs r0, #0x31
	mov r2, r8
	adds r2, #0xa3
	strb r0, [r2]
	mov r0, r8
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	adds r0, #0x1d
	strb r4, [r0]
	b _080CB0F8
	.align 2, 0
_080CAFDC: .4byte 0x000008F4
_080CAFE0: .4byte 0x000008F5
_080CAFE4: .4byte 0x000025BC
_080CAFE8: .4byte FUN_080c6060
_080CAFEC:
	adds r0, r5, #0
	bl FUN_080c3f30
	movs r4, #0xbe
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrh r1, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r3, #0
	strh r1, [r0]
	adds r4, #2
	adds r0, r5, r4
	subs r2, #0xe8
	adds r1, r2, #0
	ldrh r0, [r0]
	adds r2, r1, r0
	subs r4, #0x10
	adds r0, r5, r4
	strh r2, [r0]
	movs r2, #0xbf
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	adds r1, r1, r0
	adds r4, #2
	adds r0, r5, r4
	strh r1, [r0]
	ldr r1, _080CB064 @ =0x000008F4
	adds r0, r5, r1
	movs r2, #1
	strb r2, [r0]
	ldr r4, _080CB068 @ =0x000008F5
	adds r1, r5, r4
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080CB06C @ =0x000008F6
	adds r0, r5, r1
	strb r3, [r0]
	ldr r4, _080CB070 @ =0x000025BC
	adds r0, r5, r4
	strb r2, [r0]
	ldr r1, _080CB074 @ =FUN_080c6354
	movs r0, #0x36
	mov r3, r8
	adds r3, #0xa3
	strb r0, [r3]
	mov r0, r8
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	adds r0, #0x1d
	strb r2, [r0]
	movs r0, #2
	bl FUN_0809c08c
	b _080CB0F8
	.align 2, 0
_080CB064: .4byte 0x000008F4
_080CB068: .4byte 0x000008F5
_080CB06C: .4byte 0x000008F6
_080CB070: .4byte 0x000025BC
_080CB074: .4byte FUN_080c6354
_080CB078:
	adds r0, r5, #0
	ldr r1, [sp, #0x10]
	ldr r2, [sp, #0x14]
	ldr r3, [sp, #0x18]
	bl FUN_080c59f4
	adds r0, r5, #0
	mov r1, sl
	bl FUN_080c314c
	adds r0, r5, #0
	mov r1, sb
	ldr r2, [sp, #0x1c]
	ldr r3, [sp, #0x20]
	bl FUN_080c3784
	movs r0, #0x64
	movs r1, #0x64
	bl FUN_082464b8
	movs r6, #0xc8
	lsls r6, r6, #5
	adds r1, r5, r6
	str r0, [r1]
	ldr r1, _080CB10C @ =0x000008F4
	adds r0, r5, r1
	movs r2, #1
	strb r2, [r0]
	ldr r6, _080CB110 @ =0x000008F5
	adds r1, r5, r6
	movs r0, #8
	strb r0, [r1]
	ldr r1, _080CB114 @ =0x000008F6
	adds r0, r5, r1
	strb r4, [r0]
	ldr r6, _080CB118 @ =0x0000260E
	adds r1, r5, r6
	movs r3, #0
	movs r0, #0xa
	strh r0, [r1]
	ldr r0, _080CB11C @ =0x0000260D
	adds r1, r5, r0
	movs r0, #2
	strb r0, [r1]
	ldr r1, _080CB120 @ =0x00001909
	adds r0, r5, r1
	movs r1, #3
	strb r1, [r0]
	ldr r6, _080CB124 @ =0x0000190B
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _080CB128 @ =0x000025BC
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, _080CB12C @ =FUN_080c6c8c
	mov r0, r8
	adds r0, #0xa3
	strb r3, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
_080CB0F4:
	adds r0, #0x1d
	strb r2, [r0]
_080CB0F8:
	movs r0, #0x78
	bl prepare_08231510
	cmp r0, #0
	beq _080CB134
	bl Script_GetValue
	ldr r2, _080CB130 @ =0x000025CC
	adds r1, r5, r2
	b _080CB13A
	.align 2, 0
_080CB10C: .4byte 0x000008F4
_080CB110: .4byte 0x000008F5
_080CB114: .4byte 0x000008F6
_080CB118: .4byte 0x0000260E
_080CB11C: .4byte 0x0000260D
_080CB120: .4byte 0x00001909
_080CB124: .4byte 0x0000190B
_080CB128: .4byte 0x000025BC
_080CB12C: .4byte FUN_080c6c8c
_080CB130: .4byte 0x000025CC
_080CB134:
	ldr r4, _080CB150 @ =0x000025CC
	adds r1, r5, r4
	movs r0, #2
_080CB13A:
	strh r0, [r1]
	movs r0, #0x4b
	bl prepare_08231510
	cmp r0, #0
	beq _080CB158
	bl Script_GetValue
	ldr r6, _080CB154 @ =0x000025CE
	adds r1, r5, r6
	b _080CB15E
	.align 2, 0
_080CB150: .4byte 0x000025CC
_080CB154: .4byte 0x000025CE
_080CB158:
	ldr r0, _080CB1A8 @ =0x000025CE
	adds r1, r5, r0
	movs r0, #2
_080CB15E:
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r3, r5, r1
	movs r0, #0x40
	str r0, [sp]
	mov r0, r8
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	bl FUN_08022a70
	mov r0, r8
	ldr r1, [sp, #0xc]
	adds r2, r1, #0
	movs r3, #0xc8
	bl FUN_08022b2c
	ldr r1, _080CB1AC @ =FUN_080c9d00
	mov r0, r8
	adds r0, #0xfc
	str r1, [r0]
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _080CB1B0
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r2, r0, #0
	mov r0, r8
	adds r1, r4, #0
	bl FUN_08022fac
	b _080CB1BA
	.align 2, 0
_080CB1A8: .4byte 0x000025CE
_080CB1AC: .4byte FUN_080c9d00
_080CB1B0:
	mov r0, r8
	movs r1, #0
	movs r2, #0
	bl FUN_08022fac
_080CB1BA:
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _080CB1E0
	movs r4, #0
	mov r6, r8
	adds r6, #0xe8
	b _080CB1D4
_080CB1CC:
	bl Script_GetValue
	stm r6!, {r0}
	adds r4, #1
_080CB1D4:
	cmp r4, #3
	bgt _080CB1E0
	bl VM_GetPC
	cmp r0, #0
	bne _080CB1CC
_080CB1E0:
	ldr r2, _080CB200 @ =0x000025F8
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080c3b80
	movs r0, #0
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080CB200: .4byte 0x000025F8

	thumb_func_start FUN_080cb204
FUN_080cb204: @ 0x080CB204
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #5
	bl FUN_08022a2c
	adds r4, r0, #0
	cmp r4, #0
	bne _080CB24E
	ldr r1, _080CB240 @ =0x00002610
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080CB24C
	ldr r1, _080CB244 @ =FUN_080cab40
	ldr r2, _080CB248 @ =FUN_080cacc8
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080cad38
	cmp r0, #0
	bge _080CB24C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080CB24E
	.align 2, 0
_080CB240: .4byte 0x00002610
_080CB244: .4byte FUN_080cab40
_080CB248: .4byte FUN_080cacc8
_080CB24C:
	adds r0, r4, #0
_080CB24E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080cb254
FUN_080cb254: @ 0x080CB254
	bx lr
	.align 2, 0

	thumb_func_start FUN_080cb258
FUN_080cb258: @ 0x080CB258
	bx lr
	.align 2, 0

	thumb_func_start FUN_080cb25c
FUN_080cb25c: @ 0x080CB25C
	push {r4, lr}
	adds r1, r0, #0
	adds r4, r1, #0
	adds r4, #0x64
	adds r1, #0x38
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080cb27c
FUN_080cb27c: @ 0x080CB27C
	push {lr}
	adds r0, #0x1c
	bl FUN_0822a4e0
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080cb28c
FUN_080cb28c: @ 0x080CB28C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x48
	ldr r1, _080CB2C4 @ =0x00009DA7
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r5, #0
	adds r0, #0x1c
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080CB2C8
	bl Script_GetValue
	strh r0, [r5, #0x38]
	bl Script_GetValue
	strh r0, [r5, #0x3a]
	bl Script_GetValue
	b _080CB2CC
	.align 2, 0
_080CB2C4: .4byte 0x00009DA7
_080CB2C8:
	strh r0, [r5, #0x38]
	strh r0, [r5, #0x3a]
_080CB2CC:
	strh r0, [r5, #0x3c]
	adds r6, r5, #0
	adds r6, #0x38
	ldrh r0, [r5, #0x38]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080CB2F6
	cmp r1, #0
	blt _080CB2F6
	ldr r0, _080CB2FC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080CB2F6
	ldr r0, _080CB300 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080CB304
_080CB2F6:
	movs r4, #0
	b _080CB312
	.align 2, 0
_080CB2FC: .4byte 0x030046A8
_080CB300: .4byte 0x030046AC
_080CB304:
	ldr r0, _080CB324 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080CB312:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080CB328
	adds r0, #4
	b _080CB334
	.align 2, 0
_080CB324: .4byte 0x030046A4
_080CB328:
	ldr r0, _080CB348 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080CB334:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080CB34C
	cmp r2, #2
	beq _080CB350
	b _080CB354
	.align 2, 0
_080CB348: .4byte 0x030046A4
_080CB34C:
	ldrb r0, [r6, #4]
	b _080CB352
_080CB350:
	ldrb r0, [r6]
_080CB352:
	subs r1, r1, r0
_080CB354:
	strh r1, [r5, #0x3a]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cb35c
FUN_080cb35c: @ 0x080CB35C
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x64
	ldr r2, _080CB3DC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x32
	orrs r0, r3
	ldr r1, _080CB3E0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldrh r1, [r4, #0x18]
	ldr r2, _080CB3E4 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r0, _080CB3E8 @ =0x00040002
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x64
	movs r2, #0x78
	movs r3, #0
	bl FUN_082364f8
	ldr r1, _080CB3EC @ =FUN_080cb254
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_0823651c
	adds r4, #0x38
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CB3DC: .4byte 0xFFFF0000
_080CB3E0: .4byte 0x0000FFFF
_080CB3E4: .4byte 0x00002001
_080CB3E8: .4byte 0x00040002
_080CB3EC: .4byte FUN_080cb254

	thumb_func_start FUN_080cb3f0
FUN_080cb3f0: @ 0x080CB3F0
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xb4
	ldr r2, _080CB468 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x32
	orrs r0, r3
	ldr r1, _080CB46C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldrh r1, [r4, #0x18]
	ldr r2, _080CB470 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r5, #0
	movs r1, #0xa
	movs r2, #2
	movs r3, #1
	bl FUN_08236514
	ldr r1, _080CB474 @ =FUN_080cb258
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_0823651c
	adds r4, #0x38
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CB468: .4byte 0xFFFF0000
_080CB46C: .4byte 0x0000FFFF
_080CB470: .4byte 0x00004001
_080CB474: .4byte FUN_080cb258

	thumb_func_start FUN_080cb478
FUN_080cb478: @ 0x080CB478
	push {r4, lr}
	adds r4, r0, #0
	strh r1, [r4, #0x18]
	bl FUN_080cb28c
	adds r0, r4, #0
	bl FUN_080cb35c
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080cb490
FUN_080cb490: @ 0x080CB490
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x82
	lsls r1, r1, #1
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080CB4D0
	ldr r1, _080CB4C8 @ =FUN_080cb25c
	ldr r2, _080CB4CC @ =FUN_080cb27c
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080cb478
	cmp r0, #0
	bge _080CB4D0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080CB4D2
	.align 2, 0
_080CB4C8: .4byte FUN_080cb25c
_080CB4CC: .4byte FUN_080cb27c
_080CB4D0:
	adds r0, r4, #0
_080CB4D2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080cb4d8
FUN_080cb4d8: @ 0x080CB4D8
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r0, #0x24
	ldrsh r1, [r4, r0]
	adds r0, r4, #0
	adds r0, #0xd4
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r2, r1, r0
	movs r3, #0x28
	ldrsh r1, [r4, r3]
	adds r0, r4, #0
	adds r0, #0xd8
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	cmp r2, #0
	bne _080CB502
	cmp r1, #0
	beq _080CB562
_080CB502:
	adds r0, r2, #0
	bl FUN_0823785c
	adds r3, r0, #0
	ldr r2, _080CB528 @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CB52C
	asrs r0, r0, #0xc
	b _080CB532
	.align 2, 0
_080CB528: .4byte 0x085B0A08
_080CB52C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CB532:
	rsbs r0, r0, #0
	strh r0, [r4, #0x2c]
	ldr r1, _080CB554 @ =0x085B0A08
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CB558
	asrs r0, r0, #0xc
	b _080CB55E
	.align 2, 0
_080CB554: .4byte 0x085B0A08
_080CB558:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CB55E:
	rsbs r0, r0, #0
	strh r0, [r4, #0x30]
_080CB562:
	adds r0, r4, #0
	adds r0, #0x1c
	bl FUN_0823b4b8
	adds r5, r4, #0
	adds r5, #0xb8
	adds r4, #0x24
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08236268
	ldr r0, _080CB5AC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080CB5A2
	ldr r0, _080CB5B0 @ =0x030046A0
	ldr r1, [r0]
	ldr r2, _080CB5B4 @ =0xFFFF0000
	ldrh r0, [r1, #0x30]
	str r0, [sp]
	ldrh r1, [r1, #0x34]
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r1, r4, #0
	mov r2, sp
	bl FUN_08235f40
_080CB5A2:
	movs r0, #0
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080CB5AC: .4byte 0x030044E0
_080CB5B0: .4byte 0x030046A0
_080CB5B4: .4byte 0xFFFF0000

	thumb_func_start FUN_080cb5b8
FUN_080cb5b8: @ 0x080CB5B8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x60
	bl FUN_0822a4e0
	adds r4, #0x1c
	adds r0, r4, #0
	bl FUN_0823b284
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080cb5d4
FUN_080cb5d4: @ 0x080CB5D4
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080CB620
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080CB618 @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080CB61C @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	b _080CB62A
	.align 2, 0
_080CB618: .4byte 0xFFFF0000
_080CB61C: .4byte 0x0000FFFF
_080CB620:
	ldr r1, _080CB658 @ =0xFFFF0000
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
_080CB62A:
	add r5, sp, #8
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080CB652
	cmp r1, #0
	blt _080CB652
	ldr r0, _080CB65C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080CB652
	ldr r0, _080CB660 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080CB664
_080CB652:
	movs r4, #0
	b _080CB672
	.align 2, 0
_080CB658: .4byte 0xFFFF0000
_080CB65C: .4byte 0x030046A8
_080CB660: .4byte 0x030046AC
_080CB664:
	ldr r0, _080CB684 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080CB672:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080CB688
	adds r0, #4
	b _080CB694
	.align 2, 0
_080CB684: .4byte 0x030046A4
_080CB688:
	ldr r0, _080CB6A8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080CB694:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080CB6AC
	cmp r2, #2
	beq _080CB6B0
	b _080CB6B4
	.align 2, 0
_080CB6A8: .4byte 0x030046A4
_080CB6AC:
	ldrb r0, [r5, #4]
	b _080CB6B2
_080CB6B0:
	ldrb r0, [r5]
_080CB6B2:
	subs r1, r1, r0
_080CB6B4:
	add r0, sp, #8
	strh r1, [r0, #2]
	adds r0, r6, #0
	adds r0, #0x1c
	ldrh r1, [r6, #0x18]
	movs r2, #7
	str r2, [sp]
	str r6, [sp, #4]
	add r2, sp, #8
	movs r3, #0
	bl FUN_0823b400
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cb6d4
FUN_080cb6d4: @ 0x080CB6D4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x8c
	ldr r1, _080CB710 @ =0x00009DA7
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r5, r6, #0
	adds r5, #0x60
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r6, #0
	adds r0, #0x1c
	adds r1, r5, #0
	bl FUN_0823b46c
	adds r2, r6, #0
	adds r2, #0x7c
	ldr r0, [r6, #0x24]
	ldr r1, [r6, #0x28]
	str r0, [r2]
	str r1, [r2, #4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CB710: .4byte 0x00009DA7

	thumb_func_start FUN_080cb714
FUN_080cb714: @ 0x080CB714
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xa8
	adds r1, r5, #0
	adds r1, #0x24
	adds r0, r4, #0
	bl FUN_0823280c
	adds r0, r5, #0
	adds r0, #0x1c
	adds r1, r4, #0
	movs r2, #0x1e
	movs r3, #0x1e
	bl FUN_0823b43c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080cb73c
FUN_080cb73c: @ 0x080CB73C
	push {lr}
	adds r1, r0, #0
	adds r0, #0xb8
	adds r1, #0x24
	bl FUN_082362fc
	pop {r0}
	bx r0

	thumb_func_start FUN_080cb74c
FUN_080cb74c: @ 0x080CB74C
	push {r4, lr}
	adds r4, r0, #0
	strh r1, [r4, #0x18]
	bl FUN_080cb5d4
	adds r0, r4, #0
	bl FUN_080cb6d4
	adds r0, r4, #0
	bl FUN_080cb714
	adds r0, r4, #0
	bl FUN_080cb73c
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080cb770
FUN_080cb770: @ 0x080CB770
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #8
	movs r1, #0xdc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080CB7AC
	ldr r1, _080CB7A4 @ =FUN_080cb4d8
	ldr r2, _080CB7A8 @ =FUN_080cb5b8
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080cb74c
	cmp r0, #0
	bge _080CB7AC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080CB7AE
	.align 2, 0
_080CB7A4: .4byte FUN_080cb4d8
_080CB7A8: .4byte FUN_080cb5b8
_080CB7AC:
	adds r0, r4, #0
_080CB7AE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080cb7b4
FUN_080cb7b4: @ 0x080CB7B4
	adds r1, r2, #0
	adds r1, #0xb8
	movs r0, #1
	str r0, [r1]
	adds r2, #0xbe
	movs r0, #0
	strh r0, [r2]
	bx lr

	thumb_func_start FUN_080cb7c4
FUN_080cb7c4: @ 0x080CB7C4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r7, r6, #0
	adds r7, #0xb8
	ldr r0, [r7]
	mov r8, r0
	cmp r0, #0
	beq _080CB860
	adds r1, r6, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _080CB7F0
	movs r0, #4
	strh r0, [r6, #0x28]
	b _080CB8DC
_080CB7F0:
	cmp r0, #4
	bne _080CB854
	adds r0, r6, #0
	adds r0, #0xbc
	adds r4, r6, #0
	adds r4, #0x18
	ldrh r1, [r0]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _080CB80C
	movs r0, #7
	b _080CB81A
_080CB80C:
	asrs r0, r1, #1
	ands r0, r2
	cmp r0, #0
	beq _080CB818
	movs r0, #8
	b _080CB81A
_080CB818:
	movs r0, #6
_080CB81A:
	strh r0, [r4, #0x10]
	cmp r1, #2
	bgt _080CB828
	ldr r0, [r4]
	movs r1, #0xd
	rsbs r1, r1, #0
	b _080CB84E
_080CB828:
	cmp r1, #4
	bgt _080CB838
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #8
	b _080CB840
_080CB838:
	cmp r1, #5
	bgt _080CB846
	ldr r0, [r4]
	movs r1, #0xc
_080CB840:
	orrs r0, r1
	str r0, [r4]
	b _080CB8DC
_080CB846:
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	subs r1, #0xd
_080CB84E:
	ands r0, r1
	str r0, [r4]
	b _080CB8DC
_080CB854:
	cmp r0, #6
	bls _080CB8DC
	adds r0, r6, #0
	bl KillEntity
	b _080CB8DC
_080CB860:
	adds r0, r6, #0
	adds r0, #0xb0
	ldrh r0, [r0]
	ldrh r1, [r6, #0x34]
	adds r0, r0, r1
	strh r0, [r6, #0x34]
	adds r0, r6, #0
	adds r0, #0xb4
	ldrh r0, [r0]
	ldrh r2, [r6, #0x38]
	adds r0, r0, r2
	strh r0, [r6, #0x38]
	adds r4, r6, #0
	adds r4, #0x60
	adds r5, r6, #0
	adds r5, #0x34
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	ldr r0, _080CB8BC @ =0x03002BE0
	ldr r2, [r0]
	ldr r1, _080CB8C0 @ =0x00080002
	ldr r0, [r2, #0x20]
	orrs r0, r1
	str r0, [r2, #0x20]
	adds r0, r5, #0
	bl FUN_082328ec
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0x36
	ldrsh r1, [r6, r2]
	cmp r0, r1
	ble _080CB8C4
	movs r0, #1
	str r0, [r7]
	adds r0, r6, #0
	adds r0, #0xbe
	mov r1, r8
	strh r1, [r0]
	b _080CB8DC
	.align 2, 0
_080CB8BC: .4byte 0x03002BE0
_080CB8C0: .4byte 0x00080002
_080CB8C4:
	adds r1, r6, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080CB8DC
	adds r0, r6, #0
	bl KillEntity
_080CB8DC:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080cb8e8
FUN_080cb8e8: @ 0x080CB8E8
	push {lr}
	adds r0, #0x18
	bl FUN_0822a4e0
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080cb8f8
FUN_080cb8f8: @ 0x080CB8F8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	mov sb, r1
	mov r8, r2
	adds r6, r3, #0
	adds r4, r7, #0
	adds r4, #0x44
	ldr r1, _080CB948 @ =0x0000210E
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r5, r7, #0
	adds r5, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	mov r0, r8
	strh r0, [r5, #0x10]
	adds r6, #0x2c
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_0822b20c
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CB948: .4byte 0x0000210E

	thumb_func_start FUN_080cb94c
FUN_080cb94c: @ 0x080CB94C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r4, r0, #0
	mov sl, r1
	mov r8, r2
	mov sb, r3
	ldr r6, [sp, #0x3c]
	ldr r7, [sp, #0x40]
	adds r5, r4, #0
	adds r5, #0x60
	ldr r2, _080CB9EC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x1e
	orrs r0, r3
	ldr r1, _080CB9F0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _080CB9F4 @ =0x00002101
	movs r0, #1
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0x10
	bl FUN_082364f8
	ldr r1, _080CB9F8 @ =FUN_080cb7b4
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_0823651c
	adds r1, r4, #0
	adds r1, #0x34
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r4, #0xa2
	mov r0, sl
	strb r0, [r4]
	adds r0, r5, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CB9EC: .4byte 0xFFFF0000
_080CB9F0: .4byte 0x0000FFFF
_080CB9F4: .4byte 0x00002101
_080CB9F8: .4byte FUN_080cb7b4

	thumb_func_start FUN_080cb9fc
FUN_080cb9fc: @ 0x080CB9FC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r2, #0
	mov r8, r3
	ldr r2, [sp, #0x20]
	ldr r3, [sp, #0x24]
	ldr r4, [sp, #0x30]
	ldr r5, [sp, #0x34]
	bl FUN_080cb8f8
	str r4, [sp]
	str r5, [sp, #4]
	adds r0, r7, #0
	adds r1, r6, #0
	ldr r2, [sp, #0x28]
	ldr r3, [sp, #0x2c]
	bl FUN_080cb94c
	ldr r2, _080CBA48 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _080CBA4C
	asrs r2, r0, #0xc
	b _080CBA52
	.align 2, 0
_080CBA48: .4byte 0x085B0A08
_080CBA4C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080CBA52:
	adds r0, r7, #0
	adds r0, #0xb0
	movs r1, #0
	strh r2, [r0]
	adds r0, #2
	strh r1, [r0]
	ldr r1, _080CBA7C @ =0x085B0A08
	movs r0, #0xff
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _080CBA80
	asrs r3, r0, #0xc
	b _080CBA86
	.align 2, 0
_080CBA7C: .4byte 0x085B0A08
_080CBA80:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080CBA86:
	adds r0, r7, #0
	adds r0, #0xb4
	movs r2, #0
	strh r3, [r0]
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	adds r1, r7, #0
	adds r1, #0xbc
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0xbe
	strh r2, [r0]
	movs r0, #0
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080cbabc
FUN_080cbabc: @ 0x080CBABC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r0, #8
	movs r1, #0xc0
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080CBB1C
	ldr r1, _080CBB14 @ =FUN_080cb7c4
	ldr r2, _080CBB18 @ =FUN_080cb8e8
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x30]
	str r0, [sp, #4]
	ldr r0, [sp, #0x34]
	str r0, [sp, #8]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x40]
	str r0, [sp, #0x14]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_080cb9fc
	cmp r0, #0
	bge _080CBB1C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080CBB1E
	.align 2, 0
_080CBB14: .4byte FUN_080cb7c4
_080CBB18: .4byte FUN_080cb8e8
_080CBB1C:
	adds r0, r4, #0
_080CBB1E:
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080cbb2c
FUN_080cbb2c: @ 0x080CBB2C
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r3, r0, #0
	mov r2, sp
	ldr r0, _080CBB64 @ =0x08251E08
	ldm r0!, {r4, r5, r6}
	stm r2!, {r4, r5, r6}
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r2, r3, r0
	movs r0, #0
	strh r1, [r2]
	movs r4, #0x9b
	lsls r4, r4, #1
	adds r1, r3, r4
	strh r0, [r1]
	movs r5, #0x9c
	lsls r5, r5, #1
	adds r1, r3, r5
	ldrh r0, [r2]
	lsls r0, r0, #2
	add r0, sp
	ldr r0, [r0]
	str r0, [r1]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CBB64: .4byte 0x08251E08

	thumb_func_start FUN_080cbb68
FUN_080cbb68: @ 0x080CBB68
	push {r4, lr}
	sub sp, #0x10
	adds r3, r1, #0
	ldr r4, [r0, #0x38]
	cmp r3, #0
	bne _080CBBB4
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #2
	beq _080CBBD4
	cmp r2, #0
	ble _080CBBA6
	ldr r1, _080CBBB0 @ =0xFFFF0000
	str r3, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r0, #0xb8
	adds r3, r4, #0
	adds r3, #0x24
	add r1, sp, #8
	str r1, [sp]
	movs r1, #1
	str r1, [sp, #4]
	adds r1, r2, #0
	movs r2, #0
	bl FUN_0805fe7c
_080CBBA6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080cbb2c
	b _080CBBD4
	.align 2, 0
_080CBBB0: .4byte 0xFFFF0000
_080CBBB4:
	cmp r3, #1
	bne _080CBBD4
	movs r1, #0x99
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r2, [r0]
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1, #4]
	orrs r0, r3
	str r0, [r1, #4]
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080cbb2c
_080CBBD4:
	movs r0, #1
	add sp, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080cbbe0
FUN_080cbbe0: @ 0x080CBBE0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r3, r6, #0
	adds r3, #0x21
	ldrb r2, [r3]
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r7, [r0]
	cmp r2, r7
	beq _080CBC10
	ldrh r0, [r0]
	subs r0, r0, r2
	subs r1, #0x2c
	adds r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	cmp r0, #0x7f
	bgt _080CBC0A
	adds r0, r2, #4
	b _080CBC0E
_080CBC0A:
	adds r0, r2, #0
	adds r0, #0xfc
_080CBC0E:
	strb r0, [r3]
_080CBC10:
	movs r7, #0x97
	lsls r7, r7, #1
	adds r7, r7, r6
	mov ip, r7
	ldrh r0, [r7]
	cmp r0, #0
	bne _080CBC64
	ldr r5, _080CBC58 @ =0x0203B400
	ldr r4, _080CBC5C @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _080CBC60 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	movs r7, #0x96
	lsls r7, r7, #1
	adds r2, r6, r7
	strh r0, [r2]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x78
	mov r1, ip
	strh r0, [r1]
	b _080CBC6A
	.align 2, 0
_080CBC58: .4byte 0x0203B400
_080CBC5C: .4byte 0x030046B8
_080CBC60: .4byte 0x000003FF
_080CBC64:
	subs r0, #1
	mov r7, ip
	strh r0, [r7]
_080CBC6A:
	adds r4, r6, #0
	adds r4, #0xb8
	adds r1, r6, #0
	adds r1, #0x24
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #7
	strh r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cbc90
FUN_080cbc90: @ 0x080CBC90
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x9b
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #5
	bhi _080CBCAC
	adds r0, r4, #0
	adds r0, #0x8c
	subs r1, #4
	bl FUN_0822b20c
	b _080CBCB6
_080CBCAC:
	adds r0, r4, #0
	adds r0, #0x8c
	ldr r1, _080CBCD4 @ =0x00000133
	bl FUN_0822b20c
_080CBCB6:
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #2
	strh r0, [r1]
	movs r0, #0x9b
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CBCD4: .4byte 0x00000133

	thumb_func_start FUN_080cbcd8
FUN_080cbcd8: @ 0x080CBCD8
	push {r4, lr}
	mov ip, r0
	movs r0, #0x98
	lsls r0, r0, #1
	add r0, ip
	movs r1, #2
	strh r1, [r0]
	movs r1, #0x99
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	cmp r0, #0
	beq _080CBD62
	adds r4, r0, #0
	ldr r2, _080CBD14 @ =0x085B0A08
	mov r3, ip
	adds r3, #0x21
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080CBD18
	asrs r4, r0, #0xc
	b _080CBD1E
	.align 2, 0
_080CBD14: .4byte 0x085B0A08
_080CBD18:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r4, r0, #0
_080CBD1E:
	mov r1, ip
	ldrh r0, [r1, #0x2c]
	adds r0, r0, r4
	strh r0, [r1, #0x2c]
	movs r0, #0x99
	lsls r0, r0, #1
	add r0, ip
	ldrh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080CBD42
	asrs r1, r0, #0xc
	b _080CBD48
_080CBD42:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CBD48:
	mov r2, ip
	ldrh r0, [r2, #0x30]
	adds r0, r0, r1
	strh r0, [r2, #0x30]
	movs r2, #0x99
	lsls r2, r2, #1
	add r2, ip
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _080CBD8E
_080CBD62:
	mov r1, ip
	adds r1, #0x21
	ldrb r0, [r1]
	adds r0, #0x80
	strb r0, [r1]
	ldrb r1, [r1]
	movs r0, #0x96
	lsls r0, r0, #1
	add r0, ip
	strh r1, [r0]
	movs r2, #0x8e
	lsls r2, r2, #1
	add r2, ip
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2, #4]
	ands r0, r1
	str r0, [r2, #4]
	mov r0, ip
	movs r1, #0
	bl FUN_080cbb2c
_080CBD8E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cbd94
FUN_080cbd94: @ 0x080CBD94
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r0, #0x21
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r3, #3
	ands r0, r3
	cmp r0, #1
	ble _080CBDB6
	subs r3, r3, r0
	movs r6, #1
	b _080CBDBA
_080CBDB6:
	adds r3, r0, #0
	movs r6, #0
_080CBDBA:
	movs r0, #0x84
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #0x98
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r2, [r0]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r6, [sp]
	adds r0, r4, #0
	bl FUN_08236fac
	adds r7, r5, #0
	adds r7, #0x60
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _080CBE0C
	ldr r0, [r5, #0x60]
	movs r1, #4
	orrs r0, r1
	b _080CBE14
_080CBE0C:
	ldr r0, [r5, #0x60]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080CBE14:
	str r0, [r5, #0x60]
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
	beq _080CBE38
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080CBE40
_080CBE38:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080CBE40:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080CBE78 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080CBEB0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080CBE7C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080CBE70
	ldrb r0, [r4, #5]
_080CBE70:
	subs r0, #1
	strh r0, [r4, #8]
	b _080CBE8C
	.align 2, 0
_080CBE78: .4byte 0x0000FFFF
_080CBE7C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080CBE8C
	strh r1, [r4, #8]
_080CBE8C:
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
	bne _080CBEB0
	movs r0, #1
	strb r0, [r4, #7]
_080CBEB0:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cbeb8
FUN_080cbeb8: @ 0x080CBEB8
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080cbd94
	adds r4, #0x1c
	adds r0, r4, #0
	bl FUN_0823b4b8
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080cbee0
FUN_080cbee0: @ 0x080CBEE0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x60
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0x1c
	bl FUN_0823b284
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_0807f598
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080cbf04
FUN_080cbf04: @ 0x080CBF04
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080CBF50
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080CBF48 @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080CBF4C @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	b _080CBF5A
	.align 2, 0
_080CBF48: .4byte 0xFFFF0000
_080CBF4C: .4byte 0x0000FFFF
_080CBF50:
	ldr r1, _080CBF88 @ =0xFFFF0000
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
_080CBF5A:
	add r5, sp, #8
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080CBF82
	cmp r1, #0
	blt _080CBF82
	ldr r0, _080CBF8C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080CBF82
	ldr r0, _080CBF90 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080CBF94
_080CBF82:
	movs r4, #0
	b _080CBFA2
	.align 2, 0
_080CBF88: .4byte 0xFFFF0000
_080CBF8C: .4byte 0x030046A8
_080CBF90: .4byte 0x030046AC
_080CBF94:
	ldr r0, _080CBFB4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080CBFA2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080CBFB8
	adds r0, #4
	b _080CBFC4
	.align 2, 0
_080CBFB4: .4byte 0x030046A4
_080CBFB8:
	ldr r0, _080CBFD8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080CBFC4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080CBFDC
	cmp r2, #2
	beq _080CBFE0
	b _080CBFE4
	.align 2, 0
_080CBFD8: .4byte 0x030046A4
_080CBFDC:
	ldrb r0, [r5, #4]
	b _080CBFE2
_080CBFE0:
	ldrb r0, [r5]
_080CBFE2:
	subs r1, r1, r0
_080CBFE4:
	add r0, sp, #8
	strh r1, [r0, #2]
	adds r0, r6, #0
	adds r0, #0x1c
	ldrh r1, [r6, #0x18]
	movs r2, #7
	str r2, [sp]
	str r6, [sp, #4]
	add r2, sp, #8
	movs r3, #0
	bl FUN_0823b400
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cc004
FUN_080cc004: @ 0x080CC004
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xa8
	adds r1, r5, #0
	adds r1, #0x24
	adds r0, r4, #0
	bl FUN_0823280c
	adds r0, r5, #0
	adds r0, #0x1c
	adds r1, r4, #0
	movs r2, #0x1e
	movs r3, #0x1e
	bl FUN_0823b43c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080cc02c
FUN_080cc02c: @ 0x080CC02C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x8c
	ldr r1, _080CC090 @ =0x00009247
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r5, r6, #0
	adds r5, #0x60
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r6, #0
	adds r0, #0x1c
	adds r1, r5, #0
	bl FUN_0823b46c
	ldr r1, _080CC094 @ =0x00000133
	adds r0, r4, #0
	bl FUN_0822b20c
	adds r2, r6, #0
	adds r2, #0x7c
	ldr r0, [r6, #0x24]
	ldr r1, [r6, #0x28]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, _080CC098 @ =0x0000922E
	ldr r1, _080CC09C @ =0x00001DF8
	bl GetFile
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r1, r6, r2
	str r0, [r1]
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #7
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_080cbd94
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CC090: .4byte 0x00009247
_080CC094: .4byte 0x00000133
_080CC098: .4byte 0x0000922E
_080CC09C: .4byte 0x00001DF8

	thumb_func_start FUN_080cc0a0
FUN_080cc0a0: @ 0x080CC0A0
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0xb8
	ldr r2, _080CC10C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _080CC110 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _080CC114 @ =0x00002001
	movs r4, #0x10
	str r4, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0
	str r0, [sp]
	str r4, [sp, #4]
	adds r0, r5, #0
	movs r1, #0xa
	movs r2, #0x1e
	movs r3, #0
	bl FUN_082364f8
	adds r0, r5, #0
	movs r1, #0
	adds r2, r6, #0
	bl FUN_0823651c
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CC10C: .4byte 0xFFFF0000
_080CC110: .4byte 0x0000FFFF
_080CC114: .4byte 0x00002001

	thumb_func_start FUN_080cc118
FUN_080cc118: @ 0x080CC118
	push {r4, lr}
	adds r4, r0, #0
	strh r1, [r4, #0x18]
	bl FUN_080cbf04
	adds r0, r4, #0
	bl FUN_080cc004
	adds r0, r4, #0
	bl FUN_080cc02c
	adds r0, r4, #0
	bl FUN_080cc0a0
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x1c
	ldr r2, _080CC154 @ =FUN_080cbb68
	bl FUN_0807f558
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080cbb2c
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080CC154: .4byte FUN_080cbb68

	thumb_func_start FUN_080cc158
FUN_080cc158: @ 0x080CC158
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x9e
	lsls r1, r1, #1
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080CC198
	ldr r1, _080CC190 @ =FUN_080cbeb8
	ldr r2, _080CC194 @ =FUN_080cbee0
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080cc118
	cmp r0, #0
	bge _080CC198
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080CC19A
	.align 2, 0
_080CC190: .4byte FUN_080cbeb8
_080CC194: .4byte FUN_080cbee0
_080CC198:
	adds r0, r4, #0
_080CC19A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080cc1a0
FUN_080cc1a0: @ 0x080CC1A0
	push {lr}
	adds r3, r0, #0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r2, [r0]
	cmp r2, #4
	bls _080CC1CC
	movs r0, #8
	subs r0, r0, r2
	ldr r2, _080CC1C4 @ =0x000002E6
	adds r1, r3, r2
	strb r0, [r1]
	ldr r0, _080CC1C8 @ =0x000002E7
	adds r1, r3, r0
	movs r0, #1
	strb r0, [r1]
	b _080CC1DA
	.align 2, 0
_080CC1C4: .4byte 0x000002E6
_080CC1C8: .4byte 0x000002E7
_080CC1CC:
	ldr r1, _080CC1E0 @ =0x000002E6
	adds r0, r3, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _080CC1E4 @ =0x000002E7
	adds r0, r3, r2
	strb r1, [r0]
_080CC1DA:
	pop {r0}
	bx r0
	.align 2, 0
_080CC1E0: .4byte 0x000002E6
_080CC1E4: .4byte 0x000002E7

	thumb_func_start FUN_080cc1e8
FUN_080cc1e8: @ 0x080CC1E8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r2, #0
	movs r3, #0
	movs r0, #0xb9
	lsls r0, r0, #2
	adds r2, r6, r0
	ldrh r0, [r2]
	cmp r0, r1
	bne _080CC200
	movs r3, #1
_080CC200:
	strh r1, [r2]
	adds r4, r6, #0
	adds r4, #0x88
	adds r5, r6, #0
	adds r5, #0x68
	ldr r2, _080CC238 @ =0x000002E6
	adds r0, r6, r2
	ldrb r2, [r0]
	adds r2, r1, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _080CC23C @ =0x000002E7
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CC240
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	b _080CC24C
	.align 2, 0
_080CC238: .4byte 0x000002E6
_080CC23C: .4byte 0x000002E7
_080CC240:
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_080CC24C:
	str r1, [r0]
	lsls r1, r7, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_082372cc
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080cc268
FUN_080cc268: @ 0x080CC268
	push {r4, lr}
	mov ip, r0
	adds r4, r1, #0
	movs r0, #0xba
	lsls r0, r0, #2
	add r0, ip
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080CC29C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080CC2A0
	asrs r0, r0, #0xc
	b _080CC2A6
	.align 2, 0
_080CC29C: .4byte 0x085B0A08
_080CC2A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CC2A6:
	mov r1, ip
	strh r0, [r1, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _080CC2BC
	asrs r0, r0, #0xc
	b _080CC2C2
_080CC2BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CC2C2:
	mov r1, ip
	strh r0, [r1, #0x38]
	ldr r3, _080CC2E8 @ =0x000001C7
	add r3, ip
	ldrb r3, [r3]
	cmp r3, #1
	bne _080CC30A
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _080CC2EC
	movs r2, #0x38
	ldrsh r1, [r1, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _080CC2FA
	b _080CC2FE
	.align 2, 0
_080CC2E8: .4byte 0x000001C7
_080CC2EC:
	mov r2, ip
	movs r0, #0x38
	ldrsh r1, [r2, r0]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _080CC2FE
_080CC2FA:
	asrs r0, r0, #6
	b _080CC304
_080CC2FE:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_080CC304:
	mov r1, ip
	strh r0, [r1, #0x38]
	b _080CC342
_080CC30A:
	cmp r3, #2
	bne _080CC342
	mov r2, ip
	movs r1, #0x34
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bge _080CC326
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _080CC334
	b _080CC338
_080CC326:
	mov r2, ip
	movs r0, #0x34
	ldrsh r1, [r2, r0]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _080CC338
_080CC334:
	asrs r0, r0, #6
	b _080CC33E
_080CC338:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_080CC33E:
	mov r1, ip
	strh r0, [r1, #0x34]
_080CC342:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cc348
FUN_080cc348: @ 0x080CC348
	push {r4, lr}
	movs r4, #0xdf
	lsls r4, r4, #2
	adds r3, r0, r4
	movs r4, #0
	strb r1, [r3]
	ldr r3, _080CC368 @ =0x0000037D
	adds r1, r0, r3
	strb r2, [r1]
	ldr r1, _080CC36C @ =0x0000037E
	adds r0, r0, r1
	strh r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CC368: .4byte 0x0000037D
_080CC36C: .4byte 0x0000037E

	thumb_func_start FUN_080cc370
FUN_080cc370: @ 0x080CC370
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	str r0, [r4, #0x20]
	adds r0, r4, #0
	bl FUN_0809ebf4
	cmp r0, #0
	beq _080CC38A
	movs r1, #0x10
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
_080CC38A:
	ldr r1, _080CC3B8 @ =0x00000604
	adds r0, r4, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _080CC3BC @ =0x00000606
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r2, _080CC3C0 @ =0x0000035A
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #0xd9
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #0xfd
	ands r0, r1
	strb r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CC3B8: .4byte 0x00000604
_080CC3BC: .4byte 0x00000606
_080CC3C0: .4byte 0x0000035A

	thumb_func_start FUN_080cc3c4
FUN_080cc3c4: @ 0x080CC3C4
	ldr r2, _080CC3D0 @ =0x0000035A
	adds r0, r0, r2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_080CC3D0: .4byte 0x0000035A

	thumb_func_start FUN_080cc3d4
FUN_080cc3d4: @ 0x080CC3D4
	ldr r2, _080CC3E0 @ =0x0000035A
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	bx lr
	.align 2, 0
_080CC3E0: .4byte 0x0000035A

	thumb_func_start FUN_080cc3e4
FUN_080cc3e4: @ 0x080CC3E4
	push {lr}
	adds r2, r0, #0
	ldr r0, _080CC3F8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CC3FC
	movs r0, #1
	rsbs r0, r0, #0
	b _080CC400
	.align 2, 0
_080CC3F8: .4byte 0x03002C68
_080CC3FC:
	movs r3, #0x18
	ldrsh r0, [r0, r3]
_080CC400:
	cmp r2, r0
	bne _080CC40A
	adds r0, r1, #0
	bl PlaySound_082406e0
_080CC40A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080cc410
FUN_080cc410: @ 0x080CC410
	push {lr}
	adds r2, r0, #0
	ldr r0, _080CC424 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CC428
	movs r0, #1
	rsbs r0, r0, #0
	b _080CC42C
	.align 2, 0
_080CC424: .4byte 0x03002C68
_080CC428:
	movs r3, #0x18
	ldrsh r0, [r0, r3]
_080CC42C:
	cmp r2, r0
	bne _080CC436
	adds r0, r1, #0
	bl sound_08240740
_080CC436:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080cc43c
FUN_080cc43c: @ 0x080CC43C
	push {lr}
	adds r2, r0, #0
	ldr r0, _080CC450 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CC454
	movs r1, #1
	rsbs r1, r1, #0
	b _080CC458
	.align 2, 0
_080CC450: .4byte 0x03002C68
_080CC454:
	movs r3, #0x18
	ldrsh r1, [r0, r3]
_080CC458:
	ldr r0, [r2, #0x18]
	cmp r0, r1
	bne _080CC484
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _080CC472
	movs r0, #0xd8
	bl sound_08240740
	b _080CC484
_080CC472:
	ldr r0, _080CC488 @ =0x00000239
	bl sound_08240740
	ldr r0, _080CC48C @ =0x00000202
	bl sound_08240740
	ldr r0, _080CC490 @ =0x00000366
	bl sound_08240740
_080CC484:
	pop {r0}
	bx r0
	.align 2, 0
_080CC488: .4byte 0x00000239
_080CC48C: .4byte 0x00000202
_080CC490: .4byte 0x00000366

	thumb_func_start FUN_080cc494
FUN_080cc494: @ 0x080CC494
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldrh r1, [r2, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080CC4B2
	adds r0, r2, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0xe0
	b _080CC4E4
_080CC4B2:
	movs r0, #0x24
	ldrsh r1, [r2, r0]
	movs r4, #0x24
	ldrsh r0, [r3, r4]
	subs r4, r1, r0
	movs r0, #0x28
	ldrsh r1, [r2, r0]
	movs r2, #0x28
	ldrsh r0, [r3, r2]
	subs r1, r1, r0
	cmp r4, #0
	bne _080CC4DA
	cmp r1, #0
	bne _080CC4DA
	adds r0, r3, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0xe0
	b _080CC4E4
_080CC4DA:
	adds r0, r4, #0
	bl FUN_0823785c
	adds r1, r0, #0
	adds r1, #0x60
_080CC4E4:
	movs r0, #0xff
	ands r1, r0
	asrs r0, r1, #6
	lsls r0, r0, #1
	adds r0, #1
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080cc4f4
FUN_080cc4f4: @ 0x080CC4F4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	adds r5, r2, #0
	adds r1, #0x40
	ldrh r0, [r1]
	adds r6, r5, #0
	adds r6, #0x40
	movs r7, #0
	strh r0, [r6]
	ldrh r0, [r1]
	cmp r0, #0xc8
	bls _080CC512
	movs r0, #0xc8
	strh r0, [r6]
_080CC512:
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r2, [r3, #0x38]
	ands r2, r0
	cmp r2, #0
	beq _080CC53C
	ldr r0, _080CC538 @ =0x000003D2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r3, #0
	adds r1, r5, #0
	bl FUN_080cc494
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	b _080CC60C
	.align 2, 0
_080CC538: .4byte 0x000003D2
_080CC53C:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _080CC554
	ldrh r0, [r5, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r5, #6]
	strh r2, [r6]
	b _080CC60E
_080CC554:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r4, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _080CC5F8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080CC588
	adds r0, r3, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r1, r4, r2
	b _080CC5D8
_080CC588:
	movs r0, #0x24
	ldrsh r1, [r3, r0]
	movs r2, #0x24
	ldrsh r0, [r5, r2]
	subs r2, r1, r0
	movs r0, #0x28
	ldrsh r1, [r3, r0]
	movs r3, #0x28
	ldrsh r0, [r5, r3]
	subs r1, r1, r0
	cmp r2, #0
	bne _080CC5B6
	cmp r1, #0
	bne _080CC5B6
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	b _080CC5DA
_080CC5B6:
	adds r0, r2, #0
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	adds r0, #4
	ands r0, r1
	movs r3, #0xfa
	lsls r3, r3, #2
	adds r1, r4, r3
_080CC5D8:
	strh r0, [r1]
_080CC5DA:
	adds r3, r5, #0
	adds r3, #0x40
	ldrh r2, [r3]
	ldr r1, _080CC5F4 @ =0x000003E6
	adds r0, r4, r1
	movs r1, #0
	strh r2, [r0]
	strh r1, [r3]
	ldrh r1, [r5, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r5, #6]
	b _080CC60E
	.align 2, 0
_080CC5F4: .4byte 0x000003E6
_080CC5F8:
	ldr r2, _080CC614 @ =0x000003D2
	adds r0, r4, r2
	strb r7, [r0]
	adds r0, r3, #0
	adds r1, r5, #0
	bl FUN_080cc494
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r4, r3
_080CC60C:
	strb r0, [r1]
_080CC60E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CC614: .4byte 0x000003D2

	thumb_func_start FUN_080cc618
FUN_080cc618: @ 0x080CC618
	push {lr}
	ldr r0, _080CC628 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CC62C
	movs r1, #0
	b _080CC634
	.align 2, 0
_080CC628: .4byte 0x03002C68
_080CC62C:
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r1, [r0]
_080CC634:
	subs r0, r1, #4
	cmp r0, #1
	bls _080CC63E
	cmp r1, #0
	bne _080CC642
_080CC63E:
	movs r0, #1
	b _080CC644
_080CC642:
	movs r0, #0
_080CC644:
	pop {r1}
	bx r1

	thumb_func_start FUN_080cc648
FUN_080cc648: @ 0x080CC648
	push {r4, r5, lr}
	adds r2, r0, #0
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r3, r2, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _080CC6A0
	ldr r5, _080CC680 @ =0x00000679
	adds r1, r2, r5
	ldrb r0, [r1]
	adds r4, r0, #1
	strb r4, [r1]
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls _080CC684
	movs r0, #0xca
	lsls r0, r0, #3
	adds r2, r2, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	strb r0, [r3]
	b _080CC6A0
	.align 2, 0
_080CC680: .4byte 0x00000679
_080CC684:
	movs r1, #0xca
	lsls r1, r1, #3
	adds r0, r2, r1
	ldr r3, _080CC6A8 @ =0x0000064C
	adds r1, r2, r3
	ldr r1, [r1]
	ldr r5, _080CC6AC @ =0x0000067A
	adds r3, r2, r5
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x1a
	ldrb r3, [r3]
	adds r2, r2, r3
	bl FUN_0822dafc
_080CC6A0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CC6A8: .4byte 0x0000064C
_080CC6AC: .4byte 0x0000067A

	thumb_func_start FUN_080cc6b0
FUN_080cc6b0: @ 0x080CC6B0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	movs r0, #0xca
	lsls r0, r0, #3
	adds r5, r4, r0
	cmp r2, #0
	beq _080CC6CC
	ldr r2, _080CC6C8 @ =0x0000067A
	adds r1, r4, r2
	movs r0, #0x48
	b _080CC6D2
	.align 2, 0
_080CC6C8: .4byte 0x0000067A
_080CC6CC:
	ldr r0, _080CC710 @ =0x0000067A
	adds r1, r4, r0
	movs r0, #4
_080CC6D2:
	strb r0, [r1]
	ldr r1, _080CC714 @ =0x0000064C
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _080CC710 @ =0x0000067A
	adds r0, r4, r2
	ldrb r2, [r0]
	adds r0, r5, #0
	bl FUN_0822dafc
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r5, #0x18]
	str r1, [r5, #0x1c]
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080CC718 @ =0x00000679
	adds r0, r4, r1
	strb r2, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CC710: .4byte 0x0000067A
_080CC714: .4byte 0x0000064C
_080CC718: .4byte 0x00000679

	thumb_func_start FUN_080cc71c
FUN_080cc71c: @ 0x080CC71C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080CC774 @ =0x00001C1C
	bl GetParticleGroup
	adds r1, r0, #0
	ldr r0, _080CC778 @ =0x0000064C
	adds r6, r5, r0
	str r1, [r6]
	adds r0, #4
	adds r4, r5, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r1, [r6]
	adds r0, r4, #0
	movs r2, #4
	bl FUN_0822dafc
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r2, #0
	strb r1, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	movs r1, #0xcf
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r2, [r0]
	ldr r0, _080CC77C @ =0x00000679
	adds r5, r5, r0
	strb r2, [r5]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CC774: .4byte 0x00001C1C
_080CC778: .4byte 0x0000064C
_080CC77C: .4byte 0x00000679

	thumb_func_start FUN_080cc780
FUN_080cc780: @ 0x080CC780
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _080CC870
	ldr r0, [r5, #0x1c]
	cmp r0, #1
	bne _080CC7A2
	movs r1, #0x88
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080CC7B6
_080CC7A2:
	movs r4, #0xd0
	lsls r4, r4, #3
	adds r2, r5, r4
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	strb r0, [r6]
	b _080CC8CC
_080CC7B6:
	ldr r1, _080CC7E4 @ =0x000006A9
	adds r0, r5, r1
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r3, r0, r1
	movs r1, #0xff
	ands r3, r1
	ldr r2, _080CC7E8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080CC7EC
	asrs r1, r0, #0xc
	b _080CC7F2
	.align 2, 0
_080CC7E4: .4byte 0x000006A9
_080CC7E8: .4byte 0x085B0A08
_080CC7EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CC7F2:
	ldrh r0, [r5, #0x2c]
	adds r0, r0, r1
	movs r4, #0xd3
	lsls r4, r4, #3
	adds r1, r5, r4
	strh r0, [r1]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x46
	muls r0, r1, r0
	cmp r0, #0
	blt _080CC812
	asrs r0, r0, #0xc
	b _080CC818
_080CC812:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CC818:
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r4, [r5, #0x2e]
	adds r0, r0, r4
	ldr r4, _080CC848 @ =0x0000069A
	adds r1, r5, r4
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080CC84C
	asrs r2, r0, #0xc
	b _080CC852
	.align 2, 0
_080CC848: .4byte 0x0000069A
_080CC84C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080CC852:
	ldrh r0, [r5, #0x30]
	subs r0, r0, r2
	ldr r4, _080CC868 @ =0x0000069C
	adds r1, r5, r4
	strh r0, [r1]
	ldr r0, _080CC86C @ =0x000006A9
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _080CC8CC
	.align 2, 0
_080CC868: .4byte 0x0000069C
_080CC86C: .4byte 0x000006A9
_080CC870:
	ldr r7, [r5, #0x1c]
	cmp r7, #1
	bne _080CC8CC
	movs r1, #0x88
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080CC8CC
	movs r4, #0xd3
	lsls r4, r4, #3
	adds r2, r5, r4
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	adds r0, #0x38
	movs r4, #0
	strh r0, [r2]
	ldr r0, _080CC8D4 @ =0x0000069A
	adds r1, r5, r0
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r1, #0xd0
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	ldr r2, _080CC8D8 @ =0x0000067C
	adds r1, r5, r2
	ldr r1, [r1]
	movs r2, #0x10
	bl FUN_0822dafc
	ldr r1, _080CC8DC @ =0x000006A9
	adds r0, r5, r1
	strb r4, [r0]
	strb r7, [r6]
_080CC8CC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CC8D4: .4byte 0x0000069A
_080CC8D8: .4byte 0x0000067C
_080CC8DC: .4byte 0x000006A9

	thumb_func_start FUN_080cc8e0
FUN_080cc8e0: @ 0x080CC8E0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080CC938 @ =0x00001C1C
	bl GetParticleGroup
	adds r1, r0, #0
	ldr r0, _080CC93C @ =0x0000067C
	adds r6, r5, r0
	str r1, [r6]
	adds r0, #4
	adds r4, r5, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r1, [r6]
	adds r0, r4, #0
	movs r2, #0x10
	bl FUN_0822dafc
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r2, #0
	strb r1, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	movs r1, #0xd5
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r2, [r0]
	ldr r0, _080CC940 @ =0x000006A9
	adds r5, r5, r0
	strb r2, [r5]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CC938: .4byte 0x00001C1C
_080CC93C: .4byte 0x0000067C
_080CC940: .4byte 0x000006A9

	thumb_func_start FUN_080cc944
FUN_080cc944: @ 0x080CC944
	push {r4, r5, lr}
	mov ip, r0
	adds r0, #0x64
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CC952
	b _080CCA7A
_080CC952:
	mov r4, ip
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	mov r2, ip
	ldr r1, [r2, #0x48]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r2, #0x10]
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
	beq _080CC986
	mov r1, ip
	ldr r0, [r1]
	movs r1, #4
	orrs r0, r1
	b _080CC990
_080CC986:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080CC990:
	mov r2, ip
	str r0, [r2]
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
	beq _080CC9B8
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _080CC9C2
_080CC9B8:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080CC9C2:
	mov r2, ip
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080CC9FC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080CCA42
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080CCA06
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080CCA00
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080CCA1C
	.align 2, 0
_080CC9FC: .4byte 0x0000FFFF
_080CCA00:
	subs r0, #1
	strh r0, [r4, #8]
	b _080CCA1A
_080CCA06:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080CCA1A
	strh r1, [r4, #8]
	movs r2, #1
	b _080CCA1C
_080CCA1A:
	movs r2, #0
_080CCA1C:
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
	bne _080CCA44
	movs r0, #1
	strb r0, [r4, #7]
	b _080CCA44
_080CCA42:
	movs r2, #0
_080CCA44:
	cmp r2, #0
	beq _080CCA5E
	mov r1, ip
	adds r1, #0x64
	movs r0, #0
	strb r0, [r1]
	mov r1, ip
	ldr r0, [r1]
	movs r1, #1
	orrs r0, r1
	mov r2, ip
	str r0, [r2]
	b _080CCA7A
_080CCA5E:
	mov r0, ip
	adds r0, #0x5c
	ldrh r0, [r0]
	mov r1, ip
	ldrh r1, [r1, #0x1c]
	adds r0, r0, r1
	mov r2, ip
	strh r0, [r2, #0x1c]
	mov r0, ip
	adds r0, #0x60
	ldrh r0, [r0]
	ldrh r1, [r2, #0x20]
	adds r0, r0, r1
	strh r0, [r2, #0x20]
_080CCA7A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cca80
FUN_080cca80: @ 0x080CCA80
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x64
	ldrb r0, [r1]
	cmp r0, #0
	beq _080CCA94
	movs r0, #0
	strb r0, [r1]
	b _080CCA9C
_080CCA94:
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_080CCA9C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080ccaa0
FUN_080ccaa0: @ 0x080CCAA0
	push {lr}
	adds r3, r0, #0
	movs r0, #3
	ands r0, r3
	cmp r0, #1
	beq _080CCABC
	cmp r0, #1
	bgt _080CCAB6
	cmp r0, #0
	beq _080CCABC
	b _080CCABA
_080CCAB6:
	cmp r0, #2
	beq _080CCABC
_080CCABA:
	movs r0, #1
_080CCABC:
	str r0, [r1]
	cmp r3, #2
	bhi _080CCAC6
	movs r0, #0
	b _080CCADA
_080CCAC6:
	subs r0, r3, #3
	cmp r0, #1
	bhi _080CCAD0
	movs r0, #2
	b _080CCADA
_080CCAD0:
	cmp r3, #5
	bne _080CCAD8
	movs r0, #3
	b _080CCADA
_080CCAD8:
	movs r0, #1
_080CCADA:
	str r0, [r2]
	pop {r0}
	bx r0

	thumb_func_start FUN_080ccae0
FUN_080ccae0: @ 0x080CCAE0
	adds r1, r0, #0
	adds r1, #0xc2
	ldrh r2, [r1]
	ldr r3, _080CCB14 @ =0x000006DE
	adds r1, r0, r3
	strh r2, [r1]
	ldr r1, _080CCB18 @ =0x000006E4
	adds r2, r0, r1
	adds r1, r0, #0
	adds r1, #0xd0
	ldr r1, [r1]
	str r1, [r2]
	ldr r1, _080CCB1C @ =0x000006AC
	adds r3, r0, r1
	ldr r1, [r3]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r3]
	movs r3, #0xe2
	lsls r3, r3, #3
	adds r0, r0, r3
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
_080CCB14: .4byte 0x000006DE
_080CCB18: .4byte 0x000006E4
_080CCB1C: .4byte 0x000006AC

	thumb_func_start FUN_080ccb20
FUN_080ccb20: @ 0x080CCB20
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r0, _080CCB6C @ =0x000006AC
	adds r3, r4, r0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	ldrh r0, [r3, #0x1e]
	adds r0, #0xbe
	strh r0, [r3, #0x1e]
	ldr r2, _080CCB70 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080CCB74
	asrs r1, r0, #0xc
	b _080CCB7A
	.align 2, 0
_080CCB6C: .4byte 0x000006AC
_080CCB70: .4byte 0x085B0A08
_080CCB74:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCB7A:
	ldrh r0, [r3, #0x1c]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080CCB96
	asrs r1, r0, #0xc
	b _080CCB9C
_080CCB96:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCB9C:
	ldrh r0, [r3, #0x20]
	adds r0, r0, r1
	strh r0, [r3, #0x20]
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CCBC0
	asrs r1, r0, #0xc
	b _080CCBC6
_080CCBC0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCBC6:
	movs r7, #0xe1
	lsls r7, r7, #3
	adds r0, r4, r7
	strh r1, [r0]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CCBE4
	asrs r2, r0, #0xc
	b _080CCBEA
_080CCBE4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080CCBEA:
	ldr r3, _080CCC28 @ =0x0000070C
	adds r0, r4, r3
	strh r2, [r0]
	add r2, sp, #8
	adds r0, r6, #0
	add r1, sp, #4
	bl FUN_080ccaa0
	ldr r7, _080CCC2C @ =0x000006F4
	adds r0, r4, r7
	ldr r2, _080CCC30 @ =0x00000704
	adds r1, r4, r2
	ldr r1, [r1]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r2, [sp, #8]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #0
	bl FUN_08236fac
	adds r0, r4, #0
	bl FUN_080ccae0
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CCC28: .4byte 0x0000070C
_080CCC2C: .4byte 0x000006F4
_080CCC30: .4byte 0x00000704

	thumb_func_start FUN_080ccc34
FUN_080ccc34: @ 0x080CCC34
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	mov ip, r1
	ldr r0, _080CCC4C @ =0x000006AC
	adds r4, r5, r0
	cmp r3, #0
	bne _080CCC50
	movs r3, #0xa0
	movs r7, #0xe1
	lsls r7, r7, #1
	b _080CCC60
	.align 2, 0
_080CCC4C: .4byte 0x000006AC
_080CCC50:
	cmp r3, #1
	bne _080CCC5C
	movs r3, #0x8c
	movs r7, #0xa9
	lsls r7, r7, #1
	b _080CCC60
_080CCC5C:
	movs r3, #0x78
	movs r7, #0xe0
_080CCC60:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r6, r0, #5
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldrh r0, [r4, #0x1e]
	adds r0, r0, r3
	strh r0, [r4, #0x1e]
	ldr r2, _080CCC9C @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r7, r0
	cmp r0, #0
	blt _080CCCA0
	asrs r1, r0, #0xc
	b _080CCCA6
	.align 2, 0
_080CCC9C: .4byte 0x085B0A08
_080CCCA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCCA6:
	ldrh r0, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _080CCCBE
	asrs r1, r0, #0xc
	b _080CCCC4
_080CCCBE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCCC4:
	ldrh r0, [r4, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CCCE8
	asrs r1, r0, #0xc
	b _080CCCEE
_080CCCE8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCCEE:
	movs r3, #0xe1
	lsls r3, r3, #3
	adds r0, r5, r3
	strh r1, [r0]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CCD0C
	asrs r2, r0, #0xc
	b _080CCD12
_080CCD0C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080CCD12:
	ldr r3, _080CCD50 @ =0x0000070C
	adds r0, r5, r3
	strh r2, [r0]
	add r2, sp, #8
	mov r0, ip
	add r1, sp, #4
	bl FUN_080ccaa0
	ldr r1, _080CCD54 @ =0x000006F4
	adds r0, r5, r1
	ldr r2, _080CCD58 @ =0x00000704
	adds r1, r5, r2
	ldr r1, [r1]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r2, [sp, #8]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #1
	bl FUN_08236fac
	adds r0, r5, #0
	bl FUN_080ccae0
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CCD50: .4byte 0x0000070C
_080CCD54: .4byte 0x000006F4
_080CCD58: .4byte 0x00000704

	thumb_func_start FUN_080ccd5c
FUN_080ccd5c: @ 0x080CCD5C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _080CCD9C @ =0x000006AC
	adds r3, r4, r0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	ldr r2, _080CCDA0 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r0, #0xb4
	muls r0, r1, r0
	cmp r0, #0
	blt _080CCDA4
	asrs r1, r0, #0xc
	b _080CCDAA
	.align 2, 0
_080CCD9C: .4byte 0x000006AC
_080CCDA0: .4byte 0x085B0A08
_080CCDA4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCDAA:
	ldrh r0, [r3, #0x1c]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xb4
	muls r0, r1, r0
	cmp r0, #0
	blt _080CCDC4
	asrs r1, r0, #0xc
	b _080CCDCA
_080CCDC4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCDCA:
	ldrh r0, [r3, #0x20]
	adds r0, r0, r1
	movs r2, #0
	strh r0, [r3, #0x20]
	movs r3, #0xe1
	lsls r3, r3, #3
	adds r0, r4, r3
	strh r2, [r0]
	ldr r6, _080CCE04 @ =0x0000070C
	adds r0, r4, r6
	strh r2, [r0]
	ldr r1, _080CCE08 @ =0x000006F4
	adds r0, r4, r1
	subs r3, #4
	adds r1, r4, r3
	ldr r1, [r1]
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	adds r0, r4, #0
	bl FUN_080ccae0
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CCE04: .4byte 0x0000070C
_080CCE08: .4byte 0x000006F4

	thumb_func_start FUN_080cce0c
FUN_080cce0c: @ 0x080CCE0C
	push {r4, lr}
	ldr r1, _080CCE50 @ =0x000006AC
	adds r4, r0, r1
	ldr r1, [r4]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r4]
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r2]
	ldr r2, [r2, #4]
	str r1, [r3]
	str r2, [r3, #4]
	ldr r3, _080CCE54 @ =0x000006CA
	adds r2, r0, r3
	ldrh r1, [r2]
	adds r1, #0xe6
	strh r1, [r2]
	ldr r2, _080CCE58 @ =0x00000A8A
	adds r1, r0, r2
	ldrh r2, [r1]
	subs r3, #0x18
	adds r1, r0, r3
	strb r2, [r1]
	movs r1, #0xe2
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CCE50: .4byte 0x000006AC
_080CCE54: .4byte 0x000006CA
_080CCE58: .4byte 0x00000A8A

	thumb_func_start FUN_080cce5c
FUN_080cce5c: @ 0x080CCE5C
	push {lr}
	ldr r1, _080CCE6C @ =0x000006AC
	adds r0, r0, r1
	bl FUN_0822a4e0
	pop {r0}
	bx r0
	.align 2, 0
_080CCE6C: .4byte 0x000006AC

	thumb_func_start FUN_080cce70
FUN_080cce70: @ 0x080CCE70
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _080CCEC4 @ =0x000006AC
	adds r4, r6, r0
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r5, r6, r1
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #5
	bne _080CCED4
	ldr r1, _080CCEC8 @ =0x00002110
	adds r0, r5, #0
	bl FUN_0822b16c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0x43
	bl FUN_0822a470
	movs r0, #4
	strh r0, [r4, #0x10]
	adds r0, r5, #0
	movs r1, #0x32
	bl FUN_0822b20c
	movs r0, #1
	strb r0, [r4, #7]
	movs r0, #0x7f
	strb r0, [r4, #9]
	strb r0, [r4, #8]
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldr r0, _080CCECC @ =0x00000714
	adds r1, r6, r0
	ldr r0, _080CCED0 @ =FUN_080cca80
	b _080CCF02
	.align 2, 0
_080CCEC4: .4byte 0x000006AC
_080CCEC8: .4byte 0x00002110
_080CCECC: .4byte 0x00000714
_080CCED0: .4byte FUN_080cca80
_080CCED4:
	ldr r1, _080CCF14 @ =0x00008F5D
	adds r0, r5, #0
	bl FUN_0822b16c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl FUN_0822a470
	adds r0, r5, #0
	movs r1, #0x1d
	bl FUN_0822b20c
	ldr r0, _080CCF18 @ =0x0000922E
	ldr r1, _080CCF1C @ =0x00000837
	bl GetFile
	ldr r2, _080CCF20 @ =0x00000704
	adds r1, r6, r2
	str r0, [r1]
	ldr r0, _080CCF24 @ =0x00000714
	adds r1, r6, r0
	ldr r0, _080CCF28 @ =FUN_080cc944
_080CCF02:
	str r0, [r1]
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CCF14: .4byte 0x00008F5D
_080CCF18: .4byte 0x0000922E
_080CCF1C: .4byte 0x00000837
_080CCF20: .4byte 0x00000704
_080CCF24: .4byte 0x00000714
_080CCF28: .4byte FUN_080cc944

	thumb_func_start FUN_080ccf2c
FUN_080ccf2c: @ 0x080CCF2C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r1, _080CCF84 @ =0x0000071C
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CCFD4
	movs r2, #0
	mov r8, r2
	movs r7, #0
_080CCF44:
	movs r0, #0x34
	adds r1, r7, #0
	muls r1, r0, r1
	adds r0, r5, r1
	movs r2, #0xea
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CCFC2
	subs r2, #0x30
	adds r0, r1, r2
	adds r3, r5, r0
	adds r4, r3, #0
	adds r1, r3, #0
	adds r1, #0x31
	ldrb r0, [r1]
	adds r2, r0, #1
	movs r6, #0
	strb r2, [r1]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bls _080CCF88
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	adds r0, r3, #0
	adds r0, #0x30
	strb r6, [r0]
	b _080CCFC2
	.align 2, 0
_080CCF84: .4byte 0x0000071C
_080CCF88:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bne _080CCFA6
	movs r1, #0xe3
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r3, #0
	adds r0, #0x32
	ldrb r2, [r0]
	adds r2, #1
	adds r0, r3, #0
	bl FUN_0822dafc
_080CCFA6:
	ldrh r0, [r4, #0x28]
	ldrh r2, [r4, #0x18]
	adds r0, r0, r2
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x2a]
	ldrh r1, [r4, #0x1a]
	adds r0, r0, r1
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x2c]
	ldrh r2, [r4, #0x1c]
	adds r0, r0, r2
	strh r0, [r4, #0x1c]
	movs r0, #1
	add r8, r0
_080CCFC2:
	adds r7, #1
	cmp r7, #5
	ble _080CCF44
	mov r1, r8
	cmp r1, #0
	bne _080CCFD4
	ldr r2, _080CCFE0 @ =0x0000071C
	adds r0, r5, r2
	strb r1, [r0]
_080CCFD4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CCFE0: .4byte 0x0000071C

	thumb_func_start FUN_080ccfe4
FUN_080ccfe4: @ 0x080CCFE4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	ldr r0, _080CD070 @ =0x0000071D
	adds r7, r5, r0
	ldrb r1, [r7]
	movs r0, #0x34
	adds r4, r1, #0
	muls r4, r0, r4
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r4, r4, r1
	adds r4, r5, r4
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	lsls r3, r3, #1
	adds r3, #2
	adds r2, r4, #0
	adds r2, #0x32
	movs r0, #0
	mov sb, r0
	strb r3, [r2]
	movs r1, #0xe3
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	ldrb r2, [r2]
	adds r0, r4, #0
	bl FUN_0822dafc
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r4, #0x18]
	str r1, [r4, #0x1c]
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	adds r0, r4, #0
	adds r0, #0x31
	mov r1, sb
	strb r1, [r0]
	adds r4, #0x30
	movs r0, #1
	strb r0, [r4]
	ldr r2, _080CD074 @ =0x0000071C
	adds r5, r5, r2
	strb r0, [r5]
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls _080CD064
	strb r1, [r7]
_080CD064:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CD070: .4byte 0x0000071D
_080CD074: .4byte 0x0000071C

	thumb_func_start FUN_080cd078
FUN_080cd078: @ 0x080CD078
	push {r4, r5, lr}
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r4, r0, r1
	movs r5, #5
_080CD082:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x34
	subs r5, #1
	cmp r5, #0
	bge _080CD082
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080cd098
FUN_080cd098: @ 0x080CD098
	push {r4, r5, r6, r7, lr}
	movs r1, #0xe3
	lsls r1, r1, #3
	adds r5, r0, r1
	ldr r0, _080CD0EC @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r5]
	movs r6, #0
	movs r7, #4
	rsbs r7, r7, #0
_080CD0AE:
	movs r0, #0x34
	adds r4, r6, #0
	muls r4, r0, r4
	adds r4, #8
	adds r4, r5, r4
	ldr r1, [r5]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r7, #0
	bl FUN_0822dad4
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #2
	strb r0, [r4, #0xf]
	adds r6, #1
	cmp r6, #5
	ble _080CD0AE
	movs r0, #0
	strb r0, [r5, #4]
	strb r0, [r5, #5]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CD0EC: .4byte 0x00001C1E

	thumb_func_start FUN_080cd0f0
FUN_080cd0f0: @ 0x080CD0F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	ldr r1, _080CD158 @ =0x0000085C
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CD108
	b _080CD21A
_080CD108:
	movs r2, #0
	mov sb, r2
	movs r7, #0
	ldr r0, _080CD15C @ =0x085B0A08
	mov sl, r0
	movs r1, #0xff
	mov r8, r1
_080CD116:
	movs r0, #0x34
	muls r0, r7, r0
	movs r2, #0x86
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r4, r6, r0
	adds r2, r4, #0
	adds r2, #0x28
	ldrb r0, [r2]
	cmp r0, #0
	beq _080CD208
	adds r5, r4, #0
	movs r1, #0x2c
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bge _080CD138
	rsbs r0, r0, #0
_080CD138:
	cmp r0, #0xf
	bgt _080CD160
	movs r1, #0x30
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bge _080CD146
	rsbs r0, r0, #0
_080CD146:
	cmp r0, #0xf
	bgt _080CD160
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	movs r0, #0
	strb r0, [r2]
	b _080CD208
	.align 2, 0
_080CD158: .4byte 0x0000085C
_080CD15C: .4byte 0x085B0A08
_080CD160:
	movs r2, #0x2c
	ldrsh r0, [r4, r2]
	movs r2, #0x30
	ldrsh r1, [r4, r2]
	bl FUN_0823785c
	adds r3, r0, #0
	adds r1, r4, #0
	adds r1, #0x2a
	ldrb r0, [r1]
	mov ip, r0
	adds r0, r3, #0
	adds r0, #0x40
	mov r2, r8
	ands r0, r2
	lsls r0, r0, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _080CD194
	asrs r2, r0, #0xc
	b _080CD19A
_080CD194:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080CD19A:
	ldrh r0, [r4, #0x2c]
	subs r0, r0, r2
	strh r0, [r4, #0x2c]
	ldrb r1, [r1]
	mov r0, r8
	ands r3, r0
	lsls r0, r3, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080CD1B8
	asrs r1, r0, #0xc
	b _080CD1BE
_080CD1B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CD1BE:
	ldrh r0, [r4, #0x30]
	subs r0, r0, r1
	strh r0, [r4, #0x30]
	movs r0, #0x93
	lsls r0, r0, #4
	adds r1, r6, r0
	ldrh r0, [r4, #0x2c]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x18]
	ldr r2, _080CD228 @ =0x00000934
	adds r1, r6, r2
	ldrh r0, [r4, #0x30]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	mov r1, r8
	ands r0, r1
	cmp r0, #4
	bne _080CD204
	subs r2, #0xdc
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r4, #0
	adds r0, #0x2b
	ldrb r2, [r0]
	adds r2, #1
	adds r0, r5, #0
	bl FUN_0822dafc
_080CD204:
	movs r0, #1
	add sb, r0
_080CD208:
	adds r7, #1
	cmp r7, #3
	ble _080CD116
	mov r1, sb
	cmp r1, #0
	bne _080CD21A
	ldr r2, _080CD22C @ =0x0000085C
	adds r0, r6, r2
	strb r1, [r0]
_080CD21A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CD228: .4byte 0x00000934
_080CD22C: .4byte 0x0000085C

	thumb_func_start FUN_080cd230
FUN_080cd230: @ 0x080CD230
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	mov sb, r1
	ldr r1, [r7, #0x18]
	ldr r0, _080CD24C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CD250
	movs r2, #0
	b _080CD258
	.align 2, 0
_080CD24C: .4byte 0x03002C68
_080CD250:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r2, r0, #0
_080CD258:
	ldr r0, _080CD2E8 @ =0x0000085E
	adds r1, r7, r0
	ldrb r0, [r1]
	adds r0, #2
	adds r0, r2, r0
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x27
	bhi _080CD26E
	b _080CD39C
_080CD26E:
	ldr r1, _080CD2EC @ =0x0000085D
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #0x34
	muls r0, r1, r0
	movs r2, #0x86
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r6, r7, r0
	mov r8, r6
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r1, r6, #0
	adds r1, #0x2b
	movs r0, #2
	strb r0, [r1]
	ldr r3, _080CD2F0 @ =0x00000858
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r6, #0
	movs r2, #2
	bl FUN_0822dafc
	ldr r0, _080CD2F4 @ =0x0203B400
	mov ip, r0
	ldr r3, _080CD2F8 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _080CD2FC @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	add r1, ip
	movs r5, #0xff
	ldrb r4, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r2, r0, #0
	adds r2, #0x80
	ldr r1, _080CD300 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080CD304
	asrs r0, r0, #0xc
	b _080CD30A
	.align 2, 0
_080CD2E8: .4byte 0x0000085E
_080CD2EC: .4byte 0x0000085D
_080CD2F0: .4byte 0x00000858
_080CD2F4: .4byte 0x0203B400
_080CD2F8: .4byte 0x030046B8
_080CD2FC: .4byte 0x000003FF
_080CD300: .4byte 0x085B0A08
_080CD304:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CD30A:
	strh r0, [r6, #0x2c]
	ldr r0, _080CD320 @ =0x085B0A08
	lsls r1, r4, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _080CD324
	asrs r0, r0, #0xc
	b _080CD32A
	.align 2, 0
_080CD320: .4byte 0x085B0A08
_080CD324:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CD32A:
	movs r3, #0
	strh r0, [r6, #0x30]
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	mov r2, r8
	str r0, [r2, #0x18]
	str r1, [r2, #0x1c]
	ldrh r0, [r6, #0x2c]
	ldrh r1, [r2, #0x18]
	adds r0, r0, r1
	strh r0, [r2, #0x18]
	ldrh r0, [r6, #0x30]
	ldrh r2, [r2, #0x1c]
	adds r0, r0, r2
	mov r1, r8
	strh r0, [r1, #0x1c]
	ldr r2, _080CD3A8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080CD3AC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _080CD3B0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #0xe
	adds r1, r6, #0
	adds r1, #0x2a
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x29
	strb r3, [r0]
	subs r0, #1
	movs r2, #1
	strb r2, [r0]
	ldr r0, _080CD3B4 @ =0x0000085D
	adds r1, r7, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080CD38C
	strb r3, [r1]
_080CD38C:
	ldr r1, _080CD3B8 @ =0x0000085E
	adds r0, r7, r1
	ldrb r1, [r0]
	subs r1, #0x28
	strb r1, [r0]
	ldr r3, _080CD3BC @ =0x0000085C
	adds r0, r7, r3
	strb r2, [r0]
_080CD39C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CD3A8: .4byte 0x030046B8
_080CD3AC: .4byte 0x000003FF
_080CD3B0: .4byte 0x0203B400
_080CD3B4: .4byte 0x0000085D
_080CD3B8: .4byte 0x0000085E
_080CD3BC: .4byte 0x0000085C

	thumb_func_start FUN_080cd3c0
FUN_080cd3c0: @ 0x080CD3C0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	mov sb, r1
	ldr r1, _080CD460 @ =0x0000085E
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r1, #0xff
	ands r0, r1
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _080CD3E4
	b _080CD506
_080CD3E4:
	ldr r0, _080CD464 @ =0x0000085D
	add r0, r8
	ldrb r1, [r0]
	movs r0, #0x34
	muls r0, r1, r0
	movs r1, #0x86
	lsls r1, r1, #4
	adds r0, r0, r1
	mov r2, r8
	adds r6, r2, r0
	adds r7, r6, #0
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r1, r6, #0
	adds r1, #0x2b
	movs r0, #4
	strb r0, [r1]
	ldr r0, _080CD468 @ =0x00000858
	add r0, r8
	ldr r1, [r0]
	adds r0, r6, #0
	movs r2, #4
	bl FUN_0822dafc
	ldr r3, _080CD46C @ =0x0203B400
	mov ip, r3
	ldr r3, _080CD470 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _080CD474 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	add r1, ip
	movs r5, #0xff
	ldrb r4, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r1, #0x81
	adds r2, r0, r1
	ldr r1, _080CD478 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080CD47C
	asrs r0, r0, #0xc
	b _080CD482
	.align 2, 0
_080CD460: .4byte 0x0000085E
_080CD464: .4byte 0x0000085D
_080CD468: .4byte 0x00000858
_080CD46C: .4byte 0x0203B400
_080CD470: .4byte 0x030046B8
_080CD474: .4byte 0x000003FF
_080CD478: .4byte 0x085B0A08
_080CD47C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CD482:
	strh r0, [r6, #0x2c]
	ldr r0, _080CD498 @ =0x085B0A08
	lsls r1, r4, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _080CD49C
	asrs r0, r0, #0xc
	b _080CD4A2
	.align 2, 0
_080CD498: .4byte 0x085B0A08
_080CD49C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CD4A2:
	movs r3, #0
	strh r0, [r6, #0x30]
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x18]
	str r1, [r7, #0x1c]
	ldrh r0, [r6, #0x2c]
	ldrh r1, [r7, #0x18]
	adds r0, r0, r1
	strh r0, [r7, #0x18]
	ldrh r0, [r6, #0x30]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	ldr r2, _080CD514 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080CD518 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080CD51C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #0x1c
	adds r1, r6, #0
	adds r1, #0x2a
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x29
	strb r3, [r0]
	subs r0, #1
	movs r1, #1
	strb r1, [r0]
	ldr r0, _080CD520 @ =0x0000085C
	add r0, r8
	strb r1, [r0]
	ldr r1, _080CD524 @ =0x0000085D
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080CD506
	strb r3, [r1]
_080CD506:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CD514: .4byte 0x030046B8
_080CD518: .4byte 0x000003FF
_080CD51C: .4byte 0x0203B400
_080CD520: .4byte 0x0000085C
_080CD524: .4byte 0x0000085D

	thumb_func_start FUN_080cd528
FUN_080cd528: @ 0x080CD528
	push {r4, r5, lr}
	movs r1, #0x86
	lsls r1, r1, #4
	adds r4, r0, r1
	movs r5, #3
_080CD532:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x34
	subs r5, #1
	cmp r5, #0
	bge _080CD532
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080cd548
FUN_080cd548: @ 0x080CD548
	push {r4, r5, r6, r7, lr}
	ldr r1, _080CD598 @ =0x00000858
	adds r5, r0, r1
	ldr r0, _080CD59C @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r5]
	movs r6, #0
	movs r7, #4
	rsbs r7, r7, #0
_080CD55C:
	movs r0, #0x34
	adds r4, r6, #0
	muls r4, r0, r4
	adds r4, #8
	adds r4, r5, r4
	ldr r1, [r5]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r7, #0
	bl FUN_0822dad4
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #2
	strb r0, [r4, #0xf]
	adds r6, #1
	cmp r6, #3
	ble _080CD55C
	movs r0, #0
	strb r0, [r5, #5]
	strb r0, [r5, #6]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CD598: .4byte 0x00000858
_080CD59C: .4byte 0x00001C1E

	thumb_func_start FUN_080cd5a0
FUN_080cd5a0: @ 0x080CD5A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	ldr r2, _080CD5F8 @ =0x03003584
	ldr r1, _080CD5FC @ =0x0000094C
	adds r0, r3, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r1, r1, #1
	ldr r4, _080CD600 @ =0x00000938
	adds r0, r3, r4
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r2]
	adds r6, r1, r0
	ldr r0, _080CD604 @ =0x0000094E
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _080CD624
	ldr r1, _080CD608 @ =0x00000359
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CD60C
	movs r5, #0
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r1, r3, r2
_080CD5DE:
	subs r0, r5, #5
	cmp r0, #1
	bls _080CD5EC
	cmp r5, #0xd
	beq _080CD5EC
	ldrh r0, [r6]
	strh r0, [r1]
_080CD5EC:
	adds r6, #2
	adds r1, #2
	adds r5, #1
	cmp r5, #0xf
	ble _080CD5DE
	b _080CD6E2
	.align 2, 0
_080CD5F8: .4byte 0x03003584
_080CD5FC: .4byte 0x0000094C
_080CD600: .4byte 0x00000938
_080CD604: .4byte 0x0000094E
_080CD608: .4byte 0x00000359
_080CD60C:
	movs r4, #0xa9
	lsls r4, r4, #2
	adds r1, r3, r4
	movs r5, #0xf
_080CD614:
	ldrh r0, [r6]
	strh r0, [r1]
	adds r6, #2
	adds r1, #2
	subs r5, #1
	cmp r5, #0
	bge _080CD614
	b _080CD6E2
_080CD624:
	ldr r2, _080CD68C @ =0x00000359
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CD690
	movs r5, #0
	mov r8, r1
	movs r4, #0xa9
	lsls r4, r4, #2
	adds r7, r3, r4
_080CD638:
	subs r0, r5, #5
	cmp r0, #1
	bls _080CD680
	cmp r5, #0xd
	beq _080CD680
	ldrh r1, [r6]
	movs r0, #0x1f
	mov ip, r0
	movs r0, #0x1f
	ands r0, r1
	mov r3, r8
	ldrb r2, [r3]
	adds r4, r0, r2
	cmp r4, #0x1f
	ble _080CD658
	movs r4, #0x1f
_080CD658:
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x15
	mov r1, ip
	ands r0, r1
	adds r1, r0, r2
	cmp r1, #0x1f
	ble _080CD668
	movs r1, #0x1f
_080CD668:
	lsrs r0, r3, #0x1a
	mov r3, ip
	ands r0, r3
	adds r0, r0, r2
	cmp r0, #0x1f
	ble _080CD676
	movs r0, #0x1f
_080CD676:
	lsls r0, r0, #0xa
	lsls r1, r1, #5
	orrs r0, r1
	orrs r0, r4
	strh r0, [r7]
_080CD680:
	adds r6, #2
	adds r7, #2
	adds r5, #1
	cmp r5, #0xf
	ble _080CD638
	b _080CD6E2
	.align 2, 0
_080CD68C: .4byte 0x00000359
_080CD690:
	movs r4, #0x1f
	mov ip, r4
	mov r8, r1
	movs r0, #0xa9
	lsls r0, r0, #2
	adds r7, r3, r0
	movs r5, #0xf
_080CD69E:
	ldrh r1, [r6]
	movs r0, #0x1f
	ands r0, r1
	mov r3, r8
	ldrb r2, [r3]
	adds r4, r0, r2
	cmp r4, #0x1f
	ble _080CD6B0
	movs r4, #0x1f
_080CD6B0:
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x15
	mov r1, ip
	ands r0, r1
	adds r1, r0, r2
	cmp r1, #0x1f
	ble _080CD6C0
	movs r1, #0x1f
_080CD6C0:
	lsrs r0, r3, #0x1a
	mov r3, ip
	ands r0, r3
	adds r0, r0, r2
	cmp r0, #0x1f
	ble _080CD6CE
	movs r0, #0x1f
_080CD6CE:
	lsls r0, r0, #0xa
	lsls r1, r1, #5
	orrs r0, r1
	orrs r0, r4
	strh r0, [r7]
	adds r6, #2
	adds r7, #2
	subs r5, #1
	cmp r5, #0
	bge _080CD69E
_080CD6E2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cd6ec
FUN_080cd6ec: @ 0x080CD6EC
	push {r4, lr}
	adds r2, r0, #0
	movs r3, #0
	movs r1, #2
	ldr r0, _080CD708 @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _080CD70C @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080CD710
	movs r0, #1
	b _080CD712
	.align 2, 0
_080CD708: .4byte 0x030046A0
_080CD70C: .4byte 0x00000934
_080CD710:
	movs r0, #0
_080CD712:
	cmp r0, #0
	bne _080CD724
	ldr r0, [r2, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080CD730
	movs r3, #4
	b _080CD730
_080CD724:
	ldr r0, [r2, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080CD730
	movs r3, #8
_080CD730:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080cd738
FUN_080cd738: @ 0x080CD738
	push {r4, lr}
	ldr r1, _080CD774 @ =0x03003584
	ldr r2, [r1]
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r2, r2, r1
	movs r3, #0x95
	lsls r3, r3, #4
	adds r1, r0, r3
	ldrb r3, [r1]
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #1
	adds r2, r2, r1
	ldrh r3, [r2]
	ldr r4, _080CD778 @ =0x000002AE
	adds r1, r0, r4
	strh r3, [r1]
	adds r2, #2
	ldrh r3, [r2]
	adds r4, #2
	adds r1, r0, r4
	strh r3, [r1]
	ldrh r1, [r2, #2]
	ldr r2, _080CD77C @ =0x000002BE
	adds r0, r0, r2
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CD774: .4byte 0x03003584
_080CD778: .4byte 0x000002AE
_080CD77C: .4byte 0x000002BE

	thumb_func_start FUN_080cd780
FUN_080cd780: @ 0x080CD780
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sl, r0
	mov ip, r2
	mov sb, r3
	cmp r2, #0
	bne _080CD7C2
	ldr r0, _080CD7B0 @ =0x00000359
	add r0, sl
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CD7B4
	mov r1, sl
	adds r1, #0xd0
	movs r0, #0xa9
	lsls r0, r0, #2
	add r0, sl
	str r0, [r1]
	b _080CD942
	.align 2, 0
_080CD7B0: .4byte 0x00000359
_080CD7B4:
	movs r0, #0x8a
	lsls r0, r0, #1
	add r0, sl
	ldr r1, [r0]
	movs r0, #0xa9
	lsls r0, r0, #2
	b _080CD93E
_080CD7C2:
	mov r8, r1
	ldr r0, _080CD7F8 @ =0x00000359
	add r0, sl
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CD898
	movs r0, #0
	str r0, [sp]
	mov r1, sl
	adds r1, #0xd0
	str r1, [sp, #0xc]
	movs r6, #0xa9
	lsls r6, r6, #2
	add r6, sl
	ldr r2, _080CD7FC @ =0x0000094E
	add r2, sl
	str r2, [sp, #4]
_080CD7E4:
	ldr r0, [sp]
	subs r0, #5
	cmp r0, #1
	bls _080CD7F2
	ldr r3, [sp]
	cmp r3, #0xd
	bne _080CD800
_080CD7F2:
	ldrh r0, [r6]
	b _080CD87A
	.align 2, 0
_080CD7F8: .4byte 0x00000359
_080CD7FC: .4byte 0x0000094E
_080CD800:
	mov r4, r8
	ldrh r2, [r4]
	movs r7, #0x1f
	movs r0, #0x1f
	ands r0, r2
	ldr r3, [sp, #4]
	ldrb r1, [r3]
	adds r4, r0, r1
	cmp r4, #0x1f
	ble _080CD816
	movs r4, #0x1f
_080CD816:
	lsls r3, r2, #0x10
	lsrs r0, r3, #0x15
	ands r0, r7
	adds r2, r0, r1
	cmp r2, #0x1f
	ble _080CD824
	movs r2, #0x1f
_080CD824:
	lsrs r0, r3, #0x1a
	ands r0, r7
	adds r5, r0, r1
	cmp r5, #0x1f
	ble _080CD830
	movs r5, #0x1f
_080CD830:
	ldrh r1, [r6]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x15
	ands r3, r7
	lsrs r1, r1, #0x1a
	ands r1, r7
	mov r7, ip
	muls r7, r4, r7
	adds r4, r7, #0
	mov r7, sb
	muls r7, r0, r7
	adds r0, r7, #0
	adds r4, r4, r0
	ldr r0, [sp, #0x34]
	asrs r4, r0
	mov r7, ip
	muls r7, r2, r7
	adds r2, r7, #0
	mov r0, sb
	muls r0, r3, r0
	adds r2, r2, r0
	ldr r0, [sp, #0x34]
	asrs r2, r0
	mov r0, ip
	muls r0, r5, r0
	mov r3, sb
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	ldr r7, [sp, #0x34]
	asrs r0, r7
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r4
_080CD87A:
	strh r0, [r6, #0x20]
	movs r0, #2
	add r8, r0
	adds r6, #2
	ldr r1, [sp]
	adds r1, #1
	str r1, [sp]
	cmp r1, #0xf
	ble _080CD7E4
	movs r0, #0xb1
	lsls r0, r0, #2
	add r0, sl
	ldr r2, [sp, #0xc]
	str r0, [r2]
	b _080CD942
_080CD898:
	movs r3, #0
	str r3, [sp]
	ldr r4, _080CD954 @ =0x0000094E
	add r4, sl
	str r4, [sp, #8]
	movs r6, #0xa9
	lsls r6, r6, #2
	add r6, sl
_080CD8A8:
	mov r7, r8
	ldrh r2, [r7]
	movs r0, #0x1f
	ands r0, r2
	ldr r3, [sp, #8]
	ldrb r1, [r3]
	adds r4, r0, r1
	cmp r4, #0x1f
	ble _080CD8BC
	movs r4, #0x1f
_080CD8BC:
	lsls r3, r2, #0x10
	lsrs r0, r3, #0x15
	movs r7, #0x1f
	ands r0, r7
	adds r2, r0, r1
	cmp r2, #0x1f
	ble _080CD8CC
	movs r2, #0x1f
_080CD8CC:
	lsrs r0, r3, #0x1a
	movs r3, #0x1f
	ands r0, r3
	adds r5, r0, r1
	cmp r5, #0x1f
	ble _080CD8DA
	movs r5, #0x1f
_080CD8DA:
	ldrh r1, [r6]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x15
	movs r7, #0x1f
	ands r3, r7
	lsrs r1, r1, #0x1a
	ands r1, r7
	mov r7, ip
	muls r7, r4, r7
	mov r4, sb
	muls r4, r0, r4
	adds r0, r4, #0
	adds r4, r7, r0
	ldr r7, [sp, #0x34]
	asrs r4, r7
	mov r0, ip
	muls r0, r2, r0
	adds r2, r0, #0
	mov r0, sb
	muls r0, r3, r0
	adds r2, r2, r0
	asrs r2, r7
	mov r0, ip
	muls r0, r5, r0
	mov r3, sb
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	asrs r0, r7
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r4
	strh r0, [r6, #0x20]
	movs r4, #2
	add r8, r4
	adds r6, #2
	ldr r7, [sp]
	adds r7, #1
	str r7, [sp]
	cmp r7, #0xf
	ble _080CD8A8
	movs r0, #0x8a
	lsls r0, r0, #1
	add r0, sl
	ldr r1, [r0]
	movs r0, #0xb1
	lsls r0, r0, #2
_080CD93E:
	add r0, sl
	str r0, [r1, #0xc]
_080CD942:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CD954: .4byte 0x0000094E

	thumb_func_start FUN_080cd958
FUN_080cd958: @ 0x080CD958
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r1, _080CD9E0 @ =0x00000951
	adds r0, r5, r1
	movs r2, #0x95
	lsls r2, r2, #4
	adds r1, r5, r2
	ldrb r0, [r0]
	ldrb r3, [r1]
	cmp r0, r3
	beq _080CD97A
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080cd738
_080CD97A:
	adds r0, r5, #0
	bl FUN_080cd6ec
	adds r2, r0, #0
	ldr r6, _080CD9E4 @ =0x0000094C
	adds r1, r5, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, r4
	bne _080CD998
	adds r6, #2
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, r2
	beq _080CD9A6
_080CD998:
	strh r4, [r1]
	ldr r1, _080CD9E8 @ =0x0000094E
	adds r0, r5, r1
	strb r2, [r0]
	adds r0, r5, #0
	bl FUN_080cd5a0
_080CD9A6:
	movs r3, #0x96
	lsls r3, r3, #4
	adds r2, r5, r3
	ldrh r4, [r2]
	cmp r4, #0
	beq _080CD9B4
	b _080CDADE
_080CD9B4:
	adds r0, r5, #0
	bl FUN_080ced00
	cmp r0, #0
	blt _080CDA40
	ldr r6, _080CD9EC @ =0x00000121
	adds r0, r0, r6
	ldr r2, _080CD9F0 @ =0x00000962
	adds r1, r5, r2
	strh r0, [r1]
	ldr r2, _080CD9F4 @ =0x03003584
	ldrh r0, [r1]
	lsls r0, r0, #5
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r3, _080CD9F8 @ =0x00000964
	adds r0, r5, r3
	ldrh r1, [r0]
	cmp r1, #0x1f
	bhi _080CD9FC
	adds r2, r1, #0
	b _080CDA12
	.align 2, 0
_080CD9E0: .4byte 0x00000951
_080CD9E4: .4byte 0x0000094C
_080CD9E8: .4byte 0x0000094E
_080CD9EC: .4byte 0x00000121
_080CD9F0: .4byte 0x00000962
_080CD9F4: .4byte 0x03003584
_080CD9F8: .4byte 0x00000964
_080CD9FC:
	cmp r1, #0x2f
	bhi _080CDA04
	movs r2, #0x20
	b _080CDA12
_080CDA04:
	cmp r1, #0x4f
	bhi _080CDA10
	ldrh r1, [r0]
	movs r0, #0x50
	subs r2, r0, r1
	b _080CDA12
_080CDA10:
	movs r2, #0
_080CDA12:
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080cd780
	ldr r6, _080CDA3C @ =0x00000964
	adds r1, r5, r6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x5f
	bhi _080CDA36
	b _080CDBA0
_080CDA36:
	movs r0, #0
	b _080CDB9E
	.align 2, 0
_080CDA3C: .4byte 0x00000964
_080CDA40:
	ldr r0, _080CDA7C @ =0x00000964
	adds r3, r5, r0
	ldrh r2, [r3]
	subs r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4e
	bhi _080CDAAE
	ldr r1, _080CDA80 @ =0x03003584
	ldr r6, _080CDA84 @ =0x00000962
	adds r0, r5, r6
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r6, r1, r0
	adds r0, r2, #0
	subs r0, #0x21
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _080CDA6E
	movs r0, #0x30
	strh r0, [r3]
_080CDA6E:
	ldrh r0, [r3]
	cmp r0, #0x20
	bhi _080CDA88
	adds r2, r0, #0
	subs r0, r2, #1
	strh r0, [r3]
	b _080CDA9C
	.align 2, 0
_080CDA7C: .4byte 0x00000964
_080CDA80: .4byte 0x03003584
_080CDA84: .4byte 0x00000962
_080CDA88:
	ldrh r0, [r3]
	movs r1, #0x50
	subs r2, r1, r0
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4f
	bls _080CDA9C
	strh r4, [r3]
_080CDA9C:
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_080cd780
	b _080CDBA0
_080CDAAE:
	strh r4, [r3]
	ldr r1, _080CDAC8 @ =0x00000359
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CDACC
	adds r1, r5, #0
	adds r1, #0xd0
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r0, r5, r2
	str r0, [r1]
	b _080CDBA0
	.align 2, 0
_080CDAC8: .4byte 0x00000359
_080CDACC:
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	movs r6, #0xa9
	lsls r6, r6, #2
	adds r0, r5, r6
	str r0, [r1, #0xc]
	b _080CDBA0
_080CDADE:
	ldr r1, _080CDB24 @ =0x00000964
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	ldrh r0, [r2]
	cmp r0, #0x1f
	bls _080CDB76
	ldr r1, _080CDB28 @ =0x03003584
	ldr r2, _080CDB2C @ =0x0000095E
	adds r0, r5, r2
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldr r3, _080CDB30 @ =0x00000359
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CDB4E
	movs r3, #0
	adds r6, r5, #0
	adds r6, #0xd0
	movs r0, #0xb1
	lsls r0, r0, #2
	adds r2, r5, r0
	subs r0, #0x20
	adds r4, r5, r0
_080CDB14:
	subs r0, r3, #5
	cmp r0, #1
	bls _080CDB1E
	cmp r3, #0xd
	bne _080CDB34
_080CDB1E:
	ldrh r0, [r4]
	b _080CDB36
	.align 2, 0
_080CDB24: .4byte 0x00000964
_080CDB28: .4byte 0x03003584
_080CDB2C: .4byte 0x0000095E
_080CDB30: .4byte 0x00000359
_080CDB34:
	ldrh r0, [r1]
_080CDB36:
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	adds r4, #2
	adds r3, #1
	cmp r3, #0xf
	ble _080CDB14
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r5, r1
	str r0, [r6]
	b _080CDB94
_080CDB4E:
	movs r3, #0xb1
	lsls r3, r3, #2
	adds r2, r5, r3
	movs r3, #0xf
_080CDB56:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _080CDB56
	movs r6, #0x8a
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r1, [r0]
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r0, r5, r2
	str r0, [r1, #0xc]
	b _080CDB94
_080CDB76:
	ldr r1, _080CDBA8 @ =0x03003584
	ldr r3, _080CDBAC @ =0x0000095E
	adds r0, r5, r3
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldrh r2, [r2]
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	bl FUN_080cd780
_080CDB94:
	movs r6, #0x96
	lsls r6, r6, #4
	adds r1, r5, r6
	ldrh r0, [r1]
	subs r0, #1
_080CDB9E:
	strh r0, [r1]
_080CDBA0:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CDBA8: .4byte 0x03003584
_080CDBAC: .4byte 0x0000095E

	thumb_func_start FUN_080cdbb0
FUN_080cdbb0: @ 0x080CDBB0
	ldr r1, [r0, #0x18]
	adds r1, #0x22
	ldr r3, _080CDBF4 @ =0x00000938
	adds r2, r0, r3
	strh r1, [r2]
	ldr r1, _080CDBF8 @ =0x0000093A
	adds r2, r0, r1
	ldr r1, _080CDBFC @ =0x00000121
	strh r1, [r2]
	adds r3, #4
	adds r2, r0, r3
	movs r1, #0x20
	strh r1, [r2]
	ldr r1, _080CDC00 @ =0x0000093E
	adds r2, r0, r1
	ldr r1, _080CDC04 @ =0x00000123
	strh r1, [r2]
	adds r3, #4
	adds r2, r0, r3
	adds r1, #1
	strh r1, [r2]
	ldr r1, _080CDC08 @ =0x00000942
	adds r2, r0, r1
	movs r1, #0x1f
	strh r1, [r2]
	adds r3, #4
	adds r2, r0, r3
	movs r1, #0x21
	strh r1, [r2]
	ldr r1, _080CDC0C @ =0x00000946
	adds r0, r0, r1
	movs r1, #0x1e
	strh r1, [r0]
	bx lr
	.align 2, 0
_080CDBF4: .4byte 0x00000938
_080CDBF8: .4byte 0x0000093A
_080CDBFC: .4byte 0x00000121
_080CDC00: .4byte 0x0000093E
_080CDC04: .4byte 0x00000123
_080CDC08: .4byte 0x00000942
_080CDC0C: .4byte 0x00000946

	thumb_func_start FUN_080cdc10
FUN_080cdc10: @ 0x080CDC10
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_080cdbb0
	ldr r0, _080CDC60 @ =0x0000094C
	adds r1, r4, r0
	ldr r0, _080CDC64 @ =0x0000FFFF
	strh r0, [r1]
	movs r0, #0x95
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _080CDC68 @ =0x00000938
	adds r5, r4, r1
	ldrh r0, [r5]
	adds r1, r4, #0
	adds r1, #0xc2
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #0xa9
	lsls r1, r1, #2
	adds r3, r4, r1
	str r3, [r0]
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, [r2]
	ldrh r0, [r5]
	strh r0, [r1, #6]
	ldr r0, [r2]
	str r3, [r0, #0xc]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080cd958
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CDC60: .4byte 0x0000094C
_080CDC64: .4byte 0x0000FFFF
_080CDC68: .4byte 0x00000938

	thumb_func_start FUN_080cdc6c
FUN_080cdc6c: @ 0x080CDC6C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	ldr r1, _080CDC90 @ =0x000004C5
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080CDC98
	ldr r2, _080CDC94 @ =0x000004C4
	adds r0, r7, r2
	bl FUN_082466ec
	b _080CDD7A
	.align 2, 0
_080CDC90: .4byte 0x000004C5
_080CDC94: .4byte 0x000004C4
_080CDC98:
	cmp r0, #2
	bne _080CDCA8
	ldr r0, [r7, #0x18]
	movs r1, #0x9a
	lsls r1, r1, #1
	bl FUN_080cc3e4
	b _080CDCB6
_080CDCA8:
	cmp r0, #3
	bne _080CDCB6
	ldr r0, [r7, #0x18]
	movs r1, #0x9a
	lsls r1, r1, #1
	bl FUN_080cc3e4
_080CDCB6:
	ldr r1, _080CDD8C @ =0x000004CC
	adds r0, r7, r1
	ldr r3, [r0]
	ldrh r0, [r3]
	ldr r6, _080CDD90 @ =0xFFFF0000
	ldr r2, [sp, #0xc]
	ands r2, r6
	orrs r2, r0
	str r2, [sp, #0xc]
	ldrh r1, [r3, #2]
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r0, _080CDD94 @ =0x0000FFFF
	mov r8, r0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	ldrh r1, [r3, #4]
	ldr r0, [sp, #0x10]
	ands r0, r6
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r5, _080CDD98 @ =0x0203B400
	ldr r1, _080CDD9C @ =0x030046B8
	mov sl, r1
	ldr r2, [r1]
	adds r2, #1
	ldr r4, _080CDDA0 @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #0xf
	mov sb, r1
	mov r1, sb
	ands r0, r1
	subs r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, [sp, #0x14]
	ands r3, r6
	orrs r3, r0
	str r3, [sp, #0x14]
	adds r2, #1
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	subs r1, #0x10
	lsls r1, r1, #0x10
	mov r0, r8
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x14]
	adds r2, #1
	ands r2, r4
	mov r0, sl
	str r2, [r0]
	lsls r2, r2, #1
	adds r2, r2, r5
	ldrh r1, [r2]
	mov r2, sb
	ands r1, r2
	subs r1, #7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r6
	orrs r0, r1
	str r0, [r3, #4]
	ldr r0, [sp, #0x1c]
	ands r0, r6
	movs r2, #5
	orrs r0, r2
	mov r1, r8
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r1, sp, #0x1c
	ldr r0, [r1, #4]
	ands r0, r6
	orrs r0, r2
	str r0, [r1, #4]
	ldr r2, _080CDDA4 @ =0x000004C4
	adds r0, r7, r2
	str r1, [sp]
	movs r1, #0x28
	str r1, [sp, #4]
	str r1, [sp, #8]
	movs r1, #3
	add r2, sp, #0xc
	bl FUN_08246728
_080CDD7A:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CDD8C: .4byte 0x000004CC
_080CDD90: .4byte 0xFFFF0000
_080CDD94: .4byte 0x0000FFFF
_080CDD98: .4byte 0x0203B400
_080CDD9C: .4byte 0x030046B8
_080CDDA0: .4byte 0x000003FF
_080CDDA4: .4byte 0x000004C4

	thumb_func_start FUN_080cdda8
FUN_080cdda8: @ 0x080CDDA8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _080CDDCC @ =0x000004C7
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CDDC4
	adds r4, r0, #0
_080CDDB8:
	adds r0, r5, #0
	bl FUN_080cdc6c
	subs r4, #1
	cmp r4, #0
	bne _080CDDB8
_080CDDC4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CDDCC: .4byte 0x000004C7

	thumb_func_start FUN_080cddd0
FUN_080cddd0: @ 0x080CDDD0
	adds r1, r0, #0
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, #1
	adds r1, r1, r2
	ldrb r1, [r1]
	subs r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	bx lr
	.align 2, 0

	thumb_func_start FUN_080cddf0
FUN_080cddf0: @ 0x080CDDF0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r5, r1, #0
	mov r8, r5
	ldr r0, _080CDE44 @ =0x000004C7
	adds r7, r4, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _080CDE5E
	adds r0, r4, #0
	bl FUN_080cddd0
	ldr r2, _080CDE48 @ =0x085AD148
	ldr r1, _080CDE4C @ =0x000004C5
	adds r6, r4, r1
	ldrb r1, [r6]
	subs r1, #1
	adds r1, r1, r2
	ldrb r1, [r1]
	cmp r0, r1
	blt _080CDE32
	adds r0, r4, #0
	bl FUN_080cdc6c
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
_080CDE32:
	ldrb r0, [r7]
	cmp r0, #0
	beq _080CDE5E
	ldrb r0, [r6]
	cmp r0, #1
	bne _080CDE50
	movs r5, #3
	b _080CDE5E
	.align 2, 0
_080CDE44: .4byte 0x000004C7
_080CDE48: .4byte 0x085AD148
_080CDE4C: .4byte 0x000004C5
_080CDE50:
	cmp r0, #2
	bne _080CDE58
	movs r5, #4
	b _080CDE5E
_080CDE58:
	cmp r0, #3
	bne _080CDE5E
	movs r5, #5
_080CDE5E:
	cmp r5, r8
	bne _080CDE8C
	ldr r0, _080CDE84 @ =0x00000954
	adds r3, r4, r0
	ldrh r2, [r3]
	lsls r0, r2, #0x10
	cmp r0, #0
	beq _080CDE9A
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080CDE7E
	ldr r1, _080CDE88 @ =0x00000952
	adds r0, r4, r1
	ldrh r5, [r0]
_080CDE7E:
	subs r0, r2, #1
	strh r0, [r3]
	b _080CDE9A
	.align 2, 0
_080CDE84: .4byte 0x00000954
_080CDE88: .4byte 0x00000952
_080CDE8C:
	ldr r2, _080CDEA8 @ =0x00000952
	adds r0, r4, r2
	strh r5, [r0]
	ldr r0, _080CDEAC @ =0x00000954
	adds r1, r4, r0
	movs r0, #0x40
	strh r0, [r1]
_080CDE9A:
	adds r0, r5, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080CDEA8: .4byte 0x00000952
_080CDEAC: .4byte 0x00000954

	thumb_func_start FUN_080cdeb0
FUN_080cdeb0: @ 0x080CDEB0
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r6, r1, #0
	movs r5, #0
_080CDEBA:
	cmp r5, #1
	beq _080CDECE
	cmp r5, #1
	bgt _080CDEC8
	cmp r5, #0
	beq _080CDF1C
	b _080CDFBC
_080CDEC8:
	cmp r5, #2
	beq _080CDF8C
	b _080CDFBC
_080CDECE:
	ldr r0, _080CDEF0 @ =0x0000043E
	adds r2, r4, r0
	ldrh r1, [r2]
	cmp r1, #0
	beq _080CDEF8
	ldr r0, [r4, #0x1c]
	ands r0, r5
	cmp r0, #0
	beq _080CDEE4
	subs r0, r1, #1
	strh r0, [r2]
_080CDEE4:
	movs r6, #2
	ldr r2, _080CDEF4 @ =0x00000956
	adds r1, r4, r2
	movs r0, #0x40
	strh r0, [r1]
	b _080CDFBC
	.align 2, 0
_080CDEF0: .4byte 0x0000043E
_080CDEF4: .4byte 0x00000956
_080CDEF8:
	ldr r7, _080CDF18 @ =0x00000956
	adds r3, r4, r7
	ldrh r2, [r3]
	lsls r0, r2, #0x10
	cmp r0, #0
	beq _080CDFBC
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080CDF10
	movs r6, #2
_080CDF10:
	subs r0, r2, #1
	strh r0, [r3]
	b _080CDFBC
	.align 2, 0
_080CDF18: .4byte 0x00000956
_080CDF1C:
	ldr r0, _080CDF40 @ =0x0000043C
	adds r3, r4, r0
	ldrh r2, [r3]
	cmp r2, #0
	beq _080CDFBC
	ldr r0, [r4, #0x1c]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080CDFBC
	subs r0, r2, #1
	strh r0, [r3]
	ldr r0, _080CDF44 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CDF48
	subs r1, #2
	b _080CDF4C
	.align 2, 0
_080CDF40: .4byte 0x0000043C
_080CDF44: .4byte 0x03002C68
_080CDF48:
	movs r2, #0x18
	ldrsh r1, [r0, r2]
_080CDF4C:
	ldr r0, [r4, #0x18]
	cmp r0, r1
	bne _080CDFBC
	movs r7, #0xa3
	lsls r7, r7, #2
	adds r0, r4, r7
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _080CDFBC
	movs r1, #0x98
	lsls r1, r1, #4
	adds r0, r4, r1
	str r0, [sp]
	ldr r2, _080CDF84 @ =0x00000984
	adds r0, r4, r2
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #1
	movs r2, #0x1e
	ldr r7, _080CDF88 @ =0x0000097C
	adds r3, r4, r7
	bl FUN_08016e0c
	b _080CDFBC
	.align 2, 0
_080CDF84: .4byte 0x00000984
_080CDF88: .4byte 0x0000097C
_080CDF8C:
	movs r0, #0x88
	lsls r0, r0, #3
	adds r3, r4, r0
	ldrh r2, [r3]
	cmp r2, #0
	beq _080CDFBC
	ldr r0, [r4, #0x1c]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080CDFBC
	subs r0, r2, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CDFBC
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #0x14]
	ldr r2, _080CDFD0 @ =0x00000456
	adds r0, r4, r2
	strb r1, [r0]
_080CDFBC:
	adds r5, #1
	cmp r5, #2
	bgt _080CDFC4
	b _080CDEBA
_080CDFC4:
	adds r0, r6, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080CDFD0: .4byte 0x00000456

	thumb_func_start FUN_080cdfd4
FUN_080cdfd4: @ 0x080CDFD4
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _080CDFF8 @ =0x0000095C
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080CDFF4
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080CDFFC
_080CDFF4:
	adds r0, r2, #0
	b _080CE002
	.align 2, 0
_080CDFF8: .4byte 0x0000095C
_080CDFFC:
	ldr r1, _080CE008 @ =0x0000095A
	adds r0, r3, r1
	ldrh r0, [r0]
_080CE002:
	pop {r1}
	bx r1
	.align 2, 0
_080CE008: .4byte 0x0000095A

	thumb_func_start FUN_080ce00c
FUN_080ce00c: @ 0x080CE00C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r1, _080CE084 @ =0x00000446
	adds r0, r4, r1
	ldrh r0, [r0]
	mov r8, r0
	cmp r0, #0
	bne _080CE022
	b _080CE1C4
_080CE022:
	ldr r2, _080CE088 @ =0x00000442
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _080CE094
	ldr r3, _080CE08C @ =0x0000097A
	adds r5, r4, r3
	ldrh r0, [r5]
	cmp r0, #0x3f
	bhi _080CE052
	cmp r0, #0
	bne _080CE04C
	ldr r0, [r4, #0x18]
	movs r1, #0xf7
	lsls r1, r1, #1
	bl FUN_080cc3e4
	ldr r0, _080CE090 @ =0x000003F1
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_080CE04C:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_080CE052:
	adds r2, r4, #0
	adds r2, #0x90
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080CE08C @ =0x0000097A
	adds r0, r4, r1
	ldrh r0, [r0]
	lsrs r0, r0, #1
	movs r1, #0x40
	subs r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xbc
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0xb
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	adds r5, r2, #0
	b _080CE0FE
	.align 2, 0
_080CE084: .4byte 0x00000446
_080CE088: .4byte 0x00000442
_080CE08C: .4byte 0x0000097A
_080CE090: .4byte 0x000003F1
_080CE094:
	ldr r2, _080CE0D8 @ =0x0000097A
	adds r6, r4, r2
	ldrh r0, [r6]
	adds r5, r4, #0
	adds r5, #0x90
	cmp r0, #0
	beq _080CE0FE
	ldr r3, _080CE0DC @ =0x000003F1
	adds r7, r4, r3
	ldrb r0, [r7]
	cmp r0, #0
	beq _080CE0B8
	ldr r0, [r4, #0x18]
	ldr r1, _080CE0E0 @ =0x00000336
	bl FUN_080cc3e4
	movs r0, #0
	strb r0, [r7]
_080CE0B8:
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CE0E4
	ldr r0, [r5]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0xbc
	movs r1, #0x40
	b _080CE0F8
	.align 2, 0
_080CE0D8: .4byte 0x0000097A
_080CE0DC: .4byte 0x000003F1
_080CE0E0: .4byte 0x00000336
_080CE0E4:
	ldr r0, [r5]
	movs r1, #2
	orrs r0, r1
	str r0, [r5]
	ldrh r0, [r6]
	lsrs r0, r0, #1
	movs r1, #0x40
	subs r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xbc
_080CE0F8:
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_080CE0FE:
	ldr r1, _080CE118 @ =0x00000442
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #6
	bne _080CE192
	ldr r0, _080CE11C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CE120
	movs r2, #1
	rsbs r2, r2, #0
	b _080CE124
	.align 2, 0
_080CE118: .4byte 0x00000442
_080CE11C: .4byte 0x03002C68
_080CE120:
	movs r3, #0x18
	ldrsh r2, [r0, r3]
_080CE124:
	ldr r0, [r4, #0x18]
	cmp r0, r2
	bne _080CE136
	adds r1, r4, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #2
	b _080CE17C
_080CE136:
	ldr r1, _080CE168 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r2, _080CE16C @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #0
	beq _080CE156
	ldr r3, _080CE170 @ =0x00000442
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #4
	bne _080CE156
	movs r2, #1
_080CE156:
	cmp r2, #0
	beq _080CE174
	adds r1, r4, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #2
	b _080CE17C
	.align 2, 0
_080CE168: .4byte 0x03002BE0
_080CE16C: .4byte 0x00000446
_080CE170: .4byte 0x00000442
_080CE174:
	adds r1, r4, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #1
_080CE17C:
	orrs r0, r2
	str r0, [r1]
	ldr r0, [r5]
	orrs r0, r2
	str r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	b _080CE1A4
_080CE192:
	adds r1, r4, #0
	adds r1, #0xe8
	ldr r0, [r1]
	ldr r2, _080CE1BC @ =0xFFFFFDFF
	ands r0, r2
	str r0, [r1]
	ldr r0, [r5]
	ands r0, r2
	str r0, [r5]
_080CE1A4:
	ldr r0, [r4, #0x1c]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080CE256
	ldr r0, _080CE1C0 @ =0x00000446
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b _080CE256
	.align 2, 0
_080CE1BC: .4byte 0xFFFFFDFF
_080CE1C0: .4byte 0x00000446
_080CE1C4:
	ldr r1, _080CE208 @ =0x0000097A
	adds r6, r4, r1
	ldrh r0, [r6]
	adds r5, r4, #0
	adds r5, #0x90
	cmp r0, #0
	beq _080CE22E
	ldr r2, _080CE20C @ =0x000003F1
	adds r7, r4, r2
	ldrb r0, [r7]
	cmp r0, #0
	beq _080CE1E8
	ldr r0, [r4, #0x18]
	ldr r1, _080CE210 @ =0x00000336
	bl FUN_080cc3e4
	mov r3, r8
	strb r3, [r7]
_080CE1E8:
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CE214
	ldr r0, [r5]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0xbc
	movs r1, #0x40
	b _080CE228
	.align 2, 0
_080CE208: .4byte 0x0000097A
_080CE20C: .4byte 0x000003F1
_080CE210: .4byte 0x00000336
_080CE214:
	ldr r0, [r5]
	movs r1, #2
	orrs r0, r1
	str r0, [r5]
	ldrh r0, [r6]
	lsrs r0, r0, #1
	movs r1, #0x40
	subs r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xbc
_080CE228:
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_080CE22E:
	ldr r1, [r5]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _080CE242
	ldr r0, _080CE260 @ =0xFFFFFDFF
	ands r1, r0
	str r1, [r5]
_080CE242:
	adds r1, r4, #0
	adds r1, #0xe8
	ldr r3, [r1]
	adds r0, r3, #0
	ands r0, r2
	cmp r0, #0
	beq _080CE256
	ldr r0, _080CE260 @ =0xFFFFFDFF
	ands r3, r0
	str r3, [r1]
_080CE256:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CE260: .4byte 0xFFFFFDFF

	thumb_func_start FUN_080ce264
FUN_080ce264: @ 0x080CE264
	push {lr}
	adds r2, r0, #0
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _080CE286
	movs r0, #0x80
	lsls r0, r0, #3
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080CE286:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ce28c
FUN_080ce28c: @ 0x080CE28C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080ce00c
	adds r0, r4, #0
	bl FUN_080ce264
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080cdeb0
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_080cddf0
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_080cdfd4
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_080cd958
	adds r0, r4, #0
	bl FUN_080cc648
	adds r0, r4, #0
	bl FUN_080cc780
	adds r0, r4, #0
	bl FUN_080ccf2c
	adds r0, r4, #0
	bl FUN_080cd0f0
	ldr r0, _080CE318 @ =0x00000714
	adds r1, r4, r0
	ldr r2, _080CE31C @ =0x000006AC
	adds r0, r4, r2
	ldr r1, [r1]
	bl _call_via_r1
	ldr r1, _080CE320 @ =0x00000604
	adds r0, r4, r1
	ldrh r0, [r0]
	ldrh r2, [r4, #0x2c]
	adds r0, r0, r2
	ldr r2, _080CE324 @ =0x000005FC
	adds r1, r4, r2
	strh r0, [r1]
	ldr r1, _080CE328 @ =0x00000606
	adds r0, r4, r1
	ldrh r0, [r0]
	ldrh r2, [r4, #0x2e]
	adds r0, r0, r2
	ldr r2, _080CE32C @ =0x000005FE
	adds r1, r4, r2
	strh r0, [r1]
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	ldrh r2, [r4, #0x30]
	adds r0, r0, r2
	subs r1, #8
	adds r4, r4, r1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CE318: .4byte 0x00000714
_080CE31C: .4byte 0x000006AC
_080CE320: .4byte 0x00000604
_080CE324: .4byte 0x000005FC
_080CE328: .4byte 0x00000606
_080CE32C: .4byte 0x000005FE

	thumb_func_start FUN_080ce330
FUN_080ce330: @ 0x080CE330
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080CE370 @ =0x000004C4
	adds r0, r4, r1
	bl FUN_08247504
	ldr r1, _080CE374 @ =0x0000060C
	adds r0, r4, r1
	bl FUN_080138fc
	movs r1, #0xca
	lsls r1, r1, #3
	adds r0, r4, r1
	bl FUN_0822dabc
	movs r1, #0xd0
	lsls r1, r1, #3
	adds r0, r4, r1
	bl FUN_0822dabc
	adds r0, r4, #0
	bl FUN_080cd078
	adds r0, r4, #0
	bl FUN_080cd528
	adds r0, r4, #0
	bl FUN_080cce5c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CE370: .4byte 0x000004C4
_080CE374: .4byte 0x0000060C

	thumb_func_start FUN_080ce378
FUN_080ce378: @ 0x080CE378
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _080CE440 @ =0x000004C4
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0xa8
	movs r1, #1
	str r1, [sp]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0824742c
	ldr r2, _080CE444 @ =0x000005FC
	adds r1, r5, r2
	ldr r2, [r4]
	ldr r3, [r4, #4]
	str r2, [r1]
	str r3, [r1, #4]
	ldr r3, _080CE448 @ =0x00000604
	adds r0, r5, r3
	movs r4, #0
	movs r2, #0
	strh r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strh r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strh r2, [r0]
	ldr r2, _080CE44C @ =0x0000060C
	adds r0, r5, r2
	movs r2, #0
	bl FUN_0801385c
	bl FUN_080dc44c
	adds r0, r5, #0
	bl FUN_080cdc10
	adds r0, r5, #0
	bl FUN_080cc71c
	adds r0, r5, #0
	bl FUN_080cc8e0
	adds r0, r5, #0
	bl FUN_080cd098
	adds r0, r5, #0
	bl FUN_080cd548
	adds r0, r5, #0
	bl FUN_080cce70
	ldr r3, _080CE450 @ =0x0000097C
	adds r0, r5, r3
	movs r1, #4
	strb r1, [r0]
	ldr r2, _080CE454 @ =0x0000097D
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r4, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r4, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r4, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r4, [r0]
	adds r3, #2
	adds r0, r5, r3
	strh r1, [r0]
	adds r2, #3
	adds r0, r5, r2
	strh r1, [r0]
	adds r3, #4
	adds r0, r5, r3
	strh r1, [r0]
	adds r2, #4
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, _080CE458 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CE45C
	subs r1, #5
	b _080CE460
	.align 2, 0
_080CE440: .4byte 0x000004C4
_080CE444: .4byte 0x000005FC
_080CE448: .4byte 0x00000604
_080CE44C: .4byte 0x0000060C
_080CE450: .4byte 0x0000097C
_080CE454: .4byte 0x0000097D
_080CE458: .4byte 0x03002C68
_080CE45C:
	movs r3, #0x18
	ldrsh r1, [r0, r3]
_080CE460:
	ldr r0, [r5, #0x18]
	cmp r0, r1
	bne _080CE474
	ldr r0, _080CE470 @ =0x00000978
	adds r1, r5, r0
	movs r0, #0
	b _080CE47A
	.align 2, 0
_080CE470: .4byte 0x00000978
_080CE474:
	ldr r2, _080CE4B4 @ =0x00000978
	adds r1, r5, r2
	movs r0, #1
_080CE47A:
	strb r0, [r1]
	movs r3, #0x97
	lsls r3, r3, #4
	adds r0, r5, r3
	movs r1, #0
	strh r1, [r0]
	ldr r2, _080CE4B8 @ =0x00000972
	adds r0, r5, r2
	strh r1, [r0]
	adds r3, #4
	adds r0, r5, r3
	strh r1, [r0]
	ldr r0, _080CE4BC @ =0x03002BAC
	strh r1, [r0]
	ldr r0, _080CE4C0 @ =0x03002B90
	strh r1, [r0]
	ldr r2, _080CE4C4 @ =0x03002B84
	movs r0, #1
	strh r0, [r2]
	ldr r0, _080CE4C8 @ =0x03002BF0
	strh r1, [r0]
	ldr r0, _080CE4CC @ =0x000003FF
	adds r1, r5, r0
	movs r0, #0xff
	strb r0, [r1]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CE4B4: .4byte 0x00000978
_080CE4B8: .4byte 0x00000972
_080CE4BC: .4byte 0x03002BAC
_080CE4C0: .4byte 0x03002B90
_080CE4C4: .4byte 0x03002B84
_080CE4C8: .4byte 0x03002BF0
_080CE4CC: .4byte 0x000003FF

	thumb_func_start FUN_080ce4d0
FUN_080ce4d0: @ 0x080CE4D0
	push {lr}
	ldr r1, [r0, #0x18]
	ldr r0, _080CE4E0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CE4E4
	movs r0, #0
	b _080CE4EA
	.align 2, 0
_080CE4E0: .4byte 0x03002C68
_080CE4E4:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_080CE4EA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080ce4f0
FUN_080ce4f0: @ 0x080CE4F0
	push {lr}
	bl FUN_080cc618
	cmp r0, #0
	bne _080CE4FE
	movs r0, #0
	b _080CE500
_080CE4FE:
	movs r0, #0xa
_080CE500:
	pop {r1}
	bx r1

	thumb_func_start FUN_080ce504
FUN_080ce504: @ 0x080CE504
	push {lr}
	movs r0, #0x80
	ldr r1, [r2, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _080CE538
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080CE538
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080CE538
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r1
	cmp r0, #0
	bne _080CE538
	movs r0, #0x80
	lsls r0, r0, #4
	ands r1, r0
	cmp r1, #0
	beq _080CE53C
_080CE538:
	movs r0, #0xa
	b _080CE53E
_080CE53C:
	movs r0, #0
_080CE53E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080ce544
FUN_080ce544: @ 0x080CE544
	push {lr}
	adds r2, r0, #0
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _080CE554
	movs r2, #0
	b _080CE576
_080CE554:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _080CE560
	movs r2, #1
	b _080CE576
_080CE560:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _080CE56C
	movs r2, #2
	b _080CE576
_080CE56C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _080CE596
	movs r2, #3
_080CE576:
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	beq _080CE596
	ldr r1, _080CE59C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _080CE596
	ldr r0, [r1, #0x1c]
	cmp r0, #1
	bne _080CE596
	adds r0, r1, #0
	bl FUN_08064058
_080CE596:
	pop {r0}
	bx r0
	.align 2, 0
_080CE59C: .4byte 0x03002BE0

	thumb_func_start FUN_080ce5a0
FUN_080ce5a0: @ 0x080CE5A0
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r6, r1, #0
	movs r1, #0
	ldr r2, _080CE5EC @ =0x00000A9C
	adds r0, r3, r2
	movs r5, #2
_080CE5AE:
	str r1, [r0]
	str r1, [r0, #0xc]
	str r1, [r0, #0x18]
	adds r0, #4
	subs r5, #1
	cmp r5, #0
	bge _080CE5AE
	movs r1, #0xde
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r2, #0x10
	rsbs r2, r2, #0
	ldr r1, [r0]
	ands r1, r2
	str r1, [r0]
	movs r5, #0
	adds r4, r0, #0
_080CE5D0:
	lsls r0, r5, #2
	adds r1, r6, r0
	ldrb r1, [r1, #0x18]
	subs r1, #1
	adds r2, r0, #0
	cmp r1, #0x1e
	bls _080CE5E0
	b _080CE858
_080CE5E0:
	lsls r0, r1, #2
	ldr r1, _080CE5F0 @ =_080CE5F4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080CE5EC: .4byte 0x00000A9C
_080CE5F0: .4byte _080CE5F4
_080CE5F4: @ jump table
	.4byte _080CE670 @ case 0
	.4byte _080CE698 @ case 1
	.4byte _080CE710 @ case 2
	.4byte _080CE724 @ case 3
	.4byte _080CE858 @ case 4
	.4byte _080CE858 @ case 5
	.4byte _080CE858 @ case 6
	.4byte _080CE6C0 @ case 7
	.4byte _080CE6D4 @ case 8
	.4byte _080CE6AC @ case 9
	.4byte _080CE6FC @ case 10
	.4byte _080CE6E8 @ case 11
	.4byte _080CE684 @ case 12
	.4byte _080CE670 @ case 13
	.4byte _080CE698 @ case 14
	.4byte _080CE74C @ case 15
	.4byte _080CE738 @ case 16
	.4byte _080CE7C4 @ case 17
	.4byte _080CE7D8 @ case 18
	.4byte _080CE7EC @ case 19
	.4byte _080CE800 @ case 20
	.4byte _080CE760 @ case 21
	.4byte _080CE774 @ case 22
	.4byte _080CE788 @ case 23
	.4byte _080CE79C @ case 24
	.4byte _080CE7B0 @ case 25
	.4byte _080CE814 @ case 26
	.4byte _080CE828 @ case 27
	.4byte _080CE850 @ case 28
	.4byte _080CE846 @ case 29
	.4byte _080CE83C @ case 30
_080CE670:
	ldr r1, _080CE67C @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE680 @ =FUN_080ce4d0
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE67C: .4byte 0x00000A9C
_080CE680: .4byte FUN_080ce4d0
_080CE684:
	ldr r1, _080CE690 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE694 @ =FUN_08063d18
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE690: .4byte 0x00000A9C
_080CE694: .4byte FUN_08063d18
_080CE698:
	ldr r1, _080CE6A4 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE6A8 @ =FUN_080ce4f0
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE6A4: .4byte 0x00000A9C
_080CE6A8: .4byte FUN_080ce4f0
_080CE6AC:
	ldr r1, _080CE6B8 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE6BC @ =FUN_08063d84
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE6B8: .4byte 0x00000A9C
_080CE6BC: .4byte FUN_08063d84
_080CE6C0:
	ldr r1, _080CE6CC @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE6D0 @ =FUN_08063d94
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE6CC: .4byte 0x00000A9C
_080CE6D0: .4byte FUN_08063d94
_080CE6D4:
	ldr r1, _080CE6E0 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE6E4 @ =FUN_08063da0
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE6E0: .4byte 0x00000A9C
_080CE6E4: .4byte FUN_08063da0
_080CE6E8:
	ldr r1, _080CE6F4 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE6F8 @ =FUN_08063db0
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE6F4: .4byte 0x00000A9C
_080CE6F8: .4byte FUN_08063db0
_080CE6FC:
	ldr r1, _080CE708 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE70C @ =FUN_08063dd4
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE708: .4byte 0x00000A9C
_080CE70C: .4byte FUN_08063dd4
_080CE710:
	ldr r1, _080CE71C @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE720 @ =FUN_08063df8
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE71C: .4byte 0x00000A9C
_080CE720: .4byte FUN_08063df8
_080CE724:
	ldr r1, _080CE730 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE734 @ =FUN_08063e1c
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE730: .4byte 0x00000A9C
_080CE734: .4byte FUN_08063e1c
_080CE738:
	ldr r1, _080CE744 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE748 @ =FUN_080ce504
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE744: .4byte 0x00000AB4
_080CE748: .4byte FUN_080ce504
_080CE74C:
	ldr r1, _080CE758 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE75C @ =FUN_08063ed8
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE758: .4byte 0x00000AB4
_080CE75C: .4byte FUN_08063ed8
_080CE760:
	ldr r1, _080CE76C @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE770 @ =FUN_08063f10
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE76C: .4byte 0x00000AB4
_080CE770: .4byte FUN_08063f10
_080CE774:
	ldr r1, _080CE780 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE784 @ =FUN_08063f28
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE780: .4byte 0x00000AB4
_080CE784: .4byte FUN_08063f28
_080CE788:
	ldr r1, _080CE794 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE798 @ =FUN_08063f40
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE794: .4byte 0x00000AB4
_080CE798: .4byte FUN_08063f40
_080CE79C:
	ldr r1, _080CE7A8 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE7AC @ =FUN_08063f58
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE7A8: .4byte 0x00000AB4
_080CE7AC: .4byte FUN_08063f58
_080CE7B0:
	ldr r1, _080CE7BC @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE7C0 @ =FUN_08063f70
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE7BC: .4byte 0x00000AB4
_080CE7C0: .4byte FUN_08063f70
_080CE7C4:
	ldr r1, _080CE7D0 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE7D4 @ =FUN_08063f88
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE7D0: .4byte 0x00000AB4
_080CE7D4: .4byte FUN_08063f88
_080CE7D8:
	ldr r1, _080CE7E4 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE7E8 @ =FUN_08063fa0
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE7E4: .4byte 0x00000AB4
_080CE7E8: .4byte FUN_08063fa0
_080CE7EC:
	ldr r1, _080CE7F8 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE7FC @ =FUN_08063fb8
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE7F8: .4byte 0x00000AB4
_080CE7FC: .4byte FUN_08063fb8
_080CE800:
	ldr r1, _080CE80C @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE810 @ =FUN_08063fd0
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE80C: .4byte 0x00000AB4
_080CE810: .4byte FUN_08063fd0
_080CE814:
	ldr r1, _080CE820 @ =0x00000AA8
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE824 @ =CheckNamakuraProc
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE820: .4byte 0x00000AA8
_080CE824: .4byte CheckNamakuraProc
_080CE828:
	ldr r1, _080CE834 @ =0x00000AA8
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE838 @ =CheckParalyzeProc
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE834: .4byte 0x00000AA8
_080CE838: .4byte CheckParalyzeProc
_080CE83C:
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	b _080CE856
_080CE846:
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	b _080CE856
_080CE850:
	movs r1, #4
	ldr r0, [r4]
	orrs r0, r1
_080CE856:
	str r0, [r4]
_080CE858:
	adds r5, #1
	cmp r5, #2
	bgt _080CE860
	b _080CE5D0
_080CE860:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ce868
FUN_080ce868: @ 0x080CE868
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	movs r0, #0xa1
	lsls r0, r0, #4
	adds r6, r4, r0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _080CE8FC
	ldr r2, _080CE8EC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0xaa
	orrs r0, r3
	ldr r1, _080CE8F0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r0, _080CE8F4 @ =0xFFEC0000
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldr r2, _080CE8F8 @ =0x00002101
	adds r1, r4, #0
	adds r1, #0x28
	movs r0, #0x80
	lsls r0, r0, #9
	ldrb r1, [r1]
	lsls r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #2
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #0x32
	movs r3, #0x10
	bl FUN_082364f8
	adds r0, r6, #0
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823651c
	b _080CEA82
	.align 2, 0
_080CE8EC: .4byte 0xFFFF0000
_080CE8F0: .4byte 0x0000FFFF
_080CE8F4: .4byte 0xFFEC0000
_080CE8F8: .4byte 0x00002101
_080CE8FC:
	ldr r1, _080CE914 @ =0x00000A75
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _080CE908
	b _080CEA82
_080CE908:
	lsls r0, r0, #2
	ldr r1, _080CE918 @ =_080CE91C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080CE914: .4byte 0x00000A75
_080CE918: .4byte _080CE91C
_080CE91C: @ jump table
	.4byte _080CE930 @ case 0
	.4byte _080CE968 @ case 1
	.4byte _080CE99C @ case 2
	.4byte _080CE9D0 @ case 3
	.4byte _080CEA08 @ case 4
_080CE930:
	movs r3, #0
	movs r2, #0x5a
	add r0, sp, #0xc
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x32
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	add r2, sp, #0x14
	strh r3, [r2]
	ldr r0, _080CE95C @ =0x0000FFE7
	strh r0, [r2, #2]
	strh r3, [r2, #4]
	movs r5, #1
	ldr r3, _080CE960 @ =0x00000A7C
	adds r1, r4, r3
	movs r0, #0x20
	strh r0, [r1]
	ldr r0, _080CE964 @ =0x00000A7E
	adds r1, r4, r0
	movs r0, #0x14
	b _080CEA32
	.align 2, 0
_080CE95C: .4byte 0x0000FFE7
_080CE960: .4byte 0x00000A7C
_080CE964: .4byte 0x00000A7E
_080CE968:
	movs r3, #0
	movs r2, #0x3c
	add r0, sp, #0xc
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x64
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	add r2, sp, #0x14
	strh r3, [r2]
	strh r3, [r2, #2]
	strh r3, [r2, #4]
	movs r5, #2
	ldr r3, _080CE994 @ =0x00000A7C
	adds r1, r4, r3
	movs r0, #0x40
	strh r0, [r1]
	ldr r0, _080CE998 @ =0x00000A7E
	adds r1, r4, r0
	movs r0, #0x28
	b _080CEA32
	.align 2, 0
_080CE994: .4byte 0x00000A7C
_080CE998: .4byte 0x00000A7E
_080CE99C:
	movs r3, #0
	movs r2, #0x50
	add r0, sp, #0xc
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x46
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	add r2, sp, #0x14
	strh r3, [r2]
	movs r0, #0x1e
	strh r0, [r2, #2]
	strh r3, [r2, #4]
	movs r5, #4
	ldr r3, _080CE9C8 @ =0x00000A7C
	adds r1, r4, r3
	movs r0, #0x30
	strh r0, [r1]
	ldr r0, _080CE9CC @ =0x00000A7E
	adds r1, r4, r0
	movs r0, #0x28
	b _080CEA32
	.align 2, 0
_080CE9C8: .4byte 0x00000A7C
_080CE9CC: .4byte 0x00000A7E
_080CE9D0:
	movs r3, #0
	movs r2, #0x3c
	add r0, sp, #0xc
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x64
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	add r2, sp, #0x14
	strh r3, [r2]
	ldr r0, _080CE9FC @ =0x0000FFB0
	strh r0, [r2, #2]
	strh r3, [r2, #4]
	movs r5, #8
	ldr r3, _080CEA00 @ =0x00000A7C
	adds r1, r4, r3
	movs r0, #1
	strh r0, [r1]
	ldr r0, _080CEA04 @ =0x00000A7E
	adds r1, r4, r0
	movs r0, #0x14
	b _080CEA32
	.align 2, 0
_080CE9FC: .4byte 0x0000FFB0
_080CEA00: .4byte 0x00000A7C
_080CEA04: .4byte 0x00000A7E
_080CEA08:
	movs r3, #0
	movs r2, #0x3c
	add r0, sp, #0xc
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x32
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	add r2, sp, #0x14
	strh r3, [r2]
	ldr r0, _080CEA8C @ =0x0000FFE7
	strh r0, [r2, #2]
	strh r3, [r2, #4]
	movs r5, #0x10
	ldr r3, _080CEA90 @ =0x00000A7C
	adds r1, r4, r3
	movs r0, #0x20
	strh r0, [r1]
	ldr r0, _080CEA94 @ =0x00000A7E
	adds r1, r4, r0
	movs r0, #0x1e
_080CEA32:
	strh r0, [r1]
	adds r3, r2, #0
	ldr r2, _080CEA98 @ =0x00002101
	adds r1, r4, #0
	adds r1, #0x28
	movs r0, #0x80
	lsls r0, r0, #9
	ldrb r1, [r1]
	lsls r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp]
	add r1, sp, #0xc
	str r1, [sp, #4]
	str r3, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r2, _080CEA9C @ =0x00000A7A
	adds r0, r4, r2
	ldrh r1, [r0]
	ldr r3, _080CEA90 @ =0x00000A7C
	adds r0, r4, r3
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r3, #2
	adds r0, r4, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r6, #0
	adds r3, r5, #0
	bl FUN_082364f8
	ldr r1, _080CEAA0 @ =FUN_080d1b68
	adds r0, r6, #0
	adds r2, r4, #0
	bl FUN_0823651c
_080CEA82:
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CEA8C: .4byte 0x0000FFE7
_080CEA90: .4byte 0x00000A7C
_080CEA94: .4byte 0x00000A7E
_080CEA98: .4byte 0x00002101
_080CEA9C: .4byte 0x00000A7A
_080CEAA0: .4byte FUN_080d1b68

	thumb_func_start FUN_080ceaa4
FUN_080ceaa4: @ 0x080CEAA4
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	movs r1, #0xd8
	lsls r1, r1, #2
	adds r2, r2, r1
	ldrh r1, [r2]
	adds r1, #0x63
	asrs r1, r1, #1
	ldrb r2, [r4, #1]
	cmp r2, #3
	beq _080CEADC
	cmp r2, #3
	ble _080CEAC6
	cmp r2, #4
	beq _080CEAE0
	b _080CEAF6
_080CEAC6:
	cmp r2, #0
	blt _080CEAF6
	ldrb r0, [r4, #4]
	adds r0, r1, r0
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r0, r1
	cmp r0, #0
	bgt _080CEAF6
	movs r0, #1
	b _080CEAF6
_080CEADC:
	adds r0, r1, #0
	b _080CEAF6
_080CEAE0:
	movs r0, #0x28
	movs r1, #0xa
	bl Div
	adds r1, r0, #0
	subs r1, #8
	lsls r0, r1, #2
	adds r0, r0, r1
	ldrb r4, [r4, #4]
	adds r0, r0, r4
	lsls r0, r0, #1
_080CEAF6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start player_weapon_080ceafc
player_weapon_080ceafc: @ 0x080CEAFC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	ldr r1, _080CEB58 @ =0x00000A74
	adds r5, r7, r1
	movs r2, #0
	mov r8, r2
	strb r0, [r5]
	ldrb r0, [r4, #1]
	adds r1, #1
	adds r6, r7, r1
	strb r0, [r6]
	ldrb r1, [r4, #4]
	ldr r2, _080CEB5C @ =0x00000A78
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r1, [r4, #8]
	adds r2, #0x1e
	adds r0, r7, r2
	strh r1, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_080ceaa4
	ldr r2, _080CEB60 @ =0x00000A7A
	adds r1, r7, r2
	strh r0, [r1]
	ldr r1, _080CEB64 @ =0x00000A7C
	adds r0, r7, r1
	mov r2, r8
	strh r2, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_080ce5a0
	ldrb r0, [r5]
	cmp r0, #0x3d
	bne _080CEB70
	ldr r0, _080CEB68 @ =0x00000A98
	adds r1, r7, r0
	ldr r0, _080CEB6C @ =FUN_080d3b14
	str r0, [r1]
	b _080CEB80
	.align 2, 0
_080CEB58: .4byte 0x00000A74
_080CEB5C: .4byte 0x00000A78
_080CEB60: .4byte 0x00000A7A
_080CEB64: .4byte 0x00000A7C
_080CEB68: .4byte 0x00000A98
_080CEB6C: .4byte FUN_080d3b14
_080CEB70:
	ldr r1, _080CEB90 @ =0x00000A98
	adds r2, r7, r1
	ldr r1, _080CEB94 @ =0x085AD14C
	ldrb r0, [r6]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
_080CEB80:
	adds r0, r7, #0
	bl FUN_080ce868
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CEB90: .4byte 0x00000A98
_080CEB94: .4byte 0x085AD14C

	thumb_func_start FUN_080ceb98
FUN_080ceb98: @ 0x080CEB98
	ldr r1, _080CEBA4 @ =0x085AD160
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
	.align 2, 0
_080CEBA4: .4byte 0x085AD160

	thumb_func_start FUN_080ceba8
FUN_080ceba8: @ 0x080CEBA8
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bge _080CEBBE
	movs r0, #0
	b _080CEBF0
_080CEBBE:
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl FUN_080ceb98
	adds r2, r0, #0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #5
	bgt _080CEBEE
	movs r1, #2
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080CEBEE
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #4
	movs r1, #0x64
	bl Div
	adds r2, r0, #0
_080CEBEE:
	adds r0, r2, #0
_080CEBF0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080cebf8
FUN_080cebf8: @ 0x080CEBF8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080ceba8
	movs r1, #0xda
	lsls r1, r1, #2
	adds r4, r4, r1
	ldrh r1, [r4]
	cmp r1, r0
	bge _080CEC10
	movs r0, #0
	b _080CEC12
_080CEC10:
	movs r0, #1
_080CEC12:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080cec18
FUN_080cec18: @ 0x080CEC18
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080ceba8
	adds r2, r0, #0
	movs r0, #0xda
	lsls r0, r0, #2
	adds r4, r4, r0
	ldrh r3, [r4]
	cmp r3, r2
	bge _080CEC4C
	ldr r0, _080CEC48 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _080CEC42
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r0, [r1]
	adds r0, r0, r3
	str r0, [r1]
_080CEC42:
	movs r0, #0
	b _080CEC64
	.align 2, 0
_080CEC48: .4byte 0x03002C68
_080CEC4C:
	ldr r0, _080CEC6C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _080CEC60
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r1, r0, r3
	ldr r0, [r1]
	adds r0, r0, r2
	str r0, [r1]
_080CEC60:
	ldrh r0, [r4]
	subs r0, r0, r2
_080CEC64:
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CEC6C: .4byte 0x03002C68

	thumb_func_start FUN_080cec70
FUN_080cec70: @ 0x080CEC70
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	cmp r4, #0
	blt _080CECA0
	adds r0, r4, #0
	bl GetMagicCategory
	adds r2, r0, #0
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r1, r5, r3
	ldrb r1, [r1]
	cmp r1, #0
	bne _080CECA4
	cmp r2, #0
	bne _080CEC98
	cmp r4, #1
	beq _080CECA0
	b _080CECF4
_080CEC98:
	cmp r2, #1
	beq _080CECF4
	cmp r2, #2
	bne _080CECFA
_080CECA0:
	movs r0, #0
	b _080CECFA
_080CECA4:
	cmp r1, #1
	bne _080CECE8
	cmp r2, #0
	bne _080CECC2
	cmp r4, #0
	beq _080CECA0
	cmp r4, #2
	beq _080CECA0
	cmp r4, #3
	beq _080CECA0
	cmp r4, #4
	beq _080CECA0
	cmp r4, #5
	beq _080CECA0
	b _080CECF4
_080CECC2:
	cmp r2, #1
	beq _080CECA0
	cmp r2, #2
	bne _080CECFA
	cmp r4, #0xe
	bne _080CECF4
	ldr r0, _080CECE0 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080CECE4 @ =0x00000252
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bge _080CECA0
	b _080CECF4
	.align 2, 0
_080CECE0: .4byte 0x030046A0
_080CECE4: .4byte 0x00000252
_080CECE8:
	cmp r1, #5
	beq _080CECF4
	cmp r1, #3
	bne _080CECF8
	cmp r4, #0x10
	bne _080CECA0
_080CECF4:
	movs r0, #1
	b _080CECFA
_080CECF8:
	movs r0, #0
_080CECFA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080ced00
FUN_080ced00: @ 0x080CED00
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080CED3C @ =0x00000283
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CED44
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #5
	bgt _080CED44
	adds r0, r4, #0
	bl FUN_080cebf8
	cmp r0, #0
	beq _080CED44
	ldr r1, _080CED40 @ =0x00000A75
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080CED44
	movs r0, #0
	ldrsb r0, [r5, r0]
	b _080CED48
	.align 2, 0
_080CED3C: .4byte 0x00000283
_080CED40: .4byte 0x00000A75
_080CED44:
	movs r0, #1
	rsbs r0, r0, #0
_080CED48:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080ced50
FUN_080ced50: @ 0x080CED50
	push {lr}
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, r1
	blt _080CED62
	movs r0, #1
	b _080CED64
_080CED62:
	movs r0, #0
_080CED64:
	pop {r1}
	bx r1

	thumb_func_start FUN_080ced68
FUN_080ced68: @ 0x080CED68
	push {lr}
	ldr r2, [r0, #0x18]
	ldr r0, _080CED78 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CED7C
	movs r0, #0
	b _080CED82
	.align 2, 0
_080CED78: .4byte 0x03002C68
_080CED7C:
	adds r0, #0x60
	adds r0, r0, r2
	ldrb r0, [r0]
_080CED82:
	cmp r0, r1
	blt _080CED8A
	movs r0, #1
	b _080CED8C
_080CED8A:
	movs r0, #0
_080CED8C:
	pop {r1}
	bx r1

	thumb_func_start FUN_080ced90
FUN_080ced90: @ 0x080CED90
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0
	ldrsb r1, [r4, r1]
	cmp r1, #0
	bge _080CEDAE
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	b _080CEEB6
_080CEDAE:
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _080CEDBE
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	b _080CEEB6
_080CEDBE:
	cmp r1, #5
	bgt _080CEE10
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _080CEDD8
	movs r1, #0
	strb r1, [r4, #3]
	ldr r2, _080CEDD4 @ =0x00000951
	adds r0, r6, r2
	strb r1, [r0]
	b _080CEDFE
	.align 2, 0
_080CEDD4: .4byte 0x00000951
_080CEDD8:
	movs r5, #1
	strb r5, [r4, #3]
	adds r0, r6, #0
	bl FUN_080ced00
	cmp r0, #0
	blt _080CEDFE
	ldr r1, _080CEE08 @ =0x00000979
	adds r0, r6, r1
	strb r5, [r0]
	ldr r2, _080CEE0C @ =0x00000964
	adds r1, r6, r2
	movs r0, #0x20
	strh r0, [r1]
	ldrb r0, [r4]
	adds r0, #1
	subs r2, #0x13
	adds r1, r6, r2
	strb r0, [r1]
_080CEDFE:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	b _080CEEB6
	.align 2, 0
_080CEE08: .4byte 0x00000979
_080CEE0C: .4byte 0x00000964
_080CEE10:
	cmp r1, #0x10
	bne _080CEE72
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r4, r6, r2
	ldrb r0, [r4]
	cmp r0, #1
	bhi _080CEEB6
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _080CEE6E
	adds r0, r6, #0
	bl FUN_080cebf8
	cmp r0, #0
	beq _080CEEB4
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r6, r2
	adds r2, #0x20
	adds r1, r6, r2
	str r1, [r0]
	adds r5, r6, #0
	adds r5, #0xe8
	adds r0, r5, #0
	bl FUN_0822a4fc
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r1, r6, r2
	ldr r1, [r1]
	movs r4, #0
	str r4, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_08237040
	str r4, [r5]
	adds r0, r6, #0
	bl FUN_080cec18
_080CEE6E:
	movs r0, #0xd
	b _080CEEB6
_080CEE72:
	movs r0, #0xdf
	lsls r0, r0, #2
	adds r4, r6, r0
	ldrb r0, [r4]
	cmp r0, #1
	bhi _080CEEB6
	cmp r1, #8
	bne _080CEE96
	adds r0, r6, #0
	bl FUN_080cebf8
	cmp r0, #0
	beq _080CEEB4
	adds r0, r6, #0
	bl FUN_080cec18
	movs r0, #2
	b _080CEEB6
_080CEE96:
	cmp r1, #0xb
	bne _080CEE9E
	movs r0, #2
	b _080CEEB6
_080CEE9E:
	cmp r1, #0xd
	bne _080CEEB4
	ldr r1, _080CEEB0 @ =0x000003FB
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CEEB4
	movs r0, #0x11
	b _080CEEB6
	.align 2, 0
_080CEEB0: .4byte 0x000003FB
_080CEEB4:
	ldrb r0, [r4]
_080CEEB6:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080ceec0
FUN_080ceec0: @ 0x080CEEC0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r4, r5, r0
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	adds r0, #0x42
	ldrb r0, [r0]
	movs r6, #0
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _080CEEEA
	movs r0, #0xff
	strb r0, [r4, #1]
	strb r6, [r4, #4]
	strb r6, [r4, #2]
	b _080CEF0A
_080CEEEA:
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl GetMagicCategory
	strb r0, [r4, #1]
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl FUN_080ceb98
	strb r0, [r4, #4]
	movs r1, #0
	ldrsb r1, [r4, r1]
	adds r0, r5, #0
	bl FUN_080cec70
	strb r0, [r4, #2]
_080CEF0A:
	strb r6, [r4, #3]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080cef14
FUN_080cef14: @ 0x080CEF14
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _080CEF26
	bl Script_GetValue
_080CEF26:
	str r0, [r4, #0x18]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080cef30
FUN_080cef30: @ 0x080CEF30
	push {lr}
	ldr r1, [r0, #0x18]
	ldr r0, _080CEF44 @ =0x03002C68
	ldr r2, [r0]
	cmp r2, #0
	beq _080CEF40
	cmp r1, #0
	bge _080CEF48
_080CEF40:
	movs r0, #0
	b _080CEF56
	.align 2, 0
_080CEF44: .4byte 0x03002C68
_080CEF48:
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r2, r0
_080CEF56:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080cef5c
FUN_080cef5c: @ 0x080CEF5C
	push {r4, lr}
	adds r3, r0, #0
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r1, r3, r2
	ldr r1, [r1]
	adds r1, #0x40
	ldrb r2, [r1]
	cmp r2, #1
	beq _080CEF8A
	cmp r2, #1
	bgt _080CEF7A
	cmp r2, #0
	beq _080CEF80
	b _080CEFAC
_080CEF7A:
	cmp r2, #2
	beq _080CEF94
	b _080CEFAC
_080CEF80:
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r1, r3, r4
	strb r2, [r1]
	b _080CEFB6
_080CEF8A:
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r1, r3, r4
	strb r2, [r1]
	b _080CEFB6
_080CEF94:
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r2, r3, r4
	movs r1, #5
	strb r1, [r2]
	movs r1, #0xac
	lsls r1, r1, #4
	adds r2, r3, r1
	ldr r1, _080CEFA8 @ =FUN_080d6ea0
	b _080CEFBE
	.align 2, 0
_080CEFA8: .4byte FUN_080d6ea0
_080CEFAC:
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r2, r3, r4
	movs r1, #0
	strb r1, [r2]
_080CEFB6:
	movs r1, #0xac
	lsls r1, r1, #4
	adds r2, r3, r1
	ldr r1, _080CEFC8 @ =FUN_080d6b24
_080CEFBE:
	str r1, [r2]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080CEFC8: .4byte FUN_080d6b24

	thumb_func_start FUN_080cefcc
FUN_080cefcc: @ 0x080CEFCC
	push {r4, lr}
	sub sp, #0x14
	adds r4, r0, #0
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	adds r0, #0x41
	ldrb r0, [r0]
	add r2, sp, #8
	add r3, sp, #0xc
	add r1, sp, #0x10
	str r1, [sp]
	add r1, sp, #4
	bl FUN_081dfa20
	ldr r1, [sp, #8]
	movs r2, #0xd7
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r1, [sp, #0xc]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r1, [sp, #4]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, [sp, #0x10]
	ldr r1, _080CF018 @ =0x00000362
	adds r4, r4, r1
	strh r0, [r4]
	add sp, #0x14
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CF018: .4byte 0x00000362

	thumb_func_start FUN_080cf01c
FUN_080cf01c: @ 0x080CF01C
	movs r2, #0xd7
	lsls r2, r2, #2
	adds r1, r0, r2
	ldrh r2, [r1]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r3, _080CF03C @ =0x00000366
	adds r2, r0, r3
	strh r1, [r2]
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r0, r0, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_080CF03C: .4byte 0x00000366

	thumb_func_start FUN_080cf040
FUN_080cf040: @ 0x080CF040
	ldr r2, _080CF05C @ =0x0000035E
	adds r1, r0, r2
	ldrh r2, [r1]
	lsls r1, r2, #2
	adds r1, r1, r2
	adds r1, #0x64
	ldr r3, _080CF060 @ =0x0000036A
	adds r2, r0, r3
	strh r1, [r2]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r0, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_080CF05C: .4byte 0x0000035E
_080CF060: .4byte 0x0000036A

	thumb_func_start FUN_080cf064
FUN_080cf064: @ 0x080CF064
	push {r4, lr}
	adds r3, r0, #0
	movs r0, #0xa3
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r3, #0x18]
	lsls r0, r0, #3
	ldr r1, _080CF0A8 @ =0x030044E0
	adds r0, r0, r1
	str r0, [r2]
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r0, [r0]
	ldrh r1, [r0, #0x14]
	ldr r2, _080CF0AC @ =0x00000456
	adds r0, r3, r2
	strb r1, [r0]
	ldr r0, _080CF0B0 @ =0x0000FFFF
	adds r4, r0, #0
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r2, r3, r1
	movs r1, #9
_080CF094:
	ldrh r0, [r2]
	orrs r0, r4
	strh r0, [r2]
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bge _080CF094
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CF0A8: .4byte 0x030044E0
_080CF0AC: .4byte 0x00000456
_080CF0B0: .4byte 0x0000FFFF

	thumb_func_start FUN_080cf0b4
FUN_080cf0b4: @ 0x080CF0B4
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_080cef30
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #1
	str r0, [r4, #0x1c]
	ldr r1, _080CF144 @ =0x030046A0
	ldr r0, [r1]
	movs r3, #0xb2
	lsls r3, r3, #2
	adds r0, r0, r3
	movs r5, #0
	str r5, [r0]
	ldr r2, [r1]
	adds r3, #4
	adds r0, r2, r3
	str r5, [r0]
	subs r3, #0x1c
	adds r0, r2, r3
	strh r5, [r0]
	ldr r0, [r1]
	ldr r1, _080CF148 @ =0x000002B2
	adds r0, r0, r1
	strh r5, [r0]
	adds r0, r4, #0
	bl FUN_080cef5c
	adds r0, r4, #0
	bl FUN_080cefcc
	adds r0, r4, #0
	bl FUN_080cf01c
	adds r0, r4, #0
	bl FUN_080cf040
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
	adds r0, r4, #0
	bl FUN_080cf064
	ldr r2, _080CF14C @ =0x00000442
	adds r0, r4, r2
	strh r5, [r0]
	ldr r3, _080CF150 @ =0x00000444
	adds r0, r4, r3
	strh r5, [r0]
	ldr r1, _080CF154 @ =0x00000446
	adds r0, r4, r1
	strh r5, [r0]
	ldr r1, [r4, #0x18]
	adds r2, #0x13
	adds r0, r4, r2
	strb r1, [r0]
	adds r3, #0x16
	adds r0, r4, r3
	strh r5, [r0]
	ldr r0, _080CF158 @ =0x0000045C
	adds r4, r4, r0
	str r5, [r4]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080CF144: .4byte 0x030046A0
_080CF148: .4byte 0x000002B2
_080CF14C: .4byte 0x00000442
_080CF150: .4byte 0x00000444
_080CF154: .4byte 0x00000446
_080CF158: .4byte 0x0000045C

	thumb_func_start FUN_080cf15c
FUN_080cf15c: @ 0x080CF15C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, _080CF1CC @ =0x0000CB05
	ldr r1, _080CF1D0 @ =0x0000DE23
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _080CF23E
	adds r1, r6, #0
	adds r1, #0x68
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r6, #0
	adds r4, #0x68
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	adds r5, r6, #0
	adds r5, #0x88
	movs r3, #0x90
	lsls r3, r3, #8
	movs r0, #2
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	adds r0, r6, #0
	adds r0, #0x2c
	str r0, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822f3fc
	movs r0, #0x64
	bl prepare_08231510
	adds r1, r0, #0
	adds r7, r4, #0
	cmp r1, #0
	beq _080CF1D8
	bl Script_GetValue
	ldr r2, _080CF1D4 @ =0x00000454
	adds r1, r6, r2
	strb r0, [r1]
	b _080CF1DE
	.align 2, 0
_080CF1CC: .4byte 0x0000CB05
_080CF1D0: .4byte 0x0000DE23
_080CF1D4: .4byte 0x00000454
_080CF1D8:
	ldr r3, _080CF224 @ =0x00000454
	adds r0, r6, r3
	strb r1, [r0]
_080CF1DE:
	ldr r4, _080CF224 @ =0x00000454
	adds r0, r6, r4
	ldrb r1, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r6, r2
	movs r4, #0
	strb r1, [r0]
	adds r0, r6, #0
	bl FUN_080cc1a0
	movs r3, #0xb9
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r4, [r0]
	ldr r1, _080CF228 @ =0x000002E6
	adds r0, r6, r1
	ldrb r2, [r0]
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r7, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r2, _080CF22C @ =0x000002E7
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CF230
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	b _080CF23C
	.align 2, 0
_080CF224: .4byte 0x00000454
_080CF228: .4byte 0x000002E6
_080CF22C: .4byte 0x000002E7
_080CF230:
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_080CF23C:
	str r1, [r0]
_080CF23E:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080cf248
FUN_080cf248: @ 0x080CF248
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r4, r7, r0
	ldr r1, _080CF2F8 @ =0x0000D495
	adds r0, r4, #0
	bl FUN_0822b16c
	ldr r0, _080CF2FC @ =0x0000922E
	ldr r1, _080CF300 @ =0x0000AF44
	bl GetFile
	mov r8, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r2, r8
	str r2, [r0]
	adds r6, r7, #0
	adds r6, #0xe8
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r7, r1
	str r4, [r0]
	movs r5, #0
	ldr r2, _080CF304 @ =0x00001001
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_0822a470
	ldrh r1, [r7, #0x2c]
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r0, [r7, #0x2e]
	adds r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	ldrh r1, [r7, #0x30]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	ldr r1, _080CF308 @ =0x000003F6
	adds r0, r7, r1
	strh r5, [r0]
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r4, r7, r2
	ldr r1, _080CF30C @ =0x000002E6
	adds r0, r7, r1
	ldrb r3, [r0]
	subs r2, #0x55
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _080CF310
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _080CF318
	.align 2, 0
_080CF2F8: .4byte 0x0000D495
_080CF2FC: .4byte 0x0000922E
_080CF300: .4byte 0x0000AF44
_080CF304: .4byte 0x00001001
_080CF308: .4byte 0x000003F6
_080CF30C: .4byte 0x000002E6
_080CF310:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080CF318:
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
	beq _080CF33C
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _080CF344
_080CF33C:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080CF344:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080CF37C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080CF3B4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080CF380
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080CF374
	ldrb r0, [r4, #5]
_080CF374:
	subs r0, #1
	strh r0, [r4, #8]
	b _080CF390
	.align 2, 0
_080CF37C: .4byte 0x0000FFFF
_080CF380:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080CF390
	strh r1, [r4, #8]
_080CF390:
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
	bne _080CF3B4
	movs r0, #1
	strb r0, [r4, #7]
_080CF3B4:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cf3c0
FUN_080cf3c0: @ 0x080CF3C0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	adds r6, r1, #0
	movs r0, #0x70
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080CF400
	bl Script_GetValue
	ldr r2, _080CF3F8 @ =0x0000044C
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _080CF3FC @ =0x0000044E
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0x8a
	lsls r2, r2, #3
	adds r1, r7, r2
	strh r0, [r1]
	b _080CF412
	.align 2, 0
_080CF3F8: .4byte 0x0000044C
_080CF3FC: .4byte 0x0000044E
_080CF400:
	ldr r2, _080CF440 @ =0x0000044C
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
_080CF412:
	ldr r0, _080CF440 @ =0x0000044C
	adds r5, r7, r0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080CF43A
	cmp r1, #0
	blt _080CF43A
	ldr r0, _080CF444 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080CF43A
	ldr r0, _080CF448 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080CF44C
_080CF43A:
	movs r4, #0
	b _080CF45A
	.align 2, 0
_080CF440: .4byte 0x0000044C
_080CF444: .4byte 0x030046A8
_080CF448: .4byte 0x030046AC
_080CF44C:
	ldr r0, _080CF46C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080CF45A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080CF470
	adds r0, #4
	b _080CF47C
	.align 2, 0
_080CF46C: .4byte 0x030046A4
_080CF470:
	ldr r0, _080CF490 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080CF47C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080CF494
	cmp r2, #2
	beq _080CF498
	b _080CF49C
	.align 2, 0
_080CF490: .4byte 0x030046A4
_080CF494:
	ldrb r0, [r5, #4]
	b _080CF49A
_080CF498:
	ldrb r0, [r5]
_080CF49A:
	subs r1, r1, r0
_080CF49C:
	ldr r2, _080CF538 @ =0x0000044E
	adds r0, r7, r2
	movs r4, #0
	strh r1, [r0]
	adds r5, r7, #0
	adds r5, #0x24
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080CF53C @ =0x0000044C
	adds r6, r7, r0
	ldrb r0, [r7, #0x18]
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	adds r2, r6, #0
	movs r3, #0
	bl FUN_0823b400
	adds r0, r7, #0
	bl FUN_080cf15c
	adds r0, r7, #0
	bl FUN_080cf248
	ldr r1, _080CF540 @ =0x00000359
	adds r0, r7, r1
	strb r4, [r0]
	adds r1, r7, #0
	adds r1, #0x88
	adds r0, r5, #0
	bl FUN_0823b474
	movs r2, #0xde
	lsls r2, r2, #1
	adds r4, r7, r2
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_0823280c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x1e
	movs r3, #0x1e
	bl FUN_0823b43c
	ldr r1, _080CF544 @ =0xFFFF0000
	movs r0, #0x96
	lsls r0, r0, #0x11
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
	adds r0, r5, #0
	add r1, sp, #8
	bl FUN_0823b47c
	ldrh r1, [r7, #0x24]
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r7, r1
	adds r1, r5, #0
	movs r2, #2
	bl FUN_080f8c58
	ldr r2, _080CF548 @ =0x03002B68
	ldr r1, [r7, #0x18]
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r2, [r7, #0x24]
	strh r2, [r1]
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080CF538: .4byte 0x0000044E
_080CF53C: .4byte 0x0000044C
_080CF540: .4byte 0x00000359
_080CF544: .4byte 0xFFFF0000
_080CF548: .4byte 0x03002B68

	thumb_func_start FUN_080cf54c
FUN_080cf54c: @ 0x080CF54C
	push {lr}
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r1, r0, r2
	ldr r1, [r1]
	adds r1, #0x1c
	bl player_weapon_080ceafc
	pop {r0}
	bx r0

	thumb_func_start FUN_080cf560
FUN_080cf560: @ 0x080CF560
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r6, r5, r0
	ldr r2, _080CF5CC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x32
	orrs r0, r3
	ldr r1, _080CF5D0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xfe
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r4, sp, #0x14
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldrh r1, [r5, #0x24]
	ldr r2, _080CF5D4 @ =0x00004001
	ldr r3, [r5, #0x18]
	movs r0, #0x80
	lsls r0, r0, #9
	lsls r0, r3
	lsrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r4, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_0823646c
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CF5D8
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #1
	movs r3, #2
	bl FUN_08236514
	b _080CF5E4
	.align 2, 0
_080CF5CC: .4byte 0xFFFF0000
_080CF5D0: .4byte 0x0000FFFF
_080CF5D4: .4byte 0x00004001
_080CF5D8:
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #2
	movs r3, #1
	bl FUN_08236514
_080CF5E4:
	ldr r1, _080CF60C @ =FUN_080d787c
	adds r0, r6, #0
	adds r2, r5, #0
	bl FUN_0823651c
	movs r0, #0x82
	lsls r0, r0, #1
	adds r1, r5, r0
	adds r0, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r6, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CF60C: .4byte FUN_080d787c

	thumb_func_start FUN_080cf610
FUN_080cf610: @ 0x080CF610
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _080CF648 @ =0x08DAA7E8
	ldr r0, _080CF64C @ =0x00000266
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	ldrb r1, [r2, #2]
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CF654
	subs r2, #0xfc
	adds r0, r4, r2
	ldr r2, _080CF650 @ =0x00000362
	adds r1, r4, r2
	ldrh r1, [r1]
	movs r2, #1
	movs r3, #2
	bl FUN_08236514
	b _080CF668
	.align 2, 0
_080CF648: .4byte 0x08DAA7E8
_080CF64C: .4byte 0x00000266
_080CF650: .4byte 0x00000362
_080CF654:
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, _080CF67C @ =0x00000362
	adds r1, r4, r2
	ldrh r1, [r1]
	movs r2, #2
	movs r3, #1
	bl FUN_08236514
_080CF668:
	movs r0, #0xde
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r1, _080CF680 @ =0xF000000F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CF67C: .4byte 0x00000362
_080CF680: .4byte 0xF000000F

	thumb_func_start FUN_080cf684
FUN_080cf684: @ 0x080CF684
	push {r4, r5, lr}
	sub sp, #0x20
	adds r5, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080CF6D0
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r3, _080CF6C8 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	movs r2, #0x20
	orrs r0, r2
	ldr r1, _080CF6CC @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r3
	b _080CF702
	.align 2, 0
_080CF6C8: .4byte 0xFFFF0000
_080CF6CC: .4byte 0x0000FFFF
_080CF6D0:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r2, [sp, #0x18]
	asrs r1, r2, #0x10
	adds r1, #0x50
	lsls r1, r1, #0x10
	ldr r3, _080CF734 @ =0x0000FFFF
	adds r0, r3, #0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r4, _080CF738 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r4
	movs r2, #0x40
	orrs r0, r2
	ands r0, r3
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r4
_080CF702:
	orrs r0, r2
	str r0, [sp, #0x14]
	add r0, sp, #0x18
	movs r1, #0
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #1
	add r2, sp, #0x10
	movs r3, #0
	bl FUN_080ddcc8
	ldr r0, _080CF73C @ =0x00000376
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	add sp, #0x20
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CF734: .4byte 0x0000FFFF
_080CF738: .4byte 0xFFFF0000
_080CF73C: .4byte 0x00000376

	thumb_func_start FUN_080cf740
FUN_080cf740: @ 0x080CF740
	push {r4, r5, r6, lr}
	mov ip, r0
	ldr r0, _080CF784 @ =0x000003CA
	add r0, ip
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	movs r1, #0xf2
	lsls r1, r1, #2
	add r1, ip
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r6, r0, r2
	movs r4, #0xf3
	lsls r4, r4, #2
	add r4, ip
	movs r3, #0
	ldrsh r0, [r4, r3]
	subs r5, r0, r2
	subs r3, r5, r6
	movs r0, #0xc8
	lsls r0, r0, #2
	cmp r3, r0
	ble _080CF78C
	ldr r2, _080CF788 @ =0xFFFFFCE0
	adds r0, r3, r2
	asrs r2, r0, #1
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrh r0, [r4]
	subs r0, r0, r2
	b _080CF7A0
	.align 2, 0
_080CF784: .4byte 0x000003CA
_080CF788: .4byte 0xFFFFFCE0
_080CF78C:
	ldr r0, _080CF7F4 @ =0xFFFFFCE0
	cmp r3, r0
	bge _080CF7A2
	subs r0, r0, r3
	asrs r2, r0, #1
	ldrh r0, [r1]
	subs r0, r0, r2
	strh r0, [r1]
	ldrh r0, [r4]
	adds r0, r0, r2
_080CF7A0:
	strh r0, [r4]
_080CF7A2:
	adds r3, r5, r6
	movs r0, #0xc8
	lsls r0, r0, #2
	cmp r3, r0
	ble _080CF7CA
	ldr r1, _080CF7F4 @ =0xFFFFFCE0
	adds r0, r3, r1
	asrs r2, r0, #1
	movs r1, #0xf2
	lsls r1, r1, #2
	add r1, ip
	ldrh r0, [r1]
	subs r0, r0, r2
	strh r0, [r1]
	movs r1, #0xf3
	lsls r1, r1, #2
	add r1, ip
	ldrh r0, [r1]
	subs r0, r0, r2
	strh r0, [r1]
_080CF7CA:
	ldr r0, _080CF7F4 @ =0xFFFFFCE0
	cmp r3, r0
	bge _080CF7EC
	subs r0, r0, r3
	asrs r2, r0, #1
	movs r1, #0xf2
	lsls r1, r1, #2
	add r1, ip
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r1, #0xf3
	lsls r1, r1, #2
	add r1, ip
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_080CF7EC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CF7F4: .4byte 0xFFFFFCE0

	thumb_func_start FUN_080cf7f8
FUN_080cf7f8: @ 0x080CF7F8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080CF880 @ =0x000003CE
	adds r3, r4, r0
	movs r1, #0
	ldrsh r2, [r3, r1]
	cmp r2, #0
	bne _080CF842
	ldrh r1, [r4, #0x2c]
	movs r5, #0xf0
	lsls r5, r5, #2
	adds r0, r4, r5
	strh r1, [r0]
	ldrh r0, [r4, #0x2e]
	adds r0, #0x96
	adds r5, #2
	adds r1, r4, r5
	strh r0, [r1]
	ldrh r1, [r4, #0x30]
	adds r5, #2
	adds r0, r4, r5
	strh r1, [r0]
	movs r1, #0xf2
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r2, [r0]
	adds r5, #6
	adds r0, r4, r5
	strh r2, [r0]
	adds r1, #4
	adds r0, r4, r1
	strh r2, [r0]
	movs r0, #1
	strh r0, [r3]
	adds r0, r4, #0
	bl FUN_080cf740
_080CF842:
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r2, r4, r3
	movs r5, #0
	ldrsh r1, [r2, r5]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080CF8C8
	adds r0, r1, #0
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r2, _080CF884 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CF888
	asrs r3, r0, #0xc
	b _080CF88E
	.align 2, 0
_080CF880: .4byte 0x000003CE
_080CF884: .4byte 0x085B0A08
_080CF888:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080CF88E:
	movs r0, #0xf2
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, r0, r3
	strh r0, [r1]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CF8B0
	asrs r2, r0, #0xc
	b _080CF8B6
_080CF8B0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080CF8B6:
	movs r3, #0xf3
	lsls r3, r3, #2
	adds r1, r4, r3
	ldrh r0, [r1]
	subs r0, r0, r2
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080cf740
_080CF8C8:
	movs r5, #0xf2
	lsls r5, r5, #2
	adds r1, r4, r5
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne _080CF8E4
	movs r3, #0xf3
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	beq _080CF94A
_080CF8E4:
	ldr r2, _080CF934 @ =0x000003D1
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CF94A
	movs r3, #0
	ldrsh r0, [r1, r3]
	movs r5, #0xf3
	lsls r5, r5, #2
	adds r1, r4, r5
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r4, r3
	adds r2, r1, #0
	strb r1, [r0]
	cmp r2, #4
	bls _080CF93C
	movs r0, #8
	subs r0, r0, r2
	subs r5, #0xe6
	adds r1, r4, r5
	strb r0, [r1]
	ldr r0, _080CF938 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	b _080CF948
	.align 2, 0
_080CF934: .4byte 0x000003D1
_080CF938: .4byte 0x000002E7
_080CF93C:
	ldr r2, _080CF950 @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080CF954 @ =0x000002E7
	adds r1, r4, r3
	movs r0, #0
_080CF948:
	strb r0, [r1]
_080CF94A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CF950: .4byte 0x000002E6
_080CF954: .4byte 0x000002E7

	thumb_func_start FUN_080cf958
FUN_080cf958: @ 0x080CF958
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r1, _080CF9B8 @ =0x000003CE
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _080CFA18
	ldrh r1, [r3, #0x2c]
	movs r5, #0xf0
	lsls r5, r5, #2
	adds r0, r3, r5
	strh r1, [r0]
	ldrh r0, [r3, #0x2e]
	adds r0, #0x96
	ldr r2, _080CF9BC @ =0x000003C2
	adds r1, r3, r2
	strh r0, [r1]
	ldrh r1, [r3, #0x30]
	adds r5, #4
	adds r0, r3, r5
	strh r1, [r0]
	ldr r1, _080CF9C0 @ =0x000003BD
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldr r2, _080CF9C4 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r5, r2, #0
	cmp r0, #0
	blt _080CF9C8
	asrs r0, r0, #0xc
	b _080CF9CE
	.align 2, 0
_080CF9B8: .4byte 0x000003CE
_080CF9BC: .4byte 0x000003C2
_080CF9C0: .4byte 0x000003BD
_080CF9C4: .4byte 0x085B0A08
_080CF9C8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CF9CE:
	rsbs r1, r0, #0
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r0, r3, r2
	movs r2, #0
	strh r1, [r0]
	ldr r1, _080CF9FC @ =0x000003CA
	adds r0, r3, r1
	strh r2, [r0]
	lsls r0, r4, #1
	adds r0, r0, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	cmp r0, #0
	blt _080CFA00
	asrs r0, r0, #0xc
	b _080CFA06
	.align 2, 0
_080CF9FC: .4byte 0x000003CA
_080CFA00:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CFA06:
	rsbs r1, r0, #0
	movs r5, #0xf3
	lsls r5, r5, #2
	adds r0, r3, r5
	strh r1, [r0]
	ldr r0, _080CFA20 @ =0x000003CE
	adds r1, r3, r0
	movs r0, #1
	strh r0, [r1]
_080CFA18:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CFA20: .4byte 0x000003CE

	thumb_func_start FUN_080cfa24
FUN_080cfa24: @ 0x080CFA24
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080CFA38 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CFA3C
	movs r1, #1
	rsbs r1, r1, #0
	b _080CFA40
	.align 2, 0
_080CFA38: .4byte 0x03002C68
_080CFA3C:
	movs r2, #0x18
	ldrsh r1, [r0, r2]
_080CFA40:
	ldr r0, [r4, #0x18]
	cmp r0, r1
	bne _080CFA4C
	movs r0, #8
	bl FUN_0823bca8
_080CFA4C:
	ldr r0, _080CFA5C @ =0x000003CE
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CFA5C: .4byte 0x000003CE

	thumb_func_start FUN_080cfa60
FUN_080cfa60: @ 0x080CFA60
	push {lr}
	adds r2, r0, #0
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #1
	bls _080CFA74
	cmp r0, #5
	bne _080CFA92
_080CFA74:
	cmp r1, #0
	beq _080CFA9A
	cmp r1, #3
	beq _080CFA9A
	cmp r1, #6
	beq _080CFA9A
	cmp r1, #4
	bne _080CFA9E
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CFA9A
	b _080CFA9E
_080CFA92:
	cmp r1, #0
	beq _080CFA9A
	cmp r1, #4
	bne _080CFA9E
_080CFA9A:
	movs r0, #1
	b _080CFAA0
_080CFA9E:
	movs r0, #0
_080CFAA0:
	pop {r1}
	bx r1

	thumb_func_start FUN_080cfaa4
FUN_080cfaa4: @ 0x080CFAA4
	push {r4, lr}
	adds r4, r0, #0
	adds r2, r1, #0
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080CFAF6
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_080cfa60
	cmp r0, #0
	beq _080CFAF6
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bls _080CFADA
	cmp r0, #5
	bne _080CFAEE
_080CFADA:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _080CFAEE
	adds r0, r4, #0
	bl FUN_080cf958
	b _080CFB08
_080CFAEE:
	adds r0, r4, #0
	bl FUN_080cf7f8
	b _080CFB08
_080CFAF6:
	ldr r1, _080CFB18 @ =0x000003CE
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _080CFB08
	adds r0, r4, #0
	bl FUN_080cfa24
_080CFB08:
	ldr r0, _080CFB1C @ =0x000003D1
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CFB18: .4byte 0x000003CE
_080CFB1C: .4byte 0x000003D1

	thumb_func_start FUN_080cfb20
FUN_080cfb20: @ 0x080CFB20
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x2c
	ldrsh r0, [r5, r1]
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r4, r5, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #5
	bl Div
	strh r0, [r4]
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	ldr r2, _080CFBA8 @ =0x000003CA
	adds r1, r5, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	ldr r1, _080CFBAC @ =0x000003C2
	adds r4, r5, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	lsls r1, r1, #2
	adds r1, #0x96
	adds r0, r0, r1
	movs r1, #5
	bl Div
	strh r0, [r4]
	movs r1, #0x30
	ldrsh r0, [r5, r1]
	movs r2, #0xf3
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	movs r1, #0xf1
	lsls r1, r1, #2
	adds r4, r5, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #5
	bl Div
	strh r0, [r4]
	adds r0, r5, #0
	adds r0, #0x28
	ldrb r1, [r0]
	ldr r0, _080CFBB0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CFBB4
	movs r0, #1
	rsbs r0, r0, #0
	b _080CFBB8
	.align 2, 0
_080CFBA8: .4byte 0x000003CA
_080CFBAC: .4byte 0x000003C2
_080CFBB0: .4byte 0x03002C68
_080CFBB4:
	movs r2, #0x18
	ldrsh r0, [r0, r2]
_080CFBB8:
	cmp r1, r0
	bne _080CFBC6
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r5, r1
	bl FUN_0823bac8
_080CFBC6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cfbcc
FUN_080cfbcc: @ 0x080CFBCC
	push {lr}
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq _080CFBFE
	movs r1, #0x18
	ldr r0, _080CFBEC @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080CFBF0 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080CFBF4
	movs r0, #1
	b _080CFBF6
	.align 2, 0
_080CFBEC: .4byte 0x030046A0
_080CFBF0: .4byte 0x00000934
_080CFBF4:
	movs r0, #0
_080CFBF6:
	cmp r0, #0
	bne _080CFBFE
	movs r0, #1
	b _080CFC00
_080CFBFE:
	movs r0, #0
_080CFC00:
	pop {r1}
	bx r1

	thumb_func_start FUN_080cfc04
FUN_080cfc04: @ 0x080CFC04
	push {lr}
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq _080CFC36
	movs r1, #0x10
	ldr r0, _080CFC24 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080CFC28 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080CFC2C
	movs r0, #1
	b _080CFC2E
	.align 2, 0
_080CFC24: .4byte 0x030046A0
_080CFC28: .4byte 0x00000934
_080CFC2C:
	movs r0, #0
_080CFC2E:
	cmp r0, #0
	beq _080CFC36
	movs r0, #1
	b _080CFC38
_080CFC36:
	movs r0, #0
_080CFC38:
	pop {r1}
	bx r1

	thumb_func_start FUN_080cfc3c
FUN_080cfc3c: @ 0x080CFC3C
	push {lr}
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq _080CFC72
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r0, _080CFC60 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080CFC64 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080CFC68
	movs r0, #1
	b _080CFC6A
	.align 2, 0
_080CFC60: .4byte 0x030046A0
_080CFC64: .4byte 0x00000934
_080CFC68:
	movs r0, #0
_080CFC6A:
	cmp r0, #0
	beq _080CFC72
	movs r0, #1
	b _080CFC74
_080CFC72:
	movs r0, #0
_080CFC74:
	pop {r1}
	bx r1

	thumb_func_start FUN_080cfc78
FUN_080cfc78: @ 0x080CFC78
	push {lr}
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq _080CFCAA
	movs r1, #8
	ldr r0, _080CFC98 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080CFC9C @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080CFCA0
	movs r0, #1
	b _080CFCA2
	.align 2, 0
_080CFC98: .4byte 0x030046A0
_080CFC9C: .4byte 0x00000934
_080CFCA0:
	movs r0, #0
_080CFCA2:
	cmp r0, #0
	beq _080CFCAA
	movs r0, #1
	b _080CFCAC
_080CFCAA:
	movs r0, #0
_080CFCAC:
	pop {r1}
	bx r1

	thumb_func_start FUN_080cfcb0
FUN_080cfcb0: @ 0x080CFCB0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrh r0, [r7, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080CFCD8
	cmp r1, #0
	blt _080CFCD8
	ldr r0, _080CFCDC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080CFCD8
	ldr r0, _080CFCE0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080CFCE4
_080CFCD8:
	movs r4, #0
	b _080CFCF2
	.align 2, 0
_080CFCDC: .4byte 0x030046A8
_080CFCE0: .4byte 0x030046AC
_080CFCE4:
	ldr r0, _080CFD04 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080CFCF2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080CFD08
	adds r0, #4
	b _080CFD14
	.align 2, 0
_080CFD04: .4byte 0x030046A4
_080CFD08:
	ldr r0, _080CFDA0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080CFD14:
	ldrh r0, [r0, #2]
	bl FUN_080cfc04
	cmp r0, #0
	beq _080CFDE4
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080CFDE4
	ldr r2, _080CFDA4 @ =0x00000395
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CFDE4
	adds r0, r7, #0
	adds r0, #0x2c
	bl FUN_081d2230
	cmp r0, #0
	bne _080CFDE4
	movs r5, #0xe0
	lsls r5, r5, #1
	adds r6, r7, r5
	ldrh r0, [r6]
	ldr r5, _080CFDA0 @ =0x030046A4
	ldr r1, [r5]
	ldr r1, [r1, #4]
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl Mod
	adds r4, r0, #0
	ldrh r0, [r6]
	ldr r1, [r5]
	ldr r1, [r1, #4]
	movs r5, #4
	ldrsh r1, [r1, r5]
	bl Div
	lsls r4, r4, #8
	adds r1, r4, #0
	adds r1, #0x80
	movs r2, #0xe7
	lsls r2, r2, #2
	adds r3, r7, r2
	strh r1, [r3]
	lsls r0, r0, #8
	adds r2, r0, #0
	adds r2, #0x80
	movs r5, #0xe8
	lsls r5, r5, #2
	adds r1, r7, r5
	strh r2, [r1]
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r1, r7, r2
	str r3, [r1]
	adds r2, r4, #1
	adds r4, #0xff
	adds r3, r0, #1
	adds r0, #0xff
	movs r5, #0x2c
	ldrsh r1, [r7, r5]
	cmp r1, r2
	bge _080CFDA8
	strh r2, [r7, #0x2c]
	b _080CFDAE
	.align 2, 0
_080CFDA0: .4byte 0x030046A4
_080CFDA4: .4byte 0x00000395
_080CFDA8:
	cmp r1, r4
	ble _080CFDAE
	strh r4, [r7, #0x2c]
_080CFDAE:
	movs r2, #0x30
	ldrsh r1, [r7, r2]
	cmp r1, r3
	bge _080CFDBA
	strh r3, [r7, #0x30]
	b _080CFDC0
_080CFDBA:
	cmp r1, r0
	ble _080CFDC0
	strh r0, [r7, #0x30]
_080CFDC0:
	movs r5, #0x82
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	adds r2, r7, #0
	adds r2, #0xa8
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0xe5
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
_080CFDE4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080cfdec
FUN_080cfdec: @ 0x080CFDEC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _080CFE74 @ =0x00000395
	adds r0, r4, r1
	movs r2, #0
	movs r6, #1
	strb r6, [r0]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r1, r4, r3
	movs r5, #0
	movs r0, #0x32
	strh r0, [r1]
	movs r1, #0x3c
	adds r3, #4
	adds r0, r4, r3
	strh r1, [r0]
	ldr r1, _080CFE78 @ =0x000003D2
	adds r0, r4, r1
	strb r5, [r0]
	ldr r3, _080CFE7C @ =0x000003F6
	adds r0, r4, r3
	strh r2, [r0]
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r1, r4, r2
	ldr r2, [r1]
	movs r3, #0
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r4, r3]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	lsls r1, r1, #1
	adds r1, #1
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	strb r1, [r2]
	lsls r0, r1, #0x18
	cmp r1, #4
	bls _080CFE88
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080CFE80 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _080CFE84 @ =0x000002E7
	adds r0, r4, r3
	strb r6, [r0]
	b _080CFE96
	.align 2, 0
_080CFE74: .4byte 0x00000395
_080CFE78: .4byte 0x000003D2
_080CFE7C: .4byte 0x000003F6
_080CFE80: .4byte 0x000002E6
_080CFE84: .4byte 0x000002E7
_080CFE88:
	lsrs r0, r0, #0x19
	ldr r2, _080CFEB0 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _080CFEB4 @ =0x000002E7
	adds r0, r4, r3
	strb r5, [r0]
_080CFE96:
	ldr r0, _080CFEB8 @ =0x000003D6
	adds r1, r4, r0
	movs r2, #0
	ldr r0, _080CFEBC @ =0x00000191
	strh r0, [r1]
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0x32
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080CFEB0: .4byte 0x000002E6
_080CFEB4: .4byte 0x000002E7
_080CFEB8: .4byte 0x000003D6
_080CFEBC: .4byte 0x00000191

	thumb_func_start FUN_080cfec0
FUN_080cfec0: @ 0x080CFEC0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080CFEEA
	cmp r1, #0
	blt _080CFEEA
	ldr r0, _080CFEF0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080CFEEA
	ldr r0, _080CFEF4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080CFEF8
_080CFEEA:
	movs r4, #0
	b _080CFF06
	.align 2, 0
_080CFEF0: .4byte 0x030046A8
_080CFEF4: .4byte 0x030046AC
_080CFEF8:
	ldr r0, _080CFF18 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080CFF06:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080CFF1C
	adds r0, #4
	b _080CFF28
	.align 2, 0
_080CFF18: .4byte 0x030046A4
_080CFF1C:
	ldr r0, _080CFF3C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080CFF28:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080CFF40
	cmp r2, #2
	beq _080CFF44
	b _080CFF48
	.align 2, 0
_080CFF3C: .4byte 0x030046A4
_080CFF40:
	ldrb r0, [r5, #4]
	b _080CFF46
_080CFF44:
	ldrb r0, [r5]
_080CFF46:
	subs r1, r1, r0
_080CFF48:
	movs r2, #0x2e
	ldrsh r0, [r6, r2]
	cmp r1, r0
	bne _080CFFC4
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080CFF74
	cmp r1, #0
	blt _080CFF74
	ldr r0, _080CFF78 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080CFF74
	ldr r0, _080CFF7C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080CFF80
_080CFF74:
	movs r4, #0
	b _080CFF8E
	.align 2, 0
_080CFF78: .4byte 0x030046A8
_080CFF7C: .4byte 0x030046AC
_080CFF80:
	ldr r0, _080CFFA0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080CFF8E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080CFFA4
	adds r0, #4
	b _080CFFB0
	.align 2, 0
_080CFFA0: .4byte 0x030046A4
_080CFFA4:
	ldr r0, _080CFFC0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080CFFB0:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080CFFC4
	movs r0, #0
	b _080CFFC6
	.align 2, 0
_080CFFC0: .4byte 0x030046A4
_080CFFC4:
	movs r0, #1
_080CFFC6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080cffcc
FUN_080cffcc: @ 0x080CFFCC
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r1, _080CFFE8 @ =0x000003A7
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080D0084
	cmp r0, #2
	bgt _080CFFEC
	cmp r0, #0
	beq _080CFFFA
	b _080D01BA
	.align 2, 0
_080CFFE8: .4byte 0x000003A7
_080CFFEC:
	cmp r0, #4
	bne _080CFFF2
	b _080D00EA
_080CFFF2:
	cmp r0, #6
	bne _080CFFF8
	b _080D0150
_080CFFF8:
	b _080D01BA
_080CFFFA:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x1e
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080D0080 @ =0xFFFF0000
	ldr r3, [sp]
	ands r3, r2
	orrs r3, r0
	str r3, [sp]
	mov r4, sp
	ldrh r0, [r4, #4]
	subs r0, #0x1e
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r2, r3
	orrs r2, r0
	str r2, [sp]
	adds r0, r5, #0
	mov r1, sp
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D00E6
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #4]
	subs r0, #0x64
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	beq _080D0060
	b _080D01B6
_080D0060:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	mov r1, sp
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D00E6
	b _080D01B6
	.align 2, 0
_080D0080: .4byte 0xFFFF0000
_080D0084:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x1e
	mov r1, sp
	strh r0, [r1]
	mov r4, sp
	ldrh r0, [r4, #4]
	subs r0, #0x1e
	strh r0, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D00E6
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #4]
	subs r0, #0x64
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D014C
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	mov r1, sp
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	beq _080D014C
_080D00E6:
	movs r0, #1
	b _080D01BE
_080D00EA:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x1e
	mov r1, sp
	strh r0, [r1]
	mov r4, sp
	ldrh r0, [r4, #4]
	adds r0, #0x1e
	strh r0, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D01B2
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #4]
	adds r0, #0x64
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D014C
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	mov r1, sp
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D01B2
_080D014C:
	movs r0, #3
	b _080D01BE
_080D0150:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x1e
	mov r1, sp
	strh r0, [r1]
	mov r4, sp
	ldrh r0, [r4, #4]
	adds r0, #0x1e
	strh r0, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D01B2
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #4]
	adds r0, #0x64
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D01B6
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	mov r1, sp
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	beq _080D01B6
_080D01B2:
	movs r0, #5
	b _080D01BE
_080D01B6:
	movs r0, #7
	b _080D01BE
_080D01BA:
	movs r0, #1
	rsbs r0, r0, #0
_080D01BE:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d01c8
FUN_080d01c8: @ 0x080D01C8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r0, #0xe9
	lsls r0, r0, #2
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	bne _080D01DA
	b _080D02E2
_080D01DA:
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	bl FUN_080cfc78
	adds r1, r0, #0
	cmp r1, #0
	bne _080D0200
	ldr r2, _080D01F8 @ =0x000003A5
	adds r0, r5, r2
	strb r1, [r0]
	ldr r4, _080D01FC @ =0x000003A6
	adds r0, r5, r4
	b _080D022C
	.align 2, 0
_080D01F8: .4byte 0x000003A5
_080D01FC: .4byte 0x000003A6
_080D0200:
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r7, #1
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _080D02B0
	ldr r2, _080D0234 @ =0x000003A7
	adds r4, r5, r2
	ldrb r1, [r4]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _080D023C
	ldr r4, _080D0238 @ =0x000003A5
	adds r0, r5, r4
	movs r1, #0
	strb r1, [r0]
	subs r2, #1
	adds r0, r5, r2
_080D022C:
	strb r1, [r0]
	strb r1, [r6]
	b _080D038E
	.align 2, 0
_080D0234: .4byte 0x000003A7
_080D0238: .4byte 0x000003A5
_080D023C:
	adds r0, r5, #0
	bl FUN_080cffcc
	strb r0, [r4]
	ldrb r0, [r4]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D0270 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080D0274
	asrs r1, r0, #0xc
	b _080D027A
	.align 2, 0
_080D0270: .4byte 0x085B0A08
_080D0274:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D027A:
	movs r2, #0xea
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	ldr r1, _080D029C @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080D02A0
	asrs r1, r0, #0xc
	b _080D02A6
	.align 2, 0
_080D029C: .4byte 0x085B0A08
_080D02A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D02A6:
	movs r2, #0xeb
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	b _080D038E
_080D02B0:
	ldr r0, _080D02D0 @ =0x000003A5
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	bne _080D038E
	ldr r2, _080D02D4 @ =0x000003A6
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _080D02DC
	ldr r0, [r5, #0x18]
	ldr r1, _080D02D8 @ =0x00000335
	bl FUN_080cc3e4
	strb r7, [r4]
	b _080D038E
	.align 2, 0
_080D02D0: .4byte 0x000003A5
_080D02D4: .4byte 0x000003A6
_080D02D8: .4byte 0x00000335
_080D02DC:
	adds r0, #1
	strb r0, [r1]
	b _080D038E
_080D02E2:
	movs r4, #0xe5
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	bl FUN_080cfc78
	cmp r0, #0
	beq _080D038E
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080D0316
	cmp r1, #6
	bne _080D038E
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	blt _080D038E
_080D0316:
	movs r0, #1
	strb r0, [r6]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _080D0354 @ =0x000003A7
	adds r0, r5, r2
	strb r1, [r0]
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D0358 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080D035C
	asrs r1, r0, #0xc
	b _080D0362
	.align 2, 0
_080D0354: .4byte 0x000003A7
_080D0358: .4byte 0x085B0A08
_080D035C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D0362:
	movs r4, #0xea
	lsls r4, r4, #2
	adds r0, r5, r4
	strh r1, [r0]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080D0380
	asrs r2, r0, #0xc
	b _080D0386
_080D0380:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D0386:
	movs r4, #0xeb
	lsls r4, r4, #2
	adds r0, r5, r4
	strh r2, [r0]
_080D038E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d0394
FUN_080d0394: @ 0x080D0394
	push {r4, lr}
	movs r2, #0xf7
	lsls r2, r2, #2
	adds r4, r0, r2
	adds r1, #2
	ldrh r2, [r4]
	adds r1, r1, r2
	strh r1, [r4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x63
	bls _080D03B6
	bl FUN_080cf684
	ldrh r0, [r4]
	subs r0, #0x64
	strh r0, [r4]
_080D03B6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d03bc
FUN_080d03bc: @ 0x080D03BC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r5, [sp, #0x1c]
	ldr r6, [sp, #0x24]
	movs r7, #0
	ldrsh r0, [r1, r7]
	movs r7, #4
	ldrsh r1, [r1, r7]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r3, [sp]
	ldrh r3, [r4, #0x24]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_08240cf0
	cmp r5, #0
	beq _080D03F8
	ldr r0, [r4, #0x18]
	adds r1, r5, #0
	bl FUN_0801a0a0
	adds r0, r4, #0
	adds r1, r5, #0
	ldr r2, [sp, #0x20]
	bl FUN_080cc6b0
_080D03F8:
	cmp r6, #0
	beq _080D0404
	ldr r0, [r4, #0x18]
	adds r1, r6, #0
	bl FUN_080cc3e4
_080D0404:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d040c
FUN_080d040c: @ 0x080D040C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #3
	bne _080D044A
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	movs r3, #0xac
	lsls r3, r3, #4
	adds r1, r4, r3
	ldr r0, _080D0478 @ =FUN_080d6b24
	str r0, [r1]
	ldr r1, _080D047C @ =0x00000359
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	adds r0, #0x88
	str r0, [r4, #0x50]
	str r2, [r4, #0x4c]
	ldr r2, _080D0480 @ =0x000004CC
	adds r1, r4, r2
	adds r0, #0x20
	str r0, [r1]
	ldr r3, _080D0484 @ =0x0000094C
	adds r1, r4, r3
	ldr r0, _080D0488 @ =0x0000FFFF
	strh r0, [r1]
_080D044A:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D0494
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080D048C @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _080D0490 @ =0x000002E7
	adds r1, r4, r3
	movs r0, #1
	b _080D04A2
	.align 2, 0
_080D0478: .4byte FUN_080d6b24
_080D047C: .4byte 0x00000359
_080D0480: .4byte 0x000004CC
_080D0484: .4byte 0x0000094C
_080D0488: .4byte 0x0000FFFF
_080D048C: .4byte 0x000002E6
_080D0490: .4byte 0x000002E7
_080D0494:
	lsrs r1, r1, #0x19
	ldr r2, _080D0570 @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080D0574 @ =0x000002E7
	adds r1, r4, r3
	movs r0, #0
_080D04A2:
	strb r0, [r1]
	movs r0, #8
	str r0, [r4, #0x1c]
	ldr r1, _080D0578 @ =0x0000037D
	adds r0, r4, r1
	movs r5, #0
	strb r5, [r0]
	ldr r2, _080D057C @ =0x0000037E
	adds r0, r4, r2
	movs r6, #0
	strh r5, [r0]
	movs r3, #0xd8
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r5, [r0]
	subs r1, #0xfa
	adds r0, r4, r1
	strb r6, [r0]
	adds r0, r4, #0
	bl FUN_080cdda8
	adds r0, r4, #0
	bl FUN_080cc43c
	ldr r2, _080D0580 @ =0x000003CE
	adds r0, r4, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	beq _080D04E4
	adds r0, r4, #0
	bl FUN_080cfa24
_080D04E4:
	ldr r1, _080D0584 @ =0x00000442
	adds r0, r4, r1
	strh r5, [r0]
	ldr r2, _080D0588 @ =0x00000444
	adds r0, r4, r2
	strh r5, [r0]
	ldr r3, _080D058C @ =0x00000446
	adds r0, r4, r3
	strh r5, [r0]
	subs r1, #0x51
	adds r0, r4, r1
	strb r6, [r0]
	subs r2, #0xa0
	adds r0, r4, r2
	strb r6, [r0]
	movs r2, #0
	movs r1, #2
	subs r3, #6
	adds r0, r4, r3
_080D050A:
	strh r2, [r0]
	subs r0, #2
	subs r1, #1
	cmp r1, #0
	bge _080D050A
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #0x14]
	ldr r2, _080D0590 @ =0x00000456
	adds r0, r4, r2
	strb r1, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #5
	beq _080D054C
	ldr r0, _080D0594 @ =0x00000455
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	blt _080D0548
	adds r0, r4, #0
	adds r0, #0x2c
	movs r1, #0
	ldrsb r1, [r5, r1]
	bl FUN_081df9ac
_080D0548:
	movs r0, #0xff
	strb r0, [r5]
_080D054C:
	ldr r0, [r4, #0x18]
	bl FUN_081df7e8
	ldr r1, _080D0598 @ =0x0000045A
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _080D05DC
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D059C
	movs r0, #0
	bl FUN_081df7bc
	b _080D05CA
	.align 2, 0
_080D0570: .4byte 0x000002E6
_080D0574: .4byte 0x000002E7
_080D0578: .4byte 0x0000037D
_080D057C: .4byte 0x0000037E
_080D0580: .4byte 0x000003CE
_080D0584: .4byte 0x00000442
_080D0588: .4byte 0x00000444
_080D058C: .4byte 0x00000446
_080D0590: .4byte 0x00000456
_080D0594: .4byte 0x00000455
_080D0598: .4byte 0x0000045A
_080D059C:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D05AC
	movs r0, #1
	bl FUN_081df7bc
	b _080D05CA
_080D05AC:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080D05BC
	movs r0, #2
	bl FUN_081df7bc
	b _080D05CA
_080D05BC:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080D05CA
	movs r0, #3
	bl FUN_081df7bc
_080D05CA:
	ldr r2, _080D05E4 @ =0x0000045A
	adds r0, r4, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r2, #2
	adds r1, r4, r2
	ldr r1, [r1]
	bl FUN_080ce544
_080D05DC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D05E4: .4byte 0x0000045A

	thumb_func_start FUN_080d05e8
FUN_080d05e8: @ 0x080D05E8
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
	bl FUN_0823280c
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
	bl FUN_080cc1a0
	ldrb r0, [r6]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
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

	thumb_func_start FUN_080d06d4
FUN_080d06d4: @ 0x080D06D4
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldr r0, _080D06F4 @ =0x00000292
	add r0, ip
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r2, r1
	beq _080D0728
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _080D06F8
_080D06F0:
	adds r0, r2, #0
	b _080D0730
	.align 2, 0
_080D06F4: .4byte 0x00000292
_080D06F8:
	adds r4, r2, #1
	movs r0, #7
	ands r4, r0
	adds r3, r2, #7
	ands r3, r0
	movs r5, #2
	adds r6, r1, #0
	movs r1, #0xa5
	lsls r1, r1, #2
	add r1, ip
_080D070C:
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, r6
	beq _080D0720
	cmp r0, r4
	beq _080D0730
	cmp r0, r3
	beq _080D0730
	cmp r0, r2
	bne _080D06F0
_080D0720:
	adds r1, #2
	adds r5, #1
	cmp r5, #9
	ble _080D070C
_080D0728:
	movs r0, #0xba
	lsls r0, r0, #2
	add r0, ip
	ldrb r0, [r0]
_080D0730:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d0738
FUN_080d0738: @ 0x080D0738
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D0766
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
	adds r0, r4, #0
	bl FUN_080d06d4
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080cc1a0
_080D0766:
	ldr r0, [r4, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x20]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d0790
FUN_080d0790: @ 0x080D0790
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080D07D8 @ =0x00000446
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080D07AC
	ldr r2, _080D07DC @ =0x00000442
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #1
	bne _080D07AC
	movs r1, #1
_080D07AC:
	cmp r1, #0
	bne _080D07D4
	ldr r1, _080D07E0 @ =0x00000362
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	subs r0, #0x64
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x64
	bl Div
	adds r1, r0, #0
	cmp r1, #0x10
	ble _080D07E4
_080D07D4:
	movs r1, #0x10
	b _080D07EA
	.align 2, 0
_080D07D8: .4byte 0x00000446
_080D07DC: .4byte 0x00000442
_080D07E0: .4byte 0x00000362
_080D07E4:
	cmp r1, #8
	bgt _080D07EA
	movs r1, #9
_080D07EA:
	ldr r2, _080D0814 @ =0x000004C5
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #2
	bne _080D0800
	adds r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D0800
	subs r1, #4
_080D0800:
	ldr r0, _080D0818 @ =0x00000402
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _080D080C
	subs r1, r1, r0
_080D080C:
	cmp r1, #1
	ble _080D081C
	adds r0, r1, #0
	b _080D081E
	.align 2, 0
_080D0814: .4byte 0x000004C5
_080D0818: .4byte 0x00000402
_080D081C:
	movs r0, #2
_080D081E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080d0824
FUN_080d0824: @ 0x080D0824
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r2, r0, #0
	movs r0, #0xa4
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r3, #0
	ldrsh r4, [r1, r3]
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	bne _080D087E
	adds r5, r4, #1
	movs r0, #7
	ands r5, r0
	mov sb, r5
	adds r3, r4, #7
	ands r3, r0
	movs r6, #1
	mov r8, r1
	movs r7, #1
	rsbs r7, r7, #0
	mov ip, r7
	ldr r0, _080D088C @ =0x00000292
	adds r1, r2, r0
_080D085A:
	movs r5, #0
	ldrsh r2, [r1, r5]
	cmp r2, ip
	beq _080D0876
	adds r0, r2, #0
	cmp r0, sb
	beq _080D0880
	cmp r0, r3
	beq _080D0880
	mov r5, r8
	movs r7, #0
	ldrsh r0, [r5, r7]
	cmp r2, r0
	bne _080D087E
_080D0876:
	adds r1, #2
	adds r6, #1
	cmp r6, #4
	ble _080D085A
_080D087E:
	adds r0, r4, #0
_080D0880:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080D088C: .4byte 0x00000292

	thumb_func_start FUN_080d0890
FUN_080d0890: @ 0x080D0890
	push {lr}
	adds r1, r0, #0
	cmp r1, #0xc
	bne _080D089C
	movs r0, #0x40
	b _080D08B2
_080D089C:
	cmp r1, #0xb
	ble _080D08AA
	subs r1, #0xc
	lsls r1, r1, #2
	movs r0, #0x40
	subs r0, r0, r1
	b _080D08B2
_080D08AA:
	movs r0, #0xc
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x40
_080D08B2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d08b8
FUN_080d08b8: @ 0x080D08B8
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	adds r0, #0x9c
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _080D08CE
	b _080D09F8
_080D08CE:
	adds r0, r4, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D08DA
	b _080D09F8
_080D08DA:
	ldr r1, _080D093C @ =0x00000446
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0
	adds r5, r0, #0
	cmp r1, #0
	beq _080D08F4
	ldr r1, _080D0940 @ =0x00000442
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D08F4
	movs r2, #1
_080D08F4:
	cmp r2, #0
	beq _080D08FA
	b _080D09F8
_080D08FA:
	movs r2, #0xe5
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	bl FUN_080cfbcc
	cmp r0, #0
	beq _080D0960
	ldrh r0, [r5]
	movs r2, #0
	cmp r0, #0
	beq _080D091E
	ldr r1, _080D0940 @ =0x00000442
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D091E
	movs r2, #1
_080D091E:
	cmp r2, #0
	bne _080D0960
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D0944
	adds r1, r4, #0
	adds r1, #0x2c
	str r1, [sp]
	str r2, [sp, #4]
	movs r0, #0xca
	lsls r0, r0, #1
	b _080D094E
	.align 2, 0
_080D093C: .4byte 0x00000446
_080D0940: .4byte 0x00000442
_080D0944:
	adds r1, r4, #0
	adds r1, #0x2c
	str r1, [sp]
	str r2, [sp, #4]
	ldr r0, _080D095C @ =0x00000193
_080D094E:
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #1
	bl FUN_080d03bc
	b _080D09F8
	.align 2, 0
_080D095C: .4byte 0x00000193
_080D0960:
	cmp r6, #0
	bne _080D09F8
	ldrh r0, [r5]
	movs r1, #0
	cmp r0, #0
	beq _080D0978
	ldr r2, _080D0990 @ =0x00000442
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D0978
	movs r1, #1
_080D0978:
	cmp r1, #0
	beq _080D099E
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D0994
	ldr r0, [r4, #0x18]
	movs r1, #0xc8
	bl FUN_080cc3e4
	b _080D09F8
	.align 2, 0
_080D0990: .4byte 0x00000442
_080D0994:
	ldr r0, [r4, #0x18]
	movs r1, #0xc7
	bl FUN_080cc3e4
	b _080D09F8
_080D099E:
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D09B4
	ldr r2, _080D09C8 @ =0x000001C7
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D09D6
_080D09B4:
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D09CC
	ldr r0, [r4, #0x18]
	movs r1, #0xca
	bl FUN_080cc3e4
	b _080D09F8
	.align 2, 0
_080D09C8: .4byte 0x000001C7
_080D09CC:
	ldr r0, [r4, #0x18]
	movs r1, #0xc9
	bl FUN_080cc3e4
	b _080D09F8
_080D09D6:
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D09F0
	ldr r0, [r4, #0x18]
	ldr r1, _080D09EC @ =0x0000028E
	bl FUN_080cc3e4
	b _080D09F8
	.align 2, 0
_080D09EC: .4byte 0x0000028E
_080D09F0:
	ldr r0, [r4, #0x18]
	ldr r1, _080D0A00 @ =0x0000028D
	bl FUN_080cc3e4
_080D09F8:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D0A00: .4byte 0x0000028D

	thumb_func_start FUN_080d0a04
FUN_080d0a04: @ 0x080D0A04
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0xdf
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r4, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x20]
	adds r0, r4, #0
	bl FUN_080d0824
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D0A70
	adds r0, r4, #0
	bl FUN_080d0790
	adds r5, r0, #0
	bl FUN_080d0890
	ldr r2, _080D0A9C @ =0x00000446
	adds r0, r4, r2
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080D0A5A
	subs r2, #4
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D0A5A
	movs r1, #1
_080D0A5A:
	cmp r1, #0
	beq _080D0A68
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	muls r0, r5, r0
	asrs r5, r0, #6
_080D0A68:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080cc268
_080D0A70:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080d08b8
	adds r0, r4, #0
	bl FUN_080cc1a0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #1
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D0A9C: .4byte 0x00000446

	thumb_func_start FUN_080d0aa0
FUN_080d0aa0: @ 0x080D0AA0
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080D0B30
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ced68
	cmp r0, #0
	beq _080D0B1C
	ldr r0, [r4, #0x18]
	ldr r1, _080D0AD4 @ =0x00000392
	bl FUN_080cc3e4
	ldr r1, [r4, #0x18]
	ldr r0, _080D0AD8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080D0ADC
	movs r0, #0
	b _080D0AE2
	.align 2, 0
_080D0AD4: .4byte 0x00000392
_080D0AD8: .4byte 0x03002C68
_080D0ADC:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_080D0AE2:
	lsls r0, r0, #1
	adds r0, #0xe
	movs r2, #0xff
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x20
	bls _080D0AFA
	movs r0, #0x20
	strb r0, [r1]
_080D0AFA:
	movs r0, #0x80
	lsls r0, r0, #2
	ldrb r1, [r1]
	bl Div
	ldr r3, _080D0B18 @ =0x000003FD
	adds r1, r4, r3
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_080cc348
	b _080D0B30
	.align 2, 0
_080D0B18: .4byte 0x000003FD
_080D0B1C:
	ldr r0, [r4, #0x18]
	movs r1, #0xc9
	lsls r1, r1, #1
	bl FUN_080cc3e4
	adds r0, r4, #0
	movs r1, #2
	movs r2, #1
	bl FUN_080cc348
_080D0B30:
	ldr r1, _080D0B40 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D0B44
	cmp r0, #1
	beq _080D0BF8
	b _080D0C2C
	.align 2, 0
_080D0B40: .4byte 0x0000037D
_080D0B44:
	ldr r3, _080D0B68 @ =0x0000037E
	adds r2, r4, r3
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	adds r3, #0x7f
	adds r1, r4, r3
	ldrb r3, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r3
	blo _080D0B6C
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
	b _080D0C2C
	.align 2, 0
_080D0B68: .4byte 0x0000037E
_080D0B6C:
	ldrh r1, [r2]
	adds r0, r3, #0
	subs r0, #8
	cmp r1, r0
	bge _080D0B88
	ldr r0, _080D0BEC @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _080D0BF0 @ =0x00000125
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #0x20
	strh r0, [r1]
_080D0B88:
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080D0BB4
	ldr r3, _080D0BF4 @ =0x000003CE
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _080D0BB4
	adds r0, r4, #0
	bl FUN_080d0824
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
_080D0BB4:
	movs r3, #0xff
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_080cc268
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080d08b8
	adds r0, r4, #0
	bl FUN_080cc1a0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #1
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x20
	bl FUN_080cc1e8
	b _080D0C2C
	.align 2, 0
_080D0BEC: .4byte 0x0000095E
_080D0BF0: .4byte 0x00000125
_080D0BF4: .4byte 0x000003CE
_080D0BF8:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r3, _080D0C34 @ =0x0000037E
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080D0C2C
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D0C2C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D0C34: .4byte 0x0000037E

	thumb_func_start FUN_080d0c38
FUN_080d0c38: @ 0x080D0C38
	push {lr}
	adds r1, r0, #0
	ldr r2, _080D0C50 @ =0x000003BD
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D0C4A
	cmp r0, #5
	bne _080D0C54
_080D0C4A:
	ldrh r1, [r1, #0x2c]
	b _080D0C56
	.align 2, 0
_080D0C50: .4byte 0x000003BD
_080D0C54:
	ldrh r1, [r1, #0x30]
_080D0C56:
	movs r0, #0xff
	ands r0, r1
	subs r0, #0x1f
	cmp r0, #0xc2
	bhi _080D0C64
	movs r0, #1
	b _080D0C66
_080D0C64:
	movs r0, #0
_080D0C66:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d0c6c
FUN_080d0c6c: @ 0x080D0C6C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r1, #4
	strb r1, [r0]
	ldr r2, _080D0CBC @ =0x0000037D
	adds r0, r7, r2
	ldrb r1, [r0]
	cmp r1, #1
	bne _080D0CA8
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r7, r3
	ldr r0, [r0]
	ldrh r0, [r0, #2]
	ands r1, r0
	cmp r1, #0
	beq _080D0CA8
	adds r0, r7, #0
	movs r1, #4
	movs r2, #2
	bl FUN_080cc348
_080D0CA8:
	ldr r1, _080D0CBC @ =0x0000037D
	adds r0, r7, r1
	ldrb r4, [r0]
	cmp r4, #1
	beq _080D0D68
	cmp r4, #1
	bgt _080D0CC0
	cmp r4, #0
	beq _080D0CC8
	b _080D12F4
	.align 2, 0
_080D0CBC: .4byte 0x0000037D
_080D0CC0:
	cmp r4, #2
	bne _080D0CC6
	b _080D117E
_080D0CC6:
	b _080D12F4
_080D0CC8:
	movs r1, #4
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r0, [r0]
	movs r1, #2
	bl FUN_08066ee4
	mov sb, r0
	movs r3, #0xb9
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r0, sb
	beq _080D0D42
	ldr r0, [r7, #0x18]
	movs r1, #0xd0
	bl FUN_080cc3e4
	ldr r0, _080D0D2C @ =0x000003BD
	adds r2, r7, r0
	ldrb r0, [r2]
	adds r0, #4
	movs r1, #7
	ands r0, r1
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r7, r3
	strb r0, [r1]
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D0D34
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080D0D30 @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	subs r3, #1
	adds r1, r7, r3
	movs r0, #1
	strb r0, [r1]
	b _080D0D42
	.align 2, 0
_080D0D2C: .4byte 0x000003BD
_080D0D30: .4byte 0x000002E6
_080D0D34:
	lsrs r0, r1, #0x19
	ldr r2, _080D0D60 @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	ldr r3, _080D0D64 @ =0x000002E7
	adds r0, r7, r3
	strb r4, [r0]
_080D0D42:
	adds r0, r7, #0
	mov r1, sb
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	bne _080D0D52
	b _080D12F4
_080D0D52:
	adds r0, r7, #0
	movs r1, #4
	movs r2, #1
	bl FUN_080cc348
	b _080D12F4
	.align 2, 0
_080D0D60: .4byte 0x000002E6
_080D0D64: .4byte 0x000002E7
_080D0D68:
	movs r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r7, r1
	strb r4, [r0]
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r3, #0
	ldrsh r6, [r0, r3]
	ldr r0, _080D0DEC @ =0x000003BD
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0]
	adds r4, r0, #7
	movs r2, #7
	ands r4, r2
	adds r5, r0, #1
	ands r5, r2
	subs r1, #0x64
	adds r0, r7, r1
	ldrb r0, [r0]
	movs r1, #3
	str r2, [sp, #0x1c]
	bl FUN_08066ee4
	mov sb, r0
	ldr r2, [sp, #0x1c]
	cmp r6, r4
	beq _080D0DB0
	cmp r6, r5
	beq _080D0DB0
	b _080D1144
_080D0DB0:
	mov r3, r8
	ldrb r1, [r3]
	subs r0, r6, r1
	lsls r0, r0, #1
	adds r0, #8
	adds r1, r1, r0
	ands r1, r2
	adds r6, r1, #1
	ands r6, r2
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r2, _080D0DF0 @ =0x085B0A08
	lsls r0, r6, #5
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x32
	muls r0, r1, r0
	mov r8, r2
	cmp r0, #0
	blt _080D0DF4
	asrs r2, r0, #0xc
	b _080D0DFA
	.align 2, 0
_080D0DEC: .4byte 0x000003BD
_080D0DF0: .4byte 0x085B0A08
_080D0DF4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D0DFA:
	add r0, sp, #0xc
	ldrh r1, [r0]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D0E2C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	lsls r2, r6, #5
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #1
	add r0, r8
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x32
	muls r0, r1, r0
	mov sl, r2
	cmp r0, #0
	blt _080D0E30
	asrs r0, r0, #0xc
	b _080D0E36
	.align 2, 0
_080D0E2C: .4byte 0xFFFF0000
_080D0E30:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D0E36:
	add r3, sp, #0xc
	ldrh r1, [r3, #4]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D0E74 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r0, r3, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D0E70
	cmp r1, #0
	blt _080D0E70
	ldr r0, _080D0E78 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D0E70
	ldr r0, _080D0E7C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D0E80
_080D0E70:
	movs r6, #0
	b _080D0E8E
	.align 2, 0
_080D0E74: .4byte 0xFFFF0000
_080D0E78: .4byte 0x030046A8
_080D0E7C: .4byte 0x030046AC
_080D0E80:
	ldr r0, _080D0EBC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_080D0E8E:
	add r5, sp, #0xc
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D0EB6
	cmp r1, #0
	blt _080D0EB6
	ldr r0, _080D0EC0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D0EB6
	ldr r0, _080D0EC4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D0EC8
_080D0EB6:
	movs r4, #0
	b _080D0ED6
	.align 2, 0
_080D0EBC: .4byte 0x030046A4
_080D0EC0: .4byte 0x030046A8
_080D0EC4: .4byte 0x030046AC
_080D0EC8:
	ldr r0, _080D0EE8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D0ED6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D0EEC
	adds r0, #4
	b _080D0EF8
	.align 2, 0
_080D0EE8: .4byte 0x030046A4
_080D0EEC:
	ldr r0, _080D0F0C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D0EF8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080D0F10
	cmp r2, #2
	beq _080D0F14
	b _080D0F18
	.align 2, 0
_080D0F0C: .4byte 0x030046A4
_080D0F10:
	ldrb r0, [r5, #4]
	b _080D0F16
_080D0F14:
	ldrb r0, [r5]
_080D0F16:
	subs r1, r1, r0
_080D0F18:
	adds r5, r1, #0
	movs r0, #0x2e
	ldrsh r1, [r7, r0]
	adds r0, r1, #0
	subs r0, #0x80
	cmp r5, r0
	bgt _080D0F28
	b _080D1144
_080D0F28:
	adds r0, r1, #0
	adds r0, #0x80
	cmp r5, r0
	blt _080D0F32
	b _080D1144
_080D0F32:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D0F42
	adds r0, #4
	b _080D0F4E
_080D0F42:
	ldr r0, _080D0F88 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D0F4E:
	ldrh r0, [r0, #2]
	bl FUN_080cfc78
	cmp r0, #0
	beq _080D0F5A
	b _080D1144
_080D0F5A:
	ldr r2, _080D0F8C @ =0x085B0A08
	ldr r1, _080D0F90 @ =0x000003BD
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x32
	muls r0, r1, r0
	mov r8, r2
	cmp r0, #0
	blt _080D0F94
	asrs r1, r0, #0xc
	b _080D0F9A
	.align 2, 0
_080D0F88: .4byte 0x030046A4
_080D0F8C: .4byte 0x085B0A08
_080D0F90: .4byte 0x000003BD
_080D0F94:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D0F9A:
	add r0, sp, #0xc
	ldrh r0, [r0]
	subs r0, r0, r1
	add r1, sp, #0xc
	strh r0, [r1]
	ldr r1, _080D0FC4 @ =0x000003BD
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #6
	add r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _080D0FC8
	asrs r2, r0, #0xc
	b _080D0FCE
	.align 2, 0
_080D0FC4: .4byte 0x000003BD
_080D0FC8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D0FCE:
	add r0, sp, #0xc
	ldrh r1, [r0, #4]
	subs r1, r1, r2
	strh r1, [r0, #4]
	adds r6, r0, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _080D0FFA
	cmp r1, #0
	blt _080D0FFA
	ldr r0, _080D1000 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D0FFA
	ldr r0, _080D1004 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D1008
_080D0FFA:
	movs r4, #0
	b _080D1016
	.align 2, 0
_080D1000: .4byte 0x030046A8
_080D1004: .4byte 0x030046AC
_080D1008:
	ldr r0, _080D1028 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D1016:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D102C
	adds r0, #4
	b _080D1038
	.align 2, 0
_080D1028: .4byte 0x030046A4
_080D102C:
	ldr r0, _080D104C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D1038:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080D1050
	cmp r2, #2
	beq _080D1054
	b _080D1058
	.align 2, 0
_080D104C: .4byte 0x030046A4
_080D1050:
	ldrb r0, [r6, #4]
	b _080D1056
_080D1054:
	ldrb r0, [r6]
_080D1056:
	subs r1, r1, r0
_080D1058:
	adds r0, r5, #0
	adds r0, #0xc8
	cmp r1, r0
	blt _080D1144
	add r1, sp, #0xc
	adds r0, r1, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D1088
	cmp r1, #0
	blt _080D1088
	ldr r0, _080D108C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D1088
	ldr r0, _080D1090 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D1094
_080D1088:
	movs r4, #0
	b _080D10A2
	.align 2, 0
_080D108C: .4byte 0x030046A8
_080D1090: .4byte 0x030046AC
_080D1094:
	ldr r0, _080D10B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D10A2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D10B8
	adds r0, #4
	b _080D10C4
	.align 2, 0
_080D10B4: .4byte 0x030046A4
_080D10B8:
	ldr r0, _080D1110 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D10C4:
	ldrh r0, [r0, #2]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080D1144
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrb r0, [r0]
	bl FUN_08066ee4
	mov sb, r0
	adds r0, r7, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _080D10F0
	movs r3, #3
	cmp r0, #2
	bne _080D10F0
	movs r3, #6
_080D10F0:
	ldr r2, _080D1114 @ =0x085B0A08
	mov r0, sl
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	mov r8, r2
	cmp r0, #0
	blt _080D1118
	asrs r0, r0, #0xc
	b _080D111E
	.align 2, 0
_080D1110: .4byte 0x030046A4
_080D1114: .4byte 0x085B0A08
_080D1118:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D111E:
	rsbs r0, r0, #0
	strh r0, [r7, #0x34]
	movs r0, #0xff
	mov r2, sl
	ands r0, r2
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D113A
	asrs r0, r0, #0xc
	b _080D1140
_080D113A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D1140:
	rsbs r0, r0, #0
	strh r0, [r7, #0x38]
_080D1144:
	adds r0, r7, #0
	mov r1, sb
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0x18
	beq _080D115C
	b _080D12F4
_080D115C:
	adds r0, r7, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D1168
	b _080D12F4
_080D1168:
	adds r0, r7, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #1
	beq _080D1174
	b _080D12F4
_080D1174:
	ldr r0, [r7, #0x18]
	movs r1, #0xdb
	bl FUN_080cc3e4
	b _080D12F4
_080D117E:
	movs r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrb r0, [r0]
	movs r1, #5
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	bne _080D11A4
	b _080D12F4
_080D11A4:
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r1, _080D11DC @ =0x000003BD
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D11E8
	add r3, sp, #0x14
	ldrh r0, [r3]
	adds r0, #0x1c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080D11E0 @ =0xFFFF0000
	ldr r2, [sp, #0x14]
	ands r2, r4
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x2c
	lsls r1, r1, #0x10
	ldr r0, _080D11E4 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
	ldrh r0, [r3, #4]
	subs r0, #0x4c
	b _080D1248
	.align 2, 0
_080D11DC: .4byte 0x000003BD
_080D11E0: .4byte 0xFFFF0000
_080D11E4: .4byte 0x0000FFFF
_080D11E8:
	cmp r0, #3
	bne _080D1220
	add r3, sp, #0x14
	ldrh r0, [r3]
	subs r0, #0x34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080D1218 @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r4
	orrs r1, r0
	lsrs r2, r1, #0x10
	lsls r2, r2, #0x10
	ldr r0, _080D121C @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x14]
	ldrh r1, [r3, #4]
	ldr r0, [r3, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r3, #4]
	adds r4, r3, #0
	b _080D1294
	.align 2, 0
_080D1218: .4byte 0xFFFF0000
_080D121C: .4byte 0x0000FFFF
_080D1220:
	cmp r0, #5
	bne _080D1260
	add r3, sp, #0x14
	ldrh r0, [r3]
	adds r0, #0xc
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080D1258 @ =0xFFFF0000
	ldr r2, [sp, #0x14]
	ands r2, r4
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x2c
	lsls r1, r1, #0x10
	ldr r0, _080D125C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
	ldrh r0, [r3, #4]
	subs r0, #0x20
_080D1248:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r3, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r3, #4]
	adds r4, r3, #0
	b _080D1294
	.align 2, 0
_080D1258: .4byte 0xFFFF0000
_080D125C: .4byte 0x0000FFFF
_080D1260:
	add r4, sp, #0x14
	cmp r0, #7
	bne _080D1294
	ldrh r0, [r4]
	subs r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _080D1304 @ =0xFFFF0000
	ldr r2, [sp, #0x14]
	ands r2, r3
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x44
	lsls r1, r1, #0x10
	ldr r0, _080D1308 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
	ldrh r0, [r4, #4]
	adds r0, #0x2c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r4, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r4, #4]
_080D1294:
	ldr r2, _080D130C @ =0x085B0A08
	ldr r3, _080D1310 @ =0x000003BD
	adds r0, r7, r3
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x32
	muls r0, r1, r0
	mov r8, r2
	ldr r1, _080D1310 @ =0x000003BD
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #6
	add r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	adds r1, r7, #0
	adds r1, #0x2c
	movs r2, #0x80
	lsls r2, r2, #1
	str r4, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0xec
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #1
	bl FUN_080d03bc
	adds r0, r7, #0
	movs r1, #4
	movs r2, #1
	bl FUN_080cc348
_080D12F4:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D1304: .4byte 0xFFFF0000
_080D1308: .4byte 0x0000FFFF
_080D130C: .4byte 0x085B0A08
_080D1310: .4byte 0x000003BD

	thumb_func_start FUN_080d1314
FUN_080d1314: @ 0x080D1314
	push {lr}
	adds r2, r0, #0
	movs r1, #0x10
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _080D133C
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r3, _080D1338 @ =0x0000036A
	adds r1, r2, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _080D133C
	movs r0, #1
	b _080D133E
	.align 2, 0
_080D1338: .4byte 0x0000036A
_080D133C:
	movs r0, #0
_080D133E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d1344
FUN_080d1344: @ 0x080D1344
	push {lr}
	adds r3, r0, #0
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r3, r0
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _080D138C
	ldrh r0, [r2]
	subs r0, #0x14
	strh r0, [r2]
	ldr r2, _080D1384 @ =0x00000932
	adds r1, r3, r2
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _080D1388 @ =0x00000934
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, #0x3c
	b _080D13AA
	.align 2, 0
_080D1384: .4byte 0x00000932
_080D1388: .4byte 0x00000934
_080D138C:
	ldrh r0, [r2]
	adds r0, #0x14
	strh r0, [r2]
	ldr r2, _080D13B0 @ =0x00000932
	adds r1, r3, r2
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _080D13B4 @ =0x00000934
	adds r1, r3, r0
	ldrh r0, [r1]
	subs r0, #0x1e
_080D13AA:
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080D13B0: .4byte 0x00000932
_080D13B4: .4byte 0x00000934

	thumb_func_start FUN_080d13b8
FUN_080d13b8: @ 0x080D13B8
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #7
	beq _080D13DA
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl FUN_080cc348
	ldr r2, _080D13F0 @ =0x00000951
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_080D13DA:
	ldr r1, _080D13F4 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _080D13E6
	b _080D169A
_080D13E6:
	lsls r0, r0, #2
	ldr r1, _080D13F8 @ =_080D13FC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D13F0: .4byte 0x00000951
_080D13F4: .4byte 0x0000037D
_080D13F8: .4byte _080D13FC
_080D13FC: @ jump table
	.4byte _080D1410 @ case 0
	.4byte _080D1434 @ case 1
	.4byte _080D150C @ case 2
	.4byte _080D15D4 @ case 3
	.4byte _080D1654 @ case 4
_080D1410:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	bl FUN_080cc348
	b _080D169A
_080D1434:
	ldr r1, _080D1460 @ =0x0000037E
	adds r0, r4, r1
	ldrh r2, [r0]
	cmp r2, #0
	bne _080D148A
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _080D146C
	movs r0, #4
	strb r0, [r1]
	ldr r0, _080D1464 @ =0x000002E6
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080D1468 @ =0x000002E7
	b _080D1476
	.align 2, 0
_080D1460: .4byte 0x0000037E
_080D1464: .4byte 0x000002E6
_080D1468: .4byte 0x000002E7
_080D146C:
	strb r2, [r1]
	ldr r1, _080D14F0 @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
_080D1476:
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_080d1344
	ldr r2, _080D14F4 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_080D148A:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #8
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	bne _080D14B2
	b _080D169A
_080D14B2:
	ldr r0, [r4, #0x18]
	movs r1, #0xcb
	bl FUN_080cc3e4
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D14CE
	b _080D1610
_080D14CE:
	adds r0, r4, #0
	bl FUN_080d1314
	adds r1, r0, #0
	cmp r1, #0
	beq _080D1500
	ldr r0, [r4, #0x18]
	movs r1, #0xd8
	bl FUN_080cc3e4
	ldr r0, _080D14F8 @ =0x00000409
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _080D14FC @ =0x00000404
	adds r1, r4, r2
	b _080D163A
	.align 2, 0
_080D14F0: .4byte 0x000002E6
_080D14F4: .4byte 0x0000037E
_080D14F8: .4byte 0x00000409
_080D14FC: .4byte 0x00000404
_080D1500:
	ldr r2, _080D1508 @ =0x00000404
	adds r0, r4, r2
	strh r1, [r0]
	b _080D15C4
	.align 2, 0
_080D1508: .4byte 0x00000404
_080D150C:
	movs r1, #0xa0
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	ldr r0, _080D1540 @ =0x00000404
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #4
	bhi _080D154E
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne _080D154E
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D1544
	ldr r0, [r4, #0x18]
	subs r1, #0x50
	bl FUN_080cc3e4
	b _080D154E
	.align 2, 0
_080D1540: .4byte 0x00000404
_080D1544:
	ldr r0, [r4, #0x18]
	movs r1, #0x94
	lsls r1, r1, #1
	bl FUN_080cc3e4
_080D154E:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #9
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r5, #0
	movs r0, #0x1e
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080d1344
	movs r2, #0x93
	lsls r2, r2, #4
	adds r1, r4, r2
	adds r0, r4, #0
	bl FUN_080cd230
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D15AC
	ldr r0, [r4, #0x18]
	movs r1, #0xd8
	bl FUN_080cc410
	ldr r2, _080D15A8 @ =0x00000409
	adds r0, r4, r2
	strb r5, [r0]
	b _080D1610
	.align 2, 0
_080D15A8: .4byte 0x00000409
_080D15AC:
	adds r0, r4, #0
	bl FUN_080d1314
	cmp r0, #0
	bne _080D169A
	ldr r0, [r4, #0x18]
	movs r1, #0xd8
	bl FUN_080cc410
	ldr r1, _080D15D0 @ =0x00000409
	adds r0, r4, r1
	strb r5, [r0]
_080D15C4:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl FUN_080cc348
	b _080D169A
	.align 2, 0
_080D15D0: .4byte 0x00000409
_080D15D4:
	movs r1, #0x80
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0xa
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x1e
	strh r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D161C
_080D1610:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #4
	bl FUN_080cc348
	b _080D169A
_080D161C:
	adds r0, r4, #0
	bl FUN_080d1314
	cmp r0, #0
	beq _080D169A
	ldr r0, [r4, #0x18]
	movs r1, #0xd8
	bl FUN_080cc3e4
	ldr r2, _080D164C @ =0x00000409
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080D1650 @ =0x00000404
	adds r1, r4, r0
_080D163A:
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #2
	bl FUN_080cc348
	b _080D169A
	.align 2, 0
_080D164C: .4byte 0x00000409
_080D1650: .4byte 0x00000404
_080D1654:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0xb
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D169A
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r1, [r0]
	subs r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _080D16A0 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D169A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D16A0: .4byte 0x000002E7

	thumb_func_start FUN_080d16a4
FUN_080d16a4: @ 0x080D16A4
	push {lr}
	adds r2, r0, #0
	movs r1, #0x10
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _080D16CC
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r3, _080D16C8 @ =0x0000036A
	adds r1, r2, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _080D16CC
	movs r0, #1
	b _080D16CE
	.align 2, 0
_080D16C8: .4byte 0x0000036A
_080D16CC:
	movs r0, #0
_080D16CE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d16d4
FUN_080d16d4: @ 0x080D16D4
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #7
	beq _080D16EE
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl FUN_080cc348
_080D16EE:
	ldr r2, _080D1704 @ =0x0000037D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #4
	bls _080D16FA
	b _080D19F2
_080D16FA:
	lsls r0, r0, #2
	ldr r1, _080D1708 @ =_080D170C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D1704: .4byte 0x0000037D
_080D1708: .4byte _080D170C
_080D170C: @ jump table
	.4byte _080D1720 @ case 0
	.4byte _080D1744 @ case 1
	.4byte _080D1820 @ case 2
	.4byte _080D1928 @ case 3
	.4byte _080D19AC @ case 4
_080D1720:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	bl FUN_080cc348
	b _080D19F2
_080D1744:
	ldr r2, _080D1770 @ =0x0000037E
	adds r0, r4, r2
	ldrh r2, [r0]
	cmp r2, #0
	bne _080D179A
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _080D177C
	movs r0, #4
	strb r0, [r1]
	ldr r0, _080D1774 @ =0x000002E6
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080D1778 @ =0x000002E7
	b _080D1786
	.align 2, 0
_080D1770: .4byte 0x0000037E
_080D1774: .4byte 0x000002E6
_080D1778: .4byte 0x000002E7
_080D177C:
	strb r2, [r1]
	ldr r1, _080D1804 @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
_080D1786:
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_080d1344
	ldr r2, _080D1808 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_080D179A:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #8
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	bne _080D17C2
	b _080D19F2
_080D17C2:
	ldr r0, [r4, #0x18]
	movs r1, #0xcb
	bl FUN_080cc3e4
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D17DE
	b _080D1964
_080D17DE:
	adds r0, r4, #0
	bl FUN_080d16a4
	adds r1, r0, #0
	cmp r1, #0
	beq _080D1814
	ldr r0, [r4, #0x18]
	movs r1, #0xb9
	lsls r1, r1, #2
	bl FUN_080cc3e4
	ldr r0, _080D180C @ =0x00000409
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _080D1810 @ =0x00000404
	adds r1, r4, r2
	b _080D198E
	.align 2, 0
_080D1804: .4byte 0x000002E6
_080D1808: .4byte 0x0000037E
_080D180C: .4byte 0x00000409
_080D1810: .4byte 0x00000404
_080D1814:
	ldr r2, _080D181C @ =0x00000404
	adds r0, r4, r2
	strh r1, [r0]
	b _080D1914
	.align 2, 0
_080D181C: .4byte 0x00000404
_080D1820:
	movs r1, #0xa0
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	ldr r0, _080D1898 @ =0x00000404
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #4
	bhi _080D1846
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne _080D1846
	ldr r0, [r4, #0x18]
	ldr r1, _080D189C @ =0x00000239
	bl FUN_080cc3e4
_080D1846:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #9
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0x1e
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080d1344
	movs r0, #0x93
	lsls r0, r0, #4
	adds r1, r4, r0
	adds r0, r4, #0
	bl FUN_080cd3c0
	ldr r2, _080D18A0 @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r1, _080D18A4 @ =0x0000037E
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0x1f
	bhi _080D18A8
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	b _080D18B4
	.align 2, 0
_080D1898: .4byte 0x00000404
_080D189C: .4byte 0x00000239
_080D18A0: .4byte 0x0000095E
_080D18A4: .4byte 0x0000037E
_080D18A8:
	movs r0, #0x40
	subs r0, r0, r1
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	strh r0, [r1]
_080D18B4:
	ldr r0, _080D18F0 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bls _080D18CC
	movs r0, #0
	strh r0, [r1]
_080D18CC:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D18FC
	ldr r0, [r4, #0x18]
	ldr r1, _080D18F4 @ =0x00000239
	bl FUN_080cc410
	ldr r2, _080D18F8 @ =0x00000409
	adds r0, r4, r2
	strb r5, [r0]
	b _080D1964
	.align 2, 0
_080D18F0: .4byte 0x0000037E
_080D18F4: .4byte 0x00000239
_080D18F8: .4byte 0x00000409
_080D18FC:
	adds r0, r4, #0
	bl FUN_080d16a4
	cmp r0, #0
	bne _080D19F2
	ldr r0, [r4, #0x18]
	ldr r1, _080D1920 @ =0x00000239
	bl FUN_080cc410
	ldr r1, _080D1924 @ =0x00000409
	adds r0, r4, r1
	strb r5, [r0]
_080D1914:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl FUN_080cc348
	b _080D19F2
	.align 2, 0
_080D1920: .4byte 0x00000239
_080D1924: .4byte 0x00000409
_080D1928:
	movs r1, #0x80
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0xa
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x1e
	strh r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D1970
_080D1964:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #4
	bl FUN_080cc348
	b _080D19F2
_080D1970:
	adds r0, r4, #0
	bl FUN_080d16a4
	cmp r0, #0
	beq _080D19F2
	ldr r0, [r4, #0x18]
	ldr r1, _080D19A0 @ =0x00000239
	bl FUN_080cc3e4
	ldr r2, _080D19A4 @ =0x00000409
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080D19A8 @ =0x00000404
	adds r1, r4, r0
_080D198E:
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #2
	bl FUN_080cc348
	b _080D19F2
	.align 2, 0
_080D19A0: .4byte 0x00000239
_080D19A4: .4byte 0x00000409
_080D19A8: .4byte 0x00000404
_080D19AC:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0xb
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D19F2
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r1, [r0]
	subs r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _080D19F8 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D19F2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D19F8: .4byte 0x000002E7

	thumb_func_start FUN_080d19fc
FUN_080d19fc: @ 0x080D19FC
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080D1A30
	ldr r1, _080D1A40 @ =0x000003CE
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _080D1A30
	adds r0, r4, #0
	bl FUN_080d0824
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	movs r5, #1
_080D1A30:
	adds r0, r4, #0
	bl FUN_080cc1a0
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080D1A40: .4byte 0x000003CE

	thumb_func_start FUN_080d1a44
FUN_080d1a44: @ 0x080D1A44
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080ced00
	adds r1, r0, #0
	ldr r2, _080D1A64 @ =0x00000A8D
	adds r0, r4, r2
	strb r1, [r0]
	lsls r0, r1, #0x18
	cmp r0, #0
	blt _080D1A6C
	adds r1, #1
	ldr r2, _080D1A68 @ =0x00000951
	adds r0, r4, r2
	strb r1, [r0]
	b _080D1A74
	.align 2, 0
_080D1A64: .4byte 0x00000A8D
_080D1A68: .4byte 0x00000951
_080D1A6C:
	ldr r0, _080D1A7C @ =0x00000951
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
_080D1A74:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D1A7C: .4byte 0x00000951

	thumb_func_start FUN_080d1a80
FUN_080d1a80: @ 0x080D1A80
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _080D1A98 @ =0x00000A75
	adds r1, r4, r2
	ldrb r1, [r1]
	cmp r1, #3
	beq _080D1AD0
	cmp r1, #3
	ble _080D1A9C
	cmp r1, #4
	beq _080D1AE0
	b _080D1AF8
	.align 2, 0
_080D1A98: .4byte 0x00000A75
_080D1A9C:
	cmp r1, #0
	blt _080D1AF8
	movs r3, #0xd8
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrh r0, [r0]
	adds r0, #0x63
	asrs r2, r0, #1
	ldr r0, _080D1AC8 @ =0x00000A78
	adds r1, r4, r0
	ldr r3, _080D1ACC @ =0x00000A96
	adds r0, r4, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	ldrh r1, [r1]
	adds r0, r0, r1
	cmp r0, #0
	bge _080D1AC2
	movs r0, #0
_080D1AC2:
	adds r0, r2, r0
	b _080D1AF8
	.align 2, 0
_080D1AC8: .4byte 0x00000A78
_080D1ACC: .4byte 0x00000A96
_080D1AD0:
	movs r1, #0xd8
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	lsrs r0, r0, #1
	adds r0, #0x63
	asrs r0, r0, #1
	b _080D1AF8
_080D1AE0:
	movs r0, #0x28
	movs r1, #0xa
	bl Div
	ldr r3, _080D1B00 @ =0x00000A78
	adds r2, r4, r3
	subs r0, #8
	lsls r1, r0, #2
	adds r1, r1, r0
	ldrh r2, [r2]
	adds r0, r1, r2
	lsls r0, r0, #1
_080D1AF8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080D1B00: .4byte 0x00000A78

	thumb_func_start FUN_080d1b04
FUN_080d1b04: @ 0x080D1B04
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	bl FUN_080d1a80
	adds r5, r0, #0
	movs r7, #0
	ldr r0, _080D1B34 @ =0x00000A9C
	adds r4, r6, r0
_080D1B14:
	ldr r1, [r4]
	cmp r1, #0
	beq _080D1B22
	adds r0, r6, #0
	bl _call_via_r1
	adds r5, r5, r0
_080D1B22:
	adds r4, #4
	adds r7, #1
	cmp r7, #2
	ble _080D1B14
	adds r0, r5, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080D1B34: .4byte 0x00000A9C

	thumb_func_start FUN_080d1b38
FUN_080d1b38: @ 0x080D1B38
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r7, #0
	movs r6, #0
	ldr r0, _080D1B64 @ =0x00000AA8
	adds r4, r5, r0
_080D1B44:
	ldr r1, [r4]
	cmp r1, #0
	beq _080D1B52
	adds r0, r5, #0
	bl _call_via_r1
	orrs r7, r0
_080D1B52:
	adds r4, #4
	adds r6, #1
	cmp r6, #2
	ble _080D1B44
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080D1B64: .4byte 0x00000AA8

	thumb_func_start FUN_080d1b68
FUN_080d1b68: @ 0x080D1B68
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	movs r1, #0x1f
	ldrh r0, [r6, #0xa]
	ands r0, r1
	cmp r0, #0
	beq _080D1BF8
	ldr r5, [r7, #0x4c]
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_08236640
	movs r4, #0
_080D1B84:
	lsls r1, r4, #2
	ldr r2, _080D1C00 @ =0x00000AB4
	adds r0, r5, r2
	adds r0, r0, r1
	ldr r3, [r0]
	cmp r3, #0
	beq _080D1BA2
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl _call_via_r3
	ldrh r1, [r6, #0x3e]
	adds r1, r1, r0
	strh r1, [r6, #0x3e]
_080D1BA2:
	adds r4, #1
	cmp r4, #2
	ble _080D1B84
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D1BF8
	ldr r2, _080D1C04 @ =0x00000A8D
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _080D1BF8
	adds r0, r5, #0
	bl FUN_080cc618
	cmp r0, #0
	beq _080D1BF8
	adds r2, r6, #0
	adds r2, #0x43
	ldrb r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080D1BF8
	ldrh r1, [r6, #0x3e]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsrs r0, r0, #1
	strh r0, [r6, #0x3e]
	ldrh r1, [r6, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D1BF8
	ldrb r1, [r2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
_080D1BF8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D1C00: .4byte 0x00000AB4
_080D1C04: .4byte 0x00000A8D

	thumb_func_start FUN_080d1c08
FUN_080d1c08: @ 0x080D1C08
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080D1C88 @ =0x000009C8
	adds r6, r4, r0
	ldr r1, _080D1C8C @ =0x00000A68
	adds r2, r4, r1
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080D1C90 @ =0x00000A6A
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #0xe6
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r2, #0x22
	adds r1, r4, r2
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080d1b04
	mov r8, r0
	adds r0, r4, #0
	bl FUN_080d1b38
	adds r5, r0, #0
	ldr r1, _080D1C94 @ =0x00000A7E
	adds r0, r4, r1
	ldrh r7, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D1CA0
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0xc
	strh r0, [r1]
	ldr r2, _080D1C98 @ =0x00000A84
	adds r1, r4, r2
	movs r0, #5
	strh r0, [r1]
	ldr r0, _080D1C9C @ =0x00000A88
	adds r1, r4, r0
	movs r0, #3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r5, r0
	b _080D1CEC
	.align 2, 0
_080D1C88: .4byte 0x000009C8
_080D1C8C: .4byte 0x00000A68
_080D1C90: .4byte 0x00000A6A
_080D1C94: .4byte 0x00000A7E
_080D1C98: .4byte 0x00000A84
_080D1C9C: .4byte 0x00000A88
_080D1CA0:
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D1CD4
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0xc
	strh r0, [r1]
	ldr r2, _080D1CCC @ =0x00000A84
	adds r1, r4, r2
	movs r0, #5
	strh r0, [r1]
	ldr r0, _080D1CD0 @ =0x00000A88
	adds r1, r4, r0
	movs r0, #3
	b _080D1CEA
	.align 2, 0
_080D1CCC: .4byte 0x00000A84
_080D1CD0: .4byte 0x00000A88
_080D1CD4:
	movs r1, #0xa8
	lsls r1, r1, #4
	adds r0, r4, r1
	movs r1, #8
	strh r1, [r0]
	ldr r2, _080D1D3C @ =0x00000A84
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _080D1D40 @ =0x00000A88
	adds r1, r4, r0
	movs r0, #4
_080D1CEA:
	strh r0, [r1]
_080D1CEC:
	adds r1, r6, #0
	adds r1, #0xc5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _080D1D06
	adds r1, r0, #0
	movs r0, #1
	lsls r0, r1
	orrs r5, r0
	adds r0, r4, #0
	bl FUN_080cec18
_080D1D06:
	adds r0, r6, #0
	adds r0, #0x48
	adds r1, r6, #0
	adds r1, #0xb4
	ldrh r2, [r1]
	str r5, [sp]
	str r7, [sp, #4]
	mov r1, r8
	movs r3, #1
	bl FUN_082364f8
	adds r0, r6, #0
	adds r0, #0xc4
	ldrb r0, [r0]
	adds r2, r6, #0
	adds r2, #0x8a
	movs r1, #0
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0xc2
	strh r1, [r0]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D1D3C: .4byte 0x00000A84
_080D1D40: .4byte 0x00000A88

	thumb_func_start FUN_080d1d44
FUN_080d1d44: @ 0x080D1D44
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	mov ip, r0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r7, r3, #0
	ldr r2, _080D1D8C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080D1D90 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080D1D94 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r3, r0, #0
	adds r3, #0x70
	ldr r2, _080D1D98 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r6, r2, #0
	cmp r0, #0
	blt _080D1D9C
	asrs r1, r0, #0xc
	b _080D1DA2
	.align 2, 0
_080D1D8C: .4byte 0x030046B8
_080D1D90: .4byte 0x000003FF
_080D1D94: .4byte 0x0203B400
_080D1D98: .4byte 0x085B0A08
_080D1D9C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D1DA2:
	ldrh r0, [r4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldrh r1, [r4, #2]
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp]
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D1DC8
	asrs r0, r0, #0xc
	b _080D1DCE
_080D1DC8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D1DCE:
	ldrh r1, [r4, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D1DFC @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080D1E00
	asrs r0, r0, #0xc
	b _080D1E06
	.align 2, 0
_080D1DFC: .4byte 0xFFFF0000
_080D1E00:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D1E06:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080D1E2A
	asrs r0, r0, #0xc
	b _080D1E30
_080D1E2A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D1E30:
	rsbs r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _080D1E78 @ =0xFFFF0000
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	cmp r7, #0
	beq _080D1E66
	ldrh r0, [r2]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #8]
	ldrh r0, [r2, #4]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r2, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r2, #4]
_080D1E66:
	mov r0, ip
	mov r1, sp
	ldr r3, [sp, #0x24]
	bl FUN_080ccfe4
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D1E78: .4byte 0xFFFF0000

	thumb_func_start FUN_080d1e7c
FUN_080d1e7c: @ 0x080D1E7C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _080D1EB0 @ =0x000009C8
	adds r5, r7, r0
	ldr r1, _080D1EB4 @ =0x00000A8A
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D1EC0
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D1EB8
	ldr r0, [r7, #0x18]
	movs r1, #0xe3
	lsls r1, r1, #2
	bl FUN_080cc3e4
	b _080D1EC0
	.align 2, 0
_080D1EB0: .4byte 0x000009C8
_080D1EB4: .4byte 0x00000A8A
_080D1EB8:
	ldr r0, [r7, #0x18]
	ldr r1, _080D1F04 @ =0x0000038B
	bl FUN_080cc3e4
_080D1EC0:
	adds r0, r5, #0
	adds r0, #0xc2
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xbc
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r0
	ldrh r2, [r2]
	cmp r1, r2
	bls _080D1EDC
	b _080D1FF8
_080D1EDC:
	ldr r4, _080D1F08 @ =0x000002E7
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D1F0C
	adds r0, r5, #0
	adds r0, #0xc4
	ldrb r1, [r0]
	mov r0, r8
	ldrh r2, [r0]
	adds r0, r5, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	muls r0, r2, r0
	subs r1, r1, r0
	movs r3, #0x90
	lsls r3, r3, #1
	adds r6, r1, r3
	b _080D1F2A
	.align 2, 0
_080D1F04: .4byte 0x0000038B
_080D1F08: .4byte 0x000002E7
_080D1F0C:
	adds r2, r5, #0
	adds r2, #0xc4
	mov r4, r8
	ldrh r1, [r4]
	adds r0, r5, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	muls r0, r1, r0
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r6, r0, #0
	subs r6, #0x20
_080D1F2A:
	movs r0, #0xff
	ands r6, r0
	ldr r2, _080D1F50 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r4, r2, #0
	cmp r0, #0
	blt _080D1F54
	asrs r1, r0, #0xc
	b _080D1F5A
	.align 2, 0
_080D1F50: .4byte 0x085B0A08
_080D1F54:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D1F5A:
	adds r3, r5, #0
	adds r3, #0xa0
	ldrh r0, [r3]
	adds r0, r0, r1
	adds r2, r5, #0
	adds r2, #0x98
	strh r0, [r2]
	adds r0, r5, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	adds r1, r5, #0
	adds r1, #0x9a
	strh r0, [r1]
	lsls r0, r6, #1
	adds r0, r0, r4
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #5
	mov sb, r3
	adds r3, r2, #0
	cmp r0, #0
	blt _080D1F8E
	asrs r2, r0, #0xc
	b _080D1F94
_080D1F8E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D1F94:
	adds r0, r5, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r0, r0, r2
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	adds r4, r5, #0
	adds r4, #0x48
	adds r0, r4, #0
	adds r1, r3, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	adds r2, r5, #0
	adds r2, #0xc5
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _080D1FEE
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	mov r0, r8
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D1FEE
	ldr r1, _080D1FF4 @ =0x000002E7
	adds r0, r7, r1
	ldrb r3, [r0]
	movs r0, #0
	ldrsb r0, [r2, r0]
	str r0, [sp]
	adds r0, r7, #0
	mov r1, sb
	adds r2, r6, #0
	bl FUN_080d1d44
_080D1FEE:
	movs r0, #0
	b _080D1FFA
	.align 2, 0
_080D1FF4: .4byte 0x000002E7
_080D1FF8:
	movs r0, #1
_080D1FFA:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080d2008
FUN_080d2008: @ 0x080D2008
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D202A
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D202E
_080D202A:
	movs r6, #0x30
	b _080D2030
_080D202E:
	movs r6, #0x40
_080D2030:
	ldr r3, _080D2044 @ =0x0000037D
	adds r4, r5, r3
	ldrb r0, [r4]
	cmp r0, #1
	beq _080D2084
	cmp r0, #1
	bgt _080D2048
	cmp r0, #0
	beq _080D2054
	b _080D21C2
	.align 2, 0
_080D2044: .4byte 0x0000037D
_080D2048:
	cmp r0, #4
	beq _080D20DC
	cmp r0, #6
	bne _080D2052
	b _080D2160
_080D2052:
	b _080D21C2
_080D2054:
	adds r0, r5, #0
	bl FUN_080d1a44
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x15
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_080cc1e8
	cmp r0, #0
	bne _080D2078
	b _080D21C2
_080D2078:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_080cc348
	b _080D21C2
_080D2084:
	adds r0, r5, #0
	bl FUN_080d1a44
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x16
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D20CC
	adds r0, r5, #0
	bl FUN_080d1c08
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_080cc348
	b _080D21C2
_080D20CC:
	ldr r0, _080D20D8 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _080D21C2
	.align 2, 0
_080D20D8: .4byte 0x0000037E
_080D20DC:
	ldr r2, _080D2158 @ =0x000003D1
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D20FE
	ldr r0, _080D215C @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080D20FE:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r4, r5, r1
	ldrb r0, [r4]
	movs r1, #0x17
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_080cc1e8
	ldrb r0, [r4]
	cmp r0, #1
	bne _080D2142
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #2
	bne _080D2142
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D2142
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	bl FUN_080ccb20
_080D2142:
	adds r0, r5, #0
	bl FUN_080d1e7c
	cmp r0, #0
	beq _080D21C2
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_080cc348
	b _080D21C2
	.align 2, 0
_080D2158: .4byte 0x000003D1
_080D215C: .4byte 0x00000A76
_080D2160:
	ldr r3, _080D2194 @ =0x000003D1
	adds r0, r5, r3
	movs r3, #0
	strb r3, [r0]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D2182
	ldr r2, _080D2198 @ =0x00000A76
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_080D2182:
	ldr r0, _080D2198 @ =0x00000A76
	adds r2, r5, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _080D219C
	strb r3, [r2]
	strb r3, [r4]
	b _080D21C2
	.align 2, 0
_080D2194: .4byte 0x000003D1
_080D2198: .4byte 0x00000A76
_080D219C:
	ldr r1, _080D21C8 @ =0x0000037E
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldr r3, _080D21CC @ =0x00000A88
	adds r0, r5, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r0]
	cmp r1, r0
	blo _080D21C2
	movs r0, #0
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D21C2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D21C8: .4byte 0x0000037E
_080D21CC: .4byte 0x00000A88

	thumb_func_start FUN_080d21d0
FUN_080d21d0: @ 0x080D21D0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	ldr r2, _080D21F4 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D21F8
	asrs r1, r0, #0xc
	b _080D21FE
	.align 2, 0
_080D21F4: .4byte 0x085B0A08
_080D21F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D21FE:
	ldrh r0, [r4]
	adds r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r4, #2]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D221E
	asrs r1, r0, #0xc
	b _080D2224
_080D221E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D2224:
	ldrh r0, [r4, #4]
	adds r0, r0, r1
	strh r0, [r5, #4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d2230
FUN_080d2230: @ 0x080D2230
	push {lr}
	adds r3, r1, #0
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	lsrs r1, r1, #4
	cmp r1, #1
	beq _080D2248
	cmp r1, #2
	beq _080D224C
	b _080D2250
_080D2248:
	ldrb r0, [r3, #4]
	b _080D224E
_080D224C:
	ldrb r0, [r3]
_080D224E:
	subs r2, r2, r0
_080D2250:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d2258
FUN_080d2258: @ 0x080D2258
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r1, #0
	adds r3, r2, #0
	mov r6, sp
	mov r0, sp
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_080d21d0
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080D2294
	cmp r1, #0
	blt _080D2294
	ldr r0, _080D229C @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080D2294
	ldr r0, _080D22A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D22A8
_080D2294:
	movs r4, #0
	ldr r2, _080D22A4 @ =0x030046A4
	b _080D22B6
	.align 2, 0
_080D229C: .4byte 0x030046A8
_080D22A0: .4byte 0x030046AC
_080D22A4: .4byte 0x030046A4
_080D22A8:
	ldr r2, _080D22C4 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_080D22B6:
	ldr r0, [r2]
	ldr r2, [r0, #4]
	cmp r2, #0
	bne _080D22C8
	movs r0, #0
	b _080D22CE
	.align 2, 0
_080D22C4: .4byte 0x030046A4
_080D22C8:
	lsls r0, r4, #2
	adds r0, #0xc
	adds r0, r2, r0
_080D22CE:
	mov r5, sp
	mov r1, sp
	bl FUN_080d2230
	movs r2, #2
	ldrsh r1, [r5, r2]
	cmp r0, r1
	ble _080D22E2
	movs r0, #1
	b _080D2304
_080D22E2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D2302
	adds r0, #4
	mov r1, sp
	bl FUN_080d2230
	movs r2, #2
	ldrsh r1, [r5, r2]
	cmp r0, r1
	ble _080D2302
	movs r0, #2
	b _080D2304
_080D2302:
	movs r0, #0
_080D2304:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080d230c
FUN_080d230c: @ 0x080D230C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _080D236C @ =0x000009C8
	adds r4, r5, r0
	ldr r1, _080D2370 @ =0x00000A68
	adds r2, r5, r1
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080D2374 @ =0x00000A6A
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #0x96
	strh r0, [r1]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	ldr r6, _080D2378 @ =0x00000A8C
	adds r1, r5, r6
	strb r0, [r1]
	ldr r2, _080D237C @ =0x085B0A08
	ldrb r0, [r1]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xcc
	muls r0, r1, r0
	adds r6, r2, #0
	cmp r0, #0
	blt _080D2380
	asrs r1, r0, #0xc
	b _080D2386
	.align 2, 0
_080D236C: .4byte 0x000009C8
_080D2370: .4byte 0x00000A68
_080D2374: .4byte 0x00000A6A
_080D2378: .4byte 0x00000A8C
_080D237C: .4byte 0x085B0A08
_080D2380:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D2386:
	adds r3, r4, #0
	adds r3, #0xa0
	ldrh r0, [r3]
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x98
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	adds r1, #2
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0xc4
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r0, #0xcc
	muls r0, r1, r0
	mov r8, r3
	mov sl, r2
	cmp r0, #0
	blt _080D23BC
	asrs r1, r0, #0xc
	b _080D23C2
_080D23BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D23C2:
	adds r0, r4, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x9c
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080d1b04
	str r0, [sp, #8]
	adds r0, r5, #0
	bl FUN_080d1b38
	mov sb, r0
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #1
	bne _080D23F6
	movs r0, #0x80
	lsls r0, r0, #0xb
	mov r1, sb
	orrs r1, r0
	mov sb, r1
_080D23F6:
	adds r0, r4, #0
	adds r0, #0xb4
	ldrh r0, [r0]
	str r0, [sp, #0xc]
	mov r2, sl
	ldrb r1, [r2]
	mov r0, r8
	movs r2, #0xe0
	bl FUN_080d2258
	adds r7, r0, #0
	cmp r7, #0
	beq _080D24DE
	adds r0, r4, #0
	adds r0, #0xc5
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r3, r0, #0
	cmp r1, #2
	beq _080D2422
	cmp r1, #4
	bne _080D247E
_080D2422:
	cmp r7, #2
	bne _080D247E
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0x1b
	strh r0, [r1]
	ldrb r0, [r6]
	cmp r0, #1
	beq _080D2446
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r6, #0xde
	lsls r6, r6, #2
	adds r0, r5, r6
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	beq _080D2462
_080D2446:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r1, #4
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbe
	strh r7, [r0]
	adds r1, #4
	movs r0, #3
	strh r0, [r1]
	b _080D25A2
_080D2462:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	strh r2, [r0]
	adds r1, #6
	movs r0, #3
	strh r0, [r1]
	adds r1, #2
	movs r0, #6
	strh r0, [r1]
	b _080D25A2
_080D247E:
	adds r1, r4, #0
	adds r1, #0xba
	movs r6, #0
	movs r0, #0x1a
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D24A6
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	beq _080D24C2
_080D24A6:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	strh r6, [r0]
	adds r1, #6
	movs r0, #2
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xc0
	strh r6, [r0]
	b _080D25A2
_080D24C2:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	strh r2, [r0]
	adds r1, #6
	movs r0, #3
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xc0
	strh r2, [r0]
	b _080D25A2
_080D24DE:
	mov r3, sl
	ldrb r1, [r3]
	movs r2, #0xa8
	lsls r2, r2, #1
	mov r0, r8
	bl FUN_080d2258
	cmp r0, #0
	beq _080D2548
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0x1b
	strh r0, [r1]
	ldrb r0, [r6]
	cmp r0, #1
	beq _080D2510
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r6, #0xde
	lsls r6, r6, #2
	adds r0, r5, r6
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	beq _080D252C
_080D2510:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r1, #4
	movs r0, #2
	strh r0, [r1]
	adds r1, #2
	movs r0, #3
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xc0
	strh r7, [r0]
	b _080D259E
_080D252C:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r1, #4
	movs r0, #2
	strh r0, [r1]
	adds r1, #2
	movs r0, #7
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xc0
	strh r2, [r0]
	b _080D259E
_080D2548:
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0x1c
	strh r0, [r1]
	ldrb r0, [r6]
	cmp r0, #1
	beq _080D2568
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D2584
_080D2568:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	movs r1, #4
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #1
	b _080D259C
_080D2584:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r1, #4
	movs r0, #4
	strh r0, [r1]
	adds r1, #2
	movs r0, #7
	strh r0, [r1]
	adds r1, #2
	movs r0, #5
_080D259C:
	strh r0, [r1]
_080D259E:
	adds r3, r4, #0
	adds r3, #0xc5
_080D25A2:
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	blt _080D25BC
	adds r1, r0, #0
	movs r0, #1
	lsls r0, r1
	mov r3, sb
	orrs r3, r0
	mov sb, r3
	adds r0, r5, #0
	bl FUN_080cec18
_080D25BC:
	adds r0, r4, #0
	adds r0, #0x48
	mov r6, sb
	str r6, [sp]
	adds r1, r4, #0
	adds r1, #0xb6
	ldrh r1, [r1]
	str r1, [sp, #4]
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	movs r3, #2
	bl FUN_082364f8
	mov r1, sl
	ldrb r0, [r1]
	adds r3, r4, #0
	adds r3, #0x8a
	movs r1, #0
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xc2
	strh r1, [r0]
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d25f8
FUN_080d25f8: @ 0x080D25F8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov ip, r0
	adds r7, r2, #0
	str r3, [sp, #0x10]
	ldr r0, _080D26B0 @ =0x0203B400
	mov sb, r0
	ldr r6, _080D26B4 @ =0x030046B8
	ldr r3, [r6]
	adds r3, #1
	ldr r2, _080D26B8 @ =0x000003FF
	mov r8, r2
	ands r3, r2
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	movs r5, #0x1f
	ands r0, r5
	ldrh r2, [r1]
	adds r0, r0, r2
	subs r0, #0xf
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080D26BC @ =0xFFFF0000
	mov sl, r2
	ldr r4, [sp]
	ands r4, r2
	orrs r4, r0
	str r4, [sp]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	ands r0, r5
	ldrh r2, [r1, #2]
	adds r0, r0, r2
	subs r0, #0xf
	lsls r0, r0, #0x10
	ldr r2, _080D26C0 @ =0x0000FFFF
	ands r2, r4
	orrs r2, r0
	str r2, [sp]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	ands r0, r5
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	subs r0, #0xf
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	mov r2, sl
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r3, r3, #1
	add r3, sb
	ldrh r0, [r3]
	movs r1, #3
	ands r0, r1
	adds r3, r0, #3
	ldr r2, _080D26C4 @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D26C8
	asrs r0, r0, #0xc
	b _080D26CE
	.align 2, 0
_080D26B0: .4byte 0x0203B400
_080D26B4: .4byte 0x030046B8
_080D26B8: .4byte 0x000003FF
_080D26BC: .4byte 0xFFFF0000
_080D26C0: .4byte 0x0000FFFF
_080D26C4: .4byte 0x085B0A08
_080D26C8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D26CE:
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	movs r0, #0xff
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D26EC
	asrs r0, r0, #0xc
	b _080D26F2
_080D26EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D26F2:
	rsbs r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _080D2720 @ =0xFFFF0000
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	mov r0, ip
	mov r1, sp
	ldr r3, [sp, #0x10]
	bl FUN_080ccfe4
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D2720: .4byte 0xFFFF0000

	thumb_func_start FUN_080d2724
FUN_080d2724: @ 0x080D2724
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _080D2758 @ =0x000009C8
	adds r5, r6, r0
	ldr r1, _080D275C @ =0x00000A8A
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D276C
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D2764
	ldr r0, [r6, #0x18]
	ldr r1, _080D2760 @ =0x0000038F
	bl FUN_080cc3e4
	b _080D276C
	.align 2, 0
_080D2758: .4byte 0x000009C8
_080D275C: .4byte 0x00000A8A
_080D2760: .4byte 0x0000038F
_080D2764:
	ldr r0, [r6, #0x18]
	ldr r1, _080D27B0 @ =0x0000038D
	bl FUN_080cc3e4
_080D276C:
	adds r0, r5, #0
	adds r0, #0xc2
	adds r1, r5, #0
	adds r1, #0xbc
	ldrh r2, [r0]
	mov sb, r0
	mov sl, r1
	ldrh r3, [r1]
	cmp r2, r3
	bhs _080D284A
	subs r0, #0xa
	ldrh r1, [r0]
	mov r2, sb
	ldrh r0, [r2]
	muls r0, r1, r0
	adds r4, r0, #0
	adds r4, #0xcc
	ldr r2, _080D27B4 @ =0x085B0A08
	adds r3, r5, #0
	adds r3, #0xc4
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	mov r8, r3
	cmp r0, #0
	blt _080D27B8
	asrs r1, r0, #0xc
	b _080D27BE
	.align 2, 0
_080D27B0: .4byte 0x0000038D
_080D27B4: .4byte 0x085B0A08
_080D27B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D27BE:
	adds r0, r5, #0
	adds r0, #0xa0
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x98
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	adds r3, r5, #0
	adds r3, #0x9a
	strh r0, [r3]
	mov r3, r8
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	adds r7, r1, #0
	cmp r0, #0
	blt _080D27F0
	asrs r2, r0, #0xc
	b _080D27F6
_080D27F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D27F6:
	adds r0, r5, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r0, r0, r2
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	adds r4, r5, #0
	adds r4, #0x48
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	adds r3, r5, #0
	adds r3, #0xc5
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r1, r5, #0
	adds r1, #0xbe
	str r1, [sp]
	cmp r0, #0
	bge _080D282C
	b _080D2928
_080D282C:
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r6, #0x20]
	orrs r0, r1
	str r0, [r6, #0x20]
	mov r0, r8
	ldrb r2, [r0]
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_080d25f8
	b _080D2928
_080D284A:
	mov r1, sb
	ldrh r2, [r1]
	mov r0, sl
	ldrh r3, [r0]
	adds r1, r5, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, r3, r0
	str r1, [sp]
	cmp r2, r0
	bge _080D2928
	adds r0, r5, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	muls r0, r3, r0
	adds r4, r0, #0
	adds r4, #0xcc
	ldr r2, _080D2890 @ =0x085B0A08
	adds r3, r5, #0
	adds r3, #0xc4
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	mov r8, r3
	cmp r0, #0
	blt _080D2894
	asrs r1, r0, #0xc
	b _080D289A
	.align 2, 0
_080D2890: .4byte 0x085B0A08
_080D2894:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D289A:
	adds r0, r5, #0
	adds r0, #0xa0
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x98
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	adds r3, r5, #0
	adds r3, #0x9a
	strh r0, [r3]
	mov r3, r8
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	adds r7, r1, #0
	cmp r0, #0
	blt _080D28CC
	asrs r2, r0, #0xc
	b _080D28D2
_080D28CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D28D2:
	adds r0, r5, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r0, r0, r2
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	adds r4, r5, #0
	adds r4, #0x48
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	adds r3, r5, #0
	adds r3, #0xc5
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	blt _080D2928
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r6, #0x20]
	orrs r0, r1
	str r0, [r6, #0x20]
	mov r0, sb
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D2928
	mov r1, r8
	ldrb r2, [r1]
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_080d25f8
_080D2928:
	mov r2, sb
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r3, sl
	ldrh r1, [r3]
	ldr r3, [sp]
	ldrh r2, [r3]
	adds r3, r5, #0
	adds r3, #0xc0
	adds r1, r1, r2
	ldrh r3, [r3]
	adds r1, r1, r3
	cmp r0, r1
	bge _080D294E
	movs r0, #0
	b _080D2956
_080D294E:
	movs r0, #0
	mov r1, sb
	strh r0, [r1]
	movs r0, #1
_080D2956:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d2968
FUN_080d2968: @ 0x080D2968
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D298A
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D298E
_080D298A:
	movs r7, #0x30
	b _080D2990
_080D298E:
	movs r7, #0x40
_080D2990:
	ldr r1, _080D29A8 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #6
	bls _080D299C
	b _080D2BF8
_080D299C:
	lsls r0, r0, #2
	ldr r1, _080D29AC @ =_080D29B0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D29A8: .4byte 0x0000037D
_080D29AC: .4byte _080D29B0
_080D29B0: @ jump table
	.4byte _080D29CC @ case 0
	.4byte _080D29FC @ case 1
	.4byte _080D2BF8 @ case 2
	.4byte _080D2BF8 @ case 3
	.4byte _080D2A64 @ case 4
	.4byte _080D2B38 @ case 5
	.4byte _080D2B8C @ case 6
_080D29CC:
	adds r0, r5, #0
	bl FUN_080d1a44
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x18
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r7, #0
	bl FUN_080cc1e8
	cmp r0, #0
	bne _080D29F0
	b _080D2BF8
_080D29F0:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_080cc348
	b _080D2BF8
_080D29FC:
	adds r0, r5, #0
	bl FUN_080d1a44
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x19
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r2, _080D2A50 @ =0x0000037E
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #6
	bls _080D2A54
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D2A54
	adds r0, r5, #0
	bl FUN_080d230c
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_080cc348
	b _080D2BF8
	.align 2, 0
_080D2A50: .4byte 0x0000037E
_080D2A54:
	ldr r2, _080D2A60 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _080D2BF8
	.align 2, 0
_080D2A60: .4byte 0x0000037E
_080D2A64:
	ldr r0, _080D2AC0 @ =0x000003D1
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r4, r5, r1
	ldrb r0, [r4]
	ldr r2, _080D2AC4 @ =0x00000A82
	adds r6, r5, r2
	ldrh r1, [r6]
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r7, #0
	bl FUN_080cc1e8
	ldrb r0, [r4]
	cmp r0, #1
	bne _080D2B22
	ldrh r0, [r6]
	cmp r0, #0x1c
	bne _080D2AC8
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #1
	bne _080D2B22
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D2B22
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	movs r3, #0
	bl FUN_080ccc34
	b _080D2B22
	.align 2, 0
_080D2AC0: .4byte 0x000003D1
_080D2AC4: .4byte 0x00000A82
_080D2AC8:
	cmp r0, #0x1b
	bne _080D2AF6
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #1
	bne _080D2B22
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D2B22
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	movs r3, #1
	bl FUN_080ccc34
	b _080D2B22
_080D2AF6:
	cmp r0, #0x1a
	bne _080D2B22
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D2B22
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #1
	bne _080D2B22
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	movs r3, #2
	bl FUN_080ccc34
_080D2B22:
	adds r0, r5, #0
	bl FUN_080d2724
	cmp r0, #0
	beq _080D2BF8
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_080cc348
	b _080D2BF8
_080D2B38:
	ldr r2, _080D2B84 @ =0x000003D1
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D2B5A
	ldr r2, _080D2B88 @ =0x00000A76
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_080D2B5A:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x18
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r7, #0
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D2BF8
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_080cc348
	b _080D2BF8
	.align 2, 0
_080D2B84: .4byte 0x000003D1
_080D2B88: .4byte 0x00000A76
_080D2B8C:
	ldr r2, _080D2BC4 @ =0x000003D1
	adds r0, r5, r2
	movs r2, #0
	strb r2, [r0]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D2BAE
	ldr r0, _080D2BC8 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080D2BAE:
	ldr r1, _080D2BC8 @ =0x00000A76
	adds r4, r5, r1
	ldrb r6, [r4]
	cmp r6, #0
	beq _080D2BD0
	strb r2, [r4]
	ldr r1, _080D2BCC @ =0x0000037D
	adds r0, r5, r1
	strb r2, [r0]
	b _080D2BF8
	.align 2, 0
_080D2BC4: .4byte 0x000003D1
_080D2BC8: .4byte 0x00000A76
_080D2BCC: .4byte 0x0000037D
_080D2BD0:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x19
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r7, #0
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D2BF8
	strb r6, [r4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D2BF8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d2c00
FUN_080d2c00: @ 0x080D2C00
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080D2C7C @ =0x000009C8
	adds r5, r4, r0
	ldr r1, _080D2C80 @ =0x00000A68
	adds r2, r4, r1
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080D2C84 @ =0x00000A6A
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #0xe6
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r2, #0x22
	adds r1, r4, r2
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080d1b04
	adds r7, r0, #0
	adds r0, r4, #0
	bl FUN_080d1b38
	adds r6, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D2C90
	movs r2, #0xa8
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #0x1d
	strh r0, [r1]
	ldr r0, _080D2C88 @ =0x00000A88
	adds r1, r4, r0
	movs r0, #7
	strh r0, [r1]
	adds r2, #4
	adds r1, r4, r2
	movs r0, #4
	strh r0, [r1]
	ldr r0, _080D2C8C @ =0x00000A86
	adds r1, r4, r0
	movs r0, #6
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r6, r0
	b _080D2CEE
	.align 2, 0
_080D2C7C: .4byte 0x000009C8
_080D2C80: .4byte 0x00000A68
_080D2C84: .4byte 0x00000A6A
_080D2C88: .4byte 0x00000A88
_080D2C8C: .4byte 0x00000A86
_080D2C90:
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D2CCC
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x1d
	strh r0, [r1]
	ldr r2, _080D2CC4 @ =0x00000A88
	adds r1, r4, r2
	movs r0, #7
	strh r0, [r1]
	ldr r0, _080D2CC8 @ =0x00000A84
	adds r1, r4, r0
	movs r0, #4
	strh r0, [r1]
	subs r2, #2
	adds r1, r4, r2
	movs r0, #6
	b _080D2CEC
	.align 2, 0
_080D2CC4: .4byte 0x00000A88
_080D2CC8: .4byte 0x00000A84
_080D2CCC:
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x13
	strh r0, [r1]
	ldr r2, _080D2D40 @ =0x00000A88
	adds r1, r4, r2
	movs r0, #0xb
	strh r0, [r1]
	ldr r0, _080D2D44 @ =0x00000A84
	adds r1, r4, r0
	movs r0, #6
	strh r0, [r1]
	subs r2, #2
	adds r1, r4, r2
	movs r0, #9
_080D2CEC:
	strh r0, [r1]
_080D2CEE:
	adds r1, r5, #0
	adds r1, #0xc5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _080D2D08
	adds r1, r0, #0
	movs r0, #1
	lsls r0, r1
	orrs r6, r0
	adds r0, r4, #0
	bl FUN_080cec18
_080D2D08:
	adds r0, r5, #0
	adds r0, #0x48
	adds r1, r5, #0
	adds r1, #0xb4
	ldrh r2, [r1]
	str r6, [sp]
	adds r1, #2
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r1, r7, #0
	movs r3, #4
	bl FUN_082364f8
	adds r0, r5, #0
	adds r0, #0xc4
	ldrb r0, [r0]
	adds r2, r5, #0
	adds r2, #0x8a
	movs r1, #0
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xc2
	strh r1, [r0]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D2D40: .4byte 0x00000A88
_080D2D44: .4byte 0x00000A84

	thumb_func_start FUN_080d2d48
FUN_080d2d48: @ 0x080D2D48
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp, #0x10]
	adds r7, r2, #0
	mov ip, r3
	ldr r0, _080D2E04 @ =0x0203B400
	mov sb, r0
	ldr r6, _080D2E08 @ =0x030046B8
	ldr r3, [r6]
	adds r3, #1
	ldr r2, _080D2E0C @ =0x000003FF
	mov r8, r2
	ands r3, r2
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	movs r5, #0x1f
	ands r0, r5
	ldrh r2, [r1]
	adds r0, r0, r2
	subs r0, #0xf
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080D2E10 @ =0xFFFF0000
	mov sl, r2
	ldr r4, [sp]
	ands r4, r2
	orrs r4, r0
	str r4, [sp]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	ands r0, r5
	ldrh r2, [r1, #2]
	adds r0, r0, r2
	subs r0, #0xf
	lsls r0, r0, #0x10
	ldr r2, _080D2E14 @ =0x0000FFFF
	ands r2, r4
	orrs r2, r0
	str r2, [sp]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	ands r0, r5
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	subs r0, #0xf
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	mov r2, sl
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r3, r3, #1
	add r3, sb
	ldrh r0, [r3]
	movs r1, #3
	ands r0, r1
	adds r3, r0, #5
	ldr r2, _080D2E18 @ =0x085B0A08
	adds r0, r7, #0
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
	blt _080D2E1C
	asrs r0, r0, #0xc
	b _080D2E22
	.align 2, 0
_080D2E04: .4byte 0x0203B400
_080D2E08: .4byte 0x030046B8
_080D2E0C: .4byte 0x000003FF
_080D2E10: .4byte 0xFFFF0000
_080D2E14: .4byte 0x0000FFFF
_080D2E18: .4byte 0x085B0A08
_080D2E1C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D2E22:
	lsls r2, r0, #0x10
	ldr r1, _080D2E44 @ =0x0000FFFF
	ldr r0, [sp, #8]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #8]
	movs r0, #0xff
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D2E48
	asrs r0, r0, #0xc
	b _080D2E4E
	.align 2, 0
_080D2E44: .4byte 0x0000FFFF
_080D2E48:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D2E4E:
	rsbs r3, r0, #0
	mov r0, ip
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D2E6A
	asrs r0, r0, #0xc
	b _080D2E70
_080D2E6A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D2E70:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D2E98 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	movs r0, #0xff
	mov r2, ip
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D2E9C
	asrs r0, r0, #0xc
	b _080D2EA2
	.align 2, 0
_080D2E98: .4byte 0xFFFF0000
_080D2E9C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D2EA2:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _080D2ECC @ =0xFFFF0000
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	ldr r0, [sp, #0x10]
	mov r1, sp
	ldr r3, [sp, #0x34]
	bl FUN_080ccfe4
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D2ECC: .4byte 0xFFFF0000

	thumb_func_start FUN_080d2ed0
FUN_080d2ed0: @ 0x080D2ED0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r5, r0, #0
	ldr r0, _080D2F00 @ =0x000009C8
	adds r6, r5, r0
	ldr r1, _080D2F04 @ =0x00000A8A
	adds r3, r5, r1
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	ldr r2, _080D2F08 @ =0x00000A88
	adds r1, r5, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r4, [r1]
	cmp r0, r4
	bhi _080D2F0C
_080D2EFA:
	movs r0, #0
	b _080D317A
	.align 2, 0
_080D2F00: .4byte 0x000009C8
_080D2F04: .4byte 0x00000A8A
_080D2F08: .4byte 0x00000A88
_080D2F0C:
	ldrh r2, [r3]
	ldrh r0, [r1]
	ldr r7, _080D2F38 @ =0x00000A84
	adds r1, r5, r7
	ldrh r1, [r1]
	adds r1, r0, r1
	cmp r2, r1
	ble _080D2F1E
	b _080D313C
_080D2F1E:
	cmp r2, r1
	bne _080D2F44
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D2F3C
	ldr r0, [r5, #0x18]
	adds r1, #0x38
	bl FUN_080cc3e4
	b _080D2F44
	.align 2, 0
_080D2F38: .4byte 0x00000A84
_080D2F3C:
	ldr r0, [r5, #0x18]
	ldr r1, _080D2F8C @ =0x0000038E
	bl FUN_080cc3e4
_080D2F44:
	adds r4, r6, #0
	adds r4, #0xc2
	ldrh r1, [r4]
	adds r3, r6, #0
	adds r3, #0xc0
	ldrh r0, [r3]
	subs r1, r1, r0
	adds r0, r6, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	muls r1, r0, r1
	movs r0, #0xa8
	lsls r0, r0, #1
	subs r7, r0, r1
	movs r1, #0xff
	ands r7, r1
	ldr r2, _080D2F90 @ =0x085B0A08
	adds r0, r7, #0
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r8, r0
	movs r0, #0xfa
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	mov sb, r4
	mov r8, r3
	mov ip, r2
	cmp r0, #0
	blt _080D2F94
	asrs r1, r0, #0xc
	b _080D2F9A
	.align 2, 0
_080D2F8C: .4byte 0x0000038E
_080D2F90: .4byte 0x085B0A08
_080D2F94:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D2F9A:
	adds r2, r6, #0
	adds r2, #0xa2
	ldrh r0, [r2]
	adds r0, r0, r1
	adds r3, r6, #0
	adds r3, #0x9a
	strh r0, [r3]
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xfa
	muls r0, r1, r0
	str r2, [sp, #0xc]
	cmp r0, #0
	blt _080D2FC6
	asrs r0, r0, #0xc
	b _080D2FCC
_080D2FC6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D2FCC:
	mov sl, r0
	adds r2, r6, #0
	adds r2, #0xc4
	ldrb r0, [r2]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r4, #0
	ldrsh r0, [r0, r4]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	adds r4, r2, #0
	cmp r0, #0
	blt _080D2FF2
	asrs r1, r0, #0xc
	b _080D2FF8
_080D2FF2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D2FF8:
	adds r2, r6, #0
	adds r2, #0xa0
	ldrh r0, [r2]
	adds r0, r0, r1
	adds r1, r6, #0
	adds r1, #0x98
	strh r0, [r1]
	ldrb r0, [r4]
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r3, sl
	muls r3, r0, r3
	adds r0, r3, #0
	mov sl, r2
	mov ip, r1
	cmp r0, #0
	blt _080D3022
	asrs r1, r0, #0xc
	b _080D3028
_080D3022:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D3028:
	adds r2, r6, #0
	adds r2, #0xa4
	ldrh r0, [r2]
	adds r0, r0, r1
	adds r1, r6, #0
	adds r1, #0x9c
	strh r0, [r1]
	mov r0, sb
	ldrh r1, [r0]
	mov r3, r8
	ldrh r0, [r3]
	adds r0, #2
	str r2, [sp, #0x10]
	cmp r1, r0
	ble _080D3060
	adds r1, r6, #0
	adds r1, #0xc5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _080D3060
	ldrb r3, [r4]
	str r0, [sp]
	adds r0, r5, #0
	mov r1, ip
	adds r2, r7, #0
	bl FUN_080d2d48
_080D3060:
	mov r7, sb
	ldrh r3, [r7]
	mov r1, r8
	ldrh r0, [r1]
	adds r2, r6, #0
	adds r2, #0xbc
	ldrh r1, [r2]
	adds r0, r0, r1
	subs r0, #2
	adds r7, r2, #0
	cmp r3, r0
	bgt _080D307A
	b _080D2EFA
_080D307A:
	movs r3, #0xaa
	ldr r2, _080D309C @ =0x085B0A08
	ldrb r0, [r4]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	mov ip, r2
	cmp r0, #0
	blt _080D30A0
	asrs r0, r0, #0xc
	b _080D30A6
	.align 2, 0
_080D309C: .4byte 0x085B0A08
_080D30A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D30A6:
	mov r1, sl
	ldrh r2, [r1]
	adds r2, r2, r0
	lsls r2, r2, #0x10
	mov r1, r8
	ldrh r0, [r1]
	ldrh r1, [r7]
	adds r0, r0, r1
	mov r7, sb
	ldrh r1, [r7]
	subs r0, r0, r1
	adds r0, #1
	movs r1, #0x5a
	muls r0, r1, r0
	ldr r1, [sp, #0xc]
	ldrh r1, [r1]
	adds r0, r0, r1
	ldr r7, _080D30E8 @ =0xFFFFFEFC
	adds r0, r0, r7
	lsls r0, r0, #0x10
	lsrs r2, r2, #0x10
	orrs r2, r0
	str r2, [sp, #4]
	ldrb r0, [r4]
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D30EC
	asrs r0, r0, #0xc
	b _080D30F2
	.align 2, 0
_080D30E8: .4byte 0xFFFFFEFC
_080D30EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D30F2:
	ldr r2, [sp, #0x10]
	ldrh r1, [r2]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D3138 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	adds r0, r6, #0
	adds r0, #0xc5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080D311E
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r5, #0x20]
	orrs r0, r1
	str r0, [r5, #0x20]
_080D311E:
	movs r3, #0xa1
	lsls r3, r3, #4
	adds r0, r5, r3
	add r1, sp, #4
	movs r2, #0
	bl FUN_082364c4
	adds r0, r6, #0
	adds r0, #0x48
	bl FUN_08236400
	b _080D2EFA
	.align 2, 0
_080D3138: .4byte 0xFFFF0000
_080D313C:
	ldr r4, _080D316C @ =0x00000A86
	adds r0, r5, r4
	ldrh r0, [r0]
	adds r0, r1, r0
	cmp r2, r0
	bgt _080D3174
	ldr r7, _080D3170 @ =0x00000A8D
	adds r0, r5, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080D3160
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r5, #0x20]
	orrs r0, r1
	str r0, [r5, #0x20]
_080D3160:
	movs r1, #0xa1
	lsls r1, r1, #4
	adds r0, r5, r1
	bl FUN_08236400
	b _080D2EFA
	.align 2, 0
_080D316C: .4byte 0x00000A86
_080D3170: .4byte 0x00000A8D
_080D3174:
	movs r0, #0
	strh r0, [r3]
	movs r0, #1
_080D317A:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d318c
FUN_080d318c: @ 0x080D318C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D31AE
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D31B2
_080D31AE:
	movs r5, #0x30
	b _080D31B4
_080D31B2:
	movs r5, #0x40
_080D31B4:
	ldr r1, _080D31C8 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D31FC
	cmp r0, #1
	bgt _080D31CC
	cmp r0, #0
	beq _080D31D6
	b _080D3330
	.align 2, 0
_080D31C8: .4byte 0x0000037D
_080D31CC:
	cmp r0, #4
	beq _080D3254
	cmp r0, #5
	beq _080D3290
	b _080D3330
_080D31D6:
	adds r0, r4, #0
	bl FUN_080d1a44
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0x1d
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_080cc1e8
	cmp r0, #0
	bne _080D31FA
	b _080D3330
_080D31FA:
	b _080D330E
_080D31FC:
	adds r0, r4, #0
	bl FUN_080d1a44
	adds r0, r4, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x1e
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_080cc1e8
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D3244
	adds r0, r4, #0
	bl FUN_080d2c00
	adds r0, r4, #0
	movs r1, #3
	movs r2, #4
	bl FUN_080cc348
	b _080D3330
_080D3244:
	ldr r0, _080D3250 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _080D3330
	.align 2, 0
_080D3250: .4byte 0x0000037E
_080D3254:
	ldr r2, _080D328C @ =0x000003D1
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x1f
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_080cc1e8
	adds r0, r4, #0
	bl FUN_080d2ed0
	cmp r0, #0
	beq _080D3330
	adds r0, r4, #0
	movs r1, #3
	movs r2, #5
	bl FUN_080cc348
	b _080D3330
	.align 2, 0
_080D328C: .4byte 0x000003D1
_080D3290:
	ldr r2, _080D331C @ =0x000003D1
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D32B2
	ldr r2, _080D3320 @ =0x00000A76
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
_080D32B2:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D32E4
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D32E4
	adds r0, r4, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D32E4
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x2c
	adds r0, r4, #0
	bl FUN_080ccd5c
_080D32E4:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x1f
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D3330
	ldr r2, _080D3320 @ =0x00000A76
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _080D3324
	movs r0, #0
	strb r0, [r1]
_080D330E:
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	bl FUN_080cc348
	b _080D3330
	.align 2, 0
_080D331C: .4byte 0x000003D1
_080D3320: .4byte 0x00000A76
_080D3324:
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D3330:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d3338
FUN_080d3338: @ 0x080D3338
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080D33C0 @ =0x00000A68
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080D33C4 @ =0x00000A6A
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #0xe6
	movs r3, #0
	mov r8, r3
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r2, #0x22
	adds r6, r4, r2
	strb r0, [r6]
	adds r0, r4, #0
	bl FUN_080d1b04
	adds r5, r0, #0
	ldr r3, _080D33C8 @ =0x000009F4
	adds r0, r4, r3
	movs r1, #0x2d
	bl FUN_0822b20c
	movs r1, #0xa1
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r2, _080D33CC @ =0x00000A7C
	adds r1, r4, r2
	ldrh r2, [r1]
	mov r3, r8
	str r3, [sp]
	ldr r3, _080D33D0 @ =0x00000A7E
	adds r1, r4, r3
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r1, r5, #0
	movs r3, #8
	bl FUN_082364f8
	ldrb r1, [r6]
	ldr r2, _080D33D4 @ =0x00000A52
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080D33D8 @ =0x00000A8A
	adds r4, r4, r3
	mov r0, r8
	strh r0, [r4]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D33C0: .4byte 0x00000A68
_080D33C4: .4byte 0x00000A6A
_080D33C8: .4byte 0x000009F4
_080D33CC: .4byte 0x00000A7C
_080D33D0: .4byte 0x00000A7E
_080D33D4: .4byte 0x00000A52
_080D33D8: .4byte 0x00000A8A

	thumb_func_start FUN_080d33dc
FUN_080d33dc: @ 0x080D33DC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _080D3428 @ =0x000009C8
	adds r5, r6, r0
	ldr r1, _080D342C @ =0x00000A8A
	adds r4, r6, r1
	ldrh r0, [r4]
	cmp r0, #0
	bne _080D33F6
	ldr r0, [r6, #0x18]
	ldr r1, _080D3430 @ =0x00000391
	bl FUN_080cc3e4
_080D33F6:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _080D34A6
	ldr r2, _080D3434 @ =0x085B0A08
	ldr r3, _080D3438 @ =0x00000A8C
	adds r0, r6, r3
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x64
	muls r0, r1, r0
	cmp r0, #0
	blt _080D343C
	asrs r1, r0, #0xc
	b _080D3442
	.align 2, 0
_080D3428: .4byte 0x000009C8
_080D342C: .4byte 0x00000A8A
_080D3430: .4byte 0x00000391
_080D3434: .4byte 0x085B0A08
_080D3438: .4byte 0x00000A8C
_080D343C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D3442:
	adds r0, r5, #0
	adds r0, #0xa0
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x98
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	adds r1, #2
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xc4
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x64
	muls r0, r1, r0
	cmp r0, #0
	blt _080D3474
	asrs r1, r0, #0xc
	b _080D347A
_080D3474:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D347A:
	adds r0, r5, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	movs r3, #0xa1
	lsls r3, r3, #4
	adds r4, r6, r3
	movs r0, #0xa6
	lsls r0, r0, #4
	adds r1, r6, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	movs r0, #0
	b _080D34AC
_080D34A6:
	movs r0, #0
	strh r0, [r4]
	movs r0, #1
_080D34AC:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d34b4
FUN_080d34b4: @ 0x080D34B4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080D34D0 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #6
	bls _080D34C4
	b _080D369C
_080D34C4:
	lsls r0, r0, #2
	ldr r1, _080D34D4 @ =_080D34D8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D34D0: .4byte 0x0000037D
_080D34D4: .4byte _080D34D8
_080D34D8: @ jump table
	.4byte _080D34F4 @ case 0
	.4byte _080D3530 @ case 1
	.4byte _080D369C @ case 2
	.4byte _080D369C @ case 3
	.4byte _080D3584 @ case 4
	.4byte _080D35DC @ case 5
	.4byte _080D3660 @ case 6
_080D34F4:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x20
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	bne _080D3512
	b _080D369C
_080D3512:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D3560
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	bl FUN_080cc348
	b _080D369C
_080D3530:
	adds r0, r4, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x21
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D3572
_080D3560:
	adds r0, r4, #0
	bl FUN_080d3338
	adds r0, r4, #0
	movs r1, #3
	movs r2, #4
	bl FUN_080cc348
	b _080D369C
_080D3572:
	ldr r0, _080D3580 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _080D369C
	.align 2, 0
_080D3580: .4byte 0x0000037E
_080D3584:
	ldr r0, _080D35D4 @ =0x000003D1
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x22
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D35BE
	ldr r0, _080D35D8 @ =0x00000A76
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_080D35BE:
	adds r0, r4, #0
	bl FUN_080d33dc
	cmp r0, #0
	beq _080D369C
	adds r0, r4, #0
	movs r1, #3
	movs r2, #5
	bl FUN_080cc348
	b _080D369C
	.align 2, 0
_080D35D4: .4byte 0x000003D1
_080D35D8: .4byte 0x00000A76
_080D35DC:
	ldr r1, _080D362C @ =0x000003D1
	adds r0, r4, r1
	movs r5, #0
	strb r5, [r0]
	subs r1, #0x79
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x21
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D3614
	ldr r0, _080D3630 @ =0x00000A76
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_080D3614:
	ldr r1, _080D3630 @ =0x00000A76
	adds r2, r4, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080D3638
	strb r5, [r2]
	ldr r0, _080D3634 @ =0x0000037D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _080D369C
	.align 2, 0
_080D362C: .4byte 0x000003D1
_080D3630: .4byte 0x00000A76
_080D3634: .4byte 0x0000037D
_080D3638:
	ldr r0, _080D365C @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bls _080D369C
	movs r0, #0
	strb r0, [r2]
	adds r0, r4, #0
	movs r1, #3
	movs r2, #6
	bl FUN_080cc348
	b _080D369C
	.align 2, 0
_080D365C: .4byte 0x0000037E
_080D3660:
	ldr r0, _080D36A4 @ =0x000003D1
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x20
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r0, _080D36A8 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _080D369C
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D369C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D36A4: .4byte 0x000003D1
_080D36A8: .4byte 0x0000037E

	thumb_func_start FUN_080d36ac
FUN_080d36ac: @ 0x080D36AC
	push {r4, r5, r6, lr}
	sub sp, #0x30
	adds r5, r0, #0
	ldr r1, _080D36C8 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #7
	bls _080D36BE
	b _080D3AD8
_080D36BE:
	lsls r0, r0, #2
	ldr r1, _080D36CC @ =_080D36D0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D36C8: .4byte 0x0000037D
_080D36CC: .4byte _080D36D0
_080D36D0: @ jump table
	.4byte _080D36F0 @ case 0
	.4byte _080D371A @ case 1
	.4byte _080D37F6 @ case 2
	.4byte _080D3AD8 @ case 3
	.4byte _080D38A8 @ case 4
	.4byte _080D38FC @ case 5
	.4byte _080D3A28 @ case 6
	.4byte _080D3AA4 @ case 7
_080D36F0:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x23
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	bne _080D370E
	b _080D3AD8
_080D370E:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_080cc348
	b _080D3AD8
_080D371A:
	ldr r0, _080D377C @ =0x0000037E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080D372C
	ldr r0, [r5, #0x18]
	ldr r1, _080D3780 @ =0x000001F7
	bl FUN_080cc3e4
_080D372C:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bhi _080D375A
	b _080D3AD8
_080D375A:
	ldr r2, _080D3784 @ =0x00000A8F
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	ldr r0, _080D3788 @ =0x000003E6
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x18
	bhi _080D378C
	ldr r0, [r5, #0x18]
	movs r1, #0xd5
	b _080D38E8
	.align 2, 0
_080D377C: .4byte 0x0000037E
_080D3780: .4byte 0x000001F7
_080D3784: .4byte 0x00000A8F
_080D3788: .4byte 0x000003E6
_080D378C:
	ldr r2, _080D37BC @ =0x00000A92
	adds r1, r5, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D37C0
	ldr r0, [r5, #0x18]
	movs r1, #0xcd
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_080cc348
	b _080D37CA
	.align 2, 0
_080D37BC: .4byte 0x00000A92
_080D37C0:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #2
	bl FUN_080cc348
_080D37CA:
	movs r1, #0x20
	str r1, [sp]
	movs r0, #0x2c
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	movs r0, #0x1e
	str r0, [sp, #0x10]
	movs r0, #3
	str r0, [sp, #0x14]
	movs r0, #0x19
	str r0, [sp, #0x18]
	movs r0, #0
	str r0, [sp, #0x1c]
	adds r0, r5, #0
	movs r1, #0xe6
	movs r2, #0xb4
	movs r3, #0
	bl FUN_08080be8
	b _080D3AD8
_080D37F6:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r0, _080D388C @ =0x00000A92
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r1, _080D3890 @ =0x0000037E
	adds r4, r5, r1
	ldrh r0, [r4]
	cmp r0, #6
	bne _080D3832
	ldr r0, [r5, #0x18]
	movs r1, #0xfc
	lsls r1, r1, #1
	bl FUN_080cc3e4
_080D3832:
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D38E4
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bhi _080D3854
	b _080D3AD8
_080D3854:
	ldr r0, _080D3894 @ =0x00000A8F
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _080D3898 @ =0x000003E6
	adds r1, r5, r2
	movs r0, #0x1e
	strh r0, [r1]
	ldr r0, _080D389C @ =0x0000095E
	adds r1, r5, r0
	ldr r0, _080D38A0 @ =0x00000121
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x24
	strh r0, [r1]
	ldr r0, [r5, #0x18]
	ldr r1, _080D38A4 @ =0x000001F9
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_080cc348
	b _080D3AD8
	.align 2, 0
_080D388C: .4byte 0x00000A92
_080D3890: .4byte 0x0000037E
_080D3894: .4byte 0x00000A8F
_080D3898: .4byte 0x000003E6
_080D389C: .4byte 0x0000095E
_080D38A0: .4byte 0x00000121
_080D38A4: .4byte 0x000001F9
_080D38A8:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r2, _080D38F8 @ =0x00000A92
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D38E4
	b _080D3AD8
_080D38E4:
	ldr r0, [r5, #0x18]
	movs r1, #0xcd
_080D38E8:
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_080cc348
	b _080D3AD8
	.align 2, 0
_080D38F8: .4byte 0x00000A92
_080D38FC:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x25
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D392E
	ldr r2, _080D39A8 @ =0x00000A76
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_080D392E:
	ldr r0, _080D39AC @ =0x000003E6
	adds r6, r5, r0
	ldrh r0, [r6]
	cmp r0, #0
	beq _080D3A04
	cmp r0, #5
	bls _080D397A
	ldr r3, _080D39B0 @ =0xFFFF0000
	ldr r1, _080D39B4 @ =0x0000FFFF
	movs r0, #0
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x24]
	ands r0, r3
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x28]
	ands r0, r3
	movs r4, #0x20
	orrs r0, r4
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r4
	str r0, [r2, #4]
	adds r0, r5, #0
	adds r0, #0x2c
	movs r1, #3
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	add r1, sp, #0x20
	movs r3, #1
	bl FUN_080dbd08
_080D397A:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldrh r3, [r6]
	ldr r2, _080D39B8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D39BC
	asrs r0, r0, #0xc
	b _080D39C2
	.align 2, 0
_080D39A8: .4byte 0x00000A76
_080D39AC: .4byte 0x000003E6
_080D39B0: .4byte 0xFFFF0000
_080D39B4: .4byte 0x0000FFFF
_080D39B8: .4byte 0x085B0A08
_080D39BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D39C2:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	ldr r1, _080D39E0 @ =0x000003E6
	adds r0, r5, r1
	ldrh r1, [r0]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D39E4
	asrs r0, r0, #0xc
	b _080D39EA
	.align 2, 0
_080D39E0: .4byte 0x000003E6
_080D39E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D39EA:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
	ldr r0, _080D3A00 @ =0x000003E6
	adds r2, r5, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _080D3AD8
	.align 2, 0
_080D3A00: .4byte 0x000003E6
_080D3A04:
	ldr r2, _080D3A24 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _080D3AD8
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_080cc348
	b _080D3AD8
	.align 2, 0
_080D3A24: .4byte 0x0000037E
_080D3A28:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D3A5A
	ldr r0, _080D3A74 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080D3A5A:
	ldr r1, _080D3A74 @ =0x00000A76
	adds r2, r5, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080D3A7C
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080D3A78 @ =0x0000037D
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _080D3AD8
	.align 2, 0
_080D3A74: .4byte 0x00000A76
_080D3A78: .4byte 0x0000037D
_080D3A7C:
	ldr r0, _080D3AA0 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _080D3AD8
	movs r0, #0
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #7
	bl FUN_080cc348
	b _080D3AD8
	.align 2, 0
_080D3AA0: .4byte 0x0000037E
_080D3AA4:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x23
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r2, _080D3B08 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _080D3AD8
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D3AD8:
	ldr r0, _080D3B0C @ =0x00000A92
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0xe
	bls _080D3AF8
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D3AF4
	adds r0, r5, #0
	bl FUN_080cf684
_080D3AF4:
	movs r0, #0
	strh r0, [r4]
_080D3AF8:
	ldr r2, _080D3B10 @ =0x00000951
	adds r1, r5, r2
	movs r0, #8
	strb r0, [r1]
	add sp, #0x30
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D3B08: .4byte 0x0000037E
_080D3B0C: .4byte 0x00000A92
_080D3B10: .4byte 0x00000951

	thumb_func_start FUN_080d3b14
FUN_080d3b14: @ 0x080D3B14
	push {r4, r5, r6, lr}
	sub sp, #0x30
	adds r5, r0, #0
	ldr r1, _080D3B30 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #7
	bls _080D3B26
	b _080D3F04
_080D3B26:
	lsls r0, r0, #2
	ldr r1, _080D3B34 @ =_080D3B38
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D3B30: .4byte 0x0000037D
_080D3B34: .4byte _080D3B38
_080D3B38: @ jump table
	.4byte _080D3B58 @ case 0
	.4byte _080D3B82 @ case 1
	.4byte _080D3C3C @ case 2
	.4byte _080D3F04 @ case 3
	.4byte _080D3CE0 @ case 4
	.4byte _080D3D28 @ case 5
	.4byte _080D3E54 @ case 6
	.4byte _080D3ED0 @ case 7
_080D3B58:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x26
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	bne _080D3B76
	b _080D3F04
_080D3B76:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_080cc348
	b _080D3F04
_080D3B82:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r2, _080D3BD8 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bhi _080D3BB4
	b _080D3F04
_080D3BB4:
	ldr r0, _080D3BDC @ =0x00000A8F
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	adds r2, #0x68
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x13
	bhi _080D3BE0
	ldr r0, [r5, #0x18]
	movs r1, #0xd5
	b _080D3D18
	.align 2, 0
_080D3BD8: .4byte 0x0000037E
_080D3BDC: .4byte 0x00000A8F
_080D3BE0:
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D3C08
	ldr r0, [r5, #0x18]
	movs r1, #0xfb
	lsls r1, r1, #1
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_080cc348
	b _080D3C12
_080D3C08:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_080cc348
_080D3C12:
	movs r1, #0x20
	str r1, [sp]
	movs r0, #0x2e
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r1, #0
	str r1, [sp, #0xc]
	movs r0, #0x1e
	str r0, [sp, #0x10]
	movs r0, #0x11
	str r0, [sp, #0x14]
	movs r0, #0x14
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	adds r0, r5, #0
	movs r1, #0xc8
	movs r2, #0xaa
	movs r3, #8
	bl FUN_08080be8
	b _080D3F04
_080D3C3C:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r2, _080D3CC8 @ =0x0000037E
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #6
	bne _080D3C6E
	ldr r0, [r5, #0x18]
	movs r1, #0xfa
	lsls r1, r1, #1
	bl FUN_080cc3e4
_080D3C6E:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D3D12
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bhi _080D3C90
	b _080D3F04
_080D3C90:
	ldr r2, _080D3CCC @ =0x00000A8F
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080D3CD0 @ =0x000003E6
	adds r1, r5, r0
	movs r0, #0x1e
	strh r0, [r1]
	ldr r2, _080D3CD4 @ =0x0000095E
	adds r1, r5, r2
	ldr r0, _080D3CD8 @ =0x00000121
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #0x24
	strh r0, [r1]
	ldr r0, [r5, #0x18]
	ldr r1, _080D3CDC @ =0x000001F5
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_080cc348
	b _080D3F04
	.align 2, 0
_080D3CC8: .4byte 0x0000037E
_080D3CCC: .4byte 0x00000A8F
_080D3CD0: .4byte 0x000003E6
_080D3CD4: .4byte 0x0000095E
_080D3CD8: .4byte 0x00000121
_080D3CDC: .4byte 0x000001F5
_080D3CE0:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D3D12
	b _080D3F04
_080D3D12:
	ldr r0, [r5, #0x18]
	movs r1, #0xfb
	lsls r1, r1, #1
_080D3D18:
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_080cc348
	b _080D3F04
_080D3D28:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x28
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D3D5A
	ldr r0, _080D3DD4 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080D3D5A:
	ldr r1, _080D3DD8 @ =0x000003E6
	adds r6, r5, r1
	ldrh r0, [r6]
	cmp r0, #0
	beq _080D3E30
	cmp r0, #5
	bls _080D3DA6
	ldr r3, _080D3DDC @ =0xFFFF0000
	ldr r1, _080D3DE0 @ =0x0000FFFF
	movs r0, #0
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x24]
	ands r0, r3
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x28]
	ands r0, r3
	movs r4, #0x20
	orrs r0, r4
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r4
	str r0, [r2, #4]
	adds r0, r5, #0
	adds r0, #0x2c
	movs r1, #3
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	add r1, sp, #0x20
	movs r3, #1
	bl FUN_080dbd08
_080D3DA6:
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldrh r3, [r6]
	ldr r2, _080D3DE4 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D3DE8
	asrs r0, r0, #0xc
	b _080D3DEE
	.align 2, 0
_080D3DD4: .4byte 0x00000A76
_080D3DD8: .4byte 0x000003E6
_080D3DDC: .4byte 0xFFFF0000
_080D3DE0: .4byte 0x0000FFFF
_080D3DE4: .4byte 0x085B0A08
_080D3DE8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D3DEE:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	ldr r1, _080D3E0C @ =0x000003E6
	adds r0, r5, r1
	ldrh r1, [r0]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D3E10
	asrs r0, r0, #0xc
	b _080D3E16
	.align 2, 0
_080D3E0C: .4byte 0x000003E6
_080D3E10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D3E16:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
	ldr r0, _080D3E2C @ =0x000003E6
	adds r2, r5, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _080D3F04
	.align 2, 0
_080D3E2C: .4byte 0x000003E6
_080D3E30:
	ldr r2, _080D3E50 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _080D3F04
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_080cc348
	b _080D3F04
	.align 2, 0
_080D3E50: .4byte 0x0000037E
_080D3E54:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D3E86
	ldr r0, _080D3EA0 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080D3E86:
	ldr r1, _080D3EA0 @ =0x00000A76
	adds r2, r5, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080D3EA8
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080D3EA4 @ =0x0000037D
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _080D3F04
	.align 2, 0
_080D3EA0: .4byte 0x00000A76
_080D3EA4: .4byte 0x0000037D
_080D3EA8:
	ldr r0, _080D3ECC @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _080D3F04
	movs r0, #0
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #7
	bl FUN_080cc348
	b _080D3F04
	.align 2, 0
_080D3ECC: .4byte 0x0000037E
_080D3ED0:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x26
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r2, _080D3F14 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _080D3F04
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D3F04:
	ldr r0, _080D3F18 @ =0x00000951
	adds r1, r5, r0
	movs r0, #4
	strb r0, [r1]
	add sp, #0x30
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D3F14: .4byte 0x0000037E
_080D3F18: .4byte 0x00000951

	thumb_func_start FUN_080d3f1c
FUN_080d3f1c: @ 0x080D3F1C
	push {r4, r5, r6, lr}
	sub sp, #0x38
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D3F38
	adds r0, r5, #0
	movs r1, #3
	movs r2, #0
	bl FUN_080cc348
_080D3F38:
	ldr r2, _080D3F50 @ =0x0000037D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #8
	bls _080D3F44
	b _080D4462
_080D3F44:
	lsls r0, r0, #2
	ldr r1, _080D3F54 @ =_080D3F58
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D3F50: .4byte 0x0000037D
_080D3F54: .4byte _080D3F58
_080D3F58: @ jump table
	.4byte _080D3F7C @ case 0
	.4byte _080D3FA6 @ case 1
	.4byte _080D405E @ case 2
	.4byte _080D4462 @ case 3
	.4byte _080D410C @ case 4
	.4byte _080D419C @ case 5
	.4byte _080D41F8 @ case 6
	.4byte _080D4274 @ case 7
	.4byte _080D42B0 @ case 8
_080D3F7C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x23
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	bne _080D3F9A
	b _080D4462
_080D3F9A:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_080cc348
	b _080D4462
_080D3FA6:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r0, _080D3FF4 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bhi _080D3FD8
	b _080D4462
_080D3FD8:
	ldr r2, _080D3FF8 @ =0x00000A8F
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #9
	bhi _080D3FFC
	ldr r0, [r5, #0x18]
	movs r1, #0xd5
	b _080D40A6
	.align 2, 0
_080D3FF4: .4byte 0x0000037E
_080D3FF8: .4byte 0x00000A8F
_080D3FFC:
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D4028
	ldr r0, [r5, #0x18]
	ldr r1, _080D4024 @ =0x00000203
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_080cc348
	b _080D4032
	.align 2, 0
_080D4024: .4byte 0x00000203
_080D4028:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #2
	bl FUN_080cc348
_080D4032:
	movs r1, #0x20
	str r1, [sp]
	movs r0, #0x32
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	movs r0, #0x1e
	str r0, [sp, #0x10]
	movs r0, #5
	str r0, [sp, #0x14]
	movs r0, #0xa
	str r0, [sp, #0x18]
	movs r0, #0
	str r0, [sp, #0x1c]
	adds r0, r5, #0
	movs r1, #0xe6
	movs r2, #0xaa
	movs r3, #0
	bl FUN_08080be8
	b _080D4462
_080D405E:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r2, _080D40B8 @ =0x0000037E
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #6
	bne _080D4090
	ldr r0, [r5, #0x18]
	movs r1, #0xfc
	lsls r1, r1, #1
	bl FUN_080cc3e4
_080D4090:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D40C0
	ldr r0, [r5, #0x18]
	ldr r1, _080D40BC @ =0x00000203
_080D40A6:
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_080cc348
	b _080D4462
	.align 2, 0
_080D40B8: .4byte 0x0000037E
_080D40BC: .4byte 0x00000203
_080D40C0:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bhi _080D40D0
	b _080D4462
_080D40D0:
	ldr r2, _080D4100 @ =0x00000A8F
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080D4104 @ =0x0000095E
	adds r1, r5, r0
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x24
	strh r0, [r1]
	ldr r0, [r5, #0x18]
	ldr r1, _080D4108 @ =0x000001F9
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_080cc348
	b _080D4462
	.align 2, 0
_080D4100: .4byte 0x00000A8F
_080D4104: .4byte 0x0000095E
_080D4108: .4byte 0x000001F9
_080D410C:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080D4140
	b _080D4462
_080D4140:
	ldr r0, [r5, #0x18]
	ldr r1, _080D4190 @ =0x000002E9
	bl FUN_080cc3e4
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r0, #8
	subs r0, r0, r1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	ldr r2, _080D4194 @ =0x00000A8A
	adds r1, r5, r2
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080d1b04
	adds r1, r0, #0
	movs r2, #0xa1
	lsls r2, r2, #4
	adds r0, r5, r2
	str r4, [sp]
	movs r2, #0x1e
	str r2, [sp, #4]
	movs r2, #0x20
	movs r3, #0x10
	bl FUN_082364f8
	ldr r0, [r5, #0x18]
	ldr r1, _080D4198 @ =0x00000202
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #8
	bl FUN_080cc348
	b _080D4462
	.align 2, 0
_080D4190: .4byte 0x000002E9
_080D4194: .4byte 0x00000A8A
_080D4198: .4byte 0x00000202
_080D419C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x25
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D41CE
	ldr r0, _080D41F0 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080D41CE:
	ldr r2, _080D41F4 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _080D41E2
	b _080D4462
_080D41E2:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_080cc348
	b _080D4462
	.align 2, 0
_080D41F0: .4byte 0x00000A76
_080D41F4: .4byte 0x0000037E
_080D41F8:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D422A
	ldr r0, _080D4244 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080D422A:
	ldr r1, _080D4244 @ =0x00000A76
	adds r2, r5, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080D424C
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080D4248 @ =0x0000037D
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _080D4462
	.align 2, 0
_080D4244: .4byte 0x00000A76
_080D4248: .4byte 0x0000037D
_080D424C:
	ldr r0, _080D4270 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _080D4260
	b _080D4462
_080D4260:
	movs r0, #0
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #7
	bl FUN_080cc348
	b _080D4462
	.align 2, 0
_080D4270: .4byte 0x0000037E
_080D4274:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x23
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r2, _080D42AC @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _080D42A0
	b _080D4462
_080D42A0:
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
	b _080D4462
	.align 2, 0
_080D42AC: .4byte 0x0000037E
_080D42B0:
	ldr r1, _080D4358 @ =0x000003D1
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	adds r0, r5, #0
	bl FUN_080d19fc
	cmp r0, #0
	beq _080D42CA
	adds r0, r5, #0
	movs r1, #6
	bl FUN_080cc268
_080D42CA:
	ldr r2, _080D435C @ =0x0000037E
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r3, #3
	ands r3, r0
	adds r6, r5, #0
	adds r6, #0x2c
	cmp r3, #0
	bne _080D4310
	ldr r1, _080D4360 @ =0xFFFF0000
	ldr r2, _080D4364 @ =0x0000FFFF
	str r3, [sp, #0x20]
	ldr r0, [sp, #0x24]
	ands r0, r1
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x28]
	ands r0, r1
	movs r3, #0x20
	orrs r0, r3
	ands r0, r2
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r1
	orrs r0, r3
	str r0, [r2, #4]
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	add r1, sp, #0x20
	movs r3, #1
	bl FUN_080dbcec
_080D4310:
	ldr r0, _080D4368 @ =0x00000A8A
	adds r4, r5, r0
	ldrh r0, [r4]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4]
	ldrh r1, [r4]
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_080cce0c
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp, #0x30]
	str r1, [sp, #0x34]
	ldrh r1, [r4]
	movs r0, #0xd0
	lsls r0, r0, #1
	subs r6, r0, r1
	movs r1, #0xff
	ands r6, r1
	ldr r2, _080D436C @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xaa
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4370
	asrs r1, r0, #0xc
	b _080D4376
	.align 2, 0
_080D4358: .4byte 0x000003D1
_080D435C: .4byte 0x0000037E
_080D4360: .4byte 0xFFFF0000
_080D4364: .4byte 0x0000FFFF
_080D4368: .4byte 0x00000A8A
_080D436C: .4byte 0x085B0A08
_080D4370:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D4376:
	add r3, sp, #0x30
	ldrh r0, [r3]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D43AC @ =0xFFFF0000
	ldr r2, [sp, #0x30]
	ands r2, r1
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0xe6
	lsls r1, r1, #0x10
	ldr r0, _080D43B0 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x30]
	ldr r1, _080D43B4 @ =0x085B0A08
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xaa
	muls r0, r1, r0
	cmp r0, #0
	blt _080D43B8
	asrs r0, r0, #0xc
	b _080D43BE
	.align 2, 0
_080D43AC: .4byte 0xFFFF0000
_080D43B0: .4byte 0x0000FFFF
_080D43B4: .4byte 0x085B0A08
_080D43B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D43BE:
	ldrh r1, [r3, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D4474 @ =0xFFFF0000
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
	movs r0, #0xa1
	lsls r0, r0, #4
	adds r4, r5, r0
	adds r0, r4, #0
	adds r1, r3, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _080D4478 @ =0x00000A52
	adds r0, r5, r1
	strb r6, [r0]
	adds r0, r4, #0
	bl FUN_08236400
	ldr r2, _080D447C @ =0x00000A8A
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r0, _080D4480 @ =0x0000010F
	subs r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r5, r2
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080cc1a0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x25
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r2, _080D4484 @ =0x0000037E
	adds r4, r5, r2
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _080D443A
	ldr r0, [r5, #0x18]
	movs r1, #0x81
	lsls r1, r1, #2
	bl FUN_080cc3e4
_080D443A:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080D4488 @ =0x00000A8F
	adds r1, r5, r2
	ldrb r1, [r1]
	lsls r1, r1, #5
	cmp r0, r1
	blt _080D4462
	ldr r0, [r5, #0x18]
	ldr r1, _080D448C @ =0x00000202
	bl FUN_080cc410
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_080cc348
_080D4462:
	ldr r0, _080D4490 @ =0x00000951
	adds r1, r5, r0
	movs r0, #9
	strb r0, [r1]
	add sp, #0x38
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D4474: .4byte 0xFFFF0000
_080D4478: .4byte 0x00000A52
_080D447C: .4byte 0x00000A8A
_080D4480: .4byte 0x0000010F
_080D4484: .4byte 0x0000037E
_080D4488: .4byte 0x00000A8F
_080D448C: .4byte 0x00000202
_080D4490: .4byte 0x00000951

	thumb_func_start FUN_080d4494
FUN_080d4494: @ 0x080D4494
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D44AE
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	bl FUN_080cc348
_080D44AE:
	ldr r1, _080D44C0 @ =0x00000A98
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D44C0: .4byte 0x00000A98

	thumb_func_start FUN_080d44c4
FUN_080d44c4: @ 0x080D44C4
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _080D4528
	movs r2, #0xe4
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D44F0
	ldr r0, _080D44EC @ =0x000003FA
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	b _080D451E
	.align 2, 0
_080D44EC: .4byte 0x000003FA
_080D44F0:
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080ced68
	adds r1, r0, #0
	cmp r1, #0
	beq _080D4518
	ldr r1, _080D4514 @ =0x000003FA
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x2c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080a8ff8
	b _080D451E
	.align 2, 0
_080D4514: .4byte 0x000003FA
_080D4518:
	ldr r2, _080D453C @ =0x000003FA
	adds r0, r4, r2
	strb r1, [r0]
_080D451E:
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #0
	bl FUN_080cc348
_080D4528:
	ldr r1, _080D4540 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D45A4
	cmp r0, #1
	bgt _080D4544
	cmp r0, #0
	beq _080D454E
	b _080D4630
	.align 2, 0
_080D453C: .4byte 0x000003FA
_080D4540: .4byte 0x0000037D
_080D4544:
	cmp r0, #2
	beq _080D45DC
	cmp r0, #3
	beq _080D4618
	b _080D4630
_080D454E:
	ldr r2, _080D458C @ =0x000003FA
	adds r5, r4, r2
	ldrb r0, [r5]
	cmp r0, #0
	beq _080D456A
	ldr r0, _080D4590 @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _080D4594 @ =0x00000123
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #0x20
	strh r0, [r1]
_080D456A:
	adds r0, r4, #0
	movs r1, #0xb8
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D4630
	ldrb r0, [r5]
	cmp r0, #0
	beq _080D4598
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #1
	bl FUN_080cc348
	b _080D4630
	.align 2, 0
_080D458C: .4byte 0x000003FA
_080D4590: .4byte 0x0000095E
_080D4594: .4byte 0x00000123
_080D4598:
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #2
	bl FUN_080cc348
	b _080D4630
_080D45A4:
	ldr r1, _080D45CC @ =0x000003FA
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D45C0
	ldr r2, _080D45D0 @ =0x0000095E
	adds r1, r4, r2
	ldr r0, _080D45D4 @ =0x00000123
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
_080D45C0:
	ldr r2, _080D45D8 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _080D4600
	.align 2, 0
_080D45CC: .4byte 0x000003FA
_080D45D0: .4byte 0x0000095E
_080D45D4: .4byte 0x00000123
_080D45D8: .4byte 0x0000037E
_080D45DC:
	ldr r0, _080D4614 @ =0x0000037E
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _080D45F0
	ldr r0, [r4, #0x18]
	movs r1, #0xc9
	lsls r1, r1, #1
	bl FUN_080cc3e4
_080D45F0:
	adds r0, r4, #0
	movs r1, #0xc2
	movs r2, #0x40
	bl FUN_080cc1e8
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_080D4600:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _080D4630
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #3
	bl FUN_080cc348
	b _080D4630
	.align 2, 0
_080D4614: .4byte 0x0000037E
_080D4618:
	adds r0, r4, #0
	movs r1, #0xbd
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D4630
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl FUN_080cc348
_080D4630:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d4638
FUN_080d4638: @ 0x080D4638
	push {r4, r5, lr}
	sub sp, #0x14
	adds r4, r0, #0
	movs r1, #4
	bl FUN_080cc3c4
	ldr r1, _080D465C @ =0x0000037D
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, #1
	bne _080D4650
	b _080D475C
_080D4650:
	cmp r5, #1
	bgt _080D4660
	cmp r5, #0
	beq _080D466E
	b _080D4820
	.align 2, 0
_080D465C: .4byte 0x0000037D
_080D4660:
	cmp r5, #2
	bne _080D4666
	b _080D479C
_080D4666:
	cmp r5, #3
	bne _080D466C
	b _080D4810
_080D466C:
	b _080D4820
_080D466E:
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r2, [sp, #0xc]
	asrs r1, r2, #0x10
	adds r1, #0x96
	lsls r1, r1, #0x10
	ldr r0, _080D46B4 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	bl FUN_0823bac8
	movs r2, #0xfc
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D46BC
	movs r0, #4
	str r0, [sp]
	ldr r0, _080D46B8 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #0x10
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #3
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	b _080D46D4
	.align 2, 0
_080D46B4: .4byte 0x0000FFFF
_080D46B8: .4byte 0x00001FFF
_080D46BC:
	movs r0, #4
	str r0, [sp]
	ldr r0, _080D4704 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #3
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_080D46D4:
	ldr r0, [r4, #0x18]
	ldr r1, _080D4708 @ =0x000001AD
	bl FUN_080cc3e4
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D4714
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080D470C @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _080D4710 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _080D4724
	.align 2, 0
_080D4704: .4byte 0x00001FFF
_080D4708: .4byte 0x000001AD
_080D470C: .4byte 0x000002E6
_080D4710: .4byte 0x000002E7
_080D4714:
	lsrs r1, r1, #0x19
	ldr r2, _080D4750 @ =0x000002E6
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r1, _080D4754 @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
_080D4724:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #1
	bl FUN_080cc348
	ldr r0, _080D4758 @ =0x000003F6
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	b _080D4820
	.align 2, 0
_080D4750: .4byte 0x000002E6
_080D4754: .4byte 0x000002E7
_080D4758: .4byte 0x000003F6
_080D475C:
	ldr r2, _080D4794 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080D4820
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #2
	bl FUN_080cc348
	ldr r0, _080D4798 @ =0x000003F6
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xef
	strb r5, [r0]
	ldr r0, [r4, #0x18]
	movs r1, #0xd7
	lsls r1, r1, #1
	bl FUN_080cc3e4
	b _080D4820
	.align 2, 0
_080D4794: .4byte 0x0000037E
_080D4798: .4byte 0x000003F6
_080D479C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r5, r4, r1
	ldrb r0, [r5]
	movs r1, #0x12
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r2, _080D47D8 @ =0x000003F6
	adds r1, r4, r2
	ldrh r0, [r1]
	subs r0, #0x3c
	strh r0, [r1]
	ldr r1, _080D47DC @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #4
	bne _080D47E8
	ldrb r0, [r5]
	cmp r0, #5
	bne _080D47E0
	ldr r0, [r4, #0x18]
	subs r1, #0x91
	bl FUN_080cc3e4
	b _080D47E8
	.align 2, 0
_080D47D8: .4byte 0x000003F6
_080D47DC: .4byte 0x0000037E
_080D47E0:
	ldr r0, [r4, #0x18]
	ldr r1, _080D4808 @ =0x00000305
	bl FUN_080cc3e4
_080D47E8:
	ldr r2, _080D480C @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _080D4820
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #3
	bl FUN_080cc348
	b _080D4820
	.align 2, 0
_080D4808: .4byte 0x00000305
_080D480C: .4byte 0x0000037E
_080D4810:
	ldr r0, _080D4828 @ =0x000003F6
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080cc3c4
_080D4820:
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D4828: .4byte 0x000003F6

	thumb_func_start FUN_080d482c
FUN_080d482c: @ 0x080D482C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _080D48B6
	adds r0, r4, #0
	movs r1, #0x18
	movs r2, #0
	bl FUN_080cc348
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D4878
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r6, _080D4870 @ =0x000002E6
	adds r1, r4, r6
	strb r0, [r1]
	ldr r0, _080D4874 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _080D4888
	.align 2, 0
_080D4870: .4byte 0x000002E6
_080D4874: .4byte 0x000002E7
_080D4878:
	lsrs r1, r1, #0x19
	ldr r2, _080D48F4 @ =0x000002E6
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _080D48F8 @ =0x000002E7
	adds r0, r4, r3
	strb r2, [r0]
_080D4888:
	movs r6, #0xd6
	lsls r6, r6, #2
	adds r0, r4, r6
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r0, _080D48FC @ =0x000003D6
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	beq _080D48B6
	ldr r0, [r4, #0x18]
	ldrh r1, [r5]
	bl FUN_080cc3e4
	movs r0, #0
	strh r0, [r5]
_080D48B6:
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r3, r4, r1
	ldrh r0, [r3]
	cmp r0, #0
	bne _080D48C4
	b _080D49CA
_080D48C4:
	ldr r2, _080D4900 @ =0x00000395
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D4950
	movs r3, #0xe6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r2, [r0]
	movs r6, #0
	ldrsh r1, [r2, r6]
	movs r3, #0x2c
	ldrsh r0, [r4, r3]
	subs r3, r1, r0
	movs r6, #4
	ldrsh r1, [r2, r6]
	movs r2, #0x30
	ldrsh r0, [r4, r2]
	subs r1, r1, r0
	cmp r3, #0
	blt _080D4904
	asrs r0, r3, #3
	b _080D490A
	.align 2, 0
_080D48F4: .4byte 0x000002E6
_080D48F8: .4byte 0x000002E7
_080D48FC: .4byte 0x000003D6
_080D4900: .4byte 0x00000395
_080D4904:
	rsbs r0, r3, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080D490A:
	strh r0, [r4, #0x34]
	cmp r1, #0
	blt _080D4914
	asrs r0, r1, #3
	b _080D491A
_080D4914:
	rsbs r0, r1, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080D491A:
	strh r0, [r4, #0x38]
	ldr r3, _080D4948 @ =0x0000037E
	adds r5, r4, r3
	ldrh r1, [r5]
	cmp r1, #5
	bhi _080D49B2
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D493E
	ldr r0, [r4, #0x18]
	ldr r1, _080D494C @ =0x00000191
	bl FUN_080cc3e4
	adds r0, r4, #0
	adds r0, #0x2c
	bl FUN_080acd98
_080D493E:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	b _080D49B2
	.align 2, 0
_080D4948: .4byte 0x0000037E
_080D494C: .4byte 0x00000191
_080D4950:
	movs r6, #0xba
	lsls r6, r6, #2
	adds r0, r4, r6
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r2, _080D4980 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldrh r0, [r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4984
	asrs r0, r0, #0xc
	b _080D498A
	.align 2, 0
_080D4980: .4byte 0x085B0A08
_080D4984:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D498A:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D49A8
	asrs r0, r0, #0xc
	b _080D49AE
_080D49A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D49AE:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
_080D49B2:
	movs r6, #0xd6
	lsls r6, r6, #1
	adds r4, r4, r6
	ldrh r0, [r4]
	bl FUN_0823b9cc
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r4]
	b _080D4A2C
_080D49CA:
	movs r1, #0
	strh r0, [r3]
	ldr r2, _080D49F4 @ =0x00000395
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080D49F8 @ =0x000004C5
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D4A00
	ldr r6, _080D49FC @ =0x000004C7
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D4A00
	adds r0, r4, #0
	movs r1, #0x13
	movs r2, #0
	bl FUN_080cc348
	b _080D4A2C
	.align 2, 0
_080D49F4: .4byte 0x00000395
_080D49F8: .4byte 0x000004C5
_080D49FC: .4byte 0x000004C7
_080D4A00:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x2a
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D4A2C
	adds r0, r4, #0
	bl FUN_080cc1a0
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D4A2C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d4a34
FUN_080d4a34: @ 0x080D4A34
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x19
	beq _080D4AA2
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #0
	bl FUN_080cc348
	movs r5, #0xba
	lsls r5, r5, #2
	adds r2, r4, r5
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D4A7C
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080D4A78 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	subs r5, #1
	adds r1, r4, r5
	movs r0, #1
	strb r0, [r1]
	b _080D4A8C
	.align 2, 0
_080D4A78: .4byte 0x000002E6
_080D4A7C:
	lsrs r1, r1, #0x19
	ldr r2, _080D4AB8 @ =0x000002E6
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r5, _080D4ABC @ =0x000002E7
	adds r0, r4, r5
	strb r2, [r0]
_080D4A8C:
	ldr r0, _080D4AC0 @ =0x000003D6
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	beq _080D4AA2
	ldr r0, [r4, #0x18]
	ldrh r1, [r5]
	bl FUN_080cc3e4
	movs r0, #0
	strh r0, [r5]
_080D4AA2:
	ldr r1, _080D4AC4 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _080D4AAE
	b _080D4D28
_080D4AAE:
	lsls r0, r0, #2
	ldr r1, _080D4AC8 @ =_080D4ACC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D4AB8: .4byte 0x000002E6
_080D4ABC: .4byte 0x000002E7
_080D4AC0: .4byte 0x000003D6
_080D4AC4: .4byte 0x0000037D
_080D4AC8: .4byte _080D4ACC
_080D4ACC: @ jump table
	.4byte _080D4AE0 @ case 0
	.4byte _080D4B1C @ case 1
	.4byte _080D4C38 @ case 2
	.4byte _080D4CD0 @ case 3
	.4byte _080D4CF4 @ case 4
_080D4AE0:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r5, _080D4B18 @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _080D4B0C
	b _080D4D28
_080D4B0C:
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #1
	bl FUN_080cc348
	b _080D4D28
	.align 2, 0
_080D4B18: .4byte 0x0000037E
_080D4B1C:
	ldr r1, _080D4B7C @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D4B30
	ldr r2, _080D4B80 @ =0x000003F6
	adds r1, r4, r2
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
_080D4B30:
	movs r5, #0xd6
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	movs r1, #0x2b
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D4B84 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4B88
	asrs r0, r0, #0xc
	b _080D4B8E
	.align 2, 0
_080D4B7C: .4byte 0x0000037E
_080D4B80: .4byte 0x000003F6
_080D4B84: .4byte 0x085B0A08
_080D4B88:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D4B8E:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	ldr r1, _080D4BB0 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4BB4
	asrs r0, r0, #0xc
	b _080D4BBA
	.align 2, 0
_080D4BB0: .4byte 0x085B0A08
_080D4BB4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D4BBA:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	ldr r1, _080D4BE8 @ =0x0000037E
	adds r3, r4, r1
	ldrh r0, [r3]
	cmp r0, #3
	bls _080D4BF4
	ldr r2, _080D4BEC @ =0x000003F6
	adds r1, r4, r2
	ldrh r2, [r1]
	lsls r0, r0, #3
	cmp r2, r0
	blt _080D4BF0
	subs r0, r2, r0
	b _080D4BF2
	.align 2, 0
_080D4BE8: .4byte 0x0000037E
_080D4BEC: .4byte 0x000003F6
_080D4BF0:
	movs r0, #0
_080D4BF2:
	strh r0, [r1]
_080D4BF4:
	ldr r5, _080D4C30 @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0x13
	bls _080D4C0C
	b _080D4D28
_080D4C0C:
	ldr r2, _080D4C34 @ =0x000003F6
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080D4C18
	b _080D4D28
_080D4C18:
	strh r0, [r1]
	ldr r0, [r4, #0x18]
	movs r1, #0xaa
	lsls r1, r1, #2
	bl FUN_080cc3e4
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #2
	bl FUN_080cc348
	b _080D4D28
	.align 2, 0
_080D4C30: .4byte 0x0000037E
_080D4C34: .4byte 0x000003F6
_080D4C38:
	movs r5, #0xba
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D4C6C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4C70
	asrs r0, r0, #0xc
	b _080D4C76
	.align 2, 0
_080D4C6C: .4byte 0x085B0A08
_080D4C70:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D4C76:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4C94
	asrs r0, r0, #0xc
	b _080D4C9A
_080D4C94:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D4C9A:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x2c
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D4D28
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #3
	bl FUN_080cc348
	b _080D4D28
_080D4CD0:
	ldr r5, _080D4CF0 @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bls _080D4D28
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #4
	bl FUN_080cc348
	b _080D4D28
	.align 2, 0
_080D4CF0: .4byte 0x0000037E
_080D4CF4:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x2d
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D4D28
	ldr r2, _080D4D30 @ =0x000003D2
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080cc1a0
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D4D28:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D4D30: .4byte 0x000003D2

	thumb_func_start FUN_080d4d34
FUN_080d4d34: @ 0x080D4D34
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x1a
	beq _080D4D96
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r4, r5, r2
	ldrb r0, [r4]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r0, #0xf5
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r4]
	cmp r0, #5
	bne _080D4D7C
	ldr r0, [r5, #0x18]
	ldr r1, _080D4D78 @ =0x000002EB
	bl FUN_080cc3e4
	b _080D4D84
	.align 2, 0
_080D4D78: .4byte 0x000002EB
_080D4D7C:
	ldr r0, [r5, #0x18]
	movs r1, #0xe7
	bl FUN_080cc3e4
_080D4D84:
	ldr r0, [r5, #0x18]
	movs r1, #0xe6
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #0x1a
	movs r2, #0
	bl FUN_080cc348
_080D4D96:
	ldr r1, _080D4DAC @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D4DA2
	b _080D4EF8
_080D4DA2:
	cmp r0, #1
	bgt _080D4DB0
	cmp r0, #0
	beq _080D4DBE
	b _080D4F98
	.align 2, 0
_080D4DAC: .4byte 0x0000037D
_080D4DB0:
	cmp r0, #2
	bne _080D4DB6
	b _080D4F46
_080D4DB6:
	cmp r0, #3
	bne _080D4DBC
	b _080D4F68
_080D4DBC:
	b _080D4F98
_080D4DBE:
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D4DF4 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r4, #0xd6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4DF8
	asrs r0, r0, #0xc
	b _080D4DFE
	.align 2, 0
_080D4DF4: .4byte 0x085B0A08
_080D4DF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D4DFE:
	strh r0, [r5, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r4, #0xd6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4E1A
	asrs r0, r0, #0xc
	b _080D4E20
_080D4E1A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D4E20:
	strh r0, [r5, #0x38]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r1, [r0]
	ldrh r2, [r5, #0x34]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D4E90 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r3, sp
	ldrh r0, [r3, #4]
	ldrh r4, [r5, #0x38]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D4E8A
	cmp r1, #0
	blt _080D4E8A
	ldr r0, _080D4E94 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D4E8A
	ldr r0, _080D4E98 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D4E9C
_080D4E8A:
	movs r4, #0
	b _080D4EAA
	.align 2, 0
_080D4E90: .4byte 0xFFFF0000
_080D4E94: .4byte 0x030046A8
_080D4E98: .4byte 0x030046AC
_080D4E9C:
	ldr r0, _080D4EBC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D4EAA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D4EC0
	adds r0, #4
	b _080D4ECC
	.align 2, 0
_080D4EBC: .4byte 0x030046A4
_080D4EC0:
	ldr r0, _080D4EF4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D4ECC:
	ldrh r0, [r0, #2]
	bl FUN_080cfc04
	cmp r0, #0
	beq _080D4EDC
	movs r0, #0
	strh r0, [r5, #0x34]
	strh r0, [r5, #0x38]
_080D4EDC:
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D4F98
	adds r0, r5, #0
	movs r1, #0x1a
	movs r2, #1
	bl FUN_080cc348
	b _080D4F98
	.align 2, 0
_080D4EF4: .4byte 0x030046A4
_080D4EF8:
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #3
	bne _080D4F1E
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D4F1E
	ldr r0, [r5, #0x18]
	movs r1, #0xd1
	bl FUN_080cc3e4
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r5, #0x18]
	bl FUN_081df64c
_080D4F1E:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x2e
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D4F98
	adds r0, r5, #0
	movs r1, #0x1a
	movs r2, #2
	bl FUN_080cc348
	b _080D4F98
_080D4F46:
	ldr r4, _080D4F64 @ =0x0000037E
	adds r1, r5, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080D4F98
	adds r0, r5, #0
	movs r1, #0x1a
	movs r2, #3
	bl FUN_080cc348
	b _080D4F98
	.align 2, 0
_080D4F64: .4byte 0x0000037E
_080D4F68:
	ldr r0, _080D4FA0 @ =0x0000037E
	adds r4, r5, r0
	ldrh r0, [r4]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	blt _080D4F84
	adds r0, r5, #0
	movs r1, #5
	bl FUN_080cc3c4
_080D4F84:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _080D4F98
	adds r0, r5, #0
	bl FUN_080d05e8
_080D4F98:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D4FA0: .4byte 0x0000037E

	thumb_func_start FUN_080d4fa4
FUN_080d4fa4: @ 0x080D4FA4
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x1b
	beq _080D502E
	movs r4, #0xba
	lsls r4, r4, #2
	adds r2, r5, r4
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D4FE4
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080D4FE0 @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	subs r4, #1
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	b _080D4FF4
	.align 2, 0
_080D4FE0: .4byte 0x000002E6
_080D4FE4:
	lsrs r1, r1, #0x19
	ldr r2, _080D500C @ =0x000002E6
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r4, _080D5010 @ =0x000002E7
	adds r0, r5, r4
	strb r2, [r0]
_080D4FF4:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _080D5014
	ldr r0, [r5, #0x18]
	subs r1, #0x6d
	bl FUN_080cc3e4
	b _080D501C
	.align 2, 0
_080D500C: .4byte 0x000002E6
_080D5010: .4byte 0x000002E7
_080D5014:
	ldr r0, [r5, #0x18]
	movs r1, #0xe7
	bl FUN_080cc3e4
_080D501C:
	ldr r0, [r5, #0x18]
	movs r1, #0xe6
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #0x1b
	movs r2, #0
	bl FUN_080cc348
_080D502E:
	ldr r2, _080D5044 @ =0x0000037D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #4
	bls _080D503A
	b _080D53D8
_080D503A:
	lsls r0, r0, #2
	ldr r1, _080D5048 @ =_080D504C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D5044: .4byte 0x0000037D
_080D5048: .4byte _080D504C
_080D504C: @ jump table
	.4byte _080D5060 @ case 0
	.4byte _080D50AC @ case 1
	.4byte _080D5244 @ case 2
	.4byte _080D5384 @ case 3
	.4byte _080D53A8 @ case 4
_080D5060:
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r0, _080D50A4 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi _080D508C
	b _080D53D8
_080D508C:
	adds r0, r5, #0
	movs r1, #0x1b
	movs r2, #1
	bl FUN_080cc348
	ldr r2, _080D50A8 @ =0x000003F6
	adds r1, r5, r2
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	b _080D53D8
	.align 2, 0
_080D50A4: .4byte 0x0000037E
_080D50A8: .4byte 0x000003F6
_080D50AC:
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r0, [r0]
	movs r1, #0x2b
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D50F8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r4, #0xd6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D50FC
	asrs r0, r0, #0xc
	b _080D5102
	.align 2, 0
_080D50F8: .4byte 0x085B0A08
_080D50FC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D5102:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	ldr r1, _080D5124 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r4, #0xd6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D5128
	asrs r0, r0, #0xc
	b _080D512E
	.align 2, 0
_080D5124: .4byte 0x085B0A08
_080D5128:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D512E:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r1, [r0]
	ldrh r2, [r5, #0x34]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D51A0 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r3, sp
	ldrh r0, [r3, #4]
	ldrh r4, [r5, #0x38]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D519A
	cmp r1, #0
	blt _080D519A
	ldr r0, _080D51A4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D519A
	ldr r0, _080D51A8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D51AC
_080D519A:
	movs r4, #0
	b _080D51BA
	.align 2, 0
_080D51A0: .4byte 0xFFFF0000
_080D51A4: .4byte 0x030046A8
_080D51A8: .4byte 0x030046AC
_080D51AC:
	ldr r0, _080D51CC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D51BA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D51D0
	adds r0, #4
	b _080D51DC
	.align 2, 0
_080D51CC: .4byte 0x030046A4
_080D51D0:
	ldr r0, _080D51FC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D51DC:
	ldrh r0, [r0, #2]
	bl FUN_080cfc04
	cmp r0, #0
	beq _080D51EC
	movs r0, #0
	strh r0, [r5, #0x34]
	strh r0, [r5, #0x38]
_080D51EC:
	ldr r0, _080D5200 @ =0x000003F6
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0xe
	bls _080D5204
	subs r0, #0xf
	b _080D5206
	.align 2, 0
_080D51FC: .4byte 0x030046A4
_080D5200: .4byte 0x000003F6
_080D5204:
	movs r0, #0
_080D5206:
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x13
	bls _080D5216
	b _080D53D8
_080D5216:
	ldr r2, _080D5240 @ =0x000003F6
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r5, #0x18]
	movs r1, #0xaa
	lsls r1, r1, #2
	bl FUN_080cc3e4
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r5, #0x18]
	bl FUN_081df64c
	adds r0, r5, #0
	movs r1, #0x1b
	movs r2, #2
	bl FUN_080cc348
	b _080D53D8
	.align 2, 0
_080D5240: .4byte 0x000003F6
_080D5244:
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D5278 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r4, #0xd6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D527C
	asrs r0, r0, #0xc
	b _080D5282
	.align 2, 0
_080D5278: .4byte 0x085B0A08
_080D527C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D5282:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r4, #0xd6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D52A0
	asrs r0, r0, #0xc
	b _080D52A6
_080D52A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D52A6:
	rsbs r2, r0, #0
	strh r2, [r5, #0x38]
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r3, sp, #8
	ldrh r1, [r3]
	ldrh r0, [r5, #0x34]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _080D5300 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #8]
	ldrh r0, [r3, #4]
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r0, [r3, #4]
	ands r0, r4
	orrs r0, r2
	str r0, [r3, #4]
	ldrh r0, [r3]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D52FC
	cmp r1, #0
	blt _080D52FC
	ldr r0, _080D5304 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D52FC
	ldr r0, _080D5308 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D530C
_080D52FC:
	movs r4, #0
	b _080D531A
	.align 2, 0
_080D5300: .4byte 0xFFFF0000
_080D5304: .4byte 0x030046A8
_080D5308: .4byte 0x030046AC
_080D530C:
	ldr r0, _080D532C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D531A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D5330
	adds r0, #4
	b _080D533C
	.align 2, 0
_080D532C: .4byte 0x030046A4
_080D5330:
	ldr r0, _080D5380 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D533C:
	ldrh r0, [r0, #2]
	bl FUN_080cfc04
	cmp r0, #0
	beq _080D534C
	movs r0, #0
	strh r0, [r5, #0x34]
	strh r0, [r5, #0x38]
_080D534C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x2c
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D53D8
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #0x1b
	movs r2, #3
	bl FUN_080cc348
	b _080D53D8
	.align 2, 0
_080D5380: .4byte 0x030046A4
_080D5384:
	ldr r4, _080D53A4 @ =0x0000037E
	adds r1, r5, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080D53D8
	adds r0, r5, #0
	movs r1, #0x1b
	movs r2, #4
	bl FUN_080cc348
	b _080D53D8
	.align 2, 0
_080D53A4: .4byte 0x0000037E
_080D53A8:
	ldr r0, _080D53E0 @ =0x0000037E
	adds r4, r5, r0
	ldrh r0, [r4]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	blt _080D53C4
	adds r0, r5, #0
	movs r1, #5
	bl FUN_080cc3c4
_080D53C4:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _080D53D8
	adds r0, r5, #0
	bl FUN_080d05e8
_080D53D8:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D53E0: .4byte 0x0000037E

	thumb_func_start FUN_080d53e4
FUN_080d53e4: @ 0x080D53E4
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #4
	bl FUN_080cc3c4
	ldr r1, _080D5404 @ =0x0000037D
	adds r0, r5, r1
	ldrb r4, [r0]
	cmp r4, #1
	beq _080D5458
	cmp r4, #1
	bgt _080D5408
	cmp r4, #0
	beq _080D5412
	b _080D5504
	.align 2, 0
_080D5404: .4byte 0x0000037D
_080D5408:
	cmp r4, #2
	beq _080D5494
	cmp r4, #3
	beq _080D54E4
	b _080D5504
_080D5412:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r1, _080D5450 @ =0x000003F6
	adds r0, r5, r1
	strh r4, [r0]
	str r4, [r5, #0x3c]
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r5, #0x18]
	bl FUN_081df64c
	ldr r0, [r5, #0x18]
	ldr r1, _080D5454 @ =0x000001AD
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #0x1c
	movs r2, #1
	bl FUN_080cc348
	b _080D5504
	.align 2, 0
_080D5450: .4byte 0x000003F6
_080D5454: .4byte 0x000001AD
_080D5458:
	ldr r0, _080D5488 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080D5504
	ldr r0, _080D548C @ =0x000003F6
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r5, #0x18]
	ldr r1, _080D5490 @ =0x000001AF
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #0x1c
	movs r2, #2
	bl FUN_080cc348
	b _080D5504
	.align 2, 0
_080D5488: .4byte 0x0000037E
_080D548C: .4byte 0x000003F6
_080D5490: .4byte 0x000001AF
_080D5494:
	adds r0, r5, #0
	movs r1, #0x2c
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r1, _080D54DC @ =0x000003F6
	adds r2, r5, r1
	ldrh r0, [r2]
	subs r0, #0x1e
	movs r3, #0
	strh r0, [r2]
	ldr r0, _080D54E0 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	bls _080D5504
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r5, r1
	strh r3, [r0]
	strh r3, [r2]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080cc3c4
	adds r0, r5, #0
	movs r1, #0x1c
	movs r2, #3
	bl FUN_080cc348
	b _080D5504
	.align 2, 0
_080D54DC: .4byte 0x000003F6
_080D54E0: .4byte 0x0000037E
_080D54E4:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080cc3c4
	ldr r0, _080D550C @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080D5504
	adds r0, r5, #0
	bl FUN_080d05e8
_080D5504:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D550C: .4byte 0x0000037E

	thumb_func_start FUN_080d5510
FUN_080d5510: @ 0x080D5510
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080D5534
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_080cc348
	ldr r0, [r4, #0x18]
	movs r1, #0xd1
	lsls r1, r1, #2
	bl FUN_080cc3e4
_080D5534:
	adds r0, r4, #0
	movs r1, #8
	bl FUN_080cc3c4
	ldr r0, _080D555C @ =0x0000037E
	adds r5, r4, r0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080D5560
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
	b _080D55C8
	.align 2, 0
_080D555C: .4byte 0x0000037E
_080D5560:
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080cc3c4
	ldrh r0, [r5]
	subs r0, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080D557C
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080cc3c4
_080D557C:
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080cc3c4
	ldr r0, _080D55D0 @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _080D55D4 @ =0x00000127
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x18
	strh r0, [r1]
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D55AA
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_080cc268
_080D55AA:
	adds r0, r4, #0
	bl FUN_080cc1a0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #1
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
_080D55C8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D55D0: .4byte 0x0000095E
_080D55D4: .4byte 0x00000127

	thumb_func_start FUN_080d55d8
FUN_080d55d8: @ 0x080D55D8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0xd
	beq _080D561C
	adds r0, r6, #0
	movs r1, #0xd
	movs r2, #0
	bl FUN_080cc348
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r6, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_080cdda8
	ldr r0, [r6, #0x18]
	ldr r1, _080D56E4 @ =0x0000039A
	bl FUN_080cc3e4
	movs r0, #0x38
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0x20
	bl FUN_080ac374
_080D561C:
	ldr r0, _080D56E8 @ =0x0000037E
	adds r4, r6, r0
	ldrh r0, [r4]
	cmp r0, #0x10
	bne _080D562E
	ldr r0, [r6, #0x18]
	ldr r1, _080D56EC @ =0x000003A1
	bl FUN_080cc3e4
_080D562E:
	ldrh r0, [r4]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #2
	subs r1, r1, r0
	cmp r2, r1
	blt _080D5654
	adds r0, r6, #0
	movs r1, #0x41
	bl FUN_080cc3c4
	movs r1, #0x82
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
_080D5654:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r0, _080D56F0 @ =0x0000095E
	adds r1, r6, r0
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _080D568E
	movs r0, #0x20
	strh r0, [r1]
_080D568E:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _080D56F4 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080D56F8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080D5700
	.align 2, 0
_080D56E4: .4byte 0x0000039A
_080D56E8: .4byte 0x0000037E
_080D56EC: .4byte 0x000003A1
_080D56F0: .4byte 0x0000095E
_080D56F4: .4byte 0x000002E6
_080D56F8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D5700:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080D5724
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D572C
_080D5724:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D572C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D5764 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D579C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D5768
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D575C
	ldrb r0, [r4, #5]
_080D575C:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D5778
	.align 2, 0
_080D5764: .4byte 0x0000FFFF
_080D5768:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D5778
	strh r1, [r4, #8]
_080D5778:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
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
	bne _080D579C
	movs r0, #1
	strb r0, [r4, #7]
_080D579C:
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	adds r1, #0xe
	bl FUN_0822b20c
	ldr r2, _080D57E0 @ =0x0000037E
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080D57D8
	movs r0, #0xe0
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	adds r2, #3
	adds r1, r6, r2
	movs r0, #3
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D57D8:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D57E0: .4byte 0x0000037E

	thumb_func_start FUN_080d57e4
FUN_080d57e4: @ 0x080D57E4
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, [r5, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x20]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D580A
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D580A:
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r4, r5, r2
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	subs r2, #0x56
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _080D585C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080D5864
_080D585C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D5864:
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
	beq _080D5888
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D5890
_080D5888:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D5890:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D58C8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D5900
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D58CC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D58C0
	ldrb r0, [r4, #5]
_080D58C0:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D58DC
	.align 2, 0
_080D58C8: .4byte 0x0000FFFF
_080D58CC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D58DC
	strh r1, [r4, #8]
_080D58DC:
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
	bne _080D5900
	movs r0, #1
	strb r0, [r4, #7]
_080D5900:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d5908
FUN_080d5908: @ 0x080D5908
	push {lr}
	adds r1, r0, #0
	movs r2, #0xc
	ldr r3, _080D5938 @ =0x000004C5
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #2
	bne _080D5924
	adds r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D5924
	movs r2, #8
_080D5924:
	ldr r0, _080D593C @ =0x00000402
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080D5930
	subs r2, r2, r0
_080D5930:
	cmp r2, #1
	ble _080D5940
	adds r0, r2, #0
	b _080D5942
	.align 2, 0
_080D5938: .4byte 0x000004C5
_080D593C: .4byte 0x00000402
_080D5940:
	movs r0, #2
_080D5942:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d5948
FUN_080d5948: @ 0x080D5948
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D596C
	ldr r2, _080D59EC @ =0x00000386
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0
	bl FUN_080cc348
_080D596C:
	ldr r0, [r6, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x20]
	adds r0, r6, #0
	bl FUN_080d0824
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r6, r2
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_080d5908
	adds r1, r0, #0
	adds r0, r6, #0
	bl FUN_080cc268
	adds r0, r6, #0
	bl FUN_080cc1a0
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _080D59F0 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080D59F4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080D59FC
	.align 2, 0
_080D59EC: .4byte 0x00000386
_080D59F0: .4byte 0x000002E6
_080D59F4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D59FC:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080D5A20
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D5A28
_080D5A20:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D5A28:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D5A60 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D5A98
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D5A64
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D5A58
	ldrb r0, [r4, #5]
_080D5A58:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D5A74
	.align 2, 0
_080D5A60: .4byte 0x0000FFFF
_080D5A64:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D5A74
	strh r1, [r4, #8]
_080D5A74:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
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
	bne _080D5A98
	movs r0, #1
	strb r0, [r4, #7]
_080D5A98:
	movs r1, #0xd1
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #2
	bne _080D5AD8
	ldr r2, _080D5AC4 @ =0x0000034A
	adds r0, r6, r2
	ldrh r2, [r0]
	cmp r2, #0
	bne _080D5AD8
	ldr r0, _080D5AC8 @ =0x00000386
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080D5ACC
	strb r2, [r1]
	ldr r0, [r6, #0x18]
	movs r1, #0xc7
	bl FUN_080cc3e4
	b _080D5AD8
	.align 2, 0
_080D5AC4: .4byte 0x0000034A
_080D5AC8: .4byte 0x00000386
_080D5ACC:
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r6, #0x18]
	movs r1, #0xc8
	bl FUN_080cc3e4
_080D5AD8:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d5ae0
FUN_080d5ae0: @ 0x080D5AE0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r7, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	beq _080D5BAA
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D5B28 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	adds r4, r2, #0
	cmp r0, #0
	blt _080D5B2C
	asrs r1, r0, #0xc
	b _080D5B32
	.align 2, 0
_080D5B28: .4byte 0x085B0A08
_080D5B2C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D5B32:
	add r0, sp, #0xc
	ldrh r0, [r0]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D5B64 @ =0xFFFF0000
	ldr r2, [sp, #0xc]
	ands r2, r1
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x40
	lsls r1, r1, #0x10
	ldr r0, _080D5B68 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #6
	cmp r0, #0
	blt _080D5B6C
	asrs r2, r0, #0xc
	b _080D5B72
	.align 2, 0
_080D5B64: .4byte 0xFFFF0000
_080D5B68: .4byte 0x0000FFFF
_080D5B6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D5B72:
	add r0, sp, #0xc
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D5C00 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r0, r7, #0
	movs r1, #4
	movs r2, #0
	bl FUN_080cc348
	adds r1, r7, #0
	adds r1, #0x2c
	add r0, sp, #0xc
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	ldr r0, _080D5C04 @ =0x000003A1
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r2, #1
	movs r3, #1
	bl FUN_080d03bc
_080D5BAA:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r7, r1
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r1, [r0]
	subs r2, #0x6a
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _080D5C08
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080D5C10
	.align 2, 0
_080D5C00: .4byte 0xFFFF0000
_080D5C04: .4byte 0x000003A1
_080D5C08:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D5C10:
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
	beq _080D5C34
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D5C3C
_080D5C34:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D5C3C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D5C74 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D5CAC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D5C78
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D5C6C
	ldrb r0, [r4, #5]
_080D5C6C:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D5C88
	.align 2, 0
_080D5C74: .4byte 0x0000FFFF
_080D5C78:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D5C88
	strh r1, [r4, #8]
_080D5C88:
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
	bne _080D5CAC
	movs r0, #1
	strb r0, [r4, #7]
_080D5CAC:
	ldr r0, _080D5CD0 @ =0x0000037E
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080D5CC8
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D5CC8:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D5CD0: .4byte 0x0000037E

	thumb_func_start FUN_080d5cd4
FUN_080d5cd4: @ 0x080D5CD4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0x14
	beq _080D5CF0
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #0
	bl FUN_080cc348
_080D5CF0:
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r1, [r0]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _080D5D44
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #0xfe
	ands r0, r1
	adds r0, #1
	strb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D5D34
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080D5D2C @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r0, _080D5D30 @ =0x000002E7
	adds r1, r6, r0
	movs r0, #1
	b _080D5D42
	.align 2, 0
_080D5D2C: .4byte 0x000002E6
_080D5D30: .4byte 0x000002E7
_080D5D34:
	lsrs r1, r1, #0x19
	ldr r2, _080D5D98 @ =0x000002E6
	adds r0, r6, r2
	strb r1, [r0]
	ldr r0, _080D5D9C @ =0x000002E7
	adds r1, r6, r0
	movs r0, #0
_080D5D42:
	strb r0, [r1]
_080D5D44:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r6, r1
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r1, [r0]
	subs r2, #0x6a
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080D5DA0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080D5DA8
	.align 2, 0
_080D5D98: .4byte 0x000002E6
_080D5D9C: .4byte 0x000002E7
_080D5DA0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D5DA8:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080D5DCC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D5DD4
_080D5DCC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D5DD4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D5E0C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D5E44
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D5E10
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D5E04
	ldrb r0, [r4, #5]
_080D5E04:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D5E20
	.align 2, 0
_080D5E0C: .4byte 0x0000FFFF
_080D5E10:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D5E20
	strh r1, [r4, #8]
_080D5E20:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
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
	bne _080D5E44
	movs r0, #1
	strb r0, [r4, #7]
_080D5E44:
	ldr r1, _080D5E6C @ =0x000003FF
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _080D5E62
	adds r0, r6, #0
	bl FUN_080cc1a0
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D5E62:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D5E6C: .4byte 0x000003FF

	thumb_func_start FUN_080d5e70
FUN_080d5e70: @ 0x080D5E70
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #8
	bl FUN_080cc3c4
	ldr r1, _080D5E94 @ =0x0000037D
	adds r0, r7, r1
	ldrb r0, [r0]
	mov r8, r0
	cmp r0, #0
	beq _080D5E98
	cmp r0, #1
	bne _080D5E92
	b _080D600E
_080D5E92:
	b _080D6130
	.align 2, 0
_080D5E94: .4byte 0x0000037D
_080D5E98:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r7, r0
	ldrb r0, [r2]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D5ED0
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080D5EC8 @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	ldr r0, _080D5ECC @ =0x000002E7
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	b _080D5EE0
	.align 2, 0
_080D5EC8: .4byte 0x000002E6
_080D5ECC: .4byte 0x000002E7
_080D5ED0:
	lsrs r0, r1, #0x19
	ldr r2, _080D5F34 @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	ldr r1, _080D5F38 @ =0x000002E7
	adds r0, r7, r1
	mov r2, r8
	strb r2, [r0]
_080D5EE0:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r7, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0]
	ldr r2, _080D5F34 @ =0x000002E6
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _080D5F3C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080D5F44
	.align 2, 0
_080D5F34: .4byte 0x000002E6
_080D5F38: .4byte 0x000002E7
_080D5F3C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D5F44:
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
	beq _080D5F68
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D5F70
_080D5F68:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D5F70:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D5FA8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D5FE0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D5FAC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D5FA0
	ldrb r0, [r4, #5]
_080D5FA0:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D5FBC
	.align 2, 0
_080D5FA8: .4byte 0x0000FFFF
_080D5FAC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D5FBC
	strh r1, [r4, #8]
_080D5FBC:
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
	bne _080D5FE0
	movs r0, #1
	strb r0, [r4, #7]
_080D5FE0:
	movs r0, #0xfe
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, #0x1e
	bhi _080D6008
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r7, #0x18]
	movs r1, #0xd8
	lsls r1, r1, #1
	bl FUN_080cc3e4
	ldr r2, _080D6004 @ =0x0000037D
	adds r1, r7, r2
	movs r0, #1
	strb r0, [r1]
	b _080D6130
	.align 2, 0
_080D6004: .4byte 0x0000037D
_080D6008:
	subs r0, #0x1e
	strh r0, [r1]
	b _080D6130
_080D600E:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r7, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0]
	ldr r2, _080D6064 @ =0x000002E6
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #3
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	mov r1, r8
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, r8
	ands r0, r2
	cmp r1, r0
	beq _080D6068
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080D6070
	.align 2, 0
_080D6064: .4byte 0x000002E6
_080D6068:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D6070:
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
	beq _080D6094
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D609C
_080D6094:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D609C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D60D4 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D611A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D60DE
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D60D8
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080D60F4
	.align 2, 0
_080D60D4: .4byte 0x0000FFFF
_080D60D8:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D60F2
_080D60DE:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D60F2
	strh r1, [r4, #8]
	movs r2, #1
	b _080D60F4
_080D60F2:
	movs r2, #0
_080D60F4:
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
	bne _080D611C
	movs r0, #1
	strb r0, [r4, #7]
	b _080D611C
_080D611A:
	movs r2, #0
_080D611C:
	cmp r2, #0
	beq _080D6130
	adds r0, r7, #0
	bl FUN_080cc1a0
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D6130:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d613c
FUN_080d613c: @ 0x080D613C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _080D61B0
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D6180
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r6, _080D6178 @ =0x000002E6
	adds r1, r5, r6
	strb r0, [r1]
	ldr r0, _080D617C @ =0x000002E7
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _080D6190
	.align 2, 0
_080D6178: .4byte 0x000002E6
_080D617C: .4byte 0x000002E7
_080D6180:
	lsrs r1, r1, #0x19
	ldr r2, _080D6204 @ =0x000002E6
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _080D6208 @ =0x000002E7
	adds r0, r5, r3
	strb r2, [r0]
_080D6190:
	ldr r6, _080D620C @ =0x000003D6
	adds r4, r5, r6
	ldrh r0, [r4]
	cmp r0, #0
	beq _080D61A6
	ldr r0, [r5, #0x18]
	ldrh r1, [r4]
	bl FUN_080cc3e4
	movs r0, #0
	strh r0, [r4]
_080D61A6:
	adds r0, r5, #0
	movs r1, #0x18
	movs r2, #0
	bl FUN_080cc348
_080D61B0:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r5, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r2, _080D6204 @ =0x000002E6
	adds r0, r5, r2
	ldrb r3, [r0]
	ldr r6, _080D6208 @ =0x000002E7
	adds r0, r5, r6
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_08236fac
	adds r6, r5, #0
	adds r6, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080D6210
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _080D6218
	.align 2, 0
_080D6204: .4byte 0x000002E6
_080D6208: .4byte 0x000002E7
_080D620C: .4byte 0x000003D6
_080D6210:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D6218:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080D623C
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _080D6244
_080D623C:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D6244:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D627C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _080D62B4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D6280
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D6274
	ldrb r0, [r4, #5]
_080D6274:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D6290
	.align 2, 0
_080D627C: .4byte 0x0000FFFF
_080D6280:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r6, [r4, #5]
	cmp r0, r6
	blo _080D6290
	strh r1, [r4, #8]
_080D6290:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
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
	bne _080D62B4
	movs r0, #1
	strb r0, [r4, #7]
_080D62B4:
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r3, r5, r0
	ldrh r0, [r3]
	cmp r0, #0
	bne _080D62C2
	b _080D63BA
_080D62C2:
	ldr r1, _080D62F0 @ =0x00000395
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D6340
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r2, [r0]
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r6, #0x2c
	ldrsh r0, [r5, r6]
	subs r3, r1, r0
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	subs r1, r1, r0
	cmp r3, #0
	blt _080D62F4
	asrs r0, r3, #3
	b _080D62FA
	.align 2, 0
_080D62F0: .4byte 0x00000395
_080D62F4:
	rsbs r0, r3, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080D62FA:
	strh r0, [r5, #0x34]
	cmp r1, #0
	blt _080D6304
	asrs r0, r1, #3
	b _080D630A
_080D6304:
	rsbs r0, r1, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080D630A:
	strh r0, [r5, #0x38]
	ldr r3, _080D6338 @ =0x0000037E
	adds r4, r5, r3
	ldrh r1, [r4]
	cmp r1, #5
	bhi _080D63A2
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D632E
	ldr r0, [r5, #0x18]
	ldr r1, _080D633C @ =0x00000191
	bl FUN_080cc3e4
	adds r0, r5, #0
	adds r0, #0x2c
	bl FUN_080acd98
_080D632E:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _080D63A2
	.align 2, 0
_080D6338: .4byte 0x0000037E
_080D633C: .4byte 0x00000191
_080D6340:
	movs r6, #0xba
	lsls r6, r6, #2
	adds r0, r5, r6
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldr r2, _080D6370 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldrh r0, [r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D6374
	asrs r0, r0, #0xc
	b _080D637A
	.align 2, 0
_080D6370: .4byte 0x085B0A08
_080D6374:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D637A:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D6398
	asrs r0, r0, #0xc
	b _080D639E
_080D6398:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D639E:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
_080D63A2:
	movs r6, #0xd6
	lsls r6, r6, #1
	adds r4, r5, r6
	ldrh r0, [r4]
	bl FUN_0823b9cc
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r4]
	b _080D6400
_080D63BA:
	movs r1, #0
	strh r0, [r3]
	ldr r2, _080D63E4 @ =0x00000395
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _080D63E8 @ =0x000004C5
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D63F0
	ldr r6, _080D63EC @ =0x000004C7
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D63F0
	adds r0, r5, #0
	movs r1, #0x13
	movs r2, #0
	bl FUN_080cc348
	b _080D6400
	.align 2, 0
_080D63E4: .4byte 0x00000395
_080D63E8: .4byte 0x000004C5
_080D63EC: .4byte 0x000004C7
_080D63F0:
	adds r0, r5, #0
	bl FUN_080cc1a0
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D6400:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d6408
FUN_080d6408: @ 0x080D6408
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0xd
	beq _080D644C
	adds r0, r6, #0
	movs r1, #0xd
	movs r2, #0
	bl FUN_080cc348
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r6, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_080cdda8
	ldr r0, [r6, #0x18]
	ldr r1, _080D64E4 @ =0x0000039A
	bl FUN_080cc3e4
	movs r0, #0x38
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0x20
	bl FUN_080ac374
_080D644C:
	ldr r3, _080D64E8 @ =0x0000037E
	adds r0, r6, r3
	ldrh r0, [r0]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #2
	subs r1, r1, r0
	cmp r2, r1
	blt _080D6474
	adds r0, r6, #0
	movs r1, #0x41
	bl FUN_080cc3c4
	adds r2, r6, #0
	adds r2, #0xa8
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
_080D6474:
	adds r0, r6, #0
	movs r1, #0xc7
	movs r2, #0x40
	bl FUN_080cc1e8
	adds r1, r6, #0
	adds r1, #0xd0
	ldr r0, _080D64EC @ =0x03003584
	ldr r0, [r0]
	movs r2, #0x91
	lsls r2, r2, #6
	adds r0, r0, r2
	str r0, [r1]
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r4, r6, r3
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _080D64F0 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080D64F4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080D64FC
	.align 2, 0
_080D64E4: .4byte 0x0000039A
_080D64E8: .4byte 0x0000037E
_080D64EC: .4byte 0x03003584
_080D64F0: .4byte 0x000002E6
_080D64F4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D64FC:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080D6520
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D6528
_080D6520:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D6528:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _080D6560 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D6598
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D6564
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D6558
	ldrb r0, [r4, #5]
_080D6558:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D6574
	.align 2, 0
_080D6560: .4byte 0x0000FFFF
_080D6564:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D6574
	strh r1, [r4, #8]
_080D6574:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
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
	bne _080D6598
	movs r0, #1
	strb r0, [r4, #7]
_080D6598:
	ldr r3, _080D65F0 @ =0x0000095E
	adds r1, r6, r3
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	ldr r3, _080D65F4 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _080D65BE
	movs r0, #0x20
	strh r0, [r1]
_080D65BE:
	ldr r0, _080D65F8 @ =0x0000037E
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ands r0, r2
	cmp r0, #0x1f
	bls _080D65E8
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _080D65FC @ =0x00000381
	adds r0, r6, r2
	strb r1, [r0]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D65E8:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D65F0: .4byte 0x0000095E
_080D65F4: .4byte 0x0000FFFF
_080D65F8: .4byte 0x0000037E
_080D65FC: .4byte 0x00000381

	thumb_func_start FUN_080d6600
FUN_080d6600: @ 0x080D6600
	push {r4, lr}
	adds r4, r0, #0
	movs r2, #9
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r1, r4, r0
_080D660C:
	ldrh r0, [r1]
	strh r0, [r1, #2]
	subs r1, #2
	subs r2, #1
	cmp r2, #0
	bgt _080D660C
	adds r0, r4, #0
	bl FUN_0807849c
	adds r1, r0, #0
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r2, r4, r3
	strh r1, [r2]
	lsls r0, r1, #0x10
	cmp r0, #0
	blt _080D6642
	ldr r3, _080D6648 @ =0x00000456
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r1, r0
	adds r0, #7
	movs r1, #7
	ands r0, r1
	strh r0, [r2]
_080D6642:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D6648: .4byte 0x00000456

	thumb_func_start FUN_080d664c
FUN_080d664c: @ 0x080D664C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r1, _080D66C0 @ =0x000003F3
	adds r0, r5, r1
	ldrb r4, [r0]
	cmp r4, #0
	beq _080D665E
	b _080D67AE
_080D665E:
	ldr r2, _080D66C4 @ =0x000003BD
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r2, r3, #7
	movs r0, #7
	ands r2, r0
	adds r1, r3, #0
	adds r1, #9
	ands r1, r0
	movs r6, #0xa4
	lsls r6, r6, #2
	adds r0, r5, r6
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r0, r3
	beq _080D6688
	cmp r0, r2
	beq _080D6688
	cmp r0, r1
	beq _080D6688
	b _080D67DC
_080D6688:
	ldr r1, _080D66C4 @ =0x000003BD
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, _080D66C8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x32
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _080D66CC
	asrs r2, r0, #0xc
	b _080D66D2
	.align 2, 0
_080D66C0: .4byte 0x000003F3
_080D66C4: .4byte 0x000003BD
_080D66C8: .4byte 0x085B0A08
_080D66CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D66D2:
	mov r0, sp
	ldrh r1, [r0]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D66FC @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _080D6700
	asrs r2, r0, #0xc
	b _080D6706
	.align 2, 0
_080D66FC: .4byte 0xFFFF0000
_080D6700:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D6706:
	mov r0, sp
	ldrh r1, [r0, #4]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D6748 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r6, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D6742
	cmp r1, #0
	blt _080D6742
	ldr r0, _080D674C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D6742
	ldr r0, _080D6750 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D6754
_080D6742:
	movs r4, #0
	b _080D6762
	.align 2, 0
_080D6748: .4byte 0xFFFF0000
_080D674C: .4byte 0x030046A8
_080D6750: .4byte 0x030046AC
_080D6754:
	ldr r0, _080D6774 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D6762:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D6778
	adds r0, #4
	b _080D6784
	.align 2, 0
_080D6774: .4byte 0x030046A4
_080D6778:
	ldr r0, _080D6798 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D6784:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080D679C
	cmp r2, #2
	beq _080D67A0
	b _080D67A4
	.align 2, 0
_080D6798: .4byte 0x030046A4
_080D679C:
	ldrb r0, [r6, #4]
	b _080D67A2
_080D67A0:
	ldrb r0, [r6]
_080D67A2:
	subs r1, r1, r0
_080D67A4:
	movs r2, #0x2e
	ldrsh r0, [r5, r2]
	adds r0, #0xc8
	cmp r1, r0
	blo _080D67B2
_080D67AE:
	movs r0, #1
	b _080D67FA
_080D67B2:
	ldr r4, _080D67D8 @ =0x000003BD
	adds r0, r5, r4
	ldrb r0, [r0]
	adds r0, #4
	movs r1, #7
	ands r0, r1
	movs r6, #0xba
	lsls r6, r6, #2
	adds r1, r5, r6
	movs r4, #0
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080cc1a0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	b _080D67F6
	.align 2, 0
_080D67D8: .4byte 0x000003BD
_080D67DC:
	adds r0, r3, #4
	movs r1, #7
	ands r0, r1
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r5, r2
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080cc1a0
	movs r6, #0xdf
	lsls r6, r6, #2
	adds r0, r5, r6
_080D67F6:
	strb r4, [r0]
	movs r0, #0
_080D67FA:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d6804
FUN_080d6804: @ 0x080D6804
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r4, [r0]
	ldr r2, _080D686C @ =0x00000446
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080D6828
	ldr r3, _080D6870 @ =0x00000442
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D6828
	movs r1, #1
_080D6828:
	cmp r1, #0
	bne _080D6848
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D6848
	adds r0, r5, #0
	bl FUN_080ced90
	adds r4, r0, #0
_080D6848:
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D6878
	ldr r3, _080D6874 @ =0x000003D2
	adds r0, r5, r3
	ldrb r0, [r0]
	movs r4, #0x18
	cmp r0, #0
	beq _080D6862
	movs r4, #0x19
_080D6862:
	adds r0, r5, #0
	bl FUN_08078548
	b _080D69D4
	.align 2, 0
_080D686C: .4byte 0x00000446
_080D6870: .4byte 0x00000442
_080D6874: .4byte 0x000003D2
_080D6878:
	adds r0, r4, #0
	subs r0, #0x18
	cmp r0, #1
	bls _080D68A2
	cmp r4, #0x16
	beq _080D68A2
	cmp r4, #0x17
	beq _080D68A2
	cmp r4, #0x15
	beq _080D68A2
	cmp r4, #0x14
	beq _080D68A2
	cmp r4, #0x13
	beq _080D68A2
	movs r1, #0xfb
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D68A2
	movs r4, #0x12
_080D68A2:
	subs r0, r4, #2
	cmp r0, #0x1e
	bhi _080D6942
	lsls r0, r0, #2
	ldr r1, _080D68B4 @ =_080D68B8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D68B4: .4byte _080D68B8
_080D68B8: @ jump table
	.4byte _080D69D4 @ case 0
	.4byte _080D69D4 @ case 1
	.4byte _080D6934 @ case 2
	.4byte _080D693E @ case 3
	.4byte _080D693E @ case 4
	.4byte _080D69D4 @ case 5
	.4byte _080D693E @ case 6
	.4byte _080D693E @ case 7
	.4byte _080D693E @ case 8
	.4byte _080D693E @ case 9
	.4byte _080D693E @ case 10
	.4byte _080D69D4 @ case 11
	.4byte _080D693E @ case 12
	.4byte _080D69D4 @ case 13
	.4byte _080D693E @ case 14
	.4byte _080D69D4 @ case 15
	.4byte _080D693E @ case 16
	.4byte _080D693E @ case 17
	.4byte _080D693E @ case 18
	.4byte _080D693E @ case 19
	.4byte _080D69D4 @ case 20
	.4byte _080D69D4 @ case 21
	.4byte _080D69D4 @ case 22
	.4byte _080D69D4 @ case 23
	.4byte _080D6942 @ case 24
	.4byte _080D6942 @ case 25
	.4byte _080D6942 @ case 26
	.4byte _080D6942 @ case 27
	.4byte _080D6942 @ case 28
	.4byte _080D6942 @ case 29
	.4byte _080D693E @ case 30
_080D6934:
	adds r0, r5, #0
	bl FUN_080d664c
	cmp r0, #0
	bne _080D69D4
_080D693E:
	movs r4, #0
	b _080D69D4
_080D6942:
	ldr r2, _080D697C @ =0x00000446
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080D695A
	ldr r3, _080D6980 @ =0x00000442
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D695A
	movs r1, #1
_080D695A:
	cmp r1, #0
	beq _080D6984
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080D693E
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	ldrh r1, [r0]
	b _080D69C8
	.align 2, 0
_080D697C: .4byte 0x00000446
_080D6980: .4byte 0x00000442
_080D6984:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r2, [r0]
	ldrh r1, [r2, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D699A
	movs r4, #3
	b _080D69D4
_080D699A:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D69B4
	adds r0, r5, #0
	adds r0, #0x24
	bl FUN_08006194
	lsls r0, r0, #0x18
	movs r4, #7
	cmp r0, #0
	beq _080D69D4
	b _080D693E
_080D69B4:
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080D693E
	ldrh r1, [r2]
_080D69C8:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D693E
	movs r4, #1
_080D69D4:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080d69dc
FUN_080d69dc: @ 0x080D69DC
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _080D6A10
	adds r0, r5, #0
	movs r1, #0x10
	bl FUN_080cc3d4
	cmp r0, #0
	bne _080D6A0E
	ldr r0, [r5, #0x3c]
	cmp r0, #0
	bne _080D6A10
	movs r2, #0xde
	lsls r2, r2, #1
	adds r4, r5, r2
	adds r1, r5, #0
	adds r1, #0x2c
	adds r0, r4, #0
	bl FUN_0823280c
_080D6A0E:
	str r4, [r5, #0x3c]
_080D6A10:
	adds r0, r5, #0
	adds r0, #0x24
	bl FUN_0823b4b8
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D6A34
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	b _080D6A52
_080D6A34:
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	ldr r0, _080D6A6C @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r1, r5, #0
	adds r1, #0x2c
	movs r2, #0
	bl FUN_082364c4
_080D6A52:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D6A70
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _080D6A7C
	.align 2, 0
_080D6A6C: .4byte 0x0000FFFB
_080D6A70:
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_080D6A7C:
	str r1, [r0]
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #2
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D6A96
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	b _080D6A9C
_080D6A96:
	ldr r0, [r4]
	ldr r1, _080D6AB8 @ =0xFFFFFDFF
	ands r0, r1
_080D6A9C:
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D6ABC
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _080D6AC6
	.align 2, 0
_080D6AB8: .4byte 0xFFFFFDFF
_080D6ABC:
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_080D6AC6:
	str r1, [r0]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D6AE4
	ldr r1, _080D6AE0 @ =0x0000060C
	adds r0, r5, r1
	bl FUN_080136b4
	b _080D6AEC
	.align 2, 0
_080D6AE0: .4byte 0x0000060C
_080D6AE4:
	ldr r2, _080D6B1C @ =0x0000060C
	adds r0, r5, r2
	bl FUN_08013698
_080D6AEC:
	movs r1, #0xfe
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r5, #0x2e]
	adds r0, r0, r2
	strh r0, [r5, #0x2e]
	adds r2, r5, #0
	adds r2, #0xa8
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r5, #0
	adds r1, #0xaa
	ldr r2, _080D6B20 @ =0x000003F6
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D6B1C: .4byte 0x0000060C
_080D6B20: .4byte 0x000003F6

	thumb_func_start FUN_080d6b24
FUN_080d6b24: @ 0x080D6B24
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0x80
	lsls r0, r0, #7
	ldr r1, [r5, #0x20]
	orrs r1, r0
	str r1, [r5, #0x20]
	ldr r0, [r5, #0x1c]
	cmp r0, #2
	bne _080D6B3C
	b _080D6E7C
_080D6B3C:
	cmp r0, #2
	bhi _080D6B46
	cmp r0, #1
	beq _080D6B4E
	b _080D6E98
_080D6B46:
	cmp r0, #8
	bne _080D6B4C
	b _080D6E38
_080D6B4C:
	b _080D6E98
_080D6B4E:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D6B82
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _080D6B82
	ldr r1, [r5, #0x18]
	ldr r0, _080D6B70 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080D6B74
	movs r0, #0
	b _080D6B7A
	.align 2, 0
_080D6B70: .4byte 0x03002C68
_080D6B74:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_080D6B7A:
	adds r1, r0, #0
	adds r0, r5, #0
	bl FUN_080d0394
_080D6B82:
	adds r0, r5, #0
	bl FUN_080d6600
	adds r0, r5, #0
	bl FUN_080d6804
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080cfaa4
	ldr r1, _080D6C94 @ =0x085AD184
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r4, #0xe9
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D6BC0
	movs r1, #0xea
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
_080D6BC0:
	adds r0, r5, #0
	bl FUN_080d69dc
	ldr r2, _080D6C98 @ =0x000003CE
	adds r0, r5, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	beq _080D6BD8
	adds r0, r5, #0
	bl FUN_080cfb20
_080D6BD8:
	adds r0, r5, #0
	bl FUN_080cfcb0
	adds r0, r5, #0
	bl FUN_080d01c8
	ldr r1, _080D6C9C @ =0x00000446
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080D6BFC
	ldr r2, _080D6CA0 @ =0x00000442
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D6BFC
	movs r1, #1
_080D6BFC:
	cmp r1, #0
	beq _080D6C02
	b _080D6E98
_080D6C02:
	movs r4, #0
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	bl FUN_080cfc78
	cmp r0, #0
	bne _080D6C40
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r2, [r0]
	cmp r2, #1
	bne _080D6C40
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080D6C40
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r1, [r0]
	ands r1, r2
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r4, r0, #0x1f
_080D6C40:
	cmp r4, #0
	bne _080D6C46
	b _080D6E2C
_080D6C46:
	ldr r0, _080D6CA4 @ =0x000003BE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	beq _080D6C5A
	b _080D6E98
_080D6C5A:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D6CA8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x32
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _080D6CAC
	asrs r2, r0, #0xc
	b _080D6CB2
	.align 2, 0
_080D6C94: .4byte 0x085AD184
_080D6C98: .4byte 0x000003CE
_080D6C9C: .4byte 0x00000446
_080D6CA0: .4byte 0x00000442
_080D6CA4: .4byte 0x000003BE
_080D6CA8: .4byte 0x085B0A08
_080D6CAC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D6CB2:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D6CDC @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _080D6CE0
	asrs r2, r0, #0xc
	b _080D6CE6
	.align 2, 0
_080D6CDC: .4byte 0xFFFF0000
_080D6CE0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D6CE6:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D6D28 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r6, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D6D22
	cmp r1, #0
	blt _080D6D22
	ldr r0, _080D6D2C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D6D22
	ldr r0, _080D6D30 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D6D34
_080D6D22:
	movs r4, #0
	b _080D6D42
	.align 2, 0
_080D6D28: .4byte 0xFFFF0000
_080D6D2C: .4byte 0x030046A8
_080D6D30: .4byte 0x030046AC
_080D6D34:
	ldr r0, _080D6D54 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D6D42:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D6D58
	adds r0, #4
	b _080D6D64
	.align 2, 0
_080D6D54: .4byte 0x030046A4
_080D6D58:
	ldr r0, _080D6D78 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D6D64:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080D6D7C
	cmp r2, #2
	beq _080D6D80
	b _080D6D84
	.align 2, 0
_080D6D78: .4byte 0x030046A4
_080D6D7C:
	ldrb r0, [r6, #4]
	b _080D6D82
_080D6D80:
	ldrb r0, [r6]
_080D6D82:
	subs r1, r1, r0
_080D6D84:
	movs r4, #0x2e
	ldrsh r0, [r5, r4]
	adds r0, #0xc8
	cmp r1, r0
	bhs _080D6D90
	b _080D6E98
_080D6D90:
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D6DB8
	cmp r1, #0
	blt _080D6DB8
	ldr r0, _080D6DBC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D6DB8
	ldr r0, _080D6DC0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D6DC4
_080D6DB8:
	movs r4, #0
	b _080D6DD2
	.align 2, 0
_080D6DBC: .4byte 0x030046A8
_080D6DC0: .4byte 0x030046AC
_080D6DC4:
	ldr r0, _080D6DE4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D6DD2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D6DE8
	adds r0, #4
	b _080D6DF4
	.align 2, 0
_080D6DE4: .4byte 0x030046A4
_080D6DE8:
	ldr r0, _080D6E24 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D6DF4:
	ldrh r2, [r0, #2]
	movs r3, #4
	ands r2, r3
	cmp r2, #0
	bne _080D6E98
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r4, _080D6E28 @ =0x000003BD
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	subs r4, #0x41
	adds r0, r5, r4
	strb r3, [r0]
	subs r1, #0x3f
	adds r0, r5, r1
	strb r2, [r0]
	b _080D6E98
	.align 2, 0
_080D6E24: .4byte 0x030046A4
_080D6E28: .4byte 0x000003BD
_080D6E2C:
	ldr r2, _080D6E34 @ =0x000003BE
	adds r0, r5, r2
	strh r4, [r0]
	b _080D6E98
	.align 2, 0
_080D6E34: .4byte 0x000003BE
_080D6E38:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080cc3c4
	movs r4, #0xdf
	lsls r4, r4, #2
	adds r1, r5, r4
	ldrb r0, [r1]
	cmp r0, #0x1c
	bne _080D6E50
	adds r4, r0, #0
	b _080D6E5E
_080D6E50:
	ldr r1, _080D6E74 @ =0x000003D2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r4, #0x1a
	cmp r0, #0
	beq _080D6E5E
	movs r4, #0x1b
_080D6E5E:
	ldr r0, _080D6E78 @ =0x085AD184
	lsls r1, r4, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_080d69dc
	b _080D6E98
	.align 2, 0
_080D6E74: .4byte 0x000003D2
_080D6E78: .4byte 0x085AD184
_080D6E7C:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080cc3c4
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_080d69dc
_080D6E98:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d6ea0
FUN_080d6ea0: @ 0x080D6EA0
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0x80
	lsls r0, r0, #7
	ldr r1, [r5, #0x20]
	orrs r1, r0
	str r1, [r5, #0x20]
	ldr r0, [r5, #0x1c]
	cmp r0, #2
	bne _080D6EB8
	b _080D71EC
_080D6EB8:
	cmp r0, #2
	bhi _080D6EC2
	cmp r0, #1
	beq _080D6ECA
	b _080D7208
_080D6EC2:
	cmp r0, #8
	bne _080D6EC8
	b _080D71A8
_080D6EC8:
	b _080D7208
_080D6ECA:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _080D6EF4
	ldr r1, [r5, #0x18]
	ldr r0, _080D6EE0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080D6EE4
	movs r0, #0
	b _080D6EEA
	.align 2, 0
_080D6EE0: .4byte 0x03002C68
_080D6EE4:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_080D6EEA:
	adds r1, r0, #1
	asrs r1, r1, #1
	adds r0, r5, #0
	bl FUN_080d0394
_080D6EF4:
	adds r0, r5, #0
	bl FUN_080d6600
	adds r0, r5, #0
	bl FUN_080d6804
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080cfaa4
	ldr r1, _080D7004 @ =0x085AD204
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D6F32
	movs r2, #0xea
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
_080D6F32:
	adds r0, r5, #0
	bl FUN_080d69dc
	ldr r4, _080D7008 @ =0x000003CE
	adds r0, r5, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _080D6F4A
	adds r0, r5, #0
	bl FUN_080cfb20
_080D6F4A:
	adds r0, r5, #0
	bl FUN_080cfcb0
	adds r0, r5, #0
	bl FUN_080d01c8
	ldr r2, _080D700C @ =0x00000446
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080D6F6E
	ldr r4, _080D7010 @ =0x00000442
	adds r0, r5, r4
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D6F6E
	movs r1, #1
_080D6F6E:
	cmp r1, #0
	beq _080D6F74
	b _080D7208
_080D6F74:
	movs r4, #0
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	bl FUN_080cfc78
	cmp r0, #0
	bne _080D6FB2
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r2, [r0]
	cmp r2, #1
	bne _080D6FB2
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080D6FB2
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r1, [r0]
	ands r1, r2
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r4, r0, #0x1f
_080D6FB2:
	cmp r4, #0
	bne _080D6FB8
	b _080D719C
_080D6FB8:
	ldr r0, _080D7014 @ =0x000003BE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	beq _080D6FCC
	b _080D7208
_080D6FCC:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D7018 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x32
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _080D701C
	asrs r2, r0, #0xc
	b _080D7022
	.align 2, 0
_080D7004: .4byte 0x085AD204
_080D7008: .4byte 0x000003CE
_080D700C: .4byte 0x00000446
_080D7010: .4byte 0x00000442
_080D7014: .4byte 0x000003BE
_080D7018: .4byte 0x085B0A08
_080D701C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D7022:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D704C @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _080D7050
	asrs r2, r0, #0xc
	b _080D7056
	.align 2, 0
_080D704C: .4byte 0xFFFF0000
_080D7050:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D7056:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D7098 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r6, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D7092
	cmp r1, #0
	blt _080D7092
	ldr r0, _080D709C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D7092
	ldr r0, _080D70A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D70A4
_080D7092:
	movs r4, #0
	b _080D70B2
	.align 2, 0
_080D7098: .4byte 0xFFFF0000
_080D709C: .4byte 0x030046A8
_080D70A0: .4byte 0x030046AC
_080D70A4:
	ldr r0, _080D70C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D70B2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D70C8
	adds r0, #4
	b _080D70D4
	.align 2, 0
_080D70C4: .4byte 0x030046A4
_080D70C8:
	ldr r0, _080D70E8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D70D4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080D70EC
	cmp r2, #2
	beq _080D70F0
	b _080D70F4
	.align 2, 0
_080D70E8: .4byte 0x030046A4
_080D70EC:
	ldrb r0, [r6, #4]
	b _080D70F2
_080D70F0:
	ldrb r0, [r6]
_080D70F2:
	subs r1, r1, r0
_080D70F4:
	movs r4, #0x2e
	ldrsh r0, [r5, r4]
	adds r0, #0xc8
	cmp r1, r0
	bhs _080D7100
	b _080D7208
_080D7100:
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D7128
	cmp r1, #0
	blt _080D7128
	ldr r0, _080D712C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D7128
	ldr r0, _080D7130 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D7134
_080D7128:
	movs r4, #0
	b _080D7142
	.align 2, 0
_080D712C: .4byte 0x030046A8
_080D7130: .4byte 0x030046AC
_080D7134:
	ldr r0, _080D7154 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D7142:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D7158
	adds r0, #4
	b _080D7164
	.align 2, 0
_080D7154: .4byte 0x030046A4
_080D7158:
	ldr r0, _080D7194 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D7164:
	ldrh r2, [r0, #2]
	movs r3, #4
	ands r2, r3
	cmp r2, #0
	bne _080D7208
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r4, _080D7198 @ =0x000003BD
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	subs r4, #0x41
	adds r0, r5, r4
	strb r3, [r0]
	subs r1, #0x3f
	adds r0, r5, r1
	strb r2, [r0]
	b _080D7208
	.align 2, 0
_080D7194: .4byte 0x030046A4
_080D7198: .4byte 0x000003BD
_080D719C:
	ldr r2, _080D71A4 @ =0x000003BE
	adds r0, r5, r2
	strh r4, [r0]
	b _080D7208
	.align 2, 0
_080D71A4: .4byte 0x000003BE
_080D71A8:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080cc3c4
	movs r4, #0xdf
	lsls r4, r4, #2
	adds r1, r5, r4
	ldrb r0, [r1]
	cmp r0, #0x1c
	bne _080D71C0
	adds r4, r0, #0
	b _080D71CE
_080D71C0:
	ldr r1, _080D71E4 @ =0x000003D2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r4, #0x1a
	cmp r0, #0
	beq _080D71CE
	movs r4, #0x1b
_080D71CE:
	ldr r0, _080D71E8 @ =0x085AD204
	lsls r1, r4, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_080d69dc
	b _080D7208
	.align 2, 0
_080D71E4: .4byte 0x000003D2
_080D71E8: .4byte 0x085AD204
_080D71EC:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080cc3c4
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_080d69dc
_080D7208:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d7210
FUN_080d7210: @ 0x080D7210
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r2, [r0]
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r5, r4, r3
	ldr r0, [r5]
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D7238
	adds r0, r4, #0
	bl FUN_080ced90
	adds r2, r0, #0
_080D7238:
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D7248
	movs r2, #0x18
	b _080D72A0
_080D7248:
	cmp r2, #0x18
	beq _080D72A0
	cmp r2, #0x14
	beq _080D72A0
	cmp r2, #0x13
	beq _080D72A0
	cmp r2, #0x17
	beq _080D72A0
	cmp r2, #4
	beq _080D72A0
	cmp r2, #0xd
	beq _080D72A0
	ldr r2, [r5]
	ldrh r1, [r2, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D7280
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_08006194
	lsls r0, r0, #0x18
	movs r2, #4
	cmp r0, #0
	beq _080D72A0
_080D727C:
	movs r2, #0
	b _080D72A0
_080D7280:
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080D727C
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D727C
	movs r2, #1
_080D72A0:
	adds r0, r2, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080d72a8
FUN_080d72a8: @ 0x080D72A8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x24
	bl FUN_0823b4b8
	adds r0, r4, #0
	movs r1, #8
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D72CE
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	b _080D72EC
_080D72CE:
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	ldr r0, _080D7304 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r4, r2
	adds r1, r4, #0
	adds r1, #0x2c
	movs r2, #0
	bl FUN_082364c4
_080D72EC:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D7308
	adds r0, r4, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _080D7314
	.align 2, 0
_080D7304: .4byte 0x0000FFFB
_080D7308:
	adds r0, r4, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_080D7314:
	str r1, [r0]
	adds r0, r4, #0
	movs r1, #0x40
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D7330
	adds r0, r4, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _080D733A
_080D7330:
	adds r0, r4, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_080D733A:
	str r1, [r0]
	movs r1, #0xfe
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	ldrh r2, [r4, #0x2e]
	adds r0, r0, r2
	strh r0, [r4, #0x2e]
	movs r0, #0x82
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	movs r2, #0x83
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r2, _080D7370 @ =0x000003F6
	adds r0, r4, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D7370: .4byte 0x000003F6

	thumb_func_start FUN_080d7374
FUN_080d7374: @ 0x080D7374
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #0xb
	ldr r1, [r5, #0x20]
	orrs r1, r0
	str r1, [r5, #0x20]
	ldr r0, [r5, #0x1c]
	cmp r0, #1
	beq _080D738E
	cmp r0, #2
	beq _080D7420
	b _080D743C
_080D738E:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _080D73B6
	ldr r1, [r5, #0x18]
	ldr r0, _080D73A4 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080D73A8
	movs r0, #0
	b _080D73AE
	.align 2, 0
_080D73A4: .4byte 0x03002C68
_080D73A8:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_080D73AE:
	adds r1, r0, #0
	adds r0, r5, #0
	bl FUN_080d0394
_080D73B6:
	adds r0, r5, #0
	bl FUN_080d6600
	adds r0, r5, #0
	bl FUN_080d7210
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080cfaa4
	ldr r0, _080D7418 @ =0x085AD280
	lsls r4, r4, #2
	adds r4, r4, r0
	ldr r1, [r4]
	adds r0, r5, #0
	bl _call_via_r1
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D73F2
	adds r1, #4
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
_080D73F2:
	adds r0, r5, #0
	bl FUN_080d72a8
	ldr r1, _080D741C @ =0x000003CE
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _080D740A
	adds r0, r5, #0
	bl FUN_080cfb20
_080D740A:
	adds r0, r5, #0
	bl FUN_080cfcb0
	adds r0, r5, #0
	bl FUN_080d01c8
	b _080D743C
	.align 2, 0
_080D7418: .4byte 0x085AD280
_080D741C: .4byte 0x000003CE
_080D7420:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080cc3c4
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_080d72a8
_080D743C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d7444
FUN_080d7444: @ 0x080D7444
	push {r4, r5, lr}
	movs r1, #0
	ldr r5, _080D7460 @ =0x03002BE0
	ldrh r3, [r0, #0xa]
	movs r4, #1
	adds r2, r5, #0
_080D7450:
	adds r0, r3, #0
	asrs r0, r1
	ands r0, r4
	cmp r0, #0
	beq _080D7464
	ldr r0, [r2]
	b _080D746E
	.align 2, 0
_080D7460: .4byte 0x03002BE0
_080D7464:
	adds r2, #4
	adds r1, #1
	cmp r1, #3
	ble _080D7450
	ldr r0, [r5]
_080D746E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080d7474
FUN_080d7474: @ 0x080D7474
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #1
	bne _080D74DC
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x64
	bl Div
	adds r2, r0, #0
	cmp r2, #0
	bgt _080D7494
	movs r2, #1
_080D7494:
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r5, [r1]
	adds r3, r5, r2
	ldr r6, _080D74B0 @ =0x00000366
	adds r0, r4, r6
	ldrh r0, [r0]
	cmp r3, r0
	ble _080D74B4
	subs r2, r0, r5
	strh r0, [r1]
	b _080D74B6
	.align 2, 0
_080D74B0: .4byte 0x00000366
_080D74B4:
	strh r3, [r1]
_080D74B6:
	cmp r2, #0
	ble _080D74DC
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r3, r4, #0
	adds r3, #0x2c
	movs r5, #0x97
	lsls r5, r5, #4
	adds r1, r4, r5
	str r1, [sp]
	ldr r6, _080D74E4 @ =0x00000978
	adds r1, r4, r6
	ldrb r1, [r1]
	str r1, [sp, #4]
	adds r1, r2, #0
	movs r2, #1
	bl FUN_0805fe7c
_080D74DC:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D74E4: .4byte 0x00000978

	thumb_func_start FUN_080d74e8
FUN_080d74e8: @ 0x080D74E8
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #1
	bne _080D754C
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0x64
	bl Div
	adds r2, r0, #0
	cmp r2, #0
	bgt _080D7506
	movs r2, #1
_080D7506:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r5, [r1]
	adds r3, r5, r2
	ldr r6, _080D7520 @ =0x0000036A
	adds r0, r4, r6
	ldrh r0, [r0]
	cmp r3, r0
	ble _080D7524
	subs r2, r0, r5
	strh r0, [r1]
	b _080D7526
	.align 2, 0
_080D7520: .4byte 0x0000036A
_080D7524:
	strh r3, [r1]
_080D7526:
	cmp r2, #0
	ble _080D754C
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r3, r4, #0
	adds r3, #0x2c
	movs r5, #0x97
	lsls r5, r5, #4
	adds r1, r4, r5
	str r1, [sp]
	ldr r6, _080D7554 @ =0x00000978
	adds r1, r4, r6
	ldrb r1, [r1]
	str r1, [sp, #4]
	adds r1, r2, #0
	movs r2, #1
	bl FUN_0805fe7c
_080D754C:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D7554: .4byte 0x00000978

	thumb_func_start FUN_080d7558
FUN_080d7558: @ 0x080D7558
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r1, #0
	adds r7, r2, #0
	ldrh r0, [r5, #0x3c]
	cmp r0, #0
	ble _080D7576
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08236640
	b _080D757A
_080D7576:
	movs r0, #0
	strh r0, [r7, #0x3e]
_080D757A:
	adds r0, r5, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	movs r0, #0
	mov r8, r0
	adds r0, r5, #0
	adds r0, #0x40
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D75AC
	ldr r1, _080D75A4 @ =0x000003D6
	adds r0, r4, r1
	mov r2, r8
	strh r2, [r0]
	ldr r0, _080D75A8 @ =0x00000446
	adds r6, r4, r0
	b _080D761C
	.align 2, 0
_080D75A4: .4byte 0x000003D6
_080D75A8: .4byte 0x00000446
_080D75AC:
	ldr r2, _080D7664 @ =0x000003D6
	adds r1, r4, r2
	movs r0, #0xe6
	strh r0, [r1]
	movs r6, #0xd6
	lsls r6, r6, #2
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D75DA
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0xd
	bne _080D75DA
	subs r2, #0x56
	adds r0, r4, r2
	movs r1, #1
	strb r1, [r0]
	adds r6, #0x29
	adds r0, r4, r6
	strb r1, [r0]
_080D75DA:
	ldr r1, _080D7668 @ =0x00000446
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0
	adds r6, r0, #0
	cmp r1, #0
	beq _080D75F4
	ldr r1, _080D766C @ =0x00000442
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #6
	bne _080D75F4
	movs r2, #1
_080D75F4:
	cmp r2, #0
	beq _080D7612
	ldr r2, _080D766C @ =0x00000442
	adds r0, r4, r2
	movs r1, #0
	strh r1, [r0]
	adds r2, #4
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, r4, #0
	adds r2, #0xe8
	ldr r0, [r2]
	ldr r1, _080D7670 @ =0xFFFFFBFF
	ands r0, r1
	str r0, [r2]
_080D7612:
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r7, #0
	bl FUN_080cc4f4
_080D761C:
	movs r1, #0x10
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080D7630
	adds r0, r4, #0
	adds r0, #0x2c
	ldr r1, [r4, #0x18]
	bl FUN_081df698
_080D7630:
	ldrh r0, [r6]
	movs r1, #0
	cmp r0, #0
	beq _080D7644
	ldr r2, _080D766C @ =0x00000442
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #3
	bne _080D7644
	movs r1, #1
_080D7644:
	cmp r1, #0
	beq _080D7674
	movs r0, #0
	strh r0, [r7, #0x3e]
	movs r6, #0
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _080D765C
	b _080D784E
_080D765C:
	adds r0, r4, #0
	bl FUN_080cdda8
	b _080D784E
	.align 2, 0
_080D7664: .4byte 0x000003D6
_080D7668: .4byte 0x00000446
_080D766C: .4byte 0x00000442
_080D7670: .4byte 0xFFFFFBFF
_080D7674:
	ldrh r0, [r6]
	movs r1, #0
	cmp r0, #0
	beq _080D7688
	ldr r6, _080D76DC @ =0x00000442
	adds r0, r4, r6
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D7688
	movs r1, #1
_080D7688:
	cmp r1, #0
	bne _080D76A4
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080D76A4
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D76A8
_080D76A4:
	movs r6, #1
	add r8, r6
_080D76A8:
	movs r0, #4
	ldr r1, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080D76EC
	adds r0, r7, #0
	adds r0, #0x43
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D773C
	ldr r1, _080D76E0 @ =0x000003D2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D76D2
	ldr r2, _080D76E4 @ =0x000003D6
	adds r1, r4, r2
	ldr r0, _080D76E8 @ =0x00000191
	strh r0, [r1]
_080D76D2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08063288
	b _080D773C
	.align 2, 0
_080D76DC: .4byte 0x00000442
_080D76E0: .4byte 0x000003D2
_080D76E4: .4byte 0x000003D6
_080D76E8: .4byte 0x00000191
_080D76EC:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080D772C
	adds r0, r7, #0
	adds r0, #0x43
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D773C
	ldr r6, _080D7720 @ =0x000003D2
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D7714
	ldr r0, _080D7724 @ =0x000003D6
	adds r1, r4, r0
	ldr r0, _080D7728 @ =0x00000133
	strh r0, [r1]
_080D7714:
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08063288
	b _080D773C
	.align 2, 0
_080D7720: .4byte 0x000003D2
_080D7724: .4byte 0x000003D6
_080D7728: .4byte 0x00000133
_080D772C:
	movs r0, #0x80
	lsls r0, r0, #0xb
	ands r1, r0
	cmp r1, #0
	beq _080D773C
	adds r0, r4, #0
	bl FUN_080cdda8
_080D773C:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080D7754
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08063574
_080D7754:
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080D776C
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08063574
_080D776C:
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080D77FA
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D77A8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080D77AC
	asrs r0, r0, #0xc
	b _080D77B2
	.align 2, 0
_080D77A8: .4byte 0x085B0A08
_080D77AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D77B2:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xc8
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #4]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080D77D4
	asrs r0, r0, #0xc
	b _080D77DA
_080D77D4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D77DA:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D786C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r0, #0x2c
	movs r1, #1
	str r1, [sp]
	add r1, sp, #4
	movs r2, #0
	movs r3, #0
	bl FUN_080dc0b8
_080D77FA:
	ldrh r6, [r7, #0x3e]
	mov r0, r8
	lsls r6, r0
	movs r0, #0
	strh r0, [r7, #0x3e]
	ldr r0, [r5, #0x34]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080D7844
	movs r1, #0xf
	ldrh r0, [r5, #0xa]
	ands r0, r1
	cmp r0, #0
	beq _080D7844
	movs r1, #0x20
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080D782E
	adds r0, r5, #0
	bl FUN_080d7444
	adds r1, r6, #0
	bl FUN_080d7474
_080D782E:
	movs r1, #2
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080D7844
	adds r0, r5, #0
	bl FUN_080d7444
	adds r1, r6, #0
	bl FUN_080d74e8
_080D7844:
	ldr r2, _080D7870 @ =0x00000376
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, r0, r6
	strh r0, [r1]
_080D784E:
	ldrh r1, [r5, #0xa]
	ldr r2, _080D7874 @ =0x0000045A
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _080D7878 @ =0x0000045C
	adds r1, r4, r0
	ldr r0, [r5, #0x34]
	str r0, [r1]
	adds r0, r6, #0
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080D786C: .4byte 0xFFFF0000
_080D7870: .4byte 0x00000376
_080D7874: .4byte 0x0000045A
_080D7878: .4byte 0x0000045C

	thumb_func_start FUN_080d787c
FUN_080d787c: @ 0x080D787C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r1, [r5, #0x1c]
	cmp r1, #1
	bne _080D78D4
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r3, [r6, #6]
	ands r0, r3
	cmp r0, #0
	beq _080D78AC
	movs r0, #0x46
	adds r0, r0, r4
	mov ip, r0
	ldrb r2, [r0]
	ands r1, r2
	cmp r1, #0
	beq _080D78D4
	movs r0, #0xfe
	ands r0, r2
	mov r1, ip
	strb r0, [r1]
_080D78AC:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r3, r0
	cmp r3, #0
	beq _080D78CA
	adds r3, r4, #0
	adds r3, #0x46
	ldrb r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D78D4
	movs r0, #2
	orrs r0, r1
	strb r0, [r3]
_080D78CA:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_080d7558
_080D78D4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d78dc
FUN_080d78dc: @ 0x080D78DC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	ldrh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D790A
	cmp r1, #0
	blt _080D790A
	ldr r0, _080D7910 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D790A
	ldr r0, _080D7914 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D7918
_080D790A:
	movs r4, #0
	b _080D7926
	.align 2, 0
_080D7910: .4byte 0x030046A8
_080D7914: .4byte 0x030046AC
_080D7918:
	ldr r0, _080D7938 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D7926:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D793C
	adds r0, #4
	b _080D7948
	.align 2, 0
_080D7938: .4byte 0x030046A4
_080D793C:
	ldr r0, _080D7978 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D7948:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080D79B0
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D79B0
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r0, _080D797C @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080D7980 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D7984
	movs r0, #1
	b _080D7986
	.align 2, 0
_080D7978: .4byte 0x030046A4
_080D797C: .4byte 0x030046A0
_080D7980: .4byte 0x00000934
_080D7984:
	movs r0, #0
_080D7986:
	cmp r0, #0
	beq _080D7996
	adds r0, r5, #0
	movs r1, #0x1d
	movs r2, #0
	bl FUN_080cc348
	b _080D79A0
_080D7996:
	adds r0, r5, #0
	movs r1, #0x1c
	movs r2, #0
	bl FUN_080cc348
_080D79A0:
	ldr r4, _080D79AC @ =0x00000376
	adds r1, r5, r4
	movs r0, #0
	strh r0, [r1]
	b _080D7B40
	.align 2, 0
_080D79AC: .4byte 0x00000376
_080D79B0:
	movs r7, #0
	mov r8, r7
	ldr r1, _080D79CC @ =0x00000376
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D79EC
	ldr r0, _080D79D0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080D79D4
	movs r1, #1
	rsbs r1, r1, #0
	b _080D79D8
	.align 2, 0
_080D79CC: .4byte 0x00000376
_080D79D0: .4byte 0x03002C68
_080D79D4:
	movs r2, #0x18
	ldrsh r1, [r0, r2]
_080D79D8:
	ldr r4, _080D7ADC @ =0x0000045A
	adds r0, r5, r4
	movs r7, #0
	ldrsh r0, [r0, r7]
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D79EC
	mov r8, r1
_080D79EC:
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D7A08
	adds r0, r5, #0
	bl FUN_080cfdec
	ldr r4, _080D7AE0 @ =0x00000376
	adds r2, r5, r4
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
_080D7A08:
	movs r7, #0xd8
	lsls r7, r7, #1
	adds r0, r5, r7
	ldrh r3, [r0]
	cmp r3, #0
	bne _080D7A84
	ldr r1, _080D7AE4 @ =0x0000043E
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D7A3E
	movs r4, #0xf6
	lsls r4, r4, #2
	adds r2, r5, r4
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080D7A3E
	ldr r7, _080D7AE0 @ =0x00000376
	adds r1, r5, r7
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	strh r3, [r2]
_080D7A3E:
	ldr r1, _080D7AE8 @ =0x000004C5
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D7A84
	ldr r4, _080D7AEC @ =0x000004C7
	adds r2, r5, r4
	ldrb r0, [r2]
	cmp r0, #0
	beq _080D7A84
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r0, [r5, #0x20]
	orrs r0, r1
	str r0, [r5, #0x20]
	ldr r7, _080D7AF0 @ =0x000003DA
	adds r6, r5, r7
	ldrh r4, [r6]
	adds r4, #1
	strh r4, [r6]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldrb r1, [r2]
	movs r0, #0x3c
	bl Div
	cmp r4, r0
	blt _080D7A84
	ldr r1, _080D7AE0 @ =0x00000376
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #0xa
	strh r1, [r0]
	movs r0, #0
	strh r0, [r6]
_080D7A84:
	ldr r2, _080D7AE0 @ =0x00000376
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D7B00
	ldr r4, _080D7AF4 @ =0x00000446
	adds r0, r5, r4
	ldrh r0, [r0]
	movs r6, #0
	cmp r0, #0
	beq _080D7AA6
	ldr r7, _080D7AF8 @ =0x00000442
	adds r0, r5, r7
	ldrh r0, [r0]
	cmp r0, #3
	bne _080D7AA6
	movs r6, #1
_080D7AA6:
	cmp r6, #0
	bne _080D7B00
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, _080D7AE0 @ =0x00000376
	adds r4, r5, r2
	ldrh r1, [r4]
	adds r3, r5, #0
	adds r3, #0x2c
	movs r7, #0x97
	lsls r7, r7, #4
	adds r2, r5, r7
	str r2, [sp]
	str r6, [sp, #4]
	movs r2, #0
	bl FUN_0805fe7c
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrh r2, [r1]
	ldrh r0, [r4]
	cmp r2, r0
	bhs _080D7AFC
	strh r6, [r1]
	b _080D7B00
	.align 2, 0
_080D7ADC: .4byte 0x0000045A
_080D7AE0: .4byte 0x00000376
_080D7AE4: .4byte 0x0000043E
_080D7AE8: .4byte 0x000004C5
_080D7AEC: .4byte 0x000004C7
_080D7AF0: .4byte 0x000003DA
_080D7AF4: .4byte 0x00000446
_080D7AF8: .4byte 0x00000442
_080D7AFC:
	subs r0, r2, r0
	strh r0, [r1]
_080D7B00:
	ldr r1, _080D7B38 @ =0x00000376
	adds r0, r5, r1
	movs r3, #0
	strh r3, [r0]
	mov r2, r8
	cmp r2, #0
	beq _080D7B26
	ldrh r0, [r5, #0x24]
	movs r4, #0xd9
	lsls r4, r4, #2
	adds r1, r5, r4
	ldrh r1, [r1]
	ldr r7, _080D7B3C @ =0x00000366
	adds r2, r5, r7
	ldrh r2, [r2]
	str r3, [sp]
	movs r3, #0xa
	bl FUN_0809c344
_080D7B26:
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D7B40
	movs r0, #0
	b _080D7B42
	.align 2, 0
_080D7B38: .4byte 0x00000376
_080D7B3C: .4byte 0x00000366
_080D7B40:
	movs r0, #1
_080D7B42:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d7b50
FUN_080d7b50: @ 0x080D7B50
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r5, [r0]
	cmp r5, #0
	ble _080D7BA4
	adds r0, r4, #0
	movs r1, #8
	bl FUN_080cc3c4
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D7BA4
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _080D7BA4
	cmp r0, #0x19
	beq _080D7BA4
	subs r5, #1
	cmp r5, #0
	beq _080D7B9C
	asrs r0, r5, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D7B9C
	adds r0, r4, #0
	movs r1, #5
	bl FUN_080cc3c4
_080D7B9C:
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
_080D7BA4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d7bac
FUN_080d7bac: @ 0x080D7BAC
	push {lr}
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	bne _080D7BBC
	movs r0, #0
	b _080D7BC0
_080D7BBC:
	bl Script_GetValue
_080D7BC0:
	pop {r1}
	bx r1

	thumb_func_start FUN_080d7bc4
FUN_080d7bc4: @ 0x080D7BC4
	ldr r3, _080D7BD8 @ =0x0000095E
	adds r2, r0, r3
	strh r1, [r2]
	movs r1, #0x96
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r1, #0x20
	strh r1, [r0]
	bx lr
	.align 2, 0
_080D7BD8: .4byte 0x0000095E

	thumb_func_start FUN_080d7bdc
FUN_080d7bdc: @ 0x080D7BDC
	push {r4, r5, lr}
	bl FUN_080d7bac
	ldr r1, _080D7C14 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	bne _080D7BF0
	b _080D7F3C
_080D7BF0:
	movs r0, #0x54
	bl prepare_08231510
	cmp r0, #0
	bne _080D7BFC
	b _080D7F3C
_080D7BFC:
	bl Script_GetValue
	subs r0, #2
	cmp r0, #0x15
	bls _080D7C08
	b _080D7F3C
_080D7C08:
	lsls r0, r0, #2
	ldr r1, _080D7C18 @ =_080D7C1C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D7C14: .4byte 0x03002BE0
_080D7C18: .4byte _080D7C1C
_080D7C1C: @ jump table
	.4byte _080D7D60 @ case 0
	.4byte _080D7D8C @ case 1
	.4byte _080D7F3C @ case 2
	.4byte _080D7F3C @ case 3
	.4byte _080D7DB8 @ case 4
	.4byte _080D7DF0 @ case 5
	.4byte _080D7F00 @ case 6
	.4byte _080D7E18 @ case 7
	.4byte _080D7E40 @ case 8
	.4byte _080D7E84 @ case 9
	.4byte _080D7F3C @ case 10
	.4byte _080D7F3C @ case 11
	.4byte _080D7EBC @ case 12
	.4byte _080D7CA8 @ case 13
	.4byte _080D7C74 @ case 14
	.4byte _080D7CDC @ case 15
	.4byte _080D7F3C @ case 16
	.4byte _080D7F3C @ case 17
	.4byte _080D7F3C @ case 18
	.4byte _080D7F3C @ case 19
	.4byte _080D7CF8 @ case 20
	.4byte _080D7D2C @ case 21
_080D7C74:
	ldr r0, _080D7CA4 @ =0x00000366
	adds r4, r5, r0
	ldrh r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x64
	bl Div
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	ldrh r4, [r4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r4
	bhi _080D7C9E
	b _080D7E6A
_080D7C9E:
	strh r4, [r2]
	b _080D7E6A
	.align 2, 0
_080D7CA4: .4byte 0x00000366
_080D7CA8:
	ldr r0, _080D7CD8 @ =0x00000366
	adds r4, r5, r0
	ldrh r1, [r4]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x64
	bl Div
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	ldrh r4, [r4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r4
	bhi _080D7CD2
	b _080D7E6A
_080D7CD2:
	strh r4, [r2]
	b _080D7E6A
	.align 2, 0
_080D7CD8: .4byte 0x00000366
_080D7CDC:
	ldr r0, _080D7CF4 @ =0x00000366
	adds r4, r5, r0
	ldrh r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0x64
	bl Div
	movs r1, #0xd9
	lsls r1, r1, #2
	b _080D7ED2
	.align 2, 0
_080D7CF4: .4byte 0x00000366
_080D7CF8:
	ldr r0, _080D7D28 @ =0x00000366
	adds r4, r5, r0
	ldrh r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	movs r1, #0x64
	bl Div
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	ldrh r4, [r4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r4
	bhi _080D7D22
	b _080D7E6A
_080D7D22:
	strh r4, [r2]
	b _080D7E6A
	.align 2, 0
_080D7D28: .4byte 0x00000366
_080D7D2C:
	ldr r0, _080D7D5C @ =0x0000036A
	adds r4, r5, r0
	ldrh r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	movs r1, #0x64
	bl Div
	movs r1, #0xda
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	ldrh r4, [r4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r4
	bhi _080D7D56
	b _080D7E6A
_080D7D56:
	strh r4, [r2]
	b _080D7E6A
	.align 2, 0
_080D7D5C: .4byte 0x0000036A
_080D7D60:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D7D6E
	b _080D7EE6
_080D7D6E:
	cmp r0, #3
	bne _080D7D74
	b _080D7EE6
_080D7D74:
	ldr r0, _080D7D84 @ =0x00000442
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	ldr r0, _080D7D88 @ =0x00000444
	adds r1, r5, r0
	movs r0, #2
	b _080D7E5E
	.align 2, 0
_080D7D84: .4byte 0x00000442
_080D7D88: .4byte 0x00000444
_080D7D8C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D7D9A
	b _080D7EE6
_080D7D9A:
	cmp r0, #3
	bne _080D7DA0
	b _080D7EE6
_080D7DA0:
	ldr r0, _080D7DB0 @ =0x00000442
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080D7DB4 @ =0x00000444
	adds r1, r5, r0
	movs r0, #3
	b _080D7E5E
	.align 2, 0
_080D7DB0: .4byte 0x00000442
_080D7DB4: .4byte 0x00000444
_080D7DB8:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D7DC6
	b _080D7EE6
_080D7DC6:
	cmp r0, #3
	bne _080D7DCC
	b _080D7EE6
_080D7DCC:
	ldr r0, _080D7DE4 @ =0x00000442
	adds r1, r5, r0
	movs r0, #3
	strh r0, [r1]
	ldr r0, _080D7DE8 @ =0x00000444
	adds r1, r5, r0
	movs r0, #6
	strh r0, [r1]
	ldr r0, _080D7DEC @ =0x00000446
	adds r1, r5, r0
	subs r0, #0xc2
	b _080D7E68
	.align 2, 0
_080D7DE4: .4byte 0x00000442
_080D7DE8: .4byte 0x00000444
_080D7DEC: .4byte 0x00000446
_080D7DF0:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D7EE6
	cmp r0, #3
	beq _080D7EE6
	ldr r0, _080D7E10 @ =0x00000442
	adds r1, r5, r0
	movs r0, #4
	strh r0, [r1]
	ldr r0, _080D7E14 @ =0x00000444
	adds r1, r5, r0
	movs r0, #7
	b _080D7E5E
	.align 2, 0
_080D7E10: .4byte 0x00000442
_080D7E14: .4byte 0x00000444
_080D7E18:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D7EE6
	cmp r0, #3
	beq _080D7EE6
	ldr r0, _080D7E38 @ =0x00000442
	adds r1, r5, r0
	movs r0, #5
	strh r0, [r1]
	ldr r0, _080D7E3C @ =0x00000444
	adds r1, r5, r0
	movs r0, #9
	b _080D7E5E
	.align 2, 0
_080D7E38: .4byte 0x00000442
_080D7E3C: .4byte 0x00000444
_080D7E40:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D7EE6
	cmp r0, #3
	beq _080D7EE6
	ldr r0, _080D7E74 @ =0x00000442
	adds r1, r5, r0
	movs r0, #6
	strh r0, [r1]
	ldr r0, _080D7E78 @ =0x00000444
	adds r1, r5, r0
	movs r0, #0xa
_080D7E5E:
	strh r0, [r1]
	ldr r0, _080D7E7C @ =0x00000446
	adds r1, r5, r0
	movs r0, #0xe1
	lsls r0, r0, #3
_080D7E68:
	strh r0, [r1]
_080D7E6A:
	ldr r1, _080D7E80 @ =0x00000121
	adds r0, r5, #0
	bl FUN_080d7bc4
	b _080D7F3C
	.align 2, 0
_080D7E74: .4byte 0x00000442
_080D7E78: .4byte 0x00000444
_080D7E7C: .4byte 0x00000446
_080D7E80: .4byte 0x00000121
_080D7E84:
	ldr r1, _080D7EB8 @ =0x0000036A
	adds r4, r5, r1
	ldrh r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r1, #0x64
	bl Div
	movs r1, #0xda
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	ldrh r4, [r4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r4
	bls _080D7EAE
	strh r4, [r2]
_080D7EAE:
	movs r2, #0x96
	lsls r2, r2, #2
	adds r0, r5, #0
	movs r1, #2
	b _080D7EEE
	.align 2, 0
_080D7EB8: .4byte 0x0000036A
_080D7EBC:
	ldr r0, _080D7EFC @ =0x0000036A
	adds r4, r5, r0
	ldrh r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r1, #0x64
	bl Div
	movs r1, #0xda
	lsls r1, r1, #2
_080D7ED2:
	adds r2, r5, r1
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	ldrh r4, [r4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r4
	bls _080D7EE6
	strh r4, [r2]
_080D7EE6:
	movs r2, #0x96
	lsls r2, r2, #2
	adds r0, r5, #0
	movs r1, #0
_080D7EEE:
	bl FUN_08063574
	adds r0, r5, #0
	movs r1, #0x21
	bl FUN_080d7bc4
	b _080D7F3C
	.align 2, 0
_080D7EFC: .4byte 0x0000036A
_080D7F00:
	ldr r0, _080D7F44 @ =0x00000366
	adds r4, r5, r0
	ldrh r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0x64
	bl Div
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	ldrh r4, [r4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r4
	bls _080D7F28
	strh r4, [r2]
_080D7F28:
	movs r2, #0x96
	lsls r2, r2, #2
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08063574
	adds r0, r5, #0
	movs r1, #0x21
	bl FUN_080d7bc4
_080D7F3C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D7F44: .4byte 0x00000366

	thumb_func_start FUN_080d7f48
FUN_080d7f48: @ 0x080D7F48
	push {r4, r5, r6, lr}
	bl FUN_080d7bac
	ldr r1, _080D7F98 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _080D7FB4
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _080D7FB4
	bl Script_GetValue
	adds r6, r0, #0
	ldr r0, _080D7F9C @ =0x00000455
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _080D7F82
	adds r0, r5, #0
	adds r0, #0x2c
	movs r1, #0
	ldrsb r1, [r4, r1]
	bl FUN_081df9ac
_080D7F82:
	strb r6, [r4]
	movs r2, #0
	ldrsb r2, [r4, r2]
	ldr r0, _080D7FA0 @ =0x03002C68
	ldr r1, [r0]
	cmp r1, #0
	beq _080D7F94
	cmp r2, #0
	bge _080D7FA4
_080D7F94:
	movs r1, #0
	b _080D7FAE
	.align 2, 0
_080D7F98: .4byte 0x03002BE0
_080D7F9C: .4byte 0x00000455
_080D7FA0: .4byte 0x03002C68
_080D7FA4:
	lsls r0, r2, #3
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, #0x88
	adds r1, r1, r0
_080D7FAE:
	adds r0, r5, #0
	bl player_weapon_080ceafc
_080D7FB4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d7fbc
FUN_080d7fbc: @ 0x080D7FBC
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D7FCE
	b _080D80D2
_080D7FCE:
	ldr r2, _080D8038 @ =0x00000381
	adds r0, r4, r2
	ldrb r1, [r0]
	cmp r1, #2
	beq _080D80D2
	cmp r1, #4
	beq _080D80D2
	cmp r1, #3
	bne _080D8054
	subs r2, #0x29
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	movs r0, #0xac
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, _080D803C @ =FUN_080d7374
	str r0, [r1]
	ldr r0, _080D8040 @ =0x00000359
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	str r2, [r4, #0x50]
	adds r0, r4, #0
	adds r0, #0xe8
	str r0, [r4, #0x4c]
	ldr r2, _080D8044 @ =0x000004CC
	adds r1, r4, r2
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r4, r2
	str r0, [r1]
	ldr r0, _080D8048 @ =0x0000094C
	adds r1, r4, r0
	ldr r0, _080D804C @ =0x0000FFFF
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
	ldr r2, _080D8050 @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
	b _080D80B2
	.align 2, 0
_080D8038: .4byte 0x00000381
_080D803C: .4byte FUN_080d7374
_080D8040: .4byte 0x00000359
_080D8044: .4byte 0x000004CC
_080D8048: .4byte 0x0000094C
_080D804C: .4byte 0x0000FFFF
_080D8050: .4byte 0x0000095E
_080D8054:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xac
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, _080D80D8 @ =FUN_080d6b24
	str r0, [r1]
	ldr r1, _080D80DC @ =0x00000359
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	adds r0, #0x88
	str r0, [r4, #0x50]
	str r2, [r4, #0x4c]
	ldr r2, _080D80E0 @ =0x000004CC
	adds r1, r4, r2
	adds r0, #0x20
	str r0, [r1]
	ldr r0, _080D80E4 @ =0x0000094C
	adds r1, r4, r0
	ldr r0, _080D80E8 @ =0x0000FFFF
	strh r0, [r1]
	ldr r2, _080D80EC @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080ced00
	adds r0, #1
	ldr r2, _080D80F0 @ =0x00000951
	adds r1, r4, r2
	strb r0, [r1]
	adds r0, #1
	subs r2, #1
	adds r1, r4, r2
	strb r0, [r1]
_080D80B2:
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r0, r4, #0
	bl FUN_080cec70
	ldr r2, _080D80F4 @ =0x00000282
	adds r1, r4, r2
	movs r2, #0
	strb r0, [r1]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
_080D80D2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D80D8: .4byte FUN_080d6b24
_080D80DC: .4byte 0x00000359
_080D80E0: .4byte 0x000004CC
_080D80E4: .4byte 0x0000094C
_080D80E8: .4byte 0x0000FFFF
_080D80EC: .4byte 0x0000095E
_080D80F0: .4byte 0x00000951
_080D80F4: .4byte 0x00000282

	thumb_func_start FUN_080d80f8
FUN_080d80f8: @ 0x080D80F8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080cc370
	ldr r0, [r4, #0x1c]
	cmp r0, #1
	bne _080D811E
	adds r0, r4, #0
	bl FUN_080d78dc
	cmp r0, #0
	beq _080D8118
	adds r0, r4, #0
	bl FUN_080d040c
	b _080D811E
_080D8118:
	adds r0, r4, #0
	bl FUN_080d7b50
_080D811E:
	adds r0, r4, #0
	bl FUN_080d7fbc
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080ce28c
	ldr r1, _080D8154 @ =0x03002BC0
	ldr r0, [r4, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x1c]
	str r1, [r0]
	ldr r0, _080D8158 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080D815C
	movs r1, #1
	rsbs r1, r1, #0
	b _080D8160
	.align 2, 0
_080D8154: .4byte 0x03002BC0
_080D8158: .4byte 0x03002C68
_080D815C:
	movs r2, #0x18
	ldrsh r1, [r0, r2]
_080D8160:
	ldr r0, [r4, #0x18]
	cmp r0, r1
	bne _080D8192
	ldr r1, _080D81C4 @ =0x030046A0
	ldr r2, [r1]
	ldrh r0, [r4, #0x2c]
	strh r0, [r2, #0x30]
	ldr r2, [r1]
	ldrh r0, [r4, #0x2e]
	strh r0, [r2, #0x32]
	ldr r2, [r1]
	ldrh r0, [r4, #0x30]
	strh r0, [r2, #0x34]
	ldr r2, [r1]
	ldr r0, _080D81C8 @ =0x00000932
	adds r2, r2, r0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	strh r0, [r2]
_080D8192:
	ldr r2, _080D81CC @ =0x0000045A
	adds r0, r4, r2
	movs r1, #0
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r0, [r4, #0x1c]
	cmp r0, #8
	beq _080D81BC
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x2c
	str r1, [r0]
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r4, r2
	bl FUN_08234660
_080D81BC:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080D81C4: .4byte 0x030046A0
_080D81C8: .4byte 0x00000932
_080D81CC: .4byte 0x0000045A

	thumb_func_start FUN_080d81d0
FUN_080d81d0: @ 0x080D81D0
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_080f8cac
	adds r0, r4, #0
	adds r0, #0x88
	bl FUN_0822f1c0
	adds r0, r4, #0
	adds r0, #0xe8
	bl FUN_0822a4e0
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08236424
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_0823b284
	adds r0, r4, #0
	bl FUN_080ce330
	adds r0, r4, #0
	bl FUN_080cc43c
	ldr r1, _080D8228 @ =0x03002BE0
	ldr r0, [r4, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	ldr r1, _080D822C @ =0x03002B98
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080D8228: .4byte 0x03002BE0
_080D822C: .4byte 0x03002B98

	thumb_func_start FUN_080d8230
FUN_080d8230: @ 0x080D8230
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	bl FUN_080cef14
	adds r0, r5, #0
	bl FUN_080cf0b4
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080cf3c0
	adds r0, r5, #0
	bl FUN_080cf560
	adds r0, r5, #0
	bl FUN_080ceec0
	adds r0, r5, #0
	bl FUN_080cf54c
	adds r0, r5, #0
	bl FUN_080cf610
	adds r0, r5, #0
	bl FUN_080ce378
	ldr r1, _080D8280 @ =0x03002BC0
	ldr r0, [r5, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r5, #0x1c]
	str r1, [r0]
	ldr r0, _080D8284 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080D8288
	movs r1, #1
	rsbs r1, r1, #0
	b _080D828C
	.align 2, 0
_080D8280: .4byte 0x03002BC0
_080D8284: .4byte 0x03002C68
_080D8288:
	movs r2, #0x18
	ldrsh r1, [r0, r2]
_080D828C:
	ldr r0, [r5, #0x18]
	cmp r0, r1
	bne _080D82BE
	ldr r1, _080D82DC @ =0x030046A0
	ldr r2, [r1]
	ldrh r0, [r5, #0x2c]
	strh r0, [r2, #0x30]
	ldr r2, [r1]
	ldrh r0, [r5, #0x2e]
	strh r0, [r2, #0x32]
	ldr r2, [r1]
	ldrh r0, [r5, #0x30]
	strh r0, [r2, #0x34]
	ldr r2, [r1]
	ldr r0, _080D82E0 @ =0x00000932
	adds r2, r2, r0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	strh r0, [r2]
_080D82BE:
	ldr r1, _080D82E4 @ =0x03002BE0
	adds r0, r5, #0
	adds r0, #0x28
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r5, [r0]
	ldr r1, _080D82E8 @ =0x03002B98
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080D82DC: .4byte 0x030046A0
_080D82E0: .4byte 0x00000932
_080D82E4: .4byte 0x03002BE0
_080D82E8: .4byte 0x03002B98

	thumb_func_start CreatePlayer_080d82ec
CreatePlayer_080d82ec: @ 0x080D82EC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, _080D8320 @ =0x00000AC4
	movs r0, #6
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080D832C
	ldr r1, _080D8324 @ =FUN_080d80f8
	ldr r2, _080D8328 @ =FUN_080d81d0
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080d8230
	cmp r0, #0
	bge _080D832C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080D832E
	.align 2, 0
_080D8320: .4byte 0x00000AC4
_080D8324: .4byte FUN_080d80f8
_080D8328: .4byte FUN_080d81d0
_080D832C:
	adds r0, r4, #0
_080D832E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080d8334
FUN_080d8334: @ 0x080D8334
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xb0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080D8348
	subs r0, #1
	strh r0, [r1]
	b _080D838A
_080D8348:
	adds r5, r4, #0
	adds r5, #0xb2
	ldrh r0, [r5]
	lsrs r0, r0, #2
	strh r0, [r4, #0x28]
	ldrh r0, [r5]
	cmp r0, #0
	bne _080D8368
	ldr r0, [r4, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x18]
	ldr r0, _080D8394 @ =0x00000195
	bl PlaySound_082406e0
_080D8368:
	ldrh r0, [r5]
	cmp r0, #7
	bhi _080D8376
	adds r0, r4, #0
	adds r0, #0x60
	bl FUN_08236400
_080D8376:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _080D838A
	adds r0, r4, #0
	bl KillEntity
_080D838A:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080D8394: .4byte 0x00000195

	thumb_func_start FUN_080d8398
FUN_080d8398: @ 0x080D8398
	push {lr}
	adds r0, #0x18
	bl FUN_0822a4e0
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d83a8
FUN_080d83a8: @ 0x080D83A8
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	adds r4, r3, #0
	ldr r1, _080D83F8 @ =0x00008639
	adds r0, r6, #0
	bl FUN_0822b16c
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0822a470
	movs r0, #0
	strh r0, [r5, #0x10]
	ldr r0, _080D83FC @ =0x00000113
	adds r4, r4, r0
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_0822b20c
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	movs r1, #1
	strb r1, [r5, #7]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D83F8: .4byte 0x00008639
_080D83FC: .4byte 0x00000113

	thumb_func_start FUN_080d8400
FUN_080d8400: @ 0x080D8400
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	mov sb, r0
	adds r5, r1, #0
	mov r8, r3
	ldr r6, [sp, #0x3c]
	ldr r7, [sp, #0x40]
	ldr r3, _080D8480 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r4, #0x80
	orrs r0, r4
	ldr r1, _080D8484 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r4
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r3
	str r0, [r1, #4]
	ldr r3, _080D8488 @ =0x00002001
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	adds r2, r3, #0
	movs r3, #0
	bl FUN_0823646c
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	mov r1, r8
	ldr r2, [sp, #0x38]
	movs r3, #0x40
	bl FUN_082364f8
	adds r0, r5, #0
	movs r1, #0
	mov r2, sb
	bl FUN_0823651c
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D8480: .4byte 0xFFFF0000
_080D8484: .4byte 0x0000FFFF
_080D8488: .4byte 0x00002001

	thumb_func_start FUN_080d848c
FUN_080d848c: @ 0x080D848C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov r8, r1
	mov sb, r2
	mov sl, r3
	ldr r5, [sp, #0x2c]
	ldr r6, [sp, #0x30]
	ldr r3, [sp, #0x38]
	adds r0, #0x18
	adds r1, r7, #0
	adds r1, #0x44
	mov r2, r8
	bl FUN_080d83a8
	adds r4, r7, #0
	adds r4, #0x60
	str r5, [sp]
	str r6, [sp, #4]
	ldr r0, [sp, #0x34]
	str r0, [sp, #8]
	adds r0, r7, #0
	adds r1, r4, #0
	mov r2, sb
	mov r3, sl
	bl FUN_080d8400
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	adds r0, r7, #0
	adds r0, #0xb0
	movs r1, #0
	mov r2, sp
	ldrh r2, [r2, #0x3c]
	strh r2, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r0, #0
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d84f8
FUN_080d84f8: @ 0x080D84F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r0, #0xa
	movs r1, #0xb4
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080D8558
	ldr r1, _080D854C @ =FUN_080d8334
	ldr r2, _080D8550 @ =FUN_080d8398
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, _080D8554 @ =0x00240004
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_080d848c
	cmp r0, #0
	bge _080D8558
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080D855A
	.align 2, 0
_080D854C: .4byte FUN_080d8334
_080D8550: .4byte FUN_080d8398
_080D8554: .4byte 0x00240004
_080D8558:
	adds r0, r4, #0
_080D855A:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d8568
FUN_080d8568: @ 0x080D8568
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r0, #0xa
	movs r1, #0xb4
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080D85C8
	ldr r1, _080D85BC @ =FUN_080d8334
	ldr r2, _080D85C0 @ =FUN_080d8398
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, _080D85C4 @ =0x00240004
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0x10]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_080d848c
	cmp r0, #0
	bge _080D85C8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080D85CA
	.align 2, 0
_080D85BC: .4byte FUN_080d8334
_080D85C0: .4byte FUN_080d8398
_080D85C4: .4byte 0x00240004
_080D85C8:
	adds r0, r4, #0
_080D85CA:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d85d8
FUN_080d85d8: @ 0x080D85D8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r0, #0xa
	movs r1, #0xb4
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080D8634
	ldr r1, _080D862C @ =FUN_080d8334
	ldr r2, _080D8630 @ =FUN_080d8398
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #4]
	ldr r0, [sp, #0x30]
	str r0, [sp, #8]
	ldr r0, [sp, #0x34]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0x10]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_080d848c
	cmp r0, #0
	bge _080D8634
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080D8636
	.align 2, 0
_080D862C: .4byte FUN_080d8334
_080D8630: .4byte FUN_080d8398
_080D8634:
	adds r0, r4, #0
_080D8636:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d8644
FUN_080d8644: @ 0x080D8644
	push {r4, lr}
	movs r4, #0
	movs r3, #0
	adds r1, r0, #0
	adds r1, #0x32
	adds r2, r0, #0
	adds r2, #0x3e
	adds r0, #0x4c
_080D8654:
	strb r3, [r1]
	strb r3, [r1, #3]
	stm r0!, {r3}
	strh r3, [r2]
	adds r1, #1
	adds r2, #2
	adds r4, #1
	cmp r4, #2
	ble _080D8654
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d866c
FUN_080d866c: @ 0x080D866C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r3, [r5, #0x58]
	cmp r3, #0
	bne _080D8678
	b _080D877E
_080D8678:
	movs r0, #0x92
	lsls r0, r0, #3
	adds r1, r3, r0
	ldr r0, _080D8694 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _080D8698
	movs r0, #1
	b _080D869A
	.align 2, 0
_080D8694: .4byte 0x030046A0
_080D8698:
	movs r0, #0
_080D869A:
	cmp r0, #0
	beq _080D877E
	adds r2, r5, #0
	adds r2, #0x2e
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	adds r4, r2, #0
	cmp r0, #0
	bne _080D877E
	ldr r1, _080D86D0 @ =0x00000553
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	beq _080D877E
	ldr r2, _080D86D4 @ =0x000001DF
	adds r0, r3, r2
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #0x1d
	bhi _080D877E
	lsls r0, r0, #2
	ldr r1, _080D86D8 @ =_080D86DC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D86D0: .4byte 0x00000553
_080D86D4: .4byte 0x000001DF
_080D86D8: .4byte _080D86DC
_080D86DC: @ jump table
	.4byte _080D8758 @ case 0
	.4byte _080D877E @ case 1
	.4byte _080D8766 @ case 2
	.4byte _080D8754 @ case 3
	.4byte _080D877E @ case 4
	.4byte _080D877E @ case 5
	.4byte _080D877E @ case 6
	.4byte _080D877E @ case 7
	.4byte _080D877E @ case 8
	.4byte _080D8770 @ case 9
	.4byte _080D877E @ case 10
	.4byte _080D877E @ case 11
	.4byte _080D877E @ case 12
	.4byte _080D877E @ case 13
	.4byte _080D877E @ case 14
	.4byte _080D877E @ case 15
	.4byte _080D877E @ case 16
	.4byte _080D877E @ case 17
	.4byte _080D877E @ case 18
	.4byte _080D877E @ case 19
	.4byte _080D877E @ case 20
	.4byte _080D877E @ case 21
	.4byte _080D877E @ case 22
	.4byte _080D877E @ case 23
	.4byte _080D877E @ case 24
	.4byte _080D877E @ case 25
	.4byte _080D877E @ case 26
	.4byte _080D8754 @ case 27
	.4byte _080D877E @ case 28
	.4byte _080D8766 @ case 29
_080D8754:
	movs r0, #0xee
	b _080D8772
_080D8758:
	adds r0, r5, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D877E
	movs r0, #0xff
	b _080D8772
_080D8766:
	adds r0, r3, #0
	movs r1, #3
	bl FUN_080e81dc
	b _080D8776
_080D8770:
	ldr r0, _080D8784 @ =0x000001CF
_080D8772:
	bl PlaySound_082406e0
_080D8776:
	ldrb r1, [r4]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4]
_080D877E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D8784: .4byte 0x000001CF

	thumb_func_start FUN_080d8788
FUN_080d8788: @ 0x080D8788
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x5c
	movs r1, #0x3c
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bgt _080D8800
	movs r1, #1
	adds r0, r5, #0
	adds r0, #0x32
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D87B0
	movs r0, #1
	b _080D87B2
_080D87B0:
	movs r0, #0
_080D87B2:
	cmp r0, #0
	beq _080D884A
	adds r0, r5, #0
	bl FUN_080d8644
	movs r4, #0
	movs r0, #0
	strh r0, [r5, #0x24]
	str r0, [r5, #0x48]
	adds r0, r5, #0
	adds r0, #0x2d
	strb r4, [r0]
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
	str r0, [r7]
	adds r6, r5, #0
	adds r6, #0x39
	movs r0, #0
	ldrsb r0, [r6, r0]
	ldr r2, _080D87FC @ =0x000009FC
	add r2, r8
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_0822a4e0
	adds r0, r5, #0
	adds r0, #0x44
	strb r4, [r0]
	movs r0, #0xff
	strb r0, [r6]
	movs r0, #1
	b _080D884C
	.align 2, 0
_080D87FC: .4byte 0x000009FC
_080D8800:
	cmp r0, #0xa
	ble _080D883E
	movs r1, #1
	adds r0, r5, #0
	adds r0, #0x32
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D8816
	movs r0, #1
	b _080D8818
_080D8816:
	movs r0, #0
_080D8818:
	cmp r0, #0
	beq _080D883E
	ldr r2, _080D8858 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080D885C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080D8860 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x14
	bl Mod
	ldrh r1, [r7, #0x1c]
	subs r1, #0xa
	adds r1, r1, r0
	strh r1, [r7, #0x1c]
_080D883E:
	adds r0, r5, #0
	bl FUN_080d866c
	ldrh r0, [r5, #0x3c]
	subs r0, #1
	strh r0, [r5, #0x3c]
_080D884A:
	movs r0, #0
_080D884C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080D8858: .4byte 0x030046B8
_080D885C: .4byte 0x000003FF
_080D8860: .4byte 0x0203B400

	thumb_func_start FUN_080d8864
FUN_080d8864: @ 0x080D8864
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x5c
	movs r1, #0x3c
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bgt _080D889A
	movs r2, #1
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _080D8888
	movs r0, #1
	b _080D888A
_080D8888:
	movs r0, #0
_080D888A:
	cmp r0, #0
	beq _080D88DA
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r2]
	ands r0, r1
	strb r0, [r2]
	b _080D88DA
_080D889A:
	movs r1, #1
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D88AC
	movs r0, #1
	b _080D88AE
_080D88AC:
	movs r0, #0
_080D88AE:
	cmp r0, #0
	beq _080D88D4
	ldr r2, _080D88E0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080D88E4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080D88E8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x14
	bl Mod
	ldrh r1, [r5, #0x1c]
	subs r1, #0xa
	adds r1, r1, r0
	strh r1, [r5, #0x1c]
_080D88D4:
	ldrh r0, [r4, #0x3c]
	subs r0, #1
	strh r0, [r4, #0x3c]
_080D88DA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D88E0: .4byte 0x030046B8
_080D88E4: .4byte 0x000003FF
_080D88E8: .4byte 0x0203B400

	thumb_func_start FUN_080d88ec
FUN_080d88ec: @ 0x080D88EC
	push {lr}
	cmp r0, #1
	beq _080D8918
	cmp r0, #1
	bgt _080D88FC
	cmp r0, #0
	beq _080D8906
	b _080D894E
_080D88FC:
	cmp r0, #2
	beq _080D892A
	cmp r0, #3
	beq _080D8936
	b _080D894E
_080D8906:
	cmp r3, #0
	bne _080D8914
	movs r0, #0xc
	rsbs r0, r0, #0
	str r0, [r1]
	str r3, [r2]
	b _080D894E
_080D8914:
	str r0, [r1]
	b _080D894C
_080D8918:
	cmp r3, #3
	bgt _080D894E
	cmp r3, #0
	blt _080D894E
	movs r0, #0x10
	rsbs r0, r0, #0
	str r0, [r1]
	adds r0, #8
	b _080D894C
_080D892A:
	cmp r3, #0
	beq _080D8932
	cmp r3, #3
	bne _080D8942
_080D8932:
	movs r0, #0
	b _080D8946
_080D8936:
	cmp r3, #0
	beq _080D893E
	cmp r3, #3
	bne _080D8942
_080D893E:
	movs r0, #0
	b _080D8946
_080D8942:
	movs r0, #8
	rsbs r0, r0, #0
_080D8946:
	str r0, [r1]
	movs r0, #4
	rsbs r0, r0, #0
_080D894C:
	str r0, [r2]
_080D894E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d8954
FUN_080d8954: @ 0x080D8954
	push {lr}
	cmp r0, #1
	beq _080D8978
	cmp r0, #1
	bgt _080D8964
	cmp r0, #0
	beq _080D896E
	b _080D898A
_080D8964:
	cmp r0, #2
	beq _080D8982
	cmp r0, #3
	beq _080D8982
	b _080D898A
_080D896E:
	movs r0, #4
	rsbs r0, r0, #0
	str r0, [r1]
	subs r0, #0xb
	b _080D8988
_080D8978:
	movs r0, #0x10
	rsbs r0, r0, #0
	str r0, [r1]
	adds r0, #8
	b _080D8988
_080D8982:
	movs r0, #4
	rsbs r0, r0, #0
	str r0, [r1]
_080D8988:
	str r0, [r2]
_080D898A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d8990
FUN_080d8990: @ 0x080D8990
	push {lr}
	cmp r0, #1
	beq _080D89B4
	cmp r0, #1
	bgt _080D89A0
	cmp r0, #0
	beq _080D89AA
	b _080D89C6
_080D89A0:
	cmp r0, #2
	beq _080D89BE
	cmp r0, #3
	beq _080D89BE
	b _080D89C6
_080D89AA:
	movs r0, #4
	rsbs r0, r0, #0
	str r0, [r1]
	subs r0, #0xb
	b _080D89C4
_080D89B4:
	movs r0, #0x10
	rsbs r0, r0, #0
	str r0, [r1]
	adds r0, #8
	b _080D89C4
_080D89BE:
	movs r0, #4
	rsbs r0, r0, #0
	str r0, [r1]
_080D89C4:
	str r0, [r2]
_080D89C6:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d89cc
FUN_080d89cc: @ 0x080D89CC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [sp, #0x10]
	movs r5, #0
	cmp r0, #0
	beq _080D89E8
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r0, r0, r6
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r0, #0
	ble _080D89E8
	movs r5, #1
_080D89E8:
	cmp r4, #1
	beq _080D8A78
	cmp r4, #1
	bgt _080D89F6
	cmp r4, #0
	beq _080D8A00
	b _080D8A8A
_080D89F6:
	cmp r4, #2
	beq _080D8A82
	cmp r4, #3
	beq _080D8A82
	b _080D8A8A
_080D8A00:
	cmp r5, #0
	bne _080D8A3E
	cmp r3, #1
	beq _080D8A24
	cmp r3, #1
	bgt _080D8A12
	cmp r3, #0
	beq _080D8A1C
	b _080D8A8A
_080D8A12:
	cmp r3, #2
	beq _080D8A2C
	cmp r3, #3
	beq _080D8A36
	b _080D8A8A
_080D8A1C:
	movs r0, #0x40
	str r0, [r1]
	str r3, [r2]
	b _080D8A8A
_080D8A24:
	movs r0, #0xc
	str r0, [r1]
	movs r0, #0x20
	b _080D8A88
_080D8A2C:
	movs r0, #0x1c
	rsbs r0, r0, #0
	str r0, [r1]
	str r5, [r2]
	b _080D8A8A
_080D8A36:
	movs r0, #0x1c
	str r0, [r1]
	subs r0, #0x3c
	b _080D8A88
_080D8A3E:
	cmp r3, #1
	beq _080D8A5E
	cmp r3, #1
	bgt _080D8A4C
	cmp r3, #0
	beq _080D8A56
	b _080D8A8A
_080D8A4C:
	cmp r3, #2
	beq _080D8A66
	cmp r3, #3
	beq _080D8A70
	b _080D8A8A
_080D8A56:
	movs r0, #0xc0
	str r0, [r1]
	movs r0, #0xa
	b _080D8A88
_080D8A5E:
	movs r0, #0x1e
	str r0, [r1]
	movs r0, #0xc0
	b _080D8A88
_080D8A66:
	movs r0, #0x1a
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #0x2a
	b _080D8A88
_080D8A70:
	movs r0, #0x40
	str r0, [r1]
	subs r0, #0x70
	b _080D8A88
_080D8A78:
	movs r0, #0x10
	rsbs r0, r0, #0
	str r0, [r1]
	adds r0, #8
	b _080D8A88
_080D8A82:
	movs r0, #4
	rsbs r0, r0, #0
	str r0, [r1]
_080D8A88:
	str r0, [r2]
_080D8A8A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d8a90
FUN_080d8a90: @ 0x080D8A90
	push {lr}
	cmp r0, #1
	beq _080D8AE6
	cmp r0, #1
	bgt _080D8AA0
	cmp r0, #0
	beq _080D8AAA
	b _080D8B54
_080D8AA0:
	cmp r0, #2
	beq _080D8B00
	cmp r0, #3
	beq _080D8B18
	b _080D8B54
_080D8AAA:
	cmp r3, #1
	beq _080D8ACA
	cmp r3, #1
	bgt _080D8AB8
	cmp r3, #0
	beq _080D8AC2
	b _080D8B54
_080D8AB8:
	cmp r3, #2
	beq _080D8AD4
	cmp r3, #3
	beq _080D8ADE
	b _080D8B54
_080D8AC2:
	movs r0, #0x40
	str r0, [r1]
	subs r0, #0x6a
	b _080D8B52
_080D8ACA:
	movs r0, #0x24
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #0x18
	b _080D8B52
_080D8AD4:
	movs r0, #0x56
	rsbs r0, r0, #0
	str r0, [r1]
	adds r0, #0x4a
	b _080D8B52
_080D8ADE:
	movs r0, #0x20
	str r0, [r1]
	subs r0, #0x80
	b _080D8B52
_080D8AE6:
	cmp r3, #0
	beq _080D8AEE
	cmp r3, #3
	bne _080D8AF6
_080D8AEE:
	movs r0, #0xc
	str r0, [r1]
	subs r0, #0x2c
	b _080D8B52
_080D8AF6:
	movs r0, #0x40
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #0
	b _080D8B52
_080D8B00:
	cmp r3, #0
	beq _080D8B08
	cmp r3, #3
	bne _080D8B0C
_080D8B08:
	movs r0, #0
	b _080D8B10
_080D8B0C:
	movs r0, #8
	rsbs r0, r0, #0
_080D8B10:
	str r0, [r1]
	movs r0, #4
	rsbs r0, r0, #0
	b _080D8B52
_080D8B18:
	cmp r3, #1
	beq _080D8B38
	cmp r3, #1
	bgt _080D8B26
	cmp r3, #0
	beq _080D8B30
	b _080D8B54
_080D8B26:
	cmp r3, #2
	beq _080D8B42
	cmp r3, #3
	beq _080D8B4C
	b _080D8B54
_080D8B30:
	movs r0, #0xa
	str r0, [r1]
	str r3, [r2]
	b _080D8B54
_080D8B38:
	movs r0, #0xe
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #2
	b _080D8B52
_080D8B42:
	movs r0, #0x10
	rsbs r0, r0, #0
	str r0, [r1]
	adds r0, #0xe
	b _080D8B52
_080D8B4C:
	movs r0, #8
	str r0, [r1]
	subs r0, #0xc
_080D8B52:
	str r0, [r2]
_080D8B54:
	pop {r0}
	bx r0

	thumb_func_start FUN_080d8b58
FUN_080d8b58: @ 0x080D8B58
	push {lr}
	cmp r0, #1
	beq _080D8BAC
	cmp r0, #1
	bgt _080D8B68
	cmp r0, #0
	beq _080D8B72
	b _080D8C1A
_080D8B68:
	cmp r0, #2
	beq _080D8BC6
	cmp r0, #3
	beq _080D8BDE
	b _080D8C1A
_080D8B72:
	cmp r3, #1
	beq _080D8B92
	cmp r3, #1
	bgt _080D8B80
	cmp r3, #0
	beq _080D8B8A
	b _080D8C1A
_080D8B80:
	cmp r3, #2
	beq _080D8B9A
	cmp r3, #3
	beq _080D8BA4
	b _080D8C1A
_080D8B8A:
	movs r0, #0xdc
	str r0, [r1]
	movs r0, #0x20
	b _080D8C18
_080D8B92:
	movs r0, #0x40
	str r0, [r1]
	movs r0, #0xd2
	b _080D8C18
_080D8B9A:
	movs r0, #0x20
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #0x4e
	b _080D8C18
_080D8BA4:
	movs r0, #0x40
	str r0, [r1]
	subs r0, #0x60
	b _080D8C18
_080D8BAC:
	cmp r3, #0
	beq _080D8BB4
	cmp r3, #3
	bne _080D8BBC
_080D8BB4:
	movs r0, #0xc
	str r0, [r1]
	subs r0, #0x2c
	b _080D8C18
_080D8BBC:
	movs r0, #0x20
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #0
	b _080D8C18
_080D8BC6:
	cmp r3, #0
	beq _080D8BCE
	cmp r3, #3
	bne _080D8BD2
_080D8BCE:
	movs r0, #0
	b _080D8BD6
_080D8BD2:
	movs r0, #8
	rsbs r0, r0, #0
_080D8BD6:
	str r0, [r1]
	movs r0, #4
	rsbs r0, r0, #0
	b _080D8C18
_080D8BDE:
	cmp r3, #1
	beq _080D8BFE
	cmp r3, #1
	bgt _080D8BEC
	cmp r3, #0
	beq _080D8BF6
	b _080D8C1A
_080D8BEC:
	cmp r3, #2
	beq _080D8C08
	cmp r3, #3
	beq _080D8C12
	b _080D8C1A
_080D8BF6:
	movs r0, #2
	str r0, [r1]
	movs r0, #0xa
	b _080D8C18
_080D8BFE:
	movs r0, #8
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #0xe
	b _080D8C18
_080D8C08:
	movs r0, #0xa
	rsbs r0, r0, #0
	str r0, [r1]
	movs r0, #8
	b _080D8C18
_080D8C12:
	movs r0, #6
	str r0, [r1]
	movs r0, #5
_080D8C18:
	str r0, [r2]
_080D8C1A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d8c20
FUN_080d8c20: @ 0x080D8C20
	push {lr}
	cmp r0, #0
	blt _080D8C6C
	cmp r0, #2
	ble _080D8C6C
	cmp r0, #3
	bne _080D8C6C
	cmp r3, #1
	beq _080D8C50
	cmp r3, #1
	bgt _080D8C3C
	cmp r3, #0
	beq _080D8C46
	b _080D8C6C
_080D8C3C:
	cmp r3, #2
	beq _080D8C5A
	cmp r3, #3
	beq _080D8C62
	b _080D8C6C
_080D8C46:
	movs r0, #2
	rsbs r0, r0, #0
	str r0, [r1]
	subs r0, #6
	b _080D8C6A
_080D8C50:
	movs r0, #7
	rsbs r0, r0, #0
	str r0, [r1]
	subs r0, #3
	b _080D8C6A
_080D8C5A:
	movs r0, #7
	rsbs r0, r0, #0
	str r0, [r1]
	b _080D8C6A
_080D8C62:
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1]
	subs r0, #7
_080D8C6A:
	str r0, [r2]
_080D8C6C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080d8c70
FUN_080d8c70: @ 0x080D8C70
	push {lr}
	adds r3, r1, #0
	cmp r0, #5
	bhi _080D8CBC
	lsls r0, r0, #2
	ldr r1, _080D8C84 @ =_080D8C88
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D8C84: .4byte _080D8C88
_080D8C88: @ jump table
	.4byte _080D8CA0 @ case 0
	.4byte _080D8CAA @ case 1
	.4byte _080D8CB4 @ case 2
	.4byte _080D8CB4 @ case 3
	.4byte _080D8CAA @ case 4
	.4byte _080D8CAA @ case 5
_080D8CA0:
	movs r0, #4
	rsbs r0, r0, #0
	str r0, [r3]
	subs r0, #0xb
	b _080D8CBA
_080D8CAA:
	movs r0, #0x10
	rsbs r0, r0, #0
	str r0, [r3]
	adds r0, #8
	b _080D8CBA
_080D8CB4:
	movs r0, #4
	rsbs r0, r0, #0
	str r0, [r3]
_080D8CBA:
	str r0, [r2]
_080D8CBC:
	pop {r0}
	bx r0

	thumb_func_start FUN_080d8cc0
FUN_080d8cc0: @ 0x080D8CC0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r2, #0
	ldr r6, [sp, #0x14]
	adds r0, r5, #0
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r5, r0, #6
	subs r0, r1, #1
	cmp r0, #0x1d
	bhi _080D8DC6
	lsls r0, r0, #2
	ldr r1, _080D8CE4 @ =_080D8CE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D8CE4: .4byte _080D8CE8
_080D8CE8: @ jump table
	.4byte _080D8D6E @ case 0
	.4byte _080D8DC6 @ case 1
	.4byte _080D8D7C @ case 2
	.4byte _080D8D60 @ case 3
	.4byte _080D8D9C @ case 4
	.4byte _080D8D9C @ case 5
	.4byte _080D8D9C @ case 6
	.4byte _080D8DC6 @ case 7
	.4byte _080D8DC6 @ case 8
	.4byte _080D8D8A @ case 9
	.4byte _080D8DC6 @ case 10
	.4byte _080D8DC6 @ case 11
	.4byte _080D8DC6 @ case 12
	.4byte _080D8DC6 @ case 13
	.4byte _080D8DC6 @ case 14
	.4byte _080D8DC6 @ case 15
	.4byte _080D8DC6 @ case 16
	.4byte _080D8DC6 @ case 17
	.4byte _080D8DC6 @ case 18
	.4byte _080D8DC6 @ case 19
	.4byte _080D8DAA @ case 20
	.4byte _080D8DC6 @ case 21
	.4byte _080D8DC6 @ case 22
	.4byte _080D8DC6 @ case 23
	.4byte _080D8DC6 @ case 24
	.4byte _080D8DC6 @ case 25
	.4byte _080D8DB8 @ case 26
	.4byte _080D8D60 @ case 27
	.4byte _080D8DC6 @ case 28
	.4byte _080D8D7C @ case 29
_080D8D60:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d88ec
	b _080D8DD2
_080D8D6E:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d8954
	b _080D8DD2
_080D8D7C:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d8990
	b _080D8DD2
_080D8D8A:
	ldr r0, [sp, #0x18]
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d89cc
	b _080D8DD2
_080D8D9C:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d8a90
	b _080D8DD2
_080D8DAA:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d8b58
	b _080D8DD2
_080D8DB8:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d8c20
	b _080D8DD2
_080D8DC6:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_080d8c70
_080D8DD2:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d8ddc
FUN_080d8ddc: @ 0x080D8DDC
	bx lr
	.align 2, 0

	thumb_func_start FUN_080d8de0
FUN_080d8de0: @ 0x080D8DE0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	adds r5, r1, #0
	ldr r0, _080D8E88 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	beq _080D8E78
	ldr r2, [r7, #0x48]
	lsls r1, r5, #1
	adds r0, r7, #0
	adds r0, #0x3e
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bgt _080D8E78
	adds r0, r7, #0
	adds r0, #0x32
	adds r6, r0, r5
	ldrb r0, [r6]
	cmp r0, #1
	beq _080D8E78
	ldr r3, _080D8E8C @ =0x0203B400
	mov ip, r3
	ldr r0, _080D8E90 @ =0x030046B8
	mov sb, r0
	ldr r1, [r0]
	adds r1, #1
	ldr r4, _080D8E94 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	add r0, ip
	ldrh r0, [r0]
	lsls r2, r5, #3
	adds r2, r7, r2
	movs r3, #0xf
	ands r0, r3
	subs r0, #8
	mov sl, r0
	movs r0, #0
	mov r8, r0
	mov r0, sl
	strh r0, [r2, #4]
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	add r0, ip
	ldrh r0, [r0]
	ands r0, r3
	strh r0, [r2, #6]
	adds r1, #1
	ands r1, r4
	mov r0, sb
	str r1, [r0]
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	ands r0, r3
	subs r0, #8
	strh r0, [r2, #8]
	ldrb r1, [r6]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6]
	lsls r1, r5, #2
	adds r0, r7, #0
	adds r0, #0x4c
	adds r0, r0, r1
	mov r1, r8
	str r1, [r0]
_080D8E78:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D8E88: .4byte 0x0300015C
_080D8E8C: .4byte 0x0203B400
_080D8E90: .4byte 0x030046B8
_080D8E94: .4byte 0x000003FF

	thumb_func_start FUN_080d8e98
FUN_080d8e98: @ 0x080D8E98
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldr r0, _080D8EF4 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080D8EB0
	b _080D928C
_080D8EB0:
	str r0, [sp]
	adds r0, r7, #0
	adds r0, #0x88
	str r0, [sp, #4]
	movs r1, #0
	str r1, [sp, #0x10]
	mov sb, r1
	adds r2, r7, #0
	adds r2, #0x38
	str r2, [sp, #0x14]
	movs r3, #0
	str r3, [sp, #0x1c]
	movs r4, #0x80
	lsls r4, r4, #1
	adds r4, r4, r7
	mov r8, r4
	adds r5, r7, #4
	mov sl, r5
	adds r6, r0, #0
_080D8ED6:
	ldr r1, [sp, #0x14]
	ldrb r0, [r1]
	mov r2, sb
	asrs r0, r2
	movs r3, #1
	ands r0, r3
	cmp r0, #0
	bne _080D8EF8
	ldr r0, [r6]
	orrs r0, r3
	str r0, [r6]
	ldr r4, [sp, #0x10]
	adds r4, #1
	str r4, [sp, #0x10]
	b _080D9208
	.align 2, 0
_080D8EF4: .4byte 0x0300015C
_080D8EF8:
	adds r0, r7, #0
	adds r0, #0x32
	add r0, sb
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D8F0A
	b _080D9070
_080D8F0A:
	adds r0, r7, #0
	adds r0, #0x4c
	ldr r5, [sp, #0x1c]
	adds r1, r0, r5
	ldr r1, [r1]
	str r0, [sp, #0x18]
	cmp r1, #0xe
	ble _080D8F2A
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	ldr r2, [sp, #0x10]
	adds r2, #1
	str r2, [sp, #0x10]
	b _080D9208
_080D8F2A:
	adds r0, r7, #0
	adds r0, #0x3a
	ldrb r0, [r0]
	cmp r0, #2
	beq _080D8F3E
	cmp r0, #3
	beq _080D8F46
	movs r3, #0
	mov ip, r3
	b _080D8F4C
_080D8F3E:
	ldr r4, [sp]
	ldr r4, [r4, #0x58]
	mov ip, r4
	b _080D8F4C
_080D8F46:
	ldr r5, [sp]
	ldr r5, [r5, #0x58]
	mov ip, r5
_080D8F4C:
	adds r5, r6, #0
	mov r3, r8
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r2, [r4]
	lsrs r2, r2, #6
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	mov r1, ip
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r6, #8]
	ldrb r0, [r3, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r4]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r2, r0
	beq _080D8F8E
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _080D8F96
_080D8F8E:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D8F96:
	str r0, [r6]
	ldrb r0, [r3, #4]
	movs r1, #2
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	movs r2, #2
	ands r0, r2
	cmp r1, r0
	beq _080D8FBA
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D8FC2
_080D8FBA:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D8FC2:
	str r0, [r5]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r4, _080D8FF8 @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r3, #7]
	cmp r0, r5
	blo _080D9022
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D8FFC
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _080D8FF2
	ldrb r0, [r3, #5]
_080D8FF2:
	subs r0, #1
	strh r0, [r3, #8]
	b _080D900C
	.align 2, 0
_080D8FF8: .4byte 0x0000FFFF
_080D8FFC:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _080D900C
	strh r1, [r3, #8]
_080D900C:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
_080D9022:
	ldrh r1, [r7, #0x1c]
	mov r3, sl
	ldrh r3, [r3]
	adds r1, r1, r3
	ldrh r0, [r6, #0x18]
	adds r0, r0, r1
	strh r0, [r6, #0x18]
	ldrh r1, [r7, #0x1e]
	mov r4, sl
	ldrh r4, [r4, #2]
	adds r1, r1, r4
	ldrh r0, [r6, #0x1a]
	adds r0, r0, r1
	strh r0, [r6, #0x1a]
	ldrh r1, [r7, #0x20]
	mov r5, sl
	ldrh r5, [r5, #4]
	adds r1, r1, r5
	ldrh r0, [r6, #0x1c]
	adds r0, r0, r1
	strh r0, [r6, #0x1c]
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	adds r2, r0, r1
	ldr r1, [r2]
	asrs r1, r1, #1
	mov r3, sl
	ldrh r0, [r3, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldr r0, [r2]
	adds r0, #1
	str r0, [r2]
	b _080D9208
_080D9070:
	adds r0, r7, #0
	adds r0, #0x4c
	ldr r4, [sp, #0x1c]
	adds r1, r0, r4
	ldr r0, [r1]
	cmp r0, #0
	ble _080D9084
	subs r0, #1
	str r0, [r1]
	b _080D9208
_080D9084:
	adds r0, r7, #0
	adds r0, #0x3a
	ldrb r0, [r0]
	cmp r0, #2
	beq _080D9098
	cmp r0, #3
	beq _080D90A0
	movs r5, #0
	mov ip, r5
	b _080D90A6
_080D9098:
	ldr r0, [sp]
	ldr r0, [r0, #0x58]
	mov ip, r0
	b _080D90A6
_080D90A0:
	ldr r1, [sp]
	ldr r1, [r1, #0x58]
	mov ip, r1
_080D90A6:
	adds r5, r6, #0
	mov r3, r8
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r2, [r4]
	lsrs r2, r2, #6
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	mov r2, ip
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r6, #8]
	ldrb r0, [r3, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r4]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r2, r0
	beq _080D90E8
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _080D90F0
_080D90E8:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D90F0:
	str r0, [r6]
	ldrb r0, [r3, #4]
	movs r1, #2
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	movs r2, #2
	ands r0, r2
	cmp r1, r0
	beq _080D9114
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D911C
_080D9114:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D911C:
	str r0, [r5]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r4, _080D9154 @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r3, #7]
	cmp r0, r5
	blo _080D917E
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D9158
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _080D914C
	ldrb r0, [r3, #5]
_080D914C:
	subs r0, #1
	strh r0, [r3, #8]
	b _080D9168
	.align 2, 0
_080D9154: .4byte 0x0000FFFF
_080D9158:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _080D9168
	strh r1, [r3, #8]
_080D9168:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
_080D917E:
	ldr r5, _080D929C @ =0x085B0A08
	adds r4, r7, #0
	adds r4, #0x35
	add r4, sb
	ldrb r3, [r4]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #7
	lsrs r0, r0, #0x10
	ldr r2, _080D92A0 @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #8]
	lsls r0, r3, #1
	adds r0, r0, r5
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r0, #0x46
	muls r0, r1, r0
	lsls r0, r0, #4
	lsrs r0, r0, #0x10
	lsls r0, r0, #0x10
	ldr r1, _080D92A4 @ =0x0000FFFF
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	adds r3, #5
	strb r3, [r4]
	ldr r0, [r7]
	mov r2, sp
	ldrh r3, [r2, #8]
	ldrh r0, [r0]
	adds r2, r3, r0
	ldrh r0, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r6, #0x18]
	ldr r0, [r7]
	asrs r1, r1, #0x10
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	ldrh r0, [r7, #0x28]
	adds r0, r0, r1
	ldrh r4, [r7, #0x1e]
	adds r0, r0, r4
	strh r0, [r6, #0x1a]
	ldr r0, [r7]
	ldrh r0, [r0, #4]
	subs r0, r0, r3
	ldrh r5, [r7, #0x20]
	adds r0, r0, r5
	strh r0, [r6, #0x1c]
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r0, r7, #0
	mov r1, sb
	bl FUN_080d8de0
_080D9208:
	ldr r0, [sp, #0x1c]
	adds r0, #4
	str r0, [sp, #0x1c]
	movs r1, #0x10
	add r8, r1
	movs r2, #8
	add sl, r2
	adds r6, #0x28
	movs r3, #1
	add sb, r3
	mov r4, sb
	cmp r4, #2
	bgt _080D9224
	b _080D8ED6
_080D9224:
	ldr r5, [sp, #0x10]
	cmp r5, #2
	ble _080D928C
	adds r0, r7, #0
	adds r0, #0x2d
	movs r2, #0
	strb r2, [r0]
	adds r4, r7, #0
	adds r4, #0x39
	movs r0, #0
	ldrsb r0, [r4, r0]
	ldr r1, [sp]
	ldr r5, _080D92A8 @ =0x000009FC
	adds r3, r1, r5
	movs r1, #1
	lsls r1, r0
	ldr r0, [r3]
	bics r0, r1
	str r0, [r3]
	strh r2, [r7, #0x24]
	str r2, [r7, #0x48]
	mov sb, r2
	adds r5, r4, #0
	ldr r4, [sp, #4]
_080D9254:
	ldr r1, [sp, #0x14]
	ldrb r0, [r1]
	mov r2, sb
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D9270
	adds r0, r7, #0
	bl FUN_080d8644
	adds r0, r4, #0
	bl FUN_0822dabc
_080D9270:
	adds r4, #0x28
	movs r3, #1
	add sb, r3
	mov r0, sb
	cmp r0, #2
	ble _080D9254
	movs r4, #0
	adds r0, r7, #0
	bl FUN_080d866c
	ldr r1, [sp, #0x14]
	strb r4, [r1]
	movs r0, #0xff
	strb r0, [r5]
_080D928C:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D929C: .4byte 0x085B0A08
_080D92A0: .4byte 0xFFFF0000
_080D92A4: .4byte 0x0000FFFF
_080D92A8: .4byte 0x000009FC

	thumb_func_start FUN_080d92ac
FUN_080d92ac: @ 0x080D92AC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, _080D92DC @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080D92BE
	b _080D94AA
_080D92BE:
	mov ip, r0
	adds r7, r6, #0
	adds r7, #0x88
	movs r0, #0x80
	lsls r0, r0, #1
	adds r4, r6, r0
	adds r0, r6, #0
	adds r0, #0x3a
	ldrb r0, [r0]
	cmp r0, #2
	beq _080D92E0
	cmp r0, #3
	beq _080D92E6
	movs r3, #0
	b _080D92EA
	.align 2, 0
_080D92DC: .4byte 0x0300015C
_080D92E0:
	mov r1, ip
	ldr r3, [r1, #0x58]
	b _080D92EA
_080D92E6:
	mov r2, ip
	ldr r3, [r2, #0x58]
_080D92EA:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r2, [r5]
	lsrs r2, r2, #6
	ldrb r1, [r7, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r7, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r7, #8]
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
	beq _080D9326
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080D932E
_080D9326:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D932E:
	str r0, [r7]
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
	beq _080D9352
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080D935A
_080D9352:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D935A:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D9390 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D93BA
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D9394
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D938A
	ldrb r0, [r4, #5]
_080D938A:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D93A4
	.align 2, 0
_080D9390: .4byte 0x0000FFFF
_080D9394:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D93A4
	strh r1, [r4, #8]
_080D93A4:
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
_080D93BA:
	ldr r1, [r6, #0x4c]
	asrs r1, r1, #1
	ldr r2, _080D9434 @ =0x085B0A08
	adds r3, r6, #0
	adds r3, #0x35
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	strh r0, [r6, #4]
	ldrh r0, [r6, #6]
	adds r0, #2
	strh r0, [r6, #6]
	ldr r2, _080D9438 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080D943C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080D9440 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #4
	movs r1, #7
	ands r0, r1
	ldrb r2, [r3]
	adds r0, r0, r2
	strb r0, [r3]
	ldr r1, [r6]
	ldrh r0, [r6, #4]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r7, #0x18]
	ldr r0, [r6]
	ldrh r1, [r6, #6]
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	ldrh r0, [r6, #0x28]
	adds r0, r0, r1
	strh r0, [r7, #0x1a]
	ldr r0, [r6]
	ldrh r0, [r0, #4]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r7, #0x1c]
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	movs r1, #6
	ldrsh r0, [r6, r1]
	cmp r0, #0x3c
	bgt _080D9444
	movs r0, #0
	b _080D944E
	.align 2, 0
_080D9434: .4byte 0x085B0A08
_080D9438: .4byte 0x030046B8
_080D943C: .4byte 0x000003FF
_080D9440: .4byte 0x0203B400
_080D9444:
	cmp r0, #0x78
	bgt _080D944C
	movs r0, #1
	b _080D944E
_080D944C:
	movs r0, #2
_080D944E:
	strh r0, [r4, #8]
	movs r2, #6
	ldrsh r0, [r6, r2]
	cmp r0, #0xd2
	ble _080D94A4
	adds r0, r6, #0
	adds r0, #0x2d
	movs r5, #0
	strb r5, [r0]
	movs r0, #0x39
	adds r0, r0, r6
	mov r8, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r2, _080D94A0 @ =0x000009FC
	add r2, ip
	movs r3, #1
	adds r1, r3, #0
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	ldr r0, [r7]
	orrs r0, r3
	str r0, [r7]
	adds r0, r6, #0
	bl FUN_080d8644
	movs r4, #0
	strh r5, [r6, #0x24]
	adds r0, r7, #0
	bl FUN_0822dabc
	adds r0, r6, #0
	adds r0, #0x38
	strb r4, [r0]
	movs r0, #0xff
	mov r1, r8
	strb r0, [r1]
	b _080D94AA
	.align 2, 0
_080D94A0: .4byte 0x000009FC
_080D94A4:
	ldr r0, [r6, #0x4c]
	adds r0, #1
	str r0, [r6, #0x4c]
_080D94AA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d94b4
FUN_080d94b4: @ 0x080D94B4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, _080D9500 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080D94C6
	b _080D96AE
_080D94C6:
	mov r8, r0
	adds r7, r5, #0
	adds r7, #0x5c
	movs r0, #0x80
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _080D9504
	ldr r0, [r5, #0x5c]
	movs r1, #4
	orrs r0, r1
	b _080D950C
	.align 2, 0
_080D9500: .4byte 0x0300015C
_080D9504:
	ldr r0, [r5, #0x5c]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D950C:
	str r0, [r5, #0x5c]
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
	beq _080D9530
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080D9538
_080D9530:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D9538:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D9570 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _080D95B6
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D957A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D9574
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080D9590
	.align 2, 0
_080D9570: .4byte 0x0000FFFF
_080D9574:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D958E
_080D957A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r6, [r4, #5]
	cmp r0, r6
	blo _080D958E
	strh r1, [r4, #8]
	movs r2, #1
	b _080D9590
_080D958E:
	movs r2, #0
_080D9590:
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
	bne _080D95B8
	movs r0, #1
	strb r0, [r4, #7]
	b _080D95B8
_080D95B6:
	movs r2, #0
_080D95B8:
	mov ip, r2
	adds r0, r5, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	cmp r0, #1
	bhi _080D95D4
	ldrh r0, [r5, #0x30]
	adds r0, #0x19
	strh r0, [r5, #0x30]
	ldr r2, [r5]
	ldrh r1, [r5, #0x28]
	ldrh r3, [r2, #2]
	adds r1, r1, r3
	b _080D95E2
_080D95D4:
	ldrh r0, [r5, #0x30]
	adds r0, #0xa
	strh r0, [r5, #0x30]
	ldr r2, [r5]
	ldrh r1, [r5, #0x28]
	ldrh r6, [r2, #2]
	adds r1, r1, r6
_080D95E2:
	adds r0, r0, r1
	strh r0, [r5, #0x2a]
	ldrh r1, [r5, #0x2a]
	ldrh r3, [r5, #0x26]
	movs r6, #2
	ldrsh r0, [r2, r6]
	adds r0, r3, r0
	adds r6, r3, #0
	cmp r1, r0
	ble _080D95FC
	ldrh r0, [r2, #2]
	adds r0, r6, r0
	strh r0, [r5, #0x2a]
_080D95FC:
	ldrh r1, [r5, #0x2a]
	movs r6, #2
	ldrsh r0, [r2, r6]
	adds r0, r3, r0
	cmp r1, r0
	blt _080D9610
	movs r1, #0x3c
	ldrsh r0, [r5, r1]
	cmp r0, #0
	ble _080D9616
_080D9610:
	movs r0, #0
	strh r0, [r4, #8]
	strh r0, [r4, #0xe]
_080D9616:
	ldr r0, [r5, #0x4c]
	cmp r0, #0x1d
	bgt _080D9622
	movs r0, #0
	strh r0, [r4, #8]
	strh r0, [r4, #0xe]
_080D9622:
	mov r2, ip
	cmp r2, #0
	beq _080D9670
	adds r0, r5, #0
	adds r0, #0x2d
	movs r2, #0
	strb r2, [r0]
	adds r6, r5, #0
	adds r6, #0x39
	movs r0, #0
	ldrsb r0, [r6, r0]
	ldr r3, _080D966C @ =0x000009FC
	add r3, r8
	movs r4, #1
	adds r1, r4, #0
	lsls r1, r0
	ldr r0, [r3]
	bics r0, r1
	str r0, [r3]
	ldr r0, [r7]
	orrs r0, r4
	str r0, [r7]
	adds r0, r5, #0
	adds r0, #0x32
	strb r2, [r0]
	movs r4, #0
	strh r2, [r5, #0x24]
	str r2, [r5, #0x4c]
	adds r0, r7, #0
	bl FUN_0822a4e0
	adds r0, r5, #0
	adds r0, #0x44
	strb r4, [r0]
	movs r0, #0xff
	strb r0, [r6]
	b _080D96AE
	.align 2, 0
_080D966C: .4byte 0x000009FC
_080D9670:
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	ldr r0, [r5]
	cmp r0, #0
	beq _080D96A0
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldrh r0, [r5, #0x1c]
	ldrh r3, [r7, #0x1c]
	adds r0, r0, r3
	strh r0, [r7, #0x1c]
	ldrh r0, [r5, #0x1e]
	ldrh r6, [r5, #0x2a]
	adds r0, r0, r6
	strh r0, [r7, #0x1e]
	ldrh r0, [r5, #0x20]
	ldrh r1, [r7, #0x20]
	adds r0, r0, r1
	strh r0, [r7, #0x20]
_080D96A0:
	mov r0, r8
	adds r1, r5, #0
	bl FUN_080d8864
	ldr r0, [r5, #0x4c]
	adds r0, #1
	str r0, [r5, #0x4c]
_080D96AE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d96b8
FUN_080d96b8: @ 0x080D96B8
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	movs r1, #4
	adds r0, #0x32
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D96CC
	movs r0, #1
	b _080D96CE
_080D96CC:
	movs r0, #0
_080D96CE:
	adds r5, r0, #0
	cmp r5, #0
	bne _080D9750
	ldr r0, [r3, #0x48]
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r4, r0, #0
	cmp r1, #0
	bgt _080D96FA
	movs r0, #0x14
	strh r0, [r3, #0x3c]
	adds r2, r3, #0
	adds r2, #0x32
	ldrb r1, [r2]
	movs r0, #5
	orrs r0, r1
	strb r0, [r2]
	adds r1, r3, #0
	adds r1, #0x2c
	movs r0, #4
	strb r0, [r1]
	b _080D9750
_080D96FA:
	movs r2, #4
	movs r6, #0
	ldrsh r1, [r4, r6]
	movs r6, #0x3e
	ldrsh r0, [r3, r6]
	lsls r0, r0, #2
	movs r6, #0x32
	adds r6, r6, r3
	mov ip, r6
	adds r6, r3, #0
	adds r6, #0x2e
	cmp r1, r0
	blt _080D971C
	adds r0, r3, #0
	adds r0, #0x2c
	strb r5, [r0]
	b _080D973A
_080D971C:
	subs r2, #1
	cmp r2, #0
	ble _080D973A
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r5, #0x3e
	ldrsh r1, [r3, r5]
	muls r1, r2, r1
	cmp r0, r1
	blt _080D971C
	movs r0, #4
	subs r0, r0, r2
	adds r1, r3, #0
	adds r1, #0x2c
	strb r0, [r1]
_080D973A:
	movs r0, #0
	strh r0, [r3, #0x3c]
	subs r0, #6
	mov r2, ip
	ldrb r1, [r2]
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r6]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6]
_080D9750:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d9758
FUN_080d9758: @ 0x080D9758
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080D97A4 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	beq _080D97F4
	adds r6, r0, #0
	adds r5, r4, #0
	adds r5, #0x5c
	ldr r0, [r4, #0x5c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x5c]
	adds r0, r4, #0
	bl FUN_080d96b8
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	strh r0, [r5, #0x10]
	ldr r0, [r4]
	cmp r0, #0
	beq _080D97DC
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	ldrh r2, [r4, #0x2a]
	movs r1, #1
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D97A8
	movs r0, #1
	b _080D97AA
	.align 2, 0
_080D97A4: .4byte 0x0300015C
_080D97A8:
	movs r0, #0
_080D97AA:
	cmp r0, #0
	bne _080D97C2
	ldr r0, _080D97FC @ =0x085B0A08
	adds r1, r4, #0
	adds r1, #0x35
	ldrb r1, [r1]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	asrs r0, r0, #8
	adds r2, r2, r0
_080D97C2:
	ldrh r0, [r4, #0x1c]
	ldrh r1, [r5, #0x1c]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	ldrh r0, [r4, #0x1e]
	adds r0, r0, r2
	ldrh r3, [r5, #0x1e]
	adds r0, r0, r3
	strh r0, [r5, #0x1e]
	ldrh r0, [r4, #0x20]
	ldrh r1, [r5, #0x20]
	adds r0, r0, r1
	strh r0, [r5, #0x20]
_080D97DC:
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_080d8788
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080D97F4
	adds r1, r4, #0
	adds r1, #0x35
	ldrb r0, [r1]
	adds r0, #4
	strb r0, [r1]
_080D97F4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D97FC: .4byte 0x085B0A08

	thumb_func_start FUN_080d9800
FUN_080d9800: @ 0x080D9800
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080D984C @ =0x0300015C
	ldr r3, [r0]
	cmp r3, #0
	beq _080D98C8
	adds r5, r4, #0
	adds r5, #0x5c
	ldr r0, [r4, #0x5c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x5c]
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	strh r0, [r5, #0x10]
	ldr r0, [r4]
	cmp r0, #0
	beq _080D98C8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	ldr r0, [r4, #0x4c]
	cmp r0, #3
	bgt _080D9850
	ldrh r0, [r4, #0x30]
	adds r0, #0x14
	strh r0, [r4, #0x30]
	ldr r2, [r4]
	ldrh r1, [r4, #0x28]
	ldrh r2, [r2, #2]
	adds r1, r1, r2
	adds r0, r0, r1
	strh r0, [r4, #0x2a]
	strh r0, [r5, #0x1e]
	b _080D98A6
	.align 2, 0
_080D984C: .4byte 0x0300015C
_080D9850:
	cmp r0, #9
	bgt _080D987C
	movs r0, #1
	strh r0, [r4, #0x3c]
	ldr r0, [r4]
	ldrh r1, [r4, #0x28]
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	ldrh r0, [r4, #0x30]
	adds r0, r0, r1
	strh r0, [r5, #0x1e]
	adds r2, r4, #0
	adds r2, #0x32
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r1, r4, #0
	bl FUN_080d8864
	b _080D98A6
_080D987C:
	ldr r0, [r4]
	movs r2, #2
	ldrsh r1, [r0, r2]
	ldrh r0, [r4, #0x28]
	adds r1, r1, r0
	ldrh r0, [r4, #0x30]
	adds r1, r1, r0
	ldr r2, _080D98D0 @ =0x085B0A08
	adds r3, r4, #0
	adds r3, #0x35
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	asrs r0, r0, #8
	adds r1, r1, r0
	strh r1, [r5, #0x1e]
	ldrb r0, [r3]
	adds r0, #4
	strb r0, [r3]
_080D98A6:
	ldrh r0, [r4, #0x1c]
	ldrh r1, [r5, #0x1c]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	ldrh r0, [r4, #0x1e]
	ldrh r2, [r5, #0x1e]
	adds r0, r0, r2
	strh r0, [r5, #0x1e]
	ldrh r0, [r4, #0x20]
	ldrh r1, [r5, #0x20]
	adds r0, r0, r1
	strh r0, [r5, #0x20]
	ldr r0, [r4, #0x4c]
	cmp r0, #9
	bgt _080D98C8
	adds r0, #1
	str r0, [r4, #0x4c]
_080D98C8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D98D0: .4byte 0x085B0A08

	thumb_func_start FUN_080d98d4
FUN_080d98d4: @ 0x080D98D4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080D9952
	adds r1, r6, #0
	adds r1, #0x2f
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _080D98FA
	ldr r0, [r2, #0x30]
	ldr r1, [r2, #0x34]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	b _080D9952
_080D98FA:
	adds r4, r6, #0
	adds r4, #0x3b
	ldrb r0, [r4]
	ldrb r1, [r1]
	ldrb r2, [r2, #5]
	add r3, sp, #0xc
	str r3, [sp]
	ldr r3, [r6, #0x58]
	str r3, [sp, #4]
	add r3, sp, #8
	bl FUN_080d8cc0
	ldrb r0, [r4]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080D9946
	movs r5, #0
	adds r7, r6, #0
	adds r7, #0x38
	adds r4, #0x4d
_080D9926:
	ldrb r0, [r7]
	asrs r0, r5
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D993C
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	adds r0, r4, #0
	bl FUN_0822dad4
_080D993C:
	adds r4, #0x28
	adds r5, #1
	cmp r5, #2
	ble _080D9926
	b _080D9952
_080D9946:
	ldr r0, [sp, #8]
	movs r1, #0
	strh r0, [r6, #0x1c]
	strh r1, [r6, #0x1e]
	ldr r0, [sp, #0xc]
	strh r0, [r6, #0x20]
_080D9952:
	ldr r0, _080D9970 @ =0x085AD2EC
	adds r1, r6, #0
	adds r1, #0x3b
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r6, #0
	bl _call_via_r1
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D9970: .4byte 0x085AD2EC

	thumb_func_start FUN_080d9974
FUN_080d9974: @ 0x080D9974
	push {r4, r5, lr}
	adds r2, r0, #0
	movs r3, #0
	ldr r0, _080D9990 @ =0x000009FC
	adds r4, r2, r0
	movs r5, #1
_080D9980:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080D9994
	movs r0, #1
	b _080D9996
	.align 2, 0
_080D9990: .4byte 0x000009FC
_080D9994:
	movs r0, #0
_080D9996:
	cmp r0, #0
	bne _080D99B6
	movs r0, #0x9a
	lsls r0, r0, #1
	muls r0, r3, r0
	adds r0, #0x5c
	adds r0, r2, r0
	adds r2, r5, #0
	lsls r2, r3
	ldr r1, [r4]
	orrs r1, r2
	str r1, [r4]
	adds r1, r0, #0
	adds r1, #0x39
	strb r3, [r1]
	b _080D99BE
_080D99B6:
	adds r3, #1
	cmp r3, #7
	ble _080D9980
	movs r0, #0
_080D99BE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080d99c4
FUN_080d99c4: @ 0x080D99C4
	push {lr}
	bl FUN_080d9974
	cmp r0, #0
	bne _080D99D0
	movs r0, #0
_080D99D0:
	pop {r1}
	bx r1

	thumb_func_start FUN_080d99d4
FUN_080d99d4: @ 0x080D99D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r4, r1, #0
	adds r3, r2, #0
	cmp r7, #0
	beq _080D9A8A
	ldr r0, _080D9A4C @ =0x0300015C
	ldr r2, [r0]
	cmp r2, #0
	beq _080D9A8A
	adds r0, r7, #0
	adds r0, #0x39
	movs r1, #0
	ldrsb r1, [r0, r1]
	mov r8, r0
	cmp r1, #0
	blt _080D9A8A
	ldrh r0, [r7, #0x24]
	cmp r0, r3
	bne _080D9A8A
	movs r0, #0x88
	adds r0, r0, r7
	mov ip, r0
	adds r5, r7, #0
	adds r5, #0x5c
	adds r3, r7, #0
	adds r3, #0x3b
	ldrb r0, [r3]
	cmp r0, r4
	bne _080D9A8E
	mov r1, r8
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldr r1, _080D9A50 @ =0x000009FC
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	ldrb r0, [r3]
	cmp r0, #1
	bls _080D9A36
	cmp r0, #4
	beq _080D9A36
	cmp r0, #5
	bne _080D9A54
_080D9A36:
	adds r4, r7, #0
	adds r4, #0x44
	ldrb r0, [r4]
	cmp r0, #0
	beq _080D9A7A
	adds r0, r5, #0
	bl FUN_0822a4e0
	movs r0, #0
	strb r0, [r4]
	b _080D9A7A
	.align 2, 0
_080D9A4C: .4byte 0x0300015C
_080D9A50: .4byte 0x000009FC
_080D9A54:
	movs r5, #0
	adds r6, r7, #0
	adds r6, #0x38
	mov r4, ip
_080D9A5C:
	ldrb r0, [r6]
	asrs r0, r5
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D9A6E
	adds r0, r4, #0
	bl FUN_0822dabc
_080D9A6E:
	adds r4, #0x28
	adds r5, #1
	cmp r5, #2
	ble _080D9A5C
	movs r0, #0
	strb r0, [r6]
_080D9A7A:
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r7, #0
	bl ClearMemory
	movs r0, #0xff
	mov r1, r8
	strb r0, [r1]
_080D9A8A:
	movs r0, #0
	b _080D9A90
_080D9A8E:
	adds r0, r7, #0
_080D9A90:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d9a9c
FUN_080d9a9c: @ 0x080D9A9C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r3, r2, #0
	cmp r6, #0
	beq _080D9B22
	ldr r0, _080D9B28 @ =0x0300015C
	ldr r2, [r0]
	cmp r2, #0
	beq _080D9B22
	movs r0, #0x88
	adds r0, r0, r6
	mov ip, r0
	adds r0, r6, #0
	adds r0, #0x39
	movs r1, #0
	ldrsb r1, [r0, r1]
	mov r8, r0
	cmp r1, #0
	blt _080D9B22
	ldrh r0, [r6, #0x24]
	cmp r0, r3
	bne _080D9B22
	adds r0, r6, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	cmp r0, r4
	bne _080D9B30
	mov r1, r8
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldr r1, _080D9B2C @ =0x000009FC
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	movs r5, #0
	adds r7, r6, #0
	adds r7, #0x38
	mov r4, ip
_080D9AF4:
	ldrb r0, [r7]
	asrs r0, r5
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D9B06
	adds r0, r4, #0
	bl FUN_0822dabc
_080D9B06:
	adds r4, #0x28
	adds r5, #1
	cmp r5, #2
	ble _080D9AF4
	movs r0, #0
	strb r0, [r7]
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r6, #0
	bl ClearMemory
	movs r0, #0xff
	mov r1, r8
	strb r0, [r1]
_080D9B22:
	movs r0, #0
	b _080D9B32
	.align 2, 0
_080D9B28: .4byte 0x0300015C
_080D9B2C: .4byte 0x000009FC
_080D9B30:
	adds r0, r6, #0
_080D9B32:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080d9b3c
FUN_080d9b3c: @ 0x080D9B3C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	str r1, [sp, #0x10]
	mov sl, r2
	str r3, [sp, #0x14]
	ldr r5, [sp, #0x4c]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _080D9B6C @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080D9B70
	bl FUN_080da848
	mov sb, r0
	cmp r0, #0
	bne _080D9B72
_080D9B66:
	movs r0, #0
	b _080D9CDA
	.align 2, 0
_080D9B6C: .4byte 0x0300015C
_080D9B70:
	mov sb, r0
_080D9B72:
	cmp r5, #0
	beq _080D9B66
	mov r0, sb
	bl FUN_080d99c4
	adds r7, r0, #0
	cmp r7, #0
	beq _080D9B66
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r7, r1
	str r5, [r0]
	movs r2, #0x2c
	adds r2, r2, r7
	mov r8, r2
	movs r2, #0
	mov r3, r8
	strb r4, [r3]
	adds r0, r7, #0
	adds r0, #0x2d
	movs r1, #1
	strb r1, [r0]
	adds r3, r7, #0
	adds r3, #0x3a
	strb r2, [r3]
	adds r6, r7, #0
	adds r6, #0x2f
	ldr r0, [sp, #0x44]
	strb r0, [r6]
	movs r4, #0
	strh r2, [r7, #0x30]
	mov r5, sl
	strh r5, [r7, #0x24]
	mov r0, sp
	ldrh r0, [r0, #0x14]
	strh r0, [r7, #0x26]
	ldr r0, [sp, #0x40]
	strh r0, [r7, #0x28]
	adds r0, r7, #0
	adds r0, #0x32
	strb r1, [r0]
	movs r0, #0xa
	strh r0, [r7, #0x3c]
	adds r5, r7, #0
	adds r5, #0x3b
	strb r4, [r5]
	adds r4, r7, #0
	adds r4, #0x44
	strb r1, [r4]
	ldr r1, [sp, #0x10]
	str r1, [r7]
	ldr r0, [sp, #0x48]
	str r0, [r7, #0x58]
	str r2, [sp, #0xc]
	str r2, [sp, #8]
	movs r2, #0x5c
	adds r2, r2, r7
	mov sl, r2
	ldrb r0, [r3]
	mov r1, r8
	str r1, [sp, #0x18]
	mov r8, r3
	str r4, [sp, #0x1c]
	mov r4, sl
	cmp r0, #1
	beq _080D9C10
	cmp r0, #1
	bgt _080D9C00
	cmp r0, #0
	beq _080D9C0A
	b _080D9C16
_080D9C00:
	cmp r0, #5
	bgt _080D9C16
	cmp r0, #4
	blt _080D9C16
	b _080D9C10
_080D9C0A:
	mov r1, sb
	adds r1, #0x18
	b _080D9C18
_080D9C10:
	mov r1, sb
	adds r1, #0x34
	b _080D9C18
_080D9C16:
	movs r1, #0
_080D9C18:
	mov r0, sl
	movs r2, #0
	bl FUN_0822a470
	ldrb r0, [r6]
	cmp r0, #0xff
	bne _080D9C38
	movs r2, #0x98
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	ldr r1, [r0, #0x34]
	ldr r0, [r0, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	b _080D9C60
_080D9C38:
	ldrb r0, [r5]
	ldrb r1, [r6]
	movs r3, #0x98
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r2, [r2]
	ldrb r2, [r2, #5]
	add r3, sp, #0xc
	str r3, [sp]
	ldr r3, [r7, #0x58]
	str r3, [sp, #4]
	add r3, sp, #8
	bl FUN_080d8cc0
	ldr r0, [sp, #8]
	movs r1, #0
	strh r0, [r7, #0x1c]
	strh r1, [r7, #0x1e]
	ldr r0, [sp, #0xc]
	strh r0, [r7, #0x20]
_080D9C60:
	mov r5, sl
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	strb r1, [r5, #7]
	movs r0, #0x85
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0xff
	strh r0, [r1]
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #5
	bhi _080D9CB0
	lsls r0, r0, #2
	ldr r1, _080D9C88 @ =_080D9C8C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D9C88: .4byte _080D9C8C
_080D9C8C: @ jump table
	.4byte _080D9CA4 @ case 0
	.4byte _080D9CB0 @ case 1
	.4byte _080D9CAA @ case 2
	.4byte _080D9CAA @ case 3
	.4byte _080D9CB0 @ case 4
	.4byte _080D9CB0 @ case 5
_080D9CA4:
	mov r2, sb
	ldr r3, [r2, #0x50]
	b _080D9CB2
_080D9CAA:
	mov r5, sb
	ldr r3, [r5, #0x54]
	b _080D9CB2
_080D9CB0:
	movs r3, #0
_080D9CB2:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r5, [sp, #0x18]
	ldrb r2, [r5]
	movs r1, #0
	str r1, [sp]
	adds r1, r3, #0
	movs r3, #0
	bl FUN_08236fac
	ldr r2, [sp, #0x10]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	movs r0, #1
	ldr r3, [sp, #0x1c]
	strb r0, [r3]
	adds r0, r7, #0
_080D9CDA:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d9cec
FUN_080d9cec: @ 0x080D9CEC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	str r1, [sp, #0x28]
	str r2, [sp, #0x2c]
	adds r5, r3, #0
	ldr r1, [sp, #0x74]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	ldr r0, _080D9D20 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080D9D24
	bl FUN_080da848
	mov r8, r0
	cmp r0, #0
	bne _080D9D26
_080D9D1C:
	movs r0, #0
	b _080D9F3C
	.align 2, 0
_080D9D20: .4byte 0x0300015C
_080D9D24:
	mov r8, r0
_080D9D26:
	ldr r0, [sp, #0x80]
	cmp r0, #0
	beq _080D9D1C
	mov r0, r8
	bl FUN_080d99c4
	adds r7, r0, #0
	cmp r7, #0
	beq _080D9D1C
	movs r1, #0x2c
	adds r1, r1, r7
	mov sl, r1
	strb r4, [r1]
	adds r0, r7, #0
	adds r0, #0x2d
	movs r4, #1
	strb r4, [r0]
	strh r5, [r7, #0x26]
	adds r5, r7, #0
	adds r5, #0x2f
	ldr r0, [sp, #0x6c]
	strb r0, [r5]
	add r2, sp, #0x68
	ldrh r2, [r2]
	strh r2, [r7, #0x28]
	add r3, sp, #0x68
	ldrh r3, [r3]
	strh r3, [r7, #0x2a]
	mov r6, sb
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r1, #5
	bl Div
	strh r0, [r7, #0x3e]
	adds r1, r7, #0
	adds r1, #0x44
	strb r4, [r1]
	movs r2, #0x98
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r3, [sp, #0x80]
	str r3, [r0]
	ldr r6, [sp, #0x70]
	str r6, [r7, #0x48]
	movs r4, #0
	movs r3, #4
	movs r0, #0
	ldrsh r2, [r6, r0]
	movs r6, #0x3e
	ldrsh r0, [r7, r6]
	lsls r0, r0, #2
	mov r6, sl
	str r5, [sp, #0x38]
	str r1, [sp, #0x40]
	movs r1, #0x3b
	adds r1, r1, r7
	mov sl, r1
	movs r1, #0x3a
	adds r1, r1, r7
	mov sb, r1
	adds r1, r7, #0
	adds r1, #0x5c
	str r1, [sp, #0x44]
	movs r1, #0x98
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x3c]
	movs r1, #0x85
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x34]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x30]
	cmp r2, r0
	blt _080D9DC6
	movs r0, #0
	b _080D9DEA
_080D9DC6:
	subs r3, #1
	cmp r3, #0
	ble _080D9DE4
	ldr r0, [r7, #0x48]
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0x3e
	ldrsh r0, [r7, r2]
	muls r0, r3, r0
	cmp r1, r0
	blt _080D9DC6
	movs r0, #4
	subs r0, r0, r3
	strb r0, [r6]
	movs r4, #1
_080D9DE4:
	cmp r4, #0
	bne _080D9DEC
	movs r0, #3
_080D9DEA:
	strb r0, [r6]
_080D9DEC:
	movs r1, #0
	mov r3, sp
	ldrh r3, [r3, #0x2c]
	strh r3, [r7, #0x24]
	movs r0, #1
	mov r2, sl
	strb r0, [r2]
	mov r3, sb
	strb r0, [r3]
	ldr r0, [sp, #0x28]
	str r0, [r7]
	ldr r0, [sp, #0x7c]
	str r0, [r7, #0x58]
	str r1, [sp, #0x24]
	str r1, [sp, #0x20]
	ldr r5, [sp, #0x44]
	ldrb r0, [r3]
	adds r1, r0, #0
	cmp r0, #1
	beq _080D9E2E
	cmp r0, #1
	bgt _080D9E1E
	cmp r0, #0
	beq _080D9E28
	b _080D9E34
_080D9E1E:
	cmp r1, #5
	bgt _080D9E34
	cmp r1, #4
	blt _080D9E34
	b _080D9E2E
_080D9E28:
	mov r1, r8
	adds r1, #0x18
	b _080D9E36
_080D9E2E:
	mov r1, r8
	adds r1, #0x34
	b _080D9E36
_080D9E34:
	movs r1, #0
_080D9E36:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822a470
	ldr r1, [sp, #0x38]
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _080D9E54
	ldr r2, [sp, #0x3c]
	ldr r0, [r2]
	ldr r1, [r0, #0x34]
	ldr r0, [r0, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	b _080D9E7C
_080D9E54:
	mov r3, sl
	ldrb r0, [r3]
	ldr r2, [sp, #0x38]
	ldrb r1, [r2]
	ldr r3, [sp, #0x3c]
	ldr r2, [r3]
	ldrb r2, [r2, #5]
	add r3, sp, #0x20
	add r4, sp, #0x24
	str r4, [sp]
	ldr r4, [r7, #0x58]
	str r4, [sp, #4]
	bl FUN_080d8cc0
	ldr r0, [sp, #0x20]
	movs r1, #0
	strh r0, [r7, #0x1c]
	strh r1, [r7, #0x1e]
	ldr r0, [sp, #0x24]
	strh r0, [r7, #0x20]
_080D9E7C:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	strb r1, [r5, #7]
	movs r0, #0xff
	ldr r1, [sp, #0x34]
	strh r0, [r1]
	mov r2, sb
	ldrb r0, [r2]
	cmp r0, #5
	bhi _080D9EC8
	lsls r0, r0, #2
	ldr r1, _080D9EA0 @ =_080D9EA4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D9EA0: .4byte _080D9EA4
_080D9EA4: @ jump table
	.4byte _080D9EBC @ case 0
	.4byte _080D9EC8 @ case 1
	.4byte _080D9EC2 @ case 2
	.4byte _080D9EC2 @ case 3
	.4byte _080D9EC8 @ case 4
	.4byte _080D9EC8 @ case 5
_080D9EBC:
	mov r3, r8
	ldr r1, [r3, #0x50]
	b _080D9ECA
_080D9EC2:
	mov r0, r8
	ldr r1, [r0, #0x54]
	b _080D9ECA
_080D9EC8:
	movs r1, #0
_080D9ECA:
	ldrb r2, [r6]
	movs r0, #0
	str r0, [sp]
	ldr r0, [sp, #0x30]
	movs r3, #0
	bl FUN_08236fac
	ldr r2, [sp, #0x28]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	ldr r3, [sp, #0x44]
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	movs r0, #1
	ldr r6, [sp, #0x40]
	strb r0, [r6]
	ldr r0, _080D9F4C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080D9F3A
	ldr r0, [sp, #0x78]
	cmp r0, #1
	bne _080D9F3A
	ldr r2, _080D9F50 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080D9F54 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080D9F58 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	add r1, sp, #8
	movs r3, #2
_080D9F1C:
	ldr r0, [r7]
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r0, [r7]
	ldrh r0, [r0, #2]
	ldr r2, [sp, #0x68]
	adds r0, r0, r2
	strh r0, [r1, #2]
	ldr r0, [r7]
	ldrh r0, [r0, #4]
	strh r0, [r1, #4]
	adds r1, #8
	subs r3, #1
	cmp r3, #0
	bge _080D9F1C
_080D9F3A:
	adds r0, r7, #0
_080D9F3C:
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080D9F4C: .4byte 0x030047A4
_080D9F50: .4byte 0x030046B8
_080D9F54: .4byte 0x000003FF
_080D9F58: .4byte 0x0203B400

	thumb_func_start FUN_080d9f5c
FUN_080d9f5c: @ 0x080D9F5C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	str r1, [sp, #0x14]
	str r2, [sp, #0x18]
	str r3, [sp, #0x1c]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _080D9F88 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080D9F8C
	bl FUN_080da848
	mov sl, r0
	cmp r0, #0
	bne _080D9F8E
_080D9F84:
	movs r0, #0
	b _080DA100
	.align 2, 0
_080D9F88: .4byte 0x0300015C
_080D9F8C:
	mov sl, r0
_080D9F8E:
	ldr r0, [sp, #0x4c]
	cmp r0, #0
	beq _080D9F84
	mov r0, sl
	bl FUN_080d99c4
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0x88
	str r1, [sp, #0x20]
	cmp r7, #0
	beq _080D9F84
	movs r2, #0x2c
	adds r2, r2, r7
	mov sb, r2
	movs r4, #0
	strb r5, [r2]
	movs r3, #0x2f
	adds r3, r3, r7
	mov r8, r3
	ldr r0, [sp, #0x48]
	strb r0, [r3]
	adds r1, r7, #0
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
	adds r5, r7, #0
	adds r5, #0x3a
	movs r6, #2
	strb r6, [r5]
	strh r4, [r7, #0x30]
	mov r0, sp
	ldrh r0, [r0, #0x18]
	strh r0, [r7, #0x24]
	strh r4, [r7, #0x26]
	mov r1, sp
	ldrh r1, [r1, #0x1c]
	strh r1, [r7, #0x28]
	adds r0, r7, #0
	bl FUN_080d8644
	strh r4, [r7, #0x3c]
	strh r4, [r7, #8]
	strh r4, [r7, #6]
	strh r4, [r7, #4]
	adds r1, r7, #0
	adds r1, #0x3b
	strb r6, [r1]
	str r4, [r7, #0x58]
	movs r2, #0x98
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r3, [sp, #0x4c]
	str r3, [r0]
	str r4, [sp, #0x10]
	str r4, [sp, #0xc]
	ldr r6, [sp, #0x20]
	ldrb r0, [r5]
	mov r2, sb
	str r2, [sp, #0x24]
	mov sb, r5
	adds r4, r1, #0
	cmp r0, #2
	beq _080DA016
	cmp r0, #3
	beq _080DA01C
	movs r1, #0
	b _080DA020
_080DA016:
	mov r3, sl
	ldr r1, [r3, #0x58]
	b _080DA020
_080DA01C:
	mov r0, sl
	ldr r1, [r0, #0x58]
_080DA020:
	adds r0, r6, #0
	movs r2, #0
	bl FUN_0822d9f0
	ldrb r0, [r4]
	mov r2, r8
	ldrb r1, [r2]
	movs r3, #0x98
	lsls r3, r3, #1
	adds r5, r7, r3
	ldr r2, [r5]
	ldrb r2, [r2, #5]
	add r3, sp, #0xc
	add r4, sp, #0x10
	str r4, [sp]
	ldr r4, [r7, #0x58]
	str r4, [sp, #4]
	bl FUN_080d8cc0
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x10]
	adds r0, r6, #0
	bl FUN_0822dad4
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _080DA064
	ldr r0, [r5]
	ldr r1, [r0, #0x34]
	ldr r0, [r0, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	b _080DA074
_080DA064:
	adds r1, r7, #0
	adds r1, #0x1c
	movs r0, #0
	str r0, [sp, #8]
	add r0, sp, #8
	ldr r2, _080DA0A0 @ =0x05000002
	bl CpuSet
_080DA074:
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	movs r0, #0x7f
	strb r0, [r6, #0x10]
	strb r1, [r6, #0xf]
	movs r2, #0x85
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0xff
	strh r0, [r1]
	mov r3, sb
	ldrb r0, [r3]
	cmp r0, #5
	bhi _080DA0CC
	lsls r0, r0, #2
	ldr r1, _080DA0A4 @ =_080DA0A8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DA0A0: .4byte 0x05000002
_080DA0A4: .4byte _080DA0A8
_080DA0A8: @ jump table
	.4byte _080DA0C0 @ case 0
	.4byte _080DA0CC @ case 1
	.4byte _080DA0C6 @ case 2
	.4byte _080DA0C6 @ case 3
	.4byte _080DA0CC @ case 4
	.4byte _080DA0CC @ case 5
_080DA0C0:
	mov r0, sl
	ldr r1, [r0, #0x50]
	b _080DA0CE
_080DA0C6:
	mov r2, sl
	ldr r1, [r2, #0x54]
	b _080DA0CE
_080DA0CC:
	movs r1, #0
_080DA0CE:
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r3, [sp, #0x24]
	ldrb r2, [r3]
	movs r4, #0
	str r4, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [sp, #0x14]
	str r0, [r7]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	ldr r2, [sp, #0x20]
	str r0, [r2, #0x18]
	str r1, [r2, #0x1c]
	adds r1, r7, #0
	adds r1, #0x38
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x44
	strb r4, [r0]
	adds r0, r7, #0
_080DA100:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080da110
FUN_080da110: @ 0x080DA110
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	str r1, [sp, #0x14]
	str r2, [sp, #0x18]
	str r3, [sp, #0x1c]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _080DA13C @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080DA140
	bl FUN_080da848
	str r0, [sp, #0x20]
	cmp r0, #0
	bne _080DA142
_080DA138:
	movs r0, #0
	b _080DA346
	.align 2, 0
_080DA13C: .4byte 0x0300015C
_080DA140:
	str r0, [sp, #0x20]
_080DA142:
	ldr r0, [sp, #0x74]
	cmp r0, #0
	beq _080DA138
	ldr r0, [sp, #0x6c]
	movs r1, #3
	bl Div
	str r0, [sp, #0x28]
	ldr r0, [sp, #0x20]
	bl FUN_080d99c4
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0x88
	str r1, [sp, #0x24]
	cmp r7, #0
	beq _080DA138
	adds r2, r7, #0
	adds r2, #0x2c
	str r2, [sp, #0x2c]
	movs r4, #0
	strb r5, [r2]
	movs r3, #0x2f
	adds r3, r3, r7
	mov sb, r3
	ldr r0, [sp, #0x64]
	strb r0, [r3]
	ldr r0, [sp, #0x68]
	str r0, [r7, #0x48]
	adds r1, r7, #0
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
	movs r5, #0x3a
	adds r5, r5, r7
	mov r8, r5
	movs r5, #3
	mov r0, r8
	strb r5, [r0]
	movs r6, #0
	strh r4, [r7, #0x30]
	mov r1, sp
	ldrh r1, [r1, #0x18]
	strh r1, [r7, #0x24]
	strh r4, [r7, #0x26]
	mov r2, sp
	ldrh r2, [r2, #0x1c]
	strh r2, [r7, #0x28]
	adds r0, r7, #0
	bl FUN_080d8644
	strh r4, [r7, #0x3c]
	strh r4, [r7, #8]
	strh r4, [r7, #6]
	strh r4, [r7, #4]
	adds r2, r7, #0
	adds r2, #0x3b
	strb r5, [r2]
	ldr r3, [sp, #0x14]
	str r3, [r7]
	adds r1, r7, #0
	adds r1, #0x38
	strb r6, [r1]
	adds r0, r7, #0
	adds r0, #0x44
	strb r6, [r0]
	ldr r0, [sp, #0x78]
	str r0, [r7, #0x58]
	movs r5, #0x98
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r3, [sp, #0x74]
	str r3, [r0]
	movs r5, #0
	mov sl, r5
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0x3c]
	mov r3, sb
	str r3, [sp, #0x40]
	mov r5, r8
	str r5, [sp, #0x34]
	str r2, [sp, #0x38]
	str r1, [sp, #0x30]
	ldr r0, [sp, #0x70]
	cmp sl, r0
	blt _080DA1F0
	b _080DA344
_080DA1F0:
	mov r1, sl
	lsls r3, r1, #2
	adds r1, r7, #0
	adds r1, #0x4c
	adds r1, r1, r3
	mov r2, sl
	lsls r4, r2, #4
	adds r0, r4, r2
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0x35
	add r0, sl
	movs r2, #0
	strb r2, [r0]
	mov r5, sl
	lsls r1, r5, #1
	adds r0, r7, #0
	adds r0, #0x3e
	adds r0, r0, r1
	ldr r5, [sp, #0x28]
	mov r1, sl
	muls r1, r5, r1
	strh r1, [r0]
	str r2, [sp, #0x10]
	str r2, [sp, #0xc]
	mov r1, sl
	adds r0, r3, r1
	lsls r0, r0, #3
	adds r0, #0x88
	adds r5, r7, r0
	ldr r2, [sp, #0x34]
	ldrb r0, [r2]
	mov sb, r3
	mov r8, r4
	cmp r0, #2
	beq _080DA240
	cmp r0, #3
	beq _080DA246
	movs r1, #0
	b _080DA24A
_080DA240:
	ldr r3, [sp, #0x20]
	ldr r1, [r3, #0x58]
	b _080DA24A
_080DA246:
	ldr r0, [sp, #0x20]
	ldr r1, [r0, #0x58]
_080DA24A:
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822d9f0
	ldr r1, [sp, #0x38]
	ldrb r0, [r1]
	ldr r2, [sp, #0x40]
	ldrb r1, [r2]
	movs r3, #0x98
	lsls r3, r3, #1
	adds r6, r7, r3
	ldr r2, [r6]
	ldrb r2, [r2, #5]
	add r3, sp, #0xc
	add r4, sp, #0x10
	str r4, [sp]
	ldr r4, [r7, #0x58]
	str r4, [sp, #4]
	bl FUN_080d8cc0
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x10]
	adds r0, r5, #0
	bl FUN_0822dad4
	ldr r1, [sp, #0x40]
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _080DA290
	ldr r0, [r6]
	ldr r1, [r0, #0x34]
	ldr r0, [r0, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	b _080DA2A0
_080DA290:
	adds r1, r7, #0
	adds r1, #0x1c
	movs r0, #0
	str r0, [sp, #8]
	add r0, sp, #8
	ldr r2, _080DA2D0 @ =0x05000002
	bl CpuSet
_080DA2A0:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	movs r0, #0x7f
	strb r0, [r5, #0x10]
	strb r1, [r5, #0xf]
	mov r2, r8
	adds r0, r7, r2
	movs r3, #0x85
	lsls r3, r3, #1
	adds r1, r0, r3
	movs r0, #0xff
	strh r0, [r1]
	ldr r5, [sp, #0x34]
	ldrb r0, [r5]
	cmp r0, #5
	bhi _080DA2FC
	lsls r0, r0, #2
	ldr r1, _080DA2D4 @ =_080DA2D8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DA2D0: .4byte 0x05000002
_080DA2D4: .4byte _080DA2D8
_080DA2D8: @ jump table
	.4byte _080DA2F0 @ case 0
	.4byte _080DA2FC @ case 1
	.4byte _080DA2F6 @ case 2
	.4byte _080DA2F6 @ case 3
	.4byte _080DA2FC @ case 4
	.4byte _080DA2FC @ case 5
_080DA2F0:
	ldr r0, [sp, #0x20]
	ldr r3, [r0, #0x50]
	b _080DA2FE
_080DA2F6:
	ldr r1, [sp, #0x20]
	ldr r3, [r1, #0x54]
	b _080DA2FE
_080DA2FC:
	movs r3, #0
_080DA2FE:
	movs r0, #0x80
	lsls r0, r0, #1
	add r0, r8
	adds r0, r7, r0
	ldr r5, [sp, #0x3c]
	ldrb r2, [r5]
	movs r1, #0
	str r1, [sp]
	adds r1, r3, #0
	movs r3, #0
	bl FUN_08236fac
	mov r2, sb
	add r2, sl
	lsls r2, r2, #3
	ldr r0, [sp, #0x24]
	adds r2, r2, r0
	ldr r3, [sp, #0x14]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2, #0x18]
	str r1, [r2, #0x1c]
	movs r0, #1
	mov r5, sl
	lsls r0, r5
	ldr r2, [sp, #0x30]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	movs r3, #1
	add sl, r3
	ldr r5, [sp, #0x70]
	cmp sl, r5
	bge _080DA344
	b _080DA1F0
_080DA344:
	adds r0, r7, #0
_080DA346:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080da358
FUN_080da358: @ 0x080DA358
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r0, [sp, #0x10]
	mov sb, r1
	adds r5, r2, #0
	adds r4, r3, #0
	ldr r0, _080DA384 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080DA388
	bl FUN_080da848
	mov r8, r0
	cmp r0, #0
	bne _080DA38A
_080DA37E:
	movs r0, #0
	b _080DA4E8
	.align 2, 0
_080DA384: .4byte 0x0300015C
_080DA388:
	mov r8, r0
_080DA38A:
	ldr r0, [sp, #0x44]
	cmp r0, #0
	beq _080DA37E
	mov r0, r8
	bl FUN_080d99c4
	adds r7, r0, #0
	cmp r7, #0
	beq _080DA37E
	movs r1, #0x2c
	adds r1, r1, r7
	mov ip, r1
	movs r2, #0
	movs r0, #5
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x2d
	movs r1, #1
	strb r1, [r0]
	strh r5, [r7, #0x26]
	adds r5, r7, #0
	adds r5, #0x2f
	ldr r0, [sp, #0x3c]
	strb r0, [r5]
	strh r4, [r7, #0x28]
	strh r4, [r7, #0x2a]
	adds r4, r7, #0
	adds r4, #0x44
	strb r1, [r4]
	strh r2, [r7, #0x30]
	mov r3, sb
	strh r3, [r7, #0x24]
	adds r3, r7, #0
	adds r3, #0x3b
	movs r0, #4
	strb r0, [r3]
	adds r1, r7, #0
	adds r1, #0x3a
	strb r0, [r1]
	ldr r6, [sp, #0x10]
	str r6, [r7]
	ldr r0, [sp, #0x40]
	str r0, [r7, #0x58]
	movs r6, #0x98
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r6, [sp, #0x44]
	str r6, [r0]
	str r2, [sp, #0xc]
	str r2, [sp, #8]
	adds r6, r7, #0
	adds r6, #0x5c
	ldrb r0, [r1]
	mov sl, ip
	str r4, [sp, #0x14]
	adds r4, r3, #0
	mov sb, r1
	str r6, [sp, #0x18]
	cmp r0, #1
	beq _080DA41C
	cmp r0, #1
	bgt _080DA40C
	cmp r0, #0
	beq _080DA416
	b _080DA422
_080DA40C:
	cmp r0, #5
	bgt _080DA422
	cmp r0, #4
	blt _080DA422
	b _080DA41C
_080DA416:
	mov r1, r8
	adds r1, #0x18
	b _080DA424
_080DA41C:
	mov r1, r8
	adds r1, #0x34
	b _080DA424
_080DA422:
	movs r1, #0
_080DA424:
	adds r0, r6, #0
	movs r2, #0
	bl FUN_0822a470
	ldrb r0, [r5]
	cmp r0, #0xff
	bne _080DA444
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x34]
	ldr r0, [r0, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	b _080DA46C
_080DA444:
	ldrb r0, [r4]
	ldrb r1, [r5]
	movs r3, #0x98
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r2, [r2]
	ldrb r2, [r2, #5]
	add r3, sp, #0xc
	str r3, [sp]
	ldr r3, [r7, #0x58]
	str r3, [sp, #4]
	add r3, sp, #8
	bl FUN_080d8cc0
	ldr r0, [sp, #8]
	movs r1, #0
	strh r0, [r7, #0x1c]
	strh r1, [r7, #0x1e]
	ldr r0, [sp, #0xc]
	strh r0, [r7, #0x20]
_080DA46C:
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	strb r1, [r6, #7]
	movs r6, #0x85
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r0, #0xff
	strh r0, [r1]
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #5
	bhi _080DA4BC
	lsls r0, r0, #2
	ldr r1, _080DA494 @ =_080DA498
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DA494: .4byte _080DA498
_080DA498: @ jump table
	.4byte _080DA4B0 @ case 0
	.4byte _080DA4BC @ case 1
	.4byte _080DA4B6 @ case 2
	.4byte _080DA4B6 @ case 3
	.4byte _080DA4BC @ case 4
	.4byte _080DA4BC @ case 5
_080DA4B0:
	mov r2, r8
	ldr r3, [r2, #0x50]
	b _080DA4BE
_080DA4B6:
	mov r6, r8
	ldr r3, [r6, #0x54]
	b _080DA4BE
_080DA4BC:
	movs r3, #0
_080DA4BE:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, r1
	mov r6, sl
	ldrb r2, [r6]
	movs r1, #0
	str r1, [sp]
	adds r1, r3, #0
	movs r3, #0
	bl FUN_08236fac
	ldr r2, [sp, #0x10]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	ldr r3, [sp, #0x18]
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	movs r0, #1
	ldr r6, [sp, #0x14]
	strb r0, [r6]
	adds r0, r7, #0
_080DA4E8:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080da4f8
FUN_080da4f8: @ 0x080DA4F8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r0, [sp, #0x10]
	mov sb, r1
	adds r5, r2, #0
	adds r4, r3, #0
	ldr r0, _080DA524 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080DA528
	bl FUN_080da848
	mov r8, r0
	cmp r0, #0
	bne _080DA52A
_080DA51E:
	movs r0, #0
	b _080DA688
	.align 2, 0
_080DA524: .4byte 0x0300015C
_080DA528:
	mov r8, r0
_080DA52A:
	ldr r0, [sp, #0x44]
	cmp r0, #0
	beq _080DA51E
	mov r0, r8
	bl FUN_080d99c4
	adds r7, r0, #0
	cmp r7, #0
	beq _080DA51E
	movs r1, #0x2c
	adds r1, r1, r7
	mov ip, r1
	movs r2, #0
	movs r0, #6
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x2d
	movs r1, #1
	strb r1, [r0]
	strh r5, [r7, #0x26]
	adds r5, r7, #0
	adds r5, #0x2f
	ldr r0, [sp, #0x3c]
	strb r0, [r5]
	strh r4, [r7, #0x28]
	strh r4, [r7, #0x2a]
	adds r4, r7, #0
	adds r4, #0x44
	strb r1, [r4]
	strh r2, [r7, #0x30]
	mov r3, sb
	strh r3, [r7, #0x24]
	adds r3, r7, #0
	adds r3, #0x3b
	movs r0, #5
	strb r0, [r3]
	adds r1, r7, #0
	adds r1, #0x3a
	strb r0, [r1]
	ldr r6, [sp, #0x10]
	str r6, [r7]
	ldr r0, [sp, #0x40]
	str r0, [r7, #0x58]
	movs r6, #0x98
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r6, [sp, #0x44]
	str r6, [r0]
	str r2, [sp, #0xc]
	str r2, [sp, #8]
	adds r6, r7, #0
	adds r6, #0x5c
	ldrb r0, [r1]
	mov sl, ip
	str r4, [sp, #0x14]
	adds r4, r3, #0
	mov sb, r1
	str r6, [sp, #0x18]
	cmp r0, #1
	beq _080DA5BC
	cmp r0, #1
	bgt _080DA5AC
	cmp r0, #0
	beq _080DA5B6
	b _080DA5C2
_080DA5AC:
	cmp r0, #5
	bgt _080DA5C2
	cmp r0, #4
	blt _080DA5C2
	b _080DA5BC
_080DA5B6:
	mov r1, r8
	adds r1, #0x18
	b _080DA5C4
_080DA5BC:
	mov r1, r8
	adds r1, #0x34
	b _080DA5C4
_080DA5C2:
	movs r1, #0
_080DA5C4:
	adds r0, r6, #0
	movs r2, #0
	bl FUN_0822a470
	ldrb r0, [r5]
	cmp r0, #0xff
	bne _080DA5E4
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x34]
	ldr r0, [r0, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	b _080DA60C
_080DA5E4:
	ldrb r0, [r4]
	ldrb r1, [r5]
	movs r3, #0x98
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r2, [r2]
	ldrb r2, [r2, #5]
	add r3, sp, #0xc
	str r3, [sp]
	ldr r3, [r7, #0x58]
	str r3, [sp, #4]
	add r3, sp, #8
	bl FUN_080d8cc0
	ldr r0, [sp, #8]
	movs r1, #0
	strh r0, [r7, #0x1c]
	strh r1, [r7, #0x1e]
	ldr r0, [sp, #0xc]
	strh r0, [r7, #0x20]
_080DA60C:
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	strb r1, [r6, #7]
	movs r6, #0x85
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r0, #0xff
	strh r0, [r1]
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #5
	bhi _080DA65C
	lsls r0, r0, #2
	ldr r1, _080DA634 @ =_080DA638
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DA634: .4byte _080DA638
_080DA638: @ jump table
	.4byte _080DA650 @ case 0
	.4byte _080DA65C @ case 1
	.4byte _080DA656 @ case 2
	.4byte _080DA656 @ case 3
	.4byte _080DA65C @ case 4
	.4byte _080DA65C @ case 5
_080DA650:
	mov r2, r8
	ldr r3, [r2, #0x50]
	b _080DA65E
_080DA656:
	mov r6, r8
	ldr r3, [r6, #0x54]
	b _080DA65E
_080DA65C:
	movs r3, #0
_080DA65E:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, r1
	mov r6, sl
	ldrb r2, [r6]
	movs r1, #0
	str r1, [sp]
	adds r1, r3, #0
	movs r3, #0
	bl FUN_08236fac
	ldr r2, [sp, #0x10]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	ldr r3, [sp, #0x18]
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	movs r0, #1
	ldr r6, [sp, #0x14]
	strb r0, [r6]
	adds r0, r7, #0
_080DA688:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080da698
FUN_080da698: @ 0x080DA698
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	ldr r4, [sp, #0x2c]
	ldr r5, [sp, #0x30]
	ldr r6, [sp, #0x34]
	ldr r7, [sp, #0x38]
	str r7, [sp, #0x10]
	ldr r7, [sp, #0x3c]
	str r7, [sp, #0x14]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r4, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	movs r4, #3
	str r4, [sp, #0xc]
	bl FUN_080da110
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080da6c4
FUN_080da6c4: @ 0x080DA6C4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	ldr r4, [sp, #0x2c]
	ldr r5, [sp, #0x30]
	ldr r6, [sp, #0x34]
	ldr r7, [sp, #0x38]
	str r7, [sp, #0xc]
	ldr r7, [sp, #0x3c]
	str r7, [sp, #0x10]
	ldr r7, [sp, #0x40]
	str r7, [sp, #0x14]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r4, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	bl FUN_080da110
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080da6f0
FUN_080da6f0: @ 0x080DA6F0
	push {r4, r5, r6, r7, lr}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x5c
	ldr r3, _080DA730 @ =0x000009FC
	adds r0, r1, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _080DA728
	ldr r7, _080DA734 @ =0x085AD304
	adds r5, r1, #0
	adds r5, #0x89
	adds r4, r2, #0
	ldr r0, _080DA738 @ =0x000008C8
	adds r6, r1, r0
_080DA70E:
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	cmp r4, r6
	ble _080DA70E
_080DA728:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DA730: .4byte 0x000009FC
_080DA734: .4byte 0x085AD304
_080DA738: .4byte 0x000008C8

	thumb_func_start FUN_080da73c
FUN_080da73c: @ 0x080DA73C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	movs r2, #0
	ldr r0, _080DA760 @ =0x000009FC
	add r0, r8
	mov sb, r0
_080DA74E:
	movs r1, #1
	lsls r1, r2
	mov r3, sb
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _080DA764
	movs r0, #1
	b _080DA766
	.align 2, 0
_080DA760: .4byte 0x000009FC
_080DA764:
	movs r0, #0
_080DA766:
	adds r7, r2, #1
	cmp r0, #0
	beq _080DA7AE
	movs r0, #0x9a
	lsls r0, r0, #1
	muls r0, r2, r0
	adds r0, #0x5c
	mov r1, r8
	adds r5, r1, r0
	movs r6, #0
	adds r4, r5, #0
	adds r4, #0x88
_080DA77E:
	adds r0, r5, #0
	adds r0, #0x38
	ldrb r0, [r0]
	asrs r0, r6
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080DA794
	adds r0, r4, #0
	bl FUN_0822dabc
_080DA794:
	adds r4, #0x28
	adds r6, #1
	cmp r6, #2
	ble _080DA77E
	adds r0, r5, #0
	adds r0, #0x44
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DA7AE
	adds r0, r5, #0
	adds r0, #0x5c
	bl FUN_0822a4e0
_080DA7AE:
	adds r2, r7, #0
	cmp r2, #7
	ble _080DA74E
	movs r1, #0
	ldr r0, _080DA7C8 @ =0x0300015C
	str r1, [r0]
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DA7C8: .4byte 0x0300015C

	thumb_func_start FUN_080da7cc
FUN_080da7cc: @ 0x080DA7CC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0x18
	ldr r1, _080DA808 @ =0x0000363C
	bl FUN_0822b16c
	adds r0, r5, #0
	adds r0, #0x34
	ldr r1, _080DA80C @ =0x0000363D
	bl FUN_0822b16c
	ldr r0, _080DA810 @ =0x00001C1C
	bl GetParticleGroup
	str r0, [r5, #0x58]
	ldr r4, _080DA814 @ =0x0000922E
	ldr r1, _080DA818 @ =0x00006830
	adds r0, r4, #0
	bl GetFile
	str r0, [r5, #0x50]
	ldr r1, _080DA81C @ =0x0000D41F
	adds r0, r4, #0
	bl GetFile
	str r0, [r5, #0x54]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DA808: .4byte 0x0000363C
_080DA80C: .4byte 0x0000363D
_080DA810: .4byte 0x00001C1C
_080DA814: .4byte 0x0000922E
_080DA818: .4byte 0x00006830
_080DA81C: .4byte 0x0000D41F

	thumb_func_start FUN_080da820
FUN_080da820: @ 0x080DA820
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080DA840 @ =0x000009FC
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_080da7cc
	ldr r0, _080DA844 @ =0x0300015C
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080DA840: .4byte 0x000009FC
_080DA844: .4byte 0x0300015C

	thumb_func_start FUN_080da848
FUN_080da848: @ 0x080DA848
	push {r4, lr}
	ldr r0, _080DA880 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	bne _080DA88E
	movs r1, #0xa0
	lsls r1, r1, #4
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080DA88C
	ldr r1, _080DA884 @ =FUN_080da6f0
	ldr r2, _080DA888 @ =FUN_080da73c
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080da820
	cmp r0, #0
	bge _080DA88C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080DA88E
	.align 2, 0
_080DA880: .4byte 0x0300015C
_080DA884: .4byte FUN_080da6f0
_080DA888: .4byte FUN_080da73c
_080DA88C:
	adds r0, r4, #0
_080DA88E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080da894
FUN_080da894: @ 0x080DA894
	ldr r1, _080DA89C @ =0x0300015C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080DA89C: .4byte 0x0300015C

	thumb_func_start FUN_080da8a0
FUN_080da8a0: @ 0x080DA8A0
	push {lr}
	adds r1, r0, #0
	ldr r0, _080DA8C0 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	beq _080DA8C4
	cmp r1, #0
	beq _080DA8C4
	adds r0, r1, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DA8C4
	movs r0, #0
	b _080DA8C6
	.align 2, 0
_080DA8C0: .4byte 0x0300015C
_080DA8C4:
	movs r0, #1
_080DA8C6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080da8cc
FUN_080da8cc: @ 0x080DA8CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _080DA908 @ =0x0300015C
	ldr r0, [r0]
	cmp r0, #0
	beq _080DA9B4
	str r0, [sp]
	ldr r1, _080DA90C @ =0x000009FC
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080DA9B4
	movs r3, #0
	ldr r2, [sp]
	adds r2, r2, r1
	mov sl, r2
_080DA8F4:
	movs r1, #1
	lsls r1, r3
	mov r7, sl
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _080DA910
	movs r0, #1
	b _080DA912
	.align 2, 0
_080DA908: .4byte 0x0300015C
_080DA90C: .4byte 0x000009FC
_080DA910:
	movs r0, #0
_080DA912:
	adds r1, r3, #1
	mov sb, r1
	cmp r0, #0
	beq _080DA9AE
	movs r0, #0x9a
	lsls r0, r0, #1
	muls r0, r3, r0
	adds r0, #0x5c
	ldr r2, [sp]
	adds r5, r2, r0
	adds r4, r5, #0
	adds r4, #0x88
	adds r6, r5, #0
	adds r6, #0x5c
	adds r2, r5, #0
	adds r2, #0x39
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _080DA9AE
	movs r1, #1
	lsls r1, r0
	mov r7, sl
	ldr r0, [r7]
	bics r0, r1
	str r0, [r7]
	adds r0, r5, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	cmp r0, #1
	bls _080DA958
	cmp r0, #4
	beq _080DA958
	cmp r0, #5
	bne _080DA978
_080DA958:
	adds r4, r5, #0
	adds r4, #0x44
	ldrb r0, [r4]
	movs r1, #0x39
	adds r1, r1, r5
	mov r8, r1
	adds r3, #1
	mov sb, r3
	cmp r0, #0
	beq _080DA99E
	adds r0, r6, #0
	bl FUN_0822a4e0
	movs r0, #0
	strb r0, [r4]
	b _080DA99E
_080DA978:
	movs r6, #0
	mov r8, r2
	adds r7, r5, #0
	adds r7, #0x38
_080DA980:
	ldrb r0, [r7]
	asrs r0, r6
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq _080DA992
	adds r0, r4, #0
	bl FUN_0822dabc
_080DA992:
	adds r4, #0x28
	adds r6, #1
	cmp r6, #2
	ble _080DA980
	movs r0, #0
	strb r0, [r7]
_080DA99E:
	adds r0, r5, #0
	movs r1, #0x9a
	lsls r1, r1, #1
	bl ClearMemory
	movs r0, #0xff
	mov r7, r8
	strb r0, [r7]
_080DA9AE:
	mov r3, sb
	cmp r3, #7
	ble _080DA8F4
_080DA9B4:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080da9c4
FUN_080da9c4: @ 0x080DA9C4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, [sp, #0x3c]
	ldr r7, [sp, #0x40]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	lsls r3, r3, #0x18
	lsrs r6, r3, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	cmp r5, #0
	beq _080DA9F2
	cmp r6, #0x7f
	bne _080DAA6C
	cmp r4, #0
	bne _080DA9F6
_080DA9F2:
	movs r0, #0
	b _080DAB8C
_080DA9F6:
	cmp r2, #5
	bls _080DA9FC
	b _080DAB8C
_080DA9FC:
	lsls r0, r2, #2
	ldr r1, _080DAA08 @ =_080DAA0C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DAA08: .4byte _080DAA0C
_080DAA0C: @ jump table
	.4byte _080DAA24 @ case 0
	.4byte _080DAA30 @ case 1
	.4byte _080DAA48 @ case 2
	.4byte _080DAA3C @ case 3
	.4byte _080DAA54 @ case 4
	.4byte _080DAA60 @ case 5
_080DAA24:
	ldrh r2, [r5]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080d99d4
	b _080DAB8C
_080DAA30:
	ldrh r2, [r5]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080d99d4
	b _080DAB8C
_080DAA3C:
	ldrh r2, [r5]
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080d9a9c
	b _080DAB8C
_080DAA48:
	ldrh r2, [r5]
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080d99d4
	b _080DAB8C
_080DAA54:
	ldrh r2, [r5]
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080d99d4
	b _080DAB8C
_080DAA60:
	ldrh r2, [r5]
	adds r0, r4, #0
	movs r1, #5
	bl FUN_080d99d4
	b _080DAB8C
_080DAA6C:
	ldrh r2, [r5]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080d99d4
	adds r4, r0, #0
	ldrh r2, [r5]
	movs r1, #1
	bl FUN_080d99d4
	adds r4, r0, #0
	ldrh r2, [r5]
	movs r1, #2
	bl FUN_080d99d4
	adds r4, r0, #0
	ldrh r2, [r5]
	movs r1, #4
	bl FUN_080d99d4
	adds r4, r0, #0
	ldrh r2, [r5]
	movs r1, #5
	bl FUN_080d99d4
	adds r4, r0, #0
	ldrh r2, [r5]
	movs r1, #3
	bl FUN_080d9a9c
	movs r2, #4
	ldrh r1, [r5, #2]
	ands r1, r2
	movs r3, #0
	cmp r1, #0
	beq _080DAAB6
	movs r3, #0xff
_080DAAB6:
	mov r1, r8
	cmp r1, #5
	bhi _080DAB8C
	lsls r0, r1, #2
	ldr r1, _080DAAC8 @ =_080DAACC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DAAC8: .4byte _080DAACC
_080DAACC: @ jump table
	.4byte _080DAAE4 @ case 0
	.4byte _080DAAFE @ case 1
	.4byte _080DAB26 @ case 2
	.4byte _080DAB3A @ case 3
	.4byte _080DAB5E @ case 4
	.4byte _080DAB76 @ case 5
_080DAAE4:
	adds r1, r5, #0
	adds r1, #8
	ldrh r2, [r5]
	str r7, [sp]
	str r3, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r6, #0
	ldr r3, [sp, #0x44]
	bl FUN_080d9b3c
	b _080DAB8C
_080DAAFE:
	adds r1, r5, #0
	adds r1, #8
	ldrh r2, [r5]
	str r7, [sp]
	str r3, [sp, #4]
	ldr r3, [sp, #0x38]
	str r3, [sp, #8]
	mov r3, sb
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	str r5, [sp, #0x18]
	adds r0, r6, #0
	ldr r3, [sp, #0x44]
	bl FUN_080d9cec
	b _080DAB8C
_080DAB26:
	adds r1, r5, #0
	adds r1, #8
	ldrh r2, [r5]
	str r3, [sp]
	str r5, [sp, #4]
	movs r0, #1
	adds r3, r7, #0
	bl FUN_080d9f5c
	b _080DAB8C
_080DAB3A:
	adds r1, r5, #0
	adds r1, #8
	ldrh r2, [r5]
	str r3, [sp]
	ldr r6, [sp, #0x38]
	str r6, [sp, #4]
	mov r3, sb
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	movs r0, #7
	adds r3, r7, #0
	bl FUN_080da698
	b _080DAB8C
_080DAB5E:
	adds r0, r5, #0
	adds r0, #8
	ldrh r1, [r5]
	str r3, [sp]
	movs r2, #0
	str r2, [sp, #4]
	str r5, [sp, #8]
	ldr r2, [sp, #0x44]
	adds r3, r7, #0
	bl FUN_080da358
	b _080DAB8C
_080DAB76:
	adds r0, r5, #0
	adds r0, #8
	ldrh r1, [r5]
	str r3, [sp]
	movs r2, #0
	str r2, [sp, #4]
	str r5, [sp, #8]
	ldr r2, [sp, #0x44]
	adds r3, r7, #0
	bl FUN_080da4f8
_080DAB8C:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080dab9c
FUN_080dab9c: @ 0x080DAB9C
	push {lr}
	adds r1, r0, #0
	ldr r0, _080DABE0 @ =0x03000160
	ldr r2, [r0]
	cmp r1, #0
	blt _080DABDA
	movs r0, #0xa4
	muls r0, r1, r0
	adds r0, #0x3c
	adds r3, r2, r0
	adds r0, r3, #0
	adds r0, #0x42
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080DABDA
	movs r1, #0x3e
	ldrsh r0, [r3, r1]
	cmp r0, #2
	beq _080DABDA
	adds r2, r3, #0
	adds r2, #0x40
	ldrh r1, [r2]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2]
	adds r2, #0x12
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_080DABDA:
	pop {r0}
	bx r0
	.align 2, 0
_080DABE0: .4byte 0x03000160

	thumb_func_start FUN_080dabe4
FUN_080dabe4: @ 0x080DABE4
	push {lr}
	adds r1, r0, #0
	ldr r0, _080DAC1C @ =0x03000160
	ldr r2, [r0]
	cmp r1, #0
	blt _080DAC16
	movs r0, #0xa4
	muls r0, r1, r0
	adds r0, #0x3c
	adds r2, r2, r0
	adds r0, r2, #0
	adds r0, #0x42
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080DAC16
	movs r1, #0x3e
	ldrsh r0, [r2, r1]
	cmp r0, #2
	beq _080DAC16
	adds r2, #0x40
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_080DAC16:
	pop {r0}
	bx r0
	.align 2, 0
_080DAC1C: .4byte 0x03000160

	thumb_func_start FUN_080dac20
FUN_080dac20: @ 0x080DAC20
	bx lr
	.align 2, 0

	thumb_func_start FUN_080dac24
FUN_080dac24: @ 0x080DAC24
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r1, #0
	adds r6, r7, #0
	adds r6, #0x44
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #0
	bgt _080DAC4A
	movs r0, #0x14
	strh r0, [r6]
	adds r2, r7, #0
	adds r2, #0x40
	ldrh r1, [r2]
	subs r0, #0x19
	ands r0, r1
	strh r0, [r2]
	b _080DAC94
_080DAC4A:
	cmp r0, #0xa
	ble _080DAC8E
	ldr r0, _080DACA0 @ =0x0203B400
	mov r8, r0
	ldr r4, _080DACA4 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080DACA8 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x28
	bl Mod
	ldrh r1, [r7, #0x1c]
	subs r1, #0x14
	adds r1, r1, r0
	strh r1, [r7, #0x1c]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x28
	bl Mod
	ldrh r1, [r7, #0x20]
	subs r1, #0x14
	adds r1, r1, r0
	strh r1, [r7, #0x20]
_080DAC8E:
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
_080DAC94:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DACA0: .4byte 0x0203B400
_080DACA4: .4byte 0x030046B8
_080DACA8: .4byte 0x000003FF

	thumb_func_start FUN_080dacac
FUN_080dacac: @ 0x080DACAC
	adds r3, r2, #0
	adds r3, #0x40
	ldrh r1, [r3]
	movs r0, #2
	orrs r0, r1
	strh r0, [r3]
	adds r2, #0x52
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	bx lr

	thumb_func_start FUN_080dacc4
FUN_080dacc4: @ 0x080DACC4
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	ldr r2, _080DAD3C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r1, #0x40
	orrs r0, r1
	ldr r5, _080DAD40 @ =0x0000FFFF
	ands r0, r5
	movs r4, #0x80
	lsls r4, r4, #0x10
	orrs r0, r4
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r3, #0x10
	orrs r0, r3
	ands r0, r5
	orrs r0, r4
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r1, #4]
	adds r4, r6, #0
	adds r4, #0x4c
	ldr r2, _080DAD44 @ =0x00004001
	str r3, [sp]
	str r1, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r1, r6, #0
	adds r1, #0x9c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _080DAD48 @ =FUN_080dacac
	adds r0, r4, #0
	adds r2, r6, #0
	bl FUN_0823651c
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DAD3C: .4byte 0xFFFF0000
_080DAD40: .4byte 0x0000FFFF
_080DAD44: .4byte 0x00004001
_080DAD48: .4byte FUN_080dacac

	thumb_func_start FUN_080dad4c
FUN_080dad4c: @ 0x080DAD4C
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r2, #0
	movs r5, #1
_080DAD54:
	adds r0, r5, #0
	lsls r0, r2
	ldr r1, [r3, #0x38]
	ands r0, r1
	adds r4, r1, #0
	cmp r0, #0
	beq _080DAD66
	movs r0, #1
	b _080DAD68
_080DAD66:
	movs r0, #0
_080DAD68:
	cmp r0, #0
	bne _080DAD84
	movs r0, #0xa4
	muls r0, r2, r0
	adds r0, #0x3c
	adds r0, r3, r0
	adds r1, r5, #0
	lsls r1, r2
	orrs r1, r4
	str r1, [r3, #0x38]
	adds r1, r0, #0
	adds r1, #0x42
	strh r2, [r1]
	b _080DAD8C
_080DAD84:
	adds r2, #1
	cmp r2, #7
	ble _080DAD54
	movs r0, #0
_080DAD8C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080dad94
FUN_080dad94: @ 0x080DAD94
	push {lr}
	adds r3, r0, #0
	ldr r0, _080DADD0 @ =0x030047E0
	ldrb r0, [r0, #0xe]
	cmp r0, #5
	beq _080DADE6
	cmp r0, #0
	beq _080DADE6
	cmp r0, #4
	beq _080DADE6
	ldr r0, _080DADD4 @ =0x030046A0
	ldr r2, [r0]
	ldr r1, _080DADD8 @ =0x00000934
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080DADE6
	adds r0, r3, #0
	adds r0, #0x46
	movs r3, #0x92
	lsls r3, r3, #2
	adds r1, r2, r3
	ldr r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	bne _080DADDC
	movs r0, #1
	b _080DADDE
	.align 2, 0
_080DADD0: .4byte 0x030047E0
_080DADD4: .4byte 0x030046A0
_080DADD8: .4byte 0x00000934
_080DADDC:
	movs r0, #0
_080DADDE:
	cmp r0, #0
	beq _080DADE6
	movs r0, #1
	b _080DADE8
_080DADE6:
	movs r0, #0
_080DADE8:
	pop {r1}
	bx r1

	thumb_func_start FUN_080dadec
FUN_080dadec: @ 0x080DADEC
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r6, r3, #0
	adds r6, #0x3c
	movs r4, #0
	movs r5, #0
	movs r2, #0
_080DADFA:
	movs r1, #1
	lsls r1, r2
	ldr r0, [r3, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080DAE0A
	movs r0, #1
	b _080DAE0C
_080DAE0A:
	movs r0, #0
_080DAE0C:
	cmp r0, #0
	beq _080DAE2E
	movs r0, #0xa4
	muls r0, r2, r0
	adds r0, r0, r6
	adds r0, #0x40
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080DAE24
	movs r4, #1
_080DAE24:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080DAE2E
	movs r5, #1
_080DAE2E:
	adds r2, #1
	cmp r2, #7
	ble _080DADFA
	cmp r4, #0
	bne _080DAE44
	ldr r0, _080DAE58 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, _080DAE5C @ =0x000003FF
	adds r0, r0, r1
	movs r1, #0xff
	strb r1, [r0]
_080DAE44:
	cmp r5, #0
	bne _080DAE50
	movs r0, #1
	rsbs r0, r0, #0
	bl FUN_0808689c
_080DAE50:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DAE58: .4byte 0x03002BE0
_080DAE5C: .4byte 0x000003FF

	thumb_func_start FUN_080dae60
FUN_080dae60: @ 0x080DAE60
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	adds r4, r1, #0
	adds r7, r4, #0
	adds r0, r4, #0
	adds r0, #0x9c
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	adds r5, r4, #0
	adds r5, #0x40
	ldrh r1, [r5]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	cmp r6, #0
	beq _080DAF3E
	adds r0, r4, #0
	adds r0, #0x48
	ldrh r2, [r0]
	ldr r0, _080DAEAC @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r1, [r0]
	cmp r1, r2
	bge _080DAEB4
	ldr r3, _080DAEB0 @ =0xFFFFFF00
	adds r0, r2, r3
	subs r6, r1, r0
	b _080DAEB6
	.align 2, 0
_080DAEAC: .4byte 0x03002BE0
_080DAEB0: .4byte 0xFFFFFF00
_080DAEB4:
	subs r6, r1, r2
_080DAEB6:
	adds r0, r4, #0
	adds r0, #0x4a
	ldrh r1, [r0]
	adds r5, r4, #0
	adds r5, #0x40
	mov r8, r0
	cmp r1, r6
	beq _080DAED6
	movs r0, #4
	ands r0, r6
	cmp r0, #0
	beq _080DAED6
	ldrh r1, [r5]
	movs r0, #4
	orrs r0, r1
	strh r0, [r5]
_080DAED6:
	ldrb r0, [r7, #4]
	cmp r0, #0
	bne _080DAEE4
	adds r0, r7, #0
	movs r1, #0
	bl FUN_0822a340
_080DAEE4:
	ldrh r1, [r5]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080DAF14
	adds r1, r4, #0
	adds r1, #0x44
	movs r0, #0x3c
	strh r0, [r1]
	mov r0, sb
	adds r1, r4, #0
	bl FUN_080dac24
	adds r0, r4, #0
	adds r0, #0x1c
	bl FUN_0807a524
	mov r0, r8
	strh r6, [r0]
	ldrh r1, [r5]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strh r0, [r5]
_080DAF14:
	cmp r6, #9
	bgt _080DAF24
	ldrh r1, [r5]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080DAF24
	b _080DB020
_080DAF24:
	movs r0, #0
	strh r0, [r4, #0x3c]
	movs r0, #2
	strh r0, [r4, #0x3e]
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	ldrh r1, [r5]
	movs r0, #0x13
	rsbs r0, r0, #0
	b _080DB01A
_080DAF3E:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080DAF88
	ldrb r0, [r4, #4]
	cmp r0, #0
	bne _080DAF54
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0822a340
_080DAF54:
	ldrh r1, [r5]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080DAF70
	mov r0, sb
	adds r1, r4, #0
	bl FUN_080dac24
	ldrh r1, [r5]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strh r0, [r5]
_080DAF70:
	ldrh r1, [r5]
	movs r2, #2
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080DB020
	strh r6, [r4, #0x3c]
	strh r2, [r4, #0x3e]
	ldrh r1, [r5]
	movs r0, #3
	rsbs r0, r0, #0
	b _080DB01A
_080DAF88:
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, _080DAF9C @ =0x03002BE0
	ldr r0, [r0]
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _080DAFA0
	movs r0, #1
	b _080DAFA2
	.align 2, 0
_080DAF9C: .4byte 0x03002BE0
_080DAFA0:
	movs r0, #0
_080DAFA2:
	adds r5, r4, #0
	adds r5, #0x40
	cmp r0, #0
	bne _080DAFD0
	ldrh r1, [r5]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080DAFC4
	ldr r0, _080DAFE0 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080DAFE4 @ =0x00000942
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bgt _080DAFD0
_080DAFC4:
	adds r0, r4, #0
	bl FUN_080dad94
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080DAFE8
_080DAFD0:
	ldrb r0, [r7, #4]
	cmp r0, #0
	bne _080DAFF6
	adds r0, r7, #0
	movs r1, #0
	bl FUN_0822a340
	b _080DAFF6
	.align 2, 0
_080DAFE0: .4byte 0x030046A0
_080DAFE4: .4byte 0x00000942
_080DAFE8:
	ldrb r0, [r7, #4]
	cmp r0, #0
	beq _080DAFF6
	adds r0, r7, #0
	movs r1, #0
	bl FUN_0822a36c
_080DAFF6:
	ldrh r1, [r5]
	movs r6, #2
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _080DB020
	ldrb r0, [r7, #4]
	cmp r0, #0
	bne _080DB010
	adds r0, r7, #0
	movs r1, #0
	bl FUN_0822a340
_080DB010:
	movs r0, #0
	strh r0, [r4, #0x3c]
	strh r6, [r4, #0x3e]
	ldrh r1, [r5]
	subs r0, #3
_080DB01A:
	ands r0, r1
	strh r0, [r5]
	b _080DB034
_080DB020:
	adds r0, r4, #0
	adds r0, #0x40
	ldrh r1, [r0]
	movs r0, #0x50
	ands r0, r1
	cmp r0, #0
	bne _080DB034
	adds r0, r4, #0
	bl FUN_080db0f8
_080DB034:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080db040
FUN_080db040: @ 0x080DB040
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r7, r5, #0
	ldrb r0, [r5, #4]
	cmp r0, #0
	bne _080DB056
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0822a340
_080DB056:
	movs r1, #0x3c
	ldrsh r0, [r5, r1]
	cmp r0, #0x12
	bne _080DB06C
	adds r2, r5, #0
	adds r2, #0x40
	ldrh r1, [r2]
	movs r0, #0x51
	rsbs r0, r0, #0
	ands r0, r1
	strh r0, [r2]
_080DB06C:
	movs r2, #0x3c
	ldrsh r0, [r5, r2]
	movs r2, #2
	cmp r0, #0x3c
	bgt _080DB07E
	movs r2, #0
	cmp r0, #0x28
	ble _080DB07E
	movs r2, #1
_080DB07E:
	movs r1, #0x3c
	ldrsh r0, [r5, r1]
	ldr r1, _080DB0A4 @ =0x085AD310
	adds r1, r2, r1
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _080DB0AC
	ldr r1, [r7]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _080DB0A8
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	b _080DB0AA
	.align 2, 0
_080DB0A4: .4byte 0x085AD310
_080DB0A8:
	orrs r1, r2
_080DB0AA:
	str r1, [r7]
_080DB0AC:
	ldrh r1, [r5, #0x3c]
	movs r2, #0x3c
	ldrsh r0, [r5, r2]
	cmp r0, #0x5a
	ble _080DB0EC
	adds r6, r5, #0
	adds r6, #0x42
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r4, #0x38]
	bics r0, r1
	str r0, [r4, #0x38]
	movs r4, #0
	strh r4, [r5, #0x3e]
	adds r0, r5, #0
	adds r0, #0x4c
	bl FUN_08236424
	adds r0, r7, #0
	movs r1, #0
	bl FUN_0822a36c
	ldr r0, _080DB0E8 @ =0x0000FFFF
	strh r0, [r6]
	adds r0, r5, #0
	adds r0, #0x40
	strh r4, [r0]
	b _080DB0F0
	.align 2, 0
_080DB0E8: .4byte 0x0000FFFF
_080DB0EC:
	adds r0, r1, #1
	strh r0, [r5, #0x3c]
_080DB0F0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080db0f8
FUN_080db0f8: @ 0x080DB0F8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r0, _080DB174 @ =0x03002BE0
	mov sb, r0
	ldr r5, [r0]
	cmp r5, #0
	bne _080DB110
	b _080DB24C
_080DB110:
	add r2, sp, #4
	adds r3, r6, #0
	adds r3, #0x9c
	adds r4, r5, #0
	adds r4, #0x2c
	ldrh r1, [r5, #0x2c]
	ldrh r0, [r3]
	subs r1, r1, r0
	mov ip, r1
	mov r1, ip
	strh r1, [r2]
	ldrh r0, [r4, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r4, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r2, #4]
	movs r4, #2
	ldrsh r0, [r2, r4]
	adds r7, r2, #0
	mov r8, r3
	cmp r0, #0
	bge _080DB144
	rsbs r0, r0, #0
_080DB144:
	cmp r0, #0x1f
	bgt _080DB1CA
	mov r0, ip
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe0
	bhi _080DB1CA
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0xa0
	bgt _080DB1CA
	movs r0, #0x3a
	rsbs r0, r0, #0
	cmp r1, r0
	blt _080DB1CA
	ldr r0, _080DB178 @ =0x000003FF
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _080DB17C
	movs r0, #0
	b _080DB1C6
	.align 2, 0
_080DB174: .4byte 0x03002BE0
_080DB178: .4byte 0x000003FF
_080DB17C:
	adds r0, r6, #0
	adds r0, #0x42
	movs r1, #0
	ldrsh r0, [r0, r1]
	strb r0, [r4]
	adds r2, r6, #0
	adds r2, #0x40
	ldrh r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r2]
	adds r2, #0x12
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
	mov r2, sb
	ldr r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #3
	adds r0, r0, r4
	ldrb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x48
	strh r1, [r0]
	movs r1, #6
	mov r0, sp
	strh r1, [r0]
	movs r0, #2
	movs r1, #1
	mov r2, sp
	bl FUN_080ec7e8
	ldr r0, _080DB25C @ =0x00000115
	bl PlaySound_082406e0
	movs r0, #1
_080DB1C6:
	cmp r0, #0
	bne _080DB24C
_080DB1CA:
	adds r0, r7, #0
	bl FUN_08086a28
	cmp r0, #0
	beq _080DB24C
	bl FUN_08086850
	cmp r0, #0
	beq _080DB24C
	ldrh r0, [r7]
	mov r2, r8
	ldrh r1, [r2]
	subs r0, r0, r1
	add r1, sp, #4
	strh r0, [r1]
	ldrh r0, [r7, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldrh r1, [r7, #4]
	ldrh r0, [r2, #4]
	subs r1, r1, r0
	strh r1, [r7, #4]
	movs r4, #2
	ldrsh r0, [r7, r4]
	cmp r0, #0
	bge _080DB202
	rsbs r0, r0, #0
_080DB202:
	cmp r0, #0x1f
	bgt _080DB24C
	ldrh r0, [r7]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe0
	bhi _080DB24C
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0xa0
	bgt _080DB24C
	movs r0, #0x3a
	rsbs r0, r0, #0
	cmp r1, r0
	blt _080DB24C
	bl FUN_08086878
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bge _080DB24C
	adds r0, r6, #0
	adds r0, #0x42
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl FUN_0808689c
	adds r2, r6, #0
	adds r2, #0x40
	ldrh r0, [r2]
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _080DB25C @ =0x00000115
	bl PlaySound_082406e0
_080DB24C:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DB25C: .4byte 0x00000115

	thumb_func_start FUN_080db260
FUN_080db260: @ 0x080DB260
	push {lr}
	adds r3, r1, #0
	ldrb r0, [r0, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	bls _080DB284
	movs r0, #1
	strb r0, [r2]
	movs r0, #3
	subs r0, r0, r1
	strb r0, [r3]
	b _080DB28A
_080DB284:
	movs r0, #0
	strb r0, [r2]
	strb r1, [r3]
_080DB28A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080db290
FUN_080db290: @ 0x080DB290
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	mov sb, r1
	bl FUN_080dad4c
	adds r7, r0, #0
	cmp r7, #0
	bne _080DB2B0
	movs r0, #1
	rsbs r0, r0, #0
	b _080DB42C
_080DB2B0:
	movs r5, #0
	movs r0, #1
	strh r0, [r7, #0x3e]
	movs r1, #5
	add r1, sp
	mov r8, r1
	mov r0, sb
	add r1, sp, #4
	mov r2, r8
	bl FUN_080db260
	adds r4, r7, #0
	adds r4, #0x9c
	mov r2, sb
	ldr r0, [r2, #8]
	ldr r1, [r2, #0xc]
	str r0, [r4]
	str r1, [r4, #4]
	adds r0, r4, #0
	bl FUN_08241574
	movs r1, #0x46
	adds r1, r1, r7
	mov sl, r1
	strh r0, [r1]
	movs r2, #0x40
	adds r2, r2, r7
	mov sb, r2
	strh r5, [r2]
	adds r0, r7, #0
	adds r0, #0x48
	strh r5, [r0]
	str r7, [sp, #8]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	adds r1, r6, #0
	adds r1, #0x18
	adds r0, r7, #0
	movs r2, #0
	bl FUN_0822a4b0
	subs r4, #0x70
	ldr r1, [r6, #0x34]
	mov r2, r8
	ldrb r0, [r2]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	mov r8, sl
	mov r6, sb
	cmp r2, r0
	beq _080DB34A
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080DB352
_080DB34A:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080DB352:
	str r0, [r7]
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
	beq _080DB378
	ldr r2, [sp, #8]
	ldr r0, [r2]
	movs r1, #8
	orrs r0, r1
	b _080DB384
_080DB378:
	ldr r1, [sp, #8]
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	ldr r2, [sp, #8]
_080DB384:
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080DB3BC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080DB3F4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DB3C0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DB3B4
	ldrb r0, [r4, #5]
_080DB3B4:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DB3D0
	.align 2, 0
_080DB3BC: .4byte 0x0000FFFF
_080DB3C0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080DB3D0
	strh r1, [r4, #8]
_080DB3D0:
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
	bne _080DB3F4
	movs r0, #1
	strb r0, [r4, #7]
_080DB3F4:
	ldr r1, [sp, #8]
	ldr r0, [r1]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	ldr r2, [sp, #8]
	str r0, [r2]
	movs r0, #1
	strb r0, [r2, #7]
	mov r1, r8
	ldrh r0, [r1]
	bl FUN_0809dfec
	cmp r0, #0
	beq _080DB41A
	ldrh r1, [r6]
	movs r0, #0x20
	orrs r0, r1
	strh r0, [r6]
_080DB41A:
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080dacc4
	adds r0, r7, #0
	adds r0, #0x42
	movs r2, #0
	ldrsh r0, [r0, r2]
_080DB42C:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080db43c
FUN_080db43c: @ 0x080DB43C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x3c
	ldr r0, [r4, #0x38]
	cmp r0, #0
	beq _080DB48E
	movs r5, #0
	ldr r7, _080DB460 @ =0x085AD314
_080DB44E:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080DB464
	movs r0, #1
	b _080DB466
	.align 2, 0
_080DB460: .4byte 0x085AD314
_080DB464:
	movs r0, #0
_080DB466:
	cmp r0, #0
	beq _080DB482
	movs r0, #0xa4
	adds r1, r5, #0
	muls r1, r0, r1
	adds r1, r1, r6
	movs r2, #0x3e
	ldrsh r0, [r1, r2]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r4, #0
	bl _call_via_r2
_080DB482:
	adds r5, #1
	cmp r5, #7
	ble _080DB44E
	adds r0, r4, #0
	bl FUN_080dadec
_080DB48E:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080db498
FUN_080db498: @ 0x080DB498
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
_080DB49E:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080DB4AE
	movs r0, #1
	b _080DB4B0
_080DB4AE:
	movs r0, #0
_080DB4B0:
	cmp r0, #0
	beq _080DB4D0
	movs r0, #0xa4
	muls r0, r5, r0
	adds r0, #0x3c
	adds r4, r6, r0
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _080DB4C8
	adds r0, r4, #0
	bl FUN_0822a4e0
_080DB4C8:
	adds r0, r4, #0
	adds r0, #0x4c
	bl FUN_08236424
_080DB4D0:
	adds r5, #1
	cmp r5, #7
	ble _080DB49E
	ldr r1, _080DB4E4 @ =0x03000160
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080DB4E4: .4byte 0x03000160

	thumb_func_start FUN_080db4e8
FUN_080db4e8: @ 0x080DB4E8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	ldr r1, _080DB510 @ =0x00001C1B
	bl FUN_0822b16c
	movs r0, #0
	str r0, [r4, #0x38]
	ldr r0, _080DB514 @ =0x0000922E
	ldr r1, _080DB518 @ =0x00003DC2
	bl GetFile
	str r0, [r4, #0x34]
	ldr r0, _080DB51C @ =0x03000160
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080DB510: .4byte 0x00001C1B
_080DB514: .4byte 0x0000922E
_080DB518: .4byte 0x00003DC2
_080DB51C: .4byte 0x03000160

	thumb_func_start FUN_080db520
FUN_080db520: @ 0x080DB520
	push {r4, lr}
	ldr r0, _080DB554 @ =0x03000160
	ldr r0, [r0]
	cmp r0, #0
	bne _080DB566
	ldr r1, _080DB558 @ =0x0000055C
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080DB564
	ldr r1, _080DB55C @ =FUN_080db43c
	ldr r2, _080DB560 @ =FUN_080db498
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080db4e8
	cmp r0, #0
	bge _080DB564
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080DB566
	.align 2, 0
_080DB554: .4byte 0x03000160
_080DB558: .4byte 0x0000055C
_080DB55C: .4byte FUN_080db43c
_080DB560: .4byte FUN_080db498
_080DB564:
	adds r0, r4, #0
_080DB566:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080db56c
FUN_080db56c: @ 0x080DB56C
	ldr r1, _080DB574 @ =0x03000160
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080DB574: .4byte 0x03000160

	thumb_func_start FUN_080db578
FUN_080db578: @ 0x080DB578
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _080DB5C4 @ =0x03000160
	ldr r6, [r0]
	cmp r6, #0
	bne _080DB598
	bl FUN_080db520
	adds r6, r0, #0
	cmp r6, #0
	bne _080DB598
	b _080DB770
_080DB598:
	adds r0, r6, #0
	bl FUN_080dad4c
	adds r7, r0, #0
	cmp r7, #0
	bne _080DB5A6
	b _080DB770
_080DB5A6:
	movs r0, #1
	strh r0, [r7, #0x3e]
	movs r0, #0x70
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _080DB602
	bl VM_GetPC
	cmp r0, #0
	beq _080DB5C8
	bl Script_GetValue
	b _080DB5CA
	.align 2, 0
_080DB5C4: .4byte 0x03000160
_080DB5C8:
	movs r0, #0
_080DB5CA:
	adds r4, r7, #0
	adds r4, #0x9c
	strh r0, [r4]
	bl VM_GetPC
	adds r5, r4, #0
	cmp r0, #0
	beq _080DB5E0
	bl Script_GetValue
	b _080DB5E2
_080DB5E0:
	movs r0, #0
_080DB5E2:
	adds r1, r7, #0
	adds r1, #0x9e
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _080DB5F8
	bl Script_GetValue
	adds r1, r0, #0
	b _080DB5FA
_080DB5F8:
	movs r1, #0
_080DB5FA:
	adds r0, r7, #0
	adds r0, #0xa0
	strh r1, [r0]
	b _080DB614
_080DB602:
	adds r1, r7, #0
	adds r1, #0x9c
	strh r2, [r1]
	adds r0, r7, #0
	adds r0, #0x9e
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r5, r1, #0
_080DB614:
	movs r0, #0x72
	movs r1, #0
	bl Script_GetKeywordValue
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r5, #0
	bl FUN_08241574
	movs r1, #0x46
	adds r1, r1, r7
	mov r8, r1
	movs r1, #0
	mov r2, r8
	strh r0, [r2]
	movs r0, #0x40
	adds r0, r0, r7
	mov sl, r0
	strh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x48
	strh r1, [r0]
	mov sb, r7
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	adds r1, r6, #0
	adds r1, #0x18
	adds r0, r7, #0
	movs r2, #0
	bl FUN_0822a4b0
	adds r5, r7, #0
	adds r5, #0x2c
	ldr r1, [r6, #0x34]
	str r4, [sp]
	adds r0, r5, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x2c]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r5, #4]
	movs r3, #1
	adds r2, r3, #0
	ands r2, r0
	ldrh r1, [r4]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	ands r0, r3
	mov r6, sl
	cmp r2, r0
	beq _080DB698
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080DB6A0
_080DB698:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080DB6A0:
	str r0, [r7]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080DB6C6
	mov r1, sb
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _080DB6D0
_080DB6C6:
	mov r1, sb
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080DB6D0:
	mov r2, sb
	str r0, [r2]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _080DB708 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _080DB740
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DB70C
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _080DB702
	ldrb r0, [r5, #5]
_080DB702:
	subs r0, #1
	strh r0, [r5, #8]
	b _080DB71C
	.align 2, 0
_080DB708: .4byte 0x0000FFFF
_080DB70C:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _080DB71C
	strh r1, [r5, #8]
_080DB71C:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080DB740
	movs r0, #1
	strb r0, [r5, #7]
_080DB740:
	mov r1, sb
	ldr r0, [r1]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	movs r0, #1
	strb r0, [r2, #7]
	mov r1, r8
	ldrh r0, [r1]
	bl FUN_0809dfec
	cmp r0, #0
	beq _080DB766
	ldrh r1, [r6]
	movs r0, #0x20
	orrs r0, r1
	strh r0, [r6]
_080DB766:
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080dacc4
_080DB770:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080db780
FUN_080db780: @ 0x080DB780
	push {r4, r5, r6, lr}
	ldr r0, _080DB79C @ =0x03000160
	ldr r5, [r0]
	cmp r5, #0
	beq _080DB7DE
	movs r4, #0
_080DB78C:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080DB7A0
	movs r0, #1
	b _080DB7A2
	.align 2, 0
_080DB79C: .4byte 0x03000160
_080DB7A0:
	movs r0, #0
_080DB7A2:
	cmp r0, #0
	beq _080DB7D8
	movs r0, #0xa4
	muls r0, r4, r0
	adds r0, #0x3c
	adds r3, r5, r0
	adds r0, r3, #0
	adds r0, #0x42
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080DB7D8
	movs r1, #0x3e
	ldrsh r0, [r3, r1]
	cmp r0, #2
	beq _080DB7D8
	adds r2, r3, #0
	adds r2, #0x40
	ldrh r0, [r2]
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
	adds r2, #0x12
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
_080DB7D8:
	adds r4, #1
	cmp r4, #7
	ble _080DB78C
_080DB7DE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080db7e4
FUN_080db7e4: @ 0x080DB7E4
	bx lr
	.align 2, 0

	thumb_func_start FUN_080db7e8
FUN_080db7e8: @ 0x080DB7E8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #0x13
	ldrsb r0, [r5, r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, #0x20
	adds r6, r4, r1
	ldrh r1, [r5, #0x16]
	movs r2, #0x16
	ldrsh r0, [r5, r2]
	cmp r0, #0
	ble _080DB80C
	subs r0, r1, #1
	strh r0, [r5, #0x16]
	b _080DB968
_080DB80C:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	ldrh r0, [r5, #8]
	ldrh r1, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r5, #0xa]
	ldrh r2, [r5, #2]
	adds r0, r0, r2
	strh r0, [r5, #2]
	ldrh r0, [r5, #0xc]
	ldrh r1, [r5, #4]
	adds r0, r0, r1
	strh r0, [r5, #4]
	movs r2, #8
	ldrsh r1, [r5, r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	strh r0, [r5, #8]
	movs r0, #0xa
	ldrsh r1, [r5, r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	strh r0, [r5, #0xa]
	movs r2, #0xc
	ldrsh r1, [r5, r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	strh r0, [r5, #0xc]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
	movs r0, #0x13
	ldrsb r0, [r5, r0]
	ldr r3, [r4, #0x1c]
	lsls r0, r0, #4
	adds r4, r0, r4
	movs r0, #0xa4
	lsls r0, r0, #3
	adds r4, r4, r0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r2, [r7]
	lsrs r2, r2, #6
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r6, #8]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080DB8B2
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _080DB8BA
_080DB8B2:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080DB8BA:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080DB8DE
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _080DB8E6
_080DB8DE:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080DB8E6:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080DB920 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080DB958
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DB92A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DB924
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080DB940
	.align 2, 0
_080DB920: .4byte 0x0000FFFF
_080DB924:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DB93E
_080DB92A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080DB93E
	strh r1, [r4, #8]
	movs r2, #1
	b _080DB940
_080DB93E:
	movs r2, #0
_080DB940:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	b _080DB95A
_080DB958:
	movs r2, #0
_080DB95A:
	cmp r2, #0
	beq _080DB962
	movs r0, #2
	strb r0, [r5, #0x12]
_080DB962:
	ldrh r0, [r5, #0x14]
	adds r0, #1
	strh r0, [r5, #0x14]
_080DB968:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080db970
FUN_080db970: @ 0x080DB970
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0x13
	ldrsb r1, [r5, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	adds r0, r4, r0
	bl FUN_0822dabc
	movs r0, #0
	strb r0, [r5, #0x12]
	movs r0, #0x13
	ldrsb r0, [r5, r0]
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r4, r4, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r4]
	bics r0, r1
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0x18
	bl ClearMemory
	movs r0, #0xff
	strb r0, [r5, #0x13]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080db9b4
FUN_080db9b4: @ 0x080DB9B4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r3, #0
	movs r0, #0xe4
	lsls r0, r0, #3
	adds r4, r5, r0
	movs r6, #1
	movs r2, #0
_080DB9C4:
	adds r1, r6, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080DB9D4
	movs r0, #1
	b _080DB9D6
_080DB9D4:
	movs r0, #0
_080DB9D6:
	cmp r0, #0
	bne _080DB9F0
	movs r1, #0xe5
	lsls r1, r1, #3
	adds r0, r2, r1
	adds r0, r5, r0
	strb r3, [r0, #0x13]
	adds r2, r6, #0
	lsls r2, r3
	ldr r1, [r4]
	orrs r1, r2
	str r1, [r4]
	b _080DB9FA
_080DB9F0:
	adds r2, #0x18
	adds r3, #1
	cmp r3, #0x1f
	ble _080DB9C4
	movs r0, #0
_080DB9FA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080dba00
FUN_080dba00: @ 0x080DBA00
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	str r0, [sp, #4]
	mov r8, r1
	mov sb, r2
	str r3, [sp, #8]
	cmp r0, #0
	beq _080DBA30
	ldr r0, _080DBA38 @ =0x03000164
	ldr r0, [r0]
	mov sl, r0
	cmp r0, #0
	bne _080DBA3C
	movs r0, #0
	movs r1, #0
	bl FUN_080dbe54
	mov sl, r0
	cmp r0, #0
	bne _080DBA3C
_080DBA30:
	movs r0, #1
	rsbs r0, r0, #0
	b _080DBCCE
	.align 2, 0
_080DBA38: .4byte 0x03000164
_080DBA3C:
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r1, [sp, #8]
	cmp r0, r1
	blt _080DBA48
	b _080DBCCC
_080DBA48:
	ldr r7, _080DBB1C @ =0x030046B8
_080DBA4A:
	mov r0, sl
	bl FUN_080db9b4
	adds r6, r0, #0
	cmp r6, #0
	beq _080DBA30
	movs r1, #0x13
	ldrsb r1, [r6, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	add r0, sl
	str r0, [sp, #0xc]
	ldr r2, [sp, #4]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6]
	str r1, [r6, #4]
	mov r3, sb
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	beq _080DBAA4
	ldr r0, [r7]
	adds r0, #1
	ldr r2, _080DBB20 @ =0x000003FF
	ands r0, r2
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _080DBB24 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r2, sb
	movs r3, #0
	ldrsh r1, [r2, r3]
	lsls r1, r1, #1
	bl Mod
	mov r2, sb
	ldrh r1, [r2]
	subs r0, r0, r1
	ldrh r3, [r6]
	adds r0, r0, r3
	strh r0, [r6]
_080DBAA4:
	mov r1, sb
	movs r2, #2
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _080DBAD8
	ldr r0, [r7]
	adds r0, #1
	ldr r3, _080DBB20 @ =0x000003FF
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080DBB24 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r2, sb
	movs r3, #2
	ldrsh r1, [r2, r3]
	lsls r1, r1, #1
	bl Mod
	mov r2, sb
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	ldrh r3, [r6, #2]
	adds r0, r0, r3
	strh r0, [r6, #2]
_080DBAD8:
	mov r1, sb
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _080DBB0C
	ldr r0, [r7]
	adds r0, #1
	ldr r3, _080DBB20 @ =0x000003FF
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080DBB24 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r2, sb
	movs r3, #4
	ldrsh r1, [r2, r3]
	lsls r1, r1, #1
	bl Mod
	mov r2, sb
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	ldrh r3, [r6, #4]
	adds r0, r0, r3
	strh r0, [r6, #4]
_080DBB0C:
	mov r0, r8
	cmp r0, #0
	bne _080DBB28
	strh r0, [r6, #8]
	mov r1, r8
	strh r1, [r6, #0xa]
	strh r1, [r6, #0xc]
	b _080DBBF8
	.align 2, 0
_080DBB1C: .4byte 0x030046B8
_080DBB20: .4byte 0x000003FF
_080DBB24: .4byte 0x0203B400
_080DBB28:
	mov r2, r8
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0
	bne _080DBB3C
	ldr r0, _080DBB38 @ =0xFFFF0000
	ands r4, r0
	b _080DBB64
	.align 2, 0
_080DBB38: .4byte 0xFFFF0000
_080DBB3C:
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080DBB74 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _080DBB78 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r3, r8
	movs r2, #0
	ldrsh r1, [r3, r2]
	bl Mod
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080DBB7C @ =0xFFFF0000
	ands r1, r4
	adds r4, r1, #0
	orrs r4, r0
_080DBB64:
	mov r3, r8
	movs r1, #2
	ldrsh r0, [r3, r1]
	cmp r0, #0
	bne _080DBB84
	ldr r0, _080DBB80 @ =0x0000FFFF
	ands r4, r0
	b _080DBBAA
	.align 2, 0
_080DBB74: .4byte 0x000003FF
_080DBB78: .4byte 0x0203B400
_080DBB7C: .4byte 0xFFFF0000
_080DBB80: .4byte 0x0000FFFF
_080DBB84:
	ldr r0, [r7]
	adds r0, #1
	ldr r2, _080DBBBC @ =0x000003FF
	ands r0, r2
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _080DBBC0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r2, r8
	movs r3, #2
	ldrsh r1, [r2, r3]
	bl Mod
	lsls r0, r0, #0x10
	ldr r1, _080DBBC4 @ =0x0000FFFF
	ands r1, r4
	adds r4, r1, #0
	orrs r4, r0
_080DBBAA:
	mov r1, r8
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne _080DBBCC
	ldr r3, _080DBBC8 @ =0xFFFF0000
	ands r5, r3
	b _080DBBF4
	.align 2, 0
_080DBBBC: .4byte 0x000003FF
_080DBBC0: .4byte 0x0203B400
_080DBBC4: .4byte 0x0000FFFF
_080DBBC8: .4byte 0xFFFF0000
_080DBBCC:
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080DBC40 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _080DBC44 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r3, r8
	movs r2, #4
	ldrsh r1, [r3, r2]
	bl Mod
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080DBC48 @ =0xFFFF0000
	ands r1, r5
	adds r5, r1, #0
	orrs r5, r0
_080DBBF4:
	str r4, [r6, #8]
	str r5, [r6, #0xc]
_080DBBF8:
	ldr r0, [r7]
	adds r0, #1
	ldr r3, _080DBC40 @ =0x000003FF
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080DBC44 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x10
	bl Mod
	strh r0, [r6, #0x16]
	mov r2, sl
	ldr r1, [r2, #0x1c]
	ldr r0, [sp, #0xc]
	movs r2, #0
	bl FUN_0822d9f0
	movs r2, #8
	rsbs r2, r2, #0
	ldr r0, [sp, #0xc]
	adds r1, r2, #0
	bl FUN_0822dad4
	movs r1, #8
	ldr r0, _080DBC4C @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _080DBC50 @ =0x00000934
	adds r0, r0, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080DBC54
	movs r0, #1
	b _080DBC56
	.align 2, 0
_080DBC40: .4byte 0x000003FF
_080DBC44: .4byte 0x0203B400
_080DBC48: .4byte 0xFFFF0000
_080DBC4C: .4byte 0x030046A0
_080DBC50: .4byte 0x00000934
_080DBC54:
	movs r0, #0
_080DBC56:
	movs r2, #0xd
	cmp r0, #0
	beq _080DBC5E
	movs r2, #0xe
_080DBC5E:
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080DBCE0 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _080DBCE4 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #2
	str r2, [sp, #0x14]
	bl Mod
	adds r3, r0, #0
	ldr r0, [sp, #0x3c]
	orrs r3, r0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov ip, r3
	movs r0, #0x13
	ldrsb r0, [r6, r0]
	lsls r0, r0, #4
	movs r1, #0xa4
	lsls r1, r1, #3
	adds r0, r0, r1
	add r0, sl
	mov r3, sl
	ldr r1, [r3, #0x18]
	ldr r2, [sp, #0x14]
	mov r3, ip
	str r3, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldr r1, [sp, #0xc]
	ldr r0, [r1]
	ldr r1, _080DBCE8 @ =0x00000201
	orrs r0, r1
	ldr r2, [sp, #0xc]
	str r0, [r2]
	add r3, sp, #0x38
	ldrb r3, [r3]
	strb r3, [r2, #0xf]
	movs r0, #1
	strb r0, [r6, #0x12]
	add r0, sp, #0x40
	ldrh r0, [r0]
	strh r0, [r6, #0x10]
	ldr r1, [sp, #0x10]
	adds r1, #1
	str r1, [sp, #0x10]
	ldr r2, [sp, #8]
	cmp r1, r2
	bge _080DBCCC
	b _080DBA4A
_080DBCCC:
	movs r0, #0
_080DBCCE:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DBCE0: .4byte 0x000003FF
_080DBCE4: .4byte 0x0203B400
_080DBCE8: .4byte 0x00000201

	thumb_func_start FUN_080dbcec
FUN_080dbcec: @ 0x080DBCEC
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r4, [sp, #0x18]
	ldr r5, [sp, #0x1c]
	str r4, [sp]
	str r5, [sp, #4]
	movs r4, #1
	str r4, [sp, #8]
	bl FUN_080dba00
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080dbd08
FUN_080dbd08: @ 0x080DBD08
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r4, [sp, #0x18]
	ldr r5, [sp, #0x1c]
	str r4, [sp]
	str r5, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	bl FUN_080dba00
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080dbd24
FUN_080dbd24: @ 0x080DBD24
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080DBDA8
	movs r5, #0
	movs r7, #0x80
	lsls r7, r7, #2
	movs r0, #0xe5
	lsls r0, r0, #3
	adds r4, r6, r0
_080DBD40:
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r1, #1
	lsls r1, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080DBD56
	movs r0, #1
	b _080DBD58
_080DBD56:
	movs r0, #0
_080DBD58:
	cmp r0, #0
	beq _080DBDA0
	adds r3, r4, #0
	ldr r0, _080DBDB0 @ =0x030047A4
	ldr r1, _080DBDB4 @ =0x030047A0
	ldr r2, [r0]
	ldr r0, [r1]
	orrs r0, r2
	ands r0, r7
	cmp r0, #0
	bne _080DBD84
	movs r0, #0x80
	lsls r0, r0, #4
	ands r2, r0
	cmp r2, #0
	beq _080DBD8E
	ldr r0, _080DBDB8 @ =0x030044BC
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080DBD8E
_080DBD84:
	ldrh r1, [r4, #0x10]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080DBDA0
_080DBD8E:
	ldr r0, _080DBDBC @ =0x085AD320
	ldrb r1, [r3, #0x12]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r2, [r1]
	adds r0, r6, #0
	adds r1, r3, #0
	bl _call_via_r2
_080DBDA0:
	adds r4, #0x18
	adds r5, #1
	cmp r5, #0x1f
	ble _080DBD40
_080DBDA8:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DBDB0: .4byte 0x030047A4
_080DBDB4: .4byte 0x030047A0
_080DBDB8: .4byte 0x030044BC
_080DBDBC: .4byte 0x085AD320

	thumb_func_start FUN_080dbdc0
FUN_080dbdc0: @ 0x080DBDC0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r5, #0
	movs r0, #0xe4
	lsls r0, r0, #3
	adds r7, r6, r0
	adds r0, #8
	adds r4, r6, r0
_080DBDD0:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _080DBDE0
	movs r0, #1
	b _080DBDE2
_080DBDE0:
	movs r0, #0
_080DBDE2:
	cmp r0, #0
	beq _080DBDF8
	movs r1, #0x13
	ldrsb r1, [r4, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	adds r0, r6, r0
	bl FUN_0822dabc
_080DBDF8:
	adds r4, #0x18
	adds r5, #1
	cmp r5, #0x1f
	ble _080DBDD0
	movs r1, #0
	ldr r0, _080DBE10 @ =0x03000164
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DBE10: .4byte 0x03000164

	thumb_func_start FUN_080dbe14
FUN_080dbe14: @ 0x080DBE14
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080DBE30 @ =0x00001C1A
	bl GetParticleGroup
	str r0, [r4, #0x1c]
	ldr r0, _080DBE34 @ =0x0000922E
	ldr r1, _080DBE38 @ =0x0000D1B8
	bl GetFile
	str r0, [r4, #0x18]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DBE30: .4byte 0x00001C1A
_080DBE34: .4byte 0x0000922E
_080DBE38: .4byte 0x0000D1B8

	thumb_func_start FUN_080dbe3c
FUN_080dbe3c: @ 0x080DBE3C
	push {lr}
	ldr r3, _080DBE50 @ =0x00000724
	adds r2, r0, r3
	str r1, [r2]
	bl FUN_080dbe14
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080DBE50: .4byte 0x00000724

	thumb_func_start FUN_080dbe54
FUN_080dbe54: @ 0x080DBE54
	push {r4, r5, lr}
	ldr r5, _080DBE8C @ =0x03000164
	ldr r0, [r5]
	cmp r0, #0
	bne _080DBE9E
	ldr r1, _080DBE90 @ =0x00000A28
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	str r4, [r5]
	cmp r4, #0
	beq _080DBE9C
	ldr r1, _080DBE94 @ =FUN_080dbd24
	ldr r2, _080DBE98 @ =FUN_080dbdc0
	bl SetEntityRoutine
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080dbe3c
	cmp r0, #0
	bge _080DBE9C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080DBE9E
	.align 2, 0
_080DBE8C: .4byte 0x03000164
_080DBE90: .4byte 0x00000A28
_080DBE94: .4byte FUN_080dbd24
_080DBE98: .4byte FUN_080dbdc0
_080DBE9C:
	adds r0, r4, #0
_080DBE9E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080dbea4
FUN_080dbea4: @ 0x080DBEA4
	ldr r1, _080DBEAC @ =0x03000164
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080DBEAC: .4byte 0x03000164

	thumb_func_start FUN_080dbeb0
FUN_080dbeb0: @ 0x080DBEB0
	bx lr
	.align 2, 0

	thumb_func_start FUN_080dbeb4
FUN_080dbeb4: @ 0x080DBEB4
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	mov ip, r1
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, #0x20
	adds r5, r2, r1
	mov r0, ip
	ldrh r1, [r0, #0x1a]
	movs r3, #0x1a
	ldrsh r0, [r0, r3]
	cmp r0, #0
	ble _080DBEDC
	subs r0, r1, #1
	mov r4, ip
	strh r0, [r4, #0x1a]
	b _080DC004
_080DBEDC:
	ldr r6, [r5]
	movs r0, #2
	rsbs r0, r0, #0
	ands r6, r0
	str r6, [r5]
	mov r0, ip
	ldr r1, [r0]
	ldrh r0, [r0, #4]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r5, #0x18]
	mov r4, ip
	ldrh r0, [r4, #6]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r5, #0x1a]
	ldrh r0, [r4, #8]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	movs r0, #0x17
	ldrsb r0, [r4, r0]
	ldr r3, [r2, #0x1c]
	lsls r0, r0, #4
	adds r4, r0, r2
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r4, r4, r0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r2, [r7]
	lsrs r2, r2, #6
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r5, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r5, #8]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080DBF4E
	movs r0, #4
	orrs r6, r0
	b _080DBF54
_080DBF4E:
	movs r0, #5
	rsbs r0, r0, #0
	ands r6, r0
_080DBF54:
	str r6, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080DBF78
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080DBF80
_080DBF78:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080DBF80:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080DBFB8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _080DBFF0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DBFC2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DBFBC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080DBFD8
	.align 2, 0
_080DBFB8: .4byte 0x0000FFFF
_080DBFBC:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DBFD6
_080DBFC2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080DBFD6
	strh r1, [r4, #8]
	movs r2, #1
	b _080DBFD8
_080DBFD6:
	movs r2, #0
_080DBFD8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	b _080DBFF2
_080DBFF0:
	movs r2, #0
_080DBFF2:
	cmp r2, #0
	beq _080DBFFC
	movs r0, #2
	mov r3, ip
	strb r0, [r3, #0x16]
_080DBFFC:
	mov r4, ip
	ldrh r0, [r4, #0x18]
	adds r0, #1
	strh r0, [r4, #0x18]
_080DC004:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080dc00c
FUN_080dc00c: @ 0x080DC00C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0x17
	ldrsb r1, [r5, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	adds r0, r4, r0
	bl FUN_0822dabc
	movs r0, #0
	strb r0, [r5, #0x16]
	movs r0, #0x17
	ldrsb r0, [r5, r0]
	movs r1, #0xf0
	lsls r1, r1, #1
	adds r4, r4, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r4]
	bics r0, r1
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0x1c
	bl ClearMemory
	movs r0, #0xff
	strb r0, [r5, #0x17]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080dc050
FUN_080dc050: @ 0x080DC050
	push {r4, r5, lr}
	adds r2, r0, #0
	movs r3, #0
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r4, r2, r0
	movs r5, #1
	mov ip, r3
_080DC060:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080DC070
	movs r0, #1
	b _080DC072
_080DC070:
	movs r0, #0
_080DC072:
	cmp r0, #0
	bne _080DC08C
	movs r0, #0xf2
	lsls r0, r0, #1
	add r0, ip
	adds r0, r2, r0
	strb r3, [r0, #0x17]
	adds r2, r5, #0
	lsls r2, r3
	ldr r1, [r4]
	orrs r1, r2
	str r1, [r4]
	b _080DC098
_080DC08C:
	movs r0, #0x1c
	add ip, r0
	adds r3, #1
	cmp r3, #7
	ble _080DC060
	movs r0, #0
_080DC098:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080dc0a0
FUN_080dc0a0: @ 0x080DC0A0
	push {r4, r5, lr}
	sub sp, #8
	ldr r4, [sp, #0x14]
	ldr r5, [sp, #0x18]
	str r4, [sp]
	str r5, [sp, #4]
	bl FUN_080dc0d0
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080dc0b8
FUN_080dc0b8: @ 0x080DC0B8
	push {r4, lr}
	sub sp, #8
	ldr r4, [sp, #0x10]
	str r4, [sp]
	movs r4, #2
	str r4, [sp, #4]
	bl FUN_080dc0d0
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080dc0d0
FUN_080dc0d0: @ 0x080DC0D0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	str r0, [sp, #4]
	str r1, [sp, #8]
	mov sb, r2
	mov r8, r3
	cmp r0, #0
	beq _080DC0F2
	ldr r0, _080DC0F8 @ =0x03000168
	ldr r0, [r0]
	str r0, [sp, #0xc]
	cmp r0, #0
	bne _080DC0FC
_080DC0F2:
	movs r0, #1
	rsbs r0, r0, #0
	b _080DC340
	.align 2, 0
_080DC0F8: .4byte 0x03000168
_080DC0FC:
	movs r0, #0
	str r0, [sp, #0x14]
	ldr r1, [sp, #0x38]
	cmp r0, r1
	blt _080DC108
	b _080DC33E
_080DC108:
	ldr r2, _080DC144 @ =0x030046B8
	mov sl, r2
_080DC10C:
	ldr r0, [sp, #0xc]
	bl FUN_080dc050
	adds r7, r0, #0
	cmp r7, #0
	beq _080DC0F2
	movs r1, #0x17
	ldrsb r1, [r7, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	ldr r3, [sp, #0xc]
	adds r0, r3, r0
	str r0, [sp, #0x10]
	ldr r0, [sp, #4]
	str r0, [r7]
	ldr r1, [sp, #8]
	cmp r1, #0
	bne _080DC148
	strh r1, [r7, #4]
	mov r3, sp
	ldrh r3, [r3, #8]
	strh r3, [r7, #6]
	mov r0, sp
	ldrh r0, [r0, #8]
	strh r0, [r7, #8]
	b _080DC152
	.align 2, 0
_080DC144: .4byte 0x030046B8
_080DC148:
	ldr r2, [sp, #8]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #4]
	str r1, [r7, #8]
_080DC152:
	mov r3, r8
	cmp r3, #0
	beq _080DC1F8
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	beq _080DC18C
	mov r2, sl
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _080DC208 @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080DC20C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r2, r8
	movs r3, #0
	ldrsh r1, [r2, r3]
	lsls r1, r1, #1
	bl Mod
	mov r2, r8
	ldrh r1, [r2]
	subs r0, r0, r1
	ldrh r3, [r7, #4]
	adds r0, r0, r3
	strh r0, [r7, #4]
_080DC18C:
	mov r1, r8
	movs r2, #2
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _080DC1C2
	mov r3, sl
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080DC208 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _080DC20C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r3, r8
	movs r2, #2
	ldrsh r1, [r3, r2]
	lsls r1, r1, #1
	bl Mod
	mov r3, r8
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	ldrh r1, [r7, #6]
	adds r0, r0, r1
	strh r0, [r7, #6]
_080DC1C2:
	mov r2, r8
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmp r0, #0
	beq _080DC1F8
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _080DC208 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r3, _080DC20C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r2, r8
	movs r3, #4
	ldrsh r1, [r2, r3]
	lsls r1, r1, #1
	bl Mod
	mov r2, r8
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	ldrh r3, [r7, #8]
	adds r0, r0, r3
	strh r0, [r7, #8]
_080DC1F8:
	mov r0, sb
	cmp r0, #0
	bne _080DC210
	strh r0, [r7, #0xc]
	mov r1, sb
	strh r1, [r7, #0xe]
	strh r1, [r7, #0x10]
	b _080DC2E6
	.align 2, 0
_080DC208: .4byte 0x000003FF
_080DC20C: .4byte 0x0203B400
_080DC210:
	mov r2, sb
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0
	bne _080DC224
	ldr r0, _080DC220 @ =0xFFFF0000
	ands r5, r0
	b _080DC24E
	.align 2, 0
_080DC220: .4byte 0xFFFF0000
_080DC224:
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _080DC260 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r3, _080DC264 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r2, sb
	movs r3, #0
	ldrsh r1, [r2, r3]
	bl Mod
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080DC268 @ =0xFFFF0000
	ands r1, r5
	adds r5, r1, #0
	orrs r5, r0
_080DC24E:
	mov r1, sb
	movs r2, #2
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne _080DC270
	ldr r0, _080DC26C @ =0x0000FFFF
	ands r5, r0
	b _080DC298
	.align 2, 0
_080DC260: .4byte 0x000003FF
_080DC264: .4byte 0x0203B400
_080DC268: .4byte 0xFFFF0000
_080DC26C: .4byte 0x0000FFFF
_080DC270:
	mov r3, sl
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080DC2A8 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _080DC2AC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r3, sb
	movs r2, #2
	ldrsh r1, [r3, r2]
	bl Mod
	lsls r0, r0, #0x10
	ldr r1, _080DC2B0 @ =0x0000FFFF
	ands r1, r5
	adds r5, r1, #0
	orrs r5, r0
_080DC298:
	mov r3, sb
	movs r1, #4
	ldrsh r0, [r3, r1]
	cmp r0, #0
	bne _080DC2B8
	ldr r2, _080DC2B4 @ =0xFFFF0000
	ands r6, r2
	b _080DC2E2
	.align 2, 0
_080DC2A8: .4byte 0x000003FF
_080DC2AC: .4byte 0x0203B400
_080DC2B0: .4byte 0x0000FFFF
_080DC2B4: .4byte 0xFFFF0000
_080DC2B8:
	mov r3, sl
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080DC350 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _080DC354 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r3, sb
	movs r2, #4
	ldrsh r1, [r3, r2]
	bl Mod
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080DC358 @ =0xFFFF0000
	ands r1, r6
	adds r6, r1, #0
	orrs r6, r0
_080DC2E2:
	str r5, [r7, #0xc]
	str r6, [r7, #0x10]
_080DC2E6:
	movs r4, #0
	strh r4, [r7, #0x1a]
	ldr r3, [sp, #0xc]
	ldr r1, [r3, #0x1c]
	ldr r0, [sp, #0x10]
	movs r2, #0
	bl FUN_0822d9f0
	movs r2, #8
	rsbs r2, r2, #0
	ldr r0, [sp, #0x10]
	adds r1, r2, #0
	bl FUN_0822dad4
	movs r0, #0x17
	ldrsb r0, [r7, r0]
	lsls r0, r0, #4
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r2, [sp, #0xc]
	adds r0, r2, r0
	ldr r1, [r2, #0x18]
	str r4, [sp]
	movs r2, #0xc
	movs r3, #0
	bl FUN_08236fac
	ldr r3, [sp, #0x10]
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	add r0, sp, #0x3c
	ldrb r0, [r0]
	strb r0, [r3, #0xf]
	strb r1, [r7, #0x16]
	ldr r1, [sp, #0x14]
	adds r1, #1
	str r1, [sp, #0x14]
	ldr r2, [sp, #0x38]
	cmp r1, r2
	bge _080DC33E
	b _080DC10C
_080DC33E:
	movs r0, #0
_080DC340:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DC350: .4byte 0x000003FF
_080DC354: .4byte 0x0203B400
_080DC358: .4byte 0xFFFF0000

	thumb_func_start FUN_080dc35c
FUN_080dc35c: @ 0x080DC35C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r1, #0xf0
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080DC3B6
	movs r5, #0
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r7, r6, r0
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r4, r6, r1
	ldr r0, _080DC394 @ =0x085AD32C
	mov r8, r0
_080DC382:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _080DC398
	movs r0, #1
	b _080DC39A
	.align 2, 0
_080DC394: .4byte 0x085AD32C
_080DC398:
	movs r0, #0
_080DC39A:
	cmp r0, #0
	beq _080DC3AE
	ldrb r0, [r4, #0x16]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
_080DC3AE:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #7
	ble _080DC382
_080DC3B6:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080dc3c4
FUN_080dc3c4: @ 0x080DC3C4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r5, #0
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r7, r6, r0
	adds r0, #4
	adds r4, r6, r0
_080DC3D4:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _080DC3E4
	movs r0, #1
	b _080DC3E6
_080DC3E4:
	movs r0, #0
_080DC3E6:
	cmp r0, #0
	beq _080DC3FC
	movs r1, #0x17
	ldrsb r1, [r4, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	adds r0, r6, r0
	bl FUN_0822dabc
_080DC3FC:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #7
	ble _080DC3D4
	movs r1, #0
	ldr r0, _080DC414 @ =0x03000168
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DC414: .4byte 0x03000168

	thumb_func_start FUN_080dc418
FUN_080dc418: @ 0x080DC418
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080DC434 @ =0x00001C1A
	bl GetParticleGroup
	str r0, [r4, #0x1c]
	ldr r0, _080DC438 @ =0x0000922E
	ldr r1, _080DC43C @ =0x0000D1B8
	bl GetFile
	str r0, [r4, #0x18]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DC434: .4byte 0x00001C1A
_080DC438: .4byte 0x0000922E
_080DC43C: .4byte 0x0000D1B8

	thumb_func_start FUN_080dc440
FUN_080dc440: @ 0x080DC440
	push {lr}
	bl FUN_080dc418
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_080dc44c
FUN_080dc44c: @ 0x080DC44C
	push {r4, r5, lr}
	ldr r5, _080DC484 @ =0x03000168
	ldr r0, [r5]
	cmp r0, #0
	bne _080DC492
	movs r1, #0xb1
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	str r4, [r5]
	cmp r4, #0
	beq _080DC490
	ldr r1, _080DC488 @ =FUN_080dc35c
	ldr r2, _080DC48C @ =FUN_080dc3c4
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080dc440
	cmp r0, #0
	bge _080DC490
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080DC492
	.align 2, 0
_080DC484: .4byte 0x03000168
_080DC488: .4byte FUN_080dc35c
_080DC48C: .4byte FUN_080dc3c4
_080DC490:
	adds r0, r4, #0
_080DC492:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080dc498
FUN_080dc498: @ 0x080DC498
	ldr r1, _080DC4A0 @ =0x03000168
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080DC4A0: .4byte 0x03000168

	thumb_func_start FUN_080dc4a4
FUN_080dc4a4: @ 0x080DC4A4
	bx lr
	.align 2, 0

	thumb_func_start FUN_080dc4a8
FUN_080dc4a8: @ 0x080DC4A8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r2, #0
	mov r4, sp
	adds r3, r1, #0
	adds r3, #0xc
	adds r2, r0, #0
	adds r2, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r1, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #4
	ldrsh r1, [r4, r2]
	bl FUN_0823785c
	adds r3, r0, #0
	adds r0, #0x10
	movs r5, #0xff
	ands r0, r5
	asrs r0, r0, #5
	lsls r3, r0, #5
	ldrh r0, [r4, #2]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _080DC570
	add r2, sp, #8
	ldr r0, _080DC514 @ =0x085B0A08
	adds r1, r3, #0
	adds r1, #0x40
	ands r1, r5
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r4, #0
	ldrsh r1, [r1, r4]
	lsls r1, r1, #2
	adds r4, r2, #0
	adds r5, r0, #0
	cmp r1, #0
	blt _080DC518
	asrs r1, r1, #0xc
	b _080DC51E
	.align 2, 0
_080DC514: .4byte 0x085B0A08
_080DC518:
	rsbs r0, r1, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080DC51E:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #4
	muls r0, r1, r0
	cmp r0, #0
	blt _080DC53C
	asrs r0, r0, #0xc
	b _080DC542
_080DC53C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080DC542:
	strh r0, [r2, #4]
	ldr r0, _080DC56C @ =0x0000FFFC
	strh r0, [r4, #2]
	add r0, sp, #8
	ldrh r1, [r0]
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	ldrh r0, [r4, #2]
	movs r3, #0x8f
	lsls r3, r3, #1
	adds r1, r6, r3
	strh r0, [r1]
	ldrh r1, [r4, #4]
	movs r4, #0x90
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r1, [r0]
	b _080DC5F2
	.align 2, 0
_080DC56C: .4byte 0x0000FFFC
_080DC570:
	add r2, sp, #8
	movs r7, #0x12
	ldr r0, _080DC594 @ =0x085B0A08
	adds r1, r3, #0
	adds r1, #0x40
	ands r1, r5
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r4, #0
	ldrsh r1, [r1, r4]
	muls r1, r7, r1
	adds r4, r2, #0
	adds r5, r0, #0
	cmp r1, #0
	blt _080DC598
	asrs r1, r1, #0xc
	b _080DC59E
	.align 2, 0
_080DC594: .4byte 0x085B0A08
_080DC598:
	rsbs r0, r1, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080DC59E:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _080DC5BA
	asrs r0, r0, #0xc
	b _080DC5C0
_080DC5BA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080DC5C0:
	strh r0, [r2, #4]
	movs r0, #0x20
	strh r0, [r4, #2]
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r1, r6, r2
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	movs r0, #0x8f
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r4, #2]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r3, #0x90
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r0, [r4, #4]
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r1]
_080DC5F2:
	ldrh r0, [r6, #0x1e]
	adds r0, #1
	strh r0, [r6, #0x1e]
	ldr r0, _080DC610 @ =0x00000131
	adds r1, r6, r0
	movs r0, #0xc
	strb r0, [r1]
	movs r0, #0xb3
	lsls r0, r0, #1
	bl PlaySound_082406e0
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DC610: .4byte 0x00000131

	thumb_func_start FUN_080dc614
FUN_080dc614: @ 0x080DC614
	push {lr}
	adds r3, r2, #0
	mov ip, r3
	movs r1, #4
	ldr r2, [r0, #0x38]
	ands r1, r2
	cmp r1, #0
	beq _080DC62E
	movs r0, #0x99
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0
	b _080DC64A
_080DC62E:
	movs r0, #8
	ands r2, r0
	cmp r2, #0
	beq _080DC64C
	movs r1, #0x99
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	cmp r0, #0x59
	bls _080DC64C
	movs r0, #0x9f
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
_080DC64A:
	strh r0, [r1]
_080DC64C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080dc650
FUN_080dc650: @ 0x080DC650
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r2, _080DC74C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x20
	orrs r0, r3
	ldr r1, _080DC750 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	mov r0, sp
	adds r0, #0xc
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r6, sp, #0x14
	ldr r0, [r6, #4]
	ands r0, r2
	str r0, [r6, #4]
	movs r1, #0x3c
	adds r1, r1, r7
	mov sb, r1
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sl, r2
	ldrh r1, [r2]
	ldr r2, _080DC754 @ =0x00002003
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r6, [sp, #8]
	mov r0, sb
	movs r3, #0
	bl FUN_0823646c
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	movs r1, #0
	mov r8, r1
	str r1, [sp]
	str r1, [sp, #4]
	mov r0, sb
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #0
	bl FUN_082364f8
	adds r5, r7, #0
	adds r5, #0x1c
	mov r0, sb
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _080DC758 @ =FUN_080dc4a8
	mov r0, sb
	adds r2, r7, #0
	bl FUN_0823651c
	movs r1, #0x40
	add r0, sp, #0xc
	strh r1, [r0]
	movs r0, #0x80
	ldr r2, [sp, #0x1c]
	strh r0, [r2, #2]
	strh r1, [r2, #4]
	mov r1, r8
	strh r1, [r6]
	strh r0, [r6, #2]
	strh r1, [r6, #4]
	adds r4, r7, #0
	adds r4, #0x8c
	mov r2, sl
	ldrh r1, [r2]
	ldr r2, _080DC75C @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r6, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _080DC760 @ =FUN_080dc614
	adds r0, r4, #0
	adds r2, r7, #0
	bl FUN_0823651c
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DC74C: .4byte 0xFFFF0000
_080DC750: .4byte 0x0000FFFF
_080DC754: .4byte 0x00002003
_080DC758: .4byte FUN_080dc4a8
_080DC75C: .4byte 0x00004001
_080DC760: .4byte FUN_080dc614

	thumb_func_start FUN_080dc764
FUN_080dc764: @ 0x080DC764
	push {r4, r5, r6, lr}
	movs r3, #0
	ldr r1, _080DC788 @ =0x00000F68
	adds r4, r0, r1
	movs r5, #1
	adds r2, r0, #0
	adds r2, #0x38
	movs r6, #0xa2
	lsls r6, r6, #1
_080DC776:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080DC78C
	movs r0, #1
	b _080DC78E
	.align 2, 0
_080DC788: .4byte 0x00000F68
_080DC78C:
	movs r0, #0
_080DC78E:
	cmp r0, #0
	bne _080DC7AC
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r1, _080DC7A8 @ =0x0000012F
	adds r0, r2, r1
	strb r3, [r0]
	adds r0, r2, #0
	b _080DC7B6
	.align 2, 0
_080DC7A8: .4byte 0x0000012F
_080DC7AC:
	adds r2, r2, r6
	adds r3, #1
	cmp r3, #0xb
	ble _080DC776
	movs r0, #0
_080DC7B6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080dc7bc
FUN_080dc7bc: @ 0x080DC7BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	str r0, [sp, #0x14]
	adds r6, r1, #0
	mov sl, r6
	movs r0, #0x98
	lsls r0, r0, #1
	adds r3, r6, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _080DC7F2
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r3]
_080DC7F2:
	adds r0, r6, #0
	adds r0, #0x1c
	ldrh r1, [r6, #0x1c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	str r0, [sp, #0x24]
	cmp r2, #0
	blt _080DC81C
	cmp r1, #0
	blt _080DC81C
	ldr r0, _080DC820 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080DC81C
	ldr r0, _080DC824 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080DC828
_080DC81C:
	movs r0, #0
	b _080DC836
	.align 2, 0
_080DC820: .4byte 0x030046A8
_080DC824: .4byte 0x030046AC
_080DC828:
	ldr r0, _080DC870 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080DC836:
	movs r3, #0x9a
	lsls r3, r3, #1
	adds r1, r6, r3
	strh r0, [r1]
	movs r5, #0x96
	lsls r5, r5, #1
	adds r5, r5, r6
	mov r8, r5
	ldrh r5, [r5]
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq _080DC8AC
	mov r0, sl
	movs r2, #0x1e
	ldrsh r7, [r0, r2]
	ldrh r5, [r1]
	mov r4, sl
	adds r4, #0x1c
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	adds r3, r4, #0
	cmp r0, #0
	beq _080DC874
	adds r0, #4
	b _080DC880
	.align 2, 0
_080DC870: .4byte 0x030046A4
_080DC874:
	ldr r0, _080DC894 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080DC880:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080DC898
	cmp r2, #2
	beq _080DC89C
	b _080DC8A0
	.align 2, 0
_080DC894: .4byte 0x030046A4
_080DC898:
	ldrb r0, [r4, #4]
	b _080DC89E
_080DC89C:
	ldrb r0, [r4]
_080DC89E:
	subs r1, r1, r0
_080DC8A0:
	cmp r7, r1
	bls _080DC912
	movs r5, #0x8f
	lsls r5, r5, #1
	adds r1, r6, r5
	b _080DC90C
_080DC8AC:
	add r3, sp, #4
	mov r4, sl
	adds r4, #0x1c
	movs r7, #0x92
	lsls r7, r7, #1
	adds r2, r6, r7
	ldrh r0, [r2]
	mov r7, sl
	ldrh r1, [r7, #0x1c]
	subs r0, r0, r1
	adds r1, r3, #0
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	adds r0, r3, #0
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, _080DC940 @ =0x0003FFFF
	adds r3, r4, #0
	cmp r1, r0
	ble _080DC8FE
	movs r7, #0xa0
	lsls r7, r7, #1
	adds r0, r6, r7
	ldrh r0, [r0]
	cmp r0, #8
	bls _080DC912
_080DC8FE:
	movs r0, #1
	orrs r0, r5
	mov r1, r8
	strh r0, [r1]
	movs r2, #0x8f
	lsls r2, r2, #1
	adds r1, r6, r2
_080DC90C:
	ldrh r0, [r1]
	subs r0, #4
	strh r0, [r1]
_080DC912:
	movs r5, #0x9a
	lsls r5, r5, #1
	adds r0, r6, r5
	mov r8, r3
	movs r7, #0x8e
	lsls r7, r7, #1
	adds r4, r6, r7
	ldrh r0, [r0]
	str r0, [sp, #0x18]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #4
	ldrsh r1, [r4, r2]
	bl FUN_0823785c
	ldr r0, [sp, #0x18]
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080DC944
	adds r0, #4
	b _080DC952
	.align 2, 0
_080DC940: .4byte 0x0003FFFF
_080DC944:
	ldr r0, _080DC968 @ =0x030046A4
	ldr r1, [r0]
	ldr r3, [sp, #0x18]
	lsls r0, r3, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080DC952:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080DC96C
	cmp r2, #2
	beq _080DC972
	b _080DC978
	.align 2, 0
_080DC968: .4byte 0x030046A4
_080DC96C:
	mov r5, r8
	ldrb r0, [r5, #4]
	b _080DC976
_080DC972:
	mov r7, r8
	ldrb r0, [r7]
_080DC976:
	subs r1, r1, r0
_080DC978:
	str r1, [sp, #0x1c]
	movs r0, #0
	ldrsh r2, [r4, r0]
	movs r1, #4
	ldrsh r0, [r4, r1]
	adds r0, r2, r0
	movs r3, #2
	ldrsh r1, [r4, r3]
	adds r5, r6, #0
	adds r5, #0x8c
	cmn r0, r1
	bne _080DC992
	b _080DCBE4
_080DC992:
	mov r5, r8
	movs r7, #2
	ldrsh r0, [r5, r7]
	ldr r1, [sp, #0x1c]
	cmp r0, r1
	bgt _080DCA02
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #1
	movs r1, #0xa
	bl Div
	movs r5, #0
	strh r0, [r4]
	movs r2, #2
	ldrsh r0, [r4, r2]
	lsls r0, r0, #2
	movs r1, #0xa
	bl Div
	rsbs r0, r0, #0
	strh r0, [r4, #2]
	movs r3, #4
	ldrsh r1, [r4, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r1, #0xa
	bl Div
	strh r0, [r4, #4]
	movs r7, #0
	ldrsh r0, [r4, r7]
	movs r2, #4
	ldrsh r1, [r4, r2]
	movs r3, #2
	ldrsh r2, [r4, r3]
	adds r0, r0, r1
	adds r0, r0, r2
	cmp r0, #0
	bge _080DC9E6
	rsbs r0, r0, #0
_080DC9E6:
	cmp r0, #2
	bgt _080DC9F2
	strh r5, [r4]
	strh r5, [r4, #2]
	strh r5, [r4, #4]
	b _080DC9FA
_080DC9F2:
	movs r0, #0xb3
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080DC9FA:
	mov r5, sp
	ldrh r7, [r5, #0x1c]
	mov r5, r8
	strh r7, [r5, #2]
_080DCA02:
	ldrh r0, [r4]
	mov r1, r8
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _080DCA68 @ =0xFFFF0000
	ldr r2, [sp, #0xc]
	ands r2, r3
	orrs r2, r0
	str r2, [sp, #0xc]
	ldrh r1, [r4, #2]
	mov r5, r8
	ldrh r5, [r5, #2]
	adds r1, r1, r5
	lsls r1, r1, #0x10
	ldr r0, _080DCA6C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	ldrh r1, [r4, #4]
	mov r7, r8
	ldrh r7, [r7, #4]
	adds r1, r1, r7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r2, sp, #0xc
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080DCA64
	cmp r1, #0
	blt _080DCA64
	ldr r0, _080DCA70 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080DCA64
	ldr r0, _080DCA74 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080DCA78
_080DCA64:
	movs r5, #0
	b _080DCA86
	.align 2, 0
_080DCA68: .4byte 0xFFFF0000
_080DCA6C: .4byte 0x0000FFFF
_080DCA70: .4byte 0x030046A8
_080DCA74: .4byte 0x030046AC
_080DCA78:
	ldr r0, _080DCA98 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r3
_080DCA86:
	add r7, sp, #0xc
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080DCA9C
	adds r0, #4
	b _080DCAA8
	.align 2, 0
_080DCA98: .4byte 0x030046A4
_080DCA9C:
	ldr r0, _080DCABC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080DCAA8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080DCAC0
	cmp r2, #2
	beq _080DCAC4
	b _080DCAC8
	.align 2, 0
_080DCABC: .4byte 0x030046A4
_080DCAC0:
	ldrb r0, [r7, #4]
	b _080DCAC6
_080DCAC4:
	ldrb r0, [r7]
_080DCAC6:
	subs r1, r1, r0
_080DCAC8:
	mov sb, r1
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080DCADA
	adds r0, #4
	b _080DCAE6
_080DCADA:
	ldr r0, _080DCB04 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080DCAE6:
	ldrh r7, [r0, #2]
	ldr r0, [sp, #0x18]
	cmp r0, r5
	beq _080DCB4A
	ldr r1, [sp, #0x1c]
	cmp r1, sb
	blt _080DCB1E
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080DCB08
	adds r0, #4
	b _080DCB14
	.align 2, 0
_080DCB04: .4byte 0x030046A4
_080DCB08:
	ldr r0, _080DCBB4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080DCB14:
	ldrh r0, [r0, #2]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _080DCB4A
_080DCB1E:
	movs r2, #0
	ldrsh r1, [r4, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xa
	bl Div
	rsbs r0, r0, #0
	strh r0, [r4]
	movs r3, #4
	ldrsh r1, [r4, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xa
	bl Div
	rsbs r0, r0, #0
	strh r0, [r4, #4]
	movs r0, #0xb3
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080DCB4A:
	mov r5, sb
	cmp r5, #0
	ble _080DCB58
	movs r0, #0x40
	ands r7, r0
	cmp r7, #0
	beq _080DCBC4
_080DCB58:
	mov r7, sp
	movs r1, #0xe
	ldrsh r0, [r7, r1]
	cmp r0, sb
	bgt _080DCBC4
	ldr r0, _080DCBB8 @ =0x0300016C
	ldr r2, [r0]
	ldr r3, _080DCBBC @ =0x0000012F
	adds r7, r6, r3
	movs r0, #0
	ldrsb r0, [r7, r0]
	ldr r5, _080DCBC0 @ =0x00000F68
	adds r2, r2, r5
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	movs r1, #0x97
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r4, #0
	strb r4, [r0]
	adds r0, r6, #0
	bl FUN_0822a4e0
	adds r0, r6, #0
	adds r0, #0xdc
	bl FUN_080138fc
	adds r5, r6, #0
	adds r5, #0x8c
	adds r0, r5, #0
	bl FUN_08236424
	movs r0, #0xff
	strb r0, [r7]
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r4, [r0]
	movs r3, #0x99
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r4, [r0]
	b _080DCBE4
	.align 2, 0
_080DCBB4: .4byte 0x030046A4
_080DCBB8: .4byte 0x0300016C
_080DCBBC: .4byte 0x0000012F
_080DCBC0: .4byte 0x00000F68
_080DCBC4:
	ldrh r0, [r4]
	mov r5, r8
	ldrh r5, [r5]
	adds r0, r0, r5
	mov r7, r8
	strh r0, [r7]
	ldrh r0, [r4, #2]
	ldrh r1, [r7, #2]
	adds r0, r0, r1
	strh r0, [r7, #2]
	ldrh r0, [r4, #4]
	ldrh r2, [r7, #4]
	adds r0, r0, r2
	strh r0, [r7, #4]
	adds r5, r6, #0
	adds r5, #0x8c
_080DCBE4:
	adds r0, r5, #0
	ldr r1, [sp, #0x24]
	movs r2, #0
	bl FUN_082364c4
	ldr r3, _080DCC00 @ =0x00000131
	adds r1, r6, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _080DCC04
	subs r0, #1
	strb r0, [r1]
	b _080DCC18
	.align 2, 0
_080DCC00: .4byte 0x00000131
_080DCC04:
	adds r4, r6, #0
	adds r4, #0x3c
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_080DCC18:
	movs r5, #0x9d
	lsls r5, r5, #1
	adds r0, r6, r5
	ldrb r1, [r0]
	str r0, [sp, #0x20]
	cmp r1, #0
	beq _080DCC32
	subs r0, r1, #1
	ldr r7, [sp, #0x20]
	strb r0, [r7]
	adds r4, r6, #0
	adds r4, #0x2c
	b _080DCCB0
_080DCC32:
	movs r1, #0x99
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0x1d
	bhi _080DCC42
	movs r7, #3
	b _080DCC54
_080DCC42:
	cmp r0, #0x31
	bhi _080DCC4A
	movs r7, #2
	b _080DCC54
_080DCC4A:
	adds r4, r6, #0
	adds r4, #0x2c
	cmp r0, #0x59
	bhi _080DCCB0
	movs r7, #1
_080DCC54:
	ldrh r2, [r6, #0x3a]
	mov r8, r2
	ldrh r3, [r6, #0x34]
	mov sb, r3
	ldr r0, _080DCC80 @ =0x0000013B
	adds r5, r6, r0
	ldrb r0, [r5]
	cmp r0, #1
	bne _080DCC84
	adds r4, r6, #0
	adds r4, #0x2c
	ldr r2, [sp, #0x14]
	ldr r1, [r2, #0x34]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	movs r0, #2
	b _080DCC9C
	.align 2, 0
_080DCC80: .4byte 0x0000013B
_080DCC84:
	adds r4, r6, #0
	adds r4, #0x2c
	ldr r3, [sp, #0x14]
	ldr r1, [r3, #0x34]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	movs r0, #1
_080DCC9C:
	strb r0, [r5]
	mov r5, r8
	strh r5, [r6, #0x3a]
	mov r0, sb
	strh r0, [r6, #0x34]
	ldr r0, _080DCCE4 @ =0x085AD338
	adds r0, r7, r0
	ldrb r0, [r0]
	ldr r1, [sp, #0x20]
	strb r0, [r1]
_080DCCB0:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r2, sl
	strh r0, [r2, #0x10]
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
	beq _080DCCE8
	mov r3, sl
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	str r0, [r3]
	b _080DCCF4
	.align 2, 0
_080DCCE4: .4byte 0x085AD338
_080DCCE8:
	mov r7, sl
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
_080DCCF4:
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
	beq _080DCD1C
	mov r1, sl
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	mov r2, sl
	str r0, [r2]
	b _080DCD28
_080DCD1C:
	mov r3, sl
	ldr r0, [r3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_080DCD28:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r5, _080DCD5C @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r7, [r4, #7]
	cmp r0, r7
	blo _080DCD94
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DCD60
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DCD56
	ldrb r0, [r4, #5]
_080DCD56:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DCD70
	.align 2, 0
_080DCD5C: .4byte 0x0000FFFF
_080DCD60:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080DCD70
	strh r1, [r4, #8]
_080DCD70:
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
	bne _080DCD94
	movs r0, #1
	strb r0, [r4, #7]
_080DCD94:
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r5, #0x99
	lsls r5, r5, #1
	adds r1, r6, r5
	ldrh r0, [r1]
	cmp r0, #0
	beq _080DCDB2
	subs r0, #1
	strh r0, [r1]
	b _080DCDC6
_080DCDB2:
	movs r7, #0x97
	lsls r7, r7, #1
	adds r1, r6, r7
	movs r0, #2
	strb r0, [r1]
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
_080DCDC6:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080dcdd8
FUN_080dcdd8: @ 0x080DCDD8
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r1, #0
	movs r0, #0x98
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _080DCE2A
	adds r0, r5, #0
	adds r0, #0x1c
	movs r2, #0x9b
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r2, [r1]
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r3, [r1]
	movs r4, #0
	str r4, [sp]
	movs r1, #0x20
	bl FUN_080d84f8
	movs r7, #0x1c
	ldrsh r0, [r5, r7]
	movs r2, #0x20
	ldrsh r1, [r5, r2]
	movs r2, #0x80
	lsls r2, r2, #3
	movs r3, #1
	str r3, [sp]
	movs r7, #0x9e
	lsls r7, r7, #1
	adds r3, r5, r7
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_08240cf0
	strb r4, [r6]
_080DCE2A:
	ldr r0, _080DCE80 @ =0x0300016C
	ldr r2, [r0]
	ldr r0, _080DCE84 @ =0x0000012F
	adds r6, r5, r0
	movs r0, #0
	ldrsb r0, [r6, r0]
	ldr r1, _080DCE88 @ =0x00000F68
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	movs r2, #0x97
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r4, #0
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_0822a4e0
	adds r0, r5, #0
	adds r0, #0xdc
	bl FUN_080138fc
	adds r0, r5, #0
	adds r0, #0x8c
	bl FUN_08236424
	movs r0, #0xff
	strb r0, [r6]
	movs r3, #0x96
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r4, [r0]
	movs r7, #0x99
	lsls r7, r7, #1
	adds r0, r5, r7
	strh r4, [r0]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DCE80: .4byte 0x0300016C
_080DCE84: .4byte 0x0000012F
_080DCE88: .4byte 0x00000F68

	thumb_func_start FUN_080dce8c
FUN_080dce8c: @ 0x080DCE8C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp, #4]
	mov r8, r1
	adds r4, r2, #0
	mov sl, r3
	ldr r0, _080DCEE4 @ =0x0300016C
	ldr r5, [r0]
	cmp r5, #0
	bne _080DCEB2
	bl FUN_080dd1f8
	adds r5, r0, #0
	cmp r5, #0
	beq _080DCEDE
_080DCEB2:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _080DCEE8 @ =0x030047A4
	ldr r1, _080DCEEC @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _080DCEDE
	ldr r0, _080DCEF0 @ =0x03002BC0
	ldr r7, [r0]
	movs r0, #4
	ands r7, r0
	cmp r7, #0
	bne _080DCEDE
	adds r0, r5, #0
	bl FUN_080dc764
	adds r6, r0, #0
	cmp r6, #0
	bne _080DCEF4
_080DCEDE:
	movs r0, #0
	b _080DD0A2
	.align 2, 0
_080DCEE4: .4byte 0x0300016C
_080DCEE8: .4byte 0x030047A4
_080DCEEC: .4byte 0x030047A0
_080DCEF0: .4byte 0x03002BC0
_080DCEF4:
	movs r1, #0x97
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #1
	mov sb, r2
	mov r3, sb
	strb r3, [r0]
	subs r1, #2
	adds r0, r6, r1
	strh r7, [r0]
	movs r3, #0x92
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r6, r1
	mov r2, sb
	strb r2, [r0]
	subs r3, #8
	adds r2, r6, r3
	mov r3, r8
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x9b
	lsls r1, r1, #1
	adds r0, r6, r1
	mov r2, sl
	strh r2, [r0]
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, [sp, #0x28]
	strh r0, [r1]
	movs r1, #0x9f
	lsls r1, r1, #1
	adds r0, r6, r1
	mov r2, sp
	ldrh r2, [r2, #0x2c]
	strh r2, [r0]
	subs r3, #6
	adds r0, r6, r3
	mov r1, sp
	ldrh r1, [r1, #0x2c]
	strh r1, [r0]
	ldr r2, _080DCFC8 @ =0x00000131
	adds r1, r6, r2
	movs r0, #0x1e
	strb r0, [r1]
	adds r3, #0xa
	adds r1, r6, r3
	ldr r0, [sp, #0x30]
	strh r0, [r1]
	ldr r1, _080DCFCC @ =0x0000013B
	adds r0, r6, r1
	mov r2, sb
	strb r2, [r0]
	mov r8, r6
	ldr r3, [sp, #4]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	adds r1, r5, #0
	adds r1, #0x18
	adds r0, r6, #0
	movs r2, #0
	bl FUN_0822a470
	adds r4, r6, #0
	adds r4, #0x2c
	ldr r1, [r5, #0x34]
	str r7, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	mov r1, sb
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sb
	ands r0, r2
	cmp r1, r0
	beq _080DCFD0
	ldr r0, [r6]
	movs r3, #4
	orrs r0, r3
	b _080DCFD8
	.align 2, 0
_080DCFC8: .4byte 0x00000131
_080DCFCC: .4byte 0x0000013B
_080DCFD0:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080DCFD8:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080DD002
	mov r1, r8
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	mov r2, r8
	str r0, [r2]
	b _080DD00E
_080DD002:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_080DD00E:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080DD044 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _080DD07C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DD048
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DD03C
	ldrb r0, [r4, #5]
_080DD03C:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DD058
	.align 2, 0
_080DD044: .4byte 0x0000FFFF
_080DD048:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080DD058
	strh r1, [r4, #8]
_080DD058:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
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
	bne _080DD07C
	movs r0, #1
	strb r0, [r4, #7]
_080DD07C:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	strb r1, [r3, #7]
	adds r0, r6, #0
	adds r0, #0xdc
	mov r1, r8
	adds r1, #0x1c
	movs r2, #0
	bl FUN_0801385c
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080dc650
	adds r0, r6, #0
_080DD0A2:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080dd0b4
FUN_080dd0b4: @ 0x080DD0B4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r3, r7, #0
	adds r3, #0x38
	ldr r1, _080DD114 @ =0x00000F68
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080DD14C
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _080DD118 @ =0x030047A4
	ldr r1, _080DD11C @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _080DD14C
	movs r1, #4
	ldr r0, _080DD120 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080DD14C
	movs r6, #0
	ldr r2, _080DD114 @ =0x00000F68
	adds r2, r2, r7
	mov r8, r2
	ldr r0, _080DD124 @ =0x085AD33C
	mov sb, r0
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r5, r7, r1
	adds r4, r3, #0
_080DD100:
	movs r1, #1
	lsls r1, r6
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080DD128
	movs r0, #1
	b _080DD12A
	.align 2, 0
_080DD114: .4byte 0x00000F68
_080DD118: .4byte 0x030047A4
_080DD11C: .4byte 0x030047A0
_080DD120: .4byte 0x03002BC0
_080DD124: .4byte 0x085AD33C
_080DD128:
	movs r0, #0
_080DD12A:
	cmp r0, #0
	beq _080DD13E
	ldrb r0, [r5]
	lsls r0, r0, #2
	add r0, sb
	ldr r2, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl _call_via_r2
_080DD13E:
	movs r0, #0xa2
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r6, #1
	cmp r6, #0xb
	ble _080DD100
_080DD14C:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080dd15c
FUN_080dd15c: @ 0x080DD15C
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	ldr r1, _080DD180 @ =0x00000F68
	adds r7, r0, r1
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r5, r0, r1
	adds r4, r0, #0
	adds r4, #0x38
_080DD16E:
	movs r1, #1
	lsls r1, r6
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _080DD184
	movs r0, #1
	b _080DD186
	.align 2, 0
_080DD180: .4byte 0x00000F68
_080DD184:
	movs r0, #0
_080DD186:
	cmp r0, #0
	beq _080DD196
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r0, r5, #0
	bl FUN_080138fc
_080DD196:
	movs r0, #0xa2
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r6, #1
	cmp r6, #0xb
	ble _080DD16E
	movs r1, #0
	ldr r0, _080DD1B4 @ =0x0300016C
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DD1B4: .4byte 0x0300016C

	thumb_func_start FUN_080dd1b8
FUN_080dd1b8: @ 0x080DD1B8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	ldr r1, _080DD1E4 @ =0x0000E74B
	bl FUN_0822b16c
	ldr r0, _080DD1E8 @ =0x0000922E
	ldr r1, _080DD1EC @ =0x0000871C
	bl GetFile
	str r0, [r4, #0x34]
	ldr r0, _080DD1F0 @ =0x00000F68
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
	ldr r0, _080DD1F4 @ =0x0300016C
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080DD1E4: .4byte 0x0000E74B
_080DD1E8: .4byte 0x0000922E
_080DD1EC: .4byte 0x0000871C
_080DD1F0: .4byte 0x00000F68
_080DD1F4: .4byte 0x0300016C

	thumb_func_start FUN_080dd1f8
FUN_080dd1f8: @ 0x080DD1F8
	push {r4, lr}
	ldr r0, _080DD22C @ =0x0300016C
	ldr r0, [r0]
	cmp r0, #0
	bne _080DD23E
	ldr r1, _080DD230 @ =0x00000F6C
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080DD23C
	ldr r1, _080DD234 @ =FUN_080dd0b4
	ldr r2, _080DD238 @ =0x080DD15D
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080dd1b8
	cmp r0, #0
	bge _080DD23C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080DD23E
	.align 2, 0
_080DD22C: .4byte 0x0300016C
_080DD230: .4byte 0x00000F6C
_080DD234: .4byte FUN_080dd0b4
_080DD238: .4byte 0x080DD15D
_080DD23C:
	adds r0, r4, #0
_080DD23E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080dd244
FUN_080dd244: @ 0x080DD244
	ldr r1, _080DD24C @ =0x0300016C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080DD24C: .4byte 0x0300016C

	thumb_func_start FUN_080dd250
FUN_080dd250: @ 0x080DD250
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, _080DD274 @ =0x0300016C
	ldr r0, [r0]
	cmp r0, #0
	beq _080DD30C
	adds r2, r0, #0
	adds r2, #0x38
	ldr r3, _080DD278 @ =0x00000F68
	adds r1, r0, r3
	ldr r0, [r1]
	cmp r0, #0
	bne _080DD286
	b _080DD30C
	.align 2, 0
_080DD274: .4byte 0x0300016C
_080DD278: .4byte 0x00000F68
_080DD27C:
	adds r0, r3, #0
	adds r1, r2, #0
	bl FUN_0823785c
	b _080DD310
_080DD286:
	movs r5, #0
	adds r7, r1, #0
	mov r4, sp
	mov ip, r2
	movs r0, #0xa2
	lsls r0, r0, #1
	mov r8, r0
_080DD294:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _080DD2A4
	movs r0, #1
	b _080DD2A6
_080DD2A4:
	movs r0, #0
_080DD2A6:
	cmp r0, #0
	beq _080DD304
	ldr r0, _080DD31C @ =0x0000012F
	add r0, ip
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080DD304
	movs r0, #0x99
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	cmp r0, #0
	beq _080DD304
	movs r0, #0x97
	lsls r0, r0, #1
	add r0, ip
	ldrb r0, [r0]
	cmp r0, #2
	beq _080DD304
	mov r1, ip
	ldrh r0, [r1, #0x1c]
	ldrh r1, [r6]
	subs r0, r0, r1
	strh r0, [r4]
	mov r3, ip
	ldrh r0, [r3, #0x1e]
	ldrh r1, [r6, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r3, #0x20]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r0, #0
	ldrsh r3, [r4, r0]
	adds r1, r3, #0
	muls r1, r3, r1
	movs r0, #4
	ldrsh r2, [r4, r0]
	adds r0, r2, #0
	muls r0, r2, r0
	adds r1, r1, r0
	ldr r0, _080DD320 @ =0x00018FFF
	cmp r1, r0
	ble _080DD27C
_080DD304:
	add ip, r8
	adds r5, #1
	cmp r5, #0xb
	ble _080DD294
_080DD30C:
	movs r0, #1
	rsbs r0, r0, #0
_080DD310:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DD31C: .4byte 0x0000012F
_080DD320: .4byte 0x00018FFF

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
	bl prepare_08231510
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
	bl prepare_08231510
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
	bl prepare_08231510
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
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
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
	bl FUN_0823646c
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
	bl FUN_082364f8
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
	bl FUN_082364f8
_080DD7EC:
	ldr r0, _080DD814 @ =0x00003246
	strh r0, [r6, #4]
	adds r1, r5, #0
	adds r1, #0x50
	adds r0, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r6, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_0823651c
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
	bl FUN_08236400
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
	bl FUN_080ddad0
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
	bl FUN_080ddad0
	cmp r0, #0
	beq _080DDA46
_080DD954:
	bl FUN_080dd890
	adds r5, r0, #0
	cmp r5, #0
	beq _080DDA46
	movs r0, #0x70
	bl prepare_08231510
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
	bl prepare_08231510
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
	bl Script_GetKeywordValue
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

	thumb_func_start FUN_080dda54
FUN_080dda54: @ 0x080DDA54
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

	thumb_func_start FUN_080ddaa8
FUN_080ddaa8: @ 0x080DDAA8
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

	thumb_func_start FUN_080ddab8
FUN_080ddab8: @ 0x080DDAB8
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

	thumb_func_start FUN_080ddad0
FUN_080ddad0: @ 0x080DDAD0
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
	ldr r1, _080DDB0C @ =FUN_080dda54
	ldr r2, _080DDB10 @ =0x080DDAA9
	bl SetEntityRoutine
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ddab8
	cmp r0, #0
	bge _080DDB14
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080DDB16
	.align 2, 0
_080DDB08: .4byte 0x03000170
_080DDB0C: .4byte FUN_080dda54
_080DDB10: .4byte 0x080DDAA9
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
	bl FUN_0822dabc
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

