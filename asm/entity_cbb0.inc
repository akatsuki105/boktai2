	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080ad1ec
FUN_080ad1ec: @ 0x080AD1EC
	ldr r3, _080AD1FC @ =0x000004FC
	adds r2, r0, r3
	movs r3, #0
	strh r1, [r2]
	ldr r1, _080AD200 @ =0x000004FE
	adds r0, r0, r1
	strh r3, [r0]
	bx lr
	.align 2, 0
_080AD1FC: .4byte 0x000004FC
_080AD200: .4byte 0x000004FE

	thumb_func_start FUN_080ad204
FUN_080ad204: @ 0x080AD204
	push {lr}
	sub sp, #0xc
	adds r3, r1, #0
	ldr r1, _080AD234 @ =0x000017A4
	adds r0, r0, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080AD22E
	ldr r1, _080AD238 @ =0xFFFF0000
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
_080AD22E:
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_080AD234: .4byte 0x000017A4
_080AD238: .4byte 0xFFFF0000

	thumb_func_start FUN_080ad23c
FUN_080ad23c: @ 0x080AD23C
	push {r4, r5, r6, r7, lr}
	movs r1, #0xac
	lsls r1, r1, #3
	adds r6, r0, r1
	ldr r1, _080AD284 @ =0x00000BE4
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080AD2C4
	movs r7, #0
	movs r5, #0
_080AD252:
	movs r0, #0x34
	muls r0, r5, r0
	adds r0, #4
	adds r2, r6, r0
	adds r3, r2, #0
	adds r3, #0x30
	ldrb r0, [r3]
	cmp r0, #0
	beq _080AD2B8
	adds r4, r2, #0
	adds r4, #0x31
	adds r1, r2, #0
	adds r1, #0x32
	ldrb r0, [r4]
	ldrb r1, [r1]
	cmp r0, r1
	blo _080AD288
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	strb r0, [r3]
	b _080AD2B8
	.align 2, 0
