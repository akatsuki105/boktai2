	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081dd9b8
FUN_081dd9b8: @ 0x081DD9B8
	push {r4, lr}
	movs r3, #0
	strb r1, [r0, #0x1c]
	movs r4, #0xb5
	lsls r4, r4, #2
	adds r1, r0, r4
	str r2, [r1]
	str r3, [r0, #0x34]
	adds r0, #0x22
	movs r1, #1
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dd9d4
FUN_081dd9d4: @ 0x081DD9D4
	push {lr}
	adds r1, r0, #0
	adds r1, #0x22
	ldrb r0, [r1]
	cmp r0, #0
	bne _081DD9E4
	movs r0, #0
	b _081DD9EA
_081DD9E4:
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
_081DD9EA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081dd9f0
FUN_081dd9f0: @ 0x081DD9F0
	push {lr}
	adds r2, r0, #0
	adds r2, #0x7e
	movs r1, #0
	strh r1, [r2]
	movs r2, #0
	movs r1, #3
	adds r0, #0x86
_081DDA00:
	strh r2, [r0]
	subs r0, #2
	subs r1, #1
	cmp r1, #0
	bge _081DDA00
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081dda10
FUN_081dda10: @ 0x081DDA10
	push {lr}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x50
	ldrb r3, [r2]
	cmp r3, #0
	bne _081DDA2A
	movs r0, #1
	strb r0, [r2]
	adds r0, r1, #0
	adds r0, #0x51
	strb r3, [r0]
	b _081DDA34
_081DDA2A:
	movs r0, #0
	strb r0, [r2]
	adds r1, #0x51
	movs r0, #1
	strb r0, [r1]
_081DDA34:
	pop {r0}
	bx r0

	thumb_func_start FUN_081dda38
FUN_081dda38: @ 0x081DDA38
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x64
	movs r0, #0
	strh r0, [r1]
	movs r6, #0
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bge _081DDA8C
	adds r7, r1, #0
_081DDA4E:
	ldr r0, _081DDA5C @ =0x03002C68
	ldr r1, [r0]
	cmp r1, #0
	bne _081DDA60
	movs r0, #0
	b _081DDA70
	.align 2, 0
_081DDA5C: .4byte 0x03002C68
_081DDA60:
	adds r0, r1, #0
	adds r0, #0x51
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r6, r0
	adds r1, #0x58
	adds r1, r1, r0
	ldrb r0, [r1]
_081DDA70:
	adds r4, r0, #0
	bl GetSunLevel
	adds r1, r5, #0
	adds r1, #0x60
	adds r1, r1, r6
	strb r0, [r1]
	ldrh r0, [r7]
	adds r4, r4, r0
	strh r4, [r7]
	adds r6, #1
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	blt _081DDA4E
_081DDA8C:
	ldrh r1, [r5, #0x1a]
	cmp r1, #0
	bne _081DDA9A
	adds r0, r5, #0
	adds r0, #0x66
	strh r1, [r0]
	b _081DDAAC
_081DDA9A:
	adds r0, r5, #0
	adds r0, #0x64
	ldrh r0, [r0]
	ldrh r1, [r5, #0x1a]
	bl Div
	adds r1, r5, #0
	adds r1, #0x66
	strh r0, [r1]
_081DDAAC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081ddab4
FUN_081ddab4: @ 0x081DDAB4
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldr r1, [r3, #0x4c]
	cmp r1, #0
	blt _081DDB06
	movs r2, #0x18
	ldrsh r0, [r3, r2]
	cmp r1, r0
	bne _081DDB06
	ldrb r0, [r3, #0x1f]
	cmp r0, #0xe
	bhi _081DDB06
	movs r4, #0
	movs r2, #0
	ldrh r5, [r3, #0x1a]
	ldr r6, _081DDADC @ =0x0000FFFF
_081DDAD4:
	cmp r2, #0
	bge _081DDAE0
	ldr r0, _081DDADC @ =0x0000FFFF
	b _081DDAE8
	.align 2, 0
_081DDADC: .4byte 0x0000FFFF
_081DDAE0:
	ldr r1, [r3, #0x44]
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r0, [r0]
_081DDAE8:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r6
	beq _081DDAF2
	adds r4, #1
_081DDAF2:
	adds r2, #1
	cmp r2, #3
	ble _081DDAD4
	cmp r4, r5
	bne _081DDB00
	movs r0, #1
	b _081DDB02
_081DDB00:
	movs r0, #0
_081DDB02:
	cmp r0, #0
	bne _081DDB0C
_081DDB06:
	movs r0, #1
	rsbs r0, r0, #0
	b _081DDB0E
_081DDB0C:
	movs r0, #0
_081DDB0E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ddb14
FUN_081ddb14: @ 0x081DDB14
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x7e
	adds r0, r0, r4
	mov ip, r0
	ldrh r3, [r0]
	cmp r3, r2
	bge _081DDB54
	ldr r0, [r4, #0x48]
	cmp r0, #0
	blt _081DDB50
	adds r0, r1, r3
	ldrb r1, [r0]
	movs r0, #3
	ands r3, r0
	lsls r0, r3, #8
	orrs r1, r0
	movs r0, #0x80
	lsls r0, r0, #4
	orrs r1, r0
	adds r0, r4, #0
	adds r0, #0x42
	strh r1, [r0]
	mov r1, ip
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, r2
	bge _081DDB54
_081DDB50:
	movs r0, #0
	b _081DDB56
_081DDB54:
	movs r0, #1
_081DDB56:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ddb5c
FUN_081ddb5c: @ 0x081DDB5C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r7, r3, #0
	lsls r2, r5, #1
	adds r0, #0x80
	adds r0, r0, r2
	ldrh r1, [r0]
	cmp r1, r7
	bge _081DDBCE
	adds r4, r4, r1
	mov ip, r4
	cmp r5, #0
	bge _081DDB84
	ldr r0, _081DDB80 @ =0x0000FFFF
	b _081DDB8A
	.align 2, 0
_081DDB80: .4byte 0x0000FFFF
_081DDB84:
	ldr r0, [r6, #0x44]
	adds r0, r2, r0
	ldrh r0, [r0]
_081DDB8A:
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0xf0
	lsls r0, r0, #6
	ands r0, r4
	movs r1, #0x80
	lsls r1, r1, #4
	cmp r0, r1
	bne _081DDBA0
	movs r0, #1
	b _081DDBA2
_081DDBA0:
	movs r0, #0
_081DDBA2:
	cmp r0, #0
	beq _081DDBD2
	movs r1, #0xc0
	lsls r1, r1, #2
	ands r1, r4
	lsls r2, r5, #1
	adds r0, r6, #0
	adds r0, #0x80
	adds r2, r0, r2
	ldrh r3, [r2]
	movs r0, #3
	lsrs r1, r1, #8
	ands r0, r3
	cmp r1, r0
	bne _081DDBD2
	mov r0, ip
	strb r4, [r0]
	adds r0, r3, #1
	strh r0, [r2]
	ldrh r0, [r2]
	cmp r0, r7
	blt _081DDBD2
_081DDBCE:
	movs r0, #1
	b _081DDBD4
_081DDBD2:
	movs r0, #0
_081DDBD4:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081ddbdc
FUN_081ddbdc: @ 0x081DDBDC
	push {lr}
	movs r1, #0
	strh r1, [r0, #0x1a]
	ldrb r2, [r0, #0x1c]
	adds r1, r0, #0
	adds r1, #0x20
	strb r2, [r1]
	ldr r2, _081DDC00 @ =FUN_081de130
	movs r1, #0
	bl FUN_081dd9b8
	bl FUN_080a5e4c
	bl FUN_08238bf4
	pop {r0}
	bx r0
	.align 2, 0
_081DDC00: .4byte FUN_081de130

	thumb_func_start FUN_081ddc04
FUN_081ddc04: @ 0x081DDC04
	push {lr}
	adds r2, r0, #0
	movs r1, #0
	ldrh r0, [r2, #0x1a]
	cmp r1, r0
	bge _081DDC22
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r3, r2, r0
_081DDC16:
	adds r0, r3, r1
	strb r1, [r0]
	adds r1, #1
	ldrh r0, [r2, #0x1a]
	cmp r1, r0
	blt _081DDC16
_081DDC22:
	cmp r1, #4
	bgt _081DDC38
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r2, r2, r0
	movs r3, #4
_081DDC2E:
	adds r0, r2, r1
	strb r3, [r0]
	adds r1, #1
	cmp r1, #4
	ble _081DDC2E
_081DDC38:
	pop {r0}
	bx r0

	thumb_func_start FUN_081ddc3c
FUN_081ddc3c: @ 0x081DDC3C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r7, #0
	ldrh r0, [r6, #0x1a]
	cmp r7, r0
	bge _081DDCC6
	movs r1, #0
	mov sb, r1
	ldr r2, _081DDCB8 @ =0x270F0000
	mov r8, r2
_081DDC56:
	adds r0, r7, #0
	bl FUN_081df720
	lsls r5, r7, #1
	movs r2, #0x98
	lsls r2, r2, #1
	adds r1, r6, r2
	adds r4, r1, r5
	lsls r0, r0, #4
	subs r2, #0x10
	adds r1, r6, r2
	adds r1, r1, r5
	ldrh r2, [r1]
	lsls r1, r2, #3
	adds r1, r1, r2
	adds r0, r0, r1
	movs r2, #0x94
	lsls r2, r2, #1
	adds r1, r6, r2
	adds r1, r1, r5
	ldrh r1, [r1]
	lsls r1, r1, #2
	subs r0, r0, r1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _081DDC90
	mov r0, sb
	strh r0, [r4]
_081DDC90:
	movs r1, #0
	ldrsh r0, [r4, r1]
	mov r2, r8
	asrs r3, r2, #0x10
	cmp r0, r3
	ble _081DDC9E
	strh r3, [r4]
_081DDC9E:
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r2, r0, r5
	movs r5, #0
	ldrsh r1, [r2, r5]
	movs r5, #0
	ldrsh r0, [r4, r5]
	adds r1, r1, r0
	cmp r1, r3
	ble _081DDCBC
	strh r3, [r2]
	b _081DDCBE
	.align 2, 0
_081DDCB8: .4byte 0x270F0000
_081DDCBC:
	strh r1, [r2]
_081DDCBE:
	adds r7, #1
	ldrh r0, [r6, #0x1a]
	cmp r7, r0
	blt _081DDC56
_081DDCC6:
	cmp r7, #3
	bgt _081DDCEC
	ldr r1, _081DDCF8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r7, #1
	movs r5, #0x98
	lsls r5, r5, #1
	adds r0, r0, r5
	adds r1, r0, r6
_081DDCD8:
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	ldrh r0, [r1, #8]
	orrs r0, r2
	strh r0, [r1, #8]
	adds r1, #2
	adds r7, #1
	cmp r7, #3
	ble _081DDCD8
_081DDCEC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DDCF8: .4byte 0x0000FFFF

	thumb_func_start FUN_081ddcfc
FUN_081ddcfc: @ 0x081DDCFC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	mov sb, r0
	movs r0, #0
	mov r8, r0
	mov r1, sb
	ldrh r0, [r1, #0x1a]
	add r2, sp, #0x20
	mov sl, r2
	cmp r8, r0
	bge _081DDD3A
	adds r3, r0, #0
	movs r2, #0x98
	lsls r2, r2, #1
	add r2, sb
	mov r1, sp
_081DDD24:
	mov r4, r8
	str r4, [r1]
	movs r4, #0
	ldrsh r0, [r2, r4]
	str r0, [r1, #0x10]
	adds r2, #2
	adds r1, #4
	movs r0, #1
	add r8, r0
	cmp r8, r3
	blt _081DDD24
_081DDD3A:
	mov r1, sb
	ldrh r1, [r1, #0x1a]
	mov ip, r1
	mov r2, r8
	cmp r2, #3
	bgt _081DDD5E
	movs r1, #1
	rsbs r1, r1, #0
	lsls r0, r2, #2
	add r0, sp
_081DDD4E:
	str r1, [r0]
	str r1, [r0, #0x10]
	adds r0, #4
	movs r4, #1
	add r8, r4
	mov r2, r8
	cmp r2, #3
	ble _081DDD4E
_081DDD5E:
	movs r4, #0
	mov r8, r4
_081DDD62:
	movs r0, #3
	cmp r0, r8
	ble _081DDD94
	add r7, sp, #0x10
_081DDD6A:
	subs r6, r0, #1
	lsls r5, r6, #2
	adds r3, r7, r5
	lsls r4, r0, #2
	adds r2, r7, r4
	ldr r0, [r3]
	ldr r1, [r2]
	cmp r0, r1
	bge _081DDD8E
	str r0, [r2]
	str r1, [r3]
	mov r0, sp
	adds r2, r0, r4
	ldr r3, [r2]
	adds r1, r0, r5
	ldr r0, [r1]
	str r0, [r2]
	str r3, [r1]
_081DDD8E:
	adds r0, r6, #0
	cmp r0, r8
	bgt _081DDD6A
_081DDD94:
	movs r1, #1
	add r8, r1
	mov r2, r8
	cmp r2, #2
	ble _081DDD62
	mov r1, sl
	movs r2, #0
	mov r0, sl
	adds r0, #0xc
_081DDDA6:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge _081DDDA6
	movs r3, #0
	movs r0, #1
	str r0, [sp, #0x20]
	str r3, [sp, #0x30]
	mov r8, r0
	cmp r8, ip
	bge _081DDDE4
	mov r6, sl
	add r2, sp, #0x10
	mov r4, ip
	add r5, sp, #0x34
_081DDDC4:
	ldr r1, [r2, #4]
	ldr r0, [r2]
	cmp r1, r0
	bge _081DDDCE
	mov r3, r8
_081DDDCE:
	stm r5!, {r3}
	lsls r1, r3, #2
	adds r1, r6, r1
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	adds r2, #4
	movs r0, #1
	add r8, r0
	cmp r8, r4
	blt _081DDDC4
_081DDDE4:
	movs r1, #0
	mov r8, r1
	mov r2, ip
	cmp r8, r2
	bge _081DDE86
	movs r4, #0xa0
	lsls r4, r4, #1
	add r4, sb
	str r4, [sp, #0x40]
	mov r6, sp
_081DDDF8:
	mov r0, r8
	lsls r1, r0, #2
	ldr r7, [r6]
	add r0, sp, #0x30
	adds r0, r0, r1
	ldr r5, [r0]
	lsls r1, r5, #1
	movs r0, #0xaa
	lsls r0, r0, #1
	add r0, sb
	adds r0, r0, r1
	movs r1, #0
	ldrsh r4, [r0, r1]
	ldr r1, _081DDE34 @ =0x085AE3D4
	lsls r0, r2, #2
	adds r0, r5, r0
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldr r2, [sp, #0x40]
	ldr r0, [r2]
	muls r0, r1, r0
	movs r1, #0x14
	bl Div
	cmp r0, #0
	blt _081DDE38
	asrs r0, r0, #6
	b _081DDE3E
	.align 2, 0
_081DDE34: .4byte 0x085AE3D4
_081DDE38:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081DDE3E:
	cmp r0, #0
	ble _081DDE4A
	cmp r0, #0x3c
	ble _081DDE54
	movs r0, #0x3c
	b _081DDE54
_081DDE4A:
	movs r1, #0x3c
	rsbs r1, r1, #0
	cmp r0, r1
	bge _081DDE54
	adds r0, r1, #0
_081DDE54:
	adds r4, r4, r0
	lsls r0, r5, #2
	add r0, sl
	ldr r1, [r0]
	cmp r1, #1
	ble _081DDE68
	adds r0, r4, #0
	bl Div
	adds r4, r0, #0
_081DDE68:
	lsls r0, r7, #2
	movs r1, #0xa2
	lsls r1, r1, #1
	add r1, sb
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, r0, r4
	str r0, [r1]
	adds r6, #4
	movs r4, #1
	add r8, r4
	mov r0, sb
	ldrh r2, [r0, #0x1a]
	cmp r8, r2
	blt _081DDDF8
_081DDE86:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081dde98
FUN_081dde98: @ 0x081DDE98
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	movs r4, #0
	ldrh r0, [r0, #0x1a]
	cmp r4, r0
	bge _081DDECE
	mov r3, ip
	adds r3, #0x88
	movs r2, #0xd2
	lsls r2, r2, #1
	add r2, ip
_081DDEAE:
	adds r1, r3, #0
	adds r0, r2, #0
	adds r0, #0x1c
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	adds r3, #0x24
	adds r2, #0x48
	adds r4, #1
	mov r0, ip
	ldrh r0, [r0, #0x1a]
	cmp r4, r0
	blt _081DDEAE
_081DDECE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dded4
FUN_081dded4: @ 0x081DDED4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x30]
	movs r1, #0
	strh r0, [r4, #0x32]
	str r1, [r4, #0x34]
	adds r0, r4, #0
	bl FUN_081ddc04
	movs r3, #0
	movs r2, #0
	movs r1, #0x90
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, _081DDF38 @ =0x000003FF
	ldr r1, _081DDF3C @ =0x03004510
_081DDEF4:
	strh r2, [r0]
	strh r2, [r0, #8]
	strh r2, [r0, #0x10]
	strh r5, [r1]
	adds r0, #2
	adds r1, #2
	adds r3, #1
	cmp r3, #3
	ble _081DDEF4
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
	adds r1, r4, #0
	adds r1, #0x52
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_081dde98
	ldr r2, _081DDF40 @ =0x030046B8
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r0, _081DDF38 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DDF38: .4byte 0x000003FF
_081DDF3C: .4byte 0x03004510
_081DDF40: .4byte 0x030046B8

	thumb_func_start FUN_081ddf44
FUN_081ddf44: @ 0x081DDF44
	push {lr}
	sub sp, #0x14
	adds r1, r0, #0
	movs r0, #0xb7
	lsls r0, r0, #2
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _081DDF7A
	ldrh r0, [r1, #0x1a]
	str r0, [sp]
	ldrh r0, [r1, #0x38]
	str r0, [sp, #4]
	ldrh r0, [r1, #0x3a]
	str r0, [sp, #8]
	ldr r1, _081DDF80 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	str r0, [sp, #0xc]
	add r1, sp, #0xc
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_081DDF7A:
	add sp, #0x14
	pop {r0}
	bx r0
	.align 2, 0
_081DDF80: .4byte 0xFFFF0000

	thumb_func_start FUN_081ddf84
FUN_081ddf84: @ 0x081DDF84
	push {r4, r5, r6, lr}
	movs r3, #0
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r5, r0, r1
	movs r6, #0
	ldr r4, _081DDFAC @ =0x085AE3E8
_081DDF92:
	adds r2, r5, r3
	ldrb r1, [r2]
	ldr r0, [r4]
	cmp r1, r0
	blt _081DDF9E
	strb r6, [r2]
_081DDF9E:
	adds r4, #4
	adds r3, #1
	cmp r3, #2
	ble _081DDF92
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DDFAC: .4byte 0x085AE3E8

	thumb_func_start FUN_081ddfb0
FUN_081ddfb0: @ 0x081DDFB0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	ldr r2, _081DDFE0 @ =0x0000FFFF
	movs r1, #0
	cmp r1, r4
	bhs _081DDFF4
	movs r6, #0x80
	lsls r6, r6, #8
	ldr r5, _081DDFE4 @ =0x00001021
_081DDFC4:
	adds r0, r7, r1
	ldrb r0, [r0]
	lsls r0, r0, #8
	eors r2, r0
	movs r3, #0
	adds r1, #1
_081DDFD0:
	adds r0, r2, #0
	ands r0, r6
	cmp r0, #0
	beq _081DDFE8
	lsls r2, r2, #1
	eors r2, r5
	b _081DDFEA
	.align 2, 0
_081DDFE0: .4byte 0x0000FFFF
_081DDFE4: .4byte 0x00001021
_081DDFE8:
	lsls r2, r2, #1
_081DDFEA:
	adds r3, #1
	cmp r3, #7
	bls _081DDFD0
	cmp r1, r4
	blo _081DDFC4
_081DDFF4:
	ldr r0, _081DE000 @ =0x0000FFFF
	bics r0, r2
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081DE000: .4byte 0x0000FFFF

	thumb_func_start FUN_081de004
FUN_081de004: @ 0x081DE004
	push {lr}
	movs r1, #0
	ldrh r2, [r0, #0x1a]
	cmp r1, r2
	bge _081DE024
	adds r3, r0, #0
	adds r3, #0x78
_081DE012:
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081DE01E
	movs r0, #1
	b _081DE026
_081DE01E:
	adds r1, #1
	cmp r1, r2
	blt _081DE012
_081DE024:
	movs r0, #0
_081DE026:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081de02c
FUN_081de02c: @ 0x081DE02C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xae
	lsls r0, r0, #1
	adds r3, r5, r0
	ldr r1, _081DE068 @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0xf0
	lsls r2, r2, #2
	adds r4, r0, r2
	movs r2, #0
	adds r6, r1, #0
_081DE044:
	adds r0, r3, r2
	adds r1, r4, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #0xf
	ble _081DE044
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	bne _081DE070
	ldr r2, _081DE06C @ =0x030047E0
	ldrb r1, [r2, #6]
	lsls r0, r1, #4
	subs r0, r0, r1
	ldrb r2, [r2, #7]
	adds r0, r0, r2
	b _081DE072
	.align 2, 0
_081DE068: .4byte 0x030046A0
_081DE06C: .4byte 0x030047E0
_081DE070:
	movs r0, #0
_081DE072:
	strh r0, [r3, #0x10]
	movs r0, #0x64
	strh r0, [r3, #0x12]
	ldr r0, [r6]
	ldrh r1, [r0, #0x10]
	strh r1, [r3, #0x14]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r3, #0x18]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081de090
FUN_081de090: @ 0x081DE090
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081de02c
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _081DE0D4 @ =0x000002C5
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	movs r1, #0xce
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #4
	bl ClearMemory
	ldr r2, _081DE0D8 @ =0x00000173
	adds r1, r4, r2
	movs r0, #0xff
	strb r0, [r1]
	bl FUN_0823e1b0
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r4, r4, r1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DE0D4: .4byte 0x000002C5
_081DE0D8: .4byte 0x00000173

	thumb_func_start FUN_081de0dc
FUN_081de0dc: @ 0x081DE0DC
	push {r4, lr}
	mov ip, r0
	movs r1, #4
	movs r3, #4
	movs r0, #0x8e
	lsls r0, r0, #1
	add r0, ip
_081DE0EA:
	strb r1, [r0]
	subs r0, #1
	subs r3, #1
	cmp r3, #0
	bge _081DE0EA
	movs r3, #0
	movs r2, #0
	movs r0, #0x90
	lsls r0, r0, #1
	add r0, ip
	movs r4, #0xa2
	lsls r4, r4, #1
	add r4, ip
	movs r1, #0x9c
	lsls r1, r1, #1
	add r1, ip
_081DE10A:
	strh r2, [r0]
	strh r2, [r0, #8]
	strh r2, [r0, #0x10]
	strh r2, [r1]
	stm r4!, {r2}
	adds r0, #2
	adds r1, #2
	adds r3, #1
	cmp r3, #3
	ble _081DE10A
	movs r1, #0xa0
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081de130
FUN_081de130: @ 0x081DE130
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DE182
	ldr r0, _081DE1F4 @ =0x030044D0
	movs r3, #0
	str r3, [r0]
	movs r2, #4
	ldr r1, _081DE1F8 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r5, #0
	adds r0, #0x55
	strb r3, [r0]
	adds r1, r5, #0
	adds r1, #0x42
	movs r0, #0x80
	lsls r0, r0, #7
	strh r0, [r1]
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #6
	bl FUN_0804a084
	movs r2, #0xb6
	lsls r2, r2, #2
	adds r1, r5, r2
	str r0, [r1]
	movs r0, #1
	bl Sound_FadeOutBGM
	bl FUN_08049fa8
	movs r0, #0
	bl ClearBGTilemapBuffer
_081DE182:
	adds r4, r5, #0
	adds r4, #0x55
	ldrb r0, [r4]
	cmp r0, #0
	bne _081DE1D2
	bl FUN_0804771c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DE1D2
	movs r0, #1
	strb r0, [r4]
	movs r0, #5
	bl FUN_0809c08c
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r4, r5, r0
	ldr r0, [r4]
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #2
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldr r2, _081DE1FC @ =0x03003E78
	ldr r0, _081DE200 @ =0xFFFFF1FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	bl FUN_0822b41c
_081DE1D2:
	ldr r1, _081DE204 @ =nop_0822e738
	ldr r2, _081DE208 @ =nop_0822b09c
	ldr r3, _081DE20C @ =FUN_0822f584
	movs r0, #0
	bl FUN_0822a448
	ldr r0, [r5, #0x34]
	cmp r0, #0x1d
	bhi _081DE1EA
	ldr r1, _081DE210 @ =0x030047B8
	movs r0, #1
	str r0, [r1]
_081DE1EA:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081DE1F4: .4byte 0x030044D0
_081DE1F8: .4byte 0x030044BC
_081DE1FC: .4byte 0x03003E78
_081DE200: .4byte 0xFFFFF1FF
_081DE204: .4byte nop_0822e738
_081DE208: .4byte nop_0822b09c
_081DE20C: .4byte FUN_0822f584
_081DE210: .4byte 0x030047B8

	thumb_func_start FUN_081de214
FUN_081de214: @ 0x081DE214
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	cmp r1, #0
	beq _081DE22C
	adds r2, r4, #0
	adds r2, #0x23
	movs r1, #0
	strb r1, [r2]
_081DE22C:
	adds r5, r4, #0
	adds r5, #0x23
	ldrb r1, [r5]
	cmp r1, #3
	bne _081DE244
	ldr r2, _081DE24C @ =FUN_081de250
	adds r0, r4, #0
	movs r1, #2
	bl FUN_081dd9b8
	movs r0, #0
	strb r0, [r5]
_081DE244:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081DE24C: .4byte FUN_081de250

	thumb_func_start FUN_081de250
FUN_081de250: @ 0x081DE250
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	cmp r1, #0
	beq _081DE280
	bl FUN_08238c24
	movs r3, #0
	adds r5, r4, #0
	adds r5, #0x68
	movs r6, #1
_081DE26C:
	adds r2, r5, r3
	ldrb r1, [r2]
	cmp r1, #0
	beq _081DE276
	strb r6, [r2]
_081DE276:
	adds r3, #1
	cmp r3, #3
	ble _081DE26C
	movs r1, #0
	strh r1, [r4, #0x2e]
_081DE280:
	ldr r1, [r4, #0x34]
	cmp r1, #2
	bls _081DE2D2
	bl FUN_08238bc0
	adds r1, r0, #0
	cmp r1, #0
	blt _081DE2A4
	strb r1, [r4, #0x1d]
	ldr r2, _081DE2A0 @ =FUN_081de2dc
	adds r0, r4, #0
	movs r1, #3
	bl FUN_081dd9b8
	movs r0, #0
	b _081DE2D2
	.align 2, 0
_081DE2A0: .4byte FUN_081de2dc
_081DE2A4:
	ldrh r1, [r4, #0x2e]
	adds r1, #1
	strh r1, [r4, #0x2e]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x1d
	bls _081DE2D2
	ldr r2, _081DE2D8 @ =FUN_081de250
	adds r0, r4, #0
	movs r1, #2
	bl FUN_081dd9b8
	bl FUN_08238bf4
	adds r2, r4, #0
	adds r2, #0x68
	movs r3, #0
	adds r1, r4, #0
	adds r1, #0x6b
_081DE2CA:
	strb r3, [r1]
	subs r1, #1
	cmp r1, r2
	bge _081DE2CA
_081DE2D2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081DE2D8: .4byte FUN_081de250

	thumb_func_start FUN_081de2dc
FUN_081de2dc: @ 0x081DE2DC
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DE2F0
	movs r0, #0
	strh r0, [r4, #0x2e]
_081DE2F0:
	mov r0, sp
	bl FUN_08238e48
	adds r1, r0, #0
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	blt _081DE324
	cmp r1, #0
	blt _081DE324
	lsls r0, r0, #1
	add r0, sp
	ldrh r1, [r0]
	ldr r0, _081DE31C @ =0x0000FFFF
	cmp r1, r0
	beq _081DE324
	ldr r2, _081DE320 @ =FUN_081de360
	adds r0, r4, #0
	movs r1, #4
	bl FUN_081dd9b8
	b _081DE352
	.align 2, 0
_081DE31C: .4byte 0x0000FFFF
_081DE320: .4byte FUN_081de360
_081DE324:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _081DE352
	ldr r2, _081DE35C @ =FUN_081de250
	adds r0, r4, #0
	movs r1, #2
	bl FUN_081dd9b8
	bl FUN_08238bf4
	adds r1, r4, #0
	adds r1, #0x68
	movs r2, #0
	adds r0, r4, #0
	adds r0, #0x6b
_081DE34A:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _081DE34A
_081DE352:
	movs r0, #0
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DE35C: .4byte FUN_081de250

	thumb_func_start FUN_081de360
FUN_081de360: @ 0x081DE360
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r4, r0, #0
	mov r0, sp
	bl FUN_08238e48
	adds r0, r4, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DE3B2
	movs r2, #0
	movs r0, #0
	strh r0, [r4, #0x2e]
	adds r0, r4, #0
	adds r0, #0x28
	strb r2, [r0]
	adds r1, r4, #0
	adds r1, #0x2d
	movs r0, #0x28
	strb r0, [r1]
	ldr r0, _081DE3D8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE3A0
	adds r0, #0x2c
	strb r2, [r0]
_081DE3A0:
	adds r1, r4, #0
	adds r1, #0x74
	movs r2, #0
	adds r0, r4, #0
	adds r0, #0x77
_081DE3AA:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _081DE3AA
_081DE3B2:
	ldr r1, [r4, #0x4c]
	cmp r1, #0
	bge _081DE46C
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _081DE3E0
_081DE3C6:
	ldr r2, _081DE3DC @ =FUN_081de250
	adds r0, r4, #0
	movs r1, #2
	bl FUN_081dd9b8
	bl FUN_08238bf4
	b _081DE6D4
	.align 2, 0
_081DE3D8: .4byte 0x03002C68
_081DE3DC: .4byte FUN_081de250
_081DE3E0:
	movs r0, #3
	rsbs r0, r0, #0
	cmp r1, r0
	beq _081DE444
	adds r5, r4, #0
	adds r5, #0x78
	adds r6, r4, #0
	adds r6, #0x23
	adds r1, r4, #0
	adds r1, #0x74
	movs r2, #0
	adds r0, r4, #0
	adds r0, #0x77
_081DE3FA:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _081DE3FA
	movs r3, #0
	ldr r0, _081DE42C @ =0x0000FFFF
	mov r8, r0
	movs r7, #0
	adds r2, r4, #0
	adds r2, #0x68
	adds r1, r5, #0
	mov r5, sp
_081DE412:
	ldrh r0, [r5]
	cmp r0, r8
	bne _081DE430
	ldrb r0, [r1]
	cmp r0, #0xfe
	bhi _081DE422
	adds r0, #1
	strb r0, [r1]
_081DE422:
	ldrb r0, [r1]
	cmp r0, #0x77
	bls _081DE436
	strb r7, [r2]
	b _081DE436
	.align 2, 0
_081DE42C: .4byte 0x0000FFFF
_081DE430:
	strb r7, [r1]
	movs r0, #1
	strb r0, [r2]
_081DE436:
	adds r2, #1
	adds r1, #1
	adds r5, #2
	adds r3, #1
	cmp r3, #3
	ble _081DE412
	b _081DE6C0
_081DE444:
	ldrb r0, [r4, #0x1d]
	adds r6, r4, #0
	adds r6, #0x23
	cmp r0, #0
	beq _081DE450
	b _081DE6C0
_081DE450:
	ldr r0, _081DE468 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _081DE45E
	b _081DE6C0
_081DE45E:
	adds r1, r4, #0
	adds r1, #0x28
	movs r0, #1
	strb r0, [r1]
	b _081DE6C0
	.align 2, 0
_081DE468: .4byte 0x030044E0
_081DE46C:
	movs r3, #0
	ldr r7, _081DE498 @ =0x0000FFFF
	movs r6, #0
	adds r2, r4, #0
	adds r2, #0x68
	adds r1, r4, #0
	adds r1, #0x78
	mov r5, sp
_081DE47C:
	ldrh r0, [r5]
	cmp r0, r7
	bne _081DE49C
	ldrb r0, [r1]
	cmp r0, #0xfe
	bhi _081DE48C
	adds r0, #1
	strb r0, [r1]
_081DE48C:
	ldrb r0, [r1]
	cmp r0, #0x77
	bls _081DE4A2
	strb r6, [r2]
	b _081DE4A2
	.align 2, 0
_081DE498: .4byte 0x0000FFFF
_081DE49C:
	strb r6, [r1]
	movs r0, #1
	strb r0, [r2]
_081DE4A2:
	adds r2, #1
	adds r1, #1
	adds r5, #2
	adds r3, #1
	cmp r3, #3
	ble _081DE47C
	movs r3, #0
	strh r3, [r4, #0x2e]
	ldr r1, [r4, #0x4c]
	lsls r0, r1, #1
	add r0, sp
	ldrh r0, [r0]
	ldr r2, _081DE4F4 @ =0x0000FFFF
	cmp r0, r2
	bne _081DE4C2
	b _081DE3C6
_081DE4C2:
	strh r1, [r4, #0x18]
	strh r3, [r4, #0x1a]
	movs r1, #0
	mov sb, r1
	movs r7, #1
	mov r8, r1
	movs r3, #0
	adds r0, r4, #0
	adds r0, #0x2d
	str r0, [sp, #8]
	adds r1, r4, #0
	adds r1, #0x74
	str r1, [sp, #0x10]
	adds r0, #0x3b
	str r0, [sp, #0xc]
	mov sl, r2
	movs r1, #0xf0
	lsls r1, r1, #6
	mov ip, r1
	adds r6, r0, #0
	ldr r5, [sp, #0x10]
_081DE4EC:
	cmp r3, #0
	bge _081DE4F8
	ldr r0, _081DE4F4 @ =0x0000FFFF
	b _081DE500
	.align 2, 0
_081DE4F4: .4byte 0x0000FFFF
_081DE4F8:
	ldr r1, [r4, #0x44]
	lsls r0, r3, #1
	adds r0, r0, r1
	ldrh r0, [r0]
_081DE500:
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, sl
	beq _081DE570
	adds r0, r2, #0
	mov r1, ip
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #3
	cmp r0, r1
	bne _081DE51A
	movs r0, #1
	b _081DE51C
_081DE51A:
	movs r0, #0
_081DE51C:
	cmp r0, #0
	beq _081DE528
	movs r0, #0xff
	ands r0, r2
	cmp r0, #0x3e
	beq _081DE540
_081DE528:
	adds r0, r2, #0
	mov r1, ip
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #5
	cmp r0, r1
	bne _081DE53A
	movs r0, #1
	b _081DE53C
_081DE53A:
	movs r0, #0
_081DE53C:
	cmp r0, #0
	beq _081DE56C
_081DE540:
	movs r0, #1
	add sb, r0
	ldrb r0, [r5]
	cmp r0, #0xfe
	bhi _081DE54E
	adds r0, #1
	strb r0, [r5]
_081DE54E:
	ldrb r0, [r5]
	cmp r0, #0x59
	bls _081DE564
	movs r0, #2
	strb r0, [r6]
	cmp r7, #0
	beq _081DE58C
	ldrh r0, [r4, #0x1a]
	adds r0, #1
	strh r0, [r4, #0x1a]
	b _081DE58C
_081DE564:
	movs r7, #0
	movs r0, #1
	strb r0, [r6]
	b _081DE58C
_081DE56C:
	cmp r2, sl
	bne _081DE574
_081DE570:
	movs r0, #0
	b _081DE57A
_081DE574:
	movs r1, #1
	mov r8, r1
	mov r0, r8
_081DE57A:
	strb r0, [r6]
	movs r7, #0
	strb r7, [r5]
	ldr r0, _081DE5D8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE58C
	adds r0, #0x2c
	strb r7, [r0]
_081DE58C:
	adds r6, #1
	adds r5, #1
	adds r3, #1
	cmp r3, #3
	ble _081DE4EC
	mov r1, r8
	cmp r1, #0
	beq _081DE5C2
	movs r3, #0
	ldr r0, _081DE5DC @ =0x0000FFFF
	mov ip, r0
	mov r1, sp
	ldr r5, [sp, #0xc]
	movs r7, #1
	ldr r2, [sp, #0x10]
	movs r6, #0
_081DE5AC:
	ldrh r0, [r1]
	cmp r0, ip
	beq _081DE5B6
	adds r0, r5, r3
	strb r7, [r0]
_081DE5B6:
	adds r0, r2, r3
	strb r6, [r0]
	adds r1, #2
	adds r3, #1
	cmp r3, #3
	ble _081DE5AC
_081DE5C2:
	ldr r0, [r4, #0x44]
	ldrh r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #6
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #5
	cmp r0, r1
	bne _081DE5E0
	movs r0, #1
	b _081DE5E2
	.align 2, 0
_081DE5D8: .4byte 0x03002C68
_081DE5DC: .4byte 0x0000FFFF
_081DE5E0:
	movs r0, #0
_081DE5E2:
	cmp r0, #0
	beq _081DE654
	ldr r0, _081DE624 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE5F6
	adds r1, r0, #0
	adds r1, #0x2c
	movs r0, #1
	strb r0, [r1]
_081DE5F6:
	ldr r1, [sp, #8]
	ldrb r0, [r1]
	cmp r0, #0
	beq _081DE628
	subs r0, #1
	strb r0, [r1]
	ldrh r0, [r4, #0x1a]
	cmp r0, #1
	bls _081DE6B4
	cmp r0, sb
	bne _081DE6B4
	mov r0, r8
	cmp r0, #0
	bne _081DE6B4
	ldrb r0, [r4, #0x1d]
	adds r6, r4, #0
	adds r6, #0x23
	cmp r0, #0
	bne _081DE6C0
	movs r0, #3
	ldr r1, [sp, #0xc]
	strb r0, [r1]
	b _081DE6C0
	.align 2, 0
_081DE624: .4byte 0x03002C68
_081DE628:
	ldrh r0, [r4, #0x1a]
	cmp r0, #1
	bls _081DE6B4
	cmp r0, sb
	bne _081DE6B4
	mov r0, r8
	cmp r0, #0
	bne _081DE6B4
	ldr r2, _081DE650 @ =FUN_081de6f0
	adds r0, r4, #0
	movs r1, #5
	bl FUN_081dd9b8
	adds r0, r4, #0
	bl FUN_081dd9f0
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _081DE6D4
	.align 2, 0
_081DE650: .4byte FUN_081de6f0
_081DE654:
	movs r0, #0x28
	ldr r1, [sp, #8]
	strb r0, [r1]
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	bne _081DE6B4
	ldrh r0, [r4, #0x1a]
	cmp r0, #1
	bls _081DE6B4
	cmp r0, sb
	bne _081DE6B4
	mov r0, r8
	cmp r0, #0
	bne _081DE6B4
	ldr r0, _081DE6AC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #8
	ands r0, r1
	adds r3, r4, #0
	adds r3, #0x28
	cmp r0, #0
	bne _081DE686
	ldrb r0, [r3]
	cmp r0, #0
	beq _081DE6A4
_081DE686:
	movs r1, #0xa0
	lsls r1, r1, #5
	adds r2, r4, #0
	adds r2, #0x42
	movs r0, #0
	strh r1, [r2]
	strb r0, [r3]
	ldr r0, _081DE6B0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE6A4
	adds r1, r0, #0
	adds r1, #0x2c
	movs r0, #1
	strb r0, [r1]
_081DE6A4:
	movs r0, #3
	ldr r1, [sp, #0xc]
	strb r0, [r1]
	b _081DE6BC
	.align 2, 0
_081DE6AC: .4byte 0x030044E0
_081DE6B0: .4byte 0x03002C68
_081DE6B4:
	ldr r0, _081DE6E8 @ =0x0000043E
	adds r1, r4, #0
	adds r1, #0x42
	strh r0, [r1]
_081DE6BC:
	adds r6, r4, #0
	adds r6, #0x23
_081DE6C0:
	ldrb r0, [r6]
	cmp r0, #2
	bne _081DE6D4
	bl FUN_08238c24
	ldr r2, _081DE6EC @ =FUN_081de214
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081dd9b8
_081DE6D4:
	movs r0, #0
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081DE6E8: .4byte 0x0000043E
_081DE6EC: .4byte FUN_081de214

	thumb_func_start FUN_081de6f0
FUN_081de6f0: @ 0x081DE6F0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DE724
	adds r0, r5, #0
	bl FUN_081dd9f0
	adds r0, r5, #0
	bl FUN_081de02c
	adds r0, r5, #0
	bl FUN_081ddc04
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0x46
	bl FUN_081ddfb0
	movs r2, #0xd1
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
_081DE724:
	adds r0, r5, #0
	bl FUN_081ddab4
	cmp r0, #0
	bge _081DE73A
	adds r0, r5, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DE7E2
_081DE73A:
	ldr r0, [r5, #0x44]
	ldrh r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #6
	ands r0, r1
	movs r1, #0xc0
	lsls r1, r1, #5
	cmp r0, r1
	bne _081DE750
	movs r0, #1
	b _081DE752
_081DE750:
	movs r0, #0
_081DE752:
	cmp r0, #0
	beq _081DE770
	adds r0, r5, #0
	bl FUN_081dde98
	ldr r2, _081DE76C @ =FUN_081de7e8
	adds r0, r5, #0
	movs r1, #6
	bl FUN_081dd9b8
	movs r0, #0
	b _081DE7E2
	.align 2, 0
_081DE76C: .4byte FUN_081de7e8
_081DE770:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r5, r0
	adds r0, r5, #0
	movs r2, #0x48
	bl FUN_081ddb14
	movs r7, #0
	movs r6, #0
	ldrh r1, [r5, #0x1a]
	cmp r7, r1
	bge _081DE7B8
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r4, r5, r2
_081DE78E:
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	movs r3, #0x48
	bl FUN_081ddb5c
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #1
	bne _081DE7AE
	adds r0, r4, #0
	movs r1, #0x46
	bl FUN_081ddfb0
	adds r7, #1
_081DE7AE:
	adds r4, #0x48
	adds r6, #1
	ldrh r1, [r5, #0x1a]
	cmp r6, r1
	blt _081DE78E
_081DE7B8:
	ldrh r2, [r5, #0x1a]
	cmp r7, r2
	bne _081DE7CE
	ldrb r1, [r5, #0x1d]
	cmp r1, #0
	bne _081DE7CE
	movs r1, #0xc0
	lsls r1, r1, #5
	adds r2, r5, #0
	adds r2, #0x42
	strh r1, [r2]
_081DE7CE:
	ldr r2, [r5, #0x34]
	movs r1, #0xe1
	lsls r1, r1, #4
	cmp r2, r1
	bls _081DE7E2
	adds r0, r5, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
_081DE7E2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081de7e8
FUN_081de7e8: @ 0x081DE7E8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081ddab4
	cmp r0, #0
	bge _081DE800
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DE838
_081DE800:
	ldr r0, [r4, #0x34]
	cmp r0, #0x78
	bls _081DE836
	ldr r0, _081DE824 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE82C
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081DE82C
	ldr r2, _081DE828 @ =FUN_081de844
	adds r0, r4, #0
	movs r1, #7
	bl FUN_081dd9b8
	b _081DE836
	.align 2, 0
_081DE824: .4byte 0x03002C68
_081DE828: .4byte FUN_081de844
_081DE82C:
	ldr r2, _081DE840 @ =FUN_081de960
	adds r0, r4, #0
	movs r1, #8
	bl FUN_081dd9b8
_081DE836:
	movs r0, #0
_081DE838:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DE840: .4byte FUN_081de960

	thumb_func_start FUN_081de844
FUN_081de844: @ 0x081DE844
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DE878
	bl FUN_081dc694
	ldr r1, _081DE890 @ =0x000002EA
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0
	bl Script_ExecById
	ldr r0, _081DE894 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE878
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081DE878
	movs r0, #0xa8
	bl sound_08240264
_081DE878:
	adds r0, r4, #0
	bl FUN_081ddab4
	cmp r0, #0
	bge _081DE898
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DE95A
	.align 2, 0
_081DE890: .4byte 0x000002EA
_081DE894: .4byte 0x03002C68
_081DE898:
	ldr r2, [r4, #0x44]
	ldrh r1, [r2]
	movs r0, #0xf0
	lsls r0, r0, #6
	ands r1, r0
	movs r0, #0xe0
	lsls r0, r0, #5
	cmp r1, r0
	bne _081DE8AE
	movs r0, #1
	b _081DE8B0
_081DE8AE:
	movs r0, #0
_081DE8B0:
	cmp r0, #0
	beq _081DE8C4
	ldr r2, _081DE8C0 @ =FUN_081de9d8
	adds r0, r4, #0
	movs r1, #9
	bl FUN_081dd9b8
	b _081DE958
	.align 2, 0
_081DE8C0: .4byte FUN_081de9d8
_081DE8C4:
	ldrh r0, [r2]
	movs r1, #0xf0
	lsls r1, r1, #6
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #3
	cmp r0, r1
	bne _081DE8D8
	movs r0, #1
	b _081DE8DA
_081DE8D8:
	movs r0, #0
_081DE8DA:
	cmp r0, #0
	beq _081DE908
	ldr r2, _081DE900 @ =FUN_081de360
	adds r0, r4, #0
	movs r1, #4
	bl FUN_081dd9b8
	ldr r0, _081DE904 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE958
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081DE958
	movs r0, #1
	bl Sound_FadeOutBGM
	b _081DE958
	.align 2, 0
_081DE900: .4byte FUN_081de360
_081DE904: .4byte 0x03002C68
_081DE908:
	ldr r0, _081DE934 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE958
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081DE958
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	beq _081DE958
	cmp r1, #1
	bne _081DE938
	movs r1, #0xe0
	lsls r1, r1, #5
	adds r0, #0x1f
	strh r1, [r0]
	b _081DE954
	.align 2, 0
_081DE934: .4byte 0x03002C68
_081DE938:
	cmp r1, #2
	bne _081DE954
	movs r0, #0x80
	lsls r0, r0, #3
	adds r1, r4, #0
	adds r1, #0x42
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0
	bl Script_ExecById
_081DE954:
	movs r0, #0
	strb r0, [r5]
_081DE958:
	movs r0, #0
_081DE95A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_081de960
FUN_081de960: @ 0x081DE960
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DE97A
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DE9CE
_081DE97A:
	ldr r3, [r4, #0x44]
	ldrh r2, [r3]
	movs r1, #0xf0
	lsls r1, r1, #6
	ands r2, r1
	movs r1, #0xe0
	lsls r1, r1, #5
	cmp r2, r1
	bne _081DE990
	movs r1, #1
	b _081DE992
_081DE990:
	movs r1, #0
_081DE992:
	cmp r1, #0
	beq _081DE9A8
	ldr r2, _081DE9A4 @ =FUN_081de9d8
	adds r0, r4, #0
	movs r1, #9
	bl FUN_081dd9b8
	movs r0, #0
	b _081DE9CE
	.align 2, 0
_081DE9A4: .4byte FUN_081de9d8
_081DE9A8:
	ldrh r1, [r3]
	movs r2, #0xf0
	lsls r2, r2, #6
	ands r1, r2
	movs r2, #0x80
	lsls r2, r2, #3
	cmp r1, r2
	bne _081DE9BC
	movs r1, #1
	b _081DE9BE
_081DE9BC:
	movs r1, #0
_081DE9BE:
	cmp r1, #0
	beq _081DE9CE
	ldr r2, _081DE9D4 @ =FUN_081de360
	adds r0, r4, #0
	movs r1, #4
	bl FUN_081dd9b8
	movs r0, #0
_081DE9CE:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DE9D4: .4byte FUN_081de360

	thumb_func_start FUN_081de9d8
FUN_081de9d8: @ 0x081DE9D8
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DEA0E
	adds r0, r4, #0
	bl FUN_081dd9f0
	ldr r0, _081DEA24 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DEA0E
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081DEA0E
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r1, #6
	bl FUN_081ddfb0
	ldr r3, _081DEA28 @ =0x000002CA
	adds r1, r4, r3
	strh r0, [r1]
_081DEA0E:
	adds r0, r4, #0
	bl FUN_081ddab4
	cmp r0, #0
	bge _081DEA2C
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DEAD2
	.align 2, 0
_081DEA24: .4byte 0x03002C68
_081DEA28: .4byte 0x000002CA
_081DEA2C:
	ldr r0, _081DEAD8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DEA4A
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081DEA4A
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r1, r4, r2
	adds r0, r4, #0
	movs r2, #8
	bl FUN_081ddb14
_081DEA4A:
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r5, r4, r3
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	movs r3, #8
	bl FUN_081ddb5c
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #1
	bne _081DEAD2
	adds r0, r5, #0
	movs r1, #6
	bl FUN_081ddfb0
	ldr r2, _081DEADC @ =FUN_081deaf4
	adds r0, r4, #0
	movs r1, #0xa
	bl FUN_081dd9b8
	bl FUN_08049fa8
	movs r0, #0
	bl ClearBGTilemapBuffer
	adds r0, r4, #0
	bl FUN_081ddf84
	ldr r2, _081DEAE0 @ =0x030046B8
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	ldr r5, _081DEAE4 @ =0x000003FF
	adds r1, r5, #0
	ands r1, r0
	str r1, [r2]
	ldr r3, _081DEAE8 @ =0x000002CE
	adds r0, r4, r3
	ldrb r0, [r0]
	strh r0, [r4, #0x38]
	cmp r0, #2
	bls _081DEABC
	adds r0, r1, #1
	ands r0, r5
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081DEAEC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	strh r0, [r4, #0x38]
_081DEABC:
	adds r0, r4, #0
	bl FUN_081ddf44
	ldr r1, _081DEAF0 @ =0x03004510
	adds r2, r5, #0
	adds r0, r1, #6
_081DEAC8:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _081DEAC8
	movs r0, #0
_081DEAD2:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081DEAD8: .4byte 0x03002C68
_081DEADC: .4byte FUN_081deaf4
_081DEAE0: .4byte 0x030046B8
_081DEAE4: .4byte 0x000003FF
_081DEAE8: .4byte 0x000002CE
_081DEAEC: .4byte 0x0203B400
_081DEAF0: .4byte 0x03004510

	thumb_func_start FUN_081deaf4
FUN_081deaf4: @ 0x081DEAF4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r1, _081DEB38 @ =0x030044D0
	movs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DEB10
	movs r0, #1
	bl Sound_FadeOutBGM
_081DEB10:
	ldr r0, [r4, #0x34]
	cmp r0, #1
	bne _081DEB20
	movs r2, #4
	ldr r1, _081DEB3C @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081DEB20:
	adds r0, r4, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DEB40
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DEBB4
	.align 2, 0
_081DEB38: .4byte 0x030044D0
_081DEB3C: .4byte 0x030044BC
_081DEB40:
	movs r6, #0
	movs r3, #0
	ldrh r5, [r4, #0x1a]
	cmp r6, r5
	bge _081DEB82
	movs r7, #0xf0
	lsls r7, r7, #6
_081DEB4E:
	cmp r3, #0
	bge _081DEB5C
	ldr r2, _081DEB58 @ =0x0000FFFF
	b _081DEB64
	.align 2, 0
_081DEB58: .4byte 0x0000FFFF
_081DEB5C:
	ldr r2, [r4, #0x44]
	lsls r1, r3, #1
	adds r1, r1, r2
	ldrh r2, [r1]
_081DEB64:
	adds r1, r7, #0
	ands r1, r2
	movs r2, #0x80
	lsls r2, r2, #6
	cmp r1, r2
	bne _081DEB74
	movs r1, #1
	b _081DEB76
_081DEB74:
	movs r1, #0
_081DEB76:
	cmp r1, #0
	beq _081DEB7C
	adds r6, #1
_081DEB7C:
	adds r3, #1
	cmp r3, r5
	blt _081DEB4E
_081DEB82:
	cmp r6, r5
	bne _081DEB98
	ldr r2, _081DEB94 @ =FUN_081debd4
	adds r0, r4, #0
	movs r1, #0xb
	bl FUN_081dd9b8
	movs r0, #0
	b _081DEBB4
	.align 2, 0
_081DEB94: .4byte FUN_081debd4
_081DEB98:
	ldr r1, [r4, #0x34]
	cmp r1, #9
	bls _081DEBB4
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r4, #0
	adds r1, #0x42
	strh r2, [r1]
	ldr r3, _081DEBBC @ =0x030044BC
	movs r2, #5
	rsbs r2, r2, #0
	ldr r1, [r3]
	ands r1, r2
	str r1, [r3]
_081DEBB4:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081DEBBC: .4byte 0x030044BC

	thumb_func_start FUN_081debc0
FUN_081debc0: @ 0x081DEBC0
	push {lr}
	ldr r2, _081DEBD0 @ =FUN_081dec1c
	movs r1, #0xc
	bl FUN_081dd9b8
	pop {r0}
	bx r0
	.align 2, 0
_081DEBD0: .4byte FUN_081dec1c

	thumb_func_start FUN_081debd4
FUN_081debd4: @ 0x081DEBD4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _081DEC14 @ =0x030044D0
	movs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DEBF6
	ldr r2, _081DEC18 @ =FUN_081debc0
	movs r0, #0
	movs r1, #0
	adds r3, r4, #0
	bl FUN_080a6180
_081DEBF6:
	adds r0, r4, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DEC0C
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
_081DEC0C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DEC14: .4byte 0x030044D0
_081DEC18: .4byte FUN_081debc0

	thumb_func_start FUN_081dec1c
FUN_081dec1c: @ 0x081DEC1C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	ldr r1, _081DEC68 @ =0x030044D0
	movs r0, #1
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DEC9C
	ldr r1, _081DEC6C @ =0x085AE3F4
	ldr r2, _081DEC70 @ =0x000002CD
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x32]
	ldr r0, _081DEC74 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x94
	lsls r3, r3, #4
	adds r0, r0, r3
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x54
	strb r1, [r0]
	subs r0, #0x22
	bl FUN_0809c544
	movs r6, #0
	ldr r5, _081DEC78 @ =0x03002BE0
	b _081DEC8A
	.align 2, 0
_081DEC68: .4byte 0x030044D0
_081DEC6C: .4byte 0x085AE3F4
_081DEC70: .4byte 0x000002CD
_081DEC74: .4byte 0x030046A0
_081DEC78: .4byte 0x03002BE0
_081DEC7C:
	ldr r0, [r5]
	cmp r0, #0
	beq _081DEC86
	bl FUN_0807d118
_081DEC86:
	adds r5, #4
	adds r6, #1
_081DEC8A:
	ldr r0, _081DECD4 @ =0x03002C68
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0
	beq _081DEC98
	ldrh r1, [r0, #0x1a]
_081DEC98:
	cmp r6, r1
	blt _081DEC7C
_081DEC9C:
	adds r0, r4, #0
	bl FUN_081ddab4
	cmp r0, #0
	bge _081DECA8
	b _081DEE98
_081DECA8:
	ldr r0, _081DECD8 @ =0x04000130
	ldrh r0, [r0]
	ldr r1, _081DECDC @ =0x0000FFF3
	mov r8, r1
	mov r2, r8
	ands r2, r0
	mov r8, r2
	movs r7, #0
	movs r5, #0
	ldrh r3, [r4, #0x1a]
	cmp r5, r3
	bge _081DED8E
	movs r0, #0xf0
	lsls r0, r0, #6
	mov ip, r0
	movs r6, #0
	ldr r1, _081DECE0 @ =0x000003FF
	mov sb, r1
_081DECCC:
	cmp r5, #0
	bge _081DECE8
	ldr r0, _081DECE4 @ =0x0000FFFF
	b _081DECEE
	.align 2, 0
_081DECD4: .4byte 0x03002C68
_081DECD8: .4byte 0x04000130
_081DECDC: .4byte 0x0000FFF3
_081DECE0: .4byte 0x000003FF
_081DECE4: .4byte 0x0000FFFF
_081DECE8:
	ldr r0, [r4, #0x44]
	adds r0, r6, r0
	ldrh r0, [r0]
_081DECEE:
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	adds r0, r3, #0
	mov r2, ip
	ands r0, r2
	movs r1, #0xc0
	lsls r1, r1, #4
	cmp r0, r1
	bne _081DED04
	movs r0, #1
	b _081DED06
_081DED04:
	movs r0, #0
_081DED06:
	cmp r0, #0
	beq _081DED54
	ldr r2, _081DED50 @ =0x03004510
	adds r2, r6, r2
	adds r0, r3, #0
	mov r1, sb
	ands r0, r1
	movs r1, #0xc
	orrs r0, r1
	strh r0, [r2]
	lsrs r2, r3, #2
	movs r0, #1
	ands r2, r0
	adds r0, r4, #0
	adds r0, #0x50
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r5, r0
	adds r1, r4, #0
	adds r1, #0x58
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x52
	ldrb r0, [r0]
	lsls r2, r0
	ldrb r0, [r1]
	orrs r2, r0
	strb r2, [r1]
	cmp r5, #0
	bne _081DED84
	movs r7, #1
	movs r0, #8
	ands r0, r3
	cmp r0, #0
	beq _081DED84
	movs r7, #3
	b _081DED84
	.align 2, 0
_081DED50: .4byte 0x03004510
_081DED54:
	ldr r0, _081DED78 @ =0x0000FFFF
	cmp r3, r0
	bne _081DED5C
	b _081DEE98
_081DED5C:
	movs r2, #0x18
	ldrsh r0, [r4, r2]
	cmp r5, r0
	bne _081DED84
	adds r0, r3, #0
	mov r3, ip
	ands r0, r3
	movs r1, #0xa0
	lsls r1, r1, #6
	cmp r0, r1
	bne _081DED7C
	movs r0, #1
	b _081DED7E
	.align 2, 0
_081DED78: .4byte 0x0000FFFF
_081DED7C:
	movs r0, #0
_081DED7E:
	cmp r0, #0
	beq _081DED84
	b _081DEEA4
_081DED84:
	adds r6, #2
	adds r5, #1
	ldrh r0, [r4, #0x1a]
	cmp r5, r0
	blt _081DECCC
_081DED8E:
	movs r0, #1
	ands r0, r7
	cmp r0, #0
	beq _081DEDA0
	adds r1, r4, #0
	adds r1, #0x52
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_081DEDA0:
	movs r0, #2
	ands r7, r0
	movs r1, #0x42
	adds r1, r1, r4
	mov sb, r1
	cmp r7, #0
	beq _081DEDF8
	adds r0, r4, #0
	bl FUN_081dda10
	adds r0, r4, #0
	bl FUN_081dda38
	adds r1, r4, #0
	adds r1, #0x52
	movs r0, #0
	strb r0, [r1]
	ldr r0, _081DEE54 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x94
	lsls r2, r2, #4
	adds r0, r0, r2
	ldrh r1, [r0]
	adds r0, r4, #0
	adds r0, #0x54
	strb r1, [r0]
	movs r5, #0
	ldrh r3, [r4, #0x1a]
	cmp r5, r3
	bge _081DEDF8
	adds r2, r4, #0
	adds r2, #0x50
	adds r1, r4, #0
	adds r1, #0x58
	movs r3, #0
_081DEDE6:
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r5, r0
	adds r0, r1, r0
	strb r3, [r0]
	adds r5, #1
	ldrh r0, [r4, #0x1a]
	cmp r5, r0
	blt _081DEDE6
_081DEDF8:
	movs r2, #0x32
	ldrsh r1, [r4, r2]
	movs r0, #0xe1
	lsls r0, r0, #3
	cmp r1, r0
	beq _081DEE0C
	movs r0, #0xe1
	lsls r0, r0, #2
	cmp r1, r0
	bne _081DEE34
_081DEE0C:
	movs r5, #0
	ldrh r3, [r4, #0x1a]
	cmp r5, r3
	bge _081DEE34
	ldr r6, _081DEE58 @ =0x03002BE0
_081DEE16:
	adds r0, r5, #0
	bl FUN_081df720
	cmp r0, #2
	ble _081DEE2A
	ldr r1, [r6]
	adds r1, #0x2c
	adds r0, r5, #0
	bl FUN_0801a108
_081DEE2A:
	adds r6, #4
	adds r5, #1
	ldrh r0, [r4, #0x1a]
	cmp r5, r0
	blt _081DEE16
_081DEE34:
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bgt _081DEE60
	bl FUN_0809c58c
	movs r0, #0xa0
	lsls r0, r0, #6
	mov r2, sb
	strh r0, [r2]
	ldr r2, _081DEE5C @ =FUN_081deef8
	adds r0, r4, #0
	movs r1, #0xd
	bl FUN_081dd9b8
	b _081DEEEA
	.align 2, 0
_081DEE54: .4byte 0x030046A0
_081DEE58: .4byte 0x03002BE0
_081DEE5C: .4byte FUN_081deef8
_081DEE60:
	ldr r0, _081DEE70 @ =0x03002C68
	ldr r2, [r0]
	adds r1, r0, #0
	cmp r2, #0
	bne _081DEE74
	adds r3, r4, #0
	adds r3, #0x53
	b _081DEE8E
	.align 2, 0
_081DEE70: .4byte 0x03002C68
_081DEE74:
	movs r3, #0x18
	ldrsh r0, [r2, r3]
	adds r3, r4, #0
	adds r3, #0x53
	cmp r0, #0
	bne _081DEE8E
	ldrb r0, [r3]
	cmp r0, #7
	bne _081DEE8E
	movs r0, #8
	mov r2, r8
	orrs r2, r0
	mov r8, r2
_081DEE8E:
	ldr r1, [r1]
	cmp r1, #0
	bne _081DEEB4
	movs r0, #0
	b _081DEEC4
_081DEE98:
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DEEEC
_081DEEA4:
	ldr r2, _081DEEB0 @ =FUN_081deef8
	adds r0, r4, #0
	movs r1, #0xd
	bl FUN_081dd9b8
	b _081DEEEA
	.align 2, 0
_081DEEB0: .4byte FUN_081deef8
_081DEEB4:
	adds r0, r1, #0
	adds r0, #0x54
	ldrb r0, [r0]
	adds r1, #0x53
	ldrb r1, [r1]
	asrs r0, r1
	movs r1, #1
	ands r0, r1
_081DEEC4:
	lsls r0, r0, #2
	mov r1, r8
	orrs r1, r0
	lsls r2, r1, #0x10
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	strb r0, [r3]
	movs r0, #0xc0
	lsls r0, r0, #0x14
	orrs r0, r2
	lsls r0, r0, #2
	lsrs r0, r0, #0x12
	mov r2, sb
	strh r0, [r2]
	ldrh r0, [r4, #0x32]
	subs r0, #1
	strh r0, [r4, #0x32]
_081DEEEA:
	movs r0, #0
_081DEEEC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081deef8
FUN_081deef8: @ 0x081DEEF8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DEF54
	bl Sound_StopAll
	movs r0, #1
	movs r1, #0
	movs r2, #0
	adds r3, r5, #0
	bl FUN_080a6180
	movs r2, #4
	ldr r1, _081DEF6C @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	bl FUN_08016f84
	ldr r1, _081DEF70 @ =0x030044D0
	movs r0, #0
	str r0, [r1]
	ldr r4, _081DEF74 @ =0x030046A0
	ldr r0, [r4]
	ldr r3, _081DEF78 @ =0x00000914
	adds r1, r0, r3
	ldrh r2, [r1]
	movs r6, #0
	ldrsh r0, [r1, r6]
	cmp r0, #0
	bge _081DEF3E
	movs r2, #0
_081DEF3E:
	strh r2, [r1]
	ldr r0, [r4]
	adds r1, r0, r3
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r0, #1
	ldr r2, _081DEF7C @ =0x0000270F
	cmp r0, r2
	ble _081DEF52
	adds r0, r2, #0
_081DEF52:
	strh r0, [r1]
_081DEF54:
	adds r0, r5, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DEF80
	adds r0, r5, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF00C
	.align 2, 0
_081DEF6C: .4byte 0x030044BC
_081DEF70: .4byte 0x030044D0
_081DEF74: .4byte 0x030046A0
_081DEF78: .4byte 0x00000914
_081DEF7C: .4byte 0x0000270F
_081DEF80:
	movs r7, #0
	movs r4, #0
	ldrh r6, [r5, #0x1a]
	cmp r7, r6
	bge _081DEFD0
	movs r1, #0xf0
	lsls r1, r1, #6
	mov ip, r1
_081DEF90:
	cmp r4, #0
	bge _081DEF9C
	ldr r1, _081DEF98 @ =0x0000FFFF
	b _081DEFA4
	.align 2, 0
_081DEF98: .4byte 0x0000FFFF
_081DEF9C:
	ldr r2, [r5, #0x44]
	lsls r1, r4, #1
	adds r1, r1, r2
	ldrh r1, [r1]
_081DEFA4:
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	adds r1, r3, #0
	mov r2, ip
	ands r1, r2
	movs r2, #0x80
	lsls r2, r2, #5
	cmp r1, r2
	bne _081DEFBA
	movs r1, #1
	b _081DEFBC
_081DEFBA:
	movs r1, #0
_081DEFBC:
	cmp r1, #0
	beq _081DEFCA
	movs r1, #0x3f
	ands r1, r3
	cmp r1, #0
	bne _081DEFCA
	adds r7, #1
_081DEFCA:
	adds r4, #1
	cmp r4, r6
	blt _081DEF90
_081DEFD0:
	cmp r7, r6
	bne _081DEFFC
	ldr r2, _081DEFF8 @ =FUN_081df014
	adds r0, r5, #0
	movs r1, #0xe
	bl FUN_081dd9b8
	adds r1, r5, #0
	adds r1, #0x21
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_081ddc3c
	adds r0, r5, #0
	bl FUN_081ddcfc
	movs r0, #0
	b _081DF00C
	.align 2, 0
_081DEFF8: .4byte FUN_081df014
_081DEFFC:
	ldr r1, [r5, #0x34]
	cmp r1, #0x59
	bls _081DF00C
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r5, #0
	adds r1, #0x42
	strh r2, [r1]
_081DF00C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081df014
FUN_081df014: @ 0x081DF014
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DF036
	ldr r1, _081DF04C @ =0x000002E2
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0
	bl Script_ExecById
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0xff
	strb r0, [r1]
_081DF036:
	adds r0, r4, #0
	bl FUN_081ddab4
	cmp r0, #0
	bge _081DF050
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF0F0
	.align 2, 0
_081DF04C: .4byte 0x000002E2
_081DF050:
	movs r5, #0
	movs r7, #0
	movs r3, #0
	ldrh r6, [r4, #0x1a]
	cmp r5, r6
	bge _081DF0A6
	movs r0, #0xf0
	lsls r0, r0, #6
	mov ip, r0
_081DF062:
	cmp r3, #0
	bge _081DF070
	ldr r0, _081DF06C @ =0x0000FFFF
	b _081DF078
	.align 2, 0
_081DF06C: .4byte 0x0000FFFF
_081DF070:
	ldr r1, [r4, #0x44]
	lsls r0, r3, #1
	adds r0, r0, r1
	ldrh r0, [r0]
_081DF078:
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r0, r2, #0
	mov r1, ip
	ands r0, r1
	movs r1, #0xb0
	lsls r1, r1, #6
	cmp r0, r1
	bne _081DF08E
	movs r0, #1
	b _081DF090
_081DF08E:
	movs r0, #0
_081DF090:
	cmp r0, #0
	beq _081DF0A0
	movs r0, #0x3f
	ands r0, r2
	cmp r0, #0
	beq _081DF09E
	adds r7, #1
_081DF09E:
	adds r5, #1
_081DF0A0:
	adds r3, #1
	cmp r3, r6
	blt _081DF062
_081DF0A6:
	cmp r5, r6
	bne _081DF0D0
	cmp r5, r7
	bne _081DF0C0
	ldr r2, _081DF0BC @ =FUN_081df0f8
	adds r0, r4, #0
	movs r1, #0x11
	bl FUN_081dd9b8
	b _081DF0EE
	.align 2, 0
_081DF0BC: .4byte FUN_081df0f8
_081DF0C0:
	ldr r2, _081DF0CC @ =FUN_081df3f0
	adds r0, r4, #0
	movs r1, #0x14
	bl FUN_081dd9b8
	b _081DF0EE
	.align 2, 0
_081DF0CC: .4byte FUN_081df3f0
_081DF0D0:
	adds r1, r4, #0
	adds r1, #0x24
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _081DF0EE
	lsls r0, r0, #0x10
	movs r1, #0xb0
	lsls r1, r1, #0x16
	orrs r1, r0
	lsls r1, r1, #2
	lsrs r1, r1, #0x12
	adds r0, r4, #0
	adds r0, #0x42
	strh r1, [r0]
_081DF0EE:
	movs r0, #0
_081DF0F0:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081df0f8
FUN_081df0f8: @ 0x081DF0F8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DF134
	adds r1, r5, #0
	adds r1, #0x25
	movs r0, #0
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	ldr r0, _081DF14C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DF124
	adds r1, r0, #0
	adds r1, #0x56
	movs r0, #1
	strb r0, [r1]
_081DF124:
	ldr r0, _081DF150 @ =0x000002DE
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081DF134
	movs r1, #0
	bl Script_ExecById
_081DF134:
	adds r0, r5, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DF154
	adds r0, r5, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF22A
	.align 2, 0
_081DF14C: .4byte 0x03002C68
_081DF150: .4byte 0x000002DE
_081DF154:
	movs r7, #0
	movs r4, #0
	ldrh r6, [r5, #0x1a]
	cmp r7, r6
	bge _081DF1A4
	movs r1, #0xf0
	lsls r1, r1, #6
	mov ip, r1
_081DF164:
	cmp r4, #0
	bge _081DF170
	ldr r1, _081DF16C @ =0x0000FFFF
	b _081DF178
	.align 2, 0
_081DF16C: .4byte 0x0000FFFF
_081DF170:
	ldr r2, [r5, #0x44]
	lsls r1, r4, #1
	adds r1, r1, r2
	ldrh r1, [r1]
_081DF178:
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	adds r1, r3, #0
	mov r2, ip
	ands r1, r2
	movs r2, #0x80
	lsls r2, r2, #5
	cmp r1, r2
	bne _081DF18E
	movs r1, #1
	b _081DF190
_081DF18E:
	movs r1, #0
_081DF190:
	cmp r1, #0
	beq _081DF19E
	movs r1, #0xff
	ands r1, r3
	cmp r1, #0xa5
	bne _081DF19E
	adds r7, #1
_081DF19E:
	adds r4, #1
	cmp r4, r6
	blt _081DF164
_081DF1A4:
	cmp r7, r6
	bne _081DF1BC
	ldr r2, _081DF1B8 @ =FUN_081df23c
	adds r0, r5, #0
	movs r1, #0x12
	bl FUN_081dd9b8
	movs r0, #0
	b _081DF22A
	.align 2, 0
_081DF1B8: .4byte FUN_081df23c
_081DF1BC:
	adds r1, r5, #0
	adds r1, #0x25
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0
	beq _081DF22A
	adds r6, r5, #0
	adds r6, #0x26
	ldrb r1, [r6]
	cmp r1, #0
	bne _081DF222
	movs r0, #4
	str r0, [sp]
	ldr r0, _081DF234 @ =0x0000FFFF
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #0
	movs r1, #1
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r0, #5
	bl FUN_0809c08c
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #6
	bl FUN_0804a084
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r4, r5, r1
	str r0, [r4]
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #9
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	movs r1, #1
	strb r1, [r6]
_081DF222:
	ldr r2, _081DF238 @ =0x000010A5
	adds r1, r5, #0
	adds r1, #0x42
	strh r2, [r1]
_081DF22A:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081DF234: .4byte 0x0000FFFF
_081DF238: .4byte 0x000010A5

	thumb_func_start FUN_081df23c
FUN_081df23c: @ 0x081DF23C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DF2C0
	adds r0, r5, #0
	bl FUN_081dd9f0
	adds r0, r5, #0
	bl FUN_081de02c
	adds r0, r5, #0
	bl FUN_081ddc04
	ldr r0, _081DF2D8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DF2AC
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081DF2AC
	ldr r2, _081DF2DC @ =0x030047E0
	ldrb r1, [r2, #6]
	lsls r0, r1, #4
	subs r0, r0, r1
	ldrb r2, [r2, #7]
	adds r0, r0, r2
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	ldr r1, _081DF2E0 @ =0x000002CE
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #2
	bls _081DF2A4
	ldr r2, _081DF2E4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081DF2E8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081DF2EC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
_081DF2A4:
	movs r2, #0xb9
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
_081DF2AC:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0x46
	bl FUN_081ddfb0
	movs r2, #0xd1
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
_081DF2C0:
	adds r0, r5, #0
	bl FUN_081ddab4
	cmp r0, #0
	bge _081DF2F0
	adds r0, r5, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF38C
	.align 2, 0
_081DF2D8: .4byte 0x03002C68
_081DF2DC: .4byte 0x030047E0
_081DF2E0: .4byte 0x000002CE
_081DF2E4: .4byte 0x030046B8
_081DF2E8: .4byte 0x000003FF
_081DF2EC: .4byte 0x0203B400
_081DF2F0:
	ldr r0, [r5, #0x44]
	ldrh r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #6
	ands r0, r1
	movs r1, #0xc0
	lsls r1, r1, #5
	cmp r0, r1
	bne _081DF306
	movs r0, #1
	b _081DF308
_081DF306:
	movs r0, #0
_081DF308:
	cmp r0, #0
	beq _081DF324
	adds r0, r5, #0
	bl FUN_081dde98
	ldr r2, _081DF320 @ =FUN_081df398
	adds r0, r5, #0
	movs r1, #0x13
	bl FUN_081dd9b8
	movs r0, #0
	b _081DF38C
	.align 2, 0
_081DF320: .4byte FUN_081df398
_081DF324:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r5, r0
	adds r0, r5, #0
	movs r2, #0x48
	bl FUN_081ddb14
	movs r7, #0
	movs r6, #0
	ldrh r1, [r5, #0x1a]
	cmp r7, r1
	bge _081DF36C
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r4, r5, r2
_081DF342:
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	movs r3, #0x48
	bl FUN_081ddb5c
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #1
	bne _081DF362
	adds r0, r4, #0
	movs r1, #0x46
	bl FUN_081ddfb0
	adds r7, #1
_081DF362:
	adds r4, #0x48
	adds r6, #1
	ldrh r1, [r5, #0x1a]
	cmp r6, r1
	blt _081DF342
_081DF36C:
	ldrh r2, [r5, #0x1a]
	cmp r7, r2
	bne _081DF38C
	ldr r1, _081DF394 @ =0x03002C68
	ldr r1, [r1]
	cmp r1, #0
	beq _081DF38C
	movs r2, #0x18
	ldrsh r1, [r1, r2]
	cmp r1, #0
	bne _081DF38C
	movs r2, #0xc0
	lsls r2, r2, #5
	adds r1, r5, #0
	adds r1, #0x42
	strh r2, [r1]
_081DF38C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081DF394: .4byte 0x03002C68

	thumb_func_start FUN_081df398
FUN_081df398: @ 0x081DF398
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	adds r0, r4, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DF3B8
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF3E4
_081DF3B8:
	ldr r1, [r4, #0x34]
	cmp r1, #0x77
	bls _081DF3E4
	movs r0, #0
	bl ClearBGTilemapBuffer
	adds r0, r4, #0
	bl FUN_081dded4
	movs r1, #0xdd
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	strh r0, [r4, #0x38]
	adds r0, r4, #0
	bl FUN_081ddf44
	ldr r2, _081DF3EC @ =FUN_081deaf4
	adds r0, r4, #0
	movs r1, #0xa
	bl FUN_081dd9b8
_081DF3E4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DF3EC: .4byte FUN_081deaf4

	thumb_func_start FUN_081df3f0
FUN_081df3f0: @ 0x081DF3F0
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DF42C
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #6
	bl FUN_0804a084
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r4, r5, r1
	str r0, [r4]
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #0xa
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
_081DF42C:
	adds r0, r5, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DF444
	adds r0, r5, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF454
_081DF444:
	ldr r1, [r5, #0x34]
	cmp r1, #0x77
	bls _081DF454
	ldr r2, _081DF45C @ =FUN_081df460
	adds r0, r5, #0
	movs r1, #0x15
	bl FUN_081dd9b8
_081DF454:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081DF45C: .4byte FUN_081df460

	thumb_func_start FUN_081df460
FUN_081df460: @ 0x081DF460
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	bl FUN_081dd9d4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081DF48C
	movs r0, #0xb8
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081DF484
	movs r1, #0
	bl Script_ExecById
_081DF484:
	adds r1, r4, #0
	adds r1, #0x27
	movs r0, #0
	strb r0, [r1]
_081DF48C:
	adds r0, r4, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DF4A4
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF534
_081DF4A4:
	movs r7, #0
	movs r5, #0
	ldrh r6, [r4, #0x1a]
	movs r1, #0x29
	adds r1, r1, r4
	mov r8, r1
	cmp r7, r6
	bge _081DF4FC
	movs r2, #0xf0
	lsls r2, r2, #6
	mov ip, r2
_081DF4BA:
	cmp r5, #0
	bge _081DF4C8
	ldr r1, _081DF4C4 @ =0x0000FFFF
	b _081DF4D0
	.align 2, 0
_081DF4C4: .4byte 0x0000FFFF
_081DF4C8:
	ldr r2, [r4, #0x44]
	lsls r1, r5, #1
	adds r1, r1, r2
	ldrh r1, [r1]
_081DF4D0:
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	adds r1, r3, #0
	mov r2, ip
	ands r1, r2
	movs r2, #0x80
	lsls r2, r2, #5
	cmp r1, r2
	bne _081DF4E6
	movs r1, #1
	b _081DF4E8
_081DF4E6:
	movs r1, #0
_081DF4E8:
	cmp r1, #0
	beq _081DF4F6
	movs r1, #0x3f
	ands r1, r3
	cmp r1, #1
	bne _081DF4F6
	adds r7, #1
_081DF4F6:
	adds r5, #1
	cmp r5, r6
	blt _081DF4BA
_081DF4FC:
	cmp r7, r6
	bne _081DF50A
	ldr r2, _081DF528 @ =FUN_081df540
	adds r0, r4, #0
	movs r1, #0x16
	bl FUN_081dd9b8
_081DF50A:
	mov r2, r8
	ldrb r1, [r2]
	cmp r1, #0
	beq _081DF534
	adds r2, r4, #0
	adds r2, #0x27
	ldrb r1, [r2]
	cmp r1, #0x3b
	bls _081DF530
	ldr r2, _081DF52C @ =0x00001001
	adds r1, r4, #0
	adds r1, #0x42
	strh r2, [r1]
	b _081DF534
	.align 2, 0
_081DF528: .4byte FUN_081df540
_081DF52C: .4byte 0x00001001
_081DF530:
	adds r1, #1
	strb r1, [r2]
_081DF534:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081df540
FUN_081df540: @ 0x081DF540
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	adds r1, r4, #0
	adds r1, #0x2a
	ldrb r1, [r1]
	cmp r1, #0
	beq _081DF55C
	ldr r2, _081DF564 @ =FUN_081df568
	adds r0, r4, #0
	movs r1, #0x17
	bl FUN_081dd9b8
_081DF55C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DF564: .4byte FUN_081df568

	thumb_func_start FUN_081df568
FUN_081df568: @ 0x081DF568
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	movs r6, #0
	movs r5, #0
	ldrh r1, [r4, #0x1a]
	cmp r6, r1
	bge _081DF5C0
	movs r7, #0xf0
	lsls r7, r7, #6
_081DF57E:
	cmp r5, #0
	bge _081DF58C
	ldr r1, _081DF588 @ =0x0000FFFF
	b _081DF594
	.align 2, 0
_081DF588: .4byte 0x0000FFFF
_081DF58C:
	ldr r2, [r4, #0x44]
	lsls r1, r5, #1
	adds r1, r1, r2
	ldrh r1, [r1]
_081DF594:
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	adds r1, r3, #0
	ands r1, r7
	movs r2, #0x80
	lsls r2, r2, #5
	cmp r1, r2
	bne _081DF5A8
	movs r1, #1
	b _081DF5AA
_081DF5A8:
	movs r1, #0
_081DF5AA:
	cmp r1, #0
	beq _081DF5B8
	movs r1, #0x3f
	ands r1, r3
	cmp r1, #2
	bne _081DF5B8
	adds r6, #1
_081DF5B8:
	adds r5, #1
	ldrh r1, [r4, #0x1a]
	cmp r5, r1
	blt _081DF57E
_081DF5C0:
	ldrh r1, [r4, #0x1a]
	cmp r6, r1
	bne _081DF5D8
	ldr r2, _081DF5D4 @ =FUN_081df604
	adds r0, r4, #0
	movs r1, #0x18
	bl FUN_081dd9b8
	b _081DF5F2
	.align 2, 0
_081DF5D4: .4byte FUN_081df604
_081DF5D8:
	ldr r1, [r4, #0x4c]
	adds r1, #2
	cmp r1, #1
	bls _081DF5E6
	ldr r1, [r4, #0x34]
	cmp r1, #0xb3
	bls _081DF5F2
_081DF5E6:
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF5FA
_081DF5F2:
	ldr r2, _081DF600 @ =0x00001002
	adds r1, r4, #0
	adds r1, #0x42
	strh r2, [r1]
_081DF5FA:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081DF600: .4byte 0x00001002

	thumb_func_start FUN_081df604
FUN_081df604: @ 0x081DF604
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	adds r1, r4, #0
	adds r1, #0x2b
	ldrb r1, [r1]
	cmp r1, #0
	beq _081DF620
	ldr r2, _081DF628 @ =FUN_081df62c
	adds r0, r4, #0
	movs r1, #0x19
	bl FUN_081dd9b8
_081DF620:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DF628: .4byte FUN_081df62c

	thumb_func_start FUN_081df62c
FUN_081df62c: @ 0x081DF62C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	cmp r1, #0
	beq _081DF646
	movs r0, #7
	bl FUN_0809c08c
	movs r1, #1
	strb r1, [r4, #0x1e]
_081DF646:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081df64c
FUN_081df64c: @ 0x081DF64C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r6, r1, #0
	ldr r0, _081DF664 @ =0x03002C68
	ldr r7, [r0]
	cmp r7, #0
	bne _081DF668
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF68E
	.align 2, 0
_081DF664: .4byte 0x03002C68
_081DF668:
	movs r5, #0
_081DF66A:
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r4, r0, r5
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, r6
	bne _081DF686
	mov r0, r8
	adds r1, r6, #0
	bl FUN_081e1984
	movs r0, #0xff
	strb r0, [r4]
_081DF686:
	adds r5, #1
	cmp r5, #4
	ble _081DF66A
	movs r0, #0
_081DF68E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081df698
FUN_081df698: @ 0x081DF698
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081DF6AC @ =0x03002C68
	ldr r3, [r0]
	cmp r3, #0
	bne _081DF6B0
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF6D6
	.align 2, 0
_081DF6AC: .4byte 0x03002C68
_081DF6B0:
	movs r2, #0
	b _081DF6B6
_081DF6B4:
	adds r2, #1
_081DF6B6:
	cmp r2, #4
	bgt _081DF6D4
	movs r4, #0x8c
	lsls r4, r4, #1
	adds r0, r3, r4
	adds r4, r0, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, r1
	bne _081DF6B4
	adds r0, r5, #0
	bl FUN_081e1984
	movs r0, #0xff
	strb r0, [r4]
_081DF6D4:
	movs r0, #0
_081DF6D6:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_081df6dc
FUN_081df6dc: @ 0x081DF6DC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081DF6F0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081DF6FA
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF718
	.align 2, 0
_081DF6F0: .4byte 0x03002C68
_081DF6F4:
	strb r5, [r1]
	movs r0, #1
	b _081DF718
_081DF6FA:
	movs r2, #0
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r3, r0, r1
	movs r4, #1
	rsbs r4, r4, #0
_081DF706:
	adds r1, r3, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r4
	beq _081DF6F4
	adds r2, #1
	cmp r2, #4
	ble _081DF706
	movs r0, #0
_081DF718:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081df720
FUN_081df720: @ 0x081DF720
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081DF730 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081DF734
	movs r0, #0
	b _081DF754
	.align 2, 0
_081DF730: .4byte 0x03002C68
_081DF734:
	movs r2, #0
	movs r1, #0
	movs r5, #0x8c
	lsls r5, r5, #1
	adds r3, r0, r5
_081DF73E:
	adds r0, r3, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r4
	bne _081DF74C
	adds r2, #1
_081DF74C:
	adds r1, #1
	cmp r1, #4
	ble _081DF73E
	adds r0, r2, #0
_081DF754:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081df75c
FUN_081df75c: @ 0x081DF75C
	push {r4, lr}
	sub sp, #8
	bl Script_GetValue
	bl FUN_081df720
	adds r4, r0, #0
	mov r0, sp
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823206c
	adds r0, r4, #0
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081df784
FUN_081df784: @ 0x081DF784
	push {r4, lr}
	sub sp, #8
	ldr r0, _081DF798 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081DF79C
	movs r4, #1
	rsbs r4, r4, #0
	b _081DF7A0
	.align 2, 0
_081DF798: .4byte 0x03002C68
_081DF79C:
	movs r1, #0x18
	ldrsh r4, [r0, r1]
_081DF7A0:
	mov r0, sp
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823206c
	adds r0, r4, #0
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081df7bc
FUN_081df7bc: @ 0x081DF7BC
	push {lr}
	adds r2, r0, #0
	ldr r0, _081DF7DC @ =0x03002C68
	ldr r1, [r0]
	cmp r1, #0
	beq _081DF7E0
	lsls r0, r2, #1
	movs r2, #0x90
	lsls r2, r2, #1
	adds r1, r1, r2
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	b _081DF7E4
	.align 2, 0
_081DF7DC: .4byte 0x03002C68
_081DF7E0:
	movs r0, #1
	rsbs r0, r0, #0
_081DF7E4:
	pop {r1}
	bx r1

	thumb_func_start FUN_081df7e8
FUN_081df7e8: @ 0x081DF7E8
	push {lr}
	adds r2, r0, #0
	ldr r0, _081DF808 @ =0x03002C68
	ldr r1, [r0]
	cmp r1, #0
	beq _081DF80C
	lsls r0, r2, #1
	movs r2, #0x94
	lsls r2, r2, #1
	adds r1, r1, r2
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	b _081DF810
	.align 2, 0
_081DF808: .4byte 0x03002C68
_081DF80C:
	movs r0, #1
	rsbs r0, r0, #0
_081DF810:
	pop {r1}
	bx r1

	thumb_func_start FUN_081df814
FUN_081df814: @ 0x081DF814
	push {r4, lr}
	sub sp, #8
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081DF860
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _081DF858 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _081DF85C @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	b _081DF86A
	.align 2, 0
_081DF858: .4byte 0xFFFF0000
_081DF85C: .4byte 0x0000FFFF
_081DF860:
	ldr r1, _081DF88C @ =0xFFFF0000
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
_081DF86A:
	movs r0, #0x74
	movs r1, #4
	bl VM_GetKeywordValue
	adds r4, r0, #0
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	bne _081DF890
	mov r0, sp
	adds r1, r4, #0
	bl FUN_081df698
	b _081DF898
	.align 2, 0
_081DF88C: .4byte 0xFFFF0000
_081DF890:
	mov r0, sp
	adds r1, r4, #0
	bl FUN_081df64c
_081DF898:
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081df8a0
FUN_081df8a0: @ 0x081DF8A0
	push {lr}
	adds r2, r0, #0
	ldr r0, _081DF8B8 @ =0x03002C68
	ldr r1, [r0]
	cmp r1, #0
	beq _081DF8CE
	ldrb r0, [r1, #0x1c]
	cmp r0, #0
	bne _081DF8BC
	movs r0, #1
	b _081DF8BE
	.align 2, 0
_081DF8B8: .4byte 0x03002C68
_081DF8BC:
	movs r0, #0
_081DF8BE:
	cmp r0, #0
	bne _081DF8CE
	adds r0, r1, #0
	adds r0, #0x24
	strb r2, [r0]
	movs r0, #1
	bl Sound_FadeOutBGM
_081DF8CE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081df8d4
FUN_081df8d4: @ 0x081DF8D4
	push {lr}
	ldr r0, _081DF8EC @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DF8E6
	adds r1, r0, #0
	adds r1, #0x25
	movs r0, #1
	strb r0, [r1]
_081DF8E6:
	pop {r0}
	bx r0
	.align 2, 0
_081DF8EC: .4byte 0x03002C68

	thumb_func_start FUN_081df8f0
FUN_081df8f0: @ 0x081DF8F0
	push {lr}
	adds r1, r0, #0
	ldr r0, _081DF904 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DF900
	adds r0, #0x21
	strb r1, [r0]
_081DF900:
	pop {r0}
	bx r0
	.align 2, 0
_081DF904: .4byte 0x03002C68

	thumb_func_start FUN_081df908
FUN_081df908: @ 0x081DF908
	push {lr}
	ldr r0, _081DF920 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DF91A
	adds r1, r0, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
_081DF91A:
	pop {r0}
	bx r0
	.align 2, 0
_081DF920: .4byte 0x03002C68

	thumb_func_start FUN_081df924
FUN_081df924: @ 0x081DF924
	push {lr}
	ldr r0, _081DF93C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DF936
	adds r1, r0, #0
	adds r1, #0x2a
	movs r0, #1
	strb r0, [r1]
_081DF936:
	pop {r0}
	bx r0
	.align 2, 0
_081DF93C: .4byte 0x03002C68

	thumb_func_start FUN_081df940
FUN_081df940: @ 0x081DF940
	push {lr}
	ldr r0, _081DF958 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DF952
	adds r1, r0, #0
	adds r1, #0x2b
	movs r0, #1
	strb r0, [r1]
_081DF952:
	pop {r0}
	bx r0
	.align 2, 0
_081DF958: .4byte 0x03002C68

	thumb_func_start FUN_081df95c
FUN_081df95c: @ 0x081DF95C
	push {lr}
	adds r1, r0, #0
	ldr r0, _081DF970 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DF96C
	adds r0, #0x23
	strb r1, [r0]
_081DF96C:
	pop {r0}
	bx r0
	.align 2, 0
_081DF970: .4byte 0x03002C68

	thumb_func_start FUN_081df974
FUN_081df974: @ 0x081DF974
	push {lr}
	ldr r0, _081DF988 @ =0x03002C68
	ldr r1, [r0]
	cmp r1, #0
	beq _081DF982
	movs r0, #1
	strb r0, [r1, #0x1e]
_081DF982:
	pop {r0}
	bx r0
	.align 2, 0
_081DF988: .4byte 0x03002C68

	thumb_func_start FUN_081df98c
FUN_081df98c: @ 0x081DF98C
	push {lr}
	ldr r0, _081DF9A0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DF99C
	ldrb r0, [r0, #0x1e]
	cmp r0, #0
	bne _081DF9A4
_081DF99C:
	movs r0, #0
	b _081DF9A6
	.align 2, 0
_081DF9A0: .4byte 0x03002C68
_081DF9A4:
	movs r0, #1
_081DF9A6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081df9ac
FUN_081df9ac: @ 0x081DF9AC
	push {r4, lr}
	sub sp, #0x20
	adds r2, r0, #0
	ldr r0, _081DF9FC @ =0x03002C68
	ldr r3, [r0]
	cmp r3, #0
	beq _081DF9F2
	movs r4, #0
	ldrsh r0, [r2, r4]
	str r0, [sp]
	movs r4, #2
	ldrsh r0, [r2, r4]
	str r0, [sp, #4]
	movs r4, #4
	ldrsh r0, [r2, r4]
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	str r0, [sp, #0x14]
	ldr r1, _081DFA00 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r1
	movs r1, #6
	orrs r0, r1
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	mov r0, sp
	str r0, [r1, #4]
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrh r0, [r0]
	bl Script_ExecById
_081DF9F2:
	add sp, #0x20
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DF9FC: .4byte 0x03002C68
_081DFA00: .4byte 0xFFFF0000

	thumb_func_start FUN_081dfa04
FUN_081dfa04: @ 0x081DFA04
	push {lr}
	ldr r0, _081DFA14 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DFA18
	ldrb r0, [r0, #0x1c]
	b _081DFA1A
	.align 2, 0
_081DFA14: .4byte 0x03002C68
_081DFA18:
	movs r0, #0
_081DFA1A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081dfa20
FUN_081dfa20: @ 0x081DFA20
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r6, [sp, #0x10]
	ldr r0, _081DFA50 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DFA8E
	ldr r1, _081DFA54 @ =0x085AE3FA
	ldrb r0, [r1]
	str r0, [r5]
	ldrb r0, [r1, #1]
	str r0, [r2]
	ldrb r0, [r1, #2]
	str r0, [r3]
	ldrb r0, [r1, #3]
	str r0, [r6]
	cmp r4, #1
	beq _081DFA7C
	cmp r4, #1
	bgt _081DFA58
	cmp r4, #0
	beq _081DFA70
	b _081DFA8E
	.align 2, 0
_081DFA50: .4byte 0x03002C68
_081DFA54: .4byte 0x085AE3FA
_081DFA58:
	cmp r4, #2
	beq _081DFA62
	cmp r4, #3
	beq _081DFA88
	b _081DFA8E
_081DFA62:
	ldr r0, _081DFA6C @ =0x085AE3FE
	ldrb r0, [r0]
	str r0, [r5]
	b _081DFA8E
	.align 2, 0
_081DFA6C: .4byte 0x085AE3FE
_081DFA70:
	ldr r0, _081DFA78 @ =0x085AE3FE
	ldrb r0, [r0, #1]
	str r0, [r2]
	b _081DFA8E
	.align 2, 0
_081DFA78: .4byte 0x085AE3FE
_081DFA7C:
	ldr r0, _081DFA84 @ =0x085AE3FE
	ldrb r0, [r0, #2]
	str r0, [r3]
	b _081DFA8E
	.align 2, 0
_081DFA84: .4byte 0x085AE3FE
_081DFA88:
	ldr r0, _081DFA94 @ =0x085AE3FE
	ldrb r0, [r0, #3]
	str r0, [r6]
_081DFA8E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DFA94: .4byte 0x085AE3FE

