	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a7b68
FUN_080a7b68: @ 0x080A7B68
	movs r3, #0x82
	lsls r3, r3, #2
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080A7B7C @ =0x00000206
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080A7B7C: .4byte 0x00000206

	thumb_func_start FUN_080a7b80
FUN_080a7b80: @ 0x080A7B80
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	movs r0, #0
	str r0, [sp]
_080A7B92:
	movs r0, #0x2c
	ldr r2, [sp]
	adds r1, r2, #0
	muls r1, r0, r1
	mov sl, r1
	mov r7, sb
	add r7, sl
	adds r3, r7, #0
	adds r3, #0xc8
	ldrb r0, [r3]
	cmp r0, #0
	beq _080A7C48
	movs r0, #0xc9
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0]
	adds r0, #1
	movs r4, #0
	mov r1, r8
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls _080A7BD4
	mov r0, sb
	adds r0, #0xa0
	add r0, sl
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	strb r4, [r3]
	b _080A7C48
_080A7BD4:
	mov r2, r8
	ldrb r0, [r2]
	movs r4, #8
	subs r4, r4, r0
	adds r6, r4, #1
	adds r5, r7, #0
	adds r5, #0xb8
	movs r1, #0
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	mov r1, sb
	adds r1, #0x88
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r5]
	adds r5, #2
	movs r1, #0
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	mov r1, sb
	adds r1, #0x8a
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r5]
	adds r5, #2
	movs r1, #0
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	mov r1, sb
	adds r1, #0x8c
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r5]
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #4
	bne _080A7C48
	mov r0, sl
	adds r0, #0xa0
	add r0, sb
	mov r1, sb
	adds r1, #0x9c
	ldr r1, [r1]
	movs r2, #9
	bl FUN_0822dafc
_080A7C48:
	ldr r2, [sp]
	adds r2, #1
	str r2, [sp]
	cmp r2, #7
	ble _080A7B92
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a7c64
FUN_080a7c64: @ 0x080A7C64
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _080A7D68 @ =0x00000201
	adds r0, r0, r6
	mov sb, r0
	ldrb r0, [r0]
	adds r0, #1
	mov r1, sb
	strb r0, [r1]
	movs r3, #0xff
	mov r2, sp
	strb r3, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080A7D58
	movs r0, #0x80
	lsls r0, r0, #2
	adds r7, r6, r0
	ldrb r0, [r7]
	movs r4, #0x2c
	muls r0, r4, r0
	adds r1, r6, #0
	adds r1, #0xa0
	adds r1, r1, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldrb r0, [r7]
	muls r0, r4, r0
	adds r2, r6, #0
	adds r2, #0xb8
	adds r2, r2, r0
	adds r0, r6, #0
	adds r0, #0x88
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _080A7D6C @ =0x0203B400
	mov ip, r1
	ldr r2, _080A7D70 @ =0x030046B8
	mov r8, r2
	ldr r2, [r2]
	adds r2, #1
	ldr r5, _080A7D74 @ =0x000003FF
	ands r2, r5
	lsls r3, r2, #1
	add r3, ip
	ldrb r0, [r7]
	adds r1, r0, #0
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xb8
	ldrh r0, [r1]
	subs r0, #0x7f
	ldrb r3, [r3]
	adds r0, r0, r3
	movs r3, #0
	mov sl, r3
	strh r0, [r1]
	adds r2, #1
	ands r2, r5
	lsls r3, r2, #1
	add r3, ip
	ldrb r0, [r7]
	adds r1, r0, #0
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xba
	ldrh r0, [r1]
	subs r0, #0x7f
	ldrb r3, [r3]
	adds r0, r0, r3
	strh r0, [r1]
	adds r2, #1
	ands r2, r5
	mov r0, r8
	str r2, [r0]
	lsls r2, r2, #1
	add r2, ip
	ldrb r0, [r7]
	adds r1, r0, #0
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xbc
	ldrh r0, [r1]
	subs r0, #0x7f
	ldrb r2, [r2]
	adds r0, r0, r2
	strh r0, [r1]
	ldrb r0, [r7]
	muls r0, r4, r0
	adds r0, r6, r0
	adds r0, #0xc8
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r7]
	muls r0, r4, r0
	adds r0, r6, r0
	adds r0, #0xc9
	mov r1, sl
	strb r1, [r0]
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	mov r2, sp
	ldrb r2, [r2]
	ands r0, r2
	cmp r0, #7
	bls _080A7D52
	strb r1, [r7]
_080A7D52:
	mov r0, sl
	mov r3, sb
	strb r0, [r3]
_080A7D58:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A7D68: .4byte 0x00000201
_080A7D6C: .4byte 0x0203B400
_080A7D70: .4byte 0x030046B8
_080A7D74: .4byte 0x000003FF

	thumb_func_start FUN_080a7d78
