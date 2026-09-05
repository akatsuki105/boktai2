	.include "asm/macros.inc"

	.syntax unified
	
	.text

@ EnemyXXX_Create でファイル分けしているだけなので他の敵のコードも混じっているかもしれない

	thumb_func_start FUN_08121aec
FUN_08121aec: @ 0x08121AEC
	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	adds r4, r2, #0
	adds r5, r4, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r7, [r0]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08121B0A
	b _08121C26
_08121B0A:
	ldrh r0, [r6, #0xa]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _08121BF8
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r3, _08121B2C @ =0x0000071E
	adds r1, r7, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _08121B30
	movs r0, #1
	b _08121B32
	.align 2, 0
_08121B2C: .4byte 0x0000071E
_08121B30:
	movs r0, #0
_08121B32:
	cmp r0, #0
	bne _08121B42
	ldr r0, [r6, #0x4c]
	movs r1, #8
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08121C26
_08121B42:
	ldr r0, _08121BEC @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08121B78
	ldrh r1, [r6, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08121B78
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r6, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, _08121BF0 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_08121B78:
	movs r2, #0xea
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	bl FUN_080f8d60
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r5, r3
	str r0, [r1]
	adds r2, r6, #0
	adds r2, #0x46
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrh r3, [r4]
	cmp r3, #0
	bne _08121C26
	ldr r0, [r6, #0x4c]
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _08121C26
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #1
	str r1, [r0]
	ldr r2, _08121BF4 @ =0x0000049C
	adds r0, r5, r2
	movs r2, #4
	str r2, [r0]
	movs r6, #0x93
	lsls r6, r6, #3
	adds r0, r5, r6
	str r3, [r0]
	movs r3, #0x8b
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	subs r6, #0xe
	adds r0, r5, r6
	strh r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strh r1, [r0]
	movs r0, #0x1e
	strh r0, [r4]
	adds r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	b _08121C26
	.align 2, 0
_08121BEC: .4byte 0xFFFFF7FF
_08121BF0: .4byte 0xFEFFFFFF
_08121BF4: .4byte 0x0000049C
_08121BF8:
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08121C26
	ldrh r1, [r6, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08121C26
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r6, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, _08121C2C @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_08121C26:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08121C2C: .4byte 0xFEFFFFFF

	thumb_func_start FUN_08121c30
FUN_08121c30: @ 0x08121C30
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
	beq _08121C52
	b _081222D8
_08121C52:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08121C7C
	ldr r3, _08121C78 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08121C6A
	b _081222D8
_08121C6A:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _081222D8
	.align 2, 0
_08121C78: .4byte 0x0000048C
_08121C7C:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _08121C8C
	b _081222D8
_08121C8C:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _08121C9C
	b _08121FA8
_08121C9C:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _08121CAE
	b _081222D8
_08121CAE:
	ldr r2, _08121D40 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _08121CC2
	b _081222D8
_08121CC2:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08121CD0
	b _081222D8
_08121CD0:
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
	bne _08121CE8
	b _08121E30
_08121CE8:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _08121D50
	ands r3, r1
	cmp r3, #0
	beq _08121D50
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08121D0E
	rsbs r1, r1, #0
_08121D0E:
	cmp r1, #0x20
	bgt _08121D50
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _08121D44 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _08121D48 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _08121D4C @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _081222D8
	.align 2, 0
_08121D40: .4byte 0x0000A007
_08121D44: .4byte 0x000004BE
_08121D48: .4byte 0x0000048C
_08121D4C: .4byte 0x0000044E
_08121D50:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _08121D78 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08121D80
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08121D7C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08121DEE
	.align 2, 0
_08121D78: .4byte 0x0000048A
_08121D7C: .4byte 0x03002BE0
_08121D80:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08121D9C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08121D98 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08121DEE
	.align 2, 0
_08121D98: .4byte 0x03002BE0
_08121D9C:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08121DB8
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08121DB4 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08121DEE
	.align 2, 0
_08121DB4: .4byte 0x03002BE0
_08121DB8:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08121DD4
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08121DD0 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08121DEE
	.align 2, 0
_08121DD0: .4byte 0x03002BE0
_08121DD4:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08121DE6
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08121DEE
_08121DE6:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08121DF0
_08121DEE:
	movs r3, #1
_08121DF0:
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
	ldr r5, _08121E24 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _08121E12
	b _08121F68
_08121E12:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08121E28
	movs r0, #1
	b _08121E2A
	.align 2, 0
_08121E24: .4byte 0x0000049C
_08121E28:
	movs r0, #0
_08121E2A:
	cmp r0, #0
	bne _08121F0E
	b _08121F24
_08121E30:
	strh r2, [r7, #0x3e]
	ldr r1, _08121E58 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _08121E60
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08121E5C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08121ECE
	.align 2, 0
_08121E58: .4byte 0x0000048A
_08121E5C: .4byte 0x03002BE0
_08121E60:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08121E7C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08121E78 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08121ECE
	.align 2, 0
_08121E78: .4byte 0x03002BE0
_08121E7C:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _08121E98
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08121E94 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08121ECE
	.align 2, 0
_08121E94: .4byte 0x03002BE0
_08121E98:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08121EB4
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08121EB0 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08121ECE
	.align 2, 0
_08121EB0: .4byte 0x03002BE0
_08121EB4:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08121EC6
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08121ECE
_08121EC6:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08121ED0
_08121ECE:
	movs r3, #1
_08121ED0:
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
	ldr r5, _08121F04 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _08121F68
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08121F08
	movs r0, #1
	b _08121F0A
	.align 2, 0
_08121F04: .4byte 0x0000049C
_08121F08:
	movs r0, #0
_08121F0A:
	cmp r0, #0
	beq _08121F24
_08121F0E:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08121F20 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08121F30
	.align 2, 0
_08121F20: .4byte 0x03002BE0
_08121F24:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08121F68
_08121F30:
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
_08121F68:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08121F94
	ldr r5, _08121FA0 @ =0x0000024E
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
	bls _08121F94
	strh r1, [r2]
_08121F94:
	ldr r5, _08121FA4 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _081222D8
	.align 2, 0
_08121FA0: .4byte 0x0000024E
_08121FA4: .4byte 0x0000048C
_08121FA8:
	ldr r0, _08121FBC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08121FC0
	movs r0, #1
	b _08121FC2
	.align 2, 0
_08121FBC: .4byte 0x030047A4
_08121FC0:
	movs r0, #0
_08121FC2:
	cmp r0, #0
	beq _08121FD0
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236640
	b _08121FD8
_08121FD0:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236524
_08121FD8:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _08122010 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08122014 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _08122006
	cmp r2, #0x17
	bne _08122018
_08122006:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _0812203A
	.align 2, 0
_08122010: .4byte 0x0000048C
_08122014: .4byte 0x000001DF
_08122018:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _08122006
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _08122068 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0812203A
	movs r1, #0
_0812203A:
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
	beq _08122076
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _0812206C
	asrs r0, r0, #1
	b _08122072
	.align 2, 0
_08122068: .4byte 0x00000187
_0812206C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08122072:
	mov r2, sb
	strh r0, [r2]
_08122076:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08122094
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _08122090 @ =0x000001DD
	adds r1, r6, r4
	b _08122108
	.align 2, 0
_08122090: .4byte 0x000001DD
_08122094:
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
	bne _081220F4
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _081220F4
	ldr r2, _081220E4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081220E8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081220EC @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _081220F0 @ =0x000001DD
	adds r1, r6, r4
	b _08122108
	.align 2, 0
_081220E4: .4byte 0x030046B8
_081220E8: .4byte 0x000003FF
_081220EC: .4byte 0x0203B400
_081220F0: .4byte 0x000001DD
_081220F4:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	ldr r3, _08122128 @ =0x000001DD
	adds r1, r6, r3
_08122108:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08122130
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0812212C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0812219E
	.align 2, 0
_08122128: .4byte 0x000001DD
_0812212C: .4byte 0x03002BE0
_08122130:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0812214C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08122148 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0812219E
	.align 2, 0
_08122148: .4byte 0x03002BE0
_0812214C:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08122168
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08122164 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0812219E
	.align 2, 0
_08122164: .4byte 0x03002BE0
_08122168:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08122184
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08122180 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0812219E
	.align 2, 0
_08122180: .4byte 0x03002BE0
_08122184:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08122196
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _0812219E
_08122196:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081221A0
_0812219E:
	movs r3, #1
_081221A0:
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
	ldr r5, _081221D4 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _0812223C
	movs r1, #2
	ldr r2, _081221D8 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081221DC
	movs r0, #1
	b _081221DE
	.align 2, 0
_081221D4: .4byte 0x0000049C
_081221D8: .4byte 0x00000474
_081221DC:
	movs r0, #0
_081221DE:
	cmp r0, #0
	beq _081221F8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081221F4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08122204
	.align 2, 0
_081221F4: .4byte 0x03002BE0
_081221F8:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0812223C
_08122204:
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
_0812223C:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _08122270
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08122270
	ldr r0, _08122288 @ =0x0000024E
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
	bls _08122270
	strh r1, [r2]
_08122270:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0812228C @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _08122290 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08122294
	movs r0, #1
	b _08122296
	.align 2, 0
_08122288: .4byte 0x0000024E
_0812228C: .4byte 0x030046A0
_08122290: .4byte 0x00000934
_08122294:
	movs r0, #0
_08122296:
	ldr r1, _081222E8 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _081222AE
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_081222AE:
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
_081222D8:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081222E8: .4byte 0x0000048A

	thumb_func_start FUN_081222ec
FUN_081222ec: @ 0x081222EC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r0, [r4, #0x44]
	adds r6, r0, #0
	adds r6, #0x48
	ldr r2, _08122310 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08122314
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08122316
	.align 2, 0
_08122310: .4byte 0x0000046D
_08122314:
	movs r0, #0
_08122316:
	cmp r0, #0
	beq _08122332
	adds r0, r4, #0
	movs r1, #5
	bl FUN_080ef86c
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r4, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08122332:
	ldrh r0, [r6, #8]
	cmp r0, #2
	bls _08122348
	cmp r0, #4
	bne _08122348
	ldrh r0, [r6, #0xe]
	cmp r0, #0
	bne _08122348
	adds r0, r4, #0
	bl FUN_081275b8
_08122348:
	ldr r1, _08122378 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08122370
	ldr r3, _0812237C @ =0x000006FA
	adds r2, r5, r3
	ldrh r1, [r2]
	adds r3, #8
	adds r0, r5, r3
	strh r1, [r0]
	ldrh r0, [r2]
	adds r0, #0x1e
	ldr r2, _08122380 @ =0x000006FC
	adds r1, r5, r2
	strh r0, [r1]
	ldr r3, _08122384 @ =0x0000046B
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
_08122370:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08122378: .4byte 0x0000046E
_0812237C: .4byte 0x000006FA
_08122380: .4byte 0x000006FC
_08122384: .4byte 0x0000046B

	thumb_func_start FUN_08122388
FUN_08122388: @ 0x08122388
	bx lr
	.align 2, 0

	thumb_func_start FUN_0812238c
FUN_0812238c: @ 0x0812238C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	ldr r0, [r4, #0x44]
	adds r6, r0, #0
	adds r6, #0x48
	ldr r0, _081223AC @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081223B0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081223B2
	.align 2, 0
_081223AC: .4byte 0x0000046D
_081223B0:
	movs r0, #0
_081223B2:
	cmp r0, #0
	beq _081223EE
	adds r0, r4, #0
	bl FUN_0812dc78
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	strb r0, [r5, #5]
	adds r0, r4, #0
	movs r1, #5
	bl FUN_080ef86c
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081223EE:
	ldrh r0, [r6, #8]
	cmp r0, #2
	bls _08122404
	cmp r0, #4
	bne _08122404
	ldrh r0, [r6, #0xe]
	cmp r0, #0
	bne _08122404
	ldr r0, _08122434 @ =0x00000101
	bl PlaySound_082406e0
_08122404:
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08122440
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r0, _08122438 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r2, _0812243C @ =0x0000046B
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	b _08122450
	.align 2, 0
_08122434: .4byte 0x00000101
_08122438: .4byte 0xFFFFFEFF
_0812243C: .4byte 0x0000046B
_08122440:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08122450:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08122458
FUN_08122458: @ 0x08122458
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08122470 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08122474
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08122476
	.align 2, 0
_08122470: .4byte 0x0000046D
_08122474:
	movs r0, #0
_08122476:
	cmp r0, #0
	beq _08122486
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
_08122486:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ef86c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08122494
FUN_08122494: @ 0x08122494
	push {lr}
	adds r2, r0, #0
	ldr r0, _081224B4 @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081224A6
	movs r0, #0
	strb r0, [r1]
_081224A6:
	adds r0, r2, #0
	movs r1, #0
	bl FUN_080ef86c
	pop {r0}
	bx r0
	.align 2, 0
_081224B4: .4byte 0x0000046D

	thumb_func_start FUN_081224b8
FUN_081224b8: @ 0x081224B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov r8, r5
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	mov sl, r0
	ldr r0, _081224E0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081224E4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081224E6
	.align 2, 0
_081224E0: .4byte 0x0000046D
_081224E4:
	movs r0, #0
_081224E6:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r1, r1, r5
	mov sb, r1
	cmp r0, #0
	bne _081224F4
	b _081229EA
_081224F4:
	mov r2, r8
	ldrb r0, [r2, #5]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #6
	subs r0, #0x40
	mov r3, r8
	strb r0, [r3, #5]
	ldrb r0, [r3, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r2, r0, #1
	ands r2, r1
	ldr r1, _08122544 @ =0x0000046A
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #6
	beq _08122548
	adds r1, #0x16
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _08122548
	mov r1, r8
	ldr r0, [r1, #0x24]
	ldr r0, [r0, #8]
	ldrh r0, [r0, #4]
	lsrs r1, r0, #0xc
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	b _08122550
	.align 2, 0
_08122544: .4byte 0x0000046A
_08122548:
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
_08122550:
	asrs r0, r1, #1
	cmp r2, r0
	bne _081225BE
	ldr r2, _081225A4 @ =0x0000046B
	adds r0, r5, r2
	movs r6, #0
	movs r4, #1
	strb r4, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081225B4
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _081225A8 @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	ldr r1, _081225AC @ =0x0000046A
	adds r0, r5, r1
	strb r6, [r0]
	adds r2, #0x1c
	adds r0, r5, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	ldr r1, _081225B0 @ =0x000005BC
	adds r0, r5, r1
	ldr r2, [r0]
	movs r1, #0x1b
	adds r3, #1
	b _08122B4E
	.align 2, 0
_081225A4: .4byte 0x0000046B
_081225A8: .4byte 0x00000469
_081225AC: .4byte 0x0000046A
_081225B0: .4byte 0x000005BC
_081225B4:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	b _08122BB0
_081225BE:
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	cmp r2, #1
	bne _081225CC
	b _08122700
_081225CC:
	cmp r2, #1
	bgt _081225D6
	cmp r2, #0
	beq _081225E4
	b _081229E2
_081225D6:
	cmp r2, #2
	bne _081225DC
	b _08122808
_081225DC:
	cmp r2, #3
	bne _081225E2
	b _081228DC
_081225E2:
	b _081229E2
_081225E4:
	subs r0, r1, #2
	cmp r0, #3
	bhi _0812267C
	movs r2, #2
	ldr r1, _08122614 @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _08122620
	ldr r1, _08122618 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #1
	bl FUN_08236fac
	ldr r2, _0812261C @ =0x0000046E
	adds r6, r5, r2
	b _08122664
	.align 2, 0
_08122614: .4byte 0x0000025D
_08122618: .4byte 0x000004B7
_0812261C: .4byte 0x0000046E
_08122620:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #3
	ldr r3, _08122674 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08122678 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #3
	bne _08122648
	ldrb r0, [r6]
	cmp r0, #0
	bne _08122648
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08122668
_08122648:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_08122664:
	movs r0, #0
	strb r0, [r6]
_08122668:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	b _08122948
	.align 2, 0
_08122674: .4byte 0x000004B7
_08122678: .4byte 0x0000046E
_0812267C:
	movs r2, #2
	ldr r1, _081226A4 @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _081226B0
	ldr r1, _081226A8 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldr r2, _081226AC @ =0x0000046E
	adds r6, r5, r2
	b _081229D0
	.align 2, 0
_081226A4: .4byte 0x0000025D
_081226A8: .4byte 0x000004B7
_081226AC: .4byte 0x0000046E
_081226B0:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r3, _081226F8 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081226FC @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #2
	bne _081226D8
	ldrb r0, [r6]
	cmp r0, #0
	bne _081226D8
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081226D8
	b _081229D4
_081226D8:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	b _081229D0
	.align 2, 0
_081226F8: .4byte 0x000004B7
_081226FC: .4byte 0x0000046E
_08122700:
	subs r0, r1, #4
	cmp r0, #3
	bhi _08122798
	movs r2, #2
	ldr r3, _08122730 @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _0812273C
	ldr r1, _08122734 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #2
	bl FUN_08236fac
	ldr r2, _08122738 @ =0x0000046E
	adds r6, r5, r2
	b _0812277E
	.align 2, 0
_08122730: .4byte 0x0000025D
_08122734: .4byte 0x000004B7
_08122738: .4byte 0x0000046E
_0812273C:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #4
	ldr r3, _08122790 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08122794 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #4
	bne _08122762
	ldrb r0, [r6]
	cmp r0, #0
	bne _08122762
	ldr r0, [r4, #8]
	ands r0, r2
	cmp r0, #0
	beq _08122782
_08122762:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_0812277E:
	movs r0, #0
	strb r0, [r6]
_08122782:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	b _08122948
	.align 2, 0
_08122790: .4byte 0x000004B7
_08122794: .4byte 0x0000046E
_08122798:
	movs r1, #2
	ldr r2, _081227C0 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081227C8
	ldr r3, _081227C4 @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #2
	movs r3, #1
	bl FUN_08236fac
	b _081227F0
	.align 2, 0
_081227C0: .4byte 0x0000025D
_081227C4: .4byte 0x000004B7
_081227C8:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #3
	ldr r2, _08122800 @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #3
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_081227F0:
	ldr r3, _08122804 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
	b _081229DA
	.align 2, 0
_08122800: .4byte 0x000004B7
_08122804: .4byte 0x0000046E
_08122808:
	subs r0, r1, #2
	cmp r0, #3
	bls _0812286C
	movs r1, #2
	ldr r2, _08122838 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08122840
	ldr r3, _0812283C @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #5
	str r2, [sp]
	movs r2, #2
	movs r3, #1
	bl FUN_08236fac
	b _08122936
	.align 2, 0
_08122838: .4byte 0x0000025D
_0812283C: .4byte 0x000004B7
_08122840:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #3
	ldr r2, _08122868 @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #3
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #4
	orrs r0, r1
	b _08122934
	.align 2, 0
_08122868: .4byte 0x000004B7
_0812286C:
	movs r2, #4
	ldr r1, _08122894 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812289C
	ldr r3, _08122898 @ =0x000004B7
	adds r1, r5, r3
	movs r0, #2
	strb r0, [r1]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r2, [sp]
	movs r2, #2
	movs r3, #2
	bl FUN_08236fac
	b _081228C2
	.align 2, 0
_08122894: .4byte 0x0000025D
_08122898: .4byte 0x000004B7
_0812289C:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldr r1, _081228D4 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #4
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_081228C2:
	ldr r2, _081228D8 @ =0x0000046E
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r5, r3
	b _081229DA
	.align 2, 0
_081228D4: .4byte 0x000004B7
_081228D8: .4byte 0x0000046E
_081228DC:
	cmp r1, #3
	bhi _08122958
	movs r1, #2
	ldr r2, _08122908 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08122910
	ldr r3, _0812290C @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	b _08122936
	.align 2, 0
_08122908: .4byte 0x0000025D
_0812290C: .4byte 0x000004B7
_08122910:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldr r2, _08122950 @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #2
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08122934:
	str r0, [r4, #8]
_08122936:
	ldr r3, _08122954 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #9
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
_08122948:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081229E2
	.align 2, 0
_08122950: .4byte 0x000004B7
_08122954: .4byte 0x0000046E
_08122958:
	movs r2, #2
	ldr r1, _08122984 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08122990
	ldr r3, _08122988 @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #1
	str r2, [sp]
	movs r2, #2
	movs r3, #1
	bl FUN_08236fac
	ldr r0, _0812298C @ =0x0000046E
	adds r6, r5, r0
	b _081229D0
	.align 2, 0
_08122984: .4byte 0x0000025D
_08122988: .4byte 0x000004B7
_0812298C: .4byte 0x0000046E
_08122990:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #3
	ldr r1, _08122A1C @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08122A20 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #3
	bne _081229B8
	ldrb r0, [r6]
	cmp r0, #0
	bne _081229B8
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081229D4
_081229B8:
	strb r2, [r3]
	movs r4, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r4, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
_081229D0:
	movs r0, #0
	strb r0, [r6]
_081229D4:
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r5, r1
_081229DA:
	ldr r1, _08122A24 @ =0xFFFEFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081229E2:
	ldr r2, _08122A20 @ =0x0000046E
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
_081229EA:
	mov r3, sl
	ldrh r0, [r3, #0xe]
	cmp r0, #0
	bne _08122A4C
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r1, r0, #5
	adds r0, r1, #0
	mov r3, r8
	ldrb r2, [r3, #5]
	subs r0, r2, r0
	cmp r0, #0
	bge _08122A10
	rsbs r0, r0, #0
_08122A10:
	cmp r0, #0x15
	bgt _08122A28
	mov r0, r8
	strb r1, [r0, #5]
	b _08122A4C
	.align 2, 0
_08122A1C: .4byte 0x000004B7
_08122A20: .4byte 0x0000046E
_08122A24: .4byte 0xFFFEFFFF
_08122A28:
	movs r1, #0x80
	lsls r1, r1, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08122A44
	adds r0, r2, #0
	adds r0, #0x15
	mov r1, r8
	strb r0, [r1, #5]
	b _08122A4C
_08122A44:
	adds r0, r2, #0
	subs r0, #0x15
	mov r2, r8
	strb r0, [r2, #5]
_08122A4C:
	ldr r1, _08122A64 @ =0x0000A02F
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08122A6C
	ldr r0, _08122A68 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08122A7C
	.align 2, 0
_08122A64: .4byte 0x0000A02F
_08122A68: .4byte 0x00000482
_08122A6C:
	ldr r1, _08122AA0 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08122A7C
	movs r0, #1
	strh r0, [r2]
_08122A7C:
	ldr r3, _08122AA4 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08122AA8
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
	b _08122AC0
	.align 2, 0
_08122AA0: .4byte 0x00000482
_08122AA4: .4byte 0x0000025D
_08122AA8:
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
_08122AC0:
	ldr r1, _08122B70 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08122BB0
	mov r2, r8
	ldrb r0, [r2, #5]
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r3, #0xee
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrb r1, [r1]
	subs r1, r1, r0
	cmp r1, #0
	bge _08122AEC
	rsbs r1, r1, #0
_08122AEC:
	cmp r1, #0
	bgt _08122B80
	ldr r1, _08122B74 @ =0x0000046B
	adds r0, r5, r1
	movs r6, #0
	movs r4, #1
	strb r4, [r0]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r7, #3
	ands r0, r7
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r5, #5]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0x80
	lsls r1, r1, #3
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08122BB0
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r7, [r0]
	adds r1, #0x69
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _08122B78 @ =0x0000046A
	adds r0, r5, r2
	strb r6, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r6, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _08122B7C @ =0x000005BC
	adds r0, r5, r2
	ldr r2, [r0]
	movs r1, #0x1b
	subs r3, #0x17
_08122B4E:
	adds r0, r5, r3
	strb r4, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r6, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r6, [r0]
	b _08122BB0
	.align 2, 0
_08122B70: .4byte 0x0000046E
_08122B74: .4byte 0x0000046B
_08122B78: .4byte 0x0000046A
_08122B7C: .4byte 0x000005BC
_08122B80:
	movs r3, #0xb2
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r4, [r0]
	movs r3, #2
	ldr r0, _08122BC0 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08122BC4 @ =0x0000046B
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
_08122BB0:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08122BC0: .4byte 0x0000046D
_08122BC4: .4byte 0x0000046B

	thumb_func_start FUN_08122bc8
FUN_08122bc8: @ 0x08122BC8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r0, _08122BE4 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08122BE8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08122BEA
	.align 2, 0
_08122BE4: .4byte 0x0000046D
_08122BE8:
	movs r0, #0
_08122BEA:
	cmp r0, #0
	beq _08122C20
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r5, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	movs r0, #0x10
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08122C20:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ef86c
	ldr r2, _08122CD0 @ =0x00000482
	adds r2, r2, r5
	mov r8, r2
	movs r7, #0
	movs r0, #6
	strh r0, [r2]
	ldr r3, _08122CD4 @ =0x00000464
	adds r0, r5, r3
	ldrh r6, [r0]
	cmp r6, #0
	bne _08122CC6
	ldr r1, _08122CD8 @ =0x0000046B
	adds r0, r5, r1
	movs r4, #1
	strb r4, [r0]
	adds r0, r5, #0
	movs r1, #6
	bl FUN_080ef86c
	adds r0, r5, #0
	bl FUN_0812a41c
	ldr r2, _08122CDC @ =0x00000494
	adds r1, r5, r2
	movs r0, #0x40
	strh r0, [r1]
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _08122CE0 @ =0x00000469
	adds r0, r5, r1
	strb r7, [r0]
	subs r2, #0x2a
	adds r0, r5, r2
	strb r7, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r6, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _08122CE4 @ =FUN_08122ce8
	movs r1, #0x13
	subs r3, #0x17
	adds r0, r5, r3
	strb r4, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r7, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r6, [r0]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r0, #0x31
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r1, r8
	strh r4, [r1]
_08122CC6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08122CD0: .4byte 0x00000482
_08122CD4: .4byte 0x00000464
_08122CD8: .4byte 0x0000046B
_08122CDC: .4byte 0x00000494
_08122CE0: .4byte 0x00000469
_08122CE4: .4byte FUN_08122ce8

	thumb_func_start FUN_08122ce8
FUN_08122ce8: @ 0x08122CE8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x3c
	adds r7, r0, #0
	adds r6, r1, #0
	str r7, [sp, #4]
	ldr r0, [r7, #0x44]
	adds r5, r0, #0
	adds r5, #0x48
	ldr r0, _08122D14 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08122D18
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08122D1A
	.align 2, 0
_08122D14: .4byte 0x0000046D
_08122D18:
	movs r0, #0
_08122D1A:
	cmp r0, #0
	beq _08122D50
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r7, r1
	ldr r1, _08122E4C @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _08122E50 @ =0x0000021E
	adds r0, r7, r2
	movs r4, #0
	movs r1, #0
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	subs r2, #0x1e
	adds r0, r7, r2
	strh r1, [r0]
	adds r0, r7, #0
	movs r1, #7
	bl FUN_080ef86c
	ldr r1, _08122E54 @ =0x0000046E
	adds r0, r7, r1
	strb r4, [r0]
_08122D50:
	cmp r6, #0x3b
	bgt _08122D5A
	movs r0, #0
	strh r0, [r5, #8]
	strh r0, [r5, #0xe]
_08122D5A:
	ldr r2, _08122E54 @ =0x0000046E
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08122D66
	b _08122FBC
_08122D66:
	movs r4, #0xc9
	lsls r4, r4, #1
	adds r0, r7, r4
	movs r6, #0
	movs r5, #0
	strh r5, [r0]
	ldr r1, _08122E58 @ =0x0000046B
	adds r0, r7, r1
	movs r4, #1
	strb r4, [r0]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r1, _08122E5C @ =FUN_080e6794
	movs r0, #0xe
	ldr r2, _08122E60 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #8]
	strb r4, [r2]
	ldr r2, _08122E58 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0xc]
	strb r6, [r2]
	ldr r2, _08122E64 @ =0x00000553
	adds r2, r7, r2
	str r2, [sp, #0x10]
	strb r0, [r2]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x14]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x18]
	strh r5, [r1]
	movs r0, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r2, r7
	mov sl, r2
	strb r0, [r2]
	ldr r0, _08122E68 @ =0x00000469
	adds r0, r0, r7
	mov sb, r0
	strb r4, [r0]
	ldr r1, _08122E6C @ =0x0000046A
	adds r1, r1, r7
	mov r8, r1
	strb r6, [r1]
	ldr r2, _08122E70 @ =0x00000484
	adds r6, r7, r2
	str r5, [r6]
	ldr r0, _08122E74 @ =0x0000046C
	adds r5, r7, r0
	strb r4, [r5]
	adds r4, r7, #0
	adds r4, #0x9c
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r2, [r0]
	adds r1, #1
	adds r0, r7, r1
	ldrb r3, [r0]
	adds r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	str r0, [sp]
	ldr r0, [sp, #4]
	adds r1, r4, #0
	bl FUN_0823b490
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	ldr r0, [r4, #8]
	ldrh r1, [r0]
	strh r1, [r3]
	ldr r0, [r4, #8]
	ldrh r0, [r0, #2]
	strh r0, [r3, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r4, [sp, #8]
	str r4, [sp, #0x28]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x20]
	ldr r4, [sp, #0x10]
	str r4, [sp, #0x34]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x1c]
	ldr r4, [sp, #0x18]
	str r4, [sp, #0x30]
	str r6, [sp, #0x2c]
	str r5, [sp, #0x24]
	cmp r2, #0
	blt _08122E48
	cmp r1, #0
	blt _08122E48
	ldr r0, _08122E78 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08122E48
	ldr r0, _08122E7C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08122E80
_08122E48:
	movs r4, #0
	b _08122E8E
	.align 2, 0
_08122E4C: .4byte 0xFFFEBE3F
_08122E50: .4byte 0x0000021E
_08122E54: .4byte 0x0000046E
_08122E58: .4byte 0x0000046B
_08122E5C: .4byte FUN_080e6794
_08122E60: .4byte 0x0000046D
_08122E64: .4byte 0x00000553
_08122E68: .4byte 0x00000469
_08122E6C: .4byte 0x0000046A
_08122E70: .4byte 0x00000484
_08122E74: .4byte 0x0000046C
_08122E78: .4byte 0x030046A8
_08122E7C: .4byte 0x030046AC
_08122E80:
	ldr r0, _08122EA4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08122E8E:
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #0x38]
	bl FUN_08234224
	ldr r3, [sp, #0x38]
	cmp r0, #0
	beq _08122EA8
	adds r0, #4
	b _08122EB4
	.align 2, 0
_08122EA4: .4byte 0x030046A4
_08122EA8:
	ldr r0, _08122EC8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08122EB4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08122ECC
	cmp r2, #2
	beq _08122ED0
	b _08122ED4
	.align 2, 0
_08122EC8: .4byte 0x030046A4
_08122ECC:
	ldrb r0, [r3, #4]
	b _08122ED2
_08122ED0:
	ldrb r0, [r3]
_08122ED2:
	subs r1, r1, r0
_08122ED4:
	strh r1, [r3, #2]
	ldr r6, _08122F00 @ =0x000004A4
	adds r0, r7, r6
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08122F04
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	b _08122F2A
	.align 2, 0
_08122F00: .4byte 0x000004A4
_08122F04:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08122F24
	cmp r0, #2
	beq _08122F20
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08122F20:
	movs r0, #1
	b _08122F34
_08122F24:
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r7, r4
_08122F2A:
	ldr r1, _08122F6C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08122F34:
	adds r3, r0, #0
	cmp r3, #0
	bne _08122F74
	ldr r0, _08122F70 @ =FUN_080e48d0
	movs r2, #1
	ldr r6, [sp, #0x28]
	strb r2, [r6]
	ldr r1, [sp, #0x20]
	strb r3, [r1]
	ldr r4, [sp, #0x34]
	strb r3, [r4]
	ldr r6, [sp, #0x1c]
	str r0, [r6]
	movs r1, #0
	ldr r0, [sp, #0x30]
	strh r3, [r0]
	movs r0, #3
	mov r4, sl
	strb r0, [r4]
	mov r6, sb
	strb r1, [r6]
	mov r0, r8
	strb r1, [r0]
	ldr r1, [sp, #0x2c]
	str r3, [r1]
	ldr r4, [sp, #0x24]
	strb r2, [r4]
	b _08122FBC
	.align 2, 0
_08122F6C: .4byte 0xFFFFFDFF
_08122F70: .4byte FUN_080e48d0
_08122F74:
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r5, #0
	movs r0, #1
	strh r0, [r1, #6]
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x3c
	adds r6, #0xb0
	adds r2, r7, r6
	subs r6, #4
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _08122FCC @ =0x00000551
	adds r0, r7, r2
	strb r5, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r4, [r0]
_08122FBC:
	add sp, #0x3c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08122FCC: .4byte 0x00000551

	thumb_func_start FUN_08122fd0
FUN_08122fd0: @ 0x08122FD0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _08122FE8 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08122FEC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08122FEE
	.align 2, 0
_08122FE8: .4byte 0x0000046D
_08122FEC:
	movs r0, #0
_08122FEE:
	cmp r0, #0
	beq _08123002
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r0, _0812302C @ =0x0000046E
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
_08123002:
	cmp r5, #0x10
	ble _08123026
	ldr r1, _0812302C @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08123026
	ldr r0, _08123030 @ =0x0000046B
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #1
	beq _08123026
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
_08123026:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0812302C: .4byte 0x0000046E
_08123030: .4byte 0x0000046B

	thumb_func_start FUN_08123034
FUN_08123034: @ 0x08123034
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r0, [r4, #0x44]
	adds r5, r0, #0
	adds r5, #0x48
	ldr r0, _08123054 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08123058
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0812305A
	.align 2, 0
_08123054: .4byte 0x0000046D
_08123058:
	movs r0, #0
_0812305A:
	cmp r0, #0
	beq _0812306E
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r2, _08123120 @ =0x0000046E
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_0812306E:
	cmp r6, #0x2a
	bgt _08123074
	b _081231B0
_08123074:
	ldr r3, _08123120 @ =0x0000046E
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08123080
	b _081231CE
_08123080:
	ldr r1, _08123124 @ =0x0000046B
	adds r0, r4, r1
	movs r6, #0
	movs r5, #1
	strb r5, [r0]
	ldr r2, _08123128 @ =0x000004A4
	adds r0, r4, r2
	ldr r0, [r0]
	movs r3, #0x1c
	ldrsh r1, [r0, r3]
	movs r3, #0x20
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	bl FUN_080e6304
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _0812313C
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r4, r3
	ldr r2, [r0]
	movs r1, #0x24
	ldr r3, _0812312C @ =0x0000046D
	adds r0, r4, r3
	strb r5, [r0]
	subs r3, #2
	adds r0, r4, r3
	strb r6, [r0]
	adds r3, #0xe8
	adds r0, r4, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r1, #0
	strh r6, [r0]
	movs r2, #0xc
	subs r3, #0xeb
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _08123130 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _08123134 @ =0x00000484
	adds r0, r4, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r5, [r0]
	adds r1, #0x3e
	adds r0, r4, r1
	ldr r0, [r0]
	strh r5, [r0, #6]
	movs r0, #4
	ldr r3, _08123138 @ =0x00000222
	adds r2, r4, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _081231CE
	.align 2, 0
_08123120: .4byte 0x0000046E
_08123124: .4byte 0x0000046B
_08123128: .4byte 0x000004A4
_0812312C: .4byte 0x0000046D
_08123130: .4byte 0x0000046A
_08123134: .4byte 0x00000484
_08123138: .4byte 0x00000222
_0812313C:
	movs r1, #7
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _081231A8 @ =0x00000484
	adds r0, r4, r1
	str r2, [r0]
	adds r3, #2
	adds r0, r4, r3
	strb r5, [r0]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r5, [r0]
	subs r3, #2
	adds r0, r4, r3
	strb r2, [r0]
	adds r3, #0xe8
	adds r0, r4, r3
	strb r5, [r0]
	adds r3, #0x25
	adds r0, r4, r3
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r2, [r0]
	subs r3, #0xd0
	adds r0, r4, r3
	ldr r0, [r0]
	strh r2, [r0, #6]
	ldr r0, _081231AC @ =0x00000482
	adds r1, r4, r0
	movs r0, #3
	strh r0, [r1]
	movs r2, #0x10
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081231CE
	.align 2, 0
_081231A8: .4byte 0x00000484
_081231AC: .4byte 0x00000482
_081231B0:
	ldrh r0, [r5, #8]
	cmp r0, #2
	bne _081231CE
	ldrh r1, [r5, #0xe]
	ldrb r0, [r5, #7]
	cmp r0, #0
	beq _081231C6
	subs r0, #1
	cmp r1, r0
	beq _081231CA
	b _081231CE
_081231C6:
	cmp r1, #0
	bne _081231CE
_081231CA:
	movs r0, #0
	strh r0, [r5, #0xe]
_081231CE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081231d4
FUN_081231d4: @ 0x081231D4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	adds r3, r1, #0
	movs r2, #1
	ldr r1, _081231F8 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081231FC
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08123206
	.align 2, 0
_081231F8: .4byte 0x0000025D
_081231FC:
	ldr r1, [r5, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_08123206:
	ldr r2, _0812321C @ =0x0000046D
	adds r0, r5, r2
	ldrb r1, [r0]
	mov sb, r0
	cmp r1, #0
	beq _08123220
	movs r0, #0
	mov r4, sb
	strb r0, [r4]
	movs r0, #1
	b _08123222
	.align 2, 0
_0812321C: .4byte 0x0000046D
_08123220:
	movs r0, #0
_08123222:
	adds r1, r0, #0
	cmp r1, #0
	beq _08123234
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r5, r1
	bl FUN_080136b4
	b _08123342
_08123234:
	cmp r3, #0x1a
	bgt _0812323A
	b _0812333C
_0812323A:
	mov r4, sp
	adds r4, #5
	adds r0, r5, #0
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_080e5d44
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r1, [r4]
	movs r0, #4
	movs r2, #8
	adds r4, r1, #0
	orrs r4, r0
	ldr r1, _0812327C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08123288
	ldr r1, _08123280 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r4, [sp]
	bl FUN_08236fac
	ldr r2, _08123284 @ =0x0000046E
	adds r7, r5, r2
	b _08123306
	.align 2, 0
_0812327C: .4byte 0x0000025D
_08123280: .4byte 0x000004B7
_08123284: .4byte 0x0000046E
_08123288:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r3, #0
	adds r2, #8
	ldr r1, _081232F4 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081232F8 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _081232C4
	ldrb r0, [r7]
	cmp r0, #0
	bne _081232C4
	cmp r4, #1
	bne _081232B6
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0812330A
_081232B6:
	cmp r4, #0
	bne _081232C4
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0812330A
_081232C4:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081232D6
	movs r3, #6
_081232D6:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081232FC
	ldr r0, [r6, #8]
	mov r2, r8
	orrs r0, r2
	b _08123304
	.align 2, 0
_081232F4: .4byte 0x000004B7
_081232F8: .4byte 0x0000046E
_081232FC:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08123304:
	str r0, [r6, #8]
_08123306:
	movs r0, #0
	strb r0, [r7]
_0812330A:
	ldr r3, _08123334 @ =FUN_08123354
	movs r2, #0xd
	movs r1, #0
	movs r0, #1
	mov r4, sb
	strb r0, [r4]
	ldr r4, _08123338 @ =0x0000046B
	adds r0, r5, r4
	strb r1, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r1, [r0]
	b _08123342
	.align 2, 0
_08123334: .4byte FUN_08123354
_08123338: .4byte 0x0000046B
_0812333C:
	ldr r2, _08123350 @ =0x0000046E
	adds r0, r5, r2
	strb r1, [r0]
_08123342:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08123350: .4byte 0x0000046E

	thumb_func_start FUN_08123354
FUN_08123354: @ 0x08123354
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _0812336C @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08123370
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08123372
	.align 2, 0
_0812336C: .4byte 0x0000046D
_08123370:
	movs r0, #0
_08123372:
	cmp r0, #0
	beq _081233BE
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r6, r1
	bl FUN_08013698
	ldr r2, _08123398 @ =0x0000025D
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812339C
	ldr r2, [r6, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _081233AA
	.align 2, 0
_08123398: .4byte 0x0000025D
_0812339C:
	ldr r0, [r6, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_081233AA:
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #1
	strh r0, [r1]
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0x3c
	strh r0, [r1]
_081233BE:
	ldr r1, _0812355C @ =0x0000046E
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081233CA
	b _08123556
_081233CA:
	adds r0, r6, #0
	bl FUN_0812a504
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r2, _08123560 @ =0x0000055C
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r6, r0
	adds r2, #4
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _08123564 @ =0x00000564
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r4, #0
	strb r0, [r6, #5]
	adds r2, #5
	adds r0, r6, r2
	ldrb r1, [r0]
	subs r2, #0xfd
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _08123568 @ =0x00000566
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _0812356C @ =0x00000567
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r1, r6, r0
	adds r2, #0xfe
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _08123570 @ =0x0000056C
	adds r0, r6, r1
	ldrb r1, [r0]
	subs r2, #0x15
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _08123574 @ =0x00000572
	adds r0, r6, r1
	ldrh r1, [r0]
	subs r2, #0xdf
	adds r0, r6, r2
	movs r5, #0
	strh r1, [r0]
	movs r1, #0xae
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r1, r6, r2
	strh r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r1, [r0]
	subs r2, #0x3a
	adds r0, r6, r2
	strh r1, [r0]
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r4, [r0]
	adds r2, #0x9e
	adds r0, r6, r2
	strh r4, [r0]
	subs r1, #2
	adds r0, r6, r1
	strh r4, [r0]
	ldr r2, _08123578 @ =0x0000046B
	adds r0, r6, r2
	strb r5, [r0]
	ldr r1, _0812357C @ =0x0000046C
	adds r0, r6, r1
	movs r1, #1
	strb r1, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r5, [r0]
	ldr r2, _08123580 @ =0x0000024E
	adds r0, r6, r2
	strh r4, [r0]
	subs r2, #0xbc
	adds r0, r6, r2
	strh r4, [r0]
	ldr r2, _08123584 @ =0x00000544
	adds r0, r6, r2
	strh r4, [r0]
	subs r2, #0xde
	adds r0, r6, r2
	strh r4, [r0]
	movs r2, #0xea
	lsls r2, r2, #1
	adds r0, r6, r2
	str r4, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r4, [r0]
	adds r2, #5
	adds r0, r6, r2
	strb r5, [r0]
	adds r2, #0x3f
	adds r0, r6, r2
	strb r5, [r0]
	ldr r2, _08123588 @ =0x00000482
	adds r0, r6, r2
	strh r1, [r0]
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	adds r2, #0x1a
	adds r0, r6, r2
	str r4, [r0]
	adds r1, #8
	adds r0, r6, r1
	str r4, [r0]
	subs r2, #0x10
	adds r0, r6, r2
	strb r5, [r0]
	adds r1, #0x1e
	adds r0, r6, r1
	strh r4, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r5, [r0]
	subs r1, #0x30
	adds r0, r6, r1
	strb r5, [r0]
	subs r2, #0x35
	adds r0, r6, r2
	movs r1, #8
	bl ClearMemory
	ldr r1, _0812358C @ =0x00000464
	adds r0, r6, r1
	strh r4, [r0]
	movs r2, #0x8c
	lsls r2, r2, #3
	adds r0, r6, r2
	strh r4, [r0]
	subs r1, #2
	adds r0, r6, r1
	strh r4, [r0]
	ldr r1, _08123590 @ =0x08252018
	adds r0, r6, #0
	ldr r2, _08123594 @ =0x00000982
	bl FUN_080e6768
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r5, [r0]
	ldr r1, _08123598 @ =0x00000541
	adds r0, r6, r1
	strb r5, [r0]
	adds r2, #2
	adds r1, r6, r2
	movs r0, #0xff
	strb r0, [r1]
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	adds r2, #0xa
	adds r0, r6, r2
	strb r5, [r0]
	adds r1, #5
	adds r0, r6, r1
	strb r5, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r5, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r5, [r0]
	adds r0, r6, #0
	bl FUN_080eeee0
_08123556:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0812355C: .4byte 0x0000046E
_08123560: .4byte 0x0000055C
_08123564: .4byte 0x00000564
_08123568: .4byte 0x00000566
_0812356C: .4byte 0x00000567
_08123570: .4byte 0x0000056C
_08123574: .4byte 0x00000572
_08123578: .4byte 0x0000046B
_0812357C: .4byte 0x0000046C
_08123580: .4byte 0x0000024E
_08123584: .4byte 0x00000544
_08123588: .4byte 0x00000482
_0812358C: .4byte 0x00000464
_08123590: .4byte 0x08252018
_08123594: .4byte 0x00000982
_08123598: .4byte 0x00000541

	thumb_func_start FUN_0812359c
FUN_0812359c: @ 0x0812359C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x48
	ldr r0, _081235BC @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081235C0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081235C2
	.align 2, 0
_081235BC: .4byte 0x0000046D
_081235C0:
	movs r0, #0
_081235C2:
	cmp r0, #0
	beq _081235E4
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080ef86c
	movs r0, #2
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	ands r0, r1
	cmp r0, #0
	bne _081235E4
	movs r0, #1
	orrs r0, r1
	strh r0, [r2]
_081235E4:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Mod
	cmp r0, #0
	bne _08123600
	ldr r2, _08123648 @ =0x000001DF
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	bl FUN_080e5718
_08123600:
	ldr r1, _0812364C @ =0x00000466
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _0812365C
	movs r1, #0x80
	lsls r1, r1, #5
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r4, [r0]
	ands r4, r1
	cmp r4, #0
	bne _0812365C
	ldr r3, _08123650 @ =FUN_0812366c
	movs r2, #6
	ldr r0, _08123654 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08123658 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	b _08123666
	.align 2, 0
_08123648: .4byte 0x000001DF
_0812364C: .4byte 0x00000466
_08123650: .4byte FUN_0812366c
_08123654: .4byte 0x0000046D
_08123658: .4byte 0x0000046B
_0812365C:
	ldrh r0, [r6, #8]
	cmp r0, #2
	bne _08123666
	movs r0, #0
	strh r0, [r6, #0xe]
_08123666:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0812366c
FUN_0812366c: @ 0x0812366C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _08123684 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08123688
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0812368A
	.align 2, 0
_08123684: .4byte 0x0000046D
_08123688:
	movs r0, #0
_0812368A:
	cmp r0, #0
	beq _081236A6
	adds r0, r4, #0
	movs r1, #9
	bl FUN_080ef86c
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #2
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_081236A6:
	cmp r5, #0x28
	bne _081236B8
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081236B8:
	ldr r1, _081236DC @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081236D6
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	cmp r5, #0x3c
	ble _081236D6
	ldr r0, _081236E0 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_081236D6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081236DC: .4byte 0x0000046E
_081236E0: .4byte 0x0000046B

	thumb_func_start FUN_081236e4
FUN_081236e4: @ 0x081236E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	adds r7, r0, #0
	adds r4, r1, #0
	ldr r0, [r7, #0x44]
	adds r3, r0, #0
	adds r3, #0x48
	ldr r0, _081237B8 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08123708
	movs r0, #0
	strb r0, [r1]
_08123708:
	movs r0, #0x10
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r2, [r1]
	orrs r0, r2
	strh r0, [r1]
	adds r6, r1, #0
	cmp r4, #0x11
	bgt _08123736
	ldrh r4, [r3, #8]
	cmp r4, #0
	bne _08123736
	ldrh r1, [r3, #0xe]
	ldrb r2, [r3, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _08123736
	cmp r2, #1
	beq _08123736
	strh r4, [r3, #0xe]
_08123736:
	ldr r3, _081237BC @ =0x0000046E
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08123742
	b _08123A78
_08123742:
	ldr r4, _081237C0 @ =0x0000046B
	adds r0, r7, r4
	movs r5, #0
	movs r3, #1
	strb r3, [r0]
	movs r0, #2
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r2, [r1]
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	str r1, [sp, #0x30]
	cmp r4, #0
	beq _081237D4
	movs r1, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r7, r4
	strb r1, [r0]
	ldr r1, _081237C4 @ =0x00000469
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _081237C8 @ =0x0000046A
	adds r0, r7, r2
	strb r5, [r0]
	adds r4, #0x1c
	adds r0, r7, r4
	str r5, [r0]
	adds r1, #3
	adds r0, r7, r1
	strb r3, [r0]
	ldr r2, _081237CC @ =0x00000594
	adds r0, r7, r2
	ldr r2, [r0]
	movs r1, #7
	subs r4, #0x17
	adds r0, r7, r4
	strb r3, [r0]
	ldr r3, _081237C0 @ =0x0000046B
	adds r0, r7, r3
	strb r5, [r0]
	adds r4, #0xe6
	adds r0, r7, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	ldr r0, _081237D0 @ =0xFFFFF67C
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _08123A78
	.align 2, 0
_081237B8: .4byte 0x0000046D
_081237BC: .4byte 0x0000046E
_081237C0: .4byte 0x0000046B
_081237C4: .4byte 0x00000469
_081237C8: .4byte 0x0000046A
_081237CC: .4byte 0x00000594
_081237D0: .4byte 0xFFFFF67C
_081237D4:
	movs r0, #0x80
	ands r2, r0
	lsls r0, r2, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _0812384C
	adds r0, r7, #0
	movs r1, #0
	str r3, [sp, #0x34]
	bl FUN_080ef86c
	movs r1, #0xe
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	strb r4, [r0]
	ldr r2, _0812383C @ =0x00000469
	adds r0, r7, r2
	strb r4, [r0]
	adds r5, #2
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _08123840 @ =0x00000484
	adds r0, r7, r1
	str r4, [r0]
	adds r2, #3
	adds r0, r7, r2
	ldr r3, [sp, #0x34]
	strb r3, [r0]
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r2, [r0]
	movs r1, #0x24
	ldr r5, _08123844 @ =0x0000046D
	adds r0, r7, r5
	strb r3, [r0]
	ldr r3, _08123848 @ =0x0000046B
	adds r0, r7, r3
	strb r4, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	b _08123A78
	.align 2, 0
_0812383C: .4byte 0x00000469
_08123840: .4byte 0x00000484
_08123844: .4byte 0x0000046D
_08123848: .4byte 0x0000046B
_0812384C:
	adds r0, r7, #0
	movs r1, #0
	str r3, [sp, #0x34]
	bl FUN_080ef86c
	movs r0, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp]
	strb r0, [r4]
	ldr r0, _08123948 @ =0x00000469
	adds r0, r7, r0
	str r0, [sp, #4]
	ldr r3, [sp, #0x34]
	strb r3, [r0]
	ldr r1, _0812394C @ =0x0000046A
	adds r1, r7, r1
	str r1, [sp, #8]
	strb r5, [r1]
	ldr r2, _08123950 @ =0x00000484
	adds r2, r7, r2
	str r2, [sp, #0xc]
	str r5, [r2]
	ldr r4, _08123954 @ =0x0000046C
	adds r4, r7, r4
	str r4, [sp, #0x10]
	strb r3, [r4]
	ldr r1, _08123958 @ =FUN_080e6794
	movs r0, #0xe
	ldr r2, _0812395C @ =0x0000046D
	adds r6, r7, r2
	strb r3, [r6]
	ldr r3, _08123960 @ =0x0000046B
	adds r3, r3, r7
	mov ip, r3
	strb r5, [r3]
	ldr r4, _08123964 @ =0x00000553
	adds r4, r4, r7
	mov sl, r4
	strb r0, [r4]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r0, r7
	mov sb, r0
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r1, r7
	mov r8, r1
	movs r4, #0
	strh r5, [r1]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r1, #0x28
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _08123968 @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _0812396C @ =0x00000552
	adds r0, r7, r3
	movs r4, #7
	strb r4, [r0]
	movs r2, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r5, [r0]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r6, [sp, #0x28]
	ldr r3, [sp]
	str r3, [sp, #0x14]
	ldr r4, [sp, #4]
	str r4, [sp, #0x18]
	ldr r0, [sp, #8]
	str r0, [sp, #0x1c]
	ldr r3, [sp, #0xc]
	str r3, [sp, #0x2c]
	ldr r4, [sp, #0x10]
	str r4, [sp, #0x24]
	mov r0, ip
	str r0, [sp, #0x20]
	cmp r2, #0
	blt _08123942
	cmp r1, #0
	blt _08123942
	ldr r0, _08123970 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08123942
	ldr r0, _08123974 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08123978
_08123942:
	movs r4, #0
	b _08123986
	.align 2, 0
_08123948: .4byte 0x00000469
_0812394C: .4byte 0x0000046A
_08123950: .4byte 0x00000484
_08123954: .4byte 0x0000046C
_08123958: .4byte FUN_080e6794
_0812395C: .4byte 0x0000046D
_08123960: .4byte 0x0000046B
_08123964: .4byte 0x00000553
_08123968: .4byte 0x00000551
_0812396C: .4byte 0x00000552
_08123970: .4byte 0x030046A8
_08123974: .4byte 0x030046AC
_08123978:
	ldr r0, _08123998 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08123986:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812399C
	adds r0, #4
	b _081239A8
	.align 2, 0
_08123998: .4byte 0x030046A4
_0812399C:
	ldr r0, _081239BC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081239A8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081239C0
	cmp r2, #2
	beq _081239C4
	b _081239C8
	.align 2, 0
_081239BC: .4byte 0x030046A4
_081239C0:
	ldrb r0, [r5, #4]
	b _081239C6
_081239C4:
	ldrb r0, [r5]
_081239C6:
	subs r1, r1, r0
_081239C8:
	strh r1, [r5, #2]
	ldr r1, _081239F8 @ =0x000004A4
	adds r0, r7, r1
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08123A00
	ldr r0, _081239FC @ =0xFFFFFDFF
	ldr r3, [sp, #0x30]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	b _08123A2A
	.align 2, 0
_081239F8: .4byte 0x000004A4
_081239FC: .4byte 0xFFFFFDFF
_08123A00:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08123A20
	cmp r0, #2
	beq _08123A1C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08123A1C:
	movs r0, #1
	b _08123A2C
_08123A20:
	ldr r0, _08123A64 @ =0xFFFFFDFF
	ldr r4, [sp, #0x30]
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_08123A2A:
	movs r0, #0
_08123A2C:
	adds r3, r0, #0
	cmp r3, #0
	bne _08123A6C
	ldr r0, _08123A68 @ =FUN_080e48d0
	movs r2, #1
	ldr r5, [sp, #0x28]
	strb r2, [r5]
	ldr r1, [sp, #0x20]
	strb r3, [r1]
	mov r4, sl
	strb r3, [r4]
	mov r5, sb
	str r0, [r5]
	movs r1, #0
	mov r0, r8
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x14]
	strb r0, [r4]
	ldr r5, [sp, #0x18]
	strb r1, [r5]
	ldr r0, [sp, #0x1c]
	strb r1, [r0]
	ldr r1, [sp, #0x2c]
	str r3, [r1]
	ldr r3, [sp, #0x24]
	strb r2, [r3]
	b _08123A78
	.align 2, 0
_08123A64: .4byte 0xFFFFFDFF
_08123A68: .4byte FUN_080e48d0
_08123A6C:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
_08123A78:
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08123a88
FUN_08123a88: @ 0x08123A88
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xd8
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, [r7, #0x44]
	adds r5, r0, #0
	adds r5, #0x48
	ldr r0, _08123AB0 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08123AB4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08123AB6
	.align 2, 0
_08123AB0: .4byte 0x0000046D
_08123AB4:
	movs r0, #0
_08123AB6:
	cmp r0, #0
	beq _08123B32
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _08123ACC
	asrs r1, r0, #2
	b _08123AD2
_08123ACC:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_08123AD2:
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r0, r7, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _08123AEC
	asrs r1, r0, #2
	b _08123AF2
_08123AEC:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_08123AF2:
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
	movs r1, #8
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r4, r7, r3
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08123B20
	movs r0, #0x95
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #0xfd
	bl PlaySound_082406e0
_08123B20:
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	ldr r4, _08123C04 @ =0x0000046E
	adds r1, r7, r4
	movs r0, #0
	strb r0, [r1]
_08123B32:
	movs r1, #0x80
	lsls r1, r1, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #9
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	str r2, [sp, #0x94]
	cmp r6, #0x11
	bgt _08123B72
	ldrh r3, [r5, #8]
	cmp r3, #0
	bne _08123B72
	ldrh r1, [r5, #0xe]
	ldrb r2, [r5, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _08123B72
	cmp r2, #1
	beq _08123B72
	strh r3, [r5, #0xe]
_08123B72:
	adds r0, r6, #0
	movs r1, #0xc
	bl Mod
	cmp r0, #0
	bne _08123BE4
	movs r1, #8
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08123BE4
	ldr r2, _08123C08 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	ldr r1, _08123C0C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x28
	orrs r0, r1
	str r0, [sp, #0x14]
	ldr r2, _08123C10 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08123C14 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r6, _08123C18 @ =0x0203B400
	adds r0, r0, r6
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	adds r0, r7, #0
	adds r0, #8
	ldrb r3, [r7, #5]
	adds r3, #0x80
	movs r2, #0xa
	str r2, [sp]
	movs r2, #6
	str r2, [sp, #4]
	movs r2, #2
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	add r2, sp, #0x10
	bl FUN_080ddcc8
_08123BE4:
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r4, #0x85
	lsls r4, r4, #2
	adds r1, r7, r4
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _08123C1C
	asrs r0, r0, #2
	b _08123C22
	.align 2, 0
_08123C04: .4byte 0x0000046E
_08123C08: .4byte 0xFFFF0000
_08123C0C: .4byte 0x0000FFFF
_08123C10: .4byte 0x030046B8
_08123C14: .4byte 0x000003FF
_08123C18: .4byte 0x0203B400
_08123C1C:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08123C22:
	adds r3, r0, #0
	movs r6, #0x84
	lsls r6, r6, #2
	adds r0, r7, r6
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r5, #0x86
	lsls r5, r5, #2
	adds r1, r7, r5
	movs r6, #0
	ldrsh r0, [r1, r6]
	subs r0, r2, r0
	cmp r0, #0
	blt _08123C42
	asrs r0, r0, #2
	b _08123C48
_08123C42:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08123C48:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _08123C52
	movs r3, #0xc8
	b _08123C5C
_08123C52:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _08123C5C
	adds r3, r0, #0
_08123C5C:
	cmp r2, #0xc8
	ble _08123C64
	movs r2, #0xc8
	b _08123C6E
_08123C64:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _08123C6E
	adds r2, r0, #0
_08123C6E:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r3
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _08123C92
	cmp r2, #0
	bne _08123C92
	movs r0, #1
	b _08123C94
_08123C92:
	movs r0, #0
_08123C94:
	cmp r0, #0
	bne _08123C9C
	bl _08124CD4
_08123C9C:
	ldr r1, _08123DA4 @ =0x0000046E
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08123CAA
	bl _08124CD4
_08123CAA:
	ldr r2, _08123DA8 @ =0x0000046B
	adds r0, r7, r2
	movs r3, #0
	mov sl, r3
	movs r4, #1
	mov r8, r4
	mov r5, r8
	strb r5, [r0]
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r7, r6
	ldr r0, _08123DAC @ =0xFFFFFEDF
	ldrh r1, [r2]
	ands r0, r1
	movs r6, #0
	strh r0, [r2]
	ldr r5, [sp, #0x94]
	movs r0, #0x81
	rsbs r0, r0, #0
	ldr r1, [r5]
	ands r1, r0
	str r1, [r5]
	movs r0, #0x10
	mov sb, r0
	ldrh r3, [r2]
	adds r0, r3, #0
	mov r4, sb
	ands r0, r4
	str r2, [sp, #0x98]
	cmp r0, #0
	beq _08123DCC
	ldr r4, [r7, #0x24]
	ldr r2, _08123DB0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08123DB4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _08123DB8 @ =0x0203B400
	adds r0, r0, r5
	ldrh r0, [r0]
	asrs r0, r0, #3
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r4, #2]
	cmp r0, r1
	bne _08123D20
	adds r0, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_08123D20:
	strb r0, [r4, #2]
	strb r6, [r4, #3]
	ldr r0, _08123DBC @ =0x030046A4
	ldr r0, [r0]
	ldr r1, [r0, #0x10]
	ldr r0, [r4, #4]
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	ldrb r0, [r4, #2]
	lsls r0, r0, #3
	adds r1, r1, r0
	str r1, [r4, #8]
	adds r0, r7, #0
	bl FUN_080e6204
	movs r1, #8
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r6, [r0]
	ldr r3, _08123DC0 @ =0x00000469
	adds r0, r7, r3
	strb r6, [r0]
	ldr r4, _08123DC4 @ =0x0000046A
	adds r0, r7, r4
	strb r1, [r0]
	ldr r5, _08123DC8 @ =0x00000484
	adds r0, r7, r5
	mov r1, sl
	str r1, [r0]
	adds r2, #4
	adds r0, r7, r2
	mov r3, r8
	strb r3, [r0]
	movs r4, #0xb5
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r2, [r0]
	movs r1, #0x13
	subs r5, #0x17
	adds r0, r7, r5
	strb r3, [r0]
	ldr r3, _08123DA8 @ =0x0000046B
	adds r0, r7, r3
	strb r6, [r0]
	subs r4, #0x55
	adds r0, r7, r4
	strb r1, [r0]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r0, r7, r5
	str r2, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r7, r6
	mov r1, sl
	strh r1, [r0]
	movs r0, #9
	rsbs r0, r0, #0
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	bl _08124CD4
	.align 2, 0
_08123DA4: .4byte 0x0000046E
_08123DA8: .4byte 0x0000046B
_08123DAC: .4byte 0xFFFFFEDF
_08123DB0: .4byte 0x030046B8
_08123DB4: .4byte 0x000003FF
_08123DB8: .4byte 0x0203B400
_08123DBC: .4byte 0x030046A4
_08123DC0: .4byte 0x00000469
_08123DC4: .4byte 0x0000046A
_08123DC8: .4byte 0x00000484
_08123DCC:
	ldr r4, _08123DF0 @ =0x0000049C
	adds r0, r7, r4
	ldr r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xc
	ands r4, r0
	cmp r4, #0
	beq _08123DF4
	movs r0, #2
	movs r5, #0xc1
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	bl _08124CD4
	.align 2, 0
_08123DF0: .4byte 0x0000049C
_08123DF4:
	movs r0, #8
	ands r0, r3
	cmp r0, #0
	beq _08123E74
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _08123E60 @ =0x00000469
	adds r0, r7, r3
	strb r6, [r0]
	ldr r5, _08123E64 @ =0x0000046A
	adds r0, r7, r5
	strb r6, [r0]
	ldr r1, _08123E68 @ =0x00000484
	adds r0, r7, r1
	str r4, [r0]
	adds r2, #4
	adds r0, r7, r2
	mov r3, r8
	strb r3, [r0]
	ldr r2, _08123E6C @ =FUN_081236e4
	movs r1, #0x14
	adds r5, #3
	adds r0, r7, r5
	strb r3, [r0]
	ldr r3, _08123E70 @ =0x0000046B
	adds r0, r7, r3
	strb r6, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r0, #9
	rsbs r0, r0, #0
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r3, #0x17
	adds r0, r7, r3
	mov r4, r8
	strh r4, [r0]
	bl _08124CD4
	.align 2, 0
_08123E60: .4byte 0x00000469
_08123E64: .4byte 0x0000046A
_08123E68: .4byte 0x00000484
_08123E6C: .4byte FUN_081236e4
_08123E70: .4byte 0x0000046B
_08123E74:
	movs r4, #0x80
	ands r3, r4
	lsls r0, r3, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne _08123E82
	b _081245AC
_08123E82:
	orrs r1, r4
	str r1, [r5]
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, _08123ED4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r3, r7, r6
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x90]
	str r2, [sp, #0xb8]
	cmp r4, #0
	blt _08123ED0
	cmp r1, #0
	blt _08123ED0
	ldr r0, _08123ED8 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _08123ED0
	ldr r0, _08123EDC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08123EE0
_08123ED0:
	movs r4, #0
	b _08123EEE
	.align 2, 0
_08123ED4: .4byte 0x03002BE0
_08123ED8: .4byte 0x030046A8
_08123EDC: .4byte 0x030046AC
_08123EE0:
	ldr r0, _08123F00 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_08123EEE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08123F04
	adds r0, #4
	b _08123F10
	.align 2, 0
_08123F00: .4byte 0x030046A4
_08123F04:
	ldr r0, _08123F24 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08123F10:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08123F28
	cmp r2, #2
	beq _08123F2C
	b _08123F30
	.align 2, 0
_08123F24: .4byte 0x030046A4
_08123F28:
	ldrb r0, [r5, #4]
	b _08123F2E
_08123F2C:
	ldrb r0, [r5]
_08123F2E:
	subs r1, r1, r0
_08123F30:
	strh r1, [r5, #2]
	ldr r0, _08123F44 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08123F48
	movs r0, #1
	b _08123F4A
	.align 2, 0
_08123F44: .4byte 0x030047A4
_08123F48:
	movs r0, #0
_08123F4A:
	cmp r0, #0
	beq _08123F88
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08123F6A
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08123F66
	adds r2, r0, #0
_08123F66:
	cmp r2, #0
	bge _08123F74
_08123F6A:
	ldr r2, _08123F70 @ =0x000005C4
	adds r0, r7, r2
	b _081244A8
	.align 2, 0
_08123F70: .4byte 0x000005C4
_08123F74:
	ldr r1, _08123F84 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08123FD0
	.align 2, 0
_08123F84: .4byte 0x03002BE0
_08123F88:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08123FB4
	cmp r1, #0
	blt _08123FB4
	ldr r0, _08123FB8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08123FB4
	ldr r0, _08123FBC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08123FC0
_08123FB4:
	movs r5, #0
	b _08123FCE
	.align 2, 0
_08123FB8: .4byte 0x030046A8
_08123FBC: .4byte 0x030046AC
_08123FC0:
	ldr r0, _08124008 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08123FCE:
	movs r2, #0
_08123FD0:
	ldr r4, _0812400C @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _08123FF0
	ldr r1, _08124010 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08123FF0
	b _081243E4
_08123FF0:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x98]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x28]
	cmp r0, #0
	beq _08124014
	movs r0, #0
	b _081244BE
	.align 2, 0
_08124008: .4byte 0x030046A4
_0812400C: .4byte 0x00000256
_08124010: .4byte 0x03002BE0
_08124014:
	ldr r6, _081240BC @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x98]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xb4]
	cmp r6, #0
	beq _081240D4
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _081240C0 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x2c]
	movs r5, #1
	ldr r6, [sp, #0x2c]
	strb r5, [r6]
	ldr r2, _081240C4 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x30]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x34]
	strb r0, [r4]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x38]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r0, r7
	mov r8, r0
	mov r1, sp
	ldrh r1, [r1, #0x28]
	strh r1, [r0]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	strb r3, [r4]
	ldr r6, _081240C8 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _081240CC @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x28]
	str r6, [r1]
	ldr r6, _081240D0 @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, [sp, #0x2c]
	str r5, [sp, #0xd0]
	str r4, [sp, #0xbc]
	str r3, [sp, #0xc0]
	str r2, [sp, #0xc4]
	str r1, [sp, #0x8c]
	str r0, [sp, #0xcc]
	ldr r6, [sp, #0x30]
	str r6, [sp, #0xc8]
	ldr r0, [sp, #0x34]
	str r0, [sp, #0xa4]
	ldr r1, [sp, #0x38]
	str r1, [sp, #0xac]
	mov r2, r8
	str r2, [sp, #0xa8]
	b _081242A2
	.align 2, 0
_081240BC: .4byte 0x00000222
_081240C0: .4byte 0x0000046D
_081240C4: .4byte 0x0000046B
_081240C8: .4byte 0x00000469
_081240CC: .4byte 0x00000484
_081240D0: .4byte 0x0000046C
_081240D4:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #1
	ldr r4, _08124194 @ =0x0000046D
	adds r4, r4, r7
	mov r8, r4
	strb r0, [r4]
	ldr r5, _08124198 @ =0x0000046B
	adds r5, r7, r5
	str r5, [sp, #0x3c]
	movs r2, #0
	strb r2, [r5]
	subs r3, #0x4d
	adds r3, r7, r3
	str r3, [sp, #0x40]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x44]
	str r1, [r4]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x48]
	strh r6, [r5]
	movs r1, #5
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x4c]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _0812419C @ =0x00000469
	adds r5, r7, r4
	strb r3, [r5]
	ldr r2, _081241A0 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _081241A4 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _081241A8 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x90]
	ldr r0, [r0]
	str r0, [sp, #0x50]
	ldr r1, [sp, #0xb8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x50]
	strh r1, [r6]
	ldr r6, [sp, #0xb8]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x50]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov r0, r8
	str r0, [sp, #0xd0]
	ldr r6, [sp, #0x4c]
	str r6, [sp, #0xbc]
	str r5, [sp, #0xc0]
	str r4, [sp, #0xc4]
	str r3, [sp, #0x8c]
	str r2, [sp, #0xcc]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #0xc8]
	ldr r2, [sp, #0x40]
	str r2, [sp, #0xa4]
	ldr r3, [sp, #0x44]
	str r3, [sp, #0xac]
	ldr r4, [sp, #0x48]
	str r4, [sp, #0xa8]
	mov r5, sl
	cmp r5, #0
	blt _08124190
	cmp r1, #0
	blt _08124190
	ldr r0, _081241AC @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _08124190
	ldr r0, _081241B0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081241B4
_08124190:
	movs r4, #0
	b _081241C4
	.align 2, 0
_08124194: .4byte 0x0000046D
_08124198: .4byte 0x0000046B
_0812419C: .4byte 0x00000469
_081241A0: .4byte 0x0000046A
_081241A4: .4byte 0x00000484
_081241A8: .4byte 0x0000046C
_081241AC: .4byte 0x030046A8
_081241B0: .4byte 0x030046AC
_081241B4:
	ldr r0, _081241D4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r6, sl
	adds r4, r0, r6
_081241C4:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081241D8
	adds r0, #4
	b _081241E4
	.align 2, 0
_081241D4: .4byte 0x030046A4
_081241D8:
	ldr r0, _081241F8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081241E4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081241FC
	cmp r2, #2
	beq _08124202
	b _08124208
	.align 2, 0
_081241F8: .4byte 0x030046A4
_081241FC:
	ldr r2, [sp, #0x50]
	ldrb r0, [r2, #4]
	b _08124206
_08124202:
	ldr r3, [sp, #0x50]
	ldrb r0, [r3]
_08124206:
	subs r1, r1, r0
_08124208:
	ldr r4, [sp, #0x50]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x90]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08124234
	cmp r1, #0
	blt _08124234
	ldr r0, _08124238 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08124234
	ldr r0, _0812423C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08124240
_08124234:
	movs r4, #0
	b _0812424E
	.align 2, 0
_08124238: .4byte 0x030046A8
_0812423C: .4byte 0x030046AC
_08124240:
	ldr r0, _08124264 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0812424E:
	ldr r6, [sp, #0x90]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08124268
	adds r0, #4
	b _08124274
	.align 2, 0
_08124264: .4byte 0x030046A4
_08124268:
	ldr r0, _08124288 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08124274:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0812428C
	cmp r3, #2
	beq _08124290
	b _08124294
	.align 2, 0
_08124288: .4byte 0x030046A4
_0812428C:
	ldrb r0, [r5, #4]
	b _08124292
_08124290:
	ldrb r0, [r5]
_08124292:
	subs r2, r2, r0
_08124294:
	ldr r1, [sp, #0x90]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x90]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081242A2:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x54]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _081242CC @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x88]
	cmp r0, #0
	bne _081243AC
	movs r1, #4
	ldr r2, [sp, #0xb4]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081242D0
	movs r0, #1
	b _081242D2
	.align 2, 0
_081242CC: .4byte 0x00000482
_081242D0:
	movs r0, #0
_081242D2:
	ldr r3, _081243BC @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x88]
	cmp r0, #0
	bne _081243AC
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0xd4]
	ldr r1, _081243C0 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081243C4 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r6, #0xd
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _081243C8 @ =0x0000054E
	adds r0, r7, r0
	str r0, [sp, #0xa0]
	ldr r1, _081243CC @ =0x00000541
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081243D0 @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0xb0]
	ldr r6, _081243D4 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0x9c]
	ldr r1, _081243D8 @ =0x030046B8
	adds r2, r5, #0
_0812431A:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _081243DC @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _081243E0 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _0812433E
	adds r3, #1
	cmp r3, #3
	ble _0812431A
	adds r0, r5, #0
_0812433E:
	movs r3, #0
	strb r0, [r4]
	ldr r1, [sp, #0xac]
	ldr r0, [r1]
	ldr r2, [sp, #0xd4]
	str r0, [r2]
	ldr r4, [sp, #0xa4]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0xbc]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0xc0]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0xc4]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa0]
	strb r0, [r6]
	add r0, sp, #0x54
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb0]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xd0]
	strb r1, [r4]
	ldr r5, [sp, #0xc8]
	strb r3, [r5]
	ldr r6, [sp, #0xa4]
	strb r0, [r6]
	ldr r0, [sp, #0xac]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xa8]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0xbc]
	strb r0, [r5]
	ldr r6, [sp, #0xc0]
	strb r1, [r6]
	ldr r0, [sp, #0xc4]
	strb r2, [r0]
	ldr r2, [sp, #0x8c]
	str r3, [r2]
	ldr r3, [sp, #0xcc]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x9c]
	strb r0, [r4]
_081243AC:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x88]
	strh r0, [r5]
	movs r0, #0
	b _081244BE
	.align 2, 0
_081243BC: .4byte 0x00000482
_081243C0: .4byte 0x0000054F
_081243C4: .4byte 0x0000054C
_081243C8: .4byte 0x0000054E
_081243CC: .4byte 0x00000541
_081243D0: .4byte 0x000005BC
_081243D4: .4byte 0x00000542
_081243D8: .4byte 0x030046B8
_081243DC: .4byte 0x000003FF
_081243E0: .4byte 0x0203B400
_081243E4:
	add r6, sp, #0x18
	ldr r0, _08124424 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _08124428
	adds r0, #4
	b _08124434
	.align 2, 0
_08124424: .4byte 0x030046A4
_08124428:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08124434:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0812446C @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _08124474
	ldr r0, _08124470 @ =0xFFFFFDFF
	ldr r6, [sp, #0x98]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _0812449E
	.align 2, 0
_0812446C: .4byte 0x000004A4
_08124470: .4byte 0xFFFFFDFF
_08124474:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _08124494
	cmp r0, #2
	beq _08124490
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08124490:
	movs r0, #1
	b _081244A0
_08124494:
	ldr r0, _081244B4 @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0812449E:
	movs r0, #0
_081244A0:
	cmp r0, #0
	bne _081244BC
	ldr r3, _081244B8 @ =0x000005C4
	adds r0, r7, r3
_081244A8:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081244BE
	.align 2, 0
_081244B4: .4byte 0xFFFFFDFF
_081244B8: .4byte 0x000005C4
_081244BC:
	movs r0, #1
_081244BE:
	cmp r0, #0
	bne _0812452E
	ldr r4, _081244F4 @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081244FC
	ldr r0, _081244F8 @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08124526
	.align 2, 0
_081244F4: .4byte 0x000004A4
_081244F8: .4byte 0xFFFFFDFF
_081244FC:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0812451C
	cmp r0, #2
	beq _08124518
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08124518:
	movs r0, #1
	b _08124528
_0812451C:
	ldr r0, _08124590 @ =0xFFFFFDFF
	ldr r3, [sp, #0x98]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08124526:
	movs r0, #0
_08124528:
	cmp r0, #0
	bne _0812452E
	b _08124C64
_0812452E:
	movs r0, #4
	ldr r5, _08124594 @ =0x00000222
	adds r2, r7, r5
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r2, [r0]
	movs r1, #0x1a
	ldr r4, _08124598 @ =0x0000046D
	adds r0, r7, r4
	movs r4, #1
	strb r4, [r0]
	ldr r6, _0812459C @ =0x0000046B
	adds r0, r7, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	movs r1, #0xc
	subs r6, #0xeb
	adds r0, r7, r6
	strb r3, [r0]
	ldr r2, _081245A0 @ =0x00000469
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _081245A4 @ =0x0000046A
	adds r0, r7, r3
	strb r1, [r0]
	adds r6, #0x1c
	adds r0, r7, r6
	str r5, [r0]
	ldr r1, _081245A8 @ =0x0000046C
	adds r0, r7, r1
	strb r4, [r0]
	b _08124CD4
	.align 2, 0
_08124590: .4byte 0xFFFFFDFF
_08124594: .4byte 0x00000222
_08124598: .4byte 0x0000046D
_0812459C: .4byte 0x0000046B
_081245A0: .4byte 0x00000469
_081245A4: .4byte 0x0000046A
_081245A8: .4byte 0x0000046C
_081245AC:
	mov r3, sb
	orrs r1, r3
	ldr r4, [sp, #0x94]
	str r1, [r4]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r0, [r0]
	strh r2, [r0, #6]
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, _08124608 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r3, r7, r5
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x90]
	str r2, [sp, #0xb8]
	cmp r4, #0
	blt _08124604
	cmp r1, #0
	blt _08124604
	ldr r0, _0812460C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _08124604
	ldr r0, _08124610 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08124614
_08124604:
	movs r4, #0
	b _08124622
	.align 2, 0
_08124608: .4byte 0x03002BE0
_0812460C: .4byte 0x030046A8
_08124610: .4byte 0x030046AC
_08124614:
	ldr r0, _08124634 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_08124622:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08124638
	adds r0, #4
	b _08124644
	.align 2, 0
_08124634: .4byte 0x030046A4
_08124638:
	ldr r0, _08124658 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08124644:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812465C
	cmp r2, #2
	beq _08124660
	b _08124664
	.align 2, 0
_08124658: .4byte 0x030046A4
_0812465C:
	ldrb r0, [r5, #4]
	b _08124662
_08124660:
	ldrb r0, [r5]
_08124662:
	subs r1, r1, r0
_08124664:
	strh r1, [r5, #2]
	ldr r0, _08124678 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0812467C
	movs r0, #1
	b _0812467E
	.align 2, 0
_08124678: .4byte 0x030047A4
_0812467C:
	movs r0, #0
_0812467E:
	cmp r0, #0
	beq _081246BC
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0812469E
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0812469A
	adds r2, r0, #0
_0812469A:
	cmp r2, #0
	bge _081246A8
_0812469E:
	ldr r2, _081246A4 @ =0x000005C4
	adds r0, r7, r2
	b _08124BE0
	.align 2, 0
_081246A4: .4byte 0x000005C4
_081246A8:
	ldr r1, _081246B8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08124704
	.align 2, 0
_081246B8: .4byte 0x03002BE0
_081246BC:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081246E8
	cmp r1, #0
	blt _081246E8
	ldr r0, _081246EC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081246E8
	ldr r0, _081246F0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081246F4
_081246E8:
	movs r5, #0
	b _08124702
	.align 2, 0
_081246EC: .4byte 0x030046A8
_081246F0: .4byte 0x030046AC
_081246F4:
	ldr r0, _0812473C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08124702:
	movs r2, #0
_08124704:
	ldr r4, _08124740 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _08124724
	ldr r1, _08124744 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08124724
	b _08124B1C
_08124724:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x98]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x58]
	cmp r0, #0
	beq _08124748
	movs r0, #0
	b _08124BF6
	.align 2, 0
_0812473C: .4byte 0x030046A4
_08124740: .4byte 0x00000256
_08124744: .4byte 0x03002BE0
_08124748:
	ldr r6, _081247F0 @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x98]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	str r2, [sp, #0xb4]
	cmp r0, #0
	beq _08124808
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _081247F4 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x5c]
	movs r5, #1
	ldr r6, [sp, #0x5c]
	strb r5, [r6]
	ldr r2, _081247F8 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x60]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x64]
	strb r0, [r4]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x68]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r0, r7
	mov r8, r0
	add r1, sp, #0x58
	ldrh r1, [r1]
	strh r1, [r0]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	strb r3, [r4]
	ldr r6, _081247FC @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _08124800 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x58]
	str r6, [r1]
	ldr r6, _08124804 @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, [sp, #0x5c]
	str r5, [sp, #0xd0]
	str r4, [sp, #0xbc]
	str r3, [sp, #0xc0]
	str r2, [sp, #0xc4]
	str r1, [sp, #0x8c]
	str r0, [sp, #0xcc]
	ldr r6, [sp, #0x60]
	str r6, [sp, #0xc8]
	ldr r0, [sp, #0x64]
	str r0, [sp, #0xa4]
	ldr r1, [sp, #0x68]
	str r1, [sp, #0xac]
	mov r2, r8
	str r2, [sp, #0xa8]
	b _081249DA
	.align 2, 0
_081247F0: .4byte 0x00000222
_081247F4: .4byte 0x0000046D
_081247F8: .4byte 0x0000046B
_081247FC: .4byte 0x00000469
_08124800: .4byte 0x00000484
_08124804: .4byte 0x0000046C
_08124808:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #1
	ldr r4, _081248CC @ =0x0000046D
	adds r4, r4, r7
	mov r8, r4
	strb r0, [r4]
	ldr r5, _081248D0 @ =0x0000046B
	adds r5, r7, r5
	str r5, [sp, #0x6c]
	movs r6, #0
	strb r6, [r5]
	ldr r2, _081248D4 @ =0x00000553
	adds r2, r7, r2
	str r2, [sp, #0x70]
	strb r0, [r2]
	subs r3, #0x28
	adds r3, r7, r3
	str r3, [sp, #0x74]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x78]
	mov r5, ip
	strh r5, [r4]
	movs r1, #5
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x7c]
	movs r2, #0
	strb r2, [r6]
	ldr r3, _081248D8 @ =0x00000469
	adds r5, r7, r3
	strb r2, [r5]
	ldr r6, _081248DC @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _081248E0 @ =0x00000484
	adds r3, r7, r1
	mov r2, ip
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x90]
	ldr r0, [r0]
	str r0, [sp, #0x80]
	ldr r1, [sp, #0xb8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x80]
	strh r1, [r6]
	ldr r6, [sp, #0xb8]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x80]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov r0, r8
	str r0, [sp, #0xd0]
	ldr r6, [sp, #0x7c]
	str r6, [sp, #0xbc]
	str r5, [sp, #0xc0]
	str r4, [sp, #0xc4]
	str r3, [sp, #0x8c]
	str r2, [sp, #0xcc]
	ldr r0, [sp, #0x6c]
	str r0, [sp, #0xc8]
	ldr r2, [sp, #0x70]
	str r2, [sp, #0xa4]
	ldr r3, [sp, #0x74]
	str r3, [sp, #0xac]
	ldr r4, [sp, #0x78]
	str r4, [sp, #0xa8]
	mov r5, sb
	cmp r5, #0
	blt _081248C6
	cmp r1, #0
	blt _081248C6
	ldr r0, _081248E4 @ =0x030046A8
	ldr r0, [r0]
	cmp sb, r0
	bhs _081248C6
	ldr r0, _081248E8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081248EC
_081248C6:
	movs r4, #0
	b _081248FC
	.align 2, 0
_081248CC: .4byte 0x0000046D
_081248D0: .4byte 0x0000046B
_081248D4: .4byte 0x00000553
_081248D8: .4byte 0x00000469
_081248DC: .4byte 0x0000046A
_081248E0: .4byte 0x00000484
_081248E4: .4byte 0x030046A8
_081248E8: .4byte 0x030046AC
_081248EC:
	ldr r0, _0812490C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r6, sb
	adds r4, r0, r6
_081248FC:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08124910
	adds r0, #4
	b _0812491C
	.align 2, 0
_0812490C: .4byte 0x030046A4
_08124910:
	ldr r0, _08124930 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812491C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08124934
	cmp r2, #2
	beq _0812493A
	b _08124940
	.align 2, 0
_08124930: .4byte 0x030046A4
_08124934:
	ldr r2, [sp, #0x80]
	ldrb r0, [r2, #4]
	b _0812493E
_0812493A:
	ldr r3, [sp, #0x80]
	ldrb r0, [r3]
_0812493E:
	subs r1, r1, r0
_08124940:
	ldr r4, [sp, #0x80]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x90]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0812496C
	cmp r1, #0
	blt _0812496C
	ldr r0, _08124970 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0812496C
	ldr r0, _08124974 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08124978
_0812496C:
	movs r4, #0
	b _08124986
	.align 2, 0
_08124970: .4byte 0x030046A8
_08124974: .4byte 0x030046AC
_08124978:
	ldr r0, _0812499C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08124986:
	ldr r6, [sp, #0x90]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081249A0
	adds r0, #4
	b _081249AC
	.align 2, 0
_0812499C: .4byte 0x030046A4
_081249A0:
	ldr r0, _081249C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081249AC:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081249C4
	cmp r3, #2
	beq _081249C8
	b _081249CC
	.align 2, 0
_081249C0: .4byte 0x030046A4
_081249C4:
	ldrb r0, [r5, #4]
	b _081249CA
_081249C8:
	ldrb r0, [r5]
_081249CA:
	subs r2, r2, r0
_081249CC:
	ldr r1, [sp, #0x90]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x90]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081249DA:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x84]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _08124A04 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x88]
	cmp r0, #0
	bne _08124AE4
	movs r1, #4
	ldr r2, [sp, #0xb4]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08124A08
	movs r0, #1
	b _08124A0A
	.align 2, 0
_08124A04: .4byte 0x00000482
_08124A08:
	movs r0, #0
_08124A0A:
	ldr r3, _08124AF4 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x88]
	cmp r0, #0
	bne _08124AE4
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0xd4]
	ldr r1, _08124AF8 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _08124AFC @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r6, #0xd
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _08124B00 @ =0x0000054E
	adds r0, r7, r0
	str r0, [sp, #0xa0]
	ldr r1, _08124B04 @ =0x00000541
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _08124B08 @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0xb0]
	ldr r6, _08124B0C @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0x9c]
	ldr r1, _08124B10 @ =0x030046B8
	adds r2, r5, #0
_08124A52:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _08124B14 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _08124B18 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _08124A76
	adds r3, #1
	cmp r3, #3
	ble _08124A52
	adds r0, r5, #0
_08124A76:
	movs r3, #0
	strb r0, [r4]
	ldr r1, [sp, #0xac]
	ldr r0, [r1]
	ldr r2, [sp, #0xd4]
	str r0, [r2]
	ldr r4, [sp, #0xa4]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0xbc]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0xc0]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0xc4]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa0]
	strb r0, [r6]
	add r0, sp, #0x84
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb0]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xd0]
	strb r1, [r4]
	ldr r5, [sp, #0xc8]
	strb r3, [r5]
	ldr r6, [sp, #0xa4]
	strb r0, [r6]
	ldr r0, [sp, #0xac]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xa8]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0xbc]
	strb r0, [r5]
	ldr r6, [sp, #0xc0]
	strb r1, [r6]
	ldr r0, [sp, #0xc4]
	strb r2, [r0]
	ldr r2, [sp, #0x8c]
	str r3, [r2]
	ldr r3, [sp, #0xcc]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x9c]
	strb r0, [r4]
_08124AE4:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x88]
	strh r0, [r5]
	movs r0, #0
	b _08124BF6
	.align 2, 0
_08124AF4: .4byte 0x00000482
_08124AF8: .4byte 0x0000054F
_08124AFC: .4byte 0x0000054C
_08124B00: .4byte 0x0000054E
_08124B04: .4byte 0x00000541
_08124B08: .4byte 0x000005BC
_08124B0C: .4byte 0x00000542
_08124B10: .4byte 0x030046B8
_08124B14: .4byte 0x000003FF
_08124B18: .4byte 0x0203B400
_08124B1C:
	add r6, sp, #0x20
	ldr r0, _08124B5C @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _08124B60
	adds r0, #4
	b _08124B6C
	.align 2, 0
_08124B5C: .4byte 0x030046A4
_08124B60:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08124B6C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _08124BA4 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _08124BAC
	ldr r0, _08124BA8 @ =0xFFFFFDFF
	ldr r6, [sp, #0x98]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _08124BD6
	.align 2, 0
_08124BA4: .4byte 0x000004A4
_08124BA8: .4byte 0xFFFFFDFF
_08124BAC:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _08124BCC
	cmp r0, #2
	beq _08124BC8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08124BC8:
	movs r0, #1
	b _08124BD8
_08124BCC:
	ldr r0, _08124BEC @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08124BD6:
	movs r0, #0
_08124BD8:
	cmp r0, #0
	bne _08124BF4
	ldr r3, _08124BF0 @ =0x000005C4
	adds r0, r7, r3
_08124BE0:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _08124BF6
	.align 2, 0
_08124BEC: .4byte 0xFFFFFDFF
_08124BF0: .4byte 0x000005C4
_08124BF4:
	movs r0, #1
_08124BF6:
	cmp r0, #0
	bne _08124C7C
	ldr r4, _08124C2C @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08124C34
	ldr r0, _08124C30 @ =0xFFFFFDFF
	ldr r2, [sp, #0x98]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08124C5E
	.align 2, 0
_08124C2C: .4byte 0x000004A4
_08124C30: .4byte 0xFFFFFDFF
_08124C34:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08124C54
	cmp r0, #2
	beq _08124C50
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08124C50:
	movs r0, #1
	b _08124C60
_08124C54:
	ldr r0, _08124C74 @ =0xFFFFFDFF
	ldr r3, [sp, #0x98]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08124C5E:
	movs r0, #0
_08124C60:
	cmp r0, #0
	bne _08124C7C
_08124C64:
	ldr r4, _08124C78 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _08124CD4
	.align 2, 0
_08124C74: .4byte 0xFFFFFDFF
_08124C78: .4byte 0x000005C4
_08124C7C:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _08124CE4 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _08124CE8 @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #0x4d
	adds r0, r7, r5
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _08124CEC @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08124CF0 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _08124CF4 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #3
	strh r0, [r1]
_08124CD4:
	add sp, #0xd8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08124CE4: .4byte 0x0000046D
_08124CE8: .4byte 0x0000046B
_08124CEC: .4byte 0x00000469
_08124CF0: .4byte 0x0000046A
_08124CF4: .4byte 0x00000484

	thumb_func_start FUN_08124cf8
FUN_08124cf8: @ 0x08124CF8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x4c
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, [r7, #0x44]
	adds r0, #0x48
	mov r8, r0
	ldr r0, _08124D20 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08124D24
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08124D26
	.align 2, 0
_08124D20: .4byte 0x0000046D
_08124D24:
	movs r0, #0
_08124D26:
	cmp r0, #0
	beq _08124E00
	movs r1, #0x80
	lsls r1, r1, #0xa
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08124D66
	ldr r3, _08124D54 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08124D58
	ldr r2, [r7, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _08124D66
	.align 2, 0
_08124D54: .4byte 0x0000025D
_08124D58:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_08124D66:
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r1, _08124EE0 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _08124EE4 @ =0x0000021E
	adds r0, r7, r1
	movs r5, #0
	movs r4, #0
	strh r4, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r4, [r0]
	ldr r3, _08124EE8 @ =0x00000202
	adds r0, r7, r3
	strh r4, [r0]
	adds r0, r7, #0
	movs r1, #0xa
	bl FUN_080ef86c
	ldr r1, _08124EEC @ =0x0000046E
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _08124EF0 @ =0x00000494
	adds r1, r7, r2
	movs r0, #0x20
	strh r0, [r1]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r7, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r7, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r7, #0
	movs r1, #4
	bl FUN_080e64b4
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r4, [r0]
	adds r0, r7, #0
	bl FUN_080e8360
	movs r1, #8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08124DF4
	movs r0, #0x95
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08124DF4:
	adds r2, r7, #0
	adds r2, #0xde
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
_08124E00:
	adds r0, r6, #0
	movs r1, #0xc
	bl Mod
	cmp r0, #0
	bne _08124E70
	movs r5, #8
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r0, [r0]
	ands r0, r5
	cmp r0, #0
	beq _08124E70
	ldr r3, _08124EF4 @ =0xFFFF0000
	ldr r0, [sp, #0x30]
	ands r0, r3
	movs r1, #0x3c
	orrs r0, r1
	ldr r1, _08124EF8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x30]
	add r2, sp, #0x30
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x28
	orrs r0, r1
	str r0, [r2, #4]
	ldr r3, _08124EFC @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _08124F00 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _08124F04 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	adds r0, r7, #0
	adds r0, #8
	ldrb r3, [r7, #5]
	adds r3, #0x80
	movs r4, #0xa
	str r4, [sp]
	str r5, [sp, #4]
	movs r4, #2
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	bl FUN_080ddcc8
_08124E70:
	cmp r6, #0x22
	bgt _08124E7A
	movs r0, #0
	mov r2, r8
	strh r0, [r2, #0xe]
_08124E7A:
	adds r0, r7, #0
	bl FUN_080e4b3c
	adds r0, r7, #0
	bl FUN_080e4e20
	ldr r3, _08124EEC @ =0x0000046E
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08124E92
	b _081251E4
_08124E92:
	ldr r5, _08124F08 @ =0x0000046B
	adds r0, r7, r5
	movs r6, #1
	strb r6, [r0]
	movs r4, #0x80
	lsls r4, r4, #3
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	ands r0, r4
	ldr r2, _08124F0C @ =0x000001DF
	adds r2, r7, r2
	str r2, [sp, #0x48]
	cmp r0, #0
	beq _08124EB4
	b _08125090
_08124EB4:
	ldr r1, _08124F10 @ =0x0000A007
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08124F14
	adds r0, r7, #0
	bl FUN_0812a688
	movs r5, #8
	ldrsh r0, [r7, r5]
	movs r6, #0xc
	ldrsh r1, [r7, r6]
	movs r2, #1
	str r2, [sp]
	adds r2, r4, #0
	movs r3, #0
	bl FUN_08240cc4
	b _08125090
	.align 2, 0
_08124EE0: .4byte 0xFFFEBE3F
_08124EE4: .4byte 0x0000021E
_08124EE8: .4byte 0x00000202
_08124EEC: .4byte 0x0000046E
_08124EF0: .4byte 0x00000494
_08124EF4: .4byte 0xFFFF0000
_08124EF8: .4byte 0x0000FFFF
_08124EFC: .4byte 0x030046B8
_08124F00: .4byte 0x000003FF
_08124F04: .4byte 0x0203B400
_08124F08: .4byte 0x0000046B
_08124F0C: .4byte 0x000001DF
_08124F10: .4byte 0x0000A007
_08124F14:
	ldr r2, _0812511C @ =0xFFFF0000
	ldr r0, [sp, #0x38]
	ands r0, r2
	movs r1, #0x50
	orrs r0, r1
	ldr r1, _08125120 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x38]
	add r5, sp, #0x38
	ldr r0, [r5, #4]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	str r0, [r5, #4]
	ldr r4, _08125124 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _08125128 @ =0x000003FF
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	ldr r6, _0812512C @ =0x0203B400
	adds r0, r0, r6
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	adds r6, r7, #0
	adds r6, #8
	movs r2, #4
	mov sb, r2
	str r2, [sp]
	movs r3, #0x14
	mov r8, r3
	str r3, [sp, #4]
	movs r0, #2
	mov sl, r0
	str r0, [sp, #8]
	movs r2, #1
	str r2, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x20
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _08125128 @ =0x000003FF
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0812512C @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #3
	ands r1, r2
	adds r1, #1
	mov r3, sb
	str r3, [sp]
	mov r0, r8
	str r0, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	movs r3, #1
	str r3, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x40
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _08125128 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0812512C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x5e
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _08125128 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0812512C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x80
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _08125128 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0812512C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0xc4
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _08125128 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0812512C @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0xf0
	bl FUN_080ddcc8
	ldr r1, [sp, #0x48]
	ldrb r0, [r1]
	cmp r0, #4
	beq _0812508A
	cmp r0, #1
	beq _0812508A
	cmp r0, #5
	beq _0812508A
	cmp r0, #7
	beq _0812508A
	cmp r0, #6
	beq _0812508A
	cmp r0, #0x18
	bne _08125090
_0812508A:
	movs r0, #0xe5
	bl PlaySound_082406e0
_08125090:
	adds r0, r7, #0
	bl FUN_080e6658
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _081250F6
	movs r5, #8
	ldrsh r0, [r7, r5]
	str r0, [sp, #0x10]
	movs r6, #0xa
	ldrsh r0, [r7, r6]
	str r0, [sp, #0x14]
	movs r1, #0xc
	ldrsh r0, [r7, r1]
	str r0, [sp, #0x18]
	adds r3, #2
	adds r0, r7, r3
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	movs r5, #0xd0
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	str r0, [sp, #0x20]
	movs r6, #0xd2
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r0, [r0]
	str r0, [sp, #0x24]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldrh r0, [r7]
	str r0, [sp, #0x2c]
	ldr r1, _0812511C @ =0xFFFF0000
	ldr r0, [sp, #0x40]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x40]
	add r1, sp, #0x40
	add r3, sp, #0x10
	str r3, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_081250F6:
	ldr r5, [sp, #0x48]
	ldrb r0, [r5]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r1, r7, r6
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _08125134
	ldr r0, _08125130 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r2, r0
	movs r1, #1
	lsls r1, r3
	b _08125146
	.align 2, 0
_0812511C: .4byte 0xFFFF0000
_08125120: .4byte 0x0000FFFF
_08125124: .4byte 0x030046B8
_08125128: .4byte 0x000003FF
_0812512C: .4byte 0x0203B400
_08125130: .4byte 0x030046A0
_08125134:
	ldr r0, _081251B4 @ =0x030046A0
	ldr r2, [r0]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r2, r2, r1
	adds r0, r3, #0
	subs r0, #0x20
	movs r1, #1
	lsls r1, r0
_08125146:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r4, #0
	movs r1, #0
	strh r1, [r0]
	ldr r3, _081251B8 @ =FUN_080e48d0
	movs r2, #0x10
	ldr r5, _081251BC @ =0x0000046D
	adds r0, r7, r5
	movs r5, #1
	strb r5, [r0]
	ldr r6, _081251C0 @ =0x0000046B
	adds r0, r7, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	movs r2, #2
	subs r6, #0xeb
	adds r0, r7, r6
	strb r5, [r0]
	ldr r3, _081251C4 @ =0x00000469
	adds r0, r7, r3
	strb r4, [r0]
	adds r6, #2
	adds r0, r7, r6
	strb r2, [r0]
	ldr r2, _081251C8 @ =0x00000484
	adds r0, r7, r2
	str r1, [r0]
	adds r3, #3
	adds r0, r7, r3
	strb r5, [r0]
	ldr r6, _081251CC @ =0x0000025D
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _081251D0
	ldr r1, [r7, #0x44]
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	b _081251DA
	.align 2, 0
_081251B4: .4byte 0x030046A0
_081251B8: .4byte FUN_080e48d0
_081251BC: .4byte 0x0000046D
_081251C0: .4byte 0x0000046B
_081251C4: .4byte 0x00000469
_081251C8: .4byte 0x00000484
_081251CC: .4byte 0x0000025D
_081251D0:
	ldr r1, [r7, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r5
	str r0, [r1, #8]
_081251DA:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r7, r1
	bl FUN_080136b4
_081251E4:
	add sp, #0x4c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081251f4
FUN_081251f4: @ 0x081251F4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x84
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r4, [r0]
	ldr r2, _0812521C @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08125220
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08125222
	.align 2, 0
_0812521C: .4byte 0x0000046D
_08125220:
	movs r0, #0
_08125222:
	cmp r0, #0
	beq _0812523C
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r2, #4
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0812523C:
	adds r0, r7, #0
	bl FUN_0812a1bc
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812526E
	movs r2, #0x10
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	movs r1, #0
	strb r1, [r0]
	ldr r6, _08125284 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r3, _08125288 @ =0x0000046A
	adds r0, r7, r3
	strb r2, [r0]
	adds r5, #0x1c
	adds r0, r7, r5
	str r1, [r0]
	adds r6, #3
	adds r1, r7, r6
	movs r0, #1
	strb r0, [r1]
_0812526E:
	ldr r1, _08125288 @ =0x0000046A
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0x10
	bne _0812528C
	adds r0, r7, #0
	movs r1, #1
	bl FUN_080ef86c
	b _08125298
	.align 2, 0
_08125284: .4byte 0x00000469
_08125288: .4byte 0x0000046A
_0812528C:
	cmp r0, #0x12
	bne _08125298
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
_08125298:
	ldr r2, _08125324 @ =0x00000482
	adds r1, r7, r2
	movs r0, #2
	strh r0, [r1]
	ldr r3, _08125328 @ =0x00000702
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _081252AC
	b _08125988
_081252AC:
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, _0812532C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r0, #4
	ldr r6, _08125330 @ =0x00000222
	adds r3, r7, r6
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _08125334 @ =0x0000071E
	adds r2, r4, r1
	ldr r0, _08125338 @ =0xFFFFEBFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r4, r7, r2
	ldr r6, [r4]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x64]
	str r4, [sp, #0x58]
	str r2, [sp, #0x60]
	cmp r5, #0
	blt _08125320
	cmp r1, #0
	blt _08125320
	ldr r0, _0812533C @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _08125320
	ldr r0, _08125340 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08125344
_08125320:
	movs r4, #0
	b _08125352
	.align 2, 0
_08125324: .4byte 0x00000482
_08125328: .4byte 0x00000702
_0812532C: .4byte 0x03002BE0
_08125330: .4byte 0x00000222
_08125334: .4byte 0x0000071E
_08125338: .4byte 0xFFFFEBFF
_0812533C: .4byte 0x030046A8
_08125340: .4byte 0x030046AC
_08125344:
	ldr r0, _08125364 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_08125352:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08125368
	adds r0, #4
	b _08125374
	.align 2, 0
_08125364: .4byte 0x030046A4
_08125368:
	ldr r0, _08125388 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08125374:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812538C
	cmp r2, #2
	beq _08125390
	b _08125394
	.align 2, 0
_08125388: .4byte 0x030046A4
_0812538C:
	ldrb r0, [r6, #4]
	b _08125392
_08125390:
	ldrb r0, [r6]
_08125392:
	subs r1, r1, r0
_08125394:
	strh r1, [r6, #2]
	ldr r0, _081253A8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081253AC
	movs r0, #1
	b _081253AE
	.align 2, 0
_081253A8: .4byte 0x030047A4
_081253AC:
	movs r0, #0
_081253AE:
	cmp r0, #0
	beq _081253EC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _081253CE
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081253CA
	adds r2, r0, #0
_081253CA:
	cmp r2, #0
	bge _081253D8
_081253CE:
	ldr r4, _081253D4 @ =0x000005C4
	adds r0, r7, r4
	b _08125904
	.align 2, 0
_081253D4: .4byte 0x000005C4
_081253D8:
	ldr r1, _081253E8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08125434
	.align 2, 0
_081253E8: .4byte 0x03002BE0
_081253EC:
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08125418
	cmp r1, #0
	blt _08125418
	ldr r0, _0812541C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08125418
	ldr r0, _08125420 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08125424
_08125418:
	movs r5, #0
	b _08125432
	.align 2, 0
_0812541C: .4byte 0x030046A8
_08125420: .4byte 0x030046AC
_08125424:
	ldr r0, _08125474 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08125432:
	movs r2, #0
_08125434:
	ldr r6, _08125478 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _08125454
	ldr r1, _0812547C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08125454
	b _08125848
_08125454:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sl, r1
	str r2, [sp, #0x4c]
	cmp r1, #0
	beq _08125480
	movs r0, #0
	b _0812591A
	.align 2, 0
_08125474: .4byte 0x030046A4
_08125478: .4byte 0x00000256
_0812547C: .4byte 0x03002BE0
_08125480:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r2, [sp, #0x64]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x4c]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _08125534
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _08125520 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x80]
	movs r5, #1
	ldr r6, [sp, #0x80]
	strb r5, [r6]
	ldr r2, _08125524 @ =0x0000046B
	adds r2, r2, r7
	mov r8, r2
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r4, r7
	mov sb, r4
	strb r0, [r4]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #8]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r7, r0
	str r0, [sp, #0xc]
	mov r1, sl
	strh r1, [r0]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	strb r3, [r4]
	ldr r6, _08125528 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _0812552C @ =0x00000484
	adds r1, r7, r0
	mov r6, sl
	str r6, [r1]
	ldr r6, _08125530 @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, [sp, #0x80]
	str r5, [sp, #0x48]
	str r4, [sp, #0x34]
	str r3, [sp, #0x38]
	str r2, [sp, #0x3c]
	str r1, [sp, #0x54]
	str r0, [sp, #0x44]
	mov r6, r8
	str r6, [sp, #0x40]
	mov r0, sb
	str r0, [sp, #0x7c]
	ldr r1, [sp, #8]
	str r1, [sp, #0x2c]
	ldr r2, [sp, #0xc]
	str r2, [sp, #0x5c]
	b _081256FE
	.align 2, 0
_08125520: .4byte 0x0000046D
_08125524: .4byte 0x0000046B
_08125528: .4byte 0x00000469
_0812552C: .4byte 0x00000484
_08125530: .4byte 0x0000046C
_08125534:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #1
	ldr r4, _081255F4 @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0x10]
	strb r0, [r4]
	ldr r5, _081255F8 @ =0x0000046B
	adds r5, r7, r5
	str r5, [sp, #0x14]
	movs r6, #0
	strb r6, [r5]
	subs r3, #0x4d
	adds r3, r7, r3
	str r3, [sp, #0x18]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x1c]
	str r1, [r4]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x20]
	strh r2, [r5]
	movs r1, #5
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x80]
	movs r3, #0
	strb r3, [r6]
	ldr r4, _081255FC @ =0x00000469
	adds r5, r7, r4
	strb r3, [r5]
	ldr r6, _08125600 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _08125604 @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x58]
	ldr r0, [r0]
	str r0, [sp, #0x24]
	ldr r1, [sp, #0x60]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x24]
	strh r1, [r6]
	ldr r6, [sp, #0x60]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x24]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x48]
	ldr r6, [sp, #0x80]
	str r6, [sp, #0x34]
	str r5, [sp, #0x38]
	str r4, [sp, #0x3c]
	str r3, [sp, #0x54]
	str r2, [sp, #0x44]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x40]
	ldr r2, [sp, #0x18]
	str r2, [sp, #0x7c]
	ldr r3, [sp, #0x1c]
	str r3, [sp, #0x2c]
	ldr r4, [sp, #0x20]
	str r4, [sp, #0x5c]
	mov r5, ip
	cmp r5, #0
	blt _081255F0
	cmp r1, #0
	blt _081255F0
	ldr r0, _08125608 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _081255F0
	ldr r0, _0812560C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08125610
_081255F0:
	movs r4, #0
	b _08125620
	.align 2, 0
_081255F4: .4byte 0x0000046D
_081255F8: .4byte 0x0000046B
_081255FC: .4byte 0x00000469
_08125600: .4byte 0x0000046A
_08125604: .4byte 0x00000484
_08125608: .4byte 0x030046A8
_0812560C: .4byte 0x030046AC
_08125610:
	ldr r0, _08125630 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r6, ip
	adds r4, r0, r6
_08125620:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08125634
	adds r0, #4
	b _08125640
	.align 2, 0
_08125630: .4byte 0x030046A4
_08125634:
	ldr r0, _08125654 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08125640:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08125658
	cmp r2, #2
	beq _0812565E
	b _08125664
	.align 2, 0
_08125654: .4byte 0x030046A4
_08125658:
	ldr r2, [sp, #0x24]
	ldrb r0, [r2, #4]
	b _08125662
_0812565E:
	ldr r3, [sp, #0x24]
	ldrb r0, [r3]
_08125662:
	subs r1, r1, r0
_08125664:
	ldr r4, [sp, #0x24]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x58]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08125690
	cmp r1, #0
	blt _08125690
	ldr r0, _08125694 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08125690
	ldr r0, _08125698 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812569C
_08125690:
	movs r4, #0
	b _081256AA
	.align 2, 0
_08125694: .4byte 0x030046A8
_08125698: .4byte 0x030046AC
_0812569C:
	ldr r0, _081256C0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081256AA:
	ldr r6, [sp, #0x58]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081256C4
	adds r0, #4
	b _081256D0
	.align 2, 0
_081256C0: .4byte 0x030046A4
_081256C4:
	ldr r0, _081256E4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081256D0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081256E8
	cmp r3, #2
	beq _081256EC
	b _081256F0
	.align 2, 0
_081256E4: .4byte 0x030046A4
_081256E8:
	ldrb r0, [r5, #4]
	b _081256EE
_081256EC:
	ldrb r0, [r5]
_081256EE:
	subs r2, r2, r0
_081256F0:
	ldr r1, [sp, #0x58]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x58]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081256FE:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x28]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x4c]
	ldrh r0, [r4]
	ands r0, r1
	mov r8, r3
	ldr r5, _08125728 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x50]
	cmp r0, #0
	bne _0812580C
	movs r1, #4
	ldr r6, [sp, #0x64]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0812572C
	movs r0, #1
	b _0812572E
	.align 2, 0
_08125728: .4byte 0x00000482
_0812572C:
	movs r0, #0
_0812572E:
	ldr r1, _0812581C @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x50]
	cmp r0, #0
	bne _0812580C
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r2, r2, r7
	mov sb, r2
	movs r4, #0xa9
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sl, r4
	ldr r5, _08125820 @ =0x0000054F
	adds r5, r5, r7
	mov ip, r5
	ldr r6, _08125824 @ =0x0000054C
	adds r6, r7, r6
	str r6, [sp, #0x70]
	ldr r0, _08125828 @ =0x0000054D
	adds r0, r7, r0
	str r0, [sp, #0x74]
	ldr r1, _0812582C @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x78]
	ldr r2, _08125830 @ =0x00000541
	adds r2, r7, r2
	str r2, [sp, #0x68]
	ldr r4, _08125834 @ =0x000005BC
	adds r4, r7, r4
	str r4, [sp, #0x30]
	ldr r5, _08125838 @ =0x00000542
	adds r5, r7, r5
	str r5, [sp, #0x6c]
	ldr r6, _0812583C @ =0x0203B400
	ldr r1, _08125840 @ =0x030046B8
	ldr r5, _08125844 @ =0x000003FF
	movs r4, #3
	mov r2, r8
_0812577E:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r4
	lsls r0, r0, #6
	cmp r0, r2
	bne _0812579C
	adds r3, #1
	cmp r3, #3
	ble _0812577E
	mov r0, r8
_0812579C:
	movs r3, #0
	mov r6, sb
	strb r0, [r6]
	ldr r1, [sp, #0x2c]
	ldr r0, [r1]
	mov r2, sl
	str r0, [r2]
	ldr r4, [sp, #0x7c]
	ldrb r0, [r4]
	mov r5, ip
	strb r0, [r5]
	ldr r6, [sp, #0x34]
	ldrb r0, [r6]
	ldr r1, [sp, #0x70]
	strb r0, [r1]
	ldr r2, [sp, #0x38]
	ldrb r0, [r2]
	ldr r4, [sp, #0x74]
	strb r0, [r4]
	ldr r5, [sp, #0x3c]
	ldrb r0, [r5]
	ldr r6, [sp, #0x78]
	strb r0, [r6]
	add r0, sp, #0x28
	ldrb r1, [r0]
	ldr r0, [sp, #0x68]
	strb r1, [r0]
	ldr r1, [sp, #0x30]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x48]
	strb r1, [r4]
	ldr r5, [sp, #0x40]
	strb r3, [r5]
	ldr r6, [sp, #0x7c]
	strb r0, [r6]
	ldr r0, [sp, #0x2c]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x5c]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x34]
	strb r0, [r5]
	ldr r6, [sp, #0x38]
	strb r1, [r6]
	ldr r0, [sp, #0x3c]
	strb r2, [r0]
	ldr r2, [sp, #0x54]
	str r3, [r2]
	ldr r3, [sp, #0x44]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x6c]
	strb r0, [r4]
_0812580C:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x50]
	strh r0, [r5]
	movs r0, #0
	b _0812591A
	.align 2, 0
_0812581C: .4byte 0x00000482
_08125820: .4byte 0x0000054F
_08125824: .4byte 0x0000054C
_08125828: .4byte 0x0000054D
_0812582C: .4byte 0x0000054E
_08125830: .4byte 0x00000541
_08125834: .4byte 0x000005BC
_08125838: .4byte 0x00000542
_0812583C: .4byte 0x0203B400
_08125840: .4byte 0x030046B8
_08125844: .4byte 0x000003FF
_08125848:
	mov sb, sp
	ldr r6, _08125884 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08125888
	adds r0, #4
	b _08125892
	.align 2, 0
_08125884: .4byte 0x030046A4
_08125888:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08125892:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _081258C8 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081258CC
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _081258F2
	.align 2, 0
_081258C8: .4byte 0x000004A4
_081258CC:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081258EC
	cmp r0, #2
	beq _081258E8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081258E8:
	movs r0, #1
	b _081258FC
_081258EC:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_081258F2:
	ldr r1, _08125910 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081258FC:
	cmp r0, #0
	bne _08125918
	ldr r3, _08125914 @ =0x000005C4
	adds r0, r7, r3
_08125904:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0812591A
	.align 2, 0
_08125910: .4byte 0xFFFFFDFF
_08125914: .4byte 0x000005C4
_08125918:
	movs r0, #1
_0812591A:
	cmp r0, #0
	beq _08125992
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r3, [r0]
	movs r1, #0x24
	ldr r5, _08125974 @ =0x0000046D
	adds r0, r7, r5
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _08125978 @ =0x0000046B
	adds r0, r7, r6
	strb r2, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _0812597C @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08125980 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _08125984 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	b _08125992
	.align 2, 0
_08125974: .4byte 0x0000046D
_08125978: .4byte 0x0000046B
_0812597C: .4byte 0x00000469
_08125980: .4byte 0x0000046A
_08125984: .4byte 0x00000484
_08125988:
	ldr r6, _081259A4 @ =0x00000484
	adds r1, r7, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08125992:
	add sp, #0x84
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081259A4: .4byte 0x00000484

	thumb_func_start FUN_081259a8
FUN_081259a8: @ 0x081259A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _08125A1C @ =0xFEFFFFFF
	ldr r2, [r1]
	ands r2, r0
	str r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #0xe
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r3, [r1]
	ands r0, r3
	cmp r0, #0
	beq _08125A18
	movs r0, #4
	ands r2, r0
	cmp r2, #0
	bne _08125A18
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r3
	cmp r0, #0
	bne _08125A18
	ldr r1, _08125A20 @ =0x0000A13F
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08125A18
	movs r0, #0x80
	lsls r0, r0, #0x14
	ands r3, r0
	cmp r3, #0
	bne _08125A18
	ldr r7, _08125A24 @ =0x000004BE
	adds r0, r5, r7
	ldrh r0, [r0]
	cmp r0, #0
	bne _08125A18
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08125A28
_08125A18:
	movs r0, #1
	b _08125A2A
	.align 2, 0
_08125A1C: .4byte 0xFEFFFFFF
_08125A20: .4byte 0x0000A13F
_08125A24: .4byte 0x000004BE
_08125A28:
	movs r0, #0
_08125A2A:
	adds r1, r0, #0
	cmp r1, #0
	beq _08125A32
	b _08125CE8
_08125A32:
	movs r2, #0x87
	lsls r2, r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	movs r3, #0
	mov sb, r3
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldr r0, [r0]
	mov sl, r0
	movs r7, #8
	ldrsh r0, [r5, r7]
	movs r2, #0xc
	ldrsh r1, [r5, r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrh r2, [r2]
	adds r4, #0x51
	adds r3, r5, r4
	ldrb r3, [r3]
	ldrh r4, [r5]
	str r4, [sp]
	bl FUN_08240dc8
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r0, #0
	bge _08125A70
	b _08125CE8
_08125A70:
	ldr r7, _08125B78 @ =0x00000202
	adds r2, r5, r7
	ldrh r0, [r2]
	cmp r0, #0
	bne _08125AE4
	movs r1, #0
	movs r0, #0xb4
	strh r0, [r2]
	movs r2, #0xb9
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r3, [r0]
	movs r2, #9
	ldr r4, _08125B7C @ =0x0000046D
	adds r0, r5, r4
	movs r4, #1
	strb r4, [r0]
	ldr r7, _08125B80 @ =0x0000046B
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
	mov r7, sb
	strh r7, [r0]
	movs r2, #0xb
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r7, _08125B84 @ =0x00000469
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _08125B88 @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _08125B8C @ =0x00000484
	adds r0, r5, r2
	mov r3, sb
	str r3, [r0]
	adds r7, #3
	adds r0, r5, r7
	strb r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #7
	ldr r2, _08125B90 @ =0x0000071E
	add r2, sl
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	mov sb, r4
_08125AE4:
	movs r2, #0x80
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _08125B18
	ldr r1, _08125B94 @ =0x0000024E
	adds r2, r5, r1
	movs r3, #0x96
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r4, [r2]
	adds r0, r0, r4
	strh r0, [r2]
	movs r7, #0x93
	lsls r7, r7, #2
	adds r1, r5, r7
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _08125B18
	strh r1, [r2]
_08125B18:
	lsls r1, r6, #0x18
	asrs r1, r1, #0x18
	adds r0, r5, #0
	bl FUN_080e8f20
	movs r0, #0x81
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r2, _08125B98 @ =0x0000021E
	adds r0, r5, r2
	ldrh r2, [r0]
	adds r0, r5, #0
	bl FUN_0812a228
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08125B3C
	b _08125C88
_08125B3C:
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r6, [r0]
	adds r2, r5, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08125B74
	cmp r1, #0
	blt _08125B74
	ldr r0, _08125B9C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08125B74
	ldr r0, _08125BA0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08125BA4
_08125B74:
	movs r4, #0
	b _08125BB2
	.align 2, 0
_08125B78: .4byte 0x00000202
_08125B7C: .4byte 0x0000046D
_08125B80: .4byte 0x0000046B
_08125B84: .4byte 0x00000469
_08125B88: .4byte 0x0000046A
_08125B8C: .4byte 0x00000484
_08125B90: .4byte 0x0000071E
_08125B94: .4byte 0x0000024E
_08125B98: .4byte 0x0000021E
_08125B9C: .4byte 0x030046A8
_08125BA0: .4byte 0x030046AC
_08125BA4:
	ldr r0, _08125BC4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08125BB2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08125BC8
	adds r0, #4
	b _08125BD4
	.align 2, 0
_08125BC4: .4byte 0x030046A4
_08125BC8:
	ldr r0, _08125BE8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08125BD4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08125BEC
	cmp r2, #2
	beq _08125BF0
	b _08125BF4
	.align 2, 0
_08125BE8: .4byte 0x030046A4
_08125BEC:
	ldrb r0, [r6, #4]
	b _08125BF2
_08125BF0:
	ldrb r0, [r6]
_08125BF2:
	subs r1, r1, r0
_08125BF4:
	movs r3, #0
	strh r1, [r6, #2]
	movs r4, #0x95
	lsls r4, r4, #3
	adds r2, r5, r4
	ldr r1, [r2]
	ldrh r0, [r5, #0xa]
	strh r0, [r1, #2]
	ldr r0, [r2]
	strh r3, [r0, #6]
	movs r7, #0x81
	lsls r7, r7, #2
	adds r4, r5, r7
	ldr r1, _08125C40 @ =0x0000021E
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_0812a368
	ldr r2, _08125C44 @ =0x000004A4
	adds r0, r5, r2
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08125C4C
	ldr r0, _08125C48 @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	b _08125C76
	.align 2, 0
_08125C40: .4byte 0x0000021E
_08125C44: .4byte 0x000004A4
_08125C48: .4byte 0xFFFFFDFF
_08125C4C:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08125C6C
	cmp r0, #2
	beq _08125C68
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08125C68:
	movs r0, #1
	b _08125C78
_08125C6C:
	ldr r0, _08125C8C @ =0xFFFFFDFF
	mov r4, r8
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_08125C76:
	movs r0, #0
_08125C78:
	cmp r0, #0
	bne _08125C94
	ldr r7, _08125C90 @ =0x000005C4
	adds r0, r5, r7
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
_08125C88:
	movs r0, #1
	b _08125CEA
	.align 2, 0
_08125C8C: .4byte 0xFFFFFDFF
_08125C90: .4byte 0x000005C4
_08125C94:
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r3, _08125CFC @ =0x00000482
	adds r2, r5, r3
	movs r0, #3
	strh r0, [r2]
	ldr r2, _08125D00 @ =0xFF7FFFFF
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r1, _08125D04 @ =0x00000716
	add r1, sl
	movs r0, #4
	strb r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #2
	mov r4, r8
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #0x11
	movs r7, #0xbe
	lsls r7, r7, #1
	adds r1, r5, r7
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x81
	lsls r0, r0, #2
	adds r1, r5, r0
	adds r0, r5, #0
	bl FUN_080e7150
	mov r1, sb
	cmp r1, #0
	bne _08125C88
_08125CE8:
	movs r0, #0
_08125CEA:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08125CFC: .4byte 0x00000482
_08125D00: .4byte 0xFF7FFFFF
_08125D04: .4byte 0x00000716

	thumb_func_start FUN_08125d08
FUN_08125d08: @ 0x08125D08
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0812926c
	adds r0, r4, #0
	bl FUN_081293f4
	adds r0, r4, #0
	bl FUN_08129964
	adds r0, r4, #0
	bl FUN_0812943c
	adds r0, r4, #0
	bl FUN_0812a650
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08125d30
FUN_08125d30: @ 0x08125D30
	push {lr}
	bl FUN_0812a7b4
	movs r0, #1
	pop {r1}
	bx r1

	thumb_func_start FUN_08125d3c
FUN_08125d3c: @ 0x08125D3C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08125D54 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08125D58
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08125D5A
	.align 2, 0
_08125D54: .4byte 0x0000046C
_08125D58:
	movs r0, #0
_08125D5A:
	cmp r0, #0
	beq _08125DF0
	ldr r4, _08125DDC @ =FUN_08122fd0
	movs r3, #0xa
	ldr r2, _08125DE0 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08125DE4 @ =0x0000046B
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
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	strb r0, [r5, #5]
	adds r1, #0x17
	adds r0, r5, r1
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080e5718
	adds r0, r5, #0
	bl FUN_080e6750
	ldr r2, _08125DE8 @ =0x000001DF
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _08125DBC
	movs r0, #4
	ldr r1, _08125DEC @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08125DBC:
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
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
	b _08125E12
	.align 2, 0
_08125DDC: .4byte FUN_08122fd0
_08125DE0: .4byte 0x0000046D
_08125DE4: .4byte 0x0000046B
_08125DE8: .4byte 0x000001DF
_08125DEC: .4byte 0x00000222
_08125DF0:
	ldr r1, _08125E04 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08125E08
	adds r0, r5, #0
	bl FUN_081277d8
	b _08125E12
	.align 2, 0
_08125E04: .4byte 0x0000046B
_08125E08:
	ldr r2, _08125E18 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08125E12:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08125E18: .4byte 0x00000484

	thumb_func_start FUN_08125e1c
FUN_08125e1c: @ 0x08125E1C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x60
	adds r7, r0, #0
	ldr r0, _08125F48 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08125E38
	movs r0, #0
	strb r0, [r1]
_08125E38:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _08125E52
	bl _081266D2
_08125E52:
	ldr r2, _08125F4C @ =0x00000484
	adds r1, r7, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _08125E60
	bl FUN_081266ce
_08125E60:
	ldr r3, _08125F50 @ =0x000001DF
	adds r0, r7, r3
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
	movs r0, #3
	movs r1, #1
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #8]
	strb r0, [r4]
	ldr r5, _08125F54 @ =0x00000469
	adds r5, r7, r5
	str r5, [sp, #0xc]
	strb r1, [r5]
	ldr r0, _08125F58 @ =0x0000046A
	adds r0, r0, r7
	mov sl, r0
	strb r6, [r0]
	ldr r2, _08125F4C @ =0x00000484
	adds r2, r2, r7
	mov sb, r2
	str r6, [r2]
	ldr r3, _08125F48 @ =0x0000046C
	adds r5, r7, r3
	strb r1, [r5]
	ldr r2, _08125F5C @ =FUN_080e6794
	movs r0, #0xe
	ldr r4, _08125F60 @ =0x0000046D
	adds r4, r4, r7
	mov r8, r4
	strb r1, [r4]
	ldr r1, _08125F64 @ =0x0000046B
	adds r1, r1, r7
	mov ip, r1
	strb r6, [r1]
	adds r3, #0xe7
	adds r4, r7, r3
	strb r0, [r4]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r3, r7, r0
	str r2, [r3]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r2, r7, r1
	strh r6, [r2]
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r1, r7, r6
	ldrh r0, [r1]
	movs r6, #0x80
	ands r0, r6
	str r5, [sp, #0x50]
	ldr r5, [sp, #8]
	str r5, [sp, #0x40]
	ldr r6, [sp, #0xc]
	str r6, [sp, #0x44]
	mov r5, sl
	str r5, [sp, #0x48]
	mov r6, sb
	str r6, [sp, #0x5c]
	mov r5, r8
	str r5, [sp, #0x54]
	mov r6, ip
	str r6, [sp, #0x4c]
	str r4, [sp, #0x2c]
	str r3, [sp, #0x30]
	str r2, [sp, #0x34]
	mov r8, r1
	cmp r0, #0
	bne _08125EFA
	b _08126544
_08125EFA:
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	movs r2, #0x80
	orrs r0, r2
	str r0, [r1]
	movs r4, #0x95
	lsls r4, r4, #3
	adds r3, r7, r4
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r6, r3, #0
	mov sb, r2
	cmp r4, #0
	blt _08125F44
	cmp r1, #0
	blt _08125F44
	ldr r0, _08125F68 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _08125F44
	ldr r0, _08125F6C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08125F70
_08125F44:
	movs r4, #0
	b _08125F7E
	.align 2, 0
_08125F48: .4byte 0x0000046C
_08125F4C: .4byte 0x00000484
_08125F50: .4byte 0x000001DF
_08125F54: .4byte 0x00000469
_08125F58: .4byte 0x0000046A
_08125F5C: .4byte FUN_080e6794
_08125F60: .4byte 0x0000046D
_08125F64: .4byte 0x0000046B
_08125F68: .4byte 0x030046A8
_08125F6C: .4byte 0x030046AC
_08125F70:
	ldr r0, _08125F90 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_08125F7E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08125F94
	adds r0, #4
	b _08125FA0
	.align 2, 0
_08125F90: .4byte 0x030046A4
_08125F94:
	ldr r0, _08125FB4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08125FA0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08125FB8
	cmp r2, #2
	beq _08125FBC
	b _08125FC0
	.align 2, 0
_08125FB4: .4byte 0x030046A4
_08125FB8:
	ldrb r0, [r5, #4]
	b _08125FBE
_08125FBC:
	ldrb r0, [r5]
_08125FBE:
	subs r1, r1, r0
_08125FC0:
	strh r1, [r5, #2]
	ldr r0, _08125FD4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08125FD8
	movs r0, #1
	b _08125FDA
	.align 2, 0
_08125FD4: .4byte 0x030047A4
_08125FD8:
	movs r0, #0
_08125FDA:
	cmp r0, #0
	beq _08126018
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _08125FFA
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08125FF6
	adds r2, r0, #0
_08125FF6:
	cmp r2, #0
	bge _08126004
_08125FFA:
	ldr r6, _08126000 @ =0x000005C4
	adds r0, r7, r6
	b _0812645C
	.align 2, 0
_08126000: .4byte 0x000005C4
_08126004:
	ldr r1, _08126014 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08126060
	.align 2, 0
_08126014: .4byte 0x03002BE0
_08126018:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08126044
	cmp r1, #0
	blt _08126044
	ldr r0, _08126048 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08126044
	ldr r0, _0812604C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08126050
_08126044:
	movs r5, #0
	b _0812605E
	.align 2, 0
_08126048: .4byte 0x030046A8
_0812604C: .4byte 0x030046AC
_08126050:
	ldr r0, _08126098 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0812605E:
	movs r2, #0
_08126060:
	ldr r3, _0812609C @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _08126080
	ldr r1, _081260A0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08126080
	b _0812639C
_08126080:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r4, r8
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081260A4
	movs r0, #0
	b _08126472
	.align 2, 0
_08126098: .4byte 0x030046A4
_0812609C: .4byte 0x00000256
_081260A0: .4byte 0x03002BE0
_081260A4:
	ldr r5, _08126100 @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, r8
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	str r2, [sp, #0x3c]
	cmp r3, #0
	beq _08126104
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x54]
	strb r2, [r3]
	ldr r6, [sp, #0x4c]
	strb r5, [r6]
	ldr r3, [sp, #0x2c]
	strb r0, [r3]
	ldr r6, [sp, #0x30]
	str r1, [r6]
	ldr r0, [sp, #0x34]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0x40]
	strb r5, [r1]
	ldr r3, [sp, #0x44]
	strb r5, [r3]
	ldr r5, [sp, #0x48]
	strb r0, [r5]
	ldr r6, [sp, #0x5c]
	str r4, [r6]
	ldr r0, [sp, #0x50]
	strb r2, [r0]
	b _08126252
	.align 2, 0
_08126100: .4byte 0x00000222
_08126104:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x54]
	strb r0, [r2]
	ldr r4, [sp, #0x4c]
	strb r5, [r4]
	ldr r2, [sp, #0x2c]
	strb r0, [r2]
	ldr r4, [sp, #0x30]
	str r1, [r4]
	ldr r1, [sp, #0x34]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x40]
	strb r5, [r2]
	ldr r4, [sp, #0x44]
	strb r5, [r4]
	ldr r5, [sp, #0x48]
	strb r1, [r5]
	ldr r1, [sp, #0x5c]
	str r3, [r1]
	ldr r2, [sp, #0x50]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, sb
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08126168
	cmp r1, #0
	blt _08126168
	ldr r0, _0812616C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08126168
	ldr r0, _08126170 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08126174
_08126168:
	movs r4, #0
	b _08126182
	.align 2, 0
_0812616C: .4byte 0x030046A8
_08126170: .4byte 0x030046AC
_08126174:
	ldr r0, _08126194 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08126182:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08126198
	adds r0, #4
	b _081261A4
	.align 2, 0
_08126194: .4byte 0x030046A4
_08126198:
	ldr r0, _081261B8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081261A4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081261BC
	cmp r2, #2
	beq _081261C0
	b _081261C4
	.align 2, 0
_081261B8: .4byte 0x030046A4
_081261BC:
	ldrb r0, [r5, #4]
	b _081261C2
_081261C0:
	ldrb r0, [r5]
_081261C2:
	subs r1, r1, r0
_081261C4:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081261EC
	cmp r1, #0
	blt _081261EC
	ldr r0, _081261F0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081261EC
	ldr r0, _081261F4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081261F8
_081261EC:
	movs r4, #0
	b _08126206
	.align 2, 0
_081261F0: .4byte 0x030046A8
_081261F4: .4byte 0x030046AC
_081261F8:
	ldr r0, _08126218 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08126206:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812621C
	adds r0, #4
	b _08126228
	.align 2, 0
_08126218: .4byte 0x030046A4
_0812621C:
	ldr r0, _0812623C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08126228:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08126240
	cmp r3, #2
	beq _08126244
	b _08126248
	.align 2, 0
_0812623C: .4byte 0x030046A4
_08126240:
	ldrb r0, [r5, #4]
	b _08126246
_08126244:
	ldrb r0, [r5]
_08126246:
	subs r2, r2, r0
_08126248:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_08126252:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x10]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, r8
	ldrh r0, [r5]
	ands r0, r1
	mov sl, r4
	ldr r6, _0812627C @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x58]
	cmp r0, #0
	bne _08126360
	movs r1, #4
	ldr r2, [sp, #0x3c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08126280
	movs r0, #1
	b _08126282
	.align 2, 0
_0812627C: .4byte 0x00000482
_08126280:
	movs r0, #0
_08126282:
	ldr r3, _08126370 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x58]
	cmp r0, #0
	bne _08126360
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov ip, r5
	ldr r6, _08126374 @ =0x0000054F
	adds r6, r7, r6
	str r6, [sp, #0x28]
	ldr r0, _08126378 @ =0x0000054C
	adds r0, r7, r0
	str r0, [sp, #0x1c]
	ldr r1, _0812637C @ =0x0000054D
	adds r1, r7, r1
	str r1, [sp, #0x20]
	ldr r2, _08126380 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0x24]
	ldr r4, _08126384 @ =0x00000541
	adds r4, r7, r4
	str r4, [sp, #0x14]
	ldr r5, _08126388 @ =0x000005BC
	adds r5, r7, r5
	str r5, [sp, #0x38]
	ldr r6, _0812638C @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0x18]
	ldr r6, _08126390 @ =0x0203B400
	ldr r1, _08126394 @ =0x030046B8
	ldr r5, _08126398 @ =0x000003FF
	movs r2, #3
	mov r4, sl
_081262D2:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	cmp r0, r4
	bne _081262F0
	adds r3, #1
	cmp r3, #3
	ble _081262D2
	mov r0, sl
_081262F0:
	movs r3, #0
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x30]
	ldr r0, [r2]
	mov r4, ip
	str r0, [r4]
	ldr r5, [sp, #0x2c]
	ldrb r0, [r5]
	ldr r6, [sp, #0x28]
	strb r0, [r6]
	ldr r1, [sp, #0x40]
	ldrb r0, [r1]
	ldr r2, [sp, #0x1c]
	strb r0, [r2]
	ldr r4, [sp, #0x44]
	ldrb r0, [r4]
	ldr r5, [sp, #0x20]
	strb r0, [r5]
	ldr r6, [sp, #0x48]
	ldrb r0, [r6]
	ldr r1, [sp, #0x24]
	strb r0, [r1]
	mov r2, sp
	ldrb r4, [r2, #0x10]
	ldr r2, [sp, #0x14]
	strb r4, [r2]
	ldr r5, [sp, #0x38]
	ldr r2, [r5]
	movs r0, #0x1b
	movs r1, #1
	ldr r6, [sp, #0x54]
	strb r1, [r6]
	ldr r4, [sp, #0x4c]
	strb r3, [r4]
	ldr r5, [sp, #0x2c]
	strb r0, [r5]
	ldr r6, [sp, #0x30]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x34]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x40]
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	strb r1, [r5]
	ldr r6, [sp, #0x48]
	strb r2, [r6]
	ldr r0, [sp, #0x5c]
	str r3, [r0]
	ldr r2, [sp, #0x50]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x18]
	strb r0, [r3]
_08126360:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x58]
	strh r0, [r4]
	movs r0, #0
	b _08126472
	.align 2, 0
_08126370: .4byte 0x00000482
_08126374: .4byte 0x0000054F
_08126378: .4byte 0x0000054C
_0812637C: .4byte 0x0000054D
_08126380: .4byte 0x0000054E
_08126384: .4byte 0x00000541
_08126388: .4byte 0x000005BC
_0812638C: .4byte 0x00000542
_08126390: .4byte 0x0203B400
_08126394: .4byte 0x030046B8
_08126398: .4byte 0x000003FF
_0812639C:
	mov sl, sp
	ldr r6, _081263D8 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081263DC
	adds r0, #4
	b _081263E6
	.align 2, 0
_081263D8: .4byte 0x030046A4
_081263DC:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081263E6:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sl
	strh r0, [r4, #2]
	mov r5, sb
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _08126420 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _08126428
	ldr r0, _08126424 @ =0xFFFFFDFF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08126452
	.align 2, 0
_08126420: .4byte 0x000004A4
_08126424: .4byte 0xFFFFFDFF
_08126428:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08126448
	cmp r0, #2
	beq _08126444
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08126444:
	movs r0, #1
	b _08126454
_08126448:
	ldr r0, _08126468 @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08126452:
	movs r0, #0
_08126454:
	cmp r0, #0
	bne _08126470
	ldr r4, _0812646C @ =0x000005C4
	adds r0, r7, r4
_0812645C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _08126472
	.align 2, 0
_08126468: .4byte 0xFFFFFDFF
_0812646C: .4byte 0x000005C4
_08126470:
	movs r0, #1
_08126472:
	cmp r0, #0
	bne _081264F8
	ldr r5, _081264A8 @ =0x000004A4
	adds r0, r7, r5
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081264B0
	ldr r0, _081264AC @ =0xFFFFFDFF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081264DA
	.align 2, 0
_081264A8: .4byte 0x000004A4
_081264AC: .4byte 0xFFFFFDFF
_081264B0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081264D0
	cmp r0, #2
	beq _081264CC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081264CC:
	movs r0, #1
	b _081264DC
_081264D0:
	ldr r0, _081264F0 @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081264DA:
	movs r0, #0
_081264DC:
	cmp r0, #0
	bne _081264F8
	ldr r4, _081264F4 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081266D2
	.align 2, 0
_081264F0: .4byte 0xFFFFFDFF
_081264F4: .4byte 0x000005C4
_081264F8:
	movs r0, #4
	ldr r5, _08126538 @ =0x00000222
	adds r2, r7, r5
	ldrh r1, [r2]
	movs r4, #0
	orrs r0, r1
	strh r0, [r2]
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r3, [r0]
	movs r5, #0xc
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	subs r6, #0x64
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _0812653C @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _08126540 @ =0x00000552
	adds r0, r7, r3
	strb r5, [r0]
	b _081266D2
	.align 2, 0
_08126538: .4byte 0x00000222
_0812653C: .4byte 0x00000551
_08126540: .4byte 0x00000552
_08126544:
	movs r2, #0x10
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x1e
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r7, r6
	subs r5, #0x4c
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	subs r6, #8
	adds r0, r7, r6
	movs r1, #0
	strb r1, [r0]
	ldr r2, _081265BC @ =0x00000551
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _081265C0 @ =0x00000552
	adds r0, r7, r3
	strb r4, [r0]
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r5, [r0]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081265B8
	cmp r1, #0
	blt _081265B8
	ldr r0, _081265C4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081265B8
	ldr r0, _081265C8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081265CC
_081265B8:
	movs r4, #0
	b _081265DA
	.align 2, 0
_081265BC: .4byte 0x00000551
_081265C0: .4byte 0x00000552
_081265C4: .4byte 0x030046A8
_081265C8: .4byte 0x030046AC
_081265CC:
	ldr r0, _081265EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081265DA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081265F0
	adds r0, #4
	b _081265FC
	.align 2, 0
_081265EC: .4byte 0x030046A4
_081265F0:
	ldr r0, _08126610 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081265FC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08126614
	cmp r2, #2
	beq _08126618
	b _0812661C
	.align 2, 0
_08126610: .4byte 0x030046A4
_08126614:
	ldrb r0, [r5, #4]
	b _0812661A
_08126618:
	ldrb r0, [r5]
_0812661A:
	subs r1, r1, r0
_0812661C:
	strh r1, [r5, #2]
	ldr r5, _0812664C @ =0x000004A4
	adds r0, r7, r5
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08126654
	ldr r0, _08126650 @ =0xFFFFFDFF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0812667E
	.align 2, 0
_0812664C: .4byte 0x000004A4
_08126650: .4byte 0xFFFFFDFF
_08126654:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08126674
	cmp r0, #2
	beq _08126670
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08126670:
	movs r0, #1
	b _08126680
_08126674:
	ldr r0, _081266B8 @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0812667E:
	movs r0, #0
_08126680:
	adds r3, r0, #0
	cmp r3, #0
	bne _081266C0
	ldr r0, _081266BC @ =FUN_080e48d0
	movs r2, #1
	ldr r4, [sp, #0x54]
	strb r2, [r4]
	ldr r5, [sp, #0x4c]
	strb r3, [r5]
	ldr r6, [sp, #0x2c]
	strb r3, [r6]
	ldr r1, [sp, #0x30]
	str r0, [r1]
	movs r1, #0
	ldr r4, [sp, #0x34]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x40]
	strb r0, [r5]
	ldr r6, [sp, #0x44]
	strb r1, [r6]
	ldr r0, [sp, #0x48]
	strb r1, [r0]
	ldr r1, [sp, #0x5c]
	str r3, [r1]
	ldr r3, [sp, #0x50]
	strb r2, [r3]
	b _081266D2
	.align 2, 0
_081266B8: .4byte 0xFFFFFDFF
_081266BC: .4byte FUN_080e48d0
_081266C0:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	b _081266D2

	non_word_aligned_thumb_func_start FUN_081266ce
FUN_081266ce: @ 0x081266CE
	adds r0, #1
	str r0, [r1]
_081266D2:
	add sp, #0x60
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081266e4
FUN_081266e4: @ 0x081266E4
	movs r1, #0xc7
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, _081266F0 @ =0x085AD63C
	str r1, [r0]
	bx lr
	.align 2, 0
_081266F0: .4byte 0x085AD63C

	thumb_func_start FUN_081266f4
FUN_081266f4: @ 0x081266F4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08126764 @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08126706
	movs r0, #0
	strb r0, [r1]
_08126706:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _08126778
	ldr r0, _08126768 @ =0x00000484
	adds r2, r4, r0
	ldr r1, _0812676C @ =0x0000024E
	adds r0, r4, r1
	ldr r1, [r2]
	ldrh r0, [r0]
	cmp r1, r0
	blt _08126774
	ldr r2, _08126770 @ =0x000001DF
	adds r0, r4, r2
	ldrb r3, [r0]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _08126768 @ =0x00000484
	adds r0, r4, r1
	str r5, [r0]
	adds r2, #2
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	b _08126778
	.align 2, 0
_08126764: .4byte 0x0000046C
_08126768: .4byte 0x00000484
_0812676C: .4byte 0x0000024E
_08126770: .4byte 0x000001DF
_08126774:
	adds r0, r1, #1
	str r0, [r2]
_08126778:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08126780
FUN_08126780: @ 0x08126780
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _081267A8 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081267AC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081267AE
	.align 2, 0
_081267A8: .4byte 0x0000046C
_081267AC:
	movs r0, #0
_081267AE:
	cmp r0, #0
	beq _081267BE
	ldr r3, _08126804 @ =0x0000071E
	adds r0, r7, r3
	ldr r1, _08126808 @ =0xFFFFEFFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_081267BE:
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081267D4
	b _08126B1E
_081267D4:
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r2, _0812680C @ =0x0000A02F
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _08126814
	ldr r4, _08126810 @ =0x00000482
	adds r1, r5, r4
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08126824
	.align 2, 0
_08126804: .4byte 0x0000071E
_08126808: .4byte 0xFFFFEFFF
_0812680C: .4byte 0x0000A02F
_08126810: .4byte 0x00000482
_08126814:
	ldr r1, _08126848 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08126824
	movs r0, #1
	strh r0, [r2]
_08126824:
	ldr r3, _0812684C @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08126850
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
	b _08126868
	.align 2, 0
_08126848: .4byte 0x00000482
_0812684C: .4byte 0x0000025D
_08126850:
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
_08126868:
	ldr r0, _081268A4 @ =0x000004A4
	adds r4, r5, r0
	ldr r0, [r4]
	bl FUN_08235fd8
	cmp r0, #0
	bne _08126878
	b _08126AA0
_08126878:
	ldr r1, [r4]
	str r6, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0812688E
	b _08126B14
_0812688E:
	movs r2, #4
	ldr r3, _081268A8 @ =0x00000222
	adds r1, r5, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081268AC
	movs r0, #1
	b _081268AE
	.align 2, 0
_081268A4: .4byte 0x000004A4
_081268A8: .4byte 0x00000222
_081268AC:
	movs r0, #0
_081268AE:
	cmp r0, #0
	beq _081268B4
	b _08126A70
_081268B4:
	adds r0, r5, #0
	bl FUN_080eb2a0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081268C2
	b _08126B1E
_081268C2:
	movs r1, #1
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081268D0
	movs r0, #1
	b _081268D2
_081268D0:
	movs r0, #0
_081268D2:
	cmp r0, #0
	bne _081268D8
	b _08126A70
_081268D8:
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	str r0, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r2, r8
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081268FA
	b _08126B1E
_081268FA:
	movs r1, #4
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08126908
	movs r0, #1
	b _0812690A
_08126908:
	movs r0, #0
_0812690A:
	cmp r0, #0
	beq _08126910
	b _08126B1E
_08126910:
	movs r4, #0
	ldr r3, _08126A2C @ =0x0000046C
	adds r3, r5, r3
	str r3, [sp, #0x14]
	ldrb r7, [r5, #5]
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r0, r5, r0
	str r0, [sp, #0x24]
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r5, r1
	str r1, [sp, #0x30]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r2, r5
	mov sb, r2
	ldr r3, _08126A30 @ =0x00000553
	adds r3, r3, r5
	mov ip, r3
	ldr r0, _08126A34 @ =0x0000054F
	adds r0, r5, r0
	str r0, [sp, #0x40]
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r1, r5, r1
	str r1, [sp, #0xc]
	ldr r2, _08126A38 @ =0x0000054C
	adds r2, r5, r2
	str r2, [sp, #0x34]
	ldr r3, _08126A3C @ =0x00000469
	adds r3, r3, r5
	mov sl, r3
	ldr r0, _08126A40 @ =0x0000054D
	adds r0, r5, r0
	str r0, [sp, #0x38]
	ldr r1, _08126A44 @ =0x0000046A
	adds r1, r1, r5
	mov r8, r1
	ldr r2, _08126A48 @ =0x0000054E
	adds r2, r5, r2
	str r2, [sp, #0x3c]
	ldr r3, _08126A4C @ =0x00000541
	adds r3, r5, r3
	str r3, [sp, #0x28]
	ldr r0, _08126A50 @ =0x000005BC
	adds r0, r5, r0
	str r0, [sp, #0x1c]
	ldr r1, _08126A54 @ =0x0000046D
	adds r1, r5, r1
	str r1, [sp, #0x18]
	ldr r2, _08126A58 @ =0x0000046B
	adds r2, r5, r2
	str r2, [sp, #0x10]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r5, r3
	str r3, [sp, #8]
	ldr r0, _08126A5C @ =0x00000484
	adds r0, r5, r0
	str r0, [sp, #0x20]
	ldr r1, _08126A60 @ =0x00000542
	adds r1, r5, r1
	str r1, [sp, #0x2c]
	ldr r6, _08126A64 @ =0x0203B400
	ldr r1, _08126A68 @ =0x030046B8
	ldr r2, _08126A6C @ =0x000003FF
	movs r5, #3
	adds r3, r7, #0
_0812699A:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r5
	lsls r0, r0, #6
	cmp r0, r3
	bne _081269B8
	adds r4, #1
	cmp r4, #3
	ble _0812699A
	adds r0, r7, #0
_081269B8:
	movs r3, #0
	ldr r2, [sp, #0x24]
	strb r0, [r2]
	mov r4, sb
	ldr r0, [r4]
	ldr r1, [sp, #0x30]
	str r0, [r1]
	mov r2, ip
	ldrb r0, [r2]
	ldr r4, [sp, #0x40]
	strb r0, [r4]
	ldr r1, [sp, #0xc]
	ldrb r0, [r1]
	ldr r2, [sp, #0x34]
	strb r0, [r2]
	mov r4, sl
	ldrb r0, [r4]
	ldr r1, [sp, #0x38]
	strb r0, [r1]
	mov r2, r8
	ldrb r0, [r2]
	ldr r4, [sp, #0x3c]
	strb r0, [r4]
	mov r0, sp
	ldrb r1, [r0, #4]
	ldr r0, [sp, #0x28]
	strb r1, [r0]
	ldr r4, [sp, #0x1c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x18]
	strb r1, [r4]
	ldr r4, [sp, #0x10]
	strb r3, [r4]
	mov r4, ip
	strb r0, [r4]
	mov r0, sb
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #8]
	strh r3, [r4]
	movs r0, #3
	ldr r4, [sp, #0xc]
	strb r0, [r4]
	mov r0, sl
	strb r1, [r0]
	mov r4, r8
	strb r2, [r4]
	ldr r0, [sp, #0x20]
	str r3, [r0]
	ldr r2, [sp, #0x14]
	strb r1, [r2]
	movs r0, #2
	ldr r3, [sp, #0x2c]
	strb r0, [r3]
	b _08126B1E
	.align 2, 0
_08126A2C: .4byte 0x0000046C
_08126A30: .4byte 0x00000553
_08126A34: .4byte 0x0000054F
_08126A38: .4byte 0x0000054C
_08126A3C: .4byte 0x00000469
_08126A40: .4byte 0x0000054D
_08126A44: .4byte 0x0000046A
_08126A48: .4byte 0x0000054E
_08126A4C: .4byte 0x00000541
_08126A50: .4byte 0x000005BC
_08126A54: .4byte 0x0000046D
_08126A58: .4byte 0x0000046B
_08126A5C: .4byte 0x00000484
_08126A60: .4byte 0x00000542
_08126A64: .4byte 0x0203B400
_08126A68: .4byte 0x030046B8
_08126A6C: .4byte 0x000003FF
_08126A70:
	movs r2, #0xd
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08126A98 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08126A9C @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _08126B14
	.align 2, 0
_08126A98: .4byte 0x00000469
_08126A9C: .4byte 0x00000484
_08126AA0:
	ldr r1, [r4]
	str r6, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5ed4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08126B14
	ldr r0, _08126B00 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #8
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _08126AD8
	ldr r4, _08126B04 @ =0x000006FE
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r0, #0
	bne _08126AD8
	adds r0, r5, #0
	bl FUN_081282c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08126B1E
_08126AD8:
	movs r2, #0xe
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08126B08 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _08126B0C @ =0x0000046A
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08126B10 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _08126B1E
	.align 2, 0
_08126B00: .4byte 0x03002BE0
_08126B04: .4byte 0x000006FE
_08126B08: .4byte 0x00000469
_08126B0C: .4byte 0x0000046A
_08126B10: .4byte 0x00000484
_08126B14:
	ldr r4, _08126B30 @ =0x00000484
	adds r1, r5, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08126B1E:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08126B30: .4byte 0x00000484

	thumb_func_start FUN_08126b34
FUN_08126b34: @ 0x08126B34
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x64
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #8]
	ldr r2, _08126B60 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08126B64
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08126B66
	.align 2, 0
_08126B60: .4byte 0x0000046C
_08126B64:
	movs r0, #0
_08126B66:
	cmp r0, #0
	beq _08126BBA
	ldr r3, _08126D34 @ =0x000005A4
	adds r0, r7, r3
	ldr r2, [r0]
	movs r3, #0
	ldr r4, _08126D38 @ =0x0000046D
	adds r1, r7, r4
	movs r0, #1
	strb r0, [r1]
	ldr r5, _08126D3C @ =0x0000046B
	adds r0, r7, r5
	strb r3, [r0]
	ldr r6, _08126D40 @ =0x00000553
	adds r0, r7, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r3, [r0]
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldr r0, _08126D44 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r2, r7, r5
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r6, _08126D48 @ =0x00000202
	adds r0, r7, r6
	strh r3, [r0]
_08126BBA:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
	cmp r0, #0
	beq _08126BD4
	b _081272C0
_08126BD4:
	ldr r2, _08126D4C @ =0x00000484
	adds r1, r7, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _08126BE0
	b _081272BC
_08126BE0:
	ldr r3, _08126D50 @ =0x00000222
	adds r3, r3, r7
	mov r8, r3
	movs r0, #7
	rsbs r0, r0, #0
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	ldr r1, _08126D54 @ =FUN_080e6794
	movs r0, #0xe
	ldr r4, _08126D38 @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0xc]
	movs r4, #1
	ldr r5, [sp, #0xc]
	strb r4, [r5]
	ldr r6, _08126D3C @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x10]
	movs r2, #0
	strb r2, [r6]
	ldr r3, _08126D40 @ =0x00000553
	adds r3, r7, r3
	str r3, [sp, #0x14]
	strb r0, [r3]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r6, r7
	mov sb, r6
	mov r0, ip
	strh r0, [r6]
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r5, #0xc
	movs r1, #0x1e
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r7, r6
	subs r6, #4
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _08126D58 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r5, [r0]
	movs r0, #3
	subs r1, #0xe8
	adds r1, r7, r1
	str r1, [sp, #0x60]
	strb r0, [r1]
	ldr r2, _08126D5C @ =0x00000469
	adds r5, r7, r2
	strb r4, [r5]
	subs r6, #0xe8
	adds r3, r7, r6
	movs r0, #0
	strb r0, [r3]
	ldr r1, _08126D4C @ =0x00000484
	adds r2, r7, r1
	mov r6, ip
	str r6, [r2]
	ldr r0, _08126D60 @ =0x0000046C
	adds r1, r7, r0
	strb r4, [r1]
	ldr r4, [sp, #8]
	ldr r6, _08126D64 @ =0x000006FE
	adds r0, r4, r6
	ldrh r0, [r0]
	str r1, [sp, #0x4c]
	ldr r1, [sp, #0xc]
	str r1, [sp, #0x50]
	ldr r4, [sp, #0x10]
	str r4, [sp, #0x48]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x30]
	mov r1, sl
	str r1, [sp, #0x34]
	mov r4, sb
	str r4, [sp, #0x5c]
	ldr r6, [sp, #0x60]
	str r6, [sp, #0x3c]
	str r5, [sp, #0x40]
	str r3, [sp, #0x44]
	str r2, [sp, #0x58]
	cmp r0, #0
	beq _08126D7C
	ldr r0, _08126D68 @ =0x00000256
	adds r2, r7, r0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x18]
	ldrh r0, [r2]
	ldrh r1, [r1, #6]
	cmp r0, r1
	bne _08126D7C
	adds r0, r7, #0
	bl FUN_081282c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08126CCE
	b _081272C0
_08126CCE:
	ldr r4, [r7, #0x24]
	ldr r2, _08126D6C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08126D70 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08126D74 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	asrs r0, r0, #3
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r3, [r4, #2]
	cmp r0, r3
	bne _08126D06
	adds r0, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_08126D06:
	strb r0, [r4, #2]
	movs r5, #0
	strb r5, [r4, #3]
	ldr r0, _08126D78 @ =0x030046A4
	ldr r0, [r0]
	ldr r1, [r0, #0x10]
	ldr r0, [r4, #4]
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	ldrb r0, [r4, #2]
	lsls r0, r0, #3
	adds r1, r1, r0
	str r1, [r4, #8]
	adds r0, r7, #0
	bl FUN_080e6204
	movs r0, #4
	mov r6, r8
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	b _081272C0
	.align 2, 0
_08126D34: .4byte 0x000005A4
_08126D38: .4byte 0x0000046D
_08126D3C: .4byte 0x0000046B
_08126D40: .4byte 0x00000553
_08126D44: .4byte 0xFFFFFDFF
_08126D48: .4byte 0x00000202
_08126D4C: .4byte 0x00000484
_08126D50: .4byte 0x00000222
_08126D54: .4byte FUN_080e6794
_08126D58: .4byte 0x00000551
_08126D5C: .4byte 0x00000469
_08126D60: .4byte 0x0000046C
_08126D64: .4byte 0x000006FE
_08126D68: .4byte 0x00000256
_08126D6C: .4byte 0x030046B8
_08126D70: .4byte 0x000003FF
_08126D74: .4byte 0x0203B400
_08126D78: .4byte 0x030046A4
_08126D7C:
	movs r0, #0x95
	lsls r0, r0, #3
	adds r3, r7, r0
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r6, r3, #0
	mov sb, r2
	cmp r4, #0
	blt _08126DB8
	cmp r1, #0
	blt _08126DB8
	ldr r0, _08126DBC @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _08126DB8
	ldr r0, _08126DC0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08126DC4
_08126DB8:
	movs r4, #0
	b _08126DD2
	.align 2, 0
_08126DBC: .4byte 0x030046A8
_08126DC0: .4byte 0x030046AC
_08126DC4:
	ldr r0, _08126DE4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_08126DD2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08126DE8
	adds r0, #4
	b _08126DF4
	.align 2, 0
_08126DE4: .4byte 0x030046A4
_08126DE8:
	ldr r0, _08126E08 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08126DF4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08126E0C
	cmp r2, #2
	beq _08126E10
	b _08126E14
	.align 2, 0
_08126E08: .4byte 0x030046A4
_08126E0C:
	ldrb r0, [r5, #4]
	b _08126E12
_08126E10:
	ldrb r0, [r5]
_08126E12:
	subs r1, r1, r0
_08126E14:
	strh r1, [r5, #2]
	ldr r0, _08126E28 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08126E2C
	movs r0, #1
	b _08126E2E
	.align 2, 0
_08126E28: .4byte 0x030047A4
_08126E2C:
	movs r0, #0
_08126E2E:
	cmp r0, #0
	beq _08126E6C
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08126E4E
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08126E4A
	adds r2, r0, #0
_08126E4A:
	cmp r2, #0
	bge _08126E58
_08126E4E:
	ldr r2, _08126E54 @ =0x000005C4
	adds r0, r7, r2
	b _081272A8
	.align 2, 0
_08126E54: .4byte 0x000005C4
_08126E58:
	ldr r1, _08126E68 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08126EB4
	.align 2, 0
_08126E68: .4byte 0x03002BE0
_08126E6C:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08126E98
	cmp r1, #0
	blt _08126E98
	ldr r0, _08126E9C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08126E98
	ldr r0, _08126EA0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08126EA4
_08126E98:
	movs r5, #0
	b _08126EB2
	.align 2, 0
_08126E9C: .4byte 0x030046A8
_08126EA0: .4byte 0x030046AC
_08126EA4:
	ldr r0, _08126F44 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08126EB2:
	movs r2, #0
_08126EB4:
	ldr r4, _08126F48 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _08126ED4
	ldr r1, _08126F4C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08126ED4
	b _081271EC
_08126ED4:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	mov sl, r2
	cmp r3, #0
	beq _08126EEE
	b _081272C0
_08126EEE:
	movs r0, #5
	rsbs r0, r0, #0
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	movs r4, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _08126F50
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r5, [sp, #0x50]
	strb r2, [r5]
	ldr r6, [sp, #0x48]
	strb r4, [r6]
	ldr r5, [sp, #0x30]
	strb r0, [r5]
	ldr r6, [sp, #0x34]
	str r1, [r6]
	ldr r0, [sp, #0x5c]
	strh r3, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0x3c]
	strb r4, [r1]
	ldr r5, [sp, #0x40]
	strb r4, [r5]
	ldr r6, [sp, #0x44]
	strb r0, [r6]
	ldr r0, [sp, #0x58]
	str r3, [r0]
	ldr r1, [sp, #0x4c]
	strb r2, [r1]
	b _081270A2
	.align 2, 0
_08126F44: .4byte 0x030046A4
_08126F48: .4byte 0x00000256
_08126F4C: .4byte 0x03002BE0
_08126F50:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #1
	ldr r5, [sp, #0x50]
	strb r0, [r5]
	ldr r3, [sp, #0x48]
	strb r4, [r3]
	ldr r5, [sp, #0x30]
	strb r0, [r5]
	ldr r3, [sp, #0x34]
	str r1, [r3]
	ldr r5, [sp, #0x5c]
	strh r2, [r5]
	movs r1, #5
	ldr r3, [sp, #0x3c]
	strb r4, [r3]
	ldr r5, [sp, #0x40]
	strb r4, [r5]
	ldr r3, [sp, #0x44]
	strb r1, [r3]
	ldr r4, [sp, #0x58]
	str r2, [r4]
	ldr r5, [sp, #0x4c]
	strb r0, [r5]
	ldr r5, [r6]
	mov r1, sb
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	mov r2, sb
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08126FB6
	cmp r1, #0
	blt _08126FB6
	ldr r0, _08126FBC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08126FB6
	ldr r0, _08126FC0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08126FC4
_08126FB6:
	movs r4, #0
	b _08126FD2
	.align 2, 0
_08126FBC: .4byte 0x030046A8
_08126FC0: .4byte 0x030046AC
_08126FC4:
	ldr r0, _08126FE4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08126FD2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08126FE8
	adds r0, #4
	b _08126FF4
	.align 2, 0
_08126FE4: .4byte 0x030046A4
_08126FE8:
	ldr r0, _08127008 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08126FF4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812700C
	cmp r2, #2
	beq _08127010
	b _08127014
	.align 2, 0
_08127008: .4byte 0x030046A4
_0812700C:
	ldrb r0, [r5, #4]
	b _08127012
_08127010:
	ldrb r0, [r5]
_08127012:
	subs r1, r1, r0
_08127014:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0812703C
	cmp r1, #0
	blt _0812703C
	ldr r0, _08127040 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0812703C
	ldr r0, _08127044 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08127048
_0812703C:
	movs r4, #0
	b _08127056
	.align 2, 0
_08127040: .4byte 0x030046A8
_08127044: .4byte 0x030046AC
_08127048:
	ldr r0, _08127068 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08127056:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812706C
	adds r0, #4
	b _08127078
	.align 2, 0
_08127068: .4byte 0x030046A4
_0812706C:
	ldr r0, _0812708C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08127078:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08127090
	cmp r3, #2
	beq _08127094
	b _08127098
	.align 2, 0
_0812708C: .4byte 0x030046A4
_08127090:
	ldrb r0, [r5, #4]
	b _08127096
_08127094:
	ldrb r0, [r5]
_08127096:
	subs r2, r2, r0
_08127098:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081270A2:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	mov sb, r3
	ldr r5, _081270CC @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x54]
	cmp r0, #0
	bne _081271B0
	movs r1, #4
	mov r6, r8
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081270D0
	movs r0, #1
	b _081270D2
	.align 2, 0
_081270CC: .4byte 0x00000482
_081270D0:
	movs r0, #0
_081270D2:
	ldr r1, _081271C0 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x54]
	cmp r0, #0
	bne _081271B0
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r2, r2, r7
	mov r8, r2
	movs r4, #0xa9
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sl, r4
	ldr r5, _081271C4 @ =0x0000054F
	adds r5, r5, r7
	mov ip, r5
	ldr r6, _081271C8 @ =0x0000054C
	adds r6, r7, r6
	str r6, [sp, #0x24]
	ldr r0, _081271CC @ =0x0000054D
	adds r0, r7, r0
	str r0, [sp, #0x28]
	ldr r1, _081271D0 @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x2c]
	ldr r2, _081271D4 @ =0x00000541
	adds r2, r7, r2
	str r2, [sp, #0x1c]
	ldr r4, _081271D8 @ =0x000005BC
	adds r4, r7, r4
	str r4, [sp, #0x38]
	ldr r5, _081271DC @ =0x00000542
	adds r5, r7, r5
	str r5, [sp, #0x20]
	ldr r6, _081271E0 @ =0x0203B400
	ldr r1, _081271E4 @ =0x030046B8
	ldr r5, _081271E8 @ =0x000003FF
	movs r2, #3
	mov r4, sb
_08127122:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	cmp r0, r4
	bne _08127140
	adds r3, #1
	cmp r3, #3
	ble _08127122
	mov r0, sb
_08127140:
	movs r3, #0
	mov r6, r8
	strb r0, [r6]
	ldr r1, [sp, #0x34]
	ldr r0, [r1]
	mov r2, sl
	str r0, [r2]
	ldr r4, [sp, #0x30]
	ldrb r0, [r4]
	mov r5, ip
	strb r0, [r5]
	ldr r6, [sp, #0x3c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x24]
	strb r0, [r1]
	ldr r2, [sp, #0x40]
	ldrb r0, [r2]
	ldr r4, [sp, #0x28]
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	ldrb r0, [r5]
	ldr r6, [sp, #0x2c]
	strb r0, [r6]
	mov r0, sp
	ldrb r1, [r0, #0x18]
	ldr r0, [sp, #0x1c]
	strb r1, [r0]
	ldr r4, [sp, #0x38]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x50]
	strb r1, [r5]
	ldr r6, [sp, #0x48]
	strb r3, [r6]
	ldr r4, [sp, #0x30]
	strb r0, [r4]
	ldr r5, [sp, #0x34]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x5c]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x3c]
	strb r0, [r4]
	ldr r5, [sp, #0x40]
	strb r1, [r5]
	ldr r6, [sp, #0x44]
	strb r2, [r6]
	ldr r0, [sp, #0x58]
	str r3, [r0]
	ldr r2, [sp, #0x4c]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x20]
	strb r0, [r3]
_081271B0:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x54]
	strh r0, [r4]
	b _081272C0
	.align 2, 0
_081271C0: .4byte 0x00000482
_081271C4: .4byte 0x0000054F
_081271C8: .4byte 0x0000054C
_081271CC: .4byte 0x0000054D
_081271D0: .4byte 0x0000054E
_081271D4: .4byte 0x00000541
_081271D8: .4byte 0x000005BC
_081271DC: .4byte 0x00000542
_081271E0: .4byte 0x0203B400
_081271E4: .4byte 0x030046B8
_081271E8: .4byte 0x000003FF
_081271EC:
	mov sb, sp
	ldr r6, _08127228 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812722C
	adds r0, #4
	b _08127236
	.align 2, 0
_08127228: .4byte 0x030046A4
_0812722C:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08127236:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _0812726C @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _08127270
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _08127296
	.align 2, 0
_0812726C: .4byte 0x000004A4
_08127270:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08127290
	cmp r0, #2
	beq _0812728C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0812728C:
	movs r0, #1
	b _081272A0
_08127290:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_08127296:
	ldr r1, _081272B4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081272A0:
	cmp r0, #0
	bne _081272C0
	ldr r3, _081272B8 @ =0x000005C4
	adds r0, r7, r3
_081272A8:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081272C0
	.align 2, 0
_081272B4: .4byte 0xFFFFFDFF
_081272B8: .4byte 0x000005C4
_081272BC:
	adds r0, #1
	str r0, [r1]
_081272C0:
	add sp, #0x64
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081272d0
FUN_081272d0: @ 0x081272D0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _08127328 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081272E4
	movs r0, #0
	strb r0, [r1]
_081272E4:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081272FA
	b _08127424
_081272FA:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r1, _0812732C @ =0x0000A02F
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08127334
	ldr r0, _08127330 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08127344
	.align 2, 0
_08127328: .4byte 0x0000046C
_0812732C: .4byte 0x0000A02F
_08127330: .4byte 0x00000482
_08127334:
	ldr r1, _08127368 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08127344
	movs r0, #1
	strh r0, [r2]
_08127344:
	ldr r3, _0812736C @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08127370
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
	b _08127388
	.align 2, 0
_08127368: .4byte 0x00000482
_0812736C: .4byte 0x0000025D
_08127370:
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
_08127388:
	ldr r0, _081273D4 @ =0x000004A4
	adds r4, r5, r0
	ldr r0, [r4]
	bl FUN_08235fd8
	adds r6, r0, #0
	cmp r6, #0
	bne _081273E0
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5ed4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812741A
	movs r1, #0x12
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r6, [r0]
	ldr r3, _081273D8 @ =0x00000469
	adds r0, r5, r3
	strb r6, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r6, [r0]
	ldr r0, _081273DC @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _08127424
	.align 2, 0
_081273D4: .4byte 0x000004A4
_081273D8: .4byte 0x00000469
_081273DC: .4byte 0x0000046C
_081273E0:
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812741A
	movs r2, #0x11
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0812742C @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _08127430 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
_0812741A:
	ldr r0, _08127430 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08127424:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812742C: .4byte 0x00000469
_08127430: .4byte 0x00000484

	thumb_func_start FUN_08127434
FUN_08127434: @ 0x08127434
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _0812744C @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08127450
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08127452
	.align 2, 0
_0812744C: .4byte 0x0000046C
_08127450:
	movs r0, #0
_08127452:
	cmp r0, #0
	beq _08127486
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _081274FC @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _08127500 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _08127504 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_08127486:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _0812751A
	ldr r6, _08127500 @ =0x0000046B
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _08127510
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0x10
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r4, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r4, [r0]
	ldr r1, _08127508 @ =0x0000046C
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0812750C @ =FUN_081251f4
	movs r2, #0x26
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08127500 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	b _0812751A
	.align 2, 0
_081274FC: .4byte 0x0000046D
_08127500: .4byte 0x0000046B
_08127504: .4byte 0x00000553
_08127508: .4byte 0x0000046C
_0812750C: .4byte FUN_081251f4
_08127510:
	ldr r6, _08127520 @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0812751A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08127520: .4byte 0x00000484

	thumb_func_start FUN_08127524
FUN_08127524: @ 0x08127524
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0812753C @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08127540
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08127542
	.align 2, 0
_0812753C: .4byte 0x0000046C
_08127540:
	movs r0, #0
_08127542:
	cmp r0, #0
	beq _0812756E
	ldr r4, _08127594 @ =FUN_081251f4
	movs r3, #0x26
	ldr r0, _08127598 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0812759C @ =0x0000046B
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
_0812756E:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0812758C
	ldr r0, _081275A0 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0812758C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08127594: .4byte FUN_081251f4
_08127598: .4byte 0x0000046D
_0812759C: .4byte 0x0000046B
_081275A0: .4byte 0x00000484

	thumb_func_start FUN_081275a4
FUN_081275a4: @ 0x081275A4
	ldr r1, _081275B0 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _081275B4 @ =0x085AD644
	str r1, [r0]
	bx lr
	.align 2, 0
_081275B0: .4byte 0x00000634
_081275B4: .4byte 0x085AD644

	thumb_func_start FUN_081275b8
FUN_081275b8: @ 0x081275B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r2, [sp, #0x14]
	asrs r1, r2, #0x10
	adds r1, #0xc8
	lsls r1, r1, #0x10
	ldr r0, _08127600 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
	asrs r0, r0, #0x10
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r1, [r1]
	movs r2, #0xa
	ldrsh r1, [r1, r2]
	subs r1, r0, r1
	cmp r1, #0xff
	bgt _08127604
	movs r6, #0xf
	b _0812762E
	.align 2, 0
_08127600: .4byte 0x0000FFFF
_08127604:
	ldr r0, _08127610 @ =0x000001FF
	cmp r1, r0
	bgt _08127614
	movs r6, #0x14
	b _0812762E
	.align 2, 0
_08127610: .4byte 0x000001FF
_08127614:
	ldr r0, _08127620 @ =0x000002FF
	cmp r1, r0
	bgt _08127624
	movs r6, #0x17
	b _0812762E
	.align 2, 0
_08127620: .4byte 0x000002FF
_08127624:
	ldr r0, _081276B4 @ =0x000003FF
	movs r6, #0x22
	cmp r1, r0
	bgt _0812762E
	movs r6, #0x1b
_0812762E:
	add r4, sp, #0xc
	adds r3, r5, #0
	adds r3, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	adds r1, r4, #0
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	adds r0, r4, #0
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r3, r1, #0
	cmp r1, #0
	bge _08127668
	rsbs r3, r1, #0
_08127668:
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r2, r0, #0
	cmp r0, #0
	bge _08127674
	rsbs r2, r0, #0
_08127674:
	cmp r3, r2
	ble _0812767A
	adds r0, r1, #0
_0812767A:
	adds r1, r6, #0
	bl Div
	adds r4, r0, #0
	adds r0, r4, #0
	cmp r4, #0
	bge _0812768A
	rsbs r0, r4, #0
_0812768A:
	adds r4, r0, #0
	cmp r4, #0xa
	bgt _08127692
	movs r4, #0xa
_08127692:
	movs r1, #0xdf
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r4, r0
	ble _081276A0
	adds r4, r0, #0
_081276A0:
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _081276B8
	cmp r0, #1
	beq _081276BC
	movs r3, #3
	b _081276BE
	.align 2, 0
_081276B4: .4byte 0x000003FF
_081276B8:
	movs r3, #1
	b _081276BE
_081276BC:
	movs r3, #2
_081276BE:
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r2, r0, #6
	adds r1, #0xfd
	adds r0, r5, r1
	ldrb r0, [r0]
	subs r1, r0, r2
	cmp r1, #0x80
	ble _081276E0
	ldr r0, _081276DC @ =0xFFFFFF00
	b _081276EC
	.align 2, 0
_081276DC: .4byte 0xFFFFFF00
_081276E0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081276EE
	movs r0, #0x80
	lsls r0, r0, #1
_081276EC:
	adds r1, r1, r0
_081276EE:
	adds r6, r1, #0
	adds r0, r6, #0
	cmp r6, #0
	bge _081276F8
	rsbs r0, r6, #0
_081276F8:
	cmp r0, #0x1c
	ble _08127700
	adds r6, r2, #0
	b _08127708
_08127700:
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r6, [r0]
_08127708:
	ldr r2, _08127748 @ =0x000006FA
	adds r0, r7, r2
	ldrh r0, [r0]
	mov sb, r0
	cmp r3, #0
	beq _081277BE
	add r0, sp, #0xc
	mov r8, r0
	movs r1, #0xff
	mov sl, r1
	adds r0, r6, #0
	ands r0, r1
	lsls r0, r0, #1
	adds r7, r3, #0
	ldr r2, _0812774C @ =0x085B0A08
	adds r0, r0, r2
	str r0, [sp, #0x1c]
_0812772A:
	adds r0, r6, #0
	adds r0, #0x40
	mov r1, sl
	ands r0, r1
	lsls r0, r0, #1
	ldr r2, _0812774C @ =0x085B0A08
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08127750
	asrs r1, r0, #0xc
	b _08127756
	.align 2, 0
_08127748: .4byte 0x000006FA
_0812774C: .4byte 0x085B0A08
_08127750:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08127756:
	movs r0, #0
	mov r2, r8
	strh r1, [r2]
	strh r0, [r2, #2]
	ldr r1, [sp, #0x1c]
	movs r2, #0
	ldrsh r0, [r1, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0812776E
	asrs r0, r0, #0xc
	b _08127774
_0812776E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08127774:
	mov r1, r8
	strh r0, [r1, #4]
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r2, [r0]
	adds r2, #8
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r3, [r0]
	adds r1, #8
	adds r0, r5, r1
	ldrh r0, [r0]
	str r0, [sp]
	mov r0, sb
	str r0, [sp, #4]
	ldrh r0, [r5]
	str r0, [sp, #8]
	add r0, sp, #0x14
	add r1, sp, #0xc
	bl FUN_080dce8c
	mov r1, sb
	lsls r0, r1, #3
	movs r1, #0xa
	bl Div
	mov sb, r0
	lsls r0, r4, #2
	movs r1, #0xa
	bl Div
	adds r4, r4, r0
	subs r7, #1
	cmp r7, #0
	bne _0812772A
_081277BE:
	ldr r0, _081277D4 @ =0x00000101
	bl PlaySound_082406e0
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081277D4: .4byte 0x00000101

	thumb_func_start FUN_081277d8
FUN_081277d8: @ 0x081277D8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r3, _08127844 @ =0x00000704
	adds r0, r0, r3
	ldr r1, [r1]
	ldr r0, [r0]
	cmp r1, r0
	bhs _08127858
	ldr r3, _08127848 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r6, _0812784C @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r3, #0
	strh r2, [r0]
	movs r1, #2
	subs r6, #0xeb
	adds r0, r5, r6
	strb r3, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08127850 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _08127854 @ =0x00000484
	adds r0, r5, r3
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	b _081278A2
	.align 2, 0
_08127844: .4byte 0x00000704
_08127848: .4byte FUN_080e48d0
_0812784C: .4byte 0x0000046D
_08127850: .4byte 0x0000046A
_08127854: .4byte 0x00000484
_08127858:
	ldr r2, _081278AC @ =FUN_080e48d0
	movs r1, #0x10
	ldr r3, _081278B0 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081278B4 @ =0x0000046B
	adds r0, r5, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081278B8 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _081278BC @ =0x0000046A
	adds r0, r5, r2
	strb r4, [r0]
	adds r6, #0x1c
	adds r0, r5, r6
	str r3, [r0]
	adds r1, #3
	adds r0, r5, r1
_081278A2:
	strb r4, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081278AC: .4byte FUN_080e48d0
_081278B0: .4byte 0x0000046D
_081278B4: .4byte 0x0000046B
_081278B8: .4byte 0x00000469
_081278BC: .4byte 0x0000046A

	thumb_func_start FUN_081278c0
FUN_081278c0: @ 0x081278C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x7c
	str r0, [sp, #8]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp, #0xc]
	ldr r2, [sp, #8]
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r0, [r0]
	ldr r0, [r0, #0x18]
	ldrh r0, [r0, #6]
	mov sb, r0
	ldr r4, _0812792C @ =0x0000021E
	adds r0, r2, r4
	ldr r1, _08127930 @ =0x03002B68
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _081278FA
	bl _081280CC
_081278FA:
	ldr r6, [sp, #8]
	ldr r7, _08127934 @ =0x00000256
	adds r0, r6, r7
	ldrh r0, [r0]
	cmp sb, r0
	bne _08127908
	b _08127A48
_08127908:
	ldr r0, [sp, #8]
	ldr r1, _08127934 @ =0x00000256
	adds r4, r0, r1
	ldrh r7, [r4]
	movs r3, #0xa
	ldrsh r2, [r0, r3]
	mov r8, r2
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	str r4, [sp, #0x48]
	cmp r0, #0
	beq _0812793C
	adds r0, #4
	ldr r4, _08127938 @ =0x030046A4
	mov sl, r4
	b _0812794A
	.align 2, 0
_0812792C: .4byte 0x0000021E
_08127930: .4byte 0x03002B68
_08127934: .4byte 0x00000256
_08127938: .4byte 0x030046A4
_0812793C:
	ldr r2, _08127974 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
	mov sl, r2
_0812794A:
	ldrb r0, [r0]
	lsrs r4, r0, #4
	mov r6, sl
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	movs r3, #6
	ldrsh r0, [r0, r3]
	adds r6, r1, #0
	muls r6, r0, r6
	str r6, [sp, #0x10]
	cmp r7, sb
	bge _081279E0
	adds r5, r7, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	b _08127980
	.align 2, 0
_08127974: .4byte 0x030046A4
_08127978:
	cmp r5, sb
	beq _081279DC
	adds r5, #1
	adds r6, #1
_08127980:
	mov r1, sl
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _081279A0
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, r8
	adds r3, r4, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08127978
_081279A0:
	mov r3, sl
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	adds r5, r7, r0
	b _081279BE
_081279AE:
	cmp r5, sb
	beq _081279DC
	ldr r0, _081279D8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r5, r5, r0
_081279BE:
	ldr r2, [sp, #0x10]
	cmp r2, r5
	ble _08127A42
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, r8
	adds r3, r4, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081279AE
	b _08127A42
	.align 2, 0
_081279D8: .4byte 0x030046A4
_081279DC:
	movs r0, #1
	b _08127A44
_081279E0:
	subs r5, r7, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	b _081279F4
_081279EC:
	cmp r5, sb
	beq _081279DC
	subs r5, #1
	subs r6, #1
_081279F4:
	cmp r6, #0
	blt _08127A0A
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, r8
	adds r3, r4, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081279EC
_08127A0A:
	ldr r0, _08127A18 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r5, r7, r0
	b _08127A2C
	.align 2, 0
_08127A18: .4byte 0x030046A4
_08127A1C:
	cmp r5, sb
	beq _081279DC
	ldr r0, _08127A4C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	subs r5, r5, r0
_08127A2C:
	cmp r5, #0
	blt _08127A42
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, r8
	adds r3, r4, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08127A1C
_08127A42:
	movs r0, #0
_08127A44:
	cmp r0, #0
	beq _08127A50
_08127A48:
	movs r0, #1
	b _081280CE
	.align 2, 0
_08127A4C: .4byte 0x030046A4
_08127A50:
	ldr r7, [sp, #0xc]
	ldr r1, _08127A70 @ =0x000006FE
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08127A78
	ldr r2, [sp, #8]
	ldr r3, _08127A74 @ =0x00000256
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, sb
	bne _08127A78
	adds r0, r2, #0
	bl FUN_081282c8
	b _081280CC
	.align 2, 0
_08127A70: .4byte 0x000006FE
_08127A74: .4byte 0x00000256
_08127A78:
	ldr r4, [sp, #8]
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r4, r6
	ldr r0, _08127AC8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r7, #0x95
	lsls r7, r7, #3
	adds r3, r4, r7
	ldr r6, [r3]
	adds r2, r4, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x70]
	str r2, [sp, #0x40]
	cmp r5, #0
	blt _08127AC4
	cmp r1, #0
	blt _08127AC4
	ldr r0, _08127ACC @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _08127AC4
	ldr r0, _08127AD0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08127AD4
_08127AC4:
	movs r5, #0
	b _08127AE2
	.align 2, 0
_08127AC8: .4byte 0x03002BE0
_08127ACC: .4byte 0x030046A8
_08127AD0: .4byte 0x030046AC
_08127AD4:
	ldr r0, _08127AF4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r5
_08127AE2:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08127AF8
	adds r0, #4
	b _08127B04
	.align 2, 0
_08127AF4: .4byte 0x030046A4
_08127AF8:
	ldr r0, _08127B18 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08127B04:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08127B1C
	cmp r2, #2
	beq _08127B20
	b _08127B24
	.align 2, 0
_08127B18: .4byte 0x030046A4
_08127B1C:
	ldrb r0, [r6, #4]
	b _08127B22
_08127B20:
	ldrb r0, [r6]
_08127B22:
	subs r1, r1, r0
_08127B24:
	strh r1, [r6, #2]
	ldr r0, _08127B38 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08127B3C
	movs r0, #1
	b _08127B3E
	.align 2, 0
_08127B38: .4byte 0x030047A4
_08127B3C:
	movs r0, #0
_08127B3E:
	cmp r0, #0
	beq _08127B88
	ldr r1, [sp, #8]
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _08127B60
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08127B5C
	adds r2, r0, #0
_08127B5C:
	cmp r2, #0
	bge _08127B74
_08127B60:
	ldr r3, [sp, #8]
	ldr r4, _08127B70 @ =0x000005C4
	adds r0, r3, r4
	ldr r1, [r0]
	adds r0, r3, #0
	bl _call_via_r1
	b _081280CC
	.align 2, 0
_08127B70: .4byte 0x000005C4
_08127B74:
	ldr r1, _08127B84 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08127BD4
	.align 2, 0
_08127B84: .4byte 0x03002BE0
_08127B88:
	ldr r6, [sp, #8]
	movs r7, #0xec
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08127BB6
	cmp r1, #0
	blt _08127BB6
	ldr r0, _08127BBC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08127BB6
	ldr r0, _08127BC0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08127BC4
_08127BB6:
	movs r5, #0
	b _08127BD2
	.align 2, 0
_08127BBC: .4byte 0x030046A8
_08127BC0: .4byte 0x030046AC
_08127BC4:
	ldr r0, _08127CC0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08127BD2:
	movs r2, #0
_08127BD4:
	ldr r0, [sp, #0x48]
	ldrh r0, [r0]
	cmp r5, r0
	beq _08127BF2
	ldr r1, _08127CC4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08127BF2
	b _08128004
_08127BF2:
	movs r0, #0x80
	lsls r0, r0, #3
	ldr r1, [sp, #8]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r1, r3
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x14]
	str r2, [sp, #0x74]
	cmp r1, #0
	beq _08127C10
	b _081280CC
_08127C10:
	ldr r4, [sp, #8]
	ldr r6, _08127CC8 @ =0x00000222
	adds r2, r4, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r7, [sp, #0x74]
	ldrh r0, [r7]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	str r2, [sp, #0x38]
	cmp r7, #0
	beq _08127CE4
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _08127CCC @ =0x0000046D
	adds r4, r4, r2
	mov ip, r4
	movs r3, #1
	mov sb, r3
	mov r6, sb
	strb r6, [r4]
	ldr r7, [sp, #8]
	subs r2, #2
	adds r7, r7, r2
	mov sl, r7
	movs r3, #0
	strb r3, [r7]
	ldr r4, [sp, #8]
	ldr r6, _08127CD0 @ =0x00000553
	adds r4, r4, r6
	mov r8, r4
	strb r0, [r4]
	movs r0, #0xaf
	lsls r0, r0, #3
	ldr r7, [sp, #8]
	adds r0, r7, r0
	str r0, [sp, #0x78]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	mov r2, sp
	ldrh r2, [r2, #0x14]
	strh r2, [r5]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _08127CD4 @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _08127CD8 @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _08127CDC @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x14]
	str r6, [r1]
	ldr r6, _08127CE0 @ =0x0000046C
	adds r0, r7, r6
	mov r7, sb
	strb r7, [r0]
	mov r6, ip
	str r6, [sp, #0x64]
	mov r7, sl
	str r7, [sp, #0x5c]
	mov r6, r8
	str r6, [sp, #0x3c]
	ldr r7, [sp, #0x78]
	str r7, [sp, #0x44]
	str r5, [sp, #0x24]
	str r4, [sp, #0x50]
	str r3, [sp, #0x54]
	str r2, [sp, #0x58]
	str r1, [sp, #0x6c]
	str r0, [sp, #0x60]
	b _08127EB2
	.align 2, 0
_08127CC0: .4byte 0x030046A4
_08127CC4: .4byte 0x03002BE0
_08127CC8: .4byte 0x00000222
_08127CCC: .4byte 0x0000046D
_08127CD0: .4byte 0x00000553
_08127CD4: .4byte 0x00000469
_08127CD8: .4byte 0x0000046A
_08127CDC: .4byte 0x00000484
_08127CE0: .4byte 0x0000046C
_08127CE4:
	ldr r1, [sp, #8]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r1, r2
	ldr r1, [r0]
	movs r0, #1
	ldr r4, _08127DA8 @ =0x0000046D
	ldr r3, [sp, #8]
	adds r4, r3, r4
	str r4, [sp, #0x18]
	strb r0, [r4]
	ldr r6, _08127DAC @ =0x0000046B
	adds r3, r3, r6
	mov ip, r3
	movs r2, #0
	strb r2, [r3]
	ldr r3, [sp, #8]
	ldr r4, _08127DB0 @ =0x00000553
	adds r3, r3, r4
	mov sl, r3
	strb r0, [r3]
	ldr r6, [sp, #8]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r6, r6, r2
	mov sb, r6
	str r1, [r6]
	ldr r3, [sp, #8]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r3, r3, r4
	mov r8, r3
	strh r7, [r3]
	movs r1, #5
	ldr r2, [sp, #8]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r6, r2, r3
	movs r4, #0
	strb r4, [r6]
	adds r3, #1
	adds r5, r2, r3
	strb r4, [r5]
	adds r3, #1
	adds r4, r2, r3
	strb r1, [r4]
	ldr r1, _08127DB4 @ =0x00000484
	adds r3, r2, r1
	str r7, [r3]
	ldr r7, _08127DB8 @ =0x0000046C
	adds r2, r2, r7
	strb r0, [r2]
	ldr r0, [sp, #0x70]
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	ldr r1, [sp, #0x40]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r7, [sp, #0x1c]
	strh r1, [r7]
	ldr r7, [sp, #0x40]
	ldr r0, [r7, #8]
	ldrh r0, [r0, #2]
	ldr r7, [sp, #0x1c]
	strh r0, [r7, #4]
	lsls r1, r1, #0x10
	asrs r7, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x64]
	mov r0, ip
	str r0, [sp, #0x5c]
	mov r0, sl
	str r0, [sp, #0x3c]
	mov r0, sb
	str r0, [sp, #0x44]
	mov r0, r8
	str r0, [sp, #0x24]
	str r6, [sp, #0x50]
	str r5, [sp, #0x54]
	str r4, [sp, #0x58]
	str r3, [sp, #0x6c]
	str r2, [sp, #0x60]
	cmp r7, #0
	blt _08127DA4
	cmp r1, #0
	blt _08127DA4
	ldr r0, _08127DBC @ =0x030046A8
	ldr r0, [r0]
	cmp r7, r0
	bhs _08127DA4
	ldr r0, _08127DC0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08127DC4
_08127DA4:
	movs r7, #0
	b _08127DD2
	.align 2, 0
_08127DA8: .4byte 0x0000046D
_08127DAC: .4byte 0x0000046B
_08127DB0: .4byte 0x00000553
_08127DB4: .4byte 0x00000484
_08127DB8: .4byte 0x0000046C
_08127DBC: .4byte 0x030046A8
_08127DC0: .4byte 0x030046AC
_08127DC4:
	ldr r0, _08127DE4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r7, r0, r7
_08127DD2:
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08127DE8
	adds r0, #4
	b _08127DF4
	.align 2, 0
_08127DE4: .4byte 0x030046A4
_08127DE8:
	ldr r0, _08127E08 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08127DF4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08127E0C
	cmp r2, #2
	beq _08127E12
	b _08127E18
	.align 2, 0
_08127E08: .4byte 0x030046A4
_08127E0C:
	ldr r2, [sp, #0x1c]
	ldrb r0, [r2, #4]
	b _08127E16
_08127E12:
	ldr r3, [sp, #0x1c]
	ldrb r0, [r3]
_08127E16:
	subs r1, r1, r0
_08127E18:
	ldr r4, [sp, #0x1c]
	strh r1, [r4, #2]
	ldr r6, [sp, #0x70]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08127E44
	cmp r1, #0
	blt _08127E44
	ldr r0, _08127E48 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08127E44
	ldr r0, _08127E4C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08127E50
_08127E44:
	movs r7, #0
	b _08127E5E
	.align 2, 0
_08127E48: .4byte 0x030046A8
_08127E4C: .4byte 0x030046AC
_08127E50:
	ldr r0, _08127E74 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r7, r0, r2
_08127E5E:
	ldr r0, [sp, #0x70]
	ldr r4, [r0]
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08127E78
	adds r0, #4
	b _08127E84
	.align 2, 0
_08127E74: .4byte 0x030046A4
_08127E78:
	ldr r0, _08127E98 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08127E84:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08127E9C
	cmp r3, #2
	beq _08127EA0
	b _08127EA4
	.align 2, 0
_08127E98: .4byte 0x030046A4
_08127E9C:
	ldrb r0, [r4, #4]
	b _08127EA2
_08127EA0:
	ldrb r0, [r4]
_08127EA2:
	subs r2, r2, r0
_08127EA4:
	ldr r1, [sp, #0x70]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x70]
	ldr r0, [r2]
	strh r1, [r0, #6]
_08127EB2:
	ldr r3, [sp, #8]
	ldrb r3, [r3, #5]
	str r3, [sp, #0x20]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x74]
	ldrh r0, [r4]
	ands r0, r1
	mov r8, r3
	ldr r7, _08127EE4 @ =0x00000482
	ldr r6, [sp, #8]
	adds r7, r6, r7
	str r7, [sp, #0x68]
	cmp r0, #0
	beq _08127ED2
	b _08127FD0
_08127ED2:
	movs r1, #4
	ldr r2, [sp, #0x38]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08127EE8
	movs r0, #1
	b _08127EEA
	.align 2, 0
_08127EE4: .4byte 0x00000482
_08127EE8:
	movs r0, #0
_08127EEA:
	ldr r4, _08127FE0 @ =0x00000482
	ldr r3, [sp, #8]
	adds r4, r3, r4
	str r4, [sp, #0x68]
	cmp r0, #0
	bne _08127FD0
	movs r3, #0
	ldr r7, [sp, #8]
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	adds r1, r7, #0
	movs r2, #0xa9
	lsls r2, r2, #3
	adds r1, r1, r2
	mov sb, r1
	adds r4, r7, #0
	ldr r7, _08127FE4 @ =0x0000054F
	adds r4, r4, r7
	mov sl, r4
	ldr r0, [sp, #8]
	ldr r1, _08127FE8 @ =0x0000054C
	adds r0, r0, r1
	mov ip, r0
	ldr r4, _08127FEC @ =0x0000054D
	ldr r2, [sp, #8]
	adds r4, r2, r4
	str r4, [sp, #0x30]
	subs r7, #1
	adds r7, r2, r7
	str r7, [sp, #0x34]
	ldr r0, _08127FF0 @ =0x00000541
	adds r0, r2, r0
	str r0, [sp, #0x28]
	adds r1, #0x70
	adds r1, r2, r1
	str r1, [sp, #0x4c]
	ldr r4, _08127FF4 @ =0x00000542
	adds r4, r2, r4
	str r4, [sp, #0x2c]
	ldr r5, _08127FF8 @ =0x0203B400
	ldr r1, _08127FFC @ =0x030046B8
	ldr r4, _08128000 @ =0x000003FF
	movs r2, #3
	mov r7, r8
_08127F44:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r4
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	cmp r0, r7
	bne _08127F62
	adds r3, #1
	cmp r3, #3
	ble _08127F44
	mov r0, r8
_08127F62:
	movs r3, #0
	strb r0, [r6]
	ldr r6, [sp, #0x44]
	ldr r0, [r6]
	mov r7, sb
	str r0, [r7]
	ldr r1, [sp, #0x3c]
	ldrb r0, [r1]
	mov r2, sl
	strb r0, [r2]
	ldr r4, [sp, #0x50]
	ldrb r0, [r4]
	mov r6, ip
	strb r0, [r6]
	ldr r7, [sp, #0x54]
	ldrb r0, [r7]
	ldr r1, [sp, #0x30]
	strb r0, [r1]
	ldr r2, [sp, #0x58]
	ldrb r0, [r2]
	ldr r4, [sp, #0x34]
	strb r0, [r4]
	add r6, sp, #0x20
	ldrb r7, [r6]
	ldr r6, [sp, #0x28]
	strb r7, [r6]
	ldr r7, [sp, #0x4c]
	ldr r2, [r7]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x64]
	strb r1, [r4]
	ldr r6, [sp, #0x5c]
	strb r3, [r6]
	ldr r7, [sp, #0x3c]
	strb r0, [r7]
	ldr r0, [sp, #0x44]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x24]
	strh r3, [r4]
	movs r0, #3
	ldr r6, [sp, #0x50]
	strb r0, [r6]
	ldr r7, [sp, #0x54]
	strb r1, [r7]
	ldr r0, [sp, #0x58]
	strb r2, [r0]
	ldr r2, [sp, #0x6c]
	str r3, [r2]
	ldr r3, [sp, #0x60]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x2c]
	strb r0, [r4]
_08127FD0:
	ldr r0, [sp, #8]
	bl FUN_080e7b6c
	movs r0, #2
	ldr r6, [sp, #0x68]
	strh r0, [r6]
	b _081280CC
	.align 2, 0
_08127FE0: .4byte 0x00000482
_08127FE4: .4byte 0x0000054F
_08127FE8: .4byte 0x0000054C
_08127FEC: .4byte 0x0000054D
_08127FF0: .4byte 0x00000541
_08127FF4: .4byte 0x00000542
_08127FF8: .4byte 0x0203B400
_08127FFC: .4byte 0x030046B8
_08128000: .4byte 0x000003FF
_08128004:
	mov r8, sp
	ldr r6, _08128040 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r1, [r0, r7]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08128044
	adds r0, #4
	b _0812804E
	.align 2, 0
_08128040: .4byte 0x030046A4
_08128044:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0812804E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r3, r8
	strh r0, [r3, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	ldr r4, [sp, #8]
	ldr r6, _08128084 @ =0x000004A4
	adds r0, r4, r6
	ldr r4, [r0]
	ldr r5, [sp, #8]
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _08128088
	ldr r7, [sp, #8]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _081280B0
	.align 2, 0
_08128084: .4byte 0x000004A4
_08128088:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081280A8
	cmp r0, #2
	beq _081280A4
	ldr r0, [sp, #8]
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081280A4:
	movs r0, #1
	b _081280BA
_081280A8:
	ldr r2, [sp, #8]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r2, r3
_081280B0:
	ldr r1, _081280E0 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081280BA:
	cmp r0, #0
	bne _081280CC
	ldr r4, [sp, #8]
	ldr r6, _081280E4 @ =0x000005C4
	adds r0, r4, r6
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_081280CC:
	movs r0, #0
_081280CE:
	add sp, #0x7c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081280E0: .4byte 0xFFFFFDFF
_081280E4: .4byte 0x000005C4

	thumb_func_start FUN_081280e8
FUN_081280e8: @ 0x081280E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp, #8]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, [r1, #0x18]
	ldrh r0, [r0, #6]
	mov sb, r0
	ldr r2, [sp, #8]
	ldrb r2, [r2, #5]
	str r2, [sp, #0xc]
	mov r2, sp
	ldr r4, [sp, #8]
	adds r4, #8
	adds r3, r1, #0
	adds r3, #8
	ldrh r0, [r1, #8]
	ldr r5, [sp, #8]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	strb r0, [r5, #5]
	ldr r1, _08128170 @ =0x00000256
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp sb, r0
	bne _0812814C
	b _08128294
_0812814C:
	ldr r2, [sp, #8]
	ldr r3, _08128170 @ =0x00000256
	adds r0, r2, r3
	ldrh r6, [r0]
	movs r0, #0xa
	ldrsh r5, [r2, r0]
	mov r8, r5
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08128178
	adds r0, #4
	ldr r1, _08128174 @ =0x030046A4
	mov sl, r1
	b _08128186
	.align 2, 0
_08128170: .4byte 0x00000256
_08128174: .4byte 0x030046A4
_08128178:
	ldr r2, _081281B0 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
	mov sl, r2
_08128186:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	movs r5, #6
	ldrsh r0, [r0, r5]
	adds r2, r1, #0
	muls r2, r0, r2
	str r2, [sp, #0x10]
	cmp r6, sb
	bge _0812821C
	adds r4, r6, #1
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	b _081281BC
	.align 2, 0
_081281B0: .4byte 0x030046A4
_081281B4:
	cmp r4, sb
	beq _08128218
	adds r4, #1
	adds r5, #1
_081281BC:
	mov r3, sl
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r5, r0
	bge _081281DC
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081281B4
_081281DC:
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	adds r4, r6, r0
	b _081281FA
_081281EA:
	cmp r4, sb
	beq _08128218
	ldr r0, _08128214 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r0, [r0, r5]
	adds r4, r4, r0
_081281FA:
	ldr r0, [sp, #0x10]
	cmp r0, r4
	ble _0812827E
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081281EA
	b _0812827E
	.align 2, 0
_08128214: .4byte 0x030046A4
_08128218:
	movs r0, #1
	b _08128280
_0812821C:
	subs r4, r6, #1
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	b _08128230
_08128228:
	cmp r4, sb
	beq _08128218
	subs r4, #1
	subs r5, #1
_08128230:
	cmp r5, #0
	blt _08128246
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08128228
_08128246:
	ldr r0, _08128254 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r6, r0
	b _08128268
	.align 2, 0
_08128254: .4byte 0x030046A4
_08128258:
	cmp r4, sb
	beq _08128218
	ldr r0, _08128290 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r4, r0
_08128268:
	cmp r4, #0
	blt _0812827E
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08128258
_0812827E:
	movs r0, #0
_08128280:
	cmp r0, #0
	bne _08128294
	mov r3, sp
	ldrb r5, [r3, #0xc]
	ldr r3, [sp, #8]
	strb r5, [r3, #5]
	movs r0, #0
	b _08128296
	.align 2, 0
_08128290: .4byte 0x030046A4
_08128294:
	movs r0, #1
_08128296:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081282a8
FUN_081282a8: @ 0x081282A8
	push {lr}
	ldr r0, _081282BC @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #8
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081282C0
	movs r0, #0
	b _081282C2
	.align 2, 0
_081282BC: .4byte 0x03002BE0
_081282C0:
	movs r0, #1
_081282C2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081282c8
FUN_081282c8: @ 0x081282C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #8]
	ldr r2, _08128310 @ =0x000006FE
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _081282EC
	b _081286B6
_081282EC:
	ldrb r0, [r7, #5]
	adds r0, #0x20
	asrs r4, r0, #6
	movs r0, #3
	ands r4, r0
	ldr r3, _08128314 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	mov sb, r0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812831C
	adds r0, #4
	ldr r6, _08128318 @ =0x030046A4
	b _0812832C
	.align 2, 0
_08128310: .4byte 0x000006FE
_08128314: .4byte 0x00000256
_08128318: .4byte 0x030046A4
_0812831C:
	ldr r2, _08128358 @ =0x030046A4
	ldr r1, [r2]
	mov r5, sb
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
	adds r6, r2, #0
_0812832C:
	ldrb r0, [r0]
	movs r1, #0xf
	mov sl, r1
	mov r2, sl
	ands r2, r0
	mov sl, r2
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	movs r5, #6
	ldrsh r0, [r0, r5]
	adds r5, r1, #0
	muls r5, r0, r5
	cmp r4, #1
	beq _081283F2
	cmp r4, #1
	bgt _0812835C
	cmp r4, #0
	beq _0812836A
	b _08128584
	.align 2, 0
_08128358: .4byte 0x030046A4
_0812835C:
	cmp r4, #2
	bne _08128362
	b _08128472
_08128362:
	cmp r4, #3
	bne _08128368
	b _08128506
_08128368:
	b _08128584
_0812836A:
	mov r4, sb
	adds r4, #1
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _08128384
	b _08128584
_08128384:
	mov r8, r6
	lsls r0, r4, #2
	adds r6, r0, #0
	adds r6, #0xc
_0812838C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812839C
	adds r0, #4
	b _081283A4
_0812839C:
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_081283A4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sl
	bne _081283D0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081283BE
	adds r0, #4
	b _081283C6
_081283BE:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_081283C6:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _081283D4
_081283D0:
	movs r0, #0
	b _081283D6
_081283D4:
	movs r0, #1
_081283D6:
	cmp r0, #0
	bne _081283DC
	b _081284E6
_081283DC:
	adds r6, #4
	adds r4, #1
	adds r5, #1
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r5, r0
	blt _0812838C
	b _08128584
_081283F2:
	mov r3, sb
	adds r4, r3, r1
	cmp r5, r4
	bgt _081283FC
	b _08128584
_081283FC:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812840C
	adds r0, #4
	b _08128418
_0812840C:
	ldr r0, _08128434 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08128418:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sl
	bne _08128450
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08128438
	adds r0, #4
	ldr r6, _08128434 @ =0x030046A4
	b _08128446
	.align 2, 0
_08128434: .4byte 0x030046A4
_08128438:
	ldr r2, _08128458 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
	adds r6, r2, #0
_08128446:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _0812845C
_08128450:
	movs r0, #0
	ldr r6, _08128458 @ =0x030046A4
	b _0812845E
	.align 2, 0
_08128458: .4byte 0x030046A4
_0812845C:
	movs r0, #1
_0812845E:
	cmp r0, #0
	beq _081284EA
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	cmp r5, r4
	bgt _081283FC
	b _08128584
_08128472:
	mov r4, sb
	subs r4, #1
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	cmp r5, #0
	bge _08128484
	b _08128584
_08128484:
	mov r8, r6
	lsls r0, r4, #2
	adds r6, r0, #0
	adds r6, #0xc
_0812848C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812849C
	adds r0, #4
	b _081284A4
_0812849C:
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_081284A4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sl
	bne _081284D0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081284BE
	adds r0, #4
	b _081284C6
_081284BE:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_081284C6:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _081284D4
_081284D0:
	movs r0, #0
	b _081284D6
_081284D4:
	movs r0, #1
_081284D6:
	cmp r0, #0
	beq _081284F6
	subs r6, #4
	subs r4, #1
	subs r5, #1
	cmp r5, #0
	bge _0812848C
	b _08128584
_081284E6:
	subs r5, r4, #1
	b _08128586
_081284EA:
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r0, [r0, r5]
	subs r5, r4, r0
	b _08128586
_081284F6:
	adds r5, r4, #1
	b _08128586
_081284FA:
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r5, r4, r0
	b _08128586
_08128506:
	mov r2, sb
	subs r4, r2, r1
	cmp r4, #0
	blt _08128584
_0812850E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812851E
	adds r0, #4
	b _0812852A
_0812851E:
	ldr r0, _08128548 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812852A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sl
	bne _08128564
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812854C
	adds r0, #4
	ldr r6, _08128548 @ =0x030046A4
	b _0812855A
	.align 2, 0
_08128548: .4byte 0x030046A4
_0812854C:
	ldr r2, _0812856C @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
	adds r6, r2, #0
_0812855A:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _08128570
_08128564:
	movs r0, #0
	ldr r6, _0812856C @ =0x030046A4
	b _08128572
	.align 2, 0
_0812856C: .4byte 0x030046A4
_08128570:
	movs r0, #1
_08128572:
	cmp r0, #0
	beq _081284FA
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r4, r4, r0
	cmp r4, #0
	bge _0812850E
_08128584:
	mov r5, sb
_08128586:
	ldr r1, _081285D0 @ =0x00000256
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r5, r0
	bne _08128592
	b _081286B6
_08128592:
	mov sb, sp
	ldr r6, _081285D4 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081285D8
	adds r0, #4
	b _081285E2
	.align 2, 0
_081285D0: .4byte 0x00000256
_081285D4: .4byte 0x030046A4
_081285D8:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081285E2:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r5, sb
	strh r0, [r5, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r5, #4]
	ldrh r1, [r7, #0xa]
	mov r0, sp
	strh r1, [r0, #2]
	ldr r2, _0812861C @ =0x000004A4
	adds r0, r7, r2
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _08128620
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
	b _08128646
	.align 2, 0
_0812861C: .4byte 0x000004A4
_08128620:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08128640
	cmp r0, #2
	beq _0812863C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0812863C:
	movs r0, #1
	b _08128650
_08128640:
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
_08128646:
	ldr r1, _08128664 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08128650:
	adds r4, r0, #0
	cmp r4, #0
	beq _0812866C
	ldr r0, [sp, #8]
	ldr r2, _08128668 @ =0x000006FE
	adds r1, r0, r2
	movs r0, #0xf0
	strh r0, [r1]
	movs r0, #1
	b _081286B8
	.align 2, 0
_08128664: .4byte 0xFFFFFDFF
_08128668: .4byte 0x000006FE
_0812866C:
	ldr r1, _081286C8 @ =FUN_080e48d0
	ldr r3, _081286CC @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r5, _081286D0 @ =0x0000046B
	adds r0, r7, r5
	strb r4, [r0]
	ldr r2, _081286D4 @ =0x00000553
	adds r0, r7, r2
	strb r4, [r0]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r0, r7, r5
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _081286D8 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	adds r5, #2
	adds r0, r7, r5
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r7, r1
	str r4, [r0]
	ldr r2, _081286DC @ =0x0000046C
	adds r0, r7, r2
	strb r3, [r0]
_081286B6:
	movs r0, #0
_081286B8:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081286C8: .4byte FUN_080e48d0
_081286CC: .4byte 0x0000046D
_081286D0: .4byte 0x0000046B
_081286D4: .4byte 0x00000553
_081286D8: .4byte 0x00000469
_081286DC: .4byte 0x0000046C

	thumb_func_start FUN_081286e0
FUN_081286e0: @ 0x081286E0
	push {lr}
	adds r1, r0, #0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r3, [r0]
	adds r2, #0x18
	adds r0, r1, r2
	ldr r2, _0812870C @ =0x00000704
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blo _08128714
	ldr r1, _08128710 @ =0x000006FC
	adds r0, r3, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08128714
	movs r0, #0
	b _08128716
	.align 2, 0
_0812870C: .4byte 0x00000704
_08128710: .4byte 0x000006FC
_08128714:
	movs r0, #1
_08128716:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0812871c
FUN_0812871c: @ 0x0812871C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r4, r0
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	ldr r3, _081287A0 @ =0x0000071E
	adds r2, r2, r3
	ldr r0, _081287A4 @ =0xFFFFEBFF
	ldrh r1, [r2]
	ands r0, r1
	movs r6, #0
	strh r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r7, #0xbc
	lsls r7, r7, #1
	adds r0, r4, r7
	ldr r5, [r0]
	ands r5, r1
	cmp r5, #0
	beq _081287B4
	ldr r1, _081287A8 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _0812876E
	movs r0, #4
	ldr r3, _081287AC @ =0x00000222
	adds r2, r4, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0812876E:
	movs r0, #0x80
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r2, r4, r7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0x93
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r3, _081287B0 @ =0x0000024E
	adds r0, r4, r3
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0812880C
	adds r0, r4, #0
	bl FUN_081277d8
	b _081287FC
	.align 2, 0
_081287A0: .4byte 0x0000071E
_081287A4: .4byte 0xFFFFEBFF
_081287A8: .4byte 0x000001DF
_081287AC: .4byte 0x00000222
_081287B0: .4byte 0x0000024E
_081287B4:
	movs r1, #1
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r4, r7
	strb r6, [r0]
	ldr r2, _08128814 @ =0x00000469
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _08128818 @ =0x0000046A
	adds r0, r4, r3
	strb r6, [r0]
	adds r7, #0x1c
	adds r0, r4, r7
	str r5, [r0]
	adds r2, #3
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _0812881C @ =FUN_080e48d0
	movs r2, #0x10
	subs r7, #0x17
	adds r0, r4, r7
	strb r1, [r0]
	ldr r1, _08128820 @ =0x0000046B
	adds r0, r4, r1
	strb r6, [r0]
	adds r7, #0xe6
	adds r0, r4, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r5, [r0]
_081287FC:
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0812880C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08128814: .4byte 0x00000469
_08128818: .4byte 0x0000046A
_0812881C: .4byte FUN_080e48d0
_08128820: .4byte 0x0000046B

	thumb_func_start FUN_08128824
FUN_08128824: @ 0x08128824
	push {lr}
	adds r2, r0, #0
	movs r1, #0x80
	lsls r1, r1, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08128840
	adds r0, r2, #0
	bl FUN_081282c8
_08128840:
	pop {r0}
	bx r0

	thumb_func_start FUN_08128844
FUN_08128844: @ 0x08128844
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x84
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sb, r0
	movs r1, #0x10
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r5, r7, r2
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08128870
	bl _0812913E
_08128870:
	movs r3, #0xc3
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812888A
	movs r0, #1
	bl _08129140
_0812888A:
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0812889A
	bl _0812913E
_0812889A:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r1, r0
	cmp r1, #0
	bne _081288A8
	bl _0812913E
_081288A8:
	movs r1, #0x80
	lsls r1, r1, #0x11
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081288BE
	bl _0812913E
_081288BE:
	ldr r6, _08128920 @ =0x0000021E
	adds r0, r7, r6
	ldr r1, _08128924 @ =0x03002B68
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _081288D0
	bl _0812913E
_081288D0:
	movs r1, #8
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r4, r7, r0
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	adds r0, r7, #0
	bl FUN_080e4444
	adds r1, r0, #0
	mov r8, r4
	cmp r1, #0
	bne _081288F0
	bl _081290FA
_081288F0:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	str r1, [r0]
	ldr r0, [r1, #0x18]
	ldrh r0, [r0, #6]
	mov sl, r0
	movs r3, #0xfc
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r0, [r0]
	cmp r0, #0
	bne _0812890C
	b _0812909C
_0812890C:
	movs r1, #2
	ldr r4, _08128928 @ =0x00000474
	adds r0, r7, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812892C
	movs r0, #1
	b _0812892E
	.align 2, 0
_08128920: .4byte 0x0000021E
_08128924: .4byte 0x03002B68
_08128928: .4byte 0x00000474
_0812892C:
	movs r0, #0
_0812892E:
	cmp r0, #0
	beq _08128948
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, _08128944 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r6, r1, #0
	b _08128956
	.align 2, 0
_08128944: .4byte 0x03002BE0
_08128948:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _0812898E
_08128956:
	ldr r1, [r6]
	movs r2, #8
	ldrsh r5, [r1, r2]
	movs r3, #8
	ldrsh r0, [r7, r3]
	subs r5, r5, r0
	movs r0, #0xc
	ldrsh r4, [r1, r0]
	movs r1, #0xc
	ldrsh r0, [r7, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r7, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_0812898E:
	adds r0, r7, #0
	bl FUN_081286e0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812899C
	b _08128FDC
_0812899C:
	movs r1, #0xa0
	lsls r1, r1, #5
	ldr r0, _081289B0 @ =0x0000071E
	add r0, sb
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081289B4
	movs r0, #1
	b _081289B6
	.align 2, 0
_081289B0: .4byte 0x0000071E
_081289B4:
	movs r0, #0
_081289B6:
	cmp r0, #0
	beq _081289BC
	b _0812913E
_081289BC:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r3, r7, r4
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x60]
	str r2, [sp, #0x3c]
	cmp r4, #0
	blt _081289F8
	cmp r1, #0
	blt _081289F8
	ldr r0, _081289FC @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081289F8
	ldr r0, _08128A00 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08128A04
_081289F8:
	movs r4, #0
	b _08128A12
	.align 2, 0
_081289FC: .4byte 0x030046A8
_08128A00: .4byte 0x030046AC
_08128A04:
	ldr r0, _08128A24 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_08128A12:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08128A28
	adds r0, #4
	b _08128A34
	.align 2, 0
_08128A24: .4byte 0x030046A4
_08128A28:
	ldr r0, _08128A48 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08128A34:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08128A4C
	cmp r2, #2
	beq _08128A50
	b _08128A54
	.align 2, 0
_08128A48: .4byte 0x030046A4
_08128A4C:
	ldrb r0, [r5, #4]
	b _08128A52
_08128A50:
	ldrb r0, [r5]
_08128A52:
	subs r1, r1, r0
_08128A54:
	strh r1, [r5, #2]
	ldr r0, _08128A68 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08128A6C
	movs r0, #1
	b _08128A6E
	.align 2, 0
_08128A68: .4byte 0x030047A4
_08128A6C:
	movs r0, #0
_08128A6E:
	cmp r0, #0
	beq _08128AB0
	ldr r1, [r6]
	cmp r1, #0
	beq _08128A88
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08128A84
	adds r2, r0, #0
_08128A84:
	cmp r2, #0
	bge _08128A9C
_08128A88:
	ldr r6, _08128A98 @ =0x000005C4
	adds r0, r7, r6
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0812913E
	.align 2, 0
_08128A98: .4byte 0x000005C4
_08128A9C:
	ldr r1, _08128AAC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08128AF4
	.align 2, 0
_08128AAC: .4byte 0x03002BE0
_08128AB0:
	ldr r0, [r6]
	ldrh r1, [r0, #8]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08128AD6
	cmp r1, #0
	blt _08128AD6
	ldr r0, _08128ADC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08128AD6
	ldr r0, _08128AE0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08128AE4
_08128AD6:
	movs r5, #0
	b _08128AF2
	.align 2, 0
_08128ADC: .4byte 0x030046A8
_08128AE0: .4byte 0x030046AC
_08128AE4:
	ldr r0, _08128BD0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08128AF2:
	movs r2, #0
_08128AF4:
	ldr r1, _08128BD4 @ =0x00000256
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r5, r0
	beq _08128B14
	ldr r1, _08128BD8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08128B14
	b _08128F0C
_08128B14:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	str r2, [sp, #0x64]
	cmp r1, #0
	beq _08128B30
	b _0812913E
_08128B30:
	ldr r4, _08128BDC @ =0x00000222
	adds r2, r7, r4
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r6, [sp, #0x64]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0x38]
	cmp r6, #0
	beq _08128BF0
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _08128BE0 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #8]
	movs r3, #1
	strb r3, [r2]
	ldr r4, _08128BE4 @ =0x0000046B
	adds r4, r4, r7
	mov r8, r4
	movs r6, #0
	strb r6, [r4]
	ldr r2, _08128BE8 @ =0x00000553
	adds r2, r7, r2
	str r2, [sp, #0xc]
	strb r0, [r2]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r3, r7
	mov sl, r3
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r5, r7, r4
	mov r6, sb
	strh r6, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	movs r2, #0
	strb r2, [r4]
	ldr r6, _08128BEC @ =0x00000469
	adds r3, r7, r6
	strb r2, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	adds r6, #0x1b
	adds r1, r7, r6
	mov r0, sb
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #8]
	str r6, [sp, #0x54]
	mov r6, r8
	str r6, [sp, #0x4c]
	ldr r6, [sp, #0xc]
	str r6, [sp, #0x7c]
	mov r6, sl
	str r6, [sp, #0x80]
	str r5, [sp, #0x30]
	str r4, [sp, #0x40]
	str r3, [sp, #0x44]
	str r2, [sp, #0x48]
	str r1, [sp, #0x5c]
	str r0, [sp, #0x50]
	b _08128DC2
	.align 2, 0
_08128BD0: .4byte 0x030046A4
_08128BD4: .4byte 0x00000256
_08128BD8: .4byte 0x03002BE0
_08128BDC: .4byte 0x00000222
_08128BE0: .4byte 0x0000046D
_08128BE4: .4byte 0x0000046B
_08128BE8: .4byte 0x00000553
_08128BEC: .4byte 0x00000469
_08128BF0:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _08128CB0 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x10]
	strb r0, [r2]
	ldr r3, _08128CB4 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x14]
	movs r4, #0
	strb r4, [r3]
	ldr r2, _08128CB8 @ =0x00000553
	adds r2, r7, r2
	str r2, [sp, #0x18]
	strb r0, [r2]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x1c]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x20]
	strh r6, [r4]
	movs r1, #5
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x24]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _08128CBC @ =0x00000469
	adds r5, r7, r4
	strb r3, [r5]
	ldr r2, _08128CC0 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _08128CC4 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _08128CC8 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x60]
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldr r1, [sp, #0x3c]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x28]
	strh r1, [r6]
	ldr r6, [sp, #0x3c]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x28]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x54]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x4c]
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x7c]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0x80]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x30]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0x40]
	str r5, [sp, #0x44]
	str r4, [sp, #0x48]
	str r3, [sp, #0x5c]
	str r2, [sp, #0x50]
	mov r0, ip
	cmp r0, #0
	blt _08128CAC
	cmp r1, #0
	blt _08128CAC
	ldr r0, _08128CCC @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _08128CAC
	ldr r0, _08128CD0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08128CD4
_08128CAC:
	movs r4, #0
	b _08128CE4
	.align 2, 0
_08128CB0: .4byte 0x0000046D
_08128CB4: .4byte 0x0000046B
_08128CB8: .4byte 0x00000553
_08128CBC: .4byte 0x00000469
_08128CC0: .4byte 0x0000046A
_08128CC4: .4byte 0x00000484
_08128CC8: .4byte 0x0000046C
_08128CCC: .4byte 0x030046A8
_08128CD0: .4byte 0x030046AC
_08128CD4:
	ldr r0, _08128CF4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_08128CE4:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08128CF8
	adds r0, #4
	b _08128D04
	.align 2, 0
_08128CF4: .4byte 0x030046A4
_08128CF8:
	ldr r0, _08128D18 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08128D04:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08128D1C
	cmp r2, #2
	beq _08128D22
	b _08128D28
	.align 2, 0
_08128D18: .4byte 0x030046A4
_08128D1C:
	ldr r2, [sp, #0x28]
	ldrb r0, [r2, #4]
	b _08128D26
_08128D22:
	ldr r3, [sp, #0x28]
	ldrb r0, [r3]
_08128D26:
	subs r1, r1, r0
_08128D28:
	ldr r4, [sp, #0x28]
	strh r1, [r4, #2]
	ldr r6, [sp, #0x60]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08128D54
	cmp r1, #0
	blt _08128D54
	ldr r0, _08128D58 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08128D54
	ldr r0, _08128D5C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08128D60
_08128D54:
	movs r4, #0
	b _08128D6E
	.align 2, 0
_08128D58: .4byte 0x030046A8
_08128D5C: .4byte 0x030046AC
_08128D60:
	ldr r0, _08128D84 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08128D6E:
	ldr r0, [sp, #0x60]
	ldr r5, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08128D88
	adds r0, #4
	b _08128D94
	.align 2, 0
_08128D84: .4byte 0x030046A4
_08128D88:
	ldr r0, _08128DA8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08128D94:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08128DAC
	cmp r3, #2
	beq _08128DB0
	b _08128DB4
	.align 2, 0
_08128DA8: .4byte 0x030046A4
_08128DAC:
	ldrb r0, [r5, #4]
	b _08128DB2
_08128DB0:
	ldrb r0, [r5]
_08128DB2:
	subs r2, r2, r0
_08128DB4:
	ldr r1, [sp, #0x60]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x60]
	ldr r0, [r2]
	strh r1, [r0, #6]
_08128DC2:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x2c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x64]
	ldrh r0, [r4]
	ands r0, r1
	mov r8, r3
	ldr r6, _08128DEC @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x58]
	cmp r0, #0
	bne _08128ED0
	movs r1, #4
	ldr r2, [sp, #0x38]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08128DF0
	movs r0, #1
	b _08128DF2
	.align 2, 0
_08128DEC: .4byte 0x00000482
_08128DF0:
	movs r0, #0
_08128DF2:
	ldr r3, _08128EE0 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x58]
	cmp r0, #0
	bne _08128ED0
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _08128EE4 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _08128EE8 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x70]
	ldr r2, _08128EEC @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x74]
	ldr r4, _08128EF0 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x78]
	ldr r6, _08128EF4 @ =0x00000541
	adds r6, r7, r6
	str r6, [sp, #0x68]
	ldr r0, _08128EF8 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x34]
	ldr r1, _08128EFC @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x6c]
	ldr r6, _08128F00 @ =0x0203B400
	ldr r1, _08128F04 @ =0x030046B8
	ldr r5, _08128F08 @ =0x000003FF
	movs r4, #3
	mov r2, r8
_08128E42:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r4
	lsls r0, r0, #6
	cmp r0, r2
	bne _08128E60
	adds r3, #1
	cmp r3, #3
	ble _08128E42
	mov r0, r8
_08128E60:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x80]
	ldr r0, [r4]
	mov r6, sl
	str r0, [r6]
	ldr r1, [sp, #0x7c]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x40]
	ldrb r0, [r4]
	ldr r6, [sp, #0x70]
	strb r0, [r6]
	ldr r1, [sp, #0x44]
	ldrb r0, [r1]
	ldr r2, [sp, #0x74]
	strb r0, [r2]
	ldr r4, [sp, #0x48]
	ldrb r0, [r4]
	ldr r6, [sp, #0x78]
	strb r0, [r6]
	add r0, sp, #0x2c
	ldrb r1, [r0]
	ldr r0, [sp, #0x68]
	strb r1, [r0]
	ldr r1, [sp, #0x34]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x54]
	strb r1, [r4]
	ldr r6, [sp, #0x4c]
	strb r3, [r6]
	ldr r4, [sp, #0x7c]
	strb r0, [r4]
	ldr r6, [sp, #0x80]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x30]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x40]
	strb r0, [r4]
	ldr r6, [sp, #0x44]
	strb r1, [r6]
	ldr r0, [sp, #0x48]
	strb r2, [r0]
	ldr r2, [sp, #0x5c]
	str r3, [r2]
	ldr r3, [sp, #0x50]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x6c]
	strb r0, [r4]
_08128ED0:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r6, [sp, #0x58]
	strh r0, [r6]
	b _0812913E
	.align 2, 0
_08128EE0: .4byte 0x00000482
_08128EE4: .4byte 0x0000054F
_08128EE8: .4byte 0x0000054C
_08128EEC: .4byte 0x0000054D
_08128EF0: .4byte 0x0000054E
_08128EF4: .4byte 0x00000541
_08128EF8: .4byte 0x000005BC
_08128EFC: .4byte 0x00000542
_08128F00: .4byte 0x0203B400
_08128F04: .4byte 0x030046B8
_08128F08: .4byte 0x000003FF
_08128F0C:
	mov sb, sp
	ldr r6, _08128F48 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08128F4C
	adds r0, #4
	b _08128F56
	.align 2, 0
_08128F48: .4byte 0x030046A4
_08128F4C:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08128F56:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r6, r8
	lsls r0, r6, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r1, _08128F8C @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _08128F90
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	b _08128FB6
	.align 2, 0
_08128F8C: .4byte 0x000004A4
_08128F90:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08128FB0
	cmp r0, #2
	beq _08128FAC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08128FAC:
	movs r0, #1
	b _08128FC0
_08128FB0:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
_08128FB6:
	ldr r1, _08128FD4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08128FC0:
	cmp r0, #0
	beq _08128FC6
	b _0812913E
_08128FC6:
	ldr r4, _08128FD8 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0812913E
	.align 2, 0
_08128FD4: .4byte 0xFFFFFDFF
_08128FD8: .4byte 0x000005C4
_08128FDC:
	adds r0, r7, #0
	bl FUN_081278c0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08128FEA
	b _0812913E
_08128FEA:
	movs r1, #0x80
	lsls r1, r1, #0x13
	mov r6, r8
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08129078
	ldr r1, _08129030 @ =0x0000025E
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, sl
	beq _0812907E
	ldr r2, _08129034 @ =0x000004A4
	adds r0, r7, r2
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08129038
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r7, r4
	b _0812905C
	.align 2, 0
_08129030: .4byte 0x0000025E
_08129034: .4byte 0x000004A4
_08129038:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08129056
	cmp r0, #2
	beq _08129064
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08129064
_08129056:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
_0812905C:
	ldr r1, _08129070 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_08129064:
	ldr r1, _08129074 @ =0x0000025E
	adds r0, r7, r1
	mov r2, sl
	strh r2, [r0]
	b _0812907E
	.align 2, 0
_08129070: .4byte 0xFFFFFDFF
_08129074: .4byte 0x0000025E
_08129078:
	adds r0, r7, #0
	bl FUN_080f00ec
_0812907E:
	movs r0, #0x80
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0x14
	mov r4, r8
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r0, #1
	b _08129140
_0812909C:
	movs r1, #0x80
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081290B2
	movs r1, #0x80
	lsls r1, r1, #3
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081290FA
_081290B2:
	movs r1, #0xa0
	lsls r1, r1, #5
	ldr r0, _081290C8 @ =0x0000071E
	add r0, sb
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081290CC
	movs r0, #1
	b _081290CE
	.align 2, 0
_081290C8: .4byte 0x0000071E
_081290CC:
	movs r0, #0
_081290CE:
	cmp r0, #0
	bne _081290FA
	ldr r6, _08129110 @ =0x00000482
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r0, #1
	bne _0812913E
	ldr r1, _08129114 @ =0x0000021E
	adds r0, r7, r1
	ldr r1, _08129118 @ =0x03002B68
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _0812913E
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081290FA:
	movs r2, #0x80
	lsls r2, r2, #7
	ldr r1, _0812911C @ =0x0000071E
	add r1, sb
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _08129120
	movs r0, #1
	b _08129122
	.align 2, 0
_08129110: .4byte 0x00000482
_08129114: .4byte 0x0000021E
_08129118: .4byte 0x03002B68
_0812911C: .4byte 0x0000071E
_08129120:
	movs r0, #0
_08129122:
	cmp r0, #0
	beq _0812913E
	ldr r6, _08129150 @ =0x000001DF
	adds r0, r7, r6
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #1
	bl FUN_080e5718
	ldr r0, _08129154 @ =0xFFFFBFFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_0812913E:
	movs r0, #0
_08129140:
	add sp, #0x84
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08129150: .4byte 0x000001DF
_08129154: .4byte 0xFFFFBFFF

	thumb_func_start FUN_08129158
FUN_08129158: @ 0x08129158
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x28
	mov r8, r0
	ldr r4, _081291DC @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	movs r5, #0x20
	orrs r0, r5
	ldr r1, _081291E0 @ =0x0000FFFF
	mov sb, r1
	ands r0, r1
	movs r6, #0x80
	lsls r6, r6, #0x10
	orrs r0, r6
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r4
	orrs r0, r5
	str r0, [sp, #0xc]
	str r6, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _081291E4 @ =FUN_08121c30
	mov r0, r8
	str r0, [sp]
	add r1, sp, #8
	bl FUN_080e3834
	ldr r0, [sp, #0x18]
	ands r0, r4
	orrs r0, r5
	mov r1, sb
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r4
	orrs r0, r5
	str r0, [r1, #4]
	str r6, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _081291E8 @ =FUN_08121aec
	movs r0, #0
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	bl FUN_080e3984
	add sp, #0x28
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081291DC: .4byte 0xFFFF0000
_081291E0: .4byte 0x0000FFFF
_081291E4: .4byte FUN_08121c30
_081291E8: .4byte FUN_08121aec

	thumb_func_start FUN_081291ec
FUN_081291ec: @ 0x081291EC
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #2
	movs r2, #2
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #3
	movs r2, #3
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #5
	movs r2, #6
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #6
	movs r2, #5
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #7
	movs r2, #7
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #8
	movs r2, #8
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #9
	movs r2, #7
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #4
	movs r3, #0
	bl FUN_080ef84c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0812926c
FUN_0812926c: @ 0x0812926C
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812927E
	b _081293E6
_0812927E:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0812928C
	b _081293E6
_0812928C:
	movs r0, #0x80
	lsls r0, r0, #8
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _081292A0
	b _081293E6
_081292A0:
	movs r3, #0x10
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	beq _08129334
	ldr r3, _08129318 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x40
	orrs r0, r2
	ldr r1, _0812931C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	movs r3, #0x94
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	movs r1, #0x20
	strh r1, [r0, #0xa]
	ldr r1, _08129320 @ =0x00002201
	strh r1, [r0, #6]
	ldr r4, _08129324 @ =0x00000226
	adds r1, r5, r4
	ldrh r1, [r1]
	ldr r3, _08129328 @ =0x0000022E
	adds r2, r5, r3
	ldrh r2, [r2]
	adds r4, #0x1a
	adds r3, r5, r4
	ldr r3, [r3]
	ldr r4, _0812932C @ =0x00200004
	orrs r3, r4
	str r3, [sp]
	ldr r4, _08129330 @ =0x00000236
	adds r3, r5, r4
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
	movs r0, #0x80
	lsls r0, r0, #7
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _081293E6
	.align 2, 0
_08129318: .4byte 0xFFFF0000
_0812931C: .4byte 0x0000FFFF
_08129320: .4byte 0x00002201
_08129324: .4byte 0x00000226
_08129328: .4byte 0x0000022E
_0812932C: .4byte 0x00200004
_08129330: .4byte 0x00000236
_08129334:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r1, r0
	cmp r1, #0
	beq _0812939C
	movs r2, #0x20
	add r0, sp, #8
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x64
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	movs r2, #0x94
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	strh r3, [r0, #0xa]
	ldr r1, _0812938C @ =0x00002201
	strh r1, [r0, #6]
	ldr r3, _08129390 @ =0x00000226
	adds r1, r5, r3
	ldrh r1, [r1]
	ldr r4, _08129394 @ =0x0000022E
	adds r2, r5, r4
	ldrh r2, [r2]
	adds r4, #0x12
	adds r3, r5, r4
	ldr r3, [r3]
	movs r4, #0x80
	lsls r4, r4, #0xa
	orrs r3, r4
	str r3, [sp]
	ldr r4, _08129398 @ =0x00000236
	adds r3, r5, r4
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
	b _081293E6
	.align 2, 0
_0812938C: .4byte 0x00002201
_08129390: .4byte 0x00000226
_08129394: .4byte 0x0000022E
_08129398: .4byte 0x00000236
_0812939C:
	movs r2, #0x20
	add r0, sp, #8
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x64
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	strh r3, [r0, #0xa]
	ldr r1, _081293F0 @ =0x00002201
	strh r1, [r0, #6]
	movs r2, #0x89
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r1, [r1]
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrh r2, [r2]
	movs r4, #0x8f
	lsls r4, r4, #2
	adds r3, r5, r4
	ldr r3, [r3]
	str r3, [sp]
	subs r4, #8
	adds r3, r5, r4
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
_081293E6:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081293F0: .4byte 0x00002201

	thumb_func_start FUN_081293f4
FUN_081293f4: @ 0x081293F4
	push {r4, lr}
	adds r2, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r3, [r0]
	movs r1, #0x40
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0812942C
	ldr r0, _08129434 @ =0x000006FC
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0812941E
	subs r0, #1
	strh r0, [r1]
_0812941E:
	ldr r4, _08129438 @ =0x00000702
	adds r1, r3, r4
	ldrh r0, [r1]
	cmp r0, #0
	beq _0812942C
	subs r0, #1
	strh r0, [r1]
_0812942C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08129434: .4byte 0x000006FC
_08129438: .4byte 0x00000702

	thumb_func_start FUN_0812943c
FUN_0812943c: @ 0x0812943C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _08129450
	b _081298F8
_08129450:
	ldr r0, _081294B4 @ =0x00000464
	adds r4, r6, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _0812945C
	b _081298F8
_0812945C:
	ldr r1, _081294B8 @ =0x00000553
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _081294C4
	ldr r2, _081294BC @ =0x00000494
	adds r1, r6, r2
	movs r0, #0x20
	strh r0, [r1]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	subs r0, #0x31
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r0, _081294C0 @ =0x00000482
	adds r1, r6, r0
	movs r0, #1
	strh r0, [r1]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r6, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r6, #0
	movs r1, #4
	bl FUN_080e64b4
	strh r5, [r4]
	b _081298F8
	.align 2, 0
_081294B4: .4byte 0x00000464
_081294B8: .4byte 0x00000553
_081294BC: .4byte 0x00000494
_081294C0: .4byte 0x00000482
_081294C4:
	ldr r1, _081294EC @ =0x00000316
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #2
	bls _081294F4
	ldrh r0, [r4]
	movs r1, #0x10
	bl Mod
	cmp r0, #0
	bne _08129514
	ldr r0, _081294F0 @ =0x00000121
	bl PlaySound_082406e0
	movs r0, #0x10
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r6, r3
	b _0812950E
	.align 2, 0
_081294EC: .4byte 0x00000316
_081294F0: .4byte 0x00000121
_081294F4:
	ldrh r0, [r4]
	movs r1, #0x30
	bl Mod
	cmp r0, #0
	bne _08129514
	ldr r0, _081295DC @ =0x00000121
	bl PlaySound_082406e0
	movs r0, #0x20
	movs r4, #0xc1
	lsls r4, r4, #1
	adds r2, r6, r4
_0812950E:
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08129514:
	movs r5, #0x8c
	lsls r5, r5, #3
	adds r1, r6, r5
	ldrh r0, [r1]
	cmp r0, #0
	beq _0812956E
	movs r7, #0
	ldrh r1, [r1]
	cmp r7, r1
	bge _0812956E
	ldr r0, _081295E0 @ =0x00000462
	adds r3, r6, r0
	adds r2, r6, r5
_0812952E:
	lsls r1, r7, #1
	movs r4, #0x8b
	lsls r4, r4, #3
	adds r0, r6, r4
	adds r5, r0, r1
	ldrh r4, [r5]
	cmp r4, #0
	bne _08129560
	adds r0, r6, #0
	movs r1, #1
	str r2, [sp, #0x14]
	str r3, [sp, #0x18]
	bl FUN_080e64b4
	strh r4, [r5]
	movs r0, #1
	lsls r0, r7
	ldr r3, [sp, #0x18]
	ldrh r1, [r3]
	bics r1, r0
	strh r1, [r3]
	ldr r2, [sp, #0x14]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
_08129560:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	adds r7, #1
	ldrh r5, [r2]
	cmp r7, r5
	blt _0812952E
_0812956E:
	ldr r0, _081295E4 @ =0x00000464
	adds r1, r6, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	ldrh r0, [r1]
	movs r1, #0x28
	bl Mod
	cmp r0, #0
	beq _08129586
	b _0812970E
_08129586:
	ldr r2, _081295E8 @ =0x00000316
	adds r1, r6, r2
	movs r0, #1
	ldrb r1, [r1]
	lsls r0, r1
	movs r4, #0x8b
	lsls r4, r4, #1
	adds r3, r6, r4
	strh r0, [r3]
	ldr r5, _081295EC @ =0x0000048A
	adds r1, r6, r5
	strh r0, [r1]
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r2, r6, r0
	ldrh r0, [r2]
	ldrh r1, [r3]
	subs r0, r0, r1
	strh r0, [r2]
	movs r1, #0x93
	lsls r1, r1, #3
	adds r2, r6, r1
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	adds r7, r2, #0
	cmp r0, #0
	beq _081295C2
	b _0812970E
_081295C2:
	ldr r2, _081295F0 @ =0x0000047C
	adds r0, r6, r2
	ldrh r1, [r0]
	ldr r3, _081295F4 @ =0x0000025D
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081295F8
	ldr r0, [r6, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _08129604
	.align 2, 0
_081295DC: .4byte 0x00000121
_081295E0: .4byte 0x00000462
_081295E4: .4byte 0x00000464
_081295E8: .4byte 0x00000316
_081295EC: .4byte 0x0000048A
_081295F0: .4byte 0x0000047C
_081295F4: .4byte 0x0000025D
_081295F8:
	ldr r2, [r6, #0x44]
	ldr r0, _08129630 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_08129604:
	ldr r4, _08129634 @ =0x00000492
	adds r1, r6, r4
	movs r0, #8
	strh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #8
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08129638 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0812963C
	movs r0, #1
	b _0812963E
	.align 2, 0
_08129630: .4byte 0x03003584
_08129634: .4byte 0x00000492
_08129638: .4byte 0x030047A4
_0812963C:
	movs r0, #0
_0812963E:
	cmp r0, #0
	beq _081296AC
	movs r0, #0x94
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r2, [r1]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	bne _081296AC
	cmp r2, #0
	beq _081296AC
	ldr r0, _08129664 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _08129668
	movs r0, #1
	rsbs r0, r0, #0
	b _0812966C
	.align 2, 0
_08129664: .4byte 0x03002C68
_08129668:
	movs r2, #0x18
	ldrsh r0, [r0, r2]
_0812966C:
	cmp r0, #1
	beq _0812968E
	cmp r0, #1
	bgt _0812967A
	cmp r0, #0
	beq _08129684
	b _081296AC
_0812967A:
	cmp r0, #2
	beq _08129698
	cmp r0, #3
	beq _081296A2
	b _081296AC
_08129684:
	ldr r0, [r1]
	cmp r0, #1
	beq _081296AC
	movs r0, #0
	b _081296AE
_0812968E:
	ldr r0, [r1]
	cmp r0, #2
	beq _081296AC
	movs r0, #0
	b _081296AE
_08129698:
	ldr r0, [r1]
	cmp r0, #4
	beq _081296AC
	movs r0, #0
	b _081296AE
_081296A2:
	ldr r0, [r1]
	cmp r0, #8
	beq _081296AC
	movs r0, #0
	b _081296AE
_081296AC:
	movs r0, #1
_081296AE:
	cmp r0, #0
	beq _0812970E
	ldrh r0, [r6]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r4, #0
	ldrsh r1, [r1, r4]
	movs r5, #0x95
	lsls r5, r5, #2
	adds r2, r6, r5
	ldrh r2, [r2]
	ldr r4, _08129784 @ =0x0000025A
	adds r3, r6, r4
	ldrh r3, [r3]
	movs r4, #0
	str r4, [sp]
	bl FUN_0809c344
	add r5, sp, #0xc
	str r4, [sp, #8]
	add r0, sp, #8
	adds r1, r5, #0
	ldr r2, _08129788 @ =0x05000002
	bl CpuSet
	ldr r0, _0812978C @ =0x0000048A
	adds r2, r6, r0
	ldrh r0, [r2]
	cmp r0, #0
	bne _081296F8
	ldr r0, [r7]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _0812970E
_081296F8:
	adds r0, r6, #0
	adds r0, #0xd8
	ldrh r1, [r2]
	adds r3, r6, #0
	adds r3, #8
	str r5, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0
	bl FUN_0805fe7c
_0812970E:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _0812971E
	b _081298F8
_0812971E:
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r6, r3
	movs r2, #0
	strb r1, [r0]
	ldr r4, _08129790 @ =0x00000469
	adds r0, r6, r4
	strb r2, [r0]
	ldr r5, _08129794 @ =0x0000046A
	adds r0, r6, r5
	strb r2, [r0]
	ldr r1, _08129798 @ =0x00000484
	adds r0, r6, r1
	str r2, [r0]
	adds r3, #4
	adds r0, r6, r3
	movs r1, #1
	strb r1, [r0]
	movs r4, #0xba
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r4, [r0]
	movs r3, #0x11
	adds r5, #3
	adds r0, r6, r5
	strb r1, [r0]
	ldr r1, _0812979C @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r5, #0xe6
	adds r0, r6, r5
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r2, [r0]
	ldr r0, _081297A0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081297A4
	movs r0, #1
	b _081297A6
	.align 2, 0
_08129784: .4byte 0x0000025A
_08129788: .4byte 0x05000002
_0812978C: .4byte 0x0000048A
_08129790: .4byte 0x00000469
_08129794: .4byte 0x0000046A
_08129798: .4byte 0x00000484
_0812979C: .4byte 0x0000046B
_081297A0: .4byte 0x030047A4
_081297A4:
	movs r0, #0
_081297A6:
	cmp r0, #0
	beq _081297C0
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r0, [r0]
	movs r5, #0x93
	lsls r5, r5, #3
	adds r1, r6, r5
	ldr r1, [r1]
	bl FUN_080ce544
	b _081298EA
_081297C0:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	ldr r2, _081297E4 @ =0x00000474
	adds r5, r6, r2
	cmp r0, #0
	beq _0812988A
	movs r1, #0x80
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081297E8
	movs r0, #1
	b _081297EA
	.align 2, 0
_081297E4: .4byte 0x00000474
_081297E8:
	movs r0, #0
_081297EA:
	cmp r0, #0
	bne _0812988A
	ldr r3, _08129828 @ =0x000001DF
	adds r0, r6, r3
	ldrb r1, [r0]
	cmp r1, #0xe
	bne _08129804
	movs r4, #0x90
	lsls r4, r4, #3
	adds r0, r6, r4
	ldrh r0, [r0]
	cmp r0, #1
	beq _0812986C
_08129804:
	cmp r1, #5
	beq _0812986C
	cmp r1, #7
	beq _0812986C
	cmp r1, #6
	beq _0812986C
	ldr r2, _0812982C @ =0x030046A0
	ldr r0, [r2]
	ldr r1, _08129830 @ =0x00000948
	adds r3, r0, r1
	ldrh r4, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _08129834 @ =0x0000270E
	cmp r1, r0
	bgt _08129838
	adds r0, r4, #1
	b _0812983C
	.align 2, 0
_08129828: .4byte 0x000001DF
_0812982C: .4byte 0x030046A0
_08129830: .4byte 0x00000948
_08129834: .4byte 0x0000270E
_08129838:
	ldr r1, _08129858 @ =0x0000270F
	adds r0, r1, #0
_0812983C:
	strh r0, [r3]
	ldr r0, [r2]
	movs r3, #0xf8
	lsls r3, r3, #1
	adds r2, r0, r3
	ldrh r3, [r2]
	movs r4, #0
	ldrsh r1, [r2, r4]
	ldr r0, _0812985C @ =0x0000270E
	cmp r1, r0
	bgt _08129860
	adds r0, r3, #1
	b _08129864
	.align 2, 0
_08129858: .4byte 0x0000270F
_0812985C: .4byte 0x0000270E
_08129860:
	ldr r1, _08129898 @ =0x0000270F
	adds r0, r1, #0
_08129864:
	strh r0, [r2]
	adds r0, r6, #0
	bl FUN_080e9178
_0812986C:
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	bl FUN_0807a798
	movs r3, #0x93
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r0, [r0]
	ldr r4, _0812989C @ =0x00000189
	adds r1, r6, r4
	ldrb r1, [r1]
	bl FUN_0807a840
_0812988A:
	movs r1, #0x80
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081298A0
	movs r0, #1
	b _081298A2
	.align 2, 0
_08129898: .4byte 0x0000270F
_0812989C: .4byte 0x00000189
_081298A0:
	movs r0, #0
_081298A2:
	cmp r0, #0
	bne _081298DE
	ldr r0, _081298B8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081298BC
	movs r0, #1
	b _081298BE
	.align 2, 0
_081298B8: .4byte 0x030047A4
_081298BC:
	movs r0, #0
_081298BE:
	cmp r0, #0
	bne _081298DE
	movs r1, #0x80
	lsls r1, r1, #4
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r0, r6, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081298DE
	ldr r0, _08129900 @ =0x03002B28
	ldrh r0, [r0]
	ldrh r1, [r6]
	bl FUN_080ec5b4
_081298DE:
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_081298EA:
	ldr r1, _08129904 @ =0x00000464
	adds r0, r6, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08129908 @ =0x000004BE
	adds r0, r6, r2
	strh r1, [r0]
_081298F8:
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08129900: .4byte 0x03002B28
_08129904: .4byte 0x00000464
_08129908: .4byte 0x000004BE

	thumb_func_start FUN_0812990c
FUN_0812990c: @ 0x0812990C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x44]
	adds r1, r0, #0
	adds r1, #0x48
	ldrh r0, [r1, #0xe]
	cmp r0, #0
	bne _0812995C
	ldrh r0, [r1, #8]
	movs r1, #4
	bl Mod
	adds r3, r0, #0
	movs r2, #0x80
	lsls r2, r2, #9
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	cmp r3, #0
	beq _0812995C
	ldr r1, _08129954 @ =0x00000482
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r2, #1
	cmp r0, #2
	bls _08129948
	movs r2, #2
_08129948:
	ldr r1, _08129958 @ =0x085AD690
	lsls r0, r3, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	muls r0, r2, r0
	b _0812995E
	.align 2, 0
_08129954: .4byte 0x00000482
_08129958: .4byte 0x085AD690
_0812995C:
	movs r0, #0
_0812995E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08129964
FUN_08129964: @ 0x08129964
	push {r4, lr}
	adds r2, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r3, [r0]
	movs r1, #0x40
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0812998E
	ldr r0, _08129994 @ =0x000006FE
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0812998E
	subs r0, #1
	strh r0, [r1]
_0812998E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08129994: .4byte 0x000006FE

	thumb_func_start FUN_08129998
FUN_08129998: @ 0x08129998
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	ldr r0, _081299BC @ =0x00000256
	add r0, r8
	ldrh r0, [r0]
	mov sb, r0
	cmp r1, #1
	bne _081299B0
	b _08129B7C
_081299B0:
	cmp r1, #1
	bgt _081299C0
	cmp r1, #0
	beq _081299CE
	b _0812A080
	.align 2, 0
_081299BC: .4byte 0x00000256
_081299C0:
	cmp r1, #2
	bne _081299C6
	b _08129D2C
_081299C6:
	cmp r1, #3
	bne _081299CC
	b _08129EDC
_081299CC:
	b _0812A080
_081299CE:
	mov r4, sb
	adds r4, #1
	ldr r0, _081299F8 @ =0x00000256
	add r0, r8
	ldrh r1, [r0]
	mov r2, r8
	ldrh r0, [r2, #0xa]
	lsls r0, r0, #0x10
	asrs r7, r0, #0x18
	cmp sb, r1
	bne _08129A58
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081299FC
	adds r0, #4
	b _08129A08
	.align 2, 0
_081299F8: .4byte 0x00000256
_081299FC:
	ldr r0, _08129A24 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129A08:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r7
	bne _08129A3E
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129A28
	adds r0, #4
	b _08129A34
	.align 2, 0
_08129A24: .4byte 0x030046A4
_08129A28:
	ldr r0, _08129A44 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129A34:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _08129A48
_08129A3E:
	movs r0, #0
	b _08129A4A
	.align 2, 0
_08129A44: .4byte 0x030046A4
_08129A48:
	movs r0, #1
_08129A4A:
	cmp r0, #0
	bne _08129A50
	b _08129B62
_08129A50:
	cmp r5, r4
	bne _08129A56
	b _08129B5E
_08129A56:
	b _08129B62
_08129A58:
	ldr r6, _08129A7C @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r2, [r0, r3]
	adds r0, r1, r2
	cmp r4, r0
	bne _08129AC0
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129A80
	adds r0, #4
	b _08129A8A
	.align 2, 0
_08129A7C: .4byte 0x030046A4
_08129A80:
	ldr r0, [r6]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129A8A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r7
	bne _08129A3E
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129AA4
_08129AA0:
	adds r0, #4
	b _08129AB0
_08129AA4:
	ldr r0, _08129ABC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129AB0:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _08129A3E
	b _08129A48
	.align 2, 0
_08129ABC: .4byte 0x030046A4
_08129AC0:
	adds r0, r4, #1
	cmp r0, r1
	bne _08129AFA
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129AD8
	adds r0, #4
	b _08129AE2
_08129AD8:
	ldr r0, [r6]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129AE2:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r7
	bne _08129A3E
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	bne _08129AA0
	b _08129AA4
_08129AFA:
	subs r0, r1, r2
	cmp r4, r0
	bne _08129B62
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129B12
	adds r0, #4
	b _08129B1C
_08129B12:
	ldr r0, [r6]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129B1C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r7
	bne _08129B4C
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129B36
	adds r0, #4
	b _08129B42
_08129B36:
	ldr r0, _08129B50 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129B42:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _08129B54
_08129B4C:
	movs r0, #0
	b _08129B56
	.align 2, 0
_08129B50: .4byte 0x030046A4
_08129B54:
	movs r0, #1
_08129B56:
	cmp r0, #0
	beq _08129B62
	cmp r5, r4
	bne _08129B62
_08129B5E:
	movs r0, #1
	b _08129B64
_08129B62:
	movs r0, #0
_08129B64:
	cmp r0, #0
	bne _08129B6A
	b _0812A080
_08129B6A:
	ldr r0, _08129B78 @ =0x00000256
	add r0, r8
	ldrh r0, [r0]
	adds r0, #1
	mov sb, r0
	b _0812A080
	.align 2, 0
_08129B78: .4byte 0x00000256
_08129B7C:
	ldr r7, _08129BB0 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r2, [r0, r1]
	mov r3, sb
	adds r4, r3, r2
	ldr r0, _08129BB4 @ =0x00000256
	add r0, r8
	ldrh r1, [r0]
	mov r3, r8
	ldrh r0, [r3, #0xa]
	lsls r0, r0, #0x10
	asrs r6, r0, #0x18
	subs r0, r4, #1
	cmp r0, r1
	bne _08129C0C
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129BB8
	adds r0, #4
	b _08129BC2
	.align 2, 0
_08129BB0: .4byte 0x030046A4
_08129BB4: .4byte 0x00000256
_08129BB8:
	ldr r0, [r7]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129BC2:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _08129BF2
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129BDC
	adds r0, #4
	b _08129BE8
_08129BDC:
	ldr r0, _08129BF8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129BE8:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _08129BFC
_08129BF2:
	movs r0, #0
	b _08129BFE
	.align 2, 0
_08129BF8: .4byte 0x030046A4
_08129BFC:
	movs r0, #1
_08129BFE:
	cmp r0, #0
	bne _08129C04
	b _08129D06
_08129C04:
	cmp r5, r4
	bne _08129C0A
	b _08129D02
_08129C0A:
	b _08129D06
_08129C0C:
	adds r0, r1, r2
	cmp r4, r0
	bne _08129C64
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129C24
	adds r0, #4
	b _08129C2E
_08129C24:
	ldr r0, [r7]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129C2E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _08129BF2
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129C48
_08129C44:
	adds r0, #4
	b _08129C54
_08129C48:
	ldr r0, _08129C60 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129C54:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _08129BF2
	b _08129BFC
	.align 2, 0
_08129C60: .4byte 0x030046A4
_08129C64:
	adds r0, r4, #1
	cmp r0, r1
	bne _08129C9E
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129C7C
	adds r0, #4
	b _08129C86
_08129C7C:
	ldr r0, [r7]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129C86:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _08129BF2
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	bne _08129C44
	b _08129C48
_08129C9E:
	subs r0, r1, r2
	cmp r4, r0
	bne _08129D06
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129CB6
	adds r0, #4
	b _08129CC0
_08129CB6:
	ldr r0, [r7]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129CC0:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _08129CF0
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129CDA
	adds r0, #4
	b _08129CE6
_08129CDA:
	ldr r0, _08129CF4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129CE6:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _08129CF8
_08129CF0:
	movs r0, #0
	b _08129CFA
	.align 2, 0
_08129CF4: .4byte 0x030046A4
_08129CF8:
	movs r0, #1
_08129CFA:
	cmp r0, #0
	beq _08129D06
	cmp r5, r4
	bne _08129D06
_08129D02:
	movs r0, #1
	b _08129D08
_08129D06:
	movs r0, #0
_08129D08:
	cmp r0, #0
	bne _08129D0E
	b _0812A080
_08129D0E:
	ldr r1, _08129D24 @ =0x00000256
	add r1, r8
	ldr r0, _08129D28 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	ldrh r1, [r1]
	adds r1, r1, r0
	b _0812A07E
	.align 2, 0
_08129D24: .4byte 0x00000256
_08129D28: .4byte 0x030046A4
_08129D2C:
	mov r4, sb
	subs r4, #1
	ldr r0, _08129D58 @ =0x00000256
	add r0, r8
	ldrh r1, [r0]
	mov r3, r8
	ldrh r0, [r3, #0xa]
	lsls r0, r0, #0x10
	asrs r7, r0, #0x18
	mov r0, sb
	subs r0, #2
	cmp r0, r1
	bne _08129DB8
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129D5C
	adds r0, #4
	b _08129D68
	.align 2, 0
_08129D58: .4byte 0x00000256
_08129D5C:
	ldr r0, _08129D84 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129D68:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r7
	bne _08129D9E
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129D88
	adds r0, #4
	b _08129D94
	.align 2, 0
_08129D84: .4byte 0x030046A4
_08129D88:
	ldr r0, _08129DA4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129D94:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _08129DA8
_08129D9E:
	movs r0, #0
	b _08129DAA
	.align 2, 0
_08129DA4: .4byte 0x030046A4
_08129DA8:
	movs r0, #1
_08129DAA:
	cmp r0, #0
	bne _08129DB0
	b _08129EC2
_08129DB0:
	cmp r5, r4
	bne _08129DB6
	b _08129EBE
_08129DB6:
	b _08129EC2
_08129DB8:
	ldr r6, _08129DDC @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r2, [r0, r3]
	adds r0, r1, r2
	cmp r4, r0
	bne _08129E20
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129DE0
	adds r0, #4
	b _08129DEA
	.align 2, 0
_08129DDC: .4byte 0x030046A4
_08129DE0:
	ldr r0, [r6]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129DEA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r7
	bne _08129D9E
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129E04
_08129E00:
	adds r0, #4
	b _08129E10
_08129E04:
	ldr r0, _08129E1C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129E10:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _08129D9E
	b _08129DA8
	.align 2, 0
_08129E1C: .4byte 0x030046A4
_08129E20:
	cmp sb, r1
	bne _08129E58
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129E36
	adds r0, #4
	b _08129E40
_08129E36:
	ldr r0, [r6]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129E40:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r7
	bne _08129D9E
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	bne _08129E00
	b _08129E04
_08129E58:
	subs r0, r1, r2
	cmp r4, r0
	bne _08129EC2
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129E70
	adds r0, #4
	b _08129E7A
_08129E70:
	ldr r0, [r6]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129E7A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r7
	bne _08129EAA
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129E94
	adds r0, #4
	b _08129EA0
_08129E94:
	ldr r0, _08129EB0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129EA0:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _08129EB4
_08129EAA:
	movs r0, #0
	b _08129EB6
	.align 2, 0
_08129EB0: .4byte 0x030046A4
_08129EB4:
	movs r0, #1
_08129EB6:
	cmp r0, #0
	beq _08129EC2
	cmp r5, r4
	bne _08129EC2
_08129EBE:
	movs r0, #1
	b _08129EC4
_08129EC2:
	movs r0, #0
_08129EC4:
	cmp r0, #0
	bne _08129ECA
	b _0812A080
_08129ECA:
	ldr r0, _08129ED8 @ =0x00000256
	add r0, r8
	ldrh r0, [r0]
	subs r0, #1
	mov sb, r0
	b _0812A080
	.align 2, 0
_08129ED8: .4byte 0x00000256
_08129EDC:
	ldr r7, _08129F10 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r2, [r0, r1]
	mov r3, sb
	subs r4, r3, r2
	ldr r0, _08129F14 @ =0x00000256
	add r0, r8
	ldrh r1, [r0]
	mov r3, r8
	ldrh r0, [r3, #0xa]
	lsls r0, r0, #0x10
	asrs r6, r0, #0x18
	subs r0, r4, #1
	cmp r0, r1
	bne _08129F6C
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129F18
	adds r0, #4
	b _08129F22
	.align 2, 0
_08129F10: .4byte 0x030046A4
_08129F14: .4byte 0x00000256
_08129F18:
	ldr r0, [r7]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129F22:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _08129F52
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129F3C
	adds r0, #4
	b _08129F48
_08129F3C:
	ldr r0, _08129F58 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129F48:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _08129F5C
_08129F52:
	movs r0, #0
	b _08129F5E
	.align 2, 0
_08129F58: .4byte 0x030046A4
_08129F5C:
	movs r0, #1
_08129F5E:
	cmp r0, #0
	bne _08129F64
	b _0812A066
_08129F64:
	cmp r5, r4
	bne _08129F6A
	b _0812A062
_08129F6A:
	b _0812A066
_08129F6C:
	adds r0, r1, r2
	cmp r4, r0
	bne _08129FC4
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129F84
	adds r0, #4
	b _08129F8E
_08129F84:
	ldr r0, [r7]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129F8E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _08129F52
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129FA8
_08129FA4:
	adds r0, #4
	b _08129FB4
_08129FA8:
	ldr r0, _08129FC0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08129FB4:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _08129F52
	b _08129F5C
	.align 2, 0
_08129FC0: .4byte 0x030046A4
_08129FC4:
	adds r0, r4, #1
	cmp r0, r1
	bne _08129FFE
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08129FDC
	adds r0, #4
	b _08129FE6
_08129FDC:
	ldr r0, [r7]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08129FE6:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _08129F52
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	bne _08129FA4
	b _08129FA8
_08129FFE:
	subs r0, r1, r2
	cmp r4, r0
	bne _0812A066
	adds r5, r4, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812A016
	adds r0, #4
	b _0812A020
_0812A016:
	ldr r0, [r7]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0812A020:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r6
	bne _0812A050
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812A03A
	adds r0, #4
	b _0812A046
_0812A03A:
	ldr r0, _0812A054 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812A046:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _0812A058
_0812A050:
	movs r0, #0
	b _0812A05A
	.align 2, 0
_0812A054: .4byte 0x030046A4
_0812A058:
	movs r0, #1
_0812A05A:
	cmp r0, #0
	beq _0812A066
	cmp r5, r4
	bne _0812A066
_0812A062:
	movs r0, #1
	b _0812A068
_0812A066:
	movs r0, #0
_0812A068:
	cmp r0, #0
	beq _0812A080
	ldr r0, _0812A090 @ =0x00000256
	add r0, r8
	ldrh r1, [r0]
	ldr r0, _0812A094 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
_0812A07E:
	mov sb, r1
_0812A080:
	mov r0, sb
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0812A090: .4byte 0x00000256
_0812A094: .4byte 0x030046A4

	thumb_func_start FUN_0812a098
FUN_0812a098: @ 0x0812A098
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov sl, r0
	ldrb r0, [r6, #5]
	adds r0, #0x20
	asrs r0, r0, #6
	adds r4, r0, #2
	movs r0, #3
	ands r4, r0
	movs r7, #0
	movs r5, #0
	b _0812A0C4
_0812A0C2:
	adds r5, #1
_0812A0C4:
	cmp r5, #3
	bgt _0812A0E2
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08129998
	adds r7, r0, #0
	adds r4, #1
	movs r0, #3
	ands r4, r0
	ldr r2, _0812A120 @ =0x00000256
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r7, r0
	beq _0812A0C2
_0812A0E2:
	mov sb, sp
	ldr r5, _0812A124 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812A128
	adds r0, #4
	b _0812A132
	.align 2, 0
_0812A120: .4byte 0x00000256
_0812A124: .4byte 0x030046A4
_0812A128:
	ldr r0, [r5]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0812A132:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, sb
	strh r0, [r1, #2]
	mov r2, r8
	lsls r0, r2, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldrh r1, [r6, #0xa]
	mov r0, sp
	strh r1, [r0, #2]
	ldr r1, _0812A16C @ =0x000004A4
	adds r0, r6, r1
	ldr r4, [r0]
	adds r5, r6, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _0812A170
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r6, r2
	b _0812A194
	.align 2, 0
_0812A16C: .4byte 0x000004A4
_0812A170:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _0812A18E
	cmp r0, #2
	beq _0812A19C
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _0812A19C
_0812A18E:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r6, r1
_0812A194:
	ldr r1, _0812A1B8 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_0812A19C:
	movs r1, #0xe0
	lsls r1, r1, #3
	add r1, sl
	movs r0, #0x1e
	strh r0, [r1]
	movs r0, #1
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0812A1B8: .4byte 0xFFFFFDFF

	thumb_func_start FUN_0812a1bc
FUN_0812a1bc: @ 0x0812A1BC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r0, #0xe6
	lsls r0, r0, #1
	adds r4, r6, r0
	ldr r0, [r4]
	movs r1, #0xe0
	lsls r1, r1, #3
	adds r5, r0, r1
	ldrh r0, [r5]
	adds r7, r0, #0
	cmp r7, #0
	beq _0812A1DC
	subs r0, #1
	strh r0, [r5]
	b _0812A218
_0812A1DC:
	adds r0, r6, #0
	adds r0, #8
	bl FUN_080dd250
	cmp r0, #0
	blt _0812A208
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, _0812A204 @ =0x0000071E
	adds r0, r0, r2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	adds r0, r6, #0
	bl FUN_0812a098
	movs r0, #1
	b _0812A21A
	.align 2, 0
_0812A204: .4byte 0x0000071E
_0812A208:
	ldr r0, [r4]
	ldr r1, _0812A220 @ =0x0000071E
	adds r0, r0, r1
	ldr r1, _0812A224 @ =0xFFFFFBFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	strh r7, [r5]
_0812A218:
	movs r0, #0
_0812A21A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0812A220: .4byte 0x0000071E
_0812A224: .4byte 0xFFFFFBFF

	thumb_func_start FUN_0812a228
FUN_0812a228: @ 0x0812A228
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, _0812A2DC @ =0x03002B68
	ldrh r0, [r0]
	cmp r2, r0
	beq _0812A23A
	b _0812A35E
_0812A23A:
	ldr r5, _0812A2E0 @ =0x03002BE0
	ldr r0, [r5]
	movs r1, #8
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0812A24A
	b _0812A35E
_0812A24A:
	mov r2, sp
	adds r3, r6, #0
	adds r3, #8
	ldrh r0, [r4]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #4
	ldrsh r0, [r2, r3]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r3, #0xfa
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	cmp r1, r0
	bhs _0812A35E
	adds r0, r6, #0
	bl FUN_081280e8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812A35E
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r6, r0
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, _0812A2E4 @ =0x0000071E
	adds r0, r0, r2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, [r5]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #2
	ldr r2, _0812A2E8 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812A2EC
	movs r0, #1
	b _0812A2EE
	.align 2, 0
_0812A2DC: .4byte 0x03002B68
_0812A2E0: .4byte 0x03002BE0
_0812A2E4: .4byte 0x0000071E
_0812A2E8: .4byte 0x00000474
_0812A2EC:
	movs r0, #0
_0812A2EE:
	cmp r0, #0
	beq _0812A308
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0812A304 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0812A314
	.align 2, 0
_0812A304: .4byte 0x03002BE0
_0812A308:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0812A34C
_0812A314:
	ldr r1, [r0]
	movs r2, #8
	ldrsh r5, [r1, r2]
	movs r3, #8
	ldrsh r0, [r6, r3]
	subs r5, r5, r0
	movs r0, #0xc
	ldrsh r4, [r1, r0]
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
_0812A34C:
	movs r0, #0x80
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #1
	b _0812A360
_0812A35E:
	movs r0, #0
_0812A360:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0812a368
FUN_0812a368: @ 0x0812A368
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _0812A394
	cmp r1, #0
	blt _0812A394
	ldr r0, _0812A39C @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _0812A394
	ldr r0, _0812A3A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812A3A8
_0812A394:
	movs r5, #0
	ldr r7, _0812A3A4 @ =0x030046A4
	b _0812A3B8
	.align 2, 0
_0812A39C: .4byte 0x030046A8
_0812A3A0: .4byte 0x030046AC
_0812A3A4: .4byte 0x030046A4
_0812A3A8:
	ldr r2, _0812A3F0 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r3
	adds r7, r2, #0
_0812A3B8:
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812A3F4
	adds r0, #4
	b _0812A3FE
	.align 2, 0
_0812A3F0: .4byte 0x030046A4
_0812A3F4:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0812A3FE:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r6, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0812a41c
FUN_0812a41c: @ 0x0812A41C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #4
	bl FUN_080e64b4
	movs r1, #0x8b
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #8
	bl ClearMemory
	ldr r1, _0812A448 @ =0x00000462
	adds r0, r4, r1
	movs r1, #0
	strh r1, [r0]
	movs r0, #0x8c
	lsls r0, r0, #3
	adds r4, r4, r0
	strh r1, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0812A448: .4byte 0x00000462

	thumb_func_start FUN_0812a44c
FUN_0812a44c: @ 0x0812A44C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r3, _0812A4E0 @ =0xF3FFFFFF
	ldr r0, [r2]
	ands r0, r3
	str r0, [r2]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r6, r4, r1
	ldr r0, _0812A4E4 @ =0xFEFFFFFF
	mov ip, r0
	ldr r0, [r6]
	mov r1, ip
	ands r0, r1
	str r0, [r6]
	ldr r0, _0812A4E8 @ =0x00000482
	adds r1, r4, r0
	movs r7, #0
	movs r0, #1
	strh r0, [r1]
	ldr r1, _0812A4EC @ =0x00000222
	adds r0, r4, r1
	strh r7, [r0]
	adds r1, #0x2c
	adds r0, r4, r1
	strh r7, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r5, r4, r0
	ldr r0, _0812A4F0 @ =0xFFFFFC7F
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	ldr r0, [r2]
	ands r0, r3
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _0812A4CA
	ldr r0, [r6]
	mov r1, ip
	ands r0, r1
	str r0, [r6]
	ldr r0, _0812A4F4 @ =0xFFFFFDFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r0, #0x87
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0812A4F8 @ =0x0000021E
	adds r0, r4, r1
	strh r7, [r0]
	subs r1, #0x1c
	adds r0, r4, r1
	strh r7, [r0]
_0812A4CA:
	ldr r0, _0812A4FC @ =0xFFFFFBFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	ldr r0, _0812A500 @ =0x00000542
	adds r1, r4, r0
	movs r0, #0xff
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812A4E0: .4byte 0xF3FFFFFF
_0812A4E4: .4byte 0xFEFFFFFF
_0812A4E8: .4byte 0x00000482
_0812A4EC: .4byte 0x00000222
_0812A4F0: .4byte 0xFFFFFC7F
_0812A4F4: .4byte 0xFFFFFDFF
_0812A4F8: .4byte 0x0000021E
_0812A4FC: .4byte 0xFFFFFBFF
_0812A500: .4byte 0x00000542

	thumb_func_start FUN_0812a504
FUN_0812a504: @ 0x0812A504
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	ldr r3, _0812A584 @ =0x000006FC
	adds r0, r2, r3
	movs r1, #0
	strh r1, [r0]
	adds r3, #2
	adds r0, r2, r3
	strh r1, [r0]
	adds r3, #2
	adds r0, r2, r3
	strh r1, [r0]
	adds r3, #2
	adds r0, r2, r3
	strh r1, [r0]
	adds r3, #0x1c
	adds r0, r2, r3
	strh r1, [r0]
	ldr r3, _0812A588 @ =0x00000464
	adds r0, r4, r3
	strh r1, [r0]
	ldr r0, _0812A58C @ =0x0000071A
	adds r2, r2, r0
	strh r1, [r2]
	adds r0, r4, #0
	bl FUN_0812a41c
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	adds r0, r4, #0
	bl FUN_080e6204
	ldr r0, [r4, #0x44]
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
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0812A590
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0812A598
	.align 2, 0
_0812A584: .4byte 0x000006FC
_0812A588: .4byte 0x00000464
_0812A58C: .4byte 0x0000071A
_0812A590:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0812A598:
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
	beq _0812A5BC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0812A5C4
_0812A5BC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0812A5C4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0812A5FC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0812A634
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0812A600
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0812A5F4
	ldrb r0, [r4, #5]
_0812A5F4:
	subs r0, #1
	strh r0, [r4, #8]
	b _0812A610
	.align 2, 0
_0812A5FC: .4byte 0x0000FFFF
_0812A600:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0812A610
	strh r1, [r4, #8]
_0812A610:
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
	bne _0812A634
	movs r0, #1
	strb r0, [r4, #7]
_0812A634:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0812a63c
FUN_0812a63c: @ 0x0812A63C
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #3
	rsbs r2, r2, #0
	ldr r1, [r0]
	ands r1, r2
	str r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0812a650
FUN_0812a650: @ 0x0812A650
	push {lr}
	adds r2, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r3, _0812A66C @ =0x00000716
	adds r1, r0, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812A670
	subs r0, #1
	strb r0, [r1]
	b _0812A67E
	.align 2, 0
_0812A66C: .4byte 0x00000716
_0812A670:
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r2, r0
	ldr r1, _0812A684 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_0812A67E:
	pop {r0}
	bx r0
	.align 2, 0
_0812A684: .4byte 0xFEFFFFFF

	thumb_func_start FUN_0812a688
FUN_0812a688: @ 0x0812A688
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, [sp, #8]
	asrs r1, r2, #0x10
	adds r1, #0x40
	lsls r1, r1, #0x10
	ldr r0, _0812A6BC @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r1, [r0]
	cmp r1, #1
	beq _0812A6E4
	cmp r1, #1
	bgt _0812A6C0
	cmp r1, #0
	beq _0812A6C6
	b _0812A79E
	.align 2, 0
_0812A6BC: .4byte 0x0000FFFF
_0812A6C0:
	cmp r1, #2
	beq _0812A748
	b _0812A79E
_0812A6C6:
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0x8c
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r3, [r0]
	str r1, [sp]
	str r1, [sp, #4]
	add r0, sp, #8
	movs r1, #0
	bl FUN_080d8568
	b _0812A79E
_0812A6E4:
	movs r6, #0
	add r4, sp, #8
	movs r7, #0
_0812A6EA:
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldrh r0, [r4, #2]
	adds r0, #0x40
	strh r0, [r4, #2]
	ldr r0, _0812A73C @ =0x085AD6AC
	lsls r1, r6, #1
	adds r0, r1, r0
	ldrh r0, [r0]
	ldrh r2, [r4]
	adds r0, r0, r2
	strh r0, [r4]
	ldr r0, _0812A740 @ =0x085AD6B0
	adds r1, r1, r0
	ldrh r0, [r1]
	ldrh r3, [r4, #4]
	adds r0, r0, r3
	strh r0, [r4, #4]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r2, [r0]
	movs r3, #0x8c
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r3, [r0]
	str r7, [sp]
	ldr r0, _0812A744 @ =0x085AD698
	adds r0, r6, r0
	ldrb r0, [r0]
	str r0, [sp, #4]
	add r0, sp, #8
	movs r1, #0
	bl FUN_080d8568
	adds r6, #1
	cmp r6, #1
	ble _0812A6EA
	b _0812A79E
	.align 2, 0
_0812A73C: .4byte 0x085AD6AC
_0812A740: .4byte 0x085AD6B0
_0812A744: .4byte 0x085AD698
_0812A748:
	movs r6, #0
	add r4, sp, #8
	movs r7, #0
_0812A74E:
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldrh r0, [r4, #2]
	adds r0, #0x40
	strh r0, [r4, #2]
	ldr r0, _0812A7A8 @ =0x085AD69C
	lsls r1, r6, #1
	adds r0, r1, r0
	ldrh r0, [r0]
	ldrh r2, [r4]
	adds r0, r0, r2
	strh r0, [r4]
	ldr r0, _0812A7AC @ =0x085AD6A4
	adds r1, r1, r0
	ldrh r0, [r1]
	ldrh r3, [r4, #4]
	adds r0, r0, r3
	strh r0, [r4, #4]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r2, [r0]
	movs r3, #0x8c
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r3, [r0]
	str r7, [sp]
	ldr r0, _0812A7B0 @ =0x085AD698
	adds r0, r6, r0
	ldrb r0, [r0]
	str r0, [sp, #4]
	add r0, sp, #8
	movs r1, #0
	bl FUN_080d8568
	adds r6, #1
	cmp r6, #3
	ble _0812A74E
_0812A79E:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812A7A8: .4byte 0x085AD69C
_0812A7AC: .4byte 0x085AD6A4
_0812A7B0: .4byte 0x085AD698

	thumb_func_start FUN_0812a7b4
FUN_0812a7b4: @ 0x0812A7B4
	push {lr}
	adds r1, r0, #0
	ldr r2, _0812A7DC @ =0x00000553
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0x26
	beq _0812A7D6
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, [r0]
	ldr r0, _0812A7E0 @ =0x0000071E
	adds r1, r1, r0
	ldr r0, _0812A7E4 @ =0xFFFFEBFF
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
_0812A7D6:
	pop {r0}
	bx r0
	.align 2, 0
_0812A7DC: .4byte 0x00000553
_0812A7E0: .4byte 0x0000071E
_0812A7E4: .4byte 0xFFFFEBFF

	thumb_func_start FUN_0812a7e8
FUN_0812a7e8: @ 0x0812A7E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10c
	adds r7, r0, #0
	movs r0, #0xfd
	bl PlaySound_082406e0
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r5, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldr r1, [r5]
	ands r1, r0
	str r1, [r5]
	movs r1, #0x10
	mov r8, r1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r6, r7, r2
	ldrh r2, [r6]
	adds r1, r2, #0
	adds r0, r1, #0
	mov r3, r8
	ands r0, r3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0812A900
	ldr r5, [r7, #0x24]
	ldr r2, _0812A8E0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0812A8E4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _0812A8E8 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	asrs r0, r0, #3
	ldr r1, [r5, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r5, #2]
	cmp r0, r1
	bne _0812A860
	adds r0, #1
	ldr r1, [r5, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_0812A860:
	movs r4, #0
	strb r0, [r5, #2]
	strb r4, [r5, #3]
	ldr r0, _0812A8EC @ =0x030046A4
	ldr r0, [r0]
	ldr r1, [r0, #0x10]
	ldr r0, [r5, #4]
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	ldrb r0, [r5, #2]
	lsls r0, r0, #3
	adds r1, r1, r0
	str r1, [r5, #8]
	adds r0, r7, #0
	bl FUN_080e6204
	movs r1, #8
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _0812A8F0 @ =0x00000469
	adds r0, r7, r3
	strb r4, [r0]
	ldr r5, _0812A8F4 @ =0x0000046A
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _0812A8F8 @ =0x00000484
	adds r0, r7, r1
	str r4, [r0]
	adds r2, #4
	adds r0, r7, r2
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xb5
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r3, [r0]
	movs r2, #0x13
	adds r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _0812A8FC @ =0x0000046B
	adds r0, r7, r1
	strb r4, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	bl _0812C008
	.align 2, 0
_0812A8E0: .4byte 0x030046B8
_0812A8E4: .4byte 0x000003FF
_0812A8E8: .4byte 0x0203B400
_0812A8EC: .4byte 0x030046A4
_0812A8F0: .4byte 0x00000469
_0812A8F4: .4byte 0x0000046A
_0812A8F8: .4byte 0x00000484
_0812A8FC: .4byte 0x0000046B
_0812A900:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	bne _0812A90C
	b _0812B074
_0812A90C:
	ldr r3, _0812A994 @ =0x000001DD
	adds r0, r7, r3
	ldrb r0, [r0]
	adds r0, #0x80
	strb r0, [r7, #5]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r0, _0812A998 @ =0xFFFFDFDF
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	ldr r5, _0812A99C @ =0x00000544
	adds r1, r7, r5
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, [r1]
	mov r2, r8
	orrs r0, r2
	str r0, [r1]
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r0, [r0]
	strh r4, [r0, #6]
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, _0812A9A0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r3, r7, r3
	ldr r6, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0xdc]
	str r2, [sp, #0xf0]
	cmp r5, #0
	blt _0812A98E
	cmp r1, #0
	blt _0812A98E
	ldr r0, _0812A9A4 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0812A98E
	ldr r0, _0812A9A8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812A9AC
_0812A98E:
	movs r4, #0
	b _0812A9BA
	.align 2, 0
_0812A994: .4byte 0x000001DD
_0812A998: .4byte 0xFFFFDFDF
_0812A99C: .4byte 0x00000544
_0812A9A0: .4byte 0x03002BE0
_0812A9A4: .4byte 0x030046A8
_0812A9A8: .4byte 0x030046AC
_0812A9AC:
	ldr r0, _0812A9CC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0812A9BA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812A9D0
	adds r0, #4
	b _0812A9DC
	.align 2, 0
_0812A9CC: .4byte 0x030046A4
_0812A9D0:
	ldr r0, _0812A9F0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812A9DC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812A9F4
	cmp r2, #2
	beq _0812A9F8
	b _0812A9FC
	.align 2, 0
_0812A9F0: .4byte 0x030046A4
_0812A9F4:
	ldrb r0, [r6, #4]
	b _0812A9FA
_0812A9F8:
	ldrb r0, [r6]
_0812A9FA:
	subs r1, r1, r0
_0812A9FC:
	strh r1, [r6, #2]
	ldr r0, _0812AA10 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0812AA14
	movs r0, #1
	b _0812AA16
	.align 2, 0
_0812AA10: .4byte 0x030047A4
_0812AA14:
	movs r0, #0
_0812AA16:
	cmp r0, #0
	beq _0812AA54
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _0812AA36
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0812AA32
	adds r2, r0, #0
_0812AA32:
	cmp r2, #0
	bge _0812AA40
_0812AA36:
	ldr r6, _0812AA3C @ =0x000005C4
	adds r0, r7, r6
	b _0812AF78
	.align 2, 0
_0812AA3C: .4byte 0x000005C4
_0812AA40:
	ldr r1, _0812AA50 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0812AA9C
	.align 2, 0
_0812AA50: .4byte 0x03002BE0
_0812AA54:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0812AA80
	cmp r1, #0
	blt _0812AA80
	ldr r0, _0812AA84 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0812AA80
	ldr r0, _0812AA88 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812AA8C
_0812AA80:
	movs r5, #0
	b _0812AA9A
	.align 2, 0
_0812AA84: .4byte 0x030046A8
_0812AA88: .4byte 0x030046AC
_0812AA8C:
	ldr r0, _0812AADC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0812AA9A:
	movs r2, #0
_0812AA9C:
	ldr r3, _0812AAE0 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _0812AABC
	ldr r1, _0812AAE4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0812AABC
	b _0812AEBC
_0812AABC:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x18]
	str r2, [sp, #0xfc]
	cmp r1, #0
	beq _0812AAE8
	movs r0, #0
	b _0812AF8E
	.align 2, 0
_0812AADC: .4byte 0x030046A4
_0812AAE0: .4byte 0x00000256
_0812AAE4: .4byte 0x03002BE0
_0812AAE8:
	ldr r5, _0812AB8C @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r6, [sp, #0xfc]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0x104]
	cmp r6, #0
	beq _0812ABAC
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _0812AB90 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x1c]
	movs r5, #1
	strb r5, [r2]
	ldr r3, _0812AB94 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x20]
	movs r4, #0
	strb r4, [r3]
	ldr r6, _0812AB98 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x24]
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x28]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x2c]
	mov r2, sp
	ldrh r2, [r2, #0x18]
	strh r2, [r1]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _0812AB9C @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _0812ABA0 @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _0812ABA4 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x18]
	str r6, [r1]
	ldr r6, _0812ABA8 @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	str r4, [sp, #0xc0]
	str r3, [sp, #0xc4]
	str r2, [sp, #0xc8]
	str r1, [sp, #0xd8]
	str r0, [sp, #0xd0]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0xd4]
	ldr r1, [sp, #0x20]
	str r1, [sp, #0xcc]
	ldr r2, [sp, #0x24]
	str r2, [sp, #0xec]
	ldr r3, [sp, #0x28]
	str r3, [sp, #0xf4]
	ldr r4, [sp, #0x2c]
	str r4, [sp, #0x100]
	b _0812AD7A
	.align 2, 0
_0812AB8C: .4byte 0x00000222
_0812AB90: .4byte 0x0000046D
_0812AB94: .4byte 0x0000046B
_0812AB98: .4byte 0x00000553
_0812AB9C: .4byte 0x00000469
_0812ABA0: .4byte 0x0000046A
_0812ABA4: .4byte 0x00000484
_0812ABA8: .4byte 0x0000046C
_0812ABAC:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0812AC70 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x30]
	strb r0, [r2]
	ldr r3, _0812AC74 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x34]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x4d
	adds r5, r7, r5
	str r5, [sp, #0x38]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x3c]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x40]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x44]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _0812AC78 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _0812AC7C @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _0812AC80 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xdc]
	ldr r0, [r0]
	str r0, [sp, #0x48]
	ldr r1, [sp, #0xf0]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x48]
	strh r1, [r6]
	ldr r6, [sp, #0xf0]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x48]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x44]
	str r0, [sp, #0xc0]
	str r5, [sp, #0xc4]
	str r4, [sp, #0xc8]
	str r3, [sp, #0xd8]
	str r2, [sp, #0xd0]
	ldr r2, [sp, #0x30]
	str r2, [sp, #0xd4]
	ldr r3, [sp, #0x34]
	str r3, [sp, #0xcc]
	ldr r4, [sp, #0x38]
	str r4, [sp, #0xec]
	ldr r5, [sp, #0x3c]
	str r5, [sp, #0xf4]
	ldr r6, [sp, #0x40]
	str r6, [sp, #0x100]
	mov r0, sl
	cmp r0, #0
	blt _0812AC6A
	cmp r1, #0
	blt _0812AC6A
	ldr r0, _0812AC84 @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _0812AC6A
	ldr r0, _0812AC88 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812AC8C
_0812AC6A:
	movs r4, #0
	b _0812AC9C
	.align 2, 0
_0812AC70: .4byte 0x0000046D
_0812AC74: .4byte 0x0000046B
_0812AC78: .4byte 0x00000469
_0812AC7C: .4byte 0x00000484
_0812AC80: .4byte 0x0000046C
_0812AC84: .4byte 0x030046A8
_0812AC88: .4byte 0x030046AC
_0812AC8C:
	ldr r0, _0812ACAC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_0812AC9C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812ACB0
	adds r0, #4
	b _0812ACBC
	.align 2, 0
_0812ACAC: .4byte 0x030046A4
_0812ACB0:
	ldr r0, _0812ACD0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812ACBC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812ACD4
	cmp r2, #2
	beq _0812ACDA
	b _0812ACE0
	.align 2, 0
_0812ACD0: .4byte 0x030046A4
_0812ACD4:
	ldr r2, [sp, #0x48]
	ldrb r0, [r2, #4]
	b _0812ACDE
_0812ACDA:
	ldr r3, [sp, #0x48]
	ldrb r0, [r3]
_0812ACDE:
	subs r1, r1, r0
_0812ACE0:
	ldr r4, [sp, #0x48]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xdc]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0812AD0C
	cmp r1, #0
	blt _0812AD0C
	ldr r0, _0812AD10 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0812AD0C
	ldr r0, _0812AD14 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812AD18
_0812AD0C:
	movs r4, #0
	b _0812AD26
	.align 2, 0
_0812AD10: .4byte 0x030046A8
_0812AD14: .4byte 0x030046AC
_0812AD18:
	ldr r0, _0812AD3C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0812AD26:
	ldr r6, [sp, #0xdc]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812AD40
	adds r0, #4
	b _0812AD4C
	.align 2, 0
_0812AD3C: .4byte 0x030046A4
_0812AD40:
	ldr r0, _0812AD60 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812AD4C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0812AD64
	cmp r3, #2
	beq _0812AD68
	b _0812AD6C
	.align 2, 0
_0812AD60: .4byte 0x030046A4
_0812AD64:
	ldrb r0, [r5, #4]
	b _0812AD6A
_0812AD68:
	ldrb r0, [r5]
_0812AD6A:
	subs r2, r2, r0
_0812AD6C:
	ldr r1, [sp, #0xdc]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xdc]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0812AD7A:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x4c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xfc]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r6, _0812ADA4 @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _0812AE84
	movs r1, #4
	ldr r2, [sp, #0x104]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0812ADA8
	movs r0, #1
	b _0812ADAA
	.align 2, 0
_0812ADA4: .4byte 0x00000482
_0812ADA8:
	movs r0, #0
_0812ADAA:
	ldr r3, _0812AE94 @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _0812AE84
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _0812AE98 @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _0812AE9C @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _0812AEA0 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe8]
	ldr r0, _0812AEA4 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xe0]
	ldr r1, _0812AEA8 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xf8]
	ldr r2, _0812AEAC @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xe4]
	ldr r1, _0812AEB0 @ =0x030046B8
	str r4, [sp, #0x108]
_0812ADF0:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0812AEB4 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _0812AEB8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x108]
	cmp r0, r2
	bne _0812AE16
	adds r3, #1
	cmp r3, #3
	ble _0812ADF0
	adds r0, r4, #0
_0812AE16:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xf4]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xec]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xc0]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xc4]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xc8]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe8]
	strb r0, [r6]
	add r0, sp, #0x4c
	ldrb r1, [r0]
	ldr r0, [sp, #0xe0]
	strb r1, [r0]
	ldr r1, [sp, #0xf8]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xd4]
	strb r1, [r4]
	ldr r6, [sp, #0xcc]
	strb r3, [r6]
	ldr r4, [sp, #0xec]
	strb r0, [r4]
	ldr r6, [sp, #0xf4]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x100]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xc0]
	strb r0, [r4]
	ldr r6, [sp, #0xc4]
	strb r1, [r6]
	ldr r0, [sp, #0xc8]
	strb r2, [r0]
	ldr r2, [sp, #0xd8]
	str r3, [r2]
	ldr r3, [sp, #0xd0]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xe4]
	strb r0, [r4]
_0812AE84:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _0812AF8E
	.align 2, 0
_0812AE94: .4byte 0x00000482
_0812AE98: .4byte 0x0000054F
_0812AE9C: .4byte 0x0000054D
_0812AEA0: .4byte 0x0000054E
_0812AEA4: .4byte 0x00000541
_0812AEA8: .4byte 0x000005BC
_0812AEAC: .4byte 0x00000542
_0812AEB0: .4byte 0x030046B8
_0812AEB4: .4byte 0x000003FF
_0812AEB8: .4byte 0x0203B400
_0812AEBC:
	mov sb, sp
	ldr r6, _0812AEF8 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812AEFC
	adds r0, #4
	b _0812AF06
	.align 2, 0
_0812AEF8: .4byte 0x030046A4
_0812AEFC:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0812AF06:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _0812AF3C @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _0812AF40
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _0812AF66
	.align 2, 0
_0812AF3C: .4byte 0x000004A4
_0812AF40:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _0812AF60
	cmp r0, #2
	beq _0812AF5C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0812AF5C:
	movs r0, #1
	b _0812AF70
_0812AF60:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_0812AF66:
	ldr r1, _0812AF84 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0812AF70:
	cmp r0, #0
	bne _0812AF8C
	ldr r3, _0812AF88 @ =0x000005C4
	adds r0, r7, r3
_0812AF78:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0812AF8E
	.align 2, 0
_0812AF84: .4byte 0xFFFFFDFF
_0812AF88: .4byte 0x000005C4
_0812AF8C:
	movs r0, #1
_0812AF8E:
	cmp r0, #0
	bne _0812B008
	ldr r4, _0812AFC0 @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0812AFC4
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	b _0812AFEA
	.align 2, 0
_0812AFC0: .4byte 0x000004A4
_0812AFC4:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0812AFE4
	cmp r0, #2
	beq _0812AFE0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0812AFE0:
	movs r0, #1
	b _0812AFF4
_0812AFE4:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
_0812AFEA:
	ldr r1, _0812B000 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0812AFF4:
	cmp r0, #0
	bne _0812B008
	ldr r4, _0812B004 @ =0x000005C4
	adds r0, r7, r4
	bl FUN_0812bf9c
	.align 2, 0
_0812B000: .4byte 0xFFFFFDFF
_0812B004: .4byte 0x000005C4
_0812B008:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _0812B060 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _0812B064 @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #0x4d
	adds r0, r7, r5
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _0812B068 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0812B06C @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _0812B070 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	bl FUN_0812c004
	.align 2, 0
_0812B060: .4byte 0x0000046D
_0812B064: .4byte 0x0000046B
_0812B068: .4byte 0x00000469
_0812B06C: .4byte 0x0000046A
_0812B070: .4byte 0x00000484
_0812B074:
	ldr r4, _0812B08C @ =0x00008002
	ands r4, r1
	cmp r4, #0
	beq _0812B090
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	strh r0, [r6]
_0812B084:
	movs r0, #0
	bl FUN_0812c00a
	.align 2, 0
_0812B08C: .4byte 0x00008002
_0812B090:
	ldr r1, _0812B0FC @ =0x0000049C
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _0812B118
	ldr r2, _0812B100 @ =0x000005CC
	adds r0, r7, r2
	ldr r2, [r0]
	movs r1, #0x12
	ldr r3, _0812B104 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _0812B108 @ =0x0000046B
	adds r0, r7, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	subs r6, #0xeb
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0812B10C @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	adds r6, #2
	adds r0, r7, r6
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r7, r1
	str r4, [r0]
	ldr r2, _0812B110 @ =0x0000046C
	adds r0, r7, r2
	strb r3, [r0]
	ldr r1, _0812B114 @ =0xFEFFFFFF
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	bl _0812C008
	.align 2, 0
_0812B0FC: .4byte 0x0000049C
_0812B100: .4byte 0x000005CC
_0812B104: .4byte 0x0000046D
_0812B108: .4byte 0x0000046B
_0812B10C: .4byte 0x00000469
_0812B110: .4byte 0x0000046C
_0812B114: .4byte 0xFEFFFFFF
_0812B118:
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r2
	strh r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0812B084
	ldr r3, _0812B1DC @ =0x000004BE
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _0812B084
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0812B13E
	b _0812B89C
_0812B13E:
	ldr r4, _0812B1E0 @ =0x0000048D
	adds r2, r7, r4
	ldrb r0, [r2]
	cmp r0, #0
	bne _0812B16A
	ldr r5, _0812B1E4 @ =0x0000048C
	adds r0, r7, r5
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0812B16A
	ldr r6, _0812B1DC @ =0x000004BE
	adds r0, r7, r6
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_0812B16A:
	movs r0, #0xec
	lsls r0, r0, #1
	adds r4, r7, r0
	ldr r0, [r4]
	cmp r0, #0
	beq _0812B084
	movs r2, #0x80
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #4
	ldr r5, _0812B1E8 @ =0x00000222
	adds r3, r7, r5
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _0812B1EC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r4]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r4, r7, r6
	ldr r6, [r4]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r4, [sp, #0xdc]
	str r2, [sp, #0xf0]
	str r3, [sp, #0x104]
	cmp r5, #0
	blt _0812B1D6
	cmp r1, #0
	blt _0812B1D6
	ldr r0, _0812B1F0 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0812B1D6
	ldr r0, _0812B1F4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812B1F8
_0812B1D6:
	movs r4, #0
	b _0812B206
	.align 2, 0
_0812B1DC: .4byte 0x000004BE
_0812B1E0: .4byte 0x0000048D
_0812B1E4: .4byte 0x0000048C
_0812B1E8: .4byte 0x00000222
_0812B1EC: .4byte 0x03002BE0
_0812B1F0: .4byte 0x030046A8
_0812B1F4: .4byte 0x030046AC
_0812B1F8:
	ldr r0, _0812B218 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0812B206:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812B21C
	adds r0, #4
	b _0812B228
	.align 2, 0
_0812B218: .4byte 0x030046A4
_0812B21C:
	ldr r0, _0812B23C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812B228:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812B240
	cmp r2, #2
	beq _0812B244
	b _0812B248
	.align 2, 0
_0812B23C: .4byte 0x030046A4
_0812B240:
	ldrb r0, [r6, #4]
	b _0812B246
_0812B244:
	ldrb r0, [r6]
_0812B246:
	subs r1, r1, r0
_0812B248:
	strh r1, [r6, #2]
	ldr r0, _0812B25C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0812B260
	movs r0, #1
	b _0812B262
	.align 2, 0
_0812B25C: .4byte 0x030047A4
_0812B260:
	movs r0, #0
_0812B262:
	cmp r0, #0
	beq _0812B298
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	bne _0812B274
	b _0812B7A8
_0812B274:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0812B280
	adds r2, r0, #0
_0812B280:
	cmp r2, #0
	bge _0812B286
	b _0812B7A8
_0812B286:
	ldr r1, _0812B294 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0812B2E0
	.align 2, 0
_0812B294: .4byte 0x03002BE0
_0812B298:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0812B2C4
	cmp r1, #0
	blt _0812B2C4
	ldr r0, _0812B2C8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0812B2C4
	ldr r0, _0812B2CC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812B2D0
_0812B2C4:
	movs r5, #0
	b _0812B2DE
	.align 2, 0
_0812B2C8: .4byte 0x030046A8
_0812B2CC: .4byte 0x030046AC
_0812B2D0:
	ldr r0, _0812B320 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0812B2DE:
	movs r2, #0
_0812B2E0:
	ldr r4, _0812B324 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0812B300
	ldr r1, _0812B328 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0812B300
	b _0812B6EC
_0812B300:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x50]
	str r2, [sp, #0xfc]
	cmp r1, #0
	beq _0812B32C
	movs r0, #0
	b _0812B7C2
	.align 2, 0
_0812B320: .4byte 0x030046A4
_0812B324: .4byte 0x00000256
_0812B328: .4byte 0x03002BE0
_0812B32C:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r6, [sp, #0x104]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	movs r1, #0x80
	ldr r2, [sp, #0xfc]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _0812B3DC
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r4, _0812B3CC @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0x54]
	movs r5, #1
	strb r5, [r4]
	ldr r6, _0812B3D0 @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x58]
	movs r2, #0
	strb r2, [r6]
	subs r3, #0x65
	adds r3, r7, r3
	str r3, [sp, #0x5c]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x60]
	str r1, [r4]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x64]
	add r0, sp, #0x50
	ldrh r0, [r0]
	strh r0, [r6]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r2, [r4]
	ldr r2, _0812B3D4 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _0812B3D8 @ =0x00000484
	adds r1, r7, r6
	ldr r0, [sp, #0x50]
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	strb r5, [r0]
	str r4, [sp, #0xc0]
	str r3, [sp, #0xc4]
	str r2, [sp, #0xc8]
	str r1, [sp, #0xd8]
	str r0, [sp, #0xd0]
	ldr r0, [sp, #0x54]
	str r0, [sp, #0xd4]
	ldr r1, [sp, #0x58]
	str r1, [sp, #0xcc]
	ldr r2, [sp, #0x5c]
	str r2, [sp, #0xec]
	ldr r3, [sp, #0x60]
	str r3, [sp, #0xf4]
	ldr r4, [sp, #0x64]
	str r4, [sp, #0x100]
	b _0812B5AA
	.align 2, 0
_0812B3CC: .4byte 0x0000046D
_0812B3D0: .4byte 0x0000046B
_0812B3D4: .4byte 0x00000469
_0812B3D8: .4byte 0x00000484
_0812B3DC:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #1
	ldr r6, _0812B49C @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x68]
	strb r0, [r6]
	ldr r3, _0812B4A0 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x4d
	adds r5, r7, r5
	str r5, [sp, #0x70]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x74]
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x78]
	strh r2, [r1]
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x7c]
	strb r4, [r3]
	ldr r4, _0812B4A4 @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r3, _0812B4A8 @ =0x0000046A
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _0812B4AC @ =0x00000484
	adds r3, r7, r6
	str r2, [r3]
	ldr r1, _0812B4B0 @ =0x0000046C
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, [sp, #0xdc]
	ldr r6, [r6]
	str r6, [sp, #0x80]
	ldr r1, [sp, #0xf0]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r6, [sp, #0xf0]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x80]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x7c]
	str r0, [sp, #0xc0]
	str r5, [sp, #0xc4]
	str r4, [sp, #0xc8]
	str r3, [sp, #0xd8]
	str r2, [sp, #0xd0]
	ldr r2, [sp, #0x68]
	str r2, [sp, #0xd4]
	ldr r3, [sp, #0x6c]
	str r3, [sp, #0xcc]
	ldr r4, [sp, #0x70]
	str r4, [sp, #0xec]
	ldr r5, [sp, #0x74]
	str r5, [sp, #0xf4]
	ldr r6, [sp, #0x78]
	str r6, [sp, #0x100]
	mov r0, sb
	cmp r0, #0
	blt _0812B496
	cmp r1, #0
	blt _0812B496
	ldr r0, _0812B4B4 @ =0x030046A8
	ldr r0, [r0]
	cmp sb, r0
	bhs _0812B496
	ldr r0, _0812B4B8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812B4BC
_0812B496:
	movs r4, #0
	b _0812B4CC
	.align 2, 0
_0812B49C: .4byte 0x0000046D
_0812B4A0: .4byte 0x0000046B
_0812B4A4: .4byte 0x00000469
_0812B4A8: .4byte 0x0000046A
_0812B4AC: .4byte 0x00000484
_0812B4B0: .4byte 0x0000046C
_0812B4B4: .4byte 0x030046A8
_0812B4B8: .4byte 0x030046AC
_0812B4BC:
	ldr r0, _0812B4DC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sb
	adds r4, r0, r1
_0812B4CC:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812B4E0
	adds r0, #4
	b _0812B4EC
	.align 2, 0
_0812B4DC: .4byte 0x030046A4
_0812B4E0:
	ldr r0, _0812B500 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812B4EC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812B504
	cmp r2, #2
	beq _0812B50A
	b _0812B510
	.align 2, 0
_0812B500: .4byte 0x030046A4
_0812B504:
	ldr r2, [sp, #0x80]
	ldrb r0, [r2, #4]
	b _0812B50E
_0812B50A:
	ldr r3, [sp, #0x80]
	ldrb r0, [r3]
_0812B50E:
	subs r1, r1, r0
_0812B510:
	ldr r4, [sp, #0x80]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xdc]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0812B53C
	cmp r1, #0
	blt _0812B53C
	ldr r0, _0812B540 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0812B53C
	ldr r0, _0812B544 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812B548
_0812B53C:
	movs r4, #0
	b _0812B556
	.align 2, 0
_0812B540: .4byte 0x030046A8
_0812B544: .4byte 0x030046AC
_0812B548:
	ldr r0, _0812B56C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0812B556:
	ldr r6, [sp, #0xdc]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812B570
	adds r0, #4
	b _0812B57C
	.align 2, 0
_0812B56C: .4byte 0x030046A4
_0812B570:
	ldr r0, _0812B590 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812B57C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0812B594
	cmp r3, #2
	beq _0812B598
	b _0812B59C
	.align 2, 0
_0812B590: .4byte 0x030046A4
_0812B594:
	ldrb r0, [r5, #4]
	b _0812B59A
_0812B598:
	ldrb r0, [r5]
_0812B59A:
	subs r2, r2, r0
_0812B59C:
	ldr r1, [sp, #0xdc]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xdc]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0812B5AA:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x84]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xfc]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r6, _0812B5D4 @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _0812B6B4
	movs r1, #4
	ldr r2, [sp, #0x104]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0812B5D8
	movs r0, #1
	b _0812B5DA
	.align 2, 0
_0812B5D4: .4byte 0x00000482
_0812B5D8:
	movs r0, #0
_0812B5DA:
	ldr r3, _0812B6C4 @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _0812B6B4
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _0812B6C8 @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _0812B6CC @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _0812B6D0 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe8]
	ldr r0, _0812B6D4 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xe0]
	ldr r1, _0812B6D8 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xf8]
	ldr r2, _0812B6DC @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xe4]
	ldr r1, _0812B6E0 @ =0x030046B8
	str r4, [sp, #0x108]
_0812B620:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0812B6E4 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _0812B6E8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x108]
	cmp r0, r2
	bne _0812B646
	adds r3, #1
	cmp r3, #3
	ble _0812B620
	adds r0, r4, #0
_0812B646:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xf4]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xec]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xc0]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xc4]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xc8]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe8]
	strb r0, [r6]
	add r0, sp, #0x84
	ldrb r1, [r0]
	ldr r0, [sp, #0xe0]
	strb r1, [r0]
	ldr r1, [sp, #0xf8]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xd4]
	strb r1, [r4]
	ldr r6, [sp, #0xcc]
	strb r3, [r6]
	ldr r4, [sp, #0xec]
	strb r0, [r4]
	ldr r6, [sp, #0xf4]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x100]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xc0]
	strb r0, [r4]
	ldr r6, [sp, #0xc4]
	strb r1, [r6]
	ldr r0, [sp, #0xc8]
	strb r2, [r0]
	ldr r2, [sp, #0xd8]
	str r3, [r2]
	ldr r3, [sp, #0xd0]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xe4]
	strb r0, [r4]
_0812B6B4:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _0812B7C2
	.align 2, 0
_0812B6C4: .4byte 0x00000482
_0812B6C8: .4byte 0x0000054F
_0812B6CC: .4byte 0x0000054D
_0812B6D0: .4byte 0x0000054E
_0812B6D4: .4byte 0x00000541
_0812B6D8: .4byte 0x000005BC
_0812B6DC: .4byte 0x00000542
_0812B6E0: .4byte 0x030046B8
_0812B6E4: .4byte 0x000003FF
_0812B6E8: .4byte 0x0203B400
_0812B6EC:
	add r6, sp, #8
	ldr r0, _0812B72C @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _0812B730
	adds r0, #4
	b _0812B73C
	.align 2, 0
_0812B72C: .4byte 0x030046A4
_0812B730:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0812B73C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0812B770 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _0812B774
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
	b _0812B79A
	.align 2, 0
_0812B770: .4byte 0x000004A4
_0812B774:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _0812B794
	cmp r0, #2
	beq _0812B790
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0812B790:
	movs r0, #1
	b _0812B7A4
_0812B794:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
_0812B79A:
	ldr r1, _0812B7B8 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0812B7A4:
	cmp r0, #0
	bne _0812B7C0
_0812B7A8:
	ldr r2, _0812B7BC @ =0x000005C4
	adds r0, r7, r2
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0812B7C2
	.align 2, 0
_0812B7B8: .4byte 0xFFFFFDFF
_0812B7BC: .4byte 0x000005C4
_0812B7C0:
	movs r0, #1
_0812B7C2:
	cmp r0, #0
	bne _0812B82E
	ldr r3, _0812B7F4 @ =0x000004A4
	adds r0, r7, r3
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0812B7F8
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
	b _0812B81E
	.align 2, 0
_0812B7F4: .4byte 0x000004A4
_0812B7F8:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0812B818
	cmp r0, #2
	beq _0812B814
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0812B814:
	movs r0, #1
	b _0812B828
_0812B818:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
_0812B81E:
	ldr r1, _0812B884 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0812B828:
	cmp r0, #0
	bne _0812B82E
	b _0812BF98
_0812B82E:
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r4, _0812B888 @ =0x0000046D
	adds r0, r7, r4
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _0812B88C @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _0812B890 @ =0x00000553
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0812B894 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _0812B898 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	b _0812C008
	.align 2, 0
_0812B884: .4byte 0xFFFFFDFF
_0812B888: .4byte 0x0000046D
_0812B88C: .4byte 0x0000046B
_0812B890: .4byte 0x00000553
_0812B894: .4byte 0x0000046A
_0812B898: .4byte 0x00000484
_0812B89C:
	ldr r6, _0812B938 @ =0x0000048D
	adds r2, r7, r6
	ldrb r0, [r2]
	cmp r0, #0
	bne _0812B8C8
	ldr r1, _0812B93C @ =0x0000048C
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0812B8C8
	ldr r3, _0812B940 @ =0x000004BE
	adds r0, r7, r3
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_0812B8C8:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r3, r7, r4
	ldr r0, [r3]
	cmp r0, #0
	bne _0812B8D8
	bl _0812B084
_0812B8D8:
	movs r2, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, _0812B944 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r3]
	adds r3, r7, r6
	ldr r6, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0xdc]
	str r2, [sp, #0xf0]
	cmp r5, #0
	blt _0812B932
	cmp r1, #0
	blt _0812B932
	ldr r0, _0812B948 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0812B932
	ldr r0, _0812B94C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812B950
_0812B932:
	movs r4, #0
	b _0812B95E
	.align 2, 0
_0812B938: .4byte 0x0000048D
_0812B93C: .4byte 0x0000048C
_0812B940: .4byte 0x000004BE
_0812B944: .4byte 0x03002BE0
_0812B948: .4byte 0x030046A8
_0812B94C: .4byte 0x030046AC
_0812B950:
	ldr r0, _0812B970 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0812B95E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812B974
	adds r0, #4
	b _0812B980
	.align 2, 0
_0812B970: .4byte 0x030046A4
_0812B974:
	ldr r0, _0812B994 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812B980:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812B998
	cmp r2, #2
	beq _0812B99C
	b _0812B9A0
	.align 2, 0
_0812B994: .4byte 0x030046A4
_0812B998:
	ldrb r0, [r6, #4]
	b _0812B99E
_0812B99C:
	ldrb r0, [r6]
_0812B99E:
	subs r1, r1, r0
_0812B9A0:
	strh r1, [r6, #2]
	ldr r0, _0812B9B4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0812B9B8
	movs r0, #1
	b _0812B9BA
	.align 2, 0
_0812B9B4: .4byte 0x030047A4
_0812B9B8:
	movs r0, #0
_0812B9BA:
	cmp r0, #0
	beq _0812B9F0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	bne _0812B9CC
	b _0812BF14
_0812B9CC:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0812B9D8
	adds r2, r0, #0
_0812B9D8:
	cmp r2, #0
	bge _0812B9DE
	b _0812BF14
_0812B9DE:
	ldr r1, _0812B9EC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0812BA38
	.align 2, 0
_0812B9EC: .4byte 0x03002BE0
_0812B9F0:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0812BA1C
	cmp r1, #0
	blt _0812BA1C
	ldr r0, _0812BA20 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0812BA1C
	ldr r0, _0812BA24 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812BA28
_0812BA1C:
	movs r5, #0
	b _0812BA36
	.align 2, 0
_0812BA20: .4byte 0x030046A8
_0812BA24: .4byte 0x030046AC
_0812BA28:
	ldr r0, _0812BA78 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0812BA36:
	movs r2, #0
_0812BA38:
	ldr r4, _0812BA7C @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0812BA58
	ldr r1, _0812BA80 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0812BA58
	b _0812BE58
_0812BA58:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x88]
	str r2, [sp, #0xfc]
	cmp r1, #0
	beq _0812BA84
	movs r0, #0
	b _0812BF2E
	.align 2, 0
_0812BA78: .4byte 0x030046A4
_0812BA7C: .4byte 0x00000256
_0812BA80: .4byte 0x03002BE0
_0812BA84:
	ldr r6, _0812BB2C @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0xfc]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	str r2, [sp, #0x104]
	cmp r0, #0
	beq _0812BB44
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _0812BB30 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x8c]
	movs r5, #1
	ldr r6, [sp, #0x8c]
	strb r5, [r6]
	ldr r2, _0812BB34 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x90]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x94]
	strb r0, [r4]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x98]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r7, r0
	str r0, [sp, #0x9c]
	add r1, sp, #0x88
	ldrh r1, [r1]
	strh r1, [r0]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	strb r3, [r4]
	ldr r6, _0812BB38 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _0812BB3C @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x88]
	str r6, [r1]
	ldr r6, _0812BB40 @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	str r4, [sp, #0xc0]
	str r3, [sp, #0xc4]
	str r2, [sp, #0xc8]
	str r1, [sp, #0xd8]
	str r0, [sp, #0xd0]
	ldr r0, [sp, #0x8c]
	str r0, [sp, #0xd4]
	ldr r1, [sp, #0x90]
	str r1, [sp, #0xcc]
	ldr r2, [sp, #0x94]
	str r2, [sp, #0xec]
	ldr r3, [sp, #0x98]
	str r3, [sp, #0xf4]
	ldr r4, [sp, #0x9c]
	str r4, [sp, #0x100]
	b _0812BD16
	.align 2, 0
_0812BB2C: .4byte 0x00000222
_0812BB30: .4byte 0x0000046D
_0812BB34: .4byte 0x0000046B
_0812BB38: .4byte 0x00000469
_0812BB3C: .4byte 0x00000484
_0812BB40: .4byte 0x0000046C
_0812BB44:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #1
	ldr r6, _0812BC08 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0xa0]
	strb r0, [r6]
	ldr r2, _0812BC0C @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _0812BC10 @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #0xa8]
	strb r0, [r4]
	subs r5, #0x28
	adds r5, r7, r5
	str r5, [sp, #0xac]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0xb0]
	mov r1, ip
	strh r1, [r6]
	movs r1, #5
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xb4]
	strb r3, [r2]
	ldr r3, _0812BC14 @ =0x00000469
	adds r5, r7, r3
	movs r4, #0
	strb r4, [r5]
	ldr r6, _0812BC18 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _0812BC1C @ =0x00000484
	adds r3, r7, r1
	mov r2, ip
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xdc]
	ldr r0, [r0]
	str r0, [sp, #0xb8]
	ldr r1, [sp, #0xf0]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0xb8]
	strh r1, [r6]
	ldr r6, [sp, #0xf0]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0xb8]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov r8, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0xb4]
	str r0, [sp, #0xc0]
	str r5, [sp, #0xc4]
	str r4, [sp, #0xc8]
	str r3, [sp, #0xd8]
	str r2, [sp, #0xd0]
	ldr r2, [sp, #0xa0]
	str r2, [sp, #0xd4]
	ldr r3, [sp, #0xa4]
	str r3, [sp, #0xcc]
	ldr r4, [sp, #0xa8]
	str r4, [sp, #0xec]
	ldr r5, [sp, #0xac]
	str r5, [sp, #0xf4]
	ldr r6, [sp, #0xb0]
	str r6, [sp, #0x100]
	mov r0, r8
	cmp r0, #0
	blt _0812BC02
	cmp r1, #0
	blt _0812BC02
	ldr r0, _0812BC20 @ =0x030046A8
	ldr r0, [r0]
	cmp r8, r0
	bhs _0812BC02
	ldr r0, _0812BC24 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812BC28
_0812BC02:
	movs r4, #0
	b _0812BC38
	.align 2, 0
_0812BC08: .4byte 0x0000046D
_0812BC0C: .4byte 0x0000046B
_0812BC10: .4byte 0x00000553
_0812BC14: .4byte 0x00000469
_0812BC18: .4byte 0x0000046A
_0812BC1C: .4byte 0x00000484
_0812BC20: .4byte 0x030046A8
_0812BC24: .4byte 0x030046AC
_0812BC28:
	ldr r0, _0812BC48 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, r8
	adds r4, r0, r1
_0812BC38:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812BC4C
	adds r0, #4
	b _0812BC58
	.align 2, 0
_0812BC48: .4byte 0x030046A4
_0812BC4C:
	ldr r0, _0812BC6C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812BC58:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812BC70
	cmp r2, #2
	beq _0812BC76
	b _0812BC7C
	.align 2, 0
_0812BC6C: .4byte 0x030046A4
_0812BC70:
	ldr r2, [sp, #0xb8]
	ldrb r0, [r2, #4]
	b _0812BC7A
_0812BC76:
	ldr r3, [sp, #0xb8]
	ldrb r0, [r3]
_0812BC7A:
	subs r1, r1, r0
_0812BC7C:
	ldr r4, [sp, #0xb8]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xdc]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0812BCA8
	cmp r1, #0
	blt _0812BCA8
	ldr r0, _0812BCAC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0812BCA8
	ldr r0, _0812BCB0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812BCB4
_0812BCA8:
	movs r4, #0
	b _0812BCC2
	.align 2, 0
_0812BCAC: .4byte 0x030046A8
_0812BCB0: .4byte 0x030046AC
_0812BCB4:
	ldr r0, _0812BCD8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0812BCC2:
	ldr r6, [sp, #0xdc]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812BCDC
	adds r0, #4
	b _0812BCE8
	.align 2, 0
_0812BCD8: .4byte 0x030046A4
_0812BCDC:
	ldr r0, _0812BCFC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812BCE8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0812BD00
	cmp r3, #2
	beq _0812BD04
	b _0812BD08
	.align 2, 0
_0812BCFC: .4byte 0x030046A4
_0812BD00:
	ldrb r0, [r5, #4]
	b _0812BD06
_0812BD04:
	ldrb r0, [r5]
_0812BD06:
	subs r2, r2, r0
_0812BD08:
	ldr r1, [sp, #0xdc]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xdc]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0812BD16:
	ldrb r3, [r7, #5]
	str r3, [sp, #0xbc]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xfc]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r6, _0812BD40 @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _0812BE20
	movs r1, #4
	ldr r2, [sp, #0x104]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0812BD44
	movs r0, #1
	b _0812BD46
	.align 2, 0
_0812BD40: .4byte 0x00000482
_0812BD44:
	movs r0, #0
_0812BD46:
	ldr r3, _0812BE30 @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _0812BE20
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _0812BE34 @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _0812BE38 @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _0812BE3C @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe8]
	ldr r0, _0812BE40 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xe0]
	ldr r1, _0812BE44 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xf8]
	ldr r2, _0812BE48 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xe4]
	ldr r1, _0812BE4C @ =0x030046B8
	str r4, [sp, #0x108]
_0812BD8C:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0812BE50 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _0812BE54 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x108]
	cmp r0, r2
	bne _0812BDB2
	adds r3, #1
	cmp r3, #3
	ble _0812BD8C
	adds r0, r4, #0
_0812BDB2:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xf4]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xec]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xc0]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xc4]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xc8]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe8]
	strb r0, [r6]
	add r0, sp, #0xbc
	ldrb r1, [r0]
	ldr r0, [sp, #0xe0]
	strb r1, [r0]
	ldr r1, [sp, #0xf8]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xd4]
	strb r1, [r4]
	ldr r6, [sp, #0xcc]
	strb r3, [r6]
	ldr r4, [sp, #0xec]
	strb r0, [r4]
	ldr r6, [sp, #0xf4]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x100]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xc0]
	strb r0, [r4]
	ldr r6, [sp, #0xc4]
	strb r1, [r6]
	ldr r0, [sp, #0xc8]
	strb r2, [r0]
	ldr r2, [sp, #0xd8]
	str r3, [r2]
	ldr r3, [sp, #0xd0]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xe4]
	strb r0, [r4]
_0812BE20:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _0812BF2E
	.align 2, 0
_0812BE30: .4byte 0x00000482
_0812BE34: .4byte 0x0000054F
_0812BE38: .4byte 0x0000054D
_0812BE3C: .4byte 0x0000054E
_0812BE40: .4byte 0x00000541
_0812BE44: .4byte 0x000005BC
_0812BE48: .4byte 0x00000542
_0812BE4C: .4byte 0x030046B8
_0812BE50: .4byte 0x000003FF
_0812BE54: .4byte 0x0203B400
_0812BE58:
	add r6, sp, #0x10
	ldr r0, _0812BE98 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _0812BE9C
	adds r0, #4
	b _0812BEA8
	.align 2, 0
_0812BE98: .4byte 0x030046A4
_0812BE9C:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0812BEA8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0812BEDC @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _0812BEE0
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
	b _0812BF06
	.align 2, 0
_0812BEDC: .4byte 0x000004A4
_0812BEE0:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _0812BF00
	cmp r0, #2
	beq _0812BEFC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0812BEFC:
	movs r0, #1
	b _0812BF10
_0812BF00:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
_0812BF06:
	ldr r1, _0812BF24 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0812BF10:
	cmp r0, #0
	bne _0812BF2C
_0812BF14:
	ldr r2, _0812BF28 @ =0x000005C4
	adds r0, r7, r2
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0812BF2E
	.align 2, 0
_0812BF24: .4byte 0xFFFFFDFF
_0812BF28: .4byte 0x000005C4
_0812BF2C:
	movs r0, #1
_0812BF2E:
	cmp r0, #0
	bne _0812BFB0
	ldr r3, _0812BF60 @ =0x000004A4
	adds r0, r7, r3
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0812BF64
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
	b _0812BF8A
	.align 2, 0
_0812BF60: .4byte 0x000004A4
_0812BF64:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0812BF84
	cmp r0, #2
	beq _0812BF80
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0812BF80:
	movs r0, #1
	b _0812BF94
_0812BF84:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
_0812BF8A:
	ldr r1, _0812BFA8 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0812BF94:
	cmp r0, #0
	bne _0812BFB0
_0812BF98:
	ldr r1, _0812BFAC @ =0x000005C4
	adds r0, r7, r1
FUN_0812bf9c:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	bl _0812B084
	.align 2, 0
_0812BFA8: .4byte 0xFFFFFDFF
_0812BFAC: .4byte 0x000005C4
_0812BFB0:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r3, #1
	ldr r4, _0812C01C @ =0x0000046D
	adds r0, r7, r4
	movs r2, #0
	strb r3, [r0]
	ldr r5, _0812C020 @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _0812C024 @ =0x00000553
	adds r0, r7, r6
	strb r3, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r7, r4
	str r1, [r0]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r6, #0xeb
	adds r0, r7, r6
	strb r1, [r0]
	ldr r5, _0812C028 @ =0x00000469
	adds r0, r7, r5
	strb r1, [r0]
	adds r6, #2
	adds r0, r7, r6
	strb r4, [r0]
	ldr r1, _0812C02C @ =0x00000484
	adds r0, r7, r1
	str r2, [r0]
	ldr r2, _0812C030 @ =0x0000046C
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _0812C034 @ =0x00000482
	adds r1, r7, r3
FUN_0812c004:
	movs r0, #3
	strh r0, [r1]
_0812C008:
	movs r0, #1
FUN_0812c00a:
	add sp, #0x10c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0812C01C: .4byte 0x0000046D
_0812C020: .4byte 0x0000046B
_0812C024: .4byte 0x00000553
_0812C028: .4byte 0x00000469
_0812C02C: .4byte 0x00000484
_0812C030: .4byte 0x0000046C
_0812C034: .4byte 0x00000482

	thumb_func_start FUN_0812c038
FUN_0812c038: @ 0x0812C038
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x84
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r5, [r0]
	ldr r2, _0812C060 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812C064
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0812C066
	.align 2, 0
_0812C060: .4byte 0x0000046C
_0812C064:
	movs r0, #0
_0812C066:
	cmp r0, #0
	beq _0812C09C
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r4, _0812C104 @ =FUN_0812238c
	movs r3, #3
	ldr r6, _0812C108 @ =0x0000046D
	adds r1, r7, r6
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0812C10C @ =0x0000046B
	adds r0, r7, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r7, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r2, [r0]
_0812C09C:
	ldr r4, _0812C10C @ =0x0000046B
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812C0A8
	b _0812C792
_0812C0A8:
	ldr r6, _0812C110 @ =0x0000071E
	adds r2, r5, r6
	ldr r0, _0812C114 @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, _0812C118 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r3, r7, r1
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x5c]
	str r2, [sp, #0x60]
	cmp r4, #0
	blt _0812C0FE
	cmp r1, #0
	blt _0812C0FE
	ldr r0, _0812C11C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0812C0FE
	ldr r0, _0812C120 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812C124
_0812C0FE:
	movs r4, #0
	b _0812C132
	.align 2, 0
_0812C104: .4byte FUN_0812238c
_0812C108: .4byte 0x0000046D
_0812C10C: .4byte 0x0000046B
_0812C110: .4byte 0x0000071E
_0812C114: .4byte 0xFFFFF7FF
_0812C118: .4byte 0x03002BE0
_0812C11C: .4byte 0x030046A8
_0812C120: .4byte 0x030046AC
_0812C124:
	ldr r0, _0812C144 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0812C132:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812C148
	adds r0, #4
	b _0812C154
	.align 2, 0
_0812C144: .4byte 0x030046A4
_0812C148:
	ldr r0, _0812C168 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812C154:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812C16C
	cmp r2, #2
	beq _0812C170
	b _0812C174
	.align 2, 0
_0812C168: .4byte 0x030046A4
_0812C16C:
	ldrb r0, [r5, #4]
	b _0812C172
_0812C170:
	ldrb r0, [r5]
_0812C172:
	subs r1, r1, r0
_0812C174:
	strh r1, [r5, #2]
	ldr r0, _0812C188 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0812C18C
	movs r0, #1
	b _0812C18E
	.align 2, 0
_0812C188: .4byte 0x030047A4
_0812C18C:
	movs r0, #0
_0812C18E:
	cmp r0, #0
	beq _0812C1CC
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _0812C1AE
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0812C1AA
	adds r2, r0, #0
_0812C1AA:
	cmp r2, #0
	bge _0812C1B8
_0812C1AE:
	ldr r3, _0812C1B4 @ =0x000005C4
	adds r0, r7, r3
	b _0812C6EC
	.align 2, 0
_0812C1B4: .4byte 0x000005C4
_0812C1B8:
	ldr r1, _0812C1C8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0812C214
	.align 2, 0
_0812C1C8: .4byte 0x03002BE0
_0812C1CC:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0812C1F8
	cmp r1, #0
	blt _0812C1F8
	ldr r0, _0812C1FC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0812C1F8
	ldr r0, _0812C200 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812C204
_0812C1F8:
	movs r5, #0
	b _0812C212
	.align 2, 0
_0812C1FC: .4byte 0x030046A8
_0812C200: .4byte 0x030046AC
_0812C204:
	ldr r0, _0812C254 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0812C212:
	movs r2, #0
_0812C214:
	ldr r6, _0812C258 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _0812C234
	ldr r1, _0812C25C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0812C234
	b _0812C630
_0812C234:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	str r2, [sp, #0x34]
	cmp r1, #0
	beq _0812C260
	movs r0, #0
	b _0812C702
	.align 2, 0
_0812C254: .4byte 0x030046A4
_0812C258: .4byte 0x00000256
_0812C25C: .4byte 0x03002BE0
_0812C260:
	ldr r3, _0812C300 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0x34]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0x64]
	cmp r6, #0
	beq _0812C314
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _0812C304 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #8]
	movs r3, #1
	strb r3, [r2]
	ldr r4, _0812C308 @ =0x0000046B
	adds r4, r4, r7
	mov sb, r4
	movs r6, #0
	strb r6, [r4]
	ldr r2, _0812C30C @ =0x00000553
	adds r2, r7, r2
	str r2, [sp, #0xc]
	strb r0, [r2]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r3, r7
	mov sl, r3
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r5, r7, r4
	mov r6, r8
	strh r6, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	movs r2, #0
	strb r2, [r4]
	ldr r6, _0812C310 @ =0x00000469
	adds r3, r7, r6
	strb r2, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	adds r6, #0x1b
	adds r1, r7, r6
	mov r0, r8
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	str r0, [sp, #0x48]
	ldr r0, [sp, #8]
	str r0, [sp, #0x4c]
	mov r6, sb
	str r6, [sp, #0x44]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x7c]
	mov r6, sl
	str r6, [sp, #0x80]
	str r5, [sp, #0x58]
	str r4, [sp, #0x38]
	str r3, [sp, #0x3c]
	str r2, [sp, #0x40]
	str r1, [sp, #0x54]
	b _0812C4E6
	.align 2, 0
_0812C300: .4byte 0x00000222
_0812C304: .4byte 0x0000046D
_0812C308: .4byte 0x0000046B
_0812C30C: .4byte 0x00000553
_0812C310: .4byte 0x00000469
_0812C314:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0812C3D4 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x10]
	strb r0, [r2]
	ldr r3, _0812C3D8 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x14]
	movs r4, #0
	strb r4, [r3]
	ldr r2, _0812C3DC @ =0x00000553
	adds r2, r7, r2
	str r2, [sp, #0x18]
	strb r0, [r2]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x1c]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x20]
	strh r6, [r4]
	movs r1, #5
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x24]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _0812C3E0 @ =0x00000469
	adds r5, r7, r4
	strb r3, [r5]
	ldr r2, _0812C3E4 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _0812C3E8 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _0812C3EC @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x5c]
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldr r1, [sp, #0x60]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x28]
	strh r1, [r6]
	ldr r6, [sp, #0x60]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x28]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r2, [sp, #0x48]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x4c]
	ldr r2, [sp, #0x14]
	str r2, [sp, #0x44]
	ldr r6, [sp, #0x18]
	str r6, [sp, #0x7c]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x80]
	ldr r2, [sp, #0x20]
	str r2, [sp, #0x58]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0x38]
	str r5, [sp, #0x3c]
	str r4, [sp, #0x40]
	str r3, [sp, #0x54]
	mov r0, ip
	cmp r0, #0
	blt _0812C3D0
	cmp r1, #0
	blt _0812C3D0
	ldr r0, _0812C3F0 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _0812C3D0
	ldr r0, _0812C3F4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812C3F8
_0812C3D0:
	movs r4, #0
	b _0812C408
	.align 2, 0
_0812C3D4: .4byte 0x0000046D
_0812C3D8: .4byte 0x0000046B
_0812C3DC: .4byte 0x00000553
_0812C3E0: .4byte 0x00000469
_0812C3E4: .4byte 0x0000046A
_0812C3E8: .4byte 0x00000484
_0812C3EC: .4byte 0x0000046C
_0812C3F0: .4byte 0x030046A8
_0812C3F4: .4byte 0x030046AC
_0812C3F8:
	ldr r0, _0812C418 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_0812C408:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812C41C
	adds r0, #4
	b _0812C428
	.align 2, 0
_0812C418: .4byte 0x030046A4
_0812C41C:
	ldr r0, _0812C43C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812C428:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812C440
	cmp r2, #2
	beq _0812C446
	b _0812C44C
	.align 2, 0
_0812C43C: .4byte 0x030046A4
_0812C440:
	ldr r2, [sp, #0x28]
	ldrb r0, [r2, #4]
	b _0812C44A
_0812C446:
	ldr r3, [sp, #0x28]
	ldrb r0, [r3]
_0812C44A:
	subs r1, r1, r0
_0812C44C:
	ldr r4, [sp, #0x28]
	strh r1, [r4, #2]
	ldr r6, [sp, #0x5c]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0812C478
	cmp r1, #0
	blt _0812C478
	ldr r0, _0812C47C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0812C478
	ldr r0, _0812C480 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812C484
_0812C478:
	movs r4, #0
	b _0812C492
	.align 2, 0
_0812C47C: .4byte 0x030046A8
_0812C480: .4byte 0x030046AC
_0812C484:
	ldr r0, _0812C4A8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0812C492:
	ldr r0, [sp, #0x5c]
	ldr r5, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812C4AC
	adds r0, #4
	b _0812C4B8
	.align 2, 0
_0812C4A8: .4byte 0x030046A4
_0812C4AC:
	ldr r0, _0812C4CC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812C4B8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0812C4D0
	cmp r3, #2
	beq _0812C4D4
	b _0812C4D8
	.align 2, 0
_0812C4CC: .4byte 0x030046A4
_0812C4D0:
	ldrb r0, [r5, #4]
	b _0812C4D6
_0812C4D4:
	ldrb r0, [r5]
_0812C4D6:
	subs r2, r2, r0
_0812C4D8:
	ldr r1, [sp, #0x5c]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x5c]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0812C4E6:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x2c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x34]
	ldrh r0, [r4]
	ands r0, r1
	mov r8, r3
	ldr r6, _0812C510 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x50]
	cmp r0, #0
	bne _0812C5F4
	movs r1, #4
	ldr r2, [sp, #0x64]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0812C514
	movs r0, #1
	b _0812C516
	.align 2, 0
_0812C510: .4byte 0x00000482
_0812C514:
	movs r0, #0
_0812C516:
	ldr r3, _0812C604 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x50]
	cmp r0, #0
	bne _0812C5F4
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _0812C608 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _0812C60C @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x70]
	ldr r2, _0812C610 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x74]
	ldr r4, _0812C614 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x78]
	ldr r6, _0812C618 @ =0x00000541
	adds r6, r7, r6
	str r6, [sp, #0x68]
	ldr r0, _0812C61C @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x30]
	ldr r1, _0812C620 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x6c]
	ldr r6, _0812C624 @ =0x0203B400
	ldr r1, _0812C628 @ =0x030046B8
	ldr r5, _0812C62C @ =0x000003FF
	movs r4, #3
	mov r2, r8
_0812C566:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r4
	lsls r0, r0, #6
	cmp r0, r2
	bne _0812C584
	adds r3, #1
	cmp r3, #3
	ble _0812C566
	mov r0, r8
_0812C584:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x80]
	ldr r0, [r4]
	mov r6, sl
	str r0, [r6]
	ldr r1, [sp, #0x7c]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x38]
	ldrb r0, [r4]
	ldr r6, [sp, #0x70]
	strb r0, [r6]
	ldr r1, [sp, #0x3c]
	ldrb r0, [r1]
	ldr r2, [sp, #0x74]
	strb r0, [r2]
	ldr r4, [sp, #0x40]
	ldrb r0, [r4]
	ldr r6, [sp, #0x78]
	strb r0, [r6]
	add r0, sp, #0x2c
	ldrb r1, [r0]
	ldr r0, [sp, #0x68]
	strb r1, [r0]
	ldr r1, [sp, #0x30]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x4c]
	strb r1, [r4]
	ldr r6, [sp, #0x44]
	strb r3, [r6]
	ldr r4, [sp, #0x7c]
	strb r0, [r4]
	ldr r6, [sp, #0x80]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x58]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x38]
	strb r0, [r4]
	ldr r6, [sp, #0x3c]
	strb r1, [r6]
	ldr r0, [sp, #0x40]
	strb r2, [r0]
	ldr r2, [sp, #0x54]
	str r3, [r2]
	ldr r3, [sp, #0x48]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x6c]
	strb r0, [r4]
_0812C5F4:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r6, [sp, #0x50]
	strh r0, [r6]
	movs r0, #0
	b _0812C702
	.align 2, 0
_0812C604: .4byte 0x00000482
_0812C608: .4byte 0x0000054F
_0812C60C: .4byte 0x0000054C
_0812C610: .4byte 0x0000054D
_0812C614: .4byte 0x0000054E
_0812C618: .4byte 0x00000541
_0812C61C: .4byte 0x000005BC
_0812C620: .4byte 0x00000542
_0812C624: .4byte 0x0203B400
_0812C628: .4byte 0x030046B8
_0812C62C: .4byte 0x000003FF
_0812C630:
	mov sb, sp
	ldr r6, _0812C66C @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812C670
	adds r0, #4
	b _0812C67A
	.align 2, 0
_0812C66C: .4byte 0x030046A4
_0812C670:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0812C67A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r6, r8
	lsls r0, r6, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r1, _0812C6B0 @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _0812C6B4
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	b _0812C6DA
	.align 2, 0
_0812C6B0: .4byte 0x000004A4
_0812C6B4:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _0812C6D4
	cmp r0, #2
	beq _0812C6D0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0812C6D0:
	movs r0, #1
	b _0812C6E4
_0812C6D4:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
_0812C6DA:
	ldr r1, _0812C6F8 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0812C6E4:
	cmp r0, #0
	bne _0812C700
	ldr r4, _0812C6FC @ =0x000005C4
	adds r0, r7, r4
_0812C6EC:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0812C702
	.align 2, 0
_0812C6F8: .4byte 0xFFFFFDFF
_0812C6FC: .4byte 0x000005C4
_0812C700:
	movs r0, #1
_0812C702:
	cmp r0, #0
	beq _0812C792
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r2, _0812C7A4 @ =FUN_080e6794
	movs r1, #0xe
	ldr r6, _0812C7A8 @ =0x0000046D
	adds r0, r7, r6
	movs r5, #0
	movs r3, #1
	mov sb, r3
	mov r4, sb
	strb r4, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r5, [r0]
	ldr r3, _0812C7AC @ =0x00000553
	adds r0, r7, r3
	strb r1, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r7, r4
	str r2, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r7, r6
	movs r3, #0
	strh r5, [r0]
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r4, [r0]
	movs r2, #0xc
	mov sl, r2
	movs r1, #0x1e
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r7, r6
	subs r6, #4
	adds r0, r7, r6
	str r1, [r0]
	str r4, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r3, [r0]
	ldr r2, _0812C7B0 @ =0x00000551
	adds r0, r7, r2
	strb r3, [r0]
	ldr r4, _0812C7B4 @ =0x00000552
	adds r0, r7, r4
	mov r6, sl
	strb r6, [r0]
	movs r1, #3
	subs r2, #0xe9
	adds r0, r7, r2
	strb r1, [r0]
	subs r4, #0xe9
	adds r0, r7, r4
	mov r6, sb
	strb r6, [r0]
	ldr r1, _0812C7B8 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	adds r2, #0x1c
	adds r0, r7, r2
	str r5, [r0]
	ldr r3, _0812C7BC @ =0x0000046C
	adds r0, r7, r3
	strb r6, [r0]
_0812C792:
	add sp, #0x84
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812C7A4: .4byte FUN_080e6794
_0812C7A8: .4byte 0x0000046D
_0812C7AC: .4byte 0x00000553
_0812C7B0: .4byte 0x00000551
_0812C7B4: .4byte 0x00000552
_0812C7B8: .4byte 0x0000046A
_0812C7BC: .4byte 0x0000046C

	thumb_func_start FUN_0812c7c0
FUN_0812c7c0: @ 0x0812C7C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0812C7EC @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812C7F0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0812C7F2
	.align 2, 0
_0812C7EC: .4byte 0x0000046C
_0812C7F0:
	movs r0, #0
_0812C7F2:
	cmp r0, #0
	beq _0812C828
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r4, _0812C924 @ =FUN_081222ec
	movs r3, #0x25
	ldr r0, _0812C928 @ =0x0000046D
	adds r1, r7, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0812C92C @ =0x0000046B
	adds r0, r7, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r7, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r7, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r7, r4
	strh r2, [r0]
_0812C828:
	ldr r1, _0812C92C @ =0x0000046B
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812C834
	b _0812C99A
_0812C834:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r5, r7, r2
	ldr r1, _0812C930 @ =0xFFFFFEFF
	ldrh r0, [r5]
	ands r1, r0
	movs r6, #0
	strh r1, [r5]
	ldr r4, _0812C934 @ =0x0000071E
	add r4, r8
	ldr r0, _0812C938 @ =0xFFFFF7FF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r3, _0812C93C @ =0x00000222
	adds r2, r7, r3
	movs r0, #7
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	ldr r1, _0812C940 @ =FUN_081251f4
	movs r0, #0x26
	ldr r4, _0812C928 @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp]
	movs r2, #1
	strb r2, [r4]
	ldr r3, _0812C92C @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #4]
	strb r6, [r3]
	ldr r4, _0812C944 @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #8]
	strb r0, [r4]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0xc]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x10]
	movs r3, #0
	strh r3, [r1]
	movs r0, #0x10
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x14]
	strb r6, [r4]
	ldr r1, _0812C948 @ =0x00000469
	adds r1, r1, r7
	mov r8, r1
	strb r6, [r1]
	ldr r3, _0812C94C @ =0x0000046A
	adds r3, r3, r7
	mov sb, r3
	strb r0, [r3]
	ldr r4, _0812C950 @ =0x00000484
	adds r4, r4, r7
	mov sl, r4
	movs r0, #0
	str r0, [r4]
	ldr r1, _0812C954 @ =0x0000046C
	adds r4, r7, r1
	strb r2, [r4]
	ldr r2, _0812C958 @ =0x000004A4
	adds r0, r7, r2
	ldr r6, [r0]
	adds r3, r7, #0
	adds r3, #8
	adds r0, r6, #0
	adds r1, r3, #0
	adds r2, r3, #0
	str r3, [sp, #0x30]
	bl FUN_0823599c
	str r4, [sp, #0x20]
	ldr r4, [sp]
	str r4, [sp, #0x24]
	ldr r1, [sp, #4]
	str r1, [sp, #0x1c]
	ldr r4, [sp, #8]
	ldr r2, [sp, #0xc]
	str r2, [sp, #0x28]
	ldr r1, [sp, #0x10]
	str r1, [sp, #0x2c]
	ldr r2, [sp, #0x14]
	str r2, [sp, #0x18]
	ldr r3, [sp, #0x30]
	cmp r0, #0
	beq _0812C95C
	adds r0, r6, #0
	adds r1, r3, #0
	adds r2, r3, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0812C95C
	cmp r0, #2
	beq _0812C920
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0812C920:
	movs r0, #1
	b _0812C966
	.align 2, 0
_0812C924: .4byte FUN_081222ec
_0812C928: .4byte 0x0000046D
_0812C92C: .4byte 0x0000046B
_0812C930: .4byte 0xFFFFFEFF
_0812C934: .4byte 0x0000071E
_0812C938: .4byte 0xFFFFF7FF
_0812C93C: .4byte 0x00000222
_0812C940: .4byte FUN_081251f4
_0812C944: .4byte 0x00000553
_0812C948: .4byte 0x00000469
_0812C94C: .4byte 0x0000046A
_0812C950: .4byte 0x00000484
_0812C954: .4byte 0x0000046C
_0812C958: .4byte 0x000004A4
_0812C95C:
	ldr r0, _0812C9AC @ =0xFFFFFDFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r0, #0
_0812C966:
	adds r3, r0, #0
	cmp r3, #0
	bne _0812C99A
	ldr r0, _0812C9B0 @ =FUN_080e48d0
	movs r2, #1
	ldr r1, [sp, #0x24]
	strb r2, [r1]
	ldr r1, [sp, #0x1c]
	strb r3, [r1]
	strb r3, [r4]
	ldr r4, [sp, #0x28]
	str r0, [r4]
	movs r1, #0
	ldr r0, [sp, #0x2c]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x18]
	strb r0, [r4]
	mov r0, r8
	strb r1, [r0]
	mov r4, sb
	strb r1, [r4]
	mov r0, sl
	str r3, [r0]
	ldr r1, [sp, #0x20]
	strb r2, [r1]
_0812C99A:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812C9AC: .4byte 0xFFFFFDFF
_0812C9B0: .4byte FUN_080e48d0

	thumb_func_start FUN_0812c9b4
FUN_0812c9b4: @ 0x0812C9B4
	ldr r1, _0812C9C0 @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _0812C9C4 @ =0x085AD6B4
	str r1, [r0]
	bx lr
	.align 2, 0
_0812C9C0: .4byte 0x0000063C
_0812C9C4: .4byte 0x085AD6B4

	thumb_func_start FUN_0812c9c8
FUN_0812c9c8: @ 0x0812C9C8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08125d08
	movs r1, #0x80
	lsls r1, r1, #6
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0812C9EC
	ldr r1, _0812CA1C @ =0x000004BE
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0812CA0C
_0812C9EC:
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrb r0, [r0]
	ldr r2, _0812CA20 @ =0x0000062C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e4964
_0812CA0C:
	adds r0, r4, #0
	bl FUN_08125d30
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0812CA1C: .4byte 0x000004BE
_0812CA20: .4byte 0x0000062C

	thumb_func_start FUN_0812ca24
FUN_0812ca24: @ 0x0812CA24
	push {lr}
	bl FUN_080f06b0
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start EnemyMummy_Destroy
EnemyMummy_Destroy: @ 0x0812CA30
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _0812CA48 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812CA4C
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _0812CA54
	.align 2, 0
_0812CA48: .4byte 0x0000025D
_0812CA4C:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_0812CA54:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _0812CA70 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _0812CA74
	movs r0, #1
	b _0812CA76
	.align 2, 0
_0812CA70: .4byte 0x00000474
_0812CA74:
	movs r0, #0
_0812CA76:
	cmp r0, #0
	beq _0812CA82
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_0812CA82:
	ldr r1, _0812CADC @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _0812CA9A
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_0812CA9A:
	ldr r0, _0812CAE0 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _0812CAB2
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_0812CAB2:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0812CACA
	adds r0, r4, #0
	bl FUN_08002a58
_0812CACA:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0812CAE4
	movs r0, #1
	b _0812CAE6
	.align 2, 0
_0812CADC: .4byte 0x0000044C
_0812CAE0: .4byte 0x0000044D
_0812CAE4:
	movs r0, #0
_0812CAE6:
	cmp r0, #0
	beq _0812CAF2
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_0812CAF2:
	adds r0, r4, #0
	bl FUN_0823b284
	adds r0, r4, #0
	adds r0, #0xd8
	bl FUN_08236424
	adds r0, r4, #0
	bl FUN_080ec6fc
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start EnemyMummy_Init
EnemyMummy_Init: @ 0x0812CB0C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1b0
	adds r7, r0, #0
	str r7, [sp, #0x24]
	ldr r1, _0812CB98 @ =0x0000071E
	adds r0, r7, r1
	movs r6, #0
	strh r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	ldr r2, _0812CB9C @ =0x000001DF
	adds r0, r7, r2
	movs r3, #1
	mov r8, r3
	mov r4, r8
	strb r4, [r0]
	adds r0, r7, #0
	bl FUN_081291ec
	ldr r5, _0812CBA0 @ =0x0000025D
	adds r0, r7, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812CBAC
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _0812CBA4 @ =0x000048DE
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _0812CBA8 @ =0x0000A4B2
	bl FUN_080e3804
	ldr r6, _0812CB9C @ =0x000001DF
	adds r0, r7, r6
	ldrb r1, [r0]
	str r0, [sp, #0x44]
	cmp r1, #0x11
	beq _0812CB88
	cmp r1, #0x17
	bne _0812CB8C
_0812CB88:
	mov r0, r8
	strb r0, [r5, #7]
_0812CB8C:
	movs r2, #0xef
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0
	strb r0, [r1]
	b _0812CC14
	.align 2, 0
_0812CB98: .4byte 0x0000071E
_0812CB9C: .4byte 0x000001DF
_0812CBA0: .4byte 0x0000025D
_0812CBA4: .4byte 0x000048DE
_0812CBA8: .4byte 0x0000A4B2
_0812CBAC:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r3, sp, #0x14
	mov r8, r3
	str r6, [sp, #0x10]
	add r0, sp, #0x10
	mov r1, r8
	ldr r2, _0812CC94 @ =0x05000002
	bl CpuSet
	ldr r0, _0812CC98 @ =0x0000CB05
	ldr r1, _0812CC9C @ =0x000048DE
	bl GetFile
	adds r1, r0, #0
	adds r2, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r5, r6}
	stm r2!, {r5, r6}
	adds r0, r4, #0
	bl OpenSpriteSetFile
	adds r0, r4, #0
	adds r0, #0x20
	movs r1, #2
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r1, r8
	str r1, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	ldr r2, _0812CCA0 @ =0x000004B7
	adds r1, r7, r2
	movs r0, #0xff
	strb r0, [r1]
	ldr r3, _0812CCA4 @ =0x000001DF
	adds r3, r7, r3
	str r3, [sp, #0x44]
_0812CC14:
	str r7, [sp, #0x28]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r4, r4, r7
	mov sb, r4
	movs r4, #0
	mov r5, sb
	str r4, [r5]
	movs r6, #0xbe
	lsls r6, r6, #1
	adds r6, r6, r7
	mov r8, r6
	str r4, [r6]
	ldr r1, _0812CCA8 @ =0x0000046F
	adds r0, r7, r1
	strb r4, [r0]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r3, #0
	mov sl, r3
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r5, _0812CCAC @ =0x00000474
	adds r6, r7, r5
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _0812CC94 @ =0x05000002
	bl CpuSet
	ldr r0, _0812CCB0 @ =0x000004B6
	adds r2, r7, r0
	mov r1, sl
	strb r1, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1ac]
	bl VM_SeekToKeyword
	mov r3, sb
	str r3, [sp, #0x180]
	mov r4, r8
	str r4, [sp, #0x188]
	str r6, [sp, #0x164]
	ldr r2, [sp, #0x1ac]
	adds r6, r2, #0
	cmp r0, #0
	bne _0812CC82
	b _0812CDE4
_0812CC82:
	bl VM_GetPC
	cmp r0, #0
	beq _0812CCB4
	bl Script_GetValue
	adds r1, r0, #0
	b _0812CCB6
	.align 2, 0
_0812CC94: .4byte 0x05000002
_0812CC98: .4byte 0x0000CB05
_0812CC9C: .4byte 0x000048DE
_0812CCA0: .4byte 0x000004B7
_0812CCA4: .4byte 0x000001DF
_0812CCA8: .4byte 0x0000046F
_0812CCAC: .4byte 0x00000474
_0812CCB0: .4byte 0x000004B6
_0812CCB4:
	movs r1, #0
_0812CCB6:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	movs r0, #0
	strb r1, [r5]
	ldr r1, _0812CCDC @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x80]
	str r4, [sp, #0x88]
	cmp r0, #0
	beq _0812CCE0
	bl Script_GetValue
	adds r1, r0, #0
	b _0812CCE2
	.align 2, 0
_0812CCDC: .4byte 0x00000251
_0812CCE0:
	movs r1, #0
_0812CCE2:
	ldr r2, _0812CD18 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _0812CD1C @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0x80]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0x90]
	cmp r0, #0
	beq _0812CD20
	bl Script_GetValue
	b _0812CD24
	.align 2, 0
_0812CD18: .4byte 0x00000252
_0812CD1C: .4byte 0x000004B4
_0812CD20:
	ldr r4, [sp, #0x80]
	ldrb r0, [r4]
_0812CD24:
	strb r0, [r6]
	ldr r5, [sp, #0x80]
	ldrb r1, [r5]
	ldr r6, [sp, #0x90]
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
	blt _0812CD5C
	cmp r1, #0
	blt _0812CD5C
	ldr r0, _0812CD60 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0812CD5C
	ldr r0, _0812CD64 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812CD68
_0812CD5C:
	movs r1, #0
	b _0812CD76
	.align 2, 0
_0812CD60: .4byte 0x030046A8
_0812CD64: .4byte 0x030046AC
_0812CD68:
	ldr r0, _0812CD90 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0812CD76:
	ldr r2, _0812CD94 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0812CD98
	adds r0, #4
	b _0812CDA4
	.align 2, 0
_0812CD90: .4byte 0x030046A4
_0812CD94: .4byte 0x00000256
_0812CD98:
	ldr r0, _0812CDB8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812CDA4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812CDBC
	cmp r2, #2
	beq _0812CDC0
	b _0812CDC4
	.align 2, 0
_0812CDB8: .4byte 0x030046A4
_0812CDBC:
	ldrb r0, [r4, #4]
	b _0812CDC2
_0812CDC0:
	ldrb r0, [r4]
_0812CDC2:
	subs r1, r1, r0
_0812CDC4:
	ldr r3, _0812CDDC @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _0812CDE0 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _0812CE24
	.align 2, 0
_0812CDDC: .4byte 0x00000472
_0812CDE0: .4byte 0x0000FFFF
_0812CDE4:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _0812CE48 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _0812CE4C @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _0812CE50 @ =0x000004B4
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
	str r5, [sp, #0x80]
	str r4, [sp, #0x88]
	str r3, [sp, #0x90]
_0812CE24:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0812CE6E
	bl VM_GetPC
	cmp r0, #0
	beq _0812CE54
	bl Script_GetValue
	adds r4, r0, #0
	b _0812CE56
	.align 2, 0
_0812CE48: .4byte 0x00000251
_0812CE4C: .4byte 0x00000252
_0812CE50: .4byte 0x000004B4
_0812CE54:
	movs r4, #0x30
_0812CE56:
	bl VM_GetPC
	cmp r0, #0
	beq _0812CE68
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _0812CE6A
_0812CE68:
	movs r5, #0x40
_0812CE6A:
	mov r8, r4
	b _0812CE74
_0812CE6E:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_0812CE74:
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0812CEAC
	bl VM_GetPC
	cmp r0, #0
	beq _0812CE8E
	bl Script_GetValue
	adds r6, r0, #0
	b _0812CE90
_0812CE8E:
	movs r6, #0
_0812CE90:
	bl VM_GetPC
	cmp r0, #0
	beq _0812CEA0
	bl Script_GetValue
	adds r1, r0, #0
	b _0812CEA2
_0812CEA0:
	movs r1, #0
_0812CEA2:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _0812CEB6
_0812CEAC:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_0812CEB6:
	movs r0, #0x61
	bl VM_SeekToKeyword
	ldr r1, _0812D144 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0xa8]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x70]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x19c]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x198]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x94]
	lsls r4, r4, #0x10
	str r4, [sp, #0x40]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x4c]
	lsls r6, r6, #0x10
	str r6, [sp, #0x50]
	lsls r5, r5, #0x10
	str r5, [sp, #0x48]
	ldr r4, _0812D148 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0xa0]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x3c]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x148]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x54]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x58]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x14c]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x150]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x144]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x17c]
	ldr r1, _0812D14C @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x170]
	ldr r2, _0812D150 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x174]
	ldr r3, _0812D154 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x178]
	ldr r4, _0812D158 @ =0x00000476
	adds r4, r7, r4
	str r4, [sp, #0x168]
	movs r5, #0x8f
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x16c]
	ldr r6, _0812D15C @ =0x000004A4
	adds r6, r7, r6
	str r6, [sp, #0x190]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x194]
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xb0]
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xb8]
	movs r4, #0xb2
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xc0]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xd0]
	ldr r6, _0812D160 @ =0x000005A4
	adds r6, r7, r6
	str r6, [sp, #0xd4]
	movs r1, #0xb8
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xe8]
	ldr r2, _0812D164 @ =0x000005C4
	adds r2, r7, r2
	str r2, [sp, #0xec]
	ldr r3, _0812D168 @ =0x000005CC
	adds r3, r7, r3
	str r3, [sp, #0xf4]
	movs r4, #0xba
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xf8]
	ldr r5, _0812D16C @ =0x000005D4
	adds r5, r7, r5
	str r5, [sp, #0xfc]
	ldr r6, _0812D170 @ =0x000005DC
	adds r6, r7, r6
	str r6, [sp, #0x104]
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xf0]
	ldr r2, _0812D174 @ =0x00000584
	adds r2, r7, r2
	str r2, [sp, #0xb4]
	ldr r3, _0812D178 @ =0x00000604
	adds r3, r7, r3
	str r3, [sp, #0x128]
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x12c]
	ldr r5, _0812D17C @ =0x0000021D
	adds r5, r7, r5
	str r5, [sp, #0x5c]
	ldr r6, _0812D180 @ =0x0000060C
	adds r6, r7, r6
	str r6, [sp, #0x130]
	movs r1, #0xbe
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x118]
	ldr r2, _0812D184 @ =0x000005E4
	adds r2, r7, r2
	str r2, [sp, #0x10c]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x11c]
	ldr r4, _0812D188 @ =0x000005FC
	adds r4, r7, r4
	str r4, [sp, #0x120]
	movs r5, #0xc0
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x124]
	ldr r6, _0812D18C @ =0x00000614
	adds r6, r7, r6
	str r6, [sp, #0x134]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x138]
	ldr r2, _0812D190 @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0xe4]
	movs r3, #0xbd
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x110]
	movs r4, #0xbc
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x108]
	ldr r5, _0812D194 @ =0x000005EC
	adds r5, r7, r5
	str r5, [sp, #0x114]
	movs r6, #0xbb
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x100]
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xd8]
	ldr r2, _0812D198 @ =0x00000624
	adds r2, r7, r2
	str r2, [sp, #0x13c]
	ldr r3, _0812D19C @ =0x0000058C
	adds r3, r7, r3
	str r3, [sp, #0xbc]
	movs r4, #0xc5
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x140]
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xe0]
	ldr r6, _0812D1A0 @ =0x00000594
	adds r6, r7, r6
	str r6, [sp, #0xc4]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xc8]
	ldr r2, _0812D1A4 @ =0x0000059C
	adds r2, r7, r2
	str r2, [sp, #0xcc]
	ldr r3, _0812D1A8 @ =0x000005B4
	adds r3, r7, r3
	str r3, [sp, #0xdc]
	ldr r4, _0812D1AC @ =0x00000543
	adds r4, r7, r4
	str r4, [sp, #0x60]
	adds r5, r7, #0
	adds r5, #0xd8
	str r5, [sp, #0x154]
	movs r6, #0xcc
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x1a0]
	movs r1, #0xcd
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x1a4]
	ldr r2, _0812D1B0 @ =0x00000496
	adds r2, r7, r2
	str r2, [sp, #0x18c]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x158]
	ldr r4, _0812D1B4 @ =0x00000469
	adds r4, r7, r4
	str r4, [sp, #0x15c]
	ldr r5, _0812D1B8 @ =0x0000046A
	adds r5, r7, r5
	str r5, [sp, #0x160]
	ldr r6, _0812D1BC @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x64]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xac]
	movs r2, #0x92
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x184]
	movs r3, #0xea
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x38]
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x34]
	ldr r5, _0812D1C0 @ =0x00000572
	adds r5, r7, r5
	str r5, [sp, #0xa4]
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x30]
	movs r1, #0xae
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x9c]
	ldr r2, _0812D1C4 @ =0x0000055C
	adds r2, r7, r2
	str r2, [sp, #0x68]
	movs r3, #0xac
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	ldr r4, _0812D1C8 @ =0x00000564
	adds r4, r7, r4
	str r4, [sp, #0x74]
	ldr r5, _0812D1CC @ =0x00000565
	adds r5, r7, r5
	str r5, [sp, #0x78]
	ldr r6, _0812D1D0 @ =0x00000566
	adds r6, r7, r6
	str r6, [sp, #0x7c]
	ldr r1, _0812D1D4 @ =0x00000567
	adds r1, r7, r1
	str r1, [sp, #0x84]
	movs r2, #0xad
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x8c]
	ldr r3, _0812D1D8 @ =0x0000056C
	adds r3, r7, r3
	str r3, [sp, #0x98]
	cmp r0, #0
	bne _0812D114
	b _0812D234
_0812D114:
	movs r4, #0
	mov sl, r4
	movs r5, #0x8d
	lsls r5, r5, #2
	adds r5, r5, r7
	mov sb, r5
	movs r6, #0x8f
	lsls r6, r6, #2
	adds r6, r6, r7
	mov r8, r6
	movs r0, #0x8b
	lsls r0, r0, #2
	adds r5, r7, r0
	movs r1, #0x89
	lsls r1, r1, #2
	adds r4, r7, r1
_0812D134:
	bl VM_GetPC
	cmp r0, #0
	beq _0812D1DC
	bl Script_GetValue
	b _0812D1DE
	.align 2, 0
_0812D144: .4byte 0x0000025D
_0812D148: .4byte 0x0000025A
_0812D14C: .4byte 0x0000047A
_0812D150: .4byte 0x0000047C
_0812D154: .4byte 0x0000047E
_0812D158: .4byte 0x00000476
_0812D15C: .4byte 0x000004A4
_0812D160: .4byte 0x000005A4
_0812D164: .4byte 0x000005C4
_0812D168: .4byte 0x000005CC
_0812D16C: .4byte 0x000005D4
_0812D170: .4byte 0x000005DC
_0812D174: .4byte 0x00000584
_0812D178: .4byte 0x00000604
_0812D17C: .4byte 0x0000021D
_0812D180: .4byte 0x0000060C
_0812D184: .4byte 0x000005E4
_0812D188: .4byte 0x000005FC
_0812D18C: .4byte 0x00000614
_0812D190: .4byte 0x000005BC
_0812D194: .4byte 0x000005EC
_0812D198: .4byte 0x00000624
_0812D19C: .4byte 0x0000058C
_0812D1A0: .4byte 0x00000594
_0812D1A4: .4byte 0x0000059C
_0812D1A8: .4byte 0x000005B4
_0812D1AC: .4byte 0x00000543
_0812D1B0: .4byte 0x00000496
_0812D1B4: .4byte 0x00000469
_0812D1B8: .4byte 0x0000046A
_0812D1BC: .4byte 0x00000553
_0812D1C0: .4byte 0x00000572
_0812D1C4: .4byte 0x0000055C
_0812D1C8: .4byte 0x00000564
_0812D1CC: .4byte 0x00000565
_0812D1D0: .4byte 0x00000566
_0812D1D4: .4byte 0x00000567
_0812D1D8: .4byte 0x0000056C
_0812D1DC:
	movs r0, #0x18
_0812D1DE:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _0812D1F0
	bl Script_GetValue
	b _0812D1F2
_0812D1F0:
	movs r0, #0x18
_0812D1F2:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _0812D204
	bl Script_GetValue
	b _0812D206
_0812D204:
	movs r0, #0
_0812D206:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _0812D218
	bl Script_GetValue
	b _0812D21A
_0812D218:
	movs r0, #0
_0812D21A:
	strh r0, [r6]
	movs r2, #2
	add sb, r2
	movs r3, #4
	add r8, r3
	adds r5, #2
	adds r4, #2
	movs r6, #1
	add sl, r6
	mov r0, sl
	cmp r0, #3
	bgt _0812D234
	b _0812D134
_0812D234:
	movs r0, #0x6c
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0812D280
	bl VM_GetPC
	cmp r0, #0
	beq _0812D24E
	bl Script_GetValue
	adds r4, r0, #0
	b _0812D252
_0812D24E:
	movs r4, #0x96
	lsls r4, r4, #1
_0812D252:
	bl VM_GetPC
	cmp r0, #0
	beq _0812D262
	bl Script_GetValue
	adds r6, r0, #0
	b _0812D266
_0812D262:
	movs r6, #0x96
	lsls r6, r6, #1
_0812D266:
	bl VM_GetPC
	cmp r0, #0
	beq _0812D274
	bl Script_GetValue
	b _0812D27A
_0812D274:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
_0812D27A:
	ldr r2, [sp, #0x70]
	strh r0, [r2]
	b _0812D288
_0812D280:
	movs r4, #0
	movs r6, #0
	ldr r3, [sp, #0x70]
	strh r6, [r3]
_0812D288:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _0812D2A0
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x188]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0812D2A0:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x19c]
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, [sp, #0x198]
	strh r0, [r2]
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0812D370
	bl VM_GetPC
	cmp r0, #0
	beq _0812D2D0
	bl Script_GetValue
	b _0812D2D2
_0812D2D0:
	movs r0, #0
_0812D2D2:
	ldr r3, [sp, #0x94]
	strh r0, [r3]
	ldrh r0, [r3]
	cmp r0, #0
	blt _0812D2E0
	asrs r1, r0, #1
	b _0812D2E6
_0812D2E0:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_0812D2E6:
	ldr r5, _0812D2FC @ =0x00000546
	adds r0, r7, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0812D300
	bl Script_GetValue
	b _0812D302
	.align 2, 0
_0812D2FC: .4byte 0x00000546
_0812D300:
	movs r0, #0
_0812D302:
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0812D318
	bl Script_GetValue
	b _0812D31A
_0812D318:
	movs r0, #0
_0812D31A:
	ldr r3, _0812D330 @ =0x00000187
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0812D334
	bl Script_GetValue
	adds r1, r0, #0
	b _0812D336
	.align 2, 0
_0812D330: .4byte 0x00000187
_0812D334:
	movs r1, #0
_0812D336:
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0812D34C
	bl Script_GetValue
	b _0812D34E
_0812D34C:
	movs r0, #0
_0812D34E:
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0812D366
	bl Script_GetValue
	adds r1, r0, #0
	b _0812D368
_0812D366:
	movs r1, #0
_0812D368:
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_0812D370:
	ldr r5, [sp, #0x94]
	ldrh r1, [r5]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r6, [sp, #0x40]
	lsrs r2, r6, #0x10
	ldr r0, [sp, #0x4c]
	lsrs r3, r0, #0x10
	ldr r1, [sp, #0x50]
	lsrs r0, r1, #0x10
	str r0, [sp]
	ldr r4, [sp, #0x48]
	lsrs r0, r4, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0812D3D2
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r6, r7, r5
	bl VM_GetPC
	cmp r0, #0
	beq _0812D3B8
	bl Script_GetValue
	b _0812D3BA
_0812D3B8:
	movs r0, #0
_0812D3BA:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _0812D3CA
	bl Script_GetValue
	b _0812D3CC
_0812D3CA:
	movs r0, #0
_0812D3CC:
	ldr r6, _0812D434 @ =0x00000189
	adds r1, r7, r6
	strb r0, [r1]
_0812D3D2:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetKeywordValue
	ldr r1, [sp, #0xa0]
	strh r0, [r1]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _0812D3F6
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x188]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_0812D3F6:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _0812D40E
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r3, [sp, #0x188]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_0812D40E:
	ldr r4, [sp, #0x3c]
	lsrs r1, r4, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x28]
	add r2, sp, #0x1c
	movs r3, #0
	bl FUN_0823b400
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x164]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0812D438
	movs r0, #1
	b _0812D43A
	.align 2, 0
_0812D434: .4byte 0x00000189
_0812D438:
	movs r0, #0
_0812D43A:
	cmp r0, #0
	beq _0812D44A
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _0812D474 @ =FUN_080f48ac
	ldr r1, [sp, #0x28]
	bl FUN_0807f558
_0812D44A:
	ldr r6, [sp, #0xa8]
	ldrb r0, [r6]
	movs r1, #0
	cmp r0, #0
	bne _0812D456
	ldr r1, [r7, #0x44]
_0812D456:
	ldr r0, [sp, #0x28]
	bl FUN_0823b46c
	ldr r1, [sp, #0x44]
	ldrb r0, [r1]
	cmp r0, #0x15
	bne _0812D478
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x148]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _0812D484
	.align 2, 0
_0812D474: .4byte FUN_080f48ac
_0812D478:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x148]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_0812D484:
	ldr r2, [sp, #0x44]
	ldrb r1, [r2]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0812D4D2
	adds r0, r1, #0
	cmp r0, #0xb
	beq _0812D4D2
	cmp r0, #0x16
	beq _0812D4D2
	cmp r0, #0x14
	beq _0812D4D2
	cmp r0, #9
	beq _0812D4D2
	cmp r0, #0x19
	beq _0812D4D2
	cmp r0, #0x1a
	beq _0812D4D2
	cmp r0, #0xd
	beq _0812D4D2
	cmp r0, #0x1b
	beq _0812D4D2
	cmp r0, #0x1f
	beq _0812D4D2
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r3, [sp, #0x80]
	ldrb r2, [r3]
	ldr r4, [sp, #0x88]
	ldrb r3, [r4]
	ldr r5, [sp, #0x90]
	ldrb r0, [r5]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl FUN_0823b490
_0812D4D2:
	movs r1, #8
	ldr r6, [sp, #0x164]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0812D4E2
	movs r0, #1
	b _0812D4E4
_0812D4E2:
	movs r0, #0
_0812D4E4:
	cmp r0, #0
	beq _0812D4F2
	ldr r1, [sp, #0x58]
	ldr r0, [r1]
	ldr r2, [sp, #0x54]
	str r0, [r2]
	b _0812D504
_0812D4F2:
	ldr r3, [sp, #0x58]
	ldr r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r4, [sp, #0x54]
	str r0, [r4]
_0812D504:
	ldrh r0, [r7]
	ldr r5, [sp, #0x14c]
	strh r0, [r5]
	ldr r6, [sp, #0x144]
	ldr r0, [sp, #0x150]
	str r6, [r0]
	ldr r1, [sp, #0x2c]
	cmp r1, #0
	beq _0812D52E
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
	ldr r2, [sp, #0x28]
	strb r0, [r2, #5]
_0812D52E:
	movs r4, #0x17
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r3, [sp, #0x17c]
	strh r0, [r3]
	ldr r6, [sp, #0x170]
	strh r4, [r6]
	ldr r0, [sp, #0x174]
	strh r5, [r0]
	ldrh r0, [r3]
	adds r0, #0x17
	ldr r1, [sp, #0x178]
	strh r0, [r1]
	ldrh r1, [r6]
	ldrh r0, [r3]
	adds r1, r1, r0
	ldr r2, [sp, #0xa8]
	ldrb r0, [r2]
	cmp r0, #0
	bne _0812D568
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _0812D574
_0812D568:
	ldr r2, [r7, #0x44]
	ldr r0, _0812D5AC @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_0812D574:
	ldr r3, [sp, #0xa8]
	ldrb r0, [r3]
	cmp r0, #1
	bne _0812D5C4
	ldr r4, [sp, #0x44]
	ldrb r0, [r4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0812D5B0
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
	b _0812D5BA
	.align 2, 0
_0812D5AC: .4byte 0x03003584
_0812D5B0:
	ldr r5, [sp, #0x44]
	ldrb r0, [r5]
	bl FUN_080ecf60
	adds r4, r0, #1
_0812D5BA:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_0812D5C4:
	ldr r6, _0812D7B0 @ =0x0000047A
	adds r0, r7, r6
	ldrh r0, [r0]
	adds r0, #3
	ldr r2, _0812D7B4 @ =0x0000047E
	adds r1, r7, r2
	movs r4, #0
	strh r0, [r1]
	ldr r3, [sp, #0x170]
	ldrh r0, [r3]
	adds r0, #4
	ldr r5, [sp, #0x168]
	strh r0, [r5]
	ldrh r0, [r3]
	ldr r6, [sp, #0x16c]
	strh r0, [r6]
	adds r0, r7, #0
	bl FUN_08129158
	ldr r1, [sp, #0x24]
	movs r2, #0xe4
	lsls r2, r2, #3
	adds r0, r1, r2
	ldr r3, _0812D7B8 @ =0x00000744
	adds r1, r1, r3
	mov r8, r1
	ldr r5, _0812D7BC @ =FUN_0812c9c8
	mov sb, r5
	ldr r6, _0812D7C0 @ =FUN_0812990c
	mov sl, r6
	ldr r1, _0812D7C4 @ =FUN_081224b8
	mov ip, r1
	ldr r5, _0812D7C8 @ =FUN_08123a88
	ldr r3, _0812D7CC @ =FUN_080f62b0
	ldr r2, _0812D7D0 @ =FUN_080f62ac
	str r2, [sp, #0x1a8]
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x180]
	ldr r1, [r6]
	orrs r1, r2
	str r1, [r6]
	ldr r1, [sp, #0x190]
	str r0, [r1]
	mov r2, r8
	ldr r6, [sp, #0x194]
	str r2, [r6]
	mov r1, sb
	ldr r2, [sp, #0xb0]
	str r1, [r2]
	mov r6, sl
	ldr r1, [sp, #0xb8]
	str r6, [r1]
	mov r2, ip
	ldr r6, [sp, #0xc0]
	str r2, [r6]
	ldr r1, _0812D7D4 @ =FUN_08122458
	ldr r2, [sp, #0xd0]
	str r1, [r2]
	ldr r6, _0812D7D8 @ =FUN_08122494
	ldr r1, [sp, #0xd4]
	str r6, [r1]
	ldr r2, _0812D7DC @ =FUN_0812359c
	ldr r6, [sp, #0xe8]
	str r2, [r6]
	ldr r1, [sp, #0xec]
	str r3, [r1]
	ldr r2, [sp, #0xf4]
	str r5, [r2]
	ldr r3, _0812D7E0 @ =FUN_08124cf8
	ldr r5, [sp, #0xf8]
	str r3, [r5]
	ldr r1, _0812D7E4 @ =FUN_080f44f4
	ldr r6, [sp, #0xfc]
	str r1, [r6]
	ldr r1, _0812D7E8 @ =FUN_080f410c
	ldr r2, [sp, #0x104]
	str r1, [r2]
	ldr r3, _0812D7EC @ =FUN_08123034
	ldr r5, [sp, #0xf0]
	str r3, [r5]
	ldr r6, _0812D7F0 @ =FUN_081231d4
	ldr r1, [sp, #0xb4]
	str r6, [r1]
	ldr r2, [sp, #0x1a8]
	ldr r3, [sp, #0x128]
	str r2, [r3]
	ldr r1, _0812D7F4 @ =FUN_080f0430
	ldr r5, [sp, #0x12c]
	str r1, [r5]
	movs r1, #3
	ldr r6, [sp, #0x5c]
	strb r1, [r6]
	ldr r1, _0812D7F8 @ =0x085AD470
	ldr r2, [sp, #0x130]
	str r1, [r2]
	ldr r1, _0812D7FC @ =FUN_080e73c8
	ldr r3, [sp, #0x118]
	str r1, [r3]
	ldr r5, [sp, #0x10c]
	str r4, [r5]
	ldr r6, [sp, #0x11c]
	str r4, [r6]
	ldr r1, [sp, #0x120]
	str r4, [r1]
	ldr r2, [sp, #0x124]
	str r4, [r2]
	ldr r3, [sp, #0x134]
	str r4, [r3]
	ldr r1, _0812D800 @ =FUN_080f0320
	ldr r5, [sp, #0x138]
	str r1, [r5]
	ldr r1, _0812D804 @ =FUN_080eff14
	ldr r6, [sp, #0xe4]
	str r1, [r6]
	ldr r1, _0812D808 @ =FUN_080e72b0
	ldr r2, [sp, #0x110]
	str r1, [r2]
	ldr r3, _0812D80C @ =FUN_08122388
	ldr r5, [sp, #0x108]
	str r3, [r5]
	ldr r1, _0812D810 @ =FUN_080f47c8
	ldr r6, [sp, #0x114]
	str r1, [r6]
	ldr r1, _0812D814 @ =FUN_080f54e4
	ldr r2, [sp, #0x100]
	str r1, [r2]
	ldr r3, [sp, #0xd8]
	str r4, [r3]
	ldr r1, _0812D818 @ =FUN_080f6e64
	ldr r5, [sp, #0x13c]
	str r1, [r5]
	ldr r1, _0812D81C @ =FUN_080f64f0
	ldr r6, [sp, #0xbc]
	str r1, [r6]
	ldr r1, _0812D820 @ =FUN_080f84d4
	ldr r2, [sp, #0x140]
	str r1, [r2]
	ldr r1, _0812D824 @ =FUN_080f624c
	ldr r3, [sp, #0xe0]
	str r1, [r3]
	ldr r1, _0812D828 @ =FUN_080f56ec
	ldr r5, [sp, #0xc4]
	str r1, [r5]
	ldr r1, _0812D82C @ =FUN_080f5b34
	ldr r6, [sp, #0xc8]
	str r1, [r6]
	ldr r1, _0812D830 @ =FUN_080f5fac
	ldr r2, [sp, #0xcc]
	str r1, [r2]
	ldr r3, [sp, #0xdc]
	str r4, [r3]
	movs r1, #0x28
	ldr r4, [sp, #0x60]
	strb r1, [r4]
	ldr r1, [sp, #0x144]
	bl FUN_082362fc
	adds r0, r7, #0
	bl FUN_080e6204
	movs r5, #0xc1
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, _0812D834 @ =FUN_08128844
	str r0, [r1]
	movs r6, #0xbf
	lsls r6, r6, #3
	adds r1, r7, r6
	ldr r0, _0812D838 @ =FUN_0812a504
	str r0, [r1]
	ldr r0, _0812D83C @ =0x000005FC
	adds r1, r7, r0
	ldr r0, _0812D840 @ =FUN_0812a63c
	str r0, [r1]
	ldr r2, _0812D844 @ =0x000005AC
	adds r1, r7, r2
	ldr r0, _0812D848 @ =FUN_0812871c
	str r0, [r1]
	movs r3, #0xb6
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _0812D84C @ =FUN_08128824
	str r0, [r1]
	movs r4, #0xb5
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _0812D850 @ =FUN_08122bc8
	str r0, [r1]
	subs r5, #0x7c
	adds r1, r7, r5
	ldr r0, _0812D854 @ =FUN_0812a7e8
	str r0, [r1]
	adds r6, #0x30
	adds r1, r7, r6
	ldr r0, _0812D858 @ =FUN_081259a8
	str r0, [r1]
	movs r0, #0xde
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #1
	strh r0, [r1]
	movs r1, #0xe0
	lsls r1, r1, #0xf
	ldr r2, [sp, #0x180]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0x14
	ldr r3, [sp, #0x188]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r0, #2
	rsbs r0, r0, #0
	ldr r4, [sp, #0x154]
	ldrh r1, [r4, #6]
	ands r0, r1
	strh r0, [r4, #6]
	adds r0, r7, #0
	bl Enemy_Init_080e5dd4
	movs r0, #0x49
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r5, [sp, #0x1a0]
	strh r0, [r5]
	movs r0, #0x47
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0812D866
	movs r6, #0xce
	lsls r6, r6, #1
	adds r5, r7, r6
	movs r4, #4
_0812D7A0:
	bl VM_GetPC
	cmp r0, #0
	beq _0812D85C
	bl Script_GetValue
	b _0812D85E
	.align 2, 0
_0812D7B0: .4byte 0x0000047A
_0812D7B4: .4byte 0x0000047E
_0812D7B8: .4byte 0x00000744
_0812D7BC: .4byte FUN_0812c9c8
_0812D7C0: .4byte FUN_0812990c
_0812D7C4: .4byte FUN_081224b8
_0812D7C8: .4byte FUN_08123a88
_0812D7CC: .4byte FUN_080f62b0
_0812D7D0: .4byte FUN_080f62ac
_0812D7D4: .4byte FUN_08122458
_0812D7D8: .4byte FUN_08122494
_0812D7DC: .4byte FUN_0812359c
_0812D7E0: .4byte FUN_08124cf8
_0812D7E4: .4byte FUN_080f44f4
_0812D7E8: .4byte FUN_080f410c
_0812D7EC: .4byte FUN_08123034
_0812D7F0: .4byte FUN_081231d4
_0812D7F4: .4byte FUN_080f0430
_0812D7F8: .4byte 0x085AD470
_0812D7FC: .4byte FUN_080e73c8
_0812D800: .4byte FUN_080f0320
_0812D804: .4byte FUN_080eff14
_0812D808: .4byte FUN_080e72b0
_0812D80C: .4byte FUN_08122388
_0812D810: .4byte FUN_080f47c8
_0812D814: .4byte FUN_080f54e4
_0812D818: .4byte FUN_080f6e64
_0812D81C: .4byte FUN_080f64f0
_0812D820: .4byte FUN_080f84d4
_0812D824: .4byte FUN_080f624c
_0812D828: .4byte FUN_080f56ec
_0812D82C: .4byte FUN_080f5b34
_0812D830: .4byte FUN_080f5fac
_0812D834: .4byte FUN_08128844
_0812D838: .4byte FUN_0812a504
_0812D83C: .4byte 0x000005FC
_0812D840: .4byte FUN_0812a63c
_0812D844: .4byte 0x000005AC
_0812D848: .4byte FUN_0812871c
_0812D84C: .4byte FUN_08128824
_0812D850: .4byte FUN_08122bc8
_0812D854: .4byte FUN_0812a7e8
_0812D858: .4byte FUN_081259a8
_0812D85C:
	movs r0, #0
_0812D85E:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _0812D7A0
_0812D866:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x1a4]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x18c]
	strh r0, [r3]
	cmp r2, #0
	beq _0812D89E
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x180]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _0812D89E
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_0812D89E:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x164]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0812D8B0
	movs r0, #1
	b _0812D8B2
_0812D8B0:
	movs r0, #0
_0812D8B2:
	cmp r0, #0
	beq _0812D8C4
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x188]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_0812D8C4:
	cmp r2, #1
	beq _0812D904
	movs r1, #0
	ldr r0, [sp, #0x158]
	strb r1, [r0]
	ldr r2, [sp, #0x15c]
	strb r1, [r2]
	ldr r3, [sp, #0x160]
	strb r1, [r3]
	ldr r4, _0812D914 @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _0812D918 @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0xd4]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0x64]
	strb r1, [r6]
	ldr r0, [sp, #0xac]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_0812D904:
	movs r1, #2
	ldr r3, [sp, #0x164]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0812D91C
	movs r0, #1
	b _0812D91E
	.align 2, 0
_0812D914: .4byte 0x00000484
_0812D918: .4byte 0x0000046C
_0812D91C:
	movs r0, #0
_0812D91E:
	cmp r0, #0
	beq _0812D938
	ldr r0, _0812D934 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x184]
	strh r0, [r5]
	b _0812D942
	.align 2, 0
_0812D934: .4byte 0x030046A0
_0812D938:
	ldr r0, [sp, #0x144]
	bl FUN_08241574
	ldr r6, [sp, #0x184]
	strh r0, [r6]
_0812D942:
	movs r1, #0x40
	ldr r2, [sp, #0x164]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0812D952
	movs r0, #1
	b _0812D954
_0812D952:
	movs r0, #0
_0812D954:
	cmp r0, #0
	beq _0812D962
	ldr r0, _0812D988 @ =0xFFFFFEFF
	ldr r3, [sp, #0x154]
	ldrh r1, [r3, #6]
	ands r0, r1
	strh r0, [r3, #6]
_0812D962:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	bne _0812D996
	ldr r0, _0812D98C @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x184]
	ldrh r5, [r5]
	cmp r0, r5
	bne _0812D990
	movs r0, #1
	b _0812D992
	.align 2, 0
_0812D988: .4byte 0xFFFFFEFF
_0812D98C: .4byte 0x030046A0
_0812D990:
	movs r0, #0
_0812D992:
	cmp r0, #0
	bne _0812D99E
_0812D996:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_0812D99E:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r6, [sp, #0xa8]
	ldrb r0, [r6]
	cmp r0, #0
	bne _0812DA86
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
	beq _0812D9E0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0812D9E8
_0812D9E0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0812D9E8:
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
	beq _0812DA0C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0812DA14
_0812DA0C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0812DA14:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0812DA4C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0812DA90
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0812DA50
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0812DA44
	ldrb r0, [r4, #5]
_0812DA44:
	subs r0, #1
	strh r0, [r4, #8]
	b _0812DA60
	.align 2, 0
_0812DA4C: .4byte 0x0000FFFF
_0812DA50:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r5, [r4, #5]
	cmp r0, r5
	blo _0812DA60
	strh r1, [r4, #8]
_0812DA60:
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
	bne _0812DA90
	movs r0, #1
	strb r0, [r4, #7]
	b _0812DA90
_0812DA86:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_0812DA90:
	movs r0, #0
	ldr r6, [sp, #0x38]
	str r0, [r6]
	ldr r0, _0812DAA8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0812DAAC
	movs r0, #1
	b _0812DAAE
	.align 2, 0
_0812DAA8: .4byte 0x030047A4
_0812DAAC:
	movs r0, #0
_0812DAAE:
	cmp r0, #0
	bne _0812DAEE
	ldr r0, [sp, #0x44]
	ldrb r1, [r0]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0812DAD6
	adds r0, r1, #0
	cmp r0, #7
	beq _0812DAD6
	cmp r0, #6
	beq _0812DAD6
	cmp r0, #0x15
	beq _0812DAD6
	cmp r0, #0x14
	beq _0812DAD6
	cmp r0, #0x17
	bne _0812DAEE
_0812DAD6:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r2, [sp, #0x164]
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0812DAEE:
	adds r0, r7, #0
	bl Enemy_Init_080f3680
	adds r0, r7, #0
	bl FUN_081275a4
	adds r0, r7, #0
	bl FUN_081266e4
	adds r0, r7, #0
	bl FUN_0812c9b4
	movs r3, #0xf0
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r4, [sp, #0x24]
	ldr r5, _0812DB34 @ =0x00000714
	adds r0, r4, r5
	strh r1, [r0]
	ldr r6, [sp, #0x34]
	ldr r4, [r6]
	movs r0, #0x42
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0812DB60
	bl VM_GetPC
	cmp r0, #0
	beq _0812DB38
	bl Script_GetValue
	adds r1, r0, #0
	b _0812DB3A
	.align 2, 0
_0812DB34: .4byte 0x00000714
_0812DB38:
	movs r1, #0x14
_0812DB3A:
	movs r2, #0xdf
	lsls r2, r2, #3
	adds r0, r4, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0812DB52
	bl Script_GetValue
	adds r1, r0, #0
	b _0812DB54
_0812DB52:
	movs r1, #0xb4
_0812DB54:
	ldr r3, _0812DB5C @ =0x000006FA
	adds r0, r4, r3
	strh r1, [r0]
	b _0812DB72
	.align 2, 0
_0812DB5C: .4byte 0x000006FA
_0812DB60:
	movs r5, #0xdf
	lsls r5, r5, #3
	adds r1, r4, r5
	movs r0, #0x14
	strh r0, [r1]
	ldr r6, _0812DC10 @ =0x000006FA
	adds r1, r4, r6
	movs r0, #0xb4
	strh r0, [r1]
_0812DB72:
	ldr r0, [sp, #0x34]
	ldr r4, [r0]
	ldr r2, [sp, #0x54]
	ldr r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, _0812DC14 @ =0x00000704
	adds r1, r4, r3
	str r0, [r1]
	movs r5, #0xe1
	lsls r5, r5, #3
	adds r4, r4, r5
	ldr r6, [sp, #0x54]
	ldr r0, [r6]
	str r0, [r4]
	ldr r1, [sp, #0x164]
	ldrh r0, [r1]
	ldr r2, [sp, #0xa4]
	strh r0, [r2]
	ldr r3, [sp, #0x30]
	ldrh r0, [r3]
	ldr r4, [sp, #0x9c]
	strh r0, [r4]
	ldr r5, [sp, #0x180]
	ldr r0, [r5]
	ldr r6, [sp, #0x68]
	str r0, [r6]
	ldr r1, [sp, #0x188]
	ldr r0, [r1]
	ldr r2, [sp, #0x6c]
	str r0, [r2]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0x74]
	strb r0, [r3]
	ldr r4, [sp, #0x158]
	ldrb r0, [r4]
	ldr r5, [sp, #0x78]
	strb r0, [r5]
	ldr r6, [sp, #0x15c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x7c]
	strb r0, [r1]
	ldr r2, [sp, #0x160]
	ldrb r0, [r2]
	ldr r3, [sp, #0x84]
	strb r0, [r3]
	ldr r4, [sp, #0xac]
	ldr r0, [r4]
	ldr r5, [sp, #0x8c]
	str r0, [r5]
	ldr r6, [sp, #0x64]
	ldrb r0, [r6]
	ldr r1, [sp, #0x98]
	strb r0, [r1]
	ldr r2, _0812DC18 @ =0x0000057C
	adds r1, r7, r2
	ldr r0, _0812DC1C @ =FUN_080f09e0
	str r0, [r1]
	ldr r3, _0812DC20 @ =0x0000061C
	adds r1, r7, r3
	ldr r0, _0812DC24 @ =FUN_0812ca24
	str r0, [r1]
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _0812DC28 @ =EnemyMummy_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812DC2C
	movs r0, #0
	b _0812DC30
	.align 2, 0
_0812DC10: .4byte 0x000006FA
_0812DC14: .4byte 0x00000704
_0812DC18: .4byte 0x0000057C
_0812DC1C: .4byte FUN_080f09e0
_0812DC20: .4byte 0x0000061C
_0812DC24: .4byte FUN_0812ca24
_0812DC28: .4byte EnemyMummy_Destroy
_0812DC2C:
	movs r0, #1
	rsbs r0, r0, #0
_0812DC30:
	add sp, #0x1b0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start EnemyMummy_Create
EnemyMummy_Create: @ 0x0812DC40
	push {r4, r5, lr}
	ldr r5, _0812DC74 @ =0x0000074C
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _0812DC6C
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemyMummy_Init
	cmp r0, #0
	bge _0812DC6C
	adds r0, r4, #0
	bl EnemyMummy_Destroy
	adds r0, r4, #0
	bl Free
_0812DC6C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0812DC74: .4byte 0x0000074C

	thumb_func_start FUN_0812dc78
FUN_0812dc78: @ 0x0812DC78
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	mov r4, sp
	adds r3, r5, #0
	adds r3, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r5, #8]
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
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0x1c
	bl Div
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x20
	strh r0, [r1]
	movs r1, #4
	ldrsh r0, [r4, r1]
	movs r1, #0x1c
	bl Div
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
