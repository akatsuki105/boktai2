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

	thumb_func_start FUN_080185e4
FUN_080185e4: @ 0x080185E4
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

	thumb_func_start FUN_08018684
FUN_08018684: @ 0x08018684
	push {lr}
	bl FUN_08017dc0
	ldr r1, _08018694 @ =0x03000084
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_08018694: .4byte 0x03000084

	thumb_func_start FUN_08018698
FUN_08018698: @ 0x08018698
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

	thumb_func_start FUN_080188e4
FUN_080188e4: @ 0x080188E4
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
	ldr r1, _08018920 @ =FUN_080185e4
	ldr r2, _08018924 @ =FUN_08018684
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08018698
	cmp r0, #0
	bge _08018928
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801892A
	.align 2, 0
_08018918: .4byte 0x03000084
_0801891C: .4byte 0x000008E8
_08018920: .4byte FUN_080185e4
_08018924: .4byte FUN_08018684
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

	thumb_func_start FUN_08018990
FUN_08018990: @ 0x08018990
	push {r4, r5, lr}
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080189AA
	bl Script_GetValue
	adds r5, r0, #0
	bl Script_GetValue
	adds r4, r0, #0
	b _080189B0
_080189AA:
	movs r4, #0x96
	lsls r4, r4, #3
	adds r5, r4, #0
_080189B0:
	movs r0, #0x69
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080189C2
	bl Script_GetValue
	b _080189E4
_080189C2:
	ldr r1, _080189F4 @ =0x03000078
	ldr r3, [r1]
	cmp r3, #0
	ble _080189E4
	ldr r2, _080189F8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080189FC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08018A00 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r3, #0
	bl Mod
_080189E4:
	ldr r1, _08018A04 @ =0x03000074
	str r5, [r1]
	ldr r1, _080189F4 @ =0x03000078
	str r4, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080189F4: .4byte 0x03000078
_080189F8: .4byte 0x030046B8
_080189FC: .4byte 0x000003FF
_08018A00: .4byte 0x0203B400
_08018A04: .4byte 0x03000074

	thumb_func_start FUN_08018a08
FUN_08018a08: @ 0x08018A08
	ldr r0, _08018A10 @ =0x0300007C
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08018A10: .4byte 0x0300007C

	thumb_func_start FUN_08018a14
FUN_08018a14: @ 0x08018A14
	push {lr}
	bl FUN_08018a08
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08018a20
FUN_08018a20: @ 0x08018A20
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	adds r4, r1, #0
	mov sb, r3
	lsls r3, r4, #1
	ldr r1, _08018A60 @ =0x030042B0
	adds r6, r3, r1
	mov ip, r6
	subs r1, #0x20
	adds r7, r3, r1
	mov r1, sb
	cmp r1, #0x1f
	ble _08018A64
	adds r6, r4, #0
	cmp r6, r2
	bge _08018ACE
	subs r6, r2, r6
_08018A4A:
	mov r2, ip
	ldrh r1, [r2]
	strh r1, [r7]
	movs r3, #2
	add ip, r3
	adds r7, #2
	subs r6, #1
	cmp r6, #0
	bne _08018A4A
	b _08018ACE
	.align 2, 0
_08018A60: .4byte 0x030042B0
_08018A64:
	adds r1, r3, #0
	adds r1, #0x28
	adds r5, r5, r1
	mov r8, r5
	movs r1, #0x20
	mov r6, sb
	subs r6, r1, r6
	mov sl, r6
	adds r6, r4, #0
	cmp r6, r2
	bge _08018ACE
	subs r6, r2, r6
_08018A7C:
	mov r2, r8
	ldrh r1, [r2]
	ldr r4, _08018ADC @ =0x00007C1F
	ands r4, r1
	movs r5, #0xf8
	lsls r5, r5, #2
	ands r5, r1
	mov r3, ip
	ldrh r2, [r3]
	adds r1, r2, #0
	ldr r3, _08018ADC @ =0x00007C1F
	ands r1, r3
	mov r3, sb
	muls r3, r1, r3
	mov r1, sl
	muls r1, r4, r1
	adds r3, r3, r1
	ldr r1, _08018AE0 @ =0x000F83E0
	ands r3, r1
	movs r1, #0xf8
	lsls r1, r1, #2
	ands r2, r1
	mov r1, sb
	muls r1, r2, r1
	adds r2, r1, #0
	mov r1, sl
	muls r1, r5, r1
	adds r2, r2, r1
	movs r1, #0xf8
	lsls r1, r1, #7
	ands r2, r1
	orrs r3, r2
	lsrs r3, r3, #5
	strh r3, [r7]
	movs r2, #2
	add r8, r2
	add ip, r2
	adds r7, #2
	subs r6, #1
	cmp r6, #0
	bne _08018A7C
_08018ACE:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08018ADC: .4byte 0x00007C1F
_08018AE0: .4byte 0x000F83E0

	thumb_func_start FUN_08018ae4
FUN_08018ae4: @ 0x08018AE4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	lsls r3, r1, #1
	adds r2, r3, #0
	adds r2, #0x28
	adds r4, r4, r2
	ldr r2, _08018B14 @ =0x03004290
	adds r3, r3, r2
	adds r2, r1, #0
	cmp r2, r5
	bge _08018B0C
	subs r2, r5, r2
_08018AFE:
	ldrh r1, [r4]
	strh r1, [r3]
	adds r3, #2
	adds r4, #2
	subs r2, #1
	cmp r2, #0
	bne _08018AFE
_08018B0C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08018B14: .4byte 0x03004290

	thumb_func_start FUN_08018b18
FUN_08018b18: @ 0x08018B18
	push {lr}
	adds r1, r0, #0
	ldr r0, _08018B2C @ =0x03004290
	adds r1, #0x28
	ldr r2, _08018B30 @ =0x04000008
	bl CpuSet
	pop {r0}
	bx r0
	.align 2, 0
_08018B2C: .4byte 0x03004290
_08018B30: .4byte 0x04000008

	thumb_func_start FUN_08018b34
FUN_08018b34: @ 0x08018B34
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl FUN_0800271c
	cmp r0, #0
	beq _08018B46
	adds r0, r5, #0
	bl FUN_08018b18
