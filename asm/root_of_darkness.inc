	.include "asm/macros.inc"

	.syntax unified
	
	.text

@ EnemyXXX_Create でファイル分けしているだけなので他の敵のコードも混じっているかもしれない

	thumb_func_start FUN_081a2b84
FUN_081a2b84: @ 0x081A2B84
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
	cmp r0, #0
	beq _081A2BA4
	b _081A325C
_081A2BA4:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #1
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A2BC0
	movs r0, #1
	b _081A2BC2
_081A2BC0:
	movs r0, #0
_081A2BC2:
	cmp r0, #0
	beq _081A2BC8
	b _081A325C
_081A2BC8:
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _081A2BD8
	b _081A325C
_081A2BD8:
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _081A2C00
	ldr r4, _081A2BFC @ =0x0000048C
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A2BF0
	b _081A325C
_081A2BF0:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _081A325C
	.align 2, 0
_081A2BFC: .4byte 0x0000048C
_081A2C00:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _081A2C10
	b _081A325C
_081A2C10:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _081A2C20
	b _081A2F2C
_081A2C20:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _081A2C32
	b _081A325C
_081A2C32:
	ldr r2, _081A2CC4 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081A2C46
	b _081A325C
_081A2C46:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081A2C54
	b _081A325C
_081A2C54:
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
	bne _081A2C6C
	b _081A2DB4
_081A2C6C:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _081A2CD4
	ands r3, r1
	cmp r3, #0
	beq _081A2CD4
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081A2C92
	rsbs r1, r1, #0
_081A2C92:
	cmp r1, #0x20
	bgt _081A2CD4
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _081A2CC8 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _081A2CCC @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _081A2CD0 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _081A325C
	.align 2, 0
_081A2CC4: .4byte 0x0000A007
_081A2CC8: .4byte 0x000004BE
_081A2CCC: .4byte 0x0000048C
_081A2CD0: .4byte 0x0000044E
_081A2CD4:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _081A2CFC @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081A2D04
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081A2D00 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081A2D72
	.align 2, 0
_081A2CFC: .4byte 0x0000048A
_081A2D00: .4byte 0x03002BE0
_081A2D04:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081A2D20
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081A2D1C @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081A2D72
	.align 2, 0
_081A2D1C: .4byte 0x03002BE0
_081A2D20:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081A2D3C
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081A2D38 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081A2D72
	.align 2, 0
_081A2D38: .4byte 0x03002BE0
_081A2D3C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081A2D58
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081A2D54 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081A2D72
	.align 2, 0
_081A2D54: .4byte 0x03002BE0
_081A2D58:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081A2D6A
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081A2D72
_081A2D6A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081A2D74
_081A2D72:
	movs r3, #1
_081A2D74:
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
	ldr r5, _081A2DA8 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _081A2D96
	b _081A2EEC
_081A2D96:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A2DAC
	movs r0, #1
	b _081A2DAE
	.align 2, 0
_081A2DA8: .4byte 0x0000049C
_081A2DAC:
	movs r0, #0
_081A2DAE:
	cmp r0, #0
	bne _081A2E92
	b _081A2EA8
