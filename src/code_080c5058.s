	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
	bl Video_GetAuxSprite
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
	bl Video_SetAuxSpritePltt
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
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r0, #0x34
	ldr r1, _080DA80C @ =0x0000363D
	bl Video_GetAuxSprite
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

	thumb_func_start Entity080db520_Update
Entity080db520_Update: @ 0x080DB43C
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

	thumb_func_start Entity080db520_Destroy
Entity080db520_Destroy: @ 0x080DB498
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

	thumb_func_start Entity080db520_Init
Entity080db520_Init: @ 0x080DB4E8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	ldr r1, _080DB510 @ =0x00001C1B
	bl Video_GetAuxSprite
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

	thumb_func_start Entity080db520_Create
Entity080db520_Create: @ 0x080DB520
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
	ldr r1, _080DB55C @ =Entity080db520_Update
	ldr r2, _080DB560 @ =Entity080db520_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity080db520_Init
	cmp r0, #0
	bge _080DB564
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080DB566
	.align 2, 0
_080DB554: .4byte 0x03000160
_080DB558: .4byte 0x0000055C
_080DB55C: .4byte Entity080db520_Update
_080DB560: .4byte Entity080db520_Destroy
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
	bl Entity080db520_Create
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
	bl VM_SeekToKeyword
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
	bl VM_GetKeywordValue
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
	bl ArcTan2_8
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
	bl ArcTan2_8
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
	bl ParticleShadow_Remove
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
	bl ParticleShadow_Remove
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
	bl ParticleShadow_Init
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
	bl ParticleShadow_Remove
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
	bl Video_GetAuxSprite
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
	bl ArcTan2_8
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

