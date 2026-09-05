	.include "asm/macros.inc"

	.syntax unified
	
	.text

@ EnemyXXX_Create でファイル分けしているだけなので他の敵のコードも混じっているかもしれない

	thumb_func_start FUN_08152be0
FUN_08152be0: @ 0x08152BE0
	push {r4, r5, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08152C14
	ldrh r1, [r5, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08152C14
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r5, #4]
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, _08152C1C @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_08152C14:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08152C1C: .4byte 0xFEFFFFFF

	thumb_func_start FUN_08152c20
FUN_08152c20: @ 0x08152C20
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08152C60
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #8
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08152C50
	movs r0, #1
	b _08152C52
_08152C50:
	movs r0, #0
_08152C52:
	cmp r0, #0
	bne _08152C60
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0815ec10
_08152C60:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08152c68
FUN_08152c68: @ 0x08152C68
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08152D38
	movs r1, #4
	ldrh r0, [r5, #6]
	ands r0, r1
	cmp r0, #0
	bne _08152D38
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _08152D38
	movs r3, #0xdc
	lsls r3, r3, #3
	adds r0, r6, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _08152D38
	ldr r1, _08152CD4 @ =0x0000A13F
	adds r2, #0x64
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08152D38
	movs r1, #0x10
	ldr r0, [r7, #0x34]
	ands r0, r1
	cmp r0, #0
	bne _08152D38
	movs r2, #0x20
	adds r3, #0x20
	adds r1, r6, r3
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _08152CD8
	movs r0, #1
	b _08152CDA
	.align 2, 0
_08152CD4: .4byte 0x0000A13F
_08152CD8:
	movs r0, #0
_08152CDA:
	cmp r0, #0
	bne _08152D38
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	ldrb r1, [r4, #5]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _08152CFC
	ldr r0, _08152CF8 @ =0xFFFFFF00
	adds r1, r1, r0
	b _08152D0A
	.align 2, 0
_08152CF8: .4byte 0xFFFFFF00
_08152CFC:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08152D0A
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r1, r3
_08152D0A:
	cmp r1, #0
	bge _08152D10
	rsbs r1, r1, #0
_08152D10:
	ldr r3, _08152D28 @ =0x000001FD
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r1, r0
	bgt _08152D38
	movs r1, #8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08152D2C
	movs r0, #1
	b _08152D2E
	.align 2, 0
_08152D28: .4byte 0x000001FD
_08152D2C:
	movs r0, #0
_08152D2E:
	cmp r0, #0
	bne _08152D38
	adds r0, r4, #0
	bl FUN_08159c24
_08152D38:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08152d40
FUN_08152d40: @ 0x08152D40
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r0, _08152D7C @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08152D5A
	movs r0, #0
	strb r0, [r1]
_08152D5A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ef86c
	ldr r1, _08152D80 @ =0x00000482
	adds r0, r4, r1
	ldrh r2, [r0]
	cmp r2, #1
	bne _08152D76
	ldr r0, _08152D84 @ =0x00000704
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08152D76:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08152D7C: .4byte 0x0000046D
_08152D80: .4byte 0x00000482
_08152D84: .4byte 0x00000704

	thumb_func_start FUN_08152d88
FUN_08152d88: @ 0x08152D88
	push {lr}
	adds r2, r0, #0
	ldr r0, _08152DA8 @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08152D9A
	movs r0, #0
	strb r0, [r1]
_08152D9A:
	adds r0, r2, #0
	movs r1, #0
	bl FUN_080ef86c
	pop {r0}
	bx r0
	.align 2, 0
_08152DA8: .4byte 0x0000046D

	thumb_func_start FUN_08152dac
FUN_08152dac: @ 0x08152DAC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	mov r8, r5
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	mov sl, r0
	ldr r2, _08152DDC @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08152DE0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08152DE2
	.align 2, 0
_08152DDC: .4byte 0x0000046D
_08152DE0:
	movs r0, #0
_08152DE2:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r3, r3, r5
	mov sb, r3
	cmp r0, #0
	bne _08152DF0
	b _0815326A
_08152DF0:
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r5, #5]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r3, r0, #1
	ands r3, r1
	ldr r1, _08152E3C @ =0x0000046A
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #6
	beq _08152E68
	adds r1, #0x16
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _08152E68
	movs r1, #0x20
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08152E40
	movs r0, #1
	b _08152E42
	.align 2, 0
_08152E3C: .4byte 0x0000046A
_08152E40:
	movs r0, #0
_08152E42:
	cmp r0, #0
	bne _08152E68
	mov r1, r8
	ldr r0, [r1, #0x24]
	ldr r0, [r0, #8]
	ldrh r0, [r0, #4]
	cmp r0, #0
	blt _08152E56
	asrs r0, r0, #0xc
	b _08152E5C
_08152E56:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08152E5C:
	adds r1, r0, #0
	movs r2, #0xee
	lsls r2, r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	b _08152E70
_08152E68:
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
_08152E70:
	cmp r1, #0
	blt _08152E78
	asrs r0, r1, #1
	b _08152E7E
_08152E78:
	rsbs r0, r1, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08152E7E:
	cmp r3, r0
	bne _08152EC6
	ldr r2, _08152EB0 @ =0x0000046B
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
	beq _08152EBC
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r1, _08152EB4 @ =0x000005BC
	adds r0, r5, r1
	ldr r2, [r0]
	movs r1, #0x1b
	ldr r3, _08152EB8 @ =0x0000046D
	b _081533D0
	.align 2, 0
_08152EB0: .4byte 0x0000046B
_08152EB4: .4byte 0x000005BC
_08152EB8: .4byte 0x0000046D
_08152EBC:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	b _08153434
_08152EC6:
	cmp r3, #1
	beq _08152FA4
	cmp r3, #1
	bgt _08152ED4
	cmp r3, #0
	beq _08152EE2
	b _08153262
_08152ED4:
	cmp r3, #2
	bne _08152EDA
	b _08153064
_08152EDA:
	cmp r3, #3
	bne _08152EE0
	b _08153144
_08152EE0:
	b _08153262
_08152EE2:
	subs r0, r1, #2
	cmp r0, #3
	bhi _08152F34
	movs r2, #1
	ldr r1, _08152F08 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08152F10
	ldr r1, _08152F0C @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #1
	b _08153166
	.align 2, 0
_08152F08: .4byte 0x0000025D
_08152F0C: .4byte 0x000004B7
_08152F10:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #2
	ldr r3, _08152F2C @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08152F30 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #2
	beq _08152F2A
	b _081531A2
_08152F2A:
	b _08153192
	.align 2, 0
_08152F2C: .4byte 0x000004B7
_08152F30: .4byte 0x0000046E
_08152F34:
	movs r1, #1
	ldr r2, _08152F5C @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08152F64
	ldr r3, _08152F60 @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	b _08152F8A
	.align 2, 0
_08152F5C: .4byte 0x0000025D
_08152F60: .4byte 0x000004B7
_08152F64:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldr r2, _08152F9C @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #1
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_08152F8A:
	ldr r3, _08152FA0 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
	b _0815325A
	.align 2, 0
_08152F9C: .4byte 0x000004B7
_08152FA0: .4byte 0x0000046E
_08152FA4:
	subs r0, r1, #4
	cmp r0, #3
	bhi _08152FF8
	ldr r1, _08152FCC @ =0x0000025D
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #0
	bne _08152FD4
	ldr r1, _08152FD0 @ =0x000004B7
	adds r0, r5, r1
	strb r3, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r2, [sp]
	movs r2, #1
	movs r3, #2
	b _08153166
	.align 2, 0
_08152FCC: .4byte 0x0000025D
_08152FD0: .4byte 0x000004B7
_08152FD4:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #3
	ldr r3, _08152FF0 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _08152FF4 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #3
	beq _08152FEE
	b _081531A2
_08152FEE:
	b _08153192
	.align 2, 0
_08152FF0: .4byte 0x000004B7
_08152FF4: .4byte 0x0000046E
_08152FF8:
	ldr r1, _08153020 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08153028
	ldr r2, _08153024 @ =0x000004B7
	adds r0, r5, r2
	strb r3, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #1
	movs r3, #1
	bl FUN_08236fac
	b _08153050
	.align 2, 0
_08153020: .4byte 0x0000025D
_08153024: .4byte 0x000004B7
_08153028:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #2
	ldr r3, _0815305C @ =0x000004B7
	adds r0, r5, r3
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
	str r0, [r4, #8]
_08153050:
	ldr r0, _08153060 @ =0x0000046E
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	b _08153254
	.align 2, 0
_0815305C: .4byte 0x000004B7
_08153060: .4byte 0x0000046E
_08153064:
	subs r0, r1, #1
	cmp r0, #4
	bls _081530D4
	ldr r2, _08153094 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0815309C
	ldr r3, _08153098 @ =0x000004B7
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #5
	str r2, [sp]
	movs r2, #1
	movs r3, #1
	bl FUN_08236fac
	b _081530C0
	.align 2, 0
_08153094: .4byte 0x0000025D
_08153098: .4byte 0x000004B7
_0815309C:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldr r1, _081530CC @ =0x000004B7
	adds r0, r5, r1
	strb r3, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #2
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #4
	orrs r0, r1
	str r0, [r4, #8]
_081530C0:
	ldr r2, _081530D0 @ =0x0000046E
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	b _081531C2
	.align 2, 0
_081530CC: .4byte 0x000004B7
_081530D0: .4byte 0x0000046E
_081530D4:
	movs r1, #1
	ldr r2, _081530FC @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08153104
	ldr r3, _08153100 @ =0x000004B7
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #1
	movs r3, #2
	bl FUN_08236fac
	b _0815312C
	.align 2, 0
_081530FC: .4byte 0x0000025D
_08153100: .4byte 0x000004B7
_08153104:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r1, #3
	ldr r2, _0815313C @ =0x000004B7
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
_0815312C:
	ldr r3, _08153140 @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
	b _0815325A
	.align 2, 0
_0815313C: .4byte 0x000004B7
_08153140: .4byte 0x0000046E
_08153144:
	cmp r1, #3
	bhi _081531DC
	movs r2, #1
	ldr r1, _08153170 @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _0815317C
	ldr r1, _08153174 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #0
_08153166:
	bl FUN_08236fac
	ldr r2, _08153178 @ =0x0000046E
	adds r6, r5, r2
	b _081531BE
	.align 2, 0
_08153170: .4byte 0x0000025D
_08153174: .4byte 0x000004B7
_08153178: .4byte 0x0000046E
_0815317C:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r3, _081531D4 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081531D8 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #1
	bne _081531A2
_08153192:
	ldrb r0, [r6]
	cmp r0, #0
	bne _081531A2
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081531C2
_081531A2:
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
_081531BE:
	movs r0, #0
	strb r0, [r6]
_081531C2:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08153262
	.align 2, 0
_081531D4: .4byte 0x000004B7
_081531D8: .4byte 0x0000046E
_081531DC:
	movs r2, #1
	ldr r1, _08153204 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08153210
	ldr r3, _08153208 @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r2, [sp]
	movs r3, #1
	bl FUN_08236fac
	ldr r0, _0815320C @ =0x0000046E
	adds r6, r5, r0
	b _08153250
	.align 2, 0
_08153204: .4byte 0x0000025D
_08153208: .4byte 0x000004B7
_0815320C: .4byte 0x0000046E
_08153210:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #2
	ldr r1, _081532A0 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081532A4 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #2
	bne _08153238
	ldrb r0, [r6]
	cmp r0, #0
	bne _08153238
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08153254
_08153238:
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
_08153250:
	movs r0, #0
	strb r0, [r6]
_08153254:
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r5, r1
_0815325A:
	ldr r1, _081532A8 @ =0xFFFEFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_08153262:
	ldr r2, _081532A4 @ =0x0000046E
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
_0815326A:
	mov r3, sl
	ldrh r0, [r3, #0xe]
	cmp r0, #0
	bne _081532D0
	ldrh r0, [r3, #8]
	cmp r0, #0
	beq _081532D0
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
	bge _08153296
	rsbs r0, r0, #0
_08153296:
	cmp r0, #0x10
	bgt _081532AC
	mov r0, r8
	strb r1, [r0, #5]
	b _081532D0
	.align 2, 0
_081532A0: .4byte 0x000004B7
_081532A4: .4byte 0x0000046E
_081532A8: .4byte 0xFFFEFFFF
_081532AC:
	movs r1, #0x80
	lsls r1, r1, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081532C8
	adds r0, r2, #0
	adds r0, #0x10
	mov r1, r8
	strb r0, [r1, #5]
	b _081532D0
_081532C8:
	adds r0, r2, #0
	subs r0, #0x10
	mov r2, r8
	strb r0, [r2, #5]
_081532D0:
	ldr r1, _081532E8 @ =0x0000A02F
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081532F0
	ldr r0, _081532EC @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08153300
	.align 2, 0
_081532E8: .4byte 0x0000A02F
_081532EC: .4byte 0x00000482
_081532F0:
	ldr r1, _08153324 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08153300
	movs r0, #1
	strh r0, [r2]
_08153300:
	ldr r3, _08153328 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0815332C
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
	b _08153344
	.align 2, 0
_08153324: .4byte 0x00000482
_08153328: .4byte 0x0000025D
_0815332C:
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
_08153344:
	ldr r1, _081533F4 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08153434
	ldrb r0, [r5, #5]
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
	bge _0815336E
	rsbs r1, r1, #0
_0815336E:
	cmp r1, #0
	bgt _08153404
	ldr r1, _081533F8 @ =0x0000046B
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
	beq _08153434
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r7, [r0]
	adds r1, #0x69
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _081533FC @ =0x0000046A
	adds r0, r5, r2
	strb r6, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r6, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _08153400 @ =0x000005BC
	adds r0, r5, r2
	ldr r2, [r0]
	movs r1, #0x1b
	subs r3, #0x17
_081533D0:
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
	b _08153434
	.align 2, 0
_081533F4: .4byte 0x0000046E
_081533F8: .4byte 0x0000046B
_081533FC: .4byte 0x0000046A
_08153400: .4byte 0x000005BC
_08153404:
	movs r3, #0xb2
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r4, [r0]
	movs r3, #2
	ldr r0, _08153444 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08153448 @ =0x0000046B
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
_08153434:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08153444: .4byte 0x0000046D
_08153448: .4byte 0x0000046B

	thumb_func_start FUN_0815344c
FUN_0815344c: @ 0x0815344C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _08153464 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08153468
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0815346A
	.align 2, 0
_08153464: .4byte 0x0000046D
_08153468:
	movs r0, #0
_0815346A:
	cmp r0, #0
	beq _0815348C
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
	bne _0815348C
	movs r0, #1
	orrs r0, r1
	strh r0, [r2]
_0815348C:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Mod
	cmp r0, #0
	bne _081534A8
	ldr r2, _081534F4 @ =0x000001DF
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	bl FUN_080e5718
_081534A8:
	ldr r1, _081534F8 @ =0x00000466
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _081534EE
	movs r1, #0x80
	lsls r1, r1, #5
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r4, [r0]
	ands r4, r1
	cmp r4, #0
	bne _081534EE
	ldr r3, _081534FC @ =FUN_08153508
	movs r2, #6
	ldr r0, _08153500 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08153504 @ =0x0000046B
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
_081534EE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081534F4: .4byte 0x000001DF
_081534F8: .4byte 0x00000466
_081534FC: .4byte FUN_08153508
_08153500: .4byte 0x0000046D
_08153504: .4byte 0x0000046B

	thumb_func_start FUN_08153508
FUN_08153508: @ 0x08153508
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _08153520 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08153524
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08153526
	.align 2, 0
_08153520: .4byte 0x0000046D
_08153524:
	movs r0, #0
_08153526:
	cmp r0, #0
	beq _08153542
	adds r0, r4, #0
	movs r1, #7
	bl FUN_080ef86c
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #2
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_08153542:
	cmp r5, #0x28
	bne _08153554
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08153554:
	ldr r1, _08153570 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0815356A
	cmp r5, #0x78
	ble _0815356A
	ldr r0, _08153574 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0815356A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08153570: .4byte 0x0000046E
_08153574: .4byte 0x0000046B

	thumb_func_start FUN_08153578
FUN_08153578: @ 0x08153578
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	movs r2, #1
	ldr r1, _08153594 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08153598
	ldr r1, [r4, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081535A2
	.align 2, 0
_08153594: .4byte 0x0000025D
_08153598:
	ldr r1, [r4, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_081535A2:
	ldr r1, _081535B8 @ =0x0000046D
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _081535BC
	movs r0, #0
	strb r0, [r6]
	movs r0, #1
	b _081535BE
	.align 2, 0
_081535B8: .4byte 0x0000046D
_081535BC:
	movs r0, #0
_081535BE:
	adds r5, r0, #0
	cmp r5, #0
	beq _081535D0
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r0, r4, r3
	bl FUN_080136b4
	b _08153612
_081535D0:
	cmp r3, #0x1a
	ble _0815360C
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #4
	bl FUN_080ef968
	ldr r2, _08153604 @ =FUN_0815361c
	movs r1, #0xd
	movs r0, #1
	strb r0, [r6]
	ldr r3, _08153608 @ =0x0000046B
	adds r0, r4, r3
	strb r5, [r0]
	adds r3, #0xe8
	adds r0, r4, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r5, [r0]
	b _08153612
	.align 2, 0
_08153604: .4byte FUN_0815361c
_08153608: .4byte 0x0000046B
_0815360C:
	ldr r1, _08153618 @ =0x0000046E
	adds r0, r4, r1
	strb r5, [r0]
_08153612:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08153618: .4byte 0x0000046E

	thumb_func_start FUN_0815361c
FUN_0815361c: @ 0x0815361C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08153634 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08153638
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0815363A
	.align 2, 0
_08153634: .4byte 0x0000046D
_08153638:
	movs r0, #0
_0815363A:
	cmp r0, #0
	beq _08153686
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r6, r1
	bl FUN_08013698
	ldr r2, _08153660 @ =0x0000025D
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08153664
	ldr r2, [r6, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _08153672
	.align 2, 0
_08153660: .4byte 0x0000025D
_08153664:
	ldr r0, [r6, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_08153672:
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
_08153686:
	ldr r1, _08153824 @ =0x0000046E
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08153692
	b _0815381E
_08153692:
	adds r0, r6, #0
	bl FUN_0815ea60
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r2, _08153828 @ =0x0000055C
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
	ldr r1, _0815382C @ =0x00000564
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
	ldr r1, _08153830 @ =0x00000566
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _08153834 @ =0x00000567
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
	ldr r1, _08153838 @ =0x0000056C
	adds r0, r6, r1
	ldrb r1, [r0]
	subs r2, #0x15
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _0815383C @ =0x00000572
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
	ldr r2, _08153840 @ =0x0000046B
	adds r0, r6, r2
	strb r5, [r0]
	ldr r1, _08153844 @ =0x0000046C
	adds r0, r6, r1
	movs r1, #1
	strb r1, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r5, [r0]
	ldr r2, _08153848 @ =0x0000024E
	adds r0, r6, r2
	strh r4, [r0]
	subs r2, #0xbc
	adds r0, r6, r2
	strh r4, [r0]
	ldr r2, _0815384C @ =0x00000544
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
	ldr r2, _08153850 @ =0x00000482
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
	ldr r1, _08153854 @ =0x00000464
	adds r0, r6, r1
	strh r4, [r0]
	movs r2, #0x8c
	lsls r2, r2, #3
	adds r0, r6, r2
	strh r4, [r0]
	subs r1, #2
	adds r0, r6, r1
	strh r4, [r0]
	ldr r1, _08153858 @ =0x082520F0
	adds r0, r6, #0
	ldr r2, _0815385C @ =0x00000982
	bl FUN_080e6768
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r5, [r0]
	ldr r1, _08153860 @ =0x00000541
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
_0815381E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08153824: .4byte 0x0000046E
_08153828: .4byte 0x0000055C
_0815382C: .4byte 0x00000564
_08153830: .4byte 0x00000566
_08153834: .4byte 0x00000567
_08153838: .4byte 0x0000056C
_0815383C: .4byte 0x00000572
_08153840: .4byte 0x0000046B
_08153844: .4byte 0x0000046C
_08153848: .4byte 0x0000024E
_0815384C: .4byte 0x00000544
_08153850: .4byte 0x00000482
_08153854: .4byte 0x00000464
_08153858: .4byte 0x082520F0
_0815385C: .4byte 0x00000982
_08153860: .4byte 0x00000541

	thumb_func_start FUN_08153864
FUN_08153864: @ 0x08153864
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	ldr r0, [r4, #0x44]
	adds r5, r0, #0
	adds r5, #0x48
	ldr r3, _0815389C @ =0x0000046D
	adds r1, r4, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _08153886
	movs r0, #0
	strb r0, [r1]
_08153886:
	movs r1, #2
	movs r3, #0xe0
	lsls r3, r3, #3
	adds r0, r2, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081538A0
	movs r0, #1
	b _081538A2
	.align 2, 0
_0815389C: .4byte 0x0000046D
_081538A0:
	movs r0, #0
_081538A2:
	cmp r0, #0
	beq _081538C8
	adds r0, r4, #0
	movs r1, #0x11
	bl FUN_080ef86c
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _081538D0
	ldrh r0, [r5, #0xe]
	cmp r0, #0
	bne _081538D0
	ldr r0, _081538C4 @ =0x000001D1
	bl PlaySound_082406e0
	b _081538D0
	.align 2, 0
_081538C4: .4byte 0x000001D1
_081538C8:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
_081538D0:
	ldr r1, _081538F4 @ =0x00000454
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_080da8a0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081538E4
	cmp r6, #0x1e
	ble _081538EC
_081538E4:
	ldr r3, _081538F8 @ =0x0000046B
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
_081538EC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081538F4: .4byte 0x00000454
_081538F8: .4byte 0x0000046B

	thumb_func_start FUN_081538fc
FUN_081538fc: @ 0x081538FC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0815391C @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08153920
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08153922
	.align 2, 0
_0815391C: .4byte 0x0000046D
_08153920:
	movs r0, #0
_08153922:
	cmp r0, #0
	beq _0815392E
	ldr r3, _081539DC @ =0x0000046E
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
_0815392E:
	adds r0, r5, #0
	bl FUN_0815cb98
	cmp r4, #0x3c
	bgt _0815393A
	b _08153ADA
_0815393A:
	ldr r0, _081539E0 @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081539E4 @ =0x000004A4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r2, #0x1c
	ldrsh r1, [r0, r2]
	movs r3, #0x20
	ldrsh r2, [r0, r3]
	adds r0, r5, #0
	bl FUN_080e6304
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081539F8
	movs r1, #2
	movs r3, #0xe0
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r0, [r0]
	ands r0, r1
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r2, _081539E8 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081539E0 @ =0x0000046B
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
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081539EC @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _081539F0 @ =0x00000484
	adds r0, r5, r3
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	movs r0, #4
	ldr r1, _081539F4 @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _08153AD2
	.align 2, 0
_081539DC: .4byte 0x0000046E
_081539E0: .4byte 0x0000046B
_081539E4: .4byte 0x000004A4
_081539E8: .4byte 0x0000046D
_081539EC: .4byte 0x0000046A
_081539F0: .4byte 0x00000484
_081539F4: .4byte 0x00000222
_081539F8:
	movs r1, #2
	movs r3, #0xe0
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08153A0C
	movs r0, #1
	b _08153A0E
_08153A0C:
	movs r0, #0
_08153A0E:
	adds r4, r0, #0
	cmp r4, #0
	beq _08153A74
	ldr r3, _08153A64 @ =FUN_08155570
	movs r1, #0x23
	ldr r6, _08153A68 @ =0x0000046D
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
	movs r1, #0
	strh r2, [r0]
	movs r3, #0x11
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08153A6C @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _08153A70 @ =0x00000484
	adds r0, r5, r3
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	b _08153AC4
	.align 2, 0
_08153A64: .4byte FUN_08155570
_08153A68: .4byte 0x0000046D
_08153A6C: .4byte 0x0000046A
_08153A70: .4byte 0x00000484
_08153A74:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	ldr r3, _08153AE0 @ =0x0000046D
	adds r0, r5, r3
	strb r2, [r0]
	ldr r6, _08153AE4 @ =0x0000046B
	adds r0, r5, r6
	strb r4, [r0]
	adds r3, #0xe6
	adds r0, r5, r3
	strb r2, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r4, [r0]
	movs r3, #7
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08153AE8 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _08153AEC @ =0x00000484
	adds r0, r5, r3
	str r4, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r2, [r0]
_08153AC4:
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08153AD2:
	ldr r2, _08153AF0 @ =0x00000482
	adds r1, r5, r2
	movs r0, #2
	strh r0, [r1]
_08153ADA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08153AE0: .4byte 0x0000046D
_08153AE4: .4byte 0x0000046B
_08153AE8: .4byte 0x0000046A
_08153AEC: .4byte 0x00000484
_08153AF0: .4byte 0x00000482

	thumb_func_start FUN_08153af4
FUN_08153af4: @ 0x08153AF4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r1, #0
	ldr r0, _08153B0C @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08153B10
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08153B12
	.align 2, 0
_08153B0C: .4byte 0x0000046D
_08153B10:
	movs r0, #0
_08153B12:
	cmp r0, #0
	beq _08153B30
	ldr r1, _08153B98 @ =0x000001DD
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #3
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	subs r0, #0x40
	strb r0, [r7, #5]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
_08153B30:
	cmp r4, #0x3c
	bgt _08153B36
	b _08153D7A
_08153B36:
	ldr r2, _08153B9C @ =0x0000046E
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08153B42
	b _08153D7A
_08153B42:
	ldr r3, _08153BA0 @ =0x0000046B
	adds r1, r7, r3
	movs r0, #1
	strb r0, [r1]
	ldr r5, _08153BA4 @ =0x000001DF
	adds r0, r7, r5
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r7, r6
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
	blt _08153B92
	cmp r1, #0
	blt _08153B92
	ldr r0, _08153BA8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08153B92
	ldr r0, _08153BAC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08153BB0
_08153B92:
	movs r4, #0
	b _08153BBE
	.align 2, 0
_08153B98: .4byte 0x000001DD
_08153B9C: .4byte 0x0000046E
_08153BA0: .4byte 0x0000046B
_08153BA4: .4byte 0x000001DF
_08153BA8: .4byte 0x030046A8
_08153BAC: .4byte 0x030046AC
_08153BB0:
	ldr r0, _08153BD0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08153BBE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08153BD4
	adds r0, #4
	b _08153BE0
	.align 2, 0
_08153BD0: .4byte 0x030046A4
_08153BD4:
	ldr r0, _08153BF4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08153BE0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08153BF8
	cmp r2, #2
	beq _08153BFC
	b _08153C00
	.align 2, 0
_08153BF4: .4byte 0x030046A4
_08153BF8:
	ldrb r0, [r5, #4]
	b _08153BFE
_08153BFC:
	ldrb r0, [r5]
_08153BFE:
	subs r1, r1, r0
_08153C00:
	strh r1, [r5, #2]
	ldr r1, _08153C2C @ =0x000004A4
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
	bne _08153C30
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
	b _08153C56
	.align 2, 0
_08153C2C: .4byte 0x000004A4
_08153C30:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08153C50
	cmp r0, #2
	beq _08153C4C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08153C4C:
	movs r0, #1
	b _08153C60
_08153C50:
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
_08153C56:
	ldr r1, _08153CB0 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08153C60:
	adds r4, r0, #0
	cmp r4, #0
	bne _08153CD0
	ldr r1, _08153CB4 @ =FUN_080e48d0
	ldr r6, _08153CB8 @ =0x0000046D
	adds r0, r7, r6
	movs r3, #1
	strb r3, [r0]
	ldr r2, _08153CBC @ =0x0000046B
	adds r0, r7, r2
	strb r4, [r0]
	ldr r5, _08153CC0 @ =0x00000553
	adds r0, r7, r5
	strb r4, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _08153CC4 @ =0x00000469
	adds r0, r7, r6
	strb r2, [r0]
	ldr r1, _08153CC8 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _08153CCC @ =0x00000484
	adds r0, r7, r2
	str r4, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	b _08153D7A
	.align 2, 0
_08153CB0: .4byte 0xFFFFFDFF
_08153CB4: .4byte FUN_080e48d0
_08153CB8: .4byte 0x0000046D
_08153CBC: .4byte 0x0000046B
_08153CC0: .4byte 0x00000553
_08153CC4: .4byte 0x00000469
_08153CC8: .4byte 0x0000046A
_08153CCC: .4byte 0x00000484
_08153CD0:
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r0, [r0]
	movs r4, #0
	movs r5, #0
	movs r2, #1
	movs r6, #1
	strh r6, [r0, #6]
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _08153D80 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r4, [r0]
	adds r1, #0x1b
	adds r0, r7, r1
	str r5, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r2, [r0]
	ldr r0, _08153D84 @ =FUN_080e6794
	mov ip, r0
	movs r1, #0xe
	adds r3, #1
	adds r0, r7, r3
	strb r2, [r0]
	ldr r2, _08153D88 @ =0x0000046B
	adds r0, r7, r2
	strb r4, [r0]
	adds r3, #0xe6
	adds r0, r7, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r2, ip
	str r2, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r5, [r0]
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r2, #0x81
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r2, _08153D8C @ =0x00000482
	adds r0, r7, r2
	strh r6, [r0]
	movs r2, #0x10
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r3, [r0]
	movs r5, #7
	movs r1, #0x3c
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
	strb r4, [r0]
	ldr r2, _08153D90 @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _08153D94 @ =0x00000552
	adds r0, r7, r3
	strb r5, [r0]
_08153D7A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08153D80: .4byte 0x00000469
_08153D84: .4byte FUN_080e6794
_08153D88: .4byte 0x0000046B
_08153D8C: .4byte 0x00000482
_08153D90: .4byte 0x00000551
_08153D94: .4byte 0x00000552

	thumb_func_start FUN_08153d98
FUN_08153d98: @ 0x08153D98
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x84
	adds r7, r0, #0
	adds r6, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r0, [r7, #0x44]
	adds r4, r0, #0
	adds r4, #0x48
	ldr r2, _08153DCC @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08153DD0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08153DD2
	.align 2, 0
_08153DCC: .4byte 0x0000046D
_08153DD0:
	movs r0, #0
_08153DD2:
	cmp r0, #0
	beq _08153DF4
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r0, _08153E54 @ =0xFFFFFEFE
	ldrh r1, [r2]
	ands r0, r1
	movs r1, #0
	strh r0, [r2]
	ldr r5, _08153E58 @ =0x0000046E
	adds r0, r7, r5
	strb r1, [r0]
_08153DF4:
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
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r5, r2, #0
	cmp r6, #0x11
	bgt _08153E34
	ldrh r3, [r4, #8]
	cmp r3, #0
	bne _08153E34
	ldrh r1, [r4, #0xe]
	ldrb r2, [r4, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _08153E34
	cmp r2, #1
	beq _08153E34
	strh r3, [r4, #0xe]
_08153E34:
	movs r6, #0x83
	lsls r6, r6, #2
	adds r0, r7, r6
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r3, #0x85
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r4, #0
	ldrsh r0, [r1, r4]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _08153E5C
	asrs r0, r0, #2
	b _08153E62
	.align 2, 0
_08153E54: .4byte 0xFFFFFEFE
_08153E58: .4byte 0x0000046E
_08153E5C:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08153E62:
	adds r3, r0, #0
	movs r6, #0x84
	lsls r6, r6, #2
	adds r0, r7, r6
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r6, #8
	adds r1, r7, r6
	movs r6, #0
	ldrsh r0, [r1, r6]
	subs r0, r2, r0
	cmp r0, #0
	blt _08153E80
	asrs r0, r0, #2
	b _08153E86
_08153E80:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08153E86:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _08153E90
	movs r3, #0xc8
	b _08153E9A
_08153E90:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _08153E9A
	adds r3, r0, #0
_08153E9A:
	cmp r2, #0xc8
	ble _08153EA2
	movs r2, #0xc8
	b _08153EAC
_08153EA2:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _08153EAC
	adds r2, r0, #0
_08153EAC:
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
	bne _08153ED0
	cmp r2, #0
	bne _08153ED0
	movs r0, #1
	b _08153ED2
_08153ED0:
	movs r0, #0
_08153ED2:
	cmp r0, #0
	bne _08153EDA
	bl _0815475C
_08153EDA:
	ldr r1, _08153F2C @ =0x0000046E
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08153EE8
	bl _0815475C
_08153EE8:
	ldr r2, _08153F30 @ =0x0000046B
	adds r1, r7, r2
	movs r0, #1
	strb r0, [r1]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	subs r0, #0x22
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	ldr r4, _08153F34 @ =0x0000049C
	adds r0, r7, r4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xc
	ands r0, r1
	str r2, [sp, #0x40]
	cmp r0, #0
	beq _08153F38
	movs r0, #2
	movs r5, #0xc1
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	bl _0815475C
	.align 2, 0
_08153F2C: .4byte 0x0000046E
_08153F30: .4byte 0x0000046B
_08153F34: .4byte 0x0000049C
_08153F38:
	movs r0, #0xe0
	lsls r0, r0, #3
	add r0, r8
	ldr r0, [r0]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08153F4C
	movs r0, #1
	b _08153F4E
_08153F4C:
	movs r0, #0
_08153F4E:
	cmp r0, #0
	beq _08153FB8
	ldr r3, _08153FA4 @ =FUN_081562dc
	movs r1, #0x34
	ldr r6, _08153FA8 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _08153FAC @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	adds r6, #0xe6
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
	movs r3, #0x13
	subs r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08153FB0 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _08153FB4 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	bl _0815475C
	.align 2, 0
_08153FA4: .4byte FUN_081562dc
_08153FA8: .4byte 0x0000046D
_08153FAC: .4byte 0x0000046B
_08153FB0: .4byte 0x0000046A
_08153FB4: .4byte 0x00000484
_08153FB8:
	movs r1, #0x80
	ldr r6, [sp, #0x40]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _08153FCA
	b _0815470C
_08153FCA:
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, _08154020 @ =0x03002BE0
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
	str r3, [sp, #0x80]
	str r2, [sp, #0x68]
	cmp r4, #0
	blt _0815401A
	cmp r1, #0
	blt _0815401A
	ldr r0, _08154024 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0815401A
	ldr r0, _08154028 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815402C
_0815401A:
	movs r4, #0
	b _0815403A
	.align 2, 0
_08154020: .4byte 0x03002BE0
_08154024: .4byte 0x030046A8
_08154028: .4byte 0x030046AC
_0815402C:
	ldr r0, _0815404C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0815403A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08154050
	adds r0, #4
	b _0815405C
	.align 2, 0
_0815404C: .4byte 0x030046A4
_08154050:
	ldr r0, _08154070 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815405C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08154074
	cmp r2, #2
	beq _08154078
	b _0815407C
	.align 2, 0
_08154070: .4byte 0x030046A4
_08154074:
	ldrb r0, [r5, #4]
	b _0815407A
_08154078:
	ldrb r0, [r5]
_0815407A:
	subs r1, r1, r0
_0815407C:
	strh r1, [r5, #2]
	ldr r0, _08154090 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08154094
	movs r0, #1
	b _08154096
	.align 2, 0
_08154090: .4byte 0x030047A4
_08154094:
	movs r0, #0
_08154096:
	cmp r0, #0
	beq _081540D4
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _081540B6
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081540B2
	adds r2, r0, #0
_081540B2:
	cmp r2, #0
	bge _081540C0
_081540B6:
	ldr r3, _081540BC @ =0x000005C4
	adds r0, r7, r3
	b _081545F8
	.align 2, 0
_081540BC: .4byte 0x000005C4
_081540C0:
	ldr r1, _081540D0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0815411C
	.align 2, 0
_081540D0: .4byte 0x03002BE0
_081540D4:
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
	blt _08154100
	cmp r1, #0
	blt _08154100
	ldr r0, _08154104 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08154100
	ldr r0, _08154108 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815410C
_08154100:
	movs r5, #0
	b _0815411A
	.align 2, 0
_08154104: .4byte 0x030046A8
_08154108: .4byte 0x030046AC
_0815410C:
	ldr r0, _08154154 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0815411A:
	movs r2, #0
_0815411C:
	ldr r6, _08154158 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _0815413C
	ldr r1, _0815415C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0815413C
	b _08154538
_0815413C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x40]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _08154160
	movs r0, #0
	b _0815460E
	.align 2, 0
_08154154: .4byte 0x030046A4
_08154158: .4byte 0x00000256
_0815415C: .4byte 0x03002BE0
_08154160:
	ldr r3, _08154204 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0x40]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0x58]
	cmp r6, #0
	beq _0815421C
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _08154208 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #8]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _0815420C @ =0x0000046B
	adds r3, r3, r7
	mov r8, r3
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x65
	adds r5, r7, r5
	str r5, [sp, #0xc]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r6, r7
	mov sl, r6
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r5, r7, r0
	mov r1, sb
	strh r1, [r5]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	movs r3, #0
	strb r3, [r4]
	ldr r6, _08154210 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _08154214 @ =0x00000484
	adds r1, r7, r0
	mov r6, sb
	str r6, [r1]
	ldr r6, _08154218 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #8]
	str r6, [sp, #0x74]
	mov r6, r8
	str r6, [sp, #0x6c]
	ldr r6, [sp, #0xc]
	str r6, [sp, #0x48]
	mov r6, sl
	str r6, [sp, #0x4c]
	str r5, [sp, #0x50]
	str r4, [sp, #0x5c]
	str r3, [sp, #0x60]
	str r2, [sp, #0x64]
	str r1, [sp, #0x7c]
	str r0, [sp, #0x70]
	b _081543EE
	.align 2, 0
_08154204: .4byte 0x00000222
_08154208: .4byte 0x0000046D
_0815420C: .4byte 0x0000046B
_08154210: .4byte 0x00000469
_08154214: .4byte 0x00000484
_08154218: .4byte 0x0000046C
_0815421C:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081542E0 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x10]
	strb r0, [r2]
	ldr r3, _081542E4 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x14]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081542E8 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x18]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x1c]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x20]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x24]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _081542EC @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _081542F0 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _081542F4 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x80]
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldr r1, [sp, #0x68]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x28]
	strh r1, [r6]
	ldr r6, [sp, #0x68]
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
	str r0, [sp, #0x74]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x6c]
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x48]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0x4c]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x50]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0x5c]
	str r5, [sp, #0x60]
	str r4, [sp, #0x64]
	str r3, [sp, #0x7c]
	str r2, [sp, #0x70]
	mov r0, ip
	cmp r0, #0
	blt _081542DA
	cmp r1, #0
	blt _081542DA
	ldr r0, _081542F8 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _081542DA
	ldr r0, _081542FC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08154300
_081542DA:
	movs r4, #0
	b _08154310
	.align 2, 0
_081542E0: .4byte 0x0000046D
_081542E4: .4byte 0x0000046B
_081542E8: .4byte 0x00000553
_081542EC: .4byte 0x00000469
_081542F0: .4byte 0x00000484
_081542F4: .4byte 0x0000046C
_081542F8: .4byte 0x030046A8
_081542FC: .4byte 0x030046AC
_08154300:
	ldr r0, _08154320 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_08154310:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08154324
	adds r0, #4
	b _08154330
	.align 2, 0
_08154320: .4byte 0x030046A4
_08154324:
	ldr r0, _08154344 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08154330:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08154348
	cmp r2, #2
	beq _0815434E
	b _08154354
	.align 2, 0
_08154344: .4byte 0x030046A4
_08154348:
	ldr r2, [sp, #0x28]
	ldrb r0, [r2, #4]
	b _08154352
_0815434E:
	ldr r3, [sp, #0x28]
	ldrb r0, [r3]
_08154352:
	subs r1, r1, r0
_08154354:
	ldr r4, [sp, #0x28]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x80]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08154380
	cmp r1, #0
	blt _08154380
	ldr r0, _08154384 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08154380
	ldr r0, _08154388 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815438C
_08154380:
	movs r4, #0
	b _0815439A
	.align 2, 0
_08154384: .4byte 0x030046A8
_08154388: .4byte 0x030046AC
_0815438C:
	ldr r0, _081543B0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0815439A:
	ldr r6, [sp, #0x80]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081543B4
	adds r0, #4
	b _081543C0
	.align 2, 0
_081543B0: .4byte 0x030046A4
_081543B4:
	ldr r0, _081543D4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081543C0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081543D8
	cmp r3, #2
	beq _081543DC
	b _081543E0
	.align 2, 0
_081543D4: .4byte 0x030046A4
_081543D8:
	ldrb r0, [r5, #4]
	b _081543DE
_081543DC:
	ldrb r0, [r5]
_081543DE:
	subs r2, r2, r0
_081543E0:
	ldr r1, [sp, #0x80]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x80]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081543EE:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x2c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x40]
	ldrh r0, [r4]
	ands r0, r1
	mov sb, r3
	ldr r5, _08154418 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x78]
	cmp r0, #0
	bne _081544FC
	movs r1, #4
	ldr r6, [sp, #0x58]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0815441C
	movs r0, #1
	b _0815441E
	.align 2, 0
_08154418: .4byte 0x00000482
_0815441C:
	movs r0, #0
_0815441E:
	ldr r1, _0815450C @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x78]
	cmp r0, #0
	bne _081544FC
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r2, r2, r7
	mov r8, r2
	movs r4, #0xa9
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sl, r4
	ldr r5, _08154510 @ =0x0000054F
	adds r5, r5, r7
	mov ip, r5
	ldr r6, _08154514 @ =0x0000054C
	adds r6, r7, r6
	str r6, [sp, #0x38]
	ldr r0, _08154518 @ =0x0000054D
	adds r0, r7, r0
	str r0, [sp, #0x3c]
	ldr r1, _0815451C @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x44]
	ldr r2, _08154520 @ =0x00000541
	adds r2, r7, r2
	str r2, [sp, #0x30]
	ldr r4, _08154524 @ =0x000005BC
	adds r4, r7, r4
	str r4, [sp, #0x54]
	ldr r5, _08154528 @ =0x00000542
	adds r5, r7, r5
	str r5, [sp, #0x34]
	ldr r6, _0815452C @ =0x0203B400
	ldr r1, _08154530 @ =0x030046B8
	ldr r5, _08154534 @ =0x000003FF
	movs r4, #3
	mov r2, sb
_0815446E:
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
	bne _0815448C
	adds r3, #1
	cmp r3, #3
	ble _0815446E
	mov r0, sb
_0815448C:
	movs r3, #0
	mov r6, r8
	strb r0, [r6]
	ldr r1, [sp, #0x4c]
	ldr r0, [r1]
	mov r2, sl
	str r0, [r2]
	ldr r4, [sp, #0x48]
	ldrb r0, [r4]
	mov r5, ip
	strb r0, [r5]
	ldr r6, [sp, #0x5c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x38]
	strb r0, [r1]
	ldr r2, [sp, #0x60]
	ldrb r0, [r2]
	ldr r4, [sp, #0x3c]
	strb r0, [r4]
	ldr r5, [sp, #0x64]
	ldrb r0, [r5]
	ldr r6, [sp, #0x44]
	strb r0, [r6]
	add r0, sp, #0x2c
	ldrb r1, [r0]
	ldr r0, [sp, #0x30]
	strb r1, [r0]
	ldr r1, [sp, #0x54]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x74]
	strb r1, [r4]
	ldr r5, [sp, #0x6c]
	strb r3, [r5]
	ldr r6, [sp, #0x48]
	strb r0, [r6]
	ldr r0, [sp, #0x4c]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x50]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x5c]
	strb r0, [r5]
	ldr r6, [sp, #0x60]
	strb r1, [r6]
	ldr r0, [sp, #0x64]
	strb r2, [r0]
	ldr r2, [sp, #0x7c]
	str r3, [r2]
	ldr r3, [sp, #0x70]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x34]
	strb r0, [r4]
_081544FC:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x78]
	strh r0, [r5]
	movs r0, #0
	b _0815460E
	.align 2, 0
_0815450C: .4byte 0x00000482
_08154510: .4byte 0x0000054F
_08154514: .4byte 0x0000054C
_08154518: .4byte 0x0000054D
_0815451C: .4byte 0x0000054E
_08154520: .4byte 0x00000541
_08154524: .4byte 0x000005BC
_08154528: .4byte 0x00000542
_0815452C: .4byte 0x0203B400
_08154530: .4byte 0x030046B8
_08154534: .4byte 0x000003FF
_08154538:
	mov sb, sp
	ldr r6, _08154574 @ =0x030046A4
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
	beq _08154578
	adds r0, #4
	b _08154582
	.align 2, 0
_08154574: .4byte 0x030046A4
_08154578:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08154582:
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
	ldr r6, _081545BC @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081545C4
	ldr r0, _081545C0 @ =0xFFFFFDFF
	ldr r2, [sp, #0x40]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081545EE
	.align 2, 0
_081545BC: .4byte 0x000004A4
_081545C0: .4byte 0xFFFFFDFF
_081545C4:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081545E4
	cmp r0, #2
	beq _081545E0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081545E0:
	movs r0, #1
	b _081545F0
_081545E4:
	ldr r0, _08154604 @ =0xFFFFFDFF
	ldr r3, [sp, #0x40]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081545EE:
	movs r0, #0
_081545F0:
	cmp r0, #0
	bne _0815460C
	ldr r4, _08154608 @ =0x000005C4
	adds r0, r7, r4
_081545F8:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0815460E
	.align 2, 0
_08154604: .4byte 0xFFFFFDFF
_08154608: .4byte 0x000005C4
_0815460C:
	movs r0, #1
_0815460E:
	cmp r0, #0
	bne _08154694
	ldr r5, _08154644 @ =0x000004A4
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
	bne _0815464C
	ldr r0, _08154648 @ =0xFFFFFDFF
	ldr r2, [sp, #0x40]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08154676
	.align 2, 0
_08154644: .4byte 0x000004A4
_08154648: .4byte 0xFFFFFDFF
_0815464C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0815466C
	cmp r0, #2
	beq _08154668
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08154668:
	movs r0, #1
	b _08154678
_0815466C:
	ldr r0, _0815468C @ =0xFFFFFDFF
	ldr r3, [sp, #0x40]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08154676:
	movs r0, #0
_08154678:
	cmp r0, #0
	bne _08154694
	ldr r4, _08154690 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0815475C
	.align 2, 0
_0815468C: .4byte 0xFFFFFDFF
_08154690: .4byte 0x000005C4
_08154694:
	movs r0, #4
	ldr r5, _081546F4 @ =0x00000222
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
	ldr r4, _081546F8 @ =0x0000046D
	adds r0, r7, r4
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081546FC @ =0x0000046B
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
	ldr r2, _08154700 @ =0x00000469
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _08154704 @ =0x0000046A
	adds r0, r7, r3
	strb r1, [r0]
	adds r6, #0x1c
	adds r0, r7, r6
	str r5, [r0]
	ldr r1, _08154708 @ =0x0000046C
	adds r0, r7, r1
	strb r4, [r0]
	b _0815475C
	.align 2, 0
_081546F4: .4byte 0x00000222
_081546F8: .4byte 0x0000046D
_081546FC: .4byte 0x0000046B
_08154700: .4byte 0x00000469
_08154704: .4byte 0x0000046A
_08154708: .4byte 0x0000046C
_0815470C:
	adds r0, r7, #0
	bl FUN_0815c05c
	ldr r2, _0815476C @ =FUN_081562dc
	movs r1, #0x34
	ldr r3, _08154770 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r5, _08154774 @ =0x0000046B
	adds r0, r7, r5
	strb r4, [r0]
	ldr r6, _08154778 @ =0x00000553
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r1, #0
	strh r4, [r0]
	movs r2, #0x13
	subs r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0815477C @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _08154780 @ =0x00000484
	adds r0, r7, r2
	str r4, [r0]
	ldr r4, _08154784 @ =0x0000046C
	adds r0, r7, r4
	strb r3, [r0]
_0815475C:
	add sp, #0x84
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815476C: .4byte FUN_081562dc
_08154770: .4byte 0x0000046D
_08154774: .4byte 0x0000046B
_08154778: .4byte 0x00000553
_0815477C: .4byte 0x0000046A
_08154780: .4byte 0x00000484
_08154784: .4byte 0x0000046C

	thumb_func_start FUN_08154788
FUN_08154788: @ 0x08154788
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, [r7, #0x44]
	adds r5, r0, #0
	adds r5, #0x48
	ldr r0, _081547A4 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081547A8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081547AA
	.align 2, 0
_081547A4: .4byte 0x0000046D
_081547A8:
	movs r0, #0
_081547AA:
	cmp r0, #0
	beq _081547F2
	movs r0, #0xe9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r1, #0xc7
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r0, [r0]
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r4, #0
	strh r0, [r1]
	ldr r1, _0815486C @ =0x00004040
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r3, r7, r0
	ldr r1, _08154870 @ =0xFDFFFFFF
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	ldr r1, _08154874 @ =0xFFFFFEFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _08154878 @ =0x00000494
	adds r0, r7, r1
	strh r4, [r0]
_081547F2:
	ldrh r0, [r5, #8]
	cmp r0, #2
	bne _0815480E
	ldrh r1, [r5, #0xe]
	ldrb r2, [r5, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _0815480E
	cmp r2, #1
	beq _0815480E
	movs r0, #0
	strh r0, [r5, #0xe]
_0815480E:
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r5, r7, r2
	ldrh r0, [r5]
	subs r0, #0x1e
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bhi _0815484C
	movs r3, #0
	ldrsh r0, [r5, r3]
	movs r1, #0x1e
	bl Mod
	adds r4, r0, #0
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r1, #0xa
	bl Div
	movs r1, #0xf
	subs r1, r1, r0
	cmp r4, r1
	bge _0815484C
	movs r0, #0x20
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0815484C:
	movs r5, #0x83
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r3, #0x85
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _0815487C
	asrs r0, r0, #2
	b _08154882
	.align 2, 0
_0815486C: .4byte 0x00004040
_08154870: .4byte 0xFDFFFFFF
_08154874: .4byte 0xFFFFFEFF
_08154878: .4byte 0x00000494
_0815487C:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08154882:
	adds r3, r0, #0
	movs r1, #0x84
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r5, #0
	ldrsh r2, [r0, r5]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _081548A2
	asrs r0, r0, #2
	b _081548A8
_081548A2:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081548A8:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _081548B2
	movs r3, #0xc8
	b _081548BC
_081548B2:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _081548BC
	adds r3, r0, #0
_081548BC:
	cmp r2, #0xc8
	ble _081548C4
	movs r2, #0xc8
	b _081548CE
_081548C4:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _081548CE
	adds r2, r0, #0
_081548CE:
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
	bne _081548F2
	cmp r2, #0
	bne _081548F2
	movs r0, #1
	b _081548F4
_081548F2:
	movs r0, #0
_081548F4:
	cmp r0, #0
	beq _081549A2
	movs r0, #0xc9
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bgt _081549A2
	movs r6, #0
	movs r5, #0
	strh r5, [r1]
	ldr r3, _081549A8 @ =0x0000046B
	adds r0, r7, r3
	movs r4, #1
	strb r4, [r0]
	ldrb r0, [r7, #5]
	lsrs r0, r0, #5
	adds r0, #7
	movs r1, #7
	ands r0, r1
	ldr r2, _081549AC @ =0x000001DD
	adds r1, r7, r2
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_080e499c
	ldr r0, _081549B0 @ =0x000001D3
	bl PlaySound_082406e0
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r0, _081549B4 @ =0xFFFF5FF8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r7, #0
	movs r1, #6
	bl FUN_0815c934
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	bl FUN_08161b90
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _081549B8 @ =0x00000469
	adds r0, r7, r3
	strb r4, [r0]
	ldr r1, _081549BC @ =0x0000046A
	adds r0, r7, r1
	strb r6, [r0]
	adds r2, #0x1c
	adds r0, r7, r2
	str r5, [r0]
	adds r3, #3
	adds r0, r7, r3
	strb r4, [r0]
	ldr r2, _081549C0 @ =FUN_08153af4
	movs r1, #0xf
	adds r3, #1
	adds r0, r7, r3
	strb r4, [r0]
	subs r3, #2
	adds r0, r7, r3
	strb r6, [r0]
	adds r3, #0xe8
	adds r0, r7, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
_081549A2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081549A8: .4byte 0x0000046B
_081549AC: .4byte 0x000001DD
_081549B0: .4byte 0x000001D3
_081549B4: .4byte 0xFFFF5FF8
_081549B8: .4byte 0x00000469
_081549BC: .4byte 0x0000046A
_081549C0: .4byte FUN_08153af4

	thumb_func_start FUN_081549c4
FUN_081549c4: @ 0x081549C4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r0, [r6, #0x44]
	adds r4, r0, #0
	adds r4, #0x48
	ldr r0, _081549E4 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081549E8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081549EA
	.align 2, 0
_081549E4: .4byte 0x0000046D
_081549E8:
	movs r0, #0
_081549EA:
	cmp r0, #0
	beq _08154A4A
	adds r0, r6, #0
	movs r1, #0xa
	bl FUN_080ef86c
	ldr r2, _08154B58 @ =0x0000046E
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
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
	adds r0, r6, #0
	bl FUN_080e8360
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r1, _08154B5C @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_08154A4A:
	adds r0, r6, #0
	bl FUN_080e499c
	adds r0, r6, #0
	bl FUN_080e4b3c
	adds r0, r6, #0
	bl FUN_080e4e20
	cmp r5, #0x22
	bgt _08154A64
	movs r0, #0
	strh r0, [r4, #0xe]
_08154A64:
	ldrh r0, [r4, #8]
	cmp r0, #7
	bne _08154A86
	ldrh r1, [r4, #0xe]
	cmp r1, #4
	bne _08154A86
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r6, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08154A86
	movs r0, #0xe9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08154A86:
	ldr r7, _08154B58 @ =0x0000046E
	adds r0, r6, r7
	ldrb r0, [r0]
	cmp r0, #0
	bne _08154A92
	b _08154C1C
_08154A92:
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r6, r1
	bl FUN_080136b4
	movs r1, #0x80
	lsls r1, r1, #3
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r4, [r0]
	ands r4, r1
	cmp r4, #0
	bne _08154ABE
	b _08154BF4
_08154ABE:
	ldr r3, _08154B60 @ =0x0000046B
	adds r0, r6, r3
	movs r4, #1
	strb r4, [r0]
	adds r0, r6, #0
	bl FUN_080e6658
	movs r7, #0xcd
	lsls r7, r7, #1
	adds r2, r6, r7
	ldrh r0, [r2]
	cmp r0, #0
	beq _08154B2E
	movs r1, #8
	ldrsh r0, [r6, r1]
	str r0, [sp]
	movs r3, #0xa
	ldrsh r0, [r6, r3]
	str r0, [sp, #4]
	movs r7, #0xc
	ldrsh r0, [r6, r7]
	str r0, [sp, #8]
	movs r1, #0xce
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r3, #0xd0
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [sp, #0x10]
	movs r7, #0xd2
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r6]
	str r0, [sp, #0x1c]
	ldr r1, _08154B64 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r3, sp
	str r3, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_08154B2E:
	ldr r7, _08154B68 @ =0x000001DF
	adds r0, r6, r7
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _08154B70
	ldr r0, _08154B6C @ =0x030046A0
	ldr r2, [r0]
	movs r7, #0xe2
	lsls r7, r7, #2
	adds r2, r2, r7
	adds r1, r4, #0
	lsls r1, r3
	b _08154B82
	.align 2, 0
_08154B58: .4byte 0x0000046E
_08154B5C: .4byte 0xFFEFFFFF
_08154B60: .4byte 0x0000046B
_08154B64: .4byte 0xFFFF0000
_08154B68: .4byte 0x000001DF
_08154B6C: .4byte 0x030046A0
_08154B70:
	ldr r0, _08154BE0 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_08154B82:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r5, #0
	movs r2, #0
	strh r2, [r0]
	ldr r4, _08154BE4 @ =FUN_080e48d0
	movs r3, #0x10
	ldr r7, _08154BE8 @ =0x0000046D
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
	ldr r4, _08154BEC @ =0x00000469
	adds r0, r6, r4
	strb r5, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _08154BF0 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	b _08154C1C
	.align 2, 0
_08154BE0: .4byte 0x030046A0
_08154BE4: .4byte FUN_080e48d0
_08154BE8: .4byte 0x0000046D
_08154BEC: .4byte 0x00000469
_08154BF0: .4byte 0x00000484
_08154BF4:
	ldr r3, _08154C24 @ =FUN_08154c30
	movs r2, #0x31
	ldr r7, _08154C28 @ =0x0000046D
	adds r1, r6, r7
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08154C2C @ =0x0000046B
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
_08154C1C:
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08154C24: .4byte FUN_08154c30
_08154C28: .4byte 0x0000046D
_08154C2C: .4byte 0x0000046B

	thumb_func_start FUN_08154c30
FUN_08154c30: @ 0x08154C30
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	adds r6, r0, #0
	adds r4, r1, #0
	bl FUN_080e499c
	adds r0, r6, #0
	bl FUN_080e4b3c
	adds r0, r6, #0
	bl FUN_080e4e20
	cmp r4, #0x2a
	ble _08154C6C
	adds r0, r4, #0
	movs r1, #6
	bl Mod
	cmp r0, #0
	bne _08154C8E
	adds r0, r6, #0
	adds r0, #8
	str r0, [sp]
	movs r0, #1
	movs r1, #1
	movs r2, #0
	movs r3, #0x20
	bl FUN_08015c90
	b _08154C8E
_08154C6C:
	cmp r4, #0x34
	ble _08154C8E
	adds r0, r4, #0
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _08154C8E
	adds r0, r6, #0
	adds r0, #8
	str r0, [sp]
	movs r0, #1
	movs r1, #1
	movs r2, #0
	movs r3, #0x20
	bl FUN_08015c90
_08154C8E:
	cmp r4, #0x30
	bne _08154CA0
	adds r0, r6, #0
	movs r1, #6
	bl FUN_0815c934
	ldr r0, _08154D4C @ =0x000001CB
	bl PlaySound_082406e0
_08154CA0:
	ldr r0, [r6, #0x44]
	adds r1, r4, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08154CB4
	b _08154DCC
_08154CB4:
	ldr r1, _08154D50 @ =0x0000046B
	adds r0, r6, r1
	movs r4, #1
	strb r4, [r0]
	adds r0, r6, #0
	bl FUN_080e6658
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _08154D24
	movs r7, #8
	ldrsh r0, [r6, r7]
	str r0, [sp, #4]
	movs r1, #0xa
	ldrsh r0, [r6, r1]
	str r0, [sp, #8]
	movs r3, #0xc
	ldrsh r0, [r6, r3]
	str r0, [sp, #0xc]
	movs r7, #0xce
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0x10]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [sp, #0x18]
	movs r7, #0x94
	lsls r7, r7, #3
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	ldrh r0, [r6]
	str r0, [sp, #0x20]
	ldr r1, _08154D54 @ =0xFFFF0000
	ldr r0, [sp, #0x24]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x24]
	add r1, sp, #0x24
	add r0, sp, #4
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_08154D24:
	ldr r1, _08154D58 @ =0x000001DF
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _08154D60
	ldr r0, _08154D5C @ =0x030046A0
	ldr r2, [r0]
	movs r7, #0xe2
	lsls r7, r7, #2
	adds r2, r2, r7
	adds r1, r4, #0
	lsls r1, r3
	b _08154D72
	.align 2, 0
_08154D4C: .4byte 0x000001CB
_08154D50: .4byte 0x0000046B
_08154D54: .4byte 0xFFFF0000
_08154D58: .4byte 0x000001DF
_08154D5C: .4byte 0x030046A0
_08154D60:
	ldr r0, _08154DD4 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_08154D72:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r5, #0
	movs r2, #0
	strh r2, [r0]
	ldr r4, _08154DD8 @ =FUN_080e48d0
	movs r3, #0x10
	ldr r7, _08154DDC @ =0x0000046D
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
	ldr r4, _08154DE0 @ =0x00000469
	adds r0, r6, r4
	strb r5, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _08154DE4 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r1, [r0]
_08154DCC:
	add sp, #0x2c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08154DD4: .4byte 0x030046A0
_08154DD8: .4byte FUN_080e48d0
_08154DDC: .4byte 0x0000046D
_08154DE0: .4byte 0x00000469
_08154DE4: .4byte 0x00000484

	thumb_func_start FUN_08154de8
FUN_08154de8: @ 0x08154DE8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08154E08 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08154E0C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08154E0E
	.align 2, 0
_08154E08: .4byte 0x0000046D
_08154E0C:
	movs r0, #0
_08154E0E:
	cmp r0, #0
	beq _08154EBC
	adds r0, r5, #0
	movs r1, #0xe
	bl FUN_080ef86c
	movs r1, #8
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08154E2E
	movs r0, #1
	b _08154E30
_08154E2E:
	movs r0, #0
_08154E30:
	cmp r0, #0
	beq _08154EB4
	ldr r0, _08154E58 @ =0x00000482
	adds r1, r5, r0
	movs r0, #2
	strh r0, [r1]
	ldr r1, _08154E5C @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08154E60
	ldr r0, _08154E58 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08154E70
	.align 2, 0
_08154E58: .4byte 0x00000482
_08154E5C: .4byte 0x0000A02F
_08154E60:
	ldr r1, _08154E94 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08154E70
	movs r0, #1
	strh r0, [r2]
_08154E70:
	ldr r1, _08154E98 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08154E9C
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
	b _08154EB4
	.align 2, 0
_08154E94: .4byte 0x00000482
_08154E98: .4byte 0x0000025D
_08154E9C:
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
_08154EB4:
	ldr r2, _08154EE0 @ =0x000006C4
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
_08154EBC:
	ldr r1, _08154EE4 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08154EC8
	b _08155014
_08154EC8:
	movs r2, #8
	movs r0, #0xe0
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _08154EE8
	movs r0, #1
	b _08154EEA
	.align 2, 0
_08154EE0: .4byte 0x000006C4
_08154EE4: .4byte 0x0000046E
_08154EE8:
	movs r0, #0
_08154EEA:
	cmp r0, #0
	beq _08154F54
	ldr r3, _08154F40 @ =FUN_0815502c
	movs r1, #0x2d
	ldr r2, _08154F44 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _08154F48 @ =0x0000046B
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
	ldr r1, _08154F4C @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _08154F50 @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	b _08155014
	.align 2, 0
_08154F40: .4byte FUN_0815502c
_08154F44: .4byte 0x0000046D
_08154F48: .4byte 0x0000046B
_08154F4C: .4byte 0x00000469
_08154F50: .4byte 0x0000046C
_08154F54:
	movs r1, #1
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08154F62
	movs r0, #1
	b _08154F64
_08154F62:
	movs r0, #0
_08154F64:
	adds r4, r0, #0
	cmp r4, #0
	beq _08154FC8
	ldr r3, _08154FBC @ =FUN_081551a8
	movs r1, #0x29
	ldr r6, _08154FC0 @ =0x0000046D
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
	movs r1, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08154FC4 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	b _08155014
	.align 2, 0
_08154FBC: .4byte FUN_081551a8
_08154FC0: .4byte 0x0000046D
_08154FC4: .4byte 0x0000046A
_08154FC8:
	ldr r3, _0815501C @ =FUN_08155304
	movs r1, #0x22
	ldr r2, _08155020 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #1
	strb r2, [r0]
	ldr r6, _08155024 @ =0x0000046B
	adds r0, r5, r6
	strb r4, [r0]
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
	strh r4, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08155028 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r4, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r2, [r0]
_08155014:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0815501C: .4byte FUN_08155304
_08155020: .4byte 0x0000046D
_08155024: .4byte 0x0000046B
_08155028: .4byte 0x00000469

	thumb_func_start FUN_0815502c
FUN_0815502c: @ 0x0815502C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r7, r1, #0
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x48
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08155054 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08155058
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0815505A
	.align 2, 0
_08155054: .4byte 0x0000046D
_08155058:
	movs r0, #0
_0815505A:
	cmp r0, #0
	beq _0815506E
	adds r0, r5, #0
	movs r1, #0x11
	bl FUN_080ef86c
	ldr r0, _081550A0 @ =0x00000482
	adds r1, r5, r0
	movs r0, #2
	strh r0, [r1]
_0815506E:
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08155082
	ldrh r0, [r4, #0xe]
	cmp r0, #0
	bne _08155082
	movs r0, #0xea
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08155082:
	ldr r1, _081550A4 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081550A8
	ldr r0, _081550A0 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081550B8
	.align 2, 0
_081550A0: .4byte 0x00000482
_081550A4: .4byte 0x0000A02F
_081550A8:
	ldr r1, _081550DC @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081550B8
	movs r0, #1
	strh r0, [r2]
_081550B8:
	ldr r1, _081550E0 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081550E4
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
	b _081550FC
	.align 2, 0
_081550DC: .4byte 0x00000482
_081550E0: .4byte 0x0000025D
_081550E4:
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
_081550FC:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r1, r6, r2
	adds r0, r7, #0
	adds r0, #0x2a
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	movs r3, #0xc
	bl FUN_08159fc0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815518A
	ldr r6, _08155194 @ =0x0000046E
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0815518A
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0
	bl FUN_0815a2a8
	ldr r3, _08155198 @ =FUN_081557a0
	movs r1, #0x24
	ldr r2, _0815519C @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	subs r6, #3
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
	ldr r1, _081551A0 @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _081551A4 @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
_0815518A:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08155194: .4byte 0x0000046E
_08155198: .4byte FUN_081557a0
_0815519C: .4byte 0x0000046D
_081551A0: .4byte 0x00000469
_081551A4: .4byte 0x0000046C

	thumb_func_start FUN_081551a8
FUN_081551a8: @ 0x081551A8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r7, r1, #0
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x48
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _081551D0 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081551D4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081551D6
	.align 2, 0
_081551D0: .4byte 0x0000046D
_081551D4:
	movs r0, #0
_081551D6:
	cmp r0, #0
	beq _081551E8
	adds r0, r5, #0
	movs r1, #0x11
	bl FUN_080ef86c
	adds r0, r5, #0
	bl FUN_0815a558
_081551E8:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0815520C
	ldrh r0, [r4, #0xe]
	cmp r0, #0
	bne _0815520C
	movs r0, #0xea
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0815520C:
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r1, r6, r2
	adds r0, r7, #0
	adds r0, #0x12
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	movs r3, #2
	bl FUN_08159fc0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081552E6
	movs r7, #0xdf
	lsls r7, r7, #1
	adds r0, r5, r7
	ldrh r1, [r0]
	ldr r2, _08155254 @ =0x000006CA
	adds r0, r6, r2
	strh r1, [r0]
	ldr r7, _08155258 @ =0x0000046E
	adds r0, r5, r7
	ldrb r0, [r0]
	cmp r0, #0
	beq _081552E6
	adds r0, r5, #0
	bl FUN_08159dd0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815525C
	adds r0, r5, #0
	bl FUN_081618f8
	b _08155262
	.align 2, 0
_08155254: .4byte 0x000006CA
_08155258: .4byte 0x0000046E
_0815525C:
	adds r0, r5, #0
	bl FUN_08161ea8
_08155262:
	ldr r3, _081552F0 @ =FUN_08155658
	movs r1, #0x2a
	ldr r2, _081552F4 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r7, _081552F8 @ =0x0000046B
	adds r0, r5, r7
	strb r2, [r0]
	adds r7, #0xe8
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r3, #0
	strh r2, [r0]
	movs r1, #3
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _081552FC @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r7, #2
	adds r0, r5, r7
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _08155300 @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	add r3, sp, #4
	adds r4, r5, #0
	adds r4, #8
	movs r7, #0xd6
	lsls r7, r7, #3
	adds r2, r6, r7
	ldrh r0, [r2]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	adds r1, r3, #0
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	adds r0, r3, #0
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #4
	ldrsh r1, [r3, r2]
	bl FUN_0823785c
	strb r0, [r5, #5]
_081552E6:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081552F0: .4byte FUN_08155658
_081552F4: .4byte 0x0000046D
_081552F8: .4byte 0x0000046B
_081552FC: .4byte 0x00000469
_08155300: .4byte 0x0000046C

	thumb_func_start FUN_08155304
FUN_08155304: @ 0x08155304
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r7, r0, #0
	adds r5, r1, #0
	ldr r0, [r7, #0x44]
	adds r6, r0, #0
	adds r6, #0x48
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r4, [r0]
	ldr r2, _08155334 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08155338
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0815533A
	.align 2, 0
_08155334: .4byte 0x0000046D
_08155338:
	movs r0, #0
_0815533A:
	cmp r0, #0
	beq _08155348
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0815a2a8
_08155348:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r1, r4, r0
	adds r0, r5, #6
	str r0, [sp]
	adds r0, r7, #0
	movs r2, #0
	movs r3, #2
	bl FUN_08159fc0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08155394
	adds r0, r7, #0
	movs r1, #0x10
	bl FUN_080ef86c
	ldrh r0, [r6, #8]
	cmp r0, #0
	beq _08155382
	b _08155558
_08155382:
	ldrh r0, [r6, #0xe]
	cmp r0, #0
	beq _0815538A
	b _08155558
_0815538A:
	movs r0, #0xea
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _08155558
_08155394:
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r2, _0815544C @ =0x000006CA
	adds r0, r4, r2
	movs r2, #0
	movs r4, #0
	strh r1, [r0]
	ldr r1, _08155450 @ =FUN_08155570
	movs r0, #0x23
	ldr r3, _08155454 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0xc]
	movs r3, #1
	ldr r5, [sp, #0xc]
	strb r3, [r5]
	ldr r5, _08155458 @ =0x0000046B
	adds r5, r7, r5
	str r5, [sp, #0x10]
	strb r2, [r5]
	ldr r5, _0815545C @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x14]
	strb r0, [r5]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r0, r7
	mov ip, r0
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r1, r7
	mov sl, r1
	strh r4, [r1]
	movs r0, #0xf
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sb, r5
	strb r2, [r5]
	ldr r1, _08155460 @ =0x00000469
	adds r1, r1, r7
	mov r8, r1
	strb r2, [r1]
	ldr r2, _08155464 @ =0x0000046A
	adds r6, r7, r2
	strb r0, [r6]
	ldr r0, _08155468 @ =0x00000484
	adds r5, r7, r0
	str r4, [r5]
	ldr r1, _0815546C @ =0x0000046C
	adds r4, r7, r1
	strb r3, [r4]
	add r3, sp, #4
	adds r0, r7, #0
	adds r0, #0x9c
	ldr r2, [r0, #8]
	ldrh r1, [r2]
	adds r0, r3, #0
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r3, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x18]
	mov r0, ip
	str r0, [sp, #0x28]
	str r5, [sp, #0x2c]
	str r4, [sp, #0x20]
	cmp r2, #0
	blt _08155448
	cmp r1, #0
	blt _08155448
	ldr r0, _08155470 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08155448
	ldr r0, _08155474 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08155478
_08155448:
	movs r4, #0
	b _08155486
	.align 2, 0
_0815544C: .4byte 0x000006CA
_08155450: .4byte FUN_08155570
_08155454: .4byte 0x0000046D
_08155458: .4byte 0x0000046B
_0815545C: .4byte 0x00000553
_08155460: .4byte 0x00000469
_08155464: .4byte 0x0000046A
_08155468: .4byte 0x00000484
_0815546C: .4byte 0x0000046C
_08155470: .4byte 0x030046A8
_08155474: .4byte 0x030046AC
_08155478:
	ldr r0, _0815549C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08155486:
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #0x30]
	bl FUN_08234224
	ldr r3, [sp, #0x30]
	cmp r0, #0
	beq _081554A0
	adds r0, #4
	b _081554AC
	.align 2, 0
_0815549C: .4byte 0x030046A4
_081554A0:
	ldr r0, _081554C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081554AC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081554C4
	cmp r2, #2
	beq _081554C8
	b _081554CC
	.align 2, 0
_081554C0: .4byte 0x030046A4
_081554C4:
	ldrb r0, [r3, #4]
	b _081554CA
_081554C8:
	ldrb r0, [r3]
_081554CA:
	subs r1, r1, r0
_081554CC:
	strh r1, [r3, #2]
	ldr r1, _081554F0 @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	add r2, sp, #4
	bl FUN_0823599c
	cmp r0, #0
	bne _081554F4
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	b _0815551A
	.align 2, 0
_081554F0: .4byte 0x000004A4
_081554F4:
	adds r0, r4, #0
	adds r1, r5, #0
	add r2, sp, #4
	bl FUN_08235f40
	cmp r0, #0
	beq _08155514
	cmp r0, #2
	beq _08155510
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08155510:
	movs r0, #1
	b _08155524
_08155514:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
_0815551A:
	ldr r1, _08155568 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08155524:
	adds r3, r0, #0
	cmp r3, #0
	bne _08155558
	ldr r0, _0815556C @ =FUN_080e48d0
	movs r2, #1
	ldr r4, [sp, #0x24]
	strb r2, [r4]
	ldr r5, [sp, #0x1c]
	strb r3, [r5]
	ldr r1, [sp, #0x18]
	strb r3, [r1]
	ldr r4, [sp, #0x28]
	str r0, [r4]
	movs r1, #0
	mov r5, sl
	strh r3, [r5]
	movs r0, #3
	mov r4, sb
	strb r0, [r4]
	mov r5, r8
	strb r1, [r5]
	strb r1, [r6]
	ldr r0, [sp, #0x2c]
	str r3, [r0]
	ldr r1, [sp, #0x20]
	strb r2, [r1]
_08155558:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08155568: .4byte 0xFFFFFDFF
_0815556C: .4byte FUN_080e48d0

	thumb_func_start FUN_08155570
FUN_08155570: @ 0x08155570
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x44]
	adds r6, r0, #0
	adds r6, #0x48
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _08155594 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08155598
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0815559A
	.align 2, 0
_08155594: .4byte 0x0000046D
_08155598:
	movs r0, #0
_0815559A:
	cmp r0, #0
	beq _081555BC
	ldr r6, _081555B8 @ =0x000006E6
	adds r1, r5, r6
	movs r0, #1
	strh r0, [r1]
	movs r2, #4
	movs r0, #0xe0
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08155644
	.align 2, 0
_081555B8: .4byte 0x000006E6
_081555BC:
	adds r0, r4, #0
	movs r1, #0x11
	bl FUN_080ef86c
	ldrh r0, [r6, #8]
	cmp r0, #0
	bne _081555D6
	ldrh r0, [r6, #0xe]
	cmp r0, #0
	bne _081555D6
	ldr r0, _081555EC @ =0x000001D1
	bl PlaySound_082406e0
_081555D6:
	movs r1, #4
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081555F0
	movs r0, #1
	b _081555F2
	.align 2, 0
_081555EC: .4byte 0x000001D1
_081555F0:
	movs r0, #0
_081555F2:
	adds r5, r0, #0
	cmp r5, #0
	bne _08155644
	ldr r3, _0815564C @ =FUN_081557a0
	movs r1, #0x24
	ldr r6, _08155650 @ =0x0000046D
	adds r0, r4, r6
	movs r2, #1
	strb r2, [r0]
	subs r6, #2
	adds r0, r4, r6
	strb r5, [r0]
	adds r6, #0xe8
	adds r0, r4, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r4, r6
	movs r3, #0
	strh r5, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _08155654 @ =0x00000469
	adds r0, r4, r1
	strb r2, [r0]
	adds r6, #2
	adds r0, r4, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r4, r1
	str r5, [r0]
	adds r6, #2
	adds r0, r4, r6
	strb r2, [r0]
_08155644:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0815564C: .4byte FUN_081557a0
_08155650: .4byte 0x0000046D
_08155654: .4byte 0x00000469

	thumb_func_start FUN_08155658
FUN_08155658: @ 0x08155658
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	mov r8, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _08155680 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08155684
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08155686
	.align 2, 0
_08155680: .4byte 0x0000046D
_08155684:
	movs r0, #0
_08155686:
	cmp r0, #0
	beq _081556F4
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r5, r7, r0
	adds r3, r6, #0
	adds r3, #8
	movs r1, #0xd6
	lsls r1, r1, #3
	adds r2, r7, r1
	ldrh r0, [r2]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	movs r4, #0
	strh r0, [r5]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r2, #0
	ldrsh r0, [r5, r2]
	movs r1, #0xa
	bl Div
	strh r0, [r5]
	ldr r1, _0815572C @ =0x000006AA
	adds r0, r7, r1
	strh r4, [r0]
	ldr r2, _08155730 @ =0x000006AC
	adds r4, r7, r2
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0xa
	bl Div
	strh r0, [r4]
	movs r2, #0
	ldrsh r0, [r5, r2]
	movs r2, #0
	ldrsh r1, [r4, r2]
	bl FUN_0823785c
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r6, #5]
	ldr r0, _08155734 @ =0x000001D5
	bl PlaySound_082406e0
_081556F4:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r1, r7, r2
	mov r0, r8
	adds r0, #0x12
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #1
	movs r3, #4
	bl FUN_08159fc0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08155738
	adds r0, r6, #0
	movs r1, #0x11
	bl FUN_080ef86c
	b _08155782
	.align 2, 0
_0815572C: .4byte 0x000006AA
_08155730: .4byte 0x000006AC
_08155734: .4byte 0x000001D5
_08155738:
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r2, _08155790 @ =0x000006CA
	adds r0, r7, r2
	movs r3, #0
	movs r5, #0
	strh r1, [r0]
	ldr r4, _08155794 @ =FUN_08155964
	movs r2, #0x25
	ldr r0, _08155798 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0815579C @ =0x0000046B
	adds r0, r6, r1
	strb r3, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r5, [r0]
	movs r0, #0xe0
	lsls r0, r0, #3
	adds r2, r7, r0
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_08155782:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08155790: .4byte 0x000006CA
_08155794: .4byte FUN_08155964
_08155798: .4byte 0x0000046D
_0815579C: .4byte 0x0000046B

	thumb_func_start FUN_081557a0
FUN_081557a0: @ 0x081557A0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r5, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _081557C4 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081557C8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081557CA
	.align 2, 0
_081557C4: .4byte 0x0000046D
_081557C8:
	movs r0, #0
_081557CA:
	cmp r0, #0
	beq _081557EA
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0
	bl FUN_0815a2a8
	ldr r0, [r6, #0x44]
	movs r1, #0x1e
	ldrsh r0, [r0, r1]
	movs r1, #0x28
	bl Div
	ldr r2, _08155820 @ =0x000006CC
	adds r1, r4, r2
	strh r0, [r1]
_081557EA:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r1, r4, r2
	adds r0, r5, #0
	adds r0, #0x18
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #1
	movs r3, #4
	bl FUN_08159fc0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08155824
	adds r0, r6, #0
	movs r1, #0x11
	bl FUN_080ef86c
	b _0815585E
	.align 2, 0
_08155820: .4byte 0x000006CC
_08155824:
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r2, _08155868 @ =0x000006CA
	adds r0, r4, r2
	movs r3, #0
	movs r5, #0
	strh r1, [r0]
	ldr r4, _0815586C @ =FUN_08155964
	movs r2, #0x25
	ldr r0, _08155870 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08155874 @ =0x0000046B
	adds r0, r6, r1
	strb r3, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r5, [r0]
_0815585E:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08155868: .4byte 0x000006CA
_0815586C: .4byte FUN_08155964
_08155870: .4byte 0x0000046D
_08155874: .4byte 0x0000046B

	thumb_func_start FUN_08155878
FUN_08155878: @ 0x08155878
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r5, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _0815589C @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081558A0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081558A2
	.align 2, 0
_0815589C: .4byte 0x0000046D
_081558A0:
	movs r0, #0
_081558A2:
	cmp r0, #0
	beq _081558C2
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0
	bl FUN_0815a2a8
	ldr r0, [r6, #0x44]
	movs r1, #0x1e
	ldrsh r0, [r0, r1]
	movs r1, #0x28
	bl Div
	ldr r2, _081558F8 @ =0x000006CC
	adds r1, r4, r2
	strh r0, [r1]
_081558C2:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r1, r4, r2
	adds r0, r5, #0
	adds r0, #0x18
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #1
	movs r3, #4
	bl FUN_08159fc0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081558FC
	adds r0, r6, #0
	movs r1, #0x11
	bl FUN_080ef86c
	b _08155946
	.align 2, 0
_081558F8: .4byte 0x000006CC
_081558FC:
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r2, _08155950 @ =0x000006CA
	adds r0, r4, r2
	movs r3, #0
	movs r5, #0
	strh r1, [r0]
	ldr r4, _08155954 @ =FUN_08155964
	movs r2, #0x25
	ldr r0, _08155958 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0815595C @ =0x0000046B
	adds r0, r6, r1
	strb r3, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r5, [r0]
	ldr r2, _08155960 @ =0x000001DF
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
_08155946:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08155950: .4byte 0x000006CA
_08155954: .4byte FUN_08155964
_08155958: .4byte 0x0000046D
_0815595C: .4byte 0x0000046B
_08155960: .4byte 0x000001DF

	thumb_func_start FUN_08155964
FUN_08155964: @ 0x08155964
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x6c
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _08155990 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08155994
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08155996
	.align 2, 0
_08155990: .4byte 0x0000046D
_08155994:
	movs r0, #0
_08155996:
	cmp r0, #0
	beq _081559CE
	adds r0, r7, #0
	movs r1, #0xf
	bl FUN_080ef86c
	movs r2, #0xe0
	lsls r2, r2, #3
	add r2, sb
	movs r1, #0xa
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r0, _08155AC8 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r2, r7, r4
	ldr r1, _08155ACC @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081559CE:
	ldr r5, _08155AD0 @ =0x0000046E
	adds r0, r7, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _081559DC
	bl _081562CA
_081559DC:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r2, #0x80
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r1, r7, r6
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #0x30]
	cmp r0, #0
	bne _081559F8
	b _08155FF8
_081559F8:
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r2, [r0]
	movs r0, #0x1a
	ldr r3, _08155AD4 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #8]
	movs r1, #0
	movs r3, #1
	ldr r4, [sp, #8]
	strb r3, [r4]
	subs r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xc]
	strb r1, [r5]
	ldr r6, _08155AD8 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x10]
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x14]
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sl, r2
	movs r0, #0
	strh r1, [r2]
	movs r2, #0xc
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	strb r0, [r4]
	ldr r5, _08155ADC @ =0x00000469
	adds r5, r5, r7
	mov r8, r5
	strb r0, [r5]
	ldr r6, _08155AE0 @ =0x0000046A
	adds r6, r7, r6
	str r6, [sp, #0x68]
	strb r2, [r6]
	ldr r0, _08155AE4 @ =0x00000484
	adds r5, r7, r0
	str r1, [r5]
	ldr r1, _08155AE8 @ =0x0000046C
	adds r4, r7, r1
	strb r3, [r4]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r3, r7, r2
	ldr r6, [r3]
	str r6, [sp, #0x18]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #8]
	str r0, [sp, #0x5c]
	ldr r6, [sp, #0xc]
	str r6, [sp, #0x54]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x38]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x3c]
	mov r0, sl
	str r0, [sp, #0x40]
	mov r6, sb
	str r6, [sp, #0x48]
	mov r0, r8
	str r0, [sp, #0x4c]
	ldr r6, [sp, #0x68]
	str r6, [sp, #0x50]
	str r5, [sp, #0x64]
	str r4, [sp, #0x58]
	adds r6, r3, #0
	mov r8, r2
	mov r0, ip
	cmp r0, #0
	blt _08155AC4
	cmp r1, #0
	blt _08155AC4
	ldr r0, _08155AEC @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _08155AC4
	ldr r0, _08155AF0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08155AF4
_08155AC4:
	movs r4, #0
	b _08155B04
	.align 2, 0
_08155AC8: .4byte 0xFFFFFEFF
_08155ACC: .4byte 0xFFEFFFFF
_08155AD0: .4byte 0x0000046E
_08155AD4: .4byte 0x0000046D
_08155AD8: .4byte 0x00000553
_08155ADC: .4byte 0x00000469
_08155AE0: .4byte 0x0000046A
_08155AE4: .4byte 0x00000484
_08155AE8: .4byte 0x0000046C
_08155AEC: .4byte 0x030046A8
_08155AF0: .4byte 0x030046AC
_08155AF4:
	ldr r0, _08155B14 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_08155B04:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08155B18
	adds r0, #4
	b _08155B24
	.align 2, 0
_08155B14: .4byte 0x030046A4
_08155B18:
	ldr r0, _08155B38 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08155B24:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08155B3C
	cmp r2, #2
	beq _08155B42
	b _08155B48
	.align 2, 0
_08155B38: .4byte 0x030046A4
_08155B3C:
	ldr r2, [sp, #0x18]
	ldrb r0, [r2, #4]
	b _08155B46
_08155B42:
	ldr r3, [sp, #0x18]
	ldrb r0, [r3]
_08155B46:
	subs r1, r1, r0
_08155B48:
	ldr r4, [sp, #0x18]
	strh r1, [r4, #2]
	ldr r0, _08155B60 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08155B64
	movs r0, #1
	b _08155B66
	.align 2, 0
_08155B60: .4byte 0x030047A4
_08155B64:
	movs r0, #0
_08155B66:
	cmp r0, #0
	beq _08155BA4
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _08155B86
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08155B82
	adds r2, r0, #0
_08155B82:
	cmp r2, #0
	bge _08155B90
_08155B86:
	ldr r6, _08155B8C @ =0x000005C4
	adds r0, r7, r6
	b _08155FE6
	.align 2, 0
_08155B8C: .4byte 0x000005C4
_08155B90:
	ldr r1, _08155BA0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08155BEC
	.align 2, 0
_08155BA0: .4byte 0x03002BE0
_08155BA4:
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
	blt _08155BD0
	cmp r1, #0
	blt _08155BD0
	ldr r0, _08155BD4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08155BD0
	ldr r0, _08155BD8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08155BDC
_08155BD0:
	movs r5, #0
	b _08155BEA
	.align 2, 0
_08155BD4: .4byte 0x030046A8
_08155BD8: .4byte 0x030046AC
_08155BDC:
	ldr r0, _08155C7C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08155BEA:
	movs r2, #0
_08155BEC:
	ldr r3, _08155C80 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _08155C0C
	ldr r1, _08155C84 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08155C0C
	b _08155F24
_08155C0C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x30]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08155C20
	b _081562CA
_08155C20:
	ldr r5, _08155C88 @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x30]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sl, r2
	cmp r3, #0
	beq _08155C8C
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x5c]
	strb r2, [r3]
	ldr r6, [sp, #0x54]
	strb r5, [r6]
	ldr r3, [sp, #0x38]
	strb r0, [r3]
	ldr r6, [sp, #0x3c]
	str r1, [r6]
	ldr r0, [sp, #0x40]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0x48]
	strb r5, [r1]
	ldr r3, [sp, #0x4c]
	strb r5, [r3]
	ldr r5, [sp, #0x50]
	strb r0, [r5]
	ldr r6, [sp, #0x64]
	str r4, [r6]
	ldr r0, [sp, #0x58]
	strb r2, [r0]
	b _08155DDA
	.align 2, 0
_08155C7C: .4byte 0x030046A4
_08155C80: .4byte 0x00000256
_08155C84: .4byte 0x03002BE0
_08155C88: .4byte 0x00000222
_08155C8C:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x5c]
	strb r0, [r2]
	ldr r4, [sp, #0x54]
	strb r5, [r4]
	ldr r2, [sp, #0x38]
	strb r0, [r2]
	ldr r4, [sp, #0x3c]
	str r1, [r4]
	ldr r1, [sp, #0x40]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x48]
	strb r5, [r2]
	ldr r4, [sp, #0x4c]
	strb r5, [r4]
	ldr r5, [sp, #0x50]
	strb r1, [r5]
	ldr r1, [sp, #0x64]
	str r3, [r1]
	ldr r2, [sp, #0x58]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, r8
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
	blt _08155CF0
	cmp r1, #0
	blt _08155CF0
	ldr r0, _08155CF4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08155CF0
	ldr r0, _08155CF8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08155CFC
_08155CF0:
	movs r4, #0
	b _08155D0A
	.align 2, 0
_08155CF4: .4byte 0x030046A8
_08155CF8: .4byte 0x030046AC
_08155CFC:
	ldr r0, _08155D1C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08155D0A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08155D20
	adds r0, #4
	b _08155D2C
	.align 2, 0
_08155D1C: .4byte 0x030046A4
_08155D20:
	ldr r0, _08155D40 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08155D2C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08155D44
	cmp r2, #2
	beq _08155D48
	b _08155D4C
	.align 2, 0
_08155D40: .4byte 0x030046A4
_08155D44:
	ldrb r0, [r5, #4]
	b _08155D4A
_08155D48:
	ldrb r0, [r5]
_08155D4A:
	subs r1, r1, r0
_08155D4C:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08155D74
	cmp r1, #0
	blt _08155D74
	ldr r0, _08155D78 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08155D74
	ldr r0, _08155D7C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08155D80
_08155D74:
	movs r4, #0
	b _08155D8E
	.align 2, 0
_08155D78: .4byte 0x030046A8
_08155D7C: .4byte 0x030046AC
_08155D80:
	ldr r0, _08155DA0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08155D8E:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08155DA4
	adds r0, #4
	b _08155DB0
	.align 2, 0
_08155DA0: .4byte 0x030046A4
_08155DA4:
	ldr r0, _08155DC4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08155DB0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08155DC8
	cmp r3, #2
	beq _08155DCC
	b _08155DD0
	.align 2, 0
_08155DC4: .4byte 0x030046A4
_08155DC8:
	ldrb r0, [r5, #4]
	b _08155DCE
_08155DCC:
	ldrb r0, [r5]
_08155DCE:
	subs r2, r2, r0
_08155DD0:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_08155DDA:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x30]
	ldrh r0, [r5]
	ands r0, r1
	mov sb, r4
	ldr r6, _08155E04 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x60]
	cmp r0, #0
	bne _08155EE8
	movs r1, #4
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08155E08
	movs r0, #1
	b _08155E0A
	.align 2, 0
_08155E04: .4byte 0x00000482
_08155E08:
	movs r0, #0
_08155E0A:
	ldr r3, _08155EF8 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x60]
	cmp r0, #0
	bne _08155EE8
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r6, _08155EFC @ =0x0000054F
	adds r6, r6, r7
	mov ip, r6
	ldr r0, _08155F00 @ =0x0000054C
	adds r0, r7, r0
	str r0, [sp, #0x28]
	ldr r1, _08155F04 @ =0x0000054D
	adds r1, r7, r1
	str r1, [sp, #0x2c]
	ldr r2, _08155F08 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0x34]
	ldr r4, _08155F0C @ =0x00000541
	adds r4, r7, r4
	str r4, [sp, #0x20]
	ldr r5, _08155F10 @ =0x000005BC
	adds r5, r7, r5
	str r5, [sp, #0x44]
	ldr r6, _08155F14 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0x24]
	ldr r6, _08155F18 @ =0x0203B400
	ldr r1, _08155F1C @ =0x030046B8
	ldr r5, _08155F20 @ =0x000003FF
	movs r4, #3
	mov r2, sb
_08155E5A:
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
	bne _08155E78
	adds r3, #1
	cmp r3, #3
	ble _08155E5A
	mov r0, sb
_08155E78:
	movs r3, #0
	mov r1, r8
	strb r0, [r1]
	ldr r2, [sp, #0x3c]
	ldr r0, [r2]
	mov r4, sl
	str r0, [r4]
	ldr r5, [sp, #0x38]
	ldrb r0, [r5]
	mov r6, ip
	strb r0, [r6]
	ldr r1, [sp, #0x48]
	ldrb r0, [r1]
	ldr r2, [sp, #0x28]
	strb r0, [r2]
	ldr r4, [sp, #0x4c]
	ldrb r0, [r4]
	ldr r5, [sp, #0x2c]
	strb r0, [r5]
	ldr r6, [sp, #0x50]
	ldrb r0, [r6]
	ldr r1, [sp, #0x34]
	strb r0, [r1]
	mov r2, sp
	ldrb r4, [r2, #0x1c]
	ldr r2, [sp, #0x20]
	strb r4, [r2]
	ldr r5, [sp, #0x44]
	ldr r2, [r5]
	movs r0, #0x1b
	movs r1, #1
	ldr r6, [sp, #0x5c]
	strb r1, [r6]
	ldr r4, [sp, #0x54]
	strb r3, [r4]
	ldr r5, [sp, #0x38]
	strb r0, [r5]
	ldr r6, [sp, #0x3c]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x40]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x48]
	strb r0, [r4]
	ldr r5, [sp, #0x4c]
	strb r1, [r5]
	ldr r6, [sp, #0x50]
	strb r2, [r6]
	ldr r0, [sp, #0x64]
	str r3, [r0]
	ldr r2, [sp, #0x58]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x24]
	strb r0, [r3]
_08155EE8:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x60]
	strh r0, [r4]
	b _081562CA
	.align 2, 0
_08155EF8: .4byte 0x00000482
_08155EFC: .4byte 0x0000054F
_08155F00: .4byte 0x0000054C
_08155F04: .4byte 0x0000054D
_08155F08: .4byte 0x0000054E
_08155F0C: .4byte 0x00000541
_08155F10: .4byte 0x000005BC
_08155F14: .4byte 0x00000542
_08155F18: .4byte 0x0203B400
_08155F1C: .4byte 0x030046B8
_08155F20: .4byte 0x000003FF
_08155F24:
	mov sb, sp
	ldr r6, _08155F60 @ =0x030046A4
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
	beq _08155F64
	adds r0, #4
	b _08155F6E
	.align 2, 0
_08155F60: .4byte 0x030046A4
_08155F64:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08155F6E:
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
	ldr r6, _08155FA8 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _08155FB0
	ldr r0, _08155FAC @ =0xFFFFFDFF
	ldr r2, [sp, #0x30]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08155FDA
	.align 2, 0
_08155FA8: .4byte 0x000004A4
_08155FAC: .4byte 0xFFFFFDFF
_08155FB0:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08155FD0
	cmp r0, #2
	beq _08155FCC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08155FCC:
	movs r0, #1
	b _08155FDC
_08155FD0:
	ldr r0, _08155FF0 @ =0xFFFFFDFF
	ldr r3, [sp, #0x30]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08155FDA:
	movs r0, #0
_08155FDC:
	cmp r0, #0
	beq _08155FE2
	b _081562CA
_08155FE2:
	ldr r4, _08155FF4 @ =0x000005C4
	adds r0, r7, r4
_08155FE6:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081562CA
	.align 2, 0
_08155FF0: .4byte 0xFFFFFDFF
_08155FF4: .4byte 0x000005C4
_08155FF8:
	movs r2, #0x20
	movs r1, #0xe0
	lsls r1, r1, #3
	add r1, sb
	ldr r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _0815600E
	movs r0, #1
	b _08156010
_0815600E:
	movs r0, #0
_08156010:
	adds r4, r0, #0
	cmp r4, #0
	beq _08156090
	ldr r3, _08156078 @ =FUN_081562dc
	movs r1, #0x34
	ldr r5, _0815607C @ =0x0000046D
	adds r0, r7, r5
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _08156080 @ =0x0000046B
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
	movs r3, #0x13
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _08156084 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08156088 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _0815608C @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	adds r0, r7, #0
	bl FUN_0815b584
	movs r1, #0x41
	rsbs r1, r1, #0
	mov r6, r8
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	b _081562CA
	.align 2, 0
_08156078: .4byte FUN_081562dc
_0815607C: .4byte 0x0000046D
_08156080: .4byte 0x0000046B
_08156084: .4byte 0x00000469
_08156088: .4byte 0x0000046A
_0815608C: .4byte 0x00000484
_08156090:
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r2, [sp, #0x30]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08156190
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r2, #1
	ldr r5, _08156120 @ =0x0000046D
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _08156124 @ =0x0000046B
	adds r0, r7, r6
	strb r4, [r0]
	subs r3, #0x4d
	adds r0, r7, r3
	strb r2, [r0]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r0, r7, r5
	str r1, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r7, r6
	movs r1, #0
	strh r4, [r0]
	movs r3, #7
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _08156128 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0815612C @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _08156130 @ =0x00000484
	adds r0, r7, r3
	str r4, [r0]
	ldr r4, _08156134 @ =0x0000046C
	adds r0, r7, r4
	strb r2, [r0]
	adds r5, #0x3c
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
	bne _0815613C
	ldr r0, _08156138 @ =0xFFFFFDFF
	ldr r2, [sp, #0x30]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08156166
	.align 2, 0
_08156120: .4byte 0x0000046D
_08156124: .4byte 0x0000046B
_08156128: .4byte 0x00000469
_0815612C: .4byte 0x0000046A
_08156130: .4byte 0x00000484
_08156134: .4byte 0x0000046C
_08156138: .4byte 0xFFFFFDFF
_0815613C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0815615C
	cmp r0, #2
	beq _08156158
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08156158:
	movs r0, #1
	b _08156168
_0815615C:
	ldr r0, _0815618C @ =0xFFFFFDFF
	ldr r3, [sp, #0x30]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08156166:
	movs r0, #0
_08156168:
	cmp r0, #0
	bne _0815616E
	b _08156274
_0815616E:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #6]
	movs r2, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081562CA
	.align 2, 0
_0815618C: .4byte 0xFFFFFDFF
_08156190:
	movs r1, #0x80
	lsls r1, r1, #0xc
	mov r6, r8
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081561A2
	movs r0, #1
	b _081561A4
_081561A2:
	movs r0, #0
_081561A4:
	cmp r0, #0
	bne _081561AA
	b _081562C4
_081561AA:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r3, #1
	ldr r2, _08156224 @ =0x0000046D
	adds r0, r7, r2
	movs r2, #0
	strb r3, [r0]
	ldr r4, _08156228 @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	ldr r5, _0815622C @ =0x00000553
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
	ldr r6, _08156230 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08156234 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _08156238 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x3b
	adds r0, r7, r6
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	ldr r4, _0815623C @ =0x000006F4
	add r4, sb
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08156244
	ldr r0, _08156240 @ =0xFFFFFDFF
	ldr r2, [sp, #0x30]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0815626E
	.align 2, 0
_08156224: .4byte 0x0000046D
_08156228: .4byte 0x0000046B
_0815622C: .4byte 0x00000553
_08156230: .4byte 0x00000469
_08156234: .4byte 0x0000046A
_08156238: .4byte 0x00000484
_0815623C: .4byte 0x000006F4
_08156240: .4byte 0xFFFFFDFF
_08156244:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08156264
	cmp r0, #2
	beq _08156260
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08156260:
	movs r0, #1
	b _08156270
_08156264:
	ldr r0, _0815627C @ =0xFFFFFDFF
	ldr r3, [sp, #0x30]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0815626E:
	movs r0, #0
_08156270:
	cmp r0, #0
	bne _08156280
_08156274:
	adds r0, r7, #0
	bl FUN_0815e9a8
	b _081562CA
	.align 2, 0
_0815627C: .4byte 0xFFFFFDFF
_08156280:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #6]
	movs r2, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r6, _081562B8 @ =0x00000482
	adds r1, r7, r6
	movs r0, #3
	strh r0, [r1]
	ldr r0, _081562BC @ =0x000006F4
	add r0, sb
	movs r1, #8
	bl ClearMemory
	ldr r1, _081562C0 @ =0xFFF7FFFF
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _081562CA
	.align 2, 0
_081562B8: .4byte 0x00000482
_081562BC: .4byte 0x000006F4
_081562C0: .4byte 0xFFF7FFFF
_081562C4:
	adds r0, r7, #0
	bl FUN_0815e9a8
_081562CA:
	add sp, #0x6c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081562dc
FUN_081562dc: @ 0x081562DC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r3, [r0]
	ldr r0, [r4, #0x44]
	adds r6, r0, #0
	adds r6, #0x48
	ldr r2, _08156308 @ =0x00000482
	adds r1, r4, r2
	movs r0, #4
	strh r0, [r1]
	ldr r0, _0815630C @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08156310
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08156312
	.align 2, 0
_08156308: .4byte 0x00000482
_0815630C: .4byte 0x0000046D
_08156310:
	movs r0, #0
_08156312:
	cmp r0, #0
	beq _0815631E
	adds r0, r4, #0
	bl FUN_0815b2a0
	b _0815643A
_0815631E:
	movs r2, #0x40
	movs r0, #0xe0
	lsls r0, r0, #3
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _08156334
	movs r0, #1
	b _08156336
_08156334:
	movs r0, #0
_08156336:
	cmp r0, #0
	beq _0815637E
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r0, _0815638C @ =0x0000FFFF
	cmp r1, r0
	bhi _0815637E
	adds r0, r4, #0
	bl FUN_0815b584
	movs r1, #0x41
	rsbs r1, r1, #0
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	movs r2, #0x13
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _08156390 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
_0815637E:
	movs r1, #2
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08156394
	movs r0, #1
	b _08156396
	.align 2, 0
_0815638C: .4byte 0x0000FFFF
_08156390: .4byte 0x00000484
_08156394:
	movs r0, #0
_08156396:
	cmp r0, #0
	beq _081563D0
	movs r1, #4
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081563A8
	movs r0, #1
	b _081563AA
_081563A8:
	movs r0, #0
_081563AA:
	cmp r0, #0
	beq _08156434
	adds r0, r4, #0
	movs r1, #0x11
	bl FUN_080ef86c
	ldrh r0, [r6, #8]
	cmp r0, #0
	bne _08156434
	ldrh r0, [r6, #0xe]
	cmp r0, #0
	bne _08156434
	ldr r0, _081563CC @ =0x000001D1
	bl PlaySound_082406e0
	b _08156434
	.align 2, 0
_081563CC: .4byte 0x000001D1
_081563D0:
	movs r1, #0x40
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081563DE
	movs r0, #1
	b _081563E0
_081563DE:
	movs r0, #0
_081563E0:
	cmp r0, #0
	beq _0815642C
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	adds r0, r4, #0
	bl FUN_0815b584
	movs r1, #0x41
	rsbs r1, r1, #0
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	movs r2, #0x13
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08156424 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _08156428 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	b _08156434
	.align 2, 0
_08156424: .4byte 0x00000469
_08156428: .4byte 0x00000484
_0815642C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ef86c
_08156434:
	adds r0, r4, #0
	bl FUN_08161bb0
_0815643A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08156440
FUN_08156440: @ 0x08156440
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x88
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r5, [r0]
	ldr r2, _08156468 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0815646C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0815646E
	.align 2, 0
_08156468: .4byte 0x0000046D
_0815646C:
	movs r0, #0
_0815646E:
	cmp r0, #0
	beq _08156486
	ldr r3, _081564C0 @ =0x000006EA
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_0815a5cc
	adds r0, r7, #0
	bl FUN_0815c150
_08156486:
	ldr r4, _081564C4 @ =0x0000046E
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _08156494
	bl _08156E9A
_08156494:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r7, r6
	ldr r0, _081564C8 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r0, _081564C0 @ =0x000006EA
	adds r4, r5, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	str r2, [sp, #0x50]
	cmp r0, #0
	ble _081564CC
	adds r0, r7, #0
	bl FUN_0815c150
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	bl _08156E9A
	.align 2, 0
_081564C0: .4byte 0x000006EA
_081564C4: .4byte 0x0000046E
_081564C8: .4byte 0xFFFFFEFF
_081564CC:
	movs r2, #0x99
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r0, [r0]
	bl FUN_081e9094
	movs r0, #0xe8
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r1, #0x80
	ldr r3, [sp, #0x50]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _081564EE
	b _08156BEC
_081564EE:
	movs r1, #2
	movs r4, #0xe0
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08156502
	movs r0, #1
	b _08156504
_08156502:
	movs r0, #0
_08156504:
	cmp r0, #0
	beq _0815650C
	bl _08156E9A
_0815650C:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
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
	str r3, [sp, #0x80]
	str r2, [sp, #0x84]
	cmp r4, #0
	blt _08156550
	cmp r1, #0
	blt _08156550
	ldr r0, _08156554 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _08156550
	ldr r0, _08156558 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815655C
_08156550:
	movs r4, #0
	b _0815656A
	.align 2, 0
_08156554: .4byte 0x030046A8
_08156558: .4byte 0x030046AC
_0815655C:
	ldr r0, _0815657C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0815656A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08156580
	adds r0, #4
	b _0815658C
	.align 2, 0
_0815657C: .4byte 0x030046A4
_08156580:
	ldr r0, _081565A0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815658C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081565A4
	cmp r2, #2
	beq _081565A8
	b _081565AC
	.align 2, 0
_081565A0: .4byte 0x030046A4
_081565A4:
	ldrb r0, [r5, #4]
	b _081565AA
_081565A8:
	ldrb r0, [r5]
_081565AA:
	subs r1, r1, r0
_081565AC:
	strh r1, [r5, #2]
	ldr r0, _081565C0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081565C4
	movs r0, #1
	b _081565C6
	.align 2, 0
_081565C0: .4byte 0x030047A4
_081565C4:
	movs r0, #0
_081565C6:
	cmp r0, #0
	beq _08156604
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081565E6
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081565E2
	adds r2, r0, #0
_081565E2:
	cmp r2, #0
	bge _081565F0
_081565E6:
	ldr r2, _081565EC @ =0x000005C4
	adds r0, r7, r2
	b _08156B2C
	.align 2, 0
_081565EC: .4byte 0x000005C4
_081565F0:
	ldr r1, _08156600 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0815664C
	.align 2, 0
_08156600: .4byte 0x03002BE0
_08156604:
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
	blt _08156630
	cmp r1, #0
	blt _08156630
	ldr r0, _08156634 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08156630
	ldr r0, _08156638 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815663C
_08156630:
	movs r5, #0
	b _0815664A
	.align 2, 0
_08156634: .4byte 0x030046A8
_08156638: .4byte 0x030046AC
_0815663C:
	ldr r0, _08156684 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0815664A:
	movs r2, #0
_0815664C:
	ldr r4, _08156688 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0815666C
	ldr r1, _0815668C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0815666C
	b _08156A6C
_0815666C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r6, [sp, #0x50]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _08156690
	movs r0, #0
	b _08156B42
	.align 2, 0
_08156684: .4byte 0x030046A4
_08156688: .4byte 0x00000256
_0815668C: .4byte 0x03002BE0
_08156690:
	ldr r0, _08156730 @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x50]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0x5c]
	cmp r6, #0
	beq _08156750
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _08156734 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x10]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _08156738 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x14]
	movs r4, #0
	strb r4, [r3]
	ldr r6, _0815673C @ =0x00000553
	adds r6, r6, r7
	mov r8, r6
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r0, r7
	mov sl, r0
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	mov r2, sb
	strh r2, [r5]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _08156740 @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _08156744 @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _08156748 @ =0x00000484
	adds r1, r7, r0
	mov r6, sb
	str r6, [r1]
	ldr r6, _0815674C @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x10]
	str r6, [sp, #0x74]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x6c]
	mov r6, r8
	str r6, [sp, #0x48]
	mov r6, sl
	str r6, [sp, #0x4c]
	str r5, [sp, #0x58]
	str r4, [sp, #0x60]
	str r3, [sp, #0x64]
	str r2, [sp, #0x68]
	str r1, [sp, #0x7c]
	str r0, [sp, #0x70]
	b _08156922
	.align 2, 0
_08156730: .4byte 0x00000222
_08156734: .4byte 0x0000046D
_08156738: .4byte 0x0000046B
_0815673C: .4byte 0x00000553
_08156740: .4byte 0x00000469
_08156744: .4byte 0x0000046A
_08156748: .4byte 0x00000484
_0815674C: .4byte 0x0000046C
_08156750:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _08156810 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x18]
	strb r0, [r2]
	ldr r3, _08156814 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x1c]
	movs r4, #0
	strb r4, [r3]
	ldr r2, _08156818 @ =0x00000553
	adds r2, r7, r2
	str r2, [sp, #0x20]
	strb r0, [r2]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x24]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r4, r7
	mov r8, r4
	strh r6, [r4]
	movs r1, #5
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x28]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _0815681C @ =0x00000469
	adds r5, r7, r4
	strb r3, [r5]
	ldr r2, _08156820 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _08156824 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _08156828 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x80]
	ldr r0, [r0]
	str r0, [sp, #0x2c]
	ldr r1, [sp, #0x84]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x2c]
	strh r1, [r6]
	ldr r6, [sp, #0x84]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x2c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x74]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0x6c]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x48]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0x4c]
	mov r0, r8
	str r0, [sp, #0x58]
	ldr r6, [sp, #0x28]
	str r6, [sp, #0x60]
	str r5, [sp, #0x64]
	str r4, [sp, #0x68]
	str r3, [sp, #0x7c]
	str r2, [sp, #0x70]
	mov r0, ip
	cmp r0, #0
	blt _0815680C
	cmp r1, #0
	blt _0815680C
	ldr r0, _0815682C @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _0815680C
	ldr r0, _08156830 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08156834
_0815680C:
	movs r4, #0
	b _08156844
	.align 2, 0
_08156810: .4byte 0x0000046D
_08156814: .4byte 0x0000046B
_08156818: .4byte 0x00000553
_0815681C: .4byte 0x00000469
_08156820: .4byte 0x0000046A
_08156824: .4byte 0x00000484
_08156828: .4byte 0x0000046C
_0815682C: .4byte 0x030046A8
_08156830: .4byte 0x030046AC
_08156834:
	ldr r0, _08156854 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_08156844:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08156858
	adds r0, #4
	b _08156864
	.align 2, 0
_08156854: .4byte 0x030046A4
_08156858:
	ldr r0, _08156878 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08156864:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0815687C
	cmp r2, #2
	beq _08156882
	b _08156888
	.align 2, 0
_08156878: .4byte 0x030046A4
_0815687C:
	ldr r2, [sp, #0x2c]
	ldrb r0, [r2, #4]
	b _08156886
_08156882:
	ldr r3, [sp, #0x2c]
	ldrb r0, [r3]
_08156886:
	subs r1, r1, r0
_08156888:
	ldr r4, [sp, #0x2c]
	strh r1, [r4, #2]
	ldr r6, [sp, #0x80]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081568B4
	cmp r1, #0
	blt _081568B4
	ldr r0, _081568B8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081568B4
	ldr r0, _081568BC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081568C0
_081568B4:
	movs r4, #0
	b _081568CE
	.align 2, 0
_081568B8: .4byte 0x030046A8
_081568BC: .4byte 0x030046AC
_081568C0:
	ldr r0, _081568E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081568CE:
	ldr r0, [sp, #0x80]
	ldr r5, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081568E8
	adds r0, #4
	b _081568F4
	.align 2, 0
_081568E4: .4byte 0x030046A4
_081568E8:
	ldr r0, _08156908 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081568F4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0815690C
	cmp r3, #2
	beq _08156910
	b _08156914
	.align 2, 0
_08156908: .4byte 0x030046A4
_0815690C:
	ldrb r0, [r5, #4]
	b _08156912
_08156910:
	ldrb r0, [r5]
_08156912:
	subs r2, r2, r0
_08156914:
	ldr r1, [sp, #0x80]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x80]
	ldr r0, [r2]
	strh r1, [r0, #6]
_08156922:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x30]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x50]
	ldrh r0, [r4]
	ands r0, r1
	mov sb, r3
	ldr r6, _0815694C @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x78]
	cmp r0, #0
	bne _08156A30
	movs r1, #4
	ldr r2, [sp, #0x5c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08156950
	movs r0, #1
	b _08156952
	.align 2, 0
_0815694C: .4byte 0x00000482
_08156950:
	movs r0, #0
_08156952:
	ldr r3, _08156A40 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x78]
	cmp r0, #0
	bne _08156A30
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _08156A44 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _08156A48 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x3c]
	ldr r2, _08156A4C @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x40]
	ldr r4, _08156A50 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x44]
	ldr r6, _08156A54 @ =0x00000541
	adds r6, r7, r6
	str r6, [sp, #0x34]
	ldr r0, _08156A58 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x54]
	ldr r1, _08156A5C @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x38]
	ldr r6, _08156A60 @ =0x0203B400
	ldr r1, _08156A64 @ =0x030046B8
	ldr r5, _08156A68 @ =0x000003FF
	movs r4, #3
	mov r2, sb
_081569A2:
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
	bne _081569C0
	adds r3, #1
	cmp r3, #3
	ble _081569A2
	mov r0, sb
_081569C0:
	movs r3, #0
	mov r2, r8
	strb r0, [r2]
	ldr r4, [sp, #0x4c]
	ldr r0, [r4]
	mov r6, sl
	str r0, [r6]
	ldr r1, [sp, #0x48]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x60]
	ldrb r0, [r4]
	ldr r6, [sp, #0x3c]
	strb r0, [r6]
	ldr r1, [sp, #0x64]
	ldrb r0, [r1]
	ldr r2, [sp, #0x40]
	strb r0, [r2]
	ldr r4, [sp, #0x68]
	ldrb r0, [r4]
	ldr r6, [sp, #0x44]
	strb r0, [r6]
	add r0, sp, #0x30
	ldrb r1, [r0]
	ldr r0, [sp, #0x34]
	strb r1, [r0]
	ldr r1, [sp, #0x54]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x74]
	strb r1, [r4]
	ldr r6, [sp, #0x6c]
	strb r3, [r6]
	ldr r4, [sp, #0x48]
	strb r0, [r4]
	ldr r6, [sp, #0x4c]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x58]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x60]
	strb r0, [r4]
	ldr r6, [sp, #0x64]
	strb r1, [r6]
	ldr r0, [sp, #0x68]
	strb r2, [r0]
	ldr r2, [sp, #0x7c]
	str r3, [r2]
	ldr r3, [sp, #0x70]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x38]
	strb r0, [r4]
_08156A30:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r6, [sp, #0x78]
	strh r0, [r6]
	movs r0, #0
	b _08156B42
	.align 2, 0
_08156A40: .4byte 0x00000482
_08156A44: .4byte 0x0000054F
_08156A48: .4byte 0x0000054C
_08156A4C: .4byte 0x0000054D
_08156A50: .4byte 0x0000054E
_08156A54: .4byte 0x00000541
_08156A58: .4byte 0x000005BC
_08156A5C: .4byte 0x00000542
_08156A60: .4byte 0x0203B400
_08156A64: .4byte 0x030046B8
_08156A68: .4byte 0x000003FF
_08156A6C:
	mov sb, sp
	ldr r6, _08156AA8 @ =0x030046A4
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
	beq _08156AAC
	adds r0, #4
	b _08156AB6
	.align 2, 0
_08156AA8: .4byte 0x030046A4
_08156AAC:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08156AB6:
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
	ldr r1, _08156AF0 @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _08156AF8
	ldr r0, _08156AF4 @ =0xFFFFFDFF
	ldr r2, [sp, #0x50]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08156B22
	.align 2, 0
_08156AF0: .4byte 0x000004A4
_08156AF4: .4byte 0xFFFFFDFF
_08156AF8:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08156B18
	cmp r0, #2
	beq _08156B14
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08156B14:
	movs r0, #1
	b _08156B24
_08156B18:
	ldr r0, _08156B38 @ =0xFFFFFDFF
	ldr r3, [sp, #0x50]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08156B22:
	movs r0, #0
_08156B24:
	cmp r0, #0
	bne _08156B40
	ldr r4, _08156B3C @ =0x000005C4
	adds r0, r7, r4
_08156B2C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _08156B42
	.align 2, 0
_08156B38: .4byte 0xFFFFFDFF
_08156B3C: .4byte 0x000005C4
_08156B40:
	movs r0, #1
_08156B42:
	cmp r0, #0
	bne _08156B48
	b _08156E9A
_08156B48:
	ldr r2, _08156BD0 @ =FUN_080e6794
	movs r1, #0xe
	ldr r6, _08156BD4 @ =0x0000046D
	adds r0, r7, r6
	movs r5, #0
	movs r3, #1
	mov r8, r3
	mov r4, r8
	strb r4, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r5, [r0]
	ldr r3, _08156BD8 @ =0x00000553
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
	mov sb, r2
	movs r1, #0x18
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
	ldr r2, _08156BDC @ =0x00000551
	adds r0, r7, r2
	strb r3, [r0]
	ldr r4, _08156BE0 @ =0x00000552
	adds r0, r7, r4
	mov r6, sb
	strb r6, [r0]
	movs r1, #3
	subs r2, #0xe9
	adds r0, r7, r2
	strb r1, [r0]
	subs r4, #0xe9
	adds r0, r7, r4
	strb r3, [r0]
	ldr r6, _08156BE4 @ =0x0000046A
	adds r0, r7, r6
	strb r3, [r0]
	ldr r1, _08156BE8 @ =0x00000484
	adds r0, r7, r1
	str r5, [r0]
	adds r2, #4
	adds r0, r7, r2
	mov r3, r8
	strb r3, [r0]
	b _08156E9A
	.align 2, 0
_08156BD0: .4byte FUN_080e6794
_08156BD4: .4byte 0x0000046D
_08156BD8: .4byte 0x00000553
_08156BDC: .4byte 0x00000551
_08156BE0: .4byte 0x00000552
_08156BE4: .4byte 0x0000046A
_08156BE8: .4byte 0x00000484
_08156BEC:
	movs r2, #0x20
	movs r4, #0xe0
	lsls r4, r4, #3
	adds r1, r5, r4
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _08156C02
	movs r0, #1
	b _08156C04
_08156C02:
	movs r0, #0
_08156C04:
	cmp r0, #0
	beq _08156CD4
	movs r1, #2
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08156C16
	movs r0, #1
	b _08156C18
_08156C16:
	movs r0, #0
_08156C18:
	mov r8, r0
	cmp r0, #0
	beq _08156C20
	b _08156E9A
_08156C20:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	adds r0, r7, #0
	bl FUN_0815b584
	movs r1, #0x41
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r2, _08156CB4 @ =FUN_080e6794
	movs r1, #0xe
	ldr r6, _08156CB8 @ =0x0000046D
	adds r0, r7, r6
	movs r3, #1
	mov sb, r3
	mov r4, sb
	strb r4, [r0]
	subs r6, #2
	adds r0, r7, r6
	mov r3, r8
	strb r3, [r0]
	ldr r4, _08156CBC @ =0x00000553
	adds r0, r7, r4
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r3, #0
	mov r2, r8
	strh r2, [r0]
	ldr r4, _08156CC0 @ =FUN_081562dc
	movs r5, #0x13
	movs r1, #0x18
	subs r6, #0x20
	adds r2, r7, r6
	subs r6, #4
	adds r0, r7, r6
	str r1, [r0]
	str r4, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r3, [r0]
	ldr r2, _08156CC4 @ =0x00000551
	adds r0, r7, r2
	strb r3, [r0]
	ldr r4, _08156CC8 @ =0x00000552
	adds r0, r7, r4
	strb r5, [r0]
	movs r1, #3
	subs r6, #0xec
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08156CCC @ =0x00000469
	adds r0, r7, r1
	strb r3, [r0]
	subs r2, #0xe7
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _08156CD0 @ =0x00000484
	adds r0, r7, r3
	mov r4, r8
	str r4, [r0]
	adds r6, #4
	adds r0, r7, r6
	mov r1, sb
	b _08156E98
	.align 2, 0
_08156CB4: .4byte FUN_080e6794
_08156CB8: .4byte 0x0000046D
_08156CBC: .4byte 0x00000553
_08156CC0: .4byte FUN_081562dc
_08156CC4: .4byte 0x00000551
_08156CC8: .4byte 0x00000552
_08156CCC: .4byte 0x00000469
_08156CD0: .4byte 0x00000484
_08156CD4:
	movs r1, #2
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08156CE2
	movs r0, #1
	b _08156CE4
_08156CE2:
	movs r0, #0
_08156CE4:
	cmp r0, #0
	beq _08156CEA
	b _08156E9A
_08156CEA:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	add r5, sp, #8
	adds r0, r7, #0
	adds r0, #0x9c
	ldr r1, [r0, #8]
	ldrh r0, [r1]
	strh r0, [r5]
	ldrh r1, [r1, #2]
	strh r1, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r6, r5, #0
	cmp r2, #0
	blt _08156D24
	cmp r1, #0
	blt _08156D24
	ldr r0, _08156D28 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08156D24
	ldr r0, _08156D2C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08156D30
_08156D24:
	movs r4, #0
	b _08156D3E
	.align 2, 0
_08156D28: .4byte 0x030046A8
_08156D2C: .4byte 0x030046AC
_08156D30:
	ldr r0, _08156D50 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08156D3E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08156D54
	adds r0, #4
	b _08156D60
	.align 2, 0
_08156D50: .4byte 0x030046A4
_08156D54:
	ldr r0, _08156D74 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08156D60:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08156D78
	cmp r2, #2
	beq _08156D7C
	b _08156D80
	.align 2, 0
_08156D74: .4byte 0x030046A4
_08156D78:
	ldrb r0, [r5, #4]
	b _08156D7E
_08156D7C:
	ldrb r0, [r5]
_08156D7E:
	subs r1, r1, r0
_08156D80:
	strh r1, [r5, #2]
	ldrh r0, [r7, #0xa]
	strh r0, [r6, #2]
	ldr r2, _08156DAC @ =0x000004A4
	adds r0, r7, r2
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08156DB4
	ldr r0, _08156DB0 @ =0xFFFFFDFF
	ldr r3, [sp, #0x50]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	b _08156DDE
	.align 2, 0
_08156DAC: .4byte 0x000004A4
_08156DB0: .4byte 0xFFFFFDFF
_08156DB4:
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08156DD4
	cmp r0, #2
	beq _08156DD0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08156DD0:
	movs r0, #1
	b _08156DE0
_08156DD4:
	ldr r0, _08156DF4 @ =0xFFFFFDFF
	ldr r4, [sp, #0x50]
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_08156DDE:
	movs r0, #0
_08156DE0:
	cmp r0, #0
	bne _08156DFC
	ldr r6, _08156DF8 @ =0x000005C4
	adds r0, r7, r6
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _08156E9A
	.align 2, 0
_08156DF4: .4byte 0xFFFFFDFF
_08156DF8: .4byte 0x000005C4
_08156DFC:
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r4, #0
	movs r2, #0
	mov sb, r2
	movs r3, #1
	mov r8, r3
	movs r0, #1
	strh r0, [r1, #6]
	movs r2, #0x10
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _08156EAC @ =FUN_080e6794
	movs r1, #0xe
	ldr r3, _08156EB0 @ =0x0000046D
	adds r0, r7, r3
	mov r6, r8
	strb r6, [r0]
	subs r3, #2
	adds r0, r7, r3
	strb r4, [r0]
	ldr r6, _08156EB4 @ =0x00000553
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	mov r3, sb
	strh r3, [r0]
	adds r6, #0x4d
	adds r0, r7, r6
	ldr r3, [r0]
	movs r5, #7
	movs r1, #0x18
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	subs r6, #0x4c
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _08156EB8 @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _08156EBC @ =0x00000552
	adds r0, r7, r3
	strb r5, [r0]
	movs r1, #3
	subs r6, #0xec
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08156EC0 @ =0x00000469
	adds r0, r7, r1
	strb r4, [r0]
	subs r2, #0xe7
	adds r0, r7, r2
	strb r4, [r0]
	subs r3, #0xce
	adds r0, r7, r3
	mov r4, sb
	str r4, [r0]
	adds r6, #4
	adds r0, r7, r6
	mov r1, r8
_08156E98:
	strb r1, [r0]
_08156E9A:
	add sp, #0x88
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08156EAC: .4byte FUN_080e6794
_08156EB0: .4byte 0x0000046D
_08156EB4: .4byte 0x00000553
_08156EB8: .4byte 0x00000551
_08156EBC: .4byte 0x00000552
_08156EC0: .4byte 0x00000469

	thumb_func_start FUN_08156ec4
FUN_08156ec4: @ 0x08156EC4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r0, [r6, #0x44]
	adds r0, #0x48
	mov r8, r0
	ldrb r0, [r6, #5]
	lsrs r2, r0, #5
	ldr r3, _08156F14 @ =0x000006BA
	adds r0, r5, r3
	movs r4, #0
	ldrsh r3, [r0, r4]
	subs r0, r3, r2
	lsls r4, r0, #5
	cmp r4, #0x80
	ble _08156EF2
	ldr r7, _08156F18 @ =0xFFFFFF00
	adds r4, r4, r7
_08156EF2:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r4, r0
	bge _08156F00
	movs r0, #0x80
	lsls r0, r0, #1
	adds r4, r4, r0
_08156F00:
	ldr r1, _08156F1C @ =0x0000046D
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	beq _08156F20
	movs r0, #0
	strb r0, [r7]
	movs r0, #1
	b _08156F22
	.align 2, 0
_08156F14: .4byte 0x000006BA
_08156F18: .4byte 0xFFFFFF00
_08156F1C: .4byte 0x0000046D
_08156F20:
	movs r0, #0
_08156F22:
	cmp r0, #0
	bne _08156F28
	b _08157098
_08156F28:
	cmp r2, r3
	bne _08156FA8
	ldr r2, _08156F90 @ =0x0000054F
	adds r0, r6, r2
	ldrb r2, [r0]
	movs r3, #0xa9
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r3, [r0]
	movs r1, #0
	movs r5, #1
	strb r5, [r7]
	ldr r4, _08156F94 @ =0x0000046B
	adds r0, r6, r4
	strb r1, [r0]
	ldr r7, _08156F98 @ =0x00000553
	adds r0, r6, r7
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
	adds r4, #0xe1
	adds r0, r6, r4
	ldrb r2, [r0]
	subs r7, #6
	adds r0, r6, r7
	ldrb r3, [r0]
	adds r4, #2
	adds r0, r6, r4
	ldrb r4, [r0]
	subs r7, #0xe5
	adds r0, r6, r7
	strb r2, [r0]
	ldr r2, _08156F9C @ =0x00000469
	adds r0, r6, r2
	strb r3, [r0]
	ldr r3, _08156FA0 @ =0x0000046A
	adds r0, r6, r3
	strb r4, [r0]
	ldr r4, _08156FA4 @ =0x00000484
	adds r0, r6, r4
	str r1, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	b _08157258
	.align 2, 0
_08156F90: .4byte 0x0000054F
_08156F94: .4byte 0x0000046B
_08156F98: .4byte 0x00000553
_08156F9C: .4byte 0x00000469
_08156FA0: .4byte 0x0000046A
_08156FA4: .4byte 0x00000484
_08156FA8:
	cmp r4, #0
	blt _08157020
	cmp r2, #7
	bhi _08157098
	lsls r0, r2, #2
	ldr r1, _08156FBC @ =_08156FC0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08156FBC: .4byte _08156FC0
_08156FC0: @ jump table
	.4byte _08156FE0 @ case 0
	.4byte _08156FEA @ case 1
	.4byte _08156FF0 @ case 2
	.4byte _08156FF6 @ case 3
	.4byte _08156FFC @ case 4
	.4byte _08157002 @ case 5
	.4byte _0815700C @ case 6
	.4byte _08157016 @ case 7
_08156FE0:
	adds r0, r6, #0
	movs r1, #0x16
	bl FUN_080efe38
	b _08157098
_08156FEA:
	adds r0, r6, #0
	movs r1, #0x17
	b _0815707E
_08156FF0:
	adds r0, r6, #0
	movs r1, #0x18
	b _0815707E
_08156FF6:
	adds r0, r6, #0
	movs r1, #0x19
	b _0815707E
_08156FFC:
	adds r0, r6, #0
	movs r1, #0x1a
	b _0815707E
_08157002:
	adds r0, r6, #0
	movs r1, #0x13
	bl FUN_080efe38
	b _08157098
_0815700C:
	adds r0, r6, #0
	movs r1, #0x14
	bl FUN_080efe38
	b _08157098
_08157016:
	adds r0, r6, #0
	movs r1, #0x15
	bl FUN_080efe38
	b _08157098
_08157020:
	cmp r2, #7
	bhi _08157098
	lsls r0, r2, #2
	ldr r1, _08157030 @ =_08157034
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08157030: .4byte _08157034
_08157034: @ jump table
	.4byte _08157054 @ case 0
	.4byte _0815705E @ case 1
	.4byte _08157068 @ case 2
	.4byte _0815706E @ case 3
	.4byte _08157074 @ case 4
	.4byte _0815707A @ case 5
	.4byte _08157086 @ case 6
	.4byte _08157090 @ case 7
_08157054:
	adds r0, r6, #0
	movs r1, #0x18
	bl FUN_080efe38
	b _08157098
_0815705E:
	adds r0, r6, #0
	movs r1, #0x17
	bl FUN_080efe38
	b _08157098
_08157068:
	adds r0, r6, #0
	movs r1, #0x16
	b _0815707E
_0815706E:
	adds r0, r6, #0
	movs r1, #0x15
	b _0815707E
_08157074:
	adds r0, r6, #0
	movs r1, #0x14
	b _0815707E
_0815707A:
	adds r0, r6, #0
	movs r1, #0x13
_0815707E:
	movs r2, #1
	bl FUN_080efb60
	b _08157098
_08157086:
	adds r0, r6, #0
	movs r1, #0x1a
	bl FUN_080efe38
	b _08157098
_08157090:
	adds r0, r6, #0
	movs r1, #0x19
	bl FUN_080efe38
_08157098:
	mov r1, r8
	ldrh r0, [r1, #8]
	cmp r0, #2
	bne _081570B6
	ldrh r0, [r1, #0xe]
	cmp r0, #0
	bne _081570B6
	cmp r4, #0
	bge _081570B0
	ldrb r0, [r6, #5]
	subs r0, #0x20
	b _081570B4
_081570B0:
	ldrb r0, [r6, #5]
	adds r0, #0x20
_081570B4:
	strb r0, [r6, #5]
_081570B6:
	ldr r2, _0815711C @ =0x0000046E
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081570C2
	b _08157258
_081570C2:
	ldrb r0, [r6, #5]
	lsrs r0, r0, #5
	ldr r3, _08157120 @ =0x000006BA
	adds r1, r5, r3
	movs r4, #0
	ldrsh r1, [r1, r4]
	cmp r1, r0
	beq _08157138
	ldr r4, _08157124 @ =FUN_08156ec4
	movs r1, #0x2c
	movs r2, #0
	movs r3, #1
	strb r3, [r7]
	ldr r5, _08157128 @ =0x0000046B
	adds r0, r6, r5
	strb r2, [r0]
	ldr r7, _0815712C @ =0x00000553
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	movs r4, #0
	strh r2, [r0]
	movs r1, #3
	subs r5, #3
	adds r0, r6, r5
	strb r1, [r0]
	subs r7, #0xea
	adds r0, r6, r7
	strb r3, [r0]
	ldr r1, _08157130 @ =0x0000046A
	adds r0, r6, r1
	strb r4, [r0]
	ldr r4, _08157134 @ =0x00000484
	adds r0, r6, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r6, r5
	strb r3, [r0]
	b _08157258
	.align 2, 0
_0815711C: .4byte 0x0000046E
_08157120: .4byte 0x000006BA
_08157124: .4byte FUN_08156ec4
_08157128: .4byte 0x0000046B
_0815712C: .4byte 0x00000553
_08157130: .4byte 0x0000046A
_08157134: .4byte 0x00000484
_08157138:
	movs r0, #0xd8
	lsls r0, r0, #3
	adds r1, r5, r0
	ldrh r0, [r1]
	subs r0, #1
	movs r2, #0
	mov ip, r2
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _081571CC
	ldr r3, _081571B4 @ =0x0000054F
	adds r0, r6, r3
	ldrb r2, [r0]
	movs r4, #0xa9
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r3, [r0]
	movs r4, #1
	strb r4, [r7]
	ldr r5, _081571B8 @ =0x0000046B
	adds r1, r6, r5
	movs r0, #0
	strb r0, [r1]
	ldr r7, _081571BC @ =0x00000553
	adds r0, r6, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	mov r3, ip
	strh r3, [r0]
	adds r5, #0xe1
	adds r0, r6, r5
	ldrb r1, [r0]
	subs r7, #6
	adds r0, r6, r7
	ldrb r2, [r0]
	ldr r3, _081571C0 @ =0x0000054E
	adds r0, r6, r3
	ldrb r3, [r0]
	subs r5, #0xe4
	adds r0, r6, r5
	strb r1, [r0]
	subs r7, #0xe4
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _081571C4 @ =0x0000046A
	adds r0, r6, r1
	strb r3, [r0]
	ldr r2, _081571C8 @ =0x00000484
	adds r0, r6, r2
	mov r3, ip
	str r3, [r0]
	adds r5, #4
	adds r0, r6, r5
	strb r4, [r0]
	b _08157258
	.align 2, 0
_081571B4: .4byte 0x0000054F
_081571B8: .4byte 0x0000046B
_081571BC: .4byte 0x00000553
_081571C0: .4byte 0x0000054E
_081571C4: .4byte 0x0000046A
_081571C8: .4byte 0x00000484
_081571CC:
	ldr r1, _081571F8 @ =0x000006BE
	adds r0, r5, r1
	ldrb r0, [r0]
	ldrb r2, [r6, #5]
	subs r1, r0, r2
	cmp r1, #0x80
	ble _081571DE
	ldr r3, _081571FC @ =0xFFFFFF00
	adds r1, r1, r3
_081571DE:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081571EC
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r1, r4
_081571EC:
	cmp r1, #0
	bge _08157200
	adds r0, r2, #0
	adds r0, #0xe0
	b _08157204
	.align 2, 0
_081571F8: .4byte 0x000006BE
_081571FC: .4byte 0xFFFFFF00
_08157200:
	adds r0, r2, #0
	adds r0, #0x20
_08157204:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsrs r1, r0, #5
	ldr r2, _08157264 @ =0x000006BA
	adds r0, r5, r2
	movs r4, #0
	movs r5, #0
	strh r1, [r0]
	ldr r3, _08157268 @ =FUN_08156ec4
	movs r1, #0x2c
	movs r2, #1
	strb r2, [r7]
	ldr r7, _0815726C @ =0x0000046B
	adds r0, r6, r7
	strb r4, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r5, [r0]
	movs r1, #3
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _08157270 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r3, _08157274 @ =0x0000046A
	adds r0, r6, r3
	strb r4, [r0]
	ldr r4, _08157278 @ =0x00000484
	adds r0, r6, r4
	str r5, [r0]
	ldr r5, _0815727C @ =0x0000046C
	adds r0, r6, r5
	strb r2, [r0]
_08157258:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08157264: .4byte 0x000006BA
_08157268: .4byte FUN_08156ec4
_0815726C: .4byte 0x0000046B
_08157270: .4byte 0x00000469
_08157274: .4byte 0x0000046A
_08157278: .4byte 0x00000484
_0815727C: .4byte 0x0000046C

	thumb_func_start FUN_08157280
FUN_08157280: @ 0x08157280
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, _08157298 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0815729C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0815729E
	.align 2, 0
_08157298: .4byte 0x0000046D
_0815729C:
	movs r0, #0
_0815729E:
	cmp r0, #0
	beq _081572C2
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r0, #0x80
	lsls r0, r0, #3
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _08157348 @ =0x00000482
	adds r1, r6, r2
	movs r0, #2
	strh r0, [r1]
_081572C2:
	ldr r3, _0815734C @ =0x00000542
	adds r5, r6, r3
	ldrb r1, [r5]
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	ble _081573BC
	cmp r4, #0x1e
	bgt _081572D6
	b _08157438
_081572D6:
	movs r1, #3
	movs r2, #1
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	movs r3, #0
	strb r1, [r0]
	ldr r7, _08157350 @ =0x00000469
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _08157354 @ =0x0000046A
	adds r0, r6, r1
	strb r3, [r0]
	adds r4, #0x1c
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #3
	adds r0, r6, r7
	strb r2, [r0]
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r4, [r0]
	movs r1, #2
	adds r7, #1
	adds r0, r6, r7
	strb r2, [r0]
	ldr r2, _08157358 @ =0x0000046B
	adds r0, r6, r2
	strb r3, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r3, [r0]
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #1
	bne _08157360
	ldr r3, _0815735C @ =0x00000541
	adds r0, r6, r3
	ldrb r0, [r0]
	lsrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r4, #0xee
	lsls r4, r4, #1
	adds r1, r6, r4
	b _0815739C
	.align 2, 0
_08157348: .4byte 0x00000482
_0815734C: .4byte 0x00000542
_08157350: .4byte 0x00000469
_08157354: .4byte 0x0000046A
_08157358: .4byte 0x0000046B
_0815735C: .4byte 0x00000541
_08157360:
	movs r1, #0
	ldrb r4, [r6, #5]
	ldr r7, _081573AC @ =0x0203B400
	mov ip, r7
	ldr r2, _081573B0 @ =0x030046B8
	ldr r7, _081573B4 @ =0x000003FF
	movs r5, #3
	adds r3, r4, #0
_08157370:
	ldr r0, [r2]
	adds r0, #1
	ands r0, r7
	str r0, [r2]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	ands r0, r5
	lsls r0, r0, #6
	cmp r0, r3
	bne _0815738E
	adds r1, #1
	cmp r1, #3
	ble _08157370
	adds r0, r4, #0
_0815738E:
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r6, r2
_0815739C:
	strb r0, [r1]
	ldr r3, _081573B8 @ =0x00000542
	adds r1, r6, r3
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _08157438
	.align 2, 0
_081573AC: .4byte 0x0203B400
_081573B0: .4byte 0x030046B8
_081573B4: .4byte 0x000003FF
_081573B8: .4byte 0x00000542
_081573BC:
	movs r0, #0xff
	orrs r0, r1
	strb r0, [r5]
	cmp r4, #0xf
	ble _08157438
	ldr r4, _08157440 @ =0x0000054F
	adds r0, r6, r4
	ldrb r2, [r0]
	movs r7, #0xa9
	lsls r7, r7, #3
	adds r0, r6, r7
	ldr r3, [r0]
	ldr r1, _08157444 @ =0x0000046D
	adds r0, r6, r1
	movs r1, #0
	movs r5, #1
	strb r5, [r0]
	subs r4, #0xe4
	adds r0, r6, r4
	strb r1, [r0]
	adds r7, #0xb
	adds r0, r6, r7
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
	adds r4, #0xe1
	adds r0, r6, r4
	ldrb r2, [r0]
	subs r7, #6
	adds r0, r6, r7
	ldrb r3, [r0]
	adds r4, #2
	adds r0, r6, r4
	ldrb r4, [r0]
	subs r7, #0xe5
	adds r0, r6, r7
	strb r2, [r0]
	ldr r2, _08157448 @ =0x00000469
	adds r0, r6, r2
	strb r3, [r0]
	ldr r3, _0815744C @ =0x0000046A
	adds r0, r6, r3
	strb r4, [r0]
	ldr r4, _08157450 @ =0x00000484
	adds r0, r6, r4
	str r1, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, _08157454 @ =0xFFFFFBFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08157438:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08157440: .4byte 0x0000054F
_08157444: .4byte 0x0000046D
_08157448: .4byte 0x00000469
_0815744C: .4byte 0x0000046A
_08157450: .4byte 0x00000484
_08157454: .4byte 0xFFFFFBFF

	thumb_func_start FUN_08157458
FUN_08157458: @ 0x08157458
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08161fac
	adds r0, r4, #0
	bl FUN_081621cc
	adds r0, r4, #0
	bl FUN_08162240
	adds r0, r4, #0
	bl FUN_08162298
	movs r0, #0xdc
	lsls r0, r0, #3
	adds r4, r4, r0
	ldrh r1, [r4]
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0
	ble _08157486
	subs r0, r1, #1
	strh r0, [r4]
_08157486:
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08157490
FUN_08157490: @ 0x08157490
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0815e868
	adds r0, r4, #0
	bl FUN_0815f4ac
	adds r0, r4, #0
	bl FUN_0816231c
	adds r0, r4, #0
	bl FUN_08159ab0
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081574b4
FUN_081574b4: @ 0x081574B4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081574CC @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081574D0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081574D2
	.align 2, 0
_081574CC: .4byte 0x0000046C
_081574D0:
	movs r0, #0
_081574D2:
	cmp r0, #0
	beq _08157550
	ldr r4, _08157564 @ =FUN_08153864
	movs r3, #0xa
	ldr r2, _08157568 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0815756C @ =0x0000046B
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
	ldr r2, _08157570 @ =0x000001DF
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _08157534
	movs r0, #4
	ldr r1, _08157574 @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08157534:
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
_08157550:
	ldr r1, _0815756C @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08157578
	adds r0, r5, #0
	bl FUN_0815a69c
	b _08157582
	.align 2, 0
_08157564: .4byte FUN_08153864
_08157568: .4byte 0x0000046D
_0815756C: .4byte 0x0000046B
_08157570: .4byte 0x000001DF
_08157574: .4byte 0x00000222
_08157578:
	ldr r2, _08157588 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08157582:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08157588: .4byte 0x00000484

	thumb_func_start FUN_0815758c
FUN_0815758c: @ 0x0815758C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x60
	adds r7, r0, #0
	ldr r0, _081576F0 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081575A8
	movs r0, #0
	strb r0, [r1]
_081575A8:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081575C0
	bl _08157DE4
_081575C0:
	adds r0, r7, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _081575D2
	bl _08157DE4
_081575D2:
	ldr r2, _081576F4 @ =0x00000484
	adds r1, r7, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _081575E0
	bl FUN_08157de0
_081575E0:
	ldr r3, _081576F8 @ =0x000001DF
	adds r0, r7, r3
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
	movs r0, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #8]
	strb r0, [r4]
	ldr r5, _081576FC @ =0x00000469
	adds r5, r7, r5
	str r5, [sp, #0xc]
	movs r0, #1
	strb r0, [r5]
	ldr r1, _08157700 @ =0x0000046A
	adds r1, r7, r1
	str r1, [sp, #0x10]
	strb r6, [r1]
	ldr r2, _081576F4 @ =0x00000484
	adds r2, r2, r7
	mov sl, r2
	str r6, [r2]
	ldr r3, _081576F0 @ =0x0000046C
	adds r3, r3, r7
	mov ip, r3
	strb r0, [r3]
	ldr r1, _08157704 @ =FUN_080e6794
	movs r0, #0xe
	ldr r4, _08157708 @ =0x0000046D
	adds r4, r4, r7
	mov sb, r4
	movs r5, #1
	strb r5, [r4]
	ldr r2, _0815770C @ =0x0000046B
	adds r2, r2, r7
	mov r8, r2
	strb r6, [r2]
	ldr r3, _08157710 @ =0x00000553
	adds r5, r7, r3
	strb r0, [r5]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r4, r7, r0
	str r1, [r4]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r3, r7, r1
	strh r6, [r3]
	movs r0, #0x80
	subs r1, #0x48
	adds r2, r7, r1
	ldrh r1, [r2]
	ands r1, r0
	mov r0, ip
	str r0, [sp, #0x50]
	ldr r0, [sp, #8]
	str r0, [sp, #0x40]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x44]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x48]
	mov r0, sl
	str r0, [sp, #0x5c]
	mov r0, sb
	str r0, [sp, #0x54]
	mov r0, r8
	str r0, [sp, #0x4c]
	str r5, [sp, #0x2c]
	str r4, [sp, #0x34]
	str r3, [sp, #0x30]
	mov sl, r2
	cmp r1, #0
	bne _0815767E
	b _08157C18
_0815767E:
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x1e
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
	movs r2, #0
	strb r2, [r0]
	ldr r3, _08157714 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
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
	mov r8, r2
	cmp r4, #0
	blt _081576EA
	cmp r1, #0
	blt _081576EA
	ldr r0, _08157718 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081576EA
	ldr r0, _0815771C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08157720
_081576EA:
	movs r4, #0
	b _0815772E
	.align 2, 0
_081576F0: .4byte 0x0000046C
_081576F4: .4byte 0x00000484
_081576F8: .4byte 0x000001DF
_081576FC: .4byte 0x00000469
_08157700: .4byte 0x0000046A
_08157704: .4byte FUN_080e6794
_08157708: .4byte 0x0000046D
_0815770C: .4byte 0x0000046B
_08157710: .4byte 0x00000553
_08157714: .4byte 0x00000551
_08157718: .4byte 0x030046A8
_0815771C: .4byte 0x030046AC
_08157720:
	ldr r0, _08157740 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0815772E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08157744
	adds r0, #4
	b _08157750
	.align 2, 0
_08157740: .4byte 0x030046A4
_08157744:
	ldr r0, _08157764 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08157750:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08157768
	cmp r2, #2
	beq _0815776C
	b _08157770
	.align 2, 0
_08157764: .4byte 0x030046A4
_08157768:
	ldrb r0, [r5, #4]
	b _0815776E
_0815776C:
	ldrb r0, [r5]
_0815776E:
	subs r1, r1, r0
_08157770:
	strh r1, [r5, #2]
	ldr r0, _08157784 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08157788
	movs r0, #1
	b _0815778A
	.align 2, 0
_08157784: .4byte 0x030047A4
_08157788:
	movs r0, #0
_0815778A:
	cmp r0, #0
	beq _081577C8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081577AA
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081577A6
	adds r2, r0, #0
_081577A6:
	cmp r2, #0
	bge _081577B4
_081577AA:
	ldr r2, _081577B0 @ =0x000005C4
	adds r0, r7, r2
	b _08157C06
	.align 2, 0
_081577B0: .4byte 0x000005C4
_081577B4:
	ldr r1, _081577C4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08157810
	.align 2, 0
_081577C4: .4byte 0x03002BE0
_081577C8:
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
	blt _081577F4
	cmp r1, #0
	blt _081577F4
	ldr r0, _081577F8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081577F4
	ldr r0, _081577FC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08157800
_081577F4:
	movs r5, #0
	b _0815780E
	.align 2, 0
_081577F8: .4byte 0x030046A8
_081577FC: .4byte 0x030046AC
_08157800:
	ldr r0, _081578A0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0815780E:
	movs r2, #0
_08157810:
	ldr r4, _081578A4 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _08157830
	ldr r1, _081578A8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08157830
	b _08157B44
_08157830:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08157844
	b _08157DE4
_08157844:
	ldr r0, _081578AC @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, sl
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	str r2, [sp, #0x38]
	cmp r3, #0
	beq _081578B0
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x54]
	strb r2, [r3]
	ldr r3, [sp, #0x4c]
	strb r5, [r3]
	ldr r3, [sp, #0x2c]
	strb r0, [r3]
	ldr r0, [sp, #0x34]
	str r1, [r0]
	ldr r1, [sp, #0x30]
	strh r4, [r1]
	movs r0, #0xc
	ldr r3, [sp, #0x40]
	strb r5, [r3]
	ldr r1, [sp, #0x44]
	strb r5, [r1]
	ldr r3, [sp, #0x48]
	strb r0, [r3]
	ldr r5, [sp, #0x5c]
	str r4, [r5]
	ldr r0, [sp, #0x50]
	strb r2, [r0]
	b _081579FE
	.align 2, 0
_081578A0: .4byte 0x030046A4
_081578A4: .4byte 0x00000256
_081578A8: .4byte 0x03002BE0
_081578AC: .4byte 0x00000222
_081578B0:
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
	ldr r4, [sp, #0x34]
	str r1, [r4]
	ldr r1, [sp, #0x30]
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
	mov r3, r8
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
	blt _08157914
	cmp r1, #0
	blt _08157914
	ldr r0, _08157918 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08157914
	ldr r0, _0815791C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08157920
_08157914:
	movs r4, #0
	b _0815792E
	.align 2, 0
_08157918: .4byte 0x030046A8
_0815791C: .4byte 0x030046AC
_08157920:
	ldr r0, _08157940 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0815792E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08157944
	adds r0, #4
	b _08157950
	.align 2, 0
_08157940: .4byte 0x030046A4
_08157944:
	ldr r0, _08157964 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08157950:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08157968
	cmp r2, #2
	beq _0815796C
	b _08157970
	.align 2, 0
_08157964: .4byte 0x030046A4
_08157968:
	ldrb r0, [r5, #4]
	b _0815796E
_0815796C:
	ldrb r0, [r5]
_0815796E:
	subs r1, r1, r0
_08157970:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08157998
	cmp r1, #0
	blt _08157998
	ldr r0, _0815799C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08157998
	ldr r0, _081579A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081579A4
_08157998:
	movs r4, #0
	b _081579B2
	.align 2, 0
_0815799C: .4byte 0x030046A8
_081579A0: .4byte 0x030046AC
_081579A4:
	ldr r0, _081579C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081579B2:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081579C8
	adds r0, #4
	b _081579D4
	.align 2, 0
_081579C4: .4byte 0x030046A4
_081579C8:
	ldr r0, _081579E8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081579D4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081579EC
	cmp r3, #2
	beq _081579F0
	b _081579F4
	.align 2, 0
_081579E8: .4byte 0x030046A4
_081579EC:
	ldrb r0, [r5, #4]
	b _081579F2
_081579F0:
	ldrb r0, [r5]
_081579F2:
	subs r2, r2, r0
_081579F4:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081579FE:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x14]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov sb, r4
	adds r1, #0x82
	adds r1, r7, r1
	str r1, [sp, #0x58]
	cmp r0, #0
	bne _08157B08
	movs r1, #4
	ldr r2, [sp, #0x38]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08157A28
	movs r0, #1
	b _08157A2A
_08157A28:
	movs r0, #0
_08157A2A:
	ldr r3, _08157B18 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x58]
	cmp r0, #0
	bne _08157B08
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r0, _08157B1C @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _08157B20 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x20]
	ldr r2, _08157B24 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x24]
	ldr r4, _08157B28 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x28]
	ldr r5, _08157B2C @ =0x00000541
	adds r5, r7, r5
	str r5, [sp, #0x18]
	ldr r0, _08157B30 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x3c]
	ldr r1, _08157B34 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x1c]
	ldr r6, _08157B38 @ =0x0203B400
	ldr r1, _08157B3C @ =0x030046B8
	ldr r5, _08157B40 @ =0x000003FF
	movs r2, #3
	mov r4, sb
_08157A7A:
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
	bne _08157A98
	adds r3, #1
	cmp r3, #3
	ble _08157A7A
	mov r0, sb
_08157A98:
	movs r3, #0
	mov r2, r8
	strb r0, [r2]
	ldr r4, [sp, #0x34]
	ldr r0, [r4]
	mov r5, sl
	str r0, [r5]
	ldr r1, [sp, #0x2c]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x40]
	ldrb r0, [r4]
	ldr r5, [sp, #0x20]
	strb r0, [r5]
	ldr r1, [sp, #0x44]
	ldrb r0, [r1]
	ldr r2, [sp, #0x24]
	strb r0, [r2]
	ldr r4, [sp, #0x48]
	ldrb r0, [r4]
	ldr r5, [sp, #0x28]
	strb r0, [r5]
	mov r0, sp
	ldrb r1, [r0, #0x14]
	ldr r0, [sp, #0x18]
	strb r1, [r0]
	ldr r4, [sp, #0x3c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x54]
	strb r1, [r5]
	ldr r4, [sp, #0x4c]
	strb r3, [r4]
	ldr r5, [sp, #0x2c]
	strb r0, [r5]
	ldr r0, [sp, #0x34]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x30]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x40]
	strb r0, [r5]
	ldr r0, [sp, #0x44]
	strb r1, [r0]
	ldr r4, [sp, #0x48]
	strb r2, [r4]
	ldr r5, [sp, #0x5c]
	str r3, [r5]
	ldr r0, [sp, #0x50]
	strb r1, [r0]
	movs r0, #6
	ldr r1, [sp, #0x1c]
	strb r0, [r1]
_08157B08:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r2, [sp, #0x58]
	strh r0, [r2]
	b _08157DE4
	.align 2, 0
_08157B18: .4byte 0x00000482
_08157B1C: .4byte 0x0000054F
_08157B20: .4byte 0x0000054C
_08157B24: .4byte 0x0000054D
_08157B28: .4byte 0x0000054E
_08157B2C: .4byte 0x00000541
_08157B30: .4byte 0x000005BC
_08157B34: .4byte 0x00000542
_08157B38: .4byte 0x0203B400
_08157B3C: .4byte 0x030046B8
_08157B40: .4byte 0x000003FF
_08157B44:
	mov sb, sp
	ldr r6, _08157B80 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
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
	beq _08157B84
	adds r0, #4
	b _08157B8E
	.align 2, 0
_08157B80: .4byte 0x030046A4
_08157B84:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08157B8E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r3, sb
	strh r0, [r3, #2]
	mov r4, r8
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	ldr r5, _08157BC8 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _08157BD0
	ldr r0, _08157BCC @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08157BFA
	.align 2, 0
_08157BC8: .4byte 0x000004A4
_08157BCC: .4byte 0xFFFFFDFF
_08157BD0:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08157BF0
	cmp r0, #2
	beq _08157BEC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08157BEC:
	movs r0, #1
	b _08157BFC
_08157BF0:
	ldr r0, _08157C10 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08157BFA:
	movs r0, #0
_08157BFC:
	cmp r0, #0
	beq _08157C02
	b _08157DE4
_08157C02:
	ldr r4, _08157C14 @ =0x000005C4
	adds r0, r7, r4
_08157C06:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _08157DE4
	.align 2, 0
_08157C10: .4byte 0xFFFFFDFF
_08157C14: .4byte 0x000005C4
_08157C18:
	movs r1, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08157C2A
	b _08157DA2
_08157C2A:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x1e
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
	movs r2, #0
	strb r2, [r0]
	ldr r3, _08157C94 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	subs r1, #0xa8
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
	cmp r2, #0
	blt _08157C90
	cmp r1, #0
	blt _08157C90
	ldr r0, _08157C98 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08157C90
	ldr r0, _08157C9C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08157CA0
_08157C90:
	movs r4, #0
	b _08157CAE
	.align 2, 0
_08157C94: .4byte 0x00000551
_08157C98: .4byte 0x030046A8
_08157C9C: .4byte 0x030046AC
_08157CA0:
	ldr r0, _08157CC0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08157CAE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08157CC4
	adds r0, #4
	b _08157CD0
	.align 2, 0
_08157CC0: .4byte 0x030046A4
_08157CC4:
	ldr r0, _08157CE4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08157CD0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08157CE8
	cmp r2, #2
	beq _08157CEC
	b _08157CF0
	.align 2, 0
_08157CE4: .4byte 0x030046A4
_08157CE8:
	ldrb r0, [r5, #4]
	b _08157CEE
_08157CEC:
	ldrb r0, [r5]
_08157CEE:
	subs r1, r1, r0
_08157CF0:
	strh r1, [r5, #2]
	ldr r2, _08157D20 @ =0x000004A4
	adds r0, r7, r2
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08157D28
	ldr r0, _08157D24 @ =0xFFFFFDFF
	mov r4, sl
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	b _08157D52
	.align 2, 0
_08157D20: .4byte 0x000004A4
_08157D24: .4byte 0xFFFFFDFF
_08157D28:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08157D48
	cmp r0, #2
	beq _08157D44
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08157D44:
	movs r0, #1
	b _08157D54
_08157D48:
	ldr r0, _08157D8C @ =0xFFFFFDFF
	mov r5, sl
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_08157D52:
	movs r0, #0
_08157D54:
	adds r3, r0, #0
	cmp r3, #0
	bne _08157D94
	ldr r0, _08157D90 @ =FUN_080e48d0
	movs r2, #1
	ldr r1, [sp, #0x54]
	strb r2, [r1]
	ldr r4, [sp, #0x4c]
	strb r3, [r4]
	ldr r5, [sp, #0x2c]
	strb r3, [r5]
	ldr r1, [sp, #0x34]
	str r0, [r1]
	movs r1, #0
	ldr r4, [sp, #0x30]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x40]
	strb r0, [r5]
	ldr r0, [sp, #0x44]
	strb r1, [r0]
	ldr r4, [sp, #0x48]
	strb r1, [r4]
	ldr r5, [sp, #0x5c]
	str r3, [r5]
	ldr r0, [sp, #0x50]
	strb r2, [r0]
	b _08157DE4
	.align 2, 0
_08157D8C: .4byte 0xFFFFFDFF
_08157D90: .4byte FUN_080e48d0
_08157D94:
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	b _08157DE4
_08157DA2:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r4, #2
	movs r1, #0x1e
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
	movs r2, #0
	strb r2, [r0]
	ldr r3, _08157DDC @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	subs r1, #0xce
	adds r0, r7, r1
	movs r2, #1
	strh r2, [r0]
	b _08157DE4
	.align 2, 0
_08157DDC: .4byte 0x00000551

	thumb_func_start FUN_08157de0
FUN_08157de0: @ 0x08157DE0
	adds r0, #1
	str r0, [r1]
_08157DE4:
	add sp, #0x60
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08157df4
FUN_08157df4: @ 0x08157DF4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _08157E20 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08157E24
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08157E26
	.align 2, 0
_08157E20: .4byte 0x0000046C
_08157E24:
	movs r0, #0
_08157E26:
	cmp r0, #0
	bne _08157E2C
	b _0815814C
_08157E2C:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
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
	asrs r3, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov sb, r2
	cmp r3, #0
	blt _08157E6E
	cmp r1, #0
	blt _08157E6E
	ldr r0, _08157E74 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _08157E6E
	ldr r0, _08157E78 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08157E7C
_08157E6E:
	movs r4, #0
	b _08157E8A
	.align 2, 0
_08157E74: .4byte 0x030046A8
_08157E78: .4byte 0x030046AC
_08157E7C:
	ldr r0, _08157E9C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_08157E8A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08157EA0
	adds r0, #4
	b _08157EAC
	.align 2, 0
_08157E9C: .4byte 0x030046A4
_08157EA0:
	ldr r0, _08157EC0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08157EAC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08157EC4
	cmp r2, #2
	beq _08157EC8
	b _08157ECC
	.align 2, 0
_08157EC0: .4byte 0x030046A4
_08157EC4:
	ldrb r0, [r6, #4]
	b _08157ECA
_08157EC8:
	ldrb r0, [r6]
_08157ECA:
	subs r1, r1, r0
_08157ECC:
	strh r1, [r6, #2]
	ldr r6, _08157EFC @ =0x000004A4
	adds r0, r5, r6
	ldr r7, [r0]
	adds r4, r5, #0
	adds r4, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	adds r6, r0, #0
	adds r6, #8
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_0823599c
	mov r8, r4
	cmp r0, #0
	bne _08157F00
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _08157F26
	.align 2, 0
_08157EFC: .4byte 0x000004A4
_08157F00:
	adds r0, r7, #0
	mov r1, r8
	adds r2, r6, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08157F20
	cmp r0, #2
	beq _08157F1C
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08157F1C:
	movs r0, #1
	b _08157F30
_08157F20:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
_08157F26:
	ldr r1, _08157F6C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08157F30:
	cmp r0, #0
	beq _08157F36
	b _0815810C
_08157F36:
	mov r6, sp
	mov r0, sb
	ldr r2, [r0, #8]
	ldrh r1, [r2]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r6, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08157F68
	cmp r1, #0
	blt _08157F68
	ldr r0, _08157F70 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08157F68
	ldr r0, _08157F74 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08157F78
_08157F68:
	movs r4, #0
	b _08157F86
	.align 2, 0
_08157F6C: .4byte 0xFFFFFDFF
_08157F70: .4byte 0x030046A8
_08157F74: .4byte 0x030046AC
_08157F78:
	ldr r0, _08157F98 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08157F86:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08157F9C
	adds r0, #4
	b _08157FA8
	.align 2, 0
_08157F98: .4byte 0x030046A4
_08157F9C:
	ldr r0, _08157FBC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08157FA8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08157FC0
	cmp r2, #2
	beq _08157FC4
	b _08157FC8
	.align 2, 0
_08157FBC: .4byte 0x030046A4
_08157FC0:
	ldrb r0, [r6, #4]
	b _08157FC6
_08157FC4:
	ldrb r0, [r6]
_08157FC6:
	subs r1, r1, r0
_08157FC8:
	strh r1, [r6, #2]
	ldr r1, _08157FE8 @ =0x000004A4
	adds r0, r5, r1
	ldr r4, [r0]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _08157FEC
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _08158010
	.align 2, 0
_08157FE8: .4byte 0x000004A4
_08157FEC:
	adds r0, r4, #0
	mov r1, r8
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _0815800A
	cmp r0, #2
	beq _08158018
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08158018
_0815800A:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
_08158010:
	ldr r1, _0815802C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_08158018:
	movs r1, #2
	movs r0, #0xe0
	lsls r0, r0, #3
	add r0, sl
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08158030
	movs r0, #1
	b _08158032
	.align 2, 0
_0815802C: .4byte 0xFFFFFDFF
_08158030:
	movs r0, #0
_08158032:
	adds r4, r0, #0
	cmp r4, #0
	beq _081580A0
	adds r0, r5, #0
	movs r1, #0x11
	bl FUN_080ef86c
	ldr r3, _08158090 @ =FUN_08155570
	movs r1, #0x23
	ldr r6, _08158094 @ =0x0000046D
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
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xf
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08158098 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _0815809C @ =0x00000484
	adds r0, r5, r3
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	b _08158156
	.align 2, 0
_08158090: .4byte FUN_08155570
_08158094: .4byte 0x0000046D
_08158098: .4byte 0x0000046A
_0815809C: .4byte 0x00000484
_081580A0:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	ldr r3, _081580FC @ =0x0000046D
	adds r0, r5, r3
	strb r2, [r0]
	ldr r6, _08158100 @ =0x0000046B
	adds r0, r5, r6
	strb r4, [r0]
	adds r3, #0xe6
	adds r0, r5, r3
	strb r2, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r4, [r0]
	movs r3, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08158104 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _08158108 @ =0x00000484
	adds r0, r5, r3
	str r4, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r2, [r0]
	b _08158156
	.align 2, 0
_081580FC: .4byte 0x0000046D
_08158100: .4byte 0x0000046B
_08158104: .4byte 0x0000046A
_08158108: .4byte 0x00000484
_0815810C:
	ldr r1, _08158168 @ =0x000001DF
	adds r0, r5, r1
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	bl FUN_080e5718
	adds r0, r5, #0
	bl FUN_0815c4c0
	movs r2, #0x10
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #5
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r5, r6
	ldrh r1, [r2]
	movs r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	strh r3, [r0, #6]
_0815814C:
	ldr r2, _0815816C @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08158156:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08158168: .4byte 0x000001DF
_0815816C: .4byte 0x00000484

	thumb_func_start FUN_08158170
FUN_08158170: @ 0x08158170
	movs r1, #0xc7
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, _0815817C @ =0x085AD940
	str r1, [r0]
	bx lr
	.align 2, 0
_0815817C: .4byte 0x085AD940

	thumb_func_start FUN_08158180
FUN_08158180: @ 0x08158180
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _081581E4 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08158194
	movs r0, #0
	strb r0, [r1]
_08158194:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081581AA
	b _08158306
_081581AA:
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081581B8
	b _08158306
_081581B8:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r1, _081581E8 @ =0x0000A02F
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081581F0
	ldr r0, _081581EC @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08158200
	.align 2, 0
_081581E4: .4byte 0x0000046C
_081581E8: .4byte 0x0000A02F
_081581EC: .4byte 0x00000482
_081581F0:
	ldr r1, _08158224 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08158200
	movs r0, #1
	strh r0, [r2]
_08158200:
	ldr r3, _08158228 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0815822C
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
	b _08158244
	.align 2, 0
_08158224: .4byte 0x00000482
_08158228: .4byte 0x0000025D
_0815822C:
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
_08158244:
	ldr r1, _081582B8 @ =0x000004A4
	adds r0, r5, r1
	ldr r1, [r0]
	str r6, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5ed4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081582FC
	movs r2, #0x95
	lsls r2, r2, #3
	adds r6, r5, r2
	ldr r0, [r6]
	movs r3, #6
	ldrsh r2, [r0, r3]
	cmp r2, #0
	beq _081582C8
	movs r2, #0xf
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081582BC @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081582C0 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	movs r4, #1
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_080e6204
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r1, #0x91
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _081582C4 @ =0x00000482
	adds r0, r5, r1
	strh r4, [r0]
	ldr r0, [r6]
	movs r1, #8
	bl ClearMemory
	b _08158306
	.align 2, 0
_081582B8: .4byte 0x000004A4
_081582BC: .4byte 0x00000469
_081582C0: .4byte 0x00000484
_081582C4: .4byte 0x00000482
_081582C8:
	movs r1, #0x12
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _081582F4 @ =0x00000484
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _081582F8 @ =0x0000046C
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	adds r3, #0x18
	adds r0, r5, r3
	strh r1, [r0]
	b _08158306
	.align 2, 0
_081582F4: .4byte 0x00000484
_081582F8: .4byte 0x0000046C
_081582FC:
	ldr r0, _08158310 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08158306:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08158310: .4byte 0x00000484

	thumb_func_start FUN_08158314
FUN_08158314: @ 0x08158314
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, _0815832C @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08158330
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08158332
	.align 2, 0
_0815832C: .4byte 0x0000046C
_08158330:
	movs r0, #0
_08158332:
	cmp r0, #0
	beq _0815836A
	ldr r1, _08158420 @ =0x000001DF
	adds r0, r4, r1
	ldrb r3, [r0]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
	movs r6, #0xbe
	lsls r6, r6, #1
	adds r2, r4, r6
	ldr r1, _08158424 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r0, _08158428 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r2, _0815842C @ =0x00000482
	adds r1, r4, r2
	movs r0, #1
	strh r0, [r1]
_0815836A:
	movs r6, #0xc1
	lsls r6, r6, #3
	adds r0, r4, r6
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08158380
	b _08158494
_08158380:
	adds r0, r4, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _08158390
	b _08158494
_08158390:
	ldr r0, _08158430 @ =0x00000484
	adds r1, r4, r0
	ldr r0, [r1]
	cmp r0, #0x3c
	ble _08158490
	movs r1, #0x11
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r5, [r0]
	ldr r6, _08158434 @ =0x00000469
	adds r0, r4, r6
	strb r5, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r6, #0x1b
	adds r0, r4, r6
	str r5, [r0]
	ldr r1, _08158438 @ =0x0000046C
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0815843C @ =FUN_08155570
	movs r2, #0x23
	subs r6, #0x17
	adds r0, r4, r6
	strb r1, [r0]
	subs r6, #2
	adds r0, r4, r6
	strb r5, [r0]
	adds r6, #0xe8
	adds r0, r4, r6
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r4, r2
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r4, r6
	strh r5, [r0]
	movs r0, #0x95
	lsls r0, r0, #3
	adds r3, r4, r0
	ldr r0, [r3]
	strh r1, [r0, #6]
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r4, r1
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _08158440 @ =0x000004A4
	adds r0, r4, r2
	ldr r5, [r0]
	adds r6, r4, #0
	adds r6, #8
	ldr r7, [r3]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r7, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08158444
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r4, r6
	b _0815846A
	.align 2, 0
_08158420: .4byte 0x000001DF
_08158424: .4byte 0xFEFFFFFF
_08158428: .4byte 0xFFFFFDFF
_0815842C: .4byte 0x00000482
_08158430: .4byte 0x00000484
_08158434: .4byte 0x00000469
_08158438: .4byte 0x0000046C
_0815843C: .4byte FUN_08155570
_08158440: .4byte 0x000004A4
_08158444:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r7, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08158464
	cmp r0, #2
	beq _08158460
	adds r0, r4, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08158460:
	movs r0, #1
	b _08158474
_08158464:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
_0815846A:
	ldr r1, _08158488 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08158474:
	cmp r0, #0
	bne _08158494
	ldr r2, _0815848C @ =0x000005C4
	adds r0, r4, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	b _08158494
	.align 2, 0
_08158488: .4byte 0xFFFFFDFF
_0815848C: .4byte 0x000005C4
_08158490:
	adds r0, #1
	str r0, [r1]
_08158494:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0815849c
FUN_0815849c: @ 0x0815849C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _081584FC @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081584B0
	movs r0, #0
	strb r0, [r1]
_081584B0:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081585AE
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081585AE
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r1, _08158500 @ =0x0000A02F
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08158508
	ldr r0, _08158504 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08158518
	.align 2, 0
_081584FC: .4byte 0x0000046C
_08158500: .4byte 0x0000A02F
_08158504: .4byte 0x00000482
_08158508:
	ldr r1, _0815853C @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08158518
	movs r0, #1
	strh r0, [r2]
_08158518:
	ldr r3, _08158540 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08158544
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
	b _0815855C
	.align 2, 0
_0815853C: .4byte 0x00000482
_08158540: .4byte 0x0000025D
_08158544:
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
_0815855C:
	ldr r1, _0815859C @ =0x000004A4
	adds r0, r5, r1
	ldr r1, [r0]
	str r6, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5ed4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081585A4
	movs r2, #0x10
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081585A0 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _081585AE
	.align 2, 0
_0815859C: .4byte 0x000004A4
_081585A0: .4byte 0x00000484
_081585A4:
	ldr r0, _081585B8 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081585AE:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081585B8: .4byte 0x00000484

	thumb_func_start FUN_081585bc
FUN_081585bc: @ 0x081585BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	adds r5, r0, #0
	adds r6, r5, #0
	ldr r0, _08158698 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081585D6
	movs r0, #0
	strb r0, [r1]
_081585D6:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081585EC
	b _08158772
_081585EC:
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081585FA
	b _08158772
_081585FA:
	ldr r1, [r6, #0x24]
	ldr r0, [r1, #8]
	ldrb r0, [r0, #6]
	lsrs r4, r0, #4
	cmp r4, #0
	beq _08158622
	cmp r4, #2
	beq _08158622
	cmp r4, #4
	beq _08158622
	adds r0, r1, #0
	bl FUN_08234e3c
	ldr r0, [r6, #0x24]
	ldr r0, [r0, #8]
	ldrb r0, [r0, #6]
	lsrs r4, r0, #4
	cmp r4, #1
	bne _08158622
	b _08158772
_08158622:
	ldr r2, [r6, #0x24]
	ldrb r1, [r2, #3]
	adds r0, r1, #1
	strb r0, [r2, #3]
	lsls r1, r1, #0x18
	ldr r0, [r6, #0x24]
	ldr r0, [r0, #8]
	ldrh r2, [r0, #4]
	ldr r0, _0815869C @ =0x00000FFF
	lsrs r1, r1, #0x18
	ands r0, r2
	cmp r1, r0
	bhs _0815863E
	b _08158768
_0815863E:
	movs r3, #0xca
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _08158676
	adds r0, r5, #0
	adds r0, #0x9e
	ldrb r0, [r0]
	str r0, [sp]
	ldrh r0, [r5]
	str r0, [sp, #4]
	ldr r1, _081586A0 @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	str r0, [sp, #8]
	ldr r1, _081586A4 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	str r0, [sp, #0xc]
	add r1, sp, #0xc
	mov r3, sp
	str r3, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_08158676:
	ldr r0, [r6, #0x24]
	bl FUN_08234e3c
	adds r0, r5, #0
	bl FUN_080e6204
	ldr r0, [r6, #0x24]
	ldr r0, [r0, #8]
	ldrb r0, [r0, #6]
	lsrs r4, r0, #4
	cmp r4, #4
	bne _081586AC
	ldr r0, _081586A8 @ =0x00000482
	adds r1, r5, r0
	movs r0, #2
	strh r0, [r1]
	b _08158738
	.align 2, 0
_08158698: .4byte 0x0000046C
_0815869C: .4byte 0x00000FFF
_081586A0: .4byte 0x000001DF
_081586A4: .4byte 0xFFFF0000
_081586A8: .4byte 0x00000482
_081586AC:
	ldr r2, _081586FC @ =0x00000482
	adds r1, r5, r2
	movs r7, #0
	movs r3, #1
	mov r8, r3
	movs r0, #1
	strh r0, [r1]
	cmp r4, #0
	bne _08158738
	ldr r0, [r6, #0x24]
	adds r1, r6, #0
	adds r1, #8
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_08235038
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08158708
	movs r1, #0xf
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _08158700 @ =0x00000469
	adds r0, r5, r3
	strb r7, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r4, [r0]
	ldr r1, _08158704 @ =0x0000046C
	adds r0, r5, r1
	mov r2, r8
	strb r2, [r0]
	b _08158772
	.align 2, 0
_081586FC: .4byte 0x00000482
_08158700: .4byte 0x00000469
_08158704: .4byte 0x0000046C
_08158708:
	movs r1, #0x10
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r7, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r7, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _08158730 @ =0x00000484
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _08158734 @ =0x0000046C
	adds r0, r5, r2
	mov r3, r8
	strb r3, [r0]
	b _08158772
	.align 2, 0
_08158730: .4byte 0x00000484
_08158734: .4byte 0x0000046C
_08158738:
	movs r2, #0xf
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08158760 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _08158764 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _08158772
	.align 2, 0
_08158760: .4byte 0x00000469
_08158764: .4byte 0x00000484
_08158768:
	ldr r0, _08158780 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08158772:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08158780: .4byte 0x00000484

	thumb_func_start FUN_08158784
FUN_08158784: @ 0x08158784
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _081587D0 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081587A4
	movs r0, #0
	strb r0, [r1]
_081587A4:
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	mov r8, r0
	ldr r1, _081587D4 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081587DC
	ldr r0, _081587D8 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081587EC
	.align 2, 0
_081587D0: .4byte 0x0000046C
_081587D4: .4byte 0x0000A02F
_081587D8: .4byte 0x00000482
_081587DC:
	ldr r1, _08158810 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081587EC
	movs r0, #1
	strh r0, [r2]
_081587EC:
	ldr r1, _08158814 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08158818
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
	b _08158830
	.align 2, 0
_08158810: .4byte 0x00000482
_08158814: .4byte 0x0000025D
_08158818:
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
_08158830:
	movs r2, #2
	movs r0, #0xe0
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _08158846
	movs r0, #1
	b _08158848
_08158846:
	movs r0, #0
_08158848:
	adds r6, r0, #0
	cmp r6, #0
	bne _081588A0
	ldr r1, _08158898 @ =0x000004A4
	adds r4, r5, r1
	ldr r0, [r4]
	bl FUN_08235fd8
	cmp r0, #0
	beq _081588A0
	ldr r1, [r4]
	mov r2, r8
	str r2, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081588F8
	movs r1, #0x14
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r6, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r6, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _0815889C @ =0x00000484
	adds r0, r5, r1
	str r6, [r0]
	adds r2, #2
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _081588F8
	.align 2, 0
_08158898: .4byte 0x000004A4
_0815889C: .4byte 0x00000484
_081588A0:
	ldr r1, _081588EC @ =0x000004A4
	adds r0, r5, r1
	ldr r1, [r0]
	mov r2, r8
	str r2, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5ed4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081588F8
	movs r2, #3
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _081588F0 @ =0x00000469
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, #0x1a
	adds r0, r5, r2
	str r1, [r0]
	ldr r0, _081588F4 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x40
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
	b _08158902
	.align 2, 0
_081588EC: .4byte 0x000004A4
_081588F0: .4byte 0x00000469
_081588F4: .4byte 0x0000046C
_081588F8:
	ldr r2, _08158910 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08158902:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08158910: .4byte 0x00000484

	thumb_func_start FUN_08158914
FUN_08158914: @ 0x08158914
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _0815892C @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08158930
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08158932
	.align 2, 0
_0815892C: .4byte 0x0000046C
_08158930:
	movs r0, #0
_08158932:
	cmp r0, #0
	beq _08158966
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _081589C0 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _081589C4 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _081589C8 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
_08158966:
	ldr r1, _081589C4 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081589DC
	movs r1, #0x13
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081589CC @ =0x00000469
	adds r0, r5, r3
	strb r2, [r0]
	ldr r6, _081589D0 @ =0x0000046A
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081589D4 @ =0x00000484
	adds r0, r5, r1
	str r2, [r0]
	adds r3, #3
	adds r0, r5, r3
	movs r1, #1
	strb r1, [r0]
	ldr r4, _081589D8 @ =FUN_081562dc
	movs r3, #0x34
	adds r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081589C4 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	b _081589E6
	.align 2, 0
_081589C0: .4byte 0x0000046D
_081589C4: .4byte 0x0000046B
_081589C8: .4byte 0x00000553
_081589CC: .4byte 0x00000469
_081589D0: .4byte 0x0000046A
_081589D4: .4byte 0x00000484
_081589D8: .4byte FUN_081562dc
_081589DC:
	ldr r6, _081589EC @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081589E6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081589EC: .4byte 0x00000484

	thumb_func_start FUN_081589f0
FUN_081589f0: @ 0x081589F0
	push {lr}
	ldr r2, _08158A04 @ =0x0000046C
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08158A00
	movs r0, #0
	strb r0, [r1]
_08158A00:
	pop {r0}
	bx r0
	.align 2, 0
_08158A04: .4byte 0x0000046C

	thumb_func_start FUN_08158a08
FUN_08158a08: @ 0x08158A08
	push {lr}
	ldr r2, _08158A1C @ =0x0000046C
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08158A18
	movs r0, #0
	strb r0, [r1]
_08158A18:
	pop {r0}
	bx r0
	.align 2, 0
_08158A1C: .4byte 0x0000046C

	thumb_func_start FUN_08158a20
FUN_08158a20: @ 0x08158A20
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	adds r5, r0, #0
	ldr r0, _08158A90 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08158A3C
	movs r0, #0
	strb r0, [r1]
_08158A3C:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08158A52
	b _08158D7A
_08158A52:
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08158A60
	b _08158D7A
_08158A60:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r2, _08158A94 @ =0x0000A02F
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _08158A9C
	ldr r4, _08158A98 @ =0x00000482
	adds r1, r5, r4
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08158AAC
	.align 2, 0
_08158A90: .4byte 0x0000046C
_08158A94: .4byte 0x0000A02F
_08158A98: .4byte 0x00000482
_08158A9C:
	ldr r1, _08158AD0 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08158AAC
	movs r0, #1
	strh r0, [r2]
_08158AAC:
	ldr r3, _08158AD4 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08158AD8
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
	b _08158AF0
	.align 2, 0
_08158AD0: .4byte 0x00000482
_08158AD4: .4byte 0x0000025D
_08158AD8:
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
_08158AF0:
	ldr r0, _08158B2C @ =0x000004A4
	adds r4, r5, r0
	ldr r0, [r4]
	bl FUN_08235fd8
	adds r6, r0, #0
	cmp r6, #0
	bne _08158B02
	b _08158D28
_08158B02:
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08158B18
	b _08158D70
_08158B18:
	movs r2, #4
	ldr r3, _08158B30 @ =0x00000222
	adds r1, r5, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _08158B34
	movs r0, #1
	b _08158B36
	.align 2, 0
_08158B2C: .4byte 0x000004A4
_08158B30: .4byte 0x00000222
_08158B34:
	movs r0, #0
_08158B36:
	cmp r0, #0
	beq _08158B3C
	b _08158CF8
_08158B3C:
	adds r0, r5, #0
	bl FUN_0815d6d0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08158B4A
	b _08158D7A
_08158B4A:
	movs r1, #1
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08158B58
	movs r0, #1
	b _08158B5A
_08158B58:
	movs r0, #0
_08158B5A:
	cmp r0, #0
	bne _08158B60
	b _08158CF8
_08158B60:
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
	beq _08158B82
	b _08158D7A
_08158B82:
	movs r1, #4
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08158B90
	movs r0, #1
	b _08158B92
_08158B90:
	movs r0, #0
_08158B92:
	cmp r0, #0
	beq _08158B98
	b _08158D7A
_08158B98:
	movs r4, #0
	ldr r3, _08158CB4 @ =0x0000046C
	adds r3, r5, r3
	str r3, [sp, #0x3c]
	ldrb r7, [r5, #5]
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r0, r5, r0
	str r0, [sp, #0x10]
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r5, r1
	str r1, [sp, #0x1c]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r2, r5
	mov sb, r2
	ldr r3, _08158CB8 @ =0x00000553
	adds r3, r3, r5
	mov ip, r3
	ldr r0, _08158CBC @ =0x0000054F
	adds r0, r5, r0
	str r0, [sp, #0x2c]
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r1, r5, r1
	str r1, [sp, #0x34]
	ldr r2, _08158CC0 @ =0x0000054C
	adds r2, r5, r2
	str r2, [sp, #0x20]
	ldr r3, _08158CC4 @ =0x00000469
	adds r3, r3, r5
	mov sl, r3
	ldr r0, _08158CC8 @ =0x0000054D
	adds r0, r5, r0
	str r0, [sp, #0x24]
	ldr r1, _08158CCC @ =0x0000046A
	adds r1, r1, r5
	mov r8, r1
	ldr r2, _08158CD0 @ =0x0000054E
	adds r2, r5, r2
	str r2, [sp, #0x28]
	ldr r3, _08158CD4 @ =0x00000541
	adds r3, r5, r3
	str r3, [sp, #0x14]
	ldr r0, _08158CD8 @ =0x000005BC
	adds r0, r5, r0
	str r0, [sp, #0xc]
	ldr r1, _08158CDC @ =0x0000046D
	adds r1, r5, r1
	str r1, [sp, #0x40]
	ldr r2, _08158CE0 @ =0x0000046B
	adds r2, r5, r2
	str r2, [sp, #0x38]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r5, r3
	str r3, [sp, #0x30]
	ldr r0, _08158CE4 @ =0x00000484
	adds r0, r5, r0
	str r0, [sp, #8]
	ldr r1, _08158CE8 @ =0x00000542
	adds r1, r5, r1
	str r1, [sp, #0x18]
	ldr r2, _08158CEC @ =0x0203B400
	ldr r1, _08158CF0 @ =0x030046B8
	ldr r6, _08158CF4 @ =0x000003FF
	movs r5, #3
	adds r3, r7, #0
_08158C22:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r5
	lsls r0, r0, #6
	cmp r0, r3
	bne _08158C40
	adds r4, #1
	cmp r4, #3
	ble _08158C22
	adds r0, r7, #0
_08158C40:
	movs r3, #0
	ldr r2, [sp, #0x10]
	strb r0, [r2]
	mov r4, sb
	ldr r0, [r4]
	ldr r1, [sp, #0x1c]
	str r0, [r1]
	mov r2, ip
	ldrb r0, [r2]
	ldr r4, [sp, #0x2c]
	strb r0, [r4]
	ldr r1, [sp, #0x34]
	ldrb r0, [r1]
	ldr r2, [sp, #0x20]
	strb r0, [r2]
	mov r4, sl
	ldrb r0, [r4]
	ldr r1, [sp, #0x24]
	strb r0, [r1]
	mov r2, r8
	ldrb r0, [r2]
	ldr r4, [sp, #0x28]
	strb r0, [r4]
	mov r0, sp
	ldrb r1, [r0, #4]
	ldr r0, [sp, #0x14]
	strb r1, [r0]
	ldr r4, [sp, #0xc]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x40]
	strb r1, [r4]
	ldr r4, [sp, #0x38]
	strb r3, [r4]
	mov r4, ip
	strb r0, [r4]
	mov r0, sb
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x30]
	strh r3, [r4]
	movs r0, #3
	ldr r4, [sp, #0x34]
	strb r0, [r4]
	mov r0, sl
	strb r1, [r0]
	mov r4, r8
	strb r2, [r4]
	ldr r0, [sp, #8]
	str r3, [r0]
	ldr r2, [sp, #0x3c]
	strb r1, [r2]
	movs r0, #2
	ldr r3, [sp, #0x18]
	strb r0, [r3]
	b _08158D7A
	.align 2, 0
_08158CB4: .4byte 0x0000046C
_08158CB8: .4byte 0x00000553
_08158CBC: .4byte 0x0000054F
_08158CC0: .4byte 0x0000054C
_08158CC4: .4byte 0x00000469
_08158CC8: .4byte 0x0000054D
_08158CCC: .4byte 0x0000046A
_08158CD0: .4byte 0x0000054E
_08158CD4: .4byte 0x00000541
_08158CD8: .4byte 0x000005BC
_08158CDC: .4byte 0x0000046D
_08158CE0: .4byte 0x0000046B
_08158CE4: .4byte 0x00000484
_08158CE8: .4byte 0x00000542
_08158CEC: .4byte 0x0203B400
_08158CF0: .4byte 0x030046B8
_08158CF4: .4byte 0x000003FF
_08158CF8:
	movs r2, #0xd
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08158D20 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08158D24 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _08158D70
	.align 2, 0
_08158D20: .4byte 0x00000469
_08158D24: .4byte 0x00000484
_08158D28:
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5ed4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08158D70
	movs r1, #0xe
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	strb r6, [r0]
	ldr r2, _08158D64 @ =0x00000469
	adds r0, r5, r2
	strb r6, [r0]
	ldr r3, _08158D68 @ =0x0000046A
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, #0x1c
	adds r0, r5, r4
	str r6, [r0]
	ldr r0, _08158D6C @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _08158D7A
	.align 2, 0
_08158D64: .4byte 0x00000469
_08158D68: .4byte 0x0000046A
_08158D6C: .4byte 0x0000046C
_08158D70:
	ldr r2, _08158D8C @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08158D7A:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08158D8C: .4byte 0x00000484

	thumb_func_start FUN_08158d90
FUN_08158d90: @ 0x08158D90
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08158DA8 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08158DAC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08158DAE
	.align 2, 0
_08158DA8: .4byte 0x0000046C
_08158DAC:
	movs r0, #0
_08158DAE:
	cmp r0, #0
	beq _08158DE2
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _08158E68 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _08158E6C @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _08158E70 @ =0x00000553
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
_08158DE2:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08158E82
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _08158E82
	ldr r6, _08158E6C @ =0x0000046B
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _08158E78
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0xc
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
	ldr r1, _08158E74 @ =0x0000046C
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r3, [r0]
	movs r2, #0x1a
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08158E6C @ =0x0000046B
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
	b _08158E82
	.align 2, 0
_08158E68: .4byte 0x0000046D
_08158E6C: .4byte 0x0000046B
_08158E70: .4byte 0x00000553
_08158E74: .4byte 0x0000046C
_08158E78:
	ldr r6, _08158E88 @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08158E82:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08158E88: .4byte 0x00000484

	thumb_func_start FUN_08158e8c
FUN_08158e8c: @ 0x08158E8C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x6c
	adds r7, r0, #0
	ldr r0, _08158EAC @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08158EB0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08158EB2
	.align 2, 0
_08158EAC: .4byte 0x0000046C
_08158EB0:
	movs r0, #0
_08158EB2:
	cmp r0, #0
	beq _08158F04
	ldr r1, _08159044 @ =0x000005A4
	adds r0, r7, r1
	ldr r2, [r0]
	movs r1, #0
	ldr r3, _08159048 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r4, _0815904C @ =0x0000046B
	adds r0, r7, r4
	strb r1, [r0]
	ldr r5, _08159050 @ =0x00000553
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r2, r7, r4
	ldr r1, _08159054 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r0, _08159058 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	subs r6, #0xf6
	adds r0, r7, r6
	strh r3, [r0]
_08158F04:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08158F1A
	b _08159584
_08158F1A:
	adds r0, r7, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0
	beq _08158F2C
	b _08159584
_08158F2C:
	ldr r2, _0815905C @ =0x00000484
	adds r1, r7, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _08158F38
	b _08159580
_08158F38:
	ldr r3, _08159060 @ =0x00000222
	adds r3, r7, r3
	str r3, [sp, #8]
	movs r0, #7
	rsbs r0, r0, #0
	ldrh r1, [r3]
	ands r0, r1
	movs r4, #0
	strh r0, [r3]
	ldr r1, _08159064 @ =FUN_080e6794
	movs r0, #0xe
	ldr r5, _08159048 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0xc]
	movs r5, #1
	ldr r6, [sp, #0xc]
	strb r5, [r6]
	subs r2, #0x19
	adds r2, r7, r2
	str r2, [sp, #0x10]
	strb r4, [r2]
	ldr r3, _08159050 @ =0x00000553
	adds r3, r7, r3
	str r3, [sp, #0x14]
	strb r0, [r3]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x18]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r7, r0
	str r0, [sp, #0x1c]
	mov r1, r8
	strh r1, [r0]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r6, #0xc
	mov sb, r6
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r6, _08159068 @ =0x00000554
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _0815906C @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _08159070 @ =0x00000552
	adds r0, r7, r3
	mov r6, sb
	strb r6, [r0]
	movs r0, #3
	subs r1, #0xe8
	adds r1, r1, r7
	mov ip, r1
	strb r0, [r1]
	subs r2, #0xe8
	adds r2, r2, r7
	mov sl, r2
	strb r5, [r2]
	subs r3, #0xe8
	adds r3, r3, r7
	mov sb, r3
	strb r4, [r3]
	ldr r4, _0815905C @ =0x00000484
	adds r6, r7, r4
	mov r0, r8
	str r0, [r6]
	ldr r1, _08159074 @ =0x0000046C
	adds r3, r7, r1
	strb r5, [r3]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r4, r7, r2
	ldr r5, [r4]
	str r5, [sp, #0x20]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x58]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x5c]
	ldr r3, [sp, #0x10]
	str r3, [sp, #0x54]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x3c]
	ldr r3, [sp, #0x18]
	str r3, [sp, #0x40]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x68]
	ldr r3, [sp, #8]
	mov r8, r3
	mov r0, ip
	str r0, [sp, #0x48]
	mov r3, sl
	str r3, [sp, #0x4c]
	mov r0, sb
	str r0, [sp, #0x50]
	str r6, [sp, #0x64]
	adds r6, r4, #0
	mov sb, r2
	cmp r5, #0
	blt _08159040
	cmp r1, #0
	blt _08159040
	ldr r0, _08159078 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _08159040
	ldr r0, _0815907C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08159080
_08159040:
	movs r5, #0
	b _0815908E
	.align 2, 0
_08159044: .4byte 0x000005A4
_08159048: .4byte 0x0000046D
_0815904C: .4byte 0x0000046B
_08159050: .4byte 0x00000553
_08159054: .4byte 0xFEFFFFFF
_08159058: .4byte 0xFFFFFDFF
_0815905C: .4byte 0x00000484
_08159060: .4byte 0x00000222
_08159064: .4byte FUN_080e6794
_08159068: .4byte 0x00000554
_0815906C: .4byte 0x00000551
_08159070: .4byte 0x00000552
_08159074: .4byte 0x0000046C
_08159078: .4byte 0x030046A8
_0815907C: .4byte 0x030046AC
_08159080:
	ldr r0, _081590A0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r5
_0815908E:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081590A4
	adds r0, #4
	b _081590B0
	.align 2, 0
_081590A0: .4byte 0x030046A4
_081590A4:
	ldr r0, _081590C4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081590B0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081590C8
	cmp r2, #2
	beq _081590CE
	b _081590D4
	.align 2, 0
_081590C4: .4byte 0x030046A4
_081590C8:
	ldr r2, [sp, #0x20]
	ldrb r0, [r2, #4]
	b _081590D2
_081590CE:
	ldr r3, [sp, #0x20]
	ldrb r0, [r3]
_081590D2:
	subs r1, r1, r0
_081590D4:
	ldr r4, [sp, #0x20]
	strh r1, [r4, #2]
	ldr r0, _081590EC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081590F0
	movs r0, #1
	b _081590F2
	.align 2, 0
_081590EC: .4byte 0x030047A4
_081590F0:
	movs r0, #0
_081590F2:
	cmp r0, #0
	beq _08159130
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _08159112
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0815910E
	adds r2, r0, #0
_0815910E:
	cmp r2, #0
	bge _0815911C
_08159112:
	ldr r6, _08159118 @ =0x000005C4
	adds r0, r7, r6
	b _0815956C
	.align 2, 0
_08159118: .4byte 0x000005C4
_0815911C:
	ldr r1, _0815912C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08159178
	.align 2, 0
_0815912C: .4byte 0x03002BE0
_08159130:
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
	blt _0815915C
	cmp r1, #0
	blt _0815915C
	ldr r0, _08159160 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815915C
	ldr r0, _08159164 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08159168
_0815915C:
	movs r5, #0
	b _08159176
	.align 2, 0
_08159160: .4byte 0x030046A8
_08159164: .4byte 0x030046AC
_08159168:
	ldr r0, _0815920C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08159176:
	movs r2, #0
_08159178:
	ldr r3, _08159210 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _08159198
	ldr r1, _08159214 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08159198
	b _081594B0
_08159198:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	mov sl, r2
	cmp r3, #0
	beq _081591B2
	b _08159584
_081591B2:
	movs r0, #5
	rsbs r0, r0, #0
	mov r5, r8
	ldrh r1, [r5]
	ands r0, r1
	movs r5, #0
	mov r1, r8
	strh r0, [r1]
	movs r1, #0x80
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _08159218
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r6, [sp, #0x5c]
	strb r2, [r6]
	ldr r4, [sp, #0x54]
	strb r5, [r4]
	ldr r6, [sp, #0x3c]
	strb r0, [r6]
	ldr r0, [sp, #0x40]
	str r1, [r0]
	ldr r1, [sp, #0x68]
	strh r3, [r1]
	movs r0, #0xc
	ldr r4, [sp, #0x48]
	strb r5, [r4]
	ldr r6, [sp, #0x4c]
	strb r5, [r6]
	ldr r1, [sp, #0x50]
	strb r0, [r1]
	ldr r4, [sp, #0x64]
	str r3, [r4]
	ldr r5, [sp, #0x58]
	strb r2, [r5]
	b _08159366
	.align 2, 0
_0815920C: .4byte 0x030046A4
_08159210: .4byte 0x00000256
_08159214: .4byte 0x03002BE0
_08159218:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, [sp, #0x5c]
	strb r0, [r3]
	ldr r4, [sp, #0x54]
	strb r5, [r4]
	ldr r3, [sp, #0x3c]
	strb r0, [r3]
	ldr r4, [sp, #0x40]
	str r1, [r4]
	ldr r1, [sp, #0x68]
	strh r2, [r1]
	movs r1, #5
	ldr r3, [sp, #0x48]
	strb r5, [r3]
	ldr r4, [sp, #0x4c]
	strb r5, [r4]
	ldr r5, [sp, #0x50]
	strb r1, [r5]
	ldr r1, [sp, #0x64]
	str r2, [r1]
	ldr r2, [sp, #0x58]
	strb r0, [r2]
	ldr r4, [r6]
	mov r3, sb
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r4]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r4, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0815927C
	cmp r1, #0
	blt _0815927C
	ldr r0, _08159280 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815927C
	ldr r0, _08159284 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08159288
_0815927C:
	movs r5, #0
	b _08159296
	.align 2, 0
_08159280: .4byte 0x030046A8
_08159284: .4byte 0x030046AC
_08159288:
	ldr r0, _081592A8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08159296:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081592AC
	adds r0, #4
	b _081592B8
	.align 2, 0
_081592A8: .4byte 0x030046A4
_081592AC:
	ldr r0, _081592CC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081592B8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081592D0
	cmp r2, #2
	beq _081592D4
	b _081592D8
	.align 2, 0
_081592CC: .4byte 0x030046A4
_081592D0:
	ldrb r0, [r4, #4]
	b _081592D6
_081592D4:
	ldrb r0, [r4]
_081592D6:
	subs r1, r1, r0
_081592D8:
	strh r1, [r4, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08159300
	cmp r1, #0
	blt _08159300
	ldr r0, _08159304 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08159300
	ldr r0, _08159308 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815930C
_08159300:
	movs r5, #0
	b _0815931A
	.align 2, 0
_08159304: .4byte 0x030046A8
_08159308: .4byte 0x030046AC
_0815930C:
	ldr r0, _0815932C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0815931A:
	ldr r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08159330
	adds r0, #4
	b _0815933C
	.align 2, 0
_0815932C: .4byte 0x030046A4
_08159330:
	ldr r0, _08159350 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815933C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08159354
	cmp r3, #2
	beq _08159358
	b _0815935C
	.align 2, 0
_08159350: .4byte 0x030046A4
_08159354:
	ldrb r0, [r4, #4]
	b _0815935A
_08159358:
	ldrb r0, [r4]
_0815935A:
	subs r2, r2, r0
_0815935C:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_08159366:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x24]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov sb, r4
	ldr r6, _08159390 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x60]
	cmp r0, #0
	bne _08159474
	movs r1, #4
	mov r2, r8
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08159394
	movs r0, #1
	b _08159396
	.align 2, 0
_08159390: .4byte 0x00000482
_08159394:
	movs r0, #0
_08159396:
	ldr r3, _08159484 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x60]
	cmp r0, #0
	bne _08159474
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r6, _08159488 @ =0x0000054F
	adds r6, r6, r7
	mov ip, r6
	ldr r0, _0815948C @ =0x0000054C
	adds r0, r7, r0
	str r0, [sp, #0x30]
	ldr r1, _08159490 @ =0x0000054D
	adds r1, r7, r1
	str r1, [sp, #0x34]
	ldr r2, _08159494 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0x38]
	ldr r4, _08159498 @ =0x00000541
	adds r4, r7, r4
	str r4, [sp, #0x28]
	ldr r5, _0815949C @ =0x000005BC
	adds r5, r7, r5
	str r5, [sp, #0x44]
	ldr r6, _081594A0 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0x2c]
	ldr r6, _081594A4 @ =0x0203B400
	ldr r1, _081594A8 @ =0x030046B8
	ldr r2, _081594AC @ =0x000003FF
	movs r5, #3
	mov r4, sb
_081593E6:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r5
	lsls r0, r0, #6
	cmp r0, r4
	bne _08159404
	adds r3, #1
	cmp r3, #3
	ble _081593E6
	mov r0, sb
_08159404:
	movs r3, #0
	mov r1, r8
	strb r0, [r1]
	ldr r2, [sp, #0x40]
	ldr r0, [r2]
	mov r4, sl
	str r0, [r4]
	ldr r5, [sp, #0x3c]
	ldrb r0, [r5]
	mov r6, ip
	strb r0, [r6]
	ldr r1, [sp, #0x48]
	ldrb r0, [r1]
	ldr r2, [sp, #0x30]
	strb r0, [r2]
	ldr r4, [sp, #0x4c]
	ldrb r0, [r4]
	ldr r5, [sp, #0x34]
	strb r0, [r5]
	ldr r6, [sp, #0x50]
	ldrb r0, [r6]
	ldr r1, [sp, #0x38]
	strb r0, [r1]
	add r2, sp, #0x24
	ldrb r4, [r2]
	ldr r2, [sp, #0x28]
	strb r4, [r2]
	ldr r4, [sp, #0x44]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x5c]
	strb r1, [r5]
	ldr r6, [sp, #0x54]
	strb r3, [r6]
	ldr r4, [sp, #0x3c]
	strb r0, [r4]
	ldr r5, [sp, #0x40]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x68]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x48]
	strb r0, [r4]
	ldr r5, [sp, #0x4c]
	strb r1, [r5]
	ldr r6, [sp, #0x50]
	strb r2, [r6]
	ldr r0, [sp, #0x64]
	str r3, [r0]
	ldr r2, [sp, #0x58]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x2c]
	strb r0, [r3]
_08159474:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x60]
	strh r0, [r4]
	b _08159584
	.align 2, 0
_08159484: .4byte 0x00000482
_08159488: .4byte 0x0000054F
_0815948C: .4byte 0x0000054C
_08159490: .4byte 0x0000054D
_08159494: .4byte 0x0000054E
_08159498: .4byte 0x00000541
_0815949C: .4byte 0x000005BC
_081594A0: .4byte 0x00000542
_081594A4: .4byte 0x0203B400
_081594A8: .4byte 0x030046B8
_081594AC: .4byte 0x000003FF
_081594B0:
	mov sb, sp
	ldr r6, _081594EC @ =0x030046A4
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
	beq _081594F0
	adds r0, #4
	b _081594FA
	.align 2, 0
_081594EC: .4byte 0x030046A4
_081594F0:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081594FA:
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
	ldr r6, _08159530 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _08159534
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _0815955A
	.align 2, 0
_08159530: .4byte 0x000004A4
_08159534:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08159554
	cmp r0, #2
	beq _08159550
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08159550:
	movs r0, #1
	b _08159564
_08159554:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_0815955A:
	ldr r1, _08159578 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08159564:
	cmp r0, #0
	bne _08159584
	ldr r3, _0815957C @ =0x000005C4
	adds r0, r7, r3
_0815956C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _08159584
	.align 2, 0
_08159578: .4byte 0xFFFFFDFF
_0815957C: .4byte 0x000005C4
_08159580:
	adds r0, #1
	str r0, [r1]
_08159584:
	add sp, #0x6c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08159594
FUN_08159594: @ 0x08159594
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r0, _081595B0 @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081595B4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081595B6
	.align 2, 0
_081595B0: .4byte 0x0000046C
_081595B4:
	movs r0, #0
_081595B6:
	cmp r0, #0
	beq _0815962C
	ldr r1, _081596C8 @ =0x000005A4
	adds r0, r4, r1
	ldr r2, [r0]
	movs r1, #0
	ldr r3, _081596CC @ =0x0000046D
	adds r0, r4, r3
	movs r3, #1
	strb r3, [r0]
	ldr r5, _081596D0 @ =0x0000046B
	adds r0, r4, r5
	strb r1, [r0]
	ldr r6, _081596D4 @ =0x00000553
	adds r0, r4, r6
	strb r1, [r0]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r0, r4, r5
	str r2, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r4, r6
	strh r1, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r4, r0
	subs r1, #0x81
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, _081596D8 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r4, r5
	ldr r0, _081596DC @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r6, _081596E0 @ =0x00000482
	adds r0, r4, r6
	strh r3, [r0]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r1, r1, r2
	ldr r2, _081596E4 @ =0xFFF7FFFF
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
_0815962C:
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r0, r4, r3
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08159642
	b _08159870
_08159642:
	adds r0, r4, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _08159652
	b _08159870
_08159652:
	movs r2, #0x80
	lsls r2, r2, #5
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r1, r4, r6
	ldrh r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _081596F4
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r0, _081596E8 @ =0x0000FFFE
	cmp r1, r0
	bhi _081596F4
	movs r2, #0xbd
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r3, [r0]
	movs r1, #0x19
	ldr r6, _081596CC @ =0x0000046D
	adds r0, r4, r6
	movs r2, #1
	strb r2, [r0]
	subs r6, #2
	adds r0, r4, r6
	strb r5, [r0]
	adds r6, #0xe8
	adds r0, r4, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r3, #0
	strh r5, [r0]
	movs r1, #3
	subs r6, #0xeb
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _081596EC @ =0x00000469
	adds r0, r4, r1
	strb r2, [r0]
	adds r6, #2
	adds r0, r4, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r4, r1
	str r5, [r0]
	ldr r3, _081596F0 @ =0x0000046C
	adds r0, r4, r3
	strb r2, [r0]
	b _08159870
	.align 2, 0
_081596C8: .4byte 0x000005A4
_081596CC: .4byte 0x0000046D
_081596D0: .4byte 0x0000046B
_081596D4: .4byte 0x00000553
_081596D8: .4byte 0xFEFFFFFF
_081596DC: .4byte 0xFFFFFDFF
_081596E0: .4byte 0x00000482
_081596E4: .4byte 0xFFF7FFFF
_081596E8: .4byte 0x0000FFFE
_081596EC: .4byte 0x00000469
_081596F0: .4byte 0x0000046C
_081596F4:
	ldr r5, _0815972C @ =0x00000484
	adds r0, r4, r5
	ldr r0, [r0]
	cmp r0, #0x1e
	bne _08159734
	ldr r6, _08159730 @ =0x000001DF
	adds r0, r4, r6
	ldrb r3, [r0]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
	movs r1, #0x80
	lsls r1, r1, #5
	mov r2, r8
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08159734
	movs r3, #0xbe
	lsls r3, r3, #3
	adds r0, r4, r3
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	b _08159870
	.align 2, 0
_0815972C: .4byte 0x00000484
_08159730: .4byte 0x000001DF
_08159734:
	ldr r5, _081597C0 @ =0x00000484
	adds r1, r4, r5
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _08159740
	b _0815986C
_08159740:
	movs r1, #7
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081597C4 @ =0x00000469
	adds r0, r4, r3
	strb r2, [r0]
	subs r5, #0x1a
	adds r0, r4, r5
	strb r1, [r0]
	adds r6, #0x1c
	adds r0, r4, r6
	str r2, [r0]
	ldr r1, _081597C8 @ =0x0000046C
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r4, r3
	ldr r3, [r0]
	adds r5, #3
	adds r0, r4, r5
	strb r1, [r0]
	subs r6, #0x19
	adds r0, r4, r6
	strb r2, [r0]
	adds r5, #0xe6
	adds r0, r4, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r4, r6
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r2, [r0]
	subs r5, #0xab
	adds r2, r4, r5
	ldr r0, [r2]
	strh r1, [r0, #6]
	subs r6, #0xd4
	adds r0, r4, r6
	ldr r5, [r0]
	adds r6, r4, #0
	adds r6, #8
	ldr r7, [r2]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r7, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081597D0
	ldr r0, _081597CC @ =0xFFFFFDFF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081597FA
	.align 2, 0
_081597C0: .4byte 0x00000484
_081597C4: .4byte 0x00000469
_081597C8: .4byte 0x0000046C
_081597CC: .4byte 0xFFFFFDFF
_081597D0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r7, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081597F0
	cmp r0, #2
	beq _081597EC
	adds r0, r4, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081597EC:
	movs r0, #1
	b _081597FC
_081597F0:
	ldr r0, _08159810 @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081597FA:
	movs r0, #0
_081597FC:
	cmp r0, #0
	bne _08159818
	ldr r5, _08159814 @ =0x000005C4
	adds r0, r4, r5
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	b _08159870
	.align 2, 0
_08159810: .4byte 0xFFFFFDFF
_08159814: .4byte 0x000005C4
_08159818:
	movs r1, #0x80
	lsls r1, r1, #0xe
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r0, r4, r6
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08159870
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, _0815985C @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _08159860 @ =0xFFFFFDFF
	mov r2, r8
	ldrh r0, [r2]
	ands r1, r0
	movs r2, #0
	movs r3, #0
	mov r5, r8
	strh r1, [r5]
	adds r6, #0xa4
	adds r0, r4, r6
	strb r2, [r0]
	ldr r1, _08159864 @ =0x0000021E
	adds r0, r4, r1
	strh r3, [r0]
	ldr r2, _08159868 @ =0x00000202
	adds r0, r4, r2
	strh r3, [r0]
	b _08159870
	.align 2, 0
_0815985C: .4byte 0xFEFFFFFF
_08159860: .4byte 0xFFFFFDFF
_08159864: .4byte 0x0000021E
_08159868: .4byte 0x00000202
_0815986C:
	adds r0, #1
	str r0, [r1]
_08159870:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0815987c
FUN_0815987c: @ 0x0815987C
	ldr r1, _08159888 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _0815988C @ =0x085AD94C
	str r1, [r0]
	bx lr
	.align 2, 0
_08159888: .4byte 0x00000634
_0815988C: .4byte 0x085AD94C

	thumb_func_start FUN_08159890
FUN_08159890: @ 0x08159890
	ldr r1, _0815989C @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _081598A0 @ =0x085AD9A0
	str r1, [r0]
	bx lr
	.align 2, 0
_0815989C: .4byte 0x0000063C
_081598A0: .4byte 0x085AD9A0

	thumb_func_start FUN_081598a4
FUN_081598a4: @ 0x081598A4
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #2
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #2
	movs r2, #1
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #3
	movs r2, #3
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0x14
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #6
	movs r2, #5
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #7
	movs r2, #6
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #8
	movs r2, #5
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #9
	movs r2, #6
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #7
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xe
	movs r2, #0xa
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #0xb
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #9
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #8
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #4
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #4
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x13
	movs r2, #0xd
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0xe
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x15
	movs r2, #0x11
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #0x12
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #0x13
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x18
	movs r2, #0x10
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #0xf
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x1a
	movs r2, #0xc
	movs r3, #0
	bl FUN_080ef84c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081599cc
FUN_081599cc: @ 0x081599CC
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x3c
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r4, _08159A98 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r4
	movs r2, #0x80
	orrs r0, r2
	ldr r3, _08159A9C @ =0x0000FFFF
	mov sb, r3
	ands r0, r3
	movs r3, #0x80
	lsls r3, r3, #0x10
	mov r8, r3
	orrs r0, r3
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r4
	orrs r0, r2
	str r0, [sp, #0x10]
	str r3, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r4
	str r0, [r3, #4]
	ldr r2, _08159AA0 @ =0x0000410B
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r1, r0
	ldr r0, _08159AA4 @ =FUN_08152c68
	str r0, [sp]
	str r6, [sp, #4]
	str r2, [sp, #8]
	adds r0, r6, #0
	add r2, sp, #0xc
	bl FUN_080e391c
	ldr r0, [sp, #0x1c]
	ands r0, r4
	movs r5, #0x40
	orrs r0, r5
	mov r1, sb
	ands r0, r1
	mov r3, r8
	orrs r0, r3
	str r0, [sp, #0x1c]
	add r1, sp, #0x1c
	ldr r0, [r1, #4]
	ands r0, r4
	orrs r0, r5
	str r0, [r1, #4]
	str r3, [sp, #0x24]
	add r2, sp, #0x24
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _08159AA8 @ =FUN_08152c20
	str r6, [sp]
	adds r0, r6, #0
	bl FUN_080e3834
	ldr r0, [sp, #0x2c]
	ands r0, r4
	orrs r0, r5
	mov r1, sb
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x2c]
	add r1, sp, #0x2c
	ldr r0, [r1, #4]
	ands r0, r4
	orrs r0, r5
	str r0, [r1, #4]
	mov r3, r8
	str r3, [sp, #0x34]
	add r2, sp, #0x34
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _08159AAC @ =FUN_08152be0
	movs r0, #0
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r6, #0
	bl FUN_080e3984
	add sp, #0x3c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08159A98: .4byte 0xFFFF0000
_08159A9C: .4byte 0x0000FFFF
_08159AA0: .4byte 0x0000410B
_08159AA4: .4byte FUN_08152c68
_08159AA8: .4byte FUN_08152c20
_08159AAC: .4byte FUN_08152be0

	thumb_func_start FUN_08159ab0
FUN_08159ab0: @ 0x08159AB0
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08159ACC
	b _08159C14
_08159ACC:
	movs r1, #0x22
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08159AE0
	movs r0, #1
	b _08159AE2
_08159AE0:
	movs r0, #0
_08159AE2:
	cmp r0, #0
	bne _08159AF6
	ldr r1, _08159B08 @ =0x0000A13F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08159B0C
_08159AF6:
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r2, r5, r0
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	b _08159C14
	.align 2, 0
_08159B08: .4byte 0x0000A13F
_08159B0C:
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r2, r5, r1
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, _08159B44 @ =0x085B0A08
	ldrb r0, [r4, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	adds r3, r2, #0
	cmp r0, #0
	blt _08159B48
	asrs r2, r0, #0xc
	b _08159B4E
	.align 2, 0
_08159B44: .4byte 0x085B0A08
_08159B48:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08159B4E:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08159B78 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldrb r1, [r4, #5]
	lsls r0, r1, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #7
	adds r3, r1, #0
	cmp r0, #0
	blt _08159B7C
	asrs r2, r0, #0xc
	b _08159B82
	.align 2, 0
_08159B78: .4byte 0xFFFF0000
_08159B7C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08159B82:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08159BB0 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	adds r0, r3, #0
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	cmp r0, #1
	beq _08159BD8
	cmp r0, #1
	bgt _08159BB4
	cmp r0, #0
	beq _08159BBE
	b _08159BF0
	.align 2, 0
_08159BB0: .4byte 0xFFFF0000
_08159BB4:
	cmp r0, #2
	beq _08159BBE
	cmp r0, #3
	beq _08159BD8
	b _08159BF0
_08159BBE:
	ldr r3, _08159BD4 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r1, #0xa0
	orrs r0, r1
	str r0, [sp, #8]
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x40
	b _08159BEC
	.align 2, 0
_08159BD4: .4byte 0xFFFF0000
_08159BD8:
	ldr r3, _08159C1C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r1, #0x40
	orrs r0, r1
	str r0, [sp, #8]
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0xa0
_08159BEC:
	orrs r0, r1
	str r0, [r2, #4]
_08159BF0:
	ldr r1, _08159C20 @ =0x0000FFFF
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #8]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	mov r1, sp
	movs r2, #0
	bl FUN_082364c4
_08159C14:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08159C1C: .4byte 0xFFFF0000
_08159C20: .4byte 0x0000FFFF

	thumb_func_start FUN_08159c24
FUN_08159c24: @ 0x08159C24
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	movs r2, #0x99
	lsls r2, r2, #2
	adds r4, r6, r2
	ldr r0, [r4]
	bl FUN_081e91d4
	str r0, [r4]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0815a2a8
	ldr r4, _08159D90 @ =0x000006AA
	adds r1, r7, r4
	movs r0, #0x3a
	strh r0, [r1]
	movs r1, #0x80
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r3, r6, r0
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _08159CDA
	ldr r2, _08159D94 @ =0x00000482
	adds r1, r6, r2
	movs r0, #1
	strh r0, [r1]
	ldr r1, _08159D98 @ =0x00000222
	adds r0, r6, r1
	strh r4, [r0]
	ldr r2, _08159D9C @ =0x0000024E
	adds r0, r6, r2
	strh r4, [r0]
	ldr r0, _08159DA0 @ =0xFFFFFC7F
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _08159DA4 @ =0xF3FFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _08159CC4
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r1, _08159DA8 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _08159DAC @ =0xFFFFFDFF
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
	ldr r1, _08159DB0 @ =0x0000021E
	adds r0, r6, r1
	strh r4, [r0]
	subs r2, #0x1a
	adds r0, r6, r2
	strh r4, [r0]
_08159CC4:
	ldr r0, _08159DB4 @ =0xFFFFFBFF
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	ldr r4, _08159DB8 @ =0x00000542
	adds r1, r6, r4
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_0815c05c
_08159CDA:
	movs r0, #0xdc
	lsls r0, r0, #3
	adds r1, r7, r0
	movs r3, #0
	movs r5, #0
	movs r0, #0x78
	strh r0, [r1]
	movs r2, #8
	movs r4, #0xe0
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _08159DBC @ =FUN_08154de8
	movs r1, #0x21
	ldr r7, _08159DC0 @ =0x0000046D
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
	movs r1, #3
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _08159DC4 @ =0x00000469
	adds r0, r6, r1
	strb r3, [r0]
	ldr r2, _08159DC8 @ =0x0000046A
	adds r0, r6, r2
	strb r3, [r0]
	adds r7, #0x1c
	adds r0, r6, r7
	str r5, [r0]
	adds r1, #3
	adds r0, r6, r1
	strb r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r6, r4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
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
	movs r7, #0xc1
	lsls r7, r7, #1
	adds r2, r6, r7
	ldr r0, _08159DCC @ =0xFFFFF636
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08159D90: .4byte 0x000006AA
_08159D94: .4byte 0x00000482
_08159D98: .4byte 0x00000222
_08159D9C: .4byte 0x0000024E
_08159DA0: .4byte 0xFFFFFC7F
_08159DA4: .4byte 0xF3FFFFFF
_08159DA8: .4byte 0xFEFFFFFF
_08159DAC: .4byte 0xFFFFFDFF
_08159DB0: .4byte 0x0000021E
_08159DB4: .4byte 0xFFFFFBFF
_08159DB8: .4byte 0x00000542
_08159DBC: .4byte FUN_08154de8
_08159DC0: .4byte 0x0000046D
_08159DC4: .4byte 0x00000469
_08159DC8: .4byte 0x0000046A
_08159DCC: .4byte 0xFFFFF636

	thumb_func_start FUN_08159dd0
FUN_08159dd0: @ 0x08159DD0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	ldr r1, _08159E28 @ =0x00000256
	adds r0, r4, r1
	ldrh r5, [r0]
	ldr r2, _08159E2C @ =0x00000472
	adds r0, r4, r2
	ldrh r0, [r0]
	lsrs r0, r0, #8
	mov r8, r0
	ldr r6, _08159E30 @ =0x030046A4
	ldr r2, [r6]
	ldr r0, [r2, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	movs r3, #6
	ldrsh r0, [r0, r3]
	adds r7, r1, #0
	muls r7, r0, r7
	ldr r0, _08159E34 @ =0x03002BE0
	ldr r1, [r0]
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r1, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _08159E24
	cmp r1, #0
	blt _08159E24
	ldr r0, _08159E38 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _08159E24
	ldr r0, _08159E3C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08159E40
_08159E24:
	movs r0, #0
	b _08159E4C
	.align 2, 0
_08159E28: .4byte 0x00000256
_08159E2C: .4byte 0x00000472
_08159E30: .4byte 0x030046A4
_08159E34: .4byte 0x03002BE0
_08159E38: .4byte 0x030046A8
_08159E3C: .4byte 0x030046AC
_08159E40:
	lsls r0, r1, #1
	adds r1, r2, #0
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, r0, r3
_08159E4C:
	mov sb, r0
	ldrb r0, [r4, #5]
	lsrs r0, r0, #6
	cmp r0, #1
	beq _08159ECE
	cmp r0, #1
	bgt _08159E60
	cmp r0, #0
	beq _08159E6C
	b _08159FB2
_08159E60:
	cmp r0, #2
	beq _08159F16
	cmp r0, #3
	bne _08159E6A
	b _08159F6C
_08159E6A:
	b _08159FB2
_08159E6C:
	adds r4, r5, #1
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	cmp r5, r0
	blt _08159E8C
	b _08159FB2
_08159E8C:
	adds r7, r6, #0
	lsls r0, r4, #2
	adds r6, r0, #0
	adds r6, #0xc
_08159E94:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08159EA4
	adds r0, #4
	b _08159EAA
_08159EA4:
	ldr r0, [r7]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_08159EAA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bls _08159EB6
	b _08159FB2
_08159EB6:
	cmp r4, sb
	beq _08159F68
	adds r6, #4
	adds r4, #1
	adds r5, #1
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _08159E94
	b _08159FB2
_08159ECE:
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r5, r0
	cmp r7, r4
	ble _08159FB2
	adds r5, r6, #0
_08159EDE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08159EEE
	adds r0, #4
	b _08159EF8
_08159EEE:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08159EF8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bhi _08159FB2
	cmp r4, sb
	beq _08159F68
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	adds r4, r4, r0
	cmp r7, r4
	bgt _08159EDE
	b _08159FB2
_08159F16:
	subs r4, r5, #1
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	cmp r5, #0
	blt _08159FB2
	lsls r0, r4, #2
	adds r6, r0, #0
	adds r6, #0xc
_08159F32:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08159F42
	adds r0, #4
	b _08159F4A
_08159F42:
	ldr r0, _08159F64 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_08159F4A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bhi _08159FB2
	cmp r4, sb
	beq _08159F68
	subs r6, #4
	subs r4, #1
	subs r5, #1
	cmp r5, #0
	bge _08159F32
	b _08159FB2
	.align 2, 0
_08159F64: .4byte 0x030046A4
_08159F68:
	movs r0, #1
	b _08159FB4
_08159F6C:
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r4, r5, r0
	cmp r4, #0
	blt _08159FB2
	adds r5, r6, #0
_08159F7C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08159F8C
	adds r0, #4
	b _08159F96
_08159F8C:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08159F96:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bhi _08159FB2
	cmp r4, sb
	beq _08159F68
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	cmp r4, #0
	bge _08159F7C
_08159FB2:
	movs r0, #0
_08159FB4:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08159fc0
FUN_08159fc0: @ 0x08159FC0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	adds r4, r2, #0
	str r3, [sp]
	movs r0, #8
	adds r0, r0, r6
	mov sl, r0
	movs r1, #0x10
	adds r1, r1, r6
	mov r8, r1
	ldr r2, _08159FF8 @ =0x00000256
	adds r0, r6, r2
	ldrh r5, [r0]
	mov sb, sl
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08159FFC
	adds r0, #4
	b _0815A008
	.align 2, 0
_08159FF8: .4byte 0x00000256
_08159FFC:
	ldr r0, _0815A01C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815A008:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0815A020
	cmp r2, #2
	beq _0815A026
	b _0815A02C
	.align 2, 0
_0815A01C: .4byte 0x030046A4
_0815A020:
	mov r3, sb
	ldrb r0, [r3, #4]
	b _0815A02A
_0815A026:
	mov r2, sb
	ldrb r0, [r2]
_0815A02A:
	subs r1, r1, r0
_0815A02C:
	adds r3, r1, #0
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
	ldrh r0, [r7]
	mov r1, r8
	strh r0, [r1]
	ldrh r0, [r7, #4]
	strh r0, [r1, #4]
	ldrh r0, [r7, #2]
	ldr r1, [sp]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldr r1, [sp, #0x24]
	adds r0, r1, #0
	muls r0, r1, r0
	asrs r1, r0, #4
	cmp r4, #1
	beq _0815A06C
	cmp r4, #1
	bgt _0815A060
	cmp r4, #0
	beq _0815A066
	b _0815A07C
_0815A060:
	cmp r4, #2
	beq _0815A07A
	b _0815A07C
_0815A066:
	adds r0, r2, #1
	adds r2, r0, r1
	b _0815A07C
_0815A06C:
	movs r0, #0x40
	subs r0, r0, r1
	cmp r0, #0
	bge _0815A076
	rsbs r0, r0, #0
_0815A076:
	subs r2, r2, r0
	b _0815A07C
_0815A07A:
	adds r2, r2, r1
_0815A07C:
	adds r1, r2, r3
	cmp r4, #0
	beq _0815A088
	cmp r4, #1
	beq _0815A0B4
	b _0815A0CA
_0815A088:
	movs r3, #2
	ldrsh r0, [r7, r3]
	cmp r0, #0
	bgt _0815A0CA
	strh r4, [r7, #2]
	mov r0, r8
	strh r4, [r0]
	strh r4, [r0, #4]
	ldr r2, _0815A0B0 @ =0x00000472
	adds r1, r6, r2
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sl
	strh r0, [r1, #2]
	movs r0, #1
	b _0815A0D8
	.align 2, 0
_0815A0B0: .4byte 0x00000472
_0815A0B4:
	cmp r1, r3
	bgt _0815A0CA
	movs r0, #0
	mov r2, sl
	strh r3, [r2, #2]
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #1
	b _0815A0D8
_0815A0CA:
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r2, [r0]
	mov r0, sl
	strh r1, [r0, #2]
	movs r0, #0
_0815A0D8:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0815a0e8
FUN_0815a0e8: @ 0x0815A0E8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0815A138 @ =0x00000472
	adds r1, r5, r2
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldrh r1, [r1]
	adds r1, r1, r0
	mov r8, r1
	adds r6, r5, #0
	adds r6, #8
	ldrh r0, [r5, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0815A134
	cmp r1, #0
	blt _0815A134
	ldr r0, _0815A13C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815A134
	ldr r0, _0815A140 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815A144
_0815A134:
	movs r4, #0
	b _0815A152
	.align 2, 0
_0815A138: .4byte 0x00000472
_0815A13C: .4byte 0x030046A8
_0815A140: .4byte 0x030046AC
_0815A144:
	ldr r0, _0815A164 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0815A152:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815A168
	adds r0, #4
	b _0815A174
	.align 2, 0
_0815A164: .4byte 0x030046A4
_0815A168:
	ldr r0, _0815A188 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815A174:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0815A18C
	cmp r2, #2
	beq _0815A190
	b _0815A194
	.align 2, 0
_0815A188: .4byte 0x030046A4
_0815A18C:
	ldrb r0, [r6, #4]
	b _0815A192
_0815A190:
	ldrb r0, [r6]
_0815A192:
	subs r1, r1, r0
_0815A194:
	cmp r1, r8
	bhs _0815A1DC
	movs r0, #0xdf
	lsls r0, r0, #1
	adds r3, r5, r0
	ldr r1, _0815A1D4 @ =0x000006CE
	adds r2, r7, r1
	ldrh r0, [r2]
	lsls r0, r0, #1
	ldrh r1, [r3]
	subs r1, r1, r0
	strh r1, [r3]
	ldr r3, _0815A1D8 @ =0x00000472
	adds r0, r5, r3
	ldrh r0, [r0]
	adds r0, r0, r1
	strh r0, [r5, #0xa]
	ldr r1, [r5, #0x44]
	strh r0, [r1, #0x1e]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _0815A216
	.align 2, 0
_0815A1D4: .4byte 0x000006CE
_0815A1D8: .4byte 0x00000472
_0815A1DC:
	movs r1, #2
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815A1F0
	movs r0, #1
	b _0815A1F2
_0815A1F0:
	movs r0, #0
_0815A1F2:
	cmp r0, #0
	beq _0815A20E
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0
	strh r0, [r1]
	movs r0, #0x83
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
_0815A20E:
	ldr r2, _0815A220 @ =0x000006CE
	adds r1, r7, r2
	movs r0, #0
	strh r0, [r1]
_0815A216:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815A220: .4byte 0x000006CE

	thumb_func_start FUN_0815a224
FUN_0815a224: @ 0x0815A224
	push {r4, lr}
	mov ip, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, ip
	ldr r3, [r0]
	ldr r1, _0815A250 @ =0x000006CA
	adds r0, r3, r1
	movs r2, #0xdf
	lsls r2, r2, #1
	add r2, ip
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r1, r0
	bge _0815A258
	ldr r0, _0815A254 @ =0x000006C4
	adds r1, r3, r0
	movs r0, #0
	strb r0, [r1]
	b _0815A29C
	.align 2, 0
_0815A250: .4byte 0x000006CA
_0815A254: .4byte 0x000006C4
_0815A258:
	ldr r1, _0815A278 @ =0x085B0A08
	ldr r2, _0815A27C @ =0x000006C4
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _0815A280
	asrs r2, r0, #0xc
	b _0815A286
	.align 2, 0
_0815A278: .4byte 0x085B0A08
_0815A27C: .4byte 0x000006C4
_0815A280:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0815A286:
	ldr r1, _0815A2A4 @ =0x000006C4
	adds r0, r3, r1
	ldrb r1, [r0]
	adds r1, #0xc
	strb r1, [r0]
	movs r1, #0xdf
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_0815A29C:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0815A2A4: .4byte 0x000006C4

	thumb_func_start FUN_0815a2a8
FUN_0815a2a8: @ 0x0815A2A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	str r1, [sp, #0xc]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldrb r0, [r7, #5]
	adds r0, #0x20
	asrs r0, r0, #6
	mov sb, r0
	ldr r2, _0815A2F0 @ =0x00000256
	adds r0, r7, r2
	ldrh r5, [r0]
	mov r0, sp
	movs r1, #4
	bl ClearMemory
	ldr r3, _0815A2F4 @ =0x00000472
	adds r0, r7, r3
	ldrh r6, [r0]
	adds r4, r5, #1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815A2F8
	adds r0, #4
	b _0815A304
	.align 2, 0
_0815A2F0: .4byte 0x00000256
_0815A2F4: .4byte 0x00000472
_0815A2F8:
	ldr r0, _0815A33C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815A304:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	cmp r6, r0
	beq _0815A316
	mov r1, sp
	movs r0, #1
	strb r0, [r1]
_0815A316:
	ldr r1, _0815A340 @ =0x00000472
	adds r0, r7, r1
	ldrh r0, [r0]
	mov sl, r0
	ldr r6, _0815A33C @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r5, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815A344
	adds r0, #4
	b _0815A34E
	.align 2, 0
_0815A33C: .4byte 0x030046A4
_0815A340: .4byte 0x00000472
_0815A344:
	ldr r0, [r6]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815A34E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	cmp sl, r0
	beq _0815A360
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #1]
_0815A360:
	ldr r3, _0815A37C @ =0x00000472
	adds r0, r7, r3
	ldrh r6, [r0]
	subs r4, r5, #1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	mov sl, r4
	cmp r0, #0
	beq _0815A380
	adds r0, #4
	b _0815A38E
	.align 2, 0
_0815A37C: .4byte 0x00000472
_0815A380:
	ldr r2, _0815A3C4 @ =0x030046A4
	ldr r1, [r2]
	mov r3, sl
	lsls r0, r3, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815A38E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	cmp r6, r0
	beq _0815A3A0
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #2]
_0815A3A0:
	ldr r1, _0815A3C8 @ =0x00000472
	adds r0, r7, r1
	ldrh r6, [r0]
	ldr r2, _0815A3C4 @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r4, r5, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815A3CC
	adds r0, #4
	b _0815A3D8
	.align 2, 0
_0815A3C4: .4byte 0x030046A4
_0815A3C8: .4byte 0x00000472
_0815A3CC:
	ldr r1, _0815A414 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815A3D8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	cmp r6, r0
	beq _0815A3EA
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #3]
_0815A3EA:
	mov r0, sp
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #1
	bne _0815A430
	movs r0, #0xd5
	lsls r0, r0, #3
	add r0, r8
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0815A418 @ =0x000006AC
	add r0, r8
	strh r1, [r0]
	ldr r2, [sp, #0xc]
	cmp r2, #0
	bne _0815A420
	ldr r1, _0815A41C @ =0x000006AA
	add r1, r8
	movs r0, #0x28
	strh r0, [r1]
	b _0815A426
	.align 2, 0
_0815A414: .4byte 0x030046A4
_0815A418: .4byte 0x000006AC
_0815A41C: .4byte 0x000006AA
_0815A420:
	ldr r0, _0815A42C @ =0x000006AA
	add r0, r8
	strh r1, [r0]
_0815A426:
	movs r0, #0
	b _0815A544
	.align 2, 0
_0815A42C: .4byte 0x000006AA
_0815A430:
	mov r3, sb
	cmp r3, #1
	beq _0815A450
	cmp r3, #1
	bgt _0815A440
	cmp r3, #0
	beq _0815A44C
	b _0815A474
_0815A440:
	mov r0, sb
	cmp r0, #2
	beq _0815A464
	cmp r0, #3
	beq _0815A468
	b _0815A474
_0815A44C:
	adds r5, #1
	b _0815A474
_0815A450:
	ldr r1, _0815A460 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r5, r5, r0
	b _0815A474
	.align 2, 0
_0815A460: .4byte 0x030046A4
_0815A464:
	mov r5, sl
	b _0815A474
_0815A468:
	ldr r1, _0815A4B4 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r5, r5, r0
_0815A474:
	add r6, sp, #4
	ldr r1, _0815A4B4 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r3, _0815A4B4 @ =0x030046A4
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
	adds r3, r6, #0
	cmp r0, #0
	beq _0815A4B8
	adds r0, #4
	b _0815A4C4
	.align 2, 0
_0815A4B4: .4byte 0x030046A4
_0815A4B8:
	ldr r1, _0815A530 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815A4C4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r5, #0
	strh r0, [r6, #2]
	mov r2, sb
	lsls r0, r2, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	movs r4, #0xd5
	lsls r4, r4, #3
	add r4, r8
	adds r2, r7, #0
	adds r2, #8
	add r0, sp, #4
	ldrh r0, [r0]
	ldrh r1, [r7, #8]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r3, #0
	ldrsh r0, [r4, r3]
	movs r1, #0x14
	bl Div
	strh r0, [r4]
	ldr r4, _0815A534 @ =0x000006AC
	add r4, r8
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0x14
	bl Div
	strh r0, [r4]
	ldr r2, [sp, #0xc]
	cmp r2, #0
	bne _0815A53C
	ldr r1, _0815A538 @ =0x000006AA
	add r1, r8
	movs r0, #0x28
	strh r0, [r1]
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r0, r7, r3
	b _0815A540
	.align 2, 0
_0815A530: .4byte 0x030046A4
_0815A534: .4byte 0x000006AC
_0815A538: .4byte 0x000006AA
_0815A53C:
	ldr r0, _0815A554 @ =0x000006AA
	add r0, r8
_0815A540:
	strh r5, [r0]
	movs r0, #1
_0815A544:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0815A554: .4byte 0x000006AA

	thumb_func_start FUN_0815a558
FUN_0815a558: @ 0x0815A558
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r5, [r0]
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r4, r5, r0
	adds r3, r7, #0
	adds r3, #8
	movs r1, #0xd6
	lsls r1, r1, #3
	adds r2, r5, r1
	ldrh r0, [r2]
	ldrh r1, [r7, #8]
	subs r0, r0, r1
	movs r6, #0
	strh r0, [r4]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0x12
	bl Div
	strh r0, [r4]
	ldr r0, _0815A5C4 @ =0x000006AC
	adds r4, r5, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0x12
	bl Div
	strh r0, [r4]
	ldr r0, _0815A5C8 @ =0x000006AA
	adds r5, r5, r0
	movs r0, #0x14
	strh r0, [r5]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r6, [r0]
	movs r0, #1
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0815A5C4: .4byte 0x000006AC
_0815A5C8: .4byte 0x000006AA

	thumb_func_start FUN_0815a5cc
FUN_0815a5cc: @ 0x0815A5CC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov ip, r0
	ldrb r0, [r4, #5]
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r7, r0, #5
	ldr r0, _0815A60C @ =0x000006C5
	add r0, ip
	add r3, sp, #0x14
	lsls r5, r7, #5
	ldrb r6, [r0]
	ldr r1, _0815A610 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0815A614
	asrs r2, r0, #0xc
	b _0815A61A
	.align 2, 0
_0815A60C: .4byte 0x000006C5
_0815A610: .4byte 0x085B0A08
_0815A614:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0815A61A:
	movs r0, #0
	strh r2, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r6, r0
	cmp r0, #0
	blt _0815A632
	asrs r0, r0, #0xc
	b _0815A638
_0815A632:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0815A638:
	strh r0, [r3, #4]
	ldr r2, _0815A690 @ =0xFFFF0000
	movs r0, #0xb4
	lsls r0, r0, #0x10
	str r0, [sp, #0x1c]
	add r1, sp, #0x1c
	ldr r0, [r1, #4]
	ands r0, r2
	ldr r2, _0815A694 @ =0x0000FFF8
	orrs r0, r2
	str r0, [r1, #4]
	adds r0, r4, #0
	adds r0, #8
	lsls r3, r7, #5
	ldrh r2, [r4]
	str r2, [sp]
	movs r5, #0x8a
	lsls r5, r5, #2
	adds r2, r4, r5
	ldrh r2, [r2]
	str r2, [sp, #4]
	adds r5, #8
	adds r2, r4, r5
	ldrh r2, [r2]
	str r2, [sp, #8]
	adds r5, #8
	adds r2, r4, r5
	ldrh r2, [r2]
	str r2, [sp, #0xc]
	ldr r2, _0815A698 @ =0x000006C6
	add r2, ip
	ldrh r2, [r2]
	str r2, [sp, #0x10]
	add r2, sp, #0x14
	bl FUN_081e996c
	movs r2, #0x99
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	add sp, #0x24
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815A690: .4byte 0xFFFF0000
_0815A694: .4byte 0x0000FFF8
_0815A698: .4byte 0x000006C6

	thumb_func_start FUN_0815a69c
FUN_0815a69c: @ 0x0815A69C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	movs r1, #2
	movs r0, #0xe0
	lsls r0, r0, #3
	add r0, r8
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815A6C8
	movs r0, #1
	b _0815A6CA
_0815A6C8:
	movs r0, #0
_0815A6CA:
	cmp r0, #0
	bne _0815A6D0
	b _0815ABAC
_0815A6D0:
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	mov sl, r0
	ldr r3, _0815A6F8 @ =0x00000256
	adds r4, r6, r3
	ldrh r7, [r4]
	adds r5, r6, #0
	adds r5, #8
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	str r4, [sp, #0x24]
	str r5, [sp, #0x1c]
	cmp r0, #0
	beq _0815A6FC
	adds r0, #4
	b _0815A708
	.align 2, 0
_0815A6F8: .4byte 0x00000256
_0815A6FC:
	ldr r0, _0815A71C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815A708:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0815A720
	cmp r3, #2
	beq _0815A724
	b _0815A728
	.align 2, 0
_0815A71C: .4byte 0x030046A4
_0815A720:
	ldrb r0, [r5, #4]
	b _0815A726
_0815A724:
	ldrb r0, [r5]
_0815A726:
	subs r2, r2, r0
_0815A728:
	mov sb, r2
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815A73A
	adds r0, #4
	b _0815A746
_0815A73A:
	ldr r0, _0815A758 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815A746:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov r8, r0
	ldrb r0, [r6, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _0815A75C
	asrs r0, r0, #6
	b _0815A762
	.align 2, 0
_0815A758: .4byte 0x030046A4
_0815A75C:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0815A762:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _0815A810
	cmp r1, #1
	bgt _0815A774
	cmp r1, #0
	beq _0815A782
	b _0815AA18
_0815A774:
	cmp r1, #2
	bne _0815A77A
	b _0815A8B8
_0815A77A:
	cmp r1, #3
	bne _0815A780
	b _0815A948
_0815A780:
	b _0815AA18
_0815A782:
	adds r5, r7, #1
	movs r4, #0
	movs r0, #0xd6
	lsls r0, r0, #3
	add sl, r0
	ldr r1, _0815A7F4 @ =0x0000046D
	adds r1, r6, r1
	str r1, [sp, #0x3c]
	ldr r2, _0815A7F8 @ =0x0000046B
	adds r2, r6, r2
	str r2, [sp, #0x34]
	ldr r3, _0815A7FC @ =0x00000553
	adds r3, r6, r3
	str r3, [sp, #0x18]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r6, r0
	str r0, [sp, #0x20]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r6, r1
	str r1, [sp, #0x14]
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r6, r2
	str r2, [sp, #0x28]
	ldr r3, _0815A800 @ =0x00000469
	adds r3, r6, r3
	str r3, [sp, #0x2c]
	ldr r0, _0815A804 @ =0x0000046A
	adds r0, r6, r0
	str r0, [sp, #0x30]
	ldr r1, _0815A808 @ =0x00000484
	adds r1, r6, r1
	str r1, [sp, #0xc]
	ldr r2, _0815A80C @ =0x0000046C
	adds r2, r6, r2
	str r2, [sp, #0x38]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r3, r6, r3
	str r3, [sp, #0x10]
_0815A7D6:
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	mov r3, r8
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815A7F0
	adds r5, #1
	adds r4, #1
	cmp r4, #2
	blt _0815A7D6
_0815A7F0:
	subs r5, #1
	b _0815AA6C
	.align 2, 0
_0815A7F4: .4byte 0x0000046D
_0815A7F8: .4byte 0x0000046B
_0815A7FC: .4byte 0x00000553
_0815A800: .4byte 0x00000469
_0815A804: .4byte 0x0000046A
_0815A808: .4byte 0x00000484
_0815A80C: .4byte 0x0000046C
_0815A810:
	ldr r1, _0815A898 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	adds r5, r7, r0
	movs r4, #0
	movs r0, #0xd6
	lsls r0, r0, #3
	add sl, r0
	ldr r2, _0815A89C @ =0x0000046D
	adds r2, r6, r2
	str r2, [sp, #0x3c]
	ldr r3, _0815A8A0 @ =0x0000046B
	adds r3, r6, r3
	str r3, [sp, #0x34]
	ldr r0, _0815A8A4 @ =0x00000553
	adds r0, r6, r0
	str r0, [sp, #0x18]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r6, r2
	str r2, [sp, #0x20]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r6, r3
	str r3, [sp, #0x14]
	movs r0, #0x8d
	lsls r0, r0, #3
	adds r0, r6, r0
	str r0, [sp, #0x28]
	ldr r2, _0815A8A8 @ =0x00000469
	adds r2, r6, r2
	str r2, [sp, #0x2c]
	ldr r3, _0815A8AC @ =0x0000046A
	adds r3, r6, r3
	str r3, [sp, #0x30]
	ldr r0, _0815A8B0 @ =0x00000484
	adds r0, r6, r0
	str r0, [sp, #0xc]
	ldr r2, _0815A8B4 @ =0x0000046C
	adds r2, r6, r2
	str r2, [sp, #0x38]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r3, r6, r3
	str r3, [sp, #0x10]
_0815A86E:
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	mov r3, r8
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815A882
	b _0815A9F0
_0815A882:
	ldr r0, _0815A898 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #2
	blt _0815A86E
	subs r5, r5, r0
	b _0815AA6C
	.align 2, 0
_0815A898: .4byte 0x030046A4
_0815A89C: .4byte 0x0000046D
_0815A8A0: .4byte 0x0000046B
_0815A8A4: .4byte 0x00000553
_0815A8A8: .4byte 0x00000469
_0815A8AC: .4byte 0x0000046A
_0815A8B0: .4byte 0x00000484
_0815A8B4: .4byte 0x0000046C
_0815A8B8:
	subs r5, r7, #1
	movs r4, #0
	movs r2, #0xd6
	lsls r2, r2, #3
	add sl, r2
	ldr r3, _0815A92C @ =0x0000046D
	adds r3, r6, r3
	str r3, [sp, #0x3c]
	ldr r0, _0815A930 @ =0x0000046B
	adds r0, r6, r0
	str r0, [sp, #0x34]
	ldr r1, _0815A934 @ =0x00000553
	adds r1, r6, r1
	str r1, [sp, #0x18]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r6, r2
	str r2, [sp, #0x20]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r6, r3
	str r3, [sp, #0x14]
	movs r0, #0x8d
	lsls r0, r0, #3
	adds r0, r6, r0
	str r0, [sp, #0x28]
	ldr r1, _0815A938 @ =0x00000469
	adds r1, r6, r1
	str r1, [sp, #0x2c]
	ldr r2, _0815A93C @ =0x0000046A
	adds r2, r6, r2
	str r2, [sp, #0x30]
	ldr r3, _0815A940 @ =0x00000484
	adds r3, r6, r3
	str r3, [sp, #0xc]
	ldr r0, _0815A944 @ =0x0000046C
	adds r0, r6, r0
	str r0, [sp, #0x38]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r1, r6, r1
	str r1, [sp, #0x10]
_0815A90C:
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	mov r3, r8
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815A926
	subs r5, #1
	adds r4, #1
	cmp r4, #2
	blt _0815A90C
_0815A926:
	adds r5, #1
	b _0815AA6C
	.align 2, 0
_0815A92C: .4byte 0x0000046D
_0815A930: .4byte 0x0000046B
_0815A934: .4byte 0x00000553
_0815A938: .4byte 0x00000469
_0815A93C: .4byte 0x0000046A
_0815A940: .4byte 0x00000484
_0815A944: .4byte 0x0000046C
_0815A948:
	ldr r1, _0815A9D0 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r7, r0
	movs r4, #0
	movs r3, #0xd6
	lsls r3, r3, #3
	add sl, r3
	ldr r0, _0815A9D4 @ =0x0000046D
	adds r0, r6, r0
	str r0, [sp, #0x3c]
	ldr r2, _0815A9D8 @ =0x0000046B
	adds r2, r6, r2
	str r2, [sp, #0x34]
	ldr r3, _0815A9DC @ =0x00000553
	adds r3, r6, r3
	str r3, [sp, #0x18]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r6, r0
	str r0, [sp, #0x20]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r2, r6, r2
	str r2, [sp, #0x14]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r6, r3
	str r3, [sp, #0x28]
	ldr r0, _0815A9E0 @ =0x00000469
	adds r0, r6, r0
	str r0, [sp, #0x2c]
	ldr r2, _0815A9E4 @ =0x0000046A
	adds r2, r6, r2
	str r2, [sp, #0x30]
	ldr r3, _0815A9E8 @ =0x00000484
	adds r3, r6, r3
	str r3, [sp, #0xc]
	ldr r0, _0815A9EC @ =0x0000046C
	adds r0, r6, r0
	str r0, [sp, #0x38]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r2, r6, r2
	str r2, [sp, #0x10]
_0815A9A6:
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	mov r3, r8
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815AA04
	ldr r0, _0815A9D0 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r5, r5, r0
	adds r4, #1
	cmp r4, #2
	blt _0815A9A6
	adds r5, r5, r0
	b _0815AA6C
	.align 2, 0
_0815A9D0: .4byte 0x030046A4
_0815A9D4: .4byte 0x0000046D
_0815A9D8: .4byte 0x0000046B
_0815A9DC: .4byte 0x00000553
_0815A9E0: .4byte 0x00000469
_0815A9E4: .4byte 0x0000046A
_0815A9E8: .4byte 0x00000484
_0815A9EC: .4byte 0x0000046C
_0815A9F0:
	ldr r1, _0815AA00 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	subs r5, r5, r0
	b _0815AA6C
	.align 2, 0
_0815AA00: .4byte 0x030046A4
_0815AA04:
	ldr r1, _0815AA14 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r0, [r0, r7]
	adds r5, r5, r0
	b _0815AA6C
	.align 2, 0
_0815AA14: .4byte 0x030046A4
_0815AA18:
	ldr r0, [sp, #0x24]
	ldrh r5, [r0]
	movs r1, #0xd6
	lsls r1, r1, #3
	add sl, r1
	ldr r2, _0815AAB0 @ =0x0000046D
	adds r2, r6, r2
	str r2, [sp, #0x3c]
	ldr r3, _0815AAB4 @ =0x0000046B
	adds r3, r6, r3
	str r3, [sp, #0x34]
	ldr r4, _0815AAB8 @ =0x00000553
	adds r4, r6, r4
	str r4, [sp, #0x18]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r7, r6, r7
	str r7, [sp, #0x20]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r6, r0
	str r0, [sp, #0x14]
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r1, r6, r1
	str r1, [sp, #0x28]
	ldr r2, _0815AABC @ =0x00000469
	adds r2, r6, r2
	str r2, [sp, #0x2c]
	ldr r3, _0815AAC0 @ =0x0000046A
	adds r3, r6, r3
	str r3, [sp, #0x30]
	ldr r4, _0815AAC4 @ =0x00000484
	adds r4, r6, r4
	str r4, [sp, #0xc]
	ldr r7, _0815AAC8 @ =0x0000046C
	adds r7, r6, r7
	str r7, [sp, #0x38]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r0, r6, r0
	str r0, [sp, #0x10]
_0815AA6C:
	ldr r1, [sp, #0x24]
	ldrh r1, [r1]
	cmp r5, r1
	bne _0815AAD0
	mov r7, sl
	ldr r2, _0815AACC @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _0815AACC @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r7]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	bne _0815AB08
	b _0815AB10
	.align 2, 0
_0815AAB0: .4byte 0x0000046D
_0815AAB4: .4byte 0x0000046B
_0815AAB8: .4byte 0x00000553
_0815AABC: .4byte 0x00000469
_0815AAC0: .4byte 0x0000046A
_0815AAC4: .4byte 0x00000484
_0815AAC8: .4byte 0x0000046C
_0815AACC: .4byte 0x030046A4
_0815AAD0:
	mov r7, sl
	ldr r1, _0815AB0C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r3, _0815AB0C @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r7]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815AB10
_0815AB08:
	adds r0, #4
	b _0815AB1C
	.align 2, 0
_0815AB0C: .4byte 0x030046A4
_0815AB10:
	ldr r3, _0815ABA0 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815AB1C:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r7, #2]
	mov r4, r8
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r7, #4]
	ldr r2, _0815ABA4 @ =FUN_08155658
	movs r0, #0x2a
	movs r1, #0
	movs r3, #1
	ldr r5, [sp, #0x3c]
	strb r3, [r5]
	ldr r7, [sp, #0x34]
	strb r1, [r7]
	ldr r4, [sp, #0x18]
	strb r0, [r4]
	ldr r5, [sp, #0x20]
	str r2, [r5]
	movs r4, #0
	ldr r7, [sp, #0x14]
	strh r1, [r7]
	movs r0, #3
	ldr r2, [sp, #0x28]
	strb r0, [r2]
	ldr r5, [sp, #0x2c]
	strb r4, [r5]
	ldr r7, [sp, #0x30]
	strb r4, [r7]
	ldr r0, [sp, #0xc]
	str r1, [r0]
	ldr r1, [sp, #0x38]
	strb r3, [r1]
	ldr r0, _0815ABA8 @ =0x03002BE0
	mov r2, sp
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldr r4, [sp, #0x1c]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	movs r7, #4
	ldrsh r1, [r2, r7]
	bl FUN_0823785c
	strb r0, [r6, #5]
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r2, [sp, #0x10]
	b _0815B174
	.align 2, 0
_0815ABA0: .4byte 0x030046A4
_0815ABA4: .4byte FUN_08155658
_0815ABA8: .4byte 0x03002BE0
_0815ABAC:
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r1, [r0]
	adds r1, #0x20
	movs r2, #0xff
	ands r1, r2
	asrs r1, r1, #6
	ldrb r0, [r6, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	subs r1, r1, r0
	lsls r1, r1, #6
	cmp r1, #0x80
	ble _0815ABD8
	ldr r4, _0815ABD4 @ =0xFFFFFF00
	adds r1, r1, r4
	b _0815ABE6
	.align 2, 0
_0815ABD4: .4byte 0xFFFFFF00
_0815ABD8:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0815ABE6
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r1, r5
_0815ABE6:
	cmp r1, #0
	bge _0815ABEC
	rsbs r1, r1, #0
_0815ABEC:
	cmp r1, #0x17
	ble _0815ABF2
	b _0815B198
_0815ABF2:
	movs r7, #0xf2
	lsls r7, r7, #1
	adds r0, r6, r7
	movs r1, #0xda
	lsls r1, r1, #3
	add r1, r8
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blo _0815AC08
	b _0815B0F8
_0815AC08:
	ldr r1, _0815AC48 @ =0x000006E4
	add r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	ble _0815AC16
	b _0815B288
_0815AC16:
	movs r0, #0xde
	lsls r0, r0, #3
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r1]
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [sp, #8]
	ldr r5, _0815AC4C @ =0x00000256
	adds r4, r6, r5
	ldrh r7, [r4]
	adds r5, r6, #0
	adds r5, #8
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	str r4, [sp, #0x24]
	cmp r0, #0
	beq _0815AC50
	adds r0, #4
	b _0815AC5C
	.align 2, 0
_0815AC48: .4byte 0x000006E4
_0815AC4C: .4byte 0x00000256
_0815AC50:
	ldr r0, _0815AC70 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815AC5C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0815AC74
	cmp r3, #2
	beq _0815AC78
	b _0815AC7C
	.align 2, 0
_0815AC70: .4byte 0x030046A4
_0815AC74:
	ldrb r0, [r5, #4]
	b _0815AC7A
_0815AC78:
	ldrb r0, [r5]
_0815AC7A:
	subs r2, r2, r0
_0815AC7C:
	mov sl, r2
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815AC8E
	adds r0, #4
	b _0815AC9A
_0815AC8E:
	ldr r0, _0815ACAC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815AC9A:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov sb, r0
	ldrb r0, [r6, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _0815ACB0
	asrs r0, r0, #6
	b _0815ACB6
	.align 2, 0
_0815ACAC: .4byte 0x030046A4
_0815ACB0:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0815ACB6:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _0815AD6C
	cmp r1, #1
	bgt _0815ACC8
	cmp r1, #0
	beq _0815ACD6
	b _0815AF8C
_0815ACC8:
	cmp r1, #2
	bne _0815ACCE
	b _0815AE1C
_0815ACCE:
	cmp r1, #3
	bne _0815ACD4
	b _0815AEB4
_0815ACD4:
	b _0815AF8C
_0815ACD6:
	adds r5, r7, #1
	movs r4, #0
	movs r0, #0xe0
	lsls r0, r0, #3
	add r8, r0
	ldr r1, _0815AD50 @ =0x0000046D
	adds r1, r6, r1
	str r1, [sp, #0x3c]
	ldr r2, _0815AD54 @ =0x0000046B
	adds r2, r6, r2
	str r2, [sp, #0x34]
	ldr r3, _0815AD58 @ =0x00000553
	adds r3, r6, r3
	str r3, [sp, #0x18]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r6, r0
	str r0, [sp, #0x20]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r6, r1
	str r1, [sp, #0x14]
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r6, r2
	str r2, [sp, #0x28]
	ldr r3, _0815AD5C @ =0x00000469
	adds r3, r6, r3
	str r3, [sp, #0x2c]
	ldr r0, _0815AD60 @ =0x0000046A
	adds r0, r6, r0
	str r0, [sp, #0x30]
	ldr r1, _0815AD64 @ =0x00000484
	adds r1, r6, r1
	str r1, [sp, #0xc]
	ldr r2, _0815AD68 @ =0x0000046C
	adds r2, r6, r2
	str r2, [sp, #0x38]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r3, r6, r3
	str r3, [sp, #0x10]
	ldr r0, [sp, #8]
	movs r1, #0xd6
	lsls r1, r1, #3
	adds r6, r0, r1
_0815AD32:
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sl
	mov r3, sb
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815AD4C
	adds r5, #1
	adds r4, #1
	cmp r4, #2
	blt _0815AD32
_0815AD4C:
	subs r5, #1
	b _0815AFE8
	.align 2, 0
_0815AD50: .4byte 0x0000046D
_0815AD54: .4byte 0x0000046B
_0815AD58: .4byte 0x00000553
_0815AD5C: .4byte 0x00000469
_0815AD60: .4byte 0x0000046A
_0815AD64: .4byte 0x00000484
_0815AD68: .4byte 0x0000046C
_0815AD6C:
	ldr r1, _0815ADFC @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r5, r7, r0
	movs r4, #0
	movs r3, #0xe0
	lsls r3, r3, #3
	add r8, r3
	ldr r0, _0815AE00 @ =0x0000046D
	adds r0, r6, r0
	str r0, [sp, #0x3c]
	ldr r2, _0815AE04 @ =0x0000046B
	adds r2, r6, r2
	str r2, [sp, #0x34]
	ldr r3, _0815AE08 @ =0x00000553
	adds r3, r6, r3
	str r3, [sp, #0x18]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r6, r0
	str r0, [sp, #0x20]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r2, r6, r2
	str r2, [sp, #0x14]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r6, r3
	str r3, [sp, #0x28]
	ldr r0, _0815AE0C @ =0x00000469
	adds r0, r6, r0
	str r0, [sp, #0x2c]
	ldr r2, _0815AE10 @ =0x0000046A
	adds r2, r6, r2
	str r2, [sp, #0x30]
	ldr r3, _0815AE14 @ =0x00000484
	adds r3, r6, r3
	str r3, [sp, #0xc]
	ldr r0, _0815AE18 @ =0x0000046C
	adds r0, r6, r0
	str r0, [sp, #0x38]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r2, r6, r2
	str r2, [sp, #0x10]
	ldr r3, [sp, #8]
	movs r0, #0xd6
	lsls r0, r0, #3
	adds r6, r3, r0
_0815ADD2:
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sl
	mov r3, sb
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815ADE6
	b _0815AF64
_0815ADE6:
	ldr r0, _0815ADFC @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #2
	blt _0815ADD2
	subs r5, r5, r0
	b _0815AFE8
	.align 2, 0
_0815ADFC: .4byte 0x030046A4
_0815AE00: .4byte 0x0000046D
_0815AE04: .4byte 0x0000046B
_0815AE08: .4byte 0x00000553
_0815AE0C: .4byte 0x00000469
_0815AE10: .4byte 0x0000046A
_0815AE14: .4byte 0x00000484
_0815AE18: .4byte 0x0000046C
_0815AE1C:
	subs r5, r7, #1
	movs r4, #0
	movs r2, #0xe0
	lsls r2, r2, #3
	add r8, r2
	ldr r3, _0815AE98 @ =0x0000046D
	adds r3, r6, r3
	str r3, [sp, #0x3c]
	ldr r0, _0815AE9C @ =0x0000046B
	adds r0, r6, r0
	str r0, [sp, #0x34]
	ldr r1, _0815AEA0 @ =0x00000553
	adds r1, r6, r1
	str r1, [sp, #0x18]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r6, r2
	str r2, [sp, #0x20]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r6, r3
	str r3, [sp, #0x14]
	movs r0, #0x8d
	lsls r0, r0, #3
	adds r0, r6, r0
	str r0, [sp, #0x28]
	ldr r1, _0815AEA4 @ =0x00000469
	adds r1, r6, r1
	str r1, [sp, #0x2c]
	ldr r2, _0815AEA8 @ =0x0000046A
	adds r2, r6, r2
	str r2, [sp, #0x30]
	ldr r3, _0815AEAC @ =0x00000484
	adds r3, r6, r3
	str r3, [sp, #0xc]
	ldr r0, _0815AEB0 @ =0x0000046C
	adds r0, r6, r0
	str r0, [sp, #0x38]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r1, r6, r1
	str r1, [sp, #0x10]
	ldr r2, [sp, #8]
	movs r3, #0xd6
	lsls r3, r3, #3
	adds r6, r2, r3
_0815AE78:
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sl
	mov r3, sb
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815AE92
	subs r5, #1
	adds r4, #1
	cmp r4, #2
	blt _0815AE78
_0815AE92:
	adds r5, #1
	b _0815AFE8
	.align 2, 0
_0815AE98: .4byte 0x0000046D
_0815AE9C: .4byte 0x0000046B
_0815AEA0: .4byte 0x00000553
_0815AEA4: .4byte 0x00000469
_0815AEA8: .4byte 0x0000046A
_0815AEAC: .4byte 0x00000484
_0815AEB0: .4byte 0x0000046C
_0815AEB4:
	ldr r1, _0815AF44 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	subs r5, r7, r0
	movs r4, #0
	movs r0, #0xe0
	lsls r0, r0, #3
	add r8, r0
	ldr r2, _0815AF48 @ =0x0000046D
	adds r2, r6, r2
	str r2, [sp, #0x3c]
	ldr r3, _0815AF4C @ =0x0000046B
	adds r3, r6, r3
	str r3, [sp, #0x34]
	ldr r0, _0815AF50 @ =0x00000553
	adds r0, r6, r0
	str r0, [sp, #0x18]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r6, r2
	str r2, [sp, #0x20]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r6, r3
	str r3, [sp, #0x14]
	movs r0, #0x8d
	lsls r0, r0, #3
	adds r0, r6, r0
	str r0, [sp, #0x28]
	ldr r2, _0815AF54 @ =0x00000469
	adds r2, r6, r2
	str r2, [sp, #0x2c]
	ldr r3, _0815AF58 @ =0x0000046A
	adds r3, r6, r3
	str r3, [sp, #0x30]
	ldr r0, _0815AF5C @ =0x00000484
	adds r0, r6, r0
	str r0, [sp, #0xc]
	ldr r2, _0815AF60 @ =0x0000046C
	adds r2, r6, r2
	str r2, [sp, #0x38]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r3, r6, r3
	str r3, [sp, #0x10]
	ldr r0, [sp, #8]
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r6, r0, r2
_0815AF1A:
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sl
	mov r3, sb
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815AF78
	ldr r0, _0815AF44 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r5, r5, r0
	adds r4, #1
	cmp r4, #2
	blt _0815AF1A
	adds r5, r5, r0
	b _0815AFE8
	.align 2, 0
_0815AF44: .4byte 0x030046A4
_0815AF48: .4byte 0x0000046D
_0815AF4C: .4byte 0x0000046B
_0815AF50: .4byte 0x00000553
_0815AF54: .4byte 0x00000469
_0815AF58: .4byte 0x0000046A
_0815AF5C: .4byte 0x00000484
_0815AF60: .4byte 0x0000046C
_0815AF64:
	ldr r1, _0815AF74 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	subs r5, r5, r0
	b _0815AFE8
	.align 2, 0
_0815AF74: .4byte 0x030046A4
_0815AF78:
	ldr r1, _0815AF88 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r0, [r0, r7]
	adds r5, r5, r0
	b _0815AFE8
	.align 2, 0
_0815AF88: .4byte 0x030046A4
_0815AF8C:
	ldr r0, [sp, #0x24]
	ldrh r5, [r0]
	movs r1, #0xe0
	lsls r1, r1, #3
	add r8, r1
	ldr r2, _0815B028 @ =0x0000046D
	adds r2, r6, r2
	str r2, [sp, #0x3c]
	ldr r3, _0815B02C @ =0x0000046B
	adds r3, r6, r3
	str r3, [sp, #0x34]
	ldr r4, _0815B030 @ =0x00000553
	adds r4, r6, r4
	str r4, [sp, #0x18]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r7, r6, r7
	str r7, [sp, #0x20]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r6, r0
	str r0, [sp, #0x14]
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r1, r6, r1
	str r1, [sp, #0x28]
	ldr r2, _0815B034 @ =0x00000469
	adds r2, r6, r2
	str r2, [sp, #0x2c]
	ldr r3, _0815B038 @ =0x0000046A
	adds r3, r6, r3
	str r3, [sp, #0x30]
	ldr r4, _0815B03C @ =0x00000484
	adds r4, r6, r4
	str r4, [sp, #0xc]
	ldr r7, _0815B040 @ =0x0000046C
	adds r7, r6, r7
	str r7, [sp, #0x38]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r0, r6, r0
	str r0, [sp, #0x10]
	ldr r1, [sp, #8]
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r6, r1, r2
_0815AFE8:
	ldr r3, [sp, #0x24]
	ldrh r3, [r3]
	cmp r5, r3
	bne _0815B048
	ldr r4, _0815B044 @ =0x030046A4
	ldr r0, [r4]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r1, [r0, r7]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _0815B044 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	bne _0815B07E
	b _0815B088
	.align 2, 0
_0815B028: .4byte 0x0000046D
_0815B02C: .4byte 0x0000046B
_0815B030: .4byte 0x00000553
_0815B034: .4byte 0x00000469
_0815B038: .4byte 0x0000046A
_0815B03C: .4byte 0x00000484
_0815B040: .4byte 0x0000046C
_0815B044: .4byte 0x030046A4
_0815B048:
	ldr r4, _0815B084 @ =0x030046A4
	ldr r0, [r4]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r1, [r0, r7]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _0815B084 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815B088
_0815B07E:
	adds r0, #4
	b _0815B094
	.align 2, 0
_0815B084: .4byte 0x030046A4
_0815B088:
	ldr r3, _0815B0F0 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815B094:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r6, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r2, _0815B0F4 @ =FUN_08154de8
	movs r0, #0x21
	movs r1, #0
	movs r3, #1
	ldr r4, [sp, #0x3c]
	strb r3, [r4]
	ldr r5, [sp, #0x34]
	strb r1, [r5]
	ldr r7, [sp, #0x18]
	strb r0, [r7]
	ldr r0, [sp, #0x20]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x14]
	strh r1, [r4]
	movs r0, #3
	ldr r5, [sp, #0x28]
	strb r0, [r5]
	ldr r7, [sp, #0x2c]
	strb r2, [r7]
	ldr r0, [sp, #0x30]
	strb r2, [r0]
	ldr r2, [sp, #0xc]
	str r1, [r2]
	ldr r4, [sp, #0x38]
	strb r3, [r4]
	mov r5, r8
	ldr r0, [r5]
	orrs r0, r3
	str r0, [r5]
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r7, [sp, #0x10]
	ldrh r1, [r7]
	orrs r0, r1
	strh r0, [r7]
	b _0815B288
	.align 2, 0
_0815B0F0: .4byte 0x030046A4
_0815B0F4: .4byte FUN_08154de8
_0815B0F8:
	ldr r1, _0815B17C @ =0x000006E2
	add r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	ble _0815B106
	b _0815B288
_0815B106:
	ldr r0, _0815B180 @ =0x000006F2
	add r0, r8
	ldrh r0, [r0]
	movs r4, #0
	movs r5, #0
	strh r0, [r1]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r0, [r0]
	adds r0, #0x20
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r6, #5]
	ldr r3, _0815B184 @ =FUN_08156440
	movs r1, #0x30
	ldr r7, _0815B188 @ =0x0000046D
	adds r0, r6, r7
	movs r2, #1
	strb r2, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r4, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r5, [r0]
	movs r1, #2
	subs r7, #0xeb
	adds r0, r6, r7
	strb r4, [r0]
	ldr r3, _0815B18C @ =0x00000469
	adds r0, r6, r3
	strb r1, [r0]
	ldr r4, _0815B190 @ =0x0000046A
	adds r0, r6, r4
	strb r2, [r0]
	adds r7, #0x1c
	adds r0, r6, r7
	str r5, [r0]
	ldr r1, _0815B194 @ =0x0000046C
	adds r0, r6, r1
	strb r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
_0815B174:
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _0815B288
	.align 2, 0
_0815B17C: .4byte 0x000006E2
_0815B180: .4byte 0x000006F2
_0815B184: .4byte FUN_08156440
_0815B188: .4byte 0x0000046D
_0815B18C: .4byte 0x00000469
_0815B190: .4byte 0x0000046A
_0815B194: .4byte 0x0000046C
_0815B198:
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r5, _0815B22C @ =0x0000046D
	adds r0, r6, r5
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r7, _0815B230 @ =0x0000046B
	adds r0, r6, r7
	strb r2, [r0]
	adds r5, #0xe6
	adds r0, r6, r5
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r6, r7
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r5, #0xeb
	adds r0, r6, r5
	strb r1, [r0]
	ldr r7, _0815B234 @ =0x00000469
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _0815B238 @ =0x0000046A
	adds r0, r6, r1
	strb r3, [r0]
	ldr r3, _0815B23C @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r6, r5
	strb r4, [r0]
	adds r7, #0x19
	adds r1, r6, r7
	movs r0, #2
	strh r0, [r1]
	movs r0, #4
	ldr r1, _0815B240 @ =0x00000222
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _0815B244 @ =0x000004A4
	adds r0, r6, r2
	ldr r5, [r0]
	adds r7, r6, #0
	adds r7, #8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0815B248
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r6, r4
	b _0815B26E
	.align 2, 0
_0815B22C: .4byte 0x0000046D
_0815B230: .4byte 0x0000046B
_0815B234: .4byte 0x00000469
_0815B238: .4byte 0x0000046A
_0815B23C: .4byte 0x00000484
_0815B240: .4byte 0x00000222
_0815B244: .4byte 0x000004A4
_0815B248:
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0815B268
	cmp r0, #2
	beq _0815B264
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0815B264:
	movs r0, #1
	b _0815B278
_0815B268:
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r6, r5
_0815B26E:
	ldr r1, _0815B298 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0815B278:
	cmp r0, #0
	bne _0815B288
	ldr r7, _0815B29C @ =0x000005C4
	adds r0, r6, r7
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
_0815B288:
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815B298: .4byte 0xFFFFFDFF
_0815B29C: .4byte 0x000005C4

	thumb_func_start FUN_0815b2a0
FUN_0815b2a0: @ 0x0815B2A0
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	movs r1, #2
	movs r3, #0xe0
	lsls r3, r3, #3
	adds r0, r2, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815B2C0
	movs r0, #1
	b _0815B2C2
_0815B2C0:
	movs r0, #0
_0815B2C2:
	cmp r0, #0
	bne _0815B30E
	ldr r1, _0815B314 @ =0x000006E2
	adds r0, r2, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bgt _0815B30E
	ldrb r0, [r4, #5]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	cmp r0, #0
	beq _0815B2EC
	cmp r0, #2
	beq _0815B2EC
	cmp r0, #4
	beq _0815B2EC
	cmp r0, #6
	bne _0815B30E
_0815B2EC:
	ldr r0, _0815B314 @ =0x000006E2
	adds r1, r2, r0
	movs r0, #0x14
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_0815a5cc
	movs r1, #0x99
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_081e9094
	movs r0, #0xe8
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0815B30E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0815B314: .4byte 0x000006E2

	thumb_func_start FUN_0815b318
FUN_0815b318: @ 0x0815B318
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r1, #0
	mov r2, sp
	adds r3, r4, #0
	adds r3, #8
	ldrh r0, [r5]
	ldrh r1, [r4, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r5, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	adds r0, #0x20
	asrs r6, r0, #6
	movs r0, #3
	ands r6, r0
	ldr r1, _0815B394 @ =0x00000256
	adds r0, r4, r1
	ldrh r3, [r0]
	ldr r2, _0815B398 @ =0x00000472
	adds r4, r4, r2
	ldrh r0, [r4]
	lsrs r0, r0, #8
	mov r8, r0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0815B390
	cmp r1, #0
	blt _0815B390
	ldr r0, _0815B39C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815B390
	ldr r0, _0815B3A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815B3A4
_0815B390:
	movs r0, #0
	b _0815B3B2
	.align 2, 0
_0815B394: .4byte 0x00000256
_0815B398: .4byte 0x00000472
_0815B39C: .4byte 0x030046A8
_0815B3A0: .4byte 0x030046AC
_0815B3A4:
	ldr r0, _0815B3E0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_0815B3B2:
	mov sb, r0
	mov r0, sb
	movs r1, #1
	str r3, [sp, #8]
	bl FUN_08234224
	ldr r7, _0815B3E0 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	movs r2, #6
	ldrsh r0, [r0, r2]
	adds r5, r1, #0
	muls r5, r0, r5
	ldr r3, [sp, #8]
	cmp r6, #1
	beq _0815B444
	cmp r6, #1
	bgt _0815B3E4
	cmp r6, #0
	beq _0815B3EE
	b _0815B512
	.align 2, 0
_0815B3E0: .4byte 0x030046A4
_0815B3E4:
	cmp r6, #2
	beq _0815B484
	cmp r6, #3
	beq _0815B4D4
	b _0815B512
_0815B3EE:
	adds r4, r3, #1
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	cmp r5, r0
	blt _0815B406
	b _0815B512
_0815B406:
	lsls r0, r4, #2
	adds r6, r0, #0
	adds r6, #0xc
_0815B40C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815B41C
	adds r0, #4
	b _0815B422
_0815B41C:
	ldr r0, [r7]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_0815B422:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bhi _0815B512
	cmp r4, sb
	beq _0815B4D0
	adds r6, #4
	adds r4, #1
	adds r5, #1
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _0815B40C
	b _0815B512
_0815B444:
	adds r4, r3, r1
	cmp r5, r4
	ble _0815B512
	adds r6, r7, #0
_0815B44C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815B45C
	adds r0, #4
	b _0815B466
_0815B45C:
	ldr r0, [r6]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815B466:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bhi _0815B512
	cmp r4, sb
	beq _0815B4D0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r4, r0
	cmp r5, r4
	bgt _0815B44C
	b _0815B512
_0815B484:
	subs r4, r3, #1
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	cmp r5, #0
	blt _0815B512
	lsls r0, r4, #2
	adds r6, r0, #0
	adds r6, #0xc
_0815B498:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815B4A8
	adds r0, #4
	b _0815B4B0
_0815B4A8:
	ldr r0, _0815B4CC @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_0815B4B0:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bhi _0815B512
	cmp r4, sb
	beq _0815B4D0
	subs r6, #4
	subs r4, #1
	subs r5, #1
	cmp r5, #0
	bge _0815B498
	b _0815B512
	.align 2, 0
_0815B4CC: .4byte 0x030046A4
_0815B4D0:
	movs r0, #0
	b _0815B514
_0815B4D4:
	subs r4, r3, r1
	cmp r4, #0
	blt _0815B512
	adds r5, r7, #0
_0815B4DC:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815B4EC
	adds r0, #4
	b _0815B4F6
_0815B4EC:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815B4F6:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, r8
	bhi _0815B512
	cmp r4, sb
	beq _0815B4D0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r4, r4, r0
	cmp r4, #0
	bge _0815B4DC
_0815B512:
	movs r0, #1
_0815B514:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0815b524
FUN_0815b524: @ 0x0815B524
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x9c
	ldr r2, _0815B578 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0815B57C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0815B580 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldrb r0, [r4, #2]
	cmp r1, r0
	bne _0815B55E
	adds r0, r1, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_0815B55E:
	movs r0, #0
	strb r1, [r4, #2]
	strb r0, [r4, #3]
	ldr r0, [r4, #4]
	bl FUN_08234f6c
	ldrb r1, [r4, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0815B578: .4byte 0x030046B8
_0815B57C: .4byte 0x000003FF
_0815B580: .4byte 0x0203B400

	thumb_func_start FUN_0815b584
FUN_0815b584: @ 0x0815B584
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
	ldr r0, [r0]
	mov sb, r0
	ldr r0, _0815B704 @ =0x000006FC
	add r0, sb
	ldrh r1, [r0]
	mov r0, sp
	movs r2, #0
	movs r3, #0
	bl FUN_08234de8
	movs r2, #0
	mov r8, r2
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r2, [r0]
	movs r4, #8
	ldrsh r0, [r2, r4]
	movs r6, #8
	ldrsh r1, [r5, r6]
	subs r0, r0, r1
	movs r7, #0xc
	ldrsh r1, [r2, r7]
	movs r3, #0xc
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, _0815B708 @ =0x085B0A08
	adds r1, r0, #0
	adds r1, #0x40
	movs r2, #0xff
	ands r1, r2
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r4, #0
	ldrsh r1, [r1, r4]
	lsls r2, r1, #2
	adds r2, r2, r1
	lsls r2, r2, #5
	lsrs r2, r2, #0x10
	ldr r7, _0815B70C @ =0xFFFF0000
	ldr r1, [sp, #0xc]
	ands r1, r7
	orrs r1, r2
	str r1, [sp, #0xc]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r6, #0
	ldrsh r0, [r0, r6]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #5
	lsrs r1, r1, #0x10
	add r4, sp, #0xc
	ldr r0, [r4, #4]
	ands r0, r7
	orrs r0, r1
	str r0, [r4, #4]
	ldr r0, [sp, #4]
	bl FUN_08234f6c
	adds r3, r0, #0
	movs r6, #0
	ldr r0, [sp, #4]
	ldrb r0, [r0]
	cmp r8, r0
	bge _0815B6B2
	ldr r0, _0815B710 @ =0x000006FE
	add r0, sb
	mov sl, r0
	mov ip, r7
	mov r1, sp
	adds r1, #0x14
	str r1, [sp, #0x1c]
_0815B632:
	mov r2, sl
	ldrh r0, [r2]
	cmp r0, r6
	beq _0815B6A8
	ldrh r1, [r3]
	ldrh r0, [r5, #8]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x14]
	mov r4, ip
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x14]
	ldrh r1, [r3, #2]
	ldrh r0, [r5, #0xc]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r2, #4]
	ldr r7, [sp, #0x1c]
	movs r1, #0
	ldrsh r0, [r7, r1]
	adds r4, r2, #0
	cmp r0, #0
	bge _0815B670
	rsbs r0, r0, #0
_0815B670:
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	bgt _0815B686
	movs r2, #4
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bge _0815B682
	rsbs r0, r0, #0
_0815B682:
	cmp r0, r1
	ble _0815B6A8
_0815B686:
	add r0, sp, #0xc
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r2, [sp, #0x1c]
	movs r7, #0
	ldrsh r0, [r2, r7]
	muls r1, r0, r1
	mov r0, sp
	movs r7, #0x10
	ldrsh r2, [r0, r7]
	movs r7, #4
	ldrsh r0, [r4, r7]
	muls r0, r2, r0
	adds r1, r1, r0
	cmp r1, #0
	blt _0815B720
	adds r3, #8
_0815B6A8:
	adds r6, #1
	ldr r0, [sp, #4]
	ldrb r0, [r0]
	cmp r6, r0
	blt _0815B632
_0815B6B2:
	movs r0, #0
	cmp r0, #0
	bne _0815B726
	ldr r2, _0815B714 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0815B718 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0815B71C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [sp, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r4, _0815B710 @ =0x000006FE
	add r4, sb
	ldrh r2, [r4]
	cmp r8, r2
	bne _0815B6F4
	adds r0, #1
	ldr r1, [sp, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
_0815B6F4:
	movs r1, #0
	mov r3, r8
	strh r3, [r4]
	mov r0, sp
	mov r4, r8
	strb r4, [r0, #2]
	b _0815B736
	.align 2, 0
_0815B704: .4byte 0x000006FC
_0815B708: .4byte 0x085B0A08
_0815B70C: .4byte 0xFFFF0000
_0815B710: .4byte 0x000006FE
_0815B714: .4byte 0x030046B8
_0815B718: .4byte 0x000003FF
_0815B71C: .4byte 0x0203B400
_0815B720:
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
_0815B726:
	ldr r0, _0815B784 @ =0x000006FE
	add r0, sb
	movs r1, #0
	mov r6, r8
	strh r6, [r0]
	mov r0, sp
	mov r7, r8
	strb r7, [r0, #2]
_0815B736:
	strb r1, [r0, #3]
	ldr r0, [sp, #4]
	bl FUN_08234f6c
	str r0, [sp, #8]
	mov r1, sp
	ldrb r1, [r1, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [sp, #8]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r0, [sp, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [sp, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0815B77E
	cmp r1, #0
	blt _0815B77E
	ldr r0, _0815B788 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815B77E
	ldr r0, _0815B78C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815B790
_0815B77E:
	movs r4, #0
	b _0815B79E
	.align 2, 0
_0815B784: .4byte 0x000006FE
_0815B788: .4byte 0x030046A8
_0815B78C: .4byte 0x030046AC
_0815B790:
	ldr r0, _0815B7B0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0815B79E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815B7B4
	adds r0, #4
	b _0815B7C0
	.align 2, 0
_0815B7B0: .4byte 0x030046A4
_0815B7B4:
	ldr r0, _0815B7D4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815B7C0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0815B7D8
	cmp r2, #2
	beq _0815B7DC
	b _0815B7E0
	.align 2, 0
_0815B7D4: .4byte 0x030046A4
_0815B7D8:
	ldrb r0, [r6, #4]
	b _0815B7DE
_0815B7DC:
	ldrb r0, [r6]
_0815B7DE:
	subs r1, r1, r0
_0815B7E0:
	strh r1, [r6, #2]
	ldr r2, _0815B80C @ =0x000004A4
	adds r0, r5, r2
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r4, [r0]
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0815B810
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r5, r4
	b _0815B836
	.align 2, 0
_0815B80C: .4byte 0x000004A4
_0815B810:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0815B830
	cmp r0, #2
	beq _0815B82C
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0815B82C:
	movs r0, #1
	b _0815B840
_0815B830:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r5, r6
_0815B836:
	ldr r1, _0815B890 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0815B840:
	adds r4, r0, #0
	cmp r4, #0
	bne _0815B8B4
	ldr r1, _0815B894 @ =FUN_080e48d0
	ldr r7, _0815B898 @ =0x0000046D
	adds r0, r5, r7
	movs r3, #1
	strb r3, [r0]
	ldr r2, _0815B89C @ =0x0000046B
	adds r0, r5, r2
	strb r4, [r0]
	ldr r6, _0815B8A0 @ =0x00000553
	adds r0, r5, r6
	strb r4, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	ldr r7, _0815B8A4 @ =0x00000469
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _0815B8A8 @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _0815B8AC @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	ldr r4, _0815B8B0 @ =0x0000046C
	adds r0, r5, r4
	strb r3, [r0]
	b _0815B8C0
	.align 2, 0
_0815B890: .4byte 0xFFFFFDFF
_0815B894: .4byte FUN_080e48d0
_0815B898: .4byte 0x0000046D
_0815B89C: .4byte 0x0000046B
_0815B8A0: .4byte 0x00000553
_0815B8A4: .4byte 0x00000469
_0815B8A8: .4byte 0x0000046A
_0815B8AC: .4byte 0x00000484
_0815B8B0: .4byte 0x0000046C
_0815B8B4:
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
_0815B8C0:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0815b8d0
FUN_0815b8d0: @ 0x0815B8D0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x78
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #8]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r7, r2
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
	blt _0815B920
	cmp r1, #0
	blt _0815B920
	ldr r0, _0815B924 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815B920
	ldr r0, _0815B928 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815B92C
_0815B920:
	movs r4, #0
	b _0815B93A
	.align 2, 0
_0815B924: .4byte 0x030046A8
_0815B928: .4byte 0x030046AC
_0815B92C:
	ldr r0, _0815B94C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0815B93A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815B950
	adds r0, #4
	b _0815B95C
	.align 2, 0
_0815B94C: .4byte 0x030046A4
_0815B950:
	ldr r0, _0815B970 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815B95C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0815B974
	cmp r2, #2
	beq _0815B978
	b _0815B97C
	.align 2, 0
_0815B970: .4byte 0x030046A4
_0815B974:
	ldrb r0, [r5, #4]
	b _0815B97A
_0815B978:
	ldrb r0, [r5]
_0815B97A:
	subs r1, r1, r0
_0815B97C:
	strh r1, [r5, #2]
	ldr r0, _0815B990 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0815B994
	movs r0, #1
	b _0815B996
	.align 2, 0
_0815B990: .4byte 0x030047A4
_0815B994:
	movs r0, #0
_0815B996:
	cmp r0, #0
	beq _0815B9CC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	bne _0815B9A8
	b _0815BEE8
_0815B9A8:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0815B9B4
	adds r2, r0, #0
_0815B9B4:
	cmp r2, #0
	bge _0815B9BA
	b _0815BEE8
_0815B9BA:
	ldr r1, _0815B9C8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0815BA14
	.align 2, 0
_0815B9C8: .4byte 0x03002BE0
_0815B9CC:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0815B9F8
	cmp r1, #0
	blt _0815B9F8
	ldr r0, _0815B9FC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815B9F8
	ldr r0, _0815BA00 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815BA04
_0815B9F8:
	movs r5, #0
	b _0815BA12
	.align 2, 0
_0815B9FC: .4byte 0x030046A8
_0815BA00: .4byte 0x030046AC
_0815BA04:
	ldr r0, _0815BA54 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0815BA12:
	movs r2, #0
_0815BA14:
	ldr r1, _0815BA58 @ =0x00000256
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r5, r0
	beq _0815BA34
	ldr r1, _0815BA5C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0815BA34
	b _0815BE30
_0815BA34:
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
	str r2, [sp, #0x44]
	cmp r1, #0
	beq _0815BA60
	movs r0, #0
	b _0815BF02
	.align 2, 0
_0815BA54: .4byte 0x030046A4
_0815BA58: .4byte 0x00000256
_0815BA5C: .4byte 0x03002BE0
_0815BA60:
	ldr r4, _0815BB00 @ =0x00000222
	adds r2, r7, r4
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r6, [sp, #0x44]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	str r2, [sp, #0x2c]
	cmp r3, #0
	beq _0815BB14
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _0815BB04 @ =0x0000046D
	adds r2, r2, r7
	mov ip, r2
	movs r3, #1
	strb r3, [r2]
	ldr r4, _0815BB08 @ =0x0000046B
	adds r4, r4, r7
	mov sl, r4
	movs r6, #0
	strb r6, [r4]
	ldr r2, _0815BB0C @ =0x00000553
	adds r2, r2, r7
	mov r8, r2
	strb r0, [r2]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x74]
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
	ldr r6, _0815BB10 @ =0x00000469
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
	mov r6, ip
	str r6, [sp, #0x68]
	mov r6, sl
	str r6, [sp, #0x60]
	mov r6, r8
	str r6, [sp, #0x48]
	ldr r6, [sp, #0x74]
	str r6, [sp, #0x4c]
	str r5, [sp, #0x50]
	str r4, [sp, #0x54]
	str r3, [sp, #0x58]
	str r2, [sp, #0x5c]
	str r1, [sp, #0x24]
	str r0, [sp, #0x64]
	b _0815BCE8
	.align 2, 0
_0815BB00: .4byte 0x00000222
_0815BB04: .4byte 0x0000046D
_0815BB08: .4byte 0x0000046B
_0815BB0C: .4byte 0x00000553
_0815BB10: .4byte 0x00000469
_0815BB14:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0815BBD8 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0xc]
	strb r0, [r2]
	ldr r4, _0815BBDC @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x10]
	movs r6, #0
	strb r6, [r4]
	ldr r2, _0815BBE0 @ =0x00000553
	adds r2, r7, r2
	str r2, [sp, #0x14]
	strb r0, [r2]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r4, r7
	mov ip, r4
	str r1, [r4]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r6, r7
	mov sl, r6
	strh r3, [r6]
	movs r1, #5
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x18]
	movs r4, #0
	strb r4, [r2]
	ldr r6, _0815BBE4 @ =0x00000469
	adds r6, r6, r7
	mov r8, r6
	strb r4, [r6]
	ldr r2, _0815BBE8 @ =0x0000046A
	adds r6, r7, r2
	strb r1, [r6]
	ldr r4, _0815BBEC @ =0x00000484
	adds r5, r7, r4
	str r3, [r5]
	ldr r1, _0815BBF0 @ =0x0000046C
	adds r4, r7, r1
	strb r0, [r4]
	adds r2, #0x3e
	adds r3, r7, r2
	ldr r0, [r3]
	str r0, [sp, #0x1c]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	ldr r0, [sp, #0x1c]
	strh r1, [r0]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	ldr r2, [sp, #0x1c]
	strh r0, [r2, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x28]
	ldr r3, [sp, #0xc]
	str r3, [sp, #0x68]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x60]
	ldr r3, [sp, #0x14]
	str r3, [sp, #0x48]
	mov r0, ip
	str r0, [sp, #0x4c]
	mov r3, sl
	str r3, [sp, #0x50]
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x54]
	mov r3, r8
	str r3, [sp, #0x58]
	str r6, [sp, #0x5c]
	str r5, [sp, #0x24]
	str r4, [sp, #0x64]
	cmp r2, #0
	blt _0815BBD4
	cmp r1, #0
	blt _0815BBD4
	ldr r0, _0815BBF4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815BBD4
	ldr r0, _0815BBF8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815BBFC
_0815BBD4:
	movs r4, #0
	b _0815BC0A
	.align 2, 0
_0815BBD8: .4byte 0x0000046D
_0815BBDC: .4byte 0x0000046B
_0815BBE0: .4byte 0x00000553
_0815BBE4: .4byte 0x00000469
_0815BBE8: .4byte 0x0000046A
_0815BBEC: .4byte 0x00000484
_0815BBF0: .4byte 0x0000046C
_0815BBF4: .4byte 0x030046A8
_0815BBF8: .4byte 0x030046AC
_0815BBFC:
	ldr r0, _0815BC1C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0815BC0A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815BC20
	adds r0, #4
	b _0815BC2C
	.align 2, 0
_0815BC1C: .4byte 0x030046A4
_0815BC20:
	ldr r0, _0815BC40 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815BC2C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0815BC44
	cmp r2, #2
	beq _0815BC4A
	b _0815BC50
	.align 2, 0
_0815BC40: .4byte 0x030046A4
_0815BC44:
	ldr r4, [sp, #0x1c]
	ldrb r0, [r4, #4]
	b _0815BC4E
_0815BC4A:
	ldr r6, [sp, #0x1c]
	ldrb r0, [r6]
_0815BC4E:
	subs r1, r1, r0
_0815BC50:
	ldr r0, [sp, #0x1c]
	strh r1, [r0, #2]
	ldr r1, [sp, #0x28]
	ldr r0, [r1]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0815BC7C
	cmp r1, #0
	blt _0815BC7C
	ldr r0, _0815BC80 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815BC7C
	ldr r0, _0815BC84 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815BC88
_0815BC7C:
	movs r4, #0
	b _0815BC96
	.align 2, 0
_0815BC80: .4byte 0x030046A8
_0815BC84: .4byte 0x030046AC
_0815BC88:
	ldr r0, _0815BCAC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0815BC96:
	ldr r2, [sp, #0x28]
	ldr r5, [r2]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815BCB0
	adds r0, #4
	b _0815BCBC
	.align 2, 0
_0815BCAC: .4byte 0x030046A4
_0815BCB0:
	ldr r0, _0815BCD0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815BCBC:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0815BCD4
	cmp r3, #2
	beq _0815BCD8
	b _0815BCDC
	.align 2, 0
_0815BCD0: .4byte 0x030046A4
_0815BCD4:
	ldrb r0, [r5, #4]
	b _0815BCDA
_0815BCD8:
	ldrb r0, [r5]
_0815BCDA:
	subs r2, r2, r0
_0815BCDC:
	ldr r3, [sp, #0x28]
	ldr r0, [r3]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r3]
	strh r1, [r0, #6]
_0815BCE8:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x20]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r6, [sp, #0x44]
	ldrh r0, [r6]
	ands r0, r1
	mov sb, r4
	adds r1, #0x82
	adds r1, r7, r1
	str r1, [sp, #0x70]
	cmp r0, #0
	bne _0815BDF2
	movs r1, #4
	ldr r2, [sp, #0x2c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0815BD12
	movs r0, #1
	b _0815BD14
_0815BD12:
	movs r0, #0
_0815BD14:
	ldr r3, _0815BE04 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x70]
	cmp r0, #0
	bne _0815BDF2
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _0815BE08 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _0815BE0C @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x38]
	ldr r2, _0815BE10 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x3c]
	ldr r4, _0815BE14 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x40]
	ldr r6, _0815BE18 @ =0x00000541
	adds r6, r7, r6
	str r6, [sp, #0x30]
	ldr r0, _0815BE1C @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x6c]
	ldr r1, _0815BE20 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x34]
	ldr r6, _0815BE24 @ =0x0203B400
	ldr r1, _0815BE28 @ =0x030046B8
	ldr r5, _0815BE2C @ =0x000003FF
	movs r4, #3
	mov r2, sb
_0815BD64:
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
	bne _0815BD82
	adds r3, #1
	cmp r3, #3
	ble _0815BD64
	mov r0, sb
_0815BD82:
	movs r3, #0
	mov r2, r8
	strb r0, [r2]
	ldr r4, [sp, #0x4c]
	ldr r0, [r4]
	mov r6, sl
	str r0, [r6]
	ldr r1, [sp, #0x48]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x54]
	ldrb r0, [r4]
	ldr r6, [sp, #0x38]
	strb r0, [r6]
	ldr r1, [sp, #0x58]
	ldrb r0, [r1]
	ldr r2, [sp, #0x3c]
	strb r0, [r2]
	ldr r4, [sp, #0x5c]
	ldrb r0, [r4]
	ldr r6, [sp, #0x40]
	strb r0, [r6]
	add r0, sp, #0x20
	ldrb r1, [r0]
	ldr r0, [sp, #0x30]
	strb r1, [r0]
	ldr r1, [sp, #0x6c]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x68]
	strb r1, [r4]
	ldr r6, [sp, #0x60]
	strb r3, [r6]
	ldr r4, [sp, #0x48]
	strb r0, [r4]
	ldr r6, [sp, #0x4c]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x50]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x54]
	strb r0, [r4]
	ldr r6, [sp, #0x58]
	strb r1, [r6]
	ldr r0, [sp, #0x5c]
	strb r2, [r0]
	ldr r2, [sp, #0x24]
	str r3, [r2]
	ldr r3, [sp, #0x64]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x34]
	strb r0, [r4]
_0815BDF2:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r6, [sp, #0x70]
	strh r0, [r6]
	movs r0, #0
	b _0815BF02
	.align 2, 0
_0815BE04: .4byte 0x00000482
_0815BE08: .4byte 0x0000054F
_0815BE0C: .4byte 0x0000054C
_0815BE10: .4byte 0x0000054D
_0815BE14: .4byte 0x0000054E
_0815BE18: .4byte 0x00000541
_0815BE1C: .4byte 0x000005BC
_0815BE20: .4byte 0x00000542
_0815BE24: .4byte 0x0203B400
_0815BE28: .4byte 0x030046B8
_0815BE2C: .4byte 0x000003FF
_0815BE30:
	mov sb, sp
	ldr r6, _0815BE6C @ =0x030046A4
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
	beq _0815BE70
	adds r0, #4
	b _0815BE7A
	.align 2, 0
_0815BE6C: .4byte 0x030046A4
_0815BE70:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815BE7A:
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
	ldr r1, _0815BEB0 @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _0815BEB4
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	b _0815BEDA
	.align 2, 0
_0815BEB0: .4byte 0x000004A4
_0815BEB4:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _0815BED4
	cmp r0, #2
	beq _0815BED0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0815BED0:
	movs r0, #1
	b _0815BEE4
_0815BED4:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
_0815BEDA:
	ldr r1, _0815BEF8 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0815BEE4:
	cmp r0, #0
	bne _0815BF00
_0815BEE8:
	ldr r4, _0815BEFC @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0815BF02
	.align 2, 0
_0815BEF8: .4byte 0xFFFFFDFF
_0815BEFC: .4byte 0x000005C4
_0815BF00:
	movs r0, #1
_0815BF02:
	cmp r0, #0
	beq _0815BF3E
	ldr r6, [sp, #8]
	movs r0, #0xe0
	lsls r0, r0, #3
	adds r2, r6, r0
	movs r1, #0x41
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r2, #0x13
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0815BF50 @ =0x00000469
	adds r0, r7, r3
	strb r1, [r0]
	ldr r4, _0815BF54 @ =0x0000046A
	adds r0, r7, r4
	strb r2, [r0]
	ldr r6, _0815BF58 @ =0x00000484
	adds r0, r7, r6
	str r1, [r0]
	ldr r0, _0815BF5C @ =0x0000046C
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
_0815BF3E:
	add sp, #0x78
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815BF50: .4byte 0x00000469
_0815BF54: .4byte 0x0000046A
_0815BF58: .4byte 0x00000484
_0815BF5C: .4byte 0x0000046C

	thumb_func_start FUN_0815bf60
FUN_0815bf60: @ 0x0815BF60
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	ldr r7, [sp, #0x18]
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r2, #0
	ldrsh r0, [r5, r2]
	subs r2, r1, r0
	cmp r2, #0
	beq _0815BF8E
	adds r0, r2, #0
	cmp r2, #0
	bge _0815BF80
	rsbs r0, r2, #0
_0815BF80:
	cmp r0, r3
	bls _0815BF88
	movs r1, #0
	b _0815BF98
_0815BF88:
	ldrh r0, [r5]
	adds r0, r0, r2
	strh r0, [r5]
_0815BF8E:
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r4, #4
	ldrsh r0, [r5, r4]
	subs r1, r1, r0
_0815BF98:
	adds r0, r2, #0
	cmp r2, #0
	bge _0815BFA0
	rsbs r0, r2, #0
_0815BFA0:
	cmp r0, r3
	bhi _0815BFC2
	adds r3, r1, #0
	cmp r1, #0
	bge _0815BFAC
	rsbs r3, r1, #0
_0815BFAC:
	ldr r0, [sp, #0x14]
	cmp r3, r0
	bhi _0815BFC2
	ldrh r0, [r5]
	adds r0, r0, r2
	strh r0, [r5]
	ldrh r0, [r5, #4]
	adds r0, r0, r1
	strh r0, [r5, #4]
	movs r0, #1
	b _0815C056
_0815BFC2:
	cmp r2, #0
	bne _0815BFCA
	cmp r1, #0
	beq _0815C054
_0815BFCA:
	adds r0, r2, #0
	bl FUN_0823785c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	lsls r4, r0, #6
	strb r4, [r6]
	ldr r1, _0815BFFC @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0815C000
	asrs r0, r0, #0x10
	b _0815C006
	.align 2, 0
_0815BFFC: .4byte 0x085B0A08
_0815C000:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_0815C006:
	adds r3, r0, #0
	ldr r0, _0815C01C @ =0x085B0A08
	lsls r1, r4, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0815C020
	asrs r0, r0, #0x10
	b _0815C026
	.align 2, 0
_0815C01C: .4byte 0x085B0A08
_0815C020:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_0815C026:
	adds r2, r3, #0
	cmp r3, #0
	bge _0815C02E
	rsbs r2, r3, #0
_0815C02E:
	movs r1, #0
	cmp r2, #2
	ble _0815C036
	adds r1, r3, #0
_0815C036:
	adds r3, r1, #0
	adds r2, r0, #0
	cmp r0, #0
	bge _0815C040
	rsbs r2, r0, #0
_0815C040:
	movs r1, #0
	cmp r2, #2
	ble _0815C048
	adds r1, r0, #0
_0815C048:
	ldrh r0, [r5]
	adds r0, r0, r3
	strh r0, [r5]
	ldrh r0, [r5, #4]
	adds r0, r0, r1
	strh r0, [r5, #4]
_0815C054:
	movs r0, #0
_0815C056:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0815c05c
FUN_0815c05c: @ 0x0815C05C
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r6, [r0]
	ldr r2, _0815C11C @ =0x00000482
	adds r1, r3, r2
	movs r5, #0
	movs r0, #1
	strh r0, [r1]
	ldr r1, _0815C120 @ =0x00000222
	adds r0, r3, r1
	strh r5, [r0]
	ldr r2, _0815C124 @ =0x0000024E
	adds r0, r3, r2
	strh r5, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r4, r3, r0
	ldr r0, _0815C128 @ =0xFFFFFC7F
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r3, r1
	ldr r1, _0815C12C @ =0xF3FFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _0815C0D0
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r3, r0
	ldr r1, _0815C130 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _0815C134 @ =0xFFFFFDFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r3, r2
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0815C138 @ =0x0000021E
	adds r0, r3, r1
	strh r5, [r0]
	subs r2, #0x1a
	adds r0, r3, r2
	strh r5, [r0]
_0815C0D0:
	ldr r0, _0815C13C @ =0xFFFFFBFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	ldr r0, _0815C140 @ =0x00000542
	adds r1, r3, r0
	movs r0, #0xff
	strb r0, [r1]
	movs r1, #0x20
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r4, r6, r2
	ldr r0, [r4]
	orrs r0, r1
	ldr r1, _0815C144 @ =0xFFF7FFF6
	ands r0, r1
	str r0, [r4]
	ldr r1, _0815C148 @ =0x000006DE
	adds r0, r6, r1
	ldrh r1, [r0]
	subs r2, #0x24
	adds r0, r6, r2
	strh r1, [r0]
	ldr r1, _0815C14C @ =0x000001DD
	adds r0, r3, r1
	ldrb r0, [r0]
	strb r0, [r3, #5]
	adds r0, r3, #0
	bl FUN_0815b584
	movs r1, #0x41
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0815C11C: .4byte 0x00000482
_0815C120: .4byte 0x00000222
_0815C124: .4byte 0x0000024E
_0815C128: .4byte 0xFFFFFC7F
_0815C12C: .4byte 0xF3FFFFFF
_0815C130: .4byte 0xFEFFFFFF
_0815C134: .4byte 0xFFFFFDFF
_0815C138: .4byte 0x0000021E
_0815C13C: .4byte 0xFFFFFBFF
_0815C140: .4byte 0x00000542
_0815C144: .4byte 0xFFF7FFF6
_0815C148: .4byte 0x000006DE
_0815C14C: .4byte 0x000001DD

	thumb_func_start FUN_0815c150
FUN_0815c150: @ 0x0815C150
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrb r0, [r5, #5]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r4, r0, #3
	movs r0, #7
	ands r4, r0
	mov r2, sp
	adds r2, #5
	adds r0, r5, #0
	add r1, sp, #4
	bl FUN_080e5d44
	cmp r4, #7
	bls _0815C178
	b _0815C4B0
_0815C178:
	lsls r0, r4, #2
	ldr r1, _0815C184 @ =_0815C188
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0815C184: .4byte _0815C188
_0815C188: @ jump table
	.4byte _0815C1A8 @ case 0
	.4byte _0815C1A8 @ case 1
	.4byte _0815C22C @ case 2
	.4byte _0815C2E8 @ case 3
	.4byte _0815C2E8 @ case 4
	.4byte _0815C36C @ case 5
	.4byte _0815C3AA @ case 6
	.4byte _0815C42A @ case 7
_0815C1A8:
	ldr r1, _0815C1CC @ =0x000004D4
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r1, _0815C1D0 @ =0x0000025D
	adds r0, r5, r1
	ldrb r6, [r0]
	cmp r6, #0
	bne _0815C1D8
	ldr r1, _0815C1D4 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	adds r3, r4, #0
	str r6, [sp]
	b _0815C44C
	.align 2, 0
_0815C1CC: .4byte 0x000004D4
_0815C1D0: .4byte 0x0000025D
_0815C1D4: .4byte 0x000004B7
_0815C1D8:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	adds r2, r2, r4
	ldr r1, _0815C224 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0815C228 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, r2
	bne _0815C202
	ldrb r0, [r6]
	cmp r0, #0
	bne _0815C202
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0815C202
	b _0815C4B0
_0815C202:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r7, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	b _0815C4AA
	.align 2, 0
_0815C224: .4byte 0x000004B7
_0815C228: .4byte 0x0000046E
_0815C22C:
	add r0, sp, #4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0815C2B8
	ldr r1, _0815C258 @ =0x000004D4
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r1, _0815C25C @ =0x0000025D
	adds r0, r5, r1
	ldrb r6, [r0]
	cmp r6, #0
	bne _0815C264
	ldr r1, _0815C260 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	adds r3, r4, #0
	str r6, [sp]
	b _0815C44C
	.align 2, 0
_0815C258: .4byte 0x000004D4
_0815C25C: .4byte 0x0000025D
_0815C260: .4byte 0x000004B7
_0815C264:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	adds r2, r2, r4
	ldr r1, _0815C2B0 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0815C2B4 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, r2
	bne _0815C28E
	ldrb r0, [r6]
	cmp r0, #0
	bne _0815C28E
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0815C28E
	b _0815C4B0
_0815C28E:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r7, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	b _0815C4AA
	.align 2, 0
_0815C2B0: .4byte 0x000004B7
_0815C2B4: .4byte 0x0000046E
_0815C2B8:
	ldr r1, _0815C2DC @ =0x000004D4
	adds r0, r5, r1
	ldrb r2, [r0]
	adds r3, r4, #1
	ldr r1, _0815C2E0 @ =0x0000025D
	adds r0, r5, r1
	ldrb r4, [r0]
	cmp r4, #0
	bne _0815C318
	ldr r1, _0815C2E4 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r4, [sp]
	b _0815C44C
	.align 2, 0
_0815C2DC: .4byte 0x000004D4
_0815C2E0: .4byte 0x0000025D
_0815C2E4: .4byte 0x000004B7
_0815C2E8:
	ldr r1, _0815C30C @ =0x000004D4
	adds r0, r5, r1
	ldrb r2, [r0]
	adds r3, r4, #1
	ldr r1, _0815C310 @ =0x0000025D
	adds r0, r5, r1
	ldrb r4, [r0]
	cmp r4, #0
	bne _0815C318
	ldr r1, _0815C314 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r4, [sp]
	b _0815C44C
	.align 2, 0
_0815C30C: .4byte 0x000004D4
_0815C310: .4byte 0x0000025D
_0815C314: .4byte 0x000004B7
_0815C318:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	adds r2, r2, r3
	ldr r1, _0815C364 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0815C368 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, r2
	bne _0815C342
	ldrb r0, [r6]
	cmp r0, #0
	bne _0815C342
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0815C342
	b _0815C4B0
_0815C342:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	b _0815C4AC
	.align 2, 0
_0815C364: .4byte 0x000004B7
_0815C368: .4byte 0x0000046E
_0815C36C:
	ldr r1, _0815C394 @ =0x000004D4
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r1, _0815C398 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0815C3A0
	ldr r1, _0815C39C @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r3, #1
	str r3, [sp]
	movs r3, #4
	b _0815C44C
	.align 2, 0
_0815C394: .4byte 0x000004D4
_0815C398: .4byte 0x0000025D
_0815C39C: .4byte 0x000004B7
_0815C3A0:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	adds r2, #4
	b _0815C470
_0815C3AA:
	add r0, sp, #4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0815C3EE
	ldr r1, _0815C3D8 @ =0x000004D4
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r1, _0815C3DC @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0815C3E4
	ldr r1, _0815C3E0 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r3, #1
	str r3, [sp]
	movs r3, #2
	b _0815C44C
	.align 2, 0
_0815C3D8: .4byte 0x000004D4
_0815C3DC: .4byte 0x0000025D
_0815C3E0: .4byte 0x000004B7
_0815C3E4:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	adds r2, #2
	b _0815C470
_0815C3EE:
	ldr r1, _0815C414 @ =0x000004D4
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r1, _0815C418 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0815C420
	ldr r1, _0815C41C @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r3, #1
	str r3, [sp]
	movs r3, #3
	b _0815C44C
	.align 2, 0
_0815C414: .4byte 0x000004D4
_0815C418: .4byte 0x0000025D
_0815C41C: .4byte 0x000004B7
_0815C420:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	adds r2, #3
	b _0815C470
_0815C42A:
	ldr r1, _0815C458 @ =0x000004D4
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r1, _0815C45C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0815C468
	ldr r1, _0815C460 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r3, #1
	str r3, [sp]
_0815C44C:
	bl FUN_08236fac
	ldr r0, _0815C464 @ =0x0000046E
	adds r6, r5, r0
	b _0815C4AC
	.align 2, 0
_0815C458: .4byte 0x000004D4
_0815C45C: .4byte 0x0000025D
_0815C460: .4byte 0x000004B7
_0815C464: .4byte 0x0000046E
_0815C468:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	adds r2, #1
_0815C470:
	ldr r1, _0815C4B8 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0815C4BC @ =0x0000046E
	adds r6, r5, r0
	cmp r1, r2
	bne _0815C490
	ldrb r0, [r6]
	cmp r0, #0
	bne _0815C490
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0815C4B0
_0815C490:
	strb r2, [r3]
	movs r4, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r4, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r7, #8]
	orrs r0, r4
_0815C4AA:
	str r0, [r7, #8]
_0815C4AC:
	movs r0, #0
	strb r0, [r6]
_0815C4B0:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815C4B8: .4byte 0x000004B7
_0815C4BC: .4byte 0x0000046E

	thumb_func_start FUN_0815c4c0
FUN_0815c4c0: @ 0x0815C4C0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #2
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815C4E4
	movs r0, #1
	b _0815C4E6
_0815C4E4:
	movs r0, #0
_0815C4E6:
	adds r5, r0, #0
	cmp r5, #0
	beq _0815C594
	adds r0, r7, #0
	movs r1, #0x11
	bl FUN_080ef86c
	movs r6, #3
	movs r4, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	movs r1, #0
	strb r6, [r0]
	ldr r5, _0815C578 @ =0x00000469
	adds r0, r7, r5
	strb r4, [r0]
	ldr r2, _0815C57C @ =0x0000046A
	adds r0, r7, r2
	strb r1, [r0]
	adds r3, #0x1c
	adds r0, r7, r3
	str r1, [r0]
	adds r5, #3
	adds r0, r7, r5
	strb r4, [r0]
	ldr r3, _0815C580 @ =FUN_080e6834
	movs r2, #0xe
	adds r5, #1
	adds r0, r7, r5
	strb r4, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r1, [r0]
	adds r5, #0xe8
	adds r0, r7, r5
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r5, #0
	mov r8, r5
	strh r1, [r0]
	adds r0, r7, #0
	movs r1, #1
	movs r2, #0
	bl FUN_0815a2a8
	ldr r3, _0815C584 @ =FUN_081557a0
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r5, _0815C588 @ =0x00000554
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r6, [r0]
	ldr r2, _0815C58C @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _0815C590 @ =0x00000552
	adds r0, r7, r3
	mov r4, r8
	strb r4, [r0]
	b _0815C616
	.align 2, 0
_0815C578: .4byte 0x00000469
_0815C57C: .4byte 0x0000046A
_0815C580: .4byte FUN_080e6834
_0815C584: .4byte FUN_081557a0
_0815C588: .4byte 0x00000554
_0815C58C: .4byte 0x00000551
_0815C590: .4byte 0x00000552
_0815C594:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #3
	movs r2, #1
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0815C620 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	ldr r3, _0815C624 @ =0x0000046A
	adds r0, r7, r3
	strb r5, [r0]
	ldr r4, _0815C628 @ =0x00000484
	adds r0, r7, r4
	str r5, [r0]
	adds r6, #4
	adds r0, r7, r6
	strb r2, [r0]
	ldr r3, _0815C62C @ =FUN_080e6794
	movs r1, #0xe
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r6, #1
	adds r0, r7, r6
	strb r5, [r0]
	ldr r2, _0815C630 @ =0x00000553
	adds r0, r7, r2
	strb r1, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r7, r4
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r7, r6
	movs r4, #0
	strh r5, [r0]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r5, #7
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
	strb r4, [r0]
	ldr r2, _0815C634 @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _0815C638 @ =0x00000552
	adds r0, r7, r3
	strb r5, [r0]
_0815C616:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815C620: .4byte 0x00000469
_0815C624: .4byte 0x0000046A
_0815C628: .4byte 0x00000484
_0815C62C: .4byte FUN_080e6794
_0815C630: .4byte 0x00000553
_0815C634: .4byte 0x00000551
_0815C638: .4byte 0x00000552

	thumb_func_start FUN_0815c63c
FUN_0815c63c: @ 0x0815C63C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	movs r2, #0x97
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r0, [r0]
	bl FUN_080f8e3c
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r6, r5
	ldr r1, _0815C6E0 @ =0xFFFFEFFF
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _0815C6FC
	movs r1, #2
	movs r7, #0xe0
	lsls r7, r7, #3
	adds r0, r4, r7
	ldr r0, [r0]
	ands r0, r1
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r2, _0815C6E4 @ =0x0000046D
	adds r0, r6, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _0815C6E8 @ =0x0000046B
	adds r0, r6, r5
	strb r2, [r0]
	ldr r7, _0815C6EC @ =0x00000553
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r0, r6, r5
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r5, _0815C6F0 @ =0x00000469
	adds r0, r6, r5
	strb r1, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	ldr r1, _0815C6F4 @ =0x00000484
	adds r0, r6, r1
	str r2, [r0]
	ldr r2, _0815C6F8 @ =0x0000046C
	adds r0, r6, r2
	strb r4, [r0]
	adds r5, #0x19
	adds r1, r6, r5
	movs r0, #2
	strh r0, [r1]
	b _0815C812
	.align 2, 0
_0815C6E0: .4byte 0xFFFFEFFF
_0815C6E4: .4byte 0x0000046D
_0815C6E8: .4byte 0x0000046B
_0815C6EC: .4byte 0x00000553
_0815C6F0: .4byte 0x00000469
_0815C6F4: .4byte 0x00000484
_0815C6F8: .4byte 0x0000046C
_0815C6FC:
	movs r1, #3
	movs r2, #1
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _0815C738 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r5, _0815C73C @ =0x0000046A
	adds r1, r6, r5
	movs r0, #0
	strb r0, [r1]
	adds r7, #0x1c
	adds r0, r6, r7
	str r3, [r0]
	ldr r1, _0815C740 @ =0x0000046C
	adds r0, r6, r1
	strb r2, [r0]
	movs r1, #2
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815C744
	movs r0, #1
	b _0815C746
	.align 2, 0
_0815C738: .4byte 0x00000469
_0815C73C: .4byte 0x0000046A
_0815C740: .4byte 0x0000046C
_0815C744:
	movs r0, #0
_0815C746:
	adds r5, r0, #0
	cmp r5, #0
	beq _0815C7A8
	adds r0, r6, #0
	movs r1, #0x11
	bl FUN_080ef86c
	ldr r4, _0815C790 @ =FUN_080e6834
	movs r3, #0xe
	ldr r5, _0815C794 @ =0x0000046D
	adds r1, r6, r5
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r7, _0815C798 @ =0x0000046B
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _0815C79C @ =0x00000553
	adds r0, r6, r1
	strb r3, [r0]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r0, r6, r5
	str r4, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r6, r7
	movs r4, #0
	strh r2, [r0]
	ldr r3, _0815C7A0 @ =FUN_08155570
	movs r5, #0x11
	movs r1, #0x3c
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r6, r0
	ldr r7, _0815C7A4 @ =0x00000554
	b _0815C7EC
	.align 2, 0
_0815C790: .4byte FUN_080e6834
_0815C794: .4byte 0x0000046D
_0815C798: .4byte 0x0000046B
_0815C79C: .4byte 0x00000553
_0815C7A0: .4byte FUN_08155570
_0815C7A4: .4byte 0x00000554
_0815C7A8:
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r3, _0815C84C @ =FUN_080e6794
	movs r2, #0xe
	ldr r0, _0815C850 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0815C854 @ =0x0000046B
	adds r0, r6, r1
	strb r5, [r0]
	ldr r7, _0815C858 @ =0x00000553
	adds r0, r6, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r4, #0
	strh r5, [r0]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r6, r5
	ldr r3, [r0]
	movs r5, #7
	movs r1, #0x3c
	adds r7, #5
	adds r2, r6, r7
	subs r7, #4
_0815C7EC:
	adds r0, r6, r7
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, _0815C85C @ =0x00000551
	adds r0, r6, r2
	strb r4, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r5, [r0]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
_0815C812:
	mov r5, sp
	adds r0, r6, #0
	adds r0, #0x9c
	ldr r2, [r0, #8]
	ldrh r1, [r2]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r5, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0815C846
	cmp r1, #0
	blt _0815C846
	ldr r0, _0815C860 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815C846
	ldr r0, _0815C864 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815C868
_0815C846:
	movs r4, #0
	b _0815C876
	.align 2, 0
_0815C84C: .4byte FUN_080e6794
_0815C850: .4byte 0x0000046D
_0815C854: .4byte 0x0000046B
_0815C858: .4byte 0x00000553
_0815C85C: .4byte 0x00000551
_0815C860: .4byte 0x030046A8
_0815C864: .4byte 0x030046AC
_0815C868:
	ldr r0, _0815C888 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0815C876:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815C88C
	adds r0, #4
	b _0815C898
	.align 2, 0
_0815C888: .4byte 0x030046A4
_0815C88C:
	ldr r0, _0815C8AC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815C898:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0815C8B0
	cmp r2, #2
	beq _0815C8B4
	b _0815C8B8
	.align 2, 0
_0815C8AC: .4byte 0x030046A4
_0815C8B0:
	ldrb r0, [r5, #4]
	b _0815C8B6
_0815C8B4:
	ldrb r0, [r5]
_0815C8B6:
	subs r1, r1, r0
_0815C8B8:
	strh r1, [r5, #2]
	ldrh r1, [r6, #0xa]
	mov r0, sp
	strh r1, [r0, #2]
	ldr r2, _0815C8E0 @ =0x000004A4
	adds r0, r6, r2
	ldr r4, [r0]
	adds r5, r6, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _0815C8E4
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r6, r5
	b _0815C90A
	.align 2, 0
_0815C8E0: .4byte 0x000004A4
_0815C8E4:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _0815C904
	cmp r0, #2
	beq _0815C900
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0815C900:
	movs r0, #1
	b _0815C914
_0815C904:
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r0, r6, r7
_0815C90A:
	ldr r1, _0815C92C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0815C914:
	cmp r0, #0
	bne _0815C924
	ldr r1, _0815C930 @ =0x000005C4
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
_0815C924:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815C92C: .4byte 0xFFFFFDFF
_0815C930: .4byte 0x000005C4

	thumb_func_start FUN_0815c934
FUN_0815c934: @ 0x0815C934
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r2, r0, #0
	adds r0, r1, #0
	ldr r1, _0815CA08 @ =0xFFFF0000
	mov sl, r1
	ldr r5, [sp, #0xc]
	ands r5, r1
	ldr r3, _0815CA0C @ =0x0000FFF9
	mov ip, r3
	orrs r5, r3
	str r5, [sp, #0xc]
	ldr r1, _0815CA10 @ =0x0203B400
	mov sb, r1
	ldr r7, _0815CA14 @ =0x030046B8
	ldr r4, [r7]
	adds r4, #1
	ldr r3, _0815CA18 @ =0x000003FF
	mov r8, r3
	ands r4, r3
	lsls r1, r4, #1
	add r1, sb
	ldrh r3, [r1]
	movs r1, #0xf
	ands r3, r1
	adds r3, #0x14
	lsls r3, r3, #0x10
	ldr r6, _0815CA1C @ =0x0000FFFF
	adds r1, r6, #0
	ands r1, r5
	orrs r1, r3
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x10]
	mov r5, sl
	ands r1, r5
	mov r3, ip
	orrs r1, r3
	str r1, [sp, #0x10]
	adds r4, #1
	mov r5, r8
	ands r4, r5
	lsls r1, r4, #1
	add r1, sb
	ldrh r1, [r1]
	movs r3, #3
	mov ip, r3
	mov r5, ip
	ands r1, r5
	adds r1, #0xf
	ldr r5, [sp, #0x14]
	mov r3, sl
	ands r5, r3
	orrs r5, r1
	str r5, [sp, #0x14]
	adds r4, #1
	mov r1, r8
	ands r4, r1
	lsls r1, r4, #1
	add r1, sb
	ldrh r1, [r1]
	movs r3, #7
	ands r1, r3
	adds r1, #0xf
	lsls r1, r1, #0x10
	ands r6, r5
	orrs r6, r1
	str r6, [sp, #0x14]
	adds r4, #1
	mov r3, r8
	ands r4, r3
	str r4, [r7]
	lsls r4, r4, #1
	add r4, sb
	ldrh r3, [r4]
	mov r5, ip
	ands r3, r5
	adds r3, #0xf
	add r4, sp, #0x14
	ldr r1, [r4, #4]
	mov r5, sl
	ands r1, r5
	orrs r1, r3
	str r1, [r4, #4]
	adds r2, #8
	str r4, [sp]
	movs r1, #0x2d
	str r1, [sp, #4]
	movs r1, #0x1f
	str r1, [sp, #8]
	movs r1, #3
	add r3, sp, #0xc
	bl FUN_08014730
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815CA08: .4byte 0xFFFF0000
_0815CA0C: .4byte 0x0000FFF9
_0815CA10: .4byte 0x0203B400
_0815CA14: .4byte 0x030046B8
_0815CA18: .4byte 0x000003FF
_0815CA1C: .4byte 0x0000FFFF

	thumb_func_start FUN_0815ca20
FUN_0815ca20: @ 0x0815CA20
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r2, [r0]
	ldr r0, [r3, #0x44]
	adds r4, r0, #0
	adds r4, #0x48
	ldrh r0, [r4, #0xe]
	cmp r0, #0
	bne _0815CA8C
	movs r1, #2
	movs r5, #0xe0
	lsls r5, r5, #3
	adds r0, r2, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815CA4C
	movs r0, #1
	b _0815CA4E
_0815CA4C:
	movs r0, #0
_0815CA4E:
	cmp r0, #0
	beq _0815CA64
	ldrh r0, [r4, #8]
	movs r1, #4
	bl Mod
	ldr r1, _0815CA60 @ =0x085AD9A8
	b _0815CA7E
	.align 2, 0
_0815CA60: .4byte 0x085AD9A8
_0815CA64:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrh r0, [r4, #8]
	movs r1, #0xa
	bl Mod
	ldr r1, _0815CA88 @ =0x085AD9B0
_0815CA7E:
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	b _0815CA8E
	.align 2, 0
_0815CA88: .4byte 0x085AD9B0
_0815CA8C:
	movs r0, #0
_0815CA8E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0815ca94
FUN_0815ca94: @ 0x0815CA94
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r3, [r0]
	ldr r1, _0815CB68 @ =0x00000482
	adds r0, r6, r1
	movs r5, #0
	movs r1, #1
	mov ip, r1
	mov r1, ip
	strh r1, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r4, r6, r0
	ldr r1, _0815CB6C @ =0xFBFFFFFF
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r7, r6, r1
	ldr r0, _0815CB70 @ =0xFEFFFFFF
	mov r8, r0
	ldr r0, [r7]
	mov r1, r8
	ands r0, r1
	str r0, [r7]
	movs r0, #0xe0
	lsls r0, r0, #3
	adds r2, r3, r0
	ldr r1, _0815CB74 @ =0xFFFFFF00
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _0815CB78 @ =0x000006DC
	adds r0, r3, r1
	strh r5, [r0]
	adds r1, #0xc
	adds r0, r3, r1
	strh r5, [r0]
	movs r0, #0xdc
	lsls r0, r0, #3
	adds r3, r3, r0
	strh r5, [r3]
	ldr r1, _0815CB68 @ =0x00000482
	adds r0, r6, r1
	mov r1, ip
	strh r1, [r0]
	ldr r1, _0815CB7C @ =0x00000222
	adds r0, r6, r1
	strh r5, [r0]
	adds r1, #0x2c
	adds r0, r6, r1
	strh r5, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, _0815CB80 @ =0xFFFFFC7F
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _0815CB84 @ =0xF3FFFFFF
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _0815CB4E
	ldr r0, [r7]
	mov r1, r8
	ands r0, r1
	str r0, [r7]
	ldr r0, _0815CB88 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x87
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0815CB8C @ =0x0000021E
	adds r0, r6, r1
	strh r5, [r0]
	subs r1, #0x1c
	adds r0, r6, r1
	strh r5, [r0]
_0815CB4E:
	ldr r0, _0815CB90 @ =0xFFFFFBFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r0, _0815CB94 @ =0x00000542
	adds r1, r6, r0
	movs r0, #0xff
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815CB68: .4byte 0x00000482
_0815CB6C: .4byte 0xFBFFFFFF
_0815CB70: .4byte 0xFEFFFFFF
_0815CB74: .4byte 0xFFFFFF00
_0815CB78: .4byte 0x000006DC
_0815CB7C: .4byte 0x00000222
_0815CB80: .4byte 0xFFFFFC7F
_0815CB84: .4byte 0xF3FFFFFF
_0815CB88: .4byte 0xFFFFFDFF
_0815CB8C: .4byte 0x0000021E
_0815CB90: .4byte 0xFFFFFBFF
_0815CB94: .4byte 0x00000542

	thumb_func_start FUN_0815cb98
FUN_0815cb98: @ 0x0815CB98
	push {lr}
	adds r2, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, #2
	movs r3, #0xe0
	lsls r3, r3, #3
	adds r0, r0, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815CBB8
	movs r0, #1
	b _0815CBBA
_0815CBB8:
	movs r0, #0
_0815CBBA:
	cmp r0, #0
	beq _0815CBC8
	adds r0, r2, #0
	movs r1, #0x11
	bl FUN_080ef86c
	b _0815CBD0
_0815CBC8:
	adds r0, r2, #0
	movs r1, #0
	bl FUN_080ef86c
_0815CBD0:
	pop {r0}
	bx r0

	thumb_func_start FUN_0815cbd4
FUN_0815cbd4: @ 0x0815CBD4
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	movs r1, #8
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815CBF6
	movs r0, #1
	b _0815CBF8
_0815CBF6:
	movs r0, #0
_0815CBF8:
	cmp r0, #0
	beq _0815CBFE
	b _0815CD02
_0815CBFE:
	movs r3, #0xea
	lsls r3, r3, #1
	adds r4, r5, r3
	ldr r0, [r4]
	cmp r0, #0
	ble _0815CCEC
	adds r0, r5, #0
	bl FUN_080f00ec
	ldr r0, _0815CC80 @ =0x00000222
	adds r2, r5, r0
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0x14
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xe0
	lsls r0, r0, #3
	adds r2, r6, r0
	ldr r1, _0815CC84 @ =0xFFF3FFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldrh r0, [r4]
	bl FUN_080f8d60
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r5, r2
	str r0, [r1]
	ldrh r1, [r0, #8]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0815CC7C
	cmp r1, #0
	blt _0815CC7C
	ldr r0, _0815CC88 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815CC7C
	ldr r0, _0815CC8C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815CC90
_0815CC7C:
	movs r1, #0
	b _0815CC9E
	.align 2, 0
_0815CC80: .4byte 0x00000222
_0815CC84: .4byte 0xFFF3FFFF
_0815CC88: .4byte 0x030046A8
_0815CC8C: .4byte 0x030046AC
_0815CC90:
	ldr r0, _0815CCE4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0815CC9E:
	ldr r3, _0815CCE8 @ =0x0000025E
	adds r0, r5, r3
	strh r1, [r0]
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
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
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	strb r0, [r5, #5]
	movs r0, #1
	b _0815CD04
	.align 2, 0
_0815CCE4: .4byte 0x030046A4
_0815CCE8: .4byte 0x0000025E
_0815CCEC:
	movs r0, #8
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r3, [r1]
	ands r0, r3
	cmp r0, #0
	beq _0815CD02
	ldr r0, _0815CD0C @ =0xF7FFFFFF
	ands r3, r0
	str r3, [r1]
_0815CD02:
	movs r0, #0
_0815CD04:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0815CD0C: .4byte 0xF7FFFFFF

	thumb_func_start FUN_0815cd10
FUN_0815cd10: @ 0x0815CD10
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r3, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815CD9E
	ldr r5, _0815CD84 @ =0x000001DF
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, #2
	beq _0815CD44
	movs r0, #4
	ldr r7, _0815CD88 @ =0x00000222
	adds r2, r4, r7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0815CD44:
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r5, #0x93
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrh r1, [r0]
	ldr r7, _0815CD8C @ =0x0000024E
	adds r0, r4, r7
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0815CE1C
	movs r2, #8
	movs r0, #0xe0
	lsls r0, r0, #3
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _0815CD90
	movs r0, #1
	b _0815CD92
	.align 2, 0
_0815CD84: .4byte 0x000001DF
_0815CD88: .4byte 0x00000222
_0815CD8C: .4byte 0x0000024E
_0815CD90:
	movs r0, #0
_0815CD92:
	cmp r0, #0
	bne _0815CE1C
	adds r0, r4, #0
	bl FUN_0815a69c
	b _0815CE04
_0815CD9E:
	movs r2, #8
	movs r5, #0xe0
	lsls r5, r5, #3
	adds r1, r3, r5
	ldr r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _0815CDB4
	movs r0, #1
	b _0815CDB6
_0815CDB4:
	movs r0, #0
_0815CDB6:
	adds r5, r0, #0
	cmp r5, #0
	bne _0815CE1C
	movs r1, #1
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r4, r7
	strb r5, [r0]
	ldr r2, _0815CE24 @ =0x00000469
	adds r0, r4, r2
	strb r1, [r0]
	adds r7, #2
	adds r0, r4, r7
	strb r5, [r0]
	adds r2, #0x1b
	adds r0, r4, r2
	str r5, [r0]
	adds r7, #2
	adds r0, r4, r7
	strb r1, [r0]
	ldr r3, _0815CE28 @ =FUN_080e48d0
	movs r2, #0x10
	adds r7, #1
	adds r0, r4, r7
	strb r1, [r0]
	ldr r1, _0815CE2C @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
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
_0815CE04:
	ldr r1, _0815CE30 @ =0xFFF7FFFF
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r4, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0815CE1C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815CE24: .4byte 0x00000469
_0815CE28: .4byte FUN_080e48d0
_0815CE2C: .4byte 0x0000046B
_0815CE30: .4byte 0xFFF7FFFF

	thumb_func_start FUN_0815ce34
FUN_0815ce34: @ 0x0815CE34
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r3, [r0]
	subs r1, #0xcc
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815CE58
	b _0815D1F8
_0815CE58:
	movs r2, #8
	movs r5, #0xe0
	lsls r5, r5, #3
	adds r1, r3, r5
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _0815CE6E
	movs r0, #1
	b _0815CE70
_0815CE6E:
	movs r0, #0
_0815CE70:
	adds r7, r0, #0
	cmp r7, #0
	beq _0815CE78
	b _0815D1F8
_0815CE78:
	movs r0, #0x80
	mov sb, r0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	mov r3, sb
	ands r0, r3
	mov r8, r1
	cmp r0, #0
	beq _0815CF78
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, _0815CF58 @ =0x00000482
	adds r1, r6, r5
	movs r4, #0
	movs r0, #2
	strh r0, [r1]
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r3, [r0]
	movs r2, #0xc
	mov ip, r2
	movs r1, #0x1a
	adds r5, #0xd6
	adds r2, r6, r5
	subs r5, #4
	adds r0, r6, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, _0815CF5C @ =0x00000551
	adds r0, r6, r2
	strb r4, [r0]
	ldr r3, _0815CF60 @ =0x00000552
	adds r0, r6, r3
	mov r5, ip
	strb r5, [r0]
	ldr r3, _0815CF64 @ =FUN_080e6794
	movs r1, #0xe
	subs r2, #0xe4
	adds r0, r6, r2
	movs r2, #1
	strb r2, [r0]
	ldr r5, _0815CF68 @ =0x0000046B
	adds r0, r6, r5
	strb r4, [r0]
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
	strh r7, [r0]
	movs r1, #3
	subs r5, #0xeb
	adds r0, r6, r5
	strb r1, [r0]
	ldr r1, _0815CF6C @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r3, _0815CF70 @ =0x0000046A
	adds r0, r6, r3
	strb r4, [r0]
	adds r5, #0x1c
	adds r0, r6, r5
	str r7, [r0]
	adds r1, #3
	adds r0, r6, r1
	strb r2, [r0]
	movs r0, #4
	ldr r3, _0815CF74 @ =0x00000222
	adds r2, r6, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	mov r5, r8
	ldrh r0, [r5]
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	bne _0815CF32
	b _0815D0DA
_0815CF32:
	adds r3, #0x2c
	adds r2, r6, r3
	movs r5, #0x96
	lsls r5, r5, #1
	adds r0, r5, #0
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	subs r3, #2
	adds r1, r6, r3
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bhi _0815CF52
	b _0815D0DA
_0815CF52:
	strh r1, [r2]
	b _0815D0DA
	.align 2, 0
_0815CF58: .4byte 0x00000482
_0815CF5C: .4byte 0x00000551
_0815CF60: .4byte 0x00000552
_0815CF64: .4byte FUN_080e6794
_0815CF68: .4byte 0x0000046B
_0815CF6C: .4byte 0x00000469
_0815CF70: .4byte 0x0000046A
_0815CF74: .4byte 0x00000222
_0815CF78:
	movs r1, #0x20
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0815CF86
	movs r0, #1
	b _0815CF88
_0815CF86:
	movs r0, #0
_0815CF88:
	cmp r0, #0
	bne _0815CF8E
	b _0815D0B4
_0815CF8E:
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r6, r5
	ldr r5, [r0]
	adds r2, r6, #0
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
	blt _0815CFC6
	cmp r1, #0
	blt _0815CFC6
	ldr r0, _0815CFCC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815CFC6
	ldr r0, _0815CFD0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815CFD4
_0815CFC6:
	movs r4, #0
	b _0815CFE2
	.align 2, 0
_0815CFCC: .4byte 0x030046A8
_0815CFD0: .4byte 0x030046AC
_0815CFD4:
	ldr r0, _0815CFF4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0815CFE2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815CFF8
	adds r0, #4
	b _0815D004
	.align 2, 0
_0815CFF4: .4byte 0x030046A4
_0815CFF8:
	ldr r0, _0815D018 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815D004:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0815D01C
	cmp r3, #2
	beq _0815D020
	b _0815D024
	.align 2, 0
_0815D018: .4byte 0x030046A4
_0815D01C:
	ldrb r0, [r5, #4]
	b _0815D022
_0815D020:
	ldrb r0, [r5]
_0815D022:
	subs r2, r2, r0
_0815D024:
	movs r1, #0
	strh r2, [r5, #2]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r0, [r0]
	strh r1, [r0, #6]
	ldr r3, _0815D064 @ =0x000004A4
	adds r0, r6, r3
	ldr r5, [r0]
	adds r7, r6, #0
	adds r7, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0815D06C
	ldr r0, _0815D068 @ =0xFFFFFDFF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0815D096
	.align 2, 0
_0815D064: .4byte 0x000004A4
_0815D068: .4byte 0xFFFFFDFF
_0815D06C:
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0815D08C
	cmp r0, #2
	beq _0815D088
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0815D088:
	movs r0, #1
	b _0815D098
_0815D08C:
	ldr r0, _0815D0AC @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0815D096:
	movs r0, #0
_0815D098:
	cmp r0, #0
	beq _0815D09E
	b _0815D1F8
_0815D09E:
	ldr r5, _0815D0B0 @ =0x000005C4
	adds r0, r6, r5
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	b _0815D1F8
	.align 2, 0
_0815D0AC: .4byte 0xFFFFFDFF
_0815D0B0: .4byte 0x000005C4
_0815D0B4:
	adds r0, r6, #0
	bl FUN_0815c4c0
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r2, _0815D118 @ =0x00000482
	adds r1, r6, r2
	movs r0, #2
	strh r0, [r1]
_0815D0DA:
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r5, [r0]
	adds r2, r6, #0
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
	blt _0815D112
	cmp r1, #0
	blt _0815D112
	ldr r0, _0815D11C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815D112
	ldr r0, _0815D120 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815D124
_0815D112:
	movs r4, #0
	b _0815D132
	.align 2, 0
_0815D118: .4byte 0x00000482
_0815D11C: .4byte 0x030046A8
_0815D120: .4byte 0x030046AC
_0815D124:
	ldr r0, _0815D144 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0815D132:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815D148
	adds r0, #4
	b _0815D154
	.align 2, 0
_0815D144: .4byte 0x030046A4
_0815D148:
	ldr r0, _0815D168 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815D154:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0815D16C
	cmp r3, #2
	beq _0815D170
	b _0815D174
	.align 2, 0
_0815D168: .4byte 0x030046A4
_0815D16C:
	ldrb r0, [r5, #4]
	b _0815D172
_0815D170:
	ldrb r0, [r5]
_0815D172:
	subs r2, r2, r0
_0815D174:
	movs r1, #0
	strh r2, [r5, #2]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r6, r5
	ldr r0, [r0]
	strh r1, [r0, #6]
	ldr r1, _0815D1B4 @ =0x000004A4
	adds r0, r6, r1
	ldr r5, [r0]
	adds r7, r6, #0
	adds r7, #8
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0815D1BC
	ldr r0, _0815D1B8 @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	b _0815D1E6
	.align 2, 0
_0815D1B4: .4byte 0x000004A4
_0815D1B8: .4byte 0xFFFFFDFF
_0815D1BC:
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0815D1DC
	cmp r0, #2
	beq _0815D1D8
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0815D1D8:
	movs r0, #1
	b _0815D1E8
_0815D1DC:
	ldr r0, _0815D204 @ =0xFFFFFDFF
	mov r5, r8
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_0815D1E6:
	movs r0, #0
_0815D1E8:
	cmp r0, #0
	bne _0815D1F8
	ldr r1, _0815D208 @ =0x000005C4
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
_0815D1F8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815D204: .4byte 0xFFFFFDFF
_0815D208: .4byte 0x000005C4

	thumb_func_start FUN_0815d20c
FUN_0815d20c: @ 0x0815D20C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	str r0, [sp]
	movs r0, #0xc3
	lsls r0, r0, #3
	add r0, r8
	ldr r1, [r0]
	mov r0, r8
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	beq _0815D23E
	movs r0, #1
	b _0815D6BE
_0815D23E:
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r1, #0xbc
	lsls r1, r1, #1
	add r1, r8
	ldr r0, [r1]
	ands r0, r2
	str r1, [sp, #0x14]
	cmp r0, #0
	bne _0815D254
	b _0815D6BC
_0815D254:
	movs r6, #0x97
	lsls r6, r6, #3
	add r6, r8
	movs r0, #0xf6
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	bne _0815D268
	b _0815D6BC
_0815D268:
	mov r0, r8
	movs r1, #6
	bl FUN_080f9a38
	adds r4, r0, #0
	cmp r4, #0
	bne _0815D278
	b _0815D6BC
_0815D278:
	movs r5, #0x80
	lsls r5, r5, #5
	movs r1, #0xc0
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	ands r0, r5
	str r1, [sp, #0x18]
	cmp r0, #0
	beq _0815D29C
	ldr r0, [r6]
	bl FUN_080f8e3c
	ldr r1, [sp, #0x18]
	ldrh r0, [r1]
	bics r0, r5
	strh r0, [r1]
	str r7, [r6]
_0815D29C:
	movs r1, #0xec
	lsls r1, r1, #1
	add r1, r8
	ldr r0, [r4]
	str r0, [r1]
	ldr r0, [r0, #0x18]
	ldrh r0, [r0, #6]
	str r0, [sp, #4]
	ldr r2, _0815D2F0 @ =0x00000222
	add r2, r8
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0xfc
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	bne _0815D2C8
	b _0815D620
_0815D2C8:
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	str r0, [sp, #8]
	ldr r4, _0815D2F4 @ =0x00000256
	add r4, r8
	ldrh r6, [r4]
	mov r5, r8
	adds r5, #8
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	str r4, [sp, #0x10]
	str r5, [sp, #0xc]
	cmp r0, #0
	beq _0815D2F8
	adds r0, #4
	b _0815D304
	.align 2, 0
_0815D2F0: .4byte 0x00000222
_0815D2F4: .4byte 0x00000256
_0815D2F8:
	ldr r0, _0815D318 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815D304:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0815D31C
	cmp r3, #2
	beq _0815D320
	b _0815D324
	.align 2, 0
_0815D318: .4byte 0x030046A4
_0815D31C:
	ldrb r0, [r5, #4]
	b _0815D322
_0815D320:
	ldrb r0, [r5]
_0815D322:
	subs r2, r2, r0
_0815D324:
	mov sb, r2
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815D336
	adds r0, #4
	b _0815D342
_0815D336:
	ldr r0, _0815D354 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815D342:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	mov r2, r8
	ldrb r0, [r2, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _0815D358
	asrs r0, r0, #6
	b _0815D35E
	.align 2, 0
_0815D354: .4byte 0x030046A4
_0815D358:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0815D35E:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _0815D3A6
	cmp r1, #1
	bgt _0815D370
	cmp r1, #0
	beq _0815D37A
	b _0815D484
_0815D370:
	cmp r1, #2
	beq _0815D3EC
	cmp r1, #3
	beq _0815D418
	b _0815D484
_0815D37A:
	adds r4, r6, #1
	movs r5, #0
	ldr r0, [sp, #8]
	movs r1, #0xd6
	lsls r1, r1, #3
	adds r0, r0, r1
	mov sl, r0
_0815D388:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815D3A2
	adds r4, #1
	adds r5, #1
	cmp r5, #2
	blt _0815D388
_0815D3A2:
	subs r5, r4, #1
	b _0815D492
_0815D3A6:
	ldr r1, _0815D3E8 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r6, r0
	movs r5, #0
	ldr r0, [sp, #8]
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r0, r0, r2
	mov sl, r0
_0815D3BE:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815D45C
	ldr r0, _0815D3E8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #2
	blt _0815D3BE
	subs r5, r4, r0
	b _0815D492
	.align 2, 0
_0815D3E8: .4byte 0x030046A4
_0815D3EC:
	subs r4, r6, #1
	movs r5, #0
	ldr r2, [sp, #8]
	movs r0, #0xd6
	lsls r0, r0, #3
	adds r2, r2, r0
	mov sl, r2
_0815D3FA:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815D414
	subs r4, #1
	adds r5, #1
	cmp r5, #2
	blt _0815D3FA
_0815D414:
	adds r5, r4, #1
	b _0815D492
_0815D418:
	ldr r1, _0815D458 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r6, r0
	movs r5, #0
	ldr r0, [sp, #8]
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r0, r0, r2
	mov sl, r0
_0815D430:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815D470
	ldr r0, _0815D458 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	adds r5, #1
	cmp r5, #2
	blt _0815D430
	adds r5, r4, r0
	b _0815D492
	.align 2, 0
_0815D458: .4byte 0x030046A4
_0815D45C:
	ldr r1, _0815D46C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r4, r0
	b _0815D492
	.align 2, 0
_0815D46C: .4byte 0x030046A4
_0815D470:
	ldr r1, _0815D480 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r5, r4, r0
	b _0815D492
	.align 2, 0
_0815D480: .4byte 0x030046A4
_0815D484:
	ldr r0, [sp, #0x10]
	ldrh r5, [r0]
	ldr r1, [sp, #8]
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r1, r1, r2
	mov sl, r1
_0815D492:
	ldr r0, [sp, #0x10]
	ldrh r0, [r0]
	cmp r5, r0
	bne _0815D514
	mov r6, sl
	ldr r1, _0815D4D8 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _0815D4D8 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815D4DC
	adds r0, #4
	b _0815D4E8
	.align 2, 0
_0815D4D8: .4byte 0x030046A4
_0815D4DC:
	ldr r1, _0815D50C @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815D4E8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r2, [sp, #8]
	ldr r1, _0815D510 @ =0x000006E2
	adds r0, r2, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _0815D570
	movs r0, #0
	b _0815D572
	.align 2, 0
_0815D50C: .4byte 0x030046A4
_0815D510: .4byte 0x000006E2
_0815D514:
	mov r6, sl
	ldr r1, _0815D550 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _0815D550 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815D554
	adds r0, #4
	b _0815D560
	.align 2, 0
_0815D550: .4byte 0x030046A4
_0815D554:
	ldr r1, _0815D5D0 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815D560:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r6, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r6, #4]
_0815D570:
	movs r0, #1
_0815D572:
	cmp r0, #0
	beq _0815D620
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldr r2, [sp, #0x14]
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0815D5FC
	ldr r0, _0815D5D4 @ =0x0000025E
	add r0, r8
	ldrh r0, [r0]
	ldr r1, [sp, #4]
	cmp r0, r1
	beq _0815D602
	ldr r0, _0815D5D8 @ =0x000004A4
	add r0, r8
	ldr r5, [r0]
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	ldr r1, [sp, #0xc]
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	beq _0815D5DC
	adds r0, r5, #0
	ldr r1, [sp, #0xc]
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0815D5DC
	cmp r0, #2
	beq _0815D5E6
	mov r0, r8
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _0815D5E6
	.align 2, 0
_0815D5D0: .4byte 0x030046A4
_0815D5D4: .4byte 0x0000025E
_0815D5D8: .4byte 0x000004A4
_0815D5DC:
	ldr r0, _0815D5F4 @ =0xFFFFFDFF
	ldr r2, [sp, #0x18]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0815D5E6:
	ldr r0, _0815D5F8 @ =0x0000025E
	add r0, r8
	mov r1, sp
	ldrh r1, [r1, #4]
	strh r1, [r0]
	b _0815D602
	.align 2, 0
_0815D5F4: .4byte 0xFFFFFDFF
_0815D5F8: .4byte 0x0000025E
_0815D5FC:
	mov r0, r8
	bl FUN_080f00ec
_0815D602:
	movs r0, #0x80
	movs r2, #0xc1
	lsls r2, r2, #1
	add r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0x14
	ldr r2, [sp, #0x14]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r0, #1
	b _0815D6BE
_0815D620:
	ldr r0, _0815D6A0 @ =0x00000544
	add r0, r8
	ldrh r0, [r0]
	cmp r0, #0
	bne _0815D6BC
	movs r3, #0x80
	ldr r1, [sp, #0x14]
	ldr r0, [r1]
	ands r0, r3
	cmp r0, #0
	bne _0815D6BC
	ldr r0, [sp]
	movs r1, #0xe0
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, _0815D6A4 @ =0xFFFBFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _0815D6A8 @ =0xFFFFFBFF
	ldr r2, [sp, #0x18]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _0815D6AC @ =0x00000542
	add r1, r8
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, [sp, #0x14]
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	ldr r1, _0815D6B0 @ =0x00000202
	add r1, r8
	movs r0, #0xb4
	strh r0, [r1]
	adds r0, #0x4c
	movs r2, #0xc1
	lsls r2, r2, #1
	add r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0815D6B4 @ =0x000001DF
	add r0, r8
	ldrb r3, [r0]
	mov r0, r8
	movs r1, #0
	movs r2, #1
	bl FUN_080e5718
	ldr r0, [sp]
	ldr r1, _0815D6B8 @ =0x000006F4
	adds r2, r0, r1
	movs r0, #0xec
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #1
	b _0815D6BE
	.align 2, 0
_0815D6A0: .4byte 0x00000544
_0815D6A4: .4byte 0xFFFBFFFF
_0815D6A8: .4byte 0xFFFFFBFF
_0815D6AC: .4byte 0x00000542
_0815D6B0: .4byte 0x00000202
_0815D6B4: .4byte 0x000001DF
_0815D6B8: .4byte 0x000006F4
_0815D6BC:
	movs r0, #0
_0815D6BE:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0815d6d0
FUN_0815d6d0: @ 0x0815D6D0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x90
	str r0, [sp, #0x10]
	movs r1, #2
	ldr r2, _0815D6F0 @ =0x00000222
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815D6F4
	movs r0, #1
	b _0815D6F6
	.align 2, 0
_0815D6F0: .4byte 0x00000222
_0815D6F4:
	movs r0, #0
_0815D6F6:
	cmp r0, #0
	beq _0815D6FE
	bl _0815E834
_0815D6FE:
	movs r2, #1
	ldr r3, [sp, #0x10]
	ldr r4, _0815D714 @ =0x00000222
	adds r1, r3, r4
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #0x7c]
	cmp r0, #0
	beq _0815D718
	movs r0, #1
	b _0815D71A
	.align 2, 0
_0815D714: .4byte 0x00000222
_0815D718:
	movs r0, #0
_0815D71A:
	cmp r0, #0
	bne _0815D722
	bl _0815E834
_0815D722:
	ldr r5, [sp, #0x10]
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r0, [r0]
	movs r7, #0xa
	ldrsh r1, [r5, r7]
	movs r2, #0xa
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bne _0815D73A
	b _0815DD88
_0815D73A:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r3, r5, r4
	ldr r5, [r3]
	ldr r2, [sp, #0x10]
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
	str r2, [sp, #0x38]
	cmp r4, #0
	blt _0815D776
	cmp r1, #0
	blt _0815D776
	ldr r0, _0815D77C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0815D776
	ldr r0, _0815D780 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815D784
_0815D776:
	movs r4, #0
	b _0815D792
	.align 2, 0
_0815D77C: .4byte 0x030046A8
_0815D780: .4byte 0x030046AC
_0815D784:
	ldr r0, _0815D7A4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0815D792:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815D7A8
	adds r0, #4
	b _0815D7B4
	.align 2, 0
_0815D7A4: .4byte 0x030046A4
_0815D7A8:
	ldr r0, _0815D7C8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815D7B4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0815D7CC
	cmp r2, #2
	beq _0815D7D0
	b _0815D7D4
	.align 2, 0
_0815D7C8: .4byte 0x030046A4
_0815D7CC:
	ldrb r0, [r5, #4]
	b _0815D7D2
_0815D7D0:
	ldrb r0, [r5]
_0815D7D2:
	subs r1, r1, r0
_0815D7D4:
	strh r1, [r5, #2]
	ldr r0, _0815D7E8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0815D7EC
	movs r0, #1
	b _0815D7EE
	.align 2, 0
_0815D7E8: .4byte 0x030047A4
_0815D7EC:
	movs r0, #0
_0815D7EE:
	cmp r0, #0
	beq _0815D838
	ldr r5, [sp, #0x10]
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _0815D810
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0815D80C
	adds r2, r0, #0
_0815D80C:
	cmp r2, #0
	bge _0815D824
_0815D810:
	ldr r7, [sp, #0x10]
	ldr r1, _0815D820 @ =0x000005C4
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0815DD70
	.align 2, 0
_0815D820: .4byte 0x000005C4
_0815D824:
	ldr r1, _0815D834 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0815D884
	.align 2, 0
_0815D834: .4byte 0x03002BE0
_0815D838:
	ldr r2, [sp, #0x10]
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0815D866
	cmp r1, #0
	blt _0815D866
	ldr r0, _0815D86C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815D866
	ldr r0, _0815D870 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815D874
_0815D866:
	movs r5, #0
	b _0815D882
	.align 2, 0
_0815D86C: .4byte 0x030046A8
_0815D870: .4byte 0x030046AC
_0815D874:
	ldr r0, _0815D968 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0815D882:
	movs r2, #0
_0815D884:
	ldr r4, [sp, #0x10]
	ldr r6, _0815D96C @ =0x00000256
	adds r0, r4, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _0815D8A6
	ldr r1, _0815D970 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0815D8A6
	b _0815DCA8
_0815D8A6:
	movs r0, #0x80
	lsls r0, r0, #3
	ldr r7, [sp, #0x10]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	str r2, [sp, #0x60]
	cmp r7, #0
	beq _0815D8C2
	b _0815DD70
_0815D8C2:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r2, [sp, #0x7c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x60]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _0815D988
	ldr r4, [sp, #0x10]
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r4, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _0815D974 @ =0x0000046D
	adds r4, r4, r6
	mov ip, r4
	movs r2, #1
	mov sb, r2
	mov r3, sb
	strb r3, [r4]
	ldr r4, [sp, #0x10]
	ldr r5, _0815D978 @ =0x0000046B
	adds r4, r4, r5
	mov sl, r4
	movs r6, #0
	strb r6, [r4]
	ldr r2, [sp, #0x10]
	ldr r3, _0815D97C @ =0x00000553
	adds r2, r2, r3
	mov r8, r2
	strb r0, [r2]
	movs r5, #0xaf
	lsls r5, r5, #3
	ldr r4, [sp, #0x10]
	adds r5, r4, r5
	str r5, [sp, #0x88]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r4, r6
	strh r7, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r4, r1
	movs r2, #0
	strb r2, [r4]
	ldr r6, [sp, #0x10]
	adds r1, #1
	adds r3, r6, r1
	strb r2, [r3]
	adds r1, #1
	adds r2, r6, r1
	strb r0, [r2]
	ldr r0, _0815D980 @ =0x00000484
	adds r1, r6, r0
	str r7, [r1]
	ldr r7, _0815D984 @ =0x0000046C
	adds r0, r6, r7
	mov r6, sb
	strb r6, [r0]
	mov r7, ip
	str r7, [sp, #0x50]
	mov r6, sl
	str r6, [sp, #0x48]
	mov r7, r8
	str r7, [sp, #0x70]
	ldr r6, [sp, #0x88]
	str r6, [sp, #0x78]
	str r5, [sp, #0x74]
	str r4, [sp, #0x3c]
	str r3, [sp, #0x40]
	str r2, [sp, #0x44]
	str r1, [sp, #0x58]
	str r0, [sp, #0x4c]
	b _0815DB58
	.align 2, 0
_0815D968: .4byte 0x030046A4
_0815D96C: .4byte 0x00000256
_0815D970: .4byte 0x03002BE0
_0815D974: .4byte 0x0000046D
_0815D978: .4byte 0x0000046B
_0815D97C: .4byte 0x00000553
_0815D980: .4byte 0x00000484
_0815D984: .4byte 0x0000046C
_0815D988:
	ldr r7, [sp, #0x10]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, _0815DA4C @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x18]
	strb r0, [r3]
	adds r4, r7, #0
	ldr r5, _0815DA50 @ =0x0000046B
	adds r4, r4, r5
	mov ip, r4
	movs r6, #0
	strb r6, [r4]
	ldr r3, _0815DA54 @ =0x00000553
	adds r7, r7, r3
	mov sl, r7
	strb r0, [r7]
	ldr r4, [sp, #0x10]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r4, r4, r5
	mov sb, r4
	str r1, [r4]
	ldr r6, [sp, #0x10]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r6, r6, r7
	mov r8, r6
	strh r2, [r6]
	movs r1, #5
	ldr r3, [sp, #0x10]
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r6, r3, r4
	movs r5, #0
	strb r5, [r6]
	ldr r7, _0815DA58 @ =0x00000469
	adds r5, r3, r7
	movs r3, #0
	strb r3, [r5]
	ldr r7, [sp, #0x10]
	ldr r3, _0815DA5C @ =0x0000046A
	adds r4, r7, r3
	strb r1, [r4]
	ldr r1, _0815DA60 @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	subs r1, #0x18
	adds r2, r7, r1
	strb r0, [r2]
	ldr r7, [sp, #0x5c]
	ldr r7, [r7]
	str r7, [sp, #0x1c]
	ldr r1, [sp, #0x38]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	strh r1, [r7]
	ldr r7, [sp, #0x38]
	ldr r0, [r7, #8]
	ldrh r0, [r0, #2]
	ldr r7, [sp, #0x1c]
	strh r0, [r7, #4]
	lsls r1, r1, #0x10
	asrs r7, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x50]
	mov r0, ip
	str r0, [sp, #0x48]
	mov r0, sl
	str r0, [sp, #0x70]
	mov r0, sb
	str r0, [sp, #0x78]
	mov r0, r8
	str r0, [sp, #0x74]
	str r6, [sp, #0x3c]
	str r5, [sp, #0x40]
	str r4, [sp, #0x44]
	str r3, [sp, #0x58]
	str r2, [sp, #0x4c]
	cmp r7, #0
	blt _0815DA48
	cmp r1, #0
	blt _0815DA48
	ldr r0, _0815DA64 @ =0x030046A8
	ldr r0, [r0]
	cmp r7, r0
	bhs _0815DA48
	ldr r0, _0815DA68 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815DA6C
_0815DA48:
	movs r7, #0
	b _0815DA7A
	.align 2, 0
_0815DA4C: .4byte 0x0000046D
_0815DA50: .4byte 0x0000046B
_0815DA54: .4byte 0x00000553
_0815DA58: .4byte 0x00000469
_0815DA5C: .4byte 0x0000046A
_0815DA60: .4byte 0x00000484
_0815DA64: .4byte 0x030046A8
_0815DA68: .4byte 0x030046AC
_0815DA6C:
	ldr r0, _0815DA8C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r7, r0, r7
_0815DA7A:
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815DA90
	adds r0, #4
	b _0815DA9C
	.align 2, 0
_0815DA8C: .4byte 0x030046A4
_0815DA90:
	ldr r0, _0815DAB0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815DA9C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0815DAB4
	cmp r2, #2
	beq _0815DABA
	b _0815DAC0
	.align 2, 0
_0815DAB0: .4byte 0x030046A4
_0815DAB4:
	ldr r2, [sp, #0x1c]
	ldrb r0, [r2, #4]
	b _0815DABE
_0815DABA:
	ldr r3, [sp, #0x1c]
	ldrb r0, [r3]
_0815DABE:
	subs r1, r1, r0
_0815DAC0:
	ldr r4, [sp, #0x1c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x5c]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0815DAEC
	cmp r1, #0
	blt _0815DAEC
	ldr r0, _0815DAF0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815DAEC
	ldr r0, _0815DAF4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815DAF8
_0815DAEC:
	movs r7, #0
	b _0815DB06
	.align 2, 0
_0815DAF0: .4byte 0x030046A8
_0815DAF4: .4byte 0x030046AC
_0815DAF8:
	ldr r0, _0815DB1C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r7, r0, r2
_0815DB06:
	ldr r6, [sp, #0x5c]
	ldr r4, [r6]
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815DB20
	adds r0, #4
	b _0815DB2C
	.align 2, 0
_0815DB1C: .4byte 0x030046A4
_0815DB20:
	ldr r0, _0815DB40 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815DB2C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0815DB44
	cmp r3, #2
	beq _0815DB48
	b _0815DB4C
	.align 2, 0
_0815DB40: .4byte 0x030046A4
_0815DB44:
	ldrb r0, [r4, #4]
	b _0815DB4A
_0815DB48:
	ldrb r0, [r4]
_0815DB4A:
	subs r2, r2, r0
_0815DB4C:
	ldr r7, [sp, #0x5c]
	ldr r0, [r7]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r7]
	strh r1, [r0, #6]
_0815DB58:
	ldr r0, [sp, #0x10]
	ldrb r0, [r0, #5]
	str r0, [sp, #0x20]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x60]
	ldrh r0, [r2]
	ands r0, r1
	ldr r4, [sp, #0x20]
	ldr r5, _0815DB88 @ =0x00000482
	ldr r3, [sp, #0x10]
	adds r5, r3, r5
	str r5, [sp, #0x54]
	cmp r0, #0
	beq _0815DB78
	b _0815DC78
_0815DB78:
	movs r1, #4
	ldr r6, [sp, #0x7c]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0815DB8C
	movs r0, #1
	b _0815DB8E
	.align 2, 0
_0815DB88: .4byte 0x00000482
_0815DB8C:
	movs r0, #0
_0815DB8E:
	ldr r1, _0815DC88 @ =0x00000482
	ldr r7, [sp, #0x10]
	adds r1, r7, r1
	str r1, [sp, #0x54]
	cmp r0, #0
	bne _0815DC78
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x88]
	adds r5, r7, #0
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r5, r5, r6
	mov r8, r5
	ldr r0, _0815DC8C @ =0x0000054F
	adds r7, r7, r0
	mov sb, r7
	ldr r1, [sp, #0x10]
	ldr r2, _0815DC90 @ =0x0000054C
	adds r1, r1, r2
	mov sl, r1
	ldr r5, [sp, #0x10]
	adds r6, #5
	adds r5, r5, r6
	mov ip, r5
	subs r0, #1
	ldr r7, [sp, #0x10]
	adds r0, r7, r0
	str r0, [sp, #0x6c]
	ldr r1, _0815DC94 @ =0x00000541
	adds r1, r7, r1
	str r1, [sp, #0x64]
	adds r2, #0x70
	adds r2, r7, r2
	str r2, [sp, #0x80]
	ldr r5, _0815DC98 @ =0x00000542
	adds r5, r7, r5
	str r5, [sp, #0x68]
	ldr r1, _0815DC9C @ =0x030046B8
	ldr r5, _0815DCA0 @ =0x000003FF
	movs r2, #3
	str r4, [sp, #0x8c]
_0815DBE6:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _0815DCA4 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	ldr r7, [sp, #0x8c]
	cmp r0, r7
	bne _0815DC08
	adds r3, #1
	cmp r3, #3
	ble _0815DBE6
	adds r0, r4, #0
_0815DC08:
	movs r3, #0
	ldr r1, [sp, #0x88]
	strb r0, [r1]
	ldr r2, [sp, #0x78]
	ldr r0, [r2]
	mov r4, r8
	str r0, [r4]
	ldr r5, [sp, #0x70]
	ldrb r0, [r5]
	mov r6, sb
	strb r0, [r6]
	ldr r7, [sp, #0x3c]
	ldrb r0, [r7]
	mov r1, sl
	strb r0, [r1]
	ldr r2, [sp, #0x40]
	ldrb r0, [r2]
	mov r4, ip
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	ldrb r0, [r5]
	ldr r6, [sp, #0x6c]
	strb r0, [r6]
	add r7, sp, #0x20
	ldrb r0, [r7]
	ldr r7, [sp, #0x64]
	strb r0, [r7]
	ldr r0, [sp, #0x80]
	ldr r2, [r0]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x50]
	strb r1, [r4]
	ldr r5, [sp, #0x48]
	strb r3, [r5]
	ldr r6, [sp, #0x70]
	strb r0, [r6]
	ldr r7, [sp, #0x78]
	str r2, [r7]
	movs r2, #0
	ldr r0, [sp, #0x74]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x3c]
	strb r0, [r4]
	ldr r5, [sp, #0x40]
	strb r1, [r5]
	ldr r6, [sp, #0x44]
	strb r2, [r6]
	ldr r7, [sp, #0x58]
	str r3, [r7]
	ldr r0, [sp, #0x4c]
	strb r1, [r0]
	movs r0, #6
	ldr r1, [sp, #0x68]
	strb r0, [r1]
_0815DC78:
	ldr r0, [sp, #0x10]
	bl FUN_080e7b6c
	movs r0, #2
	ldr r2, [sp, #0x54]
	strh r0, [r2]
	b _0815DD70
	.align 2, 0
_0815DC88: .4byte 0x00000482
_0815DC8C: .4byte 0x0000054F
_0815DC90: .4byte 0x0000054C
_0815DC94: .4byte 0x00000541
_0815DC98: .4byte 0x00000542
_0815DC9C: .4byte 0x030046B8
_0815DCA0: .4byte 0x000003FF
_0815DCA4: .4byte 0x0203B400
_0815DCA8:
	mov r8, sp
	ldr r6, _0815DCE4 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r1, [r0, r7]
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
	beq _0815DCE8
	adds r0, #4
	b _0815DCF2
	.align 2, 0
_0815DCE4: .4byte 0x030046A4
_0815DCE8:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815DCF2:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r2, [sp, #0x10]
	ldr r3, _0815DD28 @ =0x000004A4
	adds r0, r2, r3
	ldr r4, [r0]
	adds r5, r2, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _0815DD2C
	ldr r4, [sp, #0x10]
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r4, r5
	b _0815DD54
	.align 2, 0
_0815DD28: .4byte 0x000004A4
_0815DD2C:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _0815DD4C
	cmp r0, #2
	beq _0815DD48
	ldr r0, [sp, #0x10]
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0815DD48:
	movs r0, #1
	b _0815DD5E
_0815DD4C:
	ldr r6, [sp, #0x10]
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r0, r6, r7
_0815DD54:
	ldr r1, _0815DD80 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0815DD5E:
	cmp r0, #0
	bne _0815DD70
	ldr r1, [sp, #0x10]
	ldr r2, _0815DD84 @ =0x000005C4
	adds r0, r1, r2
	ldr r1, [r0]
	ldr r0, [sp, #0x10]
	bl _call_via_r1
_0815DD70:
	movs r0, #2
	ldr r3, [sp, #0x7c]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r0, #1
	bl _0815E836
	.align 2, 0
_0815DD80: .4byte 0xFFFFFDFF
_0815DD84: .4byte 0x000005C4
_0815DD88:
	ldr r4, [sp, #0x10]
	ldrb r0, [r4, #5]
	adds r0, #0x20
	asrs r1, r0, #6
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	bne _0815DD9A
	b _0815E044
_0815DD9A:
	cmp r1, #1
	bgt _0815DDA4
	cmp r1, #0
	beq _0815DDB0
	b _0815E2B8
_0815DDA4:
	cmp r1, #2
	beq _0815DDB0
	cmp r1, #3
	bne _0815DDAE
	b _0815E044
_0815DDAE:
	b _0815E2B8
_0815DDB0:
	ldr r5, [sp, #0x10]
	ldr r6, _0815DDE4 @ =0x00000256
	adds r4, r5, r6
	ldrh r1, [r4]
	ldr r5, _0815DDE8 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r0, [r0, r7]
	subs r0, r1, r0
	mov r8, r0
	adds r7, r1, #0
	ldr r0, [sp, #0x10]
	movs r1, #0xa
	ldrsh r0, [r0, r1]
	mov sb, r0
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	str r4, [sp, #0x84]
	cmp r0, #0
	beq _0815DDEC
	adds r0, #4
	b _0815DDF6
	.align 2, 0
_0815DDE4: .4byte 0x00000256
_0815DDE8: .4byte 0x030046A4
_0815DDEC:
	ldr r0, [r5]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815DDF6:
	ldrb r0, [r0]
	lsrs r4, r0, #4
	ldr r2, _0815DE20 @ =0x030046A4
	mov sl, r2
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	movs r5, #6
	ldrsh r0, [r0, r5]
	adds r6, r1, #0
	muls r6, r0, r6
	str r6, [sp, #0x24]
	cmp r7, r8
	bge _0815DE8C
	adds r5, r7, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	b _0815DE2C
	.align 2, 0
_0815DE20: .4byte 0x030046A4
_0815DE24:
	cmp r5, r8
	beq _0815DE88
	adds r5, #1
	adds r6, #1
_0815DE2C:
	mov r1, sl
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _0815DE4C
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815DE24
_0815DE4C:
	mov r3, sl
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r0, [r0, r5]
	adds r5, r7, r0
	b _0815DE6A
_0815DE5A:
	cmp r5, r8
	beq _0815DE88
	ldr r0, _0815DE84 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	adds r5, r5, r0
_0815DE6A:
	ldr r0, [sp, #0x24]
	cmp r0, r5
	ble _0815DEEE
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815DE5A
	b _0815DEEE
	.align 2, 0
_0815DE84: .4byte 0x030046A4
_0815DE88:
	movs r0, #1
	b _0815DEF0
_0815DE8C:
	subs r5, r7, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	b _0815DEA0
_0815DE98:
	cmp r5, r8
	beq _0815DE88
	subs r5, #1
	subs r6, #1
_0815DEA0:
	cmp r6, #0
	blt _0815DEB6
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815DE98
_0815DEB6:
	ldr r0, _0815DEC4 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r7, r0
	b _0815DED8
	.align 2, 0
_0815DEC4: .4byte 0x030046A4
_0815DEC8:
	cmp r5, r8
	beq _0815DE88
	ldr r0, _0815DEFC @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r5, r0
_0815DED8:
	cmp r5, #0
	blt _0815DEEE
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815DEC8
_0815DEEE:
	movs r0, #0
_0815DEF0:
	cmp r0, #0
	beq _0815DF00
	movs r3, #3
	str r3, [sp, #0x14]
	b _0815E2C6
	.align 2, 0
_0815DEFC: .4byte 0x030046A4
_0815DF00:
	ldr r4, [sp, #0x84]
	ldrh r1, [r4]
	ldr r5, _0815DF2C @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	adds r0, r0, r1
	mov r8, r0
	adds r4, r1, #0
	ldr r7, [sp, #0x10]
	movs r0, #0xa
	ldrsh r7, [r7, r0]
	mov sb, r7
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815DF30
	adds r0, #4
	b _0815DF3A
	.align 2, 0
_0815DF2C: .4byte 0x030046A4
_0815DF30:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815DF3A:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	ldr r1, _0815DF64 @ =0x030046A4
	mov sl, r1
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	movs r3, #6
	ldrsh r0, [r0, r3]
	adds r5, r1, #0
	muls r5, r0, r5
	str r5, [sp, #0x28]
	cmp r4, r8
	bge _0815DFD0
	adds r5, r4, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	b _0815DF70
	.align 2, 0
_0815DF64: .4byte 0x030046A4
_0815DF68:
	cmp r5, r8
	beq _0815DFCC
	adds r5, #1
	adds r6, #1
_0815DF70:
	mov r1, sl
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _0815DF90
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815DF68
_0815DF90:
	mov r3, sl
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r0, [r0, r5]
	adds r5, r4, r0
	b _0815DFAE
_0815DF9E:
	cmp r5, r8
	beq _0815DFCC
	ldr r0, _0815DFC8 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	adds r5, r5, r0
_0815DFAE:
	ldr r0, [sp, #0x28]
	cmp r0, r5
	ble _0815E032
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815DF9E
	b _0815E032
	.align 2, 0
_0815DFC8: .4byte 0x030046A4
_0815DFCC:
	movs r0, #1
	b _0815E034
_0815DFD0:
	subs r5, r4, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	b _0815DFE4
_0815DFDC:
	cmp r5, r8
	beq _0815DFCC
	subs r5, #1
	subs r6, #1
_0815DFE4:
	cmp r6, #0
	blt _0815DFFA
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815DFDC
_0815DFFA:
	ldr r0, _0815E008 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r4, r0
	b _0815E01C
	.align 2, 0
_0815E008: .4byte 0x030046A4
_0815E00C:
	cmp r5, r8
	beq _0815DFCC
	ldr r0, _0815E040 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r5, r0
_0815E01C:
	cmp r5, #0
	blt _0815E032
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815E00C
_0815E032:
	movs r0, #0
_0815E034:
	cmp r0, #0
	bne _0815E03A
	b _0815E2B8
_0815E03A:
	movs r3, #1
	str r3, [sp, #0x14]
	b _0815E2C6
	.align 2, 0
_0815E040: .4byte 0x030046A4
_0815E044:
	ldr r5, [sp, #0x10]
	ldr r6, _0815E06C @ =0x00000256
	adds r4, r5, r6
	ldrh r0, [r4]
	adds r7, r0, #1
	mov r8, r7
	adds r7, r0, #0
	movs r1, #0xa
	ldrsh r0, [r5, r1]
	mov sb, r0
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	str r4, [sp, #0x84]
	cmp r0, #0
	beq _0815E070
	adds r0, #4
	b _0815E07C
	.align 2, 0
_0815E06C: .4byte 0x00000256
_0815E070:
	ldr r2, _0815E0A8 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815E07C:
	ldrb r0, [r0]
	lsrs r4, r0, #4
	ldr r2, _0815E0A8 @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	movs r5, #6
	ldrsh r0, [r0, r5]
	adds r6, r1, #0
	muls r6, r0, r6
	str r6, [sp, #0x2c]
	cmp r7, r8
	bge _0815E114
	adds r5, r7, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	ldr r0, _0815E0A8 @ =0x030046A4
	mov sl, r0
	b _0815E0B4
	.align 2, 0
_0815E0A8: .4byte 0x030046A4
_0815E0AC:
	cmp r5, r8
	beq _0815E110
	adds r5, #1
	adds r6, #1
_0815E0B4:
	mov r1, sl
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _0815E0D4
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815E0AC
_0815E0D4:
	mov r3, sl
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r0, [r0, r5]
	adds r5, r7, r0
	b _0815E0F2
_0815E0E2:
	cmp r5, r8
	beq _0815E110
	ldr r0, _0815E10C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	adds r5, r5, r0
_0815E0F2:
	ldr r0, [sp, #0x2c]
	cmp r0, r5
	ble _0815E176
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815E0E2
	b _0815E176
	.align 2, 0
_0815E10C: .4byte 0x030046A4
_0815E110:
	movs r0, #1
	b _0815E178
_0815E114:
	subs r5, r7, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	b _0815E128
_0815E120:
	cmp r5, r8
	beq _0815E110
	subs r5, #1
	subs r6, #1
_0815E128:
	cmp r6, #0
	blt _0815E13E
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815E120
_0815E13E:
	ldr r0, _0815E14C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r7, r0
	b _0815E160
	.align 2, 0
_0815E14C: .4byte 0x030046A4
_0815E150:
	cmp r5, r8
	beq _0815E110
	ldr r0, _0815E184 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r5, r0
_0815E160:
	cmp r5, #0
	blt _0815E176
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r4, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815E150
_0815E176:
	movs r0, #0
_0815E178:
	cmp r0, #0
	beq _0815E188
	movs r3, #0
	str r3, [sp, #0x14]
	b _0815E2C6
	.align 2, 0
_0815E184: .4byte 0x030046A4
_0815E188:
	ldr r4, [sp, #0x84]
	ldrh r0, [r4]
	subs r5, r0, #1
	mov r8, r5
	adds r4, r0, #0
	ldr r6, [sp, #0x10]
	movs r7, #0xa
	ldrsh r6, [r6, r7]
	mov sb, r6
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815E1A8
	adds r0, #4
	b _0815E1B4
_0815E1A8:
	ldr r2, _0815E1E0 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815E1B4:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	ldr r1, _0815E1E0 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	movs r3, #6
	ldrsh r0, [r0, r3]
	adds r5, r1, #0
	muls r5, r0, r5
	str r5, [sp, #0x30]
	cmp r4, r8
	bge _0815E24C
	adds r5, r4, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	ldr r0, _0815E1E0 @ =0x030046A4
	mov sl, r0
	b _0815E1EC
	.align 2, 0
_0815E1E0: .4byte 0x030046A4
_0815E1E4:
	cmp r5, r8
	beq _0815E248
	adds r5, #1
	adds r6, #1
_0815E1EC:
	mov r1, sl
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _0815E20C
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815E1E4
_0815E20C:
	mov r3, sl
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r0, [r0, r5]
	adds r5, r4, r0
	b _0815E22A
_0815E21A:
	cmp r5, r8
	beq _0815E248
	ldr r0, _0815E244 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	adds r5, r5, r0
_0815E22A:
	ldr r0, [sp, #0x30]
	cmp r0, r5
	ble _0815E2AE
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815E21A
	b _0815E2AE
	.align 2, 0
_0815E244: .4byte 0x030046A4
_0815E248:
	movs r0, #1
	b _0815E2B0
_0815E24C:
	subs r5, r4, #1
	adds r0, r5, #0
	bl Mod
	adds r6, r0, #0
	b _0815E260
_0815E258:
	cmp r5, r8
	beq _0815E248
	subs r5, #1
	subs r6, #1
_0815E260:
	cmp r6, #0
	blt _0815E276
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815E258
_0815E276:
	ldr r0, _0815E284 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r4, r0
	b _0815E298
	.align 2, 0
_0815E284: .4byte 0x030046A4
_0815E288:
	cmp r5, r8
	beq _0815E248
	ldr r0, _0815E2E0 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r5, r0
_0815E298:
	cmp r5, #0
	blt _0815E2AE
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815E288
_0815E2AE:
	movs r0, #0
_0815E2B0:
	movs r3, #2
	str r3, [sp, #0x14]
	cmp r0, #0
	bne _0815E2BE
_0815E2B8:
	movs r4, #1
	rsbs r4, r4, #0
	str r4, [sp, #0x14]
_0815E2BE:
	ldr r5, [sp, #0x14]
	cmp r5, #0
	bge _0815E2C6
	b _0815E834
_0815E2C6:
	ldr r6, [sp, #0x10]
	ldr r7, _0815E2E4 @ =0x00000256
	adds r0, r6, r7
	ldrh r0, [r0]
	mov r8, r0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815E2E8
	adds r0, #4
	b _0815E2F6
	.align 2, 0
_0815E2E0: .4byte 0x030046A4
_0815E2E4: .4byte 0x00000256
_0815E2E8:
	ldr r2, _0815E324 @ =0x030046A4
	ldr r1, [r2]
	mov r3, r8
	lsls r0, r3, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815E2F6:
	ldrb r0, [r0]
	movs r4, #0xf
	mov sb, r4
	mov r5, sb
	ands r5, r0
	mov sb, r5
	ldr r6, _0815E324 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r1, [r0, r7]
	movs r2, #6
	ldrsh r0, [r0, r2]
	adds r5, r1, #0
	muls r5, r0, r5
	ldr r3, [sp, #0x14]
	cmp r3, #1
	beq _0815E3C0
	cmp r3, #1
	bgt _0815E328
	cmp r3, #0
	beq _0815E338
	b _0815E55E
	.align 2, 0
_0815E324: .4byte 0x030046A4
_0815E328:
	ldr r4, [sp, #0x14]
	cmp r4, #2
	bne _0815E330
	b _0815E440
_0815E330:
	cmp r4, #3
	bne _0815E336
	b _0815E4E4
_0815E336:
	b _0815E55E
_0815E338:
	mov r4, r8
	adds r4, #1
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	ldr r6, _0815E36C @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r0, [r0, r7]
	cmp r5, r0
	blt _0815E354
	b _0815E55E
_0815E354:
	adds r7, r6, #0
	lsls r0, r4, #2
	adds r6, r0, #0
	adds r6, #0xc
_0815E35C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815E370
	adds r0, #4
	b _0815E376
	.align 2, 0
_0815E36C: .4byte 0x030046A4
_0815E370:
	ldr r0, [r7]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_0815E376:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sb
	bne _0815E3A0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815E390
	adds r0, #4
	b _0815E396
_0815E390:
	ldr r0, [r7]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_0815E396:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _0815E3A4
_0815E3A0:
	movs r0, #0
	b _0815E3A6
_0815E3A4:
	movs r0, #1
_0815E3A6:
	cmp r0, #0
	bne _0815E3AC
	b _0815E4B6
_0815E3AC:
	adds r6, #4
	adds r4, #1
	adds r5, #1
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _0815E35C
	b _0815E55E
_0815E3C0:
	mov r2, r8
	adds r4, r2, r1
	cmp r5, r4
	bgt _0815E3CA
	b _0815E55E
_0815E3CA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815E3DA
	adds r0, #4
	b _0815E3E6
_0815E3DA:
	ldr r0, _0815E400 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815E3E6:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sb
	bne _0815E41A
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815E404
	adds r0, #4
	b _0815E410
	.align 2, 0
_0815E400: .4byte 0x030046A4
_0815E404:
	ldr r2, _0815E420 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815E410:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _0815E424
_0815E41A:
	movs r0, #0
	b _0815E426
	.align 2, 0
_0815E420: .4byte 0x030046A4
_0815E424:
	movs r0, #1
_0815E426:
	cmp r0, #0
	beq _0815E4BA
	ldr r3, _0815E43C @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r6, #4
	ldrsh r0, [r0, r6]
	adds r4, r4, r0
	cmp r5, r4
	bgt _0815E3CA
	b _0815E55E
	.align 2, 0
_0815E43C: .4byte 0x030046A4
_0815E440:
	mov r4, r8
	subs r4, #1
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	cmp r5, #0
	bge _0815E452
	b _0815E55E
_0815E452:
	lsls r0, r4, #2
	adds r6, r0, #0
	adds r6, #0xc
	ldr r7, _0815E46C @ =0x030046A4
_0815E45A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815E470
	adds r0, #4
	b _0815E476
	.align 2, 0
_0815E46C: .4byte 0x030046A4
_0815E470:
	ldr r0, [r7]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_0815E476:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sb
	bne _0815E4A0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815E490
	adds r0, #4
	b _0815E496
_0815E490:
	ldr r0, [r7]
	ldr r0, [r0, #4]
	adds r0, r0, r6
_0815E496:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _0815E4A4
_0815E4A0:
	movs r0, #0
	b _0815E4A6
_0815E4A4:
	movs r0, #1
_0815E4A6:
	cmp r0, #0
	beq _0815E4CC
	subs r6, #4
	subs r4, #1
	subs r5, #1
	cmp r5, #0
	bge _0815E45A
	b _0815E55E
_0815E4B6:
	subs r5, r4, #1
	b _0815E560
_0815E4BA:
	ldr r7, _0815E4C8 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r4, r0
	b _0815E560
	.align 2, 0
_0815E4C8: .4byte 0x030046A4
_0815E4CC:
	adds r5, r4, #1
	b _0815E560
_0815E4D0:
	ldr r2, _0815E4E0 @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	adds r5, r4, r0
	b _0815E560
	.align 2, 0
_0815E4E0: .4byte 0x030046A4
_0815E4E4:
	mov r5, r8
	subs r4, r5, r1
	cmp r4, #0
	blt _0815E55E
_0815E4EC:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815E4FC
	adds r0, #4
	b _0815E508
_0815E4FC:
	ldr r0, _0815E524 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815E508:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sb
	bne _0815E53E
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815E528
	adds r0, #4
	b _0815E534
	.align 2, 0
_0815E524: .4byte 0x030046A4
_0815E528:
	ldr r2, _0815E544 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815E534:
	ldrh r0, [r0, #2]
	movs r1, #0x43
	ands r0, r1
	cmp r0, #0
	beq _0815E548
_0815E53E:
	movs r0, #0
	b _0815E54A
	.align 2, 0
_0815E544: .4byte 0x030046A4
_0815E548:
	movs r0, #1
_0815E54A:
	cmp r0, #0
	beq _0815E4D0
	ldr r6, _0815E5A4 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r0, [r0, r7]
	subs r4, r4, r0
	cmp r4, #0
	bge _0815E4EC
_0815E55E:
	mov r5, r8
_0815E560:
	cmp r5, #0
	bne _0815E566
	b _0815E834
_0815E566:
	ldr r1, [sp, #0x10]
	ldr r2, _0815E5A8 @ =0x00000256
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r5, r0
	bne _0815E574
	b _0815E834
_0815E574:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r3, [sp, #0x10]
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r1, r3, r4
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #0x60]
	adds r3, #8
	str r3, [sp, #0x34]
	add r7, sp, #8
	cmp r0, #0
	beq _0815E592
	b _0815E6DE
_0815E592:
	movs r1, #4
	ldr r6, [sp, #0x7c]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0815E5AC
	movs r0, #1
	b _0815E5AE
	.align 2, 0
_0815E5A4: .4byte 0x030046A4
_0815E5A8: .4byte 0x00000256
_0815E5AC:
	movs r0, #0
_0815E5AE:
	ldr r7, [sp, #0x10]
	adds r7, #8
	str r7, [sp, #0x34]
	add r7, sp, #8
	cmp r0, #0
	beq _0815E5BC
	b _0815E6DE
_0815E5BC:
	movs r2, #0
	ldr r1, _0815E71C @ =0x0000046D
	ldr r0, [sp, #0x10]
	adds r1, r0, r1
	str r1, [sp, #0x50]
	ldr r3, _0815E720 @ =0x0000046B
	adds r3, r0, r3
	str r3, [sp, #0x48]
	ldr r4, _0815E724 @ =0x00000553
	adds r4, r0, r4
	str r4, [sp, #0x70]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r0, r6
	str r6, [sp, #0x78]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r0, r1
	str r1, [sp, #0x74]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r0, r3
	str r3, [sp, #0x3c]
	ldr r4, _0815E728 @ =0x00000469
	adds r4, r0, r4
	str r4, [sp, #0x40]
	ldr r6, _0815E72C @ =0x0000046A
	adds r6, r0, r6
	str r6, [sp, #0x44]
	ldr r1, _0815E730 @ =0x00000484
	adds r1, r0, r1
	str r1, [sp, #0x58]
	ldr r3, _0815E734 @ =0x0000046C
	adds r3, r0, r3
	str r3, [sp, #0x4c]
	ldrb r4, [r0, #5]
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r6, r0, r6
	str r6, [sp, #0x88]
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r0, r0, r1
	mov r8, r0
	ldr r3, [sp, #0x10]
	ldr r6, _0815E738 @ =0x0000054F
	adds r3, r3, r6
	mov sb, r3
	ldr r0, [sp, #0x10]
	adds r1, #4
	adds r0, r0, r1
	mov sl, r0
	ldr r3, [sp, #0x10]
	subs r6, #2
	adds r3, r3, r6
	mov ip, r3
	adds r1, #2
	ldr r0, [sp, #0x10]
	adds r1, r0, r1
	str r1, [sp, #0x6c]
	ldr r3, _0815E73C @ =0x00000541
	adds r3, r0, r3
	str r3, [sp, #0x64]
	adds r6, #0x6f
	adds r6, r0, r6
	str r6, [sp, #0x80]
	ldr r1, _0815E740 @ =0x00000542
	adds r1, r0, r1
	str r1, [sp, #0x68]
	ldr r1, _0815E744 @ =0x030046B8
	adds r3, r4, #0
_0815E64A:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _0815E748 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _0815E74C @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r3
	bne _0815E66E
	adds r2, #1
	cmp r2, #3
	ble _0815E64A
	adds r0, r4, #0
_0815E66E:
	movs r3, #0
	ldr r1, [sp, #0x88]
	strb r0, [r1]
	ldr r2, [sp, #0x78]
	ldr r0, [r2]
	mov r4, r8
	str r0, [r4]
	ldr r6, [sp, #0x70]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x3c]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r6, [sp, #0x40]
	ldrb r0, [r6]
	mov r1, ip
	strb r0, [r1]
	ldr r2, [sp, #0x44]
	ldrb r0, [r2]
	ldr r4, [sp, #0x6c]
	strb r0, [r4]
	mov r6, sp
	ldrb r0, [r6, #0x14]
	ldr r6, [sp, #0x64]
	strb r0, [r6]
	ldr r1, [sp, #0x80]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x50]
	strb r1, [r4]
	ldr r6, [sp, #0x48]
	strb r3, [r6]
	ldr r4, [sp, #0x70]
	strb r0, [r4]
	ldr r6, [sp, #0x78]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x74]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x3c]
	strb r0, [r4]
	ldr r6, [sp, #0x40]
	strb r1, [r6]
	ldr r0, [sp, #0x44]
	strb r2, [r0]
	ldr r2, [sp, #0x58]
	str r3, [r2]
	ldr r3, [sp, #0x4c]
	strb r1, [r3]
	movs r0, #2
	ldr r4, [sp, #0x68]
	strb r0, [r4]
_0815E6DE:
	mov r8, r7
	ldr r6, _0815E750 @ =0x030046A4
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
	adds r6, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #8
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815E754
	adds r0, #4
	b _0815E760
	.align 2, 0
_0815E71C: .4byte 0x0000046D
_0815E720: .4byte 0x0000046B
_0815E724: .4byte 0x00000553
_0815E728: .4byte 0x00000469
_0815E72C: .4byte 0x0000046A
_0815E730: .4byte 0x00000484
_0815E734: .4byte 0x0000046C
_0815E738: .4byte 0x0000054F
_0815E73C: .4byte 0x00000541
_0815E740: .4byte 0x00000542
_0815E744: .4byte 0x030046B8
_0815E748: .4byte 0x000003FF
_0815E74C: .4byte 0x0203B400
_0815E750: .4byte 0x030046A4
_0815E754:
	ldr r4, _0815E798 @ =0x030046A4
	ldr r0, [r4]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815E760:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r5, r8
	strh r0, [r5, #2]
	lsls r0, r6, #8
	adds r0, #0x80
	strh r0, [r5, #4]
	ldr r6, [sp, #0x10]
	ldrh r0, [r6, #0xa]
	strh r0, [r7, #2]
	ldr r1, _0815E79C @ =0x000004A4
	adds r0, r6, r1
	ldr r4, [r0]
	adds r0, r4, #0
	ldr r1, [sp, #0x34]
	adds r2, r7, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0815E7A4
	ldr r0, _0815E7A0 @ =0xFFFFFDFF
	ldr r2, [sp, #0x60]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0815E7CE
	.align 2, 0
_0815E798: .4byte 0x030046A4
_0815E79C: .4byte 0x000004A4
_0815E7A0: .4byte 0xFFFFFDFF
_0815E7A4:
	adds r0, r4, #0
	ldr r1, [sp, #0x34]
	adds r2, r7, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0815E7C4
	cmp r0, #2
	beq _0815E7C0
	ldr r0, [sp, #0x10]
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0815E7C0:
	movs r0, #1
	b _0815E7D0
_0815E7C4:
	ldr r0, _0815E7E4 @ =0xFFFFFDFF
	ldr r3, [sp, #0x60]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0815E7CE:
	movs r0, #0
_0815E7D0:
	adds r4, r0, #0
	cmp r4, #0
	beq _0815E7E8
	movs r0, #2
	ldr r5, [sp, #0x7c]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	movs r0, #1
	b _0815E836
	.align 2, 0
_0815E7E4: .4byte 0xFFFFFDFF
_0815E7E8:
	ldr r1, _0815E848 @ =FUN_080e48d0
	ldr r5, [sp, #0x10]
	ldr r6, _0815E84C @ =0x0000046D
	adds r0, r5, r6
	movs r3, #1
	strb r3, [r0]
	ldr r7, _0815E850 @ =0x0000046B
	adds r0, r5, r7
	strb r4, [r0]
	ldr r2, _0815E854 @ =0x00000553
	adds r0, r5, r2
	strb r4, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r1, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r7, _0815E858 @ =0x00000469
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _0815E85C @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _0815E860 @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	ldr r4, _0815E864 @ =0x0000046C
	adds r0, r5, r4
	strb r3, [r0]
_0815E834:
	movs r0, #0
_0815E836:
	add sp, #0x90
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0815E848: .4byte FUN_080e48d0
_0815E84C: .4byte 0x0000046D
_0815E850: .4byte 0x0000046B
_0815E854: .4byte 0x00000553
_0815E858: .4byte 0x00000469
_0815E85C: .4byte 0x0000046A
_0815E860: .4byte 0x00000484
_0815E864: .4byte 0x0000046C

	thumb_func_start FUN_0815e868
FUN_0815e868: @ 0x0815E868
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r2, [r0]
	movs r1, #0x40
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815E888
	b _0815E9A0
_0815E888:
	movs r1, #2
	movs r5, #0xe0
	lsls r5, r5, #3
	adds r0, r2, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815E89C
	movs r0, #1
	b _0815E89E
_0815E89C:
	movs r0, #0
_0815E89E:
	adds r5, r0, #0
	cmp r5, #0
	beq _0815E93C
	movs r0, #0x94
	lsls r0, r0, #1
	adds r4, r6, r0
	ldr r1, _0815E92C @ =0x00000226
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r2, _0815E930 @ =0x0000022E
	adds r0, r6, r2
	ldrh r2, [r0]
	movs r3, #0x80
	lsls r3, r3, #4
	movs r5, #0x90
	lsls r5, r5, #2
	adds r0, r6, r5
	ldr r0, [r0]
	str r0, [sp]
	subs r5, #0xa
	adds r0, r6, r5
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	bl FUN_082364f8
	movs r0, #0x10
	movs r5, #0
	strh r0, [r4, #0xa]
	ldr r3, _0815E934 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x40
	orrs r0, r2
	ldr r1, _0815E938 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	adds r2, r6, #0
	adds r2, #0xd8
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	adds r0, r6, #0
	adds r0, #0xec
	strh r5, [r0]
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	rsbs r0, r0, #0
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r0, r3
	adds r1, r6, #0
	adds r1, #0xee
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0xf0
	strh r5, [r0]
	ldrh r1, [r2, #6]
	movs r0, #2
	orrs r0, r1
	b _0815E99E
	.align 2, 0
_0815E92C: .4byte 0x00000226
_0815E930: .4byte 0x0000022E
_0815E934: .4byte 0xFFFF0000
_0815E938: .4byte 0x0000FFFF
_0815E93C:
	movs r0, #0x94
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r1, [r0]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r2, [r0]
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #8
	adds r0, r6, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_082364f8
	movs r0, #0x10
	strh r0, [r4, #0xa]
	movs r1, #0x40
	add r0, sp, #8
	strh r1, [r0]
	movs r3, #0x80
	strh r3, [r0, #2]
	strh r1, [r0, #4]
	adds r2, r6, #0
	adds r2, #0xd8
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	adds r0, r6, #0
	adds r0, #0xec
	strh r5, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	strh r5, [r0]
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
_0815E99E:
	strh r0, [r2, #6]
_0815E9A0:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0815e9a8
FUN_0815e9a8: @ 0x0815E9A8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r1, _0815EA48 @ =FUN_080e6794
	movs r2, #0
	ldr r3, _0815EA4C @ =0x0000046D
	adds r0, r4, r3
	movs r5, #1
	strb r5, [r0]
	ldr r7, _0815EA50 @ =0x0000046B
	adds r0, r4, r7
	strb r2, [r0]
	adds r3, #0xe6
	adds r0, r4, r3
	strb r2, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r4, r7
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r6, #0
	strh r2, [r0]
	movs r1, #3
	subs r3, #0xeb
	adds r0, r4, r3
	strb r1, [r0]
	ldr r7, _0815EA54 @ =0x00000469
	adds r0, r4, r7
	strb r5, [r0]
	ldr r1, _0815EA58 @ =0x0000046A
	adds r0, r4, r1
	strb r6, [r0]
	adds r3, #0x1c
	adds r0, r4, r3
	str r2, [r0]
	adds r7, #3
	adds r0, r4, r7
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_080e6204
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r0, [r0]
	strh r5, [r0, #6]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r4, r3
	ldr r3, [r0]
	movs r5, #7
	movs r1, #0x3c
	adds r7, #0xec
	adds r2, r4, r7
	subs r7, #4
	adds r0, r4, r7
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r4, r1
	strb r6, [r0]
	ldr r3, _0815EA5C @ =0x00000551
	adds r0, r4, r3
	strb r6, [r0]
	subs r7, #2
	adds r0, r4, r7
	strb r5, [r0]
	movs r1, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r4, r4, r0
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815EA48: .4byte FUN_080e6794
_0815EA4C: .4byte 0x0000046D
_0815EA50: .4byte 0x0000046B
_0815EA54: .4byte 0x00000469
_0815EA58: .4byte 0x0000046A
_0815EA5C: .4byte 0x00000551

	thumb_func_start FUN_0815ea60
FUN_0815ea60: @ 0x0815EA60
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r1, #8
	bl ClearMemory
	movs r1, #0xd6
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #8
	bl ClearMemory
	ldr r2, _0815EB40 @ =0x000006C2
	adds r0, r4, r2
	movs r5, #0
	strh r5, [r0]
	ldr r1, _0815EB44 @ =0x000006DC
	adds r0, r4, r1
	strh r5, [r0]
	ldr r2, _0815EB48 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0815EB4C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0815EB50 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r2, _0815EB54 @ =0x000006EE
	adds r1, r4, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl Mod
	movs r2, #0xd9
	lsls r2, r2, #3
	adds r1, r4, r2
	strh r0, [r1]
	ldr r1, _0815EB58 @ =0x000006CA
	adds r0, r4, r1
	strh r5, [r0]
	adds r2, #4
	adds r0, r4, r2
	strh r5, [r0]
	adds r1, #4
	adds r0, r4, r1
	strh r5, [r0]
	adds r2, #0x16
	adds r0, r4, r2
	strh r5, [r0]
	adds r1, #0x16
	adds r0, r4, r1
	strh r5, [r0]
	adds r2, #4
	adds r0, r4, r2
	strh r5, [r0]
	adds r1, #6
	adds r0, r4, r1
	strh r5, [r0]
	adds r2, #0x1a
	adds r0, r4, r2
	str r5, [r0]
	subs r1, #0xa
	adds r0, r4, r1
	strh r5, [r0]
	subs r2, #2
	adds r0, r4, r2
	strh r5, [r0]
	ldr r0, _0815EB5C @ =0x00000704
	adds r4, r4, r0
	str r5, [r4]
	adds r0, r6, #0
	bl FUN_080e6204
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r0, [r6, #0x44]
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
	beq _0815EB60
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0815EB68
	.align 2, 0
_0815EB40: .4byte 0x000006C2
_0815EB44: .4byte 0x000006DC
_0815EB48: .4byte 0x030046B8
_0815EB4C: .4byte 0x000003FF
_0815EB50: .4byte 0x0203B400
_0815EB54: .4byte 0x000006EE
_0815EB58: .4byte 0x000006CA
_0815EB5C: .4byte 0x00000704
_0815EB60:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0815EB68:
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
	beq _0815EB8C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0815EB94
_0815EB8C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0815EB94:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0815EBCC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0815EC04
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0815EBD0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0815EBC4
	ldrb r0, [r4, #5]
_0815EBC4:
	subs r0, #1
	strh r0, [r4, #8]
	b _0815EBE0
	.align 2, 0
_0815EBCC: .4byte 0x0000FFFF
_0815EBD0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0815EBE0
	strh r1, [r4, #8]
_0815EBE0:
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
	bne _0815EC04
	movs r0, #1
	strb r0, [r4, #7]
_0815EC04:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0815ec0c
FUN_0815ec0c: @ 0x0815EC0C
	bx lr
	.align 2, 0

	thumb_func_start FUN_0815ec10
FUN_0815ec10: @ 0x0815EC10
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	mov r8, r1
	adds r6, r2, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x18]
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0815EC3C
	b _0815F2BA
_0815EC3C:
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0815EC68
	ldr r3, _0815EC64 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0815EC54
	b _0815F2BA
_0815EC54:
	movs r0, #0
	mov r4, r8
	strh r1, [r4, #0x3e]
	mov r1, r8
	adds r1, #0x43
	strb r0, [r1]
	b _0815F2BA
	.align 2, 0
_0815EC64: .4byte 0x0000048C
_0815EC68:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _0815EC78
	b _0815F2BA
_0815EC78:
	movs r4, #1
	ldrh r3, [r7, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _0815EC86
	b _0815EF8C
_0815EC86:
	movs r0, #0x80
	lsls r0, r0, #7
	ldr r1, [r7, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _0815EC96
	b _0815F2BA
_0815EC96:
	ldr r2, _0815ED28 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0815ECAA
	b _0815F2BA
_0815ECAA:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0815ECB8
	b _0815F2BA
_0815ECB8:
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
	bne _0815ECD0
	b _0815EE18
_0815ECD0:
	movs r1, #0x80
	lsls r1, r1, #1
	mov r2, r8
	ldrh r0, [r2, #6]
	ands r0, r1
	cmp r0, #0
	beq _0815ED38
	ands r3, r1
	cmp r3, #0
	beq _0815ED38
	mov r0, r8
	adds r0, #0x42
	ldrb r1, [r0]
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0815ECF8
	rsbs r1, r1, #0
_0815ECF8:
	cmp r1, #0x20
	bgt _0815ED38
	ldrh r0, [r7, #0x3c]
	ldr r3, _0815ED2C @ =0x000004BE
	adds r1, r6, r3
	strh r0, [r1]
	ldr r2, _0815ED30 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _0815ED34 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _0815F2BA
	.align 2, 0
_0815ED28: .4byte 0x0000A007
_0815ED2C: .4byte 0x000004BE
_0815ED30: .4byte 0x0000048C
_0815ED34: .4byte 0x0000044E
_0815ED38:
	movs r1, #0
	mov r0, r8
	strh r1, [r0, #0x3e]
	ldr r2, _0815ED60 @ =0x0000048A
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0815ED68
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0815ED64 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0815EDD6
	.align 2, 0
_0815ED60: .4byte 0x0000048A
_0815ED64: .4byte 0x03002BE0
_0815ED68:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0815ED84
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0815ED80 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0815EDD6
	.align 2, 0
_0815ED80: .4byte 0x03002BE0
_0815ED84:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0815EDA0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0815ED9C @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0815EDD6
	.align 2, 0
_0815ED9C: .4byte 0x03002BE0
_0815EDA0:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0815EDBC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0815EDB8 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0815EDD6
	.align 2, 0
_0815EDB8: .4byte 0x03002BE0
_0815EDBC:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0815EDCE
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _0815EDD6
_0815EDCE:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0815EDD8
_0815EDD6:
	movs r3, #1
_0815EDD8:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	ldr r1, [r7, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r1, [r0]
	cmp r3, #0
	bne _0815EDF8
	b _0815EF4C
_0815EDF8:
	movs r1, #2
	ldr r3, _0815EE0C @ =0x00000474
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815EE10
	movs r0, #1
	b _0815EE12
	.align 2, 0
_0815EE0C: .4byte 0x00000474
_0815EE10:
	movs r0, #0
_0815EE12:
	cmp r0, #0
	bne _0815EEF2
	b _0815EF08
_0815EE18:
	mov r1, r8
	strh r2, [r1, #0x3e]
	ldr r3, _0815EE40 @ =0x0000048A
	adds r0, r6, r3
	strh r2, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _0815EE48
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0815EE44 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0815EEB6
	.align 2, 0
_0815EE40: .4byte 0x0000048A
_0815EE44: .4byte 0x03002BE0
_0815EE48:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0815EE64
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0815EE60 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0815EEB6
	.align 2, 0
_0815EE60: .4byte 0x03002BE0
_0815EE64:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _0815EE80
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0815EE7C @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0815EEB6
	.align 2, 0
_0815EE7C: .4byte 0x03002BE0
_0815EE80:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0815EE9C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0815EE98 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0815EEB6
	.align 2, 0
_0815EE98: .4byte 0x03002BE0
_0815EE9C:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0815EEAE
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0815EEB6
_0815EEAE:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0815EEB8
_0815EEB6:
	movs r3, #1
_0815EEB8:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	ldr r1, [r7, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r1, [r0]
	cmp r3, #0
	beq _0815EF4C
	movs r1, #2
	ldr r3, _0815EEE8 @ =0x00000474
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815EEEC
	movs r0, #1
	b _0815EEEE
	.align 2, 0
_0815EEE8: .4byte 0x00000474
_0815EEEC:
	movs r0, #0
_0815EEEE:
	cmp r0, #0
	beq _0815EF08
_0815EEF2:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0815EF04 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0815EF14
	.align 2, 0
_0815EF04: .4byte 0x03002BE0
_0815EF08:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0815EF4C
_0815EF14:
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
_0815EF4C:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0815EF78
	ldr r0, _0815EF84 @ =0x0000024E
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
	bls _0815EF78
	strh r1, [r2]
_0815EF78:
	ldr r0, _0815EF88 @ =0x0000048C
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	b _0815F2BA
	.align 2, 0
_0815EF84: .4byte 0x0000024E
_0815EF88: .4byte 0x0000048C
_0815EF8C:
	ldr r0, _0815EFA0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0815EFA4
	movs r0, #1
	b _0815EFA6
	.align 2, 0
_0815EFA0: .4byte 0x030047A4
_0815EFA4:
	movs r0, #0
_0815EFA6:
	cmp r0, #0
	beq _0815EFB4
	adds r0, r7, #0
	mov r1, r8
	bl FUN_08236640
	b _0815EFBC
_0815EFB4:
	adds r0, r7, #0
	mov r1, r8
	bl FUN_08236524
_0815EFBC:
	adds r0, r7, #0
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, r8
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _0815EFF4 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _0815EFF8 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #0x1c]
	cmp r0, #2
	bls _0815EFEA
	cmp r2, #0x17
	bne _0815EFFC
_0815EFEA:
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	b _0815F01C
	.align 2, 0
_0815EFF4: .4byte 0x0000048C
_0815EFF8: .4byte 0x000001DF
_0815EFFC:
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r7, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _0815EFEA
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r4, _0815F04C @ =0x00000187
	adds r0, r6, r4
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0815F01C
	movs r1, #0
_0815F01C:
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
	beq _0815F05A
	mov r1, r8
	ldrh r0, [r1, #0x3e]
	lsls r0, r0, #1
	strh r0, [r1, #0x3e]
	mov r2, sb
	ldrh r0, [r2]
	cmp r0, #0
	blt _0815F050
	asrs r0, r0, #1
	b _0815F056
	.align 2, 0
_0815F04C: .4byte 0x00000187
_0815F050:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0815F056:
	mov r3, sb
	strh r0, [r3]
_0815F05A:
	ldrh r1, [r7, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0815F078
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _0815F074 @ =0x000001DD
	adds r1, r6, r4
	b _0815F0EC
	.align 2, 0
_0815F074: .4byte 0x000001DD
_0815F078:
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
	bne _0815F0D8
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _0815F0D8
	ldr r2, _0815F0C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0815F0CC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0815F0D0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _0815F0D4 @ =0x000001DD
	adds r1, r6, r4
	b _0815F0EC
	.align 2, 0
_0815F0C8: .4byte 0x030046B8
_0815F0CC: .4byte 0x000003FF
_0815F0D0: .4byte 0x0203B400
_0815F0D4: .4byte 0x000001DD
_0815F0D8:
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	ldr r3, _0815F10C @ =0x000001DD
	adds r1, r6, r3
_0815F0EC:
	strb r0, [r1]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0815F114
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0815F110 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0815F182
	.align 2, 0
_0815F10C: .4byte 0x000001DD
_0815F110: .4byte 0x03002BE0
_0815F114:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0815F130
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0815F12C @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0815F182
	.align 2, 0
_0815F12C: .4byte 0x03002BE0
_0815F130:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0815F14C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0815F148 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0815F182
	.align 2, 0
_0815F148: .4byte 0x03002BE0
_0815F14C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0815F168
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0815F164 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0815F182
	.align 2, 0
_0815F164: .4byte 0x03002BE0
_0815F168:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0815F17A
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0815F182
_0815F17A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0815F184
_0815F182:
	movs r3, #1
_0815F184:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	ldr r1, [r7, #0x34]
	ldr r2, [r7, #0x38]
	subs r4, #8
	adds r0, r6, r4
	str r1, [r0]
	ldr r1, _0815F1B4 @ =0x0000049C
	adds r0, r6, r1
	str r2, [r0]
	cmp r3, #0
	beq _0815F21C
	movs r1, #2
	ldr r2, _0815F1B8 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815F1BC
	movs r0, #1
	b _0815F1BE
	.align 2, 0
_0815F1B4: .4byte 0x0000049C
_0815F1B8: .4byte 0x00000474
_0815F1BC:
	movs r0, #0
_0815F1BE:
	cmp r0, #0
	beq _0815F1D8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0815F1D4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0815F1E4
	.align 2, 0
_0815F1D4: .4byte 0x03002BE0
_0815F1D8:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0815F21C
_0815F1E4:
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
_0815F21C:
	ldr r4, [sp, #0x1c]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0815F250
	movs r1, #0x80
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0815F250
	ldr r3, _0815F268 @ =0x0000024E
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
	bls _0815F250
	strh r1, [r2]
_0815F250:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0815F26C @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _0815F270 @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815F274
	movs r0, #1
	b _0815F276
	.align 2, 0
_0815F268: .4byte 0x0000024E
_0815F26C: .4byte 0x030046A0
_0815F270: .4byte 0x00000934
_0815F274:
	movs r0, #0
_0815F276:
	ldr r1, _0815F31C @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _0815F290
	movs r0, #0
	mov r2, r8
	strh r0, [r2, #0x3e]
	mov r3, sb
	strh r0, [r3]
	strh r0, [r4]
	movs r0, #1
	ldr r1, [sp, #0x1c]
	strb r0, [r1]
_0815F290:
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
_0815F2BA:
	ldr r1, _0815F320 @ =0x00000472
	adds r0, r6, r1
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r1, [r1]
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r2, _0815F324 @ =0x0000FFFF
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	add r3, sp, #8
	add r2, sp, #0x10
	adds r4, r7, #0
	adds r4, #0x24
	ldrh r0, [r7, #0x24]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0x80
	lsls r1, r1, #7
	ldr r0, [r7, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _0815F304
	b _0815F490
_0815F304:
	movs r2, #2
	ldr r4, [sp, #0x18]
	movs r0, #0xe0
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _0815F328
	movs r0, #1
	b _0815F32A
	.align 2, 0
_0815F31C: .4byte 0x0000048A
_0815F320: .4byte 0x00000472
_0815F324: .4byte 0x0000FFFF
_0815F328:
	movs r0, #0
_0815F32A:
	cmp r0, #0
	bne _0815F330
	b _0815F490
_0815F330:
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bgt _0815F344
	b _0815F490
_0815F344:
	ldrh r0, [r3, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x78
	rsbs r1, r1, #0
	cmp r0, r1
	ble _0815F354
	b _0815F490
_0815F354:
	movs r2, #0
	movs r1, #0
	mov r3, r8
	strh r1, [r3, #0x3e]
	mov r0, r8
	adds r0, #0x40
	strh r1, [r0]
	adds r0, #4
	strh r1, [r0]
	ldr r3, _0815F38C @ =0x0000048A
	adds r0, r6, r3
	strh r1, [r0]
	ldr r1, _0815F390 @ =0x0000048C
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _0815F394 @ =0x0000025D
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0815F398
	ldr r2, [r6, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _0815F3A6
	.align 2, 0
_0815F38C: .4byte 0x0000048A
_0815F390: .4byte 0x0000048C
_0815F394: .4byte 0x0000025D
_0815F398:
	ldr r0, [r6, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_0815F3A6:
	ldr r3, _0815F3EC @ =0x0000044C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0815F3BA
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r6, r1
	bl FUN_08013698
_0815F3BA:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	bne _0815F490
	movs r2, #0x80
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, [r1]
	ands r0, r2
	str r1, [sp, #0x20]
	cmp r0, #0
	bne _0815F490
	movs r1, #8
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0815F3F0
	movs r0, #1
	b _0815F3F2
	.align 2, 0
_0815F3EC: .4byte 0x0000044C
_0815F3F0:
	movs r0, #0
_0815F3F2:
	cmp r0, #0
	bne _0815F490
	movs r2, #0x80
	movs r4, #0xc1
	lsls r4, r4, #1
	adds r1, r6, r4
	ldrh r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _0815F40C
	movs r0, #1
	b _0815F40E
_0815F40C:
	movs r0, #0
_0815F40E:
	adds r5, r0, #0
	cmp r5, #0
	bne _0815F490
	movs r0, #0x80
	lsls r0, r0, #5
	mov r8, r0
	mov r1, sl
	ldrh r0, [r1]
	mov r2, r8
	ands r0, r2
	cmp r0, #0
	beq _0815F43E
	movs r3, #0x97
	lsls r3, r3, #3
	adds r4, r6, r3
	ldr r0, [r4]
	bl FUN_080f8e3c
	mov r1, sl
	ldrh r0, [r1]
	mov r2, r8
	bics r0, r2
	strh r0, [r1]
	str r5, [r4]
_0815F43E:
	movs r1, #0x80
	ldr r3, [sp, #0x20]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	ldr r4, _0815F4A0 @ =0x00000202
	adds r1, r6, r4
	movs r0, #0xb4
	strh r0, [r1]
	ldr r0, [sp, #0x18]
	ldr r1, _0815F4A4 @ =0x000006F4
	adds r2, r0, r1
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0x80
	lsls r0, r0, #1
	mov r4, sb
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	ldrh r0, [r7, #0x22]
	adds r0, #9
	movs r1, #7
	ands r0, r1
	ldr r2, _0815F4A8 @ =0x000001DD
	adds r1, r6, r2
	strb r0, [r1]
	adds r3, #7
	adds r0, r6, r3
	ldrb r3, [r0]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #1
	bl FUN_080e5718
_0815F490:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815F4A0: .4byte 0x00000202
_0815F4A4: .4byte 0x000006F4
_0815F4A8: .4byte 0x000001DD

	thumb_func_start FUN_0815f4ac
FUN_0815f4ac: @ 0x0815F4AC
	push {r4, lr}
	adds r1, r0, #0
	movs r0, #0x99
	lsls r0, r0, #2
	adds r4, r1, r0
	ldr r0, [r4]
	cmp r0, #0
	beq _0815F4D0
	adds r0, r1, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815F4D0
	ldr r0, [r4]
	bl FUN_081e91d4
	str r0, [r4]
_0815F4D0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0815f4d8
FUN_0815f4d8: @ 0x0815F4D8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xf
	movs r7, #0xbc
	lsls r7, r7, #1
	adds r2, r6, r7
	ldr r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0815F500
	movs r0, #0xc0
	lsls r0, r0, #0xe
	ands r0, r1
	cmp r0, #0
	bne _0815F504
_0815F500:
	movs r0, #0
	b _0815F712
_0815F504:
	movs r0, #0x80
	lsls r0, r0, #1
	orrs r1, r0
	str r1, [r2]
	ldr r0, _0815F550 @ =0x00000482
	adds r1, r6, r0
	movs r3, #0
	movs r4, #0
	movs r2, #1
	movs r0, #1
	strh r0, [r1]
	movs r1, #3
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _0815F554 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r6, r1
	str r4, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r2, [r0]
	movs r1, #2
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815F558
	movs r0, #1
	b _0815F55A
	.align 2, 0
_0815F550: .4byte 0x00000482
_0815F554: .4byte 0x00000469
_0815F558:
	movs r0, #0
_0815F55A:
	adds r5, r0, #0
	cmp r5, #0
	beq _0815F5F4
	adds r0, r6, #0
	movs r1, #0x11
	bl FUN_080ef86c
	ldr r4, _0815F5D8 @ =FUN_080e6834
	movs r3, #0xe
	ldr r7, _0815F5DC @ =0x0000046D
	adds r1, r6, r7
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0815F5E0 @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r6, r7
	movs r5, #0
	strh r2, [r0]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_0815a2a8
	ldr r3, _0815F5E4 @ =FUN_08155878
	movs r4, #3
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r6, r0
	ldr r7, _0815F5E8 @ =0x00000554
	adds r0, r6, r7
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, _0815F5EC @ =0x00000551
	adds r0, r6, r2
	strb r5, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r5, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r2, _0815F5F0 @ =0xFFFFFEFF
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r2, r1, #0
	b _0815F658
	.align 2, 0
_0815F5D8: .4byte FUN_080e6834
_0815F5DC: .4byte 0x0000046D
_0815F5E0: .4byte 0x0000046B
_0815F5E4: .4byte FUN_08155878
_0815F5E8: .4byte 0x00000554
_0815F5EC: .4byte 0x00000551
_0815F5F0: .4byte 0xFFFFFEFF
_0815F5F4:
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r3, _0815F69C @ =FUN_080e6794
	movs r2, #0xe
	ldr r7, _0815F6A0 @ =0x0000046D
	adds r1, r6, r7
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0815F6A4 @ =0x0000046B
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
	movs r4, #0
	strh r5, [r0]
	adds r7, #0x51
	adds r0, r6, r7
	ldr r3, [r0]
	movs r5, #9
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r6, r0
	subs r7, #0x50
	adds r0, r6, r7
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, _0815F6A8 @ =0x00000551
	adds r0, r6, r2
	strb r4, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r5, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r6, r0
_0815F658:
	movs r1, #0x10
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r5, [r0]
	adds r2, r6, #0
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
	blt _0815F698
	cmp r1, #0
	blt _0815F698
	ldr r0, _0815F6AC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815F698
	ldr r0, _0815F6B0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815F6B4
_0815F698:
	movs r4, #0
	b _0815F6C2
	.align 2, 0
_0815F69C: .4byte FUN_080e6794
_0815F6A0: .4byte 0x0000046D
_0815F6A4: .4byte 0x0000046B
_0815F6A8: .4byte 0x00000551
_0815F6AC: .4byte 0x030046A8
_0815F6B0: .4byte 0x030046AC
_0815F6B4:
	ldr r0, _0815F6D4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0815F6C2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815F6D8
	adds r0, #4
	b _0815F6E4
	.align 2, 0
_0815F6D4: .4byte 0x030046A4
_0815F6D8:
	ldr r0, _0815F6F8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815F6E4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0815F6FC
	cmp r2, #2
	beq _0815F700
	b _0815F704
	.align 2, 0
_0815F6F8: .4byte 0x030046A4
_0815F6FC:
	ldrb r0, [r5, #4]
	b _0815F702
_0815F700:
	ldrb r0, [r5]
_0815F702:
	subs r1, r1, r0
_0815F704:
	strh r1, [r5, #2]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
_0815F712:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0815f718
FUN_0815f718: @ 0x0815F718
	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r2, [r0]
	movs r1, #2
	movs r3, #0xe0
	lsls r3, r3, #3
	adds r0, r2, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0815F736
	movs r0, #1
	b _0815F738
_0815F736:
	movs r0, #0
_0815F738:
	cmp r0, #0
	beq _0815F752
	movs r0, #0xd9
	lsls r0, r0, #3
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #0x28
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0815F752
	movs r0, #0
	strh r0, [r1]
_0815F752:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0815f758
FUN_0815f758: @ 0x0815F758
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r5, [r0]
	ldr r4, _0815F888 @ =0x030046B8
	ldr r0, [r4]
	adds r2, r0, #1
	ldr r3, _0815F88C @ =0x000003FF
	ands r2, r3
	str r2, [r4]
	lsls r0, r2, #1
	ldr r6, _0815F890 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldrb r0, [r7, #5]
	subs r1, r3, r0
	cmp r1, #0x80
	ble _0815F794
	ldr r0, _0815F894 @ =0xFFFFFF00
	adds r1, r1, r0
_0815F794:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0815F7A2
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r1, r6
_0815F7A2:
	adds r0, r1, #0
	cmp r0, #0
	bge _0815F7AA
	rsbs r0, r0, #0
_0815F7AA:
	cmp r0, #0x20
	bgt _0815F878
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r1, r7, r0
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r6, r7
	mov ip, r6
	ldr r0, [r6]
	str r0, [r1]
	ldr r0, _0815F898 @ =0x00000553
	adds r0, r0, r7
	mov sl, r0
	ldrb r1, [r0]
	ldr r6, _0815F89C @ =0x0000054F
	adds r0, r7, r6
	strb r1, [r0]
	movs r0, #0x8d
	lsls r0, r0, #3
	adds r0, r0, r7
	mov sb, r0
	ldrb r1, [r0]
	subs r6, #3
	adds r0, r7, r6
	strb r1, [r0]
	ldr r0, _0815F8A0 @ =0x00000469
	adds r0, r0, r7
	mov r8, r0
	ldrb r1, [r0]
	adds r6, #1
	adds r0, r7, r6
	strb r1, [r0]
	ldr r0, _0815F8A4 @ =0x0000046A
	adds r0, r7, r0
	str r0, [sp]
	ldrb r1, [r0]
	adds r6, #1
	adds r0, r7, r6
	strb r1, [r0]
	ldrb r1, [r7, #5]
	ldr r6, _0815F8A8 @ =0x000006BE
	adds r0, r5, r6
	strh r1, [r0]
	asrs r1, r3, #5
	ldr r3, _0815F8AC @ =0x000006BA
	adds r0, r5, r3
	strh r1, [r0]
	adds r0, r2, #1
	ldr r6, _0815F88C @ =0x000003FF
	ands r0, r6
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0815F890 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r4, #3
	ands r1, r4
	adds r1, #1
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	movs r2, #0xd7
	lsls r2, r2, #3
	adds r1, r5, r2
	strh r0, [r1]
	movs r2, #0x2c
	ldr r3, _0815F8B0 @ =0x0000046D
	adds r0, r7, r3
	movs r1, #1
	strb r1, [r0]
	adds r6, #0x6c
	adds r0, r7, r6
	movs r3, #0
	strb r3, [r0]
	mov r6, sl
	strb r2, [r6]
	ldr r0, _0815F8B4 @ =FUN_08156ec4
	mov r2, ip
	str r0, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r6, #0
	strh r6, [r0]
	mov r0, sb
	strb r4, [r0]
	mov r2, r8
	strb r1, [r2]
	ldr r3, [sp]
	strb r6, [r3]
	ldr r2, _0815F8B8 @ =0x00000484
	adds r0, r7, r2
	movs r3, #0
	str r3, [r0]
	ldr r6, _0815F8BC @ =0x0000046C
	adds r0, r7, r6
	strb r1, [r0]
	movs r0, #0xd8
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r0, #4
	strh r0, [r1]
_0815F878:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815F888: .4byte 0x030046B8
_0815F88C: .4byte 0x000003FF
_0815F890: .4byte 0x0203B400
_0815F894: .4byte 0xFFFFFF00
_0815F898: .4byte 0x00000553
_0815F89C: .4byte 0x0000054F
_0815F8A0: .4byte 0x00000469
_0815F8A4: .4byte 0x0000046A
_0815F8A8: .4byte 0x000006BE
_0815F8AC: .4byte 0x000006BA
_0815F8B0: .4byte 0x0000046D
_0815F8B4: .4byte FUN_08156ec4
_0815F8B8: .4byte 0x00000484
_0815F8BC: .4byte 0x0000046C

	thumb_func_start FUN_0815f8c0
FUN_0815f8c0: @ 0x0815F8C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x7c
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sl, r0
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r6, _0815F910 @ =0x00008004
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r5, r7, r2
	ldrh r3, [r5]
	adds r2, r3, #0
	ands r6, r2
	cmp r6, #0
	beq _0815F914
	movs r3, #0x99
	lsls r3, r3, #2
	adds r4, r7, r3
_0815F8F8:
	ldr r0, [r4]
	bl FUN_081e91d4
	str r0, [r4]
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	bl _081604B8
	.align 2, 0
_0815F910: .4byte 0x00008004
_0815F914:
	ldr r4, _0815FA70 @ =0x0000049C
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r1
	cmp r0, #0
	bne _0815F926
	b _0815FAB4
_0815F926:
	movs r0, #4
	movs r1, #0
	mov r8, r1
	orrs r0, r3
	ldr r1, _0815FA74 @ =0xFFFFE854
	ands r0, r1
	strh r0, [r5]
	ldr r2, _0815FA78 @ =0x00000482
	adds r1, r7, r2
	movs r0, #1
	strh r0, [r1]
	ldr r3, _0815FA7C @ =0x00000222
	adds r0, r7, r3
	strh r6, [r0]
	ldr r4, _0815FA80 @ =0x0000024E
	adds r0, r7, r4
	strh r6, [r0]
	ldr r0, _0815FA84 @ =0xFFFFFC7F
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r1, _0815FA88 @ =0xF3FFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r1, r1, r7
	mov sb, r1
	cmp r0, #0
	beq _0815F996
	ldr r1, _0815FA8C @ =0xFEFFFFFF
	mov r3, sb
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	ldr r0, _0815FA90 @ =0xFFFFFDFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	subs r4, #0x32
	adds r0, r7, r4
	mov r1, r8
	strb r1, [r0]
	ldr r3, _0815FA94 @ =0x0000021E
	adds r0, r7, r3
	strh r6, [r0]
	subs r4, #0x1a
	adds r0, r7, r4
	strh r6, [r0]
_0815F996:
	ldr r0, _0815FA98 @ =0xFFFFFBFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	ldr r0, _0815FA9C @ =0x00000542
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x99
	lsls r1, r1, #2
	adds r4, r7, r1
	ldr r0, [r4]
	bl FUN_081e91d4
	str r0, [r4]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r2, _0815FAA0 @ =FUN_08154788
	movs r1, #0x2e
	ldr r3, _0815FAA4 @ =0x0000046D
	adds r0, r7, r3
	movs r4, #1
	strb r4, [r0]
	subs r3, #2
	adds r0, r7, r3
	mov r4, r8
	strb r4, [r0]
	adds r3, #0xe8
	adds r0, r7, r3
	strb r1, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r7, r4
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r6, [r0]
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r1, [r0]
	subs r3, #0xea
	adds r0, r7, r3
	mov r4, r8
	strb r4, [r0]
	ldr r1, _0815FAA8 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	adds r2, #0x1c
	adds r0, r7, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r7, r3
	movs r4, #1
	strb r4, [r0]
	ldr r0, _0815FAAC @ =0x000006DC
	add r0, sl
	strh r6, [r0]
	movs r2, #0xe0
	lsls r2, r2, #3
	add r2, sl
	ldr r1, _0815FAB0 @ =0xFFFFFF00
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
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
	movs r1, #3
	rsbs r1, r1, #0
	mov r6, sb
	ldr r0, [r6]
	ands r0, r1
	ldr r1, _0815FA8C @ =0xFEFFFFFF
	ands r0, r1
	str r0, [r6]
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r0, #1
	bl _081604BA
	.align 2, 0
_0815FA70: .4byte 0x0000049C
_0815FA74: .4byte 0xFFFFE854
_0815FA78: .4byte 0x00000482
_0815FA7C: .4byte 0x00000222
_0815FA80: .4byte 0x0000024E
_0815FA84: .4byte 0xFFFFFC7F
_0815FA88: .4byte 0xF3FFFFFF
_0815FA8C: .4byte 0xFEFFFFFF
_0815FA90: .4byte 0xFFFFFDFF
_0815FA94: .4byte 0x0000021E
_0815FA98: .4byte 0xFFFFFBFF
_0815FA9C: .4byte 0x00000542
_0815FAA0: .4byte FUN_08154788
_0815FAA4: .4byte 0x0000046D
_0815FAA8: .4byte 0x0000046A
_0815FAAC: .4byte 0x000006DC
_0815FAB0: .4byte 0xFFFFFF00
_0815FAB4:
	movs r4, #2
	adds r0, r2, #0
	ands r0, r4
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	beq _0815FACA
	movs r0, #0x99
	lsls r0, r0, #2
	adds r4, r7, r0
	b _0815F8F8
_0815FACA:
	movs r0, #0xc0
	lsls r0, r0, #0xc
	ands r1, r0
	cmp r1, #0
	beq _0815FB7C
	movs r1, #0x99
	lsls r1, r1, #2
	adds r4, r7, r1
	ldr r0, [r4]
	bl FUN_081e91d4
	str r0, [r4]
	ldr r2, _0815FB58 @ =0x000005CC
	adds r0, r7, r2
	ldr r2, [r0]
	movs r1, #0x12
	ldr r3, _0815FB5C @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r4, _0815FB60 @ =0x0000046B
	adds r0, r7, r4
	strb r6, [r0]
	ldr r5, _0815FB64 @ =0x00000553
	adds r0, r7, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r2, #0
	strh r6, [r0]
	movs r1, #3
	subs r4, #3
	adds r0, r7, r4
	strb r1, [r0]
	subs r5, #0xea
	adds r0, r7, r5
	strb r2, [r0]
	ldr r1, _0815FB68 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _0815FB6C @ =0x00000484
	adds r0, r7, r2
	str r6, [r0]
	adds r4, #4
	adds r0, r7, r4
	strb r3, [r0]
	ldr r0, _0815FB70 @ =0x000006DC
	add r0, sl
	strh r6, [r0]
	movs r2, #0xe0
	lsls r2, r2, #3
	add r2, sl
	ldr r1, _0815FB74 @ =0xFFFFFF00
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r1, _0815FB78 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #1
	bl _081604BA
	.align 2, 0
_0815FB58: .4byte 0x000005CC
_0815FB5C: .4byte 0x0000046D
_0815FB60: .4byte 0x0000046B
_0815FB64: .4byte 0x00000553
_0815FB68: .4byte 0x0000046A
_0815FB6C: .4byte 0x00000484
_0815FB70: .4byte 0x000006DC
_0815FB74: .4byte 0xFFFFFF00
_0815FB78: .4byte 0xFEFFFFFF
_0815FB7C:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r2, r0
	cmp r2, #0
	bne _0815FB90
	ldr r6, _0815FB9C @ =0x000004BE
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r0, #0
	beq _0815FBA0
_0815FB90:
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r3
	strh r0, [r5]
	bl _081604B8
	.align 2, 0
_0815FB9C: .4byte 0x000004BE
_0815FBA0:
	movs r1, #0xe0
	lsls r1, r1, #3
	add r1, sl
	ldr r0, [r1]
	ands r0, r4
	adds r6, r1, #0
	cmp r0, #0
	beq _0815FBB4
	movs r0, #1
	b _0815FBB6
_0815FBB4:
	movs r0, #0
_0815FBB6:
	cmp r0, #0
	beq _0815FC68
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r4, r7, r0
	ldr r1, _0815FC48 @ =0xFFFFF636
	ldrh r0, [r4]
	ands r1, r0
	movs r2, #0
	movs r3, #0
	strh r1, [r4]
	ldr r1, _0815FC4C @ =0x000005CC
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	movs r1, #0x12
	ldr r4, _0815FC50 @ =0x0000046D
	adds r0, r7, r4
	movs r5, #1
	strb r5, [r0]
	subs r4, #2
	adds r0, r7, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r7, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r4, r8
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r3, [r0]
	movs r1, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r7, r4
	strb r1, [r0]
	ldr r1, _0815FC54 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	adds r4, #2
	adds r0, r7, r4
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r7, r1
	str r3, [r0]
	ldr r2, _0815FC58 @ =0x0000046C
	adds r0, r7, r2
	strb r5, [r0]
	ldr r0, _0815FC5C @ =0x000006DC
	add r0, sl
	strh r3, [r0]
	ldr r1, _0815FC60 @ =0xFFFFFF00
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r1, _0815FC64 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_0815c05c
	movs r0, #1
	bl _081604BA
	.align 2, 0
_0815FC48: .4byte 0xFFFFF636
_0815FC4C: .4byte 0x000005CC
_0815FC50: .4byte 0x0000046D
_0815FC54: .4byte 0x00000469
_0815FC58: .4byte 0x0000046C
_0815FC5C: .4byte 0x000006DC
_0815FC60: .4byte 0xFFFFFF00
_0815FC64: .4byte 0xFEFFFFFF
_0815FC68:
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r5, _0815FD40 @ =0x0000048D
	adds r3, r7, r5
	ldrb r0, [r3]
	str r2, [sp, #0x48]
	cmp r0, #0
	bne _0815FCA6
	ldr r1, _0815FD44 @ =0x0000048C
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0815FCA6
	ldr r2, _0815FD48 @ =0x000004BE
	adds r0, r7, r2
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r3]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_0815FCA6:
	ldr r3, _0815FD4C @ =0x00000544
	adds r1, r7, r3
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r5, #0x80
	ldr r4, [sp, #0x48]
	ldrh r0, [r4]
	ands r0, r5
	cmp r0, #0
	bne _0815FCBE
	b _08160428
_0815FCBE:
	movs r6, #0x99
	lsls r6, r6, #2
	adds r4, r7, r6
	ldr r0, [r4]
	bl FUN_081e91d4
	str r0, [r4]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r2]
	cmp r0, #0
	bne _0815FCDC
	bl _081604B8
_0815FCDC:
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	movs r0, #4
	ldr r4, _0815FD50 @ =0x00000222
	adds r3, r7, r4
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _0815FD54 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r2]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r4, r7, r5
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
	str r3, [sp, #0x50]
	str r4, [sp, #0x74]
	str r2, [sp, #0x24]
	cmp r5, #0
	blt _0815FD3A
	cmp r1, #0
	blt _0815FD3A
	ldr r0, _0815FD58 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0815FD3A
	ldr r0, _0815FD5C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815FD60
_0815FD3A:
	movs r4, #0
	b _0815FD6E
	.align 2, 0
_0815FD40: .4byte 0x0000048D
_0815FD44: .4byte 0x0000048C
_0815FD48: .4byte 0x000004BE
_0815FD4C: .4byte 0x00000544
_0815FD50: .4byte 0x00000222
_0815FD54: .4byte 0x03002BE0
_0815FD58: .4byte 0x030046A8
_0815FD5C: .4byte 0x030046AC
_0815FD60:
	ldr r0, _0815FD80 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0815FD6E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815FD84
	adds r0, #4
	b _0815FD90
	.align 2, 0
_0815FD80: .4byte 0x030046A4
_0815FD84:
	ldr r0, _0815FDA4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815FD90:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0815FDA8
	cmp r2, #2
	beq _0815FDAC
	b _0815FDB0
	.align 2, 0
_0815FDA4: .4byte 0x030046A4
_0815FDA8:
	ldrb r0, [r6, #4]
	b _0815FDAE
_0815FDAC:
	ldrb r0, [r6]
_0815FDAE:
	subs r1, r1, r0
_0815FDB0:
	strh r1, [r6, #2]
	ldr r0, _0815FDC4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0815FDC8
	movs r0, #1
	b _0815FDCA
	.align 2, 0
_0815FDC4: .4byte 0x030047A4
_0815FDC8:
	movs r0, #0
_0815FDCA:
	cmp r0, #0
	beq _0815FE08
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _0815FDEA
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0815FDE6
	adds r2, r0, #0
_0815FDE6:
	cmp r2, #0
	bge _0815FDF4
_0815FDEA:
	ldr r1, _0815FDF0 @ =0x000005C4
	adds r0, r7, r1
	b _08160324
	.align 2, 0
_0815FDF0: .4byte 0x000005C4
_0815FDF4:
	ldr r1, _0815FE04 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0815FE50
	.align 2, 0
_0815FE04: .4byte 0x03002BE0
_0815FE08:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0815FE34
	cmp r1, #0
	blt _0815FE34
	ldr r0, _0815FE38 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815FE34
	ldr r0, _0815FE3C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0815FE40
_0815FE34:
	movs r5, #0
	b _0815FE4E
	.align 2, 0
_0815FE38: .4byte 0x030046A8
_0815FE3C: .4byte 0x030046AC
_0815FE40:
	ldr r0, _0815FE88 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0815FE4E:
	movs r2, #0
_0815FE50:
	ldr r3, _0815FE8C @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _0815FE70
	ldr r1, _0815FE90 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0815FE70
	b _08160264
_0815FE70:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x48]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _0815FE94
	movs r0, #0
	b _0816033A
	.align 2, 0
_0815FE88: .4byte 0x030046A4
_0815FE8C: .4byte 0x00000256
_0815FE90: .4byte 0x03002BE0
_0815FE94:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r5, [sp, #0x50]
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r1, #0x80
	ldr r6, [sp, #0x48]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _0815FF4C
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _0815FF30 @ =0x0000046D
	adds r2, r2, r7
	mov sl, r2
	movs r3, #1
	strb r3, [r2]
	ldr r4, _0815FF34 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #8]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _0815FF38 @ =0x00000553
	adds r6, r6, r7
	mov r8, r6
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x78]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	mov r2, sb
	strh r2, [r5]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _0815FF3C @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _0815FF40 @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _0815FF44 @ =0x00000484
	adds r1, r7, r0
	mov r6, sb
	str r6, [r1]
	ldr r6, _0815FF48 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	mov r6, sl
	str r6, [sp, #0x68]
	ldr r6, [sp, #8]
	str r6, [sp, #0x60]
	mov r6, r8
	str r6, [sp, #0x3c]
	ldr r6, [sp, #0x78]
	str r6, [sp, #0x40]
	str r5, [sp, #0x4c]
	str r4, [sp, #0x54]
	str r3, [sp, #0x58]
	str r2, [sp, #0x5c]
	str r1, [sp, #0x70]
	str r0, [sp, #0x64]
	b _0816011A
	.align 2, 0
_0815FF30: .4byte 0x0000046D
_0815FF34: .4byte 0x0000046B
_0815FF38: .4byte 0x00000553
_0815FF3C: .4byte 0x00000469
_0815FF40: .4byte 0x0000046A
_0815FF44: .4byte 0x00000484
_0815FF48: .4byte 0x0000046C
_0815FF4C:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, _0816000C @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0xc]
	strb r0, [r3]
	ldr r4, _08160010 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x10]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _08160014 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x14]
	strb r0, [r6]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x18]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r4, r7
	mov r8, r4
	strh r2, [r4]
	movs r1, #5
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x78]
	movs r6, #0
	strb r6, [r5]
	ldr r3, _08160018 @ =0x00000469
	adds r5, r7, r3
	strb r6, [r5]
	ldr r6, _0816001C @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _08160020 @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x74]
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	ldr r1, [sp, #0x24]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x1c]
	strh r1, [r6]
	ldr r6, [sp, #0x24]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x1c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x68]
	ldr r6, [sp, #0x10]
	str r6, [sp, #0x60]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x3c]
	ldr r6, [sp, #0x18]
	str r6, [sp, #0x40]
	mov r0, r8
	str r0, [sp, #0x4c]
	ldr r6, [sp, #0x78]
	str r6, [sp, #0x54]
	str r5, [sp, #0x58]
	str r4, [sp, #0x5c]
	str r3, [sp, #0x70]
	str r2, [sp, #0x64]
	mov r0, ip
	cmp r0, #0
	blt _08160008
	cmp r1, #0
	blt _08160008
	ldr r0, _08160024 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _08160008
	ldr r0, _08160028 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0816002C
_08160008:
	movs r4, #0
	b _0816003C
	.align 2, 0
_0816000C: .4byte 0x0000046D
_08160010: .4byte 0x0000046B
_08160014: .4byte 0x00000553
_08160018: .4byte 0x00000469
_0816001C: .4byte 0x0000046A
_08160020: .4byte 0x00000484
_08160024: .4byte 0x030046A8
_08160028: .4byte 0x030046AC
_0816002C:
	ldr r0, _0816004C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_0816003C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08160050
	adds r0, #4
	b _0816005C
	.align 2, 0
_0816004C: .4byte 0x030046A4
_08160050:
	ldr r0, _08160070 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0816005C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08160074
	cmp r2, #2
	beq _0816007A
	b _08160080
	.align 2, 0
_08160070: .4byte 0x030046A4
_08160074:
	ldr r2, [sp, #0x1c]
	ldrb r0, [r2, #4]
	b _0816007E
_0816007A:
	ldr r3, [sp, #0x1c]
	ldrb r0, [r3]
_0816007E:
	subs r1, r1, r0
_08160080:
	ldr r4, [sp, #0x1c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x74]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081600AC
	cmp r1, #0
	blt _081600AC
	ldr r0, _081600B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081600AC
	ldr r0, _081600B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081600B8
_081600AC:
	movs r4, #0
	b _081600C6
	.align 2, 0
_081600B0: .4byte 0x030046A8
_081600B4: .4byte 0x030046AC
_081600B8:
	ldr r0, _081600DC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081600C6:
	ldr r6, [sp, #0x74]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081600E0
	adds r0, #4
	b _081600EC
	.align 2, 0
_081600DC: .4byte 0x030046A4
_081600E0:
	ldr r0, _08160100 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081600EC:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08160104
	cmp r3, #2
	beq _08160108
	b _0816010C
	.align 2, 0
_08160100: .4byte 0x030046A4
_08160104:
	ldrb r0, [r5, #4]
	b _0816010A
_08160108:
	ldrb r0, [r5]
_0816010A:
	subs r2, r2, r0
_0816010C:
	ldr r1, [sp, #0x74]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x74]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0816011A:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x20]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x48]
	ldrh r0, [r4]
	ands r0, r1
	ldr r5, _08160144 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x6c]
	mov sb, r3
	cmp r0, #0
	bne _08160228
	movs r1, #4
	ldr r6, [sp, #0x50]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08160148
	movs r0, #1
	b _0816014A
	.align 2, 0
_08160144: .4byte 0x00000482
_08160148:
	movs r0, #0
_0816014A:
	ldr r1, _08160238 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x6c]
	cmp r0, #0
	bne _08160228
	movs r3, #0
	ldr r2, _0816023C @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r6, _08160240 @ =0x0000054F
	adds r6, r6, r7
	mov ip, r6
	ldr r0, _08160244 @ =0x0000054C
	adds r0, r7, r0
	str r0, [sp, #0x30]
	ldr r1, _08160248 @ =0x0000054D
	adds r1, r7, r1
	str r1, [sp, #0x34]
	ldr r2, _0816024C @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0x38]
	ldr r4, _08160250 @ =0x00000541
	adds r4, r7, r4
	str r4, [sp, #0x28]
	ldr r5, _08160254 @ =0x000005BC
	adds r5, r7, r5
	str r5, [sp, #0x44]
	ldr r6, _08160258 @ =0x0203B400
	ldr r1, _0816025C @ =0x030046B8
	ldr r5, _08160260 @ =0x000003FF
	movs r4, #3
	mov r2, sb
_0816019A:
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
	bne _081601B8
	adds r3, #1
	cmp r3, #3
	ble _0816019A
	mov r0, sb
_081601B8:
	movs r3, #0
	mov r6, r8
	strb r0, [r6]
	ldr r1, [sp, #0x40]
	ldr r0, [r1]
	mov r2, sl
	str r0, [r2]
	ldr r4, [sp, #0x3c]
	ldrb r0, [r4]
	mov r5, ip
	strb r0, [r5]
	ldr r6, [sp, #0x54]
	ldrb r0, [r6]
	ldr r1, [sp, #0x30]
	strb r0, [r1]
	ldr r2, [sp, #0x58]
	ldrb r0, [r2]
	ldr r4, [sp, #0x34]
	strb r0, [r4]
	ldr r5, [sp, #0x5c]
	ldrb r0, [r5]
	ldr r6, [sp, #0x38]
	strb r0, [r6]
	add r0, sp, #0x20
	ldrb r1, [r0]
	ldr r0, [sp, #0x28]
	strb r1, [r0]
	ldr r1, [sp, #0x44]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x68]
	strb r1, [r4]
	ldr r5, [sp, #0x60]
	strb r3, [r5]
	ldr r6, [sp, #0x3c]
	strb r0, [r6]
	ldr r0, [sp, #0x40]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x4c]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x54]
	strb r0, [r5]
	ldr r6, [sp, #0x58]
	strb r1, [r6]
	ldr r0, [sp, #0x5c]
	strb r2, [r0]
	ldr r2, [sp, #0x70]
	str r3, [r2]
	ldr r3, [sp, #0x64]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x2c]
	strb r0, [r4]
_08160228:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x6c]
	strh r0, [r5]
	movs r0, #0
	b _0816033A
	.align 2, 0
_08160238: .4byte 0x00000482
_0816023C: .4byte 0x00000542
_08160240: .4byte 0x0000054F
_08160244: .4byte 0x0000054C
_08160248: .4byte 0x0000054D
_0816024C: .4byte 0x0000054E
_08160250: .4byte 0x00000541
_08160254: .4byte 0x000005BC
_08160258: .4byte 0x0203B400
_0816025C: .4byte 0x030046B8
_08160260: .4byte 0x000003FF
_08160264:
	mov sb, sp
	ldr r6, _081602A0 @ =0x030046A4
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
	beq _081602A4
	adds r0, #4
	b _081602AE
	.align 2, 0
_081602A0: .4byte 0x030046A4
_081602A4:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081602AE:
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
	ldr r6, _081602E8 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081602F0
	ldr r0, _081602EC @ =0xFFFFFDFF
	ldr r2, [sp, #0x48]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0816031A
	.align 2, 0
_081602E8: .4byte 0x000004A4
_081602EC: .4byte 0xFFFFFDFF
_081602F0:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08160310
	cmp r0, #2
	beq _0816030C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0816030C:
	movs r0, #1
	b _0816031C
_08160310:
	ldr r0, _08160330 @ =0xFFFFFDFF
	ldr r3, [sp, #0x48]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0816031A:
	movs r0, #0
_0816031C:
	cmp r0, #0
	bne _08160338
	ldr r4, _08160334 @ =0x000005C4
	adds r0, r7, r4
_08160324:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0816033A
	.align 2, 0
_08160330: .4byte 0xFFFFFDFF
_08160334: .4byte 0x000005C4
_08160338:
	movs r0, #1
_0816033A:
	cmp r0, #0
	bne _081603C0
	ldr r5, _08160370 @ =0x000004A4
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
	bne _08160378
	ldr r0, _08160374 @ =0xFFFFFDFF
	ldr r2, [sp, #0x48]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081603A2
	.align 2, 0
_08160370: .4byte 0x000004A4
_08160374: .4byte 0xFFFFFDFF
_08160378:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08160398
	cmp r0, #2
	beq _08160394
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08160394:
	movs r0, #1
	b _081603A4
_08160398:
	ldr r0, _081603B8 @ =0xFFFFFDFF
	ldr r3, [sp, #0x48]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081603A2:
	movs r0, #0
_081603A4:
	cmp r0, #0
	bne _081603C0
	ldr r4, _081603BC @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081604B8
	.align 2, 0
_081603B8: .4byte 0xFFFFFDFF
_081603BC: .4byte 0x000005C4
_081603C0:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _08160418 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _0816041C @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	adds r6, #0xe6
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
	ldr r1, _08160420 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _08160424 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	movs r0, #1
	b _081604BA
	.align 2, 0
_08160418: .4byte 0x0000046D
_0816041C: .4byte 0x0000046B
_08160420: .4byte 0x0000046A
_08160424: .4byte 0x00000484
_08160428:
	movs r1, #0x20
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08160436
	movs r0, #1
	b _08160438
_08160436:
	movs r0, #0
_08160438:
	adds r5, r0, #0
	cmp r5, #0
	bne _081604B8
	movs r6, #0x99
	lsls r6, r6, #2
	adds r4, r7, r6
	ldr r0, [r4]
	bl FUN_081e91d4
	str r0, [r4]
	adds r0, r7, #0
	bl FUN_0815c05c
	ldr r2, _081604A0 @ =FUN_081562dc
	movs r1, #0x34
	ldr r3, _081604A4 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r4, _081604A8 @ =0x0000046B
	adds r0, r7, r4
	strb r5, [r0]
	ldr r6, _081604AC @ =0x00000553
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r1, #0
	strh r5, [r0]
	movs r2, #0x13
	subs r4, #3
	adds r0, r7, r4
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081604B0 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _081604B4 @ =0x00000484
	adds r0, r7, r2
	str r5, [r0]
	adds r4, #4
	adds r0, r7, r4
	strb r3, [r0]
	movs r0, #1
	b _081604BA
	.align 2, 0
_081604A0: .4byte FUN_081562dc
_081604A4: .4byte 0x0000046D
_081604A8: .4byte 0x0000046B
_081604AC: .4byte 0x00000553
_081604B0: .4byte 0x0000046A
_081604B4: .4byte 0x00000484
_081604B8:
	movs r0, #0
_081604BA:
	add sp, #0x7c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081604cc
FUN_081604cc: @ 0x081604CC
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r2, #0
	movs r1, #4
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081604EC
	ldr r1, _08160520 @ =0x000004BE
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08160518
_081604EC:
	adds r0, r4, #0
	bl FUN_08157458
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrb r0, [r0]
	ldr r3, _08160524 @ =0x0000062C
	adds r1, r4, r3
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e4964
	adds r0, r4, #0
	bl FUN_08157490
_08160518:
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08160520: .4byte 0x000004BE
_08160524: .4byte 0x0000062C

	thumb_func_start FUN_08160528
FUN_08160528: @ 0x08160528
	push {lr}
	bl FUN_080f06b0
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start EnemyCockatrice_Destroy
EnemyCockatrice_Destroy: @ 0x08160534
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r4, r1
	bl FUN_08236424
	ldr r2, _08160554 @ =0x0000025D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08160558
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _08160560
	.align 2, 0
_08160554: .4byte 0x0000025D
_08160558:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_08160560:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _0816057C @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _08160580
	movs r0, #1
	b _08160582
	.align 2, 0
_0816057C: .4byte 0x00000474
_08160580:
	movs r0, #0
_08160582:
	cmp r0, #0
	beq _0816058E
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_0816058E:
	ldr r1, _081605E8 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _081605A6
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_081605A6:
	ldr r0, _081605EC @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _081605BE
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_081605BE:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081605D6
	adds r0, r4, #0
	bl FUN_08002a58
_081605D6:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081605F0
	movs r0, #1
	b _081605F2
	.align 2, 0
_081605E8: .4byte 0x0000044C
_081605EC: .4byte 0x0000044D
_081605F0:
	movs r0, #0
_081605F2:
	cmp r0, #0
	beq _081605FE
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_081605FE:
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

	thumb_func_start EnemyCockatrice_Init
EnemyCockatrice_Init: @ 0x0816061C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1ac
	adds r7, r0, #0
	str r7, [sp, #0x24]
	movs r1, #0xe0
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r6, #0
	str r6, [r0]
	movs r2, #0xd7
	lsls r2, r2, #3
	adds r1, r7, r2
	movs r0, #0x78
	strh r0, [r1]
	ldr r2, _081606E0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081606E4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081606E8 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	ldr r4, _081606EC @ =0x000006BC
	adds r1, r7, r4
	strh r0, [r1]
	movs r5, #0xd8
	lsls r5, r5, #3
	adds r0, r7, r5
	strh r6, [r0]
	ldr r1, _081606F0 @ =0x000006BE
	adds r0, r7, r1
	strh r6, [r0]
	ldr r2, _081606F4 @ =0x000006E4
	adds r0, r7, r2
	strh r6, [r0]
	ldr r3, _081606F8 @ =0x000006E2
	adds r0, r7, r3
	strh r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	adds r0, r7, #0
	bl FUN_081598a4
	ldr r4, _081606FC @ =0x0000025D
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0816070C
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _08160700 @ =0x000041CF
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _08160704 @ =0x0000DA5E
	bl FUN_080e3804
	ldr r6, _08160708 @ =0x000001DF
	adds r0, r7, r6
	ldrb r1, [r0]
	str r0, [sp, #0x9c]
	cmp r1, #0x11
	beq _081606D0
	cmp r1, #0x17
	bne _081606D4
_081606D0:
	movs r0, #1
	strb r0, [r5, #7]
_081606D4:
	movs r0, #0xef
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
	b _08160772
	.align 2, 0
_081606E0: .4byte 0x030046B8
_081606E4: .4byte 0x000003FF
_081606E8: .4byte 0x0203B400
_081606EC: .4byte 0x000006BC
_081606F0: .4byte 0x000006BE
_081606F4: .4byte 0x000006E4
_081606F8: .4byte 0x000006E2
_081606FC: .4byte 0x0000025D
_08160700: .4byte 0x000041CF
_08160704: .4byte 0x0000DA5E
_08160708: .4byte 0x000001DF
_0816070C:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r1, sp, #0x14
	mov r8, r1
	str r6, [sp, #0x10]
	add r0, sp, #0x10
	ldr r2, _081607F0 @ =0x05000002
	bl CpuSet
	ldr r0, _081607F4 @ =0x0000CB05
	ldr r1, _081607F8 @ =0x000041CF
	bl GetFile
	adds r1, r0, #0
	adds r2, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	adds r0, r4, #0
	bl OpenSpriteSetFile
	adds r0, r4, #0
	adds r0, #0x20
	movs r1, #2
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r6, r8
	str r6, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	ldr r0, _081607FC @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _08160800 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0x9c]
_08160772:
	str r7, [sp, #0x28]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sb, r2
	movs r4, #0
	str r4, [r2]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r3, r3, r7
	mov r8, r3
	str r4, [r3]
	ldr r5, _08160804 @ =0x0000046F
	adds r0, r7, r5
	strb r4, [r0]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r0, #0
	mov sl, r0
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, _08160808 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _081607F0 @ =0x05000002
	bl CpuSet
	ldr r3, _0816080C @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1a8]
	bl VM_SeekToKeyword
	mov r1, sb
	str r1, [sp, #0x78]
	mov r3, r8
	str r3, [sp, #0x7c]
	str r6, [sp, #0x4c]
	ldr r2, [sp, #0x1a8]
	adds r6, r2, #0
	cmp r0, #0
	bne _081607DE
	b _08160940
_081607DE:
	bl VM_GetPC
	cmp r0, #0
	beq _08160810
	bl Script_GetValue
	adds r1, r0, #0
	b _08160812
	.align 2, 0
_081607F0: .4byte 0x05000002
_081607F4: .4byte 0x0000CB05
_081607F8: .4byte 0x000041CF
_081607FC: .4byte 0x000004B7
_08160800: .4byte 0x000001DF
_08160804: .4byte 0x0000046F
_08160808: .4byte 0x00000474
_0816080C: .4byte 0x000004B6
_08160810:
	movs r1, #0
_08160812:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _08160838 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x120]
	str r4, [sp, #0x124]
	cmp r0, #0
	beq _0816083C
	bl Script_GetValue
	adds r1, r0, #0
	b _0816083E
	.align 2, 0
_08160838: .4byte 0x00000251
_0816083C:
	movs r1, #0
_0816083E:
	ldr r2, _08160874 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _08160878 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0x120]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0x12c]
	cmp r0, #0
	beq _0816087C
	bl Script_GetValue
	b _08160880
	.align 2, 0
_08160874: .4byte 0x00000252
_08160878: .4byte 0x000004B4
_0816087C:
	ldr r4, [sp, #0x120]
	ldrb r0, [r4]
_08160880:
	strb r0, [r6]
	ldr r5, [sp, #0x120]
	ldrb r1, [r5]
	ldr r6, [sp, #0x12c]
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
	blt _081608B8
	cmp r1, #0
	blt _081608B8
	ldr r0, _081608BC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081608B8
	ldr r0, _081608C0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081608C4
_081608B8:
	movs r1, #0
	b _081608D2
	.align 2, 0
_081608BC: .4byte 0x030046A8
_081608C0: .4byte 0x030046AC
_081608C4:
	ldr r0, _081608EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081608D2:
	ldr r2, _081608F0 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081608F4
	adds r0, #4
	b _08160900
	.align 2, 0
_081608EC: .4byte 0x030046A4
_081608F0: .4byte 0x00000256
_081608F4:
	ldr r0, _08160914 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08160900:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08160918
	cmp r2, #2
	beq _0816091C
	b _08160920
	.align 2, 0
_08160914: .4byte 0x030046A4
_08160918:
	ldrb r0, [r4, #4]
	b _0816091E
_0816091C:
	ldrb r0, [r4]
_0816091E:
	subs r1, r1, r0
_08160920:
	ldr r3, _08160938 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _0816093C @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _08160980
	.align 2, 0
_08160938: .4byte 0x00000472
_0816093C: .4byte 0x0000FFFF
_08160940:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _081609A4 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _081609A8 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _081609AC @ =0x000004B4
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
	str r5, [sp, #0x120]
	str r4, [sp, #0x124]
	str r3, [sp, #0x12c]
_08160980:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081609CA
	bl VM_GetPC
	cmp r0, #0
	beq _081609B0
	bl Script_GetValue
	adds r4, r0, #0
	b _081609B2
	.align 2, 0
_081609A4: .4byte 0x00000251
_081609A8: .4byte 0x00000252
_081609AC: .4byte 0x000004B4
_081609B0:
	movs r4, #0x30
_081609B2:
	bl VM_GetPC
	cmp r0, #0
	beq _081609C4
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _081609C6
_081609C4:
	movs r5, #0x40
_081609C6:
	mov r8, r4
	b _081609D0
_081609CA:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_081609D0:
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08160A08
	bl VM_GetPC
	cmp r0, #0
	beq _081609EA
	bl Script_GetValue
	adds r6, r0, #0
	b _081609EC
_081609EA:
	movs r6, #0
_081609EC:
	bl VM_GetPC
	cmp r0, #0
	beq _081609FC
	bl Script_GetValue
	adds r1, r0, #0
	b _081609FE
_081609FC:
	movs r1, #0
_081609FE:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _08160A12
_08160A08:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_08160A12:
	movs r0, #0x61
	bl VM_SeekToKeyword
	ldr r1, _08160C98 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x138]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x118]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x84]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x80]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x130]
	lsls r4, r4, #0x10
	str r4, [sp, #0xd4]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0xe4]
	lsls r6, r6, #0x10
	str r6, [sp, #0xec]
	lsls r5, r5, #0x10
	str r5, [sp, #0xe0]
	ldr r4, _08160C9C @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x134]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0xcc]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x34]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xa0]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x38]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x3c]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x30]
	movs r6, #0xe6
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x94]
	movs r1, #0x90
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x64]
	ldr r2, _08160CA0 @ =0x0000047A
	adds r2, r7, r2
	str r2, [sp, #0x58]
	ldr r3, _08160CA4 @ =0x0000047C
	adds r3, r7, r3
	str r3, [sp, #0x5c]
	ldr r4, _08160CA8 @ =0x0000047E
	adds r4, r7, r4
	str r4, [sp, #0x60]
	ldr r5, _08160CAC @ =0x00000476
	adds r5, r7, r5
	str r5, [sp, #0x50]
	movs r6, #0x8f
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x54]
	ldr r1, _08160CB0 @ =0x000004A4
	adds r1, r7, r1
	str r1, [sp, #0x70]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x74]
	movs r3, #0xb0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xf4]
	movs r4, #0xb1
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xfc]
	movs r5, #0xb2
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x104]
	movs r6, #0xb4
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x114]
	ldr r1, _08160CB4 @ =0x000005A4
	adds r1, r7, r1
	str r1, [sp, #0x11c]
	movs r2, #0xb8
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x148]
	ldr r3, _08160CB8 @ =0x000005C4
	adds r3, r7, r3
	str r3, [sp, #0x14c]
	ldr r4, _08160CBC @ =0x000005CC
	adds r4, r7, r4
	str r4, [sp, #0x154]
	movs r5, #0xba
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x158]
	ldr r6, _08160CC0 @ =0x000005D4
	adds r6, r7, r6
	str r6, [sp, #0x15c]
	ldr r1, _08160CC4 @ =0x000005DC
	adds r1, r7, r1
	str r1, [sp, #0x164]
	movs r2, #0xb9
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x150]
	ldr r3, _08160CC8 @ =0x00000584
	adds r3, r7, r3
	str r3, [sp, #0xf8]
	ldr r4, _08160CCC @ =0x00000604
	adds r4, r7, r4
	str r4, [sp, #0x188]
	movs r5, #0xc1
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x18c]
	ldr r6, _08160CD0 @ =0x0000021D
	adds r6, r7, r6
	str r6, [sp, #0xe8]
	ldr r1, _08160CD4 @ =0x0000060C
	adds r1, r7, r1
	str r1, [sp, #0x190]
	movs r2, #0xbe
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x178]
	ldr r3, _08160CD8 @ =0x000005E4
	adds r3, r7, r3
	str r3, [sp, #0x16c]
	movs r4, #0xbf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x17c]
	ldr r5, _08160CDC @ =0x000005FC
	adds r5, r7, r5
	str r5, [sp, #0x180]
	movs r6, #0xc0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x184]
	ldr r1, _08160CE0 @ =0x00000614
	adds r1, r7, r1
	str r1, [sp, #0x194]
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x198]
	ldr r3, _08160CE4 @ =0x000005BC
	adds r3, r7, r3
	str r3, [sp, #0x144]
	movs r4, #0xbd
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x170]
	movs r5, #0xbc
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x168]
	ldr r6, _08160CE8 @ =0x000005EC
	adds r6, r7, r6
	str r6, [sp, #0x174]
	movs r1, #0xbb
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x160]
	movs r2, #0xb5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x128]
	ldr r3, _08160CEC @ =0x00000624
	adds r3, r7, r3
	str r3, [sp, #0x19c]
	ldr r4, _08160CF0 @ =0x0000058C
	adds r4, r7, r4
	str r4, [sp, #0x100]
	movs r5, #0xc5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x1a0]
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x140]
	ldr r1, _08160CF4 @ =0x00000594
	adds r1, r7, r1
	str r1, [sp, #0x108]
	movs r2, #0xb3
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x10c]
	ldr r3, _08160CF8 @ =0x0000059C
	adds r3, r7, r3
	str r3, [sp, #0x110]
	ldr r4, _08160CFC @ =0x000005B4
	adds r4, r7, r4
	str r4, [sp, #0x13c]
	ldr r5, _08160D00 @ =0x00000543
	adds r5, r7, r5
	str r5, [sp, #0xa8]
	movs r6, #0xcc
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x88]
	movs r1, #0xcd
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	ldr r2, _08160D04 @ =0x00000496
	adds r2, r7, r2
	str r2, [sp, #0x6c]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x40]
	ldr r4, _08160D08 @ =0x00000469
	adds r4, r7, r4
	str r4, [sp, #0x44]
	ldr r5, _08160D0C @ =0x0000046A
	adds r5, r7, r5
	str r5, [sp, #0x48]
	ldr r6, _08160D10 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0xac]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xf0]
	movs r2, #0x92
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x68]
	movs r3, #0xea
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x98]
	ldr r4, _08160D14 @ =0x00000572
	adds r4, r7, r4
	str r4, [sp, #0xdc]
	movs r5, #0xdf
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x90]
	movs r6, #0xae
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xd8]
	ldr r1, _08160D18 @ =0x0000055C
	adds r1, r7, r1
	str r1, [sp, #0xb0]
	movs r2, #0xac
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xb4]
	ldr r3, _08160D1C @ =0x00000564
	adds r3, r7, r3
	str r3, [sp, #0xb8]
	ldr r4, _08160D20 @ =0x00000565
	adds r4, r7, r4
	str r4, [sp, #0xbc]
	ldr r5, _08160D24 @ =0x00000566
	adds r5, r7, r5
	str r5, [sp, #0xc0]
	ldr r6, _08160D28 @ =0x00000567
	adds r6, r7, r6
	str r6, [sp, #0xc4]
	movs r1, #0xad
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xc8]
	ldr r2, _08160D2C @ =0x0000056C
	adds r2, r7, r2
	str r2, [sp, #0xd0]
	cmp r0, #0
	bne _08160C6A
	b _08160D88
_08160C6A:
	movs r3, #0
	mov sl, r3
	movs r4, #0x8d
	lsls r4, r4, #2
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r5, r5, r7
	mov r8, r5
	movs r6, #0x8b
	lsls r6, r6, #2
	adds r5, r7, r6
	movs r0, #0x89
	lsls r0, r0, #2
	adds r4, r7, r0
_08160C8A:
	bl VM_GetPC
	cmp r0, #0
	beq _08160D30
	bl Script_GetValue
	b _08160D32
	.align 2, 0
_08160C98: .4byte 0x0000025D
_08160C9C: .4byte 0x0000025A
_08160CA0: .4byte 0x0000047A
_08160CA4: .4byte 0x0000047C
_08160CA8: .4byte 0x0000047E
_08160CAC: .4byte 0x00000476
_08160CB0: .4byte 0x000004A4
_08160CB4: .4byte 0x000005A4
_08160CB8: .4byte 0x000005C4
_08160CBC: .4byte 0x000005CC
_08160CC0: .4byte 0x000005D4
_08160CC4: .4byte 0x000005DC
_08160CC8: .4byte 0x00000584
_08160CCC: .4byte 0x00000604
_08160CD0: .4byte 0x0000021D
_08160CD4: .4byte 0x0000060C
_08160CD8: .4byte 0x000005E4
_08160CDC: .4byte 0x000005FC
_08160CE0: .4byte 0x00000614
_08160CE4: .4byte 0x000005BC
_08160CE8: .4byte 0x000005EC
_08160CEC: .4byte 0x00000624
_08160CF0: .4byte 0x0000058C
_08160CF4: .4byte 0x00000594
_08160CF8: .4byte 0x0000059C
_08160CFC: .4byte 0x000005B4
_08160D00: .4byte 0x00000543
_08160D04: .4byte 0x00000496
_08160D08: .4byte 0x00000469
_08160D0C: .4byte 0x0000046A
_08160D10: .4byte 0x00000553
_08160D14: .4byte 0x00000572
_08160D18: .4byte 0x0000055C
_08160D1C: .4byte 0x00000564
_08160D20: .4byte 0x00000565
_08160D24: .4byte 0x00000566
_08160D28: .4byte 0x00000567
_08160D2C: .4byte 0x0000056C
_08160D30:
	movs r0, #0x18
_08160D32:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _08160D44
	bl Script_GetValue
	b _08160D46
_08160D44:
	movs r0, #0x18
_08160D46:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _08160D58
	bl Script_GetValue
	b _08160D5A
_08160D58:
	movs r0, #0
_08160D5A:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08160D6C
	bl Script_GetValue
	b _08160D6E
_08160D6C:
	movs r0, #0
_08160D6E:
	strh r0, [r6]
	movs r1, #2
	add sb, r1
	movs r2, #4
	add r8, r2
	adds r5, #2
	adds r4, #2
	movs r3, #1
	add sl, r3
	mov r6, sl
	cmp r6, #3
	bgt _08160D88
	b _08160C8A
_08160D88:
	movs r0, #0x6c
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08160DD4
	bl VM_GetPC
	cmp r0, #0
	beq _08160DA2
	bl Script_GetValue
	adds r4, r0, #0
	b _08160DA6
_08160DA2:
	movs r4, #0x96
	lsls r4, r4, #1
_08160DA6:
	bl VM_GetPC
	cmp r0, #0
	beq _08160DB6
	bl Script_GetValue
	adds r6, r0, #0
	b _08160DBA
_08160DB6:
	movs r6, #0x96
	lsls r6, r6, #1
_08160DBA:
	bl VM_GetPC
	cmp r0, #0
	beq _08160DC8
	bl Script_GetValue
	b _08160DCE
_08160DC8:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
_08160DCE:
	ldr r2, [sp, #0x118]
	strh r0, [r2]
	b _08160DDC
_08160DD4:
	movs r4, #0
	movs r6, #0
	ldr r3, [sp, #0x118]
	strh r6, [r3]
_08160DDC:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _08160DF4
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x7c]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_08160DF4:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x84]
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, [sp, #0x80]
	strh r0, [r2]
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08160EC4
	bl VM_GetPC
	cmp r0, #0
	beq _08160E24
	bl Script_GetValue
	b _08160E26
_08160E24:
	movs r0, #0
_08160E26:
	ldr r3, [sp, #0x130]
	strh r0, [r3]
	ldrh r0, [r3]
	cmp r0, #0
	blt _08160E34
	asrs r1, r0, #1
	b _08160E3A
_08160E34:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08160E3A:
	ldr r5, _08160E50 @ =0x00000546
	adds r0, r7, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08160E54
	bl Script_GetValue
	b _08160E56
	.align 2, 0
_08160E50: .4byte 0x00000546
_08160E54:
	movs r0, #0
_08160E56:
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08160E6C
	bl Script_GetValue
	b _08160E6E
_08160E6C:
	movs r0, #0
_08160E6E:
	ldr r3, _08160E84 @ =0x00000187
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08160E88
	bl Script_GetValue
	adds r1, r0, #0
	b _08160E8A
	.align 2, 0
_08160E84: .4byte 0x00000187
_08160E88:
	movs r1, #0
_08160E8A:
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08160EA0
	bl Script_GetValue
	b _08160EA2
_08160EA0:
	movs r0, #0
_08160EA2:
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08160EBA
	bl Script_GetValue
	adds r1, r0, #0
	b _08160EBC
_08160EBA:
	movs r1, #0
_08160EBC:
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_08160EC4:
	ldr r5, [sp, #0x130]
	ldrh r1, [r5]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r6, [sp, #0xd4]
	lsrs r2, r6, #0x10
	ldr r0, [sp, #0xe4]
	lsrs r3, r0, #0x10
	ldr r1, [sp, #0xec]
	lsrs r0, r1, #0x10
	str r0, [sp]
	ldr r4, [sp, #0xe0]
	lsrs r0, r4, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08160F26
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r6, r7, r5
	bl VM_GetPC
	cmp r0, #0
	beq _08160F0C
	bl Script_GetValue
	b _08160F0E
_08160F0C:
	movs r0, #0
_08160F0E:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _08160F1E
	bl Script_GetValue
	b _08160F20
_08160F1E:
	movs r0, #0
_08160F20:
	ldr r6, _08160F88 @ =0x00000189
	adds r1, r7, r6
	strb r0, [r1]
_08160F26:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x134]
	strh r0, [r1]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _08160F4A
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x7c]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08160F4A:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _08160F62
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r3, [sp, #0x7c]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_08160F62:
	ldr r4, [sp, #0xcc]
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
	ldr r5, [sp, #0x4c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08160F8C
	movs r0, #1
	b _08160F8E
	.align 2, 0
_08160F88: .4byte 0x00000189
_08160F8C:
	movs r0, #0
_08160F8E:
	cmp r0, #0
	beq _08160F9E
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08160FC8 @ =FUN_080f48ac
	ldr r1, [sp, #0x28]
	bl FUN_0807f558
_08160F9E:
	ldr r6, [sp, #0x138]
	ldrb r0, [r6]
	movs r1, #0
	cmp r0, #0
	bne _08160FAA
	ldr r1, [r7, #0x44]
_08160FAA:
	ldr r0, [sp, #0x28]
	bl FUN_0823b46c
	ldr r1, [sp, #0x9c]
	ldrb r0, [r1]
	cmp r0, #0x15
	bne _08160FCC
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x34]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _08160FD8
	.align 2, 0
_08160FC8: .4byte FUN_080f48ac
_08160FCC:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x34]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_08160FD8:
	ldr r2, [sp, #0x9c]
	ldrb r1, [r2]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08161026
	adds r0, r1, #0
	cmp r0, #0xb
	beq _08161026
	cmp r0, #0x16
	beq _08161026
	cmp r0, #0x14
	beq _08161026
	cmp r0, #9
	beq _08161026
	cmp r0, #0x19
	beq _08161026
	cmp r0, #0x1a
	beq _08161026
	cmp r0, #0xd
	beq _08161026
	cmp r0, #0x1b
	beq _08161026
	cmp r0, #0x1f
	beq _08161026
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r3, [sp, #0x120]
	ldrb r2, [r3]
	ldr r4, [sp, #0x124]
	ldrb r3, [r4]
	ldr r5, [sp, #0x12c]
	ldrb r0, [r5]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl FUN_0823b490
_08161026:
	movs r1, #8
	ldr r6, [sp, #0x4c]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08161036
	movs r0, #1
	b _08161038
_08161036:
	movs r0, #0
_08161038:
	cmp r0, #0
	beq _08161046
	ldr r1, [sp, #0xa4]
	ldr r0, [r1]
	ldr r2, [sp, #0xa0]
	str r0, [r2]
	b _08161058
_08161046:
	ldr r3, [sp, #0xa4]
	ldr r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r4, [sp, #0xa0]
	str r0, [r4]
_08161058:
	ldrh r0, [r7]
	ldr r5, [sp, #0x38]
	strh r0, [r5]
	ldr r6, [sp, #0x30]
	ldr r0, [sp, #0x3c]
	str r6, [r0]
	ldr r1, [sp, #0x2c]
	cmp r1, #0
	beq _08161082
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
_08161082:
	ldr r3, [sp, #0x94]
	ldr r5, [r3]
	movs r0, #0x54
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081610F4
	bl VM_GetPC
	cmp r0, #0
	beq _081610A0
	bl Script_GetValue
	adds r1, r0, #0
	b _081610A6
_081610A0:
	movs r4, #0xc8
	lsls r4, r4, #2
	adds r1, r4, #0
_081610A6:
	ldr r6, _081610BC @ =0x000006EC
	adds r0, r5, r6
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081610C0
	bl Script_GetValue
	b _081610C6
	.align 2, 0
_081610BC: .4byte 0x000006EC
_081610C0:
	movs r1, #0x96
	lsls r1, r1, #2
	adds r0, r1, #0
_081610C6:
	ldr r2, _081610DC @ =0x000006EE
	adds r4, r5, r2
	strh r0, [r4]
	bl VM_GetPC
	cmp r0, #0
	beq _081610E0
	bl Script_GetValue
	adds r1, r0, #0
	b _081610E6
	.align 2, 0
_081610DC: .4byte 0x000006EE
_081610E0:
	movs r3, #0x96
	lsls r3, r3, #2
	adds r1, r3, #0
_081610E6:
	ldr r6, _081610F0 @ =0x000006DE
	adds r0, r5, r6
	strh r1, [r0]
	b _08161110
	.align 2, 0
_081610F0: .4byte 0x000006DE
_081610F4:
	ldr r0, _08161174 @ =0x000006EC
	adds r1, r5, r0
	movs r0, #0xc8
	lsls r0, r0, #2
	strh r0, [r1]
	ldr r1, _08161178 @ =0x000006EE
	adds r2, r5, r1
	movs r1, #0x96
	lsls r1, r1, #2
	strh r1, [r2]
	ldr r3, _0816117C @ =0x000006DE
	adds r0, r5, r3
	strh r1, [r0]
	adds r4, r2, #0
_08161110:
	ldr r2, _08161180 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08161184 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r6, _08161188 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r2, #0
	ldrsh r1, [r4, r2]
	bl Mod
	movs r3, #0xd9
	lsls r3, r3, #3
	adds r1, r5, r3
	strh r0, [r1]
	movs r4, #0xfd
	lsls r4, r4, #1
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r6, [sp, #0x64]
	strh r0, [r6]
	ldr r0, [sp, #0x58]
	strh r4, [r0]
	ldr r1, [sp, #0x5c]
	strh r5, [r1]
	ldrh r0, [r6]
	ldr r2, _0816118C @ =0x000001FB
	adds r0, r0, r2
	ldr r3, [sp, #0x60]
	strh r0, [r3]
	ldr r4, [sp, #0x58]
	ldrh r1, [r4]
	ldrh r0, [r6]
	adds r1, r1, r0
	ldr r5, [sp, #0x138]
	ldrb r0, [r5]
	cmp r0, #0
	bne _08161190
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _0816119C
	.align 2, 0
_08161174: .4byte 0x000006EC
_08161178: .4byte 0x000006EE
_0816117C: .4byte 0x000006DE
_08161180: .4byte 0x030046B8
_08161184: .4byte 0x000003FF
_08161188: .4byte 0x0203B400
_0816118C: .4byte 0x000001FB
_08161190:
	ldr r2, [r7, #0x44]
	ldr r0, _081611D4 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_0816119C:
	ldr r6, [sp, #0x138]
	ldrb r0, [r6]
	cmp r0, #1
	bne _081611EC
	ldr r1, [sp, #0x9c]
	ldrb r0, [r1]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _081611D8
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
	b _081611E2
	.align 2, 0
_081611D4: .4byte 0x03003584
_081611D8:
	ldr r2, [sp, #0x9c]
	ldrb r0, [r2]
	bl FUN_080ecf60
	adds r4, r0, #1
_081611E2:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_081611EC:
	movs r4, #0
	ldr r3, [sp, #0x58]
	ldrh r0, [r3]
	adds r0, #2
	ldr r5, [sp, #0x50]
	strh r0, [r5]
	ldrh r0, [r3]
	ldr r6, [sp, #0x54]
	strh r0, [r6]
	adds r0, r7, #0
	bl FUN_081599cc
	ldr r1, [sp, #0x24]
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r0, r1, r2
	ldr r3, _081613BC @ =0x0000072C
	adds r1, r1, r3
	mov r8, r1
	ldr r5, _081613C0 @ =FUN_081604cc
	mov sb, r5
	ldr r6, _081613C4 @ =FUN_0815ca20
	mov sl, r6
	ldr r1, _081613C8 @ =FUN_08152dac
	mov ip, r1
	ldr r5, _081613CC @ =FUN_08153d98
	ldr r3, _081613D0 @ =FUN_0815f4d8
	ldr r2, _081613D4 @ =FUN_080f62ac
	str r2, [sp, #0x1a4]
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x78]
	ldr r1, [r6]
	orrs r1, r2
	str r1, [r6]
	ldr r1, [sp, #0x70]
	str r0, [r1]
	mov r2, r8
	ldr r6, [sp, #0x74]
	str r2, [r6]
	mov r1, sb
	ldr r2, [sp, #0xf4]
	str r1, [r2]
	mov r6, sl
	ldr r1, [sp, #0xfc]
	str r6, [r1]
	mov r2, ip
	ldr r6, [sp, #0x104]
	str r2, [r6]
	ldr r1, _081613D8 @ =FUN_08152d40
	ldr r2, [sp, #0x114]
	str r1, [r2]
	ldr r6, _081613DC @ =FUN_08152d88
	ldr r1, [sp, #0x11c]
	str r6, [r1]
	ldr r2, _081613E0 @ =FUN_0815344c
	ldr r6, [sp, #0x148]
	str r2, [r6]
	ldr r1, [sp, #0x14c]
	str r3, [r1]
	ldr r2, [sp, #0x154]
	str r5, [r2]
	ldr r3, _081613E4 @ =FUN_081549c4
	ldr r5, [sp, #0x158]
	str r3, [r5]
	ldr r1, _081613E8 @ =FUN_080f44f4
	ldr r6, [sp, #0x15c]
	str r1, [r6]
	ldr r1, _081613EC @ =FUN_080f410c
	ldr r2, [sp, #0x164]
	str r1, [r2]
	ldr r3, _081613F0 @ =FUN_081538fc
	ldr r5, [sp, #0x150]
	str r3, [r5]
	ldr r6, _081613F4 @ =FUN_08153578
	ldr r1, [sp, #0xf8]
	str r6, [r1]
	ldr r2, [sp, #0x1a4]
	ldr r3, [sp, #0x188]
	str r2, [r3]
	ldr r1, _081613F8 @ =FUN_080f0430
	ldr r5, [sp, #0x18c]
	str r1, [r5]
	movs r1, #1
	ldr r6, [sp, #0xe8]
	strb r1, [r6]
	ldr r1, _081613FC @ =0x085AD470
	ldr r2, [sp, #0x190]
	str r1, [r2]
	ldr r1, _08161400 @ =FUN_080e73c8
	ldr r3, [sp, #0x178]
	str r1, [r3]
	ldr r5, [sp, #0x16c]
	str r4, [r5]
	ldr r6, [sp, #0x17c]
	str r4, [r6]
	ldr r1, [sp, #0x180]
	str r4, [r1]
	ldr r2, [sp, #0x184]
	str r4, [r2]
	ldr r3, [sp, #0x194]
	str r4, [r3]
	ldr r1, _08161404 @ =FUN_080f0320
	ldr r5, [sp, #0x198]
	str r1, [r5]
	ldr r1, _08161408 @ =FUN_080eff14
	ldr r6, [sp, #0x144]
	str r1, [r6]
	ldr r5, _0816140C @ =FUN_080e72b0
	ldr r1, [sp, #0x170]
	str r5, [r1]
	ldr r2, [sp, #0x168]
	str r4, [r2]
	ldr r1, _08161410 @ =FUN_080f47c8
	ldr r3, [sp, #0x174]
	str r1, [r3]
	ldr r1, _08161414 @ =FUN_080f54e4
	ldr r6, [sp, #0x160]
	str r1, [r6]
	ldr r1, [sp, #0x128]
	str r4, [r1]
	ldr r1, _08161418 @ =FUN_080f6e64
	ldr r2, [sp, #0x19c]
	str r1, [r2]
	ldr r1, _0816141C @ =FUN_080f64f0
	ldr r3, [sp, #0x100]
	str r1, [r3]
	ldr r1, _08161420 @ =FUN_080f84d4
	ldr r6, [sp, #0x1a0]
	str r1, [r6]
	ldr r1, _08161424 @ =FUN_080f624c
	ldr r2, [sp, #0x140]
	str r1, [r2]
	ldr r1, _08161428 @ =FUN_080f56ec
	ldr r3, [sp, #0x108]
	str r1, [r3]
	ldr r1, _0816142C @ =FUN_080f5b34
	ldr r6, [sp, #0x10c]
	str r1, [r6]
	ldr r1, _08161430 @ =FUN_080f5fac
	ldr r2, [sp, #0x110]
	str r1, [r2]
	ldr r3, [sp, #0x13c]
	str r4, [r3]
	movs r1, #0x28
	ldr r6, [sp, #0xa8]
	strb r1, [r6]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r4, [r1]
	ldr r1, [sp, #0x30]
	bl FUN_082362fc
	adds r0, r7, #0
	bl FUN_080e6204
	movs r3, #0xbe
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _08161434 @ =FUN_0815c63c
	str r0, [r1]
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _08161438 @ =FUN_0815d20c
	str r0, [r1]
	movs r6, #0xbd
	lsls r6, r6, #3
	adds r0, r7, r6
	str r5, [r0]
	movs r0, #0xbf
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _0816143C @ =FUN_0815ea60
	str r0, [r1]
	ldr r2, _08161440 @ =0x000005BC
	adds r1, r7, r2
	ldr r0, _08161444 @ =FUN_08157280
	str r0, [r1]
	adds r3, #0xc
	adds r1, r7, r3
	ldr r0, _08161448 @ =FUN_0815ec0c
	str r0, [r1]
	adds r4, #0x10
	adds r1, r7, r4
	ldr r0, _0816144C @ =FUN_0815cbd4
	str r0, [r1]
	ldr r5, _08161450 @ =0x0000058C
	adds r1, r7, r5
	ldr r0, _08161454 @ =FUN_0815f8c0
	str r0, [r1]
	subs r6, #0x3c
	adds r1, r7, r6
	ldr r0, _08161458 @ =FUN_0815cd10
	str r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _0816145C @ =FUN_0815ce34
	str r0, [r1]
	movs r1, #0xb8
	lsls r1, r1, #0x11
	ldr r2, [sp, #0x78]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #8
	ldr r3, [sp, #0x7c]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	ldr r4, _08161460 @ =0x000001DF
	adds r1, r7, r4
	movs r0, #0xa
	strb r0, [r1]
	movs r0, #0x50
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	bne _081613AA
	b _081614D0
_081613AA:
	bl VM_GetPC
	cmp r0, #0
	beq _08161464
	bl Script_GetValue
	adds r1, r0, #0
	b _08161466
	.align 2, 0
_081613BC: .4byte 0x0000072C
_081613C0: .4byte FUN_081604cc
_081613C4: .4byte FUN_0815ca20
_081613C8: .4byte FUN_08152dac
_081613CC: .4byte FUN_08153d98
_081613D0: .4byte FUN_0815f4d8
_081613D4: .4byte FUN_080f62ac
_081613D8: .4byte FUN_08152d40
_081613DC: .4byte FUN_08152d88
_081613E0: .4byte FUN_0815344c
_081613E4: .4byte FUN_081549c4
_081613E8: .4byte FUN_080f44f4
_081613EC: .4byte FUN_080f410c
_081613F0: .4byte FUN_081538fc
_081613F4: .4byte FUN_08153578
_081613F8: .4byte FUN_080f0430
_081613FC: .4byte 0x085AD470
_08161400: .4byte FUN_080e73c8
_08161404: .4byte FUN_080f0320
_08161408: .4byte FUN_080eff14
_0816140C: .4byte FUN_080e72b0
_08161410: .4byte FUN_080f47c8
_08161414: .4byte FUN_080f54e4
_08161418: .4byte FUN_080f6e64
_0816141C: .4byte FUN_080f64f0
_08161420: .4byte FUN_080f84d4
_08161424: .4byte FUN_080f624c
_08161428: .4byte FUN_080f56ec
_0816142C: .4byte FUN_080f5b34
_08161430: .4byte FUN_080f5fac
_08161434: .4byte FUN_0815c63c
_08161438: .4byte FUN_0815d20c
_0816143C: .4byte FUN_0815ea60
_08161440: .4byte 0x000005BC
_08161444: .4byte FUN_08157280
_08161448: .4byte FUN_0815ec0c
_0816144C: .4byte FUN_0815cbd4
_08161450: .4byte 0x0000058C
_08161454: .4byte FUN_0815f8c0
_08161458: .4byte FUN_0815cd10
_0816145C: .4byte FUN_0815ce34
_08161460: .4byte 0x000001DF
_08161464:
	movs r1, #0x14
_08161466:
	ldr r5, [sp, #0x24]
	ldr r6, _0816147C @ =0x000006C5
	adds r0, r5, r6
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08161480
	bl Script_GetValue
	b _08161484
	.align 2, 0
_0816147C: .4byte 0x000006C5
_08161480:
	movs r0, #0x96
	lsls r0, r0, #1
_08161484:
	adds r1, r0, #0
	ldr r2, [sp, #0x24]
	ldr r3, _081614A0 @ =0x000006C6
	adds r0, r2, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081614A4
	bl Script_GetValue
	adds r1, r0, #0
	b _081614A6
	.align 2, 0
_081614A0: .4byte 0x000006C6
_081614A4:
	movs r1, #0
_081614A6:
	ldr r4, [sp, #0x24]
	movs r5, #0xde
	lsls r5, r5, #3
	adds r0, r4, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081614C0
	bl Script_GetValue
	adds r1, r0, #0
	b _081614C2
_081614C0:
	movs r1, #0
_081614C2:
	ldr r6, [sp, #0x24]
	ldr r2, _081614CC @ =0x000006F2
	adds r0, r6, r2
	strh r1, [r0]
	b _081614F2
	.align 2, 0
_081614CC: .4byte 0x000006F2
_081614D0:
	ldr r3, [sp, #0x24]
	ldr r4, _0816153C @ =0x000006C5
	adds r1, r3, r4
	movs r0, #0x14
	strb r0, [r1]
	ldr r5, _08161540 @ =0x000006C6
	adds r1, r3, r5
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r6, #0xde
	lsls r6, r6, #3
	adds r0, r3, r6
	strh r2, [r0]
	ldr r1, _08161544 @ =0x000006F2
	adds r0, r3, r1
	strh r2, [r0]
_081614F2:
	movs r2, #0x94
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r1, [r0]
	movs r0, #0x55
	bl VM_GetKeywordValue
	ldr r3, [sp, #0x24]
	ldr r4, _08161548 @ =0x000006FC
	adds r1, r3, r4
	strh r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080e5dd4
	movs r0, #0x49
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r5, [sp, #0x88]
	strh r0, [r5]
	movs r0, #0x47
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08161556
	movs r6, #0xce
	lsls r6, r6, #1
	adds r5, r7, r6
	movs r4, #4
_0816152C:
	bl VM_GetPC
	cmp r0, #0
	beq _0816154C
	bl Script_GetValue
	b _0816154E
	.align 2, 0
_0816153C: .4byte 0x000006C5
_08161540: .4byte 0x000006C6
_08161544: .4byte 0x000006F2
_08161548: .4byte 0x000006FC
_0816154C:
	movs r0, #0
_0816154E:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _0816152C
_08161556:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x8c]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x6c]
	strh r0, [r3]
	cmp r2, #0
	beq _0816158E
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x78]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _0816158E
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_0816158E:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x4c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081615A0
	movs r0, #1
	b _081615A2
_081615A0:
	movs r0, #0
_081615A2:
	cmp r0, #0
	beq _081615B4
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x7c]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_081615B4:
	cmp r2, #1
	beq _081615F4
	movs r1, #0
	ldr r0, [sp, #0x40]
	strb r1, [r0]
	ldr r2, [sp, #0x44]
	strb r1, [r2]
	ldr r3, [sp, #0x48]
	strb r1, [r3]
	ldr r4, _08161604 @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _08161608 @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0x11c]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0xac]
	strb r1, [r6]
	ldr r0, [sp, #0xf0]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_081615F4:
	movs r1, #2
	ldr r3, [sp, #0x4c]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0816160C
	movs r0, #1
	b _0816160E
	.align 2, 0
_08161604: .4byte 0x00000484
_08161608: .4byte 0x0000046C
_0816160C:
	movs r0, #0
_0816160E:
	cmp r0, #0
	beq _08161628
	ldr r0, _08161624 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x68]
	strh r0, [r5]
	b _08161632
	.align 2, 0
_08161624: .4byte 0x030046A0
_08161628:
	ldr r0, [sp, #0x30]
	bl FUN_08241574
	ldr r6, [sp, #0x68]
	strh r0, [r6]
_08161632:
	movs r1, #0x40
	ldr r2, [sp, #0x4c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08161642
	movs r0, #1
	b _08161644
_08161642:
	movs r0, #0
_08161644:
	cmp r0, #0
	beq _08161654
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _08161678 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_08161654:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	bne _08161686
	ldr r0, _0816167C @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x68]
	ldrh r4, [r4]
	cmp r0, r4
	bne _08161680
	movs r0, #1
	b _08161682
	.align 2, 0
_08161678: .4byte 0xFFFFFEFF
_0816167C: .4byte 0x030046A0
_08161680:
	movs r0, #0
_08161682:
	cmp r0, #0
	bne _0816168E
_08161686:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_0816168E:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, [sp, #0x138]
	ldrb r0, [r5]
	cmp r0, #0
	bne _08161776
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
	beq _081616D0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081616D8
_081616D0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081616D8:
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
	beq _081616FC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08161704
_081616FC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08161704:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _0816173C @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08161780
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08161740
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08161734
	ldrb r0, [r4, #5]
_08161734:
	subs r0, #1
	strh r0, [r4, #8]
	b _08161750
	.align 2, 0
_0816173C: .4byte 0x0000FFFF
_08161740:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08161750
	strh r1, [r4, #8]
_08161750:
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
	bne _08161780
	movs r0, #1
	strb r0, [r4, #7]
	b _08161780
_08161776:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_08161780:
	movs r0, #0
	ldr r3, [sp, #0x98]
	str r0, [r3]
	ldr r0, _08161798 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0816179C
	movs r0, #1
	b _0816179E
	.align 2, 0
_08161798: .4byte 0x030047A4
_0816179C:
	movs r0, #0
_0816179E:
	cmp r0, #0
	bne _081617DE
	ldr r4, [sp, #0x9c]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081617C6
	adds r0, r1, #0
	cmp r0, #7
	beq _081617C6
	cmp r0, #6
	beq _081617C6
	cmp r0, #0x15
	beq _081617C6
	cmp r0, #0x14
	beq _081617C6
	cmp r0, #0x17
	bne _081617DE
_081617C6:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x4c]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_081617DE:
	ldr r6, [sp, #0x94]
	ldr r4, [r6]
	ldr r0, [sp, #0xa0]
	ldr r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	movs r2, #0xda
	lsls r2, r2, #3
	adds r1, r4, r2
	str r0, [r1]
	ldr r3, _08161894 @ =0x000006D4
	adds r4, r4, r3
	ldr r5, [sp, #0xa0]
	ldr r0, [r5]
	str r0, [r4]
	adds r0, r7, #0
	bl Enemy_Init_080f3680
	adds r0, r7, #0
	bl FUN_0815987c
	adds r0, r7, #0
	bl FUN_08159890
	adds r0, r7, #0
	bl FUN_08158170
	ldr r6, [sp, #0x4c]
	ldrh r0, [r6]
	ldr r1, [sp, #0xdc]
	strh r0, [r1]
	ldr r2, [sp, #0x90]
	ldrh r0, [r2]
	ldr r3, [sp, #0xd8]
	strh r0, [r3]
	ldr r4, [sp, #0x78]
	ldr r0, [r4]
	ldr r5, [sp, #0xb0]
	str r0, [r5]
	ldr r6, [sp, #0x7c]
	ldr r0, [r6]
	ldr r1, [sp, #0xb4]
	str r0, [r1]
	ldrb r0, [r7, #5]
	ldr r2, [sp, #0xb8]
	strb r0, [r2]
	ldr r3, [sp, #0x40]
	ldrb r0, [r3]
	ldr r4, [sp, #0xbc]
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	ldrb r0, [r5]
	ldr r6, [sp, #0xc0]
	strb r0, [r6]
	ldr r1, [sp, #0x48]
	ldrb r0, [r1]
	ldr r2, [sp, #0xc4]
	strb r0, [r2]
	ldr r3, [sp, #0xf0]
	ldr r0, [r3]
	ldr r4, [sp, #0xc8]
	str r0, [r4]
	ldr r5, [sp, #0xac]
	ldrb r0, [r5]
	ldr r6, [sp, #0xd0]
	strb r0, [r6]
	ldr r0, _08161898 @ =0x0000057C
	adds r1, r7, r0
	ldr r0, _0816189C @ =FUN_080f09e0
	str r0, [r1]
	ldr r2, _081618A0 @ =0x0000061C
	adds r1, r7, r2
	ldr r0, _081618A4 @ =FUN_08160528
	str r0, [r1]
	movs r3, #0xc4
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _081618A8 @ =EnemyCockatrice_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081618AC
	movs r0, #0
	b _081618B0
	.align 2, 0
_08161894: .4byte 0x000006D4
_08161898: .4byte 0x0000057C
_0816189C: .4byte FUN_080f09e0
_081618A0: .4byte 0x0000061C
_081618A4: .4byte FUN_08160528
_081618A8: .4byte EnemyCockatrice_Destroy
_081618AC:
	movs r0, #1
	rsbs r0, r0, #0
_081618B0:
	add sp, #0x1ac
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start EnemyCockatrice_Create
EnemyCockatrice_Create: @ 0x081618C0
	push {r4, r5, lr}
	ldr r5, _081618F4 @ =0x00000734
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _081618EC
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemyCockatrice_Init
	cmp r0, #0
	bge _081618EC
	adds r0, r4, #0
	bl EnemyCockatrice_Destroy
	adds r0, r4, #0
	bl Free
_081618EC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081618F4: .4byte 0x00000734

	thumb_func_start FUN_081618f8
FUN_081618f8: @ 0x081618F8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	mov sl, r0
	ldr r0, _08161928 @ =0x00000256
	add r0, sb
	ldrh r6, [r0]
	mov r4, sb
	adds r4, #8
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0816192C
	adds r0, #4
	b _08161938
	.align 2, 0
_08161928: .4byte 0x00000256
_0816192C:
	ldr r0, _0816194C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08161938:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08161950
	cmp r3, #2
	beq _08161954
	b _08161958
	.align 2, 0
_0816194C: .4byte 0x030046A4
_08161950:
	ldrb r0, [r4, #4]
	b _08161956
_08161954:
	ldrb r0, [r4]
_08161956:
	subs r2, r2, r0
_08161958:
	mov r8, r2
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0816196A
	adds r0, #4
	b _08161976
_0816196A:
	ldr r0, _08161988 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08161976:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _0816198C
	asrs r0, r0, #6
	b _08161992
	.align 2, 0
_08161988: .4byte 0x030046A4
_0816198C:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08161992:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _081619D0
	cmp r1, #1
	bgt _081619A4
	cmp r1, #0
	beq _081619AE
	b _08161A90
_081619A4:
	cmp r1, #2
	beq _08161A0C
	cmp r1, #3
	beq _08161A2E
	b _08161A90
_081619AE:
	adds r4, r6, #1
	movs r5, #0
_081619B2:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081619CC
	adds r4, #1
	adds r5, #1
	cmp r5, #2
	blt _081619B2
_081619CC:
	subs r5, r4, #1
	b _08161A96
_081619D0:
	ldr r1, _08161A08 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r6, r0
	movs r5, #0
_081619DE:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08161A68
	ldr r0, _08161A08 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #2
	blt _081619DE
	subs r5, r4, r0
	b _08161A96
	.align 2, 0
_08161A08: .4byte 0x030046A4
_08161A0C:
	subs r4, r6, #1
	movs r5, #0
_08161A10:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08161A2A
	subs r4, #1
	adds r5, #1
	cmp r5, #2
	blt _08161A10
_08161A2A:
	adds r5, r4, #1
	b _08161A96
_08161A2E:
	ldr r1, _08161A64 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r6, r0
	movs r5, #0
_08161A3C:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08161A7C
	ldr r0, _08161A64 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	adds r5, #1
	cmp r5, #2
	blt _08161A3C
	adds r5, r4, r0
	b _08161A96
	.align 2, 0
_08161A64: .4byte 0x030046A4
_08161A68:
	ldr r1, _08161A78 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r4, r0
	b _08161A96
	.align 2, 0
_08161A78: .4byte 0x030046A4
_08161A7C:
	ldr r1, _08161A8C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r5, r4, r0
	b _08161A96
	.align 2, 0
_08161A8C: .4byte 0x030046A4
_08161A90:
	ldr r0, _08161AE0 @ =0x00000256
	add r0, sb
	ldrh r5, [r0]
_08161A96:
	ldr r0, _08161AE0 @ =0x00000256
	add r0, sb
	ldrh r0, [r0]
	cmp r5, r0
	bne _08161B1C
	movs r6, #0xd6
	lsls r6, r6, #3
	add r6, sl
	ldr r1, _08161AE4 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _08161AE4 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08161AE8
	adds r0, #4
	b _08161AF4
	.align 2, 0
_08161AE0: .4byte 0x00000256
_08161AE4: .4byte 0x030046A4
_08161AE8:
	ldr r1, _08161B14 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08161AF4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r0, _08161B18 @ =0x000006E2
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _08161B7C
	movs r0, #0
	b _08161B7E
	.align 2, 0
_08161B14: .4byte 0x030046A4
_08161B18: .4byte 0x000006E2
_08161B1C:
	movs r6, #0xd6
	lsls r6, r6, #3
	add r6, sl
	ldr r1, _08161B5C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _08161B5C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08161B60
	adds r0, #4
	b _08161B6C
	.align 2, 0
_08161B5C: .4byte 0x030046A4
_08161B60:
	ldr r1, _08161B8C @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08161B6C:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r6, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r6, #4]
_08161B7C:
	movs r0, #1
_08161B7E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08161B8C: .4byte 0x030046A4

	thumb_func_start FUN_08161b90
FUN_08161b90: @ 0x08161B90
	ldr r1, _08161BA8 @ =0x000006DC
	adds r2, r0, r1
	movs r1, #0
	strh r1, [r2]
	movs r1, #0xe0
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r2, _08161BAC @ =0xFFFFFF00
	ldr r1, [r0]
	ands r1, r2
	str r1, [r0]
	bx lr
	.align 2, 0
_08161BA8: .4byte 0x000006DC
_08161BAC: .4byte 0xFFFFFF00

	thumb_func_start FUN_08161bb0
FUN_08161bb0: @ 0x08161BB0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08161BD2
	b _08161E94
_08161BD2:
	movs r2, #0x20
	movs r3, #0xe0
	lsls r3, r3, #3
	adds r1, r4, r3
	ldr r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _08161BE8
	movs r0, #1
	b _08161BEA
_08161BE8:
	movs r0, #0
_08161BEA:
	cmp r0, #0
	bne _08161BF0
	b _08161E94
_08161BF0:
	ldr r2, _08161CF8 @ =0x0000B007
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r1, r5, r6
	ldrh r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _08161C04
	b _08161E94
_08161C04:
	ldr r1, _08161CFC @ =0x000006DC
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _08161C12
	b _08161E94
_08161C12:
	ldr r3, _08161D00 @ =0x000001DF
	adds r0, r5, r3
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
	adds r0, r5, #0
	bl FUN_0815ca94
	movs r2, #0x10
	subs r6, #8
	adds r1, r5, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #2
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x3c
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r5, r6
	subs r6, #4
	adds r0, r5, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _08161D04 @ =0x00000551
	adds r0, r5, r3
	strb r2, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	ldr r4, _08161D08 @ =FUN_080e6794
	movs r1, #0xe
	subs r3, #0xe4
	adds r0, r5, r3
	movs r3, #1
	strb r3, [r0]
	subs r6, #0xe7
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r4, #0
	strh r2, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08161D0C @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _08161D10 @ =0x0000046C
	adds r0, r5, r2
	strb r3, [r0]
	mov r6, sp
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r2, [r0, #8]
	ldrh r1, [r2]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r6, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08161CF4
	cmp r1, #0
	blt _08161CF4
	ldr r0, _08161D14 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08161CF4
	ldr r0, _08161D18 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08161D1C
_08161CF4:
	movs r4, #0
	b _08161D2A
	.align 2, 0
_08161CF8: .4byte 0x0000B007
_08161CFC: .4byte 0x000006DC
_08161D00: .4byte 0x000001DF
_08161D04: .4byte 0x00000551
_08161D08: .4byte FUN_080e6794
_08161D0C: .4byte 0x00000469
_08161D10: .4byte 0x0000046C
_08161D14: .4byte 0x030046A8
_08161D18: .4byte 0x030046AC
_08161D1C:
	ldr r0, _08161D3C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08161D2A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08161D40
	adds r0, #4
	b _08161D4C
	.align 2, 0
_08161D3C: .4byte 0x030046A4
_08161D40:
	ldr r0, _08161D60 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08161D4C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08161D64
	cmp r2, #2
	beq _08161D68
	b _08161D6C
	.align 2, 0
_08161D60: .4byte 0x030046A4
_08161D64:
	ldrb r0, [r6, #4]
	b _08161D6A
_08161D68:
	ldrb r0, [r6]
_08161D6A:
	subs r1, r1, r0
_08161D6C:
	strh r1, [r6, #2]
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08161D96
	cmp r1, #0
	blt _08161D96
	ldr r0, _08161D9C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08161D96
	ldr r0, _08161DA0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08161DA4
_08161D96:
	movs r4, #0
	b _08161DB2
	.align 2, 0
_08161D9C: .4byte 0x030046A8
_08161DA0: .4byte 0x030046AC
_08161DA4:
	ldr r0, _08161DC8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08161DB2:
	adds r6, r5, #0
	adds r6, #8
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	adds r7, r6, #0
	cmp r0, #0
	beq _08161DCC
	adds r0, #4
	b _08161DD8
	.align 2, 0
_08161DC8: .4byte 0x030046A4
_08161DCC:
	ldr r0, _08161DEC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08161DD8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08161DF0
	cmp r2, #2
	beq _08161DF4
	b _08161DF8
	.align 2, 0
_08161DEC: .4byte 0x030046A4
_08161DF0:
	ldrb r0, [r6, #4]
	b _08161DF6
_08161DF4:
	ldrb r0, [r6]
_08161DF6:
	subs r1, r1, r0
_08161DF8:
	mov r0, sp
	strh r1, [r0, #2]
	ldr r3, _08161E1C @ =0x000004A4
	adds r0, r5, r3
	ldr r4, [r0]
	adds r0, r4, #0
	adds r1, r7, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _08161E24
	ldr r0, _08161E20 @ =0xFFFFFDFF
	mov r6, r8
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _08161E4C
	.align 2, 0
_08161E1C: .4byte 0x000004A4
_08161E20: .4byte 0xFFFFFDFF
_08161E24:
	adds r0, r4, #0
	adds r1, r7, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08161E42
	cmp r0, #2
	beq _08161E4C
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08161E4C
_08161E42:
	ldr r0, _08161E68 @ =0xFFFFFDFF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08161E4C:
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	movs r1, #0x20
	mov r6, sb
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08161E6C
	movs r0, #1
	b _08161E6E
	.align 2, 0
_08161E68: .4byte 0xFFFFFDFF
_08161E6C:
	movs r0, #0
_08161E6E:
	cmp r0, #0
	beq _08161E94
	movs r1, #0x21
	rsbs r1, r1, #0
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r5, r3
	adds r1, #0x1c
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r6, _08161EA4 @ =0x00000482
	adds r1, r5, r6
	movs r0, #1
	strh r0, [r1]
_08161E94:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08161EA4: .4byte 0x00000482

	thumb_func_start FUN_08161ea8
FUN_08161ea8: @ 0x08161EA8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r2, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r3, [r0]
	ldrb r0, [r2, #5]
	adds r0, #0x20
	asrs r1, r0, #6
	movs r0, #3
	ands r1, r0
	movs r5, #0
	cmp r1, #1
	beq _08161EF4
	cmp r1, #1
	bgt _08161ED2
	cmp r1, #0
	beq _08161EE4
	b _08161F18
_08161ED2:
	cmp r1, #2
	beq _08161F10
	cmp r1, #3
	beq _08161F28
	ldr r4, _08161EE0 @ =0x030046A4
	mov r8, r4
	b _08161F3C
	.align 2, 0
_08161EE0: .4byte 0x030046A4
_08161EE4:
	ldr r1, _08161EF0 @ =0x00000256
	adds r0, r2, r1
	ldrh r0, [r0]
	adds r5, r0, #1
	b _08161F18
	.align 2, 0
_08161EF0: .4byte 0x00000256
_08161EF4:
	ldr r4, _08161F08 @ =0x00000256
	adds r2, r2, r4
	ldr r1, _08161F0C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	ldrh r2, [r2]
	adds r5, r0, r2
	b _08161F3A
	.align 2, 0
_08161F08: .4byte 0x00000256
_08161F0C: .4byte 0x030046A4
_08161F10:
	ldr r1, _08161F20 @ =0x00000256
	adds r0, r2, r1
	ldrh r0, [r0]
	subs r5, r0, #1
_08161F18:
	ldr r2, _08161F24 @ =0x030046A4
	mov r8, r2
	b _08161F3C
	.align 2, 0
_08161F20: .4byte 0x00000256
_08161F24: .4byte 0x030046A4
_08161F28:
	ldr r4, _08161F7C @ =0x00000256
	adds r0, r2, r4
	ldrh r2, [r0]
	ldr r1, _08161F80 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	subs r5, r2, r0
_08161F3A:
	mov r8, r1
_08161F3C:
	movs r0, #0xd6
	lsls r0, r0, #3
	adds r6, r3, r0
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08161F84
	adds r0, #4
	b _08161F90
	.align 2, 0
_08161F7C: .4byte 0x00000256
_08161F80: .4byte 0x030046A4
_08161F84:
	mov r4, r8
	ldr r0, [r4]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08161F90:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r6, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08161fac
FUN_08161fac: @ 0x08161FAC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r7, [r0]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08161FC6
	b _081621C4
_08161FC6:
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r3, r4, r2
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	ble _08162012
	movs r2, #2
	movs r0, #0xe0
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0
	ldrsh r0, [r3, r2]
	adds r6, r1, #0
	cmp r0, #0
	blt _08161FF0
	asrs r2, r0, #9
	b _08161FF6
_08161FF0:
	rsbs r0, r0, #0
	asrs r0, r0, #9
	rsbs r2, r0, #0
_08161FF6:
	movs r3, #0xf0
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r1, [r0]
	adds r0, r2, #1
	muls r0, r1, r0
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r1, r4, r2
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	str r0, [r1]
	b _08162028
_08162012:
	movs r0, #0xe0
	lsls r0, r0, #3
	adds r2, r7, r0
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	subs r1, #2
	ands r0, r1
	str r0, [r2]
	adds r6, r2, #0
_08162028:
	ldr r2, _08162050 @ =0x0000A03F
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r4, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _08162058
	adds r0, r4, #0
	bl FUN_0815a0e8
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, _08162054 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _081620AA
	.align 2, 0
_08162050: .4byte 0x0000A03F
_08162054: .4byte 0xFFEFFFFF
_08162058:
	movs r1, #2
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08162066
	movs r0, #1
	b _08162068
_08162066:
	movs r0, #0
_08162068:
	cmp r0, #0
	beq _081620AA
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081620C8 @ =0x00000553
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r1, #0
	subs r0, #0x26
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081620AA
	adds r0, r1, #0
	cmp r0, #0x2d
	beq _081620AA
	cmp r0, #0x29
	beq _081620AA
	cmp r0, #0x2a
	beq _081620AA
	cmp r0, #0x22
	beq _081620AA
	cmp r0, #0x24
	beq _081620AA
	adds r0, r4, #0
	bl FUN_0815a224
_081620AA:
	movs r1, #0x84
	lsls r1, r1, #5
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081620B8
	b _081621C4
_081620B8:
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081620CC
	movs r0, #1
	b _081620CE
	.align 2, 0
_081620C8: .4byte 0x00000553
_081620CC:
	movs r0, #0
_081620CE:
	cmp r0, #0
	bne _081621C4
	movs r1, #0x80
	lsls r1, r1, #0x11
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081621C4
	movs r1, #0x10
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r5, [r0]
	ands r5, r1
	cmp r5, #0
	bne _081621C4
	ldr r1, _0816212C @ =0x00000553
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08162102
	cmp r0, #0x23
	bne _081621C4
_08162102:
	cmp r0, #0x23
	bne _0816213A
	movs r3, #0xd9
	lsls r3, r3, #3
	adds r2, r7, r3
	ldrh r1, [r2]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0
	bgt _08162134
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	ldr r1, _08162130 @ =0x000006EC
	adds r0, r7, r1
	ldrh r0, [r0]
	strh r0, [r2]
	b _081621C4
	.align 2, 0
_0816212C: .4byte 0x00000553
_08162130: .4byte 0x000006EC
_08162134:
	subs r0, r1, #1
	strh r0, [r2]
	b _081621C4
_0816213A:
	movs r2, #0xd9
	lsls r2, r2, #3
	adds r6, r7, r2
	ldrh r1, [r6]
	movs r3, #0
	ldrsh r0, [r6, r3]
	cmp r0, #0
	bgt _081621C0
	ldr r0, _081621A8 @ =FUN_08154de8
	mov ip, r0
	movs r1, #0x21
	ldr r2, _081621AC @ =0x0000046D
	adds r0, r4, r2
	movs r2, #1
	strb r2, [r0]
	ldr r3, _081621B0 @ =0x0000046B
	adds r0, r4, r3
	strb r5, [r0]
	adds r3, #0xe8
	adds r0, r4, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	mov r3, ip
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r3, #0
	mov ip, r3
	strh r5, [r0]
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _081621B4 @ =0x00000469
	adds r0, r4, r1
	strb r2, [r0]
	adds r3, #2
	adds r0, r4, r3
	mov r1, ip
	strb r1, [r0]
	adds r3, #0x1a
	adds r0, r4, r3
	str r5, [r0]
	ldr r1, _081621B8 @ =0x0000046C
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _081621BC @ =0x000006EE
	adds r0, r7, r2
	ldrh r0, [r0]
	b _081621C2
	.align 2, 0
_081621A8: .4byte FUN_08154de8
_081621AC: .4byte 0x0000046D
_081621B0: .4byte 0x0000046B
_081621B4: .4byte 0x00000469
_081621B8: .4byte 0x0000046C
_081621BC: .4byte 0x000006EE
_081621C0:
	subs r0, r1, #1
_081621C2:
	strh r0, [r6]
_081621C4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081621cc
FUN_081621cc: @ 0x081621CC
	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r4, [r1]
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0816223A
	ldr r3, _08162218 @ =0x000006E2
	adds r1, r4, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _081621F2
	subs r0, r2, #1
	strh r0, [r1]
_081621F2:
	ldr r0, _0816221C @ =0x000006E4
	adds r1, r4, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _08162204
	subs r0, r2, #1
	strh r0, [r1]
_08162204:
	movs r1, #0x40
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08162220
	movs r0, #1
	b _08162222
	.align 2, 0
_08162218: .4byte 0x000006E2
_0816221C: .4byte 0x000006E4
_08162220:
	movs r0, #0
_08162222:
	cmp r0, #0
	beq _0816223A
	movs r3, #0xdd
	lsls r3, r3, #3
	adds r1, r4, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _0816223A
	subs r0, r2, #1
	strh r0, [r1]
_0816223A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08162240
FUN_08162240: @ 0x08162240
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08162290
	ldr r1, _0816226C @ =0x00000553
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x26
	beq _0816225C
	cmp r0, #0x2a
	bne _08162270
_0816225C:
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r2, [r0]
	movs r3, #0x8c
	lsls r3, r3, #2
	b _0816227C
	.align 2, 0
_0816226C: .4byte 0x00000553
_08162270:
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r2, [r0]
	movs r3, #0x8b
	lsls r3, r3, #2
_0816227C:
	adds r0, r4, r3
	ldrh r1, [r0]
	movs r3, #0xb3
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r2, [r0]
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
_08162290:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08162298
FUN_08162298: @ 0x08162298
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0816230C
	movs r1, #0x20
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081622C4
	movs r0, #1
	b _081622C6
_081622C4:
	movs r0, #0
_081622C6:
	cmp r0, #0
	bne _081622DC
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r4, r3
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _0816230C
_081622DC:
	ldr r1, _08162314 @ =0x0000B007
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0816230C
	ldr r3, _08162318 @ =0x000006DC
	adds r1, r5, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _0816230C
	subs r0, r2, #1
	strh r0, [r1]
	movs r2, #4
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0816230C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08162314: .4byte 0x0000B007
_08162318: .4byte 0x000006DC

	thumb_func_start FUN_0816231c
FUN_0816231c: @ 0x0816231C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081623B6
	ldr r1, _0816234C @ =0x0000A7BF
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08162354
	ldr r3, _08162350 @ =0x00000704
	adds r0, r4, r3
	b _081623AC
	.align 2, 0
_0816234C: .4byte 0x0000A7BF
_08162350: .4byte 0x00000704
_08162354:
	movs r1, #0x22
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08162368
	movs r0, #1
	b _0816236A
_08162368:
	movs r0, #0
_0816236A:
	cmp r0, #0
	beq _08162378
	ldr r3, _08162374 @ =0x00000704
	adds r0, r4, r3
	b _081623AC
	.align 2, 0
_08162374: .4byte 0x00000704
_08162378:
	ldr r1, _081623A0 @ =0x00000704
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _081623B6
	movs r2, #0xd7
	lsls r2, r2, #3
	adds r1, r4, r2
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bge _081623A4
	adds r0, r5, #0
	bl FUN_0815f758
	b _081623A8
	.align 2, 0
_081623A0: .4byte 0x00000704
_081623A4:
	subs r0, r2, #1
	strh r0, [r1]
_081623A8:
	ldr r1, _081623BC @ =0x00000704
	adds r0, r4, r1
_081623AC:
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_081623B6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081623BC: .4byte 0x00000704

