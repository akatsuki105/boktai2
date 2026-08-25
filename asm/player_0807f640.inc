	.include "asm/macros.inc"

	.syntax unified
	
	.text

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

	thumb_func_start FUN_0807f94c
FUN_0807f94c: @ 0x0807F94C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xee
	ldrh r0, [r5]
	cmp r0, #0
	bne _0807F972
	movs r2, #4
	ldr r1, _0807F9C8 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0807F9CC @ =0x00000302
	bl PlaySound_082406e0
	movs r0, #0xfd
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0807F972:
	ldr r0, _0807F9D0 @ =0x03002BE0
	ldr r2, [r0]
	adds r1, r2, #0
	adds r1, #0x90
	ldr r0, [r1]
	movs r6, #1
	orrs r0, r6
	str r0, [r1]
	adds r3, r4, #0
	adds r3, #0x5e
	movs r0, #0
	ldrsh r1, [r3, r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	movs r7, #0x2e
	ldrsh r1, [r2, r7]
	adds r0, r0, r1
	adds r0, #0x96
	asrs r0, r0, #4
	strh r0, [r3]
	adds r0, r4, #0
	adds r0, #0x3c
	adds r1, r4, #0
	adds r1, #0x1c
	bl FUN_082372cc
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _0807F9C2
	adds r0, r4, #0
	adds r0, #0x56
	strb r6, [r0]
	ldr r1, _0807F9D4 @ =FUN_0807f9d8
	adds r0, r4, #0
	bl FUN_0807f640
_0807F9C2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807F9C8: .4byte 0x030044BC
_0807F9CC: .4byte 0x00000302
_0807F9D0: .4byte 0x03002BE0
_0807F9D4: .4byte FUN_0807f9d8

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

	thumb_func_start FUN_0807fe24
FUN_0807fe24: @ 0x0807FE24
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x3c
	bl FUN_0822f1c0
	adds r4, #0xf8
	movs r5, #0xf
_0807FE32:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x3c
	subs r5, #1
	cmp r5, #0
	bge _0807FE32
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

