	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08017b70
FUN_08017b70: @ 0x08017B70
	push {lr}
	ldr r0, _08017B80 @ =0x03000084
	ldr r0, [r0]
	cmp r0, #0
	bne _08017B84
	movs r0, #0
	b _08017B86
	.align 2, 0
_08017B80: .4byte 0x03000084
_08017B84:
	movs r0, #1
_08017B86:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08017b8c
FUN_08017b8c: @ 0x08017B8C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2c]
	strh r0, [r4, #0x20]
	ldrh r0, [r4, #0x2e]
	cmp r0, #0
	beq _08017BBA
	ldr r2, _08017BCC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08017BD0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08017BD4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r4, #0x2e]
	bl Mod
	ldrh r1, [r4, #0x20]
	adds r1, r1, r0
	strh r1, [r4, #0x20]
_08017BBA:
	ldrh r0, [r4, #0x20]
	cmp r0, #9
	bhi _08017BC4
	movs r0, #0xa
	strh r0, [r4, #0x20]
_08017BC4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08017BCC: .4byte 0x030046B8
_08017BD0: .4byte 0x000003FF
_08017BD4: .4byte 0x0203B400

	thumb_func_start FUN_08017bd8
FUN_08017bd8: @ 0x08017BD8
	movs r2, #0
	strb r1, [r0, #0x19]
	str r2, [r0, #0x1c]
	movs r1, #1
	strb r1, [r0, #0x18]
	bx lr

	thumb_func_start FUN_08017be4
FUN_08017be4: @ 0x08017BE4
	push {r4, lr}
	adds r1, r0, #0
	ldr r0, _08017C00 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08017C04 @ =0x000002B2
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _08017C08
	movs r0, #0x32
	ldrsh r4, [r1, r0]
	b _08017C14
	.align 2, 0
_08017C00: .4byte 0x030046A0
_08017C04: .4byte 0x000002B2
_08017C08:
	movs r2, #0x30
	ldrsh r0, [r1, r2]
	movs r2, #0x32
	ldrsh r1, [r1, r2]
	muls r0, r1, r0
	asrs r4, r0, #6
_08017C14:
	bl FUN_0823e1b0
	adds r1, r0, #0
	subs r0, r1, #4
	cmp r0, #1
	bls _08017C24
	cmp r1, #0
	bne _08017C26
_08017C24:
	asrs r4, r4, #1
_08017C26:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08017c30
FUN_08017c30: @ 0x08017C30
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r3, _08017C8C @ =0x030047C8
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r2, _08017C90 @ =0x03003540
	movs r4, #8
	ldrsh r0, [r2, r4]
	adds r7, r1, r0
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r3, #0xa
	ldrsh r0, [r2, r3]
	adds r1, r1, r0
	mov r8, r1
	ldr r0, [r6, #0x4c]
	cmp r0, #0
	bne _08017CA0
	ldr r5, _08017C94 @ =0x0203B400
	ldr r4, _08017C98 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _08017C9C @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r2, #0x7f
	ands r1, r2
	adds r1, #0x80
	str r1, [r6, #0x4c]
	adds r0, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	subs r0, #1
	str r0, [r6, #0x48]
	b _08017CA4
	.align 2, 0
_08017C8C: .4byte 0x030047C8
_08017C90: .4byte 0x03003540
_08017C94: .4byte 0x0203B400
_08017C98: .4byte 0x030046B8
_08017C9C: .4byte 0x000003FF
_08017CA0:
	subs r0, #1
	str r0, [r6, #0x4c]
_08017CA4:
	ldr r1, [r6, #0x5c]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08017CC2
	ldr r0, [r6, #0x44]
	ldr r2, [r6, #0x48]
	cmp r0, r2
	bge _08017CBA
	adds r0, #1
	b _08017CC0
_08017CBA:
	cmp r0, r2
	ble _08017CC2
	subs r0, #1
_08017CC0:
	str r0, [r6, #0x44]
_08017CC2:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08017CDE
	ldr r0, [r6, #0x34]
	adds r0, #3
	ldr r1, [r6, #0x44]
	adds r0, r0, r1
	str r0, [r6, #0x34]
	ldr r0, [r6, #0x3c]
	subs r0, #8
	subs r0, r0, r1
	str r0, [r6, #0x3c]
	b _08017CF0
_08017CDE:
	ldr r0, [r6, #0x38]
	adds r0, #6
	ldr r1, [r6, #0x44]
	adds r0, r0, r1
	str r0, [r6, #0x38]
	ldr r0, [r6, #0x40]
	subs r0, #0x10
	subs r0, r0, r1
	str r0, [r6, #0x40]
_08017CF0:
	ldr r1, [r6, #0x50]
	lsls r1, r1, #2
	adds r0, r6, #0
	adds r0, #0x34
	adds r0, r0, r1
	ldr r5, [r0]
	adds r5, r7, r5
	movs r2, #0xff
	ands r5, r2
	adds r0, r6, #0
	adds r0, #0x3c
	adds r0, r0, r1
	ldr r4, [r0]
	add r4, r8
	ands r4, r2
	adds r0, r7, #0
	subs r0, #0x80
	movs r1, #8
	bl Div
	adds r6, r0, #0
	mov r0, r8
	subs r0, #0x80
	movs r1, #8
	bl Div
	movs r2, #2
	rsbs r2, r2, #0
	ands r2, r0
	str r4, [sp]
	movs r0, #1
	adds r1, r6, #0
	adds r3, r5, #0
	bl Video_GenerateBGMap
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08017d44
FUN_08017d44: @ 0x08017D44
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	ldr r0, _08017DBC @ =0x00001C1C
	bl GetParticleGroup
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r1, r4, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0x60
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	movs r0, #0xb4
	lsls r0, r0, #1
	adds r5, r4, r0
	mov r8, r1
	adds r6, r4, r2
	movs r7, #0x1f
	movs r2, #4
	rsbs r2, r2, #0
	mov sb, r2
_08017D7A:
	adds r4, r5, #0
	adds r4, #0x14
	mov r0, r8
	strb r0, [r5]
	strb r0, [r5, #1]
	strb r0, [r5, #2]
	ldr r1, [r6]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822da70
	adds r0, r4, #0
	mov r1, sb
	mov r2, sb
	bl FUN_0822dad4
	ldr r1, [r6]
	adds r0, r4, #0
	movs r2, #0x1e
	bl FUN_0822dafc
	subs r7, #1
	adds r5, #0x3c
	cmp r7, #0
	bge _08017D7A
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08017DBC: .4byte 0x00001C1C

	thumb_func_start FUN_08017dc0
FUN_08017dc0: @ 0x08017DC0
	push {r4, r5, lr}
	adds r1, r0, #0
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r4, r1, r2
	movs r5, #0x1f
_08017DCC:
	adds r2, r4, #0
	adds r2, #0x14
	ldrb r1, [r4]
	cmp r1, #0
	beq _08017DE0
	adds r0, r2, #0
	bl FUN_0822dabc
	movs r1, #0
	strb r1, [r4]
_08017DE0:
	subs r5, #1
	adds r4, #0x3c
	cmp r5, #0
	bge _08017DCC
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08017df0
FUN_08017df0: @ 0x08017DF0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xb4
	lsls r1, r1, #1
	adds r4, r6, r1
	movs r7, #0x1f
_08017DFC:
	adds r3, r4, #0
	adds r3, #0x14
	ldrb r1, [r4]
	cmp r1, #0
	beq _08017E5C
	ldrb r1, [r4, #3]
	lsls r1, r1, #3
	adds r1, r1, r4
	ldr r2, [r1, #8]
	ldr r1, [r1, #4]
	str r1, [r4, #0x2c]
	str r2, [r4, #0x30]
	ldrb r2, [r4, #3]
	movs r1, #1
	subs r1, r1, r2
	movs r5, #0
	strb r1, [r4, #3]
	ldrb r1, [r4, #2]
	cmp r1, #0
	beq _08017E2A
	cmp r1, #1
	beq _08017E48
	b _08017E56
_08017E2A:
	ldrb r1, [r4, #1]
	cmp r1, #2
	bls _08017E56
	movs r0, #1
	strb r0, [r4, #2]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r3, #0
	movs r2, #0x1f
	bl FUN_0822dafc
	strb r5, [r4, #1]
	b _08017E56
_08017E48:
	ldrb r1, [r4, #1]
	cmp r1, #2
	bls _08017E56
	adds r0, r3, #0
	bl FUN_0822dabc
	strb r5, [r4]
_08017E56:
	ldrb r1, [r4, #1]
	adds r1, #1
	strb r1, [r4, #1]
_08017E5C:
	subs r7, #1
	adds r4, #0x3c
	cmp r7, #0
	bge _08017DFC
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08017e6c
FUN_08017e6c: @ 0x08017E6C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	ldr r0, _08017E98 @ =0x03002BE0
	ldr r0, [r0]
	mov r8, r0
	ldr r1, [sp]
	adds r1, #0x60
	ldrh r0, [r1]
	cmp r0, #0
	beq _08017E9C
	subs r0, #1
	strh r0, [r1]
	b _080180FA
	.align 2, 0
_08017E98: .4byte 0x03002BE0
_08017E9C:
	movs r0, #0
	str r1, [sp, #0x14]
	ldr r1, [sp, #4]
	cmp r0, r1
	blt _08017EA8
	b _080180CA
_08017EA8:
	ldr r3, _08017F34 @ =0x030046B8
	ldr r2, _08017F38 @ =0x00000FFF
	mov sl, r2
	ldr r4, _08017F3C @ =0xFFFFF800
	mov sb, r4
_08017EB2:
	ldr r1, [sp]
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r7, r1, r2
	movs r1, #0
	adds r0, #1
	str r0, [sp, #0x10]
	adds r6, r7, #0
_08017EC2:
	ldrb r0, [r6]
	cmp r0, #0
	beq _08017ECA
	b _080180B4
_08017ECA:
	strb r0, [r6, #2]
	strb r0, [r6, #1]
	strb r0, [r6, #3]
	ldr r1, [r3]
	adds r1, #1
	ldr r4, _08017F40 @ =0x000003FF
	ands r1, r4
	str r1, [r3]
	lsls r0, r1, #1
	ldr r2, _08017F44 @ =0x0203B400
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r4, sl
	ands r2, r4
	mov r0, r8
	ldrh r0, [r0, #0x2c]
	adds r2, r2, r0
	add r2, sb
	strh r2, [r6, #4]
	adds r1, #1
	ldr r4, _08017F40 @ =0x000003FF
	ands r1, r4
	str r1, [r3]
	lsls r1, r1, #1
	ldr r0, _08017F44 @ =0x0203B400
	adds r1, r1, r0
	ldrh r0, [r1]
	mov r1, sl
	ands r0, r1
	mov r4, r8
	ldrh r4, [r4, #0x30]
	adds r0, r0, r4
	add r0, sb
	strh r0, [r6, #8]
	adds r5, r7, #4
	lsls r2, r2, #0x10
	asrs r2, r2, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08017F30
	cmp r1, #0
	blt _08017F30
	ldr r0, _08017F48 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08017F30
	ldr r0, _08017F4C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08017F50
_08017F30:
	movs r4, #0
	b _08017F5E
	.align 2, 0
_08017F34: .4byte 0x030046B8
_08017F38: .4byte 0x00000FFF
_08017F3C: .4byte 0xFFFFF800
_08017F40: .4byte 0x000003FF
_08017F44: .4byte 0x0203B400
_08017F48: .4byte 0x030046A8
_08017F4C: .4byte 0x030046AC
_08017F50:
	ldr r0, _08017F74 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08017F5E:
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #0x18]
	bl FUN_08234224
	ldr r3, [sp, #0x18]
	cmp r0, #0
	beq _08017F78
	adds r0, #4
	b _08017F84
	.align 2, 0
_08017F74: .4byte 0x030046A4
_08017F78:
	ldr r0, _08017F98 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08017F84:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08017F9C
	cmp r2, #2
	beq _08017FA0
	b _08017FA4
	.align 2, 0
_08017F98: .4byte 0x030046A4
_08017F9C:
	ldrb r0, [r5, #4]
	b _08017FA2
_08017FA0:
	ldrb r0, [r5]
_08017FA2:
	subs r1, r1, r0
_08017FA4:
	strh r1, [r6, #6]
	ldr r1, [r3]
	adds r1, #1
	ldr r0, _0801800C @ =0x000003FF
	ands r1, r0
	str r1, [r3]
	lsls r0, r1, #1
	ldr r2, _08018010 @ =0x0203B400
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r4, sl
	ands r2, r4
	mov r0, r8
	ldrh r0, [r0, #0x2c]
	adds r2, r2, r0
	add r2, sb
	strh r2, [r6, #0xc]
	adds r1, #1
	ldr r4, _0801800C @ =0x000003FF
	ands r1, r4
	str r1, [r3]
	lsls r1, r1, #1
	ldr r0, _08018010 @ =0x0203B400
	adds r1, r1, r0
	ldrh r0, [r1]
	mov r1, sl
	ands r0, r1
	mov r4, r8
	ldrh r4, [r4, #0x30]
	adds r0, r0, r4
	add r0, sb
	strh r0, [r6, #0x10]
	adds r5, r7, #0
	adds r5, #0xc
	lsls r2, r2, #0x10
	asrs r2, r2, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08018008
	cmp r1, #0
	blt _08018008
	ldr r0, _08018014 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08018008
	ldr r0, _08018018 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0801801C
_08018008:
	movs r4, #0
	b _0801802A
	.align 2, 0
_0801800C: .4byte 0x000003FF
_08018010: .4byte 0x0203B400
_08018014: .4byte 0x030046A8
_08018018: .4byte 0x030046AC
_0801801C:
	ldr r0, _08018040 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0801802A:
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #0x18]
	bl FUN_08234224
	ldr r3, [sp, #0x18]
	cmp r0, #0
	beq _08018044
	adds r0, #4
	b _08018050
	.align 2, 0
_08018040: .4byte 0x030046A4
_08018044:
	ldr r0, _08018064 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08018050:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08018068
	cmp r2, #2
	beq _0801806C
	b _08018070
	.align 2, 0
_08018064: .4byte 0x030046A4
_08018068:
	ldrb r0, [r5, #4]
	b _0801806E
_0801806C:
	ldrb r0, [r5]
_0801806E:
	subs r1, r1, r0
_08018070:
	strh r1, [r6, #0xe]
	adds r5, r7, #0
	adds r5, #0x14
	ldrb r0, [r6, #3]
	lsls r0, r0, #3
	adds r0, r0, r7
	ldr r1, [r0, #8]
	ldr r0, [r0, #4]
	str r0, [r6, #0x2c]
	str r1, [r6, #0x30]
	ldr r1, [sp]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0x1e
	str r3, [sp, #0x18]
	bl FUN_0822dafc
	movs r4, #1
	strb r4, [r5, #0xf]
	ldr r0, [r6, #0x14]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x14]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0822a398
	strb r4, [r6]
	ldr r3, [sp, #0x18]
	b _080180C0
_080180B4:
	adds r1, #1
	adds r6, #0x3c
	adds r7, #0x3c
	cmp r1, #0x1f
	bgt _080180C0
	b _08017EC2
_080180C0:
	ldr r0, [sp, #0x10]
	ldr r4, [sp, #4]
	cmp r0, r4
	bge _080180CA
	b _08017EB2
_080180CA:
	mov r0, sp
	ldrh r1, [r0, #8]
	ldr r0, [sp, #0x14]
	strh r1, [r0]
	ldr r2, [sp, #0xc]
	cmp r2, #0
	beq _080180FA
	ldr r2, _0801810C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08018110 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _08018114 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	ldr r1, [sp, #0xc]
	bl Mod
	ldr r2, [sp, #0x14]
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
_080180FA:
	movs r0, #0
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801810C: .4byte 0x030046B8
_08018110: .4byte 0x000003FF
_08018114: .4byte 0x0203B400

	thumb_func_start FUN_08018118
FUN_08018118: @ 0x08018118
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x18]
	cmp r0, #0
	beq _08018146
	movs r0, #0
	strb r0, [r4, #0x18]
	ldr r0, _080181A0 @ =0x030046A0
	ldr r1, [r0]
	ldr r0, _080181A4 @ =0x00000934
	adds r1, r1, r0
	ldr r0, _080181A8 @ =0xFFFFF7FF
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
	movs r0, #0
	bl FUN_080026fc
	ldr r2, _080181AC @ =0x03003E78
	ldr r0, _080181B0 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08018146:
	adds r0, r4, #0
	bl FUN_08017be4
	mov ip, r0
	ldr r6, _080181A0 @ =0x030046A0
	ldr r3, [r6]
	ldr r1, _080181B4 @ =0x00000942
	adds r0, r3, r1
	movs r1, #0
	ldrsh r5, [r0, r1]
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _080181B8 @ =0x030047A4
	ldr r1, _080181BC @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _08018242
	adds r0, r4, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #0
	beq _08018242
	cmp r5, #0
	ble _080181C4
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r2, r3, r0
	asrs r1, r5, #2
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, [r6]
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r2, r0, r1
	ldr r0, _080181C0 @ =0x03000074
	ldr r1, [r2]
	ldr r0, [r0]
	cmp r1, r0
	blt _08018242
	str r0, [r2]
	b _08018242
	.align 2, 0
_080181A0: .4byte 0x030046A0
_080181A4: .4byte 0x00000934
_080181A8: .4byte 0xFFFFF7FF
_080181AC: .4byte 0x03003E78
_080181B0: .4byte 0xFFFFFDFF
_080181B4: .4byte 0x00000942
_080181B8: .4byte 0x030047A4
_080181BC: .4byte 0x030047A0
_080181C0: .4byte 0x03000074
_080181C4:
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	cmp r0, #0
	bne _08018230
	ldr r7, _0801821C @ =0x0203B400
	ldr r3, _08018220 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r5, _08018224 @ =0x000003FF
	ands r0, r5
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	cmp r0, ip
	blt _08018236
	ldr r0, _08018228 @ =0x03000074
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, _0801822C @ =0x03000078
	ldr r1, [r0]
	cmp r1, #0
	ble _08018242
	ldr r0, [r3]
	adds r0, #1
	ands r0, r5
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	bl Mod
	ldr r2, [r6]
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r2, r2, r1
	ldr r1, [r2]
	adds r1, r1, r0
	str r1, [r2]
	b _08018242
	.align 2, 0
_0801821C: .4byte 0x0203B400
_08018220: .4byte 0x030046B8
_08018224: .4byte 0x000003FF
_08018228: .4byte 0x03000074
_0801822C: .4byte 0x03000078
_08018230:
	subs r0, #1
	str r0, [r2]
	b _08018242
_08018236:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08017bd8
	movs r0, #1
	b _0801824A
_08018242:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	movs r0, #0
_0801824A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08018250
FUN_08018250: @ 0x08018250
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x18]
	cmp r0, #0
	beq _08018264
	movs r0, #0
	strb r0, [r4, #0x18]
	movs r0, #1
	bl FUN_080026fc
_08018264:
	ldr r0, [r4, #0x1c]
	cmp r0, #0x63
	bhi _08018272
	adds r0, #1
	str r0, [r4, #0x1c]
	movs r0, #0
	b _0801827C
_08018272:
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08017bd8
	movs r0, #1
_0801827C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08018284
FUN_08018284: @ 0x08018284
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x18]
	cmp r0, #0
	beq _080182B0
	movs r0, #0
	strb r0, [r4, #0x18]
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r0, _080182D0 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080182D4 @ =0x00000934
	adds r0, r0, r1
	ldrh r1, [r0]
	orrs r2, r1
	strh r2, [r0]
	ldr r0, [r4, #0x54]
	cmp r0, #0
	beq _080182B0
	movs r1, #0
	bl Script_ExecById
_080182B0:
	movs r5, #0x80
	lsls r5, r5, #2
	ldr r3, _080182D8 @ =0x03003E78
	ldrh r0, [r3]
	adds r2, r5, #0
	orrs r2, r0
	strh r2, [r3]
	ldr r1, [r4, #0x1c]
	cmp r1, #0xe
	bhi _080182DC
	movs r0, #3
	ands r1, r0
	cmp r1, #2
	bhi _080182F6
	b _080182F2
	.align 2, 0
_080182D0: .4byte 0x030046A0
_080182D4: .4byte 0x00000934
_080182D8: .4byte 0x03003E78
_080182DC:
	cmp r1, #0x1d
	bhi _080182EA
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	bhi _080182F6
	b _080182F2
_080182EA:
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _080182F6
_080182F2:
	bics r2, r5
	strh r2, [r3]
_080182F6:
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0xa
	movs r3, #0xa
	bl FUN_08017e6c
	ldr r1, [r4, #0x1c]
	cmp r1, #0x2c
	bhi _08018314
	movs r0, #0
	str r0, [r4, #0x50]
	adds r0, r1, #1
	str r0, [r4, #0x1c]
	movs r0, #0
	b _0801831E
_08018314:
	adds r0, r4, #0
	movs r1, #3
	bl FUN_08017bd8
	movs r0, #1
_0801831E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08018324
FUN_08018324: @ 0x08018324
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldrb r0, [r4, #0x18]
	cmp r0, #0
	beq _0801838E
	movs r0, #0
	strb r0, [r4, #0x18]
	ldr r5, _080183C0 @ =0x03000080
	ldr r0, [r5]
	cmp r0, #0
	bne _08018366
	ldrh r0, [r4, #0x28]
	str r0, [r5]
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	beq _08018366
	ldr r2, _080183C4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080183C8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080183CC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r4, #0x2a]
	bl Mod
	ldr r1, [r5]
	adds r1, r1, r0
	str r1, [r5]
_08018366:
	movs r0, #0
	strh r0, [r4, #0x24]
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, _080183D0 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r0, _080183D4 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080183D8 @ =0x00000934
	adds r0, r0, r1
	ldrh r1, [r0]
	orrs r2, r1
	strh r2, [r0]
	movs r0, #2
	bl FUN_080026fc
_0801838E:
	ldrh r1, [r4, #0x20]
	cmp r1, #0
	bne _080183E8
	ldr r0, _080183DC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080183B6
	ldr r0, _080183E0 @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	ble _080183B6
	ldr r1, _080183E4 @ =0x0300446C
	movs r0, #5
	str r0, [r1]
	movs r0, #0x67
	bl PlaySound_082406e0
_080183B6:
	adds r0, r4, #0
	bl FUN_08017b8c
	b _08018424
	.align 2, 0
_080183C0: .4byte 0x03000080
_080183C4: .4byte 0x030046B8
_080183C8: .4byte 0x000003FF
_080183CC: .4byte 0x0203B400
_080183D0: .4byte 0x03003E78
_080183D4: .4byte 0x030046A0
_080183D8: .4byte 0x00000934
_080183DC: .4byte 0x030047A4
_080183E0: .4byte 0x03002B48
_080183E4: .4byte 0x0300446C
_080183E8:
	ldr r0, _0801840C @ =0x030047E0
	ldrb r0, [r0, #0xe]
	cmp r0, #2
	bls _0801841E
	cmp r1, #5
	bne _08018414
	movs r0, #0x1f
	str r0, [sp]
	ldr r0, _08018410 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r1, #2
	movs r2, #0x1f
	movs r3, #0x1f
	bl FUN_0823ce68
	b _0801841E
	.align 2, 0
_0801840C: .4byte 0x030047E0
_08018410: .4byte 0x00001FFF
_08018414:
	cmp r1, #3
	bne _0801841E
	ldr r1, _08018468 @ =0x03002B48
	movs r0, #6
	str r0, [r1]
_0801841E:
	ldrh r0, [r4, #0x20]
	subs r0, #1
	strh r0, [r4, #0x20]
_08018424:
	ldr r0, [r4, #0x1c]
	cmp r0, #0x1d
	bls _08018480
	ldr r0, _0801846C @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08018470 @ =0x00000942
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldrh r1, [r4, #0x24]
	adds r0, r0, r1
	strh r0, [r4, #0x24]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bhi _08018458
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _08018474 @ =0x030047A4
	ldr r1, _08018478 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _08018480
_08018458:
	ldr r1, _0801847C @ =0x03000080
	movs r0, #0
	str r0, [r1]
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08017bd8
	b _080184E0
	.align 2, 0
_08018468: .4byte 0x03002B48
_0801846C: .4byte 0x030046A0
_08018470: .4byte 0x00000942
_08018474: .4byte 0x030047A4
_08018478: .4byte 0x030047A0
_0801847C: .4byte 0x03000080
_08018480:
	ldr r5, _080184C4 @ =0x03000080
	ldr r0, [r5]
	cmp r0, #0
	ble _080184D4
	subs r0, #1
	str r0, [r5]
	ldr r2, _080184C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080184CC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080184D0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #4
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08017e6c
	ldr r1, [r4, #0x50]
	movs r0, #1
	subs r0, r0, r1
	str r0, [r4, #0x50]
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	movs r0, #0
	b _080184E2
	.align 2, 0
_080184C4: .4byte 0x03000080
_080184C8: .4byte 0x030046B8
_080184CC: .4byte 0x000003FF
_080184D0: .4byte 0x0203B400
_080184D4:
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08017bd8
	movs r0, #0
	str r0, [r5]
_080184E0:
	movs r0, #1
_080184E2:
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080184ec
FUN_080184ec: @ 0x080184EC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x18]
	cmp r0, #0
	beq _0801851C
	movs r0, #0
	strb r0, [r4, #0x18]
	movs r0, #3
	bl FUN_080026fc
	ldr r0, _080185AC @ =0x030046A0
	ldr r1, [r0]
	ldr r0, _080185B0 @ =0x00000934
	adds r1, r1, r0
	ldr r0, _080185B4 @ =0xFFFFF7FF
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
	ldr r0, [r4, #0x58]
	cmp r0, #0
	beq _0801851C
	movs r1, #0
	bl Script_ExecById
_0801851C:
	movs r5, #0x80
	lsls r5, r5, #2
	ldr r3, _080185B8 @ =0x03003E78
	ldrh r0, [r3]
	adds r2, r5, #0
	orrs r2, r0
	strh r2, [r3]
	ldr r1, [r4, #0x1c]
	cmp r1, #9
	bhi _0801853C
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _0801853C
	bics r2, r5
	strh r2, [r3]
_0801853C:
	ldr r0, [r4, #0x1c]
	cmp r0, #7
	bhi _0801854E
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0xa
	movs r3, #0xa
	bl FUN_08017e6c
_0801854E:
	ldr r1, [r4, #0x1c]
	cmp r1, #9
	bls _080185D4
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08017bd8
	ldr r2, _080185B8 @ =0x03003E78
	ldr r0, _080185BC @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r4, _080185AC @ =0x030046A0
	ldr r0, [r4]
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, _080185C0 @ =0x03000074
	ldr r1, [r1]
	str r1, [r0]
	ldr r0, _080185C4 @ =0x03000078
	ldr r3, [r0]
	cmp r3, #0
	ble _080185A6
	ldr r2, _080185C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080185CC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080185D0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r3, #0
	bl Mod
	ldr r2, [r4]
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r2, r2, r1
	ldr r1, [r2]
	adds r1, r1, r0
	str r1, [r2]
_080185A6:
	movs r0, #1
	b _080185DE
	.align 2, 0
_080185AC: .4byte 0x030046A0
_080185B0: .4byte 0x00000934
_080185B4: .4byte 0xFFFFF7FF
_080185B8: .4byte 0x03003E78
_080185BC: .4byte 0xFFFFFDFF
_080185C0: .4byte 0x03000074
_080185C4: .4byte 0x03000078
_080185C8: .4byte 0x030046B8
_080185CC: .4byte 0x000003FF
_080185D0: .4byte 0x0203B400
_080185D4:
	movs r0, #0
	str r0, [r4, #0x50]
	adds r0, r1, #1
	str r0, [r4, #0x1c]
	movs r0, #0
_080185DE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start Entity8ECD_Update
Entity8ECD_Update: @ 0x080185E4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08018624 @ =0x085AA948
	ldrb r0, [r4, #0x19]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _080185FC
	adds r0, r4, #0
	bl _call_via_r1
_080185FC:
	ldrb r0, [r4, #0x19]
	cmp r0, #1
	bls _08018608
	adds r0, r4, #0
	bl FUN_08017c30
_08018608:
	ldrb r0, [r4, #0x19]
	cmp r0, #3
	bne _08018638
	ldr r0, _08018628 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0801862C @ =0x00000946
	adds r0, r0, r1
	ldr r2, _08018630 @ =0x00007FFF
	adds r1, r2, #0
	strh r1, [r0]
	ldr r1, _08018634 @ =0x0300007C
	movs r0, #1
	b _08018652
	.align 2, 0
_08018624: .4byte 0x085AA948
_08018628: .4byte 0x030046A0
_0801862C: .4byte 0x00000946
_08018630: .4byte 0x00007FFF
_08018634: .4byte 0x0300007C
_08018638:
	ldr r0, _08018674 @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _08018678 @ =0x00000946
	adds r1, r0, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _0801864E
	subs r0, r2, #1
	strh r0, [r1]
_0801864E:
	ldr r1, _0801867C @ =0x0300007C
	movs r0, #0
_08018652:
	str r0, [r1]
	ldr r1, _08018680 @ =0x03002B48
	ldr r0, [r1]
	cmp r0, #0
	ble _08018660
	subs r0, #1
	str r0, [r1]
_08018660:
	adds r0, r4, #0
	bl FUN_08017df0
	ldr r0, [r4, #0x5c]
	adds r0, #1
	str r0, [r4, #0x5c]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08018674: .4byte 0x030046A0
_08018678: .4byte 0x00000946
_0801867C: .4byte 0x0300007C
_08018680: .4byte 0x03002B48

	thumb_func_start Entity8ECD_Destroy
Entity8ECD_Destroy: @ 0x08018684
	push {lr}
	bl FUN_08017dc0
	ldr r1, _08018694 @ =0x03000084
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_08018694: .4byte 0x03000084

	thumb_func_start Entity8ECD_Init
Entity8ECD_Init: @ 0x08018698
	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r6, r0, #0
	ldr r0, _080186EC @ =0x03000084
	str r6, [r0]
	ldr r0, _080186F0 @ =0x0000EA77
	bl GetTilemapFile
	adds r5, r0, #0
	movs r0, #1
	bl GetTilemapBuffer
	adds r1, r0, #0
	movs r4, #0
	str r4, [r6, #0x34]
	str r4, [r6, #0x3c]
	str r4, [r6, #0x38]
	str r4, [r6, #0x40]
	str r4, [r6, #0x50]
	ldrb r0, [r5]
	cmp r0, #0x4d
	bne _080186F4
	ldrb r0, [r5, #1]
	cmp r0, #0x50
	bne _080186F4
	str r4, [sp, #0x10]
	movs r0, #1
	movs r1, #1
	bl SetBGPrioDirect
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0x10
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #1
	adds r2, r5, #0
	movs r3, #0
	bl FUN_0822c0b8
	b _0801870A
	.align 2, 0
_080186EC: .4byte 0x03000084
_080186F0: .4byte 0x0000EA77
_080186F4:
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #1
	adds r2, r5, #0
	movs r3, #0
	bl FUN_0822bfbc
_0801870A:
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08018720
	bl Script_GetValue
	strh r0, [r6, #0x30]
	bl Script_GetValue
	b _08018724
_08018720:
	movs r0, #0x40
	strh r0, [r6, #0x30]
_08018724:
	strh r0, [r6, #0x32]
	movs r0, #0x69
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0801873C
	bl Script_GetValue
	strh r0, [r6, #0x28]
	bl Script_GetValue
	b _08018746
_0801873C:
	movs r0, #0xe1
	lsls r0, r0, #5
	strh r0, [r6, #0x28]
	movs r0, #0xe1
	lsls r0, r0, #4
_08018746:
	strh r0, [r6, #0x2a]
	ldr r4, _080187AC @ =0x03000080
	ldrh r1, [r6, #0x28]
	ldr r0, [r4]
	cmp r0, r1
	ble _0801877A
	str r1, [r4]
	ldrh r0, [r6, #0x2a]
	cmp r0, #0
	beq _0801877A
	ldr r2, _080187B0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080187B4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080187B8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r6, #0x2a]
	bl Mod
	ldr r1, [r4]
	adds r1, r1, r0
	str r1, [r4]
_0801877A:
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08018794
	bl Script_GetValue
	ldr r1, _080187BC @ =0x030046A0
	ldr r1, [r1]
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r1, r1, r2
	str r0, [r1]
_08018794:
	movs r0, #0x74
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080187C0
	bl Script_GetValue
	strh r0, [r6, #0x2c]
	bl Script_GetValue
	b _080187C6
	.align 2, 0
_080187AC: .4byte 0x03000080
_080187B0: .4byte 0x030046B8
_080187B4: .4byte 0x000003FF
_080187B8: .4byte 0x0203B400
_080187BC: .4byte 0x030046A0
_080187C0:
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r6, #0x2c]
_080187C6:
	strh r0, [r6, #0x2e]
	adds r0, r6, #0
	bl FUN_08017b8c
	movs r0, #0x61
	movs r1, #1
	bl VM_GetKeywordValue
	adds r1, r6, #0
	adds r1, #0x22
	strb r0, [r1]
	ldr r3, _08018828 @ =0x030046A0
	ldr r2, [r3]
	ldr r4, _0801882C @ =0x00000942
	adds r0, r2, r4
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r4, #0xb4
	lsls r4, r4, #2
	adds r2, r2, r4
	asrs r1, r1, #2
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, [r3]
	adds r2, r0, r4
	ldr r0, _08018830 @ =0x03000074
	ldr r1, [r2]
	ldr r0, [r0]
	cmp r1, r0
	blt _08018806
	str r0, [r2]
_08018806:
	movs r5, #0
	ldr r2, [r3]
	ldr r1, _0801882C @ =0x00000942
	adds r0, r2, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _08018864
	ldr r1, _08018834 @ =0x03000080
	ldr r0, [r1]
	cmp r0, #0
	ble _08018838
	cmp r0, #0x63
	bgt _08018862
	movs r0, #0x64
	str r0, [r1]
	b _08018862
	.align 2, 0
_08018828: .4byte 0x030046A0
_0801882C: .4byte 0x00000942
_08018830: .4byte 0x03000074
_08018834: .4byte 0x03000080
_08018838:
	adds r0, r2, r4
	ldr r0, [r0]
	cmp r0, #0
	bne _08018864
	adds r0, r6, #0
	bl FUN_08017be4
	ldr r3, _080188D8 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r2, _080188DC @ =0x000003FF
	ands r1, r2
	str r1, [r3]
	lsls r1, r1, #1
	ldr r2, _080188E0 @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #0x3f
	ands r1, r2
	cmp r1, r0
	bge _08018864
_08018862:
	movs r5, #3
_08018864:
	movs r0, #0x6d
	adds r1, r5, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	adds r0, r6, #0
	bl FUN_08017bd8
	movs r0, #0x43
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r6, #0x54]
	movs r0, #0x4f
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r6, #0x58]
	ldr r4, _080188E0 @ =0x0203B400
	ldr r5, _080188D8 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r3, _080188DC @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r2, #0x7f
	ands r0, r2
	adds r0, #0x80
	str r0, [r6, #0x4c]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r2, #7
	ands r0, r2
	subs r0, #4
	str r0, [r6, #0x44]
	adds r1, #1
	ands r1, r3
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r0, [r1]
	ands r0, r2
	subs r0, #4
	str r0, [r6, #0x48]
	adds r0, r6, #0
	bl FUN_08017d44
	movs r0, #0
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080188D8: .4byte 0x030046B8
_080188DC: .4byte 0x000003FF
_080188E0: .4byte 0x0203B400

	thumb_func_start Entity8ECD_Create
Entity8ECD_Create: @ 0x080188E4
	push {r4, lr}
	ldr r0, _08018918 @ =0x03000084
	ldr r0, [r0]
	cmp r0, #0
	bne _0801892A
	ldr r1, _0801891C @ =0x000008E8
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08018928
	ldr r1, _08018920 @ =Entity8ECD_Update
	ldr r2, _08018924 @ =Entity8ECD_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity8ECD_Init
	cmp r0, #0
	bge _08018928
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801892A
	.align 2, 0
_08018918: .4byte 0x03000084
_0801891C: .4byte 0x000008E8
_08018920: .4byte Entity8ECD_Update
_08018924: .4byte Entity8ECD_Destroy
_08018928:
	adds r0, r4, #0
_0801892A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08018930
FUN_08018930: @ 0x08018930
	push {r4, lr}
	ldr r0, _08018940 @ =0x03000084
	ldr r4, [r0]
	cmp r4, #0
	bne _08018944
	movs r0, #1
	rsbs r0, r0, #0
	b _08018954
	.align 2, 0
_08018940: .4byte 0x03000084
_08018944:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08017bd8
	adds r2, r4, #0
	adds r2, #0x22
	movs r1, #1
	strb r1, [r2]
_08018954:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801895c
FUN_0801895c: @ 0x0801895C
	push {r4, lr}
	ldr r1, _0801896C @ =0x03000084
	ldr r4, [r1]
	cmp r4, #0
	bne _08018970
	movs r0, #1
	rsbs r0, r0, #0
	b _0801898A
	.align 2, 0
_0801896C: .4byte 0x03000084
_08018970:
	ldrb r1, [r4, #0x19]
	cmp r1, #3
	bgt _08018982
	cmp r1, #1
	blt _08018982
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08017bd8
_08018982:
	adds r2, r4, #0
	adds r2, #0x22
	movs r1, #0
	strb r1, [r2]
_0801898A:
	pop {r4}
	pop {r1}
	bx r1