_08018B46:
	ldrb r0, [r5, #0x1c]
	cmp r0, #2
	bne _08018B68
	ldr r2, [r5, #0x24]
	movs r0, #0xf
	ands r2, r0
	cmp r2, #0
	bne _08018BC4
	ldrh r0, [r5, #0x20]
	ldrh r1, [r5, #0x22]
	subs r0, r0, r1
	strh r0, [r5, #0x20]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08018BC4
	strh r2, [r5, #0x20]
	b _08018BC4
_08018B68:
	cmp r0, #1
	bne _08018B8C
	ldr r0, [r5, #0x24]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08018BC4
	ldrh r0, [r5, #0x22]
	ldrh r1, [r5, #0x20]
	adds r0, r0, r1
	strh r0, [r5, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	ble _08018BC4
	movs r0, #0x20
	strh r0, [r5, #0x20]
	b _08018BC4
_08018B8C:
	ldr r0, [r5, #0x24]
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08018BC4
	ldrh r1, [r5, #0x22]
	ldrh r2, [r5, #0x20]
	adds r0, r1, r2
	strh r0, [r5, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	ble _08018BB8
	movs r0, #0x20
	strh r0, [r5, #0x20]
	ldr r2, _08018BB4 @ =0x0000FFFF
	adds r0, r2, #0
	orrs r0, r1
	b _08018BC2
	.align 2, 0
_08018BB4: .4byte 0x0000FFFF
_08018BB8:
	cmp r0, #0x10
	bgt _08018BC4
	movs r0, #0x10
	strh r0, [r5, #0x20]
	movs r0, #1
_08018BC2:
	strh r0, [r5, #0x22]
_08018BC4:
	movs r2, #1
	ldrb r0, [r5, #0x1c]
	cmp r0, #1
	beq _08018C14
	cmp r0, #1
	bgt _08018BD6
	cmp r0, #0
	beq _08018BDC
	b _08018CB4
_08018BD6:
	cmp r0, #2
	beq _08018C64
	b _08018CB4
_08018BDC:
	movs r6, #0
_08018BDE:
	movs r1, #1
	lsls r1, r6
	ldrh r0, [r5, #0x18]
	ands r0, r1
	cmp r0, #0
	bne _08018BF8
	adds r4, r2, #3
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_08018ae4
	b _08018C08
_08018BF8:
	adds r4, r2, #3
	movs r0, #0x20
	ldrsh r3, [r5, r0]
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_08018a20
_08018C08:
	adds r1, r4, #0
	adds r2, r1, #0
	adds r6, #1
	cmp r6, #3
	ble _08018BDE
	b _08018CB4
_08018C14:
	movs r6, #0
_08018C16:
	movs r1, #1
	lsls r1, r6
	ldrh r0, [r5, #0x18]
	ands r0, r1
	cmp r0, #0
	bne _08018C4A
	ldrh r0, [r5, #0x1a]
	ands r0, r1
	cmp r0, #0
	bne _08018C38
	adds r4, r2, #3
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_08018ae4
	b _08018C58
_08018C38:
	adds r4, r2, #3
	movs r1, #0x20
	ldrsh r3, [r5, r1]
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_08018a20
	b _08018C58
_08018C4A:
	adds r4, r2, #3
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	movs r3, #0x20
	bl FUN_08018a20
_08018C58:
	adds r1, r4, #0
	adds r2, r1, #0
	adds r6, #1
	cmp r6, #3
	ble _08018C16
	b _08018CB4
_08018C64:
	movs r6, #0
_08018C66:
	movs r1, #1
	lsls r1, r6
	ldrh r0, [r5, #0x18]
	ands r0, r1
	cmp r0, #0
	bne _08018C9A
	ldrh r0, [r5, #0x1a]
	ands r0, r1
	cmp r0, #0
	bne _08018C88
	adds r4, r2, #3
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_08018ae4
	b _08018CAA
_08018C88:
	adds r4, r2, #3
	movs r0, #0x20
	ldrsh r3, [r5, r0]
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_08018a20
	b _08018CAA
_08018C9A:
	adds r4, r2, #3
	movs r1, #0x20
	ldrsh r3, [r5, r1]
	adds r0, r5, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_08018a20
_08018CAA:
	adds r1, r4, #0
	adds r2, r1, #0
	adds r6, #1
	cmp r6, #3
	ble _08018C66
_08018CB4:
	ldr r0, [r5, #0x24]
	adds r0, #1
	str r0, [r5, #0x24]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08018cc4
FUN_08018cc4: @ 0x08018CC4
	ldr r1, _08018CCC @ =0x03000088
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08018CCC: .4byte 0x03000088

	thumb_func_start FUN_08018cd0
FUN_08018cd0: @ 0x08018CD0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08018D10 @ =0x03000088
	str r5, [r0]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	ldrh r1, [r5, #0x18]
	orrs r4, r1
	strh r4, [r5, #0x18]
	ldrh r1, [r5, #0x1a]
	orrs r0, r1
	strh r0, [r5, #0x1a]
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r5, #0x1c]
	ldrb r0, [r5, #0x1c]
	cmp r0, #1
	beq _08018D22
	cmp r0, #1
	bgt _08018D14
	cmp r0, #0
	beq _08018D1A
	b _08018D34
	.align 2, 0
_08018D10: .4byte 0x03000088
_08018D14:
	cmp r0, #2
	beq _08018D26
	b _08018D34
_08018D1A:
	movs r0, #0x10
	strh r0, [r5, #0x20]
	movs r0, #1
	b _08018D32
_08018D22:
	movs r0, #0
	b _08018D28
_08018D26:
	movs r0, #0x20
_08018D28:
	strh r0, [r5, #0x20]
	movs r0, #0x61
	movs r1, #2
	bl VM_GetKeywordValue
_08018D32:
	strh r0, [r5, #0x22]
_08018D34:
	adds r0, r5, #0
	bl FUN_08018b18
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08018d44
FUN_08018d44: @ 0x08018D44
	push {r4, lr}
	movs r0, #0xc
	movs r1, #0x48
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08018D78
	ldr r1, _08018D70 @ =FUN_08018b34
	ldr r2, _08018D74 @ =FUN_08018cc4
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08018cd0
	cmp r0, #0
	bge _08018D78
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08018D7A
	.align 2, 0
_08018D70: .4byte FUN_08018b34
_08018D74: .4byte FUN_08018cc4
_08018D78:
	adds r0, r4, #0
_08018D7A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08018d80
FUN_08018d80: @ 0x08018D80
	push {r4, lr}
	ldr r0, _08018DA4 @ =0x03000088
	ldr r4, [r0]
	cmp r4, #0
	beq _08018DCA
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r4, #0x1c]
	ldrb r0, [r4, #0x1c]
	cmp r0, #1
	beq _08018DB6
	cmp r0, #1
	bgt _08018DA8
	cmp r0, #0
	beq _08018DAE
	b _08018DCA
	.align 2, 0
_08018DA4: .4byte 0x03000088
_08018DA8:
	cmp r0, #2
	beq _08018DC0
	b _08018DCA
_08018DAE:
	movs r0, #0x10
	strh r0, [r4, #0x20]
	movs r0, #1
	b _08018DC8
_08018DB6:
	movs r0, #0
	strh r0, [r4, #0x20]
	movs r0, #0x61
	movs r1, #2
	b _08018DC4
_08018DC0:
	movs r0, #0x61
	movs r1, #1
_08018DC4:
	bl VM_GetKeywordValue
_08018DC8:
	strh r0, [r4, #0x22]
_08018DCA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08018dd0
FUN_08018dd0: @ 0x08018DD0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0800271c
	cmp r0, #0
	beq _08018E68
	ldrb r0, [r4, #0x18]
	cmp r0, #3
	bhi _08018E2C
	movs r3, #0
	ldrb r0, [r4, #0x18]
	cmp r3, r0
	bge _08018DFE
	ldr r2, _08018E24 @ =0x030042AE
	adds r1, r2, #0
	subs r1, #8
_08018DF0:
	ldrh r0, [r2]
	strh r0, [r1]
	subs r1, #2
	adds r3, #1
	ldrb r0, [r4, #0x18]
	cmp r3, r0
	blt _08018DF0
_08018DFE:
	cmp r3, #3
	bgt _08018E68
	ldr r0, _08018E28 @ =0x03004330
	lsls r1, r3, #1
	rsbs r1, r1, #0
	adds r2, r1, #0
	subs r2, #0x8a
	adds r2, r2, r0
	adds r1, #8
	adds r1, r1, r0
_08018E12:
	ldrh r0, [r1]
	strh r0, [r2]
	subs r2, #2
	subs r1, #2
	adds r3, #1
	cmp r3, #3
	ble _08018E12
	b _08018E68
	.align 2, 0
_08018E24: .4byte 0x030042AE
_08018E28: .4byte 0x03004330
_08018E2C:
	movs r3, #0
	ldrb r0, [r4, #0x18]
	subs r0, #4
	cmp r3, r0
	bge _08018E50
	ldr r0, _08018E98 @ =0x03004332
	adds r2, r0, #0
	subs r2, #0x92
	adds r1, r0, #0
_08018E3E:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r2, #2
	adds r1, #2
	adds r3, #1
	ldrb r0, [r4, #0x18]
	subs r0, #4
	cmp r3, r0
	blt _08018E3E
_08018E50:
	cmp r3, #3
	bgt _08018E68
	ldr r2, _08018E9C @ =0x030042AE
	lsls r0, r3, #1
	subs r0, #0xe
	adds r1, r0, r2
_08018E5C:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r1, #2
	adds r3, #1
	cmp r3, #3
	ble _08018E5C
_08018E68:
	ldrb r0, [r4, #0x19]
	adds r0, #1
	strb r0, [r4, #0x19]
	ldr r1, _08018EA0 @ =0x085AA95C
	ldrb r2, [r4, #0x18]
	adds r1, r2, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _08018ECA
	cmp r2, #3
	bhi _08018EA4
	movs r0, #0xb
	subs r1, r0, r2
	ldr r2, _08018E9C @ =0x030042AE
	lsls r0, r1, #1
	adds r1, r2, #0
	subs r1, #0x1e
	adds r0, r0, r1
	ldrh r1, [r2]
	strh r1, [r0]
	b _08018EB6
	.align 2, 0
_08018E98: .4byte 0x03004332
_08018E9C: .4byte 0x030042AE
_08018EA0: .4byte 0x085AA95C
_08018EA4:
	adds r1, r2, #4
	lsls r2, r2, #1
	ldr r0, _08018ED4 @ =0x0300432A
	adds r2, r2, r0
	lsls r1, r1, #1
	subs r0, #0x9a
	adds r1, r1, r0
	ldrh r0, [r2]
	strh r0, [r1]
_08018EB6:
	ldrb r0, [r4, #0x18]
	adds r0, #1
	movs r1, #0
	strb r0, [r4, #0x18]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _08018EC8
	strb r1, [r4, #0x18]
_08018EC8:
	strb r1, [r4, #0x19]
_08018ECA:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08018ED4: .4byte 0x0300432A

	thumb_func_start FUN_08018ed8
FUN_08018ed8: @ 0x08018ED8
	movs r0, #0
	bx lr

	thumb_func_start FUN_08018edc
FUN_08018edc: @ 0x08018EDC
	movs r1, #0
	strb r1, [r0, #0x18]
	strb r1, [r0, #0x19]
	ldr r0, _08018EF0 @ =0x030042AE
	adds r1, r0, #0
	subs r1, #0x1e
	ldrh r0, [r0]
	strh r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_08018EF0: .4byte 0x030042AE

	thumb_func_start FUN_08018ef4
FUN_08018ef4: @ 0x08018EF4
	push {r4, lr}
	movs r0, #0xc
	movs r1, #0x1c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08018F28
	ldr r1, _08018F20 @ =FUN_08018dd0
	ldr r2, _08018F24 @ =FUN_08018ed8
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08018edc
	cmp r0, #0
	bge _08018F28
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08018F2A
	.align 2, 0
_08018F20: .4byte FUN_08018dd0
_08018F24: .4byte FUN_08018ed8
_08018F28:
	adds r0, r4, #0
_08018F2A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08018f30
FUN_08018f30: @ 0x08018F30
	ldrh r0, [r0, #0x18]
	movs r2, #1
	lsls r2, r1
	ands r0, r2
	bx lr
	.align 2, 0

	thumb_func_start FUN_08018f3c
FUN_08018f3c: @ 0x08018F3C
	push {r4, lr}
	ldr r4, _08018F64 @ =0x03004250
	movs r2, #0
	ldr r3, _08018F68 @ =0x085AA964
	adds r1, r0, #0
	adds r1, #0x1c
_08018F48:
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	cmp r2, #8
	ble _08018F48
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08018F64: .4byte 0x03004250
_08018F68: .4byte 0x085AA964

	thumb_func_start FUN_08018f6c
FUN_08018f6c: @ 0x08018F6C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r7, _08018F94 @ =0x03004250
	movs r4, #0
	ldr r5, _08018F98 @ =0x085AA964
_08018F76:
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08018f30
	cmp r0, #0
	beq _08018F9C
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r7
	adds r1, r7, #0
	adds r1, #0xd0
	ldrh r1, [r1]
	strh r1, [r0]
	b _08018FAE
	.align 2, 0
_08018F94: .4byte 0x03004250
_08018F98: .4byte 0x085AA964
_08018F9C:
	ldrb r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r7
	lsls r2, r4, #1
	adds r0, r6, #0
	adds r0, #0x1c
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
_08018FAE:
	adds r5, #1
	adds r4, #1
	cmp r4, #8
	ble _08018F76
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08018fbc
FUN_08018fbc: @ 0x08018FBC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0800271c
	cmp r0, #0
	beq _08018FE4
	bl FUN_0823e1b0
	adds r1, r0, #0
	subs r0, r1, #4
	cmp r0, #1
	bls _08018FD8
	cmp r1, #0
	bne _08018FE4
_08018FD8:
	adds r0, r4, #0
	bl FUN_08018f3c
	adds r0, r4, #0
	bl FUN_08018f6c
_08018FE4:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08018fec
FUN_08018fec: @ 0x08018FEC
	movs r0, #0
	bx lr

	thumb_func_start FUN_08018ff0
FUN_08018ff0: @ 0x08018FF0
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0801900C @ =0x0000FFFF
	movs r0, #0x66
	bl VM_GetKeywordValue
	strh r0, [r4, #0x18]
	adds r0, r4, #0
	bl FUN_08018f3c
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801900C: .4byte 0x0000FFFF

	thumb_func_start FUN_08019010
FUN_08019010: @ 0x08019010
	push {r4, lr}
	movs r0, #0xc
	movs r1, #0x3c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08019044
	ldr r1, _0801903C @ =FUN_08018fbc
	ldr r2, _08019040 @ =FUN_08018fec
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08018ff0
	cmp r0, #0
	bge _08019044
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08019046
	.align 2, 0
_0801903C: .4byte FUN_08018fbc
_08019040: .4byte FUN_08018fec
_08019044:
	adds r0, r4, #0
_08019046:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801904c
FUN_0801904c: @ 0x0801904C
	push {lr}
	adds r1, r0, #0
	ldr r0, _08019060 @ =0x03004250
	adds r1, #0x1c
	ldr r2, _08019064 @ =0x04000080
	bl CpuSet
	pop {r0}
	bx r0
	.align 2, 0
_08019060: .4byte 0x03004250
_08019064: .4byte 0x04000080

	thumb_func_start FUN_08019068
FUN_08019068: @ 0x08019068
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r1, #0
	ldrb r0, [r5, #0xf]
	cmp r0, #0
	bne _080190A4
	ldrb r0, [r5, #0xd]
	ldrb r1, [r5, #0x10]
	cmp r0, r1
	blo _0801909C
	ldrb r1, [r5, #0xe]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r3, r1, #0
	cmp r2, #0
	bne _080190C0
	movs r0, #1
	strb r0, [r5, #0xf]
	strb r2, [r5, #0xd]
	b _080190C8
_0801909C:
	ldr r7, [r5]
	ldr r4, [r5, #4]
	ldrb r1, [r5, #0x10]
	b _080190D6
_080190A4:
	ldrb r0, [r5, #0xd]
	ldrb r2, [r5, #0x11]
	cmp r0, r2
	blo _080190D0
	ldrb r1, [r5, #0xe]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r1, #0
	cmp r0, #0
	bne _080190C8
	strb r0, [r5, #0xf]
	strb r0, [r5, #0xd]
_080190C0:
	ldr r7, [r5]
	ldr r4, [r5, #4]
	ldrb r1, [r5, #0x10]
	b _080190DC
_080190C8:
	ldr r7, [r5, #4]
	ldr r4, [r5]
	ldrb r1, [r5, #0x11]
	b _080190DC
_080190D0:
	ldr r7, [r5, #4]
	ldr r4, [r5]
	ldrb r1, [r5, #0x11]
_080190D6:
	adds r0, #1
	strb r0, [r5, #0xd]
	ldrb r3, [r5, #0xe]
_080190DC:
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	beq _08019170
	cmp r1, #0
	ble _080190F2
	ldrb r0, [r5, #0xd]
	lsls r0, r0, #5
	bl Div
	b _080190F4
_080190F2:
	movs r0, #0
_080190F4:
	mov r8, r0
	movs r0, #0x20
	mov r1, r8
	subs r1, r0, r1
	mov sb, r1
	movs r6, #0
	ldrb r2, [r5, #0xc]
	cmp r6, r2
	bge _0801918C
	movs r0, #0xf8
	lsls r0, r0, #2
	mov sl, r0
	mov ip, r4
_0801910E:
	lsls r1, r6, #1
	str r1, [sp]
	ldrh r1, [r7]
	mov r2, ip
	ldrh r3, [r2]
	adds r0, r1, #0
	ldr r4, _08019168 @ =0x00007C1F
	ands r0, r4
	mov r2, r8
	muls r2, r0, r2
	adds r0, r3, #0
	ands r0, r4
	mov r4, sb
	muls r4, r0, r4
	adds r0, r4, #0
	adds r2, r2, r0
	ldr r0, _0801916C @ =0x000F83E0
	ands r2, r0
	mov r0, sl
	ands r1, r0
	mov r4, r8
	muls r4, r1, r4
	adds r1, r4, #0
	ands r3, r0
	mov r0, sb
	muls r0, r3, r0
	adds r1, r1, r0
	movs r0, #0xf8
	lsls r0, r0, #7
	ands r1, r0
	orrs r2, r1
	lsrs r2, r2, #5
	ldr r0, [r5, #8]
	ldr r1, [sp]
	adds r4, r1, r0
	strh r2, [r4]
	movs r2, #2
	add ip, r2
	adds r7, #2
	adds r6, #1
	ldrb r4, [r5, #0xc]
	cmp r6, r4
	blt _0801910E
	b _0801918C
	.align 2, 0
_08019168: .4byte 0x00007C1F
_0801916C: .4byte 0x000F83E0
_08019170:
	movs r6, #0
	ldrb r0, [r5, #0xc]
	cmp r6, r0
	bge _0801918C
	adds r2, r4, #0
	ldr r1, [r5, #8]
_0801917C:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	adds r6, #1
	ldrb r4, [r5, #0xc]
	cmp r6, r4
	blt _0801917C
_0801918C:
	movs r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080191a0
FUN_080191a0: @ 0x080191A0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl FUN_0800271c
	cmp r0, #0
	beq _080191B2
	adds r0, r5, #0
	bl FUN_0801904c
_080191B2:
	movs r6, #0
	ldr r0, [r5, #0x18]
	cmp r6, r0
	bhs _080191D2
	movs r0, #0x87
	lsls r0, r0, #2
	adds r4, r5, r0
_080191C0:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08019068
	adds r4, #0x14
	adds r6, #1
	ldr r0, [r5, #0x18]
	cmp r6, r0
	blo _080191C0
_080191D2:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080191dc
FUN_080191dc: @ 0x080191DC
	ldr r1, _080191E4 @ =0x0300008C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080191E4: .4byte 0x0300008C

	thumb_func_start FUN_080191e8
FUN_080191e8: @ 0x080191E8
	push {lr}
	ldr r1, _080191FC @ =0x0300008C
	str r0, [r1]
	movs r1, #0
	str r1, [r0, #0x18]
	bl FUN_0801904c
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080191FC: .4byte 0x0300008C

	thumb_func_start FUN_08019200
FUN_08019200: @ 0x08019200
	push {r4, lr}
	ldr r0, _08019238 @ =0x0300008C
	ldr r0, [r0]
	cmp r0, #0
	bne _08019246
	movs r1, #0xd7
	lsls r1, r1, #2
	movs r0, #0xc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08019244
	ldr r1, _0801923C @ =FUN_080191a0
	ldr r2, _08019240 @ =FUN_080191dc
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080191e8
	cmp r0, #0
	bge _08019244
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08019246
	.align 2, 0
_08019238: .4byte 0x0300008C
_0801923C: .4byte FUN_080191a0
_08019240: .4byte FUN_080191dc
_08019244:
	adds r0, r4, #0
_08019246:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801924c
FUN_0801924c: @ 0x0801924C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	bl FUN_08019200
	adds r6, r0, #0
	cmp r6, #0
	beq _08019268
	ldr r1, [r6, #0x18]
	cmp r1, #0xf
	bls _0801926E
_08019268:
	movs r0, #1
	rsbs r0, r0, #0
	b _08019378
_0801926E:
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r0, r1
	adds r5, r6, r0
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0801929A
	bl Script_GetValue
	adds r7, r0, #0
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	mov sl, r0
	b _080192A0
_0801929A:
	movs r7, #0
	movs r4, #0
	mov sl, r4
_080192A0:
	movs r0, #0x64
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080192BE
	bl Script_GetValue
	mov sb, r0
	bl Script_GetValue
	mov r8, r0
	bl Script_GetValue
	str r0, [sp]
	b _080192C8
_080192BE:
	movs r0, #0
	mov sb, r0
	mov r8, r0
	movs r1, #0
	str r1, [sp]
_080192C8:
	movs r0, #0x62
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080192E0
	bl Script_GetValue
	str r0, [sp, #4]
	bl Script_GetValue
	adds r3, r0, #0
	b _080192E6
_080192E0:
	movs r0, #0
	str r0, [sp, #4]
	movs r3, #0
_080192E6:
	mov r1, sl
	cmp r1, #1
	bne _08019300
	lsls r0, r7, #4
	adds r0, r0, r4
	lsls r0, r0, #1
	adds r0, #0x1c
	adds r0, r6, r0
	str r0, [r5]
	ldr r2, _080192FC @ =0x03004250
	b _0801930C
	.align 2, 0
_080192FC: .4byte 0x03004250
_08019300:
	lsls r0, r7, #5
	lsls r1, r4, #1
	ldr r2, _08019324 @ =0x03004250
	adds r1, r1, r2
	adds r0, r0, r1
	str r0, [r5]
_0801930C:
	ldr r4, [sp]
	cmp r4, #1
	bne _08019328
	mov r1, sb
	lsls r0, r1, #4
	add r0, r8
	lsls r0, r0, #1
	adds r0, #0x1c
	adds r0, r6, r0
	str r0, [r5, #4]
	b _08019336
	.align 2, 0
_08019324: .4byte 0x03004250
_08019328:
	mov r4, sb
	lsls r1, r4, #5
	mov r4, r8
	lsls r0, r4, #1
	adds r0, r0, r2
	adds r1, r1, r0
	str r1, [r5, #4]
_08019336:
	ldr r0, [sp, #4]
	lsls r1, r0, #5
	lsls r0, r3, #1
	adds r0, r0, r2
	adds r1, r1, r0
	str r1, [r5, #8]
	movs r0, #0x6e
	movs r1, #1
	bl VM_GetKeywordValue
	movs r4, #0
	strb r0, [r5, #0xc]
	strb r4, [r5, #0xd]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r5, #0xe]
	strb r4, [r5, #0xf]
	movs r0, #0x53
	movs r1, #0xa
	bl VM_GetKeywordValue
	strb r0, [r5, #0x10]
	movs r0, #0x44
	movs r1, #0xa
	bl VM_GetKeywordValue
	adds r1, r0, #0
	strb r1, [r5, #0x11]
	ldr r1, [r6, #0x18]
	adds r1, #1
	str r1, [r6, #0x18]
_08019378:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08019388
FUN_08019388: @ 0x08019388
	push {lr}
	movs r2, #0
	ldrh r1, [r0, #0x24]
	cmp r2, r1
	bge _080193AA
	adds r3, r1, #0
	adds r1, r0, #0
	adds r1, #0x34
_08019398:
	ldrb r0, [r1]
	cmp r0, #1
	bne _080193A2
	movs r0, #1
	b _080193AC
_080193A2:
	adds r1, #0x30
	adds r2, #1
	cmp r2, r3
	blt _08019398
_080193AA:
	movs r0, #0
_080193AC:
	pop {r1}
	bx r1

	thumb_func_start FUN_080193b0
FUN_080193b0: @ 0x080193B0
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldrh r0, [r3, #6]
	adds r4, r0, #0
	cmp r4, #0
	bne _08019400
	ldr r1, [r2, #0x1c]
	cmp r1, #0
	blt _080193CA
	ldr r0, [r2, #0x18]
	cmp r0, r1
	bge _08019404
_080193CA:
	movs r0, #1
	strb r0, [r3]
	ldr r2, _080193F4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080193F8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080193FC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	strb r0, [r3, #1]
	strh r4, [r3, #2]
	ldr r0, [r3, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #8]
	b _08019404
	.align 2, 0
_080193F4: .4byte 0x030046B8
_080193F8: .4byte 0x000003FF
_080193FC: .4byte 0x0203B400
_08019400:
	subs r0, #1
	strh r0, [r3, #6]
_08019404:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801940c
FUN_0801940c: @ 0x0801940C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldrh r0, [r6, #0x20]
	ldrh r1, [r5, #2]
	adds r0, r0, r1
	strh r0, [r5, #2]
	ldrh r3, [r5, #6]
	movs r0, #3
	ands r0, r3
	cmp r0, #0
	bne _08019438
	adds r0, r5, #0
	adds r0, #8
	ldr r1, [r6, #0x28]
	ldrh r2, [r6, #0x26]
	lsrs r3, r3, #2
	movs r4, #1
	ands r3, r4
	adds r2, r2, r3
	bl FUN_0822dafc
_08019438:
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	ldrh r0, [r5, #2]
	ldrh r1, [r6, #0x22]
	cmp r0, r1
	blo _0801945E
	movs r0, #0
	strb r0, [r5]
	ldr r0, [r5, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #8]
	ldrh r1, [r6, #0x24]
	movs r0, #8
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, #4
	strh r0, [r5, #6]
_0801945E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08019464
FUN_08019464: @ 0x08019464
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r0, #0
	mov r8, r0
	ldrh r1, [r5, #0x24]
	cmp r8, r1
	bge _0801951A
	movs r2, #0x54
	adds r2, r2, r5
	mov sl, r2
	movs r0, #0x34
	adds r0, r0, r5
	mov sb, r0
	mov r4, sb
_08019488:
	mov r1, sb
	ldrb r0, [r4]
	cmp r0, #0
	bne _08019498
	adds r0, r5, #0
	bl FUN_080193b0
	b _0801949E
_08019498:
	adds r0, r5, #0
	bl FUN_0801940c
_0801949E:
	mov r3, sl
	ldrb r6, [r4, #1]
	ldrh r7, [r4, #4]
	ldr r2, _080194C0 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _080194C4
	asrs r1, r0, #0xc
	b _080194CA
	.align 2, 0
_080194C0: .4byte 0x085B0A08
_080194C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080194CA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _080194E2
	asrs r0, r0, #0xc
	b _080194E8
_080194E2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080194E8:
	strh r0, [r3, #4]
	ldrh r1, [r4, #2]
	ldrh r0, [r4, #0x22]
	adds r1, r1, r0
	strh r1, [r4, #0x22]
	ldrh r0, [r5, #0x2c]
	ldrh r2, [r4, #0x20]
	adds r0, r0, r2
	strh r0, [r4, #0x20]
	ldrh r0, [r5, #0x2e]
	adds r1, r1, r0
	strh r1, [r4, #0x22]
	ldrh r0, [r5, #0x30]
	ldrh r1, [r4, #0x24]
	adds r0, r0, r1
	strh r0, [r4, #0x24]
	movs r2, #0x30
	add sl, r2
	adds r4, #0x30
	add sb, r2
	movs r0, #1
	add r8, r0
	ldrh r1, [r5, #0x24]
	cmp r8, r1
	blt _08019488
_0801951A:
	ldrh r2, [r5, #0x24]
	mov r8, r2
	cmp r2, #7
	bgt _08019542
	movs r2, #1
	mov r1, r8
	lsls r0, r1, #1
	add r0, r8
	lsls r0, r0, #4
	adds r0, #0x3c
	adds r1, r0, r5
_08019530:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x30
	movs r0, #1
	add r8, r0
	mov r0, r8
	cmp r0, #7
	ble _08019530
_08019542:
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
	ldr r1, [r5, #0x1c]
	cmp r1, #0
	ble _08019562
	cmp r0, r1
	blt _08019562
	adds r0, r5, #0
	bl FUN_08019388
	cmp r0, #0
	bne _08019562
	adds r0, r5, #0
	bl KillEntity
_08019562:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08019574
FUN_08019574: @ 0x08019574
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x3c
	movs r5, #7
_0801957C:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x30
	subs r5, #1
	cmp r5, #0
	bge _0801957C
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08019594
FUN_08019594: @ 0x08019594
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	str r2, [sp]
	mov r8, r3
	ldr r7, [sp, #0x24]
	ldr r0, [sp, #0x28]
	cmp r0, #8
	bhi _08019654
	lsls r0, r0, #2
	ldr r1, _080195BC @ =_080195C0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080195BC: .4byte _080195C0
_080195C0: @ jump table
	.4byte _08019654 @ case 0
	.4byte _080195E4 @ case 1
	.4byte _08019654 @ case 2
	.4byte _080195F4 @ case 3
	.4byte _08019604 @ case 4
	.4byte _08019614 @ case 5
	.4byte _08019624 @ case 6
	.4byte _08019634 @ case 7
	.4byte _08019644 @ case 8
_080195E4:
	ldr r0, _080195F0 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #0
	b _0801965E
	.align 2, 0
_080195F0: .4byte 0x00001C1E
_080195F4:
	ldr r0, _08019600 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #4
	b _0801965E
	.align 2, 0
_08019600: .4byte 0x00001C1E
_08019604:
	ldr r0, _08019610 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #6
	b _0801965E
	.align 2, 0
_08019610: .4byte 0x00001C1E
_08019614:
	ldr r0, _08019620 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #8
	b _0801965E
	.align 2, 0
_08019620: .4byte 0x00001C1E
_08019624:
	ldr r0, _08019630 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #0xa
	b _0801965E
	.align 2, 0
_08019630: .4byte 0x00001C1E
_08019634:
	ldr r0, _08019640 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #0xc
	b _0801965E
	.align 2, 0
_08019640: .4byte 0x00001C1E
_08019644:
	ldr r0, _08019650 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #0xe
	b _0801965E
	.align 2, 0
_08019650: .4byte 0x00001C1E
_08019654:
	ldr r0, _08019694 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #2
_0801965E:
	strh r0, [r6, #0x26]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r6, #0x2c]
	str r1, [r6, #0x30]
	adds r5, r6, #0
	adds r5, #0x2c
	ldrh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08019690
	cmp r1, #0
	blt _08019690
	ldr r0, _08019698 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08019690
	ldr r0, _0801969C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080196A0
_08019690:
	movs r4, #0
	b _080196AE
	.align 2, 0
_08019694: .4byte 0x00001C1E
_08019698: .4byte 0x030046A8
_0801969C: .4byte 0x030046AC
_080196A0:
	ldr r0, _080196C0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080196AE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080196C4
	adds r0, #4
	b _080196D0
	.align 2, 0
_080196C0: .4byte 0x030046A4
_080196C4:
	ldr r0, _080196E4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080196D0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080196E8
	cmp r2, #2
	beq _080196EC
	b _080196F0
	.align 2, 0
_080196E4: .4byte 0x030046A4
_080196E8:
	ldrb r0, [r5, #4]
	b _080196EE
_080196EC:
	ldrb r0, [r5]
_080196EE:
	subs r1, r1, r0
_080196F0:
	movs r2, #0x2e
	ldrsh r0, [r6, r2]
	cmp r0, r1
	bge _080196FA
	strh r1, [r6, #0x2e]
_080196FA:
	movs r0, #0
	str r0, [r6, #0x18]
	mov r3, r8
	str r3, [r6, #0x1c]
	movs r0, #0x14
	strh r0, [r6, #0x20]
	movs r0, #0xc8
	lsls r0, r0, #1
	strh r0, [r6, #0x22]
	cmp r7, #7
	ble _08019712
	movs r7, #8
_08019712:
	strh r7, [r6, #0x24]
	adds r7, r6, #0
	adds r7, #0x34
	movs r0, #0
	mov r8, r0
	mov sb, r0
	ldr r1, _080197A0 @ =0x085B0A08
	mov sl, r1
	adds r5, r7, #0
_08019724:
	adds r4, r7, #0
	adds r4, #8
	mov r2, sb
	strb r2, [r5]
	ldr r2, _080197A4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080197A8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080197AC @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	subs r0, #0x20
	strb r0, [r5, #1]
	mov r0, sb
	strh r0, [r5, #2]
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r5, #4]
	mov r2, r8
	lsls r0, r2, #2
	strh r0, [r5, #6]
	ldr r1, [r6, #0x28]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r1, [r6, #0x28]
	ldrh r2, [r6, #0x26]
	adds r0, r4, #0
	bl FUN_0822dafc
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	ldrb r2, [r5, #1]
	ldrh r3, [r5, #4]
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080197B0
	asrs r0, r0, #0xc
	b _080197B6
	.align 2, 0
_080197A0: .4byte 0x085B0A08
_080197A4: .4byte 0x030046B8
_080197A8: .4byte 0x000003FF
_080197AC: .4byte 0x0203B400
_080197B0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080197B6:
	strh r0, [r5, #0x20]
	mov r0, sb
	strh r0, [r5, #0x22]
	lsls r0, r2, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080197CE
	asrs r2, r0, #0xc
	b _080197D4
_080197CE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080197D4:
	strh r2, [r5, #0x24]
	ldrh r1, [r5, #2]
	ldrh r3, [r5, #0x22]
	adds r1, r1, r3
	strh r1, [r5, #0x22]
	ldrh r0, [r6, #0x2c]
	ldrh r3, [r5, #0x20]
	adds r0, r0, r3
	strh r0, [r5, #0x20]
	ldrh r0, [r6, #0x2e]
	adds r1, r1, r0
	strh r1, [r5, #0x22]
	ldrh r0, [r6, #0x30]
	adds r0, r2, r0
	strh r0, [r5, #0x24]
	movs r0, #1
	strb r0, [r5, #0x17]
	add r8, r0
	adds r5, #0x30
	adds r7, #0x30
	mov r0, r8
	cmp r0, #7
	ble _08019724
	movs r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08019814
FUN_08019814: @ 0x08019814
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r1, #0xda
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08019864
	ldr r1, _0801985C @ =FUN_08019464
	ldr r2, _08019860 @ =FUN_08019574
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_08019594
	cmp r0, #0
	bge _08019864
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08019866
	.align 2, 0
_0801985C: .4byte FUN_08019464
_08019860: .4byte FUN_08019574
_08019864:
	adds r0, r4, #0
_08019866:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08019874
FUN_08019874: @ 0x08019874
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	movs r1, #0xda
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r7, r0, #0
	cmp r7, #0
	beq _08019940
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080198D4
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080198CC @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080198D0 @ =0x0000FFFF
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
	b _080198DE
	.align 2, 0
_080198CC: .4byte 0xFFFF0000
_080198D0: .4byte 0x0000FFFF
_080198D4:
	ldr r1, _08019934 @ =0xFFFF0000
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
_080198DE:
	movs r4, #0x80
	lsls r4, r4, #1
	movs r0, #0x64
	adds r1, r4, #0
	bl VM_GetKeywordValue
	mov r8, r0
	movs r0, #0x74
	adds r1, r4, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x6e
	movs r1, #8
	bl VM_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x54
	movs r1, #0
	bl VM_GetKeywordValue
	adds r4, r0, #0
	ldr r1, _08019938 @ =FUN_08019464
	ldr r2, _0801993C @ =FUN_08019574
	adds r0, r7, #0
	bl SetEntityRoutine
	str r5, [sp]
	str r4, [sp, #4]
	adds r0, r7, #0
	add r1, sp, #8
	mov r2, r8
	adds r3, r6, #0
	bl FUN_08019594
	cmp r0, #0
	bge _08019940
	adds r0, r7, #0
	bl KillEntity
	movs r0, #0
	b _08019942
	.align 2, 0
_08019934: .4byte 0xFFFF0000
_08019938: .4byte FUN_08019464
_0801993C: .4byte FUN_08019574
_08019940:
	adds r0, r7, #0
_08019942:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity82B7_Update
Entity82B7_Update: @ 0x08019950
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x18]
	ldrh r1, [r4, #0x20]
	ldrh r2, [r4, #0x22]
	bl Video_SetBLDCNTDirect
	movs r1, #0x1b
	ldrsb r1, [r4, r1]
	ldr r0, [r4, #0x24]
	muls r0, r1, r0
	ldr r1, [r4, #0x28]
	bl Div
	movs r1, #0x19
	ldrsb r1, [r4, r1]
	adds r5, r1, r0
	ldrb r0, [r4, #0x18]
	cmp r0, #1
	bne _08019994
	movs r1, #0x1c
	ldrsb r1, [r4, r1]
	ldr r0, [r4, #0x24]
	muls r0, r1, r0
	ldr r1, [r4, #0x28]
	bl Div
	movs r1, #0x1a
	ldrsb r1, [r4, r1]
	adds r1, r1, r0
	adds r0, r5, #0
	bl Video_SetBLDALPHADirect
	b _0801999A
_08019994:
	adds r0, r5, #0
	bl Video_SetBLDYDirect
_0801999A:
	ldr r1, [r4, #0x24]
	ldr r0, [r4, #0x28]
	cmp r1, r0
	blo _080199A8
	adds r0, r4, #0
	bl KillEntity
_080199A8:
	ldr r0, [r4, #0x24]
	adds r0, #1
	str r0, [r4, #0x24]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity82B7_Destroy
Entity82B7_Destroy: @ 0x080199B8
	movs r0, #0
	bx lr

	thumb_func_start Entity82B7_Init
Entity82B7_Init: @ 0x080199BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r0, #0x6d
	movs r1, #1
	bl VM_GetKeywordValue
	strb r0, [r5, #0x18]
	movs r0, #0x69
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080199FC
	adds r7, r5, #0
	adds r7, #0x19
	movs r0, #0x1b
	adds r0, r0, r5
	mov r8, r0
	adds r4, r7, #0
_080199E4:
	bl VM_GetPC
	cmp r0, #0
	beq _080199F0
	bl Script_GetValue
_080199F0:
	strb r0, [r4]
	adds r4, #1
	adds r0, r7, #1
	cmp r4, r0
	ble _080199E4
	b _08019A16
_080199FC:
	adds r7, r5, #0
	adds r7, #0x19
	movs r0, #0x1b
	adds r0, r0, r5
	mov r8, r0
	adds r1, r7, #0
	movs r2, #0
	adds r0, r5, #0
	adds r0, #0x1a
_08019A0E:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _08019A0E
_08019A16:
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08019A42
	movs r6, #0
	mov r4, r8
_08019A24:
	bl VM_GetPC
	cmp r0, #0
	beq _08019A36
	bl Script_GetValue
	adds r1, r7, r6
	ldrb r1, [r1]
	subs r0, r0, r1
_08019A36:
	strb r0, [r4]
	adds r4, #1
	adds r6, #1
	cmp r6, #1
	ble _08019A24
	b _08019A50
_08019A42:
	mov r1, r8
	movs r2, #0
	adds r0, r1, #1
_08019A48:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _08019A48
_08019A50:
	movs r0, #0x73
	movs r1, #0
	bl VM_GetKeywordValue
	movs r4, #0
	strh r0, [r5, #0x20]
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r5, #0x22]
	movs r0, #0x74
	movs r1, #0x3c
	bl VM_GetKeywordValue
	str r0, [r5, #0x28]
	str r4, [r5, #0x24]
	cmp r0, #0
	bne _08019A7A
	movs r0, #0x3c
	str r0, [r5, #0x28]
_08019A7A:
	ldrb r0, [r5, #0x18]
	ldrh r1, [r5, #0x20]
	ldrh r2, [r5, #0x22]
	bl Video_SetBLDCNTDirect
	ldrb r0, [r5, #0x18]
	cmp r0, #1
	bne _08019A98
	movs r0, #0x19
	ldrsb r0, [r5, r0]
	movs r1, #0x1a
	ldrsb r1, [r5, r1]
	bl Video_SetBLDALPHADirect
	b _08019AA0
_08019A98:
	movs r0, #0x19
	ldrsb r0, [r5, r0]
	bl Video_SetBLDYDirect
_08019AA0:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity82B7_Create
Entity82B7_Create: @ 0x08019AAC
	push {r4, lr}
	movs r0, #0xb
	movs r1, #0x2c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08019AE0
	ldr r1, _08019AD8 @ =Entity82B7_Update
	ldr r2, _08019ADC @ =Entity82B7_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity82B7_Init
	cmp r0, #0
	bge _08019AE0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08019AE2
	.align 2, 0
_08019AD8: .4byte Entity82B7_Update
_08019ADC: .4byte Entity82B7_Destroy
_08019AE0:
	adds r0, r4, #0
_08019AE2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08019ae8
FUN_08019ae8: @ 0x08019AE8
	ldr r1, _08019AF0 @ =0x03000090
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08019AF0: .4byte 0x03000090

	thumb_func_start FUN_08019af4
FUN_08019af4: @ 0x08019AF4
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	mov r8, r0
	adds r4, r1, #0
	movs r6, #0
	strb r6, [r4]
	str r6, [r4, #4]
	movs r0, #1
	mov sb, r0
	mov r0, sb
	strb r0, [r4, #2]
	strb r6, [r4, #1]
	adds r5, r4, #0
	adds r5, #8
	movs r0, #0x80
	lsls r0, r0, #1
	add r8, r0
	mov r0, r8
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0x13
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	mov r0, r8
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0x33
	bl FUN_0822dafc
	mov r0, sb
	strb r0, [r4, #0x17]
	strh r6, [r4, #0x30]
	strh r6, [r4, #0x32]
	strh r6, [r4, #0x34]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08019b54
FUN_08019b54: @ 0x08019B54
	push {lr}
	adds r0, r1, #0
	adds r0, #8
	bl FUN_0822dabc
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08019b64
FUN_08019b64: @ 0x08019B64
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #2]
	cmp r0, #0
	beq _08019B76
	movs r0, #0
	strb r0, [r2, #2]
	movs r0, #1
	b _08019B78
_08019B76:
	movs r0, #0
_08019B78:
	cmp r0, #0
	beq _08019B84
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
_08019B84:
	ldr r0, [r2, #4]
	adds r0, #1
	str r0, [r2, #4]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08019b90
FUN_08019b90: @ 0x08019B90
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r1, #0
	ldrb r0, [r6, #2]
	cmp r0, #0
	beq _08019BA2
	movs r0, #0
	strb r0, [r6, #2]
_08019BA2:
	mov r5, sp
	movs r0, #0x30
	adds r0, r0, r6
	mov ip, r0
	ldrh r0, [r6, #0x30]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	mov r1, ip
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08019BC8
	asrs r0, r0, #8
	b _08019BCE
_08019BC8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019BCE:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08019BE0
	asrs r0, r0, #8
	b _08019BE6
_08019BE0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019BE6:
	adds r4, r0, #0
	mov r2, ip
	movs r3, #2
	ldrsh r1, [r2, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08019BFC
	asrs r0, r0, #8
	b _08019C02
_08019BFC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019C02:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08019C80 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	adds r5, r7, #0
	adds r5, #0x18
	mov r4, sp
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0x18
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r4, r3]
	movs r3, #4
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #1]
	mov r0, sp
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r3, #0x18
	ldrsh r0, [r7, r3]
	subs r2, r2, r0
	movs r1, #4
	ldrsh r0, [r4, r1]
	movs r3, #4
	ldrsh r1, [r5, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	ldr r0, _08019C84 @ =0x00000FFF
	cmp r1, r0
	bls _08019C74
	ldr r0, [r6, #4]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0x10
	bls _08019C88
_08019C74:
	ldr r0, [r6, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r6, #8]
	b _08019CEC
	.align 2, 0
_08019C80: .4byte 0x030047C8
_08019C84: .4byte 0x00000FFF
_08019C88:
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	ldr r2, _08019CB4 @ =0x085B0A08
	ldrb r3, [r6, #1]
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
	cmp r0, #0
	blt _08019CB8
	asrs r0, r0, #0xc
	b _08019CBE
	.align 2, 0
_08019CB4: .4byte 0x085B0A08
_08019CB8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08019CBE:
	adds r0, #0x78
	strh r0, [r6, #0x20]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _08019CD6
	asrs r0, r0, #0xc
	b _08019CDC
_08019CD6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08019CDC:
	adds r0, #0x50
	movs r1, #0
	strh r0, [r6, #0x22]
	strh r1, [r6, #0x24]
	ldrb r1, [r6, #1]
	movs r0, #0xa0
	subs r0, r0, r1
	strb r0, [r6, #0xf]
_08019CEC:
	ldr r0, [r6, #4]
	cmp r0, #0xb3
	bls _08019CFC
	movs r0, #0
	strb r0, [r6]
	str r0, [r6, #4]
	movs r0, #1
	strb r0, [r6, #2]
_08019CFC:
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08019d0c
FUN_08019d0c: @ 0x08019D0C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	adds r6, r1, #0
	ldrb r0, [r6, #2]
	cmp r0, #0
	beq _08019D26
	movs r0, #0
	strb r0, [r6, #2]
	movs r0, #1
	b _08019D28
_08019D26:
	movs r0, #0
_08019D28:
	cmp r0, #0
	bne _08019D2E
	b _08019E56
_08019D2E:
	mov r5, sp
	adds r7, r6, #0
	adds r7, #0x30
	ldrh r0, [r6, #0x30]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08019D50
	asrs r0, r0, #8
	b _08019D56
_08019D50:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019D56:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08019D68
	asrs r0, r0, #8
	b _08019D6E
_08019D68:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019D6E:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r7, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08019D82
	asrs r0, r0, #8
	b _08019D88
_08019D82:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019D88:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08019E2C @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	mov r5, r8
	adds r5, #0x18
	mov r4, sp
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, r8
	movs r3, #0x18
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r2, #4
	ldrsh r1, [r4, r2]
	movs r3, #4
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #1]
	mov r0, sp
	movs r1, #0
	ldrsh r2, [r0, r1]
	mov r3, r8
	movs r1, #0x18
	ldrsh r0, [r3, r1]
	subs r2, r2, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	movs r4, #4
	ldrsh r1, [r5, r4]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08019E30 @ =0x00000FFF
	cmp r1, r0
	bhi _08019DF6
	b _08019F08
_08019DF6:
	ldr r0, [r6, #4]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0x10
	bls _08019E02
	b _08019F08
_08019E02:
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	ldr r2, _08019E34 @ =0x085B0A08
	ldrb r3, [r6, #1]
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
	cmp r0, #0
	blt _08019E38
	asrs r0, r0, #0xc
	b _08019E3E
	.align 2, 0
_08019E2C: .4byte 0x030047C8
_08019E30: .4byte 0x00000FFF
_08019E34: .4byte 0x085B0A08
_08019E38:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08019E3E:
	adds r0, #0x78
	strh r0, [r6, #0x20]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _08019E54
	b _08019F66
_08019E54:
	b _08019F6A
_08019E56:
	add r5, sp, #8
	adds r7, r6, #0
	adds r7, #0x30
	ldrh r0, [r6, #0x30]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	mov ip, r5
	cmp r0, #0
	blt _08019E7A
	asrs r0, r0, #8
	b _08019E80
_08019E7A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019E80:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08019E92
	asrs r0, r0, #8
	b _08019E98
_08019E92:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019E98:
	adds r4, r0, #0
	movs r3, #2
	ldrsh r1, [r7, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08019EAC
	asrs r0, r0, #8
	b _08019EB2
_08019EAC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019EB2:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08019F14 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	add r0, sp, #8
	movs r4, #0
	ldrsh r2, [r0, r4]
	mov r1, r8
	movs r3, #0x18
	ldrsh r0, [r1, r3]
	subs r2, r2, r0
	mov r4, ip
	movs r1, #4
	ldrsh r0, [r4, r1]
	mov r3, r8
	movs r4, #0x1c
	ldrsh r1, [r3, r4]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08019F18 @ =0x00000FFF
	cmp r1, r0
	bls _08019F08
	ldr r0, [r6, #4]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0x10
	bls _08019F1C
_08019F08:
	ldr r0, [r6, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r6, #8]
	b _08019F80
	.align 2, 0
_08019F14: .4byte 0x030047C8
_08019F18: .4byte 0x00000FFF
_08019F1C:
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	ldr r2, _08019F48 @ =0x085B0A08
	ldrb r3, [r6, #1]
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
	cmp r0, #0
	blt _08019F4C
	asrs r0, r0, #0xc
	b _08019F52
	.align 2, 0
_08019F48: .4byte 0x085B0A08
_08019F4C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08019F52:
	adds r0, #0x78
	strh r0, [r6, #0x20]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _08019F6A
_08019F66:
	asrs r0, r0, #0xc
	b _08019F70
_08019F6A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08019F70:
	adds r0, #0x50
	movs r1, #0
	strh r0, [r6, #0x22]
	strh r1, [r6, #0x24]
	ldrb r1, [r6, #1]
	movs r0, #0xa0
	subs r0, r0, r1
	strb r0, [r6, #0xf]
_08019F80:
	ldr r0, [r6, #4]
	cmp r0, #0x3b
	bls _08019F90
	movs r0, #0
	strb r0, [r6]
	str r0, [r6, #4]
	movs r0, #1
	strb r0, [r6, #2]
_08019F90:
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity4B15_Update
Entity4B15_Update: @ 0x08019FA4
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	mov r1, sp
	ldr r0, _08019FDC @ =0x08251B58
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	adds r4, r6, #0
	adds r4, #0x20
	movs r5, #3
_08019FB8:
	ldrb r0, [r4]
	lsls r0, r0, #2
	add r0, sp
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
	subs r5, #1
	adds r4, #0x38
	cmp r5, #0
	bge _08019FB8
	movs r0, #0
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08019FDC: .4byte 0x08251B58

	thumb_func_start Entity4B15_Destroy
Entity4B15_Destroy: @ 0x08019FE0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x20
	movs r6, #3
_08019FEA:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08019b54
	adds r4, #0x38
	subs r6, #1
	cmp r6, #0
	bge _08019FEA
	movs r1, #0
	ldr r0, _0801A008 @ =0x03000090
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801A008: .4byte 0x03000090

	thumb_func_start Entity4B15_Init
Entity4B15_Init: @ 0x0801A00C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _0801A04C @ =0x03000090
	str r5, [r0]
	ldr r0, _0801A050 @ =0x00001C1A
	bl GetParticleGroup
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r5, r2
	str r0, [r1]
	movs r1, #0
	movs r0, #0x78
	strh r0, [r5, #0x18]
	movs r0, #0x50
	strh r0, [r5, #0x1a]
	strh r1, [r5, #0x1c]
	adds r4, r5, #0
	adds r4, #0x20
	movs r6, #3
_0801A034:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08019af4
	adds r4, #0x38
	subs r6, #1
	cmp r6, #0
	bge _0801A034
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801A04C: .4byte 0x03000090
_0801A050: .4byte 0x00001C1A

	thumb_func_start Entity4B15_Create
Entity4B15_Create: @ 0x0801A054
	push {r4, lr}
	ldr r0, _0801A08C @ =0x03000090
	ldr r0, [r0]
	cmp r0, #0
	bne _0801A09A
	movs r1, #0x82
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801A098
	ldr r1, _0801A090 @ =Entity4B15_Update
	ldr r2, _0801A094 @ =Entity4B15_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity4B15_Init
	cmp r0, #0
	bge _0801A098
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801A09A
	.align 2, 0
_0801A08C: .4byte 0x03000090
_0801A090: .4byte Entity4B15_Update
_0801A094: .4byte Entity4B15_Destroy
_0801A098:
	adds r0, r4, #0
_0801A09A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801a0a0
FUN_0801a0a0: @ 0x0801A0A0
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	ldr r0, _0801A0C0 @ =0x03000090
	ldr r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _0801A100
	ldr r0, _0801A0C4 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0801A0C8
	movs r0, #1
	rsbs r0, r0, #0
	b _0801A0CC
	.align 2, 0
_0801A0C0: .4byte 0x03000090
_0801A0C4: .4byte 0x03002C68
_0801A0C8:
	movs r1, #0x18
	ldrsh r0, [r0, r1]
_0801A0CC:
	cmp r0, r3
	beq _0801A100
	lsls r4, r3, #3
	subs r4, r4, r3
	lsls r4, r4, #3
	adds r4, #0x20
	ldr r2, [r2]
	adds r4, r2, r4
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r4, #0x30]
	str r1, [r4, #0x34]
	adds r0, r4, #0
	adds r0, #8
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r2, r1
	ldr r1, [r2]
	movs r2, #0x33
	bl FUN_0822dafc
	movs r1, #1
	movs r0, #0
	strb r1, [r4]
	str r0, [r4, #4]
	strb r1, [r4, #2]
_0801A100:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801a108
FUN_0801a108: @ 0x0801A108
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	ldr r0, _0801A128 @ =0x03000090
	ldr r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _0801A16A
	ldr r0, _0801A12C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0801A130
	movs r0, #1
	rsbs r0, r0, #0
	b _0801A134
	.align 2, 0
_0801A128: .4byte 0x03000090
_0801A12C: .4byte 0x03002C68
_0801A130:
	movs r1, #0x18
	ldrsh r0, [r0, r1]
_0801A134:
	cmp r0, r3
	beq _0801A16A
	lsls r4, r3, #3
	subs r4, r4, r3
	lsls r4, r4, #3
	adds r4, #0x20
	ldr r2, [r2]
	adds r4, r2, r4
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r4, #0x30]
	str r1, [r4, #0x34]
	adds r0, r4, #0
	adds r0, #8
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r2, r1
	ldr r1, [r2]
	movs r2, #0x35
	bl FUN_0822dafc
	movs r0, #2
	movs r1, #0
	strb r0, [r4]
	str r1, [r4, #4]
	movs r0, #1
	strb r0, [r4, #2]
_0801A16A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801a170
FUN_0801a170: @ 0x0801A170
	bx lr
	.align 2, 0

	thumb_func_start FUN_0801a174
FUN_0801a174: @ 0x0801A174
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	adds r7, r1, #0
	movs r1, #0xa
	ldrsh r0, [r7, r1]
	mov r2, r8
	movs r3, #0x1e
	ldrsh r1, [r2, r3]
	ldrb r5, [r7, #5]
	adds r1, r1, r5
	subs r1, r0, r1
	movs r0, #0x96
	lsls r0, r0, #3
	cmp r1, r0
	ble _0801A1B8
	ldrh r0, [r7, #0xa]
	subs r0, #0x18
	strh r0, [r7, #0xa]
	adds r6, r7, #0
	adds r6, #0x18
	movs r1, #1
	movs r4, #2
_0801A1A8:
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	subs r4, #1
	adds r6, #0x28
	cmp r4, #0
	bge _0801A1A8
	b _0801A3A0
_0801A1B8:
	cmp r1, #0x18
	bgt _0801A1BE
	b _0801A2FA
_0801A1BE:
	ldrh r0, [r7, #0xa]
	subs r0, #0x18
	strh r0, [r7, #0xa]
	adds r6, r7, #0
	adds r6, #0x18
	ldr r0, [r7, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	mov sb, r1
	ands r0, r1
	str r0, [r7, #0x18]
	ldrb r0, [r7, #2]
	cmp r0, #0
	bne _0801A2AC
	movs r0, #0x18
	strb r0, [r7, #2]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	movs r2, #1
	mov ip, r2
	orrs r1, r2
	str r1, [r0]
	ldrb r0, [r7, #1]
	adds r0, #1
	strb r0, [r7, #1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0801A204
	mov r3, ip
	strb r3, [r7, #1]
_0801A204:
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r6, r0
	ldr r5, _0801A2A0 @ =0x0203B400
	mov sl, r5
	ldr r4, _0801A2A4 @ =0x030046B8
	ldr r2, [r4]
	adds r2, #1
	ldr r3, _0801A2A8 @ =0x000003FF
	ands r2, r3
	lsls r1, r2, #1
	add r1, sl
	ldrh r1, [r1]
	mov r5, ip
	ands r1, r5
	subs r1, #4
	adds r2, #1
	ands r2, r3
	str r2, [r4]
	lsls r2, r2, #1
	add r2, sl
	ldrh r2, [r2]
	ands r2, r5
	subs r2, #4
	bl FUN_0822dad4
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r6, r0
	mov r2, r8
	ldr r1, [r2, #0x28]
	movs r2, #2
	bl FUN_0822dafc
	ldrb r0, [r7, #1]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r3, r8
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
	strb r0, [r1, #0xe]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	mov r5, sb
	ands r1, r5
	str r1, [r0]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	orrs r1, r2
	str r1, [r0]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r7, #8]
	ldr r2, [r7, #0xc]
	str r1, [r0, #0x18]
	str r2, [r0, #0x1c]
	b _0801A3A0
	.align 2, 0
_0801A2A0: .4byte 0x0203B400
_0801A2A4: .4byte 0x030046B8
_0801A2A8: .4byte 0x000003FF
_0801A2AC:
	subs r0, #1
	strb r0, [r7, #2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x16
	bne _0801A2E0
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r6, r0
	mov r2, r8
	ldr r1, [r2, #0x28]
	movs r2, #2
	bl FUN_0822dafc
	ldrb r0, [r7, #1]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r3, r8
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
	strb r0, [r1, #0xe]
_0801A2E0:
	ldrb r0, [r7, #2]
	cmp r0, #0x14
	bne _0801A3A0
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _0801A3A0
_0801A2FA:
	movs r1, #0
	movs r0, #2
	strb r0, [r7]
	strh r1, [r7, #6]
	ldr r2, _0801A3B8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801A3BC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _0801A3C0 @ =0x0203B400
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	adds r0, #4
	strb r0, [r7, #3]
	adds r6, r7, #0
	adds r6, #0x18
	movs r4, #0
	movs r0, #0x10
	adds r0, r0, r7
	mov sl, r0
	movs r1, #0x13
	adds r1, r1, r7
	mov sb, r1
	adds r5, r2, #0
_0801A332:
	ldr r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r1, r0
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r6]
	mov r2, r8
	ldr r1, [r2, #0x28]
	adds r0, r6, #0
	movs r2, #2
	bl FUN_0822dafc
	mov r3, r8
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
	strb r0, [r6, #0xe]
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r6, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
	mov r0, sl
	adds r1, r0, r4
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _0801A3BC @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _0801A3C0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	mov r3, sb
	adds r2, r3, r4
	movs r0, #3
	ands r1, r0
	strb r1, [r2]
	adds r4, #1
	adds r6, #0x28
	cmp r4, #2
	ble _0801A332
	ldr r0, _0801A3C4 @ =0x03002BE0
	ldr r0, [r0]
	bl FUN_0807a8e0
_0801A3A0:
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r7, #0x30]
	str r1, [r7, #0x34]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801A3B8: .4byte 0x030046B8
_0801A3BC: .4byte 0x000003FF
_0801A3C0: .4byte 0x0203B400
_0801A3C4: .4byte 0x03002BE0

	thumb_func_start FUN_0801a3c8
FUN_0801a3c8: @ 0x0801A3C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r0
	adds r6, r1, #0
	ldrb r0, [r6, #4]
	mov sb, r0
	adds r4, r6, #0
	adds r4, #0x18
	movs r1, #0
	mov r8, r1
_0801A3E4:
	mov r0, sb
	adds r0, #0x40
	movs r2, #0xff
	ands r0, r2
	lsls r0, r0, #1
	ldr r7, _0801A424 @ =0x085B0A08
	adds r0, r0, r7
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrb r0, [r6, #3]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	ldrh r7, [r4, #0x18]
	adds r0, r0, r7
	strh r0, [r4, #0x18]
	ldrh r0, [r6, #6]
	cmp r0, #0x18
	bhi _0801A43A
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r2, _0801A424 @ =0x085B0A08
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	lsls r0, r0, #6
	cmp r0, #0
	blt _0801A428
	asrs r1, r0, #0xc
	b _0801A42E
	.align 2, 0
_0801A424: .4byte 0x085B0A08
_0801A428:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0801A42E:
	mov r2, sl
	ldrh r0, [r2, #0x1e]
	adds r0, r0, r1
	ldrb r7, [r6, #5]
	adds r0, r0, r7
	b _0801A43E
_0801A43A:
	ldrh r0, [r4, #0x1a]
	subs r0, #0xa
_0801A43E:
	strh r0, [r4, #0x1a]
	mov r1, sb
	lsls r0, r1, #1
	ldr r2, _0801A524 @ =0x085B0A08
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldrb r0, [r6, #3]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	movs r2, #0
	mov ip, r2
	strh r0, [r4, #0x1c]
	adds r0, r6, #0
	adds r0, #0x13
	mov r7, r8
	adds r5, r0, r7
	ldrb r1, [r5]
	adds r1, #1
	strb r1, [r5]
	movs r2, #0xff
	mov r0, sp
	strb r2, [r0]
	lsls r1, r1, #0x18
	ldr r2, _0801A528 @ =0x085AA970
	adds r0, r6, #0
	adds r0, #0x10
	adds r3, r0, r7
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	lsrs r1, r1, #0x18
	ldrh r0, [r0]
	cmp r1, r0
	blo _0801A4B6
	mov r7, ip
	strb r7, [r5]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	mov r1, sp
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #1
	bls _0801A4A0
	mov r2, ip
	strb r2, [r3]
_0801A4A0:
	mov r7, sl
	ldr r1, [r7, #0x28]
	ldrb r2, [r3]
	adds r2, #2
	adds r0, r4, #0
	bl FUN_0822dafc
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
	strb r0, [r4, #0xe]
_0801A4B6:
	ldr r2, _0801A52C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801A530 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0801A534 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r1, #0x4c
	mov r2, sb
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	movs r7, #1
	add r8, r7
	adds r4, #0x28
	mov r0, r8
	cmp r0, #2
	bgt _0801A4EC
	b _0801A3E4
_0801A4EC:
	ldrh r0, [r6, #6]
	cmp r0, #0x1f
	bls _0801A514
	adds r4, r6, #0
	adds r4, #0x18
	movs r1, #1
	movs r2, #2
	mov r8, r2
_0801A4FC:
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r7, #1
	rsbs r7, r7, #0
	add r8, r7
	adds r4, #0x28
	mov r0, r8
	cmp r0, #0
	bge _0801A4FC
	movs r0, #0
	strb r0, [r6]
_0801A514:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801A524: .4byte 0x085B0A08
_0801A528: .4byte 0x085AA970
_0801A52C: .4byte 0x030046B8
_0801A530: .4byte 0x000003FF
_0801A534: .4byte 0x0203B400

	thumb_func_start Entity4F5C_Update
Entity4F5C_Update: @ 0x0801A538
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	movs r7, #0
	adds r4, r5, #0
	adds r4, #0x2c
	ldr r0, _0801A568 @ =0x085AA974
	mov r8, r0
	movs r6, #2
_0801A55C:
	ldrb r0, [r4]
	cmp r0, #0
	bne _0801A56C
	adds r7, #1
	b _0801A582
	.align 2, 0
_0801A568: .4byte 0x085AA974
_0801A56C:
	ldrb r0, [r4]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	bl _call_via_r2
	ldrh r0, [r4, #6]
	adds r0, #1
	strh r0, [r4, #6]
_0801A582:
	subs r6, #1
	adds r4, #0x90
	cmp r6, #0
	bge _0801A55C
	cmp r7, #3
	bne _0801A5A4
	ldrh r0, [r5, #0x1a]
	cmp r0, #0
	beq _0801A59E
	movs r1, #0
	bl Script_ExecById
	movs r0, #0
	strh r0, [r5, #0x1a]
_0801A59E:
	adds r0, r5, #0
	bl KillEntity
_0801A5A4:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity4F5C_Destroy
Entity4F5C_Destroy: @ 0x0801A5B0
	push {r4, r5, r6, r7, lr}
	adds r0, #0x2c
	movs r1, #0
_0801A5B6:
	adds r6, r1, #1
	adds r7, r0, #0
	adds r7, #0x90
	adds r4, r0, #0
	adds r4, #0x18
	movs r5, #2
_0801A5C2:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x28
	subs r5, #1
	cmp r5, #0
	bge _0801A5C2
	adds r1, r6, #0
	adds r0, r7, #0
	cmp r1, #2
	ble _0801A5B6
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity4F5C_Init
Entity4F5C_Init: @ 0x0801A5E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, _0801A604 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xee
	lsls r1, r1, #1
	adds r5, r7, r1
	str r0, [r5]
	cmp r0, #0
	bne _0801A608
	movs r0, #1
	rsbs r0, r0, #0
	b _0801A7FA
	.align 2, 0
_0801A604: .4byte 0x03002BE0
_0801A608:
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	movs r4, #0
	strh r0, [r7, #0x1a]
	ldr r3, [r5]
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, [sp]
	asrs r0, r2, #0x10
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r1, _0801A6E4 @ =0x0000FFFF
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	strh r4, [r7, #0x18]
	ldr r0, _0801A6E8 @ =0x00001C1C
	bl GetParticleGroup
	str r0, [r7, #0x24]
	ldr r0, _0801A6EC @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r7, #0x28]
	adds r5, r7, #0
	adds r5, #0x2c
	mov r8, r4
	ldr r2, _0801A6F0 @ =0x030046B8
	mov sl, r2
_0801A656:
	adds r4, r5, #0
	adds r4, #0x18
	movs r0, #1
	strb r0, [r5]
	strb r0, [r5, #1]
	mov r3, sl
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _0801A6F4 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _0801A6F8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	strb r0, [r5, #2]
	movs r3, #0
	strb r3, [r5, #3]
	mov r1, r8
	lsls r0, r1, #8
	movs r1, #3
	bl Div
	mov r3, sl
	ldr r2, [r3]
	adds r2, #1
	ldr r1, _0801A6F4 @ =0x000003FF
	ands r2, r1
	str r2, [r3]
	lsls r1, r2, #1
	ldr r3, _0801A6F8 @ =0x0203B400
	adds r1, r1, r3
	ldrh r1, [r1]
	movs r3, #0x3f
	ands r1, r3
	adds r0, r0, r1
	strb r0, [r5, #4]
	movs r0, #0
	strh r0, [r5, #6]
	ldrb r1, [r5, #4]
	adds r2, #1
	ldr r3, _0801A6F4 @ =0x000003FF
	ands r2, r3
	mov r0, sl
	str r2, [r0]
	lsls r2, r2, #1
	ldr r3, _0801A6F8 @ =0x0203B400
	adds r2, r2, r3
	ldrh r2, [r2]
	movs r0, #0x3f
	adds r3, r5, #0
	adds r3, #8
	adds r6, r1, #0
	ands r2, r0
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r1, _0801A6FC @ =0x085B0A08
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _0801A700
	asrs r0, r0, #0xc
	b _0801A706
	.align 2, 0
_0801A6E4: .4byte 0x0000FFFF
_0801A6E8: .4byte 0x00001C1C
_0801A6EC: .4byte 0x00001C1E
_0801A6F0: .4byte 0x030046B8
_0801A6F4: .4byte 0x000003FF
_0801A6F8: .4byte 0x0203B400
_0801A6FC: .4byte 0x085B0A08
_0801A700:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0801A706:
	strh r0, [r3]
	movs r0, #0
	strh r0, [r3, #2]
	lsls r0, r6, #1
	ldr r1, _0801A720 @ =0x085B0A08
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _0801A724
	asrs r0, r0, #0xc
	b _0801A72A
	.align 2, 0
_0801A720: .4byte 0x085B0A08
_0801A724:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0801A72A:
	strh r0, [r3, #4]
	mov r2, sl
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0801A7A8 @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0801A7AC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x24
	strb r0, [r5, #5]
	mov r2, sp
	ldrh r0, [r2]
	ldrh r3, [r5, #8]
	adds r0, r0, r3
	strh r0, [r5, #8]
	ldr r1, _0801A7B0 @ =0x085AA980
	mov r2, r8
	lsls r0, r2, #1
	adds r0, r0, r1
	ldr r3, [sp]
	asrs r1, r3, #0x10
	ldrh r0, [r0]
	adds r1, r1, r0
	ldrh r0, [r5, #0xa]
	adds r0, r0, r1
	strh r0, [r5, #0xa]
	mov r1, sp
	ldrh r0, [r1, #4]
	ldrh r2, [r5, #0xc]
	adds r0, r0, r2
	strh r0, [r5, #0xc]
	movs r6, #0
	movs r3, #1
	add r8, r3
	movs r0, #0x90
	adds r0, r0, r5
	mov sb, r0
_0801A77E:
	ldr r1, [r7, #0x24]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	cmp r6, #0
	bne _0801A7B4
	ldr r1, [r7, #0x24]
	adds r0, r4, #0
	movs r2, #0x1c
	bl FUN_0822dafc
	ldr r0, [r7, #0x24]
	ldrh r0, [r0, #6]
	b _0801A7C4
	.align 2, 0
_0801A7A8: .4byte 0x000003FF
_0801A7AC: .4byte 0x0203B400
_0801A7B0: .4byte 0x085AA980
_0801A7B4:
	ldr r1, [r7, #0x28]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_0822dafc
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
_0801A7C4:
	strb r0, [r4, #0xe]
	ldrh r0, [r5, #8]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r0, [r5, #0xa]
	ldrh r2, [r4, #0x1a]
	adds r0, r0, r2
	strh r0, [r4, #0x1a]
	ldrh r0, [r5, #0xc]
	ldrh r3, [r4, #0x1c]
	adds r0, r0, r3
	strh r0, [r4, #0x1c]
	adds r6, #1
	adds r4, #0x28
	cmp r6, #2
	ble _0801A77E
	mov r5, sb
	mov r0, r8
	cmp r0, #2
	bgt _0801A7F0
	b _0801A656
_0801A7F0:
	movs r0, #0x9f
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r0, #0
_0801A7FA:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity4F5C_Create
Entity4F5C_Create: @ 0x0801A80C
	push {r4, lr}
	movs r1, #0xf0
	lsls r1, r1, #1
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801A844
	ldr r1, _0801A83C @ =Entity4F5C_Update
	ldr r2, _0801A840 @ =Entity4F5C_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity4F5C_Init
	cmp r0, #0
	bge _0801A844
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801A846
	.align 2, 0
_0801A83C: .4byte Entity4F5C_Update
_0801A840: .4byte Entity4F5C_Destroy
_0801A844:
	adds r0, r4, #0
_0801A846:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start EntityFBE5_Update
EntityFBE5_Update: @ 0x0801A84C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, [r4, #0x18]
	cmp r1, #7
	bhi _0801A868
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	beq _0801A880
	ldr r0, [r4, #0x44]
	movs r1, #1
	orrs r0, r1
	b _0801A888
_0801A868:
	cmp r1, #0xf
	bhi _0801A87C
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	bls _0801A880
	ldr r0, [r4, #0x44]
	movs r1, #1
	orrs r0, r1
	b _0801A888
_0801A87C:
	cmp r1, #0x10
	bne _0801A88A
_0801A880:
	ldr r0, [r4, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_0801A888:
	str r0, [r4, #0x44]
_0801A88A:
	ldr r0, [r4, #0x18]
	cmp r0, #0x1e
	bne _0801A8A4
	adds r0, r4, #0
	adds r0, #0x3c
	adds r1, r4, #0
	adds r1, #0x1c
	movs r2, #0
	str r2, [sp]
	movs r2, #0x19
	movs r3, #1
	bl FUN_082370cc
_0801A8A4:
	ldr r2, [r4, #0x18]
	cmp r2, #0x59
	bls _0801A8E2
	cmp r2, #0x69
	bhi _0801A8C0
	movs r0, #3
	ands r0, r2
	cmp r0, #1
	bhi _0801A8DA
	ldr r0, [r4, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _0801A8E0
_0801A8C0:
	cmp r2, #0x7e
	bhi _0801A8D6
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _0801A8DA
	ldr r0, [r4, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _0801A8E0
_0801A8D6:
	cmp r2, #0x7f
	bne _0801A8E2
_0801A8DA:
	ldr r0, [r4, #0x44]
	movs r1, #1
	orrs r0, r1
_0801A8E0:
	str r0, [r4, #0x44]
_0801A8E2:
	cmp r2, #0xb4
	bne _0801A900
	ldr r0, [r4, #0x44]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x44]
	adds r0, r4, #0
	adds r0, #0x9c
	ldr r0, [r0]
	cmp r0, #0
	beq _0801A912
	movs r1, #0
	bl Script_ExecById
	b _0801A912
_0801A900:
	adds r0, r4, #0
	adds r0, #0x3c
	adds r1, r4, #0
	adds r1, #0x1c
	bl FUN_082372cc
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
_0801A912:
	movs r0, #0
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start EntityFBE5_Destroy
EntityFBE5_Destroy: @ 0x0801A91C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0801A93C @ =FUN_0822db5c
	ldr r2, _0801A940 @ =FUN_0822aaac
	ldr r3, _0801A944 @ =FUN_0822f204
	movs r0, #0
	bl FUN_0822a448
	adds r4, #0x3c
	adds r0, r4, #0
	bl FUN_0822f1c0
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801A93C: .4byte FUN_0822db5c
_0801A940: .4byte FUN_0822aaac
_0801A944: .4byte FUN_0822f204

	thumb_func_start EntityFBE5_Init
EntityFBE5_Init: @ 0x0801A948
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x2c
	adds r6, r0, #0
	ldr r0, _0801A968 @ =0x0000CB05
	ldr r1, _0801A96C @ =0x0000D3DA
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _0801A970
	movs r0, #1
	rsbs r0, r0, #0
	b _0801AA84
	.align 2, 0
_0801A968: .4byte 0x0000CB05
_0801A96C: .4byte 0x0000D3DA
_0801A970:
	adds r1, r6, #0
	adds r1, #0x1c
	adds r0, r2, #0
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r6, #0
	adds r4, #0x1c
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	movs r0, #0x70
	bl VM_SeekToKeyword
	adds r7, r4, #0
	cmp r0, #0
	beq _0801A9CC
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0801A9C4 @ =0xFFFF0000
	ldr r1, [sp, #0x24]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x24]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0801A9C8 @ =0x0000FFFF
	ldr r1, [sp, #0x24]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x24]
	add r1, sp, #0x24
	ldr r0, [r1, #4]
	ands r0, r4
	b _0801A9E8
	.align 2, 0
_0801A9C4: .4byte 0xFFFF0000
_0801A9C8: .4byte 0x0000FFFF
_0801A9CC:
	ldr r2, _0801AA90 @ =0xFFFF0000
	ldr r0, [sp, #0x24]
	ands r0, r2
	movs r1, #0x78
	orrs r0, r1
	ldr r1, _0801AA94 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x24]
	add r1, sp, #0x24
	ldr r0, [r1, #4]
	ands r0, r2
_0801A9E8:
	str r0, [r1, #4]
	mov r8, r1
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r6, #0
	adds r1, #0x9c
	str r0, [r1]
	movs r4, #0
	str r4, [r6, #0x18]
	adds r5, r6, #0
	adds r5, #0x3c
	ldr r3, _0801AA98 @ =0x00002011
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r0, r8
	str r0, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_0822f3fc
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r7, #0
	movs r2, #0x18
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _0801AA9C @ =FUN_0822e424
	ldr r2, _0801AAA0 @ =FUN_0822af38
	ldr r3, _0801AAA4 @ =FUN_0822f264
	movs r0, #0
	bl FUN_0822a448
	movs r0, #2
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	movs r0, #0x1f
	str r0, [sp, #0x18]
	str r0, [sp, #0x1c]
	str r0, [sp, #0x20]
	movs r0, #3
	movs r1, #5
	add r2, sp, #0x10
	bl FUN_08002800
	movs r2, #0
	adds r4, r6, #0
	adds r4, #0xa0
	movs r1, #0x76
	adds r1, r1, r6
	mov ip, r1
	adds r5, #0x48
	adds r6, r4, #0
	ldr r1, _0801AAA8 @ =0x00001084
_0801AA60:
	lsls r0, r2, #5
	adds r3, r2, #1
	movs r2, #0xf
	adds r0, r0, r6
	adds r0, #0x1e
_0801AA6A:
	strh r1, [r0]
	subs r0, #2
	subs r2, #1
	cmp r2, #0
	bge _0801AA6A
	adds r2, r3, #0
	cmp r2, #0xf
	ble _0801AA60
	ldr r0, _0801AAAC @ =0x00006541
	mov r3, ip
	strh r0, [r3]
	str r4, [r5]
	movs r0, #0
_0801AA84:
	add sp, #0x2c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801AA90: .4byte 0xFFFF0000
_0801AA94: .4byte 0x0000FFFF
_0801AA98: .4byte 0x00002011
_0801AA9C: .4byte FUN_0822e424
_0801AAA0: .4byte FUN_0822af38
_0801AAA4: .4byte FUN_0822f264
_0801AAA8: .4byte 0x00001084
_0801AAAC: .4byte 0x00006541

	thumb_func_start EntityFBE5_Create
EntityFBE5_Create: @ 0x0801AAB0
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xa8
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801AAEC
	ldr r1, _0801AAE4 @ =EntityFBE5_Update
	ldr r2, _0801AAE8 @ =EntityFBE5_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl EntityFBE5_Init
	cmp r0, #0
	bge _0801AAEC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801AAEE
	.align 2, 0
_0801AAE4: .4byte EntityFBE5_Update
_0801AAE8: .4byte EntityFBE5_Destroy
_0801AAEC:
	adds r0, r4, #0
_0801AAEE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801aaf4
FUN_0801aaf4: @ 0x0801AAF4
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	movs r0, #8
	adds r0, r0, r1
	mov sb, r0
	ldr r0, [r1, #8]
	movs r3, #2
	rsbs r3, r3, #0
	ands r0, r3
	str r0, [r1, #8]
	movs r0, #0
	mov r8, r0
	movs r6, #1
	movs r0, #1
	strb r0, [r1]
	ldr r5, _0801ABA4 @ =0x0203B400
	ldr r3, _0801ABA8 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r4, _0801ABAC @ =0x000003FF
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r2, r6
	adds r2, #3
	ands r0, r6
	adds r2, r2, r0
	strb r2, [r1, #1]
	ldr r0, [r3]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	adds r0, #5
	ldrb r2, [r1, #1]
	subs r0, r0, r2
	asrs r0, r0, #2
	strb r0, [r1, #2]
	ldr r0, [r3]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #7
	ands r0, r2
	adds r0, #1
	strb r0, [r1, #3]
	mov r2, r8
	strb r2, [r1, #4]
	mov r0, r8
	strh r0, [r1, #6]
	ldr r0, [r3]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrb r1, [r1]
	subs r1, #0x10
	mov r2, sb
	strh r1, [r2, #0x1c]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, #0xa0
	strh r0, [r2, #0x1e]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801ABA4: .4byte 0x0203B400
_0801ABA8: .4byte 0x030046B8
_0801ABAC: .4byte 0x000003FF

	thumb_func_start FUN_0801abb0
FUN_0801abb0: @ 0x0801ABB0
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	adds r4, r6, #0
	adds r4, #8
	adds r1, r5, #0
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0x11
	bl FUN_0822a470
	ldr r1, _0801ABF0 @ =0x085AA988
	movs r0, #3
	mov r2, r8
	ands r0, r2
	adds r0, r0, r1
	ldrb r0, [r0]
	strh r0, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #7]
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_0801aaf4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801ABF0: .4byte 0x085AA988

	thumb_func_start FUN_0801abf4
FUN_0801abf4: @ 0x0801ABF4
	push {lr}
	adds r0, r1, #0
	adds r0, #8
	bl FUN_0822a4e0
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity78C9_Update
Entity78C9_Update: @ 0x0801AC04
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0x38
	movs r6, #0
	ldr r0, _0801ACC8 @ =0x030046B8
	mov sl, r0
	ldr r1, _0801ACCC @ =0x085B0A08
	mov sb, r1
	movs r2, #0xff
	mov r8, r2
_0801AC22:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801ACB0
	adds r5, r4, #0
	adds r5, #8
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0801ACD0 @ =0x000003FF
	ands r0, r1
	mov r2, sl
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0801ACD4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #1
	ands r2, r0
	ldrb r1, [r4, #3]
	adds r1, r1, r2
	ldrb r0, [r4, #4]
	adds r0, r0, r1
	strb r0, [r4, #4]
	movs r3, #4
	ldrsb r3, [r4, r3]
	cmp r3, #0
	bge _0801AC5A
	rsbs r3, r3, #0
_0801AC5A:
	adds r0, r3, #0
	adds r0, #0x40
	mov r2, r8
	ands r0, r2
	lsls r0, r0, #1
	add r0, sb
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #2
	ldrsb r0, [r4, r0]
	adds r2, r1, #0
	muls r2, r0, r2
	mov r0, r8
	ands r3, r0
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrb r1, [r4, #1]
	muls r1, r0, r1
	asrs r1, r1, #0xc
	asrs r2, r2, #0xc
	ldrh r0, [r5, #0x1c]
	adds r2, r2, r0
	strh r2, [r5, #0x1c]
	ldrh r0, [r5, #0x1e]
	subs r0, r0, r1
	strh r0, [r5, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x14
	rsbs r1, r1, #0
	cmp r0, r1
	bgt _0801ACB0
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_0801aaf4
_0801ACB0:
	adds r6, #1
	adds r4, #0x34
	cmp r6, #0x1f
	ble _0801AC22
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801ACC8: .4byte 0x030046B8
_0801ACCC: .4byte 0x085B0A08
_0801ACD0: .4byte 0x000003FF
_0801ACD4: .4byte 0x0203B400

	thumb_func_start Entity78C9_Destroy
Entity78C9_Destroy: @ 0x0801ACD8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x38
	movs r4, #0
_0801ACE2:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0801abf4
	adds r4, #1
	adds r5, #0x34
	cmp r4, #0x1f
	ble _0801ACE2
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start Entity78C9_Init
Entity78C9_Init: @ 0x0801ACFC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x38
	adds r0, #0x1c
	ldr r1, _0801AD28 @ =0x00002E7B
	bl Video_GetActorSprite
	movs r4, #0
_0801AD0E:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0801abb0
	adds r4, #1
	adds r5, #0x34
	cmp r4, #0x1f
	ble _0801AD0E
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801AD28: .4byte 0x00002E7B

	thumb_func_start Entity78C9_Create
Entity78C9_Create: @ 0x0801AD2C
	push {r4, lr}
	movs r1, #0xd7
	lsls r1, r1, #3
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801AD64
	ldr r1, _0801AD5C @ =Entity78C9_Update
	ldr r2, _0801AD60 @ =Entity78C9_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity78C9_Init
	cmp r0, #0
	bge _0801AD64
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801AD66
	.align 2, 0
_0801AD5C: .4byte Entity78C9_Update
_0801AD60: .4byte Entity78C9_Destroy
_0801AD64:
	adds r0, r4, #0
_0801AD66:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801ad6c
FUN_0801ad6c: @ 0x0801AD6C
	ldr r1, _0801AD74 @ =0x03000094
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0801AD74: .4byte 0x03000094

	thumb_func_start FUN_0801ad78
FUN_0801ad78: @ 0x0801AD78
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	mov r8, r1
	ldrh r0, [r6, #0x18]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x14
	adds r2, r1, #0
	adds r0, r1, #0
	muls r0, r1, r0
	mov sb, r0
	ldr r3, _0801AE60 @ =0x000002F6
	adds r0, r6, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r3, r0, r1
	cmp r3, #0
	bge _0801ADA6
	movs r3, #0
_0801ADA6:
	adds r7, r0, r1
	cmp r7, #0xb4
	ble _0801ADAE
	movs r7, #0xb4
_0801ADAE:
	subs r0, r2, r0
	mov r0, r8
	lsls r2, r0, #1
	adds r1, r2, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x24
	adds r5, r6, r0
	mov sl, r2
	cmp r3, #0
	ble _0801ADD4
	movs r0, #0
	adds r4, r3, #0
_0801ADCA:
	strh r0, [r5]
	subs r4, #1
	adds r5, #2
	cmp r4, #0
	bne _0801ADCA
_0801ADD4:
	adds r4, r3, #0
	cmp r4, r7
	bge _0801AE28
	movs r3, #0xff
_0801ADDC:
	ldr r1, _0801AE60 @ =0x000002F6
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r0, r0, r4
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	mov r2, sb
	subs r0, r2, r0
	str r3, [sp]
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r2, r1, r0
	adds r1, r1, r0
	ldr r3, [sp]
	cmp r2, #0
	bge _0801AE10
	movs r2, #0
_0801AE10:
	cmp r1, #0xf0
	ble _0801AE16
	movs r1, #0xf0
_0801AE16:
	ands r2, r3
	lsls r0, r2, #8
	ands r1, r3
	orrs r0, r1
	strh r0, [r5]
	adds r4, #1
	adds r5, #2
	cmp r4, r7
	blt _0801ADDC
_0801AE28:
	adds r4, r7, #0
	cmp r4, #0xb3
	bgt _0801AE3A
	movs r0, #0
_0801AE30:
	strh r0, [r5]
	adds r4, #1
	adds r5, #2
	cmp r4, #0xb3
	ble _0801AE30
_0801AE3A:
	mov r1, sl
	add r1, r8
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r6, r3
	adds r1, r1, r0
	movs r0, #0
	strh r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801AE60: .4byte 0x000002F6

	thumb_func_start FUN_0801ae64
FUN_0801ae64: @ 0x0801AE64
	ldr r0, _0801AE7C @ =0x03003518
	movs r1, #0
	str r1, [r0]
	ldr r0, _0801AE80 @ =0x03002CA0
	str r1, [r0]
	ldr r2, _0801AE84 @ =0x03003510
	movs r0, #1
	strh r0, [r2]
	ldr r0, _0801AE88 @ =0x03003514
	strh r1, [r0]
	bx lr
	.align 2, 0
_0801AE7C: .4byte 0x03003518
_0801AE80: .4byte 0x03002CA0
_0801AE84: .4byte 0x03003510
_0801AE88: .4byte 0x03003514

	thumb_func_start FUN_0801ae8c
FUN_0801ae8c: @ 0x0801AE8C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _0801AED8 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0801AF70
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, [sp]
	asrs r1, r2, #0x10
	adds r1, #0xa4
	lsls r1, r1, #0x10
	ldr r0, _0801AEDC @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r6, r5, r0
	mov r7, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0801AEE0
	asrs r0, r0, #8
	b _0801AEE6
	.align 2, 0
_0801AED8: .4byte 0x03002BE0
_0801AEDC: .4byte 0x0000FFFF
_0801AEE0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801AEE6:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0801AEF8
	asrs r0, r0, #8
	b _0801AEFE
_0801AEF8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801AEFE:
	adds r4, r0, #0
	movs r2, #2
	ldrsh r1, [r7, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0801AF12
	asrs r0, r0, #8
	b _0801AF18
_0801AF12:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801AF18:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0801AF48 @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _0801AF4C
	movs r0, #0
	b _0801AF52
	.align 2, 0
_0801AF48: .4byte 0x030047C8
_0801AF4C:
	cmp r0, #0xf0
	ble _0801AF54
	movs r0, #0xf0
_0801AF52:
	strh r0, [r1]
_0801AF54:
	ldr r0, _0801AF64 @ =0x000002F6
	adds r1, r5, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _0801AF68
	movs r0, #0
	b _0801AF80
	.align 2, 0
_0801AF64: .4byte 0x000002F6
_0801AF68:
	cmp r0, #0xb4
	ble _0801AF82
	movs r0, #0xb4
	b _0801AF80
_0801AF70:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0x78
	strh r0, [r1]
	ldr r2, _0801AFDC @ =0x000002F6
	adds r1, r5, r2
	movs r0, #0x5a
_0801AF80:
	strh r0, [r1]
_0801AF82:
	ldrh r1, [r5, #0x22]
	movs r4, #1
	subs r1, r4, r1
	adds r0, r5, #0
	bl FUN_0801ad78
	ldr r2, _0801AFE0 @ =0x03003518
	ldrh r0, [r5, #0x22]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x24
	adds r0, r5, r0
	str r0, [r2]
	ldr r1, _0801AFE4 @ =0x03002CA0
	ldr r0, _0801AFE8 @ =0x04000040
	str r0, [r1]
	ldr r0, _0801AFEC @ =0x03003510
	strh r4, [r0]
	ldr r0, _0801AFF0 @ =0x03003514
	strh r4, [r0]
	ldrh r0, [r5, #0x1a]
	cmp r0, #0
	beq _0801AFF8
	ldrh r0, [r5, #0x1c]
	ldrh r1, [r5, #0x18]
	adds r0, r0, r1
	strh r0, [r5, #0x18]
	lsls r0, r0, #0x10
	ldr r1, _0801AFF4 @ =0x0F9F0000
	cmp r0, r1
	ble _0801B01A
	movs r0, #0xfa
	lsls r0, r0, #4
	strh r0, [r5, #0x18]
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	beq _0801B01A
	adds r0, r5, #0
	bl KillEntity
	b _0801B01A
	.align 2, 0
_0801AFDC: .4byte 0x000002F6
_0801AFE0: .4byte 0x03003518
_0801AFE4: .4byte 0x03002CA0
_0801AFE8: .4byte 0x04000040
_0801AFEC: .4byte 0x03003510
_0801AFF0: .4byte 0x03003514
_0801AFF4: .4byte 0x0F9F0000
_0801AFF8:
	ldrh r0, [r5, #0x18]
	ldrh r1, [r5, #0x1c]
	subs r0, r0, r1
	strh r0, [r5, #0x18]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	bgt _0801B01A
	strh r1, [r5, #0x18]
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	beq _0801B01A
	adds r0, r5, #0
	bl KillEntity
_0801B01A:
	ldrh r0, [r5, #0x22]
	movs r1, #1
	subs r1, r1, r0
	strh r1, [r5, #0x22]
	ldrh r0, [r5, #0x20]
	adds r0, #1
	strh r0, [r5, #0x20]
	movs r0, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801b034
FUN_0801b034: @ 0x0801B034
	push {lr}
	sub sp, #4
	bl FUN_0801ae64
	bl VBlankIntrWait
	movs r0, #0xb4
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0xf0
	bl FUN_0822cdcc
	ldr r1, _0801B05C @ =0x03000094
	movs r0, #0
	str r0, [r1]
	add sp, #4
	pop {r1}
	bx r1
	.align 2, 0
_0801B05C: .4byte 0x03000094

	thumb_func_start FUN_0801b060
FUN_0801b060: @ 0x0801B060
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _0801B0D8 @ =0x03000094
	str r5, [r0]
	movs r0, #0
	strh r0, [r5, #0x20]
	strh r0, [r5, #0x22]
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r5, #0x1a]
	movs r0, #0x72
	movs r1, #0xfa
	bl VM_GetKeywordValue
	lsls r1, r0, #4
	strh r1, [r5, #0x18]
	lsls r0, r0, #0x14
	ldr r1, _0801B0DC @ =0x0F9F0000
	cmp r0, r1
	ble _0801B092
	movs r0, #0xfa
	lsls r0, r0, #4
	strh r0, [r5, #0x18]
_0801B092:
	movs r0, #0x73
	movs r1, #8
	bl VM_GetKeywordValue
	lsls r0, r0, #4
	strh r0, [r5, #0x1c]
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r5, #0x1e]
	ldr r0, _0801B0E0 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0801B174
	movs r1, #0xbd
	lsls r1, r1, #2
	adds r6, r5, r1
	adds r7, r0, #0
	adds r7, #0x2c
	ldrh r0, [r0, #0x2c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0801B0E4
	asrs r0, r0, #8
	b _0801B0EA
	.align 2, 0
_0801B0D8: .4byte 0x03000094
_0801B0DC: .4byte 0x0F9F0000
_0801B0E0: .4byte 0x03002BE0
_0801B0E4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801B0EA:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0801B0FC
	asrs r0, r0, #8
	b _0801B102
_0801B0FC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801B102:
	adds r4, r0, #0
	movs r2, #2
	ldrsh r1, [r7, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0801B116
	asrs r0, r0, #8
	b _0801B11C
_0801B116:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801B11C:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0801B14C @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _0801B150
	movs r0, #0
	b _0801B156
	.align 2, 0
_0801B14C: .4byte 0x030047C8
_0801B150:
	cmp r0, #0xf0
	ble _0801B158
	movs r0, #0xf0
_0801B156:
	strh r0, [r1]
_0801B158:
	ldr r0, _0801B168 @ =0x000002F6
	adds r1, r5, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _0801B16C
	movs r0, #0
	b _0801B184
	.align 2, 0
_0801B168: .4byte 0x000002F6
_0801B16C:
	cmp r0, #0xb4
	ble _0801B186
	movs r0, #0xb4
	b _0801B184
_0801B174:
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0x78
	strh r0, [r1]
	ldr r2, _0801B19C @ =0x000002F6
	adds r1, r5, r2
	movs r0, #0x5a
_0801B184:
	strh r0, [r1]
_0801B186:
	movs r4, #0
_0801B188:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0801ad78
	adds r4, #1
	cmp r4, #1
	ble _0801B188
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801B19C: .4byte 0x000002F6

	thumb_func_start FUN_0801b1a0
FUN_0801b1a0: @ 0x0801B1A0
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x61
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r0, #0
	ldr r0, _0801B1C4 @ =0x03000094
	ldr r0, [r0]
	cmp r0, #0
	bne _0801B206
	cmp r1, #0
	beq _0801B1C8
	movs r1, #0xc0
	lsls r1, r1, #2
	movs r0, #0xb
	b _0801B1CE
	.align 2, 0
_0801B1C4: .4byte 0x03000094
_0801B1C8:
	movs r1, #0xc0
	lsls r1, r1, #2
	movs r0, #9
_0801B1CE:
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801B204
	ldr r1, _0801B1FC @ =FUN_0801ae8c
	ldr r2, _0801B200 @ =FUN_0801b034
	adds r0, r4, #0
	bl SetEntityRoutine
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0801b060
	cmp r0, #0
	bge _0801B204
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801B206
	.align 2, 0
_0801B1FC: .4byte FUN_0801ae8c
_0801B200: .4byte FUN_0801b034
_0801B204:
	adds r0, r4, #0
_0801B206:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start EntityA687_Update
EntityA687_Update: @ 0x0801B20C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x28]
	cmp r0, #1
	beq _0801B234
	cmp r0, #1
	blo _0801B220
	cmp r0, #2
	beq _0801B24A
	b _0801B268
_0801B220:
	ldr r2, [r4, #0x24]
	ldr r1, [r4, #0x1c]
	cmp r2, r1
	bls _0801B22E
	subs r0, r2, #2
	str r0, [r4, #0x24]
	b _0801B268
_0801B22E:
	str r1, [r4, #0x24]
	adds r0, #1
	b _0801B242
_0801B234:
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
	ldr r1, [r4, #0x20]
	cmp r0, r1
	blo _0801B268
	movs r0, #2
_0801B242:
	str r0, [r4, #0x28]
	movs r0, #0
	str r0, [r4, #0x18]
	b _0801B268
_0801B24A:
	ldr r0, [r4, #0x24]
	cmp r0, #0x3f
	bhi _0801B256
	adds r0, #2
	str r0, [r4, #0x24]
	b _0801B268
_0801B256:
	movs r0, #0x40
	str r0, [r4, #0x24]
	movs r0, #3
	str r0, [r4, #0x28]
	movs r0, #0
	str r0, [r4, #0x18]
	adds r0, r4, #0
	bl KillEntity
_0801B268:
	ldr r0, _0801B294 @ =0x03004460
	ldr r3, [r4, #0x24]
	str r3, [r0]
	ldr r1, _0801B298 @ =0x03004454
	ldr r2, _0801B29C @ =0x00001FFF
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _0801B2A0 @ =0x03004494
	ldr r1, _0801B2A4 @ =0x00001084
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, _0801B2A8 @ =0x0300445C
	str r3, [r0]
	ldr r1, _0801B2AC @ =0x03004490
	movs r0, #0x20
	strh r0, [r1]
	ldr r0, _0801B2B0 @ =0x03004464
	strh r2, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801B294: .4byte 0x03004460
_0801B298: .4byte 0x03004454
_0801B29C: .4byte 0x00001FFF
_0801B2A0: .4byte 0x03004494
_0801B2A4: .4byte 0x00001084
_0801B2A8: .4byte 0x0300445C
_0801B2AC: .4byte 0x03004490
_0801B2B0: .4byte 0x03004464

	thumb_func_start EntityA687_Destroy
EntityA687_Destroy: @ 0x0801B2B4
	ldr r0, _0801B2DC @ =0x03004460
	movs r3, #0x40
	str r3, [r0]
	ldr r1, _0801B2E0 @ =0x03004454
	ldr r2, _0801B2E4 @ =0x00001FFF
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _0801B2E8 @ =0x03004494
	ldr r1, _0801B2EC @ =0x00001084
	adds r2, r1, #0
	strh r2, [r0]
	ldr r0, _0801B2F0 @ =0x0300445C
	str r3, [r0]
	ldr r1, _0801B2F4 @ =0x03004490
	movs r0, #0
	strh r0, [r1]
	ldr r0, _0801B2F8 @ =0x03004464
	strh r2, [r0]
	movs r0, #0
	bx lr
	.align 2, 0
_0801B2DC: .4byte 0x03004460
_0801B2E0: .4byte 0x03004454
_0801B2E4: .4byte 0x00001FFF
_0801B2E8: .4byte 0x03004494
_0801B2EC: .4byte 0x00001084
_0801B2F0: .4byte 0x0300445C
_0801B2F4: .4byte 0x03004490
_0801B2F8: .4byte 0x03004464

	thumb_func_start EntityA687_Init
EntityA687_Init: @ 0x0801B2FC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x72
	movs r1, #0x20
	bl VM_GetKeywordValue
	str r0, [r4, #0x1c]
	movs r0, #0x65
	movs r1, #0x78
	bl VM_GetKeywordValue
	str r0, [r4, #0x20]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start EntityA687_Create
EntityA687_Create: @ 0x0801B31C
	push {r4, lr}
	movs r0, #9
	movs r1, #0x2c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801B350
	ldr r1, _0801B348 @ =EntityA687_Update
	ldr r2, _0801B34C @ =EntityA687_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityA687_Init
	cmp r0, #0
	bge _0801B350
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801B352
	.align 2, 0
_0801B348: .4byte EntityA687_Update
_0801B34C: .4byte EntityA687_Destroy
_0801B350:
	adds r0, r4, #0
_0801B352:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801b358
FUN_0801b358: @ 0x0801B358
	push {lr}
	sub sp, #0xc
	str r1, [sp]
	ldr r2, _0801B380 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r2
	movs r2, #1
	orrs r1, r2
	str r1, [sp, #4]
	add r1, sp, #4
	mov r2, sp
	str r2, [r1, #4]
	ldr r0, [r0, #0x28]
	cmp r0, #0
	beq _0801B37A
	bl Script_ExecById
_0801B37A:
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_0801B380: .4byte 0xFFFF0000

	thumb_func_start FUN_0801b384
FUN_0801b384: @ 0x0801B384
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	movs r5, #0
	strh r0, [r4, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3b
	ble _0801B39C
	strh r5, [r4, #0x1e]
	b _0801B4F0
_0801B39C:
	bl GetHour
	strh r0, [r4, #0x18]
	bl GetMinute
	strh r0, [r4, #0x1a]
	bl GetSecond
	strh r0, [r4, #0x1c]
	movs r1, #0x18
	ldrsh r0, [r4, r1]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r0
	lsls r1, r1, #4
	movs r3, #0x1a
	ldrsh r2, [r4, r3]
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r2, #0x1c
	ldrsh r0, [r4, r2]
	adds r1, r1, r0
	str r1, [r4, #0x20]
	ldr r0, _0801B408 @ =0x0000A8DE
	ldr r3, _0801B40C @ =0xFFFF5722
	adds r2, r1, r3
	cmp r1, r0
	bge _0801B3DC
	subs r2, r0, r1
_0801B3DC:
	ldr r0, _0801B410 @ =0x0000A8BF
	cmp r2, r0
	ble _0801B3E6
	ldr r0, _0801B414 @ =0xFFFEAE80
	adds r2, r2, r0
_0801B3E6:
	adds r0, r2, #0
	cmp r0, #0
	bge _0801B3EE
	rsbs r0, r0, #0
_0801B3EE:
	cmp r0, #0x1e
	bgt _0801B418
	adds r1, r4, #0
	adds r1, #0x2c
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801B420
	strb r5, [r1]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0801b358
	b _0801B420
	.align 2, 0
_0801B408: .4byte 0x0000A8DE
_0801B40C: .4byte 0xFFFF5722
_0801B410: .4byte 0x0000A8BF
_0801B414: .4byte 0xFFFEAE80
_0801B418:
	adds r1, r4, #0
	adds r1, #0x2c
	movs r0, #1
	strb r0, [r1]
_0801B420:
	ldr r2, _0801B474 @ =0x030047E0
	ldrb r0, [r2, #0xa]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r0
	lsls r1, r1, #4
	ldrb r2, [r2, #0xb]
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r3, [r4, #0x24]
	ldr r0, [r4, #0x20]
	subs r2, r0, r1
	cmp r0, r1
	bge _0801B444
	subs r2, r1, r0
_0801B444:
	ldr r0, _0801B478 @ =0x0000A8BF
	cmp r2, r0
	ble _0801B44E
	ldr r1, _0801B47C @ =0xFFFEAE80
	adds r2, r2, r1
_0801B44E:
	adds r0, r2, #0
	cmp r0, #0
	bge _0801B456
	rsbs r0, r0, #0
_0801B456:
	cmp r0, r3
	bgt _0801B480
	adds r1, r4, #0
	adds r1, #0x2d
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801B488
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0801b358
	b _0801B488
	.align 2, 0
_0801B474: .4byte 0x030047E0
_0801B478: .4byte 0x0000A8BF
_0801B47C: .4byte 0xFFFEAE80
_0801B480:
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #1
	strb r0, [r1]
_0801B488:
	ldr r2, _0801B4DC @ =0x030047E0
	ldrb r0, [r2, #0xc]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r0
	lsls r1, r1, #4
	ldrb r2, [r2, #0xd]
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r3, [r4, #0x24]
	ldr r0, [r4, #0x20]
	subs r2, r0, r1
	cmp r0, r1
	bge _0801B4AC
	subs r2, r1, r0
_0801B4AC:
	ldr r0, _0801B4E0 @ =0x0000A8BF
	cmp r2, r0
	ble _0801B4B6
	ldr r0, _0801B4E4 @ =0xFFFEAE80
	adds r2, r2, r0
_0801B4B6:
	adds r0, r2, #0
	cmp r0, #0
	bge _0801B4BE
	rsbs r0, r0, #0
_0801B4BE:
	cmp r0, r3
	bgt _0801B4E8
	adds r1, r4, #0
	adds r1, #0x2e
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801B4F0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #2
	bl FUN_0801b358
	b _0801B4F0
	.align 2, 0
_0801B4DC: .4byte 0x030047E0
_0801B4E0: .4byte 0x0000A8BF
_0801B4E4: .4byte 0xFFFEAE80
_0801B4E8:
	adds r1, r4, #0
	adds r1, #0x2e
	movs r0, #1
	strb r0, [r1]
_0801B4F0:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
_0801B4F8:
	.byte 0x00, 0x20, 0x70, 0x47

	thumb_func_start FUN_0801b4fc
FUN_0801b4fc: @ 0x0801B4FC
	push {r4, lr}
	adds r4, r0, #0
	bl GetHour
	strh r0, [r4, #0x18]
	bl GetMinute
	strh r0, [r4, #0x1a]
	bl GetSecond
	strh r0, [r4, #0x1c]
	movs r1, #0x18
	ldrsh r0, [r4, r1]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, r1, r0
	lsls r1, r1, #4
	movs r0, #0x1a
	ldrsh r2, [r4, r0]
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r2, #0x1c
	ldrsh r0, [r4, r2]
	adds r1, r1, r0
	str r1, [r4, #0x20]
	movs r0, #0x64
	movs r1, #0x3c
	bl VM_GetKeywordValue
	str r0, [r4, #0x24]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r4, #0x28]
	movs r2, #1
	movs r1, #3
	adds r0, r4, #0
	adds r0, #0x2f
_0801B550:
	strb r2, [r0]
	subs r0, #1
	subs r1, #1
	cmp r1, #0
	bge _0801B550
	movs r0, #0
	strh r0, [r4, #0x1e]
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start EntityACE3_Create
EntityACE3_Create: @ 0x0801B564
	push {r4, lr}
	movs r0, #8
	movs r1, #0x30
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801B598
	ldr r1, _0801B590 @ =FUN_0801b384
	ldr r2, _0801B594 @ =0x0801B4F9
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0801b4fc
	cmp r0, #0
	bge _0801B598
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801B59A
	.align 2, 0
_0801B590: .4byte FUN_0801b384
_0801B594: .4byte 0x0801B4F9
_0801B598:
	adds r0, r4, #0
_0801B59A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801b5a0
FUN_0801b5a0: @ 0x0801B5A0
	push {lr}
	adds r1, r0, #0
	ldr r0, _0801B5B4 @ =0x03004250
	adds r1, #0x20
	ldr r2, _0801B5B8 @ =0x04000080
	bl CpuSet
	pop {r0}
	bx r0
	.align 2, 0
_0801B5B4: .4byte 0x03004250
_0801B5B8: .4byte 0x04000080

	thumb_func_start FUN_0801b5bc
FUN_0801b5bc: @ 0x0801B5BC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0800271c
	cmp r0, #0
	beq _0801B5CE
	adds r0, r4, #0
	bl FUN_0801b5a0
_0801B5CE:
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
	cmp r0, #3
	ble _0801B606
	movs r1, #0
	str r1, [r4, #0x18]
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	cmp r0, #6
	ble _0801B5E8
	str r1, [r4, #0x1c]
_0801B5E8:
	movs r1, #0
	adds r3, r4, #0
	adds r3, #0x20
	ldr r2, _0801B610 @ =0x03004250
_0801B5F0:
	ldr r0, [r4, #0x1c]
	lsls r0, r0, #4
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, r3, r0
	ldrh r0, [r0]
	strh r0, [r2]
	adds r2, #2
	adds r1, #1
	cmp r1, #0xf
	ble _0801B5F0
_0801B606:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801B610: .4byte 0x03004250
_0801B614:
	.byte 0x00, 0x20, 0x70, 0x47

	thumb_func_start FUN_0801b618
FUN_0801b618: @ 0x0801B618
	push {lr}
	bl FUN_0801b5a0
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start EntityD9D3_Create
EntityD9D3_Create: @ 0x0801B624
	push {r4, lr}
	movs r1, #0x88
	lsls r1, r1, #2
	movs r0, #0xc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801B65C
	ldr r1, _0801B654 @ =FUN_0801b5bc
	ldr r2, _0801B658 @ =0x0801B615
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0801b618
	cmp r0, #0
	bge _0801B65C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801B65E
	.align 2, 0
_0801B654: .4byte FUN_0801b5bc
_0801B658: .4byte 0x0801B615
_0801B65C:
	adds r0, r4, #0
_0801B65E:
	pop {r4}
	pop {r1}
	bx r1
