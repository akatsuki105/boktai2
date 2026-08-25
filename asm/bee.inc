	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081668f0
FUN_081668f0: @ 0x081668F0
	bx lr
	.align 2, 0

	thumb_func_start FUN_081668f4
FUN_081668f4: @ 0x081668F4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov r8, r1
	adds r6, r2, #0
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08166914
	b _08166FFA
_08166914:
	movs r1, #0x80
	lsls r1, r1, #4
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _08166922
	b _08166FFA
_08166922:
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r0, #0x40
	add r0, r8
	mov sb, r0
	cmp r2, #0
	beq _08166938
	b _08166FBA
_08166938:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08166964
	ldr r3, _08166960 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08166950
	b _08166FBA
_08166950:
	movs r1, #0
	mov r4, r8
	strh r2, [r4, #0x3e]
	mov r0, r8
	adds r0, #0x43
	strb r1, [r0]
	b _08166FBA
	.align 2, 0
_08166960: .4byte 0x0000048C
_08166964:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _08166974
	b _08166FBA
_08166974:
	movs r4, #1
	ldrh r3, [r7, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _08166982
	b _08166C8C
_08166982:
	movs r0, #0x80
	lsls r0, r0, #7
	ldr r1, [r7, #0x34]
	ands r0, r1
	mov ip, r1
	cmp r0, #0
	bne _08166992
	b _08166FBA
_08166992:
	ldr r2, _08166A24 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081669A6
	b _08166FBA
_081669A6:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081669B4
	b _08166FBA
_081669B4:
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
	bne _081669CC
	b _08166B14
_081669CC:
	movs r1, #0x80
	lsls r1, r1, #1
	mov r2, r8
	ldrh r0, [r2, #6]
	ands r0, r1
	cmp r0, #0
	beq _08166A34
	ands r3, r1
	cmp r3, #0
	beq _08166A34
	mov r0, r8
	adds r0, #0x42
	ldrb r1, [r0]
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081669F4
	rsbs r1, r1, #0
_081669F4:
	cmp r1, #0x20
	bgt _08166A34
	ldrh r0, [r7, #0x3c]
	ldr r3, _08166A28 @ =0x000004BE
	adds r1, r6, r3
	strh r0, [r1]
	ldr r2, _08166A2C @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _08166A30 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _08166FBA
	.align 2, 0
_08166A24: .4byte 0x0000A007
_08166A28: .4byte 0x000004BE
_08166A2C: .4byte 0x0000048C
_08166A30: .4byte 0x0000044E
_08166A34:
	movs r1, #0
	mov r0, r8
	strh r1, [r0, #0x3e]
	ldr r2, _08166A5C @ =0x0000048A
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08166A64
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08166A60 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08166AD2
	.align 2, 0
_08166A5C: .4byte 0x0000048A
_08166A60: .4byte 0x03002BE0
_08166A64:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08166A80
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08166A7C @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08166AD2
	.align 2, 0
_08166A7C: .4byte 0x03002BE0
_08166A80:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08166A9C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08166A98 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08166AD2
	.align 2, 0
_08166A98: .4byte 0x03002BE0
_08166A9C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08166AB8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08166AB4 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08166AD2
	.align 2, 0
_08166AB4: .4byte 0x03002BE0
_08166AB8:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08166ACA
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _08166AD2
_08166ACA:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08166AD4
_08166AD2:
	movs r3, #1
_08166AD4:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	ldr r1, [r7, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, ip
	str r4, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r1, [r0]
	cmp r3, #0
	bne _08166AF4
	b _08166C48
_08166AF4:
	movs r1, #2
	ldr r3, _08166B08 @ =0x00000474
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08166B0C
	movs r0, #1
	b _08166B0E
	.align 2, 0
_08166B08: .4byte 0x00000474
_08166B0C:
	movs r0, #0
_08166B0E:
	cmp r0, #0
	bne _08166BEE
	b _08166C04
_08166B14:
	mov r3, r8
	strh r2, [r3, #0x3e]
	ldr r1, _08166B3C @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _08166B44
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08166B40 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08166BB2
	.align 2, 0
_08166B3C: .4byte 0x0000048A
_08166B40: .4byte 0x03002BE0
_08166B44:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08166B60
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08166B5C @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08166BB2
	.align 2, 0
_08166B5C: .4byte 0x03002BE0
_08166B60:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _08166B7C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08166B78 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08166BB2
	.align 2, 0
_08166B78: .4byte 0x03002BE0
_08166B7C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08166B98
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08166B94 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08166BB2
	.align 2, 0
_08166B94: .4byte 0x03002BE0
_08166B98:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08166BAA
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _08166BB2
_08166BAA:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08166BB4
_08166BB2:
	movs r3, #1
_08166BB4:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	ldr r1, [r7, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, ip
	str r4, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r1, [r0]
	cmp r3, #0
	beq _08166C48
	movs r1, #2
	ldr r3, _08166BE4 @ =0x00000474
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08166BE8
	movs r0, #1
	b _08166BEA
	.align 2, 0
_08166BE4: .4byte 0x00000474
_08166BE8:
	movs r0, #0
_08166BEA:
	cmp r0, #0
	beq _08166C04
_08166BEE:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08166C00 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08166C10
	.align 2, 0
_08166C00: .4byte 0x03002BE0
_08166C04:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08166C48
_08166C10:
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
_08166C48:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08166C74
	ldr r0, _08166C84 @ =0x0000024E
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
	bls _08166C74
	strh r1, [r2]
_08166C74:
	ldr r0, _08166C88 @ =0x0000048C
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x40
	add r1, r8
	mov sb, r1
	b _08166FBA
	.align 2, 0
_08166C84: .4byte 0x0000024E
_08166C88: .4byte 0x0000048C
_08166C8C:
	ldr r0, _08166CA0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08166CA4
	movs r0, #1
	b _08166CA6
	.align 2, 0
_08166CA0: .4byte 0x030047A4
_08166CA4:
	movs r0, #0
_08166CA6:
	cmp r0, #0
	beq _08166CB4
	adds r0, r7, #0
	mov r1, r8
	bl FUN_08236640
	b _08166CBC
_08166CB4:
	adds r0, r7, #0
	mov r1, r8
	bl FUN_08236524
_08166CBC:
	adds r0, r7, #0
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, r8
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _08166CF4 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08166CF8 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _08166CEA
	cmp r2, #0x17
	bne _08166CFC
_08166CEA:
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	b _08166D1C
	.align 2, 0
_08166CF4: .4byte 0x0000048C
_08166CF8: .4byte 0x000001DF
_08166CFC:
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r7, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _08166CEA
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r4, _08166D4C @ =0x00000187
	adds r0, r6, r4
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08166D1C
	movs r1, #0
_08166D1C:
	mov r0, r8
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
	beq _08166D5A
	mov r1, r8
	ldrh r0, [r1, #0x3e]
	lsls r0, r0, #1
	strh r0, [r1, #0x3e]
	mov r2, sb
	ldrh r0, [r2]
	cmp r0, #0
	blt _08166D50
	asrs r0, r0, #1
	b _08166D56
	.align 2, 0
_08166D4C: .4byte 0x00000187
_08166D50:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08166D56:
	mov r3, sb
	strh r0, [r3]
_08166D5A:
	ldrh r1, [r7, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08166D78
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _08166D74 @ =0x000001DD
	adds r1, r6, r4
	b _08166DEC
	.align 2, 0
_08166D74: .4byte 0x000001DD
_08166D78:
	mov r4, sp
	adds r3, r7, #0
	adds r3, #0xc
	mov r2, r8
	adds r2, #0xc
	mov r1, r8
	ldrh r0, [r1, #0xc]
	ldrh r1, [r7, #0xc]
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
	bne _08166DD8
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _08166DD8
	ldr r2, _08166DC8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08166DCC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08166DD0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _08166DD4 @ =0x000001DD
	adds r1, r6, r4
	b _08166DEC
	.align 2, 0
_08166DC8: .4byte 0x030046B8
_08166DCC: .4byte 0x000003FF
_08166DD0: .4byte 0x0203B400
_08166DD4: .4byte 0x000001DD
_08166DD8:
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	ldr r3, _08166E0C @ =0x000001DD
	adds r1, r6, r3
_08166DEC:
	strb r0, [r1]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08166E14
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08166E10 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08166E82
	.align 2, 0
_08166E0C: .4byte 0x000001DD
_08166E10: .4byte 0x03002BE0
_08166E14:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08166E30
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08166E2C @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08166E82
	.align 2, 0
_08166E2C: .4byte 0x03002BE0
_08166E30:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08166E4C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08166E48 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08166E82
	.align 2, 0
_08166E48: .4byte 0x03002BE0
_08166E4C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08166E68
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08166E64 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08166E82
	.align 2, 0
_08166E64: .4byte 0x03002BE0
_08166E68:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08166E7A
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08166E82
_08166E7A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08166E84
_08166E82:
	movs r3, #1
_08166E84:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	ldr r1, [r7, #0x34]
	ldr r2, [r7, #0x38]
	subs r4, #8
	adds r0, r6, r4
	str r1, [r0]
	ldr r1, _08166EB4 @ =0x0000049C
	adds r0, r6, r1
	str r2, [r0]
	cmp r3, #0
	beq _08166F1C
	movs r1, #2
	ldr r2, _08166EB8 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08166EBC
	movs r0, #1
	b _08166EBE
	.align 2, 0
_08166EB4: .4byte 0x0000049C
_08166EB8: .4byte 0x00000474
_08166EBC:
	movs r0, #0
_08166EBE:
	cmp r0, #0
	beq _08166ED8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08166ED4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08166EE4
	.align 2, 0
_08166ED4: .4byte 0x03002BE0
_08166ED8:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08166F1C
_08166EE4:
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
_08166F1C:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _08166F50
	movs r1, #0x80
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08166F50
	ldr r3, _08166F68 @ =0x0000024E
	adds r2, r6, r3
	movs r4, #0x96
	lsls r4, r4, #1
	adds r0, r4, #0
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	subs r3, #2
	adds r1, r6, r3
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _08166F50
	strh r1, [r2]
_08166F50:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _08166F6C @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _08166F70 @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08166F74
	movs r0, #1
	b _08166F76
	.align 2, 0
_08166F68: .4byte 0x0000024E
_08166F6C: .4byte 0x030046A0
_08166F70: .4byte 0x00000934
_08166F74:
	movs r0, #0
_08166F76:
	ldr r1, _0816700C @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _08166F90
	movs r0, #0
	mov r2, r8
	strh r0, [r2, #0x3e]
	mov r3, sb
	strh r0, [r3]
	strh r0, [r4]
	movs r0, #1
	ldr r1, [sp, #8]
	strb r0, [r1]
_08166F90:
	adds r0, r6, #0
	bl FUN_080e64e4
	mov r2, r8
	ldrh r0, [r2, #0x3e]
	strh r0, [r4]
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r0, [r7, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r7, #0x3e]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08166FBA:
	ldr r2, _08167010 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08167014 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08167018 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r3, sb
	ldrh r2, [r3]
	movs r1, #0xf
	ands r0, r1
	subs r2, r2, r0
	cmp r2, #0x14
	bge _08166FDE
	movs r2, #0x14
_08166FDE:
	mov r4, sb
	strh r2, [r4]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r2, #5
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
_08166FFA:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816700C: .4byte 0x0000048A
_08167010: .4byte 0x030046B8
_08167014: .4byte 0x000003FF
_08167018: .4byte 0x0203B400

	thumb_func_start FUN_0816701c
FUN_0816701c: @ 0x0816701C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _08167048 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816704C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816704E
	.align 2, 0
_08167048: .4byte 0x0000046D
_0816704C:
	movs r0, #0
_0816704E:
	adds r1, r0, #0
	cmp r1, #0
	beq _08167140
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_08168464
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	movs r1, #0
	strb r1, [r0, #5]
	ldr r1, _0816709C @ =0x000004C4
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _081670A0 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081670AC
	ldr r1, _081670A4 @ =0x000004B7
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
	ldr r2, _081670A8 @ =0x0000046E
	adds r7, r5, r2
	b _0816712E
	.align 2, 0
_0816709C: .4byte 0x000004C4
_081670A0: .4byte 0x0000025D
_081670A4: .4byte 0x000004B7
_081670A8: .4byte 0x0000046E
_081670AC:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _0816711C @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08167120 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _081670E6
	ldrb r0, [r7]
	cmp r0, #0
	bne _081670E6
	cmp r4, #1
	bne _081670D8
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08167132
_081670D8:
	cmp r4, #0
	bne _081670E6
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08167132
_081670E6:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081670F8
	movs r3, #6
_081670F8:
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
	beq _08167124
	ldr r0, [r6, #8]
	mov r2, r8
	orrs r0, r2
	b _0816712C
	.align 2, 0
_0816711C: .4byte 0x000004B7
_08167120: .4byte 0x0000046E
_08167124:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0816712C:
	str r0, [r6, #8]
_0816712E:
	movs r0, #0
	strb r0, [r7]
_08167132:
	ldrb r1, [r5, #5]
	ldr r0, _0816713C @ =0x00000663
	add r0, sl
	b _08167258
	.align 2, 0
_0816713C: .4byte 0x00000663
_08167140:
	ldr r0, _081671A0 @ =0x00000663
	add r0, sl
	ldrb r0, [r0]
	ldrb r2, [r5, #5]
	cmp r0, r2
	bne _0816714E
	b _08167254
_0816714E:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	mov r8, r0
	ldrh r0, [r0, #8]
	str r0, [sp, #0xc]
	mov r1, r8
	ldrh r1, [r1, #0xe]
	str r1, [sp, #0x10]
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_08168464
	ldr r2, _081671A4 @ =0x000004C4
	adds r0, r5, r2
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _081671A8 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081671B4
	ldr r1, _081671AC @ =0x000004B7
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
	ldr r2, _081671B0 @ =0x0000046E
	adds r7, r5, r2
	b _08167236
	.align 2, 0
_081671A0: .4byte 0x00000663
_081671A4: .4byte 0x000004C4
_081671A8: .4byte 0x0000025D
_081671AC: .4byte 0x000004B7
_081671B0: .4byte 0x0000046E
_081671B4:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _08167224 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08167228 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _081671EE
	ldrb r0, [r7]
	cmp r0, #0
	bne _081671EE
	cmp r4, #1
	bne _081671E0
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0816723A
_081671E0:
	cmp r4, #0
	bne _081671EE
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0816723A
_081671EE:
	strb r2, [r3]
	movs r1, #4
	mov sb, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _08167200
	movs r3, #6
_08167200:
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
	beq _0816722C
	ldr r0, [r6, #8]
	mov r2, sb
	orrs r0, r2
	b _08167234
	.align 2, 0
_08167224: .4byte 0x000004B7
_08167228: .4byte 0x0000046E
_0816722C:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08167234:
	str r0, [r6, #8]
_08167236:
	movs r0, #0
	strb r0, [r7]
_0816723A:
	mov r0, sp
	ldrh r1, [r0, #0xc]
	mov r0, r8
	strh r1, [r0, #8]
	mov r2, sp
	ldrh r2, [r2, #0x10]
	strh r2, [r0, #0xe]
	ldrb r1, [r5, #5]
	ldr r0, _08167250 @ =0x00000663
	add r0, sl
	b _08167258
	.align 2, 0
_08167250: .4byte 0x00000663
_08167254:
	ldr r2, _0816726C @ =0x0000046E
	adds r0, r5, r2
_08167258:
	strb r1, [r0]
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816726C: .4byte 0x0000046E

	thumb_func_start FUN_08167270
FUN_08167270: @ 0x08167270
	push {lr}
	adds r2, r0, #0
	ldr r0, _08167290 @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08167282
	movs r0, #0
	strb r0, [r1]
_08167282:
	adds r0, r2, #0
	movs r1, #0
	bl FUN_080ef86c
	pop {r0}
	bx r0
	.align 2, 0
_08167290: .4byte 0x0000046D

	thumb_func_start FUN_08167294
FUN_08167294: @ 0x08167294
	push {lr}
	adds r2, r0, #0
	ldr r0, _081672B4 @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081672A6
	movs r0, #0
	strb r0, [r1]
_081672A6:
	adds r0, r2, #0
	movs r1, #0xe
	bl FUN_080ef86c
	pop {r0}
	bx r0
	.align 2, 0
_081672B4: .4byte 0x0000046D

	thumb_func_start FUN_081672b8
FUN_081672b8: @ 0x081672B8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081672D0 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081672D4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081672D6
	.align 2, 0
_081672D0: .4byte 0x0000046D
_081672D4:
	movs r0, #0
_081672D6:
	cmp r0, #0
	beq _081672E2
	adds r0, r4, #0
	movs r1, #5
	bl FUN_080ef86c
_081672E2:
	ldr r1, _081672FC @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081672F4
	ldr r0, _08167300 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_081672F4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081672FC: .4byte 0x0000046E
_08167300: .4byte 0x0000046B

	thumb_func_start FUN_08167304
FUN_08167304: @ 0x08167304
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r3, _08167330 @ =0x0000046D
	adds r1, r5, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _08167334
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08167336
	.align 2, 0
_08167330: .4byte 0x0000046D
_08167334:
	movs r0, #0
_08167336:
	adds r2, r0, #0
	cmp r2, #0
	beq _08167424
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_08168464
	ldr r3, _08167384 @ =0x000004C4
	adds r0, r5, r3
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _08167388 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08167394
	ldr r1, _0816738C @ =0x000004B7
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
	ldr r3, _08167390 @ =0x0000046E
	adds r7, r5, r3
	b _08167416
	.align 2, 0
_08167384: .4byte 0x000004C4
_08167388: .4byte 0x0000025D
_0816738C: .4byte 0x000004B7
_08167390: .4byte 0x0000046E
_08167394:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _08167404 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08167408 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _081673CE
	ldrb r0, [r7]
	cmp r0, #0
	bne _081673CE
	cmp r4, #1
	bne _081673C0
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0816741A
_081673C0:
	cmp r4, #0
	bne _081673CE
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0816741A
_081673CE:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081673E0
	movs r3, #6
_081673E0:
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
	beq _0816740C
	ldr r0, [r6, #8]
	mov r3, r8
	orrs r0, r3
	b _08167414
	.align 2, 0
_08167404: .4byte 0x000004B7
_08167408: .4byte 0x0000046E
_0816740C:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08167414:
	str r0, [r6, #8]
_08167416:
	movs r0, #0
	strb r0, [r7]
_0816741A:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080ef86c
	b _08167530
_08167424:
	ldr r0, _08167488 @ =0x00000663
	add r0, sl
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrb r0, [r0]
	ldrb r3, [r1]
	cmp r0, r3
	bne _08167438
	b _08167544
_08167438:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	mov r8, r0
	ldrh r0, [r0, #8]
	str r0, [sp, #0xc]
	mov r3, r8
	ldrh r3, [r3, #0xe]
	str r3, [sp, #0x10]
	ldrb r0, [r1]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_08168464
	ldr r1, _0816748C @ =0x000004C4
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _08167490 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816749C
	ldr r1, _08167494 @ =0x000004B7
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
	ldr r3, _08167498 @ =0x0000046E
	adds r7, r5, r3
	b _0816751E
	.align 2, 0
_08167488: .4byte 0x00000663
_0816748C: .4byte 0x000004C4
_08167490: .4byte 0x0000025D
_08167494: .4byte 0x000004B7
_08167498: .4byte 0x0000046E
_0816749C:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _0816750C @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08167510 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _081674D6
	ldrb r0, [r7]
	cmp r0, #0
	bne _081674D6
	cmp r4, #1
	bne _081674C8
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08167522
_081674C8:
	cmp r4, #0
	bne _081674D6
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08167522
_081674D6:
	strb r2, [r3]
	movs r1, #4
	mov sb, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081674E8
	movs r3, #6
_081674E8:
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
	beq _08167514
	ldr r0, [r6, #8]
	mov r3, sb
	orrs r0, r3
	b _0816751C
	.align 2, 0
_0816750C: .4byte 0x000004B7
_08167510: .4byte 0x0000046E
_08167514:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0816751C:
	str r0, [r6, #8]
_0816751E:
	movs r0, #0
	strb r0, [r7]
_08167522:
	mov r0, sp
	ldrh r1, [r0, #0xc]
	mov r0, r8
	strh r1, [r0, #8]
	mov r3, sp
	ldrh r3, [r3, #0x10]
	strh r3, [r0, #0xe]
_08167530:
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r0, _08167540 @ =0x00000663
	add r0, sl
	strb r1, [r0]
	b _0816754A
	.align 2, 0
_08167540: .4byte 0x00000663
_08167544:
	ldr r3, _0816755C @ =0x0000046E
	adds r0, r5, r3
	strb r2, [r0]
_0816754A:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0816755C: .4byte 0x0000046E

	thumb_func_start FUN_08167560
FUN_08167560: @ 0x08167560
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _08167584 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08167588
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816758A
	.align 2, 0
_08167584: .4byte 0x0000046D
_08167588:
	movs r0, #0
_0816758A:
	cmp r0, #0
	beq _081675B4
	movs r0, #0x20
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r4, r7, r3
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, _081675E4 @ =0xFFFFFEFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_081675B4:
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	adds r5, #0x98
	adds r1, r7, r5
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _081675E8
	asrs r0, r0, #2
	b _081675EE
	.align 2, 0
_081675E4: .4byte 0xFFFFFEFF
_081675E8:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081675EE:
	adds r3, r0, #0
	movs r5, #0x84
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r5, #8
	adds r1, r7, r5
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _0816760C
	asrs r0, r0, #2
	b _08167612
_0816760C:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08167612:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _0816761C
	movs r3, #0xc8
	b _08167626
_0816761C:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _08167626
	adds r3, r0, #0
_08167626:
	cmp r2, #0xc8
	ble _0816762E
	movs r2, #0xc8
	b _08167638
_0816762E:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _08167638
	adds r2, r0, #0
_08167638:
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
	bne _0816765C
	cmp r2, #0
	bne _0816765C
	movs r0, #1
	b _0816765E
_0816765C:
	movs r0, #0
_0816765E:
	cmp r0, #0
	beq _081676CC
	ldr r1, _081676D8 @ =0x0000046B
	adds r0, r7, r1
	movs r6, #0
	movs r5, #1
	strb r5, [r0]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r4, #0
	strh r0, [r2]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_08168380
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _081676DC @ =0x00000469
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _081676E0 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	adds r2, #0x1c
	adds r0, r7, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r7, r3
	strb r5, [r0]
	movs r2, #8
	movs r1, #0xcb
	lsls r1, r1, #3
	add r1, r8
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081676E4 @ =0x000006AE
	add r1, r8
	movs r0, #0x3c
	strb r0, [r1]
_081676CC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081676D8: .4byte 0x0000046B
_081676DC: .4byte 0x00000469
_081676E0: .4byte 0x0000046A
_081676E4: .4byte 0x000006AE

	thumb_func_start FUN_081676e8
FUN_081676e8: @ 0x081676E8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, _08167704 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08167708
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816770A
	.align 2, 0
_08167704: .4byte 0x0000046D
_08167708:
	movs r0, #0
_0816770A:
	cmp r0, #0
	beq _0816774C
	adds r0, r6, #0
	movs r1, #0xa
	bl FUN_080ef86c
	adds r0, r6, #0
	bl FUN_080e8360
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r1, _081677F4 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _081677F8 @ =0x0000021E
	adds r0, r6, r2
	movs r1, #0
	strh r1, [r0]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r1, [r0]
	ldr r7, _081677FC @ =0x00000202
	adds r0, r6, r7
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_0816774C:
	ldr r0, [r6, #0x44]
	adds r1, r4, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08167760
	b _0816789E
_08167760:
	ldr r1, _08167800 @ =0x0000046B
	adds r0, r6, r1
	movs r4, #1
	strb r4, [r0]
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _081677CA
	movs r7, #8
	ldrsh r0, [r6, r7]
	str r0, [sp]
	movs r1, #0xa
	ldrsh r0, [r6, r1]
	str r0, [sp, #4]
	movs r3, #0xc
	ldrsh r0, [r6, r3]
	str r0, [sp, #8]
	movs r7, #0xce
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r7, #0x94
	lsls r7, r7, #3
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r6]
	str r0, [sp, #0x1c]
	ldr r1, _08167804 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_081677CA:
	ldr r1, _08167808 @ =0x000001DF
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _08167810
	ldr r0, _0816780C @ =0x030046A0
	ldr r2, [r0]
	movs r7, #0xe2
	lsls r7, r7, #2
	adds r2, r2, r7
	adds r1, r4, #0
	lsls r1, r3
	b _08167822
	.align 2, 0
_081677F4: .4byte 0xFFFEBE3F
_081677F8: .4byte 0x0000021E
_081677FC: .4byte 0x00000202
_08167800: .4byte 0x0000046B
_08167804: .4byte 0xFFFF0000
_08167808: .4byte 0x000001DF
_0816780C: .4byte 0x030046A0
_08167810:
	ldr r0, _081678A8 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_08167822:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #3
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08167840
	adds r0, r6, #0
	bl FUN_080e6658
_08167840:
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r5, #0
	movs r2, #0
	strh r2, [r0]
	ldr r4, _081678AC @ =FUN_080e48d0
	movs r3, #0x10
	ldr r7, _081678B0 @ =0x0000046D
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
	ldr r4, _081678B4 @ =0x00000469
	adds r0, r6, r4
	strb r5, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _081678B8 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	movs r7, #0x9a
	lsls r7, r7, #2
	adds r0, r6, r7
	bl FUN_080136b4
_0816789E:
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081678A8: .4byte 0x030046A0
_081678AC: .4byte FUN_080e48d0
_081678B0: .4byte 0x0000046D
_081678B4: .4byte 0x00000469
_081678B8: .4byte 0x00000484

	thumb_func_start FUN_081678bc
FUN_081678bc: @ 0x081678BC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _081678D4 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081678D8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081678DA
	.align 2, 0
_081678D4: .4byte 0x0000046C
_081678D8:
	movs r0, #0
_081678DA:
	cmp r0, #0
	beq _0816799E
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r4, [r0]
	movs r3, #1
	ldr r6, _08167948 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	strb r3, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
	ldr r0, _0816794C @ =0x00000704
	adds r1, r1, r0
	str r2, [sp]
	mov r0, sp
	ldr r2, _08167950 @ =0x05000002
	bl CpuSet
	ldr r2, _08167954 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08167958 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0816795C @ =0x0203B400
	adds r0, r0, r1
	ldrb r3, [r0]
	ldr r1, _08167960 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _08167964
	asrs r1, r0, #6
	b _0816796A
	.align 2, 0
_08167948: .4byte 0x0000046D
_0816794C: .4byte 0x00000704
_08167950: .4byte 0x05000002
_08167954: .4byte 0x030046B8
_08167958: .4byte 0x000003FF
_0816795C: .4byte 0x0203B400
_08167960: .4byte 0x085B0A08
_08167964:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r1, r0, #0
_0816796A:
	movs r6, #0xe0
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r1, [r0]
	ldr r2, _0816798C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _08167990
	asrs r1, r0, #6
	b _08167996
	.align 2, 0
_0816798C: .4byte 0x085B0A08
_08167990:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r1, r0, #0
_08167996:
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
_0816799E:
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r4, r5, r3
	movs r6, #0
	ldrsh r0, [r4, r6]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r6, r1, r0
	cmp r6, #0
	bne _081679FE
	adds r0, r5, #0
	bl FUN_08168380
	str r6, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _08167A10 @ =0x05000002
	bl CpuSet
	ldr r0, _08167A14 @ =0x03002BE0
	ldr r1, [r0]
	adds r1, #0x2c
	adds r0, r5, #0
	bl FUN_081683c0
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r6, [r0]
	ldr r3, _08167A18 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _08167A1C @ =0x0000046A
	adds r0, r5, r1
	strb r6, [r0]
	adds r2, #0x1c
	adds r0, r5, r2
	str r6, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
_081679FE:
	ldr r6, _08167A20 @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08167A10: .4byte 0x05000002
_08167A14: .4byte 0x03002BE0
_08167A18: .4byte 0x00000469
_08167A1C: .4byte 0x0000046A
_08167A20: .4byte 0x00000484

	thumb_func_start FUN_08167a24
FUN_08167a24: @ 0x08167A24
	ldr r1, _08167A30 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _08167A34 @ =0x085ADA14
	str r1, [r0]
	bx lr
	.align 2, 0
_08167A30: .4byte 0x00000634
_08167A34: .4byte 0x085ADA14

	thumb_func_start FUN_08167a38
FUN_08167a38: @ 0x08167A38
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r5, r1, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08167A52
	b _08167C04
_08167A52:
	movs r1, #0x80
	lsls r1, r1, #7
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08167A66
	b _08167C04
_08167A66:
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r4, [r0]
	ldrh r1, [r5, #2]
	movs r2, #0xd8
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r7, #0
	strh r1, [r0]
	ldrh r0, [r0]
	bl FUN_0823b2d0
	ldr r1, _08167B10 @ =0x000006C4
	adds r3, r4, r1
	str r0, [r3]
	ldrh r1, [r5, #4]
	ldr r2, _08167B14 @ =0x000006C2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r5, _08167B18 @ =0x000006AC
	adds r0, r4, r5
	strb r7, [r0]
	add r2, sp, #4
	adds r0, r6, #0
	adds r0, #8
	str r0, [sp, #0x14]
	ldr r0, [r3]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldr r5, [sp, #0x14]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	movs r5, #0xfe
	lsls r5, r5, #1
	adds r3, r6, r5
	strb r0, [r3]
	ldr r2, _08167B1C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08167B20 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08167B24 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	ldrb r3, [r3]
	adds r3, r0, r3
	movs r1, #0xff
	add r7, sp, #0xc
	ands r3, r1
	ldr r2, _08167B28 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #9
	ldr r5, [sp, #0x14]
	adds r2, r7, #0
	cmp r0, #0
	blt _08167B2C
	asrs r1, r0, #0xc
	b _08167B32
	.align 2, 0
_08167B10: .4byte 0x000006C4
_08167B14: .4byte 0x000006C2
_08167B18: .4byte 0x000006AC
_08167B1C: .4byte 0x030046B8
_08167B20: .4byte 0x000003FF
_08167B24: .4byte 0x0203B400
_08167B28: .4byte 0x085B0A08
_08167B2C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08167B32:
	movs r0, #0
	strh r1, [r7]
	strh r0, [r7, #2]
	ldr r1, _08167B50 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x80
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _08167B54
	asrs r0, r0, #0xc
	b _08167B5A
	.align 2, 0
_08167B50: .4byte 0x085B0A08
_08167B54:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08167B5A:
	movs r1, #0
	mov sb, r1
	movs r3, #0
	mov r8, r3
	strh r0, [r7, #4]
	ldr r0, _08167C14 @ =0x000006BE
	adds r1, r4, r0
	movs r0, #0xa0
	lsls r0, r0, #3
	strh r0, [r1]
	add r1, sp, #0xc
	ldrh r0, [r6, #8]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r5, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r0, r6, #0
	adds r1, r2, #0
	str r2, [sp, #0x18]
	bl FUN_081684b4
	adds r0, r6, #0
	adds r1, r5, #0
	ldr r2, [sp, #0x18]
	bl FUN_0816869c
	ldr r2, _08167C18 @ =0x00000704
	adds r1, r4, r2
	mov r3, r8
	str r3, [sp]
	mov r0, sp
	ldr r2, _08167C1C @ =0x05000002
	bl CpuSet
	movs r1, #2
	movs r2, #6
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r6, r5
	strb r1, [r0]
	ldr r1, _08167C20 @ =0x00000469
	adds r0, r6, r1
	mov r3, sb
	strb r3, [r0]
	adds r5, #2
	adds r0, r6, r5
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r6, r1
	mov r2, r8
	str r2, [r0]
	ldr r3, _08167C24 @ =0x0000046C
	adds r0, r6, r3
	movs r1, #1
	strb r1, [r0]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r6, r5
	ldr r2, [r0]
	adds r3, #1
	adds r0, r6, r3
	strb r1, [r0]
	ldr r5, _08167C28 @ =0x0000046B
	adds r0, r6, r5
	mov r3, sb
	strb r3, [r0]
	adds r5, #0xe8
	adds r0, r6, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	mov r3, r8
	strh r3, [r0]
_08167C04:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08167C14: .4byte 0x000006BE
_08167C18: .4byte 0x00000704
_08167C1C: .4byte 0x05000002
_08167C20: .4byte 0x00000469
_08167C24: .4byte 0x0000046C
_08167C28: .4byte 0x0000046B

	thumb_func_start FUN_08167c2c
FUN_08167c2c: @ 0x08167C2C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r2, _08167CA8 @ =0x00000661
	adds r0, r5, r2
	movs r3, #0
	strb r3, [r0]
	ldr r1, _08167CAC @ =0x000006B4
	adds r0, r5, r1
	movs r2, #0
	strh r3, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	ldr r0, _08167CB0 @ =0x000006B7
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xd7
	lsls r1, r1, #3
	adds r0, r5, r1
	strh r3, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	ldr r3, _08167CB4 @ =0x0000070C
	adds r2, r5, r3
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #8]
	str r1, [r6, #0xc]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _08167CA4
	cmp r1, #0
	blt _08167CA4
	ldr r0, _08167CB8 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _08167CA4
	ldr r0, _08167CBC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08167CC0
_08167CA4:
	movs r1, #0
	b _08167CCE
	.align 2, 0
_08167CA8: .4byte 0x00000661
_08167CAC: .4byte 0x000006B4
_08167CB0: .4byte 0x000006B7
_08167CB4: .4byte 0x0000070C
_08167CB8: .4byte 0x030046A8
_08167CBC: .4byte 0x030046AC
_08167CC0:
	ldr r0, _08167CEC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r3
_08167CCE:
	ldr r2, _08167CF0 @ =0x00000256
	adds r0, r6, r2
	strh r1, [r0]
	ldrh r4, [r0]
	ldr r3, _08167CF4 @ =0x0000070C
	adds r7, r5, r3
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08167CF8
	adds r0, #4
	b _08167D04
	.align 2, 0
_08167CEC: .4byte 0x030046A4
_08167CF0: .4byte 0x00000256
_08167CF4: .4byte 0x0000070C
_08167CF8:
	ldr r0, _08167D18 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08167D04:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08167D1C
	cmp r3, #2
	beq _08167D20
	b _08167D24
	.align 2, 0
_08167D18: .4byte 0x030046A4
_08167D1C:
	ldrb r0, [r7, #4]
	b _08167D22
_08167D20:
	ldrb r0, [r7]
_08167D22:
	subs r2, r2, r0
_08167D24:
	ldr r0, _08167D50 @ =0x00000472
	adds r1, r6, r0
	strh r2, [r1]
	ldrh r0, [r6, #0xa]
	subs r0, r0, r2
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r2, r6, r3
	strh r0, [r2]
	ldrh r0, [r1]
	strh r0, [r6, #0xa]
	ldr r1, _08167D54 @ =0x0000025D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08167D58
	ldr r2, [r6, #0x44]
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _08167D62
	.align 2, 0
_08167D50: .4byte 0x00000472
_08167D54: .4byte 0x0000025D
_08167D58:
	ldr r2, [r6, #0x44]
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_08167D62:
	ldr r2, _08167DC8 @ =0x000006F4
	adds r1, r5, r2
	movs r4, #0
	str r4, [sp]
	mov r0, sp
	ldr r2, _08167DCC @ =0x05000002
	bl CpuSet
	ldr r3, _08167DD0 @ =0x000006FC
	adds r1, r5, r3
	str r4, [sp]
	mov r0, sp
	ldr r2, _08167DCC @ =0x05000002
	bl CpuSet
	ldr r0, _08167DD4 @ =0x00000704
	adds r1, r5, r0
	str r4, [sp]
	mov r0, sp
	ldr r2, _08167DCC @ =0x05000002
	bl CpuSet
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, [r6, #0x44]
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
	beq _08167DD8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08167DE0
	.align 2, 0
_08167DC8: .4byte 0x000006F4
_08167DCC: .4byte 0x05000002
_08167DD0: .4byte 0x000006FC
_08167DD4: .4byte 0x00000704
_08167DD8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08167DE0:
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
	beq _08167E04
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08167E0C
_08167E04:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08167E0C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08167E44 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08167E7C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08167E48
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08167E3C
	ldrb r0, [r4, #5]
_08167E3C:
	subs r0, #1
	strh r0, [r4, #8]
	b _08167E58
	.align 2, 0
_08167E44: .4byte 0x0000FFFF
_08167E48:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08167E58
	strh r1, [r4, #8]
_08167E58:
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
	bne _08167E7C
	movs r0, #1
	strb r0, [r4, #7]
_08167E7C:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08167e84
FUN_08167e84: @ 0x08167E84
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08167E9E
	b _08168004
_08167E9E:
	ldr r2, _08167ED8 @ =0x00000472
	adds r5, r4, r2
	ldrh r1, [r5]
	ldr r3, _08167EDC @ =0x0000065E
	adds r2, r6, r3
	ldrh r0, [r2]
	subs r1, r1, r0
	movs r0, #0xdf
	lsls r0, r0, #1
	adds r3, r4, r0
	ldrh r0, [r3]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r5]
	strh r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xd
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08167EE0
	ldrh r0, [r3]
	ldrh r5, [r5]
	adds r0, r0, r5
	strh r0, [r4, #0xa]
	b _08168004
	.align 2, 0
_08167ED8: .4byte 0x00000472
_08167EDC: .4byte 0x0000065E
_08167EE0:
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _08167F00 @ =0x00000103
	cmp r1, r0
	bgt _08167F64
	movs r1, #1
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08167F04
	movs r0, #1
	b _08167F06
	.align 2, 0
_08167F00: .4byte 0x00000103
_08167F04:
	movs r0, #0
_08167F06:
	cmp r0, #0
	beq _08167F18
	ldr r3, _08167F14 @ =0x00000472
	adds r0, r4, r3
	ldrh r0, [r0]
	strh r0, [r4, #0xa]
	b _08168004
	.align 2, 0
_08167F14: .4byte 0x00000472
_08167F18:
	ldr r1, _08167F30 @ =0x085B0A08
	ldr r2, _08167F34 @ =0x000006B6
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _08167F38
	asrs r1, r0, #9
	b _08167F3E
	.align 2, 0
_08167F30: .4byte 0x085B0A08
_08167F34: .4byte 0x000006B6
_08167F38:
	rsbs r0, r0, #0
	asrs r0, r0, #9
	rsbs r1, r0, #0
_08167F3E:
	movs r0, #0xdf
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	ldr r3, _08167F90 @ =0x000006B6
	adds r1, r6, r3
	ldrb r0, [r1]
	cmp r0, #0x3f
	bhi _08167F58
	adds r0, #1
	strb r0, [r1]
_08167F58:
	ldr r0, _08167F94 @ =0x00000472
	adds r1, r4, r0
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0xa]
_08167F64:
	ldr r1, _08167F94 @ =0x00000472
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0xa
	ldrsh r0, [r4, r2]
	ldr r3, _08167F98 @ =0xFFFFFEFC
	adds r0, r0, r3
	subs r1, r1, r0
	adds r0, r1, #0
	cmp r1, #0
	bge _08167F7C
	rsbs r0, r1, #0
_08167F7C:
	cmp r0, #0x10
	ble _08167FA8
	cmp r1, #0
	bge _08167F9C
	movs r0, #0xdf
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #8
	b _08167FA6
	.align 2, 0
_08167F90: .4byte 0x000006B6
_08167F94: .4byte 0x00000472
_08167F98: .4byte 0xFFFFFEFC
_08167F9C:
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #8
_08167FA6:
	strh r0, [r1]
_08167FA8:
	ldr r3, _08167FD4 @ =0x00000472
	adds r1, r4, r3
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0xa]
	ldr r2, [r4, #0x44]
	ldr r1, _08167FD8 @ =0x085B0A08
	ldr r3, _08167FDC @ =0x000006B6
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _08167FE0
	asrs r1, r0, #5
	b _08167FE6
	.align 2, 0
_08167FD4: .4byte 0x00000472
_08167FD8: .4byte 0x085B0A08
_08167FDC: .4byte 0x000006B6
_08167FE0:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r1, r0, #0
_08167FE6:
	ldrh r0, [r2, #0x1e]
	subs r0, r0, r1
	strh r0, [r2, #0x1e]
	ldr r3, _08167FFC @ =0x000006B6
	adds r2, r6, r3
	ldrb r0, [r2]
	cmp r0, #0x40
	bls _08168000
	movs r0, #0
	b _08168002
	.align 2, 0
_08167FFC: .4byte 0x000006B6
_08168000:
	adds r0, #8
_08168002:
	strb r0, [r2]
_08168004:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0816800c
FUN_0816800c: @ 0x0816800C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x28
	adds r6, r0, #0
	ldr r4, _08168090 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	movs r2, #0x10
	orrs r0, r2
	ldr r1, _08168094 @ =0x0000FFFF
	mov r8, r1
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r4
	orrs r0, r2
	str r0, [sp, #0xc]
	movs r5, #0
	str r5, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _08168098 @ =FUN_081668f4
	str r6, [sp]
	adds r0, r6, #0
	add r1, sp, #8
	bl FUN_080e3834
	ldr r0, [sp, #0x18]
	ands r0, r4
	movs r2, #0x20
	orrs r0, r2
	mov r1, r8
	ands r0, r1
	movs r1, #0xd0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r4
	orrs r0, r2
	str r0, [r1, #4]
	str r5, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _0816809C @ =FUN_081668f0
	str r5, [sp]
	str r6, [sp, #4]
	adds r0, r6, #0
	bl FUN_080e3984
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08168090: .4byte 0xFFFF0000
_08168094: .4byte 0x0000FFFF
_08168098: .4byte FUN_081668f4
_0816809C: .4byte FUN_081668f0

	thumb_func_start FUN_081680a0
FUN_081680a0: @ 0x081680A0
	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r4, _081680B8 @ =0x000006B4
	adds r0, r3, r4
	ldrh r0, [r0]
	cmp r0, #0
	blt _081680BC
	asrs r0, r0, #7
	b _081680C2
	.align 2, 0
_081680B8: .4byte 0x000006B4
_081680BC:
	rsbs r0, r0, #0
	asrs r0, r0, #7
	rsbs r0, r0, #0
_081680C2:
	cmp r0, #0
	bge _081680C8
	rsbs r0, r0, #0
_081680C8:
	adds r2, r0, #0
	cmp r2, #7
	ble _081680D0
	movs r2, #7
_081680D0:
	movs r1, #4
	movs r4, #0xcb
	lsls r4, r4, #3
	adds r0, r3, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081680E4
	movs r0, #1
	b _081680E6
_081680E4:
	movs r0, #0
_081680E6:
	cmp r0, #0
	bne _081680F8
	ldr r0, _081680F4 @ =0x085ADA18
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r0, [r1]
	b _08168102
	.align 2, 0
_081680F4: .4byte 0x085ADA18
_081680F8:
	ldr r0, _08168108 @ =0x085ADA18
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, #6
_08168102:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08168108: .4byte 0x085ADA18

	thumb_func_start FUN_0816810c
FUN_0816810c: @ 0x0816810C
	push {r4, r5, lr}
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r2, r0, r3
	ldr r4, [r2]
	ldr r2, _0816813C @ =0x000006F4
	adds r5, r4, r2
	ldr r2, [r0, #8]
	ldr r3, [r0, #0xc]
	str r2, [r5]
	str r3, [r5, #4]
	ldr r3, _08168140 @ =0x000006FC
	adds r2, r4, r3
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, _08168144 @ =0x000006B4
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0816813C: .4byte 0x000006F4
_08168140: .4byte 0x000006FC
_08168144: .4byte 0x000006B4

	thumb_func_start FUN_08168148
FUN_08168148: @ 0x08168148
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
	ldr r1, _081681E0 @ =0x000006F4
	add r1, r8
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [sp, #4]
	str r2, [sp, #8]
	ldr r1, _081681E4 @ =0x000006FC
	add r1, r8
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	ldr r2, _081681E8 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	str r1, [sp, #4]
	ldr r1, [sp, #0xc]
	ands r1, r2
	str r1, [sp, #0xc]
	ldr r1, _081681EC @ =0x000006B4
	add r1, r8
	movs r3, #0xd7
	lsls r3, r3, #3
	add r3, r8
	ldr r5, _081681F0 @ =0x000004A4
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
	ldr r2, _081681F4 @ =0x05000002
	bl CpuSet
	adds r0, r6, #0
	muls r0, r6, r0
	mov sl, r4
	mov ip, r5
	cmp r0, #0
	blt _081681F8
	asrs r0, r0, #0xa
	b _081681FE
	.align 2, 0
_081681E0: .4byte 0x000006F4
_081681E4: .4byte 0x000006FC
_081681E8: .4byte 0x0000FFFF
_081681EC: .4byte 0x000006B4
_081681F0: .4byte 0x000004A4
_081681F4: .4byte 0x05000002
_081681F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_081681FE:
	adds r1, r0, #0
	adds r0, r1, #0
	muls r0, r6, r0
	cmp r0, #0
	blt _0816820C
	asrs r3, r0, #0xa
	b _08168212
_0816820C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r3, r0, #0
_08168212:
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
	blt _0816824A
	asrs r1, r0, #0xa
	b _08168250
_0816824A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_08168250:
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
	blt _0816828A
	asrs r1, r0, #0xa
	b _08168290
_0816828A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_08168290:
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
	blt _081682BE
	asrs r1, r0, #0xa
	b _081682C4
_081682BE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081682C4:
	ldrh r0, [r7, #4]
	adds r0, r0, r1
	mov r5, sb
	strh r0, [r5, #4]
	ldr r3, _081682E0 @ =0x000006B4
	add r3, r8
	ldrh r4, [r3]
	ldr r2, _081682E4 @ =0x000003FF
	cmp r4, r2
	bls _081682E8
	movs r0, #0
	strh r0, [r3]
	movs r0, #1
	b _08168316
	.align 2, 0
_081682E0: .4byte 0x000006B4
_081682E4: .4byte 0x000003FF
_081682E8:
	ldr r1, _08168328 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _0816832C @ =0x0203B400
	adds r0, r0, r6
	ldrb r0, [r0]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	adds r0, r0, r1
	adds r0, r4, r0
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #3
	cmp r0, r1
	bls _08168314
	strh r1, [r3]
_08168314:
	movs r0, #0
_08168316:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08168328: .4byte 0x030046B8
_0816832C: .4byte 0x0203B400

	thumb_func_start FUN_08168330
FUN_08168330: @ 0x08168330
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
	movs r1, #3
	movs r2, #3
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #3
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xe
	movs r2, #1
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #5
	movs r2, #2
	movs r3, #0
	bl FUN_080ef84c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08168380
FUN_08168380: @ 0x08168380
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
	movs r2, #4
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r2, #0x97
	lsls r2, r2, #1
	add r2, ip
	ldrh r1, [r2]
	ldr r0, _081683BC @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	bx lr
	.align 2, 0
_081683BC: .4byte 0x0000FFFB

	thumb_func_start FUN_081683c0
FUN_081683c0: @ 0x081683C0
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
	bl FUN_0816810c
	adds r0, r4, #0
	bl FUN_08168148
	movs r1, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r6, #0
	strb r6, [r0]
	ldr r3, _08168458 @ =0x00000469
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
	ldr r2, _0816845C @ =0x00000704
	add r8, r2
	str r6, [sp]
	mov r0, sp
	mov r1, r8
	ldr r2, _08168460 @ =0x05000002
	bl CpuSet
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08168458: .4byte 0x00000469
_0816845C: .4byte 0x00000704
_08168460: .4byte 0x05000002

	thumb_func_start FUN_08168464
FUN_08168464: @ 0x08168464
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
	ble _08168488
	movs r0, #8
	subs r0, r0, r1
	str r0, [r3]
	movs r0, #1
	b _0816848C
_08168488:
	str r1, [r3]
	movs r0, #0
_0816848C:
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08168494
FUN_08168494: @ 0x08168494
	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081684AE
	subs r0, #1
	strb r0, [r1]
_081684AE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081684b4
FUN_081684b4: @ 0x081684B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r2, r0, r3
	ldr r2, [r2]
	str r2, [sp, #0x24]
	ldr r2, [r0, #8]
	ldr r3, [r0, #0xc]
	str r2, [sp, #4]
	str r3, [sp, #8]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r1, _0816857C @ =0x0000FFFF
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
	movs r0, #0x80
	lsls r0, r0, #3
	movs r1, #8
	bl Div
	str r0, [sp, #0x28]
	ldr r4, [sp, #0x24]
	ldr r7, _08168580 @ =0x00000704
	adds r0, r4, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #4
	str r0, [sp, #0x2c]
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #4
	str r0, [sp, #0x30]
	movs r0, #0
	mov r4, sp
	adds r4, #0x14
	str r4, [sp, #0x38]
	add r7, sp, #0x1c
	mov sl, r7
	add r1, sp, #4
	mov sb, r1
	mov r2, sp
	adds r2, #0xc
	str r2, [sp, #0x34]
_08168526:
	adds r4, r0, #1
	lsls r0, r0, #3
	ldr r3, [sp, #0x24]
	adds r0, r0, r3
	mov r8, r0
	ldr r7, _08168584 @ =0x00000664
	add r8, r7
	ldr r0, [sp, #0x28]
	adds r5, r0, #0
	muls r5, r4, r5
	add r0, sp, #0xc
	ldrh r1, [r0]
	add r0, sp, #4
	ldrh r0, [r0]
	subs r1, r1, r0
	add r0, sp, #0x14
	strh r1, [r0]
	ldr r1, [sp, #0x34]
	ldrh r0, [r1, #2]
	mov r2, sb
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	mov r3, sp
	strh r0, [r3, #0x16]
	ldr r7, [sp, #0x34]
	ldrh r0, [r7, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #0x18]
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	mov r1, sl
	ldr r2, _08168588 @ =0x05000002
	bl CpuSet
	adds r0, r5, #0
	muls r0, r5, r0
	mov ip, r4
	cmp r0, #0
	blt _0816858C
	asrs r0, r0, #0xa
	b _08168592
	.align 2, 0
_0816857C: .4byte 0x0000FFFF
_08168580: .4byte 0x00000704
_08168584: .4byte 0x00000664
_08168588: .4byte 0x05000002
_0816858C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_08168592:
	adds r3, r0, #0
	adds r0, r3, #0
	muls r0, r5, r0
	cmp r0, #0
	blt _081685A0
	asrs r1, r0, #0xa
	b _081685A6
_081685A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081685A6:
	lsls r2, r1, #1
	lsls r0, r3, #1
	adds r6, r0, r3
	subs r0, r1, r0
	adds r0, r0, r5
	ldr r4, [sp, #0x30]
	adds r5, r0, #0
	muls r5, r4, r5
	subs r1, r1, r3
	str r1, [sp, #0x3c]
	subs r0, r2, r6
	adds r0, #1
	mov r7, sl
	movs r3, #0
	ldrsh r1, [r7, r3]
	muls r0, r1, r0
	ldr r7, [sp, #0x2c]
	adds r4, r0, #0
	muls r4, r7, r4
	subs r1, r6, r2
	ldr r3, [sp, #0x38]
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	ldr r1, [sp, #0x3c]
	adds r0, r0, r1
	cmp r0, #0
	blt _081685E6
	asrs r1, r0, #0xa
	b _081685EC
_081685E6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081685EC:
	mov r3, sb
	ldrh r0, [r3]
	adds r0, r0, r1
	mov r4, r8
	strh r0, [r4]
	subs r3, r2, r6
	adds r1, r3, #1
	mov r7, sl
	movs r4, #2
	ldrsh r0, [r7, r4]
	muls r0, r1, r0
	ldr r7, [sp, #0x2c]
	adds r4, r0, #0
	muls r4, r7, r4
	rsbs r2, r2, #0
	adds r0, r2, r6
	str r0, [sp, #0x40]
	ldr r1, [sp, #0x38]
	movs r7, #2
	ldrsh r0, [r1, r7]
	ldr r1, [sp, #0x40]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	ldr r4, [sp, #0x3c]
	adds r0, r0, r4
	cmp r0, #0
	blt _08168628
	asrs r1, r0, #0xa
	b _0816862E
_08168628:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0816862E:
	mov r7, sb
	ldrh r0, [r7, #2]
	adds r0, r0, r1
	mov r1, r8
	strh r0, [r1, #2]
	adds r1, r3, #1
	mov r3, sl
	movs r4, #4
	ldrsh r0, [r3, r4]
	muls r0, r1, r0
	ldr r7, [sp, #0x2c]
	adds r4, r0, #0
	muls r4, r7, r4
	adds r1, r2, r6
	ldr r2, [sp, #0x38]
	movs r3, #4
	ldrsh r0, [r2, r3]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	ldr r4, [sp, #0x3c]
	adds r0, r0, r4
	cmp r0, #0
	blt _08168662
	asrs r1, r0, #0xa
	b _08168668
_08168662:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_08168668:
	mov r7, sb
	ldrh r0, [r7, #4]
	adds r0, r0, r1
	mov r1, r8
	strh r0, [r1, #4]
	mov r0, ip
	cmp r0, #7
	bgt _0816867A
	b _08168526
_0816867A:
	ldr r3, [sp, #0x24]
	ldr r4, _08168698 @ =0x000006A4
	adds r2, r3, r4
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	str r0, [r2]
	str r1, [r2, #4]
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08168698: .4byte 0x000006A4

	thumb_func_start FUN_0816869c
FUN_0816869c: @ 0x0816869C
	push {r4, r5, lr}
	sub sp, #8
	mov r5, sp
	ldrh r3, [r2]
	ldrh r4, [r1]
	subs r3, r3, r4
	mov r4, sp
	strh r3, [r4]
	ldrh r3, [r2, #2]
	ldrh r4, [r1, #2]
	subs r3, r3, r4
	strh r3, [r5, #2]
	ldrh r2, [r2, #4]
	ldrh r1, [r1, #4]
	subs r2, r2, r1
	strh r2, [r5, #4]
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_081686c4
FUN_081686c4: @ 0x081686C4
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08168746
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08168718
	movs r3, #0x94
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r5, _08168710 @ =0x00000226
	adds r1, r4, r5
	ldrh r1, [r1]
	ldr r3, _08168714 @ =0x0000022E
	adds r2, r4, r3
	ldrh r2, [r2]
	adds r5, #0x1a
	adds r3, r4, r5
	ldr r3, [r3]
	str r3, [sp]
	subs r5, #0xa
	adds r3, r4, r5
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
	b _08168746
	.align 2, 0
_08168710: .4byte 0x00000226
_08168714: .4byte 0x0000022E
_08168718:
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r2, #0x89
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r1, [r1]
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrh r2, [r2]
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r3, r4, r5
	ldr r3, [r3]
	str r3, [sp]
	subs r5, #8
	adds r3, r4, r5
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
_08168746:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08168750
FUN_08168750: @ 0x08168750
	push {r4, lr}
	adds r3, r0, #0
	movs r0, #8
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r4, r3, r1
	ldr r1, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0816879C
	movs r0, #9
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r4]
	movs r2, #0xa
	ldrsh r1, [r3, r2]
	ldr r0, _081687A0 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x2e
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _08168780
	rsbs r1, r1, #0
_08168780:
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r1, r0
	bgt _0816879C
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blo _081687A4
_0816879C:
	movs r0, #0
	b _081687BE
	.align 2, 0
_081687A0: .4byte 0x03002BE0
_081687A4:
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
_081687BE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081687c4
FUN_081687c4: @ 0x081687C4
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	orrs r1, r2
	str r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081687d8
FUN_081687d8: @ 0x081687D8
	push {lr}
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #1
	beq _081687F2
	cmp r0, #1
	bgt _081687F6
	cmp r0, #0
	bne _081687F6
	movs r0, #5
	b _081687F8
_081687F2:
	movs r0, #2
	b _081687F8
_081687F6:
	movs r0, #4
_081687F8:
	pop {r1}
	bx r1

	thumb_func_start FUN_081687fc
FUN_081687fc: @ 0x081687FC
	push {lr}
	ldr r2, _08168810 @ =0x000006AF
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816880C
	subs r0, #1
	strb r0, [r1]
_0816880C:
	pop {r0}
	bx r0
	.align 2, 0
_08168810: .4byte 0x000006AF

	thumb_func_start FUN_08168814
FUN_08168814: @ 0x08168814
	push {lr}
	bl FUN_08167e84
	movs r0, #1
	pop {r1}
	bx r1

	thumb_func_start FUN_08168820
FUN_08168820: @ 0x08168820
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08168494
	adds r0, r4, #0
	bl FUN_081686c4
	adds r0, r4, #0
	bl FUN_081687fc
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0816883c
FUN_0816883c: @ 0x0816883C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _08168868 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816886C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816886E
	.align 2, 0
_08168868: .4byte 0x0000046C
_0816886C:
	movs r0, #0
_0816886E:
	movs r3, #8
	adds r3, r3, r6
	mov sb, r3
	cmp r0, #0
	bne _0816887A
	b _08168A44
_0816887A:
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _081688C8 @ =0x0000046D
	adds r0, r6, r2
	movs r2, #0
	strb r1, [r0]
	ldr r4, _081688CC @ =0x0000046B
	adds r0, r6, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r1, #0
	strh r2, [r0]
	ldr r0, _081688D0 @ =0x000006AC
	add r0, r8
	strb r1, [r0]
	movs r2, #8
	movs r1, #0xcb
	lsls r1, r1, #3
	add r1, r8
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081688D4
	movs r0, #1
	b _081688D6
	.align 2, 0
_081688C8: .4byte 0x0000046D
_081688CC: .4byte 0x0000046B
_081688D0: .4byte 0x000006AC
_081688D4:
	movs r0, #0
_081688D6:
	cmp r0, #0
	beq _0816896E
	ldr r2, _08168924 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08168928 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _0816892C @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrb r2, [r1]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x80
	adds r3, r2, r0
	movs r1, #0xff
	add r4, sp, #4
	ands r3, r1
	movs r5, #0xa0
	lsls r5, r5, #1
	ldr r2, _08168930 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	mov sl, r4
	cmp r0, #0
	blt _08168934
	asrs r1, r0, #0xc
	b _0816893A
	.align 2, 0
_08168924: .4byte 0x030046B8
_08168928: .4byte 0x000003FF
_0816892C: .4byte 0x0203B400
_08168930: .4byte 0x085B0A08
_08168934:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816893A:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08168952
	asrs r0, r0, #0xc
	b _08168958
_08168952:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08168958:
	strh r0, [r4, #4]
	movs r1, #9
	rsbs r1, r1, #0
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	adds r0, r6, #0
	bl FUN_081687d8
	movs r1, #6
	b _081689F6
_0816896E:
	ldr r2, _081689B4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081689B8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081689BC @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r4, #0xfe
	lsls r4, r4, #1
	adds r2, r6, r4
	movs r1, #0x3f
	ands r0, r1
	ldrb r2, [r2]
	adds r3, r0, r2
	movs r1, #0xff
	add r4, sp, #4
	ands r3, r1
	ldr r2, _081689C0 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	mov sl, r4
	cmp r0, #0
	blt _081689C4
	asrs r1, r0, #0xc
	b _081689CA
	.align 2, 0
_081689B4: .4byte 0x030046B8
_081689B8: .4byte 0x000003FF
_081689BC: .4byte 0x0203B400
_081689C0: .4byte 0x085B0A08
_081689C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081689CA:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _081689E6
	asrs r0, r0, #0xc
	b _081689EC
_081689E6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081689EC:
	strh r0, [r4, #4]
	adds r0, r6, #0
	bl FUN_081687d8
	movs r1, #0x28
_081689F6:
	lsls r1, r0
	ldr r0, _08168AAC @ =0x000006BE
	add r0, r8
	strh r1, [r0]
	add r1, sp, #4
	ldrh r0, [r6, #8]
	ldrh r3, [r1]
	adds r0, r0, r3
	movs r5, #0
	strh r0, [r1]
	mov r4, sl
	ldrh r0, [r4, #2]
	adds r4, r6, #0
	adds r4, #8
	ldrh r1, [r6, #0xa]
	adds r0, r0, r1
	mov r2, sl
	strh r0, [r2, #2]
	ldrh r0, [r4, #4]
	ldrh r3, [r2, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	adds r0, r6, #0
	mov r1, sl
	bl FUN_081684b4
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sl
	bl FUN_0816869c
	ldr r1, _08168AB0 @ =0x00000704
	add r1, r8
	str r5, [sp]
	mov r0, sp
	ldr r2, _08168AB4 @ =0x05000002
	bl CpuSet
	mov sb, r4
_08168A44:
	ldr r0, _08168AB8 @ =0x000006AC
	add r0, r8
	ldrb r1, [r0]
	add r3, sp, #0xc
	lsls r1, r1, #3
	add r1, r8
	ldr r4, _08168ABC @ =0x00000664
	adds r1, r1, r4
	ldrh r0, [r1]
	ldrh r2, [r6, #8]
	subs r0, r0, r2
	strh r0, [r3]
	ldrh r0, [r1, #2]
	mov r4, sb
	ldrh r2, [r4, #2]
	subs r0, r0, r2
	strh r0, [r3, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrb r0, [r0]
	strb r0, [r6, #5]
	ldr r2, _08168AAC @ =0x000006BE
	add r2, r8
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, #0
	ble _08168B48
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r4, #4
	ldrsh r0, [r3, r4]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r1, r0
	ble _08168B48
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, #0
	blt _08168AC0
	asrs r1, r0, #5
	b _08168AC6
	.align 2, 0
_08168AAC: .4byte 0x000006BE
_08168AB0: .4byte 0x00000704
_08168AB4: .4byte 0x05000002
_08168AB8: .4byte 0x000006AC
_08168ABC: .4byte 0x00000664
_08168AC0:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r1, r0, #0
_08168AC6:
	adds r5, r1, #0
	cmp r5, #1
	bge _08168ACE
	movs r5, #1
_08168ACE:
	ldr r4, _08168B34 @ =0x000006AC
	add r4, r8
	ldrb r0, [r4]
	lsls r0, r0, #3
	add r0, r8
	ldr r1, _08168B38 @ =0x00000664
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r3, #8
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	adds r1, r5, #0
	bl Div
	ldrh r1, [r6, #0x10]
	adds r1, r1, r0
	strh r1, [r6, #0x10]
	ldrb r0, [r4]
	lsls r0, r0, #3
	add r0, r8
	movs r4, #0xcd
	lsls r4, r4, #3
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0xc
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	adds r1, r5, #0
	bl Div
	ldrh r1, [r6, #0x14]
	adds r1, r1, r0
	strh r1, [r6, #0x14]
	ldr r2, _08168B3C @ =0x00000704
	add r2, r8
	ldr r0, [r6, #0x10]
	ldr r1, [r6, #0x14]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _08168B40 @ =0x000006BE
	add r2, r8
	ldr r3, _08168B44 @ =0x00000484
	adds r0, r6, r3
	ldr r1, [r0]
	ldrh r0, [r2]
	subs r0, r0, r1
	strh r0, [r2]
	b _08168C7E
	.align 2, 0
_08168B34: .4byte 0x000006AC
_08168B38: .4byte 0x00000664
_08168B3C: .4byte 0x00000704
_08168B40: .4byte 0x000006BE
_08168B44: .4byte 0x00000484
_08168B48:
	ldr r1, _08168BB4 @ =0x000006AC
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bhi _08168B5C
	b _08168C5C
_08168B5C:
	ldr r0, _08168BB8 @ =0x000006A4
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r6, #8]
	movs r0, #0xd5
	lsls r0, r0, #3
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r6, #0xc]
	ldr r2, _08168BBC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08168BC0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _08168BC4 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r2, r6, r1
	movs r1, #0x3f
	ands r0, r1
	ldrb r2, [r2]
	adds r3, r0, r2
	movs r1, #0xff
	add r7, sp, #4
	ands r3, r1
	ldr r2, _08168BC8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #9
	mov sl, r7
	cmp r0, #0
	blt _08168BCC
	asrs r1, r0, #0xc
	b _08168BD2
	.align 2, 0
_08168BB4: .4byte 0x000006AC
_08168BB8: .4byte 0x000006A4
_08168BBC: .4byte 0x030046B8
_08168BC0: .4byte 0x000003FF
_08168BC4: .4byte 0x0203B400
_08168BC8: .4byte 0x085B0A08
_08168BCC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08168BD2:
	movs r0, #0
	strh r1, [r7]
	strh r0, [r7, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _08168BEE
	asrs r0, r0, #0xc
	b _08168BF4
_08168BEE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08168BF4:
	movs r4, #0
	movs r5, #0
	strh r0, [r7, #4]
	add r1, sp, #4
	ldrh r0, [r6, #8]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	mov r1, sl
	ldrh r0, [r1, #2]
	mov r2, sb
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	mov r3, sl
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	adds r0, r6, #0
	mov r1, sl
	bl FUN_081684b4
	adds r0, r6, #0
	mov r1, sb
	mov r2, sl
	bl FUN_0816869c
	adds r0, r6, #0
	bl FUN_081687d8
	movs r1, #0xd6
	lsls r1, r1, #3
	add r1, r8
	ldrh r1, [r1]
	lsls r1, r0
	ldr r0, _08168C50 @ =0x000006BE
	add r0, r8
	strh r1, [r0]
	ldr r0, _08168C54 @ =0x000006AC
	add r0, r8
	strb r4, [r0]
	ldr r2, _08168C58 @ =0x00000484
	adds r0, r6, r2
	str r5, [r0]
	b _08168D14
	.align 2, 0
_08168C50: .4byte 0x000006BE
_08168C54: .4byte 0x000006AC
_08168C58: .4byte 0x00000484
_08168C5C:
	ldrb r0, [r1]
	subs r0, #1
	lsls r0, r0, #3
	add r0, r8
	ldr r3, _08168C9C @ =0x00000664
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r6, #8]
	ldrb r0, [r1]
	subs r0, #1
	lsls r0, r0, #3
	add r0, r8
	movs r4, #0xcd
	lsls r4, r4, #3
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r6, #0xc]
_08168C7E:
	ldr r0, _08168CA0 @ =0x00000484
	adds r1, r6, r0
	ldr r0, [r1]
	cmp r0, #0x13
	bgt _08168C8C
	adds r0, #1
	str r0, [r1]
_08168C8C:
	ldr r1, _08168CA4 @ =0x000006AE
	add r1, r8
	ldrb r0, [r1]
	adds r3, r0, #0
	cmp r3, #0
	beq _08168CA8
	subs r0, #1
	b _08168D12
	.align 2, 0
_08168C9C: .4byte 0x00000664
_08168CA0: .4byte 0x00000484
_08168CA4: .4byte 0x000006AE
_08168CA8:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r0, _08168CE8 @ =0x0000FFFE
	cmp r1, r0
	bhi _08168D14
	movs r0, #0xcc
	lsls r0, r0, #3
	add r0, r8
	ldrb r2, [r0]
	cmp r2, #0
	beq _08168CF0
	movs r1, #2
	movs r2, #1
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	strb r3, [r0]
	adds r4, #1
	adds r0, r6, r4
	strb r1, [r0]
	ldr r1, _08168CEC @ =0x0000046A
	adds r0, r6, r1
	strb r2, [r0]
	adds r4, #0x1b
	adds r0, r6, r4
	str r3, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r2, [r0]
	b _08168D14
	.align 2, 0
_08168CE8: .4byte 0x0000FFFE
_08168CEC: .4byte 0x0000046A
_08168CF0:
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r6, r3
	strb r2, [r0]
	ldr r4, _08168D24 @ =0x00000469
	adds r0, r6, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r6, r3
	strb r1, [r0]
	adds r4, #0x1b
	adds r0, r6, r4
	str r2, [r0]
	ldr r0, _08168D28 @ =0x0000046C
	adds r1, r6, r0
	movs r0, #1
_08168D12:
	strb r0, [r1]
_08168D14:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08168D24: .4byte 0x00000469
_08168D28: .4byte 0x0000046C

	thumb_func_start FUN_08168d2c
FUN_08168d2c: @ 0x08168D2C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _08168D4C @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08168D50
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08168D52
	.align 2, 0
_08168D4C: .4byte 0x0000046C
_08168D50:
	movs r0, #0
_08168D52:
	cmp r0, #0
	beq _08168D8E
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrb r0, [r0]
	movs r3, #0
	strb r0, [r4, #5]
	movs r6, #0xb4
	lsls r6, r6, #3
	adds r0, r4, r6
	ldr r2, [r0]
	movs r1, #1
	ldr r6, _08168DD8 @ =0x0000046D
	adds r0, r4, r6
	strb r1, [r0]
	subs r6, #2
	adds r0, r4, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r4, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r3, [r0]
_08168D8E:
	ldr r3, _08168DDC @ =0x00000484
	adds r1, r4, r3
	ldr r0, [r1]
	cmp r0, #0x1e
	ble _08168DE4
	movs r2, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	movs r1, #0
	strb r1, [r0]
	subs r3, #0x1b
	adds r0, r4, r3
	strb r2, [r0]
	adds r6, #2
	adds r0, r4, r6
	strb r1, [r0]
	ldr r2, _08168DDC @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	movs r2, #8
	movs r6, #0xcb
	lsls r6, r6, #3
	adds r1, r5, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08168DE0 @ =0x000006AE
	adds r1, r5, r0
	movs r0, #0x3c
	strb r0, [r1]
	b _08168DE8
	.align 2, 0
_08168DD8: .4byte 0x0000046D
_08168DDC: .4byte 0x00000484
_08168DE0: .4byte 0x000006AE
_08168DE4:
	adds r0, #1
	str r0, [r1]
_08168DE8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08168df0
FUN_08168df0: @ 0x08168DF0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08168E08 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08168E0C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08168E0E
	.align 2, 0
_08168E08: .4byte 0x0000046C
_08168E0C:
	movs r0, #0
_08168E0E:
	cmp r0, #0
	beq _08168E46
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r3, #0
	strb r0, [r5, #5]
	ldr r4, _08168E94 @ =FUN_08167294
	movs r2, #0x24
	ldr r0, _08168E98 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08168E9C @ =0x0000046B
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r3, [r0]
_08168E46:
	ldr r1, _08168EA0 @ =0x00000484
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0x28
	ble _08168E82
	ldr r2, _08168EA4 @ =0x0000046E
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08168E82
	movs r2, #2
	movs r3, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	movs r1, #0
	strb r1, [r0]
	adds r4, #1
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08168EA8 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r1, [r0]
	ldr r0, _08168EAC @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_08168E82:
	ldr r2, _08168EA0 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08168E94: .4byte FUN_08167294
_08168E98: .4byte 0x0000046D
_08168E9C: .4byte 0x0000046B
_08168EA0: .4byte 0x00000484
_08168EA4: .4byte 0x0000046E
_08168EA8: .4byte 0x0000046A
_08168EAC: .4byte 0x0000046C

	thumb_func_start FUN_08168eb0
FUN_08168eb0: @ 0x08168EB0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08168ED0 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08168ED4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08168ED6
	.align 2, 0
_08168ED0: .4byte 0x0000046C
_08168ED4:
	movs r0, #0
_08168ED6:
	cmp r0, #0
	beq _08168F46
	movs r4, #0xfe
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrb r0, [r0]
	movs r3, #0
	strb r0, [r5, #5]
	ldr r4, _08168FAC @ =FUN_081672b8
	movs r2, #0x25
	ldr r0, _08168FB0 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08168FB4 @ =0x0000046B
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r3, [r0]
	subs r1, #0xaf
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r0, _08168FB8 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2, #0xc]
	str r1, [r2, #0x10]
	ldr r2, _08168FBC @ =0x000006AD
	adds r0, r6, r2
	ldrb r1, [r0]
	movs r4, #0xcc
	lsls r4, r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0xf2
	lsls r0, r0, #2
	bl PlaySound_082406e0
_08168F46:
	movs r4, #0x18
	ldr r2, _08168FC0 @ =0x000004A4
	adds r0, r5, r2
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
	bge _08168F6A
	rsbs r2, r2, #0
_08168F6A:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _08168F7C
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _08168F78
	rsbs r2, r2, #0
_08168F78:
	cmp r2, #0x20
	ble _08168FFC
_08168F7C:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _08168F88
	cmp r1, #0
	beq _08168FFC
_08168F88:
	asrs r1, r1, #0x10
	bl FUN_0823785c
	strb r0, [r5, #5]
	ldr r2, _08168FC4 @ =0x085B0A08
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08168FC8
	asrs r1, r0, #0xc
	b _08168FCE
	.align 2, 0
_08168FAC: .4byte FUN_081672b8
_08168FB0: .4byte 0x0000046D
_08168FB4: .4byte 0x0000046B
_08168FB8: .4byte 0x03002BE0
_08168FBC: .4byte 0x000006AD
_08168FC0: .4byte 0x000004A4
_08168FC4: .4byte 0x085B0A08
_08168FC8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08168FCE:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _08168FEC @ =0x085B0A08
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _08168FF0
	asrs r1, r0, #0xc
	b _08168FF6
	.align 2, 0
_08168FEC: .4byte 0x085B0A08
_08168FF0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08168FF6:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_08168FFC:
	ldr r4, _08169030 @ =0x0000046B
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0816903C
	movs r2, #2
	movs r3, #4
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	subs r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08169034 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r1, [r0]
	ldr r0, _08169038 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _08169046
	.align 2, 0
_08169030: .4byte 0x0000046B
_08169034: .4byte 0x0000046A
_08169038: .4byte 0x0000046C
_0816903C:
	ldr r2, _0816904C @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08169046:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0816904C: .4byte 0x00000484

	thumb_func_start FUN_08169050
FUN_08169050: @ 0x08169050
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08169068 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0816906C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0816906E
	.align 2, 0
_08169068: .4byte 0x0000046C
_0816906C:
	movs r0, #0
_0816906E:
	cmp r0, #0
	beq _08169128
	ldr r4, _081690E4 @ =FUN_08167304
	movs r3, #0x26
	ldr r2, _081690E8 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081690EC @ =0x0000046B
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
	ldr r2, _081690F0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081690F4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081690F8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r2, r5, r1
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x71
	ldrb r2, [r2]
	adds r3, r0, r2
	movs r1, #0xff
	ands r3, r1
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r4, r5, r2
	ldr r2, _081690FC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08169100
	asrs r1, r0, #0xc
	b _08169106
	.align 2, 0
_081690E4: .4byte FUN_08167304
_081690E8: .4byte 0x0000046D
_081690EC: .4byte 0x0000046B
_081690F0: .4byte 0x030046B8
_081690F4: .4byte 0x000003FF
_081690F8: .4byte 0x0203B400
_081690FC: .4byte 0x085B0A08
_08169100:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08169106:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _08169120
	asrs r0, r0, #0xc
	b _08169126
_08169120:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08169126:
	strh r0, [r4, #4]
_08169128:
	ldr r0, _0816916C @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	cmp r0, #0x1e
	ble _0816917C
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, _08169170 @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r4, #0
	strh r1, [r2]
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _08169174 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r2, #0x1b
	adds r0, r5, r2
	str r4, [r0]
	ldr r0, _08169178 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _08169180
	.align 2, 0
_0816916C: .4byte 0x00000484
_08169170: .4byte 0xFFFFFEFF
_08169174: .4byte 0x0000046A
_08169178: .4byte 0x0000046C
_0816917C:
	adds r0, #1
	str r0, [r1]
_08169180:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08169188
FUN_08169188: @ 0x08169188
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _081691B0 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081691B4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081691B6
	.align 2, 0
_081691B0: .4byte 0x0000046C
_081691B4:
	movs r0, #0
_081691B6:
	add r7, sp, #4
	movs r3, #8
	adds r3, r3, r6
	mov r8, r3
	cmp r0, #0
	bne _081691C4
	b _0816931E
_081691C4:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r6, r5
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _0816927C @ =0x0000046D
	adds r0, r6, r2
	movs r2, #0
	strb r1, [r0]
	ldr r5, _08169280 @ =0x0000046B
	adds r0, r6, r5
	strb r2, [r0]
	adds r5, #0xe8
	adds r0, r6, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r1, #0
	strh r2, [r0]
	ldr r5, _08169284 @ =0x000006AC
	adds r0, r4, r5
	strb r1, [r0]
	ldr r1, _08169288 @ =0x000006C4
	adds r0, r4, r1
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r7]
	ldrh r0, [r2, #2]
	mov r3, r8
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r5, #0
	ldrsh r0, [r7, r5]
	movs r2, #4
	ldrsh r1, [r7, r2]
	bl FUN_0823785c
	movs r5, #0xfe
	lsls r5, r5, #1
	adds r3, r6, r5
	strb r0, [r3]
	ldr r2, _0816928C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08169290 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08169294 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	ldrb r3, [r3]
	adds r3, r0, r3
	movs r2, #0xff
	ldr r5, _08169298 @ =0x000006C2
	adds r0, r4, r5
	add r5, sp, #0xc
	ands r3, r2
	ldrh r0, [r0]
	mov ip, r0
	ldr r1, _0816929C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	adds r2, r5, #0
	cmp r0, #0
	blt _081692A0
	asrs r1, r0, #0xc
	b _081692A6
	.align 2, 0
_0816927C: .4byte 0x0000046D
_08169280: .4byte 0x0000046B
_08169284: .4byte 0x000006AC
_08169288: .4byte 0x000006C4
_0816928C: .4byte 0x030046B8
_08169290: .4byte 0x000003FF
_08169294: .4byte 0x0203B400
_08169298: .4byte 0x000006C2
_0816929C: .4byte 0x085B0A08
_081692A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081692A6:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _081692C4 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081692C8
	asrs r0, r0, #0xc
	b _081692CE
	.align 2, 0
_081692C4: .4byte 0x085B0A08
_081692C8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081692CE:
	movs r3, #0
	mov sb, r3
	strh r0, [r5, #4]
	ldr r5, _081693CC @ =0x000006BE
	adds r1, r4, r5
	movs r0, #0xa0
	lsls r0, r0, #3
	strh r0, [r1]
	add r1, sp, #0xc
	ldrh r0, [r6, #8]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r2, #2]
	mov r5, r8
	ldrh r1, [r5, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r0, r6, #0
	adds r1, r2, #0
	str r2, [sp, #0x1c]
	bl FUN_081684b4
	adds r0, r6, #0
	mov r1, r8
	ldr r2, [sp, #0x1c]
	bl FUN_0816869c
	ldr r2, _081693D0 @ =0x00000704
	adds r1, r4, r2
	mov r3, sb
	str r3, [sp]
	mov r0, sp
	ldr r2, _081693D4 @ =0x05000002
	bl CpuSet
_0816931E:
	ldr r5, _081693D8 @ =0x000006AC
	adds r0, r4, r5
	ldrb r1, [r0]
	add r5, sp, #0x14
	lsls r1, r1, #3
	adds r1, r1, r4
	ldr r0, _081693DC @ =0x00000664
	adds r1, r1, r0
	ldrh r0, [r1]
	ldrh r3, [r6, #8]
	subs r0, r0, r3
	strh r0, [r5]
	ldrh r2, [r1, #2]
	mov ip, r2
	mov r0, r8
	ldrh r0, [r0, #2]
	mov sb, r0
	mov r2, ip
	mov r0, sb
	subs r2, r2, r0
	strh r2, [r5, #2]
	ldrh r0, [r1, #4]
	mov r2, r8
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	ldr r1, _081693E0 @ =0x000006C4
	adds r0, r4, r1
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #8
	ldrh r0, [r0, #8]
	subs r0, r0, r3
	add r3, sp, #4
	strh r0, [r3]
	ldrh r0, [r2, #2]
	mov ip, r0
	mov r1, r8
	ldrh r1, [r1, #2]
	mov sb, r1
	mov r0, ip
	mov r1, sb
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldrh r0, [r2, #4]
	mov r2, r8
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r2, #4
	ldrsh r1, [r7, r2]
	bl FUN_0823785c
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r1, r6, r3
	strb r0, [r1]
	strb r0, [r6, #5]
	ldr r0, _081693CC @ =0x000006BE
	adds r2, r4, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	ble _0816946C
	movs r3, #0
	ldrsh r0, [r5, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #4
	ldrsh r0, [r5, r3]
	adds r5, r0, #0
	muls r5, r0, r5
	adds r0, r5, #0
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r1, r0
	ble _0816946C
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	blt _081693E4
	asrs r1, r0, #5
	b _081693EA
	.align 2, 0
_081693CC: .4byte 0x000006BE
_081693D0: .4byte 0x00000704
_081693D4: .4byte 0x05000002
_081693D8: .4byte 0x000006AC
_081693DC: .4byte 0x00000664
_081693E0: .4byte 0x000006C4
_081693E4:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r1, r0, #0
_081693EA:
	adds r5, r1, #0
	cmp r5, #1
	bge _081693F2
	movs r5, #1
_081693F2:
	ldr r2, _08169458 @ =0x000006AC
	adds r7, r4, r2
	ldrb r0, [r7]
	lsls r0, r0, #3
	adds r0, r4, r0
	ldr r3, _0816945C @ =0x00000664
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #8
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	adds r1, r5, #0
	bl Div
	ldrh r1, [r6, #0x10]
	adds r1, r1, r0
	strh r1, [r6, #0x10]
	ldrb r0, [r7]
	lsls r0, r0, #3
	adds r0, r4, r0
	movs r3, #0xcd
	lsls r3, r3, #3
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0xc
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	adds r1, r5, #0
	bl Div
	ldrh r1, [r6, #0x14]
	adds r1, r1, r0
	strh r1, [r6, #0x14]
	ldr r3, _08169460 @ =0x00000704
	adds r2, r4, r3
	ldr r0, [r6, #0x10]
	ldr r1, [r6, #0x14]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r5, _08169464 @ =0x000006BE
	adds r2, r4, r5
	ldr r1, _08169468 @ =0x00000484
	adds r0, r6, r1
	ldr r1, [r0]
	ldrh r0, [r2]
	subs r0, r0, r1
	strh r0, [r2]
	b _081695DE
	.align 2, 0
_08169458: .4byte 0x000006AC
_0816945C: .4byte 0x00000664
_08169460: .4byte 0x00000704
_08169464: .4byte 0x000006BE
_08169468: .4byte 0x00000484
_0816946C:
	ldr r2, _08169510 @ =0x000006AC
	adds r1, r4, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bhi _08169480
	b _081695BC
_08169480:
	ldr r3, _08169514 @ =0x000006A4
	adds r0, r4, r3
	ldrh r1, [r0]
	strh r1, [r6, #8]
	movs r5, #0xd5
	lsls r5, r5, #3
	adds r0, r4, r5
	ldrh r0, [r0]
	strh r0, [r6, #0xc]
	adds r2, #0x18
	adds r0, r4, r2
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #8
	ldrh r0, [r0, #8]
	subs r0, r0, r1
	add r3, sp, #4
	strh r0, [r3]
	ldrh r0, [r2, #2]
	mov r5, r8
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r2, #4
	ldrsh r1, [r7, r2]
	bl FUN_0823785c
	movs r5, #0xfe
	lsls r5, r5, #1
	adds r3, r6, r5
	strb r0, [r3]
	ldr r2, _08169518 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0816951C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08169520 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	ldrb r3, [r3]
	adds r3, r0, r3
	movs r2, #0xff
	ldr r5, _08169524 @ =0x000006C2
	adds r0, r4, r5
	add r7, sp, #0xc
	ands r3, r2
	ldrh r5, [r0]
	ldr r1, _08169528 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	adds r2, r7, #0
	cmp r0, #0
	blt _0816952C
	asrs r1, r0, #0xc
	b _08169532
	.align 2, 0
_08169510: .4byte 0x000006AC
_08169514: .4byte 0x000006A4
_08169518: .4byte 0x030046B8
_0816951C: .4byte 0x000003FF
_08169520: .4byte 0x0203B400
_08169524: .4byte 0x000006C2
_08169528: .4byte 0x085B0A08
_0816952C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08169532:
	movs r0, #0
	strh r1, [r7]
	strh r0, [r7, #2]
	ldr r1, _0816954C @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _08169550
	asrs r0, r0, #0xc
	b _08169556
	.align 2, 0
_0816954C: .4byte 0x085B0A08
_08169550:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08169556:
	movs r5, #0
	mov sb, r5
	movs r5, #0
	strh r0, [r7, #4]
	add r1, sp, #0xc
	ldrh r0, [r6, #8]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r2, #2]
	mov r3, r8
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r0, r6, #0
	adds r1, r2, #0
	str r2, [sp, #0x1c]
	bl FUN_081684b4
	adds r0, r6, #0
	mov r1, r8
	ldr r2, [sp, #0x1c]
	bl FUN_0816869c
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r3, _081695B0 @ =0x000006BE
	adds r1, r4, r3
	strh r0, [r1]
	ldr r1, _081695B4 @ =0x000006AC
	adds r0, r4, r1
	mov r2, sb
	strb r2, [r0]
	ldr r3, _081695B8 @ =0x00000484
	adds r0, r6, r3
	str r5, [r0]
	b _081695EC
	.align 2, 0
_081695B0: .4byte 0x000006BE
_081695B4: .4byte 0x000006AC
_081695B8: .4byte 0x00000484
_081695BC:
	ldrb r0, [r1]
	subs r0, #1
	lsls r0, r0, #3
	adds r0, r4, r0
	ldr r5, _081695FC @ =0x00000664
	adds r0, r0, r5
	ldrh r0, [r0]
	strh r0, [r6, #8]
	ldrb r0, [r1]
	subs r0, #1
	lsls r0, r0, #3
	adds r0, r4, r0
	movs r1, #0xcd
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r6, #0xc]
_081695DE:
	ldr r2, _08169600 @ =0x00000484
	adds r1, r6, r2
	ldr r0, [r1]
	cmp r0, #0x13
	bgt _081695EC
	adds r0, #1
	str r0, [r1]
_081695EC:
	add sp, #0x20
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081695FC: .4byte 0x00000664
_08169600: .4byte 0x00000484

	thumb_func_start FUN_08169604
FUN_08169604: @ 0x08169604
	ldr r1, _08169610 @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _08169614 @ =0x085ADA38
	str r1, [r0]
	bx lr
	.align 2, 0
_08169610: .4byte 0x0000063C
_08169614: .4byte 0x085ADA38

	thumb_func_start FUN_08169618
FUN_08169618: @ 0x08169618
	ldr r1, _08169624 @ =0x0000064C
	adds r0, r0, r1
	ldr r1, _08169628 @ =0x085ADA4C
	str r1, [r0]
	bx lr
	.align 2, 0
_08169624: .4byte 0x0000064C
_08169628: .4byte 0x085ADA4C

	thumb_func_start FUN_0816962c
FUN_0816962c: @ 0x0816962C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08168814
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _08169664 @ =0x0000062C
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
	bl FUN_08168820
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08169664: .4byte 0x0000062C

	thumb_func_start FUN_08169668
FUN_08169668: @ 0x08169668
	push {lr}
	movs r1, #0xec
	lsls r1, r1, #1
	adds r2, r0, r1
	ldr r1, _08169684 @ =0x03002BE0
	ldr r1, [r1]
	adds r1, #0x24
	str r1, [r2]
	bl FUN_080f06b0
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08169684: .4byte 0x03002BE0

	thumb_func_start FUN_08169688
FUN_08169688: @ 0x08169688
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _081696A0 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081696A4
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _081696AC
	.align 2, 0
_081696A0: .4byte 0x0000025D
_081696A4:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_081696AC:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _081696C8 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081696CC
	movs r0, #1
	b _081696CE
	.align 2, 0
_081696C8: .4byte 0x00000474
_081696CC:
	movs r0, #0
_081696CE:
	cmp r0, #0
	beq _081696DA
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_081696DA:
	ldr r1, _08169734 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _081696F2
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_081696F2:
	ldr r0, _08169738 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _0816970A
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_0816970A:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08169722
	adds r0, r4, #0
	bl FUN_08002a58
_08169722:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0816973C
	movs r0, #1
	b _0816973E
	.align 2, 0
_08169734: .4byte 0x0000044C
_08169738: .4byte 0x0000044D
_0816973C:
	movs r0, #0
_0816973E:
	cmp r0, #0
	beq _0816974A
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_0816974A:
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