_081A2DB4:
	strh r2, [r7, #0x3e]
	ldr r1, _081A2DDC @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _081A2DE4
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081A2DE0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081A2E52
	.align 2, 0
_081A2DDC: .4byte 0x0000048A
_081A2DE0: .4byte 0x03002BE0
_081A2DE4:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081A2E00
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081A2DFC @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081A2E52
	.align 2, 0
_081A2DFC: .4byte 0x03002BE0
_081A2E00:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _081A2E1C
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081A2E18 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081A2E52
	.align 2, 0
_081A2E18: .4byte 0x03002BE0
_081A2E1C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081A2E38
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081A2E34 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081A2E52
	.align 2, 0
_081A2E34: .4byte 0x03002BE0
_081A2E38:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081A2E4A
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081A2E52
_081A2E4A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081A2E54
_081A2E52:
	movs r3, #1
_081A2E54:
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
	ldr r5, _081A2E88 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _081A2EEC
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A2E8C
	movs r0, #1
	b _081A2E8E
	.align 2, 0
_081A2E88: .4byte 0x0000049C
_081A2E8C:
	movs r0, #0
_081A2E8E:
	cmp r0, #0
	beq _081A2EA8
_081A2E92:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081A2EA4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _081A2EB4
	.align 2, 0
_081A2EA4: .4byte 0x03002BE0
_081A2EA8:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081A2EEC
_081A2EB4:
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
_081A2EEC:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081A2F18
	ldr r5, _081A2F24 @ =0x0000024E
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
	bls _081A2F18
	strh r1, [r2]
_081A2F18:
	ldr r5, _081A2F28 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _081A325C
	.align 2, 0
_081A2F24: .4byte 0x0000024E
_081A2F28: .4byte 0x0000048C
_081A2F2C:
	ldr r0, _081A2F40 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081A2F44
	movs r0, #1
	b _081A2F46
	.align 2, 0
_081A2F40: .4byte 0x030047A4
_081A2F44:
	movs r0, #0
_081A2F46:
	cmp r0, #0
	beq _081A2F54
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236640
	b _081A2F5C
_081A2F54:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236524
_081A2F5C:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _081A2F94 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _081A2F98 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _081A2F8A
	cmp r2, #0x17
	bne _081A2F9C
_081A2F8A:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _081A2FBE
	.align 2, 0
_081A2F94: .4byte 0x0000048C
_081A2F98: .4byte 0x000001DF
_081A2F9C:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _081A2F8A
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _081A2FEC @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081A2FBE
	movs r1, #0
_081A2FBE:
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
	beq _081A2FFA
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _081A2FF0
	asrs r0, r0, #1
	b _081A2FF6
	.align 2, 0
_081A2FEC: .4byte 0x00000187
_081A2FF0:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081A2FF6:
	mov r2, sb
	strh r0, [r2]
_081A2FFA:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081A3018
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _081A3014 @ =0x000001DD
	adds r1, r6, r4
	b _081A308C
	.align 2, 0
_081A3014: .4byte 0x000001DD
_081A3018:
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
	bne _081A3078
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _081A3078
	ldr r2, _081A3068 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081A306C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081A3070 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _081A3074 @ =0x000001DD
	adds r1, r6, r4
	b _081A308C
	.align 2, 0
_081A3068: .4byte 0x030046B8
_081A306C: .4byte 0x000003FF
_081A3070: .4byte 0x0203B400
_081A3074: .4byte 0x000001DD
_081A3078:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	ldr r3, _081A30AC @ =0x000001DD
	adds r1, r6, r3
_081A308C:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081A30B4
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081A30B0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081A3122
	.align 2, 0
_081A30AC: .4byte 0x000001DD
_081A30B0: .4byte 0x03002BE0
_081A30B4:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081A30D0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081A30CC @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081A3122
	.align 2, 0
_081A30CC: .4byte 0x03002BE0
_081A30D0:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081A30EC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081A30E8 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081A3122
	.align 2, 0
_081A30E8: .4byte 0x03002BE0
_081A30EC:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081A3108
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081A3104 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081A3122
	.align 2, 0
_081A3104: .4byte 0x03002BE0
_081A3108:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081A311A
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _081A3122
_081A311A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081A3124
_081A3122:
	movs r3, #1
_081A3124:
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
	ldr r5, _081A3158 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _081A31C0
	movs r1, #2
	ldr r2, _081A315C @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A3160
	movs r0, #1
	b _081A3162
	.align 2, 0
_081A3158: .4byte 0x0000049C
_081A315C: .4byte 0x00000474
_081A3160:
	movs r0, #0
_081A3162:
	cmp r0, #0
	beq _081A317C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081A3178 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _081A3188
	.align 2, 0
_081A3178: .4byte 0x03002BE0
_081A317C:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081A31C0
_081A3188:
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
_081A31C0:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _081A31F4
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081A31F4
	ldr r0, _081A320C @ =0x0000024E
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
	bls _081A31F4
	strh r1, [r2]
_081A31F4:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _081A3210 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _081A3214 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A3218
	movs r0, #1
	b _081A321A
	.align 2, 0
_081A320C: .4byte 0x0000024E
_081A3210: .4byte 0x030046A0
_081A3214: .4byte 0x00000934
_081A3218:
	movs r0, #0
_081A321A:
	ldr r1, _081A326C @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _081A3232
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_081A3232:
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
_081A325C:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A326C: .4byte 0x0000048A

	thumb_func_start FUN_081a3270
FUN_081a3270: @ 0x081A3270
	bx lr
	.align 2, 0

	thumb_func_start FUN_081a3274
FUN_081a3274: @ 0x081A3274
	push {lr}
	adds r3, r0, #0
	ldr r0, _081A328C @ =0x0000046D
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A3290
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A3292
	.align 2, 0
_081A328C: .4byte 0x0000046D
_081A3290:
	movs r0, #0
_081A3292:
	cmp r0, #0
	beq _081A32B8
	ldr r1, [r3, #0x44]
	movs r0, #2
	strb r0, [r1, #7]
	adds r2, r3, #0
	adds r2, #0xde
	ldrh r1, [r2]
	ldr r0, _081A32C4 @ =0x0000FFFB
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _081A32C8 @ =0x00000474
	adds r2, r3, r0
	ldr r0, _081A32CC @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081A32B8:
	adds r0, r3, #0
	movs r1, #0xe
	bl FUN_080efd44
	pop {r0}
	bx r0
	.align 2, 0
_081A32C4: .4byte 0x0000FFFB
_081A32C8: .4byte 0x00000474
_081A32CC: .4byte 0xFFFFF7FF

	thumb_func_start FUN_081a32d0
FUN_081a32d0: @ 0x081A32D0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081A32E8 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A32EC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A32EE
	.align 2, 0
_081A32E8: .4byte 0x0000046D
_081A32EC:
	movs r0, #0
_081A32EE:
	cmp r0, #0
	beq _081A333C
	ldr r1, [r4, #0x44]
	movs r2, #0
	movs r0, #2
	strb r0, [r1, #7]
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r2, [r0]
	ldr r1, _081A331C @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A3320
	ldr r2, [r4, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _081A332E
	.align 2, 0
_081A331C: .4byte 0x0000025D
_081A3320:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_081A332E:
	adds r0, r4, #0
	movs r1, #0xf
	bl FUN_080efd44
	ldr r0, _081A3354 @ =0x000001DB
	bl PlaySound_082406e0
_081A333C:
	ldr r1, _081A3358 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A334E
	ldr r0, _081A335C @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_081A334E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081A3354: .4byte 0x000001DB
_081A3358: .4byte 0x0000046E
_081A335C: .4byte 0x0000046B

	thumb_func_start FUN_081a3360
FUN_081a3360: @ 0x081A3360
	bx lr
	.align 2, 0

	thumb_func_start FUN_081a3364
FUN_081a3364: @ 0x081A3364
	push {lr}
	adds r3, r0, #0
	ldr r0, _081A337C @ =0x0000046D
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A3380
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A3382
	.align 2, 0
_081A337C: .4byte 0x0000046D
_081A3380:
	movs r0, #0
_081A3382:
	cmp r0, #0
	beq _081A33B2
	ldr r1, [r3, #0x44]
	movs r0, #3
	strb r0, [r1, #7]
	adds r2, r3, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	ldr r1, _081A33B8 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _081A33BC @ =0x00000474
	adds r2, r3, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r0, r3, #0
	movs r1, #0x14
	bl FUN_080efd44
_081A33B2:
	pop {r0}
	bx r0
	.align 2, 0
_081A33B8: .4byte 0x0000FFF7
_081A33BC: .4byte 0x00000474

	thumb_func_start FUN_081a33c0
FUN_081a33c0: @ 0x081A33C0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	ldr r0, [r6, #0x44]
	adds r7, r0, #0
	adds r7, #0x48
	ldr r0, _081A33E4 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A33E8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A33EA
	.align 2, 0
_081A33E4: .4byte 0x0000046D
_081A33E8:
	movs r0, #0
_081A33EA:
	cmp r0, #0
	beq _081A33F6
	adds r0, r6, #0
	movs r1, #5
	bl FUN_080ef86c
_081A33F6:
	ldrh r0, [r7, #8]
	cmp r0, #3
	bne _081A3408
	ldrh r0, [r7, #0xe]
	cmp r0, #0
	bne _081A3408
	ldr r0, _081A3550 @ =0x000001DD
	bl PlaySound_082406e0
_081A3408:
	ldrh r0, [r7, #8]
	adds r1, r0, #0
	cmp r1, #3
	beq _081A3412
	b _081A35D8
_081A3412:
	ldrh r0, [r7, #0xe]
	cmp r0, #6
	bgt _081A341A
	b _081A35D8
_081A341A:
	adds r5, r6, #0
	adds r5, #0xde
	ldrh r1, [r5]
	movs r0, #4
	movs r2, #0
	mov r8, r2
	movs r3, #0
	mov sb, r3
	orrs r0, r1
	ldr r1, _081A3554 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r5]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _081A3558 @ =0x00000474
	adds r4, r6, r1
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r6, #0
	movs r1, #0
	bl FUN_081a5224
	adds r3, r5, #0
	adds r2, r4, #0
	cmp r0, #0
	bne _081A3452
	b _081A3626
_081A3452:
	ldr r3, _081A355C @ =FUN_081a378c
	movs r1, #0x24
	ldr r2, _081A3560 @ =0x0000046D
	adds r0, r6, r2
	movs r2, #1
	strb r2, [r0]
	ldr r4, _081A3564 @ =0x0000046B
	adds r0, r6, r4
	mov r4, r8
	strb r4, [r0]
	ldr r4, _081A3568 @ =0x00000553
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	mov r4, sb
	strh r4, [r0]
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r6, r3
	mov r4, r8
	strb r4, [r0]
	adds r3, #1
	adds r0, r6, r3
	strb r1, [r0]
	ldr r4, _081A356C @ =0x0000046A
	adds r0, r6, r4
	strb r2, [r0]
	ldr r1, _081A3570 @ =0x00000484
	adds r0, r6, r1
	mov r3, sb
	str r3, [r0]
	adds r4, #2
	adds r0, r6, r4
	strb r2, [r0]
	movs r0, #0x15
	add r0, sp
	mov r8, r0
	adds r0, r6, #0
	add r1, sp, #0x14
	mov r2, r8
	bl FUN_080e5d44
	ldr r3, _081A3574 @ =0x085ADE10
	mov r2, r8
	ldrb r1, [r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	ldrh r4, [r7, #8]
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r3
	ldrh r0, [r0]
	ldrh r1, [r6, #8]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _081A3578 @ =0xFFFF0000
	ldr r2, [sp, #0x18]
	ands r2, r4
	orrs r2, r0
	str r2, [sp, #0x18]
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	ldrh r1, [r7, #8]
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r3
	ldrh r1, [r0, #2]
	ldrh r0, [r6, #0xa]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _081A357C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	mov r2, r8
	ldrb r1, [r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	ldrh r7, [r7, #8]
	adds r0, r0, r7
	lsls r0, r0, #3
	adds r0, r0, r3
	ldrh r1, [r0, #4]
	ldrh r3, [r6, #0xc]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r5, sp, #0x18
	ldr r0, [r5, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r5, #4]
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r0, [r0]
	ldrb r1, [r0, #4]
	cmp r1, #3
	bhi _081A3584
	ldr r1, _081A3580 @ =0x03002BE0
	ldrb r0, [r0, #4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrb r1, [r2]
	str r1, [sp]
	mov r7, sb
	str r7, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	str r7, [sp, #0x10]
	adds r1, r5, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0807ab64
	b _081A35C0
	.align 2, 0
_081A3550: .4byte 0x000001DD
_081A3554: .4byte 0x0000FFF7
_081A3558: .4byte 0x00000474
_081A355C: .4byte FUN_081a378c
_081A3560: .4byte 0x0000046D
_081A3564: .4byte 0x0000046B
_081A3568: .4byte 0x00000553
_081A356C: .4byte 0x0000046A
_081A3570: .4byte 0x00000484
_081A3574: .4byte 0x085ADE10
_081A3578: .4byte 0xFFFF0000
_081A357C: .4byte 0x0000FFFF
_081A3580: .4byte 0x03002BE0
_081A3584:
	cmp r1, #4
	bne _081A35C0
	ldr r4, [r0, #0x38]
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r4, r1
	mov r2, sb
	strh r2, [r0]
	adds r0, r4, #0
	bl FUN_080e499c
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r4, r3
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	mov r7, r8
	ldrb r0, [r7]
	str r0, [sp]
	mov r0, sb
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r1, #0
	adds r2, r5, #0
	movs r3, #0
	bl FUN_080e6978
_081A35C0:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #2
	movs r3, #0xcc
	lsls r3, r3, #3
	adds r1, r1, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081A3692
_081A35D8:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _081A3608
	adds r3, r6, #0
	adds r3, #0xde
	ldrh r1, [r3]
	ldr r0, _081A35FC @ =0x0000FFFB
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strh r0, [r3]
	ldr r4, _081A3600 @ =0x00000474
	adds r2, r6, r4
	ldr r0, _081A3604 @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	b _081A3624
	.align 2, 0
_081A35FC: .4byte 0x0000FFFB
_081A3600: .4byte 0x00000474
_081A3604: .4byte 0xFFFFF7FF
_081A3608:
	adds r3, r6, #0
	adds r3, #0xde
	ldrh r1, [r3]
	movs r0, #4
	orrs r0, r1
	ldr r1, _081A36A0 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r3]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r7, _081A36A4 @ =0x00000474
	adds r2, r6, r7
	ldrh r1, [r2]
	orrs r0, r1
_081A3624:
	strh r0, [r2]
_081A3626:
	ldr r1, _081A36A8 @ =0x0000046E
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A3692
	ldrh r1, [r3]
	ldr r0, _081A36AC @ =0x0000FFFB
	ands r0, r1
	movs r4, #0
	movs r5, #0
	movs r1, #8
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _081A36B0 @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r2, _081A36B4 @ =FUN_081a36cc
	movs r1, #0x26
	ldr r3, _081A36B8 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #1
	strb r3, [r0]
	ldr r7, _081A36BC @ =0x0000046B
	adds r0, r6, r7
	strb r4, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
	movs r1, #2
	movs r2, #3
	subs r7, #0xeb
	adds r0, r6, r7
	strb r4, [r0]
	ldr r4, _081A36C0 @ =0x00000469
	adds r0, r6, r4
	strb r1, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _081A36C4 @ =0x00000484
	adds r0, r6, r1
	str r5, [r0]
	ldr r2, _081A36C8 @ =0x0000046C
	adds r0, r6, r2
	strb r3, [r0]
_081A3692:
	add sp, #0x20
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A36A0: .4byte 0x0000FFF7
_081A36A4: .4byte 0x00000474
_081A36A8: .4byte 0x0000046E
_081A36AC: .4byte 0x0000FFFB
_081A36B0: .4byte 0xFFFFF7FF
_081A36B4: .4byte FUN_081a36cc
_081A36B8: .4byte 0x0000046D
_081A36BC: .4byte 0x0000046B
_081A36C0: .4byte 0x00000469
_081A36C4: .4byte 0x00000484
_081A36C8: .4byte 0x0000046C

	thumb_func_start FUN_081a36cc
FUN_081a36cc: @ 0x081A36CC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081A36E4 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A36E8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A36EA
	.align 2, 0
_081A36E4: .4byte 0x0000046D
_081A36E8:
	movs r0, #0
_081A36EA:
	cmp r0, #0
	beq _081A3712
	adds r2, r5, #0
	adds r2, #0xde
	ldrh r1, [r2]
	ldr r0, _081A3770 @ =0x0000FFFB
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _081A3774 @ =0x00000474
	adds r2, r5, r1
	ldr r0, _081A3778 @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r5, #0
	movs r1, #0x11
	bl FUN_080ef86c
_081A3712:
	ldr r2, _081A377C @ =0x0000046E
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A376A
	ldr r3, _081A3780 @ =FUN_081a3274
	movs r1, #0x21
	ldr r6, _081A3784 @ =0x0000046D
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
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r2, [r0]
	movs r3, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081A3788 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r4, [r0]
_081A376A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081A3770: .4byte 0x0000FFFB
_081A3774: .4byte 0x00000474
_081A3778: .4byte 0xFFFFF7FF
_081A377C: .4byte 0x0000046E
_081A3780: .4byte FUN_081a3274
_081A3784: .4byte 0x0000046D
_081A3788: .4byte 0x0000046A

	thumb_func_start FUN_081a378c
FUN_081a378c: @ 0x081A378C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r6, r0, #0
	str r1, [sp, #0x2c]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x30]
	ldr r0, [r6, #0x44]
	adds r0, #0x48
	mov r8, r0
	ldr r2, _081A37C0 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A37C4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A37C6
	.align 2, 0
_081A37C0: .4byte 0x0000046D
_081A37C4:
	movs r0, #0
_081A37C6:
	cmp r0, #0
	beq _081A37FE
	ldr r0, _081A383C @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r1, [r0]
	ldr r4, [sp, #0x30]
	movs r7, #0xce
	lsls r7, r7, #3
	adds r0, r4, r7
	strb r1, [r0]
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	ldr r1, _081A3840 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _081A3844 @ =0x00000474
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081A37FE:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	mov sb, r0
	mov r4, sp
	adds r4, #0x15
	adds r0, r6, #0
	add r1, sp, #0x14
	adds r2, r4, #0
	bl FUN_080e5d44
	mov r3, sb
	ldrb r0, [r3, #4]
	mov sl, r4
	cmp r0, #3
	bhi _081A384E
	mov r4, r8
	ldrh r0, [r4, #0xe]
	adds r0, #1
	ldrb r7, [r4, #7]
	cmp r0, r7
	blt _081A3848
	ldrh r0, [r4, #8]
	adds r0, #1
	ldrb r1, [r4, #5]
	cmp r0, r1
	blt _081A3852
	movs r0, #0
	b _081A3852
	.align 2, 0
_081A383C: .4byte 0x03002BE0
_081A3840: .4byte 0x0000FFF7
_081A3844: .4byte 0x00000474
_081A3848:
	mov r2, r8
	ldrh r0, [r2, #8]
	b _081A3852
_081A384E:
	mov r3, r8
	ldrh r0, [r3, #8]
_081A3852:
	ldr r4, _081A3918 @ =0x085ADE10
	lsls r3, r0, #3
	mov r7, sl
	ldrb r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r3, r0
	adds r0, r0, r4
	ldrh r0, [r0]
	ldrh r1, [r6, #8]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _081A391C @ =0xFFFF0000
	ldr r2, [sp, #0x1c]
	ands r2, r5
	orrs r2, r0
	str r2, [sp, #0x1c]
	ldrb r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r3, r0
	adds r0, r0, r4
	ldrh r1, [r0, #2]
	ldrh r0, [r6, #0xa]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _081A3920 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	ldrb r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r3, r3, r0
	adds r3, r3, r4
	ldrh r1, [r3, #4]
	ldrh r2, [r6, #0xc]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r4, sp, #0x1c
	ldr r0, [r4, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [r4, #4]
	mov r3, sb
	ldrb r0, [r3, #4]
	cmp r0, #4
	beq _081A38BE
	b _081A3A94
_081A38BE:
	ldr r0, [r6, #0x44]
	movs r1, #0
	mov sl, r1
	movs r1, #2
	strb r1, [r0, #7]
	ldr r5, [r3, #0x38]
	ldrb r0, [r7]
	str r0, [sp]
	mov r2, sl
	str r2, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	adds r2, r4, #0
	movs r3, #0
	bl FUN_080e6978
	ldr r3, [sp, #0x2c]
	cmp r3, #0x8c
	bgt _081A38E6
	b _081A3C84
_081A38E6:
	movs r4, #0xc2
	lsls r4, r4, #1
	adds r2, r5, r4
	ldrh r1, [r2]
	movs r7, #0x8b
	lsls r7, r7, #1
	adds r0, r5, r7
	strh r1, [r0]
	ldr r3, _081A3924 @ =0x0000048A
	adds r0, r5, r3
	strh r1, [r0]
	mov r4, sl
	strh r4, [r2]
	add r7, sp, #0x18
	mov r8, r7
	ldr r0, _081A3928 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081A392C
	movs r0, #1
	b _081A392E
	.align 2, 0
_081A3918: .4byte 0x085ADE10
_081A391C: .4byte 0xFFFF0000
_081A3920: .4byte 0x0000FFFF
_081A3924: .4byte 0x0000048A
_081A3928: .4byte 0x030047A4
_081A392C:
	movs r0, #0
_081A392E:
	cmp r0, #0
	beq _081A399C
	movs r0, #0x94
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r2, [r1]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	bne _081A399C
	cmp r2, #0
	beq _081A399C
	ldr r0, _081A3954 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081A3958
	movs r0, #1
	rsbs r0, r0, #0
	b _081A395C
	.align 2, 0
_081A3954: .4byte 0x03002C68
_081A3958:
	movs r2, #0x18
	ldrsh r0, [r0, r2]
_081A395C:
	cmp r0, #1
	beq _081A397E
	cmp r0, #1
	bgt _081A396A
	cmp r0, #0
	beq _081A3974
	b _081A399C
_081A396A:
	cmp r0, #2
	beq _081A3988
	cmp r0, #3
	beq _081A3992
	b _081A399C
_081A3974:
	ldr r0, [r1]
	cmp r0, #1
	beq _081A399C
	movs r0, #0
	b _081A399E
_081A397E:
	ldr r0, [r1]
	cmp r0, #2
	beq _081A399C
	movs r0, #0
	b _081A399E
_081A3988:
	ldr r0, [r1]
	cmp r0, #4
	beq _081A399C
	movs r0, #0
	b _081A399E
_081A3992:
	ldr r0, [r1]
	cmp r0, #8
	beq _081A399C
	movs r0, #0
	b _081A399E
_081A399C:
	movs r0, #1
_081A399E:
	cmp r0, #0
	beq _081A3A06
	ldrh r0, [r5]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r4, #0
	ldrsh r1, [r1, r4]
	movs r7, #0x95
	lsls r7, r7, #2
	adds r2, r5, r7
	ldrh r2, [r2]
	ldr r4, _081A3A70 @ =0x0000025A
	adds r3, r5, r4
	ldrh r3, [r3]
	movs r4, #0
	str r4, [sp]
	bl FUN_0809c344
	add r7, sp, #0x24
	mov r0, r8
	str r4, [r0]
	add r0, sp, #0x18
	adds r1, r7, #0
	ldr r2, _081A3A74 @ =0x05000002
	bl CpuSet
	ldr r1, _081A3A78 @ =0x0000048A
	adds r2, r5, r1
	ldrh r0, [r2]
	cmp r0, #0
	bne _081A39F0
	movs r3, #0x93
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _081A3A06
_081A39F0:
	adds r0, r5, #0
	adds r0, #0xd8
	ldrh r1, [r2]
	adds r3, r5, #0
	adds r3, #8
	str r7, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0
	bl FUN_0805fe7c
_081A3A06:
	movs r1, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	movs r2, #0
	strb r1, [r0]
	ldr r7, _081A3A7C @ =0x00000469
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _081A3A80 @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r3, _081A3A84 @ =0x00000484
	adds r0, r5, r3
	str r2, [r0]
	adds r4, #4
	adds r0, r5, r4
	movs r3, #1
	strb r3, [r0]
	ldr r7, _081A3A88 @ =0x000005DC
	adds r0, r6, r7
	ldr r4, [r0]
	movs r1, #0x1e
	ldr r7, _081A3A8C @ =0x0000046D
	adds r0, r5, r7
	strb r3, [r0]
	subs r7, #2
	adds r0, r5, r7
	strb r2, [r0]
	adds r7, #0xe8
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
	ldr r7, [sp, #0x30]
	movs r0, #0xcc
	lsls r0, r0, #3
	adds r2, r7, r0
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _081A3A90 @ =0x0000046B
	adds r0, r6, r1
	strb r3, [r0]
	b _081A3CB0
	.align 2, 0
_081A3A70: .4byte 0x0000025A
_081A3A74: .4byte 0x05000002
_081A3A78: .4byte 0x0000048A
_081A3A7C: .4byte 0x00000469
_081A3A80: .4byte 0x0000046A
_081A3A84: .4byte 0x00000484
_081A3A88: .4byte 0x000005DC
_081A3A8C: .4byte 0x0000046D
_081A3A90: .4byte 0x0000046B
_081A3A94:
	cmp r0, #3
	bls _081A3A9A
	b _081A3C84
_081A3A9A:
	ldr r1, [r6, #0x44]
	movs r5, #0
	movs r0, #1
	strb r0, [r1, #7]
	mov r2, sb
	ldr r2, [r2, #0x38]
	mov sb, r2
	ldr r3, [sp, #0x30]
	ldr r7, _081A3ACC @ =0x00000672
	adds r0, r3, r7
	ldrb r1, [r0]
	ldr r0, [sp, #0x2c]
	bl Mod
	cmp r0, #0
	beq _081A3ABC
	b _081A3C64
_081A3ABC:
	movs r0, #0xd9
	lsls r0, r0, #2
	add r0, sb
	ldrh r0, [r0]
	cmp r0, #0
	bne _081A3AD0
	movs r0, #1
	b _081A3AD2
	.align 2, 0
_081A3ACC: .4byte 0x00000672
_081A3AD0:
	movs r0, #0
_081A3AD2:
	cmp r0, #0
	bne _081A3B10
	ldr r1, [sp, #0x30]
	movs r2, #0xce
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrb r2, [r0]
	ldr r0, _081A3AF8 @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r1, [r0]
	cmp r1, r2
	bge _081A3B00
	ldr r4, _081A3AFC @ =0xFFFFFF00
	adds r0, r2, r4
	subs r1, r1, r0
	b _081A3B02
	.align 2, 0
_081A3AF8: .4byte 0x03002BE0
_081A3AFC: .4byte 0xFFFFFF00
_081A3B00:
	subs r1, r1, r2
_081A3B02:
	ldr r7, [sp, #0x30]
	ldr r2, _081A3B24 @ =0x00000671
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r1, r0
	bgt _081A3B10
	b _081A3C2C
_081A3B10:
	add r2, sp, #0x14
	ldrb r0, [r6, #5]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _081A3B28
	asrs r0, r1, #6
	b _081A3B2E
	.align 2, 0
_081A3B24: .4byte 0x00000671
_081A3B28:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081A3B2E:
	lsls r0, r0, #6
	strb r0, [r2]
	ldr r3, _081A3B78 @ =0x00000256
	adds r0, r6, r3
	ldrh r5, [r0]
	add r4, sp, #0x1c
	mov sl, r4
	ldr r7, _081A3B7C @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #0x1c
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081A3B80
	adds r0, #4
	b _081A3B8A
	.align 2, 0
_081A3B78: .4byte 0x00000256
_081A3B7C: .4byte 0x030046A4
_081A3B80:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A3B8A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r5, #0
	movs r4, #0
	mov r7, sl
	strh r0, [r7, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r7, #4]
	add r0, sp, #0x14
	ldrb r3, [r0]
	movs r0, #0x3c
	str r0, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sb
	add r1, sp, #0x1c
	movs r2, #0x40
	bl FUN_0807ac74
	ldr r3, [sp, #0x30]
	movs r7, #0xcc
	lsls r7, r7, #3
	adds r2, r3, r7
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r5, [r0]
	ldr r3, _081A3C18 @ =0x00000469
	adds r0, r6, r3
	strb r5, [r0]
	ldr r7, _081A3C1C @ =0x0000046A
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081A3C20 @ =0x00000484
	adds r0, r6, r1
	str r4, [r0]
	adds r2, #4
	adds r0, r6, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _081A3C24 @ =FUN_081a3274
	movs r2, #0x21
	adds r7, #3
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081A3C28 @ =0x0000046B
	adds r0, r6, r1
	strb r5, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r4, [r0]
	b _081A3CB0
	.align 2, 0
_081A3C18: .4byte 0x00000469
_081A3C1C: .4byte 0x0000046A
_081A3C20: .4byte 0x00000484
_081A3C24: .4byte FUN_081a3274
_081A3C28: .4byte 0x0000046B
_081A3C2C:
	adds r0, r6, #0
	bl FUN_081a544c
	adds r3, r0, #0
	mov r4, sl
	ldrb r0, [r4]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r7, _081A3C60 @ =0x00000226
	adds r0, r6, r7
	ldrh r0, [r0]
	str r0, [sp, #0xc]
	movs r1, #0x90
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	mov r0, sb
	add r1, sp, #0x1c
	movs r2, #0
	bl FUN_0807ab64
	b _081A3C84
	.align 2, 0
_081A3C60: .4byte 0x00000226
_081A3C64:
	adds r0, r6, #0
	bl FUN_081a544c
	adds r3, r0, #0
	mov r2, sl
	ldrb r0, [r2]
	str r0, [sp]
	str r5, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	str r5, [sp, #0x10]
	mov r0, sb
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0807ab64
_081A3C84:
	adds r0, r6, #0
	movs r1, #0x12
	bl FUN_080efd44
	mov r3, r8
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _081A3CA2
	ldrh r0, [r3, #0xe]
	cmp r0, #0
	bne _081A3CA2
	movs r0, #0xef
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081A3CA2:
	ldr r4, [sp, #0x2c]
	cmp r4, #0xb4
	ble _081A3CB0
	ldr r7, _081A3CC0 @ =0x0000046B
	adds r1, r6, r7
	movs r0, #1
	strb r0, [r1]
_081A3CB0:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A3CC0: .4byte 0x0000046B

	thumb_func_start FUN_081a3cc4
FUN_081a3cc4: @ 0x081A3CC4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldr r2, _081A3CF0 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A3CF4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A3CF6
	.align 2, 0
_081A3CF0: .4byte 0x0000046D
_081A3CF4:
	movs r0, #0
_081A3CF6:
	cmp r0, #0
	beq _081A3DF0
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	ldr r1, _081A3D70 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _081A3D74 @ =0x00000474
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r0, r6, #0
	movs r1, #0x15
	bl FUN_080ef86c
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	mov sl, r0
	ldr r1, _081A3D78 @ =0x00000256
	adds r0, r6, r1
	ldrh r5, [r0]
	add r2, sp, #0x10
	mov sb, r2
	ldr r7, _081A3D7C @ =0x030046A4
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
	add r0, sp, #0x10
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081A3D80
	adds r0, #4
	b _081A3D8A
	.align 2, 0
_081A3D70: .4byte 0x0000FFF7
_081A3D74: .4byte 0x00000474
_081A3D78: .4byte 0x00000256
_081A3D7C: .4byte 0x030046A4
_081A3D80:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A3D8A:
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
	ldrb r0, [r6, #5]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _081A3DB0
	asrs r0, r1, #6
	b _081A3DB6
_081A3DB0:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081A3DB6:
	lsls r0, r0, #0x1e
	lsrs r3, r0, #0x18
	mov r1, sl
	ldrb r0, [r1, #4]
	cmp r0, #3
	bhi _081A3DD8
	ldr r0, [r1, #0x38]
	movs r1, #0x3c
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	add r1, sp, #0x10
	movs r2, #0x40
	bl FUN_0807ac74
_081A3DD8:
	ldr r1, [r6, #0x44]
	movs r0, #2
	strb r0, [r1, #7]
	ldr r0, [sp, #0x18]
	movs r1, #0xcc
	lsls r1, r1, #3
	adds r2, r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081A3DF0:
	ldr r2, _081A3E14 @ =0x0000046E
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A3E02
	ldr r0, _081A3E18 @ =0x0000046B
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
_081A3E02:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A3E14: .4byte 0x0000046E
_081A3E18: .4byte 0x0000046B

	thumb_func_start FUN_081a3e1c
FUN_081a3e1c: @ 0x081A3E1C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r0, [r6, #0x44]
	adds r4, r0, #0
	adds r4, #0x48
	ldr r0, _081A3E3C @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A3E40
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A3E42
	.align 2, 0
_081A3E3C: .4byte 0x0000046D
_081A3E40:
	movs r0, #0
_081A3E42:
	cmp r0, #0
	beq _081A3E82
	adds r0, r6, #0
	movs r1, #3
	bl FUN_080efd44
	ldr r7, _081A3F38 @ =0x0000046E
	adds r1, r6, r7
	movs r0, #0
	strb r0, [r1]
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	ldr r1, _081A3F3C @ =0x0000FFF7
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _081A3F40 @ =0x00000474
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x20
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r2, r6, r7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081A3E82:
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	cmp r5, #0x11
	bgt _081A3EAE
	ldrh r3, [r4, #8]
	cmp r3, #0
	bne _081A3EAE
	ldrh r1, [r4, #0xe]
	ldrb r2, [r4, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _081A3EAE
	cmp r2, #1
	beq _081A3EAE
	strh r3, [r4, #0xe]
_081A3EAE:
	ldr r5, _081A3F38 @ =0x0000046E
	adds r0, r6, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A3F32
	ldr r7, _081A3F44 @ =0x0000046B
	adds r0, r6, r7
	movs r4, #0
	strb r4, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r3, #0
	strh r0, [r2]
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r6, r1
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _081A3F48 @ =FUN_081a3274
	movs r1, #0x21
	subs r5, #1
	adds r0, r6, r5
	movs r5, #1
	strb r5, [r0]
	adds r0, r6, r7
	strb r3, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r6, r7
	strh r4, [r0]
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r3, [r0]
	ldr r7, _081A3F4C @ =0x00000469
	adds r0, r6, r7
	strb r3, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r3, [r0]
	adds r7, #0x1b
	adds r0, r6, r7
	str r4, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r5, [r0]
	movs r5, #0xfe
	lsls r5, r5, #1
	adds r0, r6, r5
	ldrb r0, [r0]
	strb r0, [r6, #5]
_081A3F32:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A3F38: .4byte 0x0000046E
_081A3F3C: .4byte 0x0000FFF7
_081A3F40: .4byte 0x00000474
_081A3F44: .4byte 0x0000046B
_081A3F48: .4byte FUN_081a3274
_081A3F4C: .4byte 0x00000469

	thumb_func_start FUN_081a3f50
FUN_081a3f50: @ 0x081A3F50
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081A3F68 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A3F6C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A3F6E
	.align 2, 0
_081A3F68: .4byte 0x0000046D
_081A3F6C:
	movs r0, #0
_081A3F6E:
	cmp r0, #0
	beq _081A3F7A
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_080efd44
_081A3F7A:
	ldr r1, _081A3FA4 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A3FBE
	adds r0, r4, #0
	adds r0, #8
	bl FUN_0803712c
	movs r2, #1
	ldr r1, _081A3FA8 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A3FAC
	ldr r1, [r4, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081A3FB6
	.align 2, 0
_081A3FA4: .4byte 0x0000046E
_081A3FA8: .4byte 0x0000025D
_081A3FAC:
	ldr r1, [r4, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_081A3FB6:
	ldr r0, _081A3FC4 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_081A3FBE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081A3FC4: .4byte 0x0000046B

	thumb_func_start FUN_081a3fc8
FUN_081a3fc8: @ 0x081A3FC8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x78
	adds r7, r0, #0
	mov sl, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, [r7, #0x44]
	str r2, [sp, #0x74]
	ldr r3, _081A3FF8 @ =0x0000046D
	adds r1, r7, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A3FFC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A3FFE
	.align 2, 0
_081A3FF8: .4byte 0x0000046D
_081A3FFC:
	movs r0, #0
_081A3FFE:
	cmp r0, #0
	bne _081A4004
	b _081A41A8
_081A4004:
	movs r0, #0x40
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r7, r6
	ldrh r1, [r2]
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	adds r0, r7, #0
	movs r1, #0xa
	movs r2, #1
	bl FUN_080efc44
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
	adds r2, r7, #0
	adds r2, #0xde
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	ldr r1, _081A40BC @ =0x0000FFF7
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _081A40C0 @ =0x00000474
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r0, r7, #0
	bl FUN_080e8360
	add r4, sp, #0x50
	str r5, [sp, #0x2c]
	add r0, sp, #0x2c
	adds r1, r4, #0
	ldr r2, _081A40C4 @ =0x05000002
	bl CpuSet
	ldr r2, _081A40C8 @ =0x000001DD
	adds r0, r7, r2
	ldrb r3, [r0]
	ldr r2, _081A40CC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081A40D0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r6, _081A40D4 @ =0x0203B400
	adds r0, r0, r6
	ldrh r5, [r0]
	movs r0, #0x1f
	adds r6, r4, #0
	ands r5, r0
	ldr r2, _081A40D8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	mov r8, r6
	cmp r0, #0
	blt _081A40DC
	asrs r1, r0, #0xc
	b _081A40E2
	.align 2, 0
_081A40BC: .4byte 0x0000FFF7
_081A40C0: .4byte 0x00000474
_081A40C4: .4byte 0x05000002
_081A40C8: .4byte 0x000001DD
_081A40CC: .4byte 0x030046B8
_081A40D0: .4byte 0x000003FF
_081A40D4: .4byte 0x0203B400
_081A40D8: .4byte 0x085B0A08
_081A40DC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A40E2:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	ldr r1, _081A40FC @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081A4100
	asrs r0, r0, #0xc
	b _081A4106
	.align 2, 0
_081A40FC: .4byte 0x085B0A08
_081A4100:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A4106:
	movs r4, #0
	strh r0, [r6, #4]
	ldr r2, _081A4168 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081A416C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081A4170 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x30
	mov r6, r8
	strh r0, [r6, #2]
	adds r0, r7, #0
	adds r0, #8
	ldr r2, _081A4174 @ =0x0000D638
	ldr r3, _081A4178 @ =0x000099DD
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0x1e
	str r1, [sp, #4]
	movs r5, #2
	str r5, [sp, #8]
	str r4, [sp, #0xc]
	movs r1, #0xdc
	str r1, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	mov r1, r8
	bl FUN_081ef708
	ldr r1, _081A417C @ =0x0000049C
	adds r0, r7, r1
	ldr r4, [r0]
	ands r4, r5
	cmp r4, #0
	beq _081A4180
	movs r0, #0xe5
	bl PlaySound_082406e0
	b _081A41A8
	.align 2, 0
_081A4168: .4byte 0x030046B8
_081A416C: .4byte 0x000003FF
_081A4170: .4byte 0x0203B400
_081A4174: .4byte 0x0000D638
_081A4178: .4byte 0x000099DD
_081A417C: .4byte 0x0000049C
_081A4180:
	ldr r5, _081A4248 @ =0x0000066C
	add r5, sb
	ldrh r0, [r5]
	cmp r0, #0
	beq _081A41A8
	ldrh r0, [r7]
	str r0, [sp, #0x58]
	ldr r1, _081A424C @ =0xFFFF0000
	ldr r0, [sp, #0x5c]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #0x5c]
	add r0, sp, #0x58
	add r1, sp, #0x5c
	str r0, [r1, #4]
	ldrh r0, [r5]
	bl Script_ExecById
	strh r4, [r5]
_081A41A8:
	mov r2, sl
	cmp r2, #0x14
	bgt _081A41B0
	b _081A460A
_081A41B0:
	ldr r3, _081A4250 @ =0x0000049C
	adds r0, r7, r3
	ldr r5, [r0]
	movs r0, #2
	ands r5, r0
	cmp r5, #0
	bne _081A4268
	movs r6, #0x95
	lsls r6, r6, #2
	adds r0, r7, r6
	ldrh r1, [r0]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r3, #0
	strh r1, [r0]
	subs r6, #0xd4
	adds r2, r7, r6
	movs r0, #0x41
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r3, [r0]
	ldr r6, _081A4254 @ =0x00000469
	adds r0, r7, r6
	strb r3, [r0]
	adds r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	adds r6, #0x1b
	adds r0, r7, r6
	str r5, [r0]
	adds r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	ldr r4, _081A4258 @ =FUN_081a32d0
	movs r2, #0x29
	subs r6, #0x17
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081A425C @ =0x0000046B
	adds r0, r7, r1
	strb r3, [r0]
	adds r6, #0xe6
	adds r0, r7, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	adds r2, r7, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	movs r1, #8
	orrs r0, r1
	orrs r0, r3
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	strh r0, [r2, #6]
	ldr r3, _081A4260 @ =0x00000474
	adds r2, r7, r3
	ldr r0, _081A4264 @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081A460A
	.align 2, 0
_081A4248: .4byte 0x0000066C
_081A424C: .4byte 0xFFFF0000
_081A4250: .4byte 0x0000049C
_081A4254: .4byte 0x00000469
_081A4258: .4byte FUN_081a32d0
_081A425C: .4byte 0x0000046B
_081A4260: .4byte 0x00000474
_081A4264: .4byte 0xFFFFF7FF
_081A4268:
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r0, _081A4280 @ =0x030046A0
	ldr r0, [r0]
	ldr r6, _081A4284 @ =0x00000934
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A4288
	movs r0, #1
	b _081A428A
	.align 2, 0
_081A4280: .4byte 0x030046A0
_081A4284: .4byte 0x00000934
_081A4288:
	movs r0, #0
_081A428A:
	cmp r0, #0
	beq _081A42B8
	movs r0, #0xe5
	bl PlaySound_082406e0
	adds r0, r7, #0
	adds r0, #8
	bl FUN_0803712c
	movs r0, #0x80
	lsls r0, r0, #5
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _081A42B4 @ =0x000001DF
	adds r5, r7, r2
	b _081A442E
	.align 2, 0
_081A42B4: .4byte 0x000001DF
_081A42B8:
	ldr r2, _081A44C0 @ =0xFFFF0000
	ldr r0, [sp, #0x64]
	ands r0, r2
	movs r1, #0x50
	orrs r0, r1
	ldr r1, _081A44C4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x64]
	add r5, sp, #0x64
	ldr r0, [r5, #4]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	str r0, [r5, #4]
	ldr r4, _081A44C8 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _081A44CC @ =0x000003FF
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	ldr r6, _081A44D0 @ =0x0203B400
	adds r0, r0, r6
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	movs r2, #8
	adds r2, r2, r7
	mov sl, r2
	movs r3, #4
	str r3, [sp]
	movs r6, #0x14
	mov sb, r6
	str r6, [sp, #4]
	movs r0, #2
	mov r8, r0
	str r0, [sp, #8]
	movs r6, #1
	str r6, [sp, #0xc]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0x20
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081A44CC @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081A44D0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	mov r2, sb
	str r2, [sp, #4]
	mov r3, r8
	str r3, [sp, #8]
	str r6, [sp, #0xc]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0x40
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081A44CC @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081A44D0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	mov r2, sb
	str r2, [sp, #4]
	mov r3, r8
	str r3, [sp, #8]
	str r6, [sp, #0xc]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0x5e
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081A44CC @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081A44D0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	mov r2, sb
	str r2, [sp, #4]
	mov r3, r8
	str r3, [sp, #8]
	str r6, [sp, #0xc]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0x80
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081A44CC @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081A44D0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	mov r2, sb
	str r2, [sp, #4]
	mov r3, r8
	str r3, [sp, #8]
	str r6, [sp, #0xc]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0xc4
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081A44CC @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _081A44D0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	mov r2, sb
	str r2, [sp, #4]
	mov r3, r8
	str r3, [sp, #8]
	str r6, [sp, #0xc]
	mov r0, sl
	adds r2, r5, #0
	movs r3, #0xf0
	bl FUN_080ddcc8
	ldr r6, _081A44D4 @ =0x000001DF
	adds r0, r7, r6
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #4
	beq _081A4428
	cmp r1, #1
	beq _081A4428
	cmp r1, #5
	beq _081A4428
	cmp r1, #7
	beq _081A4428
	cmp r1, #6
	beq _081A4428
	cmp r1, #0x18
	bne _081A442E
_081A4428:
	movs r0, #0xe5
	bl PlaySound_082406e0
_081A442E:
	ldr r1, [sp, #0x74]
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_080e6658
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _081A44A0
	movs r6, #8
	ldrsh r0, [r7, r6]
	str r0, [sp, #0x30]
	movs r1, #0xa
	ldrsh r0, [r7, r1]
	str r0, [sp, #0x34]
	movs r3, #0xc
	ldrsh r0, [r7, r3]
	str r0, [sp, #0x38]
	movs r6, #0xce
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r0, [r0]
	str r0, [sp, #0x3c]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x40]
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r0, [r0]
	str r0, [sp, #0x44]
	movs r6, #0x94
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r0, [r0]
	str r0, [sp, #0x48]
	ldrh r0, [r7]
	str r0, [sp, #0x4c]
	ldr r1, _081A44C0 @ =0xFFFF0000
	ldr r0, [sp, #0x6c]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x6c]
	add r0, sp, #0x30
	add r1, sp, #0x6c
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_081A44A0:
	ldrb r0, [r5]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r7, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	cmp r0, #0x1f
	bgt _081A44DC
	ldr r3, _081A44D8 @ =0x030046A0
	ldr r2, [r3]
	movs r6, #0xe2
	lsls r6, r6, #2
	adds r2, r2, r6
	b _081A44E8
	.align 2, 0
_081A44C0: .4byte 0xFFFF0000
_081A44C4: .4byte 0x0000FFFF
_081A44C8: .4byte 0x030046B8
_081A44CC: .4byte 0x000003FF
_081A44D0: .4byte 0x0203B400
_081A44D4: .4byte 0x000001DF
_081A44D8: .4byte 0x030046A0
_081A44DC:
	ldr r3, _081A4558 @ =0x030046A0
	ldr r2, [r3]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r2, r2, r1
	subs r0, #0x20
_081A44E8:
	adds r1, r4, #0
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r5, r3, #0
	ldr r4, _081A455C @ =FUN_080e48d0
	movs r3, #0x10
	ldr r2, _081A4560 @ =0x0000046D
	adds r0, r7, r2
	movs r1, #0
	movs r2, #1
	strb r2, [r0]
	ldr r6, _081A4564 @ =0x0000046B
	adds r0, r7, r6
	strb r1, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r7, r3
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r7, r6
	movs r3, #0
	strh r1, [r0]
	movs r4, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r7, r6
	strb r2, [r0]
	adds r6, #1
	adds r0, r7, r6
	strb r3, [r0]
	ldr r3, _081A4568 @ =0x0000046A
	adds r0, r7, r3
	strb r4, [r0]
	adds r6, #0x1b
	adds r0, r7, r6
	str r1, [r0]
	ldr r1, _081A456C @ =0x0000046C
	adds r0, r7, r1
	strb r2, [r0]
	ldr r0, [r5]
	ldr r3, _081A4570 @ =0x00000948
	adds r2, r0, r3
	ldrh r3, [r2]
	movs r6, #0
	ldrsh r1, [r2, r6]
	ldr r0, _081A4574 @ =0x0000270E
	cmp r1, r0
	bgt _081A4578
	adds r0, r3, #1
	b _081A457C
	.align 2, 0
_081A4558: .4byte 0x030046A0
_081A455C: .4byte FUN_080e48d0
_081A4560: .4byte 0x0000046D
_081A4564: .4byte 0x0000046B
_081A4568: .4byte 0x0000046A
_081A456C: .4byte 0x0000046C
_081A4570: .4byte 0x00000948
_081A4574: .4byte 0x0000270E
_081A4578:
	ldr r1, _081A4598 @ =0x0000270F
	adds r0, r1, #0
_081A457C:
	strh r0, [r2]
	ldr r0, [r5]
	movs r2, #0xf8
	lsls r2, r2, #1
	adds r3, r0, r2
	ldrh r2, [r3]
	movs r6, #0
	ldrsh r1, [r3, r6]
	ldr r0, _081A459C @ =0x0000270E
	cmp r1, r0
	bgt _081A45A0
	adds r0, r2, #1
	b _081A45A4
	.align 2, 0
_081A4598: .4byte 0x0000270F
_081A459C: .4byte 0x0000270E
_081A45A0:
	ldr r1, _081A45DC @ =0x0000270F
	adds r0, r1, #0
_081A45A4:
	strh r0, [r3]
	adds r0, r7, #0
	bl FUN_080e9178
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	bl FUN_0807a798
	movs r3, #0x93
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r0, [r0]
	ldr r6, _081A45E0 @ =0x00000189
	adds r1, r7, r6
	ldrb r1, [r1]
	bl FUN_0807a840
	ldr r0, _081A45E4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081A45E8
	movs r0, #1
	b _081A45EA
	.align 2, 0
_081A45DC: .4byte 0x0000270F
_081A45E0: .4byte 0x00000189
_081A45E4: .4byte 0x030047A4
_081A45E8:
	movs r0, #0
_081A45EA:
	cmp r0, #0
	bne _081A460A
	movs r1, #0x80
	lsls r1, r1, #4
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081A460A
	ldr r0, _081A461C @ =0x03002B28
	ldrh r0, [r0]
	ldrh r1, [r7]
	bl FUN_080ec5b4
_081A460A:
	add sp, #0x78
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A461C: .4byte 0x03002B28

	thumb_func_start FUN_081a4620
FUN_081a4620: @ 0x081A4620
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r2, [r0, #6]
	movs r1, #4
	orrs r1, r2
	strh r1, [r0, #6]
	movs r0, #1
	bx lr
	.align 2, 0

	thumb_func_start FUN_081a4634
FUN_081a4634: @ 0x081A4634
	push {lr}
	adds r1, r0, #0
	adds r0, #0xd8
	adds r1, #8
	movs r2, #0
	bl FUN_082364c4
	movs r0, #1
	pop {r1}
	bx r1

	thumb_func_start FUN_081a4648
FUN_081a4648: @ 0x081A4648
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r6, _081A4668 @ =0x0000046C
	adds r1, r4, r6
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A466C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A466E
	.align 2, 0
_081A4668: .4byte 0x0000046C
_081A466C:
	movs r0, #0
_081A466E:
	cmp r0, #0
	beq _081A4690
	adds r2, r4, #0
	adds r2, #0xd8
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r0, _081A46A8 @ =0x00000474
	adds r2, r4, r0
	ldr r0, _081A46AC @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081A4690:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081a5224
	cmp r0, #0
	bne _081A46B0
	movs r6, #0xcd
	lsls r6, r6, #3
	adds r1, r5, r6
	ldrh r0, [r1]
	adds r0, #1
	b _081A46B8
	.align 2, 0
_081A46A8: .4byte 0x00000474
_081A46AC: .4byte 0xFFFFF7FF
_081A46B0:
	movs r0, #0xcd
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r0, #0
_081A46B8:
	strh r0, [r1]
	ldr r1, _081A472C @ =0x00000484
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0x1e
	ble _081A471A
	movs r6, #0xcd
	lsls r6, r6, #3
	adds r0, r5, r6
	movs r1, #0
	ldrsh r5, [r0, r1]
	cmp r5, #0
	bne _081A471A
	movs r3, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r3, [r0]
	ldr r1, _081A4730 @ =0x00000469
	adds r0, r4, r1
	strb r5, [r0]
	adds r6, #2
	adds r0, r4, r6
	strb r5, [r0]
	adds r1, #0x1b
	adds r0, r4, r1
	str r5, [r0]
	adds r6, #2
	adds r0, r4, r6
	movs r1, #1
	strb r1, [r0]
	ldr r2, _081A4734 @ =FUN_081a33c0
	adds r6, #1
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _081A4738 @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r6, #0xe6
	adds r0, r4, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r4, r6
	strh r5, [r0]
_081A471A:
	ldr r0, _081A472C @ =0x00000484
	adds r1, r4, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081A472C: .4byte 0x00000484
_081A4730: .4byte 0x00000469
_081A4734: .4byte FUN_081a33c0
_081A4738: .4byte 0x0000046B

	thumb_func_start FUN_081a473c
FUN_081a473c: @ 0x081A473C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r2, _081A475C @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A4760
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A4762
	.align 2, 0
_081A475C: .4byte 0x0000046C
_081A4760:
	movs r0, #0
_081A4762:
	cmp r0, #0
	beq _081A4798
	ldr r4, _081A481C @ =FUN_081a32d0
	movs r3, #0x29
	ldr r7, _081A4820 @ =0x0000046D
	adds r1, r6, r7
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081A4824 @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r2, [r0]
	movs r7, #0xcd
	lsls r7, r7, #3
	adds r0, r5, r7
	strh r2, [r0]
_081A4798:
	ldr r1, _081A4824 @ =0x0000046B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A480C
	adds r2, r6, #0
	adds r2, #0xd8
	movs r1, #5
	rsbs r1, r1, #0
	ldrh r0, [r2, #6]
	ands r1, r0
	movs r3, #0
	movs r5, #0
	movs r0, #8
	orrs r1, r0
	strh r1, [r2, #6]
	ldr r4, _081A4828 @ =0x00000474
	adds r2, r6, r4
	ldr r0, _081A482C @ =0xFFFFF7FF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r2, _081A4830 @ =FUN_081a3274
	movs r1, #0x21
	ldr r7, _081A4820 @ =0x0000046D
	adds r0, r6, r7
	movs r4, #1
	strb r4, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
	movs r1, #2
	subs r7, #0xeb
	adds r0, r6, r7
	strb r3, [r0]
	ldr r2, _081A4834 @ =0x00000469
	adds r0, r6, r2
	strb r3, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081A4838 @ =0x00000484
	adds r0, r6, r1
	str r5, [r0]
	adds r2, #3
	adds r0, r6, r2
	strb r4, [r0]
_081A480C:
	ldr r4, _081A4838 @ =0x00000484
	adds r1, r6, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A481C: .4byte FUN_081a32d0
_081A4820: .4byte 0x0000046D
_081A4824: .4byte 0x0000046B
_081A4828: .4byte 0x00000474
_081A482C: .4byte 0xFFFFF7FF
_081A4830: .4byte FUN_081a3274
_081A4834: .4byte 0x00000469
_081A4838: .4byte 0x00000484

	thumb_func_start FUN_081a483c
FUN_081a483c: @ 0x081A483C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081A48A8 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A484E
	movs r0, #0
	strb r0, [r1]
_081A484E:
	ldr r1, _081A48AC @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A48BC
	ldr r2, _081A48B0 @ =FUN_081a378c
	movs r1, #0x24
	ldr r3, _081A48B4 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081A48AC @ =0x0000046B
	adds r0, r5, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081A48B8 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r3, [r0]
	ldr r3, _081A48A8 @ =0x0000046C
	adds r0, r5, r3
	strb r4, [r0]
	b _081A48C6
	.align 2, 0
_081A48A8: .4byte 0x0000046C
_081A48AC: .4byte 0x0000046B
_081A48B0: .4byte FUN_081a378c
_081A48B4: .4byte 0x0000046D
_081A48B8: .4byte 0x00000469
_081A48BC:
	ldr r6, _081A48CC @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A48C6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081A48CC: .4byte 0x00000484

	thumb_func_start FUN_081a48d0
FUN_081a48d0: @ 0x081A48D0
	push {lr}
	ldr r2, _081A48E4 @ =0x0000046C
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A48E0
	movs r0, #0
	strb r0, [r1]
_081A48E0:
	pop {r0}
	bx r0
	.align 2, 0
_081A48E4: .4byte 0x0000046C

	thumb_func_start FUN_081a48e8
FUN_081a48e8: @ 0x081A48E8
	push {r4, lr}
	adds r2, r0, #0
	ldr r0, _081A4934 @ =0x0000046C
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A48FA
	movs r0, #0
	strb r0, [r1]
_081A48FA:
	ldr r1, _081A4938 @ =0x00000484
	adds r3, r2, r1
	ldr r0, [r3]
	cmp r0, #0x1e
	ble _081A4928
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r2, r4
	movs r1, #0
	strb r1, [r0]
	adds r4, #1
	adds r0, r2, r4
	strb r1, [r0]
	adds r4, #1
	adds r0, r2, r4
	strb r1, [r0]
	adds r4, #0x1a
	adds r0, r2, r4
	str r1, [r0]
	ldr r0, _081A4934 @ =0x0000046C
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
_081A4928:
	ldr r0, [r3]
	adds r0, #1
	str r0, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081A4934: .4byte 0x0000046C
_081A4938: .4byte 0x00000484

	thumb_func_start FUN_081a493c
FUN_081a493c: @ 0x081A493C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081A49AC @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A494E
	movs r0, #0
	strb r0, [r1]
_081A494E:
	ldr r1, _081A49B0 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A49A6
	ldr r2, _081A49B4 @ =FUN_081a3cc4
	movs r1, #0x28
	ldr r3, _081A49B8 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081A49B0 @ =0x0000046B
	adds r0, r5, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081A49BC @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r3, [r0]
	ldr r3, _081A49AC @ =0x0000046C
	adds r0, r5, r3
	strb r4, [r0]
_081A49A6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081A49AC: .4byte 0x0000046C
_081A49B0: .4byte 0x0000046B
_081A49B4: .4byte FUN_081a3cc4
_081A49B8: .4byte 0x0000046D
_081A49BC: .4byte 0x00000469

	thumb_func_start FUN_081a49c0
FUN_081a49c0: @ 0x081A49C0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081A4A30 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A49D2
	movs r0, #0
	strb r0, [r1]
_081A49D2:
	ldr r1, _081A4A34 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A4A2A
	ldr r3, _081A4A38 @ =FUN_081a3274
	movs r1, #0x21
	ldr r2, _081A4A3C @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081A4A34 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r2, [r0]
	movs r3, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081A4A40 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r4, [r0]
_081A4A2A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081A4A30: .4byte 0x0000046C
_081A4A34: .4byte 0x0000046B
_081A4A38: .4byte FUN_081a3274
_081A4A3C: .4byte 0x0000046D
_081A4A40: .4byte 0x0000046A

	thumb_func_start FUN_081a4a44
FUN_081a4a44: @ 0x081A4A44
	push {lr}
	adds r2, r0, #0
	ldr r0, _081A4A90 @ =0x0000046C
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A4A56
	movs r0, #0
	strb r0, [r1]
_081A4A56:
	movs r1, #0x93
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrh r0, [r0]
	ldr r1, _081A4A94 @ =0x00000484
	adds r3, r2, r1
	ldr r1, [r3]
	cmp r0, r1
	bgt _081A4A98
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r2, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r2, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r2, r3
	strb r1, [r0]
	adds r3, #0x1a
	adds r0, r2, r3
	str r1, [r0]
	ldr r0, _081A4A90 @ =0x0000046C
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
	b _081A4A9C
	.align 2, 0
_081A4A90: .4byte 0x0000046C
_081A4A94: .4byte 0x00000484
_081A4A98:
	adds r0, r1, #1
	str r0, [r3]
_081A4A9C:
	pop {r0}
	bx r0

	thumb_func_start FUN_081a4aa0
FUN_081a4aa0: @ 0x081A4AA0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081A4AB8 @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A4ABC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A4ABE
	.align 2, 0
_081A4AB8: .4byte 0x0000046C
_081A4ABC:
	movs r0, #0
_081A4ABE:
	cmp r0, #0
	beq _081A4B12
	movs r2, #1
	ldr r1, _081A4AD8 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A4ADC
	ldr r1, [r4, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081A4AE6
	.align 2, 0
_081A4AD8: .4byte 0x0000025D
_081A4ADC:
	ldr r1, [r4, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_081A4AE6:
	movs r2, #3
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _081A4B24 @ =0x00000469
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #0x1a
	adds r0, r4, r2
	str r1, [r0]
	ldr r0, _081A4B28 @ =0x0000046C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080e49c4
_081A4B12:
	ldr r2, _081A4B2C @ =0x00000484
	adds r1, r4, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081A4B24: .4byte 0x00000469
_081A4B28: .4byte 0x0000046C
_081A4B2C: .4byte 0x00000484

	thumb_func_start FUN_081a4b30
FUN_081a4b30: @ 0x081A4B30
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081A4B48 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A4B4C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A4B4E
	.align 2, 0
_081A4B48: .4byte 0x0000046C
_081A4B4C:
	movs r0, #0
_081A4B4E:
	cmp r0, #0
	beq _081A4B7C
	ldr r4, _081A4BEC @ =FUN_081a3f50
	movs r3, #0x2d
	ldr r2, _081A4BF0 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _081A4BF4 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _081A4BF8 @ =0x00000553
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
_081A4B7C:
	ldr r2, _081A4BF4 @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A4BE4
	ldr r3, _081A4BFC @ =FUN_080e48d0
	movs r1, #0x10
	ldr r6, _081A4BF0 @ =0x0000046D
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
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r3, #0
	strh r2, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081A4C00 @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _081A4C04 @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #5
	movs r6, #0xc1
	lsls r6, r6, #1
	adds r2, r5, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081A4BE4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081A4BEC: .4byte FUN_081a3f50
_081A4BF0: .4byte 0x0000046D
_081A4BF4: .4byte 0x0000046B
_081A4BF8: .4byte 0x00000553
_081A4BFC: .4byte FUN_080e48d0
_081A4C00: .4byte 0x00000469
_081A4C04: .4byte 0x0000046C

	thumb_func_start FUN_081a4c08
FUN_081a4c08: @ 0x081A4C08
	ldr r1, _081A4C24 @ =0x00000634
	adds r2, r0, r1
	ldr r1, _081A4C28 @ =0x085ADE70
	str r1, [r2]
	ldr r1, _081A4C2C @ =0x0000063C
	adds r2, r0, r1
	ldr r1, _081A4C30 @ =0x085ADE60
	str r1, [r2]
	ldr r1, _081A4C34 @ =0x00000644
	adds r0, r0, r1
	ldr r1, _081A4C38 @ =0x085ADE80
	str r1, [r0]
	bx lr
	.align 2, 0
_081A4C24: .4byte 0x00000634
_081A4C28: .4byte 0x085ADE70
_081A4C2C: .4byte 0x0000063C
_081A4C30: .4byte 0x085ADE60
_081A4C34: .4byte 0x00000644
_081A4C38: .4byte 0x085ADE80

	thumb_func_start FUN_081a4c3c
FUN_081a4c3c: @ 0x081A4C3C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _081A4CBC
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r1, [r0]
	ldr r6, _081A4CAC @ =0x00000469
	adds r0, r4, r6
	strb r5, [r0]
	ldr r1, _081A4CB0 @ =0x0000046A
	adds r0, r4, r1
	strb r5, [r0]
	adds r2, #0x1c
	adds r0, r4, r2
	str r5, [r0]
	adds r6, #3
	adds r0, r4, r6
	movs r1, #1
	strb r1, [r0]
	ldr r3, _081A4CB4 @ =FUN_081a3e1c
	movs r2, #0x2a
	adds r6, #1
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _081A4CB8 @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r6, #0xe6
	adds r0, r4, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r5, [r0]
	movs r0, #1
	b _081A4CC6
	.align 2, 0
_081A4CAC: .4byte 0x00000469
_081A4CB0: .4byte 0x0000046A
_081A4CB4: .4byte FUN_081a3e1c
_081A4CB8: .4byte 0x0000046B
_081A4CBC:
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strh r0, [r2]
	movs r0, #0
_081A4CC6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_081a4ccc
FUN_081a4ccc: @ 0x081A4CCC
  .include "asm/func/FUN_081a4ccc.inc"


	thumb_func_start FUN_081a4e88
FUN_081a4e88: @ 0x081A4E88
	push {lr}
	sub sp, #4
	movs r1, #6
	mov r0, sp
	strh r1, [r0]
	movs r0, #0x18
	mov r1, sp
	bl FUN_080ec79c
	add sp, #4
	pop {r0}
	bx r0

	thumb_func_start FUN_081a4ea0
FUN_081a4ea0: @ 0x081A4EA0
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xe
	movs r2, #0
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
	movs r1, #3
	movs r2, #7
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #5
	movs r2, #3
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #4
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #5
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x13
	movs r2, #6
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #8
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #8
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x15
	movs r2, #9
	movs r3, #0
	bl FUN_080ef84c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081a4f2c
FUN_081a4f2c: @ 0x081A4F2C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r1, r0, r2
	movs r2, #0
	str r2, [r1]
	movs r1, #0xcd
	lsls r1, r1, #3
	adds r0, r0, r1
	strh r2, [r0]
	ldrh r0, [r4, #8]
	adds r0, #0x20
	strh r0, [r4, #8]
	ldrh r0, [r4, #0xc]
	adds r0, #0x20
	strh r0, [r4, #0xc]
	ldr r2, _081A4F6C @ =0x0000025D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A4F70
	ldr r2, [r4, #0x44]
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _081A4F7A
	.align 2, 0
_081A4F6C: .4byte 0x0000025D
_081A4F70:
	ldr r2, [r4, #0x44]
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_081A4F7A:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
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
	beq _081A4FB6
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081A4FBE
_081A4FB6:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081A4FBE:
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
	beq _081A4FE2
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081A4FEA
_081A4FE2:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081A4FEA:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081A5020 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081A5058
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081A5024
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081A501A
	ldrb r0, [r4, #5]
_081A501A:
	subs r0, #1
	strh r0, [r4, #8]
	b _081A5034
	.align 2, 0
_081A5020: .4byte 0x0000FFFF
_081A5024:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081A5034
	strh r1, [r4, #8]
_081A5034:
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
	bne _081A5058
	movs r0, #1
	strb r0, [r4, #7]
_081A5058:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081a5060
FUN_081a5060: @ 0x081A5060
	push {r4, r5, lr}
	sub sp, #0x28
	adds r5, r0, #0
	ldr r4, _081A50D0 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	movs r2, #0x40
	orrs r0, r2
	ldr r1, _081A50D4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r4
	orrs r0, r2
	str r0, [sp, #0xc]
	movs r0, #0x80
	lsls r0, r0, #0x10
	str r0, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _081A50D8 @ =FUN_081a2b84
	str r5, [sp]
	ldr r0, _081A50DC @ =0x00005005
	str r0, [sp, #4]
	adds r0, r5, #0
	add r1, sp, #8
	bl FUN_080e38a8
	movs r2, #0
	str r2, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r4
	str r0, [r1, #4]
	str r2, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _081A50E0 @ =FUN_081a3270
	movs r0, #1
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r5, #0
	bl FUN_080e3984
	add sp, #0x28
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081A50D0: .4byte 0xFFFF0000
_081A50D4: .4byte 0x0000FFFF
_081A50D8: .4byte FUN_081a2b84
_081A50DC: .4byte 0x00005005
_081A50E0: .4byte FUN_081a3270

	thumb_func_start FUN_081a50e4
FUN_081a50e4: @ 0x081A50E4
	push {r4, r5, r6, lr}
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r1, r0, r2
	movs r2, #0
	strb r2, [r1]
	ldr r3, _081A5138 @ =0x00000469
	adds r1, r0, r3
	strb r2, [r1]
	ldr r6, _081A513C @ =0x0000046A
	adds r1, r0, r6
	strb r2, [r1]
	adds r3, #0x1b
	adds r1, r0, r3
	str r2, [r1]
	adds r6, #2
	adds r1, r0, r6
	movs r3, #1
	strb r3, [r1]
	ldr r5, _081A5140 @ =FUN_081a3274
	movs r4, #0x21
	adds r6, #1
	adds r1, r0, r6
	strb r3, [r1]
	ldr r3, _081A5144 @ =0x0000046B
	adds r1, r0, r3
	strb r2, [r1]
	adds r6, #0xe6
	adds r1, r0, r6
	strb r4, [r1]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r1, r0, r3
	str r5, [r1]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r0, r6
	strh r2, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081A5138: .4byte 0x00000469
_081A513C: .4byte 0x0000046A
_081A5140: .4byte FUN_081a3274
_081A5144: .4byte 0x0000046B

	thumb_func_start FUN_081a5148
FUN_081a5148: @ 0x081A5148
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	movs r0, #0
	mov r8, r0
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	lsls r6, r0, #1
	ldr r0, _081A5190 @ =0x03002BE0
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #9
	ldr r1, [r1, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _081A5176
	movs r6, #0x90
	lsls r6, r6, #0xa
_081A5176:
	ldr r2, _081A5194 @ =0x00000553
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #3
	bne _081A5198
	movs r0, #0x80
	lsls r0, r0, #0xb
	ands r1, r0
	cmp r1, #0
	beq _081A5198
	movs r0, #0
	b _081A5212
	.align 2, 0
_081A5190: .4byte 0x03002BE0
_081A5194: .4byte 0x00000553
_081A5198:
	movs r0, #0x80
	lsls r0, r0, #5
	mov sb, r0
	mov r3, sp
	adds r5, r7, #0
	adds r5, #8
	ldr r4, _081A5220 @ =0x03002BE0
	movs r1, #0
	mov ip, r1
_081A51AA:
	ldr r1, [r4]
	cmp r1, #0
	beq _081A5202
	ldr r0, [r1, #0x20]
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	bne _081A5202
	movs r2, #0xd8
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _081A5202
	adds r2, r1, #0
	adds r2, #0x2c
	ldrh r0, [r1, #0x2c]
	ldrh r1, [r7, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	cmp r6, r1
	ble _081A5202
	adds r6, r1, #0
	ldr r0, [r4]
	adds r0, #0x24
	mov r8, r0
_081A5202:
	adds r4, #4
	movs r0, #1
	rsbs r0, r0, #0
	add ip, r0
	mov r1, ip
	cmp r1, #0
	bge _081A51AA
	mov r0, r8
_081A5212:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081A5220: .4byte 0x03002BE0

	thumb_func_start FUN_081a5224
FUN_081a5224: @ 0x081A5224
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	mov sb, r1
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	adds r0, r5, #0
	bl FUN_081a5148
	adds r6, r0, #0
	cmp r6, #0
	beq _081A5298
	movs r2, #0xa
	ldrsh r1, [r5, r2]
	movs r3, #0xa
	ldrsh r0, [r6, r3]
	cmp r1, r0
	bne _081A5298
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	adds r3, r6, #0
	adds r3, #8
	ldrh r0, [r6, #8]
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
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #4
	ldrsh r0, [r2, r3]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	cmp r8, r1
	ble _081A5296
	mov r8, r1
	b _081A5298
_081A5296:
	movs r6, #0
_081A5298:
	adds r7, r5, #0
	adds r7, #8
	adds r0, r7, #0
	bl FUN_080edc40
	adds r4, r0, #0
	cmp r4, #0
	beq _081A52F0
	movs r0, #0xa
	ldrsh r1, [r5, r0]
	movs r2, #0xa
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _081A52F0
	mov r2, sp
	adds r3, r4, #0
	adds r3, #8
	ldrh r0, [r4, #8]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #4
	ldrsh r0, [r2, r3]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	cmp r8, r1
	ble _081A52F0
	adds r6, r4, #0
_081A52F0:
	cmp r6, #0
	bne _081A52F6
	b _081A543C
_081A52F6:
	ldrh r0, [r6, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081A531A
	cmp r1, #0
	blt _081A531A
	ldr r0, _081A5320 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081A531A
	ldr r0, _081A5324 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081A5328
_081A531A:
	movs r3, #0
	b _081A5336
	.align 2, 0
_081A5320: .4byte 0x030046A8
_081A5324: .4byte 0x030046AC
_081A5328:
	ldr r0, _081A5354 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r2
_081A5336:
	mov r4, sb
	cmp r4, #1
	bne _081A539A
	ldr r1, _081A5358 @ =0x00000256
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r0, r1, #1
	cmp r0, r3
	bne _081A535C
	movs r0, #0
	strb r0, [r5, #5]
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r5, r2
	b _081A542C
	.align 2, 0
_081A5354: .4byte 0x030046A4
_081A5358: .4byte 0x00000256
_081A535C:
	subs r0, r1, #1
	cmp r0, r3
	bne _081A5368
	movs r0, #0x80
	strb r0, [r5, #5]
	b _081A5426
_081A5368:
	ldr r0, _081A5384 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r2, [r0, r4]
	adds r0, r1, r2
	cmp r0, r3
	bne _081A5388
	movs r0, #0x40
	strb r0, [r5, #5]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	b _081A542C
	.align 2, 0
_081A5384: .4byte 0x030046A4
_081A5388:
	subs r0, r1, r2
	cmp r0, r3
	bne _081A543C
	movs r0, #0xc0
	strb r0, [r5, #5]
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r5, r2
	b _081A542C
_081A539A:
	ldrb r0, [r5, #5]
	adds r0, #0x20
	asrs r1, r0, #6
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	beq _081A53D4
	cmp r1, #1
	bgt _081A53B2
	cmp r1, #0
	beq _081A53BC
	b _081A543C
_081A53B2:
	cmp r1, #2
	beq _081A53FC
	cmp r1, #3
	beq _081A5410
	b _081A543C
_081A53BC:
	ldr r4, _081A53D0 @ =0x00000256
	adds r0, r5, r4
	ldrh r0, [r0]
	adds r0, #1
	cmp r0, r3
	bne _081A543C
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	b _081A542C
	.align 2, 0
_081A53D0: .4byte 0x00000256
_081A53D4:
	ldr r2, _081A53F4 @ =0x00000256
	adds r1, r5, r2
	ldr r0, _081A53F8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	ldrh r1, [r1]
	adds r0, r0, r1
	cmp r0, r3
	bne _081A543C
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	b _081A542C
	.align 2, 0
_081A53F4: .4byte 0x00000256
_081A53F8: .4byte 0x030046A4
_081A53FC:
	ldr r2, _081A540C @ =0x00000256
	adds r0, r5, r2
	ldrh r0, [r0]
	subs r0, #1
	cmp r0, r3
	bne _081A543C
	b _081A5426
	.align 2, 0
_081A540C: .4byte 0x00000256
_081A5410:
	ldr r4, _081A5434 @ =0x00000256
	adds r0, r5, r4
	ldrh r1, [r0]
	ldr r0, _081A5438 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	cmp r1, r3
	bne _081A543C
_081A5426:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r5, r3
_081A542C:
	str r6, [r0]
	adds r0, r6, #0
	b _081A543E
	.align 2, 0
_081A5434: .4byte 0x00000256
_081A5438: .4byte 0x030046A4
_081A543C:
	movs r0, #0
_081A543E:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081a544c
FUN_081a544c: @ 0x081A544C
	push {lr}
	ldr r0, [r0, #0x44]
	adds r0, #0x48
	ldrh r1, [r0, #8]
	cmp r1, #3
	bne _081A545C
	movs r0, #1
	b _081A5466
_081A545C:
	cmp r1, #4
	beq _081A5464
	ldrh r0, [r0, #8]
	b _081A5466
_081A5464:
	movs r0, #0
_081A5466:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081a546c
FUN_081a546c: @ 0x081A546C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081a4620
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _081A54A4 @ =0x0000062C
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
	bl FUN_081a4634
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081A54A4: .4byte 0x0000062C

	thumb_func_start FUN_081a54a8
FUN_081a54a8: @ 0x081A54A8
	push {lr}
	bl FUN_080f06b0
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_081a54b4
FUN_081a54b4: @ 0x081A54B4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _081A54CC @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A54D0
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _081A54D8
	.align 2, 0
_081A54CC: .4byte 0x0000025D
_081A54D0:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_081A54D8:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _081A54F4 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081A54F8
	movs r0, #1
	b _081A54FA
	.align 2, 0
_081A54F4: .4byte 0x00000474
_081A54F8:
	movs r0, #0
_081A54FA:
	cmp r0, #0
	beq _081A5506
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_081A5506:
	ldr r1, _081A5560 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _081A551E
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_081A551E:
	ldr r0, _081A5564 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _081A5536
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_081A5536:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081A554E
	adds r0, r4, #0
	bl FUN_08002a58
_081A554E:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081A5568
	movs r0, #1
	b _081A556A
	.align 2, 0
_081A5560: .4byte 0x0000044C
_081A5564: .4byte 0x0000044D
_081A5568:
	movs r0, #0
_081A556A:
	cmp r0, #0
	beq _081A5576
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_081A5576:
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
