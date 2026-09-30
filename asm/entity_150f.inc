	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081e0c14
FUN_081e0c14: @ 0x081E0C14
	ldr r1, _081E0C1C @ =0x030001B0
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081E0C1C: .4byte 0x030001B0

	thumb_func_start FUN_081e0c20
FUN_081e0c20: @ 0x081E0C20
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldrh r0, [r7, #0x10]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r7, #0x14]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _081E0C4E
	cmp r1, #0
	blt _081E0C4E
	ldr r0, _081E0C54 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081E0C4E
	ldr r0, _081E0C58 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081E0C5C
_081E0C4E:
	movs r6, #0
	b _081E0C6A
	.align 2, 0
_081E0C54: .4byte 0x030046A8
_081E0C58: .4byte 0x030046AC
_081E0C5C:
	ldr r0, _081E0C7C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r4
_081E0C6A:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0C80
	adds r0, #4
	b _081E0C8C
	.align 2, 0
_081E0C7C: .4byte 0x030046A4
_081E0C80:
	ldr r0, _081E0CA8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E0C8C:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _081E0CE4
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0CCC
	adds r0, #4
	b _081E0CD8
	.align 2, 0
_081E0CA8: .4byte 0x030046A4
_081E0CAC:
	ldr r4, _081E0CC8 @ =0x030046A4
	ldr r0, [r4]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	subs r6, r6, r1
	adds r0, r6, #0
	bl Mod
	lsls r0, r0, #8
	strh r0, [r7, #0x10]
	ldr r0, [r4]
	b _081E0E2A
	.align 2, 0
_081E0CC8: .4byte 0x030046A4
_081E0CCC:
	ldr r0, _081E0CFC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E0CD8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081E0CE4
	b _081E0EB2
_081E0CE4:
	movs r0, #0
	mov sb, r0
	ldr r1, _081E0CFC @ =0x030046A4
	mov r8, r1
_081E0CEC:
	mov r2, sb
	cmp r2, #1
	beq _081E0D46
	cmp r2, #1
	bgt _081E0D00
	cmp r2, #0
	beq _081E0D0E
	b _081E0EA6
	.align 2, 0
_081E0CFC: .4byte 0x030046A4
_081E0D00:
	mov r0, sb
	cmp r0, #2
	beq _081E0DC2
	cmp r0, #3
	bne _081E0D0C
	b _081E0E3C
_081E0D0C:
	b _081E0EA6
_081E0D0E:
	adds r4, r6, #1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0D20
	adds r0, #4
	b _081E0D2C
_081E0D20:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0D2C:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _081E0D38
	b _081E0EA6
_081E0D38:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	bne _081E0DF6
	b _081E0DFA
_081E0D46:
	ldr r5, _081E0D64 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0D68
	adds r0, #4
	b _081E0D72
	.align 2, 0
_081E0D64: .4byte 0x030046A4
_081E0D68:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0D72:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _081E0D7E
	b _081E0EA6
_081E0D7E:
	ldr r5, _081E0D9C @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0DA0
	adds r0, #4
	b _081E0DAA
	.align 2, 0
_081E0D9C: .4byte 0x030046A4
_081E0DA0:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0DAA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081E0EA6
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r6, r6, r1
	b _081E0E1C
_081E0DC2:
	subs r4, r6, #1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0DD4
	adds r0, #4
	b _081E0DE0
_081E0DD4:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0DE0:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _081E0EA6
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0DFA
_081E0DF6:
	adds r0, #4
	b _081E0E06
_081E0DFA:
	mov r2, r8
	ldr r0, [r2]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0E06:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081E0EA6
	adds r6, r4, #0
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
_081E0E1C:
	adds r0, r6, #0
	bl Mod
	lsls r0, r0, #8
	strh r0, [r7, #0x10]
	mov r1, r8
	ldr r0, [r1]
_081E0E2A:
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Div
	lsls r0, r0, #8
	strh r0, [r7, #0x14]
	b _081E0EB2
_081E0E3C:
	ldr r5, _081E0E58 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0E5C
	adds r0, #4
	b _081E0E66
	.align 2, 0
_081E0E58: .4byte 0x030046A4
_081E0E5C:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0E66:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	bne _081E0EA6
	ldr r5, _081E0E8C @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0E90
	adds r0, #4
	b _081E0E9A
	.align 2, 0
_081E0E8C: .4byte 0x030046A4
_081E0E90:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0E9A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081E0EA6
	b _081E0CAC
_081E0EA6:
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #3
	bgt _081E0EB2
	b _081E0CEC
_081E0EB2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e0ec0
FUN_081e0ec0: @ 0x081E0EC0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	ldrh r0, [r0, #0x10]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	mov r1, r8
	ldrh r0, [r1, #0x14]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _081E0EF2
	cmp r1, #0
	blt _081E0EF2
	ldr r0, _081E0EF8 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081E0EF2
	ldr r0, _081E0EFC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081E0F00
_081E0EF2:
	movs r6, #0
	b _081E0F0E
	.align 2, 0
_081E0EF8: .4byte 0x030046A8
_081E0EFC: .4byte 0x030046AC
_081E0F00:
	ldr r0, _081E0F34 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r4
_081E0F0E:
	ldr r0, _081E0F38 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _081E0F3C @ =0x00000934
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _081E0F22
	b _081E10AA
_081E0F22:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0F60
	adds r0, #4
	b _081E0F6C
	.align 2, 0
_081E0F34: .4byte 0x030046A4
_081E0F38: .4byte 0x030046A0
_081E0F3C: .4byte 0x00000934
_081E0F40:
	ldr r4, _081E0F5C @ =0x030046A4
	ldr r0, [r4]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	subs r6, r6, r1
	adds r0, r6, #0
	bl Mod
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #0x10]
	ldr r0, [r4]
	b _081E1056
	.align 2, 0
_081E0F5C: .4byte 0x030046A4
_081E0F60:
	ldr r0, _081E0F90 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E0F6C:
	ldrh r0, [r0, #2]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	bne _081E0F78
	b _081E10AA
_081E0F78:
	movs r7, #0
	ldr r2, _081E0F90 @ =0x030046A4
	mov sb, r2
	mov sl, r1
_081E0F80:
	cmp r7, #1
	beq _081E0FCE
	cmp r7, #1
	bgt _081E0F94
	cmp r7, #0
	beq _081E0F9E
	b _081E10A2
	.align 2, 0
_081E0F90: .4byte 0x030046A4
_081E0F94:
	cmp r7, #2
	beq _081E1012
	cmp r7, #3
	beq _081E106A
	b _081E10A2
_081E0F9E:
	adds r4, r6, #1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0FB0
	adds r0, #4
	b _081E0FBC
_081E0FB0:
	mov r1, sb
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0FBC:
	ldrh r0, [r0, #2]
	mov r2, sl
	ands r0, r2
	cmp r0, #0
	bne _081E10A2
	adds r6, r4, #0
	mov r1, sb
	ldr r0, [r1]
	b _081E1040
_081E0FCE:
	ldr r5, _081E0FEC @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E0FF0
	adds r0, #4
	b _081E0FFA
	.align 2, 0
_081E0FEC: .4byte 0x030046A4
_081E0FF0:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E0FFA:
	ldrh r0, [r0, #2]
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	bne _081E10A2
	mov r2, sb
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r6, r6, r1
	b _081E1046
_081E1012:
	subs r4, r6, #1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E1024
	adds r0, #4
	b _081E1030
_081E1024:
	mov r2, sb
	ldr r0, [r2]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E1030:
	ldrh r0, [r0, #2]
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	bne _081E10A2
	adds r6, r4, #0
	mov r2, sb
	ldr r0, [r2]
_081E1040:
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
_081E1046:
	adds r0, r6, #0
	bl Mod
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #0x10]
	mov r2, sb
	ldr r0, [r2]
_081E1056:
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Div
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #0x14]
	b _081E10AA
_081E106A:
	ldr r5, _081E1088 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r6, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E108C
	adds r0, #4
	b _081E1096
	.align 2, 0
_081E1088: .4byte 0x030046A4
_081E108C:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081E1096:
	ldrh r0, [r0, #2]
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	bne _081E10A2
	b _081E0F40
_081E10A2:
	adds r7, #1
	cmp r7, #3
	bgt _081E10AA
	b _081E0F80
_081E10AA:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e10b8
FUN_081e10b8: @ 0x081E10B8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [r4, #0x10]
	str r1, [r4, #0x14]
	adds r0, r4, #0
	bl FUN_081e0ec0
	adds r0, r4, #0
	bl FUN_081e0c20
	ldrh r1, [r4, #0x10]
	ldr r0, _081E1110 @ =0xFFFFFF00
	adds r5, r0, #0
	ands r5, r1
	strh r5, [r4, #0x10]
	ldrh r1, [r4, #0x14]
	ands r0, r1
	strh r0, [r4, #0x14]
	movs r0, #1
	ands r0, r6
	cmp r0, #0
	beq _081E1120
	ldr r3, _081E1114 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _081E1118 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _081E111C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r5, #0
	adds r1, #0x80
	movs r2, #0x7f
	ands r0, r2
	adds r1, r1, r0
	strh r1, [r4, #0x10]
	adds r2, r3, #0
	b _081E113C
	.align 2, 0
_081E1110: .4byte 0xFFFFFF00
_081E1114: .4byte 0x030046B8
_081E1118: .4byte 0x000003FF
_081E111C: .4byte 0x0203B400
_081E1120:
	ldr r2, _081E1158 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081E115C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081E1160 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, r5, r0
	strh r0, [r4, #0x10]
_081E113C:
	cmp r6, #2
	bgt _081E1164
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081E115C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081E1160 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	lsls r0, r6, #2
	adds r0, r0, r6
	b _081E117C
	.align 2, 0
_081E1158: .4byte 0x030046B8
_081E115C: .4byte 0x000003FF
_081E1160: .4byte 0x0203B400
_081E1164:
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081E11B8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081E11BC @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	subs r1, r6, #3
	lsls r0, r1, #2
	adds r0, r0, r1
_081E117C:
	lsls r0, r0, #4
	movs r1, #0x3f
	ands r2, r1
	adds r0, r0, r2
	ldrh r1, [r4, #0x14]
	adds r0, r0, r1
	strh r0, [r4, #0x14]
	adds r6, r4, #0
	adds r6, #0x10
	ldrh r0, [r4, #0x10]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081E11B2
	cmp r1, #0
	blt _081E11B2
	ldr r0, _081E11C0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081E11B2
	ldr r0, _081E11C4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081E11C8
_081E11B2:
	movs r5, #0
	b _081E11D6
	.align 2, 0
_081E11B8: .4byte 0x000003FF
_081E11BC: .4byte 0x0203B400
_081E11C0: .4byte 0x030046A8
_081E11C4: .4byte 0x030046AC
_081E11C8:
	ldr r0, _081E11E8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081E11D6:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E11EC
	adds r0, #4
	b _081E11F8
	.align 2, 0
_081E11E8: .4byte 0x030046A4
_081E11EC:
	ldr r0, _081E120C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E11F8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081E1210
	cmp r2, #2
	beq _081E1214
	b _081E1218
	.align 2, 0
_081E120C: .4byte 0x030046A4
_081E1210:
	ldrb r0, [r6, #4]
	b _081E1216
_081E1214:
	ldrb r0, [r6]
_081E1216:
	subs r1, r1, r0
_081E1218:
	strh r1, [r4, #0x12]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e1220
FUN_081e1220: @ 0x081E1220
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	movs r0, #0
	strb r2, [r5]
	strb r0, [r5, #1]
	strb r0, [r5, #2]
	strb r0, [r5, #3]
	strh r0, [r5, #6]
	str r0, [r5, #0x20]
	adds r0, r5, #0
	adds r0, #0x24
	adds r3, #0x20
	adds r1, r3, #0
	movs r2, #1
	bl AuxSprite_Add
	adds r4, r5, #0
	adds r4, #0x50
	adds r1, r5, #0
	adds r1, #0x40
	adds r0, r4, #0
	movs r2, #0
	bl ParticleShadow_Init
	adds r0, r4, #0
	bl ParticleShadow_Hide
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e1260
FUN_081e1260: @ 0x081E1260
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x24
	bl AuxSprite_Remove
	adds r4, #0x50
	adds r0, r4, #0
	bl ParticleShadow_Remove
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e127c
FUN_081e127c: @ 0x081E127C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r5, #0
	strb r5, [r4, #1]
	strb r5, [r4, #2]
	strb r5, [r4, #3]
	ldr r0, [r4, #0x24]
	movs r6, #1
	orrs r0, r6
	str r0, [r4, #0x24]
	adds r0, r4, #0
	adds r0, #0x50
	bl ParticleShadow_Hide
	str r5, [r4, #0x20]
	strh r5, [r4, #6]
	strb r6, [r4, #4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e12a4
FUN_081e12a4: @ 0x081E12A4
	push {lr}
	adds r2, r0, #0
	adds r2, #0x6c
	movs r3, #0
_081E12AC:
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, r1
	bne _081E12B8
	adds r0, r2, #0
	b _081E12C2
_081E12B8:
	adds r3, #1
	adds r2, #0x90
	cmp r3, #4
	ble _081E12AC
	movs r0, #0
_081E12C2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e12c8
FUN_081e12c8: @ 0x081E12C8
	push {r4, r5, lr}
	sub sp, #0x18
	adds r5, r0, #0
	adds r3, r1, #0
	ldrh r0, [r5, #0x1c]
	cmp r0, #0
	beq _081E12F4
	movs r1, #0
	ldrsb r1, [r3, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _081E12F4
	adds r4, r1, #0
	movs r2, #0xc
	ldr r1, _081E12FC @ =0x03002BC0
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _081E1300
_081E12F4:
	movs r0, #1
	rsbs r0, r0, #0
	b _081E1338
	.align 2, 0
_081E12FC: .4byte 0x03002BC0
_081E1300:
	str r4, [sp]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #4]
	adds r0, r3, #0
	adds r0, #0x42
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #8]
	adds r0, r3, #0
	adds r0, #0x44
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #0xc]
	ldr r1, _081E1340 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	str r0, [sp, #0x10]
	add r1, sp, #0x10
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r5, #0x1c]
	bl VM_ExecByID
_081E1338:
	add sp, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081E1340: .4byte 0xFFFF0000

	thumb_func_start FUN_081e1344
FUN_081e1344: @ 0x081E1344
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov r8, r0
	adds r4, r1, #0
	ldr r5, [r0, #0x18]
	movs r0, #3
	ands r5, r0
	mov sl, r5
	adds r0, r5, #4
	cmp r5, r0
	bge _081E1426
	movs r0, #0x40
	adds r0, r0, r4
	mov sb, r0
	movs r1, #0x18
	adds r1, r1, r4
	mov ip, r1
_081E136E:
	movs r7, #3
	ands r7, r5
	lsls r2, r7, #2
	mov r0, r8
	adds r0, #0x5c
	adds r0, r0, r2
	ldr r3, [r0]
	cmp r3, #0
	beq _081E141C
	movs r0, #0xc
	ldr r1, _081E13EC @ =0x03002BC0
	adds r1, r2, r1
	ldr r1, [r1]
	ands r1, r0
	cmp r1, #0
	bne _081E141C
	movs r1, #0x80
	lsls r1, r1, #0x15
	ldr r0, [r3, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081E141C
	lsls r0, r7, #3
	mov r6, r8
	adds r2, r0, r6
	adds r2, #0x3c
	mov r0, ip
	movs r6, #2
	ldrsh r1, [r0, r6]
	movs r6, #2
	ldrsh r0, [r2, r6]
	subs r1, r1, r0
	str r1, [sp]
	mov r0, sb
	movs r6, #2
	ldrsh r1, [r0, r6]
	movs r6, #0x2e
	ldrsh r0, [r3, r6]
	subs r0, r1, r0
	cmp r0, #0
	bge _081E13C2
	rsbs r0, r0, #0
_081E13C2:
	cmp r0, #0x7f
	bgt _081E13F0
	movs r0, #0x18
	ldrsh r1, [r4, r0]
	movs r3, #0
	ldrsh r0, [r2, r3]
	subs r0, r1, r0
	cmp r0, #0
	bge _081E13D6
	rsbs r0, r0, #0
_081E13D6:
	cmp r0, #0xe
	bgt _081E13F0
	movs r0, #0x18
	rsbs r0, r0, #0
	ldr r6, [sp]
	cmp r6, r0
	blt _081E13F0
	cmp r6, #4
	bgt _081E13F0
	movs r0, #1
	b _081E13F2
	.align 2, 0
_081E13EC: .4byte 0x03002BC0
_081E13F0:
	movs r0, #0
_081E13F2:
	cmp r0, #0
	beq _081E141C
	strb r7, [r4]
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl FUN_081df6dc
	mov r0, r8
	adds r1, r4, #0
	bl FUN_081e12c8
	ldr r0, _081E1418 @ =FUN_081e169c
	str r0, [r4, #0x20]
	movs r0, #0
	strh r0, [r4, #6]
	movs r0, #1
	strb r0, [r4, #4]
	b _081E1428
	.align 2, 0
_081E1418: .4byte FUN_081e169c
_081E141C:
	adds r5, #1
	mov r0, sl
	adds r0, #4
	cmp r5, r0
	blt _081E136E
_081E1426:
	movs r0, #0
_081E1428:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e1438
FUN_081e1438: @ 0x081E1438
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r4, r2, #0
	ldrb r0, [r5, #4]
	cmp r0, #0
	beq _081E144E
	movs r0, #0
	strb r0, [r5, #4]
	movs r0, #1
	b _081E1450
_081E144E:
	movs r0, #0
_081E1450:
	cmp r0, #0
	beq _081E147C
	ldr r0, [r5, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x24]
	adds r0, r5, #0
	adds r0, #0x50
	bl ParticleShadow_Show
	ldr r0, [r5, #0x40]
	ldr r1, [r5, #0x44]
	str r0, [r5, #8]
	str r1, [r5, #0xc]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_081e10b8
	ldr r0, _081E14E4 @ =0x00000276
	bl PlaySound_082406e0
_081E147C:
	ldrb r0, [r5, #2]
	adds r0, #1
	movs r2, #0
	strb r0, [r5, #2]
	movs r1, #0xff
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	blt _081E14AA
	strb r2, [r5, #2]
	ldrb r0, [r5, #3]
	adds r0, #1
	strb r0, [r5, #3]
	ands r0, r1
	cmp r0, #3
	bls _081E149E
	strb r2, [r5, #3]
_081E149E:
	ldrb r1, [r5, #3]
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq _081E14A8
	adds r1, #4
_081E14A8:
	strh r1, [r5, #0x34]
_081E14AA:
	adds r0, r5, #0
	adds r0, #0x40
	adds r1, r5, #0
	adds r1, #8
	adds r2, r5, #0
	adds r2, #0x10
	ldrh r3, [r5, #6]
	movs r4, #6
	str r4, [sp]
	bl LerpVec3
	ldr r2, _081E14E8 @ =0x085B0A08
	ldrh r0, [r5, #6]
	lsls r0, r0, #1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r1, #6
	subs r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _081E14EC
	asrs r2, r0, #0xc
	b _081E14F2
	.align 2, 0
_081E14E4: .4byte 0x00000276
_081E14E8: .4byte 0x085B0A08
_081E14EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081E14F2:
	adds r1, r5, #0
	adds r1, #0x42
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls _081E1516
	ldr r0, _081E1520 @ =FUN_081e1524
	str r0, [r5, #0x20]
	movs r0, #0
	strh r0, [r5, #6]
	movs r0, #1
	strb r0, [r5, #4]
_081E1516:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E1520: .4byte FUN_081e1524

	thumb_func_start FUN_081e1524
FUN_081e1524: @ 0x081E1524
	push {lr}
	adds r3, r1, #0
	ldrb r0, [r3, #4]
	cmp r0, #0
	beq _081E1532
	movs r0, #0
	strb r0, [r3, #4]
_081E1532:
	ldrb r0, [r3, #2]
	adds r0, #1
	movs r2, #0
	strb r0, [r3, #2]
	movs r1, #0xff
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	blt _081E1560
	strb r2, [r3, #2]
	ldrb r0, [r3, #3]
	adds r0, #1
	strb r0, [r3, #3]
	ands r0, r1
	cmp r0, #3
	bls _081E1554
	strb r2, [r3, #3]
_081E1554:
	ldrb r1, [r3, #3]
	ldrb r0, [r3, #1]
	cmp r0, #0
	beq _081E155E
	adds r1, #4
_081E155E:
	strh r1, [r3, #0x34]
_081E1560:
	ldr r2, _081E157C @ =0x085B0A08
	ldrh r0, [r3, #6]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	cmp r0, #0
	blt _081E1580
	asrs r1, r0, #0xc
	b _081E1586
	.align 2, 0
_081E157C: .4byte 0x085B0A08
_081E1580:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081E1586:
	ldrh r0, [r3, #0x12]
	adds r0, r0, r1
	adds r1, r3, #0
	adds r1, #0x42
	strh r0, [r1]
	ldrh r0, [r3, #6]
	adds r0, #1
	strh r0, [r3, #6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _081E15AA
	ldr r0, _081E15B0 @ =FUN_081e15b4
	str r0, [r3, #0x20]
	movs r0, #0
	strh r0, [r3, #6]
	movs r0, #1
	strb r0, [r3, #4]
_081E15AA:
	pop {r0}
	bx r0
	.align 2, 0
_081E15B0: .4byte FUN_081e15b4

	thumb_func_start FUN_081e15b4
FUN_081e15b4: @ 0x081E15B4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _081E15C8
	movs r0, #0
	strb r0, [r4, #4]
	movs r0, #1
	b _081E15CA
_081E15C8:
	movs r0, #0
_081E15CA:
	adds r5, r4, #0
	adds r5, #0x40
	cmp r0, #0
	beq _081E15FC
	adds r0, r5, #0
	movs r1, #0x80
	bl FUN_082342cc
	strb r0, [r4, #1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E15F4
	adds r1, r4, #0
	adds r1, #0x2b
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x50
	bl ParticleShadow_Hide
	b _081E15FC
_081E15F4:
	adds r1, r4, #0
	adds r1, #0x2b
	movs r0, #2
	strb r0, [r1]
_081E15FC:
	ldrb r0, [r4, #2]
	adds r0, #1
	movs r2, #0
	strb r0, [r4, #2]
	movs r1, #0xff
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	blt _081E162A
	strb r2, [r4, #2]
	ldrb r0, [r4, #3]
	adds r0, #1
	strb r0, [r4, #3]
	ands r0, r1
	cmp r0, #3
	bls _081E161E
	strb r2, [r4, #3]
_081E161E:
	ldrb r1, [r4, #3]
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _081E1628
	adds r1, #4
_081E1628:
	strh r1, [r4, #0x34]
_081E162A:
	adds r6, r4, #0
	adds r6, #0x18
	adds r2, r5, #0
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r5, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r5, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081E164C
	asrs r0, r0, #8
	b _081E1652
_081E164C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081E1652:
	strh r0, [r6]
	adds r1, r5, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081E1664
	asrs r0, r0, #8
	b _081E166A
_081E1664:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081E166A:
	adds r3, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _081E167E
	asrs r1, r0, #8
	b _081E1684
_081E167E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_081E1684:
	subs r0, r3, r1
	strh r0, [r6, #2]
	adds r0, r3, r1
	strh r0, [r6, #4]
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_081e1344
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e169c
FUN_081e169c: @ 0x081E169C
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _081E16AE
	movs r0, #0
	strb r0, [r4, #4]
	movs r0, #1
	b _081E16B0
_081E16AE:
	movs r0, #0
_081E16B0:
	cmp r0, #0
	beq _081E16DE
	movs r0, #0
	strb r0, [r4, #1]
	movs r1, #0
	ldrsb r1, [r4, r1]
	ldr r0, _081E16CC @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081E16D0
	movs r0, #1
	rsbs r0, r0, #0
	b _081E16D4
	.align 2, 0
_081E16CC: .4byte 0x03002C68
_081E16D0:
	movs r2, #0x18
	ldrsh r0, [r0, r2]
_081E16D4:
	cmp r1, r0
	bne _081E16DE
	ldr r0, _081E1730 @ =0x00000275
	bl PlaySound_082406e0
_081E16DE:
	ldrb r0, [r4, #2]
	adds r0, #1
	movs r2, #0
	strb r0, [r4, #2]
	movs r1, #0xff
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	blt _081E170C
	strb r2, [r4, #2]
	ldrb r0, [r4, #3]
	adds r0, #1
	strb r0, [r4, #3]
	ands r0, r1
	cmp r0, #3
	bls _081E1700
	strb r2, [r4, #3]
_081E1700:
	ldrb r1, [r4, #3]
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _081E170A
	adds r1, #4
_081E170A:
	strh r1, [r4, #0x34]
_081E170C:
	adds r1, r4, #0
	adds r1, #0x42
	ldrh r0, [r1]
	adds r0, #0x18
	strh r0, [r1]
	ldrh r0, [r4, #6]
	adds r0, #1
	strh r0, [r4, #6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _081E172A
	adds r0, r4, #0
	bl FUN_081e127c
_081E172A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E1730: .4byte 0x00000275

	thumb_func_start FUN_081e1734
FUN_081e1734: @ 0x081E1734
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #4
	mov ip, r0
	movs r6, #0
_081E173E:
	lsls r1, r6, #2
	adds r0, r7, #0
	adds r0, #0x5c
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081E17B2
	lsls r0, r6, #3
	adds r3, r0, r7
	adds r3, #0x3c
	adds r5, r1, #0
	adds r5, #0x2c
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081E1772
	asrs r0, r0, #8
	b _081E1778
_081E1772:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081E1778:
	strh r0, [r3]
	adds r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081E178A
	asrs r0, r0, #8
	b _081E1790
_081E178A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081E1790:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _081E17A4
	asrs r1, r0, #8
	b _081E17AA
_081E17A4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_081E17AA:
	subs r0, r2, r1
	strh r0, [r3, #2]
	adds r0, r2, r1
	strh r0, [r3, #4]
_081E17B2:
	adds r6, #1
	cmp r6, ip
	blt _081E173E
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity150F_Update
Entity150F_Update: @ 0x081E17C0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r7, #0
	adds r4, r5, #0
	adds r4, #0x6c
	movs r6, #0
_081E17CC:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _081E17EA
	cmp r7, #0
	bne _081E17DE
	adds r0, r5, #0
	bl FUN_081e1734
	movs r7, #1
_081E17DE:
	ldr r3, [r4, #0x20]
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl _call_via_r3
_081E17EA:
	adds r6, #1
	adds r4, #0x90
	cmp r6, #4
	ble _081E17CC
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity150F_Destroy
Entity150F_Destroy: @ 0x081E1800
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	adds r4, r5, #0
	adds r4, #0x6c
_081E180A:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_081e1260
	cmp r0, #0
	bge _081E181C
	movs r0, #1
	rsbs r0, r0, #0
	b _081E182C
_081E181C:
	adds r4, #0x90
	adds r6, #1
	cmp r6, #4
	ble _081E180A
	movs r1, #0
	ldr r0, _081E1834 @ =0x030001B0
	str r1, [r0]
	movs r0, #0
_081E182C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081E1834: .4byte 0x030001B0

	thumb_func_start Entity150F_Init
Entity150F_Init: @ 0x081E1838
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, _081E1868 @ =0x030001B0
	str r7, [r0]
	movs r0, #0
	str r0, [r7, #0x18]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r7, #0x1c]
	adds r0, r7, #0
	adds r0, #0x20
	ldr r1, _081E186C @ =0x00002712
	bl Video_GetAuxSprite
	cmp r0, #0
	bne _081E1870
_081E1860:
	movs r0, #1
	rsbs r0, r0, #0
	b _081E1934
	.align 2, 0
_081E1868: .4byte 0x030001B0
_081E186C: .4byte 0x00002712
_081E1870:
	ldr r0, _081E18E4 @ =0x03002C68
	ldr r0, [r0]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r6, r0, r1
	cmp r0, #0
	bne _081E1880
	movs r6, #0
_081E1880:
	movs r5, #0
	adds r4, r7, #0
	adds r4, #0x6c
_081E1886:
	adds r0, r6, r5
	movs r2, #0
	ldrsb r2, [r0, r2]
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_081e1220
	cmp r0, #0
	blt _081E1860
	adds r4, #0x90
	adds r5, #1
	cmp r5, #4
	ble _081E1886
	movs r5, #0
	ldr r2, _081E18E8 @ =0x03002BE0
	mov r8, r2
	movs r0, #0x5c
	adds r0, r0, r7
	mov ip, r0
_081E18AC:
	lsls r1, r5, #2
	mov r2, r8
	adds r0, r1, r2
	ldr r2, [r0]
	add r1, ip
	str r2, [r1]
	cmp r2, #0
	beq _081E192C
	lsls r0, r5, #3
	adds r3, r0, r7
	adds r3, #0x3c
	adds r6, r2, #0
	adds r6, #0x2c
	ldrh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081E18EC
	asrs r0, r0, #8
	b _081E18F2
	.align 2, 0
_081E18E4: .4byte 0x03002C68
_081E18E8: .4byte 0x03002BE0
_081E18EC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081E18F2:
	strh r0, [r3]
	adds r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081E1904
	asrs r0, r0, #8
	b _081E190A
_081E1904:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081E190A:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _081E191E
	asrs r1, r0, #8
	b _081E1924
_081E191E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_081E1924:
	subs r0, r2, r1
	strh r0, [r3, #2]
	adds r0, r2, r1
	strh r0, [r3, #4]
_081E192C:
	adds r5, #1
	cmp r5, #3
	ble _081E18AC
	movs r0, #0
_081E1934:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity150F_Create
Entity150F_Create: @ 0x081E1940
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xcf
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081E197C
	ldr r1, _081E1974 @ =Entity150F_Update
	ldr r2, _081E1978 @ =Entity150F_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity150F_Init
	cmp r0, #0
	bge _081E197C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081E197E
	.align 2, 0
_081E1974: .4byte Entity150F_Update
_081E1978: .4byte Entity150F_Destroy
_081E197C:
	adds r0, r4, #0
_081E197E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e1984
FUN_081e1984: @ 0x081E1984
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E19CC @ =0x030001B0
	ldr r0, [r0]
	cmp r0, #0
	beq _081E19D4
	bl FUN_081e12a4
	adds r3, r0, #0
	cmp r3, #0
	beq _081E19D4
	movs r0, #0xff
	strb r0, [r3]
	movs r2, #0
	strb r2, [r3, #1]
	strb r2, [r3, #2]
	strb r2, [r3, #3]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x40]
	str r1, [r3, #0x44]
	adds r1, r3, #0
	adds r1, #0x2b
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #8]
	str r1, [r3, #0xc]
	ldr r0, _081E19D0 @ =FUN_081e1438
	str r0, [r3, #0x20]
	strh r2, [r3, #6]
	movs r0, #1
	strb r0, [r3, #4]
	movs r0, #0
	b _081E19D8
	.align 2, 0
_081E19CC: .4byte 0x030001B0
_081E19D0: .4byte FUN_081e1438
_081E19D4:
	movs r0, #1
	rsbs r0, r0, #0
_081E19D8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
