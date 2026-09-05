	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0813a26c
FUN_0813a26c: @ 0x0813A26C
	push {r4, r5, r6, r7, lr}
	ldrh r0, [r1, #0xa]
	cmp r0, #1
	beq _0813A276
	b _0813A406
_0813A276:
	adds r5, r2, #0
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0813A286
	b _0813A406
_0813A286:
	movs r0, #0xa
	ldrsh r1, [r5, r0]
	ldr r2, _0813A2C0 @ =0x03002BE0
	ldr r0, [r2]
	movs r3, #0x2e
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	ldr r0, _0813A2C4 @ =0x03002B8C
	ldrh r0, [r0]
	movs r3, #0
	adds r6, r2, #0
	cmp r0, #0
	beq _0813A2AA
	ldr r0, _0813A2C8 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _0813A2AA
	movs r3, #1
_0813A2AA:
	cmp r3, #0
	bne _0813A2BC
	ldr r0, [r6]
	movs r7, #0xd6
	lsls r7, r7, #2
	adds r0, r0, r7
	ldrb r0, [r0]
	cmp r0, #3
	bne _0813A2CC
_0813A2BC:
	movs r0, #0x3c
	b _0813A2D0
	.align 2, 0
_0813A2C0: .4byte 0x03002BE0
_0813A2C4: .4byte 0x03002B8C
_0813A2C8: .4byte 0x03002B60
_0813A2CC:
	movs r0, #0x82
	lsls r0, r0, #1
_0813A2D0:
	subs r0, r0, r1
	cmp r0, #0
	bge _0813A2D8
	rsbs r0, r0, #0
_0813A2D8:
	cmp r0, #0x20
	ble _0813A2DE
	b _0813A406
_0813A2DE:
	ldr r3, _0813A3A4 @ =FUN_080e48d0
	movs r2, #0x10
	ldr r1, _0813A3A8 @ =0x0000046D
	adds r0, r5, r1
	movs r1, #0
	movs r4, #1
	strb r4, [r0]
	ldr r7, _0813A3AC @ =0x0000046B
	adds r0, r5, r7
	strb r1, [r0]
	adds r7, #0xe8
	adds r0, r5, r7
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r2, #0
	strh r1, [r0]
	movs r3, #2
	subs r7, #0xeb
	adds r0, r5, r7
	strb r2, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r3, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r2, [r0]
	ldr r2, _0813A3B0 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r7, #2
	adds r0, r5, r7
	strb r4, [r0]
	movs r0, #0x94
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1, #6]
	movs r2, #4
	orrs r0, r2
	strh r0, [r1, #6]
	adds r1, r5, #0
	adds r1, #0xd8
	ldrh r0, [r1, #6]
	orrs r0, r2
	strh r0, [r1, #6]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _0813A3B4 @ =0x00000474
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r7, #0xc1
	lsls r7, r7, #1
	adds r2, r5, r7
	ldr r0, _0813A3B8 @ =0xFFFFFE7F
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0813A3C0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	movs r7, #0xcb
	lsls r7, r7, #3
	adds r0, r0, r7
	ldr r0, [r0]
	ands r0, r3
	ldr r0, [r6]
	movs r1, #0
	bl FUN_0807a904
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r1, r1, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0813A3BC @ =0x000002AD
	bl PlaySound_082406e0
	b _0813A406
	.align 2, 0
_0813A3A4: .4byte FUN_080e48d0
_0813A3A8: .4byte 0x0000046D
_0813A3AC: .4byte 0x0000046B
_0813A3B0: .4byte 0x00000484
_0813A3B4: .4byte 0x00000474
_0813A3B8: .4byte 0xFFFFFE7F
_0813A3BC: .4byte 0x000002AD
_0813A3C0:
	movs r7, #0xe6
	lsls r7, r7, #1
	adds r0, r5, r7
	ldr r0, [r0]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r0, [r0]
	ands r0, r3
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #2
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r1, r1, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r7, #0x90
	lsls r7, r7, #3
	adds r0, r5, r7
	ldrh r0, [r0]
	cmp r0, #1
	bne _0813A3FE
	ldr r0, [r6]
	movs r1, #1
	bl FUN_08063288
	b _0813A406
_0813A3FE:
	ldr r0, [r6]
	movs r1, #2
	bl FUN_08063288
_0813A406:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0813a40c
FUN_0813a40c: @ 0x0813A40C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0813A42E
	b _0813AAB4
_0813A42E:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0813A458
	ldr r3, _0813A454 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0813A446
	b _0813AAB4
_0813A446:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _0813AAB4
	.align 2, 0
_0813A454: .4byte 0x0000048C
_0813A458:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _0813A468
	b _0813AAB4
_0813A468:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _0813A478
	b _0813A784
_0813A478:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _0813A48A
	b _0813AAB4
_0813A48A:
	ldr r2, _0813A51C @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0813A49E
	b _0813AAB4
_0813A49E:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0813A4AC
	b _0813AAB4
_0813A4AC:
	movs r0, #0x3c
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0x14
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	bne _0813A4C4
	b _0813A60C
_0813A4C4:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _0813A52C
	ands r3, r1
	cmp r3, #0
	beq _0813A52C
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0813A4EA
	rsbs r1, r1, #0
_0813A4EA:
	cmp r1, #0x20
	bgt _0813A52C
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _0813A520 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _0813A524 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _0813A528 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _0813AAB4
	.align 2, 0
_0813A51C: .4byte 0x0000A007
_0813A520: .4byte 0x000004BE
_0813A524: .4byte 0x0000048C
_0813A528: .4byte 0x0000044E
_0813A52C:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _0813A554 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0813A55C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813A558 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0813A5CA
	.align 2, 0
_0813A554: .4byte 0x0000048A
_0813A558: .4byte 0x03002BE0
_0813A55C:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0813A578
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0813A574 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0813A5CA
	.align 2, 0
_0813A574: .4byte 0x03002BE0
_0813A578:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0813A594
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0813A590 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0813A5CA
	.align 2, 0
_0813A590: .4byte 0x03002BE0
_0813A594:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0813A5B0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0813A5AC @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0813A5CA
	.align 2, 0
_0813A5AC: .4byte 0x03002BE0
_0813A5B0:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0813A5C2
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0813A5CA
_0813A5C2:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0813A5CC
_0813A5CA:
	movs r3, #1
_0813A5CC:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, r8
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r5, _0813A600 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _0813A5EE
	b _0813A744
_0813A5EE:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813A604
	movs r0, #1
	b _0813A606
	.align 2, 0
_0813A600: .4byte 0x0000049C
_0813A604:
	movs r0, #0
_0813A606:
	cmp r0, #0
	bne _0813A6EA
	b _0813A700
_0813A60C:
	strh r2, [r7, #0x3e]
	ldr r1, _0813A634 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _0813A63C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813A638 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0813A6AA
	.align 2, 0
_0813A634: .4byte 0x0000048A
_0813A638: .4byte 0x03002BE0
_0813A63C:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0813A658
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0813A654 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0813A6AA
	.align 2, 0
_0813A654: .4byte 0x03002BE0
_0813A658:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _0813A674
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0813A670 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0813A6AA
	.align 2, 0
_0813A670: .4byte 0x03002BE0
_0813A674:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0813A690
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0813A68C @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0813A6AA
	.align 2, 0
_0813A68C: .4byte 0x03002BE0
_0813A690:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0813A6A2
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0813A6AA
_0813A6A2:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0813A6AC
_0813A6AA:
	movs r3, #1
_0813A6AC:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, r8
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r5, _0813A6E0 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _0813A744
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813A6E4
	movs r0, #1
	b _0813A6E6
	.align 2, 0
_0813A6E0: .4byte 0x0000049C
_0813A6E4:
	movs r0, #0
_0813A6E6:
	cmp r0, #0
	beq _0813A700
_0813A6EA:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813A6FC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0813A70C
	.align 2, 0
_0813A6FC: .4byte 0x03002BE0
_0813A700:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0813A744
_0813A70C:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_0813A744:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0813A770
	ldr r5, _0813A77C @ =0x0000024E
	adds r2, r6, r5
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _0813A770
	strh r1, [r2]
_0813A770:
	ldr r5, _0813A780 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _0813AAB4
	.align 2, 0
_0813A77C: .4byte 0x0000024E
_0813A780: .4byte 0x0000048C
_0813A784:
	ldr r0, _0813A798 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0813A79C
	movs r0, #1
	b _0813A79E
	.align 2, 0
_0813A798: .4byte 0x030047A4
_0813A79C:
	movs r0, #0
_0813A79E:
	cmp r0, #0
	beq _0813A7AC
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236640
	b _0813A7B4
_0813A7AC:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236524
_0813A7B4:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _0813A7EC @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _0813A7F0 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _0813A7E2
	cmp r2, #0x17
	bne _0813A7F4
_0813A7E2:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _0813A816
	.align 2, 0
_0813A7EC: .4byte 0x0000048C
_0813A7F0: .4byte 0x000001DF
_0813A7F4:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _0813A7E2
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _0813A844 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0813A816
	movs r1, #0
_0813A816:
	adds r0, r7, #0
	adds r0, #0x40
	strh r1, [r0]
	mov sb, r0
	movs r2, #6
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0813A852
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _0813A848
	asrs r0, r0, #1
	b _0813A84E
	.align 2, 0
_0813A844: .4byte 0x00000187
_0813A848:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0813A84E:
	mov r2, sb
	strh r0, [r2]
_0813A852:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0813A870
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _0813A86C @ =0x000001DD
	adds r1, r6, r4
	b _0813A8E4
	.align 2, 0
_0813A86C: .4byte 0x000001DD
_0813A870:
	mov r4, sp
	mov r3, r8
	adds r3, #0xc
	adds r2, r7, #0
	adds r2, #0xc
	ldrh r0, [r7, #0xc]
	mov r5, r8
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _0813A8D0
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _0813A8D0
	ldr r2, _0813A8C0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0813A8C4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0813A8C8 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _0813A8CC @ =0x000001DD
	adds r1, r6, r4
	b _0813A8E4
	.align 2, 0
_0813A8C0: .4byte 0x030046B8
_0813A8C4: .4byte 0x000003FF
_0813A8C8: .4byte 0x0203B400
_0813A8CC: .4byte 0x000001DD
_0813A8D0:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	ldr r3, _0813A904 @ =0x000001DD
	adds r1, r6, r3
_0813A8E4:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0813A90C
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0813A908 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0813A97A
	.align 2, 0
_0813A904: .4byte 0x000001DD
_0813A908: .4byte 0x03002BE0
_0813A90C:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0813A928
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0813A924 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0813A97A
	.align 2, 0
_0813A924: .4byte 0x03002BE0
_0813A928:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0813A944
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813A940 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0813A97A
	.align 2, 0
_0813A940: .4byte 0x03002BE0
_0813A944:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0813A960
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0813A95C @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0813A97A
	.align 2, 0
_0813A95C: .4byte 0x03002BE0
_0813A960:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0813A972
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _0813A97A
_0813A972:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0813A97C
_0813A97A:
	movs r3, #1
_0813A97C:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, r8
	ldr r1, [r2, #0x34]
	ldr r2, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	str r1, [r0]
	ldr r5, _0813A9B0 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _0813AA18
	movs r1, #2
	ldr r2, _0813A9B4 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813A9B8
	movs r0, #1
	b _0813A9BA
	.align 2, 0
_0813A9B0: .4byte 0x0000049C
_0813A9B4: .4byte 0x00000474
_0813A9B8:
	movs r0, #0
_0813A9BA:
	cmp r0, #0
	beq _0813A9D4
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813A9D0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0813A9E0
	.align 2, 0
_0813A9D0: .4byte 0x03002BE0
_0813A9D4:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0813AA18
_0813A9E0:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_0813AA18:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0813AA4C
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0813AA4C
	ldr r0, _0813AA64 @ =0x0000024E
	adds r2, r6, r0
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _0813AA4C
	strh r1, [r2]
_0813AA4C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0813AA68 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _0813AA6C @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813AA70
	movs r0, #1
	b _0813AA72
	.align 2, 0
_0813AA64: .4byte 0x0000024E
_0813AA68: .4byte 0x030046A0
_0813AA6C: .4byte 0x00000934
_0813AA70:
	movs r0, #0
_0813AA72:
	ldr r1, _0813AAC4 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _0813AA8A
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_0813AA8A:
	adds r0, r6, #0
	bl FUN_080e64e4
	ldrh r0, [r7, #0x3e]
	strh r0, [r4]
	movs r4, #0xc4
	lsls r4, r4, #1
	adds r1, r6, r4
	mov r5, r8
	ldrh r0, [r5, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0813AAB4:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813AAC4: .4byte 0x0000048A

	thumb_func_start FUN_0813aac8
FUN_0813aac8: @ 0x0813AAC8
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0813AAE8 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813AAEC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813AAEE
	.align 2, 0
_0813AAE8: .4byte 0x0000046D
_0813AAEC:
	movs r0, #0
_0813AAEE:
	cmp r0, #0
	beq _0813AB0C
	ldr r0, _0813AB5C @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r1, [r0]
	ldr r4, _0813AB60 @ =0x0000066B
	adds r0, r6, r4
	movs r2, #0
	strb r1, [r0]
	ldr r1, _0813AB64 @ =0x0000065E
	adds r0, r6, r1
	strh r2, [r0]
_0813AB0C:
	adds r0, r5, #0
	movs r1, #0xf
	bl FUN_080efe38
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ldr r3, _0813AB68 @ =0x0000065C
	adds r1, r6, r3
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _0813ABB2
	movs r4, #0x90
	lsls r4, r4, #3
	adds r2, r5, r4
	ldrh r3, [r2]
	cmp r3, #0
	bne _0813AB6C
	ldr r0, _0813AB5C @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x89
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r1, [r1]
	movs r4, #0x8b
	lsls r4, r4, #2
	adds r2, r5, r4
	ldrh r2, [r2]
	str r3, [sp]
	adds r4, #0x10
	adds r3, r5, r4
	ldr r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_0807e7fc
	b _0813ABB2
	.align 2, 0
_0813AB5C: .4byte 0x03002BE0
_0813AB60: .4byte 0x0000066B
_0813AB64: .4byte 0x0000065E
_0813AB68: .4byte 0x0000065C
_0813AB6C:
	ldr r0, _0813AB98 @ =0x0000065E
	adds r1, r6, r0
	movs r3, #0x89
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r0, [r0]
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x64
	bls _0813ABB2
	ldrh r0, [r2]
	cmp r0, #1
	bne _0813ABA0
	ldr r0, _0813AB9C @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #1
	bl FUN_08063288
	b _0813ABAA
	.align 2, 0
_0813AB98: .4byte 0x0000065E
_0813AB9C: .4byte 0x03002BE0
_0813ABA0:
	ldr r0, _0813ABD0 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #2
	bl FUN_08063288
_0813ABAA:
	ldr r0, _0813ABD4 @ =0x0000065E
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
_0813ABB2:
	ldr r1, _0813ABD8 @ =0x0000066B
	adds r0, r6, r1
	ldrb r2, [r0]
	ldr r0, _0813ABD0 @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r1, [r0]
	cmp r1, r2
	bge _0813ABE0
	ldr r4, _0813ABDC @ =0xFFFFFF00
	adds r0, r2, r4
	subs r4, r1, r0
	b _0813ABE2
	.align 2, 0
_0813ABD0: .4byte 0x03002BE0
_0813ABD4: .4byte 0x0000065E
_0813ABD8: .4byte 0x0000066B
_0813ABDC: .4byte 0xFFFFFF00
_0813ABE0:
	subs r4, r1, r2
_0813ABE2:
	ldr r0, _0813AC28 @ =0x0000066A
	adds r7, r6, r0
	ldrb r0, [r7]
	cmp r0, r4
	beq _0813AC06
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0813AC04
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0813AC04:
	strb r4, [r7]
_0813AC06:
	ldr r2, _0813AC28 @ =0x0000066A
	adds r0, r6, r2
	ldr r3, _0813AC2C @ =0x0000065D
	adds r1, r6, r3
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bls _0813AC1E
	ldr r4, _0813AC30 @ =0x0000046B
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
_0813AC1E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813AC28: .4byte 0x0000066A
_0813AC2C: .4byte 0x0000065D
_0813AC30: .4byte 0x0000046B

	thumb_func_start FUN_0813ac34
FUN_0813ac34: @ 0x0813AC34
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _0813AC8C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813AC4C
	movs r0, #0
	strb r0, [r1]
_0813AC4C:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_0813c994
	ldr r1, _0813AC90 @ =0x000004C4
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _0813AC94 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0813ACA0
	ldr r1, _0813AC98 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _0813AC9C @ =0x0000046E
	adds r7, r5, r0
	b _0813AD22
	.align 2, 0
_0813AC8C: .4byte 0x0000046D
_0813AC90: .4byte 0x000004C4
_0813AC94: .4byte 0x0000025D
_0813AC98: .4byte 0x000004B7
_0813AC9C: .4byte 0x0000046E
_0813ACA0:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _0813AD10 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0813AD14 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0813ACDA
	ldrb r0, [r7]
	cmp r0, #0
	bne _0813ACDA
	cmp r4, #1
	bne _0813ACCC
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0813AD26
_0813ACCC:
	cmp r4, #0
	bne _0813ACDA
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0813AD26
_0813ACDA:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0813ACEC
	movs r3, #6
_0813ACEC:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0813AD18
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _0813AD20
	.align 2, 0
_0813AD10: .4byte 0x000004B7
_0813AD14: .4byte 0x0000046E
_0813AD18:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0813AD20:
	str r0, [r6, #8]
_0813AD22:
	movs r0, #0
	strb r0, [r7]
_0813AD26:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0813ad34
FUN_0813ad34: @ 0x0813AD34
	push {lr}
	adds r2, r0, #0
	ldr r0, _0813AD4C @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813AD50
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813AD52
	.align 2, 0
_0813AD4C: .4byte 0x0000046D
_0813AD50:
	movs r0, #0
_0813AD52:
	cmp r0, #0
	beq _0813AD5E
	adds r0, r2, #0
	movs r1, #0x10
	bl FUN_080efe38
_0813AD5E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0813ad64
FUN_0813ad64: @ 0x0813AD64
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _0813ADC4 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813AD7C
	movs r0, #0
	strb r0, [r1]
_0813AD7C:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_0813c994
	ldr r1, _0813ADC8 @ =0x000004C4
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _0813ADCC @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0813ADD8
	ldr r1, _0813ADD0 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _0813ADD4 @ =0x0000046E
	adds r7, r5, r0
	b _0813AE5A
	.align 2, 0
_0813ADC4: .4byte 0x0000046D
_0813ADC8: .4byte 0x000004C4
_0813ADCC: .4byte 0x0000025D
_0813ADD0: .4byte 0x000004B7
_0813ADD4: .4byte 0x0000046E
_0813ADD8:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _0813AE48 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0813AE4C @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0813AE12
	ldrb r0, [r7]
	cmp r0, #0
	bne _0813AE12
	cmp r4, #1
	bne _0813AE04
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0813AE5E
_0813AE04:
	cmp r4, #0
	bne _0813AE12
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0813AE5E
_0813AE12:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0813AE24
	movs r3, #6
_0813AE24:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0813AE50
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _0813AE58
	.align 2, 0
_0813AE48: .4byte 0x000004B7
_0813AE4C: .4byte 0x0000046E
_0813AE50:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0813AE58:
	str r0, [r6, #8]
_0813AE5A:
	movs r0, #0
	strb r0, [r7]
_0813AE5E:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0813ae6c
FUN_0813ae6c: @ 0x0813AE6C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r5, #0
	ldr r0, _0813AE8C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813AE90
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813AE92
	.align 2, 0
_0813AE8C: .4byte 0x0000046D
_0813AE90:
	movs r0, #0
_0813AE92:
	cmp r0, #0
	beq _0813AF30
	ldrb r0, [r5, #5]
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r3, r0, #3
	movs r1, #7
	ands r3, r1
	movs r4, #0xee
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrb r4, [r0]
	adds r0, r4, #0
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	ands r0, r1
	cmp r3, r0
	bne _0813AF00
	movs r1, #0
	strb r4, [r5, #5]
	ldr r2, _0813AEF4 @ =0x000005A4
	adds r0, r5, r2
	ldr r3, [r0]
	ldr r4, _0813AEF8 @ =0x0000046D
	adds r0, r5, r4
	movs r2, #1
	strb r2, [r0]
	subs r4, #2
	adds r0, r5, r4
	strb r1, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	adds r4, #0x25
	adds r0, r5, r4
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	ldr r4, _0813AEFC @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	b _0813B0F2
	.align 2, 0
_0813AEF4: .4byte 0x000005A4
_0813AEF8: .4byte 0x0000046D
_0813AEFC: .4byte 0x0000046B
_0813AF00:
	subs r0, #8
	subs r0, r3, r0
	movs r1, #7
	ands r0, r1
	cmp r0, #4
	bgt _0813AF20
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _0813AF1C @ =0xFFFEFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _0813AF30
	.align 2, 0
_0813AF1C: .4byte 0xFFFEFFFF
_0813AF20:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0813AF30:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	mov r8, r0
	ldr r1, _0813AF54 @ =0x0000A02F
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813AF5C
	ldr r0, _0813AF58 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0813AF6C
	.align 2, 0
_0813AF54: .4byte 0x0000A02F
_0813AF58: .4byte 0x00000482
_0813AF5C:
	ldr r1, _0813AF94 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0813AF6C
	movs r0, #1
	strh r0, [r2]
_0813AF6C:
	ldr r3, _0813AF98 @ =0x0000025D
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	bne _0813AF9C
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _0813AFB4
	.align 2, 0
_0813AF94: .4byte 0x00000482
_0813AF98: .4byte 0x0000025D
_0813AF9C:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_0813AFB4:
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _0813AFC6
	b _0813B0F2
_0813AFC6:
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _0813B010 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0813B014 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
	movs r1, #0x80
	lsls r1, r1, #9
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813B018
	ldrb r0, [r6, #5]
	adds r0, #0x20
	b _0813B01C
	.align 2, 0
_0813B010: .4byte 0x0000046D
_0813B014: .4byte 0x0000046B
_0813B018:
	ldrb r0, [r6, #5]
	subs r0, #0x20
_0813B01C:
	strb r0, [r6, #5]
	ldrb r0, [r6, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_0813c994
	movs r0, #0
	mov r3, r8
	strb r0, [r3, #5]
	ldr r4, _0813B060 @ =0x000004C4
	adds r0, r5, r4
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldrb r0, [r7]
	cmp r0, #0
	bne _0813B06C
	ldr r1, _0813B064 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r2, _0813B068 @ =0x0000046E
	adds r7, r5, r2
	b _0813B0EE
	.align 2, 0
_0813B060: .4byte 0x000004C4
_0813B064: .4byte 0x000004B7
_0813B068: .4byte 0x0000046E
_0813B06C:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r3, _0813B0DC @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0813B0E0 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0813B0A6
	ldrb r0, [r7]
	cmp r0, #0
	bne _0813B0A6
	cmp r4, #1
	bne _0813B098
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0813B0F2
_0813B098:
	cmp r4, #0
	bne _0813B0A6
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0813B0F2
_0813B0A6:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0813B0B8
	movs r3, #6
_0813B0B8:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0813B0E4
	ldr r0, [r6, #8]
	mov r2, r8
	orrs r0, r2
	b _0813B0EC
	.align 2, 0
_0813B0DC: .4byte 0x000004B7
_0813B0E0: .4byte 0x0000046E
_0813B0E4:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0813B0EC:
	str r0, [r6, #8]
_0813B0EE:
	movs r0, #0
	strb r0, [r7]
_0813B0F2:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0813b100
FUN_0813b100: @ 0x0813B100
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	mov sb, r1
	ldr r0, _0813B15C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813B11C
	movs r0, #0
	strb r0, [r1]
_0813B11C:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_0813c994
	ldr r1, _0813B160 @ =0x000004EC
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _0813B164 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0813B170
	ldr r1, _0813B168 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _0813B16C @ =0x0000046E
	adds r7, r5, r0
	b _0813B1F2
	.align 2, 0
_0813B15C: .4byte 0x0000046D
_0813B160: .4byte 0x000004EC
_0813B164: .4byte 0x0000025D
_0813B168: .4byte 0x000004B7
_0813B16C: .4byte 0x0000046E
_0813B170:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _0813B1E0 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0813B1E4 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0813B1AA
	ldrb r0, [r7]
	cmp r0, #0
	bne _0813B1AA
	cmp r4, #1
	bne _0813B19C
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0813B1F6
_0813B19C:
	cmp r4, #0
	bne _0813B1AA
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0813B1F6
_0813B1AA:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0813B1BC
	movs r3, #6
_0813B1BC:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0813B1E8
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _0813B1F0
	.align 2, 0
_0813B1E0: .4byte 0x000004B7
_0813B1E4: .4byte 0x0000046E
_0813B1E8:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0813B1F0:
	str r0, [r6, #8]
_0813B1F2:
	movs r0, #0
	strb r0, [r7]
_0813B1F6:
	mov r0, sb
	cmp r0, #0x1d
	bgt _0813B20A
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0813B20A:
	mov r0, sb
	cmp r0, #0x3b
	ble _0813B218
	ldr r0, _0813B228 @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_0813B218:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813B228: .4byte 0x0000046B

	thumb_func_start FUN_0813b22c
FUN_0813b22c: @ 0x0813B22C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _0813B244 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813B248
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813B24A
	.align 2, 0
_0813B244: .4byte 0x0000046D
_0813B248:
	movs r0, #0
_0813B24A:
	cmp r0, #0
	beq _0813B254
	adds r0, r4, #0
	bl FUN_0813cd94
_0813B254:
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	movs r6, #0
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	cmp r5, #0x1e
	ble _0813B33E
	adds r0, r4, #0
	bl FUN_0813c938
	ldr r7, _0813B2D8 @ =0x0000024E
	adds r3, r4, r7
	ldrh r5, [r3]
	cmp r5, #0
	beq _0813B2E8
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	strh r0, [r3]
	ldr r0, _0813B2DC @ =0x03002BE0
	ldr r1, [r0]
	adds r1, #0x2c
	adds r0, r4, #0
	bl FUN_0813c9c4
	movs r1, #2
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r6, [r0]
	ldr r7, _0813B2E0 @ =0x00000469
	adds r0, r4, r7
	strb r1, [r0]
	ldr r1, _0813B2E4 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	adds r3, #0x1c
	adds r1, r4, r3
	movs r0, #0
	str r0, [r1]
	adds r7, #3
	adds r0, r4, r7
	strb r2, [r0]
	b _0813B33E
	.align 2, 0
_0813B2D8: .4byte 0x0000024E
_0813B2DC: .4byte 0x03002BE0
_0813B2E0: .4byte 0x00000469
_0813B2E4: .4byte 0x0000046A
_0813B2E8:
	ldr r3, _0813B344 @ =FUN_0813b100
	movs r2, #0xa
	ldr r1, _0813B348 @ =0x0000046D
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	ldr r7, _0813B34C @ =0x0000046B
	adds r0, r4, r7
	strb r6, [r0]
	adds r7, #0xe8
	adds r0, r4, r7
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r4, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r5, [r0]
	subs r7, #0xeb
	adds r0, r4, r7
	strb r6, [r0]
	ldr r2, _0813B350 @ =0x00000469
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _0813B354 @ =0x0000046A
	adds r0, r4, r3
	strb r1, [r0]
	adds r7, #0x1c
	adds r0, r4, r7
	str r5, [r0]
	adds r2, #3
	adds r0, r4, r2
	strb r1, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrb r0, [r0]
	strb r0, [r4, #5]
	subs r7, #2
	adds r0, r4, r7
	strh r1, [r0]
_0813B33E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813B344: .4byte FUN_0813b100
_0813B348: .4byte 0x0000046D
_0813B34C: .4byte 0x0000046B
_0813B350: .4byte 0x00000469
_0813B354: .4byte 0x0000046A

	thumb_func_start FUN_0813b358
FUN_0813b358: @ 0x0813B358
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _0813B380 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813B384
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813B386
	.align 2, 0
_0813B380: .4byte 0x0000046D
_0813B384:
	movs r0, #0
_0813B386:
	cmp r0, #0
	beq _0813B3DA
	movs r0, #0x20
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r4, r5, r6
	ldrh r1, [r4]
	movs r6, #0
	orrs r0, r1
	strh r0, [r4]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r1, #8
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0813B3B4
	movs r0, #0x95
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0813B3B4:
	movs r0, #0x94
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1, #6]
	movs r2, #4
	orrs r0, r2
	strh r0, [r1, #6]
	adds r1, r5, #0
	adds r1, #0xd8
	ldrh r0, [r1, #6]
	orrs r0, r2
	strh r0, [r1, #6]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _0813B40C @ =0x00000474
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0813B3DA:
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r1, r5, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r6, #0x83
	lsls r6, r6, #2
	adds r0, r5, r6
	movs r2, #0
	ldrsh r3, [r0, r2]
	adds r4, #0x98
	adds r2, r5, r4
	movs r6, #0
	ldrsh r0, [r2, r6]
	subs r0, r3, r0
	mov r8, r1
	adds r4, r2, #0
	cmp r0, #0
	blt _0813B410
	asrs r0, r0, #2
	b _0813B416
	.align 2, 0
_0813B40C: .4byte 0x00000474
_0813B410:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0813B416:
	adds r3, r0, #0
	movs r1, #0x84
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r6, #0
	ldrsh r0, [r1, r6]
	subs r0, r2, r0
	cmp r0, #0
	blt _0813B436
	asrs r0, r0, #2
	b _0813B43C
_0813B436:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0813B43C:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _0813B446
	movs r3, #0xc8
	b _0813B450
_0813B446:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _0813B450
	adds r3, r0, #0
_0813B450:
	cmp r2, #0xc8
	ble _0813B458
	movs r2, #0xc8
	b _0813B462
_0813B458:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0813B462
	adds r2, r0, #0
_0813B462:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r3
	strh r0, [r5, #0x10]
	ldrh r0, [r5, #0x14]
	adds r0, r0, r2
	strh r0, [r5, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _0813B486
	cmp r2, #0
	bne _0813B486
	movs r0, #1
	b _0813B488
_0813B486:
	movs r0, #0
_0813B488:
	cmp r0, #0
	bne _0813B48E
	b _0813B620
_0813B48E:
	ldr r1, _0813B538 @ =0x0000046B
	adds r0, r5, r1
	movs r4, #0
	movs r7, #1
	strb r7, [r0]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r3, r5, r2
	ldr r0, _0813B53C @ =0xFFFFFEDF
	ldrh r1, [r3]
	ands r0, r1
	movs r6, #0
	strh r0, [r3]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xd
	mov r2, r8
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r0, _0813B540 @ =0x00000666
	add r0, sb
	strb r6, [r0]
	movs r0, #8
	ldrh r2, [r3]
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	cmp r0, #0
	beq _0813B554
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _0813B544 @ =0x00000469
	adds r0, r5, r1
	strb r6, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r6, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r7, [r0]
	ldr r0, _0813B548 @ =FUN_0813b22c
	mov r8, r0
	movs r1, #0x14
	adds r2, #1
	adds r0, r5, r2
	strb r7, [r0]
	subs r2, #2
	adds r0, r5, r2
	strb r6, [r0]
	ldr r6, _0813B54C @ =0x00000553
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	mov r2, r8
	str r2, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r4, [r0]
	movs r0, #9
	rsbs r0, r0, #0
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	ldr r1, _0813B550 @ =0x00000482
	adds r0, r5, r1
	strh r7, [r0]
	b _0813B620
	.align 2, 0
_0813B538: .4byte 0x0000046B
_0813B53C: .4byte 0xFFFFFEDF
_0813B540: .4byte 0x00000666
_0813B544: .4byte 0x00000469
_0813B548: .4byte FUN_0813b22c
_0813B54C: .4byte 0x00000553
_0813B550: .4byte 0x00000482
_0813B554:
	ldr r4, _0813B5A8 @ =0x0000024E
	adds r1, r5, r4
	ldrh r4, [r1]
	cmp r4, #0
	beq _0813B5BC
	movs r0, #0x80
	lsls r0, r0, #1
	orrs r0, r2
	strh r0, [r3]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r0, _0813B5AC @ =0x03002BE0
	ldr r1, [r0]
	adds r1, #0x2c
	adds r0, r5, #0
	bl FUN_0813c9c4
	movs r1, #2
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	strb r6, [r0]
	ldr r6, _0813B5B0 @ =0x00000469
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0813B5B4 @ =0x0000046A
	adds r0, r5, r1
	strb r7, [r0]
	ldr r2, _0813B5B8 @ =0x00000484
	adds r0, r5, r2
	mov r4, r8
	str r4, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r7, [r0]
	adds r0, r5, #0
	bl FUN_0813c938
	b _0813B620
	.align 2, 0
_0813B5A8: .4byte 0x0000024E
_0813B5AC: .4byte 0x03002BE0
_0813B5B0: .4byte 0x00000469
_0813B5B4: .4byte 0x0000046A
_0813B5B8: .4byte 0x00000484
_0813B5BC:
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r3, r5, r0
	ldrb r0, [r3]
	strb r0, [r5, #5]
	ldr r1, _0813B62C @ =FUN_0813b100
	mov r8, r1
	movs r1, #0xa
	ldr r2, _0813B630 @ =0x0000046D
	adds r0, r5, r2
	strb r7, [r0]
	subs r2, #2
	adds r0, r5, r2
	strb r6, [r0]
	adds r2, #0xe8
	adds r0, r5, r2
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	mov r2, r8
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r6, [r0]
	ldr r6, _0813B634 @ =0x00000469
	adds r0, r5, r6
	strb r7, [r0]
	ldr r1, _0813B638 @ =0x0000046A
	adds r0, r5, r1
	strb r7, [r0]
	adds r2, #0x1c
	adds r0, r5, r2
	str r4, [r0]
	ldr r4, _0813B63C @ =0x0000046C
	adds r0, r5, r4
	strb r7, [r0]
	ldrb r0, [r3]
	strb r0, [r5, #5]
	adds r6, #0x19
	adds r0, r5, r6
	strh r7, [r0]
	adds r0, r5, #0
	bl FUN_0813c938
_0813B620:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813B62C: .4byte FUN_0813b100
_0813B630: .4byte 0x0000046D
_0813B634: .4byte 0x00000469
_0813B638: .4byte 0x0000046A
_0813B63C: .4byte 0x0000046C

	thumb_func_start FUN_0813b640
FUN_0813b640: @ 0x0813B640
	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	adds r6, r0, #0
	ldr r0, _0813B658 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813B65C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813B65E
	.align 2, 0
_0813B658: .4byte 0x0000046D
_0813B65C:
	movs r0, #0
_0813B65E:
	cmp r0, #0
	beq _0813B6CE
	adds r0, r6, #0
	movs r1, #0xa
	bl FUN_080efe38
	adds r0, r6, #0
	bl FUN_080e8360
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r1, _0813B774 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _0813B778 @ =0x0000021E
	adds r0, r6, r2
	movs r1, #0
	strh r1, [r0]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r1, [r0]
	ldr r4, _0813B77C @ =0x00000202
	adds r0, r6, r4
	strh r1, [r0]
	movs r7, #0xbe
	lsls r7, r7, #1
	adds r2, r6, r7
	ldr r1, _0813B780 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x94
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1, #6]
	movs r2, #4
	orrs r0, r2
	strh r0, [r1, #6]
	adds r1, r6, #0
	adds r1, #0xd8
	ldrh r0, [r1, #6]
	orrs r0, r2
	strh r0, [r1, #6]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _0813B784 @ =0x00000474
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r0, r6, #0
	bl FUN_0813cd94
_0813B6CE:
	ldr r2, _0813B788 @ =0x0000046E
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0813B6DA
	b _0813B808
_0813B6DA:
	ldr r3, _0813B78C @ =0x0000046B
	adds r0, r6, r3
	movs r4, #1
	strb r4, [r0]
	adds r0, r6, #0
	bl FUN_080e6658
	movs r7, #0xcd
	lsls r7, r7, #1
	adds r2, r6, r7
	ldrh r0, [r2]
	cmp r0, #0
	beq _0813B74A
	movs r1, #8
	ldrsh r0, [r6, r1]
	str r0, [sp]
	movs r3, #0xa
	ldrsh r0, [r6, r3]
	str r0, [sp, #4]
	movs r7, #0xc
	ldrsh r0, [r6, r7]
	str r0, [sp, #8]
	movs r1, #0xce
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r3, #0xd0
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [sp, #0x10]
	movs r7, #0xd2
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r6]
	str r0, [sp, #0x1c]
	ldr r1, _0813B790 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r3, sp
	str r3, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_0813B74A:
	ldr r7, _0813B794 @ =0x000001DF
	adds r0, r6, r7
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _0813B79C
	ldr r0, _0813B798 @ =0x030046A0
	ldr r2, [r0]
	movs r7, #0xe2
	lsls r7, r7, #2
	adds r2, r2, r7
	adds r1, r4, #0
	lsls r1, r3
	b _0813B7AE
	.align 2, 0
_0813B774: .4byte 0xFFFEBE3F
_0813B778: .4byte 0x0000021E
_0813B77C: .4byte 0x00000202
_0813B780: .4byte 0xFFEFFFFF
_0813B784: .4byte 0x00000474
_0813B788: .4byte 0x0000046E
_0813B78C: .4byte 0x0000046B
_0813B790: .4byte 0xFFFF0000
_0813B794: .4byte 0x000001DF
_0813B798: .4byte 0x030046A0
_0813B79C:
	ldr r0, _0813B810 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_0813B7AE:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r5, #0
	movs r2, #0
	strh r2, [r0]
	ldr r4, _0813B814 @ =FUN_080e48d0
	movs r3, #0x10
	ldr r7, _0813B818 @ =0x0000046D
	adds r0, r6, r7
	movs r1, #1
	strb r1, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r5, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r6, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r2, [r0]
	movs r3, #2
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r4, _0813B81C @ =0x00000469
	adds r0, r6, r4
	strb r5, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _0813B820 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r1, [r0]
_0813B808:
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813B810: .4byte 0x030046A0
_0813B814: .4byte FUN_080e48d0
_0813B818: .4byte 0x0000046D
_0813B81C: .4byte 0x00000469
_0813B820: .4byte 0x00000484

	thumb_func_start FUN_0813b824
FUN_0813b824: @ 0x0813B824
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0813B844 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813B848
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813B84A
	.align 2, 0
_0813B844: .4byte 0x0000046C
_0813B848:
	movs r0, #0
_0813B84A:
	cmp r0, #0
	beq _0813B890
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	movs r4, #1
	ldr r2, _0813B8D4 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r4, [r0]
	ldr r3, _0813B8D8 @ =0x0000046B
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r4, [r0]
	adds r3, #0x25
	adds r0, r5, r3
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r1, r7, r3
	str r2, [sp]
	mov r0, sp
	ldr r2, _0813B8DC @ =0x05000002
	bl CpuSet
	ldr r1, _0813B8E0 @ =0x00000667
	adds r0, r7, r1
	strb r4, [r0]
_0813B890:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0813B8A6
	b _0813BAF8
_0813B8A6:
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r1, _0813B8E4 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813B8EC
	ldr r3, _0813B8E8 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0813B8FC
	.align 2, 0
_0813B8D4: .4byte 0x0000046D
_0813B8D8: .4byte 0x0000046B
_0813B8DC: .4byte 0x05000002
_0813B8E0: .4byte 0x00000667
_0813B8E4: .4byte 0x0000A02F
_0813B8E8: .4byte 0x00000482
_0813B8EC:
	ldr r1, _0813B920 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0813B8FC
	movs r0, #1
	strh r0, [r2]
_0813B8FC:
	ldr r3, _0813B924 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0813B928
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _0813B940
	.align 2, 0
_0813B920: .4byte 0x00000482
_0813B924: .4byte 0x0000025D
_0813B928:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_0813B940:
	adds r0, r5, #0
	bl FUN_0813c38c
	ldr r1, _0813B980 @ =0x000004A4
	adds r0, r5, r1
	ldr r1, [r0]
	ldrh r2, [r1, #0xc]
	ldrh r0, [r5, #8]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	ldrh r0, [r1, #0x10]
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0
	bge _0813B968
	rsbs r2, r2, #0
_0813B968:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _0813B984
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _0813B976
	rsbs r2, r2, #0
_0813B976:
	cmp r2, #0x20
	bgt _0813B984
	movs r0, #1
	b _0813B9EE
	.align 2, 0
_0813B980: .4byte 0x000004A4
_0813B984:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _0813B990
	cmp r1, #0
	beq _0813B9EC
_0813B990:
	asrs r1, r1, #0x10
	bl FUN_0823785c
	strb r0, [r5, #5]
	ldr r2, _0813B9B4 @ =0x085B0A08
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0813B9B8
	asrs r1, r0, #0xc
	b _0813B9BE
	.align 2, 0
_0813B9B4: .4byte 0x085B0A08
_0813B9B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0813B9BE:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _0813B9DC @ =0x085B0A08
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	cmp r0, #0
	blt _0813B9E0
	asrs r1, r0, #0xc
	b _0813B9E6
	.align 2, 0
_0813B9DC: .4byte 0x085B0A08
_0813B9E0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0813B9E6:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_0813B9EC:
	movs r0, #0
_0813B9EE:
	cmp r0, #0
	bne _0813B9F4
	b _0813BAEE
_0813B9F4:
	adds r0, r5, #0
	bl FUN_0813c584
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0813BAEE
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r3, r7, r0
	ldrb r4, [r5, #5]
	ldr r2, _0813BA24 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0813BA28
	asrs r1, r0, #0xc
	b _0813BA2E
	.align 2, 0
_0813BA24: .4byte 0x085B0A08
_0813BA28:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0813BA2E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0813BA46
	asrs r0, r0, #0xc
	b _0813BA4C
_0813BA46:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0813BA4C:
	strh r0, [r3, #4]
	adds r0, r5, #0
	bl FUN_0813c3ec
	add r6, sp, #4
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r1, [r0, #8]
	ldrh r0, [r1]
	strh r0, [r6]
	ldrh r1, [r1, #2]
	strh r1, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r7, r6, #0
	cmp r2, #0
	blt _0813BA86
	cmp r1, #0
	blt _0813BA86
	ldr r0, _0813BA8C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0813BA86
	ldr r0, _0813BA90 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0813BA94
_0813BA86:
	movs r4, #0
	b _0813BAA2
	.align 2, 0
_0813BA8C: .4byte 0x030046A8
_0813BA90: .4byte 0x030046AC
_0813BA94:
	ldr r0, _0813BAB4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0813BAA2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0813BAB8
	adds r0, #4
	b _0813BAC4
	.align 2, 0
_0813BAB4: .4byte 0x030046A4
_0813BAB8:
	ldr r0, _0813BAD8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0813BAC4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0813BADC
	cmp r2, #2
	beq _0813BAE0
	b _0813BAE4
	.align 2, 0
_0813BAD8: .4byte 0x030046A4
_0813BADC:
	ldrb r0, [r6, #4]
	b _0813BAE2
_0813BAE0:
	ldrb r0, [r6]
_0813BAE2:
	subs r1, r1, r0
_0813BAE4:
	strh r1, [r6, #2]
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_0813c9c4
_0813BAEE:
	ldr r3, _0813BB00 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0813BAF8:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813BB00: .4byte 0x00000484

	thumb_func_start FUN_0813bb04
FUN_0813bb04: @ 0x0813BB04
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0813BB28 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813BB2C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813BB2E
	.align 2, 0
_0813BB28: .4byte 0x0000046C
_0813BB2C:
	movs r0, #0
_0813BB2E:
	cmp r0, #0
	beq _0813BB62
	movs r3, #0xb2
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r4, [r0]
	movs r3, #2
	ldr r0, _0813BBEC @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0813BBF0 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_0813BB62:
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r6, r7, r2
	ldrh r0, [r6]
	ldrh r3, [r5, #0x10]
	adds r0, r0, r3
	movs r1, #0
	mov r8, r1
	strh r0, [r5, #0x10]
	adds r2, #4
	adds r4, r7, r2
	ldrh r0, [r4]
	ldrh r3, [r5, #0x14]
	adds r0, r0, r3
	strh r0, [r5, #0x14]
	ldr r0, _0813BBF4 @ =0x00000484
	adds r7, r5, r0
	ldr r0, [r7]
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0813BBA0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	strh r0, [r6]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	strh r0, [r4]
_0813BBA0:
	ldr r1, _0813BBF0 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0813BC40
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _0813BC04
	movs r1, #2
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	mov r3, r8
	strb r3, [r0]
	ldr r3, _0813BBF8 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _0813BBFC @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	adds r3, #0x1b
	adds r1, r5, r3
	movs r0, #0
	str r0, [r1]
	ldr r1, _0813BC00 @ =0x0000046C
	adds r0, r5, r1
	strb r2, [r0]
	b _0813BC46
	.align 2, 0
_0813BBEC: .4byte 0x0000046D
_0813BBF0: .4byte 0x0000046B
_0813BBF4: .4byte 0x00000484
_0813BBF8: .4byte 0x00000469
_0813BBFC: .4byte 0x0000046A
_0813BC00: .4byte 0x0000046C
_0813BC04:
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	mov r3, r8
	strb r3, [r0]
	ldr r3, _0813BC30 @ =0x00000469
	adds r0, r5, r3
	mov r3, r8
	strb r3, [r0]
	ldr r3, _0813BC34 @ =0x0000046A
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _0813BC38 @ =0x00000484
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _0813BC3C @ =0x0000046C
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _0813BC46
	.align 2, 0
_0813BC30: .4byte 0x00000469
_0813BC34: .4byte 0x0000046A
_0813BC38: .4byte 0x00000484
_0813BC3C: .4byte 0x0000046C
_0813BC40:
	ldr r0, [r7]
	adds r0, #1
	str r0, [r7]
_0813BC46:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0813bc50
FUN_0813bc50: @ 0x0813BC50
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _0813BC78 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813BC7C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813BC7E
	.align 2, 0
_0813BC78: .4byte 0x0000046C
_0813BC7C:
	movs r0, #0
_0813BC7E:
	cmp r0, #0
	beq _0813BCB4
	ldr r1, _0813BD28 @ =0x000005A4
	adds r0, r6, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r0, _0813BD2C @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0813BD30 @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r6, r1
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r2, [r0]
	ldr r0, _0813BD34 @ =0x00000666
	add r0, sb
	strb r1, [r0]
_0813BCB4:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0813BCCA
	b _0813BE1C
_0813BCCA:
	movs r0, #0xdf
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0xef
	bgt _0813BCDA
	b _0813BE12
_0813BCDA:
	ldr r2, _0813BD38 @ =0x00000484
	adds r0, r6, r2
	ldr r0, [r0]
	cmp r0, #0x3c
	bgt _0813BCE6
	b _0813BE12
_0813BCE6:
	movs r0, #0xf0
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_0813c3ec
	add r7, sp, #4
	adds r0, r6, #0
	adds r0, #0x9c
	ldr r1, [r0, #8]
	ldrh r0, [r1]
	strh r0, [r7]
	ldrh r1, [r1, #2]
	strh r1, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r5, r7, #0
	cmp r2, #0
	blt _0813BD22
	cmp r1, #0
	blt _0813BD22
	ldr r0, _0813BD3C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0813BD22
	ldr r0, _0813BD40 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0813BD44
_0813BD22:
	movs r4, #0
	b _0813BD52
	.align 2, 0
_0813BD28: .4byte 0x000005A4
_0813BD2C: .4byte 0x0000046D
_0813BD30: .4byte 0x0000046B
_0813BD34: .4byte 0x00000666
_0813BD38: .4byte 0x00000484
_0813BD3C: .4byte 0x030046A8
_0813BD40: .4byte 0x030046AC
_0813BD44:
	ldr r0, _0813BD64 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0813BD52:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0813BD68
	adds r0, #4
	b _0813BD74
	.align 2, 0
_0813BD64: .4byte 0x030046A4
_0813BD68:
	ldr r0, _0813BD88 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0813BD74:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0813BD8C
	cmp r2, #2
	beq _0813BD90
	b _0813BD94
	.align 2, 0
_0813BD88: .4byte 0x030046A4
_0813BD8C:
	ldrb r0, [r7, #4]
	b _0813BD92
_0813BD90:
	ldrb r0, [r7]
_0813BD92:
	subs r1, r1, r0
_0813BD94:
	movs r4, #0
	movs r0, #0
	mov r8, r0
	strh r1, [r7, #2]
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_0813c54c
	adds r0, r6, #0
	bl FUN_0813c584
	movs r1, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r4, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r4, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	adds r2, #0x1a
	adds r0, r6, r2
	mov r2, r8
	str r2, [r0]
	ldr r2, _0813BE2C @ =0x0000046C
	adds r0, r6, r2
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #8
	add r2, sp, #4
	ldrh r0, [r2]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r5, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r2, #4
	ldrsh r1, [r5, r2]
	bl FUN_0823785c
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r1, #0xd5
	lsls r1, r1, #3
	add r1, sb
	mov r0, r8
	str r0, [sp]
	mov r0, sp
	ldr r2, _0813BE30 @ =0x05000002
	bl CpuSet
_0813BE12:
	ldr r2, _0813BE34 @ =0x00000484
	adds r1, r6, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0813BE1C:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813BE2C: .4byte 0x0000046C
_0813BE30: .4byte 0x05000002
_0813BE34: .4byte 0x00000484

	thumb_func_start FUN_0813be38
FUN_0813be38: @ 0x0813BE38
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r2, _0813BE58 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813BE5C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813BE5E
	.align 2, 0
_0813BE58: .4byte 0x0000046C
_0813BE5C:
	movs r0, #0
_0813BE5E:
	cmp r0, #0
	beq _0813BEC8
	ldr r3, _0813BEE8 @ =FUN_080e48d0
	movs r2, #0x10
	ldr r7, _0813BEEC @ =0x0000046D
	adds r0, r6, r7
	movs r1, #0
	movs r4, #1
	strb r4, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r1, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r6, r7
	strh r1, [r0]
	adds r0, r6, #0
	movs r1, #0x11
	bl FUN_080efe38
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r1, #0x94
	lsls r1, r1, #1
	adds r3, r6, r1
	movs r1, #5
	rsbs r1, r1, #0
	ldrh r2, [r3, #6]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3, #6]
	adds r2, r6, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	ands r1, r0
	strh r1, [r2, #6]
	ldr r7, _0813BEF0 @ =0x00000474
	adds r2, r6, r7
	ldr r0, _0813BEF4 @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0813BEC8:
	ldr r1, _0813BEF8 @ =0x00000484
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0x27
	bgt _0813BEFC
	movs r1, #8
	bl Mod
	cmp r0, #0
	bne _0813BF14
	movs r0, #0x20
	movs r7, #0xc1
	lsls r7, r7, #1
	adds r2, r6, r7
	b _0813BF0E
	.align 2, 0
_0813BEE8: .4byte FUN_080e48d0
_0813BEEC: .4byte 0x0000046D
_0813BEF0: .4byte 0x00000474
_0813BEF4: .4byte 0xFFFFF7FF
_0813BEF8: .4byte 0x00000484
_0813BEFC:
	movs r1, #3
	bl Mod
	cmp r0, #0
	bne _0813BF14
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r6, r1
_0813BF0E:
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0813BF14:
	ldr r2, _0813BF6C @ =0x00000484
	adds r7, r6, r2
	ldr r0, [r7]
	cmp r0, #0x3c
	ble _0813BF60
	movs r0, #0xdf
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, _0813BF70 @ =0x00000472
	adds r1, r6, r0
	ldrh r0, [r6, #0xa]
	ldrh r1, [r1]
	subs r0, r0, r1
	ldrh r1, [r2]
	adds r0, r0, r1
	movs r4, #0
	movs r5, #0
	strh r0, [r2]
	adds r0, r6, #0
	bl FUN_0813c938
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r4, [r0]
	ldr r1, _0813BF74 @ =0x00000469
	adds r0, r6, r1
	strb r4, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r4, [r0]
	adds r1, #0x1b
	adds r0, r6, r1
	str r5, [r0]
	adds r2, #2
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
_0813BF60:
	ldr r0, [r7]
	adds r0, #1
	str r0, [r7]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813BF6C: .4byte 0x00000484
_0813BF70: .4byte 0x00000472
_0813BF74: .4byte 0x00000469

	thumb_func_start FUN_0813bf78
FUN_0813bf78: @ 0x0813BF78
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0813BF98 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813BF9C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813BF9E
	.align 2, 0
_0813BF98: .4byte 0x0000046C
_0813BF9C:
	movs r0, #0
_0813BF9E:
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r3, r5, r1
	cmp r0, #0
	beq _0813C08E
	ldr r3, _0813C014 @ =FUN_0813ad34
	movs r2, #0x23
	ldr r0, _0813C018 @ =0x0000046D
	adds r1, r5, r0
	movs r4, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0813C01C @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r4, [r0]
	adds r0, r5, #0
	bl FUN_0813cd94
	ldr r2, _0813C020 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0813C024 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0813C028 @ =0x0203B400
	adds r0, r0, r1
	ldrb r6, [r0]
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r1, r7, r2
	str r4, [sp]
	mov r0, sp
	ldr r2, _0813C02C @ =0x05000002
	bl CpuSet
	ldr r1, _0813C030 @ =0x085B0A08
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _0813C034
	asrs r1, r0, #0xc
	b _0813C03A
	.align 2, 0
_0813C014: .4byte FUN_0813ad34
_0813C018: .4byte 0x0000046D
_0813C01C: .4byte 0x0000046B
_0813C020: .4byte 0x030046B8
_0813C024: .4byte 0x000003FF
_0813C028: .4byte 0x0203B400
_0813C02C: .4byte 0x05000002
_0813C030: .4byte 0x085B0A08
_0813C034:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0813C03A:
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0xa
	strh r0, [r1]
	ldr r2, _0813C06C @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _0813C070
	asrs r1, r0, #0xc
	b _0813C076
	.align 2, 0
_0813C06C: .4byte 0x085B0A08
_0813C070:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0813C076:
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r2, _0813C120 @ =0xFFEFFFFF
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r3, r1, #0
_0813C08E:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r6, #0x10
	ldr r1, [r3]
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	beq _0813C10C
	movs r0, #0x80
	lsls r0, r0, #0xd
	orrs r1, r0
	str r1, [r3]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r4, #0
	str r4, [sp]
	mov r0, sp
	ldr r2, _0813C124 @ =0x05000002
	bl CpuSet
	movs r1, #4
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	ldr r2, _0813C128 @ =0x00000469
	adds r0, r5, r2
	strb r4, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _0813C12C @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #3
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r2, _0813C130 @ =FUN_080e48d0
	adds r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _0813C134 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r3, #0xe6
	adds r0, r5, r3
	strb r6, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
_0813C10C:
	ldr r3, _0813C12C @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813C120: .4byte 0xFFEFFFFF
_0813C124: .4byte 0x05000002
_0813C128: .4byte 0x00000469
_0813C12C: .4byte 0x00000484
_0813C130: .4byte FUN_080e48d0
_0813C134: .4byte 0x0000046B

	thumb_func_start FUN_0813c138
FUN_0813c138: @ 0x0813C138
	ldr r1, _0813C144 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _0813C148 @ =0x085AD770
	str r1, [r0]
	bx lr
	.align 2, 0
_0813C144: .4byte 0x00000634
_0813C148: .4byte 0x085AD770

	thumb_func_start FUN_0813c14c
FUN_0813c14c: @ 0x0813C14C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0813C1C8
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #2
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813C176
	movs r0, #1
	b _0813C178
_0813C176:
	movs r0, #0
_0813C178:
	cmp r0, #0
	beq _0813C1C8
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r2, #0
	strb r2, [r0]
	ldr r6, _0813C1D0 @ =0x00000469
	adds r0, r5, r6
	strb r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	ldr r1, _0813C1D4 @ =0x0000046C
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	ldr r4, _0813C1D8 @ =FUN_080e48d0
	movs r3, #0x10
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0813C1DC @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
_0813C1C8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0813C1D0: .4byte 0x00000469
_0813C1D4: .4byte 0x0000046C
_0813C1D8: .4byte FUN_080e48d0
_0813C1DC: .4byte 0x0000046B

	thumb_func_start FUN_0813c1e0
FUN_0813c1e0: @ 0x0813C1E0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0813C1FA
	b _0813C382
_0813C1FA:
	movs r1, #1
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813C20E
	movs r0, #1
	b _0813C210
_0813C20E:
	movs r0, #0
_0813C210:
	cmp r0, #0
	beq _0813C216
	b _0813C382
_0813C216:
	ldr r1, _0813C230 @ =0x00000553
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #0x22
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0813C238
	ldr r2, _0813C234 @ =0x00000472
	adds r1, r4, r2
	movs r2, #0xdf
	lsls r2, r2, #1
	b _0813C250
	.align 2, 0
_0813C230: .4byte 0x00000553
_0813C234: .4byte 0x00000472
_0813C238:
	movs r1, #0x80
	lsls r1, r1, #0xd
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0813C260
	ldr r0, _0813C25C @ =0x00000472
	adds r1, r4, r0
	adds r2, #0x42
_0813C250:
	adds r0, r4, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0xa]
	b _0813C382
	.align 2, 0
_0813C25C: .4byte 0x00000472
_0813C260:
	ldr r0, _0813C28C @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _0813C274
	ldr r0, _0813C290 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _0813C274
	movs r1, #1
_0813C274:
	cmp r1, #0
	bne _0813C288
	ldr r0, _0813C294 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #3
	bne _0813C298
_0813C288:
	movs r3, #0x3c
	b _0813C29C
	.align 2, 0
_0813C28C: .4byte 0x03002B8C
_0813C290: .4byte 0x03002B60
_0813C294: .4byte 0x03002BE0
_0813C298:
	movs r3, #0x82
	lsls r3, r3, #1
_0813C29C:
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r6, _0813C2C4 @ =0x085B0A08
	cmp r0, r3
	bge _0813C2F8
	ldr r2, _0813C2C8 @ =0x00000666
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _0813C2CC
	asrs r1, r0, #9
	b _0813C2D2
	.align 2, 0
_0813C2C4: .4byte 0x085B0A08
_0813C2C8: .4byte 0x00000666
_0813C2CC:
	rsbs r0, r0, #0
	asrs r0, r0, #9
	rsbs r1, r0, #0
_0813C2D2:
	movs r0, #0xdf
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	ldr r0, _0813C324 @ =0x00000666
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0x3f
	bhi _0813C2EC
	adds r0, #1
	strb r0, [r1]
_0813C2EC:
	ldr r0, _0813C328 @ =0x00000472
	adds r1, r4, r0
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0xa]
_0813C2F8:
	ldr r1, _0813C328 @ =0x00000472
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r0, r0, r3
	movs r2, #0xa
	ldrsh r1, [r4, r2]
	subs r0, r0, r1
	adds r1, r0, #0
	cmp r0, #0
	bge _0813C30E
	rsbs r1, r0, #0
_0813C30E:
	cmp r1, #0x10
	ble _0813C338
	cmp r0, #0
	bge _0813C32C
	movs r0, #0xdf
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #2
	b _0813C336
	.align 2, 0
_0813C324: .4byte 0x00000666
_0813C328: .4byte 0x00000472
_0813C32C:
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #2
_0813C336:
	strh r0, [r1]
_0813C338:
	ldr r0, _0813C364 @ =0x00000472
	adds r1, r4, r0
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0xa]
	ldr r1, [r4, #0x44]
	ldr r2, _0813C368 @ =0x00000666
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0813C36C
	asrs r2, r0, #0xc
	b _0813C372
	.align 2, 0
_0813C364: .4byte 0x00000472
_0813C368: .4byte 0x00000666
_0813C36C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0813C372:
	ldrh r0, [r1, #0x1e]
	adds r0, r0, r2
	strh r0, [r1, #0x1e]
	ldr r0, _0813C388 @ =0x00000666
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
_0813C382:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0813C388: .4byte 0x00000666

	thumb_func_start FUN_0813c38c
FUN_0813c38c: @ 0x0813C38C
	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r3, [r0]
	movs r0, #0xcd
	lsls r0, r0, #3
	adds r2, r3, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r4, #0xa0
	lsls r4, r4, #1
	cmp r0, r4
	ble _0813C3B4
	ldr r0, _0813C3B0 @ =0x00000667
	adds r1, r3, r0
	movs r0, #0xff
	b _0813C3C0
	.align 2, 0
_0813C3B0: .4byte 0x00000667
_0813C3B4:
	ldr r4, _0813C3E4 @ =0xFFFFFEC0
	cmp r0, r4
	bge _0813C3C4
	ldr r0, _0813C3E8 @ =0x00000667
	adds r1, r3, r0
	movs r0, #1
_0813C3C0:
	strb r0, [r1]
	strh r4, [r2]
_0813C3C4:
	movs r1, #0xcd
	lsls r1, r1, #3
	adds r2, r3, r1
	subs r1, #1
	adds r0, r3, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0813C3E4: .4byte 0xFFFFFEC0
_0813C3E8: .4byte 0x00000667

	thumb_func_start FUN_0813c3ec
FUN_0813c3ec: @ 0x0813C3EC
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x9c
	ldr r2, _0813C440 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0813C444 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0813C448 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldrb r0, [r4, #2]
	cmp r1, r0
	bne _0813C426
	adds r0, r1, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_0813C426:
	movs r0, #0
	strb r1, [r4, #2]
	strb r0, [r4, #3]
	ldr r0, [r4, #4]
	bl FUN_08234f6c
	ldrb r1, [r4, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0813C440: .4byte 0x030046B8
_0813C444: .4byte 0x000003FF
_0813C448: .4byte 0x0203B400

	thumb_func_start FUN_0813c44c
FUN_0813c44c: @ 0x0813C44C
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x2c
	mov sb, r0
	ldr r5, _0813C508 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r5
	movs r6, #0x10
	orrs r0, r6
	ldr r4, _0813C50C @ =0x0000FFFF
	ands r0, r4
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r5
	orrs r0, r6
	str r0, [sp, #0x10]
	movs r0, #0
	mov r8, r0
	str r0, [sp, #0x14]
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r5
	str r0, [r2, #4]
	ldr r3, _0813C510 @ =FUN_0813a40c
	mov r0, sb
	str r0, [sp]
	add r1, sp, #0xc
	bl FUN_080e3834
	ldr r0, [sp, #0x1c]
	ands r0, r5
	orrs r0, r6
	ands r0, r4
	movs r1, #0xa8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r4, sp, #0x1c
	ldr r0, [r4, #4]
	ands r0, r5
	orrs r0, r6
	str r0, [r4, #4]
	mov r0, r8
	str r0, [sp, #0x24]
	add r3, sp, #0x24
	ldr r0, [r3, #4]
	ands r0, r5
	str r0, [r3, #4]
	ldr r2, _0813C514 @ =0x00002003
	movs r5, #0x94
	lsls r5, r5, #1
	add r5, sb
	mov r0, sb
	ldrh r1, [r0]
	str r6, [sp]
	str r4, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_082364f8
	mov r1, sb
	adds r1, #8
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0813C518 @ =FUN_0813a26c
	adds r0, r5, #0
	mov r2, sb
	bl FUN_0823651c
	add sp, #0x2c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0813C508: .4byte 0xFFFF0000
_0813C50C: .4byte 0x0000FFFF
_0813C510: .4byte FUN_0813a40c
_0813C514: .4byte 0x00002003
_0813C518: .4byte FUN_0813a26c

	thumb_func_start FUN_0813c51c
FUN_0813c51c: @ 0x0813C51C
	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0813C544 @ =0x00000664
	adds r0, r0, r1
	ldrh r0, [r0]
	lsrs r0, r0, #7
	adds r1, r0, #0
	cmp r1, #7
	ble _0813C536
	movs r1, #7
_0813C536:
	ldr r0, _0813C548 @ =0x085AD784
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_0813C544: .4byte 0x00000664
_0813C548: .4byte 0x085AD784

	thumb_func_start FUN_0813c54c
FUN_0813c54c: @ 0x0813C54C
	push {r4, r5, lr}
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r2, r0, r3
	ldr r4, [r2]
	movs r2, #0xd3
	lsls r2, r2, #3
	adds r5, r4, r2
	ldr r2, [r0, #8]
	ldr r3, [r0, #0xc]
	str r2, [r5]
	str r3, [r5, #4]
	movs r3, #0xd4
	lsls r3, r3, #3
	adds r2, r4, r3
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, _0813C580 @ =0x00000664
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0813C580: .4byte 0x00000664

	thumb_func_start FUN_0813c584
FUN_0813c584: @ 0x0813C584
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r1, [r1]
	mov r8, r1
	movs r1, #0xd3
	lsls r1, r1, #3
	add r1, r8
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [sp, #4]
	str r2, [sp, #8]
	ldr r3, _0813C620 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r3
	str r1, [sp, #4]
	movs r1, #0xd4
	lsls r1, r1, #3
	add r1, r8
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	ldr r1, [sp, #0xc]
	ands r1, r3
	str r1, [sp, #0xc]
	ldr r1, _0813C624 @ =0x00000664
	add r1, r8
	movs r3, #0xcd
	lsls r3, r3, #3
	add r3, r8
	ldr r5, _0813C628 @ =0x000004A4
	adds r0, r0, r5
	ldr r0, [r0]
	adds r0, #0xc
	mov sb, r0
	add r7, sp, #4
	add r2, sp, #0xc
	ldrh r6, [r1]
	movs r1, #0
	ldrsh r0, [r3, r1]
	str r0, [sp, #0x24]
	add r4, sp, #0x14
	ldrh r0, [r2]
	ldrh r1, [r7]
	subs r0, r0, r1
	movs r3, #0
	strh r0, [r4]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	add r5, sp, #0x1c
	str r3, [sp]
	mov r0, sp
	adds r1, r5, #0
	ldr r2, _0813C62C @ =0x05000002
	bl CpuSet
	adds r0, r6, #0
	muls r0, r6, r0
	mov sl, r4
	mov ip, r5
	cmp r0, #0
	blt _0813C630
	asrs r0, r0, #0xa
	b _0813C636
	.align 2, 0
_0813C620: .4byte 0x0000FFFF
_0813C624: .4byte 0x00000664
_0813C628: .4byte 0x000004A4
_0813C62C: .4byte 0x05000002
_0813C630:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_0813C636:
	adds r1, r0, #0
	adds r0, r1, #0
	muls r0, r6, r0
	cmp r0, #0
	blt _0813C644
	asrs r3, r0, #0xa
	b _0813C64A
_0813C644:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r3, r0, #0
_0813C64A:
	lsls r2, r3, #1
	lsls r0, r1, #1
	adds r4, r0, r1
	subs r0, r3, r0
	adds r0, r0, r6
	ldr r5, [sp, #0x24]
	adds r3, r0, #0
	muls r3, r5, r3
	str r3, [sp, #0x30]
	subs r0, r2, r4
	adds r0, #1
	mov r6, ip
	movs r3, #0
	ldrsh r1, [r6, r3]
	adds r5, r0, #0
	muls r5, r1, r5
	subs r6, r4, r2
	mov r1, sl
	movs r3, #0
	ldrsh r0, [r1, r3]
	muls r0, r6, r0
	adds r0, r5, r0
	ldr r5, [sp, #0x30]
	adds r0, r0, r5
	cmp r0, #0
	blt _0813C682
	asrs r1, r0, #0xa
	b _0813C688
_0813C682:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0813C688:
	ldrh r0, [r7]
	adds r0, r0, r1
	mov r6, sb
	strh r0, [r6]
	subs r3, r2, r4
	adds r0, r3, #1
	str r0, [sp, #0x28]
	mov r1, ip
	movs r5, #2
	ldrsh r0, [r1, r5]
	ldr r6, [sp, #0x28]
	adds r5, r6, #0
	muls r5, r0, r5
	rsbs r2, r2, #0
	adds r0, r2, r4
	mov r1, sl
	movs r6, #2
	ldrsh r1, [r1, r6]
	adds r6, r0, #0
	adds r0, r1, #0
	muls r0, r6, r0
	adds r0, r5, r0
	ldr r1, [sp, #0x30]
	adds r0, r0, r1
	adds r0, #0
	cmp r0, #0
	blt _0813C6C2
	asrs r1, r0, #0xa
	b _0813C6C8
_0813C6C2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0813C6C8:
	ldrh r0, [r7, #2]
	adds r0, r0, r1
	mov r5, sb
	strh r0, [r5, #2]
	adds r1, r3, #1
	mov r6, ip
	movs r3, #4
	ldrsh r0, [r6, r3]
	adds r5, r1, #0
	muls r5, r0, r5
	adds r1, r2, r4
	mov r6, sl
	movs r2, #4
	ldrsh r0, [r6, r2]
	muls r0, r1, r0
	adds r0, r5, r0
	ldr r3, [sp, #0x30]
	adds r0, r0, r3
	adds r0, #0
	cmp r0, #0
	blt _0813C6F6
	asrs r1, r0, #0xa
	b _0813C6FC
_0813C6F6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0813C6FC:
	ldrh r0, [r7, #4]
	adds r0, r0, r1
	mov r5, sb
	strh r0, [r5, #4]
	ldr r1, _0813C71C @ =0x00000664
	add r1, r8
	ldrh r2, [r1]
	ldr r0, _0813C720 @ =0x000003FF
	cmp r2, r0
	bhi _0813C724
	adds r0, r2, #0
	adds r0, #0x80
	strh r0, [r1]
	movs r0, #0
	b _0813C726
	.align 2, 0
_0813C71C: .4byte 0x00000664
_0813C720: .4byte 0x000003FF
_0813C724:
	movs r0, #1
_0813C726:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0813c738
FUN_0813c738: @ 0x0813C738
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #3
	movs r2, #5
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #1
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #2
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #3
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xb
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #6
	movs r3, #0
	bl FUN_080ef84c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start enemy_curoro_0813c7ac
enemy_curoro_0813c7ac: @ 0x0813C7AC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _0813C87C @ =0x00000664
	adds r0, r4, r2
	movs r1, #0
	movs r5, #0
	strh r5, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	movs r2, #1
	mov r8, r2
	mov r2, r8
	strb r2, [r0]
	movs r2, #0xcd
	lsls r2, r2, #3
	adds r0, r4, r2
	strh r5, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r4, r1
	str r5, [r0]
	adds r2, #0x2d
	adds r1, r4, r2
	str r5, [sp]
	mov r0, sp
	ldr r2, _0813C880 @ =0x05000002
	bl CpuSet
	movs r0, #0xd4
	lsls r0, r0, #3
	adds r1, r4, r0
	str r5, [sp]
	mov r0, sp
	ldr r2, _0813C880 @ =0x05000002
	bl CpuSet
	movs r1, #0xd5
	lsls r1, r1, #3
	adds r4, r4, r1
	str r5, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0813C880 @ =0x05000002
	bl CpuSet
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r0, [r0]
	movs r1, #8
	bl ClearMemory
	ldr r1, _0813C884 @ =0x08252078
	adds r0, r6, #0
	movs r2, #0x87
	lsls r2, r2, #1
	bl FUN_080e6768
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
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
	mov r1, r8
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, r8
	ands r0, r2
	cmp r1, r0
	beq _0813C888
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0813C890
	.align 2, 0
_0813C87C: .4byte 0x00000664
_0813C880: .4byte 0x05000002
_0813C884: .4byte 0x08252078
_0813C888:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0813C890:
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
	beq _0813C8B4
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0813C8BC
_0813C8B4:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0813C8BC:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0813C8F4 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0813C92C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0813C8F8
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0813C8EC
	ldrb r0, [r4, #5]
_0813C8EC:
	subs r0, #1
	strh r0, [r4, #8]
	b _0813C908
	.align 2, 0
_0813C8F4: .4byte 0x0000FFFF
_0813C8F8:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0813C908
	strh r1, [r4, #8]
_0813C908:
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
	bne _0813C92C
	movs r0, #1
	strb r0, [r4, #7]
_0813C92C:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0813c938
FUN_0813c938: @ 0x0813C938
	mov ip, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, ip
	ldr r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #0xd
	movs r2, #0xbe
	lsls r2, r2, #1
	add r2, ip
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r2, #2
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r3, #0x94
	lsls r3, r3, #1
	add r3, ip
	movs r1, #5
	rsbs r1, r1, #0
	ldrh r2, [r3, #6]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3, #6]
	mov r2, ip
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	ands r1, r0
	strh r1, [r2, #6]
	ldr r2, _0813C98C @ =0x00000474
	add r2, ip
	ldr r0, _0813C990 @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	bx lr
	.align 2, 0
_0813C98C: .4byte 0x00000474
_0813C990: .4byte 0xFFFFF7FF

	thumb_func_start FUN_0813c994
FUN_0813c994: @ 0x0813C994
	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	cmp r1, #4
	ble _0813C9B8
	movs r0, #8
	subs r0, r0, r1
	str r0, [r3]
	movs r0, #1
	b _0813C9BC
_0813C9B8:
	str r1, [r3]
	movs r0, #0
_0813C9BC:
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0813c9c4
FUN_0813c9c4: @ 0x0813C9C4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov r8, r0
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0813c54c
	adds r0, r4, #0
	bl FUN_0813c584
	movs r1, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r6, #0
	strb r6, [r0]
	ldr r3, _0813CA5C @ =0x00000469
	adds r0, r4, r3
	strb r6, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r4, r3
	str r6, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	add r2, sp, #4
	adds r3, r4, #0
	adds r3, #8
	ldrh r0, [r5]
	ldrh r1, [r4, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r5, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	movs r1, #0xee
	lsls r1, r1, #1
	adds r4, r4, r1
	strb r0, [r4]
	movs r2, #0xd5
	lsls r2, r2, #3
	add r8, r2
	str r6, [sp]
	mov r0, sp
	mov r1, r8
	ldr r2, _0813CA60 @ =0x05000002
	bl CpuSet
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0813CA5C: .4byte 0x00000469
_0813CA60: .4byte 0x05000002

	thumb_func_start FUN_0813ca64
FUN_0813ca64: @ 0x0813CA64
	push {r4, lr}
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r3, r0, r1
	ldr r1, _0813CA90 @ =0xFFFFFEFF
	ldrh r2, [r3]
	ands r1, r2
	movs r4, #0
	strh r1, [r3]
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r3, r0, r1
	ldr r2, _0813CA94 @ =0xFBFFFFFF
	ldr r1, [r3]
	ands r1, r2
	str r1, [r3]
	ldr r1, _0813CA98 @ =0x0000024E
	adds r0, r0, r1
	strh r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0813CA90: .4byte 0xFFFFFEFF
_0813CA94: .4byte 0xFBFFFFFF
_0813CA98: .4byte 0x0000024E

	thumb_func_start FUN_0813ca9c
FUN_0813ca9c: @ 0x0813CA9C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _0813CAC0
	adds r2, #0xce
	adds r0, r5, r2
	strh r1, [r0]
	b _0813CB7C
_0813CAC0:
	ldr r0, _0813CAD0 @ =0x0000024E
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0813CAD4
	subs r0, #1
	strh r0, [r1]
	b _0813CB7C
	.align 2, 0
_0813CAD0: .4byte 0x0000024E
_0813CAD4:
	adds r0, r5, #0
	bl FUN_0813c3ec
	mov r6, sp
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r2, [r0, #8]
	ldrh r1, [r2]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r6, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0813CB0E
	cmp r1, #0
	blt _0813CB0E
	ldr r0, _0813CB14 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0813CB0E
	ldr r0, _0813CB18 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0813CB1C
_0813CB0E:
	movs r4, #0
	b _0813CB2A
	.align 2, 0
_0813CB14: .4byte 0x030046A8
_0813CB18: .4byte 0x030046AC
_0813CB1C:
	ldr r0, _0813CB3C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0813CB2A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0813CB40
	adds r0, #4
	b _0813CB4C
	.align 2, 0
_0813CB3C: .4byte 0x030046A4
_0813CB40:
	ldr r0, _0813CB60 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0813CB4C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0813CB64
	cmp r2, #2
	beq _0813CB68
	b _0813CB6C
	.align 2, 0
_0813CB60: .4byte 0x030046A4
_0813CB64:
	ldrb r0, [r6, #4]
	b _0813CB6A
_0813CB68:
	ldrb r0, [r6]
_0813CB6A:
	subs r1, r1, r0
_0813CB6C:
	strh r1, [r6, #2]
	adds r0, r5, #0
	mov r1, sp
	bl FUN_0813c9c4
	adds r0, r5, #0
	bl FUN_0813ca64
_0813CB7C:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0813cb84
FUN_0813cb84: @ 0x0813CB84
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0x80
	lsls r1, r1, #6
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813CC6E
	mov r4, sp
	adds r3, r5, #0
	adds r3, #8
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r5, #8]
	ldrh r1, [r2]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3, #4]
	ldrh r2, [r2, #4]
	adds r1, r1, r2
	strh r1, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0813CBE6
	cmp r1, #0
	blt _0813CBE6
	ldr r0, _0813CBEC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0813CBE6
	ldr r0, _0813CBF0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0813CBF4
_0813CBE6:
	movs r4, #0
	b _0813CC02
	.align 2, 0
_0813CBEC: .4byte 0x030046A8
_0813CBF0: .4byte 0x030046AC
_0813CBF4:
	ldr r0, _0813CC14 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0813CC02:
	mov r6, sp
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0813CC18
	adds r0, #4
	b _0813CC24
	.align 2, 0
_0813CC14: .4byte 0x030046A4
_0813CC18:
	ldr r0, _0813CC38 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0813CC24:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0813CC3C
	cmp r2, #2
	beq _0813CC40
	b _0813CC44
	.align 2, 0
_0813CC38: .4byte 0x030046A4
_0813CC3C:
	ldrb r0, [r6, #4]
	b _0813CC42
_0813CC40:
	ldrb r0, [r6]
_0813CC42:
	subs r1, r1, r0
_0813CC44:
	ldr r2, _0813CC78 @ =0x00000472
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, r1
	bge _0813CC6E
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r2, #0
	ldrsh r0, [r1, r2]
	rsbs r0, r0, #0
	movs r2, #0
	strh r0, [r1]
	adds r3, #4
	adds r1, r5, r3
	movs r3, #0
	ldrsh r0, [r1, r3]
	rsbs r0, r0, #0
	strh r0, [r1]
	strh r2, [r5, #0x10]
	strh r2, [r5, #0x14]
_0813CC6E:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0813CC78: .4byte 0x00000472

	thumb_func_start FUN_0813cc7c
FUN_0813cc7c: @ 0x0813CC7C
	push {r4, lr}
	adds r3, r0, #0
	movs r0, #8
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r4, r3, r1
	ldr r1, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0813CCC8
	movs r0, #9
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r4]
	movs r2, #0xa
	ldrsh r1, [r3, r2]
	ldr r0, _0813CCCC @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x2e
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _0813CCAC
	rsbs r1, r1, #0
_0813CCAC:
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r1, r0
	bgt _0813CCC8
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blo _0813CCD0
_0813CCC8:
	movs r0, #0
	b _0813CCEA
	.align 2, 0
_0813CCCC: .4byte 0x03002BE0
_0813CCD0:
	movs r0, #0x80
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r3, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0x14
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r0, #1
_0813CCEA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0813ccf0
FUN_0813ccf0: @ 0x0813CCF0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _0813CD20
	movs r3, #0x93
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrh r1, [r0]
	ldr r6, _0813CD1C @ =0x0000024E
	adds r0, r4, r6
	strh r1, [r0]
	b _0813CD78
	.align 2, 0
_0813CD1C: .4byte 0x0000024E
_0813CD20:
	ldr r3, _0813CD80 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r2, _0813CD84 @ =0x0000046D
	adds r0, r4, r2
	movs r2, #1
	strb r2, [r0]
	ldr r6, _0813CD88 @ =0x0000046B
	adds r0, r4, r6
	strb r5, [r0]
	adds r6, #0xe8
	adds r0, r4, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r1, #0
	strh r5, [r0]
	subs r6, #0xeb
	adds r0, r4, r6
	strb r1, [r0]
	ldr r3, _0813CD8C @ =0x00000469
	adds r0, r4, r3
	strb r2, [r0]
	adds r6, #2
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _0813CD90 @ =0x00000484
	adds r0, r4, r1
	str r5, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r2, [r0]
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r4, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0813CD78:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0813CD80: .4byte FUN_080e48d0
_0813CD84: .4byte 0x0000046D
_0813CD88: .4byte 0x0000046B
_0813CD8C: .4byte 0x00000469
_0813CD90: .4byte 0x00000484

	thumb_func_start FUN_0813cd94
FUN_0813cd94: @ 0x0813CD94
	push {lr}
	adds r2, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, #2
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r0, r0, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813CDB4
	movs r0, #1
	b _0813CDB6
_0813CDB4:
	movs r0, #0
_0813CDB6:
	cmp r0, #0
	beq _0813CDEC
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0813CDD4
	ldr r0, _0813CDF0 @ =0x03002BE0
	ldr r1, [r0]
	ldr r3, _0813CDF4 @ =0x00000402
	adds r1, r1, r3
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_0813CDD4:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r1, [r0]
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r1, r1, r3
	movs r2, #3
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
_0813CDEC:
	pop {r0}
	bx r0
	.align 2, 0
_0813CDF0: .4byte 0x03002BE0
_0813CDF4: .4byte 0x00000402

	thumb_func_start FUN_0813cdf8
FUN_0813cdf8: @ 0x0813CDF8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0813c1e0
	adds r0, r4, #0
	bl FUN_0813ca9c
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0813ce10
FUN_0813ce10: @ 0x0813CE10
	push {lr}
	bl FUN_0813cb84
	movs r0, #1
	pop {r1}
	bx r1

	thumb_func_start FUN_0813ce1c
FUN_0813ce1c: @ 0x0813CE1C
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r2, _0813CE3C @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813CE40
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813CE42
	.align 2, 0
_0813CE3C: .4byte 0x0000046C
_0813CE40:
	movs r0, #0
_0813CE42:
	cmp r0, #0
	beq _0813CE88
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r1, [r0]
	movs r4, #1
	ldr r2, _0813CEC4 @ =0x0000046D
	adds r0, r6, r2
	movs r2, #0
	strb r4, [r0]
	ldr r3, _0813CEC8 @ =0x0000046B
	adds r0, r6, r3
	strb r2, [r0]
	adds r3, #0xe8
	adds r0, r6, r3
	strb r4, [r0]
	adds r3, #0x25
	adds r0, r6, r3
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r1, r5, r3
	str r2, [sp]
	mov r0, sp
	ldr r2, _0813CECC @ =0x05000002
	bl CpuSet
	ldr r1, _0813CED0 @ =0x00000667
	adds r0, r5, r1
	strb r4, [r0]
_0813CE88:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	adds r5, r0, #0
	ldr r1, _0813CED4 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813CEDC
	ldr r3, _0813CED8 @ =0x00000482
	adds r1, r6, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0813CEEC
	.align 2, 0
_0813CEC4: .4byte 0x0000046D
_0813CEC8: .4byte 0x0000046B
_0813CECC: .4byte 0x05000002
_0813CED0: .4byte 0x00000667
_0813CED4: .4byte 0x0000A02F
_0813CED8: .4byte 0x00000482
_0813CEDC:
	ldr r1, _0813CF10 @ =0x00000482
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0813CEEC
	movs r0, #1
	strh r0, [r2]
_0813CEEC:
	ldr r3, _0813CF14 @ =0x0000025D
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0813CF18
	ldr r4, [r6, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _0813CF30
	.align 2, 0
_0813CF10: .4byte 0x00000482
_0813CF14: .4byte 0x0000025D
_0813CF18:
	ldr r4, [r6, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_0813CF30:
	adds r0, r6, #0
	bl FUN_0813c38c
	ldr r1, _0813CF70 @ =0x000004A4
	adds r0, r6, r1
	ldr r1, [r0]
	ldrh r2, [r1, #0xc]
	ldrh r0, [r6, #8]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	ldrh r0, [r1, #0x10]
	ldrh r1, [r6, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0
	bge _0813CF58
	rsbs r2, r2, #0
_0813CF58:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _0813CF74
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _0813CF66
	rsbs r2, r2, #0
_0813CF66:
	cmp r2, #0x20
	bgt _0813CF74
	movs r0, #1
	b _0813CFDE
	.align 2, 0
_0813CF70: .4byte 0x000004A4
_0813CF74:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _0813CF80
	cmp r1, #0
	beq _0813CFDC
_0813CF80:
	asrs r1, r1, #0x10
	bl FUN_0823785c
	strb r0, [r6, #5]
	ldr r2, _0813CFA4 @ =0x085B0A08
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0813CFA8
	asrs r1, r0, #0xc
	b _0813CFAE
	.align 2, 0
_0813CFA4: .4byte 0x085B0A08
_0813CFA8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0813CFAE:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r1
	strh r0, [r6, #0x10]
	ldr r1, _0813CFCC @ =0x085B0A08
	ldrb r0, [r6, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _0813CFD0
	asrs r1, r0, #0xc
	b _0813CFD6
	.align 2, 0
_0813CFCC: .4byte 0x085B0A08
_0813CFD0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0813CFD6:
	ldrh r0, [r6, #0x14]
	adds r0, r0, r1
	strh r0, [r6, #0x14]
_0813CFDC:
	movs r0, #0
_0813CFDE:
	cmp r0, #0
	beq _0813D05C
	adds r0, r6, #0
	bl FUN_0813c584
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0813D05C
	ldr r5, _0813D070 @ =0x03002BE0
	ldr r1, [r5]
	adds r1, #0x2c
	adds r0, r6, #0
	bl FUN_0813c54c
	adds r0, r6, #0
	bl FUN_0813c584
	movs r2, #1
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0813D074 @ =0x00000469
	adds r0, r6, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r6, r3
	strb r2, [r0]
	adds r3, #0x1a
	adds r0, r6, r3
	str r1, [r0]
	ldr r1, _0813D078 @ =0x0000046C
	adds r0, r6, r1
	strb r2, [r0]
	add r2, sp, #4
	adds r4, r6, #0
	adds r4, #8
	ldr r0, [r5]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
_0813D05C:
	ldr r3, _0813D07C @ =0x00000484
	adds r1, r6, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0813D070: .4byte 0x03002BE0
_0813D074: .4byte 0x00000469
_0813D078: .4byte 0x0000046C
_0813D07C: .4byte 0x00000484

	thumb_func_start FUN_0813d080
FUN_0813d080: @ 0x0813D080
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _0813D0A0 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813D0A4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813D0A6
	.align 2, 0
_0813D0A0: .4byte 0x0000046C
_0813D0A4:
	movs r0, #0
_0813D0A6:
	cmp r0, #0
	beq _0813D0EA
	ldr r4, _0813D18C @ =FUN_0813aac8
	movs r3, #0x22
	ldr r0, _0813D190 @ =0x0000046D
	adds r1, r6, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0813D194 @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r6, r1
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r2, [r0]
	movs r0, #0xd3
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r0, _0813D198 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r6, #0
	bl FUN_0813ca64
_0813D0EA:
	ldr r0, _0813D198 @ =0x03002BE0
	mov r5, sp
	movs r1, #0xd3
	lsls r1, r1, #3
	adds r2, r7, r1
	ldr r3, [r0]
	adds r4, r3, #0
	adds r4, #0x2c
	ldrh r1, [r3, #0x2c]
	ldrh r0, [r2]
	subs r1, r1, r0
	movs r7, #0
	movs r0, #0
	mov ip, r0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r1, [r4, #4]
	ldrh r0, [r2, #4]
	subs r1, r1, r0
	strh r1, [r5, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r4, [r6, #0x10]
	adds r0, r0, r4
	strh r0, [r6, #0x10]
	ldrh r0, [r6, #0x14]
	adds r0, r0, r1
	strh r0, [r6, #0x14]
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _0813D194 @ =0x0000046B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0813D1A4
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r7, [r0]
	ldr r4, _0813D19C @ =0x00000469
	adds r0, r6, r4
	strb r7, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r1, [r0]
	adds r4, #0x1b
	adds r0, r6, r4
	mov r1, ip
	str r1, [r0]
	adds r2, #2
	adds r0, r6, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0813D1A0 @ =FUN_080e48d0
	movs r2, #0x10
	subs r4, #0x17
	adds r0, r6, r4
	strb r1, [r0]
	ldr r1, _0813D194 @ =0x0000046B
	adds r0, r6, r1
	strb r7, [r0]
	adds r4, #0xe6
	adds r0, r6, r4
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	mov r4, ip
	strh r4, [r0]
	b _0813D1AE
	.align 2, 0
_0813D18C: .4byte FUN_0813aac8
_0813D190: .4byte 0x0000046D
_0813D194: .4byte 0x0000046B
_0813D198: .4byte 0x03002BE0
_0813D19C: .4byte 0x00000469
_0813D1A0: .4byte FUN_080e48d0
_0813D1A4:
	ldr r0, _0813D1B8 @ =0x00000484
	adds r1, r6, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0813D1AE:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813D1B8: .4byte 0x00000484

	thumb_func_start FUN_0813d1bc
FUN_0813d1bc: @ 0x0813D1BC
	ldr r1, _0813D1C8 @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _0813D1CC @ =0x085AD7A4
	str r1, [r0]
	bx lr
	.align 2, 0
_0813D1C8: .4byte 0x0000063C
_0813D1CC: .4byte 0x085AD7A4

	thumb_func_start FUN_0813d1d0
FUN_0813d1d0: @ 0x0813D1D0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0813D1E8 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813D1EC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813D1EE
	.align 2, 0
_0813D1E8: .4byte 0x0000046C
_0813D1EC:
	movs r0, #0
_0813D1EE:
	cmp r0, #0
	beq _0813D236
	ldr r4, _0813D250 @ =FUN_0813b100
	movs r3, #0xa
	ldr r2, _0813D254 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0813D258 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	subs r1, #0x48
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
_0813D236:
	ldr r1, _0813D258 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0813D260
	ldr r0, _0813D25C @ =0x03002BE0
	ldr r1, [r0]
	adds r1, #0x2c
	adds r0, r5, #0
	bl FUN_0813c9c4
	b _0813D26A
	.align 2, 0
_0813D250: .4byte FUN_0813b100
_0813D254: .4byte 0x0000046D
_0813D258: .4byte 0x0000046B
_0813D25C: .4byte 0x03002BE0
_0813D260:
	ldr r2, _0813D270 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0813D26A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0813D270: .4byte 0x00000484

	thumb_func_start FUN_0813d274
FUN_0813d274: @ 0x0813D274
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _0813D2F8 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813D298
	movs r0, #0
	strb r0, [r1]
_0813D298:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0813D2AE
	b _0813D3E4
_0813D2AE:
	ldr r2, _0813D2FC @ =0x00000484
	adds r1, r6, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _0813D2BA
	b _0813D3E0
_0813D2BA:
	adds r0, r6, #0
	bl FUN_0813c3ec
	add r7, sp, #4
	adds r0, r6, #0
	adds r0, #0x9c
	ldr r1, [r0, #8]
	ldrh r0, [r1]
	strh r0, [r7]
	ldrh r1, [r1, #2]
	strh r1, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r5, r7, #0
	cmp r2, #0
	blt _0813D2F2
	cmp r1, #0
	blt _0813D2F2
	ldr r0, _0813D300 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0813D2F2
	ldr r0, _0813D304 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0813D308
_0813D2F2:
	movs r4, #0
	b _0813D316
	.align 2, 0
_0813D2F8: .4byte 0x0000046C
_0813D2FC: .4byte 0x00000484
_0813D300: .4byte 0x030046A8
_0813D304: .4byte 0x030046AC
_0813D308:
	ldr r0, _0813D328 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0813D316:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0813D32C
	adds r0, #4
	b _0813D338
	.align 2, 0
_0813D328: .4byte 0x030046A4
_0813D32C:
	ldr r0, _0813D34C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0813D338:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0813D350
	cmp r2, #2
	beq _0813D354
	b _0813D358
	.align 2, 0
_0813D34C: .4byte 0x030046A4
_0813D350:
	ldrb r0, [r7, #4]
	b _0813D356
_0813D354:
	ldrb r0, [r7]
_0813D356:
	subs r1, r1, r0
_0813D358:
	movs r4, #0
	movs r0, #0
	mov r8, r0
	strh r1, [r7, #2]
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_0813c54c
	adds r0, r6, #0
	bl FUN_0813c584
	movs r1, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r4, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r4, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	adds r2, #0x1a
	adds r0, r6, r2
	mov r2, r8
	str r2, [r0]
	ldr r2, _0813D3D8 @ =0x0000046C
	adds r0, r6, r2
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #8
	add r2, sp, #4
	ldrh r0, [r2]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r5, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r2, #4
	ldrsh r1, [r5, r2]
	bl FUN_0823785c
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r1, #0xd5
	lsls r1, r1, #3
	add r1, sb
	mov r0, r8
	str r0, [sp]
	mov r0, sp
	ldr r2, _0813D3DC @ =0x05000002
	bl CpuSet
	b _0813D3E4
	.align 2, 0
_0813D3D8: .4byte 0x0000046C
_0813D3DC: .4byte 0x05000002
_0813D3E0:
	adds r0, #1
	str r0, [r1]
_0813D3E4:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0813d3f4
FUN_0813d3f4: @ 0x0813D3F4
	movs r1, #0xc7
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, _0813D400 @ =0x085AD7AC
	str r1, [r0]
	bx lr
	.align 2, 0
_0813D400: .4byte 0x085AD7AC

	thumb_func_start FUN_0813d404
FUN_0813d404: @ 0x0813D404
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0813cdf8
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _0813D43C @ =0x0000062C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e4964
	adds r0, r4, #0
	bl FUN_0813ce10
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0813D43C: .4byte 0x0000062C

	thumb_func_start FUN_0813d440
FUN_0813d440: @ 0x0813D440
	push {lr}
	movs r1, #0xec
	lsls r1, r1, #1
	adds r2, r0, r1
	ldr r1, _0813D45C @ =0x03002BE0
	ldr r1, [r1]
	adds r1, #0x24
	str r1, [r2]
	bl FUN_080f06b0
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_0813D45C: .4byte 0x03002BE0

	thumb_func_start EnemyCuroro_Destroy
EnemyCuroro_Destroy: @ 0x0813D460
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _0813D478 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0813D47C
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _0813D484
	.align 2, 0
_0813D478: .4byte 0x0000025D
_0813D47C:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_0813D484:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _0813D4A0 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _0813D4A4
	movs r0, #1
	b _0813D4A6
	.align 2, 0
_0813D4A0: .4byte 0x00000474
_0813D4A4:
	movs r0, #0
_0813D4A6:
	cmp r0, #0
	beq _0813D4B2
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_0813D4B2:
	ldr r1, _0813D50C @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _0813D4CA
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_0813D4CA:
	ldr r0, _0813D510 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _0813D4E2
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_0813D4E2:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0813D4FA
	adds r0, r4, #0
	bl FUN_08002a58
_0813D4FA:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0813D514
	movs r0, #1
	b _0813D516
	.align 2, 0
_0813D50C: .4byte 0x0000044C
_0813D510: .4byte 0x0000044D
_0813D514:
	movs r0, #0
_0813D516:
	cmp r0, #0
	beq _0813D522
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_0813D522:
	adds r0, r4, #0
	bl FUN_0823b284
	adds r0, r4, #0
	adds r0, #0xd8
	bl FUN_08236424
	adds r0, r4, #0
	bl FUN_080ec6fc
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EnemyCuroro_Init
EnemyCuroro_Init: @ 0x0813D540
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1a4
	adds r7, r0, #0
	str r7, [sp, #0x24]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r6, #0
	str r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	ldr r2, _0813D5CC @ =0x000001DF
	adds r1, r7, r2
	movs r0, #0x11
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_0813c738
	ldr r3, _0813D5D0 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0813D5DC
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _0813D5D4 @ =0x0000D28E
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _0813D5D8 @ =0x00009607
	bl FUN_080e3804
	ldr r4, _0813D5CC @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0x90]
	cmp r1, #0x11
	beq _0813D5BA
	cmp r1, #0x17
	bne _0813D5BE
_0813D5BA:
	movs r0, #1
	strb r0, [r5, #7]
_0813D5BE:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _0813D644
	.align 2, 0
_0813D5CC: .4byte 0x000001DF
_0813D5D0: .4byte 0x0000025D
_0813D5D4: .4byte 0x0000D28E
_0813D5D8: .4byte 0x00009607
_0813D5DC:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r0, sp, #0x14
	mov r8, r0
	str r6, [sp, #0x10]
	add r0, sp, #0x10
	mov r1, r8
	ldr r2, _0813D6C0 @ =0x05000002
	bl CpuSet
	ldr r0, _0813D6C4 @ =0x0000CB05
	ldr r1, _0813D6C8 @ =0x0000D28E
	bl GetFile
	adds r1, r0, #0
	adds r2, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	adds r0, r4, #0
	bl OpenSpriteSetFile
	adds r0, r4, #0
	adds r0, #0x20
	movs r1, #2
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r6, r8
	str r6, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	ldr r0, _0813D6CC @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _0813D6D0 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0x90]
_0813D644:
	str r7, [sp, #0x28]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sb, r2
	movs r4, #0
	str r4, [r2]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r3, r3, r7
	mov r8, r3
	str r4, [r3]
	ldr r5, _0813D6D4 @ =0x0000046F
	adds r0, r7, r5
	strb r4, [r0]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r0, #0
	mov sl, r0
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, _0813D6D8 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _0813D6C0 @ =0x05000002
	bl CpuSet
	ldr r3, _0813D6DC @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x19c]
	bl VM_SeekToKeyword
	mov r1, sb
	str r1, [sp, #0x60]
	mov r3, r8
	str r3, [sp, #0x64]
	str r6, [sp, #0x3c]
	ldr r2, [sp, #0x19c]
	adds r6, r2, #0
	cmp r0, #0
	bne _0813D6B0
	b _0813D810
_0813D6B0:
	bl VM_GetPC
	cmp r0, #0
	beq _0813D6E0
	bl Script_GetValue
	adds r1, r0, #0
	b _0813D6E2
	.align 2, 0
_0813D6C0: .4byte 0x05000002
_0813D6C4: .4byte 0x0000CB05
_0813D6C8: .4byte 0x0000D28E
_0813D6CC: .4byte 0x000004B7
_0813D6D0: .4byte 0x000001DF
_0813D6D4: .4byte 0x0000046F
_0813D6D8: .4byte 0x00000474
_0813D6DC: .4byte 0x000004B6
_0813D6E0:
	movs r1, #0
_0813D6E2:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _0813D708 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xe8]
	str r4, [sp, #0xec]
	cmp r0, #0
	beq _0813D70C
	bl Script_GetValue
	adds r1, r0, #0
	b _0813D70E
	.align 2, 0
_0813D708: .4byte 0x00000251
_0813D70C:
	movs r1, #0
_0813D70E:
	ldr r2, _0813D744 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _0813D748 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xe8]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0xf4]
	cmp r0, #0
	beq _0813D74C
	bl Script_GetValue
	b _0813D750
	.align 2, 0
_0813D744: .4byte 0x00000252
_0813D748: .4byte 0x000004B4
_0813D74C:
	ldr r4, [sp, #0xe8]
	ldrb r0, [r4]
_0813D750:
	strb r0, [r6]
	ldr r5, [sp, #0xe8]
	ldrb r1, [r5]
	ldr r6, [sp, #0xf4]
	ldrb r2, [r6]
	add r0, sp, #0x1c
	bl FUN_08234f90
	add r0, sp, #0x1c
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sp
	ldrh r0, [r1, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0813D788
	cmp r1, #0
	blt _0813D788
	ldr r0, _0813D78C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0813D788
	ldr r0, _0813D790 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0813D794
_0813D788:
	movs r1, #0
	b _0813D7A2
	.align 2, 0
_0813D78C: .4byte 0x030046A8
_0813D790: .4byte 0x030046AC
_0813D794:
	ldr r0, _0813D7BC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0813D7A2:
	ldr r2, _0813D7C0 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0813D7C4
	adds r0, #4
	b _0813D7D0
	.align 2, 0
_0813D7BC: .4byte 0x030046A4
_0813D7C0: .4byte 0x00000256
_0813D7C4:
	ldr r0, _0813D7E4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0813D7D0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0813D7E8
	cmp r2, #2
	beq _0813D7EC
	b _0813D7F0
	.align 2, 0
_0813D7E4: .4byte 0x030046A4
_0813D7E8:
	ldrb r0, [r4, #4]
	b _0813D7EE
_0813D7EC:
	ldrb r0, [r4]
_0813D7EE:
	subs r1, r1, r0
_0813D7F0:
	ldr r3, _0813D808 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _0813D80C @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _0813D850
	.align 2, 0
_0813D808: .4byte 0x00000472
_0813D80C: .4byte 0x0000FFFF
_0813D810:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _0813D874 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _0813D878 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _0813D87C @ =0x000004B4
	adds r1, r7, r6
	adds r0, r1, r0
	mov r6, sl
	strb r6, [r0]
	ldrb r2, [r2]
	movs r0, #1
	eors r0, r2
	adds r1, r1, r0
	strb r6, [r1]
	movs r0, #0
	str r0, [sp, #0x2c]
	str r5, [sp, #0xe8]
	str r4, [sp, #0xec]
	str r3, [sp, #0xf4]
_0813D850:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0813D89A
	bl VM_GetPC
	cmp r0, #0
	beq _0813D880
	bl Script_GetValue
	adds r4, r0, #0
	b _0813D882
	.align 2, 0
_0813D874: .4byte 0x00000251
_0813D878: .4byte 0x00000252
_0813D87C: .4byte 0x000004B4
_0813D880:
	movs r4, #0x30
_0813D882:
	bl VM_GetPC
	cmp r0, #0
	beq _0813D894
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _0813D896
_0813D894:
	movs r5, #0x40
_0813D896:
	mov r8, r4
	b _0813D8A0
_0813D89A:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_0813D8A0:
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0813D8D8
	bl VM_GetPC
	cmp r0, #0
	beq _0813D8BA
	bl Script_GetValue
	adds r6, r0, #0
	b _0813D8BC
_0813D8BA:
	movs r6, #0
_0813D8BC:
	bl VM_GetPC
	cmp r0, #0
	beq _0813D8CC
	bl Script_GetValue
	adds r1, r0, #0
	b _0813D8CE
_0813D8CC:
	movs r1, #0
_0813D8CE:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _0813D8E2
_0813D8D8:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_0813D8E2:
	movs r0, #0x61
	bl VM_SeekToKeyword
	ldr r1, _0813DB54 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x108]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x68]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xf8]
	lsls r4, r4, #0x10
	str r4, [sp, #0x84]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x8c]
	lsls r6, r6, #0x10
	str r6, [sp, #0x94]
	lsls r5, r5, #0x10
	str r5, [sp, #0x88]
	ldr r4, _0813DB58 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x104]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x7c]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x18c]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x98]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x9c]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x190]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x194]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x188]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x4c]
	ldr r1, _0813DB5C @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x40]
	ldr r2, _0813DB60 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x44]
	ldr r3, _0813DB64 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x48]
	ldr r4, _0813DB68 @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0x58]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x5c]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xd8]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xe4]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xfc]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x114]
	ldr r4, _0813DB6C @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0x118]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x12c]
	ldr r6, _0813DB70 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0x130]
	ldr r1, _0813DB74 @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0x138]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x13c]
	ldr r3, _0813DB78 @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0x140]
	ldr r4, _0813DB7C @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0x148]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x134]
	ldr r6, _0813DB80 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0xdc]
	ldr r1, _0813DB84 @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x16c]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x170]
	ldr r3, _0813DB88 @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0xa8]
	ldr r4, _0813DB8C @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x174]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x15c]
	ldr r6, _0813DB90 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0x150]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x160]
	ldr r2, _0813DB94 @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x164]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x168]
	ldr r4, _0813DB98 @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x178]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x17c]
	ldr r6, _0813DB9C @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0x128]
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x154]
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x14c]
	ldr r3, _0813DBA0 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x158]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x144]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x11c]
	ldr r6, _0813DBA4 @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x180]
	ldr r1, _0813DBA8 @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0xf0]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x184]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x124]
	ldr r4, _0813DBAC @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0x100]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x10c]
	ldr r6, _0813DBB0 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0x110]
	ldr r1, _0813DBB4 @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0x120]
	ldr r2, _0813DBB8 @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0xa0]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x70]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x74]
	ldr r5, _0813DBBC @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x54]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x30]
	ldr r1, _0813DBC0 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x34]
	ldr r2, _0813DBC4 @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x38]
	ldr r3, _0813DBC8 @ =0x00000553
	adds r3, r7, r3
	str r3, [sp, #0xa4]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xd4]
	movs r5, #0x92
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x50]
	movs r6, #0xea
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x80]
	ldr r1, _0813DBCC @ =0x00000572
	adds r1, r7, r1
	str r1, [sp, #0xd0]
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x78]
	movs r3, #0xae
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xcc]
	ldr r4, _0813DBD0 @ =0x0000055C
	adds r4, r7, r4
	str r4, [sp, #0xac]
	movs r5, #0xac
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xb0]
	ldr r6, _0813DBD4 @ =0x00000564
	adds r6, r7, r6
	str r6, [sp, #0xb4]
	ldr r1, _0813DBD8 @ =0x00000565
	adds r1, r7, r1
	str r1, [sp, #0xb8]
	ldr r2, _0813DBDC @ =0x00000566
	adds r2, r7, r2
	str r2, [sp, #0xbc]
	ldr r3, _0813DBE0 @ =0x00000567
	adds r3, r7, r3
	str r3, [sp, #0xc0]
	movs r4, #0xad
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xc4]
	ldr r5, _0813DBE4 @ =0x0000056C
	adds r5, r7, r5
	str r5, [sp, #0xc8]
	cmp r0, #0
	bne _0813DB24
	b _0813DC3E
_0813DB24:
	movs r6, #0
	mov sl, r6
	movs r0, #0x8d
	lsls r0, r0, #2
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0x8f
	lsls r1, r1, #2
	adds r1, r1, r7
	mov r8, r1
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r5, r7, r2
	movs r3, #0x89
	lsls r3, r3, #2
	adds r4, r7, r3
_0813DB44:
	bl VM_GetPC
	cmp r0, #0
	beq _0813DBE8
	bl Script_GetValue
	b _0813DBEA
	.align 2, 0
_0813DB54: .4byte 0x0000025D
_0813DB58: .4byte 0x0000025A
_0813DB5C: .4byte 0x0000047A
_0813DB60: .4byte 0x0000047C
_0813DB64: .4byte 0x0000047E
_0813DB68: .4byte 0x000004A4
_0813DB6C: .4byte 0x000005A4
_0813DB70: .4byte 0x000005C4
_0813DB74: .4byte 0x000005CC
_0813DB78: .4byte 0x000005D4
_0813DB7C: .4byte 0x000005DC
_0813DB80: .4byte 0x00000584
_0813DB84: .4byte 0x00000604
_0813DB88: .4byte 0x0000021D
_0813DB8C: .4byte 0x0000060C
_0813DB90: .4byte 0x000005E4
_0813DB94: .4byte 0x000005FC
_0813DB98: .4byte 0x00000614
_0813DB9C: .4byte 0x000005BC
_0813DBA0: .4byte 0x000005EC
_0813DBA4: .4byte 0x00000624
_0813DBA8: .4byte 0x0000058C
_0813DBAC: .4byte 0x00000594
_0813DBB0: .4byte 0x0000059C
_0813DBB4: .4byte 0x000005B4
_0813DBB8: .4byte 0x00000543
_0813DBBC: .4byte 0x00000496
_0813DBC0: .4byte 0x00000469
_0813DBC4: .4byte 0x0000046A
_0813DBC8: .4byte 0x00000553
_0813DBCC: .4byte 0x00000572
_0813DBD0: .4byte 0x0000055C
_0813DBD4: .4byte 0x00000564
_0813DBD8: .4byte 0x00000565
_0813DBDC: .4byte 0x00000566
_0813DBE0: .4byte 0x00000567
_0813DBE4: .4byte 0x0000056C
_0813DBE8:
	movs r0, #0x18
_0813DBEA:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _0813DBFC
	bl Script_GetValue
	b _0813DBFE
_0813DBFC:
	movs r0, #0x18
_0813DBFE:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _0813DC10
	bl Script_GetValue
	b _0813DC12
_0813DC10:
	movs r0, #0
_0813DC12:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _0813DC24
	bl Script_GetValue
	b _0813DC26
_0813DC24:
	movs r0, #0
_0813DC26:
	strh r0, [r6]
	movs r6, #2
	add sb, r6
	movs r0, #4
	add r8, r0
	adds r5, #2
	adds r4, #2
	movs r1, #1
	add sl, r1
	mov r2, sl
	cmp r2, #3
	ble _0813DB44
_0813DC3E:
	movs r0, #0x6c
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0813DC8A
	bl VM_GetPC
	cmp r0, #0
	beq _0813DC58
	bl Script_GetValue
	adds r4, r0, #0
	b _0813DC5C
_0813DC58:
	movs r4, #0x96
	lsls r4, r4, #1
_0813DC5C:
	bl VM_GetPC
	cmp r0, #0
	beq _0813DC6C
	bl Script_GetValue
	adds r6, r0, #0
	b _0813DC70
_0813DC6C:
	movs r6, #0x96
	lsls r6, r6, #1
_0813DC70:
	bl VM_GetPC
	cmp r0, #0
	beq _0813DC7E
	bl Script_GetValue
	b _0813DC84
_0813DC7E:
	movs r3, #0x96
	lsls r3, r3, #1
	adds r0, r3, #0
_0813DC84:
	ldr r5, [sp, #0xe0]
	strh r0, [r5]
	b _0813DC92
_0813DC8A:
	movs r4, #0
	movs r6, #0
	ldr r0, [sp, #0xe0]
	strh r6, [r0]
_0813DC92:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _0813DCAA
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x64]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_0813DCAA:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r3, [sp, #0x6c]
	strh r0, [r3]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r5, [sp, #0x68]
	strh r0, [r5]
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0813DD78
	bl VM_GetPC
	cmp r0, #0
	beq _0813DCDA
	bl Script_GetValue
	b _0813DCDC
_0813DCDA:
	movs r0, #0
_0813DCDC:
	ldr r1, [sp, #0xf8]
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, #0
	blt _0813DCEA
	asrs r1, r0, #1
	b _0813DCF0
_0813DCEA:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_0813DCF0:
	ldr r2, _0813DD04 @ =0x00000546
	adds r0, r7, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0813DD08
	bl Script_GetValue
	b _0813DD0A
	.align 2, 0
_0813DD04: .4byte 0x00000546
_0813DD08:
	movs r0, #0
_0813DD0A:
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0813DD20
	bl Script_GetValue
	b _0813DD22
_0813DD20:
	movs r0, #0
_0813DD22:
	ldr r5, _0813DD38 @ =0x00000187
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0813DD3C
	bl Script_GetValue
	adds r1, r0, #0
	b _0813DD3E
	.align 2, 0
_0813DD38: .4byte 0x00000187
_0813DD3C:
	movs r1, #0
_0813DD3E:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0813DD54
	bl Script_GetValue
	b _0813DD56
_0813DD54:
	movs r0, #0
_0813DD56:
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0813DD6E
	bl Script_GetValue
	adds r1, r0, #0
	b _0813DD70
_0813DD6E:
	movs r1, #0
_0813DD70:
	movs r5, #0xc6
	lsls r5, r5, #1
	adds r0, r7, r5
	strh r1, [r0]
_0813DD78:
	ldr r0, [sp, #0xf8]
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r1, [sp, #0x84]
	lsrs r2, r1, #0x10
	ldr r4, [sp, #0x8c]
	lsrs r3, r4, #0x10
	ldr r5, [sp, #0x94]
	lsrs r0, r5, #0x10
	str r0, [sp]
	ldr r6, [sp, #0x88]
	lsrs r0, r6, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0813DDDA
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r6, r7, r0
	bl VM_GetPC
	cmp r0, #0
	beq _0813DDC0
	bl Script_GetValue
	b _0813DDC2
_0813DDC0:
	movs r0, #0
_0813DDC2:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _0813DDD2
	bl Script_GetValue
	b _0813DDD4
_0813DDD2:
	movs r0, #0
_0813DDD4:
	ldr r2, _0813DE3C @ =0x00000189
	adds r1, r7, r2
	strb r0, [r1]
_0813DDDA:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetKeywordValue
	ldr r3, [sp, #0x104]
	strh r0, [r3]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _0813DDFE
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r4, [sp, #0x64]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_0813DDFE:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _0813DE16
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r5, [sp, #0x64]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0813DE16:
	ldr r6, [sp, #0x7c]
	lsrs r1, r6, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x28]
	add r2, sp, #0x1c
	movs r3, #0
	bl FUN_0823b400
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x3c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0813DE40
	movs r0, #1
	b _0813DE42
	.align 2, 0
_0813DE3C: .4byte 0x00000189
_0813DE40:
	movs r0, #0
_0813DE42:
	cmp r0, #0
	beq _0813DE52
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _0813DE7C @ =FUN_080f48ac
	ldr r1, [sp, #0x28]
	bl FUN_0807f558
_0813DE52:
	ldr r3, [sp, #0x108]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _0813DE5E
	ldr r1, [r7, #0x44]
_0813DE5E:
	ldr r0, [sp, #0x28]
	bl FUN_0823b46c
	ldr r4, [sp, #0x90]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _0813DE80
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x18c]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _0813DE8C
	.align 2, 0
_0813DE7C: .4byte FUN_080f48ac
_0813DE80:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x18c]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_0813DE8C:
	ldr r5, [sp, #0x90]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0813DEDA
	adds r0, r1, #0
	cmp r0, #0xb
	beq _0813DEDA
	cmp r0, #0x16
	beq _0813DEDA
	cmp r0, #0x14
	beq _0813DEDA
	cmp r0, #9
	beq _0813DEDA
	cmp r0, #0x19
	beq _0813DEDA
	cmp r0, #0x1a
	beq _0813DEDA
	cmp r0, #0xd
	beq _0813DEDA
	cmp r0, #0x1b
	beq _0813DEDA
	cmp r0, #0x1f
	beq _0813DEDA
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0xe8]
	ldrb r2, [r6]
	ldr r0, [sp, #0xec]
	ldrb r3, [r0]
	ldr r4, [sp, #0xf4]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl FUN_0823b490
_0813DEDA:
	movs r1, #8
	ldr r5, [sp, #0x3c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0813DEEA
	movs r0, #1
	b _0813DEEC
_0813DEEA:
	movs r0, #0
_0813DEEC:
	cmp r0, #0
	beq _0813DEFA
	ldr r6, [sp, #0x9c]
	ldr r0, [r6]
	ldr r1, [sp, #0x98]
	str r0, [r1]
	b _0813DF0C
_0813DEFA:
	ldr r2, [sp, #0x9c]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0x98]
	str r0, [r3]
_0813DF0C:
	ldrh r0, [r7]
	ldr r4, [sp, #0x190]
	strh r0, [r4]
	ldr r5, [sp, #0x188]
	ldr r6, [sp, #0x194]
	str r5, [r6]
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq _0813DF36
	adds r0, r7, #0
	adds r0, #0xa4
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	lsrs r0, r0, #0xc
	movs r1, #7
	ands r0, r1
	adds r0, #5
	ands r0, r1
	lsls r0, r0, #5
	ldr r1, [sp, #0x28]
	strb r0, [r1, #5]
_0813DF36:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0813E014
	bl VM_GetPC
	cmp r0, #0
	beq _0813DF4E
	bl Script_GetValue
	b _0813DF50
_0813DF4E:
	movs r0, #0
_0813DF50:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _0813DF60
	bl Script_GetValue
	b _0813DF62
_0813DF60:
	movs r0, #0
_0813DF62:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _0813DF72
	bl Script_GetValue
	b _0813DF74
_0813DF72:
	movs r0, #0
_0813DF74:
	strh r0, [r7, #0xc]
	ldrh r0, [r7, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldr r3, [sp, #0x188]
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0813DF9C
	cmp r1, #0
	blt _0813DF9C
	ldr r0, _0813DFA0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0813DF9C
	ldr r0, _0813DFA4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0813DFA8
_0813DF9C:
	movs r1, #0
	b _0813DFB6
	.align 2, 0
_0813DFA0: .4byte 0x030046A8
_0813DFA4: .4byte 0x030046AC
_0813DFA8:
	ldr r0, _0813DFD0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0813DFB6:
	ldr r4, _0813DFD4 @ =0x00000256
	adds r0, r7, r4
	strh r1, [r0]
	ldrh r4, [r0]
	ldr r5, [sp, #0x188]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0813DFD8
	adds r0, #4
	b _0813DFE4
	.align 2, 0
_0813DFD0: .4byte 0x030046A4
_0813DFD4: .4byte 0x00000256
_0813DFD8:
	ldr r0, _0813DFF8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0813DFE4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0813DFFC
	cmp r2, #2
	beq _0813E000
	b _0813E004
	.align 2, 0
_0813DFF8: .4byte 0x030046A4
_0813DFFC:
	ldrb r0, [r5, #4]
	b _0813E002
_0813E000:
	ldrb r0, [r5]
_0813E002:
	subs r1, r1, r0
_0813E004:
	ldr r5, _0813E030 @ =0x00000472
	adds r0, r7, r5
	strh r1, [r0]
	ldr r6, [sp, #0x24]
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r0, r6, r2
	strh r1, [r0]
_0813E014:
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0813E05E
	bl VM_GetPC
	cmp r0, #0
	beq _0813E034
	bl Script_GetValue
	adds r1, r0, #0
	b _0813E036
	.align 2, 0
_0813E030: .4byte 0x00000472
_0813E034:
	movs r1, #0
_0813E036:
	ldr r3, [sp, #0x24]
	ldr r4, _0813E050 @ =0x0000065C
	adds r0, r3, r4
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0813E054
	bl Script_GetValue
	adds r1, r0, #0
	b _0813E056
	.align 2, 0
_0813E050: .4byte 0x0000065C
_0813E054:
	movs r1, #0
_0813E056:
	ldr r5, [sp, #0x24]
	ldr r6, _0813E09C @ =0x0000065D
	adds r0, r5, r6
	strb r1, [r0]
_0813E05E:
	movs r4, #0x5c
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x4c]
	strh r0, [r1]
	ldr r2, [sp, #0x40]
	strh r4, [r2]
	ldr r3, [sp, #0x44]
	strh r5, [r3]
	ldrh r0, [r1]
	adds r0, #0x61
	ldr r4, [sp, #0x48]
	strh r0, [r4]
	ldrh r1, [r2]
	ldr r5, [sp, #0x4c]
	ldrh r0, [r5]
	adds r1, r1, r0
	ldr r6, [sp, #0x108]
	ldrb r0, [r6]
	cmp r0, #0
	bne _0813E0A0
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _0813E0AC
	.align 2, 0
_0813E09C: .4byte 0x0000065D
_0813E0A0:
	ldr r2, [r7, #0x44]
	ldr r0, _0813E0E4 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_0813E0AC:
	ldr r1, [sp, #0x108]
	ldrb r0, [r1]
	cmp r0, #1
	bne _0813E0FC
	ldr r2, [sp, #0x90]
	ldrb r0, [r2]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0813E0E8
	movs r0, #5
	bl FUN_080ecf60
	adds r4, r0, #1
	movs r0, #6
	bl FUN_080ecf60
	adds r4, r4, r0
	movs r0, #7
	bl FUN_080ecf60
	adds r4, r4, r0
	movs r0, #8
	bl FUN_080ecf60
	adds r4, r4, r0
	b _0813E0F2
	.align 2, 0
_0813E0E4: .4byte 0x03003584
_0813E0E8:
	ldr r3, [sp, #0x90]
	ldrb r0, [r3]
	bl FUN_080ecf60
	adds r4, r0, #1
_0813E0F2:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_0813E0FC:
	adds r0, r7, #0
	bl FUN_0813c44c
	ldr r5, [sp, #0x24]
	ldr r6, _0813E2A8 @ =0x0000066C
	adds r4, r5, r6
	movs r0, #0xd2
	lsls r0, r0, #3
	adds r5, r5, r0
	ldr r1, _0813E2AC @ =FUN_0813d404
	str r1, [sp, #0x1a0]
	ldr r2, _0813E2B0 @ =FUN_0813c51c
	mov r8, r2
	ldr r3, _0813E2B4 @ =FUN_0813ae6c
	mov sb, r3
	ldr r6, _0813E2B8 @ =FUN_0813ac34
	mov sl, r6
	ldr r0, _0813E2BC @ =FUN_0813ad64
	mov ip, r0
	movs r2, #0
	ldr r3, _0813E2C0 @ =FUN_080f62b0
	ldr r1, _0813E2C4 @ =FUN_080f62ac
	str r1, [sp, #0x198]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x60]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x58]
	str r4, [r0]
	ldr r1, [sp, #0x5c]
	str r5, [r1]
	ldr r4, [sp, #0x1a0]
	ldr r5, [sp, #0xd8]
	str r4, [r5]
	mov r6, r8
	ldr r0, [sp, #0xe4]
	str r6, [r0]
	mov r1, sb
	ldr r4, [sp, #0xfc]
	str r1, [r4]
	mov r5, sl
	ldr r6, [sp, #0x114]
	str r5, [r6]
	mov r0, ip
	ldr r1, [sp, #0x118]
	str r0, [r1]
	ldr r4, [sp, #0x12c]
	str r2, [r4]
	ldr r5, [sp, #0x130]
	str r3, [r5]
	ldr r6, _0813E2C8 @ =FUN_0813b358
	ldr r0, [sp, #0x138]
	str r6, [r0]
	ldr r1, _0813E2CC @ =FUN_0813b640
	ldr r3, [sp, #0x13c]
	str r1, [r3]
	ldr r0, _0813E2D0 @ =FUN_080f44f4
	ldr r4, [sp, #0x140]
	str r0, [r4]
	ldr r0, _0813E2D4 @ =FUN_080f410c
	ldr r5, [sp, #0x148]
	str r0, [r5]
	ldr r6, [sp, #0x134]
	str r2, [r6]
	ldr r0, [sp, #0xdc]
	str r2, [r0]
	ldr r1, [sp, #0x198]
	ldr r3, [sp, #0x16c]
	str r1, [r3]
	ldr r0, _0813E2D8 @ =FUN_080f0430
	ldr r4, [sp, #0x170]
	str r0, [r4]
	movs r6, #1
	ldr r5, [sp, #0xa8]
	strb r6, [r5]
	ldr r0, _0813E2DC @ =0x085AD470
	ldr r1, [sp, #0x174]
	str r0, [r1]
	ldr r0, _0813E2E0 @ =FUN_080e73c8
	ldr r3, [sp, #0x15c]
	str r0, [r3]
	ldr r4, [sp, #0x150]
	str r2, [r4]
	ldr r5, [sp, #0x160]
	str r2, [r5]
	ldr r6, [sp, #0x164]
	str r2, [r6]
	ldr r0, [sp, #0x168]
	str r2, [r0]
	ldr r1, [sp, #0x178]
	str r2, [r1]
	ldr r0, _0813E2E4 @ =FUN_080f0320
	ldr r3, [sp, #0x17c]
	str r0, [r3]
	ldr r0, _0813E2E8 @ =FUN_080eff14
	ldr r4, [sp, #0x128]
	str r0, [r4]
	ldr r0, _0813E2EC @ =FUN_080e72b0
	ldr r5, [sp, #0x154]
	str r0, [r5]
	ldr r6, [sp, #0x14c]
	str r2, [r6]
	ldr r0, _0813E2F0 @ =FUN_080f47c8
	ldr r1, [sp, #0x158]
	str r0, [r1]
	ldr r0, _0813E2F4 @ =FUN_080f54e4
	ldr r3, [sp, #0x144]
	str r0, [r3]
	ldr r4, [sp, #0x11c]
	str r2, [r4]
	ldr r0, _0813E2F8 @ =FUN_080f6e64
	ldr r5, [sp, #0x180]
	str r0, [r5]
	ldr r0, _0813E2FC @ =FUN_080f64f0
	ldr r6, [sp, #0xf0]
	str r0, [r6]
	ldr r0, _0813E300 @ =FUN_080f84d4
	ldr r1, [sp, #0x184]
	str r0, [r1]
	ldr r0, _0813E304 @ =FUN_080f624c
	ldr r3, [sp, #0x124]
	str r0, [r3]
	ldr r0, _0813E308 @ =FUN_080f56ec
	ldr r4, [sp, #0x100]
	str r0, [r4]
	ldr r0, _0813E30C @ =FUN_080f5b34
	ldr r5, [sp, #0x10c]
	str r0, [r5]
	ldr r0, _0813E310 @ =FUN_080f5fac
	ldr r6, [sp, #0x110]
	str r0, [r6]
	ldr r0, [sp, #0x120]
	str r2, [r0]
	movs r0, #0x28
	ldr r1, [sp, #0xa0]
	strb r0, [r1]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _0813E314 @ =enemy_curoro_0813c7ac
	str r0, [r1]
	ldr r4, _0813E318 @ =0x000005FC
	adds r0, r7, r4
	str r2, [r0]
	ldr r5, _0813E31C @ =0x000005AC
	adds r1, r7, r5
	ldr r0, _0813E320 @ =FUN_0813ccf0
	str r0, [r1]
	movs r6, #0xb6
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _0813E324 @ =FUN_0813cc7c
	str r0, [r1]
	ldr r2, _0813E328 @ =0x0000060C
	adds r1, r7, r2
	ldr r0, _0813E32C @ =0x085AD7B4
	str r0, [r1]
	movs r0, #0x60
	ldr r3, [sp, #0x3c]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r4, [sp, #0x60]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r0, _0813E330 @ =0x02100400
	ldr r5, [sp, #0x64]
	ldr r1, [r5]
	orrs r1, r0
	str r1, [r5]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r0, #0
	beq _0813E274
	movs r0, #8
	orrs r1, r0
	str r1, [r5]
_0813E274:
	adds r0, r7, #0
	bl Enemy_Init_080e5dd4
	movs r0, #0x49
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x70]
	strh r0, [r1]
	movs r0, #0x47
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0813E33E
	movs r2, #0xce
	lsls r2, r2, #1
	adds r5, r7, r2
	movs r4, #4
_0813E298:
	bl VM_GetPC
	cmp r0, #0
	beq _0813E334
	bl Script_GetValue
	b _0813E336
	.align 2, 0
_0813E2A8: .4byte 0x0000066C
_0813E2AC: .4byte FUN_0813d404
_0813E2B0: .4byte FUN_0813c51c
_0813E2B4: .4byte FUN_0813ae6c
_0813E2B8: .4byte FUN_0813ac34
_0813E2BC: .4byte FUN_0813ad64
_0813E2C0: .4byte FUN_080f62b0
_0813E2C4: .4byte FUN_080f62ac
_0813E2C8: .4byte FUN_0813b358
_0813E2CC: .4byte FUN_0813b640
_0813E2D0: .4byte FUN_080f44f4
_0813E2D4: .4byte FUN_080f410c
_0813E2D8: .4byte FUN_080f0430
_0813E2DC: .4byte 0x085AD470
_0813E2E0: .4byte FUN_080e73c8
_0813E2E4: .4byte FUN_080f0320
_0813E2E8: .4byte FUN_080eff14
_0813E2EC: .4byte FUN_080e72b0
_0813E2F0: .4byte FUN_080f47c8
_0813E2F4: .4byte FUN_080f54e4
_0813E2F8: .4byte FUN_080f6e64
_0813E2FC: .4byte FUN_080f64f0
_0813E300: .4byte FUN_080f84d4
_0813E304: .4byte FUN_080f624c
_0813E308: .4byte FUN_080f56ec
_0813E30C: .4byte FUN_080f5b34
_0813E310: .4byte FUN_080f5fac
_0813E314: .4byte enemy_curoro_0813c7ac
_0813E318: .4byte 0x000005FC
_0813E31C: .4byte 0x000005AC
_0813E320: .4byte FUN_0813ccf0
_0813E324: .4byte FUN_0813cc7c
_0813E328: .4byte 0x0000060C
_0813E32C: .4byte 0x085AD7B4
_0813E330: .4byte 0x02100400
_0813E334:
	movs r0, #0
_0813E336:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _0813E298
_0813E33E:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r3, [sp, #0x74]
	strh r0, [r3]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r4, [sp, #0x54]
	strh r0, [r4]
	cmp r2, #0
	beq _0813E376
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r5, [sp, #0x60]
	ldr r1, [r5]
	orrs r1, r0
	str r1, [r5]
	cmp r2, #2
	bne _0813E376
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r5]
_0813E376:
	movs r2, #0
	movs r1, #4
	ldr r6, [sp, #0x3c]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0813E388
	movs r0, #1
	b _0813E38A
_0813E388:
	movs r0, #0
_0813E38A:
	cmp r0, #0
	beq _0813E39C
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r2, [sp, #0x64]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r2, #1
_0813E39C:
	cmp r2, #1
	beq _0813E3DC
	movs r1, #0
	ldr r3, [sp, #0x30]
	strb r1, [r3]
	ldr r4, [sp, #0x34]
	strb r1, [r4]
	ldr r5, [sp, #0x38]
	strb r1, [r5]
	ldr r6, _0813E3EC @ =0x00000484
	adds r0, r7, r6
	str r1, [r0]
	ldr r2, _0813E3F0 @ =0x0000046C
	adds r0, r7, r2
	movs r2, #1
	strb r2, [r0]
	ldr r4, [sp, #0x118]
	ldr r3, [r4]
	ldr r5, _0813E3F4 @ =0x0000046D
	adds r0, r7, r5
	strb r2, [r0]
	subs r6, #0x19
	adds r0, r7, r6
	strb r1, [r0]
	ldr r0, [sp, #0xa4]
	strb r1, [r0]
	ldr r2, [sp, #0xd4]
	str r3, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_0813E3DC:
	movs r1, #2
	ldr r4, [sp, #0x3c]
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0813E3F8
	movs r0, #1
	b _0813E3FA
	.align 2, 0
_0813E3EC: .4byte 0x00000484
_0813E3F0: .4byte 0x0000046C
_0813E3F4: .4byte 0x0000046D
_0813E3F8:
	movs r0, #0
_0813E3FA:
	cmp r0, #0
	beq _0813E414
	ldr r0, _0813E410 @ =0x030046A0
	ldr r0, [r0]
	movs r5, #0x92
	lsls r5, r5, #2
	adds r0, r0, r5
	ldr r0, [r0]
	ldr r6, [sp, #0x50]
	strh r0, [r6]
	b _0813E41E
	.align 2, 0
_0813E410: .4byte 0x030046A0
_0813E414:
	ldr r0, [sp, #0x188]
	bl FUN_08241574
	ldr r1, [sp, #0x50]
	strh r0, [r1]
_0813E41E:
	movs r1, #0x40
	ldr r2, [sp, #0x3c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0813E42E
	movs r0, #1
	b _0813E430
_0813E42E:
	movs r0, #0
_0813E430:
	cmp r0, #0
	beq _0813E440
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _0813E464 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_0813E440:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	bne _0813E472
	ldr r0, _0813E468 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x50]
	ldrh r4, [r4]
	cmp r0, r4
	bne _0813E46C
	movs r0, #1
	b _0813E46E
	.align 2, 0
_0813E464: .4byte 0xFFFFFEFF
_0813E468: .4byte 0x030046A0
_0813E46C:
	movs r0, #0
_0813E46E:
	cmp r0, #0
	bne _0813E47A
_0813E472:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_0813E47A:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, [sp, #0x108]
	ldrb r0, [r5]
	cmp r0, #0
	bne _0813E562
	ldr r5, [r7, #0x44]
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
	beq _0813E4BC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0813E4C4
_0813E4BC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0813E4C4:
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
	beq _0813E4E8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0813E4F0
_0813E4E8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0813E4F0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _0813E528 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0813E56C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0813E52C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0813E520
	ldrb r0, [r4, #5]
_0813E520:
	subs r0, #1
	strh r0, [r4, #8]
	b _0813E53C
	.align 2, 0
_0813E528: .4byte 0x0000FFFF
_0813E52C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0813E53C
	strh r1, [r4, #8]
_0813E53C:
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
	bne _0813E56C
	movs r0, #1
	strb r0, [r4, #7]
	b _0813E56C
_0813E562:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_0813E56C:
	movs r0, #0
	ldr r3, [sp, #0x80]
	str r0, [r3]
	ldr r0, _0813E584 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0813E588
	movs r0, #1
	b _0813E58A
	.align 2, 0
_0813E584: .4byte 0x030047A4
_0813E588:
	movs r0, #0
_0813E58A:
	cmp r0, #0
	bne _0813E5CA
	ldr r4, [sp, #0x90]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0813E5B2
	adds r0, r1, #0
	cmp r0, #7
	beq _0813E5B2
	cmp r0, #6
	beq _0813E5B2
	cmp r0, #0x15
	beq _0813E5B2
	cmp r0, #0x14
	beq _0813E5B2
	cmp r0, #0x17
	bne _0813E5CA
_0813E5B2:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x3c]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_0813E5CA:
	adds r0, r7, #0
	bl Enemy_Init_080f3680
	adds r0, r7, #0
	bl FUN_0813c138
	adds r0, r7, #0
	bl FUN_0813d1bc
	adds r0, r7, #0
	bl FUN_0813d3f4
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r0, #2
	strh r0, [r1]
	ldr r1, [sp, #0x3c]
	ldrh r0, [r1]
	ldr r2, [sp, #0xd0]
	strh r0, [r2]
	ldr r3, [sp, #0x78]
	ldrh r0, [r3]
	ldr r4, [sp, #0xcc]
	strh r0, [r4]
	ldr r5, [sp, #0x60]
	ldr r0, [r5]
	ldr r6, [sp, #0xac]
	str r0, [r6]
	ldr r1, [sp, #0x64]
	ldr r0, [r1]
	ldr r2, [sp, #0xb0]
	str r0, [r2]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0xb4]
	strb r0, [r3]
	ldr r4, [sp, #0x30]
	ldrb r0, [r4]
	ldr r5, [sp, #0xb8]
	strb r0, [r5]
	ldr r6, [sp, #0x34]
	ldrb r0, [r6]
	ldr r1, [sp, #0xbc]
	strb r0, [r1]
	ldr r2, [sp, #0x38]
	ldrb r0, [r2]
	ldr r3, [sp, #0xc0]
	strb r0, [r3]
	ldr r4, [sp, #0xd4]
	ldr r0, [r4]
	ldr r5, [sp, #0xc4]
	str r0, [r5]
	ldr r6, [sp, #0xa4]
	ldrb r0, [r6]
	ldr r1, [sp, #0xc8]
	strb r0, [r1]
	ldr r2, _0813E664 @ =0x0000057C
	adds r1, r7, r2
	ldr r0, _0813E668 @ =FUN_080f09e0
	str r0, [r1]
	ldr r3, _0813E66C @ =0x0000061C
	adds r1, r7, r3
	ldr r0, _0813E670 @ =FUN_0813d440
	str r0, [r1]
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _0813E674 @ =EnemyCuroro_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0813E678
	movs r0, #0
	b _0813E67C
	.align 2, 0
_0813E664: .4byte 0x0000057C
_0813E668: .4byte FUN_080f09e0
_0813E66C: .4byte 0x0000061C
_0813E670: .4byte FUN_0813d440
_0813E674: .4byte EnemyCuroro_Destroy
_0813E678:
	movs r0, #1
	rsbs r0, r0, #0
_0813E67C:
	add sp, #0x1a4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start EnemyCuroro_Create
EnemyCuroro_Create: @ 0x0813E68C
	push {r4, r5, lr}
	movs r5, #0xd6
	lsls r5, r5, #3
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _0813E6BA
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemyCuroro_Init
	cmp r0, #0
	bge _0813E6BA
	adds r0, r4, #0
	bl EnemyCuroro_Destroy
	adds r0, r4, #0
	bl Free
_0813E6BA:
	pop {r4, r5}
	pop {r0}
	bx r0