_080AD284: .4byte 0x00000BE4
_080AD288:
	movs r7, #1
	ldrh r0, [r2, #0x28]
	ldrh r1, [r2, #0x18]
	adds r0, r0, r1
	strh r0, [r2, #0x18]
	ldrh r0, [r2, #0x2a]
	ldrh r1, [r2, #0x1a]
	adds r0, r0, r1
	strh r0, [r2, #0x1a]
	ldrh r0, [r2, #0x2c]
	ldrh r1, [r2, #0x1c]
	adds r0, r0, r1
	strh r0, [r2, #0x1c]
	ldrb r0, [r4]
	cmp r0, #6
	bne _080AD2B2
	ldr r1, [r6]
	adds r0, r2, #0
	movs r2, #3
	bl FUN_0822dafc
_080AD2B2:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_080AD2B8:
	adds r5, #1
	cmp r5, #0x1f
	ble _080AD252
	ldr r1, _080AD2CC @ =0x00000684
	adds r0, r6, r1
	strb r7, [r0]
_080AD2C4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD2CC: .4byte 0x00000684

	thumb_func_start FUN_080ad2d0
FUN_080ad2d0: @ 0x080AD2D0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	mov r8, r2
	mov sb, r3
	ldr r6, [sp, #0x20]
	movs r0, #0xac
	lsls r0, r0, #3
	adds r3, r5, r0
	ldr r2, _080AD360 @ =0x00000BE5
	adds r7, r5, r2
	ldrb r2, [r7]
	movs r0, #0x34
	adds r4, r2, #0
	muls r4, r0, r4
	adds r4, #4
	adds r4, r3, r4
	ldr r0, [r4]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r4]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r4, #0x18]
	str r1, [r4, #0x1c]
	movs r0, #0
	mov sl, r0
	strb r6, [r4, #0xf]
	ldr r1, [r3]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_0822dafc
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	adds r0, r4, #0
	adds r0, #0x31
	mov r1, sl
	strb r1, [r0]
	adds r0, #1
	mov r2, sb
	strb r2, [r0]
	adds r4, #0x30
	movs r0, #1
	strb r0, [r4]
	ldr r1, _080AD364 @ =0x00000BE4
	adds r5, r5, r1
	strb r0, [r5]
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _080AD350
	mov r2, sl
	strb r2, [r7]
_080AD350:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD360: .4byte 0x00000BE5
_080AD364: .4byte 0x00000BE4

	thumb_func_start FUN_080ad368
FUN_080ad368: @ 0x080AD368
	push {r4, r5, lr}
	ldr r1, _080AD384 @ =0x00000564
	adds r4, r0, r1
	movs r5, #0x1f
_080AD370:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x34
	subs r5, #1
	cmp r5, #0
	bge _080AD370
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AD384: .4byte 0x00000564

	thumb_func_start FUN_080ad388
FUN_080ad388: @ 0x080AD388
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r0, #0xac
	lsls r0, r0, #3
	adds r6, r4, r0
	ldr r0, _080AD3E0 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6]
	ldr r0, _080AD3E4 @ =0x00000BE4
	adds r4, r4, r0
	movs r0, #0
	strb r0, [r4]
	movs r5, #0
	movs r7, #4
	rsbs r7, r7, #0
_080AD3A8:
	movs r0, #0x34
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #4
	adds r4, r6, r4
	ldr r1, [r6]
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
	adds r4, #0x30
	movs r0, #0
	strb r0, [r4]
	adds r5, #1
	cmp r5, #0x1f
	ble _080AD3A8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD3E0: .4byte 0x00001C1E
_080AD3E4: .4byte 0x00000BE4

	thumb_func_start FUN_080ad3e8
FUN_080ad3e8: @ 0x080AD3E8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080AD400 @ =0x00000C0B
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bhi _080AD4D8
	lsls r0, r0, #2
	ldr r1, _080AD404 @ =_080AD408
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080AD400: .4byte 0x00000C0B
_080AD404: .4byte _080AD408
_080AD408: @ jump table
	.4byte _080AD420 @ case 0
	.4byte _080AD434 @ case 1
	.4byte _080AD458 @ case 2
	.4byte _080AD46C @ case 3
	.4byte _080AD498 @ case 4
	.4byte _080AD4C8 @ case 5
_080AD420:
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r1, #2
	strb r1, [r0]
	ldr r3, _080AD430 @ =0x0000022D
	adds r0, r4, r3
	b _080AD4D6
	.align 2, 0
_080AD430: .4byte 0x0000022D
_080AD434:
	movs r0, #0x8b
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #0
	movs r0, #2
	strb r0, [r1]
	ldr r1, _080AD450 @ =0x0000022D
	adds r0, r4, r1
	strb r2, [r0]
	ldr r3, _080AD454 @ =0x00001426
	adds r1, r4, r3
	movs r0, #1
	strh r0, [r1]
	b _080AD484
	.align 2, 0
_080AD450: .4byte 0x0000022D
_080AD454: .4byte 0x00001426
_080AD458:
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r1, #0
	strb r1, [r0]
	ldr r3, _080AD468 @ =0x0000022D
	adds r0, r4, r3
	b _080AD4D6
	.align 2, 0
_080AD468: .4byte 0x0000022D
_080AD46C:
	movs r1, #0x8b
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _080AD48C @ =0x0000022D
	adds r0, r4, r3
	movs r1, #1
	strb r1, [r0]
	ldr r3, _080AD490 @ =0x00001426
	adds r0, r4, r3
	strh r1, [r0]
_080AD484:
	ldr r1, _080AD494 @ =0x00001424
	adds r0, r4, r1
	strh r2, [r0]
	b _080AD4D8
	.align 2, 0
_080AD48C: .4byte 0x0000022D
_080AD490: .4byte 0x00001426
_080AD494: .4byte 0x00001424
_080AD498:
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r0, _080AD4BC @ =0x0000022D
	adds r1, r4, r0
	movs r0, #2
	strb r0, [r1]
	ldr r1, _080AD4C0 @ =0x00001426
	adds r0, r4, r1
	strh r2, [r0]
	ldr r2, _080AD4C4 @ =0x00001424
	adds r0, r4, r2
	strh r3, [r0]
	b _080AD4D8
	.align 2, 0
_080AD4BC: .4byte 0x0000022D
_080AD4C0: .4byte 0x00001426
_080AD4C4: .4byte 0x00001424
_080AD4C8:
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r1, #2
	strb r1, [r0]
	ldr r2, _080AD4E0 @ =0x0000022D
	adds r0, r4, r2
_080AD4D6:
	strb r1, [r0]
_080AD4D8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AD4E0: .4byte 0x0000022D

	thumb_func_start FUN_080ad4e4
FUN_080ad4e4: @ 0x080AD4E4
	push {lr}
	adds r1, r0, #0
	adds r0, #0x68
	ldrh r0, [r0]
	cmp r0, #0
	beq _080AD4FE
	ldr r0, [r1]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080AD4FE
	movs r0, #1
	b _080AD500
_080AD4FE:
	movs r0, #0
_080AD500:
	pop {r1}
	bx r1

	thumb_func_start FUN_080ad504
FUN_080ad504: @ 0x080AD504
	push {lr}
	adds r1, r0, #0
	adds r1, #0x6e
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x81
	bls _080AD51C
	movs r0, #0
	strh r0, [r1]
_080AD51C:
	ldrh r0, [r1]
	cmp r0, #0x1d
	bhi _080AD526
	movs r0, #0
	b _080AD540
_080AD526:
	cmp r0, #0x27
	bls _080AD53A
	cmp r0, #0x31
	bls _080AD53E
	cmp r0, #0x6d
	bhi _080AD536
	movs r0, #3
	b _080AD540
_080AD536:
	cmp r0, #0x77
	bls _080AD53E
_080AD53A:
	movs r0, #1
	b _080AD540
_080AD53E:
	movs r0, #2
_080AD540:
	pop {r1}
	bx r1

	thumb_func_start FUN_080ad544
FUN_080ad544: @ 0x080AD544
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r7, r0, #0
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _080AD56A
	mov r4, sp
	movs r5, #2
_080AD55C:
	bl Script_GetValue
	stm r4!, {r0}
	subs r5, #1
	cmp r5, #0
	bge _080AD55C
	b _080AD58E
_080AD56A:
	ldr r0, _080AD67C @ =0x08251D7C
	bl FUN_08230860
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	ldr r0, _080AD680 @ =0x08251D98
	bl FUN_08230860
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	ldr r0, _080AD684 @ =0x08251DB4
	bl FUN_08230860
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
_080AD58E:
	movs r5, #0
	mov r6, sp
_080AD592:
	lsls r4, r5, #2
	ldm r6!, {r1}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080AD688 @ =0x000092B3
	bl GetFile
	movs r2, #0x88
	lsls r2, r2, #2
	adds r1, r7, r2
	adds r1, r1, r4
	adds r0, #0x14
	str r0, [r1]
	adds r5, #1
	cmp r5, #2
	ble _080AD592
	bl FUN_0823e1b0
	ldr r3, _080AD68C @ =0x00000C0B
	adds r1, r7, r3
	movs r4, #0
	strb r0, [r1]
	ldrb r1, [r1]
	adds r0, r7, #0
	bl FUN_080ad3e8
	ldr r1, _080AD690 @ =0x00001426
	adds r0, r7, r1
	strh r4, [r0]
	ldr r2, _080AD694 @ =0x00001424
	adds r0, r7, r2
	strh r4, [r0]
	ldr r3, _080AD698 @ =0x0000022D
	adds r0, r7, r3
	ldrb r1, [r0]
	lsls r1, r1, #2
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r7, r2
	adds r0, r0, r1
	ldr r0, [r0]
	mov r8, r0
	adds r6, r7, #0
	adds r6, #0x20
	mov r4, r8
	movs r5, #0xf
_080AD5EE:
	adds r0, r4, #0
	adds r1, r6, #0
	ldr r2, _080AD69C @ =0x04000008
	bl CpuSet
	adds r6, #0x20
	adds r4, #0x20
	subs r5, #1
	cmp r5, #0
	bge _080AD5EE
	ldr r6, _080AD6A0 @ =0x03004250
	mov r4, r8
	movs r5, #2
_080AD608:
	adds r0, r4, #0
	adds r1, r6, #0
	ldr r2, _080AD69C @ =0x04000008
	bl CpuSet
	adds r6, #0x20
	adds r4, #0x20
	subs r5, #1
	cmp r5, #0
	bge _080AD608
	movs r5, #2
	movs r3, #0x8d
	lsls r3, r3, #2
	adds r0, r7, r3
_080AD624:
	strh r5, [r0]
	subs r0, #2
	subs r5, #1
	cmp r5, #0
	bge _080AD624
	movs r0, #0x95
	lsls r0, r0, #2
	adds r4, r7, r0
	adds r0, r4, #0
	bl FUN_080ad4e4
	cmp r0, #0
	beq _080AD664
	adds r0, r4, #0
	bl FUN_080ad504
	ldr r1, _080AD6A4 @ =0x000002BE
	adds r2, r7, r1
	strh r0, [r2]
	movs r3, #0xa0
	lsls r3, r3, #2
	adds r0, r7, r3
	subs r3, #0x53
	adds r1, r7, r3
	ldrb r1, [r1]
	lsls r1, r1, #2
	ldrh r2, [r2]
	subs r3, #0xa5
	adds r2, r2, r3
	adds r1, r1, r2
	bl FUN_0822b20c
_080AD664:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #0
	str r0, [r1]
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD67C: .4byte 0x08251D7C
_080AD680: .4byte 0x08251D98
_080AD684: .4byte 0x08251DB4
_080AD688: .4byte 0x000092B3
_080AD68C: .4byte 0x00000C0B
_080AD690: .4byte 0x00001426
_080AD694: .4byte 0x00001424
_080AD698: .4byte 0x0000022D
_080AD69C: .4byte 0x04000008
_080AD6A0: .4byte 0x03004250
_080AD6A4: .4byte 0x000002BE

	thumb_func_start FUN_080ad6a8
FUN_080ad6a8: @ 0x080AD6A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r0
	bl FUN_0823e1b0
	adds r2, r0, #0
	ldr r1, _080AD768 @ =0x00000C0B
	add r1, r8
	ldrb r0, [r1]
	cmp r0, r2
	beq _080AD6D0
	strb r2, [r1]
	ldrb r1, [r1]
	mov r0, r8
	bl FUN_080ad3e8
_080AD6D0:
	ldr r0, _080AD76C @ =0x00001426
	add r0, r8
	ldrh r0, [r0]
	cmp r0, #0
	bne _080AD6DC
	b _080AD914
_080AD6DC:
	ldr r1, _080AD770 @ =0x00001428
	add r1, r8
	movs r0, #1
	strh r0, [r1]
	ldr r1, _080AD774 @ =0x00001424
	add r1, r8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls _080AD784
	ldr r0, _080AD778 @ =0x0000022D
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #2
	movs r1, #0x88
	lsls r1, r1, #2
	add r1, r8
	adds r1, r1, r0
	mov r5, r8
	adds r5, #0x20
	ldr r4, [r1]
	movs r6, #0xf
_080AD70E:
	adds r0, r4, #0
	adds r1, r5, #0
	ldr r2, _080AD77C @ =0x04000008
	bl CpuSet
	adds r5, #0x20
	adds r4, #0x20
	subs r6, #1
	cmp r6, #0
	bge _080AD70E
	ldr r0, _080AD76C @ =0x00001426
	add r0, r8
	movs r1, #0
	strh r1, [r0]
	movs r4, #0x95
	lsls r4, r4, #2
	add r4, r8
	adds r0, r4, #0
	bl FUN_080ad4e4
	cmp r0, #0
	bne _080AD73C
	b _080AD952
_080AD73C:
	adds r0, r4, #0
	bl FUN_080ad504
	ldr r2, _080AD780 @ =0x000002BE
	add r2, r8
	strh r0, [r2]
	movs r0, #0xa0
	lsls r0, r0, #2
	add r0, r8
	ldr r1, _080AD778 @ =0x0000022D
	add r1, r8
	ldrb r1, [r1]
	lsls r1, r1, #2
	ldrh r2, [r2]
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r2, r2, r3
	adds r1, r1, r2
	bl FUN_0822b20c
	b _080AD952
	.align 2, 0
_080AD768: .4byte 0x00000C0B
_080AD76C: .4byte 0x00001426
_080AD770: .4byte 0x00001428
_080AD774: .4byte 0x00001424
_080AD778: .4byte 0x0000022D
_080AD77C: .4byte 0x04000008
_080AD780: .4byte 0x000002BE
_080AD784:
	ldrh r1, [r1]
	movs r0, #0x40
	subs r0, r0, r1
	mov sl, r0
	mov sb, r1
	movs r0, #0x8b
	lsls r0, r0, #2
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #2
	movs r1, #0x88
	lsls r1, r1, #2
	add r1, r8
	adds r0, r1, r0
	ldr r0, [r0]
	mov ip, r0
	ldr r0, _080AD90C @ =0x0000022D
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r7, [r1]
	movs r0, #0
	mov r5, r8
	adds r5, #0x20
	str r5, [sp, #0x14]
_080AD7B8:
	movs r1, #0
	str r1, [sp]
	lsls r2, r0, #5
	str r2, [sp, #0x10]
	adds r0, #1
	str r0, [sp, #0xc]
_080AD7C4:
	mov r5, ip
	ldrh r3, [r5]
	movs r2, #0x1f
	ands r2, r3
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x15
	movs r0, #0x1f
	ands r6, r0
	lsrs r3, r3, #0x1a
	ands r3, r0
	ldrh r1, [r7]
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x15
	movs r5, #0x1f
	ands r4, r5
	lsrs r1, r1, #0x1a
	ands r1, r5
	mov r5, sl
	muls r5, r2, r5
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	adds r5, r5, r0
	asrs r5, r5, #6
	mov r2, sl
	muls r2, r6, r2
	mov r0, sb
	muls r0, r4, r0
	adds r2, r2, r0
	asrs r2, r2, #6
	mov r0, sl
	muls r0, r3, r0
	mov r3, sb
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	asrs r0, r0, #6
	ldr r3, [sp]
	lsls r1, r3, #1
	ldr r3, [sp, #0x10]
	adds r1, r1, r3
	ldr r3, [sp, #0x14]
	adds r1, r3, r1
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r5
	strh r0, [r1]
	movs r5, #2
	add ip, r5
	adds r7, #2
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	cmp r0, #0xf
	ble _080AD7C4
	ldr r0, [sp, #0xc]
	cmp r0, #0xf
	ble _080AD7B8
	movs r4, #0x95
	lsls r4, r4, #2
	add r4, r8
	adds r0, r4, #0
	bl FUN_080ad4e4
	cmp r0, #0
	bne _080AD84E
	b _080AD952
_080AD84E:
	adds r0, r4, #0
	bl FUN_080ad504
	ldr r2, _080AD910 @ =0x03003584
	movs r1, #0x8b
	lsls r1, r1, #2
	add r1, r8
	ldrb r1, [r1]
	lsls r1, r1, #2
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r0, r0, r3
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r2, [r2]
	adds r1, r2, r1
	str r1, [sp, #4]
	ldr r1, _080AD90C @ =0x0000022D
	add r1, r8
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r2, r2, r1
	mov ip, r2
	movs r7, #0xa7
	lsls r7, r7, #2
	add r7, r8
	movs r5, #0xf
	str r5, [sp, #8]
_080AD88A:
	ldr r0, [sp, #4]
	ldrh r3, [r0]
	movs r2, #0x1f
	ands r2, r3
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x15
	movs r1, #0x1f
	ands r6, r1
	lsrs r3, r3, #0x1a
	ands r3, r1
	mov r5, ip
	ldrh r1, [r5]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x15
	movs r5, #0x1f
	ands r4, r5
	lsrs r1, r1, #0x1a
	ands r1, r5
	mov r5, sl
	muls r5, r2, r5
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	adds r5, r5, r0
	asrs r5, r5, #6
	mov r2, sl
	muls r2, r6, r2
	mov r0, sb
	muls r0, r4, r0
	adds r2, r2, r0
	asrs r2, r2, #6
	mov r0, sl
	muls r0, r3, r0
	mov r3, sb
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r5
	strh r0, [r7]
	ldr r5, [sp, #4]
	adds r5, #2
	str r5, [sp, #4]
	movs r0, #2
	add ip, r0
	adds r7, #2
	ldr r1, [sp, #8]
	subs r1, #1
	str r1, [sp, #8]
	cmp r1, #0
	bge _080AD88A
	movs r1, #0xa3
	lsls r1, r1, #2
	add r1, r8
	movs r0, #0xa7
	lsls r0, r0, #2
	add r0, r8
	str r0, [r1]
	b _080AD952
	.align 2, 0
_080AD90C: .4byte 0x0000022D
_080AD910: .4byte 0x03003584
_080AD914:
	movs r4, #0x95
	lsls r4, r4, #2
	add r4, r8
	adds r0, r4, #0
	bl FUN_080ad4e4
	cmp r0, #0
	beq _080AD952
	adds r0, r4, #0
	bl FUN_080ad504
	ldr r2, _080AD964 @ =0x000002BE
	add r2, r8
	ldrh r3, [r2]
	cmp r0, r3
	beq _080AD952
	strh r0, [r2]
	movs r0, #0xa0
	lsls r0, r0, #2
	add r0, r8
	ldr r1, _080AD968 @ =0x0000022D
	add r1, r8
	ldrb r1, [r1]
	lsls r1, r1, #2
	ldrh r2, [r2]
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r2, r2, r5
	adds r1, r1, r2
	bl FUN_0822b20c
_080AD952:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AD964: .4byte 0x000002BE
_080AD968: .4byte 0x0000022D

	thumb_func_start FUN_080ad96c
FUN_080ad96c: @ 0x080AD96C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _080AD982
	adds r0, r5, #0
	bl _call_via_r1
_080AD982:
	adds r0, r5, #0
	bl FUN_080ad6a8
	ldr r2, _080AD9C8 @ =0x00001428
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080AD9C0
	movs r4, #0
_080AD994:
	lsls r1, r4, #1
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r0, r5, r2
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r0, #0x20
	adds r0, r5, r0
	lsls r1, r4, #5
	ldr r2, _080AD9CC @ =0x03004250
	adds r1, r1, r2
	ldr r2, _080AD9D0 @ =0x04000008
	bl CpuSet
	adds r4, #1
	cmp r4, #2
	ble _080AD994
	ldr r0, _080AD9C8 @ =0x00001428
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
_080AD9C0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AD9C8: .4byte 0x00001428
_080AD9CC: .4byte 0x03004250
_080AD9D0: .4byte 0x04000008

	thumb_func_start FUN_080ad9d4
FUN_080ad9d4: @ 0x080AD9D4
	push {r4, lr}
	lsls r1, r1, #1
	movs r4, #0x8c
	lsls r4, r4, #2
	adds r3, r0, r4
	adds r3, r3, r1
	strh r2, [r3]
	ldr r1, _080AD9F0 @ =0x00001428
	adds r0, r0, r1
	movs r1, #1
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AD9F0: .4byte 0x00001428

	thumb_func_start FUN_080ad9f4
FUN_080ad9f4: @ 0x080AD9F4
	movs r3, #0x94
	lsls r3, r3, #2
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080ADA08 @ =0x0000022E
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080ADA08: .4byte 0x0000022E

	thumb_func_start FUN_080ada0c
FUN_080ada0c: @ 0x080ADA0C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #2
	movs r2, #2
	bl FUN_080ad9d4
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ad9f4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ada28
FUN_080ada28: @ 0x080ADA28
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #2
	movs r2, #5
	bl FUN_080ad9d4
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ad9f4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ada44
FUN_080ada44: @ 0x080ADA44
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #2
	movs r2, #3
	bl FUN_080ad9d4
	ldr r1, _080ADA60 @ =FUN_080ada64
	adds r0, r4, #0
	bl FUN_080ad9f4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADA60: .4byte FUN_080ada64

	thumb_func_start FUN_080ada64
FUN_080ada64: @ 0x080ADA64
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADA94 @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080ADA8C
	adds r0, r4, #0
	movs r1, #2
	movs r2, #4
	bl FUN_080ad9d4
	ldr r1, _080ADA98 @ =FUN_080ada9c
	adds r0, r4, #0
	bl FUN_080ad9f4
_080ADA8C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADA94: .4byte 0x0000022E
_080ADA98: .4byte FUN_080ada9c

	thumb_func_start FUN_080ada9c
FUN_080ada9c: @ 0x080ADA9C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADACC @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080ADAC4
	adds r0, r4, #0
	movs r1, #2
	movs r2, #5
	bl FUN_080ad9d4
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ad9f4
_080ADAC4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADACC: .4byte 0x0000022E

	thumb_func_start FUN_080adad0
FUN_080adad0: @ 0x080ADAD0
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #2
	movs r2, #4
	bl FUN_080ad9d4
	ldr r1, _080ADAEC @ =FUN_080adaf0
	adds r0, r4, #0
	bl FUN_080ad9f4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADAEC: .4byte FUN_080adaf0

	thumb_func_start FUN_080adaf0
FUN_080adaf0: @ 0x080ADAF0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADB20 @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080ADB18
	adds r0, r4, #0
	movs r1, #2
	movs r2, #3
	bl FUN_080ad9d4
	ldr r1, _080ADB24 @ =FUN_080adb28
	adds r0, r4, #0
	bl FUN_080ad9f4
_080ADB18:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADB20: .4byte 0x0000022E
_080ADB24: .4byte FUN_080adb28

	thumb_func_start FUN_080adb28
FUN_080adb28: @ 0x080ADB28
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADB58 @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080ADB50
	adds r0, r4, #0
	movs r1, #2
	movs r2, #2
	bl FUN_080ad9d4
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ad9f4
_080ADB50:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADB58: .4byte 0x0000022E

	thumb_func_start FUN_080adb5c
FUN_080adb5c: @ 0x080ADB5C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #2
	movs r2, #6
	bl FUN_080ad9d4
	ldr r1, _080ADB88 @ =FUN_080adb90
	adds r0, r4, #0
	bl FUN_080ad9f4
	movs r1, #0xa1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r1, #0
	str r1, [r0]
	ldr r0, _080ADB8C @ =0x0000022E
	adds r4, r4, r0
	strh r1, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADB88: .4byte FUN_080adb90
_080ADB8C: .4byte 0x0000022E

	thumb_func_start FUN_080adb90
FUN_080adb90: @ 0x080ADB90
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADBC0 @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080ADBB8
	adds r0, r4, #0
	movs r1, #2
	movs r2, #7
	bl FUN_080ad9d4
	ldr r1, _080ADBC4 @ =FUN_080adbc8
	adds r0, r4, #0
	bl FUN_080ad9f4
_080ADBB8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADBC0: .4byte 0x0000022E
_080ADBC4: .4byte FUN_080adbc8

	thumb_func_start FUN_080adbc8
FUN_080adbc8: @ 0x080ADBC8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADBF8 @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080ADBF0
	adds r0, r4, #0
	movs r1, #2
	movs r2, #8
	bl FUN_080ad9d4
	ldr r1, _080ADBFC @ =FUN_080adc00
	adds r0, r4, #0
	bl FUN_080ad9f4
_080ADBF0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADBF8: .4byte 0x0000022E
_080ADBFC: .4byte FUN_080adc00

	thumb_func_start FUN_080adc00
FUN_080adc00: @ 0x080ADC00
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADC30 @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080ADC28
	adds r0, r4, #0
	movs r1, #2
	movs r2, #9
	bl FUN_080ad9d4
	ldr r1, _080ADC34 @ =FUN_080adc38
	adds r0, r4, #0
	bl FUN_080ad9f4
_080ADC28:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADC30: .4byte 0x0000022E
_080ADC34: .4byte FUN_080adc38

	thumb_func_start FUN_080adc38
FUN_080adc38: @ 0x080ADC38
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADC68 @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080ADC60
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0xa
	bl FUN_080ad9d4
	ldr r1, _080ADC6C @ =FUN_080adc70
	adds r0, r4, #0
	bl FUN_080ad9f4
_080ADC60:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADC68: .4byte 0x0000022E
_080ADC6C: .4byte FUN_080adc70

	thumb_func_start FUN_080adc70
FUN_080adc70: @ 0x080ADC70
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADCA0 @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080ADC98
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0xb
	bl FUN_080ad9d4
	ldr r1, _080ADCA4 @ =FUN_080adca8
	adds r0, r4, #0
	bl FUN_080ad9f4
_080ADC98:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADCA0: .4byte 0x0000022E
_080ADCA4: .4byte FUN_080adca8

	thumb_func_start FUN_080adca8
FUN_080adca8: @ 0x080ADCA8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADCE0 @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080ADCDA
	adds r0, r4, #0
	movs r1, #2
	movs r2, #2
	bl FUN_080ad9d4
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ad9f4
	movs r0, #0xa1
	lsls r0, r0, #5
	adds r1, r4, r0
	movs r0, #1
	str r0, [r1]
_080ADCDA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADCE0: .4byte 0x0000022E

	thumb_func_start FUN_080adce4
FUN_080adce4: @ 0x080ADCE4
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #2
	movs r2, #0xc
	bl FUN_080ad9d4
	ldr r1, _080ADD00 @ =FUN_080add3c
	adds r0, r4, #0
	bl FUN_080ad9f4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADD00: .4byte FUN_080add3c

	thumb_func_start FUN_080add04
FUN_080add04: @ 0x080ADD04
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADD34 @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x25
	bls _080ADD2C
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0xc
	bl FUN_080ad9d4
	ldr r1, _080ADD38 @ =FUN_080add3c
	adds r0, r4, #0
	bl FUN_080ad9f4
_080ADD2C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADD34: .4byte 0x0000022E
_080ADD38: .4byte FUN_080add3c

	thumb_func_start FUN_080add3c
FUN_080add3c: @ 0x080ADD3C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADD6C @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080ADD64
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0xd
	bl FUN_080ad9d4
	ldr r1, _080ADD70 @ =FUN_080add74
	adds r0, r4, #0
	bl FUN_080ad9f4
_080ADD64:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADD6C: .4byte 0x0000022E
_080ADD70: .4byte FUN_080add74

	thumb_func_start FUN_080add74
FUN_080add74: @ 0x080ADD74
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADDA4 @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x25
	bls _080ADD9C
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0xc
	bl FUN_080ad9d4
	ldr r1, _080ADDA8 @ =FUN_080addac
	adds r0, r4, #0
	bl FUN_080ad9f4
_080ADD9C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADDA4: .4byte 0x0000022E
_080ADDA8: .4byte FUN_080addac

	thumb_func_start FUN_080addac
FUN_080addac: @ 0x080ADDAC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080ADDDC @ =0x0000022E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080ADDD4
	adds r0, r4, #0
	movs r1, #2
	movs r2, #2
	bl FUN_080ad9d4
	ldr r1, _080ADDE0 @ =FUN_080add04
	adds r0, r4, #0
	bl FUN_080ad9f4
_080ADDD4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080ADDDC: .4byte 0x0000022E
_080ADDE0: .4byte FUN_080add04

	thumb_func_start FUN_080adde4
FUN_080adde4: @ 0x080ADDE4
	push {lr}
	movs r1, #0xc1
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xa
	bhi _080ADE44
	lsls r0, r0, #2
	ldr r1, _080ADDFC @ =_080ADE00
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080ADDFC: .4byte _080ADE00
_080ADE00: @ jump table
	.4byte _080ADE2C @ case 0
	.4byte _080ADE30 @ case 1
	.4byte _080ADE30 @ case 2
	.4byte _080ADE34 @ case 3
	.4byte _080ADE38 @ case 4
	.4byte _080ADE44 @ case 5
	.4byte _080ADE44 @ case 6
	.4byte _080ADE3C @ case 7
	.4byte _080ADE3C @ case 8
	.4byte _080ADE40 @ case 9
	.4byte _080ADE40 @ case 10
_080ADE2C:
	movs r0, #8
	b _080ADE46
_080ADE30:
	movs r0, #6
	b _080ADE46
_080ADE34:
	movs r0, #4
	b _080ADE46
_080ADE38:
	movs r0, #2
	b _080ADE46
_080ADE3C:
	movs r0, #0xa
	b _080ADE46
_080ADE40:
	movs r0, #0xc
	b _080ADE46
_080ADE44:
	movs r0, #0
_080ADE46:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080ade4c
FUN_080ade4c: @ 0x080ADE4C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080ADE78 @ =0x000092B3
	ldr r1, _080ADE7C @ =0x0000313A
	bl GetFile
	adds r4, r0, #0
	adds r4, #0x14
	adds r0, r5, #0
	bl FUN_080adde4
	lsls r0, r0, #5
	adds r4, r4, r0
	ldr r1, _080ADE80 @ =0x03004250
	ldr r2, _080ADE84 @ =0x04000010
	adds r0, r4, #0
	bl CpuSet
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080ADE78: .4byte 0x000092B3
_080ADE7C: .4byte 0x0000313A
_080ADE80: .4byte 0x03004250
_080ADE84: .4byte 0x04000010

	thumb_func_start FUN_080ade88
FUN_080ade88: @ 0x080ADE88
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, _080ADF1C @ =0x0000C091
	ldr r2, _080ADF20 @ =0x085AD048
	ldr r3, _080ADF24 @ =0x00001336
	adds r1, r6, r3
	ldrb r1, [r1]
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r1, [r1]
	bl GetFile
	adds r2, r0, #0
	ldr r0, _080ADF28 @ =0x000004D4
	adds r5, r6, r0
	str r2, [r5]
	movs r4, #0
	str r4, [sp, #0xc]
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r1, sp, #0xc
	str r1, [sp, #8]
	movs r0, #3
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	ldr r1, [r5]
	movs r0, #1
	movs r2, #0
	bl FUN_0822c398
	ldr r2, _080ADF2C @ =0x03003E78
	ldr r0, _080ADF30 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	movs r1, #0
	bl SetBGPrioDirect
	ldr r1, _080ADF34 @ =0x04000050
	ldr r2, _080ADF38 @ =0x00003C42
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	movs r3, #0x81
	lsls r3, r3, #4
	adds r0, r3, #0
	strh r0, [r1]
	ldr r0, _080ADF3C @ =0x04000054
	strh r4, [r0]
	ldr r0, _080ADF40 @ =0x000092B3
	ldr r1, _080ADF44 @ =0x0000F308
	bl GetFile
	movs r1, #0x9b
	lsls r1, r1, #3
	adds r6, r6, r1
	movs r2, #0xca
	lsls r2, r2, #1
	adds r0, r0, r2
	str r0, [r6]
	ldr r1, _080ADF48 @ =0x030043D0
	ldr r2, _080ADF4C @ =0x04000008
	bl CpuSet
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080ADF1C: .4byte 0x0000C091
_080ADF20: .4byte 0x085AD048
_080ADF24: .4byte 0x00001336
_080ADF28: .4byte 0x000004D4
_080ADF2C: .4byte 0x03003E78
_080ADF30: .4byte 0xFFFFFDFF
_080ADF34: .4byte 0x04000050
_080ADF38: .4byte 0x00003C42
_080ADF3C: .4byte 0x04000054
_080ADF40: .4byte 0x000092B3
_080ADF44: .4byte 0x0000F308
_080ADF48: .4byte 0x030043D0
_080ADF4C: .4byte 0x04000008

	thumb_func_start FUN_080adf50
FUN_080adf50: @ 0x080ADF50
	ldr r1, _080ADF5C @ =0x00001324
	adds r0, r0, r1
	movs r1, #0x30
	strh r1, [r0]
	bx lr
	.align 2, 0
_080ADF5C: .4byte 0x00001324

	thumb_func_start FUN_080adf60
FUN_080adf60: @ 0x080ADF60
	push {lr}
	ldr r0, _080ADF8C @ =0x03002C58
	ldr r3, [r0]
	cmp r3, #0
	beq _080ADF88
	ldr r0, _080ADF90 @ =0x00001324
	adds r1, r3, r0
	movs r2, #0
	movs r0, #0x40
	strh r0, [r1]
	ldr r1, _080ADF94 @ =0x00001326
	adds r0, r3, r1
	strh r2, [r0]
	ldr r0, _080ADF98 @ =0x00001374
	adds r1, r3, r0
	movs r0, #1
	strh r0, [r1]
	ldr r0, _080ADF9C @ =0x00000129
	bl PlaySound_082406e0
_080ADF88:
	pop {r0}
	bx r0
	.align 2, 0
_080ADF8C: .4byte 0x03002C58
_080ADF90: .4byte 0x00001324
_080ADF94: .4byte 0x00001326
_080ADF98: .4byte 0x00001374
_080ADF9C: .4byte 0x00000129

	thumb_func_start FUN_080adfa0
FUN_080adfa0: @ 0x080ADFA0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	adds r7, r0, #0
	str r1, [sp, #0x30]
	str r2, [sp, #0x34]
	str r3, [sp, #0x38]
	ldr r0, _080AE00C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	ble _080AE094
	ldr r2, _080AE010 @ =0x00001324
	adds r0, r7, r2
	ldrh r5, [r0]
	lsls r4, r5, #0x10
	lsrs r3, r4, #0x10
	cmp r3, #0
	bne _080ADFD4
	b _080AE370
_080ADFD4:
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, _080AE014 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	cmp r3, #0x1f
	bls _080AE034
	movs r4, #0x10
	cmp r3, #0x23
	bls _080AE028
	ldr r2, _080AE018 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AE01C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080AE020 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #7
	ands r0, r1
	ldr r2, _080AE024 @ =0x00001326
	adds r1, r7, r2
	b _080AE04E
	.align 2, 0
_080AE00C: .4byte 0x030046A0
_080AE010: .4byte 0x00001324
_080AE014: .4byte 0x03003E78
_080AE018: .4byte 0x030046B8
_080AE01C: .4byte 0x000003FF
_080AE020: .4byte 0x0203B400
_080AE024: .4byte 0x00001326
_080AE028:
	ldr r3, _080AE030 @ =0x00001326
	adds r1, r7, r3
	movs r0, #5
	b _080AE04E
	.align 2, 0
_080AE030: .4byte 0x00001326
_080AE034:
	lsrs r4, r4, #0x11
	movs r0, #3
	ands r0, r5
	cmp r0, #0
	bne _080AE050
	ldr r0, _080AE088 @ =0x00001326
	adds r1, r7, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _080AE050
	subs r0, r2, #1
_080AE04E:
	strh r0, [r1]
_080AE050:
	movs r0, #0x10
	subs r0, r0, r4
	asrs r0, r0, #1
	adds r0, #8
	ldr r1, _080AE08C @ =0x04000052
	lsls r0, r0, #8
	orrs r0, r4
	strh r0, [r1]
	ldr r1, _080AE088 @ =0x00001326
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r3, [sp, #0x60]
	adds r0, r3, r0
	str r0, [sp]
	movs r0, #1
	ldr r1, [sp, #0x30]
	ldr r2, [sp, #0x34]
	ldr r3, [sp, #0x38]
	bl Video_GenerateBGMap
	ldr r0, _080AE090 @ =0x00001324
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b _080AE37A
	.align 2, 0
_080AE088: .4byte 0x00001326
_080AE08C: .4byte 0x04000052
_080AE090: .4byte 0x00001324
_080AE094:
	movs r1, #0x9b
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	adds r0, #0x20
	ldr r1, _080AE0E8 @ =0x030043D0
	ldr r2, _080AE0EC @ =0x04000008
	bl CpuSet
	ldr r2, _080AE0F0 @ =0x00001374
	adds r0, r7, r2
	ldrh r3, [r0]
	cmp r3, #0
	beq _080AE0B2
	b _080AE1E8
_080AE0B2:
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, _080AE0F4 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _080AE0F8 @ =0x00001324
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls _080AE0D2
	strh r3, [r1]
_080AE0D2:
	ldrh r0, [r1]
	lsls r2, r0, #0x10
	lsrs r0, r2, #0x10
	cmp r0, #0x20
	bls _080AE0FC
	ldrh r1, [r1]
	movs r0, #0x40
	subs r0, r0, r1
	asrs r0, r0, #3
	b _080AE0FE
	.align 2, 0
_080AE0E8: .4byte 0x030043D0
_080AE0EC: .4byte 0x04000008
_080AE0F0: .4byte 0x00001374
_080AE0F4: .4byte 0x03003E78
_080AE0F8: .4byte 0x00001324
_080AE0FC:
	lsrs r0, r2, #0x13
_080AE0FE:
	adds r2, r0, #0
	adds r2, #0xc
	movs r0, #0x10
	subs r0, r0, r2
	asrs r0, r0, #1
	adds r0, #8
	ldr r1, _080AE1C8 @ =0x04000052
	lsls r0, r0, #8
	orrs r0, r2
	strh r0, [r1]
	ldr r2, _080AE1CC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AE1D0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080AE1D4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #7
	ands r0, r1
	ldr r2, _080AE1D8 @ =0x00001326
	adds r1, r7, r2
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	ldr r1, [sp, #0x60]
	adds r0, r1, r0
	str r0, [sp]
	movs r0, #1
	ldr r1, [sp, #0x30]
	ldr r2, [sp, #0x34]
	ldr r3, [sp, #0x38]
	bl Video_GenerateBGMap
	ldr r2, _080AE1DC @ =0x00001324
	adds r0, r7, r2
	ldrh r0, [r0]
	movs r5, #3
	ands r5, r0
	cmp r5, #0
	beq _080AE158
	b _080AE37A
_080AE158:
	movs r3, #0xa2
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r0, sp, #0x10
	ldrh r1, [r0]
	adds r1, #0x40
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _080AE1E0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	ldrh r0, [r0, #4]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x14]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x14]
	ldr r0, [sp, #0x18]
	ands r0, r3
	movs r4, #0x96
	lsls r4, r4, #1
	orrs r0, r4
	ldr r1, _080AE1E4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x96
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0x18]
	add r2, sp, #0x18
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r4
	str r0, [r2, #4]
	str r5, [sp]
	movs r0, #0x30
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #1
	movs r3, #0
	bl FUN_080ddcc8
	b _080AE37A
	.align 2, 0
_080AE1C8: .4byte 0x04000052
_080AE1CC: .4byte 0x030046B8
_080AE1D0: .4byte 0x000003FF
_080AE1D4: .4byte 0x0203B400
_080AE1D8: .4byte 0x00001326
_080AE1DC: .4byte 0x00001324
_080AE1E0: .4byte 0xFFFF0000
_080AE1E4: .4byte 0x0000FFFF
_080AE1E8:
	ldr r0, _080AE348 @ =0x00001324
	adds r0, r7, r0
	str r0, [sp, #0x3c]
	ldrh r0, [r0]
	cmp r0, #0
	bne _080AE1F6
	b _080AE370
_080AE1F6:
	movs r1, #0xa2
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r2, _080AE34C @ =0x0203B400
	mov sl, r2
	ldr r4, _080AE350 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _080AE354 @ =0x000003FF
	mov r8, r3
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	movs r5, #0xfa
	lsls r5, r5, #1
	adds r1, r5, #0
	bl Mod
	add r1, sp, #0x20
	mov sb, r1
	ldrh r1, [r1]
	subs r1, #0xfa
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r6, _080AE358 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r6
	orrs r0, r1
	str r0, [sp, #0x20]
	ldr r0, [r4]
	adds r0, #1
	mov r2, r8
	ands r0, r2
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	adds r1, r5, #0
	bl Mod
	ldr r2, [sp, #0x20]
	asrs r1, r2, #0x10
	subs r1, #0xfa
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _080AE35C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	ldr r0, [r4]
	adds r0, #1
	mov r3, r8
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	adds r1, r5, #0
	bl Mod
	mov r2, sb
	ldrh r1, [r2, #4]
	subs r1, #0xfa
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r2, #4]
	ands r0, r6
	orrs r0, r1
	str r0, [r2, #4]
	ldr r0, [sp, #0x28]
	ands r0, r6
	str r0, [sp, #0x28]
	ldr r1, [r4]
	adds r1, #1
	mov r3, r8
	ands r1, r3
	lsls r0, r1, #1
	add r0, sl
	ldrh r0, [r0]
	movs r2, #0x1f
	ands r0, r2
	adds r0, #0x10
	lsls r0, r0, #0x10
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r6
	str r0, [r2, #4]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	add r1, sl
	ldrh r3, [r1]
	movs r4, #7
	ands r3, r4
	adds r3, #8
	movs r0, #1
	str r0, [sp]
	adds r0, r7, #0
	mov r1, sb
	bl FUN_080ad2d0
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, _080AE360 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, [sp, #0x3c]
	ldrh r0, [r1]
	lsrs r2, r0, #2
	movs r0, #0x10
	subs r0, r0, r2
	asrs r0, r0, #1
	adds r0, #8
	ldr r1, _080AE364 @ =0x04000052
	lsls r0, r0, #8
	orrs r0, r2
	strh r0, [r1]
	ldr r2, [sp, #0x3c]
	ldrh r0, [r2]
	ands r4, r0
	cmp r4, #0
	bne _080AE312
	ldr r3, _080AE368 @ =0x00001326
	adds r1, r7, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #6
	bgt _080AE312
	adds r0, r2, #1
	strh r0, [r1]
_080AE312:
	ldr r1, _080AE368 @ =0x00001326
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r3, [sp, #0x60]
	adds r0, r3, r0
	str r0, [sp]
	movs r0, #1
	ldr r1, [sp, #0x30]
	ldr r2, [sp, #0x34]
	ldr r3, [sp, #0x38]
	bl Video_GenerateBGMap
	ldr r0, _080AE348 @ =0x00001324
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080AE37A
	ldr r0, _080AE36C @ =0x03002C58
	ldr r0, [r0]
	movs r1, #9
	bl FUN_080ad204
	b _080AE37A
	.align 2, 0
_080AE348: .4byte 0x00001324
_080AE34C: .4byte 0x0203B400
_080AE350: .4byte 0x030046B8
_080AE354: .4byte 0x000003FF
_080AE358: .4byte 0xFFFF0000
_080AE35C: .4byte 0x0000FFFF
_080AE360: .4byte 0x03003E78
_080AE364: .4byte 0x04000052
_080AE368: .4byte 0x00001326
_080AE36C: .4byte 0x03002C58
_080AE370:
	ldr r0, _080AE38C @ =0x03003E78
	ldr r1, _080AE390 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_080AE37A:
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AE38C: .4byte 0x03003E78
_080AE390: .4byte 0xFFFFFDFF

	thumb_func_start FUN_080ae394
FUN_080ae394: @ 0x080AE394
	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r4, r0, #0
	ldr r0, _080AE40C @ =0x0000C091
	ldr r1, _080AE410 @ =0x0000AD57
	bl GetFile
	ldr r2, _080AE414 @ =0x000004DC
	adds r1, r4, r2
	str r0, [r1]
	mov r2, sp
	adds r1, r0, #0
	ldm r1!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r1!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldr r1, [sp, #0xc]
	adds r1, r1, r0
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x10]
	adds r1, r1, r0
	str r1, [sp, #0x10]
	ldr r1, [sp, #0x14]
	adds r1, r1, r0
	str r1, [sp, #0x14]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r2, _080AE418 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #3
	movs r1, #1
	bl SetBGPrioDirect
	ldr r0, _080AE41C @ =0x000092B3
	ldr r1, _080AE420 @ =0x0000E2BA
	bl GetFile
	movs r2, #0x9c
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r0, r0, r3
	str r0, [r1]
	movs r1, #5
	ldr r5, _080AE424 @ =0x000004E4
	adds r4, r4, r5
	movs r0, #3
_080AE3F8:
	strb r1, [r4, #4]
	strb r1, [r4]
	adds r4, #1
	subs r0, #1
	cmp r0, #0
	bge _080AE3F8
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AE40C: .4byte 0x0000C091
_080AE410: .4byte 0x0000AD57
_080AE414: .4byte 0x000004DC
_080AE418: .4byte 0x03003E78
_080AE41C: .4byte 0x000092B3
_080AE420: .4byte 0x0000E2BA
_080AE424: .4byte 0x000004E4

	thumb_func_start FUN_080ae428
FUN_080ae428: @ 0x080AE428
	push {lr}
	adds r3, r0, #0
	ldr r0, _080AE468 @ =0x000004EC
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r2, r0, #1
	strh r2, [r1]
	ldr r0, _080AE46C @ =0x0000FFFF
	adds r1, r0, #0
	adds r0, r2, #0
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080AE462
	lsls r1, r2, #0x10
	lsrs r1, r1, #0x11
	movs r0, #3
	ands r1, r0
	movs r2, #0x9c
	lsls r2, r2, #3
	adds r0, r3, r2
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	ldr r1, _080AE470 @ =0x030043B0
	ldr r2, _080AE474 @ =0x04000008
	bl CpuSet
_080AE462:
	pop {r0}
	bx r0
	.align 2, 0
_080AE468: .4byte 0x000004EC
_080AE46C: .4byte 0x0000FFFF
_080AE470: .4byte 0x030043B0
_080AE474: .4byte 0x04000008

	thumb_func_start FUN_080ae478
FUN_080ae478: @ 0x080AE478
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x68
	str r0, [sp, #0x2c]
	str r1, [sp, #0x30]
	str r2, [sp, #0x34]
	adds r4, r3, #0
	ldr r5, [sp, #0x88]
	movs r0, #0
	str r0, [sp, #0x54]
	ldr r0, [sp, #0x2c]
	bl FUN_080ae428
	mov r1, sp
	ldrh r2, [r1, #0x30]
	ldr r1, _080AE4E8 @ =0x03003F60
	strh r2, [r1, #0x10]
	mov r3, sp
	ldrh r3, [r3, #0x34]
	strh r3, [r1, #0x12]
	strh r4, [r1, #0x20]
	strh r5, [r1, #0x22]
	ldr r4, [r1, #0x2c]
	mov sb, r4
	movs r5, #0x18
	ldrsh r0, [r1, r5]
	lsls r0, r0, #1
	str r0, [sp, #0x3c]
	movs r2, #0x1a
	ldrsh r0, [r1, r2]
	lsls r0, r0, #1
	str r0, [sp, #0x40]
	add r4, sp, #0x24
	ldr r3, [sp, #0x2c]
	movs r5, #0xa0
	lsls r5, r5, #3
	adds r2, r3, r5
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r5, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r5, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r6, r4, #0
	cmp r0, #0
	blt _080AE4EC
	asrs r0, r0, #8
	b _080AE4F2
	.align 2, 0
_080AE4E8: .4byte 0x03003F60
_080AE4EC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080AE4F2:
	strh r0, [r4]
	adds r1, r5, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080AE504
	asrs r0, r0, #8
	b _080AE50A
_080AE504:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080AE50A:
	adds r3, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080AE51E
	asrs r1, r0, #8
	b _080AE524
_080AE51E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_080AE524:
	subs r0, r3, r1
	strh r0, [r4, #2]
	adds r0, r3, r1
	strh r0, [r4, #4]
	movs r2, #0
	ldrsh r1, [r6, r2]
	ldr r2, _080AE554 @ =0x03003540
	movs r3, #8
	ldrsh r0, [r2, r3]
	adds r1, r1, r0
	str r1, [sp, #0x4c]
	add r0, sp, #0x24
	movs r4, #2
	ldrsh r1, [r0, r4]
	movs r5, #0xa
	ldrsh r0, [r2, r5]
	adds r1, r1, r0
	str r1, [sp, #0x50]
	ldr r0, [sp, #0x4c]
	cmp r0, #0
	blt _080AE558
	asrs r0, r0, #3
	b _080AE560
	.align 2, 0
_080AE554: .4byte 0x03003540
_080AE558:
	ldr r1, [sp, #0x4c]
	rsbs r0, r1, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080AE560:
	str r0, [sp, #0x4c]
	ldr r2, [sp, #0x50]
	cmp r2, #0
	blt _080AE56C
	asrs r0, r2, #3
	b _080AE574
_080AE56C:
	ldr r3, [sp, #0x50]
	rsbs r0, r3, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080AE574:
	movs r4, #2
	rsbs r4, r4, #0
	ands r4, r0
	ldr r5, [sp, #0x4c]
	ldr r0, [sp, #0x30]
	subs r5, r5, r0
	str r5, [sp, #0x4c]
	ldr r1, [sp, #0x34]
	subs r4, r4, r1
	str r4, [sp, #0x50]
	ldr r2, [sp, #0x2c]
	ldr r3, _080AE5E0 @ =0x000004DC
	adds r0, r2, r3
	ldr r2, [r0]
	mov r1, sp
	adds r0, r2, #0
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldr r0, [sp, #0xc]
	adds r0, r0, r2
	str r0, [sp, #0xc]
	str r0, [sp, #0x38]
	ldr r4, [sp, #0x2c]
	ldr r5, _080AE5E4 @ =0x0000132A
	adds r1, r4, r5
	movs r0, #0
	strb r0, [r1]
	movs r3, #0
	ldrb r0, [r4, #0x1e]
	cmp r3, r0
	blt _080AE5B8
	b _080AE882
_080AE5B8:
	mov r1, sp
	adds r1, #0x18
	str r1, [sp, #0x58]
_080AE5BE:
	ldr r2, [sp, #0x2c]
	movs r4, #0xc1
	lsls r4, r4, #4
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080AE5DA
	ldr r5, _080AE5E8 @ =0x000004FC
	adds r0, r2, r5
	ldrh r0, [r0]
	cmp r0, #0xa
	beq _080AE5EC
	cmp r0, #0xe
	beq _080AE5EC
_080AE5DA:
	movs r1, #5
	b _080AE604
	.align 2, 0
_080AE5E0: .4byte 0x000004DC
_080AE5E4: .4byte 0x0000132A
_080AE5E8: .4byte 0x000004FC
_080AE5EC:
	lsls r1, r3, #2
	ldr r2, [sp, #0x2c]
	ldr r4, _080AE63C @ =0x00000BE8
	adds r0, r2, r4
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, #0xcf
	ldrb r0, [r0]
	movs r1, #5
	cmp r0, #4
	bne _080AE604
	movs r1, #0
_080AE604:
	ldr r5, [sp, #0x2c]
	ldr r2, _080AE640 @ =0x000004E4
	adds r0, r5, r2
	adds r0, r0, r3
	strb r1, [r0]
	movs r4, #0x9d
	lsls r4, r4, #3
	adds r0, r5, r4
	adds r2, r0, r3
	ldrb r0, [r2]
	adds r5, r3, #1
	str r5, [sp, #0x60]
	cmp r0, r1
	bne _080AE622
	b _080AE876
_080AE622:
	cmp r1, #0
	bne _080AE62A
	movs r0, #1
	str r0, [sp, #0x54]
_080AE62A:
	strb r1, [r2]
	cmp r3, #1
	beq _080AE68E
	cmp r3, #1
	bgt _080AE644
	cmp r3, #0
	beq _080AE64E
	b _080AE6AC
	.align 2, 0
_080AE63C: .4byte 0x00000BE8
_080AE640: .4byte 0x000004E4
_080AE644:
	cmp r3, #2
	beq _080AE666
	cmp r3, #3
	beq _080AE67E
	b _080AE6AC
_080AE64E:
	ldr r2, [sp, #0x4c]
	mov ip, r2
	ldr r4, [sp, #0x50]
	mov r8, r4
	mov r7, ip
	subs r7, #7
	cmp r7, #0
	bge _080AE660
	movs r7, #0
_080AE660:
	mov r2, r8
	subs r2, #6
	b _080AE6A4
_080AE666:
	ldr r5, [sp, #0x4c]
	adds r5, #7
	mov ip, r5
	ldr r0, [sp, #0x50]
	mov r8, r0
	ldr r7, [sp, #0x4c]
	cmp r7, #0
	bge _080AE678
	movs r7, #0
_080AE678:
	mov r2, r8
	subs r2, #6
	b _080AE6A4
_080AE67E:
	ldr r2, [sp, #0x4c]
	mov ip, r2
	ldr r4, [sp, #0x50]
	adds r4, #4
	mov r8, r4
	mov r7, ip
	subs r7, #7
	b _080AE69C
_080AE68E:
	ldr r5, [sp, #0x4c]
	adds r5, #7
	mov ip, r5
	ldr r0, [sp, #0x50]
	adds r0, #4
	mov r8, r0
	ldr r7, [sp, #0x4c]
_080AE69C:
	cmp r7, #0
	bge _080AE6A2
	movs r7, #0
_080AE6A2:
	ldr r2, [sp, #0x50]
_080AE6A4:
	cmp r2, #0
	bge _080AE6B6
	movs r2, #0
	b _080AE6B6
_080AE6AC:
	movs r7, #1
	rsbs r7, r7, #0
	adds r2, r7, #0
	mov r8, r7
	mov ip, r8
_080AE6B6:
	adds r3, #1
	str r3, [sp, #0x60]
	mov r3, ip
	cmp r3, #0
	bge _080AE6C2
	b _080AE876
_080AE6C2:
	mov r4, r8
	cmp r4, #0
	bge _080AE6CA
	b _080AE876
_080AE6CA:
	cmp r7, #0x1f
	ble _080AE6D0
	b _080AE876
_080AE6D0:
	cmp r2, #0x1f
	ble _080AE6D6
	b _080AE876
_080AE6D6:
	ldr r5, _080AE72C @ =0x03003F60
	ldrh r0, [r5, #0x18]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	str r0, [sp, #0x48]
	cmp r1, #5
	bne _080AE730
	adds r6, r2, #0
	cmp r6, r8
	blt _080AE6EC
	b _080AE876
_080AE6EC:
	adds r5, r7, #0
	adds r0, r6, #2
	str r0, [sp, #0x5c]
	cmp r5, ip
	bge _080AE722
	movs r4, #0x1f
	movs r3, #0
_080AE6FA:
	ldr r1, [sp, #0x30]
	adds r2, r1, r5
	ldr r0, [sp, #0x34]
	adds r1, r0, r6
	ands r2, r4
	ands r1, r4
	lsls r0, r1, #5
	adds r0, r2, r0
	lsls r0, r0, #1
	add r0, sb
	strh r3, [r0]
	adds r1, #1
	lsls r1, r1, #5
	adds r2, r2, r1
	lsls r2, r2, #1
	add r2, sb
	strh r3, [r2]
	adds r5, #1
	cmp r5, ip
	blt _080AE6FA
_080AE722:
	ldr r6, [sp, #0x5c]
	cmp r6, r8
	blt _080AE6EC
	b _080AE876
	.align 2, 0
_080AE72C: .4byte 0x03003F60
_080AE730:
	adds r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [sp, #0x58]
	ldr r3, [sp, #0x38]
	adds r0, r0, r3
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldr r4, [sp, #0x2c]
	ldr r5, _080AE7AC @ =0x000004DC
	adds r0, r4, r5
	ldr r3, [sp, #0x58]
	ldr r1, [r3, #8]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r3, #8]
	ldr r4, _080AE7B0 @ =0x03003F60
	str r1, [r4, #0x28]
	str r1, [sp, #0x44]
	adds r6, r2, #0
	cmp r6, r8
	blt _080AE760
	b _080AE876
_080AE760:
	adds r5, r7, #0
	adds r0, r6, #2
	str r0, [sp, #0x5c]
	cmp r5, ip
	blt _080AE76C
	b _080AE86E
_080AE76C:
	movs r1, #0x1f
	mov sl, r1
_080AE770:
	ldr r2, [sp, #0x30]
	adds r4, r2, r5
	ldr r0, [sp, #0x34]
	adds r3, r0, r6
	cmp r4, #0
	blt _080AE78C
	cmp r3, #0
	blt _080AE78C
	ldr r1, [sp, #0x3c]
	cmp r4, r1
	bge _080AE78C
	ldr r2, [sp, #0x40]
	cmp r3, r2
	blt _080AE7B4
_080AE78C:
	mov r0, sl
	ands r4, r0
	ands r3, r0
	lsls r0, r3, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	strh r1, [r0]
	adds r0, r3, #1
	lsls r0, r0, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	add r0, sb
	b _080AE864
	.align 2, 0
_080AE7AC: .4byte 0x000004DC
_080AE7B0: .4byte 0x03003F60
_080AE7B4:
	cmp r4, #0
	blt _080AE7BC
	asrs r0, r4, #5
	b _080AE7C2
_080AE7BC:
	rsbs r0, r4, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_080AE7C2:
	adds r1, r0, #0
	cmp r3, #0
	blt _080AE7CC
	asrs r0, r3, #5
	b _080AE7D2
_080AE7CC:
	rsbs r0, r3, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_080AE7D2:
	ldr r2, [sp, #0x48]
	muls r0, r2, r0
	adds r0, r1, r0
	lsls r2, r0, #8
	mov r0, sl
	ands r4, r0
	ands r3, r0
	cmp r4, #0
	blt _080AE7E8
	asrs r0, r4, #1
	b _080AE7EE
_080AE7E8:
	rsbs r0, r4, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080AE7EE:
	adds r1, r0, #0
	cmp r3, #0
	blt _080AE7F8
	asrs r0, r3, #1
	b _080AE7FE
_080AE7F8:
	rsbs r0, r3, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080AE7FE:
	lsls r0, r0, #4
	adds r1, r2, r1
	adds r1, r1, r0
	lsls r1, r1, #1
	ldr r2, [sp, #0x44]
	adds r1, r1, r2
	ldrh r2, [r1]
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	bne _080AE840
	lsls r1, r3, #5
	adds r1, r4, r1
	lsls r1, r1, #1
	add r1, sb
	str r1, [sp, #0x64]
	ldr r1, _080AE83C @ =0x03003F60
	ldr r0, [r1, #0x24]
	lsls r2, r2, #3
	adds r2, r2, r0
	ldrh r0, [r2]
	ldr r1, [sp, #0x64]
	strh r0, [r1]
	adds r0, r3, #1
	lsls r0, r0, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	add r0, sb
	ldrh r1, [r2, #4]
	b _080AE864
	.align 2, 0
_080AE83C: .4byte 0x03003F60
_080AE840:
	lsls r1, r3, #5
	adds r1, r4, r1
	lsls r1, r1, #1
	add r1, sb
	str r1, [sp, #0x64]
	ldr r1, _080AE8A0 @ =0x03003F60
	ldr r0, [r1, #0x24]
	lsls r2, r2, #3
	adds r2, r2, r0
	ldrh r0, [r2, #2]
	ldr r1, [sp, #0x64]
	strh r0, [r1]
	adds r0, r3, #1
	lsls r0, r0, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	add r0, sb
	ldrh r1, [r2, #6]
_080AE864:
	strh r1, [r0]
	adds r5, #1
	cmp r5, ip
	bge _080AE86E
	b _080AE770
_080AE86E:
	ldr r6, [sp, #0x5c]
	cmp r6, r8
	bge _080AE876
	b _080AE760
_080AE876:
	ldr r3, [sp, #0x60]
	ldr r2, [sp, #0x2c]
	ldrb r2, [r2, #0x1e]
	cmp r3, r2
	bge _080AE882
	b _080AE5BE
_080AE882:
	ldr r3, [sp, #0x54]
	cmp r3, #0
	beq _080AE88E
	movs r0, #0xf5
	bl PlaySound_082406e0
_080AE88E:
	add sp, #0x68
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AE8A0: .4byte 0x03003F60

	thumb_func_start FUN_080ae8a4
FUN_080ae8a4: @ 0x080AE8A4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r8, r0
	ldr r3, _080AE8D4 @ =0x030047C8
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r2, _080AE8D8 @ =0x03003540
	movs r4, #8
	ldrsh r0, [r2, r4]
	adds r6, r1, r0
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r3, #0xa
	ldrsh r0, [r2, r3]
	adds r5, r1, r0
	adds r0, r6, #0
	subs r0, #0x80
	cmp r0, #0
	blt _080AE8DC
	asrs r1, r0, #3
	b _080AE8E2
	.align 2, 0
_080AE8D4: .4byte 0x030047C8
_080AE8D8: .4byte 0x03003540
_080AE8DC:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r1, r0, #0
_080AE8E2:
	adds r7, r1, #0
	adds r0, r5, #0
	subs r0, #0x80
	cmp r0, #0
	blt _080AE8F0
	asrs r0, r0, #3
	b _080AE8F6
_080AE8F0:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080AE8F6:
	movs r4, #2
	rsbs r4, r4, #0
	ands r4, r0
	subs r6, #0x78
	subs r5, #0x5a
	str r5, [sp]
	mov r0, r8
	adds r1, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080adfa0
	str r5, [sp]
	mov r0, r8
	adds r1, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080ae478
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080ae928
FUN_080ae928: @ 0x080AE928
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	ldr r0, _080AE984 @ =0x00001348
	adds r3, r5, r0
	ldr r2, _080AE988 @ =0x0000134A
	adds r1, r5, r2
	ldrh r0, [r3]
	ldrh r2, [r1]
	cmp r0, r2
	bhs _080AE99C
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	bhs _080AE94E
	b _080AEAD0
_080AE94E:
	ldr r0, _080AE98C @ =0x03002BE0
	ldr r2, [r0]
	movs r3, #0x2c
	ldrsh r0, [r2, r3]
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r1, r5, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	ldr r3, _080AE990 @ =0x00000504
	adds r2, r5, r3
	movs r3, #0
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	ldr r2, _080AE994 @ =0x00001352
	adds r1, r5, r2
	strh r0, [r1]
	ldr r3, _080AE998 @ =0x0000134C
	adds r1, r5, r3
	movs r0, #0
	strh r0, [r1]
	b _080AEAD0
	.align 2, 0
_080AE984: .4byte 0x00001348
_080AE988: .4byte 0x0000134A
_080AE98C: .4byte 0x03002BE0
_080AE990: .4byte 0x00000504
_080AE994: .4byte 0x00001352
_080AE998: .4byte 0x0000134C
_080AE99C:
	ldr r0, _080AE9F4 @ =0x0000134C
	adds r2, r5, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2f
	bls _080AE9B0
	b _080AEACC
_080AE9B0:
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	beq _080AE9BA
	b _080AEAD0
_080AE9BA:
	ldrh r0, [r2]
	lsls r6, r0, #4
	ldr r2, _080AE9F8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AE9FC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080AEA00 @ =0x0203B400
	adds r0, r0, r1
	ldrh r4, [r0]
	ldr r3, _080AEA04 @ =0x085B0A08
	ldr r1, _080AEA08 @ =0x00001352
	adds r0, r5, r1
	ldrh r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r7, r2, #0
	cmp r0, #0
	blt _080AEA0C
	asrs r2, r0, #0xc
	b _080AEA12
	.align 2, 0
_080AE9F4: .4byte 0x0000134C
_080AE9F8: .4byte 0x030046B8
_080AE9FC: .4byte 0x000003FF
_080AEA00: .4byte 0x0203B400
_080AEA04: .4byte 0x085B0A08
_080AEA08: .4byte 0x00001352
_080AEA0C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080AEA12:
	movs r0, #0xa0
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r0, #0x7f
	ands r4, r0
	ldrh r1, [r1]
	adds r0, r4, r1
	adds r1, r2, #0
	subs r1, #0x40
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r2, _080AEA60 @ =0x00000502
	adds r1, r5, r2
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #0x14]
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080AEA64 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080AEA68 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r1, _080AEA6C @ =0x00001352
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	cmp r0, #0
	blt _080AEA70
	asrs r3, r0, #0xc
	b _080AEA76
	.align 2, 0
_080AEA60: .4byte 0x00000502
_080AEA64: .4byte 0x000003FF
_080AEA68: .4byte 0x0203B400
_080AEA6C: .4byte 0x00001352
_080AEA70:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080AEA76:
	ldr r0, _080AEAC0 @ =0x00000504
	adds r1, r5, r0
	movs r0, #0x7f
	ands r2, r0
	ldrh r1, [r1]
	adds r1, r2, r1
	adds r0, r3, #0
	subs r0, #0x40
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080AEAC4 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	movs r2, #0x80
	lsls r2, r2, #1
	movs r0, #2
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	ldr r1, _080AEAC8 @ =0x0000134E
	adds r0, r5, r1
	ldrh r0, [r0]
	str r0, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	add r3, sp, #0x14
	str r3, [sp, #0x10]
	movs r0, #1
	movs r1, #0
	movs r3, #2
	bl FUN_08056774
	b _080AEAD0
	.align 2, 0
_080AEAC0: .4byte 0x00000504
_080AEAC4: .4byte 0xFFFF0000
_080AEAC8: .4byte 0x0000134E
_080AEACC:
	movs r0, #0
	strh r0, [r3]
_080AEAD0:
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080aead8
FUN_080aead8: @ 0x080AEAD8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _080AEB08 @ =0x00001348
	adds r3, r5, r0
	ldr r2, _080AEB0C @ =0x0000134A
	adds r1, r5, r2
	ldrh r0, [r3]
	ldrh r2, [r1]
	cmp r0, r2
	bhs _080AEB14
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _080AEB90
	ldr r3, _080AEB10 @ =0x0000134C
	adds r1, r5, r3
	movs r0, #0
	strh r0, [r1]
	b _080AEB90
	.align 2, 0
_080AEB08: .4byte 0x00001348
_080AEB0C: .4byte 0x0000134A
_080AEB10: .4byte 0x0000134C
_080AEB14:
	ldr r0, _080AEB78 @ =0x0000134C
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r2, r0, #1
	strh r2, [r1]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bhi _080AEB8C
	movs r0, #0x1f
	ands r2, r0
	cmp r2, #0
	bne _080AEB90
	ldr r0, _080AEB7C @ =0x030046B8
	ldr r1, [r0]
	adds r1, #1
	ldr r2, _080AEB80 @ =0x000003FF
	ands r1, r2
	str r1, [r0]
	lsls r1, r1, #1
	ldr r2, _080AEB84 @ =0x0203B400
	adds r1, r1, r2
	ldrb r4, [r1]
	movs r6, #7
_080AEB44:
	movs r3, #0x9b
	lsls r3, r3, #5
	adds r0, r5, r3
	ldr r0, [r0]
	ldr r2, _080AEB88 @ =0x0000134E
	adds r1, r5, r2
	ldrh r1, [r1]
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r2, r5, r3
	str r2, [sp]
	adds r2, r4, #0
	movs r3, #0x18
	bl FUN_0805d80c
	adds r4, #0x20
	movs r0, #0xff
	ands r4, r0
	subs r6, #1
	cmp r6, #0
	bge _080AEB44
	adds r0, #0x7b
	bl PlaySound_082406e0
	b _080AEB90
	.align 2, 0
_080AEB78: .4byte 0x0000134C
_080AEB7C: .4byte 0x030046B8
_080AEB80: .4byte 0x000003FF
_080AEB84: .4byte 0x0203B400
_080AEB88: .4byte 0x0000134E
_080AEB8C:
	movs r0, #0
	strh r0, [r3]
_080AEB90:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080aeb98
FUN_080aeb98: @ 0x080AEB98
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r4, r0, #0
	ldr r0, _080AEBF8 @ =0x00001348
	adds r1, r4, r0
	ldr r3, _080AEBFC @ =0x0000134A
	adds r2, r4, r3
	ldrh r0, [r1]
	ldrh r5, [r2]
	cmp r0, r5
	bhs _080AEC10
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r2, [r2]
	cmp r0, r2
	bhs _080AEBC4
	b _080AEE04
_080AEBC4:
	ldr r0, _080AEC00 @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r1, r4, r3
	movs r5, #0
	ldrsh r1, [r1, r5]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	ldr r5, _080AEC04 @ =0x00000504
	adds r2, r4, r5
	movs r3, #0
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	ldr r5, _080AEC08 @ =0x00001352
	adds r1, r4, r5
	strh r0, [r1]
	ldr r0, _080AEC0C @ =0x0000134C
	adds r1, r4, r0
	b _080AEE00
	.align 2, 0
_080AEBF8: .4byte 0x00001348
_080AEBFC: .4byte 0x0000134A
_080AEC00: .4byte 0x03002BE0
_080AEC04: .4byte 0x00000504
_080AEC08: .4byte 0x00001352
_080AEC0C: .4byte 0x0000134C
_080AEC10:
	ldr r0, _080AEC50 @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r1, r4, r3
	movs r5, #0
	ldrsh r1, [r1, r5]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	ldr r5, _080AEC54 @ =0x00000504
	adds r2, r4, r5
	movs r3, #0
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	ldr r5, _080AEC58 @ =0x00001352
	adds r3, r4, r5
	ldrh r2, [r3]
	ldr r5, _080AEC5C @ =0xFFFFFF00
	adds r1, r2, r5
	subs r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	cmp r0, #0x7f
	bgt _080AEC60
	adds r0, r2, #1
	b _080AEC66
	.align 2, 0
_080AEC50: .4byte 0x03002BE0
_080AEC54: .4byte 0x00000504
_080AEC58: .4byte 0x00001352
_080AEC5C: .4byte 0xFFFFFF00
_080AEC60:
	adds r0, r2, #0
	adds r0, #0xff
	movs r1, #0xff
_080AEC66:
	ands r0, r1
	strh r0, [r3]
	ldr r0, _080AED04 @ =0x0000134C
	adds r5, r4, r0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bls _080AEC7E
	b _080AEDFC
_080AEC7E:
	ldrh r0, [r5]
	movs r1, #7
	bl Mod
	cmp r0, #0
	beq _080AEC8C
	b _080AEE04
_080AEC8C:
	ldr r7, _080AED08 @ =0x030046B8
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080AED0C @ =0x000003FF
	mov r8, r1
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _080AED10 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x30
	bl Mod
	ldr r3, _080AED14 @ =0x00001352
	adds r1, r4, r3
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r6, r0, #0
	subs r6, #0x18
	movs r3, #0xff
	mov sb, r3
	ands r6, r3
	ldrh r0, [r5]
	movs r1, #0x2a
	bl Mod
	cmp r0, #0
	bne _080AED68
	ldr r0, [r7]
	adds r0, #1
	mov r5, r8
	ands r0, r5
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080AED10 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	add r3, sp, #0x14
	adds r5, r0, #0
	adds r5, #8
	ldr r1, _080AED18 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	mov r2, sb
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _080AED1C
	asrs r2, r0, #0xc
	b _080AED22
	.align 2, 0
_080AED04: .4byte 0x0000134C
_080AED08: .4byte 0x030046B8
_080AED0C: .4byte 0x000003FF
_080AED10: .4byte 0x0203B400
_080AED14: .4byte 0x00001352
_080AED18: .4byte 0x085B0A08
_080AED1C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080AED22:
	movs r0, #0
	strh r2, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _080AED3A
	asrs r0, r0, #0xc
	b _080AED40
_080AED3A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AED40:
	strh r0, [r3, #4]
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r2, #0xa
	str r2, [sp]
	ldr r3, _080AED64 @ =0x0000134E
	adds r1, r4, r3
	ldrh r1, [r1]
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #8
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	add r1, sp, #0x14
	movs r2, #8
	b _080AEDEE
	.align 2, 0
_080AED64: .4byte 0x0000134E
_080AED68:
	ldr r0, [r7]
	adds r0, #1
	mov r5, r8
	ands r0, r5
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080AEDA0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	add r3, sp, #0x14
	adds r5, r0, #0
	adds r5, #0xc
	ldr r1, _080AEDA4 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	mov r2, sb
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _080AEDA8
	asrs r2, r0, #0xc
	b _080AEDAE
	.align 2, 0
_080AEDA0: .4byte 0x0203B400
_080AEDA4: .4byte 0x085B0A08
_080AEDA8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080AEDAE:
	movs r0, #0
	strh r2, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _080AEDC6
	asrs r0, r0, #0xc
	b _080AEDCC
_080AEDC6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AEDCC:
	strh r0, [r3, #4]
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r2, #0xa
	str r2, [sp]
	ldr r3, _080AEDF8 @ =0x0000134E
	adds r1, r4, r3
	ldrh r1, [r1]
	str r1, [sp, #4]
	movs r1, #5
	str r1, [sp, #8]
	movs r1, #8
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	add r1, sp, #0x14
	movs r2, #4
_080AEDEE:
	movs r3, #0x96
	bl FUN_080df148
	b _080AEE04
	.align 2, 0
_080AEDF8: .4byte 0x0000134E
_080AEDFC:
	ldr r5, _080AEE14 @ =0x00001348
	adds r1, r4, r5
_080AEE00:
	movs r0, #0
	strh r0, [r1]
_080AEE04:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AEE14: .4byte 0x00001348

	thumb_func_start FUN_080aee18
FUN_080aee18: @ 0x080AEE18
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, _080AEE60 @ =0x00001348
	adds r4, r6, r0
	ldr r1, _080AEE64 @ =0x0000134A
	adds r5, r6, r1
	ldrh r1, [r4]
	ldrh r2, [r5]
	cmp r1, r2
	bhs _080AEE6C
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r1, r0
	bne _080AEE4A
	movs r1, #0x9b
	lsls r1, r1, #5
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_0805b1a0
_080AEE4A:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r5, [r5]
	cmp r0, r5
	bhs _080AEE5C
	b _080AEFC0
_080AEE5C:
	ldr r2, _080AEE68 @ =0x0000134C
	b _080AEFBA
	.align 2, 0
_080AEE60: .4byte 0x00001348
_080AEE64: .4byte 0x0000134A
_080AEE68: .4byte 0x0000134C
_080AEE6C:
	ldr r1, _080AEEC8 @ =0x0000134C
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080AEE78
	b _080AEFA6
_080AEE78:
	ldr r0, _080AEECC @ =0x030046B8
	ldr r1, [r0]
	adds r1, #1
	ldr r2, _080AEED0 @ =0x000003FF
	ands r1, r2
	str r1, [r0]
	lsls r1, r1, #1
	ldr r2, _080AEED4 @ =0x0203B400
	adds r1, r1, r2
	ldrb r4, [r1]
	ldr r1, _080AEED8 @ =0x085B0A08
	mov sl, r1
	add r5, sp, #8
	adds r7, r0, #0
	movs r2, #2
	mov sb, r2
	movs r0, #0xff
	mov r8, r0
_080AEE9C:
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r1, _080AEED8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	mov r2, r8
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	cmp r0, #0
	blt _080AEEDC
	asrs r1, r0, #0xc
	b _080AEEE2
	.align 2, 0
_080AEEC8: .4byte 0x0000134C
_080AEECC: .4byte 0x030046B8
_080AEED0: .4byte 0x000003FF
_080AEED4: .4byte 0x0203B400
_080AEED8: .4byte 0x085B0A08
_080AEEDC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080AEEE2:
	ldrh r0, [r5]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080AEF34 @ =0xFFFF0000
	ldr r3, [sp, #8]
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #8]
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080AEF38 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _080AEF3C @ =0x0203B400
	adds r0, r0, r2
	ldrh r2, [r0]
	asrs r1, r3, #0x10
	adds r1, #0x80
	movs r0, #0x1f
	ands r2, r0
	adds r1, r1, r2
	lsls r1, r1, #0x10
	ldr r0, _080AEF40 @ =0x0000FFFF
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #8]
	adds r0, r4, #0
	mov r1, r8
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #6
	cmp r0, #0
	blt _080AEF44
	asrs r0, r0, #0xc
	b _080AEF4A
	.align 2, 0
_080AEF34: .4byte 0xFFFF0000
_080AEF38: .4byte 0x000003FF
_080AEF3C: .4byte 0x0203B400
_080AEF40: .4byte 0x0000FFFF
_080AEF44:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AEF4A:
	ldrh r1, [r5, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080AEFD0 @ =0xFFFF0000
	ldr r0, [r5, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	movs r1, #0x9b
	lsls r1, r1, #5
	adds r0, r6, r1
	ldr r0, [r0]
	ldr r1, _080AEFD4 @ =0x03002BE0
	ldr r2, [r1]
	adds r2, #0x2c
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0xc8
	str r1, [sp, #4]
	add r1, sp, #8
	adds r3, r4, #0
	bl FUN_0805b0b0
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080AEFD8 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _080AEFDC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, r0, r4
	adds r4, r0, #0
	adds r4, #0x4e
	mov r0, r8
	ands r4, r0
	subs r1, #0x10
	add sb, r1
	mov r2, sb
	cmp r2, #0
	blt _080AEFA6
	b _080AEE9C
_080AEFA6:
	ldr r0, _080AEFE0 @ =0x0000134C
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3c
	bls _080AEFC0
	ldr r2, _080AEFE4 @ =0x00001348
_080AEFBA:
	adds r1, r6, r2
	movs r0, #0
	strh r0, [r1]
_080AEFC0:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AEFD0: .4byte 0xFFFF0000
_080AEFD4: .4byte 0x03002BE0
_080AEFD8: .4byte 0x000003FF
_080AEFDC: .4byte 0x0203B400
_080AEFE0: .4byte 0x0000134C
_080AEFE4: .4byte 0x00001348

	thumb_func_start FUN_080aefe8
FUN_080aefe8: @ 0x080AEFE8
	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r5, r0, #0
	ldr r0, _080AF018 @ =0x00001348
	adds r3, r5, r0
	ldr r2, _080AF01C @ =0x0000134A
	adds r1, r5, r2
	ldrh r0, [r3]
	ldrh r2, [r1]
	cmp r0, r2
	bhs _080AF024
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _080AF0A2
	ldr r3, _080AF020 @ =0x0000134C
	adds r1, r5, r3
	movs r0, #0
	strh r0, [r1]
	b _080AF0A2
	.align 2, 0
_080AF018: .4byte 0x00001348
_080AF01C: .4byte 0x0000134A
_080AF020: .4byte 0x0000134C
_080AF024:
	ldr r0, _080AF090 @ =0x0000134C
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r2, r0, #1
	movs r6, #0
	strh r2, [r1]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xff
	bhi _080AF0A0
	movs r0, #0x1f
	ands r2, r0
	cmp r2, #0
	bne _080AF0A2
	ldr r0, _080AF094 @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r4, r5, r3
	movs r3, #0
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	ldr r3, _080AF098 @ =0x00000504
	adds r2, r5, r3
	movs r3, #0
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r1, r0, #0
	movs r2, #0x9b
	lsls r2, r2, #5
	adds r0, r5, r2
	ldr r0, [r0]
	ldr r3, _080AF09C @ =0x0000134E
	adds r2, r5, r3
	ldrh r3, [r2]
	movs r2, #0xa
	str r2, [sp]
	movs r2, #0x78
	str r2, [sp, #4]
	movs r2, #0x5a
	str r2, [sp, #8]
	str r6, [sp, #0xc]
	str r4, [sp, #0x10]
	movs r2, #0xf
	bl FUN_0805f320
	b _080AF0A2
	.align 2, 0
_080AF090: .4byte 0x0000134C
_080AF094: .4byte 0x03002BE0
_080AF098: .4byte 0x00000504
_080AF09C: .4byte 0x0000134E
_080AF0A0:
	strh r6, [r3]
_080AF0A2:
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080af0ac
FUN_080af0ac: @ 0x080AF0AC
	push {lr}
	adds r2, r0, #0
	ldr r1, _080AF0C4 @ =0x0000135C
	adds r0, r2, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _080AF0C0
	adds r0, r2, #0
	bl _call_via_r1
_080AF0C0:
	pop {r0}
	bx r0
	.align 2, 0
_080AF0C4: .4byte 0x0000135C

	thumb_func_start FUN_080af0c8
FUN_080af0c8: @ 0x080AF0C8
	push {lr}
	adds r1, r0, #0
	ldr r2, _080AF0DC @ =0x00001336
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #3
	beq _080AF0E0
	cmp r0, #4
	beq _080AF0E6
	b _080AF0F2
	.align 2, 0
_080AF0DC: .4byte 0x00001336
_080AF0E0:
	bl FUN_080df478
	b _080AF0F2
_080AF0E6:
	movs r2, #0x9b
	lsls r2, r2, #5
	adds r0, r1, r2
	ldr r0, [r0]
	bl FUN_0805b1a0
_080AF0F2:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080af0f8
FUN_080af0f8: @ 0x080AF0F8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080AF110 @ =0x00001336
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bhi _080AF1EC
	lsls r0, r0, #2
	ldr r1, _080AF114 @ =_080AF118
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080AF110: .4byte 0x00001336
_080AF114: .4byte _080AF118
_080AF118: @ jump table
	.4byte _080AF130 @ case 0
	.4byte _080AF14C @ case 1
	.4byte _080AF158 @ case 2
	.4byte _080AF180 @ case 3
	.4byte _080AF198 @ case 4
	.4byte _080AF1C0 @ case 5
_080AF130:
	ldr r2, _080AF140 @ =0x0000135C
	adds r1, r4, r2
	ldr r0, _080AF144 @ =FUN_080ae928
	str r0, [r1]
	ldr r0, _080AF148 @ =0x0000134A
	adds r1, r4, r0
	b _080AF170
	.align 2, 0
_080AF140: .4byte 0x0000135C
_080AF144: .4byte FUN_080ae928
_080AF148: .4byte 0x0000134A
_080AF14C:
	ldr r2, _080AF154 @ =0x0000135C
	adds r1, r4, r2
	b _080AF1F0
	.align 2, 0
_080AF154: .4byte 0x0000135C
_080AF158:
	bl FUN_0805d79c
	movs r2, #0x9b
	lsls r2, r2, #5
	adds r1, r4, r2
	str r0, [r1]
	ldr r0, _080AF178 @ =0x0000135C
	adds r1, r4, r0
	ldr r0, _080AF17C @ =FUN_080aead8
	str r0, [r1]
	subs r2, #0x16
	adds r1, r4, r2
_080AF170:
	movs r0, #0xb4
	lsls r0, r0, #1
	strh r0, [r1]
	b _080AF1F4
	.align 2, 0
_080AF178: .4byte 0x0000135C
_080AF17C: .4byte FUN_080aead8
_080AF180:
	ldr r0, _080AF18C @ =0x0000135C
	adds r1, r4, r0
	ldr r0, _080AF190 @ =FUN_080aeb98
	str r0, [r1]
	ldr r2, _080AF194 @ =0x0000134A
	b _080AF1D8
	.align 2, 0
_080AF18C: .4byte 0x0000135C
_080AF190: .4byte FUN_080aeb98
_080AF194: .4byte 0x0000134A
_080AF198:
	ldr r1, _080AF1B4 @ =0x0000134E
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0x32
	bl FUN_0805b068
	movs r2, #0x9b
	lsls r2, r2, #5
	adds r1, r4, r2
	str r0, [r1]
	ldr r0, _080AF1B8 @ =0x0000135C
	adds r1, r4, r0
	ldr r0, _080AF1BC @ =FUN_080aee18
	b _080AF1D4
	.align 2, 0
_080AF1B4: .4byte 0x0000134E
_080AF1B8: .4byte 0x0000135C
_080AF1BC: .4byte FUN_080aee18
_080AF1C0:
	movs r0, #0x5a
	bl FUN_0805f2dc
	movs r2, #0x9b
	lsls r2, r2, #5
	adds r1, r4, r2
	str r0, [r1]
	ldr r0, _080AF1E4 @ =0x0000135C
	adds r1, r4, r0
	ldr r0, _080AF1E8 @ =FUN_080aefe8
_080AF1D4:
	str r0, [r1]
	subs r2, #0x16
_080AF1D8:
	adds r1, r4, r2
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
	b _080AF1F4
	.align 2, 0
_080AF1E4: .4byte 0x0000135C
_080AF1E8: .4byte FUN_080aefe8
_080AF1EC:
	ldr r0, _080AF1FC @ =0x0000135C
	adds r1, r4, r0
_080AF1F0:
	movs r0, #0
	str r0, [r1]
_080AF1F4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080AF1FC: .4byte 0x0000135C

	thumb_func_start FUN_080af200
FUN_080af200: @ 0x080AF200
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x7f
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080AF2E8
	adds r4, r2, #0
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r1, [r0]
	ldr r2, _080AF24C @ =0x0000068D
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #0xf3
	bl PlaySound_082406e0
	ldrh r1, [r5, #0x3c]
	ldrh r0, [r6, #0x3c]
	subs r1, r1, r0
	cmp r1, #0
	bge _080AF230
	movs r1, #0
_080AF230:
	movs r0, #1
	ldr r2, [r5, #0x34]
	ands r0, r2
	cmp r0, #0
	beq _080AF254
	adds r1, #0x14
	ldr r2, _080AF250 @ =0x0000068E
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #0xd2
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x20
	b _080AF2C2
	.align 2, 0
_080AF24C: .4byte 0x0000068D
_080AF250: .4byte 0x0000068E
_080AF254:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _080AF274
	adds r1, #0x64
	ldr r2, _080AF270 @ =0x0000068E
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #0xd2
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x18
	b _080AF2C2
	.align 2, 0
_080AF270: .4byte 0x0000068E
_080AF274:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _080AF290
	adds r1, #0x32
	ldr r2, _080AF28C @ =0x0000068E
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #0xd2
	lsls r0, r0, #3
	adds r1, r4, r0
	b _080AF2C0
	.align 2, 0
_080AF28C: .4byte 0x0000068E
_080AF290:
	movs r3, #0x10
	ands r3, r2
	cmp r3, #0
	beq _080AF2AC
	adds r1, #0x64
	ldr r2, _080AF2A8 @ =0x0000068E
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #0xd2
	lsls r0, r0, #3
	adds r1, r4, r0
	b _080AF2C0
	.align 2, 0
_080AF2A8: .4byte 0x0000068E
_080AF2AC:
	movs r0, #0x40
	ands r2, r0
	cmp r2, #0
	beq _080AF2C4
	ldr r1, _080AF2F0 @ =0x0000068E
	adds r0, r4, r1
	strh r3, [r0]
	movs r2, #0xd2
	lsls r2, r2, #3
	adds r1, r4, r2
_080AF2C0:
	movs r0, #0x80
_080AF2C2:
	strh r0, [r1]
_080AF2C4:
	movs r1, #0xcf
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #5
	bne _080AF2DA
	movs r2, #0xd2
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0
	strh r0, [r1]
_080AF2DA:
	ldr r0, _080AF2F0 @ =0x0000068E
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0xc8
	bls _080AF2E8
	movs r0, #0xc8
	strh r0, [r1]
_080AF2E8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AF2F0: .4byte 0x0000068E

	thumb_func_start FUN_080af2f4
FUN_080af2f4: @ 0x080AF2F4
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	movs r4, #1
	adds r1, r3, #0
	adds r1, #0x68
	movs r2, #7
_080AF308:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x68
	subs r2, #1
	cmp r2, #0
	bge _080AF308
	movs r4, #1
	movs r0, #0xea
	lsls r0, r0, #2
	adds r1, r3, r0
	movs r2, #5
_080AF320:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x68
	subs r2, #1
	cmp r2, #0
	bge _080AF320
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080af334
FUN_080af334: @ 0x080AF334
	push {lr}
	mov ip, r0
	ldr r0, [r0]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2]
	adds r2, #0x68
	movs r3, #7
_080AF348:
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r2, #0x68
	subs r3, #1
	cmp r3, #0
	bge _080AF348
	movs r2, #2
	rsbs r2, r2, #0
	movs r1, #0xea
	lsls r1, r1, #2
	add r1, ip
	movs r3, #5
_080AF362:
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r1, #0x68
	subs r3, #1
	cmp r3, #0
	bge _080AF362
	pop {r0}
	bx r0

	thumb_func_start FUN_080af374
FUN_080af374: @ 0x080AF374
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r3, r4, r0
	ldrh r0, [r3]
	cmp r0, #0
	bne _080AF3A2
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r2, r4, r1
	adds r1, #0x58
	adds r0, r4, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, _080AF3E0 @ =0x0000061A
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
_080AF3A2:
	cmp r5, #2
	bne _080AF3C2
	ldrh r0, [r3]
	cmp r0, #2
	beq _080AF3C2
	ldr r1, _080AF3E4 @ =0x000006AC
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_080adf50
	ldr r0, _080AF3E8 @ =0x03002C58
	ldr r0, [r0]
	ldr r3, _080AF3EC @ =0x0000133E
	adds r0, r0, r3
	movs r1, #1
	strb r1, [r0]
_080AF3C2:
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r2, r4, r0
	movs r1, #0
	strh r5, [r2]
	ldr r3, _080AF3F0 @ =0x0000067A
	adds r0, r4, r3
	strh r1, [r0]
	ldrh r0, [r2]
	cmp r0, #0
	bne _080AF3F4
	adds r0, r4, #0
	bl FUN_080af2f4
	b _080AF3FA
	.align 2, 0
_080AF3E0: .4byte 0x0000061A
_080AF3E4: .4byte 0x000006AC
_080AF3E8: .4byte 0x03002C58
_080AF3EC: .4byte 0x0000133E
_080AF3F0: .4byte 0x0000067A
_080AF3F4:
	adds r0, r4, #0
	bl FUN_080af334
_080AF3FA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080af400
FUN_080af400: @ 0x080AF400
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0xce
	lsls r2, r2, #3
	adds r0, r5, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r7, r1, r0
	ldr r1, _080AF464 @ =0x0000061C
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _080AF468 @ =0x00000674
	adds r0, r5, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r6, r1, r0
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_0823785c
	adds r4, r0, #0
	lsls r1, r4, #4
	ldr r2, _080AF46C @ =0x0000067C
	adds r0, r5, r2
	movs r2, #0
	strh r1, [r0]
	ldr r1, _080AF470 @ =0x0000067E
	adds r0, r5, r1
	strh r2, [r0]
	adds r0, r4, #0
	subs r0, #0x20
	cmp r0, #0x3f
	bls _080AF454
	subs r0, #0x80
	cmp r0, #0x3f
	bhi _080AF478
_080AF454:
	lsls r0, r6, #0xc
	ldr r2, _080AF474 @ =0x085B0A08
	movs r1, #0xff
	ands r1, r4
	lsls r1, r1, #1
	adds r1, r1, r2
	b _080AF488
	.align 2, 0
_080AF464: .4byte 0x0000061C
_080AF468: .4byte 0x00000674
_080AF46C: .4byte 0x0000067C
_080AF470: .4byte 0x0000067E
_080AF474: .4byte 0x085B0A08
_080AF478:
	lsls r0, r7, #0xc
	ldr r3, _080AF49C @ =0x085B0A08
	adds r1, r4, #0
	adds r1, #0x40
	movs r2, #0xff
	ands r1, r2
	lsls r1, r1, #1
	adds r1, r1, r3
_080AF488:
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl Div
	ldr r2, _080AF4A0 @ =0x00000684
	adds r1, r5, r2
	strh r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AF49C: .4byte 0x085B0A08
_080AF4A0: .4byte 0x00000684

	thumb_func_start FUN_080af4a4
FUN_080af4a4: @ 0x080AF4A4
	push {lr}
	ldr r3, _080AF4C4 @ =0x000006AC
	adds r0, r0, r3
	ldr r0, [r0]
	lsls r1, r1, #2
	ldr r3, _080AF4C8 @ =0x00000BE8
	adds r0, r0, r3
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, r2
	beq _080AF4CC
	movs r0, #0
	b _080AF4CE
	.align 2, 0
_080AF4C4: .4byte 0x000006AC
_080AF4C8: .4byte 0x00000BE8
_080AF4CC:
	movs r0, #1
_080AF4CE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080af4d4
FUN_080af4d4: @ 0x080AF4D4
	push {lr}
	ldr r3, _080AF4F0 @ =0x000006AC
	adds r0, r0, r3
	ldr r0, [r0]
	lsls r1, r1, #2
	ldr r3, _080AF4F4 @ =0x00000BE8
	adds r0, r0, r3
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r2, #0
	bl FUN_080b283c
	pop {r0}
	bx r0
	.align 2, 0
_080AF4F0: .4byte 0x000006AC
_080AF4F4: .4byte 0x00000BE8

	thumb_func_start FUN_080af4f8
FUN_080af4f8: @ 0x080AF4F8
	ldr r1, _080AF504 @ =0x000006AC
	adds r0, r0, r1
	ldr r0, [r0]
	ldrb r0, [r0, #0x1f]
	bx lr
	.align 2, 0
_080AF504: .4byte 0x000006AC

	thumb_func_start FUN_080af508
FUN_080af508: @ 0x080AF508
	ldr r1, _080AF518 @ =0x000006AC
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xc1
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_080AF518: .4byte 0x000006AC

	thumb_func_start FUN_080af51c
FUN_080af51c: @ 0x080AF51C
	ldr r2, _080AF534 @ =0x000006AC
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r1, r1, #2
	ldr r2, _080AF538 @ =0x00000BE8
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, #0xe2
	movs r1, #1
	strh r1, [r0]
	bx lr
	.align 2, 0
_080AF534: .4byte 0x000006AC
_080AF538: .4byte 0x00000BE8

	thumb_func_start FUN_080af53c
FUN_080af53c: @ 0x080AF53C
	push {r4, r5, lr}
	ldr r2, _080AF550 @ =0x000006AC
	adds r1, r0, r2
	ldr r5, [r1]
	bl FUN_080af4f8
	adds r3, r0, #0
	cmp r3, #0
	bne _080AF558
	b _080AF59C
	.align 2, 0
_080AF550: .4byte 0x000006AC
_080AF554:
	adds r0, r3, #0
	b _080AF5A0
_080AF558:
	ldr r2, _080AF5A8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AF5AC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080AF5B0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #4
	adds r1, r3, #0
	bl Mod
	adds r2, r0, #0
	movs r3, #0
	ldrb r0, [r5, #0x1e]
	cmp r3, r0
	bge _080AF59C
	adds r4, r0, #0
	ldr r0, _080AF5B4 @ =0x00000BE8
	adds r1, r5, r0
_080AF584:
	ldr r0, [r1]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #4
	bne _080AF594
	cmp r2, #0
	beq _080AF554
	subs r2, #1
_080AF594:
	adds r1, #4
	adds r3, #1
	cmp r3, r4
	blt _080AF584
_080AF59C:
	movs r0, #1
	rsbs r0, r0, #0
_080AF5A0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080AF5A8: .4byte 0x030046B8
_080AF5AC: .4byte 0x000003FF
_080AF5B0: .4byte 0x0203B400
_080AF5B4: .4byte 0x00000BE8

	thumb_func_start FUN_080af5b8
FUN_080af5b8: @ 0x080AF5B8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_080af400
	ldr r5, _080AF634 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r6, _080AF638 @ =0x000003FF
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _080AF63C @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r0, #0xc0
	ldr r2, _080AF640 @ =0x00000686
	adds r1, r4, r2
	strh r0, [r1]
	ldr r0, _080AF644 @ =0x03002BE0
	ldr r2, [r0]
	movs r3, #0x2c
	ldrsh r0, [r2, r3]
	movs r3, #0xce
	lsls r3, r3, #3
	adds r1, r4, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	ldr r3, _080AF648 @ =0x00000674
	adds r2, r4, r3
	movs r3, #0
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	ldr r2, _080AF64C @ =0x0000067C
	adds r1, r4, r2
	ldrh r1, [r1]
	lsrs r1, r1, #4
	ldr r3, _080AF650 @ =0xFFFFFF00
	adds r0, r0, r3
	subs r1, r1, r0
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0x7f
	bgt _080AF654
	ldr r0, [r5]
	adds r0, #1
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _080AF63C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #0xc
	adds r2, #4
	b _080AF670
	.align 2, 0
_080AF634: .4byte 0x030046B8
_080AF638: .4byte 0x000003FF
_080AF63C: .4byte 0x0203B400
_080AF640: .4byte 0x00000686
_080AF644: .4byte 0x03002BE0
_080AF648: .4byte 0x00000674
_080AF64C: .4byte 0x0000067C
_080AF650: .4byte 0xFFFFFF00
_080AF654:
	ldr r0, [r5]
	adds r0, #1
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	ldr r3, _080AF6AC @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #0xc
	rsbs r0, r0, #0
	movs r2, #0xd0
	lsls r2, r2, #3
_080AF670:
	adds r1, r4, r2
	strh r0, [r1]
	ldr r3, _080AF6B0 @ =0x0000067E
	adds r1, r4, r3
	movs r3, #0
	movs r0, #0
	strh r0, [r1]
	ldr r2, _080AF6B4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AF6B8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080AF6AC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x40
	ldr r2, _080AF6BC @ =0x00000682
	adds r1, r4, r2
	strh r0, [r1]
	ldr r1, _080AF6C0 @ =0x0000068C
	adds r0, r4, r1
	strb r3, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AF6AC: .4byte 0x0203B400
_080AF6B0: .4byte 0x0000067E
_080AF6B4: .4byte 0x030046B8
_080AF6B8: .4byte 0x000003FF
_080AF6BC: .4byte 0x00000682
_080AF6C0: .4byte 0x0000068C

	thumb_func_start FUN_080af6c4
FUN_080af6c4: @ 0x080AF6C4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r1, _080AF744 @ =0x000006AC
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	adds r0, r5, #0
	bl FUN_080af4f8
	adds r4, r0, #0
	adds r0, r5, #0
	bl FUN_080af508
	adds r1, r0, #0
	cmp r4, #0
	bgt _080AF6EC
	b _080AF878
_080AF6EC:
	cmp r1, #0
	bgt _080AF6F2
	b _080AF878
_080AF6F2:
	movs r6, #0
	movs r7, #0
	movs r2, #0xcf
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r0, [r0]
	adds r3, r0, #0
	cmp r3, #2
	bne _080AF758
	adds r0, r4, #0
	muls r0, r1, r0
	lsls r6, r0, #2
	ldr r2, _080AF748 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AF74C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _080AF750 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080AF7A4
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r4, _080AF754 @ =0x0000069C
	adds r2, r5, r4
	str r7, [sp]
	str r7, [sp, #4]
	str r3, [sp, #8]
	str r1, [sp, #0xc]
	movs r3, #0
	bl FUN_080ddcc8
	b _080AF7A4
	.align 2, 0
_080AF744: .4byte 0x000006AC
_080AF748: .4byte 0x030046B8
_080AF74C: .4byte 0x000003FF
_080AF750: .4byte 0x0203B400
_080AF754: .4byte 0x0000069C
_080AF758:
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _080AF766
	cmp r3, #7
	bne _080AF7A4
_080AF766:
	adds r6, r4, #0
	muls r6, r1, r6
	ldr r2, _080AF7FC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080AF800 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080AF804 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _080AF7A4
	movs r2, #0xce
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r3, _080AF808 @ =0x000006A4
	adds r2, r5, r3
	str r7, [sp]
	str r7, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	movs r3, #0
	bl FUN_080ddcc8
_080AF7A4:
	cmp r6, #0
	ble _080AF7BE
	ldr r0, _080AF80C @ =0x00000BF8
	add r0, r8
	ldrh r0, [r0]
	muls r0, r6, r0
	movs r1, #0x64
	bl Div
	adds r6, r0, #0
	cmp r6, #0
	bgt _080AF7BE
	movs r6, #1
_080AF7BE:
	ldr r0, _080AF810 @ =0x00000696
	adds r4, r5, r0
	ldrh r0, [r4]
	adds r0, r0, r6
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x28
	bls _080AF7E6
	ldrh r0, [r4]
	movs r1, #0x28
	bl Div
	adds r7, r7, r0
	lsls r1, r7, #2
	adds r1, r1, r7
	lsls r1, r1, #3
	ldrh r0, [r4]
	subs r0, r0, r1
	strh r0, [r4]
_080AF7E6:
	ldr r1, _080AF814 @ =0x030046A0
	ldr r0, [r1]
	movs r3, #0xae
	lsls r3, r3, #2
	adds r2, r0, r3
	ldr r0, [r2]
	cmp r0, r7
	bgt _080AF818
	movs r0, #0
	b _080AF81A
	.align 2, 0
_080AF7FC: .4byte 0x030046B8
_080AF800: .4byte 0x000003FF
_080AF804: .4byte 0x0203B400
_080AF808: .4byte 0x000006A4
_080AF80C: .4byte 0x00000BF8
_080AF810: .4byte 0x00000696
_080AF814: .4byte 0x030046A0
_080AF818:
	subs r0, r0, r7
_080AF81A:
	str r0, [r2]
	ldr r5, _080AF884 @ =0x03002C58
	ldr r0, [r5]
	ldr r3, _080AF888 @ =0x0000133F
	adds r2, r0, r3
	ldrb r4, [r2]
	cmp r4, #0
	bne _080AF878
	ldr r0, [r1]
	movs r6, #0xae
	lsls r6, r6, #2
	adds r1, r0, r6
	adds r6, #4
	adds r0, r0, r6
	ldr r0, [r0]
	asrs r0, r0, #2
	ldr r1, [r1]
	cmp r1, r0
	bgt _080AF878
	movs r0, #1
	strb r0, [r2]
	ldr r1, [r5]
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	movs r2, #0x9a
	lsls r2, r2, #5
	adds r1, r1, r2
	adds r1, r1, r0
	ldrh r0, [r1]
	bl PlaySound_082406e0
	movs r0, #0x1f
	str r0, [sp]
	ldr r0, _080AF88C @ =0x00001FFF
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0
	movs r1, #4
	movs r2, #0x1f
	movs r3, #0x1f
	bl FUN_0823ce68
	ldr r0, [r5]
	movs r1, #4
	bl FUN_080ad204
_080AF878:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AF884: .4byte 0x03002C58
_080AF888: .4byte 0x0000133F
_080AF88C: .4byte 0x00001FFF

	thumb_func_start FUN_080af890
FUN_080af890: @ 0x080AF890
	ldr r1, _080AF89C @ =0x0000068A
	adds r0, r0, r1
	movs r1, #0x10
	strh r1, [r0]
	bx lr
	.align 2, 0
_080AF89C: .4byte 0x0000068A

	thumb_func_start FUN_080af8a0
FUN_080af8a0: @ 0x080AF8A0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080AF900 @ =0x000006AC
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _080AF904 @ =0x0000068A
	adds r1, r4, r2
	movs r0, #0x10
	strh r0, [r1]
	movs r0, #0xc3
	lsls r0, r0, #3
	adds r2, r4, r0
	movs r1, #0xce
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080AF908 @ =0x0000067A
	adds r3, r4, r2
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080AF938
	ldr r0, _080AF90C @ =0x0000061A
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	movs r1, #0xc1
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080AF910
	ldrb r0, [r5, #0x1f]
	cmp r0, #0
	beq _080AF910
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080af374
	b _080AF970
	.align 2, 0
_080AF900: .4byte 0x000006AC
_080AF904: .4byte 0x0000068A
_080AF908: .4byte 0x0000067A
_080AF90C: .4byte 0x0000061A
_080AF910:
	adds r0, r4, #0
	bl FUN_080af5b8
	ldr r2, _080AF934 @ =0x00000686
	adds r1, r4, r2
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0xd1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x60
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080af374
	b _080AF970
	.align 2, 0
_080AF934: .4byte 0x00000686
_080AF938:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080AF960
	ldr r1, _080AF95C @ =0x0000061A
	adds r2, r4, r1
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r0, #0
	ldrh r0, [r2]
	adds r1, r1, r0
	ldrh r0, [r3]
	subs r0, #8
	lsls r0, r0, #4
	subs r1, r1, r0
	strh r1, [r2]
	b _080AF970
	.align 2, 0
_080AF95C: .4byte 0x0000061A
_080AF960:
	ldr r2, _080AF978 @ =0x0000061A
	adds r1, r4, r2
	ldrh r0, [r3]
	adds r0, #1
	lsls r0, r0, #5
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_080AF970:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AF978: .4byte 0x0000061A

	thumb_func_start FUN_080af97c
FUN_080af97c: @ 0x080AF97C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r1, _080AF9A4 @ =0x0000068A
	adds r0, r7, r1
	movs r2, #0x10
	strh r2, [r0]
	ldr r0, _080AF9A8 @ =0x0000067A
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080AF9AC
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080af374
	b _080AFA0A
	.align 2, 0
_080AF9A4: .4byte 0x0000068A
_080AF9A8: .4byte 0x0000067A
_080AF9AC:
	ldrh r4, [r1]
	subs r4, r2, r4
	adds r6, r4, #1
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r5, r7, r1
	movs r2, #0
	ldrsh r0, [r5, r2]
	muls r0, r4, r0
	movs r2, #0xce
	lsls r2, r2, #3
	adds r1, r7, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r5]
	ldr r0, _080AFA10 @ =0x0000061A
	adds r5, r7, r0
	movs r1, #0
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	ldr r2, _080AFA14 @ =0x00000672
	adds r1, r7, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r5]
	ldr r0, _080AFA18 @ =0x0000061C
	adds r5, r7, r0
	movs r1, #0
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	ldr r2, _080AFA1C @ =0x00000674
	adds r1, r7, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r5]
_080AFA0A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AFA10: .4byte 0x0000061A
_080AFA14: .4byte 0x00000672
_080AFA18: .4byte 0x0000061C
_080AFA1C: .4byte 0x00000674

	thumb_func_start FUN_080afa20
FUN_080afa20: @ 0x080AFA20
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080AFA50 @ =0x0000068A
	adds r1, r5, r0
	movs r0, #0x10
	strh r0, [r1]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xce
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r4, #0
	ldrsh r2, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, r0, r2
	cmp r0, #0
	blt _080AFA54
	asrs r1, r0, #2
	b _080AFA5A
	.align 2, 0
_080AFA50: .4byte 0x0000068A
_080AFA54:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_080AFA5A:
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r0, r5, r2
	strh r1, [r0]
	ldr r3, _080AFAA8 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080AFAAC @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r4, _080AFAB0 @ =0x0203B400
	adds r0, r0, r4
	ldrh r1, [r0]
	ldr r0, _080AFAB4 @ =0x00000672
	adds r2, r5, r0
	movs r0, #0x3f
	ands r1, r0
	adds r1, #0x80
	ldrh r0, [r2]
	adds r0, r0, r1
	ldr r2, _080AFAB8 @ =0x0000061A
	adds r1, r5, r2
	strh r0, [r1]
	ldr r4, _080AFABC @ =0x0000061C
	adds r0, r5, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r4, #0x58
	adds r0, r5, r4
	movs r4, #0
	ldrsh r2, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, r0, r2
	cmp r0, #0
	blt _080AFAC0
	asrs r1, r0, #2
	b _080AFAC6
	.align 2, 0
_080AFAA8: .4byte 0x030046B8
_080AFAAC: .4byte 0x000003FF
_080AFAB0: .4byte 0x0203B400
_080AFAB4: .4byte 0x00000672
_080AFAB8: .4byte 0x0000061A
_080AFABC: .4byte 0x0000061C
_080AFAC0:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_080AFAC6:
	ldr r2, _080AFB40 @ =0x0000061C
	adds r0, r5, r2
	strh r1, [r0]
	ldr r4, _080AFB44 @ =0x0000067A
	adds r1, r5, r4
	ldrh r0, [r1]
	ldr r2, _080AFB48 @ =0x0000012B
	cmp r0, r2
	bhi _080AFADC
	adds r0, #1
	strh r0, [r1]
_080AFADC:
	ldrh r0, [r1]
	cmp r0, #0x3b
	bls _080AFBC4
	movs r0, #0xd3
	lsls r0, r0, #3
	adds r6, r5, r0
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080AFB9C
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080AFB4C @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _080AFB50 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r4, #0x96
	lsls r4, r4, #1
	adds r1, r4, #0
	bl Mod
	adds r0, r0, r4
	strh r0, [r6]
	adds r0, r5, #0
	bl FUN_080af53c
	ldr r2, _080AFB54 @ =0x00000692
	adds r4, r5, r2
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _080AFBC4
	adds r0, r5, #0
	bl FUN_080af400
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne _080AFB5C
	ldr r3, _080AFB58 @ =0x0000067C
	adds r1, r5, r3
	movs r0, #0xf0
	lsls r0, r0, #3
	b _080AFB8C
	.align 2, 0
_080AFB40: .4byte 0x0000061C
_080AFB44: .4byte 0x0000067A
_080AFB48: .4byte 0x0000012B
_080AFB4C: .4byte 0x000003FF
_080AFB50: .4byte 0x0203B400
_080AFB54: .4byte 0x00000692
_080AFB58: .4byte 0x0000067C
_080AFB5C:
	cmp r0, #1
	bne _080AFB70
	ldr r4, _080AFB6C @ =0x0000067C
	adds r1, r5, r4
	movs r0, #0xf8
	lsls r0, r0, #4
	b _080AFB8C
	.align 2, 0
_080AFB6C: .4byte 0x0000067C
_080AFB70:
	cmp r0, #2
	bne _080AFB84
	ldr r0, _080AFB80 @ =0x0000067C
	adds r1, r5, r0
	movs r0, #0xc8
	lsls r0, r0, #4
	b _080AFB8C
	.align 2, 0
_080AFB80: .4byte 0x0000067C
_080AFB84:
	ldr r2, _080AFB98 @ =0x0000067C
	adds r1, r5, r2
	movs r0, #0x90
	lsls r0, r0, #3
_080AFB8C:
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_080af374
	b _080AFBC4
	.align 2, 0
_080AFB98: .4byte 0x0000067C
_080AFB9C:
	ldrh r0, [r1]
	cmp r0, r2
	bls _080AFBC4
	adds r0, r5, #0
	bl FUN_080af5b8
	ldr r3, _080AFBCC @ =0x00000686
	adds r1, r5, r3
	movs r0, #0xe0
	lsls r0, r0, #1
	strh r0, [r1]
	movs r4, #0xd1
	lsls r4, r4, #3
	adds r1, r5, r4
	movs r0, #0x60
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #3
	bl FUN_080af374
_080AFBC4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AFBCC: .4byte 0x00000686

	thumb_func_start FUN_080afbd0
FUN_080afbd0: @ 0x080AFBD0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, _080AFBF4 @ =0x0000067E
	adds r1, r6, r0
	movs r2, #0xd0
	lsls r2, r2, #3
	adds r0, r6, r2
	ldrh r3, [r1]
	movs r4, #0
	ldrsh r2, [r1, r4]
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r2, r0
	bge _080AFBF8
	adds r0, r3, #1
	b _080AFBFE
	.align 2, 0
_080AFBF4: .4byte 0x0000067E
_080AFBF8:
	cmp r2, r0
	ble _080AFC00
	subs r0, r3, #1
_080AFBFE:
	strh r0, [r1]
_080AFC00:
	ldr r0, _080AFCF4 @ =0x00000682
	adds r4, r6, r0
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080AFC62
	ldr r1, _080AFCF8 @ =0x0203B400
	mov ip, r1
	ldr r5, _080AFCFC @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r7, _080AFD00 @ =0x000003FF
	ands r1, r7
	lsls r0, r1, #1
	add r0, ip
	ldrh r0, [r0]
	movs r2, #7
	ands r0, r2
	adds r3, r0, #0
	adds r3, #0xc
	movs r0, #0xd0
	lsls r0, r0, #3
	adds r2, r6, r0
	strh r3, [r2]
	adds r1, #1
	ands r1, r7
	str r1, [r5]
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080AFC4C
	rsbs r0, r3, #0
	strh r0, [r2]
_080AFC4C:
	ldr r0, [r5]
	adds r0, #1
	ands r0, r7
	str r0, [r5]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x20
	strh r0, [r4]
_080AFC62:
	ldr r1, _080AFD04 @ =0x0000067C
	adds r3, r6, r1
	ldr r4, _080AFD08 @ =0x00000FFF
	adds r2, r4, #0
	ldrh r5, [r3]
	adds r1, r2, r5
	ldr r4, _080AFD0C @ =0x0000067E
	adds r0, r6, r4
	ldrh r0, [r0]
	adds r0, r0, r1
	ands r0, r2
	strh r0, [r3]
	lsrs r0, r0, #4
	mov ip, r0
	movs r5, #0xd1
	lsls r5, r5, #3
	adds r7, r6, r5
	ldrh r0, [r7]
	subs r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080AFCBC
	ldr r5, _080AFCF8 @ =0x0203B400
	ldr r4, _080AFCFC @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _080AFD00 @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrb r1, [r1]
	adds r1, #0xc0
	ldr r2, _080AFD10 @ =0x00000686
	strh r1, [r2, r6]
	adds r0, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x40
	strh r0, [r7]
_080AFCBC:
	ldr r3, _080AFD14 @ =0x00000684
	adds r1, r6, r3
	ldrh r2, [r1]
	lsls r0, r2, #4
	ldr r4, _080AFD10 @ =0x00000686
	adds r3, r6, r4
	subs r0, r0, r2
	ldrh r3, [r3]
	adds r0, r0, r3
	asrs r0, r0, #4
	strh r0, [r1]
	ldrh r3, [r1]
	ldr r1, _080AFD18 @ =0x085B0A08
	mov r2, ip
	adds r2, #0x40
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r3, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _080AFD1C
	asrs r0, r0, #0xc
	b _080AFD22
	.align 2, 0
_080AFCF4: .4byte 0x00000682
_080AFCF8: .4byte 0x0203B400
_080AFCFC: .4byte 0x030046B8
_080AFD00: .4byte 0x000003FF
_080AFD04: .4byte 0x0000067C
_080AFD08: .4byte 0x00000FFF
_080AFD0C: .4byte 0x0000067E
_080AFD10: .4byte 0x00000686
_080AFD14: .4byte 0x00000684
_080AFD18: .4byte 0x085B0A08
_080AFD1C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AFD22:
	adds r3, r0, #0
	ldr r1, _080AFD4C @ =0x0000068C
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #5
	muls r0, r1, r0
	cmp r0, #0
	blt _080AFD50
	asrs r1, r0, #0x18
	b _080AFD56
	.align 2, 0
_080AFD4C: .4byte 0x0000068C
_080AFD50:
	rsbs r0, r0, #0
	asrs r0, r0, #0x18
	rsbs r1, r0, #0
_080AFD56:
	movs r5, #0xce
	lsls r5, r5, #3
	adds r0, r6, r5
	ldrh r0, [r0]
	adds r0, r0, r3
	adds r0, r0, r1
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r1, r6, r2
	strh r0, [r1]
	ldr r3, _080AFD84 @ =0x00000684
	adds r0, r6, r3
	ldrh r1, [r0]
	mov r5, ip
	lsls r0, r5, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080AFD88
	asrs r0, r0, #0xc
	b _080AFD8E
	.align 2, 0
_080AFD84: .4byte 0x00000684
_080AFD88:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AFD8E:
	adds r2, r0, #0
	ldr r3, _080AFDB4 @ =0x0000068C
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r5, #0
	ldrsh r1, [r0, r5]
	mov r3, ip
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #5
	muls r0, r1, r0
	cmp r0, #0
	blt _080AFDB8
	asrs r1, r0, #0x18
	b _080AFDBE
	.align 2, 0
_080AFDB4: .4byte 0x0000068C
_080AFDB8:
	rsbs r0, r0, #0
	asrs r0, r0, #0x18
	rsbs r1, r0, #0
_080AFDBE:
	ldr r5, _080AFDFC @ =0x00000674
	adds r0, r6, r5
	ldrh r0, [r0]
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r2, _080AFE00 @ =0x0000061C
	adds r1, r6, r2
	strh r0, [r1]
	movs r3, #0xd3
	lsls r3, r3, #3
	adds r1, r6, r3
	ldrh r0, [r1]
	cmp r0, #2
	bhi _080AFE08
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_080af53c
	ldr r4, _080AFE04 @ =0x00000692
	adds r1, r6, r4
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _080AFE0C
	adds r0, r6, #0
	movs r1, #4
	bl FUN_080af374
	b _080AFE0C
	.align 2, 0
_080AFDFC: .4byte 0x00000674
_080AFE00: .4byte 0x0000061C
_080AFE04: .4byte 0x00000692
_080AFE08:
	subs r0, #2
	strh r0, [r1]
_080AFE0C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080afe18
FUN_080afe18: @ 0x080AFE18
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r1, _080AFE38 @ =0x00000692
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080AFE3C
	movs r4, #0xf0
	lsls r4, r4, #3
	movs r6, #0xf0
	lsls r6, r6, #1
	b _080AFE5C
	.align 2, 0
_080AFE38: .4byte 0x00000692
_080AFE3C:
	cmp r0, #1
	bne _080AFE46
	movs r4, #0xf8
	lsls r4, r4, #4
	b _080AFE58
_080AFE46:
	cmp r0, #2
	bne _080AFE54
	movs r4, #0xc8
	lsls r4, r4, #4
	movs r6, #0xf0
	lsls r6, r6, #1
	b _080AFE5C
_080AFE54:
	movs r4, #0x90
	lsls r4, r4, #3
_080AFE58:
	movs r6, #0xc8
	lsls r6, r6, #1
_080AFE5C:
	ldr r2, _080AFE7C @ =0x0000067C
	adds r1, r5, r2
	ldrh r2, [r1]
	ldr r3, _080AFE80 @ =0xFFFFF000
	adds r0, r2, r3
	subs r7, r4, r0
	ldr r3, _080AFE84 @ =0x00000FFF
	ands r7, r3
	ldr r0, _080AFE88 @ =0x000007FF
	cmp r7, r0
	bgt _080AFE8C
	cmp r7, #0x2f
	ble _080AFE94
	adds r0, r2, #0
	adds r0, #0x30
	b _080AFE9E
	.align 2, 0
_080AFE7C: .4byte 0x0000067C
_080AFE80: .4byte 0xFFFFF000
_080AFE84: .4byte 0x00000FFF
_080AFE88: .4byte 0x000007FF
_080AFE8C:
	movs r0, #0xfd
	lsls r0, r0, #4
	cmp r7, r0
	ble _080AFE98
_080AFE94:
	strh r4, [r1]
	b _080AFEA2
_080AFE98:
	movs r4, #0xfd
	lsls r4, r4, #4
	adds r0, r2, r4
_080AFE9E:
	ands r0, r3
	strh r0, [r1]
_080AFEA2:
	ldr r1, _080AFEE0 @ =0x0000067C
	adds r0, r5, r1
	ldrh r0, [r0]
	lsrs r4, r0, #4
	ldr r3, _080AFEE4 @ =0x00000684
	adds r2, r5, r3
	ldrh r1, [r2]
	subs r0, r6, r1
	mov ip, r0
	lsls r0, r1, #3
	subs r0, r0, r1
	adds r0, r0, r6
	asrs r0, r0, #3
	strh r0, [r2]
	ldrh r3, [r2]
	ldr r2, _080AFEE8 @ =0x085B0A08
	adds r0, r4, #0
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
	blt _080AFEEC
	asrs r0, r0, #0xc
	b _080AFEF2
	.align 2, 0
_080AFEE0: .4byte 0x0000067C
_080AFEE4: .4byte 0x00000684
_080AFEE8: .4byte 0x085B0A08
_080AFEEC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AFEF2:
	mov r8, r0
	ldr r2, _080AFF24 @ =0x0000068C
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r3, #0
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	muls r0, r2, r0
	cmp r0, #0
	blt _080AFF28
	asrs r2, r0, #0x18
	b _080AFF2E
	.align 2, 0
_080AFF24: .4byte 0x0000068C
_080AFF28:
	rsbs r0, r0, #0
	asrs r0, r0, #0x18
	rsbs r2, r0, #0
_080AFF2E:
	movs r3, #0xce
	lsls r3, r3, #3
	adds r0, r5, r3
	ldrh r0, [r0]
	add r0, r8
	adds r0, r0, r2
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r1, r5, r2
	strh r0, [r1]
	adds r3, #0x14
	adds r0, r5, r3
	ldrh r1, [r0]
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080AFF5E
	asrs r0, r0, #0xc
	b _080AFF64
_080AFF5E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AFF64:
	mov r8, r0
	ldr r3, _080AFF90 @ =0x0000068C
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r3, #0
	ldrsh r2, [r0, r3]
	ands r4, r1
	lsls r0, r4, #1
	adds r0, r0, r6
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #5
	muls r0, r2, r0
	cmp r0, #0
	blt _080AFF94
	asrs r1, r0, #0x18
	b _080AFF9A
	.align 2, 0
_080AFF90: .4byte 0x0000068C
_080AFF94:
	rsbs r0, r0, #0
	asrs r0, r0, #0x18
	rsbs r1, r0, #0
_080AFF9A:
	ldr r2, _080AFFD4 @ =0x00000674
	adds r0, r5, r2
	ldrh r0, [r0]
	add r0, r8
	adds r0, r0, r1
	ldr r3, _080AFFD8 @ =0x0000061C
	adds r1, r5, r3
	strh r0, [r1]
	cmp r7, #0
	bne _080AFFC8
	mov r0, ip
	cmp r0, #0
	bge _080AFFB6
	rsbs r0, r0, #0
_080AFFB6:
	cmp r0, #0x1f
	bgt _080AFFC8
	movs r0, #0xf4
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #5
	bl FUN_080af374
_080AFFC8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AFFD4: .4byte 0x00000674
_080AFFD8: .4byte 0x0000061C

	thumb_func_start FUN_080affdc
FUN_080affdc: @ 0x080AFFDC
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080B0060 @ =0x00000692
	adds r5, r4, r0
	movs r1, #0
	ldrsb r1, [r5, r1]
	adds r0, r4, #0
	movs r2, #4
	bl FUN_080af4a4
	cmp r0, #0
	beq _080B0086
	ldr r2, _080B0064 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080B0068 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080B006C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r1, r0, #3
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _080B0032
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r3, _080B0070 @ =0x0000069C
	adds r2, r4, r3
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #1
	str r1, [sp, #8]
	movs r1, #2
	str r1, [sp, #0xc]
	movs r1, #1
	movs r3, #0
	bl FUN_080ddcc8
_080B0032:
	ldr r0, _080B0074 @ =0x0000067A
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bls _080B0078
	movs r1, #0
	ldrsb r1, [r5, r1]
	adds r0, r4, #0
	movs r2, #5
	bl FUN_080af4d4
	adds r0, r4, #0
	bl FUN_080af5b8
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080af374
	b _080B0094
	.align 2, 0
_080B0060: .4byte 0x00000692
_080B0064: .4byte 0x030046B8
_080B0068: .4byte 0x000003FF
_080B006C: .4byte 0x0203B400
_080B0070: .4byte 0x0000069C
_080B0074: .4byte 0x0000067A
_080B0078:
	movs r1, #0
	ldrsb r1, [r5, r1]
	adds r0, r4, #0
	movs r2, #5
	bl FUN_080af51c
	b _080B0094
_080B0086:
	adds r0, r4, #0
	bl FUN_080af5b8
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080af374
_080B0094:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b009c
FUN_080b009c: @ 0x080B009C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B00D0 @ =0x0000068A
	adds r1, r4, r0
	movs r0, #6
	strh r0, [r1]
	ldr r1, _080B00D4 @ =0x0000068E
	adds r0, r4, r1
	ldrh r3, [r0]
	ldr r2, _080B00D8 @ =0x085B0A08
	subs r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080B00DC
	asrs r3, r0, #0xc
	b _080B00E2
	.align 2, 0
_080B00D0: .4byte 0x0000068A
_080B00D4: .4byte 0x0000068E
_080B00D8: .4byte 0x085B0A08
_080B00DC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080B00E2:
	movs r0, #0xc3
	lsls r0, r0, #3
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r1, _080B010C @ =0x0000068E
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r3, _080B0110 @ =0x0000068D
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080B0114
	asrs r2, r0, #0xc
	b _080B011A
	.align 2, 0
_080B010C: .4byte 0x0000068E
_080B0110: .4byte 0x0000068D
_080B0114:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080B011A:
	ldr r3, _080B0174 @ =0x0000061C
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r3, #0xce
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r2, r2, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	ldr r3, _080B0178 @ =0x00000674
	adds r1, r4, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _080B017C @ =0x00077A0F
	cmp r1, r0
	ble _080B0188
	ldr r3, _080B0180 @ =0x0000068E
	adds r1, r4, r3
	ldrh r0, [r1]
	cmp r0, #0x1d
	bhi _080B0168
	movs r0, #0x1e
	strh r0, [r1]
_080B0168:
	ldr r0, _080B0184 @ =0x0000068D
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #0x80
	strb r0, [r1]
	b _080B0196
	.align 2, 0
_080B0174: .4byte 0x0000061C
_080B0178: .4byte 0x00000674
_080B017C: .4byte 0x00077A0F
_080B0180: .4byte 0x0000068E
_080B0184: .4byte 0x0000068D
_080B0188:
	ldr r1, _080B01B0 @ =0x0000068E
	adds r2, r4, r1
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
_080B0196:
	ldr r2, _080B01B0 @ =0x0000068E
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _080B01A8
	adds r0, r4, #0
	movs r1, #8
	bl FUN_080af374
_080B01A8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B01B0: .4byte 0x0000068E

	thumb_func_start FUN_080b01b4
FUN_080b01b4: @ 0x080B01B4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B01E8 @ =0x0000067A
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	movs r2, #0xd2
	lsls r2, r2, #3
	adds r0, r4, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r0]
	cmp r1, r0
	blo _080B01E0
	adds r0, r4, #0
	bl FUN_080af5b8
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080af374
_080B01E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B01E8: .4byte 0x0000067A

	thumb_func_start FUN_080b01ec
FUN_080b01ec: @ 0x080B01EC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r4, r0, #0
	ldr r0, _080B02B4 @ =0x0000068A
	adds r1, r4, r0
	movs r7, #0
	movs r0, #0x10
	strh r0, [r1]
	ldr r1, _080B02B8 @ =0x0000067A
	adds r6, r4, r1
	ldrh r0, [r6]
	cmp r0, #0x3f
	bhi _080B02D0
	cmp r0, #0
	bne _080B021C
	adds r0, r4, #0
	bl FUN_080af2f4
	ldr r0, _080B02BC @ =0x03002C58
	ldr r0, [r0]
	ldr r1, _080B02C0 @ =0x0000133E
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
_080B021C:
	ldrh r1, [r6]
	cmp r1, #0x1f
	bls _080B022A
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080B02A6
_080B022A:
	movs r0, #0x40
	subs r0, r0, r1
	lsls r0, r0, #0x11
	lsrs r0, r0, #0x10
	ldr r3, _080B02C4 @ =0xFFFF0000
	ldr r2, [sp, #0x10]
	ands r2, r3
	orrs r2, r0
	str r2, [sp, #0x10]
	add r0, sp, #0x10
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	ldr r0, _080B02C8 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	ldrh r1, [r0]
	ldr r0, [sp, #0x14]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x14]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r4, r1
	str r7, [sp]
	str r7, [sp, #4]
	movs r5, #2
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	movs r1, #1
	add r2, sp, #0x10
	movs r3, #0
	bl FUN_080ddcc8
	ldrh r0, [r6]
	cmp r0, #0x1f
	bhi _080B02A6
	ldr r1, _080B02CC @ =0x000006AC
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_080adf50
	ldrh r0, [r6]
	movs r1, #5
	bl Mod
	movs r1, #0x68
	muls r0, r1, r0
	adds r0, r0, r4
	movs r1, #0xf1
	lsls r1, r1, #2
	adds r0, r0, r1
	str r7, [sp]
	str r7, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	movs r1, #1
	add r2, sp, #0x10
	movs r3, #0
	bl FUN_080ddcc8
_080B02A6:
	ldr r0, _080B02B8 @ =0x0000067A
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _080B02D8
	.align 2, 0
_080B02B4: .4byte 0x0000068A
_080B02B8: .4byte 0x0000067A
_080B02BC: .4byte 0x03002C58
_080B02C0: .4byte 0x0000133E
_080B02C4: .4byte 0xFFFF0000
_080B02C8: .4byte 0x0000FFFF
_080B02CC: .4byte 0x000006AC
_080B02D0:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080af374
_080B02D8:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b02e0
FUN_080b02e0: @ 0x080B02E0
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xcf
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #9
	beq _080B038E
	cmp r0, #0
	beq _080B038E
	cmp r0, #1
	beq _080B038E
	cmp r0, #6
	beq _080B038E
	cmp r0, #2
	bne _080B031A
	adds r0, r4, #0
	bl FUN_080af508
	cmp r0, #0
	bne _080B037C
	adds r0, r4, #0
	bl FUN_080af5b8
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080af374
	b _080B038E
_080B031A:
	cmp r0, #7
	bne _080B037C
	adds r0, r4, #0
	bl FUN_080af508
	cmp r0, #0
	ble _080B037C
	movs r3, #0xc3
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r3, #0x58
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r2, r2, r0
	subs r3, #0x54
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r3, #0x58
	adds r1, r4, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r0, r0, r1
	subs r0, #0x40
	subs r2, #0x40
	cmp r2, #0
	bge _080B0358
	rsbs r2, r2, #0
_080B0358:
	cmp r2, #0x7f
	bgt _080B037C
	cmp r0, #0
	bge _080B0362
	rsbs r0, r0, #0
_080B0362:
	cmp r0, #0x7f
	bgt _080B037C
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080af374
	ldr r0, _080B0378 @ =0x0000068E
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	b _080B038E
	.align 2, 0
_080B0378: .4byte 0x0000068E
_080B037C:
	ldr r1, _080B0394 @ =0x0000068E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080B038E
	adds r0, r4, #0
	movs r1, #7
	bl FUN_080af374
_080B038E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B0394: .4byte 0x0000068E

	thumb_func_start FUN_080b0398
FUN_080b0398: @ 0x080B0398
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	str r1, [sp]
	movs r0, #0
	mov r8, r0
	movs r7, #0xff
	ldr r1, _080B03F0 @ =0x085B0A08
	mov sl, r1
	movs r2, #1
	mov sb, r2
_080B03B6:
	movs r0, #0x68
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	adds r0, #0x68
	adds r0, r0, r6
	mov ip, r0
	mov r4, ip
	ldr r2, _080B03F0 @ =0x085B0A08
	adds r0, #0x64
	ldrh r1, [r0]
	adds r0, r7, #0
	ands r0, r1
	adds r0, #0x40
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	cmp r1, #0
	bge _080B03E2
	rsbs r1, r1, #0
_080B03E2:
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080B03F4
	asrs r0, r0, #0xc
	b _080B03FA
	.align 2, 0
_080B03F0: .4byte 0x085B0A08
_080B03F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080B03FA:
	adds r3, r0, #0
	adds r3, #0x3c
	mov r0, ip
	adds r0, #0x66
	ldrh r1, [r0]
	adds r1, #0x40
	ands r1, r7
	lsls r1, r1, #1
	add r1, sl
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r1, r3, r1
	adds r2, r0, #0
	cmp r1, #0
	blt _080B041C
	asrs r1, r1, #0xc
	b _080B0422
_080B041C:
	rsbs r0, r1, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080B0422:
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r0, r6, r5
	ldrh r0, [r0]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	ldr r1, _080B0450 @ =0x0000061A
	adds r0, r6, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x1e]
	ldrh r1, [r2]
	adds r0, r7, #0
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r3, r0
	cmp r0, #0
	blt _080B0454
	asrs r1, r0, #0xc
	b _080B045A
	.align 2, 0
_080B0450: .4byte 0x0000061A
_080B0454:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080B045A:
	ldr r3, _080B047C @ =0x0000061C
	adds r0, r6, r3
	ldrh r0, [r0]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	movs r5, #0xcf
	lsls r5, r5, #3
	adds r0, r6, r5
	ldrh r0, [r0]
	cmp r0, #2
	bne _080B0480
	mov r1, ip
	adds r1, #0x64
	ldrh r0, [r1]
	adds r0, #4
	b _080B0488
	.align 2, 0
_080B047C: .4byte 0x0000061C
_080B0480:
	mov r1, ip
	adds r1, #0x64
	ldrh r0, [r1]
	adds r0, #2
_080B0488:
	strh r0, [r1]
	mov r0, r8
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq _080B049A
	ldrh r0, [r2]
	adds r0, #1
	b _080B049E
_080B049A:
	ldrh r0, [r2]
	adds r0, #0xff
_080B049E:
	ands r0, r7
	strh r0, [r2]
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
	mov r2, sb
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r3, sb
	ands r0, r3
	cmp r2, r0
	beq _080B04DA
	mov r1, ip
	ldr r0, [r1]
	movs r1, #4
	orrs r0, r1
	mov r2, ip
	str r0, [r2]
	b _080B04E6
_080B04DA:
	mov r3, ip
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_080B04E6:
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
	beq _080B050C
	mov r5, ip
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	str r0, [r5]
	b _080B051A
_080B050C:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2]
_080B051A:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _080B0550 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r4, #7]
	cmp r0, r5
	blo _080B0588
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B0554
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B0548
	ldrb r0, [r4, #5]
_080B0548:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B0564
	.align 2, 0
_080B0550: .4byte 0x0000FFFF
_080B0554:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B0564
	strh r1, [r4, #8]
_080B0564:
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
	ands r0, r7
	cmp r0, #0
	bne _080B0588
	mov r3, sb
	strb r3, [r4, #7]
_080B0588:
	mov r0, ip
	adds r0, #0x2c
	ldr r1, [sp]
	bl FUN_0822b20c
	movs r5, #1
	add r8, r5
	mov r0, r8
	cmp r0, #7
	bgt _080B059E
	b _080B03B6
_080B059E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b05b0
FUN_080b05b0: @ 0x080B05B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	str r1, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r1, #0xff
	mov sl, r1
	movs r2, #0x18
	str r2, [sp, #8]
_080B05CC:
	movs r0, #0x68
	ldr r3, [sp, #4]
	muls r0, r3, r0
	movs r4, #0xea
	lsls r4, r4, #2
	adds r0, r0, r4
	add r0, r8
	mov ip, r0
	mov sb, ip
	adds r2, r3, #0
	adds r2, #2
	movs r0, #8
	subs r3, r0, r2
	ldr r0, _080B0608 @ =0x0000061A
	add r0, r8
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldr r0, _080B060C @ =0x00000672
	add r0, r8
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r1, r1, r0
	muls r1, r3, r1
	lsls r0, r1, #1
	adds r0, r0, r1
	cmp r0, #0
	blt _080B0610
	asrs r0, r0, #5
	b _080B0616
	.align 2, 0
_080B0608: .4byte 0x0000061A
_080B060C: .4byte 0x00000672
_080B0610:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_080B0616:
	adds r4, r0, #0
	movs r0, #0xc3
	lsls r0, r0, #3
	add r0, r8
	movs r5, #0
	ldrsh r0, [r0, r5]
	adds r1, r0, #0
	muls r1, r2, r1
	movs r0, #0xce
	lsls r0, r0, #3
	add r0, r8
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r3, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080B063C
	asrs r0, r0, #3
	b _080B0642
_080B063C:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080B0642:
	adds r1, r0, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080B0670 @ =0xFFFF0000
	ands r0, r6
	adds r6, r0, #0
	orrs r6, r1
	ldr r0, _080B0674 @ =0x0000061A
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r2, r1
	ldr r0, _080B0678 @ =0x00000672
	add r0, r8
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r3, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080B067C
	asrs r0, r0, #3
	b _080B0682
	.align 2, 0
_080B0670: .4byte 0xFFFF0000
_080B0674: .4byte 0x0000061A
_080B0678: .4byte 0x00000672
_080B067C:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080B0682:
	lsls r1, r0, #0x10
	ldr r0, _080B06AC @ =0x0000FFFF
	ands r0, r6
	adds r6, r0, #0
	orrs r6, r1
	ldr r0, _080B06B0 @ =0x0000061C
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r2, r1
	ldr r0, _080B06B4 @ =0x00000674
	add r0, r8
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	adds r0, r1, r0
	cmp r0, #0
	blt _080B06B8
	asrs r0, r0, #3
	b _080B06BE
	.align 2, 0
_080B06AC: .4byte 0x0000FFFF
_080B06B0: .4byte 0x0000061C
_080B06B4: .4byte 0x00000674
_080B06B8:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080B06BE:
	adds r1, r0, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080B06F4 @ =0xFFFF0000
	ands r0, r7
	adds r7, r0, #0
	orrs r7, r1
	ldr r2, _080B06F8 @ =0x085B0A08
	mov r3, ip
	adds r3, #0x64
	ldrh r1, [r3]
	mov r0, sl
	ands r0, r1
	adds r0, #0x40
	mov r4, sl
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r0, [r0, r5]
	ldr r1, [sp, #8]
	muls r0, r1, r0
	cmp r0, #0
	blt _080B06FC
	asrs r0, r0, #0xc
	b _080B0702
	.align 2, 0
_080B06F4: .4byte 0xFFFF0000
_080B06F8: .4byte 0x085B0A08
_080B06FC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080B0702:
	adds r5, r0, #0
	mov r0, ip
	adds r0, #0x66
	ldrh r1, [r0]
	adds r1, #0x40
	mov r4, sl
	ands r1, r4
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r4, #0
	ldrsh r1, [r1, r4]
	muls r1, r5, r1
	adds r4, r0, #0
	cmp r1, #0
	blt _080B0724
	asrs r0, r1, #0xc
	b _080B072A
_080B0724:
	rsbs r0, r1, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080B072A:
	adds r0, r6, r0
	mov r1, sb
	strh r0, [r1, #0x1c]
	asrs r0, r6, #0x10
	strh r0, [r1, #0x1e]
	ldrh r1, [r4]
	mov r0, sl
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _080B074C
	asrs r0, r0, #0xc
	b _080B0752
_080B074C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080B0752:
	adds r0, r7, r0
	mov r5, sb
	strh r0, [r5, #0x20]
	ldrh r0, [r4]
	adds r0, #3
	mov r1, sl
	ands r0, r1
	strh r0, [r4]
	ldrh r0, [r3]
	adds r0, #5
	strh r0, [r3]
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
	movs r2, #1
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _080B07A0
	mov r1, ip
	ldr r0, [r1]
	movs r1, #4
	orrs r0, r1
	mov r2, ip
	str r0, [r2]
	b _080B07AC
_080B07A0:
	mov r3, ip
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_080B07AC:
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
	beq _080B07D2
	mov r5, ip
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	str r0, [r5]
	b _080B07E0
_080B07D2:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2]
_080B07E0:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _080B0814 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r4, #7]
	cmp r0, r5
	blo _080B084E
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B0818
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B080E
	ldrb r0, [r4, #5]
_080B080E:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B0828
	.align 2, 0
_080B0814: .4byte 0x0000FFFF
_080B0818:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B0828
	strh r1, [r4, #8]
_080B0828:
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
	mov r3, sl
	ands r0, r3
	cmp r0, #0
	bne _080B084E
	movs r5, #1
	strb r5, [r4, #7]
_080B084E:
	mov r0, ip
	adds r0, #0x2c
	ldr r1, [sp]
	bl FUN_0822b20c
	ldr r0, [sp, #8]
	adds r0, #4
	str r0, [sp, #8]
	ldr r1, [sp, #4]
	adds r1, #1
	str r1, [sp, #4]
	cmp r1, #5
	bgt _080B086A
	b _080B05CC
_080B086A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b087c
FUN_080b087c: @ 0x080B087C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	ldrh r0, [r5, #0x1c]
	adds r4, r0, #0
	adds r4, #0x2c
	strh r4, [r5, #0x1c]
	ldrh r0, [r5, #0x1e]
	adds r0, #0x40
	strh r0, [r5, #0x1e]
	ldrh r0, [r5, #0x20]
	adds r3, r0, #0
	adds r3, #0x2c
	strh r3, [r5, #0x20]
	movs r2, #0xcf
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #8
	bne _080B08D4
	ldr r2, _080B0904 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080B0908 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080B090C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	subs r0, #8
	adds r1, r4, r0
	strh r1, [r5, #0x1c]
	subs r0, r3, r0
	strh r0, [r5, #0x20]
_080B08D4:
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
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
	beq _080B0910
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080B0918
	.align 2, 0
_080B0904: .4byte 0x030046B8
_080B0908: .4byte 0x000003FF
_080B090C: .4byte 0x0203B400
_080B0910:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B0918:
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
	beq _080B093C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080B0944
_080B093C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080B0944:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B097C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B09B4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B0980
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B0974
	ldrb r0, [r4, #5]
_080B0974:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B0990
	.align 2, 0
_080B097C: .4byte 0x0000FFFF
_080B0980:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B0990
	strh r1, [r4, #8]
_080B0990:
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
	bne _080B09B4
	movs r0, #1
	strb r0, [r4, #7]
_080B09B4:
	adds r0, r5, #0
	adds r0, #0x2c
	adds r1, r7, #0
	bl FUN_0822b20c
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_080b0398
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_080b05b0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b09d4
FUN_080b09d4: @ 0x080B09D4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080B0A14 @ =0x00000C6C
	adds r5, r4, r0
	adds r0, r5, #0
	bl FUN_080b02e0
	ldr r1, _080B0A18 @ =0x085AD054
	ldr r2, _080B0A1C @ =0x000012E4
	adds r0, r4, r2
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	ldr r0, _080B0A20 @ =0x000012F6
	adds r3, r4, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _080B0A28
	ldr r1, _080B0A24 @ =0x00001292
	adds r2, r4, r1
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	b _080B0A42
	.align 2, 0
_080B0A14: .4byte 0x00000C6C
_080B0A18: .4byte 0x085AD054
_080B0A1C: .4byte 0x000012E4
_080B0A20: .4byte 0x000012F6
_080B0A24: .4byte 0x00001292
_080B0A28:
	ldr r3, _080B0A94 @ =0x00001292
	adds r2, r4, r3
	ldrh r1, [r2]
	ldr r0, _080B0A98 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	ldr r1, _080B0A9C @ =0x0000128C
	adds r0, r4, r1
	ldr r2, _080B0AA0 @ =0x00001284
	adds r1, r4, r2
	movs r2, #0
	bl FUN_082364c4
_080B0A42:
	ldr r3, _080B0AA4 @ =0x00000C0F
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B0A52
	adds r0, r5, #0
	bl FUN_080af6c4
_080B0A52:
	movs r6, #0x3e
	ldr r1, _080B0AA8 @ =0x0000135C
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080B0A84
	ldr r3, _080B0AAC @ =0x00001348
	adds r2, r4, r3
	ldr r0, _080B0AB0 @ =0x0000134A
	adds r1, r4, r0
	ldrh r0, [r2]
	ldrh r3, [r1]
	cmp r0, r3
	bhs _080B0A82
	ldrh r3, [r2]
	ldrh r0, [r1]
	subs r0, #0x5a
	cmp r3, r0
	blt _080B0A84
	lsrs r0, r3, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080B0A84
_080B0A82:
	movs r6, #0x3f
_080B0A84:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_080b087c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B0A94: .4byte 0x00001292
_080B0A98: .4byte 0x0000FFFB
_080B0A9C: .4byte 0x0000128C
_080B0AA0: .4byte 0x00001284
_080B0AA4: .4byte 0x00000C0F
_080B0AA8: .4byte 0x0000135C
_080B0AAC: .4byte 0x00001348
_080B0AB0: .4byte 0x0000134A

	thumb_func_start FUN_080b0ab4
FUN_080b0ab4: @ 0x080B0AB4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl FUN_0822a4e0
	adds r4, r6, #0
	adds r4, #0x68
	movs r5, #7
_080B0AC2:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x68
	subs r5, #1
	cmp r5, #0
	bge _080B0AC2
	movs r0, #0xea
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r5, #5
_080B0AD8:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x68
	subs r5, #1
	cmp r5, #0
	bge _080B0AD8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b0aec
FUN_080b0aec: @ 0x080B0AEC
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #0xc4
	lsls r0, r0, #3
	adds r4, r5, r0
	ldr r2, _080B0B6C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _080B0B70 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
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
	ldr r2, _080B0B74 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236514
	movs r0, #0xc3
	lsls r0, r0, #3
	adds r1, r5, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _080B0B78 @ =FUN_080af200
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B0B6C: .4byte 0xFFFF0000
_080B0B70: .4byte 0x0000FFFF
_080B0B74: .4byte 0x00004001
_080B0B78: .4byte FUN_080af200

	thumb_func_start FUN_080b0b7c
FUN_080b0b7c: @ 0x080B0B7C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x2c
	ldr r0, _080B0BE8 @ =0x08251DD0
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl Video_GetActorSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0822a470
	movs r6, #0
	strh r6, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #7]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldr r5, _080B0BEC @ =0x0000922E
	ldr r0, _080B0BF0 @ =0x08251DD4
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl GetFile
	adds r1, r0, #0
	str r1, [r4, #0x58]
	adds r4, #0x48
	str r6, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B0BE8: .4byte 0x08251DD0
_080B0BEC: .4byte 0x0000922E
_080B0BF0: .4byte 0x08251DD4

	thumb_func_start FUN_080b0bf4
FUN_080b0bf4: @ 0x080B0BF4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	movs r0, #0
	mov r8, r0
	ldr r7, _080B0C4C @ =0x030046B8
	ldr r1, _080B0C50 @ =0x000003FF
	mov sl, r1
_080B0C0C:
	movs r0, #0x68
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	adds r0, #0x68
	mov r1, sb
	adds r5, r1, r0
	adds r6, r5, #0
	adds r4, r5, #0
	adds r4, #0x2c
	ldr r0, _080B0C54 @ =0x08251DD0
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl Video_GetActorSprite
	mov r0, r8
	movs r3, #1
	ands r0, r3
	cmp r0, #0
	beq _080B0C58
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x80
	lsls r2, r2, #2
	bl FUN_0822a470
	b _080B0C64
	.align 2, 0
_080B0C4C: .4byte 0x030046B8
_080B0C50: .4byte 0x000003FF
_080B0C54: .4byte 0x08251DD0
_080B0C58:
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x80
	lsls r2, r2, #3
	bl FUN_0822a470
_080B0C64:
	movs r0, #0
	strh r0, [r5, #0x10]
	movs r1, #1
	strb r1, [r5, #7]
	movs r0, #0xc3
	lsls r0, r0, #3
	add r0, sb
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	mov r3, r8
	lsls r0, r3, #5
	adds r1, r6, #0
	adds r1, #0x66
	strh r0, [r1]
	ldr r0, [r7]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _080B0D1C @ =0x0203B400
	adds r0, r0, r3
	ldrb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x64
	strh r1, [r0]
	ldr r0, _080B0D20 @ =0x08251DD4
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080B0D24 @ =0x0000922E
	bl GetFile
	str r0, [r6, #0x58]
	ldr r0, [r7]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _080B0D1C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r2, r0, #0
	adds r2, #1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r0, #0x48
	ldr r1, [r6, #0x58]
	movs r3, #0
	str r3, [sp]
	bl FUN_08236fac
	ldr r0, [r7]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _080B0D1C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080B0D00
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	str r0, [r5]
_080B0D00:
	movs r3, #1
	add r8, r3
	mov r0, r8
	cmp r0, #7
	bgt _080B0D0C
	b _080B0C0C
_080B0D0C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B0D1C: .4byte 0x0203B400
_080B0D20: .4byte 0x08251DD4
_080B0D24: .4byte 0x0000922E

	thumb_func_start FUN_080b0d28
FUN_080b0d28: @ 0x080B0D28
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov r8, r0
	movs r7, #0
	movs r0, #1
	mov sb, r0
	movs r1, #0
	mov sl, r1
_080B0D40:
	movs r0, #0x68
	muls r0, r7, r0
	movs r3, #0xea
	lsls r3, r3, #2
	adds r0, r0, r3
	mov r1, r8
	adds r5, r1, r0
	adds r6, r5, #0
	adds r4, r5, #0
	adds r4, #0x2c
	ldr r0, _080B0D80 @ =0x08251DD0
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl Video_GetActorSprite
	adds r0, r7, #0
	mov r3, sb
	ands r0, r3
	cmp r0, #0
	beq _080B0D84
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x80
	lsls r2, r2, #2
	bl FUN_0822a470
	b _080B0D90
	.align 2, 0
_080B0D80: .4byte 0x08251DD0
_080B0D84:
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x80
	lsls r2, r2, #3
	bl FUN_0822a470
_080B0D90:
	mov r0, sl
	strh r0, [r5, #0x10]
	cmp r7, #0
	bne _080B0D9E
	movs r0, #2
	strb r0, [r5, #7]
	b _080B0DA2
_080B0D9E:
	mov r1, sb
	strb r1, [r5, #7]
_080B0DA2:
	movs r0, #0xc3
	lsls r0, r0, #3
	add r0, r8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	lsls r0, r7, #5
	adds r1, r6, #0
	adds r1, #0x66
	strh r0, [r1]
	ldr r2, _080B0E28 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080B0E2C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080B0E30 @ =0x0203B400
	adds r0, r0, r3
	ldrb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x64
	strh r1, [r0]
	ldr r0, _080B0E34 @ =0x08251DD4
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080B0E38 @ =0x0000922E
	bl GetFile
	adds r1, r0, #0
	str r1, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0x48
	adds r4, r7, #1
	asrs r3, r4, #1
	movs r2, #5
	subs r2, r2, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r3, sl
	str r3, [sp]
	movs r3, #0
	bl FUN_08236fac
	mov r0, sb
	ands r7, r0
	cmp r7, #0
	beq _080B0E12
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	str r0, [r5]
_080B0E12:
	adds r7, r4, #0
	cmp r7, #5
	ble _080B0D40
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B0E28: .4byte 0x030046B8
_080B0E2C: .4byte 0x000003FF
_080B0E30: .4byte 0x0203B400
_080B0E34: .4byte 0x08251DD4
_080B0E38: .4byte 0x0000922E

	thumb_func_start FUN_080b0e3c
FUN_080b0e3c: @ 0x080B0E3C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080b0b7c
	adds r0, r4, #0
	bl FUN_080b0bf4
	adds r0, r4, #0
	bl FUN_080b0d28
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b0e58
FUN_080b0e58: @ 0x080B0E58
	ldr r2, _080B0E88 @ =0x0000069C
	adds r1, r0, r2
	movs r2, #0xa0
	strh r2, [r1]
	ldr r3, _080B0E8C @ =0x0000069E
	adds r1, r0, r3
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	ldr r2, _080B0E90 @ =0x000006A4
	adds r1, r0, r2
	movs r3, #0x40
	strh r3, [r1]
	ldr r1, _080B0E94 @ =0x000006A6
	adds r2, r0, r1
	movs r1, #0x20
	strh r1, [r2]
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r0, r0, r2
	strh r3, [r0]
	bx lr
	.align 2, 0
_080B0E88: .4byte 0x0000069C
_080B0E8C: .4byte 0x0000069E
_080B0E90: .4byte 0x000006A4
_080B0E94: .4byte 0x000006A6

	thumb_func_start FUN_080b0e98
FUN_080b0e98: @ 0x080B0E98
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r0, _080B0F1C @ =0x00000C6C
	adds r6, r7, r0
	ldr r1, _080B0F20 @ =0x000012DC
	adds r3, r7, r1
	movs r2, #0xa2
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r3]
	str r1, [r3, #4]
	ldrh r0, [r3]
	subs r0, #0x20
	strh r0, [r3]
	movs r0, #0x97
	lsls r0, r0, #5
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #0x20
	strh r0, [r1]
	ldr r1, _080B0F24 @ =0x00001284
	adds r2, r7, r1
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080B0F28 @ =0x00001286
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #0x80
	strh r0, [r1]
	ldr r4, _080B0F2C @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080B0F30 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _080B0F34 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x96
	lsls r1, r1, #2
	bl Mod
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	adds r0, r6, #0
	bl FUN_080b0e3c
	movs r0, #0x4c
	bl prepare_08231510
	cmp r0, #0
	beq _080B0F38
	bl Script_GetValue
	adds r1, r0, #0
	b _080B0F3A
	.align 2, 0
_080B0F1C: .4byte 0x00000C6C
_080B0F20: .4byte 0x000012DC
_080B0F24: .4byte 0x00001284
_080B0F28: .4byte 0x00001286
_080B0F2C: .4byte 0x030046B8
_080B0F30: .4byte 0x000003FF
_080B0F34: .4byte 0x0203B400
_080B0F38:
	movs r1, #5
_080B0F3A:
	adds r0, r6, #0
	bl FUN_080b0aec
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080af374
	ldr r2, _080B1010 @ =0x0000067C
	adds r1, r6, r2
	movs r0, #0
	mov r8, r0
	movs r0, #0xa0
	strh r0, [r1]
	ldr r1, _080B1014 @ =0x0000067E
	adds r0, r6, r1
	mov r2, r8
	strh r2, [r0]
	ldr r5, _080B1018 @ =0x0203B400
	ldr r0, _080B101C @ =0x030046B8
	mov ip, r0
	ldr r1, [r0]
	adds r1, #1
	ldr r4, _080B1020 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #0xf
	ands r0, r2
	adds r3, r0, #0
	adds r3, #8
	movs r0, #0xd0
	lsls r0, r0, #3
	adds r2, r6, r0
	strh r3, [r2]
	adds r1, #1
	ands r1, r4
	mov r0, ip
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080B0F9A
	rsbs r0, r3, #0
	strh r0, [r2]
_080B0F9A:
	mov r2, ip
	ldr r1, [r2]
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r3, #0x3f
	ands r0, r3
	adds r0, #0xc0
	ldr r2, _080B1024 @ =0x00000682
	strh r0, [r2, r6]
	ldr r0, _080B1028 @ =0x0000068C
	adds r2, r6, r0
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080B102C @ =0x00000684
	adds r0, r6, r2
	mov r2, r8
	strh r2, [r0]
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrb r0, [r0]
	adds r0, #0xc0
	ldr r2, _080B1030 @ =0x00000686
	strh r0, [r2, r6]
	adds r1, #1
	ands r1, r4
	mov r0, ip
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	ands r0, r3
	adds r0, #0x40
	adds r2, #2
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0xd3
	lsls r0, r0, #3
	adds r1, r6, r0
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_080b0e58
	ldr r1, _080B1034 @ =0x000006AC
	adds r0, r6, r1
	str r7, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B1010: .4byte 0x0000067C
_080B1014: .4byte 0x0000067E
_080B1018: .4byte 0x0203B400
_080B101C: .4byte 0x030046B8
_080B1020: .4byte 0x000003FF
_080B1024: .4byte 0x00000682
_080B1028: .4byte 0x0000068C
_080B102C: .4byte 0x00000684
_080B1030: .4byte 0x00000686
_080B1034: .4byte 0x000006AC

	thumb_func_start FUN_080b1038
FUN_080b1038: @ 0x080B1038
	push {r4, r5, lr}
	adds r4, r2, #0
	movs r2, #0
	ldrsh r3, [r0, r2]
	movs r5, #0
	ldrsh r2, [r1, r5]
	subs r3, r3, r2
	movs r5, #4
	ldrsh r2, [r0, r5]
	movs r5, #4
	ldrsh r0, [r1, r5]
	subs r1, r2, r0
	cmp r3, r4
	bgt _080B106C
	cmp r1, r4
	bgt _080B106C
	adds r0, r3, #0
	muls r0, r3, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	adds r1, r4, #0
	muls r1, r4, r1
	cmp r0, r1
	ble _080B1070
_080B106C:
	movs r0, #0
	b _080B1072
_080B1070:
	movs r0, #1
_080B1072:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b1078
FUN_080b1078: @ 0x080B1078
	push {r4, lr}
	adds r1, r0, #0
	ldr r0, _080B10B4 @ =0x03002C00
	ldr r3, [r0]
	cmp r3, #0
	beq _080B10BC
	ldr r0, _080B10B8 @ =0x03002BE0
	ldr r2, [r0]
	ldr r0, [r2, #0x1c]
	cmp r0, #1
	bne _080B10BC
	movs r4, #0xdf
	lsls r4, r4, #2
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #6
	bne _080B10BC
	adds r0, r3, #0
	adds r0, #0x48
	movs r2, #0xa2
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r2, #0x46
	bl FUN_080b1038
	cmp r0, #0
	beq _080B10BC
	movs r0, #1
	b _080B10BE
	.align 2, 0
_080B10B4: .4byte 0x03002C00
_080B10B8: .4byte 0x03002BE0
_080B10BC:
	movs r0, #0
_080B10BE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b10c4
FUN_080b10c4: @ 0x080B10C4
	push {r4, lr}
	movs r2, #0
	ldrb r1, [r0, #0x1e]
	cmp r2, r1
	bge _080B10F0
	adds r3, r1, #0
	ldr r4, _080B10E4 @ =0x00000BE8
	adds r1, r0, r4
_080B10D4:
	ldr r0, [r1]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #2
	beq _080B10E8
	movs r0, #0
	b _080B10F2
	.align 2, 0
_080B10E4: .4byte 0x00000BE8
_080B10E8:
	adds r1, #4
	adds r2, #1
	cmp r2, r3
	blt _080B10D4
_080B10F0:
	movs r0, #1
_080B10F2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b10f8
FUN_080b10f8: @ 0x080B10F8
	push {lr}
	adds r1, r0, #0
	ldr r0, _080B113C @ =0x03002BE0
	ldr r2, [r0]
	ldr r0, [r2, #0x1c]
	cmp r0, #1
	bne _080B1140
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _080B1140
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #7
	bne _080B1140
	adds r0, r2, #0
	adds r0, #0x2c
	movs r2, #0xa1
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r2, #0x64
	bl FUN_080b1038
	cmp r0, #0
	beq _080B1140
	movs r0, #1
	b _080B1142
	.align 2, 0
_080B113C: .4byte 0x03002BE0
_080B1140:
	movs r0, #0
_080B1142:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080b1148
FUN_080b1148: @ 0x080B1148
	push {lr}
	adds r1, r0, #0
	ldr r0, _080B1168 @ =0x03002C00
	ldr r0, [r0]
	adds r0, #0x48
	movs r2, #0xa2
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r2, #0xc8
	lsls r2, r2, #2
	bl FUN_080b1038
	cmp r0, #0
	bne _080B116C
	movs r0, #1
	b _080B116E
	.align 2, 0
_080B1168: .4byte 0x03002C00
_080B116C:
	movs r0, #0
_080B116E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080b1174
FUN_080b1174: @ 0x080B1174
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	bl FUN_080b1078
	cmp r0, #0
	beq _080B11A4
	ldr r0, _080B11AC @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #1
	rsbs r2, r2, #0
	movs r4, #0
	str r4, [sp]
	movs r1, #0
	movs r3, #0
	bl FUN_0807bb3c
	ldr r1, _080B11B0 @ =0x00000C16
	adds r0, r5, r1
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ad1ec
_080B11A4:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B11AC: .4byte 0x03002BE0
_080B11B0: .4byte 0x00000C16

	thumb_func_start FUN_080b11b4
FUN_080b11b4: @ 0x080B11B4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, _080B125C @ =0x000004FE
	adds r0, r0, r7
	mov sb, r0
	ldrh r0, [r0]
	adds r0, #1
	mov r1, sb
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #5
	bhi _080B127C
	mov r2, sb
	ldrh r0, [r2]
	movs r4, #6
	subs r4, r4, r0
	ldr r5, _080B1260 @ =0x03002C00
	ldr r0, [r5]
	adds r0, #0x48
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r6, r4, #1
	muls r0, r6, r0
	movs r2, #0xa2
	lsls r2, r2, #3
	adds r1, r7, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	adds r1, r4, #0
	bl Div
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080B1264 @ =0xFFFF0000
	mov r8, r1
	ldr r1, [sp]
	mov r2, r8
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldr r0, [r5]
	adds r0, #0x4c
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	ldr r2, _080B1268 @ =0x00000514
	adds r1, r7, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	adds r1, r4, #0
	bl Div
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	mov r2, r8
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	ldr r0, [r5]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r2, [r0]
	mov r0, sb
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B1272
	adds r0, r2, #0
	cmp r0, #0
	beq _080B1272
	cmp r0, #4
	bls _080B126C
	adds r2, #1
	b _080B126E
	.align 2, 0
_080B125C: .4byte 0x000004FE
_080B1260: .4byte 0x03002C00
_080B1264: .4byte 0xFFFF0000
_080B1268: .4byte 0x00000514
_080B126C:
	subs r2, #1
_080B126E:
	movs r0, #7
	ands r2, r0
_080B1272:
	mov r0, sp
	adds r1, r2, #0
	bl FUN_08086590
	b _080B13E6
_080B127C:
	cmp r1, #6
	bne _080B12C4
	ldr r1, _080B12BC @ =0x03002C00
	ldr r0, [r1]
	ldr r3, _080B12C0 @ =0x000001F5
	adds r2, r0, r3
	movs r0, #0xb
	strb r0, [r2]
	ldr r2, [r1]
	movs r1, #0xa2
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2, #0x48]
	str r1, [r2, #0x4c]
	adds r3, #0xb
	adds r2, r2, r3
	movs r0, #0
	strb r0, [r2]
	movs r0, #0x95
	lsls r0, r0, #2
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xf9
	bl PlaySound_082406e0
	b _080B13E6
	.align 2, 0
_080B12BC: .4byte 0x03002C00
_080B12C0: .4byte 0x000001F5
_080B12C4:
	cmp r1, #0x45
	bhi _080B1304
	ldr r2, _080B12F8 @ =0x00000C16
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #2
	beq _080B12E6
	cmp r1, #0x14
	bne _080B12E6
	ldr r1, _080B12FC @ =FUN_080adb5c
	adds r0, r7, #0
	bl FUN_080ad9f4
	movs r0, #0x93
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080B12E6:
	ldr r3, _080B1300 @ =0x000004FE
	adds r0, r7, r3
	ldrh r1, [r0]
	movs r0, #0x46
	subs r0, r0, r1
	asrs r0, r0, #1
	bl FUN_0823b9cc
	b _080B13E6
	.align 2, 0
_080B12F8: .4byte 0x00000C16
_080B12FC: .4byte FUN_080adb5c
_080B1300: .4byte 0x000004FE
_080B1304:
	ldr r1, _080B1348 @ =0x00000C16
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080B1354
	movs r4, #0
	ldrb r2, [r7, #0x1e]
	cmp r0, r2
	bge _080B132A
	ldr r3, _080B134C @ =0x00000BE8
	adds r5, r7, r3
_080B131A:
	ldm r5!, {r0}
	movs r1, #1
	bl FUN_080b283c
	adds r4, #1
	ldrb r0, [r7, #0x1e]
	cmp r4, r0
	blt _080B131A
_080B132A:
	ldr r0, _080B1350 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	bl FUN_0807b910
	movs r0, #0xfa
	bl PlaySound_082406e0
	adds r0, r7, #0
	movs r1, #2
	bl FUN_080ad1ec
	b _080B13E6
	.align 2, 0
_080B1348: .4byte 0x00000C16
_080B134C: .4byte 0x00000BE8
_080B1350: .4byte 0x03002BE0
_080B1354:
	cmp r0, #1
	bne _080B13AE
	ldr r4, _080B139C @ =0x03002BE0
	ldr r0, [r4]
	movs r1, #1
	rsbs r1, r1, #0
	bl FUN_0807b910
	ldr r0, [r4]
	bl FUN_0807d118
	movs r3, #0
	ldrb r0, [r7, #0x1e]
	cmp r3, r0
	bge _080B138C
	ldr r1, _080B13A0 @ =0x00000BE8
	adds r2, r7, r1
	adds r1, r0, #0
_080B1378:
	ldr r0, [r2]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #4
	bne _080B1384
	movs r3, #1
_080B1384:
	adds r2, #4
	subs r1, #1
	cmp r1, #0
	bne _080B1378
_080B138C:
	cmp r3, #0
	beq _080B13A4
	adds r0, r7, #0
	movs r1, #4
	bl FUN_080ad1ec
	b _080B13E6
	.align 2, 0
_080B139C: .4byte 0x03002BE0
_080B13A0: .4byte 0x00000BE8
_080B13A4:
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ad1ec
	b _080B13E6
_080B13AE:
	ldr r4, _080B13F4 @ =0x03002BE0
	ldr r0, [r4]
	movs r1, #1
	rsbs r1, r1, #0
	bl FUN_0807b910
	ldr r0, [r4]
	bl FUN_0807d118
	movs r0, #0xf5
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, _080B13F8 @ =0x03002C00
	ldr r0, [r0]
	ldr r2, _080B13FC @ =0x000001F5
	adds r1, r0, r2
	movs r0, #0xd
	strb r0, [r1]
	ldr r3, _080B1400 @ =0x00000C6C
	adds r0, r7, r3
	movs r1, #1
	bl FUN_080af374
	adds r0, r7, #0
	movs r1, #0xa
	bl FUN_080ad1ec
_080B13E6:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B13F4: .4byte 0x03002BE0
_080B13F8: .4byte 0x03002C00
_080B13FC: .4byte 0x000001F5
_080B1400: .4byte 0x00000C6C

	thumb_func_start FUN_080b1404
FUN_080b1404: @ 0x080B1404
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080b10c4
	cmp r0, #0
	beq _080B1428
	ldr r0, _080B1430 @ =0x03002BE0
	ldr r0, [r0]
	bl FUN_0807d118
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080ad1ec
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ad204
_080B1428:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B1430: .4byte 0x03002BE0

	thumb_func_start FUN_080b1434
FUN_080b1434: @ 0x080B1434
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _080B147C @ =0x03002C00
	ldr r0, [r0]
	ldr r1, _080B1480 @ =0x000001F5
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xb
	beq _080B1474
	adds r0, r4, #0
	bl FUN_080b1078
	cmp r0, #0
	beq _080B1474
	ldr r0, _080B1484 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	str r1, [sp]
	movs r3, #0
	bl FUN_0807bb3c
	ldr r5, _080B1488 @ =0x00000C16
	adds r1, r4, r5
	movs r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ad1ec
_080B1474:
	movs r2, #0
	ldrb r3, [r4, #0x1e]
	b _080B148E
	.align 2, 0
_080B147C: .4byte 0x03002C00
_080B1480: .4byte 0x000001F5
_080B1484: .4byte 0x03002BE0
_080B1488: .4byte 0x00000C16
_080B148C:
	adds r2, #1
_080B148E:
	cmp r2, r3
	bge _080B14AC
	lsls r1, r2, #2
	ldr r5, _080B14B4 @ =0x00000BE8
	adds r0, r4, r5
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #4
	bne _080B148C
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080ad1ec
_080B14AC:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B14B4: .4byte 0x00000BE8

	thumb_func_start FUN_080b14b8
FUN_080b14b8: @ 0x080B14B8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r7, #0
	movs r6, #0
	ldrb r0, [r4, #0x1e]
	cmp r7, r0
	bge _080B1506
_080B14C6:
	lsls r0, r6, #2
	ldr r2, _080B1560 @ =0x00000BE8
	adds r1, r4, r2
	adds r5, r1, r0
	ldr r1, [r5]
	adds r0, r1, #0
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #4
	bne _080B14FE
	adds r7, #1
	adds r0, r1, #0
	adds r0, #0xec
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B14FE
	movs r0, #0x93
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r4, #0
	ldr r1, _080B1564 @ =FUN_080adb5c
	bl FUN_080ad9f4
	ldr r0, [r5]
	adds r0, #0xec
	movs r1, #0
	strb r1, [r0]
_080B14FE:
	adds r6, #1
	ldrb r0, [r4, #0x1e]
	cmp r6, r0
	blt _080B14C6
_080B1506:
	ldr r2, _080B1568 @ =0x00001332
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _080B1522
	ldrb r0, [r4, #0x1e]
	cmp r7, r0
	blt _080B1522
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ad204
_080B1522:
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _080B1536
	ldr r1, _080B156C @ =FUN_080adce4
	adds r0, r4, #0
	bl FUN_080ad9f4
_080B1536:
	adds r0, r4, #0
	bl FUN_080b10f8
	cmp r0, #0
	beq _080B155A
	ldr r0, _080B1570 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0xa1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r2, #0
	movs r3, #4
	bl FUN_0807ba94
	adds r0, r4, #0
	movs r1, #5
	bl FUN_080ad1ec
_080B155A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B1560: .4byte 0x00000BE8
_080B1564: .4byte FUN_080adb5c
_080B1568: .4byte 0x00001332
_080B156C: .4byte FUN_080adce4
_080B1570: .4byte 0x03002BE0

	thumb_func_start FUN_080b1574
FUN_080b1574: @ 0x080B1574
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r6, _080B1620 @ =0x03002BE0
	ldr r5, [r6]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B1650
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	movs r2, #0x2c
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	lsls r0, r0, #0xe
	lsrs r0, r0, #0x10
	ldr r3, _080B1624 @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r3
	orrs r2, r0
	str r2, [sp]
	ldr r7, _080B1628 @ =0x00000502
	adds r0, r4, r7
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	movs r7, #0x2e
	ldrsh r1, [r5, r7]
	adds r0, r0, r1
	lsls r0, r0, #0xe
	lsrs r0, r0, #0x10
	lsls r0, r0, #0x10
	ldr r1, _080B162C @ =0x0000FFFF
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldr r1, _080B1630 @ =0x00000504
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r1, r0, #1
	adds r1, r1, r0
	movs r7, #0x30
	ldrsh r0, [r5, r7]
	adds r1, r1, r0
	lsls r1, r1, #0xe
	lsrs r1, r1, #0x10
	ldr r0, [sp, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #4]
	movs r0, #0x10
	mov r1, sp
	bl FUN_0823bb7c
	movs r1, #0xc1
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B1638
	ldr r0, [r6]
	movs r1, #1
	movs r2, #0
	bl FUN_0807bbb0
	movs r0, #5
	bl PlaySound_082406e0
	ldr r1, _080B1634 @ =FUN_080ada44
	adds r0, r4, #0
	bl FUN_080ad9f4
	adds r0, r4, #0
	movs r1, #7
	bl FUN_080ad1ec
	b _080B1650
	.align 2, 0
_080B1620: .4byte 0x03002BE0
_080B1624: .4byte 0xFFFF0000
_080B1628: .4byte 0x00000502
_080B162C: .4byte 0x0000FFFF
_080B1630: .4byte 0x00000504
_080B1634: .4byte FUN_080ada44
_080B1638:
	ldr r0, [r6]
	movs r1, #0
	movs r2, #0
	bl FUN_0807bbb0
	ldr r0, _080B1658 @ =0x00000197
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #6
	bl FUN_080ad1ec
_080B1650:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B1658: .4byte 0x00000197

	thumb_func_start FUN_080b165c
FUN_080b165c: @ 0x080B165C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080B16B0 @ =0x000004FE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1e
	bne _080B16BC
	movs r4, #0
	ldrb r2, [r5, #0x1e]
	cmp r4, r2
	bge _080B169E
_080B167A:
	lsls r0, r4, #2
	ldr r2, _080B16B4 @ =0x00000BE8
	adds r1, r5, r2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r1, #0
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #4
	bne _080B1696
	adds r0, r1, #0
	movs r1, #5
	bl FUN_080b283c
_080B1696:
	adds r4, #1
	ldrb r0, [r5, #0x1e]
	cmp r4, r0
	blt _080B167A
_080B169E:
	ldr r1, _080B16B8 @ =FUN_080adb5c
	adds r0, r5, #0
	bl FUN_080ad9f4
	movs r0, #4
	bl sound_fadeout_08240440
	b _080B170A
	.align 2, 0
_080B16B0: .4byte 0x000004FE
_080B16B4: .4byte 0x00000BE8
_080B16B8: .4byte FUN_080adb5c
_080B16BC:
	cmp r0, #0x5a
	bne _080B16D8
	movs r0, #0x10
	bl FUN_0823bca8
	ldr r0, _080B16D4 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0
	bl FUN_0807bc64
	b _080B170A
	.align 2, 0
_080B16D4: .4byte 0x03002BE0
_080B16D8:
	cmp r0, #0x69
	bls _080B170A
	ldr r0, _080B1710 @ =0x03002BE0
	ldr r1, [r0]
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B170A
	adds r0, r1, #0
	bl FUN_0807d118
	adds r0, r5, #0
	movs r1, #3
	bl FUN_080ad1ec
	ldr r0, _080B1714 @ =0x00001332
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #2
	bl FUN_080ad204
_080B170A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B1710: .4byte 0x03002BE0
_080B1714: .4byte 0x00001332

	thumb_func_start FUN_080b1718
FUN_080b1718: @ 0x080B1718
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B1760 @ =0x000004FE
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x45
	bhi _080B173A
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x46
	bne _080B173A
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080ad204
_080B173A:
	ldr r1, _080B1764 @ =0x00001333
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B175A
	ldr r0, _080B1768 @ =0x00001334
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x3b
	bhi _080B1752
	adds r0, #1
	strh r0, [r1]
_080B1752:
	ldrh r0, [r1]
	lsrs r0, r0, #1
	bl FUN_0823b9cc
_080B175A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B1760: .4byte 0x000004FE
_080B1764: .4byte 0x00001333
_080B1768: .4byte 0x00001334

	thumb_func_start FUN_080b176c
FUN_080b176c: @ 0x080B176C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B1780 @ =0x000004FE
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x1d
	bhi _080B1784
	adds r0, #1
	strh r0, [r1]
	b _080B17AA
	.align 2, 0
_080B1780: .4byte 0x000004FE
_080B1784:
	ldr r1, _080B17B0 @ =0x00000C12
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B17AA
	movs r0, #0xf5
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, _080B17B4 @ =0x03002C00
	ldr r0, [r0]
	ldr r2, _080B17B8 @ =0x000001F5
	adds r1, r0, r2
	movs r0, #0xd
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #9
	bl FUN_080ad1ec
_080B17AA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B17B0: .4byte 0x00000C12
_080B17B4: .4byte 0x03002C00
_080B17B8: .4byte 0x000001F5

	thumb_func_start FUN_080b17bc
FUN_080b17bc: @ 0x080B17BC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B17E8 @ =0x03002C00
	ldr r0, [r0]
	ldr r1, _080B17EC @ =0x000001F5
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xc
	bne _080B17E0
	ldr r1, _080B17F0 @ =0x00000C6C
	adds r0, r4, r1
	movs r1, #1
	bl FUN_080af374
	adds r0, r4, #0
	movs r1, #0xa
	bl FUN_080ad1ec
_080B17E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B17E8: .4byte 0x03002C00
_080B17EC: .4byte 0x000001F5
_080B17F0: .4byte 0x00000C6C

	thumb_func_start FUN_080b17f4
FUN_080b17f4: @ 0x080B17F4
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	movs r1, #0xc1
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r3, _080B184C @ =0x030046A0
	cmp r0, #0
	beq _080B1828
	ldrb r0, [r4, #0x1e]
	cmp r5, r0
	bge _080B1828
	subs r1, #0x28
	adds r2, r4, r1
	adds r1, r0, #0
_080B1814:
	ldr r0, [r2]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #4
	bne _080B1820
	movs r5, #1
_080B1820:
	adds r2, #4
	subs r1, #1
	cmp r1, #0
	bne _080B1814
_080B1828:
	ldr r0, [r3]
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	ble _080B183C
	adds r0, r4, #0
	bl FUN_080af0ac
_080B183C:
	cmp r5, #0
	beq _080B1854
	ldr r0, _080B1850 @ =0x000004FE
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	b _080B1878
	.align 2, 0
_080B184C: .4byte 0x030046A0
_080B1850: .4byte 0x000004FE
_080B1854:
	ldr r0, _080B1880 @ =0x000004FE
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bls _080B1878
	ldr r1, _080B1884 @ =0x00000C6C
	adds r0, r4, r1
	movs r1, #6
	bl FUN_080af374
	adds r0, r4, #0
	movs r1, #0xb
	bl FUN_080ad1ec
_080B1878:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B1880: .4byte 0x000004FE
_080B1884: .4byte 0x00000C6C

	thumb_func_start FUN_080b1888
FUN_080b1888: @ 0x080B1888
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080B18BC @ =0x000012E4
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080B18B6
	ldr r0, _080B18C0 @ =0x000001EB
	bl PlaySound_082406e0
	movs r1, #0xa2
	lsls r1, r1, #3
	adds r0, r4, r1
	bl FUN_08086b18
	adds r0, r4, #0
	movs r1, #0xc
	bl FUN_080ad1ec
	adds r0, r4, #0
	movs r1, #5
	bl FUN_080ad204
_080B18B6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B18BC: .4byte 0x000012E4
_080B18C0: .4byte 0x000001EB

	thumb_func_start FUN_080b18c4
FUN_080b18c4: @ 0x080B18C4
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	bl FUN_080b1078
	cmp r0, #0
	beq _080B1900
	ldr r0, _080B18F8 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	str r1, [sp]
	movs r3, #0
	bl FUN_0807bb3c
	ldr r0, _080B18FC @ =0x00000C16
	adds r1, r5, r0
	movs r0, #2
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ad1ec
	b _080B19B2
	.align 2, 0
_080B18F8: .4byte 0x03002BE0
_080B18FC: .4byte 0x00000C16
_080B1900:
	adds r0, r5, #0
	bl FUN_080b1148
	cmp r0, #0
	beq _080B19B2
	ldr r0, _080B1960 @ =0x03002C00
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x48
	movs r3, #0
	ldrsh r2, [r0, r3]
	ldr r6, _080B1964 @ =0x03002BE0
	ldr r4, [r6]
	movs r3, #0x2c
	ldrsh r0, [r4, r3]
	subs r2, r2, r0
	adds r1, #0x4c
	movs r0, #0
	ldrsh r1, [r1, r0]
	movs r3, #0x30
	ldrsh r0, [r4, r3]
	subs r1, r1, r0
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #1
	bls _080B193C
	cmp r0, #5
	bne _080B1968
_080B193C:
	adds r0, r2, #0
	bl FUN_0823785c
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r1, #0x10
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #5
	adds r1, #3
	movs r0, #7
	ands r1, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0807b9dc
	b _080B1990
	.align 2, 0
_080B1960: .4byte 0x03002C00
_080B1964: .4byte 0x03002BE0
_080B1968:
	adds r0, r2, #0
	bl FUN_0823785c
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r1, #0x10
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #5
	adds r1, #3
	movs r0, #7
	ands r1, r0
	adds r0, r4, #0
	bl FUN_0807b910
	ldr r0, [r6]
	movs r1, #0
	bl FUN_0807cc84
_080B1990:
	ldr r4, _080B19BC @ =0x03002C00
	ldr r0, [r4]
	bl FUN_0808613c
	ldr r1, [r4]
	adds r1, #0x48
	movs r0, #0x10
	bl FUN_0823bb7c
	adds r0, r5, #0
	movs r1, #0xd
	bl FUN_080ad1ec
	adds r0, r5, #0
	movs r1, #6
	bl FUN_080ad204
_080B19B2:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B19BC: .4byte 0x03002C00

	thumb_func_start FUN_080b19c0
FUN_080b19c0: @ 0x080B19C0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _080B1A70 @ =0x000004FE
	adds r5, r6, r0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x21
	bne _080B1A16
	ldr r0, _080B1A74 @ =0x03002C00
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x48
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, _080B1A78 @ =0x03002BE0
	ldr r4, [r1]
	movs r3, #0x2c
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	adds r2, #0x4c
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r3, #0x30
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r1, #0x10
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #5
	adds r1, #3
	movs r0, #7
	ands r1, r0
	adds r0, r4, #0
	bl FUN_0807b910
_080B1A16:
	ldrh r0, [r5]
	cmp r0, #0x40
	bne _080B1A22
	ldr r0, _080B1A7C @ =0x000001C5
	bl PlaySound_082406e0
_080B1A22:
	ldrh r0, [r5]
	cmp r0, #0xf0
	bne _080B1A34
	ldr r0, _080B1A78 @ =0x03002BE0
	ldr r1, [r0]
	adds r1, #0x2c
	movs r0, #0x10
	bl FUN_0823bb7c
_080B1A34:
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bne _080B1A56
	ldr r1, _080B1A80 @ =0x00001346
	adds r0, r6, r1
	ldrh r0, [r0]
	bl PlaySound_082406e0
	ldr r0, _080B1A78 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	movs r2, #0
	bl FUN_0807bcb0
_080B1A56:
	ldrh r1, [r5]
	movs r0, #0x96
	lsls r0, r0, #1
	cmp r1, r0
	bne _080B1A68
	adds r0, r6, #0
	movs r1, #7
	bl FUN_080ad204
_080B1A68:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B1A70: .4byte 0x000004FE
_080B1A74: .4byte 0x03002C00
_080B1A78: .4byte 0x03002BE0
_080B1A7C: .4byte 0x000001C5
_080B1A80: .4byte 0x00001346

	thumb_func_start FUN_080b1a84
FUN_080b1a84: @ 0x080B1A84
	bx lr
	.align 2, 0

	thumb_func_start FUN_080b1a88
FUN_080b1a88: @ 0x080B1A88
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r1, _080B1B14 @ =0x00000C0F
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B1B0A
	movs r2, #0x95
	lsls r2, r2, #2
	adds r4, r6, r2
	mov r8, r4
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r5, r6, r0
	ldr r1, _080B1B18 @ =0x0000C039
	adds r0, r5, #0
	bl Video_GetActorSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0822a470
	movs r0, #3
	strb r0, [r4, #7]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0822b234
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r7, r6, r1
	ldr r2, [r5, #0xc]
	adds r1, r7, #0
	movs r3, #0xf
_080B1AD2:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _080B1AD2
	str r7, [r5, #0xc]
	adds r0, r4, #0
	adds r0, #0x6a
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	mov r2, r8
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	adds r1, r4, #0
	adds r1, #0x68
	movs r0, #1
	strh r0, [r1]
_080B1B0A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B1B14: .4byte 0x00000C0F
_080B1B18: .4byte 0x0000C039

	thumb_func_start FUN_080b1b1c
FUN_080b1b1c: @ 0x080B1B1C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xa3
	lsls r0, r0, #3
	adds r4, r5, r0
	adds r0, #0x2c
	adds r6, r5, r0
	ldr r1, _080B1B70 @ =0x00003641
	adds r0, r6, #0
	bl Video_GetActorSprite
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_0822a470
	movs r0, #0
	strh r0, [r4, #0x10]
	ldr r0, [r4]
	movs r1, #2
	orrs r0, r1
	str r0, [r4]
	movs r0, #0x60
	strb r0, [r4, #9]
	strb r0, [r4, #8]
	movs r0, #1
	strb r0, [r4, #7]
	movs r0, #0xa2
	lsls r0, r0, #3
	adds r5, r5, r0
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldrh r0, [r4, #0x1e]
	adds r0, #0x48
	strh r0, [r4, #0x1e]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B1B70: .4byte 0x00003641

	thumb_func_start FUN_080b1b74
FUN_080b1b74: @ 0x080B1B74
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	mov r8, r0
	ldrh r0, [r0, #0x1a]
	movs r1, #0
	str r1, [sp, #0x30]
	cmp r0, #1
	bne _080B1B90
	movs r2, #1
	str r2, [sp, #0x30]
_080B1B90:
	movs r0, #0x67
	bl prepare_08231510
	cmp r0, #0
	bne _080B1BA4
	movs r3, #0x64
	str r3, [sp, #0x28]
	movs r4, #0
	str r4, [sp, #0x2c]
	b _080B1BB0
_080B1BA4:
	bl Script_GetValue
	str r0, [sp, #0x28]
	bl Script_GetValue
	str r0, [sp, #0x2c]
_080B1BB0:
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	bne _080B1BE0
	movs r7, #0
	mov r0, r8
	ldrb r0, [r0, #0x1e]
	cmp r7, r0
	bge _080B1C04
	movs r0, #0
	add r2, sp, #0x10
	ldr r1, _080B1BDC @ =0x00000BE8
	add r1, r8
_080B1BCC:
	stm r1!, {r0}
	stm r2!, {r0}
	adds r7, #1
	mov r3, r8
	ldrb r3, [r3, #0x1e]
	cmp r7, r3
	blt _080B1BCC
	b _080B1C04
	.align 2, 0
_080B1BDC: .4byte 0x00000BE8
_080B1BE0:
	movs r7, #0
	mov r4, r8
	ldrb r4, [r4, #0x1e]
	cmp r7, r4
	bge _080B1C04
	add r5, sp, #0x10
	ldr r4, _080B1C38 @ =0x00000BE8
	add r4, r8
_080B1BF0:
	movs r0, #0
	stm r4!, {r0}
	bl Script_GetValue
	stm r5!, {r0}
	adds r7, #1
	mov r0, r8
	ldrb r0, [r0, #0x1e]
	cmp r7, r0
	blt _080B1BF0
_080B1C04:
	movs r7, #0
	mov r1, r8
	ldrb r1, [r1, #0x1e]
	cmp r7, r1
	blt _080B1C10
	b _080B1D48
_080B1C10:
	ldr r2, _080B1C3C @ =0xFFFFFDFE
	mov sl, r2
	add r5, sp, #0x20
	ldr r3, _080B1C40 @ =0xFFFF0000
	mov sb, r3
_080B1C1A:
	movs r0, #0xa0
	lsls r0, r0, #3
	add r0, r8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	cmp r7, #1
	beq _080B1CD4
	cmp r7, #1
	bgt _080B1C44
	cmp r7, #0
	beq _080B1C4E
	b _080B1D08
	.align 2, 0
_080B1C38: .4byte 0x00000BE8
_080B1C3C: .4byte 0xFFFFFDFE
_080B1C40: .4byte 0xFFFF0000
_080B1C44:
	cmp r7, #2
	beq _080B1C7A
	cmp r7, #3
	beq _080B1CA6
	b _080B1D08
_080B1C4E:
	ldrh r1, [r5]
	add r1, sl
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x20]
	mov r4, sb
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x20]
	ldrh r1, [r5, #4]
	adds r1, #0x4c
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r5, #4]
	movs r0, #1
	mov ip, r0
	movs r6, #0
	movs r2, #6
	b _080B1D10
_080B1C7A:
	ldrh r1, [r5]
	adds r1, #0x4c
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x20]
	mov r2, sb
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	ldrh r1, [r5, #4]
	add r1, sl
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	movs r3, #1
	mov ip, r3
	movs r6, #1
	movs r2, #3
	b _080B1D10
_080B1CA6:
	ldrh r1, [r5]
	subs r1, #0x4c
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x20]
	mov r4, sb
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x20]
	ldrh r1, [r5, #4]
	ldr r0, _080B1CD0 @ =0x00000202
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r5, #4]
	movs r1, #0
	mov ip, r1
	b _080B1D0C
	.align 2, 0
_080B1CD0: .4byte 0x00000202
_080B1CD4:
	ldrh r1, [r5]
	ldr r2, _080B1D04 @ =0x00000202
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x20]
	mov r3, sb
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x20]
	ldrh r1, [r5, #4]
	subs r1, #0x4c
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r5, #4]
	movs r4, #0
	mov ip, r4
	movs r6, #1
	movs r2, #9
	b _080B1D10
	.align 2, 0
_080B1D04: .4byte 0x00000202
_080B1D08:
	movs r0, #0
	mov ip, r0
_080B1D0C:
	movs r6, #0
	movs r2, #0
_080B1D10:
	add r1, sp, #0x20
	lsls r4, r7, #2
	mov r0, sp
	adds r0, r0, r4
	adds r0, #0x10
	ldr r3, [r0]
	ldr r0, [sp, #0x30]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	str r0, [sp, #4]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	adds r0, r1, #0
	mov r1, ip
	adds r2, r6, #0
	bl Entity080b3898_Create
	ldr r1, _080B1D58 @ =0x00000BE8
	add r1, r8
	adds r1, r1, r4
	str r0, [r1]
	adds r7, #1
	mov r1, r8
	ldrb r1, [r1, #0x1e]
	cmp r7, r1
	bge _080B1D48
	b _080B1C1A
_080B1D48:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B1D58: .4byte 0x00000BE8

	thumb_func_start FUN_080b1d5c
FUN_080b1d5c: @ 0x080B1D5C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _080B1D8A
	bl Script_GetValue
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r1, r4, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r5, _080B1DD8 @ =0x00000502
	adds r1, r4, r5
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _080B1DDC @ =0x00000504
	adds r1, r4, r2
	strh r0, [r1]
_080B1D8A:
	movs r5, #0xa1
	lsls r5, r5, #3
	adds r2, r4, r5
	movs r0, #0xa0
	lsls r0, r0, #3
	adds r3, r4, r0
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r1, #0
	ldrh r5, [r2]
	adds r1, r0, r5
	strh r1, [r2]
	ldr r2, _080B1DE0 @ =0x0000050C
	adds r1, r4, r2
	ldrh r5, [r1]
	adds r0, r0, r5
	strh r0, [r1]
	movs r0, #0xa2
	lsls r0, r0, #3
	adds r2, r4, r0
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	subs r0, #0x14
	strh r0, [r2]
	ldr r2, _080B1DE4 @ =0x00000514
	adds r1, r4, r2
	ldrh r0, [r1]
	subs r0, #0x14
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B1DD8: .4byte 0x00000502
_080B1DDC: .4byte 0x00000504
_080B1DE0: .4byte 0x0000050C
_080B1DE4: .4byte 0x00000514

	thumb_func_start FUN_080b1de8
FUN_080b1de8: @ 0x080B1DE8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080B1E08
	bl Script_GetValue
	ldr r2, _080B1E04 @ =0x000017A4
	adds r1, r4, r2
	str r0, [r1]
	b _080B1E0E
	.align 2, 0
_080B1E04: .4byte 0x000017A4
_080B1E08:
	ldr r2, _080B1E14 @ =0x000017A4
	adds r0, r4, r2
	str r1, [r0]
_080B1E0E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B1E14: .4byte 0x000017A4

	thumb_func_start FUN_080b1e18
FUN_080b1e18: @ 0x080B1E18
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x62
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080B1E5C
	bl Script_GetValue
	ldr r2, _080B1E54 @ =0x00001336
	adds r1, r5, r2
	strb r0, [r1]
	bl Script_GetValue
	ldr r4, _080B1E58 @ =0x030046A0
	ldr r1, [r4]
	movs r2, #0xae
	lsls r2, r2, #2
	adds r1, r1, r2
	str r0, [r1]
	bl Script_GetValue
	ldr r1, [r4]
	movs r2, #0xaf
	lsls r2, r2, #2
	adds r1, r1, r2
	str r0, [r1]
	b _080B1E7A
	.align 2, 0
_080B1E54: .4byte 0x00001336
_080B1E58: .4byte 0x030046A0
_080B1E5C:
	ldr r2, _080B1E9C @ =0x00001336
	adds r0, r5, r2
	strb r1, [r0]
	ldr r2, _080B1EA0 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, _080B1EA4 @ =0x00001770
	str r1, [r0]
	ldr r0, [r2]
	movs r2, #0xaf
	lsls r2, r2, #2
	adds r0, r0, r2
	str r1, [r0]
_080B1E7A:
	ldr r0, _080B1EA0 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0xae
	lsls r2, r2, #2
	adds r1, r0, r2
	adds r2, #4
	adds r0, r0, r2
	ldr r0, [r0]
	asrs r0, r0, #2
	ldr r1, [r1]
	cmp r1, r0
	ble _080B1EAC
	ldr r0, _080B1EA8 @ =0x0000133F
	adds r1, r5, r0
	movs r0, #0
	b _080B1EB2
	.align 2, 0
_080B1E9C: .4byte 0x00001336
_080B1EA0: .4byte 0x030046A0
_080B1EA4: .4byte 0x00001770
_080B1EA8: .4byte 0x0000133F
_080B1EAC:
	ldr r2, _080B1ECC @ =0x0000133F
	adds r1, r5, r2
	movs r0, #1
_080B1EB2:
	strb r0, [r1]
	ldr r1, _080B1ED0 @ =0x00001336
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _080B1EC0
	b _080B2022
_080B1EC0:
	lsls r0, r0, #2
	ldr r1, _080B1ED4 @ =_080B1ED8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080B1ECC: .4byte 0x0000133F
_080B1ED0: .4byte 0x00001336
_080B1ED4: .4byte _080B1ED8
_080B1ED8: @ jump table
	.4byte _080B1EF0 @ case 0
	.4byte _080B1F28 @ case 1
	.4byte _080B1F5C @ case 2
	.4byte _080B1F94 @ case 3
	.4byte _080B1FC8 @ case 4
	.4byte _080B2000 @ case 5
_080B1EF0:
	movs r2, #0x9a
	lsls r2, r2, #5
	adds r1, r5, r2
	ldr r0, _080B1F14 @ =0x0000023F
	strh r0, [r1]
	ldr r0, _080B1F18 @ =0x00001342
	adds r1, r5, r0
	ldr r0, _080B1F1C @ =0x00000245
	strh r0, [r1]
	adds r2, #4
	adds r1, r5, r2
	adds r0, #0xd
	strh r0, [r1]
	ldr r0, _080B1F20 @ =0x00001346
	adds r1, r5, r0
	ldr r0, _080B1F24 @ =0x0000024B
	b _080B2020
	.align 2, 0
_080B1F14: .4byte 0x0000023F
_080B1F18: .4byte 0x00001342
_080B1F1C: .4byte 0x00000245
_080B1F20: .4byte 0x00001346
_080B1F24: .4byte 0x0000024B
_080B1F28:
	movs r2, #0x9a
	lsls r2, r2, #5
	adds r1, r5, r2
	movs r0, #0x90
	lsls r0, r0, #2
	strh r0, [r1]
	ldr r0, _080B1F50 @ =0x00001342
	adds r1, r5, r0
	ldr r0, _080B1F54 @ =0x00000246
	strh r0, [r1]
	adds r2, #4
	adds r1, r5, r2
	adds r0, #0xd
	strh r0, [r1]
	ldr r0, _080B1F58 @ =0x00001346
	adds r1, r5, r0
	movs r0, #0x93
	lsls r0, r0, #2
	b _080B2020
	.align 2, 0
_080B1F50: .4byte 0x00001342
_080B1F54: .4byte 0x00000246
_080B1F58: .4byte 0x00001346
_080B1F5C:
	movs r2, #0x9a
	lsls r2, r2, #5
	adds r1, r5, r2
	ldr r0, _080B1F80 @ =0x00000241
	strh r0, [r1]
	ldr r0, _080B1F84 @ =0x00001342
	adds r1, r5, r0
	ldr r0, _080B1F88 @ =0x00000247
	strh r0, [r1]
	adds r2, #4
	adds r1, r5, r2
	adds r0, #0xd
	strh r0, [r1]
	ldr r0, _080B1F8C @ =0x00001346
	adds r1, r5, r0
	ldr r0, _080B1F90 @ =0x0000024D
	b _080B2020
	.align 2, 0
_080B1F80: .4byte 0x00000241
_080B1F84: .4byte 0x00001342
_080B1F88: .4byte 0x00000247
_080B1F8C: .4byte 0x00001346
_080B1F90: .4byte 0x0000024D
_080B1F94:
	movs r2, #0x9a
	lsls r2, r2, #5
	adds r1, r5, r2
	ldr r0, _080B1FB8 @ =0x00000242
	strh r0, [r1]
	ldr r0, _080B1FBC @ =0x00001342
	adds r1, r5, r0
	movs r0, #0x92
	lsls r0, r0, #2
	strh r0, [r1]
	adds r2, #4
	adds r1, r5, r2
	adds r0, #0xd
	strh r0, [r1]
	ldr r0, _080B1FC0 @ =0x00001346
	adds r1, r5, r0
	ldr r0, _080B1FC4 @ =0x0000024E
	b _080B2020
	.align 2, 0
_080B1FB8: .4byte 0x00000242
_080B1FBC: .4byte 0x00001342
_080B1FC0: .4byte 0x00001346
_080B1FC4: .4byte 0x0000024E
_080B1FC8:
	movs r2, #0x9a
	lsls r2, r2, #5
	adds r1, r5, r2
	ldr r0, _080B1FEC @ =0x00000243
	strh r0, [r1]
	ldr r0, _080B1FF0 @ =0x00001342
	adds r1, r5, r0
	ldr r0, _080B1FF4 @ =0x00000249
	strh r0, [r1]
	adds r2, #4
	adds r1, r5, r2
	adds r0, #0xd
	strh r0, [r1]
	ldr r0, _080B1FF8 @ =0x00001346
	adds r1, r5, r0
	ldr r0, _080B1FFC @ =0x0000024F
	b _080B2020
	.align 2, 0
_080B1FEC: .4byte 0x00000243
_080B1FF0: .4byte 0x00001342
_080B1FF4: .4byte 0x00000249
_080B1FF8: .4byte 0x00001346
_080B1FFC: .4byte 0x0000024F
_080B2000:
	movs r1, #0x9a
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r1, #0x91
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r2, _080B2038 @ =0x00001342
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, _080B203C @ =0x00001344
	adds r1, r5, r0
	ldr r0, _080B2040 @ =0x00000257
	strh r0, [r1]
	adds r2, #4
	adds r1, r5, r2
	subs r0, #7
_080B2020:
	strh r0, [r1]
_080B2022:
	movs r0, #0x54
	bl prepare_08231510
	cmp r0, #0
	beq _080B2048
	bl Script_GetValue
	ldr r2, _080B2044 @ =0x0000134E
	adds r1, r5, r2
	b _080B204E
	.align 2, 0
_080B2038: .4byte 0x00001342
_080B203C: .4byte 0x00001344
_080B2040: .4byte 0x00000257
_080B2044: .4byte 0x0000134E
_080B2048:
	ldr r0, _080B205C @ =0x0000134E
	adds r1, r5, r0
	movs r0, #0xa
_080B204E:
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080af0f8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B205C: .4byte 0x0000134E

	thumb_func_start FUN_080b2060
FUN_080b2060: @ 0x080B2060
	push {r4, lr}
	movs r2, #0
	ldrb r1, [r0, #0x1e]
	cmp r2, r1
	bge _080B208C
	adds r3, r1, #0
	ldr r4, _080B2080 @ =0x00000BE8
	adds r1, r0, r4
_080B2070:
	ldr r0, [r1]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B2084
	movs r0, #0
	b _080B208E
	.align 2, 0
_080B2080: .4byte 0x00000BE8
_080B2084:
	adds r1, #4
	adds r2, #1
	cmp r2, r3
	blt _080B2070
_080B208C:
	movs r0, #1
_080B208E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b2094
FUN_080b2094: @ 0x080B2094
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrh r6, [r5, #0x1a]
	cmp r6, #0
	beq _080B20A4
	cmp r6, #1
	beq _080B2148
	b _080B21CE
_080B20A4:
	adds r0, r5, #0
	bl FUN_080b2060
	cmp r0, #0
	beq _080B20BE
	adds r0, r5, #0
	bl FUN_080b1a88
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ad1ec
	b _080B21CE
_080B20BE:
	movs r0, #0x4f
	bl prepare_08231510
	cmp r0, #0
	beq _080B20CE
	bl Script_GetValue
	b _080B20D0
_080B20CE:
	movs r0, #0
_080B20D0:
	cmp r0, #0
	beq _080B2138
	ldr r2, _080B212C @ =0x03002C00
	ldr r0, [r2]
	cmp r0, #0
	beq _080B2138
	ldr r3, _080B2130 @ =0x000001F5
	adds r1, r0, r3
	movs r3, #0
	movs r0, #0xb
	strb r0, [r1]
	ldr r2, [r2]
	movs r1, #0xa2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2, #0x48]
	str r1, [r2, #0x4c]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r2, r2, r0
	strb r3, [r2]
	ldrb r0, [r5, #0x1e]
	cmp r3, r0
	bge _080B211E
	ldr r1, _080B2134 @ =0x00000BE8
	adds r2, r5, r1
	adds r1, r0, #0
_080B210A:
	ldr r0, [r2]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #4
	bne _080B2116
	movs r3, #1
_080B2116:
	adds r2, #4
	subs r1, #1
	cmp r1, #0
	bne _080B210A
_080B211E:
	cmp r3, #0
	beq _080B213E
	adds r0, r5, #0
	movs r1, #4
	bl FUN_080ad1ec
	b _080B21CE
	.align 2, 0
_080B212C: .4byte 0x03002C00
_080B2130: .4byte 0x000001F5
_080B2134: .4byte 0x00000BE8
_080B2138:
	adds r0, r5, #0
	bl FUN_080b1a88
_080B213E:
	adds r0, r5, #0
	movs r1, #3
	bl FUN_080ad1ec
	b _080B21CE
_080B2148:
	adds r0, r5, #0
	bl FUN_080b0e98
	adds r0, r5, #0
	bl FUN_080b1e18
	ldr r3, _080B2190 @ =0x03002C00
	ldr r0, [r3]
	ldr r2, _080B2194 @ =0x000001F5
	adds r1, r0, r2
	movs r4, #0
	movs r0, #0xb
	strb r0, [r1]
	ldr r2, [r3]
	movs r1, #0xa2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2, #0x48]
	str r1, [r2, #0x4c]
	movs r0, #0x80
	lsls r0, r0, #2
	adds r2, r2, r0
	strb r4, [r2]
	ldr r0, [r3]
	strb r6, [r0, #0x1b]
	ldr r0, [r3]
	ldrb r0, [r0, #0x1a]
	cmp r0, #6
	bne _080B219C
	ldr r2, _080B2198 @ =0x00000BF8
	adds r1, r5, r2
	movs r0, #0x50
	b _080B21B2
	.align 2, 0
_080B2190: .4byte 0x03002C00
_080B2194: .4byte 0x000001F5
_080B2198: .4byte 0x00000BF8
_080B219C:
	cmp r0, #7
	bne _080B21AC
	ldr r3, _080B21A8 @ =0x00000BF8
	adds r1, r5, r3
	movs r0, #0x78
	b _080B21B2
	.align 2, 0
_080B21A8: .4byte 0x00000BF8
_080B21AC:
	ldr r0, _080B21D4 @ =0x00000BF8
	adds r1, r5, r0
	movs r0, #0x64
_080B21B2:
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080ade88
	adds r0, r5, #0
	bl FUN_080ae394
	adds r0, r5, #0
	bl FUN_080b1b1c
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080ad1ec
_080B21CE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B21D4: .4byte 0x00000BF8

	thumb_func_start FUN_080b21d8
FUN_080b21d8: @ 0x080B21D8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _080B21EA
	bl Script_GetValue
_080B21EA:
	strh r0, [r4, #0x1a]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b21f4
FUN_080b21f4: @ 0x080B21F4
	push {lr}
	ldr r2, _080B221C @ =0x03002C58
	ldr r1, [r2]
	cmp r1, #0
	beq _080B2216
	ldr r0, _080B2220 @ =0x00000C0F
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r2]
	movs r2, #0xc1
	lsls r2, r2, #4
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r2, #1
	adds r0, r0, r2
	strb r1, [r0]
_080B2216:
	pop {r0}
	bx r0
	.align 2, 0
_080B221C: .4byte 0x03002C58
_080B2220: .4byte 0x00000C0F

	thumb_func_start FUN_080b2224
FUN_080b2224: @ 0x080B2224
	push {r4, lr}
	sub sp, #8
	ldr r4, _080B2268 @ =0x03002C58
	ldr r0, [r4]
	cmp r0, #0
	beq _080B22E0
	mov r0, sp
	bl FUN_0823167c
	ldr r0, [r4]
	ldrh r2, [r0, #0x1a]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	ldr r0, _080B226C @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _080B2280
	ldr r1, _080B2270 @ =0x000001F5
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xb
	bne _080B2274
	mov r0, sp
	movs r1, #0
	movs r2, #1
	bl FUN_0823206c
	b _080B228A
	.align 2, 0
_080B2268: .4byte 0x03002C58
_080B226C: .4byte 0x03002C00
_080B2270: .4byte 0x000001F5
_080B2274:
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl FUN_0823206c
	b _080B228A
_080B2280:
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl FUN_0823206c
_080B228A:
	movs r4, #0
_080B228C:
	mov r0, sp
	bl FUN_0823167c
	ldr r0, _080B22B8 @ =0x03002C58
	ldr r0, [r0]
	lsls r1, r4, #2
	ldr r2, _080B22BC @ =0x00000BE8
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080B22AC
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #1
	bhi _080B22C0
_080B22AC:
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl FUN_0823206c
	b _080B22DA
	.align 2, 0
_080B22B8: .4byte 0x03002C58
_080B22BC: .4byte 0x00000BE8
_080B22C0:
	cmp r0, #4
	bne _080B22D0
	mov r0, sp
	movs r1, #0
	movs r2, #4
	bl FUN_0823206c
	b _080B22DA
_080B22D0:
	mov r0, sp
	movs r1, #0
	movs r2, #2
	bl FUN_0823206c
_080B22DA:
	adds r4, #1
	cmp r4, #3
	ble _080B228C
_080B22E0:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b22e8
FUN_080b22e8: @ 0x080B22E8
	push {lr}
	ldr r3, _080B2308 @ =0x03002C58
	ldr r1, [r3]
	cmp r1, #0
	beq _080B2304
	ldr r0, _080B230C @ =0x00001333
	adds r1, r1, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r3]
	ldr r1, _080B2310 @ =0x00001334
	adds r0, r0, r1
	strh r2, [r0]
_080B2304:
	pop {r0}
	bx r0
	.align 2, 0
_080B2308: .4byte 0x03002C58
_080B230C: .4byte 0x00001333
_080B2310: .4byte 0x00001334

	thumb_func_start FUN_080b2314
FUN_080b2314: @ 0x080B2314
	push {lr}
	ldr r0, _080B232C @ =0x03002C58
	ldr r0, [r0]
	cmp r0, #0
	beq _080B2326
	ldr r2, _080B2330 @ =0x00000C12
	adds r1, r0, r2
	movs r0, #1
	strb r0, [r1]
_080B2326:
	pop {r0}
	bx r0
	.align 2, 0
_080B232C: .4byte 0x03002C58
_080B2330: .4byte 0x00000C12

	thumb_func_start FUN_080b2334
FUN_080b2334: @ 0x080B2334
	push {lr}
	ldr r0, _080B234C @ =0x03002C58
	ldr r0, [r0]
	cmp r0, #0
	beq _080B2346
	ldr r2, _080B2350 @ =0x00000C12
	adds r1, r0, r2
	movs r0, #0
	strb r0, [r1]
_080B2346:
	pop {r0}
	bx r0
	.align 2, 0
_080B234C: .4byte 0x03002C58
_080B2350: .4byte 0x00000C12

	thumb_func_start FUN_080b2354
FUN_080b2354: @ 0x080B2354
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, _080B23A4 @ =0x000017A8
	adds r5, r7, r0
	movs r6, #0
	ldr r2, _080B23A8 @ =0x03002B4C
	ldr r1, [r2]
	adds r1, #0x24
	ldr r3, _080B23AC @ =0x000017AE
	adds r0, r7, r3
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r6, r0
	bge _080B23EC
	mov r8, r2
_080B2378:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r6, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r5, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08022474
	ldrb r0, [r4, #6]
	cmp r0, #0
	beq _080B23B0
	cmp r0, #1
	beq _080B23C8
	b _080B23D8
	.align 2, 0
_080B23A4: .4byte 0x000017A8
_080B23A8: .4byte 0x03002B4C
_080B23AC: .4byte 0x000017AE
_080B23B0:
	ldrh r1, [r4, #8]
	ldr r2, _080B23C4 @ =0x00000C11
	adds r0, r7, r2
	strb r1, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08022488
	b _080B23D8
	.align 2, 0
_080B23C4: .4byte 0x00000C11
_080B23C8:
	adds r0, r7, #0
	ldr r1, _080B23F8 @ =FUN_080ada44
	bl FUN_080ad9f4
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08022488
_080B23D8:
	adds r6, #1
	mov r3, r8
	ldr r1, [r3]
	adds r1, #0x24
	adds r0, r5, #6
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r6, r0
	blt _080B2378
_080B23EC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B23F8: .4byte FUN_080ada44

	thumb_func_start FUN_080b23fc
FUN_080b23fc: @ 0x080B23FC
	push {lr}
	ldr r1, _080B240C @ =0x000017A8
	adds r0, r0, r1
	bl FUN_08022428
	pop {r0}
	bx r0
	.align 2, 0
_080B240C: .4byte 0x000017A8

	thumb_func_start FUN_080b2410
FUN_080b2410: @ 0x080B2410
	push {lr}
	ldr r1, _080B2424 @ =0x000017A8
	adds r2, r0, r1
	ldrh r1, [r0, #0x18]
	adds r0, r2, #0
	movs r2, #9
	bl FUN_080223f4
	pop {r0}
	bx r0
	.align 2, 0
_080B2424: .4byte 0x000017A8

	thumb_func_start FUN_080b2428
FUN_080b2428: @ 0x080B2428
	ldr r1, _080B2430 @ =0x03002C58
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080B2430: .4byte 0x03002C58

	thumb_func_start FUN_080b2434
FUN_080b2434: @ 0x080B2434
	push {lr}
	adds r2, r0, #0
	ldr r1, _080B2450 @ =0x00000C0F
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B245C
	ldr r0, _080B2454 @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _080B2458 @ =0x00000942
	adds r0, r0, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	b _080B2462
	.align 2, 0
_080B2450: .4byte 0x00000C0F
_080B2454: .4byte 0x030046A0
_080B2458: .4byte 0x00000942
_080B245C:
	ldr r1, _080B2470 @ =0x00000C11
	adds r0, r2, r1
	ldrb r1, [r0]
_080B2462:
	movs r3, #0xc1
	lsls r3, r3, #4
	adds r0, r2, r3
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_080B2470: .4byte 0x00000C11

	thumb_func_start FUN_080b2474
FUN_080b2474: @ 0x080B2474
	push {r4, lr}
	movs r3, #0
	ldrb r1, [r0, #0x1e]
	cmp r3, r1
	bge _080B2496
	ldr r4, _080B24A0 @ =0x00000BE8
	adds r2, r0, r4
_080B2482:
	ldr r0, [r2]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #4
	bne _080B248E
	adds r3, #1
_080B248E:
	adds r2, #4
	subs r1, #1
	cmp r1, #0
	bne _080B2482
_080B2496:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080B24A0: .4byte 0x00000BE8

	thumb_func_start FUN_080b24a4
FUN_080b24a4: @ 0x080B24A4
	push {lr}
	adds r3, r0, #0
	movs r1, #0xc1
	lsls r1, r1, #4
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B2518
	ldrb r0, [r3, #0x1f]
	cmp r0, #0
	beq _080B2518
	ldr r2, _080B2504 @ =0x000004FC
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r0, #0xa
	beq _080B24C8
	cmp r0, #0xe
	bne _080B2518
_080B24C8:
	movs r0, #0xa3
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #1
	strh r0, [r2, #0x10]
	ldr r2, _080B2508 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080B250C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080B2510 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x48
	ldr r2, _080B2514 @ =0x00000521
	adds r1, r3, r2
	strb r0, [r1]
	subs r2, #1
	adds r1, r3, r2
	strb r0, [r1]
	b _080B2526
	.align 2, 0
_080B2504: .4byte 0x000004FC
_080B2508: .4byte 0x030046B8
_080B250C: .4byte 0x000003FF
_080B2510: .4byte 0x0203B400
_080B2514: .4byte 0x00000521
_080B2518:
	movs r1, #0xa3
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_080B2526:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b252c
FUN_080b252c: @ 0x080B252C
	push {r4, r5, lr}
	sub sp, #8
	ldr r1, _080B2588 @ =0x03002BE0
	ldr r4, [r1]
	movs r2, #0x2c
	ldrsh r1, [r4, r2]
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r2, r0, r3
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r1, r1, r2
	lsls r1, r1, #0xf
	lsrs r1, r1, #0x10
	ldr r5, _080B258C @ =0xFFFF0000
	ldr r3, [sp]
	ands r3, r5
	orrs r3, r1
	str r3, [sp]
	ldrh r2, [r4, #0x2e]
	adds r2, #0x96
	lsls r2, r2, #0x10
	ldr r1, _080B2590 @ =0x0000FFFF
	ands r1, r3
	orrs r1, r2
	str r1, [sp]
	movs r2, #0x30
	ldrsh r1, [r4, r2]
	ldr r3, _080B2594 @ =0x00000504
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r1, r0
	lsls r1, r1, #0xf
	lsrs r1, r1, #0x10
	ldr r0, [sp, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	bl FUN_0823b8ac
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B2588: .4byte 0x03002BE0
_080B258C: .4byte 0xFFFF0000
_080B2590: .4byte 0x0000FFFF
_080B2594: .4byte 0x00000504

	thumb_func_start EntityCBB0_Update
EntityCBB0_Update: @ 0x080B2598
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080b2354
	adds r0, r4, #0
	bl FUN_080b2434
	adds r0, r4, #0
	bl FUN_080b2474
	strb r0, [r4, #0x1f]
	ldr r0, _080B25BC @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x1c]
	cmp r1, #4
	bne _080B25C0
	movs r0, #0
	b _080B26C2
	.align 2, 0
_080B25BC: .4byte 0x03002BE0
_080B25C0:
	ldrh r0, [r4, #0x1a]
	cmp r0, #1
	bne _080B2604
	ldr r2, _080B2628 @ =0x000004FC
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0xe
	beq _080B2604
	cmp r1, #1
	bne _080B2604
	ldr r0, _080B262C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _080B2604
	adds r0, r4, #0
	movs r1, #0xe
	bl FUN_080ad1ec
	ldr r2, _080B2630 @ =0x00000C6C
	adds r0, r4, r2
	movs r1, #9
	bl FUN_080af374
	adds r0, r4, #0
	bl FUN_080af0c8
	adds r0, r4, #0
	movs r1, #8
	bl FUN_080ad204
_080B2604:
	ldr r1, _080B2634 @ =0x085AD07C
	ldr r2, _080B2628 @ =0x000004FC
	adds r0, r4, r2
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrh r0, [r4, #0x1a]
	cmp r0, #0
	bne _080B2638
	adds r0, r4, #0
	bl FUN_080ad96c
	b _080B26BC
	.align 2, 0
_080B2628: .4byte 0x000004FC
_080B262C: .4byte 0x030046A0
_080B2630: .4byte 0x00000C6C
_080B2634: .4byte 0x085AD07C
_080B2638:
	adds r0, r4, #0
	bl FUN_080b09d4
	adds r0, r4, #0
	bl FUN_080b252c
	adds r0, r4, #0
	bl FUN_080ae8a4
	adds r0, r4, #0
	bl FUN_080ade4c
	adds r0, r4, #0
	bl FUN_080b24a4
	ldr r1, _080B2688 @ =0x0000133E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B26BC
	ldr r2, _080B268C @ =0x00000C0F
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B26B4
	ldr r0, _080B2690 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _080B2698
	ldr r2, _080B2694 @ =0x00001344
	adds r0, r4, r2
	ldrh r0, [r0]
	bl PlaySound_082406e0
	b _080B26AE
	.align 2, 0
_080B2688: .4byte 0x0000133E
_080B268C: .4byte 0x00000C0F
_080B2690: .4byte 0x030046A0
_080B2694: .4byte 0x00001344
_080B2698:
	ldr r1, _080B26C8 @ =0x0000133F
	adds r0, r4, r1
	ldrb r1, [r0]
	lsls r1, r1, #1
	movs r2, #0x9a
	lsls r2, r2, #5
	adds r0, r4, r2
	adds r0, r0, r1
	ldrh r0, [r0]
	bl PlaySound_082406e0
_080B26AE:
	ldr r0, _080B26CC @ =0x0000029B
	bl PlaySound_082406e0
_080B26B4:
	ldr r0, _080B26D0 @ =0x0000133E
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
_080B26BC:
	adds r0, r4, #0
	bl FUN_080ad23c
_080B26C2:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080B26C8: .4byte 0x0000133F
_080B26CC: .4byte 0x0000029B
_080B26D0: .4byte 0x0000133E

	thumb_func_start EntityCBB0_Destroy
EntityCBB0_Destroy: @ 0x080B26D4
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x1a]
	cmp r0, #0
	bne _080B26F4
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080B270E
	subs r1, #0x68
	adds r0, r4, r1
	bl FUN_0822a4e0
	b _080B270E
_080B26F4:
	ldr r1, _080B2728 @ =0x00000C6C
	adds r0, r4, r1
	bl FUN_080b0ab4
	movs r1, #0xa3
	lsls r1, r1, #3
	adds r0, r4, r1
	bl FUN_0822a4e0
	movs r0, #1
	movs r1, #1
	bl SetBGPrioDirect
_080B270E:
	adds r0, r4, #0
	bl FUN_080ad368
	adds r0, r4, #0
	bl FUN_080b23fc
	ldr r1, _080B272C @ =0x03002C58
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080B2728: .4byte 0x00000C6C
_080B272C: .4byte 0x03002C58

	thumb_func_start EntityCBB0_Init
EntityCBB0_Init: @ 0x080B2730
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x64
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080B2750
	bl Script_GetValue
	ldr r2, _080B274C @ =0x00000C0F
	adds r1, r4, r2
	strb r0, [r1]
	b _080B2756
	.align 2, 0
_080B274C: .4byte 0x00000C0F
_080B2750:
	ldr r2, _080B2788 @ =0x00000C0F
	adds r0, r4, r2
	strb r1, [r0]
_080B2756:
	ldr r0, _080B278C @ =0x03002BE0
	ldr r1, [r0]
	ldr r2, _080B2790 @ =0x000004F4
	adds r0, r4, r2
	str r1, [r0]
	movs r0, #0x9f
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _080B2794 @ =0x03002C00
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_080b1d5c
	adds r0, r4, #0
	bl FUN_080b21d8
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _080B2798
	bl Script_GetValue
	b _080B279A
	.align 2, 0
_080B2788: .4byte 0x00000C0F
_080B278C: .4byte 0x03002BE0
_080B2790: .4byte 0x000004F4
_080B2794: .4byte 0x03002C00
_080B2798:
	movs r0, #4
_080B279A:
	strb r0, [r4, #0x1e]
	adds r0, r4, #0
	bl FUN_080b1b74
	adds r0, r4, #0
	bl FUN_080b2094
	adds r0, r4, #0
	bl FUN_080ad388
	adds r0, r4, #0
	bl FUN_080ad544
	adds r0, r4, #0
	bl FUN_080b1de8
	adds r0, r4, #0
	bl FUN_080b2410
	ldr r0, _080B27E0 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080B27E4 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0xc1
	lsls r2, r2, #4
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _080B27E8 @ =0x03002C58
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080B27E0: .4byte 0x030046A0
_080B27E4: .4byte 0x00000942
_080B27E8: .4byte 0x03002C58

	thumb_func_start EntityCBB0_Create
EntityCBB0_Create: @ 0x080B27EC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080B2824 @ =0x03002C58
	ldr r0, [r0]
	cmp r0, #0
	bne _080B2836
	ldr r1, _080B2828 @ =0x000017DC
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080B2834
	ldr r1, _080B282C @ =EntityCBB0_Update
	ldr r2, _080B2830 @ =EntityCBB0_Destroy
	bl SetEntityRoutine
	strh r5, [r4, #0x18]
	adds r0, r4, #0
	bl EntityCBB0_Init
	cmp r0, #0
	bge _080B2834
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080B2836
	.align 2, 0
_080B2824: .4byte 0x03002C58
_080B2828: .4byte 0x000017DC
_080B282C: .4byte EntityCBB0_Update
_080B2830: .4byte EntityCBB0_Destroy
_080B2834:
	adds r0, r4, #0
_080B2836:
	pop {r4, r5}
	pop {r1}
	bx r1
