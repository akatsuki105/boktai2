	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0807f478
FUN_0807f478: @ 0x0807F478
	push {lr}
	adds r3, r0, #0
	ldr r0, _0807F4A0 @ =0x03002BF8
	ldr r0, [r0]
	cmp r0, #0
	beq _0807F4A4
	ldr r1, [r0, #0x18]
	cmp r1, #0
	beq _0807F4A4
	ldr r0, [r1]
	ldrh r0, [r0]
	movs r2, #1
_0807F490:
	cmp r0, r3
	bne _0807F490
	ldr r0, [r1, #4]
	ands r0, r2
	cmp r0, #0
	bne _0807F4A4
	adds r0, r1, #0
	b _0807F4A6
	.align 2, 0
_0807F4A0: .4byte 0x03002BF8
_0807F4A4:
	movs r0, #0
_0807F4A6:
	pop {r1}
	bx r1
	.align 2, 0
_0807F4AC:
	.byte 0xF0, 0xB5, 0x57, 0x46
	.byte 0x4E, 0x46, 0x45, 0x46, 0xE0, 0xB4, 0x82, 0xB0, 0x80, 0x46, 0x00, 0x91, 0x99, 0x46, 0x03, 0x48
	.byte 0x00, 0x68, 0x00, 0x28, 0x04, 0xD1, 0x00, 0x20, 0x3C, 0xE0, 0x00, 0x00, 0xF8, 0x2B, 0x00, 0x03
	.byte 0x86, 0x69, 0x00, 0x20, 0x82, 0x46, 0x17, 0x1C, 0x57, 0x43, 0x00, 0x2E, 0x31, 0xD0, 0x80, 0x20
	.byte 0x40, 0x00, 0x49, 0x46, 0x41, 0x1A, 0x01, 0x91, 0x70, 0x68, 0x01, 0x21, 0x08, 0x40, 0x00, 0x28
	.byte 0x24, 0xD0, 0x32, 0x68, 0x08, 0x23, 0xD1, 0x5E, 0x44, 0x46, 0x00, 0x23, 0xE0, 0x5E, 0x0D, 0x1A
	.byte 0x0C, 0x24, 0x11, 0x5F, 0x42, 0x46, 0x04, 0x23, 0xD0, 0x5E, 0x0C, 0x1A, 0x28, 0x1C, 0x21, 0x1C
	.byte 0xB8, 0xF1, 0xA4, 0xF9, 0x00, 0x9A, 0x0F, 0x4B, 0xD1, 0x18, 0x41, 0x1A, 0xFF, 0x20, 0x01, 0x40
	.byte 0x49, 0x45, 0x02, 0xDD, 0x01, 0x98, 0x81, 0x42, 0x08, 0xDB, 0x29, 0x1C, 0x69, 0x43, 0x20, 0x1C
	.byte 0x60, 0x43, 0x08, 0x18, 0xB8, 0x42, 0x01, 0xDA, 0x07, 0x1C, 0xB2, 0x46, 0xF6, 0x68, 0x00, 0x2E
	.byte 0xD2, 0xD1, 0x50, 0x46, 0x02, 0xB0, 0x38, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC
	.byte 0x02, 0xBC, 0x08, 0x47, 0x00, 0xFF, 0xFF, 0xFF

	thumb_func_start FUN_0807f558
FUN_0807f558: @ 0x0807F558
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	ldr r0, _0807F56C @ =0x03002BF8
	ldr r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _0807F570
	movs r0, #0
	b _0807F590
	.align 2, 0
_0807F56C: .4byte 0x03002BF8
_0807F570:
	str r4, [r3]
	str r2, [r3, #8]
	ldr r0, [r1, #0x18]
	cmp r0, #0
	beq _0807F584
_0807F57A:
	cmp r0, r3
	beq _0807F58E
	ldr r0, [r0, #0xc]
	cmp r0, #0
	bne _0807F57A
_0807F584:
	ldr r0, [r5]
	ldr r0, [r0, #0x18]
	str r0, [r3, #0xc]
	ldr r0, [r5]
	str r3, [r0, #0x18]
_0807F58E:
	movs r0, #1
_0807F590:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0807f598
FUN_0807f598: @ 0x0807F598
	push {lr}
	adds r3, r0, #0
	ldr r0, _0807F5B0 @ =0x03002BF8
	ldr r2, [r0]
	cmp r2, #0
	beq _0807F5C6
	ldr r1, [r2, #0x18]
	cmp r1, r3
	bne _0807F5C0
	ldr r0, [r1, #0xc]
	str r0, [r2, #0x18]
	b _0807F5C6
	.align 2, 0
_0807F5B0: .4byte 0x03002BF8
_0807F5B4:
	ldr r0, [r0, #0xc]
	str r0, [r1, #0xc]
	b _0807F5C6
_0807F5BA:
	cmp r0, r3
	beq _0807F5B4
	ldr r1, [r1, #0xc]
_0807F5C0:
	ldr r0, [r1, #0xc]
	cmp r0, #0
	bne _0807F5BA
_0807F5C6:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807f5cc
FUN_0807f5cc: @ 0x0807F5CC
	movs r0, #0
	bx lr

	thumb_func_start FUN_0807f5d0
FUN_0807f5d0: @ 0x0807F5D0
	ldr r1, _0807F5D8 @ =0x03002BF8
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0807F5D8: .4byte 0x03002BF8

	thumb_func_start FUN_0807f5dc
FUN_0807f5dc: @ 0x0807F5DC
	movs r1, #0
	str r1, [r0, #0x18]
	str r1, [r0, #0x1c]
	ldr r1, _0807F5EC @ =0x03002BF8
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_0807F5EC: .4byte 0x03002BF8

	thumb_func_start FUN_0807f5f0
FUN_0807f5f0: @ 0x0807F5F0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _0807F62C @ =0x03002BF8
	ldr r0, [r0]
	cmp r0, #0
	bne _0807F63A
	movs r0, #2
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0807F638
	ldr r1, _0807F630 @ =FUN_0807f5cc
	ldr r2, _0807F634 @ =FUN_0807f5d0
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0807f5dc
	cmp r0, #0
	bge _0807F638
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0807F63A
	.align 2, 0
_0807F62C: .4byte 0x03002BF8
_0807F630: .4byte FUN_0807f5cc
_0807F634: .4byte FUN_0807f5d0
_0807F638:
	adds r0, r4, #0
_0807F63A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0807f640
FUN_0807f640: @ 0x0807F640
	movs r3, #0x98
	lsls r3, r3, #3
	adds r2, r0, r3
	str r1, [r2]
	adds r0, #0xee
	movs r1, #0
	strh r1, [r0]
	bx lr

	thumb_func_start FUN_0807f650
FUN_0807f650: @ 0x0807F650
	push {r4, r5, lr}
	adds r5, r0, #0
	mov ip, r1
	adds r1, #0x29
	mov r0, ip
	adds r0, #0x2d
	ldrb r0, [r0]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	mov r0, ip
	ldrh r3, [r0, #0x30]
	ldr r2, _0807F688 @ =0x085B0A08
	ldrb r0, [r1]
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
	blt _0807F68C
	asrs r3, r0, #0xc
	b _0807F692
	.align 2, 0
_0807F688: .4byte 0x085B0A08
_0807F68C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0807F692:
	ldr r2, [r5, #0x18]
	ldrh r0, [r2, #0x2c]
	adds r0, r0, r3
	mov r3, ip
	strh r0, [r3, #0x18]
	ldrh r1, [r3, #0x30]
	mov r0, ip
	adds r0, #0x29
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _0807F6B6
	asrs r1, r0, #0xc
	b _0807F6BC
_0807F6B6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0807F6BC:
	ldrh r0, [r2, #0x30]
	adds r0, r0, r1
	mov r1, ip
	strh r0, [r1, #0x1c]
	movs r2, #0x97
	lsls r2, r2, #3
	adds r0, r5, r2
	adds r1, #0x2b
	ldrh r2, [r0]
	ldrb r1, [r1]
	cmp r2, r1
	blo _0807F700
	movs r0, #7
	ands r0, r2
	cmp r0, #0
	bne _0807F6EA
	mov r1, ip
	adds r1, #0x2d
	ldrb r0, [r1]
	cmp r0, #2
	bls _0807F6EA
	subs r0, #1
	strb r0, [r1]
_0807F6EA:
	mov r3, ip
	ldrh r0, [r3, #0x30]
	adds r0, #6
	strh r0, [r3, #0x30]
	mov r1, ip
	adds r1, #0x2a
	ldrh r0, [r3, #0x1a]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r3, #0x1a]
	b _0807F708
_0807F700:
	mov r1, ip
	ldrh r0, [r1, #0x30]
	adds r0, #1
	strh r0, [r1, #0x30]
_0807F708:
	mov r0, ip
	adds r0, #0x2c
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	bne _0807F724
	adds r0, r5, #0
	adds r0, #0xf4
	ldr r1, [r0]
	mov r0, ip
	movs r2, #4
	bl FUN_0822dafc
	b _0807F736
_0807F724:
	cmp r1, #4
	bne _0807F736
	adds r0, r5, #0
	adds r0, #0xf4
	ldr r1, [r0]
	mov r0, ip
	movs r2, #5
	bl FUN_0822dafc
_0807F736:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _0807F748
	movs r0, #0
	strb r0, [r4]
_0807F748:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807f750
FUN_0807f750: @ 0x0807F750
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldrh r0, [r2, #0x34]
	ldrh r1, [r2, #0x18]
	adds r0, r0, r1
	strh r0, [r2, #0x18]
	ldrh r0, [r2, #0x38]
	ldrh r1, [r2, #0x1c]
	adds r0, r0, r1
	strh r0, [r2, #0x1c]
	adds r1, r2, #0
	adds r1, #0x2c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bne _0807F786
	adds r0, r3, #0
	adds r0, #0xf4
	ldr r1, [r0]
	adds r0, r2, #0
	movs r2, #5
	bl FUN_0822dafc
_0807F786:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0807f78c
FUN_0807f78c: @ 0x0807F78C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r0
	adds r3, r1, #0
	mov r8, r2
	movs r2, #0
	movs r1, #0x90
	lsls r1, r1, #1
	add r1, ip
	b _0807F7AC
_0807F7A2:
	adds r1, #0x3c
	adds r2, #1
	cmp r2, #0xf
	ble _0807F7AC
	b _0807F8B8
_0807F7AC:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0807F7A2
	cmp r2, #0xf
	ble _0807F7B8
	b _0807F8B8
_0807F7B8:
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r0, #0xf8
	mov r1, ip
	adds r7, r1, r0
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r7, #0x18]
	str r1, [r7, #0x1c]
	ldr r6, _0807F840 @ =0x0203B400
	ldr r5, _0807F844 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r3, _0807F848 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	ldrh r0, [r7, #0x18]
	subs r0, #0x3f
	movs r4, #0x7f
	ands r2, r4
	adds r0, r0, r2
	strh r0, [r7, #0x18]
	adds r1, #1
	ands r1, r3
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	ldrh r0, [r7, #0x1c]
	subs r0, #0x3f
	ands r1, r4
	adds r0, r0, r1
	strh r0, [r7, #0x1c]
	ldrh r0, [r7, #0x1a]
	adds r0, #0x80
	strh r0, [r7, #0x1a]
	mov r0, ip
	adds r0, #0xf4
	ldr r1, [r0]
	adds r0, r7, #0
	movs r2, #4
	bl FUN_0822dafc
	ldr r2, _0807F84C @ =0x085B0A08
	mov r0, r8
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _0807F850
	asrs r0, r0, #0xc
	b _0807F856
	.align 2, 0
_0807F840: .4byte 0x0203B400
_0807F844: .4byte 0x030046B8
_0807F848: .4byte 0x000003FF
_0807F84C: .4byte 0x085B0A08
_0807F850:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0807F856:
	strh r0, [r7, #0x34]
	ldr r1, _0807F878 @ =0x085B0A08
	movs r0, #0xff
	mov r2, r8
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _0807F87C
	asrs r0, r0, #0xc
	b _0807F882
	.align 2, 0
_0807F878: .4byte 0x085B0A08
_0807F87C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0807F882:
	movs r1, #0
	strh r0, [r7, #0x38]
	adds r0, r7, #0
	adds r0, #0x2c
	strb r1, [r0]
	adds r0, #3
	movs r3, #1
	strb r3, [r0]
	ldr r2, _0807F8C4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0807F8C8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0807F8CC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #8
	adds r1, r7, #0
	adds r1, #0x2e
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x28
	strb r3, [r0]
_0807F8B8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807F8C4: .4byte 0x030046B8
_0807F8C8: .4byte 0x000003FF
_0807F8CC: .4byte 0x0203B400

	thumb_func_start FUN_0807f8d0
FUN_0807f8d0: @ 0x0807F8D0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0xf8
	movs r0, #0x90
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r0, #0
	mov r8, r0
	movs r7, #0xf
_0807F8E8:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0807F926
	ldrb r0, [r4, #6]
	subs r0, #1
	strb r0, [r4, #6]
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _0807F90E
	adds r0, r5, #0
	adds r0, #0xf8
	add r0, r8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	strb r3, [r4]
	b _0807F926
_0807F90E:
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _0807F91E
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_0807f650
	b _0807F926
_0807F91E:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_0807f750
_0807F926:
	adds r6, #0x3c
	adds r4, #0x3c
	movs r0, #0x3c
	add r8, r0
	subs r7, #1
	cmp r7, #0
	bge _0807F8E8
	movs r0, #0x97
	lsls r0, r0, #3
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807F94C:
	.byte 0xF0, 0xB5, 0x04, 0x1C
	.byte 0x25, 0x1C, 0xEE, 0x35, 0x28, 0x88, 0x00, 0x28, 0x0B, 0xD1, 0x04, 0x22, 0x1A, 0x49, 0x08, 0x68
	.byte 0x10, 0x43, 0x08, 0x60, 0x19, 0x48, 0xC0, 0xF1, 0xBB, 0xFE, 0xFD, 0x20, 0x40, 0x00, 0xC0, 0xF1
	.byte 0xB7, 0xFE, 0x17, 0x48, 0x02, 0x68, 0x11, 0x1C, 0x90, 0x31, 0x08, 0x68, 0x01, 0x26, 0x30, 0x43
	.byte 0x08, 0x60, 0x23, 0x1C, 0x5E, 0x33, 0x00, 0x20, 0x19, 0x5E, 0x08, 0x01, 0x40, 0x1A, 0x2E, 0x27
	.byte 0xD1, 0x5F, 0x40, 0x18, 0x96, 0x30, 0x00, 0x11, 0x18, 0x80, 0x20, 0x1C, 0x3C, 0x30, 0x21, 0x1C
	.byte 0x1C, 0x31, 0xB7, 0xF1, 0x93, 0xFC, 0x28, 0x88, 0x01, 0x30, 0x28, 0x80, 0x00, 0x04, 0x00, 0x0C
	.byte 0x3B, 0x28, 0x06, 0xD9, 0x20, 0x1C, 0x56, 0x30, 0x06, 0x70, 0x06, 0x49, 0x20, 0x1C, 0xFF, 0xF7
	.byte 0x3F, 0xFE, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0xBC, 0x44, 0x00, 0x03, 0x02, 0x03, 0x00, 0x00
	.byte 0xE0, 0x2B, 0x00, 0x03, 0xD9, 0xF9, 0x07, 0x08

	thumb_func_start FUN_0807f9d8
FUN_0807f9d8: @ 0x0807F9D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xee
	ldrh r0, [r5]
	cmp r0, #0
	bne _0807F9FC
	ldr r0, _0807FA68 @ =0x00000303
	bl PlaySound_082406e0
	ldr r0, _0807FA6C @ =0x000001FB
	bl PlaySound_082406e0
_0807F9FC:
	ldr r0, _0807FA70 @ =0x03002BE0
	mov sl, r0
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #0x90
	ldr r1, [r2]
	movs r3, #1
	mov r8, r3
	orrs r1, r3
	str r1, [r2]
	ldr r1, _0807FA74 @ =0x0000060C
	adds r0, r0, r1
	bl FUN_080136b4
	ldrh r1, [r5]
	adds r3, r1, #0
	cmp r3, #7
	bhi _0807FA7C
	adds r7, r4, #0
	adds r7, #0x3c
	adds r6, r4, #0
	adds r6, #0x1c
	cmp r3, #0
	bne _0807FA42
	ldr r0, [r4, #0x44]
	movs r1, #4
	orrs r0, r1
	str r0, [r4, #0x44]
	ldr r2, _0807FA78 @ =0x0000018F
	str r3, [sp]
	adds r0, r7, #0
	adds r1, r6, #0
	movs r3, #1
	bl FUN_082370cc
_0807FA42:
	ldr r1, [r4, #0x18]
	ldrh r0, [r5]
	lsls r0, r0, #7
	ldrh r2, [r1, #0x2c]
	subs r2, r2, r0
	adds r1, r4, #0
	adds r1, #0x5c
	strh r2, [r1]
	ldr r0, [r4, #0x18]
	ldrh r2, [r0, #0x30]
	adds r0, r4, #0
	adds r0, #0x60
	strh r2, [r0]
	adds r0, r4, #0
	movs r2, #0x80
	bl FUN_0807f78c
	b _0807FCA6
	.align 2, 0
_0807FA68: .4byte 0x00000303
_0807FA6C: .4byte 0x000001FB
_0807FA70: .4byte 0x03002BE0
_0807FA74: .4byte 0x0000060C
_0807FA78: .4byte 0x0000018F
_0807FA7C:
	cmp r3, #0x17
	bhi _0807FAE0
	adds r7, r4, #0
	adds r7, #0x3c
	adds r6, r4, #0
	adds r6, #0x1c
	cmp r3, #8
	bne _0807FAA6
	ldr r0, [r4, #0x44]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x44]
	ldr r2, _0807FAD4 @ =0x0000018F
	mov r3, r8
	str r3, [sp]
	adds r0, r7, #0
	adds r1, r6, #0
	movs r3, #1
	bl FUN_082370cc
_0807FAA6:
	ldr r2, _0807FAD8 @ =0x03003540
	ldrh r0, [r5]
	lsls r0, r0, #5
	ldr r1, _0807FADC @ =0xFFFFFD00
	adds r0, r0, r1
	ldrh r3, [r2]
	adds r0, r0, r3
	adds r1, r4, #0
	adds r1, #0x5c
	strh r0, [r1]
	ldrh r0, [r5]
	subs r0, #0x10
	lsls r0, r0, #7
	ldrh r2, [r2, #4]
	subs r2, r2, r0
	adds r0, r4, #0
	adds r0, #0x60
	strh r2, [r0]
	adds r0, r4, #0
	movs r2, #0x48
	bl FUN_0807f78c
	b _0807FCA6
	.align 2, 0
_0807FAD4: .4byte 0x0000018F
_0807FAD8: .4byte 0x03003540
_0807FADC: .4byte 0xFFFFFD00
_0807FAE0:
	cmp r3, #0x27
	bhi _0807FB40
	adds r7, r4, #0
	adds r7, #0x3c
	adds r6, r4, #0
	adds r6, #0x1c
	cmp r3, #0x18
	bne _0807FB0A
	ldr r0, [r4, #0x44]
	movs r1, #4
	orrs r0, r1
	str r0, [r4, #0x44]
	movs r2, #0xc8
	lsls r2, r2, #1
	mov r0, r8
	str r0, [sp]
	adds r0, r7, #0
	adds r1, r6, #0
	movs r3, #1
	bl FUN_082370cc
_0807FB0A:
	ldr r3, _0807FB38 @ =0x03003540
	ldrh r0, [r5]
	lsls r0, r0, #5
	ldr r1, _0807FB3C @ =0xFFFFFB00
	adds r0, r0, r1
	ldrh r2, [r3]
	subs r2, r2, r0
	adds r1, r4, #0
	adds r1, #0x5c
	strh r2, [r1]
	ldrh r0, [r5]
	subs r0, #0x20
	lsls r0, r0, #7
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	adds r2, r4, #0
	adds r2, #0x60
	strh r0, [r2]
	adds r0, r4, #0
	movs r2, #0xc8
	bl FUN_0807f78c
	b _0807FCA6
	.align 2, 0
_0807FB38: .4byte 0x03003540
_0807FB3C: .4byte 0xFFFFFB00
_0807FB40:
	cmp r3, #0x37
	bhi _0807FBA4
	adds r7, r4, #0
	adds r7, #0x3c
	adds r6, r4, #0
	adds r6, #0x1c
	cmp r3, #0x28
	bne _0807FB68
	ldr r0, [r4, #0x44]
	movs r1, #4
	orrs r0, r1
	str r0, [r4, #0x44]
	ldr r2, _0807FB98 @ =0x0000018F
	mov r3, r8
	str r3, [sp]
	adds r0, r7, #0
	adds r1, r6, #0
	movs r3, #1
	bl FUN_082370cc
_0807FB68:
	ldr r3, _0807FB9C @ =0x03003540
	ldrh r0, [r5]
	subs r0, #0x30
	lsls r0, r0, #7
	ldrh r2, [r3]
	subs r2, r2, r0
	adds r1, r4, #0
	adds r1, #0x5c
	strh r2, [r1]
	ldrh r0, [r5]
	lsls r0, r0, #5
	ldr r5, _0807FBA0 @ =0xFFFFFB00
	adds r0, r0, r5
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	adds r2, r4, #0
	adds r2, #0x60
	strh r0, [r2]
	adds r0, r4, #0
	movs r2, #9
	bl FUN_0807f78c
	b _0807FCA6
	.align 2, 0
_0807FB98: .4byte 0x0000018F
_0807FB9C: .4byte 0x03003540
_0807FBA0: .4byte 0xFFFFFB00
_0807FBA4:
	cmp r3, #0x47
	bhi _0807FC08
	adds r7, r4, #0
	adds r7, #0x3c
	adds r6, r4, #0
	adds r6, #0x1c
	cmp r3, #0x38
	bne _0807FBD0
	ldr r0, [r4, #0x44]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x44]
	movs r2, #0xc8
	lsls r2, r2, #1
	mov r0, r8
	str r0, [sp]
	adds r0, r7, #0
	adds r1, r6, #0
	movs r3, #1
	bl FUN_082370cc
_0807FBD0:
	ldr r2, _0807FC00 @ =0x03003540
	ldrh r0, [r5]
	subs r0, #0x40
	lsls r0, r0, #7
	ldrh r1, [r2]
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x5c
	strh r0, [r1]
	ldrh r0, [r5]
	lsls r0, r0, #5
	ldr r3, _0807FC04 @ =0xFFFFF700
	adds r0, r0, r3
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	adds r2, r4, #0
	adds r2, #0x60
	strh r0, [r2]
	adds r0, r4, #0
	movs r2, #0x89
	bl FUN_0807f78c
	b _0807FCA6
	.align 2, 0
_0807FC00: .4byte 0x03003540
_0807FC04: .4byte 0xFFFFF700
_0807FC08:
	movs r0, #3
	ands r0, r1
	movs r1, #0x5c
	adds r1, r1, r4
	mov sb, r1
	cmp r0, #0
	bne _0807FC1E
	adds r0, r4, #0
	movs r2, #0xc0
	bl FUN_0807f78c
_0807FC1E:
	ldrh r0, [r5]
	adds r7, r4, #0
	adds r7, #0x3c
	adds r6, r4, #0
	adds r6, #0x1c
	cmp r0, #0x48
	bne _0807FC46
	ldr r0, [r4, #0x44]
	movs r1, #4
	orrs r0, r1
	str r0, [r4, #0x44]
	movs r2, #0xc8
	lsls r2, r2, #1
	mov r3, r8
	str r3, [sp]
	adds r0, r7, #0
	adds r1, r6, #0
	movs r3, #1
	bl FUN_082370cc
_0807FC46:
	ldrh r0, [r5]
	cmp r0, #0x60
	bne _0807FC66
	ldr r0, [r4, #0x44]
	movs r1, #4
	orrs r0, r1
	str r0, [r4, #0x44]
	movs r2, #0xc9
	lsls r2, r2, #1
	movs r0, #0
	str r0, [sp]
	adds r0, r7, #0
	adds r1, r6, #0
	movs r3, #1
	bl FUN_082370cc
_0807FC66:
	ldr r0, [r4, #0x18]
	ldrh r0, [r0, #0x2c]
	mov r1, sb
	strh r0, [r1]
	ldr r2, [r4, #0x18]
	ldrh r1, [r5]
	movs r0, #0x68
	subs r0, r0, r1
	lsls r0, r0, #5
	ldrh r1, [r2, #0x30]
	subs r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x60
	strh r1, [r0]
	adds r2, r4, #0
	adds r2, #0x5e
	mov r3, sl
	ldr r0, [r3]
	ldrh r5, [r2]
	mov r8, r5
	movs r3, #0
	ldrsh r1, [r2, r3]
	ldrh r3, [r0, #0x2e]
	movs r5, #0x2e
	ldrsh r0, [r0, r5]
	cmp r1, r0
	ble _0807FCA4
	mov r0, r8
	subs r0, #0xa
	strh r0, [r2]
	b _0807FCA6
_0807FCA4:
	strh r3, [r2]
_0807FCA6:
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_082372cc
	ldr r0, [r4, #0x18]
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r2, r0, r1
	adds r0, r4, #0
	adds r0, #0xf2
	ldrh r1, [r2]
	adds r3, r0, #0
	ldrh r5, [r3]
	cmp r1, r5
	bls _0807FCDA
	adds r0, r1, #0
	adds r1, r4, #0
	adds r1, #0xf0
	ldrh r1, [r1]
	subs r0, r0, r1
	ldrh r1, [r3]
	cmp r0, r1
	bge _0807FCD8
	strh r1, [r2]
	b _0807FCDA
_0807FCD8:
	strh r0, [r2]
_0807FCDA:
	adds r1, r4, #0
	adds r1, #0xee
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x68
	bls _0807FD06
	subs r1, #0x98
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r4, #0x18]
	ldrh r1, [r3]
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r0, r0, r2
	strh r1, [r0]
	ldr r1, _0807FD18 @ =FUN_0807fd1c
	adds r0, r4, #0
	bl FUN_0807f640
_0807FD06:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807FD18: .4byte FUN_0807fd1c

	thumb_func_start FUN_0807fd1c
FUN_0807fd1c: @ 0x0807FD1C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xee
	ldrh r0, [r4]
	cmp r0, #0
	bne _0807FD38
	movs r0, #0xd8
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_0807FD38:
	ldr r4, _0807FD98 @ =0x03002BE0
	ldr r0, [r4]
	adds r2, r0, #0
	adds r2, #0x90
	ldr r1, [r2]
	movs r6, #1
	orrs r1, r6
	str r1, [r2]
	ldr r1, _0807FD9C @ =0x0000060C
	adds r0, r0, r1
	bl FUN_08013698
	adds r0, r5, #0
	adds r0, #0x3c
	adds r1, r5, #0
	adds r1, #0x1c
	bl FUN_082372cc
	cmp r0, #0
	beq _0807FD92
	ldr r0, [r4]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r4]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #5
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _0807FDA0 @ =0x000002E6
	adds r0, r0, r1
	movs r1, #3
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _0807FDA4 @ =0x000002E7
	adds r0, r0, r1
	strb r6, [r0]
	ldr r1, _0807FDA8 @ =FUN_0807fdac
	adds r0, r5, #0
	bl FUN_0807f640
_0807FD92:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807FD98: .4byte 0x03002BE0
_0807FD9C: .4byte 0x0000060C
_0807FDA0: .4byte 0x000002E6
_0807FDA4: .4byte 0x000002E7
_0807FDA8: .4byte FUN_0807fdac

	thumb_func_start FUN_0807fdac
FUN_0807fdac: @ 0x0807FDAC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x44]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x44]
	adds r3, r4, #0
	adds r3, #0xee
	ldrh r0, [r3]
	cmp r0, #0
	bne _0807FDD6
	ldr r2, _0807FDF0 @ =0x030044BC
	subs r1, #6
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _0807FDF4 @ =0x030047A4
	ldr r0, [r2]
	adds r1, #3
	ands r0, r1
	str r0, [r2]
_0807FDD6:
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _0807FDF8
	adds r0, r4, #0
	adds r0, #0x9c
	bl FUN_08236400
	b _0807FDFE
	.align 2, 0
_0807FDF0: .4byte 0x030044BC
_0807FDF4: .4byte 0x030047A4
_0807FDF8:
	adds r0, r4, #0
	bl KillEntity
_0807FDFE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0807fe04
FUN_0807fe04: @ 0x0807FE04
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0807f8d0
	movs r1, #0x98
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0807FE24:
	.byte 0x30, 0xB5, 0x04, 0x1C, 0x3C, 0x30, 0xAF, 0xF1, 0xC9, 0xF9, 0xF8, 0x34
	.byte 0x0F, 0x25, 0x20, 0x1C, 0xAD, 0xF1, 0x42, 0xFE, 0x3C, 0x34, 0x01, 0x3D, 0x00, 0x2D, 0xF8, 0xDA
	.byte 0x00, 0x20, 0x30, 0xBC, 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_0807fe48
FUN_0807fe48: @ 0x0807FE48
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _0807FEC8 @ =0x0000CB05
	ldr r1, _0807FECC @ =0x0000DE23
	bl FUN_082310cc
	adds r2, r0, #0
	cmp r2, #0
	beq _0807FEBE
	adds r1, r7, #0
	adds r1, #0x1c
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r7, #0
	adds r4, #0x1c
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822f284
	adds r6, r7, #0
	adds r6, #0x3c
	movs r3, #0x90
	lsls r3, r3, #8
	movs r0, #2
	str r0, [sp]
	movs r5, #0
	str r5, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	ldr r0, [r7, #0x18]
	adds r0, #0x2c
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822f3fc
	movs r2, #0xc7
	lsls r2, r2, #1
	str r5, [sp]
	adds r0, r6, #0
	adds r1, r4, #0
	movs r3, #1
	bl FUN_082370cc
	adds r1, r7, #0
	adds r1, #0x76
	movs r0, #0x26
	strh r0, [r1]
	adds r1, #0xe
	ldr r0, [r7, #0x18]
	adds r0, #0xd0
	ldr r0, [r0]
	str r0, [r1]
_0807FEBE:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807FEC8: .4byte 0x0000CB05
_0807FECC: .4byte 0x0000DE23

	thumb_func_start FUN_0807fed0
FUN_0807fed0: @ 0x0807FED0
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x9c
	ldr r2, _0807FF60 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	ldr r3, _0807FF64 @ =0x00007530
	orrs r0, r3
	ldr r1, _0807FF68 @ =0x0000FFFF
	ands r0, r1
	ldr r1, _0807FF6C @ =0x75300000
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldr r2, _0807FF70 @ =0x00003001
	ldr r1, [r4, #0x18]
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
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r0, [r4, #0x18]
	ldr r1, _0807FF74 @ =0x00000366
	adds r0, r0, r1
	ldrh r1, [r0]
	lsrs r1, r1, #1
	movs r0, #0x80
	lsls r0, r0, #0xb
	str r0, [sp]
	movs r0, #0x32
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r2, #0x32
	movs r3, #0
	bl FUN_082364f8
	adds r0, r5, #0
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823651c
	ldr r1, [r4, #0x18]
	adds r1, #0x2c
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807FF60: .4byte 0xFFFF0000
_0807FF64: .4byte 0x00007530
_0807FF68: .4byte 0x0000FFFF
_0807FF6C: .4byte 0x75300000
_0807FF70: .4byte 0x00003001
_0807FF74: .4byte 0x00000366

	thumb_func_start FUN_0807ff78
FUN_0807ff78: @ 0x0807FF78
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r6, _08080064 @ =0x0203B400
	ldr r4, _08080068 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _0808006C @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrb r0, [r0]
	str r0, [sp, #4]
	ldr r0, _08080070 @ =0x00001C1E
	bl FUN_0822b10c
	adds r1, r7, #0
	adds r1, #0xf4
	str r0, [r1]
	movs r0, #0
	str r0, [sp]
	mov sb, r1
	mov sl, r6
	mov r8, r4
	adds r6, r5, #0
	movs r1, #0
	str r1, [sp, #8]
	movs r2, #0x84
	lsls r2, r2, #1
	adds r4, r7, r2
	adds r5, r7, #0
	adds r5, #0xf8
_0807FFC2:
	mov r3, sb
	ldr r1, [r3]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	mov r0, r8
	ldr r2, [r0]
	adds r2, #1
	ands r2, r6
	lsls r0, r2, #1
	add r0, sl
	ldrh r1, [r0]
	ldr r3, [sp, #4]
	ldr r0, [sp, #8]
	adds r3, r3, r0
	movs r0, #7
	ands r1, r0
	adds r3, r3, r1
	strb r3, [r4, #0x19]
	adds r2, #1
	ands r2, r6
	lsls r0, r2, #1
	add r0, sl
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #7
	strb r0, [r4, #0x1d]
	adds r2, #1
	ands r2, r6
	lsls r0, r2, #1
	add r0, sl
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x5f
	ands r0, r1
	adds r0, #0x60
	strh r0, [r4, #0x20]
	ldr r0, [sp]
	movs r3, #3
	ands r0, r3
	lsls r0, r0, #1
	adds r0, #1
	strb r0, [r4, #0x1a]
	adds r2, #1
	ands r2, r6
	mov r0, r8
	str r2, [r0]
	lsls r2, r2, #1
	add r2, sl
	ldrh r0, [r2]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #8
	strb r0, [r4, #0x1b]
	ldrh r2, [r4, #0x20]
	ldrb r0, [r4, #0x19]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r1, _08080074 @ =0x085B0A08
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _08080078
	asrs r2, r0, #0xc
	b _0808007E
	.align 2, 0
_08080064: .4byte 0x0203B400
_08080068: .4byte 0x030046B8
_0808006C: .4byte 0x000003FF
_08080070: .4byte 0x00001C1E
_08080074: .4byte 0x085B0A08
_08080078:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0808007E:
	ldr r0, [r7, #0x18]
	ldrh r0, [r0, #0x2c]
	adds r0, r0, r2
	strh r0, [r4, #8]
	ldr r0, [r7, #0x18]
	ldrh r0, [r0, #0x2e]
	strh r0, [r4, #0xa]
	ldrh r1, [r4, #0x20]
	ldrb r0, [r4, #0x19]
	lsls r0, r0, #1
	ldr r2, _080800A4 @ =0x085B0A08
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080800A8
	asrs r1, r0, #0xc
	b _080800AE
	.align 2, 0
_080800A4: .4byte 0x085B0A08
_080800A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080800AE:
	ldr r0, [r7, #0x18]
	ldrh r0, [r0, #0x30]
	adds r0, r0, r1
	strh r0, [r4, #0xc]
	movs r0, #2
	strb r0, [r5, #0xf]
	movs r0, #0xec
	strb r0, [r4]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _080800E8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	strb r1, [r4, #0x1c]
	cmp r1, #3
	bhi _080800EC
	mov r3, sb
	ldr r1, [r3]
	adds r0, r5, #0
	movs r2, #4
	bl FUN_0822dafc
	b _080800F8
	.align 2, 0
_080800E8: .4byte 0x0203B400
_080800EC:
	mov r0, sb
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #5
	bl FUN_0822dafc
_080800F8:
	movs r0, #0
	strb r0, [r4, #0x1c]
	strb r0, [r4, #0x1f]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _08080144 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x38
	strb r0, [r4, #0x1e]
	movs r0, #1
	strb r0, [r4, #0x18]
	ldr r3, [sp, #8]
	adds r3, #0x10
	str r3, [sp, #8]
	adds r4, #0x3c
	adds r5, #0x3c
	ldr r0, [sp]
	adds r0, #1
	str r0, [sp]
	cmp r0, #0xf
	bgt _08080132
	b _0807FFC2
_08080132:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080144: .4byte 0x0203B400

	thumb_func_start FUN_08080148
FUN_08080148: @ 0x08080148
	push {r4, lr}
	adds r4, r0, #0
	str r1, [r4, #0x18]
	bl FUN_0807fe48
	adds r0, r4, #0
	bl FUN_0807fed0
	adds r0, r4, #0
	bl FUN_0807ff78
	ldr r1, _080801A8 @ =0x0807F94D
	adds r0, r4, #0
	bl FUN_0807f640
	ldr r1, _080801AC @ =0x030047A4
	ldr r0, [r1]
	movs r3, #1
	orrs r0, r3
	str r0, [r1]
	ldr r0, [r4, #0x18]
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	lsrs r0, r0, #1
	adds r1, r4, #0
	adds r1, #0xf2
	strh r0, [r1]
	cmp r0, #0
	bne _08080188
	strh r3, [r1]
_08080188:
	ldr r0, [r4, #0x18]
	adds r0, r0, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r1, #0x48
	bl Div
	adds r0, #1
	adds r1, r4, #0
	adds r1, #0xf0
	strh r0, [r1]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080801A8: .4byte 0x0807F94D
_080801AC: .4byte 0x030047A4

	thumb_func_start FUN_080801b0
FUN_080801b0: @ 0x080801B0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _080801E0 @ =0x000004C4
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080801EC
	ldr r1, _080801E4 @ =FUN_0807fe04
	ldr r2, _080801E8 @ =0x0807FE25
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08080148
	cmp r0, #0
	bge _080801EC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080801EE
	.align 2, 0
_080801E0: .4byte 0x000004C4
_080801E4: .4byte FUN_0807fe04
_080801E8: .4byte 0x0807FE25
_080801EC:
	adds r0, r4, #0
_080801EE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080801f4
FUN_080801f4: @ 0x080801F4
	movs r3, #0xca
	lsls r3, r3, #1
	adds r2, r0, r3
	str r1, [r2]
	adds r0, #0xca
	movs r1, #0
	strh r1, [r0]
	bx lr

	thumb_func_start FUN_08080204
FUN_08080204: @ 0x08080204
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r0
	ldr r3, [r0, #0x18]
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	mov r2, ip
	str r0, [r2, #0x38]
	str r1, [r2, #0x3c]
	mov r0, ip
	adds r0, #0xbc
	ldrh r0, [r0]
	ldrh r4, [r2, #0x3a]
	adds r0, r0, r4
	strh r0, [r2, #0x3a]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r7, r0, #5
	ldr r1, _08080270 @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	movs r2, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r6, [r0, r4]
	adds r0, r7, #0
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r5, [r0, r2]
	ldr r4, _08080274 @ =0x000002E7
	adds r3, r3, r4
	ldrb r0, [r3]
	mov r8, r1
	cmp r0, #0
	beq _080802D8
	mov r1, ip
	adds r1, #0xbe
	ldrh r0, [r1]
	muls r0, r6, r0
	adds r3, r1, #0
	cmp r0, #0
	blt _08080278
	asrs r0, r0, #0xc
	b _0808027E
	.align 2, 0
_08080270: .4byte 0x085B0A08
_08080274: .4byte 0x000002E7
_08080278:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808027E:
	adds r4, r0, #0
	mov r1, ip
	adds r1, #0xc0
	ldrh r0, [r1]
	muls r0, r5, r0
	adds r2, r1, #0
	cmp r0, #0
	blt _08080292
	asrs r0, r0, #0xc
	b _08080298
_08080292:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08080298:
	adds r0, r4, r0
	mov r1, ip
	ldrh r1, [r1, #0x38]
	adds r0, r0, r1
	mov r4, ip
	strh r0, [r4, #0x38]
	ldrh r0, [r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _080802B0
	asrs r0, r0, #0xc
	b _080802B6
_080802B0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080802B6:
	adds r1, r0, #0
	ldrh r0, [r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _080802C4
	asrs r0, r0, #0xc
	b _080802CA
_080802C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080802CA:
	subs r0, r1, r0
	mov r1, ip
	ldrh r1, [r1, #0x3c]
	adds r0, r0, r1
	mov r2, ip
	strh r0, [r2, #0x3c]
	b _08080348
_080802D8:
	mov r1, ip
	adds r1, #0xbe
	ldrh r0, [r1]
	muls r0, r6, r0
	adds r3, r1, #0
	cmp r0, #0
	blt _080802EA
	asrs r0, r0, #0xc
	b _080802F0
_080802EA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080802F0:
	adds r4, r0, #0
	mov r1, ip
	adds r1, #0xc0
	ldrh r0, [r1]
	muls r0, r5, r0
	adds r2, r1, #0
	cmp r0, #0
	blt _08080304
	asrs r0, r0, #0xc
	b _0808030A
_08080304:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808030A:
	subs r0, r4, r0
	mov r4, ip
	ldrh r4, [r4, #0x38]
	adds r0, r0, r4
	mov r1, ip
	strh r0, [r1, #0x38]
	ldrh r0, [r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _08080322
	asrs r0, r0, #0xc
	b _08080328
_08080322:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08080328:
	adds r1, r0, #0
	ldrh r0, [r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08080336
	asrs r0, r0, #0xc
	b _0808033C
_08080336:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808033C:
	adds r0, r1, r0
	mov r2, ip
	ldrh r2, [r2, #0x3c]
	adds r0, r0, r2
	mov r4, ip
	strh r0, [r4, #0x3c]
_08080348:
	movs r2, #0xff
	lsrs r0, r7, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	mov r0, ip
	adds r0, #0xc8
	strb r1, [r0]
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r2, [r0, r1]
	mov r1, ip
	adds r1, #0xc2
	ldrh r0, [r1]
	muls r0, r2, r0
	adds r3, r1, #0
	cmp r0, #0
	blt _08080378
	asrs r2, r0, #0xc
	b _0808037E
_08080378:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0808037E:
	mov r0, ip
	adds r0, #0xb4
	strh r2, [r0]
	lsls r0, r7, #1
	add r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrh r0, [r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _08080398
	asrs r1, r0, #0xc
	b _0808039E
_08080398:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808039E:
	mov r0, ip
	adds r0, #0xb8
	strh r1, [r0]
	subs r0, #0x12
	strb r7, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080803b4
FUN_080803b4: @ 0x080803B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	mov sl, r0
	movs r0, #0xff
	mov r8, r0
	ldr r1, _08080410 @ =0x085B0A08
	mov sb, r1
	mov ip, r5
	movs r7, #0
	mov r3, ip
	adds r3, #0xec
	movs r6, #3
_080803E0:
	ldrb r0, [r3, #0x10]
	cmp r0, #0
	beq _08080482
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	adds r0, #1
	movs r2, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _08080414
	strb r2, [r3, #0x10]
	adds r0, r5, #0
	adds r0, #0xd4
	adds r0, r0, r7
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _08080482
	.align 2, 0
_08080410: .4byte 0x085B0A08
_08080414:
	ldrh r2, [r3, #0x12]
	ldrh r1, [r1]
	movs r0, #0x10
	subs r0, r0, r1
	muls r0, r2, r0
	asrs r4, r0, #3
	movs r0, #0x11
	ldrsb r0, [r3, r0]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	mov r1, sl
	adds r2, r1, r0
	mov r0, r8
	ands r2, r0
	ldr r0, [r5, #0x38]
	ldr r1, [r5, #0x3c]
	str r0, [r3]
	str r1, [r3, #4]
	adds r0, r2, #0
	adds r0, #0x40
	mov r1, r8
	ands r0, r1
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08080454
	asrs r1, r0, #0xc
	b _0808045A
_08080454:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808045A:
	ldrh r0, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	mov r0, r8
	ands r2, r0
	lsls r0, r2, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08080476
	asrs r1, r0, #0xc
	b _0808047C
_08080476:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808047C:
	ldrh r0, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
_08080482:
	movs r0, #0x30
	add ip, r0
	adds r7, #0x30
	adds r3, #0x30
	subs r6, #1
	cmp r6, #0
	bge _080803E0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080804a0
FUN_080804a0: @ 0x080804A0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0xcc
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xfc
	movs r3, #0
	movs r1, #1
	strb r1, [r0]
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r1, r7, #0
	adds r1, #0xd4
	adds r1, r1, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	movs r1, #0x80
	lsls r1, r1, #1
	mov sb, r1
	add r0, sb
	strh r3, [r0]
	ldr r0, _08080594 @ =0x0203B400
	mov r8, r0
	ldr r6, _08080598 @ =0x030046B8
	ldr r1, [r6]
	adds r1, #1
	ldr r5, _0808059C @ =0x000003FF
	ands r1, r5
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	ldrb r3, [r4]
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #4
	adds r0, r7, r0
	asrs r2, r2, #3
	movs r3, #0x7f
	ands r2, r3
	adds r2, #0x40
	adds r0, #0xfe
	strh r2, [r0]
	adds r1, #1
	ands r1, r5
	str r1, [r6]
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	movs r1, #0x60
	bl Mod
	ldrb r2, [r4]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #4
	adds r1, r7, r1
	subs r0, #0x30
	adds r1, #0xfd
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldrb r0, [r4]
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #4
	adds r2, r7, r2
	adds r0, r2, #0
	adds r0, #0xfd
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	add r0, sb
	adds r5, r5, r0
	movs r3, #0xff
	ands r5, r3
	adds r2, #0xec
	ldr r0, [r7, #0x38]
	ldr r1, [r7, #0x3c]
	str r0, [r2]
	str r1, [r2, #4]
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xfe
	ldrh r2, [r0]
	ldr r1, _080805A0 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080805A4
	asrs r2, r0, #0xc
	b _080805AA
	.align 2, 0
_08080594: .4byte 0x0203B400
_08080598: .4byte 0x030046B8
_0808059C: .4byte 0x000003FF
_080805A0: .4byte 0x085B0A08
_080805A4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080805AA:
	adds r3, r7, #0
	adds r3, #0xcc
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xec
	ldrh r1, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xfe
	ldrh r2, [r0]
	ldr r1, _080805E4 @ =0x085B0A08
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080805E8
	asrs r2, r0, #0xc
	b _080805EE
	.align 2, 0
_080805E4: .4byte 0x085B0A08
_080805E8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080805EE:
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xf0
	ldrh r1, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _08080612
	movs r0, #0
	strb r0, [r3]
_08080612:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08080620
FUN_08080620: @ 0x08080620
	push {r4, r5, lr}
	movs r5, #0
	movs r4, #1
	adds r1, r0, #0
	adds r1, #0xd4
	adds r2, r0, #0
	adds r2, #0xfc
	movs r3, #3
_08080630:
	strb r5, [r2]
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x30
	adds r2, #0x30
	subs r3, #1
	cmp r3, #0
	bge _08080630
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08080648
FUN_08080648: @ 0x08080648
	push {lr}
	adds r0, r2, #0
	ldr r1, _08080658 @ =FUN_0808094c
	bl FUN_080801f4
	pop {r0}
	bx r0
	.align 2, 0
_08080658: .4byte FUN_0808094c

	thumb_func_start FUN_0808065c
FUN_0808065c: @ 0x0808065C
	push {r4, lr}
	adds r2, r0, #0
	ldr r0, _0808069C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08080688
	adds r0, r2, #0
	adds r0, #0xc4
	ldrh r3, [r0]
	ldr r0, _080806A0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _08080688
	movs r4, #0xa0
	lsls r4, r4, #1
	adds r1, r0, r4
	ldr r0, [r1]
	adds r0, r0, r3
	str r0, [r1]
_08080688:
	ldr r0, [r2, #0x18]
	adds r1, r2, #0
	adds r1, #0xc4
	ldrh r1, [r1]
	bl FUN_0807aa60
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808069C: .4byte 0x030047A4
_080806A0: .4byte 0x03002C68

	thumb_func_start FUN_080806a4
FUN_080806a4: @ 0x080806A4
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xcd
	ldrb r0, [r0]
	cmp r0, #0
	beq _080806B4
	movs r0, #8
	b _080806E4
_080806B4:
	ldr r0, _080806CC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080806D0
	ldr r0, [r4, #0x18]
	bl FUN_080d1b04
	b _080806D6
	.align 2, 0
_080806CC: .4byte 0x030047A4
_080806D0:
	ldr r0, [r4, #0x18]
	bl FUN_0806f900
_080806D6:
	adds r1, r0, #0
	adds r0, r4, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	muls r0, r1, r0
	asrs r0, r0, #1
	adds r0, r1, r0
_080806E4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080806ec
FUN_080806ec: @ 0x080806EC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x18]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r5, [r0]
	cmp r5, #3
	beq _08080706
	adds r0, r4, #0
	bl KillEntity
	b _080807EE
_08080706:
	adds r0, r4, #0
	bl FUN_08080204
	ldr r0, [r4, #0x18]
	ldr r1, _0808074C @ =0x0000037D
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08080754
	adds r0, r4, #0
	bl FUN_08080620
	ldr r0, [r4, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl FUN_080806a4
	adds r1, r4, #0
	adds r1, #0x64
	strh r0, [r1, #0x3c]
	adds r0, r4, #0
	bl FUN_0808065c
	ldr r1, _08080750 @ =FUN_080808cc
	adds r0, r4, #0
	bl FUN_080801f4
	b _080807EE
	.align 2, 0
_0808074C: .4byte 0x0000037D
_08080750: .4byte FUN_080808cc
_08080754:
	adds r0, r4, #0
	bl FUN_080803b4
	ldr r0, [r4, #0x18]
	ldr r1, _0808077C @ =0x0000037D
	adds r0, r0, r1
	ldrb r2, [r0]
	cmp r2, #2
	bne _08080780
	adds r1, r4, #0
	adds r1, #0xca
	ldrh r0, [r1]
	ands r5, r0
	adds r6, r4, #0
	adds r6, #0xc9
	adds r7, r1, #0
	cmp r5, #3
	bne _080807C2
	b _080807A0
	.align 2, 0
_0808077C: .4byte 0x0000037D
_08080780:
	cmp r2, #3
	bne _080807A8
	ldr r0, [r4, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0xca
	ldrh r0, [r1]
	ands r2, r0
	adds r6, r4, #0
	adds r6, #0xc9
	adds r7, r1, #0
	cmp r2, #3
	bne _080807C2
_080807A0:
	adds r0, r4, #0
	bl FUN_080804a0
	b _080807C2
_080807A8:
	adds r1, r4, #0
	adds r1, #0xc9
	ldrb r0, [r1]
	adds r6, r1, #0
	adds r7, r4, #0
	adds r7, #0xca
	cmp r0, #0
	beq _080807C2
	ldr r0, [r4, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x1c]
_080807C2:
	ldr r0, [r4, #0x18]
	ldr r1, _080807E0 @ =0x00000A8F
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r6]
	ldrh r0, [r7]
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080807E4
	ldrb r0, [r6]
	adds r0, #1
	b _080807E6
	.align 2, 0
_080807E0: .4byte 0x00000A8F
_080807E4:
	ldrb r0, [r6]
_080807E6:
	strh r0, [r4, #0x2c]
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
_080807EE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080807f4
FUN_080807f4: @ 0x080807F4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x18]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r6, [r0]
	cmp r6, #3
	bne _08080868
	adds r0, r4, #0
	bl FUN_08080204
	ldr r0, [r4, #0x18]
	ldr r5, _08080850 @ =0x0000037D
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #5
	bne _08080858
	adds r0, r4, #0
	bl FUN_08080620
	ldr r0, [r4, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	adds r0, #1
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl FUN_080806a4
	adds r1, r4, #0
	adds r1, #0x64
	strh r0, [r1, #0x3c]
	adds r0, r4, #0
	bl FUN_0808065c
	ldr r1, _08080854 @ =FUN_080808cc
	adds r0, r4, #0
	bl FUN_080801f4
	b _080808C0
	.align 2, 0
_08080850: .4byte 0x0000037D
_08080854: .4byte FUN_080808cc
_08080858:
	cmp r0, #8
	bne _08080870
	adds r0, r4, #0
	bl FUN_08080620
	adds r0, r4, #0
	bl FUN_0808065c
_08080868:
	adds r0, r4, #0
	bl KillEntity
	b _080808C0
_08080870:
	adds r0, r4, #0
	bl FUN_080803b4
	ldr r0, [r4, #0x18]
	adds r0, r0, r5
	ldrb r1, [r0]
	cmp r1, #2
	bne _08080896
	adds r1, r4, #0
	adds r1, #0xca
	ldrh r0, [r1]
	ands r6, r0
	adds r5, r1, #0
	cmp r6, #3
	bne _080808AC
	adds r0, r4, #0
	bl FUN_080804a0
	b _080808AC
_08080896:
	adds r5, r4, #0
	adds r5, #0xca
	cmp r1, #3
	bne _080808AC
	ldrh r0, [r5]
	ands r1, r0
	cmp r1, #3
	bne _080808AC
	adds r0, r4, #0
	bl FUN_080804a0
_080808AC:
	ldr r0, [r4, #0x18]
	ldr r1, _080808C8 @ =0x00000A8F
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0xc9
	strb r1, [r0]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_080808C0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080808C8: .4byte 0x00000A8F

	thumb_func_start FUN_080808cc
FUN_080808cc: @ 0x080808CC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, #0xb4
	ldrh r0, [r0]
	ldrh r1, [r6, #0x38]
	adds r0, r0, r1
	strh r0, [r6, #0x38]
	adds r0, r6, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	ldrh r2, [r6, #0x3c]
	adds r0, r0, r2
	strh r0, [r6, #0x3c]
	adds r4, r6, #0
	adds r4, #0x64
	adds r5, r6, #0
	adds r5, #0x38
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	ldr r2, [r6, #0x18]
	ldr r1, _08080924 @ =0x00080002
	ldr r0, [r2, #0x20]
	orrs r0, r1
	str r0, [r2, #0x20]
	adds r0, r5, #0
	bl FUN_082328ec
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0x3a
	ldrsh r1, [r6, r2]
	cmp r0, r1
	ble _0808092C
	ldr r1, _08080928 @ =FUN_0808094c
	adds r0, r6, #0
	bl FUN_080801f4
	b _08080944
	.align 2, 0
_08080924: .4byte 0x00080002
_08080928: .4byte FUN_0808094c
_0808092C:
	adds r1, r6, #0
	adds r1, #0xca
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _08080944
	adds r0, r6, #0
	bl KillEntity
_08080944:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808094c
FUN_0808094c: @ 0x0808094C
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xca
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _08080968
	movs r0, #4
	strh r0, [r2, #0x2c]
	b _080809D4
_08080968:
	cmp r0, #4
	bne _080809CA
	adds r0, r2, #0
	adds r0, #0xc8
	adds r2, #0x1c
	ldrb r1, [r0]
	movs r3, #1
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	beq _08080982
	movs r0, #7
	b _08080990
_08080982:
	asrs r0, r1, #1
	ands r0, r3
	cmp r0, #0
	beq _0808098E
	movs r0, #8
	b _08080990
_0808098E:
	movs r0, #6
_08080990:
	strh r0, [r2, #0x10]
	cmp r1, #2
	bgt _0808099E
	ldr r0, [r2]
	movs r1, #0xd
	rsbs r1, r1, #0
	b _080809C4
_0808099E:
	cmp r1, #4
	bgt _080809AE
	ldr r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #8
	b _080809B6
_080809AE:
	cmp r1, #5
	bgt _080809BC
	ldr r0, [r2]
	movs r1, #0xc
_080809B6:
	orrs r0, r1
	str r0, [r2]
	b _080809D4
_080809BC:
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	subs r1, #0xd
_080809C4:
	ands r0, r1
	str r0, [r2]
	b _080809D4
_080809CA:
	cmp r0, #6
	bls _080809D4
	adds r0, r2, #0
	bl KillEntity
_080809D4:
	pop {r0}
	bx r0

	thumb_func_start FUN_080809d8
FUN_080809d8: @ 0x080809D8
	push {lr}
	movs r2, #0xca
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_080809ec
FUN_080809ec: @ 0x080809EC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x1c
	bl FUN_0822a4e0
	adds r4, #0xd4
	movs r5, #3
_080809FA:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x30
	subs r5, #1
	cmp r5, #0
	bge _080809FA
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08080a10
FUN_08080a10: @ 0x08080A10
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r4, #0
	adds r5, #0x48
	ldr r1, _08080A40 @ =0x0000210E
	adds r0, r5, #0
	bl FUN_0822b16c
	adds r4, #0x1c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl FUN_0822a470
	movs r0, #0
	strh r0, [r4, #0x10]
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_0822b20c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08080A40: .4byte 0x0000210E

	thumb_func_start FUN_08080a44
FUN_08080a44: @ 0x08080A44
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r4, r0, #0
	mov r8, r1
	adds r6, r2, #0
	adds r7, r3, #0
	adds r5, r4, #0
	adds r5, #0x64
	ldr r3, _08080A84 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r2, #0x1e
	orrs r0, r2
	ldr r1, _08080A88 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x10]
	adds r0, r4, #0
	adds r0, #0xcd
	ldrb r0, [r0]
	cmp r0, #0
	beq _08080A8C
	str r1, [sp, #0x14]
	b _08080A8E
	.align 2, 0
_08080A84: .4byte 0xFFFF0000
_08080A88: .4byte 0x0000FFFF
_08080A8C:
	str r0, [sp, #0x14]
_08080A8E:
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r3
	str r0, [r1, #4]
	adds r3, r1, #0
	ldr r2, _08080AEC @ =0x00002101
	ldr r1, [r4, #0x18]
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
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	mov r2, r8
	movs r3, #0x10
	bl FUN_082364f8
	ldr r1, _08080AF0 @ =FUN_08080648
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_0823651c
	adds r1, r4, #0
	adds r1, #0x38
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080AEC: .4byte 0x00002101
_08080AF0: .4byte FUN_08080648

	thumb_func_start FUN_08080af4
FUN_08080af4: @ 0x08080AF4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	mov sb, r1
	adds r1, r4, #0
	adds r1, #0xcc
	movs r0, #0
	strb r0, [r1]
	ldr r0, _08080B64 @ =0x00001C1E
	bl FUN_0822b10c
	adds r1, r4, #0
	adds r1, #0xd0
	str r0, [r1]
	adds r6, r1, #0
	adds r5, r4, #0
	adds r5, #0xfc
	adds r4, #0xd4
	movs r0, #4
	rsbs r0, r0, #0
	mov r8, r0
	movs r7, #3
_08080B24:
	ldr r1, [r6]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r4, #0
	mov r1, r8
	mov r2, r8
	bl FUN_0822dad4
	ldr r1, [r6]
	adds r0, r4, #0
	mov r2, sb
	bl FUN_0822dafc
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #0
	strb r0, [r5]
	adds r5, #0x30
	adds r4, #0x30
	subs r7, #1
	cmp r7, #0
	bge _08080B24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080B64: .4byte 0x00001C1E

	thumb_func_start FUN_08080b68
FUN_08080b68: @ 0x08080B68
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r5, [sp, #0x14]
	ldr r4, [sp, #0x30]
	ldr r6, [sp, #0x34]
	str r1, [r7, #0x18]
	adds r0, #0xbc
	movs r1, #0
	strh r2, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	strh r5, [r0]
	adds r0, #2
	mov r2, sp
	ldrh r2, [r2, #0x18]
	strh r2, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, #5
	strb r1, [r0]
	adds r0, #4
	strb r6, [r0]
	adds r0, r7, #0
	ldr r1, [sp, #0x1c]
	bl FUN_08080a10
	adds r0, r7, #0
	ldr r1, [sp, #0x20]
	ldr r2, [sp, #0x24]
	ldr r3, [sp, #0x28]
	bl FUN_08080a44
	adds r0, r7, #0
	bl FUN_08080204
	adds r0, r7, #0
	ldr r1, [sp, #0x2c]
	bl FUN_08080af4
	ldr r0, [r7, #0x18]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #5
	beq _08080BD4
	ldr r1, _08080BD0 @ =FUN_080806ec
	adds r0, r7, #0
	bl FUN_080801f4
	b _08080BDC
	.align 2, 0
_08080BD0: .4byte FUN_080806ec
_08080BD4:
	ldr r1, _08080BE4 @ =FUN_080807f4
	adds r0, r7, #0
	bl FUN_080801f4
_08080BDC:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08080BE4: .4byte FUN_080807f4

	thumb_func_start FUN_08080be8
FUN_08080be8: @ 0x08080BE8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x24
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r1, #0xcc
	lsls r1, r1, #1
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08080C54
	ldr r1, _08080C4C @ =FUN_080809d8
	ldr r2, _08080C50 @ =FUN_080809ec
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #4]
	ldr r0, [sp, #0x40]
	str r0, [sp, #8]
	ldr r0, [sp, #0x44]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x48]
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x4c]
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x50]
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x54]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x58]
	str r0, [sp, #0x20]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_08080b68
	cmp r0, #0
	bge _08080C54
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08080C56
	.align 2, 0
_08080C4C: .4byte FUN_080809d8
_08080C50: .4byte FUN_080809ec
_08080C54:
	adds r0, r4, #0
_08080C56:
	add sp, #0x24
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08080c64
FUN_08080c64: @ 0x08080C64
	push {lr}
	adds r3, r0, #0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r2, [r0]
	cmp r2, #4
	bls _08080C90
	movs r0, #8
	subs r0, r0, r2
	ldr r2, _08080C88 @ =0x000002E6
	adds r1, r3, r2
	strb r0, [r1]
	ldr r0, _08080C8C @ =0x000002E7
	adds r1, r3, r0
	movs r0, #1
	strb r0, [r1]
	b _08080C9E
	.align 2, 0
_08080C88: .4byte 0x000002E6
_08080C8C: .4byte 0x000002E7
_08080C90:
	ldr r1, _08080CA4 @ =0x000002E6
	adds r0, r3, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _08080CA8 @ =0x000002E7
	adds r0, r3, r2
	strb r1, [r0]
_08080C9E:
	pop {r0}
	bx r0
	.align 2, 0
_08080CA4: .4byte 0x000002E6
_08080CA8: .4byte 0x000002E7

	thumb_func_start FUN_08080cac
FUN_08080cac: @ 0x08080CAC
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
	bne _08080CC4
	movs r3, #1
_08080CC4:
	strh r1, [r2]
	adds r4, r6, #0
	adds r4, #0x88
	adds r5, r6, #0
	adds r5, #0x68
	ldr r2, _08080CFC @ =0x000002E6
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
	ldr r1, _08080D00 @ =0x000002E7
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08080D04
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	b _08080D10
	.align 2, 0
_08080CFC: .4byte 0x000002E6
_08080D00: .4byte 0x000002E7
_08080D04:
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_08080D10:
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

	thumb_func_start FUN_08080d2c
FUN_08080d2c: @ 0x08080D2C
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
	ldr r2, _08080D60 @ =0x085B0A08
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
	blt _08080D64
	asrs r0, r0, #0xc
	b _08080D6A
	.align 2, 0
_08080D60: .4byte 0x085B0A08
_08080D64:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08080D6A:
	mov r1, ip
	strh r0, [r1, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _08080D80
	asrs r0, r0, #0xc
	b _08080D86
_08080D80:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08080D86:
	mov r1, ip
	strh r0, [r1, #0x38]
	ldr r3, _08080DAC @ =0x000001C7
	add r3, ip
	ldrb r3, [r3]
	cmp r3, #1
	bne _08080DCE
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08080DB0
	movs r2, #0x38
	ldrsh r1, [r1, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08080DBE
	b _08080DC2
	.align 2, 0
_08080DAC: .4byte 0x000001C7
_08080DB0:
	mov r2, ip
	movs r0, #0x38
	ldrsh r1, [r2, r0]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _08080DC2
_08080DBE:
	asrs r0, r0, #6
	b _08080DC8
_08080DC2:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08080DC8:
	mov r1, ip
	strh r0, [r1, #0x38]
	b _08080E06
_08080DCE:
	cmp r3, #2
	bne _08080E06
	mov r2, ip
	movs r1, #0x34
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bge _08080DEA
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08080DF8
	b _08080DFC
_08080DEA:
	mov r2, ip
	movs r0, #0x34
	ldrsh r1, [r2, r0]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _08080DFC
_08080DF8:
	asrs r0, r0, #6
	b _08080E02
_08080DFC:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08080E02:
	mov r1, ip
	strh r0, [r1, #0x34]
_08080E06:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08080e0c
FUN_08080e0c: @ 0x08080E0C
	push {r4, lr}
	movs r4, #0xdf
	lsls r4, r4, #2
	adds r3, r0, r4
	movs r4, #0
	strb r1, [r3]
	ldr r3, _08080E2C @ =0x0000037D
	adds r1, r0, r3
	strb r2, [r1]
	ldr r1, _08080E30 @ =0x0000037E
	adds r0, r0, r1
	strh r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08080E2C: .4byte 0x0000037D
_08080E30: .4byte 0x0000037E

	thumb_func_start FUN_08080e34
FUN_08080e34: @ 0x08080E34
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	str r0, [r4, #0x20]
	ldr r1, _08080EB4 @ =0x0000038E
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r1, _08080EB8 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0xb2
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, #0
	bne _08080E68
	adds r0, r4, #0
	bl FUN_0809e138
	cmp r0, #0
	beq _08080E68
	movs r1, #0x10
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
_08080E68:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08080E84
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
_08080E84:
	ldr r1, _08080EBC @ =0x00000604
	adds r0, r4, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08080EC0 @ =0x00000606
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r2, _08080EC4 @ =0x0000035A
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
_08080EB4: .4byte 0x0000038E
_08080EB8: .4byte 0x030046A0
_08080EBC: .4byte 0x00000604
_08080EC0: .4byte 0x00000606
_08080EC4: .4byte 0x0000035A

	thumb_func_start FUN_08080ec8
FUN_08080ec8: @ 0x08080EC8
	ldr r2, _08080ED4 @ =0x0000035A
	adds r0, r0, r2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_08080ED4: .4byte 0x0000035A

	thumb_func_start FUN_08080ed8
FUN_08080ed8: @ 0x08080ED8
	ldr r2, _08080EE4 @ =0x0000035A
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	bx lr
	.align 2, 0
_08080EE4: .4byte 0x0000035A

	thumb_func_start FUN_08080ee8
FUN_08080ee8: @ 0x08080EE8
	push {lr}
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _08080EFE
	movs r0, #0xd8
	bl sound_08240740
	b _08080F10
_08080EFE:
	ldr r0, _08080F14 @ =0x00000239
	bl sound_08240740
	ldr r0, _08080F18 @ =0x00000202
	bl sound_08240740
	ldr r0, _08080F1C @ =0x00000366
	bl sound_08240740
_08080F10:
	pop {r0}
	bx r0
	.align 2, 0
_08080F14: .4byte 0x00000239
_08080F18: .4byte 0x00000202
_08080F1C: .4byte 0x00000366

	thumb_func_start FUN_08080f20
FUN_08080f20: @ 0x08080F20
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldrh r1, [r2, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08080F3E
	adds r0, r2, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0xe0
	b _08080F70
_08080F3E:
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
	bne _08080F66
	cmp r1, #0
	bne _08080F66
	adds r0, r3, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0xe0
	b _08080F70
_08080F66:
	adds r0, r4, #0
	bl FUN_0823785c
	adds r1, r0, #0
	adds r1, #0x60
_08080F70:
	movs r0, #0xff
	ands r1, r0
	asrs r0, r1, #6
	lsls r0, r0, #1
	adds r0, #1
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08080f80
FUN_08080f80: @ 0x08080F80
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
	bls _08080F9E
	movs r0, #0xc8
	strh r0, [r6]
_08080F9E:
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r2, [r3, #0x38]
	ands r2, r0
	cmp r2, #0
	beq _08080FC8
	ldr r0, _08080FC4 @ =0x000003D2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r3, #0
	adds r1, r5, #0
	bl FUN_08080f20
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	b _08081098
	.align 2, 0
_08080FC4: .4byte 0x000003D2
_08080FC8:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08080FE0
	ldrh r0, [r5, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r5, #6]
	strh r2, [r6]
	b _0808109A
_08080FE0:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r4, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _08081084
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08081014
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
	b _08081064
_08081014:
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
	bne _08081042
	cmp r1, #0
	bne _08081042
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	b _08081066
_08081042:
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
_08081064:
	strh r0, [r1]
_08081066:
	adds r3, r5, #0
	adds r3, #0x40
	ldrh r2, [r3]
	ldr r1, _08081080 @ =0x000003E6
	adds r0, r4, r1
	movs r1, #0
	strh r2, [r0]
	strh r1, [r3]
	ldrh r1, [r5, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r5, #6]
	b _0808109A
	.align 2, 0
_08081080: .4byte 0x000003E6
_08081084:
	ldr r2, _080810A0 @ =0x000003D2
	adds r0, r4, r2
	strb r7, [r0]
	adds r0, r3, #0
	adds r1, r5, #0
	bl FUN_08080f20
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r4, r3
_08081098:
	strb r0, [r1]
_0808109A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080810A0: .4byte 0x000003D2

	thumb_func_start FUN_080810a4
FUN_080810a4: @ 0x080810A4
	push {lr}
	adds r2, r0, #0
	ldr r1, _080810E8 @ =0x0000038E
	adds r0, r2, r1
	ldrb r0, [r0]
	ldr r1, _080810EC @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r3, #0xb2
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	bgt _080810E4
	movs r1, #0x80
	lsls r1, r1, #3
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r2, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080810E4
	bl FUN_0823e1b0
	adds r1, r0, #0
	subs r0, r1, #4
	cmp r0, #1
	bls _080810E4
	cmp r1, #0
	bne _080810F0
_080810E4:
	movs r0, #1
	b _080810F2
	.align 2, 0
_080810E8: .4byte 0x0000038E
_080810EC: .4byte 0x030046A0
_080810F0:
	movs r0, #0
_080810F2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080810f8
FUN_080810f8: @ 0x080810F8
	push {r4, lr}
	movs r4, #0
_080810FC:
	adds r0, r4, #0
	bl GetValuableItemID
	subs r0, #0x38
	cmp r0, #7
	bls _08081110
	adds r4, #1
	cmp r4, #0xf
	ble _080810FC
	movs r0, #0
_08081110:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08081118
FUN_08081118: @ 0x08081118
	push {lr}
	sub sp, #0xc
	adds r3, r1, #0
	ldr r1, _08081148 @ =0x000009C4
	adds r0, r0, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _08081142
	ldr r1, _0808114C @ =0xFFFF0000
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
	bl FUN_082318ac
_08081142:
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_08081148: .4byte 0x000009C4
_0808114C: .4byte 0xFFFF0000

	thumb_func_start FUN_08081150
FUN_08081150: @ 0x08081150
	ldr r2, _0808115C @ =0x000009BC
	adds r0, r0, r2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_0808115C: .4byte 0x000009BC

	thumb_func_start FUN_08081160
FUN_08081160: @ 0x08081160
	ldr r2, _0808116C @ =0x000009BC
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	bx lr
	.align 2, 0
_0808116C: .4byte 0x000009BC

	thumb_func_start FUN_08081170
FUN_08081170: @ 0x08081170
	push {lr}
	movs r1, #0x9c
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08081184
	movs r1, #0
	bl FUN_082318ac
_08081184:
	pop {r0}
	bx r0

	thumb_func_start FUN_08081188
FUN_08081188: @ 0x08081188
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r2, r0, #0
	ldr r1, _080811CC @ =0x03003584
	ldr r3, _080811D0 @ =0x0000094C
	adds r0, r2, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r6, r1, r0
	ldr r0, _080811D4 @ =0x0000094E
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _080811D8
	movs r5, #0
	movs r3, #0xa9
	lsls r3, r3, #2
	adds r1, r2, r3
_080811B2:
	subs r0, r5, #5
	cmp r0, #1
	bls _080811C0
	cmp r5, #0xd
	beq _080811C0
	ldrh r0, [r6]
	strh r0, [r1]
_080811C0:
	adds r6, #2
	adds r1, #2
	adds r5, #1
	cmp r5, #0xf
	ble _080811B2
	b _08081234
	.align 2, 0
_080811CC: .4byte 0x03003584
_080811D0: .4byte 0x0000094C
_080811D4: .4byte 0x0000094E
_080811D8:
	movs r5, #0
	mov r8, r1
	movs r0, #0xa9
	lsls r0, r0, #2
	adds r7, r2, r0
_080811E2:
	subs r0, r5, #5
	cmp r0, #1
	bls _0808122A
	cmp r5, #0xd
	beq _0808122A
	ldrh r1, [r6]
	movs r3, #0x1f
	mov ip, r3
	movs r0, #0x1f
	ands r0, r1
	mov r3, r8
	ldrb r2, [r3]
	adds r4, r0, r2
	cmp r4, #0x1f
	ble _08081202
	movs r4, #0x1f
_08081202:
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x15
	mov r1, ip
	ands r0, r1
	adds r1, r0, r2
	cmp r1, #0x1f
	ble _08081212
	movs r1, #0x1f
_08081212:
	lsrs r0, r3, #0x1a
	mov r3, ip
	ands r0, r3
	adds r0, r0, r2
	cmp r0, #0x1f
	ble _08081220
	movs r0, #0x1f
_08081220:
	lsls r0, r0, #0xa
	lsls r1, r1, #5
	orrs r0, r1
	orrs r0, r4
	strh r0, [r7]
_0808122A:
	adds r6, #2
	adds r7, #2
	adds r5, #1
	cmp r5, #0xf
	ble _080811E2
_08081234:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08081240
FUN_08081240: @ 0x08081240
	push {r4, lr}
	adds r2, r0, #0
	movs r3, #0
	movs r1, #2
	ldr r0, _0808125C @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _08081260 @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08081264
	movs r0, #1
	b _08081266
	.align 2, 0
_0808125C: .4byte 0x030046A0
_08081260: .4byte 0x00000934
_08081264:
	movs r0, #0
_08081266:
	cmp r0, #0
	bne _08081278
	ldr r0, [r2, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08081284
	movs r3, #8
	b _08081284
_08081278:
	ldr r0, [r2, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08081284
	movs r3, #4
_08081284:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808128c
FUN_0808128c: @ 0x0808128C
	push {r4, lr}
	ldr r1, _080812C8 @ =0x03003584
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
	ldr r4, _080812CC @ =0x000002AE
	adds r1, r0, r4
	strh r3, [r1]
	adds r2, #2
	ldrh r3, [r2]
	adds r4, #2
	adds r1, r0, r4
	strh r3, [r1]
	ldrh r1, [r2, #2]
	ldr r2, _080812D0 @ =0x000002BE
	adds r0, r0, r2
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080812C8: .4byte 0x03003584
_080812CC: .4byte 0x000002AE
_080812D0: .4byte 0x000002BE

	thumb_func_start FUN_080812d4
FUN_080812d4: @ 0x080812D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r0, [sp]
	mov ip, r2
	str r3, [sp, #4]
	cmp r2, #0
	bne _080812F8
	adds r1, r0, #0
	adds r1, #0xd0
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r0, r0, r2
	str r0, [r1]
	b _080813BE
_080812F8:
	mov sl, r1
	movs r3, #0
	mov r8, r3
	ldr r7, [sp]
	adds r7, #0xd0
	str r7, [sp, #0xc]
	ldr r0, [sp]
	movs r1, #0xa9
	lsls r1, r1, #2
	adds r6, r0, r1
	ldr r2, _08081324 @ =0x0000094E
	adds r2, r0, r2
	str r2, [sp, #8]
_08081312:
	mov r0, r8
	subs r0, #5
	cmp r0, #1
	bls _08081320
	mov r3, r8
	cmp r3, #0xd
	bne _08081328
_08081320:
	ldrh r0, [r6]
	b _080813A0
	.align 2, 0
_08081324: .4byte 0x0000094E
_08081328:
	mov r7, sl
	ldrh r2, [r7]
	movs r7, #0x1f
	movs r0, #0x1f
	mov sb, r0
	ands r0, r2
	ldr r3, [sp, #8]
	ldrb r1, [r3]
	adds r4, r0, r1
	cmp r4, #0x1f
	ble _08081340
	movs r4, #0x1f
_08081340:
	lsls r3, r2, #0x10
	lsrs r0, r3, #0x15
	ands r0, r7
	adds r2, r0, r1
	cmp r2, #0x1f
	ble _0808134E
	movs r2, #0x1f
_0808134E:
	lsrs r0, r3, #0x1a
	ands r0, r7
	adds r5, r0, r1
	cmp r5, #0x1f
	ble _0808135A
	movs r5, #0x1f
_0808135A:
	ldrh r1, [r6]
	mov r0, sb
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x15
	ands r3, r7
	lsrs r1, r1, #0x1a
	ands r1, r7
	mov r7, ip
	muls r7, r4, r7
	adds r4, r7, #0
	ldr r7, [sp, #4]
	muls r0, r7, r0
	adds r4, r4, r0
	ldr r0, [sp, #0x30]
	asrs r4, r0
	mov r7, ip
	muls r7, r2, r7
	adds r2, r7, #0
	ldr r7, [sp, #4]
	adds r0, r3, #0
	muls r0, r7, r0
	adds r2, r2, r0
	ldr r0, [sp, #0x30]
	asrs r2, r0
	mov r0, ip
	muls r0, r5, r0
	muls r1, r7, r1
	adds r0, r0, r1
	ldr r1, [sp, #0x30]
	asrs r0, r1
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r4
_080813A0:
	strh r0, [r6, #0x20]
	movs r2, #2
	add sl, r2
	adds r6, #2
	movs r3, #1
	add r8, r3
	mov r7, r8
	cmp r7, #0xf
	ble _08081312
	ldr r1, [sp]
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r3, [sp, #0xc]
	str r0, [r3]
_080813BE:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080813d0
FUN_080813d0: @ 0x080813D0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, _08081450 @ =0x00000951
	adds r0, r4, r1
	movs r2, #0x95
	lsls r2, r2, #4
	adds r1, r4, r2
	ldrb r0, [r0]
	ldrb r3, [r1]
	cmp r0, r3
	beq _080813F2
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0808128c
_080813F2:
	adds r0, r4, #0
	bl FUN_08081240
	adds r2, r0, #0
	ldr r6, _08081454 @ =0x0000094C
	adds r1, r4, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, r5
	bne _08081410
	adds r6, #2
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, r2
	beq _0808141E
_08081410:
	strh r5, [r1]
	ldr r1, _08081458 @ =0x0000094E
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_08081188
_0808141E:
	ldr r2, _0808145C @ =0x00000476
	adds r0, r4, r2
	ldrb r5, [r0]
	cmp r5, #0
	beq _0808148C
	ldr r0, _08081460 @ =0x03003584
	ldr r0, [r0]
	movs r3, #0x99
	lsls r3, r3, #6
	adds r5, r0, r3
	movs r3, #0
	adds r6, r4, #0
	adds r6, #0xd0
	movs r0, #0xb1
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
_08081442:
	subs r0, r3, #5
	cmp r0, #1
	bls _0808144C
	cmp r3, #0xd
	bne _08081464
_0808144C:
	ldrh r0, [r2]
	b _08081466
	.align 2, 0
_08081450: .4byte 0x00000951
_08081454: .4byte 0x0000094C
_08081458: .4byte 0x0000094E
_0808145C: .4byte 0x00000476
_08081460: .4byte 0x03003584
_08081464:
	ldrh r0, [r5]
_08081466:
	strh r0, [r1]
	adds r5, #2
	adds r1, #2
	adds r2, #2
	adds r3, #1
	cmp r3, #0xf
	ble _08081442
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r4, r1
	str r0, [r6]
	ldr r2, _08081488 @ =0x00000476
	adds r1, r4, r2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _0808159C
	.align 2, 0
_08081488: .4byte 0x00000476
_0808148C:
	movs r3, #0x96
	lsls r3, r3, #4
	adds r2, r4, r3
	ldrh r0, [r2]
	cmp r0, #0
	bne _08081512
	ldr r6, _080814D4 @ =0x00000964
	adds r3, r4, r6
	ldrh r2, [r3]
	subs r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4e
	bhi _08081502
	ldr r1, _080814D8 @ =0x03003584
	subs r6, #2
	adds r0, r4, r6
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r6, r1, r0
	adds r0, r2, #0
	subs r0, #0x21
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _080814C6
	movs r0, #0x30
	strh r0, [r3]
_080814C6:
	ldrh r0, [r3]
	cmp r0, #0x1f
	bhi _080814DC
	adds r2, r0, #0
	subs r0, r2, #1
	strh r0, [r3]
	b _080814F0
	.align 2, 0
_080814D4: .4byte 0x00000964
_080814D8: .4byte 0x03003584
_080814DC:
	ldrh r0, [r3]
	movs r1, #0x50
	subs r2, r1, r0
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4f
	bls _080814F0
	strh r5, [r3]
_080814F0:
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080812d4
	b _0808159C
_08081502:
	strh r5, [r3]
	adds r1, r4, #0
	adds r1, #0xd0
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r0, [r1]
	b _0808159C
_08081512:
	ldr r3, _0808154C @ =0x00000964
	adds r0, r4, r3
	strh r5, [r0]
	ldrh r0, [r2]
	cmp r0, #0x1f
	bls _08081572
	ldr r1, _08081550 @ =0x03003584
	ldr r6, _08081554 @ =0x0000095E
	adds r0, r4, r6
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r5, r1, r0
	movs r1, #0
	adds r6, r4, #0
	adds r6, #0xd0
	movs r0, #0xb1
	lsls r0, r0, #2
	adds r2, r4, r0
	subs r0, #0x20
	adds r3, r4, r0
_0808153C:
	subs r0, r1, #5
	cmp r0, #1
	bls _08081546
	cmp r1, #0xd
	bne _08081558
_08081546:
	ldrh r0, [r3]
	b _0808155A
	.align 2, 0
_0808154C: .4byte 0x00000964
_08081550: .4byte 0x03003584
_08081554: .4byte 0x0000095E
_08081558:
	ldrh r0, [r5]
_0808155A:
	strh r0, [r2]
	adds r5, #2
	adds r2, #2
	adds r3, #2
	adds r1, #1
	cmp r1, #0xf
	ble _0808153C
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r4, r1
	str r0, [r6]
	b _08081590
_08081572:
	ldr r1, _080815A4 @ =0x03003584
	ldr r3, _080815A8 @ =0x0000095E
	adds r0, r4, r3
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldrh r2, [r2]
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_080812d4
_08081590:
	movs r6, #0x96
	lsls r6, r6, #4
	adds r1, r4, r6
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_0808159C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080815A4: .4byte 0x03003584
_080815A8: .4byte 0x0000095E

	thumb_func_start FUN_080815ac
FUN_080815ac: @ 0x080815AC
	push {r4, lr}
	ldr r1, _080815E8 @ =0x0000094A
	adds r3, r0, r1
	movs r2, #0
	movs r1, #0x27
	strh r1, [r3]
	ldr r4, _080815EC @ =0x0000094C
	adds r1, r0, r4
	strh r2, [r1]
	movs r1, #0x95
	lsls r1, r1, #4
	adds r2, r0, r1
	movs r1, #0xff
	strb r1, [r2]
	adds r2, r0, #0
	adds r2, #0xc2
	adds r1, #0x22
	strh r1, [r2]
	adds r2, #0xe
	movs r4, #0xa9
	lsls r4, r4, #2
	adds r1, r0, r4
	str r1, [r2]
	ldrh r1, [r3]
	bl FUN_080813d0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080815E8: .4byte 0x0000094A
_080815EC: .4byte 0x0000094C

	thumb_func_start FUN_080815f0
FUN_080815f0: @ 0x080815F0
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _08081614 @ =0x0000095C
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08081610
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08081618
_08081610:
	adds r0, r2, #0
	b _0808161E
	.align 2, 0
_08081614: .4byte 0x0000095C
_08081618:
	ldr r1, _08081624 @ =0x0000095A
	adds r0, r3, r1
	ldrh r0, [r0]
_0808161E:
	pop {r1}
	bx r1
	.align 2, 0
_08081624: .4byte 0x0000095A

	thumb_func_start FUN_08081628
FUN_08081628: @ 0x08081628
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08081684 @ =0x0000094A
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_080815f0
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_080813d0
	adds r1, r4, #0
	adds r1, #0xa8
	ldr r2, _08081688 @ =0x00000604
	adds r0, r4, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	subs r2, #8
	adds r1, r4, r2
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0xaa
	adds r2, #0xa
	adds r0, r4, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	subs r2, #8
	adds r1, r4, r2
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0xac
	adds r2, #0xa
	adds r0, r4, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r4, r4, r1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08081684: .4byte 0x0000094A
_08081688: .4byte 0x00000604

	thumb_func_start FUN_0808168c
FUN_0808168c: @ 0x0808168C
	push {lr}
	ldr r1, _0808169C @ =0x0000060C
	adds r0, r0, r1
	bl FUN_080138fc
	pop {r0}
	bx r0
	.align 2, 0
_0808169C: .4byte 0x0000060C

	thumb_func_start FUN_080816a0
FUN_080816a0: @ 0x080816A0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _08081748 @ =0x000005FC
	adds r1, r4, r0
	adds r0, r4, #0
	adds r0, #0xa8
	ldr r2, [r0]
	ldr r3, [r0, #4]
	str r2, [r1]
	str r3, [r1, #4]
	ldr r2, _0808174C @ =0x00000604
	adds r0, r4, r2
	movs r5, #0
	movs r6, #0
	strh r6, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r6, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r6, [r0]
	adds r2, #4
	adds r0, r4, r2
	movs r2, #0
	bl FUN_0801385c
	adds r0, r4, #0
	bl FUN_080815ac
	ldr r1, _08081750 @ =0x0000097C
	adds r0, r4, r1
	movs r1, #4
	strb r1, [r0]
	ldr r2, _08081754 @ =0x0000097D
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	movs r1, #0x97
	lsls r1, r1, #4
	adds r0, r4, r1
	strh r6, [r0]
	subs r2, #0x18
	adds r0, r4, r2
	strh r6, [r0]
	adds r1, #4
	adds r0, r4, r1
	strh r6, [r0]
	ldr r2, _08081758 @ =0x000003FF
	adds r4, r4, r2
	movs r0, #0xff
	strb r0, [r4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08081748: .4byte 0x000005FC
_0808174C: .4byte 0x00000604
_08081750: .4byte 0x0000097C
_08081754: .4byte 0x0000097D
_08081758: .4byte 0x000003FF

	thumb_func_start FUN_0808175c
FUN_0808175c: @ 0x0808175C
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r5, r4, r0
	ldr r2, _080817DC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x32
	orrs r0, r3
	ldr r1, _080817E0 @ =0x0000FFFF
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
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldrh r1, [r4, #0x24]
	ldr r2, _080817E4 @ =0x00004001
	movs r0, #1
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r5, #0
	movs r1, #0x14
	movs r2, #2
	movs r3, #1
	bl FUN_08236514
	ldr r1, _080817E8 @ =FUN_080843ac
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_0823651c
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r4, r0
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
_080817DC: .4byte 0xFFFF0000
_080817E0: .4byte 0x0000FFFF
_080817E4: .4byte 0x00004001
_080817E8: .4byte FUN_080843ac

	thumb_func_start FUN_080817ec
FUN_080817ec: @ 0x080817EC
	movs r1, #1
	str r1, [r0, #0x1c]
	movs r1, #0xac
	lsls r1, r1, #4
	adds r2, r0, r1
	ldr r1, _08081824 @ =FUN_08084330
	str r1, [r2]
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #0
	strb r2, [r1]
	ldr r3, _08081828 @ =0x0000037D
	adds r1, r0, r3
	strb r2, [r1]
	adds r3, #1
	adds r1, r0, r3
	strh r2, [r1]
	ldr r2, _0808182C @ =0x03002B68
	adds r1, r0, #0
	adds r1, #0x28
	ldrb r1, [r1]
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r0, [r0, #0x24]
	strh r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_08081824: .4byte FUN_08084330
_08081828: .4byte 0x0000037D
_0808182C: .4byte 0x03002B68

	thumb_func_start FUN_08081830
FUN_08081830: @ 0x08081830
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r0, _080818A0 @ =0x0000CB05
	ldr r1, _080818A4 @ =0x0000DE23
	bl FUN_082310cc
	adds r2, r0, #0
	cmp r2, #0
	bne _08081846
	b _08081AA4
_08081846:
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
	bl FUN_0822f284
	adds r5, r6, #0
	adds r5, #0x88
	movs r3, #0x80
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
	cmp r1, #0
	beq _080818A8
	bl fetch_082316e4
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r6, r2
	strb r0, [r1]
	b _080818B0
	.align 2, 0
_080818A0: .4byte 0x0000CB05
_080818A4: .4byte 0x0000DE23
_080818A8:
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r6, r3
	strb r1, [r0]
_080818B0:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r2, [r0]
	cmp r2, #4
	bls _080818D8
	movs r0, #8
	subs r0, r0, r2
	ldr r2, _080818D0 @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _080818D4 @ =0x000002E7
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	b _080818E6
	.align 2, 0
_080818D0: .4byte 0x000002E6
_080818D4: .4byte 0x000002E7
_080818D8:
	ldr r1, _08081918 @ =0x000002E6
	adds r0, r6, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _0808191C @ =0x000002E7
	adds r0, r6, r2
	strb r1, [r0]
_080818E6:
	movs r3, #0xb9
	lsls r3, r3, #2
	adds r0, r6, r3
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08081918 @ =0x000002E6
	adds r0, r6, r2
	ldrb r2, [r0]
	str r1, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r3, _0808191C @ =0x000002E7
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08081920
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	b _0808192C
	.align 2, 0
_08081918: .4byte 0x000002E6
_0808191C: .4byte 0x000002E7
_08081920:
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_0808192C:
	str r1, [r0]
	add r0, sp, #0x10
	bl FUN_08084734
	adds r2, r6, #0
	movs r4, #0x8f
	lsls r4, r4, #3
	adds r5, r6, r4
	movs r0, #8
	adds r0, r0, r6
	mov ip, r0
	adds r7, r6, #0
	adds r7, #0x18
_08081946:
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	str r0, [r5]
	str r1, [r5, #4]
	cmp r2, ip
	beq _08081974
	cmp r2, ip
	bgt _0808195C
	cmp r2, r6
	beq _0808196A
	b _0808198E
_0808195C:
	adds r0, r6, #0
	adds r0, #0x10
	cmp r2, r0
	beq _0808197C
	cmp r2, r7
	beq _08081986
	b _0808198E
_0808196A:
	movs r1, #0x2c
	movs r4, #0xa0
	rsbs r4, r4, #0
	movs r3, #5
	b _08081994
_08081974:
	movs r1, #0x2c
	movs r4, #0xfc
	movs r3, #1
	b _08081994
_0808197C:
	movs r1, #0xa0
	rsbs r1, r1, #0
	movs r4, #0x2c
	movs r3, #3
	b _08081994
_08081986:
	movs r1, #0xfc
	movs r4, #0x2c
	movs r3, #7
	b _08081994
_0808198E:
	movs r1, #0
	movs r4, #0
	movs r3, #0
_08081994:
	ldrh r0, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	ldr r0, _080819D4 @ =0x0000047C
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, r0, r4
	strh r0, [r1]
	ldr r1, _080819D8 @ =0x0000047E
	adds r0, r2, r1
	strh r3, [r0]
	adds r2, #8
	adds r5, #8
	cmp r2, r7
	ble _08081946
	ldr r2, _080819DC @ =0x000004A6
	adds r0, r6, r2
	movs r1, #0
	strb r1, [r0]
	ldr r3, _080819E0 @ =0x00000466
	adds r0, r6, r3
	strb r1, [r0]
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _080819E8
	bl fetch_082316e4
	ldr r4, _080819E4 @ =0x00000467
	adds r1, r6, r4
	b _080819EE
	.align 2, 0
_080819D4: .4byte 0x0000047C
_080819D8: .4byte 0x0000047E
_080819DC: .4byte 0x000004A6
_080819E0: .4byte 0x00000466
_080819E4: .4byte 0x00000467
_080819E8:
	ldr r5, _08081A10 @ =0x00000467
	adds r1, r6, r5
	movs r0, #0x32
_080819EE:
	strb r0, [r1]
	ldr r1, _08081A14 @ =0x00000469
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	movs r0, #0x62
	bl prepare_08231510
	cmp r0, #0
	beq _08081A18
	bl fetch_082316e4
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r1, r6, r2
	b _08081A20
	.align 2, 0
_08081A10: .4byte 0x00000467
_08081A14: .4byte 0x00000469
_08081A18:
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r1, r6, r3
	movs r0, #3
_08081A20:
	strb r0, [r1]
	ldr r4, _08081A50 @ =0x0000046D
	adds r0, r6, r4
	movs r1, #0
	strb r1, [r0]
	ldr r5, _08081A54 @ =0x00000474
	adds r0, r6, r5
	strh r1, [r0]
	movs r0, #0x47
	bl prepare_08231510
	cmp r0, #0
	beq _08081A60
	bl fetch_082316e4
	ldr r2, _08081A58 @ =0x0000046C
	adds r1, r6, r2
	strb r0, [r1]
	bl fetch_082316e4
	ldr r3, _08081A5C @ =0x00000472
	adds r1, r6, r3
	b _08081A6E
	.align 2, 0
_08081A50: .4byte 0x0000046D
_08081A54: .4byte 0x00000474
_08081A58: .4byte 0x0000046C
_08081A5C: .4byte 0x00000472
_08081A60:
	ldr r4, _08081A8C @ =0x0000046C
	adds r1, r6, r4
	movs r0, #4
	strb r0, [r1]
	ldr r5, _08081A90 @ =0x00000472
	adds r1, r6, r5
	movs r0, #0xb4
_08081A6E:
	strh r0, [r1]
	ldr r1, _08081A94 @ =0x0000046B
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _08081A9C
	bl fetch_082316e4
	ldr r2, _08081A98 @ =0x0000046A
	adds r1, r6, r2
	b _08081AA2
	.align 2, 0
_08081A8C: .4byte 0x0000046C
_08081A90: .4byte 0x00000472
_08081A94: .4byte 0x0000046B
_08081A98: .4byte 0x0000046A
_08081A9C:
	ldr r3, _08081AAC @ =0x0000046A
	adds r1, r6, r3
	movs r0, #5
_08081AA2:
	strb r0, [r1]
_08081AA4:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08081AAC: .4byte 0x0000046A

	thumb_func_start FUN_08081ab0
FUN_08081ab0: @ 0x08081AB0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	adds r7, r1, #0
	movs r0, #1
	str r0, [r6, #0x18]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08081B04
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08081AFC @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	ldr r2, _08081B00 @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	b _08081B0E
	.align 2, 0
_08081AFC: .4byte 0xFFFF0000
_08081B00: .4byte 0x0000FFFF
_08081B04:
	ldr r1, _08081B3C @ =0xFFFF0000
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
_08081B0E:
	add r5, sp, #8
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08081B36
	cmp r1, #0
	blt _08081B36
	ldr r0, _08081B40 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08081B36
	ldr r0, _08081B44 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08081B48
_08081B36:
	movs r4, #0
	b _08081B56
	.align 2, 0
_08081B3C: .4byte 0xFFFF0000
_08081B40: .4byte 0x030046A8
_08081B44: .4byte 0x030046AC
_08081B48:
	ldr r0, _08081B68 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08081B56:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08081B6C
	adds r0, #4
	b _08081B78
	.align 2, 0
_08081B68: .4byte 0x030046A4
_08081B6C:
	ldr r0, _08081B8C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08081B78:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08081B90
	cmp r2, #2
	beq _08081B94
	b _08081B98
	.align 2, 0
_08081B8C: .4byte 0x030046A4
_08081B90:
	ldrb r0, [r5, #4]
	b _08081B96
_08081B94:
	ldrb r0, [r5]
_08081B96:
	subs r1, r1, r0
_08081B98:
	add r0, sp, #8
	strh r1, [r0, #2]
	adds r5, r6, #0
	adds r5, #0x24
	lsls r1, r7, #0x10
	lsrs r1, r1, #0x10
	ldrb r0, [r6, #0x18]
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r5, #0
	add r2, sp, #8
	movs r3, #0
	bl FUN_0823b400
	adds r0, r6, #0
	bl FUN_08081830
	adds r1, r6, #0
	adds r1, #0x88
	adds r0, r5, #0
	bl FUN_0823b474
	movs r0, #0xde
	lsls r0, r0, #1
	adds r4, r6, r0
	adds r0, r4, #0
	add r1, sp, #8
	bl FUN_0823280c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x1e
	movs r3, #0x1e
	bl FUN_0823b43c
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r6, r1
	add r1, sp, #8
	bl FUN_082362fc
	ldr r0, _08081C00 @ =0x00000464
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_08002a48
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08081C00: .4byte 0x00000464

	thumb_func_start FUN_08081c04
FUN_08081c04: @ 0x08081C04
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r7, r0, #0
	ldr r0, _08081C30 @ =0x000009C8
	adds r6, r7, r0
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _08081C38
	bl fetch_082316e4
	ldr r2, _08081C34 @ =0x00000A7A
	adds r1, r7, r2
	strh r0, [r1]
	bl fetch_082316e4
	adds r5, r0, #0
	b _08081C42
	.align 2, 0
_08081C30: .4byte 0x000009C8
_08081C34: .4byte 0x00000A7A
_08081C38:
	ldr r0, _08081CFC @ =0x00000A7A
	adds r1, r7, r0
	movs r0, #0xa
	strh r0, [r1]
	movs r5, #0x1e
_08081C42:
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0x20
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x14
	strh r0, [r1]
	adds r4, r6, #0
	adds r4, #0x2c
	ldr r1, _08081D00 @ =0x00002110
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0x43
	bl FUN_0822a470
	movs r0, #4
	strh r0, [r6, #0x10]
	adds r0, r4, #0
	movs r1, #0x32
	bl FUN_0822b20c
	movs r1, #2
	mov r8, r1
	mov r2, r8
	strb r2, [r6, #7]
	movs r0, #0x7f
	strb r0, [r6, #9]
	strb r0, [r6, #8]
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	movs r0, #0xa1
	lsls r0, r0, #4
	adds r4, r7, r0
	ldr r2, _08081D04 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0xaa
	orrs r0, r3
	ldr r1, _08081D08 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r0, _08081D0C @ =0xFFEC0000
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _08081D10 @ =0x00002101
	movs r0, #1
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	mov r1, r8
	str r1, [sp]
	ldr r2, _08081D14 @ =0x00000A7E
	adds r0, r7, r2
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0x32
	movs r3, #0x10
	bl FUN_082364f8
	adds r0, r4, #0
	movs r1, #0
	adds r2, r7, #0
	bl FUN_0823651c
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08081CFC: .4byte 0x00000A7A
_08081D00: .4byte 0x00002110
_08081D04: .4byte 0xFFFF0000
_08081D08: .4byte 0x0000FFFF
_08081D0C: .4byte 0xFFEC0000
_08081D10: .4byte 0x00002101
_08081D14: .4byte 0x00000A7E

	thumb_func_start FUN_08081d18
FUN_08081d18: @ 0x08081D18
	push {r4, r5, r6, lr}
	sub sp, #0x20
	adds r2, r0, #0
	adds r0, #0x90
	ldr r5, [r0]
	movs r0, #1
	ands r5, r0
	cmp r5, #0
	bne _08081D94
	movs r0, #0xf7
	lsls r0, r0, #2
	adds r6, r2, r0
	adds r0, r1, #2
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x63
	bls _08081D94
	ldr r0, [r2, #0x2c]
	ldr r1, [r2, #0x30]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r2, [sp, #0x18]
	asrs r1, r2, #0x10
	adds r1, #0x50
	lsls r1, r1, #0x10
	ldr r3, _08081D9C @ =0x0000FFFF
	adds r0, r3, #0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r4, _08081DA0 @ =0xFFFF0000
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
	orrs r0, r2
	str r0, [sp, #0x14]
	add r0, sp, #0x18
	str r5, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #1
	add r2, sp, #0x10
	movs r3, #0
	bl FUN_080ddcc8
	ldrh r0, [r6]
	subs r0, #0x64
	strh r0, [r6]
_08081D94:
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08081D9C: .4byte 0x0000FFFF
_08081DA0: .4byte 0xFFFF0000

	thumb_func_start FUN_08081da4
FUN_08081da4: @ 0x08081DA4
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _08081DCC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08081DD0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08081DD4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #4
	movs r1, #0x64
	bl Mod
	cmp r0, r4
	blt _08081DD8
	movs r0, #0
	b _08081DDA
	.align 2, 0
_08081DCC: .4byte 0x030046B8
_08081DD0: .4byte 0x000003FF
_08081DD4: .4byte 0x0203B400
_08081DD8:
	movs r0, #1
_08081DDA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08081de0
FUN_08081de0: @ 0x08081DE0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	mov sl, r0
	str r1, [sp, #0x40]
	str r2, [sp, #0x44]
	movs r0, #0
	mov sb, r0
	movs r6, #0
	movs r1, #0xff
	mov r8, r1
	mov r5, sp
_08081DFE:
	ldr r0, _08081E28 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r5]
	str r1, [r5, #4]
	lsls r2, r6, #5
	ldr r1, _08081E2C @ =0x085B0A08
	adds r0, r2, #0
	adds r0, #0x40
	mov r3, r8
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	cmp r0, #0
	blt _08081E30
	asrs r1, r0, #0xc
	b _08081E36
	.align 2, 0
_08081E28: .4byte 0x03002BE0
_08081E2C: .4byte 0x085B0A08
_08081E30:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08081E36:
	ldrh r0, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	mov r3, r8
	ands r2, r3
	lsls r0, r2, #1
	ldr r1, _08081E54 @ =0x085B0A08
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #9
	cmp r0, #0
	blt _08081E58
	asrs r0, r0, #0xc
	b _08081E5E
	.align 2, 0
_08081E54: .4byte 0x085B0A08
_08081E58:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08081E5E:
	ldrh r1, [r5, #4]
	adds r1, r1, r0
	strh r1, [r5, #4]
	adds r7, r5, #0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08081E88
	cmp r1, #0
	blt _08081E88
	ldr r0, _08081E8C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08081E88
	ldr r0, _08081E90 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08081E94
_08081E88:
	movs r4, #0
	b _08081EA2
	.align 2, 0
_08081E8C: .4byte 0x030046A8
_08081E90: .4byte 0x030046AC
_08081E94:
	ldr r0, _08081EB4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08081EA2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08081EB8
	adds r0, #4
	b _08081EC4
	.align 2, 0
_08081EB4: .4byte 0x030046A4
_08081EB8:
	ldr r0, _08081ED8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08081EC4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08081EDC
	cmp r3, #2
	beq _08081EE0
	b _08081EE8
	.align 2, 0
_08081ED8: .4byte 0x030046A4
_08081EDC:
	ldrh r1, [r7, #4]
	b _08081EE2
_08081EE0:
	ldrh r1, [r7]
_08081EE2:
	mov r0, r8
	ands r0, r1
	subs r2, r2, r0
_08081EE8:
	mov r3, sl
	movs r1, #0x2e
	ldrsh r0, [r3, r1]
	cmp r2, r0
	bne _08081EFA
	movs r0, #1
	strh r0, [r5, #6]
	add sb, r0
	b _08081EFE
_08081EFA:
	movs r0, #0
	strh r0, [r5, #6]
_08081EFE:
	adds r5, #8
	adds r6, #1
	cmp r6, #7
	bgt _08081F08
	b _08081DFE
_08081F08:
	mov r2, sb
	cmp r2, #0
	bne _08081F28
	b _08081F60
_08081F10:
	ldr r0, [r1]
	ldr r1, [r1, #4]
	ldr r3, [sp, #0x40]
	str r0, [r3]
	str r1, [r3, #4]
	adds r0, r6, #7
	movs r1, #7
	ands r0, r1
	ldr r1, [sp, #0x44]
	str r0, [r1]
	movs r0, #1
	b _08081F62
_08081F28:
	ldr r2, _08081F74 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08081F78 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08081F7C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	asrs r0, r0, #3
	mov r1, sb
	bl Mod
	adds r2, r0, #0
	movs r6, #0
	mov r1, sp
_08081F4A:
	movs r3, #6
	ldrsh r0, [r1, r3]
	cmp r0, #0
	beq _08081F58
	cmp r2, #0
	beq _08081F10
	subs r2, #1
_08081F58:
	adds r1, #8
	adds r6, #1
	cmp r6, #7
	ble _08081F4A
_08081F60:
	movs r0, #0
_08081F62:
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08081F74: .4byte 0x030046B8
_08081F78: .4byte 0x000003FF
_08081F7C: .4byte 0x0203B400

	thumb_func_start FUN_08081f80
FUN_08081f80: @ 0x08081F80
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08081FA0
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
	adds r0, r4, #0
	bl FUN_08080c64
_08081FA0:
	movs r1, #0xcf
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08081fb4
FUN_08081fb4: @ 0x08081FB4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08081FCE
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl FUN_08080e0c
_08081FCE:
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_08080ec8
	movs r2, #0x82
	lsls r2, r2, #2
	adds r3, r4, r2
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r2, #0x2c
	ldrsh r6, [r4, r2]
	subs r2, r0, r6
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x30
	ldrsh r5, [r4, r1]
	subs r1, r0, r5
	movs r7, #0xc
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	cmp r0, #0x90
	bgt _08082074
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r4, #0x2c]
	str r1, [r4, #0x30]
	ldr r1, _08082038 @ =0x00000471
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _08082040
	movs r0, #8
	subs r0, r0, r1
	subs r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _0808203C @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	b _0808204C
	.align 2, 0
_08082038: .4byte 0x00000471
_0808203C: .4byte 0x000002E7
_08082040:
	ldr r2, _0808206C @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _08082070 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
_0808204C:
	strb r0, [r1]
	movs r1, #0xcf
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	movs r1, #0x8e
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08080e0c
	b _08082118
	.align 2, 0
_0808206C: .4byte 0x000002E6
_08082070: .4byte 0x000002E7
_08082074:
	movs r2, #0x86
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r2, r0, r6
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r1, r0, r5
	adds r0, r2, #0
	bl FUN_0823785c
	adds r5, r0, #0
	ldr r2, _080820B0 @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _080820B4
	asrs r0, r0, #0xc
	b _080820BA
	.align 2, 0
_080820B0: .4byte 0x085B0A08
_080820B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080820BA:
	strh r0, [r4, #0x34]
	ldr r0, _080820D4 @ =0x085B0A08
	movs r1, #0xff
	ands r1, r5
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _080820D8
	asrs r0, r0, #0xc
	b _080820DE
	.align 2, 0
_080820D4: .4byte 0x085B0A08
_080820D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080820DE:
	strh r0, [r4, #0x38]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08235fd8
	cmp r0, #0
	beq _0808210E
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08080c64
_0808210E:
	ldr r1, _08082120 @ =0x000001A3
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
_08082118:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08082120: .4byte 0x000001A3

	thumb_func_start FUN_08082124
FUN_08082124: @ 0x08082124
	push {lr}
	adds r2, r0, #0
	movs r1, #0x10
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0808214C
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r3, _08082148 @ =0x0000036A
	adds r1, r2, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _0808214C
	movs r0, #1
	b _0808214E
	.align 2, 0
_08082148: .4byte 0x0000036A
_0808214C:
	movs r0, #0
_0808214E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08082154
FUN_08082154: @ 0x08082154
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #7
	beq _0808216E
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl FUN_08080e0c
_0808216E:
	ldr r2, _08082184 @ =0x0000037D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #4
	bls _0808217A
	b _08082456
_0808217A:
	lsls r0, r0, #2
	ldr r1, _08082188 @ =_0808218C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08082184: .4byte 0x0000037D
_08082188: .4byte _0808218C
_0808218C: @ jump table
	.4byte _080821A0 @ case 0
	.4byte _080821B8 @ case 1
	.4byte _080822D0 @ case 2
	.4byte _080823AC @ case 3
	.4byte _0808241C @ case 4
_080821A0:
	movs r1, #0xcf
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	bl FUN_08080e0c
	b _08082456
_080821B8:
	ldr r1, _08082214 @ =0x0000037E
	adds r0, r4, r1
	ldrh r2, [r0]
	cmp r2, #0
	bne _0808226E
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _08082228
	movs r0, #4
	strb r0, [r1]
	ldr r0, _08082218 @ =0x000002E6
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0808221C @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	subs r0, #0x14
	strh r0, [r2]
	ldr r2, _08082220 @ =0x00000932
	adds r1, r4, r2
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _08082224 @ =0x00000934
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x3c
	b _08082262
	.align 2, 0
_08082214: .4byte 0x0000037E
_08082218: .4byte 0x000002E6
_0808221C: .4byte 0x000002E7
_08082220: .4byte 0x00000932
_08082224: .4byte 0x00000934
_08082228:
	strb r2, [r1]
	ldr r1, _080822BC @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	adds r0, #0x14
	strh r0, [r2]
	ldr r2, _080822C0 @ =0x00000932
	adds r1, r4, r2
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _080822C4 @ =0x00000934
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #0x1e
_08082262:
	strh r0, [r1]
	ldr r2, _080822C8 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0808226E:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xe9
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	bne _0808228A
	b _08082456
_0808228A:
	movs r0, #0xcb
	bl PlaySound_082406e0
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080822A4
	b _080823DC
_080822A4:
	adds r0, r4, #0
	bl FUN_08082124
	adds r1, r0, #0
	cmp r1, #0
	beq _080822B2
	b _080823F2
_080822B2:
	ldr r2, _080822CC @ =0x00000404
	adds r0, r4, r2
	strh r1, [r0]
	b _0808239A
	.align 2, 0
_080822BC: .4byte 0x000002E6
_080822C0: .4byte 0x00000932
_080822C4: .4byte 0x00000934
_080822C8: .4byte 0x0000037E
_080822CC: .4byte 0x00000404
_080822D0:
	movs r1, #0xa0
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	ldr r0, _0808232C @ =0x00000404
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #4
	bhi _080822F6
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne _080822F6
	movs r0, #0x94
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080822F6:
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0x1e
	strh r0, [r1]
	ldr r0, _08082330 @ =0x0000095E
	adds r1, r4, r0
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r1, _08082334 @ =0x0000037E
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0x1f
	bhi _08082338
	movs r2, #0x96
	lsls r2, r2, #4
	adds r0, r4, r2
	strh r1, [r0]
	b _08082344
	.align 2, 0
_0808232C: .4byte 0x00000404
_08082330: .4byte 0x0000095E
_08082334: .4byte 0x0000037E
_08082338:
	movs r0, #0x40
	subs r0, r0, r1
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	strh r0, [r1]
_08082344:
	ldr r0, _0808237C @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bls _0808235C
	movs r0, #0
	strh r0, [r1]
_0808235C:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08082384
	movs r0, #0xd8
	bl sound_08240740
	ldr r2, _08082380 @ =0x00000409
	adds r0, r4, r2
	strb r5, [r0]
	b _080823DC
	.align 2, 0
_0808237C: .4byte 0x0000037E
_08082380: .4byte 0x00000409
_08082384:
	adds r0, r4, #0
	bl FUN_08082124
	cmp r0, #0
	bne _08082456
	movs r0, #0xd8
	bl sound_08240740
	ldr r1, _080823A8 @ =0x00000409
	adds r0, r4, r1
	strb r5, [r0]
_0808239A:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl FUN_08080e0c
	b _08082456
	.align 2, 0
_080823A8: .4byte 0x00000409
_080823AC:
	movs r1, #0x80
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	movs r1, #0xeb
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
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
	bne _080823E8
_080823DC:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #4
	bl FUN_08080e0c
	b _08082456
_080823E8:
	adds r0, r4, #0
	bl FUN_08082124
	cmp r0, #0
	beq _08082456
_080823F2:
	movs r0, #0xd8
	bl PlaySound_082406e0
	ldr r2, _08082414 @ =0x00000409
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08082418 @ =0x00000404
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #2
	bl FUN_08080e0c
	b _08082456
	.align 2, 0
_08082414: .4byte 0x00000409
_08082418: .4byte 0x00000404
_0808241C:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08082456
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r1, [r0]
	ldr r2, _0808245C @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _08082460 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_08082456:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808245C: .4byte 0x000002E6
_08082460: .4byte 0x000002E7

	thumb_func_start FUN_08082464
FUN_08082464: @ 0x08082464
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808247C @ =0x000003FE
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08082480
	adds r0, r4, #0
	movs r1, #0x3c
	bl FUN_08080ec8
	b _08082488
	.align 2, 0
_0808247C: .4byte 0x000003FE
_08082480:
	adds r0, r4, #0
	movs r1, #0x3d
	bl FUN_08080ec8
_08082488:
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08082498
FUN_08082498: @ 0x08082498
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _08082520
	adds r0, r4, #0
	movs r1, #0x18
	movs r2, #0
	bl FUN_08080e0c
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080824E4
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r5, _080824DC @ =0x000002E6
	adds r1, r4, r5
	strb r0, [r1]
	ldr r6, _080824E0 @ =0x000002E7
	adds r1, r4, r6
	movs r0, #1
	strb r0, [r1]
	b _080824F4
	.align 2, 0
_080824DC: .4byte 0x000002E6
_080824E0: .4byte 0x000002E7
_080824E4:
	lsrs r1, r1, #0x19
	ldr r2, _08082510 @ =0x000002E6
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _08082514 @ =0x000002E7
	adds r0, r4, r3
	strb r2, [r0]
_080824F4:
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r0, _08082518 @ =0x00000366
	bl sound_08240740
	ldr r0, _0808251C @ =0x0000036A
	bl PlaySound_082406e0
	b _08082666
	.align 2, 0
_08082510: .4byte 0x000002E6
_08082514: .4byte 0x000002E7
_08082518: .4byte 0x00000366
_0808251C: .4byte 0x0000036A
_08082520:
	movs r6, #0xd6
	lsls r6, r6, #1
	adds r5, r4, r6
	ldrh r0, [r5]
	cmp r0, #0
	beq _0808260C
	ldr r1, _0808255C @ =0x00000395
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08082598
	movs r2, #0x2c
	ldrsh r1, [r4, r2]
	movs r3, #0xe6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r2, [r0]
	movs r5, #0
	ldrsh r0, [r2, r5]
	subs r3, r1, r0
	movs r6, #0x30
	ldrsh r1, [r4, r6]
	movs r5, #4
	ldrsh r0, [r2, r5]
	subs r1, r1, r0
	rsbs r0, r3, #0
	cmp r0, #0
	blt _08082560
	asrs r0, r0, #3
	b _08082564
	.align 2, 0
_0808255C: .4byte 0x00000395
_08082560:
	asrs r0, r3, #3
	rsbs r0, r0, #0
_08082564:
	strh r0, [r4, #0x34]
	rsbs r0, r1, #0
	cmp r0, #0
	blt _08082570
	asrs r0, r0, #3
	b _08082574
_08082570:
	asrs r0, r1, #3
	rsbs r0, r0, #0
_08082574:
	strh r0, [r4, #0x38]
	movs r6, #0xf5
	lsls r6, r6, #2
	adds r0, r4, r6
	ldrh r1, [r0]
	cmp r1, #0x55
	bls _080825FA
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080825FA
	ldr r0, _08082594 @ =0x00000191
	bl PlaySound_082406e0
	b _080825FA
	.align 2, 0
_08082594: .4byte 0x00000191
_08082598:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080825C8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldrh r0, [r5]
	muls r0, r1, r0
	cmp r0, #0
	blt _080825CC
	asrs r0, r0, #0xc
	b _080825D2
	.align 2, 0
_080825C8: .4byte 0x085B0A08
_080825CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080825D2:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080825F0
	asrs r0, r0, #0xc
	b _080825F6
_080825F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080825F6:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
_080825FA:
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r2, r4, r5
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _08082666
_0808260C:
	ldr r6, _0808262C @ =0x000004C5
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #3
	bne _08082634
	ldr r1, _08082630 @ =0x000004C7
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08082634
	adds r0, r4, #0
	movs r1, #0x13
	movs r2, #0
	bl FUN_08080e0c
	b _08082666
	.align 2, 0
_0808262C: .4byte 0x000004C5
_08082630: .4byte 0x000004C7
_08082634:
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08082666
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r3, _0808266C @ =0x00000395
	adds r0, r4, r3
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_08080c64
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_08082666:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808266C: .4byte 0x00000395

	thumb_func_start FUN_08082670
FUN_08082670: @ 0x08082670
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x19
	beq _080826D8
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #0
	bl FUN_08080e0c
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080826BC
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r5, _080826B4 @ =0x000002E6
	adds r1, r4, r5
	strb r0, [r1]
	ldr r0, _080826B8 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _080826CC
	.align 2, 0
_080826B4: .4byte 0x000002E6
_080826B8: .4byte 0x000002E7
_080826BC:
	lsrs r1, r1, #0x19
	ldr r2, _080826F0 @ =0x000002E6
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _080826F4 @ =0x000002E7
	adds r0, r4, r3
	strb r2, [r0]
_080826CC:
	ldr r0, _080826F8 @ =0x00000366
	bl sound_08240740
	ldr r0, _080826FC @ =0x0000036B
	bl PlaySound_082406e0
_080826D8:
	ldr r5, _08082700 @ =0x0000037D
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, #4
	bls _080826E4
	b _0808295A
_080826E4:
	lsls r0, r0, #2
	ldr r1, _08082704 @ =_08082708
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080826F0: .4byte 0x000002E6
_080826F4: .4byte 0x000002E7
_080826F8: .4byte 0x00000366
_080826FC: .4byte 0x0000036B
_08082700: .4byte 0x0000037D
_08082704: .4byte _08082708
_08082708: @ jump table
	.4byte _0808271C @ case 0
	.4byte _0808274C @ case 1
	.4byte _0808285C @ case 2
	.4byte _080828E8 @ case 3
	.4byte _0808290C @ case 4
_0808271C:
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r0, _08082748 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _0808273C
	b _0808295A
_0808273C:
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #1
	bl FUN_08080e0c
	b _0808295A
	.align 2, 0
_08082748: .4byte 0x0000037E
_0808274C:
	ldr r1, _080827A0 @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08082760
	ldr r2, _080827A4 @ =0x000003F6
	adds r1, r4, r2
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
_08082760:
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080827A8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080827AC
	asrs r0, r0, #0xc
	b _080827B2
	.align 2, 0
_080827A0: .4byte 0x0000037E
_080827A4: .4byte 0x000003F6
_080827A8: .4byte 0x085B0A08
_080827AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080827B2:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	ldr r1, _080827D4 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080827D8
	asrs r0, r0, #0xc
	b _080827DE
	.align 2, 0
_080827D4: .4byte 0x085B0A08
_080827D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080827DE:
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
	ldr r1, _0808280C @ =0x0000037E
	adds r3, r4, r1
	ldrh r0, [r3]
	cmp r0, #3
	bls _08082818
	ldr r2, _08082810 @ =0x000003F6
	adds r1, r4, r2
	ldrh r2, [r1]
	lsls r0, r0, #3
	cmp r2, r0
	blt _08082814
	subs r0, r2, r0
	b _08082816
	.align 2, 0
_0808280C: .4byte 0x0000037E
_08082810: .4byte 0x000003F6
_08082814:
	movs r0, #0
_08082816:
	strh r0, [r1]
_08082818:
	ldr r3, _08082850 @ =0x0000037E
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	cmp r0, #0x13
	bls _08082830
	b _0808295A
_08082830:
	ldr r0, _08082854 @ =0x000003F6
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0808283C
	b _0808295A
_0808283C:
	strh r0, [r1]
	ldr r0, _08082858 @ =0x0000033A
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #2
	bl FUN_08080e0c
	b _0808295A
	.align 2, 0
_08082850: .4byte 0x0000037E
_08082854: .4byte 0x000003F6
_08082858: .4byte 0x0000033A
_0808285C:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08082890 @ =0x085B0A08
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
	blt _08082894
	asrs r0, r0, #0xc
	b _0808289A
	.align 2, 0
_08082890: .4byte 0x085B0A08
_08082894:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808289A:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080828B8
	asrs r0, r0, #0xc
	b _080828BE
_080828B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080828BE:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	movs r1, #0xe3
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _0808295A
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r1, r4, r5
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #3
	bl FUN_08080e0c
	b _0808295A
_080828E8:
	ldr r0, _08082908 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bls _0808295A
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #4
	bl FUN_08080e0c
	b _0808295A
	.align 2, 0
_08082908: .4byte 0x0000037E
_0808290C:
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _0808295A
	ldr r1, _08082960 @ =0x000003D2
	adds r0, r4, r1
	movs r5, #0
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_08080c64
	ldr r3, _08082964 @ =0x0000046D
	adds r2, r4, r3
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	subs r3, #1
	adds r1, r4, r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _08082950
	strb r5, [r2]
	ldr r5, _08082968 @ =0x00000472
	adds r0, r4, r5
	ldrh r1, [r0]
	ldr r2, _0808296C @ =0x00000474
	adds r0, r4, r2
	strh r1, [r0]
_08082950:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_0808295A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08082960: .4byte 0x000003D2
_08082964: .4byte 0x0000046D
_08082968: .4byte 0x00000472
_0808296C: .4byte 0x00000474

	thumb_func_start FUN_08082970
FUN_08082970: @ 0x08082970
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x12
	beq _08082998
	ldr r0, _080829AC @ =0x00000366
	bl sound_08240740
	ldr r0, _080829B0 @ =0x0000036F
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #0
	bl FUN_08080e0c
_08082998:
	ldr r3, _080829B4 @ =0x0000037D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #1
	beq _08082A20
	cmp r0, #1
	bgt _080829B8
	cmp r0, #0
	beq _080829BE
	b _08082A88
	.align 2, 0
_080829AC: .4byte 0x00000366
_080829B0: .4byte 0x0000036F
_080829B4: .4byte 0x0000037D
_080829B8:
	cmp r0, #2
	beq _08082A70
	b _08082A88
_080829BE:
	movs r1, #0xf9
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08082A88
	movs r6, #0x99
	lsls r6, r6, #4
	adds r1, r5, r6
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08082A14 @ =0x0000098C
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldr r3, _08082A18 @ =0x00000474
	adds r2, r5, r3
	str r2, [sp]
	ldr r6, _08082A1C @ =0x00000472
	adds r2, r5, r6
	movs r3, #0
	ldrsh r2, [r2, r3]
	str r2, [sp, #4]
	movs r2, #0x96
	lsls r2, r2, #1
	str r2, [sp, #8]
	adds r2, #0x50
	str r2, [sp, #0xc]
	movs r2, #1
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #1
	bl FUN_08080e0c
	b _08082A88
	.align 2, 0
_08082A14: .4byte 0x0000098C
_08082A18: .4byte 0x00000474
_08082A1C: .4byte 0x00000472
_08082A20:
	ldr r6, _08082A68 @ =0x00000474
	adds r1, r5, r6
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _08082A88
	ldr r0, _08082A6C @ =0x0000098C
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	movs r6, #0x99
	lsls r6, r6, #4
	adds r2, r5, r6
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	movs r3, #0x96
	lsls r3, r3, #1
	str r3, [sp, #8]
	adds r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #0x7f
	bl FUN_080da9c4
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #2
	bl FUN_08080e0c
	b _08082A88
	.align 2, 0
_08082A68: .4byte 0x00000474
_08082A6C: .4byte 0x0000098C
_08082A70:
	ldr r1, _08082A90 @ =0x000001F7
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08082A88
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_08082A88:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08082A90: .4byte 0x000001F7

	thumb_func_start FUN_08082a94
FUN_08082a94: @ 0x08082A94
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x13
	beq _08082AF4
	ldr r0, _08082B50 @ =0x00000366
	bl sound_08240740
	ldr r0, _08082B54 @ =0x00000369
	bl PlaySound_082406e0
	movs r3, #0x99
	lsls r3, r3, #4
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	ldr r6, _08082B58 @ =0x0000098C
	adds r4, r5, r6
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldr r3, _08082B5C @ =0x00000474
	adds r2, r5, r3
	str r2, [sp]
	ldr r6, _08082B60 @ =0x00000472
	adds r2, r5, r6
	movs r3, #0
	ldrsh r2, [r2, r3]
	str r2, [sp, #4]
	movs r2, #0x96
	lsls r2, r2, #1
	str r2, [sp, #8]
	adds r2, #0x50
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #3
	bl FUN_080da9c4
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0x13
	movs r2, #0
	bl FUN_08080e0c
_08082AF4:
	ldr r6, _08082B64 @ =0x0000037E
	adds r0, r5, r6
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08082B86
	ldr r0, _08082B68 @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r3, #0x2c
	ldrsh r1, [r5, r3]
	subs r0, r0, r1
	movs r6, #0x30
	ldrsh r1, [r2, r6]
	movs r3, #0x30
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	movs r6, #0xba
	lsls r6, r6, #2
	adds r3, r5, r6
	ldrb r2, [r3]
	cmp r1, r2
	beq _08082B74
	adds r0, r2, #0
	subs r0, #8
	subs r0, r1, r0
	movs r1, #7
	ands r0, r1
	cmp r0, #4
	ble _08082B6C
	adds r0, r2, #7
	b _08082B70
	.align 2, 0
_08082B50: .4byte 0x00000366
_08082B54: .4byte 0x00000369
_08082B58: .4byte 0x0000098C
_08082B5C: .4byte 0x00000474
_08082B60: .4byte 0x00000472
_08082B64: .4byte 0x0000037E
_08082B68: .4byte 0x03002BE0
_08082B6C:
	adds r0, r2, #1
	movs r1, #7
_08082B70:
	ands r0, r1
	strb r0, [r3]
_08082B74:
	adds r0, r5, #0
	bl FUN_08080c64
	movs r1, #0xcf
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08080cac
_08082B86:
	ldr r0, _08082BD4 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	movs r3, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _08082BCC
	ldr r1, _08082BD8 @ =0x0000098C
	adds r4, r5, r1
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	movs r6, #0x99
	lsls r6, r6, #4
	adds r2, r5, r6
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	movs r3, #0x96
	lsls r3, r3, #1
	str r3, [sp, #8]
	adds r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #0x7f
	bl FUN_080da9c4
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08080e0c
_08082BCC:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08082BD4: .4byte 0x0000037E
_08082BD8: .4byte 0x0000098C

	thumb_func_start FUN_08082bdc
FUN_08082bdc: @ 0x08082BDC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _08082BF6
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08080e0c
_08082BF6:
	adds r0, r4, #0
	movs r1, #0x1c
	bl FUN_08080ec8
	movs r2, #0x82
	lsls r2, r2, #2
	adds r3, r4, r2
	movs r5, #0
	ldrsh r1, [r3, r5]
	movs r2, #0x2c
	ldrsh r0, [r4, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _08082C14
	rsbs r0, r0, #0
_08082C14:
	adds r6, r0, #0
	movs r5, #0x83
	lsls r5, r5, #2
	adds r2, r4, r5
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r5, #0x30
	ldrsh r0, [r4, r5]
	subs r1, r1, r0
	cmp r1, #0
	bge _08082C2C
	rsbs r1, r1, #0
_08082C2C:
	adds r5, r1, #0
	cmp r6, #0x1f
	bgt _08082C84
	cmp r5, #0x1f
	bgt _08082C84
	ldr r0, _08082C78 @ =0x000003F2
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldrh r0, [r3]
	strh r0, [r4, #0x2c]
	ldrh r0, [r2]
	strh r0, [r4, #0x30]
	ldr r1, _08082C7C @ =0x000001A3
	adds r0, r4, #0
	movs r2, #0x20
	bl FUN_08080cac
	ldr r1, _08082C80 @ =0x00000471
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08080c64
	movs r5, #0x8e
	lsls r5, r5, #3
	adds r0, r4, r5
	ldrb r1, [r0]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08080e0c
	b _08082DA0
	.align 2, 0
_08082C78: .4byte 0x000003F2
_08082C7C: .4byte 0x000001A3
_08082C80: .4byte 0x00000471
_08082C84:
	ldr r0, _08082CAC @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _08082CB0 @ =0x00000127
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #0x18
	strh r0, [r1]
	cmp r6, #0xbf
	bgt _08082C9E
	cmp r5, #0xbf
	ble _08082CB8
_08082C9E:
	ldr r5, _08082CB4 @ =0x000003F2
	adds r1, r4, r5
	ldrb r0, [r1]
	cmp r0, #4
	bhi _08082CC6
	adds r0, #1
	b _08082CC4
	.align 2, 0
_08082CAC: .4byte 0x0000095E
_08082CB0: .4byte 0x00000127
_08082CB4: .4byte 0x000003F2
_08082CB8:
	ldr r0, _08082CDC @ =0x000003F2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08082CC6
	subs r0, #1
_08082CC4:
	strb r0, [r1]
_08082CC6:
	ldr r1, _08082CDC @ =0x000003F2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08082CE0
	adds r0, r4, #0
	movs r1, #3
	bl FUN_08080ec8
	b _08082CEC
	.align 2, 0
_08082CDC: .4byte 0x000003F2
_08082CE0:
	cmp r0, #0
	beq _08082CEC
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08080ec8
_08082CEC:
	movs r2, #0x86
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r2, #0x2c
	ldrsh r0, [r4, r2]
	subs r6, r1, r0
	movs r5, #0x87
	lsls r5, r5, #2
	adds r0, r4, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0x30
	ldrsh r0, [r4, r5]
	subs r5, r1, r0
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_0823785c
	adds r3, r0, #0
	ldr r2, _08082D30 @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08082D34
	asrs r0, r0, #0xc
	b _08082D3A
	.align 2, 0
_08082D30: .4byte 0x085B0A08
_08082D34:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08082D3A:
	strh r0, [r4, #0x34]
	ldr r0, _08082D54 @ =0x085B0A08
	movs r1, #0xff
	ands r1, r3
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08082D58
	asrs r0, r0, #0xc
	b _08082D5E
	.align 2, 0
_08082D54: .4byte 0x085B0A08
_08082D58:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08082D5E:
	strh r0, [r4, #0x38]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08235fd8
	cmp r0, #0
	beq _08082D96
	adds r0, r6, #0
	adds r1, r5, #0
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
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08080c64
_08082D96:
	ldr r1, _08082DA8 @ =0x000001A3
	adds r0, r4, #0
	movs r2, #0x20
	bl FUN_08080cac
_08082DA0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08082DA8: .4byte 0x000001A3

	thumb_func_start FUN_08082dac
FUN_08082dac: @ 0x08082DAC
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #9
	beq _08082DD0
	adds r0, r4, #0
	movs r1, #9
	movs r2, #0
	bl FUN_08080e0c
	ldr r2, _08082DE8 @ =0x00000951
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_08082DD0:
	ldr r3, _08082DEC @ =0x0000037D
	adds r0, r4, r3
	ldrb r2, [r0]
	cmp r2, #1
	bne _08082DDC
	b _08082F30
_08082DDC:
	cmp r2, #1
	bgt _08082DF0
	cmp r2, #0
	beq _08082DFE
	b _08083012
	.align 2, 0
_08082DE8: .4byte 0x00000951
_08082DEC: .4byte 0x0000037D
_08082DF0:
	cmp r2, #2
	bne _08082DF6
	b _08082F84
_08082DF6:
	cmp r2, #3
	bne _08082DFC
	b _08082FE8
_08082DFC:
	b _08083012
_08082DFE:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r3, r4, r0
	ldrb r0, [r3]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _08082E60
	movs r1, #4
	strb r1, [r3]
	ldr r3, _08082E50 @ =0x000002E6
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _08082E54 @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
	movs r3, #0x93
	lsls r3, r3, #4
	adds r2, r4, r3
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	subs r0, #0x14
	strh r0, [r2]
	ldr r0, _08082E58 @ =0x00000932
	adds r1, r4, r0
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r0, _08082E5C @ =0x00000934
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x3c
	b _08082E9A
	.align 2, 0
_08082E50: .4byte 0x000002E6
_08082E54: .4byte 0x000002E7
_08082E58: .4byte 0x00000932
_08082E5C: .4byte 0x00000934
_08082E60:
	strb r2, [r3]
	ldr r1, _08082EBC @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	ldr r3, _08082EC0 @ =0x000002E7
	adds r0, r4, r3
	strb r2, [r0]
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	adds r0, #0x14
	strh r0, [r2]
	ldr r2, _08082EC4 @ =0x00000932
	adds r1, r4, r2
	movs r3, #0xa5
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r3, _08082EC8 @ =0x00000934
	adds r1, r4, r3
	ldrh r0, [r1]
	subs r0, #0x14
_08082E9A:
	strh r0, [r1]
	movs r1, #0xcf
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _08082ECC
	ldr r2, _08082EBC @ =0x000002E6
	adds r1, r4, r2
	movs r0, #1
	b _08082ED2
	.align 2, 0
_08082EBC: .4byte 0x000002E6
_08082EC0: .4byte 0x000002E7
_08082EC4: .4byte 0x00000932
_08082EC8: .4byte 0x00000934
_08082ECC:
	ldr r3, _08082F1C @ =0x000002E6
	adds r1, r4, r3
	movs r0, #0
_08082ED2:
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #9
	movs r2, #1
	bl FUN_08080e0c
	ldr r0, _08082F20 @ =0x0000095E
	adds r1, r4, r0
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #2
	strh r0, [r1]
	ldr r0, _08082F24 @ =0x0000036E
	bl PlaySound_082406e0
	adds r1, r4, #0
	adds r1, #0x2c
	movs r3, #0x93
	lsls r3, r3, #4
	adds r2, r4, r3
	ldr r3, _08082F28 @ =0x000003BA
	adds r0, r4, r3
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl FUN_080abd14
	ldr r0, _08082F2C @ =0x00000477
	adds r1, r4, r0
	movs r0, #0x3c
	strb r0, [r1]
	b _08083012
	.align 2, 0
_08082F1C: .4byte 0x000002E6
_08082F20: .4byte 0x0000095E
_08082F24: .4byte 0x0000036E
_08082F28: .4byte 0x000003BA
_08082F2C: .4byte 0x00000477
_08082F30:
	ldr r2, _08082F80 @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _08082F52
	movs r0, #0x20
	strh r0, [r1]
_08082F52:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xe9
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08083012
	movs r0, #0xcb
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #9
	movs r2, #2
	bl FUN_08080e0c
	b _08083012
	.align 2, 0
_08082F80: .4byte 0x0000095E
_08082F84:
	movs r1, #0xeb
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r2, _08082FDC @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	ldr r3, _08082FE0 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _08082FB6
	movs r0, #0x20
	strh r0, [r1]
_08082FB6:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x1e
	strh r0, [r1]
	ldr r3, _08082FE4 @ =0x0000037E
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ands r0, r2
	cmp r0, #0x17
	bls _08083012
	adds r0, r4, #0
	movs r1, #9
	movs r2, #3
	bl FUN_08080e0c
	b _08083012
	.align 2, 0
_08082FDC: .4byte 0x0000095E
_08082FE0: .4byte 0x0000FFFF
_08082FE4: .4byte 0x0000037E
_08082FE8:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08083012
	adds r0, r4, #0
	bl FUN_08080c64
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_08083012:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808301c
FUN_0808301c: @ 0x0808301C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #8
	beq _08083038
	adds r0, r5, #0
	movs r1, #8
	movs r2, #0
	bl FUN_08080e0c
_08083038:
	ldr r2, _08083050 @ =0x00000951
	adds r0, r5, r2
	movs r1, #9
	strb r1, [r0]
	ldr r3, _08083054 @ =0x0000037D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08083058
	cmp r0, #1
	beq _08083076
	b _080831CC
	.align 2, 0
_08083050: .4byte 0x00000951
_08083054: .4byte 0x0000037D
_08083058:
	movs r1, #0xef
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	bne _0808306A
	b _080831CC
_0808306A:
	adds r0, r5, #0
	movs r1, #8
	movs r2, #1
	bl FUN_08080e0c
	b _080831CC
_08083076:
	bl FUN_08084754
	ldr r1, _08083098 @ =0x0000095E
	adds r0, r5, r1
	movs r1, #0x91
	lsls r1, r1, #1
	strh r1, [r0]
	ldr r2, _0808309C @ =0x0000037E
	adds r0, r5, r2
	ldrh r1, [r0]
	cmp r1, #0x1f
	bhi _080830A0
	movs r3, #0x96
	lsls r3, r3, #4
	adds r0, r5, r3
	strh r1, [r0]
	b _080830AC
	.align 2, 0
_08083098: .4byte 0x0000095E
_0808309C: .4byte 0x0000037E
_080830A0:
	movs r0, #0x40
	subs r0, r0, r1
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	strh r0, [r1]
_080830AC:
	ldr r3, _08083150 @ =0x0000037E
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bls _080830C2
	movs r0, #0
	strh r0, [r1]
_080830C2:
	ldr r1, _08083154 @ =0x000001E3
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08080cac
	bl FUN_080230c4
	adds r6, r0, #0
	movs r0, #0
	ldrsh r1, [r6, r0]
	movs r2, #0x2c
	ldrsh r0, [r5, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _080830E2
	rsbs r0, r0, #0
_080830E2:
	adds r3, r0, #0
	movs r0, #4
	ldrsh r1, [r6, r0]
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _080830F4
	rsbs r1, r1, #0
_080830F4:
	adds r2, r1, #0
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	cmp r3, #0xbf
	bgt _0808310A
	cmp r2, #0xbf
	ble _08083112
_0808310A:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bls _080831CC
_08083112:
	mov r4, sp
	mov r0, sp
	bl FUN_08084734
	mov r0, sp
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0
	ldrsh r0, [r6, r3]
	subs r3, r1, r0
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r2, #4
	ldrsh r0, [r6, r2]
	subs r2, r1, r0
	adds r0, r3, #0
	adds r1, r2, #0
	bl FUN_0823785c
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	movs r6, #0
	cmp r0, #1
	beq _08083162
	cmp r0, #1
	bgt _08083158
	cmp r0, #0
	beq _0808315E
	b _08083168
	.align 2, 0
_08083150: .4byte 0x0000037E
_08083154: .4byte 0x000001E3
_08083158:
	cmp r0, #2
	beq _08083166
	b _08083168
_0808315E:
	movs r6, #3
	b _08083168
_08083162:
	movs r6, #1
	b _08083168
_08083166:
	movs r6, #2
_08083168:
	ldr r3, _080831D4 @ =0x000004A6
	adds r7, r5, r3
	ldrb r0, [r7]
	adds r0, #3
	movs r1, #3
	ands r0, r1
	cmp r0, r6
	beq _080831C2
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x2c
	lsls r4, r6, #3
	subs r3, #0x2e
	adds r2, r4, r3
	adds r2, r5, r2
	bl FUN_08235f40
	cmp r0, #0
	beq _080831C2
	movs r0, #0x8e
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r0, #8
	strb r0, [r1]
	adds r0, r5, r4
	ldr r1, _080831D8 @ =0x0000047E
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r2, _080831DC @ =0x00000471
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r6, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r7]
	movs r0, #0x1e
	bl FUN_08084798
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08080e0c
_080831C2:
	movs r3, #0xe3
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r0, #0
	strh r0, [r1]
_080831CC:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080831D4: .4byte 0x000004A6
_080831D8: .4byte 0x0000047E
_080831DC: .4byte 0x00000471

	thumb_func_start FUN_080831e0
FUN_080831e0: @ 0x080831E0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	mov ip, r1
	adds r5, r2, #0
	adds r6, r3, #0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r2, _08083224 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _08083228
	asrs r1, r0, #0xc
	b _0808322E
	.align 2, 0
_08083224: .4byte 0x085B0A08
_08083228:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808322E:
	ldrh r0, [r4, #0x2c]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldrh r1, [r4, #0x2e]
	adds r1, #0xe6
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #0x14]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _08083254
	asrs r0, r0, #0xc
	b _0808325A
_08083254:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808325A:
	ldrh r1, [r4, #0x30]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080832A4 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	str r5, [sp]
	ldr r7, _080832A8 @ =0x00000A7A
	adds r0, r4, r7
	ldrh r0, [r0]
	str r0, [sp, #4]
	ldr r1, _080832AC @ =0x00000A7C
	adds r0, r4, r1
	ldrh r0, [r0]
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	ldr r2, _080832B0 @ =0x00000A7E
	adds r0, r4, r2
	ldrh r0, [r0]
	str r0, [sp, #0x10]
	add r0, sp, #0x14
	adds r1, r3, #0
	movs r2, #0x20
	mov r3, ip
	bl FUN_080cbabc
	ldr r0, _080832B4 @ =0x00000367
	bl PlaySound_082406e0
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080832A4: .4byte 0xFFFF0000
_080832A8: .4byte 0x00000A7A
_080832AC: .4byte 0x00000A7C
_080832B0: .4byte 0x00000A7E
_080832B4: .4byte 0x00000367

	thumb_func_start FUN_080832b8
FUN_080832b8: @ 0x080832B8
	push {r4, r5, lr}
	sub sp, #0x18
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _080832D4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	bl FUN_08080e0c
_080832D4:
	ldr r2, _080832F4 @ =0x00000951
	adds r0, r4, r2
	movs r1, #9
	strb r1, [r0]
	ldr r3, _080832F8 @ =0x0000037D
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #7
	bls _080832E8
	b _080835CE
_080832E8:
	lsls r0, r0, #2
	ldr r1, _080832FC @ =_08083300
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080832F4: .4byte 0x00000951
_080832F8: .4byte 0x0000037D
_080832FC: .4byte _08083300
_08083300: @ jump table
	.4byte _08083320 @ case 0
	.4byte _0808337C @ case 1
	.4byte _080833E0 @ case 2
	.4byte _080835CE @ case 3
	.4byte _080835CE @ case 4
	.4byte _08083460 @ case 5
	.4byte _08083510 @ case 6
	.4byte _08083540 @ case 7
_08083320:
	movs r1, #0xef
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	bne _08083332
	b _080835CE
_08083332:
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08080e0c
	ldr r0, _08083368 @ =0x0000046E
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _0808336C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08083370 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08083374 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	adds r0, #2
	ldr r2, _08083378 @ =0x0000046F
	adds r1, r4, r2
	strb r0, [r1]
	b _080835CE
	.align 2, 0
_08083368: .4byte 0x0000046E
_0808336C: .4byte 0x030046B8
_08083370: .4byte 0x000003FF
_08083374: .4byte 0x0203B400
_08083378: .4byte 0x0000046F
_0808337C:
	ldr r3, _080833BC @ =0x0000037E
	adds r5, r4, r3
	ldrh r0, [r5]
	cmp r0, #0
	bne _0808338C
	ldr r0, _080833C0 @ =0x000001F7
	bl PlaySound_082406e0
_0808338C:
	ldr r1, _080833C4 @ =0x000001E3
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _080833A6
	b _080835CE
_080833A6:
	bl FUN_080298dc
	cmp r0, #0
	beq _080833C8
	adds r0, r4, #0
	movs r1, #3
	movs r2, #2
	bl FUN_08080e0c
	b _080835CE
	.align 2, 0
_080833BC: .4byte 0x0000037E
_080833C0: .4byte 0x000001F7
_080833C4: .4byte 0x000001E3
_080833C8:
	adds r0, r4, #0
	movs r1, #1
	movs r2, #6
	movs r3, #2
	bl FUN_080831e0
	adds r0, r4, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08080e0c
	b _080835CE
_080833E0:
	ldr r1, _0808343C @ =0x000001E3
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r0, _08083440 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _08083448
	add r2, sp, #8
	adds r0, r4, #0
	mov r1, sp
	bl FUN_08081de0
	cmp r0, #0
	bne _0808340C
	b _080835CE
_0808340C:
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x2c
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	bne _08083422
	b _080835CE
_08083422:
	movs r2, #0x8e
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #3
	strb r0, [r1]
	ldr r1, [sp, #8]
	ldr r3, _08083444 @ =0x00000471
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #2
	b _08083508
	.align 2, 0
_0808343C: .4byte 0x000001E3
_08083440: .4byte 0x0000037E
_08083444: .4byte 0x00000471
_08083448:
	ldr r0, _0808345C @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _0808345A
	b _080835CE
_0808345A:
	b _08083504
	.align 2, 0
_0808345C: .4byte 0x03002BE0
_08083460:
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r2, _080834A4 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08083480
	b _080835CE
_08083480:
	ldr r3, _080834A8 @ =0x0000046E
	adds r0, r4, r3
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	adds r2, #0xf1
	adds r0, r4, r2
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrb r0, [r0]
	cmp r1, r0
	bhs _080834AC
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08080e0c
	b _080835CE
	.align 2, 0
_080834A4: .4byte 0x0000037E
_080834A8: .4byte 0x0000046E
_080834AC:
	ldr r0, _080834FC @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _08083504
	add r5, sp, #0xc
	add r2, sp, #0x14
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08081de0
	cmp r0, #0
	bne _080834CE
	b _080835CE
_080834CE:
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x2c
	adds r2, r5, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080835CE
	movs r2, #0x8e
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #3
	strb r0, [r1]
	ldr r1, [sp, #0x14]
	ldr r3, _08083500 @ =0x00000471
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #2
	b _08083508
	.align 2, 0
_080834FC: .4byte 0x03002BE0
_08083500: .4byte 0x00000471
_08083504:
	adds r0, r4, #0
	movs r1, #3
_08083508:
	movs r2, #6
	bl FUN_08080e0c
	b _080835CE
_08083510:
	ldr r1, _08083538 @ =0x000001E3
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r0, _0808353C @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bls _080835CE
	adds r0, r4, #0
	movs r1, #3
	movs r2, #7
	bl FUN_08080e0c
	b _080835CE
	.align 2, 0
_08083538: .4byte 0x000001E3
_0808353C: .4byte 0x0000037E
_08083540:
	movs r1, #0xef
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r2, _080835B4 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _080835CE
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r4, r3
	adds r1, r4, #0
	adds r1, #0x2c
	ldr r2, _080835B8 @ =0x000004A6
	adds r5, r4, r2
	ldrb r2, [r5]
	lsls r2, r2, #3
	movs r3, #0x8f
	lsls r3, r3, #3
	adds r2, r2, r3
	adds r2, r4, r2
	bl FUN_08235f40
	cmp r0, #0
	beq _080835C4
	movs r0, #0x8e
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #8
	strb r0, [r1]
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r0, r4, r0
	ldr r1, _080835BC @ =0x0000047E
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r2, _080835C0 @ =0x00000471
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08080e0c
	ldrb r0, [r5]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r5]
	b _080835CE
	.align 2, 0
_080835B4: .4byte 0x0000037E
_080835B8: .4byte 0x000004A6
_080835BC: .4byte 0x0000047E
_080835C0: .4byte 0x00000471
_080835C4:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_080835CE:
	add sp, #0x18
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080835d8
FUN_080835d8: @ 0x080835D8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x28
	adds r7, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0x14
	beq _080835F8
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #0
	bl FUN_08080e0c
_080835F8:
	ldr r2, _08083638 @ =0x00000951
	adds r0, r7, r2
	movs r1, #9
	strb r1, [r0]
	ldr r3, _0808363C @ =0x000003E6
	adds r2, r7, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _0808367E
	movs r4, #0xfa
	lsls r4, r4, #2
	adds r0, r7, r4
	ldrh r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldrh r3, [r2]
	ldr r2, _08083640 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	muls r0, r3, r0
	cmp r0, #0
	blt _08083644
	asrs r0, r0, #0xc
	b _0808364A
	.align 2, 0
_08083638: .4byte 0x00000951
_0808363C: .4byte 0x000003E6
_08083640: .4byte 0x085B0A08
_08083644:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808364A:
	strh r0, [r7, #0x34]
	ldr r1, _08083664 @ =0x000003E6
	adds r0, r7, r1
	ldrh r1, [r0]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _08083668
	asrs r0, r0, #0xc
	b _0808366E
	.align 2, 0
_08083664: .4byte 0x000003E6
_08083668:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808366E:
	strh r0, [r7, #0x38]
	ldr r3, _08083698 @ =0x000003E6
	adds r2, r7, r3
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
_0808367E:
	ldr r4, _0808369C @ =0x0000037D
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #6
	bls _0808368C
	bl _08083E9C
_0808368C:
	lsls r0, r0, #2
	ldr r1, _080836A0 @ =_080836A4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08083698: .4byte 0x000003E6
_0808369C: .4byte 0x0000037D
_080836A0: .4byte _080836A4
_080836A4: @ jump table
	.4byte _080836C0 @ case 0
	.4byte _080836EC @ case 1
	.4byte _08083774 @ case 2
	.4byte _08083800 @ case 3
	.4byte _0808388C @ case 4
	.4byte _08083E44 @ case 5
	.4byte _08083E74 @ case 6
_080836C0:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	movs r1, #0xef
	lsls r1, r1, #1
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	bne _080836DE
	bl _08083E9C
_080836DE:
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #1
	bl FUN_08080e0c
	bl _08083E9C
_080836EC:
	ldr r6, _08083754 @ =0x0000037E
	adds r4, r7, r6
	ldrh r0, [r4]
	cmp r0, #0
	bne _080836FC
	ldr r0, _08083758 @ =0x000001F7
	bl PlaySound_082406e0
_080836FC:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	ldr r1, _0808375C @ =0x000001E3
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08083720
	b _08083E9C
_08083720:
	ldr r0, _08083760 @ =0x00000402
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _08083764 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08083768 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0808376C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	ldr r2, _08083770 @ =0x00000403
	adds r1, r7, r2
	strb r0, [r1]
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #2
	bl FUN_08080e0c
	b _08083E9C
	.align 2, 0
_08083754: .4byte 0x0000037E
_08083758: .4byte 0x000001F7
_0808375C: .4byte 0x000001E3
_08083760: .4byte 0x00000402
_08083764: .4byte 0x030046B8
_08083768: .4byte 0x000003FF
_0808376C: .4byte 0x0203B400
_08083770: .4byte 0x00000403
_08083774:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	ldr r1, _080837C0 @ =0x000001E3
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r3, _080837C4 @ =0x0000037E
	adds r1, r7, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2c
	bhi _0808379C
	b _08083E9C
_0808379C:
	ldr r6, _080837C8 @ =0x00000402
	adds r4, r7, r6
	ldr r0, _080837CC @ =0x00000403
	adds r1, r7, r0
	ldrb r0, [r4]
	ldrb r1, [r1]
	cmp r0, r1
	blo _080837D4
	ldr r0, _080837D0 @ =0x000002E9
	bl PlaySound_082406e0
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #3
	bl FUN_08080e0c
	b _080837E4
	.align 2, 0
_080837C0: .4byte 0x000001E3
_080837C4: .4byte 0x0000037E
_080837C8: .4byte 0x00000402
_080837CC: .4byte 0x00000403
_080837D0: .4byte 0x000002E9
_080837D4:
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #2
	bl FUN_08080e0c
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_080837E4:
	ldr r2, _080837FC @ =0x0000095E
	adds r1, r7, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r7, r3
	movs r0, #0x20
	strh r0, [r1]
	b _08083E9C
	.align 2, 0
_080837FC: .4byte 0x0000095E
_08083800:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	ldr r1, _08083874 @ =0x000001E3
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r4, _08083878 @ =0x0000037E
	adds r1, r7, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _08083828
	b _08083E9C
_08083828:
	ldr r0, _0808387C @ =0x00000366
	bl PlaySound_082406e0
	movs r6, #0xba
	lsls r6, r6, #2
	adds r2, r7, r6
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	ldr r3, _08083880 @ =0x00000A8A
	adds r1, r7, r3
	strh r0, [r1]
	ldr r4, _08083884 @ =0x000004A4
	adds r1, r7, r4
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r2]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	ldr r6, _08083888 @ =0x000004A7
	adds r1, r7, r6
	strb r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #2
	adds r0, r7, r1
	bl FUN_08084734
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #4
	bl FUN_08080e0c
	b _08083E9C
	.align 2, 0
_08083874: .4byte 0x000001E3
_08083878: .4byte 0x0000037E
_0808387C: .4byte 0x00000366
_08083880: .4byte 0x00000A8A
_08083884: .4byte 0x000004A4
_08083888: .4byte 0x000004A7
_0808388C:
	ldr r2, _080838F8 @ =0x000003E6
	adds r1, r7, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r7, #0
	movs r1, #0x80
	bl FUN_08080ec8
	movs r3, #0xde
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080838AE
	b _08083B48
_080838AE:
	movs r6, #0
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, sp, #8
	ldrh r1, [r0]
	adds r1, #0x23
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080838FC @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	add r5, sp, #8
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080838F4
	cmp r1, #0
	blt _080838F4
	ldr r0, _08083900 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080838F4
	ldr r0, _08083904 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08083908
_080838F4:
	movs r4, #0
	b _08083916
	.align 2, 0
_080838F8: .4byte 0x000003E6
_080838FC: .4byte 0xFFFF0000
_08083900: .4byte 0x030046A8
_08083904: .4byte 0x030046AC
_08083908:
	ldr r0, _08083928 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08083916:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0808392C
	adds r0, #4
	b _08083938
	.align 2, 0
_08083928: .4byte 0x030046A4
_0808392C:
	ldr r0, _0808394C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08083938:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08083950
	cmp r2, #2
	beq _08083954
	b _08083958
	.align 2, 0
_0808394C: .4byte 0x030046A4
_08083950:
	ldrb r0, [r5, #4]
	b _08083956
_08083954:
	ldrb r0, [r5]
_08083956:
	subs r1, r1, r0
_08083958:
	movs r4, #0x2e
	ldrsh r0, [r7, r4]
	cmp r1, r0
	bne _080839FA
	add r0, sp, #8
	ldrh r0, [r0]
	subs r0, #0x46
	add r1, sp, #8
	strh r0, [r1]
	adds r5, r1, #0
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0808398E
	cmp r1, #0
	blt _0808398E
	ldr r0, _08083994 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0808398E
	ldr r0, _08083998 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0808399C
_0808398E:
	movs r4, #0
	b _080839AA
	.align 2, 0
_08083994: .4byte 0x030046A8
_08083998: .4byte 0x030046AC
_0808399C:
	ldr r0, _080839BC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080839AA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080839C0
	adds r0, #4
	b _080839CC
	.align 2, 0
_080839BC: .4byte 0x030046A4
_080839C0:
	ldr r0, _080839E0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080839CC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080839E4
	cmp r2, #2
	beq _080839E8
	b _080839EC
	.align 2, 0
_080839E0: .4byte 0x030046A4
_080839E4:
	ldrb r0, [r5, #4]
	b _080839EA
_080839E8:
	ldrb r0, [r5]
_080839EA:
	subs r1, r1, r0
_080839EC:
	movs r2, #0x2e
	ldrsh r0, [r7, r2]
	cmp r1, r0
	beq _080839F6
	movs r6, #1
_080839F6:
	cmp r6, #0
	beq _08083A0A
_080839FA:
	ldr r3, _08083A44 @ =0x000004A7
	adds r1, r7, r3
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	movs r0, #0x80
	subs r0, r0, r2
	strb r0, [r1]
_08083A0A:
	movs r6, #0
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, sp, #8
	ldrh r1, [r0, #4]
	adds r1, #0x23
	strh r1, [r0, #4]
	adds r5, r0, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08083A40
	cmp r1, #0
	blt _08083A40
	ldr r0, _08083A48 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08083A40
	ldr r0, _08083A4C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08083A50
_08083A40:
	movs r4, #0
	b _08083A5E
	.align 2, 0
_08083A44: .4byte 0x000004A7
_08083A48: .4byte 0x030046A8
_08083A4C: .4byte 0x030046AC
_08083A50:
	ldr r0, _08083A70 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08083A5E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08083A74
	adds r0, #4
	b _08083A80
	.align 2, 0
_08083A70: .4byte 0x030046A4
_08083A74:
	ldr r0, _08083A94 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08083A80:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08083A98
	cmp r2, #2
	beq _08083A9C
	b _08083AA0
	.align 2, 0
_08083A94: .4byte 0x030046A4
_08083A98:
	ldrb r0, [r5, #4]
	b _08083A9E
_08083A9C:
	ldrb r0, [r5]
_08083A9E:
	subs r1, r1, r0
_08083AA0:
	movs r4, #0x2e
	ldrsh r0, [r7, r4]
	cmp r1, r0
	bne _08083B3E
	add r0, sp, #8
	ldrh r1, [r0, #4]
	subs r1, #0x46
	strh r1, [r0, #4]
	adds r5, r0, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08083AD4
	cmp r1, #0
	blt _08083AD4
	ldr r0, _08083AD8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08083AD4
	ldr r0, _08083ADC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08083AE0
_08083AD4:
	movs r4, #0
	b _08083AEE
	.align 2, 0
_08083AD8: .4byte 0x030046A8
_08083ADC: .4byte 0x030046AC
_08083AE0:
	ldr r0, _08083B00 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08083AEE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08083B04
	adds r0, #4
	b _08083B10
	.align 2, 0
_08083B00: .4byte 0x030046A4
_08083B04:
	ldr r0, _08083B24 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08083B10:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08083B28
	cmp r2, #2
	beq _08083B2C
	b _08083B30
	.align 2, 0
_08083B24: .4byte 0x030046A4
_08083B28:
	ldrb r0, [r5, #4]
	b _08083B2E
_08083B2C:
	ldrb r0, [r5]
_08083B2E:
	subs r1, r1, r0
_08083B30:
	movs r2, #0x2e
	ldrsh r0, [r7, r2]
	cmp r1, r0
	beq _08083B3A
	movs r6, #1
_08083B3A:
	cmp r6, #0
	beq _08083B48
_08083B3E:
	ldr r3, _08083BE0 @ =0x000004A7
	adds r1, r7, r3
	ldrb r0, [r1]
	rsbs r0, r0, #0
	strb r0, [r1]
_08083B48:
	ldr r4, _08083BE4 @ =0x0000037E
	adds r0, r7, r4
	ldrh r1, [r0]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, #0
	bne _08083BA2
	movs r6, #0xec
	lsls r6, r6, #2
	adds r4, r7, r6
	adds r0, r4, #0
	bl FUN_08084734
	ldr r0, _08083BE8 @ =0x0203B400
	mov r8, r0
	ldr r1, _08083BEC @ =0x030046B8
	mov ip, r1
	ldr r1, [r1]
	adds r1, #1
	ldr r3, _08083BF0 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	ldrh r0, [r4]
	subs r0, #0xff
	ldr r6, _08083BF4 @ =0x000001FF
	adds r5, r6, #0
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r4]
	adds r1, #1
	ands r1, r3
	mov r0, ip
	str r1, [r0]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	subs r3, #0x4b
	adds r2, r7, r3
	ldrh r0, [r2]
	subs r0, #0xff
	ands r1, r5
	adds r0, r0, r1
	strh r0, [r2]
_08083BA2:
	movs r4, #0xec
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r6, #0
	ldrsh r0, [r0, r6]
	movs r2, #0x2c
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	movs r3, #0xed
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r4, #0
	ldrsh r1, [r1, r4]
	movs r6, #0x30
	ldrsh r2, [r7, r6]
	subs r1, r1, r2
	bl FUN_0823785c
	ldr r1, _08083BE0 @ =0x000004A7
	adds r3, r7, r1
	ldrb r2, [r3]
	subs r0, r0, r2
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r0, r4
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0x7f
	bgt _08083BF8
	adds r0, r2, #2
	b _08083BFC
	.align 2, 0
_08083BE0: .4byte 0x000004A7
_08083BE4: .4byte 0x0000037E
_08083BE8: .4byte 0x0203B400
_08083BEC: .4byte 0x030046B8
_08083BF0: .4byte 0x000003FF
_08083BF4: .4byte 0x000001FF
_08083BF8:
	adds r0, r2, #0
	adds r0, #0xfe
_08083BFC:
	strb r0, [r3]
	adds r0, r1, #0
	subs r0, #0x40
	cmp r0, #0x80
	bls _08083C20
	ldr r6, _08083C1C @ =0x000004A4
	adds r1, r7, r6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _08083C36
	movs r0, #0x20
	b _08083C34
	.align 2, 0
_08083C1C: .4byte 0x000004A4
_08083C20:
	adds r0, r1, #0
	subs r0, #0x61
	cmp r0, #0x3e
	bhi _08083C36
	ldr r0, _08083C58 @ =0x000004A4
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08083C36
	subs r0, #1
_08083C34:
	strh r0, [r1]
_08083C36:
	ldr r2, _08083C5C @ =0x085B0A08
	ldr r1, _08083C60 @ =0x000004A7
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #3
	cmp r0, #0
	blt _08083C64
	asrs r0, r0, #0xc
	b _08083C6A
	.align 2, 0
_08083C58: .4byte 0x000004A4
_08083C5C: .4byte 0x085B0A08
_08083C60: .4byte 0x000004A7
_08083C64:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08083C6A:
	strh r0, [r7, #0x34]
	ldr r1, _08083C88 @ =0x085B0A08
	ldr r3, _08083C8C @ =0x000004A7
	adds r0, r7, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #3
	cmp r0, #0
	blt _08083C90
	asrs r0, r0, #0xc
	b _08083C96
	.align 2, 0
_08083C88: .4byte 0x085B0A08
_08083C8C: .4byte 0x000004A7
_08083C90:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08083C96:
	strh r0, [r7, #0x38]
	ldr r6, _08083D0C @ =0x00000A8A
	adds r5, r7, r6
	ldrh r0, [r5]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	strh r0, [r5]
	ldr r0, _08083D10 @ =0x000009E4
	adds r2, r7, r0
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _08083D14 @ =0x000009E6
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #0xe6
	strh r0, [r1]
	ldrh r1, [r5]
	ldr r3, _08083D18 @ =0x000009CE
	adds r0, r7, r3
	strb r1, [r0]
	ldrh r1, [r5]
	ldr r0, _08083D1C @ =0x0000010F
	subs r0, r0, r1
	movs r4, #0xff
	ands r0, r4
	asrs r0, r0, #5
	movs r6, #0xba
	lsls r6, r6, #2
	adds r1, r7, r6
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_08080c64
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldrh r1, [r5]
	movs r0, #0xd0
	lsls r0, r0, #1
	subs r5, r0, r1
	ands r5, r4
	ldr r1, _08083D20 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xaa
	muls r0, r1, r0
	cmp r0, #0
	blt _08083D24
	asrs r1, r0, #0xc
	b _08083D2A
	.align 2, 0
_08083D0C: .4byte 0x00000A8A
_08083D10: .4byte 0x000009E4
_08083D14: .4byte 0x000009E6
_08083D18: .4byte 0x000009CE
_08083D1C: .4byte 0x0000010F
_08083D20: .4byte 0x085B0A08
_08083D24:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08083D2A:
	add r3, sp, #0x10
	ldrh r0, [r3]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08083D60 @ =0xFFFF0000
	ldr r2, [sp, #0x10]
	ands r2, r1
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0xe6
	lsls r1, r1, #0x10
	ldr r0, _08083D64 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r1, _08083D68 @ =0x085B0A08
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0xaa
	muls r0, r1, r0
	cmp r0, #0
	blt _08083D6C
	asrs r0, r0, #0xc
	b _08083D72
	.align 2, 0
_08083D60: .4byte 0xFFFF0000
_08083D64: .4byte 0x0000FFFF
_08083D68: .4byte 0x085B0A08
_08083D6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08083D72:
	ldrh r1, [r3, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r6, _08083E2C @ =0xFFFF0000
	ldr r0, [r3, #4]
	ands r0, r6
	orrs r0, r1
	str r0, [r3, #4]
	movs r0, #0xa1
	lsls r0, r0, #4
	adds r4, r7, r0
	adds r0, r4, #0
	adds r1, r3, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _08083E30 @ =0x00000A52
	adds r0, r7, r1
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_08236400
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r2, _08083E34 @ =0x0000037E
	adds r4, r7, r2
	ldrh r0, [r4]
	movs r1, #3
	ands r1, r0
	cmp r1, #0
	bne _08083DEE
	ldr r2, _08083E38 @ =0x0000FFFF
	str r1, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r6
	str r0, [r1, #4]
	ldr r0, [sp, #0x20]
	ands r0, r6
	movs r3, #0x20
	orrs r0, r3
	ands r0, r2
	str r0, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r6
	orrs r0, r3
	str r0, [r2, #4]
	adds r0, r7, #0
	adds r0, #0x2c
	movs r3, #2
	str r3, [sp]
	movs r3, #4
	str r3, [sp, #4]
	movs r3, #1
	bl FUN_080dbcec
_08083DEE:
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08083E00
	movs r0, #0x81
	lsls r0, r0, #2
	bl PlaySound_082406e0
_08083E00:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08083E3C @ =0x00000403
	adds r1, r7, r3
	ldrb r1, [r1]
	adds r1, #1
	lsls r1, r1, #5
	cmp r0, r1
	blt _08083E9C
	ldr r0, _08083E40 @ =0x00000366
	bl sound_08240740
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #5
	bl FUN_08080e0c
	b _08083E9C
	.align 2, 0
_08083E2C: .4byte 0xFFFF0000
_08083E30: .4byte 0x00000A52
_08083E34: .4byte 0x0000037E
_08083E38: .4byte 0x0000FFFF
_08083E3C: .4byte 0x00000403
_08083E40: .4byte 0x00000366
_08083E44:
	ldr r1, _08083E6C @ =0x000001E3
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r4, _08083E70 @ =0x0000037E
	adds r1, r7, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _08083E9C
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #6
	bl FUN_08080e0c
	b _08083E9C
	.align 2, 0
_08083E6C: .4byte 0x000001E3
_08083E70: .4byte 0x0000037E
_08083E74:
	movs r1, #0xef
	lsls r1, r1, #1
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r6, _08083EA8 @ =0x0000037E
	adds r1, r7, r6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _08083E9C
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_08083E9C:
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08083EA8: .4byte 0x0000037E

	thumb_func_start FUN_08083eac
FUN_08083eac: @ 0x08083EAC
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r6, _08083EE8 @ =0x03002BF0
	ldrh r0, [r6]
	cmp r0, #0
	beq _08083ECC
	ldr r0, _08083EEC @ =0x0000036A
	bl PlaySound_082406e0
	ldr r1, _08083EF0 @ =0x00000472
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _08083EF4 @ =0x00000474
	adds r0, r4, r2
	strh r1, [r0]
_08083ECC:
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r3, r4, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _08083EFC
	ldr r1, _08083EF8 @ =0x000003D2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08083F3C
	movs r0, #0x19
	b _08084068
	.align 2, 0
_08083EE8: .4byte 0x03002BF0
_08083EEC: .4byte 0x0000036A
_08083EF0: .4byte 0x00000472
_08083EF4: .4byte 0x00000474
_08083EF8: .4byte 0x000003D2
_08083EFC:
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r5, [r0]
	adds r0, r5, #0
	subs r0, #0x18
	cmp r0, #1
	bls _08083F66
	cmp r5, #0x15
	beq _08083F66
	ldrh r0, [r6]
	cmp r0, #0
	beq _08083F48
	adds r2, r4, #0
	adds r2, #0x90
	ldr r0, [r2]
	ldr r1, _08083F40 @ =0xFFFFF9FE
	ands r0, r1
	str r0, [r2]
	movs r1, #0
	movs r0, #0x32
	strh r0, [r3]
	ldr r2, _08083F44 @ =0x000003D2
	adds r0, r4, r2
	strb r1, [r0]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
_08083F3C:
	movs r0, #0x18
	b _08084068
	.align 2, 0
_08083F40: .4byte 0xFFFFF9FE
_08083F44: .4byte 0x000003D2
_08083F48:
	cmp r5, #0x12
	beq _08083F56
	ldr r1, _08083F5C @ =0x00000474
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0
	beq _08083F60
_08083F56:
	movs r0, #0x12
	b _08084068
	.align 2, 0
_08083F5C: .4byte 0x00000474
_08083F60:
	subs r0, r5, #2
	cmp r0, #1
	bhi _08083F6A
_08083F66:
	adds r0, r5, #0
	b _08084068
_08083F6A:
	cmp r5, #0x13
	bne _08083F72
	movs r0, #0x13
	b _08084068
_08083F72:
	ldr r0, _08083FD0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _08083FF0
	ldr r2, _08083FD4 @ =0x00000466
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08083FF6
	ldr r3, _08083FD8 @ =0x00000467
	adds r0, r4, r3
	ldrb r0, [r0]
	bl FUN_08081da4
	cmp r0, #0
	beq _08083FE0
	add r2, sp, #8
	adds r0, r4, #0
	mov r1, sp
	bl FUN_08081de0
	cmp r0, #0
	beq _08083FE0
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x2c
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08083FE0
	movs r2, #0x8e
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #3
	strb r0, [r1]
	ldr r1, [sp, #8]
	ldr r3, _08083FDC @ =0x00000471
	adds r0, r4, r3
	strb r1, [r0]
	movs r0, #0x13
	b _08084068
	.align 2, 0
_08083FD0: .4byte 0x03002BE0
_08083FD4: .4byte 0x00000466
_08083FD8: .4byte 0x00000467
_08083FDC: .4byte 0x00000471
_08083FE0:
	ldr r0, _08083FEC @ =0x00000466
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _08083FF6
	.align 2, 0
_08083FEC: .4byte 0x00000466
_08083FF0:
	ldr r2, _08084000 @ =0x00000466
	adds r0, r4, r2
	strb r1, [r0]
_08083FF6:
	cmp r5, #1
	bne _08084004
	movs r0, #1
	b _08084068
	.align 2, 0
_08084000: .4byte 0x00000466
_08084004:
	cmp r5, #0x14
	bne _0808400C
	movs r0, #0x14
	b _08084068
_0808400C:
	cmp r5, #8
	bne _08084014
	movs r0, #8
	b _08084068
_08084014:
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r4, r3
	adds r1, r4, #0
	adds r1, #0x2c
	ldr r2, _0808403C @ =0x000004A6
	adds r5, r4, r2
	ldrb r2, [r5]
	lsls r2, r2, #3
	movs r3, #0x8f
	lsls r3, r3, #3
	adds r2, r2, r3
	adds r2, r4, r2
	bl FUN_08235f40
	cmp r0, #0
	bne _08084040
	movs r0, #0
	b _08084068
	.align 2, 0
_0808403C: .4byte 0x000004A6
_08084040:
	movs r0, #0x8e
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #8
	strb r0, [r1]
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r0, r4, r0
	ldr r1, _08084070 @ =0x0000047E
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r2, _08084074 @ =0x00000471
	adds r0, r4, r2
	strb r1, [r0]
	ldrb r0, [r5]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r5]
	movs r0, #2
_08084068:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08084070: .4byte 0x0000047E
_08084074: .4byte 0x00000471

	thumb_func_start FUN_08084078
FUN_08084078: @ 0x08084078
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrh r1, [r5, #0x34]
	ldrh r0, [r5, #0x2c]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080840D0 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldrh r1, [r5, #0x38]
	ldrh r0, [r5, #0x30]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r3, sp
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080840CC
	cmp r1, #0
	blt _080840CC
	ldr r0, _080840D4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080840CC
	ldr r0, _080840D8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080840DC
_080840CC:
	movs r4, #0
	b _080840EA
	.align 2, 0
_080840D0: .4byte 0xFFFF0000
_080840D4: .4byte 0x030046A8
_080840D8: .4byte 0x030046AC
_080840DC:
	ldr r0, _080840FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080840EA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08084100
	adds r0, #4
	b _0808410C
	.align 2, 0
_080840FC: .4byte 0x030046A4
_08084100:
	ldr r0, _08084160 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0808410C:
	ldrh r0, [r0, #2]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0808411C
	movs r0, #0
	strh r0, [r5, #0x34]
	strh r0, [r5, #0x38]
_0808411C:
	adds r0, r5, #0
	movs r1, #0x10
	bl FUN_08080ed8
	cmp r0, #0
	beq _080841C0
	movs r0, #0
	str r0, [r5, #0x3c]
	adds r0, r5, #0
	adds r0, #0x24
	bl FUN_0823b4b8
	adds r6, r5, #0
	adds r6, #0x2c
	ldrh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0808415C
	cmp r1, #0
	blt _0808415C
	ldr r0, _08084164 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0808415C
	ldr r0, _08084168 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0808416C
_0808415C:
	movs r4, #0
	b _0808417A
	.align 2, 0
_08084160: .4byte 0x030046A4
_08084164: .4byte 0x030046A8
_08084168: .4byte 0x030046AC
_0808416C:
	ldr r0, _0808418C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0808417A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08084190
	adds r0, #4
	b _0808419C
	.align 2, 0
_0808418C: .4byte 0x030046A4
_08084190:
	ldr r0, _080841B0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0808419C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080841B4
	cmp r2, #2
	beq _080841B8
	b _080841BC
	.align 2, 0
_080841B0: .4byte 0x030046A4
_080841B4:
	ldrb r0, [r6, #4]
	b _080841BA
_080841B8:
	ldrb r0, [r6]
_080841BA:
	subs r1, r1, r0
_080841BC:
	strh r1, [r5, #0x2e]
	b _080841E0
_080841C0:
	ldr r0, [r5, #0x3c]
	cmp r0, #0
	bne _080841D8
	movs r1, #0xde
	lsls r1, r1, #1
	adds r4, r5, r1
	adds r1, r5, #0
	adds r1, #0x2c
	adds r0, r4, #0
	bl FUN_0823280c
	str r4, [r5, #0x3c]
_080841D8:
	adds r0, r5, #0
	adds r0, #0x24
	bl FUN_0823b4b8
_080841E0:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08080ed8
	cmp r0, #0
	beq _080841FC
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	b _0808421A
_080841FC:
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	ldr r0, _08084230 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r1, r5, #0
	adds r1, #0x2c
	movs r2, #0
	bl FUN_082364c4
_0808421A:
	adds r0, r5, #0
	movs r1, #0x20
	bl FUN_08080ed8
	cmp r0, #0
	beq _08084238
	ldr r0, _08084234 @ =0x00000464
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	b _08084262
	.align 2, 0
_08084230: .4byte 0x0000FFFB
_08084234: .4byte 0x00000464
_08084238:
	ldr r1, _08084298 @ =0x00000464
	adds r4, r5, r1
	ldrb r0, [r4]
	adds r6, r5, #0
	adds r6, #0x2c
	cmp r0, #0
	bne _08084256
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r1, r6, #0
	bl FUN_082362fc
	movs r0, #1
	strb r0, [r4]
_08084256:
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r6, #0
	bl FUN_08236268
_08084262:
	adds r2, r5, #0
	adds r2, #0xa8
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r5, #0
	adds r1, #0xaa
	ldr r2, _0808429C @ =0x000003F6
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08080ed8
	cmp r0, #0
	beq _080842A0
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _080842AC
	.align 2, 0
_08084298: .4byte 0x00000464
_0808429C: .4byte 0x000003F6
_080842A0:
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_080842AC:
	str r1, [r0]
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08080ed8
	cmp r0, #0
	beq _080842C6
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	b _080842CC
_080842C6:
	ldr r0, [r4]
	ldr r1, _080842E4 @ =0xFFFFFDFF
	ands r0, r1
_080842CC:
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08080ed8
	cmp r0, #0
	beq _080842EC
	ldr r1, _080842E8 @ =0x0000060C
	adds r0, r5, r1
	bl FUN_080136b4
	b _080842F4
	.align 2, 0
_080842E4: .4byte 0xFFFFFDFF
_080842E8: .4byte 0x0000060C
_080842EC:
	ldr r2, _08084310 @ =0x0000060C
	adds r0, r5, r2
	bl FUN_08013698
_080842F4:
	adds r0, r5, #0
	movs r1, #0x80
	bl FUN_08080ed8
	cmp r0, #0
	beq _08084318
	ldr r1, _08084314 @ =0x000009C8
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _08084322
	.align 2, 0
_08084310: .4byte 0x0000060C
_08084314: .4byte 0x000009C8
_08084318:
	ldr r2, _0808432C @ =0x000009C8
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_08084322:
	str r1, [r0]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808432C: .4byte 0x000009C8

	thumb_func_start FUN_08084330
FUN_08084330: @ 0x08084330
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #1
	beq _08084340
	cmp r0, #2
	beq _08084388
	b _080843A4
_08084340:
	ldr r0, [r4, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0808435E
	ldr r0, _0808437C @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08084380 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	asrs r1, r1, #1
	adds r0, r4, #0
	bl FUN_08081d18
_0808435E:
	adds r0, r4, #0
	bl FUN_08083eac
	ldr r1, _08084384 @ =0x085ABF54
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_08084078
	b _080843A4
	.align 2, 0
_0808437C: .4byte 0x030046A0
_08084380: .4byte 0x00000942
_08084384: .4byte 0x085ABF54
_08084388:
	adds r0, r4, #0
	movs r1, #8
	bl FUN_08080ec8
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_08084078
_080843A4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080843ac
FUN_080843ac: @ 0x080843AC
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	ldr r6, [r4, #0x1c]
	cmp r6, #1
	beq _080843BC
	b _0808453A
_080843BC:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r3, #6]
	ands r0, r1
	cmp r0, #0
	beq _080843DE
	adds r2, r5, #0
	adds r2, #0x46
	ldrb r1, [r2]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _080843D8
	b _0808453A
_080843D8:
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r2]
_080843DE:
	adds r0, r3, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x44
	movs r2, #0
	mov ip, r2
	strh r1, [r0]
	movs r7, #0xdf
	lsls r7, r7, #2
	adds r0, r4, r7
	ldrb r0, [r0]
	cmp r0, #8
	bne _0808449C
	ldr r1, _08084440 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808449C
	ldr r2, _08084444 @ =0x00000476
	adds r1, r4, r2
	movs r0, #4
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r3, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _0808444C
	ldr r3, _08084448 @ =0x0000046B
	adds r2, r4, r3
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	adds r7, #0xee
	adds r1, r4, r7
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _08084490
	mov r0, ip
	strb r0, [r2]
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0
	bl FUN_08080e0c
	b _0808453A
	.align 2, 0
_08084440: .4byte 0x0000037D
_08084444: .4byte 0x00000476
_08084448: .4byte 0x0000046B
_0808444C:
	ldr r1, _08084488 @ =0x00000469
	adds r2, r4, r1
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r1, r4, r7
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _08084490
	mov r0, ip
	strb r0, [r2]
	adds r0, r3, #0
	adds r1, r5, #0
	bl FUN_08080f20
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _0808448C @ =0x000003D2
	adds r0, r4, r3
	strb r6, [r0]
	adds r1, r5, #0
	adds r1, #0x40
	movs r0, #0x64
	b _08084538
	.align 2, 0
_08084488: .4byte 0x00000469
_0808448C: .4byte 0x000003D2
_08084490:
	ldr r0, _08084498 @ =0x0000036A
	bl PlaySound_082406e0
	b _0808453A
	.align 2, 0
_08084498: .4byte 0x0000036A
_0808449C:
	ldr r7, _080844C8 @ =0x00000469
	adds r1, r4, r7
	movs r0, #0
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r3, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _080844BC
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r4, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _080844CC
_080844BC:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r5, #0
	bl FUN_08080f80
	b _0808453A
	.align 2, 0
_080844C8: .4byte 0x00000469
_080844CC:
	adds r0, r3, #0
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r2, _08084500 @ =0x000003E6
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08084504
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
	movs r3, #0xfa
	lsls r3, r3, #2
	adds r1, r4, r3
	b _08084538
	.align 2, 0
_08084500: .4byte 0x000003E6
_08084504:
	movs r7, #0x24
	ldrsh r0, [r3, r7]
	movs r2, #0x24
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r7, #0x28
	ldrsh r1, [r3, r7]
	movs r3, #0x28
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
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
	movs r7, #0xfa
	lsls r7, r7, #2
	adds r1, r4, r7
_08084538:
	strh r0, [r1]
_0808453A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08084540
FUN_08084540: @ 0x08084540
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r5, [r0]
	cmp r5, #0
	ble _0808458E
	adds r0, r4, #0
	movs r1, #8
	bl FUN_08080ec8
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0808458E
	subs r5, #1
	cmp r5, #0
	beq _08084586
	ldr r1, _08084594 @ =0x00000476
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08084586
	asrs r0, r5, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08084586
	adds r0, r4, #0
	movs r1, #5
	bl FUN_08080ec8
_08084586:
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
_0808458E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08084594: .4byte 0x00000476

	thumb_func_start FUN_08084598
FUN_08084598: @ 0x08084598
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080845D4 @ =0x03002BE0
	ldr r0, [r0]
	ldr r0, [r0, #0x1c]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080845CA
	adds r0, r4, #0
	bl FUN_08080e34
	adds r0, r4, #0
	bl FUN_08084540
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_08081628
_080845CA:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080845D4: .4byte 0x03002BE0

	thumb_func_start FUN_080845d8
FUN_080845d8: @ 0x080845D8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x88
	bl FUN_0822f1c0
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08236424
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_0823b284
	adds r0, r4, #0
	bl FUN_0808168c
	ldr r1, _08084620 @ =0x000009C8
	adds r0, r4, r1
	bl FUN_0822a4e0
	ldr r1, _08084624 @ =0x03002BE0
	adds r4, #0x28
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	ldr r1, _08084628 @ =0x03002B98
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08084620: .4byte 0x000009C8
_08084624: .4byte 0x03002BE0
_08084628: .4byte 0x03002B98

	thumb_func_start FUN_0808462c
FUN_0808462c: @ 0x0808462C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08081ab0
	adds r0, r4, #0
	bl FUN_0808175c
	adds r0, r4, #0
	bl FUN_080817ec
	adds r0, r4, #0
	bl FUN_08081c04
	adds r0, r4, #0
	bl FUN_080816a0
	ldr r1, _0808466C @ =0x03002BE0
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r4, [r0]
	ldr r1, _08084670 @ =0x03002B98
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0808466C: .4byte 0x03002BE0
_08084670: .4byte 0x03002B98

	thumb_func_start FUN_08084674
FUN_08084674: @ 0x08084674
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _080846B0 @ =0x03002BE0
	ldr r0, [r0, #4]
	cmp r0, #0
	bne _080846C2
	ldr r1, _080846B4 @ =0x00000AC4
	movs r0, #6
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080846C0
	ldr r1, _080846B8 @ =FUN_08084598
	ldr r2, _080846BC @ =FUN_080845d8
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0808462c
	cmp r0, #0
	bge _080846C0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080846C2
	.align 2, 0
_080846B0: .4byte 0x03002BE0
_080846B4: .4byte 0x00000AC4
_080846B8: .4byte FUN_08084598
_080846BC: .4byte FUN_080845d8
_080846C0:
	adds r0, r4, #0
_080846C2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080846c8
FUN_080846c8: @ 0x080846C8
	push {r4, lr}
	ldr r4, _080846F0 @ =0x03002BFC
	ldr r0, [r4]
	cmp r0, #0
	beq _080846E8
	adds r0, #0xb1
	ldrb r0, [r0]
	cmp r0, #6
	bne _080846E8
	ldr r0, _080846F4 @ =0x0000020E
	bl PlaySound_082406e0
	ldr r0, [r4]
	adds r0, #0xb5
	movs r1, #1
	strb r1, [r0]
_080846E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080846F0: .4byte 0x03002BFC
_080846F4: .4byte 0x0000020E

	thumb_func_start FUN_080846f8
FUN_080846f8: @ 0x080846F8
	push {lr}
	ldr r0, _0808470C @ =0x03002BFC
	ldr r0, [r0]
	cmp r0, #0
	beq _08084708
	movs r1, #7
	bl FUN_08084c30
_08084708:
	pop {r0}
	bx r0
	.align 2, 0
_0808470C: .4byte 0x03002BFC

	thumb_func_start FUN_08084710
FUN_08084710: @ 0x08084710
	push {lr}
	ldr r0, _08084728 @ =0x03002BFC
	ldr r0, [r0]
	cmp r0, #0
	beq _08084722
	adds r0, #0xb1
	ldrb r0, [r0]
	cmp r0, #6
	beq _0808472C
_08084722:
	movs r0, #0
	b _0808472E
	.align 2, 0
_08084728: .4byte 0x03002BFC
_0808472C:
	movs r0, #1
_0808472E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08084734
FUN_08084734: @ 0x08084734
	push {lr}
	adds r2, r0, #0
	ldr r0, _08084750 @ =0x03002BFC
	ldr r0, [r0]
	cmp r0, #0
	beq _0808474A
	adds r0, #0xc0
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
_0808474A:
	pop {r0}
	bx r0
	.align 2, 0
_08084750: .4byte 0x03002BFC

	thumb_func_start FUN_08084754
FUN_08084754: @ 0x08084754
	push {lr}
	ldr r3, _08084790 @ =0x03002BFC
	ldr r0, [r3]
	cmp r0, #0
	beq _0808478A
	adds r2, r0, #0
	adds r2, #0xac
	adds r0, #0xae
	ldrb r1, [r0]
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	ldr r1, _08084794 @ =0x13FF0000
	cmp r0, r1
	bls _0808477A
	movs r0, #0xa0
	lsls r0, r0, #5
	strh r0, [r2]
_0808477A:
	ldr r0, [r3]
	adds r0, #0xb0
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r3]
	adds r0, #0xb8
	movs r1, #0
	strh r1, [r0]
_0808478A:
	pop {r0}
	bx r0
	.align 2, 0
_08084790: .4byte 0x03002BFC
_08084794: .4byte 0x13FF0000

	thumb_func_start FUN_08084798
FUN_08084798: @ 0x08084798
	push {lr}
	adds r1, r0, #0
	ldr r0, _080847AC @ =0x03002BFC
	ldr r0, [r0]
	cmp r0, #0
	beq _080847A8
	adds r0, #0xb8
	strh r1, [r0]
_080847A8:
	pop {r0}
	bx r0
	.align 2, 0
_080847AC: .4byte 0x03002BFC

	thumb_func_start FUN_080847b0
FUN_080847b0: @ 0x080847B0
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x2e]
	adds r0, #1
	movs r5, #0
	strh r0, [r3, #0x2e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _0808485E
	movs r0, #0x18
	ldrsh r2, [r3, r0]
	ldr r1, [r3, #0x28]
	movs r4, #0
	ldrsh r0, [r1, r4]
	subs r2, r2, r0
	adds r4, r1, #0
	cmp r2, #0
	bge _080847D8
	rsbs r2, r2, #0
_080847D8:
	movs r6, #0x1c
	ldrsh r1, [r3, r6]
	movs r6, #4
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _080847E8
	rsbs r1, r1, #0
_080847E8:
	cmp r2, #0x7f
	bgt _080847F0
	cmp r1, #0x7f
	ble _0808485E
_080847F0:
	movs r0, #0x32
	ldrsh r2, [r3, r0]
	ldrh r1, [r3, #0x2e]
	movs r0, #0x10
	subs r0, r0, r1
	muls r0, r2, r0
	asrs r5, r0, #4
	ldrh r0, [r3, #0x30]
	adds r0, #1
	movs r1, #0xff
	ands r0, r1
	strh r0, [r3, #0x30]
	ldr r2, _08084828 @ =0x085B0A08
	movs r1, #0x30
	ldrsh r0, [r3, r1]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	muls r0, r5, r0
	cmp r0, #0
	blt _0808482C
	asrs r1, r0, #0xc
	b _08084832
	.align 2, 0
_08084828: .4byte 0x085B0A08
_0808482C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08084832:
	ldrh r0, [r4]
	adds r0, r0, r1
	strh r0, [r3, #0x18]
	ldrh r1, [r3, #0x30]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08084850
	asrs r1, r0, #0xc
	b _08084856
_08084850:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08084856:
	ldrh r0, [r4, #4]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	b _08084868
_0808485E:
	strh r5, [r3, #0x2c]
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
_08084868:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08084870
FUN_08084870: @ 0x08084870
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, _0808491C @ =0x000003A6
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _08084920 @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _0808488E
	b _0808499A
_0808488E:
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrh r1, [r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0xd4
	adds r6, r7, r0
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	ldr r1, _08084924 @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r6]
	adds r0, r7, #0
	adds r0, #0xc0
	str r0, [r6, #0x28]
	ldr r5, _08084928 @ =0x0203B400
	ldr r4, _0808492C @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	adds r3, #0x5b
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	ldr r2, _08084930 @ =0x000001FF
	mov ip, r2
	mov r2, ip
	ands r1, r2
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r1, r1, r2
	strh r1, [r6, #0x32]
	adds r0, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	asrs r0, r0, #4
	movs r1, #0xff
	ands r0, r1
	strh r0, [r6, #0x30]
	adds r0, r7, #0
	adds r0, #0xd0
	ldr r1, [r0]
	adds r0, r6, #0
	movs r2, #1
	bl FUN_0822dafc
	ldr r2, _08084934 @ =0x085B0A08
	movs r3, #0x30
	ldrsh r0, [r6, r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0x32
	ldrsh r0, [r6, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _08084938
	asrs r1, r0, #0xc
	b _0808493E
	.align 2, 0
_0808491C: .4byte 0x000003A6
_08084920: .4byte 0x0000FFFF
_08084924: .4byte 0xFFFFFDFF
_08084928: .4byte 0x0203B400
_0808492C: .4byte 0x030046B8
_08084930: .4byte 0x000001FF
_08084934: .4byte 0x085B0A08
_08084938:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808493E:
	ldr r2, [r6, #0x28]
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r6, #0x18]
	ldrh r0, [r2, #2]
	strh r0, [r6, #0x1a]
	ldr r3, _08084968 @ =0x085B0A08
	ldrh r1, [r6, #0x30]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #0x32
	ldrsh r0, [r6, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _0808496C
	asrs r1, r0, #0xc
	b _08084972
	.align 2, 0
_08084968: .4byte 0x085B0A08
_0808496C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08084972:
	ldrh r0, [r2, #4]
	adds r0, r0, r1
	movs r2, #0
	strh r0, [r6, #0x1c]
	ldr r0, _080849A0 @ =FUN_080847b0
	str r0, [r6, #0x38]
	movs r0, #1
	strh r0, [r6, #0x2c]
	strh r2, [r6, #0x2e]
	movs r0, #0xe9
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _0808499A
	strh r2, [r1]
_0808499A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080849A0: .4byte FUN_080847b0

	thumb_func_start FUN_080849a4
FUN_080849a4: @ 0x080849A4
	push {r4, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldrh r0, [r4, #0x2e]
	adds r2, r0, #1
	strh r2, [r4, #0x2e]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _08084A00
	ldrh r0, [r4, #0x34]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x36]
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	movs r0, #0x34
	ldrsh r1, [r4, r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	asrs r0, r0, #3
	strh r0, [r4, #0x34]
	movs r0, #0x36
	ldrsh r1, [r4, r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	asrs r0, r0, #3
	strh r0, [r4, #0x36]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	bne _080849F2
	adds r0, r4, #0
	adds r1, r3, #0
	movs r2, #4
	bl FUN_0822dafc
_080849F2:
	ldrh r0, [r4, #0x2e]
	cmp r0, #0xa
	bne _08084A0C
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	b _08084A08
_08084A00:
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r0, [r4]
	movs r1, #1
_08084A08:
	orrs r0, r1
	str r0, [r4]
_08084A0C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08084a14
FUN_08084a14: @ 0x08084A14
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _08084AE0 @ =0x0000020D
	bl PlaySound_082406e0
	ldr r7, _08084AE4 @ =0x030046B8
	ldr r0, _08084AE8 @ =0x000003FF
	mov sl, r0
	movs r1, #0
	str r1, [sp]
	adds r6, r5, #0
	adds r6, #0xd4
	adds r4, r6, #0
	movs r2, #0xff
	mov sb, r2
	movs r3, #0xb
	mov r8, r3
_08084A40:
	ldr r1, [r4]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	ldr r0, _08084AEC @ =0xFFFFFDFF
	ands r1, r0
	str r1, [r4]
	adds r0, r5, #0
	adds r0, #0xd0
	ldr r1, [r0]
	ldr r0, [r7]
	adds r0, #1
	mov r2, sl
	ands r0, r2
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _08084AF0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r2, [r0]
	movs r0, #1
	ands r2, r0
	adds r2, #4
	adds r0, r6, #0
	bl FUN_0822dafc
	adds r0, r5, #0
	adds r0, #0xc0
	ldrh r0, [r0]
	strh r0, [r4, #0x18]
	adds r0, r5, #0
	adds r0, #0xc2
	ldrh r0, [r0]
	strh r0, [r4, #0x1a]
	adds r0, r5, #0
	adds r0, #0xc4
	ldrh r0, [r0]
	strh r0, [r4, #0x1c]
	ldr r0, [r7]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _08084AF0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x60
	bl Mod
	adds r2, r0, #0
	adds r2, #0x30
	ldr r0, [r7]
	adds r0, #1
	mov r3, sl
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _08084AF0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	ldr r3, [sp]
	adds r1, r3, r0
	mov r0, sb
	ands r1, r0
	adds r0, r1, #0
	adds r0, #0x40
	mov r3, sb
	ands r0, r3
	lsls r0, r0, #1
	ldr r3, _08084AF4 @ =0x085B0A08
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _08084AF8
	asrs r0, r0, #0xc
	b _08084AFE
	.align 2, 0
_08084AE0: .4byte 0x0000020D
_08084AE4: .4byte 0x030046B8
_08084AE8: .4byte 0x000003FF
_08084AEC: .4byte 0xFFFFFDFF
_08084AF0: .4byte 0x0203B400
_08084AF4: .4byte 0x085B0A08
_08084AF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08084AFE:
	strh r0, [r4, #0x34]
	mov r0, sb
	ands r1, r0
	lsls r0, r1, #1
	ldr r1, _08084B18 @ =0x085B0A08
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _08084B1C
	asrs r1, r0, #0xc
	b _08084B22
	.align 2, 0
_08084B18: .4byte 0x085B0A08
_08084B1C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08084B22:
	movs r0, #0
	strh r1, [r4, #0x36]
	ldr r1, _08084B58 @ =FUN_080849a4
	str r1, [r4, #0x38]
	movs r1, #1
	strh r1, [r4, #0x2c]
	strh r0, [r4, #0x2e]
	ldr r0, [sp]
	adds r0, #0x14
	str r0, [sp]
	adds r4, #0x3c
	adds r6, #0x3c
	subs r1, #2
	add r8, r1
	mov r2, r8
	cmp r2, #0
	blt _08084B46
	b _08084A40
_08084B46:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08084B58: .4byte FUN_080849a4

	thumb_func_start FUN_08084b5c
FUN_08084b5c: @ 0x08084B5C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xd4
	movs r7, #0
	movs r6, #0xb
_08084B68:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0
	beq _08084B84
	movs r0, #0x86
	lsls r0, r0, #1
	adds r2, r5, r0
	adds r2, r2, r7
	adds r0, r5, #0
	adds r0, #0xd0
	ldr r1, [r0]
	ldr r2, [r2]
	adds r0, r4, #0
	bl _call_via_r2
_08084B84:
	adds r4, #0x3c
	adds r7, #0x3c
	subs r6, #1
	cmp r6, #0
	bge _08084B68
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08084b94
FUN_08084b94: @ 0x08084B94
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0xd4
	movs r5, #0xb
_08084B9C:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x3c
	subs r5, #1
	cmp r5, #0
	bge _08084B9C
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08084bb0
FUN_08084bb0: @ 0x08084BB0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08084C28 @ =0x000003A6
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _08084C2C @ =0x00001C1E
	bl FUN_0822b10c
	adds r1, r4, #0
	adds r1, #0xd0
	str r0, [r1]
	adds r5, r1, #0
	movs r0, #0
	mov r8, r0
	adds r4, #0xd4
	movs r7, #4
	rsbs r7, r7, #0
	movs r6, #0xb
_08084BE2:
	ldr r1, [r5]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r7, #0
	bl FUN_0822dad4
	ldr r1, [r5]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822dafc
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #1
	strb r0, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	mov r1, r8
	strh r1, [r4, #0x2c]
	strh r1, [r4, #0x2e]
	adds r4, #0x3c
	subs r6, #1
	cmp r6, #0
	bge _08084BE2
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08084C28: .4byte 0x000003A6
_08084C2C: .4byte 0x00001C1E

	thumb_func_start FUN_08084c30
FUN_08084c30: @ 0x08084C30
	mov ip, r0
	adds r0, #0xb1
	movs r3, #0
	strb r1, [r0]
	movs r2, #0xea
	lsls r2, r2, #2
	add r2, ip
	ldr r1, _08084C54 @ =0x085ABFC8
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
	mov r0, ip
	adds r0, #0xb2
	strh r3, [r0]
	bx lr
	.align 2, 0
_08084C54: .4byte 0x085ABFC8

	thumb_func_start FUN_08084c58
FUN_08084c58: @ 0x08084C58
	push {lr}
	adds r3, r0, #0
	adds r0, #0xac
	ldrh r0, [r0]
	cmp r0, #0
	beq _08084C96
	ldr r0, [r3, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0x18]
	ldr r0, [r3, #0x60]
	ands r0, r1
	str r0, [r3, #0x60]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r2, #0
	movs r0, #1
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	adds r1, #0xa
	movs r0, #0x50
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0xb5
	strb r2, [r0]
	adds r0, r3, #0
	movs r1, #1
	bl FUN_08084c30
_08084C96:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08084c9c
FUN_08084c9c: @ 0x08084C9C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xaa
	ldrh r0, [r4]
	adds r0, #4
	strh r0, [r4]
	ldr r1, _08084CE4 @ =0x0000FFFF
	adds r6, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _08084CC2
	movs r0, #0x20
	strh r0, [r4]
	adds r0, r5, #0
	movs r1, #3
	bl FUN_08084c30
_08084CC2:
	ldrh r1, [r4]
	adds r0, r5, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	muls r0, r1, r0
	asrs r0, r0, #7
	adds r1, r5, #0
	adds r1, #0xa8
	strh r0, [r1]
	ands r0, r6
	cmp r0, #0
	bne _08084CDE
	movs r0, #1
	strh r0, [r1]
_08084CDE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08084CE4: .4byte 0x0000FFFF

	thumb_func_start FUN_08084ce8
FUN_08084ce8: @ 0x08084CE8
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xaa
	ldrh r0, [r1]
	cmp r0, #4
	bhi _08084D1C
	adds r0, r4, #0
	bl FUN_08084a14
	adds r1, r4, #0
	adds r1, #0xac
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r4, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x18]
	ldr r0, [r4, #0x60]
	orrs r0, r1
	str r0, [r4, #0x60]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08084c30
	b _08084D3C
_08084D1C:
	subs r0, #4
	strh r0, [r1]
	ldrh r1, [r1]
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	muls r0, r1, r0
	asrs r0, r0, #7
	adds r1, r4, #0
	adds r1, #0xa8
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08084D3C
	movs r0, #1
	strh r0, [r1]
_08084D3C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08084d44
FUN_08084d44: @ 0x08084D44
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0xac
	ldrh r0, [r2]
	movs r1, #0xc0
	lsls r1, r1, #4
	cmp r0, r1
	bls _08084D62
	strh r1, [r2]
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08084c30
	b _08084D6E
_08084D62:
	cmp r0, #0
	bne _08084D6E
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08084c30
_08084D6E:
	adds r0, r4, #0
	adds r0, #0xac
	ldrh r1, [r0]
	lsrs r1, r1, #6
	adds r1, #0x20
	adds r5, r4, #0
	adds r5, #0xaa
	strh r1, [r5]
	ldr r3, _08084DBC @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _08084DC0 @ =0x000003FF
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _08084DC4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	lsrs r1, r1, #3
	bl Mod
	ldrh r1, [r5]
	adds r1, r1, r0
	strh r1, [r5]
	ldrh r2, [r5]
	adds r1, r4, #0
	adds r1, #0xb4
	ldrb r1, [r1]
	muls r1, r2, r1
	asrs r1, r1, #7
	asrs r0, r0, #1
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xa8
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08084DBC: .4byte 0x030046B8
_08084DC0: .4byte 0x000003FF
_08084DC4: .4byte 0x0203B400

	thumb_func_start FUN_08084dc8
FUN_08084dc8: @ 0x08084DC8
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xac
	ldrh r0, [r4]
	adds r0, #0x60
	strh r0, [r4]
	lsls r0, r0, #0x10
	ldr r1, _08084E44 @ =0x13FF0000
	cmp r0, r1
	bls _08084DF4
	movs r0, #0xba
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r0, #0xa0
	lsls r0, r0, #5
	strh r0, [r4]
	adds r0, r5, #0
	movs r1, #6
	bl FUN_08084c30
_08084DF4:
	adds r0, r5, #0
	bl FUN_08084870
	ldrh r1, [r4]
	lsrs r1, r1, #6
	adds r1, #0x20
	adds r4, r5, #0
	adds r4, #0xaa
	strh r1, [r4]
	ldr r3, _08084E48 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _08084E4C @ =0x000003FF
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _08084E50 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	lsrs r1, r1, #3
	bl Mod
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	ldrh r2, [r4]
	adds r1, r5, #0
	adds r1, #0xb4
	ldrb r1, [r1]
	muls r1, r2, r1
	asrs r1, r1, #7
	asrs r0, r0, #1
	adds r1, r1, r0
	adds r0, r5, #0
	adds r0, #0xa8
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08084E44: .4byte 0x13FF0000
_08084E48: .4byte 0x030046B8
_08084E4C: .4byte 0x000003FF
_08084E50: .4byte 0x0203B400

	thumb_func_start FUN_08084e54
FUN_08084e54: @ 0x08084E54
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xac
	ldrh r0, [r4]
	subs r0, #0x60
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xc0
	lsls r1, r1, #4
	cmp r0, r1
	bhi _08084E78
	strh r1, [r4]
	adds r0, r5, #0
	movs r1, #3
	bl FUN_08084c30
_08084E78:
	ldrh r1, [r4]
	lsrs r1, r1, #6
	adds r1, #0x20
	adds r4, r5, #0
	adds r4, #0xaa
	strh r1, [r4]
	ldr r3, _08084EC0 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _08084EC4 @ =0x000003FF
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _08084EC8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	lsrs r1, r1, #3
	bl Mod
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	ldrh r2, [r4]
	adds r1, r5, #0
	adds r1, #0xb4
	ldrb r1, [r1]
	muls r1, r2, r1
	asrs r1, r1, #7
	asrs r0, r0, #1
	adds r1, r1, r0
	adds r0, r5, #0
	adds r0, #0xa8
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08084EC0: .4byte 0x030046B8
_08084EC4: .4byte 0x000003FF
_08084EC8: .4byte 0x0203B400

	thumb_func_start FUN_08084ecc
FUN_08084ecc: @ 0x08084ECC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0xac
	ldrh r1, [r0]
	ldr r0, _08084EE4 @ =0x000013FF
	cmp r1, r0
	bls _08084EE8
	adds r0, r5, #0
	bl FUN_08084870
	b _08084EF8
	.align 2, 0
_08084EE4: .4byte 0x000013FF
_08084EE8:
	adds r1, r5, #0
	adds r1, #0xb5
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #5
	bl FUN_08084c30
_08084EF8:
	adds r4, r5, #0
	adds r4, #0xba
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2f
	bls _08084F14
	ldr r0, _08084F6C @ =0x0000020F
	bl PlaySound_082406e0
	movs r0, #0
	strh r0, [r4]
_08084F14:
	adds r0, r5, #0
	adds r0, #0xac
	ldrh r1, [r0]
	lsrs r1, r1, #6
	adds r1, #0x20
	adds r4, r5, #0
	adds r4, #0xaa
	strh r1, [r4]
	ldr r3, _08084F70 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _08084F74 @ =0x000003FF
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _08084F78 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	lsrs r1, r1, #3
	bl Mod
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	ldrh r2, [r4]
	adds r1, r5, #0
	adds r1, #0xb4
	ldrb r1, [r1]
	muls r1, r2, r1
	asrs r1, r1, #7
	asrs r0, r0, #1
	adds r1, r1, r0
	adds r2, r5, #0
	adds r2, #0xa8
	strh r1, [r2]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x78
	bls _08084F66
	movs r0, #0x78
	strh r0, [r2]
_08084F66:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08084F6C: .4byte 0x0000020F
_08084F70: .4byte 0x030046B8
_08084F74: .4byte 0x000003FF
_08084F78: .4byte 0x0203B400

	thumb_func_start FUN_08084f7c
FUN_08084f7c: @ 0x08084F7C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	adds r1, r6, #0
	adds r1, #0xaa
	ldrh r0, [r1]
	cmp r0, #0xc
	bhi _0808506C
	movs r7, #0
	movs r0, #0xc0
	adds r0, r0, r6
	mov sb, r0
	movs r1, #0xc4
	adds r1, r1, r6
	mov r8, r1
	movs r2, #0xac
	adds r2, r2, r6
	mov sl, r2
_08084FA6:
	mov r3, sb
	movs r0, #0
	ldrsh r2, [r3, r0]
	ldr r1, _08085064 @ =0x03002BE0
	lsls r0, r7, #2
	adds r5, r0, r1
	ldr r4, [r5]
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	subs r2, r2, r0
	mov r3, r8
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r3, #0x30
	ldrsh r0, [r4, r3]
	subs r3, r1, r0
	adds r0, r2, #0
	cmp r2, #0
	bge _08084FCE
	rsbs r0, r2, #0
_08084FCE:
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	bgt _08085038
	adds r0, r3, #0
	cmp r3, #0
	bge _08084FDE
	rsbs r0, r3, #0
_08084FDE:
	cmp r0, r1
	bgt _08085038
	adds r0, r2, #0
	muls r0, r2, r0
	adds r1, r3, #0
	muls r1, r3, r1
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #9
	cmp r0, r1
	bgt _08085038
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0x64
	strh r0, [r1]
	ldr r0, [r5]
	ldr r1, _08085068 @ =0x000003D2
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_0823785c
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	ldr r2, [r5]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #1
	adds r0, #1
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r2, r3
	strb r0, [r2]
	ldr r0, [r5]
	movs r1, #0x1e
	movs r2, #0xd8
	lsls r2, r2, #1
	adds r0, r0, r2
	strh r1, [r0]
_08085038:
	adds r7, #1
	cmp r7, #1
	ble _08084FA6
	adds r0, r6, #0
	bl FUN_08084a14
	movs r0, #0
	mov r3, sl
	strh r0, [r3]
	ldr r0, [r6, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r6, #0x18]
	ldr r0, [r6, #0x60]
	orrs r0, r1
	str r0, [r6, #0x60]
	adds r0, r6, #0
	movs r1, #0
	bl FUN_08084c30
	b _0808508C
	.align 2, 0
_08085064: .4byte 0x03002BE0
_08085068: .4byte 0x000003D2
_0808506C:
	subs r0, #0xc
	strh r0, [r1]
	ldrh r1, [r1]
	adds r0, r6, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	muls r0, r1, r0
	asrs r0, r0, #7
	adds r1, r6, #0
	adds r1, #0xa8
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0808508C
	movs r0, #1
	strh r0, [r1]
_0808508C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808509c
FUN_0808509c: @ 0x0808509C
	push {lr}
	mov ip, r0
	adds r0, #0xb0
	ldrb r0, [r0]
	cmp r0, #0
	bne _080850D0
	mov r1, ip
	adds r1, #0xb8
	ldrh r0, [r1]
	adds r3, r0, #0
	cmp r3, #0
	beq _080850B8
	subs r0, #1
	b _080850CE
_080850B8:
	mov r1, ip
	adds r1, #0xac
	mov r0, ip
	adds r0, #0xaf
	ldrb r2, [r0]
	ldrh r0, [r1]
	cmp r0, r2
	bhs _080850CC
	strh r3, [r1]
	b _080850D0
_080850CC:
	subs r0, r0, r2
_080850CE:
	strh r0, [r1]
_080850D0:
	mov r0, ip
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08085138
	mov r1, ip
	adds r1, #0xb4
	ldrb r0, [r1]
	adds r0, #6
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _080850EE
	movs r0, #0x7f
	strb r0, [r1]
_080850EE:
	mov r1, ip
	adds r1, #0xb6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _08085118 @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808511C
	mov r2, ip
	adds r2, #0xc8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	mov r3, ip
	str r0, [r3, #0x34]
	str r1, [r3, #0x38]
	adds r0, r2, #0
	b _0808512E
	.align 2, 0
_08085118: .4byte 0x0000FFFF
_0808511C:
	mov r0, ip
	adds r0, #0xc0
	ldr r1, [r0, #4]
	ldr r0, [r0]
	mov r2, ip
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	mov r0, ip
	adds r0, #0xc8
_0808512E:
	mov r2, ip
	adds r2, #0x7c
	ldr r1, [r0, #4]
	ldr r0, [r0]
	b _08085162
_08085138:
	mov r1, ip
	adds r1, #0xb4
	ldrb r0, [r1]
	subs r0, #6
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x4f
	bhi _0808514E
	movs r0, #0x50
	strb r0, [r1]
_0808514E:
	mov r3, ip
	adds r3, #0xc0
	ldr r0, [r3]
	ldr r1, [r3, #4]
	mov r2, ip
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	adds r2, #0x7c
	ldr r0, [r3]
	ldr r1, [r3, #4]
_08085162:
	str r0, [r2]
	str r1, [r2, #4]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808516c
FUN_0808516c: @ 0x0808516C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #4
	ldr r0, _080851BC @ =0x03002BC0
	ldr r5, [r0]
	ands r5, r1
	cmp r5, #0
	bne _080851B4
	adds r0, r4, #0
	bl FUN_08084b5c
	adds r0, r4, #0
	bl FUN_0808509c
	movs r1, #0xea
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	adds r0, #0xa8
	ldrh r1, [r0]
	subs r0, #0x87
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	adds r0, #0x8a
	ldrh r1, [r0]
	subs r0, #0x41
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	adds r0, #0x48
	strb r5, [r0]
_080851B4:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080851BC: .4byte 0x03002BC0

	thumb_func_start FUN_080851c0
FUN_080851c0: @ 0x080851C0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0x60
	bl FUN_0822a4e0
	adds r0, r4, #0
	bl FUN_08084b94
	ldr r1, _080851E4 @ =0x03002BFC
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080851E4: .4byte 0x03002BFC

	thumb_func_start FUN_080851e8
FUN_080851e8: @ 0x080851E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov r8, r0
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _08085240
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08085238 @ =0xFFFF0000
	mov sb, r1
	mov r2, sb
	ands r2, r6
	orrs r2, r0
	str r2, [sp]
	adds r6, r2, #0
	bl fetch_082316e4
	lsls r0, r0, #0x10
	ldr r1, _0808523C @ =0x0000FFFF
	adds r2, r6, #0
	ands r2, r1
	adds r6, r2, #0
	orrs r6, r0
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, sb
	ands r1, r7
	adds r7, r1, #0
	orrs r7, r0
	b _08085246
	.align 2, 0
_08085238: .4byte 0xFFFF0000
_0808523C: .4byte 0x0000FFFF
_08085240:
	ldr r0, _08085298 @ =0xFFFF0000
	movs r6, #0
	ands r7, r0
_08085246:
	movs r2, #0xa8
	add r2, r8
	mov sl, r2
	movs r2, #0
	movs r3, #0
	movs r0, #1
	mov r1, sl
	strh r0, [r1]
	movs r1, #0xaa
	add r1, r8
	mov sb, r1
	strh r0, [r1]
	mov r1, r8
	adds r1, #0xb4
	movs r0, #0x50
	strb r0, [r1]
	mov r0, r8
	adds r0, #0xb5
	strb r2, [r0]
	subs r0, #9
	strh r3, [r0]
	movs r0, #0x70
	bl prepare_08231510
	mov r2, sl
	str r2, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	cmp r0, #0
	beq _0808529C
	bl fetch_082316e4
	mov r1, r8
	adds r1, #0xae
	strb r0, [r1]
	bl fetch_082316e4
	mov r1, r8
	adds r1, #0xaf
	b _080852A8
	.align 2, 0
_08085298: .4byte 0xFFFF0000
_0808529C:
	mov r1, r8
	adds r1, #0xae
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0xc
_080852A8:
	strb r0, [r1]
	mov r4, r8
	adds r4, #0x18
	mov r5, r8
	adds r5, #0x44
	ldr r2, _08085368 @ =0x00003641
	mov sl, r2
	adds r0, r5, #0
	mov r1, sl
	bl FUN_0822b16c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #3
	bl FUN_0822a470
	adds r0, r5, #0
	movs r1, #0x32
	bl FUN_0822b20c
	movs r0, #0
	strh r0, [r4, #0x10]
	ldr r1, [sp, #8]
	ldrh r0, [r1]
	strb r0, [r4, #9]
	strb r0, [r4, #8]
	movs r2, #2
	mov sb, r2
	mov r0, sb
	strb r0, [r4, #7]
	str r6, [r4, #0x1c]
	str r7, [r4, #0x20]
	adds r4, #0x48
	adds r5, #0x48
	adds r0, r5, #0
	mov r1, sl
	bl FUN_0822b16c
	ldr r2, _0808536C @ =0x00000203
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0822a470
	adds r0, r5, #0
	movs r1, #0x32
	bl FUN_0822b20c
	movs r0, #1
	strh r0, [r4, #0x10]
	ldr r1, [sp, #0xc]
	ldrh r0, [r1]
	strb r0, [r4, #9]
	strb r0, [r4, #8]
	mov r2, sb
	strb r2, [r4, #7]
	str r6, [r4, #0x1c]
	str r7, [r4, #0x20]
	mov r0, r8
	adds r0, #0xc0
	str r6, [r0]
	str r7, [r0, #4]
	mov r1, r8
	adds r1, #0xc8
	str r6, [r1]
	str r7, [r1, #4]
	mov r2, r8
	adds r2, #0xca
	ldrh r0, [r2]
	subs r0, #0x40
	strh r0, [r2]
	ldrh r0, [r1]
	subs r0, #0x2d
	strh r0, [r1]
	adds r1, #4
	ldrh r0, [r1]
	subs r0, #0x2d
	strh r0, [r1]
	mov r0, r8
	bl FUN_08084bb0
	mov r0, r8
	movs r1, #0
	bl FUN_08084c30
	ldr r0, _08085370 @ =0x03002BFC
	mov r1, r8
	str r1, [r0]
	movs r0, #0
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08085368: .4byte 0x00003641
_0808536C: .4byte 0x00000203
_08085370: .4byte 0x03002BFC

	thumb_func_start FUN_08085374
FUN_08085374: @ 0x08085374
	push {r4, lr}
	ldr r0, _080853AC @ =0x03002BFC
	ldr r0, [r0]
	cmp r0, #0
	bne _080853BA
	movs r1, #0xeb
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080853B8
	ldr r1, _080853B0 @ =FUN_0808516c
	ldr r2, _080853B4 @ =FUN_080851c0
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080851e8
	cmp r0, #0
	bge _080853B8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080853BA
	.align 2, 0
_080853AC: .4byte 0x03002BFC
_080853B0: .4byte FUN_0808516c
_080853B4: .4byte FUN_080851c0
_080853B8:
	adds r0, r4, #0
_080853BA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080853c0
FUN_080853c0: @ 0x080853C0
	push {r4, r5, r6, lr}
	movs r1, #0x81
	lsls r1, r1, #2
	adds r4, r0, r1
	movs r6, #4
	rsbs r6, r6, #0
	movs r5, #6
_080853CE:
	ldr r0, _08085404 @ =0x00001C1C
	bl FUN_0822b10c
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822d9f0
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r6, #0
	bl FUN_0822dad4
	movs r0, #0xff
	strb r0, [r4, #0x10]
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	subs r5, #1
	adds r4, #0x28
	cmp r5, #0
	bge _080853CE
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08085404: .4byte 0x00001C1C

	thumb_func_start FUN_08085408
FUN_08085408: @ 0x08085408
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r6, r0, #0
	ldr r0, _08085444 @ =0x03002BE0
	ldr r5, [r0]
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrb r1, [r1]
	mov r8, r0
	cmp r1, #6
	beq _08085448
	movs r3, #0x81
	lsls r3, r3, #2
	adds r4, r6, r3
	movs r2, #1
	movs r1, #6
_08085432:
	ldr r0, [r4]
	orrs r0, r2
	str r0, [r4]
	subs r1, #1
	adds r4, #0x28
	cmp r1, #0
	bge _08085432
	b _08085642
	.align 2, 0
_08085444: .4byte 0x03002BE0
_08085448:
	ldr r7, _08085490 @ =0x000002E6
	adds r0, r5, r7
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r1, _08085494 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r2, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r7, #0
	ldrsh r4, [r0, r7]
	ands r3, r2
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	ldr r7, _08085498 @ =0x000002E7
	adds r0, r5, r7
	ldrb r0, [r0]
	adds r7, r1, #0
	cmp r0, #0
	beq _080854B2
	subs r1, r2, r4
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _0808549C
	asrs r0, r0, #0xc
	b _080854A2
	.align 2, 0
_08085490: .4byte 0x000002E6
_08085494: .4byte 0x085B0A08
_08085498: .4byte 0x000002E7
_0808549C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080854A2:
	adds r3, r0, #0
	adds r1, r4, r2
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	bge _080854D6
	b _080854DA
_080854B2:
	adds r1, r4, r2
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _080854C2
	asrs r0, r0, #0xc
	b _080854C8
_080854C2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080854C8:
	adds r3, r0, #0
	subs r1, r2, r4
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _080854DA
_080854D6:
	asrs r0, r0, #0xc
	b _080854E0
_080854DA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080854E0:
	adds r5, r0, #0
	mov r0, r8
	ldr r4, [r0]
	ldrh r0, [r4, #0x2c]
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08085544 @ =0xFFFF0000
	adds r1, r3, #0
	ldr r2, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldrh r0, [r4, #0x2e]
	adds r0, #0xdc
	lsls r0, r0, #0x10
	ldr r2, _08085548 @ =0x0000FFFF
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldrh r0, [r4, #0x30]
	adds r0, r0, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r7
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x64
	muls r0, r1, r0
	cmp r0, #0
	blt _0808554C
	asrs r1, r0, #0xc
	b _08085552
	.align 2, 0
_08085544: .4byte 0xFFFF0000
_08085548: .4byte 0x0000FFFF
_0808554C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08085552:
	adds r0, r6, #0
	adds r0, #0x48
	ldrh r0, [r0]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08085590 @ =0xFFFF0000
	ldr r2, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	adds r0, r6, #0
	adds r0, #0x4a
	ldrh r0, [r0]
	subs r0, #0x32
	lsls r0, r0, #0x10
	ldr r2, _08085594 @ =0x0000FFFF
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	lsls r0, r3, #1
	adds r0, r0, r7
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x64
	muls r0, r1, r0
	cmp r0, #0
	blt _08085598
	asrs r1, r0, #0xc
	b _0808559E
	.align 2, 0
_08085590: .4byte 0xFFFF0000
_08085594: .4byte 0x0000FFFF
_08085598:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808559E:
	adds r0, r6, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08085654 @ =0xFFFF0000
	ldr r7, [sp, #0xc]
	ands r1, r7
	orrs r1, r0
	str r1, [sp, #0xc]
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _08085658 @ =0x000002E6
	adds r0, r0, r2
	ldrb r0, [r0]
	movs r3, #2
	rsbs r3, r3, #0
	mov sb, r3
	cmp r0, #4
	bne _080855CE
	movs r7, #0x14
	rsbs r7, r7, #0
	mov sb, r7
_080855CE:
	movs r0, #0x81
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0
	ldr r2, [sp, #8]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	mov ip, r0
	ldr r3, [sp]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	mov sl, r0
	mov r6, ip
	asrs r7, r2, #0x10
	str r7, [sp, #0x10]
	adds r0, r3, #0
	asrs r0, r0, #0x10
	mov r8, r0
	adds r5, r7, #0
_080855F4:
	adds r3, r1, #1
	movs r2, #7
	subs r2, r2, r1
	mov r0, sl
	muls r0, r2, r0
	adds r0, r6, r0
	asrs r0, r0, #3
	strh r0, [r4, #0x18]
	mov r0, r8
	muls r0, r2, r0
	adds r0, r5, r0
	asrs r0, r0, #3
	strh r0, [r4, #0x1a]
	ldr r1, [sp, #0xc]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r3, r1
	ldr r7, [sp, #4]
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	muls r0, r2, r0
	adds r1, r1, r0
	asrs r1, r1, #3
	strh r1, [r4, #0x1c]
	mov r0, sb
	strb r0, [r4, #0x10]
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	add r6, ip
	ldr r1, [sp, #0x10]
	adds r5, r5, r1
	adds r1, r3, #0
	adds r4, #0x28
	cmp r1, #6
	ble _080855F4
_08085642:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08085654: .4byte 0xFFFF0000
_08085658: .4byte 0x000002E6

	thumb_func_start FUN_0808565c
FUN_0808565c: @ 0x0808565C
	push {r4, r5, lr}
	movs r1, #0x81
	lsls r1, r1, #2
	adds r4, r0, r1
	movs r5, #6
_08085666:
	adds r0, r4, #0
	bl FUN_0822dabc
	subs r5, #1
	adds r4, #0x28
	cmp r5, #0
	bge _08085666
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808567c
FUN_0808567c: @ 0x0808567C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080856C4 @ =0x0000033B
	adds r6, r4, r0
	ldrb r0, [r6]
	cmp r0, #0
	bne _080856BE
	movs r0, #0xda
	lsls r0, r0, #2
	adds r5, r4, r0
	ldr r1, _080856C8 @ =0x00001C1B
	adds r0, r5, #0
	bl FUN_0822b16c
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r4, r0
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0822a470
	movs r2, #8
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822a4f8
	movs r0, #6
	strh r0, [r4, #0x10]
	movs r0, #1
	strb r0, [r6]
_080856BE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080856C4: .4byte 0x0000033B
_080856C8: .4byte 0x00001C1B

	thumb_func_start FUN_080856cc
FUN_080856cc: @ 0x080856CC
	push {r4, lr}
	adds r1, r0, #0
	ldr r0, _080856F0 @ =0x0000033B
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, #1
	bne _080856E8
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r0, r1, r2
	bl FUN_0822a4e0
	movs r0, #0
	strb r0, [r4]
_080856E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080856F0: .4byte 0x0000033B

	thumb_func_start FUN_080856f4
FUN_080856f4: @ 0x080856F4
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xca
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r1, r0
	cmp r1, #0x5f
	bls _0808573E
	cmp r1, #0x60
	bne _08085712
	ldr r0, _08085750 @ =0x000002AA
	bl PlaySound_082406e0
_08085712:
	ldr r2, _08085754 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08085758 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0808575C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	movs r1, #0xb
	muls r0, r1, r0
	subs r0, #5
	ldr r2, _08085760 @ =0x0000031E
	adds r1, r4, r2
	strh r0, [r1]
	rsbs r0, r0, #0
	adds r2, #4
	adds r1, r4, r2
	strh r0, [r1]
_0808573E:
	movs r0, #0xca
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08085750: .4byte 0x000002AA
_08085754: .4byte 0x030046B8
_08085758: .4byte 0x000003FF
_0808575C: .4byte 0x0203B400
_08085760: .4byte 0x0000031E

	thumb_func_start FUN_08085764
FUN_08085764: @ 0x08085764
	push {r4, r5, lr}
	sub sp, #0x20
	adds r3, r0, #0
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldr r2, _0808579C @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r0, #0x64
	muls r0, r1, r0
	adds r5, r2, #0
	cmp r0, #0
	blt _080857A0
	asrs r1, r0, #0xc
	b _080857A6
	.align 2, 0
_0808579C: .4byte 0x085B0A08
_080857A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080857A6:
	adds r0, r3, #0
	adds r0, #0x48
	ldrh r0, [r0]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	adds r1, r3, #0
	adds r1, #0x4a
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #8]
	lsls r0, r4, #1
	adds r0, r0, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x64
	muls r0, r1, r0
	cmp r0, #0
	blt _080857D2
	asrs r2, r0, #0xc
	b _080857D8
_080857D2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080857D8:
	adds r0, r3, #0
	adds r0, #0x4c
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0808580C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _08085810
	asrs r0, r0, #0xc
	b _08085816
	.align 2, 0
_0808580C: .4byte 0xFFFF0000
_08085810:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08085816:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	lsls r0, r4, #1
	adds r0, r0, r5
	movs r5, #0
	ldrsh r1, [r0, r5]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _08085832
	asrs r0, r0, #0xc
	b _08085838
_08085832:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08085838:
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _08085878 @ =0xFFFF0000
	add r1, sp, #0x10
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	ldr r0, [sp, #0x18]
	ands r0, r3
	movs r4, #0x20
	orrs r0, r4
	ldr r2, _0808587C @ =0x0000FFFF
	ands r0, r2
	str r0, [sp, #0x18]
	add r2, sp, #0x18
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r4
	str r0, [r2, #4]
	movs r0, #3
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	add r0, sp, #8
	movs r3, #1
	bl FUN_080dbd08
	add sp, #0x20
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08085878: .4byte 0xFFFF0000
_0808587C: .4byte 0x0000FFFF

	thumb_func_start FUN_08085880
FUN_08085880: @ 0x08085880
	push {r4, lr}
	sub sp, #0x20
	mov ip, r0
	ldr r2, _080858B8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080858BC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080858C0 @ =0x0203B400
	adds r0, r0, r1
	movs r1, #0xff
	ldrb r4, [r0]
	ldr r2, _080858C4 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _080858C8
	asrs r0, r0, #0xc
	b _080858CE
	.align 2, 0
_080858B8: .4byte 0x030046B8
_080858BC: .4byte 0x000003FF
_080858C0: .4byte 0x0203B400
_080858C4: .4byte 0x085B0A08
_080858C8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080858CE:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _080858E6
	asrs r0, r0, #0xc
	b _080858EC
_080858E6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080858EC:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _08085968 @ =0xFFFF0000
	add r2, sp, #8
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0xc]
	mov r1, ip
	adds r1, #0x48
	adds r0, r2, #0
	ldrh r0, [r0]
	lsls r0, r0, #2
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	mov r1, ip
	adds r1, #0x4a
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #0x10]
	mov r0, ip
	adds r0, #0x4c
	ldrh r2, [r2, #4]
	lsls r2, r2, #2
	ldrh r0, [r0]
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r0, sp, #0x10
	ldr r1, [r0, #4]
	ands r1, r3
	orrs r1, r2
	str r1, [r0, #4]
	movs r1, #0
	str r1, [sp, #0x18]
	add r2, sp, #0x18
	ldr r1, [r2, #4]
	ands r1, r3
	str r1, [r2, #4]
	movs r1, #3
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	add r1, sp, #8
	movs r3, #1
	bl FUN_080dbd08
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0808595E
	movs r0, #0xd3
	bl PlaySound_082406e0
_0808595E:
	add sp, #0x20
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08085968: .4byte 0xFFFF0000

	thumb_func_start FUN_0808596c
FUN_0808596c: @ 0x0808596C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov r8, r0
	movs r0, #0
	mov sb, r0
	add r7, sp, #0x18
	ldr r5, _080859AC @ =0xFFFF0000
	ldr r1, _080859B0 @ =0x0000FFFF
	mov sl, r1
	add r4, sp, #8
	add r6, sp, #0x10
_0808598A:
	mov r2, sb
	lsls r3, r2, #5
	ldr r2, _080859B4 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #4
	cmp r0, #0
	blt _080859B8
	asrs r0, r0, #0xc
	b _080859BE
	.align 2, 0
_080859AC: .4byte 0xFFFF0000
_080859B0: .4byte 0x0000FFFF
_080859B4: .4byte 0x085B0A08
_080859B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080859BE:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #8]
	ands r0, r5
	orrs r0, r1
	mov r2, sl
	ands r0, r2
	str r0, [sp, #8]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	ldr r1, _080859E8 @ =0x085B0A08
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #4
	cmp r0, #0
	blt _080859EC
	asrs r0, r0, #0xc
	b _080859F2
	.align 2, 0
_080859E8: .4byte 0x085B0A08
_080859EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080859F2:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r4, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [r4, #4]
	mov r1, r8
	adds r1, #0x48
	ldrh r0, [r4]
	lsls r0, r0, #3
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r5
	orrs r1, r0
	mov r0, r8
	adds r0, #0x4a
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	mov r2, sl
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x10]
	mov r0, r8
	adds r0, #0x4c
	ldrh r1, [r4, #4]
	lsls r1, r1, #3
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r6, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [r6, #4]
	movs r0, #0
	str r0, [sp, #0x18]
	ldr r0, [r7, #4]
	ands r0, r5
	str r0, [r7, #4]
	movs r0, #3
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	add r1, sp, #8
	adds r2, r7, #0
	movs r3, #1
	bl FUN_080dbd08
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #7
	ble _0808598A
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08085a74
FUN_08085a74: @ 0x08085A74
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #8
	adds r2, r1, #0
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, _08085B20 @ =0x0203B400
	mov r8, r0
	ldr r1, _08085B24 @ =0x030046B8
	mov ip, r1
	ldr r3, [r1]
	adds r3, #1
	ldr r6, _08085B28 @ =0x000003FF
	ands r3, r6
	lsls r0, r3, #1
	add r0, r8
	ldrh r1, [r0]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0xf
	movs r4, #0x1f
	mov sb, r4
	mov r4, sb
	ands r1, r4
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08085B2C @ =0xFFFF0000
	mov sl, r1
	ldr r5, [sp]
	ands r5, r1
	orrs r5, r0
	str r5, [sp]
	adds r3, #1
	ands r3, r6
	lsls r0, r3, #1
	add r0, r8
	ldrh r4, [r0]
	mov r0, sp
	ldrh r1, [r0, #4]
	subs r1, #0xf
	mov r0, sb
	ands r4, r0
	adds r1, r1, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #4]
	mov r4, sl
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #4]
	adds r3, #1
	ands r3, r6
	mov r0, ip
	str r3, [r0]
	lsls r3, r3, #1
	add r3, r8
	ldrh r3, [r3]
	asrs r1, r5, #0x10
	subs r1, #0x10
	movs r0, #0x3f
	ands r3, r0
	subs r1, r1, r3
	lsls r1, r1, #0x10
	ldr r0, _08085B30 @ =0x0000FFFF
	ands r0, r5
	orrs r0, r1
	str r0, [sp]
	movs r0, #1
	mov r1, sp
	bl FUN_080155e4
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08085B20: .4byte 0x0203B400
_08085B24: .4byte 0x030046B8
_08085B28: .4byte 0x000003FF
_08085B2C: .4byte 0xFFFF0000
_08085B30: .4byte 0x0000FFFF

	thumb_func_start FUN_08085b34
FUN_08085b34: @ 0x08085B34
	push {lr}
	adds r3, r0, #0
	ldr r1, _08085B4C @ =0x0000032A
	adds r0, r3, r1
	ldrh r0, [r0]
	cmp r0, #1
	beq _08085B72
	cmp r0, #1
	bgt _08085B50
	cmp r0, #0
	beq _08085B56
	b _08085BCA
	.align 2, 0
_08085B4C: .4byte 0x0000032A
_08085B50:
	cmp r0, #2
	beq _08085BAA
	b _08085BCA
_08085B56:
	movs r0, #0xcb
	lsls r0, r0, #2
	adds r2, r3, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _08085BC8
	lsls r1, r0, #5
	subs r1, r1, r0
	asrs r1, r1, #6
	strh r1, [r3, #0x22]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
	b _08085BCA
_08085B72:
	movs r0, #0xcb
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, #0x3f
	bhi _08085B82
	adds r1, r0, #0
	b _08085B88
_08085B82:
	ldrh r0, [r1]
	movs r1, #0x80
	subs r1, r1, r0
_08085B88:
	lsls r0, r1, #5
	subs r0, r0, r1
	asrs r0, r0, #6
	strh r0, [r3, #0x22]
	movs r0, #0xcb
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bls _08085BCA
	movs r0, #0
	strh r0, [r1]
	b _08085BCA
_08085BAA:
	movs r1, #0xcb
	lsls r1, r1, #2
	adds r2, r3, r1
	ldrh r0, [r2]
	cmp r0, #0x3f
	bhi _08085BC6
	lsls r1, r0, #5
	subs r1, r1, r0
	asrs r1, r1, #6
	strh r1, [r3, #0x22]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	b _08085BCA
_08085BC6:
	movs r0, #0x1f
_08085BC8:
	strh r0, [r3, #0x22]
_08085BCA:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08085bd0
FUN_08085bd0: @ 0x08085BD0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp]
	ldr r1, _08085CA4 @ =0x03003584
	movs r2, #0xc7
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r3, _08085CA8 @ =0x00000207
	adds r0, r0, r3
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r0, r1, r0
	str r0, [sp, #4]
	ldr r4, _08085CAC @ =0x000041E0
	adds r4, r1, r4
	str r4, [sp, #8]
	ldr r1, [sp]
	adds r2, #0x18
	adds r0, r1, r2
	ldrh r1, [r0]
	movs r0, #0x40
	subs r0, r0, r1
	mov sb, r0
	mov ip, r1
	movs r3, #0
	mov sl, r3
	movs r4, #0x1f
	mov r8, r4
	movs r7, #0x1f
_08085C14:
	ldr r0, [sp, #4]
	ldrh r1, [r0]
	adds r2, r7, #0
	ands r2, r1
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x15
	mov r3, r8
	ands r6, r3
	lsrs r1, r1, #0x1a
	ands r1, r3
	ldr r0, [sp, #8]
	ldrh r4, [r0]
	adds r0, r7, #0
	ands r0, r4
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x15
	ands r5, r3
	lsrs r4, r4, #0x1a
	ands r4, r3
	mov r3, sb
	muls r3, r2, r3
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	adds r3, r3, r0
	asrs r3, r3, #6
	ands r3, r7
	mov r2, sb
	muls r2, r6, r2
	mov r0, ip
	muls r0, r5, r0
	adds r2, r2, r0
	asrs r2, r2, #6
	ands r2, r7
	mov r0, sb
	muls r0, r1, r0
	adds r1, r0, #0
	mov r0, ip
	muls r0, r4, r0
	adds r1, r1, r0
	asrs r1, r1, #6
	ands r1, r7
	mov r4, sl
	lsls r0, r4, #1
	ldr r4, [sp]
	adds r4, #0x20
	adds r4, r4, r0
	lsls r2, r2, #5
	orrs r3, r2
	lsls r1, r1, #0xa
	orrs r3, r1
	strh r3, [r4]
	ldr r0, [sp, #4]
	adds r0, #2
	str r0, [sp, #4]
	ldr r1, [sp, #8]
	adds r1, #2
	str r1, [sp, #8]
	movs r2, #1
	add sl, r2
	mov r3, sl
	cmp r3, #0xf
	ble _08085C14
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08085CA4: .4byte 0x03003584
_08085CA8: .4byte 0x00000207
_08085CAC: .4byte 0x000041E0

	thumb_func_start FUN_08085cb0
FUN_08085cb0: @ 0x08085CB0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0xb0
	ldr r2, _08085CE8 @ =0x00000207
	adds r1, r1, r2
	bl FUN_0822b20c
	adds r0, r4, #0
	adds r0, #0xbc
	adds r5, r4, #0
	adds r5, #0x20
	ldr r2, [r0]
	adds r1, r5, #0
	movs r3, #0xf
_08085CCC:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _08085CCC
	adds r0, r4, #0
	adds r0, #0xbc
	str r5, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08085CE8: .4byte 0x00000207

	thumb_func_start FUN_08085cec
FUN_08085cec: @ 0x08085CEC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08085D14 @ =0x0000040A
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08085D04
	ldr r2, _08085D18 @ =0x00000406
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08085D1C
_08085D04:
	movs r0, #0xcd
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x3f
	bhi _08085D2C
	adds r0, #1
	b _08085D2A
	.align 2, 0
_08085D14: .4byte 0x0000040A
_08085D18: .4byte 0x00000406
_08085D1C:
	movs r2, #0xcd
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08085D2C
	subs r0, #1
_08085D2A:
	strh r0, [r1]
_08085D2C:
	movs r0, #0xcc
	lsls r0, r0, #2
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	beq _08085D5C
	ldr r2, _08085D58 @ =0x0000032E
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #9
	beq _08085D4E
	movs r0, #9
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #9
	bl FUN_08085cb0
_08085D4E:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	b _08085D9E
	.align 2, 0
_08085D58: .4byte 0x0000032E
_08085D5C:
	movs r1, #0xcd
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08085D7C
	ldr r2, _08085D78 @ =0x0000032E
	adds r1, r4, r2
	movs r0, #8
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_08085bd0
	b _08085D9E
	.align 2, 0
_08085D78: .4byte 0x0000032E
_08085D7C:
	ldr r0, _08085DA4 @ =0x0000032E
	adds r1, r4, r0
	movs r2, #0xc7
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r2, [r0]
	ldrh r0, [r1]
	cmp r0, r2
	beq _08085D98
	strh r2, [r1]
	ldrh r1, [r1]
	adds r0, r4, #0
	bl FUN_08085cb0
_08085D98:
	adds r0, r4, #0
	bl FUN_08085b34
_08085D9E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08085DA4: .4byte 0x0000032E

	thumb_func_start FUN_08085da8
FUN_08085da8: @ 0x08085DA8
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xce
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _08085DBC
	subs r0, #1
	strh r0, [r4]
_08085DBC:
	ldr r1, _08085DF4 @ =0x0000033A
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08085EB0
	adds r1, #0x4a
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08085EB0
	ldrb r0, [r5, #0x1a]
	cmp r0, #5
	bne _08085DFC
	subs r1, #0x4e
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08085EA2
	ldrh r0, [r4]
	cmp r0, #0
	bne _08085EA2
	ldr r0, _08085DF8 @ =0x0000026A
	bl PlaySound_082406e0
	movs r0, #0x64
	strh r0, [r4]
	b _08085EA2
	.align 2, 0
_08085DF4: .4byte 0x0000033A
_08085DF8: .4byte 0x0000026A
_08085DFC:
	ldr r1, _08085E34 @ =0x00000336
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08085E8E
	adds r0, r5, #0
	adds r0, #0x48
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08085E2E
	cmp r1, #0
	blt _08085E2E
	ldr r0, _08085E38 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08085E2E
	ldr r0, _08085E3C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08085E40
_08085E2E:
	movs r4, #0
	b _08085E4E
	.align 2, 0
_08085E34: .4byte 0x00000336
_08085E38: .4byte 0x030046A8
_08085E3C: .4byte 0x030046AC
_08085E40:
	ldr r0, _08085E60 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08085E4E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08085E64
	adds r0, #4
	b _08085E70
	.align 2, 0
_08085E60: .4byte 0x030046A4
_08085E64:
	ldr r0, _08085E84 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08085E70:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	subs r0, #1
	cmp r0, #1
	bhi _08085E88
	movs r0, #0xd3
	bl PlaySound_082406e0
	b _08085E8E
	.align 2, 0
_08085E84: .4byte 0x030046A4
_08085E88:
	movs r0, #0xd2
	bl PlaySound_082406e0
_08085E8E:
	ldr r1, _08085EAC @ =0x00000336
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _08085EA2
	adds r0, r5, #0
	bl FUN_08085764
_08085EA2:
	ldr r0, _08085EAC @ =0x00000336
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	b _08085EB6
	.align 2, 0
_08085EAC: .4byte 0x00000336
_08085EB0:
	ldr r0, _08085EC0 @ =0x00000336
	adds r1, r5, r0
	movs r0, #0
_08085EB6:
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08085EC0: .4byte 0x00000336

	thumb_func_start FUN_08085ec4
FUN_08085ec4: @ 0x08085EC4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08085cec
	adds r0, r4, #0
	bl FUN_08085da8
	adds r0, r4, #0
	bl FUN_08085408
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08085ee0
FUN_08085ee0: @ 0x08085EE0
	adds r3, r0, #0
	ldr r0, _08085EF4 @ =0x000001F5
	adds r2, r3, r0
	movs r0, #0
	strb r1, [r2]
	movs r2, #0xfb
	lsls r2, r2, #1
	adds r1, r3, r2
	strh r0, [r1]
	bx lr
	.align 2, 0
_08085EF4: .4byte 0x000001F5

	thumb_func_start FUN_08085ef8
FUN_08085ef8: @ 0x08085EF8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r2, r1, #0
	movs r0, #0x80
	lsls r0, r0, #2
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #4
	bls _08085F16
	adds r1, r0, #0
	movs r0, #8
	subs r3, r0, r1
	movs r6, #1
	b _08085F1A
_08085F16:
	ldrb r3, [r3]
	movs r6, #0
_08085F1A:
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r4, r5, r1
	adds r1, #0x10
	adds r0, r5, r1
	ldr r1, [r0]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r6, [sp]
	adds r0, r4, #0
	bl FUN_08236fac
	adds r5, #0x84
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
	beq _08085F64
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08085F6C
_08085F64:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08085F6C:
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
	beq _08085F90
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08085F98
_08085F90:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08085F98:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08085FD0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08086016
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08085FDA
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08085FD4
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08085FF0
	.align 2, 0
_08085FD0: .4byte 0x0000FFFF
_08085FD4:
	subs r0, #1
	strh r0, [r4, #8]
	b _08085FEE
_08085FDA:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08085FEE
	strh r1, [r4, #8]
	movs r2, #1
	b _08085FF0
_08085FEE:
	movs r2, #0
_08085FF0:
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
	bne _08086018
	movs r0, #1
	strb r0, [r4, #7]
	b _08086018
_08086016:
	movs r2, #0
_08086018:
	adds r0, r2, #0
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08086024
FUN_08086024: @ 0x08086024
	push {lr}
	ldrb r2, [r0, #0x1a]
	adds r1, r1, r2
	bl FUN_08085ef8
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08086034
FUN_08086034: @ 0x08086034
	push {r4, lr}
	sub sp, #0x10
	adds r1, r0, #0
	movs r0, #0xc9
	lsls r0, r0, #2
	adds r3, r1, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _0808606E
	movs r2, #0
	strh r2, [r3]
	ldr r3, _08086078 @ =0x00000326
	adds r0, r1, r3
	strh r2, [r0]
	ldr r0, _0808607C @ =0x00000414
	adds r4, r1, r0
	ldr r0, [r4]
	adds r1, #0x40
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0xfa
	str r2, [sp, #8]
	adds r2, #0x28
	str r2, [sp, #0xc]
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r4]
_0808606E:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08086078: .4byte 0x00000326
_0808607C: .4byte 0x00000414

	thumb_func_start FUN_08086080
FUN_08086080: @ 0x08086080
	push {lr}
	bl FUN_08086034
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808608c
FUN_0808608c: @ 0x0808608C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x48
	adds r0, r6, #0
	bl FUN_0823629c
	cmp r0, #0xff
	beq _080860BE
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r4, r5, r0
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_082362fc
	movs r0, #0xea
	lsls r0, r0, #2
	adds r2, r5, r0
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_08235a84
	cmp r0, #0
	bne _080860C2
_080860BE:
	movs r0, #0
	b _080860C4
_080860C2:
	movs r0, #1
_080860C4:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080860cc
FUN_080860cc: @ 0x080860CC
	push {lr}
	adds r2, r0, #0
	ldr r1, _08086100 @ =0x000003A6
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r0, r2, r3
	strh r1, [r0]
	ldr r1, _08086104 @ =0x000003A2
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080860F4
	movs r3, #0xe1
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808610C
_080860F4:
	ldr r0, _08086108 @ =0x03002C00
	ldr r0, [r0]
	movs r1, #0
	bl FUN_08085ee0
	b _08086132
	.align 2, 0
_08086100: .4byte 0x000003A6
_08086104: .4byte 0x000003A2
_08086108: .4byte 0x03002C00
_0808610C:
	adds r0, r2, #0
	bl FUN_0808608c
	cmp r0, #0
	beq _08086128
	ldr r0, _08086124 @ =0x03002C00
	ldr r0, [r0]
	movs r1, #3
	bl FUN_08085ee0
	b _08086132
	.align 2, 0
_08086124: .4byte 0x03002C00
_08086128:
	ldr r0, _08086138 @ =0x03002C00
	ldr r0, [r0]
	movs r1, #4
	bl FUN_08085ee0
_08086132:
	pop {r0}
	bx r0
	.align 2, 0
_08086138: .4byte 0x03002C00

	thumb_func_start FUN_0808613c
FUN_0808613c: @ 0x0808613C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xf3
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r5, #0x48]
	ldr r1, [r5, #0x4c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _0808619C @ =0x000003CE
	adds r1, r5, r2
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_0808567c
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r5, #0x48]
	ldr r1, [r5, #0x4c]
	str r0, [r2]
	str r1, [r2, #4]
	adds r6, r2, #0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08086198
	cmp r1, #0
	blt _08086198
	ldr r0, _080861A0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08086198
	ldr r0, _080861A4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080861A8
_08086198:
	movs r4, #0
	b _080861B6
	.align 2, 0
_0808619C: .4byte 0x000003CE
_080861A0: .4byte 0x030046A8
_080861A4: .4byte 0x030046AC
_080861A8:
	ldr r0, _080861C8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080861B6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080861CC
	adds r0, #4
	b _080861D8
	.align 2, 0
_080861C8: .4byte 0x030046A4
_080861CC:
	ldr r0, _080861EC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080861D8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080861F0
	cmp r2, #2
	beq _080861F4
	b _080861F8
	.align 2, 0
_080861EC: .4byte 0x030046A4
_080861F0:
	ldrb r0, [r6, #4]
	b _080861F6
_080861F4:
	ldrb r0, [r6]
_080861F6:
	subs r1, r1, r0
_080861F8:
	ldr r2, _0808622C @ =0x0000035A
	adds r0, r5, r2
	strh r1, [r0]
	movs r0, #0xfa
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _08086218
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	bl FUN_080f8cac
	movs r0, #0
	strb r0, [r4]
_08086218:
	adds r0, r5, #0
	bl FUN_08086080
	adds r0, r5, #0
	movs r1, #5
	bl FUN_08085ee0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808622C: .4byte 0x0000035A

	thumb_func_start FUN_08086230
FUN_08086230: @ 0x08086230
	ldr r1, _08086238 @ =0x03002C00
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08086238: .4byte 0x03002C00

	thumb_func_start coffin_0808623c
coffin_0808623c: @ 0x0808623C
	push {r4, r5, lr}
	ldr r5, _08086264 @ =0x030046A0
	ldr r0, [r5]
	ldr r4, _08086268 @ =0x00000252
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r0, #0x38
	movs r1, #0
	bl TryAddItem
	ldr r0, [r5]
	adds r0, r0, r4
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08086264: .4byte 0x030046A0
_08086268: .4byte 0x00000252

	thumb_func_start FUN_0808626c
FUN_0808626c: @ 0x0808626C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #4
	ands r1, r0
	cmp r1, #0
	beq _08086286
	ands r3, r0
	cmp r3, #0
	beq _08086282
	cmp r4, r2
	beq _0808628C
_08086282:
	movs r0, #0
	b _0808628E
_08086286:
	ands r3, r0
	cmp r3, #0
	bne _08086282
_0808628C:
	movs r0, #1
_0808628E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08086294
FUN_08086294: @ 0x08086294
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	mov sb, r2
	ldr r0, _08086354 @ =0x03002C00
	ldr r3, [r0]
	adds r2, r0, #0
	cmp r3, #0
	bne _080862B2
	b _0808657E
_080862B2:
	movs r0, #0
	ldrsh r1, [r5, r0]
	adds r0, r3, #0
	adds r0, #0x48
	movs r6, #0
	ldrsh r0, [r0, r6]
	subs r6, r1, r0
	movs r7, #4
	ldrsh r1, [r5, r7]
	adds r0, r3, #0
	adds r0, #0x4c
	movs r7, #0
	ldrsh r0, [r0, r7]
	subs r1, r1, r0
	mov r8, r1
	adds r0, r6, #0
	muls r0, r6, r0
	adds r7, r1, #0
	mov r1, r8
	muls r1, r7, r1
	adds r0, r0, r1
	ldr r1, _08086358 @ =0x0000BD10
	cmp r0, r1
	ble _080862E4
	b _0808657E
_080862E4:
	ldr r1, _0808635C @ =0x000001F5
	adds r0, r3, r1
	ldrb r1, [r0]
	adds r0, r1, #0
	subs r0, #0xf
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080862F8
	b _08086408
_080862F8:
	adds r0, r1, #0
	cmp r0, #0
	beq _08086308
	cmp r0, #3
	beq _08086308
	cmp r0, #4
	beq _08086308
	b _0808657E
_08086308:
	ldr r0, [r2]
	ldr r2, _08086360 @ =0x00000386
	adds r1, r0, r2
	ldrh r2, [r1]
	movs r7, #0xe1
	lsls r7, r7, #2
	adds r0, r0, r7
	ldrb r3, [r0]
	adds r0, r4, #0
	mov r1, sb
	bl FUN_0808626c
	cmp r0, #0
	bne _08086326
	b _0808657E
_08086326:
	ldrh r2, [r5]
	lsls r0, r2, #0x10
	asrs r4, r0, #0x18
	ldrh r1, [r5, #4]
	lsls r0, r1, #0x10
	asrs r3, r0, #0x18
	mov ip, r2
	mov sb, r1
	cmp r4, #0
	blt _0808634E
	cmp r3, #0
	blt _0808634E
	ldr r0, _08086364 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0808634E
	ldr r0, _08086368 @ =0x030046AC
	ldr r0, [r0]
	cmp r3, r0
	blo _0808636C
_0808634E:
	movs r4, #0
	b _0808637A
	.align 2, 0
_08086354: .4byte 0x03002C00
_08086358: .4byte 0x0000BD10
_0808635C: .4byte 0x000001F5
_08086360: .4byte 0x00000386
_08086364: .4byte 0x030046A8
_08086368: .4byte 0x030046AC
_0808636C:
	ldr r0, _080863A8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r3, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0808637A:
	ldr r2, _080863AC @ =0x03002C00
	ldr r1, [r2]
	adds r1, #0x48
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080863A4
	cmp r1, #0
	blt _080863A4
	ldr r0, _080863B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080863A4
	ldr r0, _080863B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080863B8
_080863A4:
	movs r3, #0
	b _080863C6
	.align 2, 0
_080863A8: .4byte 0x030046A4
_080863AC: .4byte 0x03002C00
_080863B0: .4byte 0x030046A8
_080863B4: .4byte 0x030046AC
_080863B8:
	ldr r0, _0808640C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r3
_080863C6:
	cmp r4, r3
	beq _08086408
	adds r0, r3, #1
	cmp r4, r0
	beq _080863EE
	subs r0, r3, #1
	cmp r4, r0
	beq _080863EE
	ldr r0, _0808640C @ =0x030046A4
	ldr r0, [r0]
	mov sl, r0
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r1, [r0, r7]
	adds r0, r3, r1
	cmp r4, r0
	beq _080863EE
	subs r0, r3, r1
	cmp r4, r0
	bne _08086410
_080863EE:
	movs r1, #2
	ldrsh r0, [r5, r1]
	ldr r1, [r2]
	adds r1, #0x4a
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r0, r0, r1
	cmp r0, #0
	bge _08086402
	rsbs r0, r0, #0
_08086402:
	cmp r0, #0xff
	ble _08086408
	b _0808657E
_08086408:
	movs r0, #1
	b _08086580
	.align 2, 0
_0808640C: .4byte 0x030046A4
_08086410:
	movs r7, #2
	ldrsh r0, [r5, r7]
	ldr r1, [r2]
	adds r1, #0x4a
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r0, r0, r1
	cmp r0, #0
	bge _08086424
	rsbs r0, r0, #0
_08086424:
	cmp r0, #0xff
	ble _0808642A
	b _0808657E
_0808642A:
	mov r7, ip
	subs r1, r7, r6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08086478 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r0, sb
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
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
	blt _08086472
	cmp r1, #0
	blt _08086472
	ldr r0, _0808647C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08086472
	ldr r0, _08086480 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08086484
_08086472:
	movs r4, #0
	b _08086490
	.align 2, 0
_08086478: .4byte 0xFFFF0000
_0808647C: .4byte 0x030046A8
_08086480: .4byte 0x030046AC
_08086484:
	lsls r0, r1, #1
	mov r1, sl
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r4, r0, r2
_08086490:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080864A0
	adds r0, #4
	b _080864AC
_080864A0:
	ldr r0, _080864C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080864AC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080864C4
	cmp r2, #2
	beq _080864C8
	b _080864CC
	.align 2, 0
_080864C0: .4byte 0x030046A4
_080864C4:
	ldrb r0, [r6, #4]
	b _080864CA
_080864C8:
	ldrb r0, [r6]
_080864CA:
	subs r1, r1, r0
_080864CC:
	movs r2, #2
	ldrsh r0, [r5, r2]
	subs r0, r0, r1
	cmp r0, #0
	bge _080864D8
	rsbs r0, r0, #0
_080864D8:
	cmp r0, #0x7f
	ble _08086408
	ldrh r1, [r5]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r5, #4]
	mov r6, r8
	subs r1, r1, r6
	strh r1, [r0, #4]
	mov r6, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0808650E
	cmp r1, #0
	blt _0808650E
	ldr r0, _08086514 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0808650E
	ldr r0, _08086518 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0808651C
_0808650E:
	movs r4, #0
	b _0808652A
	.align 2, 0
_08086514: .4byte 0x030046A8
_08086518: .4byte 0x030046AC
_0808651C:
	ldr r0, _0808653C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0808652A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08086540
	adds r0, #4
	b _0808654C
	.align 2, 0
_0808653C: .4byte 0x030046A4
_08086540:
	ldr r0, _08086560 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0808654C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08086564
	cmp r2, #2
	beq _08086568
	b _0808656C
	.align 2, 0
_08086560: .4byte 0x030046A4
_08086564:
	ldrb r0, [r6, #4]
	b _0808656A
_08086568:
	ldrb r0, [r6]
_0808656A:
	subs r1, r1, r0
_0808656C:
	movs r7, #2
	ldrsh r0, [r5, r7]
	subs r0, r0, r1
	cmp r0, #0
	bge _08086578
	rsbs r0, r0, #0
_08086578:
	cmp r0, #0x7f
	bgt _0808657E
	b _08086408
_0808657E:
	movs r0, #0
_08086580:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08086590
FUN_08086590: @ 0x08086590
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	ldr r0, _080865B8 @ =0x03002C00
	ldr r3, [r0]
	cmp r3, #0
	beq _080865B2
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r1, [r2]
	ldr r2, [r2, #4]
	str r1, [r0]
	str r2, [r0, #4]
	ldr r1, _080865BC @ =0x0000038E
	adds r0, r3, r1
	strh r4, [r0]
_080865B2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080865B8: .4byte 0x03002C00
_080865BC: .4byte 0x0000038E

	thumb_func_start FUN_080865c0
FUN_080865c0: @ 0x080865C0
	push {lr}
	ldr r0, _080865D0 @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _080865D4
	adds r0, #0x48
	b _080865D6
	.align 2, 0
_080865D0: .4byte 0x03002C00
_080865D4:
	movs r0, #0
_080865D6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080865dc
FUN_080865dc: @ 0x080865DC
	push {lr}
	adds r2, r0, #0
	ldr r0, _080865F8 @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _08086600
	ldr r1, _080865FC @ =0x0000040C
	adds r0, r0, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #1
	b _08086608
	.align 2, 0
_080865F8: .4byte 0x03002C00
_080865FC: .4byte 0x0000040C
_08086600:
	strh r0, [r2]
	strh r0, [r2, #2]
	strh r0, [r2, #4]
	movs r0, #0
_08086608:
	pop {r1}
	bx r1

	thumb_func_start FUN_0808660c
FUN_0808660c: @ 0x0808660C
	push {lr}
	adds r1, r0, #0
	ldr r0, _08086628 @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _08086622
	ldr r2, _0808662C @ =0x000001F5
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, r1
	beq _08086630
_08086622:
	movs r0, #0
	b _08086632
	.align 2, 0
_08086628: .4byte 0x03002C00
_0808662C: .4byte 0x000001F5
_08086630:
	movs r0, #1
_08086632:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08086638
FUN_08086638: @ 0x08086638
	push {r4, r5, r6, lr}
	ldr r0, _080866C8 @ =0x03002C00
	ldr r5, [r0]
	cmp r5, #0
	beq _080866DC
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0808666E
	bl fetch_082316e4
	movs r2, #0xea
	lsls r2, r2, #2
	adds r1, r5, r2
	strh r0, [r1]
	bl fetch_082316e4
	ldr r2, _080866CC @ =0x000003AA
	adds r1, r5, r2
	strh r0, [r1]
	bl fetch_082316e4
	movs r2, #0xeb
	lsls r2, r2, #2
	adds r1, r5, r2
	strh r0, [r1]
_0808666E:
	movs r0, #0x52
	bl prepare_08231510
	cmp r0, #0
	beq _08086684
	bl fetch_082316e4
	movs r2, #0xec
	lsls r2, r2, #2
	adds r1, r5, r2
	str r0, [r1]
_08086684:
	ldr r1, _080866D0 @ =0x000001F5
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	bne _080866DC
	adds r6, r5, #0
	adds r6, #0x48
	adds r0, r6, #0
	bl FUN_0823629c
	cmp r0, #0xff
	beq _080866BC
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r4, r5, r2
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_082362fc
	movs r0, #0xea
	lsls r0, r0, #2
	adds r2, r5, r0
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_08235a84
	cmp r0, #0
	bne _080866D4
_080866BC:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08085ee0
	b _080866DC
	.align 2, 0
_080866C8: .4byte 0x03002C00
_080866CC: .4byte 0x000003AA
_080866D0: .4byte 0x000001F5
_080866D4:
	adds r0, r5, #0
	movs r1, #3
	bl FUN_08085ee0
_080866DC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080866e4
FUN_080866e4: @ 0x080866E4
	push {r4, lr}
	ldr r4, _08086708 @ =0x03002C00
	ldr r0, [r4]
	cmp r0, #0
	beq _08086700
	movs r1, #0
	bl FUN_08085ee0
	ldr r0, [r4]
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #1
	strh r1, [r0]
_08086700:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08086708: .4byte 0x03002C00

	thumb_func_start FUN_0808670c
FUN_0808670c: @ 0x0808670C
	push {lr}
	adds r1, r0, #0
	ldr r0, _08086724 @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _0808671E
	ldr r2, _08086728 @ =0x0000040A
	adds r0, r0, r2
	strb r1, [r0]
_0808671E:
	pop {r0}
	bx r0
	.align 2, 0
_08086724: .4byte 0x03002C00
_08086728: .4byte 0x0000040A

	thumb_func_start FUN_0808672c
FUN_0808672c: @ 0x0808672C
	push {lr}
	ldr r0, _08086788 @ =0x03002C00
	ldr r1, [r0]
	cmp r1, #0
	beq _08086798
	movs r2, #0xe5
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _08086798
	ldr r2, _0808678C @ =0x0000040A
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08086798
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08086798
	ldr r2, _08086790 @ =0x000003B6
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _08086798
	ldr r2, _08086794 @ =0x000001F5
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	bls _08086782
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08086798
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08086798
_08086782:
	movs r0, #1
	b _0808679A
	.align 2, 0
_08086788: .4byte 0x03002C00
_0808678C: .4byte 0x0000040A
_08086790: .4byte 0x000003B6
_08086794: .4byte 0x000001F5
_08086798:
	movs r0, #0
_0808679A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080867a0
FUN_080867a0: @ 0x080867A0
	push {r4, r5, lr}
	sub sp, #0x10
	ldr r0, _080867D4 @ =0x03002C00
	ldr r5, [r0]
	cmp r5, #0
	beq _0808683E
	ldr r1, _080867D8 @ =0x000001F5
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r4, r0, #0
	cmp r4, #1
	bne _080867E0
	adds r0, r5, #0
	bl FUN_08086080
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r3, #0
	strh r4, [r0]
	ldr r0, _080867DC @ =0x000003B6
	adds r1, r5, r0
	movs r0, #0x96
	lsls r0, r0, #1
	b _08086814
	.align 2, 0
_080867D4: .4byte 0x03002C00
_080867D8: .4byte 0x000001F5
_080867DC: .4byte 0x000003B6
_080867E0:
	cmp r4, #0
	beq _080867FE
	cmp r4, #2
	beq _080867FE
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0808683E
	movs r1, #0xc9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0808683E
_080867FE:
	adds r0, r5, #0
	bl FUN_08086080
	adds r0, r5, #0
	bl FUN_080860cc
	ldr r0, _08086848 @ =0x000003B6
	adds r1, r5, r0
	movs r3, #0
	movs r0, #0x96
	lsls r0, r0, #2
_08086814:
	strh r0, [r1]
	movs r1, #0x83
	lsls r1, r1, #3
	adds r2, r5, r1
	strh r3, [r2]
	ldr r0, _0808684C @ =0x00000414
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x40
	str r2, [sp]
	movs r2, #0xc8
	str r2, [sp, #4]
	movs r2, #0xfa
	str r2, [sp, #8]
	adds r2, #0x50
	str r2, [sp, #0xc]
	movs r2, #1
	bl FUN_080da9c4
	str r0, [r4]
_0808683E:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08086848: .4byte 0x000003B6
_0808684C: .4byte 0x00000414

	thumb_func_start FUN_08086850
FUN_08086850: @ 0x08086850
	push {lr}
	ldr r0, _08086868 @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _08086864
	ldr r1, _0808686C @ =0x000001F5
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08086870
_08086864:
	movs r0, #0
	b _08086872
	.align 2, 0
_08086868: .4byte 0x03002C00
_0808686C: .4byte 0x000001F5
_08086870:
	movs r0, #1
_08086872:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08086878
FUN_08086878: @ 0x08086878
	push {lr}
	ldr r0, _08086890 @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _08086894
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	b _08086898
	.align 2, 0
_08086890: .4byte 0x03002C00
_08086894:
	movs r0, #1
	rsbs r0, r0, #0
_08086898:
	pop {r1}
	bx r1

	thumb_func_start FUN_0808689c
FUN_0808689c: @ 0x0808689C
	push {lr}
	adds r1, r0, #0
	ldr r0, _080868B4 @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _080868B0
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r0, r0, r2
	strh r1, [r0]
_080868B0:
	pop {r0}
	bx r0
	.align 2, 0
_080868B4: .4byte 0x03002C00

	thumb_func_start FUN_080868b8
FUN_080868b8: @ 0x080868B8
	push {r4, r5, lr}
	adds r1, r0, #0
	ldr r0, _080868D4 @ =0x03002C00
	ldr r4, [r0]
	cmp r4, #0
	beq _0808690A
	cmp r1, #0
	beq _080868D8
	adds r0, r4, #0
	movs r1, #7
	bl FUN_08085ee0
	b _080868E0
	.align 2, 0
_080868D4: .4byte 0x03002C00
_080868D8:
	adds r0, r4, #0
	movs r1, #6
	bl FUN_08085ee0
_080868E0:
	movs r0, #0xfa
	lsls r0, r0, #1
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _080868FA
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_080f8cac
	movs r0, #0
	strb r0, [r5]
_080868FA:
	movs r0, #0xc8
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_08086080
_0808690A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08086910
FUN_08086910: @ 0x08086910
	push {r4, lr}
	ldr r0, _08086950 @ =0x03002C00
	ldr r4, [r0]
	cmp r4, #0
	beq _0808694A
	adds r0, r4, #0
	movs r1, #8
	bl FUN_08085ee0
	adds r0, r4, #0
	bl FUN_0808567c
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r2, r4, r0
	adds r0, r4, #0
	adds r0, #0xa0
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0xc8
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, _08086954 @ =0x000005DC
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_08086080
_0808694A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08086950: .4byte 0x03002C00
_08086954: .4byte 0x000005DC

	thumb_func_start FUN_08086958
FUN_08086958: @ 0x08086958
	push {lr}
	ldr r0, _0808696C @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _08086970
	movs r1, #0xe1
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	b _08086972
	.align 2, 0
_0808696C: .4byte 0x03002C00
_08086970:
	movs r0, #0
_08086972:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08086978
FUN_08086978: @ 0x08086978
	push {lr}
	adds r1, r0, #0
	ldr r0, _08086998 @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _08086992
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0808699C
_08086992:
	movs r0, #0
	b _0808699E
	.align 2, 0
_08086998: .4byte 0x03002C00
_0808699C:
	movs r0, #1
_0808699E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080869a4
FUN_080869a4: @ 0x080869A4
	push {lr}
	ldr r0, _080869B8 @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _080869C0
	ldr r1, _080869BC @ =0x00000386
	adds r0, r0, r1
	ldrh r0, [r0]
	b _080869C2
	.align 2, 0
_080869B8: .4byte 0x03002C00
_080869BC: .4byte 0x00000386
_080869C0:
	movs r0, #0
_080869C2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080869c8
FUN_080869c8: @ 0x080869C8
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	ldr r3, _080869F0 @ =0x03002C00
	ldr r1, [r3]
	cmp r1, #0
	beq _080869EA
	movs r0, #0xe1
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrb r0, [r1]
	orrs r2, r0
	strb r2, [r1]
	ldr r0, [r3]
	ldr r1, _080869F4 @ =0x00000386
	adds r0, r0, r1
	strh r4, [r0]
_080869EA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080869F0: .4byte 0x03002C00
_080869F4: .4byte 0x00000386

	thumb_func_start FUN_080869f8
FUN_080869f8: @ 0x080869F8
	push {lr}
	adds r2, r0, #0
	ldr r3, _08086A20 @ =0x03002C00
	ldr r1, [r3]
	cmp r1, #0
	beq _08086A1A
	movs r0, #0xe1
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrb r0, [r1]
	bics r0, r2
	movs r2, #0
	strb r0, [r1]
	ldr r0, [r3]
	ldr r1, _08086A24 @ =0x00000386
	adds r0, r0, r1
	strh r2, [r0]
_08086A1A:
	pop {r0}
	bx r0
	.align 2, 0
_08086A20: .4byte 0x03002C00
_08086A24: .4byte 0x00000386

	thumb_func_start FUN_08086a28
FUN_08086a28: @ 0x08086A28
	push {lr}
	adds r2, r0, #0
	ldr r0, _08086A40 @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _08086A44
	ldr r1, [r0, #0x4c]
	ldr r0, [r0, #0x48]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #1
	b _08086A46
	.align 2, 0
_08086A40: .4byte 0x03002C00
_08086A44:
	movs r0, #0
_08086A46:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08086a4c
FUN_08086a4c: @ 0x08086A4C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08086AAC @ =0x03002C00
	ldr r3, [r0]
	cmp r3, #0
	beq _08086AA4
	movs r0, #0xfc
	lsls r0, r0, #1
	adds r2, r3, r0
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x48]
	str r1, [r3, #0x4c]
	adds r2, r3, #0
	adds r2, #0xa0
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _08086AB0 @ =0x0000031E
	adds r0, r3, r1
	ldrh r0, [r0]
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	adds r1, r3, #0
	adds r1, #0xa4
	ldr r2, _08086AB4 @ =0x00000322
	adds r0, r3, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2]
	str r1, [r2, #4]
_08086AA4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08086AAC: .4byte 0x03002C00
_08086AB0: .4byte 0x0000031E
_08086AB4: .4byte 0x00000322

	thumb_func_start FUN_08086ab8
FUN_08086ab8: @ 0x08086AB8
	push {lr}
	ldr r0, _08086AE0 @ =0x03002C00
	ldr r1, [r0]
	cmp r1, #0
	beq _08086AE8
	ldrb r0, [r1, #0x1a]
	cmp r0, #4
	bne _08086AE8
	ldr r2, _08086AE4 @ =0x000001F5
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #4
	bhi _08086AE8
	adds r0, r1, #0
	movs r1, #9
	bl FUN_08085ee0
	movs r0, #1
	b _08086AEA
	.align 2, 0
_08086AE0: .4byte 0x03002C00
_08086AE4: .4byte 0x000001F5
_08086AE8:
	movs r0, #0
_08086AEA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08086af0
FUN_08086af0: @ 0x08086AF0
	push {lr}
	ldr r0, _08086B0C @ =0x03002C00
	ldr r1, [r0]
	cmp r1, #0
	beq _08086B10
	ldrb r0, [r1, #0x1a]
	cmp r0, #4
	bne _08086B10
	adds r0, r1, #0
	movs r1, #0xa
	bl FUN_08085ee0
	movs r0, #1
	b _08086B12
	.align 2, 0
_08086B0C: .4byte 0x03002C00
_08086B10:
	movs r0, #0
_08086B12:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08086b18
FUN_08086b18: @ 0x08086B18
	push {r4, r5, r6, lr}
	ldr r5, _08086B8C @ =0x03002C00
	ldr r3, [r5]
	cmp r3, #0
	beq _08086BC2
	movs r4, #0xef
	lsls r4, r4, #2
	adds r2, r3, r4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r3, #0
	movs r1, #0xe
	bl FUN_08085ee0
	ldr r3, [r5]
	movs r0, #0x81
	lsls r0, r0, #3
	adds r1, r3, r0
	movs r0, #0xf
	strh r0, [r1]
	ldr r0, _08086B90 @ =0x03002BE0
	ldr r2, [r0]
	movs r6, #0x2c
	ldrsh r1, [r2, r6]
	adds r4, r3, r4
	movs r6, #0
	ldrsh r0, [r4, r6]
	subs r4, r1, r0
	movs r0, #0x30
	ldrsh r1, [r2, r0]
	movs r2, #0xf0
	lsls r2, r2, #2
	adds r0, r3, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	subs r1, r1, r0
	cmp r4, #0
	bne _08086B6C
	cmp r1, #0
	beq _08086B98
_08086B6C:
	adds r0, r4, #0
	bl FUN_0823785c
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	ldr r2, [r5]
	adds r0, #7
	movs r1, #7
	ands r0, r1
	ldr r1, _08086B94 @ =0x00000404
	adds r2, r2, r1
	strh r0, [r2]
	b _08086BB6
	.align 2, 0
_08086B8C: .4byte 0x03002C00
_08086B90: .4byte 0x03002BE0
_08086B94: .4byte 0x00000404
_08086B98:
	ldr r2, _08086BC8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08086BCC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08086BD0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	ldr r6, _08086BD4 @ =0x00000404
	adds r1, r3, r6
	strh r0, [r1]
_08086BB6:
	ldr r0, _08086BD8 @ =0x03002C00
	ldr r0, [r0]
	ldr r1, _08086BDC @ =0x00000402
	adds r0, r0, r1
	movs r1, #0x1d
	strh r1, [r0]
_08086BC2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08086BC8: .4byte 0x030046B8
_08086BCC: .4byte 0x000003FF
_08086BD0: .4byte 0x0203B400
_08086BD4: .4byte 0x00000404
_08086BD8: .4byte 0x03002C00
_08086BDC: .4byte 0x00000402

	thumb_func_start FUN_08086be0
FUN_08086be0: @ 0x08086BE0
	push {r4, lr}
	sub sp, #8
	ldr r0, _08086C4C @ =0x03002C00
	ldr r4, [r0]
	cmp r4, #0
	beq _08086C44
	mov r0, sp
	bl FUN_0823167c
	adds r0, r4, #0
	adds r0, #0x48
	movs r1, #0
	ldrsh r2, [r0, r1]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	adds r0, r4, #0
	adds r0, #0x4a
	movs r1, #0
	ldrsh r2, [r0, r1]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	adds r0, r4, #0
	adds r0, #0x4c
	movs r1, #0
	ldrsh r2, [r0, r1]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r2, [r0]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
_08086C44:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08086C4C: .4byte 0x03002C00

	thumb_func_start FUN_08086c50
FUN_08086c50: @ 0x08086C50
	push {r4, r5, r6, lr}
	ldr r0, _08086CB4 @ =0x03002C00
	ldr r5, [r0]
	cmp r5, #0
	bne _08086C5C
	b _08086D56
_08086C5C:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08086D40
	bl fetch_082316e4
	movs r1, #0xfc
	lsls r1, r1, #1
	adds r4, r5, r1
	strh r0, [r4]
	bl fetch_082316e4
	movs r2, #0xfd
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	bl fetch_082316e4
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	adds r6, r4, #0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08086CB0
	cmp r1, #0
	blt _08086CB0
	ldr r0, _08086CB8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08086CB0
	ldr r0, _08086CBC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08086CC0
_08086CB0:
	movs r4, #0
	b _08086CCE
	.align 2, 0
_08086CB4: .4byte 0x03002C00
_08086CB8: .4byte 0x030046A8
_08086CBC: .4byte 0x030046AC
_08086CC0:
	ldr r0, _08086CE0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08086CCE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08086CE4
	adds r0, #4
	b _08086CF0
	.align 2, 0
_08086CE0: .4byte 0x030046A4
_08086CE4:
	ldr r0, _08086D04 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08086CF0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08086D08
	cmp r2, #2
	beq _08086D0C
	b _08086D10
	.align 2, 0
_08086D04: .4byte 0x030046A4
_08086D08:
	ldrb r0, [r6, #4]
	b _08086D0E
_08086D0C:
	ldrb r0, [r6]
_08086D0E:
	subs r1, r1, r0
_08086D10:
	movs r2, #0xfd
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	movs r0, #0xfc
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x48]
	str r1, [r5, #0x4c]
	adds r3, r5, #0
	adds r3, #0xa0
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	movs r1, #0xf1
	lsls r1, r1, #2
	adds r3, r5, r1
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
_08086D40:
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _08086D56
	bl fetch_082316e4
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r5, r2
	strb r0, [r1]
_08086D56:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08086d5c
FUN_08086d5c: @ 0x08086D5C
	push {lr}
	ldr r0, _08086D74 @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _08086D6E
	ldr r2, _08086D78 @ =0x0000040B
	adds r1, r0, r2
	movs r0, #1
	strb r0, [r1]
_08086D6E:
	pop {r0}
	bx r0
	.align 2, 0
_08086D74: .4byte 0x03002C00
_08086D78: .4byte 0x0000040B

	thumb_func_start FUN_08086d7c
FUN_08086d7c: @ 0x08086D7C
	push {r4, lr}
	ldr r0, _08086DAC @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08086DB0 @ =0x00000252
	adds r1, r0, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _08086DA4
	movs r4, #0
_08086D90:
	adds r0, r4, #0
	bl GetValuableItemID
	subs r0, #0x38
	cmp r0, #7
	bls _08086DA4
	adds r4, #1
	cmp r4, #0xf
	ble _08086D90
	movs r0, #0
_08086DA4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08086DAC: .4byte 0x030046A0
_08086DB0: .4byte 0x00000252

	thumb_func_start FUN_08086db4
FUN_08086db4: @ 0x08086DB4
	push {r4, r5, lr}
	ldr r0, _08086DC8 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08086DCC @ =0x00000252
	adds r1, r0, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _08086DDA
	b _08086DF2
	.align 2, 0
_08086DC8: .4byte 0x030046A0
_08086DCC: .4byte 0x00000252
_08086DD0:
	adds r0, r5, #0
	bl RemoveValuable
	adds r0, r4, #0
	b _08086DF2
_08086DDA:
	movs r5, #0
_08086DDC:
	adds r0, r5, #0
	bl GetValuableItemID
	adds r4, r0, #0
	subs r4, #0x38
	cmp r4, #7
	bls _08086DD0
	adds r5, #1
	cmp r5, #0xf
	ble _08086DDC
	movs r0, #0
_08086DF2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08086df8
FUN_08086df8: @ 0x08086DF8
	push {r4, lr}
	adds r4, r0, #0
	strh r1, [r4, #0x18]
	bl FUN_08086db4
	ldr r3, _08086E48 @ =0x030046A0
	ldr r1, [r3]
	ldr r2, _08086E4C @ =0x00000252
	adds r1, r1, r2
	strh r0, [r1]
	ldr r0, [r3]
	adds r0, r0, r2
	ldrh r0, [r0]
	strb r0, [r4, #0x1a]
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _08086E22
	bl fetch_082316e4
_08086E22:
	strh r0, [r4, #0x1c]
	ldr r1, _08086E50 @ =0x085ABFE8
	ldrb r0, [r4, #0x1a]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x1e]
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _08086E54
	bl fetch_082316e4
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08085ee0
	b _08086E5C
	.align 2, 0
_08086E48: .4byte 0x030046A0
_08086E4C: .4byte 0x00000252
_08086E50: .4byte 0x085ABFE8
_08086E54:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08085ee0
_08086E5C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08086e64
FUN_08086e64: @ 0x08086E64
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x72
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _08086E9C
	bl fetch_082316e4
	movs r2, #0xea
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	bl fetch_082316e4
	ldr r3, _08086E98 @ =0x000003AA
	adds r1, r4, r3
	strh r0, [r1]
	bl fetch_082316e4
	movs r2, #0xeb
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	b _08086EB0
	.align 2, 0
_08086E98: .4byte 0x000003AA
_08086E9C:
	movs r3, #0xea
	lsls r3, r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	ldr r2, _08086ECC @ =0x000003AA
	adds r0, r4, r2
	strh r1, [r0]
	adds r3, #4
	adds r0, r4, r3
	strh r1, [r0]
_08086EB0:
	movs r0, #0x4f
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _08086ED0
	bl fetch_082316e4
	movs r2, #0xec
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	b _08086ED8
	.align 2, 0
_08086ECC: .4byte 0x000003AA
_08086ED0:
	movs r3, #0xec
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
_08086ED8:
	ldr r1, _08086F18 @ =0x085ABFF8
	ldrb r0, [r4, #0x1a]
	adds r0, r0, r1
	ldrb r1, [r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	ldr r2, _08086F1C @ =0x000003A6
	adds r1, r4, r2
	strh r0, [r1]
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r1, r4, r3
	strh r0, [r1]
	ldrb r0, [r4, #0x1a]
	cmp r0, #2
	bne _08086F28
	ldr r0, _08086F20 @ =0x000003A2
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	ldr r2, _08086F24 @ =0x000001F5
	adds r1, r4, r2
	ldrb r0, [r1]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08086F46
	movs r0, #0
	strb r0, [r1]
	b _08086F46
	.align 2, 0
_08086F18: .4byte 0x085ABFF8
_08086F1C: .4byte 0x000003A6
_08086F20: .4byte 0x000003A2
_08086F24: .4byte 0x000001F5
_08086F28:
	ldr r3, _08086F7C @ =0x000003A2
	adds r1, r4, r3
	movs r0, #1
	strh r0, [r1]
	ldr r1, _08086F80 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08086F46
	adds r0, r4, #0
	bl FUN_080860cc
_08086F46:
	ldr r1, _08086F84 @ =0x085ABFF8
	ldrb r0, [r4, #0x1a]
	adds r0, r0, r1
	ldrb r1, [r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r2, _08086F88 @ =0x00000392
	adds r1, r4, r2
	movs r2, #0
	strh r0, [r1]
	movs r3, #0xe4
	lsls r3, r3, #2
	adds r1, r4, r3
	strh r0, [r1]
	ldr r0, _08086F8C @ =0x0000039A
	adds r1, r4, r0
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08086F7C: .4byte 0x000003A2
_08086F80: .4byte 0x000001F5
_08086F84: .4byte 0x085ABFF8
_08086F88: .4byte 0x00000392
_08086F8C: .4byte 0x0000039A

	thumb_func_start FUN_08086f90
FUN_08086f90: @ 0x08086F90
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0x1a]
	movs r1, #0xc7
	lsls r1, r1, #2
	adds r5, r6, r1
	strh r0, [r5]
	adds r4, r6, #0
	adds r4, #0xb0
	ldr r1, _08087004 @ =0x00002499
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r6, #0
	adds r0, #0x84
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	ldrh r1, [r5]
	ldr r2, _08087008 @ =0x0000032E
	adds r0, r6, r2
	strh r1, [r0]
	ldrh r1, [r0]
	ldr r0, _0808700C @ =0x00000207
	adds r1, r1, r0
	adds r0, r4, #0
	bl FUN_0822b20c
	adds r0, r6, #0
	adds r0, #0xbc
	subs r4, #0x90
	ldr r2, [r0]
	adds r1, r4, #0
	movs r3, #0xf
_08086FD6:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _08086FD6
	adds r0, r6, #0
	adds r0, #0xbc
	str r4, [r0]
	movs r0, #0x64
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _08087010
	bl fetch_082316e4
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r6, r2
	strb r0, [r1]
	b _08087018
	.align 2, 0
_08087004: .4byte 0x00002499
_08087008: .4byte 0x0000032E
_0808700C: .4byte 0x00000207
_08087010:
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r6, r2
	strb r1, [r0]
_08087018:
	ldr r0, _0808704C @ =0x0000922E
	ldr r1, _08087050 @ =0x00003D95
	bl FUN_082310cc
	movs r2, #0xf0
	lsls r2, r2, #1
	adds r1, r6, r2
	str r0, [r1]
	adds r0, r6, #0
	movs r1, #0
	bl FUN_08086024
	ldr r1, _08087054 @ =0x0000031E
	adds r0, r6, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xc8
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808704C: .4byte 0x0000922E
_08087050: .4byte 0x00003D95
_08087054: .4byte 0x0000031E

	thumb_func_start FUN_08087058
FUN_08087058: @ 0x08087058
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _08087090
	bl fetch_082316e4
	movs r2, #0xfc
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	bl fetch_082316e4
	movs r2, #0xfd
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	bl fetch_082316e4
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	b _080870A4
_08087090:
	movs r2, #0xfc
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
_080870A4:
	movs r0, #0xfc
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080870CE
	cmp r1, #0
	blt _080870CE
	ldr r0, _080870D4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080870CE
	ldr r0, _080870D8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080870DC
_080870CE:
	movs r4, #0
	b _080870EA
	.align 2, 0
_080870D4: .4byte 0x030046A8
_080870D8: .4byte 0x030046AC
_080870DC:
	ldr r0, _080870FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080870EA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08087100
	adds r0, #4
	b _0808710C
	.align 2, 0
_080870FC: .4byte 0x030046A4
_08087100:
	ldr r0, _08087120 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0808710C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08087124
	cmp r2, #2
	beq _08087128
	b _0808712C
	.align 2, 0
_08087120: .4byte 0x030046A4
_08087124:
	ldrb r0, [r6, #4]
	b _0808712A
_08087128:
	ldrb r0, [r6]
_0808712A:
	subs r1, r1, r0
_0808712C:
	movs r2, #0xfd
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	adds r3, r5, #0
	adds r3, #0xa0
	movs r0, #0xfc
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	movs r1, #0xf1
	lsls r1, r1, #2
	adds r3, r5, r1
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r3, r5, r0
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	adds r4, r5, #0
	adds r4, #0x40
	ldrh r1, [r5, #0x18]
	movs r0, #6
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823b400
	adds r1, r5, #0
	adds r1, #0x84
	adds r0, r4, #0
	bl FUN_0823b46c
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r1, r5, #0
	adds r1, #0x45
	strb r0, [r1]
	ldrh r1, [r4]
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldrb r0, [r5, #0x1a]
	cmp r0, #3
	beq _080871D4
	ldrh r0, [r5, #0x1c]
	cmp r0, #0
	bne _080871BC
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #1
	bl FUN_080f8c58
	b _080871CA
_080871BC:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r1, r4, #0
	movs r2, #4
	bl FUN_080f8c58
_080871CA:
	movs r0, #0xfa
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080871D4:
	adds r0, r4, #0
	bl FUN_08002a48
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080871e4
FUN_080871e4: @ 0x080871E4
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0xdc
	ldr r2, _08087280 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x5a
	orrs r0, r3
	ldr r4, _08087284 @ =0x0000FFFF
	ands r0, r4
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r3, #0x64
	orrs r0, r3
	ands r0, r4
	movs r1, #0xc8
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r1, #4]
	ldrb r0, [r5, #0x1a]
	adds r4, r1, #0
	cmp r0, #3
	beq _08087238
	ldrh r0, [r5, #0x1c]
	movs r3, #2
	cmp r0, #0
	bne _0808723A
_08087238:
	movs r3, #0x10
_0808723A:
	ldrh r1, [r5, #0x18]
	ldr r2, _08087288 @ =0x00004081
	str r3, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r4, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236514
	ldr r1, _0808728C @ =FUN_08087528
	adds r0, r6, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r1, r5, #0
	adds r1, #0x48
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
_08087280: .4byte 0xFFFF0000
_08087284: .4byte 0x0000FFFF
_08087288: .4byte 0x00004081
_0808728C: .4byte FUN_08087528

	thumb_func_start FUN_08087290
FUN_08087290: @ 0x08087290
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	movs r0, #0x96
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r2, _08087304 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _08087308 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
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
	ldrh r1, [r5, #0x18]
	ldr r2, _0808730C @ =0x00002001
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
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r1, #0x32
	movs r2, #0x32
	movs r3, #0
	bl FUN_082364f8
	adds r0, r4, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_0823651c
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08087304: .4byte 0xFFFF0000
_08087308: .4byte 0x0000FFFF
_0808730C: .4byte 0x00002001

	thumb_func_start FUN_08087310
FUN_08087310: @ 0x08087310
	push {r4, lr}
	movs r2, #0xf5
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r4, #0
	movs r3, #2
	strh r3, [r1]
	adds r2, #2
	adds r1, r0, r2
	strh r4, [r1]
	ldr r1, _080873A4 @ =0x000003DA
	adds r2, r0, r1
	movs r1, #0x40
	strh r1, [r2]
	movs r1, #0xf7
	lsls r1, r1, #2
	adds r2, r0, r1
	movs r1, #3
	strh r1, [r2]
	ldr r1, _080873A8 @ =0x000003DE
	adds r2, r0, r1
	movs r1, #6
	strh r1, [r2]
	movs r2, #0xf8
	lsls r2, r2, #2
	adds r1, r0, r2
	strh r3, [r1]
	adds r2, #2
	adds r1, r0, r2
	strh r3, [r1]
	movs r3, #0xf9
	lsls r3, r3, #2
	adds r2, r0, r3
	movs r1, #0x3c
	strh r1, [r2]
	ldr r1, _080873AC @ =0x000003E6
	adds r2, r0, r1
	movs r1, #8
	strh r1, [r2]
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r1, r0, r2
	strh r4, [r1]
	adds r3, #6
	adds r1, r0, r3
	movs r2, #0xff
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r4, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r4, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r4, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	ldr r1, _080873B0 @ =0x000003FA
	adds r0, r0, r1
	strh r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080873A4: .4byte 0x000003DA
_080873A8: .4byte 0x000003DE
_080873AC: .4byte 0x000003E6
_080873B0: .4byte 0x000003FA

	thumb_func_start FUN_080873b4
FUN_080873b4: @ 0x080873B4
	push {r4, r5, lr}
	sub sp, #0x10
	adds r2, r0, #0
	ldr r0, _0808741C @ =0x00000326
	adds r3, r2, r0
	ldrh r0, [r3]
	adds r1, r0, r1
	strh r1, [r3]
	movs r0, #0xc9
	lsls r0, r0, #2
	adds r4, r2, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08087428
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	movs r5, #0x96
	lsls r5, r5, #3
	cmp r0, r5
	bls _08087436
	strh r5, [r3]
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08087436
	ldr r1, _08087420 @ =0x000001F5
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _08087436
	movs r0, #1
	strh r0, [r4]
	ldr r0, _08087424 @ =0x00000414
	adds r4, r2, r0
	ldr r0, [r4]
	adds r1, r2, #0
	adds r1, #0x40
	str r3, [sp]
	str r5, [sp, #4]
	movs r2, #0xfa
	str r2, [sp, #8]
	adds r2, #0x28
	str r2, [sp, #0xc]
	movs r2, #1
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r4]
	b _08087436
	.align 2, 0
_0808741C: .4byte 0x00000326
_08087420: .4byte 0x000001F5
_08087424: .4byte 0x00000414
_08087428:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x96
	lsls r1, r1, #3
	cmp r0, r1
	bls _08087436
	strh r1, [r3]
_08087436:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08087440
FUN_08087440: @ 0x08087440
	push {r4, lr}
	sub sp, #0x10
	adds r1, r0, #0
	ldr r0, _0808748C @ =0x00000326
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _08087484
	subs r0, #1
	movs r3, #0
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _08087484
	movs r4, #0xc9
	lsls r4, r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	strh r3, [r2]
	ldr r0, _08087490 @ =0x00000414
	adds r4, r1, r0
	ldr r0, [r4]
	adds r1, #0x40
	str r3, [sp]
	str r3, [sp, #4]
	movs r2, #0xfa
	str r2, [sp, #8]
	adds r2, #0x28
	str r2, [sp, #0xc]
	movs r2, #0x7f
	bl FUN_080da9c4
	str r0, [r4]
_08087484:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808748C: .4byte 0x00000326
_08087490: .4byte 0x00000414

	thumb_func_start FUN_08087494
FUN_08087494: @ 0x08087494
	push {r4, lr}
	ldr r1, _080874B4 @ =0x000003B6
	adds r2, r0, r1
	ldrh r1, [r2]
	adds r3, r1, #0
	cmp r3, #0
	beq _080874C4
	ldr r4, _080874B8 @ =0x000001F5
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #1
	bne _080874C0
	cmp r3, #2
	bls _080874BC
	subs r0, r1, #2
	b _080874C2
	.align 2, 0
_080874B4: .4byte 0x000003B6
_080874B8: .4byte 0x000001F5
_080874BC:
	movs r0, #0
	b _080874C2
_080874C0:
	subs r0, r1, #1
_080874C2:
	strh r0, [r2]
_080874C4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080874cc
FUN_080874cc: @ 0x080874CC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08087508 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0808751C
	adds r0, r4, #0
	bl FUN_08087440
	adds r0, r4, #0
	bl FUN_08087494
	ldr r0, _0808750C @ =0x00000332
	adds r3, r4, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _08087510
	adds r2, r4, #0
	adds r2, #0xe2
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	b _0808751C
	.align 2, 0
_08087508: .4byte 0x030047A4
_0808750C: .4byte 0x00000332
_08087510:
	adds r2, r4, #0
	adds r2, #0xe2
	ldrh r1, [r2]
	ldr r0, _08087524 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
_0808751C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08087524: .4byte 0x0000FFFB

	thumb_func_start FUN_08087528
FUN_08087528: @ 0x08087528
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r1, #0x80
	lsls r1, r1, #4
	ldrh r0, [r3, #6]
	ands r0, r1
	cmp r0, #0
	bne _080875DC
	adds r5, r2, #0
	ldrb r0, [r5, #0x1b]
	cmp r0, #1
	beq _080875DC
	movs r2, #0
	ldrh r0, [r5, #0x1c]
	cmp r0, #0
	bne _0808755E
	ldrh r1, [r3, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08087564
	ldr r0, [r3, #0x34]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08087560
	b _08087564
_0808755E:
	movs r2, #1
_08087560:
	cmp r2, #0
	beq _080875DC
_08087564:
	ldr r1, _08087584 @ =0x00000332
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080875DC
	ldrh r0, [r3, #0x3c]
	cmp r0, #0
	beq _080875DC
	movs r0, #1
	ldr r1, [r3, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _08087588
	movs r1, #0xc8
	b _080875C4
	.align 2, 0
_08087584: .4byte 0x00000332
_08087588:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08087598
	movs r1, #0x96
	lsls r1, r1, #1
	movs r4, #0xc
	b _080875C6
_08087598:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080875A6
	movs r1, #0xfa
	lsls r1, r1, #1
	b _080875C4
_080875A6:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080875B2
	movs r1, #0x96
	b _080875C4
_080875B2:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _080875C0
	movs r1, #0xfa
	lsls r1, r1, #1
	b _080875C4
_080875C0:
	movs r1, #0xc8
	lsls r1, r1, #1
_080875C4:
	movs r4, #8
_080875C6:
	adds r0, r5, #0
	bl FUN_080873b4
	movs r1, #0xcc
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #4
	strh r1, [r0]
	ldr r1, _080875E4 @ =0x00000332
	adds r0, r5, r1
	strh r4, [r0]
_080875DC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080875E4: .4byte 0x00000332

	thumb_func_start FUN_080875e8
FUN_080875e8: @ 0x080875E8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08087624 @ =0x0000040C
	adds r2, r4, r0
	ldr r0, [r4, #0x48]
	ldr r1, [r4, #0x4c]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r2, _08087628 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	cmp r0, #0
	blt _0808762C
	asrs r3, r0, #0xc
	b _08087632
	.align 2, 0
_08087624: .4byte 0x0000040C
_08087628: .4byte 0x085B0A08
_0808762C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08087632:
	ldr r0, _08087650 @ =0x0000040C
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	cmp r0, #0
	blt _08087654
	asrs r2, r0, #0xc
	b _0808765A
	.align 2, 0
_08087650: .4byte 0x0000040C
_08087654:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0808765A:
	movs r0, #0x82
	lsls r0, r0, #3
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808766c
FUN_0808766c: @ 0x0808766C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe1
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08087716
	ldr r2, _080876B4 @ =0x000001F5
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #5
	beq _08087716
	adds r6, r5, #0
	adds r6, #0x48
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080876AE
	cmp r1, #0
	blt _080876AE
	ldr r0, _080876B8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080876AE
	ldr r0, _080876BC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080876C0
_080876AE:
	movs r4, #0
	b _080876CE
	.align 2, 0
_080876B4: .4byte 0x000001F5
_080876B8: .4byte 0x030046A8
_080876BC: .4byte 0x030046AC
_080876C0:
	ldr r0, _080876E0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080876CE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080876E4
	adds r0, #4
	b _080876F0
	.align 2, 0
_080876E0: .4byte 0x030046A4
_080876E4:
	ldr r0, _08087704 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080876F0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08087708
	cmp r2, #2
	beq _0808770C
	b _08087710
	.align 2, 0
_08087704: .4byte 0x030046A4
_08087708:
	ldrb r0, [r6, #4]
	b _0808770E
_0808770C:
	ldrb r0, [r6]
_0808770E:
	subs r1, r1, r0
_08087710:
	adds r0, r5, #0
	adds r0, #0x4a
	strh r1, [r0]
_08087716:
	adds r4, r5, #0
	adds r4, #0x48
	ldr r1, _08087784 @ =0x0000031E
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r4]
	adds r0, r0, r2
	adds r1, r5, #0
	adds r1, #0xa0
	strh r0, [r1]
	subs r1, #0x56
	movs r2, #0xc8
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0xa2
	strh r0, [r1]
	subs r1, #0x56
	adds r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0xa4
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xdc
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08087780
	cmp r1, #0
	blt _08087780
	ldr r0, _08087788 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08087780
	ldr r0, _0808778C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087790
_08087780:
	movs r0, #0
	b _0808779E
	.align 2, 0
_08087784: .4byte 0x0000031E
_08087788: .4byte 0x030046A8
_0808778C: .4byte 0x030046AC
_08087790:
	ldr r0, _080877B8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_0808779E:
	adds r2, r5, #0
	adds r2, #0xd2
	strh r0, [r2]
	ldrh r4, [r2]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080877BC
	adds r2, r0, #4
	b _080877C8
	.align 2, 0
_080877B8: .4byte 0x030046A4
_080877BC:
	ldr r0, _08087810 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r2, r1, r0
_080877C8:
	ldrb r0, [r2]
	lsrs r0, r0, #4
	adds r1, r5, #0
	adds r1, #0xd7
	strb r0, [r1]
	ldrb r1, [r2]
	movs r0, #0xf
	ands r0, r1
	adds r1, r5, #0
	adds r1, #0xd5
	strb r0, [r1]
	ldrh r0, [r2, #2]
	adds r2, r5, #0
	adds r2, #0xda
	strh r0, [r2]
	adds r0, r5, #0
	bl FUN_080875e8
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r5, #0x48]
	ldr r1, [r5, #0x4c]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _08087814 @ =0x0000038E
	adds r0, r5, r2
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08087810: .4byte 0x030046A4
_08087814: .4byte 0x0000038E

	thumb_func_start FUN_08087818
FUN_08087818: @ 0x08087818
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0xff
	lsls r0, r0, #2
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, #0
	bne _0808782E
	adds r0, #1
	strh r0, [r1]
	b _08087968
_0808782E:
	ldr r1, _08087878 @ =0x000001F5
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _0808783A
	b _08087968
_0808783A:
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08087848
	b _08087968
_08087848:
	adds r0, r6, #0
	adds r0, #0x48
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r5, r0, #0
	cmp r2, #0
	blt _08087872
	cmp r1, #0
	blt _08087872
	ldr r0, _0808787C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08087872
	ldr r0, _08087880 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087884
_08087872:
	movs r4, #0
	b _08087892
	.align 2, 0
_08087878: .4byte 0x000001F5
_0808787C: .4byte 0x030046A8
_08087880: .4byte 0x030046AC
_08087884:
	ldr r0, _080878A4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08087892:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080878A8
	adds r0, #4
	b _080878B4
	.align 2, 0
_080878A4: .4byte 0x030046A4
_080878A8:
	ldr r0, _080878F0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080878B4:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	bne _08087964
	ldr r1, _080878F4 @ =0x000001F5
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08087968
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080878EC
	cmp r1, #0
	blt _080878EC
	ldr r0, _080878F8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080878EC
	ldr r0, _080878FC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087900
_080878EC:
	movs r4, #0
	b _0808790E
	.align 2, 0
_080878F0: .4byte 0x030046A4
_080878F4: .4byte 0x000001F5
_080878F8: .4byte 0x030046A8
_080878FC: .4byte 0x030046AC
_08087900:
	ldr r0, _08087920 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0808790E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08087924
	adds r0, #4
	b _08087930
	.align 2, 0
_08087920: .4byte 0x030046A4
_08087924:
	ldr r0, _08087944 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08087930:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08087948
	cmp r2, #2
	beq _0808794C
	b _08087950
	.align 2, 0
_08087944: .4byte 0x030046A4
_08087948:
	ldrb r0, [r5, #4]
	b _0808794E
_0808794C:
	ldrb r0, [r5]
_0808794E:
	subs r1, r1, r0
_08087950:
	adds r0, r6, #0
	adds r0, #0x4a
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _08087960
	rsbs r0, r0, #0
_08087960:
	cmp r0, #0xff
	ble _08087968
_08087964:
	movs r0, #1
	b _0808796A
_08087968:
	movs r0, #0
_0808796A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08087970
FUN_08087970: @ 0x08087970
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08087818
	cmp r0, #0
	beq _08087982
	adds r0, r4, #0
	bl FUN_0808613c
_08087982:
	ldr r1, _08087998 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x10
	bhi _08087A4C
	lsls r0, r0, #2
	ldr r1, _0808799C @ =_080879A0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08087998: .4byte 0x000001F5
_0808799C: .4byte _080879A0
_080879A0: @ jump table
	.4byte _080879E4 @ case 0
	.4byte _080879FC @ case 1
	.4byte _08087A4C @ case 2
	.4byte _080879E4 @ case 3
	.4byte _080879E4 @ case 4
	.4byte _08087A4C @ case 5
	.4byte _08087A4C @ case 6
	.4byte _08087A4C @ case 7
	.4byte _08087A4C @ case 8
	.4byte _08087A4C @ case 9
	.4byte _08087A4C @ case 10
	.4byte _08087A4C @ case 11
	.4byte _08087A4C @ case 12
	.4byte _08087A4C @ case 13
	.4byte _08087A4C @ case 14
	.4byte _08087A18 @ case 15
	.4byte _08087A30 @ case 16
_080879E4:
	ldr r0, _080879F8 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	beq _08087A0C
	b _08087A4C
	.align 2, 0
_080879F8: .4byte 0x03002BE0
_080879FC:
	ldr r0, _08087A10 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _08087A14
_08087A0C:
	movs r0, #1
	b _08087A52
	.align 2, 0
_08087A10: .4byte 0x03002BE0
_08087A14:
	movs r0, #0
	b _08087A52
_08087A18:
	ldr r0, _08087A2C @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	beq _08087A40
	b _08087A4C
	.align 2, 0
_08087A2C: .4byte 0x03002BE0
_08087A30:
	ldr r0, _08087A44 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _08087A48
_08087A40:
	movs r0, #0x10
	b _08087A52
	.align 2, 0
_08087A44: .4byte 0x03002BE0
_08087A48:
	movs r0, #0xf
	b _08087A52
_08087A4C:
	ldr r1, _08087A58 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
_08087A52:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08087A58: .4byte 0x000001F5

	thumb_func_start FUN_08087a5c
FUN_08087a5c: @ 0x08087A5C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldr r0, _08087A84 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08087A76
	b _08087B96
_08087A76:
	ldr r0, _08087A88 @ =0x00000396
	adds r2, r6, r0
	ldrh r0, [r2]
	cmp r0, #0x3f
	bhi _08087A8C
	movs r7, #0x10
	b _08087A9C
	.align 2, 0
_08087A84: .4byte 0x030047A4
_08087A88: .4byte 0x00000396
_08087A8C:
	ldr r0, _08087B4C @ =0x0000032A
	adds r1, r6, r0
	movs r0, #2
	strh r0, [r1]
	ldrh r0, [r2]
	lsrs r0, r0, #2
	adds r7, r0, #0
	adds r7, #0x10
_08087A9C:
	ldr r1, _08087B50 @ =0x0203B400
	mov sb, r1
	ldr r5, _08087B54 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r2, _08087B58 @ =0x000003FF
	mov r8, r2
	ands r0, r2
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	adds r1, r7, #0
	bl Mod
	asrs r4, r7, #1
	subs r0, r0, r4
	ldr r2, _08087B5C @ =0x0000031E
	adds r1, r6, r2
	strh r0, [r1]
	ldr r0, [r5]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	adds r1, r7, #0
	bl Mod
	subs r0, r0, r4
	ldr r2, _08087B60 @ =0x00000322
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0xe7
	lsls r0, r0, #2
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _08087B64 @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _08087B1C
	ldr r0, [r5]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _08087B50 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08087B1C
	ldr r0, _08087B68 @ =0x000002B9
	bl PlaySound_082406e0
_08087B1C:
	ldr r0, _08087B6C @ =0x00000396
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bls _08087B96
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08087B70 @ =0x000001F5
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _08087B78
	ldr r0, _08087B74 @ =0x0000039E
	adds r1, r6, r0
	movs r0, #2
	b _08087B7E
	.align 2, 0
_08087B4C: .4byte 0x0000032A
_08087B50: .4byte 0x0203B400
_08087B54: .4byte 0x030046B8
_08087B58: .4byte 0x000003FF
_08087B5C: .4byte 0x0000031E
_08087B60: .4byte 0x00000322
_08087B64: .4byte 0x0000FFFF
_08087B68: .4byte 0x000002B9
_08087B6C: .4byte 0x00000396
_08087B70: .4byte 0x000001F5
_08087B74: .4byte 0x0000039E
_08087B78:
	ldr r2, _08087BA4 @ =0x0000039E
	adds r1, r6, r2
	movs r0, #1
_08087B7E:
	strh r0, [r1]
	adds r0, r6, #0
	movs r1, #2
	bl FUN_08085ee0
	ldr r1, _08087BA8 @ =0x0000039A
	adds r0, r6, r1
	ldrh r1, [r0]
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r1, [r0]
_08087B96:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08087BA4: .4byte 0x0000039E
_08087BA8: .4byte 0x0000039A

	thumb_func_start FUN_08087bac
FUN_08087bac: @ 0x08087BAC
	push {lr}
	adds r2, r0, #0
	ldr r0, _08087BF0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08087BFE
	ldr r1, _08087BF4 @ =0x000003A2
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08087BFE
	adds r1, #0x12
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08087BFE
	subs r1, #0x30
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08087BFE
	movs r0, #0xe9
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08087BF8
	subs r0, #1
	strh r0, [r1]
	b _08087BFE
	.align 2, 0
_08087BF0: .4byte 0x030047A4
_08087BF4: .4byte 0x000003A2
_08087BF8:
	adds r0, r2, #0
	bl FUN_080860cc
_08087BFE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08087c04
FUN_08087c04: @ 0x08087C04
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08087C58 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08087C1A
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08085ee0
_08087C1A:
	adds r2, r4, #0
	adds r2, #0xe2
	ldrh r1, [r2]
	ldr r0, _08087C5C @ =0x0000FFFB
	ands r0, r1
	movs r1, #0
	strh r0, [r2]
	ldr r2, _08087C60 @ =0x0000032A
	adds r0, r4, r2
	strh r1, [r0]
	adds r0, r4, #0
	bl FUN_08086024
	ldr r0, _08087C64 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08087CB6
	movs r5, #0xe5
	lsls r5, r5, #2
	adds r3, r4, r5
	ldrh r0, [r3]
	cmp r0, #0
	beq _08087C68
	adds r0, r4, #0
	bl FUN_08087a5c
	b _08087CB6
	.align 2, 0
_08087C58: .4byte 0x000001F5
_08087C5C: .4byte 0x0000FFFB
_08087C60: .4byte 0x0000032A
_08087C64: .4byte 0x030047A4
_08087C68:
	movs r1, #0xc9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r2, [r0]
	cmp r2, #0
	beq _08087C7C
	adds r0, r4, #0
	bl FUN_080856f4
	b _08087CB6
_08087C7C:
	ldr r5, _08087CA4 @ =0x0000040A
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08087CB0
	ldr r1, _08087CA8 @ =0x00000392
	adds r0, r4, r1
	ldrh r1, [r0]
	subs r5, #0x7a
	adds r0, r4, r5
	strh r1, [r0]
	ldr r1, _08087CAC @ =0x000003A6
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r5, #0x14
	adds r0, r4, r5
	strh r1, [r0]
	strh r2, [r3]
	b _08087CB6
	.align 2, 0
_08087CA4: .4byte 0x0000040A
_08087CA8: .4byte 0x00000392
_08087CAC: .4byte 0x000003A6
_08087CB0:
	adds r0, r4, #0
	bl FUN_08087bac
_08087CB6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08087cbc
FUN_08087cbc: @ 0x08087CBC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, _08087CF0 @ =0x03002BE0
	ldr r1, [r0]
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08087CEC
	cmp r1, #0
	blt _08087CEC
	ldr r0, _08087CF4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08087CEC
	ldr r0, _08087CF8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087CFC
_08087CEC:
	movs r4, #0
	b _08087D0A
	.align 2, 0
_08087CF0: .4byte 0x03002BE0
_08087CF4: .4byte 0x030046A8
_08087CF8: .4byte 0x030046AC
_08087CFC:
	ldr r0, _08087D1C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08087D0A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08087D20
	adds r0, #4
	b _08087D2C
	.align 2, 0
_08087D1C: .4byte 0x030046A4
_08087D20:
	ldr r0, _08087D6C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08087D2C:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	adds r6, r7, #0
	adds r6, #0x48
	cmp r0, #0
	beq _08087D3C
	b _08087E64
_08087D3C:
	ldr r0, _08087D70 @ =0x03002BE0
	ldr r0, [r0]
	adds r5, r0, #0
	adds r5, #0x2c
	ldrh r0, [r0, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08087D68
	cmp r1, #0
	blt _08087D68
	ldr r0, _08087D74 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08087D68
	ldr r0, _08087D78 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087D7C
_08087D68:
	movs r4, #0
	b _08087D8A
	.align 2, 0
_08087D6C: .4byte 0x030046A4
_08087D70: .4byte 0x03002BE0
_08087D74: .4byte 0x030046A8
_08087D78: .4byte 0x030046AC
_08087D7C:
	ldr r0, _08087D9C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08087D8A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08087DA0
	adds r0, #4
	b _08087DAC
	.align 2, 0
_08087D9C: .4byte 0x030046A4
_08087DA0:
	ldr r0, _08087DC0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08087DAC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08087DC4
	cmp r2, #2
	beq _08087DC8
	b _08087DCC
	.align 2, 0
_08087DC0: .4byte 0x030046A4
_08087DC4:
	ldrb r0, [r5, #4]
	b _08087DCA
_08087DC8:
	ldrb r0, [r5]
_08087DCA:
	subs r1, r1, r0
_08087DCC:
	mov r8, r1
	adds r5, r7, #0
	adds r5, #0x48
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r6, r5, #0
	cmp r2, #0
	blt _08087DF8
	cmp r1, #0
	blt _08087DF8
	ldr r0, _08087DFC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08087DF8
	ldr r0, _08087E00 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087E04
_08087DF8:
	movs r4, #0
	b _08087E12
	.align 2, 0
_08087DFC: .4byte 0x030046A8
_08087E00: .4byte 0x030046AC
_08087E04:
	ldr r0, _08087E24 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08087E12:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08087E28
	adds r0, #4
	b _08087E34
	.align 2, 0
_08087E24: .4byte 0x030046A4
_08087E28:
	ldr r0, _08087E48 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08087E34:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08087E4C
	cmp r2, #2
	beq _08087E50
	b _08087E54
	.align 2, 0
_08087E48: .4byte 0x030046A4
_08087E4C:
	ldrb r0, [r5, #4]
	b _08087E52
_08087E50:
	ldrb r0, [r5]
_08087E52:
	subs r1, r1, r0
_08087E54:
	mov r2, r8
	subs r0, r2, r1
	cmp r0, #0
	bge _08087E5E
	rsbs r0, r0, #0
_08087E5E:
	cmp r0, #0xff
	bgt _08087E64
	b _08087F72
_08087E64:
	ldr r2, _08087E90 @ =0x03002BE0
	ldr r1, [r2]
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r1, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _08087E8C
	cmp r1, #0
	blt _08087E8C
	ldr r0, _08087E94 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _08087E8C
	ldr r0, _08087E98 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087E9C
_08087E8C:
	movs r4, #0
	b _08087EAA
	.align 2, 0
_08087E90: .4byte 0x03002BE0
_08087E94: .4byte 0x030046A8
_08087E98: .4byte 0x030046AC
_08087E9C:
	ldr r0, _08087ED4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_08087EAA:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _08087ECE
	cmp r1, #0
	blt _08087ECE
	ldr r0, _08087ED8 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _08087ECE
	ldr r0, _08087EDC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087EE0
_08087ECE:
	movs r3, #0
	b _08087EEE
	.align 2, 0
_08087ED4: .4byte 0x030046A4
_08087ED8: .4byte 0x030046A8
_08087EDC: .4byte 0x030046AC
_08087EE0:
	ldr r0, _08087F04 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r3
_08087EEE:
	adds r0, r4, #1
	cmp r3, r0
	bne _08087F08
	ldr r1, [r2]
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r0, #2
	strh r0, [r1, #0x2c]
	b _08087F72
	.align 2, 0
_08087F04: .4byte 0x030046A4
_08087F08:
	subs r0, r4, #1
	cmp r3, r0
	bne _08087F20
	ldr r1, [r2]
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #2
	strh r0, [r1, #0x2c]
	b _08087F72
_08087F20:
	ldr r0, _08087F44 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r1, [r0, r5]
	adds r0, r4, r1
	cmp r3, r0
	bne _08087F48
	ldr r1, [r2]
	adds r0, r7, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r0, #2
	b _08087F70
	.align 2, 0
_08087F44: .4byte 0x030046A4
_08087F48:
	subs r0, r4, r1
	cmp r3, r0
	bne _08087F62
	ldr r1, [r2]
	adds r0, r7, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #2
	b _08087F70
_08087F62:
	ldr r1, [r2]
	ldrh r0, [r6]
	strh r0, [r1, #0x2c]
	ldr r1, [r2]
	adds r0, r7, #0
	adds r0, #0x4c
	ldrh r0, [r0]
_08087F70:
	strh r0, [r1, #0x30]
_08087F72:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08087f7c
FUN_08087f7c: @ 0x08087F7C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	ldr r3, _08087FBC @ =0x03002BE0
	ldr r0, [r3]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldr r2, _08087FC0 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r0, #0x46
	muls r0, r1, r0
	adds r5, r3, #0
	cmp r0, #0
	blt _08087FC4
	asrs r0, r0, #0xc
	b _08087FCA
	.align 2, 0
_08087FBC: .4byte 0x03002BE0
_08087FC0: .4byte 0x085B0A08
_08087FC4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08087FCA:
	mov sl, r0
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x46
	muls r0, r1, r0
	cmp r0, #0
	blt _08087FE4
	asrs r0, r0, #0xc
	b _08087FEA
_08087FE4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08087FEA:
	adds r7, r0, #0
	ldr r2, [r5]
	movs r3, #0x2c
	ldrsh r0, [r2, r3]
	add r0, sl
	adds r3, r6, #0
	adds r3, #0x48
	movs r4, #0
	ldrsh r1, [r3, r4]
	subs r5, r0, r1
	movs r1, #0x30
	ldrsh r0, [r2, r1]
	adds r0, r0, r7
	adds r2, r6, #0
	adds r2, #0x4c
	movs r4, #0
	ldrsh r1, [r2, r4]
	subs r4, r0, r1
	adds r1, r5, #0
	muls r1, r5, r1
	adds r0, r4, #0
	muls r0, r4, r0
	adds r1, r1, r0
	ldr r0, _08088048 @ =0x000057E4
	mov r8, r3
	mov sb, r2
	cmp r1, r0
	ble _080880EE
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	adds r4, r0, #0
	ldr r2, _0808804C @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _08088050
	asrs r0, r0, #0xc
	b _08088056
	.align 2, 0
_08088048: .4byte 0x000057E4
_0808804C: .4byte 0x085B0A08
_08088050:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08088056:
	adds r5, r0, #0
	ldr r1, _08088074 @ =0x085B0A08
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _08088078
	asrs r1, r0, #0xc
	b _0808807E
	.align 2, 0
_08088074: .4byte 0x085B0A08
_08088078:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808807E:
	mov r3, r8
	movs r4, #0
	ldrsh r2, [r3, r4]
	mov r0, sl
	subs r2, r2, r0
	adds r2, r2, r5
	mov r3, sb
	movs r4, #0
	ldrsh r0, [r3, r4]
	subs r0, r0, r7
	adds r4, r0, r1
	ldr r3, _080880AC @ =0x03002BE0
	ldr r0, [r3]
	movs r5, #0x2c
	ldrsh r1, [r0, r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, r0, r2
	adds r5, r3, #0
	cmp r0, #0
	blt _080880B0
	asrs r1, r0, #2
	b _080880B6
	.align 2, 0
_080880AC: .4byte 0x03002BE0
_080880B0:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_080880B6:
	ldr r0, [r5]
	strh r1, [r0, #0x2c]
	ldr r0, [r5]
	movs r2, #0x30
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, r0, r4
	cmp r0, #0
	blt _080880CE
	asrs r1, r0, #2
	b _080880D4
_080880CE:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_080880D4:
	ldr r0, [r5]
	strh r1, [r0, #0x30]
	adds r0, r6, #0
	bl FUN_08087cbc
	ldr r0, [r5]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r2, r0, r3
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
_080880EE:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080880fc
FUN_080880fc: @ 0x080880FC
	push {r4, lr}
	adds r2, r0, #0
	movs r1, #0xe1
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08088138
	movs r4, #0xe4
	lsls r4, r4, #2
	adds r1, r2, r4
	ldrh r0, [r1]
	adds r3, r0, #0
	cmp r3, #0
	beq _08088120
	subs r0, #1
	strh r0, [r1]
	b _08088138
_08088120:
	ldr r4, _08088140 @ =0x00000392
	adds r0, r2, r4
	ldrh r0, [r0]
	strh r0, [r1]
	movs r0, #0xe5
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #1
	strh r0, [r1]
	ldr r1, _08088144 @ =0x00000396
	adds r0, r2, r1
	strh r3, [r0]
_08088138:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08088140: .4byte 0x00000392
_08088144: .4byte 0x00000396

	thumb_func_start FUN_08088148
FUN_08088148: @ 0x08088148
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080881CC @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _0808815E
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08085ee0
_0808815E:
	movs r2, #0xed
	lsls r2, r2, #2
	adds r3, r4, r2
	ldrh r0, [r3]
	cmp r0, #0
	beq _080881AE
	ldr r5, _080881D0 @ =0x000003A2
	adds r0, r4, r5
	ldrh r0, [r0]
	cmp r0, #0
	beq _080881AE
	adds r0, r4, #0
	adds r0, #0x48
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r5, #6
	adds r0, r4, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r1, r2, r0
	cmp r1, #0
	bge _0808818C
	rsbs r1, r1, #0
_0808818C:
	movs r5, #0xeb
	lsls r5, r5, #2
	adds r0, r4, r5
	movs r5, #0
	ldrsh r0, [r0, r5]
	subs r0, r2, r0
	cmp r0, #0
	bge _0808819E
	rsbs r0, r0, #0
_0808819E:
	movs r2, #0x80
	lsls r2, r2, #1
	cmp r1, r2
	bgt _080881AA
	cmp r0, r2
	ble _080881AE
_080881AA:
	movs r0, #0
	strh r0, [r3]
_080881AE:
	ldr r0, _080881D4 @ =0x0000032A
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _080881D8
	adds r0, r4, #0
	bl FUN_08087f7c
	b _08088230
	.align 2, 0
_080881CC: .4byte 0x000001F5
_080881D0: .4byte 0x000003A2
_080881D4: .4byte 0x0000032A
_080881D8:
	adds r2, r4, #0
	adds r2, #0x48
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r5, #0xe2
	lsls r5, r5, #2
	adds r0, r4, r5
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _080881F2
	rsbs r1, r1, #0
_080881F2:
	adds r3, r4, #0
	adds r3, #0x4c
	cmp r1, #2
	bgt _08088214
	movs r5, #0
	ldrsh r0, [r3, r5]
	movs r5, #0xe3
	lsls r5, r5, #2
	adds r1, r4, r5
	movs r5, #0
	ldrsh r1, [r1, r5]
	subs r0, r0, r1
	cmp r0, #0
	bge _08088210
	rsbs r0, r0, #0
_08088210:
	cmp r0, #2
	ble _0808821C
_08088214:
	ldr r0, _08088258 @ =0x0000033A
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0808821C:
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r2]
	movs r2, #0xe3
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	strh r0, [r3]
_08088230:
	ldr r3, _0808825C @ =0x0000038E
	adds r0, r4, r3
	ldrh r1, [r0]
	movs r5, #0x80
	lsls r5, r5, #2
	adds r0, r4, r5
	strb r1, [r0]
	ldrb r0, [r4, #0x1a]
	cmp r0, #5
	bne _08088260
	ldr r1, _08088258 @ =0x0000033A
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08088260
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_08085ef8
	b _08088268
	.align 2, 0
_08088258: .4byte 0x0000033A
_0808825C: .4byte 0x0000038E
_08088260:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08086024
_08088268:
	ldr r0, _0808828C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080882DE
	movs r2, #0xe5
	lsls r2, r2, #2
	adds r3, r4, r2
	ldrh r0, [r3]
	cmp r0, #0
	beq _08088290
	adds r0, r4, #0
	bl FUN_08087a5c
	b _080882DE
	.align 2, 0
_0808828C: .4byte 0x030047A4
_08088290:
	movs r5, #0xc9
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrh r2, [r0]
	cmp r2, #0
	beq _080882A4
	adds r0, r4, #0
	bl FUN_080856f4
	b _080882DE
_080882A4:
	ldr r1, _080882CC @ =0x0000040A
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080882D8
	ldr r5, _080882D0 @ =0x00000392
	adds r0, r4, r5
	ldrh r1, [r0]
	subs r5, #2
	adds r0, r4, r5
	strh r1, [r0]
	ldr r1, _080882D4 @ =0x000003A6
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r5, #0x14
	adds r0, r4, r5
	strh r1, [r0]
	strh r2, [r3]
	b _080882DE
	.align 2, 0
_080882CC: .4byte 0x0000040A
_080882D0: .4byte 0x00000392
_080882D4: .4byte 0x000003A6
_080882D8:
	adds r0, r4, #0
	bl FUN_080880fc
_080882DE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080882e4
FUN_080882e4: @ 0x080882E4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08088310
	cmp r1, #0
	blt _08088310
	ldr r0, _08088314 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08088310
	ldr r0, _08088318 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0808831C
_08088310:
	movs r4, #0
	b _0808832A
	.align 2, 0
_08088314: .4byte 0x030046A8
_08088318: .4byte 0x030046AC
_0808831C:
	ldr r0, _0808833C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0808832A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08088340
	adds r0, #4
	b _0808834C
	.align 2, 0
_0808833C: .4byte 0x030046A4
_08088340:
	ldr r0, _08088374 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0808834C:
	ldrh r1, [r0, #2]
	ands r5, r1
	cmp r5, #0
	bne _08088426
	movs r0, #0x80
	ands r1, r0
	cmp r1, #0
	beq _08088386
	movs r1, #0x10
	ldr r0, _08088378 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _0808837C @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08088380
	movs r0, #1
	b _08088382
	.align 2, 0
_08088374: .4byte 0x030046A4
_08088378: .4byte 0x030046A0
_0808837C: .4byte 0x00000934
_08088380:
	movs r0, #0
_08088382:
	cmp r0, #0
	bne _08088426
_08088386:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080883AA
	cmp r1, #0
	blt _080883AA
	ldr r0, _080883B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080883AA
	ldr r0, _080883B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080883B8
_080883AA:
	movs r4, #0
	b _080883C6
	.align 2, 0
_080883B0: .4byte 0x030046A8
_080883B4: .4byte 0x030046AC
_080883B8:
	ldr r0, _080883D8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080883C6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080883DC
	adds r0, #4
	b _080883E8
	.align 2, 0
_080883D8: .4byte 0x030046A4
_080883DC:
	ldr r0, _080883FC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080883E8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08088400
	cmp r2, #2
	beq _08088404
	b _08088408
	.align 2, 0
_080883FC: .4byte 0x030046A4
_08088400:
	ldrb r0, [r6, #4]
	b _08088406
_08088404:
	ldrb r0, [r6]
_08088406:
	subs r1, r1, r0
_08088408:
	movs r2, #2
	ldrsh r0, [r7, r2]
	subs r0, r0, r1
	cmp r0, #0
	bge _08088414
	rsbs r0, r0, #0
_08088414:
	cmp r0, #0x32
	bgt _08088426
	adds r0, r6, #0
	bl sub_081D2230
	cmp r0, #0
	bne _08088426
	movs r0, #1
	b _08088428
_08088426:
	movs r0, #0
_08088428:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08088430
FUN_08088430: @ 0x08088430
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r1, #0
	adds r7, r2, #0
	ldrh r2, [r5]
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bne _0808846C
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r1, [r0, #4]
	ldrh r5, [r5, #4]
	adds r1, r1, r5
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08088468 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, sp
	b _080884DA
	.align 2, 0
_08088468: .4byte 0xFFFF0000
_0808846C:
	movs r1, #4
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bne _0808848C
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r1, r2, r0
	mov r0, sp
	strh r1, [r0]
	adds r0, r4, #0
	mov r1, sp
	b _080884DA
_0808848C:
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r1, r2, r0
	mov r0, sp
	strh r1, [r0]
	mov r6, sp
	adds r0, r4, #0
	mov r1, sp
	adds r2, r7, #0
	bl FUN_080882e4
	cmp r0, #0
	beq _080884E4
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp]
	str r1, [sp, #4]
	ldrh r0, [r5, #4]
	ldrh r1, [r6, #4]
	adds r0, r0, r1
	strh r0, [r6, #4]
	adds r0, r4, #0
	mov r1, sp
	adds r2, r7, #0
	bl FUN_080882e4
	cmp r0, #0
	beq _080884E4
	mov r1, sp
	ldrh r0, [r5]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	adds r0, r4, #0
_080884DA:
	adds r2, r7, #0
	bl FUN_080882e4
	cmp r0, #0
	bne _080884E8
_080884E4:
	movs r0, #0
	b _080884EA
_080884E8:
	movs r0, #1
_080884EA:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080884f4
FUN_080884f4: @ 0x080884F4
	push {lr}
	cmp r0, #0
	bge _080884FC
	rsbs r0, r0, #0
_080884FC:
	cmp r0, #0x20
	bgt _0808850E
	cmp r1, #0
	bge _08088506
	rsbs r1, r1, #0
_08088506:
	cmp r1, #0x20
	bgt _0808850E
	movs r0, #1
	b _08088510
_0808850E:
	movs r0, #0
_08088510:
	pop {r1}
	bx r1

	thumb_func_start FUN_08088514
FUN_08088514: @ 0x08088514
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r1, _08088568 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _08088534
	adds r0, r4, #0
	movs r1, #3
	bl FUN_08085ee0
_08088534:
	ldr r0, _0808856C @ =0x030047A4
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r1, r0
	cmp r1, #0
	beq _08088544
	b _08088708
_08088544:
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08088574
	ldr r3, _08088570 @ =0x0000032A
	adds r0, r4, r3
	strh r1, [r0]
	adds r2, #0x94
	adds r0, r4, r2
	strh r1, [r0]
	adds r0, r4, #0
	bl FUN_080856f4
	adds r7, r4, #0
	adds r7, #0x48
	b _080886FC
	.align 2, 0
_08088568: .4byte 0x000001F5
_0808856C: .4byte 0x030047A4
_08088570: .4byte 0x0000032A
_08088574:
	ldr r3, _080885E8 @ =0x0000032A
	adds r1, r4, r3
	movs r0, #1
	strh r0, [r1]
	movs r1, #0xee
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r7, r4, #0
	adds r7, #0x48
	cmp r0, #0x5a
	bhi _0808858E
	b _080886BE
_0808858E:
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r2, #0
	ldrsh r0, [r7, r2]
	subs r1, r1, r0
	mov sb, r1
	movs r3, #0xce
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r1, r4, #0
	adds r1, #0x4c
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r2, r2, r0
	mov r8, r2
	mov sl, r1
	mov r0, sb
	cmp r0, #0
	bne _080885C2
	cmp r2, #0
	beq _08088690
_080885C2:
	mov r0, sb
	mov r1, r8
	bl FUN_0823785c
	adds r5, r0, #0
	ldr r2, _080885EC @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	cmp r0, #0
	blt _080885F0
	asrs r0, r0, #0xc
	b _080885F6
	.align 2, 0
_080885E8: .4byte 0x0000032A
_080885EC: .4byte 0x085B0A08
_080885F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080885F6:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	ldr r1, _08088618 @ =0x085B0A08
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	cmp r0, #0
	blt _0808861C
	asrs r0, r0, #0xc
	b _08088622
	.align 2, 0
_08088618: .4byte 0x085B0A08
_0808861C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08088622:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08088664 @ =0xFFFF0000
	mov r6, sp
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	ldr r2, _08088668 @ =0x00000841
	adds r0, r7, #0
	mov r1, sp
	bl FUN_08088430
	adds r1, r0, #0
	cmp r1, #0
	beq _08088670
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r7]
	adds r0, r0, r1
	strh r0, [r7]
	ldrh r0, [r6, #4]
	mov r2, sl
	ldrh r2, [r2]
	adds r0, r0, r2
	mov r3, sl
	strh r0, [r3]
	ldr r0, _0808866C @ =0x0000033A
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _08088676
	.align 2, 0
_08088664: .4byte 0xFFFF0000
_08088668: .4byte 0x00000841
_0808866C: .4byte 0x0000033A
_08088670:
	ldr r2, _080886F0 @ =0x0000033A
	adds r0, r4, r2
	strb r1, [r0]
_08088676:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r4, r3
	strb r1, [r0]
_08088690:
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080886BE
	mov r0, sb
	mov r1, r8
	bl FUN_080884f4
	cmp r0, #0
	beq _080886BE
	movs r2, #0xec
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _080886BE
	movs r1, #0
	bl FUN_082318ac
_080886BE:
	movs r3, #0xee
	lsls r3, r3, #2
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bls _080886D6
	movs r0, #0
	strh r0, [r1]
_080886D6:
	ldrb r0, [r4, #0x1a]
	cmp r0, #5
	bne _080886F4
	ldr r1, _080886F0 @ =0x0000033A
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080886F4
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_08085ef8
	b _080886FC
	.align 2, 0
_080886F0: .4byte 0x0000033A
_080886F4:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08086024
_080886FC:
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	adds r1, r7, #0
	bl FUN_08236268
_08088708:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08088718
FUN_08088718: @ 0x08088718
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r1, _08088760 @ =0x000001F5
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #4
	beq _08088730
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08085ee0
_08088730:
	ldr r0, _08088764 @ =0x030047A4
	ldr r1, [r0]
	movs r6, #0x80
	lsls r6, r6, #2
	ands r1, r6
	cmp r1, #0
	beq _08088740
	b _08088902
_08088740:
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r7, [r0]
	cmp r7, #0
	beq _0808876C
	ldr r4, _08088768 @ =0x0000032A
	adds r0, r5, r4
	strh r1, [r0]
	adds r2, #0x94
	adds r0, r5, r2
	strh r1, [r0]
	adds r0, r5, #0
	bl FUN_080856f4
	b _08088902
	.align 2, 0
_08088760: .4byte 0x000001F5
_08088764: .4byte 0x030047A4
_08088768: .4byte 0x0000032A
_0808876C:
	ldr r4, _080887B8 @ =0x0000032A
	adds r0, r5, r4
	movs r1, #1
	strh r1, [r0]
	movs r1, #0xee
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x5a
	bne _08088800
	ldr r2, _080887BC @ =0x000003BA
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #0
	beq _080887C8
	ldr r2, _080887C0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	adds r1, #0x47
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080887C4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	adds r2, r5, r6
	ldrb r1, [r2]
	adds r1, r1, r0
	adds r1, #2
	movs r0, #7
	ands r1, r0
	strb r1, [r2]
	strh r7, [r4]
	b _080888BA
	.align 2, 0
_080887B8: .4byte 0x0000032A
_080887BC: .4byte 0x000003BA
_080887C0: .4byte 0x030046B8
_080887C4: .4byte 0x0203B400
_080887C8:
	ldr r2, _080887F4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080887F8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _080887FC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r2, r5, r6
	ldrb r1, [r2]
	adds r1, r1, r0
	adds r1, #7
	movs r0, #7
	ands r1, r0
	strb r1, [r2]
	b _080888BA
	.align 2, 0
_080887F4: .4byte 0x030046B8
_080887F8: .4byte 0x000003FF
_080887FC: .4byte 0x0203B400
_08088800:
	cmp r0, #0x5a
	bls _080888BA
	adds r0, r5, r6
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08088830 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	cmp r0, #0
	blt _08088834
	asrs r0, r0, #0xc
	b _0808883A
	.align 2, 0
_08088830: .4byte 0x085B0A08
_08088834:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808883A:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	cmp r0, #0
	blt _08088854
	asrs r0, r0, #0xc
	b _0808885A
_08088854:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808885A:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0808889C @ =0xFFFF0000
	mov r6, sp
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	adds r4, r5, #0
	adds r4, #0x48
	ldr r2, _080888A0 @ =0x00000843
	adds r0, r4, #0
	mov r1, sp
	bl FUN_08088430
	cmp r0, #0
	beq _080888A8
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	adds r1, r5, #0
	adds r1, #0x4c
	ldrh r0, [r6, #4]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r4, _080888A4 @ =0x0000033A
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	b _080888BA
	.align 2, 0
_0808889C: .4byte 0xFFFF0000
_080888A0: .4byte 0x00000843
_080888A4: .4byte 0x0000033A
_080888A8:
	movs r0, #0xee
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0x1e
	strh r0, [r1]
	ldr r2, _080888D4 @ =0x000003BA
	adds r1, r5, r2
	movs r0, #1
	strh r0, [r1]
_080888BA:
	ldrb r0, [r5, #0x1a]
	cmp r0, #5
	bne _080888DC
	ldr r4, _080888D8 @ =0x0000033A
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080888DC
	adds r0, r5, #0
	movs r1, #0x20
	bl FUN_08085ef8
	b _080888E4
	.align 2, 0
_080888D4: .4byte 0x000003BA
_080888D8: .4byte 0x0000033A
_080888DC:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08086024
_080888E4:
	movs r0, #0xee
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bls _08088902
	adds r0, r5, #0
	bl FUN_080860cc
	movs r0, #0
	strh r0, [r4]
_08088902:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808890c
FUN_0808890c: @ 0x0808890C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r1, _08088990 @ =0x000001F5
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _0808892A
	adds r0, r7, #0
	movs r1, #2
	bl FUN_08085ee0
_0808892A:
	ldr r0, _08088994 @ =0x030047A4
	ldr r5, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r5, r0
	cmp r5, #0
	beq _0808893A
	b _08088BAE
_0808893A:
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrh r0, [r0]
	lsls r1, r0, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x40
	bhi _0808894C
	b _08088ABC
_0808894C:
	ldr r1, _08088998 @ =0x0000032A
	adds r0, r7, r1
	movs r1, #2
	strh r1, [r0]
	adds r2, #8
	adds r1, r7, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _08088964
	bl FUN_080dab9c
_08088964:
	ldr r0, _0808899C @ =0x0000039E
	adds r3, r7, r0
	ldrh r0, [r3]
	cmp r0, #2
	bne _080889A0
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r7, r1
	subs r1, #0x48
	strh r1, [r0]
	movs r5, #0xa5
	lsls r5, r5, #1
	adds r2, r7, r5
	movs r0, #0x20
	strh r0, [r2]
	movs r2, #0xa6
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	movs r0, #1
	strh r0, [r3]
	b _080889C2
	.align 2, 0
_08088990: .4byte 0x000001F5
_08088994: .4byte 0x030047A4
_08088998: .4byte 0x0000032A
_0808899C: .4byte 0x0000039E
_080889A0:
	cmp r0, #1
	bne _080889C2
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0x80
	strh r1, [r0]
	movs r0, #0xa5
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r0, #0x20
	strh r0, [r2]
	movs r2, #0xa6
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	strh r5, [r3]
_080889C2:
	movs r5, #0x96
	lsls r5, r5, #1
	adds r4, r7, r5
	adds r1, r7, #0
	adds r1, #0x48
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	movs r0, #0xe6
	lsls r0, r0, #2
	adds r0, r0, r7
	mov r8, r0
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _08088A1E
	ldr r2, _08088A88 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08088A8C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08088A90 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r5, #0xd4
	adds r2, r7, r5
	ldrb r1, [r2]
	adds r1, r1, r0
	subs r1, #1
	movs r0, #7
	ands r1, r0
	strb r1, [r2]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_08086024
_08088A1E:
	ldr r6, _08088A90 @ =0x0203B400
	ldr r0, _08088A88 @ =0x030046B8
	mov ip, r0
	ldr r1, [r0]
	adds r1, #1
	ldr r3, _08088A8C @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r4, #0x3f
	ands r0, r4
	subs r0, #0x1f
	ldr r5, _08088A94 @ =0x0000031E
	adds r2, r7, r5
	strh r0, [r2]
	adds r1, #1
	ands r1, r3
	mov r0, ip
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #0x1f
	ldr r2, _08088A98 @ =0x00000322
	adds r1, r7, r2
	strh r0, [r1]
	mov r5, r8
	ldrh r1, [r5]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _08088A68
	adds r0, r7, #0
	bl FUN_08085880
_08088A68:
	ldr r1, _08088A9C @ =0x00000326
	adds r0, r7, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08088B5A
	lsrs r2, r0, #0x13
	mov r5, r8
	ldrh r1, [r5]
	adds r0, r2, #0
	adds r0, #0x40
	cmp r1, r0
	bge _08088AA0
	movs r0, #0x40
	strh r0, [r5]
	b _08088AA6
	.align 2, 0
_08088A88: .4byte 0x030046B8
_08088A8C: .4byte 0x000003FF
_08088A90: .4byte 0x0203B400
_08088A94: .4byte 0x0000031E
_08088A98: .4byte 0x00000322
_08088A9C: .4byte 0x00000326
_08088AA0:
	subs r0, r1, r2
	mov r1, r8
	strh r0, [r1]
_08088AA6:
	ldr r2, _08088AB8 @ =0x00000326
	adds r0, r7, r2
	movs r1, #0
	strh r1, [r0]
	movs r5, #0xc9
	lsls r5, r5, #2
	adds r0, r7, r5
	strh r1, [r0]
	b _08088B5A
	.align 2, 0
_08088AB8: .4byte 0x00000326
_08088ABC:
	lsrs r6, r1, #0x11
	cmp r6, #1
	bgt _08088AC4
	movs r6, #2
_08088AC4:
	ldr r0, _08088B84 @ =0x0203B400
	mov sl, r0
	ldr r1, _08088B88 @ =0x030046B8
	mov r8, r1
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _08088B8C @ =0x000003FF
	mov sb, r2
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	adds r1, r6, #0
	bl Mod
	asrs r4, r6, #1
	subs r0, r0, r4
	ldr r2, _08088B90 @ =0x0000031E
	adds r1, r7, r2
	strh r0, [r1]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	adds r1, r6, #0
	bl Mod
	subs r0, r0, r4
	ldr r2, _08088B94 @ =0x00000322
	adds r1, r7, r2
	strh r0, [r1]
	ldr r1, _08088B98 @ =0x0000032A
	adds r0, r7, r1
	strh r5, [r0]
	adds r2, #4
	adds r0, r7, r2
	strh r5, [r0]
	subs r1, #6
	adds r0, r7, r1
	strh r5, [r0]
	adds r2, #0x76
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r5, _08088B9C @ =0x0000FFFF
	adds r1, r5, #0
	ands r0, r1
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _08088B5A
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r5, _08088B84 @ =0x0203B400
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08088B5A
	ldr r0, _08088BA0 @ =0x000002B9
	bl PlaySound_082406e0
_08088B5A:
	movs r0, #0xe6
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08088BAE
	ldrb r0, [r7, #0x1b]
	cmp r0, #1
	bne _08088BA8
	adds r0, r7, #0
	movs r1, #0xf
	bl FUN_08085ee0
	ldr r2, _08088BA4 @ =0x00000402
	adds r1, r7, r2
	movs r0, #0x1e
	strh r0, [r1]
	b _08088BAE
	.align 2, 0
_08088B84: .4byte 0x0203B400
_08088B88: .4byte 0x030046B8
_08088B8C: .4byte 0x000003FF
_08088B90: .4byte 0x0000031E
_08088B94: .4byte 0x00000322
_08088B98: .4byte 0x0000032A
_08088B9C: .4byte 0x0000FFFF
_08088BA0: .4byte 0x000002B9
_08088BA4: .4byte 0x00000402
_08088BA8:
	adds r0, r7, #0
	bl FUN_080860cc
_08088BAE:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08088bbc
FUN_08088bbc: @ 0x08088BBC
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0xe2
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0xfb
	lsls r2, r2, #1
	adds r4, r5, r2
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08086024
	ldrh r0, [r4]
	cmp r0, #0x1b
	bls _08088C4C
	cmp r0, #0x2b
	bhi _08088C28
	adds r4, r0, #0
	adds r3, r4, #0
	subs r3, #0x1c
	adds r2, r5, #0
	adds r2, #0x84
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	lsls r1, r3, #2
	movs r0, #0x40
	subs r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x8c
	strb r0, [r1]
	cmp r3, #8
	ble _08088C4C
	lsls r0, r3, #3
	adds r2, #9
	strb r0, [r2]
	adds r1, r4, #0
	subs r1, #0x24
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	b _08088C36
_08088C28:
	cmp r0, #0x33
	bhi _08088C40
	ldrh r0, [r4]
	subs r0, #0x2c
	movs r1, #0xc8
	muls r0, r1, r0
	adds r0, #0xf0
_08088C36:
	movs r2, #0xc8
	lsls r2, r2, #2
	adds r1, r5, r2
	strh r0, [r1]
	b _08088C4C
_08088C40:
	adds r0, r5, #0
	adds r0, #0x84
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_08088C4C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08088c54
FUN_08088c54: @ 0x08088C54
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r6, #0
	strb r6, [r0]
	adds r1, r4, #0
	adds r1, #0xe2
	ldrh r0, [r1]
	movs r5, #4
	orrs r0, r5
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08086024
	movs r2, #0xfb
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0x4b
	bhi _08088C90
	adds r0, r4, #0
	adds r0, #0x84
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _08088D14
_08088C90:
	cmp r0, #0x53
	bhi _08088CCA
	ldrh r3, [r1]
	adds r2, r4, #0
	adds r2, #0x84
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	adds r0, r4, #0
	adds r0, #0x8c
	strb r5, [r0]
	adds r1, r4, #0
	adds r1, #0x8d
	movs r0, #0x78
	strb r0, [r1]
	movs r0, #0x54
	subs r0, r0, r3
	movs r1, #0xc8
	muls r0, r1, r0
	adds r0, #0xf0
	movs r2, #0xc8
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	b _08088D14
_08088CCA:
	cmp r0, #0x63
	bhi _08088D14
	ldrh r0, [r1]
	adds r3, r0, #0
	subs r3, #0x54
	movs r0, #0xf
	subs r2, r0, r3
	lsls r1, r2, #2
	movs r0, #0x40
	subs r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x8c
	strb r0, [r1]
	cmp r3, #7
	bgt _08088D04
	lsls r0, r2, #3
	adds r2, r4, #0
	adds r2, #0x8d
	strb r0, [r2]
	movs r0, #8
	subs r0, r0, r3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #1
	movs r2, #0xc8
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	b _08088D14
_08088D04:
	adds r1, r4, #0
	adds r1, #0x8d
	movs r0, #0x40
	strb r0, [r1]
	movs r1, #0xc8
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r6, [r0]
_08088D14:
	movs r2, #0xfb
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x67
	bls _08088D3E
	adds r0, r4, #0
	adds r0, #0x84
	ldr r1, [r0]
	movs r2, #3
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08085ee0
_08088D3E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08088d44
FUN_08088d44: @ 0x08088D44
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r1, _08088DBC @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _08088D5E
	adds r0, r4, #0
	movs r1, #5
	bl FUN_08085ee0
_08088D5E:
	ldr r0, _08088DC0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08088D6E
	b _08088FAE
_08088D6E:
	ldr r2, _08088DC4 @ =0x0000032A
	adds r1, r4, r2
	movs r2, #0
	movs r0, #2
	strh r0, [r1]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r4, r3
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0xe2
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
	movs r5, #0
	mov r8, r5
	movs r0, #0xfb
	lsls r0, r0, #1
	adds r3, r4, r0
	ldrh r2, [r3]
	lsls r0, r2, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x3f
	bhi _08088DCC
	adds r2, r4, #0
	adds r2, #0x4a
	movs r3, #0
	ldrsh r1, [r2, r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	ldr r3, _08088DC8 @ =0x000003CE
	adds r1, r4, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	asrs r0, r0, #3
	strh r0, [r2]
	b _08088E56
	.align 2, 0
_08088DBC: .4byte 0x000001F5
_08088DC0: .4byte 0x030047A4
_08088DC4: .4byte 0x0000032A
_08088DC8: .4byte 0x000003CE
_08088DCC:
	cmp r1, #0x7f
	bhi _08088E1C
	ldr r2, _08088E0C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08088E10 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08088E14 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #1
	ands r1, r0
	lsls r0, r1, #4
	adds r0, r0, r1
	subs r0, #8
	ldr r2, _08088E18 @ =0x0000031E
	adds r1, r4, r2
	strh r0, [r1]
	rsbs r0, r0, #0
	adds r2, #4
	adds r1, r4, r2
	strh r0, [r1]
	movs r5, #1
	ldrh r1, [r3]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08088E52
	mov r8, r5
	b _08088E52
	.align 2, 0
_08088E0C: .4byte 0x030046B8
_08088E10: .4byte 0x000003FF
_08088E14: .4byte 0x0203B400
_08088E18: .4byte 0x0000031E
_08088E1C:
	cmp r1, #0xbf
	bhi _08088E3A
	lsrs r0, r0, #0x11
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _08088E2C
	movs r5, #1
_08088E2C:
	movs r0, #0xf
	ands r0, r2
	cmp r0, #0
	bne _08088E52
	movs r3, #1
	mov r8, r3
	b _08088E52
_08088E3A:
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08088E46
	movs r5, #1
_08088E46:
	movs r0, #0xf
	ands r0, r2
	cmp r0, #0
	bne _08088E52
	movs r0, #1
	mov r8, r0
_08088E52:
	cmp r5, #0
	beq _08088F04
_08088E56:
	adds r3, r4, #0
	adds r3, #0x84
	ldr r0, [r3]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r3]
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r7, r4, r1
	ldrh r0, [r7]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r6, r3, #0
	cmp r2, #0
	blt _08088E9C
	cmp r1, #0
	blt _08088E9C
	ldr r0, _08088EA0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08088E9C
	ldr r0, _08088EA4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08088EA8
_08088E9C:
	movs r5, #0
	b _08088EB6
	.align 2, 0
_08088EA0: .4byte 0x030046A8
_08088EA4: .4byte 0x030046AC
_08088EA8:
	ldr r0, _08088EC8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08088EB6:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08088ECC
	adds r0, #4
	b _08088ED8
	.align 2, 0
_08088EC8: .4byte 0x030046A4
_08088ECC:
	ldr r0, _08088EEC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08088ED8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08088EF0
	cmp r2, #2
	beq _08088EF4
	b _08088EF8
	.align 2, 0
_08088EEC: .4byte 0x030046A4
_08088EF0:
	ldrb r0, [r7, #4]
	b _08088EF6
_08088EF4:
	ldrb r0, [r7]
_08088EF6:
	subs r1, r1, r0
_08088EF8:
	ldr r2, _08088F00 @ =0x0000035A
	adds r0, r4, r2
	strh r1, [r0]
	b _08088F1E
	.align 2, 0
_08088F00: .4byte 0x0000035A
_08088F04:
	adds r2, r4, #0
	adds r2, #0x84
	ldr r0, [r2]
	movs r3, #1
	orrs r0, r3
	str r0, [r2]
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r6, r2, #0
_08088F1E:
	mov r1, r8
	cmp r1, #0
	beq _08088F32
	adds r0, r4, #0
	adds r0, #0x48
	movs r2, #0xf5
	lsls r2, r2, #2
	adds r1, r4, r2
	bl FUN_08085a74
_08088F32:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08086024
	movs r3, #0xfb
	lsls r3, r3, #1
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xff
	bls _08088FAE
	adds r0, r4, #0
	bl FUN_080856cc
	ldr r0, _08088F8C @ =0x03002C00
	ldr r0, [r0]
	movs r1, #0
	bl FUN_08085ee0
	movs r0, #0xec
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r2, [r1]
	cmp r2, #0
	beq _08088FA0
	movs r0, #0
	str r0, [r1]
	adds r0, r2, #0
	movs r1, #0
	bl FUN_082318ac
	ldr r1, _08088F90 @ =0x0000040B
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08088F94
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	b _08088FAE
	.align 2, 0
_08088F8C: .4byte 0x03002C00
_08088F90: .4byte 0x0000040B
_08088F94:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	b _08088FAE
_08088FA0:
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	ldr r2, _08088FB8 @ =0x0000040B
	adds r0, r4, r2
	strb r1, [r0]
_08088FAE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08088FB8: .4byte 0x0000040B

	thumb_func_start FUN_08088fbc
FUN_08088fbc: @ 0x08088FBC
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r1, _08089030 @ =0x000001F5
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #6
	beq _08088FD4
	adds r0, r5, #0
	movs r1, #6
	bl FUN_08085ee0
_08088FD4:
	ldr r0, _08089034 @ =0x030047A4
	ldr r3, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r3, r0
	cmp r3, #0
	bne _08089076
	ldr r1, _08089038 @ =0x0000032A
	adds r0, r5, r1
	strh r3, [r0]
	movs r0, #0xfb
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrh r0, [r6]
	adds r1, r0, #1
	strh r1, [r6]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _08089040
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _08089076
	movs r1, #0x83
	lsls r1, r1, #3
	adds r2, r5, r1
	strh r3, [r2]
	ldr r0, _0808903C @ =0x00000414
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x40
	str r2, [sp]
	movs r2, #0xc8
	str r2, [sp, #4]
	movs r2, #0xfa
	str r2, [sp, #8]
	adds r2, #0x28
	str r2, [sp, #0xc]
	movs r2, #1
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r4]
	b _08089076
	.align 2, 0
_08089030: .4byte 0x000001F5
_08089034: .4byte 0x030047A4
_08089038: .4byte 0x0000032A
_0808903C: .4byte 0x00000414
_08089040:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bne _0808905C
	ldr r1, _08089080 @ =0x00000414
	adds r4, r5, r1
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x40
	ldrh r2, [r1]
	movs r1, #1
	bl FUN_080d99d4
	str r0, [r4]
_0808905C:
	movs r1, #0xc8
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	subs r1, #0x1e
	strh r1, [r0]
	ldrh r0, [r6]
	cmp r0, #8
	bls _08089076
	ldr r0, _08089084 @ =0x0000040B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_08089076:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08089080: .4byte 0x00000414
_08089084: .4byte 0x0000040B

	thumb_func_start FUN_08089088
FUN_08089088: @ 0x08089088
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r1, _080890F0 @ =0x000001F5
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #7
	beq _080890A0
	adds r0, r5, #0
	movs r1, #7
	bl FUN_08085ee0
_080890A0:
	ldr r1, _080890F4 @ =0x0000032A
	adds r0, r5, r1
	movs r3, #0
	strh r3, [r0]
	movs r0, #0xfb
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrh r0, [r6]
	adds r1, r0, #1
	strh r1, [r6]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _080890FC
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _08089132
	movs r1, #0x83
	lsls r1, r1, #3
	adds r2, r5, r1
	strh r3, [r2]
	ldr r0, _080890F8 @ =0x00000414
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x40
	str r2, [sp]
	movs r2, #0xc8
	str r2, [sp, #4]
	movs r2, #0xfa
	str r2, [sp, #8]
	adds r2, #0x28
	str r2, [sp, #0xc]
	movs r2, #1
	bl FUN_080da9c4
	str r0, [r4]
	b _08089132
	.align 2, 0
_080890F0: .4byte 0x000001F5
_080890F4: .4byte 0x0000032A
_080890F8: .4byte 0x00000414
_080890FC:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bne _08089118
	ldr r1, _0808913C @ =0x00000414
	adds r4, r5, r1
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x40
	ldrh r2, [r1]
	movs r1, #1
	bl FUN_080d99d4
	str r0, [r4]
_08089118:
	movs r1, #0xc8
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	subs r1, #0x3c
	strh r1, [r0]
	ldrh r0, [r6]
	cmp r0, #0x1d
	bls _08089132
	ldr r0, _08089140 @ =0x0000040B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_08089132:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808913C: .4byte 0x00000414
_08089140: .4byte 0x0000040B

	thumb_func_start FUN_08089144
FUN_08089144: @ 0x08089144
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r1, _0808919C @ =0x000001F5
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #8
	beq _08089160
	adds r0, r7, #0
	movs r1, #8
	bl FUN_08085ee0
_08089160:
	ldr r2, _080891A0 @ =0x0000032A
	adds r0, r7, r2
	movs r6, #0
	strh r6, [r0]
	movs r0, #0xfb
	lsls r0, r0, #1
	adds r5, r7, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _080891AE
	ldr r1, _080891A4 @ =0x0000031E
	adds r0, r7, r1
	strh r6, [r0]
	subs r2, #8
	adds r0, r7, r2
	strh r6, [r0]
	movs r0, #0xc8
	lsls r0, r0, #2
	adds r4, r7, r0
	ldrh r0, [r4]
	cmp r0, #0x1e
	bhi _080891A8
	adds r0, r7, #0
	bl FUN_080856cc
	strh r6, [r4]
	movs r0, #1
	strh r0, [r5]
	b _0808927A
	.align 2, 0
_0808919C: .4byte 0x000001F5
_080891A0: .4byte 0x0000032A
_080891A4: .4byte 0x0000031E
_080891A8:
	subs r0, #0x1e
	strh r0, [r4]
	b _0808927A
_080891AE:
	adds r1, r0, #1
	strh r1, [r5]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080891DE
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi _080891CE
	lsls r1, r1, #4
	movs r2, #0xc8
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	b _080891E6
_080891CE:
	movs r0, #7
	subs r0, r0, r1
	lsls r0, r0, #4
	movs r6, #0xc8
	lsls r6, r6, #2
	adds r1, r7, r6
	strh r0, [r1]
	b _080891E6
_080891DE:
	movs r1, #0xc8
	lsls r1, r1, #2
	adds r0, r7, r1
	strh r6, [r0]
_080891E6:
	movs r2, #0xfb
	lsls r2, r2, #1
	adds r2, r2, r7
	mov r8, r2
	ldrh r0, [r2]
	cmp r0, #0xb
	bhi _0808922A
	ldr r6, _08089288 @ =0x0203B400
	mov ip, r6
	ldr r5, _0808928C @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r3, _08089290 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	add r0, ip
	ldrh r0, [r0]
	movs r4, #0x1f
	ands r0, r4
	subs r0, #0x10
	ldr r6, _08089294 @ =0x0000031E
	adds r2, r7, r6
	strh r0, [r2]
	adds r1, #1
	ands r1, r3
	str r1, [r5]
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #0x10
	ldr r2, _08089298 @ =0x00000322
	adds r1, r7, r2
	strh r0, [r1]
_0808922A:
	mov r6, r8
	ldrh r0, [r6]
	cmp r0, #2
	bne _08089238
	adds r0, r7, #0
	bl FUN_0808596c
_08089238:
	mov r1, r8
	ldrh r0, [r1]
	cmp r0, #0x1d
	bls _0808927A
	adds r0, r7, #0
	movs r1, #0
	bl FUN_08085ee0
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #1
	strh r0, [r1]
	ldr r6, _0808929C @ =0x00000326
	adds r2, r7, r6
	ldr r3, _080892A0 @ =0x0000011F
	strh r3, [r2]
	ldr r0, _080892A4 @ =0x00000414
	adds r4, r7, r0
	ldr r0, [r4]
	adds r1, r7, #0
	adds r1, #0x40
	str r2, [sp]
	str r3, [sp, #4]
	movs r2, #0xfa
	str r2, [sp, #8]
	adds r2, #0x28
	str r2, [sp, #0xc]
	movs r2, #1
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r4]
_0808927A:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08089288: .4byte 0x0203B400
_0808928C: .4byte 0x030046B8
_08089290: .4byte 0x000003FF
_08089294: .4byte 0x0000031E
_08089298: .4byte 0x00000322
_0808929C: .4byte 0x00000326
_080892A0: .4byte 0x0000011F
_080892A4: .4byte 0x00000414

	thumb_func_start FUN_080892a8
FUN_080892a8: @ 0x080892A8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080892F0 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0xb
	beq _080892BE
	adds r0, r4, #0
	movs r1, #0xb
	bl FUN_08085ee0
_080892BE:
	ldr r3, _080892F4 @ =0x0000032A
	adds r0, r4, r3
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	adds r3, #0x6a
	adds r0, r4, r3
	strh r1, [r0]
	adds r3, r4, #0
	adds r3, #0xe2
	ldrh r0, [r3]
	movs r1, #4
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08086024
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080892F0: .4byte 0x000001F5
_080892F4: .4byte 0x0000032A

	thumb_func_start FUN_080892f8
FUN_080892f8: @ 0x080892F8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08089340 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0xd
	beq _0808930E
	adds r0, r4, #0
	movs r1, #0xd
	bl FUN_08085ee0
_0808930E:
	adds r3, r4, #0
	adds r3, #0xe2
	ldrh r1, [r3]
	movs r0, #4
	movs r2, #0
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	movs r1, #8
	bl FUN_08086024
	cmp r0, #0
	beq _08089338
	adds r0, r4, #0
	movs r1, #0xc
	bl FUN_08085ee0
_08089338:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08089340: .4byte 0x000001F5

	thumb_func_start FUN_08089344
FUN_08089344: @ 0x08089344
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08089368 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0xc
	beq _0808935A
	adds r0, r4, #0
	movs r1, #0xc
	bl FUN_08085ee0
_0808935A:
	ldrb r0, [r4, #0x1a]
	cmp r0, #6
	bne _08089370
	ldr r0, _0808936C @ =0x0000032A
	adds r1, r4, r0
	movs r0, #1
	b _08089396
	.align 2, 0
_08089368: .4byte 0x000001F5
_0808936C: .4byte 0x0000032A
_08089370:
	cmp r0, #7
	bne _08089390
	ldr r0, _08089388 @ =0x00000406
	adds r1, r4, r0
	movs r2, #0
	movs r0, #1
	strh r0, [r1]
	ldr r1, _0808938C @ =0x0000032A
	adds r0, r4, r1
	strh r2, [r0]
	b _08089398
	.align 2, 0
_08089388: .4byte 0x00000406
_0808938C: .4byte 0x0000032A
_08089390:
	ldr r0, _080893BC @ =0x0000032A
	adds r1, r4, r0
	movs r0, #0
_08089396:
	strh r0, [r1]
_08089398:
	adds r3, r4, #0
	adds r3, #0xe2
	ldrh r1, [r3]
	movs r0, #4
	movs r2, #0
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	movs r1, #0x18
	bl FUN_08086024
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080893BC: .4byte 0x0000032A

	thumb_func_start FUN_080893c0
FUN_080893c0: @ 0x080893C0
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808940C @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0xe
	beq _080893D6
	adds r0, r4, #0
	movs r1, #0xe
	bl FUN_08085ee0
_080893D6:
	adds r3, r4, #0
	adds r3, #0xe2
	ldrh r1, [r3]
	movs r0, #4
	movs r2, #0
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_08086024
	cmp r0, #0
	beq _08089406
	movs r1, #0x81
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_08085ee0
_08089406:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808940C: .4byte 0x000001F5

	thumb_func_start FUN_08089410
FUN_08089410: @ 0x08089410
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _0808947C @ =0x00000402
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0x1e
	bne _08089488
	adds r0, r4, #0
	adds r0, #0x48
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xef
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r2, r1, r0
	adds r0, r4, #0
	adds r0, #0x4c
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #0xf0
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	cmp r2, #0
	bne _0808944E
	cmp r1, #0
	beq _08089470
_0808944E:
	adds r0, r2, #0
	bl FUN_0823785c
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	ldr r2, _08089480 @ =0x00000404
	adds r1, r4, r2
	strh r0, [r1]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r4, r3
	strb r0, [r1]
_08089470:
	ldr r0, _08089484 @ =0x0000033A
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _08089502
	.align 2, 0
_0808947C: .4byte 0x00000402
_08089480: .4byte 0x00000404
_08089484: .4byte 0x0000033A
_08089488:
	cmp r0, #0x1d
	bhi _08089502
	ldr r1, _080894B8 @ =0x00000404
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r2, _080894BC @ =0x085B0A08
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
	cmp r0, #0
	blt _080894C0
	asrs r3, r0, #0xc
	b _080894C6
	.align 2, 0
_080894B8: .4byte 0x00000404
_080894BC: .4byte 0x085B0A08
_080894C0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080894C6:
	adds r1, r4, #0
	adds r1, #0x48
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	cmp r0, #0
	blt _080894E4
	asrs r2, r0, #0xc
	b _080894EA
_080894E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080894EA:
	adds r1, r4, #0
	adds r1, #0x4c
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r3, _08089534 @ =0x00000404
	adds r0, r4, r3
	ldrh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_08089502:
	ldr r0, _08089538 @ =0x00000402
	adds r3, r4, r0
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0808952E
	ldr r2, _0808953C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08089540 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08089544 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x2d
	strh r0, [r3]
_0808952E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08089534: .4byte 0x00000404
_08089538: .4byte 0x00000402
_0808953C: .4byte 0x030046B8
_08089540: .4byte 0x000003FF
_08089544: .4byte 0x0203B400

	thumb_func_start FUN_08089548
FUN_08089548: @ 0x08089548
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _0808959C @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0xf
	beq _0808955E
	adds r0, r4, #0
	movs r1, #0xf
	bl FUN_08085ee0
_0808955E:
	adds r2, r4, #0
	adds r2, #0xe2
	ldrh r1, [r2]
	ldr r0, _080895A0 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	ldr r2, _080895A4 @ =0x0000032A
	adds r5, r4, r2
	movs r0, #1
	strh r0, [r5]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08086024
	ldr r0, _080895A8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080895C8
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0
	beq _080895AC
	adds r0, r4, #0
	bl FUN_08087a5c
	b _080895C8
	.align 2, 0
_0808959C: .4byte 0x000001F5
_080895A0: .4byte 0x0000FFFB
_080895A4: .4byte 0x0000032A
_080895A8: .4byte 0x030047A4
_080895AC:
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080895C2
	strh r1, [r5]
	adds r0, r4, #0
	bl FUN_080856f4
	b _080895C8
_080895C2:
	adds r0, r4, #0
	bl FUN_08089410
_080895C8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080895d0
FUN_080895d0: @ 0x080895D0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08089638 @ =0x00000402
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0x1e
	bne _08089640
	adds r0, r4, #0
	adds r0, #0x48
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xef
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r2, r1, r0
	adds r0, r4, #0
	adds r0, #0x4c
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #0xf0
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	cmp r2, #0
	bne _0808960E
	cmp r1, #0
	beq _080896D4
_0808960E:
	adds r0, r2, #0
	bl FUN_0823785c
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	ldr r2, _0808963C @ =0x00000404
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, #4
	movs r1, #7
	ands r0, r1
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r4, r3
	b _080896D2
	.align 2, 0
_08089638: .4byte 0x00000402
_0808963C: .4byte 0x00000404
_08089640:
	cmp r0, #0x1d
	bhi _080896D4
	ldr r1, _08089674 @ =0x00000404
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r2, _08089678 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _0808967C
	asrs r3, r0, #0xc
	b _08089682
	.align 2, 0
_08089674: .4byte 0x00000404
_08089678: .4byte 0x085B0A08
_0808967C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08089682:
	adds r1, r4, #0
	adds r1, #0x48
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080896A2
	asrs r2, r0, #0xc
	b _080896A8
_080896A2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080896A8:
	adds r1, r4, #0
	adds r1, #0x4c
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r3, _08089708 @ =0x00000404
	adds r0, r4, r3
	ldrb r0, [r0]
	adds r0, #4
	movs r1, #7
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_08087f7c
	ldr r3, _0808970C @ =0x0000033A
	adds r1, r4, r3
	movs r0, #1
_080896D2:
	strb r0, [r1]
_080896D4:
	ldr r0, _08089710 @ =0x00000402
	adds r3, r4, r0
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08089700
	ldr r2, _08089714 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08089718 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0808971C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x2d
	strh r0, [r3]
_08089700:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08089708: .4byte 0x00000404
_0808970C: .4byte 0x0000033A
_08089710: .4byte 0x00000402
_08089714: .4byte 0x030046B8
_08089718: .4byte 0x000003FF
_0808971C: .4byte 0x0203B400

	thumb_func_start FUN_08089720
FUN_08089720: @ 0x08089720
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080897B4 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x10
	beq _08089736
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_08085ee0
_08089736:
	ldr r2, _080897B8 @ =0x0000032A
	adds r1, r4, r2
	movs r0, #1
	strh r0, [r1]
	movs r3, #0xe2
	lsls r3, r3, #2
	adds r2, r4, r3
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x48]
	str r1, [r4, #0x4c]
	adds r0, r4, #0
	adds r0, #0x48
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #0
	ldrsh r0, [r2, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _08089760
	rsbs r1, r1, #0
_08089760:
	cmp r1, #2
	bgt _08089782
	adds r0, r4, #0
	adds r0, #0x4c
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xe3
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _0808977E
	rsbs r1, r1, #0
_0808977E:
	cmp r1, #2
	ble _0808978A
_08089782:
	ldr r3, _080897BC @ =0x0000033A
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
_0808978A:
	ldr r1, _080897C0 @ =0x0000038E
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	ldrb r0, [r4, #0x1a]
	cmp r0, #5
	bne _080897C4
	ldr r3, _080897BC @ =0x0000033A
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _080897C4
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_08085ef8
	b _080897CC
	.align 2, 0
_080897B4: .4byte 0x000001F5
_080897B8: .4byte 0x0000032A
_080897BC: .4byte 0x0000033A
_080897C0: .4byte 0x0000038E
_080897C4:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08086024
_080897CC:
	ldr r0, _080897F0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08089820
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0
	beq _080897F4
	adds r0, r4, #0
	bl FUN_08087a5c
	b _08089820
	.align 2, 0
_080897F0: .4byte 0x030047A4
_080897F4:
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08089814
	ldr r3, _08089810 @ =0x0000032A
	adds r0, r4, r3
	strh r1, [r0]
	adds r0, r4, #0
	bl FUN_080856f4
	b _08089820
	.align 2, 0
_08089810: .4byte 0x0000032A
_08089814:
	adds r0, r4, #0
	bl FUN_080895d0
	adds r0, r4, #0
	bl FUN_080880fc
_08089820:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08089828:
	.byte 0x30, 0xB5, 0x04, 0x1C, 0x06, 0x48, 0x21, 0x18
	.byte 0x00, 0x20, 0x08, 0x80, 0x04, 0x21, 0x05, 0x48, 0x00, 0x68, 0x08, 0x40, 0x00, 0x28, 0x07, 0xD0
	.byte 0x20, 0x1C, 0xFB, 0xF7, 0xE1, 0xFD, 0x3D, 0xE0, 0x06, 0x04, 0x00, 0x00, 0xC0, 0x2B, 0x00, 0x03
	.byte 0x04, 0x49, 0x65, 0x18, 0x29, 0x78, 0x00, 0x29, 0x06, 0xD0, 0x20, 0x1C, 0xA7, 0xF1, 0x06, 0xFA
	.byte 0x30, 0xE0, 0x00, 0x00, 0x0B, 0x04, 0x00, 0x00, 0x18, 0x4A, 0xA0, 0x18, 0x01, 0x80, 0x04, 0x32
	.byte 0xA0, 0x18, 0x01, 0x80, 0x16, 0x48, 0x21, 0x18, 0x00, 0x20, 0x08, 0x70, 0x20, 0x1C, 0xFE, 0xF7
	.byte 0x77, 0xF8, 0x14, 0x49, 0x80, 0x00, 0x40, 0x18, 0x01, 0x68, 0x20, 0x1C, 0xC3, 0xF1, 0xEA, 0xFA
	.byte 0x20, 0x1C, 0xFD, 0xF7, 0xEB, 0xFE, 0x20, 0x1C, 0xFD, 0xF7, 0x18, 0xFE, 0x20, 0x1C, 0xFC, 0xF7
	.byte 0x11, 0xFB, 0xD2, 0x22, 0x52, 0x00, 0xA1, 0x18, 0x20, 0x1C, 0x48, 0x30, 0x08, 0x60, 0xD0, 0x21
	.byte 0x49, 0x00, 0x60, 0x18, 0xAA, 0xF1, 0xD4, 0xFE, 0x28, 0x78, 0x00, 0x28, 0x02, 0xD0, 0x20, 0x1C
	.byte 0xA7, 0xF1, 0xD4, 0xF9, 0x00, 0x20, 0x30, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x1E, 0x03, 0x00, 0x00
	.byte 0x3A, 0x03, 0x00, 0x00, 0x00, 0xC0, 0x5A, 0x08

	thumb_func_start FUN_080898d8
FUN_080898d8: @ 0x080898D8
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xfa
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080898F0
	subs r1, #0x10
	adds r0, r4, r1
	bl FUN_080f8cac
_080898F0:
	adds r0, r4, #0
	adds r0, #0x40
	bl FUN_0823b284
	adds r0, r4, #0
	adds r0, #0x84
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0xdc
	bl FUN_08236424
	adds r0, r4, #0
	bl FUN_0808565c
	adds r0, r4, #0
	bl FUN_080856cc
	ldr r1, _08089920 @ =0x03002C00
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08089920: .4byte 0x03002C00

	thumb_func_start FUN_08089924
FUN_08089924: @ 0x08089924
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08086df8
	adds r0, r4, #0
	bl FUN_08086f90
	adds r0, r4, #0
	bl FUN_08087058
	adds r0, r4, #0
	bl FUN_08086e64
	adds r0, r4, #0
	bl FUN_080871e4
	adds r0, r4, #0
	bl FUN_08087290
	adds r0, r4, #0
	bl FUN_080853c0
	adds r0, r4, #0
	bl FUN_08087310
	ldr r1, _08089990 @ =0x0000032A
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	movs r3, #0xcb
	lsls r3, r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	adds r3, #6
	adds r0, r4, r3
	strh r1, [r0]
	movs r0, #0xe8
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, _08089994 @ =0x0000FFFF
	strh r0, [r1]
	ldr r1, _08089998 @ =0x0000040B
	adds r0, r4, r1
	strb r2, [r0]
	adds r3, #0xd8
	adds r0, r4, r3
	strb r2, [r0]
	ldr r0, _0808999C @ =0x03002C00
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08089990: .4byte 0x0000032A
_08089994: .4byte 0x0000FFFF
_08089998: .4byte 0x0000040B
_0808999C: .4byte 0x03002C00

	thumb_func_start FUN_080899a0
FUN_080899a0: @ 0x080899A0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _080899DC @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	bne _080899EE
	ldr r1, _080899E0 @ =0x0000041C
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080899EC
	ldr r1, _080899E4 @ =0x08089829
	ldr r2, _080899E8 @ =FUN_080898d8
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_08089924
	cmp r0, #0
	bge _080899EC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080899EE
	.align 2, 0
_080899DC: .4byte 0x03002C00
_080899E0: .4byte 0x0000041C
_080899E4: .4byte 0x08089829
_080899E8: .4byte FUN_080898d8
_080899EC:
	adds r0, r4, #0
_080899EE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080899f4
FUN_080899f4: @ 0x080899F4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _08089A50 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _08089A98
	ldr r0, [r0, #0x1c]
	cmp r0, #1
	bne _08089A98
	movs r7, #0
	ldr r6, _08089A54 @ =0x030046A0
	ldr r0, [r6]
	movs r4, #0xae
	lsls r4, r4, #2
	adds r1, r0, r4
	ldr r0, [r1]
	cmp r0, #0
	ble _08089A58
	ldrh r0, [r5, #0x18]
	adds r0, #1
	strh r0, [r5, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r2, [r5, #0x1a]
	cmp r0, r2
	blo _08089A5A
	strh r7, [r5, #0x18]
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	ldr r1, [r6]
	adds r0, r1, r4
	ldr r0, [r0]
	movs r2, #0xaf
	lsls r2, r2, #2
	adds r1, r1, r2
	ldr r1, [r1]
	movs r2, #1
	bl FUN_0809c3c0
	ldr r0, [r6]
	adds r0, r0, r4
	ldr r0, [r0]
	cmp r0, #0
	bgt _08089A5A
	b _08089A5E
	.align 2, 0
_08089A50: .4byte 0x03002BE0
_08089A54: .4byte 0x030046A0
_08089A58:
	movs r7, #1
_08089A5A:
	cmp r7, #0
	beq _08089A98
_08089A5E:
	ldr r4, _08089AA0 @ =0x03002BE0
	ldr r1, [r4]
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0x15
	beq _08089A98
	adds r0, r1, #0
	bl FUN_0807e854
	ldr r0, [r4]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	movs r1, #0x1f
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _08089AA4 @ =0x0000037D
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	adds r1, #1
	adds r0, r0, r1
	strh r2, [r0]
	adds r0, r5, #0
	bl KillEntity
_08089A98:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08089AA0: .4byte 0x03002BE0
_08089AA4: .4byte 0x0000037D

	thumb_func_start FUN_08089aa8
FUN_08089aa8: @ 0x08089AA8
	movs r0, #0
	bx lr

	thumb_func_start FUN_08089aac
FUN_08089aac: @ 0x08089AAC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08089AD4 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0xae
	lsls r2, r2, #2
	adds r1, r0, r2
	ldr r0, [r1]
	cmp r0, #0
	bgt _08089AC4
	movs r0, #1
	str r0, [r1]
_08089AC4:
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _08089AD8
	bl fetch_082316e4
	b _08089ADA
	.align 2, 0
_08089AD4: .4byte 0x030046A0
_08089AD8:
	movs r0, #0x1e
_08089ADA:
	strh r0, [r4, #0x1a]
	movs r0, #0
	strh r0, [r4, #0x18]
	ldr r0, _08089B00 @ =0x030046A0
	ldr r1, [r0]
	movs r2, #0xae
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r0, [r0]
	adds r2, #4
	adds r1, r1, r2
	ldr r1, [r1]
	movs r2, #0
	bl FUN_0809c3c0
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08089B00: .4byte 0x030046A0

	thumb_func_start FUN_08089b04
FUN_08089b04: @ 0x08089B04
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #8
	movs r1, #0x1c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08089B40
	ldr r1, _08089B38 @ =FUN_080899f4
	ldr r2, _08089B3C @ =FUN_08089aa8
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_08089aac
	cmp r0, #0
	bge _08089B40
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08089B42
	.align 2, 0
_08089B38: .4byte FUN_080899f4
_08089B3C: .4byte FUN_08089aa8
_08089B40:
	adds r0, r4, #0
_08089B42:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08089b48
FUN_08089b48: @ 0x08089B48
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	adds r7, r3, #0
	ldr r0, _08089B80 @ =0x03003584
	ldr r3, _08089B84 @ =0x00000207
	adds r1, r1, r3
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r1, r1, r0
	mov r8, r1
	adds r2, r2, r3
	lsls r2, r2, #5
	adds r0, r0, r2
	mov ip, r0
	cmp r7, #0
	bne _08089B88
	ldr r1, [sp]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r1, r2
	mov r3, r8
	str r3, [r0]
	b _08089C32
	.align 2, 0
_08089B80: .4byte 0x03003584
_08089B84: .4byte 0x00000207
_08089B88:
	cmp r7, #0x40
	bne _08089B9A
	ldr r1, [sp]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r1, r2
	mov r3, ip
	str r3, [r0]
	b _08089C32
_08089B9A:
	ldr r0, [sp]
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r0, r1
	mov sl, r0
	movs r0, #0x40
	subs r0, r0, r7
	mov sb, r0
	movs r2, #0xf
	str r2, [sp, #4]
_08089BAE:
	mov r3, r8
	ldrh r0, [r3]
	movs r4, #0x1f
	ands r4, r0
	movs r6, #0xf8
	lsls r6, r6, #2
	ands r6, r0
	movs r5, #0xf8
	lsls r5, r5, #7
	ands r5, r0
	mov r1, ip
	ldrh r0, [r1]
	movs r1, #0x1f
	ands r1, r0
	movs r2, #0xf8
	lsls r2, r2, #2
	ands r2, r0
	movs r3, #0xf8
	lsls r3, r3, #7
	ands r3, r0
	mov r0, sb
	muls r0, r4, r0
	muls r1, r7, r1
	adds r0, r0, r1
	asrs r4, r0, #6
	mov r0, sb
	muls r0, r6, r0
	adds r1, r2, #0
	muls r1, r7, r1
	adds r0, r0, r1
	asrs r6, r0, #6
	mov r0, sb
	muls r0, r5, r0
	adds r1, r3, #0
	muls r1, r7, r1
	adds r0, r0, r1
	asrs r5, r0, #6
	movs r2, #0x1f
	ands r4, r2
	movs r3, #0xf8
	lsls r3, r3, #2
	ands r6, r3
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r5, r0
	orrs r4, r6
	orrs r4, r5
	mov r1, sl
	strh r4, [r1]
	movs r2, #2
	add r8, r2
	add ip, r2
	add sl, r2
	ldr r3, [sp, #4]
	subs r3, #1
	str r3, [sp, #4]
	cmp r3, #0
	bge _08089BAE
	ldr r0, [sp]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r3, #0xb8
	lsls r3, r3, #1
	adds r0, r0, r3
	str r0, [r1]
_08089C32:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08089c44
FUN_08089c44: @ 0x08089C44
	push {lr}
	movs r3, #1
	adds r1, r0, #0
	adds r1, #0xa0
	movs r2, #3
_08089C4E:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _08089C4E
	pop {r0}
	bx r0

	thumb_func_start FUN_08089c60
FUN_08089c60: @ 0x08089C60
	push {lr}
	movs r3, #1
	adds r1, r0, #0
	adds r1, #0xa0
	movs r2, #3
_08089C6A:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _08089C6A
	pop {r0}
	bx r0

	thumb_func_start FUN_08089c7c
FUN_08089c7c: @ 0x08089C7C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r6, #0x18
	movs r5, #0
	ldr r2, _08089CC0 @ =0x03002B4C
	ldr r1, [r2]
	adds r1, #0x24
	adds r0, #0x1e
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r5, r0
	bge _08089CD6
	adds r7, r2, #0
_08089C98:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r6, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08022474
	ldrb r0, [r4, #6]
	cmp r0, #3
	bne _08089CC4
	movs r0, #1
	b _08089CD8
	.align 2, 0
_08089CC0: .4byte 0x03002B4C
_08089CC4:
	adds r5, #1
	ldr r1, [r7]
	adds r1, #0x24
	adds r0, r6, #6
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r5, r0
	blt _08089C98
_08089CD6:
	movs r0, #0
_08089CD8:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08089ce0
FUN_08089ce0: @ 0x08089CE0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08089c7c
	cmp r0, #0
	beq _08089D1E
	movs r0, #0x4e
	adds r0, r0, r4
	mov ip, r0
	movs r3, #2
	rsbs r3, r3, #0
	adds r1, r4, #0
	adds r1, #0xa0
	movs r0, #0x92
	lsls r0, r0, #1
	adds r2, r4, r0
_08089D00:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x2c
	cmp r1, r2
	ble _08089D00
	movs r0, #0
	movs r1, #1
	mov r2, ip
	strh r1, [r2]
	str r0, [r4, #0x64]
	movs r0, #0xe3
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08089D1E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08089d24
FUN_08089d24: @ 0x08089D24
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x5c
	ldrh r0, [r1]
	subs r0, #0x46
	movs r3, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _08089D46
	strh r3, [r1]
	movs r0, #2
	subs r1, #0xe
	strh r0, [r1]
	str r3, [r2, #0x64]
	b _08089D4C
_08089D46:
	ldr r0, [r2, #0x64]
	adds r0, #1
	str r0, [r2, #0x64]
_08089D4C:
	pop {r0}
	bx r0

	thumb_func_start FUN_08089d50
FUN_08089d50: @ 0x08089D50
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, [r7, #0x64]
	cmp r0, #3
	bhi _08089D8E
	ldr r6, _08089DA0 @ =0x0203B400
	ldr r5, _08089DA4 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r3, _08089DA8 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r4, #0x1f
	ands r0, r4
	subs r0, #0x10
	adds r2, r7, #0
	adds r2, #0x60
	strh r0, [r2]
	adds r1, #1
	ands r1, r3
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #0x10
	adds r1, r7, #0
	adds r1, #0x62
	strh r0, [r1]
_08089D8E:
	ldr r1, [r7, #0x64]
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _08089DAC
	adds r0, r7, #0
	bl FUN_08089c60
	b _08089DB6
	.align 2, 0
_08089DA0: .4byte 0x0203B400
_08089DA4: .4byte 0x030046B8
_08089DA8: .4byte 0x000003FF
_08089DAC:
	cmp r1, #2
	bne _08089DB6
	adds r0, r7, #0
	bl FUN_08089c44
_08089DB6:
	ldr r0, [r7, #0x64]
	cmp r0, #0xf
	bls _08089DD2
	ldr r0, [r7, #0x74]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x74]
	movs r1, #3
	adds r2, r7, #0
	adds r2, #0x4e
	movs r0, #0
	strh r1, [r2]
	b _08089DD4
_08089DD2:
	adds r0, #1
_08089DD4:
	str r0, [r7, #0x64]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08089ddc
FUN_08089ddc: @ 0x08089DDC
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r0, #0x58
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #6
	subs r0, r0, r1
	lsls r0, r0, #4
	adds r1, r4, #0
	adds r1, #0x5a
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl Div
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x52
	strh r0, [r1]
	ldr r1, [r4, #0x64]
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _08089E18
	adds r0, r4, #0
	bl FUN_08089c60
	b _08089E22
_08089E18:
	cmp r1, #2
	bne _08089E22
	adds r0, r4, #0
	bl FUN_08089c44
_08089E22:
	adds r1, r4, #0
	adds r1, #0x58
	ldrh r0, [r1]
	subs r0, #0x46
	movs r2, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _08089E88
	strh r2, [r1]
	subs r1, #6
	movs r0, #0x80
	lsls r0, r0, #3
	strh r0, [r1]
	movs r0, #4
	subs r1, #4
	strh r0, [r1]
	str r2, [r4, #0x64]
	movs r0, #0xe2
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08089c44
	adds r0, r4, #0
	adds r0, #0x90
	movs r1, #0x40
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0x28
	str r1, [sp, #8]
	movs r1, #0xfa
	str r1, [sp, #0xc]
	movs r1, #8
	movs r2, #1
	movs r3, #1
	bl FUN_08015a90
	adds r0, r4, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	cmp r0, #0
	beq _08089E8E
	adds r0, r4, #0
	adds r0, #0x18
	movs r1, #1
	bl FUN_08022488
	b _08089E8E
_08089E88:
	ldr r0, [r4, #0x64]
	adds r0, #1
	str r0, [r4, #0x64]
_08089E8E:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08089e98
FUN_08089e98: @ 0x08089E98
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r6, _08089EF0 @ =0x0203B400
	ldr r5, _08089EF4 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r3, _08089EF8 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r4, #0x1f
	ands r0, r4
	subs r0, #0x10
	adds r2, r7, #0
	adds r2, #0x60
	strh r0, [r2]
	adds r1, #1
	ands r1, r3
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #0x10
	adds r1, r7, #0
	adds r1, #0x62
	strh r0, [r1]
	ldr r3, [r7, #0x64]
	cmp r3, #3
	bhi _08089EFC
	movs r0, #0x28
	bl FUN_0823b9cc
	adds r0, r7, #0
	adds r0, #0x50
	ldrh r1, [r0]
	ldr r3, [r7, #0x64]
	lsls r3, r3, #4
	adds r0, r7, #0
	movs r2, #8
	bl FUN_08089b48
	b _08089F0E
	.align 2, 0
_08089EF0: .4byte 0x0203B400
_08089EF4: .4byte 0x030046B8
_08089EF8: .4byte 0x000003FF
_08089EFC:
	adds r0, r7, #0
	adds r0, #0x50
	ldrh r2, [r0]
	subs r3, #4
	lsls r3, r3, #4
	adds r0, r7, #0
	movs r1, #8
	bl FUN_08089b48
_08089F0E:
	ldr r0, [r7, #0x64]
	cmp r0, #7
	bls _08089F2C
	adds r0, r7, #0
	adds r0, #0x60
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r0, #5
	adds r2, r7, #0
	adds r2, #0x4e
	strh r0, [r2]
	str r1, [r7, #0x64]
	b _08089F30
_08089F2C:
	adds r0, #1
	str r0, [r7, #0x64]
_08089F30:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08089f38
FUN_08089f38: @ 0x08089F38
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x64]
	cmp r0, #0x59
	bls _08089F4E
	movs r1, #6
	adds r3, r2, #0
	adds r3, #0x4e
	movs r0, #0
	strh r1, [r3]
	b _08089F50
_08089F4E:
	adds r0, #1
_08089F50:
	str r0, [r2, #0x64]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08089f58
FUN_08089f58: @ 0x08089F58
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r1, [r7, #0x64]
	adds r0, r1, #0
	subs r0, #0xa
	cmp r0, #0x13
	bls _08089F6C
	subs r0, #0x32
	cmp r0, #0x13
	bhi _08089FB0
_08089F6C:
	ldr r6, _08089FA4 @ =0x0203B400
	ldr r5, _08089FA8 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r3, _08089FAC @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r4, #0x1f
	ands r0, r4
	subs r0, #0x10
	adds r2, r7, #0
	adds r2, #0x60
	strh r0, [r2]
	adds r1, #1
	ands r1, r3
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #0x10
	adds r1, r7, #0
	adds r1, #0x62
	strh r0, [r1]
	b _08089FBC
	.align 2, 0
_08089FA4: .4byte 0x0203B400
_08089FA8: .4byte 0x030046B8
_08089FAC: .4byte 0x000003FF
_08089FB0:
	adds r0, r7, #0
	adds r0, #0x60
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
_08089FBC:
	ldr r0, [r7, #0x64]
	cmp r0, #0xa
	beq _08089FCE
	cmp r0, #0x14
	beq _08089FCE
	cmp r0, #0x3c
	beq _08089FCE
	cmp r0, #0x46
	bne _08089FD4
_08089FCE:
	movs r0, #0xd3
	bl PlaySound_082406e0
_08089FD4:
	ldr r0, [r7, #0x64]
	cmp r0, #0x59
	bls _08089FE6
	movs r1, #7
	adds r2, r7, #0
	adds r2, #0x4e
	movs r0, #0
	strh r1, [r2]
	b _08089FE8
_08089FE6:
	adds r0, #1
_08089FE8:
	str r0, [r7, #0x64]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08089ff0
FUN_08089ff0: @ 0x08089FF0
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, [r4, #0x64]
	ldr r0, [r4, #0x54]
	cmp r1, r0
	bne _0808A00C
	ldr r0, [r4, #0x68]
	cmp r0, #0
	beq _0808A00C
	movs r1, #0
	bl FUN_082318ac
	movs r0, #0
	str r0, [r4, #0x68]
_0808A00C:
	ldr r0, [r4, #0x64]
	adds r0, #1
	str r0, [r4, #0x64]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808a018
FUN_0808a018: @ 0x0808A018
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r1, _0808A068 @ =0x085AC044
	adds r5, r4, #0
	adds r5, #0x4e
	ldrh r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrh r0, [r5]
	cmp r0, #0
	beq _0808A0E0
	movs r5, #0
	adds r7, r4, #0
	adds r7, #0x5c
	adds r6, r4, #0
	adds r6, #0x60
	movs r0, #0x62
	adds r0, r0, r4
	mov ip, r0
_0808A046:
	movs r0, #0x2c
	muls r0, r5, r0
	adds r0, #0x74
	adds r2, r4, r0
	ldr r0, [r4, #0x6c]
	ldr r1, [r4, #0x70]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	movs r1, #0
	ldrsh r3, [r7, r1]
	cmp r5, #4
	bhi _0808A0C8
	lsls r0, r5, #2
	ldr r1, _0808A06C @ =_0808A070
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808A068: .4byte 0x085AC044
_0808A06C: .4byte _0808A070
_0808A070: @ jump table
	.4byte _0808A084 @ case 0
	.4byte _0808A09E @ case 1
	.4byte _0808A0A4 @ case 2
	.4byte _0808A0B0 @ case 3
	.4byte _0808A0BC @ case 4
_0808A084:
	adds r0, r4, #0
	adds r0, #0x58
	ldrh r0, [r0]
	ldrh r1, [r2, #0x1e]
	adds r0, r0, r1
	strh r0, [r2, #0x1e]
	adds r0, r4, #0
	adds r0, #0x52
	ldrh r0, [r0]
	lsrs r0, r0, #4
	strb r0, [r2, #8]
	strb r0, [r2, #9]
	b _0808A0C8
_0808A09E:
	ldrh r0, [r2, #0x1c]
	subs r0, r0, r3
	b _0808A0C0
_0808A0A4:
	ldrh r0, [r2, #0x1c]
	adds r0, r0, r3
	strh r0, [r2, #0x1c]
	ldrh r0, [r2, #0x20]
	adds r0, r0, r3
	b _0808A0C6
_0808A0B0:
	ldrh r0, [r2, #0x1c]
	subs r0, r0, r3
	strh r0, [r2, #0x1c]
	ldrh r0, [r2, #0x20]
	adds r0, r0, r3
	b _0808A0C6
_0808A0BC:
	ldrh r0, [r2, #0x1c]
	adds r0, r0, r3
_0808A0C0:
	strh r0, [r2, #0x1c]
	ldrh r0, [r2, #0x20]
	subs r0, r0, r3
_0808A0C6:
	strh r0, [r2, #0x20]
_0808A0C8:
	ldrh r0, [r6]
	ldrh r1, [r2, #0x1c]
	adds r0, r0, r1
	strh r0, [r2, #0x1c]
	mov r1, ip
	ldrh r0, [r1]
	ldrh r1, [r2, #0x20]
	adds r0, r0, r1
	strh r0, [r2, #0x20]
	adds r5, #1
	cmp r5, #4
	ble _0808A046
_0808A0E0:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808a0e8
FUN_0808a0e8: @ 0x0808A0E8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x74
	movs r5, #4
_0808A0F2:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x2c
	subs r5, #1
	cmp r5, #0
	bge _0808A0F2
	adds r0, r6, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	cmp r0, #0
	beq _0808A112
	adds r0, r6, #0
	adds r0, #0x18
	bl FUN_08022428
_0808A112:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808a11c
FUN_0808a11c: @ 0x0808A11C
	push {r4, lr}
	movs r4, #0
_0808A120:
	adds r0, r4, #0
	bl GetValuableItemID
	subs r0, #0x38
	cmp r0, #7
	bls _0808A134
	adds r4, #1
	cmp r4, #0xf
	ble _0808A120
	movs r0, #0
_0808A134:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808a13c
FUN_0808a13c: @ 0x0808A13C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	adds r4, r1, #0
	movs r0, #0x4f
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _0808A164
	bl fetch_082316e4
	adds r1, r6, #0
	adds r1, #0x4c
	strh r0, [r1]
	adds r0, r1, #0
	b _0808A16A
_0808A164:
	adds r0, r6, #0
	adds r0, #0x4c
	strh r1, [r0]
_0808A16A:
	ldrh r1, [r0]
	cmp r1, #0
	beq _0808A18C
	adds r0, r6, #0
	adds r0, #0x18
	adds r1, r4, #0
	movs r2, #0xa
	bl FUN_080223f4
	movs r0, #0
	adds r1, r6, #0
	adds r1, #0x4e
	strh r0, [r1]
	str r0, [r6, #0x64]
	movs r0, #1
	mov sl, r0
	b _0808A1A2
_0808A18C:
	movs r0, #1
	adds r2, r6, #0
	adds r2, #0x4e
	strh r0, [r2]
	str r1, [r6, #0x64]
	movs r1, #0
	mov sl, r1
	movs r0, #0xe3
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0808A1A2:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0808A1CC
	bl fetch_082316e4
	adds r1, r6, #0
	adds r1, #0x6c
	strh r0, [r1]
	bl fetch_082316e4
	adds r1, r6, #0
	adds r1, #0x6e
	strh r0, [r1]
	bl fetch_082316e4
	adds r1, r6, #0
	adds r1, #0x70
	strh r0, [r1]
	b _0808A1E8
_0808A1CC:
	ldr r0, _0808A240 @ =0x030046A0
	ldr r1, [r0]
	ldrh r2, [r1, #0x30]
	adds r0, r6, #0
	adds r0, #0x6c
	strh r2, [r0]
	ldrh r0, [r1, #0x32]
	adds r2, r6, #0
	adds r2, #0x6e
	strh r0, [r2]
	ldrh r1, [r1, #0x34]
	adds r0, r6, #0
	adds r0, #0x70
	strh r1, [r0]
_0808A1E8:
	bl FUN_0808a11c
	adds r5, r6, #0
	adds r5, #0x50
	strh r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #3
	movs r0, #0x68
	bl FUN_0823174c
	adds r4, r6, #0
	adds r4, #0x58
	strh r0, [r4]
	adds r1, r6, #0
	adds r1, #0x5a
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #2
	movs r0, #0x6d
	bl FUN_0823174c
	adds r1, r6, #0
	adds r1, #0x5c
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	subs r1, #0xc
	movs r0, #0xfe
	lsls r0, r0, #3
	strh r0, [r1]
	movs r0, #0x65
	bl prepare_08231510
	mov r8, r5
	mov sb, r4
	cmp r0, #0
	beq _0808A244
	bl fetch_082316e4
	str r0, [r6, #0x68]
	bl fetch_082316e4
	b _0808A246
	.align 2, 0
_0808A240: .4byte 0x030046A0
_0808A244:
	str r0, [r6, #0x68]
_0808A246:
	str r0, [r6, #0x54]
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r1, _0808A294 @ =0x00002499
	bl FUN_0822b16c
	movs r5, #0
	movs r7, #1
_0808A258:
	movs r0, #0x2c
	muls r0, r5, r0
	adds r0, #0x74
	adds r4, r6, r0
	adds r0, r4, #0
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r2, #2
	bl FUN_0822a470
	mov r0, r8
	ldrh r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	strh r0, [r4, #0x10]
	ldr r0, [r6, #0x6c]
	ldr r1, [r6, #0x70]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	cmp r5, #0
	bne _0808A298
	mov r1, sb
	ldrh r0, [r1]
	ldrh r2, [r4, #0x1e]
	adds r0, r0, r2
	strh r0, [r4, #0x1e]
	ldr r0, [r4]
	orrs r0, r7
	b _0808A2A4
	.align 2, 0
_0808A294: .4byte 0x00002499
_0808A298:
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	mov r1, sl
	orrs r0, r1
_0808A2A4:
	str r0, [r4]
	strb r7, [r4, #7]
	adds r5, #1
	cmp r5, #4
	ble _0808A258
	mov r2, r8
	ldrh r1, [r2]
	ldr r0, _0808A2EC @ =0x03003584
	ldr r2, _0808A2F0 @ =0x00000207
	adds r1, r1, r2
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r4, r6, r1
	ldr r2, _0808A2F4 @ =0x04000008
	adds r1, r4, #0
	bl CpuSet
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r6, r2
	str r4, [r0]
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r6, r1
	str r4, [r0]
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0808A2EC: .4byte 0x03003584
_0808A2F0: .4byte 0x00000207
_0808A2F4: .4byte 0x04000008

	thumb_func_start FUN_0808a2f8
FUN_0808a2f8: @ 0x0808A2F8
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xc8
	lsls r1, r1, #1
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0808A334
	ldr r1, _0808A32C @ =FUN_0808a018
	ldr r2, _0808A330 @ =FUN_0808a0e8
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0808a13c
	cmp r0, #0
	bge _0808A334
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0808A336
	.align 2, 0
_0808A32C: .4byte FUN_0808a018
_0808A330: .4byte FUN_0808a0e8
_0808A334:
	adds r0, r4, #0
_0808A336:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808a33c
FUN_0808a33c: @ 0x0808A33C
	movs r3, #0x9f
	lsls r3, r3, #4
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _0808A350 @ =0x000009EC
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_0808A350: .4byte 0x000009EC

	thumb_func_start FUN_0808a354
FUN_0808a354: @ 0x0808A354
	push {r4, lr}
	adds r3, r0, #0
	ldr r4, _0808A388 @ =0x000009F4
	adds r0, r3, r4
	str r1, [r0]
	ldr r0, _0808A38C @ =0x000009EE
	adds r1, r3, r0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _0808A390 @ =0x000009F8
	adds r0, r3, r1
	strb r2, [r0]
	lsls r2, r2, #0x18
	cmp r2, #0
	beq _0808A39C
	ldr r4, _0808A394 @ =0x00000FCC
	adds r1, r3, r4
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0808A398 @ =0x0000102C
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	b _0808A3B2
	.align 2, 0
_0808A388: .4byte 0x000009F4
_0808A38C: .4byte 0x000009EE
_0808A390: .4byte 0x000009F8
_0808A394: .4byte 0x00000FCC
_0808A398: .4byte 0x0000102C
_0808A39C:
	ldr r4, _0808A3BC @ =0x00000FCC
	adds r1, r3, r4
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldr r0, _0808A3C0 @ =0x0000102C
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
_0808A3B2:
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808A3BC: .4byte 0x00000FCC
_0808A3C0: .4byte 0x0000102C

	thumb_func_start FUN_0808a3c4
FUN_0808a3c4: @ 0x0808A3C4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r1, #0
	adds r1, r2, #0
	adds r6, r3, #0
	ldr r7, [sp, #0x24]
	movs r4, #0
	str r4, [sp, #0xc]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	adds r2, r5, #0
	movs r3, #0
	bl FUN_0822c0b8
	movs r0, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0822c398
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	ldr r1, _0808A418 @ =0x030043F0
	ldr r2, _0808A41C @ =0x04000018
	adds r0, r7, #0
	bl CpuSet
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808A418: .4byte 0x030043F0
_0808A41C: .4byte 0x04000018

	thumb_func_start FUN_0808a420
FUN_0808a420: @ 0x0808A420
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #4
	ldr r0, _0808A43C @ =0x03003ED0
	adds r3, r3, r0
	ldr r0, [r3, #0x2c]
	movs r3, #0x1f
	ands r1, r3
	lsls r1, r1, #1
	adds r0, r0, r1
	ands r2, r3
	lsls r2, r2, #6
	adds r0, r0, r2
	bx lr
	.align 2, 0
_0808A43C: .4byte 0x03003ED0

	thumb_func_start FUN_0808a440
FUN_0808a440: @ 0x0808A440
	push {lr}
	adds r2, r0, #0
	movs r0, #0x11
	cmp r1, #0
	beq _0808A452
	movs r0, #0x31
	cmp r1, #1
	bne _0808A452
	movs r0, #0x91
_0808A452:
	adds r0, r2, r0
	pop {r1}
	bx r1

	thumb_func_start FUN_0808a458
FUN_0808a458: @ 0x0808A458
	push {r4, lr}
	ldr r2, _0808A480 @ =0x03004494
	strh r1, [r2]
	ldr r3, _0808A484 @ =0x03004454
	ldr r4, _0808A488 @ =0x0000FFFF
	adds r2, r4, #0
	strh r2, [r3]
	ldr r2, _0808A48C @ =0x03004040
	str r0, [r2]
	ldr r2, _0808A490 @ =0x03004464
	strh r1, [r2]
	ldr r2, _0808A494 @ =0x03004490
	movs r1, #0
	strh r1, [r2]
	ldr r1, _0808A498 @ =0x0300445C
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808A480: .4byte 0x03004494
_0808A484: .4byte 0x03004454
_0808A488: .4byte 0x0000FFFF
_0808A48C: .4byte 0x03004040
_0808A490: .4byte 0x03004464
_0808A494: .4byte 0x03004490
_0808A498: .4byte 0x0300445C

	thumb_func_start min
min: @ 0x0808A49C
	push {lr}
	adds r2, r0, #0
	adds r0, r1, #0
	cmp r2, r0
	bgt _0808A4A8
	adds r0, r2, #0
_0808A4A8:
	pop {r1}
	bx r1

	thumb_func_start FUN_0808a4ac
FUN_0808a4ac: @ 0x0808A4AC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r1
	adds r4, r2, #0
	adds r6, r3, #0
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp]
	movs r5, #0x64
	muls r0, r5, r0
	subs r7, r4, r0
	adds r0, r7, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r7, r1
	str r1, [sp, #8]
	adds r0, r6, #0
	movs r1, #0x64
	bl Div
	add r4, sp, #0xc
	str r0, [sp, #0xc]
	muls r0, r5, r0
	subs r7, r6, r0
	adds r0, r7, #0
	movs r1, #0xa
	bl Div
	str r0, [r4, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r7, r1
	str r1, [r4, #8]
	mov r0, r8
	cmp r0, #0
	bne _0808A522
	movs r6, #0
	movs r1, #0x1c
	mov r8, r1
	mov sb, r6
	movs r0, #3
	mov sl, r0
	movs r7, #0xd0
	lsls r7, r7, #8
	movs r0, #0
	ldr r1, [sp, #0x3c]
	b _0808A538
_0808A522:
	movs r6, #1
	movs r1, #0x9b
	mov r8, r1
	mov sb, r6
	movs r0, #4
	mov sl, r0
	movs r7, #0xf0
	lsls r7, r7, #8
	ldr r1, [sp, #0x3c]
	subs r1, #1
	movs r0, #0
_0808A538:
	ldr r2, [sp, #0x40]
	bl FUN_0808a420
	adds r5, r0, #0
	adds r0, r7, #0
	orrs r0, r6
	strh r0, [r5]
	adds r5, #2
	str r0, [sp, #0x18]
	adds r4, r7, #0
	mov r1, r8
	orrs r4, r1
	mov r8, sp
	movs r6, #2
_0808A554:
	mov r1, r8
	adds r1, #4
	mov r8, r1
	subs r1, #4
	ldm r1!, {r0}
	mov r1, sb
	bl FUN_0808a440
	orrs r0, r7
	strh r0, [r5]
	adds r5, #2
	subs r6, #1
	cmp r6, #0
	bge _0808A554
	strh r4, [r5]
	adds r5, #2
	add r4, sp, #0xc
	movs r6, #2
_0808A578:
	ldm r4!, {r0}
	mov r1, sb
	bl FUN_0808a440
	orrs r0, r7
	strh r0, [r5]
	adds r5, #2
	subs r6, #1
	cmp r6, #0
	bge _0808A578
	mov r0, sl
	cmp r0, #0
	beq _0808A5A0
	ldr r0, [sp, #0x18]
	mov r6, sl
_0808A596:
	strh r0, [r5]
	adds r5, #2
	subs r6, #1
	cmp r6, #0
	bne _0808A596
_0808A5A0:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808a5b0
FUN_0808a5b0: @ 0x0808A5B0
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r2, #0
	adds r5, r3, #0
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r2, r0, r3
	ldr r3, [r2]
	movs r6, #0xd9
	lsls r6, r6, #2
	adds r2, r3, r6
	ldrh r2, [r2]
	adds r6, #2
	adds r3, r3, r6
	ldrh r3, [r3]
	str r4, [sp]
	str r5, [sp, #4]
	bl FUN_0808a4ac
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808a5e0
FUN_0808a5e0: @ 0x0808A5E0
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r2, #0
	adds r5, r3, #0
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r2, r0, r3
	ldr r3, [r2]
	movs r6, #0xda
	lsls r6, r6, #2
	adds r2, r3, r6
	ldrh r2, [r2]
	adds r6, #2
	adds r3, r3, r6
	ldrh r3, [r3]
	str r4, [sp]
	str r5, [sp, #4]
	bl FUN_0808a4ac
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808a610
FUN_0808a610: @ 0x0808A610
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	adds r6, r1, #0
	mov sb, r2
	mov sl, r3
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r1, r0, r2
	ldrh r1, [r1]
	ldr r5, _0808A648 @ =0x00000366
	adds r0, r0, r5
	ldrh r2, [r0]
	cmp r1, #0
	bne _0808A64C
	movs r1, #0
	movs r5, #0
	mov r8, r5
	b _0808A666
	.align 2, 0
_0808A648: .4byte 0x00000366
_0808A64C:
	subs r1, #1
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	subs r0, r0, r1
	subs r1, r2, #1
	bl Div
	adds r1, r0, #1
	asrs r5, r1, #3
	lsls r0, r5, #3
	subs r0, r1, r0
	mov r8, r0
_0808A666:
	cmp r6, #0
	bne _0808A6B4
	movs r7, #0x43
	movs r0, #0x4b
	str r0, [sp]
	movs r6, #0x4c
	cmp r1, #0x27
	ble _0808A67C
	movs r4, #0xf8
	lsls r4, r4, #2
	b _0808A6A2
_0808A67C:
	cmp r1, #0x13
	ble _0808A688
	ldr r4, _0808A684 @ =0x0000029F
	b _0808A6A2
	.align 2, 0
_0808A684: .4byte 0x0000029F
_0808A688:
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r3, r4, r1
	ldrh r2, [r3]
	lsrs r0, r2, #2
	movs r1, #1
	ands r0, r1
	movs r4, #0x12
	cmp r0, #0
	beq _0808A69E
	ldr r4, _0808A6B0 @ =0x0000109F
_0808A69E:
	adds r0, r2, #1
	strh r0, [r3]
_0808A6A2:
	movs r0, #0
	mov r1, sb
	mov r2, sl
	bl FUN_0808a420
	adds r3, r0, #0
	b _0808A6E2
	.align 2, 0
_0808A6B0: .4byte 0x0000109F
_0808A6B4:
	movs r7, #0x63
	movs r2, #0x6b
	str r2, [sp]
	ldr r6, _0808A750 @ =0x000004BD
	movs r4, #0xf8
	lsls r4, r4, #2
	cmp r1, #0x27
	bgt _0808A6CC
	ldr r4, _0808A754 @ =0x0000109F
	cmp r1, #0x13
	ble _0808A6CC
	ldr r4, _0808A758 @ =0x0000029F
_0808A6CC:
	mov r1, sb
	subs r1, #1
	movs r0, #0
	mov r2, sl
	bl FUN_0808a420
	adds r3, r0, #0
	ldr r2, _0808A75C @ =0x0000D0BD
	adds r1, r2, #0
	strh r1, [r3]
	adds r3, #2
_0808A6E2:
	ldr r2, _0808A760 @ =0x03004406
	ldrh r1, [r2]
	cmp r1, r4
	beq _0808A6EC
	strh r4, [r2]
_0808A6EC:
	movs r4, #0
	cmp r4, r5
	bge _0808A708
	ldr r2, _0808A764 @ =0xFFFFD000
	adds r1, r2, #0
	adds r2, r7, #0
	orrs r2, r1
	adds r4, r5, #0
_0808A6FC:
	strh r2, [r3]
	adds r3, #2
	subs r4, #1
	cmp r4, #0
	bne _0808A6FC
	adds r4, r5, #0
_0808A708:
	mov r5, r8
	cmp r5, #0
	beq _0808A720
	mov r1, r8
	subs r1, #8
	subs r1, r7, r1
	ldr r5, _0808A764 @ =0xFFFFD000
	adds r2, r5, #0
	orrs r1, r2
	strh r1, [r3]
	adds r3, #2
	adds r4, #1
_0808A720:
	cmp r4, #9
	bgt _0808A736
	ldr r2, _0808A764 @ =0xFFFFD000
	adds r1, r2, #0
	ldr r5, [sp]
	orrs r1, r5
_0808A72C:
	strh r1, [r3]
	adds r3, #2
	adds r4, #1
	cmp r4, #9
	ble _0808A72C
_0808A736:
	ldr r2, _0808A764 @ =0xFFFFD000
	adds r1, r2, #0
	orrs r6, r1
	strh r6, [r3]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0808A750: .4byte 0x000004BD
_0808A754: .4byte 0x0000109F
_0808A758: .4byte 0x0000029F
_0808A75C: .4byte 0x0000D0BD
_0808A760: .4byte 0x03004406
_0808A764: .4byte 0xFFFFD000

	thumb_func_start FUN_0808a768
FUN_0808a768: @ 0x0808A768
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	str r1, [sp, #0x10]
	mov sl, r2
	str r3, [sp, #0x14]
	movs r0, #0x9e
	lsls r0, r0, #4
	add r0, r8
	ldr r0, [r0]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r1, r0, r2
	ldrh r1, [r1]
	ldr r3, _0808A79C @ =0x0000036A
	adds r0, r0, r3
	ldrh r2, [r0]
	cmp r1, #0
	bne _0808A7A0
	movs r5, #0
	mov sb, r5
	b _0808A7BA
	.align 2, 0
_0808A79C: .4byte 0x0000036A
_0808A7A0:
	subs r1, #1
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	subs r0, r0, r1
	subs r1, r2, #1
	bl Div
	adds r0, #1
	asrs r5, r0, #3
	lsls r1, r5, #3
	subs r0, r0, r1
	mov sb, r0
_0808A7BA:
	movs r0, #0x9e
	lsls r0, r0, #4
	add r0, r8
	ldr r2, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	movs r4, #0x1f
	cmp r0, #5
	beq _0808A7D2
	ldr r4, _0808A810 @ =0x0000035F
_0808A7D2:
	ldr r3, [sp, #0x10]
	cmp r3, #0
	bne _0808A81C
	movs r7, #0x53
	movs r0, #0x4b
	str r0, [sp, #0x18]
	movs r6, #0x4c
	movs r1, #0x60
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0808A802
	ldr r0, _0808A814 @ =0x00000A02
	add r0, r8
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x12
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _0808A802
	ldr r4, _0808A818 @ =0x00007FFF
_0808A802:
	movs r0, #0
	mov r1, sl
	ldr r2, [sp, #0x14]
	bl FUN_0808a420
	adds r3, r0, #0
	b _0808A83A
	.align 2, 0
_0808A810: .4byte 0x0000035F
_0808A814: .4byte 0x00000A02
_0808A818: .4byte 0x00007FFF
_0808A81C:
	movs r7, #0x73
	movs r1, #0x6b
	str r1, [sp, #0x18]
	ldr r6, _0808A940 @ =0x000004BD
	mov r1, sl
	subs r1, #1
	movs r0, #0
	ldr r2, [sp, #0x14]
	bl FUN_0808a420
	adds r3, r0, #0
	ldr r2, _0808A944 @ =0x0000D0BD
	adds r1, r2, #0
	strh r1, [r3]
	adds r3, #2
_0808A83A:
	ldr r2, _0808A948 @ =0x03004408
	ldrh r1, [r2]
	cmp r1, r4
	beq _0808A844
	strh r4, [r2]
_0808A844:
	movs r4, #0
	ldr r1, _0808A94C @ =0x030047A4
	mov sl, r1
	cmp r4, r5
	bge _0808A864
	ldr r2, _0808A950 @ =0xFFFFD000
	adds r1, r2, #0
	adds r2, r7, #0
	orrs r2, r1
	adds r4, r5, #0
_0808A858:
	strh r2, [r3]
	adds r3, #2
	subs r4, #1
	cmp r4, #0
	bne _0808A858
	adds r4, r5, #0
_0808A864:
	mov r5, sb
	cmp r5, #0
	beq _0808A87C
	mov r1, sb
	subs r1, #8
	subs r1, r7, r1
	ldr r5, _0808A950 @ =0xFFFFD000
	adds r2, r5, #0
	orrs r1, r2
	strh r1, [r3]
	adds r3, #2
	adds r4, #1
_0808A87C:
	cmp r4, #9
	bgt _0808A892
	ldr r2, _0808A950 @ =0xFFFFD000
	adds r1, r2, #0
	ldr r5, [sp, #0x18]
	orrs r1, r5
_0808A888:
	strh r1, [r3]
	adds r3, #2
	adds r4, #1
	cmp r4, #9
	ble _0808A888
_0808A892:
	ldr r1, _0808A950 @ =0xFFFFD000
	adds r7, r1, #0
	orrs r6, r7
	strh r6, [r3]
	mov r2, sl
	ldr r1, [r2]
	movs r2, #0x80
	lsls r2, r2, #5
	ands r1, r2
	cmp r1, #0
	bne _0808A98C
	ldr r3, [sp, #0x10]
	cmp r3, #0
	bne _0808A98C
	movs r1, #0x9e
	lsls r1, r1, #4
	add r1, r8
	ldr r1, [r1]
	movs r2, #8
	movs r5, #0xde
	lsls r5, r5, #2
	adds r1, r1, r5
	ldr r1, [r1]
	ands r1, r2
	cmp r1, #0
	beq _0808A95C
	ldr r5, _0808A954 @ =0x030046A0
	ldr r0, [r5]
	movs r4, #0xef
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	movs r1, #0xfa
	lsls r1, r1, #2
	bl Div
	str r0, [sp]
	ldr r2, [r5]
	adds r2, r2, r4
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r4, [r2]
	subs r4, r4, r1
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp, #4]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #8]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [sp, #0xc]
	movs r0, #0
	movs r1, #9
	movs r2, #3
	bl FUN_0808a420
	adds r4, r0, #0
	mov r6, sp
	movs r5, #3
_0808A922:
	ldm r6!, {r0}
	movs r1, #0
	bl FUN_0808a440
	adds r1, r0, #0
	orrs r1, r7
	strh r1, [r4]
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _0808A922
	ldr r2, _0808A958 @ =0x00000A2F
	add r2, r8
	movs r1, #1
	b _0808A98A
	.align 2, 0
_0808A940: .4byte 0x000004BD
_0808A944: .4byte 0x0000D0BD
_0808A948: .4byte 0x03004408
_0808A94C: .4byte 0x030047A4
_0808A950: .4byte 0xFFFFD000
_0808A954: .4byte 0x030046A0
_0808A958: .4byte 0x00000A2F
_0808A95C:
	ldr r1, _0808A99C @ =0x00000A2F
	add r1, r8
	ldrb r1, [r1]
	cmp r1, #0
	beq _0808A98C
	movs r0, #0
	movs r1, #9
	movs r2, #3
	bl FUN_0808a420
	adds r1, r0, #0
	movs r2, #0xd0
	lsls r2, r2, #8
	adds r3, r2, #0
	movs r2, #3
_0808A97A:
	strh r3, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0808A97A
	ldr r2, _0808A99C @ =0x00000A2F
	add r2, r8
	movs r1, #0
_0808A98A:
	strb r1, [r2]
_0808A98C:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0808A99C: .4byte 0x00000A2F
_0808A9A0:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_0808a9a4
FUN_0808a9a4: @ 0x0808A9A4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r7, r1, #0
	mov r8, r2
	mov sb, r3
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x1e
	bne _0808A9CC
	movs r6, #1
	b _0808AA4C
_0808A9CC:
	ldr r0, _0808AA04 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0xdd
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _0808AA08 @ =0x000009C3
	cmp r1, r0
	ble _0808AA0C
	adds r0, #0x59
	adds r4, r5, r0
	ldrh r2, [r4]
	lsrs r0, r2, #4
	movs r1, #1
	ands r0, r1
	movs r6, #1
	cmp r0, #0
	beq _0808A9F4
	movs r6, #0
_0808A9F4:
	movs r0, #0x3f
	ands r0, r2
	cmp r0, #2
	bne _0808AA32
	movs r0, #0x99
	lsls r0, r0, #1
	b _0808AA2E
	.align 2, 0
_0808AA04: .4byte 0x030046A0
_0808AA08: .4byte 0x000009C3
_0808AA0C:
	cmp r1, #0
	ble _0808AA44
	ldr r1, _0808AA3C @ =0x00000A1C
	adds r4, r5, r1
	ldrh r2, [r4]
	lsrs r0, r2, #5
	movs r1, #1
	ands r0, r1
	movs r6, #1
	cmp r0, #0
	beq _0808AA24
	movs r6, #0
_0808AA24:
	movs r0, #0x3f
	ands r0, r2
	cmp r0, #2
	bne _0808AA32
	ldr r0, _0808AA40 @ =0x00000131
_0808AA2E:
	bl PlaySound_082406e0
_0808AA32:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _0808AA4C
	.align 2, 0
_0808AA3C: .4byte 0x00000A1C
_0808AA40: .4byte 0x00000131
_0808AA44:
	movs r6, #0
	ldr r2, _0808AA74 @ =0x00000A1C
	adds r0, r5, r2
	strh r6, [r0]
_0808AA4C:
	movs r0, #0
	mov r1, r8
	mov r2, sb
	bl FUN_0808a420
	adds r3, r0, #0
	cmp r6, #0
	beq _0808AA80
	movs r2, #0
	ldr r1, _0808AA78 @ =0x030046A0
	ldr r0, _0808AA7C @ =0xFFFFD000
	adds r4, r0, #0
_0808AA64:
	adds r0, r2, #3
	orrs r0, r4
	strh r0, [r3]
	adds r3, #2
	adds r2, #1
	cmp r2, #0xb
	ble _0808AA64
	b _0808AB32
	.align 2, 0
_0808AA74: .4byte 0x00000A1C
_0808AA78: .4byte 0x030046A0
_0808AA7C: .4byte 0xFFFFD000
_0808AA80:
	cmp r7, #1
	bne _0808AA8C
	ldr r2, _0808AA88 @ =0x0000029F
	b _0808AAE2
	.align 2, 0
_0808AA88: .4byte 0x0000029F
_0808AA8C:
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x10
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0808AAD8
	ldr r2, _0808AAD0 @ =0x00000A04
	adds r0, r5, r2
	ldrh r0, [r0]
	ldr r2, _0808AAD4 @ =0x0000029F
	cmp r0, #0x24
	bls _0808AAB6
	subs r2, #0xa4
	cmp r0, #0x2c
	bls _0808AAB6
	cmp r0, #0x34
	bhi _0808AAB6
	subs r2, #0x84
_0808AAB6:
	ldr r4, _0808AAD0 @ =0x00000A04
	adds r1, r5, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _0808AAE2
	movs r0, #0
	strh r0, [r1]
	b _0808AAE2
	.align 2, 0
_0808AAD0: .4byte 0x00000A04
_0808AAD4: .4byte 0x0000029F
_0808AAD8:
	ldr r0, _0808AB80 @ =0x00000A04
	adds r1, r5, r0
	movs r0, #0x34
	strh r0, [r1]
	ldr r2, _0808AB84 @ =0x00000177
_0808AAE2:
	ldr r1, _0808AB88 @ =0x03004404
	ldrh r0, [r1]
	cmp r0, r2
	beq _0808AAEC
	strh r2, [r1]
_0808AAEC:
	ldr r0, _0808AB8C @ =0x030046A0
	ldr r1, [r0]
	ldr r2, _0808AB90 @ =0x00000942
	adds r1, r1, r2
	movs r2, #0
	ldrsh r4, [r1, r2]
	ldr r2, _0808AB94 @ =0x0000D05C
	adds r1, r2, #0
	strh r1, [r3]
	adds r3, #2
	movs r2, #0
	adds r1, r0, #0
	cmp r2, r4
	bge _0808AB1A
	ldr r2, _0808AB98 @ =0x0000D05D
	adds r0, r2, #0
	adds r2, r4, #0
_0808AB0E:
	strh r0, [r3]
	adds r3, #2
	subs r2, #1
	cmp r2, #0
	bne _0808AB0E
	adds r2, r4, #0
_0808AB1A:
	cmp r2, #9
	bgt _0808AB2C
	ldr r4, _0808AB9C @ =0x0000D05E
	adds r0, r4, #0
_0808AB22:
	strh r0, [r3]
	adds r3, #2
	adds r2, #1
	cmp r2, #9
	ble _0808AB22
_0808AB2C:
	ldr r2, _0808ABA0 @ =0x0000D05F
	adds r0, r2, #0
	strh r0, [r3]
_0808AB32:
	movs r4, #0x9e
	lsls r4, r4, #4
	adds r0, r5, r4
	ldr r0, [r0]
	ldr r2, _0808ABA4 @ =0x0000038E
	adds r0, r0, r2
	ldrb r0, [r0]
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #0xb2
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	cmp r0, #0
	ble _0808ABAC
	movs r0, #0
	movs r1, #0xf
	movs r2, #0x11
	bl FUN_0808a420
	adds r3, r0, #0
	movs r2, #0
	movs r0, #0xd0
	lsls r0, r0, #8
	adds r1, r0, #0
_0808AB66:
	adds r0, r2, #0
	adds r0, #0x3b
	orrs r0, r1
	strh r0, [r3]
	adds r3, #2
	adds r2, #1
	cmp r2, #4
	ble _0808AB66
	ldr r2, _0808ABA8 @ =0x00000A96
	adds r1, r5, r2
	movs r0, #1
	b _0808ABDA
	.align 2, 0
_0808AB80: .4byte 0x00000A04
_0808AB84: .4byte 0x00000177
_0808AB88: .4byte 0x03004404
_0808AB8C: .4byte 0x030046A0
_0808AB90: .4byte 0x00000942
_0808AB94: .4byte 0x0000D05C
_0808AB98: .4byte 0x0000D05D
_0808AB9C: .4byte 0x0000D05E
_0808ABA0: .4byte 0x0000D05F
_0808ABA4: .4byte 0x0000038E
_0808ABA8: .4byte 0x00000A96
_0808ABAC:
	ldr r4, _0808ABE8 @ =0x00000A96
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808ABDC
	movs r0, #0
	movs r1, #0xf
	movs r2, #0x11
	bl FUN_0808a420
	adds r3, r0, #0
	movs r1, #0xd0
	lsls r1, r1, #8
	adds r0, r1, #0
	movs r2, #4
_0808ABCA:
	strh r0, [r3]
	adds r3, #2
	subs r2, #1
	cmp r2, #0
	bge _0808ABCA
	ldr r2, _0808ABE8 @ =0x00000A96
	adds r1, r5, r2
	movs r0, #0
_0808ABDA:
	strb r0, [r1]
_0808ABDC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808ABE8: .4byte 0x00000A96

	thumb_func_start FUN_0808abec
FUN_0808abec: @ 0x0808ABEC
	push {r4, r5, lr}
	adds r3, r0, #0
	cmp r1, #1
	bne _0808AC58
	movs r4, #0x1f
	ldr r1, _0808AC30 @ =0x00000A1E
	adds r0, r3, r1
	movs r5, #0
	ldrsh r2, [r0, r5]
	ldr r1, _0808AC34 @ =0x030046A0
	ldr r0, [r1]
	movs r5, #0xae
	lsls r5, r5, #2
	adds r0, r0, r5
	ldr r0, [r0]
	adds r5, r1, #0
	cmp r2, r0
	bge _0808AC3C
	movs r1, #0xa2
	lsls r1, r1, #4
	adds r0, r3, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x12
	movs r0, #1
	ands r1, r0
	ldr r2, _0808AC38 @ =0x00007FFF
	cmp r1, #0
	beq _0808AC7C
_0808AC2A:
	movs r2, #0xf8
	lsls r2, r2, #2
	b _0808AC7C
	.align 2, 0
_0808AC30: .4byte 0x00000A1E
_0808AC34: .4byte 0x030046A0
_0808AC38: .4byte 0x00007FFF
_0808AC3C:
	ldr r0, _0808AC50 @ =0x00000A22
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0808AC2A
	ldr r2, _0808AC54 @ =0x00007FFF
	subs r0, #1
	strh r0, [r1]
	b _0808AC7C
	.align 2, 0
_0808AC50: .4byte 0x00000A22
_0808AC54: .4byte 0x00007FFF
_0808AC58:
	ldr r4, _0808AC6C @ =0x000039CE
	ldr r5, _0808AC70 @ =0x00000A22
	adds r1, r3, r5
	ldrh r0, [r1]
	cmp r0, #0
	beq _0808AC78
	ldr r2, _0808AC74 @ =0x00007FFF
	subs r0, #1
	strh r0, [r1]
	b _0808AC7A
	.align 2, 0
_0808AC6C: .4byte 0x000039CE
_0808AC70: .4byte 0x00000A22
_0808AC74: .4byte 0x00007FFF
_0808AC78:
	movs r2, #0x1f
_0808AC7A:
	ldr r5, _0808ACAC @ =0x030046A0
_0808AC7C:
	ldr r1, _0808ACB0 @ =0x0300440C
	ldrh r0, [r1]
	cmp r0, r4
	beq _0808AC86
	strh r4, [r1]
_0808AC86:
	subs r1, #2
	ldrh r0, [r1]
	cmp r0, r2
	beq _0808AC90
	strh r2, [r1]
_0808AC90:
	ldr r4, [r5]
	movs r0, #0xae
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r1, [r2]
	ldr r5, _0808ACB4 @ =0x00000A1E
	adds r0, r3, r5
	strh r1, [r0]
	ldr r3, [r2]
	cmp r3, #0
	bgt _0808ACB8
	movs r5, #0
	b _0808ACDC
	.align 2, 0
_0808ACAC: .4byte 0x030046A0
_0808ACB0: .4byte 0x0300440C
_0808ACB4: .4byte 0x00000A1E
_0808ACB8:
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #1
	ble _0808ACDA
	movs r1, #0x4f
	subs r0, r3, #1
	muls r0, r1, r0
	subs r1, r2, #1
	bl Div
	adds r4, r0, #1
	asrs r5, r4, #3
	lsls r0, r5, #3
	subs r4, r4, r0
	b _0808ACDE
_0808ACDA:
	movs r5, #0xa
_0808ACDC:
	movs r4, #0
_0808ACDE:
	movs r0, #0
	movs r1, #0x1d
	movs r2, #1
	bl FUN_0808a420
	adds r2, r0, #0
	ldr r1, _0808AD4C @ =0x0000D08C
	adds r0, r1, #0
	strh r0, [r2]
	subs r2, #2
	subs r1, #1
	adds r0, r1, #0
	strh r0, [r2]
	subs r2, #2
	subs r1, #1
	adds r0, r1, #0
	strh r0, [r2]
	subs r2, #2
	movs r3, #0
	cmp r3, r5
	bge _0808AD1A
	subs r1, #1
	adds r0, r1, #0
	adds r3, r5, #0
_0808AD0E:
	strh r0, [r2]
	subs r2, #2
	subs r3, #1
	cmp r3, #0
	bne _0808AD0E
	adds r3, r5, #0
_0808AD1A:
	cmp r4, #0
	beq _0808AD2E
	adds r0, r4, #0
	adds r0, #0x81
	ldr r4, _0808AD50 @ =0xFFFFD000
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	subs r2, #2
	adds r3, #1
_0808AD2E:
	cmp r3, #9
	bgt _0808AD40
	ldr r5, _0808AD54 @ =0x0000D081
	adds r0, r5, #0
_0808AD36:
	strh r0, [r2]
	subs r2, #2
	adds r3, #1
	cmp r3, #9
	ble _0808AD36
_0808AD40:
	ldr r1, _0808AD58 @ =0x0000D080
	adds r0, r1, #0
	strh r0, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808AD4C: .4byte 0x0000D08C
_0808AD50: .4byte 0xFFFFD000
_0808AD54: .4byte 0x0000D081
_0808AD58: .4byte 0x0000D080

	thumb_func_start FUN_0808ad5c
FUN_0808ad5c: @ 0x0808AD5C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	movs r2, #0
	movs r7, #0
	movs r5, #0
	mov sb, r5
	mov r8, r5
	mov sl, r5
	movs r6, #0
	ldr r1, _0808AD98 @ =0x00000A0A
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0808AE24
	ldr r2, _0808AD9C @ =0x000039CE
	mov sl, r2
	ldr r0, _0808ADA0 @ =0x00000A0D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0808ADA8
	ldr r2, _0808ADA4 @ =0x00007FFF
	mov r8, r2
	subs r0, #1
	strb r0, [r1]
	b _0808ADAC
	.align 2, 0
_0808AD98: .4byte 0x00000A0A
_0808AD9C: .4byte 0x000039CE
_0808ADA0: .4byte 0x00000A0D
_0808ADA4: .4byte 0x00007FFF
_0808ADA8:
	movs r0, #0x1f
	mov r8, r0
_0808ADAC:
	ldr r1, _0808ADC8 @ =0x00000A0C
	adds r0, r4, r1
	ldrb r0, [r0]
	mov sb, r0
	lsls r5, r0, #3
	ldr r0, _0808ADCC @ =0x00000A06
	adds r2, r4, r0
	ldrh r0, [r2]
	cmp r0, #0
	bne _0808ADD0
	movs r7, #0
	movs r5, #0
	b _0808ADEC
	.align 2, 0
_0808ADC8: .4byte 0x00000A0C
_0808ADCC: .4byte 0x00000A06
_0808ADD0:
	subs r1, r5, #1
	ldrh r0, [r2]
	subs r0, #1
	muls r0, r1, r0
	ldr r2, _0808AE14 @ =0x00000A08
	adds r1, r4, r2
	ldrh r1, [r1]
	subs r1, #1
	bl Div
	adds r5, r0, #1
	asrs r7, r5, #3
	lsls r0, r7, #3
	subs r5, r5, r0
_0808ADEC:
	movs r6, #0x8c
	ldr r0, _0808AE18 @ =0x00000A0A
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	ldr r2, _0808AE1C @ =0x00000A15
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	movs r2, #1
	ldr r0, _0808AE20 @ =0x00000A12
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0808AEA8
	subs r0, #1
	strh r0, [r1]
	b _0808AEA8
	.align 2, 0
_0808AE14: .4byte 0x00000A08
_0808AE18: .4byte 0x00000A0A
_0808AE1C: .4byte 0x00000A15
_0808AE20: .4byte 0x00000A12
_0808AE24:
	ldr r1, _0808AE48 @ =0x00000A12
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0808AEA8
	movs r2, #0x1f
	mov sl, r2
	ldr r0, _0808AE4C @ =0x00000A14
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0808AE54
	ldr r2, _0808AE50 @ =0x00007FFF
	mov r8, r2
	subs r0, #1
	strb r0, [r1]
	b _0808AE5A
	.align 2, 0
_0808AE48: .4byte 0x00000A12
_0808AE4C: .4byte 0x00000A14
_0808AE50: .4byte 0x00007FFF
_0808AE54:
	movs r0, #0xf8
	lsls r0, r0, #2
	mov r8, r0
_0808AE5A:
	movs r1, #0xa
	mov sb, r1
	ldr r0, _0808AE70 @ =0x00000A0E
	adds r2, r4, r0
	ldrh r0, [r2]
	cmp r0, #0
	bne _0808AE74
	movs r7, #0
	movs r5, #0
	b _0808AE92
	.align 2, 0
_0808AE70: .4byte 0x00000A0E
_0808AE74:
	movs r1, #0x4f
	ldrh r0, [r2]
	subs r0, #1
	muls r0, r1, r0
	movs r2, #0xa1
	lsls r2, r2, #4
	adds r1, r4, r2
	ldrh r1, [r1]
	subs r1, #1
	bl Div
	adds r5, r0, #1
	asrs r7, r5, #3
	lsls r0, r7, #3
	subs r5, r5, r0
_0808AE92:
	movs r6, #0x42
	ldr r0, _0808AF4C @ =0x00000A15
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _0808AF50 @ =0x00000A12
	adds r1, r4, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	movs r2, #1
_0808AEA8:
	cmp r2, #0
	beq _0808AF68
	ldr r1, _0808AF54 @ =0x0300440C
	ldrh r0, [r1]
	cmp r0, sl
	beq _0808AEB8
	mov r4, sl
	strh r4, [r1]
_0808AEB8:
	subs r1, #2
	ldrh r0, [r1]
	cmp r0, r8
	beq _0808AEC4
	mov r0, r8
	strh r0, [r1]
_0808AEC4:
	movs r0, #0
	movs r1, #0x1d
	movs r2, #1
	bl FUN_0808a420
	adds r2, r0, #0
	ldr r4, _0808AF58 @ =0xFFFFD000
	adds r1, r4, #0
	movs r3, #2
_0808AED6:
	adds r0, r6, #0
	orrs r0, r1
	strh r0, [r2]
	subs r2, #2
	subs r6, #1
	subs r3, #1
	cmp r3, #0
	bge _0808AED6
	movs r3, #0
	cmp r3, r7
	bge _0808AEFE
	ldr r1, _0808AF5C @ =0x0000D089
	adds r0, r1, #0
	adds r3, r7, #0
_0808AEF2:
	strh r0, [r2]
	subs r2, #2
	subs r3, #1
	cmp r3, #0
	bne _0808AEF2
	adds r3, r7, #0
_0808AEFE:
	cmp r5, #0
	beq _0808AF12
	adds r0, r5, #0
	adds r0, #0x81
	ldr r4, _0808AF58 @ =0xFFFFD000
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	subs r2, #2
	adds r3, #1
_0808AF12:
	cmp r3, sb
	bge _0808AF2A
	ldr r1, _0808AF60 @ =0x0000D081
	adds r0, r1, #0
	mov r4, sb
	subs r3, r4, r3
_0808AF1E:
	strh r0, [r2]
	subs r2, #2
	subs r3, #1
	cmp r3, #0
	bne _0808AF1E
	mov r3, sb
_0808AF2A:
	ldr r1, _0808AF64 @ =0x0000D080
	adds r0, r1, #0
	strh r0, [r2]
	subs r2, #2
	adds r3, #1
	cmp r3, #0xa
	bgt _0808AF98
	movs r4, #0xd0
	lsls r4, r4, #8
	adds r0, r4, #0
_0808AF3E:
	strh r0, [r2]
	subs r2, #2
	adds r3, #1
	cmp r3, #0xa
	ble _0808AF3E
	b _0808AF98
	.align 2, 0
_0808AF4C: .4byte 0x00000A15
_0808AF50: .4byte 0x00000A12
_0808AF54: .4byte 0x0300440C
_0808AF58: .4byte 0xFFFFD000
_0808AF5C: .4byte 0x0000D089
_0808AF60: .4byte 0x0000D081
_0808AF64: .4byte 0x0000D080
_0808AF68:
	ldr r1, _0808AFA8 @ =0x00000A15
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808AF98
	movs r0, #0
	movs r1, #0x1d
	movs r2, #1
	bl FUN_0808a420
	adds r2, r0, #0
	movs r1, #0xd0
	lsls r1, r1, #8
	adds r0, r1, #0
	movs r3, #0xd
_0808AF86:
	strh r0, [r2]
	subs r2, #2
	subs r3, #1
	cmp r3, #0
	bge _0808AF86
	ldr r2, _0808AFA8 @ =0x00000A15
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_0808AF98:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808AFA8: .4byte 0x00000A15

	thumb_func_start FUN_0808afac
FUN_0808afac: @ 0x0808AFAC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #0x9e
	lsls r0, r0, #4
	adds r4, r7, r0
	ldr r0, [r4]
	ldr r1, _0808B038 @ =0x00000446
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0808B04C
	ldr r3, _0808B03C @ =0x00000A3C
	adds r2, r7, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808B040 @ =0x00000A34
	adds r0, r7, r1
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r2, [r4]
	ldr r3, _0808B044 @ =0x00000444
	adds r2, r2, r3
	ldrh r2, [r2]
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl FUN_0822f3cc
	movs r0, #0
	movs r1, #1
	movs r2, #5
	bl FUN_0808a420
	adds r6, r0, #0
	ldr r0, [r4]
	ldr r1, _0808B038 @ =0x00000446
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, #0x3b
	movs r1, #0x3c
	bl Div
	adds r4, r0, #0
	movs r1, #0xa
	bl Div
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	movs r1, #0
	bl FUN_0808a440
	ldr r2, _0808B048 @ =0xFFFFD000
	adds r5, r2, #0
	orrs r0, r5
	strh r0, [r6]
	adds r6, #2
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808a440
	orrs r0, r5
	strh r0, [r6]
	b _0808B0C4
	.align 2, 0
_0808B038: .4byte 0x00000446
_0808B03C: .4byte 0x00000A3C
_0808B040: .4byte 0x00000A34
_0808B044: .4byte 0x00000444
_0808B048: .4byte 0xFFFFD000
_0808B04C:
	ldr r0, _0808B078 @ =0x030046A0
	ldr r1, [r0]
	movs r2, #0xac
	lsls r2, r2, #2
	adds r0, r1, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	beq _0808B084
	ldr r0, _0808B07C @ =0x00000A3C
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808B080 @ =0x00000A34
	adds r0, r7, r1
	adds r1, r7, #0
	adds r1, #0xa0
	movs r2, #0x83
	b _0808B0A8
	.align 2, 0
_0808B078: .4byte 0x030046A0
_0808B07C: .4byte 0x00000A3C
_0808B080: .4byte 0x00000A34
_0808B084:
	ldr r2, _0808B0D0 @ =0x000002B2
	adds r0, r1, r2
	movs r3, #0
	ldrsh r5, [r0, r3]
	cmp r5, #0
	beq _0808B0E0
	ldr r0, _0808B0D4 @ =0x00000A3C
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808B0D8 @ =0x00000A34
	adds r0, r7, r1
	adds r1, r7, #0
	adds r1, #0xa0
	movs r2, #0x84
_0808B0A8:
	movs r3, #1
	bl FUN_0822f3cc
	movs r0, #0
	movs r1, #1
	movs r2, #5
	bl FUN_0808a420
	adds r6, r0, #0
	movs r2, #0xd0
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r6]
	strh r0, [r6, #2]
_0808B0C4:
	ldr r3, _0808B0DC @ =0x00000A94
	adds r1, r7, r3
	movs r0, #1
	strb r0, [r1]
	b _0808B10C
	.align 2, 0
_0808B0D0: .4byte 0x000002B2
_0808B0D4: .4byte 0x00000A3C
_0808B0D8: .4byte 0x00000A34
_0808B0DC: .4byte 0x00000A94
_0808B0E0:
	ldr r0, _0808B114 @ =0x00000A94
	adds r4, r7, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0808B10C
	ldr r1, _0808B118 @ =0x00000A3C
	adds r2, r7, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	movs r2, #5
	bl FUN_0808a420
	adds r6, r0, #0
	movs r2, #0xd0
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r6]
	strh r0, [r6, #2]
	strb r5, [r4]
_0808B10C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808B114: .4byte 0x00000A94
_0808B118: .4byte 0x00000A3C

	thumb_func_start FUN_0808b11c
FUN_0808b11c: @ 0x0808B11C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	ldr r0, _0808B150 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _0808B158
	cmp r6, #0
	bne _0808B1A2
	subs r0, r5, #1
	cmp r0, #2
	bhi _0808B1A2
	ldr r1, _0808B154 @ =0x00000A9B
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r5, r0
	beq _0808B1A2
	movs r0, #0x87
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _0808B1A2
	.align 2, 0
_0808B150: .4byte 0x030047A4
_0808B154: .4byte 0x00000A9B
_0808B158:
	ldr r0, _0808B17C @ =0x00000A98
	adds r7, r4, r0
	ldrb r0, [r7]
	cmp r0, #0
	bne _0808B184
	ldr r1, _0808B180 @ =0x00000A99
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808B174
	movs r0, #0x87
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0808B174:
	movs r0, #1
	strb r0, [r7]
	b _0808B1A2
	.align 2, 0
_0808B17C: .4byte 0x00000A98
_0808B180: .4byte 0x00000A99
_0808B184:
	cmp r6, #0
	beq _0808B190
	cmp r6, #1
	bne _0808B1A2
	cmp r5, #0
	bne _0808B1A2
_0808B190:
	ldr r1, _0808B1B4 @ =0x00000A9B
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r5, r0
	beq _0808B1A2
	movs r0, #0x87
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0808B1A2:
	ldr r1, _0808B1B8 @ =0x00000A9A
	adds r0, r4, r1
	strb r6, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r5, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808B1B4: .4byte 0x00000A9B
_0808B1B8: .4byte 0x00000A9A

	thumb_func_start FUN_0808b1bc
FUN_0808b1bc: @ 0x0808B1BC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r1, _0808B1FC @ =0x00000A97
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808B1CC
	b _0808B2F2
_0808B1CC:
	subs r1, #0xb7
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0808B1E2
	movs r1, #4
	ldr r0, _0808B200 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0808B208
_0808B1E2:
	movs r3, #1
	ldr r0, _0808B204 @ =0x00000AA8
	adds r1, r5, r0
	movs r2, #1
_0808B1EA:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0808B1EA
	ldr r0, _0808B1FC @ =0x00000A97
	b _0808B22E
	.align 2, 0
_0808B1FC: .4byte 0x00000A97
_0808B200: .4byte 0x03002BC0
_0808B204: .4byte 0x00000AA8
_0808B208:
	ldr r1, _0808B238 @ =0x00000A9C
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r4, [r0]
	ldr r0, _0808B23C @ =0x00001734
	cmp r4, r0
	ble _0808B248
	movs r3, #1
	ldr r0, _0808B240 @ =0x00000AA8
	adds r1, r5, r0
	movs r2, #1
_0808B21E:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0808B21E
	ldr r0, _0808B244 @ =0x00000A98
_0808B22E:
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	b _0808B2F2
	.align 2, 0
_0808B238: .4byte 0x00000A9C
_0808B23C: .4byte 0x00001734
_0808B240: .4byte 0x00000AA8
_0808B244: .4byte 0x00000A98
_0808B248:
	adds r7, r5, #0
	adds r7, #0x60
	movs r3, #2
	rsbs r3, r3, #0
	ldr r0, _0808B288 @ =0x00000AA8
	adds r1, r5, r0
	movs r2, #1
_0808B256:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0808B256
	cmp r4, #0
	ble _0808B28C
	subs r0, r4, #1
	movs r1, #0x3c
	bl Div
	adds r4, r0, #1
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	adds r6, r0, #0
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #1
	subs r4, r4, r0
	b _0808B290
	.align 2, 0
_0808B288: .4byte 0x00000AA8
_0808B28C:
	movs r6, #0
	movs r4, #0
_0808B290:
	cmp r6, #0
	bne _0808B2BC
	movs r1, #0xaa
	lsls r1, r1, #4
	adds r0, r5, r1
	adds r1, r7, #0
	movs r2, #0x7d
	movs r3, #1
	bl FUN_0822f3cc
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r0, r5, r1
	adds r2, r4, #0
	adds r2, #0x7d
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r7, #0
	movs r3, #1
	bl FUN_0822f3cc
	b _0808B2E8
_0808B2BC:
	movs r1, #0xaa
	lsls r1, r1, #4
	adds r0, r5, r1
	adds r2, r6, #0
	adds r2, #0x73
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r7, #0
	movs r3, #1
	bl FUN_0822f3cc
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r0, r5, r1
	adds r2, r4, #0
	adds r2, #0x73
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r7, #0
	movs r3, #1
	bl FUN_0822f3cc
_0808B2E8:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0808b11c
_0808B2F2:
	ldr r0, _0808B308 @ =0x00000A99
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0808B300
	subs r0, #1
	strb r0, [r1]
_0808B300:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808B308: .4byte 0x00000A99

	thumb_func_start FUN_0808b30c
FUN_0808b30c: @ 0x0808B30C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	ldr r0, [sp, #0x14]
	movs r7, #0x31
	cmp r0, #0
	bne _0808B320
	movs r7, #0x91
_0808B320:
	movs r0, #0
	bl FUN_0808a420
	adds r6, r0, #0
	cmp r4, #0
	ble _0808B358
_0808B32C:
	adds r0, r5, #0
	adds r1, r4, #0
	bl Div
	adds r1, r0, r7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r3, #0xf0
	lsls r3, r3, #8
	adds r2, r3, #0
	orrs r1, r2
	strh r1, [r6]
	adds r6, #2
	muls r0, r4, r0
	subs r5, r5, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	adds r4, r0, #0
	cmp r4, #0
	bgt _0808B32C
_0808B358:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808b360
FUN_0808b360: @ 0x0808B360
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	bl FUN_0808a420
	adds r1, r0, #0
	cmp r4, #0
	ble _0808B380
	ldr r0, _0808B388 @ =0x0000F090
	adds r2, r0, #0
	adds r0, r4, #0
_0808B376:
	strh r2, [r1]
	adds r1, #2
	subs r0, #1
	cmp r0, #0
	bne _0808B376
_0808B380:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808B388: .4byte 0x0000F090

	thumb_func_start FUN_0808b38c
FUN_0808b38c: @ 0x0808B38C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0x12
	movs r2, #1
	bl FUN_0808a420
	adds r1, r0, #0
	ldr r0, _0808B3EC @ =0x00003AE6
	adds r4, r4, r0
	ldrb r4, [r4]
	cmp r4, #0
	bne _0808B3FC
	ldr r2, _0808B3F0 @ =0x0000F023
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #2
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #0x77
	adds r0, r2, #0
	strh r0, [r1]
	subs r2, #0x9a
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r5, _0808B3F4 @ =0x030046A0
	ldr r0, [r5]
	movs r3, #0x91
	lsls r3, r3, #4
	adds r2, r0, r3
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldr r1, _0808B3F8 @ =0x0000270F
	cmp r0, r1
	ble _0808B3E2
	strh r1, [r2]
_0808B3E2:
	ldr r0, [r5]
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	b _0808B43E
	.align 2, 0
_0808B3EC: .4byte 0x00003AE6
_0808B3F0: .4byte 0x0000F023
_0808B3F4: .4byte 0x030046A0
_0808B3F8: .4byte 0x0000270F
_0808B3FC:
	cmp r4, #1
	bne _0808B45C
	ldr r2, _0808B450 @ =0x0000F025
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	subs r2, #4
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #0x79
	adds r0, r2, #0
	strh r0, [r1]
	subs r2, #0x6b
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r5, _0808B454 @ =0x030046A0
	ldr r0, [r5]
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r1, r0, r3
	ldr r0, [r1]
	ldr r2, _0808B458 @ =0x0000270F
	cmp r0, r2
	ble _0808B438
	str r2, [r1]
_0808B438:
	ldr r0, [r5]
	adds r0, r0, r3
	ldr r0, [r0]
_0808B43E:
	movs r1, #0xfa
	lsls r1, r1, #2
	str r4, [sp]
	movs r2, #0x17
	movs r3, #1
	bl FUN_0808b30c
	b _0808B4AA
	.align 2, 0
_0808B450: .4byte 0x0000F025
_0808B454: .4byte 0x030046A0
_0808B458: .4byte 0x0000270F
_0808B45C:
	ldr r2, _0808B4B4 @ =0x0000F0B9
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	subs r2, #0x98
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #0x99
	adds r0, r2, #0
	strh r0, [r1]
	subs r2, #0x20
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r4, _0808B4B8 @ =0x030046A0
	ldr r0, [r4]
	movs r3, #0xef
	lsls r3, r3, #2
	adds r1, r0, r3
	ldr r0, [r1]
	ldr r2, _0808B4BC @ =0x0000270F
	cmp r0, r2
	ble _0808B494
	str r2, [r1]
_0808B494:
	ldr r0, [r4]
	adds r0, r0, r3
	ldr r0, [r0]
	movs r1, #0xfa
	lsls r1, r1, #2
	movs r2, #0
	str r2, [sp]
	movs r2, #0x17
	movs r3, #1
	bl FUN_0808b30c
_0808B4AA:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808B4B4: .4byte 0x0000F0B9
_0808B4B8: .4byte 0x030046A0
_0808B4BC: .4byte 0x0000270F

	thumb_func_start FUN_0808b4c0
FUN_0808b4c0: @ 0x0808B4C0
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, _0808B564 @ =0x00000F56
	adds r0, r4, r1
	ldrb r1, [r0]
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _0808B4DC
	cmp r1, #6
	beq _0808B4DC
	b _0808B5F4
_0808B4DC:
	ldr r2, _0808B568 @ =0x000009F8
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808B524
	ldr r2, _0808B56C @ =0x030044E0
	ldrh r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0808B524
	ldrh r1, [r2, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808B524
	ldr r0, _0808B570 @ =0x00003AE6
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0808B512
	strb r2, [r1]
_0808B512:
	ldr r1, _0808B574 @ =0x00003AE7
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0xdc
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_0808b38c
_0808B524:
	movs r0, #0
	movs r1, #0x12
	movs r2, #0
	bl FUN_0808a420
	adds r1, r0, #0
	ldr r2, _0808B570 @ =0x00003AE6
	adds r0, r4, r2
	ldrb r4, [r0]
	cmp r4, #0
	bne _0808B57C
	ldr r2, _0808B578 @ =0x0000F020
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1, #2]
	bl GetHour
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x16
	movs r3, #0
	bl FUN_0808b30c
	bl GetMinute
	b _0808B5A8
	.align 2, 0
_0808B564: .4byte 0x00000F56
_0808B568: .4byte 0x000009F8
_0808B56C: .4byte 0x030044E0
_0808B570: .4byte 0x00003AE6
_0808B574: .4byte 0x00003AE7
_0808B578: .4byte 0x0000F020
_0808B57C:
	cmp r4, #1
	bne _0808B5C0
	ldr r2, _0808B5B8 @ =0x0000F027
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r5, _0808B5BC @ =0x030047E0
	ldrb r0, [r5, #0xa]
	movs r4, #0
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x16
	movs r3, #0
	bl FUN_0808b30c
	ldrb r0, [r5, #0xb]
_0808B5A8:
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x19
	movs r3, #0
	bl FUN_0808b30c
	b _0808B5F4
	.align 2, 0
_0808B5B8: .4byte 0x0000F027
_0808B5BC: .4byte 0x030047E0
_0808B5C0:
	ldr r2, _0808B5FC @ =0x0000F027
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #2
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r5, _0808B600 @ =0x030047E0
	ldrb r0, [r5, #0xc]
	movs r4, #0
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x16
	movs r3, #0
	bl FUN_0808b30c
	ldrb r0, [r5, #0xd]
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x19
	movs r3, #0
	bl FUN_0808b30c
_0808B5F4:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808B5FC: .4byte 0x0000F027
_0808B600: .4byte 0x030047E0

	thumb_func_start FUN_0808b604
FUN_0808b604: @ 0x0808B604
	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	movs r1, #1
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_0808a610
	adds r3, r6, #1
	adds r0, r5, #0
	movs r1, #1
	adds r2, r4, #0
	bl FUN_0808a768
	ldr r5, _0808B66C @ =0x030046A0
	ldr r0, [r5]
	adds r0, #0x58
	movs r1, #0
	ldrsh r0, [r0, r1]
	add r1, sp, #4
	bl FUN_08242b28
	add r0, sp, #4
	bl FUN_0807a6cc
	adds r4, #1
	adds r3, r6, #2
	movs r7, #0
	str r7, [sp]
	movs r1, #0x64
	adds r2, r4, #0
	bl FUN_0808b30c
	ldr r5, [r5]
	adds r1, r5, #0
	adds r1, #0x5c
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _0808B670
	movs r0, #0
	bl FUN_0807a70c
	adds r3, r6, #3
	str r7, [sp]
	movs r1, #0x64
	adds r2, r4, #0
	bl FUN_0808b30c
	b _0808B698
	.align 2, 0
_0808B66C: .4byte 0x030046A0
_0808B670:
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #3
	ldr r1, _0808B6A0 @ =0x08DAA7B0
	adds r0, r0, r1
	bl FUN_0807a70c
	adds r3, r6, #3
	str r7, [sp]
	movs r1, #0x64
	adds r2, r4, #0
	bl FUN_0808b30c
_0808B698:
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808B6A0: .4byte 0x08DAA7B0

	thumb_func_start FUN_0808b6a4
FUN_0808b6a4: @ 0x0808B6A4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _0808B6C4 @ =0x030044E0
	ldrh r0, [r5, #2]
	movs r3, #0xf0
	adds r2, r3, #0
	ands r2, r0
	cmp r2, #0
	beq _0808B6CC
	ldr r1, _0808B6C8 @ =0x00003B24
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldrh r0, [r5, #2]
	b _0808B6F6
	.align 2, 0
_0808B6C4: .4byte 0x030044E0
_0808B6C8: .4byte 0x00003B24
_0808B6CC:
	ldrh r1, [r5]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0808B6F4
	ldr r0, _0808B6F0 @ =0x00003B24
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bls _0808B6F4
	strb r2, [r1]
	ldrh r0, [r5]
	b _0808B6F6
	.align 2, 0
_0808B6F0: .4byte 0x00003B24
_0808B6F4:
	movs r0, #0
_0808B6F6:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808b6fc
FUN_0808b6fc: @ 0x0808B6FC
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _0808B750 @ =0x0000150C
	adds r3, r5, r0
	ldr r0, [r3]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r3]
	ldr r2, _0808B754 @ =0x00001524
	adds r0, r5, r2
	movs r3, #0
	strh r3, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r3, [r0]
	ldr r2, _0808B758 @ =0x00003B25
	adds r0, r5, r2
	strb r1, [r0]
	lsls r1, r1, #0x18
	movs r2, #5
	cmp r1, #0
	beq _0808B72E
	movs r2, #4
_0808B72E:
	ldr r0, _0808B75C @ =0x00001504
	adds r4, r5, r0
	adds r5, #0x60
	str r3, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl FUN_082370cc
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_082372cc
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808B750: .4byte 0x0000150C
_0808B754: .4byte 0x00001524
_0808B758: .4byte 0x00003B25
_0808B75C: .4byte 0x00001504

	thumb_func_start FUN_0808b760
FUN_0808b760: @ 0x0808B760
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _0808B788 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0808B794
	ldr r0, _0808B78C @ =0x0000150C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _0808B790 @ =0x00003B25
	adds r0, r4, r1
	ldrb r0, [r0]
	b _0808B81C
	.align 2, 0
_0808B788: .4byte 0x030044E0
_0808B78C: .4byte 0x0000150C
_0808B790: .4byte 0x00003B25
_0808B794:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0808B7B0
	ldr r3, _0808B7AC @ =0x0000150C
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0
	b _0808B81C
	.align 2, 0
_0808B7AC: .4byte 0x0000150C
_0808B7B0:
	movs r2, #0
	ldr r3, _0808B7CC @ =0x00003B25
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808B7D0
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	rsbs r0, r0, #0
	lsrs r2, r0, #0x1f
	b _0808B7DA
	.align 2, 0
_0808B7CC: .4byte 0x00003B25
_0808B7D0:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0808B7DA
	movs r2, #1
_0808B7DA:
	adds r5, r4, #0
	adds r5, #0x60
	cmp r2, #0
	beq _0808B80E
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r0, _0808B824 @ =0x00003B25
	adds r1, r4, r0
	ldrb r2, [r1]
	movs r0, #1
	subs r0, r0, r2
	movs r3, #0
	strb r0, [r1]
	ldr r2, _0808B828 @ =0x00001504
	adds r0, r4, r2
	ldrb r1, [r1]
	movs r2, #5
	subs r2, r2, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	adds r1, r5, #0
	movs r3, #1
	bl FUN_082370cc
_0808B80E:
	ldr r3, _0808B828 @ =0x00001504
	adds r0, r4, r3
	adds r1, r5, #0
	bl FUN_082372cc
	movs r0, #1
	rsbs r0, r0, #0
_0808B81C:
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0808B824: .4byte 0x00003B25
_0808B828: .4byte 0x00001504

	thumb_func_start FUN_0808b82c
FUN_0808b82c: @ 0x0808B82C
	push {r4, lr}
	adds r3, r0, #0
	movs r4, #1
	ldr r0, _0808B864 @ =0x00000F6C
	adds r1, r3, r0
	movs r2, #0x73
_0808B838:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0808B838
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r1, r3, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0808B868 @ =0x00000BB8
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808B864: .4byte 0x00000F6C
_0808B868: .4byte 0x00000BB8

	thumb_func_start FUN_0808b86c
FUN_0808b86c: @ 0x0808B86C
	push {r4, lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _0808B89C @ =0x00000F6C
	adds r4, r3, r0
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r1, _0808B8A0 @ =0x00000F64
	adds r0, r3, r1
	adds r3, #0x60
	adds r2, #0x29
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r3, #0
	movs r3, #1
	bl FUN_0822f3cc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808B89C: .4byte 0x00000F6C
_0808B8A0: .4byte 0x00000F64

	thumb_func_start FUN_0808b8a4
FUN_0808b8a4: @ 0x0808B8A4
	push {r4, r5, r6, lr}
	ldr r3, _0808B900 @ =0xFFFF0000
	adds r1, r3, #0
	ands r1, r4
	movs r2, #0x90
	orrs r1, r2
	ldr r2, _0808B904 @ =0x0000FFFF
	ands r1, r2
	movs r2, #0x80
	lsls r2, r2, #0xe
	adds r4, r1, #0
	orrs r4, r2
	ands r5, r3
	movs r6, #0
	movs r1, #0xcc
	lsls r1, r1, #3
	adds r3, r0, r1
_0808B8C6:
	ldr r0, _0808B908 @ =0x00000F84
	adds r2, r3, r0
	str r4, [r2]
	str r5, [r2, #4]
	movs r1, #3
	ands r1, r6
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	ldr r0, _0808B90C @ =0x00000F86
	adds r2, r3, r0
	asrs r1, r6, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	adds r3, #0x60
	adds r6, #1
	cmp r6, #0xf
	ble _0808B8C6
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808B900: .4byte 0xFFFF0000
_0808B904: .4byte 0x0000FFFF
_0808B908: .4byte 0x00000F84
_0808B90C: .4byte 0x00000F86

	thumb_func_start FUN_0808b910
FUN_0808b910: @ 0x0808B910
	push {r4, r5, r6, lr}
	ldr r3, _0808B96C @ =0xFFFF0000
	adds r1, r3, #0
	ands r1, r4
	movs r2, #0x40
	orrs r1, r2
	ldr r2, _0808B970 @ =0x0000FFFF
	ands r1, r2
	movs r2, #0x98
	lsls r2, r2, #0xf
	adds r4, r1, #0
	orrs r4, r2
	ands r5, r3
	movs r6, #0
	movs r1, #0xd8
	lsls r1, r1, #4
	adds r3, r0, r1
_0808B932:
	ldr r0, _0808B974 @ =0x00000F84
	adds r2, r3, r0
	str r4, [r2]
	str r5, [r2, #4]
	movs r1, #1
	ands r1, r6
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	ldr r0, _0808B978 @ =0x00000F86
	adds r2, r3, r0
	asrs r1, r6, #1
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	adds r3, #0x60
	adds r6, #1
	cmp r6, #3
	ble _0808B932
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808B96C: .4byte 0xFFFF0000
_0808B970: .4byte 0x0000FFFF
_0808B974: .4byte 0x00000F84
_0808B978: .4byte 0x00000F86

	thumb_func_start FUN_0808b97c
FUN_0808b97c: @ 0x0808B97C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r7, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	movs r4, #0
	cmp r4, r6
	bge _0808B9B6
_0808B990:
	adds r2, r7, r4
	movs r0, #0
	mov r1, r8
	bl FUN_0808a420
	adds r2, r4, #1
	cmp r5, #0
	ble _0808B9B0
	ldr r1, _0808B9C0 @ =0x0000F001
	adds r3, r1, #0
	adds r1, r5, #0
_0808B9A6:
	strh r3, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bne _0808B9A6
_0808B9B0:
	adds r4, r2, #0
	cmp r4, r6
	blt _0808B990
_0808B9B6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808B9C0: .4byte 0x0000F001

	thumb_func_start FUN_0808b9c4
FUN_0808b9c4: @ 0x0808B9C4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r7, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	movs r4, #0
	cmp r4, r6
	bge _0808B9FE
_0808B9D8:
	adds r2, r7, r4
	movs r0, #0
	mov r1, r8
	bl FUN_0808a420
	adds r2, r4, #1
	cmp r5, #0
	ble _0808B9F8
	ldr r1, _0808BA08 @ =0x0000F002
	adds r3, r1, #0
	adds r1, r5, #0
_0808B9EE:
	strh r3, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bne _0808B9EE
_0808B9F8:
	adds r4, r2, #0
	cmp r4, r6
	blt _0808B9D8
_0808B9FE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808BA08: .4byte 0x0000F002

	thumb_func_start FUN_0808ba0c
FUN_0808ba0c: @ 0x0808BA0C
	strh r1, [r0, #0x3a]
	ldr r1, _0808BA1C @ =0x03003584
	ldrh r2, [r0, #0x3a]
	lsls r2, r2, #5
	ldr r1, [r1]
	adds r1, r1, r2
	str r1, [r0, #0x48]
	bx lr
	.align 2, 0
_0808BA1C: .4byte 0x03003584

	thumb_func_start FUN_0808ba20
FUN_0808ba20: @ 0x0808BA20
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	mov r8, r1
	adds r4, r2, #0
	movs r1, #0
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	mov r2, r8
	movs r3, #0
	ldrsh r1, [r2, r3]
	adds r0, r0, r1
	adds r6, r4, #1
	adds r1, r6, #0
	bl Div
	strh r0, [r5]
	movs r1, #2
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	mov r2, r8
	movs r3, #2
	ldrsh r1, [r2, r3]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r5, #2]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808ba64
FUN_0808ba64: @ 0x0808BA64
	push {lr}
	adds r2, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r1, [r0]
	ldr r3, _0808BA80 @ =0x0000043E
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _0808BA84
	movs r1, #2
	b _0808BAA2
	.align 2, 0
_0808BA80: .4byte 0x0000043E
_0808BA84:
	ldr r3, _0808BAB8 @ =0x0000038E
	adds r0, r1, r3
	ldrb r0, [r0]
	ldr r1, _0808BABC @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	cmp r0, #0
	ble _0808BAA2
	movs r1, #6
_0808BAA2:
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r0, r2, r3
	ldr r0, [r0]
	lsls r1, r1, #1
	ldr r2, _0808BAC0 @ =0x00000938
	adds r0, r0, r2
	adds r0, r0, r1
	ldrh r0, [r0]
	pop {r1}
	bx r1
	.align 2, 0
_0808BAB8: .4byte 0x0000038E
_0808BABC: .4byte 0x030046A0
_0808BAC0: .4byte 0x00000938

	thumb_func_start FUN_0808bac4
FUN_0808bac4: @ 0x0808BAC4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	bl FUN_0808ba64
	ldr r1, _0808BB14 @ =0x03003584
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldr r0, _0808BB18 @ =0x000009B8
	adds r2, r7, r0
	movs r3, #0xf
_0808BADC:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _0808BADC
	ldr r2, _0808BB1C @ =0x000009DE
	adds r1, r7, r2
	movs r0, #0
	strb r0, [r1]
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r0, r7, r3
	ldr r0, [r0]
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #5
	bls _0808BB08
	b _0808C020
_0808BB08:
	lsls r0, r0, #2
	ldr r1, _0808BB20 @ =_0808BB24
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808BB14: .4byte 0x03003584
_0808BB18: .4byte 0x000009B8
_0808BB1C: .4byte 0x000009DE
_0808BB20: .4byte _0808BB24
_0808BB24: @ jump table
	.4byte _0808BB3C @ case 0
	.4byte _0808BB84 @ case 1
	.4byte _0808BC18 @ case 2
	.4byte _0808BD68 @ case 3
	.4byte _0808BE9C @ case 4
	.4byte _0808BBC8 @ case 5
_0808BB3C:
	ldr r0, _0808BB74 @ =0x000024CC
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xb6
	lsls r1, r1, #4
	adds r2, r7, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r2, _0808BB78 @ =0x0000250C
	adds r1, r7, r2
	ldr r3, _0808BB7C @ =0x000009B8
	adds r0, r7, r3
	str r0, [r1]
	ldr r4, _0808BB80 @ =0x000024C4
	adds r0, r7, r4
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r2, #0
	str r2, [sp]
	movs r2, #4
	b _0808BBFE
	.align 2, 0
_0808BB74: .4byte 0x000024CC
_0808BB78: .4byte 0x0000250C
_0808BB7C: .4byte 0x000009B8
_0808BB80: .4byte 0x000024C4
_0808BB84:
	ldr r3, _0808BBBC @ =0x000024CC
	adds r2, r7, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r4, #0xb6
	lsls r4, r4, #4
	adds r2, r7, r4
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r0, _0808BBC0 @ =0x0000250C
	adds r1, r7, r0
	ldr r2, _0808BBC4 @ =0x000009B8
	adds r0, r7, r2
	str r0, [r1]
	subs r3, #8
	adds r0, r7, r3
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r2, #0
	str r2, [sp]
	movs r2, #0xcb
	b _0808BBFE
	.align 2, 0
_0808BBBC: .4byte 0x000024CC
_0808BBC0: .4byte 0x0000250C
_0808BBC4: .4byte 0x000009B8
_0808BBC8:
	ldr r0, _0808BC08 @ =0x000024CC
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xb6
	lsls r1, r1, #4
	adds r2, r7, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r2, _0808BC0C @ =0x0000250C
	adds r1, r7, r2
	ldr r3, _0808BC10 @ =0x000009B8
	adds r0, r7, r3
	str r0, [r1]
	ldr r4, _0808BC14 @ =0x000024C4
	adds r0, r7, r4
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r7, r2
	adds r2, #0xa2
	movs r3, #0
	str r3, [sp]
_0808BBFE:
	movs r3, #1
	bl FUN_082370cc
	b _0808C020
	.align 2, 0
_0808BC08: .4byte 0x000024CC
_0808BC0C: .4byte 0x0000250C
_0808BC10: .4byte 0x000009B8
_0808BC14: .4byte 0x000024C4
_0808BC18:
	ldr r3, _0808BCA4 @ =0x00000B8C
	adds r4, r7, r3
	ldr r1, _0808BCA8 @ =0x0000DA6D
	adds r0, r4, #0
	bl FUN_0822b16c
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r5, r7, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0822a4fc
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	ldr r2, _0808BCAC @ =0x00000B7E
	adds r1, r7, r2
	movs r0, #0x60
	strh r0, [r1]
	ldr r3, _0808BCB0 @ =0x000024CC
	adds r1, r7, r3
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	ldr r0, _0808BCB4 @ =0x00000B98
	adds r1, r7, r0
	ldr r2, _0808BCB8 @ =0x000009B8
	adds r0, r7, r2
	str r0, [r1]
	ldr r3, _0808BCBC @ =0x00000BA8
	adds r6, r7, r3
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r1, [r0]
	str r4, [sp]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #1
	bl FUN_08237040
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r6, #4]
	adds r1, r4, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r4
	cmp r1, r0
	beq _0808BCC0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0808BCC8
	.align 2, 0
_0808BCA4: .4byte 0x00000B8C
_0808BCA8: .4byte 0x0000DA6D
_0808BCAC: .4byte 0x00000B7E
_0808BCB0: .4byte 0x000024CC
_0808BCB4: .4byte 0x00000B98
_0808BCB8: .4byte 0x000009B8
_0808BCBC: .4byte 0x00000BA8
_0808BCC0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0808BCC8:
	str r0, [r5]
	ldrb r0, [r6, #4]
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
	beq _0808BCEC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0808BCF4
_0808BCEC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0808BCF4:
	str r0, [r5]
	ldrh r0, [r6, #0xe]
	adds r0, #1
	strh r0, [r6, #0xe]
	ldr r3, _0808BD2C @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r4, [r6, #7]
	cmp r0, r4
	bhs _0808BD0C
	b _0808C020
_0808BD0C:
	movs r0, #0
	strh r0, [r6, #0xe]
	ldrb r1, [r6, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0808BD30
	ldrh r0, [r6, #8]
	cmp r0, #0
	bne _0808BD26
	ldrb r0, [r6, #5]
_0808BD26:
	subs r0, #1
	strh r0, [r6, #8]
	b _0808BD40
	.align 2, 0
_0808BD2C: .4byte 0x0000FFFF
_0808BD30:
	ldrh r0, [r6, #8]
	adds r0, #1
	strh r0, [r6, #8]
	ands r0, r2
	ldrb r2, [r6, #5]
	cmp r0, r2
	blo _0808BD40
	strh r1, [r6, #8]
_0808BD40:
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r6, #6]
	ldrb r1, [r6, #6]
	ldrh r0, [r6, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r6, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808BD62
	b _0808C020
_0808BD62:
	movs r0, #1
	strb r0, [r6, #7]
	b _0808C020
_0808BD68:
	ldr r3, _0808BDF4 @ =0x00000B8C
	adds r4, r7, r3
	ldr r1, _0808BDF8 @ =0x0000D495
	adds r0, r4, #0
	bl FUN_0822b16c
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r5, r7, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0822a4fc
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	ldr r2, _0808BDFC @ =0x00000B7E
	adds r1, r7, r2
	movs r2, #0
	movs r0, #0x70
	strh r0, [r1]
	ldr r3, _0808BE00 @ =0x000024CC
	adds r1, r7, r3
	ldr r0, [r1]
	movs r6, #1
	orrs r0, r6
	str r0, [r1]
	ldr r4, _0808BE04 @ =0x00000B98
	adds r1, r7, r4
	ldr r3, _0808BE08 @ =0x000009B8
	adds r0, r7, r3
	str r0, [r1]
	ldr r0, _0808BE0C @ =0x00000BA8
	adds r4, r7, r0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	movs r3, #0xd4
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r1, [r0]
	str r2, [sp]
	adds r0, r4, #0
	movs r3, #4
	bl FUN_08237040
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	adds r1, r6, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r6
	cmp r1, r0
	beq _0808BE10
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0808BE18
	.align 2, 0
_0808BDF4: .4byte 0x00000B8C
_0808BDF8: .4byte 0x0000D495
_0808BDFC: .4byte 0x00000B7E
_0808BE00: .4byte 0x000024CC
_0808BE04: .4byte 0x00000B98
_0808BE08: .4byte 0x000009B8
_0808BE0C: .4byte 0x00000BA8
_0808BE10:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0808BE18:
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
	beq _0808BE3C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0808BE44
_0808BE3C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0808BE44:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0808BE7C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	bhs _0808BE5C
	b _0808C020
_0808BE5C:
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0808BE80
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0808BE76
	ldrb r0, [r4, #5]
_0808BE76:
	subs r0, #1
	strh r0, [r4, #8]
	b _0808BE90
	.align 2, 0
_0808BE7C: .4byte 0x0000FFFF
_0808BE80:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0808BE90
	strh r1, [r4, #8]
_0808BE90:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	b _0808C006
_0808BE9C:
	ldr r3, _0808BF0C @ =0x00000B8C
	adds r5, r7, r3
	ldr r1, _0808BF10 @ =0x00002499
	adds r0, r5, #0
	bl FUN_0822b16c
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r4, r7, r0
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0822a4fc
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r2, _0808BF14 @ =0x00000B7E
	adds r1, r7, r2
	movs r3, #0
	movs r0, #0x60
	strh r0, [r1]
	ldr r4, _0808BF18 @ =0x000024CC
	adds r2, r7, r4
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r0, _0808BF1C @ =0x00000B98
	adds r1, r7, r0
	ldr r2, _0808BF20 @ =0x000009B8
	adds r0, r7, r2
	str r0, [r1]
	movs r4, #0x9e
	lsls r4, r4, #4
	adds r0, r7, r4
	ldr r1, [r0]
	ldr r0, _0808BF24 @ =0x00000387
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #5
	bne _0808BF2C
	ldr r4, _0808BF28 @ =0x00000BA8
	adds r0, r7, r4
	movs r4, #0xd5
	lsls r4, r4, #2
	adds r1, r1, r4
	ldr r1, [r1]
	ldrb r2, [r2]
	str r3, [sp]
	movs r3, #4
	bl FUN_08237040
	b _0808BF42
	.align 2, 0
_0808BF0C: .4byte 0x00000B8C
_0808BF10: .4byte 0x00002499
_0808BF14: .4byte 0x00000B7E
_0808BF18: .4byte 0x000024CC
_0808BF1C: .4byte 0x00000B98
_0808BF20: .4byte 0x000009B8
_0808BF24: .4byte 0x00000387
_0808BF28: .4byte 0x00000BA8
_0808BF2C:
	ldr r4, _0808BF78 @ =0x00000BA8
	adds r0, r7, r4
	movs r4, #0xd5
	lsls r4, r4, #2
	adds r1, r1, r4
	ldr r1, [r1]
	ldrb r2, [r2]
	str r3, [sp]
	movs r3, #0
	bl FUN_08237040
_0808BF42:
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r5, r7, r0
	ldr r1, _0808BF78 @ =0x00000BA8
	adds r4, r7, r1
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
	beq _0808BF7C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0808BF84
	.align 2, 0
_0808BF78: .4byte 0x00000BA8
_0808BF7C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0808BF84:
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
	beq _0808BFA8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0808BFB0
_0808BFA8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0808BFB0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0808BFE8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0808C020
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0808BFEC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0808BFE0
	ldrb r0, [r4, #5]
_0808BFE0:
	subs r0, #1
	strh r0, [r4, #8]
	b _0808BFFC
	.align 2, 0
_0808BFE8: .4byte 0x0000FFFF
_0808BFEC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0808BFFC
	strh r1, [r4, #8]
_0808BFFC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
_0808C006:
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
	bne _0808C020
	movs r0, #1
	strb r0, [r4, #7]
_0808C020:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808c028
FUN_0808c028: @ 0x0808C028
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r0, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #5
	bls _0808C042
	b _0808C15C
_0808C042:
	lsls r0, r0, #2
	ldr r1, _0808C04C @ =_0808C050
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808C04C: .4byte _0808C050
_0808C050: @ jump table
	.4byte _0808C068 @ case 0
	.4byte _0808C068 @ case 1
	.4byte _0808C07C @ case 2
	.4byte _0808C07C @ case 3
	.4byte _0808C07C @ case 4
	.4byte _0808C068 @ case 5
_0808C068:
	ldr r1, _0808C078 @ =0x000024C4
	adds r0, r2, r1
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r2, r3
	bl FUN_082372cc
	b _0808C15C
	.align 2, 0
_0808C078: .4byte 0x000024C4
_0808C07C:
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r5, r2, r0
	ldr r1, _0808C0B4 @ =0x00000BA8
	adds r4, r2, r1
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
	beq _0808C0B8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0808C0C0
	.align 2, 0
_0808C0B4: .4byte 0x00000BA8
_0808C0B8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0808C0C0:
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
	beq _0808C0E4
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0808C0EC
_0808C0E4:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0808C0EC:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0808C124 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0808C15C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0808C128
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0808C11C
	ldrb r0, [r4, #5]
_0808C11C:
	subs r0, #1
	strh r0, [r4, #8]
	b _0808C138
	.align 2, 0
_0808C124: .4byte 0x0000FFFF
_0808C128:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0808C138
	strh r1, [r4, #8]
_0808C138:
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
	bne _0808C15C
	movs r0, #1
	strb r0, [r4, #7]
_0808C15C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808c164
FUN_0808c164: @ 0x0808C164
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r3, #0
	ldr r0, _0808C1B0 @ =0x000009D8
	adds r3, r4, r0
	strh r1, [r3]
	ldr r1, _0808C1B4 @ =0x000009DA
	adds r0, r4, r1
	strh r2, [r0]
	ldr r1, _0808C1B8 @ =0x03003584
	ldrh r0, [r3]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldr r0, _0808C1BC @ =0x000009B8
	adds r2, r4, r0
	movs r3, #0xf
_0808C186:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _0808C186
	ldr r1, _0808C1C0 @ =0x000009DD
	adds r0, r4, r1
	movs r1, #0
	strb r5, [r0]
	ldr r2, _0808C1C4 @ =0x000009DC
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _0808C1C8 @ =0x000009DE
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808C1B0: .4byte 0x000009D8
_0808C1B4: .4byte 0x000009DA
_0808C1B8: .4byte 0x03003584
_0808C1BC: .4byte 0x000009B8
_0808C1C0: .4byte 0x000009DD
_0808C1C4: .4byte 0x000009DC
_0808C1C8: .4byte 0x000009DE

	thumb_func_start FUN_0808c1cc
FUN_0808c1cc: @ 0x0808C1CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sl, r0
	ldr r0, _0808C1E8 @ =0x000009DE
	add r0, sl
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808C1EC
	movs r0, #1
	b _0808C316
	.align 2, 0
_0808C1E8: .4byte 0x000009DE
_0808C1EC:
	ldr r1, _0808C244 @ =0x03003584
	ldr r0, _0808C248 @ =0x000009D8
	add r0, sl
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r0, r1, r0
	str r0, [sp]
	ldr r0, _0808C24C @ =0x000009DA
	add r0, sl
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r1, r1, r0
	mov sb, r1
	ldr r2, _0808C250 @ =0x000009DC
	add r2, sl
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldr r1, _0808C254 @ =0x000009DD
	add r1, sl
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r3, [r1]
	cmp r0, r3
	blo _0808C260
	ldr r1, _0808C258 @ =0x000009B8
	add r1, sl
	movs r7, #0xf
_0808C226:
	mov r2, sb
	ldrh r0, [r2]
	strh r0, [r1]
	movs r3, #2
	add sb, r3
	adds r1, #2
	subs r7, #1
	cmp r7, #0
	bge _0808C226
	ldr r1, _0808C25C @ =0x000009DE
	add r1, sl
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0808C316
	.align 2, 0
_0808C244: .4byte 0x03003584
_0808C248: .4byte 0x000009D8
_0808C24C: .4byte 0x000009DA
_0808C250: .4byte 0x000009DC
_0808C254: .4byte 0x000009DD
_0808C258: .4byte 0x000009B8
_0808C25C: .4byte 0x000009DE
_0808C260:
	ldrb r1, [r1]
	ldrb r0, [r2]
	subs r1, r1, r0
	str r1, [sp, #4]
	movs r7, #0
	ldr r0, _0808C328 @ =0x000009DC
	add r0, sl
	str r0, [sp, #8]
	ldr r1, _0808C32C @ =0x000009DD
	add r1, sl
	str r1, [sp, #0xc]
_0808C276:
	cmp r7, #5
	beq _0808C304
	cmp r7, #0xd
	beq _0808C304
	ldr r2, [sp]
	ldrh r5, [r2]
	movs r0, #0x1f
	ands r0, r5
	lsls r5, r5, #0x10
	lsrs r3, r5, #0x15
	movs r1, #0x1f
	ands r3, r1
	lsrs r5, r5, #0x1a
	ands r5, r1
	mov r2, sb
	ldrh r4, [r2]
	movs r2, #0x1f
	ands r2, r4
	lsls r4, r4, #0x10
	lsrs r6, r4, #0x15
	ands r6, r1
	lsrs r4, r4, #0x1a
	ands r4, r1
	ldr r1, [sp, #4]
	muls r0, r1, r0
	ldr r1, [sp, #8]
	ldrb r1, [r1]
	mov r8, r1
	mov r1, r8
	muls r1, r2, r1
	adds r0, r0, r1
	ldr r2, [sp, #0xc]
	ldrb r1, [r2]
	str r3, [sp, #0x10]
	bl Div
	mov r8, r0
	ldr r3, [sp, #0x10]
	ldr r1, [sp, #4]
	adds r0, r3, #0
	muls r0, r1, r0
	ldr r2, [sp, #8]
	ldrb r1, [r2]
	muls r1, r6, r1
	adds r0, r0, r1
	ldr r3, [sp, #0xc]
	ldrb r1, [r3]
	bl Div
	adds r6, r0, #0
	ldr r1, [sp, #4]
	adds r0, r5, #0
	muls r0, r1, r0
	ldr r2, [sp, #8]
	ldrb r1, [r2]
	muls r1, r4, r1
	adds r0, r0, r1
	ldr r3, [sp, #0xc]
	ldrb r1, [r3]
	bl Div
	lsls r1, r7, #1
	ldr r2, _0808C330 @ =0x000009B8
	add r2, sl
	adds r2, r2, r1
	lsls r0, r0, #0xa
	lsls r6, r6, #5
	orrs r0, r6
	mov r1, r8
	orrs r0, r1
	strh r0, [r2]
_0808C304:
	ldr r2, [sp]
	adds r2, #2
	str r2, [sp]
	movs r3, #2
	add sb, r3
	adds r7, #1
	cmp r7, #0xf
	ble _0808C276
	movs r0, #0
_0808C316:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0808C328: .4byte 0x000009DC
_0808C32C: .4byte 0x000009DD
_0808C330: .4byte 0x000009B8

	thumb_func_start FUN_0808c334
FUN_0808c334: @ 0x0808C334
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	adds r6, r1, #0
	mov r8, r2
	mov sb, r3
	ldr r3, [sp, #0x20]
	ldr r2, [sp, #0x24]
	ldr r4, [sp, #0x28]
	lsls r0, r6, #5
	ldr r1, _0808C3A4 @ =0x00003B28
	adds r0, r0, r1
	mov r7, sl
	adds r5, r7, r0
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r5]
	str r1, [r5, #4]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #8]
	str r1, [r5, #0xc]
	cmp r4, #0
	beq _0808C3DA
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r7, #0
	ldrsh r1, [r3, r7]
	subs r0, r0, r1
	movs r7, #2
	ldrsh r1, [r2, r7]
	movs r2, #2
	ldrsh r3, [r3, r2]
	subs r1, r1, r3
	bl FUN_0823785c
	adds r3, r0, #0
	adds r3, #0x40
	movs r1, #0xff
	ands r3, r1
	ldr r2, _0808C3A8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r4, r0
	cmp r0, #0
	blt _0808C3AC
	asrs r0, r0, #0xc
	b _0808C3B2
	.align 2, 0
_0808C3A4: .4byte 0x00003B28
_0808C3A8: .4byte 0x085B0A08
_0808C3AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808C3B2:
	strh r0, [r5, #0x10]
	ldr r0, _0808C3CC @ =0x085B0A08
	movs r1, #0xff
	ands r1, r3
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0808C3D0
	asrs r0, r0, #0xc
	b _0808C3D6
	.align 2, 0
_0808C3CC: .4byte 0x085B0A08
_0808C3D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808C3D6:
	strh r0, [r5, #0x12]
	b _0808C3DE
_0808C3DA:
	strh r4, [r5, #0x10]
	strh r4, [r5, #0x12]
_0808C3DE:
	lsls r4, r6, #1
	adds r4, r4, r6
	lsls r4, r4, #5
	ldr r7, _0808C430 @ =0x000020A4
	adds r4, r4, r7
	add r4, sl
	mov r1, sl
	adds r1, #0xa0
	mov r0, r8
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	movs r3, #1
	bl FUN_0822f3cc
	adds r0, r4, #0
	mov r1, sb
	bl FUN_0808ba0c
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r4, #0x20]
	str r1, [r4, #0x24]
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	movs r0, #0
	strh r0, [r5, #0x18]
	ldr r0, [sp, #0x2c]
	strh r0, [r5, #0x1a]
	movs r0, #1
	strb r0, [r5, #0x1c]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808C430: .4byte 0x000020A4

	thumb_func_start FUN_0808c434
FUN_0808c434: @ 0x0808C434
	push {r4, r5, r6, r7, lr}
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #5
	ldr r3, _0808C454 @ =0x000020A4
	adds r2, r2, r3
	adds r6, r0, r2
	lsls r1, r1, #5
	ldr r7, _0808C458 @ =0x00003B28
	adds r1, r1, r7
	adds r5, r0, r1
	ldrb r0, [r5, #0x1c]
	cmp r0, #0
	bne _0808C45C
	movs r0, #1
	b _0808C508
	.align 2, 0
_0808C454: .4byte 0x000020A4
_0808C458: .4byte 0x00003B28
_0808C45C:
	ldrh r0, [r5, #0x18]
	adds r0, #1
	strh r0, [r5, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r5, #0x1a]
	cmp r0, r1
	blo _0808C47C
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r6, #0x20]
	str r1, [r6, #0x24]
	movs r0, #0
	strb r0, [r5, #0x1c]
	movs r0, #1
	b _0808C508
_0808C47C:
	ldrh r1, [r5, #0x1a]
	ldrh r3, [r5, #0x18]
	subs r4, r1, r3
	movs r2, #0
	ldrsh r0, [r5, r2]
	muls r0, r4, r0
	movs r7, #8
	ldrsh r2, [r5, r7]
	muls r2, r3, r2
	adds r0, r0, r2
	bl Div
	strh r0, [r6, #0x20]
	movs r1, #2
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	movs r3, #0xa
	ldrsh r2, [r5, r3]
	ldrh r1, [r5, #0x18]
	muls r1, r2, r1
	adds r0, r0, r1
	ldrh r1, [r5, #0x1a]
	bl Div
	strh r0, [r6, #0x22]
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _0808C506
	ldr r4, _0808C4DC @ =0x085B0A08
	ldrh r0, [r5, #0x18]
	lsls r0, r0, #7
	ldrh r1, [r5, #0x1a]
	bl Div
	movs r1, #0xff
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r4
	movs r7, #0
	ldrsh r2, [r1, r7]
	movs r1, #0x10
	ldrsh r0, [r5, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _0808C4E0
	asrs r1, r0, #0xc
	b _0808C4E6
	.align 2, 0
_0808C4DC: .4byte 0x085B0A08
_0808C4E0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808C4E6:
	ldrh r0, [r6, #0x20]
	adds r0, r0, r1
	strh r0, [r6, #0x20]
	movs r3, #0x12
	ldrsh r0, [r5, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _0808C4FA
	asrs r1, r0, #0xc
	b _0808C500
_0808C4FA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808C500:
	ldrh r0, [r6, #0x22]
	adds r0, r0, r1
	strh r0, [r6, #0x22]
_0808C506:
	movs r0, #0
_0808C508:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808c510
FUN_0808c510: @ 0x0808C510
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r2, #0
	beq _0808C520
	ldr r0, _0808C544 @ =0x00000107
	bl PlaySound_082406e0
_0808C520:
	bl FUN_08049e5c
	adds r0, r4, #0
	bl FUN_080478f0
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	adds r0, r5, #0
	bl FUN_08047a28
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808C544: .4byte 0x00000107

	thumb_func_start FUN_0808c548
FUN_0808c548: @ 0x0808C548
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808C57C @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0808C5BC
	ldr r1, _0808C580 @ =0x00001BC4
	adds r0, r4, r1
	ldr r1, _0808C584 @ =0x000002DF
	bl FUN_0808ba0c
	ldr r1, _0808C588 @ =0x000009EE
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0x1d
	bhi _0808C590
	ldr r1, _0808C58C @ =0x00001C2C
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _0808C59A
	.align 2, 0
_0808C57C: .4byte 0x00003AE8
_0808C580: .4byte 0x00001BC4
_0808C584: .4byte 0x000002DF
_0808C588: .4byte 0x000009EE
_0808C58C: .4byte 0x00001C2C
_0808C590:
	ldr r1, _0808C5B4 @ =0x00001C2C
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_0808C59A:
	str r1, [r0]
	ldr r0, _0808C5B8 @ =0x000009EE
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _0808C5D4
	movs r0, #0
	strh r0, [r1]
	b _0808C5D4
	.align 2, 0
_0808C5B4: .4byte 0x00001C2C
_0808C5B8: .4byte 0x000009EE
_0808C5BC:
	ldr r1, _0808C5F0 @ =0x00001BC4
	adds r0, r4, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_0808ba0c
	ldr r0, _0808C5F4 @ =0x00001C2C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_0808C5D4:
	ldr r1, _0808C5F8 @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0808C604
	ldr r1, _0808C5FC @ =0x00001C84
	adds r0, r4, r1
	ldr r1, _0808C600 @ =0x000002DF
	bl FUN_0808ba0c
	b _0808C610
	.align 2, 0
_0808C5F0: .4byte 0x00001BC4
_0808C5F4: .4byte 0x00001C2C
_0808C5F8: .4byte 0x00003AE8
_0808C5FC: .4byte 0x00001C84
_0808C600: .4byte 0x000002DF
_0808C604:
	ldr r1, _0808C618 @ =0x00001C84
	adds r0, r4, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_0808ba0c
_0808C610:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808C618: .4byte 0x00001C84

	thumb_func_start FUN_0808c61c
FUN_0808c61c: @ 0x0808C61C
	push {r4, lr}
	ldr r4, _0808C640 @ =0x000025A4
	adds r3, r0, r4
	strh r1, [r3]
	adds r4, #2
	adds r3, r0, r4
	strh r2, [r3]
	adds r4, #0x5e
	adds r3, r0, r4
	strh r1, [r3]
	adds r2, #8
	ldr r1, _0808C644 @ =0x00002606
	adds r0, r0, r1
	strh r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808C640: .4byte 0x000025A4
_0808C644: .4byte 0x00002606

	thumb_func_start FUN_0808c648
FUN_0808c648: @ 0x0808C648
	push {lr}
	cmp r0, #0
	beq _0808C652
	adds r0, #0xa0
	b _0808C654
_0808C652:
	movs r0, #0x93
_0808C654:
	pop {r1}
	bx r1

	thumb_func_start FUN_0808c658
FUN_0808c658: @ 0x0808C658
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r3, r1, #0
	adds r7, r2, #0
	cmp r3, #0
	bge _0808C678
	ldr r1, _0808C674 @ =0x0000258C
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _0808C6A4
	.align 2, 0
_0808C674: .4byte 0x0000258C
_0808C678:
	ldr r0, _0808C6B8 @ =0x0000258C
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808C6BC @ =0x00002584
	adds r4, r6, r1
	adds r5, r6, #0
	adds r5, #0x60
	adds r0, r3, #0
	bl FUN_0808c648
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl FUN_0822f3cc
_0808C6A4:
	cmp r7, #0
	bge _0808C6C4
	ldr r1, _0808C6C0 @ =0x000025EC
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _0808C6F0
	.align 2, 0
_0808C6B8: .4byte 0x0000258C
_0808C6BC: .4byte 0x00002584
_0808C6C0: .4byte 0x000025EC
_0808C6C4:
	ldr r0, _0808C6F8 @ =0x000025EC
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808C6FC @ =0x000025E4
	adds r4, r6, r1
	adds r5, r6, #0
	adds r5, #0x60
	adds r0, r7, #0
	bl FUN_0808c648
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl FUN_0822f3cc
_0808C6F0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808C6F8: .4byte 0x000025EC
_0808C6FC: .4byte 0x000025E4

	thumb_func_start FUN_0808c700
FUN_0808c700: @ 0x0808C700
	push {lr}
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_0808c658
	pop {r0}
	bx r0

	thumb_func_start FUN_0808c710
FUN_0808c710: @ 0x0808C710
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x39
	ldrb r0, [r5]
	adds r2, r0, #1
	strb r2, [r5]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _0808C738
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r1, r4, #0
	adds r1, #0x38
	movs r0, #0
	strb r0, [r1]
	b _0808C766
_0808C738:
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x1b
	adds r2, #2
	adds r0, r4, #0
	bl FUN_0822dafc
	ldrh r0, [r4, #0x30]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r2, [r4, #0x32]
	ldrh r1, [r4, #0x1a]
	adds r0, r2, r1
	strh r0, [r4, #0x1a]
	ldrb r1, [r5]
	movs r0, #7
	ands r0, r1
	adds r1, r4, #0
	adds r1, #0x38
	cmp r0, #0
	bne _0808C766
	adds r0, r2, #1
	strh r0, [r4, #0x32]
_0808C766:
	ldrb r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0808C770:
	.byte 0x10, 0xB5, 0x02, 0x1C, 0x11, 0x1C, 0x39, 0x31, 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x00, 0x06
	.byte 0x00, 0x0E, 0x13, 0x28, 0x08, 0xD9, 0x10, 0x68, 0x01, 0x21, 0x08, 0x43, 0x10, 0x60, 0x11, 0x1C
	.byte 0x38, 0x31, 0x00, 0x20, 0x08, 0x70, 0x10, 0xE0, 0x10, 0x8E, 0x13, 0x8B, 0xC0, 0x18, 0x10, 0x83
	.byte 0x53, 0x8E, 0x54, 0x8B, 0x18, 0x19, 0x50, 0x83, 0x09, 0x78, 0x03, 0x20, 0x08, 0x40, 0x11, 0x1C
	.byte 0x38, 0x31, 0x00, 0x28, 0x01, 0xD1, 0x58, 0x1C, 0x50, 0x86, 0x08, 0x78, 0x10, 0xBC, 0x02, 0xBC
	.byte 0x08, 0x47, 0x00, 0x00

	thumb_func_start FUN_0808c7c4
FUN_0808c7c4: @ 0x0808C7C4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov sb, r0
	movs r1, #0
_0808C7D2:
	lsls r0, r1, #6
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r2, _0808C830 @ =0x00003B8C
	adds r0, r0, r2
	mov r2, sb
	adds r6, r2, r0
	ldrb r0, [r6, #4]
	adds r1, #1
	mov r8, r1
	cmp r0, #0
	beq _0808C81C
	movs r3, #0
	adds r4, r6, #0
	adds r4, #0x40
	adds r5, r6, #0
	adds r5, #8
	movs r7, #7
_0808C7F6:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0808C810
	ldr r1, [r6]
	ldr r2, [r4, #4]
	adds r0, r5, #0
	str r3, [sp]
	bl _call_via_r2
	ldr r3, [sp]
	cmp r0, #0
	beq _0808C810
	movs r3, #1
_0808C810:
	adds r4, #0x40
	adds r5, #0x40
	subs r7, #1
	cmp r7, #0
	bge _0808C7F6
	strb r3, [r6, #4]
_0808C81C:
	mov r1, r8
	cmp r1, #1
	ble _0808C7D2
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808C830: .4byte 0x00003B8C

	thumb_func_start FUN_0808c834
FUN_0808c834: @ 0x0808C834
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r2, [sp]
	str r3, [sp, #4]
	lsls r2, r1, #6
	adds r2, r2, r1
	lsls r2, r2, #3
	ldr r1, _0808C8F0 @ =0x00003B8C
	adds r2, r2, r1
	adds r0, r0, r2
	mov r8, r0
	ldr r0, _0808C8F4 @ =0x00001C1E
	bl FUN_0822b10c
	mov r2, r8
	str r0, [r2]
	movs r0, #1
	strb r0, [r2, #4]
	movs r7, #0
	ldr r3, _0808C8F8 @ =0x000003FF
	mov sl, r3
	mov r6, r8
	adds r6, #0x40
	mov r5, r8
	adds r5, #8
	adds r4, r5, #0
	ldr r0, _0808C8FC @ =0x085B0A08
	mov sb, r0
_0808C874:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r4, #0x18]
	mov r2, sp
	ldrh r2, [r2, #4]
	strh r2, [r4, #0x1a]
	mov r3, r8
	ldr r1, [r3]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822dafc
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	ldr r0, _0808C900 @ =0x030046B8
	ldr r1, [r0]
	adds r1, #1
	mov r2, sl
	ands r1, r2
	lsls r0, r1, #1
	ldr r3, _0808C904 @ =0x0203B400
	adds r0, r0, r3
	ldrh r2, [r0]
	lsls r3, r7, #5
	asrs r2, r2, #3
	movs r0, #0xf
	ands r2, r0
	adds r3, r3, r2
	adds r2, r3, #0
	subs r2, #8
	adds r1, #1
	mov r0, sl
	ands r1, r0
	ldr r0, _0808C900 @ =0x030046B8
	str r1, [r0]
	lsls r1, r1, #1
	ldr r0, _0808C904 @ =0x0203B400
	adds r1, r1, r0
	ldrh r0, [r1]
	asrs r0, r0, #3
	movs r1, #3
	ands r0, r1
	adds r1, r0, #4
	adds r3, #0x38
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	add r0, sb
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _0808C908
	asrs r0, r0, #0xc
	b _0808C90E
	.align 2, 0
_0808C8F0: .4byte 0x00003B8C
_0808C8F4: .4byte 0x00001C1E
_0808C8F8: .4byte 0x000003FF
_0808C8FC: .4byte 0x085B0A08
_0808C900: .4byte 0x030046B8
_0808C904: .4byte 0x0203B400
_0808C908:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808C90E:
	strh r0, [r4, #0x30]
	movs r0, #0xff
	ands r2, r0
	lsls r0, r2, #1
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _0808C926
	asrs r3, r0, #0xc
	b _0808C92C
_0808C926:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0808C92C:
	movs r0, #0
	strh r3, [r4, #0x32]
	movs r1, #1
	strb r1, [r6]
	strb r0, [r6, #1]
	ldr r0, _0808C958 @ =FUN_0808c710
	str r0, [r4, #0x3c]
	adds r6, #0x40
	adds r4, #0x40
	adds r5, #0x40
	adds r7, #1
	cmp r7, #7
	ble _0808C874
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808C958: .4byte FUN_0808c710

	thumb_func_start FUN_0808c95c
FUN_0808c95c: @ 0x0808C95C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r2, [sp]
	str r3, [sp, #4]
	lsls r2, r1, #6
	adds r2, r2, r1
	lsls r2, r2, #3
	ldr r1, _0808C9C4 @ =0x00003B8C
	adds r2, r2, r1
	adds r0, r0, r2
	mov sb, r0
	ldr r0, _0808C9C8 @ =0x00001C1C
	bl FUN_0822b10c
	mov r2, sb
	str r0, [r2]
	movs r0, #1
	strb r0, [r2, #4]
	movs r3, #0
	mov r8, r3
	mov r6, sb
	adds r6, #0x40
	mov r5, sb
	adds r5, #8
	adds r4, r5, #0
	mov sl, r0
_0808C998:
	ldr r1, [r4]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r4]
	ldr r7, _0808C9CC @ =0x030046B8
	ldr r0, [r7]
	adds r0, #1
	ldr r2, _0808C9D0 @ =0x000003FF
	ands r0, r2
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _0808C9D4 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r7, sl
	ands r0, r7
	cmp r0, #0
	beq _0808C9D8
	movs r0, #4
	orrs r1, r0
	b _0808C9DE
	.align 2, 0
_0808C9C4: .4byte 0x00003B8C
_0808C9C8: .4byte 0x00001C1C
_0808C9CC: .4byte 0x030046B8
_0808C9D0: .4byte 0x000003FF
_0808C9D4: .4byte 0x0203B400
_0808C9D8:
	movs r0, #5
	rsbs r0, r0, #0
	ands r1, r0
_0808C9DE:
	str r1, [r4]
	mov r0, sb
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0x15
	bl FUN_0822dafc
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0822dadc
	ldr r2, _0808CA4C @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r3, _0808CA50 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	ldr r7, _0808CA54 @ =0x0203B400
	adds r0, r0, r7
	ldrh r2, [r0]
	mov r0, r8
	lsls r3, r0, #5
	asrs r2, r2, #3
	movs r0, #0xf
	ands r2, r0
	adds r3, r3, r2
	adds r2, r3, #0
	subs r2, #8
	adds r1, #1
	ldr r7, _0808CA50 @ =0x000003FF
	ands r1, r7
	ldr r0, _0808CA4C @ =0x030046B8
	str r1, [r0]
	lsls r1, r1, #1
	ldr r7, _0808CA54 @ =0x0203B400
	adds r1, r1, r7
	ldrh r0, [r1]
	asrs r0, r0, #3
	mov r1, sl
	ands r0, r1
	adds r1, r0, #3
	adds r3, #0x38
	movs r0, #0xff
	ands r3, r0
	lsls r3, r3, #1
	ldr r7, _0808CA58 @ =0x085B0A08
	adds r3, r3, r7
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r0, r1, r0
	cmp r0, #0
	blt _0808CA5C
	asrs r0, r0, #0xc
	b _0808CA62
	.align 2, 0
_0808CA4C: .4byte 0x030046B8
_0808CA50: .4byte 0x000003FF
_0808CA54: .4byte 0x0203B400
_0808CA58: .4byte 0x085B0A08
_0808CA5C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808CA62:
	strh r0, [r4, #0x30]
	movs r0, #0xff
	ands r2, r0
	lsls r0, r2, #1
	ldr r2, _0808CA7C @ =0x085B0A08
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _0808CA80
	asrs r0, r0, #0xc
	b _0808CA86
	.align 2, 0
_0808CA7C: .4byte 0x085B0A08
_0808CA80:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808CA86:
	subs r1, r0, #2
	movs r2, #0
	strh r1, [r4, #0x32]
	ldrh r0, [r4, #0x30]
	ldr r7, [sp]
	adds r0, r0, r7
	strh r0, [r4, #0x18]
	ldr r0, [sp, #4]
	adds r1, r1, r0
	strh r1, [r4, #0x1a]
	mov r1, sl
	strb r1, [r6]
	strb r2, [r6, #1]
	ldr r0, _0808CAC8 @ =0x0808C771
	str r0, [r4, #0x3c]
	adds r6, #0x40
	adds r4, #0x40
	adds r5, #0x40
	movs r2, #1
	add r8, r2
	mov r3, r8
	cmp r3, #7
	bgt _0808CAB6
	b _0808C998
_0808CAB6:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808CAC8: .4byte 0x0808C771

	thumb_func_start FUN_0808cacc
FUN_0808cacc: @ 0x0808CACC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r1, #0
_0808CAD2:
	lsls r0, r1, #6
	adds r6, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r1, _0808CAFC @ =0x00003B94
	adds r0, r0, r1
	adds r4, r7, r0
	movs r5, #7
_0808CAE2:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x40
	subs r5, #1
	cmp r5, #0
	bge _0808CAE2
	adds r1, r6, #0
	cmp r1, #1
	ble _0808CAD2
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808CAFC: .4byte 0x00003B94

	thumb_func_start FUN_0808cb00
FUN_0808cb00: @ 0x0808CB00
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	movs r4, #0
_0808CB10:
	lsls r0, r4, #6
	adds r0, r0, r4
	lsls r0, r0, #3
	ldr r1, _0808CB88 @ =0x00003B8C
	adds r0, r0, r1
	ldr r1, [sp]
	adds r6, r1, r0
	movs r0, #0x91
	str r0, [sp, #4]
	cmp r4, #0
	bne _0808CB2A
	movs r1, #0x11
	str r1, [sp, #4]
_0808CB2A:
	ldr r0, _0808CB8C @ =0x00001C1E
	bl FUN_0822b10c
	str r0, [r6]
	movs r0, #0
	strb r0, [r6, #4]
	strb r0, [r6, #5]
	adds r4, #1
	mov sl, r4
	subs r0, #4
	mov sb, r0
	movs r1, #0
	mov r8, r1
	adds r5, r6, #0
	adds r5, #0x40
	adds r4, r6, #0
	adds r4, #8
	movs r7, #7
_0808CB4E:
	ldr r1, [r6]
	adds r0, r4, #0
	ldr r2, [sp, #4]
	bl FUN_0822d9f0
	adds r0, r4, #0
	mov r1, sb
	mov r2, sb
	bl FUN_0822dad4
	mov r0, r8
	strb r0, [r4, #0xf]
	strb r0, [r5]
	adds r5, #0x40
	adds r4, #0x40
	subs r7, #1
	cmp r7, #0
	bge _0808CB4E
	mov r4, sl
	cmp r4, #1
	ble _0808CB10
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808CB88: .4byte 0x00003B8C
_0808CB8C: .4byte 0x00001C1E

	thumb_func_start FUN_0808cb90
FUN_0808cb90: @ 0x0808CB90
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xa3
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808CBCC
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0808a420
	adds r2, r0, #0
	movs r1, #0
	ldr r0, _0808CBD4 @ =0xFFFFD000
	adds r3, r0, #0
_0808CBB2:
	adds r0, r1, #0
	adds r0, #0xa0
	orrs r0, r3
	strh r0, [r2]
	adds r2, #2
	adds r1, #1
	cmp r1, #8
	ble _0808CBB2
	movs r0, #0xa3
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0808CBCC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808CBD4: .4byte 0xFFFFD000

	thumb_func_start FUN_0808cbd8
FUN_0808cbd8: @ 0x0808CBD8
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xa3
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808CC0E
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0808a420
	movs r1, #0xd0
	lsls r1, r1, #8
	adds r2, r1, #0
	movs r1, #8
_0808CBFA:
	strh r2, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0808CBFA
	movs r0, #0xa3
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
_0808CC0E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808cc14
FUN_0808cc14: @ 0x0808CC14
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _0808CC7E
	ldr r0, _0808CC4C @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x42
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _0808CC78
	ldr r1, _0808CC50 @ =0x00000A31
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x1d
	bhi _0808CC54
	adds r0, r4, #0
	bl FUN_0808cbd8
	b _0808CC5A
	.align 2, 0
_0808CC4C: .4byte 0x030046A0
_0808CC50: .4byte 0x00000A31
_0808CC54:
	adds r0, r4, #0
	bl FUN_0808cb90
_0808CC5A:
	ldr r0, _0808CC74 @ =0x00000A31
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3b
	bls _0808CC7E
	movs r0, #0
	strb r0, [r1]
	b _0808CC7E
	.align 2, 0
_0808CC74: .4byte 0x00000A31
_0808CC78:
	adds r0, r4, #0
	bl FUN_0808cbd8
_0808CC7E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808cc84
FUN_0808cc84: @ 0x0808CC84
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0808CCA2
	b _0808CE04
_0808CCA2:
	ldr r3, _0808CCE0 @ =0x00000282
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808CCB6
	adds r2, #5
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808CD48
_0808CCB6:
	ldr r3, _0808CCE4 @ =0x00000C03
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808CCF0
	ldr r1, _0808CCE8 @ =0x00000C02
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	muls r0, r1, r0
	adds r0, r0, r4
	ldr r2, _0808CCEC @ =0x00000C0C
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0xc8
	movs r3, #1
	bl FUN_0822f3cc
	b _0808CD24
	.align 2, 0
_0808CCE0: .4byte 0x00000282
_0808CCE4: .4byte 0x00000C03
_0808CCE8: .4byte 0x00000C02
_0808CCEC: .4byte 0x00000C0C
_0808CCF0:
	cmp r0, #0x1e
	bne _0808CD24
	ldr r3, _0808CD3C @ =0x00000C02
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r2, r4
	ldr r1, _0808CD40 @ =0x00000C0C
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xa0
	adds r2, r4, r2
	adds r3, #7
	adds r2, r2, r3
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl FUN_0822f3cc
_0808CD24:
	ldr r0, _0808CD44 @ =0x00000C03
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3b
	bls _0808CE04
	movs r0, #0
	strb r0, [r1]
	b _0808CE04
	.align 2, 0
_0808CD3C: .4byte 0x00000C02
_0808CD40: .4byte 0x00000C0C
_0808CD44: .4byte 0x00000C03
_0808CD48:
	ldr r2, _0808CD98 @ =0x00000283
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808CDD4
	ldr r3, _0808CD9C @ =0x000009EE
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _0808CDA0 @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808CDAC
	ldr r3, _0808CDA4 @ =0x00000C02
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r2, r4
	ldr r1, _0808CDA8 @ =0x00000C0C
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xa0
	adds r2, r4, r2
	adds r3, #7
	adds r2, r2, r3
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	b _0808CDC4
	.align 2, 0
_0808CD98: .4byte 0x00000283
_0808CD9C: .4byte 0x000009EE
_0808CDA0: .4byte 0x0000FFFF
_0808CDA4: .4byte 0x00000C02
_0808CDA8: .4byte 0x00000C0C
_0808CDAC:
	ldr r1, _0808CDCC @ =0x00000C02
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	muls r0, r1, r0
	adds r0, r0, r4
	ldr r2, _0808CDD0 @ =0x00000C0C
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0xc9
_0808CDC4:
	movs r3, #1
	bl FUN_0822f3cc
	b _0808CE04
	.align 2, 0
_0808CDCC: .4byte 0x00000C02
_0808CDD0: .4byte 0x00000C0C
_0808CDD4:
	ldr r3, _0808CE34 @ =0x00000C02
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r2, r4
	ldr r1, _0808CE38 @ =0x00000C0C
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xa0
	adds r2, r4, r2
	adds r3, #7
	adds r2, r2, r3
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl FUN_0822f3cc
_0808CE04:
	ldr r0, _0808CE3C @ =0x00000D99
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0808CE48
	ldr r1, _0808CE40 @ =0x00000D98
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x68
	muls r0, r1, r0
	adds r0, r0, r4
	ldr r2, _0808CE44 @ =0x00000DA4
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0xc9
	movs r3, #1
	bl FUN_0822f3cc
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	b _0808CE8E
	.align 2, 0
_0808CE34: .4byte 0x00000C02
_0808CE38: .4byte 0x00000C0C
_0808CE3C: .4byte 0x00000D99
_0808CE40: .4byte 0x00000D98
_0808CE44: .4byte 0x00000DA4
_0808CE48:
	ldr r3, _0808CE78 @ =0x00000D98
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x68
	muls r1, r0, r1
	movs r2, #0xda
	lsls r2, r2, #4
	adds r0, r4, r2
	adds r0, r0, r1
	ldr r2, [r0]
	cmp r2, #0
	bne _0808CE7C
	adds r0, r1, r4
	adds r3, #0xc
	adds r0, r0, r3
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0
	movs r3, #1
	bl FUN_0822f3cc
	b _0808CE8E
	.align 2, 0
_0808CE78: .4byte 0x00000D98
_0808CE7C:
	adds r0, r1, r4
	ldr r1, _0808CE94 @ =0x00000DA4
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xa0
	ldrb r2, [r2]
	movs r3, #1
	bl FUN_0822f3cc
_0808CE8E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808CE94: .4byte 0x00000DA4

	thumb_func_start FUN_0808ce98
FUN_0808ce98: @ 0x0808CE98
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0808CF0E
	ldr r0, _0808CEF0 @ =0x000009FE
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #7
	beq _0808CF0E
	cmp r0, #2
	bhi _0808CF0E
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #1
	bl FUN_0808a610
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #2
	bl FUN_0808a768
	adds r0, r4, #0
	movs r1, #0
	movs r2, #9
	movs r3, #0x12
	bl FUN_0808a9a4
	adds r0, r4, #0
	bl FUN_0808afac
	ldrb r0, [r5]
	cmp r0, #0
	bne _0808CEF4
	adds r0, r4, #0
	bl FUN_0808ad5c
	b _0808CEFC
	.align 2, 0
_0808CEF0: .4byte 0x000009FE
_0808CEF4:
	ldrb r1, [r5]
	adds r0, r4, #0
	bl FUN_0808abec
_0808CEFC:
	adds r0, r4, #0
	bl FUN_0808cc14
	adds r0, r4, #0
	bl FUN_0808cc84
	adds r0, r4, #0
	bl FUN_0808b1bc
_0808CF0E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808cf14
FUN_0808cf14: @ 0x0808CF14
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808CF40 @ =0x030044BC
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0808CF4A
	adds r0, r4, #0
	bl FUN_0808ce98
	adds r0, r4, #0
	bl FUN_0808da88
	cmp r0, #0
	beq _0808CF44
	movs r0, #0x86
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0808CF4A
	.align 2, 0
_0808CF40: .4byte 0x030044BC
_0808CF44:
	adds r0, r4, #0
	bl FUN_0809b3b0
_0808CF4A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808cf50
FUN_0808cf50: @ 0x0808CF50
	push {lr}
	ldr r1, _0808CF60 @ =0x00000A34
	adds r0, r0, r1
	bl FUN_0822f1c0
	pop {r0}
	bx r0
	.align 2, 0
_0808CF60: .4byte 0x00000A34

	thumb_func_start FUN_0808cf64
FUN_0808cf64: @ 0x0808CF64
	push {r4, r5, lr}
	sub sp, #0x18
	adds r5, r0, #0
	ldr r0, _0808CFA4 @ =0x030047A4
	ldr r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #5
	ands r2, r0
	cmp r2, #0
	beq _0808CFB4
	ldr r1, _0808CFA8 @ =0xFFFF0000
	movs r2, #0
	str r2, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	ldr r1, _0808CFAC @ =0x00000A34
	adds r0, r5, r1
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r3, _0808CFB0 @ =0x00010031
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	movs r2, #0x47
	bl FUN_0822f3fc
	b _0808CFE6
	.align 2, 0
_0808CFA4: .4byte 0x030047A4
_0808CFA8: .4byte 0xFFFF0000
_0808CFAC: .4byte 0x00000A34
_0808CFB0: .4byte 0x00010031
_0808CFB4:
	movs r4, #0
	movs r1, #8
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x18
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	ldr r3, _0808CFF0 @ =0x00000A34
	adds r0, r5, r3
	adds r1, r5, #0
	adds r1, #0xa0
	ldr r3, _0808CFF4 @ =0x00010031
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	movs r2, #0x68
	bl FUN_0822f3fc
	ldr r3, _0808CFF8 @ =0x00000A95
	adds r0, r5, r3
	strb r4, [r0]
_0808CFE6:
	add sp, #0x18
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808CFF0: .4byte 0x00000A34
_0808CFF4: .4byte 0x00010031
_0808CFF8: .4byte 0x00000A95

	thumb_func_start FUN_0808cffc
FUN_0808cffc: @ 0x0808CFFC
	push {r4, r5, lr}
	movs r1, #0xaa
	lsls r1, r1, #4
	adds r4, r0, r1
	movs r5, #1
_0808D006:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0808D006
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808d01c
FUN_0808d01c: @ 0x0808D01C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r1, _0808D0AC @ =0x0000FFFF
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r1, _0808D0B0 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r5, #0
	mov r8, r5
	movs r0, #0xaa
	lsls r0, r0, #4
	adds r4, r6, r0
	movs r7, #0
	ldr r3, _0808D0B4 @ =0x03003584
	mov sb, r3
_0808D04E:
	adds r1, r5, #0
	adds r1, #0xe
	lsls r1, r1, #0x13
	lsrs r1, r1, #0x10
	ldr r2, _0808D0B0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0x73
	ldr r3, _0808D0B8 @ =0x00010031
	bl FUN_0822f3fc
	mov r0, r8
	strh r0, [r4, #0x3a]
	ldr r3, _0808D0BC @ =0x00000AE8
	adds r2, r6, r3
	adds r2, r2, r7
	ldrh r1, [r4, #0x3a]
	lsls r1, r1, #5
	mov r3, sb
	ldr r0, [r3]
	adds r0, r0, r1
	str r0, [r2]
	adds r4, #0x60
	adds r7, #0x60
	adds r5, #1
	cmp r5, #1
	ble _0808D04E
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808D0AC: .4byte 0x0000FFFF
_0808D0B0: .4byte 0xFFFF0000
_0808D0B4: .4byte 0x03003584
_0808D0B8: .4byte 0x00010031
_0808D0BC: .4byte 0x00000AE8

	thumb_func_start FUN_0808d0c0
FUN_0808d0c0: @ 0x0808D0C0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r5, _0808D174 @ =0x0000C091
	ldr r1, _0808D178 @ =0x0000A413
	adds r0, r5, #0
	bl FUN_082310cc
	str r0, [r4, #0x18]
	ldr r1, _0808D17C @ =0x0000A7D7
	adds r0, r5, #0
	bl FUN_082310cc
	str r0, [r4, #0x1c]
	ldr r1, _0808D180 @ =0x0000A7E7
	adds r0, r5, #0
	bl FUN_082310cc
	str r0, [r4, #0x20]
	ldr r1, _0808D184 @ =0x0000A7F7
	adds r0, r5, #0
	bl FUN_082310cc
	str r0, [r4, #0x24]
	ldr r1, _0808D188 @ =0x000083C0
	adds r0, r5, #0
	bl FUN_082310cc
	str r0, [r4, #0x2c]
	ldr r1, _0808D18C @ =0x000009FE
	adds r0, r4, r1
	movs r6, #0
	strb r6, [r0]
	ldr r5, _0808D190 @ =0x000092B3
	ldr r1, _0808D194 @ =0x0000EFDA
	adds r0, r5, #0
	bl FUN_082310cc
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x30]
	ldr r1, _0808D198 @ =0x0000ECBF
	adds r0, r5, #0
	bl FUN_082310cc
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x34]
	ldr r1, _0808D19C @ =0x00005F5E
	adds r0, r5, #0
	bl FUN_082310cc
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x38]
	ldr r1, _0808D1A0 @ =0x0000EAA8
	adds r0, r5, #0
	bl FUN_082310cc
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x3c]
	ldr r1, [r4, #0x18]
	ldr r0, [r4, #0x30]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0808a3c4
	ldr r1, _0808D1A4 @ =0x00000A94
	adds r0, r4, r1
	strb r6, [r0]
	subs r1, #0x6a
	adds r0, r4, r1
	strb r6, [r0]
	adds r0, r4, #0
	bl FUN_0808cf64
	adds r0, r4, #0
	bl FUN_0808d01c
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808D174: .4byte 0x0000C091
_0808D178: .4byte 0x0000A413
_0808D17C: .4byte 0x0000A7D7
_0808D180: .4byte 0x0000A7E7
_0808D184: .4byte 0x0000A7F7
_0808D188: .4byte 0x000083C0
_0808D18C: .4byte 0x000009FE
_0808D190: .4byte 0x000092B3
_0808D194: .4byte 0x0000EFDA
_0808D198: .4byte 0x0000ECBF
_0808D19C: .4byte 0x00005F5E
_0808D1A0: .4byte 0x0000EAA8
_0808D1A4: .4byte 0x00000A94

	thumb_func_start FUN_0808d1a8
FUN_0808d1a8: @ 0x0808D1A8
	push {lr}
	adds r1, r0, #0
	ldr r2, _0808D1F8 @ =0x00000F3C
	adds r0, r1, r2
	ldrb r0, [r0]
	movs r2, #0x1f
	cmp r0, #9
	bls _0808D1D2
	movs r2, #0x1b
	cmp r0, #0x11
	bls _0808D1D2
	movs r2, #0x12
	cmp r0, #0x19
	bls _0808D1D2
	movs r2, #0xa
	cmp r0, #0x21
	bls _0808D1D2
	movs r2, #0x1b
	cmp r0, #0x29
	bhi _0808D1D2
	movs r2, #0x12
_0808D1D2:
	ldr r0, _0808D1F8 @ =0x00000F3C
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x31
	bls _0808D1E8
	movs r0, #0
	strb r0, [r1]
_0808D1E8:
	ldr r0, _0808D1FC @ =0x03004250
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r0, r1
	strh r2, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0808D1F8: .4byte 0x00000F3C
_0808D1FC: .4byte 0x03004250

	thumb_func_start FUN_0808d200
FUN_0808d200: @ 0x0808D200
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r7, _0808D260 @ =0x085AC064
	movs r6, #0
_0808D20C:
	adds r4, r6, #0
	adds r4, #0x10
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0808a420
	adds r5, r0, #0
	movs r0, #0
	movs r1, #0x1a
	adds r2, r4, #0
	bl FUN_0808a420
	adds r1, r0, #0
	adds r4, r6, #1
	movs r2, #3
_0808D22C:
	ldrh r0, [r7]
	strh r0, [r5]
	adds r5, #2
	ldrh r0, [r7]
	strh r0, [r1]
	adds r1, #2
	adds r7, #2
	subs r2, #1
	cmp r2, #0
	bge _0808D22C
	adds r6, r4, #0
	cmp r6, #3
	ble _0808D20C
	ldr r1, _0808D264 @ =0x00000F3C
	add r1, r8
	movs r0, #0
	strb r0, [r1]
	mov r0, r8
	bl FUN_0808d1a8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808D260: .4byte 0x085AC064
_0808D264: .4byte 0x00000F3C

	thumb_func_start FUN_0808d268
FUN_0808d268: @ 0x0808D268
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	movs r0, #0xd0
	lsls r0, r0, #8
	adds r7, r0, #0
_0808D272:
	adds r4, r6, #0
	adds r4, #0x10
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0808a420
	adds r5, r0, #0
	movs r0, #0
	movs r1, #0x1a
	adds r2, r4, #0
	bl FUN_0808a420
	adds r4, r6, #1
	movs r1, #3
_0808D290:
	strh r7, [r5]
	adds r5, #2
	strh r7, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0808D290
	adds r6, r4, #0
	cmp r6, #3
	ble _0808D272
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808d2ac
FUN_0808d2ac: @ 0x0808D2AC
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
_0808D2B2:
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r5, r0
	bge _0808D304
	movs r0, #0x64
	adds r3, r5, #0
	muls r3, r0, r3
	ldr r0, _0808D2F8 @ =0x00000C14
	adds r2, r4, r0
	adds r2, r2, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r0, r3, r4
	ldr r1, _0808D2FC @ =0x00000C0C
	adds r0, r0, r1
	adds r3, r4, r3
	ldr r2, _0808D300 @ =0x00000C09
	adds r3, r3, r2
	movs r2, #0
	ldrsb r2, [r3, r2]
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r4, #0
	adds r1, #0xa0
	movs r3, #1
	bl FUN_0822f3cc
	b _0808D316
	.align 2, 0
_0808D2F8: .4byte 0x00000C14
_0808D2FC: .4byte 0x00000C0C
_0808D300: .4byte 0x00000C09
_0808D304:
	movs r0, #0x64
	muls r0, r5, r0
	ldr r1, _0808D354 @ =0x00000C14
	adds r2, r4, r1
	adds r2, r2, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_0808D316:
	movs r2, #0xf4
	lsls r2, r2, #4
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r5, r0
	bge _0808D378
	movs r0, #0x68
	adds r3, r5, #0
	muls r3, r0, r3
	ldr r0, _0808D358 @ =0x00000DAC
	adds r2, r4, r0
	adds r2, r2, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xda
	lsls r1, r1, #4
	adds r0, r4, r1
	adds r0, r0, r3
	ldr r1, [r0]
	cmp r1, #0
	bne _0808D360
	adds r0, r3, r4
	ldr r2, _0808D35C @ =0x00000DA4
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0
	b _0808D36C
	.align 2, 0
_0808D354: .4byte 0x00000C14
_0808D358: .4byte 0x00000DAC
_0808D35C: .4byte 0x00000DA4
_0808D360:
	adds r0, r3, r4
	ldr r2, _0808D374 @ =0x00000DA4
	adds r0, r0, r2
	ldrb r2, [r1]
	adds r1, r4, #0
	adds r1, #0xa0
_0808D36C:
	movs r3, #1
	bl FUN_0822f3cc
	b _0808D38A
	.align 2, 0
_0808D374: .4byte 0x00000DA4
_0808D378:
	movs r0, #0x68
	muls r0, r5, r0
	ldr r1, _0808D398 @ =0x00000DAC
	adds r2, r4, r1
	adds r2, r2, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_0808D38A:
	adds r5, #1
	cmp r5, #3
	ble _0808D2B2
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808D398: .4byte 0x00000DAC

	thumb_func_start FUN_0808d39c
FUN_0808d39c: @ 0x0808D39C
	push {r4, r5, lr}
	movs r3, #1
	ldr r1, _0808D3C8 @ =0x00000C14
	adds r2, r0, r1
	ldr r4, _0808D3CC @ =0x00000DAC
	adds r1, r0, r4
	ldr r5, _0808D3D0 @ =0x00000EE4
	adds r4, r0, r5
_0808D3AC:
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r2, #0x64
	adds r1, #0x68
	cmp r1, r4
	ble _0808D3AC
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808D3C8: .4byte 0x00000C14
_0808D3CC: .4byte 0x00000DAC
_0808D3D0: .4byte 0x00000EE4

	thumb_func_start FUN_0808d3d4
FUN_0808d3d4: @ 0x0808D3D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	movs r3, #0
	movs r0, #0xc0
	lsls r0, r0, #4
	adds r0, r0, r4
	mov sl, r0
	ldr r1, _0808D430 @ =0x00000C02
	adds r1, r1, r4
	mov sb, r1
	ldr r7, _0808D434 @ =0x00000DAC
	adds r6, r4, r7
	movs r0, #2
	rsbs r0, r0, #0
	mov ip, r0
	movs r1, #0xf4
	lsls r1, r1, #4
	adds r1, r1, r4
	mov r8, r1
	ldr r7, _0808D438 @ =0x00000C14
	adds r2, r4, r7
	adds r5, r4, #0
_0808D408:
	mov r0, sl
	ldrb r0, [r0]
	cmp r3, r0
	bge _0808D440
	mov r1, sb
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r3, r0
	bne _0808D440
	ldr r7, _0808D43C @ =0x00000C09
	adds r0, r5, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0808D440
	ldr r0, [r2]
	mov r1, ip
	ands r0, r1
	b _0808D446
	.align 2, 0
_0808D430: .4byte 0x00000C02
_0808D434: .4byte 0x00000DAC
_0808D438: .4byte 0x00000C14
_0808D43C: .4byte 0x00000C09
_0808D440:
	ldr r0, [r2]
	movs r7, #1
	orrs r0, r7
_0808D446:
	str r0, [r2]
	mov r0, r8
	ldrb r0, [r0]
	cmp r3, r0
	bge _0808D474
	ldr r1, _0808D470 @ =0x00000D98
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r3, r0
	bne _0808D474
	movs r0, #0x68
	adds r1, r3, #0
	muls r1, r0, r1
	adds r1, r6, r1
	ldr r0, [r1]
	mov r7, ip
	ands r0, r7
	b _0808D482
	.align 2, 0
_0808D470: .4byte 0x00000D98
_0808D474:
	movs r0, #0x68
	adds r1, r3, #0
	muls r1, r0, r1
	adds r1, r6, r1
	ldr r0, [r1]
	movs r7, #1
	orrs r0, r7
_0808D482:
	str r0, [r1]
	adds r2, #0x64
	adds r5, #0x64
	adds r3, #1
	cmp r3, #3
	ble _0808D408
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808d49c
FUN_0808d49c: @ 0x0808D49C
	push {r4, r5, lr}
	adds r0, r1, #0
	adds r5, r3, #0
	ldr r4, [sp, #0xc]
	adds r0, r5, r0
	subs r0, r0, r2
	adds r1, r5, #0
	bl Mod
	lsls r2, r4, #1
	adds r2, r2, r4
	movs r3, #0x88
	subs r2, r3, r2
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	subs r2, r2, r1
	subs r1, r5, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	subs r3, r3, r0
	cmp r2, r3
	bge _0808D4D4
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r2, r2, r0
_0808D4D4:
	adds r0, r2, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808d4dc
FUN_0808d4dc: @ 0x0808D4DC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r4, r0, #0
	movs r6, #0
	movs r1, #0xf4
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r6, r0
	bge _0808D554
	adds r7, r4, r1
	mov r8, r6
	ldr r0, _0808D51C @ =0x00000DA4
	adds r5, r4, r0
_0808D4FC:
	movs r1, #0xda
	lsls r1, r1, #4
	adds r0, r4, r1
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	bne _0808D520
	adds r0, r5, #0
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0
	movs r3, #1
	bl FUN_0822f3cc
	b _0808D52E
	.align 2, 0
_0808D51C: .4byte 0x00000DA4
_0808D520:
	ldrb r2, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	adds r1, #0xa0
	movs r3, #1
	bl FUN_0822f3cc
_0808D52E:
	ldr r1, _0808D560 @ =0x00000D98
	adds r0, r4, r1
	movs r2, #0
	ldrsb r2, [r0, r2]
	ldrb r3, [r7]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_0808d49c
	strh r0, [r5, #0x22]
	movs r0, #0x68
	add r8, r0
	adds r5, #0x68
	adds r6, #1
	ldrb r1, [r7]
	cmp r6, r1
	blt _0808D4FC
_0808D554:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808D560: .4byte 0x00000D98

	thumb_func_start FUN_0808d564
FUN_0808d564: @ 0x0808D564
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r6, #0
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r6, r0
	bge _0808D5BC
	adds r7, r5, r1
_0808D57A:
	movs r0, #0x64
	adds r4, r6, #0
	muls r4, r0, r4
	ldr r0, _0808D5C4 @ =0x00000C08
	adds r4, r4, r0
	adds r4, r5, r4
	adds r0, r4, #4
	movs r2, #1
	ldrsb r2, [r4, r2]
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r5, #0
	adds r1, #0xa0
	movs r3, #1
	bl FUN_0822f3cc
	ldr r1, _0808D5C8 @ =0x00000C02
	adds r0, r5, r1
	movs r2, #0
	ldrsb r2, [r0, r2]
	ldrb r3, [r7]
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_0808d49c
	strh r0, [r4, #0x26]
	adds r6, #1
	ldrb r0, [r7]
	cmp r6, r0
	blt _0808D57A
_0808D5BC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808D5C4: .4byte 0x00000C08
_0808D5C8: .4byte 0x00000C02

	thumb_func_start FUN_0808d5cc
FUN_0808d5cc: @ 0x0808D5CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r6, #0
	ldr r0, _0808D634 @ =0x00000D98
	adds r2, r7, r0
	movs r0, #0xff
	strb r0, [r2]
	mov sl, r6
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #5
	beq _0808D6BC
	movs r5, #0
	ldr r0, _0808D638 @ =0x030046A0
	mov sb, r0
_0808D5FE:
	movs r1, #0
	mov ip, r1
	movs r3, #0
	movs r2, #1
	rsbs r2, r2, #0
	mov r8, r2
	mov r1, sb
	ldr r0, [r1]
	lsls r4, r5, #1
	adds r0, r4, r0
	adds r1, r0, #0
	adds r1, #0x60
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _0808D63C
	bl GetWeapon
	adds r3, r0, #0
	mov r1, sb
	ldr r0, [r1]
	adds r0, r4, r0
	adds r0, #0x60
	movs r1, #0
	ldrsh r2, [r0, r1]
	mov r8, r2
	b _0808D670
	.align 2, 0
_0808D634: .4byte 0x00000D98
_0808D638: .4byte 0x030046A0
_0808D63C:
	movs r2, #0
	ldr r0, _0808D654 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _0808D658
	mov r0, sl
	cmp r0, #0
	bne _0808D65E
	b _0808D662
	.align 2, 0
_0808D654: .4byte 0x030047A4
_0808D658:
	cmp r5, #3
	bne _0808D65E
	movs r2, #1
_0808D65E:
	cmp r2, #0
	beq _0808D66A
_0808D662:
	movs r3, #0
	movs r1, #1
	mov sl, r1
	mov ip, r1
_0808D66A:
	mov r2, ip
	cmp r2, #0
	beq _0808D69A
_0808D670:
	movs r0, #0x68
	muls r0, r6, r0
	ldr r1, _0808D6A4 @ =0x00000D9C
	adds r0, r0, r1
	adds r0, r7, r0
	strb r5, [r0]
	mov r2, r8
	strb r2, [r0, #1]
	str r3, [r0, #4]
	ldr r1, _0808D6A8 @ =0x030046A0
	ldr r0, [r1]
	adds r0, #0x58
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov sb, r1
	cmp r5, r0
	bne _0808D698
	ldr r1, _0808D6AC @ =0x00000D98
	adds r0, r7, r1
	strb r6, [r0]
_0808D698:
	adds r6, #1
_0808D69A:
	adds r5, #1
	cmp r5, #3
	ble _0808D5FE
	b _0808D6D2
	.align 2, 0
_0808D6A4: .4byte 0x00000D9C
_0808D6A8: .4byte 0x030046A0
_0808D6AC: .4byte 0x00000D98
_0808D6B0:
	ldr r3, _0808D6B8 @ =0x00000D98
	adds r0, r7, r3
	strb r2, [r0]
	b _0808D754
	.align 2, 0
_0808D6B8: .4byte 0x00000D98
_0808D6BC:
	ldr r1, _0808D764 @ =0x00000D9C
	adds r0, r7, r1
	movs r1, #3
	strb r1, [r0]
	strb r6, [r0, #1]
	movs r3, #0xff
	lsls r3, r3, #6
	adds r1, r7, r3
	str r1, [r0, #4]
	strb r6, [r2]
	movs r6, #1
_0808D6D2:
	movs r1, #0xf4
	lsls r1, r1, #4
	adds r0, r7, r1
	strb r6, [r0]
	ldr r4, _0808D768 @ =0x030047A4
	cmp r6, #3
	bgt _0808D704
	movs r2, #0xff
	movs r3, #0
	movs r0, #0x68
	muls r0, r6, r0
	ldr r1, _0808D764 @ =0x00000D9C
	adds r0, r0, r1
	adds r1, r0, r7
_0808D6EE:
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	ldrb r0, [r1, #1]
	orrs r0, r2
	strb r0, [r1, #1]
	str r3, [r1, #4]
	adds r1, #0x68
	adds r6, #1
	cmp r6, #3
	ble _0808D6EE
_0808D704:
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	bne _0808D754
	ldr r2, _0808D76C @ =0x00000D98
	adds r0, r7, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0808D754
	ldr r0, _0808D770 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x58
	movs r1, #3
	strh r1, [r0]
	movs r2, #0
	movs r5, #0
	movs r3, #0xf4
	lsls r3, r3, #4
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r5, r0
	bge _0808D754
	adds r3, r0, #0
	ldr r0, _0808D764 @ =0x00000D9C
	adds r1, r7, r0
_0808D73E:
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #3
	beq _0808D6B0
	cmp r0, #0
	blt _0808D74C
	adds r2, #1
_0808D74C:
	adds r1, #0x68
	adds r5, #1
	cmp r5, r3
	blt _0808D73E
_0808D754:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808D764: .4byte 0x00000D9C
_0808D768: .4byte 0x030047A4
_0808D76C: .4byte 0x00000D98
_0808D770: .4byte 0x030046A0

	thumb_func_start FUN_0808d774
FUN_0808d774: @ 0x0808D774
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r5, #0
	ldr r0, _0808D7E4 @ =0x00000C02
	adds r7, r6, r0
	movs r0, #0xff
	strb r0, [r7]
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _0808D7F4
	ldr r0, _0808D7E8 @ =0x00000C04
	adds r2, r6, r0
	ldr r1, _0808D7EC @ =0x030046A0
	ldr r3, [r1]
	adds r0, r3, #0
	adds r0, #0x5a
	str r0, [r2]
	movs r4, #0
	mov r8, r1
	mov ip, r2
	adds r3, #0x68
	movs r2, #0
_0808D7B2:
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	blt _0808D7D8
	ldr r0, _0808D7F0 @ =0x00000C08
	adds r1, r2, r0
	adds r1, r6, r1
	strb r4, [r1]
	ldrh r0, [r3]
	strb r0, [r1, #1]
	mov r1, ip
	ldr r0, [r1]
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r4, r0
	bne _0808D7D4
	strb r5, [r7]
_0808D7D4:
	adds r2, #0x64
	adds r5, #1
_0808D7D8:
	adds r3, #2
	adds r4, #1
	cmp r4, #3
	ble _0808D7B2
	b _0808D83E
	.align 2, 0
_0808D7E4: .4byte 0x00000C02
_0808D7E8: .4byte 0x00000C04
_0808D7EC: .4byte 0x030046A0
_0808D7F0: .4byte 0x00000C08
_0808D7F4:
	ldr r0, _0808D818 @ =0x00000C04
	adds r2, r6, r0
	ldr r1, _0808D81C @ =0x030046A0
	ldr r0, [r1]
	adds r0, #0x5e
	str r0, [r2]
	movs r4, #0
	mov r8, r1
	adds r3, r7, #0
	movs r1, #8
	mov ip, r1
	ldr r7, _0808D820 @ =0x00000C08
	adds r1, r6, r7
_0808D80E:
	strb r4, [r1]
	cmp r4, #0
	bne _0808D824
	mov r0, ip
	b _0808D826
	.align 2, 0
_0808D818: .4byte 0x00000C04
_0808D81C: .4byte 0x030046A0
_0808D820: .4byte 0x00000C08
_0808D824:
	movs r0, #9
_0808D826:
	strb r0, [r1, #1]
	ldr r0, [r2]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r4, r0
	bne _0808D834
	strb r5, [r3]
_0808D834:
	adds r1, #0x64
	adds r5, #1
	adds r4, #1
	cmp r4, #1
	ble _0808D80E
_0808D83E:
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r6, r1
	strb r5, [r0]
	cmp r5, #3
	bgt _0808D86A
	movs r2, #0xff
	movs r0, #0x64
	muls r0, r5, r0
	ldr r7, _0808D8E0 @ =0x00000C08
	adds r0, r0, r7
	adds r1, r0, r6
_0808D856:
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	ldrb r0, [r1, #1]
	orrs r0, r2
	strb r0, [r1, #1]
	adds r1, #0x64
	adds r5, #1
	cmp r5, #3
	ble _0808D856
_0808D86A:
	movs r4, #3
_0808D86C:
	subs r4, #1
	cmp r4, #0
	bge _0808D86C
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808D8F2
	ldr r7, _0808D8E4 @ =0x00000C02
	adds r0, r6, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0808D8F2
	movs r4, #1
	ldr r0, _0808D8E8 @ =0x00000C04
	adds r5, r6, r0
	movs r3, #3
_0808D894:
	ldr r2, [r5]
	movs r1, #0
	ldrsh r0, [r2, r1]
	adds r0, r0, r4
	ands r0, r3
	mov r7, r8
	ldr r1, [r7]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0x68
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _0808D8EC
	ldrh r0, [r2]
	adds r0, r0, r4
	ands r0, r3
	strh r0, [r2]
	movs r3, #0
	ldr r7, _0808D8E8 @ =0x00000C04
	adds r5, r6, r7
	ldr r0, _0808D8E4 @ =0x00000C02
	adds r4, r6, r0
	ldr r1, _0808D8E0 @ =0x00000C08
	adds r2, r6, r1
_0808D8C6:
	ldr r0, [r5]
	movs r1, #0
	ldrsb r1, [r2, r1]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r1, r0
	bne _0808D8D6
	strb r3, [r4]
_0808D8D6:
	adds r2, #0x64
	adds r3, #1
	cmp r3, #3
	ble _0808D8C6
	b _0808D8F2
	.align 2, 0
_0808D8E0: .4byte 0x00000C08
_0808D8E4: .4byte 0x00000C02
_0808D8E8: .4byte 0x00000C04
_0808D8EC:
	adds r4, #1
	cmp r4, #3
	ble _0808D894
_0808D8F2:
	ldr r0, _0808D904 @ =0x00000C03
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808D904: .4byte 0x00000C03

	thumb_func_start FUN_0808d908
FUN_0808d908: @ 0x0808D908
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808d200
	adds r0, r4, #0
	bl FUN_0808d2ac
	bl FUN_082408d0
	movs r2, #4
	ldr r1, _0808D934 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _0808D938 @ =FUN_0808db68
	adds r0, r4, #0
	bl FUN_0808a33c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808D934: .4byte 0x030044BC
_0808D938: .4byte FUN_0808db68

	thumb_func_start FUN_0808d93c
FUN_0808d93c: @ 0x0808D93C
	push {lr}
	adds r3, r0, #0
	ldr r0, _0808D97C @ =0x00000C02
	adds r1, r3, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _0808D984
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808D984
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r3, r2
	ldr r0, [r0]
	movs r2, #0
	ldrsb r2, [r1, r2]
	movs r1, #0x64
	muls r1, r2, r1
	adds r1, r3, r1
	ldr r2, _0808D980 @ =0x00000C09
	adds r1, r1, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl FUN_08064fd8
	b _0808D994
	.align 2, 0
_0808D97C: .4byte 0x00000C02
_0808D980: .4byte 0x00000C09
_0808D984:
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r3, r1
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	bl FUN_08064fd8
_0808D994:
	pop {r0}
	bx r0

	thumb_func_start FUN_0808d998
FUN_0808d998: @ 0x0808D998
	push {lr}
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r1, r0, r2
	ldr r3, [r1]
	ldr r2, _0808D9C4 @ =0x00000D98
	adds r1, r0, r2
	movs r2, #0
	ldrsb r2, [r1, r2]
	movs r1, #0x68
	muls r1, r2, r1
	movs r2, #0xda
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r3, #0
	bl weapon_08064664
	pop {r0}
	bx r0
	.align 2, 0
_0808D9C4: .4byte 0x00000D98

	thumb_func_start FUN_0808d9c8
FUN_0808d9c8: @ 0x0808D9C8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808d268
	adds r0, r4, #0
	bl FUN_0808d998
	adds r0, r4, #0
	bl FUN_0808d93c
	ldr r0, _0808DA08 @ =0x00000C03
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0808d3d4
	bl FUN_082408f4
	ldr r2, _0808DA0C @ =0x030044BC
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808DA10 @ =FUN_0808cf14
	adds r0, r4, #0
	bl FUN_0808a33c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808DA08: .4byte 0x00000C03
_0808DA0C: .4byte 0x030044BC
_0808DA10: .4byte FUN_0808cf14

	thumb_func_start FUN_0808da14
FUN_0808da14: @ 0x0808DA14
	push {lr}
	adds r2, r0, #0
	ldr r0, _0808DA68 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0808DA80
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0808DA80
	ldr r1, [r0, #0x1c]
	cmp r1, #1
	bne _0808DA80
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0808DA80
	ldr r1, _0808DA6C @ =0x00000F3D
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808DA80
	ldr r1, _0808DA70 @ =0x000009FE
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	bhi _0808DA80
	ldr r2, _0808DA74 @ =0x00000201
	ldr r0, _0808DA78 @ =0x030047A4
	ldr r1, _0808DA7C @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _0808DA80
	movs r0, #1
	b _0808DA82
	.align 2, 0
_0808DA68: .4byte 0x030044E0
_0808DA6C: .4byte 0x00000F3D
_0808DA70: .4byte 0x000009FE
_0808DA74: .4byte 0x00000201
_0808DA78: .4byte 0x030047A4
_0808DA7C: .4byte 0x030047A0
_0808DA80:
	movs r0, #0
_0808DA82:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808da88
FUN_0808da88: @ 0x0808DA88
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808da14
	cmp r0, #0
	bne _0808DA98
	movs r0, #0
	b _0808DAA0
_0808DA98:
	adds r0, r4, #0
	bl FUN_0808d908
	movs r0, #1
_0808DAA0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808daa8
FUN_0808daa8: @ 0x0808DAA8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _0808DB50 @ =0x00000C01
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0808DAFA
	subs r0, #1
	strb r0, [r1]
	movs r5, #0
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r2, [r0]
	cmp r5, r2
	bge _0808DAFA
	adds r6, r0, #0
_0808DACC:
	ldr r1, _0808DB54 @ =0x00000C02
	adds r0, r4, r1
	movs r2, #0
	ldrsb r2, [r0, r2]
	ldrb r3, [r6]
	subs r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0808d49c
	movs r1, #0x64
	muls r1, r5, r1
	adds r1, r4, r1
	ldr r2, _0808DB58 @ =0x00000C2E
	adds r1, r1, r2
	strh r0, [r1]
	adds r5, #1
	ldrb r0, [r6]
	cmp r5, r0
	blt _0808DACC
_0808DAFA:
	ldr r2, _0808DB5C @ =0x00000F41
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0808DB46
	subs r0, #1
	strb r0, [r1]
	movs r5, #0
	movs r1, #0xf4
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r2, [r0]
	cmp r5, r2
	bge _0808DB46
	adds r6, r0, #0
_0808DB18:
	ldr r1, _0808DB60 @ =0x00000D98
	adds r0, r4, r1
	movs r2, #0
	ldrsb r2, [r0, r2]
	ldrb r3, [r6]
	ldr r1, _0808DB5C @ =0x00000F41
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0808d49c
	movs r1, #0x68
	muls r1, r5, r1
	adds r1, r4, r1
	ldr r2, _0808DB64 @ =0x00000DC6
	adds r1, r1, r2
	strh r0, [r1]
	adds r5, #1
	ldrb r0, [r6]
	cmp r5, r0
	blt _0808DB18
_0808DB46:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808DB50: .4byte 0x00000C01
_0808DB54: .4byte 0x00000C02
_0808DB58: .4byte 0x00000C2E
_0808DB5C: .4byte 0x00000F41
_0808DB60: .4byte 0x00000D98
_0808DB64: .4byte 0x00000DC6

	thumb_func_start FUN_0808db68
FUN_0808db68: @ 0x0808DB68
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0
	movs r2, #3
	movs r3, #1
	bl FUN_0808a5b0
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #2
	bl FUN_0808a5e0
	ldr r0, _0808DBAC @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _0808DBB8
	ldr r1, _0808DBB0 @ =0x00000C01
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808DBB8
	ldr r2, _0808DBB4 @ =0x00000F41
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808DBB8
	adds r0, r4, #0
	bl FUN_0808d9c8
	b _0808DCA4
	.align 2, 0
_0808DBAC: .4byte 0x030044E0
_0808DBB0: .4byte 0x00000C01
_0808DBB4: .4byte 0x00000F41
_0808DBB8:
	ldr r0, _0808DBF8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0808DC42
	ldr r0, _0808DBFC @ =0x00000C01
	adds r7, r4, r0
	ldrb r0, [r7]
	cmp r0, #0
	bne _0808DC42
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r6, r4, r1
	ldrb r0, [r6]
	cmp r0, #1
	bls _0808DC42
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r4, r2
	ldr r0, [r0]
	ldr r1, _0808DC00 @ =0x00000285
	adds r0, r0, r1
	ldrb r5, [r0]
	cmp r5, #0
	beq _0808DC04
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0808DC42
	.align 2, 0
_0808DBF8: .4byte 0x030044E0
_0808DBFC: .4byte 0x00000C01
_0808DC00: .4byte 0x00000285
_0808DC04:
	ldr r0, _0808DCB8 @ =0x0000010B
	bl PlaySound_082406e0
	ldr r2, _0808DCBC @ =0x00000C02
	adds r1, r4, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r6, [r6]
	cmp r0, r6
	blt _0808DC20
	strb r5, [r1]
_0808DC20:
	ldr r2, _0808DCC0 @ =0x00000C04
	adds r0, r4, r2
	ldr r2, [r0]
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r0, #0x64
	muls r0, r1, r0
	adds r0, r4, r0
	ldr r1, _0808DCC4 @ =0x00000C08
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r2]
	movs r0, #8
	strb r0, [r7]
_0808DC42:
	ldr r0, _0808DCC8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808DCA4
	ldr r2, _0808DCCC @ =0x00000F41
	adds r7, r4, r2
	ldrb r6, [r7]
	cmp r6, #0
	bne _0808DCA4
	movs r0, #0xf4
	lsls r0, r0, #4
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #1
	bls _0808DCA4
	ldr r0, _0808DCB8 @ =0x0000010B
	bl PlaySound_082406e0
	ldr r1, _0808DCD0 @ =0x00000D98
	adds r2, r4, r1
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r5, [r5]
	cmp r0, r5
	blt _0808DC82
	strb r6, [r2]
_0808DC82:
	ldr r0, _0808DCD4 @ =0x030046A0
	ldr r1, [r0]
	adds r1, #0x58
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	movs r0, #0x68
	muls r0, r2, r0
	adds r0, r4, r0
	ldr r2, _0808DCD8 @ =0x00000D9C
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	movs r0, #8
	strb r0, [r7]
_0808DCA4:
	adds r0, r4, #0
	bl FUN_0808daa8
	adds r0, r4, #0
	bl FUN_0808d1a8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808DCB8: .4byte 0x0000010B
_0808DCBC: .4byte 0x00000C02
_0808DCC0: .4byte 0x00000C04
_0808DCC4: .4byte 0x00000C08
_0808DCC8: .4byte 0x030044E0
_0808DCCC: .4byte 0x00000F41
_0808DCD0: .4byte 0x00000D98
_0808DCD4: .4byte 0x030046A0
_0808DCD8: .4byte 0x00000D9C

	thumb_func_start FUN_0808dcdc
FUN_0808dcdc: @ 0x0808DCDC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov r8, r0
	ldr r2, _0808DD90 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #8
	orrs r0, r1
	ldr r4, _0808DD94 @ =0x0000FFFF
	ands r0, r4
	movs r3, #0x88
	lsls r3, r3, #0x10
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x18]
	ands r0, r2
	movs r1, #0xd8
	orrs r0, r1
	ands r0, r4
	orrs r0, r3
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	movs r5, #0
	mov r7, r8
	adds r7, #0xa0
	ldr r0, _0808DD98 @ =0x00010011
	mov sl, r0
	movs r6, #0
	movs r1, #0x3c
	mov sb, r1
_0808DD2C:
	movs r0, #0x64
	adds r4, r5, #0
	muls r4, r0, r4
	add r4, r8
	ldr r0, _0808DD9C @ =0x00000C0C
	adds r4, r4, r0
	str r6, [sp]
	str r6, [sp, #4]
	mov r1, sb
	str r1, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0xb6
	mov r3, sl
	bl FUN_0822f3fc
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0808ba0c
	movs r0, #0x68
	muls r0, r5, r0
	add r0, r8
	ldr r1, _0808DDA0 @ =0x00000DA4
	adds r0, r0, r1
	str r6, [sp]
	str r6, [sp, #4]
	mov r1, sb
	str r1, [sp, #8]
	add r1, sp, #0x18
	str r1, [sp, #0xc]
	adds r1, r7, #0
	movs r2, #1
	mov r3, sl
	bl FUN_0822f3fc
	adds r5, #1
	cmp r5, #3
	ble _0808DD2C
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808DD90: .4byte 0xFFFF0000
_0808DD94: .4byte 0x0000FFFF
_0808DD98: .4byte 0x00010011
_0808DD9C: .4byte 0x00000C0C
_0808DDA0: .4byte 0x00000DA4

	thumb_func_start FUN_0808dda4
FUN_0808dda4: @ 0x0808DDA4
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_0808DDAA:
	movs r0, #0x64
	muls r0, r4, r0
	adds r0, r0, r5
	ldr r1, _0808DDD4 @ =0x00000C0C
	adds r0, r0, r1
	bl FUN_0822f1c0
	movs r0, #0x68
	muls r0, r4, r0
	adds r0, r0, r5
	ldr r1, _0808DDD8 @ =0x00000DA4
	adds r0, r0, r1
	bl FUN_0822f1c0
	adds r4, #1
	cmp r4, #3
	ble _0808DDAA
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808DDD4: .4byte 0x00000C0C
_0808DDD8: .4byte 0x00000DA4

	thumb_func_start FUN_0808dddc
FUN_0808dddc: @ 0x0808DDDC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808dcdc
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0808DE2A
	adds r0, r4, #0
	bl FUN_0808d5cc
	adds r0, r4, #0
	bl FUN_0808d774
	adds r0, r4, #0
	bl FUN_0808d4dc
	adds r0, r4, #0
	bl FUN_0808d564
	ldr r0, _0808DE20 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _0808DE24
	adds r0, r4, #0
	bl FUN_0808d39c
	b _0808DE2A
	.align 2, 0
_0808DE20: .4byte 0x030047A4
_0808DE24:
	adds r0, r4, #0
	bl FUN_0808d3d4
_0808DE2A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808de30
FUN_0808de30: @ 0x0808DE30
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808d5cc
	adds r0, r4, #0
	bl FUN_0808d4dc
	adds r0, r4, #0
	bl FUN_0808d3d4
	adds r0, r4, #0
	bl FUN_0808d998
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808de50
FUN_0808de50: @ 0x0808DE50
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808d774
	adds r0, r4, #0
	bl FUN_0808d564
	adds r0, r4, #0
	bl FUN_0808d3d4
	adds r0, r4, #0
	bl FUN_0808d93c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808de70
FUN_0808de70: @ 0x0808DE70
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r2, _0808DF54 @ =0x030044E0
	ldrh r1, [r2, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	mov r8, r2
	cmp r0, #0
	beq _0808DEDC
	ldr r0, _0808DF58 @ =0x00000C01
	adds r7, r4, r0
	ldrb r6, [r7]
	cmp r6, #0
	bne _0808DEDC
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #1
	bls _0808DEDC
	ldr r0, _0808DF5C @ =0x0000010B
	bl PlaySound_082406e0
	ldr r2, _0808DF60 @ =0x00000C02
	adds r1, r4, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r5, [r5]
	cmp r0, r5
	blt _0808DEBA
	strb r6, [r1]
_0808DEBA:
	ldr r2, _0808DF64 @ =0x00000C04
	adds r0, r4, r2
	ldr r2, [r0]
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r0, #0x64
	muls r0, r1, r0
	adds r0, r4, r0
	ldr r1, _0808DF68 @ =0x00000C08
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r2]
	movs r0, #8
	strb r0, [r7]
_0808DEDC:
	mov r2, r8
	ldrh r1, [r2, #2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808DF3E
	ldr r0, _0808DF6C @ =0x00000F41
	adds r7, r4, r0
	ldrb r6, [r7]
	cmp r6, #0
	bne _0808DF3E
	movs r1, #0xf4
	lsls r1, r1, #4
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #1
	bls _0808DF3E
	ldr r0, _0808DF5C @ =0x0000010B
	bl PlaySound_082406e0
	ldr r0, _0808DF70 @ =0x00000D98
	adds r2, r4, r0
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r5, [r5]
	cmp r0, r5
	blt _0808DF1C
	strb r6, [r2]
_0808DF1C:
	ldr r0, _0808DF74 @ =0x030046A0
	ldr r1, [r0]
	adds r1, #0x58
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	movs r0, #0x68
	muls r0, r2, r0
	adds r0, r4, r0
	ldr r2, _0808DF78 @ =0x00000D9C
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	movs r0, #8
	strb r0, [r7]
_0808DF3E:
	adds r0, r4, #0
	bl FUN_0808daa8
	adds r0, r4, #0
	bl FUN_0808d1a8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808DF54: .4byte 0x030044E0
_0808DF58: .4byte 0x00000C01
_0808DF5C: .4byte 0x0000010B
_0808DF60: .4byte 0x00000C02
_0808DF64: .4byte 0x00000C04
_0808DF68: .4byte 0x00000C08
_0808DF6C: .4byte 0x00000F41
_0808DF70: .4byte 0x00000D98
_0808DF74: .4byte 0x030046A0
_0808DF78: .4byte 0x00000D9C

	thumb_func_start FUN_0808df7c
FUN_0808df7c: @ 0x0808DF7C
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_0808d39c
	ldr r0, _0808DFC0 @ =0x00000D98
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	movs r3, #0x68
	muls r0, r3, r0
	ldr r2, _0808DFC4 @ =0x00000DAC
	adds r1, r4, r2
	adds r1, r1, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0
	ldrsb r0, [r5, r0]
	muls r0, r3, r0
	adds r0, r0, r4
	ldr r1, _0808DFC8 @ =0x00000DA4
	adds r0, r0, r1
	adds r4, #0xa0
	adds r1, r4, #0
	movs r2, #0
	movs r3, #1
	bl FUN_0822f3cc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808DFC0: .4byte 0x00000D98
_0808DFC4: .4byte 0x00000DAC
_0808DFC8: .4byte 0x00000DA4

	thumb_func_start FUN_0808dfcc
FUN_0808dfcc: @ 0x0808DFCC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808E000 @ =0x030044BC
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0808DFF8
	ldr r1, _0808E004 @ =0x000009FE
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	bhi _0808DFF8
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #1
	bl FUN_0808a610
	adds r0, r4, #0
	bl FUN_0808daa8
_0808DFF8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808E000: .4byte 0x030044BC
_0808E004: .4byte 0x000009FE

	thumb_func_start FUN_0808e008
FUN_0808e008: @ 0x0808E008
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808E040 @ =0x030044BC
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0808E0D6
	ldr r1, _0808E044 @ =0x000009FE
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	bhi _0808E0D6
	adds r0, r4, #0
	bl FUN_0808de70
	ldr r2, _0808E048 @ =0x00000A16
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0x3f
	bhi _0808E04C
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #1
	bl FUN_0808a610
	b _0808E058
	.align 2, 0
_0808E040: .4byte 0x030044BC
_0808E044: .4byte 0x000009FE
_0808E048: .4byte 0x00000A16
_0808E04C:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #1
	bl FUN_0808a5b0
_0808E058:
	ldr r0, _0808E084 @ =0x00000A16
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bls _0808E06E
	movs r0, #0
	strh r0, [r1]
_0808E06E:
	ldr r0, _0808E088 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0808E090
	ldr r1, _0808E08C @ =FUN_0808dfcc
	adds r0, r4, #0
	bl FUN_0808a33c
	b _0808E0D6
	.align 2, 0
_0808E084: .4byte 0x00000A16
_0808E088: .4byte 0x030044E0
_0808E08C: .4byte FUN_0808dfcc
_0808E090:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0808E0D6
	bl FUN_08050dac
	ldr r2, _0808E0BC @ =0x000009F9
	adds r1, r4, r2
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808E0C4
	ldr r1, _0808E0C0 @ =0x00000A34
	adds r0, r4, r1
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #0x46
	movs r3, #1
	bl FUN_0822f3cc
	b _0808E0D6
	.align 2, 0
_0808E0BC: .4byte 0x000009F9
_0808E0C0: .4byte 0x00000A34
_0808E0C4:
	ldr r1, _0808E0DC @ =0x00000A34
	adds r0, r4, r1
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #0x47
	movs r3, #1
	bl FUN_0822f3cc
_0808E0D6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808E0DC: .4byte 0x00000A34

	thumb_func_start FUN_0808e0e0
FUN_0808e0e0: @ 0x0808E0E0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r1, #0
	adds r6, r2, #0
	adds r4, r3, #0
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [sp, #8]
	movs r0, #0
	mov r8, r0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0808a420
	adds r4, r0, #0
	movs r6, #0
	ldr r1, _0808E13C @ =0xFFFFD000
	adds r7, r1, #0
	mov r5, sp
_0808E128:
	ldr r0, [r5]
	cmp r0, #0
	ble _0808E140
	movs r1, #1
	mov r8, r1
	movs r1, #0
	bl FUN_0808a440
	orrs r0, r7
	b _0808E15A
	.align 2, 0
_0808E13C: .4byte 0xFFFFD000
_0808E140:
	mov r1, r8
	cmp r1, #0
	bne _0808E14A
	cmp r6, #2
	bne _0808E154
_0808E14A:
	movs r1, #0
	bl FUN_0808a440
	orrs r0, r7
	b _0808E15A
_0808E154:
	movs r1, #0xd0
	lsls r1, r1, #8
	adds r0, r1, #0
_0808E15A:
	strh r0, [r4]
	adds r4, #2
	adds r5, #4
	adds r6, #1
	cmp r6, #2
	ble _0808E128
	ldr r1, _0808E178 @ =0x0000D07B
	adds r0, r1, #0
	strh r0, [r4]
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808E178: .4byte 0x0000D07B

	thumb_func_start FUN_0808e17c
FUN_0808e17c: @ 0x0808E17C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0x13
	movs r2, #3
	bl FUN_0808a420
	ldr r2, _0808E1B4 @ =0x0000D04D
	adds r1, r2, #0
	strh r1, [r0]
	adds r0, #2
	adds r2, #1
	adds r1, r2, #0
	strh r1, [r0]
	adds r2, #0xd
	adds r1, r2, #0
	strh r1, [r0, #2]
	bl FUN_08050d64
	adds r3, r0, #0
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #3
	bl FUN_0808e0e0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808E1B4: .4byte 0x0000D04D

	thumb_func_start FUN_0808e1b8
FUN_0808e1b8: @ 0x0808E1B8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0x14
	movs r2, #4
	bl FUN_0808a420
	ldr r2, _0808E1F0 @ =0x0000D00F
	adds r1, r2, #0
	strh r1, [r0]
	adds r0, #2
	adds r2, #1
	adds r1, r2, #0
	strh r1, [r0]
	adds r2, #0x4b
	adds r1, r2, #0
	strh r1, [r0, #2]
	bl FUN_08050d7c
	adds r3, r0, #0
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #4
	bl FUN_0808e0e0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808E1F0: .4byte 0x0000D00F

	thumb_func_start FUN_0808e1f4
FUN_0808e1f4: @ 0x0808E1F4
	push {r4, r5, lr}
	movs r4, #0
	movs r0, #0xd0
	lsls r0, r0, #8
	adds r5, r0, #0
_0808E1FE:
	adds r2, r4, #0
	adds r2, #0x11
	movs r0, #0
	movs r1, #9
	bl FUN_0808a420
	adds r2, r4, #1
	movs r1, #0xb
_0808E20E:
	strh r5, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0808E20E
	adds r4, r2, #0
	cmp r4, #1
	ble _0808E1FE
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808e224
FUN_0808e224: @ 0x0808E224
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r0, #0x9e
	lsls r0, r0, #4
	adds r6, r4, r0
	ldr r0, [r6]
	cmp r0, #0
	bne _0808E236
	b _0808E3F0
_0808E236:
	ldr r1, _0808E2C8 @ =0x000009FE
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #2
	bls _0808E242
	b _0808E3F0
_0808E242:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #1
	bl FUN_0808a610
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #2
	bl FUN_0808a768
	adds r0, r4, #0
	bl FUN_0808e1f4
	adds r0, r4, #0
	bl FUN_0808afac
	ldrb r1, [r5]
	adds r0, r4, #0
	bl FUN_0808abec
	adds r0, r4, #0
	bl FUN_0808b1bc
	adds r0, r4, #0
	bl FUN_0808e17c
	adds r0, r4, #0
	bl FUN_0808e1b8
	ldr r1, [r6]
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0808E294
	b _0808E3F0
_0808E294:
	ldr r3, _0808E2CC @ =0x00000282
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808E334
	ldr r1, _0808E2D0 @ =0x00000C03
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808E2DC
	ldr r2, _0808E2D4 @ =0x00000C02
	adds r0, r4, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	muls r0, r1, r0
	adds r0, r0, r4
	ldr r3, _0808E2D8 @ =0x00000C0C
	adds r0, r0, r3
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0xc8
	movs r3, #1
	bl FUN_0822f3cc
	b _0808E310
	.align 2, 0
_0808E2C8: .4byte 0x000009FE
_0808E2CC: .4byte 0x00000282
_0808E2D0: .4byte 0x00000C03
_0808E2D4: .4byte 0x00000C02
_0808E2D8: .4byte 0x00000C0C
_0808E2DC:
	cmp r0, #0x1e
	bne _0808E310
	ldr r1, _0808E328 @ =0x00000C02
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r2, r4
	ldr r3, _0808E32C @ =0x00000C0C
	adds r0, r0, r3
	adds r1, r4, #0
	adds r1, #0xa0
	adds r2, r4, r2
	subs r3, #3
	adds r2, r2, r3
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl FUN_0822f3cc
_0808E310:
	ldr r0, _0808E330 @ =0x00000C03
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3b
	bls _0808E3F0
	movs r0, #0
	strb r0, [r1]
	b _0808E3F0
	.align 2, 0
_0808E328: .4byte 0x00000C02
_0808E32C: .4byte 0x00000C0C
_0808E330: .4byte 0x00000C03
_0808E334:
	ldr r2, _0808E384 @ =0x00000283
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808E3C0
	ldr r3, _0808E388 @ =0x000009EE
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _0808E38C @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808E398
	ldr r3, _0808E390 @ =0x00000C02
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r2, r4
	ldr r1, _0808E394 @ =0x00000C0C
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xa0
	adds r2, r4, r2
	adds r3, #7
	adds r2, r2, r3
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	b _0808E3B0
	.align 2, 0
_0808E384: .4byte 0x00000283
_0808E388: .4byte 0x000009EE
_0808E38C: .4byte 0x0000FFFF
_0808E390: .4byte 0x00000C02
_0808E394: .4byte 0x00000C0C
_0808E398:
	ldr r1, _0808E3B8 @ =0x00000C02
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	muls r0, r1, r0
	adds r0, r0, r4
	ldr r2, _0808E3BC @ =0x00000C0C
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0xc9
_0808E3B0:
	movs r3, #1
	bl FUN_0822f3cc
	b _0808E3F0
	.align 2, 0
_0808E3B8: .4byte 0x00000C02
_0808E3BC: .4byte 0x00000C0C
_0808E3C0:
	ldr r3, _0808E3F8 @ =0x00000C02
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r2, r4
	ldr r1, _0808E3FC @ =0x00000C0C
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xa0
	adds r2, r4, r2
	adds r3, #7
	adds r2, r2, r3
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl FUN_0822f3cc
_0808E3F0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808E3F8: .4byte 0x00000C02
_0808E3FC: .4byte 0x00000C0C

	thumb_func_start FUN_0808e400
FUN_0808e400: @ 0x0808E400
	push {lr}
	adds r2, r0, #0
	ldr r0, _0808E41C @ =0x030044BC
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0808E416
	adds r0, r2, #0
	bl FUN_0808e224
_0808E416:
	pop {r0}
	bx r0
	.align 2, 0
_0808E41C: .4byte 0x030044BC

	thumb_func_start FUN_0808e420
FUN_0808e420: @ 0x0808E420
	push {r4, r5, lr}
	ldr r0, _0808E474 @ =0x0300013C
	ldr r5, [r0]
	cmp r5, #0
	beq _0808E4D8
	adds r0, r5, #0
	bl FUN_0808d200
	adds r0, r5, #0
	bl FUN_0808d5cc
	adds r0, r5, #0
	bl FUN_0808d4dc
	adds r0, r5, #0
	bl FUN_0808d774
	adds r0, r5, #0
	bl FUN_0808d564
	adds r0, r5, #0
	bl FUN_0808d2ac
	ldr r1, _0808E478 @ =0x000009F9
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	bl FUN_08050d94
	cmp r0, #0
	beq _0808E4A0
	bl FUN_08050de8
	cmp r0, #0
	bne _0808E480
	ldr r2, _0808E47C @ =0x00000A3C
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _0808E4A0
	.align 2, 0
_0808E474: .4byte 0x0300013C
_0808E478: .4byte 0x000009F9
_0808E47C: .4byte 0x00000A3C
_0808E480:
	ldr r0, _0808E4E0 @ =0x00000A3C
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808E4E4 @ =0x00000A34
	adds r0, r5, r1
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #0x47
	movs r3, #1
	bl FUN_0822f3cc
_0808E4A0:
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r2, _0808E4E8 @ =0x0000036A
	adds r1, r0, r2
	ldrh r1, [r1]
	subs r2, #2
	adds r0, r0, r2
	movs r4, #0
	strh r1, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #3
	movs r3, #2
	bl FUN_0808a768
	movs r0, #0x86
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _0808E4EC @ =0x00000A16
	adds r0, r5, r1
	strh r4, [r0]
	ldr r1, _0808E4F0 @ =FUN_0808e008
	adds r0, r5, #0
	bl FUN_0808a33c
_0808E4D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808E4E0: .4byte 0x00000A3C
_0808E4E4: .4byte 0x00000A34
_0808E4E8: .4byte 0x0000036A
_0808E4EC: .4byte 0x00000A16
_0808E4F0: .4byte FUN_0808e008

	thumb_func_start FUN_0808e4f4
FUN_0808e4f4: @ 0x0808E4F4
	push {r4, lr}
	ldr r0, _0808E530 @ =0x0300013C
	ldr r4, [r0]
	cmp r4, #0
	beq _0808E528
	bl FUN_0808d268
	ldr r0, _0808E534 @ =0x00000A3C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	adds r0, r4, #0
	bl FUN_0808d998
	adds r0, r4, #0
	bl FUN_0808d93c
	adds r0, r4, #0
	bl FUN_0808d3d4
	ldr r1, _0808E538 @ =FUN_0808e400
	adds r0, r4, #0
	bl FUN_0808a33c
_0808E528:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808E530: .4byte 0x0300013C
_0808E534: .4byte 0x00000A3C
_0808E538: .4byte FUN_0808e400

	thumb_func_start FUN_0808e53c
FUN_0808e53c: @ 0x0808E53C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r3, #2
	rsbs r3, r3, #0
	ldr r0, _0808E594 @ =0x0000366C
	adds r1, r5, r0
	movs r2, #2
_0808E54A:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0808E54A
	ldr r1, _0808E598 @ =0x00003664
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0xc0
	ldr r2, _0808E59C @ =0x0000401E
	adds r1, r5, r2
	ldrb r2, [r1]
	adds r2, #7
	adds r1, r4, #0
	movs r3, #1
	bl FUN_0822f3cc
	ldr r1, _0808E5A0 @ =0x000036C4
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #8
	movs r3, #1
	bl FUN_0822f3cc
	ldr r2, _0808E5A4 @ =0x00003724
	adds r0, r5, r2
	adds r1, r4, #0
	movs r2, #8
	movs r3, #1
	bl FUN_0822f3cc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808E594: .4byte 0x0000366C
_0808E598: .4byte 0x00003664
_0808E59C: .4byte 0x0000401E
_0808E5A0: .4byte 0x000036C4
_0808E5A4: .4byte 0x00003724

	thumb_func_start FUN_0808e5a8
FUN_0808e5a8: @ 0x0808E5A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r1, _0808E5D4 @ =0x00004022
	adds r0, r7, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _0808E5D8
	movs r2, #0xc0
	adds r2, r2, r7
	mov sl, r2
	movs r1, #0
	add r0, sp, #0xc
_0808E5CA:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _0808E5CA
	b _0808E61A
	.align 2, 0
_0808E5D4: .4byte 0x00004022
_0808E5D8:
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	subs r4, r4, r1
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp, #4]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #8]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r4, r1
	str r1, [sp, #0xc]
	movs r0, #0xc0
	adds r0, r0, r7
	mov sl, r0
_0808E61A:
	mov sb, sp
	ldr r1, _0808E688 @ =0x00003784
	adds r4, r7, r1
	ldr r6, _0808E68C @ =0x00002820
	movs r5, #3
_0808E624:
	ldr r2, _0808E690 @ =0x00000F6C
	adds r1, r7, r2
	adds r1, r1, r6
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	mov r8, r2
	ands r0, r2
	str r0, [r1]
	mov r0, sb
	adds r0, #4
	mov sb, r0
	subs r0, #4
	ldm r0!, {r2}
	adds r2, #8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, sl
	movs r3, #1
	bl FUN_0822f3cc
	adds r4, #0x60
	adds r6, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0808E624
	ldr r2, _0808E694 @ =0x0000390C
	adds r1, r7, r2
	ldr r0, [r1]
	mov r2, r8
	ands r0, r2
	str r0, [r1]
	ldr r1, _0808E698 @ =0x00004022
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r2, _0808E69C @ =0x0000401E
	adds r0, r7, r2
	ldrb r0, [r0]
	adds r4, r1, #0
	muls r4, r0, r4
	cmp r4, #0
	bne _0808E6A0
	movs r1, #0
	add r0, sp, #0xc
_0808E67E:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _0808E67E
	b _0808E6DC
	.align 2, 0
_0808E688: .4byte 0x00003784
_0808E68C: .4byte 0x00002820
_0808E690: .4byte 0x00000F6C
_0808E694: .4byte 0x0000390C
_0808E698: .4byte 0x00004022
_0808E69C: .4byte 0x0000401E
_0808E6A0:
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	subs r4, r4, r1
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp, #4]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #8]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r4, r1
	str r1, [sp, #0xc]
_0808E6DC:
	mov r8, sp
	ldr r0, _0808E72C @ =0x00003964
	adds r4, r7, r0
	movs r6, #0xa8
	lsls r6, r6, #6
	movs r5, #3
_0808E6E8:
	ldr r1, _0808E730 @ =0x00000F6C
	adds r2, r7, r1
	adds r2, r2, r6
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	mov r0, r8
	adds r0, #4
	mov r8, r0
	subs r0, #4
	ldm r0!, {r2}
	adds r2, #8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, sl
	movs r3, #1
	bl FUN_0822f3cc
	adds r4, #0x60
	adds r6, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0808E6E8
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808E72C: .4byte 0x00003964
_0808E730: .4byte 0x00000F6C

	thumb_func_start FUN_0808e734
FUN_0808e734: @ 0x0808E734
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _0808E820 @ =0xFFFF0000
	ands r0, r5
	movs r1, #0x90
	orrs r0, r1
	ldr r1, _0808E824 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xe
	adds r5, r0, #0
	orrs r5, r1
	ldr r0, _0808E828 @ =0x030046A0
	ldr r1, [r0]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r2, _0808E82C @ =0x00004022
	adds r0, r7, r2
	ldrh r2, [r0]
	ldr r3, _0808E830 @ =0x0000401E
	adds r0, r7, r3
	ldrb r0, [r0]
	muls r0, r2, r0
	ldr r4, [r1]
	adds r4, r4, r0
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	subs r4, r4, r1
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp, #4]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #8]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [sp, #0xc]
	mov sl, sp
	ldr r0, _0808E834 @ =0x00002164
	adds r4, r7, r0
	movs r2, #0x90
	lsls r2, r2, #5
	mov sb, r2
	movs r3, #3
	mov r8, r3
_0808E7BE:
	ldr r0, _0808E838 @ =0x00000F6C
	adds r2, r7, r0
	add r2, sb
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	str r5, [r4, #0x20]
	str r6, [r4, #0x24]
	mov r3, sl
	adds r3, #4
	mov sl, r3
	subs r3, #4
	ldm r3!, {r2}
	adds r2, #0x14
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r7, #0
	adds r1, #0x60
	movs r3, #1
	bl FUN_0822f3cc
	adds r1, r5, #0
	adds r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _0808E820 @ =0xFFFF0000
	ands r0, r5
	adds r5, r0, #0
	orrs r5, r1
	adds r4, #0x60
	movs r0, #0x60
	add sb, r0
	movs r2, #1
	rsbs r2, r2, #0
	add r8, r2
	mov r3, r8
	cmp r3, #0
	bge _0808E7BE
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808E820: .4byte 0xFFFF0000
_0808E824: .4byte 0x0000FFFF
_0808E828: .4byte 0x030046A0
_0808E82C: .4byte 0x00004022
_0808E830: .4byte 0x0000401E
_0808E834: .4byte 0x00002164
_0808E838: .4byte 0x00000F6C

	thumb_func_start FUN_0808e83c
FUN_0808e83c: @ 0x0808E83C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrh r2, [r0]
	ldr r3, _0808E868 @ =0x00004022
	adds r0, r4, r3
	ldrh r0, [r0]
	adds r2, r2, r0
	ldr r0, _0808E86C @ =0x0000036A
	adds r1, r1, r0
	ldrh r3, [r1]
	cmp r2, #0
	bne _0808E870
	movs r3, #0
	b _0808E882
	.align 2, 0
_0808E868: .4byte 0x00004022
_0808E86C: .4byte 0x0000036A
_0808E870:
	subs r1, r2, #1
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	subs r0, r0, r1
	subs r1, r3, #1
	bl Div
	adds r3, r0, #1
_0808E882:
	ldr r1, _0808E8A8 @ =0x000028EC
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r1, r3, #0
	subs r1, #0x98
	ldr r2, _0808E8AC @ =0x00002904
	adds r0, r4, r2
	strh r1, [r0]
	ldr r3, _0808E8B0 @ =0x00002906
	adds r1, r4, r3
	ldr r0, _0808E8B4 @ =0x0000FFD8
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808E8A8: .4byte 0x000028EC
_0808E8AC: .4byte 0x00002904
_0808E8B0: .4byte 0x00002906
_0808E8B4: .4byte 0x0000FFD8

	thumb_func_start FUN_0808e8b8
FUN_0808e8b8: @ 0x0808E8B8
	push {lr}
	asrs r0, r0, #2
	cmp r0, #1
	beq _0808E8D2
	cmp r0, #1
	ble _0808E8D6
	cmp r0, #2
	beq _0808E8CE
	cmp r0, #3
	beq _0808E8D2
	b _0808E8D6
_0808E8CE:
	movs r0, #2
	b _0808E8D8
_0808E8D2:
	movs r0, #1
	b _0808E8D8
_0808E8D6:
	movs r0, #0
_0808E8D8:
	pop {r1}
	bx r1

	thumb_func_start FUN_0808e8dc
FUN_0808e8dc: @ 0x0808E8DC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, _0808E968 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0808E984
	ldr r0, _0808E96C @ =0x030046A0
	ldr r1, [r0]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r2, _0808E970 @ =0x00004022
	adds r5, r6, r2
	ldrh r3, [r5]
	adds r4, r3, #1
	subs r2, #4
	adds r0, r6, r2
	ldrb r0, [r0]
	adds r2, r4, #0
	muls r2, r0, r2
	ldr r0, [r1]
	adds r0, r0, r2
	ldr r1, _0808E974 @ =0x0000270F
	cmp r0, r1
	bgt _0808E984
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrh r0, [r0]
	adds r0, r0, r3
	adds r2, #2
	adds r1, r1, r2
	ldrh r1, [r1]
	cmp r0, r1
	bge _0808E984
	strh r4, [r5]
	ldr r0, _0808E978 @ =0x0000037D
	bl PlaySound_082406e0
	adds r0, r6, #0
	bl FUN_0808e83c
	adds r0, r6, #0
	bl FUN_0808e734
	adds r0, r6, #0
	bl FUN_0808e5a8
	ldr r0, _0808E97C @ =0x00004020
	adds r4, r6, r0
	movs r0, #0x13
	strb r0, [r4]
	ldr r1, _0808E980 @ =0x00004021
	adds r5, r6, r1
	ldrb r0, [r5]
	bl FUN_0808e8b8
	adds r7, r0, #0
	ldrb r0, [r4]
	adds r3, r0, r7
	b _0808E9DC
	.align 2, 0
_0808E968: .4byte 0x030044E0
_0808E96C: .4byte 0x030046A0
_0808E970: .4byte 0x00004022
_0808E974: .4byte 0x0000270F
_0808E978: .4byte 0x0000037D
_0808E97C: .4byte 0x00004020
_0808E980: .4byte 0x00004021
_0808E984:
	ldr r0, _0808E9F0 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0808EA08
	ldr r2, _0808E9F4 @ =0x00004022
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0808EA08
	subs r0, #1
	strh r0, [r1]
	ldr r0, _0808E9F8 @ =0x0000037D
	bl PlaySound_082406e0
	adds r0, r6, #0
	bl FUN_0808e83c
	adds r0, r6, #0
	bl FUN_0808e734
	adds r0, r6, #0
	bl FUN_0808e5a8
	ldr r0, _0808E9FC @ =0x00004020
	adds r4, r6, r0
	movs r0, #0x16
	strb r0, [r4]
	ldr r1, _0808EA00 @ =0x00004021
	adds r5, r6, r1
	ldrb r0, [r5]
	bl FUN_0808e8b8
	adds r7, r0, #0
	ldrb r0, [r4]
	adds r3, r0, r7
	ldr r2, _0808EA04 @ =0x00004024
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0808E9DC
	movs r0, #1
	strh r0, [r1]
_0808E9DC:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _0808EA40
	movs r0, #0
	strb r0, [r5]
	b _0808EA40
	.align 2, 0
_0808E9F0: .4byte 0x030044E0
_0808E9F4: .4byte 0x00004022
_0808E9F8: .4byte 0x0000037D
_0808E9FC: .4byte 0x00004020
_0808EA00: .4byte 0x00004021
_0808EA04: .4byte 0x00004024
_0808EA08:
	ldr r0, _0808EA34 @ =0x00004021
	adds r4, r6, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0808EA3C
	bl FUN_0808e8b8
	adds r7, r0, #0
	ldr r1, _0808EA38 @ =0x00004020
	adds r0, r6, r1
	ldrb r0, [r0]
	adds r3, r0, r7
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _0808EA40
	movs r0, #0
	strb r0, [r4]
	b _0808EA40
	.align 2, 0
_0808EA34: .4byte 0x00004021
_0808EA38: .4byte 0x00004020
_0808EA3C:
	movs r7, #0
	movs r3, #0x12
_0808EA40:
	ldr r0, _0808EAAC @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0808EA78
	ldr r0, _0808EAB0 @ =0x030046A0
	ldr r2, [r0]
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r2, r2, r4
	ldr r1, _0808EAB4 @ =0x00004022
	adds r0, r6, r1
	ldrh r0, [r0]
	adds r0, #1
	ldr r4, _0808EAB8 @ =0x0000401E
	adds r1, r6, r4
	ldrb r1, [r1]
	muls r1, r0, r1
	ldr r0, [r2]
	adds r0, r0, r1
	ldr r1, _0808EABC @ =0x0000270F
	cmp r0, r1
	ble _0808EA78
	ldr r0, _0808EAC0 @ =0x00004024
	adds r1, r6, r0
	movs r0, #0x3c
	strh r0, [r1]
_0808EA78:
	ldr r2, _0808EAC0 @ =0x00004024
	adds r1, r6, r2
	ldrh r0, [r1]
	movs r4, #0xc0
	adds r4, r4, r6
	mov r8, r4
	lsls r5, r3, #0x10
	cmp r0, #0
	beq _0808EB0A
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _0808EAC8
	adds r0, r6, #0
	bl FUN_0808e5a8
	movs r0, #4
	bl FUN_08047a28
	ldr r1, _0808EAC4 @ =0x00004026
	adds r0, r6, r1
	strh r4, [r0]
	b _0808EB0A
	.align 2, 0
_0808EAAC: .4byte 0x030044E0
_0808EAB0: .4byte 0x030046A0
_0808EAB4: .4byte 0x00004022
_0808EAB8: .4byte 0x0000401E
_0808EABC: .4byte 0x0000270F
_0808EAC0: .4byte 0x00004024
_0808EAC4: .4byte 0x00004026
_0808EAC8:
	ldr r2, _0808EB30 @ =0x0000390C
	adds r0, r6, r2
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	movs r4, #1
	ldr r0, _0808EB34 @ =0x0000396C
	adds r2, r6, r0
	ldr r0, _0808EB38 @ =0x0000378C
	adds r1, r6, r0
	movs r3, #3
_0808EAE0:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	adds r2, #0x60
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0808EAE0
	ldr r1, _0808EB3C @ =0x00004026
	adds r4, r6, r1
	ldrh r0, [r4]
	cmp r0, #0
	bne _0808EB0A
	movs r0, #6
	bl FUN_08047a28
	movs r0, #1
	strh r0, [r4]
_0808EB0A:
	ldr r2, _0808EB40 @ =0x00003604
	adds r0, r6, r2
	lsrs r2, r5, #0x10
	mov r1, r8
	movs r3, #1
	bl FUN_0822f3cc
	ldr r4, _0808EB44 @ =0x00000BE4
	adds r0, r6, r4
	ldr r2, _0808EB48 @ =0x00000143
	adds r1, r7, r2
	bl FUN_0822b20c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808EB30: .4byte 0x0000390C
_0808EB34: .4byte 0x0000396C
_0808EB38: .4byte 0x0000378C
_0808EB3C: .4byte 0x00004026
_0808EB40: .4byte 0x00003604
_0808EB44: .4byte 0x00000BE4
_0808EB48: .4byte 0x00000143

	thumb_func_start FUN_0808eb4c
FUN_0808eb4c: @ 0x0808EB4C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_0808b82c
	ldr r1, [r4, #0x2c]
	movs r0, #0
	movs r2, #3
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	ldr r0, _0808EBD0 @ =0x000034EC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808EBD4 @ =0x00003504
	adds r0, r4, r1
	strh r5, [r0]
	ldr r2, _0808EBD8 @ =0x00003506
	adds r0, r4, r2
	strh r5, [r0]
	subs r1, #0x20
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	str r5, [sp]
	movs r2, #7
	movs r3, #2
	bl FUN_082370cc
	adds r0, r4, #0
	bl FUN_0808e53c
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0808b6fc
	ldr r2, _0808EBDC @ =0x00001524
	adds r0, r4, r2
	ldr r1, _0808EBE0 @ =0x0000FFF8
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #1
	bl FUN_08047a28
	ldr r1, _0808EBE4 @ =FUN_0808eeac
	adds r0, r4, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808EBD0: .4byte 0x000034EC
_0808EBD4: .4byte 0x00003504
_0808EBD8: .4byte 0x00003506
_0808EBDC: .4byte 0x00001524
_0808EBE0: .4byte 0x0000FFF8
_0808EBE4: .4byte FUN_0808eeac

	thumb_func_start FUN_0808ebe8
FUN_0808ebe8: @ 0x0808EBE8
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, [r4, #0x2c]
	ldr r0, [r4, #0x3c]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #3
	bl FUN_0808a3c4
	adds r0, r4, #0
	bl FUN_0808eb4c
	ldr r1, _0808EC14 @ =FUN_0808ee50
	adds r0, r4, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808EC14: .4byte FUN_0808ee50

	thumb_func_start FUN_0808ec18
FUN_0808ec18: @ 0x0808EC18
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	bl FUN_0808b82c
	ldr r1, [r7, #0x2c]
	movs r0, #0
	movs r2, #4
	bl FUN_0822c398
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	ldr r0, _0808ED2C @ =0x000034EC
	adds r1, r7, r0
	ldr r0, [r1]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r1]
	ldr r1, _0808ED30 @ =0x000034E4
	adds r0, r7, r1
	adds r6, r7, #0
	adds r6, #0xc0
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #5
	movs r3, #1
	bl FUN_082370cc
	ldr r2, _0808ED34 @ =0x00004022
	adds r0, r7, r2
	strh r4, [r0]
	adds r0, r7, #0
	bl FUN_0808e734
	adds r0, r7, #0
	bl FUN_0808e83c
	ldr r0, _0808ED38 @ =0x00000BB8
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	ldr r2, _0808ED3C @ =0x0000360C
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	ldr r0, _0808ED40 @ =0x00003624
	adds r1, r7, r0
	movs r0, #0x10
	strh r0, [r1]
	adds r2, #0x1a
	adds r1, r7, r2
	ldr r0, _0808ED44 @ =0x0000FFFC
	strh r0, [r1]
	ldr r1, _0808ED48 @ =0x00003604
	adds r0, r7, r1
	adds r1, r6, #0
	movs r2, #0x12
	movs r3, #1
	bl FUN_0822f3cc
	ldr r2, _0808ED4C @ =0x0000390C
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	ldr r1, _0808ED50 @ =0x00003904
	adds r0, r7, r1
	ldr r2, _0808ED54 @ =0x0000401E
	adds r1, r7, r2
	ldrb r2, [r1]
	adds r2, #7
	adds r1, r6, #0
	movs r3, #1
	bl FUN_0822f3cc
	ldr r0, _0808ED58 @ =0x0000396C
	adds r2, r7, r0
	ldr r0, _0808ED5C @ =0x0000378C
	adds r1, r7, r0
	movs r3, #3
_0808ECCA:
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	ldr r0, [r2]
	ands r0, r5
	str r0, [r2]
	adds r2, #0x60
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0808ECCA
	movs r4, #0
	adds r0, r7, #0
	bl FUN_0808e5a8
	ldr r1, _0808ED60 @ =0x00004024
	adds r0, r7, r1
	movs r1, #0
	strh r4, [r0]
	ldr r2, _0808ED64 @ =0x00004026
	adds r0, r7, r2
	strh r4, [r0]
	subs r2, #5
	adds r0, r7, r2
	strb r1, [r0]
	ldr r1, _0808ED48 @ =0x00003604
	adds r0, r7, r1
	adds r1, r7, #0
	adds r1, #0xc0
	movs r2, #0x12
	movs r3, #1
	bl FUN_0822f3cc
	ldr r2, _0808ED68 @ =0x00000BE4
	adds r0, r7, r2
	ldr r1, _0808ED6C @ =0x00000143
	bl FUN_0822b20c
	movs r0, #4
	bl FUN_08047a28
	ldr r1, _0808ED70 @ =FUN_0808ef58
	adds r0, r7, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808ED2C: .4byte 0x000034EC
_0808ED30: .4byte 0x000034E4
_0808ED34: .4byte 0x00004022
_0808ED38: .4byte 0x00000BB8
_0808ED3C: .4byte 0x0000360C
_0808ED40: .4byte 0x00003624
_0808ED44: .4byte 0x0000FFFC
_0808ED48: .4byte 0x00003604
_0808ED4C: .4byte 0x0000390C
_0808ED50: .4byte 0x00003904
_0808ED54: .4byte 0x0000401E
_0808ED58: .4byte 0x0000396C
_0808ED5C: .4byte 0x0000378C
_0808ED60: .4byte 0x00004024
_0808ED64: .4byte 0x00004026
_0808ED68: .4byte 0x00000BE4
_0808ED6C: .4byte 0x00000143
_0808ED70: .4byte FUN_0808ef58

	thumb_func_start FUN_0808ed74
FUN_0808ed74: @ 0x0808ED74
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_0808b82c
	ldr r1, [r4, #0x2c]
	movs r0, #0
	movs r2, #5
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	ldr r0, _0808EDD4 @ =0x000034EC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808EDD8 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	str r5, [sp]
	movs r2, #6
	movs r3, #2
	bl FUN_082370cc
	movs r0, #3
	bl FUN_08047a28
	ldr r0, _0808EDDC @ =0x000002C1
	bl PlaySound_082406e0
	ldr r1, _0808EDE0 @ =0x0808F01D
	adds r0, r4, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808EDD4: .4byte 0x000034EC
_0808EDD8: .4byte 0x000034E4
_0808EDDC: .4byte 0x000002C1
_0808EDE0: .4byte 0x0808F01D

	thumb_func_start FUN_0808ede4
FUN_0808ede4: @ 0x0808EDE4
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_0808b82c
	ldr r1, [r4, #0x2c]
	ldr r0, [r4, #0x3c]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #5
	bl FUN_0808a3c4
	ldr r0, _0808EE44 @ =0x000034EC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808EE48 @ =0x00003504
	adds r0, r4, r1
	movs r2, #0
	strh r2, [r0]
	adds r1, #2
	adds r0, r4, r1
	strh r2, [r0]
	subs r1, #0x22
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	str r2, [sp]
	movs r2, #6
	movs r3, #2
	bl FUN_082370cc
	movs r0, #0xd
	bl FUN_08047a28
	ldr r1, _0808EE4C @ =FUN_0808f0d8
	adds r0, r4, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808EE44: .4byte 0x000034EC
_0808EE48: .4byte 0x00003504
_0808EE4C: .4byte FUN_0808f0d8

	thumb_func_start FUN_0808ee50
FUN_0808ee50: @ 0x0808EE50
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808EE68 @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _0808EE6C
	lsls r0, r0, #2
	movs r1, #0
	bl FUN_0808a458
	b _0808EE74
	.align 2, 0
_0808EE68: .4byte 0x000009EC
_0808EE6C:
	movs r0, #0x40
	movs r1, #0
	bl FUN_0808a458
_0808EE74:
	ldr r1, _0808EEA0 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl FUN_082372cc
	ldr r0, _0808EEA4 @ =0x000009EC
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0808EE9A
	ldr r1, _0808EEA8 @ =FUN_0808eeac
	adds r0, r4, #0
	bl FUN_0808a33c
_0808EE9A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808EEA0: .4byte 0x000034E4
_0808EEA4: .4byte 0x000009EC
_0808EEA8: .4byte FUN_0808eeac

	thumb_func_start FUN_0808eeac
FUN_0808eeac: @ 0x0808EEAC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808EED8 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl FUN_082372cc
	adds r0, r4, #0
	bl FUN_0808b760
	cmp r0, #0
	bne _0808EEE0
	movs r0, #0xde
	bl PlaySound_082406e0
	ldr r1, _0808EEDC @ =0x0808EEF9
	adds r0, r4, #0
	bl FUN_0808a33c
	b _0808EEF0
	.align 2, 0
_0808EED8: .4byte 0x000034E4
_0808EEDC: .4byte 0x0808EEF9
_0808EEE0:
	cmp r0, #1
	bne _0808EEF0
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_0808ec18
_0808EEF0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808EEF8:
	.byte 0x10, 0xB5, 0x04, 0x1C, 0x06, 0x48, 0x21, 0x18
	.byte 0x08, 0x88, 0x0F, 0x28, 0x0A, 0xD8, 0x01, 0x1C, 0x10, 0x20, 0x40, 0x1A, 0x80, 0x00, 0x00, 0x21
	.byte 0xFB, 0xF7, 0xA2, 0xFA, 0x06, 0xE0, 0x00, 0x00, 0xEC, 0x09, 0x00, 0x00, 0x00, 0x20, 0x00, 0x21
	.byte 0xFB, 0xF7, 0x9A, 0xFA, 0x0A, 0x49, 0x60, 0x18, 0x21, 0x1C, 0xC0, 0x31, 0xA8, 0xF1, 0xCE, 0xF9
	.byte 0x08, 0x48, 0x22, 0x18, 0x10, 0x88, 0x41, 0x1C, 0x11, 0x80, 0x00, 0x04, 0x00, 0x0C, 0x0F, 0x28
	.byte 0x02, 0xD9, 0x20, 0x1C, 0x00, 0xF0, 0xD4, 0xF9, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0xE4, 0x34, 0x00, 0x00, 0xEC, 0x09, 0x00, 0x00

	thumb_func_start FUN_0808ef58
FUN_0808ef58: @ 0x0808EF58
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _0808EF88 @ =0x000034E4
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0xc0
	bl FUN_082372cc
	ldr r0, _0808EF8C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808EFF8
	ldr r2, _0808EF90 @ =0x00004022
	adds r6, r5, r2
	ldrh r1, [r6]
	cmp r1, #0
	bne _0808EF94
	movs r0, #0xde
	bl PlaySound_082406e0
	b _0808EFE2
	.align 2, 0
_0808EF88: .4byte 0x000034E4
_0808EF8C: .4byte 0x030044E0
_0808EF90: .4byte 0x00004022
_0808EF94:
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldr r4, _0808EFEC @ =0x030046A0
	ldr r1, [r4]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldrh r2, [r6]
	ldr r0, _0808EFF0 @ =0x0000401E
	adds r3, r5, r0
	ldrb r0, [r3]
	muls r2, r0, r2
	ldr r0, [r1]
	adds r0, r0, r2
	str r0, [r1]
	ldr r0, [r4]
	movs r1, #0xea
	lsls r1, r1, #1
	adds r2, r0, r1
	ldrh r1, [r6]
	ldrb r0, [r3]
	muls r1, r0, r1
	ldr r0, [r2]
	adds r0, r0, r1
	cmp r0, #0
	bge _0808EFDA
	ldr r0, _0808EFF4 @ =0x7FFFFFFF
_0808EFDA:
	str r0, [r2]
	movs r0, #0xdd
	bl PlaySound_082406e0
_0808EFE2:
	adds r0, r5, #0
	bl FUN_0808ed74
	b _0808F014
	.align 2, 0
_0808EFEC: .4byte 0x030046A0
_0808EFF0: .4byte 0x0000401E
_0808EFF4: .4byte 0x7FFFFFFF
_0808EFF8:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0808F00E
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_0808eb4c
	b _0808F014
_0808F00E:
	adds r0, r5, #0
	bl FUN_0808e8dc
_0808F014:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808F01C:
	.byte 0x10, 0xB5, 0x04, 0x1C
	.byte 0x0F, 0x49, 0x60, 0x18, 0x21, 0x1C, 0xC0, 0x31, 0xA8, 0xF1, 0x50, 0xF9, 0x0D, 0x48, 0x21, 0x18
	.byte 0x08, 0x88, 0x01, 0x30, 0x08, 0x80, 0x00, 0x04, 0x00, 0x0C, 0x96, 0x28, 0x28, 0xD9, 0x0A, 0x49
	.byte 0x60, 0x18, 0x00, 0x88, 0x00, 0x28, 0x1F, 0xD0, 0x05, 0x20, 0xB8, 0xF7, 0xED, 0xFC, 0x07, 0x49
	.byte 0x60, 0x18, 0x00, 0x68, 0x00, 0x28, 0x0B, 0xD0, 0x00, 0x21, 0xA2, 0xF1, 0x27, 0xFC, 0x0B, 0xE0
	.byte 0xE4, 0x34, 0x00, 0x00, 0xEC, 0x09, 0x00, 0x00, 0x22, 0x40, 0x00, 0x00, 0x28, 0x40, 0x00, 0x00
	.byte 0x00, 0x20, 0x03, 0x21, 0xB8, 0xF7, 0xE4, 0xFD, 0x02, 0x49, 0x20, 0x1C, 0xFB, 0xF7, 0x5E, 0xF9
	.byte 0x06, 0xE0, 0x00, 0x00, 0x9D, 0xF0, 0x08, 0x08, 0x03, 0x49, 0x20, 0x1C, 0xFB, 0xF7, 0x56, 0xF9
	.byte 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x0D, 0xAE, 0x09, 0x08

	thumb_func_start FUN_0808f09c
FUN_0808f09c: @ 0x0808F09C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808F0CC @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl FUN_082372cc
	ldr r0, _0808F0D0 @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x95
	bls _0808F0C6
	ldr r1, _0808F0D4 @ =FUN_0809ae0c
	adds r0, r4, #0
	bl FUN_0808a33c
_0808F0C6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F0CC: .4byte 0x000034E4
_0808F0D0: .4byte 0x000009EC
_0808F0D4: .4byte FUN_0809ae0c

	thumb_func_start FUN_0808f0d8
FUN_0808f0d8: @ 0x0808F0D8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808F0F8 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl FUN_082372cc
	ldr r1, _0808F0FC @ =0x000009EC
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0xf
	bhi _0808F100
	adds r0, r1, #0
	lsls r0, r0, #2
	b _0808F106
	.align 2, 0
_0808F0F8: .4byte 0x000034E4
_0808F0FC: .4byte 0x000009EC
_0808F100:
	cmp r1, #0x85
	bhi _0808F10E
	movs r0, #0x40
_0808F106:
	movs r1, #0
	bl FUN_0808a458
	b _0808F11C
_0808F10E:
	ldrh r1, [r0]
	movs r0, #0x96
	subs r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0
	bl FUN_0808a458
_0808F11C:
	ldr r1, _0808F13C @ =0x000009EC
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r2, r1, #1
	strh r2, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x95
	bls _0808F134
	adds r0, r4, #0
	bl FUN_0808f2f0
_0808F134:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F13C: .4byte 0x000009EC

	thumb_func_start FUN_0808f140
FUN_0808f140: @ 0x0808F140
	push {lr}
	ldr r0, _0808F158 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0808F15C @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #1
	bgt _0808F160
	movs r0, #9
	b _0808F16C
	.align 2, 0
_0808F158: .4byte 0x030046A0
_0808F15C: .4byte 0x00000942
_0808F160:
	cmp r1, #9
	bgt _0808F16A
	movs r0, #0xb
	subs r0, r0, r1
	b _0808F16C
_0808F16A:
	movs r0, #2
_0808F16C:
	pop {r1}
	bx r1

	thumb_func_start FUN_0808f170
FUN_0808f170: @ 0x0808F170
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08047864
	bl FUN_08049e5c
	bl FUN_08049f84
	movs r0, #1
	movs r1, #0xf
	movs r2, #0x1c
	movs r3, #4
	bl FUN_08047b8c
	ldr r0, [r4, #0x54]
	bl FUN_080478f0
	movs r0, #1
	bl FUN_080477e4
	ldr r1, _0808F1AC @ =0x0000401F
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808F1B0
	adds r0, r4, #0
	bl FUN_0808ede4
	b _0808F1B6
	.align 2, 0
_0808F1AC: .4byte 0x0000401F
_0808F1B0:
	adds r0, r4, #0
	bl FUN_0808ebe8
_0808F1B6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808f1bc
FUN_0808f1bc: @ 0x0808F1BC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _0808F208 @ =0x00003544
	adds r0, r4, r1
	adds r6, r4, #0
	adds r6, #0xc0
	ldr r1, _0808F20C @ =0x0000401C
	adds r5, r4, r1
	ldrb r2, [r5]
	adds r2, #0x19
	adds r1, r6, #0
	movs r3, #1
	bl FUN_0822f3cc
	ldr r1, _0808F210 @ =0x000035A4
	adds r0, r4, r1
	ldrb r1, [r5]
	movs r2, #0x1c
	subs r2, r2, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r6, #0
	movs r3, #1
	bl FUN_0822f3cc
	ldr r0, _0808F214 @ =0x00003624
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r5]
	lsls r0, r0, #5
	ldr r1, _0808F218 @ =0x00003626
	adds r4, r4, r1
	strh r0, [r4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808F208: .4byte 0x00003544
_0808F20C: .4byte 0x0000401C
_0808F210: .4byte 0x000035A4
_0808F214: .4byte 0x00003624
_0808F218: .4byte 0x00003626

	thumb_func_start FUN_0808f21c
FUN_0808f21c: @ 0x0808F21C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_08047864
	bl FUN_08049e5c
	bl FUN_08049f84
	movs r0, #1
	movs r1, #1
	movs r2, #0x1c
	movs r3, #6
	bl FUN_08047b8c
	ldr r0, [r4, #0x54]
	bl FUN_080478f0
	movs r0, #1
	bl FUN_080477e4
	ldr r1, [r4, #0x18]
	ldr r0, [r4, #0x30]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #2
	bl FUN_0808a3c4
	adds r0, r4, #0
	bl FUN_0808b82c
	ldr r0, _0808F2D4 @ =0x000034EC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _0808F2D8 @ =0x00003504
	adds r1, r4, r0
	movs r0, #0
	mov r8, r0
	ldr r0, _0808F2DC @ =0x0000FFA8
	strh r0, [r1]
	ldr r0, _0808F2E0 @ =0x00003506
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
	ldr r1, _0808F2E4 @ =0x000034E4
	adds r0, r4, r1
	adds r5, r4, #0
	adds r5, #0xc0
	mov r1, r8
	str r1, [sp]
	adds r1, r5, #0
	movs r2, #4
	movs r3, #2
	bl FUN_082370cc
	ldr r0, _0808F2E8 @ =0x00003604
	adds r6, r4, r0
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0x1d
	movs r3, #1
	bl FUN_0822f3cc
	mov r1, r8
	str r1, [sp]
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0xa
	movs r3, #1
	bl FUN_082370cc
	movs r0, #0
	bl FUN_08047a28
	ldr r1, _0808F2EC @ =FUN_0808f520
	adds r0, r4, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808F2D4: .4byte 0x000034EC
_0808F2D8: .4byte 0x00003504
_0808F2DC: .4byte 0x0000FFA8
_0808F2E0: .4byte 0x00003506
_0808F2E4: .4byte 0x000034E4
_0808F2E8: .4byte 0x00003604
_0808F2EC: .4byte FUN_0808f520

	thumb_func_start FUN_0808f2f0
FUN_0808f2f0: @ 0x0808F2F0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	bl FUN_08047864
	bl FUN_08049e5c
	bl FUN_08049f84
	movs r0, #1
	movs r1, #1
	movs r2, #0x1c
	movs r3, #4
	bl FUN_08047b8c
	ldr r0, [r5, #0x54]
	bl FUN_080478f0
	movs r0, #1
	bl FUN_080477e4
	ldr r1, [r5, #0x18]
	ldr r0, [r5, #0x30]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	movs r3, #2
	bl FUN_0808a3c4
	adds r0, r5, #0
	bl FUN_0808b82c
	ldr r0, _0808F3D0 @ =0x000034EC
	adds r1, r5, r0
	ldr r0, [r1]
	movs r4, #2
	rsbs r4, r4, #0
	ands r0, r4
	str r0, [r1]
	ldr r0, _0808F3D4 @ =0x00003504
	adds r1, r5, r0
	movs r7, #0
	ldr r0, _0808F3D8 @ =0x0000FFE4
	strh r0, [r1]
	ldr r0, _0808F3DC @ =0x00003506
	adds r1, r5, r0
	movs r0, #0x20
	strh r0, [r1]
	ldr r1, _0808F3E0 @ =0x000034E4
	adds r0, r5, r1
	adds r6, r5, #0
	adds r6, #0xc0
	str r7, [sp]
	adds r1, r6, #0
	movs r2, #7
	movs r3, #2
	bl FUN_082370cc
	ldr r0, _0808F3E4 @ =0x0000354C
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _0808F38C
	ldr r0, _0808F3E8 @ =0x000035AC
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
_0808F38C:
	ldr r0, _0808F3EC @ =0x0000360C
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	ldr r1, _0808F3F0 @ =0x00003604
	adds r4, r5, r1
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0x1d
	movs r3, #1
	bl FUN_0822f3cc
	str r7, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0xa
	movs r3, #1
	bl FUN_082370cc
	adds r0, r5, #0
	bl FUN_0808f1bc
	movs r0, #7
	bl FUN_08047a28
	ldr r1, _0808F3F4 @ =FUN_0808f604
	adds r0, r5, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808F3D0: .4byte 0x000034EC
_0808F3D4: .4byte 0x00003504
_0808F3D8: .4byte 0x0000FFE4
_0808F3DC: .4byte 0x00003506
_0808F3E0: .4byte 0x000034E4
_0808F3E4: .4byte 0x0000354C
_0808F3E8: .4byte 0x000035AC
_0808F3EC: .4byte 0x0000360C
_0808F3F0: .4byte 0x00003604
_0808F3F4: .4byte FUN_0808f604

	thumb_func_start FUN_0808f3f8
FUN_0808f3f8: @ 0x0808F3F8
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_0808b82c
	ldr r0, _0808F484 @ =0x000034EC
	adds r1, r4, r0
	ldr r0, [r1]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r1]
	ldr r0, _0808F488 @ =0x00003504
	adds r1, r4, r0
	movs r2, #0
	ldr r0, _0808F48C @ =0x0000FFE4
	strh r0, [r1]
	ldr r0, _0808F490 @ =0x00003506
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
	ldr r1, _0808F494 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	str r2, [sp]
	movs r2, #6
	movs r3, #2
	bl FUN_082370cc
	ldr r0, _0808F498 @ =0x0000354C
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _0808F45C
	ldr r0, _0808F49C @ =0x000035AC
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
_0808F45C:
	ldr r0, _0808F4A0 @ =0x0000360C
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	ldr r0, _0808F4A4 @ =0x000002C1
	bl PlaySound_082406e0
	movs r0, #3
	bl FUN_08047a28
	ldr r1, _0808F4A8 @ =FUN_0808f8bc
	adds r0, r4, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808F484: .4byte 0x000034EC
_0808F488: .4byte 0x00003504
_0808F48C: .4byte 0x0000FFE4
_0808F490: .4byte 0x00003506
_0808F494: .4byte 0x000034E4
_0808F498: .4byte 0x0000354C
_0808F49C: .4byte 0x000035AC
_0808F4A0: .4byte 0x0000360C
_0808F4A4: .4byte 0x000002C1
_0808F4A8: .4byte FUN_0808f8bc

	thumb_func_start FUN_0808f4ac
FUN_0808f4ac: @ 0x0808F4AC
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_0808b82c
	ldr r0, _0808F504 @ =0x000034EC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _0808F508 @ =0x00003504
	adds r1, r4, r0
	movs r2, #0
	ldr r0, _0808F50C @ =0x0000FFE4
	strh r0, [r1]
	ldr r0, _0808F510 @ =0x00003506
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
	ldr r1, _0808F514 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	str r2, [sp]
	movs r2, #6
	movs r3, #2
	bl FUN_082370cc
	ldr r0, _0808F518 @ =0x000002C1
	bl PlaySound_082406e0
	movs r0, #3
	bl FUN_08047a28
	ldr r1, _0808F51C @ =FUN_0808f774
	adds r0, r4, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F504: .4byte 0x000034EC
_0808F508: .4byte 0x00003504
_0808F50C: .4byte 0x0000FFE4
_0808F510: .4byte 0x00003506
_0808F514: .4byte 0x000034E4
_0808F518: .4byte 0x000002C1
_0808F51C: .4byte FUN_0808f774

	thumb_func_start FUN_0808f520
FUN_0808f520: @ 0x0808F520
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _0808F538 @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _0808F53C
	lsls r0, r0, #2
	movs r1, #0
	bl FUN_0808a458
	b _0808F544
	.align 2, 0
_0808F538: .4byte 0x000009EC
_0808F53C:
	movs r0, #0x40
	movs r1, #0
	bl FUN_0808a458
_0808F544:
	ldr r1, _0808F5E0 @ =0x000009EC
	adds r5, r4, r1
	ldrh r0, [r5]
	cmp r0, #0x10
	bne _0808F556
	movs r0, #0xb0
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0808F556:
	ldr r1, _0808F5E4 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl FUN_082372cc
	ldrh r0, [r5]
	cmp r0, #0x68
	bls _0808F572
	ldr r0, _0808F5E8 @ =0x00003504
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #5
	strh r0, [r1]
_0808F572:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x74
	bls _0808F5DA
	movs r0, #7
	bl FUN_08047a28
	ldr r0, _0808F5E8 @ =0x00003504
	adds r1, r4, r0
	ldr r0, _0808F5EC @ =0x0000FFE4
	strh r0, [r1]
	ldr r0, _0808F5F0 @ =0x0000360C
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldr r0, _0808F5F4 @ =0x0000354C
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _0808F5C4
	ldr r0, _0808F5F8 @ =0x000035AC
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
_0808F5C4:
	ldr r1, _0808F5FC @ =0x0000401C
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_0808f1bc
	ldr r1, _0808F600 @ =FUN_0808f670
	adds r0, r4, #0
	bl FUN_0808a33c
_0808F5DA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808F5E0: .4byte 0x000009EC
_0808F5E4: .4byte 0x000034E4
_0808F5E8: .4byte 0x00003504
_0808F5EC: .4byte 0x0000FFE4
_0808F5F0: .4byte 0x0000360C
_0808F5F4: .4byte 0x0000354C
_0808F5F8: .4byte 0x000035AC
_0808F5FC: .4byte 0x0000401C
_0808F600: .4byte FUN_0808f670

	thumb_func_start FUN_0808f604
FUN_0808f604: @ 0x0808F604
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0808F61C @ =0x000009EC
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _0808F620
	lsls r0, r0, #2
	movs r1, #0
	bl FUN_0808a458
	b _0808F628
	.align 2, 0
_0808F61C: .4byte 0x000009EC
_0808F620:
	movs r0, #0x40
	movs r1, #0
	bl FUN_0808a458
_0808F628:
	ldr r1, _0808F660 @ =0x000034E4
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0xc0
	adds r1, r4, #0
	bl FUN_082372cc
	ldr r1, _0808F664 @ =0x00003604
	adds r0, r5, r1
	adds r1, r4, #0
	bl FUN_082372cc
	ldr r0, _0808F668 @ =0x000009EC
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0808F65A
	ldr r1, _0808F66C @ =FUN_0808f670
	adds r0, r5, #0
	bl FUN_0808a33c
_0808F65A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808F660: .4byte 0x000034E4
_0808F664: .4byte 0x00003604
_0808F668: .4byte 0x000009EC
_0808F66C: .4byte FUN_0808f670

	thumb_func_start FUN_0808f670
FUN_0808f670: @ 0x0808F670
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _0808F6EC @ =0x000034E4
	adds r0, r4, r1
	adds r5, r4, #0
	adds r5, #0xc0
	adds r1, r5, #0
	bl FUN_082372cc
	ldr r2, _0808F6F0 @ =0x00003604
	adds r6, r4, r2
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_082372cc
	ldr r0, _0808F6F4 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808F720
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0x1d
	movs r3, #1
	bl FUN_0822f3cc
	ldr r1, _0808F6F8 @ =0x0000401C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808F710
	movs r0, #8
	bl FUN_08047a28
	ldr r2, _0808F6FC @ =0x0000401E
	adds r0, r4, r2
	ldrb r0, [r0]
	subs r0, #1
	movs r1, #0x32
	muls r1, r0, r1
	movs r0, #0
	bl FUN_08047c40
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808b6fc
	ldr r0, _0808F700 @ =0x00001524
	adds r1, r4, r0
	ldr r0, _0808F704 @ =0x0000FFF8
	strh r0, [r1]
	ldr r2, _0808F708 @ =0x00001526
	adds r1, r4, r2
	subs r0, #0x60
	strh r0, [r1]
	ldr r1, _0808F70C @ =FUN_0808f81c
	b _0808F712
	.align 2, 0
_0808F6EC: .4byte 0x000034E4
_0808F6F0: .4byte 0x00003604
_0808F6F4: .4byte 0x030044E0
_0808F6F8: .4byte 0x0000401C
_0808F6FC: .4byte 0x0000401E
_0808F700: .4byte 0x00001524
_0808F704: .4byte 0x0000FFF8
_0808F708: .4byte 0x00001526
_0808F70C: .4byte FUN_0808f81c
_0808F710:
	ldr r1, _0808F71C @ =FUN_0808f7cc
_0808F712:
	adds r0, r4, #0
	bl FUN_0808a33c
	b _0808F76A
	.align 2, 0
_0808F71C: .4byte FUN_0808f7cc
_0808F720:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0808F736
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_0808f4ac
	b _0808F76A
_0808F736:
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r4, r2
	ldr r0, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #5
	beq _0808F76A
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	beq _0808F76A
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r0, _0808F770 @ =0x0000401C
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	bl FUN_0808f1bc
_0808F76A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808F770: .4byte 0x0000401C

	thumb_func_start FUN_0808f774
FUN_0808f774: @ 0x0808F774
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808F7BC @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl FUN_082372cc
	ldr r0, _0808F7C0 @ =0x00003504
	adds r2, r4, r0
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r0, #0x58
	rsbs r0, r0, #0
	cmp r1, r0
	ble _0808F79A
	subs r0, r3, #5
	strh r0, [r2]
_0808F79A:
	ldr r0, _0808F7C4 @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x95
	bls _0808F7B4
	ldr r1, _0808F7C8 @ =FUN_0809ae0c
	adds r0, r4, #0
	bl FUN_0808a33c
_0808F7B4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F7BC: .4byte 0x000034E4
_0808F7C0: .4byte 0x00003504
_0808F7C4: .4byte 0x000009EC
_0808F7C8: .4byte FUN_0809ae0c

	thumb_func_start FUN_0808f7cc
FUN_0808f7cc: @ 0x0808F7CC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808F7EC @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _0808F7F0
	adds r1, r0, #0
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0
	bl FUN_0808a458
	b _0808F7F8
	.align 2, 0
_0808F7EC: .4byte 0x000009EC
_0808F7F0:
	movs r0, #0
	movs r1, #0
	bl FUN_0808a458
_0808F7F8:
	ldr r0, _0808F818 @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0808F810
	adds r0, r4, #0
	bl FUN_0808f170
_0808F810:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F818: .4byte 0x000009EC

	thumb_func_start FUN_0808f81c
FUN_0808f81c: @ 0x0808F81C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _0808F850 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl FUN_082372cc
	adds r0, r4, #0
	bl FUN_0808b760
	adds r5, r0, #0
	cmp r5, #0
	bne _0808F858
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #7
	bl FUN_08047a28
	ldr r1, _0808F854 @ =FUN_0808f670
	adds r0, r4, #0
	bl FUN_0808a33c
	b _0808F8A2
	.align 2, 0
_0808F850: .4byte 0x000034E4
_0808F854: .4byte FUN_0808f670
_0808F858:
	cmp r5, #1
	bne _0808F8A2
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r3, _0808F8A8 @ =0x030046A0
	ldr r2, [r3]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r2, r2, r0
	ldr r1, _0808F8AC @ =0x0000401E
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #1
	movs r1, #0x32
	muls r1, r0, r1
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
	ldr r1, _0808F8B0 @ =0x0000270F
	cmp r0, r1
	ble _0808F88E
	ldr r0, [r3]
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r0, r2
	str r1, [r0]
_0808F88E:
	ldr r1, _0808F8B4 @ =0x00003FB0
	adds r0, r4, r1
	strb r5, [r0]
	ldr r2, _0808F8B8 @ =0x00003FB1
	adds r1, r4, r2
	movs r0, #2
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0808f3f8
_0808F8A2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808F8A8: .4byte 0x030046A0
_0808F8AC: .4byte 0x0000401E
_0808F8B0: .4byte 0x0000270F
_0808F8B4: .4byte 0x00003FB0
_0808F8B8: .4byte 0x00003FB1

	thumb_func_start FUN_0808f8bc
FUN_0808f8bc: @ 0x0808F8BC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808F8F8 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl FUN_082372cc
	ldr r0, _0808F8FC @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x95
	bls _0808F914
	movs r0, #5
	bl FUN_08047a28
	ldr r1, _0808F900 @ =0x00004028
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0808F904
	movs r1, #0
	bl FUN_082318ac
	b _0808F90C
	.align 2, 0
_0808F8F8: .4byte 0x000034E4
_0808F8FC: .4byte 0x000009EC
_0808F900: .4byte 0x00004028
_0808F904:
	movs r0, #0
	movs r1, #3
	bl FUN_08047c40
_0808F90C:
	ldr r1, _0808F91C @ =FUN_0808f920
	adds r0, r4, #0
	bl FUN_0808a33c
_0808F914:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F91C: .4byte FUN_0808f920

	thumb_func_start FUN_0808f920
FUN_0808f920: @ 0x0808F920
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808F950 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl FUN_082372cc
	ldr r0, _0808F954 @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x95
	bls _0808F94A
	ldr r1, _0808F958 @ =FUN_0809ae0c
	adds r0, r4, #0
	bl FUN_0808a33c
_0808F94A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F950: .4byte 0x000034E4
_0808F954: .4byte 0x000009EC
_0808F958: .4byte FUN_0809ae0c

	thumb_func_start FUN_0808f95c
FUN_0808f95c: @ 0x0808F95C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808f140
	ldr r2, _0808F980 @ =0x0000401E
	adds r1, r4, r2
	strb r0, [r1]
	ldr r2, _0808F984 @ =0x03003E78
	ldr r0, _0808F988 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	bl FUN_0808f21c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F980: .4byte 0x0000401E
_0808F984: .4byte 0x03003E78
_0808F988: .4byte 0xFFFFFDFF

	thumb_func_start FUN_0808f98c
FUN_0808f98c: @ 0x0808F98C
	ldrb r1, [r0, #1]
	lsls r1, r1, #2
	ldrb r2, [r0, #2]
	adds r1, r1, r2
	adds r0, #8
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bx lr

	thumb_func_start FUN_0808f9a0
FUN_0808f9a0: @ 0x0808F9A0
	push {r4, lr}
	adds r3, r0, #0
	ldr r4, _0808F9BC @ =0x030044E0
	ldrh r0, [r4, #2]
	movs r1, #0xf0
	adds r2, r1, #0
	ands r2, r0
	cmp r2, #0
	beq _0808F9C0
	movs r0, #0
	strb r0, [r3, #7]
	ldrh r0, [r4, #2]
	b _0808F9E0
	.align 2, 0
_0808F9BC: .4byte 0x030044E0
_0808F9C0:
	ldrh r0, [r4]
	ands r1, r0
	cmp r1, #0
	beq _0808F9DC
	ldrb r0, [r3, #7]
	adds r0, #1
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bls _0808F9DE
	strb r2, [r3, #7]
	ldrh r0, [r4]
	b _0808F9E0
_0808F9DC:
	strb r1, [r3, #7]
_0808F9DE:
	movs r0, #0
_0808F9E0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808f9e8
FUN_0808f9e8: @ 0x0808F9E8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r2, [r4, #2]
	ldrb r1, [r4, #1]
	lsls r1, r1, #2
	adds r1, r2, r1
	adds r0, #8
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	adds r3, r2, #3
	movs r0, #3
	ands r3, r0
	cmp r3, r2
	beq _0808FA40
_0808FA06:
	ldrb r1, [r4, #1]
	lsls r1, r1, #2
	adds r1, r3, r1
	adds r0, r4, #0
	adds r0, #8
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0808FA34
	cmp r0, r5
	beq _0808FA34
	strb r3, [r4, #2]
	adds r0, r4, #0
	bl FUN_0808f98c
	strb r0, [r4, #3]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r0, #1
	b _0808FA42
_0808FA34:
	adds r3, #3
	movs r0, #3
	ands r3, r0
	ldrb r0, [r4, #2]
	cmp r3, r0
	bne _0808FA06
_0808FA40:
	movs r0, #0
_0808FA42:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808fa48
FUN_0808fa48: @ 0x0808FA48
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r2, [r4, #2]
	ldrb r1, [r4, #1]
	lsls r1, r1, #2
	adds r1, r2, r1
	adds r0, #8
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	adds r3, r2, #1
	movs r0, #3
	ands r3, r0
	cmp r3, r2
	beq _0808FAA0
_0808FA66:
	ldrb r1, [r4, #1]
	lsls r1, r1, #2
	adds r1, r3, r1
	adds r0, r4, #0
	adds r0, #8
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0808FA94
	cmp r0, r5
	beq _0808FA94
	strb r3, [r4, #2]
	adds r0, r4, #0
	bl FUN_0808f98c
	strb r0, [r4, #3]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r0, #1
	b _0808FAA2
_0808FA94:
	adds r3, #1
	movs r0, #3
	ands r3, r0
	ldrb r0, [r4, #2]
	cmp r3, r0
	bne _0808FA66
_0808FAA0:
	movs r0, #0
_0808FAA2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808faa8
FUN_0808faa8: @ 0x0808FAA8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r3, [r4, #1]
	lsls r1, r3, #2
	ldrb r0, [r4, #2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #8
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	subs r2, r3, #1
	cmp r3, #0
	bne _0808FAFC
_0808FAC4:
	movs r2, #8
	b _0808FAFC
_0808FAC8:
	lsls r1, r2, #2
	ldrb r0, [r4, #2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #8
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0808FAF6
	cmp r0, r5
	beq _0808FAF6
	strb r2, [r4, #1]
	adds r0, r4, #0
	bl FUN_0808f98c
	strb r0, [r4, #3]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r0, #1
	b _0808FB02
_0808FAF6:
	cmp r2, #0
	beq _0808FAC4
	subs r2, #1
_0808FAFC:
	cmp r2, r3
	bne _0808FAC8
	movs r0, #0
_0808FB02:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808fb08
FUN_0808fb08: @ 0x0808FB08
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r3, [r4, #1]
	lsls r1, r3, #2
	ldrb r0, [r4, #2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #8
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	adds r2, r3, #1
	cmp r3, #8
	bne _0808FB5C
_0808FB24:
	movs r2, #0
	b _0808FB5C
_0808FB28:
	lsls r1, r2, #2
	ldrb r0, [r4, #2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #8
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0808FB56
	cmp r0, r5
	beq _0808FB56
	strb r2, [r4, #1]
	adds r0, r4, #0
	bl FUN_0808f98c
	strb r0, [r4, #3]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r0, #1
	b _0808FB62
_0808FB56:
	cmp r2, #8
	beq _0808FB24
	adds r2, #1
_0808FB5C:
	cmp r2, r3
	bne _0808FB28
	movs r0, #0
_0808FB62:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808fb68
FUN_0808fb68: @ 0x0808FB68
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808f9a0
	adds r1, r0, #0
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0808FB82
	adds r0, r4, #0
	bl FUN_0808f9e8
	b _0808FBB4
_0808FB82:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0808FB92
	adds r0, r4, #0
	bl FUN_0808fa48
	b _0808FBB4
_0808FB92:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0808FBA2
	adds r0, r4, #0
	bl FUN_0808faa8
	b _0808FBB4
_0808FBA2:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0808FBAE
	movs r0, #0
	b _0808FBB4
_0808FBAE:
	adds r0, r4, #0
	bl FUN_0808fb08
_0808FBB4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808fbbc
FUN_0808fbbc: @ 0x0808FBBC
	ldrb r1, [r0, #1]
	strb r1, [r0, #4]
	ldrb r1, [r0, #2]
	strb r1, [r0, #5]
	ldrb r1, [r0, #3]
	strb r1, [r0, #6]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0808fbcc
FUN_0808fbcc: @ 0x0808FBCC
	ldrb r1, [r0, #4]
	strb r1, [r0, #1]
	ldrb r1, [r0, #5]
	strb r1, [r0, #2]
	ldrb r1, [r0, #6]
	strb r1, [r0, #3]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0808fbdc
FUN_0808fbdc: @ 0x0808FBDC
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	strb r1, [r4, #1]
	strb r2, [r4, #2]
	bl FUN_0808f98c
	strb r0, [r4, #3]
	strb r5, [r4, #7]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808fbf4
FUN_0808fbf4: @ 0x0808FBF4
	push {lr}
	ldr r2, _0808FC10 @ =0x00004038
	adds r1, r0, r2
	ldrb r1, [r1]
	subs r2, #0xc
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r1, r1, #4
	adds r1, r1, r0
	ldrb r0, [r1, #0xf]
	bl FUN_08047a28
	pop {r0}
	bx r0
	.align 2, 0
_0808FC10: .4byte 0x00004038

	thumb_func_start FUN_0808fc14
FUN_0808fc14: @ 0x0808FC14
	push {r4, lr}
	ldr r0, _0808FC4C @ =0x030046A0
	ldr r3, [r0]
	movs r0, #0x95
	lsls r0, r0, #2
	adds r2, r3, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0xe
	bgt _0808FC5C
	ldr r1, _0808FC50 @ =0x085ACEC8
	lsls r0, r0, #2
	adds r1, r0, r1
	ldr r2, [r1]
	ldr r1, _0808FC54 @ =0x085ACF04
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r4, _0808FC58 @ =0x00000256
	adds r0, r3, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrb r0, [r0, #0xf]
	b _0808FC62
	.align 2, 0
_0808FC4C: .4byte 0x030046A0
_0808FC50: .4byte 0x085ACEC8
_0808FC54: .4byte 0x085ACF04
_0808FC58: .4byte 0x00000256
_0808FC5C:
	movs r4, #0
	ldrsh r0, [r2, r4]
	adds r0, #0x40
_0808FC62:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808fc68
FUN_0808fc68: @ 0x0808FC68
	push {lr}
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _0808FC84
	bl fetch_082316e4
	ldr r1, _0808FC88 @ =0x030046A0
	ldr r1, [r1]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r1, r1, r2
	strh r0, [r1]
_0808FC84:
	pop {r0}
	bx r0
	.align 2, 0
_0808FC88: .4byte 0x030046A0

	thumb_func_start FUN_0808fc8c
FUN_0808fc8c: @ 0x0808FC8C
	push {lr}
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0808FCA6
	bl fetch_082316e4
	ldr r1, _0808FCAC @ =0x030046A0
	ldr r1, [r1]
	ldr r2, _0808FCB0 @ =0x00000256
	adds r1, r1, r2
	strh r0, [r1]
_0808FCA6:
	pop {r0}
	bx r0
	.align 2, 0
_0808FCAC: .4byte 0x030046A0
_0808FCB0: .4byte 0x00000256

	thumb_func_start FUN_0808fcb4
FUN_0808fcb4: @ 0x0808FCB4
	push {lr}
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _0808FCD0
	bl fetch_082316e4
	ldr r1, _0808FCD4 @ =0x030046A0
	ldr r1, [r1]
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r1, r2
	strh r0, [r1]
_0808FCD0:
	pop {r0}
	bx r0
	.align 2, 0
_0808FCD4: .4byte 0x030046A0

	thumb_func_start FUN_0808fcd8
FUN_0808fcd8: @ 0x0808FCD8
	push {lr}
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0808FCF2
	bl fetch_082316e4
	ldr r1, _0808FCF8 @ =0x030046A0
	ldr r1, [r1]
	ldr r2, _0808FCFC @ =0x0000025A
	adds r1, r1, r2
	strh r0, [r1]
_0808FCF2:
	pop {r0}
	bx r0
	.align 2, 0
_0808FCF8: .4byte 0x030046A0
_0808FCFC: .4byte 0x0000025A

	thumb_func_start FUN_0808fd00
FUN_0808fd00: @ 0x0808FD00
	push {lr}
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _0808FD24
	bl fetch_082316e4
	ldr r1, _0808FD28 @ =0x030046A0
	ldr r2, [r1]
	movs r1, #0x98
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_0808FD24:
	pop {r0}
	bx r0
	.align 2, 0
_0808FD28: .4byte 0x030046A0

	thumb_func_start FUN_0808fd2c
FUN_0808fd2c: @ 0x0808FD2C
	ldr r1, _0808FD40 @ =0x030046A0
	ldr r2, [r1]
	movs r1, #0x98
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	bx lr
	.align 2, 0
_0808FD40: .4byte 0x030046A0

	thumb_func_start FUN_0808fd44
FUN_0808fd44: @ 0x0808FD44
	push {lr}
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	bne _0808FD70
	ldr r0, _0808FD6C @ =0x030046A0
	ldr r1, [r0]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r0, r1
	b _0808FD82
	.align 2, 0
_0808FD6C: .4byte 0x030046A0
_0808FD70:
	bl fetch_082316e4
	ldr r1, _0808FD88 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r0, r2
_0808FD82:
	ldr r0, [r0]
	pop {r1}
	bx r1
	.align 2, 0
_0808FD88: .4byte 0x030046A0

	thumb_func_start FUN_0808fd8c
FUN_0808fd8c: @ 0x0808FD8C
	push {lr}
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _0808FDA0
	bl fetch_082316e4
	adds r2, r0, #0
	b _0808FDAE
_0808FDA0:
	ldr r0, _0808FDC4 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x95
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
_0808FDAE:
	ldr r0, _0808FDC4 @ =0x030046A0
	ldr r1, [r0]
	lsls r0, r2, #2
	adds r0, r0, r1
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0808FDC4: .4byte 0x030046A0

	thumb_func_start FUN_0808fdc8
FUN_0808fdc8: @ 0x0808FDC8
	push {r4, lr}
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _0808FDDC
	bl fetch_082316e4
	adds r4, r0, #0
	b _0808FDEA
_0808FDDC:
	ldr r0, _0808FE18 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x95
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r4, [r0, r1]
_0808FDEA:
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _0808FE10
	bl fetch_082316e4
	ldr r1, _0808FE18 @ =0x030046A0
	ldr r1, [r1]
	lsls r2, r4, #2
	adds r2, r2, r1
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_0808FE10:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808FE18: .4byte 0x030046A0

	thumb_func_start FUN_0808fe1c
FUN_0808fe1c: @ 0x0808FE1C
	push {r4, lr}
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _0808FE30
	bl fetch_082316e4
	adds r4, r0, #0
	b _0808FE3E
_0808FE30:
	ldr r0, _0808FE6C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x95
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r4, [r0, r1]
_0808FE3E:
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _0808FE64
	bl fetch_082316e4
	ldr r1, _0808FE6C @ =0x030046A0
	ldr r1, [r1]
	lsls r2, r4, #2
	adds r2, r2, r1
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
_0808FE64:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808FE6C: .4byte 0x030046A0

	thumb_func_start FUN_0808fe70
FUN_0808fe70: @ 0x0808FE70
	adds r1, r0, #0
	movs r0, #0xf
	ands r0, r1
	bx lr

	thumb_func_start FUN_0808fe78
FUN_0808fe78: @ 0x0808FE78
	asrs r0, r0, #4
	bx lr

	thumb_func_start FUN_0808fe7c
FUN_0808fe7c: @ 0x0808FE7C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	mov sl, r1
	mov sb, r2
	ldr r0, _0808FE9C @ =0x00004034
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	beq _0808FF6C
	movs r7, #0
	b _0808FF52
	.align 2, 0
_0808FE9C: .4byte 0x00004034
_0808FEA0:
	ldr r1, _0808FF00 @ =0x00004038
	add r1, r8
	ldrb r0, [r6, #1]
	ldrb r1, [r1]
	cmp r0, r1
	bne _0808FF50
	ldr r0, _0808FF04 @ =0x030046A0
	ldr r1, [r0]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	asrs r0, r7
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808FF50
	ldrb r3, [r6, #2]
	ldrb r2, [r6, #3]
	cmp r3, sl
	blt _0808FF50
	mov r0, sl
	adds r0, #0x20
	cmp r3, r0
	bge _0808FF50
	cmp r2, sb
	blt _0808FF50
	mov r0, sb
	adds r0, #0x20
	cmp r2, r0
	bge _0808FF50
	movs r4, #0
	subs r0, r5, #1
	cmp r0, #4
	bhi _0808FF2A
	lsls r0, r0, #2
	ldr r1, _0808FF08 @ =_0808FF0C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808FF00: .4byte 0x00004038
_0808FF04: .4byte 0x030046A0
_0808FF08: .4byte _0808FF0C
_0808FF0C: @ jump table
	.4byte _0808FF20 @ case 0
	.4byte _0808FF24 @ case 1
	.4byte _0808FF28 @ case 2
	.4byte _0808FF28 @ case 3
	.4byte _0808FF28 @ case 4
_0808FF20:
	movs r4, #0xd
	b _0808FF2A
_0808FF24:
	movs r4, #0xf
	b _0808FF2A
_0808FF28:
	movs r4, #1
_0808FF2A:
	movs r0, #1
	adds r1, r3, #0
	bl FUN_0808a420
	adds r5, r0, #0
	ldrb r0, [r6]
	bl FUN_0808fe78
	cmp r0, #0
	beq _0808FF48
	ldr r2, _0808FF44 @ =0xFFFFE400
	adds r0, r2, #0
	b _0808FF4C
	.align 2, 0
_0808FF44: .4byte 0xFFFFE400
_0808FF48:
	ldr r1, _0808FF7C @ =0xFFFFE000
	adds r0, r1, #0
_0808FF4C:
	orrs r4, r0
	strh r4, [r5]
_0808FF50:
	adds r7, #1
_0808FF52:
	cmp r7, #0x1f
	bgt _0808FF6C
	ldr r0, _0808FF80 @ =0x00004034
	add r0, r8
	lsls r1, r7, #2
	ldr r0, [r0]
	adds r6, r0, r1
	ldrb r0, [r6]
	bl FUN_0808fe70
	adds r5, r0, #0
	cmp r5, #0
	bne _0808FEA0
_0808FF6C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808FF7C: .4byte 0xFFFFE000
_0808FF80: .4byte 0x00004034

	thumb_func_start FUN_0808ff84
FUN_0808ff84: @ 0x0808FF84
	push {r4, r5, lr}
	ldr r2, _0808FFF0 @ =0x00004044
	adds r1, r0, r2
	movs r2, #0
	strh r2, [r1]
	ldr r3, _0808FFF4 @ =0x00004046
	adds r1, r0, r3
	strh r2, [r1]
	ldr r5, _0808FFF8 @ =0x00004038
	adds r4, r0, r5
	ldrb r1, [r4]
	ldr r2, _0808FFFC @ =0x0000402C
	adds r3, r0, r2
	ldr r2, [r3]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrb r1, [r1, #4]
	subs r1, #0x1e
	lsls r1, r1, #3
	adds r5, #0x10
	adds r2, r0, r5
	strh r1, [r2]
	ldrb r1, [r4]
	ldr r2, [r3]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrb r1, [r1, #5]
	subs r1, #0x14
	lsls r1, r1, #3
	adds r5, #2
	adds r2, r0, r5
	strh r1, [r2]
	ldrb r1, [r4]
	ldr r2, [r3]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrb r1, [r1, #2]
	lsls r1, r1, #3
	adds r5, #2
	adds r2, r0, r5
	strh r1, [r2]
	ldrb r1, [r4]
	ldr r2, [r3]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrb r1, [r1, #3]
	lsls r1, r1, #3
	ldr r2, _08090000 @ =0x0000404E
	adds r0, r0, r2
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808FFF0: .4byte 0x00004044
_0808FFF4: .4byte 0x00004046
_0808FFF8: .4byte 0x00004038
_0808FFFC: .4byte 0x0000402C
_08090000: .4byte 0x0000404E

	thumb_func_start FUN_08090004
FUN_08090004: @ 0x08090004
	ldr r1, _08090030 @ =0x00002CAC
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, #1
	orrs r1, r3
	str r1, [r2]
	ldr r1, _08090034 @ =0x00002D0C
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	ldr r1, _08090038 @ =0x00002D6C
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	ldr r1, _0809003C @ =0x00002DCC
	adds r0, r0, r1
	ldr r1, [r0]
	orrs r1, r3
	str r1, [r0]
	bx lr
	.align 2, 0
_08090030: .4byte 0x00002CAC
_08090034: .4byte 0x00002D0C
_08090038: .4byte 0x00002D6C
_0809003C: .4byte 0x00002DCC

	thumb_func_start FUN_08090040
FUN_08090040: @ 0x08090040
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	ldr r0, _08090084 @ =0x00002CAC
	adds r2, r3, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r5, _08090088 @ =0x00002D0C
	adds r4, r3, r5
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r6, _0809008C @ =0x00004040
	adds r1, r3, r6
	ldr r7, _08090090 @ =0x00004044
	adds r0, r3, r7
	movs r6, #0
	ldrsh r5, [r1, r6]
	ldrh r6, [r0]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r5, r0
	bgt _08090094
	strh r6, [r1]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	b _080900AC
	.align 2, 0
_08090084: .4byte 0x00002CAC
_08090088: .4byte 0x00002D0C
_0809008C: .4byte 0x00004040
_08090090: .4byte 0x00004044
_08090094:
	ldr r2, _080900E8 @ =0x00004048
	adds r0, r3, r2
	ldrh r2, [r0]
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r5, r0
	blt _080900AC
	strh r2, [r1]
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080900AC:
	ldr r7, _080900EC @ =0x00002D6C
	adds r4, r3, r7
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r0, _080900F0 @ =0x00002DCC
	adds r5, r3, r0
	ldr r2, [r5]
	ands r2, r1
	str r2, [r5]
	ldr r1, _080900F4 @ =0x00004042
	adds r6, r3, r1
	ldr r7, _080900F8 @ =0x00004046
	adds r7, r7, r3
	movs r1, #0
	ldrsh r0, [r6, r1]
	mov r8, r0
	movs r1, #0
	ldrsh r0, [r7, r1]
	cmp r8, r0
	bgt _080900FC
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	ldrh r0, [r7]
	b _08090110
	.align 2, 0
_080900E8: .4byte 0x00004048
_080900EC: .4byte 0x00002D6C
_080900F0: .4byte 0x00002DCC
_080900F4: .4byte 0x00004042
_080900F8: .4byte 0x00004046
_080900FC:
	ldr r7, _0809011C @ =0x0000404A
	adds r1, r3, r7
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r8, r0
	blt _08090112
	movs r0, #1
	orrs r2, r0
	str r2, [r5]
	ldrh r0, [r1]
_08090110:
	strh r0, [r6]
_08090112:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809011C: .4byte 0x0000404A

	thumb_func_start FUN_08090120
FUN_08090120: @ 0x08090120
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08090144 @ =0x00002CA4
	adds r4, r6, r0
	movs r5, #3
_0809012A:
	adds r0, r4, #0
	adds r1, r6, #0
	adds r1, #0x80
	bl FUN_082372cc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809012A
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08090144: .4byte 0x00002CA4

	thumb_func_start FUN_08090148
FUN_08090148: @ 0x08090148
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r5, r0, #0
	ldr r0, _08090214 @ =0x00002E2C
	adds r7, r5, r0
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
	str r0, [r7]
	ldr r2, _08090218 @ =0x00002E8C
	adds r6, r5, r2
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, _0809021C @ =0x00002EEC
	adds r3, r5, r0
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	ldr r1, _08090220 @ =0x00002F4C
	adds r1, r1, r5
	mov r8, r1
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08090224 @ =0x0000403C
	adds r0, r0, r5
	mov sb, r0
	movs r0, #0xff
	mov r1, sb
	strb r0, [r1]
	ldr r2, _08090228 @ =0x0000403D
	adds r2, r5, r2
	str r2, [sp]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r2]
	ldr r0, _0809022C @ =0x0000403E
	adds r0, r5, r0
	str r0, [sp, #4]
	movs r0, #1
	rsbs r0, r0, #0
	ldr r1, [sp, #4]
	strb r0, [r1]
	ldr r2, _08090230 @ =0x0000403F
	adds r2, r5, r2
	str r2, [sp, #8]
	strb r0, [r2]
	ldr r0, _08090234 @ =0x0000402C
	adds r0, r5, r0
	str r0, [sp, #0xc]
	ldr r1, _08090238 @ =0x00004038
	adds r1, r1, r5
	mov sl, r1
	ldrb r0, [r1]
	lsls r0, r0, #4
	ldr r1, [sp, #0xc]
	ldr r2, [r1]
	adds r4, r2, r0
	ldr r1, _0809023C @ =0x00004039
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080901D4
	b _08090512
_080901D4:
	movs r1, #6
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080902A4
	adds r0, r1, #0
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	bl FUN_0808fd2c
	cmp r0, #0
	beq _0809024E
	ldrb r0, [r4, #6]
	mov r2, sb
	strb r0, [r2]
	ldr r2, [r7]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r7]
	ldrb r1, [r4, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08090244
	ldr r0, _08090240 @ =0xFFFFFDFF
	ands r2, r0
	str r2, [r7]
	b _080902A4
	.align 2, 0
_08090214: .4byte 0x00002E2C
_08090218: .4byte 0x00002E8C
_0809021C: .4byte 0x00002EEC
_08090220: .4byte 0x00002F4C
_08090224: .4byte 0x0000403C
_08090228: .4byte 0x0000403D
_0809022C: .4byte 0x0000403E
_08090230: .4byte 0x0000403F
_08090234: .4byte 0x0000402C
_08090238: .4byte 0x00004038
_0809023C: .4byte 0x00004039
_08090240: .4byte 0xFFFFFDFF
_08090244:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r2, r0
	str r2, [r7]
	b _080902A4
_0809024E:
	ldr r0, _08090294 @ =0x00004050
	adds r3, r5, r0
	mov r1, sl
	ldrb r0, [r1]
	ldrh r2, [r3]
	cmp r0, r2
	beq _080902A4
	movs r1, #6
	ldrsb r1, [r4, r1]
	ldr r0, [sp, #0xc]
	ldr r2, [r0]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrh r6, [r3]
	lsls r0, r6, #4
	adds r0, r0, r2
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bne _080902A4
	mov r1, sb
	strb r6, [r1]
	ldr r1, [r7]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7]
	movs r0, #6
	ldrsb r0, [r4, r0]
	ldrh r3, [r3]
	cmp r0, r3
	bne _0809029C
	ldr r0, _08090298 @ =0xFFFFFDFF
	ands r1, r0
	b _080902A2
	.align 2, 0
_08090294: .4byte 0x00004050
_08090298: .4byte 0xFFFFFDFF
_0809029C:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r1, r0
_080902A2:
	str r1, [r7]
_080902A4:
	movs r1, #7
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08090374
	adds r0, r1, #0
	ldr r2, _080902F0 @ =0x0000402C
	adds r7, r5, r2
	ldr r1, [r7]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	bl FUN_0808fd2c
	cmp r0, #0
	beq _0809030A
	ldrb r1, [r4, #7]
	ldr r2, _080902F4 @ =0x0000403D
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _080902F8 @ =0x00002E8C
	adds r3, r5, r0
	ldr r2, [r3]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08090300
	ldr r0, _080902FC @ =0xFFFFFDFF
	ands r2, r0
	str r2, [r3]
	b _08090374
	.align 2, 0
_080902F0: .4byte 0x0000402C
_080902F4: .4byte 0x0000403D
_080902F8: .4byte 0x00002E8C
_080902FC: .4byte 0xFFFFFDFF
_08090300:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r2, r0
	str r2, [r3]
	b _08090374
_0809030A:
	ldr r1, _08090358 @ =0x00004038
	adds r0, r5, r1
	ldr r2, _0809035C @ =0x00004050
	adds r6, r5, r2
	ldrb r0, [r0]
	ldrh r1, [r6]
	cmp r0, r1
	beq _08090374
	movs r1, #7
	ldrsb r1, [r4, r1]
	ldr r2, [r7]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrh r3, [r6]
	lsls r0, r3, #4
	adds r0, r0, r2
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bne _08090374
	ldr r2, _08090360 @ =0x0000403D
	adds r0, r5, r2
	strb r3, [r0]
	ldr r0, _08090364 @ =0x00002E8C
	adds r2, r5, r0
	ldr r1, [r2]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	movs r0, #7
	ldrsb r0, [r4, r0]
	ldrh r6, [r6]
	cmp r0, r6
	bne _0809036C
	ldr r0, _08090368 @ =0xFFFFFDFF
	ands r1, r0
	b _08090372
	.align 2, 0
_08090358: .4byte 0x00004038
_0809035C: .4byte 0x00004050
_08090360: .4byte 0x0000403D
_08090364: .4byte 0x00002E8C
_08090368: .4byte 0xFFFFFDFF
_0809036C:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r1, r0
_08090372:
	str r1, [r2]
_08090374:
	movs r1, #8
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08090444
	adds r0, r1, #0
	ldr r1, _080903C0 @ =0x0000402C
	adds r7, r5, r1
	ldr r1, [r7]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	bl FUN_0808fd2c
	cmp r0, #0
	beq _080903DA
	ldrb r1, [r4, #8]
	ldr r2, _080903C4 @ =0x0000403E
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _080903C8 @ =0x00002EEC
	adds r3, r5, r0
	ldr r2, [r3]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080903D0
	ldr r0, _080903CC @ =0xFFFFFDFF
	ands r2, r0
	str r2, [r3]
	b _08090444
	.align 2, 0
_080903C0: .4byte 0x0000402C
_080903C4: .4byte 0x0000403E
_080903C8: .4byte 0x00002EEC
_080903CC: .4byte 0xFFFFFDFF
_080903D0:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r2, r0
	str r2, [r3]
	b _08090444
_080903DA:
	ldr r1, _08090428 @ =0x00004038
	adds r0, r5, r1
	ldr r2, _0809042C @ =0x00004050
	adds r6, r5, r2
	ldrb r0, [r0]
	ldrh r1, [r6]
	cmp r0, r1
	beq _08090444
	movs r1, #8
	ldrsb r1, [r4, r1]
	ldr r2, [r7]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrh r3, [r6]
	lsls r0, r3, #4
	adds r0, r0, r2
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bne _08090444
	ldr r2, _08090430 @ =0x0000403E
	adds r0, r5, r2
	strb r3, [r0]
	ldr r0, _08090434 @ =0x00002EEC
	adds r2, r5, r0
	ldr r1, [r2]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	movs r0, #8
	ldrsb r0, [r4, r0]
	ldrh r6, [r6]
	cmp r0, r6
	bne _0809043C
	ldr r0, _08090438 @ =0xFFFFFDFF
	ands r1, r0
	b _08090442
	.align 2, 0
_08090428: .4byte 0x00004038
_0809042C: .4byte 0x00004050
_08090430: .4byte 0x0000403E
_08090434: .4byte 0x00002EEC
_08090438: .4byte 0xFFFFFDFF
_0809043C:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r1, r0
_08090442:
	str r1, [r2]
_08090444:
	movs r1, #9
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _08090452
	b _08090682
_08090452:
	adds r0, r1, #0
	ldr r1, _08090494 @ =0x0000402C
	adds r7, r5, r1
	ldr r1, [r7]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	bl FUN_0808fd2c
	cmp r0, #0
	beq _080904A0
	ldrb r1, [r4, #9]
	ldr r2, _08090498 @ =0x0000403F
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _0809049C @ =0x00002F4C
	adds r3, r5, r0
	ldr r2, [r3]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0809048A
	b _0809060A
_0809048A:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r2, r0
	str r2, [r3]
	b _08090682
	.align 2, 0
_08090494: .4byte 0x0000402C
_08090498: .4byte 0x0000403F
_0809049C: .4byte 0x00002F4C
_080904A0:
	ldr r1, _080904F4 @ =0x00004038
	adds r0, r5, r1
	ldr r2, _080904F8 @ =0x00004050
	adds r6, r5, r2
	ldrb r0, [r0]
	ldrh r1, [r6]
	cmp r0, r1
	bne _080904B2
	b _08090682
_080904B2:
	movs r1, #9
	ldrsb r1, [r4, r1]
	ldr r2, [r7]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrh r3, [r6]
	lsls r0, r3, #4
	adds r0, r0, r2
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	beq _080904CC
	b _08090682
_080904CC:
	ldr r2, _080904FC @ =0x0000403F
	adds r0, r5, r2
	strb r3, [r0]
	ldr r0, _08090500 @ =0x00002F4C
	adds r2, r5, r0
	ldr r1, [r2]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	movs r0, #9
	ldrsb r0, [r4, r0]
	ldrh r6, [r6]
	cmp r0, r6
	bne _08090508
	ldr r0, _08090504 @ =0xFFFFFDFF
	ands r1, r0
	str r1, [r2]
	b _08090682
	.align 2, 0
_080904F4: .4byte 0x00004038
_080904F8: .4byte 0x00004050
_080904FC: .4byte 0x0000403F
_08090500: .4byte 0x00002F4C
_08090504: .4byte 0xFFFFFDFF
_08090508:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r1, r0
	str r1, [r2]
	b _08090682
_08090512:
	movs r1, #0xb
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08090570
	adds r0, r1, #0
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	bl FUN_0808fd2c
	cmp r0, #0
	bne _08090530
	b _08090682
_08090530:
	ldrb r0, [r4, #0xb]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [r7]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r7]
	ldrb r1, [r4, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08090564
	movs r1, #6
	ldrsb r1, [r4, r1]
	movs r0, #0xb
	ldrsb r0, [r4, r0]
	cmp r1, r0
	bne _08090564
	ldr r0, _08090560 @ =0xFFFFFDFF
	ands r2, r0
	str r2, [r7]
	b _08090682
	.align 2, 0
_08090560: .4byte 0xFFFFFDFF
_08090564:
	ldr r2, _0809056C @ =0x00002E2C
	adds r0, r5, r2
	b _08090678
	.align 2, 0
_0809056C: .4byte 0x00002E2C
_08090570:
	movs r0, #0xc
	ldrsb r0, [r4, r0]
	cmp r0, r1
	beq _080905C8
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	bl FUN_0808fd2c
	cmp r0, #0
	bne _08090588
	b _08090682
_08090588:
	ldrb r0, [r4, #0xc]
	ldr r1, [sp]
	strb r0, [r1]
	ldr r2, [r6]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r6]
	ldrb r1, [r4, #0xa]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080905BC
	movs r1, #7
	ldrsb r1, [r4, r1]
	movs r0, #0xc
	ldrsb r0, [r4, r0]
	cmp r1, r0
	bne _080905BC
	ldr r0, _080905B8 @ =0xFFFFFDFF
	ands r2, r0
	str r2, [r6]
	b _08090682
	.align 2, 0
_080905B8: .4byte 0xFFFFFDFF
_080905BC:
	ldr r2, _080905C4 @ =0x00002E8C
	adds r0, r5, r2
	b _08090678
	.align 2, 0
_080905C4: .4byte 0x00002E8C
_080905C8:
	movs r1, #0xd
	ldrsb r1, [r4, r1]
	cmp r1, r0
	beq _08090624
	adds r0, r1, #0
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	str r3, [sp, #0x10]
	bl FUN_0808fd2c
	ldr r3, [sp, #0x10]
	cmp r0, #0
	beq _08090682
	ldrb r0, [r4, #0xd]
	ldr r1, [sp, #4]
	strb r0, [r1]
	ldr r2, [r3]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08090618
	movs r1, #8
	ldrsb r1, [r4, r1]
	movs r0, #0xd
	ldrsb r0, [r4, r0]
	cmp r1, r0
	bne _08090618
_0809060A:
	ldr r0, _08090614 @ =0xFFFFFDFF
	ands r2, r0
	str r2, [r3]
	b _08090682
	.align 2, 0
_08090614: .4byte 0xFFFFFDFF
_08090618:
	ldr r2, _08090620 @ =0x00002EEC
	adds r0, r5, r2
	b _08090678
	.align 2, 0
_08090620: .4byte 0x00002EEC
_08090624:
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	cmp r0, r1
	beq _08090682
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	bl FUN_0808fd2c
	cmp r0, #0
	beq _08090682
	ldrb r0, [r4, #0xe]
	ldr r1, [sp, #8]
	strb r0, [r1]
	mov r0, r8
	ldr r2, [r0]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	mov r1, r8
	str r2, [r1]
	ldrb r1, [r4, #0xa]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08090674
	movs r1, #9
	ldrsb r1, [r4, r1]
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	cmp r1, r0
	bne _08090674
	ldr r0, _08090670 @ =0xFFFFFDFF
	ands r2, r0
	mov r0, r8
	str r2, [r0]
	b _08090682
	.align 2, 0
_08090670: .4byte 0xFFFFFDFF
_08090674:
	ldr r1, _08090694 @ =0x00002F4C
	adds r0, r5, r1
_08090678:
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	orrs r1, r2
	str r1, [r0]
_08090682:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08090694: .4byte 0x00002F4C

	thumb_func_start FUN_08090698
FUN_08090698: @ 0x08090698
	push {r4, r5, r6, r7, lr}
	movs r5, #0
	ldr r0, _080906C4 @ =0x0000E002
	adds r7, r0, #0
_080906A0:
	movs r4, #0
	adds r6, r5, #1
_080906A4:
	movs r0, #1
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0808a420
	strh r7, [r0]
	adds r4, #1
	cmp r4, #0x1f
	ble _080906A4
	adds r5, r6, #0
	cmp r5, #0x1f
	ble _080906A0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080906C4: .4byte 0x0000E002

	thumb_func_start FUN_080906c8
FUN_080906c8: @ 0x080906C8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08090700 @ =0x00004039
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809070C
	ldr r1, [r4, #0x28]
	ldr r2, _08090704 @ =0x00004038
	adds r0, r4, r2
	ldrb r0, [r0]
	ldr r3, _08090708 @ =0x0000402C
	adds r2, r4, r3
	ldr r2, [r2]
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrb r2, [r0, #1]
	movs r0, #1
	bl FUN_0822c398
	adds r0, r4, #0
	bl FUN_0808ff84
	adds r0, r4, #0
	bl FUN_08090148
	b _0809071E
	.align 2, 0
_08090700: .4byte 0x00004039
_08090704: .4byte 0x00004038
_08090708: .4byte 0x0000402C
_0809070C:
	adds r0, r4, #0
	bl FUN_08090698
	adds r0, r4, #0
	bl FUN_08090004
	adds r0, r4, #0
	bl FUN_08090148
_0809071E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08090724
FUN_08090724: @ 0x08090724
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08090760 @ =0x0000402C
	adds r0, r4, r1
	ldr r2, [r0]
	movs r5, #1
	rsbs r5, r5, #0
	ldr r0, _08090764 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0809076C
	ldr r0, _08090768 @ =0x0000403C
_08090740:
	adds r1, r4, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r5
	beq _080907CA
	adds r5, r0, #0
	lsls r0, r5, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	bl FUN_0808fd2c
	adds r1, r0, #0
	cmp r1, #0
	bne _080907B2
	b _080907C4
	.align 2, 0
_08090760: .4byte 0x0000402C
_08090764: .4byte 0x030044E0
_08090768: .4byte 0x0000403C
_0809076C:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0809077C
	ldr r0, _08090778 @ =0x0000403D
	b _08090740
	.align 2, 0
_08090778: .4byte 0x0000403D
_0809077C:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0809078C
	ldr r0, _08090788 @ =0x0000403E
	b _08090740
	.align 2, 0
_08090788: .4byte 0x0000403E
_0809078C:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080907CA
	ldr r0, _080907BC @ =0x0000403F
	adds r1, r4, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r5
	beq _080907CA
	adds r5, r0, #0
	lsls r0, r5, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	bl FUN_0808fd2c
	adds r1, r0, #0
	cmp r1, #0
	beq _080907C4
_080907B2:
	ldr r2, _080907C0 @ =0x00004039
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	b _080907CA
	.align 2, 0
_080907BC: .4byte 0x0000403F
_080907C0: .4byte 0x00004039
_080907C4:
	ldr r2, _080907D4 @ =0x00004039
	adds r0, r4, r2
	strb r1, [r0]
_080907CA:
	cmp r5, #0
	bge _080907D8
	movs r0, #0
	b _080907E6
	.align 2, 0
_080907D4: .4byte 0x00004039
_080907D8:
	ldr r1, _080907EC @ =0x00004038
	adds r0, r4, r1
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_080906c8
	movs r0, #1
_080907E6:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080907EC: .4byte 0x00004038

	thumb_func_start FUN_080907f0
FUN_080907f0: @ 0x080907F0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	movs r4, #0
	ldr r1, _08090840 @ =0x030044E0
	ldrh r2, [r1]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	adds r3, r1, #0
	cmp r0, #0
	beq _080908A0
	adds r0, r6, #0
	bl FUN_08090724
	adds r4, r0, #0
	cmp r4, #0
	bne _0809081A
	b _0809090C
_0809081A:
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r1, _08090844 @ =0x00004038
	adds r0, r6, r1
	ldr r2, _08090848 @ =0x00004050
	adds r1, r6, r2
	ldrb r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08090850
	ldr r3, _0809084C @ =0x00002BEC
	adds r0, r6, r3
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	b _0809085A
	.align 2, 0
_08090840: .4byte 0x030044E0
_08090844: .4byte 0x00004038
_08090848: .4byte 0x00004050
_0809084C: .4byte 0x00002BEC
_08090850:
	ldr r0, _08090878 @ =0x00002BEC
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
_0809085A:
	ldr r1, _0809087C @ =0x00004038
	adds r0, r6, r1
	ldr r2, _08090880 @ =0x00004056
	adds r1, r6, r2
	ldrb r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08090888
	ldr r3, _08090884 @ =0x00002C4C
	adds r0, r6, r3
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _08090892
	.align 2, 0
_08090878: .4byte 0x00002BEC
_0809087C: .4byte 0x00004038
_08090880: .4byte 0x00004056
_08090884: .4byte 0x00002C4C
_08090888:
	ldr r1, _0809089C @ =0x00002C4C
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_08090892:
	str r1, [r0]
	adds r0, r6, #0
	bl FUN_0808fbf4
	b _0809090C
	.align 2, 0
_0809089C: .4byte 0x00002C4C
_080908A0:
	ldr r1, _080908C0 @ =0x00004039
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080908AC
	b _080909BE
_080908AC:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _080908C8
	ldr r2, _080908C4 @ =0x00004040
	adds r1, r6, r2
	ldrh r0, [r1]
	subs r0, #2
	b _080908D8
	.align 2, 0
_080908C0: .4byte 0x00004039
_080908C4: .4byte 0x00004040
_080908C8:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _080908DC
	ldr r0, _080908F0 @ =0x00004040
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #2
_080908D8:
	strh r0, [r1]
	movs r4, #1
_080908DC:
	ldrh r1, [r3]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080908F8
	ldr r2, _080908F4 @ =0x00004042
	adds r1, r6, r2
	ldrh r0, [r1]
	subs r0, #2
	b _08090908
	.align 2, 0
_080908F0: .4byte 0x00004040
_080908F4: .4byte 0x00004042
_080908F8:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0809090C
	ldr r3, _080909D0 @ =0x00004042
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #2
_08090908:
	strh r0, [r1]
	movs r4, #1
_0809090C:
	ldr r1, _080909D4 @ =0x00004039
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080909BE
	cmp r4, #0
	beq _080909BE
	adds r0, r6, #0
	bl FUN_08090040
	ldr r2, _080909D8 @ =0x00004040
	adds r0, r6, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r2, #0xc
	adds r0, r6, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r7, r1, r0
	ldr r1, _080909D0 @ =0x00004042
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _080909DC @ =0x0000404E
	adds r0, r6, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	mov r8, r1
	asrs r5, r7, #3
	asrs r4, r1, #3
	movs r0, #2
	rsbs r0, r0, #0
	ands r4, r0
	str r1, [sp]
	movs r0, #1
	adds r1, r5, #0
	adds r2, r4, #0
	adds r3, r7, #0
	bl FUN_0822c40c
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0808fe7c
	ldr r3, _080909E0 @ =0x00002BEC
	adds r0, r6, r3
	ldr r0, [r0]
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	bne _08090994
	ldr r1, _080909E4 @ =0x00004052
	adds r0, r6, r1
	ldrh r0, [r0]
	subs r0, r0, r7
	adds r3, #0x18
	adds r1, r6, r3
	strh r0, [r1]
	ldr r1, _080909E8 @ =0x00004054
	adds r0, r6, r1
	ldrh r0, [r0]
	mov r3, r8
	subs r0, r0, r3
	ldr r3, _080909EC @ =0x00002C06
	adds r1, r6, r3
	strh r0, [r1]
_08090994:
	ldr r1, _080909F0 @ =0x00002C4C
	adds r0, r6, r1
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	bne _080909BE
	ldr r2, _080909F4 @ =0x00004058
	adds r0, r6, r2
	ldrh r0, [r0]
	subs r0, r0, r7
	ldr r3, _080909F8 @ =0x00002C64
	adds r1, r6, r3
	strh r0, [r1]
	ldr r1, _080909FC @ =0x0000405A
	adds r0, r6, r1
	ldrh r0, [r0]
	mov r2, r8
	subs r0, r0, r2
	adds r3, #2
	adds r1, r6, r3
	strh r0, [r1]
_080909BE:
	adds r0, r6, #0
	bl FUN_08090120
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080909D0: .4byte 0x00004042
_080909D4: .4byte 0x00004039
_080909D8: .4byte 0x00004040
_080909DC: .4byte 0x0000404E
_080909E0: .4byte 0x00002BEC
_080909E4: .4byte 0x00004052
_080909E8: .4byte 0x00004054
_080909EC: .4byte 0x00002C06
_080909F0: .4byte 0x00002C4C
_080909F4: .4byte 0x00004058
_080909F8: .4byte 0x00002C64
_080909FC: .4byte 0x0000405A

	thumb_func_start FUN_08090a00
FUN_08090a00: @ 0x08090A00
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	ldr r0, _08090AD0 @ =0x030046A0
	ldr r4, [r0]
	ldr r0, _08090AD4 @ =0x00000256
	adds r6, r4, r0
	movs r1, #0
	ldrsh r0, [r6, r1]
	ldr r2, _08090AD8 @ =0x00004030
	adds r5, r3, r2
	ldr r1, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	ldr r7, _08090ADC @ =0x00004050
	adds r0, r3, r7
	strh r1, [r0]
	movs r1, #0
	ldrsh r0, [r6, r1]
	ldr r1, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	lsls r0, r0, #2
	adds r2, #0x22
	adds r2, r2, r3
	mov r8, r2
	strh r0, [r2]
	movs r7, #0
	ldrsh r0, [r6, r7]
	ldr r1, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #2]
	lsls r0, r0, #2
	ldr r2, _08090AE0 @ =0x00004054
	adds r1, r3, r2
	strh r0, [r1]
	movs r7, #0x95
	lsls r7, r7, #2
	adds r0, r4, r7
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r2, #0
	ldrsh r7, [r0, r2]
	mov ip, r7
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp ip, r0
	bne _08090AF8
	ldr r1, _08090AE4 @ =0x00000252
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _08090AF8
	ldr r7, _08090AE8 @ =0x0000025A
	adds r2, r4, r7
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldr r1, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	ldr r4, _08090AEC @ =0x00004056
	adds r0, r3, r4
	strh r1, [r0]
	movs r7, #0
	ldrsh r0, [r2, r7]
	ldr r1, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	lsls r0, r0, #2
	ldr r1, _08090AF0 @ =0x00004058
	adds r4, r3, r1
	strh r0, [r4]
	movs r7, #0
	ldrsh r0, [r2, r7]
	ldr r1, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #2]
	lsls r0, r0, #2
	ldr r5, _08090AF4 @ =0x0000405A
	adds r1, r3, r5
	strh r0, [r1]
	movs r7, #0
	ldrsh r1, [r6, r7]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	bne _08090B00
	mov r5, r8
	ldrh r0, [r5]
	subs r0, #4
	strh r0, [r5]
	ldrh r0, [r4]
	adds r0, #4
	strh r0, [r4]
	b _08090B00
	.align 2, 0
_08090AD0: .4byte 0x030046A0
_08090AD4: .4byte 0x00000256
_08090AD8: .4byte 0x00004030
_08090ADC: .4byte 0x00004050
_08090AE0: .4byte 0x00004054
_08090AE4: .4byte 0x00000252
_08090AE8: .4byte 0x0000025A
_08090AEC: .4byte 0x00004056
_08090AF0: .4byte 0x00004058
_08090AF4: .4byte 0x0000405A
_08090AF8:
	ldr r7, _08090B0C @ =0x00004056
	adds r1, r3, r7
	movs r0, #0xff
	strh r0, [r1]
_08090B00:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08090B0C: .4byte 0x00004056

	thumb_func_start FUN_08090b10
FUN_08090b10: @ 0x08090B10
	push {lr}
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08090B2A
	movs r0, #0
	b _08090B34
_08090B2A:
	cmp r0, #5
	beq _08090B32
	movs r0, #1
	b _08090B34
_08090B32:
	movs r0, #2
_08090B34:
	pop {r1}
	bx r1

	thumb_func_start FUN_08090b38
FUN_08090b38: @ 0x08090B38
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	bl FUN_08090148
	ldr r1, _08090C4C @ =0x0000403C
	adds r0, r6, r1
	ldr r1, [r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08090B84
	ldr r2, _08090C50 @ =0x00002164
	adds r0, r6, r2
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0x33
	movs r3, #1
	bl FUN_0822f3cc
	ldr r0, _08090C54 @ =0x0000216C
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08090C58 @ =0x00002184
	adds r0, r6, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08090C5C @ =0x00002186
	adds r0, r6, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r6, r2
	strh r1, [r0]
_08090B84:
	ldr r0, _08090C60 @ =0x00002BEC
	adds r1, r6, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	mov r8, r2
	ands r0, r2
	str r0, [r1]
	ldr r0, _08090C64 @ =0x00002BE4
	adds r4, r6, r0
	adds r5, r6, #0
	adds r5, #0x80
	adds r0, r6, #0
	bl FUN_08090b10
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl FUN_0822f3cc
	ldr r1, _08090C68 @ =0x00004052
	adds r2, r6, r1
	ldr r0, _08090C6C @ =0x00004040
	adds r7, r6, r0
	subs r1, #6
	adds r5, r6, r1
	ldrh r0, [r7]
	ldrh r1, [r5]
	subs r0, r0, r1
	ldrh r1, [r2]
	subs r1, r1, r0
	ldr r2, _08090C70 @ =0x00002C04
	adds r0, r6, r2
	movs r2, #0
	mov ip, r2
	strh r1, [r0]
	ldr r0, _08090C74 @ =0x00004054
	adds r2, r6, r0
	ldr r1, _08090C78 @ =0x00004042
	adds r4, r6, r1
	subs r0, #6
	adds r3, r6, r0
	ldrh r1, [r4]
	ldrh r0, [r3]
	subs r1, r1, r0
	ldrh r0, [r2]
	subs r0, r0, r1
	ldr r2, _08090C7C @ =0x00002C06
	adds r1, r6, r2
	strh r0, [r1]
	ldr r1, _08090C80 @ =0x00002C08
	adds r0, r6, r1
	mov r2, ip
	strh r2, [r0]
	ldr r1, _08090C84 @ =0x00004056
	adds r0, r6, r1
	ldr r2, _08090C88 @ =0x00004050
	adds r1, r6, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08090C42
	ldr r0, _08090C8C @ =0x00002C4C
	adds r1, r6, r0
	ldr r0, [r1]
	mov r2, r8
	ands r0, r2
	str r0, [r1]
	ldr r0, _08090C90 @ =0x00004058
	adds r2, r6, r0
	ldrh r1, [r7]
	ldrh r0, [r5]
	subs r1, r1, r0
	ldrh r0, [r2]
	subs r0, r0, r1
	ldr r2, _08090C94 @ =0x00002C64
	adds r1, r6, r2
	strh r0, [r1]
	ldr r0, _08090C98 @ =0x0000405A
	adds r2, r6, r0
	ldrh r1, [r4]
	ldrh r0, [r3]
	subs r1, r1, r0
	ldrh r0, [r2]
	subs r0, r0, r1
	ldr r2, _08090C9C @ =0x00002C66
	adds r1, r6, r2
	strh r0, [r1]
	ldr r1, _08090CA0 @ =0x00002C68
	adds r0, r6, r1
	mov r2, ip
	strh r2, [r0]
_08090C42:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08090C4C: .4byte 0x0000403C
_08090C50: .4byte 0x00002164
_08090C54: .4byte 0x0000216C
_08090C58: .4byte 0x00002184
_08090C5C: .4byte 0x00002186
_08090C60: .4byte 0x00002BEC
_08090C64: .4byte 0x00002BE4
_08090C68: .4byte 0x00004052
_08090C6C: .4byte 0x00004040
_08090C70: .4byte 0x00002C04
_08090C74: .4byte 0x00004054
_08090C78: .4byte 0x00004042
_08090C7C: .4byte 0x00002C06
_08090C80: .4byte 0x00002C08
_08090C84: .4byte 0x00004056
_08090C88: .4byte 0x00004050
_08090C8C: .4byte 0x00002C4C
_08090C90: .4byte 0x00004058
_08090C94: .4byte 0x00002C64
_08090C98: .4byte 0x0000405A
_08090C9C: .4byte 0x00002C66
_08090CA0: .4byte 0x00002C68

	thumb_func_start FUN_08090ca4
FUN_08090ca4: @ 0x08090CA4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08090148
	ldr r1, _08090D30 @ =0x0000403C
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08090CEC
	ldr r2, _08090D34 @ =0x00002164
	adds r0, r4, r2
	adds r1, r4, #0
	adds r1, #0x60
	movs r2, #0x33
	movs r3, #1
	bl FUN_0822f3cc
	ldr r0, _08090D38 @ =0x0000216C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08090D3C @ =0x00002184
	adds r0, r4, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08090D40 @ =0x00002186
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
_08090CEC:
	ldr r0, _08090D44 @ =0x00002BEC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08090D48 @ =0x00002BE4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x80
	movs r2, #8
	movs r3, #1
	bl FUN_0822f3cc
	ldr r2, _08090D4C @ =0x00002C04
	adds r0, r4, r2
	movs r1, #0
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _08090D50 @ =0x00002C4C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08090D30: .4byte 0x0000403C
_08090D34: .4byte 0x00002164
_08090D38: .4byte 0x0000216C
_08090D3C: .4byte 0x00002184
_08090D40: .4byte 0x00002186
_08090D44: .4byte 0x00002BEC
_08090D48: .4byte 0x00002BE4
_08090D4C: .4byte 0x00002C04
_08090D50: .4byte 0x00002C4C

	thumb_func_start FUN_08090d54
FUN_08090d54: @ 0x08090D54
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _08090D74 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x95
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #6
	ble _08090D78
	ldr r0, [r7, #0x24]
	b _08090D7A
	.align 2, 0
_08090D74: .4byte 0x030046A0
_08090D78:
	ldr r0, [r7, #0x20]
_08090D7A:
	str r0, [r7, #0x28]
	adds r0, r7, #0
	bl FUN_08090a00
	ldr r3, _08090DB0 @ =0x00004050
	adds r0, r7, r3
	ldrh r0, [r0]
	ldr r1, _08090DB4 @ =0x00004038
	adds r2, r7, r1
	strb r0, [r2]
	subs r3, #0x24
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _08090DBC
	ldrb r0, [r2]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	bl FUN_0808fd2c
	cmp r0, #0
	beq _08090DBC
	ldr r0, _08090DB8 @ =0x00004039
	adds r1, r7, r0
	movs r0, #1
	b _08090DC2
	.align 2, 0
_08090DB0: .4byte 0x00004050
_08090DB4: .4byte 0x00004038
_08090DB8: .4byte 0x00004039
_08090DBC:
	ldr r2, _08090E7C @ =0x00004039
	adds r1, r7, r2
	movs r0, #0
_08090DC2:
	strb r0, [r1]
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r2, [r7, #0x28]
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r3, sp, #0xc
	str r3, [sp, #8]
	movs r0, #6
	movs r1, #2
	movs r3, #0
	bl FUN_0822c0b8
	ldr r1, _08090E7C @ =0x00004039
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08090E9C
	adds r0, r7, #0
	bl FUN_0808ff84
	ldr r2, _08090E80 @ =0x00004052
	adds r1, r7, r2
	ldr r3, _08090E84 @ =0x0000404C
	adds r3, r3, r7
	mov r8, r3
	ldrh r0, [r3]
	ldrh r1, [r1]
	adds r0, r0, r1
	subs r0, #0x78
	ldr r1, _08090E88 @ =0x00004040
	adds r5, r7, r1
	strh r0, [r5]
	adds r2, #2
	adds r1, r7, r2
	ldr r3, _08090E8C @ =0x0000404E
	adds r6, r7, r3
	ldrh r0, [r6]
	ldrh r1, [r1]
	adds r0, r0, r1
	subs r0, #0x50
	ldr r1, _08090E90 @ =0x00004042
	adds r4, r7, r1
	strh r0, [r4]
	adds r0, r7, #0
	bl FUN_08090040
	adds r0, r7, #0
	bl FUN_08090b38
	ldr r1, [r7, #0x28]
	ldr r2, _08090E94 @ =0x00004038
	adds r0, r7, r2
	ldrb r0, [r0]
	ldr r3, _08090E98 @ =0x0000402C
	adds r2, r7, r3
	ldr r2, [r2]
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrb r2, [r0, #1]
	movs r0, #1
	bl FUN_0822c398
	movs r0, #0
	ldrsh r3, [r5, r0]
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	subs r3, r3, r0
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r2, #0
	ldrsh r0, [r6, r2]
	subs r1, r1, r0
	asrs r5, r3, #3
	asrs r4, r1, #3
	movs r0, #2
	rsbs r0, r0, #0
	ands r4, r0
	str r1, [sp]
	movs r0, #1
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0822c40c
	adds r0, r7, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0808fe7c
	b _08090EA8
	.align 2, 0
_08090E7C: .4byte 0x00004039
_08090E80: .4byte 0x00004052
_08090E84: .4byte 0x0000404C
_08090E88: .4byte 0x00004040
_08090E8C: .4byte 0x0000404E
_08090E90: .4byte 0x00004042
_08090E94: .4byte 0x00004038
_08090E98: .4byte 0x0000402C
_08090E9C:
	adds r0, r7, #0
	bl FUN_08090698
	adds r0, r7, #0
	bl FUN_08090ca4
_08090EA8:
	ldr r0, [r7, #0x50]
	bl FUN_080478f0
	ldr r0, _08090ED8 @ =0x0000EFDA
	bl FUN_08047dc0
	movs r0, #1
	bl FUN_080477e4
	adds r0, r7, #0
	bl FUN_0808fbf4
	ldr r1, _08090EDC @ =FUN_080907f0
	adds r0, r7, #0
	movs r2, #0
	bl FUN_0808a354
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08090ED8: .4byte 0x0000EFDA
_08090EDC: .4byte FUN_080907f0

	thumb_func_start FUN_08090ee0
FUN_08090ee0: @ 0x08090EE0
	push {lr}
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _08090F04
	bl fetch_082316e4
	ldr r1, _08090F08 @ =0x030046A0
	ldr r2, [r1]
	movs r1, #0x99
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08090F04:
	pop {r0}
	bx r0
	.align 2, 0
_08090F08: .4byte 0x030046A0

	thumb_func_start FUN_08090f0c
FUN_08090f0c: @ 0x08090F0C
	ldr r1, _08090F20 @ =0x030046A0
	ldr r2, [r1]
	movs r1, #0x99
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	bx lr
	.align 2, 0
_08090F20: .4byte 0x030046A0

	thumb_func_start FUN_08090f24
FUN_08090f24: @ 0x08090F24
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r1
	mov r8, r2
	movs r7, #0
	mov r0, sb
	adds r0, #0x20
	str r0, [sp, #4]
	movs r1, #0x20
	add r1, r8
	mov sl, r1
_08090F42:
	ldr r1, _08091074 @ =0x085ACEA0
	lsls r0, r7, #2
	adds r4, r0, r1
	ldrb r0, [r4, #3]
	bl FUN_08090f0c
	cmp r0, #0
	beq _08091004
	ldrb r5, [r4]
	ldrb r6, [r4, #1]
	ldrb r0, [r4, #2]
	movs r2, #8
	str r2, [sp]
	cmp r0, #0
	beq _08090F64
	movs r0, #0xc
	str r0, [sp]
_08090F64:
	cmp r5, sb
	blt _08090F8A
	ldr r1, [sp, #4]
	cmp r5, r1
	bge _08090F8A
	cmp r6, r8
	blt _08090F8A
	cmp r6, sl
	bge _08090F8A
	movs r0, #1
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0808a420
	adds r1, r0, #0
	ldr r0, [sp]
	ldr r2, _08091078 @ =0xFFFFE000
	orrs r0, r2
	strh r0, [r1]
_08090F8A:
	adds r4, r5, #1
	cmp r4, sb
	blt _08090FB4
	ldr r0, [sp, #4]
	cmp r4, r0
	bge _08090FB4
	cmp r6, r8
	blt _08090FB4
	cmp r6, sl
	bge _08090FB4
	movs r0, #1
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_0808a420
	adds r1, r0, #0
	ldr r0, [sp]
	adds r0, #1
	ldr r2, _08091078 @ =0xFFFFE000
	orrs r0, r2
	strh r0, [r1]
_08090FB4:
	cmp r5, sb
	blt _08090FDC
	ldr r0, [sp, #4]
	cmp r5, r0
	bge _08090FDC
	adds r2, r6, #1
	cmp r2, r8
	blt _08090FDC
	cmp r2, sl
	bge _08090FDC
	movs r0, #1
	adds r1, r5, #0
	bl FUN_0808a420
	adds r1, r0, #0
	ldr r0, [sp]
	adds r0, #0x10
	ldr r2, _08091078 @ =0xFFFFE000
	orrs r0, r2
	strh r0, [r1]
_08090FDC:
	cmp r4, sb
	blt _08091004
	ldr r0, [sp, #4]
	cmp r4, r0
	bge _08091004
	adds r2, r6, #1
	cmp r2, r8
	blt _08091004
	cmp r2, sl
	bge _08091004
	movs r0, #1
	adds r1, r4, #0
	bl FUN_0808a420
	adds r1, r0, #0
	ldr r0, [sp]
	adds r0, #0x11
	ldr r2, _08091078 @ =0xFFFFE000
	orrs r0, r2
	strh r0, [r1]
_08091004:
	adds r7, #1
	cmp r7, #9
	ble _08090F42
	movs r0, #0xe
	bl FUN_08090f0c
	cmp r0, #0
	bne _08091062
	movs r6, #0
	movs r7, #0
_08091018:
	movs r5, #0
	adds r0, r7, #1
	mov r8, r0
_0809101E:
	adds r0, r7, r5
	cmp r0, #1
	ble _08091056
	cmp r0, #8
	bgt _08091056
	subs r0, r7, r5
	cmp r0, #3
	bgt _08091056
	adds r4, r6, #0
	adds r4, #0x11
	cmp r6, #1
	bgt _08091038
	adds r4, r6, #3
_08091038:
	adds r1, r5, #0
	adds r1, #0x2b
	movs r0, #1
	adds r2, r7, #0
	adds r2, #0xf
	bl FUN_0808a420
	ldr r2, _08091078 @ =0xFFFFE000
	adds r1, r2, #0
	orrs r4, r1
	strh r4, [r0]
	adds r6, #1
	cmp r6, #3
	ble _08091056
	movs r6, #0
_08091056:
	adds r5, #1
	cmp r5, #5
	ble _0809101E
	mov r7, r8
	cmp r7, #5
	ble _08091018
_08091062:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08091074: .4byte 0x085ACEA0
_08091078: .4byte 0xFFFFE000

	thumb_func_start FUN_0809107c
FUN_0809107c: @ 0x0809107C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	movs r3, #0
	ldr r1, _080910A4 @ =0x030044E0
	ldrh r2, [r1]
	movs r0, #0x20
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _080910AC
	ldr r0, _080910A8 @ =0x00004040
	adds r1, r5, r0
	ldrh r0, [r1]
	subs r0, #2
	b _080910BC
	.align 2, 0
_080910A4: .4byte 0x030044E0
_080910A8: .4byte 0x00004040
_080910AC:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _080910C0
	ldr r2, _080910D8 @ =0x00004040
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #2
_080910BC:
	strh r0, [r1]
	movs r3, #1
_080910C0:
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080910E0
	ldr r3, _080910DC @ =0x00004042
	adds r1, r5, r3
	ldrh r0, [r1]
	subs r0, #2
	strh r0, [r1]
	b _080910FA
	.align 2, 0
_080910D8: .4byte 0x00004040
_080910DC: .4byte 0x00004042
_080910E0:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080910F4
	ldr r7, _0809123C @ =0x00004042
	adds r1, r5, r7
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	movs r3, #1
_080910F4:
	cmp r3, #0
	bne _080910FA
	b _08091226
_080910FA:
	adds r0, r5, #0
	bl FUN_08090040
	ldr r0, _08091240 @ =0x00004040
	adds r7, r5, r0
	ldrh r1, [r7]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x13
	ldr r2, _0809123C @ =0x00004042
	adds r6, r5, r2
	ldrh r2, [r6]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x13
	movs r4, #2
	rsbs r4, r4, #0
	ands r2, r4
	movs r0, #0
	ldrsh r3, [r7, r0]
	mov r8, r3
	movs r3, #0
	ldrsh r0, [r6, r3]
	str r0, [sp]
	movs r0, #1
	mov r3, r8
	bl FUN_0822c40c
	ldrh r1, [r7]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x13
	ldrh r2, [r6]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x13
	ands r2, r4
	adds r0, r5, #0
	bl FUN_08090f24
	ldr r1, _08091244 @ =0x00004052
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r1, [r7]
	subs r0, r0, r1
	ldr r2, _08091248 @ =0x00002C04
	adds r1, r5, r2
	strh r0, [r1]
	ldr r3, _0809124C @ =0x00004054
	adds r0, r5, r3
	ldrh r0, [r0]
	ldrh r1, [r6]
	subs r0, r0, r1
	adds r2, #2
	adds r1, r5, r2
	strh r0, [r1]
	ldr r3, _08091250 @ =0x00002C4C
	adds r0, r5, r3
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08091190
	ldr r1, _08091254 @ =0x00004058
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r1, [r7]
	subs r0, r0, r1
	adds r2, #0x5e
	adds r1, r5, r2
	strh r0, [r1]
	ldr r3, _08091258 @ =0x0000405A
	adds r0, r5, r3
	ldrh r0, [r0]
	ldrh r1, [r6]
	subs r0, r0, r1
	adds r2, #2
	adds r1, r5, r2
	strh r0, [r1]
_08091190:
	mov sb, r7
	adds r2, r6, #0
	movs r7, #0x81
	lsls r7, r7, #6
	adds r3, r5, r7
	ldr r0, _0809125C @ =0x00002FAC
	adds r4, r5, r0
	movs r1, #1
	mov r8, r1
	ldr r7, _08091260 @ =0x00000F84
	mov ip, r7
	movs r6, #5
_080911A8:
	ldr r0, [r4]
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	bne _080911C8
	mov r7, sb
	ldrh r0, [r7]
	rsbs r0, r0, #0
	mov r7, ip
	adds r1, r3, r7
	strh r0, [r1]
	ldrh r0, [r2]
	rsbs r0, r0, #0
	ldr r7, _08091264 @ =0x00000F86
	adds r1, r3, r7
	strh r0, [r1]
_080911C8:
	adds r3, #0x60
	adds r4, #0x60
	subs r6, #1
	cmp r6, #0
	bge _080911A8
	ldr r0, _08091268 @ =0x085ACE3C
	ldr r1, _08091240 @ =0x00004040
	adds r1, r1, r5
	mov ip, r1
	ldr r2, _0809123C @ =0x00004042
	adds r2, r2, r5
	mov r8, r2
	adds r4, r0, #0
	adds r4, #0x1c
	movs r3, #0x8a
	lsls r3, r3, #6
	adds r2, r5, r3
	ldr r7, _0809126C @ =0x000031EC
	adds r3, r5, r7
	movs r6, #7
_080911F0:
	ldr r0, [r3]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0809121A
	ldrb r1, [r4]
	lsls r1, r1, #2
	mov r7, ip
	ldrh r0, [r7]
	subs r1, r1, r0
	ldr r7, _08091260 @ =0x00000F84
	adds r0, r2, r7
	strh r1, [r0]
	ldrb r1, [r4, #1]
	lsls r1, r1, #2
	mov r7, r8
	ldrh r0, [r7]
	subs r1, r1, r0
	ldr r7, _08091264 @ =0x00000F86
	adds r0, r2, r7
	strh r1, [r0]
_0809121A:
	adds r4, #4
	adds r2, #0x60
	adds r3, #0x60
	subs r6, #1
	cmp r6, #0
	bge _080911F0
_08091226:
	adds r0, r5, #0
	bl FUN_08090120
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809123C: .4byte 0x00004042
_08091240: .4byte 0x00004040
_08091244: .4byte 0x00004052
_08091248: .4byte 0x00002C04
_0809124C: .4byte 0x00004054
_08091250: .4byte 0x00002C4C
_08091254: .4byte 0x00004058
_08091258: .4byte 0x0000405A
_0809125C: .4byte 0x00002FAC
_08091260: .4byte 0x00000F84
_08091264: .4byte 0x00000F86
_08091268: .4byte 0x085ACE3C
_0809126C: .4byte 0x000031EC

	thumb_func_start FUN_08091270
FUN_08091270: @ 0x08091270
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r7, r0, #0
	ldr r2, [r7, #0x1c]
	str r2, [r7, #0x28]
	movs r0, #0
	str r0, [sp, #0xc]
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #6
	movs r1, #2
	movs r3, #0
	bl FUN_0822c0b8
	ldr r6, _0809152C @ =0x085ACE3C
	ldr r0, _08091530 @ =0x030046A0
	ldr r2, [r0]
	movs r1, #0x95
	lsls r1, r1, #2
	adds r4, r2, r1
	movs r3, #0
	ldrsh r0, [r4, r3]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #2
	ldr r1, _08091534 @ =0x00004052
	adds r5, r7, r1
	strh r0, [r5]
	movs r3, #0
	ldrsh r0, [r4, r3]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrb r0, [r0, #1]
	lsls r0, r0, #2
	ldr r3, _08091538 @ =0x00004054
	adds r1, r7, r3
	strh r0, [r1]
	ldr r1, _0809153C @ =0x00000252
	adds r0, r2, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _08091318
	movs r0, #0x96
	lsls r0, r0, #2
	adds r2, r2, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r0, r0, #2
	ldr r1, _08091540 @ =0x00004058
	adds r3, r7, r1
	strh r0, [r3]
	movs r1, #0
	ldrsh r0, [r2, r1]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrb r0, [r0, #1]
	lsls r0, r0, #2
	ldr r6, _08091544 @ =0x0000405A
	adds r1, r7, r6
	strh r0, [r1]
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _08091318
	ldrh r0, [r5]
	subs r0, #4
	strh r0, [r5]
	ldrh r0, [r3]
	adds r0, #4
	strh r0, [r3]
_08091318:
	ldr r3, _08091548 @ =0x00004044
	adds r0, r7, r3
	movs r4, #0
	strh r4, [r0]
	ldr r5, _0809154C @ =0x00004046
	adds r0, r7, r5
	strh r4, [r0]
	ldr r6, _08091550 @ =0x00004048
	adds r1, r7, r6
	movs r0, #0x88
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r0, _08091554 @ =0x0000404A
	adds r1, r7, r0
	movs r0, #0xb0
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r1, _08091534 @ =0x00004052
	adds r6, r7, r1
	ldrh r0, [r6]
	subs r0, #0x78
	ldr r2, _08091558 @ =0x00004040
	adds r2, r2, r7
	mov sl, r2
	strh r0, [r2]
	adds r3, #0x10
	adds r3, r3, r7
	mov r8, r3
	ldrh r0, [r3]
	subs r0, #0x50
	ldr r4, _0809155C @ =0x00004042
	adds r4, r4, r7
	mov sb, r4
	strh r0, [r4]
	adds r0, r7, #0
	bl FUN_08090040
	mov r5, sl
	ldrh r1, [r5]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x13
	ldrh r2, [r4]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x13
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	movs r4, #0
	ldrsh r3, [r5, r4]
	mov r5, sb
	movs r4, #0
	ldrsh r0, [r5, r4]
	str r0, [sp]
	movs r0, #1
	bl FUN_0822c40c
	ldr r5, _08091560 @ =0x00002BEC
	adds r1, r7, r5
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldr r3, _08091564 @ =0x00002BE4
	adds r4, r7, r3
	adds r5, r7, #0
	adds r5, #0x80
	adds r0, r7, #0
	bl FUN_08090b10
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl FUN_0822f3cc
	ldrh r0, [r6]
	mov r4, sl
	ldrh r1, [r4]
	subs r0, r0, r1
	ldr r5, _08091568 @ =0x00002C04
	adds r1, r7, r5
	strh r0, [r1]
	mov r6, r8
	ldrh r0, [r6]
	mov r2, sb
	ldrh r1, [r2]
	subs r0, r0, r1
	ldr r3, _0809156C @ =0x00002C06
	adds r1, r7, r3
	strh r0, [r1]
	ldr r4, _08091570 @ =0x00002C08
	adds r0, r7, r4
	movs r5, #0
	strh r5, [r0]
	ldr r0, _08091530 @ =0x030046A0
	ldr r0, [r0]
	ldr r6, _0809153C @ =0x00000252
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _08091424
	ldr r2, _08091574 @ =0x00002C4C
	adds r1, r7, r2
	ldr r0, [r1]
	movs r3, #2
	rsbs r3, r3, #0
	ands r0, r3
	str r0, [r1]
	ldr r4, _08091540 @ =0x00004058
	adds r0, r7, r4
	ldrh r0, [r0]
	mov r5, sl
	ldrh r1, [r5]
	subs r0, r0, r1
	ldr r6, _08091578 @ =0x00002C64
	adds r1, r7, r6
	strh r0, [r1]
	ldr r1, _08091544 @ =0x0000405A
	adds r0, r7, r1
	ldrh r0, [r0]
	mov r2, sb
	ldrh r1, [r2]
	subs r0, r0, r1
	ldr r3, _0809157C @ =0x00002C66
	adds r1, r7, r3
	strh r0, [r1]
	ldr r4, _08091580 @ =0x00002C68
	adds r0, r7, r4
	movs r5, #0
	strh r5, [r0]
_08091424:
	mov r6, sl
	ldrh r1, [r6]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x13
	mov r0, sb
	ldrh r2, [r0]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x13
	movs r3, #2
	rsbs r3, r3, #0
	ands r2, r3
	adds r0, r7, #0
	bl FUN_08090f24
	movs r5, #0
	mov r8, r5
	ldr r6, _08091584 @ =0x00002FC4
	adds r4, r7, r6
	movs r6, #0x81
	lsls r6, r6, #6
_0809144C:
	adds r0, r5, #0
	bl FUN_08090f0c
	cmp r0, #0
	beq _0809147E
	ldr r0, _08091588 @ =0x00000F6C
	adds r2, r7, r0
	adds r2, r2, r6
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08091558 @ =0x00004040
	adds r0, r7, r1
	ldrh r0, [r0]
	rsbs r0, r0, #0
	strh r0, [r4]
	ldr r2, _0809155C @ =0x00004042
	adds r0, r7, r2
	ldrh r0, [r0]
	rsbs r0, r0, #0
	strh r0, [r4, #2]
	mov r3, r8
	strh r3, [r4, #4]
_0809147E:
	adds r4, #0x60
	adds r6, #0x60
	adds r5, #1
	cmp r5, #5
	ble _0809144C
	movs r5, #0
	mov r8, r5
	ldr r6, _0809158C @ =0x00003204
	adds r4, r7, r6
	movs r3, #0x8a
	lsls r3, r3, #6
	ldr r0, _0809152C @ =0x085ACE3C
	adds r6, r0, #0
	adds r6, #0x1c
_0809149A:
	adds r0, r5, #6
	str r3, [sp, #0x10]
	bl FUN_08090f0c
	ldr r3, [sp, #0x10]
	cmp r0, #0
	beq _080914D8
	ldr r0, _08091588 @ =0x00000F6C
	adds r2, r7, r0
	adds r2, r2, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldrb r1, [r6]
	lsls r1, r1, #2
	ldr r2, _08091558 @ =0x00004040
	adds r0, r7, r2
	ldrh r0, [r0]
	subs r1, r1, r0
	strh r1, [r4]
	ldrb r1, [r6, #1]
	lsls r1, r1, #2
	adds r2, #2
	adds r0, r7, r2
	ldrh r0, [r0]
	subs r1, r1, r0
	strh r1, [r4, #2]
	mov r0, r8
	strh r0, [r4, #4]
_080914D8:
	adds r4, #0x60
	adds r3, #0x60
	adds r6, #4
	adds r5, #1
	cmp r5, #7
	ble _0809149A
	ldr r0, [r7, #0x50]
	bl FUN_080478f0
	ldr r0, _08091590 @ =0x0000EFDA
	bl FUN_08047dc0
	movs r0, #1
	bl FUN_080477e4
	ldr r1, _0809152C @ =0x085ACE3C
	ldr r0, _08091530 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #3]
	bl FUN_08047a28
	ldr r1, _08091594 @ =FUN_0809107c
	adds r0, r7, #0
	movs r2, #0
	bl FUN_0808a354
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809152C: .4byte 0x085ACE3C
_08091530: .4byte 0x030046A0
_08091534: .4byte 0x00004052
_08091538: .4byte 0x00004054
_0809153C: .4byte 0x00000252
_08091540: .4byte 0x00004058
_08091544: .4byte 0x0000405A
_08091548: .4byte 0x00004044
_0809154C: .4byte 0x00004046
_08091550: .4byte 0x00004048
_08091554: .4byte 0x0000404A
_08091558: .4byte 0x00004040
_0809155C: .4byte 0x00004042
_08091560: .4byte 0x00002BEC
_08091564: .4byte 0x00002BE4
_08091568: .4byte 0x00002C04
_0809156C: .4byte 0x00002C06
_08091570: .4byte 0x00002C08
_08091574: .4byte 0x00002C4C
_08091578: .4byte 0x00002C64
_0809157C: .4byte 0x00002C66
_08091580: .4byte 0x00002C68
_08091584: .4byte 0x00002FC4
_08091588: .4byte 0x00000F6C
_0809158C: .4byte 0x00003204
_08091590: .4byte 0x0000EFDA
_08091594: .4byte FUN_0809107c

	thumb_func_start FUN_08091598
FUN_08091598: @ 0x08091598
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	bl FUN_08047864
	bl FUN_08049e5c
	bl FUN_08049fa8
	movs r0, #0
	movs r1, #0x12
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	ldr r0, _08091644 @ =0x0000402C
	adds r3, r6, r0
	ldr r2, _08091648 @ =0x085ACEC8
	ldr r5, _0809164C @ =0x030046A0
	ldr r1, [r5]
	movs r4, #0x95
	lsls r4, r4, #2
	adds r1, r1, r4
	movs r7, #0
	ldrsh r0, [r1, r7]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r3]
	ldr r0, _08091650 @ =0x00004030
	adds r3, r6, r0
	ldr r2, _08091654 @ =0x085ACF04
	movs r7, #0
	ldrsh r0, [r1, r7]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r3]
	ldr r0, _08091658 @ =0x00004034
	adds r3, r6, r0
	ldr r2, _0809165C @ =0x085ACF40
	movs r7, #0
	ldrsh r0, [r1, r7]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r3]
	adds r0, r6, #0
	bl FUN_0808b82c
	ldr r1, _08091660 @ =0x00000F56
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r6, #0
	bl FUN_0808b86c
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0x18
	bl FUN_0808c61c
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0808c658
	ldr r0, [r5]
	adds r0, r0, r4
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #0xe
	ble _08091664
	ldr r1, [r6, #0x18]
	ldr r0, [r6, #0x38]
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #5
	bl FUN_0808a3c4
	adds r0, r6, #0
	bl FUN_08091270
	b _0809167A
	.align 2, 0
_08091644: .4byte 0x0000402C
_08091648: .4byte 0x085ACEC8
_0809164C: .4byte 0x030046A0
_08091650: .4byte 0x00004030
_08091654: .4byte 0x085ACF04
_08091658: .4byte 0x00004034
_0809165C: .4byte 0x085ACF40
_08091660: .4byte 0x00000F56
_08091664:
	ldr r1, [r6, #0x18]
	ldr r0, [r6, #0x34]
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #5
	bl FUN_0808a3c4
	adds r0, r6, #0
	bl FUN_08090d54
_0809167A:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08091684
FUN_08091684: @ 0x08091684
	push {r4, r5, r6, lr}
	ldr r5, _080916B8 @ =0x03002C10
	movs r0, #0
	strh r0, [r5]
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _080916B2
	movs r4, #0
	movs r6, #1
_0809169A:
	bl fetch_082316e4
	cmp r0, #0
	beq _080916AC
	adds r0, r6, #0
	lsls r0, r4
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_080916AC:
	adds r4, #1
	cmp r4, #3
	ble _0809169A
_080916B2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080916B8: .4byte 0x03002C10

	thumb_func_start FUN_080916bc
FUN_080916bc: @ 0x080916BC
	adds r2, r0, #0
	ldr r0, _080916CC @ =0x03002C10
	ldrh r0, [r0]
	movs r1, #1
	lsls r1, r2
	ands r0, r1
	bx lr
	.align 2, 0
_080916CC: .4byte 0x03002C10

	thumb_func_start FUN_080916d0
FUN_080916d0: @ 0x080916D0
	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	strb r6, [r0]
	movs r4, #0
	adds r1, r0, #0
	adds r1, #8
	movs r2, #0x28
	adds r2, r2, r0
	mov ip, r2
	adds r7, r0, #0
	adds r7, #0x2b
_080916E6:
	lsls r0, r4, #2
	movs r3, #3
	adds r2, r0, #3
	adds r0, r4, r1
	adds r0, #0xc
_080916F0:
	strb r2, [r0]
	subs r2, #1
	subs r0, #4
	subs r3, #1
	cmp r3, #0
	bge _080916F0
	adds r4, #1
	cmp r4, #3
	ble _080916E6
	movs r0, #1
	ands r0, r6
	cmp r0, #0
	beq _0809172A
	movs r4, #0
	movs r2, #0x10
	adds r5, r1, #0
	adds r5, #0x10
_08091712:
	movs r3, #3
	adds r0, r4, r5
	adds r0, #0xc
_08091718:
	strb r2, [r0]
	subs r0, #4
	subs r3, #1
	cmp r3, #0
	bge _08091718
	adds r4, #1
	cmp r4, #3
	ble _08091712
	b _08091748
_0809172A:
	movs r4, #0
	movs r5, #0xff
	adds r1, #0x10
_08091730:
	adds r2, r4, r1
	movs r3, #3
_08091734:
	ldrb r0, [r2]
	orrs r0, r5
	strb r0, [r2]
	adds r2, #4
	subs r3, #1
	cmp r3, #0
	bge _08091734
	adds r4, #1
	cmp r4, #3
	ble _08091730
_08091748:
	movs r4, #0
	mov r2, ip
	movs r3, #0xff
_0809174E:
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r4, #1
	cmp r4, #2
	ble _0809174E
	movs r0, #0x20
	ands r0, r6
	cmp r0, #0
	beq _08091768
	movs r0, #0x15
	b _0809176A
_08091768:
	movs r0, #0xff
_0809176A:
	strb r0, [r7]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