FUN_080a7d78: @ 0x080A7D78
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080a7b80
	adds r0, r4, #0
	bl FUN_080a7c64
	ldr r0, _080A7DB8 @ =0x00000206
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080A7DB0
	ldr r0, [r4, #0x70]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x70]
	ldr r0, _080A7DBC @ =0x00000133
	bl PlaySound_082406e0
	ldr r1, _080A7DC0 @ =FUN_080a7dc4
	adds r0, r4, #0
	bl FUN_080a7b68
_080A7DB0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A7DB8: .4byte 0x00000206
_080A7DBC: .4byte 0x00000133
_080A7DC0: .4byte FUN_080a7dc4

	thumb_func_start FUN_080a7dc4
FUN_080a7dc4: @ 0x080A7DC4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	bl FUN_080a7b80
	adds r0, r7, #0
	adds r0, #0x20
	bl FUN_08236400
	ldr r0, _080A7E28 @ =0x00000206
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _080A7DF2
	b _080A7F2A
_080A7DF2:
	adds r0, r7, #0
	adds r0, #0x8a
	movs r1, #0
	ldrsh r6, [r0, r1]
	adds r5, r7, #0
	adds r5, #0x18
	ldrh r0, [r7, #0x18]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A7E22
	cmp r1, #0
	blt _080A7E22
	ldr r0, _080A7E2C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A7E22
	ldr r0, _080A7E30 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A7E34
_080A7E22:
	movs r4, #0
	b _080A7E42
	.align 2, 0
_080A7E28: .4byte 0x00000206
_080A7E2C: .4byte 0x030046A8
_080A7E30: .4byte 0x030046AC
_080A7E34:
	ldr r0, _080A7E54 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A7E42:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080A7E58
	adds r0, #4
	b _080A7E64
	.align 2, 0
_080A7E54: .4byte 0x030046A4
_080A7E58:
	ldr r0, _080A7E78 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A7E64:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A7E7C
	cmp r2, #2
	beq _080A7E80
	b _080A7E84
	.align 2, 0
_080A7E78: .4byte 0x030046A4
_080A7E7C:
	ldrb r0, [r5, #4]
	b _080A7E82
_080A7E80:
	ldrb r0, [r5]
_080A7E82:
	subs r1, r1, r0
_080A7E84:
	cmp r6, r1
	bls _080A7F24
	ldr r6, _080A7F3C @ =0x0203B400
	ldr r0, _080A7F40 @ =0x030046B8
	mov sl, r0
	ldr r2, [r0]
	adds r2, #1
	ldr r4, _080A7F44 @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0xf
	mov sb, r1
	mov r1, sb
	ands r0, r1
	subs r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _080A7F48 @ =0xFFFF0000
	ldr r3, [sp, #0xc]
	ands r3, r5
	orrs r3, r0
	str r3, [sp, #0xc]
	adds r2, #1
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	subs r1, #0x10
	lsls r1, r1, #0x10
	ldr r0, _080A7F4C @ =0x0000FFFF
	mov r8, r0
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0xc]
	adds r2, #1
	ands r2, r4
	mov r1, sl
	str r2, [r1]
	lsls r2, r2, #1
	adds r2, r2, r6
	ldrh r0, [r2]
	mov r1, sb
	ands r0, r1
	subs r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r5
	orrs r1, r0
	str r1, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r5
	movs r2, #5
	orrs r0, r2
	mov r1, r8
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r5
	orrs r0, r2
	str r0, [r1, #4]
	adds r2, r7, #0
	adds r2, #0x88
	str r1, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #4
	movs r1, #2
	add r3, sp, #0xc
	bl FUN_08014730
_080A7F24:
	adds r0, r7, #0
	bl KillEntity
_080A7F2A:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A7F3C: .4byte 0x0203B400
_080A7F40: .4byte 0x030046B8
_080A7F44: .4byte 0x000003FF
_080A7F48: .4byte 0xFFFF0000
_080A7F4C: .4byte 0x0000FFFF

	thumb_func_start FreezeEffect_Update
FreezeEffect_Update: @ 0x080A7F50
	push {lr}
	movs r2, #0x82
	lsls r2, r2, #2
	adds r1, r0, r2
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FreezeEffect_Destroy
FreezeEffect_Destroy: @ 0x080A7F64
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x70
	bl FUN_0822dabc
	adds r4, #0xa0
	movs r5, #7
_080A7F72:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x2c
	subs r5, #1
	cmp r5, #0
	bge _080A7F72
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a7f88
FUN_080a7f88: @ 0x080A7F88
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #0x1c
	adds r6, r0, #0
	mov sb, r2
	mov sl, r3
	movs r0, #0x20
	adds r0, r0, r6
	mov r8, r0
	ldr r4, _080A8024 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r4
	movs r3, #0x64
	orrs r0, r3
	ldr r2, _080A8028 @ =0x0000FFFF
	ands r0, r2
	movs r2, #0xc8
	lsls r2, r2, #0xf
	orrs r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r4
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r5, #0
	str r5, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r4
	str r0, [r3, #4]
	movs r2, #0x84
	lsls r2, r2, #6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp]
	add r1, sp, #0xc
	str r1, [sp, #4]
	str r3, [sp, #8]
	mov r0, r8
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r3, #0x80
	lsls r3, r3, #7
	str r5, [sp]
	str r5, [sp, #4]
	mov r0, r8
	mov r1, sb
	movs r2, #0
	bl FUN_082364f8
	adds r0, r6, #0
	adds r0, #0x62
	mov r1, sl
	strb r1, [r0]
	mov r0, r8
	movs r1, #0
	adds r2, r6, #0
	bl FUN_0823651c
	adds r6, #0x88
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A8024: .4byte 0xFFFF0000
_080A8028: .4byte 0x0000FFFF

	thumb_func_start FUN_080a802c
FUN_080a802c: @ 0x080A802C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x70
	ldr r0, _080A807C @ =0x00001C1A
	bl GetParticleGroup
	adds r1, r0, #0
	adds r5, r6, #0
	adds r5, #0x98
	str r1, [r5]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	movs r2, #8
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r1, [r5]
	adds r0, r4, #0
	movs r2, #0xa
	bl FUN_0822dafc
	ldr r0, [r6, #0x18]
	ldr r1, [r6, #0x1c]
	str r0, [r4, #0x18]
	str r1, [r4, #0x1c]
	ldrh r0, [r4, #0x1a]
	adds r0, #0xd7
	strh r0, [r4, #0x1a]
	movs r0, #1
	strb r0, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A807C: .4byte 0x00001C1A

	thumb_func_start FUN_080a8080
FUN_080a8080: @ 0x080A8080
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	ldr r0, _080A8100 @ =0x00001C1E
	bl GetParticleGroup
	mov r1, r8
	adds r1, #0x9c
	str r0, [r1]
	movs r6, #0
	adds r7, r1, #0
	mov sl, r6
	movs r0, #4
	rsbs r0, r0, #0
	mov sb, r0
_080A80A4:
	movs r0, #0x2c
	adds r5, r6, #0
	muls r5, r0, r5
	adds r4, r5, #0
	adds r4, #0xa0
	add r4, r8
	ldr r1, [r7]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r4, #0
	mov r1, sb
	mov r2, sb
	bl FUN_0822dad4
	ldr r1, [r7]
	adds r0, r4, #0
	movs r2, #8
	bl FUN_0822dafc
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #2
	strb r0, [r4, #0xf]
	movs r0, #0xec
	strb r0, [r4, #0x10]
	add r5, r8
	adds r0, r5, #0
	adds r0, #0xc8
	mov r1, sl
	strb r1, [r0]
	adds r5, #0xc9
	strb r1, [r5]
	adds r6, #1
	cmp r6, #7
	ble _080A80A4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A8100: .4byte 0x00001C1E

	thumb_func_start FreezeEffect_Init
FreezeEffect_Init: @ 0x080A8104
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r7, [sp, #0x14]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r4, #0x18]
	str r1, [r4, #0x1c]
	adds r0, r4, #0
	bl FUN_080a802c
	adds r0, r4, #0
	bl FUN_080a8080
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl FUN_080a7f88
	ldr r0, _080A815C @ =0x00000202
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0x81
	lsls r1, r1, #2
	adds r0, r4, r1
	mov r2, sp
	ldrh r2, [r2, #0x18]
	strh r2, [r0]
	movs r0, #0xe6
	lsls r0, r0, #2
	bl PlaySound_082406e0
	ldr r1, _080A8160 @ =FUN_080a7d78
	adds r0, r4, #0
	bl FUN_080a7b68
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A815C: .4byte 0x00000202
_080A8160: .4byte FUN_080a7d78

	thumb_func_start FreezeEffect_Create
FreezeEffect_Create: @ 0x080A8164
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r1, #0x83
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A81B4
	ldr r1, _080A81AC @ =FreezeEffect_Update
	ldr r2, _080A81B0 @ =FreezeEffect_Destroy
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FreezeEffect_Init
	cmp r0, #0
	bge _080A81B4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A81B6
	.align 2, 0
_080A81AC: .4byte FreezeEffect_Update
_080A81B0: .4byte FreezeEffect_Destroy
_080A81B4:
	adds r0, r4, #0
_080A81B6:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
