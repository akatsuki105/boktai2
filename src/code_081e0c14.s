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
	bl FUN_0822a470
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
	bl FUN_0822a4e0
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
	bl Script_ExecById
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

	thumb_func_start FUN_081e19e0
FUN_081e19e0: @ 0x081E19E0
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e19e4
FUN_081e19e4: @ 0x081E19E4
	push {lr}
	movs r1, #0x20
	ldr r0, [r0, #0x64]
	ands r0, r1
	pop {r0}
	bx r0

	thumb_func_start FUN_081e19f0
FUN_081e19f0: @ 0x081E19F0
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e19f4
FUN_081e19f4: @ 0x081E19F4
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e19f8
FUN_081e19f8: @ 0x081E19F8
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e19fc
FUN_081e19fc: @ 0x081E19FC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	bl FUN_080478f0
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #6
	bl FUN_08047b8c
	movs r0, #0
	bl FUN_08047a28
	ldr r0, _081E1A3C @ =0x000026BB
	bl FUN_08047dc0
	movs r0, #1
	bl FUN_080477e4
	adds r1, r4, #0
	adds r1, #0x61
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _081E1A40 @ =0xFFFFFBFF
	ldr r0, [r4, #0x64]
	ands r0, r1
	str r0, [r4, #0x64]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E1A3C: .4byte 0x000026BB
_081E1A40: .4byte 0xFFFFFBFF

	thumb_func_start FUN_081e1a44
FUN_081e1a44: @ 0x081E1A44
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _081E1A88 @ =0x0000C091
	ldr r1, _081E1A8C @ =0x0000A413
	bl GetFile
	adds r2, r0, #0
	str r2, [r4, #0x58]
	movs r0, #3
	str r0, [sp, #0xc]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E1A88: .4byte 0x0000C091
_081E1A8C: .4byte 0x0000A413

	thumb_func_start FUN_081e1a90
FUN_081e1a90: @ 0x081E1A90
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_08047864
	movs r0, #0
	bl ClearBGTilemapBuffer
	bl Sio_Reset
	bl Sio_Start
	adds r3, r0, #0
	ldr r2, _081E1AF0 @ =FUN_081e1cec
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	ands r0, r1
	str r2, [r4, #0x4c]
	adds r2, r4, #0
	adds r2, #0x69
	movs r0, #1
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x6a
	movs r0, #0
	strb r0, [r1]
	adds r5, r1, #0
	cmp r3, #0
	bge _081E1AF8
	subs r1, #2
	movs r0, #2
	strb r0, [r1]
	ldr r3, _081E1AF4 @ =FUN_081e1f80
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	ands r0, r1
	str r3, [r4, #0x4c]
	movs r0, #1
	strb r0, [r2]
	movs r0, #5
	strb r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	orrs r0, r1
	str r0, [r4, #0x64]
	b _081E1B3A
	.align 2, 0
_081E1AF0: .4byte FUN_081e1cec
_081E1AF4: .4byte FUN_081e1f80
_081E1AF8:
	cmp r3, #0
	bne _081E1B0A
	movs r0, #0x20
	ldr r1, [r4, #0x64]
	orrs r1, r0
	str r1, [r4, #0x64]
	bl FUN_08238114
	b _081E1B16
_081E1B0A:
	movs r0, #0x40
	ldr r1, [r4, #0x64]
	orrs r1, r0
	str r1, [r4, #0x64]
	bl FUN_08238120
_081E1B16:
	str r0, [r4, #0x70]
	bl FUN_08238480
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, [r4, #0x64]
	orrs r0, r1
	str r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0x6d
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x6c
	movs r1, #0
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
_081E1B3A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e1b40
FUN_081e1b40: @ 0x081E1B40
	push {r4, lr}
	adds r4, r0, #0
	cmp r2, #0
	beq _081E1B58
	adds r1, r4, #0
	adds r1, #0x68
	movs r0, #3
	strb r0, [r1]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081E1B60
_081E1B58:
	adds r1, r4, #0
	adds r1, #0x68
	movs r0, #4
	strb r0, [r1]
_081E1B60:
	ldr r2, _081E1B8C @ =FUN_081e1ff8
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	ands r0, r1
	str r2, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #6
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	orrs r0, r1
	str r0, [r4, #0x64]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E1B8C: .4byte FUN_081e1ff8

	thumb_func_start FUN_081e1b90
FUN_081e1b90: @ 0x081E1B90
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r0, [r6, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E1BA8
	movs r0, #1
	b _081E1BAA
_081E1BA8:
	movs r0, #0
_081E1BAA:
	adds r7, r0, #0
	cmp r7, #0
	bne _081E1C80
	movs r0, #0
	mov r8, r0
	bl FUN_0823812c
	adds r5, r0, #0
	cmp r5, #0
	beq _081E1BC8
	cmp r5, #1
	beq _081E1BE4
	adds r1, r6, #0
	adds r1, #0x6b
	b _081E1C0E
_081E1BC8:
	bl FUN_082380f4
	mov r8, r0
	bl FUN_08238114
	ldr r1, [r6, #0x70]
	cmp r1, r0
	beq _081E1BF4
	adds r4, r6, #0
	adds r4, #0x6b
	strb r5, [r4]
	bl FUN_08238114
	b _081E1C0A
_081E1BE4:
	bl FUN_082380d4
	mov r8, r0
	bl FUN_08238120
	ldr r1, [r6, #0x70]
	cmp r1, r0
	bne _081E1C00
_081E1BF4:
	adds r1, r6, #0
	adds r1, #0x6b
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _081E1C0E
_081E1C00:
	adds r4, r6, #0
	adds r4, #0x6b
	strb r7, [r4]
	bl FUN_08238120
_081E1C0A:
	str r0, [r6, #0x70]
	adds r1, r4, #0
_081E1C0E:
	ldrb r0, [r1]
	cmp r0, #0xa
	bhi _081E1C2C
	mov r0, r8
	cmp r0, #0
	bne _081E1C30
	adds r1, r6, #0
	adds r1, #0x6c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bls _081E1C38
_081E1C2C:
	movs r0, #1
	b _081E1C82
_081E1C30:
	adds r1, r6, #0
	adds r1, #0x6c
	movs r0, #0
	strb r0, [r1]
_081E1C38:
	bl FUN_08238094
	cmp r0, #0
	blt _081E1C2C
	bl FUN_0823812c
	cmp r0, #0
	blt _081E1C80
	bl FUN_0823812c
	adds r1, r6, #0
	adds r1, #0x6d
	movs r2, #0
	ldrsb r2, [r1, r2]
	adds r4, r1, #0
	cmp r0, r2
	beq _081E1C80
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r0, [r6, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E1C6A
	movs r0, #1
	b _081E1C6C
_081E1C6A:
	movs r0, #0
_081E1C6C:
	cmp r0, #0
	bne _081E1C2C
	bl FUN_0823812c
	strb r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r0, [r6, #0x64]
	orrs r0, r1
	str r0, [r6, #0x64]
_081E1C80:
	movs r0, #0
_081E1C82:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e1c8c
FUN_081e1c8c: @ 0x081E1C8C
	push {lr}
	adds r2, r0, #0
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _081E1CAE
	adds r0, r2, #0
	bl FUN_08238538
	cmp r0, #0
	ble _081E1CA6
	movs r0, #1
	b _081E1CB2
_081E1CA6:
	cmp r0, #0
	blt _081E1CAE
	movs r0, #0
	b _081E1CB2
_081E1CAE:
	movs r0, #1
	rsbs r0, r0, #0
_081E1CB2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e1cb8
FUN_081e1cb8: @ 0x081E1CB8
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	ldr r0, [r4]
	cmp r0, #0
	blt _081E1CD0
	bl FUN_082384f4
	cmp r0, #0
	bne _081E1CDE
	movs r0, #1
	b _081E1CE4
_081E1CD0:
	adds r0, r2, #0
	movs r1, #0x10
	bl FUN_082384b0
	str r0, [r4]
	cmp r0, #0
	blt _081E1CE2
_081E1CDE:
	movs r0, #2
	b _081E1CE4
_081E1CE2:
	movs r0, #0
_081E1CE4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e1cec
FUN_081e1cec: @ 0x081E1CEC
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x69
	ldrb r0, [r1]
	cmp r0, #0
	beq _081E1CFE
	movs r0, #0
	strb r0, [r1]
_081E1CFE:
	adds r0, r2, #0
	bl FUN_081e1d7c
	pop {r0}
	bx r0

	thumb_func_start FUN_081e1d08
FUN_081e1d08: @ 0x081E1D08
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x69
	ldrb r0, [r1]
	cmp r0, #0
	beq _081E1D1A
	movs r0, #0
	strb r0, [r1]
_081E1D1A:
	movs r1, #1
	ldr r0, [r4, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E1D28
	movs r0, #1
	b _081E1D2A
_081E1D28:
	movs r0, #0
_081E1D2A:
	cmp r0, #0
	beq _081E1D72
	adds r0, r4, #0
	adds r0, #0x3c
	adds r1, r4, #0
	adds r1, #0x50
	bl FUN_081e1cb8
	cmp r0, #1
	bne _081E1D72
	ldr r1, [r4, #0x78]
	cmp r1, #0
	beq _081E1D4A
	ldr r0, [r4, #0x74]
	bl _call_via_r1
_081E1D4A:
	movs r0, #0
	strh r0, [r4, #0x3c]
	subs r0, #2
	ldr r1, [r4, #0x64]
	ands r1, r0
	str r1, [r4, #0x64]
	adds r0, #1
	str r0, [r4, #0x50]
	ldr r2, _081E1D78 @ =FUN_081e1cec
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	str r2, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #0
	strb r0, [r1]
_081E1D72:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E1D78: .4byte FUN_081e1cec

	thumb_func_start FUN_081e1d7c
FUN_081e1d7c: @ 0x081E1D7C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x3c
	ldr r1, [r4, #0x64]
	bl FUN_081e1c8c
	cmp r0, #0
	beq _081E1D96
	cmp r0, #0
	ble _081E1E24
	cmp r0, #1
	beq _081E1D9E
	b _081E1E24
_081E1D96:
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #0x50]
	b _081E1E24
_081E1D9E:
	ldrh r0, [r4, #0x3c]
	adds r1, r0, #0
	cmp r1, #6
	bne _081E1DAA
	movs r0, #1
	b _081E1DAC
_081E1DAA:
	movs r0, #0
_081E1DAC:
	cmp r0, #0
	beq _081E1DB4
	movs r0, #0x82
	b _081E1DF8
_081E1DB4:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bne _081E1DC0
	movs r0, #1
	b _081E1DC2
_081E1DC0:
	movs r0, #0
_081E1DC2:
	cmp r0, #0
	beq _081E1DCC
	movs r0, #0x81
	lsls r0, r0, #1
	b _081E1DF8
_081E1DCC:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	bne _081E1DD8
	movs r0, #1
	b _081E1DDA
_081E1DD8:
	movs r0, #0
_081E1DDA:
	cmp r0, #0
	beq _081E1DE8
	ldr r0, _081E1DE4 @ =0x00000202
	b _081E1DF8
	.align 2, 0
_081E1DE4: .4byte 0x00000202
_081E1DE8:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xa
	bne _081E1DF4
	movs r0, #1
	b _081E1DF6
_081E1DF4:
	movs r0, #0
_081E1DF6:
	movs r0, #2
_081E1DF8:
	ldr r1, [r4, #0x64]
	orrs r1, r0
	str r1, [r4, #0x64]
	ldr r2, _081E1E20 @ =FUN_081e1e2c
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	str r2, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #4
	strb r0, [r1]
	subs r0, #5
	str r0, [r4, #0x50]
	movs r0, #1
	b _081E1E26
	.align 2, 0
_081E1E20: .4byte FUN_081e1e2c
_081E1E24:
	movs r0, #0
_081E1E26:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e1e2c
FUN_081e1e2c: @ 0x081E1E2C
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x69
	ldrb r0, [r1]
	cmp r0, #0
	beq _081E1E3E
	movs r0, #0
	strb r0, [r1]
_081E1E3E:
	movs r1, #2
	ldr r0, [r4, #0x64]
	ands r0, r1
	movs r0, #3
	rsbs r0, r0, #0
	ldr r1, [r4, #0x64]
	ands r1, r0
	str r1, [r4, #0x64]
	movs r0, #0x80
	ands r1, r0
	cmp r1, #0
	beq _081E1E5A
	movs r0, #1
	b _081E1E5C
_081E1E5A:
	movs r0, #0
_081E1E5C:
	cmp r0, #0
	beq _081E1EA0
	movs r0, #0x81
	rsbs r0, r0, #0
	ldr r1, [r4, #0x64]
	ands r1, r0
	str r1, [r4, #0x64]
	movs r0, #1
	strh r0, [r4, #0x3c]
	ldr r0, _081E1E98 @ =0x030046A0
	ldr r2, [r0]
	movs r3, #0xf0
	lsls r3, r3, #2
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [r4, #0x40]
	adds r3, #4
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [r4, #0x44]
	adds r3, #4
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [r4, #0x48]
_081E1E8C:
	ldr r2, _081E1E9C @ =FUN_081e1d08
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	b _081E1F10
	.align 2, 0
_081E1E98: .4byte 0x030046A0
_081E1E9C: .4byte FUN_081e1d08
_081E1EA0:
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r1, [r4, #0x64]
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _081E1EB2
	movs r0, #1
	b _081E1EB4
_081E1EB2:
	movs r0, #0
_081E1EB4:
	cmp r0, #0
	beq _081E1EDC
	ldr r1, _081E1ED4 @ =0xFFFFFEFF
	ands r1, r2
	str r1, [r4, #0x64]
	movs r0, #0
	strh r0, [r4, #0x3c]
	ldr r0, _081E1ED8 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x91
	lsls r2, r2, #4
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [r4, #0x40]
	b _081E1E8C
	.align 2, 0
_081E1ED4: .4byte 0xFFFFFEFF
_081E1ED8: .4byte 0x030046A0
_081E1EDC:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081E1EEA
	movs r0, #1
	b _081E1EEC
_081E1EEA:
	movs r0, #0
_081E1EEC:
	cmp r0, #0
	beq _081E1F34
	ldr r0, _081E1F2C @ =0xFFFFFDFF
	ands r0, r2
	str r0, [r4, #0x64]
	movs r0, #2
	strh r0, [r4, #0x3c]
	bl FUN_08243104
	str r0, [r4, #0x40]
	bl FUN_08243140
	str r0, [r4, #0x44]
	ldr r2, _081E1F30 @ =FUN_081e1d08
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	ands r0, r1
_081E1F10:
	str r2, [r4, #0x4c]
	adds r0, r4, #0
	adds r0, #0x69
	movs r1, #1
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x6a
	movs r0, #1
	strb r0, [r2]
	ldr r0, [r4, #0x64]
	orrs r0, r1
	str r0, [r4, #0x64]
	b _081E1F74
	.align 2, 0
_081E1F2C: .4byte 0xFFFFFDFF
_081E1F30: .4byte FUN_081e1d08
_081E1F34:
	ldr r2, [r4, #0x7c]
	cmp r2, #0
	beq _081E1F44
	ldr r0, [r4, #0x74]
	adds r1, r4, #0
	adds r1, #0x3c
	bl _call_via_r2
_081E1F44:
	movs r0, #0x80
	lsls r0, r0, #5
	ldr r1, [r4, #0x64]
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _081E1F56
	movs r0, #1
	b _081E1F58
_081E1F56:
	movs r0, #0
_081E1F58:
	cmp r0, #0
	bne _081E1F74
	ldr r1, _081E1F7C @ =FUN_081e1cec
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r2
	str r1, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #0
	strb r0, [r1]
_081E1F74:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E1F7C: .4byte FUN_081e1cec

	thumb_func_start FUN_081e1f80
FUN_081e1f80: @ 0x081E1F80
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x69
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E1FD6
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	ldr r1, [r5, #0x58]
	movs r0, #0
	movs r2, #3
	bl FUN_0822c398
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r5, #0
	adds r0, #0x68
	ldrb r0, [r0]
	bl FUN_08047a28
	movs r0, #1
	bl FUN_080477e4
	movs r0, #1
	bl Sound_FadeOutBGM
	adds r1, r5, #0
	adds r1, #0x62
	movs r0, #0
	strh r4, [r1]
	strb r0, [r6]
_081E1FD6:
	adds r1, r5, #0
	adds r1, #0x62
	ldrh r0, [r1]
	cmp r0, #0x3b
	bhi _081E1FE6
	adds r0, #1
	strh r0, [r1]
	b _081E1FF0
_081E1FE6:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r5, #0x64]
	orrs r0, r1
	str r0, [r5, #0x64]
_081E1FF0:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e1ff8
FUN_081e1ff8: @ 0x081E1FF8
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x69
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E204E
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	ldr r1, [r5, #0x58]
	movs r0, #0
	movs r2, #3
	bl FUN_0822c398
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r5, #0
	adds r0, #0x68
	ldrb r0, [r0]
	bl FUN_08047a28
	movs r0, #1
	bl FUN_080477e4
	movs r0, #1
	bl Sound_FadeOutBGM
	adds r1, r5, #0
	adds r1, #0x62
	movs r0, #0
	strh r4, [r1]
	strb r0, [r6]
_081E204E:
	adds r0, r5, #0
	adds r0, #0x62
	ldrh r1, [r0]
	adds r4, r0, #0
	cmp r1, #0x9c
	bne _081E2072
	movs r0, #4
	str r0, [sp]
	ldr r0, _081E20D0 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_081E2072:
	ldrh r0, [r4]
	cmp r0, #0xb4
	bls _081E20C0
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r5, #0
	adds r0, #0x80
	ldr r1, [r0]
	cmp r1, #0
	beq _081E20A0
	adds r0, r5, #0
	bl _call_via_r1
_081E20A0:
	bl FUN_0824172c
	ldr r0, _081E20D4 @ =0x0300481C
	movs r1, #0
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0x6e
	ldrh r0, [r1]
	cmp r0, #0
	beq _081E20BA
	movs r1, #0
	bl Script_ExecById
_081E20BA:
	adds r0, r5, #0
	bl KillEntity
_081E20C0:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E20D0: .4byte 0x0000FFFF
_081E20D4: .4byte 0x0300481C

	thumb_func_start FUN_081e20d8
FUN_081e20d8: @ 0x081E20D8
	push {lr}
	adds r1, r0, #0
	adds r1, #0x69
	ldrb r0, [r1]
	cmp r0, #0
	beq _081E20E8
	movs r0, #0
	strb r0, [r1]
_081E20E8:
	pop {r0}
	bx r0

	thumb_func_start FUN_081e20ec
FUN_081e20ec: @ 0x081E20EC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08241704
	ldr r1, _081E210C @ =0x0300481C
	movs r0, #1
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r4, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E2110
	movs r0, #1
	b _081E2112
	.align 2, 0
_081E210C: .4byte 0x0300481C
_081E2110:
	movs r0, #0
_081E2112:
	cmp r0, #0
	bne _081E211C
	ldr r1, _081E2130 @ =0x030047B8
	movs r0, #1
	str r0, [r1]
_081E211C:
	movs r0, #0x80
	lsls r0, r0, #5
	ldr r1, [r4, #0x64]
	ands r0, r1
	adds r2, r1, #0
	cmp r0, #0
	beq _081E2134
	movs r0, #1
	b _081E2136
	.align 2, 0
_081E2130: .4byte 0x030047B8
_081E2134:
	movs r0, #0
_081E2136:
	cmp r0, #0
	beq _081E2148
	ldr r1, [r4, #0x4c]
	cmp r1, #0
	beq _081E21A6
	adds r0, r4, #0
	bl _call_via_r1
	b _081E21A6
_081E2148:
	ldr r1, _081E215C @ =0x030047B8
	movs r0, #1
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081E2160
	movs r0, #1
	b _081E2162
	.align 2, 0
_081E215C: .4byte 0x030047B8
_081E2160:
	movs r0, #0
_081E2162:
	cmp r0, #0
	beq _081E21B0
	bl FUN_0823849c
	adds r0, r4, #0
	bl FUN_081e1b90
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E21B0
	adds r1, r4, #0
	adds r1, #0x68
	movs r0, #2
	strb r0, [r1]
	ldr r2, _081E21AC @ =FUN_081e1f80
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	ands r0, r1
	str r2, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #5
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	orrs r0, r1
	str r0, [r4, #0x64]
	bl Sio_Stop
_081E21A6:
	movs r0, #1
	rsbs r0, r0, #0
	b _081E21BE
	.align 2, 0
_081E21AC: .4byte FUN_081e1f80
_081E21B0:
	ldr r1, [r4, #0x4c]
	cmp r1, #0
	beq _081E21BC
	adds r0, r4, #0
	bl _call_via_r1
_081E21BC:
	movs r0, #1
_081E21BE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e21c4
FUN_081e21c4: @ 0x081E21C4
	push {lr}
	bl Sio_Stop
	ldr r1, _081E21D8 @ =0x03002C6C
	movs r0, #0
	str r0, [r1]
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
_081E21D8: .4byte 0x03002C6C

	thumb_func_start FUN_081e21dc
FUN_081e21dc: @ 0x081E21DC
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0
	bl sound_082402f8
	movs r5, #1
	rsbs r5, r5, #0
	str r5, [r4, #0x50]
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081E2200
	bl FUN_0823d340
	str r0, [r4, #0x54]
	cmp r0, #0
	beq _081E221C
_081E2200:
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r4, #0
	adds r1, #0x6e
	movs r5, #0
	strh r0, [r1]
	ldr r0, _081E2224 @ =0x00001770
	movs r1, #1
	bl FUN_081d9d38
	cmp r0, #0
	bne _081E2228
_081E221C:
	movs r0, #1
	rsbs r0, r0, #0
	b _081E226A
	.align 2, 0
_081E2224: .4byte 0x00001770
_081E2228:
	ldr r1, _081E2270 @ =FUN_081e1a90
	ldr r2, _081E2274 @ =FUN_081e1b40
	adds r0, r4, #0
	bl FUN_081d9d88
	adds r0, r4, #0
	bl FUN_081e1a44
	adds r0, r4, #0
	bl FUN_081e19fc
	ldr r0, _081E2278 @ =0x03002C6C
	str r4, [r0]
	str r5, [r4, #0x7c]
	adds r0, r4, #0
	adds r0, #0x80
	str r5, [r0]
	str r5, [r4, #0x78]
	str r5, [r4, #0x74]
	ldr r2, _081E227C @ =FUN_081e20d8
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x64]
	ands r0, r1
	str r2, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #7
	strb r0, [r1]
	movs r0, #1
_081E226A:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081E2270: .4byte FUN_081e1a90
_081E2274: .4byte FUN_081e1b40
_081E2278: .4byte 0x03002C6C
_081E227C: .4byte FUN_081e20d8

	thumb_func_start FUN_081e2280
FUN_081e2280: @ 0x081E2280
	push {r4, lr}
	ldr r0, _081E22B4 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	bne _081E22C2
	movs r0, #2
	movs r1, #0x84
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081E22C0
	ldr r1, _081E22B8 @ =FUN_081e20ec
	ldr r2, _081E22BC @ =FUN_081e21c4
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081e21dc
	cmp r0, #0
	bge _081E22C0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081E22C2
	.align 2, 0
_081E22B4: .4byte 0x03002C6C
_081E22B8: .4byte FUN_081e20ec
_081E22BC: .4byte FUN_081e21c4
_081E22C0:
	adds r0, r4, #0
_081E22C2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e22c8
FUN_081e22c8: @ 0x081E22C8
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #1
	rsbs r4, r4, #0
	str r4, [r5, #0x50]
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081E22EA
	bl FUN_0823d340
	str r0, [r5, #0x54]
	cmp r0, #0
	bne _081E22EA
	adds r0, r4, #0
	b _081E2322
_081E22EA:
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r5, #0
	adds r1, #0x6e
	movs r4, #0
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_081e1a44
	adds r0, r5, #0
	bl FUN_081e19fc
	ldr r0, _081E2328 @ =0x03002C6C
	str r5, [r0]
	str r4, [r5, #0x7c]
	adds r0, r5, #0
	adds r0, #0x80
	str r4, [r0]
	str r4, [r5, #0x78]
	str r4, [r5, #0x74]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_081e1a90
	movs r0, #1
_081E2322:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081E2328: .4byte 0x03002C6C

	thumb_func_start FUN_081e232c
FUN_081e232c: @ 0x081E232C
	push {r4, lr}
	ldr r0, _081E2360 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	bne _081E236E
	movs r0, #2
	movs r1, #0x84
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081E236C
	ldr r1, _081E2364 @ =FUN_081e20ec
	ldr r2, _081E2368 @ =FUN_081e21c4
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081e22c8
	cmp r0, #0
	bge _081E236C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081E236E
	.align 2, 0
_081E2360: .4byte 0x03002C6C
_081E2364: .4byte FUN_081e20ec
_081E2368: .4byte FUN_081e21c4
_081E236C:
	adds r0, r4, #0
_081E236E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e2374
FUN_081e2374: @ 0x081E2374
	ldr r1, _081E237C @ =0x03002C6C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081E237C: .4byte 0x03002C6C

	thumb_func_start FUN_081e2380
FUN_081e2380: @ 0x081E2380
	push {lr}
	ldr r0, _081E2398 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E23A2
	movs r1, #3
	ldr r0, [r0, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E239C
	movs r0, #1
	b _081E239E
	.align 2, 0
_081E2398: .4byte 0x03002C6C
_081E239C:
	movs r0, #0
_081E239E:
	cmp r0, #0
	bne _081E23A6
_081E23A2:
	movs r0, #0
	b _081E23A8
_081E23A6:
	movs r0, #1
_081E23A8:
	pop {r1}
	bx r1

	thumb_func_start FUN_081e23ac
FUN_081e23ac: @ 0x081E23AC
	push {lr}
	adds r1, r0, #0
	ldr r0, _081E23C0 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E23BC
	str r1, [r0, #0x74]
	str r1, [r0, #0x7c]
_081E23BC:
	pop {r0}
	bx r0
	.align 2, 0
_081E23C0: .4byte 0x03002C6C

	thumb_func_start FUN_081e23c4
FUN_081e23c4: @ 0x081E23C4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E23E0 @ =0x03002C6C
	ldr r3, [r0]
	cmp r3, #0
	beq _081E23DA
	str r4, [r3, #0x7c]
	adds r0, r3, #0
	adds r0, #0x80
	str r1, [r0]
	str r2, [r3, #0x78]
_081E23DA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E23E0: .4byte 0x03002C6C

	thumb_func_start FUN_081e23e4
FUN_081e23e4: @ 0x081E23E4
	push {lr}
	ldr r0, _081E23F4 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	bne _081E23F8
	movs r0, #1
	rsbs r0, r0, #0
	b _081E2412
	.align 2, 0
_081E23F4: .4byte 0x03002C6C
_081E23F8:
	movs r1, #0x20
	ldr r0, [r0, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E2406
	movs r0, #1
	b _081E2408
_081E2406:
	movs r0, #0
_081E2408:
	cmp r0, #0
	bne _081E2410
	movs r0, #0
	b _081E2412
_081E2410:
	movs r0, #1
_081E2412:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e2418
FUN_081e2418: @ 0x081E2418
	push {lr}
	adds r1, r0, #0
	ldr r0, _081E242C @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E2430
	adds r0, #0x60
	strb r1, [r0]
	movs r0, #0
	b _081E2434
	.align 2, 0
_081E242C: .4byte 0x03002C6C
_081E2430:
	movs r0, #1
	rsbs r0, r0, #0
_081E2434:
	pop {r1}
	bx r1

	thumb_func_start FUN_081e2438
FUN_081e2438: @ 0x081E2438
	push {lr}
	ldr r0, _081E2448 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E244C
	adds r0, #0x60
	ldrb r0, [r0]
	b _081E244E
	.align 2, 0
_081E2448: .4byte 0x03002C6C
_081E244C:
	movs r0, #0
_081E244E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e2454
FUN_081e2454: @ 0x081E2454
	push {lr}
	ldr r0, _081E2470 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E247A
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, [r0, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E2474
	movs r0, #1
	b _081E2476
	.align 2, 0
_081E2470: .4byte 0x03002C6C
_081E2474:
	movs r0, #0
_081E2476:
	cmp r0, #0
	bne _081E247E
_081E247A:
	movs r0, #0
	b _081E2480
_081E247E:
	movs r0, #1
_081E2480:
	pop {r1}
	bx r1

	thumb_func_start FUN_081e2484
FUN_081e2484: @ 0x081E2484
	push {lr}
	ldr r0, _081E24A0 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E24AE
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r0, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E24A4
	movs r0, #1
	b _081E24A6
	.align 2, 0
_081E24A0: .4byte 0x03002C6C
_081E24A4:
	movs r0, #0
_081E24A6:
	cmp r0, #0
	bne _081E24AE
	movs r0, #0
	b _081E24B0
_081E24AE:
	movs r0, #1
_081E24B0:
	pop {r1}
	bx r1

	thumb_func_start FUN_081e24b4
FUN_081e24b4: @ 0x081E24B4
	push {lr}
	ldr r0, _081E24D0 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E2506
	adds r2, r0, #0
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r2, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E24D4
	movs r0, #1
	b _081E24D6
	.align 2, 0
_081E24D0: .4byte 0x03002C6C
_081E24D4:
	movs r0, #0
_081E24D6:
	cmp r0, #0
	bne _081E2506
	adds r1, r2, #0
	adds r1, #0x68
	movs r0, #2
	strb r0, [r1]
	ldr r3, _081E250C @ =FUN_081e1f80
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r2, #0x64]
	ands r0, r1
	str r3, [r2, #0x4c]
	adds r1, r2, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #5
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r2, #0x64]
	orrs r0, r1
	str r0, [r2, #0x64]
_081E2506:
	pop {r0}
	bx r0
	.align 2, 0
_081E250C: .4byte FUN_081e1f80

	thumb_func_start FUN_081e2510
FUN_081e2510: @ 0x081E2510
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _081E2530 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E253E
	adds r3, r0, #0
	ldr r1, _081E2534 @ =0x00001003
	ldr r0, [r3, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E2538
	movs r0, #1
	b _081E253A
	.align 2, 0
_081E2530: .4byte 0x03002C6C
_081E2534: .4byte 0x00001003
_081E2538:
	movs r0, #0
_081E253A:
	cmp r0, #0
	beq _081E2542
_081E253E:
	movs r0, #0
	b _081E25CE
_081E2542:
	cmp r4, #3
	bne _081E2558
	strh r4, [r3, #0x3c]
	ldr r0, [r5]
	str r0, [r3, #0x40]
	ldr r0, [r5, #4]
	str r0, [r3, #0x44]
	ldr r0, [r5, #8]
_081E2552:
	str r0, [r3, #0x48]
_081E2554:
	strh r2, [r3, #0x3e]
	b _081E25AA
_081E2558:
	cmp r4, #4
	bne _081E256A
	strh r4, [r3, #0x3c]
	ldr r0, [r5, #0xc]
	str r0, [r3, #0x40]
	ldr r0, [r5, #0x10]
	str r0, [r3, #0x44]
	ldr r0, [r5, #0x14]
	b _081E2552
_081E256A:
	cmp r4, #5
	bne _081E257C
	strh r4, [r3, #0x3c]
	ldr r0, [r5, #0x18]
	str r0, [r3, #0x40]
	ldr r0, [r5, #0x1c]
	str r0, [r3, #0x44]
	ldr r0, [r5, #0x20]
	b _081E2552
_081E257C:
	cmp r4, #0xa
	bne _081E2588
	strh r4, [r3, #0x3c]
	ldr r0, [r5]
	str r0, [r3, #0x40]
	b _081E2554
_081E2588:
	cmp r4, #0xb
	bne _081E2590
	strh r4, [r3, #0x3c]
	b _081E2554
_081E2590:
	cmp r4, #0xc
	bne _081E259C
	strh r4, [r3, #0x3c]
	ldr r0, [r5]
	str r0, [r3, #0x40]
	b _081E2554
_081E259C:
	cmp r4, #6
	beq _081E25A8
	cmp r4, #7
	beq _081E25A8
	cmp r4, #8
	bne _081E25CC
_081E25A8:
	strh r4, [r3, #0x3c]
_081E25AA:
	ldr r2, _081E25D4 @ =FUN_081e1d08
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r3, #0x64]
	ands r0, r1
	str r2, [r3, #0x4c]
	adds r0, r3, #0
	adds r0, #0x69
	movs r1, #1
	strb r1, [r0]
	adds r2, r3, #0
	adds r2, #0x6a
	movs r0, #1
	strb r0, [r2]
	ldr r0, [r3, #0x64]
	orrs r0, r1
	str r0, [r3, #0x64]
_081E25CC:
	movs r0, #1
_081E25CE:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081E25D4: .4byte FUN_081e1d08

	thumb_func_start FUN_081e25d8
FUN_081e25d8: @ 0x081E25D8
	push {lr}
	ldr r0, _081E25EC @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E25E6
	bl KillEntity
_081E25E6:
	pop {r0}
	bx r0
	.align 2, 0
_081E25EC: .4byte 0x03002C6C

	thumb_func_start FUN_081e25f0
FUN_081e25f0: @ 0x081E25F0
	push {lr}
	ldr r0, _081E2608 @ =0x03002C6C
	ldr r2, [r0]
	cmp r2, #0
	beq _081E2604
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r0, [r2, #0x64]
	orrs r0, r1
	str r0, [r2, #0x64]
_081E2604:
	pop {r0}
	bx r0
	.align 2, 0
_081E2608: .4byte 0x03002C6C

	thumb_func_start FUN_081e260c
FUN_081e260c: @ 0x081E260C
	push {lr}
	ldr r0, _081E2624 @ =0x03002C6C
	ldr r2, [r0]
	cmp r2, #0
	beq _081E2620
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r2, #0x64]
	orrs r0, r1
	str r0, [r2, #0x64]
_081E2620:
	pop {r0}
	bx r0
	.align 2, 0
_081E2624: .4byte 0x03002C6C

	thumb_func_start FUN_081e2628
FUN_081e2628: @ 0x081E2628
	push {r4, r5, r6, lr}
	movs r1, #0xaf
	lsls r1, r1, #4
	adds r2, r0, r1
	movs r1, #0
	strh r1, [r2]
	ldr r3, _081E2730 @ =0x00000AF2
	adds r2, r0, r3
	movs r1, #1
	strh r1, [r2]
	ldr r6, _081E2734 @ =0x00000AF4
	adds r2, r0, r6
	movs r1, #2
	strh r1, [r2]
	ldr r1, _081E2738 @ =0x00000AF6
	adds r2, r0, r1
	movs r1, #3
	strh r1, [r2]
	ldr r2, _081E273C @ =0x00000AF8
	adds r1, r0, r2
	movs r5, #4
	strh r5, [r1]
	adds r3, #8
	adds r1, r0, r3
	movs r4, #5
	strh r4, [r1]
	adds r6, #8
	adds r2, r0, r6
	movs r1, #6
	strh r1, [r2]
	ldr r1, _081E2740 @ =0x00000AFE
	adds r2, r0, r1
	movs r1, #7
	strh r1, [r2]
	adds r3, #6
	adds r2, r0, r3
	movs r1, #8
	strh r1, [r2]
	adds r6, #6
	adds r2, r0, r6
	movs r1, #9
	strh r1, [r2]
	ldr r1, _081E2744 @ =0x00000B04
	adds r2, r0, r1
	movs r1, #0xb
	strh r1, [r2]
	adds r3, #6
	adds r2, r0, r3
	movs r1, #0xc
	strh r1, [r2]
	adds r6, #6
	adds r2, r0, r6
	movs r1, #0xd
	strh r1, [r2]
	ldr r1, _081E2748 @ =0x00000B0A
	adds r2, r0, r1
	movs r1, #0xe
	strh r1, [r2]
	adds r3, #6
	adds r2, r0, r3
	movs r1, #0xf
	strh r1, [r2]
	adds r6, #6
	adds r2, r0, r6
	movs r1, #0x10
	strh r1, [r2]
	movs r1, #0xb1
	lsls r1, r1, #4
	adds r2, r0, r1
	movs r1, #0x11
	strh r1, [r2]
	adds r3, #6
	adds r2, r0, r3
	movs r1, #0x12
	strh r1, [r2]
	adds r6, #6
	adds r2, r0, r6
	movs r1, #0x13
	strh r1, [r2]
	ldr r1, _081E274C @ =0x00000B16
	adds r2, r0, r1
	movs r1, #0x14
	strh r1, [r2]
	adds r3, #6
	adds r2, r0, r3
	movs r1, #0x16
	strh r1, [r2]
	adds r6, #6
	adds r2, r0, r6
	movs r1, #0x17
	strh r1, [r2]
	ldr r1, _081E2750 @ =0x00000B1C
	adds r2, r0, r1
	movs r1, #0x18
	strh r1, [r2]
	adds r3, #6
	adds r2, r0, r3
	movs r1, #0x19
	strh r1, [r2]
	adds r6, #0x14
	adds r2, r0, r6
	movs r1, #0x15
	strh r1, [r2]
	movs r1, #0xb2
	lsls r1, r1, #4
	adds r2, r0, r1
	movs r1, #0x3c
	strh r1, [r2]
	ldr r2, _081E2754 @ =0x00000B22
	adds r1, r0, r2
	movs r2, #0x41
	strh r2, [r1]
	adds r3, #6
	adds r1, r0, r3
	strh r2, [r1]
	subs r6, #8
	adds r3, r0, r6
	strh r2, [r3]
	adds r6, #2
	adds r1, r0, r6
	strh r2, [r1]
	ldr r2, _081E2758 @ =0x00000B2A
	adds r1, r0, r2
	strh r5, [r1]
	adds r6, #4
	adds r0, r0, r6
	strh r4, [r0]
	movs r0, #0x40
	strh r0, [r3]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E2730: .4byte 0x00000AF2
_081E2734: .4byte 0x00000AF4
_081E2738: .4byte 0x00000AF6
_081E273C: .4byte 0x00000AF8
_081E2740: .4byte 0x00000AFE
_081E2744: .4byte 0x00000B04
_081E2748: .4byte 0x00000B0A
_081E274C: .4byte 0x00000B16
_081E2750: .4byte 0x00000B1C
_081E2754: .4byte 0x00000B22
_081E2758: .4byte 0x00000B2A

	thumb_func_start FUN_081e275c
FUN_081e275c: @ 0x081E275C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r4, _081E27D8 @ =0x0000C091
	ldr r1, _081E27DC @ =0x0000CD91
	adds r0, r4, #0
	bl GetFile
	str r0, [r6, #0x1c]
	ldr r1, _081E27E0 @ =0x0000A413
	adds r0, r4, #0
	bl GetFile
	str r0, [r6, #0x20]
	movs r4, #1
	str r4, [sp, #0xc]
	ldr r2, [r6, #0x1c]
	movs r5, #0
	str r5, [sp]
	str r4, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	movs r0, #3
	str r0, [sp, #0xc]
	ldr r2, [r6, #0x20]
	str r5, [sp]
	str r4, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r5, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _081E27E4 @ =0x000092B3
	ldr r1, _081E27E8 @ =0x000026BB
	bl GetFile
	adds r0, #0x14
	str r0, [r6, #0x24]
	ldr r1, _081E27EC @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E27D8: .4byte 0x0000C091
_081E27DC: .4byte 0x0000CD91
_081E27E0: .4byte 0x0000A413
_081E27E4: .4byte 0x000092B3
_081E27E8: .4byte 0x000026BB
_081E27EC: .4byte 0x03004250

	thumb_func_start FUN_081e27f0
FUN_081e27f0: @ 0x081E27F0
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	ldr r4, _081E284C @ =0x0000CB05
	ldr r1, _081E2850 @ =0x0000DCC1
	adds r0, r4, #0
	bl GetFile
	adds r1, r0, #0
	ldr r2, _081E2854 @ =0x00000AE8
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x40
	adds r0, r5, r2
	bl OpenMainSpriteFile
	ldr r1, _081E2858 @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r1, r0, #0
	ldr r2, _081E285C @ =0x00000AEC
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x24
	adds r0, r5, r2
	bl OpenMainSpriteFile
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _081E2860 @ =0x05000002
	bl CpuSet
	movs r6, #0
_081E283A:
	cmp r6, #0xf
	bgt _081E2868
	movs r1, #0xaf
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrh r2, [r0]
	ldr r0, _081E2864 @ =0x00000AA8
	b _081E2910
	.align 2, 0
_081E284C: .4byte 0x0000CB05
_081E2850: .4byte 0x0000DCC1
_081E2854: .4byte 0x00000AE8
_081E2858: .4byte 0x0000B343
_081E285C: .4byte 0x00000AEC
_081E2860: .4byte 0x05000002
_081E2864: .4byte 0x00000AA8
_081E2868:
	cmp r6, #0x14
	bgt _081E28D4
	adds r0, r6, #0
	subs r0, #0x10
	cmp r0, #4
	bhi _081E28C8
	lsls r0, r0, #2
	ldr r1, _081E2880 @ =_081E2884
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081E2880: .4byte _081E2884
_081E2884: @ jump table
	.4byte _081E2898 @ case 0
	.4byte _081E28A0 @ case 1
	.4byte _081E28A8 @ case 2
	.4byte _081E28B0 @ case 3
	.4byte _081E28BC @ case 4
_081E2898:
	ldr r1, _081E289C @ =0x00000B18
	b _081E28BE
	.align 2, 0
_081E289C: .4byte 0x00000B18
_081E28A0:
	ldr r2, _081E28A4 @ =0x00000B1A
	b _081E28B2
	.align 2, 0
_081E28A4: .4byte 0x00000B1A
_081E28A8:
	ldr r1, _081E28AC @ =0x00000B1C
	b _081E28BE
	.align 2, 0
_081E28AC: .4byte 0x00000B1C
_081E28B0:
	ldr r2, _081E28B8 @ =0x00000B1E
_081E28B2:
	adds r0, r5, r2
	ldrh r2, [r0]
	b _081E28CA
	.align 2, 0
_081E28B8: .4byte 0x00000B1E
_081E28BC:
	ldr r1, _081E28C4 @ =0x00000B2E
_081E28BE:
	adds r0, r5, r1
	ldrh r2, [r0]
	b _081E28CA
	.align 2, 0
_081E28C4: .4byte 0x00000B2E
_081E28C8:
	movs r2, #0
_081E28CA:
	ldr r0, _081E28D0 @ =0x00000AA8
	b _081E2910
	.align 2, 0
_081E28D0: .4byte 0x00000AA8
_081E28D4:
	cmp r6, #0x15
	bgt _081E28EC
	lsls r1, r6, #1
	movs r2, #0xaf
	lsls r2, r2, #4
	adds r0, r5, r2
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r0, _081E28E8 @ =0x00000AC8
	b _081E292E
	.align 2, 0
_081E28E8: .4byte 0x00000AC8
_081E28EC:
	cmp r6, #0x19
	bgt _081E28F8
	ldr r1, _081E28F4 @ =0x00000B22
	b _081E290A
	.align 2, 0
_081E28F4: .4byte 0x00000B22
_081E28F8:
	cmp r6, #0x1a
	bgt _081E2904
	ldr r1, _081E2900 @ =0x00000B2A
	b _081E290A
	.align 2, 0
_081E2900: .4byte 0x00000B2A
_081E2904:
	cmp r6, #0x1b
	bgt _081E2920
	ldr r1, _081E2918 @ =0x00000B26
_081E290A:
	adds r0, r5, r1
	ldrh r2, [r0]
	ldr r0, _081E291C @ =0x00000AC8
_081E2910:
	adds r3, r5, r0
	lsls r1, r6, #1
	b _081E2930
	.align 2, 0
_081E2918: .4byte 0x00000B26
_081E291C: .4byte 0x00000AC8
_081E2920:
	lsls r1, r6, #1
	movs r2, #0xaf
	lsls r2, r2, #4
	adds r0, r5, r2
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r0, _081E295C @ =0x00000AA8
_081E292E:
	adds r3, r5, r0
_081E2930:
	adds r0, r1, r6
	lsls r0, r0, #5
	adds r0, #0x28
	adds r0, r5, r0
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	adds r1, r3, #0
	movs r3, #0x10
	bl MainSprite_Add
	adds r6, #1
	cmp r6, #0x1b
	bgt _081E2952
	b _081E283A
_081E2952:
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E295C: .4byte 0x00000AA8

	thumb_func_start FUN_081e2960
FUN_081e2960: @ 0x081E2960
	push {r4, lr}
	adds r4, r0, #0
	movs r3, #0
_081E2966:
	cmp r3, #0xf
	bls _081E296C
	b _081E2AF8
_081E296C:
	lsls r0, r3, #2
	ldr r1, _081E2978 @ =_081E297C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081E2978: .4byte _081E297C
_081E297C: @ jump table
	.4byte _081E29BC @ case 0
	.4byte _081E29D2 @ case 1
	.4byte _081E29E8 @ case 2
	.4byte _081E29FE @ case 3
	.4byte _081E2A14 @ case 4
	.4byte _081E2A2A @ case 5
	.4byte _081E2A40 @ case 6
	.4byte _081E2A56 @ case 7
	.4byte _081E2A6C @ case 8
	.4byte _081E2A7C @ case 9
	.4byte _081E2A8C @ case 10
	.4byte _081E2A9C @ case 11
	.4byte _081E2AB2 @ case 12
	.4byte _081E2AC2 @ case 13
	.4byte _081E2AD2 @ case 14
	.4byte _081E2AE2 @ case 15
_081E29BC:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0x58
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E29D2:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0x50
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E29E8:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0x48
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E29FE:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0x40
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E2A14:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xd8
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E2A2A:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xd0
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E2A40:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xc8
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E2A56:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xc0
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x38
	b _081E2AF6
_081E2A6C:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0x40
	b _081E2AF0
_081E2A7C:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0x38
	b _081E2AF0
_081E2A8C:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0x58
	b _081E2AF0
_081E2A9C:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r1, r0, #0
	adds r1, #0x48
	movs r2, #0x50
	strh r2, [r1]
	adds r0, #0x4a
	strh r2, [r0]
	b _081E2AF8
_081E2AB2:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xc0
	b _081E2AF0
_081E2AC2:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xb8
	b _081E2AF0
_081E2AD2:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xd8
	b _081E2AF0
_081E2AE2:
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #5
	adds r0, r4, r0
	adds r2, r0, #0
	adds r2, #0x48
	movs r1, #0xd0
_081E2AF0:
	strh r1, [r2]
	adds r0, #0x4a
	movs r1, #0x50
_081E2AF6:
	strh r1, [r0]
_081E2AF8:
	adds r3, #1
	cmp r3, #0xf
	bgt _081E2B00
	b _081E2966
_081E2B00:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e2b08
FUN_081e2b08: @ 0x081E2B08
	ldr r1, [r0, #0x30]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #0x30]
	adds r3, r0, #0
	adds r3, #0x90
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	adds r3, #0x60
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0x84
	lsls r1, r1, #2
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xcc
	lsls r1, r1, #2
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xfc
	lsls r1, r1, #2
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0x8a
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0x96
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xa2
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xae
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xba
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xc6
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xde
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xea
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0x9f
	lsls r1, r1, #4
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xf6
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r3]
	orrs r1, r2
	str r1, [r3]
	movs r1, #0xa5
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r0]
	orrs r1, r2
	str r1, [r0]
	bx lr

	thumb_func_start FUN_081e2c14
FUN_081e2c14: @ 0x081E2C14
	adds r3, r0, #0
	ldr r0, [r3, #0x30]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0x30]
	adds r2, r3, #0
	adds r2, #0x90
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r2, #0x60
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xa8
	lsls r0, r0, #1
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xd8
	lsls r0, r0, #1
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x84
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xcc
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xe4
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xfc
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x8a
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x96
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xa2
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xae
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xba
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xc6
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	bx lr

	thumb_func_start FUN_081e2cdc
FUN_081e2cdc: @ 0x081E2CDC
	adds r3, r0, #0
	ldr r0, [r3, #0x30]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0x30]
	adds r2, r3, #0
	adds r2, #0x90
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r2, #0x60
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xa8
	lsls r0, r0, #1
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xd8
	lsls r0, r0, #1
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x84
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xb4
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xcc
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xe4
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xfc
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x8a
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x96
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xa2
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xae
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xba
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	bx lr

	thumb_func_start FUN_081e2d98
FUN_081e2d98: @ 0x081E2D98
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, #1
	orrs r1, r3
	str r1, [r2]
	movs r1, #0xde
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	movs r1, #0xea
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	movs r1, #0xf6
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	movs r1, #0xa5
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r0]
	orrs r1, r3
	str r1, [r0]
	bx lr

	thumb_func_start FUN_081e2dd8
FUN_081e2dd8: @ 0x081E2DD8
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, #1
	orrs r1, r3
	str r1, [r2]
	movs r1, #0xc6
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	movs r1, #0xde
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	movs r1, #0xea
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	movs r1, #0xf6
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	movs r1, #0xa5
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, [r0]
	orrs r1, r3
	str r1, [r0]
	bx lr

	thumb_func_start FUN_081e2e24
FUN_081e2e24: @ 0x081E2E24
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _081E2E78 @ =0x00001590
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	ldr r2, _081E2E7C @ =0x00000E28
	adds r1, r4, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	bl Textbox_LookupString
	movs r3, #0
	ldrb r1, [r0]
	cmp r1, #0
	beq _081E2E68
	cmp r1, #0x3c
	beq _081E2E68
	ldr r1, _081E2E80 @ =0x000015A4
	adds r5, r4, r1
	adds r2, r0, #0
_081E2E50:
	adds r1, r5, r3
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, #1
	adds r3, #1
	ldrb r0, [r2]
	cmp r0, #0
	beq _081E2E68
	cmp r3, #0xf
	bgt _081E2E68
	cmp r0, #0x3c
	bne _081E2E50
_081E2E68:
	ldr r2, _081E2E80 @ =0x000015A4
	adds r0, r4, r2
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E2E78: .4byte 0x00001590
_081E2E7C: .4byte 0x00000E28
_081E2E80: .4byte 0x000015A4

	thumb_func_start FUN_081e2e84
FUN_081e2e84: @ 0x081E2E84
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081E2EA0
	bl FUN_0823d340
	ldr r2, _081E2ED4 @ =0x000015F0
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	beq _081E2ED0
_081E2EA0:
	movs r0, #0x77
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081E2EB8
	bl FUN_0823d340
	ldr r2, _081E2ED8 @ =0x00001590
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	beq _081E2ED0
_081E2EB8:
	movs r0, #0x59
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081E2EE0
	bl FUN_0823d340
	ldr r2, _081E2EDC @ =0x000015F4
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	bne _081E2EE0
_081E2ED0:
	movs r0, #0
	b _081E2EE2
	.align 2, 0
_081E2ED4: .4byte 0x000015F0
_081E2ED8: .4byte 0x00001590
_081E2EDC: .4byte 0x000015F4
_081E2EE0:
	movs r0, #1
_081E2EE2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e2ee8
FUN_081e2ee8: @ 0x081E2EE8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #1
	ldr r2, _081E2F00 @ =0x00001610
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E2F04
	movs r0, #1
	b _081E2F06
	.align 2, 0
_081E2F00: .4byte 0x00001610
_081E2F04:
	movs r0, #0
_081E2F06:
	cmp r0, #0
	bne _081E2F24
	bl FUN_08049f5c
	bl FUN_08049e5c
	movs r2, #1
	ldr r0, _081E2F20 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081E32C8
	.align 2, 0
_081E2F20: .4byte 0x00001610
_081E2F24:
	ldr r1, _081E2F60 @ =0x00001616
	adds r4, r5, r1
	ldrb r0, [r4]
	cmp r0, #0x16
	beq _081E2F36
	cmp r0, #0x13
	beq _081E2F36
	cmp r0, #0xa
	bne _081E2F6C
_081E2F36:
	ldr r2, _081E2F64 @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0xa
	bne _081E2F44
	b _081E32C8
_081E2F44:
	bl FUN_08049e5c
	ldr r1, _081E2F68 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0xa
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #0xa
	b _081E32C6
	.align 2, 0
_081E2F60: .4byte 0x00001616
_081E2F64: .4byte 0x00001617
_081E2F68: .4byte 0x000015F0
_081E2F6C:
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E2F8C
	ldrb r0, [r4]
	cmp r0, #2
	beq _081E2F8C
	cmp r0, #0x15
	beq _081E2F8C
	cmp r0, #8
	beq _081E2F8C
	cmp r0, #0x1d
	beq _081E2F8C
	cmp r0, #5
	bne _081E2FC0
_081E2F8C:
	ldr r2, _081E2FB8 @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #7
	bne _081E2F9A
	b _081E32C8
_081E2F9A:
	bl FUN_08049e5c
	ldr r1, _081E2FBC @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #7
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #7
	b _081E32C6
	.align 2, 0
_081E2FB8: .4byte 0x00001617
_081E2FBC: .4byte 0x000015F0
_081E2FC0:
	bl FUN_081e23e4
	cmp r0, #0
	bne _081E2FCA
	b _081E3154
_081E2FCA:
	ldrb r0, [r4]
	cmp r0, #0
	beq _081E2FD2
	b _081E3184
_081E2FD2:
	ldr r2, _081E3018 @ =0x00001615
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E309C
	ldr r1, _081E301C @ =0x00000BB5
	adds r0, r5, r1
	ldrb r0, [r0]
	ldr r2, _081E3020 @ =0x00000BB4
	adds r1, r5, r2
	ldrb r1, [r1]
	subs r0, r0, r1
	cmp r0, #0
	bgt _081E302C
	ldr r0, _081E3024 @ =0x00001617
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #5
	bne _081E2FFC
	b _081E32C8
_081E2FFC:
	bl FUN_08049e5c
	ldr r1, _081E3028 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #5
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #5
	b _081E3182
	.align 2, 0
_081E3018: .4byte 0x00001615
_081E301C: .4byte 0x00000BB5
_081E3020: .4byte 0x00000BB4
_081E3024: .4byte 0x00001617
_081E3028: .4byte 0x000015F0
_081E302C:
	bl FUN_08243104
	cmp r0, #0
	bgt _081E3068
	ldr r2, _081E3060 @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0x14
	bne _081E3042
	b _081E32C8
_081E3042:
	bl FUN_08049e5c
	ldr r1, _081E3064 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0x14
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #0x14
	b _081E3182
	.align 2, 0
_081E3060: .4byte 0x00001617
_081E3064: .4byte 0x000015F0
_081E3068:
	ldr r2, _081E3094 @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #3
	bne _081E3076
	b _081E32C8
_081E3076:
	bl FUN_08049e5c
	ldr r1, _081E3098 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #3
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #3
	b _081E3182
	.align 2, 0
_081E3094: .4byte 0x00001617
_081E3098: .4byte 0x000015F0
_081E309C:
	bl FUN_08243140
	adds r4, r0, #0
	bl FUN_08243104
	subs r4, r4, r0
	cmp r4, #0
	bgt _081E30E0
	ldr r2, _081E30D8 @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #6
	bne _081E30BA
	b _081E32C8
_081E30BA:
	bl FUN_08049e5c
	ldr r1, _081E30DC @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #6
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #6
	b _081E3182
	.align 2, 0
_081E30D8: .4byte 0x00001617
_081E30DC: .4byte 0x000015F0
_081E30E0:
	ldr r2, _081E3114 @ =0x00000BB4
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E3120
	ldr r0, _081E3118 @ =0x00001617
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0x15
	bne _081E30F8
	b _081E32C8
_081E30F8:
	bl FUN_08049e5c
	ldr r1, _081E311C @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0x15
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #0x15
	b _081E3182
	.align 2, 0
_081E3114: .4byte 0x00000BB4
_081E3118: .4byte 0x00001617
_081E311C: .4byte 0x000015F0
_081E3120:
	ldr r2, _081E314C @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #4
	bne _081E312E
	b _081E32C8
_081E312E:
	bl FUN_08049e5c
	ldr r1, _081E3150 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #4
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #4
	b _081E3182
	.align 2, 0
_081E314C: .4byte 0x00001617
_081E3150: .4byte 0x000015F0
_081E3154:
	ldrb r0, [r4]
	cmp r0, #1
	bne _081E3184
	ldr r2, _081E31BC @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #2
	bne _081E3168
	b _081E32C8
_081E3168:
	bl FUN_08049e5c
	ldr r1, _081E31C0 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #2
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #2
_081E3182:
	strb r0, [r4]
_081E3184:
	ldr r2, _081E31C4 @ =0x00001616
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0xa
	beq _081E3192
	cmp r0, #0xd
	bne _081E31C8
_081E3192:
	ldr r0, _081E31BC @ =0x00001617
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0xa
	bne _081E31A0
	b _081E32C8
_081E31A0:
	bl FUN_08049e5c
	ldr r1, _081E31C0 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0xa
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #0xa
	b _081E32C6
	.align 2, 0
_081E31BC: .4byte 0x00001617
_081E31C0: .4byte 0x000015F0
_081E31C4: .4byte 0x00001616
_081E31C8:
	cmp r0, #3
	bne _081E31E4
	ldr r2, _081E31DC @ =0x00001617
	adds r6, r5, r2
	movs r1, #0
	ldrsb r1, [r6, r1]
	ldr r0, _081E31E0 @ =0x0000161A
	adds r4, r5, r0
	b _081E3230
	.align 2, 0
_081E31DC: .4byte 0x00001617
_081E31E0: .4byte 0x0000161A
_081E31E4:
	cmp r0, #4
	bne _081E324C
	ldr r1, _081E321C @ =0x0000161A
	adds r4, r5, r1
	ldrb r0, [r4]
	cmp r0, #0x11
	bne _081E3228
	ldr r2, _081E3220 @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0xf
	beq _081E32C8
	bl FUN_08049e5c
	ldr r1, _081E3224 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0xf
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #0xf
	b _081E32C6
	.align 2, 0
_081E321C: .4byte 0x0000161A
_081E3220: .4byte 0x00001617
_081E3224: .4byte 0x000015F0
_081E3228:
	ldr r2, _081E3248 @ =0x00001617
	adds r6, r5, r2
	movs r1, #0
	ldrsb r1, [r6, r1]
_081E3230:
	ldrb r0, [r4]
	adds r0, #0x19
	cmp r1, r0
	beq _081E32C8
	adds r0, r5, #0
	bl FUN_081e4544
	ldrb r0, [r4]
	adds r0, #0x19
	strb r0, [r6]
	b _081E32C8
	.align 2, 0
_081E3248: .4byte 0x00001617
_081E324C:
	cmp r0, #7
	bne _081E32C8
	ldr r0, _081E3290 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _081E3294 @ =0x000015E4
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r1, r0
	blt _081E32A0
	ldr r0, _081E3298 @ =0x00001617
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0x10
	beq _081E32C8
	bl FUN_08049e5c
	ldr r1, _081E329C @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0x10
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #0x10
	b _081E32C6
	.align 2, 0
_081E3290: .4byte 0x030046A0
_081E3294: .4byte 0x000015E4
_081E3298: .4byte 0x00001617
_081E329C: .4byte 0x000015F0
_081E32A0:
	ldr r2, _081E32D0 @ =0x00001617
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0x11
	beq _081E32C8
	bl FUN_08049e5c
	ldr r1, _081E32D4 @ =0x000015F0
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0x11
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #0x11
_081E32C6:
	strb r0, [r4]
_081E32C8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E32D0: .4byte 0x00001617
_081E32D4: .4byte 0x000015F0

	thumb_func_start FUN_081e32d8
FUN_081e32d8: @ 0x081E32D8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	movs r1, #4
	ldr r2, _081E32F4 @ =0x00001610
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E32F8
	movs r0, #1
	b _081E32FA
	.align 2, 0
_081E32F4: .4byte 0x00001610
_081E32F8:
	movs r0, #0
_081E32FA:
	cmp r0, #0
	bne _081E3300
	b _081E3422
_081E3300:
	movs r6, #0
	ldr r0, _081E3430 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x91
	lsls r3, r3, #4
	adds r0, r0, r3
	movs r1, #0
	ldrsh r4, [r0, r1]
	movs r2, #0
	ldr r0, _081E3434 @ =0x000003E7
	adds r7, r5, #0
	adds r7, #0xe8
	movs r3, #0x88
	adds r3, r3, r5
	mov r8, r3
	movs r1, #0x28
	adds r1, r1, r5
	mov sb, r1
	cmp r4, r0
	ble _081E3332
	ldr r1, _081E3438 @ =0xFFFFFC18
_081E332A:
	adds r2, #1
	adds r4, r4, r1
	cmp r4, r0
	bgt _081E332A
_081E3332:
	movs r3, #0xa4
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r3, _081E343C @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	adds r2, r6, #0
	cmp r4, #0x63
	ble _081E3352
_081E334A:
	adds r2, #1
	subs r4, #0x64
	cmp r4, #0x63
	bgt _081E334A
_081E3352:
	ldr r0, _081E343C @ =0x00000AA8
	adds r1, r5, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r7, #0
	bl MainSprite_LoadPose
	adds r2, r6, #0
	cmp r4, #9
	ble _081E336E
_081E3366:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E3366
_081E336E:
	ldr r3, _081E343C @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r0, r8
	bl MainSprite_LoadPose
	adds r2, r6, #0
	cmp r4, #0
	ble _081E338A
_081E3382:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E3382
_081E338A:
	ldr r0, _081E343C @ =0x00000AA8
	adds r1, r5, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r0, sb
	bl MainSprite_LoadPose
	ldr r1, _081E3440 @ =0x00000BB6
	adds r0, r5, r1
	ldrh r4, [r0]
	adds r2, r6, #0
	ldr r0, _081E3434 @ =0x000003E7
	cmp r4, r0
	ble _081E33B0
	ldr r1, _081E3438 @ =0xFFFFFC18
_081E33A8:
	adds r2, #1
	adds r4, r4, r1
	cmp r4, r0
	bgt _081E33A8
_081E33B0:
	movs r3, #0xb2
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r3, _081E343C @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	adds r2, r6, #0
	cmp r4, #0x63
	ble _081E33D0
_081E33C8:
	adds r2, #1
	subs r4, #0x64
	cmp r4, #0x63
	bgt _081E33C8
_081E33D0:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r3, _081E343C @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	adds r2, r6, #0
	cmp r4, #9
	ble _081E33F0
_081E33E8:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E33E8
_081E33F0:
	movs r1, #0x82
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r3, _081E343C @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	adds r2, r6, #0
	cmp r4, #0
	ble _081E3410
_081E3408:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E3408
_081E3410:
	movs r1, #0xd4
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r3, _081E343C @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
_081E3422:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E3430: .4byte 0x030046A0
_081E3434: .4byte 0x000003E7
_081E3438: .4byte 0xFFFFFC18
_081E343C: .4byte 0x00000AA8
_081E3440: .4byte 0x00000BB6

	thumb_func_start FUN_081e3444
FUN_081e3444: @ 0x081E3444
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #8
	ldr r2, _081E345C @ =0x00001610
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E3460
	movs r0, #1
	b _081E3462
	.align 2, 0
_081E345C: .4byte 0x00001610
_081E3460:
	movs r0, #0
_081E3462:
	cmp r0, #0
	bne _081E3468
	b _081E3582
_081E3468:
	movs r6, #0
	bl FUN_08243104
	adds r4, r0, #0
	movs r2, #0
	cmp r4, #9
	ble _081E347E
_081E3476:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E3476
_081E347E:
	movs r3, #0xe2
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	adds r2, r6, #0
	cmp r4, #0
	ble _081E349E
_081E3496:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E3496
_081E349E:
	movs r1, #0xca
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	bl FUN_08243140
	adds r4, r0, #0
	adds r2, r6, #0
	cmp r4, #9
	ble _081E34C4
_081E34BC:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E34BC
_081E34C4:
	movs r1, #0x89
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	adds r2, r6, #0
	cmp r4, #0
	ble _081E34E4
_081E34DC:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E34DC
_081E34E4:
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	ldr r1, _081E358C @ =0x00000BB4
	adds r0, r5, r1
	ldrb r4, [r0]
	adds r2, r6, #0
	cmp r4, #9
	ble _081E350A
_081E3502:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E3502
_081E350A:
	movs r3, #0xa1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	adds r2, r6, #0
	cmp r4, #0
	ble _081E352A
_081E3522:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E3522
_081E352A:
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	ldr r1, _081E3590 @ =0x00000BB5
	adds r0, r5, r1
	ldrb r4, [r0]
	adds r2, r6, #0
	cmp r4, #9
	ble _081E3550
_081E3548:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E3548
_081E3550:
	movs r3, #0xb9
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	adds r2, r6, #0
	cmp r4, #0
	ble _081E3570
_081E3568:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E3568
_081E3570:
	movs r1, #0xad
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
_081E3582:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E3588: .4byte 0x00000AA8
_081E358C: .4byte 0x00000BB4
_081E3590: .4byte 0x00000BB5

	thumb_func_start FUN_081e3594
FUN_081e3594: @ 0x081E3594
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, _081E367C @ =0x00000AA8
	adds r4, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	adds r0, r5, #0
	adds r0, #0xe8
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	adds r0, r5, #0
	adds r0, #0x88
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	adds r0, r5, #0
	adds r0, #0x28
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0x82
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0xd4
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0xca
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0x89
	lsls r1, r1, #3
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0xa1
	lsls r1, r1, #3
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0xad
	lsls r1, r1, #3
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E367C: .4byte 0x00000AA8

	thumb_func_start FUN_081e3680
FUN_081e3680: @ 0x081E3680
	adds r3, r0, #0
	movs r0, #0xb4
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0x40
	strh r0, [r1]
	movs r1, #0xb5
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0x68
	strh r2, [r0]
	movs r0, #0x84
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0x48
	strh r0, [r1]
	movs r1, #0x85
	lsls r1, r1, #1
	adds r0, r3, r1
	strh r2, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #0x50
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0xaa
	strh r2, [r0]
	subs r1, #0x60
	movs r0, #0x58
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x4a
	strh r2, [r0]
	ldr r0, [r3, #0x30]
	subs r2, #0x6a
	ands r0, r2
	str r0, [r3, #0x30]
	adds r1, #0x48
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r1, #0x60
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r0, #0xa8
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	bx lr

	thumb_func_start FUN_081e36e8
FUN_081e36e8: @ 0x081E36E8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081e3680
	ldr r0, _081E370C @ =0x000015E2
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _081E3710 @ =0x000015BC
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #0x24
	bl ClearMemory
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E370C: .4byte 0x000015E2
_081E3710: .4byte 0x000015BC

	thumb_func_start FUN_081e3714
FUN_081e3714: @ 0x081E3714
	push {lr}
	ldr r1, _081E3748 @ =0x000015E7
	adds r2, r0, r1
	movs r1, #3
	strb r1, [r2]
	ldr r2, _081E374C @ =0x000015E8
	adds r1, r0, r2
	movs r2, #9
	strb r2, [r1]
	ldr r3, _081E3750 @ =0x000015E9
	adds r1, r0, r3
	strb r2, [r1]
	adds r3, #1
	adds r1, r0, r3
	strb r2, [r1]
	adds r3, #1
	adds r1, r0, r3
	strb r2, [r1]
	ldr r1, _081E3754 @ =0x000015EC
	adds r0, r0, r1
	movs r1, #4
	bl ClearMemory
	pop {r0}
	bx r0
	.align 2, 0
_081E3748: .4byte 0x000015E7
_081E374C: .4byte 0x000015E8
_081E3750: .4byte 0x000015E9
_081E3754: .4byte 0x000015EC

	thumb_func_start FUN_081e3758
FUN_081e3758: @ 0x081E3758
	adds r2, r0, #0
	ldr r0, _081E3790 @ =0x000015EC
	adds r3, r2, r0
	ldr r1, _081E3794 @ =0x000015ED
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	ldrb r3, [r3]
	adds r0, r0, r3
	ldr r3, _081E3798 @ =0x000015EE
	adds r1, r2, r3
	ldrb r3, [r1]
	movs r1, #0x64
	muls r1, r3, r1
	adds r0, r0, r1
	ldr r1, _081E379C @ =0x000015EF
	adds r2, r2, r1
	ldrb r2, [r2]
	lsls r1, r2, #5
	subs r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r0, r0, r1
	bx lr
	.align 2, 0
_081E3790: .4byte 0x000015EC
_081E3794: .4byte 0x000015ED
_081E3798: .4byte 0x000015EE
_081E379C: .4byte 0x000015EF

	thumb_func_start FUN_081e37a0
FUN_081e37a0: @ 0x081E37A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r2, #0
	ldr r0, _081E37F0 @ =0x000003E7
	cmp r4, r0
	ble _081E37BC
	ldr r1, _081E37F4 @ =0xFFFFFC18
_081E37B4:
	adds r2, #1
	adds r4, r4, r1
	cmp r4, r0
	bgt _081E37B4
_081E37BC:
	ldr r1, _081E37F8 @ =0x000015E6
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	bne _081E3804
	ldr r3, _081E37FC @ =0x00001616
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #7
	bne _081E3804
	movs r6, #0xa4
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r7, _081E3800 @ =0x00000AA8
	adds r1, r5, r7
	adds r3, r2, #0
	adds r3, #0xa
	lsls r3, r3, #1
	movs r6, #0xaf
	lsls r6, r6, #4
	adds r2, r5, r6
	adds r2, r2, r3
	ldrh r2, [r2]
	bl MainSprite_LoadPose
	b _081E381E
	.align 2, 0
_081E37F0: .4byte 0x000003E7
_081E37F4: .4byte 0xFFFFFC18
_081E37F8: .4byte 0x000015E6
_081E37FC: .4byte 0x00001616
_081E3800: .4byte 0x00000AA8
_081E3804:
	movs r7, #0xa4
	lsls r7, r7, #1
	adds r0, r5, r7
	ldr r3, _081E3868 @ =0x00000AA8
	adds r1, r5, r3
	lsls r3, r2, #1
	movs r6, #0xaf
	lsls r6, r6, #4
	adds r2, r5, r6
	adds r2, r2, r3
	ldrh r2, [r2]
	bl MainSprite_LoadPose
_081E381E:
	movs r2, #0
	adds r3, r5, #0
	adds r3, #0xe8
	adds r6, r5, #0
	adds r6, #0x88
	movs r7, #0x28
	adds r7, r7, r5
	mov r8, r7
	cmp r4, #0x63
	ble _081E383A
_081E3832:
	adds r2, #1
	subs r4, #0x64
	cmp r4, #0x63
	bgt _081E3832
_081E383A:
	ldr r1, _081E386C @ =0x000015E6
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #2
	bne _081E3874
	ldr r7, _081E3870 @ =0x00001616
	adds r0, r5, r7
	ldrb r0, [r0]
	cmp r0, #7
	bne _081E3874
	ldr r0, _081E3868 @ =0x00000AA8
	adds r1, r5, r0
	adds r2, #0xa
	lsls r2, r2, #1
	movs r7, #0xaf
	lsls r7, r7, #4
	adds r0, r5, r7
	adds r0, r0, r2
	ldrh r2, [r0]
	adds r0, r3, #0
	bl MainSprite_LoadPose
	b _081E388A
	.align 2, 0
_081E3868: .4byte 0x00000AA8
_081E386C: .4byte 0x000015E6
_081E3870: .4byte 0x00001616
_081E3874:
	ldr r0, _081E38C8 @ =0x00000AA8
	adds r1, r5, r0
	lsls r2, r2, #1
	movs r7, #0xaf
	lsls r7, r7, #4
	adds r0, r5, r7
	adds r0, r0, r2
	ldrh r2, [r0]
	adds r0, r3, #0
	bl MainSprite_LoadPose
_081E388A:
	movs r2, #0
	cmp r4, #9
	ble _081E3898
_081E3890:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E3890
_081E3898:
	ldr r1, _081E38CC @ =0x000015E6
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _081E38D4
	ldr r3, _081E38D0 @ =0x00001616
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #7
	bne _081E38D4
	ldr r7, _081E38C8 @ =0x00000AA8
	adds r1, r5, r7
	adds r2, #0xa
	lsls r2, r2, #1
	movs r3, #0xaf
	lsls r3, r3, #4
	adds r0, r5, r3
	adds r0, r0, r2
	ldrh r2, [r0]
	adds r0, r6, #0
	bl MainSprite_LoadPose
	b _081E38EA
	.align 2, 0
_081E38C8: .4byte 0x00000AA8
_081E38CC: .4byte 0x000015E6
_081E38D0: .4byte 0x00001616
_081E38D4:
	ldr r7, _081E3928 @ =0x00000AA8
	adds r1, r5, r7
	lsls r2, r2, #1
	movs r3, #0xaf
	lsls r3, r3, #4
	adds r0, r5, r3
	adds r0, r0, r2
	ldrh r2, [r0]
	adds r0, r6, #0
	bl MainSprite_LoadPose
_081E38EA:
	movs r2, #0
	cmp r4, #0
	ble _081E38F8
_081E38F0:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E38F0
_081E38F8:
	ldr r6, _081E392C @ =0x000015E6
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E3934
	ldr r7, _081E3930 @ =0x00001616
	adds r0, r5, r7
	ldrb r0, [r0]
	cmp r0, #7
	bne _081E3934
	ldr r0, _081E3928 @ =0x00000AA8
	adds r1, r5, r0
	adds r2, #0xa
	lsls r2, r2, #1
	movs r3, #0xaf
	lsls r3, r3, #4
	adds r0, r5, r3
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r0, r8
	bl MainSprite_LoadPose
	b _081E394A
	.align 2, 0
_081E3928: .4byte 0x00000AA8
_081E392C: .4byte 0x000015E6
_081E3930: .4byte 0x00001616
_081E3934:
	ldr r6, _081E3954 @ =0x00000AA8
	adds r1, r5, r6
	lsls r2, r2, #1
	movs r7, #0xaf
	lsls r7, r7, #4
	adds r0, r5, r7
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r0, r8
	bl MainSprite_LoadPose
_081E394A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E3954: .4byte 0x00000AA8

	thumb_func_start FUN_081e3958
FUN_081e3958: @ 0x081E3958
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r1, #0
	cmp r0, #0
	bne _081E3968
	b _081E3CAC
_081E3968:
	adds r4, r0, #0
	ldrh r0, [r6]
	adds r1, r0, #0
	cmp r1, #0
	bne _081E3976
	movs r0, #1
	b _081E3978
_081E3976:
	movs r0, #0
_081E3978:
	cmp r0, #0
	beq _081E398C
	ldr r1, [r6, #4]
	ldr r2, _081E3988 @ =0x00000BB6
	adds r0, r4, r2
	strh r1, [r0]
	movs r2, #4
	b _081E3C9E
	.align 2, 0
_081E3988: .4byte 0x00000BB6
_081E398C:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _081E3998
	movs r0, #1
	b _081E399A
_081E3998:
	movs r0, #0
_081E399A:
	cmp r0, #0
	beq _081E39E8
	adds r1, r6, #4
	movs r3, #0
	ldrb r0, [r6, #4]
	ldr r5, _081E39E0 @ =0x00001610
	adds r5, r5, r4
	mov sb, r5
	cmp r0, #0
	beq _081E39C8
	ldr r7, _081E39E4 @ =0x00000BB8
	adds r5, r4, r7
	adds r2, r1, #0
_081E39B4:
	adds r0, r5, r3
	ldrb r1, [r2]
	strb r1, [r0]
	adds r2, #1
	adds r3, #1
	ldrb r0, [r2]
	cmp r0, #0
	beq _081E39C8
	cmp r3, #0xb
	ble _081E39B4
_081E39C8:
	ldr r1, _081E39E4 @ =0x00000BB8
	adds r0, r4, r1
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0]
	movs r1, #2
	mov r2, sb
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	b _081E3CA8
	.align 2, 0
_081E39E0: .4byte 0x00001610
_081E39E4: .4byte 0x00000BB8
_081E39E8:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bne _081E39F4
	movs r0, #1
	b _081E39F6
_081E39F4:
	movs r0, #0
_081E39F6:
	cmp r0, #0
	beq _081E3A20
	ldr r1, [r6, #4]
	ldr r3, _081E3A14 @ =0x00000BB4
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, [r6, #8]
	ldr r5, _081E3A18 @ =0x00000BB5
	adds r0, r4, r5
	strb r1, [r0]
	movs r2, #8
	ldr r7, _081E3A1C @ =0x00001610
	adds r1, r4, r7
	b _081E3CA2
	.align 2, 0
_081E3A14: .4byte 0x00000BB4
_081E3A18: .4byte 0x00000BB5
_081E3A1C: .4byte 0x00001610
_081E3A20:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xa
	bne _081E3A2C
	movs r0, #1
	b _081E3A2E
_081E3A2C:
	movs r0, #0
_081E3A2E:
	cmp r0, #0
	beq _081E3A60
	ldr r0, [r6, #4]
	movs r2, #0xb1
	lsls r2, r2, #5
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #0x80
	ldr r5, _081E3A5C @ =0x00001610
	adds r3, r4, r5
	ldr r2, [r3]
	orrs r2, r0
	str r2, [r3]
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, #4
	beq _081E3A52
	b _081E3CA8
_081E3A52:
	movs r0, #0x80
	lsls r0, r0, #0xd
	orrs r2, r0
	str r2, [r3]
	b _081E3CA8
	.align 2, 0
_081E3A5C: .4byte 0x00001610
_081E3A60:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bne _081E3A6C
	movs r0, #1
	b _081E3A6E
_081E3A6C:
	movs r0, #0
_081E3A6E:
	cmp r0, #0
	beq _081E3B40
	ldr r1, [r6, #4]
	ldr r2, _081E3A84 @ =0x000015BC
	adds r0, r4, r2
	strb r1, [r0]
	cmp r1, #0
	blt _081E3A88
	asrs r2, r1, #8
	b _081E3A8E
	.align 2, 0
_081E3A84: .4byte 0x000015BC
_081E3A88:
	rsbs r0, r1, #0
	asrs r0, r0, #8
	rsbs r2, r0, #0
_081E3A8E:
	ldr r3, _081E3A9C @ =0x000015BD
	adds r0, r4, r3
	strb r2, [r0]
	cmp r1, #0
	blt _081E3AA0
	asrs r2, r1, #0x10
	b _081E3AA6
	.align 2, 0
_081E3A9C: .4byte 0x000015BD
_081E3AA0:
	rsbs r0, r1, #0
	asrs r0, r0, #0x10
	rsbs r2, r0, #0
_081E3AA6:
	ldr r5, _081E3AB4 @ =0x000015BE
	adds r0, r4, r5
	strb r2, [r0]
	cmp r1, #0
	blt _081E3AB8
	asrs r1, r1, #0x18
	b _081E3ABE
	.align 2, 0
_081E3AB4: .4byte 0x000015BE
_081E3AB8:
	rsbs r0, r1, #0
	asrs r0, r0, #0x18
	rsbs r1, r0, #0
_081E3ABE:
	ldr r7, _081E3AD8 @ =0x000015BF
	adds r0, r4, r7
	strb r1, [r0]
	ldr r1, [r6, #8]
	movs r2, #0xae
	lsls r2, r2, #5
	adds r0, r4, r2
	strb r1, [r0]
	cmp r1, #0
	blt _081E3ADC
	asrs r2, r1, #8
	b _081E3AE2
	.align 2, 0
_081E3AD8: .4byte 0x000015BF
_081E3ADC:
	rsbs r0, r1, #0
	asrs r0, r0, #8
	rsbs r2, r0, #0
_081E3AE2:
	ldr r3, _081E3AF0 @ =0x000015C1
	adds r0, r4, r3
	strb r2, [r0]
	cmp r1, #0
	blt _081E3AF4
	asrs r1, r1, #0x10
	b _081E3AFA
	.align 2, 0
_081E3AF0: .4byte 0x000015C1
_081E3AF4:
	rsbs r0, r1, #0
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
_081E3AFA:
	ldr r5, _081E3B10 @ =0x000015C2
	adds r0, r4, r5
	strh r1, [r0]
	ldr r1, [r6, #0xc]
	ldr r7, _081E3B14 @ =0x000015C4
	adds r0, r4, r7
	strh r1, [r0]
	cmp r1, #0
	blt _081E3B18
	asrs r1, r1, #0x10
	b _081E3B1E
	.align 2, 0
_081E3B10: .4byte 0x000015C2
_081E3B14: .4byte 0x000015C4
_081E3B18:
	rsbs r0, r1, #0
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
_081E3B1E:
	ldr r2, _081E3B38 @ =0x000015C6
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r1, [r6, #2]
	movs r3, #0xaf
	lsls r3, r3, #5
	adds r0, r4, r3
	strh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r5, _081E3B3C @ =0x00001610
	adds r1, r4, r5
	b _081E3CA2
	.align 2, 0
_081E3B38: .4byte 0x000015C6
_081E3B3C: .4byte 0x00001610
_081E3B40:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bne _081E3B4C
	movs r0, #1
	b _081E3B4E
_081E3B4C:
	movs r0, #0
_081E3B4E:
	cmp r0, #0
	beq _081E3B7C
	movs r7, #0xaf
	lsls r7, r7, #5
	adds r0, r4, r7
	ldrh r0, [r0]
	ldrh r1, [r6, #2]
	cmp r0, r1
	bne _081E3B9C
	adds r5, r6, #4
	movs r2, #0
	ldr r7, _081E3B78 @ =0x000015C8
	adds r3, r4, r7
_081E3B68:
	adds r0, r3, r2
	adds r1, r5, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #0xb
	ble _081E3B68
	b _081E3CA8
	.align 2, 0
_081E3B78: .4byte 0x000015C8
_081E3B7C:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne _081E3B88
	movs r0, #1
	b _081E3B8A
_081E3B88:
	movs r0, #0
_081E3B8A:
	cmp r0, #0
	beq _081E3C60
	movs r1, #0xaf
	lsls r1, r1, #5
	adds r0, r4, r1
	ldrh r0, [r0]
	ldrh r2, [r6, #2]
	cmp r0, r2
	beq _081E3BA2
_081E3B9C:
	bl FUN_081e24b4
	b _081E3CAC
_081E3BA2:
	ldr r3, _081E3C3C @ =0x00001610
	adds r3, r3, r4
	mov sb, r3
	adds r3, r4, #0
	adds r2, r6, #4
	movs r5, #2
_081E3BAE:
	ldrb r1, [r2]
	ldr r7, _081E3C40 @ =0x000015D4
	adds r0, r3, r7
	strb r1, [r0]
	adds r2, #1
	ldrb r1, [r2]
	adds r7, #1
	adds r0, r3, r7
	strb r1, [r0]
	adds r2, #1
	ldrb r1, [r2]
	adds r7, #1
	adds r0, r3, r7
	strb r1, [r0]
	adds r2, #1
	ldrb r1, [r2]
	adds r7, #1
	adds r0, r3, r7
	strb r1, [r0]
	adds r2, #1
	adds r3, #4
	subs r5, #1
	cmp r5, #0
	bge _081E3BAE
	ldr r0, _081E3C44 @ =0x00000E28
	adds r0, r0, r4
	mov ip, r0
	ldr r1, _081E3C48 @ =0x000015BC
	adds r1, r1, r4
	mov r8, r1
	mov r1, ip
	mov r0, r8
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldm r0!, {r2, r5, r7}
	stm r1!, {r2, r5, r7}
	ldr r3, _081E3C4C @ =0x00000E04
	adds r0, r4, r3
	mov r2, r8
	ldm r2!, {r1, r5, r7}
	stm r0!, {r1, r5, r7}
	ldm r2!, {r3, r5, r7}
	stm r0!, {r3, r5, r7}
	ldm r2!, {r1, r3, r5}
	stm r0!, {r1, r3, r5}
	ldr r7, _081E3C50 @ =0x000014AC
	adds r0, r4, r7
	ldr r2, _081E3C54 @ =0x0000156C
	adds r1, r4, r2
	mov r3, ip
	ldrb r2, [r3]
	bl MainSprite_LoadPose
	ldr r5, _081E3C58 @ =0x000014B4
	adds r2, r4, r5
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r7, sb
	ldr r0, [r7]
	orrs r0, r1
	ldr r1, _081E3C5C @ =0xFFFFF7FF
	ands r0, r1
	str r0, [r7]
	b _081E3CA8
	.align 2, 0
_081E3C3C: .4byte 0x00001610
_081E3C40: .4byte 0x000015D4
_081E3C44: .4byte 0x00000E28
_081E3C48: .4byte 0x000015BC
_081E3C4C: .4byte 0x00000E04
_081E3C50: .4byte 0x000014AC
_081E3C54: .4byte 0x0000156C
_081E3C58: .4byte 0x000014B4
_081E3C5C: .4byte 0xFFFFF7FF
_081E3C60:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bne _081E3C6C
	movs r0, #1
	b _081E3C6E
_081E3C6C:
	movs r0, #0
_081E3C6E:
	cmp r0, #0
	beq _081E3C80
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r0, _081E3C7C @ =0x00001610
	adds r1, r4, r0
	b _081E3CA2
	.align 2, 0
_081E3C7C: .4byte 0x00001610
_081E3C80:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xc
	bne _081E3C8C
	movs r0, #1
	b _081E3C8E
_081E3C8C:
	movs r0, #0
_081E3C8E:
	cmp r0, #0
	beq _081E3CA8
	ldr r1, [r6, #4]
	ldr r2, _081E3CB8 @ =0x000015E2
	adds r0, r4, r2
	strh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #5
_081E3C9E:
	ldr r3, _081E3CBC @ =0x00001610
	adds r1, r4, r3
_081E3CA2:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081E3CA8:
	movs r0, #0
	strh r0, [r6]
_081E3CAC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E3CB8: .4byte 0x000015E2
_081E3CBC: .4byte 0x00001610

	thumb_func_start FUN_081e3cc0
FUN_081e3cc0: @ 0x081E3CC0
	movs r2, #0x80
	lsls r2, r2, #0xf
	ldr r1, _081E3CD0 @ =0x00001610
	adds r0, r0, r1
	ldr r1, [r0]
	orrs r1, r2
	str r1, [r0]
	bx lr
	.align 2, 0
_081E3CD0: .4byte 0x00001610

	thumb_func_start FUN_081e3cd4
FUN_081e3cd4: @ 0x081E3CD4
	push {lr}
	bl FUN_0824172c
	ldr r1, _081E3CE4 @ =0x0300481C
	movs r0, #0
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_081E3CE4: .4byte 0x0300481C

	thumb_func_start FUN_081e3ce8
FUN_081e3ce8: @ 0x081E3CE8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r1, #2
	ldr r2, _081E3D00 @ =0x00001610
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E3D04
	movs r0, #1
	b _081E3D06
	.align 2, 0
_081E3D00: .4byte 0x00001610
_081E3D04:
	movs r0, #0
_081E3D06:
	cmp r0, #0
	beq _081E3D62
	movs r0, #0xb0
	lsls r0, r0, #5
	adds r5, r7, r0
	ldr r0, [r5]
	ldr r1, _081E3D68 @ =0x000015F0
	adds r6, r7, r1
	ldr r1, [r6]
	bl FUN_0804a240
	ldr r0, [r5]
	movs r1, #0
	bl FUN_0804a2f8
	ldr r2, _081E3D6C @ =0x00001604
	adds r4, r7, r2
	ldr r0, [r4]
	ldr r1, [r6]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #1
	bl FUN_0804a2f8
	ldr r0, [r5]
	ldr r1, _081E3D70 @ =0x030046A0
	ldr r2, [r1]
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #1
	bl FUN_0804a40c
	ldr r0, [r4]
	ldr r1, _081E3D74 @ =0x00000BB8
	adds r2, r7, r1
	movs r1, #2
	bl FUN_0804a40c
	ldr r0, [r5]
	bl FUN_0804a1f0
	ldr r0, [r4]
	bl FUN_0804a1f0
_081E3D62:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E3D68: .4byte 0x000015F0
_081E3D6C: .4byte 0x00001604
_081E3D70: .4byte 0x030046A0
_081E3D74: .4byte 0x00000BB8

	thumb_func_start FUN_081e3d78
FUN_081e3d78: @ 0x081E3D78
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	movs r1, #4
	movs r2, #0xa
	movs r3, #2
	bl FUN_0804a084
	movs r2, #0xb0
	lsls r2, r2, #5
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #0x11
	movs r1, #4
	movs r2, #0xa
	movs r3, #2
	bl FUN_0804a084
	ldr r2, _081E3DDC @ =0x00001604
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_0804a084
	ldr r2, _081E3DE0 @ =0x00001608
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_0804a084
	ldr r2, _081E3DE4 @ =0x0000160C
	adds r1, r4, r2
	str r0, [r1]
	ldr r0, _081E3DE8 @ =0x00000BB8
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xc
	bl ClearMemory
	movs r0, #0
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E3DDC: .4byte 0x00001604
_081E3DE0: .4byte 0x00001608
_081E3DE4: .4byte 0x0000160C
_081E3DE8: .4byte 0x00000BB8

	thumb_func_start FUN_081e3dec
FUN_081e3dec: @ 0x081E3DEC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0xb0
	lsls r0, r0, #5
	adds r5, r4, r0
	ldr r0, [r5]
	bl FUN_0804a210
	ldr r1, _081E3E6C @ =0x00001604
	adds r6, r4, r1
	ldr r0, [r6]
	bl FUN_0804a210
	ldr r0, _081E3E70 @ =0x00001608
	adds r0, r0, r4
	mov r8, r0
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, _081E3E74 @ =0x0000160C
	adds r4, r4, r1
	ldr r0, [r4]
	bl FUN_0804a210
	ldr r0, [r5]
	movs r5, #2
	str r5, [sp]
	movs r1, #1
	movs r2, #4
	movs r3, #0xa
	bl FUN_0804a38c
	ldr r0, [r6]
	str r5, [sp]
	movs r1, #0x11
	movs r2, #4
	movs r3, #0xa
	bl FUN_0804a38c
	mov r1, r8
	ldr r0, [r1]
	str r5, [sp]
	movs r1, #2
	movs r2, #0x10
	movs r3, #0x1c
	bl FUN_0804a38c
	ldr r0, [r4]
	str r5, [sp]
	movs r1, #0
	movs r2, #0x10
	movs r3, #0x1c
	bl FUN_0804a38c
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E3E6C: .4byte 0x00001604
_081E3E70: .4byte 0x00001608
_081E3E74: .4byte 0x0000160C

	thumb_func_start FUN_081e3e78
FUN_081e3e78: @ 0x081E3E78
	push {lr}
	ldr r2, _081E3E9C @ =0x0000161A
	adds r1, r0, r2
	ldrb r1, [r1]
	subs r2, #0x81
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	beq _081E3E98
	adds r0, r1, #0
	bl FUN_08243180
	cmp r0, #0
	bne _081E3EA0
_081E3E98:
	movs r0, #0
	b _081E3EA2
	.align 2, 0
_081E3E9C: .4byte 0x0000161A
_081E3EA0:
	movs r0, #1
_081E3EA2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e3ea8
FUN_081e3ea8: @ 0x081E3EA8
	push {r4, r5, lr}
	sub sp, #4
	adds r1, r0, #0
	ldr r0, _081E3EFC @ =0x0000161A
	adds r4, r1, r0
	movs r5, #0
	strb r5, [r4]
	ldr r2, _081E3F00 @ =0x0000161B
	adds r0, r1, r2
	strb r5, [r0]
	ldr r2, _081E3F04 @ =0x00000808
	adds r0, r1, r2
	ldrb r2, [r4]
	movs r3, #3
	ands r3, r2
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #3
	adds r2, #0x90
	strh r2, [r0, #0x20]
	ldrb r3, [r4]
	lsrs r3, r3, #2
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #3
	adds r2, #0x20
	strh r2, [r0, #0x22]
	ldr r2, [r0, #8]
	movs r3, #1
	orrs r2, r3
	str r2, [r0, #8]
	ldr r2, _081E3F08 @ =0x00000AC8
	adds r1, r1, r2
	str r5, [sp]
	movs r2, #0
	bl FUN_082370cc
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E3EFC: .4byte 0x0000161A
_081E3F00: .4byte 0x0000161B
_081E3F04: .4byte 0x00000808
_081E3F08: .4byte 0x00000AC8

	thumb_func_start FUN_081e3f0c
FUN_081e3f0c: @ 0x081E3F0C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r0, _081E3F9C @ =0x00001594
	adds r2, r7, r0
	movs r0, #0
	str r0, [r2]
	ldr r3, _081E3FA0 @ =0x00001598
	adds r1, r7, r3
	strb r0, [r1]
	ldr r0, _081E3FA4 @ =0x030046A0
	ldr r0, [r0]
	adds r6, r2, #0
	movs r2, #1
	mov sb, r2
	adds r5, r1, #0
	adds r4, r0, #0
	adds r4, #0x60
	movs r3, #0
	mov r8, r3
	movs r0, #3
	mov ip, r0
_081E3F3C:
	ldr r0, _081E3FA8 @ =0x00000868
	add r0, r8
	adds r2, r7, r0
	movs r1, #0
	ldrsh r3, [r4, r1]
	cmp r3, #0
	blt _081E3F74
	movs r1, #3
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r2, #0x20]
	asrs r1, r3, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r2, #0x22]
	mov r1, sb
	lsls r1, r3
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
_081E3F74:
	ldr r0, [r2, #8]
	mov r3, sb
	orrs r0, r3
	str r0, [r2, #8]
	adds r4, #2
	movs r0, #0x60
	add r8, r0
	movs r1, #1
	rsbs r1, r1, #0
	add ip, r1
	mov r2, ip
	cmp r2, #0
	bge _081E3F3C
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E3F9C: .4byte 0x00001594
_081E3FA0: .4byte 0x00001598
_081E3FA4: .4byte 0x030046A0
_081E3FA8: .4byte 0x00000868

	thumb_func_start FUN_081e3fac
FUN_081e3fac: @ 0x081E3FAC
	push {r4, r5, lr}
	movs r2, #0
	ldr r3, _081E3FDC @ =0x00001598
	adds r1, r0, r3
	ldrb r5, [r1]
	cmp r2, r5
	bge _081E3FD6
	movs r4, #2
	rsbs r4, r4, #0
	adds r3, r1, #0
	movs r5, #0x87
	lsls r5, r5, #4
	adds r1, r0, r5
_081E3FC6:
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	adds r1, #0x60
	adds r2, #1
	ldrb r0, [r3]
	cmp r2, r0
	blt _081E3FC6
_081E3FD6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E3FDC: .4byte 0x00001598

	thumb_func_start FUN_081e3fe0
FUN_081e3fe0: @ 0x081E3FE0
	push {r4, r5, lr}
	movs r2, #0
	ldr r3, _081E4010 @ =0x00001598
	adds r1, r0, r3
	ldrb r5, [r1]
	cmp r2, r5
	bge _081E4008
	movs r4, #1
	adds r3, r1, #0
	movs r5, #0x87
	lsls r5, r5, #4
	adds r1, r0, r5
_081E3FF8:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	adds r2, #1
	ldrb r0, [r3]
	cmp r2, r0
	blt _081E3FF8
_081E4008:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E4010: .4byte 0x00001598

	thumb_func_start FUN_081e4014
FUN_081e4014: @ 0x081E4014
	push {lr}
	sub sp, #0x18
	adds r1, r0, #0
	ldr r2, _081E404C @ =0xFFFF0000
	movs r0, #0x80
	lsls r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	ldr r2, _081E4050 @ =0x0000150C
	adds r0, r1, r2
	adds r2, #0x60
	adds r1, r1, r2
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	movs r2, #0xd0
	movs r3, #0x11
	bl MainSprite_Add
	add sp, #0x18
	pop {r1}
	bx r1
	.align 2, 0
_081E404C: .4byte 0xFFFF0000
_081E4050: .4byte 0x0000150C

	thumb_func_start FUN_081e4054
FUN_081e4054: @ 0x081E4054
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sl, r0
	ldr r7, _081E4108 @ =0x00000BC4
	add r7, sl
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _081E410C @ =0x05000002
	bl CpuSet
	ldr r0, _081E4110 @ =0x0000CB05
	ldr r1, _081E4114 @ =0x00005D04
	bl GetFile
	adds r1, r0, #0
	cmp r1, #0
	bne _081E4086
	b _081E41BE
_081E4086:
	ldr r0, _081E4118 @ =0x0000158C
	add r0, sl
	str r1, [r0]
	ldr r0, _081E411C @ =0x0000156C
	add r0, sl
	bl OpenMainSpriteFile
	movs r5, #0
	mov r8, r5
	ldr r6, _081E4120 @ =0x00000E86
	add r6, sl
	ldr r0, _081E4124 @ =0x00000E4C
	add r0, sl
	mov sb, r0
	adds r4, r7, #0
_081E40A4:
	movs r1, #3
	ands r1, r5
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	mov r1, sp
	strh r0, [r1, #0x14]
	asrs r1, r5, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	mov r2, sp
	strh r0, [r2, #0x16]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08242b14
	ldrb r2, [r4]
	movs r0, #1
	str r0, [sp]
	movs r3, #0
	str r3, [sp, #4]
	str r3, [sp, #8]
	add r0, sp, #0x14
	str r0, [sp, #0xc]
	mov r0, sb
	ldr r3, _081E4128 @ =0x000009A8
	adds r1, r7, r3
	movs r3, #0x10
	bl MainSprite_Add
	adds r0, r5, #0
	bl FUN_08243180
	cmp r0, #0
	bne _081E4130
	movs r0, #0xb8
	lsls r0, r0, #2
	strh r0, [r6]
	subs r0, #0x10
	adds r1, r7, r0
	add r1, r8
	ldr r0, _081E412C @ =0x03003584
	ldr r0, [r0]
	movs r2, #0xb8
	lsls r2, r2, #7
	b _081E4142
	.align 2, 0
_081E4108: .4byte 0x00000BC4
_081E410C: .4byte 0x05000002
_081E4110: .4byte 0x0000CB05
_081E4114: .4byte 0x00005D04
_081E4118: .4byte 0x0000158C
_081E411C: .4byte 0x0000156C
_081E4120: .4byte 0x00000E86
_081E4124: .4byte 0x00000E4C
_081E4128: .4byte 0x000009A8
_081E412C: .4byte 0x03003584
_081E4130:
	ldr r0, _081E41D0 @ =0x000002DF
	strh r0, [r6]
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r1, r7, r3
	add r1, r8
	ldr r0, _081E41D4 @ =0x03003584
	ldr r0, [r0]
	ldr r2, _081E41D8 @ =0x00005BE0
_081E4142:
	adds r0, r0, r2
	str r0, [r1]
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r7, r3
	add r0, r8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	movs r0, #0x60
	add r8, r0
	adds r6, #0x60
	add sb, r0
	adds r4, #0x24
	adds r5, #1
	cmp r5, #0xf
	ble _081E40A4
	movs r0, #0x30
	mov r1, sp
	strh r0, [r1, #0x14]
	add r1, sp, #0x14
	movs r0, #0x48
	strh r0, [r1, #2]
	mov sb, r2
	ldr r2, _081E41DC @ =0x00000888
	adds r4, r7, r2
	movs r6, #0xc0
	lsls r6, r6, #3
	movs r3, #0
	mov r8, r3
	movs r5, #1
_081E4182:
	mov r0, sb
	str r0, [sp]
	mov r1, r8
	str r1, [sp, #4]
	str r1, [sp, #8]
	add r2, sp, #0x14
	str r2, [sp, #0xc]
	adds r0, r4, #0
	ldr r3, _081E41E0 @ =0x000009A8
	adds r1, r7, r3
	movs r2, #0
	movs r3, #0x10
	bl MainSprite_Add
	movs r0, #0xa4
	lsls r0, r0, #2
	adds r1, r7, r0
	adds r1, r1, r6
	ldr r0, [r1]
	mov r2, sb
	orrs r0, r2
	str r0, [r1]
	adds r4, #0x60
	adds r6, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081E4182
	mov r0, sl
	bl FUN_081e4014
_081E41BE:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E41D0: .4byte 0x000002DF
_081E41D4: .4byte 0x03003584
_081E41D8: .4byte 0x00005BE0
_081E41DC: .4byte 0x00000888
_081E41E0: .4byte 0x000009A8

	thumb_func_start FUN_081e41e4
FUN_081e41e4: @ 0x081E41E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, _081E428C @ =0x00000BC4
	adds r0, r0, r7
	mov r8, r0
	add r4, sp, #4
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _081E4290 @ =0x05000002
	bl CpuSet
	ldr r0, _081E4294 @ =0x0000CB05
	ldr r1, _081E4298 @ =0x00005D04
	bl GetFile
	adds r1, r0, #0
	mov sl, r4
	cmp r1, #0
	bne _081E421A
	b _081E432E
_081E421A:
	ldr r2, _081E429C @ =0x0000158C
	adds r0, r7, r2
	str r1, [r0]
	subs r2, #0x20
	adds r0, r7, r2
	bl OpenMainSpriteFile
	movs r5, #0
	mov sb, r5
	ldr r0, _081E42A0 @ =0x00000E86
	adds r6, r7, r0
	ldr r1, _081E42A4 @ =0x00000E4C
	adds r7, r7, r1
	mov r4, r8
_081E4236:
	movs r1, #3
	ands r1, r5
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	mov r2, sl
	strh r0, [r2]
	asrs r1, r5, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	add r1, sp, #4
	strh r0, [r1, #2]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08242b14
	ldrb r2, [r4]
	adds r0, r7, #0
	ldr r1, _081E42A8 @ =0x000009A8
	add r1, r8
	bl MainSprite_LoadPose
	adds r0, r5, #0
	bl FUN_08243180
	cmp r0, #0
	bne _081E42B0
	movs r0, #0xb8
	lsls r0, r0, #2
	strh r0, [r6]
	movs r1, #0xb4
	lsls r1, r1, #2
	add r1, r8
	add r1, sb
	ldr r0, _081E42AC @ =0x03003584
	ldr r0, [r0]
	movs r2, #0xb8
	lsls r2, r2, #7
	b _081E42C2
	.align 2, 0
_081E428C: .4byte 0x00000BC4
_081E4290: .4byte 0x05000002
_081E4294: .4byte 0x0000CB05
_081E4298: .4byte 0x00005D04
_081E429C: .4byte 0x0000158C
_081E42A0: .4byte 0x00000E86
_081E42A4: .4byte 0x00000E4C
_081E42A8: .4byte 0x000009A8
_081E42AC: .4byte 0x03003584
_081E42B0:
	ldr r0, _081E4340 @ =0x000002DF
	strh r0, [r6]
	movs r1, #0xb4
	lsls r1, r1, #2
	add r1, r8
	add r1, sb
	ldr r0, _081E4344 @ =0x03003584
	ldr r0, [r0]
	ldr r2, _081E4348 @ =0x00005BE0
_081E42C2:
	adds r0, r0, r2
	str r0, [r1]
	movs r0, #0xa4
	lsls r0, r0, #2
	add r0, r8
	add r0, sb
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	movs r0, #0x60
	add sb, r0
	adds r6, #0x60
	adds r7, #0x60
	adds r4, #0x24
	adds r5, #1
	cmp r5, #0xf
	ble _081E4236
	movs r0, #0x30
	mov r1, sl
	strh r0, [r1]
	add r1, sp, #4
	movs r0, #0x48
	strh r0, [r1, #2]
	ldr r4, _081E434C @ =0x00000888
	add r4, r8
	movs r6, #0xc0
	lsls r6, r6, #3
	movs r5, #1
_081E42FC:
	adds r0, r4, #0
	ldr r1, _081E4350 @ =0x000009A8
	add r1, r8
	movs r2, #0
	bl MainSprite_LoadPose
	movs r2, #0xa4
	lsls r2, r2, #2
	add r2, r8
	adds r2, r2, r6
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	mov r2, sl
	ldrh r0, [r2]
	strh r0, [r4, #0x20]
	add r0, sp, #4
	ldrh r0, [r0, #2]
	strh r0, [r4, #0x22]
	adds r4, #0x60
	adds r6, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081E42FC
_081E432E:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E4340: .4byte 0x000002DF
_081E4344: .4byte 0x03003584
_081E4348: .4byte 0x00005BE0
_081E434C: .4byte 0x00000888
_081E4350: .4byte 0x000009A8

	thumb_func_start FUN_081e4354
FUN_081e4354: @ 0x081E4354
	push {r4, lr}
	ldr r2, _081E4380 @ =0x00000E54
	adds r1, r0, r2
	ldr r3, _081E4384 @ =0x00000BC4
	adds r2, r0, r3
	movs r4, #2
	rsbs r4, r4, #0
	movs r3, #0xf
_081E4364:
	ldrb r0, [r2]
	cmp r0, #0
	beq _081E4370
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
_081E4370:
	adds r1, #0x60
	adds r2, #0x24
	subs r3, #1
	cmp r3, #0
	bge _081E4364
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E4380: .4byte 0x00000E54
_081E4384: .4byte 0x00000BC4

	thumb_func_start FUN_081e4388
FUN_081e4388: @ 0x081E4388
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _081E43CC @ =0x00000BC4
	adds r0, r0, r7
	mov sb, r0
	movs r6, #0
	movs r3, #0
	ldr r0, _081E43D0 @ =0x00000E86
	adds r5, r7, r0
	ldr r1, _081E43D4 @ =0x03003584
	mov r8, r1
	adds r0, #0xe
	adds r4, r7, r0
_081E43AC:
	adds r0, r6, #0
	str r3, [sp]
	bl FUN_08243180
	ldr r3, [sp]
	cmp r0, #0
	bne _081E43D8
	movs r0, #0xb8
	lsls r0, r0, #2
	strh r0, [r5]
	mov r1, r8
	ldr r0, [r1]
	movs r1, #0xb8
	lsls r1, r1, #7
	b _081E43E2
	.align 2, 0
_081E43CC: .4byte 0x00000BC4
_081E43D0: .4byte 0x00000E86
_081E43D4: .4byte 0x03003584
_081E43D8:
	ldr r0, _081E4440 @ =0x000002DF
	strh r0, [r5]
	mov r1, r8
	ldr r0, [r1]
	ldr r1, _081E4444 @ =0x00005BE0
_081E43E2:
	adds r0, r0, r1
	str r0, [r4]
	movs r0, #0xa4
	lsls r0, r0, #2
	add r0, sb
	adds r0, r0, r3
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	adds r4, #0x60
	adds r3, #0x60
	adds r5, #0x60
	adds r6, #1
	cmp r6, #0xf
	ble _081E43AC
	movs r0, #0x30
	mov r8, r0
	ldr r0, _081E4448 @ =0x00001454
	adds r1, r7, r0
	movs r0, #0xc0
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r5, _081E444C @ =0x00000E6E
	movs r4, #0x48
	movs r3, #1
	movs r6, #1
_081E4418:
	mov r0, r8
	strh r0, [r1, #0x18]
	adds r0, r2, r5
	strh r4, [r0]
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	adds r2, #0x60
	subs r6, #1
	cmp r6, #0
	bge _081E4418
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E4440: .4byte 0x000002DF
_081E4444: .4byte 0x00005BE0
_081E4448: .4byte 0x00001454
_081E444C: .4byte 0x00000E6E

	thumb_func_start FUN_081e4450
FUN_081e4450: @ 0x081E4450
	push {r4, lr}
	adds r3, r0, #0
	movs r4, #1
	ldr r0, _081E4480 @ =0x00000E54
	adds r1, r3, r0
	movs r2, #0x11
_081E445C:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _081E445C
	movs r1, #0xa5
	lsls r1, r1, #4
	adds r0, r3, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E4480: .4byte 0x00000E54

	thumb_func_start FUN_081e4484
FUN_081e4484: @ 0x081E4484
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _081E44AC @ =0x00000E4C
	adds r4, r6, r0
	movs r5, #0x11
_081E448E:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081E448E
	ldr r1, _081E44B0 @ =0x0000150C
	adds r0, r6, r1
	bl FUN_0822f1c0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E44AC: .4byte 0x00000E4C
_081E44B0: .4byte 0x0000150C

	thumb_func_start FUN_081e44b4
FUN_081e44b4: @ 0x081E44B4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x28
	movs r5, #0x1b
_081E44BC:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081E44BC
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e44d0
FUN_081e44d0: @ 0x081E44D0
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r2, _081E4510 @ =0x00001604
	adds r0, r4, r2
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, _081E4514 @ =0x00001608
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r2, _081E4518 @ =0x0000160C
	adds r0, r4, r2
	ldr r0, [r0]
	bl FUN_0804a210
	movs r1, #1
	ldr r2, _081E451C @ =0x00001610
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E4520
	movs r0, #1
	b _081E4522
	.align 2, 0
_081E4510: .4byte 0x00001604
_081E4514: .4byte 0x00001608
_081E4518: .4byte 0x0000160C
_081E451C: .4byte 0x00001610
_081E4520:
	movs r0, #0
_081E4522:
	cmp r0, #0
	beq _081E4538
	bl FUN_08049fa8
	ldr r0, _081E4540 @ =0x00001610
	adds r2, r4, r0
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081E4538:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E4540: .4byte 0x00001610

	thumb_func_start FUN_081e4544
FUN_081e4544: @ 0x081E4544
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _081E45AC @ =0x0000161A
	adds r0, r4, r1
	ldrb r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r3, _081E45B0 @ =0x00000BC4
	adds r0, r0, r3
	adds r5, r4, r0
	ldr r1, _081E45B4 @ =0x00001608
	adds r0, r4, r1
	ldr r0, [r0]
	ldr r3, _081E45B8 @ =0x0000159C
	adds r2, r4, r3
	adds r1, r5, #0
	bl FUN_08094d30
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E45C8
	bl FUN_08049f5c
	bl FUN_08049e5c
	ldr r1, _081E45BC @ =0x00001590
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl FUN_08094d48
	adds r0, r5, #0
	bl FUN_08094e70
	adds r2, r0, #0
	ldr r3, _081E45C0 @ =0x0000150C
	adds r0, r4, r3
	ldr r1, [r0, #8]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r0, #8]
	ldr r3, _081E45C4 @ =0x0000156C
	adds r1, r4, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #0
	bl MainSprite_SetPose
	b _081E45D8
	.align 2, 0
_081E45AC: .4byte 0x0000161A
_081E45B0: .4byte 0x00000BC4
_081E45B4: .4byte 0x00001608
_081E45B8: .4byte 0x0000159C
_081E45BC: .4byte 0x00001590
_081E45C0: .4byte 0x0000150C
_081E45C4: .4byte 0x0000156C
_081E45C8:
	bl FUN_08049e5c
	ldr r1, _081E45E0 @ =0x0000150C
	adds r0, r4, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
_081E45D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E45E0: .4byte 0x0000150C

	thumb_func_start FUN_081e45e4
FUN_081e45e4: @ 0x081E45E4
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #4
	ldr r0, _081E4600 @ =0x03003ED0
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
_081E4600: .4byte 0x03003ED0

	thumb_func_start FUN_081e4604
FUN_081e4604: @ 0x081E4604
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	movs r7, #3
	movs r0, #3
	bl FUN_081e45e4
	adds r6, r0, #0
	cmp r5, #0
	ble _081E463C
_081E461C:
	adds r0, r4, #0
	adds r1, r5, #0
	bl Div
	adds r1, r0, r7
	strh r1, [r6]
	adds r6, #2
	muls r0, r5, r0
	subs r4, r4, r0
	adds r0, r5, #0
	movs r1, #0xa
	bl Div
	adds r5, r0, #0
	cmp r5, #0
	bgt _081E461C
_081E463C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e4644
FUN_081e4644: @ 0x081E4644
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	mov r8, r1
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r7, [sp, #0x1c]
	movs r4, #0
	cmp r4, r6
	bge _081E4680
_081E465C:
	mov r0, r8
	adds r2, r0, r4
	ldr r0, [sp, #0x20]
	mov r1, sb
	bl FUN_081e45e4
	adds r2, r4, #1
	cmp r5, #0
	ble _081E467A
	adds r1, r5, #0
_081E4670:
	strh r7, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bne _081E4670
_081E467A:
	adds r4, r2, #0
	cmp r4, r6
	blt _081E465C
_081E4680:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e468c
FUN_081e468c: @ 0x081E468C
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r6, r1, #0
	movs r7, #0
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081E46B4
	ldr r1, _081E46AC @ =0x085AE404
	ldr r2, _081E46B0 @ =0x0000161A
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r2, [r0]
	b _081E46CA
	.align 2, 0
_081E46AC: .4byte 0x085AE404
_081E46B0: .4byte 0x0000161A
_081E46B4:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081E46E4
	ldr r1, _081E46D8 @ =0x085AE404
	ldr r2, _081E46DC @ =0x0000161A
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r2, [r0, #1]
_081E46CA:
	cmp r2, #0x10
	bne _081E4754
	ldr r1, _081E46E0 @ =0x0000161B
	adds r0, r3, r1
	strb r7, [r0]
	b _081E4748
	.align 2, 0
_081E46D8: .4byte 0x085AE404
_081E46DC: .4byte 0x0000161A
_081E46E0: .4byte 0x0000161B
_081E46E4:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081E4704
	ldr r1, _081E46FC @ =0x085AE404
	ldr r2, _081E4700 @ =0x0000161A
	adds r5, r3, r2
	ldrb r4, [r5]
	lsls r0, r4, #2
	adds r0, r0, r1
	ldrb r2, [r0, #2]
	b _081E471A
	.align 2, 0
_081E46FC: .4byte 0x085AE404
_081E4700: .4byte 0x0000161A
_081E4704:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081E473C
	ldr r1, _081E4730 @ =0x085AE404
	ldr r2, _081E4734 @ =0x0000161A
	adds r5, r3, r2
	ldrb r4, [r5]
	lsls r0, r4, #2
	adds r0, r0, r1
	ldrb r2, [r0, #3]
_081E471A:
	cmp r2, #0x10
	bne _081E4724
	ldr r1, _081E4738 @ =0x0000161B
	adds r0, r3, r1
	strb r4, [r0]
_081E4724:
	ldrb r0, [r5]
	cmp r0, #0x10
	bne _081E4748
	movs r7, #1
	b _081E4748
	.align 2, 0
_081E4730: .4byte 0x085AE404
_081E4734: .4byte 0x0000161A
_081E4738: .4byte 0x0000161B
_081E473C:
	ldr r2, _081E4744 @ =0x0000161A
	adds r0, r3, r2
	ldrb r0, [r0]
	b _081E47BC
	.align 2, 0
_081E4744: .4byte 0x0000161A
_081E4748:
	cmp r2, #0x10
	bne _081E4754
	movs r0, #0x30
	strh r0, [r6]
	movs r0, #0x48
	b _081E47B8
_081E4754:
	cmp r2, #0x11
	bne _081E4760
	movs r0, #0x38
	strh r0, [r6]
	movs r0, #0x68
	b _081E47B8
_081E4760:
	cmp r7, #0
	beq _081E47A0
	ldr r0, _081E477C @ =0x0000161B
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081E47A0
	cmp r0, #7
	beq _081E478A
	cmp r0, #7
	bgt _081E4780
	cmp r0, #4
	beq _081E478A
	b _081E47A0
	.align 2, 0
_081E477C: .4byte 0x0000161B
_081E4780:
	cmp r0, #8
	beq _081E4796
	cmp r0, #0xb
	beq _081E4796
	b _081E47A0
_081E478A:
	cmp r2, #0
	bne _081E4792
	movs r2, #4
	b _081E47A0
_081E4792:
	movs r2, #7
	b _081E47A0
_081E4796:
	cmp r2, #0
	bne _081E479E
	movs r2, #8
	b _081E47A0
_081E479E:
	movs r2, #0xb
_081E47A0:
	movs r1, #3
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r6]
	asrs r1, r2, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
_081E47B8:
	strh r0, [r6, #2]
	adds r0, r2, #0
_081E47BC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e47c4
FUN_081e47c4: @ 0x081E47C4
	mov ip, r0
	movs r1, #0xb4
	lsls r1, r1, #1
	add r1, ip
	movs r3, #0
	movs r0, #0x98
	strh r0, [r1]
	adds r0, #0xd2
	add r0, ip
	movs r2, #0x68
	strh r2, [r0]
	movs r1, #0x84
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0xa0
	strh r0, [r1]
	adds r0, #0x6a
	add r0, ip
	strh r2, [r0]
	mov r1, ip
	adds r1, #0xa8
	movs r0, #0xa8
	strh r0, [r1]
	mov r0, ip
	adds r0, #0xaa
	strh r2, [r0]
	subs r1, #0x60
	movs r0, #0xb0
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x4a
	strh r2, [r0]
	mov r1, ip
	ldr r0, [r1, #0x30]
	subs r2, #0x6a
	ands r0, r2
	str r0, [r1, #0x30]
	adds r1, #0x90
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r1, #0x60
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xa8
	lsls r1, r1, #1
	add r1, ip
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r0, _081E4834 @ =0x000015E4
	add r0, ip
	strh r3, [r0]
	bx lr
	.align 2, 0
_081E4834: .4byte 0x000015E4

	thumb_func_start FUN_081e4838
FUN_081e4838: @ 0x081E4838
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r7, #0
	ldr r1, _081E4878 @ =0x000015E2
	adds r0, r5, r1
	ldrh r4, [r0]
	movs r6, #0
	movs r2, #0
	ldr r0, _081E487C @ =0x000003E7
	cmp r4, r0
	ble _081E4858
	ldr r1, _081E4880 @ =0xFFFFFC18
_081E4850:
	adds r2, #1
	adds r4, r4, r1
	cmp r4, r0
	bgt _081E4850
_081E4858:
	cmp r2, r7
	bgt _081E4860
	cmp r6, #0
	ble _081E4888
_081E4860:
	movs r3, #0xa4
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r3, _081E4884 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	adds r6, #1
	b _081E4896
	.align 2, 0
_081E4878: .4byte 0x000015E2
_081E487C: .4byte 0x000003E7
_081E4880: .4byte 0xFFFFFC18
_081E4884: .4byte 0x00000AA8
_081E4888:
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_081E4896:
	adds r2, r7, #0
	cmp r4, #0x63
	ble _081E48A4
_081E489C:
	adds r2, #1
	subs r4, #0x64
	cmp r4, #0x63
	bgt _081E489C
_081E48A4:
	cmp r2, r7
	bgt _081E48AC
	cmp r6, #0
	ble _081E48C4
_081E48AC:
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r3, _081E48C0 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	adds r6, #1
	b _081E48D0
	.align 2, 0
_081E48C0: .4byte 0x00000AA8
_081E48C4:
	adds r0, r5, #0
	adds r0, #0xf0
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_081E48D0:
	adds r2, r7, #0
	cmp r4, #9
	ble _081E48DE
_081E48D6:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E48D6
_081E48DE:
	cmp r2, r7
	bgt _081E48E6
	cmp r6, #0
	ble _081E4900
_081E48E6:
	adds r0, r5, #0
	adds r0, #0x88
	ldr r3, _081E48FC @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	adds r6, #1
	b _081E490C
	.align 2, 0
_081E48FC: .4byte 0x00000AA8
_081E4900:
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_081E490C:
	adds r2, r7, #0
	cmp r4, #0
	ble _081E491A
_081E4912:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E4912
_081E491A:
	cmp r2, r7
	bgt _081E4922
	cmp r6, #0
	blt _081E4938
_081E4922:
	adds r0, r5, #0
	adds r0, #0x28
	ldr r3, _081E4934 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	b _081E4940
	.align 2, 0
_081E4934: .4byte 0x00000AA8
_081E4938:
	ldr r0, [r5, #0x30]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x30]
_081E4940:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e4948
FUN_081e4948: @ 0x081E4948
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0x9f
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _081E4994 @ =0x00000A08
	adds r0, r4, r1
	movs r5, #0
	movs r3, #0
	strh r3, [r0]
	ldr r2, _081E4998 @ =0x00000A0A
	adds r0, r4, r2
	strh r3, [r0]
	ldr r6, _081E499C @ =0x000009E8
	adds r0, r4, r6
	adds r2, #0xbe
	adds r1, r4, r2
	ldr r6, _081E49A0 @ =0x00000B2A
	adds r2, r4, r6
	ldrh r2, [r2]
	str r3, [sp]
	movs r3, #1
	bl FUN_082370cc
	ldr r0, _081E49A4 @ =0x00001623
	adds r4, r4, r0
	strb r5, [r4]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E4994: .4byte 0x00000A08
_081E4998: .4byte 0x00000A0A
_081E499C: .4byte 0x000009E8
_081E49A0: .4byte 0x00000B2A
_081E49A4: .4byte 0x00001623

	thumb_func_start FUN_081e49a8
FUN_081e49a8: @ 0x081E49A8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r2, #0
	ldr r6, _081E49C4 @ =0x03003584
	movs r0, #0xb3
	lsls r0, r0, #4
	adds r7, r4, r0
_081E49B6:
	cmp r2, #3
	bne _081E49C8
	ldr r0, [r6]
	movs r3, #0xa5
	lsls r3, r3, #7
	b _081E49CC
	.align 2, 0
_081E49C4: .4byte 0x03003584
_081E49C8:
	ldr r0, [r6]
	ldr r3, _081E4A4C @ =0x00005260
_081E49CC:
	adds r1, r0, r3
	lsls r0, r2, #5
	adds r5, r2, #1
	adds r2, r1, #0
	adds r1, r0, r7
	movs r3, #0xf
_081E49D8:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _081E49D8
	adds r2, r5, #0
	cmp r2, #3
	ble _081E49B6
	movs r2, #0
	ldr r1, _081E4A50 @ =0x00000B62
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r3, _081E4A54 @ =0x00000B52
	adds r0, r4, r3
	strh r1, [r0]
	ldr r1, _081E4A58 @ =0x00000B64
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	ldr r1, _081E4A5C @ =0x00000B66
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r0, r4, r1
	subs r3, #0x26
	adds r1, r4, r3
	str r1, [r0]
	movs r3, #0xf2
	lsls r3, r3, #3
	adds r0, r4, r3
	str r1, [r0]
	movs r1, #0xce
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r3, #0xb7
	lsls r3, r3, #4
	adds r1, r4, r3
	str r1, [r0]
	movs r3, #0xda
	lsls r3, r3, #3
	adds r0, r4, r3
	str r1, [r0]
	movs r1, #0xbb
	lsls r1, r1, #4
	adds r0, r4, r1
	strh r2, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E4A4C: .4byte 0x00005260
_081E4A50: .4byte 0x00000B62
_081E4A54: .4byte 0x00000B52
_081E4A58: .4byte 0x00000B64
_081E4A5C: .4byte 0x00000B66

	thumb_func_start FUN_081e4a60
FUN_081e4a60: @ 0x081E4A60
	push {lr}
	adds r3, r0, #0
	movs r1, #0xbb
	lsls r1, r1, #4
	adds r0, r3, r1
	ldrh r0, [r0]
	movs r2, #0x1f
	cmp r0, #9
	bls _081E4A8C
	movs r2, #0x1b
	cmp r0, #0x11
	bls _081E4A8C
	movs r2, #0x12
	cmp r0, #0x19
	bls _081E4A8C
	movs r2, #0xa
	cmp r0, #0x21
	bls _081E4A8C
	movs r2, #0x1b
	cmp r0, #0x29
	bhi _081E4A8C
	movs r2, #0x12
_081E4A8C:
	movs r0, #0xbb
	lsls r0, r0, #4
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x31
	bls _081E4AA4
	movs r0, #0
	strh r0, [r1]
_081E4AA4:
	ldr r1, _081E4AB4 @ =0x00000B48
	adds r0, r3, r1
	strh r2, [r0]
	adds r1, #0x40
	adds r0, r3, r1
	strh r2, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_081E4AB4: .4byte 0x00000B48

	thumb_func_start FUN_081e4ab8
FUN_081e4ab8: @ 0x081E4AB8
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
	ldr r1, _081E4AD0 @ =0x030044E0
	ldrh r2, [r1, #2]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _081E4AD4
	movs r4, #1
	b _081E4AF6
	.align 2, 0
_081E4AD0: .4byte 0x030044E0
_081E4AD4:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _081E4AE0
	movs r4, #2
	b _081E4AF6
_081E4AE0:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081E4AEC
	movs r4, #4
	b _081E4AF6
_081E4AEC:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081E4AF6
	movs r4, #8
_081E4AF6:
	ldrh r3, [r1]
	movs r2, #0xf0
	ands r2, r3
	cmp r2, #0
	beq _081E4B56
	ldr r0, _081E4B18 @ =0x00001619
	adds r2, r5, r0
	ldrb r0, [r2]
	cmp r0, #0xb
	bls _081E4B50
	movs r0, #0x40
	ands r0, r3
	cmp r0, #0
	beq _081E4B1C
	movs r0, #1
	b _081E4B26
	.align 2, 0
_081E4B18: .4byte 0x00001619
_081E4B1C:
	movs r0, #0x80
	ands r0, r3
	cmp r0, #0
	beq _081E4B28
	movs r0, #2
_081E4B26:
	orrs r4, r0
_081E4B28:
	ldrh r1, [r1]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _081E4B36
	movs r0, #4
	b _081E4B40
_081E4B36:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081E4B42
	movs r0, #8
_081E4B40:
	orrs r4, r0
_081E4B42:
	ldr r0, _081E4B4C @ =0x00001619
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	b _081E4B5C
	.align 2, 0
_081E4B4C: .4byte 0x00001619
_081E4B50:
	adds r0, #1
	strb r0, [r2]
	b _081E4B5C
_081E4B56:
	ldr r1, _081E4B64 @ =0x00001619
	adds r0, r5, r1
	strb r2, [r0]
_081E4B5C:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081E4B64: .4byte 0x00001619

	thumb_func_start FUN_081e4b68
FUN_081e4b68: @ 0x081E4B68
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _081E4B88 @ =0x0000162C
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, r1
	bne _081E4B90
	bl Save_SwitchSlot
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E4B90
	ldr r0, _081E4B8C @ =FUN_081e6388
	movs r2, #0x18
	b _081E4B94
	.align 2, 0
_081E4B88: .4byte 0x0000162C
_081E4B8C: .4byte FUN_081e6388
_081E4B90:
	ldr r0, _081E4BAC @ =FUN_081e6458
	movs r2, #0x19
_081E4B94:
	str r0, [r4, #0x18]
	ldr r0, _081E4BB0 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E4BB4 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E4BAC: .4byte FUN_081e6458
_081E4BB0: .4byte 0x00001614
_081E4BB4: .4byte 0x00001616

	thumb_func_start FUN_081e4bb8
FUN_081e4bb8: @ 0x081E4BB8
	ldr r1, _081E4BD0 @ =FUN_081e6458
	movs r3, #0x19
	str r1, [r0, #0x18]
	ldr r1, _081E4BD4 @ =0x00001614
	adds r2, r0, r1
	movs r1, #1
	strb r1, [r2]
	ldr r1, _081E4BD8 @ =0x00001616
	adds r0, r0, r1
	strb r3, [r0]
	bx lr
	.align 2, 0
_081E4BD0: .4byte FUN_081e6458
_081E4BD4: .4byte 0x00001614
_081E4BD8: .4byte 0x00001616

	thumb_func_start FUN_081e4bdc
FUN_081e4bdc: @ 0x081E4BDC
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _081E4C00 @ =0x0000162C
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, r1
	beq _081E4C10
	ldr r0, _081E4C04 @ =FUN_081e64cc
	movs r2, #0x1c
	str r0, [r4, #0x18]
	ldr r0, _081E4C08 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E4C0C @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	b _081E4C2C
	.align 2, 0
_081E4C00: .4byte 0x0000162C
_081E4C04: .4byte FUN_081e64cc
_081E4C08: .4byte 0x00001614
_081E4C0C: .4byte 0x00001616
_081E4C10:
	adds r0, r4, #0
	bl FUN_081e5290
	adds r0, r4, #0
	bl FUN_081e23ac
	ldr r0, _081E4C34 @ =FUN_081e3958
	ldr r1, _081E4C38 @ =FUN_081e3cd4
	ldr r2, _081E4C3C @ =FUN_081e3cc0
	bl FUN_081e23c4
	adds r0, r4, #0
	bl FUN_081e4d04
_081E4C2C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E4C34: .4byte FUN_081e3958
_081E4C38: .4byte FUN_081e3cd4
_081E4C3C: .4byte FUN_081e3cc0

	thumb_func_start FUN_081e4c40
FUN_081e4c40: @ 0x081E4C40
	ldr r1, _081E4C58 @ =FUN_081e64cc
	movs r3, #0x1c
	str r1, [r0, #0x18]
	ldr r1, _081E4C5C @ =0x00001614
	adds r2, r0, r1
	movs r1, #1
	strb r1, [r2]
	ldr r1, _081E4C60 @ =0x00001616
	adds r0, r0, r1
	strb r3, [r0]
	bx lr
	.align 2, 0
_081E4C58: .4byte FUN_081e64cc
_081E4C5C: .4byte 0x00001614
_081E4C60: .4byte 0x00001616

	thumb_func_start FUN_081e4c64
FUN_081e4c64: @ 0x081E4C64
	push {r4, lr}
	sub sp, #4
	str r1, [sp]
	ldr r1, _081E4C94 @ =0x00001610
	adds r4, r0, r1
	ldr r1, _081E4C98 @ =0xFFBFFFFF
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r0, _081E4C9C @ =0x03002CF0
	ldr r2, [r0]
	mov r0, sp
	movs r1, #0xa
	bl FUN_081e2510
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E4CA0
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r4]
	orrs r0, r1
	b _081E4CA6
	.align 2, 0
_081E4C94: .4byte 0x00001610
_081E4C98: .4byte 0xFFBFFFFF
_081E4C9C: .4byte 0x03002CF0
_081E4CA0:
	ldr r1, _081E4CB0 @ =0xFFFBFFFF
	ldr r0, [r4]
	ands r0, r1
_081E4CA6:
	str r0, [r4]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E4CB0: .4byte 0xFFFBFFFF

	thumb_func_start FUN_081e4cb4
FUN_081e4cb4: @ 0x081E4CB4
	push {r4, r5, lr}
	adds r4, r2, #0
	ldr r2, _081E4CE4 @ =0x00001610
	adds r5, r0, r2
	ldr r3, _081E4CE8 @ =0xFFBFFFFF
	ldr r2, [r5]
	ands r2, r3
	str r2, [r5]
	ldr r2, _081E4CEC @ =0x0000161C
	adds r0, r0, r2
	ldr r2, [r0]
	adds r0, r1, #0
	adds r1, r4, #0
	bl FUN_081e2510
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E4CF0
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r5]
	orrs r0, r1
	b _081E4CF6
	.align 2, 0
_081E4CE4: .4byte 0x00001610
_081E4CE8: .4byte 0xFFBFFFFF
_081E4CEC: .4byte 0x0000161C
_081E4CF0:
	ldr r1, _081E4D00 @ =0xFFF7FFFF
	ldr r0, [r5]
	ands r0, r1
_081E4CF6:
	str r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E4D00: .4byte 0xFFF7FFFF

	thumb_func_start FUN_081e4d04
FUN_081e4d04: @ 0x081E4D04
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r4, #0
	bl FUN_081e2960
	adds r0, r4, #0
	bl FUN_081e3dec
	ldr r1, _081E4D64 @ =0x00000BB4
	adds r0, r4, r1
	movs r1, #0x10
	bl ClearMemory
	adds r0, r4, #0
	bl FUN_081e3594
	ldr r1, [r4, #0x1c]
	movs r0, #3
	movs r2, #1
	bl FUN_0822c398
	movs r0, #0
	str r0, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	bl FUN_081e23e4
	cmp r0, #0
	beq _081E4D68
	adds r0, r4, #0
	bl FUN_081e2d98
	adds r0, r4, #0
	bl FUN_081e2c14
	b _081E4D6E
	.align 2, 0
_081E4D64: .4byte 0x00000BB4
_081E4D68:
	adds r0, r4, #0
	bl FUN_081e2cdc
_081E4D6E:
	ldr r2, _081E4DC4 @ =0x00001615
	adds r0, r4, r2
	movs r1, #0
	strb r1, [r0]
	subs r2, #5
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _081E4DC8 @ =0x000015BC
	adds r0, r4, r1
	movs r1, #0x34
	bl ClearMemory
	ldr r2, _081E4DCC @ =0x00000E04
	adds r0, r4, r2
	movs r1, #0x24
	bl ClearMemory
	ldr r1, _081E4DD0 @ =0x00000E28
	adds r0, r4, r1
	movs r1, #0x24
	bl ClearMemory
	adds r0, r4, #0
	bl FUN_081e3ea8
	adds r0, r4, #0
	bl FUN_081e41e4
	ldr r0, _081E4DD4 @ =FUN_081e8110
	movs r2, #2
	str r0, [r4, #0x18]
	ldr r0, _081E4DD8 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E4DDC @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E4DC4: .4byte 0x00001615
_081E4DC8: .4byte 0x000015BC
_081E4DCC: .4byte 0x00000E04
_081E4DD0: .4byte 0x00000E28
_081E4DD4: .4byte FUN_081e8110
_081E4DD8: .4byte 0x00001614
_081E4DDC: .4byte 0x00001616

	thumb_func_start FUN_081e4de0
FUN_081e4de0: @ 0x081E4DE0
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r4, #0
	bl FUN_081e2960
	adds r0, r4, #0
	bl FUN_081e3dec
	adds r0, r4, #0
	bl FUN_081e3ce8
	adds r0, r4, #0
	bl FUN_081e32d8
	adds r0, r4, #0
	bl FUN_081e3444
	ldr r1, [r4, #0x1c]
	movs r0, #3
	movs r2, #1
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	bl FUN_081e23e4
	cmp r0, #0
	beq _081E4E60
	ldr r0, _081E4E54 @ =FUN_081e7db4
	str r0, [r4, #0x18]
	ldr r0, _081E4E58 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E4E5C @ =0x00001616
	adds r0, r4, r1
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_081e2d98
	adds r0, r4, #0
	bl FUN_081e2c14
	b _081E4E78
	.align 2, 0
_081E4E54: .4byte FUN_081e7db4
_081E4E58: .4byte 0x00001614
_081E4E5C: .4byte 0x00001616
_081E4E60:
	ldr r0, _081E4EC0 @ =FUN_081e7fd0
	movs r1, #1
	str r0, [r4, #0x18]
	ldr r2, _081E4EC4 @ =0x00001614
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_081e2cdc
_081E4E78:
	ldr r0, _081E4EC8 @ =0x00001615
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _081E4ECC @ =0x00001610
	adds r1, r4, r2
	movs r0, #0x3e
	str r0, [r1]
	ldr r1, _081E4ED0 @ =0x000015BC
	adds r0, r4, r1
	movs r1, #0x34
	bl ClearMemory
	ldr r2, _081E4ED4 @ =0x00000E04
	adds r0, r4, r2
	movs r1, #0x24
	bl ClearMemory
	ldr r1, _081E4ED8 @ =0x00000E28
	adds r0, r4, r1
	movs r1, #0x24
	bl ClearMemory
	adds r0, r4, #0
	bl FUN_081e3ea8
	adds r0, r4, #0
	bl FUN_081e4388
	adds r0, r4, #0
	bl FUN_081e49a8
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E4EC0: .4byte FUN_081e7fd0
_081E4EC4: .4byte 0x00001614
_081E4EC8: .4byte 0x00001615
_081E4ECC: .4byte 0x00001610
_081E4ED0: .4byte 0x000015BC
_081E4ED4: .4byte 0x00000E04
_081E4ED8: .4byte 0x00000E28

	thumb_func_start FUN_081e4edc
FUN_081e4edc: @ 0x081E4EDC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r7, #0
	bl FUN_081e2960
	adds r0, r7, #0
	bl FUN_081e3dec
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r2, _081E4F18 @ =0x00001610
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E4F1C
	movs r0, #1
	b _081E4F1E
	.align 2, 0
_081E4F18: .4byte 0x00001610
_081E4F1C:
	movs r0, #0
_081E4F1E:
	adds r6, r0, #0
	cmp r6, #0
	bne _081E4F26
	b _081E511C
_081E4F26:
	ldr r0, _081E50CC @ =FUN_081e7414
	movs r1, #4
	str r0, [r7, #0x18]
	ldr r2, _081E50D0 @ =0x00001614
	adds r0, r7, r2
	movs r2, #0
	mov sl, r2
	movs r2, #1
	strb r2, [r0]
	ldr r2, _081E50D4 @ =0x00001616
	adds r0, r7, r2
	strb r1, [r0]
	movs r0, #0xb0
	lsls r0, r0, #5
	adds r5, r7, r0
	ldr r0, [r5]
	bl FUN_0804a210
	ldr r1, _081E50D8 @ =0x00001604
	adds r4, r7, r1
	ldr r0, [r4]
	bl FUN_0804a210
	ldr r0, [r5]
	ldr r1, _081E50DC @ =0x00000BB8
	adds r2, r7, r1
	movs r1, #1
	bl FUN_0804a40c
	ldr r0, [r4]
	ldr r4, _081E50E0 @ =0x030046A0
	ldr r2, [r4]
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #2
	bl FUN_0804a40c
	ldr r1, [r7, #0x1c]
	movs r0, #3
	movs r2, #2
	bl FUN_0822c398
	mov r2, sl
	str r2, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r7, #0
	bl FUN_081e3ea8
	movs r0, #0x81
	lsls r0, r0, #4
	adds r0, r0, r7
	mov r8, r0
	ldr r0, [r0]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
	str r0, [r2]
	ldr r1, _081E50E4 @ =0x00001619
	adds r0, r7, r1
	mov r2, sl
	strb r2, [r0]
	adds r1, #2
	adds r0, r7, r1
	movs r2, #0x11
	mov sb, r2
	mov r1, sb
	strb r1, [r0]
	adds r0, r7, #0
	bl FUN_081e3fac
	adds r0, r7, #0
	bl FUN_081e4354
	ldr r2, _081E50E8 @ =0x000014B4
	adds r1, r7, r2
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E50EC @ =0x000014CC
	adds r1, r7, r0
	movs r0, #0x30
	strh r0, [r1]
	ldr r2, _081E50F0 @ =0x000014CE
	adds r1, r7, r2
	movs r0, #0x48
	strh r0, [r1]
	ldr r1, _081E50F4 @ =0x00000E28
	adds r0, r7, r1
	movs r1, #0x24
	bl ClearMemory
	ldr r2, _081E50F8 @ =0x00000E04
	adds r0, r7, r2
	movs r1, #0x24
	bl ClearMemory
	ldr r0, [r4]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xfa
	lsls r1, r1, #2
	mov r2, sl
	str r2, [sp]
	movs r2, #0x16
	movs r3, #1
	bl FUN_081e4604
	ldr r0, [r4]
	adds r0, #0x40
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, sl
	str r2, [sp]
	movs r1, #0xa
	movs r2, #0x15
	movs r3, #0
	bl FUN_081e4604
	ldr r0, [r5]
	ldr r1, _081E50FC @ =0x000015F0
	adds r4, r7, r1
	ldr r1, [r4]
	bl FUN_0804a240
	ldr r0, [r5]
	movs r1, #0
	bl FUN_0804a2f8
	ldr r0, [r5]
	bl FUN_0804a1f0
	adds r0, r7, #0
	bl FUN_081e3680
	ldr r2, _081E5100 @ =0x000015E2
	adds r0, r7, r2
	ldrh r1, [r0]
	adds r0, r7, #0
	bl FUN_081e37a0
	ldr r1, _081E5104 @ =0x0000161A
	adds r0, r7, r1
	mov r2, sb
	strb r2, [r0]
	subs r1, #0x12
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r2, _081E5108 @ =0x00001590
	adds r1, r7, r2
	ldr r1, [r1]
	bl FUN_0804a240
	bl FUN_08049f5c
	ldr r0, _081E510C @ =0x00001610
	adds r1, r7, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	bl FUN_08049e5c
	ldr r0, [r4]
	bl VM_ParseStringRef
	adds r0, #0xf
	bl Textbox_LookupString
	bl FUN_08049e30
	ldr r0, _081E5110 @ =0x00001617
	adds r1, r7, r0
	movs r0, #0xf
	strb r0, [r1]
	ldr r2, _081E5114 @ =0x00001514
	adds r1, r7, r2
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	mov r1, r8
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0xde
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_081e49a8
	ldr r0, _081E510C @ =0x00001610
	adds r1, r7, r0
	ldr r0, _081E5118 @ =0x0000860E
	b _081E5242
	.align 2, 0
_081E50CC: .4byte FUN_081e7414
_081E50D0: .4byte 0x00001614
_081E50D4: .4byte 0x00001616
_081E50D8: .4byte 0x00001604
_081E50DC: .4byte 0x00000BB8
_081E50E0: .4byte 0x030046A0
_081E50E4: .4byte 0x00001619
_081E50E8: .4byte 0x000014B4
_081E50EC: .4byte 0x000014CC
_081E50F0: .4byte 0x000014CE
_081E50F4: .4byte 0x00000E28
_081E50F8: .4byte 0x00000E04
_081E50FC: .4byte 0x000015F0
_081E5100: .4byte 0x000015E2
_081E5104: .4byte 0x0000161A
_081E5108: .4byte 0x00001590
_081E510C: .4byte 0x00001610
_081E5110: .4byte 0x00001617
_081E5114: .4byte 0x00001514
_081E5118: .4byte 0x0000860E
_081E511C:
	ldr r0, _081E5254 @ =FUN_081e6f28
	movs r2, #3
	str r0, [r7, #0x18]
	ldr r0, _081E5258 @ =0x00001614
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E525C @ =0x00001616
	adds r0, r7, r1
	strb r2, [r0]
	bl FUN_08049e5c
	bl FUN_08049fa8
	ldr r2, _081E5260 @ =0x00001610
	adds r1, r7, r2
	movs r4, #2
	rsbs r4, r4, #0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #5
	adds r0, r0, r7
	mov r8, r0
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, _081E5264 @ =0x00001604
	adds r0, r7, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, [r7, #0x1c]
	movs r0, #3
	movs r2, #3
	bl FUN_0822c398
	str r6, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r7, #0
	bl FUN_081e3ea8
	movs r2, #0x81
	lsls r2, r2, #4
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r0, #0xa5
	lsls r0, r0, #4
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	ldr r1, _081E5268 @ =0x00001619
	adds r0, r7, r1
	strb r6, [r0]
	adds r0, r7, #0
	bl FUN_081e3fac
	adds r0, r7, #0
	bl FUN_081e4354
	ldr r2, _081E526C @ =0x000014B4
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	ldr r0, _081E5270 @ =0x000014CC
	adds r1, r7, r0
	movs r2, #0
	movs r0, #0x30
	strh r0, [r1]
	ldr r0, _081E5274 @ =0x000014CE
	adds r1, r7, r0
	movs r0, #0x48
	strh r0, [r1]
	ldr r1, _081E5278 @ =0x0000161A
	adds r5, r7, r1
	strb r2, [r5]
	ldr r2, _081E527C @ =0x00001608
	adds r4, r7, r2
	ldr r0, [r4]
	subs r2, #0x78
	adds r1, r7, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	bl FUN_0804a1f0
	adds r0, r7, #0
	bl FUN_081e4544
	ldrb r1, [r5]
	ldr r2, _081E5280 @ =0x00001617
	adds r0, r7, r2
	strb r1, [r0]
	ldr r4, _081E5284 @ =0x030046A0
	ldr r0, [r4]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xfa
	lsls r1, r1, #2
	str r6, [sp]
	movs r2, #0x16
	movs r3, #1
	bl FUN_081e4604
	ldr r0, [r4]
	adds r0, #0x40
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r6, [sp]
	movs r1, #0xa
	movs r2, #0x15
	movs r3, #0
	bl FUN_081e4604
	mov r2, r8
	ldr r0, [r2]
	ldr r2, _081E5288 @ =0x000015F0
	adds r1, r7, r2
	ldr r1, [r1]
	bl FUN_0804a240
	mov r1, r8
	ldr r0, [r1]
	movs r1, #0
	bl FUN_0804a2f8
	mov r2, r8
	ldr r0, [r2]
	bl FUN_0804a1f0
	ldr r0, _081E5260 @ =0x00001610
	adds r1, r7, r0
	ldr r0, _081E528C @ =0x0001010E
_081E5242:
	str r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E5254: .4byte FUN_081e6f28
_081E5258: .4byte 0x00001614
_081E525C: .4byte 0x00001616
_081E5260: .4byte 0x00001610
_081E5264: .4byte 0x00001604
_081E5268: .4byte 0x00001619
_081E526C: .4byte 0x000014B4
_081E5270: .4byte 0x000014CC
_081E5274: .4byte 0x000014CE
_081E5278: .4byte 0x0000161A
_081E527C: .4byte 0x00001608
_081E5280: .4byte 0x00001617
_081E5284: .4byte 0x030046A0
_081E5288: .4byte 0x000015F0
_081E528C: .4byte 0x0001010E

	thumb_func_start FUN_081e5290
FUN_081e5290: @ 0x081E5290
	push {lr}
	ldr r2, _081E52A8 @ =0x00001628
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081E52A2
	movs r1, #0
	bl Script_ExecById
_081E52A2:
	pop {r0}
	bx r0
	.align 2, 0
_081E52A8: .4byte 0x00001628

	thumb_func_start FUN_081e52ac
FUN_081e52ac: @ 0x081E52AC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _081E5384 @ =0x000014AC
	adds r7, r6, r0
	ldr r1, _081E5388 @ =0x00001614
	adds r5, r6, r1
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E5342
	ldr r2, _081E538C @ =0x00001599
	adds r4, r6, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r3, _081E5390 @ =0x00000E4C
	adds r1, r1, r3
	adds r1, r6, r1
	adds r0, r7, #0
	movs r2, #0xd
	bl FUN_0822f588
	ldr r0, [r7, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #8]
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r6, r0
	ldr r1, _081E5394 @ =0x00000E86
	adds r0, r0, r1
	movs r2, #0
	mov r8, r2
	movs r2, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	strh r1, [r0]
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r3, _081E5398 @ =0x00000E94
	adds r1, r6, r3
	adds r1, r1, r0
	ldr r0, _081E539C @ =0x03003584
	ldr r0, [r0]
	movs r3, #0xb8
	lsls r3, r3, #7
	adds r0, r0, r3
	str r0, [r1]
	ldr r0, _081E53A0 @ =0x000015B4
	adds r1, r6, r0
	movs r0, #0x30
	strh r0, [r1]
	ldr r3, _081E53A4 @ =0x000015B6
	adds r1, r6, r3
	movs r0, #0x48
	strh r0, [r1]
	ldr r1, _081E53A8 @ =0x0000159A
	adds r0, r6, r1
	strh r2, [r0]
	ldr r0, _081E53AC @ =0x0000038A
	bl PlaySound_082406e0
	mov r2, r8
	strb r2, [r5]
_081E5342:
	ldr r3, _081E53B0 @ =0x000014CC
	adds r1, r6, r3
	ldr r0, _081E53A0 @ =0x000015B4
	adds r2, r6, r0
	adds r3, #0xce
	adds r4, r6, r3
	ldrh r3, [r4]
	movs r0, #5
	str r0, [sp]
	adds r0, r1, #0
	bl LerpVec3
	ldrh r0, [r4]
	cmp r0, #0xb
	bls _081E53C0
	movs r0, #0x30
	strh r0, [r7, #0x20]
	movs r0, #0x48
	strh r0, [r7, #0x22]
	ldr r0, _081E53B4 @ =FUN_081e6f28
	movs r2, #3
	str r0, [r6, #0x18]
	ldr r0, _081E5388 @ =0x00001614
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E53B8 @ =0x00001616
	adds r0, r6, r1
	strb r2, [r0]
	ldr r0, _081E53BC @ =0x00000111
	bl PlaySound_082406e0
	b _081E53D2
	.align 2, 0
_081E5384: .4byte 0x000014AC
_081E5388: .4byte 0x00001614
_081E538C: .4byte 0x00001599
_081E5390: .4byte 0x00000E4C
_081E5394: .4byte 0x00000E86
_081E5398: .4byte 0x00000E94
_081E539C: .4byte 0x03003584
_081E53A0: .4byte 0x000015B4
_081E53A4: .4byte 0x000015B6
_081E53A8: .4byte 0x0000159A
_081E53AC: .4byte 0x0000038A
_081E53B0: .4byte 0x000014CC
_081E53B4: .4byte FUN_081e6f28
_081E53B8: .4byte 0x00001616
_081E53BC: .4byte 0x00000111
_081E53C0:
	ldr r2, _081E53E0 @ =0x00000808
	adds r0, r6, r2
	ldr r3, _081E53E4 @ =0x00000AC8
	adds r1, r6, r3
	bl MainSprite_AdvanceAnim
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_081E53D2:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E53E0: .4byte 0x00000808
_081E53E4: .4byte 0x00000AC8

	thumb_func_start FUN_081e53e8
FUN_081e53e8: @ 0x081E53E8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa
	bne _081E5454
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r5, r3
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r6, _081E543C @ =0x00001514
	adds r1, r5, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r7, _081E5440 @ =0x00001624
	adds r0, r5, r7
	strb r2, [r0]
	ldr r0, _081E5444 @ =0x000014B4
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E5448 @ =FUN_081e653c
	movs r1, #0x11
	str r0, [r5, #0x18]
	ldr r3, _081E544C @ =0x00001614
	adds r0, r5, r3
	strb r2, [r0]
	ldr r6, _081E5450 @ =0x00001616
	adds r0, r5, r6
	strb r1, [r0]
	b _081E5634
	.align 2, 0
_081E543C: .4byte 0x00001514
_081E5440: .4byte 0x00001624
_081E5444: .4byte 0x000014B4
_081E5448: .4byte FUN_081e653c
_081E544C: .4byte 0x00001614
_081E5450: .4byte 0x00001616
_081E5454:
	ldr r7, _081E54D8 @ =0x00001614
	adds r7, r7, r5
	mov r8, r7
	ldrb r0, [r7]
	cmp r0, #0
	beq _081E54F8
	ldr r1, _081E54DC @ =0x00001608
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r2, _081E54E0 @ =0x00001514
	adds r1, r5, r2
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r6, #0xa5
	lsls r6, r6, #4
	adds r1, r5, r6
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r7, _081E54E4 @ =0x0000161C
	adds r1, r5, r7
	ldr r0, _081E54E8 @ =0x03002CF0
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _081E54EC @ =0x00000E28
	adds r1, r5, r0
	adds r2, #0x85
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r2, r0, #3
	adds r2, r2, r0
	lsls r2, r2, #2
	adds r2, r5, r2
	adds r0, r1, #0
	ldr r3, _081E54F0 @ =0x00000BC4
	adds r2, r2, r3
	ldm r2!, {r3, r6, r7}
	stm r0!, {r3, r6, r7}
	ldm r2!, {r3, r6, r7}
	stm r0!, {r3, r6, r7}
	ldm r2!, {r3, r6, r7}
	stm r0!, {r3, r6, r7}
	adds r0, r5, #0
	movs r2, #3
	bl FUN_081e4cb4
	ldr r6, _081E54F4 @ =0x00001622
	adds r0, r5, r6
	movs r1, #0
	strb r4, [r0]
	mov r7, r8
	strb r1, [r7]
	b _081E5634
	.align 2, 0
_081E54D8: .4byte 0x00001614
_081E54DC: .4byte 0x00001608
_081E54E0: .4byte 0x00001514
_081E54E4: .4byte 0x0000161C
_081E54E8: .4byte 0x03002CF0
_081E54EC: .4byte 0x00000E28
_081E54F0: .4byte 0x00000BC4
_081E54F4: .4byte 0x00001622
_081E54F8:
	adds r0, r5, #0
	bl FUN_081e2ee8
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E550A
	b _081E5634
_081E550A:
	ldr r1, _081E5520 @ =0x00001622
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _081E557C
	cmp r0, #2
	bgt _081E5524
	cmp r0, #1
	beq _081E552A
	b _081E5634
	.align 2, 0
_081E5520: .4byte 0x00001622
_081E5524:
	cmp r0, #3
	beq _081E55CC
	b _081E5634
_081E552A:
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r2, _081E5540 @ =0x00001610
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E5544
	movs r0, #1
	b _081E5546
	.align 2, 0
_081E5540: .4byte 0x00001610
_081E5544:
	movs r0, #0
_081E5546:
	cmp r0, #0
	beq _081E555C
	ldr r3, _081E5558 @ =0x00000E28
	adds r1, r5, r3
	adds r0, r5, #0
	movs r2, #3
	bl FUN_081e4cb4
	b _081E5634
	.align 2, 0
_081E5558: .4byte 0x00000E28
_081E555C:
	ldr r6, _081E5574 @ =0x00000E28
	adds r1, r5, r6
	adds r0, r5, #0
	movs r2, #4
	bl FUN_081e4cb4
	ldr r7, _081E5578 @ =0x00001622
	adds r1, r5, r7
	movs r0, #2
	strb r0, [r1]
	b _081E5634
	.align 2, 0
_081E5574: .4byte 0x00000E28
_081E5578: .4byte 0x00001622
_081E557C:
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r2, _081E5590 @ =0x00001610
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E5594
	movs r0, #1
	b _081E5596
	.align 2, 0
_081E5590: .4byte 0x00001610
_081E5594:
	movs r0, #0
_081E5596:
	cmp r0, #0
	beq _081E55AC
	ldr r3, _081E55A8 @ =0x00000E28
	adds r1, r5, r3
	adds r0, r5, #0
	movs r2, #4
	bl FUN_081e4cb4
	b _081E5634
	.align 2, 0
_081E55A8: .4byte 0x00000E28
_081E55AC:
	ldr r6, _081E55C4 @ =0x00000E28
	adds r1, r5, r6
	adds r0, r5, #0
	movs r2, #5
	bl FUN_081e4cb4
	ldr r7, _081E55C8 @ =0x00001622
	adds r1, r5, r7
	movs r0, #3
	strb r0, [r1]
	b _081E5634
	.align 2, 0
_081E55C4: .4byte 0x00000E28
_081E55C8: .4byte 0x00001622
_081E55CC:
	movs r2, #0x80
	lsls r2, r2, #0xc
	ldr r0, _081E55E4 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E55E8
	movs r0, #1
	b _081E55EA
	.align 2, 0
_081E55E4: .4byte 0x00001610
_081E55E8:
	movs r0, #0
_081E55EA:
	cmp r0, #0
	beq _081E5600
	ldr r2, _081E55FC @ =0x00000E28
	adds r1, r5, r2
	adds r0, r5, #0
	movs r2, #5
	bl FUN_081e4cb4
	b _081E5634
	.align 2, 0
_081E55FC: .4byte 0x00000E28
_081E5600:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E5610
	movs r0, #1
	b _081E5612
_081E5610:
	movs r0, #0
_081E5612:
	cmp r0, #0
	beq _081E5634
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E5634
	ldr r0, _081E5640 @ =FUN_081e57f4
	movs r2, #0xa
	str r0, [r5, #0x18]
	ldr r3, _081E5644 @ =0x00001614
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	ldr r6, _081E5648 @ =0x00001616
	adds r0, r5, r6
	strb r2, [r0]
_081E5634:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E5640: .4byte FUN_081e57f4
_081E5644: .4byte 0x00001614
_081E5648: .4byte 0x00001616

	thumb_func_start FUN_081e564c
FUN_081e564c: @ 0x081E564C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa
	bne _081E56C0
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r5, r3
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E56A8 @ =0x00001514
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r3, #0xde
	lsls r3, r3, #3
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E56AC @ =0x000014B4
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081E56B0 @ =0x00001624
	adds r0, r5, r1
	strb r2, [r0]
	ldr r0, _081E56B4 @ =FUN_081e653c
	movs r1, #0x11
	str r0, [r5, #0x18]
	ldr r3, _081E56B8 @ =0x00001614
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081E56BC @ =0x00001616
	adds r0, r5, r2
	strb r1, [r0]
	b _081E57E0
	.align 2, 0
_081E56A8: .4byte 0x00001514
_081E56AC: .4byte 0x000014B4
_081E56B0: .4byte 0x00001624
_081E56B4: .4byte FUN_081e653c
_081E56B8: .4byte 0x00001614
_081E56BC: .4byte 0x00001616
_081E56C0:
	ldr r3, _081E5720 @ =0x00001614
	adds r6, r5, r3
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E573C
	ldr r1, _081E5724 @ =0x00001608
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r2, _081E5728 @ =0x00001514
	adds r1, r5, r2
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r0, #0xde
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r2, _081E572C @ =0x0000161C
	adds r1, r5, r2
	ldr r0, _081E5730 @ =0x03002CF0
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0xb
	bl FUN_081e4cb4
	ldr r3, _081E5734 @ =0x00001618
	adds r1, r5, r3
	movs r2, #0
	movs r0, #0xb
	strb r0, [r1]
	ldr r1, _081E5738 @ =0x00001622
	adds r0, r5, r1
	strb r4, [r0]
	strb r2, [r6]
	b _081E57E0
	.align 2, 0
_081E5720: .4byte 0x00001614
_081E5724: .4byte 0x00001608
_081E5728: .4byte 0x00001514
_081E572C: .4byte 0x0000161C
_081E5730: .4byte 0x03002CF0
_081E5734: .4byte 0x00001618
_081E5738: .4byte 0x00001622
_081E573C:
	adds r0, r5, #0
	bl FUN_081e2ee8
	movs r2, #0x80
	lsls r2, r2, #0xc
	ldr r3, _081E5758 @ =0x00001610
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E575C
	movs r0, #1
	b _081E575E
	.align 2, 0
_081E5758: .4byte 0x00001610
_081E575C:
	movs r0, #0
_081E575E:
	cmp r0, #0
	beq _081E577C
	ldr r0, _081E5774 @ =0x000015E2
	adds r1, r5, r0
	ldr r2, _081E5778 @ =0x00001618
	adds r0, r5, r2
	ldrb r2, [r0]
	adds r0, r5, #0
	bl FUN_081e4cb4
	b _081E57E0
	.align 2, 0
_081E5774: .4byte 0x000015E2
_081E5778: .4byte 0x00001618
_081E577C:
	ldr r3, _081E57A0 @ =0x00001622
	adds r4, r5, r3
	ldrb r0, [r4]
	cmp r0, #1
	bne _081E57AC
	ldr r0, _081E57A4 @ =0x000015E2
	adds r1, r5, r0
	adds r0, r5, #0
	movs r2, #0xc
	bl FUN_081e4cb4
	ldr r2, _081E57A8 @ =0x00001618
	adds r1, r5, r2
	movs r0, #0xc
	strb r0, [r1]
	movs r0, #2
	strb r0, [r4]
	b _081E57E0
	.align 2, 0
_081E57A0: .4byte 0x00001622
_081E57A4: .4byte 0x000015E2
_081E57A8: .4byte 0x00001618
_081E57AC:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E57BC
	movs r0, #1
	b _081E57BE
_081E57BC:
	movs r0, #0
_081E57BE:
	cmp r0, #0
	beq _081E57E0
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E57E0
	ldr r0, _081E57E8 @ =FUN_081e57f4
	movs r2, #0xa
	str r0, [r5, #0x18]
	ldr r3, _081E57EC @ =0x00001614
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E57F0 @ =0x00001616
	adds r0, r5, r1
	strb r2, [r0]
_081E57E0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E57E8: .4byte FUN_081e57f4
_081E57EC: .4byte 0x00001614
_081E57F0: .4byte 0x00001616

	thumb_func_start FUN_081e57f4
FUN_081e57f4: @ 0x081E57F4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081E5824 @ =0x00001614
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E580E
	adds r0, r4, #0
	movs r1, #4
	bl FUN_081e4c64
	movs r0, #0
	strb r0, [r5]
_081E580E:
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r3, _081E5828 @ =0x00001610
	adds r1, r4, r3
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E582C
	movs r0, #1
	b _081E582E
	.align 2, 0
_081E5824: .4byte 0x00001614
_081E5828: .4byte 0x00001610
_081E582C:
	movs r0, #0
_081E582E:
	cmp r0, #0
	beq _081E583C
	adds r0, r4, #0
	movs r1, #4
	bl FUN_081e4c64
	b _081E58D6
_081E583C:
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0xa
	bne _081E5868
	adds r1, #4
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	ldr r0, _081E5860 @ =FUN_081e653c
	movs r2, #0x11
	str r0, [r4, #0x18]
	ldr r3, _081E5864 @ =0x00001614
	adds r0, r4, r3
	strb r1, [r0]
	b _081E58BA
	.align 2, 0
_081E5860: .4byte FUN_081e653c
_081E5864: .4byte 0x00001614
_081E5868:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E5878
	movs r0, #1
	b _081E587A
_081E5878:
	movs r0, #0
_081E587A:
	cmp r0, #0
	beq _081E58D0
	movs r3, #0xb1
	lsls r3, r3, #5
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #4
	beq _081E58A2
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E589C
	movs r0, #1
	b _081E589E
_081E589C:
	movs r0, #0
_081E589E:
	cmp r0, #0
	beq _081E58D0
_081E58A2:
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E58D0
	ldr r0, _081E58C4 @ =FUN_081e58dc
	movs r2, #0xc
	str r0, [r4, #0x18]
	ldr r3, _081E58C8 @ =0x00001614
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
_081E58BA:
	ldr r1, _081E58CC @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	b _081E58D6
	.align 2, 0
_081E58C4: .4byte FUN_081e58dc
_081E58C8: .4byte 0x00001614
_081E58CC: .4byte 0x00001616
_081E58D0:
	adds r0, r4, #0
	bl FUN_081e2ee8
_081E58D6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e58dc
FUN_081e58dc: @ 0x081E58DC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _081E5A6C @ =0x00001614
	adds r0, r0, r7
	mov sl, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E58F8
	b _081E5A48
_081E58F8:
	bl FUN_08049e5c
	bl FUN_08049f84
	ldr r2, _081E5A70 @ =0x00001610
	adds r1, r7, r2
	movs r3, #2
	rsbs r3, r3, #0
	mov sb, r3
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_081e3fe0
	adds r0, r7, #0
	bl FUN_081e4450
	movs r0, #0x14
	str r0, [sp]
	movs r6, #0
	str r6, [sp, #4]
	str r6, [sp, #8]
	str r6, [sp, #0xc]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0x1e
	bl FUN_0822bdb8
	adds r0, r7, #0
	bl FUN_081e47c4
	adds r0, r7, #0
	bl FUN_081e4838
	ldr r1, [r7, #0x1c]
	movs r0, #3
	movs r2, #4
	bl FUN_0822c398
	str r6, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #0xb0
	lsls r0, r0, #5
	adds r4, r7, r0
	ldr r0, [r4]
	movs r5, #2
	str r5, [sp]
	movs r1, #0xd
	movs r2, #4
	movs r3, #0xa
	bl FUN_0804a38c
	ldr r0, [r4]
	ldr r1, _081E5A74 @ =0x000015F0
	adds r1, r1, r7
	mov r8, r1
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #0
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldr r2, _081E5A78 @ =0x00001604
	adds r4, r7, r2
	ldr r0, [r4]
	str r5, [sp]
	movs r1, #0xd
	movs r2, #0xa
	movs r3, #0xa
	bl FUN_0804a38c
	ldr r0, [r4]
	mov r3, r8
	ldr r1, [r3]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #1
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldr r0, _081E5A7C @ =0x00001608
	adds r4, r7, r0
	ldr r0, [r4]
	str r5, [sp]
	movs r1, #8
	movs r2, #7
	movs r3, #0x1c
	bl FUN_0804a38c
	ldr r0, [r4]
	ldr r2, _081E5A80 @ =0x00001590
	adds r1, r7, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	ldr r3, _081E5A84 @ =0x00000E28
	adds r5, r7, r3
	ldr r1, _081E5A88 @ =0x0000159C
	adds r2, r7, r1
	adds r1, r5, #0
	bl FUN_08094d30
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldr r2, _081E5A8C @ =0x000014AC
	adds r0, r7, r2
	ldr r3, _081E5A90 @ =0x0000156C
	adds r1, r7, r3
	ldrb r2, [r5]
	bl MainSprite_LoadPose
	ldr r0, _081E5A94 @ =0x000014CC
	adds r1, r7, r0
	movs r5, #0
	movs r0, #0x20
	strh r0, [r1]
	ldr r2, _081E5A98 @ =0x000014CE
	adds r1, r7, r2
	movs r0, #0x38
	strh r0, [r1]
	ldr r3, _081E5A9C @ =0x000014B4
	adds r1, r7, r3
	ldr r0, [r1]
	mov r2, sb
	ands r0, r2
	str r0, [r1]
	ldr r3, _081E5AA0 @ =0x0000160C
	adds r4, r7, r3
	ldr r0, [r4]
	mov r2, r8
	ldr r1, [r2]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #0xb
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	adds r0, r7, #0
	bl FUN_081e4948
	movs r3, #0xb1
	lsls r3, r3, #5
	adds r0, r7, r3
	strh r6, [r0]
	ldr r1, _081E5AA4 @ =0x0000162A
	adds r0, r7, r1
	strh r6, [r0]
	mov r2, sl
	strb r5, [r2]
_081E5A48:
	ldr r3, _081E5AA8 @ =0x000009E8
	adds r6, r7, r3
	ldr r0, _081E5AAC @ =0x00000AC8
	adds r0, r0, r7
	mov r8, r0
	adds r0, r6, #0
	mov r1, r8
	bl MainSprite_AdvanceAnim
	ldr r2, _081E5AA4 @ =0x0000162A
	adds r1, r7, r2
	ldrh r0, [r1]
	cmp r0, #0x1d
	bhi _081E5AB0
	adds r0, #1
	strh r0, [r1]
	b _081E5C24
	.align 2, 0
_081E5A6C: .4byte 0x00001614
_081E5A70: .4byte 0x00001610
_081E5A74: .4byte 0x000015F0
_081E5A78: .4byte 0x00001604
_081E5A7C: .4byte 0x00001608
_081E5A80: .4byte 0x00001590
_081E5A84: .4byte 0x00000E28
_081E5A88: .4byte 0x0000159C
_081E5A8C: .4byte 0x000014AC
_081E5A90: .4byte 0x0000156C
_081E5A94: .4byte 0x000014CC
_081E5A98: .4byte 0x000014CE
_081E5A9C: .4byte 0x000014B4
_081E5AA0: .4byte 0x0000160C
_081E5AA4: .4byte 0x0000162A
_081E5AA8: .4byte 0x000009E8
_081E5AAC: .4byte 0x00000AC8
_081E5AB0:
	ldr r0, _081E5AE8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081E5AF8
	adds r0, r7, #0
	movs r1, #9
	bl FUN_081e4c64
	ldr r3, _081E5AEC @ =0x00001618
	adds r1, r7, r3
	movs r2, #0
	movs r0, #9
	strb r0, [r1]
	ldr r1, _081E5AF0 @ =0x00001624
	adds r0, r7, r1
	strb r2, [r0]
	ldr r0, _081E5AF4 @ =FUN_081e5d14
	movs r2, #0x10
	str r0, [r7, #0x18]
	subs r3, #4
	adds r1, r7, r3
	movs r0, #1
	b _081E5BB8
	.align 2, 0
_081E5AE8: .4byte 0x030044E0
_081E5AEC: .4byte 0x00001618
_081E5AF0: .4byte 0x00001624
_081E5AF4: .4byte FUN_081e5d14
_081E5AF8:
	ldr r2, _081E5B28 @ =0x00001623
	adds r5, r7, r2
	ldrb r0, [r5]
	cmp r0, #0
	bne _081E5B78
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081E5B30
	ldr r3, _081E5B2C @ =0x00000B2C
	adds r0, r7, r3
	ldrh r2, [r0]
	str r4, [sp]
	adds r0, r6, #0
	mov r1, r8
	movs r3, #1
	bl FUN_082370cc
	movs r0, #1
	strb r0, [r5]
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _081E5BEE
	.align 2, 0
_081E5B28: .4byte 0x00001623
_081E5B2C: .4byte 0x00000B2C
_081E5B30:
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _081E5BEE
	adds r0, r7, #0
	movs r1, #3
	bl FUN_081e4c64
	ldr r0, _081E5B6C @ =FUN_081e5c40
	movs r2, #0xd
	str r0, [r7, #0x18]
	ldr r0, _081E5B70 @ =0x00001614
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E5B74 @ =0x00001616
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0x9f
	lsls r2, r2, #4
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _081E5C24
	.align 2, 0
_081E5B6C: .4byte FUN_081e5c40
_081E5B70: .4byte 0x00001614
_081E5B74: .4byte 0x00001616
_081E5B78:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne _081E5BD4
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _081E5BEE
	adds r0, r7, #0
	movs r1, #9
	bl FUN_081e4c64
	ldr r3, _081E5BC4 @ =0x00001618
	adds r1, r7, r3
	movs r0, #9
	strb r0, [r1]
	ldr r1, _081E5BC8 @ =0x00001624
	adds r0, r7, r1
	strb r4, [r0]
	movs r2, #0x9f
	lsls r2, r2, #4
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	ldr r0, _081E5BCC @ =FUN_081e5d14
	movs r2, #0x10
	str r0, [r7, #0x18]
	subs r3, #4
	adds r1, r7, r3
	movs r0, #1
_081E5BB8:
	strb r0, [r1]
	ldr r1, _081E5BD0 @ =0x00001616
	adds r0, r7, r1
	strb r2, [r0]
	b _081E5C24
	.align 2, 0
_081E5BC4: .4byte 0x00001618
_081E5BC8: .4byte 0x00001624
_081E5BCC: .4byte FUN_081e5d14
_081E5BD0: .4byte 0x00001616
_081E5BD4:
	ldr r2, _081E5C34 @ =0x00000B2A
	adds r0, r7, r2
	ldrh r2, [r0]
	str r4, [sp]
	adds r0, r6, #0
	mov r1, r8
	movs r3, #1
	bl FUN_082370cc
	strb r4, [r5]
	movs r0, #0xdc
	bl PlaySound_082406e0
_081E5BEE:
	movs r3, #0xb1
	lsls r3, r3, #5
	adds r0, r7, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #9
	bne _081E5C24
	ldr r2, _081E5C38 @ =0x00001624
	adds r1, r7, r2
	movs r0, #0
	strb r0, [r1]
	ldr r0, _081E5C3C @ =FUN_081e653c
	movs r1, #0x11
	str r0, [r7, #0x18]
	subs r3, #0xc
	adds r0, r7, r3
	movs r2, #1
	strb r2, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	movs r0, #0x9f
	lsls r0, r0, #4
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081E5C24:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E5C34: .4byte 0x00000B2A
_081E5C38: .4byte 0x00001624
_081E5C3C: .4byte FUN_081e653c

	thumb_func_start FUN_081e5c40
FUN_081e5c40: @ 0x081E5C40
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081E5C88 @ =0x00001614
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E5C6A
	movs r1, #0x9f
	lsls r1, r1, #4
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _081E5C8C @ =0x0000160C
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	movs r0, #0
	strb r0, [r5]
_081E5C6A:
	adds r0, r4, #0
	bl FUN_081e2ee8
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E5C90 @ =0x00001610
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _081E5C94
	movs r0, #1
	b _081E5C96
	.align 2, 0
_081E5C88: .4byte 0x00001614
_081E5C8C: .4byte 0x0000160C
_081E5C90: .4byte 0x00001610
_081E5C94:
	movs r0, #0
_081E5C96:
	cmp r0, #0
	beq _081E5CA4
	adds r0, r4, #0
	movs r1, #3
	bl FUN_081e4c64
	b _081E5CFC
_081E5CA4:
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E5CFC
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081E5CBE
	movs r0, #1
	b _081E5CC0
_081E5CBE:
	movs r0, #0
_081E5CC0:
	cmp r0, #0
	beq _081E5CFC
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #3
	bne _081E5CDC
	ldr r0, _081E5CD8 @ =FUN_081e5dc8
	movs r2, #0xe
	b _081E5CEC
	.align 2, 0
_081E5CD8: .4byte FUN_081e5dc8
_081E5CDC:
	cmp r0, #9
	bne _081E5CFC
	ldr r0, _081E5D04 @ =0x00001624
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r0, _081E5D08 @ =FUN_081e653c
	movs r2, #0x11
_081E5CEC:
	str r0, [r4, #0x18]
	ldr r0, _081E5D0C @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E5D10 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
_081E5CFC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E5D04: .4byte 0x00001624
_081E5D08: .4byte FUN_081e653c
_081E5D0C: .4byte 0x00001614
_081E5D10: .4byte 0x00001616

	thumb_func_start FUN_081e5d14
FUN_081e5d14: @ 0x081E5D14
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081E5D5C @ =0x00001614
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E5D3E
	movs r1, #0x9f
	lsls r1, r1, #4
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _081E5D60 @ =0x0000160C
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	movs r0, #0
	strb r0, [r5]
_081E5D3E:
	adds r0, r4, #0
	bl FUN_081e2ee8
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E5D64 @ =0x00001610
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _081E5D68
	movs r0, #1
	b _081E5D6A
	.align 2, 0
_081E5D5C: .4byte 0x00001614
_081E5D60: .4byte 0x0000160C
_081E5D64: .4byte 0x00001610
_081E5D68:
	movs r0, #0
_081E5D6A:
	cmp r0, #0
	beq _081E5D80
	ldr r1, _081E5D7C @ =0x00001618
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_081e4c64
	b _081E5DB4
	.align 2, 0
_081E5D7C: .4byte 0x00001618
_081E5D80:
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E5DB4
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081E5D9A
	movs r0, #1
	b _081E5D9C
_081E5D9A:
	movs r0, #0
_081E5D9C:
	cmp r0, #0
	beq _081E5DB4
	ldr r0, _081E5DBC @ =FUN_081e653c
	movs r2, #0x11
	str r0, [r4, #0x18]
	ldr r0, _081E5DC0 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E5DC4 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
_081E5DB4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E5DBC: .4byte FUN_081e653c
_081E5DC0: .4byte 0x00001614
_081E5DC4: .4byte 0x00001616

	thumb_func_start FUN_081e5dc8
FUN_081e5dc8: @ 0x081E5DC8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r1, _081E5EF4 @ =0x00001614
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E5DE0
	b _081E5FA8
_081E5DE0:
	bl FUN_08049e5c
	bl FUN_08049f84
	ldr r2, _081E5EF8 @ =0x00001610
	adds r2, r2, r7
	mov r8, r2
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_081e3fe0
	adds r0, r7, #0
	bl FUN_081e4450
	adds r0, r7, #0
	bl FUN_081e2b08
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r7, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r2, _081E5EFC @ =0x00001604
	adds r0, r7, r2
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r0, _081E5F00 @ =0x00001608
	adds r6, r7, r0
	ldr r0, [r6]
	bl FUN_0804a210
	ldr r1, _081E5F04 @ =0x0000160C
	adds r4, r7, r1
	ldr r0, [r4]
	bl FUN_0804a210
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	ldr r1, [r7, #0x20]
	movs r0, #0
	movs r2, #4
	bl FUN_0822c398
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, [r4]
	movs r1, #6
	str r1, [sp]
	movs r1, #1
	movs r2, #6
	movs r3, #0x1c
	bl FUN_0804a38c
	ldr r0, [r4]
	ldr r2, _081E5F08 @ =0x000015F0
	adds r2, r2, r7
	mov sb, r2
	ldr r1, [r2]
	bl FUN_0804a240
	adds r0, r7, #0
	bl FUN_081e2e24
	ldr r1, _081E5F0C @ =0x00000E28
	adds r0, r7, r1
	ldr r2, _081E5F10 @ =0x0000159C
	adds r5, r7, r2
	adds r1, r5, #0
	bl FUN_08094c6c
	ldr r0, [r4]
	ldr r2, _081E5F14 @ =0x000015E2
	adds r1, r7, r2
	ldrh r2, [r1]
	movs r1, #0
	bl FUN_0804a3e4
	ldr r0, [r4]
	ldr r1, _081E5F18 @ =0x000015A4
	adds r2, r7, r1
	movs r1, #3
	bl FUN_0804a40c
	ldr r0, [r4]
	movs r1, #4
	adds r2, r5, #0
	bl FUN_0804a40c
	ldr r0, [r4]
	ldr r1, _081E5F1C @ =0x00000BB8
	adds r2, r7, r1
	movs r1, #2
	bl FUN_0804a40c
	ldr r0, [r6]
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	movs r2, #0xf
	movs r3, #0x1e
	bl FUN_0804a38c
	ldr r0, [r6]
	mov r2, sb
	ldr r1, [r2]
	bl FUN_0804a240
	ldr r0, [r6]
	movs r1, #0x12
	bl FUN_0804a2f8
	ldr r0, [r6]
	bl FUN_0804a1f0
	movs r1, #0x80
	lsls r1, r1, #9
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E5F20
	movs r0, #1
	b _081E5F22
	.align 2, 0
_081E5EF4: .4byte 0x00001614
_081E5EF8: .4byte 0x00001610
_081E5EFC: .4byte 0x00001604
_081E5F00: .4byte 0x00001608
_081E5F04: .4byte 0x0000160C
_081E5F08: .4byte 0x000015F0
_081E5F0C: .4byte 0x00000E28
_081E5F10: .4byte 0x0000159C
_081E5F14: .4byte 0x000015E2
_081E5F18: .4byte 0x000015A4
_081E5F1C: .4byte 0x00000BB8
_081E5F20:
	movs r0, #0
_081E5F22:
	cmp r0, #0
	beq _081E5F5C
	ldr r1, _081E5F40 @ =0x000015E2
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _081E5F48
	ldr r2, _081E5F44 @ =0x0000160C
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0xc
	bl FUN_0804a2f8
	b _081E5F88
	.align 2, 0
_081E5F40: .4byte 0x000015E2
_081E5F44: .4byte 0x0000160C
_081E5F48:
	ldr r1, _081E5F58 @ =0x0000160C
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0x17
	bl FUN_0804a2f8
	b _081E5F88
	.align 2, 0
_081E5F58: .4byte 0x0000160C
_081E5F5C:
	ldr r2, _081E5F74 @ =0x000015E2
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _081E5F7C
	ldr r1, _081E5F78 @ =0x0000160C
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0xd
	bl FUN_0804a2f8
	b _081E5F88
	.align 2, 0
_081E5F74: .4byte 0x000015E2
_081E5F78: .4byte 0x0000160C
_081E5F7C:
	ldr r2, _081E5FC0 @ =0x0000160C
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0x18
	bl FUN_0804a2f8
_081E5F88:
	ldr r1, _081E5FC0 @ =0x0000160C
	adds r0, r7, r1
	ldr r0, [r0]
	bl FUN_0804a1f0
	adds r0, r7, #0
	movs r1, #7
	bl FUN_081e4c64
	ldr r0, _081E5FC4 @ =0x00000123
	bl PlaySound_082406e0
	ldr r2, _081E5FC8 @ =0x00001614
	adds r1, r7, r2
	movs r0, #0
	strb r0, [r1]
_081E5FA8:
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E5FCC @ =0x00001610
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E5FD0
	movs r0, #1
	b _081E5FD2
	.align 2, 0
_081E5FC0: .4byte 0x0000160C
_081E5FC4: .4byte 0x00000123
_081E5FC8: .4byte 0x00001614
_081E5FCC: .4byte 0x00001610
_081E5FD0:
	movs r0, #0
_081E5FD2:
	cmp r0, #0
	beq _081E5FE0
	adds r0, r7, #0
	movs r1, #7
	bl FUN_081e4c64
	b _081E6022
_081E5FE0:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E5FF0
	movs r0, #1
	b _081E5FF2
_081E5FF0:
	movs r0, #0
_081E5FF2:
	cmp r0, #0
	beq _081E6022
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #7
	bne _081E6022
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E6022
	ldr r0, _081E6030 @ =FUN_081e603c
	movs r2, #0xf
	str r0, [r7, #0x18]
	ldr r0, _081E6034 @ =0x00001614
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E6038 @ =0x00001616
	adds r0, r7, r1
	strb r2, [r0]
_081E6022:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E6030: .4byte FUN_081e603c
_081E6034: .4byte 0x00001614
_081E6038: .4byte 0x00001616

	thumb_func_start FUN_081e603c
FUN_081e603c: @ 0x081E603C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E6068 @ =0x00001614
	adds r3, r4, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081E6056
	ldr r1, _081E606C @ =0x0000162A
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081E6056:
	ldr r0, _081E606C @ =0x0000162A
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x1d
	bhi _081E6070
	adds r0, #1
	strh r0, [r1]
	b _081E60A8
	.align 2, 0
_081E6068: .4byte 0x00001614
_081E606C: .4byte 0x0000162A
_081E6070:
	ldr r0, _081E60B0 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081E60B4 @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081E60A8
	adds r0, r4, #0
	movs r1, #8
	bl FUN_081e4c64
	ldr r1, _081E60B8 @ =0x00001608
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r0, _081E60BC @ =FUN_081e60c8
	movs r2, #0x16
	str r0, [r4, #0x18]
	ldr r0, _081E60C0 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E60C4 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
_081E60A8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E60B0: .4byte 0x030044E0
_081E60B4: .4byte 0x0000030F
_081E60B8: .4byte 0x00001608
_081E60BC: .4byte FUN_081e60c8
_081E60C0: .4byte 0x00001614
_081E60C4: .4byte 0x00001616

	thumb_func_start FUN_081e60c8
FUN_081e60c8: @ 0x081E60C8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E60FC @ =0x00001614
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _081E60E0
	ldr r0, _081E6100 @ =0x00001617
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	strb r0, [r2]
_081E60E0:
	adds r0, r4, #0
	bl FUN_081e2ee8
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E6104 @ =0x00001610
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E6108
	movs r0, #1
	b _081E610A
	.align 2, 0
_081E60FC: .4byte 0x00001614
_081E6100: .4byte 0x00001617
_081E6104: .4byte 0x00001610
_081E6108:
	movs r0, #0
_081E610A:
	cmp r0, #0
	beq _081E6118
	adds r0, r4, #0
	movs r1, #8
	bl FUN_081e4c64
	b _081E6164
_081E6118:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E6128
	movs r0, #1
	b _081E612A
_081E6128:
	movs r0, #0
_081E612A:
	cmp r0, #0
	beq _081E6164
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #8
	bne _081E6164
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E6164
	ldr r1, _081E616C @ =0x0000160C
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r0, _081E6170 @ =FUN_081e617c
	movs r2, #0x17
	str r0, [r4, #0x18]
	ldr r0, _081E6174 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E6178 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
_081E6164:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E616C: .4byte 0x0000160C
_081E6170: .4byte FUN_081e617c
_081E6174: .4byte 0x00001614
_081E6178: .4byte 0x00001616

	thumb_func_start FUN_081e617c
FUN_081e617c: @ 0x081E617C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _081E6248 @ =0x00001614
	adds r7, r6, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _081E6210
	bl FUN_08049e5c
	bl FUN_08049fa8
	ldr r1, _081E624C @ =0x00001610
	adds r2, r6, r1
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	ldr r1, [r6, #0x20]
	movs r0, #0
	movs r2, #3
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r2, _081E6250 @ =0x0000160C
	adds r4, r6, r2
	ldr r0, [r4]
	bl FUN_0804a210
	ldr r0, [r4]
	movs r1, #6
	str r1, [sp]
	movs r1, #1
	movs r2, #7
	movs r3, #0x1c
	bl FUN_0804a38c
	ldr r0, [r4]
	ldr r3, _081E6254 @ =0x000015F4
	adds r1, r6, r3
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #6
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	bl FUN_081e25f0
	movs r0, #1
	bl Sound_FadeOutBGM
	ldr r4, _081E6258 @ =0x0000162A
	adds r0, r6, r4
	movs r1, #0
	strh r5, [r0]
	strb r1, [r7]
_081E6210:
	ldr r0, _081E6258 @ =0x0000162A
	adds r4, r6, r0
	ldrh r0, [r4]
	cmp r0, #0x3b
	bne _081E622C
	bl FUN_081e25d8
	movs r2, #0x80
	lsls r2, r2, #0xe
	ldr r3, _081E624C @ =0x00001610
	adds r1, r6, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081E622C:
	ldrh r0, [r4]
	cmp r0, #0x3c
	beq _081E6234
	b _081E636A
_081E6234:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r4, _081E624C @ =0x00001610
	adds r0, r6, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E625C
	movs r0, #1
	b _081E625E
	.align 2, 0
_081E6248: .4byte 0x00001614
_081E624C: .4byte 0x00001610
_081E6250: .4byte 0x0000160C
_081E6254: .4byte 0x000015F4
_081E6258: .4byte 0x0000162A
_081E625C:
	movs r0, #0
_081E625E:
	cmp r0, #0
	beq _081E62AC
	ldr r1, _081E6298 @ =0x00000E28
	adds r0, r6, r1
	bl FUN_08242b88
	ldr r3, _081E629C @ =0x030046A0
	ldr r0, [r3]
	movs r4, #0x91
	lsls r4, r4, #4
	adds r2, r0, r4
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r4, _081E62A0 @ =0x000015E2
	adds r0, r6, r4
	ldrh r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081E6286
	movs r1, #0
_081E6286:
	strh r1, [r2]
	ldr r0, [r3]
	ldr r2, _081E62A4 @ =0x0000091A
	adds r1, r0, r2
	movs r3, #0
	ldrsh r0, [r1, r3]
	adds r0, #1
	ldr r2, _081E62A8 @ =0x0000270F
	b _081E62E6
	.align 2, 0
_081E6298: .4byte 0x00000E28
_081E629C: .4byte 0x030046A0
_081E62A0: .4byte 0x000015E2
_081E62A4: .4byte 0x0000091A
_081E62A8: .4byte 0x0000270F
_081E62AC:
	ldr r4, _081E6310 @ =0x00001599
	adds r0, r6, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bl FUN_08242c08
	ldr r4, _081E6314 @ =0x030046A0
	ldr r0, [r4]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r3, r0, r1
	ldr r2, _081E6318 @ =0x000015E2
	adds r1, r6, r2
	movs r2, #0
	ldrsh r0, [r3, r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	ldr r2, _081E631C @ =0x0000270F
	cmp r0, r2
	ble _081E62D8
	adds r0, r2, #0
_081E62D8:
	strh r0, [r3]
	ldr r0, [r4]
	ldr r3, _081E6320 @ =0x00000918
	adds r1, r0, r3
	movs r4, #0
	ldrsh r0, [r1, r4]
	adds r0, #1
_081E62E6:
	cmp r0, r2
	ble _081E62EC
	adds r0, r2, #0
_081E62EC:
	strh r0, [r1]
	bl Save_WriteExtraToNextSlot
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E6330
	ldr r0, _081E6324 @ =FUN_081e6458
	movs r2, #0x19
	str r0, [r6, #0x18]
	ldr r0, _081E6328 @ =0x00001614
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E632C @ =0x00001616
	adds r0, r6, r1
	strb r2, [r0]
	b _081E6374
	.align 2, 0
_081E6310: .4byte 0x00001599
_081E6314: .4byte 0x030046A0
_081E6318: .4byte 0x000015E2
_081E631C: .4byte 0x0000270F
_081E6320: .4byte 0x00000918
_081E6324: .4byte FUN_081e6458
_081E6328: .4byte 0x00001614
_081E632C: .4byte 0x00001616
_081E6330:
	movs r0, #0x96
	lsls r0, r0, #2
	movs r1, #0
	bl FUN_081d9d38
	cmp r0, #0
	bne _081E6360
	ldr r0, _081E6354 @ =FUN_081e6458
	movs r2, #0x19
	str r0, [r6, #0x18]
	ldr r3, _081E6358 @ =0x00001614
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	ldr r4, _081E635C @ =0x00001616
	adds r0, r6, r4
	strb r2, [r0]
	b _081E6374
	.align 2, 0
_081E6354: .4byte FUN_081e6458
_081E6358: .4byte 0x00001614
_081E635C: .4byte 0x00001616
_081E6360:
	ldr r1, _081E637C @ =FUN_081e4b68
	ldr r2, _081E6380 @ =FUN_081e4bb8
	adds r0, r6, #0
	bl FUN_081d9d88
_081E636A:
	ldr r0, _081E6384 @ =0x0000162A
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081E6374:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E637C: .4byte FUN_081e4b68
_081E6380: .4byte FUN_081e4bb8
_081E6384: .4byte 0x0000162A

	thumb_func_start FUN_081e6388
FUN_081e6388: @ 0x081E6388
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _081E63AC @ =0x00001614
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081E6410
	movs r2, #1
	ldr r0, _081E63B0 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081E63B4
	movs r0, #1
	b _081E63B6
	.align 2, 0
_081E63AC: .4byte 0x00001614
_081E63B0: .4byte 0x00001610
_081E63B4:
	movs r0, #0
_081E63B6:
	cmp r0, #0
	beq _081E63CC
	bl FUN_08049e5c
	bl FUN_08049f84
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
_081E63CC:
	ldr r1, _081E63FC @ =0x0000160C
	adds r4, r5, r1
	ldr r0, [r4]
	ldr r2, _081E6400 @ =0x000015F4
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #7
	bl FUN_0804a2f8
	ldr r0, _081E6404 @ =0x000002AE
	bl PlaySound_082406e0
	ldr r0, _081E6408 @ =0x0000162A
	adds r1, r5, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _081E640C @ =0x00001614
	adds r0, r5, r1
	strb r2, [r0]
	b _081E6448
	.align 2, 0
_081E63FC: .4byte 0x0000160C
_081E6400: .4byte 0x000015F4
_081E6404: .4byte 0x000002AE
_081E6408: .4byte 0x0000162A
_081E640C: .4byte 0x00001614
_081E6410:
	ldr r2, _081E6434 @ =0x0000162A
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #0
	bne _081E6448
	movs r0, #0xc8
	lsls r0, r0, #1
	movs r1, #0
	bl FUN_081d9d38
	cmp r0, #0
	bne _081E6438
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_081e4c40
	b _081E6448
	.align 2, 0
_081E6434: .4byte 0x0000162A
_081E6438:
	ldr r1, _081E6450 @ =FUN_081e4bdc
	ldr r2, _081E6454 @ =FUN_081e4c40
	adds r0, r5, #0
	bl FUN_081d9d88
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_081E6448:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E6450: .4byte FUN_081e4bdc
_081E6454: .4byte FUN_081e4c40

	thumb_func_start FUN_081e6458
FUN_081e6458: @ 0x081E6458
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081E64A8 @ =0x00001614
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E6496
	ldr r2, _081E64AC @ =0x0000160C
	adds r4, r5, r2
	ldr r0, [r4]
	subs r2, #0x18
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #5
	bl FUN_0804a2f8
	ldr r0, _081E64B0 @ =0x0000162A
	adds r1, r5, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r6]
	bl FUN_081e260c
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081E6496:
	ldr r2, _081E64B0 @ =0x0000162A
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #0x3b
	bhi _081E64B4
	adds r0, #1
	strh r0, [r1]
	b _081E64C2
	.align 2, 0
_081E64A8: .4byte 0x00001614
_081E64AC: .4byte 0x0000160C
_081E64B0: .4byte 0x0000162A
_081E64B4:
	movs r2, #0x80
	lsls r2, r2, #0x10
	ldr r0, _081E64C8 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081E64C2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E64C8: .4byte 0x00001610

	thumb_func_start FUN_081e64cc
FUN_081e64cc: @ 0x081E64CC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081E6518 @ =0x00001614
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E6508
	ldr r2, _081E651C @ =0x0000160C
	adds r4, r5, r2
	ldr r0, [r4]
	subs r2, #0x18
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #2
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldr r0, _081E6520 @ =0x0000162A
	adds r1, r5, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r6]
	bl FUN_081e260c
_081E6508:
	ldr r2, _081E6520 @ =0x0000162A
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #0x3b
	bhi _081E6524
	adds r0, #1
	strh r0, [r1]
	b _081E6532
	.align 2, 0
_081E6518: .4byte 0x00001614
_081E651C: .4byte 0x0000160C
_081E6520: .4byte 0x0000162A
_081E6524:
	movs r2, #0x80
	lsls r2, r2, #0x10
	ldr r0, _081E6538 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081E6532:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E6538: .4byte 0x00001610

	thumb_func_start FUN_081e653c
FUN_081e653c: @ 0x081E653C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	ldr r1, _081E6584 @ =0x00001614
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E654E
	b _081E664A
_081E654E:
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	ldr r1, [r7, #0x20]
	movs r0, #0
	movs r2, #4
	bl FUN_0822c398
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r1, #1
	ldr r2, _081E6588 @ =0x00001610
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E658C
	movs r0, #1
	b _081E658E
	.align 2, 0
_081E6584: .4byte 0x00001614
_081E6588: .4byte 0x00001610
_081E658C:
	movs r0, #0
_081E658E:
	cmp r0, #0
	beq _081E65A8
	bl FUN_08049e5c
	bl FUN_08049f84
	ldr r0, _081E6660 @ =0x00001610
	adds r2, r7, r0
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081E65A8:
	adds r0, r7, #0
	bl FUN_081e3fe0
	adds r0, r7, #0
	bl FUN_081e4450
	adds r0, r7, #0
	bl FUN_081e2b08
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r7, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r2, _081E6664 @ =0x00001604
	adds r0, r7, r2
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r0, _081E6668 @ =0x00001608
	adds r5, r7, r0
	ldr r0, [r5]
	bl FUN_0804a210
	ldr r1, _081E666C @ =0x0000160C
	adds r4, r7, r1
	ldr r0, [r4]
	bl FUN_0804a210
	ldr r0, [r4]
	movs r1, #6
	str r1, [sp]
	movs r1, #1
	movs r2, #6
	movs r3, #0x1c
	bl FUN_0804a38c
	ldr r0, [r4]
	ldr r2, _081E6670 @ =0x000015F0
	adds r6, r7, r2
	ldr r1, [r6]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #0xe
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldr r0, [r5]
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	movs r2, #0xf
	movs r3, #0x1e
	bl FUN_0804a38c
	ldr r0, [r5]
	ldr r1, [r6]
	bl FUN_0804a240
	ldr r0, [r5]
	movs r1, #0x12
	bl FUN_0804a2f8
	ldr r0, [r5]
	bl FUN_0804a1f0
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r7, #0
	movs r1, #5
	bl FUN_081e4c64
	ldr r0, _081E6674 @ =0x00001614
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
_081E664A:
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E6660 @ =0x00001610
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E6678
	movs r0, #1
	b _081E667A
	.align 2, 0
_081E6660: .4byte 0x00001610
_081E6664: .4byte 0x00001604
_081E6668: .4byte 0x00001608
_081E666C: .4byte 0x0000160C
_081E6670: .4byte 0x000015F0
_081E6674: .4byte 0x00001614
_081E6678:
	movs r0, #0
_081E667A:
	cmp r0, #0
	beq _081E6688
	adds r0, r7, #0
	movs r1, #5
	bl FUN_081e4c64
	b _081E66CA
_081E6688:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E6698
	movs r0, #1
	b _081E669A
_081E6698:
	movs r0, #0
_081E669A:
	cmp r0, #0
	beq _081E66CA
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #5
	bne _081E66CA
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E66CA
	ldr r0, _081E66D4 @ =FUN_081e66e0
	movs r2, #0x12
	str r0, [r7, #0x18]
	ldr r0, _081E66D8 @ =0x00001614
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E66DC @ =0x00001616
	adds r0, r7, r1
	strb r2, [r0]
_081E66CA:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E66D4: .4byte FUN_081e66e0
_081E66D8: .4byte 0x00001614
_081E66DC: .4byte 0x00001616

	thumb_func_start FUN_081e66e0
FUN_081e66e0: @ 0x081E66E0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E670C @ =0x00001614
	adds r3, r4, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081E66FA
	ldr r1, _081E6710 @ =0x0000162A
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081E66FA:
	ldr r0, _081E6710 @ =0x0000162A
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x1d
	bhi _081E6714
	adds r0, #1
	strh r0, [r1]
	b _081E674C
	.align 2, 0
_081E670C: .4byte 0x00001614
_081E6710: .4byte 0x0000162A
_081E6714:
	ldr r0, _081E6754 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081E6758 @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081E674C
	adds r0, r4, #0
	movs r1, #6
	bl FUN_081e4c64
	ldr r1, _081E675C @ =0x00001608
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r0, _081E6760 @ =FUN_081e676c
	movs r2, #0x13
	str r0, [r4, #0x18]
	ldr r0, _081E6764 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E6768 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
_081E674C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E6754: .4byte 0x030044E0
_081E6758: .4byte 0x0000030F
_081E675C: .4byte 0x00001608
_081E6760: .4byte FUN_081e676c
_081E6764: .4byte 0x00001614
_081E6768: .4byte 0x00001616

	thumb_func_start FUN_081e676c
FUN_081e676c: @ 0x081E676C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E67A0 @ =0x00001614
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _081E6784
	ldr r0, _081E67A4 @ =0x00001617
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	strb r0, [r2]
_081E6784:
	adds r0, r4, #0
	bl FUN_081e2ee8
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E67A8 @ =0x00001610
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E67AC
	movs r0, #1
	b _081E67AE
	.align 2, 0
_081E67A0: .4byte 0x00001614
_081E67A4: .4byte 0x00001617
_081E67A8: .4byte 0x00001610
_081E67AC:
	movs r0, #0
_081E67AE:
	cmp r0, #0
	beq _081E67BC
	adds r0, r4, #0
	movs r1, #6
	bl FUN_081e4c64
	b _081E680A
_081E67BC:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E67CC
	movs r0, #1
	b _081E67CE
_081E67CC:
	movs r0, #0
_081E67CE:
	cmp r0, #0
	beq _081E680A
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #6
	bne _081E680A
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E680A
	ldr r1, _081E6800 @ =0x00001624
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081E6804
	cmp r0, #1
	bne _081E680A
	adds r0, r4, #0
	bl FUN_081e4de0
	b _081E680A
	.align 2, 0
_081E6800: .4byte 0x00001624
_081E6804:
	adds r0, r4, #0
	bl FUN_081e4edc
_081E680A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e6810
FUN_081e6810: @ 0x081E6810
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081E6890 @ =0x00001614
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E6838
	ldr r1, _081E6894 @ =0x00001608
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r3, _081E6898 @ =0x00001514
	adds r2, r4, r3
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	strb r0, [r5]
_081E6838:
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa
	bne _081E68AC
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r4, r3
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E6898 @ =0x00001514
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r3, #0xde
	lsls r3, r3, #3
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E689C @ =0x000014B4
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081E68A0 @ =0x00001624
	adds r0, r4, r1
	strb r2, [r0]
	ldr r0, _081E68A4 @ =FUN_081e653c
	movs r1, #0x11
	str r0, [r4, #0x18]
	ldr r3, _081E6890 @ =0x00001614
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _081E68A8 @ =0x00001616
	adds r0, r4, r2
	strb r1, [r0]
	b _081E6A06
	.align 2, 0
_081E6890: .4byte 0x00001614
_081E6894: .4byte 0x00001608
_081E6898: .4byte 0x00001514
_081E689C: .4byte 0x000014B4
_081E68A0: .4byte 0x00001624
_081E68A4: .4byte FUN_081e653c
_081E68A8: .4byte 0x00001616
_081E68AC:
	adds r0, r4, #0
	bl FUN_081e2ee8
	ldr r3, _081E68E0 @ =0x00000808
	adds r0, r4, r3
	ldr r2, _081E68E4 @ =0x00000AC8
	adds r1, r4, r2
	bl MainSprite_AdvanceAnim
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E68CA
	b _081E6A06
_081E68CA:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r3, _081E68E8 @ =0x00001610
	adds r1, r4, r3
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E68EC
	movs r0, #1
	b _081E68EE
	.align 2, 0
_081E68E0: .4byte 0x00000808
_081E68E4: .4byte 0x00000AC8
_081E68E8: .4byte 0x00001610
_081E68EC:
	movs r0, #0
_081E68EE:
	cmp r0, #0
	bne _081E68F4
	b _081E6A06
_081E68F4:
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #4
	beq _081E6904
	b _081E6A06
_081E6904:
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E6914
	movs r0, #1
	b _081E6916
_081E6914:
	movs r0, #0
_081E6916:
	cmp r0, #0
	beq _081E69A8
	ldr r0, _081E695C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _081E6960 @ =0x000015E4
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r1, r0
	blt _081E696C
	ldr r0, _081E6964 @ =0x00001617
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0x10
	beq _081E6A06
	bl FUN_08049e5c
	ldr r1, _081E6968 @ =0x000015F0
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0x10
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #0x10
	b _081E6992
	.align 2, 0
_081E695C: .4byte 0x030046A0
_081E6960: .4byte 0x000015E4
_081E6964: .4byte 0x00001617
_081E6968: .4byte 0x000015F0
_081E696C:
	ldr r2, _081E699C @ =0x00001617
	adds r5, r4, r2
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0x11
	beq _081E6A06
	bl FUN_08049e5c
	ldr r3, _081E69A0 @ =0x000015F0
	adds r0, r4, r3
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0x11
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #0x11
_081E6992:
	strb r0, [r5]
	ldr r0, _081E69A4 @ =FUN_081e6b5c
	movs r2, #7
	b _081E69F6
	.align 2, 0
_081E699C: .4byte 0x00001617
_081E69A0: .4byte 0x000015F0
_081E69A4: .4byte FUN_081e6b5c
_081E69A8:
	bl FUN_08049e5c
	ldr r2, _081E6A0C @ =0x0000161A
	adds r5, r4, r2
	ldrb r0, [r5]
	cmp r0, #0x11
	beq _081E69F2
	adds r0, r4, #0
	bl FUN_081e4544
	ldrb r0, [r5]
	adds r0, #0x19
	ldr r3, _081E6A10 @ =0x00001617
	adds r1, r4, r3
	strb r0, [r1]
	ldr r1, _081E6A14 @ =0x00001608
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a1f0
	ldrb r1, [r5]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r4, r0
	ldr r2, _081E6A18 @ =0x00000BC4
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081E69F2
	ldr r3, _081E6A1C @ =0x00001514
	adds r0, r4, r3
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_081E69F2:
	ldr r0, _081E6A20 @ =FUN_081e7414
	movs r2, #4
_081E69F6:
	str r0, [r4, #0x18]
	ldr r0, _081E6A24 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E6A28 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
_081E6A06:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E6A0C: .4byte 0x0000161A
_081E6A10: .4byte 0x00001617
_081E6A14: .4byte 0x00001608
_081E6A18: .4byte 0x00000BC4
_081E6A1C: .4byte 0x00001514
_081E6A20: .4byte FUN_081e7414
_081E6A24: .4byte 0x00001614
_081E6A28: .4byte 0x00001616

	thumb_func_start FUN_081e6a2c
FUN_081e6a2c: @ 0x081E6A2C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081E6AA0 @ =0x00001614
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E6A54
	ldr r1, _081E6AA4 @ =0x00001608
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r3, _081E6AA8 @ =0x00001514
	adds r2, r4, r3
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	strb r0, [r5]
_081E6A54:
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa
	bne _081E6ABC
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r4, r3
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E6AA8 @ =0x00001514
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081E6AAC @ =0x00001624
	adds r0, r4, r1
	strb r2, [r0]
	ldr r3, _081E6AB0 @ =0x000014B4
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E6AB4 @ =FUN_081e653c
	movs r1, #0x11
	str r0, [r4, #0x18]
	ldr r3, _081E6AA0 @ =0x00001614
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _081E6AB8 @ =0x00001616
	adds r0, r4, r2
	strb r1, [r0]
	b _081E6B42
	.align 2, 0
_081E6AA0: .4byte 0x00001614
_081E6AA4: .4byte 0x00001608
_081E6AA8: .4byte 0x00001514
_081E6AAC: .4byte 0x00001624
_081E6AB0: .4byte 0x000014B4
_081E6AB4: .4byte FUN_081e653c
_081E6AB8: .4byte 0x00001616
_081E6ABC:
	adds r0, r4, #0
	bl FUN_081e2ee8
	ldr r3, _081E6AEC @ =0x00000808
	adds r0, r4, r3
	ldr r2, _081E6AF0 @ =0x00000AC8
	adds r1, r4, r2
	bl MainSprite_AdvanceAnim
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E6B42
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r3, _081E6AF4 @ =0x00001610
	adds r0, r4, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E6AF8
	movs r0, #1
	b _081E6AFA
	.align 2, 0
_081E6AEC: .4byte 0x00000808
_081E6AF0: .4byte 0x00000AC8
_081E6AF4: .4byte 0x00001610
_081E6AF8:
	movs r0, #0
_081E6AFA:
	cmp r0, #0
	beq _081E6B42
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #4
	bne _081E6B42
	bl FUN_08049e5c
	adds r0, r4, #0
	bl FUN_081e4544
	ldr r3, _081E6B48 @ =0x0000161A
	adds r0, r4, r3
	ldrb r0, [r0]
	adds r0, #0x19
	ldr r2, _081E6B4C @ =0x00001617
	adds r1, r4, r2
	strb r0, [r1]
	subs r3, #0x12
	adds r0, r4, r3
	ldr r0, [r0]
	bl FUN_0804a1f0
	ldr r0, _081E6B50 @ =FUN_081e6f28
	movs r2, #3
	str r0, [r4, #0x18]
	ldr r0, _081E6B54 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E6B58 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
_081E6B42:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E6B48: .4byte 0x0000161A
_081E6B4C: .4byte 0x00001617
_081E6B50: .4byte FUN_081e6f28
_081E6B54: .4byte 0x00001614
_081E6B58: .4byte 0x00001616

	thumb_func_start FUN_081e6b5c
FUN_081e6b5c: @ 0x081E6B5C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r1, _081E6B80 @ =0x00001614
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081E6C3A
	movs r2, #0x80
	lsls r2, r2, #0xa
	ldr r3, _081E6B84 @ =0x00001610
	adds r1, r6, r3
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081E6B88
	movs r0, #1
	b _081E6B8A
	.align 2, 0
_081E6B80: .4byte 0x00001614
_081E6B84: .4byte 0x00001610
_081E6B88:
	movs r0, #0
_081E6B8A:
	adds r3, r0, #0
	cmp r3, #0
	bne _081E6C32
	movs r4, #0xea
	lsls r4, r4, #3
	adds r2, r6, r4
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r5, #0xed
	lsls r5, r5, #3
	adds r1, r6, r5
	movs r5, #0
	movs r0, #0x18
	strh r0, [r1]
	ldr r1, _081E6C90 @ =0x0000076A
	adds r0, r6, r1
	strh r3, [r0]
	ldr r2, _081E6C94 @ =0x000015E6
	adds r0, r6, r2
	strb r5, [r0]
	ldr r3, _081E6C98 @ =0x000015E2
	adds r4, r6, r3
	ldrh r1, [r4]
	adds r0, r6, #0
	bl FUN_081e37a0
	ldrh r1, [r4]
	ldr r2, _081E6C9C @ =0x000015E4
	adds r0, r6, r2
	strh r1, [r0]
	ldr r3, _081E6CA0 @ =0x00001619
	adds r0, r6, r3
	strb r5, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
	ldrh r1, [r4]
	movs r2, #0
	ldr r0, _081E6CA4 @ =0x000003E7
	cmp r1, r0
	ble _081E6BF0
	ldr r3, _081E6CA8 @ =0xFFFFFC18
_081E6BE8:
	adds r2, #1
	adds r1, r1, r3
	cmp r1, r0
	bgt _081E6BE8
_081E6BF0:
	ldr r4, _081E6CAC @ =0x000015EF
	adds r0, r6, r4
	strb r2, [r0]
	movs r2, #0
	cmp r1, #0x63
	ble _081E6C04
_081E6BFC:
	adds r2, #1
	subs r1, #0x64
	cmp r1, #0x63
	bgt _081E6BFC
_081E6C04:
	ldr r5, _081E6CB0 @ =0x000015EE
	adds r0, r6, r5
	strb r2, [r0]
	movs r2, #0
	cmp r1, #9
	ble _081E6C18
_081E6C10:
	adds r2, #1
	subs r1, #0xa
	cmp r1, #9
	bgt _081E6C10
_081E6C18:
	ldr r3, _081E6CB4 @ =0x000015ED
	adds r0, r6, r3
	strb r2, [r0]
	movs r2, #0
	cmp r1, #0
	ble _081E6C2C
_081E6C24:
	adds r2, #1
	subs r1, #1
	cmp r1, #0
	bgt _081E6C24
_081E6C2C:
	ldr r4, _081E6CB8 @ =0x000015EC
	adds r0, r6, r4
	strb r2, [r0]
_081E6C32:
	ldr r5, _081E6CBC @ =0x00001614
	adds r1, r6, r5
	movs r0, #0
	strb r0, [r1]
_081E6C3A:
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa
	bne _081E6CD4
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r6, r3
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r4, _081E6CC0 @ =0x00001514
	adds r1, r6, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0xde
	lsls r5, r5, #3
	adds r1, r6, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E6CC4 @ =0x000014B4
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081E6CC8 @ =0x00001624
	adds r0, r6, r1
	strb r2, [r0]
	ldr r0, _081E6CCC @ =FUN_081e653c
	movs r1, #0x11
	str r0, [r6, #0x18]
	ldr r3, _081E6CBC @ =0x00001614
	adds r0, r6, r3
	strb r2, [r0]
	ldr r4, _081E6CD0 @ =0x00001616
	adds r0, r6, r4
	strb r1, [r0]
	b _081E6F20
	.align 2, 0
_081E6C90: .4byte 0x0000076A
_081E6C94: .4byte 0x000015E6
_081E6C98: .4byte 0x000015E2
_081E6C9C: .4byte 0x000015E4
_081E6CA0: .4byte 0x00001619
_081E6CA4: .4byte 0x000003E7
_081E6CA8: .4byte 0xFFFFFC18
_081E6CAC: .4byte 0x000015EF
_081E6CB0: .4byte 0x000015EE
_081E6CB4: .4byte 0x000015ED
_081E6CB8: .4byte 0x000015EC
_081E6CBC: .4byte 0x00001614
_081E6CC0: .4byte 0x00001514
_081E6CC4: .4byte 0x000014B4
_081E6CC8: .4byte 0x00001624
_081E6CCC: .4byte FUN_081e653c
_081E6CD0: .4byte 0x00001616
_081E6CD4:
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r5, _081E6CEC @ =0x00001610
	adds r1, r6, r5
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081E6CF0
	movs r0, #1
	b _081E6CF2
	.align 2, 0
_081E6CEC: .4byte 0x00001610
_081E6CF0:
	movs r0, #0
_081E6CF2:
	adds r5, r0, #0
	cmp r5, #0
	beq _081E6D28
	ldr r0, _081E6D18 @ =FUN_081e6810
	movs r2, #0x15
	str r0, [r6, #0x18]
	ldr r0, _081E6D1C @ =0x00001614
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E6D20 @ =0x00001616
	adds r0, r6, r1
	strb r2, [r0]
	ldr r1, _081E6D24 @ =0xFFFFF7FF
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	b _081E6F20
	.align 2, 0
_081E6D18: .4byte FUN_081e6810
_081E6D1C: .4byte 0x00001614
_081E6D20: .4byte 0x00001616
_081E6D24: .4byte 0xFFFFF7FF
_081E6D28:
	adds r0, r6, #0
	bl FUN_081e4ab8
	adds r1, r0, #0
	ldr r3, _081E6D58 @ =0x000015E6
	adds r2, r6, r3
	ldrb r4, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081E6D68
	ldr r1, _081E6D5C @ =0x000015EC
	adds r0, r6, r1
	adds r1, r0, r4
	ldr r2, _081E6D60 @ =0x000015E8
	adds r0, r6, r2
	adds r0, r0, r4
	ldrb r2, [r1]
	ldrb r0, [r0]
	cmp r2, r0
	blo _081E6D64
	strb r5, [r1]
	b _081E6D94
	.align 2, 0
_081E6D58: .4byte 0x000015E6
_081E6D5C: .4byte 0x000015EC
_081E6D60: .4byte 0x000015E8
_081E6D64:
	adds r0, r2, #1
	b _081E6D92
_081E6D68:
	movs r3, #2
	ands r3, r1
	cmp r3, #0
	beq _081E6DB4
	ldr r5, _081E6D88 @ =0x000015EC
	adds r0, r6, r5
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, #0
	bne _081E6D90
	ldr r2, _081E6D8C @ =0x000015E8
	adds r0, r6, r2
	adds r0, r0, r4
	ldrb r0, [r0]
	b _081E6D92
	.align 2, 0
_081E6D88: .4byte 0x000015EC
_081E6D8C: .4byte 0x000015E8
_081E6D90:
	subs r0, #1
_081E6D92:
	strb r0, [r1]
_081E6D94:
	adds r0, r6, #0
	bl FUN_081e3758
	ldr r3, _081E6DB0 @ =0x000015E4
	adds r1, r6, r3
	strh r0, [r1]
	ldrh r1, [r1]
	adds r0, r6, #0
	bl FUN_081e37a0
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _081E6DE8
	.align 2, 0
_081E6DB0: .4byte 0x000015E4
_081E6DB4:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081E6DD4
	ldr r5, _081E6DCC @ =0x000015E7
	adds r0, r6, r5
	ldrb r0, [r0]
	cmp r4, r0
	blo _081E6DD0
	strb r3, [r2]
	b _081E6DE8
	.align 2, 0
_081E6DCC: .4byte 0x000015E7
_081E6DD0:
	adds r0, r4, #1
	b _081E6DE6
_081E6DD4:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081E6DE8
	cmp r4, #0
	bne _081E6DE4
	movs r0, #3
	b _081E6DE6
_081E6DE4:
	subs r0, r4, #1
_081E6DE6:
	strb r0, [r2]
_081E6DE8:
	ldr r1, _081E6E88 @ =0x000015E6
	adds r0, r6, r1
	ldrb r1, [r0]
	cmp r1, r4
	beq _081E6E1A
	lsls r1, r1, #3
	movs r0, #0x18
	subs r0, r0, r1
	movs r2, #0xed
	lsls r2, r2, #3
	adds r1, r6, r2
	movs r2, #0
	strh r0, [r1]
	ldr r3, _081E6E8C @ =0x0000076A
	adds r0, r6, r3
	strh r2, [r0]
	ldr r4, _081E6E90 @ =0x000015E4
	adds r0, r6, r4
	ldrh r1, [r0]
	adds r0, r6, #0
	bl FUN_081e37a0
	movs r0, #0xdc
	bl PlaySound_082406e0
_081E6E1A:
	ldr r0, _081E6E94 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r4, #1
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _081E6E32
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081E6EB6
_081E6E32:
	ldr r0, _081E6E98 @ =0x030046A0
	ldr r0, [r0]
	movs r5, #0x91
	lsls r5, r5, #4
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r5, _081E6E90 @ =0x000015E4
	adds r2, r6, r5
	ldrh r1, [r2]
	cmp r0, r1
	blt _081E6EAC
	ldr r0, _081E6E9C @ =FUN_081e7414
	movs r1, #4
	str r0, [r6, #0x18]
	adds r5, #0x30
	adds r0, r6, r5
	strb r4, [r0]
	ldr r4, _081E6EA0 @ =0x00001616
	adds r0, r6, r4
	strb r1, [r0]
	movs r5, #0xea
	lsls r5, r5, #3
	adds r1, r6, r5
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	ldrh r1, [r2]
	ldr r2, _081E6EA4 @ =0x000015E2
	adds r0, r6, r2
	strh r1, [r0]
	ldrh r1, [r0]
	adds r0, r6, #0
	bl FUN_081e37a0
	ldr r1, _081E6EA8 @ =0xFFFDFFFF
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _081E6F20
	.align 2, 0
_081E6E88: .4byte 0x000015E6
_081E6E8C: .4byte 0x0000076A
_081E6E90: .4byte 0x000015E4
_081E6E94: .4byte 0x030044E0
_081E6E98: .4byte 0x030046A0
_081E6E9C: .4byte FUN_081e7414
_081E6EA0: .4byte 0x00001616
_081E6EA4: .4byte 0x000015E2
_081E6EA8: .4byte 0xFFFDFFFF
_081E6EAC:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _081E6F14
_081E6EB6:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081E6F14
	ldr r0, _081E6F00 @ =FUN_081e7414
	movs r1, #4
	str r0, [r6, #0x18]
	ldr r5, _081E6F04 @ =0x00001614
	adds r0, r6, r5
	strb r4, [r0]
	ldr r2, _081E6F08 @ =0x00001616
	adds r0, r6, r2
	strb r1, [r0]
	movs r4, #0xea
	lsls r4, r4, #3
	adds r1, r6, r4
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	subs r5, #0x32
	adds r4, r6, r5
	ldrh r1, [r4]
	adds r0, r6, #0
	bl FUN_081e37a0
	ldrh r1, [r4]
	ldr r2, _081E6F0C @ =0x000015E4
	adds r0, r6, r2
	strh r1, [r0]
	ldr r1, _081E6F10 @ =0xFFFDFFFF
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081E6F20
	.align 2, 0
_081E6F00: .4byte FUN_081e7414
_081E6F04: .4byte 0x00001614
_081E6F08: .4byte 0x00001616
_081E6F0C: .4byte 0x000015E4
_081E6F10: .4byte 0xFFFDFFFF
_081E6F14:
	adds r0, r6, #0
	bl FUN_081e2ee8
	adds r0, r6, #0
	bl FUN_081e4a60
_081E6F20:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e6f28
FUN_081e6f28: @ 0x081E6F28
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r1, _081E6F54 @ =0x00001614
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E6F3E
	b _081E7090
_081E6F3E:
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r3, _081E6F58 @ =0x00001610
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081E6F5C
	movs r0, #1
	b _081E6F5E
	.align 2, 0
_081E6F54: .4byte 0x00001614
_081E6F58: .4byte 0x00001610
_081E6F5C:
	movs r0, #0
_081E6F5E:
	adds r4, r0, #0
	cmp r4, #0
	bne _081E7056
	adds r0, r5, #0
	bl FUN_081e2b08
	movs r0, #0x14
	str r0, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0x1e
	bl FUN_0822bdb8
	ldr r1, [r5, #0x1c]
	movs r0, #3
	movs r2, #3
	bl FUN_0822c398
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #0x81
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r0, r5, #0
	bl FUN_081e3fac
	adds r0, r5, #0
	bl FUN_081e4354
	ldr r1, _081E70CC @ =0x0000161A
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _081E70D0 @ =0x00001608
	adds r4, r5, r2
	ldr r0, [r4]
	ldr r3, _081E70D4 @ =0x00001590
	adds r1, r5, r3
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	bl FUN_0804a1f0
	adds r0, r5, #0
	bl FUN_081e4544
	ldr r0, _081E70D8 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r2, r0, r1
	movs r3, #0
	ldrsh r0, [r2, r3]
	ldr r1, _081E70DC @ =0x0000270F
	cmp r0, r1
	ble _081E6FEC
	adds r0, r1, #0
_081E6FEC:
	movs r1, #0xfa
	lsls r1, r1, #2
	movs r6, #0
	str r6, [sp]
	movs r2, #0x16
	movs r3, #1
	bl FUN_081e4604
	ldr r0, _081E70D8 @ =0x030046A0
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x40
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r2, #0x63
	cmp r0, #0x63
	bgt _081E7010
	adds r2, r0, #0
_081E7010:
	str r6, [sp]
	adds r0, r2, #0
	movs r1, #0xa
	movs r2, #0x15
	movs r3, #0
	bl FUN_081e4604
	movs r0, #0xb0
	lsls r0, r0, #5
	adds r4, r5, r0
	ldr r0, [r4]
	ldr r2, _081E70E0 @ =0x000015F0
	adds r1, r5, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #0
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldr r3, _081E70E4 @ =0x00001599
	adds r1, r5, r3
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _081E70E8 @ =0x00001619
	adds r0, r5, r1
	strb r6, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
_081E7056:
	ldr r2, _081E70E4 @ =0x00001599
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _081E7074
	movs r3, #0xf6
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_081E7074:
	ldr r1, _081E70EC @ =0x00001617
	adds r0, r5, r1
	movs r4, #0
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_081e2ee8
	ldr r2, _081E70F0 @ =0x0000162A
	adds r0, r5, r2
	movs r1, #0
	strh r4, [r0]
	ldr r3, _081E70F4 @ =0x00001614
	adds r0, r5, r3
	strb r1, [r0]
_081E7090:
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa
	bne _081E7108
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r5, r3
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E70F8 @ =0x00001514
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081E70FC @ =0x00001624
	adds r0, r5, r1
	strb r2, [r0]
	ldr r3, _081E7100 @ =0x000014B4
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E7104 @ =FUN_081e653c
	movs r1, #0x11
	b _081E7378
	.align 2, 0
_081E70CC: .4byte 0x0000161A
_081E70D0: .4byte 0x00001608
_081E70D4: .4byte 0x00001590
_081E70D8: .4byte 0x030046A0
_081E70DC: .4byte 0x0000270F
_081E70E0: .4byte 0x000015F0
_081E70E4: .4byte 0x00001599
_081E70E8: .4byte 0x00001619
_081E70EC: .4byte 0x00001617
_081E70F0: .4byte 0x0000162A
_081E70F4: .4byte 0x00001614
_081E70F8: .4byte 0x00001514
_081E70FC: .4byte 0x00001624
_081E7100: .4byte 0x000014B4
_081E7104: .4byte FUN_081e653c
_081E7108:
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r3, _081E7120 @ =0x00001610
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081E7124
	movs r0, #1
	b _081E7126
	.align 2, 0
_081E7120: .4byte 0x00001610
_081E7124:
	movs r0, #0
_081E7126:
	cmp r0, #0
	beq _081E7158
	ldr r0, _081E7148 @ =FUN_081e6a2c
	movs r2, #8
	str r0, [r5, #0x18]
	ldr r0, _081E714C @ =0x00001614
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7150 @ =0x00001616
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, _081E7154 @ =0xFFFFCFFF
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	b _081E7400
	.align 2, 0
_081E7148: .4byte FUN_081e6a2c
_081E714C: .4byte 0x00001614
_081E7150: .4byte 0x00001616
_081E7154: .4byte 0xFFFFCFFF
_081E7158:
	adds r0, r5, #0
	bl FUN_081e2ee8
	ldr r2, _081E717C @ =0x00000808
	adds r0, r5, r2
	ldr r3, _081E7180 @ =0x00000AC8
	adds r1, r5, r3
	bl MainSprite_AdvanceAnim
	ldr r0, _081E7184 @ =0x0000162A
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0x1e
	bls _081E7188
	adds r0, #1
	strh r0, [r1]
	b _081E7400
	.align 2, 0
_081E717C: .4byte 0x00000808
_081E7180: .4byte 0x00000AC8
_081E7184: .4byte 0x0000162A
_081E7188:
	ldr r1, _081E71B0 @ =0x0000161A
	adds r0, r5, r1
	ldrb r4, [r0]
	adds r0, r5, #0
	bl FUN_081e4ab8
	adds r1, r0, #0
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081E71B8
	asrs r0, r4, #2
	cmp r0, #0
	bne _081E71B4
	movs r0, #3
	ands r0, r4
	adds r4, r0, #0
	adds r4, #0xc
	b _081E7214
	.align 2, 0
_081E71B0: .4byte 0x0000161A
_081E71B4:
	subs r4, #4
	b _081E7214
_081E71B8:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081E71D8
	asrs r0, r4, #2
	cmp r0, #3
	bne _081E71CA
	ands r4, r0
	b _081E71CC
_081E71CA:
	adds r4, #4
_081E71CC:
	ldr r3, _081E71D4 @ =0x00001619
	adds r1, r5, r3
	b _081E7218
	.align 2, 0
_081E71D4: .4byte 0x00001619
_081E71D8:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081E71FC
	movs r0, #3
	ands r0, r4
	cmp r0, #0
	bne _081E71F0
	movs r0, #0xfc
	ands r0, r4
	adds r4, r0, #3
	b _081E71F2
_081E71F0:
	subs r4, #1
_081E71F2:
	ldr r0, _081E71F8 @ =0x00001619
	adds r1, r5, r0
	b _081E7218
	.align 2, 0
_081E71F8: .4byte 0x00001619
_081E71FC:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081E721C
	movs r0, #3
	ands r0, r4
	cmp r0, #3
	bne _081E7212
	movs r0, #0xfc
	ands r4, r0
	b _081E7214
_081E7212:
	adds r4, #1
_081E7214:
	ldr r2, _081E7254 @ =0x00001619
	adds r1, r5, r2
_081E7218:
	movs r0, #0
	strb r0, [r1]
_081E721C:
	ldr r3, _081E7258 @ =0x0000161A
	adds r7, r5, r3
	ldrb r0, [r7]
	cmp r4, r0
	beq _081E7264
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	ldr r2, _081E725C @ =0x00000828
	adds r1, r5, r2
	strh r0, [r1]
	asrs r1, r4, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	ldr r3, _081E7260 @ =0x0000082A
	adds r1, r5, r3
	strh r0, [r1]
	strb r4, [r7]
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _081E7400
	.align 2, 0
_081E7254: .4byte 0x00001619
_081E7258: .4byte 0x0000161A
_081E725C: .4byte 0x00000828
_081E7260: .4byte 0x0000082A
_081E7264:
	ldr r0, _081E7310 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	mov r8, r0
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _081E7334
	adds r0, r5, #0
	bl FUN_081e3e78
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E7284
	b _081E73BA
_081E7284:
	ldr r1, _081E7314 @ =0x00001599
	adds r2, r5, r1
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _081E72BC
	adds r1, r0, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r5, r0
	ldr r3, _081E7318 @ =0x00000E86
	adds r0, r0, r3
	ldr r1, _081E731C @ =0x000002DF
	strh r1, [r0]
	movs r1, #0
	ldrsb r1, [r2, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r3, #0xe
	adds r1, r5, r3
	adds r1, r1, r0
	ldr r0, _081E7320 @ =0x03003584
	ldr r0, [r0]
	ldr r3, _081E7324 @ =0x00005BE0
	adds r0, r0, r3
	str r0, [r1]
_081E72BC:
	ldrb r0, [r7]
	strb r0, [r2]
	movs r0, #0xf6
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	ldr r3, _081E7328 @ =0x00000A68
	adds r1, r5, r3
	strh r0, [r1]
	asrs r1, r4, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	adds r3, #2
	adds r1, r5, r3
	strh r0, [r1]
	movs r0, #0xa5
	lsls r0, r0, #4
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r0, _081E732C @ =FUN_081e52ac
	movs r1, #6
	str r0, [r5, #0x18]
	ldr r2, _081E7330 @ =0x00001614
	adds r0, r5, r2
	mov r3, r8
	strb r3, [r0]
	adds r2, #2
	b _081E7382
	.align 2, 0
_081E7310: .4byte 0x030044E0
_081E7314: .4byte 0x00001599
_081E7318: .4byte 0x00000E86
_081E731C: .4byte 0x000002DF
_081E7320: .4byte 0x03003584
_081E7324: .4byte 0x00005BE0
_081E7328: .4byte 0x00000A68
_081E732C: .4byte FUN_081e52ac
_081E7330: .4byte 0x00001614
_081E7334:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081E73A4
	adds r0, r5, #0
	movs r1, #0xa
	bl FUN_081e4c64
	ldr r3, _081E7388 @ =0x00001618
	adds r1, r5, r3
	movs r0, #0xa
	strb r0, [r1]
	movs r0, #0x81
	lsls r0, r0, #4
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r2, _081E738C @ =0x00001514
	adds r1, r5, r2
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r3, _081E7390 @ =0x000014B4
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r1, _081E7394 @ =0x00001624
	adds r0, r5, r1
	mov r2, r8
	strb r2, [r0]
	ldr r0, _081E7398 @ =FUN_081e5d14
	movs r1, #0x10
_081E7378:
	str r0, [r5, #0x18]
	ldr r3, _081E739C @ =0x00001614
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081E73A0 @ =0x00001616
_081E7382:
	adds r0, r5, r2
	strb r1, [r0]
	b _081E7400
	.align 2, 0
_081E7388: .4byte 0x00001618
_081E738C: .4byte 0x00001514
_081E7390: .4byte 0x000014B4
_081E7394: .4byte 0x00001624
_081E7398: .4byte FUN_081e5d14
_081E739C: .4byte 0x00001614
_081E73A0: .4byte 0x00001616
_081E73A4:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081E7400
	ldr r3, _081E73C4 @ =0x00001599
	adds r0, r5, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _081E73C8
_081E73BA:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _081E7400
	.align 2, 0
_081E73C4: .4byte 0x00001599
_081E73C8:
	movs r0, #0xf6
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	str r6, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #0x19
	movs r1, #0x10
	movs r2, #5
	movs r3, #1
	bl FUN_081e4644
	ldr r0, _081E740C @ =FUN_081e53e8
	movs r1, #9
	str r0, [r5, #0x18]
	ldr r2, _081E7410 @ =0x00001614
	adds r0, r5, r2
	mov r3, r8
	strb r3, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
_081E7400:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E740C: .4byte FUN_081e53e8
_081E7410: .4byte 0x00001614

	thumb_func_start FUN_081e7414
FUN_081e7414: @ 0x081E7414
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	ldr r1, _081E7444 @ =0x00001614
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E742E
	b _081E75C2
_081E742E:
	movs r2, #0x80
	lsls r2, r2, #2
	ldr r3, _081E7448 @ =0x00001610
	adds r1, r7, r3
	ldr r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081E744C
	movs r0, #1
	b _081E744E
	.align 2, 0
_081E7444: .4byte 0x00001614
_081E7448: .4byte 0x00001610
_081E744C:
	movs r0, #0
_081E744E:
	adds r6, r0, #0
	cmp r6, #0
	beq _081E7456
	b _081E7596
_081E7456:
	adds r0, r7, #0
	bl FUN_081e2b08
	movs r0, #0x14
	str r0, [sp]
	str r6, [sp, #4]
	str r6, [sp, #8]
	str r6, [sp, #0xc]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0x1e
	bl FUN_0822bdb8
	ldr r1, [r7, #0x1c]
	movs r0, #3
	movs r2, #2
	bl FUN_0822c398
	str r6, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #0x81
	lsls r0, r0, #4
	adds r5, r7, r0
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	mov r8, r1
	ands r0, r1
	str r0, [r5]
	adds r0, r7, #0
	bl FUN_081e3fac
	adds r0, r7, #0
	bl FUN_081e4354
	ldr r4, _081E7618 @ =0x030046A0
	ldr r0, [r4]
	movs r2, #0x91
	lsls r2, r2, #4
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xfa
	lsls r1, r1, #2
	str r6, [sp]
	movs r2, #0x16
	movs r3, #1
	bl FUN_081e4604
	ldr r0, [r4]
	adds r0, #0x40
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r6, [sp]
	movs r1, #0xa
	movs r2, #0x15
	movs r3, #0
	bl FUN_081e4604
	movs r2, #0xb0
	lsls r2, r2, #5
	adds r4, r7, r2
	ldr r0, [r4]
	ldr r3, _081E761C @ =0x000015F0
	adds r3, r3, r7
	mov sl, r3
	ldr r1, [r3]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #0
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldr r1, _081E7620 @ =0x000015E2
	adds r0, r7, r1
	ldrh r1, [r0]
	adds r0, r7, #0
	bl FUN_081e37a0
	adds r0, r7, #0
	bl FUN_081e36e8
	adds r0, r7, #0
	bl FUN_081e3714
	adds r0, r7, #0
	bl FUN_081e49a8
	ldr r2, _081E7624 @ =0x00001599
	adds r1, r7, r2
	movs r0, #0xff
	strb r0, [r1]
	ldr r3, _081E7628 @ =0x00001619
	adds r0, r7, r3
	strb r6, [r0]
	ldr r1, _081E762C @ =0x0000161B
	adds r0, r7, r1
	strb r6, [r0]
	adds r2, #0x87
	adds r1, r7, r2
	ldr r0, _081E7630 @ =0x0000FFFF
	strh r0, [r1]
	adds r3, #1
	adds r1, r7, r3
	movs r0, #0x11
	strb r0, [r1]
	ldr r1, _081E7634 @ =0x00001608
	adds r0, r7, r1
	ldr r0, [r0]
	subs r2, #0x90
	adds r1, r7, r2
	ldr r1, [r1]
	bl FUN_0804a240
	bl FUN_08049e5c
	mov r3, sl
	ldr r0, [r3]
	bl VM_ParseStringRef
	adds r0, #0xf
	bl Textbox_LookupString
	bl FUN_08049e30
	ldr r0, _081E7638 @ =0x00001617
	adds r1, r7, r0
	movs r0, #0xf
	strb r0, [r1]
	ldr r2, _081E763C @ =0x00001514
	adds r1, r7, r2
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, [r5]
	orrs r0, r2
	str r0, [r5]
	movs r3, #0xde
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, [r1]
	mov r2, r8
	ands r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #2
	mov r3, sb
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081E7596:
	movs r0, #0xf6
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r2, _081E7640 @ =0x0000162A
	adds r1, r7, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r3, _081E7644 @ =0x00001614
	adds r0, r7, r3
	strb r2, [r0]
	ldr r1, _081E7638 @ =0x00001617
	adds r0, r7, r1
	strb r2, [r0]
	adds r0, r7, #0
	bl FUN_081e2ee8
_081E75C2:
	movs r2, #0xb1
	lsls r2, r2, #5
	adds r0, r7, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0xa
	bne _081E7654
	movs r0, #0x81
	lsls r0, r0, #4
	adds r1, r7, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r3, _081E763C @ =0x00001514
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xde
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	subs r3, #0x60
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081E7648 @ =0x00001624
	adds r0, r7, r1
	strb r2, [r0]
	ldr r0, _081E764C @ =FUN_081e653c
	movs r1, #0x11
	str r0, [r7, #0x18]
	ldr r3, _081E7644 @ =0x00001614
	adds r0, r7, r3
	strb r2, [r0]
	ldr r2, _081E7650 @ =0x00001616
	adds r0, r7, r2
	strb r1, [r0]
	b _081E78B2
	.align 2, 0
_081E7618: .4byte 0x030046A0
_081E761C: .4byte 0x000015F0
_081E7620: .4byte 0x000015E2
_081E7624: .4byte 0x00001599
_081E7628: .4byte 0x00001619
_081E762C: .4byte 0x0000161B
_081E7630: .4byte 0x0000FFFF
_081E7634: .4byte 0x00001608
_081E7638: .4byte 0x00001617
_081E763C: .4byte 0x00001514
_081E7640: .4byte 0x0000162A
_081E7644: .4byte 0x00001614
_081E7648: .4byte 0x00001624
_081E764C: .4byte FUN_081e653c
_081E7650: .4byte 0x00001616
_081E7654:
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r3, _081E766C @ =0x00001610
	adds r1, r7, r3
	ldr r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081E7670
	movs r0, #1
	b _081E7672
	.align 2, 0
_081E766C: .4byte 0x00001610
_081E7670:
	movs r0, #0
_081E7672:
	cmp r0, #0
	beq _081E76A8
	ldr r0, _081E7698 @ =FUN_081e6810
	movs r2, #0x15
	str r0, [r7, #0x18]
	ldr r0, _081E769C @ =0x00001614
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E76A0 @ =0x00001616
	adds r0, r7, r1
	strb r2, [r0]
	ldr r1, _081E76A4 @ =0xFFFFF7FF
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _081E78B2
	.align 2, 0
_081E7698: .4byte FUN_081e6810
_081E769C: .4byte 0x00001614
_081E76A0: .4byte 0x00001616
_081E76A4: .4byte 0xFFFFF7FF
_081E76A8:
	adds r0, r7, #0
	bl FUN_081e2ee8
	ldr r3, _081E76D0 @ =0x00000808
	adds r0, r7, r3
	ldr r2, _081E76D4 @ =0x00000AC8
	adds r1, r7, r2
	bl MainSprite_AdvanceAnim
	adds r0, r7, #0
	bl FUN_081e4a60
	ldr r3, _081E76D8 @ =0x0000162A
	adds r1, r7, r3
	ldrh r0, [r1]
	cmp r0, #0x1e
	bls _081E76DC
	adds r0, #1
	strh r0, [r1]
	b _081E78B2
	.align 2, 0
_081E76D0: .4byte 0x00000808
_081E76D4: .4byte 0x00000AC8
_081E76D8: .4byte 0x0000162A
_081E76DC:
	adds r0, r7, #0
	bl FUN_081e4ab8
	adds r2, r0, #0
	adds r0, r7, #0
	add r1, sp, #0x10
	bl FUN_081e468c
	adds r1, r0, #0
	ldr r0, _081E7738 @ =0x0000161A
	adds r4, r7, r0
	ldrb r2, [r4]
	cmp r1, r2
	beq _081E77B8
	strb r1, [r4]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x11
	bne _081E7744
	ldr r3, _081E773C @ =0x00001608
	adds r0, r7, r3
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r0, _081E7740 @ =0x00001514
	adds r1, r7, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xde
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	b _081E77A0
	.align 2, 0
_081E7738: .4byte 0x0000161A
_081E773C: .4byte 0x00001608
_081E7740: .4byte 0x00001514
_081E7744:
	ldr r1, _081E77A8 @ =0x00001608
	adds r0, r7, r1
	ldr r0, [r0]
	bl FUN_0804a1f0
	ldrb r1, [r4]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r7, r0
	ldr r2, _081E77AC @ =0x00000BC4
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081E7770
	ldr r3, _081E77B0 @ =0x00001514
	adds r0, r7, r3
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_081E7770:
	movs r0, #0x81
	lsls r0, r0, #4
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xde
	lsls r1, r1, #3
	adds r2, r7, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r3, _081E77B4 @ =0x00000828
	adds r2, r7, r3
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	bl FUN_081e2ee8
_081E77A0:
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _081E78B2
	.align 2, 0
_081E77A8: .4byte 0x00001608
_081E77AC: .4byte 0x00000BC4
_081E77B0: .4byte 0x00001514
_081E77B4: .4byte 0x00000828
_081E77B8:
	ldr r0, _081E77EC @ =0x030044E0
	ldrh r2, [r0, #2]
	movs r5, #1
	movs r4, #1
	adds r0, r4, #0
	ands r0, r2
	cmp r0, #0
	beq _081E77FC
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x11
	bne _081E78B2
	ldr r0, _081E77F0 @ =FUN_081e6b5c
	movs r1, #7
	str r0, [r7, #0x18]
	ldr r2, _081E77F4 @ =0x00001614
	adds r0, r7, r2
	strb r5, [r0]
	ldr r3, _081E77F8 @ =0x00001616
	adds r0, r7, r3
	strb r1, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _081E78B2
	.align 2, 0
_081E77EC: .4byte 0x030044E0
_081E77F0: .4byte FUN_081e6b5c
_081E77F4: .4byte 0x00001614
_081E77F8: .4byte 0x00001616
_081E77FC:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081E7874
	adds r0, r7, #0
	movs r1, #0xa
	bl FUN_081e4c64
	ldr r0, _081E785C @ =0x00001618
	adds r1, r7, r0
	movs r0, #0xa
	strb r0, [r1]
	movs r2, #0x81
	lsls r2, r2, #4
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r3, _081E7860 @ =0x00001514
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r0, _081E7864 @ =0x000014B4
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r2, #0xde
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r3, _081E7868 @ =0x00001624
	adds r0, r7, r3
	strb r5, [r0]
	ldr r0, _081E786C @ =FUN_081e5d14
	movs r1, #0x10
	str r0, [r7, #0x18]
	ldr r2, _081E7870 @ =0x00001614
	adds r0, r7, r2
	strb r5, [r0]
	subs r3, #0xe
	adds r0, r7, r3
	strb r1, [r0]
	b _081E78B2
	.align 2, 0
_081E785C: .4byte 0x00001618
_081E7860: .4byte 0x00001514
_081E7864: .4byte 0x000014B4
_081E7868: .4byte 0x00001624
_081E786C: .4byte FUN_081e5d14
_081E7870: .4byte 0x00001614
_081E7874:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081E78B2
	movs r0, #0xf6
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	str r4, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #0x19
	movs r1, #0x10
	movs r2, #5
	movs r3, #1
	bl FUN_081e4644
	ldr r0, _081E78C4 @ =FUN_081e564c
	movs r1, #0xb
	str r0, [r7, #0x18]
	ldr r2, _081E78C8 @ =0x00001614
	adds r0, r7, r2
	strb r5, [r0]
	ldr r3, _081E78CC @ =0x00001616
	adds r0, r7, r3
	strb r1, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
_081E78B2:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E78C4: .4byte FUN_081e564c
_081E78C8: .4byte 0x00001614
_081E78CC: .4byte 0x00001616

	thumb_func_start FUN_081e78d0
FUN_081e78d0: @ 0x081E78D0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _081E79B0 @ =0x00001614
	adds r7, r6, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _081E799A
	bl FUN_08049e5c
	bl FUN_08049fa8
	ldr r1, _081E79B4 @ =0x00001610
	adds r2, r6, r1
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r6, #0
	bl FUN_081e3fe0
	adds r0, r6, #0
	bl FUN_081e4450
	adds r0, r6, #0
	bl FUN_081e2b08
	movs r2, #0xb0
	lsls r2, r2, #5
	adds r0, r6, r2
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, _081E79B8 @ =0x00001604
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r2, _081E79BC @ =0x00001608
	adds r0, r6, r2
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r0, _081E79C0 @ =0x0000160C
	adds r4, r6, r0
	ldr r0, [r4]
	bl FUN_0804a210
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	ldr r1, [r6, #0x20]
	movs r0, #0
	movs r2, #3
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, [r4]
	movs r1, #6
	str r1, [sp]
	movs r1, #1
	movs r2, #7
	movs r3, #0x1c
	bl FUN_0804a38c
	ldr r0, [r4]
	ldr r2, _081E79C4 @ =0x000015F0
	adds r1, r6, r2
	ldr r1, [r1]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #0x16
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	adds r0, r6, #0
	movs r1, #0xb
	bl FUN_081e4c64
	movs r0, #1
	bl Sound_FadeOutBGM
	ldr r1, _081E79C8 @ =0x0000162A
	adds r0, r6, r1
	movs r1, #0
	strh r5, [r0]
	strb r1, [r7]
_081E799A:
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E79B4 @ =0x00001610
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E79CC
	movs r0, #1
	b _081E79CE
	.align 2, 0
_081E79B0: .4byte 0x00001614
_081E79B4: .4byte 0x00001610
_081E79B8: .4byte 0x00001604
_081E79BC: .4byte 0x00001608
_081E79C0: .4byte 0x0000160C
_081E79C4: .4byte 0x000015F0
_081E79C8: .4byte 0x0000162A
_081E79CC:
	movs r0, #0
_081E79CE:
	cmp r0, #0
	beq _081E79DC
	adds r0, r6, #0
	movs r1, #0xb
	bl FUN_081e4c64
	b _081E7A22
_081E79DC:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E79EC
	movs r0, #1
	b _081E79EE
_081E79EC:
	movs r0, #0
_081E79EE:
	cmp r0, #0
	beq _081E7A22
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xb
	bne _081E7A22
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E7A22
	bl FUN_081e25f0
	ldr r0, _081E7A2C @ =FUN_081e7a38
	movs r2, #0x1b
	str r0, [r6, #0x18]
	ldr r0, _081E7A30 @ =0x00001614
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7A34 @ =0x00001616
	adds r0, r6, r1
	strb r2, [r0]
_081E7A22:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E7A2C: .4byte FUN_081e7a38
_081E7A30: .4byte 0x00001614
_081E7A34: .4byte 0x00001616

	thumb_func_start FUN_081e7a38
FUN_081e7a38: @ 0x081E7A38
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _081E7AAC @ =0x00001614
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081E7A54
	ldr r1, _081E7AB0 @ =0x0000162A
	adds r0, r5, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081E7A54:
	ldr r0, _081E7AB0 @ =0x0000162A
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x24
	bne _081E7A76
	movs r0, #4
	str r0, [sp]
	ldr r0, _081E7AB4 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_081E7A76:
	ldrh r0, [r4]
	cmp r0, #0x3c
	bls _081E7AB8
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E7ABC
	adds r0, r5, #0
	bl FUN_081e3cd4
	adds r0, r5, #0
	bl KillEntity
	b _081E7ABC
	.align 2, 0
_081E7AAC: .4byte 0x00001614
_081E7AB0: .4byte 0x0000162A
_081E7AB4: .4byte 0x0000FFFF
_081E7AB8:
	adds r0, #1
	strh r0, [r4]
_081E7ABC:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e7ac4
FUN_081e7ac4: @ 0x081E7AC4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081E7B1C @ =0x00001614
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E7AEA
	ldr r0, _081E7B20 @ =0x0000162A
	adds r1, r5, r0
	movs r4, #0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _081E7B24 @ =0x00001618
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_081e4c64
	strb r4, [r6]
_081E7AEA:
	adds r0, r5, #0
	bl FUN_081e2ee8
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xb
	bne _081E7B30
	ldr r0, _081E7B28 @ =FUN_081e78d0
	movs r2, #0x1a
	str r0, [r5, #0x18]
	ldr r0, _081E7B1C @ =0x00001614
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7B2C @ =0x00001616
	adds r0, r5, r1
	strb r2, [r0]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081E7BEA
	.align 2, 0
_081E7B1C: .4byte 0x00001614
_081E7B20: .4byte 0x0000162A
_081E7B24: .4byte 0x00001618
_081E7B28: .4byte FUN_081e78d0
_081E7B2C: .4byte 0x00001616
_081E7B30:
	adds r0, r5, #0
	bl FUN_081e4a60
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E7B4C @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081E7B50
	movs r0, #1
	b _081E7B52
	.align 2, 0
_081E7B4C: .4byte 0x00001610
_081E7B50:
	movs r0, #0
_081E7B52:
	cmp r0, #0
	beq _081E7B68
	ldr r1, _081E7B64 @ =0x00001618
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_081e4c64
	b _081E7BEA
	.align 2, 0
_081E7B64: .4byte 0x00001618
_081E7B68:
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xd
	bne _081E7BEA
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E7B86
	movs r0, #1
	b _081E7B88
_081E7B86:
	movs r0, #0
_081E7B88:
	cmp r0, #0
	beq _081E7BEA
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E7BEA
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, _081E7BBC @ =0x00001604
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_0804a210
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E7BC0
	movs r0, #1
	b _081E7BC2
	.align 2, 0
_081E7BBC: .4byte 0x00001604
_081E7BC0:
	movs r0, #0
_081E7BC2:
	cmp r0, #0
	beq _081E7BD0
	ldr r0, _081E7BCC @ =FUN_081e6f28
	movs r2, #3
	b _081E7BD4
	.align 2, 0
_081E7BCC: .4byte FUN_081e6f28
_081E7BD0:
	ldr r0, _081E7BF0 @ =FUN_081e7414
	movs r2, #4
_081E7BD4:
	str r0, [r5, #0x18]
	ldr r0, _081E7BF4 @ =0x00001614
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7BF8 @ =0x00001616
	adds r0, r5, r1
	strb r2, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
_081E7BEA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E7BF0: .4byte FUN_081e7414
_081E7BF4: .4byte 0x00001614
_081E7BF8: .4byte 0x00001616

	thumb_func_start FUN_081e7bfc
FUN_081e7bfc: @ 0x081E7BFC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _081E7C54 @ =0x00001614
	adds r5, r6, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E7C22
	ldr r2, _081E7C58 @ =0x0000162A
	adds r1, r6, r2
	movs r4, #0
	movs r0, #0
	strh r0, [r1]
	ldr r3, _081E7C5C @ =0x00001618
	adds r0, r6, r3
	ldrb r1, [r0]
	adds r0, r6, #0
	bl FUN_081e4c64
	strb r4, [r5]
_081E7C22:
	adds r0, r6, #0
	bl FUN_081e2ee8
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xb
	bne _081E7C68
	ldr r0, _081E7C60 @ =FUN_081e78d0
	movs r2, #0x1a
	str r0, [r6, #0x18]
	ldr r3, _081E7C54 @ =0x00001614
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7C64 @ =0x00001616
	adds r0, r6, r1
	strb r2, [r0]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081E7D9E
	.align 2, 0
_081E7C54: .4byte 0x00001614
_081E7C58: .4byte 0x0000162A
_081E7C5C: .4byte 0x00001618
_081E7C60: .4byte FUN_081e78d0
_081E7C64: .4byte 0x00001616
_081E7C68:
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r3, _081E7C80 @ =0x00001610
	adds r1, r6, r3
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081E7C84
	movs r0, #1
	b _081E7C86
	.align 2, 0
_081E7C80: .4byte 0x00001610
_081E7C84:
	movs r0, #0
_081E7C86:
	cmp r0, #0
	beq _081E7C9C
	ldr r1, _081E7C98 @ =0x00001618
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r6, #0
	bl FUN_081e4c64
	b _081E7D9E
	.align 2, 0
_081E7C98: .4byte 0x00001618
_081E7C9C:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081E7CAC
	movs r0, #1
	b _081E7CAE
_081E7CAC:
	movs r0, #0
_081E7CAE:
	cmp r0, #0
	beq _081E7D9E
	bl FUN_081e2380
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E7D9E
	ldr r2, _081E7D34 @ =0x0000162E
	adds r0, r6, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	cmp r2, #0
	bne _081E7D50
	ldr r0, _081E7D38 @ =FUN_081e7414
	movs r2, #4
	str r0, [r6, #0x18]
	ldr r0, _081E7D3C @ =0x00001614
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7D40 @ =0x00001616
	adds r0, r6, r1
	strb r2, [r0]
	bl FUN_08049e5c
	bl FUN_08049f84
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	movs r2, #0xb0
	lsls r2, r2, #5
	adds r4, r6, r2
	ldr r0, [r4]
	bl FUN_0804a210
	ldr r3, _081E7D44 @ =0x00001604
	adds r5, r6, r3
	ldr r0, [r5]
	bl FUN_0804a210
	ldr r0, [r4]
	ldr r1, _081E7D48 @ =0x00000BB8
	adds r2, r6, r1
	movs r1, #1
	bl FUN_0804a40c
	ldr r0, [r5]
	ldr r1, _081E7D4C @ =0x030046A0
	ldr r2, [r1]
	movs r3, #0xf0
	lsls r3, r3, #2
	adds r2, r2, r3
	movs r1, #2
	bl FUN_0804a40c
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _081E7D9E
	.align 2, 0
_081E7D34: .4byte 0x0000162E
_081E7D38: .4byte FUN_081e7414
_081E7D3C: .4byte 0x00001614
_081E7D40: .4byte 0x00001616
_081E7D44: .4byte 0x00001604
_081E7D48: .4byte 0x00000BB8
_081E7D4C: .4byte 0x030046A0
_081E7D50:
	cmp r2, #1
	bne _081E7D9E
	ldr r0, _081E7DA4 @ =FUN_081e6f28
	movs r1, #3
	str r0, [r6, #0x18]
	ldr r3, _081E7DA8 @ =0x00001614
	adds r0, r6, r3
	strb r2, [r0]
	ldr r2, _081E7DAC @ =0x00001616
	adds r0, r6, r2
	strb r1, [r0]
	bl FUN_08049e5c
	bl FUN_08049f84
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	movs r3, #0xb0
	lsls r3, r3, #5
	adds r0, r6, r3
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, _081E7DB0 @ =0x00001604
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_0804a210
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
	movs r0, #0xdd
	bl PlaySound_082406e0
_081E7D9E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E7DA4: .4byte FUN_081e6f28
_081E7DA8: .4byte 0x00001614
_081E7DAC: .4byte 0x00001616
_081E7DB0: .4byte 0x00001604

	thumb_func_start FUN_081e7db4
FUN_081e7db4: @ 0x081E7DB4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081E7E00 @ =0x00001614
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081E7DCE
	ldr r1, _081E7E04 @ =0x0000162A
	adds r0, r5, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081E7DCE:
	adds r0, r5, #0
	bl FUN_081e32d8
	adds r0, r5, #0
	bl FUN_081e2ee8
	adds r0, r5, #0
	bl FUN_081e4a60
	ldr r2, _081E7E04 @ =0x0000162A
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #0x1d
	bhi _081E7E08
	adds r0, #1
	strh r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xb
	beq _081E7DFE
	b _081E7FAE
_081E7DFE:
	b _081E7E26
	.align 2, 0
_081E7E00: .4byte 0x00001614
_081E7E04: .4byte 0x0000162A
_081E7E08:
	ldr r0, _081E7E44 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	bne _081E7E26
	movs r2, #0xb1
	lsls r2, r2, #5
	adds r0, r5, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xb
	bne _081E7E54
_081E7E26:
	ldr r0, _081E7E48 @ =FUN_081e78d0
	movs r2, #0x1a
	str r0, [r5, #0x18]
	ldr r0, _081E7E4C @ =0x00001614
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7E50 @ =0x00001616
	adds r0, r5, r1
	strb r2, [r0]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081E7FAE
	.align 2, 0
_081E7E44: .4byte 0x030044E0
_081E7E48: .4byte FUN_081e78d0
_081E7E4C: .4byte 0x00001614
_081E7E50: .4byte 0x00001616
_081E7E54:
	ldr r2, _081E7E88 @ =0x00001615
	adds r4, r5, r2
	ldrb r0, [r4]
	cmp r0, #0
	bne _081E7EF8
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _081E7E8C
	movs r0, #0xc6
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r0, [r1]
	movs r3, #1
	orrs r0, r3
	str r0, [r1]
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	strb r3, [r4]
	b _081E7F20
	.align 2, 0
_081E7E88: .4byte 0x00001615
_081E7E8C:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081E7E96
	b _081E7FAE
_081E7E96:
	ldr r2, _081E7EE0 @ =0x00000BB5
	adds r0, r5, r2
	ldrb r0, [r0]
	subs r2, #1
	adds r1, r5, r2
	ldrb r1, [r1]
	subs r0, r0, r1
	cmp r0, #0
	ble _081E7F4C
	bl FUN_08243104
	cmp r0, #0
	ble _081E7F4C
	bl FUN_08049e5c
	ldr r1, _081E7EE4 @ =0x00001618
	adds r0, r5, r1
	strb r6, [r0]
	movs r2, #0x80
	lsls r2, r2, #9
	ldr r0, _081E7EE8 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E7EEC @ =FUN_081e7ac4
	movs r2, #5
	str r0, [r5, #0x18]
	ldr r0, _081E7EF0 @ =0x00001614
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7EF4 @ =0x00001616
	adds r0, r5, r1
	strb r2, [r0]
	b _081E7FAE
	.align 2, 0
_081E7EE0: .4byte 0x00000BB5
_081E7EE4: .4byte 0x00001618
_081E7EE8: .4byte 0x00001610
_081E7EEC: .4byte FUN_081e7ac4
_081E7EF0: .4byte 0x00001614
_081E7EF4: .4byte 0x00001616
_081E7EF8:
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _081E7F28
	movs r0, #0xc6
	lsls r0, r0, #3
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	strb r6, [r4]
_081E7F20:
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _081E7FAE
_081E7F28:
	movs r6, #1
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081E7FAE
	bl FUN_08243140
	adds r4, r0, #0
	bl FUN_08243104
	subs r4, r4, r0
	cmp r4, #0
	ble _081E7F4C
	ldr r2, _081E7F58 @ =0x00000BB4
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E7F5C
_081E7F4C:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _081E7FAE
	.align 2, 0
_081E7F58: .4byte 0x00000BB4
_081E7F5C:
	bl FUN_08049e5c
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, _081E7FB4 @ =0x00000BB8
	adds r2, r5, r1
	movs r1, #1
	bl FUN_0804a40c
	ldr r2, _081E7FB8 @ =0x00001604
	adds r0, r5, r2
	ldr r0, [r0]
	ldr r1, _081E7FBC @ =0x030046A0
	ldr r2, [r1]
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #2
	bl FUN_0804a40c
	ldr r2, _081E7FC0 @ =0x00001618
	adds r0, r5, r2
	strb r6, [r0]
	movs r2, #0x80
	lsls r2, r2, #8
	ldr r0, _081E7FC4 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E7FC8 @ =FUN_081e7ac4
	movs r1, #5
	str r0, [r5, #0x18]
	ldr r2, _081E7FCC @ =0x00001614
	adds r0, r5, r2
	strb r6, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
_081E7FAE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E7FB4: .4byte 0x00000BB8
_081E7FB8: .4byte 0x00001604
_081E7FBC: .4byte 0x030046A0
_081E7FC0: .4byte 0x00001618
_081E7FC4: .4byte 0x00001610
_081E7FC8: .4byte FUN_081e7ac4
_081E7FCC: .4byte 0x00001614

	thumb_func_start FUN_081e7fd0
FUN_081e7fd0: @ 0x081E7FD0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081E8014 @ =0x00001614
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E7FF0
	movs r0, #1
	bl Sound_FadeOutBGM
	ldr r1, _081E8018 @ =0x0000162A
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r5]
_081E7FF0:
	adds r0, r4, #0
	bl FUN_081e2ee8
	ldr r2, _081E8018 @ =0x0000162A
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0x1d
	bhi _081E801C
	adds r0, #1
	strh r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xb
	bne _081E8090
	b _081E8036
	.align 2, 0
_081E8014: .4byte 0x00001614
_081E8018: .4byte 0x0000162A
_081E801C:
	ldr r0, _081E8054 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _081E8036
	movs r2, #0xb1
	lsls r2, r2, #5
	adds r0, r4, r2
	ldrh r1, [r0]
	lsls r0, r1, #0x10
	cmp r1, #0xb
	bne _081E8064
_081E8036:
	ldr r0, _081E8058 @ =FUN_081e78d0
	movs r2, #0x1a
	str r0, [r4, #0x18]
	ldr r0, _081E805C @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E8060 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081E8090
	.align 2, 0
_081E8054: .4byte 0x030044E0
_081E8058: .4byte FUN_081e78d0
_081E805C: .4byte 0x00001614
_081E8060: .4byte 0x00001616
_081E8064:
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _081E8090
	ldr r2, _081E8098 @ =0x0000162E
	adds r0, r4, r2
	strh r1, [r0]
	bl FUN_08049e5c
	ldr r0, _081E809C @ =0x00001618
	adds r1, r4, r0
	movs r0, #0xd
	strb r0, [r1]
	ldr r0, _081E80A0 @ =FUN_081e7bfc
	movs r2, #0x1d
	str r0, [r4, #0x18]
	ldr r0, _081E80A4 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E80A8 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
_081E8090:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E8098: .4byte 0x0000162E
_081E809C: .4byte 0x00001618
_081E80A0: .4byte FUN_081e7bfc
_081E80A4: .4byte 0x00001614
_081E80A8: .4byte 0x00001616

	thumb_func_start FUN_081e80ac
FUN_081e80ac: @ 0x081E80AC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E80D8 @ =0x00001614
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081E80BE
	movs r0, #0
	strb r0, [r1]
_081E80BE:
	bl FUN_081e2454
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E80FC
	bl FUN_081e23e4
	cmp r0, #0
	beq _081E80DC
	adds r0, r4, #0
	bl FUN_081e2c14
	b _081E80E2
	.align 2, 0
_081E80D8: .4byte 0x00001614
_081E80DC:
	adds r0, r4, #0
	bl FUN_081e2cdc
_081E80E2:
	ldr r0, _081E8104 @ =FUN_081e8110
	movs r2, #2
	str r0, [r4, #0x18]
	ldr r0, _081E8108 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E810C @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_081e275c
_081E80FC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E8104: .4byte FUN_081e8110
_081E8108: .4byte 0x00001614
_081E810C: .4byte 0x00001616

	thumb_func_start FUN_081e8110
FUN_081e8110: @ 0x081E8110
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _081E819C @ =0x00001614
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081E817C
	adds r0, r5, #0
	bl FUN_081e2960
	adds r0, r5, #0
	movs r1, #0
	movs r2, #6
	bl FUN_081e4cb4
	ldr r0, _081E81A0 @ =0x00001618
	adds r1, r5, r0
	movs r3, #0
	movs r0, #6
	strb r0, [r1]
	ldr r1, _081E81A4 @ =0x00001610
	adds r2, r5, r1
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xb1
	lsls r0, r0, #5
	adds r1, r5, r0
	ldr r0, _081E81A8 @ =0x0000FFFF
	strh r0, [r1]
	ldr r1, _081E81AC @ =0x00001625
	adds r0, r5, r1
	strb r3, [r0]
	bl FUN_081e23e4
	cmp r0, #0
	beq _081E816E
	movs r0, #0xa8
	bl sound_08240960
	cmp r0, #0
	bne _081E816E
	movs r0, #0xa8
	bl sound_08240264
_081E816E:
	adds r0, r5, #0
	bl FUN_081e49a8
	ldr r0, _081E819C @ =0x00001614
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
_081E817C:
	adds r0, r5, #0
	bl FUN_081e2ee8
	adds r0, r5, #0
	bl FUN_081e4a60
	movs r2, #2
	ldr r0, _081E81A4 @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081E81B0
	movs r0, #1
	b _081E81B2
	.align 2, 0
_081E819C: .4byte 0x00001614
_081E81A0: .4byte 0x00001618
_081E81A4: .4byte 0x00001610
_081E81A8: .4byte 0x0000FFFF
_081E81AC: .4byte 0x00001625
_081E81B0:
	movs r0, #0
_081E81B2:
	cmp r0, #0
	beq _081E81FC
	movs r1, #0x10
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E81C4
	movs r0, #1
	b _081E81C6
_081E81C4:
	movs r0, #0
_081E81C6:
	adds r6, r0, #0
	cmp r6, #0
	bne _081E8230
	adds r0, r5, #0
	bl FUN_081e3ce8
	movs r1, #0x10
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #7
	bl FUN_081e4cb4
	ldr r0, _081E81F4 @ =0x00001618
	adds r1, r5, r0
	movs r0, #7
	strb r0, [r1]
	ldr r1, _081E81F8 @ =0x00001625
	adds r0, r5, r1
	strb r6, [r0]
	b _081E83DA
	.align 2, 0
_081E81F4: .4byte 0x00001618
_081E81F8: .4byte 0x00001625
_081E81FC:
	ldr r0, _081E822C @ =0x00001625
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x77
	bls _081E8230
	bl FUN_081e24b4
	adds r0, r5, #0
	bl FUN_081e44d0
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r5, #0
	bl KillEntity
	b _081E83DA
	.align 2, 0
_081E822C: .4byte 0x00001625
_081E8230:
	movs r1, #4
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E823E
	movs r0, #1
	b _081E8240
_081E823E:
	movs r0, #0
_081E8240:
	cmp r0, #0
	beq _081E8280
	movs r1, #0x20
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E8252
	movs r0, #1
	b _081E8254
_081E8252:
	movs r0, #0
_081E8254:
	cmp r0, #0
	bne _081E8280
	adds r0, r5, #0
	bl FUN_081e32d8
	movs r1, #0x20
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #8
	bl FUN_081e4cb4
	ldr r0, _081E827C @ =0x00001618
	adds r1, r5, r0
	movs r0, #8
	strb r0, [r1]
	b _081E83DA
	.align 2, 0
_081E827C: .4byte 0x00001618
_081E8280:
	movs r1, #8
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E828E
	movs r0, #1
	b _081E8290
_081E828E:
	movs r0, #0
_081E8290:
	cmp r0, #0
	beq _081E82CC
	movs r1, #0x40
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E82A2
	movs r0, #1
	b _081E82A4
_081E82A2:
	movs r0, #0
_081E82A4:
	cmp r0, #0
	bne _081E82CC
	adds r0, r5, #0
	bl FUN_081e3444
	movs r1, #0x40
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0xc
	bl FUN_081e4c64
	ldr r0, _081E82C8 @ =0x00001618
	adds r1, r5, r0
	movs r0, #0xc
	strb r0, [r1]
	b _081E83DA
	.align 2, 0
_081E82C8: .4byte 0x00001618
_081E82CC:
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E82DC
	movs r0, #1
	b _081E82DE
_081E82DC:
	movs r0, #0
_081E82DE:
	cmp r0, #0
	beq _081E82F4
	ldr r1, _081E82F0 @ =0x00001618
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_081e4c64
	b _081E83DA
	.align 2, 0
_081E82F0: .4byte 0x00001618
_081E82F4:
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E8304
	movs r0, #1
	b _081E8306
_081E8304:
	movs r0, #0
_081E8306:
	cmp r0, #0
	beq _081E8320
	ldr r1, _081E831C @ =0x00001618
	adds r0, r5, r1
	ldrb r2, [r0]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_081e4cb4
	b _081E83DA
	.align 2, 0
_081E831C: .4byte 0x00001618
_081E8320:
	movs r1, #0x10
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E832E
	movs r0, #1
	b _081E8330
_081E832E:
	movs r0, #0
_081E8330:
	cmp r0, #0
	beq _081E83DA
	movs r1, #0x20
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E8342
	movs r0, #1
	b _081E8344
_081E8342:
	movs r0, #0
_081E8344:
	cmp r0, #0
	beq _081E83DA
	movs r1, #0x40
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E8356
	movs r0, #1
	b _081E8358
_081E8356:
	movs r0, #0
_081E8358:
	cmp r0, #0
	beq _081E83DA
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xc
	bne _081E83DA
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E837A
	movs r0, #1
	b _081E837C
_081E837A:
	movs r0, #0
_081E837C:
	cmp r0, #0
	beq _081E83DA
	bl FUN_081e2380
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _081E83DA
	bl FUN_081e23e4
	cmp r0, #0
	beq _081E83BC
	ldr r0, _081E83B0 @ =FUN_081e7db4
	str r0, [r5, #0x18]
	ldr r0, _081E83B4 @ =0x00001614
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E83B8 @ =0x00001616
	adds r0, r5, r1
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_081e2d98
	b _081E83D4
	.align 2, 0
_081E83B0: .4byte FUN_081e7db4
_081E83B4: .4byte 0x00001614
_081E83B8: .4byte 0x00001616
_081E83BC:
	ldr r0, _081E83E0 @ =FUN_081e7fd0
	movs r4, #1
	str r0, [r5, #0x18]
	ldr r1, _081E83E4 @ =0x00001614
	adds r0, r5, r1
	strb r4, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_081e2dd8
_081E83D4:
	ldr r1, _081E83E8 @ =0x0000162C
	adds r0, r5, r1
	strh r4, [r0]
_081E83DA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E83E0: .4byte FUN_081e7fd0
_081E83E4: .4byte 0x00001614
_081E83E8: .4byte 0x0000162C

	thumb_func_start FUN_081e83ec
FUN_081e83ec: @ 0x081E83EC
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #0x10
	ldr r2, _081E8404 @ =0x00001610
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E8408
	movs r0, #1
	b _081E840A
	.align 2, 0
_081E8404: .4byte 0x00001610
_081E8408:
	movs r0, #0
_081E840A:
	cmp r0, #0
	bne _081E8414
	ldr r1, _081E8434 @ =0x030047B8
	movs r0, #1
	str r0, [r1]
_081E8414:
	bl FUN_081e2484
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081E8454
	movs r1, #0x80
	lsls r1, r1, #0xe
	ldr r2, _081E8438 @ =0x00001610
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E843C
	movs r0, #1
	b _081E843E
	.align 2, 0
_081E8434: .4byte 0x030047B8
_081E8438: .4byte 0x00001610
_081E843C:
	movs r0, #0
_081E843E:
	cmp r0, #0
	bne _081E8454
	adds r0, r4, #0
	bl FUN_081e44d0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #1
	rsbs r0, r0, #0
	b _081E8462
_081E8454:
	ldr r1, [r4, #0x18]
	cmp r1, #0
	beq _081E8460
	adds r0, r4, #0
	bl _call_via_r1
_081E8460:
	movs r0, #1
_081E8462:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e8468
FUN_081e8468: @ 0x081E8468
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_081e44d0
	adds r0, r4, #0
	bl FUN_081e44b4
	adds r0, r4, #0
	bl FUN_081e4484
	bl FUN_081e2484
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _081E84AC
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	bl FUN_0824172c
	ldr r0, _081E84B4 @ =0x0300481C
	str r5, [r0]
	ldr r0, _081E84B8 @ =0x00001626
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081E84AC
	movs r1, #0
	bl Script_ExecById
_081E84AC:
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081E84B4: .4byte 0x0300481C
_081E84B8: .4byte 0x00001626

	thumb_func_start FUN_081e84bc
FUN_081e84bc: @ 0x081E84BC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081e2628
	adds r0, r4, #0
	bl FUN_081e27f0
	adds r0, r4, #0
	bl FUN_081e2960
	adds r0, r4, #0
	bl FUN_081e3ea8
	adds r0, r4, #0
	bl FUN_081e3f0c
	adds r0, r4, #0
	bl FUN_081e4054
	ldr r1, _081E8550 @ =0x00001615
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _081E8554 @ =0x00001610
	adds r0, r4, r2
	str r1, [r0]
	ldr r0, _081E8558 @ =0x00001617
	adds r1, r4, r0
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_081e2e84
	movs r0, #0x6c
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, _081E855C @ =0x00001628
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, _081E8560 @ =0x00001626
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_081e23ac
	ldr r0, _081E8564 @ =FUN_081e3958
	ldr r1, _081E8568 @ =FUN_081e3cd4
	ldr r2, _081E856C @ =FUN_081e3cc0
	bl FUN_081e23c4
	adds r0, r4, #0
	bl FUN_081e3d78
	adds r0, r4, #0
	bl FUN_081e2b08
	ldr r0, _081E8570 @ =FUN_081e80ac
	movs r2, #0x14
	str r0, [r4, #0x18]
	ldr r0, _081E8574 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E8578 @ =0x00001616
	adds r4, r4, r1
	strb r2, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081E8550: .4byte 0x00001615
_081E8554: .4byte 0x00001610
_081E8558: .4byte 0x00001617
_081E855C: .4byte 0x00001628
_081E8560: .4byte 0x00001626
_081E8564: .4byte FUN_081e3958
_081E8568: .4byte FUN_081e3cd4
_081E856C: .4byte FUN_081e3cc0
_081E8570: .4byte FUN_081e80ac
_081E8574: .4byte 0x00001614
_081E8578: .4byte 0x00001616

	thumb_func_start FUN_081e857c
FUN_081e857c: @ 0x081E857C
	push {r4, lr}
	ldr r1, _081E85A8 @ =0x00001630
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081E85B4
	ldr r1, _081E85AC @ =FUN_081e83ec
	ldr r2, _081E85B0 @ =FUN_081e8468
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081e84bc
	cmp r0, #0
	bge _081E85B4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081E85B6
	.align 2, 0
_081E85A8: .4byte 0x00001630
_081E85AC: .4byte FUN_081e83ec
_081E85B0: .4byte FUN_081e8468
_081E85B4:
	adds r0, r4, #0
_081E85B6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e85bc
FUN_081e85bc: @ 0x081E85BC
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e85c0
FUN_081e85c0: @ 0x081E85C0
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x1c
	adds r5, r0, #0
	mov r8, r1
	mov sb, r2
	adds r6, r3, #0
	ldr r2, _081E864C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x10
	orrs r0, r3
	ldr r1, _081E8650 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0x80
	lsls r0, r0, #0x10
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r5, #0
	adds r4, #0x44
	ldr r2, _081E8654 @ =0x00002101
	str r3, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r0, _081E8658 @ =0x00008020
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0
	bl FUN_082364f8
	ldr r1, _081E865C @ =FUN_081e85bc
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r5, #0x1c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E864C: .4byte 0xFFFF0000
_081E8650: .4byte 0x0000FFFF
_081E8654: .4byte 0x00002101
_081E8658: .4byte 0x00008020
_081E865C: .4byte FUN_081e85bc

	thumb_func_start FUN_081e8660
FUN_081e8660: @ 0x081E8660
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e8664
FUN_081e8664: @ 0x081E8664
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	adds r5, r6, #0
	adds r0, r6, #0
	adds r0, #0x9c
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #2
	cmp r0, #0x3c
	bgt _081E8682
	movs r2, #0
	cmp r0, #0x28
	ble _081E8682
	movs r2, #1
_081E8682:
	adds r4, r6, #0
	adds r4, #0x9c
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r1, _081E86AC @ =0x085AE44C
	adds r1, r2, r1
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _081E86B4
	ldr r1, [r5]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _081E86B0
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	b _081E86B2
	.align 2, 0
_081E86AC: .4byte 0x085AE44C
_081E86B0:
	orrs r1, r2
_081E86B2:
	str r1, [r5]
_081E86B4:
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0x5a
	ble _081E86DE
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	adds r0, r6, #0
	adds r0, #0x97
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r0
	ldr r0, [r7, #0x38]
	bics r0, r1
	str r0, [r7, #0x38]
	adds r1, r6, #0
	adds r1, #0x96
	movs r0, #0
	strb r0, [r1]
_081E86DE:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e86ec
FUN_081e86ec: @ 0x081E86EC
	push {r4, r5, lr}
	adds r4, r1, #0
	bl FUN_081e8664
	adds r5, r4, #0
	adds r5, #0x44
	adds r4, #0x1c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e8710
FUN_081e8710: @ 0x081E8710
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r8, r0
	adds r7, r1, #0
	adds r6, r7, #0
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	adds r4, r7, #0
	adds r4, #0x2c
	movs r1, #0x20
	adds r0, r7, #0
	adds r0, #0x94
	movs r2, #0
	ldrsh r0, [r0, r2]
	ands r0, r1
	cmp r0, #0
	beq _081E8744
	movs r0, #1
	b _081E8746
_081E8744:
	movs r0, #0
_081E8746:
	cmp r0, #0
	bne _081E874E
	strh r0, [r4, #8]
	strh r0, [r4, #0xe]
_081E874E:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E877A
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081E8782
_081E877A:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E8782:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E87A6
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081E87AE
_081E87A6:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E87AE:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _081E87E8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081E882E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E87F2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081E87EC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081E8808
	.align 2, 0
_081E87E8: .4byte 0x0000FFFF
_081E87EC:
	subs r0, #1
	strh r0, [r4, #8]
	b _081E8806
_081E87F2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081E8806
	strh r1, [r4, #8]
	movs r2, #1
	b _081E8808
_081E8806:
	movs r2, #0
_081E8808:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _081E8830
	movs r0, #1
	strb r0, [r4, #7]
	b _081E8830
_081E882E:
	movs r2, #0
_081E8830:
	cmp r2, #0
	beq _081E886A
	adds r1, r7, #0
	adds r1, #0x9c
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	adds r4, r7, #0
	adds r4, #0x97
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r1, r0
	mov r3, r8
	ldr r0, [r3, #0x38]
	bics r0, r1
	str r0, [r3, #0x38]
	adds r0, r7, #0
	adds r0, #0x96
	strb r2, [r0]
	adds r0, r6, #0
	bl FUN_0822a4e0
	movs r0, #0xff
	strb r0, [r4]
	b _081E8A2A
_081E886A:
	movs r2, #0x20
	adds r1, r7, #0
	adds r1, #0x94
	movs r3, #0
	ldrsh r0, [r1, r3]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081E8880
	movs r0, #1
	b _081E8882
_081E8880:
	movs r0, #0
_081E8882:
	movs r1, #0x1c
	adds r1, r1, r6
	mov r8, r1
	cmp r0, #0
	beq _081E888E
	b _081E8A16
_081E888E:
	ldr r0, [r6, #0x1c]
	ldr r1, [r6, #0x20]
	str r0, [sp]
	str r1, [sp, #4]
	mov r2, sp
	adds r3, r7, #0
	adds r3, #0x3c
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r7, #0x3c]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	ldrh r0, [r7, #0x3e]
	subs r0, #1
	strh r0, [r7, #0x3e]
	mov r5, r8
	ldrh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081E88E4
	cmp r1, #0
	blt _081E88E4
	ldr r0, _081E88E8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081E88E4
	ldr r0, _081E88EC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081E88F0
_081E88E4:
	movs r4, #0
	b _081E88FE
	.align 2, 0
_081E88E8: .4byte 0x030046A8
_081E88EC: .4byte 0x030046AC
_081E88F0:
	ldr r0, _081E8910 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081E88FE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E8914
	adds r0, #4
	b _081E8920
	.align 2, 0
_081E8910: .4byte 0x030046A4
_081E8914:
	ldr r0, _081E8934 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E8920:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081E8938
	cmp r2, #2
	beq _081E893C
	b _081E8940
	.align 2, 0
_081E8934: .4byte 0x030046A4
_081E8938:
	ldrb r0, [r5, #4]
	b _081E893E
_081E893C:
	ldrb r0, [r5]
_081E893E:
	subs r1, r1, r0
_081E8940:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	mov r5, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081E896E
	cmp r1, #0
	blt _081E896E
	ldr r0, _081E8974 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081E896E
	ldr r0, _081E8978 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081E897C
_081E896E:
	movs r4, #0
	b _081E898A
	.align 2, 0
_081E8974: .4byte 0x030046A8
_081E8978: .4byte 0x030046AC
_081E897C:
	ldr r0, _081E899C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081E898A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E89A0
	adds r0, #4
	b _081E89AC
	.align 2, 0
_081E899C: .4byte 0x030046A4
_081E89A0:
	ldr r0, _081E89C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E89AC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081E89C4
	cmp r2, #2
	beq _081E89C8
	b _081E89CC
	.align 2, 0
_081E89C0: .4byte 0x030046A4
_081E89C4:
	ldrb r0, [r5, #4]
	b _081E89CA
_081E89C8:
	ldrb r0, [r5]
_081E89CA:
	subs r1, r1, r0
_081E89CC:
	lsls r0, r1, #0x10
	lsrs r2, r0, #0x10
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	movs r3, #0x1e
	ldrsh r1, [r6, r3]
	mov r3, sb
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	blt _081E89EE
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bge _081E8A16
_081E89EE:
	ldrh r0, [r6, #0x1c]
	ldrh r1, [r7, #0x3c]
	subs r0, r0, r1
	movs r2, #0
	strh r0, [r6, #0x1c]
	adds r3, r7, #0
	adds r3, #0x40
	ldrh r0, [r6, #0x20]
	ldrh r1, [r3]
	subs r0, r0, r1
	strh r0, [r6, #0x20]
	mov r0, sl
	ldrh r1, [r0]
	movs r0, #0x20
	orrs r0, r1
	mov r1, sl
	strh r0, [r1]
	strh r2, [r7, #0x3c]
	strh r2, [r7, #0x3e]
	strh r2, [r3]
_081E8A16:
	adds r4, r7, #0
	adds r4, #0x44
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_081E8A2A:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e8a3c
FUN_081e8a3c: @ 0x081E8A3C
	push {r4, r5, r6, lr}
	mov ip, r0
	movs r2, #0
	movs r5, #1
	mov r3, ip
	adds r3, #0xd3
	mov r4, ip
	adds r4, #0x3c
_081E8A4C:
	adds r0, r5, #0
	lsls r0, r2
	mov r6, ip
	ldr r1, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081E8A5E
	movs r0, #1
	b _081E8A60
_081E8A5E:
	movs r0, #0
_081E8A60:
	cmp r0, #0
	bne _081E8A74
	adds r0, r5, #0
	lsls r0, r2
	orrs r0, r1
	mov r1, ip
	str r0, [r1, #0x38]
	strb r2, [r3]
	adds r0, r4, #0
	b _081E8A80
_081E8A74:
	adds r3, #0xa0
	adds r4, #0xa0
	adds r2, #1
	cmp r2, #3
	ble _081E8A4C
	movs r0, #0
_081E8A80:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e8a88
FUN_081e8a88: @ 0x081E8A88
	push {lr}
	bl FUN_081e8a3c
	cmp r0, #0
	bne _081E8A94
	movs r0, #0
_081E8A94:
	pop {r1}
	bx r1

	thumb_func_start FUN_081e8a98
FUN_081e8a98: @ 0x081E8A98
	push {lr}
	adds r1, r0, #0
	adds r0, #0x20
	asrs r1, r0, #6
	movs r0, #3
	ands r1, r0
	cmp r1, #2
	bgt _081E8AB0
	cmp r1, #1
	blt _081E8AB0
	movs r0, #1
	b _081E8AB2
_081E8AB0:
	movs r0, #0
_081E8AB2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e8ab8
FUN_081e8ab8: @ 0x081E8AB8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	adds r7, r1, #0
	mov sb, r2
	adds r5, r3, #0
	cmp r4, #0
	bne _081E8AD0
	b _081E8C42
_081E8AD0:
	bl FUN_081e8a88
	adds r6, r0, #0
	cmp r6, #0
	bne _081E8ADC
	b _081E8C42
_081E8ADC:
	adds r1, r6, #0
	adds r1, #0x98
	adds r0, r7, #0
	adds r0, #8
	str r0, [r1]
	subs r1, #2
	movs r0, #0
	mov r8, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x94
	mov r1, r8
	strh r1, [r0]
	adds r0, r6, #0
	adds r1, r5, #0
	ldr r2, [sp, #0x2c]
	ldr r3, [sp, #0x30]
	bl FUN_081e85c0
	adds r5, r6, #0
	adds r1, r4, #0
	adds r1, #0x18
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822a470
	ldrb r0, [r7, #5]
	bl FUN_081e8a98
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r5, #0
	adds r2, #0x2c
	ldr r1, [r4, #0x34]
	str r0, [sp]
	adds r0, r2, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	mov r2, sb
	ldrb r0, [r2, #4]
	cmp r0, #3
	bls _081E8B4C
	mov r3, r8
	strh r3, [r5, #0x3c]
	strh r3, [r5, #0x3e]
	adds r0, r5, #0
	adds r0, #0x40
	strh r3, [r0]
	b _081E8C38
_081E8B4C:
	mov r1, sb
	ldr r0, [r1, #0x38]
	add r2, sp, #4
	adds r4, r5, #0
	adds r4, #0x1c
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r5, #0x1c]
	subs r0, r0, r1
	adds r1, r2, #0
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	adds r0, r2, #0
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	adds r2, r5, #0
	adds r2, #0x86
	strb r0, [r2]
	ldr r3, _081E8BA8 @ =0x085B0A08
	ldrb r0, [r2]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _081E8BAC
	asrs r0, r0, #0xc
	b _081E8BB2
	.align 2, 0
_081E8BA8: .4byte 0x085B0A08
_081E8BAC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081E8BB2:
	strh r0, [r6, #0x3c]
	ldr r1, _081E8BD0 @ =0x085B0A08
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _081E8BD4
	asrs r0, r0, #0xc
	b _081E8BDA
	.align 2, 0
_081E8BD0: .4byte 0x085B0A08
_081E8BD4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081E8BDA:
	adds r4, r6, #0
	adds r4, #0x40
	strh r0, [r4]
	movs r2, #0
	movs r7, #0
	movs r3, #0x3c
	ldrsh r0, [r6, r3]
	cmp r0, #0
	beq _081E8BFC
	add r0, sp, #4
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0x3c
	ldrsh r1, [r6, r2]
	bl Div
	adds r2, r0, #0
_081E8BFC:
	movs r3, #0
	ldrsh r0, [r4, r3]
	cmp r0, #0
	beq _081E8C18
	add r0, sp, #4
	movs r1, #4
	ldrsh r0, [r0, r1]
	movs r3, #0
	ldrsh r1, [r4, r3]
	str r2, [sp, #0xc]
	bl Div
	adds r7, r0, #0
	ldr r2, [sp, #0xc]
_081E8C18:
	cmp r2, r7
	ble _081E8C28
	cmp r2, #0
	blt _081E8C24
	asrs r0, r2, #1
	b _081E8C36
_081E8C24:
	rsbs r0, r2, #0
	b _081E8C32
_081E8C28:
	cmp r7, #0
	blt _081E8C30
	asrs r0, r7, #1
	b _081E8C36
_081E8C30:
	rsbs r0, r7, #0
_081E8C32:
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081E8C36:
	strh r0, [r6, #0x3e]
_081E8C38:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	strb r1, [r5, #7]
_081E8C42:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e8c50
FUN_081e8c50: @ 0x081E8C50
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r7, #0
	ldr r0, _081E8C78 @ =0x085AE450
	mov r8, r0
	adds r5, r6, #0
	adds r5, #0xd2
	adds r4, r6, #0
	adds r4, #0x3c
_081E8C66:
	movs r1, #1
	lsls r1, r7
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081E8C7C
	movs r0, #1
	b _081E8C7E
	.align 2, 0
_081E8C78: .4byte 0x085AE450
_081E8C7C:
	movs r0, #0
_081E8C7E:
	cmp r0, #0
	beq _081E8C92
	ldrb r0, [r5]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
_081E8C92:
	adds r5, #0xa0
	adds r4, #0xa0
	adds r7, #1
	cmp r7, #3
	ble _081E8C66
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e8ca8
FUN_081e8ca8: @ 0x081E8CA8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x3c
_081E8CB2:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081E8CC2
	movs r0, #1
	b _081E8CC4
_081E8CC2:
	movs r0, #0
_081E8CC4:
	cmp r0, #0
	beq _081E8CCE
	adds r0, r4, #0
	bl FUN_0822a4e0
_081E8CCE:
	adds r4, #0xa0
	adds r5, #1
	cmp r5, #3
	ble _081E8CB2
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e8ce0
FUN_081e8ce0: @ 0x081E8CE0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	ldr r1, _081E8D00 @ =0x0000E74B
	bl Video_GetAuxSprite
	ldr r0, _081E8D04 @ =0x0000922E
	ldr r1, _081E8D08 @ =0x0000871C
	bl GetFile
	str r0, [r4, #0x34]
	movs r0, #0
	str r0, [r4, #0x38]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081E8D00: .4byte 0x0000E74B
_081E8D04: .4byte 0x0000922E
_081E8D08: .4byte 0x0000871C

	thumb_func_start FUN_081e8d0c
FUN_081e8d0c: @ 0x081E8D0C
	push {r4, lr}
	movs r1, #0xaf
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081E8D44
	ldr r1, _081E8D3C @ =FUN_081e8c50
	ldr r2, _081E8D40 @ =FUN_081e8ca8
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081e8ce0
	cmp r0, #0
	bge _081E8D44
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081E8D46
	.align 2, 0
_081E8D3C: .4byte FUN_081e8c50
_081E8D40: .4byte FUN_081e8ca8
_081E8D44:
	adds r0, r4, #0
_081E8D46:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e8d4c
FUN_081e8d4c: @ 0x081E8D4C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	adds r5, r1, #0
	adds r3, r2, #0
	ldrh r1, [r5, #6]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _081E8D62
	b _081E8E72
_081E8D62:
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _081E8D6E
	b _081E8E72
_081E8D6E:
	movs r1, #0xf
	ldrh r0, [r5, #0xa]
	ands r0, r1
	cmp r0, #0
	beq _081E8E2A
	ldrb r2, [r2, #2]
	ldr r0, [r5, #0x4c]
	movs r1, #8
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _081E8DC4
	adds r2, #0x20
	movs r0, #0xff
	ands r2, r0
	cmp r2, #0
	blt _081E8D94
	asrs r0, r2, #6
	b _081E8D9A
_081E8D94:
	rsbs r0, r2, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081E8D9A:
	adds r2, r0, #0
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _081E8DB2
	asrs r0, r1, #6
	b _081E8DB8
_081E8DB2:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081E8DB8:
	subs r0, r2, r0
	cmp r0, #0
	bge _081E8DC0
	rsbs r0, r0, #0
_081E8DC0:
	cmp r0, #2
	bne _081E8DC8
_081E8DC4:
	movs r0, #1
	b _081E8DCA
_081E8DC8:
	movs r0, #0
_081E8DCA:
	cmp r0, #0
	beq _081E8E72
	movs r0, #3
	strb r0, [r3]
	adds r1, r3, #0
	adds r1, #0xe6
	movs r0, #1
	strh r0, [r1]
	mov r2, sp
	adds r4, r5, #0
	adds r4, #0xc
	adds r3, r6, #0
	adds r3, #0xc
	ldrh r0, [r6, #0xc]
	ldrh r1, [r5, #0xc]
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
	bl ArcTan2_8
	cmp r0, #0
	blt _081E8E14
	asrs r0, r0, #5
	b _081E8E1A
_081E8E14:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081E8E1A:
	strh r0, [r6, #0x22]
	adds r2, r5, #0
	adds r2, #0x46
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	b _081E8E72
_081E8E2A:
	movs r0, #3
	strb r0, [r3]
	adds r0, r3, #0
	adds r0, #0xe6
	strh r4, [r0]
	add r2, sp, #8
	adds r4, r5, #0
	adds r4, #0xc
	adds r3, r6, #0
	adds r3, #0xc
	ldrh r0, [r6, #0xc]
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	cmp r0, #0
	blt _081E8E6A
	asrs r0, r0, #5
	b _081E8E70
_081E8E6A:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081E8E70:
	strh r0, [r6, #0x22]
_081E8E72:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e8e7c
FUN_081e8e7c: @ 0x081E8E7C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	mov r8, r1
	mov sb, r2
	adds r6, r3, #0
	adds r5, r7, #0
	adds r5, #0x14
	ldr r2, _081E8F14 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x20
	orrs r0, r3
	ldr r1, _081E8F18 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xa4
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r4, #0
	str r4, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	adds r0, r7, #0
	adds r0, #0xea
	ldrh r1, [r0]
	ldr r2, _081E8F1C @ =0x00002301
	str r4, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r0, _081E8F20 @ =0x00004010
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r5, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0x10
	bl FUN_082364f8
	adds r1, r7, #0
	adds r1, #0x80
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _081E8F24 @ =FUN_081e8d4c
	adds r0, r5, #0
	adds r2, r7, #0
	bl FUN_0823651c
	ldrb r1, [r7, #2]
	adds r0, r7, #0
	adds r0, #0x56
	strb r1, [r0]
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E8F14: .4byte 0xFFFF0000
_081E8F18: .4byte 0x0000FFFF
_081E8F1C: .4byte 0x00002301
_081E8F20: .4byte 0x00004010
_081E8F24: .4byte FUN_081e8d4c

	thumb_func_start FUN_081e8f28
FUN_081e8f28: @ 0x081E8F28
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e8f2c
FUN_081e8f2c: @ 0x081E8F2C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5]
	lsrs r0, r0, #3
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _081E8F7A
	ldr r0, [r5, #0x64]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x64]
	adds r1, r5, #0
	adds r1, #0xee
	movs r0, #3
	strh r0, [r1]
	ldrb r1, [r5]
	movs r0, #7
	ands r0, r1
	strb r0, [r5]
	ldrb r0, [r5, #2]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081e978c
	adds r0, r5, #0
	adds r0, #0xbc
	ldr r1, [r6, #0x18]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #2
	bl FUN_08237040
_081E8F7A:
	adds r1, r5, #0
	adds r1, #0xee
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bgt _081E8F94
	ldr r0, [r5, #0x64]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x64]
	b _081E8F98
_081E8F94:
	subs r0, r2, #1
	strh r0, [r1]
_081E8F98:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e8fa0
FUN_081e8fa0: @ 0x081E8FA0
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r3, #0x90
	ldr r1, [r3]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r3]
	adds r5, r3, #0
	adds r4, r0, #0
	adds r4, #0xcc
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
	beq _081E8FE2
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081E8FEA
_081E8FE2:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E8FEA:
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
	beq _081E900E
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081E9016
_081E900E:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E9016:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081E904C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081E9084
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E9050
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081E9046
	ldrb r0, [r4, #5]
_081E9046:
	subs r0, #1
	strh r0, [r4, #8]
	b _081E9060
	.align 2, 0
_081E904C: .4byte 0x0000FFFF
_081E9050:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081E9060
	strh r1, [r4, #8]
_081E9060:
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
	bne _081E9084
	movs r0, #1
	strb r0, [r4, #7]
_081E9084:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e908c
FUN_081e908c: @ 0x081E908C
	adds r0, #0xf0
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e9094
FUN_081e9094: @ 0x081E9094
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	ldr r0, _081E9110 @ =0x030001B4
	ldr r7, [r0]
	cmp r7, #0
	bne _081E90A8
	b _081E91C6
_081E90A8:
	mov r0, r8
	cmp r0, #0
	bne _081E90B0
	b _081E91C6
_081E90B0:
	mov r4, r8
	adds r4, #0x90
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	mov r1, r8
	ldrb r0, [r1, #2]
	mov r5, sp
	adds r5, #5
	add r1, sp, #4
	adds r2, r5, #0
	bl FUN_081e978c
	mov r6, r8
	adds r6, #0xcc
	ldr r1, [r7, #0x18]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r5]
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #1
	bl FUN_08237040
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r4, #0x10]
	ldrb r0, [r6, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E9114
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _081E911C
	.align 2, 0
_081E9110: .4byte 0x030001B4
_081E9114:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E911C:
	str r0, [r4]
	ldrb r0, [r6, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E9140
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _081E9148
_081E9140:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E9148:
	str r0, [r4]
	ldrh r0, [r6, #0xe]
	adds r0, #1
	strh r0, [r6, #0xe]
	ldr r1, _081E9180 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r6, #7]
	cmp r0, r1
	blo _081E91B8
	movs r0, #0
	strh r0, [r6, #0xe]
	ldrb r1, [r6, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E9184
	ldrh r0, [r6, #8]
	cmp r0, #0
	bne _081E9178
	ldrb r0, [r6, #5]
_081E9178:
	subs r0, #1
	strh r0, [r6, #8]
	b _081E9194
	.align 2, 0
_081E9180: .4byte 0x0000FFFF
_081E9184:
	ldrh r0, [r6, #8]
	adds r0, #1
	strh r0, [r6, #8]
	ands r0, r2
	ldrb r2, [r6, #5]
	cmp r0, r2
	blo _081E9194
	strh r1, [r6, #8]
_081E9194:
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _081E91B8
	movs r0, #1
	strb r0, [r6, #7]
_081E91B8:
	mov r0, r8
	adds r0, #0xe8
	movs r1, #0
	strh r1, [r0]
	movs r0, #2
	mov r1, r8
	strb r0, [r1]
_081E91C6:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e91d4
FUN_081e91d4: @ 0x081E91D4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _081E91F8 @ =0x030001B4
	ldr r6, [r0]
	cmp r6, #0
	beq _081E91F2
	cmp r5, #0
	beq _081E91F2
	adds r0, r5, #0
	adds r0, #0xe4
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r7, r0, #0
	cmp r1, #0
	bge _081E91FC
_081E91F2:
	movs r0, #0
	b _081E924C
	.align 2, 0
_081E91F8: .4byte 0x030001B4
_081E91FC:
	movs r0, #0
	ldrsb r0, [r7, r0]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081E9210
	movs r0, #1
	b _081E9212
_081E9210:
	movs r0, #0
_081E9212:
	cmp r0, #0
	beq _081E924A
	ldrb r4, [r5]
	cmp r4, #1
	bne _081E924A
	adds r0, r5, #0
	adds r0, #0x64
	bl FUN_0822a4e0
	adds r0, r5, #0
	adds r0, #0x90
	bl FUN_0822a4e0
	movs r0, #0
	ldrsb r0, [r7, r0]
	lsls r4, r0
	ldr r0, [r6, #0x38]
	bics r0, r4
	str r0, [r6, #0x38]
	movs r0, #0xff
	strb r0, [r7]
	adds r1, r5, #0
	adds r1, #0xe8
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r5]
	b _081E924C
_081E924A:
	adds r0, r5, #0
_081E924C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e9254
FUN_081e9254: @ 0x081E9254
	push {r4, r5, r6, r7, lr}
	ldr r0, _081E9278 @ =0x030001B4
	ldr r6, [r0]
	cmp r6, #0
	beq _081E92C4
	ldr r0, [r6, #0x38]
	cmp r0, #0
	beq _081E92C4
	movs r7, #0
_081E9266:
	movs r1, #1
	lsls r1, r7
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081E927C
	movs r0, #1
	b _081E927E
	.align 2, 0
_081E9278: .4byte 0x030001B4
_081E927C:
	movs r0, #0
_081E927E:
	cmp r0, #0
	beq _081E92BE
	movs r0, #0xf4
	muls r0, r7, r0
	adds r0, #0x3c
	adds r5, r6, r0
	ldrb r4, [r5]
	cmp r4, #1
	bne _081E92BE
	adds r0, r5, #0
	adds r0, #0x64
	bl FUN_0822a4e0
	adds r0, r5, #0
	adds r0, #0x90
	bl FUN_0822a4e0
	adds r1, r5, #0
	adds r1, #0xe4
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r4, r0
	ldr r0, [r6, #0x38]
	bics r0, r4
	str r0, [r6, #0x38]
	movs r0, #0xff
	strb r0, [r1]
	adds r1, #4
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r5]
_081E92BE:
	adds r7, #1
	cmp r7, #0xb
	ble _081E9266
_081E92C4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e92cc
FUN_081e92cc: @ 0x081E92CC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, _081E9380 @ =0x030001B4
	ldr r0, [r0]
	mov sb, r0
	adds r5, r6, #0
	adds r5, #0xbc
	adds r7, r6, #0
	adds r7, #0x64
	ldr r0, [r6, #0x64]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x64]
	adds r0, r6, #0
	adds r0, #0xee
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _081E932A
	ldrh r1, [r6, #0xc]
	ldrh r2, [r6, #4]
	adds r1, r1, r2
	strh r1, [r6, #4]
	ldrh r0, [r6, #0xe]
	ldrh r3, [r6, #6]
	adds r0, r0, r3
	strh r0, [r6, #6]
	ldrh r0, [r6, #0x10]
	ldrh r2, [r6, #8]
	adds r0, r0, r2
	strh r0, [r6, #8]
	adds r0, r6, #0
	adds r0, #0x80
	strh r1, [r0]
	ldrh r0, [r6, #6]
	adds r1, r6, #0
	adds r1, #0x82
	strh r0, [r1]
	ldrh r1, [r6, #8]
	adds r0, r6, #0
	adds r0, #0x84
	strh r1, [r0]
_081E932A:
	adds r0, r6, #0
	bl FUN_081e97cc
	ldrb r0, [r6, #2]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081e978c
	mov r3, sb
	ldr r1, [r3, #0x18]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r4]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #2
	bl FUN_08236fac
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r5, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E9384
	ldr r0, [r6, #0x64]
	movs r1, #4
	orrs r0, r1
	b _081E938C
	.align 2, 0
_081E9380: .4byte 0x030001B4
_081E9384:
	ldr r0, [r6, #0x64]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E938C:
	str r0, [r6, #0x64]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E93B0
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081E93B8
_081E93B0:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E93B8:
	str r0, [r7]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _081E93F0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r5, #7]
	cmp r0, r3
	blo _081E9428
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E93F4
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _081E93E8
	ldrb r0, [r5, #5]
_081E93E8:
	subs r0, #1
	strh r0, [r5, #8]
	b _081E9404
	.align 2, 0
_081E93F0: .4byte 0x0000FFFF
_081E93F4:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _081E9404
	strh r1, [r5, #8]
_081E9404:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E9428
	movs r0, #1
	strb r0, [r5, #7]
_081E9428:
	adds r0, r6, #0
	adds r0, #0xe8
	movs r3, #0
	ldrsh r1, [r0, r3]
	mov r8, r0
	cmp r1, #1
	bne _081E9438
	b _081E953E
_081E9438:
	adds r7, r6, #0
	adds r7, #0x90
	adds r4, r6, #0
	adds r4, #0xcc
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov ip, r7
	cmp r1, r0
	beq _081E9474
	mov r1, ip
	ldr r0, [r1]
	movs r1, #4
	orrs r0, r1
	mov r2, ip
	str r0, [r2]
	b _081E9480
_081E9474:
	mov r3, ip
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_081E9480:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E94A2
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081E94AA
_081E94A2:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E94AA:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081E94E4 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081E952A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E94EE
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081E94E8
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081E9504
	.align 2, 0
_081E94E4: .4byte 0x0000FFFF
_081E94E8:
	subs r0, #1
	strh r0, [r4, #8]
	b _081E9502
_081E94EE:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081E9502
	strh r1, [r4, #8]
	movs r2, #1
	b _081E9504
_081E9502:
	movs r2, #0
_081E9504:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _081E952C
	movs r0, #1
	strb r0, [r4, #7]
	b _081E952C
_081E952A:
	movs r2, #0
_081E952C:
	cmp r2, #0
	beq _081E953E
	mov r3, ip
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	mov r0, r8
	strh r1, [r0]
_081E953E:
	adds r5, r6, #0
	adds r5, #0xec
	ldrh r0, [r5]
	cmp r0, #0
	beq _081E955E
	adds r4, r6, #0
	adds r4, #0x14
	adds r1, r6, #0
	adds r1, #0xdc
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_081E955E:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	adds r0, r6, #0
	bl FUN_081e9d04
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E9596
	adds r1, r6, #0
	adds r1, #0xf0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _081E9582
	subs r0, r2, #1
	b _081E958C
_081E9582:
	movs r0, #3
	strb r0, [r6]
	adds r1, r6, #0
	adds r1, #0xe6
	movs r0, #1
_081E958C:
	strh r0, [r1]
	mov r0, sb
	adds r1, r6, #0
	bl FUN_081e8f2c
_081E9596:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e95a4
FUN_081e95a4: @ 0x081E95A4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _081E9648 @ =0x030001B4
	ldr r0, [r0]
	mov r8, r0
	adds r6, r5, #0
	adds r6, #0xe6
	ldrh r0, [r6]
	cmp r0, #0
	beq _081E95F0
	ldrb r0, [r5, #2]
	mov r2, sp
	adds r2, #5
	add r1, sp, #4
	bl FUN_081e978c
	adds r0, r5, #0
	adds r0, #0xbc
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r4, #0
	str r4, [sp]
	movs r2, #3
	movs r3, #0
	bl FUN_08236fac
	adds r2, r5, #0
	adds r2, #0x80
	adds r0, r5, #0
	adds r0, #0xdc
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	strh r4, [r6]
_081E95F0:
	adds r1, r5, #0
	adds r1, #0x80
	ldrh r0, [r5, #0xc]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r5, #0xe]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r5, #0x10]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r7, r5, #0
	adds r7, #0x64
	adds r4, r5, #0
	adds r4, #0xbc
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov ip, r7
	cmp r1, r0
	beq _081E964C
	ldr r0, [r5, #0x64]
	movs r1, #4
	orrs r0, r1
	b _081E9654
	.align 2, 0
_081E9648: .4byte 0x030001B4
_081E964C:
	ldr r0, [r5, #0x64]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E9654:
	str r0, [r5, #0x64]
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
	beq _081E9678
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081E9680
_081E9678:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E9680:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081E96B8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081E96FE
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E96C2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081E96BC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081E96D8
	.align 2, 0
_081E96B8: .4byte 0x0000FFFF
_081E96BC:
	subs r0, #1
	strh r0, [r4, #8]
	b _081E96D6
_081E96C2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081E96D6
	strh r1, [r4, #8]
	movs r2, #1
	b _081E96D8
_081E96D6:
	movs r2, #0
_081E96D8:
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
	bne _081E9700
	movs r0, #1
	strb r0, [r4, #7]
	b _081E9700
_081E96FE:
	movs r2, #0
_081E9700:
	cmp r2, #0
	beq _081E9736
	mov r0, ip
	bl FUN_0822a4e0
	adds r0, r5, #0
	adds r0, #0x90
	bl FUN_0822a4e0
	adds r4, r5, #0
	adds r4, #0xe4
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #1
	lsls r1, r0
	mov r2, r8
	ldr r0, [r2, #0x38]
	bics r0, r1
	str r0, [r2, #0x38]
	adds r0, r5, #0
	movs r1, #0xf4
	bl ClearMemory
	movs r0, #0xff
	strb r0, [r4]
	movs r0, #0
	strb r0, [r5]
_081E9736:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081e9744
FUN_081e9744: @ 0x081E9744
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r2, #0
	movs r5, #1
_081E974C:
	adds r0, r5, #0
	lsls r0, r2
	ldr r1, [r3, #0x38]
	ands r0, r1
	adds r4, r1, #0
	cmp r0, #0
	beq _081E975E
	movs r0, #1
	b _081E9760
_081E975E:
	movs r0, #0
_081E9760:
	cmp r0, #0
	bne _081E977C
	movs r0, #0xf4
	muls r0, r2, r0
	adds r0, #0x3c
	adds r0, r3, r0
	adds r1, r5, #0
	lsls r1, r2
	orrs r1, r4
	str r1, [r3, #0x38]
	adds r1, r0, #0
	adds r1, #0xe4
	strb r2, [r1]
	b _081E9784
_081E977C:
	adds r2, #1
	cmp r2, #0xb
	ble _081E974C
	movs r0, #0
_081E9784:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e978c
FUN_081e978c: @ 0x081E978C
	push {lr}
	adds r3, r0, #0
	asrs r0, r3, #5
	adds r3, r0, #3
	movs r0, #7
	ands r3, r0
	cmp r3, #6
	beq _081E97B4
	cmp r3, #6
	bgt _081E97A6
	cmp r3, #5
	beq _081E97AC
	b _081E97C2
_081E97A6:
	cmp r3, #7
	beq _081E97BC
	b _081E97C2
_081E97AC:
	movs r0, #3
	strb r0, [r1]
	movs r0, #1
	b _081E97C6
_081E97B4:
	movs r0, #2
	strb r0, [r1]
	movs r0, #1
	b _081E97C6
_081E97BC:
	movs r0, #1
	strb r0, [r1]
	b _081E97C6
_081E97C2:
	strb r3, [r1]
	movs r0, #0
_081E97C6:
	strb r0, [r2]
	pop {r0}
	bx r0

	thumb_func_start FUN_081e97cc
FUN_081e97cc: @ 0x081E97CC
	push {lr}
	mov ip, r0
	mov r3, ip
	adds r3, #0xdc
	mov r2, ip
	adds r2, #0x80
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	mov r1, ip
	ldrb r0, [r1, #2]
	lsrs r0, r0, #5
	cmp r0, #7
	bhi _081E98E4
	lsls r0, r0, #2
	ldr r1, _081E97FC @ =_081E9800
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081E97FC: .4byte _081E9800
_081E9800: @ jump table
	.4byte _081E9820 @ case 0
	.4byte _081E983E @ case 1
	.4byte _081E985C @ case 2
	.4byte _081E987A @ case 3
	.4byte _081E9886 @ case 4
	.4byte _081E9892 @ case 5
	.4byte _081E989A @ case 6
	.4byte _081E98B8 @ case 7
_081E9820:
	ldrh r0, [r2]
	adds r0, #0x80
	strh r0, [r3]
	ldrh r0, [r2, #4]
	subs r0, #0x40
	strh r0, [r3, #4]
	ldrh r0, [r2, #2]
	subs r0, #8
	mov r1, ip
	adds r1, #0xae
	strh r0, [r1]
	ldrh r0, [r2, #2]
	adds r0, #0x10
	subs r1, #0x2c
	b _081E98E2
_081E983E:
	ldrh r0, [r2]
	adds r0, #0x80
	strh r0, [r3]
	ldrh r0, [r2, #4]
	adds r0, #0x80
	strh r0, [r3, #4]
	ldrh r0, [r2, #2]
	subs r0, #8
	mov r1, ip
	adds r1, #0xae
	strh r0, [r1]
	ldrh r0, [r2, #2]
	adds r0, #0x10
	subs r1, #0x2c
	b _081E98E2
_081E985C:
	ldrh r0, [r2]
	subs r0, #0x20
	strh r0, [r3]
	ldrh r0, [r2, #4]
	adds r0, #0x80
	strh r0, [r3, #4]
	ldrh r0, [r2, #2]
	subs r0, #8
	mov r1, ip
	adds r1, #0xae
	strh r0, [r1]
	ldrh r0, [r2, #2]
	adds r0, #0x10
	subs r1, #0x2c
	b _081E98E2
_081E987A:
	ldrh r0, [r2]
	subs r0, #0x60
	strh r0, [r3]
	ldrh r0, [r2, #4]
	adds r0, #0x20
	b _081E98C8
_081E9886:
	ldrh r0, [r2]
	subs r0, #0x80
	strh r0, [r3]
	ldrh r0, [r2, #4]
	subs r0, #0x20
	b _081E98C8
_081E9892:
	ldrh r0, [r2]
	subs r0, #0x40
	strh r0, [r3]
	b _081E98C4
_081E989A:
	ldrh r0, [r2]
	subs r0, #0x20
	strh r0, [r3]
	ldrh r0, [r2, #4]
	subs r0, #0x80
	strh r0, [r3, #4]
	ldrh r0, [r2, #2]
	adds r0, #0x10
	mov r1, ip
	adds r1, #0xae
	strh r0, [r1]
	ldrh r0, [r2, #2]
	subs r0, #8
	subs r1, #0x2c
	b _081E98E2
_081E98B8:
	ldrh r0, [r2]
	adds r0, #0x80
	strh r0, [r3]
	ldrh r0, [r2, #2]
	adds r0, #0x40
	strh r0, [r3, #2]
_081E98C4:
	ldrh r0, [r2, #4]
	subs r0, #0x60
_081E98C8:
	strh r0, [r3, #4]
	ldrh r0, [r2, #2]
	adds r0, #0x10
	mov r1, ip
	adds r1, #0xae
	strh r0, [r1]
	ldrh r0, [r2, #2]
	subs r0, #8
	subs r1, #0x2c
	strh r0, [r1]
	ldrh r0, [r2, #4]
	subs r0, #0x10
	adds r1, #2
_081E98E2:
	strh r0, [r1]
_081E98E4:
	pop {r0}
	bx r0

	thumb_func_start FUN_081e98e8
FUN_081e98e8: @ 0x081E98E8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r7, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	add r3, sp, #0x14
	ldr r2, _081E9914 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081E9918
	asrs r1, r0, #0xc
	b _081E991E
	.align 2, 0
_081E9914: .4byte 0x085B0A08
_081E9918:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081E991E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081E993A
	asrs r0, r0, #0xc
	b _081E9940
_081E993A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081E9940:
	strh r0, [r3, #4]
	ldr r0, _081E9968 @ =0x00000309
	str r0, [sp]
	ldr r0, [sp, #0x30]
	str r0, [sp, #4]
	ldr r0, [sp, #0x34]
	str r0, [sp, #8]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0xc]
	str r6, [sp, #0x10]
	adds r0, r7, #0
	movs r1, #0
	add r2, sp, #0x14
	adds r3, r4, #0
	bl FUN_081e996c
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081E9968: .4byte 0x00000309

	thumb_func_start FUN_081e996c
FUN_081e996c: @ 0x081E996C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp, #8]
	mov r8, r1
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r0, _081E9998 @ =0x030001B4
	ldr r0, [r0]
	cmp r0, #0
	bne _081E999C
	bl FUN_081e9cac
	mov sb, r0
	cmp r0, #0
	bne _081E999E
_081E9992:
	movs r0, #0
	b _081E9B7C
	.align 2, 0
_081E9998: .4byte 0x030001B4
_081E999C:
	mov sb, r0
_081E999E:
	mov r0, sb
	bl FUN_081e9744
	adds r6, r0, #0
	cmp r6, #0
	beq _081E9992
	adds r7, r6, #0
	adds r7, #0x64
	adds r5, r6, #0
	adds r5, #0x90
	mov r4, sb
	adds r4, #0x1c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	ldr r0, [r6, #0x64]
	movs r1, #1
	mov sl, r1
	orrs r0, r1
	str r0, [r6, #0x64]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	adds r1, r6, #0
	adds r1, #0xec
	movs r0, #0
	strh r0, [r1]
	ldr r2, [sp, #8]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	mov r0, r8
	cmp r0, #0
	beq _081E9A0C
	ldrh r0, [r0]
	ldrh r1, [r7, #0x1c]
	adds r0, r0, r1
	strh r0, [r7, #0x1c]
	mov r2, r8
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #0x1e]
	adds r0, r0, r1
	strh r0, [r7, #0x1e]
	ldrh r0, [r2, #4]
	ldrh r2, [r7, #0x20]
	adds r0, r0, r2
	strh r0, [r7, #0x20]
_081E9A0C:
	ldr r2, [sp, #0xc]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0xc]
	str r1, [r6, #0x10]
	movs r0, #0xff
	strb r0, [r6, #1]
	mov r0, sp
	ldrb r0, [r0, #0x10]
	strb r0, [r6, #2]
	adds r1, r6, #0
	adds r1, #0xea
	ldr r0, [sp, #0x34]
	strh r0, [r1]
	adds r1, #6
	ldr r0, [sp, #0x44]
	strh r0, [r1]
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [r6, #4]
	str r1, [r6, #8]
	adds r2, r6, #0
	adds r2, #0xac
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r5]
	mov r1, sl
	orrs r0, r1
	str r0, [r5]
	ldrb r0, [r6, #2]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081e978c
	adds r5, r6, #0
	adds r5, #0xbc
	mov r2, sb
	ldr r1, [r2, #0x18]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r4]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #2
	bl FUN_08236fac
	adds r0, r6, #0
	adds r0, #0xcc
	mov r2, sb
	ldr r1, [r2, #0x18]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #0
	bl FUN_08237040
	mov r8, r7
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r5, #4]
	mov r1, sl
	ands r1, r0
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sl
	ands r0, r2
	cmp r1, r0
	beq _081E9AB4
	ldr r0, [r6, #0x64]
	movs r1, #4
	orrs r0, r1
	b _081E9ABC
_081E9AB4:
	ldr r0, [r6, #0x64]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E9ABC:
	str r0, [r6, #0x64]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E9AE2
	mov r1, r8
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081E9AEC
_081E9AE2:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E9AEC:
	mov r2, r8
	str r0, [r2]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _081E9B24 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _081E9B5C
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E9B28
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _081E9B1E
	ldrb r0, [r5, #5]
_081E9B1E:
	subs r0, #1
	strh r0, [r5, #8]
	b _081E9B38
	.align 2, 0
_081E9B24: .4byte 0x0000FFFF
_081E9B28:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _081E9B38
	strh r1, [r5, #8]
_081E9B38:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E9B5C
	movs r0, #1
	strb r0, [r5, #7]
_081E9B5C:
	adds r0, r6, #0
	ldr r1, [sp, #0x38]
	ldr r2, [sp, #0x3c]
	ldr r3, [sp, #0x40]
	bl FUN_081e8e7c
	adds r0, r6, #0
	bl FUN_081e97cc
	movs r0, #1
	strb r0, [r6]
	strb r0, [r7, #7]
	adds r1, r6, #0
	adds r1, #0x97
	strb r0, [r1]
	adds r0, r6, #0
_081E9B7C:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e9b8c
FUN_081e9b8c: @ 0x081E9B8C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	mov r2, sp
	ldr r1, _081E9BC8 @ =0x082523E8
	ldm r1!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldr r1, [r1]
	str r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	ldr r1, _081E9BCC @ =0x030047A4
	ldr r2, _081E9BD0 @ =0x030047A0
	ldr r1, [r1]
	ldr r2, [r2]
	orrs r1, r2
	ands r1, r3
	cmp r1, #0
	bne _081E9BC4
	movs r2, #4
	ldr r1, _081E9BD4 @ =0x03002BC0
	ldr r1, [r1]
	ands r1, r2
	cmp r1, #0
	bne _081E9BC4
	ldr r1, [r6, #0x38]
	cmp r1, #0
	bne _081E9BD8
_081E9BC4:
	movs r0, #0
	b _081E9C1C
	.align 2, 0
_081E9BC8: .4byte 0x082523E8
_081E9BCC: .4byte 0x030047A4
_081E9BD0: .4byte 0x030047A0
_081E9BD4: .4byte 0x03002BC0
_081E9BD8:
	movs r5, #0
_081E9BDA:
	movs r2, #1
	lsls r2, r5
	ldr r1, [r6, #0x38]
	ands r1, r2
	cmp r1, #0
	beq _081E9BEA
	movs r1, #1
	b _081E9BEC
_081E9BEA:
	movs r1, #0
_081E9BEC:
	cmp r1, #0
	beq _081E9C16
	movs r0, #0xf4
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x3c
	adds r4, r6, r4
	ldrb r1, [r4]
	movs r0, #7
	ands r0, r1
	lsls r0, r0, #2
	add r0, sp
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrh r1, [r4, #0x1a]
	ldr r3, _081E9C24 @ =0x0000FFFB
	adds r2, r3, #0
	ands r1, r2
	strh r1, [r4, #0x1a]
_081E9C16:
	adds r5, #1
	cmp r5, #0xb
	ble _081E9BDA
_081E9C1C:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081E9C24: .4byte 0x0000FFFB

	thumb_func_start FUN_081e9c28
FUN_081e9c28: @ 0x081E9C28
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
_081E9C2E:
	movs r2, #1
	lsls r2, r5
	ldr r1, [r6, #0x38]
	ands r1, r2
	cmp r1, #0
	beq _081E9C3E
	movs r1, #1
	b _081E9C40
_081E9C3E:
	movs r1, #0
_081E9C40:
	cmp r1, #0
	beq _081E9C5E
	movs r0, #0xf4
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x3c
	adds r4, r6, r4
	adds r0, r4, #0
	adds r0, #0x64
	bl FUN_0822a4e0
	adds r4, #0x90
	adds r0, r4, #0
	bl FUN_0822a4e0
_081E9C5E:
	adds r5, #1
	cmp r5, #0xb
	ble _081E9C2E
	ldr r2, _081E9C70 @ =0x030001B4
	movs r1, #0
	str r1, [r2]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081E9C70: .4byte 0x030001B4

	thumb_func_start FUN_081e9c74
FUN_081e9c74: @ 0x081E9C74
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x1c
	ldr r1, _081E9C9C @ =0x00002D41
	bl Video_GetAuxSprite
	ldr r0, _081E9CA0 @ =0x0000922E
	ldr r1, _081E9CA4 @ =0x0000D6C8
	bl GetFile
	adds r1, r0, #0
	str r1, [r4, #0x18]
	ldr r1, _081E9CA8 @ =0x030001B4
	str r4, [r1]
	movs r1, #0
	str r1, [r4, #0x38]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081E9C9C: .4byte 0x00002D41
_081E9CA0: .4byte 0x0000922E
_081E9CA4: .4byte 0x0000D6C8
_081E9CA8: .4byte 0x030001B4

	thumb_func_start FUN_081e9cac
FUN_081e9cac: @ 0x081E9CAC
	push {r4, lr}
	ldr r0, _081E9CE0 @ =0x030001B4
	ldr r0, [r0]
	cmp r0, #0
	bne _081E9CF2
	ldr r1, _081E9CE4 @ =0x00000BAC
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081E9CF0
	ldr r1, _081E9CE8 @ =FUN_081e9b8c
	ldr r2, _081E9CEC @ =FUN_081e9c28
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081e9c74
	cmp r0, #0
	bge _081E9CF0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081E9CF2
	.align 2, 0
_081E9CE0: .4byte 0x030001B4
_081E9CE4: .4byte 0x00000BAC
_081E9CE8: .4byte FUN_081e9b8c
_081E9CEC: .4byte FUN_081e9c28
_081E9CF0:
	adds r0, r4, #0
_081E9CF2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081e9cf8
FUN_081e9cf8: @ 0x081E9CF8
	ldr r1, _081E9D00 @ =0x030001B4
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081E9D00: .4byte 0x030001B4

	thumb_func_start FUN_081e9d04
FUN_081e9d04: @ 0x081E9D04
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r0, #0xe8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq _081E9D1C
	adds r0, r6, #0
	adds r0, #0xec
	ldrh r0, [r0]
	cmp r0, #4
	bls _081E9DAC
_081E9D1C:
	adds r0, r6, #0
	adds r0, #0x82
	movs r1, #0
	ldrsh r7, [r0, r1]
	adds r5, r6, #0
	adds r5, #0xdc
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081E9D4C
	cmp r1, #0
	blt _081E9D4C
	ldr r0, _081E9D50 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081E9D4C
	ldr r0, _081E9D54 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081E9D58
_081E9D4C:
	movs r4, #0
	b _081E9D66
	.align 2, 0
_081E9D50: .4byte 0x030046A8
_081E9D54: .4byte 0x030046AC
_081E9D58:
	ldr r0, _081E9D78 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081E9D66:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081E9D7C
	adds r0, #4
	b _081E9D88
	.align 2, 0
_081E9D78: .4byte 0x030046A4
_081E9D7C:
	ldr r0, _081E9D9C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081E9D88:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081E9DA0
	cmp r2, #2
	beq _081E9DA4
	b _081E9DA8
	.align 2, 0
_081E9D9C: .4byte 0x030046A4
_081E9DA0:
	ldrb r0, [r5, #4]
	b _081E9DA6
_081E9DA4:
	ldrb r0, [r5]
_081E9DA6:
	subs r1, r1, r0
_081E9DA8:
	cmp r7, r1
	blo _081E9DB0
_081E9DAC:
	movs r0, #0
	b _081E9DBC
_081E9DB0:
	movs r0, #3
	strb r0, [r6]
	adds r1, r6, #0
	adds r1, #0xe6
	movs r0, #1
	strh r0, [r1]
_081E9DBC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e9dc4
FUN_081e9dc4: @ 0x081E9DC4
	bx lr
	.align 2, 0

	thumb_func_start FUN_081e9dc8
FUN_081e9dc8: @ 0x081E9DC8
	push {r4, r5, r6, r7, lr}
	mov ip, r1
	movs r2, #0xb
	ldrsb r2, [r1, r2]
	movs r1, #0x2c
	muls r1, r2, r1
	adds r1, #0x1c
	adds r6, r0, r1
	mov r3, ip
	ldr r1, [r3]
	ldr r2, [r3, #4]
	str r1, [r6, #0x1c]
	str r2, [r6, #0x20]
	ldr r5, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r5, r1
	str r5, [r6]
	movs r1, #0xb
	ldrsb r1, [r3, r1]
	lsls r1, r1, #4
	adds r4, r1, r0
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r4, r4, r0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E9E24
	movs r0, #4
	orrs r5, r0
	b _081E9E2A
_081E9E24:
	movs r0, #5
	rsbs r0, r0, #0
	ands r5, r0
_081E9E2A:
	str r5, [r6]
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
	beq _081E9E4E
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081E9E56
_081E9E4E:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E9E56:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081E9E90 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081E9ED6
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E9E9A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081E9E94
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081E9EB0
	.align 2, 0
_081E9E90: .4byte 0x0000FFFF
_081E9E94:
	subs r0, #1
	strh r0, [r4, #8]
	b _081E9EAE
_081E9E9A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081E9EAE
	strh r1, [r4, #8]
	movs r2, #1
	b _081E9EB0
_081E9EAE:
	movs r2, #0
_081E9EB0:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
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
	bne _081E9ED8
	movs r0, #1
	strb r0, [r4, #7]
	b _081E9ED8
_081E9ED6:
	movs r2, #0
_081E9ED8:
	cmp r2, #0
	beq _081E9EE2
	movs r0, #2
	mov r3, ip
	strb r0, [r3, #0xa]
_081E9EE2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e9ee8
FUN_081e9ee8: @ 0x081E9EE8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0xb
	ldrsb r1, [r5, r1]
	movs r0, #0x2c
	muls r0, r1, r0
	adds r0, #0x1c
	adds r0, r4, r0
	bl FUN_0822a4e0
	movs r0, #0
	strb r0, [r5, #0xa]
	movs r0, #0xb
	ldrsb r0, [r5, r0]
	movs r1, #0x86
	lsls r1, r1, #2
	adds r4, r4, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r4]
	bics r0, r1
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0xc
	bl ClearMemory
	movs r0, #0xff
	strb r0, [r5, #0xb]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081e9f28
FUN_081e9f28: @ 0x081E9F28
	push {r4, r5, lr}
	adds r2, r0, #0
	movs r3, #0
	movs r0, #0x86
	lsls r0, r0, #2
	adds r4, r2, r0
	movs r5, #1
	mov ip, r3
_081E9F38:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E9F48
	movs r0, #1
	b _081E9F4A
_081E9F48:
	movs r0, #0
_081E9F4A:
	cmp r0, #0
	bne _081E9F64
	movs r0, #0x87
	lsls r0, r0, #2
	add r0, ip
	adds r0, r2, r0
	strb r3, [r0, #0xb]
	adds r2, r5, #0
	lsls r2, r3
	ldr r1, [r4]
	orrs r1, r2
	str r1, [r4]
	b _081E9F70
_081E9F64:
	movs r0, #0xc
	add ip, r0
	adds r3, #1
	cmp r3, #7
	ble _081E9F38
	movs r0, #0
_081E9F70:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081e9f78
FUN_081e9f78: @ 0x081E9F78
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	mov r8, r1
	str r2, [sp, #4]
	cmp r0, #0
	beq _081E9F96
	ldr r0, _081E9F9C @ =0x030001B8
	ldr r6, [r0]
	cmp r6, #0
	bne _081E9FA0
_081E9F96:
	movs r0, #1
	rsbs r0, r0, #0
	b _081EA01E
	.align 2, 0
_081E9F9C: .4byte 0x030001B8
_081E9FA0:
	movs r7, #0
	cmp r7, r8
	bge _081EA01C
	movs r0, #1
	mov sl, r0
	lsls r3, r3, #0x10
	str r3, [sp, #8]
_081E9FAE:
	adds r0, r6, #0
	bl FUN_081e9f28
	adds r5, r0, #0
	cmp r5, #0
	beq _081E9F96
	movs r1, #0xb
	ldrsb r1, [r5, r1]
	movs r0, #0x2c
	adds r4, r1, #0
	muls r4, r0, r4
	adds r4, #0x1c
	adds r4, r6, r4
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5]
	str r1, [r5, #4]
	adds r0, r4, #0
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r2, #0
	bl FUN_0822a470
	movs r0, #0xb
	ldrsb r0, [r5, r0]
	lsls r0, r0, #4
	movs r1, #0xcc
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r6, r0
	ldr r1, [r6, #0x18]
	movs r2, #0
	str r2, [sp]
	ldr r3, [sp, #8]
	lsrs r2, r3, #0x10
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [r4, #0xc]
	ldr r1, [sp, #0x2c]
	bl Video_SetAuxSpritePltt
	ldr r0, [r4]
	mov r1, sl
	orrs r0, r1
	str r0, [r4]
	mov r2, sp
	ldrb r2, [r2, #4]
	strb r2, [r4, #7]
	strb r1, [r5, #0xa]
	adds r7, #1
	cmp r7, r8
	blt _081E9FAE
_081EA01C:
	movs r0, #0
_081EA01E:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081ea030
FUN_081ea030: @ 0x081EA030
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r1, #0x86
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081EA08A
	movs r5, #0
	movs r0, #0x86
	lsls r0, r0, #2
	adds r7, r6, r0
	movs r1, #0x87
	lsls r1, r1, #2
	adds r4, r6, r1
	ldr r0, _081EA068 @ =0x085AE45C
	mov r8, r0
_081EA056:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081EA06C
	movs r0, #1
	b _081EA06E
	.align 2, 0
_081EA068: .4byte 0x085AE45C
_081EA06C:
	movs r0, #0
_081EA06E:
	cmp r0, #0
	beq _081EA082
	ldrb r0, [r4, #0xa]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
_081EA082:
	adds r4, #0xc
	adds r5, #1
	cmp r5, #7
	ble _081EA056
_081EA08A:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081ea098
FUN_081ea098: @ 0x081EA098
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r5, #0
	movs r0, #0x86
	lsls r0, r0, #2
	adds r7, r6, r0
	adds r0, #4
	adds r4, r6, r0
_081EA0A8:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081EA0B8
	movs r0, #1
	b _081EA0BA
_081EA0B8:
	movs r0, #0
_081EA0BA:
	cmp r0, #0
	beq _081EA0CE
	movs r1, #0xb
	ldrsb r1, [r4, r1]
	movs r0, #0x2c
	muls r0, r1, r0
	adds r0, #0x1c
	adds r0, r6, r0
	bl FUN_0822a4e0
_081EA0CE:
	adds r4, #0xc
	adds r5, #1
	cmp r5, #7
	ble _081EA0A8
	movs r1, #0
	ldr r0, _081EA0E4 @ =0x030001B8
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EA0E4: .4byte 0x030001B8

	thumb_func_start FUN_081ea0e8
FUN_081ea0e8: @ 0x081EA0E8
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, _081EA108 @ =0x0000863A
	bl Video_GetAuxSprite
	ldr r0, _081EA10C @ =0x0000922E
	ldr r1, _081EA110 @ =0x0000931E
	bl GetFile
	str r0, [r4, #0x18]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081EA108: .4byte 0x0000863A
_081EA10C: .4byte 0x0000922E
_081EA110: .4byte 0x0000931E

	thumb_func_start FUN_081ea114
FUN_081ea114: @ 0x081EA114
	push {lr}
	bl FUN_081ea0e8
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_081ea120
FUN_081ea120: @ 0x081EA120
	push {r4, r5, lr}
	ldr r5, _081EA15C @ =0x030001B8
	ldr r0, [r5]
	cmp r0, #0
	bne _081EA16A
	movs r1, #0x9f
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	str r4, [r5]
	cmp r4, #0
	beq _081EA168
	ldr r1, _081EA160 @ =FUN_081ea030
	ldr r2, _081EA164 @ =FUN_081ea098
	bl SetEntityRoutine
	adds r0, r4, #0
	movs r1, #0
	bl FUN_081ea114
	cmp r0, #0
	bge _081EA168
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081EA16A
	.align 2, 0
_081EA15C: .4byte 0x030001B8
_081EA160: .4byte FUN_081ea030
_081EA164: .4byte FUN_081ea098
_081EA168:
	adds r0, r4, #0
_081EA16A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ea170
FUN_081ea170: @ 0x081EA170
	ldr r1, _081EA178 @ =0x030001B8
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081EA178: .4byte 0x030001B8

	thumb_func_start FUN_081ea17c
FUN_081ea17c: @ 0x081EA17C
	bx lr
	.align 2, 0

	thumb_func_start FUN_081ea180
FUN_081ea180: @ 0x081EA180
	bx lr
	.align 2, 0

	thumb_func_start FUN_081ea184
FUN_081ea184: @ 0x081EA184
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	mov r8, r1
	mov sb, r2
	adds r6, r3, #0
	ldr r7, [sp, #0x38]
	ldr r2, _081EA210 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x10
	orrs r0, r3
	ldr r1, _081EA214 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r5, #0
	adds r4, #0x3c
	ldr r2, _081EA218 @ =0x00002001
	str r3, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0
	bl FUN_082364f8
	adds r1, r5, #0
	adds r1, #0x2c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _081EA21C @ =FUN_081ea180
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081EA210: .4byte 0xFFFF0000
_081EA214: .4byte 0x0000FFFF
_081EA218: .4byte 0x00002001
_081EA21C: .4byte FUN_081ea180

	thumb_func_start FUN_081ea220
FUN_081ea220: @ 0x081EA220
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r2, #0
	movs r5, #1
_081EA228:
	adds r0, r5, #0
	lsls r0, r2
	ldr r1, [r3, #0x34]
	ands r0, r1
	adds r4, r1, #0
	cmp r0, #0
	beq _081EA23A
	movs r0, #1
	b _081EA23C
_081EA23A:
	movs r0, #0
_081EA23C:
	cmp r0, #0
	bne _081EA258
	movs r0, #0xd4
	muls r0, r2, r0
	adds r0, #0x38
	adds r0, r3, r0
	adds r1, r5, #0
	lsls r1, r2
	orrs r1, r4
	str r1, [r3, #0x34]
	adds r1, r0, #0
	adds r1, #0xd3
	strb r2, [r1]
	b _081EA260
_081EA258:
	adds r2, #1
	cmp r2, #7
	ble _081EA228
	movs r0, #0
_081EA260:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081ea268
FUN_081ea268: @ 0x081EA268
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	adds r7, r1, #0
	mov sb, r7
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	ldrh r0, [r7, #0x34]
	ldrh r1, [r7, #0x2c]
	adds r0, r0, r1
	strh r0, [r7, #0x2c]
	ldrh r1, [r7, #0x36]
	ldrh r2, [r7, #0x2e]
	adds r0, r1, r2
	strh r0, [r7, #0x2e]
	ldrh r0, [r7, #0x38]
	ldrh r2, [r7, #0x30]
	adds r0, r0, r2
	strh r0, [r7, #0x30]
	subs r1, #1
	strh r1, [r7, #0x36]
	movs r0, #0x1e
	ldrsh r6, [r7, r0]
	adds r5, r7, #0
	adds r5, #0x1c
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081EA2D4
	cmp r1, #0
	blt _081EA2D4
	ldr r0, _081EA2D8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081EA2D4
	ldr r0, _081EA2DC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081EA2E0
_081EA2D4:
	movs r4, #0
	b _081EA2EE
	.align 2, 0
_081EA2D8: .4byte 0x030046A8
_081EA2DC: .4byte 0x030046AC
_081EA2E0:
	ldr r0, _081EA300 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081EA2EE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081EA304
	adds r0, #4
	b _081EA310
	.align 2, 0
_081EA300: .4byte 0x030046A4
_081EA304:
	ldr r0, _081EA324 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EA310:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EA328
	cmp r2, #2
	beq _081EA32C
	b _081EA330
	.align 2, 0
_081EA324: .4byte 0x030046A4
_081EA328:
	ldrb r0, [r5, #4]
	b _081EA32E
_081EA32C:
	ldrb r0, [r5]
_081EA32E:
	subs r1, r1, r0
_081EA330:
	cmp r6, r1
	blo _081EA33E
	mov r1, sb
	movs r2, #0x1e
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bgt _081EA424
_081EA33E:
	movs r0, #0xeb
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r5, r7, #0
	adds r5, #0xd3
	movs r0, #0
	ldrsb r0, [r5, r0]
	movs r1, #1
	lsls r1, r0
	mov r2, r8
	ldr r0, [r2, #0x34]
	bics r0, r1
	str r0, [r2, #0x34]
	adds r0, r7, #0
	adds r0, #0xd2
	movs r4, #0
	strb r4, [r0]
	mov r0, sb
	bl FUN_0822a4e0
	adds r0, r7, #0
	adds r0, #0x8c
	bl ParticleShadow_Remove
	movs r0, #0xff
	strb r0, [r5]
	adds r0, r7, #0
	adds r0, #0xd0
	strh r4, [r0]
	subs r0, #4
	str r4, [r0]
	ldr r5, _081EA40C @ =0xFFFF0000
	ldr r4, [sp, #0xc]
	ands r4, r5
	ldr r6, _081EA410 @ =0x0000FFF4
	orrs r4, r6
	str r4, [sp, #0xc]
	ldr r0, _081EA414 @ =0x0203B400
	mov ip, r0
	ldr r1, _081EA418 @ =0x030046B8
	mov sl, r1
	ldr r1, [r1]
	adds r1, #1
	ldr r2, _081EA41C @ =0x000003FF
	mov r8, r2
	ands r1, r2
	lsls r0, r1, #1
	add r0, ip
	ldrh r2, [r0]
	movs r0, #7
	mov sb, r0
	mov r0, sb
	ands r2, r0
	lsls r2, r2, #0x10
	ldr r3, _081EA420 @ =0x0000FFFF
	adds r0, r3, #0
	ands r0, r4
	orrs r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r5
	orrs r0, r6
	str r0, [sp, #0x10]
	ldr r2, [sp, #0x14]
	ands r2, r5
	movs r4, #0x18
	orrs r2, r4
	str r2, [sp, #0x14]
	adds r1, #1
	mov r0, r8
	ands r1, r0
	mov r0, sl
	str r1, [r0]
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	mov r1, sb
	ands r0, r1
	adds r0, #3
	lsls r0, r0, #0x10
	ands r3, r2
	orrs r3, r0
	str r3, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r5
	orrs r0, r4
	str r0, [r1, #4]
	adds r2, r7, #0
	adds r2, #0x2c
	str r1, [sp]
	movs r0, #0x20
	str r0, [sp, #4]
	movs r0, #0x1f
	str r0, [sp, #8]
	movs r0, #6
	movs r1, #3
	add r3, sp, #0xc
	bl FUN_08014730
	b _081EA43A
	.align 2, 0
_081EA40C: .4byte 0xFFFF0000
_081EA410: .4byte 0x0000FFF4
_081EA414: .4byte 0x0203B400
_081EA418: .4byte 0x030046B8
_081EA41C: .4byte 0x000003FF
_081EA420: .4byte 0x0000FFFF
_081EA424:
	adds r4, r7, #0
	adds r4, #0x3c
	adds r1, r7, #0
	adds r1, #0x2c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_081EA43A:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081ea44c
FUN_081ea44c: @ 0x081EA44C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	adds r5, r1, #0
	adds r6, r5, #0
	adds r0, r5, #0
	adds r0, #0xcc
	ldr r0, [r0]
	movs r2, #2
	cmp r0, #0x3c
	bgt _081EA46E
	movs r2, #0
	cmp r0, #0x28
	ble _081EA46E
	movs r2, #1
_081EA46E:
	adds r4, r5, #0
	adds r4, #0xcc
	ldr r0, [r4]
	ldr r1, _081EA498 @ =0x085AE468
	adds r1, r2, r1
	ldrb r1, [r1]
	bl Mod
	adds r7, r4, #0
	cmp r0, #0
	bne _081EA4A0
	ldr r1, [r6]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _081EA49C
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	b _081EA49E
	.align 2, 0
_081EA498: .4byte 0x085AE468
_081EA49C:
	orrs r1, r2
_081EA49E:
	str r1, [r6]
_081EA4A0:
	ldr r0, [r7]
	cmp r0, #0x5a
	ble _081EA4E4
	movs r0, #0xd3
	adds r0, r0, r5
	mov r8, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #1
	lsls r1, r0
	mov r2, sb
	ldr r0, [r2, #0x34]
	bics r0, r1
	str r0, [r2, #0x34]
	adds r0, r5, #0
	adds r0, #0xd2
	movs r4, #0
	strb r4, [r0]
	adds r0, r6, #0
	bl FUN_0822a4e0
	adds r0, r5, #0
	adds r0, #0x8c
	bl ParticleShadow_Remove
	movs r0, #0xff
	mov r1, r8
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0xd0
	strh r4, [r0]
	str r4, [r7]
	b _081EA4E8
_081EA4E4:
	adds r0, #1
	str r0, [r7]
_081EA4E8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081ea4f4
FUN_081ea4f4: @ 0x081EA4F4
	push {lr}
	adds r3, r1, #0
	ldrb r0, [r0, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	bls _081EA518
	movs r0, #1
	strb r0, [r2]
	movs r0, #3
	subs r0, r0, r1
	strb r0, [r3]
	b _081EA51E
_081EA518:
	movs r0, #0
	strb r0, [r2]
	strb r1, [r3]
_081EA51E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081ea524
FUN_081ea524: @ 0x081EA524
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r4, [sp, #0x1c]
	ldr r5, [sp, #0x20]
	ldr r6, [sp, #0x24]
	str r4, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	bl FUN_081ea688
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ea540
FUN_081ea540: @ 0x081EA540
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sb, r0
	mov sl, r1
	str r2, [sp, #0x14]
	str r3, [sp, #0x18]
	ldrh r1, [r1, #8]
	ldrh r0, [r0, #8]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r7, _081EA670 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r7
	orrs r0, r1
	str r0, [sp, #0xc]
	mov r0, sl
	ldrh r1, [r0, #0xc]
	mov r2, sb
	ldrh r0, [r2, #0xc]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r6, sp, #0xc
	ldr r0, [sp, #0x10]
	ands r0, r7
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r5, _081EA674 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _081EA678 @ =0x000003FF
	mov r8, r1
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _081EA67C @ =0x0203B400
	adds r0, r0, r2
	ldrh r4, [r0]
	movs r0, #0x3f
	ands r4, r0
	adds r4, #0x1e
	adds r0, r6, #0
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r4, #0
	bl Div
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r7
	orrs r1, r0
	str r1, [sp, #0xc]
	movs r2, #4
	ldrsh r0, [r6, r2]
	adds r1, r4, #0
	bl Div
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r7
	orrs r1, r0
	str r1, [sp, #0x10]
	adds r0, r4, #0
	movs r1, #2
	bl Div
	ldr r1, [r5]
	adds r1, #1
	mov r2, r8
	ands r1, r2
	str r1, [r5]
	lsls r1, r1, #1
	ldr r2, _081EA67C @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #7
	ands r1, r2
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r1, _081EA680 @ =0x0000FFFF
	ldr r2, [sp, #0xc]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #0xc]
	add r0, sp, #0xc
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0x30
	ble _081EA60A
	adds r0, r7, #0
	ands r0, r2
	movs r1, #0x30
	orrs r0, r1
	str r0, [sp, #0xc]
_081EA60A:
	add r0, sp, #0xc
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r2, #0x30
	rsbs r2, r2, #0
	cmp r0, r2
	bge _081EA622
	ldr r0, [sp, #0xc]
	ands r0, r7
	ldr r1, _081EA684 @ =0x0000FFD0
	orrs r0, r1
	str r0, [sp, #0xc]
_081EA622:
	movs r1, #4
	ldrsh r0, [r6, r1]
	cmp r0, #0x30
	ble _081EA634
	ldr r0, [sp, #0x10]
	ands r0, r7
	movs r1, #0x30
	orrs r0, r1
	str r0, [sp, #0x10]
_081EA634:
	movs r1, #4
	ldrsh r0, [r6, r1]
	cmp r0, r2
	bge _081EA646
	ldr r0, [sp, #0x10]
	ands r0, r7
	ldr r1, _081EA684 @ =0x0000FFD0
	orrs r0, r1
	str r0, [sp, #0x10]
_081EA646:
	ldr r2, [sp, #0x18]
	str r2, [sp]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #4]
	ldr r0, [sp, #0x40]
	str r0, [sp, #8]
	mov r0, sb
	mov r1, sl
	add r2, sp, #0xc
	ldr r3, [sp, #0x14]
	bl FUN_081ea688
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EA670: .4byte 0xFFFF0000
_081EA674: .4byte 0x030046B8
_081EA678: .4byte 0x000003FF
_081EA67C: .4byte 0x0203B400
_081EA680: .4byte 0x0000FFFF
_081EA684: .4byte 0x0000FFD0

	thumb_func_start FUN_081ea688
FUN_081ea688: @ 0x081EA688
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	mov r8, r2
	mov sl, r3
	ldr r0, _081EA740 @ =0x030001BC
	ldr r7, [r0]
	cmp r7, #0
	bne _081EA6AC
	bl FUN_081ea820
	adds r7, r0, #0
	cmp r7, #0
	beq _081EA748
_081EA6AC:
	adds r0, r7, #0
	bl FUN_081ea220
	adds r6, r0, #0
	cmp r6, #0
	beq _081EA748
	adds r0, #0xd2
	movs r4, #0
	movs r1, #1
	mov sb, r1
	mov r2, sb
	strb r2, [r0]
	mov r2, sp
	adds r2, #5
	adds r0, r5, #0
	add r1, sp, #4
	bl FUN_081ea4f4
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r6, #0x2c]
	str r1, [r6, #0x30]
	adds r0, r6, #0
	adds r0, #0xd0
	strh r4, [r0]
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x34]
	str r1, [r6, #0x38]
	adds r0, r6, #0
	adds r0, #0x8c
	adds r1, r6, #0
	adds r1, #0x2c
	movs r2, #0
	bl ParticleShadow_Init
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	adds r1, r7, #0
	adds r1, #0x18
	adds r0, r6, #0
	movs r2, #0
	bl FUN_0822a470
	movs r0, #3
	strh r0, [r6, #0x10]
	ldr r0, [r6, #0xc]
	ldr r1, _081EA744 @ =0x00000243
	bl Video_SetAuxSpritePltt
	ldr r0, [r6]
	mov r1, sb
	orrs r0, r1
	str r0, [r6]
	movs r0, #2
	strb r0, [r6, #7]
	ldr r0, [sp, #0x30]
	str r0, [sp]
	adds r0, r6, #0
	mov r1, sl
	ldr r2, [sp, #0x28]
	ldr r3, [sp, #0x2c]
	bl FUN_081ea184
	adds r0, r6, #0
	adds r0, #0xd3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	b _081EA74C
	.align 2, 0
_081EA740: .4byte 0x030001BC
_081EA744: .4byte 0x00000243
_081EA748:
	movs r0, #1
	rsbs r0, r0, #0
_081EA74C:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ea75c
FUN_081ea75c: @ 0x081EA75C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x38
	ldr r0, [r5, #0x34]
	cmp r0, #0
	beq _081EA7AA
	movs r4, #0
	ldr r7, _081EA780 @ =0x085AE46C
_081EA76E:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _081EA784
	movs r0, #1
	b _081EA786
	.align 2, 0
_081EA780: .4byte 0x085AE46C
_081EA784:
	movs r0, #0
_081EA786:
	cmp r0, #0
	beq _081EA7A4
	movs r0, #0xd4
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r6
	adds r0, r1, #0
	adds r0, #0xd2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081EA7A4:
	adds r4, #1
	cmp r4, #7
	ble _081EA76E
_081EA7AA:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081ea7b4
FUN_081ea7b4: @ 0x081EA7B4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
_081EA7BA:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _081EA7CA
	movs r0, #1
	b _081EA7CC
_081EA7CA:
	movs r0, #0
_081EA7CC:
	cmp r0, #0
	beq _081EA7E8
	movs r0, #0xd4
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x38
	adds r4, r6, r4
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x8c
	adds r0, r4, #0
	bl ParticleShadow_Remove
_081EA7E8:
	adds r5, #1
	cmp r5, #7
	ble _081EA7BA
	ldr r1, _081EA7FC @ =0x030001BC
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081EA7FC: .4byte 0x030001BC

	thumb_func_start FUN_081ea800
FUN_081ea800: @ 0x081EA800
	push {lr}
	movs r1, #0
	str r1, [r0, #0x34]
	ldr r1, _081EA818 @ =0x030001BC
	str r0, [r1]
	adds r0, #0x18
	ldr r1, _081EA81C @ =0x000084EE
	bl Video_GetAuxSprite
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_081EA818: .4byte 0x030001BC
_081EA81C: .4byte 0x000084EE

	thumb_func_start FUN_081ea820
FUN_081ea820: @ 0x081EA820
	push {r4, lr}
	ldr r0, _081EA858 @ =0x030001BC
	ldr r0, [r0]
	cmp r0, #0
	bne _081EA866
	movs r1, #0xdb
	lsls r1, r1, #3
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081EA864
	ldr r1, _081EA85C @ =FUN_081ea75c
	ldr r2, _081EA860 @ =FUN_081ea7b4
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_081ea800
	cmp r0, #0
	bge _081EA864
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081EA866
	.align 2, 0
_081EA858: .4byte 0x030001BC
_081EA85C: .4byte FUN_081ea75c
_081EA860: .4byte FUN_081ea7b4
_081EA864:
	adds r0, r4, #0
_081EA866:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ea86c
FUN_081ea86c: @ 0x081EA86C
	ldr r1, _081EA874 @ =0x030001BC
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081EA874: .4byte 0x030001BC
