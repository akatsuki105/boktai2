	.include "asm/macros.inc"

	.syntax unified
	
	.text

@ EnemyXXX_Create でファイル分けしているだけなので他の敵のコードも混じっているかもしれない

	thumb_func_start FUN_08102e20
FUN_08102e20: @ 0x08102E20
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08102E7E
	movs r1, #0x80
	lsls r1, r1, #4
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08102E7E
	ldr r1, _08102E88 @ =0x00000553
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x38
	bne _08102E7E
	ldr r0, _08102E8C @ =0x00000574
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r4, r1
	movs r1, #4
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r4, #0
	bl FUN_080ee538
	movs r1, #1
	mov r0, sp
	strh r1, [r0]
	adds r0, r4, #0
	mov r1, sp
	bl FUN_080e59d0
_08102E7E:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08102E88: .4byte 0x00000553
_08102E8C: .4byte 0x00000574

	thumb_func_start FUN_08102e90
FUN_08102e90: @ 0x08102E90
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08102EA6
	b _08103106
_08102EA6:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov sb, r0
	movs r1, #0x10
	movs r0, #0xe6
	lsls r0, r0, #3
	add r0, sb
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08102EC4
	movs r0, #1
	b _08102EC6
_08102EC4:
	movs r0, #0
_08102EC6:
	cmp r0, #0
	beq _08102ECC
	b _08103106
_08102ECC:
	ldr r0, _08102FF8 @ =0x0000A03F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r2, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _08102EE0
	b _08103106
_08102EE0:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r2, r0
	cmp r2, #0
	beq _08102EEC
	b _08103106
_08102EEC:
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r1, r4, r3
	movs r5, #0
	ldrsh r0, [r1, r5]
	adds r2, r0, #0
	muls r2, r0, r2
	movs r3, #2
	ldrsh r0, [r1, r3]
	adds r5, r0, #0
	muls r5, r0, r5
	adds r0, r5, #0
	adds r2, r2, r0
	movs r3, #4
	ldrsh r0, [r1, r3]
	adds r5, r0, #0
	muls r5, r0, r5
	adds r0, r5, #0
	cmn r2, r0
	beq _08102F16
	b _08103106
_08102F16:
	ldr r0, _08102FFC @ =0x00000724
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #0
	beq _08102F22
	b _08103106
_08102F22:
	ldr r0, _08103000 @ =0x0000072C
	add r0, sb
	ldrh r5, [r0]
	cmp r5, #0
	beq _08102F2E
	b _08103106
_08102F2E:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, _08103004 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	ldr r2, _08103008 @ =0x00000482
	adds r1, r4, r2
	movs r6, #0
	movs r0, #3
	strh r0, [r1]
	movs r7, #0x80
	mov r3, r8
	ldrh r0, [r3]
	ands r0, r7
	cmp r0, #0
	beq _08102F66
	movs r0, #4
	ldr r1, _0810300C @ =0x00000222
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08102F66:
	mov r2, r8
	ldrh r0, [r2]
	ands r0, r7
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _08103024
	movs r1, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r6, [r0]
	ldr r2, _08103010 @ =0x00000469
	adds r0, r4, r2
	strb r6, [r0]
	adds r3, #2
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _08103014 @ =0x00000484
	adds r0, r4, r1
	str r5, [r0]
	adds r2, #3
	adds r0, r4, r2
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r4, r3
	ldr r0, [r0]
	mov ip, r0
	movs r2, #0x1a
	ldr r3, _08103018 @ =0x0000046D
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _0810301C @ =0x0000046B
	adds r0, r4, r1
	strb r6, [r0]
	adds r3, #0xe6
	adds r0, r4, r3
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	mov r2, ip
	str r2, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r5, [r0]
	mov r5, r8
	ldrh r0, [r5]
	ands r0, r7
	cmp r0, #0
	beq _08103072
	ldr r0, _08103020 @ =0x0000024E
	adds r2, r4, r0
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r5, #0x93
	lsls r5, r5, #2
	adds r1, r4, r5
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _08103072
	strh r1, [r2]
	b _08103072
	.align 2, 0
_08102FF8: .4byte 0x0000A03F
_08102FFC: .4byte 0x00000724
_08103000: .4byte 0x0000072C
_08103004: .4byte 0x03002BE0
_08103008: .4byte 0x00000482
_0810300C: .4byte 0x00000222
_08103010: .4byte 0x00000469
_08103014: .4byte 0x00000484
_08103018: .4byte 0x0000046D
_0810301C: .4byte 0x0000046B
_08103020: .4byte 0x0000024E
_08103024:
	movs r1, #7
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r6, [r0]
	ldr r5, _081030B0 @ =0x00000469
	adds r0, r4, r5
	strb r6, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r5, #0x1b
	adds r0, r4, r5
	str r3, [r0]
	ldr r1, _081030B4 @ =0x0000046C
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r2, [r0]
	subs r5, #0x17
	adds r0, r4, r5
	strb r1, [r0]
	subs r5, #2
	adds r0, r4, r5
	strb r6, [r0]
	adds r5, #0xe8
	adds r0, r4, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r3, [r0]
_08103072:
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r4, r3
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	ldr r5, _081030B8 @ =0x000004A4
	adds r0, r4, r5
	ldr r6, [r0]
	adds r7, r4, #0
	adds r7, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	adds r5, r0, #0
	adds r5, #8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081030C0
	ldr r0, _081030BC @ =0xFFFFFDFF
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081030EA
	.align 2, 0
_081030B0: .4byte 0x00000469
_081030B4: .4byte 0x0000046C
_081030B8: .4byte 0x000004A4
_081030BC: .4byte 0xFFFFFDFF
_081030C0:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081030E0
	cmp r0, #2
	beq _081030DC
	adds r0, r4, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081030DC:
	movs r0, #1
	b _081030EC
_081030E0:
	ldr r0, _08103114 @ =0xFFFFFDFF
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081030EA:
	movs r0, #0
_081030EC:
	cmp r0, #0
	bne _081030FC
	ldr r5, _08103118 @ =0x000005C4
	adds r0, r4, r5
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_081030FC:
	ldr r1, _0810311C @ =0x0000072C
	add r1, sb
	movs r0, #0xb4
	lsls r0, r0, #1
	strh r0, [r1]
_08103106:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08103114: .4byte 0xFFFFFDFF
_08103118: .4byte 0x000005C4
_0810311C: .4byte 0x0000072C

	thumb_func_start FUN_08103120
FUN_08103120: @ 0x08103120
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r1, _081031B4 @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _08103220
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08103220
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ldr r6, _081031B8 @ =0x000007A4
	adds r0, r0, r6
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	strb r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r7, r5, r6
	ldrh r0, [r7]
	ands r0, r1
	cmp r0, #0
	bne _08103220
	ldr r2, _081031BC @ =0xFFFF0000
	ldrh r1, [r4, #6]
	lsls r1, r1, #0x10
	ldrh r0, [r4, #4]
	orrs r0, r1
	str r0, [sp]
	ldrh r1, [r4, #8]
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	ldr r1, _081031C0 @ =0x000004A4
	adds r0, r5, r1
	ldr r4, [r0]
	adds r6, r5, #0
	adds r6, #8
	adds r0, r4, #0
	adds r1, r6, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	beq _081031C4
	adds r0, r4, #0
	adds r1, r6, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081031C4
	cmp r0, #2
	beq _081031AE
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081031AE:
	movs r0, #1
	b _081031CE
	.align 2, 0
_081031B4: .4byte 0x000001DF
_081031B8: .4byte 0x000007A4
_081031BC: .4byte 0xFFFF0000
_081031C0: .4byte 0x000004A4
_081031C4:
	ldr r0, _08103228 @ =0xFFFFFDFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r0, #0
_081031CE:
	cmp r0, #0
	beq _08103220
	ldr r3, _0810322C @ =FUN_080e48d0
	movs r1, #0x10
	ldr r2, _08103230 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _08103234 @ =0x0000046B
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
	movs r3, #0x12
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08103238 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r4, [r0]
_08103220:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08103228: .4byte 0xFFFFFDFF
_0810322C: .4byte FUN_080e48d0
_08103230: .4byte 0x0000046D
_08103234: .4byte 0x0000046B
_08103238: .4byte 0x0000046A

	thumb_func_start FUN_0810323c
FUN_0810323c: @ 0x0810323C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, _08103288 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _08103298
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08103298
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r1, [r0]
	ldr r2, _0810328C @ =0x00000714
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _08103298
	subs r2, #6
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08103298
	ldr r0, _08103290 @ =0x0000070D
	adds r2, r1, r0
	ldrb r3, [r2]
	ldrh r1, [r5, #2]
	adds r0, r3, r1
	cmp r0, #6
	ble _08103294
	movs r0, #6
	b _08103296
	.align 2, 0
_08103288: .4byte 0x000001DF
_0810328C: .4byte 0x00000714
_08103290: .4byte 0x0000070D
_08103294:
	adds r0, r3, r1
_08103296:
	strb r0, [r2]
_08103298:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081032a0
FUN_081032a0: @ 0x081032A0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r2, _081032B8 @ =0x000001DF
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #6
	beq _081032CA
	cmp r0, #6
	bgt _081032BC
	cmp r0, #5
	beq _081032C2
	b _0810333A
	.align 2, 0
_081032B8: .4byte 0x000001DF
_081032BC:
	cmp r0, #7
	beq _081032D4
	b _0810333A
_081032C2:
	movs r6, #0xeb
	lsls r6, r6, #3
	adds r1, r1, r6
	b _081032DA
_081032CA:
	movs r0, #0xeb
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r0, #0x3c
	b _081032DC
_081032D4:
	movs r2, #0xeb
	lsls r2, r2, #3
	adds r1, r1, r2
_081032DA:
	movs r0, #0x78
_081032DC:
	strh r0, [r1]
	ldr r3, _08103340 @ =FUN_08109220
	movs r1, #0x37
	ldr r6, _08103344 @ =0x0000046D
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
	ldr r1, _08103348 @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _0810334C @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	movs r6, #0xc1
	lsls r6, r6, #1
	adds r2, r5, r6
	ldr r0, _08103350 @ =0xFFFFF636
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0810333A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08103340: .4byte FUN_08109220
_08103344: .4byte 0x0000046D
_08103348: .4byte 0x00000469
_0810334C: .4byte 0x0000046C
_08103350: .4byte 0xFFFFF636

	thumb_func_start FUN_08103354
FUN_08103354: @ 0x08103354
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r5, [r0]
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r3, r2
	ldr r4, [r0]
	cmp r4, #0
	beq _08103404
	movs r6, #0xeb
	lsls r6, r6, #3
	adds r0, r5, r6
	ldrh r0, [r0]
	cmp r0, #0
	bne _08103404
	movs r1, #0x80
	lsls r1, r1, #0x14
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r3, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08103404
	movs r6, #0xe0
	lsls r6, r6, #1
	adds r1, r3, r6
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	movs r6, #2
	ldrsh r0, [r1, r6]
	adds r6, r0, #0
	muls r6, r0, r6
	adds r0, r6, #0
	adds r2, r2, r0
	movs r6, #4
	ldrsh r0, [r1, r6]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	cmn r2, r0
	bne _08103404
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r3, r2
	ldr r1, [r0]
	movs r0, #0x90
	lsls r0, r0, #0xa
	cmp r1, r0
	bhi _08103404
	ldrb r1, [r4, #5]
	ldrb r0, [r3, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _081033D8
	ldr r6, _081033D4 @ =0xFFFFFF00
	adds r1, r1, r6
	b _081033E6
	.align 2, 0
_081033D4: .4byte 0xFFFFFF00
_081033D8:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081033E6
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_081033E6:
	adds r0, r1, #0
	cmp r0, #0
	bge _081033EE
	rsbs r0, r0, #0
_081033EE:
	cmp r0, #0x3f
	ble _08103404
	ldr r1, _08103400 @ =0x00000724
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08103404
	movs r0, #1
	b _08103406
	.align 2, 0
_08103400: .4byte 0x00000724
_08103404:
	movs r0, #0
_08103406:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0810340c
FUN_0810340c: @ 0x0810340C
	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r2, #0xeb
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08103426
	subs r0, #1
	strh r0, [r1]
_08103426:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0810342c
FUN_0810342c: @ 0x0810342C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _081034B8 @ =0x00000724
	adds r0, r1, r2
	movs r6, #0
	strb r6, [r0]
	adds r2, #0x34
	adds r0, r1, r2
	movs r5, #0
	strh r6, [r0]
	ldr r2, _081034BC @ =0x00000574
	adds r0, r4, r2
	ldr r0, [r0]
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r1, r1, r2
	strh r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #8
	bl ClearMemory
	ldr r1, _081034C0 @ =0x08251FE4
	adds r0, r4, #0
	ldr r2, _081034C4 @ =0x0000010B
	bl FUN_080e6768
	adds r0, r4, #0
	bl FUN_080e6204
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	adds r0, r4, #0
	adds r0, #0x9c
	adds r1, r4, #0
	adds r1, #8
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_08235038
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081034CC
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
	ldr r1, _081034C8 @ =0x00000484
	adds r0, r4, r1
	str r6, [r0]
	adds r2, #2
	adds r1, r4, r2
	b _081034EA
	.align 2, 0
_081034B8: .4byte 0x00000724
_081034BC: .4byte 0x00000574
_081034C0: .4byte 0x08251FE4
_081034C4: .4byte 0x0000010B
_081034C8: .4byte 0x00000484
_081034CC:
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #0x1a
	adds r0, r4, r2
	str r1, [r0]
	ldr r0, _08103500 @ =0x0000046C
	adds r1, r4, r0
_081034EA:
	movs r0, #1
	strb r0, [r1]
	ldr r1, [r4, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08103500: .4byte 0x0000046C

	thumb_func_start FUN_08103504
FUN_08103504: @ 0x08103504
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #0x4c
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r4, _08103608 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r4
	movs r6, #0x80
	orrs r0, r6
	ldr r1, _0810360C @ =0x0000FFFF
	mov sb, r1
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	mov r8, r1
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r4
	orrs r0, r6
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r4
	str r0, [r3, #4]
	ldr r2, _08103610 @ =0x0000410B
	movs r1, #0xcb
	lsls r1, r1, #3
	add r1, sl
	ldr r0, _08103614 @ =FUN_08109118
	str r0, [sp]
	str r5, [sp, #4]
	str r2, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	bl FUN_080e391c
	ldr r0, [sp, #0x1c]
	ands r0, r4
	orrs r0, r6
	mov r1, sb
	ands r0, r1
	mov r1, r8
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r1, sp, #0x1c
	ldr r0, [r1, #4]
	ands r0, r4
	orrs r0, r6
	str r0, [r1, #4]
	mov r0, r8
	str r0, [sp, #0x24]
	add r2, sp, #0x24
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _08103618 @ =FUN_08108a1c
	str r5, [sp]
	adds r0, r5, #0
	bl FUN_080e3834
	ldr r0, [sp, #0x2c]
	ands r0, r4
	movs r2, #0x40
	orrs r0, r2
	mov r1, sb
	ands r0, r1
	movs r6, #0xc8
	lsls r6, r6, #0xf
	orrs r0, r6
	str r0, [sp, #0x2c]
	add r1, sp, #0x2c
	ldr r0, [r1, #4]
	ands r0, r4
	orrs r0, r2
	str r0, [r1, #4]
	mov r0, r8
	str r0, [sp, #0x34]
	add r2, sp, #0x34
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _0810361C @ =FUN_08108908
	movs r0, #0
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r5, #0
	bl FUN_080e3984
	str r6, [sp, #0x3c]
	add r2, sp, #0x3c
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	mov r1, r8
	str r1, [sp, #0x44]
	add r3, sp, #0x44
	ldr r0, [r3, #4]
	ands r0, r4
	str r0, [r3, #4]
	movs r0, #0xd5
	lsls r0, r0, #3
	add sl, r0
	ldr r0, _08103620 @ =FUN_081089a4
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	str r5, [sp, #8]
	adds r0, r5, #0
	mov r1, sl
	bl FUN_080e3a14
	add sp, #0x4c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08103608: .4byte 0xFFFF0000
_0810360C: .4byte 0x0000FFFF
_08103610: .4byte 0x0000410B
_08103614: .4byte FUN_08109118
_08103618: .4byte FUN_08108a1c
_0810361C: .4byte FUN_08108908
_08103620: .4byte FUN_081089a4

	thumb_func_start FUN_08103624
FUN_08103624: @ 0x08103624
	push {r4, r5, lr}
	sub sp, #8
	mov ip, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, ip
	ldr r0, [r0]
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r0, r0, r2
	lsls r4, r1, #1
	movs r2, #0x89
	lsls r2, r2, #2
	add r2, ip
	adds r2, r2, r4
	ldrh r5, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	add r2, ip
	adds r2, r2, r4
	ldrh r2, [r2]
	lsls r1, r1, #2
	movs r3, #0x8f
	lsls r3, r3, #2
	add r3, ip
	adds r3, r3, r1
	ldr r1, [r3]
	str r1, [sp]
	movs r1, #0x8d
	lsls r1, r1, #2
	add r1, ip
	adds r1, r1, r4
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r1, r5, #0
	movs r3, #0
	bl FUN_082364f8
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08103678
FUN_08103678: @ 0x08103678
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
	beq _08103694
	b _0810387A
_08103694:
	ldr r2, _081036AC @ =0x000001DF
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #8
	bne _081036B4
	ldr r0, _081036B0 @ =0x0000065E
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	b _0810387A
	.align 2, 0
_081036AC: .4byte 0x000001DF
_081036B0: .4byte 0x0000065E
_081036B4:
	movs r1, #0x80
	lsls r1, r1, #4
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081036C8
	b _0810387A
_081036C8:
	ldr r1, _08103704 @ =0x00000553
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x38
	bne _081036D4
	b _0810387A
_081036D4:
	cmp r0, #0x3c
	bne _081036DA
	b _0810387A
_081036DA:
	ldr r2, _08103708 @ =0x00000724
	adds r3, r5, r2
	ldrb r0, [r3]
	cmp r0, #0
	beq _08103710
	adds r2, r4, #0
	adds r2, #0xde
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0810370C @ =0x0000065E
	adds r2, r5, r0
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
	b _08103728
	.align 2, 0
_08103704: .4byte 0x00000553
_08103708: .4byte 0x00000724
_0810370C: .4byte 0x0000065E
_08103710:
	adds r3, r4, #0
	adds r3, #0xde
	ldrh r2, [r3]
	ldr r1, _0810375C @ =0x0000FFFB
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	ldr r0, _08103760 @ =0x0000065E
	adds r2, r5, r0
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
_08103728:
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r5, r1
	mov r1, sp
	movs r2, #0
	bl FUN_082364c4
	ldr r2, _08103764 @ =0x085B0A08
	ldrb r0, [r4, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #7
	cmp r0, #0
	blt _08103768
	asrs r1, r0, #0xc
	b _0810376E
	.align 2, 0
_0810375C: .4byte 0x0000FFFB
_08103760: .4byte 0x0000065E
_08103764: .4byte 0x085B0A08
_08103768:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810376E:
	mov r0, sp
	ldrh r0, [r0]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldr r1, _08103790 @ =0x085B0A08
	ldrb r2, [r4, #5]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	cmp r0, #0
	blt _08103794
	asrs r3, r0, #0xc
	b _0810379A
	.align 2, 0
_08103790: .4byte 0x085B0A08
_08103794:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0810379A:
	mov r1, sp
	ldrh r0, [r1, #4]
	adds r0, r0, r3
	strh r0, [r1, #4]
	adds r0, r2, #0
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	cmp r0, #1
	beq _08103808
	cmp r0, #1
	bgt _081037BA
	cmp r0, #0
	beq _081037C4
	b _08103848
_081037BA:
	cmp r0, #2
	beq _081037C4
	cmp r0, #3
	beq _08103808
	b _08103848
_081037C4:
	ldr r2, _081037E4 @ =0x000001DF
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #6
	bne _081037EC
	ldr r3, _081037E8 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r1, #0xb4
	orrs r0, r1
	str r0, [sp, #8]
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x54
	b _08103844
	.align 2, 0
_081037E4: .4byte 0x000001DF
_081037E8: .4byte 0xFFFF0000
_081037EC:
	ldr r3, _08103804 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r1, #0xa0
	orrs r0, r1
	str r0, [sp, #8]
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x40
	b _08103844
	.align 2, 0
_08103804: .4byte 0xFFFF0000
_08103808:
	ldr r1, _08103828 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _08103830
	ldr r3, _0810382C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r1, #0x54
	orrs r0, r1
	str r0, [sp, #8]
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0xb4
	b _08103844
	.align 2, 0
_08103828: .4byte 0x000001DF
_0810382C: .4byte 0xFFFF0000
_08103830:
	ldr r3, _08103884 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r1, #0x40
	orrs r0, r1
	str r0, [sp, #8]
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0xa0
_08103844:
	orrs r0, r1
	str r0, [r2, #4]
_08103848:
	ldr r1, _08103888 @ =0x0000FFFF
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #8]
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	mov r1, sp
	movs r2, #0
	bl FUN_082364c4
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r5, r1
	mov r1, sp
	movs r2, #0
	bl FUN_082364c4
_0810387A:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08103884: .4byte 0xFFFF0000
_08103888: .4byte 0x0000FFFF

	thumb_func_start FUN_0810388c
FUN_0810388c: @ 0x0810388C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _081038A4 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #6
	beq _08103972
	cmp r0, #6
	bgt _081038A8
	cmp r0, #5
	beq _081038B6
	b _08103C10
	.align 2, 0
_081038A4: .4byte 0x000001DF
_081038A8:
	cmp r0, #7
	bne _081038AE
	b _08103A6A
_081038AE:
	cmp r0, #8
	bne _081038B4
	b _08103B68
_081038B4:
	b _08103C10
_081038B6:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #6
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0xc
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0x1e
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xe
	movs r2, #0x38
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #0x3a
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #0x3c
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xb
	movs r2, #0x4a
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #6
	movs r2, #0x50
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xc
	movs r2, #0x4a
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0x50
	movs r3, #4
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0x60
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0x72
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #0x68
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #0x6a
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xd
	movs r2, #0x6c
	b _08103B60
_08103972:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #8
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0xe
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0x21
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xe
	movs r2, #0x3e
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #0x40
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #0x42
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xb
	movs r2, #0x4c
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #6
	movs r2, #0x54
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xc
	movs r2, #0x4c
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0x54
	movs r3, #4
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0x62
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0x72
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x13
	movs r2, #0x7e
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0x80
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x15
	movs r2, #0x82
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #0x84
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #0x86
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #0x68
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #0x6a
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xd
	movs r2, #0x6e
	b _08103B60
_08103A6A:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #4
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0xa
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0x10
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0x27
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xe
	movs r2, #0x44
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #0x46
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #0x48
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xb
	movs r2, #0x4e
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #6
	movs r2, #0x58
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0x5a
	movs r3, #4
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xc
	movs r2, #0x4e
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0x64
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0x72
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x13
	movs r2, #0x12
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0x14
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x15
	movs r2, #0x16
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #0x8c
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #0x8e
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #0x68
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #0x6a
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xd
	movs r2, #0x70
_08103B60:
	movs r3, #0
	bl FUN_080ef84c
	b _08103C10
_08103B68:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x7c
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0x36
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0x2d
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0x88
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #6
	movs r2, #0x5c
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0x5e
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0x66
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0x74
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x13
	movs r2, #0x18
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0x1a
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x15
	movs r2, #0x1c
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #0x88
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #0x8a
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x18
	movs r2, #0x88
	movs r3, #4
	bl FUN_080ef84c
_08103C10:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08103c18
FUN_08103c18: @ 0x08103C18
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r3, [r0]
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r6, _08103C94 @ =0x0000075C
	adds r1, r3, r6
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bls _08103CA8
	movs r1, #0xec
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r0, [r0]
	cmp r2, r0
	bhs _08103CA8
	ldr r3, _08103C98 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r2, _08103C9C @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _08103CA0 @ =0x0000046B
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
	ldr r1, _08103CA4 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	movs r0, #1
	b _08103CAA
	.align 2, 0
_08103C94: .4byte 0x0000075C
_08103C98: .4byte FUN_080e48d0
_08103C9C: .4byte 0x0000046D
_08103CA0: .4byte 0x0000046B
_08103CA4: .4byte 0x0000046A
_08103CA8:
	movs r0, #0
_08103CAA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08103cb0
FUN_08103cb0: @ 0x08103CB0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r1, [r0]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _08103CEC
	ldr r6, _08103CE8 @ =0xFFFFFF00
	adds r1, r1, r6
	b _08103CFA
	.align 2, 0
_08103CE8: .4byte 0xFFFFFF00
_08103CEC:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08103CFA
	movs r7, #0x80
	lsls r7, r7, #1
	adds r1, r1, r7
_08103CFA:
	cmp r1, #0
	bge _08103D00
	rsbs r1, r1, #0
_08103D00:
	adds r7, r1, #0
	ldr r1, _08103D14 @ =0x000006FC
	adds r0, r4, r1
	movs r1, #0xc
	ldrh r0, [r0, #0x26]
	ands r0, r1
	cmp r0, #0
	beq _08103D18
	movs r0, #1
	b _08103D1A
	.align 2, 0
_08103D14: .4byte 0x000006FC
_08103D18:
	movs r0, #0
_08103D1A:
	adds r6, r0, #0
	cmp r6, #0
	beq _08103D22
	b _081041F6
_08103D22:
	adds r0, r5, #0
	bl FUN_081058f4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08103DFA
	ldr r2, _08103DB8 @ =0x00000716
	adds r2, r2, r4
	mov r8, r2
	ldrh r0, [r2]
	cmp r0, #0
	beq _08103D3C
	b _081041F6
_08103D3C:
	adds r1, r7, #0
	cmp r1, #0
	bge _08103D44
	rsbs r1, r1, #0
_08103D44:
	cmp r1, #0x1f
	bgt _08103DD4
	ldrb r1, [r5, #5]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #0x80
	strb r0, [r5, #5]
	adds r0, r5, #0
	bl FUN_08105db4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08103D64
	b _081041F6
_08103D64:
	ldr r2, _08103DBC @ =FUN_080e48d0
	movs r1, #0x10
	ldr r4, _08103DC0 @ =0x0000046D
	adds r0, r5, r4
	movs r3, #1
	strb r3, [r0]
	ldr r7, _08103DC4 @ =0x0000046B
	adds r0, r5, r7
	strb r6, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r6, [r0]
	movs r2, #0x12
	subs r4, #0xeb
	adds r0, r5, r4
	strb r1, [r0]
	ldr r7, _08103DC8 @ =0x00000469
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _08103DCC @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _08103DD0 @ =0x00000484
	adds r0, r5, r2
	str r6, [r0]
	adds r4, #4
	adds r0, r5, r4
	strb r3, [r0]
	movs r0, #0x78
	mov r6, r8
	strh r0, [r6]
	b _081041F6
	.align 2, 0
_08103DB8: .4byte 0x00000716
_08103DBC: .4byte FUN_080e48d0
_08103DC0: .4byte 0x0000046D
_08103DC4: .4byte 0x0000046B
_08103DC8: .4byte 0x00000469
_08103DCC: .4byte 0x0000046A
_08103DD0: .4byte 0x00000484
_08103DD4:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r7, #0xe6
	lsls r7, r7, #3
	adds r0, r4, r7
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08103DEA
	movs r0, #1
	b _08103DEC
_08103DEA:
	movs r0, #0
_08103DEC:
	cmp r0, #0
	beq _08103DF2
	b _081041F6
_08103DF2:
	adds r0, r5, #0
	bl FUN_081075dc
	b _081041F6
_08103DFA:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _08103E24 @ =0x00000546
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r1, r0
	blt _08103E10
	b _08103FFA
_08103E10:
	ldr r7, _08103E28 @ =0x00000744
	adds r0, r4, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _08103E30
	ldr r2, _08103E2C @ =FUN_080e48d0
	movs r1, #0x10
	subs r3, #0xd9
	b _0810400C
	.align 2, 0
_08103E24: .4byte 0x00000546
_08103E28: .4byte 0x00000744
_08103E2C: .4byte FUN_080e48d0
_08103E30:
	bl FUN_081f95f4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08103F08
	ldr r7, _08103E84 @ =0x00000746
	adds r0, r4, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _08103F08
	ldr r3, _08103E88 @ =0x000006FC
	adds r2, r4, r3
	movs r0, #4
	ldrh r1, [r2, #0x26]
	orrs r0, r1
	strh r0, [r2, #0x26]
	adds r4, r5, #0
	adds r4, #8
	movs r3, #0x80
	lsls r3, r3, #0xb
	str r6, [sp]
	adds r0, r5, #0
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081078d8
	ldr r6, _08103E8C @ =0x000004A4
	adds r0, r5, r6
	ldr r6, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	add r2, sp, #4
	bl FUN_0823599c
	cmp r0, #0
	bne _08103E90
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r0, r5, r7
	b _08103EB4
	.align 2, 0
_08103E84: .4byte 0x00000746
_08103E88: .4byte 0x000006FC
_08103E8C: .4byte 0x000004A4
_08103E90:
	adds r0, r6, #0
	adds r1, r4, #0
	add r2, sp, #4
	bl FUN_08235f40
	cmp r0, #0
	beq _08103EAE
	cmp r0, #2
	beq _08103EBC
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08103EBC
_08103EAE:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
_08103EB4:
	ldr r1, _08103EF0 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_08103EBC:
	movs r1, #0x15
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	movs r2, #0
	strb r2, [r0]
	ldr r3, _08103EF4 @ =0x00000469
	adds r0, r5, r3
	strb r2, [r0]
	ldr r4, _08103EF8 @ =0x0000046A
	adds r0, r5, r4
	strb r1, [r0]
	ldr r6, _08103EFC @ =0x00000484
	adds r0, r5, r6
	str r2, [r0]
	ldr r7, _08103F00 @ =0x0000046C
	adds r0, r5, r7
	movs r1, #1
	strb r1, [r0]
	ldr r4, _08103F04 @ =FUN_080e48d0
	movs r3, #0x10
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	subs r7, #1
	b _0810413A
	.align 2, 0
_08103EF0: .4byte 0xFFFFFDFF
_08103EF4: .4byte 0x00000469
_08103EF8: .4byte 0x0000046A
_08103EFC: .4byte 0x00000484
_08103F00: .4byte 0x0000046C
_08103F04: .4byte FUN_080e48d0
_08103F08:
	movs r6, #0xe9
	lsls r6, r6, #3
	adds r0, r4, r6
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #0
	bgt _08103FE4
	adds r0, r5, #0
	bl FUN_0810634c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08103FE4
	ldr r0, _08103F64 @ =0x000006FC
	adds r2, r4, r0
	movs r0, #8
	ldrh r1, [r2, #0x26]
	movs r4, #0
	orrs r0, r1
	strh r0, [r2, #0x26]
	add r7, sp, #0xc
	adds r6, r5, #0
	adds r6, #8
	movs r3, #0x80
	lsls r3, r3, #0xb
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl FUN_081078d8
	ldr r1, _08103F68 @ =0x000004A4
	adds r0, r5, r1
	ldr r4, [r0]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08103F6C
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _08103F90
	.align 2, 0
_08103F64: .4byte 0x000006FC
_08103F68: .4byte 0x000004A4
_08103F6C:
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08103F8A
	cmp r0, #2
	beq _08103F98
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08103F98
_08103F8A:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
_08103F90:
	ldr r1, _08103FCC @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_08103F98:
	movs r1, #0x15
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	movs r2, #0
	strb r2, [r0]
	ldr r6, _08103FD0 @ =0x00000469
	adds r0, r5, r6
	strb r2, [r0]
	ldr r7, _08103FD4 @ =0x0000046A
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _08103FD8 @ =0x00000484
	adds r0, r5, r1
	str r2, [r0]
	ldr r3, _08103FDC @ =0x0000046C
	adds r0, r5, r3
	movs r1, #1
	strb r1, [r0]
	ldr r4, _08103FE0 @ =FUN_080e48d0
	movs r3, #0x10
	adds r6, #4
	adds r0, r5, r6
	strb r1, [r0]
	adds r7, #1
	b _0810413A
	.align 2, 0
_08103FCC: .4byte 0xFFFFFDFF
_08103FD0: .4byte 0x00000469
_08103FD4: .4byte 0x0000046A
_08103FD8: .4byte 0x00000484
_08103FDC: .4byte 0x0000046C
_08103FE0: .4byte FUN_080e48d0
_08103FE4:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r6, #0xe6
	lsls r6, r6, #3
	adds r0, r4, r6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08103FF8
	b _08104186
_08103FF8:
	b _0810418A
_08103FFA:
	ldr r7, _08104058 @ =0x00000744
	adds r0, r4, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _08104078
	ldr r2, _0810405C @ =FUN_080e48d0
	movs r1, #0x10
	ldr r3, _08104060 @ =0x0000046D
_0810400C:
	adds r0, r5, r3
	movs r4, #1
	strb r4, [r0]
	ldr r7, _08104064 @ =0x0000046B
	adds r0, r5, r7
	strb r6, [r0]
	adds r3, #0xe6
	adds r0, r5, r3
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r6, [r0]
	movs r2, #2
	movs r3, #7
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _08104068 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _0810406C @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	ldr r3, _08104070 @ =0x00000484
	adds r0, r5, r3
	str r6, [r0]
	ldr r6, _08104074 @ =0x0000046C
	adds r0, r5, r6
	strb r4, [r0]
	b _081041F6
	.align 2, 0
_08104058: .4byte 0x00000744
_0810405C: .4byte FUN_080e48d0
_08104060: .4byte 0x0000046D
_08104064: .4byte 0x0000046B
_08104068: .4byte 0x00000469
_0810406C: .4byte 0x0000046A
_08104070: .4byte 0x00000484
_08104074: .4byte 0x0000046C
_08104078:
	bl FUN_081f95f4
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	bne _08104174
	ldr r1, _081040D0 @ =0x00000746
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _08104174
	ldr r3, _081040D4 @ =0x000006FC
	adds r2, r4, r3
	movs r0, #4
	ldrh r1, [r2, #0x26]
	orrs r0, r1
	strh r0, [r2, #0x26]
	add r6, sp, #0x14
	adds r4, r5, #0
	adds r4, #8
	movs r3, #0x80
	lsls r3, r3, #0xb
	str r7, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_081078d8
	ldr r7, _081040D8 @ =0x000004A4
	adds r0, r5, r7
	ldr r7, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081040DC
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
	b _08104100
	.align 2, 0
_081040D0: .4byte 0x00000746
_081040D4: .4byte 0x000006FC
_081040D8: .4byte 0x000004A4
_081040DC:
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081040FA
	cmp r0, #2
	beq _08104108
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08104108
_081040FA:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
_08104100:
	ldr r1, _08104158 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_08104108:
	movs r1, #0x15
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r2, #0
	strb r2, [r0]
	ldr r4, _0810415C @ =0x00000469
	adds r0, r5, r4
	strb r2, [r0]
	ldr r6, _08104160 @ =0x0000046A
	adds r0, r5, r6
	strb r1, [r0]
	ldr r7, _08104164 @ =0x00000484
	adds r0, r5, r7
	str r2, [r0]
	ldr r1, _08104168 @ =0x0000046C
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	ldr r4, _0810416C @ =FUN_080e48d0
	movs r3, #0x10
	adds r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	subs r7, #0x19
_0810413A:
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _08104170 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
	b _081041F6
	.align 2, 0
_08104158: .4byte 0xFFFFFDFF
_0810415C: .4byte 0x00000469
_08104160: .4byte 0x0000046A
_08104164: .4byte 0x00000484
_08104168: .4byte 0x0000046C
_0810416C: .4byte FUN_080e48d0
_08104170: .4byte 0x00000553
_08104174:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r6, #0xe6
	lsls r6, r6, #3
	adds r0, r4, r6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0810418A
_08104186:
	movs r0, #1
	b _0810418C
_0810418A:
	movs r0, #0
_0810418C:
	adds r4, r0, #0
	cmp r4, #0
	bne _081041F6
	ldrb r1, [r5, #5]
	movs r7, #0xfe
	lsls r7, r7, #1
	adds r0, r5, r7
	ldrb r0, [r0]
	adds r0, #0x80
	strb r0, [r5, #5]
	adds r0, r5, #0
	bl FUN_08105db4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081041F6
	ldr r2, _08104204 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r3, _08104208 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _0810420C @ =0x0000046B
	adds r0, r5, r6
	strb r4, [r0]
	ldr r7, _08104210 @ =0x00000553
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r1, #0
	strh r4, [r0]
	movs r2, #0x12
	subs r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	subs r7, #0xea
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _08104214 @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _08104218 @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	ldr r4, _0810421C @ =0x0000046C
	adds r0, r5, r4
	strb r3, [r0]
_081041F6:
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08104204: .4byte FUN_080e48d0
_08104208: .4byte 0x0000046D
_0810420C: .4byte 0x0000046B
_08104210: .4byte 0x00000553
_08104214: .4byte 0x0000046A
_08104218: .4byte 0x00000484
_0810421C: .4byte 0x0000046C

	thumb_func_start FUN_08104220
FUN_08104220: @ 0x08104220
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r1, [r0]
	ldrb r0, [r6, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _08104258
	ldr r4, _08104254 @ =0xFFFFFF00
	adds r1, r1, r4
	b _08104266
	.align 2, 0
_08104254: .4byte 0xFFFFFF00
_08104258:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08104266
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r1, r5
_08104266:
	adds r4, r1, #0
	cmp r4, #0
	bge _0810426E
	rsbs r4, r4, #0
_0810426E:
	adds r0, r6, #0
	bl FUN_081058f4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08104346
	ldr r0, _08104304 @ =0x00000716
	adds r0, r0, r7
	mov r8, r0
	ldrh r5, [r0]
	cmp r5, #0
	beq _08104288
	b _0810463A
_08104288:
	adds r1, r4, #0
	cmp r1, #0
	bge _08104290
	rsbs r1, r1, #0
_08104290:
	cmp r1, #0x1f
	bgt _08104320
	ldrb r1, [r6, #5]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	adds r0, #0x80
	strb r0, [r6, #5]
	adds r0, r6, #0
	bl FUN_08105db4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081042B0
	b _0810463A
_081042B0:
	ldr r2, _08104308 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r3, _0810430C @ =0x0000046D
	adds r0, r6, r3
	movs r3, #1
	strb r3, [r0]
	ldr r4, _08104310 @ =0x0000046B
	adds r0, r6, r4
	strb r5, [r0]
	ldr r7, _08104314 @ =0x00000553
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r5, [r0]
	movs r2, #0x12
	subs r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	subs r7, #0xea
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _08104318 @ =0x0000046A
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _0810431C @ =0x00000484
	adds r0, r6, r2
	str r5, [r0]
	adds r4, #4
	adds r0, r6, r4
	strb r3, [r0]
	movs r0, #0x78
	mov r5, r8
	strh r0, [r5]
	b _0810463A
	.align 2, 0
_08104304: .4byte 0x00000716
_08104308: .4byte FUN_080e48d0
_0810430C: .4byte 0x0000046D
_08104310: .4byte 0x0000046B
_08104314: .4byte 0x00000553
_08104318: .4byte 0x0000046A
_0810431C: .4byte 0x00000484
_08104320:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08104336
	movs r0, #1
	b _08104338
_08104336:
	movs r0, #0
_08104338:
	cmp r0, #0
	beq _0810433E
	b _0810463A
_0810433E:
	adds r0, r6, #0
	bl FUN_081075dc
	b _0810463A
_08104346:
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	ldr r5, _081043D8 @ =0x00000546
	adds r0, r6, r5
	ldrh r0, [r0]
	cmp r1, r0
	blt _0810435C
	b _0810449A
_0810435C:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0xe7
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _081043FC
	ldr r3, _081043DC @ =0x00000746
	adds r0, r7, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	bgt _081043FC
	bl FUN_081f460c
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _081043FC
	ldr r2, _081043E0 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r7, _081043E4 @ =0x0000046D
	adds r0, r6, r7
	movs r4, #1
	strb r4, [r0]
	ldr r3, _081043E8 @ =0x0000046B
	adds r0, r6, r3
	strb r5, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r5, [r0]
	movs r2, #2
	movs r3, #5
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081043EC @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081043F0 @ =0x0000046A
	adds r0, r6, r2
	strb r3, [r0]
	ldr r3, _081043F4 @ =0x00000484
	adds r0, r6, r3
	str r5, [r0]
	ldr r5, _081043F8 @ =0x0000046C
	adds r0, r6, r5
	strb r4, [r0]
	b _0810463A
	.align 2, 0
_081043D8: .4byte 0x00000546
_081043DC: .4byte 0x00000746
_081043E0: .4byte FUN_080e48d0
_081043E4: .4byte 0x0000046D
_081043E8: .4byte 0x0000046B
_081043EC: .4byte 0x00000469
_081043F0: .4byte 0x0000046A
_081043F4: .4byte 0x00000484
_081043F8: .4byte 0x0000046C
_081043FC:
	ldr r1, _08104468 @ =0x00000744
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _08104484
	ldr r2, _0810446C @ =FUN_080e48d0
	movs r1, #0x10
	ldr r3, _08104470 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _08104474 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #4
	mov r8, r4
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	ldr r1, _08104478 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _0810447C @ =0x0000046A
	adds r0, r6, r2
	mov r4, r8
	strb r4, [r0]
	adds r1, #0x1b
	adds r0, r6, r1
	str r3, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r5, [r0]
	ldr r3, _08104480 @ =0x0000070D
	adds r1, r7, r3
	movs r0, #3
	strb r0, [r1]
	b _0810463A
	.align 2, 0
_08104468: .4byte 0x00000744
_0810446C: .4byte FUN_080e48d0
_08104470: .4byte 0x0000046D
_08104474: .4byte 0x0000046B
_08104478: .4byte 0x00000469
_0810447C: .4byte 0x0000046A
_08104480: .4byte 0x0000070D
_08104484:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r4, #0xe6
	lsls r4, r4, #3
	adds r0, r7, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08104498
	b _081045CA
_08104498:
	b _081045CE
_0810449A:
	movs r5, #0xf2
	lsls r5, r5, #1
	adds r0, r6, r5
	ldr r2, _08104518 @ =0x0000073C
	adds r1, r7, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _08104538
	movs r3, #0xe9
	lsls r3, r3, #3
	adds r0, r7, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	bgt _08104538
	adds r0, r6, #0
	bl FUN_0810645c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081045B8
	ldr r2, _0810451C @ =FUN_080e48d0
	movs r1, #0x10
	ldr r5, _08104520 @ =0x0000046D
	adds r0, r6, r5
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r7, _08104524 @ =0x0000046B
	adds r0, r6, r7
	strb r3, [r0]
	ldr r4, _08104528 @ =0x00000553
	adds r0, r6, r4
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r6, r7
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #6
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _0810452C @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _08104530 @ =0x0000046A
	adds r0, r6, r2
	strb r4, [r0]
	ldr r4, _08104534 @ =0x00000484
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	b _0810463A
	.align 2, 0
_08104518: .4byte 0x0000073C
_0810451C: .4byte FUN_080e48d0
_08104520: .4byte 0x0000046D
_08104524: .4byte 0x0000046B
_08104528: .4byte 0x00000553
_0810452C: .4byte 0x00000469
_08104530: .4byte 0x0000046A
_08104534: .4byte 0x00000484
_08104538:
	ldr r1, _081045A0 @ =0x00000744
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _081045B8
	ldr r3, _081045A4 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r4, _081045A8 @ =0x0000046D
	adds r0, r6, r4
	movs r2, #0
	movs r5, #1
	strb r5, [r0]
	subs r4, #2
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
	movs r4, #2
	movs r0, #4
	mov r8, r0
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r6, r3
	strb r1, [r0]
	ldr r1, _081045AC @ =0x00000469
	adds r0, r6, r1
	strb r4, [r0]
	adds r3, #2
	adds r0, r6, r3
	mov r1, r8
	strb r1, [r0]
	adds r3, #0x1a
	adds r0, r6, r3
	str r2, [r0]
	ldr r1, _081045B0 @ =0x0000046C
	adds r0, r6, r1
	strb r5, [r0]
	ldr r2, _081045B4 @ =0x0000070D
	adds r0, r7, r2
	strb r4, [r0]
	b _0810463A
	.align 2, 0
_081045A0: .4byte 0x00000744
_081045A4: .4byte FUN_080e48d0
_081045A8: .4byte 0x0000046D
_081045AC: .4byte 0x00000469
_081045B0: .4byte 0x0000046C
_081045B4: .4byte 0x0000070D
_081045B8:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r3, #0xe6
	lsls r3, r3, #3
	adds r0, r7, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081045CE
_081045CA:
	movs r0, #1
	b _081045D0
_081045CE:
	movs r0, #0
_081045D0:
	adds r4, r0, #0
	cmp r4, #0
	bne _0810463A
	ldrb r1, [r6, #5]
	movs r5, #0xfe
	lsls r5, r5, #1
	adds r0, r6, r5
	ldrb r0, [r0]
	adds r0, #0x80
	strb r0, [r6, #5]
	adds r0, r6, #0
	bl FUN_08105db4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0810463A
	ldr r2, _08104644 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r7, _08104648 @ =0x0000046D
	adds r0, r6, r7
	movs r3, #1
	strb r3, [r0]
	ldr r5, _0810464C @ =0x0000046B
	adds r0, r6, r5
	strb r4, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r4, [r0]
	movs r2, #0x12
	subs r5, #3
	adds r0, r6, r5
	strb r1, [r0]
	subs r7, #0xea
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _08104650 @ =0x0000046A
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _08104654 @ =0x00000484
	adds r0, r6, r2
	str r4, [r0]
	ldr r4, _08104658 @ =0x0000046C
	adds r0, r6, r4
	strb r3, [r0]
_0810463A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08104644: .4byte FUN_080e48d0
_08104648: .4byte 0x0000046D
_0810464C: .4byte 0x0000046B
_08104650: .4byte 0x0000046A
_08104654: .4byte 0x00000484
_08104658: .4byte 0x0000046C

	thumb_func_start FUN_0810465c
FUN_0810465c: @ 0x0810465C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	bl FUN_081058f4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08104698
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08104684
	movs r0, #1
	b _08104686
_08104684:
	movs r0, #0
_08104686:
	cmp r0, #0
	beq _0810468E
	movs r0, #1
	b _0810471E
_0810468E:
	adds r0, r5, #0
	bl FUN_08106648
	movs r0, #1
	b _0810471E
_08104698:
	cmp r4, #0x18
	bgt _0810471C
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r7, _08104704 @ =0x00000734
	adds r1, r6, r7
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _0810471C
	ldr r2, _08104708 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r3, _0810470C @ =0x0000046D
	adds r0, r5, r3
	movs r3, #0
	movs r4, #1
	strb r4, [r0]
	ldr r7, _08104710 @ =0x0000046B
	adds r0, r5, r7
	strb r3, [r0]
	adds r7, #0xe8
	adds r0, r5, r7
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
	subs r7, #0xeb
	adds r0, r5, r7
	strb r1, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r2, [r0]
	ldr r2, _08104714 @ =0x0000046A
	adds r0, r5, r2
	strb r1, [r0]
	adds r7, #0x1b
	adds r0, r5, r7
	str r3, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _08104718 @ =0x00000757
	adds r0, r6, r3
	strb r1, [r0]
	movs r0, #1
	b _0810471E
	.align 2, 0
_08104704: .4byte 0x00000734
_08104708: .4byte FUN_080e48d0
_0810470C: .4byte 0x0000046D
_08104710: .4byte 0x0000046B
_08104714: .4byte 0x0000046A
_08104718: .4byte 0x00000757
_0810471C:
	movs r0, #0
_0810471E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08104724
FUN_08104724: @ 0x08104724
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	bl FUN_081058f4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08104760
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0810474C
	movs r0, #1
	b _0810474E
_0810474C:
	movs r0, #0
_0810474E:
	cmp r0, #0
	beq _08104756
	movs r0, #1
	b _0810494E
_08104756:
	adds r0, r5, #0
	bl FUN_08106648
	movs r0, #1
	b _0810494E
_08104760:
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r7, _081047EC @ =0x0000073C
	adds r1, r6, r7
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _08104824
	movs r1, #0xe9
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _08104824
	cmp r4, #0xc
	bgt _08104808
	subs r3, #0x60
	adds r0, r5, r3
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldr r2, _081047F0 @ =0x00000546
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r1, r0
	bgt _08104808
	ldr r3, _081047F4 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r7, _081047F8 @ =0x0000046D
	adds r0, r5, r7
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	subs r7, #2
	adds r0, r5, r7
	strb r2, [r0]
	adds r7, #0xe8
	adds r0, r5, r7
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
	subs r7, #0xeb
	adds r0, r5, r7
	strb r3, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r1, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _081047FC @ =0x00000484
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _08104800 @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	ldr r7, _08104804 @ =0x00000757
	adds r0, r6, r7
	strb r3, [r0]
	movs r0, #1
	b _0810494E
	.align 2, 0
_081047EC: .4byte 0x0000073C
_081047F0: .4byte 0x00000546
_081047F4: .4byte FUN_080e48d0
_081047F8: .4byte 0x0000046D
_081047FC: .4byte 0x00000484
_08104800: .4byte 0x0000046C
_08104804: .4byte 0x00000757
_08104808:
	cmp r4, #0x18
	ble _0810480E
	b _0810494C
_0810480E:
	ldr r1, _08104820 @ =0x00000744
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _0810481C
	b _0810494C
_0810481C:
	b _08104846
	.align 2, 0
_08104820: .4byte 0x00000744
_08104824:
	cmp r4, #0x18
	bgt _081048B8
	movs r7, #0xf2
	lsls r7, r7, #1
	adds r0, r5, r7
	ldr r2, _0810489C @ =0x00000734
	adds r1, r6, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _081048B8
	ldr r3, _081048A0 @ =0x00000744
	adds r0, r6, r3
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #0
	bgt _081048B8
_08104846:
	ldr r2, _081048A4 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r3, _081048A8 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #0
	movs r4, #1
	strb r4, [r0]
	ldr r7, _081048AC @ =0x0000046B
	adds r0, r5, r7
	strb r3, [r0]
	adds r7, #0xe8
	adds r0, r5, r7
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
	subs r7, #0xeb
	adds r0, r5, r7
	strb r1, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r2, [r0]
	ldr r2, _081048B0 @ =0x0000046A
	adds r0, r5, r2
	strb r1, [r0]
	adds r7, #0x1b
	adds r0, r5, r7
	str r3, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _081048B4 @ =0x00000757
	adds r0, r6, r3
	strb r1, [r0]
	movs r0, #1
	b _0810494E
	.align 2, 0
_0810489C: .4byte 0x00000734
_081048A0: .4byte 0x00000744
_081048A4: .4byte FUN_080e48d0
_081048A8: .4byte 0x0000046D
_081048AC: .4byte 0x0000046B
_081048B0: .4byte 0x0000046A
_081048B4: .4byte 0x00000757
_081048B8:
	cmp r4, #0xc
	bgt _0810494C
	movs r7, #0xf2
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r2, #0xe7
	lsls r2, r2, #3
	adds r1, r6, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _0810494C
	ldr r3, _08104934 @ =0x00000746
	adds r0, r6, r3
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, #0
	bgt _0810494C
	ldr r4, _08104938 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r2, _0810493C @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	movs r3, #1
	strb r3, [r0]
	ldr r7, _08104940 @ =0x0000046B
	adds r0, r5, r7
	strb r2, [r0]
	adds r7, #0xe8
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r4, #0
	strh r2, [r0]
	movs r1, #2
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r5, r7
	strb r4, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _08104944 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r7, #0x1b
	adds r0, r5, r7
	str r2, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r3, [r0]
	ldr r2, _08104948 @ =0x00000757
	adds r0, r6, r2
	strb r4, [r0]
	movs r0, #1
	b _0810494E
	.align 2, 0
_08104934: .4byte 0x00000746
_08104938: .4byte FUN_080e48d0
_0810493C: .4byte 0x0000046D
_08104940: .4byte 0x0000046B
_08104944: .4byte 0x0000046A
_08104948: .4byte 0x00000757
_0810494C:
	movs r0, #0
_0810494E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08104954
FUN_08104954: @ 0x08104954
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r7, r1, #0
	adds r3, r2, #0
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r2, _0810499C @ =0x0000075C
	adds r1, r7, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blo _08104974
	b _08104B82
_08104974:
	movs r4, #0xc2
	lsls r4, r4, #1
	adds r0, r6, r4
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldr r2, _081049A0 @ =0x00000546
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r1, r0
	blt _081049AC
	movs r1, #0x80
	movs r4, #0xe6
	lsls r4, r4, #3
	adds r0, r7, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081049A4
	movs r0, #1
	b _081049A6
	.align 2, 0
_0810499C: .4byte 0x0000075C
_081049A0: .4byte 0x00000546
_081049A4:
	movs r0, #0
_081049A6:
	cmp r0, #0
	bne _081049AC
	b _08104AE0
_081049AC:
	cmp r3, #0x18
	ble _081049B2
	b _08104B78
_081049B2:
	movs r5, #0xf2
	lsls r5, r5, #1
	adds r0, r6, r5
	ldr r2, _08104A28 @ =0x00000734
	adds r1, r7, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _08104A44
	ldr r4, _08104A2C @ =0x00000744
	adds r0, r7, r4
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	bgt _08104A44
	ldr r2, _08104A30 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r3, _08104A34 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _08104A38 @ =0x0000046B
	adds r0, r6, r5
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
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	subs r5, #0xeb
	adds r0, r6, r5
	strb r1, [r0]
	adds r5, #1
	adds r0, r6, r5
	strb r2, [r0]
	ldr r2, _08104A3C @ =0x0000046A
	adds r0, r6, r2
	strb r1, [r0]
	adds r5, #0x1b
	adds r0, r6, r5
	str r3, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r4, [r0]
	ldr r3, _08104A40 @ =0x00000757
	adds r0, r7, r3
	strb r1, [r0]
	movs r0, #1
	b _08104C2A
	.align 2, 0
_08104A28: .4byte 0x00000734
_08104A2C: .4byte 0x00000744
_08104A30: .4byte FUN_080e48d0
_08104A34: .4byte 0x0000046D
_08104A38: .4byte 0x0000046B
_08104A3C: .4byte 0x0000046A
_08104A40: .4byte 0x00000757
_08104A44:
	cmp r3, #0x18
	ble _08104A4A
	b _08104B78
_08104A4A:
	ldr r4, _08104AC0 @ =0x00000746
	adds r0, r7, r4
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	bgt _08104AE0
	ldr r3, _08104AC4 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r2, _08104AC8 @ =0x0000046D
	adds r0, r6, r2
	movs r2, #0
	movs r4, #1
	mov ip, r4
	mov r5, ip
	strb r5, [r0]
	ldr r4, _08104ACC @ =0x0000046B
	adds r0, r6, r4
	strb r2, [r0]
	ldr r5, _08104AD0 @ =0x00000553
	adds r0, r6, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r4, #0
	strh r2, [r0]
	movs r1, #2
	movs r3, #3
	subs r5, #0xeb
	adds r0, r6, r5
	strb r4, [r0]
	adds r5, #1
	adds r0, r6, r5
	strb r1, [r0]
	ldr r1, _08104AD4 @ =0x0000046A
	adds r0, r6, r1
	strb r3, [r0]
	ldr r3, _08104AD8 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r5, #3
	adds r0, r6, r5
	mov r1, ip
	strb r1, [r0]
	movs r3, #0xe6
	lsls r3, r3, #3
	adds r2, r7, r3
	movs r0, #0x81
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r5, _08104ADC @ =0x00000757
	adds r0, r7, r5
	b _08104C00
	.align 2, 0
_08104AC0: .4byte 0x00000746
_08104AC4: .4byte FUN_080e48d0
_08104AC8: .4byte 0x0000046D
_08104ACC: .4byte 0x0000046B
_08104AD0: .4byte 0x00000553
_08104AD4: .4byte 0x0000046A
_08104AD8: .4byte 0x00000484
_08104ADC: .4byte 0x00000757
_08104AE0:
	cmp r3, #0x18
	bgt _08104B78
	ldr r0, _08104B60 @ =0x00000757
	adds r5, r7, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _08104B78
	ldr r3, _08104B64 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r2, _08104B68 @ =0x0000046D
	adds r0, r6, r2
	movs r2, #0
	movs r4, #1
	mov ip, r4
	mov r4, ip
	strb r4, [r0]
	ldr r4, _08104B6C @ =0x0000046B
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
	movs r4, #0
	strh r2, [r0]
	movs r1, #2
	movs r0, #3
	mov r8, r0
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r6, r3
	strb r4, [r0]
	adds r3, #1
	adds r0, r6, r3
	strb r1, [r0]
	ldr r1, _08104B70 @ =0x0000046A
	adds r0, r6, r1
	mov r3, r8
	strb r3, [r0]
	adds r1, #0x1a
	adds r0, r6, r1
	str r2, [r0]
	ldr r2, _08104B74 @ =0x0000046C
	adds r0, r6, r2
	mov r3, ip
	strb r3, [r0]
	movs r0, #0xe6
	lsls r0, r0, #3
	adds r2, r7, r0
	movs r0, #0x81
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	strb r4, [r5]
	movs r0, #1
	b _08104C2A
	.align 2, 0
_08104B60: .4byte 0x00000757
_08104B64: .4byte FUN_080e48d0
_08104B68: .4byte 0x0000046D
_08104B6C: .4byte 0x0000046B
_08104B70: .4byte 0x0000046A
_08104B74: .4byte 0x0000046C
_08104B78:
	adds r0, r6, #0
	bl FUN_08106648
	movs r0, #1
	b _08104C2A
_08104B82:
	cmp r3, #0x14
	bgt _08104C28
	movs r1, #0xe7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r2, r0
	bhs _08104B9E
	ldr r2, _08104C08 @ =0x00000746
	adds r0, r7, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	ble _08104BA8
_08104B9E:
	ldr r4, _08104C0C @ =0x00000757
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _08104C28
_08104BA8:
	ldr r3, _08104C10 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r5, _08104C14 @ =0x0000046D
	adds r0, r6, r5
	movs r2, #0
	movs r4, #1
	mov ip, r4
	mov r5, ip
	strb r5, [r0]
	ldr r4, _08104C18 @ =0x0000046B
	adds r0, r6, r4
	strb r2, [r0]
	ldr r5, _08104C1C @ =0x00000553
	adds r0, r6, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r4, #0
	strh r2, [r0]
	movs r1, #2
	movs r3, #3
	subs r5, #0xeb
	adds r0, r6, r5
	strb r4, [r0]
	adds r5, #1
	adds r0, r6, r5
	strb r1, [r0]
	ldr r1, _08104C20 @ =0x0000046A
	adds r0, r6, r1
	strb r3, [r0]
	ldr r3, _08104C24 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r5, #3
	adds r0, r6, r5
	mov r1, ip
	strb r1, [r0]
	ldr r2, _08104C0C @ =0x00000757
	adds r0, r7, r2
_08104C00:
	strb r4, [r0]
	movs r0, #1
	b _08104C2A
	.align 2, 0
_08104C08: .4byte 0x00000746
_08104C0C: .4byte 0x00000757
_08104C10: .4byte FUN_080e48d0
_08104C14: .4byte 0x0000046D
_08104C18: .4byte 0x0000046B
_08104C1C: .4byte 0x00000553
_08104C20: .4byte 0x0000046A
_08104C24: .4byte 0x00000484
_08104C28:
	movs r0, #0
_08104C2A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08104c34
FUN_08104c34: @ 0x08104C34
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08104C4E
	b _08104D66
_08104C4E:
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r6, [r0]
	adds r1, #0xe4
	adds r0, r5, r1
	adds r2, #0x68
	adds r1, r5, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _08104D44
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	adds r3, #0xc
	adds r0, r5, r3
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
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	ldrb r1, [r5, #5]
	subs r2, r0, r1
	cmp r2, #0x80
	ble _08104CB0
	ldr r0, _08104CAC @ =0xFFFFFF00
	adds r2, r2, r0
	b _08104CBE
	.align 2, 0
_08104CAC: .4byte 0xFFFFFF00
_08104CB0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r2, r0
	bge _08104CBE
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r2, r1
_08104CBE:
	cmp r2, #0
	bge _08104CC4
	rsbs r2, r2, #0
_08104CC4:
	ldr r3, _08104CE4 @ =0x000001FD
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r2, r0
	bge _08104D20
	ldr r1, _08104CE8 @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08104CEC
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_0810465c
	b _08104D06
	.align 2, 0
_08104CE4: .4byte 0x000001FD
_08104CE8: .4byte 0x000001DF
_08104CEC:
	cmp r0, #6
	bne _08104CFA
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08104724
	b _08104D06
_08104CFA:
	cmp r0, #7
	bne _08104D0C
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08104954
_08104D06:
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08104D66
_08104D0C:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08104D32
	b _08104D36
_08104D20:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r3, #0xe6
	lsls r3, r3, #3
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08104D36
_08104D32:
	movs r0, #1
	b _08104D38
_08104D36:
	movs r0, #0
_08104D38:
	cmp r0, #0
	bne _08104D66
	adds r0, r5, #0
	bl FUN_08106648
	b _08104D66
_08104D44:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08104D5A
	movs r0, #1
	b _08104D5C
_08104D5A:
	movs r0, #0
_08104D5C:
	cmp r0, #0
	bne _08104D66
	adds r0, r5, #0
	bl FUN_08106648
_08104D66:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08104d70
FUN_08104d70: @ 0x08104D70
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	movs r2, #0x80
	lsls r2, r2, #0x13
	mov r8, r2
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r6, r5, r3
	ldr r4, [r6]
	ands r4, r2
	cmp r4, #0
	beq _08104E34
	adds r1, #0x13
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _08104DAC
	movs r0, #4
	adds r3, #0xaa
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08104DAC:
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r3, #0x93
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _08104DEA
	adds r0, r5, #0
	bl FUN_081058f4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08104DEA
	ldr r1, _08104E00 @ =0x00000724
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08104E12
_08104DEA:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08104E04
	movs r0, #1
	b _08104E06
	.align 2, 0
_08104E00: .4byte 0x00000724
_08104E04:
	movs r0, #0
_08104E06:
	cmp r0, #0
	bne _08104E9E
	adds r0, r5, #0
	bl FUN_08106648
	b _08104E9E
_08104E12:
	adds r0, r5, #0
	bl FUN_08104c34
	movs r0, #8
	bl FUN_080ecf60
	cmp r0, #0
	beq _08104E9E
	mov r1, sp
	movs r0, #7
	strh r0, [r1]
	movs r0, #3
	strh r0, [r1, #2]
	movs r0, #8
	bl FUN_080ec79c
	b _08104E9E
_08104E34:
	movs r1, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	ldr r7, _08104EAC @ =0x00000469
	adds r0, r5, r7
	strb r1, [r0]
	ldr r2, _08104EB0 @ =0x0000046A
	adds r0, r5, r2
	strb r4, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r4, [r0]
	adds r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	ldr r3, _08104EB4 @ =FUN_080e48d0
	movs r2, #0x10
	adds r7, #1
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _08104EB8 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	movs r0, #8
	bl FUN_080ecf60
	cmp r0, #0
	beq _08104E96
	mov r1, sp
	movs r0, #7
	strh r0, [r1]
	movs r0, #3
	strh r0, [r1, #2]
	movs r0, #8
	bl FUN_080ec79c
_08104E96:
	ldr r0, [r6]
	mov r3, r8
	orrs r0, r3
	str r0, [r6]
_08104E9E:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08104EAC: .4byte 0x00000469
_08104EB0: .4byte 0x0000046A
_08104EB4: .4byte FUN_080e48d0
_08104EB8: .4byte 0x0000046B

	thumb_func_start FUN_08104ebc
FUN_08104ebc: @ 0x08104EBC
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r7, r6, r3
	ldrh r1, [r7]
	ands r0, r1
	cmp r0, #0
	beq _08104EDC
	b _08105160
_08104EDC:
	ldr r4, _08104F80 @ =0x00000724
	adds r0, r2, r4
	ldrb r5, [r0]
	cmp r5, #0
	beq _08104EE8
	b _08105160
_08104EE8:
	movs r0, #0x80
	mov ip, r0
	ands r1, r0
	lsls r0, r1, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08104F9C
	movs r1, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r5, [r0]
	ldr r3, _08104F84 @ =0x00000469
	adds r0, r6, r3
	strb r5, [r0]
	ldr r4, _08104F88 @ =0x0000046A
	adds r0, r6, r4
	strb r1, [r0]
	ldr r1, _08104F8C @ =0x00000484
	adds r0, r6, r1
	str r5, [r0]
	adds r2, #4
	adds r0, r6, r2
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r3, [r0]
	movs r2, #0x1a
	adds r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	ldr r1, _08104F90 @ =0x0000046B
	adds r0, r6, r1
	strb r5, [r0]
	adds r4, #0xe6
	adds r0, r6, r4
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
	ldrh r0, [r7]
	mov r3, ip
	ands r0, r3
	cmp r0, #0
	beq _08104F72
	ldr r4, _08104F94 @ =0x0000024E
	adds r2, r6, r4
	movs r5, #0x96
	lsls r5, r5, #1
	adds r0, r5, #0
	ldrh r7, [r2]
	adds r0, r0, r7
	strh r0, [r2]
	movs r3, #0x93
	lsls r3, r3, #2
	adds r1, r6, r3
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _08104F72
	strh r1, [r2]
_08104F72:
	movs r0, #4
	ldr r4, _08104F98 @ =0x00000222
	adds r2, r6, r4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _0810502A
	.align 2, 0
_08104F80: .4byte 0x00000724
_08104F84: .4byte 0x00000469
_08104F88: .4byte 0x0000046A
_08104F8C: .4byte 0x00000484
_08104F90: .4byte 0x0000046B
_08104F94: .4byte 0x0000024E
_08104F98: .4byte 0x00000222
_08104F9C:
	movs r1, #3
	movs r2, #1
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r6, r5
	strb r1, [r0]
	ldr r7, _08105068 @ =0x00000469
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _0810506C @ =0x0000046A
	adds r0, r6, r1
	strb r4, [r0]
	ldr r3, _08105070 @ =0x00000484
	adds r0, r6, r3
	str r4, [r0]
	adds r5, #4
	adds r0, r6, r5
	strb r2, [r0]
	ldr r3, _08105074 @ =FUN_080e6794
	movs r1, #0xe
	adds r7, #4
	adds r0, r6, r7
	strb r2, [r0]
	ldr r2, _08105078 @ =0x0000046B
	adds r0, r6, r2
	strb r4, [r0]
	adds r5, #0xe7
	adds r0, r6, r5
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r6, r7
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r5, #0
	strh r4, [r0]
	movs r2, #0x10
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r4, _0810507C @ =0x00000482
	adds r1, r6, r4
	movs r0, #2
	strh r0, [r1]
	adds r7, #0x28
	adds r0, r6, r7
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x3c
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r6, r0
	subs r7, #0x4c
	adds r0, r6, r7
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r5, [r0]
	ldr r2, _08105080 @ =0x00000551
	adds r0, r6, r2
	strb r5, [r0]
	ldr r3, _08105084 @ =0x00000552
	adds r0, r6, r3
	strb r4, [r0]
_0810502A:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r6, r4
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
	blt _08105062
	cmp r1, #0
	blt _08105062
	ldr r0, _08105088 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08105062
	ldr r0, _0810508C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08105090
_08105062:
	movs r4, #0
	b _0810509E
	.align 2, 0
_08105068: .4byte 0x00000469
_0810506C: .4byte 0x0000046A
_08105070: .4byte 0x00000484
_08105074: .4byte FUN_080e6794
_08105078: .4byte 0x0000046B
_0810507C: .4byte 0x00000482
_08105080: .4byte 0x00000551
_08105084: .4byte 0x00000552
_08105088: .4byte 0x030046A8
_0810508C: .4byte 0x030046AC
_08105090:
	ldr r0, _081050B0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0810509E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081050B4
	adds r0, #4
	b _081050C0
	.align 2, 0
_081050B0: .4byte 0x030046A4
_081050B4:
	ldr r0, _081050D4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081050C0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081050D8
	cmp r3, #2
	beq _081050DC
	b _081050E0
	.align 2, 0
_081050D4: .4byte 0x030046A4
_081050D8:
	ldrb r0, [r5, #4]
	b _081050DE
_081050DC:
	ldrb r0, [r5]
_081050DE:
	subs r2, r2, r0
_081050E0:
	movs r1, #0
	strh r2, [r5, #2]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r6, r5
	ldr r0, [r0]
	strh r1, [r0, #6]
	movs r7, #0xec
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r1, [r0]
	ldr r2, _0810511C @ =0x000004A4
	adds r0, r6, r2
	ldr r4, [r0]
	adds r5, r6, #0
	adds r5, #8
	adds r7, r1, #0
	adds r7, #8
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r7, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08105120
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r6, r3
	b _08105146
	.align 2, 0
_0810511C: .4byte 0x000004A4
_08105120:
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r7, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08105140
	cmp r0, #2
	beq _0810513C
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0810513C:
	movs r0, #1
	b _08105150
_08105140:
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r6, r4
_08105146:
	ldr r1, _08105168 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08105150:
	cmp r0, #0
	bne _08105160
	ldr r5, _0810516C @ =0x000005C4
	adds r0, r6, r5
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
_08105160:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08105168: .4byte 0xFFFFFDFF
_0810516C: .4byte 0x000005C4

	thumb_func_start FUN_08105170
FUN_08105170: @ 0x08105170
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r0, [r3, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	bne _081051EC
	ldr r1, _08105190 @ =0x000001DF
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _08105194
	movs r5, #1
	b _081051A8
	.align 2, 0
_08105190: .4byte 0x000001DF
_08105194:
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r3, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	rsbs r0, r0, #0
	lsrs r5, r0, #0x1f
_081051A8:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081051CC @ =0x000001DF
	adds r0, r3, r1
	ldrb r1, [r0]
	cmp r1, #7
	bne _081051D4
	ldr r2, _081051D0 @ =0x085AD504
	ldrh r0, [r4, #0x14]
	ands r1, r0
	lsls r0, r1, #1
	b _081051DE
	.align 2, 0
_081051CC: .4byte 0x000001DF
_081051D0: .4byte 0x085AD504
_081051D4:
	ldr r2, _081051E8 @ =0x085AD4E4
	ldrh r1, [r4, #0x14]
	movs r0, #7
	ands r0, r1
	lsls r0, r0, #1
_081051DE:
	lsls r1, r5, #4
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0]
	b _081051EE
	.align 2, 0
_081051E8: .4byte 0x085AD4E4
_081051EC:
	movs r0, #0
_081051EE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_081051f4
FUN_081051f4: @ 0x081051F4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #8]
	adds r1, #0x10
	movs r0, #0xff
	ands r1, r0
	asrs r6, r1, #6
	adds r0, r6, #2
	str r0, [sp, #0xc]
	movs r0, #3
	ldr r1, [sp, #0xc]
	ands r1, r0
	str r1, [sp, #0xc]
	movs r2, #0
	str r2, [sp, #0x10]
_0810521A:
	ldr r3, [sp, #0xc]
	cmp r6, r3
	bne _08105222
	b _08105580
_08105222:
	cmp r6, #1
	beq _0810524C
	cmp r6, #1
	bgt _08105230
	cmp r6, #0
	beq _0810523A
	b _081052A0
_08105230:
	cmp r6, #2
	beq _0810526C
	cmp r6, #3
	beq _08105280
	b _081052A0
_0810523A:
	ldr r0, [sp, #8]
	ldr r2, _08105248 @ =0x00000256
	adds r1, r0, r2
	ldrh r0, [r1]
	adds r7, r0, #1
	mov r8, r1
	b _081052AA
	.align 2, 0
_08105248: .4byte 0x00000256
_0810524C:
	ldr r3, [sp, #8]
	ldr r0, _08105264 @ =0x00000256
	adds r1, r3, r0
	ldr r2, _08105268 @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldrh r2, [r1]
	adds r7, r0, r2
	mov r8, r1
	b _081052AA
	.align 2, 0
_08105264: .4byte 0x00000256
_08105268: .4byte 0x030046A4
_0810526C:
	ldr r3, [sp, #8]
	ldr r0, _0810527C @ =0x00000256
	adds r1, r3, r0
	ldrh r0, [r1]
	subs r7, r0, #1
	mov r8, r1
	b _081052AA
	.align 2, 0
_0810527C: .4byte 0x00000256
_08105280:
	ldr r2, [sp, #8]
	ldr r3, _08105298 @ =0x00000256
	adds r1, r2, r3
	ldrh r2, [r1]
	ldr r3, _0810529C @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r7, r2, r0
	mov r8, r1
	b _081052AA
	.align 2, 0
_08105298: .4byte 0x00000256
_0810529C: .4byte 0x030046A4
_081052A0:
	ldr r1, [sp, #8]
	ldr r2, _081052BC @ =0x00000256
	adds r0, r1, r2
	ldrh r7, [r0]
	mov r8, r0
_081052AA:
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081052C0
	adds r0, #4
	b _081052CC
	.align 2, 0
_081052BC: .4byte 0x00000256
_081052C0:
	ldr r3, _081052E8 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081052CC:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	str r0, [sp, #0x14]
	mov r0, r8
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081052EC
	adds r0, #4
	b _081052F8
	.align 2, 0
_081052E8: .4byte 0x030046A4
_081052EC:
	ldr r1, _08105310 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081052F8:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	str r0, [sp, #0x18]
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08105314
	adds r0, #4
	b _08105320
	.align 2, 0
_08105310: .4byte 0x030046A4
_08105314:
	ldr r2, _08105360 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08105320:
	ldrh r0, [r0, #2]
	str r0, [sp, #0x1c]
	mov sl, sp
	ldr r5, _08105360 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r7, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08105364
	adds r0, #4
	b _0810536E
	.align 2, 0
_08105360: .4byte 0x030046A4
_08105364:
	ldr r0, [r5]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0810536E:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	mov r3, sl
	strh r1, [r3, #2]
	mov r1, sb
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	mov r4, sp
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08105394
	adds r0, #4
	b _081053A0
_08105394:
	ldr r2, _081053B8 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081053A0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r3, #0xf
	ands r2, r3
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081053BC
	cmp r2, #2
	beq _081053C0
	b _081053C4
	.align 2, 0
_081053B8: .4byte 0x030046A4
_081053BC:
	ldrb r0, [r4, #4]
	b _081053C2
_081053C0:
	ldrb r0, [r4]
_081053C2:
	subs r1, r1, r0
_081053C4:
	str r1, [sp, #0x20]
	mov r0, r8
	ldrh r5, [r0]
	mov sl, sp
	ldr r1, _08105408 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r3, _08105408 @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
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
	beq _0810540C
	adds r0, #4
	b _08105418
	.align 2, 0
_08105408: .4byte 0x030046A4
_0810540C:
	ldr r3, _08105444 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08105418:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	mov r0, sl
	strh r1, [r0, #2]
	mov r1, sb
	lsls r0, r1, #8
	adds r0, #0x80
	mov r2, sl
	strh r0, [r2, #4]
	mov r3, r8
	ldrh r4, [r3]
	mov r5, sp
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08105448
	adds r0, #4
	b _08105454
	.align 2, 0
_08105444: .4byte 0x030046A4
_08105448:
	ldr r1, _0810546C @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08105454:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r3, #0xf
	ands r2, r3
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08105470
	cmp r2, #2
	beq _08105474
	b _08105478
	.align 2, 0
_0810546C: .4byte 0x030046A4
_08105470:
	ldrb r0, [r5, #4]
	b _08105476
_08105474:
	ldrb r0, [r5]
_08105476:
	subs r1, r1, r0
_08105478:
	ldr r0, [sp, #0x20]
	subs r2, r0, r1
	adds r0, r1, #0
	adds r0, #0xff
	asrs r0, r0, #8
	ldr r1, [sp, #0x20]
	adds r1, #0xff
	asrs r1, r1, #8
	subs r0, r0, r1
	lsls r1, r0, #8
	movs r0, #0x43
	ldr r3, [sp, #0x1c]
	ands r3, r0
	cmp r3, #0
	bne _08105580
	cmp r2, #0
	beq _0810557A
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bne _081054B6
	cmp r6, #1
	bne _081054B0
	ldr r3, [sp, #0x18]
	cmp r3, #1
	bne _081054CC
	movs r0, #0x80
	lsls r0, r0, #1
	b _081054DA
_081054B0:
	cmp r6, #3
	bne _08105580
	b _081054D6
_081054B6:
	ldr r0, [sp, #0x14]
	cmp r0, #2
	bne _081054DE
	cmp r6, #0
	bne _081054D2
	ldr r3, [sp, #0x18]
	cmp r3, #2
	bne _081054CC
	movs r0, #0x80
	lsls r0, r0, #1
	b _081054DA
_081054CC:
	cmp r1, #0
	beq _081054DE
	b _08105580
_081054D2:
	cmp r6, #2
	bne _08105580
_081054D6:
	ldr r3, [sp, #0x18]
	ldr r0, _081054F4 @ =0xFFFFFF00
_081054DA:
	cmp r1, r0
	bne _08105580
_081054DE:
	ldr r0, [sp, #0x18]
	cmp r0, #1
	bne _08105504
	cmp r6, #1
	bne _081054F8
	ldr r3, [sp, #0x14]
	cmp r3, #1
	bne _08105514
	movs r0, #0x80
	lsls r0, r0, #1
	b _08105530
	.align 2, 0
_081054F4: .4byte 0xFFFFFF00
_081054F8:
	cmp r6, #3
	bne _08105580
	ldr r0, [sp, #0x14]
	cmp r0, #1
	beq _0810552E
	b _0810553C
_08105504:
	ldr r3, [sp, #0x18]
	cmp r3, #2
	bne _0810554C
	cmp r6, #0
	bne _08105524
	ldr r0, [sp, #0x14]
	cmp r0, #2
	bne _0810551E
_08105514:
	movs r3, #0x80
	lsls r3, r3, #1
	cmp r1, r3
	beq _08105540
	b _08105580
_0810551E:
	movs r0, #0x80
	lsls r0, r0, #1
	b _08105530
_08105524:
	cmp r6, #2
	bne _08105580
	ldr r3, [sp, #0x14]
	cmp r3, #2
	bne _0810553C
_0810552E:
	ldr r0, _08105538 @ =0xFFFFFF00
_08105530:
	cmp r1, r0
	beq _08105540
	b _08105580
	.align 2, 0
_08105538: .4byte 0xFFFFFF00
_0810553C:
	cmp r1, #0
	bne _08105580
_08105540:
	ldr r0, [sp, #0x18]
	cmp r0, #2
	bne _0810554C
	ldr r1, [sp, #0x14]
	cmp r1, #2
	beq _08105558
_0810554C:
	ldr r3, [sp, #0x18]
	cmp r3, #1
	bne _0810556A
	ldr r0, [sp, #0x14]
	cmp r0, #1
	bne _0810556A
_08105558:
	adds r0, r2, #0
	cmp r2, #0
	bge _08105560
	rsbs r0, r2, #0
_08105560:
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	ble _0810557A
	b _08105580
_0810556A:
	adds r0, r2, #0
	cmp r0, #0
	bge _08105572
	rsbs r0, r0, #0
_08105572:
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0xff
	bgt _0810557C
_0810557A:
	adds r1, r7, #0
_0810557C:
	cmp r1, #0
	bge _08105588
_08105580:
	adds r6, #1
	movs r0, #3
	ands r6, r0
	b _0810558C
_08105588:
	adds r0, r6, #0
	b _0810559C
_0810558C:
	ldr r2, [sp, #0x10]
	adds r2, #1
	str r2, [sp, #0x10]
	cmp r2, #3
	bgt _08105598
	b _0810521A
_08105598:
	movs r0, #1
	rsbs r0, r0, #0
_0810559C:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081055ac
FUN_081055ac: @ 0x081055AC
	push {r4, r5, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r5, [r0]
	movs r0, #0x45
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081055F2
	bl VM_GetPC
	cmp r0, #0
	beq _081055D0
	bl Script_GetValue
	adds r1, r0, #0
	b _081055D2
_081055D0:
	movs r1, #0
_081055D2:
	movs r2, #0xe5
	lsls r2, r2, #3
	adds r0, r5, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081055EA
	bl Script_GetValue
	adds r1, r0, #0
	b _081055EC
_081055EA:
	movs r1, #0
_081055EC:
	ldr r2, _0810560C @ =0x0000072A
	adds r0, r5, r2
	strh r1, [r0]
_081055F2:
	movs r0, #0x64
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08105640
	bl VM_GetPC
	cmp r0, #0
	beq _08105610
	bl Script_GetValue
	adds r4, r0, #0
	b _08105612
	.align 2, 0
_0810560C: .4byte 0x0000072A
_08105610:
	movs r4, #0
_08105612:
	bl VM_GetPC
	cmp r0, #0
	beq _08105622
	bl Script_GetValue
	adds r1, r0, #0
	b _08105624
_08105622:
	movs r1, #0
_08105624:
	ldr r2, _0810563C @ =0x00000726
	adds r0, r5, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08105660
	bl Script_GetValue
	adds r3, r0, #0
	b _08105646
	.align 2, 0
_0810563C: .4byte 0x00000726
_08105640:
	movs r4, #0
	movs r3, #1
	rsbs r3, r3, #0
_08105646:
	cmp r3, #0
	blt _08105660
	movs r0, #0x80
	lsls r0, r0, #4
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _08105670 @ =0x00000756
	adds r0, r5, r2
	strb r3, [r0]
_08105660:
	cmp r4, #0
	beq _08105688
	cmp r4, #1
	beq _08105674
	cmp r4, #2
	beq _08105678
	b _08105688
	.align 2, 0
_08105670: .4byte 0x00000756
_08105674:
	movs r0, #0xa
	b _0810567C
_08105678:
	movs r0, #0x80
	lsls r0, r0, #5
_0810567C:
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08105688:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08105690
FUN_08105690: @ 0x08105690
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r5, [r0]
	ldr r2, _081056B0 @ =0x000001DF
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #6
	beq _081056E8
	cmp r0, #6
	bgt _081056B4
	cmp r0, #5
	beq _081056BE
	b _081057A4
	.align 2, 0
_081056B0: .4byte 0x000001DF
_081056B4:
	cmp r0, #7
	beq _08105728
	cmp r0, #8
	beq _08105768
	b _081057A4
_081056BE:
	ldr r1, _081056DC @ =0x00000734
	adds r0, r5, r1
	ldr r1, _081056E0 @ =0x00013880
	str r1, [r0]
	ldr r2, _081056E4 @ =0x0000075C
	adds r0, r5, r2
	str r1, [r0]
	movs r0, #0xec
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r0, r3, r2
	ldr r0, [r0]
	b _081057A2
	.align 2, 0
_081056DC: .4byte 0x00000734
_081056E0: .4byte 0x00013880
_081056E4: .4byte 0x0000075C
_081056E8:
	ldr r0, _0810571C @ =0x00000734
	adds r1, r5, r0
	movs r0, #0xc8
	lsls r0, r0, #9
	str r0, [r1]
	movs r1, #0xe7
	lsls r1, r1, #3
	adds r2, r5, r1
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r0, [r0]
	str r0, [r2]
	ldr r3, _08105720 @ =0x0000073C
	adds r0, r5, r3
	ldr r1, _08105724 @ =0x00014E1F
	str r1, [r0]
	adds r3, #0x20
	adds r0, r5, r3
	str r1, [r0]
	movs r0, #0xec
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r0, [r2]
	b _081057A2
	.align 2, 0
_0810571C: .4byte 0x00000734
_08105720: .4byte 0x0000073C
_08105724: .4byte 0x00014E1F
_08105728:
	ldr r2, _08105760 @ =0x00000734
	adds r1, r5, r2
	movs r0, #0xc8
	lsls r0, r0, #9
	str r0, [r1]
	movs r0, #0xe7
	lsls r0, r0, #3
	adds r4, r5, r0
	movs r2, #0xf4
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r0, [r1]
	str r0, [r4]
	ldr r1, [r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r1, #0xa
	bl Div
	adds r1, r0, #0
	ldr r3, _08105764 @ =0x0000075C
	adds r0, r5, r3
	str r1, [r0]
	movs r0, #0xec
	lsls r0, r0, #3
	adds r1, r5, r0
	b _081057A0
	.align 2, 0
_08105760: .4byte 0x00000734
_08105764: .4byte 0x0000075C
_08105768:
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r4, r3, r1
	ldr r0, [r4]
	lsls r0, r0, #2
	movs r1, #0xa
	bl Div
	adds r1, r0, #0
	ldr r2, _081057AC @ =0x00000734
	adds r0, r5, r2
	str r1, [r0]
	movs r3, #0xe7
	lsls r3, r3, #3
	adds r1, r5, r3
	ldr r0, [r4]
	str r0, [r1]
	ldr r0, _081057B0 @ =0x0000073C
	adds r1, r5, r0
	ldr r0, [r4]
	str r0, [r1]
	adds r2, #0x28
	adds r1, r5, r2
	movs r0, #0xc8
	lsls r0, r0, #9
	str r0, [r1]
	adds r3, #0x28
	adds r1, r5, r3
_081057A0:
	ldr r0, [r4]
_081057A2:
	str r0, [r1]
_081057A4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081057AC: .4byte 0x00000734
_081057B0: .4byte 0x0000073C

	thumb_func_start FUN_081057b4
FUN_081057b4: @ 0x081057B4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081057E8 @ =0x000001DF
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #8
	bne _081057C4
	b _081058EE
_081057C4:
	movs r0, #0xa0
	lsls r0, r0, #2
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r4, r3
	ldrh r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _08105826
	ldrb r0, [r2]
	cmp r0, #6
	beq _08105806
	cmp r0, #6
	bgt _081057EC
	cmp r0, #5
	beq _081057F2
	b _081058EE
	.align 2, 0
_081057E8: .4byte 0x000001DF
_081057EC:
	cmp r0, #7
	beq _081058A4
	b _081058EE
_081057F2:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x76
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0x30
	b _081058C2
_08105806:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x78
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0x32
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0x24
	b _081058C2
_08105826:
	ldrb r0, [r2]
	cmp r0, #6
	beq _08105850
	cmp r0, #6
	bgt _08105836
	cmp r0, #5
	beq _0810583C
	b _081058EE
_08105836:
	cmp r0, #7
	beq _0810589A
	b _081058EE
_0810583C:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #6
	b _081058C2
_08105850:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r1, r0
	cmp r1, #0
	beq _0810587A
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x78
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0x32
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0x24
	b _081058C2
_0810587A:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #8
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0x21
	b _081058C2
_0810589A:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r1, r0
	cmp r1, #0
	beq _081058CA
_081058A4:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x7a
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0x34
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0x2a
_081058C2:
	movs r3, #0
	bl FUN_080ef84c
	b _081058EE
_081058CA:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #4
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0xa
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0x27
	movs r3, #0
	bl FUN_080ef84c
_081058EE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081058f4
FUN_081058f4: @ 0x081058F4
	push {lr}
	mov ip, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, ip
	ldr r3, [r0]
	movs r0, #0x90
	lsls r0, r0, #3
	add r0, ip
	ldrh r0, [r0]
	cmp r0, #2
	beq _081059E0
	cmp r0, #2
	bgt _08105916
	cmp r0, #0
	beq _08105922
	b _08105AB0
_08105916:
	cmp r0, #5
	beq _08105922
	cmp r0, #8
	bne _08105920
	b _08105A4C
_08105920:
	b _08105AB0
_08105922:
	ldr r0, _08105930 @ =0x000001DF
	add r0, ip
	ldrb r0, [r0]
	cmp r0, #5
	bne _08105938
	ldr r1, _08105934 @ =0x00000744
	b _08105A9A
	.align 2, 0
_08105930: .4byte 0x000001DF
_08105934: .4byte 0x00000744
_08105938:
	cmp r0, #7
	bne _08105978
	movs r0, #0xc2
	lsls r0, r0, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _08105964 @ =0x00000546
	add r0, ip
	ldrh r0, [r0]
	cmp r1, r0
	blt _08105970
	movs r1, #0x80
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r3, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08105968
	movs r0, #1
	b _0810596A
	.align 2, 0
_08105964: .4byte 0x00000546
_08105968:
	movs r0, #0
_0810596A:
	cmp r0, #0
	bne _08105970
	b _08105A98
_08105970:
	ldr r1, _08105974 @ =0x00000744
	b _08105A9A
	.align 2, 0
_08105974: .4byte 0x00000744
_08105978:
	movs r0, #0xf2
	lsls r0, r0, #1
	add r0, ip
	ldr r2, _081059D0 @ =0x00000734
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _08105998
	ldr r1, _081059D4 @ =0x00000744
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _08105998
	b _08105AA4
_08105998:
	movs r0, #0xf2
	lsls r0, r0, #1
	add r0, ip
	movs r2, #0xe7
	lsls r2, r2, #3
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _081059B8
	ldr r1, _081059D8 @ =0x00000746
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _08105AA4
_081059B8:
	movs r0, #0xf2
	lsls r0, r0, #1
	add r0, ip
	ldr r2, _081059DC @ =0x0000073C
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _08105AB0
	movs r1, #0xe9
	lsls r1, r1, #3
	b _08105A9A
	.align 2, 0
_081059D0: .4byte 0x00000734
_081059D4: .4byte 0x00000744
_081059D8: .4byte 0x00000746
_081059DC: .4byte 0x0000073C
_081059E0:
	movs r0, #0xc2
	lsls r0, r0, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _08105A28 @ =0x00000546
	add r0, ip
	ldrh r0, [r0]
	cmp r1, r0
	bge _08105A34
	movs r0, #0xf2
	lsls r0, r0, #1
	add r0, ip
	ldr r2, _08105A2C @ =0x00000734
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _08105A12
	ldr r1, _08105A30 @ =0x00000744
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _08105AA4
_08105A12:
	movs r0, #0xf2
	lsls r0, r0, #1
	add r0, ip
	movs r2, #0xe7
	lsls r2, r2, #3
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _08105AB0
	b _08105A98
	.align 2, 0
_08105A28: .4byte 0x00000546
_08105A2C: .4byte 0x00000734
_08105A30: .4byte 0x00000744
_08105A34:
	ldr r1, _08105A48 @ =0x00000744
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _08105AA4
	movs r1, #0xe9
	lsls r1, r1, #3
	b _08105A9A
	.align 2, 0
_08105A48: .4byte 0x00000744
_08105A4C:
	movs r0, #0xc2
	lsls r0, r0, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _08105A80 @ =0x00000546
	add r0, ip
	ldrh r0, [r0]
	cmp r1, r0
	bge _08105A8C
	ldr r1, _08105A84 @ =0x00000744
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _08105AA4
	ldr r1, _08105A88 @ =0x00000746
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _08105AA4
	movs r1, #0xe9
	lsls r1, r1, #3
	b _08105A9A
	.align 2, 0
_08105A80: .4byte 0x00000546
_08105A84: .4byte 0x00000744
_08105A88: .4byte 0x00000746
_08105A8C:
	ldr r1, _08105AA8 @ =0x00000744
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _08105AA4
_08105A98:
	ldr r1, _08105AAC @ =0x00000746
_08105A9A:
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _08105AB0
_08105AA4:
	movs r0, #1
	b _08105AB2
	.align 2, 0
_08105AA8: .4byte 0x00000744
_08105AAC: .4byte 0x00000746
_08105AB0:
	movs r0, #0
_08105AB2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08105ab8
FUN_08105ab8: @ 0x08105AB8
	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r2, [r0]
	ldr r3, _08105B14 @ =0x00000744
	adds r1, r2, r3
	ldrh r3, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	ble _08105AD4
	subs r0, r3, #1
	strh r0, [r1]
_08105AD4:
	ldr r0, _08105B18 @ =0x00000746
	adds r1, r2, r0
	ldrh r3, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	ble _08105AE6
	subs r0, r3, #1
	strh r0, [r1]
_08105AE6:
	movs r0, #0xe9
	lsls r0, r0, #3
	adds r1, r2, r0
	ldrh r3, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	ble _08105AFA
	subs r0, r3, #1
	strh r0, [r1]
_08105AFA:
	ldr r0, _08105B1C @ =0x0000074A
	adds r1, r2, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _08105B0C
	subs r0, r2, #1
	strh r0, [r1]
_08105B0C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08105B14: .4byte 0x00000744
_08105B18: .4byte 0x00000746
_08105B1C: .4byte 0x0000074A

	thumb_func_start FUN_08105b20
FUN_08105b20: @ 0x08105B20
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sb, r0
	str r1, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r1, _08105B5C @ =0x00000256
	add r1, sb
	str r1, [sp, #0x10]
	mov r2, sb
	adds r2, #8
	str r2, [sp, #0x18]
	str r2, [sp, #0x14]
	ldr r0, _08105B60 @ =0x030046A4
	mov sl, r0
_08105B46:
	ldr r1, [sp, #0x10]
	ldrh r6, [r1]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08105B64
	adds r0, #4
	b _08105B70
	.align 2, 0
_08105B5C: .4byte 0x00000256
_08105B60: .4byte 0x030046A4
_08105B64:
	mov r2, sl
	ldr r0, [r2]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08105B70:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08105B84
	cmp r3, #2
	beq _08105B8A
	b _08105B90
_08105B84:
	ldr r1, [sp, #0x14]
	ldrb r0, [r1, #4]
	b _08105B8E
_08105B8A:
	ldr r1, [sp, #0x14]
	ldrb r0, [r1]
_08105B8E:
	subs r2, r2, r0
_08105B90:
	mov r8, r2
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08105BA2
	adds r0, #4
	b _08105BAE
_08105BA2:
	mov r2, sl
	ldr r0, [r2]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08105BAE:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _08105BC0
	asrs r0, r0, #6
	b _08105BC6
_08105BC0:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08105BC6:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _08105C04
	cmp r1, #1
	bgt _08105BD8
	cmp r1, #0
	beq _08105BE2
	b _08105CB8
_08105BD8:
	cmp r1, #2
	beq _08105C40
	cmp r1, #3
	beq _08105C62
	b _08105CB8
_08105BE2:
	adds r4, r6, #1
	movs r5, #0
_08105BE6:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08105C00
	adds r4, #1
	adds r5, #1
	cmp r5, #1
	blt _08105BE6
_08105C00:
	subs r5, r4, #1
	b _08105CBC
_08105C04:
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r6, r0
	movs r5, #0
_08105C12:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08105C9C
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #1
	blt _08105C12
	ldr r2, _08105C3C @ =0x030046A4
	b _08105C9E
	.align 2, 0
_08105C3C: .4byte 0x030046A4
_08105C40:
	subs r4, r6, #1
	movs r5, #0
_08105C44:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08105C5E
	subs r4, #1
	adds r5, #1
	cmp r5, #1
	blt _08105C44
_08105C5E:
	adds r5, r4, #1
	b _08105CBC
_08105C62:
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r6, r0
	movs r5, #0
_08105C70:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08105CAA
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	adds r5, #1
	cmp r5, #1
	blt _08105C70
	ldr r2, _08105C98 @ =0x030046A4
	b _08105CAC
	.align 2, 0
_08105C98: .4byte 0x030046A4
_08105C9C:
	mov r2, sl
_08105C9E:
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r4, r0
	b _08105CBC
_08105CAA:
	mov r2, sl
_08105CAC:
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r5, r4, r0
	b _08105CBC
_08105CB8:
	ldr r2, [sp, #0x10]
	ldrh r5, [r2]
_08105CBC:
	ldr r0, [sp, #0x10]
	ldrh r0, [r0]
	cmp r5, r0
	bne _08105CD8
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x40
	strb r0, [r1, #5]
	ldr r2, [sp, #0xc]
	adds r2, #1
	str r2, [sp, #0xc]
	cmp r2, #3
	bgt _08105CD8
	b _08105B46
_08105CD8:
	mov r0, sp
	ldrb r1, [r0, #8]
	mov r0, sb
	strb r1, [r0, #5]
	mov r8, sp
	ldr r6, _08105D1C @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
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
	beq _08105D20
	adds r0, #4
	b _08105D2A
	.align 2, 0
_08105D1C: .4byte 0x030046A4
_08105D20:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08105D2A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r0, _08105D70 @ =0x000004A4
	add r0, sb
	ldr r4, [r0]
	adds r0, r4, #0
	ldr r1, [sp, #0x18]
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	beq _08105D74
	adds r0, r4, #0
	ldr r1, [sp, #0x18]
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08105D74
	cmp r0, #2
	beq _08105D6C
	mov r0, sb
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08105D6C:
	movs r0, #1
	b _08105D84
	.align 2, 0
_08105D70: .4byte 0x000004A4
_08105D74:
	movs r0, #0xc0
	lsls r0, r0, #1
	add r0, sb
	ldr r1, _08105D8C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08105D84:
	cmp r0, #0
	beq _08105D90
	movs r0, #1
	b _08105D9E
	.align 2, 0
_08105D8C: .4byte 0xFFFFFDFF
_08105D90:
	ldr r0, _08105DB0 @ =0x000005C4
	add r0, sb
	ldr r1, [r0]
	mov r0, sb
	bl _call_via_r1
	movs r0, #0
_08105D9E:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08105DB0: .4byte 0x000005C4

	thumb_func_start FUN_08105db4
FUN_08105db4: @ 0x08105DB4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sl, r0
	str r1, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r1, _08105E04 @ =0x00000256
	add r1, sl
	str r1, [sp, #0x10]
	mov r2, sl
	adds r2, #8
	str r2, [sp, #0x18]
	str r2, [sp, #0x14]
_08105DD6:
	ldr r2, _08105E08 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08105E0C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08105E10 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r7, r0, #1
	ldr r2, [sp, #0x10]
	ldrh r6, [r2]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08105E14
	adds r0, #4
	b _08105E20
	.align 2, 0
_08105E04: .4byte 0x00000256
_08105E08: .4byte 0x030046B8
_08105E0C: .4byte 0x000003FF
_08105E10: .4byte 0x0203B400
_08105E14:
	ldr r1, _08105E34 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08105E20:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08105E38
	cmp r3, #2
	beq _08105E3E
	b _08105E44
	.align 2, 0
_08105E34: .4byte 0x030046A4
_08105E38:
	ldr r1, [sp, #0x14]
	ldrb r0, [r1, #4]
	b _08105E42
_08105E3E:
	ldr r1, [sp, #0x14]
	ldrb r0, [r1]
_08105E42:
	subs r2, r2, r0
_08105E44:
	mov sb, r2
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08105E56
	adds r0, #4
	b _08105E62
_08105E56:
	ldr r2, _08105E78 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08105E62:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov r8, r0
	mov r1, sl
	ldrb r0, [r1, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _08105E7C
	asrs r0, r0, #6
	b _08105E82
	.align 2, 0
_08105E78: .4byte 0x030046A4
_08105E7C:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08105E82:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _08105EC2
	cmp r1, #1
	bgt _08105E94
	cmp r1, #0
	beq _08105E9E
	b _08105F90
_08105E94:
	cmp r1, #2
	beq _08105F00
	cmp r1, #3
	beq _08105F24
	b _08105F90
_08105E9E:
	adds r4, r6, #1
	movs r5, #0
	cmp r5, r7
	bge _08105F60
_08105EA6:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	mov r3, r8
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08105F60
	adds r4, #1
	adds r5, #1
	cmp r5, r7
	blt _08105EA6
	b _08105F60
_08105EC2:
	ldr r2, _08105EFC @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r6, r0
	movs r5, #0
	cmp r5, r7
	bge _08105F64
_08105ED4:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	mov r3, r8
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08105F64
	ldr r2, _08105EFC @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	adds r5, #1
	cmp r5, r7
	blt _08105ED4
	b _08105F64
	.align 2, 0
_08105EFC: .4byte 0x030046A4
_08105F00:
	subs r4, r6, #1
	movs r5, #0
	cmp r5, r7
	bge _08105F78
_08105F08:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	mov r3, r8
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08105F78
	subs r4, #1
	adds r5, #1
	cmp r5, r7
	blt _08105F08
	b _08105F78
_08105F24:
	ldr r2, _08105F5C @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r6, r0
	movs r5, #0
	cmp r5, r7
	bge _08105F7C
_08105F36:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	mov r3, r8
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08105F7C
	ldr r2, _08105F5C @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	adds r5, #1
	cmp r5, r7
	blt _08105F36
	b _08105F7C
	.align 2, 0
_08105F5C: .4byte 0x030046A4
_08105F60:
	subs r5, r4, #1
	b _08105F94
_08105F64:
	ldr r2, _08105F74 @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r4, r0
	b _08105F94
	.align 2, 0
_08105F74: .4byte 0x030046A4
_08105F78:
	adds r5, r4, #1
	b _08105F94
_08105F7C:
	ldr r2, _08105F8C @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r5, r4, r0
	b _08105F94
	.align 2, 0
_08105F8C: .4byte 0x030046A4
_08105F90:
	ldr r2, [sp, #0x10]
	ldrh r5, [r2]
_08105F94:
	ldr r0, [sp, #0x10]
	ldrh r0, [r0]
	cmp r5, r0
	bne _08105FB0
	mov r1, sl
	ldrb r0, [r1, #5]
	adds r0, #0x40
	strb r0, [r1, #5]
	ldr r2, [sp, #0xc]
	adds r2, #1
	str r2, [sp, #0xc]
	cmp r2, #3
	bgt _08105FB0
	b _08105DD6
_08105FB0:
	mov r0, sp
	ldrb r1, [r0, #8]
	mov r0, sl
	strb r1, [r0, #5]
	mov r8, sp
	ldr r6, _08105FF4 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
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
	beq _08105FF8
	adds r0, #4
	b _08106002
	.align 2, 0
_08105FF4: .4byte 0x030046A4
_08105FF8:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08106002:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r0, _08106048 @ =0x000004A4
	add r0, sl
	ldr r4, [r0]
	adds r0, r4, #0
	ldr r1, [sp, #0x18]
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	beq _0810604C
	adds r0, r4, #0
	ldr r1, [sp, #0x18]
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _0810604C
	cmp r0, #2
	beq _08106044
	mov r0, sl
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08106044:
	movs r0, #1
	b _0810605C
	.align 2, 0
_08106048: .4byte 0x000004A4
_0810604C:
	movs r0, #0xc0
	lsls r0, r0, #1
	add r0, sl
	ldr r1, _08106064 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0810605C:
	cmp r0, #0
	beq _08106068
	movs r0, #1
	b _08106076
	.align 2, 0
_08106064: .4byte 0xFFFFFDFF
_08106068:
	ldr r0, _08106088 @ =0x000005C4
	add r0, sl
	ldr r1, [r0]
	mov r0, sl
	bl _call_via_r1
	movs r0, #0
_08106076:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08106088: .4byte 0x000005C4

	thumb_func_start FUN_0810608c
FUN_0810608c: @ 0x0810608C
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0xea
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r0, [r4]
	cmp r0, #0
	ble _0810618C
	adds r0, r5, #0
	bl FUN_080f00ec
	ldr r1, _08106108 @ =0x00000222
	adds r2, r5, r1
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0x14
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
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
	blt _08106102
	cmp r1, #0
	blt _08106102
	ldr r0, _0810610C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08106102
	ldr r0, _08106110 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08106114
_08106102:
	movs r1, #0
	b _08106122
	.align 2, 0
_08106108: .4byte 0x00000222
_0810610C: .4byte 0x030046A8
_08106110: .4byte 0x030046AC
_08106114:
	ldr r0, _08106180 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_08106122:
	ldr r3, _08106184 @ =0x0000025E
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
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r1, r1, r2
	ldr r0, _08106188 @ =0xFFFFFCFF
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
	movs r0, #1
	b _081061A4
	.align 2, 0
_08106180: .4byte 0x030046A4
_08106184: .4byte 0x0000025E
_08106188: .4byte 0xFFFFFCFF
_0810618C:
	movs r0, #8
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r3, [r1]
	ands r0, r3
	cmp r0, #0
	beq _081061A2
	ldr r0, _081061AC @ =0xF7FFFFFF
	ands r3, r0
	str r3, [r1]
_081061A2:
	movs r0, #0
_081061A4:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081061AC: .4byte 0xF7FFFFFF

	thumb_func_start FUN_081061b0
FUN_081061b0: @ 0x081061B0
	push {r4, lr}
	adds r3, r0, #0
	movs r1, #8
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r4, r3, r0
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081061D8
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blo _081061DC
_081061D8:
	movs r0, #0
	b _081061F6
_081061DC:
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
_081061F6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081061fc
FUN_081061fc: @ 0x081061FC
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
	bne _0810622C
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #2
	bne _08106226
	adds r0, r2, #0
	bl FUN_08104220
	b _0810622C
_08106226:
	adds r0, r2, #0
	bl FUN_08103cb0
_0810622C:
	pop {r0}
	bx r0

	thumb_func_start FUN_08106230
FUN_08106230: @ 0x08106230
	bx lr
	.align 2, 0

	thumb_func_start FUN_08106234
FUN_08106234: @ 0x08106234
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r1, _0810627C @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	beq _08106248
	b _08106340
_08106248:
	adds r7, r4, #0
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #2
	bne _08106330
	movs r0, #0x4f
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081062BC
	movs r5, #0
	movs r0, #0
	mov r8, r0
	movs r6, #0
_08106268:
	ldr r1, _08106280 @ =0x0000079E
	adds r0, r7, r1
	adds r4, r0, r6
	bl VM_GetPC
	cmp r0, #0
	beq _08106284
	bl Script_GetValue
	b _08106286
	.align 2, 0
_0810627C: .4byte 0x000001DF
_08106280: .4byte 0x0000079E
_08106284:
	movs r0, #0
_08106286:
	strh r0, [r4]
	movs r2, #0xf3
	lsls r2, r2, #3
	adds r0, r7, r2
	adds r4, r0, r6
	bl VM_GetPC
	cmp r0, #0
	beq _0810629E
	bl Script_GetValue
	b _081062A0
_0810629E:
	movs r0, #0
_081062A0:
	strh r0, [r4]
	ldr r1, _081062B8 @ =0x000007A4
	adds r0, r7, r1
	adds r0, r0, r5
	mov r2, r8
	strb r2, [r0]
	adds r6, #2
	adds r5, #1
	cmp r5, #2
	ble _08106268
	b _081062DA
	.align 2, 0
_081062B8: .4byte 0x000007A4
_081062BC:
	movs r5, #0
	movs r6, #0
	movs r2, #0
	ldr r0, _081062F4 @ =0x000007A4
	adds r3, r4, r0
	subs r0, #0xc
	adds r1, r4, r0
_081062CA:
	strh r2, [r1, #6]
	strh r2, [r1]
	adds r0, r3, r5
	strb r6, [r0]
	adds r1, #2
	adds r5, #1
	cmp r5, #2
	ble _081062CA
_081062DA:
	movs r0, #0x54
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0810631C
	bl VM_GetPC
	cmp r0, #0
	beq _081062F8
	bl Script_GetValue
	adds r1, r0, #0
	b _081062FA
	.align 2, 0
_081062F4: .4byte 0x000007A4
_081062F8:
	movs r1, #0
_081062FA:
	ldr r2, _08106310 @ =0x0000071C
	adds r0, r7, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08106314
	bl Script_GetValue
	adds r1, r0, #0
	b _08106316
	.align 2, 0
_08106310: .4byte 0x0000071C
_08106314:
	movs r1, #0
_08106316:
	ldr r2, _08106328 @ =0x0000071E
	adds r0, r7, r2
	strh r1, [r0]
_0810631C:
	ldr r0, _0810632C @ =0x00000755
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
	b _08106340
	.align 2, 0
_08106328: .4byte 0x0000071E
_0810632C: .4byte 0x00000755
_08106330:
	movs r0, #0x73
	movs r1, #0
	bl VM_GetKeywordValue
	movs r2, #0xe4
	lsls r2, r2, #3
	adds r1, r4, r2
	strh r0, [r1]
_08106340:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0810634c
FUN_0810634c: @ 0x0810634C
	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08106370
	movs r0, #0x1f
	bl FUN_080ecf60
	cmp r0, #0
	bne _08106370
	movs r0, #1
	b _08106372
_08106370:
	movs r0, #0
_08106372:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08106378
FUN_08106378: @ 0x08106378
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	ldr r1, _081063D0 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _08106440
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #8
	bne _08106440
	subs r1, #0x13
	adds r0, r4, r1
	ldr r7, [r0]
	adds r0, r4, #0
	bl FUN_0810634c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08106440
	ldrb r0, [r4, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	add r3, sp, #0xc
	lsls r5, r0, #6
	ldr r2, _081063D4 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	adds r6, r3, #0
	cmp r0, #0
	blt _081063D8
	asrs r1, r0, #0xc
	b _081063DE
	.align 2, 0
_081063D0: .4byte 0x000001DF
_081063D4: .4byte 0x085B0A08
_081063D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081063DE:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _081063FA
	asrs r0, r0, #0xc
	b _08106400
_081063FA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08106400:
	strh r0, [r3, #4]
	movs r1, #8
	ldrsh r0, [r4, r1]
	movs r2, #0
	ldrsh r1, [r6, r2]
	adds r0, r0, r1
	str r0, [sp]
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	str r0, [sp, #4]
	movs r2, #0xc
	ldrsh r0, [r4, r2]
	add r1, sp, #0xc
	movs r2, #4
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	str r0, [sp, #8]
	ldr r1, _08106448 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	mov r0, sp
	str r0, [r1, #4]
	movs r2, #0xe4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrh r0, [r0]
	bl Script_ExecById
_08106440:
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08106448: .4byte 0xFFFF0000

	thumb_func_start FUN_0810644c
FUN_0810644c: @ 0x0810644C
	push {lr}
	movs r0, #2
_08106450:
	subs r0, #1
	cmp r0, #0
	bge _08106450
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0810645c
FUN_0810645c: @ 0x0810645C
	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r2, #0
	ldr r4, _08106484 @ =0x000007A4
	adds r3, r0, r4
	subs r4, #0xc
	adds r1, r0, r4
_08106470:
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08106488
	ldrh r0, [r1]
	cmp r0, #0
	beq _08106488
	movs r0, #1
	b _08106492
	.align 2, 0
_08106484: .4byte 0x000007A4
_08106488:
	adds r1, #2
	adds r2, #1
	cmp r2, #2
	ble _08106470
	movs r0, #0
_08106492:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08106498
FUN_08106498: @ 0x08106498
	push {r4, r5, lr}
	sub sp, #0x18
	adds r2, r0, #0
	ldr r1, _08106538 @ =0x000001DF
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _08106530
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r4, [r0]
	movs r5, #0
	ldr r1, _0810653C @ =0x000007A4
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081064C8
	movs r3, #0xf3
	lsls r3, r3, #3
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _081064EA
_081064C8:
	adds r5, #1
	cmp r5, #2
	bgt _08106530
	ldr r1, _0810653C @ =0x000007A4
	adds r0, r4, r1
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _081064C8
	lsls r0, r5, #1
	movs r3, #0xf3
	lsls r3, r3, #3
	adds r1, r4, r3
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081064C8
_081064EA:
	cmp r5, #2
	bgt _08106530
	movs r1, #8
	ldrsh r0, [r2, r1]
	str r0, [sp]
	movs r3, #0xa
	ldrsh r0, [r2, r3]
	str r0, [sp, #4]
	movs r1, #0xc
	ldrsh r0, [r2, r1]
	str r0, [sp, #8]
	ldrb r0, [r2, #5]
	str r0, [sp, #0xc]
	ldr r1, _08106540 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	str r0, [sp, #0x10]
	add r1, sp, #0x10
	mov r3, sp
	str r3, [r1, #4]
	lsls r2, r5, #1
	movs r3, #0xf3
	lsls r3, r3, #3
	adds r0, r4, r3
	adds r0, r0, r2
	ldrh r0, [r0]
	bl Script_ExecById
	ldr r1, _0810653C @ =0x000007A4
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #1
	strb r1, [r0]
_08106530:
	add sp, #0x18
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08106538: .4byte 0x000001DF
_0810653C: .4byte 0x000007A4
_08106540: .4byte 0xFFFF0000

	thumb_func_start FUN_08106544
FUN_08106544: @ 0x08106544
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	subs r1, #0xcc
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081065C6
	ldr r4, _081065CC @ =0x0000070E
	adds r4, r4, r2
	mov ip, r4
	ldrb r6, [r4]
	cmp r6, #0
	bne _081065C6
	ldr r7, _081065D0 @ =0x0000070D
	adds r0, r2, r7
	ldrb r0, [r0]
	cmp r0, #0
	beq _081065C6
	ldr r2, _081065D4 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r3, _081065D8 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #1
	strb r3, [r0]
	ldr r4, _081065DC @ =0x0000046B
	adds r0, r5, r4
	strb r6, [r0]
	ldr r7, _081065E0 @ =0x00000553
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r1, #0
	strh r6, [r0]
	movs r2, #2
	movs r4, #4
	subs r7, #0xeb
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _081065E4 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	adds r7, #2
	adds r0, r5, r7
	strb r4, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r6, [r0]
	ldr r4, _081065E8 @ =0x0000046C
	adds r0, r5, r4
	strb r3, [r0]
	mov r7, ip
	strb r3, [r7]
_081065C6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081065CC: .4byte 0x0000070E
_081065D0: .4byte 0x0000070D
_081065D4: .4byte FUN_080e48d0
_081065D8: .4byte 0x0000046D
_081065DC: .4byte 0x0000046B
_081065E0: .4byte 0x00000553
_081065E4: .4byte 0x00000469
_081065E8: .4byte 0x0000046C

	thumb_func_start FUN_081065ec
FUN_081065ec: @ 0x081065EC
	push {r4, r5, r6, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r6, [r0]
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0810663E
	movs r4, #0
_08106602:
	lsls r0, r4, #1
	ldr r2, _08106618 @ =0x0000074C
	adds r1, r6, r2
	adds r5, r1, r0
	bl VM_GetPC
	cmp r0, #0
	beq _0810661C
	bl Script_GetValue
	b _0810661E
	.align 2, 0
_08106618: .4byte 0x0000074C
_0810661C:
	movs r0, #0
_0810661E:
	strh r0, [r5]
	adds r4, #1
	cmp r4, #3
	ble _08106602
	bl VM_GetPC
	cmp r0, #0
	beq _08106636
	bl Script_GetValue
	adds r1, r0, #0
	b _08106638
_08106636:
	movs r1, #0
_08106638:
	ldr r2, _08106644 @ =0x0000075A
	adds r0, r6, r2
	strh r1, [r0]
_0810663E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08106644: .4byte 0x0000075A

	thumb_func_start FUN_08106648
FUN_08106648: @ 0x08106648
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc0
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r4, [r0]
	ldr r1, _081066F4 @ =0x08251FE4
	ldr r2, _081066F8 @ =0x00000679
	adds r0, r7, #0
	bl FUN_080e6768
	ldr r2, _081066FC @ =0x00000757
	adds r1, r4, r2
	ldrb r0, [r1]
	adds r0, #1
	movs r5, #0
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r6, _08106700 @ =0x0000075C
	adds r1, r4, r6
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _0810671C
	ldrb r1, [r7, #5]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	adds r0, #0x80
	strb r0, [r7, #5]
	adds r0, r7, #0
	bl FUN_08105b20
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081066A4
	bl _08107444
_081066A4:
	ldr r2, _08106704 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r3, _08106708 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r4, _0810670C @ =0x0000046B
	adds r0, r7, r4
	strb r5, [r0]
	ldr r6, _08106710 @ =0x00000553
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
	movs r2, #0xf
	subs r4, #3
	adds r0, r7, r4
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08106714 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _08106718 @ =0x00000484
	adds r0, r7, r2
	str r5, [r0]
	adds r4, #4
	adds r0, r7, r4
	strb r3, [r0]
	bl _08107444
	.align 2, 0
_081066F4: .4byte 0x08251FE4
_081066F8: .4byte 0x00000679
_081066FC: .4byte 0x00000757
_08106700: .4byte 0x0000075C
_08106704: .4byte FUN_080e48d0
_08106708: .4byte 0x0000046D
_0810670C: .4byte 0x0000046B
_08106710: .4byte 0x00000553
_08106714: .4byte 0x0000046A
_08106718: .4byte 0x00000484
_0810671C:
	movs r5, #0xec
	lsls r5, r5, #3
	adds r0, r4, r5
	ldr r0, [r0]
	cmp r2, r0
	bhi _0810672A
	b _08106DB8
_0810672A:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, [r1]
	cmp r0, #0
	bne _0810673E
	ldr r0, _08106780 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
_0810673E:
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
	str r3, [sp, #0x9c]
	str r2, [sp, #0xb8]
	cmp r4, #0
	blt _0810677A
	cmp r1, #0
	blt _0810677A
	ldr r0, _08106784 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0810677A
	ldr r0, _08106788 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810678C
_0810677A:
	movs r4, #0
	b _0810679A
	.align 2, 0
_08106780: .4byte 0x03002BE0
_08106784: .4byte 0x030046A8
_08106788: .4byte 0x030046AC
_0810678C:
	ldr r0, _081067AC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0810679A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081067B0
	adds r0, #4
	b _081067BC
	.align 2, 0
_081067AC: .4byte 0x030046A4
_081067B0:
	ldr r0, _081067D0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081067BC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081067D4
	cmp r2, #2
	beq _081067D8
	b _081067DC
	.align 2, 0
_081067D0: .4byte 0x030046A4
_081067D4:
	ldrb r0, [r5, #4]
	b _081067DA
_081067D8:
	ldrb r0, [r5]
_081067DA:
	subs r1, r1, r0
_081067DC:
	strh r1, [r5, #2]
	ldr r0, _081067F0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081067F4
	movs r0, #1
	b _081067F6
	.align 2, 0
_081067F0: .4byte 0x030047A4
_081067F4:
	movs r0, #0
_081067F6:
	cmp r0, #0
	beq _08106834
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08106816
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08106812
	adds r2, r0, #0
_08106812:
	cmp r2, #0
	bge _08106820
_08106816:
	ldr r2, _0810681C @ =0x000005C4
	adds r0, r7, r2
	b _08106D50
	.align 2, 0
_0810681C: .4byte 0x000005C4
_08106820:
	ldr r1, _08106830 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0810687C
	.align 2, 0
_08106830: .4byte 0x03002BE0
_08106834:
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
	blt _08106860
	cmp r1, #0
	blt _08106860
	ldr r0, _08106864 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08106860
	ldr r0, _08106868 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810686C
_08106860:
	movs r5, #0
	b _0810687A
	.align 2, 0
_08106864: .4byte 0x030046A8
_08106868: .4byte 0x030046AC
_0810686C:
	ldr r0, _081068BC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0810687A:
	movs r2, #0
_0810687C:
	ldr r4, _081068C0 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0810689C
	ldr r1, _081068C4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0810689C
	b _08106C94
_0810689C:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x10]
	str r2, [sp, #0x74]
	cmp r1, #0
	beq _081068C8
	movs r0, #0
	b _08106D66
	.align 2, 0
_081068BC: .4byte 0x030046A4
_081068C0: .4byte 0x00000256
_081068C4: .4byte 0x03002BE0
_081068C8:
	ldr r6, _0810696C @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x74]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xa0]
	cmp r6, #0
	beq _08106980
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _08106970 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x14]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _08106974 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x18]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x1c]
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r5, r7
	mov r8, r5
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	mov r0, sp
	ldrh r0, [r0, #0x10]
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r3, [r4]
	ldr r2, _08106978 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _0810697C @ =0x00000484
	adds r1, r7, r6
	ldr r0, [sp, #0x10]
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x8c]
	ldr r6, [sp, #0x18]
	str r6, [sp, #0x84]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0xac]
	mov r6, r8
	str r6, [sp, #0xb0]
	str r5, [sp, #0x94]
	str r4, [sp, #0x78]
	str r3, [sp, #0x7c]
	str r2, [sp, #0x80]
	str r1, [sp, #0x98]
	str r0, [sp, #0x88]
	b _08106B52
	.align 2, 0
_0810696C: .4byte 0x00000222
_08106970: .4byte 0x0000046D
_08106974: .4byte 0x0000046B
_08106978: .4byte 0x00000469
_0810697C: .4byte 0x00000484
_08106980:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _08106A44 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x20]
	strb r0, [r2]
	ldr r3, _08106A48 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x24]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _08106A4C @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x28]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x30]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x34]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _08106A50 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _08106A54 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _08106A58 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x9c]
	ldr r0, [r0]
	str r0, [sp, #0x38]
	ldr r1, [sp, #0xb8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x38]
	strh r1, [r6]
	ldr r6, [sp, #0xb8]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x38]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x8c]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0x84]
	ldr r0, [sp, #0x28]
	str r0, [sp, #0xac]
	ldr r6, [sp, #0x2c]
	str r6, [sp, #0xb0]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0x94]
	ldr r6, [sp, #0x34]
	str r6, [sp, #0x78]
	str r5, [sp, #0x7c]
	str r4, [sp, #0x80]
	str r3, [sp, #0x98]
	str r2, [sp, #0x88]
	mov r0, sl
	cmp r0, #0
	blt _08106A3E
	cmp r1, #0
	blt _08106A3E
	ldr r0, _08106A5C @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _08106A3E
	ldr r0, _08106A60 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08106A64
_08106A3E:
	movs r4, #0
	b _08106A74
	.align 2, 0
_08106A44: .4byte 0x0000046D
_08106A48: .4byte 0x0000046B
_08106A4C: .4byte 0x00000553
_08106A50: .4byte 0x00000469
_08106A54: .4byte 0x00000484
_08106A58: .4byte 0x0000046C
_08106A5C: .4byte 0x030046A8
_08106A60: .4byte 0x030046AC
_08106A64:
	ldr r0, _08106A84 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_08106A74:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08106A88
	adds r0, #4
	b _08106A94
	.align 2, 0
_08106A84: .4byte 0x030046A4
_08106A88:
	ldr r0, _08106AA8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08106A94:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08106AAC
	cmp r2, #2
	beq _08106AB2
	b _08106AB8
	.align 2, 0
_08106AA8: .4byte 0x030046A4
_08106AAC:
	ldr r2, [sp, #0x38]
	ldrb r0, [r2, #4]
	b _08106AB6
_08106AB2:
	ldr r3, [sp, #0x38]
	ldrb r0, [r3]
_08106AB6:
	subs r1, r1, r0
_08106AB8:
	ldr r4, [sp, #0x38]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x9c]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08106AE4
	cmp r1, #0
	blt _08106AE4
	ldr r0, _08106AE8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08106AE4
	ldr r0, _08106AEC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08106AF0
_08106AE4:
	movs r4, #0
	b _08106AFE
	.align 2, 0
_08106AE8: .4byte 0x030046A8
_08106AEC: .4byte 0x030046AC
_08106AF0:
	ldr r0, _08106B14 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08106AFE:
	ldr r6, [sp, #0x9c]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08106B18
	adds r0, #4
	b _08106B24
	.align 2, 0
_08106B14: .4byte 0x030046A4
_08106B18:
	ldr r0, _08106B38 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08106B24:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08106B3C
	cmp r3, #2
	beq _08106B40
	b _08106B44
	.align 2, 0
_08106B38: .4byte 0x030046A4
_08106B3C:
	ldrb r0, [r5, #4]
	b _08106B42
_08106B40:
	ldrb r0, [r5]
_08106B42:
	subs r2, r2, r0
_08106B44:
	ldr r1, [sp, #0x9c]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x9c]
	ldr r0, [r2]
	strh r1, [r0, #6]
_08106B52:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x3c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x74]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _08106B7C @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x90]
	cmp r0, #0
	bne _08106C5C
	movs r1, #4
	ldr r2, [sp, #0xa0]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08106B80
	movs r0, #1
	b _08106B82
	.align 2, 0
_08106B7C: .4byte 0x00000482
_08106B80:
	movs r0, #0
_08106B82:
	ldr r3, _08106C6C @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x90]
	cmp r0, #0
	bne _08106C5C
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0xbc]
	ldr r1, _08106C70 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _08106C74 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r6, #0xd
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _08106C78 @ =0x0000054E
	adds r0, r7, r0
	str r0, [sp, #0xa8]
	ldr r1, _08106C7C @ =0x00000541
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _08106C80 @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0xb4]
	ldr r6, _08106C84 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	ldr r1, _08106C88 @ =0x030046B8
	adds r2, r5, #0
_08106BCA:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _08106C8C @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _08106C90 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _08106BEE
	adds r3, #1
	cmp r3, #3
	ble _08106BCA
	adds r0, r5, #0
_08106BEE:
	movs r3, #0
	strb r0, [r4]
	ldr r1, [sp, #0xb0]
	ldr r0, [r1]
	ldr r2, [sp, #0xbc]
	str r0, [r2]
	ldr r4, [sp, #0xac]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x7c]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x80]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	add r0, sp, #0x3c
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb4]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x8c]
	strb r1, [r4]
	ldr r5, [sp, #0x84]
	strb r3, [r5]
	ldr r6, [sp, #0xac]
	strb r0, [r6]
	ldr r0, [sp, #0xb0]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x94]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x78]
	strb r0, [r5]
	ldr r6, [sp, #0x7c]
	strb r1, [r6]
	ldr r0, [sp, #0x80]
	strb r2, [r0]
	ldr r2, [sp, #0x98]
	str r3, [r2]
	ldr r3, [sp, #0x88]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa4]
	strb r0, [r4]
_08106C5C:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x90]
	strh r0, [r5]
	movs r0, #0
	b _08106D66
	.align 2, 0
_08106C6C: .4byte 0x00000482
_08106C70: .4byte 0x0000054F
_08106C74: .4byte 0x0000054C
_08106C78: .4byte 0x0000054E
_08106C7C: .4byte 0x00000541
_08106C80: .4byte 0x000005BC
_08106C84: .4byte 0x00000542
_08106C88: .4byte 0x030046B8
_08106C8C: .4byte 0x000003FF
_08106C90: .4byte 0x0203B400
_08106C94:
	mov sb, sp
	ldr r6, _08106CD0 @ =0x030046A4
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
	beq _08106CD4
	adds r0, #4
	b _08106CDE
	.align 2, 0
_08106CD0: .4byte 0x030046A4
_08106CD4:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08106CDE:
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
	ldr r6, _08106D14 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _08106D18
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _08106D3E
	.align 2, 0
_08106D14: .4byte 0x000004A4
_08106D18:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08106D38
	cmp r0, #2
	beq _08106D34
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08106D34:
	movs r0, #1
	b _08106D48
_08106D38:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_08106D3E:
	ldr r1, _08106D5C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08106D48:
	cmp r0, #0
	bne _08106D64
	ldr r3, _08106D60 @ =0x000005C4
	adds r0, r7, r3
_08106D50:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _08106D66
	.align 2, 0
_08106D5C: .4byte 0xFFFFFDFF
_08106D60: .4byte 0x000005C4
_08106D64:
	movs r0, #1
_08106D66:
	cmp r0, #0
	bne _08106D6C
	b _08107444
_08106D6C:
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r5, _08106DAC @ =0x0000046D
	adds r0, r7, r5
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _08106DB0 @ =0x0000046B
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
	ldr r6, _08106DB4 @ =0x00000469
	b _0810742E
	.align 2, 0
_08106DAC: .4byte 0x0000046D
_08106DB0: .4byte 0x0000046B
_08106DB4: .4byte 0x00000469
_08106DB8:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, [r1]
	cmp r0, #0
	bne _08106DCC
	ldr r0, _08106E0C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
_08106DCC:
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
	str r3, [sp, #0x9c]
	str r2, [sp, #0xb8]
	cmp r4, #0
	blt _08106E08
	cmp r1, #0
	blt _08106E08
	ldr r0, _08106E10 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _08106E08
	ldr r0, _08106E14 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08106E18
_08106E08:
	movs r4, #0
	b _08106E26
	.align 2, 0
_08106E0C: .4byte 0x03002BE0
_08106E10: .4byte 0x030046A8
_08106E14: .4byte 0x030046AC
_08106E18:
	ldr r0, _08106E38 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_08106E26:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08106E3C
	adds r0, #4
	b _08106E48
	.align 2, 0
_08106E38: .4byte 0x030046A4
_08106E3C:
	ldr r0, _08106E5C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08106E48:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08106E60
	cmp r2, #2
	beq _08106E64
	b _08106E68
	.align 2, 0
_08106E5C: .4byte 0x030046A4
_08106E60:
	ldrb r0, [r5, #4]
	b _08106E66
_08106E64:
	ldrb r0, [r5]
_08106E66:
	subs r1, r1, r0
_08106E68:
	strh r1, [r5, #2]
	ldr r0, _08106E7C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08106E80
	movs r0, #1
	b _08106E82
	.align 2, 0
_08106E7C: .4byte 0x030047A4
_08106E80:
	movs r0, #0
_08106E82:
	cmp r0, #0
	beq _08106EB8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	bne _08106E94
	b _081073D4
_08106E94:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08106EA0
	adds r2, r0, #0
_08106EA0:
	cmp r2, #0
	bge _08106EA6
	b _081073D4
_08106EA6:
	ldr r1, _08106EB4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08106F00
	.align 2, 0
_08106EB4: .4byte 0x03002BE0
_08106EB8:
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
	blt _08106EE4
	cmp r1, #0
	blt _08106EE4
	ldr r0, _08106EE8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08106EE4
	ldr r0, _08106EEC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08106EF0
_08106EE4:
	movs r5, #0
	b _08106EFE
	.align 2, 0
_08106EE8: .4byte 0x030046A8
_08106EEC: .4byte 0x030046AC
_08106EF0:
	ldr r0, _08106F40 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08106EFE:
	movs r2, #0
_08106F00:
	ldr r4, _08106F44 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _08106F20
	ldr r1, _08106F48 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08106F20
	b _08107318
_08106F20:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x40]
	str r2, [sp, #0x74]
	cmp r1, #0
	beq _08106F4C
	movs r0, #0
	b _081073EE
	.align 2, 0
_08106F40: .4byte 0x030046A4
_08106F44: .4byte 0x00000256
_08106F48: .4byte 0x03002BE0
_08106F4C:
	ldr r6, _08106FF0 @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x74]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	str r2, [sp, #0xa0]
	cmp r0, #0
	beq _08107004
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _08106FF4 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x44]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _08106FF8 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x48]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x4c]
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x50]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	add r0, sp, #0x40
	ldrh r0, [r0]
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r3, [r4]
	ldr r2, _08106FFC @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _08107000 @ =0x00000484
	adds r1, r7, r6
	ldr r0, [sp, #0x40]
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x44]
	str r6, [sp, #0x8c]
	ldr r6, [sp, #0x48]
	str r6, [sp, #0x84]
	ldr r6, [sp, #0x4c]
	str r6, [sp, #0xac]
	ldr r6, [sp, #0x50]
	str r6, [sp, #0xb0]
	str r5, [sp, #0x94]
	str r4, [sp, #0x78]
	str r3, [sp, #0x7c]
	str r2, [sp, #0x80]
	str r1, [sp, #0x98]
	str r0, [sp, #0x88]
	b _081071D6
	.align 2, 0
_08106FF0: .4byte 0x00000222
_08106FF4: .4byte 0x0000046D
_08106FF8: .4byte 0x0000046B
_08106FFC: .4byte 0x00000469
_08107000: .4byte 0x00000484
_08107004:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081070C8 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x54]
	strb r0, [r2]
	ldr r3, _081070CC @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x58]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081070D0 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x5c]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x60]
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x64]
	mov r2, ip
	strh r2, [r1]
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x68]
	strb r4, [r3]
	ldr r4, _081070D4 @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r2, _081070D8 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r6, _081070DC @ =0x00000484
	adds r3, r7, r6
	mov r1, ip
	str r1, [r3]
	subs r6, #0x18
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x9c]
	ldr r0, [r0]
	str r0, [sp, #0x6c]
	ldr r1, [sp, #0xb8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x6c]
	strh r1, [r6]
	ldr r6, [sp, #0xb8]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x6c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x54]
	str r0, [sp, #0x8c]
	ldr r6, [sp, #0x58]
	str r6, [sp, #0x84]
	ldr r0, [sp, #0x5c]
	str r0, [sp, #0xac]
	ldr r6, [sp, #0x60]
	str r6, [sp, #0xb0]
	ldr r0, [sp, #0x64]
	str r0, [sp, #0x94]
	ldr r6, [sp, #0x68]
	str r6, [sp, #0x78]
	str r5, [sp, #0x7c]
	str r4, [sp, #0x80]
	str r3, [sp, #0x98]
	str r2, [sp, #0x88]
	mov r0, sb
	cmp r0, #0
	blt _081070C4
	cmp r1, #0
	blt _081070C4
	ldr r0, _081070E0 @ =0x030046A8
	ldr r0, [r0]
	cmp sb, r0
	bhs _081070C4
	ldr r0, _081070E4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081070E8
_081070C4:
	movs r4, #0
	b _081070F8
	.align 2, 0
_081070C8: .4byte 0x0000046D
_081070CC: .4byte 0x0000046B
_081070D0: .4byte 0x00000553
_081070D4: .4byte 0x00000469
_081070D8: .4byte 0x0000046A
_081070DC: .4byte 0x00000484
_081070E0: .4byte 0x030046A8
_081070E4: .4byte 0x030046AC
_081070E8:
	ldr r0, _08107108 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sb
	adds r4, r0, r1
_081070F8:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0810710C
	adds r0, #4
	b _08107118
	.align 2, 0
_08107108: .4byte 0x030046A4
_0810710C:
	ldr r0, _0810712C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08107118:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08107130
	cmp r2, #2
	beq _08107136
	b _0810713C
	.align 2, 0
_0810712C: .4byte 0x030046A4
_08107130:
	ldr r2, [sp, #0x6c]
	ldrb r0, [r2, #4]
	b _0810713A
_08107136:
	ldr r3, [sp, #0x6c]
	ldrb r0, [r3]
_0810713A:
	subs r1, r1, r0
_0810713C:
	ldr r4, [sp, #0x6c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x9c]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08107168
	cmp r1, #0
	blt _08107168
	ldr r0, _0810716C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08107168
	ldr r0, _08107170 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08107174
_08107168:
	movs r4, #0
	b _08107182
	.align 2, 0
_0810716C: .4byte 0x030046A8
_08107170: .4byte 0x030046AC
_08107174:
	ldr r0, _08107198 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08107182:
	ldr r6, [sp, #0x9c]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0810719C
	adds r0, #4
	b _081071A8
	.align 2, 0
_08107198: .4byte 0x030046A4
_0810719C:
	ldr r0, _081071BC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081071A8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081071C0
	cmp r3, #2
	beq _081071C4
	b _081071C8
	.align 2, 0
_081071BC: .4byte 0x030046A4
_081071C0:
	ldrb r0, [r5, #4]
	b _081071C6
_081071C4:
	ldrb r0, [r5]
_081071C6:
	subs r2, r2, r0
_081071C8:
	ldr r1, [sp, #0x9c]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x9c]
	ldr r0, [r2]
	strh r1, [r0, #6]
_081071D6:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x70]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x74]
	ldrh r0, [r4]
	ands r0, r1
	adds r5, r3, #0
	ldr r6, _08107200 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x90]
	cmp r0, #0
	bne _081072E0
	movs r1, #4
	ldr r2, [sp, #0xa0]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08107204
	movs r0, #1
	b _08107206
	.align 2, 0
_08107200: .4byte 0x00000482
_08107204:
	movs r0, #0
_08107206:
	ldr r3, _081072F0 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x90]
	cmp r0, #0
	bne _081072E0
	movs r3, #0
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r4, r7, r6
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0xbc]
	ldr r1, _081072F4 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081072F8 @ =0x0000054C
	adds r2, r2, r7
	mov sb, r2
	adds r6, #0xd
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _081072FC @ =0x0000054E
	adds r0, r7, r0
	str r0, [sp, #0xa8]
	ldr r1, _08107300 @ =0x00000541
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _08107304 @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0xb4]
	ldr r6, _08107308 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	ldr r1, _0810730C @ =0x030046B8
	adds r2, r5, #0
_0810724E:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _08107310 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _08107314 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _08107272
	adds r3, #1
	cmp r3, #3
	ble _0810724E
	adds r0, r5, #0
_08107272:
	movs r3, #0
	strb r0, [r4]
	ldr r1, [sp, #0xb0]
	ldr r0, [r1]
	ldr r2, [sp, #0xbc]
	str r0, [r2]
	ldr r4, [sp, #0xac]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x7c]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x80]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	add r0, sp, #0x70
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb4]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x8c]
	strb r1, [r4]
	ldr r5, [sp, #0x84]
	strb r3, [r5]
	ldr r6, [sp, #0xac]
	strb r0, [r6]
	ldr r0, [sp, #0xb0]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x94]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x78]
	strb r0, [r5]
	ldr r6, [sp, #0x7c]
	strb r1, [r6]
	ldr r0, [sp, #0x80]
	strb r2, [r0]
	ldr r2, [sp, #0x98]
	str r3, [r2]
	ldr r3, [sp, #0x88]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa4]
	strb r0, [r4]
_081072E0:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x90]
	strh r0, [r5]
	movs r0, #0
	b _081073EE
	.align 2, 0
_081072F0: .4byte 0x00000482
_081072F4: .4byte 0x0000054F
_081072F8: .4byte 0x0000054C
_081072FC: .4byte 0x0000054E
_08107300: .4byte 0x00000541
_08107304: .4byte 0x000005BC
_08107308: .4byte 0x00000542
_0810730C: .4byte 0x030046B8
_08107310: .4byte 0x000003FF
_08107314: .4byte 0x0203B400
_08107318:
	add r6, sp, #8
	ldr r0, _08107358 @ =0x030046A4
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
	beq _0810735C
	adds r0, #4
	b _08107368
	.align 2, 0
_08107358: .4byte 0x030046A4
_0810735C:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08107368:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0810739C @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _081073A0
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
	b _081073C6
	.align 2, 0
_0810739C: .4byte 0x000004A4
_081073A0:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _081073C0
	cmp r0, #2
	beq _081073BC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081073BC:
	movs r0, #1
	b _081073D0
_081073C0:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
_081073C6:
	ldr r1, _081073E4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081073D0:
	cmp r0, #0
	bne _081073EC
_081073D4:
	ldr r2, _081073E8 @ =0x000005C4
	adds r0, r7, r2
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081073EE
	.align 2, 0
_081073E4: .4byte 0xFFFFFDFF
_081073E8: .4byte 0x000005C4
_081073EC:
	movs r0, #1
_081073EE:
	cmp r0, #0
	beq _08107444
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r4, _08107454 @ =0x0000046D
	adds r0, r7, r4
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _08107458 @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _0810745C @ =0x00000553
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
_0810742E:
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08107460 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _08107464 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
_08107444:
	add sp, #0xc0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08107454: .4byte 0x0000046D
_08107458: .4byte 0x0000046B
_0810745C: .4byte 0x00000553
_08107460: .4byte 0x0000046A
_08107464: .4byte 0x00000484

	thumb_func_start FUN_08107468
FUN_08107468: @ 0x08107468
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r7, r1, #0
	adds r3, r2, #0
	adds r5, r4, #0
	adds r5, #8
	mov r1, sp
	adds r2, r5, #0
	bl FUN_081077a4
	ldr r1, _0810749C @ =0x000004A4
	adds r0, r4, r1
	ldr r6, [r0]
	adds r0, r6, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081074A0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	b _081074C6
	.align 2, 0
_0810749C: .4byte 0x000004A4
_081074A0:
	adds r0, r6, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081074C0
	cmp r0, #2
	beq _081074BC
	adds r0, r4, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081074BC:
	movs r0, #1
	b _081074D0
_081074C0:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r4, r3
_081074C6:
	ldr r1, _081074E4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081074D0:
	cmp r0, #0
	bne _081074EC
	ldr r1, _081074E8 @ =0x000005C4
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	b _081075CA
	.align 2, 0
_081074E4: .4byte 0xFFFFFDFF
_081074E8: .4byte 0x000005C4
_081074EC:
	ldr r2, _08107558 @ =0x00000714
	adds r1, r7, r2
	movs r5, #0
	movs r7, #0
	movs r0, #0xa0
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r2, _0810755C @ =FUN_080e48d0
	movs r1, #0x10
	ldr r3, _08107560 @ =0x0000046D
	adds r0, r4, r3
	movs r6, #1
	strb r6, [r0]
	subs r3, #2
	adds r0, r4, r3
	strb r5, [r0]
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
	strh r7, [r0]
	subs r3, #0xaf
	adds r0, r4, r3
	ldr r2, [r0]
	movs r1, #0x1c
	ldrsh r0, [r2, r1]
	movs r3, #8
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r3, #0x20
	ldrsh r1, [r2, r3]
	movs r3, #0xc
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r1, r0, #0
	ldrb r0, [r4, #5]
	subs r0, r1, r0
	cmp r0, #0
	bge _0810754C
	rsbs r0, r0, #0
_0810754C:
	cmp r0, #0x1f
	ble _081075A8
	cmp r1, #0
	blt _08107564
	asrs r0, r1, #5
	b _0810756A
	.align 2, 0
_08107558: .4byte 0x00000714
_0810755C: .4byte FUN_080e48d0
_08107560: .4byte 0x0000046D
_08107564:
	rsbs r0, r1, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0810756A:
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	movs r2, #0xee
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	movs r1, #0x13
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
	ldr r1, _081075A0 @ =0x00000484
	adds r0, r4, r1
	str r2, [r0]
	ldr r2, _081075A4 @ =0x0000046C
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	b _081075CA
	.align 2, 0
_081075A0: .4byte 0x00000484
_081075A4: .4byte 0x0000046C
_081075A8:
	movs r1, #0x12
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r5, [r0]
	ldr r2, _081075D4 @ =0x00000469
	adds r0, r4, r2
	strb r5, [r0]
	adds r3, #2
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _081075D8 @ =0x00000484
	adds r0, r4, r1
	str r7, [r0]
	adds r2, #3
	adds r0, r4, r2
	strb r6, [r0]
_081075CA:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081075D4: .4byte 0x00000469
_081075D8: .4byte 0x00000484

	thumb_func_start FUN_081075dc
FUN_081075dc: @ 0x081075DC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r1, _0810766C @ =0x08251FE4
	ldr r2, _08107670 @ =0x000006C2
	adds r0, r5, #0
	bl FUN_080e6768
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r3, _08107674 @ =0x0000075C
	adds r1, r4, r3
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _0810768C
	ldrb r1, [r5, #5]
	movs r6, #0xfe
	lsls r6, r6, #1
	adds r0, r5, r6
	ldrb r0, [r0]
	adds r0, #0x80
	movs r4, #0
	strb r0, [r5, #5]
	adds r0, r5, #0
	bl FUN_08105db4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08107704
	ldr r2, _08107678 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r3, _0810767C @ =0x0000046D
	adds r0, r5, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _08107680 @ =0x0000046B
	adds r0, r5, r6
	strb r4, [r0]
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
	strh r4, [r0]
	movs r2, #0x12
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08107684 @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _08107688 @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	b _08107704
	.align 2, 0
_0810766C: .4byte 0x08251FE4
_08107670: .4byte 0x000006C2
_08107674: .4byte 0x0000075C
_08107678: .4byte FUN_080e48d0
_0810767C: .4byte 0x0000046D
_08107680: .4byte 0x0000046B
_08107684: .4byte 0x0000046A
_08107688: .4byte 0x00000484
_0810768C:
	ldr r1, _081076E4 @ =0x00000714
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _081076F8
	movs r2, #3
	movs r1, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r3, #0
	strb r2, [r0]
	ldr r6, _081076E8 @ =0x00000469
	adds r0, r5, r6
	strb r1, [r0]
	ldr r2, _081076EC @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r3, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	ldr r4, _081076F0 @ =FUN_0810dbb0
	movs r2, #0x3b
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081076F4 @ =0x0000046B
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r3, [r0]
	b _08107704
	.align 2, 0
_081076E4: .4byte 0x00000714
_081076E8: .4byte 0x00000469
_081076EC: .4byte 0x0000046A
_081076F0: .4byte FUN_0810dbb0
_081076F4: .4byte 0x0000046B
_081076F8:
	movs r2, #0x80
	lsls r2, r2, #0xb
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08107468
_08107704:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0810770c
FUN_0810770c: @ 0x0810770C
	push {r4, r5, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r2, #0
	movs r0, #0xe3
	lsls r0, r0, #3
	adds r3, r4, r0
	movs r5, #0xff
_08107720:
	adds r1, r3, r2
	ldrb r0, [r1]
	orrs r0, r5
	strb r0, [r1]
	adds r2, #1
	cmp r2, #2
	ble _08107720
	ldr r0, _0810773C @ =0x0000071B
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0810773C: .4byte 0x0000071B

	thumb_func_start FUN_08107740
FUN_08107740: @ 0x08107740
	push {lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r3, _08107770 @ =0x0000071B
	adds r2, r0, r3
	subs r3, #3
	adds r0, r0, r3
	ldrb r3, [r2]
	adds r0, r0, r3
	strb r1, [r0]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0810776A
	movs r0, #0
	strb r0, [r2]
_0810776A:
	pop {r0}
	bx r0
	.align 2, 0
_08107770: .4byte 0x0000071B

	thumb_func_start FUN_08107774
FUN_08107774: @ 0x08107774
	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	movs r2, #0
	movs r4, #0xe3
	lsls r4, r4, #3
	adds r3, r0, r4
_08107786:
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r1
	bne _08107796
	movs r0, #1
	b _0810779E
_08107796:
	adds r2, #1
	cmp r2, #2
	ble _08107786
	movs r0, #0
_0810779E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081077a4
FUN_081077a4: @ 0x081077A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	mov sl, r0
	str r1, [sp, #0x20]
	str r2, [sp, #0x24]
	str r3, [sp, #0x28]
	mov r0, sp
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08234de8
	movs r0, #0
	mov r8, r0
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp, #0x2c]
	movs r6, #0
	ldr r0, [sp, #4]
	ldrb r2, [r0]
	cmp r8, r2
	bge _08107858
	add r7, sp, #0xc
	add r5, sp, #0x18
	ldr r3, _081078C4 @ =0xFFFF0000
	mov sb, r3
_081077E0:
	bl FUN_08234f6c
	lsls r1, r6, #3
	adds r0, r0, r1
	str r0, [r7, #8]
	ldr r2, [sp, #0x24]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [r7, #8]
	ldrh r1, [r0]
	ldrh r0, [r5]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x18]
	mov r3, sb
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, [r7, #8]
	ldrh r1, [r0, #2]
	ldrh r0, [r5, #4]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r5, #4]
	movs r1, #0
	ldrsh r0, [r5, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r5, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r4, r1, r0
	ldr r0, [sp, #0x28]
	cmp r4, r0
	blt _0810784E
	cmp r8, r4
	bge _0810784E
	mov r0, sl
	adds r1, r6, #0
	bl FUN_08107774
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0810784E
	str r6, [sp, #0x2c]
	mov r8, r4
_0810784E:
	adds r6, #1
	ldr r0, [sp, #4]
	ldrb r1, [r0]
	cmp r6, r1
	blt _081077E0
_08107858:
	mov r2, r8
	cmp r2, #0
	bne _0810787C
	ldr r2, _081078C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081078CC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081078D0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #4]
	ldrb r1, [r1]
	bl Mod
	str r0, [sp, #0x2c]
_0810787C:
	mov r0, sl
	ldr r1, [sp, #0x2c]
	bl FUN_08107740
	mov r0, sp
	movs r1, #0
	add r2, sp, #0x2c
	ldrb r2, [r2]
	strb r2, [r0, #2]
	strb r1, [r0, #3]
	ldr r0, [sp, #4]
	bl FUN_08234f6c
	str r0, [sp, #8]
	mov r1, sp
	ldrb r1, [r1, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [sp, #8]
	ldrh r1, [r0]
	ldr r3, [sp, #0x20]
	strh r1, [r3]
	ldr r1, _081078D4 @ =0x00000472
	add r1, sl
	ldrh r1, [r1]
	strh r1, [r3, #2]
	ldrh r0, [r0, #2]
	strh r0, [r3, #4]
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081078C4: .4byte 0xFFFF0000
_081078C8: .4byte 0x030046B8
_081078CC: .4byte 0x000003FF
_081078D0: .4byte 0x0203B400
_081078D4: .4byte 0x00000472

	thumb_func_start FUN_081078d8
FUN_081078d8: @ 0x081078D8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	mov sl, r0
	str r1, [sp, #0x20]
	str r2, [sp, #0x24]
	str r3, [sp, #0x28]
	ldr r1, [sp, #0x50]
	mov r0, sp
	movs r2, #0
	movs r3, #0
	bl FUN_08234de8
	movs r0, #0
	mov r8, r0
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp, #0x2c]
	movs r6, #0
	ldr r0, [sp, #4]
	ldrb r2, [r0]
	cmp r8, r2
	bge _0810798C
	add r7, sp, #0xc
	add r5, sp, #0x18
	ldr r3, _081079F8 @ =0xFFFF0000
	mov sb, r3
_08107914:
	bl FUN_08234f6c
	lsls r1, r6, #3
	adds r0, r0, r1
	str r0, [r7, #8]
	ldr r2, [sp, #0x24]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [r7, #8]
	ldrh r1, [r0]
	ldrh r0, [r5]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x18]
	mov r3, sb
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, [r7, #8]
	ldrh r1, [r0, #2]
	ldrh r0, [r5, #4]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r5, #4]
	movs r1, #0
	ldrsh r0, [r5, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r5, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r4, r1, r0
	ldr r0, [sp, #0x28]
	cmp r4, r0
	blt _08107982
	cmp r8, r4
	bge _08107982
	mov r0, sl
	adds r1, r6, #0
	bl FUN_08107774
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08107982
	str r6, [sp, #0x2c]
	mov r8, r4
_08107982:
	adds r6, #1
	ldr r0, [sp, #4]
	ldrb r1, [r0]
	cmp r6, r1
	blt _08107914
_0810798C:
	mov r2, r8
	cmp r2, #0
	bne _081079B0
	ldr r2, _081079FC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08107A00 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08107A04 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #4]
	ldrb r1, [r1]
	bl Mod
	str r0, [sp, #0x2c]
_081079B0:
	mov r0, sl
	ldr r1, [sp, #0x2c]
	bl FUN_08107740
	mov r0, sp
	movs r1, #0
	add r2, sp, #0x2c
	ldrb r2, [r2]
	strb r2, [r0, #2]
	strb r1, [r0, #3]
	ldr r0, [sp, #4]
	bl FUN_08234f6c
	str r0, [sp, #8]
	mov r1, sp
	ldrb r1, [r1, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [sp, #8]
	ldrh r1, [r0]
	ldr r3, [sp, #0x20]
	strh r1, [r3]
	ldr r1, _08107A08 @ =0x00000472
	add r1, sl
	ldrh r1, [r1]
	strh r1, [r3, #2]
	ldrh r0, [r0, #2]
	strh r0, [r3, #4]
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081079F8: .4byte 0xFFFF0000
_081079FC: .4byte 0x030046B8
_08107A00: .4byte 0x000003FF
_08107A04: .4byte 0x0203B400
_08107A08: .4byte 0x00000472

	thumb_func_start FUN_08107a0c
FUN_08107a0c: @ 0x08107A0C
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x9c
	ldr r2, _08107A60 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08107A64 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08107A68 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldrb r0, [r4, #2]
	cmp r1, r0
	bne _08107A46
	adds r0, r1, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_08107A46:
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
_08107A60: .4byte 0x030046B8
_08107A64: .4byte 0x000003FF
_08107A68: .4byte 0x0203B400

	thumb_func_start FUN_08107a6c
FUN_08107a6c: @ 0x08107A6C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x34
	adds r6, r0, #0
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r0, [r0]
	adds r0, #0xf7
	mov r8, r0
	ldr r2, _08107AB8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	subs r1, #0x81
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08107ABC @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0xa
	ldr r1, _08107AC0 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107AC4
	asrs r1, r0, #0xc
	b _08107ACA
	.align 2, 0
_08107AB8: .4byte 0x030046B8
_08107ABC: .4byte 0x0203B400
_08107AC0: .4byte 0x085B0A08
_08107AC4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08107ACA:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _08107AE4 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107AE8
	asrs r0, r0, #0xc
	b _08107AEE
	.align 2, 0
_08107AE4: .4byte 0x085B0A08
_08107AE8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08107AEE:
	movs r1, #0
	strh r0, [r4, #4]
	add r2, sp, #0x2c
	movs r0, #0x64
	strh r0, [r2, #2]
	adds r4, r6, #0
	adds r4, #8
	ldr r2, _08107B5C @ =0x0000D45E
	ldr r3, _08107B60 @ =0x00001DC3
	movs r0, #5
	str r0, [sp]
	movs r0, #0x1a
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, r8
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r4, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _08107B64 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08107B68 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08107B6C @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r5, sp, #0x2c
	movs r6, #0xa
	ldr r1, _08107B70 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r7, r4, #0
	cmp r0, #0
	blt _08107B74
	asrs r1, r0, #0xc
	b _08107B7A
	.align 2, 0
_08107B5C: .4byte 0x0000D45E
_08107B60: .4byte 0x00001DC3
_08107B64: .4byte 0x030046B8
_08107B68: .4byte 0x000003FF
_08107B6C: .4byte 0x0203B400
_08107B70: .4byte 0x085B0A08
_08107B74:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08107B7A:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _08107B94 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08107B98
	asrs r0, r0, #0xc
	b _08107B9E
	.align 2, 0
_08107B94: .4byte 0x085B0A08
_08107B98:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08107B9E:
	movs r1, #0
	strh r0, [r5, #4]
	add r0, sp, #0x2c
	movs r4, #0x64
	strh r4, [r0, #2]
	ldr r2, _08107C04 @ =0x0000D45E
	ldr r3, _08107C08 @ =0x00001DC3
	movs r0, #6
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, r8
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _08107C0C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08107C10 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08107C14 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0xa
	ldr r1, _08107C18 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107C1C
	asrs r1, r0, #0xc
	b _08107C22
	.align 2, 0
_08107C04: .4byte 0x0000D45E
_08107C08: .4byte 0x00001DC3
_08107C0C: .4byte 0x030046B8
_08107C10: .4byte 0x000003FF
_08107C14: .4byte 0x0203B400
_08107C18: .4byte 0x085B0A08
_08107C1C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08107C22:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _08107C3C @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107C40
	asrs r0, r0, #0xc
	b _08107C46
	.align 2, 0
_08107C3C: .4byte 0x085B0A08
_08107C40:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08107C46:
	movs r1, #0
	strh r0, [r4, #4]
	add r2, sp, #0x2c
	movs r0, #0x3c
	strh r0, [r2, #2]
	ldr r2, _08107CB0 @ =0x0000D45E
	ldr r3, _08107CB4 @ =0x00001DC3
	movs r0, #0xa
	str r0, [sp]
	movs r0, #0x64
	str r0, [sp, #4]
	ldr r0, _08107CB8 @ =0x00000202
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, r8
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _08107CBC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08107CC0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08107CC4 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0xa
	ldr r1, _08107CC8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107CCC
	asrs r1, r0, #0xc
	b _08107CD2
	.align 2, 0
_08107CB0: .4byte 0x0000D45E
_08107CB4: .4byte 0x00001DC3
_08107CB8: .4byte 0x00000202
_08107CBC: .4byte 0x030046B8
_08107CC0: .4byte 0x000003FF
_08107CC4: .4byte 0x0203B400
_08107CC8: .4byte 0x085B0A08
_08107CCC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08107CD2:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _08107CEC @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107CF0
	asrs r0, r0, #0xc
	b _08107CF6
	.align 2, 0
_08107CEC: .4byte 0x085B0A08
_08107CF0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08107CF6:
	movs r1, #0
	strh r0, [r4, #4]
	add r2, sp, #0x2c
	movs r0, #0x46
	strh r0, [r2, #2]
	ldr r2, _08107D60 @ =0x0000D45E
	ldr r3, _08107D64 @ =0x00001DC3
	movs r0, #0xa
	str r0, [sp]
	movs r0, #0x64
	str r0, [sp, #4]
	ldr r0, _08107D68 @ =0x00000202
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, r8
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _08107D6C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08107D70 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08107D74 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0xa
	ldr r1, _08107D78 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107D7C
	asrs r1, r0, #0xc
	b _08107D82
	.align 2, 0
_08107D60: .4byte 0x0000D45E
_08107D64: .4byte 0x00001DC3
_08107D68: .4byte 0x00000202
_08107D6C: .4byte 0x030046B8
_08107D70: .4byte 0x000003FF
_08107D74: .4byte 0x0203B400
_08107D78: .4byte 0x085B0A08
_08107D7C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08107D82:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _08107D9C @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107DA0
	asrs r0, r0, #0xc
	b _08107DA6
	.align 2, 0
_08107D9C: .4byte 0x085B0A08
_08107DA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08107DA6:
	movs r1, #0
	strh r0, [r4, #4]
	add r2, sp, #0x2c
	movs r0, #0x32
	strh r0, [r2, #2]
	ldr r2, _08107E10 @ =0x0000D45E
	ldr r3, _08107E14 @ =0x00001DC3
	movs r0, #7
	str r0, [sp]
	movs r0, #0x64
	str r0, [sp, #4]
	ldr r0, _08107E18 @ =0x00000202
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, r8
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _08107E1C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08107E20 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08107E24 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0xa
	ldr r1, _08107E28 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107E2C
	asrs r1, r0, #0xc
	b _08107E32
	.align 2, 0
_08107E10: .4byte 0x0000D45E
_08107E14: .4byte 0x00001DC3
_08107E18: .4byte 0x00000202
_08107E1C: .4byte 0x030046B8
_08107E20: .4byte 0x000003FF
_08107E24: .4byte 0x0203B400
_08107E28: .4byte 0x085B0A08
_08107E2C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08107E32:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _08107E4C @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107E50
	asrs r0, r0, #0xc
	b _08107E56
	.align 2, 0
_08107E4C: .4byte 0x085B0A08
_08107E50:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08107E56:
	movs r1, #0
	strh r0, [r4, #4]
	add r2, sp, #0x2c
	movs r0, #0x3c
	strh r0, [r2, #2]
	ldr r2, _08107EC0 @ =0x0000D45E
	ldr r3, _08107EC4 @ =0x00001DC3
	movs r0, #7
	str r0, [sp]
	movs r0, #0x64
	str r0, [sp, #4]
	ldr r0, _08107EC8 @ =0x00000202
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, r8
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _08107ECC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08107ED0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08107ED4 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0xa
	ldr r1, _08107ED8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107EDC
	asrs r1, r0, #0xc
	b _08107EE2
	.align 2, 0
_08107EC0: .4byte 0x0000D45E
_08107EC4: .4byte 0x00001DC3
_08107EC8: .4byte 0x00000202
_08107ECC: .4byte 0x030046B8
_08107ED0: .4byte 0x000003FF
_08107ED4: .4byte 0x0203B400
_08107ED8: .4byte 0x085B0A08
_08107EDC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08107EE2:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _08107EFC @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107F00
	asrs r0, r0, #0xc
	b _08107F06
	.align 2, 0
_08107EFC: .4byte 0x085B0A08
_08107F00:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08107F06:
	movs r1, #0
	strh r0, [r4, #4]
	add r2, sp, #0x2c
	movs r0, #0x28
	strh r0, [r2, #2]
	ldr r2, _08107F70 @ =0x0000D45E
	ldr r3, _08107F74 @ =0x00001DC3
	movs r0, #8
	str r0, [sp]
	movs r0, #0x64
	str r0, [sp, #4]
	ldr r0, _08107F78 @ =0x00000202
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, r8
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _08107F7C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08107F80 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08107F84 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0xa
	ldr r1, _08107F88 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107F8C
	asrs r1, r0, #0xc
	b _08107F92
	.align 2, 0
_08107F70: .4byte 0x0000D45E
_08107F74: .4byte 0x00001DC3
_08107F78: .4byte 0x00000202
_08107F7C: .4byte 0x030046B8
_08107F80: .4byte 0x000003FF
_08107F84: .4byte 0x0203B400
_08107F88: .4byte 0x085B0A08
_08107F8C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08107F92:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _08107FAC @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08107FB0
	asrs r0, r0, #0xc
	b _08107FB6
	.align 2, 0
_08107FAC: .4byte 0x085B0A08
_08107FB0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08107FB6:
	movs r1, #0
	strh r0, [r4, #4]
	add r2, sp, #0x2c
	movs r0, #0x5a
	strh r0, [r2, #2]
	ldr r2, _08108020 @ =0x0000D45E
	ldr r3, _08108024 @ =0x00001DC3
	movs r0, #9
	str r0, [sp]
	movs r0, #0x64
	str r0, [sp, #4]
	ldr r0, _08108028 @ =0x00000202
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, r8
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _0810802C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08108030 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08108034 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0xa
	ldr r1, _08108038 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0810803C
	asrs r1, r0, #0xc
	b _08108042
	.align 2, 0
_08108020: .4byte 0x0000D45E
_08108024: .4byte 0x00001DC3
_08108028: .4byte 0x00000202
_0810802C: .4byte 0x030046B8
_08108030: .4byte 0x000003FF
_08108034: .4byte 0x0203B400
_08108038: .4byte 0x085B0A08
_0810803C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08108042:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _0810805C @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08108060
	asrs r0, r0, #0xc
	b _08108066
	.align 2, 0
_0810805C: .4byte 0x085B0A08
_08108060:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08108066:
	movs r1, #0
	strh r0, [r4, #4]
	add r2, sp, #0x2c
	movs r0, #0x32
	strh r0, [r2, #2]
	ldr r2, _081080A8 @ =0x0000D45E
	ldr r3, _081080AC @ =0x00001DC3
	movs r0, #0xb
	str r0, [sp]
	movs r0, #0x64
	str r0, [sp, #4]
	ldr r0, _081080B0 @ =0x00000202
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, r8
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	add sp, #0x34
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081080A8: .4byte 0x0000D45E
_081080AC: .4byte 0x00001DC3
_081080B0: .4byte 0x00000202

	thumb_func_start FUN_081080b4
FUN_081080b4: @ 0x081080B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r4, r0, #0
	ldrb r0, [r4, #5]
	adds r0, #0x20
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #6
	lsls r7, r0, #6
	adds r7, #0x40
	ands r7, r3
	ldr r2, _08108278 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0810827C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08108280 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ands r0, r3
	movs r1, #1
	rsbs r1, r1, #0
	mov sb, r1
	cmp r0, #0x7f
	bgt _081080F6
	movs r0, #1
	mov sb, r0
_081080F6:
	movs r1, #8
	adds r1, r1, r4
	mov sl, r1
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	movs r0, #0x8a
	lsls r0, r0, #2
	adds r0, r0, r4
	mov r8, r0
	ldrh r0, [r0]
	str r0, [sp, #8]
	adds r1, #0xa0
	adds r6, r4, r1
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	movs r0, #0x91
	lsls r0, r0, #2
	adds r5, r4, r0
	ldr r0, [r5]
	str r0, [sp, #0x10]
	adds r1, #8
	adds r4, r4, r1
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0x80
	lsls r2, r2, #5
	movs r3, #2
	bl FUN_081f9294
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0x80
	lsls r2, r2, #5
	movs r3, #3
	bl FUN_081f9294
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0x80
	lsls r2, r2, #5
	movs r3, #4
	bl FUN_081f9294
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0x80
	lsls r2, r2, #5
	movs r3, #5
	bl FUN_081f9294
	movs r3, #2
	rsbs r3, r3, #0
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0x80
	lsls r2, r2, #5
	bl FUN_081f9294
	movs r3, #3
	rsbs r3, r3, #0
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0x80
	lsls r2, r2, #5
	bl FUN_081f9294
	movs r3, #4
	rsbs r3, r3, #0
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0x80
	lsls r2, r2, #5
	bl FUN_081f9294
	movs r3, #5
	rsbs r3, r3, #0
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0x80
	lsls r2, r2, #5
	bl FUN_081f9294
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08108278: .4byte 0x030046B8
_0810827C: .4byte 0x000003FF
_08108280: .4byte 0x0203B400

	thumb_func_start FUN_08108284
FUN_08108284: @ 0x08108284
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r4, r0, #0
	ldrb r0, [r4, #5]
	adds r0, #0x20
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #6
	lsls r7, r0, #6
	adds r7, #0x40
	ands r7, r3
	ldr r2, _08108448 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0810844C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08108450 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ands r0, r3
	movs r1, #1
	rsbs r1, r1, #0
	mov sb, r1
	cmp r0, #0x7f
	bgt _081082C6
	movs r0, #1
	mov sb, r0
_081082C6:
	movs r1, #8
	adds r1, r1, r4
	mov sl, r1
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	movs r0, #0x8a
	lsls r0, r0, #2
	adds r0, r0, r4
	mov r8, r0
	ldrh r0, [r0]
	str r0, [sp, #8]
	adds r1, #0xa0
	adds r6, r4, r1
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	movs r0, #0x91
	lsls r0, r0, #2
	adds r5, r4, r0
	ldr r0, [r5]
	str r0, [sp, #0x10]
	adds r1, #8
	adds r4, r4, r1
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0xa0
	lsls r2, r2, #4
	movs r3, #2
	bl FUN_081f9294
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0x80
	lsls r2, r2, #2
	movs r3, #3
	bl FUN_081f9294
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0xc0
	lsls r2, r2, #3
	movs r3, #4
	bl FUN_081f9294
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0xe0
	lsls r2, r2, #4
	movs r3, #5
	bl FUN_081f9294
	movs r3, #2
	rsbs r3, r3, #0
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0xa0
	lsls r2, r2, #4
	bl FUN_081f9294
	movs r3, #3
	rsbs r3, r3, #0
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0x80
	lsls r2, r2, #2
	bl FUN_081f9294
	movs r3, #4
	rsbs r3, r3, #0
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0xc0
	lsls r2, r2, #3
	bl FUN_081f9294
	movs r3, #5
	rsbs r3, r3, #0
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldrh r0, [r6]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0xe0
	lsls r2, r2, #4
	bl FUN_081f9294
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08108448: .4byte 0x030046B8
_0810844C: .4byte 0x000003FF
_08108450: .4byte 0x0203B400

	thumb_func_start FUN_08108454
FUN_08108454: @ 0x08108454
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r4, r0, #0
	ldrb r0, [r4, #5]
	adds r0, #0x20
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #6
	lsls r7, r0, #6
	adds r7, #0x40
	ands r7, r3
	ldr r2, _08108628 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0810862C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08108630 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ands r0, r3
	movs r1, #1
	rsbs r1, r1, #0
	mov sb, r1
	cmp r0, #0x7f
	bgt _08108496
	movs r0, #1
	mov sb, r0
_08108496:
	movs r1, #8
	adds r1, r1, r4
	mov sl, r1
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	movs r0, #0x8a
	lsls r0, r0, #2
	adds r0, r0, r4
	mov r8, r0
	ldrh r0, [r0]
	str r0, [sp, #8]
	adds r1, #0xa0
	adds r1, r4, r1
	str r1, [sp, #0x18]
	ldrh r0, [r1]
	str r0, [sp, #0xc]
	movs r0, #0x91
	lsls r0, r0, #2
	adds r5, r4, r0
	ldr r0, [r5]
	str r0, [sp, #0x10]
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r4, r4, r1
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0xc0
	lsls r2, r2, #4
	movs r3, #2
	bl FUN_081f9294
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldr r1, [sp, #0x18]
	ldrh r0, [r1]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0xc0
	lsls r2, r2, #4
	movs r3, #3
	bl FUN_081f9294
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldr r1, [sp, #0x18]
	ldrh r0, [r1]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0xc0
	lsls r2, r2, #4
	movs r3, #4
	bl FUN_081f9294
	mov r0, sb
	str r0, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldr r1, [sp, #0x18]
	ldrh r0, [r1]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0xc0
	lsls r2, r2, #4
	movs r3, #5
	bl FUN_081f9294
	movs r3, #2
	rsbs r3, r3, #0
	mov r0, sb
	rsbs r6, r0, #0
	str r6, [sp]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldr r1, [sp, #0x18]
	ldrh r0, [r1]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0x80
	lsls r2, r2, #3
	bl FUN_081f9294
	movs r3, #3
	rsbs r3, r3, #0
	str r6, [sp]
	movs r0, #0xc8
	lsls r0, r0, #1
	str r0, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldr r1, [sp, #0x18]
	ldrh r0, [r1]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0x80
	lsls r2, r2, #3
	bl FUN_081f9294
	movs r3, #4
	rsbs r3, r3, #0
	str r6, [sp]
	movs r0, #0xc8
	lsls r0, r0, #1
	str r0, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldr r1, [sp, #0x18]
	ldrh r0, [r1]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0x80
	lsls r2, r2, #3
	bl FUN_081f9294
	movs r3, #5
	rsbs r3, r3, #0
	str r6, [sp]
	movs r0, #0xc8
	lsls r0, r0, #1
	str r0, [sp, #4]
	mov r1, r8
	ldrh r0, [r1]
	str r0, [sp, #8]
	ldr r1, [sp, #0x18]
	ldrh r0, [r1]
	str r0, [sp, #0xc]
	ldr r0, [r5]
	str r0, [sp, #0x10]
	ldrh r0, [r4]
	str r0, [sp, #0x14]
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0x80
	lsls r2, r2, #3
	bl FUN_081f9294
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08108628: .4byte 0x030046B8
_0810862C: .4byte 0x000003FF
_08108630: .4byte 0x0203B400

	thumb_func_start FUN_08108634
FUN_08108634: @ 0x08108634
	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r0, #0x78
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	beq _0810868C
	bl VM_GetPC
	cmp r0, #0
	beq _0810865A
	bl Script_GetValue
	adds r1, r0, #0
	b _0810865C
_0810865A:
	movs r1, #0
_0810865C:
	movs r2, #0xdf
	lsls r2, r2, #3
	adds r0, r4, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08108674
	bl Script_GetValue
	adds r2, r0, #0
	b _08108676
_08108674:
	movs r2, #0
_08108676:
	ldr r1, _08108684 @ =0x000006FA
	adds r0, r4, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _08108688 @ =0x000006FB
	b _0810869E
	.align 2, 0
_08108684: .4byte 0x000006FA
_08108688: .4byte 0x000006FB
_0810868C:
	movs r1, #0xdf
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strh r2, [r0]
	ldr r2, _081086A8 @ =0x000006FA
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
_0810869E:
	adds r0, r4, r2
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081086A8: .4byte 0x000006FA

	thumb_func_start FUN_081086ac
FUN_081086ac: @ 0x081086AC
	push {r4, r5, r6, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	movs r2, #0xdf
	lsls r2, r2, #3
	adds r5, r1, r2
	ldrh r0, [r5]
	cmp r0, #0
	beq _081086EC
	ldr r0, _081086F4 @ =0x000006FB
	adds r4, r1, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r2, #2
	adds r6, r1, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r6]
	cmp r0, r1
	blo _081086EC
	ldrh r0, [r5]
	movs r1, #0
	bl Script_ExecById
	movs r1, #0
	movs r0, #0
	strh r0, [r5]
	strb r1, [r6]
	strb r1, [r4]
_081086EC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081086F4: .4byte 0x000006FB

	thumb_func_start FUN_081086f8
FUN_081086f8: @ 0x081086F8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08108710 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08108714
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08108716
	.align 2, 0
_08108710: .4byte 0x0000046D
_08108714:
	movs r0, #0
_08108716:
	cmp r0, #0
	beq _08108746
	ldrb r0, [r4, #5]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r4, #5]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r1, r1, r2
	ldr r0, _0810877C @ =0xFFFFF8FF
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
_08108746:
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08108774
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	ldr r2, _08108780 @ =0x00000716
	adds r0, r0, r2
	movs r1, #0
	strh r1, [r0]
	adds r0, r4, #0
	bl FUN_08104220
	ldr r0, _08108784 @ =0x00000482
	adds r1, r4, r0
	movs r0, #1
	strh r0, [r1]
_08108774:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0810877C: .4byte 0xFFFFF8FF
_08108780: .4byte 0x00000716
_08108784: .4byte 0x00000482

	thumb_func_start FUN_08108788
FUN_08108788: @ 0x08108788
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081087A0 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081087A4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081087A6
	.align 2, 0
_081087A0: .4byte 0x0000046D
_081087A4:
	movs r0, #0
_081087A6:
	cmp r0, #0
	beq _081087D6
	ldrb r0, [r4, #5]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r4, #5]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r1, r1, r2
	ldr r0, _08108818 @ =0xFFFFF8FF
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
_081087D6:
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08108810
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	ldr r0, _0810881C @ =0x00000716
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _08108820 @ =0x000006FC
	adds r2, r2, r1
	subs r0, #0xe
	ldrh r1, [r2, #0x26]
	ands r0, r1
	strh r0, [r2, #0x26]
	adds r0, r4, #0
	bl FUN_08103cb0
	ldr r2, _08108824 @ =0x00000482
	adds r1, r4, r2
	movs r0, #1
	strh r0, [r1]
_08108810:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08108818: .4byte 0xFFFFF8FF
_0810881C: .4byte 0x00000716
_08108820: .4byte 0x000006FC
_08108824: .4byte 0x00000482

	thumb_func_start FUN_08108828
FUN_08108828: @ 0x08108828
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081057b4
	adds r0, r4, #0
	bl FUN_08105ab8
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #2
	bne _0810886A
	ldr r2, _08108890 @ =0x00000546
	adds r0, r4, r2
	ldrh r1, [r0]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _0810886A
	ldr r0, _08108894 @ =0x0000070F
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08108864
	subs r0, #1
	strb r0, [r1]
_08108864:
	adds r0, r4, #0
	bl FUN_08106544
_0810886A:
	ldr r2, _08108898 @ =0x00000714
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08108878
	subs r0, #1
	strh r0, [r1]
_08108878:
	ldr r0, _0810889C @ =0x00000716
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08108886
	subs r0, #1
	strh r0, [r1]
_08108886:
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08108890: .4byte 0x00000546
_08108894: .4byte 0x0000070F
_08108898: .4byte 0x00000714
_0810889C: .4byte 0x00000716

	thumb_func_start FUN_081088a0
FUN_081088a0: @ 0x081088A0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081057b4
	adds r0, r4, #0
	bl FUN_08105ab8
	ldr r0, _081088C4 @ =0x0000072C
	adds r4, r4, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _081088BC
	subs r0, #1
	strh r0, [r4]
_081088BC:
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081088C4: .4byte 0x0000072C

	thumb_func_start FUN_081088c8
FUN_081088c8: @ 0x081088C8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08103678
	adds r0, r4, #0
	bl FUN_0810340c
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081088FC
	subs r1, #0x34
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r1, r1, r2
	ldr r0, _08108904 @ =0xFFFFDFFF
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
_081088FC:
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08108904: .4byte 0xFFFFDFFF

	thumb_func_start FUN_08108908
FUN_08108908: @ 0x08108908
	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	adds r4, r2, #0
	adds r7, r4, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08108998
	movs r2, #0x10
	movs r0, #0xe6
	lsls r0, r0, #3
	adds r1, r5, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _0810893A
	movs r0, #1
	b _0810893C
_0810893A:
	movs r0, #0
_0810893C:
	cmp r0, #0
	beq _0810896A
	movs r1, #0x80
	lsls r1, r1, #4
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08108950
	movs r0, #1
	b _08108952
_08108950:
	movs r0, #0
_08108952:
	cmp r0, #0
	beq _08108998
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _08108998
_0810896A:
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08108998
	ldrh r1, [r6, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08108998
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r6, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, _081089A0 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_08108998:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081089A0: .4byte 0xFEFFFFFF

	thumb_func_start FUN_081089a4
FUN_081089a4: @ 0x081089A4
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	adds r4, r2, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08108A10
	movs r2, #0x10
	movs r0, #0xe6
	lsls r0, r0, #3
	adds r1, r5, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _081089D4
	movs r0, #1
	b _081089D6
_081089D4:
	movs r0, #0
_081089D6:
	cmp r0, #0
	bne _08108A10
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08108A08
	ldrh r1, [r6, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08108A08
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r6, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, _08108A18 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_08108A08:
	movs r0, #0x20
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_08108A10:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08108A18: .4byte 0xFEFFFFFF

	thumb_func_start FUN_08108a1c
FUN_08108a1c: @ 0x08108A1C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08108A44
	b _08109104
_08108A44:
	movs r1, #0x10
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08108A58
	movs r0, #1
	b _08108A5A
_08108A58:
	movs r0, #0
_08108A5A:
	cmp r0, #0
	beq _08108A60
	b _08109104
_08108A60:
	ldr r3, _08108AA0 @ =0x00000724
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08108A6C
	b _08109104
_08108A6C:
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08108A7C
	b _08109104
_08108A7C:
	movs r4, #0x8e
	lsls r4, r4, #1
	adds r0, r6, r4
	ldrh r0, [r0]
	cmp r0, #0
	beq _08108AA8
	ldr r5, _08108AA4 @ =0x0000048C
	adds r0, r6, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _08108A94
	b _08109104
_08108A94:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _08109104
	.align 2, 0
_08108AA0: .4byte 0x00000724
_08108AA4: .4byte 0x0000048C
_08108AA8:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _08108AB8
	b _08109104
_08108AB8:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _08108AC8
	b _08108DD4
_08108AC8:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _08108ADA
	b _08109104
_08108ADA:
	ldr r2, _08108B6C @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _08108AEE
	b _08109104
_08108AEE:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08108AFC
	b _08109104
_08108AFC:
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
	bne _08108B14
	b _08108C5C
_08108B14:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _08108B7C
	ands r3, r1
	cmp r3, #0
	beq _08108B7C
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08108B3A
	rsbs r1, r1, #0
_08108B3A:
	cmp r1, #0x20
	bgt _08108B7C
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _08108B70 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _08108B74 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _08108B78 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _08109104
	.align 2, 0
_08108B6C: .4byte 0x0000A007
_08108B70: .4byte 0x000004BE
_08108B74: .4byte 0x0000048C
_08108B78: .4byte 0x0000044E
_08108B7C:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _08108BA4 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08108BAC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08108BA8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08108C1A
	.align 2, 0
_08108BA4: .4byte 0x0000048A
_08108BA8: .4byte 0x03002BE0
_08108BAC:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08108BC8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08108BC4 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08108C1A
	.align 2, 0
_08108BC4: .4byte 0x03002BE0
_08108BC8:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08108BE4
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08108BE0 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08108C1A
	.align 2, 0
_08108BE0: .4byte 0x03002BE0
_08108BE4:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08108C00
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08108BFC @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08108C1A
	.align 2, 0
_08108BFC: .4byte 0x03002BE0
_08108C00:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08108C12
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08108C1A
_08108C12:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08108C1C
_08108C1A:
	movs r3, #1
_08108C1C:
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
	ldr r5, _08108C50 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _08108C3E
	b _08108D94
_08108C3E:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08108C54
	movs r0, #1
	b _08108C56
	.align 2, 0
_08108C50: .4byte 0x0000049C
_08108C54:
	movs r0, #0
_08108C56:
	cmp r0, #0
	bne _08108D3A
	b _08108D50
_08108C5C:
	strh r2, [r7, #0x3e]
	ldr r1, _08108C84 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _08108C8C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08108C88 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08108CFA
	.align 2, 0
_08108C84: .4byte 0x0000048A
_08108C88: .4byte 0x03002BE0
_08108C8C:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08108CA8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08108CA4 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08108CFA
	.align 2, 0
_08108CA4: .4byte 0x03002BE0
_08108CA8:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _08108CC4
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08108CC0 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08108CFA
	.align 2, 0
_08108CC0: .4byte 0x03002BE0
_08108CC4:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08108CE0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08108CDC @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08108CFA
	.align 2, 0
_08108CDC: .4byte 0x03002BE0
_08108CE0:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08108CF2
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08108CFA
_08108CF2:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08108CFC
_08108CFA:
	movs r3, #1
_08108CFC:
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
	ldr r5, _08108D30 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _08108D94
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08108D34
	movs r0, #1
	b _08108D36
	.align 2, 0
_08108D30: .4byte 0x0000049C
_08108D34:
	movs r0, #0
_08108D36:
	cmp r0, #0
	beq _08108D50
_08108D3A:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08108D4C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08108D5C
	.align 2, 0
_08108D4C: .4byte 0x03002BE0
_08108D50:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08108D94
_08108D5C:
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
_08108D94:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08108DC0
	ldr r5, _08108DCC @ =0x0000024E
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
	bls _08108DC0
	strh r1, [r2]
_08108DC0:
	ldr r5, _08108DD0 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _08109104
	.align 2, 0
_08108DCC: .4byte 0x0000024E
_08108DD0: .4byte 0x0000048C
_08108DD4:
	ldr r0, _08108DE8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08108DEC
	movs r0, #1
	b _08108DEE
	.align 2, 0
_08108DE8: .4byte 0x030047A4
_08108DEC:
	movs r0, #0
_08108DEE:
	cmp r0, #0
	beq _08108DFC
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236640
	b _08108E04
_08108DFC:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236524
_08108E04:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _08108E3C @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08108E40 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _08108E32
	cmp r2, #0x17
	bne _08108E44
_08108E32:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _08108E66
	.align 2, 0
_08108E3C: .4byte 0x0000048C
_08108E40: .4byte 0x000001DF
_08108E44:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _08108E32
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _08108E94 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08108E66
	movs r1, #0
_08108E66:
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
	beq _08108EA2
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _08108E98
	asrs r0, r0, #1
	b _08108E9E
	.align 2, 0
_08108E94: .4byte 0x00000187
_08108E98:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08108E9E:
	mov r2, sb
	strh r0, [r2]
_08108EA2:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08108EC0
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _08108EBC @ =0x000001DD
	adds r1, r6, r4
	b _08108F34
	.align 2, 0
_08108EBC: .4byte 0x000001DD
_08108EC0:
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
	bne _08108F20
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _08108F20
	ldr r2, _08108F10 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08108F14 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08108F18 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _08108F1C @ =0x000001DD
	adds r1, r6, r4
	b _08108F34
	.align 2, 0
_08108F10: .4byte 0x030046B8
_08108F14: .4byte 0x000003FF
_08108F18: .4byte 0x0203B400
_08108F1C: .4byte 0x000001DD
_08108F20:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	ldr r3, _08108F54 @ =0x000001DD
	adds r1, r6, r3
_08108F34:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08108F5C
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08108F58 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08108FCA
	.align 2, 0
_08108F54: .4byte 0x000001DD
_08108F58: .4byte 0x03002BE0
_08108F5C:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08108F78
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08108F74 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08108FCA
	.align 2, 0
_08108F74: .4byte 0x03002BE0
_08108F78:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08108F94
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08108F90 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08108FCA
	.align 2, 0
_08108F90: .4byte 0x03002BE0
_08108F94:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08108FB0
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08108FAC @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08108FCA
	.align 2, 0
_08108FAC: .4byte 0x03002BE0
_08108FB0:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08108FC2
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _08108FCA
_08108FC2:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08108FCC
_08108FCA:
	movs r3, #1
_08108FCC:
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
	ldr r5, _08109000 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _08109068
	movs r1, #2
	ldr r2, _08109004 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08109008
	movs r0, #1
	b _0810900A
	.align 2, 0
_08109000: .4byte 0x0000049C
_08109004: .4byte 0x00000474
_08109008:
	movs r0, #0
_0810900A:
	cmp r0, #0
	beq _08109024
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08109020 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08109030
	.align 2, 0
_08109020: .4byte 0x03002BE0
_08109024:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08109068
_08109030:
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
_08109068:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0810909C
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0810909C
	ldr r0, _081090B4 @ =0x0000024E
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
	bls _0810909C
	strh r1, [r2]
_0810909C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _081090B8 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _081090BC @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081090C0
	movs r0, #1
	b _081090C2
	.align 2, 0
_081090B4: .4byte 0x0000024E
_081090B8: .4byte 0x030046A0
_081090BC: .4byte 0x00000934
_081090C0:
	movs r0, #0
_081090C2:
	ldr r1, _08109114 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _081090DA
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_081090DA:
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
_08109104:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08109114: .4byte 0x0000048A

	thumb_func_start FUN_08109118
FUN_08109118: @ 0x08109118
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
	bne _081091B8
	movs r1, #4
	ldrh r0, [r5, #6]
	ands r0, r1
	cmp r0, #0
	bne _081091B8
	ldr r2, _08109168 @ =0x000001DF
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #8
	beq _081091B8
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _081091B8
	movs r1, #0x10
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0810916C
	movs r0, #1
	b _0810916E
	.align 2, 0
_08109168: .4byte 0x000001DF
_0810916C:
	movs r0, #0
_0810916E:
	cmp r0, #0
	bne _081091B8
	ldr r1, _081091C0 @ =0x0000A13F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081091B8
	movs r1, #0x10
	ldr r0, [r7, #0x34]
	ands r0, r1
	cmp r0, #0
	bne _081091B8
	adds r0, r4, #0
	bl FUN_08103354
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081091B8
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_081032a0
	ldr r0, _081091C4 @ =0x00000724
	adds r1, r6, r0
	movs r0, #0x14
	strb r0, [r1]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #0x80
	ldr r2, _081091C8 @ =0x000001DD
	adds r1, r4, r2
	strb r0, [r1]
_081091B8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081091C0: .4byte 0x0000A13F
_081091C4: .4byte 0x00000724
_081091C8: .4byte 0x000001DD

	thumb_func_start FUN_081091cc
FUN_081091cc: @ 0x081091CC
	push {lr}
	ldr r2, _081091E0 @ =0x0000046D
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081091DC
	movs r0, #0
	strb r0, [r1]
_081091DC:
	pop {r0}
	bx r0
	.align 2, 0
_081091E0: .4byte 0x0000046D

	thumb_func_start FUN_081091e4
FUN_081091e4: @ 0x081091E4
	push {lr}
	ldr r2, _081091F8 @ =0x0000046D
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081091F4
	movs r0, #0
	strb r0, [r1]
_081091F4:
	pop {r0}
	bx r0
	.align 2, 0
_081091F8: .4byte 0x0000046D

	thumb_func_start FUN_081091fc
FUN_081091fc: @ 0x081091FC
	push {lr}
	adds r2, r0, #0
	ldr r0, _0810921C @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810920E
	movs r0, #0
	strb r0, [r1]
_0810920E:
	adds r0, r2, #0
	movs r1, #0
	bl FUN_080ef86c
	pop {r0}
	bx r0
	.align 2, 0
_0810921C: .4byte 0x0000046D

	thumb_func_start FUN_08109220
FUN_08109220: @ 0x08109220
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x88
	adds r7, r0, #0
	ldr r0, _08109240 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08109244
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08109246
	.align 2, 0
_08109240: .4byte 0x0000046D
_08109244:
	movs r0, #0
_08109246:
	cmp r0, #0
	bne _0810924C
	b _08109962
_0810924C:
	ldr r2, _0810938C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08109390 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08109394 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r6, r0, #0
	adds r6, #0xa
	ldr r2, _08109398 @ =0x000001DD
	adds r0, r7, r2
	ldrb r1, [r0]
	adds r0, r7, #0
	bl FUN_081051f4
	adds r5, r0, #0
	cmp r5, #0
	blt _0810927C
	b _081098DC
_0810927C:
	adds r0, r7, #0
	movs r1, #0xf
	bl FUN_080ef86c
	ldr r3, _0810939C @ =0x000001DF
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #2
	beq _0810929A
	movs r0, #4
	ldr r4, _081093A0 @ =0x00000222
	adds r2, r7, r4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0810929A:
	movs r0, #0x80
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r4, r7, r5
	ldrh r1, [r4]
	movs r2, #0
	orrs r0, r1
	strh r0, [r4]
	movs r6, #0x93
	lsls r6, r6, #2
	adds r0, r7, r6
	ldrh r1, [r0]
	ldr r3, _081093A4 @ =0x0000024E
	adds r0, r7, r3
	strh r1, [r0]
	movs r0, #0xc
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x10]
	strb r2, [r5]
	ldr r6, _081093A8 @ =0x00000469
	adds r6, r7, r6
	str r6, [sp, #0x14]
	strb r2, [r6]
	ldr r1, _081093AC @ =0x0000046A
	adds r1, r7, r1
	str r1, [sp, #0x18]
	strb r0, [r1]
	ldr r3, _081093B0 @ =0x00000484
	adds r3, r7, r3
	str r3, [sp, #0x1c]
	movs r5, #0
	str r5, [r3]
	ldr r6, _081093B4 @ =0x0000046C
	adds r6, r7, r6
	str r6, [sp, #0x20]
	movs r1, #1
	strb r1, [r6]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r3, [r0]
	movs r0, #0x1a
	ldr r6, _081093B8 @ =0x0000046D
	adds r5, r7, r6
	strb r1, [r5]
	ldr r1, _081093BC @ =0x0000046B
	adds r1, r1, r7
	mov sl, r1
	strb r2, [r1]
	ldr r2, _081093C0 @ =0x00000553
	adds r2, r2, r7
	mov sb, r2
	strb r0, [r2]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r6, r7
	mov r8, r6
	str r3, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r7, r0
	str r0, [sp, #0x80]
	movs r1, #0
	strh r1, [r0]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r3, r7, r2
	ldr r6, [r3]
	str r6, [sp, #0x24]
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
	str r5, [sp, #0x70]
	str r4, [sp, #0x58]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x5c]
	ldr r4, [sp, #0x14]
	str r4, [sp, #0x60]
	ldr r5, [sp, #0x18]
	str r5, [sp, #0x64]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0x78]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x6c]
	mov r4, sl
	str r4, [sp, #0x68]
	mov r5, sb
	str r5, [sp, #0x4c]
	mov r6, r8
	str r6, [sp, #0x50]
	ldr r0, [sp, #0x80]
	str r0, [sp, #0x7c]
	adds r6, r3, #0
	mov r8, r2
	mov r2, ip
	cmp r2, #0
	blt _08109388
	cmp r1, #0
	blt _08109388
	ldr r0, _081093C4 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _08109388
	ldr r0, _081093C8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081093CC
_08109388:
	movs r4, #0
	b _081093DC
	.align 2, 0
_0810938C: .4byte 0x030046B8
_08109390: .4byte 0x000003FF
_08109394: .4byte 0x0203B400
_08109398: .4byte 0x000001DD
_0810939C: .4byte 0x000001DF
_081093A0: .4byte 0x00000222
_081093A4: .4byte 0x0000024E
_081093A8: .4byte 0x00000469
_081093AC: .4byte 0x0000046A
_081093B0: .4byte 0x00000484
_081093B4: .4byte 0x0000046C
_081093B8: .4byte 0x0000046D
_081093BC: .4byte 0x0000046B
_081093C0: .4byte 0x00000553
_081093C4: .4byte 0x030046A8
_081093C8: .4byte 0x030046AC
_081093CC:
	ldr r0, _081093EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r3, ip
	adds r4, r0, r3
_081093DC:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081093F0
	adds r0, #4
	b _081093FC
	.align 2, 0
_081093EC: .4byte 0x030046A4
_081093F0:
	ldr r0, _08109410 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081093FC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08109414
	cmp r2, #2
	beq _0810941A
	b _08109420
	.align 2, 0
_08109410: .4byte 0x030046A4
_08109414:
	ldr r4, [sp, #0x24]
	ldrb r0, [r4, #4]
	b _0810941E
_0810941A:
	ldr r5, [sp, #0x24]
	ldrb r0, [r5]
_0810941E:
	subs r1, r1, r0
_08109420:
	ldr r0, [sp, #0x24]
	strh r1, [r0, #2]
	ldr r0, _08109438 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0810943C
	movs r0, #1
	b _0810943E
	.align 2, 0
_08109438: .4byte 0x030047A4
_0810943C:
	movs r0, #0
_0810943E:
	cmp r0, #0
	beq _08109484
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0810945E
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0810945A
	adds r2, r0, #0
_0810945A:
	cmp r2, #0
	bge _08109470
_0810945E:
	ldr r2, _0810946C @ =0x000005C4
	adds r0, r7, r2
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081098BC
	.align 2, 0
_0810946C: .4byte 0x000005C4
_08109470:
	ldr r1, _08109480 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081094CC
	.align 2, 0
_08109480: .4byte 0x03002BE0
_08109484:
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
	blt _081094B0
	cmp r1, #0
	blt _081094B0
	ldr r0, _081094B4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081094B0
	ldr r0, _081094B8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081094BC
_081094B0:
	movs r5, #0
	b _081094CA
	.align 2, 0
_081094B4: .4byte 0x030046A8
_081094B8: .4byte 0x030046AC
_081094BC:
	ldr r0, _0810955C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081094CA:
	movs r2, #0
_081094CC:
	ldr r4, _08109560 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081094EC
	ldr r1, _08109564 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081094EC
	b _081097F4
_081094EC:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x58]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08109500
	b _081098BC
_08109500:
	ldr r0, _08109568 @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x58]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _0810956C
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x70]
	strb r2, [r3]
	ldr r6, [sp, #0x68]
	strb r5, [r6]
	ldr r3, [sp, #0x4c]
	strb r0, [r3]
	ldr r6, [sp, #0x50]
	str r1, [r6]
	ldr r0, [sp, #0x7c]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0x5c]
	strb r5, [r1]
	ldr r3, [sp, #0x60]
	strb r5, [r3]
	ldr r5, [sp, #0x64]
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	str r4, [r6]
	ldr r0, [sp, #0x6c]
	strb r2, [r0]
	b _081096BA
	.align 2, 0
_0810955C: .4byte 0x030046A4
_08109560: .4byte 0x00000256
_08109564: .4byte 0x03002BE0
_08109568: .4byte 0x00000222
_0810956C:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x70]
	strb r0, [r2]
	ldr r4, [sp, #0x68]
	strb r5, [r4]
	ldr r2, [sp, #0x4c]
	strb r0, [r2]
	ldr r4, [sp, #0x50]
	str r1, [r4]
	ldr r1, [sp, #0x7c]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x5c]
	strb r5, [r2]
	ldr r4, [sp, #0x60]
	strb r5, [r4]
	ldr r5, [sp, #0x64]
	strb r1, [r5]
	ldr r1, [sp, #0x78]
	str r3, [r1]
	ldr r2, [sp, #0x6c]
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
	blt _081095D0
	cmp r1, #0
	blt _081095D0
	ldr r0, _081095D4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081095D0
	ldr r0, _081095D8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081095DC
_081095D0:
	movs r4, #0
	b _081095EA
	.align 2, 0
_081095D4: .4byte 0x030046A8
_081095D8: .4byte 0x030046AC
_081095DC:
	ldr r0, _081095FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081095EA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08109600
	adds r0, #4
	b _0810960C
	.align 2, 0
_081095FC: .4byte 0x030046A4
_08109600:
	ldr r0, _08109620 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810960C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08109624
	cmp r2, #2
	beq _08109628
	b _0810962C
	.align 2, 0
_08109620: .4byte 0x030046A4
_08109624:
	ldrb r0, [r5, #4]
	b _0810962A
_08109628:
	ldrb r0, [r5]
_0810962A:
	subs r1, r1, r0
_0810962C:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08109654
	cmp r1, #0
	blt _08109654
	ldr r0, _08109658 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08109654
	ldr r0, _0810965C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08109660
_08109654:
	movs r4, #0
	b _0810966E
	.align 2, 0
_08109658: .4byte 0x030046A8
_0810965C: .4byte 0x030046AC
_08109660:
	ldr r0, _08109680 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0810966E:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08109684
	adds r0, #4
	b _08109690
	.align 2, 0
_08109680: .4byte 0x030046A4
_08109684:
	ldr r0, _081096A4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08109690:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081096A8
	cmp r3, #2
	beq _081096AC
	b _081096B0
	.align 2, 0
_081096A4: .4byte 0x030046A4
_081096A8:
	ldrb r0, [r5, #4]
	b _081096AE
_081096AC:
	ldrb r0, [r5]
_081096AE:
	subs r2, r2, r0
_081096B0:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081096BA:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x28]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x58]
	ldrh r0, [r5]
	ands r0, r1
	adds r5, r4, #0
	ldr r6, _081096E4 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x74]
	cmp r0, #0
	bne _081097C2
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081096E8
	movs r0, #1
	b _081096EA
	.align 2, 0
_081096E4: .4byte 0x00000482
_081096E8:
	movs r0, #0
_081096EA:
	ldr r3, _081097D0 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x74]
	cmp r0, #0
	bne _081097C2
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r2, r7, r4
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r6, r7, r0
	ldr r1, _081097D4 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	adds r4, #0xc
	adds r4, r4, r7
	mov sb, r4
	adds r0, #5
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _081097D8 @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x48]
	ldr r4, _081097DC @ =0x00000541
	adds r4, r4, r7
	mov ip, r4
	ldr r0, _081097E0 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x54]
	ldr r1, _081097E4 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x44]
	ldr r1, _081097E8 @ =0x030046B8
	str r5, [sp, #0x84]
_08109730:
	ldr r0, [r1]
	adds r0, #1
	ldr r4, _081097EC @ =0x000003FF
	ands r0, r4
	str r0, [r1]
	lsls r0, r0, #1
	ldr r4, _081097F0 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r4, #3
	ands r0, r4
	lsls r0, r0, #6
	ldr r4, [sp, #0x84]
	cmp r0, r4
	bne _08109756
	adds r3, #1
	cmp r3, #3
	ble _08109730
	adds r0, r5, #0
_08109756:
	movs r3, #0
	strb r0, [r2]
	ldr r5, [sp, #0x50]
	ldr r0, [r5]
	str r0, [r6]
	ldr r6, [sp, #0x4c]
	ldrb r0, [r6]
	mov r1, r8
	strb r0, [r1]
	ldr r2, [sp, #0x5c]
	ldrb r0, [r2]
	mov r4, sb
	strb r0, [r4]
	ldr r5, [sp, #0x60]
	ldrb r0, [r5]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0x64]
	ldrb r0, [r1]
	ldr r2, [sp, #0x48]
	strb r0, [r2]
	add r4, sp, #0x28
	ldrb r5, [r4]
	mov r4, ip
	strb r5, [r4]
	ldr r5, [sp, #0x54]
	ldr r2, [r5]
	movs r0, #0x1b
	movs r1, #1
	ldr r6, [sp, #0x70]
	strb r1, [r6]
	ldr r4, [sp, #0x68]
	strb r3, [r4]
	ldr r5, [sp, #0x4c]
	strb r0, [r5]
	ldr r6, [sp, #0x50]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x7c]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x5c]
	strb r0, [r4]
	ldr r5, [sp, #0x60]
	strb r1, [r5]
	ldr r6, [sp, #0x64]
	strb r2, [r6]
	ldr r0, [sp, #0x78]
	str r3, [r0]
	ldr r2, [sp, #0x6c]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x44]
	strb r0, [r3]
_081097C2:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x74]
	strh r0, [r4]
	b _081098BC
	.align 2, 0
_081097D0: .4byte 0x00000482
_081097D4: .4byte 0x0000054F
_081097D8: .4byte 0x0000054E
_081097DC: .4byte 0x00000541
_081097E0: .4byte 0x000005BC
_081097E4: .4byte 0x00000542
_081097E8: .4byte 0x030046B8
_081097EC: .4byte 0x000003FF
_081097F0: .4byte 0x0203B400
_081097F4:
	mov sb, sp
	ldr r6, _08109830 @ =0x030046A4
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
	beq _08109834
	adds r0, #4
	b _0810983E
	.align 2, 0
_08109830: .4byte 0x030046A4
_08109834:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0810983E:
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
	ldr r6, _08109878 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _08109880
	ldr r0, _0810987C @ =0xFFFFFDFF
	ldr r2, [sp, #0x58]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081098AA
	.align 2, 0
_08109878: .4byte 0x000004A4
_0810987C: .4byte 0xFFFFFDFF
_08109880:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081098A0
	cmp r0, #2
	beq _0810989C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0810989C:
	movs r0, #1
	b _081098AC
_081098A0:
	ldr r0, _081098D4 @ =0xFFFFFDFF
	ldr r3, [sp, #0x58]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081098AA:
	movs r0, #0
_081098AC:
	cmp r0, #0
	bne _081098BC
	ldr r4, _081098D8 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
_081098BC:
	movs r5, #0xe6
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	movs r1, #0x80
	movs r6, #0xe6
	lsls r6, r6, #3
	adds r0, r0, r6
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	b _08109F70
	.align 2, 0
_081098D4: .4byte 0xFFFFFDFF
_081098D8: .4byte 0x000005C4
_081098DC:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r4, r7, r0
	lsls r3, r5, #6
	ldr r2, _08109900 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08109904
	asrs r1, r0, #0xc
	b _0810990A
	.align 2, 0
_08109900: .4byte 0x085B0A08
_08109904:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810990A:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08109926
	asrs r0, r0, #0xc
	b _0810992C
_08109926:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810992C:
	strh r0, [r4, #4]
	adds r0, r5, #2
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #6
	strb r0, [r7, #5]
	ldr r2, _08109A4C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08109A50 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08109A54 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0xc
	movs r4, #0xe1
	lsls r4, r4, #1
	adds r1, r7, r4
	strh r0, [r1]
	adds r0, r7, #0
	movs r1, #0xe
	bl FUN_080ef86c
_08109962:
	movs r1, #0x10
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08109974
	b _08109F70
_08109974:
	adds r0, r7, #0
	movs r1, #0xf
	bl FUN_080ef86c
	movs r0, #0xc
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x2c]
	movs r1, #0
	strb r1, [r6]
	ldr r2, _08109A58 @ =0x00000469
	adds r2, r7, r2
	str r2, [sp, #0x30]
	strb r1, [r2]
	ldr r3, _08109A5C @ =0x0000046A
	adds r3, r7, r3
	str r3, [sp, #0x34]
	strb r0, [r3]
	ldr r4, _08109A60 @ =0x00000484
	adds r4, r7, r4
	str r4, [sp, #0x38]
	str r1, [r4]
	ldr r5, _08109A64 @ =0x0000046C
	adds r5, r5, r7
	mov sl, r5
	movs r2, #1
	strb r2, [r5]
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r3, [r0]
	movs r0, #0x1a
	ldr r5, _08109A68 @ =0x0000046D
	adds r4, r7, r5
	strb r2, [r4]
	ldr r6, _08109A6C @ =0x0000046B
	adds r6, r6, r7
	mov sb, r6
	strb r1, [r6]
	ldr r2, _08109A70 @ =0x00000553
	adds r2, r2, r7
	mov r8, r2
	strb r0, [r2]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x80]
	str r3, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	strh r1, [r5]
	movs r0, #0x95
	lsls r0, r0, #3
	adds r3, r7, r0
	ldr r1, [r3]
	str r1, [sp, #0x3c]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x3c]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r4, [sp, #0x70]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0x5c]
	ldr r4, [sp, #0x30]
	str r4, [sp, #0x60]
	ldr r6, [sp, #0x34]
	str r6, [sp, #0x64]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0x78]
	mov r4, sl
	str r4, [sp, #0x6c]
	mov r6, sb
	str r6, [sp, #0x68]
	mov r0, r8
	str r0, [sp, #0x4c]
	ldr r4, [sp, #0x80]
	str r4, [sp, #0x50]
	str r5, [sp, #0x7c]
	adds r6, r3, #0
	mov r8, r2
	mov r5, ip
	cmp r5, #0
	blt _08109A46
	cmp r1, #0
	blt _08109A46
	ldr r0, _08109A74 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _08109A46
	ldr r0, _08109A78 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08109A7C
_08109A46:
	movs r4, #0
	b _08109A8C
	.align 2, 0
_08109A4C: .4byte 0x030046B8
_08109A50: .4byte 0x000003FF
_08109A54: .4byte 0x0203B400
_08109A58: .4byte 0x00000469
_08109A5C: .4byte 0x0000046A
_08109A60: .4byte 0x00000484
_08109A64: .4byte 0x0000046C
_08109A68: .4byte 0x0000046D
_08109A6C: .4byte 0x0000046B
_08109A70: .4byte 0x00000553
_08109A74: .4byte 0x030046A8
_08109A78: .4byte 0x030046AC
_08109A7C:
	ldr r0, _08109A9C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_08109A8C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08109AA0
	adds r0, #4
	b _08109AAC
	.align 2, 0
_08109A9C: .4byte 0x030046A4
_08109AA0:
	ldr r0, _08109AC0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08109AAC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08109AC4
	cmp r2, #2
	beq _08109ACA
	b _08109AD0
	.align 2, 0
_08109AC0: .4byte 0x030046A4
_08109AC4:
	ldr r2, [sp, #0x3c]
	ldrb r0, [r2, #4]
	b _08109ACE
_08109ACA:
	ldr r3, [sp, #0x3c]
	ldrb r0, [r3]
_08109ACE:
	subs r1, r1, r0
_08109AD0:
	ldr r4, [sp, #0x3c]
	strh r1, [r4, #2]
	ldr r0, _08109AE8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08109AEC
	movs r0, #1
	b _08109AEE
	.align 2, 0
_08109AE8: .4byte 0x030047A4
_08109AEC:
	movs r0, #0
_08109AEE:
	cmp r0, #0
	beq _08109B34
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _08109B0E
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08109B0A
	adds r2, r0, #0
_08109B0A:
	cmp r2, #0
	bge _08109B20
_08109B0E:
	ldr r6, _08109B1C @ =0x000005C4
	adds r0, r7, r6
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _08109F70
	.align 2, 0
_08109B1C: .4byte 0x000005C4
_08109B20:
	ldr r1, _08109B30 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08109B7C
	.align 2, 0
_08109B30: .4byte 0x03002BE0
_08109B34:
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
	blt _08109B60
	cmp r1, #0
	blt _08109B60
	ldr r0, _08109B64 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08109B60
	ldr r0, _08109B68 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08109B6C
_08109B60:
	movs r5, #0
	b _08109B7A
	.align 2, 0
_08109B64: .4byte 0x030046A8
_08109B68: .4byte 0x030046AC
_08109B6C:
	ldr r0, _08109C10 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08109B7A:
	movs r2, #0
_08109B7C:
	ldr r3, _08109C14 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _08109B9C
	ldr r1, _08109C18 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08109B9C
	b _08109EA8
_08109B9C:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	str r2, [sp, #0x58]
	cmp r4, #0
	beq _08109BB6
	b _08109F70
_08109BB6:
	ldr r5, _08109C1C @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x58]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _08109C20
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x70]
	strb r2, [r3]
	ldr r6, [sp, #0x68]
	strb r5, [r6]
	ldr r3, [sp, #0x4c]
	strb r0, [r3]
	ldr r6, [sp, #0x50]
	str r1, [r6]
	ldr r0, [sp, #0x7c]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0x5c]
	strb r5, [r1]
	ldr r3, [sp, #0x60]
	strb r5, [r3]
	ldr r5, [sp, #0x64]
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	str r4, [r6]
	ldr r0, [sp, #0x6c]
	strb r2, [r0]
	b _08109D6E
	.align 2, 0
_08109C10: .4byte 0x030046A4
_08109C14: .4byte 0x00000256
_08109C18: .4byte 0x03002BE0
_08109C1C: .4byte 0x00000222
_08109C20:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x70]
	strb r0, [r2]
	ldr r4, [sp, #0x68]
	strb r5, [r4]
	ldr r2, [sp, #0x4c]
	strb r0, [r2]
	ldr r4, [sp, #0x50]
	str r1, [r4]
	ldr r1, [sp, #0x7c]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x5c]
	strb r5, [r2]
	ldr r4, [sp, #0x60]
	strb r5, [r4]
	ldr r5, [sp, #0x64]
	strb r1, [r5]
	ldr r1, [sp, #0x78]
	str r3, [r1]
	ldr r2, [sp, #0x6c]
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
	blt _08109C84
	cmp r1, #0
	blt _08109C84
	ldr r0, _08109C88 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08109C84
	ldr r0, _08109C8C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08109C90
_08109C84:
	movs r4, #0
	b _08109C9E
	.align 2, 0
_08109C88: .4byte 0x030046A8
_08109C8C: .4byte 0x030046AC
_08109C90:
	ldr r0, _08109CB0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08109C9E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08109CB4
	adds r0, #4
	b _08109CC0
	.align 2, 0
_08109CB0: .4byte 0x030046A4
_08109CB4:
	ldr r0, _08109CD4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08109CC0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08109CD8
	cmp r2, #2
	beq _08109CDC
	b _08109CE0
	.align 2, 0
_08109CD4: .4byte 0x030046A4
_08109CD8:
	ldrb r0, [r5, #4]
	b _08109CDE
_08109CDC:
	ldrb r0, [r5]
_08109CDE:
	subs r1, r1, r0
_08109CE0:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08109D08
	cmp r1, #0
	blt _08109D08
	ldr r0, _08109D0C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08109D08
	ldr r0, _08109D10 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08109D14
_08109D08:
	movs r4, #0
	b _08109D22
	.align 2, 0
_08109D0C: .4byte 0x030046A8
_08109D10: .4byte 0x030046AC
_08109D14:
	ldr r0, _08109D34 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08109D22:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08109D38
	adds r0, #4
	b _08109D44
	.align 2, 0
_08109D34: .4byte 0x030046A4
_08109D38:
	ldr r0, _08109D58 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08109D44:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08109D5C
	cmp r3, #2
	beq _08109D60
	b _08109D64
	.align 2, 0
_08109D58: .4byte 0x030046A4
_08109D5C:
	ldrb r0, [r5, #4]
	b _08109D62
_08109D60:
	ldrb r0, [r5]
_08109D62:
	subs r2, r2, r0
_08109D64:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_08109D6E:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x40]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x58]
	ldrh r0, [r5]
	ands r0, r1
	adds r5, r4, #0
	ldr r6, _08109D98 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x74]
	cmp r0, #0
	bne _08109E76
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08109D9C
	movs r0, #1
	b _08109D9E
	.align 2, 0
_08109D98: .4byte 0x00000482
_08109D9C:
	movs r0, #0
_08109D9E:
	ldr r3, _08109E84 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x74]
	cmp r0, #0
	bne _08109E76
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r2, r7, r4
	movs r0, #0xa9
	lsls r0, r0, #3
	adds r6, r7, r0
	ldr r1, _08109E88 @ =0x0000054F
	adds r1, r1, r7
	mov r8, r1
	adds r4, #0xc
	adds r4, r4, r7
	mov sb, r4
	adds r0, #5
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _08109E8C @ =0x0000054E
	adds r1, r7, r1
	str r1, [sp, #0x48]
	ldr r4, _08109E90 @ =0x00000541
	adds r4, r4, r7
	mov ip, r4
	ldr r0, _08109E94 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x54]
	ldr r1, _08109E98 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x44]
	ldr r1, _08109E9C @ =0x030046B8
	str r5, [sp, #0x84]
_08109DE4:
	ldr r0, [r1]
	adds r0, #1
	ldr r4, _08109EA0 @ =0x000003FF
	ands r0, r4
	str r0, [r1]
	lsls r0, r0, #1
	ldr r4, _08109EA4 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r4, #3
	ands r0, r4
	lsls r0, r0, #6
	ldr r4, [sp, #0x84]
	cmp r0, r4
	bne _08109E0A
	adds r3, #1
	cmp r3, #3
	ble _08109DE4
	adds r0, r5, #0
_08109E0A:
	movs r3, #0
	strb r0, [r2]
	ldr r5, [sp, #0x50]
	ldr r0, [r5]
	str r0, [r6]
	ldr r6, [sp, #0x4c]
	ldrb r0, [r6]
	mov r1, r8
	strb r0, [r1]
	ldr r2, [sp, #0x5c]
	ldrb r0, [r2]
	mov r4, sb
	strb r0, [r4]
	ldr r5, [sp, #0x60]
	ldrb r0, [r5]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0x64]
	ldrb r0, [r1]
	ldr r2, [sp, #0x48]
	strb r0, [r2]
	add r4, sp, #0x40
	ldrb r5, [r4]
	mov r4, ip
	strb r5, [r4]
	ldr r5, [sp, #0x54]
	ldr r2, [r5]
	movs r0, #0x1b
	movs r1, #1
	ldr r6, [sp, #0x70]
	strb r1, [r6]
	ldr r4, [sp, #0x68]
	strb r3, [r4]
	ldr r5, [sp, #0x4c]
	strb r0, [r5]
	ldr r6, [sp, #0x50]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x7c]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x5c]
	strb r0, [r4]
	ldr r5, [sp, #0x60]
	strb r1, [r5]
	ldr r6, [sp, #0x64]
	strb r2, [r6]
	ldr r0, [sp, #0x78]
	str r3, [r0]
	ldr r2, [sp, #0x6c]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x44]
	strb r0, [r3]
_08109E76:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x74]
	strh r0, [r4]
	b _08109F70
	.align 2, 0
_08109E84: .4byte 0x00000482
_08109E88: .4byte 0x0000054F
_08109E8C: .4byte 0x0000054E
_08109E90: .4byte 0x00000541
_08109E94: .4byte 0x000005BC
_08109E98: .4byte 0x00000542
_08109E9C: .4byte 0x030046B8
_08109EA0: .4byte 0x000003FF
_08109EA4: .4byte 0x0203B400
_08109EA8:
	add r6, sp, #8
	ldr r0, _08109EE8 @ =0x030046A4
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
	beq _08109EEC
	adds r0, #4
	b _08109EF8
	.align 2, 0
_08109EE8: .4byte 0x030046A4
_08109EEC:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08109EF8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _08109F2C @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _08109F30
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
	b _08109F56
	.align 2, 0
_08109F2C: .4byte 0x000004A4
_08109F30:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _08109F50
	cmp r0, #2
	beq _08109F4C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08109F4C:
	movs r0, #1
	b _08109F60
_08109F50:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
_08109F56:
	ldr r1, _08109F80 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08109F60:
	cmp r0, #0
	bne _08109F70
	ldr r2, _08109F84 @ =0x000005C4
	adds r0, r7, r2
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
_08109F70:
	add sp, #0x88
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08109F80: .4byte 0xFFFFFDFF
_08109F84: .4byte 0x000005C4

	thumb_func_start FUN_08109f88
FUN_08109f88: @ 0x08109F88
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r0, _08109FAC @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08109FB0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08109FB2
	.align 2, 0
_08109FAC: .4byte 0x0000046D
_08109FB0:
	movs r0, #0
_08109FB2:
	cmp r0, #0
	beq _08109FBE
	adds r0, r5, #0
	movs r1, #5
	bl FUN_080ef86c
_08109FBE:
	ldr r1, _0810A038 @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08109FDA
	ldrh r0, [r4, #0x14]
	cmp r0, #2
	bne _08109FDA
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	bne _08109FDA
	ldr r0, _0810A03C @ =0x000003A9
	bl PlaySound_082406e0
_08109FDA:
	ldrh r0, [r4, #0x14]
	cmp r0, #3
	bne _0810A000
	movs r1, #0xd5
	lsls r1, r1, #3
	adds r0, r6, r1
	bl FUN_08236400
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	bne _0810A000
	ldr r1, _0810A038 @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _0810A000
	ldr r0, _0810A040 @ =0x000003AA
	bl PlaySound_082406e0
_0810A000:
	ldr r1, _0810A044 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810A032
	ldr r4, _0810A048 @ =FUN_0810a054
	movs r3, #0x3d
	ldr r0, _0810A04C @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810A050 @ =0x0000046B
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
_0810A032:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0810A038: .4byte 0x000001DF
_0810A03C: .4byte 0x000003A9
_0810A040: .4byte 0x000003AA
_0810A044: .4byte 0x0000046E
_0810A048: .4byte FUN_0810a054
_0810A04C: .4byte 0x0000046D
_0810A050: .4byte 0x0000046B

	thumb_func_start FUN_0810a054
FUN_0810a054: @ 0x0810A054
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r0, _0810A074 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810A078
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810A07A
	.align 2, 0
_0810A074: .4byte 0x0000046D
_0810A078:
	movs r0, #0
_0810A07A:
	cmp r0, #0
	beq _0810A086
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
_0810A086:
	ldr r1, _0810A0A0 @ =0x0000075A
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r6, r0
	ble _0810A098
	ldr r0, _0810A0A4 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0810A098:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0810A0A0: .4byte 0x0000075A
_0810A0A4: .4byte 0x0000046B

	thumb_func_start FUN_0810a0a8
FUN_0810a0a8: @ 0x0810A0A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r5, [r0]
	ldr r0, [r7, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r2, _0810A0D8 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810A0DC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810A0DE
	.align 2, 0
_0810A0D8: .4byte 0x0000046D
_0810A0DC:
	movs r0, #0
_0810A0DE:
	cmp r0, #0
	beq _0810A0EA
	adds r0, r7, #0
	movs r1, #5
	bl FUN_080ef86c
_0810A0EA:
	ldrh r0, [r4, #0x14]
	cmp r0, #2
	bne _0810A0FC
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	bne _0810A0FC
	ldr r0, _0810A124 @ =0x000003A9
	bl PlaySound_082406e0
_0810A0FC:
	ldrh r0, [r4, #0x14]
	cmp r0, #3
	bne _0810A10C
	movs r1, #0xd5
	lsls r1, r1, #3
	adds r0, r5, r1
	bl FUN_08236400
_0810A10C:
	movs r2, #0x20
	movs r0, #0xe6
	lsls r0, r0, #3
	adds r1, r5, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0810A128
	movs r0, #1
	b _0810A12A
	.align 2, 0
_0810A124: .4byte 0x000003A9
_0810A128:
	movs r0, #0
_0810A12A:
	adds r4, r0, #0
	cmp r4, #0
	bne _0810A132
	b _0810A3A0
_0810A132:
	ldrb r0, [r7, #5]
	adds r1, r0, #0
	adds r1, #0x10
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _0810A144
	asrs r0, r1, #6
	b _0810A14A
_0810A144:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0810A14A:
	lsls r3, r0, #6
	add r4, sp, #0x2c
	movs r5, #0x14
	ldr r2, _0810A170 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	adds r6, r2, #0
	cmp r0, #0
	blt _0810A174
	asrs r1, r0, #0xc
	b _0810A17A
	.align 2, 0
_0810A170: .4byte 0x085B0A08
_0810A174:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810A17A:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0810A196
	asrs r0, r0, #0xc
	b _0810A19C
_0810A196:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810A19C:
	strh r0, [r4, #4]
	ldr r2, _0810A1D4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0810A1D8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0810A1DC @ =0x0203B400
	adds r0, r0, r1
	movs r1, #0xff
	ldrb r3, [r0]
	add r5, sp, #0x34
	movs r4, #0xa
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	mov r8, r5
	cmp r0, #0
	blt _0810A1E0
	asrs r2, r0, #0xc
	b _0810A1E6
	.align 2, 0
_0810A1D4: .4byte 0x030046B8
_0810A1D8: .4byte 0x000003FF
_0810A1DC: .4byte 0x0203B400
_0810A1E0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0810A1E6:
	movs r0, #0
	strh r2, [r5]
	strh r0, [r5, #2]
	ldr r1, _0810A204 @ =0x085B0A08
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0810A208
	asrs r0, r0, #0xc
	b _0810A20E
	.align 2, 0
_0810A204: .4byte 0x085B0A08
_0810A208:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810A20E:
	movs r4, #0
	strh r0, [r5, #4]
	movs r2, #0x1e
	mov ip, r2
	mov r1, ip
	mov r0, r8
	strh r1, [r0, #2]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp, #0x3c]
	str r1, [sp, #0x40]
	ldr r2, [sp, #0x3c]
	asrs r1, r2, #0x10
	movs r0, #0x82
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _0810A2B8 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x3c]
	add r5, sp, #0x3c
	add r1, sp, #0x34
	ldrh r0, [r5]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5]
	mov r1, r8
	ldrh r0, [r1, #2]
	ldrh r1, [r5, #2]
	adds r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r5, #4]
	mov r2, r8
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r5, #4]
	ldr r2, _0810A2BC @ =0x0000D45E
	ldr r3, _0810A2C0 @ =0x00001DC3
	movs r0, #2
	str r0, [sp]
	mov r1, ip
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0xf7
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r0, r5, #0
	mov r1, r8
	bl FUN_081ef708
	ldr r2, _0810A2C4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0810A2C8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0810A2CC @ =0x0203B400
	adds r0, r0, r2
	movs r2, #0xff
	ldrb r3, [r0]
	mov ip, r8
	movs r4, #0xa
	ldr r1, _0810A2D0 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	adds r6, r5, #0
	cmp r0, #0
	blt _0810A2D4
	asrs r1, r0, #0xc
	b _0810A2DA
	.align 2, 0
_0810A2B8: .4byte 0x0000FFFF
_0810A2BC: .4byte 0x0000D45E
_0810A2C0: .4byte 0x00001DC3
_0810A2C4: .4byte 0x030046B8
_0810A2C8: .4byte 0x000003FF
_0810A2CC: .4byte 0x0203B400
_0810A2D0: .4byte 0x085B0A08
_0810A2D4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810A2DA:
	movs r0, #0
	mov r2, ip
	strh r1, [r2]
	strh r0, [r2, #2]
	ldr r1, _0810A2FC @ =0x085B0A08
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0810A300
	asrs r0, r0, #0xc
	b _0810A306
	.align 2, 0
_0810A2FC: .4byte 0x085B0A08
_0810A300:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810A306:
	movs r2, #0
	mov sb, r2
	movs r4, #0
	mov r1, ip
	strh r0, [r1, #4]
	movs r5, #0x1e
	mov r2, r8
	strh r5, [r2, #2]
	ldrh r0, [r6, #2]
	adds r0, #0xdc
	strh r0, [r6, #2]
	add r2, sp, #0x34
	add r1, sp, #0x3c
	ldrh r0, [r1]
	ldrh r2, [r2]
	adds r0, r0, r2
	strh r0, [r1]
	mov r1, r8
	ldrh r0, [r1, #2]
	ldrh r1, [r6, #2]
	adds r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r6, #4]
	mov r2, r8
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r6, #4]
	ldr r2, _0810A388 @ =0x0000D45E
	ldr r3, _0810A38C @ =0x00001DC3
	movs r0, #3
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0xf7
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r0, r6, #0
	mov r1, r8
	bl FUN_081ef708
	movs r0, #0x21
	rsbs r0, r0, #0
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r3, _0810A390 @ =FUN_0810a3f4
	movs r2, #0x24
	ldr r0, _0810A394 @ =0x0000046D
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810A398 @ =0x0000046B
	adds r0, r7, r1
	mov r1, sb
	strb r1, [r0]
	ldr r1, _0810A39C @ =0x00000553
	b _0810A3BE
	.align 2, 0
_0810A388: .4byte 0x0000D45E
_0810A38C: .4byte 0x00001DC3
_0810A390: .4byte FUN_0810a3f4
_0810A394: .4byte 0x0000046D
_0810A398: .4byte 0x0000046B
_0810A39C: .4byte 0x00000553
_0810A3A0:
	ldr r2, _0810A3E4 @ =0x0000046E
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810A3D2
	ldr r3, _0810A3E8 @ =FUN_0810a4bc
	movs r2, #0x23
	ldr r0, _0810A3EC @ =0x0000046D
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810A3F0 @ =0x0000046B
	adds r0, r7, r1
	strb r4, [r0]
	adds r1, #0xe8
_0810A3BE:
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r7, r2
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
_0810A3D2:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810A3E4: .4byte 0x0000046E
_0810A3E8: .4byte FUN_0810a4bc
_0810A3EC: .4byte 0x0000046D
_0810A3F0: .4byte 0x0000046B

	thumb_func_start FUN_0810a3f4
FUN_0810a3f4: @ 0x0810A3F4
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r2, _0810A414 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810A418
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810A41A
	.align 2, 0
_0810A414: .4byte 0x0000046D
_0810A418:
	movs r0, #0
_0810A41A:
	cmp r0, #0
	beq _0810A464
	adds r0, r5, #0
	movs r1, #0x16
	bl FUN_080ef86c
	ldr r3, _0810A4A0 @ =0x000001DF
	adds r1, r5, r3
	movs r0, #5
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_0810388c
	adds r0, r5, #0
	bl FUN_08105690
	movs r1, #0xd5
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r2, _0810A4A4 @ =0x0000022A
	adds r1, r5, r2
	ldrh r1, [r1]
	ldr r3, _0810A4A8 @ =0x00000232
	adds r2, r5, r3
	ldrh r2, [r2]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r3, r5, r4
	ldr r3, [r3]
	str r3, [sp]
	subs r4, #0xe
	adds r3, r5, r4
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
_0810A464:
	ldr r1, _0810A4AC @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810A498
	ldr r4, _0810A4B0 @ =FUN_0810a054
	movs r3, #0x3d
	ldr r2, _0810A4B4 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810A4B8 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
_0810A498:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0810A4A0: .4byte 0x000001DF
_0810A4A4: .4byte 0x0000022A
_0810A4A8: .4byte 0x00000232
_0810A4AC: .4byte 0x0000046E
_0810A4B0: .4byte FUN_0810a054
_0810A4B4: .4byte 0x0000046D
_0810A4B8: .4byte 0x0000046B

	thumb_func_start FUN_0810a4bc
FUN_0810a4bc: @ 0x0810A4BC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0810A4D4 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810A4D8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810A4DA
	.align 2, 0
_0810A4D4: .4byte 0x0000046D
_0810A4D8:
	movs r0, #0
_0810A4DA:
	cmp r0, #0
	beq _0810A4E6
	adds r0, r5, #0
	movs r1, #0x17
	bl FUN_080ef86c
_0810A4E6:
	ldr r1, _0810A520 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810A518
	ldr r4, _0810A524 @ =FUN_0810a054
	movs r3, #0x3d
	ldr r0, _0810A528 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810A52C @ =0x0000046B
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
_0810A518:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0810A520: .4byte 0x0000046E
_0810A524: .4byte FUN_0810a054
_0810A528: .4byte 0x0000046D
_0810A52C: .4byte 0x0000046B

	thumb_func_start FUN_0810a530
FUN_0810a530: @ 0x0810A530
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0810A548 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810A54C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810A54E
	.align 2, 0
_0810A548: .4byte 0x0000046D
_0810A54C:
	movs r0, #0
_0810A54E:
	cmp r0, #0
	beq _0810A55A
	adds r0, r5, #0
	movs r1, #0x13
	bl FUN_080ef86c
_0810A55A:
	ldr r1, _0810A594 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810A58C
	ldr r4, _0810A598 @ =FUN_0810a5a4
	movs r3, #0x27
	ldr r0, _0810A59C @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810A5A0 @ =0x0000046B
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
_0810A58C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0810A594: .4byte 0x0000046E
_0810A598: .4byte FUN_0810a5a4
_0810A59C: .4byte 0x0000046D
_0810A5A0: .4byte 0x0000046B

	thumb_func_start FUN_0810a5a4
FUN_0810a5a4: @ 0x0810A5A4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	ldr r0, _0810A5BC @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810A5C0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810A5C2
	.align 2, 0
_0810A5BC: .4byte 0x0000046D
_0810A5C0:
	movs r0, #0
_0810A5C2:
	cmp r0, #0
	beq _0810A5D4
	adds r0, r6, #0
	movs r1, #0x14
	bl FUN_080ef86c
	ldr r0, _0810A5F8 @ =0x000003AB
	bl PlaySound_082406e0
_0810A5D4:
	add r3, sp, #0xc
	ldrb r4, [r6, #5]
	ldr r2, _0810A5FC @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	adds r5, r3, #0
	cmp r0, #0
	blt _0810A600
	asrs r1, r0, #0xc
	b _0810A606
	.align 2, 0
_0810A5F8: .4byte 0x000003AB
_0810A5FC: .4byte 0x085B0A08
_0810A600:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810A606:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _0810A620
	asrs r0, r0, #0xc
	b _0810A626
_0810A620:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810A626:
	movs r7, #0
	strh r0, [r3, #4]
	ldrh r0, [r5]
	ldrh r1, [r6, #0x10]
	adds r0, r0, r1
	strh r0, [r6, #0x10]
	add r5, sp, #0xc
	ldrh r0, [r5, #4]
	ldrh r2, [r6, #0x14]
	adds r0, r0, r2
	strh r0, [r6, #0x14]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	str r7, [sp, #8]
	add r0, sp, #8
	adds r1, r5, #0
	ldr r2, _0810A6C4 @ =0x05000002
	bl CpuSet
	ldr r4, _0810A6C8 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r4
	movs r3, #0x52
	orrs r0, r3
	ldr r1, _0810A6CC @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #0x14]
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r4
	orrs r0, r3
	str r0, [r2, #4]
	adds r0, r6, #0
	adds r0, #8
	movs r1, #2
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	adds r1, r5, #0
	movs r3, #1
	bl FUN_080dbcec
	ldr r1, _0810A6D0 @ =0x0000046E
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810A6BA
	ldr r3, _0810A6D4 @ =FUN_0810a6e4
	movs r2, #0x28
	ldr r0, _0810A6D8 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0810A6DC @ =0x0000046B
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0810A6E0 @ =0x00000553
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r7, [r0]
_0810A6BA:
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810A6C4: .4byte 0x05000002
_0810A6C8: .4byte 0xFFFF0000
_0810A6CC: .4byte 0x0000FFFF
_0810A6D0: .4byte 0x0000046E
_0810A6D4: .4byte FUN_0810a6e4
_0810A6D8: .4byte 0x0000046D
_0810A6DC: .4byte 0x0000046B
_0810A6E0: .4byte 0x00000553

	thumb_func_start FUN_0810a6e4
FUN_0810a6e4: @ 0x0810A6E4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	mov sb, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r0, _0810A710 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810A714
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810A716
	.align 2, 0
_0810A710: .4byte 0x0000046D
_0810A714:
	movs r0, #0
_0810A716:
	cmp r0, #0
	beq _0810A72A
	adds r0, r7, #0
	movs r1, #0x15
	bl FUN_080ef86c
	ldr r1, _0810A754 @ =0x00000725
	add r1, r8
	movs r0, #0x48
	strb r0, [r1]
_0810A72A:
	ldr r0, _0810A754 @ =0x00000725
	add r0, r8
	add r3, sp, #0xc
	ldrb r4, [r7, #5]
	ldrb r5, [r0]
	ldr r2, _0810A758 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	adds r6, r3, #0
	cmp r0, #0
	blt _0810A75C
	asrs r1, r0, #0xc
	b _0810A762
	.align 2, 0
_0810A754: .4byte 0x00000725
_0810A758: .4byte 0x085B0A08
_0810A75C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810A762:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0810A77A
	asrs r0, r0, #0xc
	b _0810A780
_0810A77A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810A780:
	strh r0, [r3, #4]
	ldrh r0, [r6]
	ldrh r1, [r7, #0x10]
	adds r0, r0, r1
	strh r0, [r7, #0x10]
	add r0, sp, #0xc
	ldrh r0, [r0, #4]
	ldrh r1, [r7, #0x14]
	adds r0, r0, r1
	strh r0, [r7, #0x14]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r0, sb
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0810A810
	ldr r0, _0810A7C0 @ =0x00000725
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	blt _0810A7C4
	asrs r1, r0, #1
	b _0810A7CA
	.align 2, 0
_0810A7C0: .4byte 0x00000725
_0810A7C4:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_0810A7CA:
	ldr r0, _0810A864 @ =0x00000725
	add r0, r8
	movs r6, #0
	strb r1, [r0]
	ldr r3, _0810A868 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r3
	movs r2, #0x52
	orrs r0, r2
	ldr r1, _0810A86C @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #0x14]
	add r4, sp, #0x14
	ldr r0, [r4, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r4, #4]
	add r5, sp, #0x1c
	str r6, [sp, #8]
	add r0, sp, #8
	adds r1, r5, #0
	ldr r2, _0810A870 @ =0x05000002
	bl CpuSet
	adds r0, r7, #0
	adds r0, #8
	movs r1, #2
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	adds r1, r5, #0
	adds r2, r4, #0
	movs r3, #1
	bl FUN_080dbcec
_0810A810:
	movs r0, #0xd5
	lsls r0, r0, #3
	add r0, r8
	bl FUN_08236400
	ldr r1, _0810A874 @ =0x0000046E
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810A854
	ldr r0, _0810A864 @ =0x00000725
	add r0, r8
	ldrb r4, [r0]
	cmp r4, #0
	bne _0810A854
	ldr r3, _0810A878 @ =FUN_0810a884
	movs r2, #0x29
	ldr r0, _0810A87C @ =0x0000046D
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810A880 @ =0x0000046B
	adds r0, r7, r1
	strb r4, [r0]
	adds r1, #0xe8
	adds r0, r7, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r7, r1
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
_0810A854:
	add sp, #0x24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810A864: .4byte 0x00000725
_0810A868: .4byte 0xFFFF0000
_0810A86C: .4byte 0x0000FFFF
_0810A870: .4byte 0x05000002
_0810A874: .4byte 0x0000046E
_0810A878: .4byte FUN_0810a884
_0810A87C: .4byte 0x0000046D
_0810A880: .4byte 0x0000046B

	thumb_func_start FUN_0810a884
FUN_0810a884: @ 0x0810A884
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0810A89C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810A8A0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810A8A2
	.align 2, 0
_0810A89C: .4byte 0x0000046D
_0810A8A0:
	movs r0, #0
_0810A8A2:
	cmp r0, #0
	beq _0810A8AE
	adds r0, r5, #0
	movs r1, #0x16
	bl FUN_080ef86c
_0810A8AE:
	ldr r1, _0810A8E8 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810A8E0
	ldr r4, _0810A8EC @ =FUN_0810a054
	movs r3, #0x3d
	ldr r0, _0810A8F0 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810A8F4 @ =0x0000046B
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
_0810A8E0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0810A8E8: .4byte 0x0000046E
_0810A8EC: .4byte FUN_0810a054
_0810A8F0: .4byte 0x0000046D
_0810A8F4: .4byte 0x0000046B

	thumb_func_start FUN_0810a8f8
FUN_0810a8f8: @ 0x0810A8F8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r0, _0810A91C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810A920
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810A922
	.align 2, 0
_0810A91C: .4byte 0x0000046D
_0810A920:
	movs r0, #0
_0810A922:
	cmp r0, #0
	beq _0810A92E
	adds r0, r5, #0
	movs r1, #0x17
	bl FUN_080ef86c
_0810A92E:
	ldrh r1, [r4, #0x14]
	subs r0, r1, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _0810A944
	subs r0, r1, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _0810A94E
_0810A944:
	movs r1, #0xd5
	lsls r1, r1, #3
	adds r0, r6, r1
	bl FUN_08236400
_0810A94E:
	ldrh r0, [r4, #0x14]
	cmp r0, #4
	beq _0810A958
	cmp r0, #7
	bne _0810A964
_0810A958:
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	bne _0810A964
	ldr r0, _0810A99C @ =0x000003AA
	bl PlaySound_082406e0
_0810A964:
	ldr r1, _0810A9A0 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810A996
	ldr r4, _0810A9A4 @ =FUN_0810a054
	movs r3, #0x3d
	ldr r0, _0810A9A8 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810A9AC @ =0x0000046B
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
_0810A996:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0810A99C: .4byte 0x000003AA
_0810A9A0: .4byte 0x0000046E
_0810A9A4: .4byte FUN_0810a054
_0810A9A8: .4byte 0x0000046D
_0810A9AC: .4byte 0x0000046B

	thumb_func_start FUN_0810a9b0
FUN_0810a9b0: @ 0x0810A9B0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _0810A9C8 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810A9CC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810A9CE
	.align 2, 0
_0810A9C8: .4byte 0x0000046D
_0810A9CC:
	movs r0, #0
_0810A9CE:
	cmp r0, #0
	beq _0810A9DA
	adds r0, r5, #0
	movs r1, #0x13
	bl FUN_080ef86c
_0810A9DA:
	cmp r4, #0x14
	ble _0810AA10
	ldr r1, _0810AA18 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810AA10
	ldr r4, _0810AA1C @ =FUN_0810aa28
	movs r3, #0x2c
	ldr r0, _0810AA20 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810AA24 @ =0x0000046B
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
_0810AA10:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0810AA18: .4byte 0x0000046E
_0810AA1C: .4byte FUN_0810aa28
_0810AA20: .4byte 0x0000046D
_0810AA24: .4byte 0x0000046B

	thumb_func_start FUN_0810aa28
FUN_0810aa28: @ 0x0810AA28
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x24
	adds r5, r0, #0
	mov sb, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r3, _0810AA50 @ =0x0000046D
	adds r1, r5, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810AA54
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810AA56
	.align 2, 0
_0810AA50: .4byte 0x0000046D
_0810AA54:
	movs r0, #0
_0810AA56:
	cmp r0, #0
	bne _0810AA5C
	b _0810ABC2
_0810AA5C:
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	ldrb r0, [r5, #5]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _0810AA76
	asrs r0, r1, #6
	b _0810AA7C
_0810AA76:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0810AA7C:
	lsls r0, r0, #0x1e
	lsrs r6, r0, #0x18
	add r3, sp, #0xc
	adds r4, r5, #0
	adds r4, #8
	ldr r0, _0810AAC0 @ =0x00000764
	adds r2, r2, r0
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
	mov r8, r0
	subs r1, r0, r6
	cmp r1, #0x80
	ble _0810AAC8
	ldr r3, _0810AAC4 @ =0xFFFFFF00
	adds r1, r1, r3
	b _0810AAD6
	.align 2, 0
_0810AAC0: .4byte 0x00000764
_0810AAC4: .4byte 0xFFFFFF00
_0810AAC8:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0810AAD6
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r1, r4
_0810AAD6:
	adds r7, r1, #0
	add r3, sp, #0x14
	movs r4, #0xa
	ldr r2, _0810AAFC @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	mov ip, r3
	cmp r0, #0
	blt _0810AB00
	asrs r1, r0, #0xc
	b _0810AB06
	.align 2, 0
_0810AAFC: .4byte 0x085B0A08
_0810AB00:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810AB06:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0810AB1E
	asrs r0, r0, #0xc
	b _0810AB24
_0810AB1E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810AB24:
	strh r0, [r3, #4]
	add r3, sp, #0x1c
	ldrh r0, [r3]
	mov r4, ip
	ldrh r4, [r4]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0810AB70 @ =0xFFFF0000
	ldr r2, [sp, #0x1c]
	ands r2, r4
	orrs r2, r0
	asrs r1, r2, #0x10
	movs r0, #0x82
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _0810AB74 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r1, sp, #0x14
	ldrh r0, [r3, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r3, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r3, #4]
	adds r1, r3, #0
	cmp r7, #0xc
	ble _0810AB78
	adds r0, r6, #0
	adds r0, #0xc
	lsls r0, r0, #0x18
	b _0810AB8C
	.align 2, 0
_0810AB70: .4byte 0xFFFF0000
_0810AB74: .4byte 0x0000FFFF
_0810AB78:
	movs r0, #0xc
	rsbs r0, r0, #0
	cmp r7, r0
	bge _0810AB88
	adds r0, r6, #0
	subs r0, #0xc
	lsls r0, r0, #0x18
	b _0810AB8C
_0810AB88:
	mov r2, r8
	lsls r0, r2, #0x18
_0810AB8C:
	lsrs r6, r0, #0x18
	movs r3, #0x8a
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r2, [r0]
	movs r4, #0x8c
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrh r3, [r0]
	adds r4, #0x14
	adds r0, r5, r4
	ldr r0, [r0]
	str r0, [sp]
	subs r4, #0xc
	adds r0, r5, r4
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r0, #0x2a
	str r0, [sp, #8]
	adds r0, r1, #0
	adds r1, r6, #0
	bl FUN_081f0098
	movs r0, #0xea
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0810ABC2:
	adds r0, r5, #0
	movs r1, #0x14
	bl FUN_080ef86c
	mov r0, sb
	cmp r0, #0x18
	ble _0810ABFA
	ldr r4, _0810AC08 @ =FUN_0810ac14
	movs r3, #0x2d
	ldr r2, _0810AC0C @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810AC10 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
_0810ABFA:
	add sp, #0x24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810AC08: .4byte FUN_0810ac14
_0810AC0C: .4byte 0x0000046D
_0810AC10: .4byte 0x0000046B

	thumb_func_start FUN_0810ac14
FUN_0810ac14: @ 0x0810AC14
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0810AC2C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810AC30
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810AC32
	.align 2, 0
_0810AC2C: .4byte 0x0000046D
_0810AC30:
	movs r0, #0
_0810AC32:
	cmp r0, #0
	beq _0810AC3E
	adds r0, r5, #0
	movs r1, #0x15
	bl FUN_080ef86c
_0810AC3E:
	ldr r1, _0810AC78 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810AC70
	ldr r4, _0810AC7C @ =FUN_0810a054
	movs r3, #0x3d
	ldr r0, _0810AC80 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810AC84 @ =0x0000046B
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
_0810AC70:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0810AC78: .4byte 0x0000046E
_0810AC7C: .4byte FUN_0810a054
_0810AC80: .4byte 0x0000046D
_0810AC84: .4byte 0x0000046B

	thumb_func_start FUN_0810ac88
FUN_0810ac88: @ 0x0810AC88
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r0, _0810ACB0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810ACB4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810ACB6
	.align 2, 0
_0810ACB0: .4byte 0x0000046D
_0810ACB4:
	movs r0, #0
_0810ACB6:
	cmp r0, #0
	beq _0810ACD6
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r5, #5]
	adds r0, r5, #0
	movs r1, #0x13
	bl FUN_080ef86c
_0810ACD6:
	cmp r6, #8
	bne _0810ACEA
	ldr r0, _0810AD34 @ =0x00000704
	adds r2, r7, r0
	ldr r0, _0810AD38 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
_0810ACEA:
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	bne _0810ACFC
	ldrh r0, [r4, #0x14]
	cmp r0, #0xc
	bne _0810ACFC
	ldr r0, _0810AD3C @ =0x000003B2
	bl PlaySound_082406e0
_0810ACFC:
	ldr r1, _0810AD40 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810AD2E
	ldr r4, _0810AD44 @ =FUN_0810ad50
	movs r3, #0x2f
	ldr r0, _0810AD48 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810AD4C @ =0x0000046B
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
_0810AD2E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810AD34: .4byte 0x00000704
_0810AD38: .4byte 0x03002BE0
_0810AD3C: .4byte 0x000003B2
_0810AD40: .4byte 0x0000046E
_0810AD44: .4byte FUN_0810ad50
_0810AD48: .4byte 0x0000046D
_0810AD4C: .4byte 0x0000046B

	thumb_func_start FUN_0810ad50
FUN_0810ad50: @ 0x0810AD50
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r7, r0, #0
	mov sl, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0810AD7C @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810AD80
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810AD82
	.align 2, 0
_0810AD7C: .4byte 0x0000046D
_0810AD80:
	movs r0, #0
_0810AD82:
	cmp r0, #0
	beq _0810ADBE
	ldr r1, _0810ADAC @ =0x0000070C
	add r1, r8
	movs r0, #0
	strb r0, [r1]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	ldr r5, _0810ADB0 @ =0x00000546
	adds r0, r7, r5
	ldrh r0, [r0]
	cmp r1, r0
	bgt _0810ADB4
	movs r1, #0xe2
	lsls r1, r1, #3
	add r1, r8
	movs r0, #0xa
	b _0810ADBC
	.align 2, 0
_0810ADAC: .4byte 0x0000070C
_0810ADB0: .4byte 0x00000546
_0810ADB4:
	movs r1, #0xe2
	lsls r1, r1, #3
	add r1, r8
	movs r0, #5
_0810ADBC:
	strb r0, [r1]
_0810ADBE:
	adds r0, r7, #0
	movs r1, #0x14
	bl FUN_080ef86c
	ldr r0, _0810AE34 @ =0x0000070D
	add r0, r8
	ldr r1, _0810AE38 @ =0x0000070C
	add r1, r8
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhi _0810ADD8
	b _0810AF30
_0810ADD8:
	mov r0, sl
	movs r1, #0xc
	bl Mod
	cmp r0, #0
	beq _0810ADE6
	b _0810AF30
_0810ADE6:
	ldrb r0, [r7, #5]
	adds r0, #0x20
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #6
	lsls r0, r0, #6
	adds r2, r0, #0
	adds r2, #0xe0
	ands r2, r3
	ldr r4, _0810AE3C @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0810AE40 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0810AE44 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r6, r2, r0
	ands r6, r3
	add r5, sp, #0x18
	ldr r1, _0810AE48 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #7
	mov ip, r4
	cmp r0, #0
	blt _0810AE4C
	asrs r2, r0, #0xc
	b _0810AE52
	.align 2, 0
_0810AE34: .4byte 0x0000070D
_0810AE38: .4byte 0x0000070C
_0810AE3C: .4byte 0x030046B8
_0810AE40: .4byte 0x000003FF
_0810AE44: .4byte 0x0203B400
_0810AE48: .4byte 0x085B0A08
_0810AE4C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0810AE52:
	movs r0, #0
	strh r2, [r5]
	strh r0, [r5, #2]
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x80
	muls r0, r1, r0
	cmp r0, #0
	blt _0810AE6C
	asrs r0, r0, #0xc
	b _0810AE72
_0810AE6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810AE72:
	strh r0, [r5, #4]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r1, sp, #0x18
	add r0, sp, #0x20
	ldrh r2, [r0]
	ldrh r1, [r1]
	adds r2, r2, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r5, _0810AF70 @ =0xFFFF0000
	ldr r1, [sp, #0x20]
	ands r1, r5
	orrs r1, r2
	str r1, [sp, #0x20]
	ldr r4, _0810AF74 @ =0x0203B400
	mov sb, r4
	mov r1, ip
	ldr r2, [r1]
	adds r2, #1
	ldr r4, _0810AF78 @ =0x000003FF
	ands r2, r4
	str r2, [r1]
	lsls r2, r2, #1
	add r2, sb
	ldr r3, [sp, #0x20]
	asrs r1, r3, #0x10
	adds r1, #0xdc
	ldrb r2, [r2]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	ldr r2, _0810AF7C @ =0x0000FFFF
	ands r2, r3
	orrs r2, r1
	str r2, [sp, #0x20]
	add r2, sp, #0x18
	ldrh r1, [r0, #4]
	ldrh r2, [r2, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, [r0, #4]
	ands r2, r5
	orrs r2, r1
	str r2, [r0, #4]
	mov r2, ip
	ldr r1, [r2]
	adds r1, #1
	ands r1, r4
	str r1, [r2]
	lsls r1, r1, #1
	add r1, sb
	ldrh r5, [r1]
	movs r2, #0xe2
	lsls r2, r2, #3
	add r2, r8
	movs r1, #0xf
	ands r5, r1
	ldrb r2, [r2]
	adds r2, r2, r5
	mov sb, r2
	ldr r1, _0810AF80 @ =0x03002BE0
	ldr r1, [r1]
	adds r1, #0x2c
	ldr r3, _0810AF84 @ =0x00000226
	adds r2, r7, r3
	ldrh r2, [r2]
	ldr r4, _0810AF88 @ =0x0000022E
	adds r3, r7, r4
	ldrh r3, [r3]
	movs r5, #0x90
	lsls r5, r5, #2
	adds r4, r7, r5
	ldr r4, [r4]
	str r4, [sp]
	subs r5, #0xa
	adds r4, r7, r5
	ldrh r4, [r4]
	str r4, [sp, #4]
	mov r4, sb
	str r4, [sp, #8]
	movs r4, #0x78
	str r4, [sp, #0xc]
	movs r4, #0xf0
	str r4, [sp, #0x10]
	str r6, [sp, #0x14]
	bl FUN_081f51ac
	ldr r1, _0810AF8C @ =0x0000070C
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0810AF30:
	mov r5, sl
	cmp r5, #0x78
	ble _0810AF60
	ldr r4, _0810AF90 @ =FUN_0810afa0
	movs r3, #0x30
	ldr r0, _0810AF94 @ =0x0000046D
	adds r1, r7, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810AF98 @ =0x0000046B
	adds r0, r7, r1
	strb r2, [r0]
	ldr r5, _0810AF9C @ =0x00000553
	adds r0, r7, r5
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r2, [r0]
_0810AF60:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810AF70: .4byte 0xFFFF0000
_0810AF74: .4byte 0x0203B400
_0810AF78: .4byte 0x000003FF
_0810AF7C: .4byte 0x0000FFFF
_0810AF80: .4byte 0x03002BE0
_0810AF84: .4byte 0x00000226
_0810AF88: .4byte 0x0000022E
_0810AF8C: .4byte 0x0000070C
_0810AF90: .4byte FUN_0810afa0
_0810AF94: .4byte 0x0000046D
_0810AF98: .4byte 0x0000046B
_0810AF9C: .4byte 0x00000553

	thumb_func_start FUN_0810afa0
FUN_0810afa0: @ 0x0810AFA0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0810AFC0 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810AFC4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810AFC6
	.align 2, 0
_0810AFC0: .4byte 0x0000046D
_0810AFC4:
	movs r0, #0
_0810AFC6:
	cmp r0, #0
	beq _0810AFD2
	adds r0, r5, #0
	movs r1, #0x15
	bl FUN_080ef86c
_0810AFD2:
	ldr r1, _0810B020 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810B01A
	ldr r4, _0810B024 @ =FUN_0810a054
	movs r3, #0x3d
	ldr r2, _0810B028 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810B02C @ =0x0000046B
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
	movs r1, #0
	strh r2, [r0]
	ldr r2, _0810B030 @ =0x0000070E
	adds r0, r6, r2
	strb r1, [r0]
	subs r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	ldr r0, _0810B034 @ =0x0000070F
	adds r1, r6, r0
	movs r0, #0x3c
	strb r0, [r1]
_0810B01A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0810B020: .4byte 0x0000046E
_0810B024: .4byte FUN_0810a054
_0810B028: .4byte 0x0000046D
_0810B02C: .4byte 0x0000046B
_0810B030: .4byte 0x0000070E
_0810B034: .4byte 0x0000070F

	thumb_func_start FUN_0810b038
FUN_0810b038: @ 0x0810B038
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	ldr r0, _0810B054 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810B058
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810B05A
	.align 2, 0
_0810B054: .4byte 0x0000046D
_0810B058:
	movs r0, #0
_0810B05A:
	cmp r0, #0
	beq _0810B0FC
	ldr r2, _0810B0A0 @ =0x00000482
	adds r1, r5, r2
	movs r0, #2
	strh r0, [r1]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r5, #5]
	adds r0, r5, #0
	movs r1, #0x13
	bl FUN_080ef86c
	ldr r1, _0810B0A4 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0810B0A8
	ldr r3, _0810B0A0 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0810B0B8
	.align 2, 0
_0810B0A0: .4byte 0x00000482
_0810B0A4: .4byte 0x0000A02F
_0810B0A8:
	ldr r1, _0810B0DC @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0810B0B8
	movs r0, #1
	strh r0, [r2]
_0810B0B8:
	ldr r3, _0810B0E0 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810B0E4
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
	b _0810B0FC
	.align 2, 0
_0810B0DC: .4byte 0x00000482
_0810B0E0: .4byte 0x0000025D
_0810B0E4:
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
_0810B0FC:
	ldrh r0, [r6, #0xc]
	cmp r0, #0
	bne _0810B10E
	ldrh r0, [r6, #0x14]
	cmp r0, #0xc
	bne _0810B10E
	ldr r0, _0810B150 @ =0x000003B2
	bl PlaySound_082406e0
_0810B10E:
	ldr r6, _0810B154 @ =0x0000046E
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810B148
	ldr r4, _0810B158 @ =FUN_0810b164
	movs r3, #0x3f
	ldr r1, _0810B15C @ =0x0000046D
	adds r0, r5, r1
	movs r1, #0
	movs r2, #1
	strb r2, [r0]
	subs r6, #3
	adds r0, r5, r6
	strb r1, [r0]
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
	strh r1, [r0]
	ldr r1, _0810B160 @ =0x00000482
	adds r0, r5, r1
	strh r2, [r0]
_0810B148:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0810B150: .4byte 0x000003B2
_0810B154: .4byte 0x0000046E
_0810B158: .4byte FUN_0810b164
_0810B15C: .4byte 0x0000046D
_0810B160: .4byte 0x00000482

	thumb_func_start FUN_0810b164
FUN_0810b164: @ 0x0810B164
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x3c
	adds r5, r0, #0
	mov r8, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0810B18C @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810B190
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810B192
	.align 2, 0
_0810B18C: .4byte 0x0000046D
_0810B190:
	movs r0, #0
_0810B192:
	cmp r0, #0
	beq _0810B1EE
	ldr r3, _0810B1C8 @ =0x0000070C
	adds r1, r6, r3
	movs r0, #0
	strb r0, [r1]
	movs r4, #0xc2
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _0810B1CC @ =0x00000546
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r1, r0
	bgt _0810B1D8
	ldr r4, _0810B1D0 @ =0x0000070D
	adds r1, r6, r4
	movs r0, #3
	strb r0, [r1]
	movs r0, #0x3c
	movs r1, #4
	bl Div
	ldr r2, _0810B1D4 @ =0x00000712
	adds r1, r6, r2
	b _0810B1EC
	.align 2, 0
_0810B1C8: .4byte 0x0000070C
_0810B1CC: .4byte 0x00000546
_0810B1D0: .4byte 0x0000070D
_0810B1D4: .4byte 0x00000712
_0810B1D8:
	ldr r3, _0810B248 @ =0x0000070D
	adds r1, r6, r3
	movs r0, #2
	strb r0, [r1]
	movs r0, #0x50
	movs r1, #3
	bl Div
	ldr r4, _0810B24C @ =0x00000712
	adds r1, r6, r4
_0810B1EC:
	strh r0, [r1]
_0810B1EE:
	adds r0, r5, #0
	movs r1, #0x14
	bl FUN_080ef86c
	ldr r1, _0810B250 @ =0x0000070C
	adds r0, r6, r1
	ldr r2, _0810B248 @ =0x0000070D
	adds r1, r6, r2
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	blo _0810B208
	b _0810B338
_0810B208:
	ldr r3, _0810B24C @ =0x00000712
	adds r0, r6, r3
	ldrh r1, [r0]
	mov r0, r8
	bl Mod
	cmp r0, #0
	beq _0810B21A
	b _0810B338
_0810B21A:
	ldrb r3, [r5, #5]
	adds r0, r3, #0
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r7, r0, #6
	add r4, sp, #0x24
	ldr r2, _0810B254 @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	mov ip, r3
	cmp r0, #0
	blt _0810B258
	asrs r1, r0, #0xc
	b _0810B25E
	.align 2, 0
_0810B248: .4byte 0x0000070D
_0810B24C: .4byte 0x00000712
_0810B250: .4byte 0x0000070C
_0810B254: .4byte 0x085B0A08
_0810B258:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810B25E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r7, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _0810B27A
	asrs r0, r0, #0xc
	b _0810B280
_0810B27A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810B280:
	strh r0, [r4, #4]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp, #0x2c]
	str r1, [sp, #0x30]
	add r1, sp, #0x24
	add r3, sp, #0x2c
	ldrh r0, [r3]
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0810B374 @ =0xFFFF0000
	ldr r2, [sp, #0x2c]
	ands r2, r4
	orrs r2, r0
	asrs r1, r2, #0x10
	movs r0, #0x96
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _0810B378 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x2c]
	add r1, sp, #0x24
	ldrh r0, [r3, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r3, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r3, #4]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	mov r2, ip
	subs r1, r0, r2
	adds r2, r3, #0
	cmp r1, #0x80
	bgt _0810B2DC
	movs r0, #0x80
	rsbs r0, r0, #0
_0810B2DC:
	ldr r0, _0810B37C @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #0x34]
	str r1, [sp, #0x38]
	add r1, sp, #0x34
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r3, [r0]
	movs r0, #0x5a
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	movs r0, #0x14
	str r0, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	movs r0, #0x19
	str r0, [sp, #0x10]
	ldr r4, _0810B380 @ =0x00000226
	adds r0, r5, r4
	ldrh r0, [r0]
	str r0, [sp, #0x14]
	adds r4, #8
	adds r0, r5, r4
	ldrh r0, [r0]
	str r0, [sp, #0x18]
	adds r4, #0x12
	adds r0, r5, r4
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	subs r4, #0xa
	adds r0, r5, r4
	ldrh r0, [r0]
	str r0, [sp, #0x20]
	adds r0, r2, #0
	movs r2, #2
	bl FUN_081f86b4
	ldr r0, _0810B384 @ =0x0000070C
	adds r1, r6, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0810B338:
	mov r1, r8
	cmp r1, #0x50
	ble _0810B368
	ldr r4, _0810B388 @ =FUN_0810b394
	movs r3, #0x40
	ldr r2, _0810B38C @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810B390 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
_0810B368:
	add sp, #0x3c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810B374: .4byte 0xFFFF0000
_0810B378: .4byte 0x0000FFFF
_0810B37C: .4byte 0x03002BE0
_0810B380: .4byte 0x00000226
_0810B384: .4byte 0x0000070C
_0810B388: .4byte FUN_0810b394
_0810B38C: .4byte 0x0000046D
_0810B390: .4byte 0x0000046B

	thumb_func_start FUN_0810b394
FUN_0810b394: @ 0x0810B394
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0810B3B4 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810B3B8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810B3BA
	.align 2, 0
_0810B3B4: .4byte 0x0000046D
_0810B3B8:
	movs r0, #0
_0810B3BA:
	cmp r0, #0
	beq _0810B3C6
	adds r0, r5, #0
	movs r1, #0x15
	bl FUN_080ef86c
_0810B3C6:
	ldr r1, _0810B414 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810B40E
	ldr r4, _0810B418 @ =FUN_0810a054
	movs r3, #0x3d
	ldr r2, _0810B41C @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810B420 @ =0x0000046B
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
	movs r1, #0
	strh r2, [r0]
	ldr r2, _0810B424 @ =0x0000070E
	adds r0, r6, r2
	strb r1, [r0]
	subs r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	ldr r0, _0810B428 @ =0x0000070F
	adds r1, r6, r0
	movs r0, #0x3c
	strb r0, [r1]
_0810B40E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0810B414: .4byte 0x0000046E
_0810B418: .4byte FUN_0810a054
_0810B41C: .4byte 0x0000046D
_0810B420: .4byte 0x0000046B
_0810B424: .4byte 0x0000070E
_0810B428: .4byte 0x0000070F

	thumb_func_start FUN_0810b42c
FUN_0810b42c: @ 0x0810B42C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r0, _0810B448 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810B44C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810B44E
	.align 2, 0
_0810B448: .4byte 0x0000046D
_0810B44C:
	movs r0, #0
_0810B44E:
	cmp r0, #0
	beq _0810B46E
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r5, #5]
	adds r0, r5, #0
	movs r1, #0x13
	bl FUN_080ef86c
_0810B46E:
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	bne _0810B480
	ldrh r0, [r4, #0x14]
	cmp r0, #0xc
	bne _0810B480
	ldr r0, _0810B4B8 @ =0x000003B2
	bl PlaySound_082406e0
_0810B480:
	ldr r1, _0810B4BC @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810B4B2
	ldr r4, _0810B4C0 @ =FUN_0810b4cc
	movs r3, #0x42
	ldr r0, _0810B4C4 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810B4C8 @ =0x0000046B
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
_0810B4B2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0810B4B8: .4byte 0x000003B2
_0810B4BC: .4byte 0x0000046E
_0810B4C0: .4byte FUN_0810b4cc
_0810B4C4: .4byte 0x0000046D
_0810B4C8: .4byte 0x0000046B

	thumb_func_start FUN_0810b4cc
FUN_0810b4cc: @ 0x0810B4CC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _0810B4E4 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810B4E8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810B4EA
	.align 2, 0
_0810B4E4: .4byte 0x0000046D
_0810B4E8:
	movs r0, #0
_0810B4EA:
	cmp r0, #0
	beq _0810B542
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _0810B50C @ =0x00000546
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r1, r0
	bgt _0810B510
	adds r0, r4, #0
	bl FUN_08108284
	b _0810B542
	.align 2, 0
_0810B50C: .4byte 0x00000546
_0810B510:
	ldr r2, _0810B530 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0810B534 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0810B538 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x3f
	bgt _0810B53C
	adds r0, r4, #0
	bl FUN_08108454
	b _0810B542
	.align 2, 0
_0810B530: .4byte 0x030046B8
_0810B534: .4byte 0x000003FF
_0810B538: .4byte 0x0203B400
_0810B53C:
	adds r0, r4, #0
	bl FUN_081080b4
_0810B542:
	adds r0, r4, #0
	movs r1, #0x14
	bl FUN_080ef86c
	bl FUN_081f95f4
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0810B57E
	ldr r3, _0810B584 @ =FUN_0810b590
	movs r2, #0x43
	ldr r0, _0810B588 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810B58C @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r4, r2
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
_0810B57E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0810B584: .4byte FUN_0810b590
_0810B588: .4byte 0x0000046D
_0810B58C: .4byte 0x0000046B

	thumb_func_start FUN_0810b590
FUN_0810b590: @ 0x0810B590
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0810B5B0 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810B5B4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810B5B6
	.align 2, 0
_0810B5B0: .4byte 0x0000046D
_0810B5B4:
	movs r0, #0
_0810B5B6:
	cmp r0, #0
	beq _0810B5C2
	adds r0, r5, #0
	movs r1, #0x15
	bl FUN_080ef86c
_0810B5C2:
	ldr r1, _0810B610 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810B60A
	ldr r4, _0810B614 @ =FUN_0810a054
	movs r3, #0x3d
	ldr r2, _0810B618 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810B61C @ =0x0000046B
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
	movs r1, #0
	strh r2, [r0]
	ldr r2, _0810B620 @ =0x0000070E
	adds r0, r6, r2
	strb r1, [r0]
	subs r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	ldr r0, _0810B624 @ =0x0000070F
	adds r1, r6, r0
	movs r0, #0x3c
	strb r0, [r1]
_0810B60A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0810B610: .4byte 0x0000046E
_0810B614: .4byte FUN_0810a054
_0810B618: .4byte 0x0000046D
_0810B61C: .4byte 0x0000046B
_0810B620: .4byte 0x0000070E
_0810B624: .4byte 0x0000070F

	thumb_func_start FUN_0810b628
FUN_0810b628: @ 0x0810B628
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r0, _0810B644 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810B648
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810B64A
	.align 2, 0
_0810B644: .4byte 0x0000046D
_0810B648:
	movs r0, #0
_0810B64A:
	cmp r0, #0
	beq _0810B66A
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r5, #5]
	adds r0, r5, #0
	movs r1, #0x13
	bl FUN_080ef86c
_0810B66A:
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	bne _0810B67C
	ldrh r0, [r4, #0x14]
	cmp r0, #0xc
	bne _0810B67C
	ldr r0, _0810B6B4 @ =0x000003B2
	bl PlaySound_082406e0
_0810B67C:
	ldr r1, _0810B6B8 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810B6AE
	ldr r4, _0810B6BC @ =FUN_0810b6c8
	movs r3, #0x45
	ldr r0, _0810B6C0 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810B6C4 @ =0x0000046B
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
_0810B6AE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0810B6B4: .4byte 0x000003B2
_0810B6B8: .4byte 0x0000046E
_0810B6BC: .4byte FUN_0810b6c8
_0810B6C0: .4byte 0x0000046D
_0810B6C4: .4byte 0x0000046B

	thumb_func_start FUN_0810b6c8
FUN_0810b6c8: @ 0x0810B6C8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _0810B6E0 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810B6E4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810B6E6
	.align 2, 0
_0810B6E0: .4byte 0x0000046D
_0810B6E4:
	movs r0, #0
_0810B6E6:
	cmp r0, #0
	beq _0810B6F0
	adds r0, r4, #0
	bl FUN_08106378
_0810B6F0:
	adds r0, r4, #0
	movs r1, #0x14
	bl FUN_080ef86c
	movs r0, #0x1f
	bl FUN_080ecf60
	adds r5, r0, #0
	cmp r5, #0
	bne _0810B72A
	ldr r3, _0810B730 @ =FUN_0810b73c
	movs r2, #0x46
	ldr r0, _0810B734 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810B738 @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
_0810B72A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0810B730: .4byte FUN_0810b73c
_0810B734: .4byte 0x0000046D
_0810B738: .4byte 0x0000046B

	thumb_func_start FUN_0810b73c
FUN_0810b73c: @ 0x0810B73C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0810B75C @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810B760
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810B762
	.align 2, 0
_0810B75C: .4byte 0x0000046D
_0810B760:
	movs r0, #0
_0810B762:
	cmp r0, #0
	beq _0810B76E
	adds r0, r5, #0
	movs r1, #0x15
	bl FUN_080ef86c
_0810B76E:
	ldr r1, _0810B7BC @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810B7B6
	ldr r4, _0810B7C0 @ =FUN_0810a054
	movs r3, #0x3d
	ldr r2, _0810B7C4 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810B7C8 @ =0x0000046B
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
	movs r1, #0
	strh r2, [r0]
	ldr r2, _0810B7CC @ =0x0000070E
	adds r0, r6, r2
	strb r1, [r0]
	subs r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	ldr r0, _0810B7D0 @ =0x0000070F
	adds r1, r6, r0
	movs r0, #0x3c
	strb r0, [r1]
_0810B7B6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0810B7BC: .4byte 0x0000046E
_0810B7C0: .4byte FUN_0810a054
_0810B7C4: .4byte 0x0000046D
_0810B7C8: .4byte 0x0000046B
_0810B7CC: .4byte 0x0000070E
_0810B7D0: .4byte 0x0000070F

	thumb_func_start FUN_0810b7d4
FUN_0810b7d4: @ 0x0810B7D4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r0, _0810B7F0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810B7F4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810B7F6
	.align 2, 0
_0810B7F0: .4byte 0x0000046D
_0810B7F4:
	movs r0, #0
_0810B7F6:
	cmp r0, #0
	beq _0810B816
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r5, #5]
	adds r0, r5, #0
	movs r1, #0x13
	bl FUN_080ef86c
_0810B816:
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	bne _0810B828
	ldrh r0, [r4, #0x14]
	cmp r0, #0xc
	bne _0810B828
	ldr r0, _0810B860 @ =0x000003B2
	bl PlaySound_082406e0
_0810B828:
	ldr r1, _0810B864 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810B85A
	ldr r4, _0810B868 @ =FUN_0810b874
	movs r3, #0x32
	ldr r0, _0810B86C @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810B870 @ =0x0000046B
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
_0810B85A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0810B860: .4byte 0x000003B2
_0810B864: .4byte 0x0000046E
_0810B868: .4byte FUN_0810b874
_0810B86C: .4byte 0x0000046D
_0810B870: .4byte 0x0000046B

	thumb_func_start FUN_0810b874
FUN_0810b874: @ 0x0810B874
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	adds r5, r0, #0
	adds r7, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0810B8D0 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810B892
	movs r0, #0
	strb r0, [r1]
_0810B892:
	adds r0, r5, #0
	movs r1, #0x14
	bl FUN_080ef86c
	adds r0, r7, #0
	movs r1, #0xf
	bl Mod
	cmp r0, #0
	bne _0810B994
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp, #0x24]
	str r1, [sp, #0x28]
	ldr r2, [sp, #0x24]
	asrs r1, r2, #0x10
	adds r1, #0xdc
	lsls r1, r1, #0x10
	ldr r0, _0810B8D4 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x24]
	ldrb r0, [r5, #5]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _0810B8D8
	asrs r0, r1, #6
	b _0810B8DE
	.align 2, 0
_0810B8D0: .4byte 0x0000046D
_0810B8D4: .4byte 0x0000FFFF
_0810B8D8:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0810B8DE:
	add r4, sp, #0x1c
	lsls r3, r0, #6
	ldr r2, _0810B900 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	cmp r0, #0
	blt _0810B904
	asrs r1, r0, #0xc
	b _0810B90A
	.align 2, 0
_0810B900: .4byte 0x085B0A08
_0810B904:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810B90A:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	muls r0, r1, r0
	cmp r0, #0
	blt _0810B928
	asrs r0, r0, #0xc
	b _0810B92E
_0810B928:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810B92E:
	strh r0, [r4, #4]
	add r0, sp, #0x24
	add r3, sp, #0x1c
	adds r2, r3, #0
	ldrh r1, [r0]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r0]
	ldrh r1, [r3, #2]
	ldrh r2, [r0, #2]
	adds r1, r1, r2
	strh r1, [r0, #2]
	ldrh r1, [r0, #4]
	ldrh r3, [r3, #4]
	adds r1, r1, r3
	strh r1, [r0, #4]
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r1, [r1]
	adds r1, #8
	adds r3, #0x50
	adds r2, r5, r3
	ldrh r2, [r2]
	str r2, [sp]
	adds r3, #8
	adds r2, r5, r3
	ldrh r2, [r2]
	str r2, [sp, #4]
	adds r3, #0x14
	adds r2, r5, r3
	ldr r2, [r2]
	str r2, [sp, #8]
	subs r3, #0xc
	adds r2, r5, r3
	ldrh r2, [r2]
	str r2, [sp, #0xc]
	movs r2, #0x14
	str r2, [sp, #0x10]
	ldr r3, _0810B9CC @ =0x0000071C
	adds r2, r6, r3
	ldrh r2, [r2]
	str r2, [sp, #0x14]
	adds r3, #2
	adds r2, r6, r3
	ldrh r2, [r2]
	str r2, [sp, #0x18]
	movs r2, #6
	movs r3, #6
	bl FUN_081f42cc
_0810B994:
	cmp r7, #0x28
	ble _0810B9C2
	ldr r4, _0810B9D0 @ =FUN_0810b9dc
	movs r3, #0x33
	ldr r0, _0810B9D4 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810B9D8 @ =0x0000046B
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
_0810B9C2:
	add sp, #0x2c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810B9CC: .4byte 0x0000071C
_0810B9D0: .4byte FUN_0810b9dc
_0810B9D4: .4byte 0x0000046D
_0810B9D8: .4byte 0x0000046B

	thumb_func_start FUN_0810b9dc
FUN_0810b9dc: @ 0x0810B9DC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0810B9F4 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810B9F8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810B9FA
	.align 2, 0
_0810B9F4: .4byte 0x0000046D
_0810B9F8:
	movs r0, #0
_0810B9FA:
	cmp r0, #0
	beq _0810BA06
	adds r0, r5, #0
	movs r1, #0x15
	bl FUN_080ef86c
_0810BA06:
	ldr r1, _0810BA40 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810BA38
	ldr r4, _0810BA44 @ =FUN_0810a054
	movs r3, #0x3d
	ldr r0, _0810BA48 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810BA4C @ =0x0000046B
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
_0810BA38:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0810BA40: .4byte 0x0000046E
_0810BA44: .4byte FUN_0810a054
_0810BA48: .4byte 0x0000046D
_0810BA4C: .4byte 0x0000046B

	thumb_func_start FUN_0810ba50
FUN_0810ba50: @ 0x0810BA50
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r0, _0810BA6C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810BA70
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810BA72
	.align 2, 0
_0810BA6C: .4byte 0x0000046D
_0810BA70:
	movs r0, #0
_0810BA72:
	cmp r0, #0
	beq _0810BA7E
	adds r0, r5, #0
	movs r1, #5
	bl FUN_080ef86c
_0810BA7E:
	ldrh r0, [r4, #0x14]
	cmp r0, #3
	bne _0810BA90
	ldrh r0, [r4, #0xc]
	cmp r0, #0
	bne _0810BA90
	adds r0, r5, #0
	bl FUN_08106498
_0810BA90:
	ldr r1, _0810BAC8 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810BAC2
	ldr r4, _0810BACC @ =FUN_0810a054
	movs r3, #0x3d
	ldr r0, _0810BAD0 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810BAD4 @ =0x0000046B
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
_0810BAC2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0810BAC8: .4byte 0x0000046E
_0810BACC: .4byte FUN_0810a054
_0810BAD0: .4byte 0x0000046D
_0810BAD4: .4byte 0x0000046B

	thumb_func_start FUN_0810bad8
FUN_0810bad8: @ 0x0810BAD8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov r8, r5
	adds r3, r5, #0
	adds r3, #0x9c
	ldr r0, _0810BAFC @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810BB00
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810BB02
	.align 2, 0
_0810BAFC: .4byte 0x0000046D
_0810BB00:
	movs r0, #0
_0810BB02:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r1, r1, r5
	mov sb, r1
	cmp r0, #0
	bne _0810BB10
	b _0810BFB6
_0810BB10:
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
	adds r2, r0, #1
	ands r2, r1
	ldr r4, _0810BB60 @ =0x0000046A
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #6
	beq _0810BB64
	cmp r0, #0x14
	beq _0810BB64
	movs r1, #0x89
	lsls r1, r1, #7
	mov r6, sb
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	bne _0810BB64
	ldr r0, [r3, #8]
	ldrh r0, [r0, #4]
	lsrs r1, r0, #0xc
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	b _0810BB6C
	.align 2, 0
_0810BB60: .4byte 0x0000046A
_0810BB64:
	movs r4, #0xee
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrb r1, [r0]
_0810BB6C:
	asrs r0, r1, #1
	cmp r2, r0
	bne _0810BBE8
	ldr r6, _0810BBD8 @ =0x0000046B
	adds r0, r5, r6
	movs r4, #0
	movs r3, #1
	strb r3, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0810BB8C
	b _0810C198
_0810BB8C:
	movs r1, #3
	subs r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0810BBDC @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	ldr r2, _0810BBE0 @ =0x0000046A
	adds r0, r5, r2
	strb r4, [r0]
	adds r6, #0x1c
	adds r0, r5, r6
	str r4, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r3, [r0]
	ldr r2, _0810BBE4 @ =0x000005BC
	adds r0, r5, r2
	ldr r2, [r0]
	movs r1, #0x1b
	subs r6, #0x17
	adds r0, r5, r6
	strb r3, [r0]
	ldr r3, _0810BBD8 @ =0x0000046B
	adds r0, r5, r3
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	b _0810C198
	.align 2, 0
_0810BBD8: .4byte 0x0000046B
_0810BBDC: .4byte 0x00000469
_0810BBE0: .4byte 0x0000046A
_0810BBE4: .4byte 0x000005BC
_0810BBE8:
	cmp r2, #1
	bne _0810BBEE
	b _0810BCEC
_0810BBEE:
	cmp r2, #1
	bgt _0810BBF8
	cmp r2, #0
	beq _0810BC06
	b _0810BFB6
_0810BBF8:
	cmp r2, #2
	bne _0810BBFE
	b _0810BDB8
_0810BBFE:
	cmp r2, #3
	bne _0810BC04
	b _0810BE84
_0810BC04:
	b _0810BFB6
_0810BC06:
	subs r0, r1, #2
	cmp r0, #3
	bhi _0810BC80
	movs r3, #0x99
	lsls r3, r3, #3
	adds r0, r5, r3
	ldrb r2, [r0]
	ldr r4, _0810BC34 @ =0x0000025D
	adds r0, r5, r4
	ldrb r3, [r0]
	cmp r3, #0
	bne _0810BC3C
	ldr r6, _0810BC38 @ =0x000004B7
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #1
	b _0810BEAC
	.align 2, 0
_0810BC34: .4byte 0x0000025D
_0810BC38: .4byte 0x000004B7
_0810BC3C:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	adds r2, #1
	ldr r1, _0810BC78 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0810BC7C @ =0x0000046E
	adds r6, r5, r0
	cmp r1, r2
	bne _0810BC66
	ldrb r0, [r6]
	cmp r0, #0
	bne _0810BC66
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0810BC66
	b _0810BF0A
_0810BC66:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	b _0810BEF4
	.align 2, 0
_0810BC78: .4byte 0x000004B7
_0810BC7C: .4byte 0x0000046E
_0810BC80:
	movs r4, #0x99
	lsls r4, r4, #3
	adds r0, r5, r4
	ldrb r2, [r0]
	ldr r6, _0810BCAC @ =0x0000025D
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810BCB4
	ldr r1, _0810BCB0 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r3, #4
	str r3, [sp]
	movs r3, #0
	bl FUN_08236fac
	b _0810BCD8
	.align 2, 0
_0810BCAC: .4byte 0x0000025D
_0810BCB0: .4byte 0x000004B7
_0810BCB4:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldr r3, _0810BCE4 @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	movs r3, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
_0810BCC6:
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_0810BCD8:
	ldr r4, _0810BCE8 @ =0x0000046E
	adds r1, r5, r4
	movs r0, #0
	strb r0, [r1]
	b _0810BFA8
	.align 2, 0
_0810BCE4: .4byte 0x000004B7
_0810BCE8: .4byte 0x0000046E
_0810BCEC:
	subs r0, r1, #4
	cmp r0, #3
	bhi _0810BD64
	movs r1, #0x99
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, _0810BD18 @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _0810BD20
	ldr r4, _0810BD1C @ =0x000004B7
	adds r0, r5, r4
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #2
	b _0810BEAC
	.align 2, 0
_0810BD18: .4byte 0x0000025D
_0810BD1C: .4byte 0x000004B7
_0810BD20:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	adds r2, #2
	ldr r1, _0810BD5C @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0810BD60 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, r2
	bne _0810BD4A
	ldrb r0, [r6]
	cmp r0, #0
	bne _0810BD4A
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0810BD4A
	b _0810BF0A
_0810BD4A:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	b _0810BEF4
	.align 2, 0
_0810BD5C: .4byte 0x000004B7
_0810BD60: .4byte 0x0000046E
_0810BD64:
	movs r4, #0x99
	lsls r4, r4, #3
	adds r0, r5, r4
	ldrb r2, [r0]
	ldr r6, _0810BD90 @ =0x0000025D
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810BD98
	ldr r1, _0810BD94 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r3, #4
	str r3, [sp]
	movs r3, #1
	bl FUN_08236fac
	b _0810BCD8
	.align 2, 0
_0810BD90: .4byte 0x0000025D
_0810BD94: .4byte 0x000004B7
_0810BD98:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	adds r2, #1
	ldr r3, _0810BDB4 @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	movs r3, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	b _0810BCC6
	.align 2, 0
_0810BDB4: .4byte 0x000004B7
_0810BDB8:
	subs r0, r1, #1
	cmp r0, #4
	bls _0810BE30
	movs r1, #0x99
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, _0810BDEC @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810BDF4
	ldr r4, _0810BDF0 @ =0x000004B7
	adds r0, r5, r4
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r3, #5
	str r3, [sp]
	movs r3, #1
	bl FUN_08236fac
	b _0810BE1C
	.align 2, 0
_0810BDEC: .4byte 0x0000025D
_0810BDF0: .4byte 0x000004B7
_0810BDF4:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	adds r2, #1
	ldr r6, _0810BE28 @ =0x000004B7
	adds r0, r5, r6
	strb r2, [r0]
	movs r3, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #4
	orrs r0, r1
	str r0, [r4, #8]
_0810BE1C:
	ldr r0, _0810BE2C @ =0x0000046E
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	b _0810BF0A
	.align 2, 0
_0810BE28: .4byte 0x000004B7
_0810BE2C: .4byte 0x0000046E
_0810BE30:
	movs r4, #0x99
	lsls r4, r4, #3
	adds r0, r5, r4
	ldrb r2, [r0]
	ldr r6, _0810BE5C @ =0x0000025D
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810BE64
	ldr r1, _0810BE60 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r3, #4
	str r3, [sp]
	movs r3, #2
	bl FUN_08236fac
	b _0810BCD8
	.align 2, 0
_0810BE5C: .4byte 0x0000025D
_0810BE60: .4byte 0x000004B7
_0810BE64:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	adds r2, #2
	ldr r3, _0810BE80 @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	movs r3, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	b _0810BCC6
	.align 2, 0
_0810BE80: .4byte 0x000004B7
_0810BE84:
	cmp r1, #3
	bhi _0810BF24
	movs r1, #0x99
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, _0810BEB8 @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _0810BEC4
	ldr r4, _0810BEBC @ =0x000004B7
	adds r0, r5, r4
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #0
_0810BEAC:
	bl FUN_08236fac
	ldr r0, _0810BEC0 @ =0x0000046E
	adds r6, r5, r0
	b _0810BF06
	.align 2, 0
_0810BEB8: .4byte 0x0000025D
_0810BEBC: .4byte 0x000004B7
_0810BEC0: .4byte 0x0000046E
_0810BEC4:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r1, _0810BF1C @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0810BF20 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, r2
	bne _0810BEEA
	ldrb r0, [r6]
	cmp r0, #0
	bne _0810BEEA
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0810BF0A
_0810BEEA:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
_0810BEF4:
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_0810BF06:
	movs r0, #0
	strb r0, [r6]
_0810BF0A:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _0810BFB6
	.align 2, 0
_0810BF1C: .4byte 0x000004B7
_0810BF20: .4byte 0x0000046E
_0810BF24:
	movs r4, #0x99
	lsls r4, r4, #3
	adds r0, r5, r4
	ldrb r2, [r0]
	ldr r6, _0810BF54 @ =0x0000025D
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810BF60
	ldr r1, _0810BF58 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r3, #1
	str r3, [sp]
	bl FUN_08236fac
	ldr r2, _0810BF5C @ =0x0000046E
	adds r6, r5, r2
	b _0810BFA4
	.align 2, 0
_0810BF54: .4byte 0x0000025D
_0810BF58: .4byte 0x000004B7
_0810BF5C: .4byte 0x0000046E
_0810BF60:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	adds r2, #1
	ldr r3, _0810BFF8 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r4, _0810BFFC @ =0x0000046E
	adds r6, r5, r4
	cmp r1, r2
	bne _0810BF88
	ldrb r0, [r6]
	cmp r0, #0
	bne _0810BF88
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0810BFA8
_0810BF88:
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
	str r0, [r7, #8]
_0810BFA4:
	movs r0, #0
	strb r0, [r6]
_0810BFA8:
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r2, r5, r6
	ldr r1, _0810C000 @ =0xFFFEFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_0810BFB6:
	ldr r0, [r5, #0x44]
	adds r1, r0, #0
	adds r1, #0x20
	ldrh r0, [r1, #0xc]
	cmp r0, #0
	bne _0810C028
	ldrh r0, [r1, #0x14]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0810C028
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
	bge _0810BFEC
	rsbs r0, r0, #0
_0810BFEC:
	cmp r0, #0x20
	bgt _0810C004
	mov r4, r8
	strb r1, [r4, #5]
	b _0810C028
	.align 2, 0
_0810BFF8: .4byte 0x000004B7
_0810BFFC: .4byte 0x0000046E
_0810C000: .4byte 0xFFFEFFFF
_0810C004:
	movs r1, #0x80
	lsls r1, r1, #9
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0810C020
	adds r0, r2, #0
	adds r0, #0x20
	mov r1, r8
	strb r0, [r1, #5]
	b _0810C028
_0810C020:
	adds r0, r2, #0
	subs r0, #0x20
	mov r2, r8
	strb r0, [r2, #5]
_0810C028:
	ldr r1, _0810C040 @ =0x0000A02F
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0810C048
	ldr r4, _0810C044 @ =0x00000482
	adds r1, r5, r4
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0810C058
	.align 2, 0
_0810C040: .4byte 0x0000A02F
_0810C044: .4byte 0x00000482
_0810C048:
	ldr r6, _0810C07C @ =0x00000482
	adds r0, r5, r6
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0810C058
	movs r0, #1
	strh r0, [r2]
_0810C058:
	ldr r1, _0810C080 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810C084
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
	b _0810C09C
	.align 2, 0
_0810C07C: .4byte 0x00000482
_0810C080: .4byte 0x0000025D
_0810C084:
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
_0810C09C:
	ldr r2, _0810C150 @ =0x0000046E
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810C198
	ldrb r0, [r5, #5]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r2, #8
	rsbs r2, r2, #0
	ldr r3, _0810C154 @ =0x0000046B
	adds r4, r5, r3
	movs r7, #0
	movs r6, #1
	strb r6, [r4]
	adds r1, #0xdd
	adds r3, r5, r1
	ldrb r1, [r3]
	orrs r0, r2
	subs r1, r1, r0
	movs r0, #7
	ands r1, r0
	cmp r1, #4
	ble _0810C0D6
	movs r0, #8
	subs r1, r0, r1
_0810C0D6:
	adds r0, r1, #0
	cmp r0, #0
	bge _0810C0DE
	rsbs r0, r0, #0
_0810C0DE:
	cmp r0, #0
	bne _0810C16C
	strb r6, [r4]
	ldrb r0, [r3]
	adds r0, #5
	lsls r0, r0, #5
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
	beq _0810C198
	movs r1, #3
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _0810C158 @ =0x00000469
	adds r0, r5, r4
	strb r6, [r0]
	ldr r1, _0810C15C @ =0x0000046A
	adds r0, r5, r1
	strb r7, [r0]
	ldr r2, _0810C160 @ =0x00000484
	adds r0, r5, r2
	str r7, [r0]
	adds r3, #4
	adds r0, r5, r3
	strb r6, [r0]
	ldr r4, _0810C164 @ =0x000005BC
	adds r0, r5, r4
	ldr r2, [r0]
	movs r1, #0x1b
	adds r3, #1
	adds r0, r5, r3
	strb r6, [r0]
	ldr r4, _0810C154 @ =0x0000046B
	adds r0, r5, r4
	strb r7, [r0]
	ldr r6, _0810C168 @ =0x00000553
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	b _0810C196
	.align 2, 0
_0810C150: .4byte 0x0000046E
_0810C154: .4byte 0x0000046B
_0810C158: .4byte 0x00000469
_0810C15C: .4byte 0x0000046A
_0810C160: .4byte 0x00000484
_0810C164: .4byte 0x000005BC
_0810C168: .4byte 0x00000553
_0810C16C:
	movs r3, #0xb2
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r2, [r0]
	movs r1, #2
	ldr r4, _0810C1A8 @ =0x0000046D
	adds r0, r5, r4
	strb r6, [r0]
	ldr r6, _0810C1AC @ =0x0000046B
	adds r0, r5, r6
	strb r7, [r0]
	subs r3, #0x3d
	adds r0, r5, r3
	strb r1, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r2, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
_0810C196:
	strh r7, [r0]
_0810C198:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810C1A8: .4byte 0x0000046D
_0810C1AC: .4byte 0x0000046B

	thumb_func_start FUN_0810c1b0
FUN_0810c1b0: @ 0x0810C1B0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _0810C1C8 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810C1CC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810C1CE
	.align 2, 0
_0810C1C8: .4byte 0x0000046D
_0810C1CC:
	movs r0, #0
_0810C1CE:
	cmp r0, #0
	beq _0810C1F0
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
	bne _0810C1F0
	movs r0, #1
	orrs r0, r1
	strh r0, [r2]
_0810C1F0:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Mod
	cmp r0, #0
	bne _0810C20C
	ldr r2, _0810C258 @ =0x000001DF
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	bl FUN_080e5718
_0810C20C:
	ldr r1, _0810C25C @ =0x00000466
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _0810C252
	movs r1, #0x80
	lsls r1, r1, #5
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r4, [r0]
	ands r4, r1
	cmp r4, #0
	bne _0810C252
	ldr r3, _0810C260 @ =FUN_0810c26c
	movs r2, #6
	ldr r0, _0810C264 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810C268 @ =0x0000046B
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
_0810C252:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0810C258: .4byte 0x000001DF
_0810C25C: .4byte 0x00000466
_0810C260: .4byte FUN_0810c26c
_0810C264: .4byte 0x0000046D
_0810C268: .4byte 0x0000046B

	thumb_func_start FUN_0810c26c
FUN_0810c26c: @ 0x0810C26C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _0810C284 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810C288
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810C28A
	.align 2, 0
_0810C284: .4byte 0x0000046D
_0810C288:
	movs r0, #0
_0810C28A:
	cmp r0, #0
	beq _0810C2A6
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
_0810C2A6:
	cmp r5, #0x28
	bne _0810C2B8
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0810C2B8:
	ldr r1, _0810C2D4 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810C2CE
	cmp r5, #0x78
	ble _0810C2CE
	ldr r0, _0810C2D8 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0810C2CE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0810C2D4: .4byte 0x0000046E
_0810C2D8: .4byte 0x0000046B

	thumb_func_start FUN_0810c2dc
FUN_0810c2dc: @ 0x0810C2DC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r3, [r0]
	ldr r2, _0810C2FC @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810C300
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810C302
	.align 2, 0
_0810C2FC: .4byte 0x0000046D
_0810C300:
	movs r0, #0
_0810C302:
	adds r2, r0, #0
	cmp r2, #0
	beq _0810C3F0
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r2, r3, r0
	ldrh r0, [r2, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r2, r3, r0
	ldrh r0, [r2, #6]
	orrs r0, r1
	strh r0, [r2, #6]
	adds r2, r4, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	orrs r0, r1
	strh r0, [r2, #6]
	movs r0, #0x94
	lsls r0, r0, #1
	adds r2, r4, r0
	mvns r1, r1
	ldrh r0, [r2, #6]
	ands r1, r0
	strh r1, [r2, #6]
	ldrb r3, [r4, #5]
	ldr r2, _0810C37C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0810C380 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0810C384 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xf
	ands r1, r0
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r5, r4, r0
	adds r6, r3, #0
	adds r7, r1, #0
	adds r7, #0x1c
	ldr r3, _0810C388 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0810C38C
	asrs r1, r0, #0xc
	b _0810C392
	.align 2, 0
_0810C37C: .4byte 0x030046B8
_0810C380: .4byte 0x000003FF
_0810C384: .4byte 0x0203B400
_0810C388: .4byte 0x085B0A08
_0810C38C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810C392:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r6, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0810C3AA
	asrs r0, r0, #0xc
	b _0810C3B0
_0810C3AA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810C3B0:
	strh r0, [r5, #4]
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0810C3E8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0810C3EC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x18
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0x11
	bl FUN_080ef86c
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08013698
	b _0810C458
	.align 2, 0
_0810C3E8: .4byte 0x000003FF
_0810C3EC: .4byte 0x0203B400
_0810C3F0:
	ldr r0, [r4, #0x18]
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0810C40A
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r2, [r0]
	adds r1, #4
	adds r0, r4, r1
	strh r2, [r0]
_0810C40A:
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0810C458
	movs r1, #0x80
	lsls r1, r1, #4
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r3, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0810C430
	movs r0, #1
	b _0810C432
_0810C430:
	movs r0, #0
_0810C432:
	cmp r0, #0
	beq _0810C43C
	ldr r0, _0810C460 @ =0x000003AD
	bl PlaySound_082406e0
_0810C43C:
	movs r0, #0x94
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r1, #1
	mov r0, sp
	strh r1, [r0]
	adds r0, r4, #0
	mov r1, sp
	bl FUN_080e59d0
_0810C458:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810C460: .4byte 0x000003AD

	thumb_func_start FUN_0810c464
FUN_0810c464: @ 0x0810C464
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r3, [r0]
	ldr r2, _0810C488 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810C48C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810C48E
	.align 2, 0
_0810C488: .4byte 0x0000046D
_0810C48C:
	movs r0, #0
_0810C48E:
	cmp r0, #0
	beq _0810C4D6
	movs r0, #0x94
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r0, [r2, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r2, r4, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	orrs r0, r1
	strh r0, [r2, #6]
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r2, r3, r0
	ldrh r0, [r2, #6]
	orrs r0, r1
	strh r0, [r2, #6]
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r2, r3, r0
	ldrh r0, [r2, #6]
	orrs r1, r0
	strh r1, [r2, #6]
	adds r0, r4, #0
	movs r1, #0x11
	bl FUN_080ef86c
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_080136b4
	b _0810C510
_0810C4D6:
	movs r1, #2
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r3, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0810C4EA
	movs r0, #1
	b _0810C4EC
_0810C4EA:
	movs r0, #0
_0810C4EC:
	cmp r0, #0
	bne _0810C510
	ldr r0, _0810C518 @ =0x00000726
	adds r2, r3, r0
	ldrh r1, [r2]
	ldr r0, _0810C51C @ =0x00004E1F
	cmp r1, r0
	bhi _0810C510
	adds r0, r1, #0
	cmp r0, r5
	bge _0810C510
	movs r1, #1
	mov r0, sp
	strh r1, [r0]
	adds r0, r4, #0
	mov r1, sp
	bl FUN_080e59d0
_0810C510:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0810C518: .4byte 0x00000726
_0810C51C: .4byte 0x00004E1F

	thumb_func_start FUN_0810c520
FUN_0810c520: @ 0x0810C520
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _0810C538 @ =0x0000046D
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _0810C53C
	movs r0, #0
	strb r0, [r2]
	movs r0, #1
	b _0810C53E
	.align 2, 0
_0810C538: .4byte 0x0000046D
_0810C53C:
	movs r0, #0
_0810C53E:
	adds r5, r0, #0
	cmp r5, #0
	bne _0810C54C
	cmp r1, #0x1e
	beq _0810C54C
	cmp r1, #0x37
	bne _0810C556
_0810C54C:
	adds r0, r4, #0
	movs r1, #0x12
	bl FUN_080ef86c
	b _0810C580
_0810C556:
	cmp r1, #0x5f
	ble _0810C580
	ldr r3, _0810C588 @ =FUN_0810c594
	movs r2, #0xd
	ldr r0, _0810C58C @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810C590 @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
_0810C580:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0810C588: .4byte FUN_0810c594
_0810C58C: .4byte 0x0000046D
_0810C590: .4byte 0x0000046B

	thumb_func_start FUN_0810c594
FUN_0810c594: @ 0x0810C594
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r4, [r0]
	ldr r2, _0810C5BC @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810C5C0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810C5C2
	.align 2, 0
_0810C5BC: .4byte 0x0000046D
_0810C5C0:
	movs r0, #0
_0810C5C2:
	cmp r0, #0
	beq _0810C5DE
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r0, r7, r3
	bl FUN_08013698
	adds r0, r7, #0
	movs r1, #0xd
	bl FUN_080ef86c
	ldr r0, _0810C85C @ =0x000003AE
	bl PlaySound_082406e0
_0810C5DE:
	ldr r1, _0810C860 @ =0x0000046E
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810C5EA
	b _0810C84A
_0810C5EA:
	adds r3, r7, #0
	adds r3, #0xde
	ldrh r2, [r3]
	ldr r1, _0810C864 @ =0x0000FFFB
	adds r0, r1, #0
	ands r0, r2
	movs r2, #0
	mov sb, r2
	movs r6, #0
	strh r0, [r3]
	movs r0, #0x97
	lsls r0, r0, #1
	adds r3, r7, r0
	ldrh r2, [r3]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	ldr r2, _0810C868 @ =0x0000065E
	adds r3, r4, r2
	ldrh r2, [r3]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	ldr r3, _0810C86C @ =0x000006AE
	adds r2, r4, r3
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r5, r7, r0
	ldr r4, _0810C870 @ =0xFFFFF7FF
	ldrh r0, [r5]
	ands r4, r0
	strh r4, [r5]
	ldrb r1, [r7, #5]
	str r1, [sp]
	movs r2, #0x80
	lsls r2, r2, #7
	ands r4, r2
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	rsbs r4, r4, #0
	asrs r4, r4, #0x1f
	ands r4, r2
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r2, _0810C874 @ =0x0000055C
	adds r0, r7, r2
	ldr r0, [r0]
	str r0, [r1]
	adds r3, #4
	adds r1, r7, r3
	adds r2, #4
	adds r0, r7, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r3, _0810C878 @ =0x00000564
	adds r0, r7, r3
	ldrb r0, [r0]
	strb r0, [r7, #5]
	ldr r1, _0810C87C @ =0x00000565
	adds r0, r7, r1
	ldrb r0, [r0]
	subs r2, #0xf8
	adds r2, r7, r2
	str r2, [sp, #4]
	strb r0, [r2]
	adds r3, #2
	adds r0, r7, r3
	ldrb r0, [r0]
	subs r1, #0xfc
	adds r1, r7, r1
	str r1, [sp, #8]
	strb r0, [r1]
	ldr r2, _0810C880 @ =0x00000567
	adds r0, r7, r2
	ldrb r0, [r0]
	subs r3, #0xfc
	adds r3, r7, r3
	str r3, [sp, #0xc]
	strb r0, [r3]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x10]
	movs r1, #0xad
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r2, [sp, #0x10]
	str r0, [r2]
	ldr r3, _0810C884 @ =0x0000056C
	adds r0, r7, r3
	ldrb r0, [r0]
	subs r1, #0x15
	adds r1, r7, r1
	str r1, [sp, #0x14]
	strb r0, [r1]
	ldr r2, _0810C888 @ =0x00000572
	adds r0, r7, r2
	ldrh r1, [r0]
	subs r3, #0xf8
	adds r0, r7, r3
	strh r1, [r0]
	movs r1, #0xae
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r0, [r0]
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	movs r3, #0x95
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrh r1, [r0]
	subs r2, #0x3a
	adds r0, r7, r2
	strh r1, [r0]
	subs r3, #0xd2
	adds r0, r7, r3
	strh r6, [r0]
	ldr r1, _0810C88C @ =0x00000222
	adds r0, r7, r1
	strh r6, [r0]
	strh r6, [r5]
	ldr r2, _0810C890 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x18]
	mov r3, sb
	strb r3, [r2]
	ldr r0, _0810C894 @ =0x0000046C
	adds r0, r0, r7
	mov sl, r0
	movs r1, #1
	strb r1, [r0]
	ldr r2, _0810C898 @ =0x0000046D
	adds r2, r2, r7
	mov r8, r2
	strb r1, [r2]
	ldr r3, _0810C860 @ =0x0000046E
	adds r0, r7, r3
	mov r2, sb
	strb r2, [r0]
	ldr r3, _0810C89C @ =0x0000024E
	adds r0, r7, r3
	strh r6, [r0]
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r6, [r0]
	ldr r3, _0810C8A0 @ =0x00000544
	adds r0, r7, r3
	strh r6, [r0]
	ldr r2, _0810C8A4 @ =0x00000466
	adds r0, r7, r2
	strh r6, [r0]
	movs r3, #0xea
	lsls r3, r3, #1
	adds r0, r7, r3
	str r6, [r0]
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	str r6, [r0]
	adds r3, #9
	adds r0, r7, r3
	mov r2, sb
	strb r2, [r0]
	adds r3, #0x3f
	adds r0, r7, r3
	strb r2, [r0]
	ldr r2, _0810C8A8 @ =0x00000482
	adds r0, r7, r2
	strh r1, [r0]
	movs r3, #0x93
	lsls r3, r3, #3
	adds r0, r7, r3
	str r6, [r0]
	ldr r1, _0810C8AC @ =0x0000049C
	adds r0, r7, r1
	str r6, [r0]
	adds r2, #0x1e
	adds r0, r7, r2
	str r6, [r0]
	subs r3, #0xc
	adds r0, r7, r3
	mov r1, sb
	strb r1, [r0]
	adds r2, #0x1e
	adds r0, r7, r2
	strh r6, [r0]
	adds r3, #1
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _0810C8B0 @ =0x0000048E
	adds r0, r7, r1
	mov r2, sb
	strb r2, [r0]
	subs r3, #0x35
	adds r0, r7, r3
	movs r1, #8
	bl ClearMemory
	ldr r1, _0810C8B4 @ =0x00000464
	adds r0, r7, r1
	strh r6, [r0]
	movs r2, #0x8c
	lsls r2, r2, #3
	adds r0, r7, r2
	strh r6, [r0]
	ldr r3, _0810C8B8 @ =0x00000462
	adds r0, r7, r3
	strh r6, [r0]
	ldr r1, _0810C8BC @ =0x08251FCC
	adds r0, r7, #0
	ldr r2, _0810C8C0 @ =0x00000982
	bl FUN_080e6768
	movs r1, #0xa8
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r2, sb
	strb r2, [r0]
	ldr r3, _0810C8C4 @ =0x00000541
	adds r0, r7, r3
	strb r2, [r0]
	ldr r0, _0810C8C8 @ =0x00000542
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r0, r7, r1
	str r6, [r0]
	ldr r2, _0810C8CC @ =0x0000054C
	adds r0, r7, r2
	mov r3, sb
	strb r3, [r0]
	adds r1, #5
	adds r0, r7, r1
	strb r3, [r0]
	adds r2, #2
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _0810C8D0 @ =0x0000054F
	adds r0, r7, r3
	mov r1, sb
	strb r1, [r0]
	adds r0, r7, #0
	bl FUN_080eeee0
	ldrh r0, [r5]
	orrs r4, r0
	strh r4, [r5]
	mov r2, sp
	ldrb r2, [r2]
	strb r2, [r7, #5]
	adds r0, r7, #0
	bl FUN_0810342c
	ldrh r0, [r5]
	movs r3, #0x80
	lsls r3, r3, #7
	ands r0, r3
	cmp r0, #0
	beq _0810C84A
	movs r0, #2
	ldr r1, [sp, #4]
	strb r0, [r1]
	mov r3, sb
	ldr r2, [sp, #8]
	strb r3, [r2]
	ldr r1, [sp, #0xc]
	strb r0, [r1]
	ldr r2, _0810C8D4 @ =0x00000484
	adds r0, r7, r2
	str r6, [r0]
	movs r0, #1
	mov r3, sl
	strb r0, [r3]
	ldr r1, _0810C8D8 @ =FUN_080e48d0
	movs r0, #0x10
	movs r3, #1
	mov r2, r8
	strb r3, [r2]
	mov r3, sb
	ldr r2, [sp, #0x18]
	strb r3, [r2]
	ldr r2, [sp, #0x14]
	strb r0, [r2]
	ldr r3, [sp, #0x10]
	str r1, [r3]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r6, [r0]
	adds r0, r7, #0
	adds r0, #0x48
	movs r1, #1
	bl FUN_08022488
_0810C84A:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810C85C: .4byte 0x000003AE
_0810C860: .4byte 0x0000046E
_0810C864: .4byte 0x0000FFFB
_0810C868: .4byte 0x0000065E
_0810C86C: .4byte 0x000006AE
_0810C870: .4byte 0xFFFFF7FF
_0810C874: .4byte 0x0000055C
_0810C878: .4byte 0x00000564
_0810C87C: .4byte 0x00000565
_0810C880: .4byte 0x00000567
_0810C884: .4byte 0x0000056C
_0810C888: .4byte 0x00000572
_0810C88C: .4byte 0x00000222
_0810C890: .4byte 0x0000046B
_0810C894: .4byte 0x0000046C
_0810C898: .4byte 0x0000046D
_0810C89C: .4byte 0x0000024E
_0810C8A0: .4byte 0x00000544
_0810C8A4: .4byte 0x00000466
_0810C8A8: .4byte 0x00000482
_0810C8AC: .4byte 0x0000049C
_0810C8B0: .4byte 0x0000048E
_0810C8B4: .4byte 0x00000464
_0810C8B8: .4byte 0x00000462
_0810C8BC: .4byte 0x08251FCC
_0810C8C0: .4byte 0x00000982
_0810C8C4: .4byte 0x00000541
_0810C8C8: .4byte 0x00000542
_0810C8CC: .4byte 0x0000054C
_0810C8D0: .4byte 0x0000054F
_0810C8D4: .4byte 0x00000484
_0810C8D8: .4byte FUN_080e48d0

	thumb_func_start FUN_0810c8dc
FUN_0810c8dc: @ 0x0810C8DC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r3, [r0]
	ldr r2, _0810C8FC @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810C900
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810C902
	.align 2, 0
_0810C8FC: .4byte 0x0000046D
_0810C900:
	movs r0, #0
_0810C902:
	cmp r0, #0
	beq _0810C950
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0810C934
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xe6
	lsls r0, r0, #3
	adds r1, r3, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _0810C92E
	movs r0, #1
	b _0810C930
_0810C92E:
	movs r0, #0
_0810C930:
	cmp r0, #0
	beq _0810C93E
_0810C934:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	b _0810C950
_0810C93E:
	adds r0, r4, #0
	movs r1, #0xc
	bl FUN_080ef86c
	movs r0, #0x80
	lsls r0, r0, #6
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_0810C950:
	cmp r6, #0x3c
	bgt _0810C956
	b _0810CA84
_0810C956:
	ldr r1, _0810C9EC @ =0x0000046B
	adds r0, r4, r1
	movs r6, #0
	movs r7, #1
	strb r7, [r0]
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _0810CA04
	ldr r3, _0810C9F0 @ =0x000004A4
	adds r0, r4, r3
	ldr r0, [r0]
	movs r2, #0x1c
	ldrsh r1, [r0, r2]
	movs r3, #0x20
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	bl FUN_080e6304
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r2, [r0]
	movs r1, #0x1a
	ldr r3, _0810C9F4 @ =0x0000046D
	adds r0, r4, r3
	strb r7, [r0]
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
	ldr r1, _0810C9F8 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _0810C9FC @ =0x00000484
	adds r0, r4, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r7, [r0]
	movs r0, #4
	ldr r1, _0810CA00 @ =0x00000222
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _0810CA7C
	.align 2, 0
_0810C9EC: .4byte 0x0000046B
_0810C9F0: .4byte 0x000004A4
_0810C9F4: .4byte 0x0000046D
_0810C9F8: .4byte 0x0000046A
_0810C9FC: .4byte 0x00000484
_0810CA00: .4byte 0x00000222
_0810CA04:
	ldr r3, _0810CA8C @ =0x000004A4
	adds r0, r4, r3
	ldr r0, [r0]
	movs r2, #0x1c
	ldrsh r1, [r0, r2]
	movs r3, #0x20
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	bl FUN_080e6304
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _0810CA90 @ =0x0000046D
	adds r0, r4, r2
	strb r7, [r0]
	ldr r3, _0810CA94 @ =0x0000046B
	adds r0, r4, r3
	strb r5, [r0]
	adds r2, #0xe6
	adds r0, r4, r2
	strb r7, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r4, r3
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	strh r5, [r0]
	movs r2, #7
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _0810CA98 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _0810CA9C @ =0x00000484
	adds r0, r4, r2
	str r5, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r7, [r0]
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0810CA7C:
	ldr r2, _0810CAA0 @ =0x00000482
	adds r1, r4, r2
	movs r0, #2
	strh r0, [r1]
_0810CA84:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810CA8C: .4byte 0x000004A4
_0810CA90: .4byte 0x0000046D
_0810CA94: .4byte 0x0000046B
_0810CA98: .4byte 0x0000046A
_0810CA9C: .4byte 0x00000484
_0810CAA0: .4byte 0x00000482

	thumb_func_start FUN_0810caa4
FUN_0810caa4: @ 0x0810CAA4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc0
	adds r7, r0, #0
	ldr r0, _0810CAC4 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810CAC8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810CACA
	.align 2, 0
_0810CAC4: .4byte 0x0000046D
_0810CAC8:
	movs r0, #0
_0810CACA:
	cmp r0, #0
	beq _0810CAD6
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_0810CAD6:
	movs r1, #0x80
	lsls r1, r1, #6
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r3, r7, r2
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r2, #0x80
	lsls r2, r2, #9
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x83
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r0, #0x85
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r4, #0
	ldrsh r0, [r1, r4]
	subs r0, r2, r0
	adds r5, r1, #0
	cmp r0, #0
	blt _0810CB16
	asrs r0, r0, #2
	b _0810CB1C
_0810CB16:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0810CB1C:
	adds r4, r0, #0
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
	blt _0810CB3A
	asrs r0, r0, #2
	b _0810CB40
_0810CB3A:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0810CB40:
	adds r2, r0, #0
	cmp r4, #0xc8
	ble _0810CB4A
	movs r4, #0xc8
	b _0810CB54
_0810CB4A:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r4, r0
	bge _0810CB54
	adds r4, r0, #0
_0810CB54:
	cmp r2, #0xc8
	ble _0810CB5C
	movs r2, #0xc8
	b _0810CB66
_0810CB5C:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0810CB66
	adds r2, r0, #0
_0810CB66:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r4
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r5]
	adds r0, r0, r4
	strh r0, [r5]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r4, #0
	bne _0810CB8A
	cmp r2, #0
	bne _0810CB8A
	movs r0, #1
	b _0810CB8C
_0810CB8A:
	movs r0, #0
_0810CB8C:
	cmp r0, #0
	bne _0810CB94
	bl _0810DA40
_0810CB94:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	ldr r2, _0810CBE8 @ =0x0000046B
	adds r1, r7, r2
	movs r0, #1
	strb r0, [r1]
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldr r0, _0810CBEC @ =0xFFFFFEDF
	ldrh r1, [r2]
	ands r0, r1
	movs r6, #0
	strh r0, [r2]
	adds r5, r3, #0
	movs r0, #0x81
	rsbs r0, r0, #0
	ldr r4, [r5]
	ands r4, r0
	str r4, [r5]
	ldr r1, _0810CBF0 @ =0x0000049C
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xc
	ands r0, r1
	str r2, [sp, #0xa4]
	cmp r0, #0
	beq _0810CBF4
	movs r0, #2
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	bl _0810DA40
	.align 2, 0
_0810CBE8: .4byte 0x0000046B
_0810CBEC: .4byte 0xFFFFFEDF
_0810CBF0: .4byte 0x0000049C
_0810CBF4:
	movs r1, #0x80
	ldr r2, [sp, #0xa4]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	bne _0810CC06
	b _0810D318
_0810CC06:
	orrs r4, r1
	str r4, [r5]
	movs r0, #4
	ldr r4, _0810CC68 @ =0x00000222
	adds r3, r7, r4
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, _0810CC6C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
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
	str r3, [sp, #0xb0]
	str r4, [sp, #0xa8]
	str r2, [sp, #0x80]
	cmp r5, #0
	blt _0810CC62
	cmp r1, #0
	blt _0810CC62
	ldr r0, _0810CC70 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0810CC62
	ldr r0, _0810CC74 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810CC78
_0810CC62:
	movs r4, #0
	b _0810CC86
	.align 2, 0
_0810CC68: .4byte 0x00000222
_0810CC6C: .4byte 0x03002BE0
_0810CC70: .4byte 0x030046A8
_0810CC74: .4byte 0x030046AC
_0810CC78:
	ldr r0, _0810CC98 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0810CC86:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0810CC9C
	adds r0, #4
	b _0810CCA8
	.align 2, 0
_0810CC98: .4byte 0x030046A4
_0810CC9C:
	ldr r0, _0810CCBC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810CCA8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0810CCC0
	cmp r2, #2
	beq _0810CCC4
	b _0810CCC8
	.align 2, 0
_0810CCBC: .4byte 0x030046A4
_0810CCC0:
	ldrb r0, [r6, #4]
	b _0810CCC6
_0810CCC4:
	ldrb r0, [r6]
_0810CCC6:
	subs r1, r1, r0
_0810CCC8:
	strh r1, [r6, #2]
	ldr r0, _0810CCDC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0810CCE0
	movs r0, #1
	b _0810CCE2
	.align 2, 0
_0810CCDC: .4byte 0x030047A4
_0810CCE0:
	movs r0, #0
_0810CCE2:
	cmp r0, #0
	beq _0810CD20
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0810CD02
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0810CCFE
	adds r2, r0, #0
_0810CCFE:
	cmp r2, #0
	bge _0810CD0C
_0810CD02:
	ldr r2, _0810CD08 @ =0x000005C4
	adds r0, r7, r2
	b _0810D228
	.align 2, 0
_0810CD08: .4byte 0x000005C4
_0810CD0C:
	ldr r1, _0810CD1C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0810CD68
	.align 2, 0
_0810CD1C: .4byte 0x03002BE0
_0810CD20:
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
	blt _0810CD4C
	cmp r1, #0
	blt _0810CD4C
	ldr r0, _0810CD50 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810CD4C
	ldr r0, _0810CD54 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810CD58
_0810CD4C:
	movs r5, #0
	b _0810CD66
	.align 2, 0
_0810CD50: .4byte 0x030046A8
_0810CD54: .4byte 0x030046AC
_0810CD58:
	ldr r0, _0810CDA0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0810CD66:
	movs r2, #0
_0810CD68:
	ldr r4, _0810CDA4 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0810CD88
	ldr r1, _0810CDA8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0810CD88
	b _0810D168
_0810CD88:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0xa4]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r0, #0
	beq _0810CDAC
	movs r0, #0
	b _0810D23E
	.align 2, 0
_0810CDA0: .4byte 0x030046A4
_0810CDA4: .4byte 0x00000256
_0810CDA8: .4byte 0x03002BE0
_0810CDAC:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r6, [sp, #0xb0]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	movs r1, #0x80
	ldr r2, [sp, #0xa4]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _0810CE58
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r4, _0810CE48 @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0x14]
	movs r5, #1
	strb r5, [r4]
	ldr r6, _0810CE4C @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x18]
	movs r2, #0
	strb r2, [r6]
	subs r3, #0x65
	adds r3, r7, r3
	str r3, [sp, #0x1c]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	str r1, [r4]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	mov r0, sb
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r2, [r4]
	ldr r2, _0810CE50 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _0810CE54 @ =0x00000484
	adds r1, r7, r6
	mov r0, sb
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x98]
	ldr r6, [sp, #0x18]
	str r6, [sp, #0x90]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0x74]
	mov r6, r8
	str r6, [sp, #0x78]
	str r5, [sp, #0xac]
	str r4, [sp, #0x84]
	str r3, [sp, #0x88]
	str r2, [sp, #0x8c]
	str r1, [sp, #0xa0]
	str r0, [sp, #0x94]
	b _0810D026
	.align 2, 0
_0810CE48: .4byte 0x0000046D
_0810CE4C: .4byte 0x0000046B
_0810CE50: .4byte 0x00000469
_0810CE54: .4byte 0x00000484
_0810CE58:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, _0810CF18 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x20]
	strb r0, [r3]
	ldr r4, _0810CF1C @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x24]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _0810CF20 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x28]
	strb r0, [r6]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x2c]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x30]
	strh r2, [r4]
	movs r1, #5
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x34]
	movs r6, #0
	strb r6, [r5]
	ldr r3, _0810CF24 @ =0x00000469
	adds r5, r7, r3
	strb r6, [r5]
	ldr r6, _0810CF28 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _0810CF2C @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xa8]
	ldr r0, [r0]
	str r0, [sp, #0x38]
	ldr r1, [sp, #0x80]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x38]
	strh r1, [r6]
	ldr r6, [sp, #0x80]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x38]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x98]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0x90]
	ldr r0, [sp, #0x28]
	str r0, [sp, #0x74]
	ldr r6, [sp, #0x2c]
	str r6, [sp, #0x78]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0xac]
	ldr r6, [sp, #0x34]
	str r6, [sp, #0x84]
	str r5, [sp, #0x88]
	str r4, [sp, #0x8c]
	str r3, [sp, #0xa0]
	str r2, [sp, #0x94]
	mov r0, ip
	cmp r0, #0
	blt _0810CF14
	cmp r1, #0
	blt _0810CF14
	ldr r0, _0810CF30 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _0810CF14
	ldr r0, _0810CF34 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810CF38
_0810CF14:
	movs r4, #0
	b _0810CF48
	.align 2, 0
_0810CF18: .4byte 0x0000046D
_0810CF1C: .4byte 0x0000046B
_0810CF20: .4byte 0x00000553
_0810CF24: .4byte 0x00000469
_0810CF28: .4byte 0x0000046A
_0810CF2C: .4byte 0x00000484
_0810CF30: .4byte 0x030046A8
_0810CF34: .4byte 0x030046AC
_0810CF38:
	ldr r0, _0810CF58 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_0810CF48:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0810CF5C
	adds r0, #4
	b _0810CF68
	.align 2, 0
_0810CF58: .4byte 0x030046A4
_0810CF5C:
	ldr r0, _0810CF7C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810CF68:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0810CF80
	cmp r2, #2
	beq _0810CF86
	b _0810CF8C
	.align 2, 0
_0810CF7C: .4byte 0x030046A4
_0810CF80:
	ldr r2, [sp, #0x38]
	ldrb r0, [r2, #4]
	b _0810CF8A
_0810CF86:
	ldr r3, [sp, #0x38]
	ldrb r0, [r3]
_0810CF8A:
	subs r1, r1, r0
_0810CF8C:
	ldr r4, [sp, #0x38]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xa8]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0810CFB8
	cmp r1, #0
	blt _0810CFB8
	ldr r0, _0810CFBC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810CFB8
	ldr r0, _0810CFC0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810CFC4
_0810CFB8:
	movs r4, #0
	b _0810CFD2
	.align 2, 0
_0810CFBC: .4byte 0x030046A8
_0810CFC0: .4byte 0x030046AC
_0810CFC4:
	ldr r0, _0810CFE8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0810CFD2:
	ldr r6, [sp, #0xa8]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0810CFEC
	adds r0, #4
	b _0810CFF8
	.align 2, 0
_0810CFE8: .4byte 0x030046A4
_0810CFEC:
	ldr r0, _0810D00C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810CFF8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0810D010
	cmp r3, #2
	beq _0810D014
	b _0810D018
	.align 2, 0
_0810D00C: .4byte 0x030046A4
_0810D010:
	ldrb r0, [r5, #4]
	b _0810D016
_0810D014:
	ldrb r0, [r5]
_0810D016:
	subs r2, r2, r0
_0810D018:
	ldr r1, [sp, #0xa8]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xa8]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0810D026:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x3c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xa4]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _0810D050 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x9c]
	cmp r0, #0
	bne _0810D130
	movs r1, #4
	ldr r6, [sp, #0xb0]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0810D054
	movs r0, #1
	b _0810D056
	.align 2, 0
_0810D050: .4byte 0x00000482
_0810D054:
	movs r0, #0
_0810D056:
	ldr r1, _0810D140 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x9c]
	cmp r0, #0
	bne _0810D130
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xbc]
	ldr r0, _0810D144 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _0810D148 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _0810D14C @ =0x0000054E
	adds r6, r6, r7
	mov ip, r6
	ldr r0, _0810D150 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xb4]
	ldr r1, _0810D154 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0x7c]
	ldr r2, _0810D158 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xb8]
	ldr r1, _0810D15C @ =0x030046B8
	adds r2, r4, #0
_0810D09E:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _0810D160 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _0810D164 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _0810D0C2
	adds r3, #1
	cmp r3, #3
	ble _0810D09E
	adds r0, r4, #0
_0810D0C2:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0x78]
	ldr r0, [r1]
	ldr r2, [sp, #0xbc]
	str r0, [r2]
	ldr r4, [sp, #0x74]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x84]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x88]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x8c]
	ldrb r0, [r5]
	mov r6, ip
	strb r0, [r6]
	add r0, sp, #0x3c
	ldrb r1, [r0]
	ldr r0, [sp, #0xb4]
	strb r1, [r0]
	ldr r1, [sp, #0x7c]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x98]
	strb r1, [r4]
	ldr r5, [sp, #0x90]
	strb r3, [r5]
	ldr r6, [sp, #0x74]
	strb r0, [r6]
	ldr r0, [sp, #0x78]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xac]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x84]
	strb r0, [r5]
	ldr r6, [sp, #0x88]
	strb r1, [r6]
	ldr r0, [sp, #0x8c]
	strb r2, [r0]
	ldr r2, [sp, #0xa0]
	str r3, [r2]
	ldr r3, [sp, #0x94]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xb8]
	strb r0, [r4]
_0810D130:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x9c]
	strh r0, [r5]
	movs r0, #0
	b _0810D23E
	.align 2, 0
_0810D140: .4byte 0x00000482
_0810D144: .4byte 0x0000054F
_0810D148: .4byte 0x0000054C
_0810D14C: .4byte 0x0000054E
_0810D150: .4byte 0x00000541
_0810D154: .4byte 0x000005BC
_0810D158: .4byte 0x00000542
_0810D15C: .4byte 0x030046B8
_0810D160: .4byte 0x000003FF
_0810D164: .4byte 0x0203B400
_0810D168:
	mov sb, sp
	ldr r6, _0810D1A4 @ =0x030046A4
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
	beq _0810D1A8
	adds r0, #4
	b _0810D1B2
	.align 2, 0
_0810D1A4: .4byte 0x030046A4
_0810D1A8:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0810D1B2:
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
	ldr r6, _0810D1EC @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _0810D1F4
	ldr r0, _0810D1F0 @ =0xFFFFFDFF
	ldr r2, [sp, #0xa4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0810D21E
	.align 2, 0
_0810D1EC: .4byte 0x000004A4
_0810D1F0: .4byte 0xFFFFFDFF
_0810D1F4:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _0810D214
	cmp r0, #2
	beq _0810D210
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0810D210:
	movs r0, #1
	b _0810D220
_0810D214:
	ldr r0, _0810D234 @ =0xFFFFFDFF
	ldr r3, [sp, #0xa4]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0810D21E:
	movs r0, #0
_0810D220:
	cmp r0, #0
	bne _0810D23C
	ldr r4, _0810D238 @ =0x000005C4
	adds r0, r7, r4
_0810D228:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0810D23E
	.align 2, 0
_0810D234: .4byte 0xFFFFFDFF
_0810D238: .4byte 0x000005C4
_0810D23C:
	movs r0, #1
_0810D23E:
	cmp r0, #0
	bne _0810D2AE
	ldr r5, _0810D274 @ =0x000004A4
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
	bne _0810D27C
	ldr r0, _0810D278 @ =0xFFFFFDFF
	ldr r2, [sp, #0xa4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0810D2A6
	.align 2, 0
_0810D274: .4byte 0x000004A4
_0810D278: .4byte 0xFFFFFDFF
_0810D27C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0810D29C
	cmp r0, #2
	beq _0810D298
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0810D298:
	movs r0, #1
	b _0810D2A8
_0810D29C:
	ldr r0, _0810D304 @ =0xFFFFFDFF
	ldr r3, [sp, #0xa4]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0810D2A6:
	movs r0, #0
_0810D2A8:
	cmp r0, #0
	bne _0810D2AE
	b _0810D9D0
_0810D2AE:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _0810D308 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _0810D30C @ =0x0000046B
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
	ldr r1, _0810D310 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _0810D314 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	b _0810DA40
	.align 2, 0
_0810D304: .4byte 0xFFFFFDFF
_0810D308: .4byte 0x0000046D
_0810D30C: .4byte 0x0000046B
_0810D310: .4byte 0x0000046A
_0810D314: .4byte 0x00000484
_0810D318:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, _0810D374 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r0, #0x10
	orrs r4, r0
	str r4, [r3]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	strh r2, [r0, #6]
	adds r3, r7, r1
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
	str r3, [sp, #0xa8]
	str r2, [sp, #0x80]
	cmp r5, #0
	blt _0810D36E
	cmp r1, #0
	blt _0810D36E
	ldr r0, _0810D378 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0810D36E
	ldr r0, _0810D37C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810D380
_0810D36E:
	movs r4, #0
	b _0810D38E
	.align 2, 0
_0810D374: .4byte 0x03002BE0
_0810D378: .4byte 0x030046A8
_0810D37C: .4byte 0x030046AC
_0810D380:
	ldr r0, _0810D3A0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0810D38E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0810D3A4
	adds r0, #4
	b _0810D3B0
	.align 2, 0
_0810D3A0: .4byte 0x030046A4
_0810D3A4:
	ldr r0, _0810D3C4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810D3B0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0810D3C8
	cmp r2, #2
	beq _0810D3CC
	b _0810D3D0
	.align 2, 0
_0810D3C4: .4byte 0x030046A4
_0810D3C8:
	ldrb r0, [r6, #4]
	b _0810D3CE
_0810D3CC:
	ldrb r0, [r6]
_0810D3CE:
	subs r1, r1, r0
_0810D3D0:
	strh r1, [r6, #2]
	ldr r0, _0810D3E4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0810D3E8
	movs r0, #1
	b _0810D3EA
	.align 2, 0
_0810D3E4: .4byte 0x030047A4
_0810D3E8:
	movs r0, #0
_0810D3EA:
	cmp r0, #0
	beq _0810D420
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	bne _0810D3FC
	b _0810D93C
_0810D3FC:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0810D408
	adds r2, r0, #0
_0810D408:
	cmp r2, #0
	bge _0810D40E
	b _0810D93C
_0810D40E:
	ldr r1, _0810D41C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0810D468
	.align 2, 0
_0810D41C: .4byte 0x03002BE0
_0810D420:
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
	blt _0810D44C
	cmp r1, #0
	blt _0810D44C
	ldr r0, _0810D450 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810D44C
	ldr r0, _0810D454 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810D458
_0810D44C:
	movs r5, #0
	b _0810D466
	.align 2, 0
_0810D450: .4byte 0x030046A8
_0810D454: .4byte 0x030046AC
_0810D458:
	ldr r0, _0810D4A0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0810D466:
	movs r2, #0
_0810D468:
	ldr r6, _0810D4A4 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _0810D488
	ldr r1, _0810D4A8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0810D488
	b _0810D87C
_0810D488:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0xa4]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x40]
	cmp r0, #0
	beq _0810D4AC
	movs r0, #0
	b _0810D956
	.align 2, 0
_0810D4A0: .4byte 0x030046A4
_0810D4A4: .4byte 0x00000256
_0810D4A8: .4byte 0x03002BE0
_0810D4AC:
	ldr r3, _0810D550 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0xa4]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xb0]
	cmp r6, #0
	beq _0810D568
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _0810D554 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x44]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _0810D558 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x48]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x65
	adds r5, r7, r5
	str r5, [sp, #0x4c]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x50]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r5, r7, r0
	add r1, sp, #0x40
	ldrh r1, [r1]
	strh r1, [r5]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	movs r3, #0
	strb r3, [r4]
	ldr r6, _0810D55C @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _0810D560 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x40]
	str r6, [r1]
	ldr r6, _0810D564 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x44]
	str r6, [sp, #0x98]
	ldr r6, [sp, #0x48]
	str r6, [sp, #0x90]
	ldr r6, [sp, #0x4c]
	str r6, [sp, #0x74]
	ldr r6, [sp, #0x50]
	str r6, [sp, #0x78]
	str r5, [sp, #0xac]
	str r4, [sp, #0x84]
	str r3, [sp, #0x88]
	str r2, [sp, #0x8c]
	str r1, [sp, #0xa0]
	str r0, [sp, #0x94]
	b _0810D73A
	.align 2, 0
_0810D550: .4byte 0x00000222
_0810D554: .4byte 0x0000046D
_0810D558: .4byte 0x0000046B
_0810D55C: .4byte 0x00000469
_0810D560: .4byte 0x00000484
_0810D564: .4byte 0x0000046C
_0810D568:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0810D62C @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x54]
	strb r0, [r2]
	ldr r3, _0810D630 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x58]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _0810D634 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x5c]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x60]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x64]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x68]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _0810D638 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _0810D63C @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _0810D640 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xa8]
	ldr r0, [r0]
	str r0, [sp, #0x6c]
	ldr r1, [sp, #0x80]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x6c]
	strh r1, [r6]
	ldr r6, [sp, #0x80]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x6c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x54]
	str r0, [sp, #0x98]
	ldr r6, [sp, #0x58]
	str r6, [sp, #0x90]
	ldr r0, [sp, #0x5c]
	str r0, [sp, #0x74]
	ldr r6, [sp, #0x60]
	str r6, [sp, #0x78]
	ldr r0, [sp, #0x64]
	str r0, [sp, #0xac]
	ldr r6, [sp, #0x68]
	str r6, [sp, #0x84]
	str r5, [sp, #0x88]
	str r4, [sp, #0x8c]
	str r3, [sp, #0xa0]
	str r2, [sp, #0x94]
	mov r0, sl
	cmp r0, #0
	blt _0810D626
	cmp r1, #0
	blt _0810D626
	ldr r0, _0810D644 @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _0810D626
	ldr r0, _0810D648 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810D64C
_0810D626:
	movs r4, #0
	b _0810D65C
	.align 2, 0
_0810D62C: .4byte 0x0000046D
_0810D630: .4byte 0x0000046B
_0810D634: .4byte 0x00000553
_0810D638: .4byte 0x00000469
_0810D63C: .4byte 0x00000484
_0810D640: .4byte 0x0000046C
_0810D644: .4byte 0x030046A8
_0810D648: .4byte 0x030046AC
_0810D64C:
	ldr r0, _0810D66C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_0810D65C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0810D670
	adds r0, #4
	b _0810D67C
	.align 2, 0
_0810D66C: .4byte 0x030046A4
_0810D670:
	ldr r0, _0810D690 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810D67C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0810D694
	cmp r2, #2
	beq _0810D69A
	b _0810D6A0
	.align 2, 0
_0810D690: .4byte 0x030046A4
_0810D694:
	ldr r2, [sp, #0x6c]
	ldrb r0, [r2, #4]
	b _0810D69E
_0810D69A:
	ldr r3, [sp, #0x6c]
	ldrb r0, [r3]
_0810D69E:
	subs r1, r1, r0
_0810D6A0:
	ldr r4, [sp, #0x6c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xa8]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0810D6CC
	cmp r1, #0
	blt _0810D6CC
	ldr r0, _0810D6D0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810D6CC
	ldr r0, _0810D6D4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810D6D8
_0810D6CC:
	movs r4, #0
	b _0810D6E6
	.align 2, 0
_0810D6D0: .4byte 0x030046A8
_0810D6D4: .4byte 0x030046AC
_0810D6D8:
	ldr r0, _0810D6FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0810D6E6:
	ldr r6, [sp, #0xa8]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0810D700
	adds r0, #4
	b _0810D70C
	.align 2, 0
_0810D6FC: .4byte 0x030046A4
_0810D700:
	ldr r0, _0810D720 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810D70C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0810D724
	cmp r3, #2
	beq _0810D728
	b _0810D72C
	.align 2, 0
_0810D720: .4byte 0x030046A4
_0810D724:
	ldrb r0, [r5, #4]
	b _0810D72A
_0810D728:
	ldrb r0, [r5]
_0810D72A:
	subs r2, r2, r0
_0810D72C:
	ldr r1, [sp, #0xa8]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xa8]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0810D73A:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x70]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xa4]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _0810D764 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x9c]
	cmp r0, #0
	bne _0810D844
	movs r1, #4
	ldr r6, [sp, #0xb0]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0810D768
	movs r0, #1
	b _0810D76A
	.align 2, 0
_0810D764: .4byte 0x00000482
_0810D768:
	movs r0, #0
_0810D76A:
	ldr r1, _0810D854 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x9c]
	cmp r0, #0
	bne _0810D844
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xbc]
	ldr r0, _0810D858 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _0810D85C @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _0810D860 @ =0x0000054E
	adds r6, r6, r7
	mov ip, r6
	ldr r0, _0810D864 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xb4]
	ldr r1, _0810D868 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0x7c]
	ldr r2, _0810D86C @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xb8]
	ldr r1, _0810D870 @ =0x030046B8
	adds r2, r4, #0
_0810D7B2:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _0810D874 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _0810D878 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _0810D7D6
	adds r3, #1
	cmp r3, #3
	ble _0810D7B2
	adds r0, r4, #0
_0810D7D6:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0x78]
	ldr r0, [r1]
	ldr r2, [sp, #0xbc]
	str r0, [r2]
	ldr r4, [sp, #0x74]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x84]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x88]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x8c]
	ldrb r0, [r5]
	mov r6, ip
	strb r0, [r6]
	add r0, sp, #0x70
	ldrb r1, [r0]
	ldr r0, [sp, #0xb4]
	strb r1, [r0]
	ldr r1, [sp, #0x7c]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x98]
	strb r1, [r4]
	ldr r5, [sp, #0x90]
	strb r3, [r5]
	ldr r6, [sp, #0x74]
	strb r0, [r6]
	ldr r0, [sp, #0x78]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xac]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x84]
	strb r0, [r5]
	ldr r6, [sp, #0x88]
	strb r1, [r6]
	ldr r0, [sp, #0x8c]
	strb r2, [r0]
	ldr r2, [sp, #0xa0]
	str r3, [r2]
	ldr r3, [sp, #0x94]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xb8]
	strb r0, [r4]
_0810D844:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x9c]
	strh r0, [r5]
	movs r0, #0
	b _0810D956
	.align 2, 0
_0810D854: .4byte 0x00000482
_0810D858: .4byte 0x0000054F
_0810D85C: .4byte 0x0000054C
_0810D860: .4byte 0x0000054E
_0810D864: .4byte 0x00000541
_0810D868: .4byte 0x000005BC
_0810D86C: .4byte 0x00000542
_0810D870: .4byte 0x030046B8
_0810D874: .4byte 0x000003FF
_0810D878: .4byte 0x0203B400
_0810D87C:
	add r6, sp, #8
	ldr r0, _0810D8BC @ =0x030046A4
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
	beq _0810D8C0
	adds r0, #4
	b _0810D8CC
	.align 2, 0
_0810D8BC: .4byte 0x030046A4
_0810D8C0:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0810D8CC:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0810D904 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _0810D90C
	ldr r0, _0810D908 @ =0xFFFFFDFF
	ldr r6, [sp, #0xa4]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _0810D936
	.align 2, 0
_0810D904: .4byte 0x000004A4
_0810D908: .4byte 0xFFFFFDFF
_0810D90C:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _0810D92C
	cmp r0, #2
	beq _0810D928
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0810D928:
	movs r0, #1
	b _0810D938
_0810D92C:
	ldr r0, _0810D94C @ =0xFFFFFDFF
	ldr r2, [sp, #0xa4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0810D936:
	movs r0, #0
_0810D938:
	cmp r0, #0
	bne _0810D954
_0810D93C:
	ldr r3, _0810D950 @ =0x000005C4
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0810D956
	.align 2, 0
_0810D94C: .4byte 0xFFFFFDFF
_0810D950: .4byte 0x000005C4
_0810D954:
	movs r0, #1
_0810D956:
	adds r1, r0, #0
	cmp r1, #0
	bne _0810D9E8
	ldr r4, [sp, #0x10]
	ldr r5, _0810D994 @ =0x00000744
	adds r0, r4, r5
	strh r1, [r0]
	ldr r6, _0810D998 @ =0x000004A4
	adds r0, r7, r6
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
	bne _0810D9A0
	ldr r0, _0810D99C @ =0xFFFFFDFF
	ldr r2, [sp, #0xa4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0810D9CA
	.align 2, 0
_0810D994: .4byte 0x00000744
_0810D998: .4byte 0x000004A4
_0810D99C: .4byte 0xFFFFFDFF
_0810D9A0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0810D9C0
	cmp r0, #2
	beq _0810D9BC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0810D9BC:
	movs r0, #1
	b _0810D9CC
_0810D9C0:
	ldr r0, _0810D9E0 @ =0xFFFFFDFF
	ldr r3, [sp, #0xa4]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0810D9CA:
	movs r0, #0
_0810D9CC:
	cmp r0, #0
	bne _0810D9E8
_0810D9D0:
	ldr r4, _0810D9E4 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0810DA40
	.align 2, 0
_0810D9E0: .4byte 0xFFFFFDFF
_0810D9E4: .4byte 0x000005C4
_0810D9E8:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _0810DA50 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _0810DA54 @ =0x0000046B
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
	ldr r6, _0810DA58 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0810DA5C @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _0810DA60 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #2
	strh r0, [r1]
_0810DA40:
	add sp, #0xc0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810DA50: .4byte 0x0000046D
_0810DA54: .4byte 0x0000046B
_0810DA58: .4byte 0x00000469
_0810DA5C: .4byte 0x0000046A
_0810DA60: .4byte 0x00000484

	thumb_func_start FUN_0810da64
FUN_0810da64: @ 0x0810DA64
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0810DA88 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810DA8C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810DA8E
	.align 2, 0
_0810DA88: .4byte 0x0000046D
_0810DA8C:
	movs r0, #0
_0810DA8E:
	cmp r0, #0
	beq _0810DA9C
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	b _0810DB9E
_0810DA9C:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0xec
	lsls r1, r1, #3
	add r1, r8
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhi _0810DABA
	ldr r0, _0810DAD0 @ =0x0000075C
	add r0, r8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810DAD8
_0810DABA:
	movs r0, #0xe6
	lsls r0, r0, #3
	add r0, r8
	ldr r1, _0810DAD4 @ =0xFFFFFEFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	adds r0, r5, #0
	bl FUN_08106648
	b _0810DB9E
	.align 2, 0
_0810DAD0: .4byte 0x0000075C
_0810DAD4: .4byte 0xFFFFFEFF
_0810DAD8:
	adds r0, r5, #0
	bl FUN_081058f4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0810DB9E
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r2, _0810DB18 @ =0x000004A4
	adds r0, r5, r2
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0810DB1C
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _0810DB42
	.align 2, 0
_0810DB18: .4byte 0x000004A4
_0810DB1C:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0810DB3C
	cmp r0, #2
	beq _0810DB38
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0810DB38:
	movs r0, #1
	b _0810DB4C
_0810DB3C:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
_0810DB42:
	ldr r1, _0810DB60 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0810DB4C:
	cmp r0, #0
	bne _0810DB68
	ldr r2, _0810DB64 @ =0x000005C4
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	b _0810DB9E
	.align 2, 0
_0810DB60: .4byte 0xFFFFFDFF
_0810DB64: .4byte 0x000005C4
_0810DB68:
	movs r2, #0xe6
	lsls r2, r2, #3
	add r2, r8
	ldr r1, _0810DBA8 @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r4, #0
	strh r1, [r2]
	movs r1, #0xf
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _0810DBAC @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #2
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_0810DB9E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810DBA8: .4byte 0xFFFFFEFF
_0810DBAC: .4byte 0x00000484

	thumb_func_start FUN_0810dbb0
FUN_0810dbb0: @ 0x0810DBB0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r2, _0810DBD0 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810DBD4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810DBD6
	.align 2, 0
_0810DBD0: .4byte 0x0000046D
_0810DBD4:
	movs r0, #0
_0810DBD6:
	cmp r0, #0
	beq _0810DBDC
	b _0810DD02
_0810DBDC:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r6, #0xfe
	lsls r6, r6, #1
	adds r0, r5, r6
	ldrb r1, [r0]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0810DC00
	ldr r0, _0810DBFC @ =0xFFFFFF00
	adds r1, r1, r0
	b _0810DC0E
	.align 2, 0
_0810DBFC: .4byte 0xFFFFFF00
_0810DC00:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0810DC0E
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0810DC0E:
	cmp r1, #0
	bge _0810DC14
	rsbs r1, r1, #0
_0810DC14:
	cmp r1, #0x20
	ble _0810DCD0
	movs r1, #0x80
	lsls r1, r1, #3
	movs r6, #0xe6
	lsls r6, r6, #3
	adds r0, r4, r6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0810DC2E
	movs r0, #1
	b _0810DC30
_0810DC2E:
	movs r0, #0
_0810DC30:
	cmp r0, #0
	bne _0810DD02
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _0810DC4C
	asrs r0, r1, #6
	b _0810DC52
_0810DC4C:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0810DC52:
	lsls r0, r0, #6
	cmp r0, #0
	blt _0810DC5C
	asrs r0, r0, #5
	b _0810DC62
_0810DC5C:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0810DC62:
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	movs r2, #0xee
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _0810DCC0 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r4, _0810DCC4 @ =0x0000046D
	adds r0, r5, r4
	movs r4, #1
	strb r4, [r0]
	ldr r6, _0810DCC8 @ =0x0000046B
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
	movs r3, #0x14
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0810DCCC @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	b _0810DD02
	.align 2, 0
_0810DCC0: .4byte FUN_080e48d0
_0810DCC4: .4byte 0x0000046D
_0810DCC8: .4byte 0x0000046B
_0810DCCC: .4byte 0x0000046A
_0810DCD0:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r6, #0xec
	lsls r6, r6, #3
	adds r1, r4, r6
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhi _0810DCEE
	ldr r1, _0810DD08 @ =0x0000075C
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810DD02
_0810DCEE:
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r1, _0810DD0C @ =0xFFFFFEFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	adds r0, r5, #0
	bl FUN_081075dc
_0810DD02:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0810DD08: .4byte 0x0000075C
_0810DD0C: .4byte 0xFFFFFEFF

	thumb_func_start FUN_0810dd10
FUN_0810dd10: @ 0x0810DD10
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r5, [r0]
	ldr r2, _0810DD30 @ =0x0000046D
	adds r1, r3, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810DD34
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810DD36
	.align 2, 0
_0810DD30: .4byte 0x0000046D
_0810DD34:
	movs r0, #0
_0810DD36:
	cmp r0, #0
	bne _0810DE08
	movs r2, #0x80
	lsls r2, r2, #1
	movs r4, #0xe6
	lsls r4, r4, #3
	adds r1, r5, r4
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _0810DD52
	movs r0, #1
	b _0810DD54
_0810DD52:
	movs r0, #0
_0810DD54:
	cmp r0, #0
	beq _0810DE00
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0xec
	lsls r2, r2, #3
	adds r1, r5, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bls _0810DDD6
	ldr r4, _0810DD7C @ =0x000001DF
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, #8
	bne _0810DD80
	movs r2, #0x14
	b _0810DD82
	.align 2, 0
_0810DD7C: .4byte 0x000001DF
_0810DD80:
	movs r2, #0x11
_0810DD82:
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r3, r1
	movs r1, #0
	strb r1, [r0]
	ldr r4, _0810DDB8 @ =0x00000469
	adds r0, r3, r4
	strb r1, [r0]
	adds r4, #1
	adds r0, r3, r4
	strb r2, [r0]
	ldr r2, _0810DDBC @ =0x00000484
	adds r0, r3, r2
	str r1, [r0]
	adds r4, #2
	adds r1, r3, r4
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	blt _0810DDC0
	asrs r0, r0, #5
	b _0810DDC6
	.align 2, 0
_0810DDB8: .4byte 0x00000469
_0810DDBC: .4byte 0x00000484
_0810DDC0:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0810DDC6:
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r3, r2
	strb r0, [r1]
	b _0810DE08
_0810DDD6:
	ldr r0, _0810DDF0 @ =0xFFFFFEFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	ldr r4, _0810DDF4 @ =0x000001DF
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, #8
	bne _0810DDF8
	adds r0, r3, #0
	bl FUN_081075dc
	b _0810DE08
	.align 2, 0
_0810DDF0: .4byte 0xFFFFFEFF
_0810DDF4: .4byte 0x000001DF
_0810DDF8:
	adds r0, r3, #0
	bl FUN_08106648
	b _0810DE08
_0810DE00:
	adds r0, r3, #0
	movs r1, #1
	bl FUN_080ef86c
_0810DE08:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0810de10
FUN_0810de10: @ 0x0810DE10
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, _0810DE28 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810DE2C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810DE2E
	.align 2, 0
_0810DE28: .4byte 0x0000046D
_0810DE2C:
	movs r0, #0
_0810DE2E:
	cmp r0, #0
	beq _0810DF26
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r1, _0810DE70 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _0810DE74 @ =0x0000021E
	adds r0, r6, r2
	movs r1, #0
	strh r1, [r0]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r1, [r0]
	subs r2, #0x1c
	adds r0, r6, r2
	strh r1, [r0]
	subs r3, #0x54
	adds r0, r6, r3
	ldr r0, [r0]
	movs r1, #0x10
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0810DE78
	movs r0, #1
	b _0810DE7A
	.align 2, 0
_0810DE70: .4byte 0xFFFEBE3F
_0810DE74: .4byte 0x0000021E
_0810DE78:
	movs r0, #0
_0810DE7A:
	cmp r0, #0
	bne _0810DE96
	adds r0, r6, #0
	movs r1, #3
	bl FUN_080ef86c
	ldr r3, _0810DEBC @ =0x000001DF
	adds r0, r6, r3
	ldrb r3, [r0]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #1
	bl FUN_080e5718
_0810DE96:
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0810DEC0 @ =0x0000025D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810DEC4
	ldr r2, [r6, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _0810DED2
	.align 2, 0
_0810DEBC: .4byte 0x000001DF
_0810DEC0: .4byte 0x0000025D
_0810DEC4:
	ldr r0, [r6, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_0810DED2:
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _0810DF50 @ =0x00000469
	adds r0, r6, r3
	strb r2, [r0]
	ldr r1, _0810DF54 @ =0x0000046A
	adds r0, r6, r1
	strb r2, [r0]
	adds r3, #0x1b
	adds r0, r6, r3
	str r2, [r0]
	ldr r0, _0810DF58 @ =0x0000046C
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r2, [r0]
	subs r3, #0x16
	adds r0, r6, r3
	strb r1, [r0]
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r2, [r0]
	adds r3, #0x50
	adds r0, r6, r3
	strh r2, [r0]
	movs r2, #0x80
	lsls r2, r2, #0xa
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0810DF26:
	cmp r4, #6
	ble _0810DFEC
	subs r0, r4, #6
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #1
	ldrh r0, [r6, #0xa]
	subs r0, r0, r1
	strh r0, [r6, #0xa]
	ldr r1, _0810DF5C @ =0x0000025D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810DF60
	ldr r2, [r6, #0x44]
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _0810DF6A
	.align 2, 0
_0810DF50: .4byte 0x00000469
_0810DF54: .4byte 0x0000046A
_0810DF58: .4byte 0x0000046C
_0810DF5C: .4byte 0x0000025D
_0810DF60:
	ldr r2, [r6, #0x44]
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_0810DF6A:
	cmp r4, #8
	ble _0810DFEC
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r5, #0
	movs r4, #0
	strh r4, [r0]
	movs r0, #8
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #3
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
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
	ldr r3, _0810DFF4 @ =FUN_080f5208
	movs r2, #0x17
	ldr r0, _0810DFF8 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810DFFC @ =0x0000046B
	adds r0, r6, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r4, [r0]
_0810DFEC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0810DFF4: .4byte FUN_080f5208
_0810DFF8: .4byte 0x0000046D
_0810DFFC: .4byte 0x0000046B

	thumb_func_start FUN_0810e000
FUN_0810e000: @ 0x0810E000
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x3c
	adds r7, r0, #0
	adds r4, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldr r2, _0810E02C @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810E030
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810E032
	.align 2, 0
_0810E02C: .4byte 0x0000046D
_0810E030:
	movs r0, #0
_0810E032:
	cmp r0, #0
	bne _0810E038
	b _0810E16C
_0810E038:
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
	adds r0, r7, #0
	bl FUN_080e8360
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r1, _0810E0B0 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _0810E0B4 @ =0x0000021E
	adds r0, r7, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	subs r2, #0x1e
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, r7, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #2
	bne _0810E0B8
	bl FUN_081f5400
	bl FUN_081f45ac
	b _0810E0C0
	.align 2, 0
_0810E0B0: .4byte 0xFFFEBE3F
_0810E0B4: .4byte 0x0000021E
_0810E0B8:
	bl FUN_081f9d80
	bl FUN_081f9628
_0810E0C0:
	movs r0, #0xcd
	lsls r0, r0, #1
	adds r2, r7, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _0810E11E
	movs r1, #8
	ldrsh r0, [r7, r1]
	str r0, [sp]
	movs r1, #0xa
	ldrsh r0, [r7, r1]
	str r0, [sp, #4]
	movs r1, #0xc
	ldrsh r0, [r7, r1]
	str r0, [sp, #8]
	movs r1, #0xce
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0xc]
	adds r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	adds r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r7]
	str r0, [sp, #0x1c]
	ldr r1, _0810E148 @ =0xFFFF0000
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
_0810E11E:
	ldr r1, _0810E14C @ =0x000001DF
	adds r0, r7, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r7, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _0810E154
	ldr r0, _0810E150 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r2, r0
	movs r1, #1
	lsls r1, r3
	b _0810E166
	.align 2, 0
_0810E148: .4byte 0xFFFF0000
_0810E14C: .4byte 0x000001DF
_0810E150: .4byte 0x030046A0
_0810E154:
	ldr r0, _0810E27C @ =0x030046A0
	ldr r2, [r0]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r2, r2, r1
	adds r0, r3, #0
	subs r0, #0x20
	movs r1, #1
	lsls r1, r0
_0810E166:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_0810E16C:
	adds r0, r7, #0
	movs r1, #0xa
	bl FUN_080ef86c
	adds r0, r7, #0
	bl FUN_080e499c
	movs r0, #0x40
	bl FUN_0823b9cc
	cmp r4, #0x78
	ble _0810E26C
	ldr r0, _0810E280 @ =0x000003B3
	bl PlaySound_082406e0
	adds r0, r7, #0
	bl FUN_08107a6c
	ldr r2, _0810E284 @ =0x0000046B
	adds r0, r7, r2
	movs r1, #1
	strb r1, [r0]
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r1, #0
	strh r1, [r0]
	subs r2, #0x76
	adds r0, r7, r2
	strh r1, [r0]
	ldr r0, _0810E288 @ =0x0000046D
	adds r0, r7, r0
	str r0, [sp, #0x2c]
	movs r1, #1
	strb r1, [r0]
	ldr r2, _0810E284 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x30]
	movs r0, #0
	strb r0, [r2]
	ldr r1, _0810E28C @ =0x00000553
	adds r1, r7, r1
	str r1, [sp, #0x34]
	movs r2, #0x10
	strb r2, [r1]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x38]
	ldr r1, _0810E290 @ =FUN_080e48d0
	str r1, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r4, r7, r2
	movs r0, #0
	strh r0, [r4]
	movs r0, #2
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r5, r7, r1
	movs r2, #1
	strb r2, [r5]
	adds r1, #1
	adds r6, r7, r1
	movs r2, #0
	strb r2, [r6]
	adds r1, #1
	adds r1, r1, r7
	mov sl, r1
	strb r0, [r1]
	ldr r2, _0810E294 @ =0x00000484
	adds r2, r2, r7
	mov sb, r2
	movs r0, #0
	str r0, [r2]
	ldr r1, _0810E298 @ =0x0000046C
	adds r1, r1, r7
	mov r8, r1
	movs r2, #1
	strb r2, [r1]
	adds r0, r7, #0
	bl FUN_080e6658
	ldr r1, [sp, #0x28]
	ldr r2, _0810E29C @ =0x0000072A
	adds r0, r1, r2
	ldrh r0, [r0]
	bl FUN_0807a798
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r7, r1
	bl FUN_080136b4
	movs r0, #1
	ldr r2, [sp, #0x2c]
	strb r0, [r2]
	movs r2, #0
	ldr r1, [sp, #0x30]
	strb r2, [r1]
	movs r1, #0x10
	ldr r0, [sp, #0x34]
	strb r1, [r0]
	ldr r2, _0810E290 @ =FUN_080e48d0
	ldr r0, [sp, #0x38]
	str r2, [r0]
	movs r1, #0
	strh r1, [r4]
	movs r0, #3
	strb r0, [r5]
	movs r2, #0
	strb r2, [r6]
	mov r0, sl
	strb r2, [r0]
	movs r1, #0
	mov r2, sb
	str r1, [r2]
	movs r1, #1
	mov r0, r8
	strb r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #5
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0810E26C:
	add sp, #0x3c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810E27C: .4byte 0x030046A0
_0810E280: .4byte 0x000003B3
_0810E284: .4byte 0x0000046B
_0810E288: .4byte 0x0000046D
_0810E28C: .4byte 0x00000553
_0810E290: .4byte FUN_080e48d0
_0810E294: .4byte 0x00000484
_0810E298: .4byte 0x0000046C
_0810E29C: .4byte 0x0000072A

	thumb_func_start FUN_0810e2a0
FUN_0810e2a0: @ 0x0810E2A0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xe8
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x8c]
	ldr r2, _0810E2CC @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810E2D0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810E2D2
	.align 2, 0
_0810E2CC: .4byte 0x0000046D
_0810E2D0:
	movs r0, #0
_0810E2D2:
	cmp r0, #0
	bne _0810E2D8
	b _0810E4C0
_0810E2D8:
	adds r0, r7, #0
	movs r1, #0xa
	bl FUN_080ef86c
	ldr r3, _0810E37C @ =0x0000046E
	adds r0, r7, r3
	movs r4, #0
	strb r4, [r0]
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
	adds r0, r7, #0
	bl FUN_080e8360
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r1, _0810E380 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r6, _0810E384 @ =0x0000021E
	adds r0, r7, r6
	strh r4, [r0]
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r7, r1
	strh r4, [r0]
	ldr r2, _0810E388 @ =0x00000202
	adds r0, r7, r2
	strh r4, [r0]
	adds r2, r7, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r3, _0810E38C @ =0x000001DF
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #6
	bne _0810E410
	ldrb r0, [r7, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r1, #0xff
	ands r3, r1
	add r5, sp, #0x4c
	movs r4, #0xa
	ldr r2, _0810E390 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	muls r0, r4, r0
	adds r6, r5, #0
	cmp r0, #0
	blt _0810E394
	asrs r1, r0, #0xc
	b _0810E39A
	.align 2, 0
_0810E37C: .4byte 0x0000046E
_0810E380: .4byte 0xFFFEBE3F
_0810E384: .4byte 0x0000021E
_0810E388: .4byte 0x00000202
_0810E38C: .4byte 0x000001DF
_0810E390: .4byte 0x085B0A08
_0810E394:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810E39A:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0810E3B2
	asrs r0, r0, #0xc
	b _0810E3B8
_0810E3B2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810E3B8:
	movs r4, #0
	strh r0, [r5, #4]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp, #0x54]
	str r1, [sp, #0x58]
	ldr r2, [sp, #0x54]
	asrs r1, r2, #0x10
	adds r1, #0xc8
	lsls r1, r1, #0x10
	ldr r0, _0810E404 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x54]
	movs r0, #0x36
	strh r0, [r6, #2]
	add r0, sp, #0x54
	ldr r2, _0810E408 @ =0x0000D45E
	ldr r3, _0810E40C @ =0x00001DC3
	str r4, [sp]
	movs r1, #0x1a
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	movs r1, #0xf7
	str r1, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r1, r6, #0
	bl FUN_081ef708
	b _0810E4B2
	.align 2, 0
_0810E404: .4byte 0x0000FFFF
_0810E408: .4byte 0x0000D45E
_0810E40C: .4byte 0x00001DC3
_0810E410:
	cmp r0, #7
	bne _0810E4B2
	ldrb r0, [r7, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r1, #0xff
	ands r3, r1
	add r5, sp, #0x5c
	movs r4, #0xa
	ldr r2, _0810E440 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	muls r0, r4, r0
	adds r6, r5, #0
	cmp r0, #0
	blt _0810E444
	asrs r1, r0, #0xc
	b _0810E44A
	.align 2, 0
_0810E440: .4byte 0x085B0A08
_0810E444:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810E44A:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0810E462
	asrs r0, r0, #0xc
	b _0810E468
_0810E462:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810E468:
	movs r4, #0
	strh r0, [r5, #4]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp, #0x64]
	str r1, [sp, #0x68]
	ldr r2, [sp, #0x64]
	asrs r1, r2, #0x10
	adds r1, #0xc8
	lsls r1, r1, #0x10
	ldr r0, _0810E58C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x64]
	movs r0, #0x36
	strh r0, [r6, #2]
	add r0, sp, #0x64
	ldr r2, _0810E590 @ =0x0000D45E
	ldr r3, _0810E594 @ =0x00001DC3
	movs r1, #4
	str r1, [sp]
	movs r1, #0x1a
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	movs r1, #0xf7
	str r1, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r1, r6, #0
	bl FUN_081ef708
_0810E4B2:
	movs r0, #0xc0
	lsls r0, r0, #5
	ldr r3, _0810E598 @ =0x00000474
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0810E4C0:
	adds r0, r7, #0
	bl FUN_080e499c
	ldr r4, _0810E59C @ =0x0000046E
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810E4D4
	bl _0810ECCC
_0810E4D4:
	ldr r5, _0810E5A0 @ =0x0000046B
	adds r0, r7, r5
	movs r1, #0
	movs r4, #1
	strb r4, [r0]
	movs r6, #0xc9
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r1, [r0]
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #7
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r7, r3
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #0xe0]
	cmp r0, #0
	bne _0810E504
	b _0810E648
_0810E504:
	movs r5, #0xcd
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r0, [r2]
	cmp r0, #0
	beq _0810E564
	movs r6, #8
	ldrsh r0, [r7, r6]
	str r0, [sp, #0x2c]
	movs r1, #0xa
	ldrsh r0, [r7, r1]
	str r0, [sp, #0x30]
	movs r3, #0xc
	ldrsh r0, [r7, r3]
	str r0, [sp, #0x34]
	adds r5, #2
	adds r0, r7, r5
	ldr r0, [r0]
	str r0, [sp, #0x38]
	movs r6, #0xd0
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r0, [r0]
	str r0, [sp, #0x3c]
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x40]
	movs r3, #0x94
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r0, [r0]
	str r0, [sp, #0x44]
	ldrh r0, [r7]
	str r0, [sp, #0x48]
	ldr r1, _0810E5A4 @ =0xFFFF0000
	ldr r0, [sp, #0x6c]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x6c]
	add r1, sp, #0x6c
	add r5, sp, #0x2c
	str r5, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_0810E564:
	ldr r6, _0810E5A8 @ =0x000001DF
	adds r0, r7, r6
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r7, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _0810E5B0
	ldr r0, _0810E5AC @ =0x030046A0
	ldr r2, [r0]
	movs r5, #0xe2
	lsls r5, r5, #2
	adds r2, r2, r5
	adds r1, r4, #0
	lsls r1, r3
	b _0810E5C2
	.align 2, 0
_0810E58C: .4byte 0x0000FFFF
_0810E590: .4byte 0x0000D45E
_0810E594: .4byte 0x00001DC3
_0810E598: .4byte 0x00000474
_0810E59C: .4byte 0x0000046E
_0810E5A0: .4byte 0x0000046B
_0810E5A4: .4byte 0xFFFF0000
_0810E5A8: .4byte 0x000001DF
_0810E5AC: .4byte 0x030046A0
_0810E5B0:
	ldr r0, _0810E630 @ =0x030046A0
	ldr r2, [r0]
	movs r6, #0xe3
	lsls r6, r6, #2
	adds r2, r2, r6
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_0810E5C2:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r4, _0810E634 @ =FUN_0810c464
	movs r3, #0x38
	ldr r1, _0810E638 @ =0x0000046D
	adds r0, r7, r1
	movs r1, #0
	movs r2, #1
	strb r2, [r0]
	ldr r5, _0810E63C @ =0x0000046B
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _0810E640 @ =0x00000553
	adds r0, r7, r6
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r7, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r7, r4
	strh r1, [r0]
	movs r5, #0xc2
	lsls r5, r5, #1
	adds r0, r7, r5
	strh r2, [r0]
	movs r0, #0x41
	rsbs r0, r0, #0
	ldr r6, [sp, #0xe0]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	movs r0, #0x12
	ldr r1, [sp, #0x8c]
	movs r3, #0xe6
	lsls r3, r3, #3
	adds r2, r1, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0810E644 @ =0x000003AD
	bl PlaySound_082406e0
	adds r4, #0xa0
	adds r0, r7, r4
	bl FUN_080136b4
	adds r0, r7, #0
	adds r0, #0x48
	movs r1, #1
	bl FUN_08022488
	b _0810ECCC
	.align 2, 0
_0810E630: .4byte 0x030046A0
_0810E634: .4byte FUN_0810c464
_0810E638: .4byte 0x0000046D
_0810E63C: .4byte 0x0000046B
_0810E640: .4byte 0x00000553
_0810E644: .4byte 0x000003AD
_0810E648:
	ldr r5, _0810E68C @ =0x0000049C
	adds r0, r7, r5
	ldr r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	cmp r0, #0
	beq _0810E672
	movs r6, #0x93
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r0, [r0]
	movs r1, #0x17
	ands r0, r1
	movs r2, #0xe6
	lsls r2, r2, #3
	ldr r1, [sp, #0x8c]
	adds r2, r1, r2
	str r2, [sp, #0xd8]
	cmp r0, #0
	beq _0810E672
	b _0810E888
_0810E672:
	movs r2, #0xc0
	lsls r2, r2, #5
	ldr r3, [sp, #0x8c]
	movs r4, #0xe6
	lsls r4, r4, #3
	adds r1, r3, r4
	ldrh r0, [r1]
	ands r0, r2
	str r1, [sp, #0xd8]
	cmp r0, #0
	beq _0810E690
	movs r0, #1
	b _0810E692
	.align 2, 0
_0810E68C: .4byte 0x0000049C
_0810E690:
	movs r0, #0
_0810E692:
	adds r3, r0, #0
	cmp r3, #0
	beq _0810E69A
	b _0810E888
_0810E69A:
	ldr r1, _0810E73C @ =FUN_0810c464
	movs r0, #0x38
	ldr r5, _0810E740 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x90]
	movs r2, #1
	strb r2, [r5]
	ldr r6, _0810E744 @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x94]
	strb r3, [r6]
	ldr r4, _0810E748 @ =0x00000553
	adds r4, r4, r7
	mov r8, r4
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sb, r5
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x98]
	movs r1, #0
	strh r3, [r6]
	movs r0, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x9c]
	strb r0, [r4]
	ldr r5, _0810E74C @ =0x00000469
	adds r5, r5, r7
	mov ip, r5
	strb r1, [r5]
	ldr r6, _0810E750 @ =0x0000046A
	adds r5, r7, r6
	strb r1, [r5]
	ldr r0, _0810E754 @ =0x00000484
	adds r4, r7, r0
	str r3, [r4]
	ldr r1, _0810E758 @ =0x0000046C
	adds r3, r7, r1
	strb r2, [r3]
	movs r6, #0xc2
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r2, [r0]
	movs r2, #0x40
	movs r0, #0x41
	rsbs r0, r0, #0
	ldr r6, [sp, #0xe0]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	ldr r1, [sp, #0xd8]
	ldrh r0, [r1]
	ands r0, r2
	ldr r2, [sp, #0x90]
	str r2, [sp, #0xd0]
	ldr r6, [sp, #0x94]
	str r6, [sp, #0xc8]
	mov r1, r8
	str r1, [sp, #0xdc]
	mov r2, sb
	str r2, [sp, #0xe4]
	ldr r6, [sp, #0x98]
	str r6, [sp, #0xb4]
	ldr r1, [sp, #0x9c]
	str r1, [sp, #0xbc]
	mov r2, ip
	str r2, [sp, #0xc0]
	str r5, [sp, #0xc4]
	str r4, [sp, #0xd4]
	str r3, [sp, #0xcc]
	cmp r0, #0
	beq _0810E75C
	movs r0, #1
	b _0810E75E
	.align 2, 0
_0810E73C: .4byte FUN_0810c464
_0810E740: .4byte 0x0000046D
_0810E744: .4byte 0x0000046B
_0810E748: .4byte 0x00000553
_0810E74C: .4byte 0x00000469
_0810E750: .4byte 0x0000046A
_0810E754: .4byte 0x00000484
_0810E758: .4byte 0x0000046C
_0810E75C:
	movs r0, #0
_0810E75E:
	cmp r0, #0
	beq _0810E776
	ldr r3, _0810E80C @ =0x000001DF
	adds r1, r7, r3
	movs r0, #7
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_0810388c
	adds r0, r7, #0
	bl FUN_08105690
_0810E776:
	ldr r4, [sp, #0x8c]
	ldr r5, _0810E810 @ =0x00000726
	adds r0, r4, r5
	ldrh r1, [r0]
	ldr r0, _0810E814 @ =0x00004E1F
	cmp r1, r0
	bls _0810E864
	movs r6, #0xcd
	lsls r6, r6, #1
	adds r2, r7, r6
	ldrh r0, [r2]
	cmp r0, #0
	beq _0810E7E4
	movs r1, #8
	ldrsh r0, [r7, r1]
	str r0, [sp, #0x2c]
	movs r3, #0xa
	ldrsh r0, [r7, r3]
	str r0, [sp, #0x30]
	movs r4, #0xc
	ldrsh r0, [r7, r4]
	str r0, [sp, #0x34]
	movs r5, #0xce
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	str r0, [sp, #0x38]
	adds r6, #6
	adds r0, r7, r6
	ldr r0, [r0]
	str r0, [sp, #0x3c]
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x40]
	movs r3, #0x94
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r0, [r0]
	str r0, [sp, #0x44]
	ldrh r0, [r7]
	str r0, [sp, #0x48]
	ldr r1, _0810E818 @ =0xFFFF0000
	ldr r0, [sp, #0x74]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x74]
	add r1, sp, #0x74
	add r4, sp, #0x2c
	str r4, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_0810E7E4:
	ldr r5, _0810E80C @ =0x000001DF
	adds r0, r7, r5
	ldrb r0, [r0]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r1, r7, r6
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _0810E820
	ldr r0, _0810E81C @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r2, r0
	movs r1, #1
	lsls r1, r3
	b _0810E832
	.align 2, 0
_0810E80C: .4byte 0x000001DF
_0810E810: .4byte 0x00000726
_0810E814: .4byte 0x00004E1F
_0810E818: .4byte 0xFFFF0000
_0810E81C: .4byte 0x030046A0
_0810E820:
	ldr r0, _0810E858 @ =0x030046A0
	ldr r2, [r0]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r2, r2, r1
	adds r0, r3, #0
	subs r0, #0x20
	movs r1, #1
	lsls r1, r0
_0810E832:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r2, [sp, #0x8c]
	ldr r3, _0810E85C @ =0x0000072A
	adds r0, r2, r3
	ldrh r0, [r0]
	bl FUN_0807a798
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r0, [r0]
	ldr r5, _0810E860 @ =0x00000189
	adds r1, r7, r5
	ldrb r1, [r1]
	bl FUN_0807a840
	b _0810E872
	.align 2, 0
_0810E858: .4byte 0x030046A0
_0810E85C: .4byte 0x0000072A
_0810E860: .4byte 0x00000189
_0810E864:
	ldr r6, [sp, #0x8c]
	movs r1, #0xe5
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r0, [r0]
	bl FUN_0807a798
_0810E872:
	movs r0, #0x10
	ldr r2, [sp, #0xd8]
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0810E884 @ =0x000003AD
	bl PlaySound_082406e0
	b _0810EC3E
	.align 2, 0
_0810E884: .4byte 0x000003AD
_0810E888:
	ldr r3, _0810E914 @ =FUN_080e48d0
	movs r2, #0x10
	ldr r4, _0810E918 @ =0x0000046D
	adds r4, r4, r7
	mov sl, r4
	movs r0, #0
	movs r1, #1
	strb r1, [r4]
	ldr r5, _0810E91C @ =0x0000046B
	adds r5, r7, r5
	str r5, [sp, #0xa0]
	strb r0, [r5]
	ldr r6, _0810E920 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	strb r2, [r6]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xa8]
	str r3, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0xac]
	movs r2, #0
	strh r0, [r3]
	movs r3, #2
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xb0]
	strb r1, [r4]
	ldr r6, _0810E924 @ =0x00000469
	adds r5, r7, r6
	strb r2, [r5]
	ldr r2, _0810E928 @ =0x0000046A
	adds r4, r7, r2
	strb r3, [r4]
	adds r6, #0x1b
	adds r3, r7, r6
	str r0, [r3]
	ldr r0, _0810E92C @ =0x0000046C
	adds r2, r7, r0
	strb r1, [r2]
	movs r0, #0x40
	ldr r6, [sp, #0xd8]
	ldrh r1, [r6]
	ands r1, r0
	mov r0, sl
	str r0, [sp, #0xd0]
	ldr r6, [sp, #0xa0]
	str r6, [sp, #0xc8]
	ldr r0, [sp, #0xa4]
	str r0, [sp, #0xdc]
	ldr r6, [sp, #0xa8]
	str r6, [sp, #0xe4]
	ldr r0, [sp, #0xac]
	str r0, [sp, #0xb4]
	ldr r6, [sp, #0xb0]
	str r6, [sp, #0xbc]
	str r5, [sp, #0xc0]
	str r4, [sp, #0xc4]
	str r3, [sp, #0xd4]
	str r2, [sp, #0xcc]
	cmp r1, #0
	beq _0810E930
	movs r0, #1
	b _0810E932
	.align 2, 0
_0810E914: .4byte FUN_080e48d0
_0810E918: .4byte 0x0000046D
_0810E91C: .4byte 0x0000046B
_0810E920: .4byte 0x00000553
_0810E924: .4byte 0x00000469
_0810E928: .4byte 0x0000046A
_0810E92C: .4byte 0x0000046C
_0810E930:
	movs r0, #0
_0810E932:
	cmp r0, #0
	beq _0810E93E
	ldr r0, _0810E9D0 @ =0x000001DF
	adds r1, r7, r0
	movs r0, #7
	strb r0, [r1]
_0810E93E:
	adds r0, r7, #0
	bl FUN_080e6658
	movs r1, #0xcd
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r0, [r2]
	cmp r0, #0
	beq _0810E9A4
	movs r3, #8
	ldrsh r0, [r7, r3]
	str r0, [sp, #0x2c]
	movs r4, #0xa
	ldrsh r0, [r7, r4]
	str r0, [sp, #0x30]
	movs r5, #0xc
	ldrsh r0, [r7, r5]
	str r0, [sp, #0x34]
	movs r6, #0xce
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r0, [r0]
	str r0, [sp, #0x38]
	adds r1, #6
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x3c]
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r0, [r0]
	str r0, [sp, #0x40]
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r0, [r0]
	str r0, [sp, #0x44]
	ldrh r0, [r7]
	str r0, [sp, #0x48]
	ldr r1, _0810E9D4 @ =0xFFFF0000
	ldr r0, [sp, #0x7c]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x7c]
	add r1, sp, #0x7c
	add r5, sp, #0x2c
	str r5, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_0810E9A4:
	ldr r6, _0810E9D0 @ =0x000001DF
	adds r4, r7, r6
	ldrb r0, [r4]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r7, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	str r4, [sp, #0xb8]
	cmp r3, #0x1f
	bgt _0810E9DC
	ldr r0, _0810E9D8 @ =0x030046A0
	ldr r2, [r0]
	movs r4, #0xe2
	lsls r4, r4, #2
	adds r2, r2, r4
	movs r1, #1
	lsls r1, r3
	b _0810E9EE
	.align 2, 0
_0810E9D0: .4byte 0x000001DF
_0810E9D4: .4byte 0xFFFF0000
_0810E9D8: .4byte 0x030046A0
_0810E9DC:
	ldr r0, _0810EA2C @ =0x030046A0
	ldr r2, [r0]
	movs r5, #0xe3
	lsls r5, r5, #2
	adds r2, r2, r5
	adds r0, r3, #0
	subs r0, #0x20
	movs r1, #1
	lsls r1, r0
_0810E9EE:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r6, [sp, #0x8c]
	ldr r1, _0810EA30 @ =0x0000072A
	adds r0, r6, r1
	ldrh r0, [r0]
	bl FUN_0807a798
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r0, [r0]
	ldr r3, _0810EA34 @ =0x00000189
	adds r1, r7, r3
	ldrb r1, [r1]
	bl FUN_0807a840
	ldr r0, _0810EA2C @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _0810EA38 @ =0x00000948
	adds r2, r0, r4
	ldrh r3, [r2]
	movs r5, #0
	ldrsh r1, [r2, r5]
	ldr r0, _0810EA3C @ =0x0000270E
	cmp r1, r0
	bgt _0810EA40
	adds r0, r3, #1
	b _0810EA44
	.align 2, 0
_0810EA2C: .4byte 0x030046A0
_0810EA30: .4byte 0x0000072A
_0810EA34: .4byte 0x00000189
_0810EA38: .4byte 0x00000948
_0810EA3C: .4byte 0x0000270E
_0810EA40:
	ldr r6, _0810EA60 @ =0x0000270F
	adds r0, r6, #0
_0810EA44:
	strh r0, [r2]
	ldr r0, _0810EA64 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xf8
	lsls r1, r1, #1
	adds r2, r0, r1
	ldrh r3, [r2]
	movs r4, #0
	ldrsh r1, [r2, r4]
	ldr r0, _0810EA68 @ =0x0000270E
	cmp r1, r0
	bgt _0810EA6C
	adds r0, r3, #1
	b _0810EA70
	.align 2, 0
_0810EA60: .4byte 0x0000270F
_0810EA64: .4byte 0x030046A0
_0810EA68: .4byte 0x0000270E
_0810EA6C:
	ldr r5, _0810EC00 @ =0x0000270F
	adds r0, r5, #0
_0810EA70:
	strh r0, [r2]
	adds r0, r7, #0
	bl FUN_080e9178
	ldr r2, _0810EC04 @ =0xFFFF0000
	ldr r0, [sp, #0x84]
	ands r0, r2
	movs r1, #0x50
	orrs r0, r1
	ldr r1, _0810EC08 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x84]
	add r5, sp, #0x84
	ldr r0, [r5, #4]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	str r0, [r5, #4]
	ldr r4, _0810EC0C @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r6, _0810EC10 @ =0x000003FF
	ands r0, r6
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0810EC14 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r2, #3
	ands r1, r2
	adds r1, #1
	adds r6, r7, #0
	adds r6, #8
	movs r3, #4
	str r3, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r2, #2
	str r2, [sp, #8]
	movs r3, #1
	str r3, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x20
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0810EC10 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0810EC14 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	movs r2, #0x14
	str r2, [sp, #4]
	movs r3, #2
	str r3, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x40
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0810EC10 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0810EC14 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	movs r2, #0x14
	str r2, [sp, #4]
	movs r3, #2
	str r3, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x5e
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0810EC10 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0810EC14 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	movs r2, #0x14
	str r2, [sp, #4]
	movs r3, #2
	str r3, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0x80
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0810EC10 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0810EC14 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r0, #4
	str r0, [sp]
	movs r2, #0x14
	str r2, [sp, #4]
	movs r3, #2
	str r3, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0xc4
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0810EC10 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r2, _0810EC14 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r3, #3
	ands r1, r3
	adds r1, #1
	movs r4, #4
	str r4, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r2, #2
	str r2, [sp, #8]
	movs r3, #1
	str r3, [sp, #0xc]
	adds r0, r6, #0
	adds r2, r5, #0
	movs r3, #0xf0
	bl FUN_080ddcc8
	ldr r5, [sp, #0xb8]
	ldrb r4, [r5]
	cmp r4, #4
	beq _0810EBE8
	cmp r4, #1
	beq _0810EBE8
	cmp r4, #5
	beq _0810EBE8
	cmp r4, #7
	beq _0810EBE8
	cmp r4, #6
	beq _0810EBE8
	cmp r4, #0x18
	bne _0810EBEE
_0810EBE8:
	movs r0, #0xe5
	bl PlaySound_082406e0
_0810EBEE:
	ldr r0, _0810EC18 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0810EC1C
	movs r0, #1
	b _0810EC1E
	.align 2, 0
_0810EC00: .4byte 0x0000270F
_0810EC04: .4byte 0xFFFF0000
_0810EC08: .4byte 0x0000FFFF
_0810EC0C: .4byte 0x030046B8
_0810EC10: .4byte 0x000003FF
_0810EC14: .4byte 0x0203B400
_0810EC18: .4byte 0x030047A4
_0810EC1C:
	movs r0, #0
_0810EC1E:
	cmp r0, #0
	bne _0810EC3E
	movs r1, #0x80
	lsls r1, r1, #4
	movs r6, #0xbe
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0810EC3E
	ldr r0, _0810EC5C @ =0x03002B28
	ldrh r0, [r0]
	ldrh r1, [r7]
	bl FUN_080ec5b4
_0810EC3E:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r7, r1
	bl FUN_080136b4
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0xd8]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0810EC60
	movs r0, #1
	b _0810EC62
	.align 2, 0
_0810EC5C: .4byte 0x03002B28
_0810EC60:
	movs r0, #0
_0810EC62:
	cmp r0, #0
	beq _0810ECCC
	add r1, sp, #0x2c
	movs r4, #0
	movs r5, #0
	movs r0, #6
	strh r0, [r1]
	ldr r3, [sp, #0x8c]
	ldr r6, _0810ECDC @ =0x00000756
	adds r0, r3, r6
	ldrb r0, [r0]
	strh r0, [r1, #2]
	ldrh r0, [r7, #8]
	strh r0, [r1, #4]
	ldrh r0, [r7, #0xa]
	strh r0, [r1, #6]
	ldrh r0, [r7, #0xc]
	strh r0, [r1, #8]
	movs r0, #8
	bl FUN_080ec79c
	ldr r1, _0810ECE0 @ =FUN_080e48d0
	movs r0, #0x10
	movs r2, #1
	ldr r3, [sp, #0xd0]
	strb r2, [r3]
	ldr r6, [sp, #0xc8]
	strb r4, [r6]
	ldr r3, [sp, #0xdc]
	strb r0, [r3]
	ldr r6, [sp, #0xe4]
	str r1, [r6]
	ldr r0, [sp, #0xb4]
	strh r5, [r0]
	movs r0, #3
	ldr r1, [sp, #0xbc]
	strb r0, [r1]
	ldr r3, [sp, #0xc0]
	strb r4, [r3]
	ldr r6, [sp, #0xc4]
	strb r4, [r6]
	ldr r0, [sp, #0xd4]
	str r5, [r0]
	ldr r1, [sp, #0xcc]
	strb r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #5
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0810ECCC:
	add sp, #0xe8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810ECDC: .4byte 0x00000756
_0810ECE0: .4byte FUN_080e48d0

	thumb_func_start FUN_0810ece4
FUN_0810ece4: @ 0x0810ECE4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x74
	adds r7, r0, #0
	ldr r0, _0810ED04 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810ED08
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810ED0A
	.align 2, 0
_0810ED04: .4byte 0x0000046C
_0810ED08:
	movs r0, #0
_0810ED0A:
	cmp r0, #0
	bne _0810ED10
	b _0810F04C
_0810ED10:
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	strb r0, [r7, #5]
	ldr r2, _0810EDE8 @ =0x000001DF
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #5
	bne _0810EDFC
	movs r0, #0x80
	lsls r0, r0, #2
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	mov sb, r2
	cmp r4, #0
	bne _0810ED48
	ldr r6, _0810EDEC @ =0x000004B7
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0x76
	beq _0810ED48
	b _0810EFE0
_0810ED48:
	mov r4, sp
	adds r4, #5
	adds r0, r7, #0
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_080e5d44
	add r0, sp, #4
	ldrb r3, [r0]
	ldr r1, _0810EDF0 @ =0x000004C1
	adds r0, r7, r1
	ldrb r1, [r4]
	ldrb r0, [r0]
	movs r2, #0x76
	adds r4, r1, #0
	orrs r4, r0
	ldr r6, _0810EDF4 @ =0x0000025D
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810ED74
	b _0810EF26
_0810ED74:
	ldr r0, [r7, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r3, #0
	adds r2, #0x76
	ldr r3, _0810EDEC @ =0x000004B7
	adds r0, r7, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0810EDF8 @ =0x0000046E
	adds r6, r7, r0
	cmp r1, r2
	bne _0810EDB4
	ldrb r0, [r6]
	cmp r0, #0
	bne _0810EDB4
	cmp r4, #1
	bne _0810EDA4
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0810EDA4
	b _0810EFD2
_0810EDA4:
	cmp r4, #0
	bne _0810EDB4
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0810EDB4
	b _0810EFD2
_0810EDB4:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0810EDC6
	movs r3, #6
_0810EDC6:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	bne _0810EDDE
	b _0810EFC4
_0810EDDE:
	ldr r0, [r5, #8]
	mov r2, r8
	orrs r0, r2
	b _0810EFCC
	.align 2, 0
_0810EDE8: .4byte 0x000001DF
_0810EDEC: .4byte 0x000004B7
_0810EDF0: .4byte 0x000004C1
_0810EDF4: .4byte 0x0000025D
_0810EDF8: .4byte 0x0000046E
_0810EDFC:
	cmp r0, #6
	bne _0810EED4
	movs r0, #0x80
	lsls r0, r0, #2
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	mov sb, r2
	cmp r4, #0
	bne _0810EE24
	ldr r6, _0810EEC4 @ =0x000004B7
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0x78
	beq _0810EE24
	b _0810EFE0
_0810EE24:
	mov r4, sp
	adds r4, #6
	mov r5, sp
	adds r5, #7
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_080e5d44
	ldrb r3, [r4]
	ldr r1, _0810EEC8 @ =0x000004C1
	adds r0, r7, r1
	ldrb r1, [r5]
	ldrb r0, [r0]
	movs r2, #0x78
	adds r4, r1, #0
	orrs r4, r0
	ldr r6, _0810EECC @ =0x0000025D
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0810EF26
	ldr r0, [r7, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r3, #0
	adds r2, #0x78
	ldr r3, _0810EEC4 @ =0x000004B7
	adds r0, r7, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0810EED0 @ =0x0000046E
	adds r6, r7, r0
	cmp r1, r2
	bne _0810EE90
	ldrb r0, [r6]
	cmp r0, #0
	bne _0810EE90
	cmp r4, #1
	bne _0810EE80
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0810EE80
	b _0810EFD2
_0810EE80:
	cmp r4, #0
	bne _0810EE90
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0810EE90
	b _0810EFD2
_0810EE90:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0810EEA2
	movs r3, #6
_0810EEA2:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	bne _0810EEBA
	b _0810EFC4
_0810EEBA:
	ldr r0, [r5, #8]
	mov r2, r8
	orrs r0, r2
	b _0810EFCC
	.align 2, 0
_0810EEC4: .4byte 0x000004B7
_0810EEC8: .4byte 0x000004C1
_0810EECC: .4byte 0x0000025D
_0810EED0: .4byte 0x0000046E
_0810EED4:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r3, r3, r7
	mov sb, r3
	cmp r0, #7
	beq _0810EEE2
	b _0810F008
_0810EEE2:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _0810EEFC
	ldr r6, _0810EF40 @ =0x000004B7
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0x7a
	bne _0810EFE0
_0810EEFC:
	add r4, sp, #8
	mov r5, sp
	adds r5, #9
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_080e5d44
	ldrb r3, [r4]
	ldr r1, _0810EF44 @ =0x000004C1
	adds r0, r7, r1
	ldrb r1, [r5]
	ldrb r0, [r0]
	movs r2, #0x7a
	adds r4, r1, #0
	orrs r4, r0
	ldr r6, _0810EF48 @ =0x0000025D
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810EF50
_0810EF26:
	ldr r1, _0810EF40 @ =0x000004B7
	adds r0, r7, r1
	strb r2, [r0]
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r4, [sp]
	bl FUN_08236fac
	ldr r2, _0810EF4C @ =0x0000046E
	adds r6, r7, r2
	b _0810EFCE
	.align 2, 0
_0810EF40: .4byte 0x000004B7
_0810EF44: .4byte 0x000004C1
_0810EF48: .4byte 0x0000025D
_0810EF4C: .4byte 0x0000046E
_0810EF50:
	ldr r0, [r7, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r3, #0
	adds r2, #0x7a
	ldr r3, _0810EFBC @ =0x000004B7
	adds r0, r7, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0810EFC0 @ =0x0000046E
	adds r6, r7, r0
	cmp r1, r2
	bne _0810EF8C
	ldrb r0, [r6]
	cmp r0, #0
	bne _0810EF8C
	cmp r4, #1
	bne _0810EF7E
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0810EFD2
_0810EF7E:
	cmp r4, #0
	bne _0810EF8C
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0810EFD2
_0810EF8C:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0810EF9E
	movs r3, #6
_0810EF9E:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0810EFC4
	ldr r0, [r5, #8]
	mov r2, r8
	orrs r0, r2
	b _0810EFCC
	.align 2, 0
_0810EFBC: .4byte 0x000004B7
_0810EFC0: .4byte 0x0000046E
_0810EFC4:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0810EFCC:
	str r0, [r5, #8]
_0810EFCE:
	movs r0, #0
	strb r0, [r6]
_0810EFD2:
	ldr r3, _0810EFDC @ =0x0000046B
	adds r1, r7, r3
	movs r0, #1
	strb r0, [r1]
	b _0810F008
	.align 2, 0
_0810EFDC: .4byte 0x0000046B
_0810EFE0:
	ldr r3, _0810F128 @ =FUN_080f3cdc
	movs r2, #0xa
	ldr r6, _0810F12C @ =0x0000046D
	adds r1, r7, r6
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810F130 @ =0x0000046B
	adds r0, r7, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r7, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
_0810F008:
	ldr r3, _0810F134 @ =0x000001DF
	adds r0, r7, r3
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080e5718
	adds r0, r7, #0
	bl FUN_080e6750
	ldr r4, _0810F134 @ =0x000001DF
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #2
	beq _0810F034
	movs r0, #4
	ldr r6, _0810F138 @ =0x00000222
	adds r2, r7, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0810F034:
	movs r0, #0x80
	mov r2, sb
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r3, #0x93
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r4, _0810F13C @ =0x0000024E
	adds r0, r7, r4
	strh r1, [r0]
_0810F04C:
	ldr r6, _0810F130 @ =0x0000046B
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _0810F058
	b _0810F660
_0810F058:
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x14]
	movs r1, #0
	ldr r2, [sp, #0x14]
	strb r1, [r2]
	ldr r3, _0810F140 @ =0x00000469
	adds r3, r7, r3
	str r3, [sp, #0x18]
	strb r1, [r3]
	ldr r4, _0810F144 @ =0x0000046A
	adds r4, r7, r4
	str r4, [sp, #0x1c]
	strb r0, [r4]
	adds r6, #0x19
	adds r6, r7, r6
	str r6, [sp, #0x20]
	str r1, [r6]
	ldr r0, _0810F148 @ =0x0000046C
	adds r0, r0, r7
	mov sl, r0
	movs r2, #1
	strb r2, [r0]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r3, [r0]
	movs r0, #0x1a
	ldr r4, _0810F12C @ =0x0000046D
	adds r4, r4, r7
	mov sb, r4
	strb r2, [r4]
	ldr r6, _0810F130 @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x70]
	strb r1, [r6]
	ldr r2, _0810F14C @ =0x00000553
	adds r5, r7, r2
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r4, r7, r6
	str r3, [r4]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r3, r7, r0
	strh r1, [r3]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, [r1]
	str r2, [sp, #0x24]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x24]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov r0, sl
	str r0, [sp, #0x44]
	mov r6, sb
	str r6, [sp, #0x48]
	ldr r0, [sp, #0x70]
	str r0, [sp, #0x40]
	str r5, [sp, #0x68]
	str r4, [sp, #0x6c]
	str r3, [sp, #0x30]
	ldr r3, [sp, #0x14]
	str r3, [sp, #0x34]
	ldr r4, [sp, #0x18]
	str r4, [sp, #0x38]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0x3c]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x50]
	mov r6, r8
	mov r8, r2
	mov r2, ip
	cmp r2, #0
	blt _0810F122
	cmp r1, #0
	blt _0810F122
	ldr r0, _0810F150 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _0810F122
	ldr r0, _0810F154 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810F158
_0810F122:
	movs r4, #0
	b _0810F168
	.align 2, 0
_0810F128: .4byte FUN_080f3cdc
_0810F12C: .4byte 0x0000046D
_0810F130: .4byte 0x0000046B
_0810F134: .4byte 0x000001DF
_0810F138: .4byte 0x00000222
_0810F13C: .4byte 0x0000024E
_0810F140: .4byte 0x00000469
_0810F144: .4byte 0x0000046A
_0810F148: .4byte 0x0000046C
_0810F14C: .4byte 0x00000553
_0810F150: .4byte 0x030046A8
_0810F154: .4byte 0x030046AC
_0810F158:
	ldr r0, _0810F178 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r3, ip
	adds r4, r0, r3
_0810F168:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0810F17C
	adds r0, #4
	b _0810F188
	.align 2, 0
_0810F178: .4byte 0x030046A4
_0810F17C:
	ldr r0, _0810F19C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810F188:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0810F1A0
	cmp r2, #2
	beq _0810F1A6
	b _0810F1AC
	.align 2, 0
_0810F19C: .4byte 0x030046A4
_0810F1A0:
	ldr r4, [sp, #0x24]
	ldrb r0, [r4, #4]
	b _0810F1AA
_0810F1A6:
	ldr r2, [sp, #0x24]
	ldrb r0, [r2]
_0810F1AA:
	subs r1, r1, r0
_0810F1AC:
	ldr r3, [sp, #0x24]
	strh r1, [r3, #2]
	ldr r0, _0810F1C4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0810F1C8
	movs r0, #1
	b _0810F1CA
	.align 2, 0
_0810F1C4: .4byte 0x030047A4
_0810F1C8:
	movs r0, #0
_0810F1CA:
	cmp r0, #0
	beq _0810F208
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0810F1EA
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0810F1E6
	adds r2, r0, #0
_0810F1E6:
	cmp r2, #0
	bge _0810F1F4
_0810F1EA:
	ldr r6, _0810F1F0 @ =0x000005C4
	adds r0, r7, r6
	b _0810F64C
	.align 2, 0
_0810F1F0: .4byte 0x000005C4
_0810F1F4:
	ldr r1, _0810F204 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0810F250
	.align 2, 0
_0810F204: .4byte 0x03002BE0
_0810F208:
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
	blt _0810F234
	cmp r1, #0
	blt _0810F234
	ldr r0, _0810F238 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810F234
	ldr r0, _0810F23C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810F240
_0810F234:
	movs r5, #0
	b _0810F24E
	.align 2, 0
_0810F238: .4byte 0x030046A8
_0810F23C: .4byte 0x030046AC
_0810F240:
	ldr r0, _0810F2E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0810F24E:
	movs r2, #0
_0810F250:
	ldr r3, _0810F2E8 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _0810F270
	ldr r1, _0810F2EC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0810F270
	b _0810F58C
_0810F270:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	mov sb, r2
	cmp r4, #0
	beq _0810F28A
	b _0810F66A
_0810F28A:
	ldr r0, _0810F2F0 @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sl, r2
	cmp r3, #0
	beq _0810F2F4
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x48]
	strb r2, [r3]
	ldr r6, [sp, #0x40]
	strb r5, [r6]
	ldr r3, [sp, #0x68]
	strb r0, [r3]
	ldr r6, [sp, #0x6c]
	str r1, [r6]
	ldr r0, [sp, #0x30]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0x34]
	strb r5, [r1]
	ldr r3, [sp, #0x38]
	strb r5, [r3]
	ldr r6, [sp, #0x3c]
	strb r0, [r6]
	ldr r0, [sp, #0x50]
	str r4, [r0]
	ldr r1, [sp, #0x44]
	strb r2, [r1]
	b _0810F442
	.align 2, 0
_0810F2E4: .4byte 0x030046A4
_0810F2E8: .4byte 0x00000256
_0810F2EC: .4byte 0x03002BE0
_0810F2F0: .4byte 0x00000222
_0810F2F4:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r0, #1
	ldr r4, [sp, #0x48]
	strb r0, [r4]
	ldr r2, [sp, #0x40]
	strb r5, [r2]
	ldr r4, [sp, #0x68]
	strb r0, [r4]
	ldr r2, [sp, #0x6c]
	str r1, [r2]
	ldr r4, [sp, #0x30]
	strh r3, [r4]
	movs r1, #5
	ldr r2, [sp, #0x34]
	strb r5, [r2]
	ldr r4, [sp, #0x38]
	strb r5, [r4]
	ldr r2, [sp, #0x3c]
	strb r1, [r2]
	ldr r4, [sp, #0x50]
	str r3, [r4]
	ldr r1, [sp, #0x44]
	strb r0, [r1]
	ldr r5, [r6]
	mov r2, r8
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
	blt _0810F358
	cmp r1, #0
	blt _0810F358
	ldr r0, _0810F35C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810F358
	ldr r0, _0810F360 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810F364
_0810F358:
	movs r4, #0
	b _0810F372
	.align 2, 0
_0810F35C: .4byte 0x030046A8
_0810F360: .4byte 0x030046AC
_0810F364:
	ldr r0, _0810F384 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0810F372:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0810F388
	adds r0, #4
	b _0810F394
	.align 2, 0
_0810F384: .4byte 0x030046A4
_0810F388:
	ldr r0, _0810F3A8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810F394:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0810F3AC
	cmp r2, #2
	beq _0810F3B0
	b _0810F3B4
	.align 2, 0
_0810F3A8: .4byte 0x030046A4
_0810F3AC:
	ldrb r0, [r5, #4]
	b _0810F3B2
_0810F3B0:
	ldrb r0, [r5]
_0810F3B2:
	subs r1, r1, r0
_0810F3B4:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0810F3DC
	cmp r1, #0
	blt _0810F3DC
	ldr r0, _0810F3E0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810F3DC
	ldr r0, _0810F3E4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810F3E8
_0810F3DC:
	movs r4, #0
	b _0810F3F6
	.align 2, 0
_0810F3E0: .4byte 0x030046A8
_0810F3E4: .4byte 0x030046AC
_0810F3E8:
	ldr r0, _0810F408 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0810F3F6:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0810F40C
	adds r0, #4
	b _0810F418
	.align 2, 0
_0810F408: .4byte 0x030046A4
_0810F40C:
	ldr r0, _0810F42C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810F418:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0810F430
	cmp r3, #2
	beq _0810F434
	b _0810F438
	.align 2, 0
_0810F42C: .4byte 0x030046A4
_0810F430:
	ldrb r0, [r5, #4]
	b _0810F436
_0810F434:
	ldrb r0, [r5]
_0810F436:
	subs r2, r2, r0
_0810F438:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_0810F442:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x28]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r4, sb
	ldrh r0, [r4]
	ands r0, r1
	mov r8, r3
	ldr r6, _0810F46C @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x4c]
	cmp r0, #0
	bne _0810F550
	movs r1, #4
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0810F470
	movs r0, #1
	b _0810F472
	.align 2, 0
_0810F46C: .4byte 0x00000482
_0810F470:
	movs r0, #0
_0810F472:
	ldr r3, _0810F560 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x4c]
	cmp r0, #0
	bne _0810F550
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _0810F564 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _0810F568 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x5c]
	ldr r2, _0810F56C @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x60]
	ldr r4, _0810F570 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x64]
	ldr r6, _0810F574 @ =0x00000541
	adds r6, r7, r6
	str r6, [sp, #0x54]
	ldr r0, _0810F578 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x2c]
	ldr r1, _0810F57C @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x58]
	ldr r6, _0810F580 @ =0x0203B400
	ldr r1, _0810F584 @ =0x030046B8
	ldr r5, _0810F588 @ =0x000003FF
	movs r4, #3
	mov r2, r8
_0810F4C2:
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
	bne _0810F4E0
	adds r3, #1
	cmp r3, #3
	ble _0810F4C2
	mov r0, r8
_0810F4E0:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x6c]
	ldr r0, [r4]
	mov r6, sl
	str r0, [r6]
	ldr r1, [sp, #0x68]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x34]
	ldrb r0, [r4]
	ldr r6, [sp, #0x5c]
	strb r0, [r6]
	ldr r1, [sp, #0x38]
	ldrb r0, [r1]
	ldr r2, [sp, #0x60]
	strb r0, [r2]
	ldr r4, [sp, #0x3c]
	ldrb r0, [r4]
	ldr r6, [sp, #0x64]
	strb r0, [r6]
	add r0, sp, #0x28
	ldrb r1, [r0]
	ldr r0, [sp, #0x54]
	strb r1, [r0]
	ldr r1, [sp, #0x2c]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x48]
	strb r1, [r4]
	ldr r6, [sp, #0x40]
	strb r3, [r6]
	ldr r4, [sp, #0x68]
	strb r0, [r4]
	ldr r6, [sp, #0x6c]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x30]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x34]
	strb r0, [r4]
	ldr r6, [sp, #0x38]
	strb r1, [r6]
	ldr r0, [sp, #0x3c]
	strb r2, [r0]
	ldr r2, [sp, #0x50]
	str r3, [r2]
	ldr r3, [sp, #0x44]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x58]
	strb r0, [r4]
_0810F550:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r6, [sp, #0x4c]
	strh r0, [r6]
	b _0810F66A
	.align 2, 0
_0810F560: .4byte 0x00000482
_0810F564: .4byte 0x0000054F
_0810F568: .4byte 0x0000054C
_0810F56C: .4byte 0x0000054D
_0810F570: .4byte 0x0000054E
_0810F574: .4byte 0x00000541
_0810F578: .4byte 0x000005BC
_0810F57C: .4byte 0x00000542
_0810F580: .4byte 0x0203B400
_0810F584: .4byte 0x030046B8
_0810F588: .4byte 0x000003FF
_0810F58C:
	add r6, sp, #0xc
	ldr r0, _0810F5CC @ =0x030046A4
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
	beq _0810F5D0
	adds r0, #4
	b _0810F5DC
	.align 2, 0
_0810F5CC: .4byte 0x030046A4
_0810F5D0:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0810F5DC:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r6, _0810F610 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _0810F614
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _0810F63A
	.align 2, 0
_0810F610: .4byte 0x000004A4
_0810F614:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _0810F634
	cmp r0, #2
	beq _0810F630
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0810F630:
	movs r0, #1
	b _0810F644
_0810F634:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_0810F63A:
	ldr r1, _0810F658 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0810F644:
	cmp r0, #0
	bne _0810F66A
	ldr r3, _0810F65C @ =0x000005C4
	adds r0, r7, r3
_0810F64C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0810F66A
	.align 2, 0
_0810F658: .4byte 0xFFFFFDFF
_0810F65C: .4byte 0x000005C4
_0810F660:
	ldr r4, _0810F67C @ =0x00000484
	adds r1, r7, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0810F66A:
	add sp, #0x74
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810F67C: .4byte 0x00000484

	thumb_func_start FUN_0810f680
FUN_0810f680: @ 0x0810F680
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x90
	adds r7, r0, #0
	ldr r0, _0810F6A0 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810F6A4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810F6A6
	.align 2, 0
_0810F6A0: .4byte 0x0000046C
_0810F6A4:
	movs r0, #0
_0810F6A6:
	cmp r0, #0
	beq _0810F6B4
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	strb r0, [r7, #5]
_0810F6B4:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0810F6CC
	bl _0810FF36
_0810F6CC:
	adds r0, r7, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _0810F6DE
	bl _0810FF36
_0810F6DE:
	ldr r3, _0810F7D0 @ =0x00000484
	adds r1, r7, r3
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _0810F6EC
	bl FUN_0810ff32
_0810F6EC:
	movs r0, #0x80
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	str r2, [sp, #0x48]
	cmp r3, #0
	bne _0810F704
	b _0810FCF8
_0810F704:
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #8]
	strb r6, [r1]
	ldr r2, _0810F7D4 @ =0x00000469
	adds r2, r7, r2
	str r2, [sp, #0xc]
	strb r6, [r2]
	ldr r3, _0810F7D8 @ =0x0000046A
	adds r3, r7, r3
	str r3, [sp, #0x10]
	strb r0, [r3]
	ldr r4, _0810F7D0 @ =0x00000484
	adds r4, r7, r4
	str r4, [sp, #0x14]
	str r6, [r4]
	ldr r0, _0810F7DC @ =0x0000046C
	adds r0, r0, r7
	mov sb, r0
	movs r1, #1
	strb r1, [r0]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r2, [r0]
	movs r0, #0x1a
	ldr r3, _0810F7E0 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x18]
	strb r1, [r3]
	ldr r4, _0810F7E4 @ =0x0000046B
	adds r4, r4, r7
	mov r8, r4
	strb r6, [r4]
	ldr r1, _0810F7E8 @ =0x00000553
	adds r1, r1, r7
	mov sl, r1
	strb r0, [r1]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r5, r7, r3
	str r2, [r5]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r4, r7, r0
	strh r6, [r4]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r3, r7, r1
	ldr r2, [r3]
	str r2, [sp, #0x1c]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x1c]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov r0, sb
	str r0, [sp, #0x80]
	ldr r6, [sp, #8]
	str r6, [sp, #0x70]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x74]
	ldr r6, [sp, #0x10]
	str r6, [sp, #0x78]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x8c]
	ldr r6, [sp, #0x18]
	str r6, [sp, #0x84]
	mov r0, r8
	str r0, [sp, #0x7c]
	mov r6, sl
	str r6, [sp, #0x60]
	str r5, [sp, #0x68]
	str r4, [sp, #0x64]
	adds r6, r3, #0
	mov r8, r2
	mov r0, ip
	cmp r0, #0
	blt _0810F7CC
	cmp r1, #0
	blt _0810F7CC
	ldr r0, _0810F7EC @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _0810F7CC
	ldr r0, _0810F7F0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810F7F4
_0810F7CC:
	movs r4, #0
	b _0810F804
	.align 2, 0
_0810F7D0: .4byte 0x00000484
_0810F7D4: .4byte 0x00000469
_0810F7D8: .4byte 0x0000046A
_0810F7DC: .4byte 0x0000046C
_0810F7E0: .4byte 0x0000046D
_0810F7E4: .4byte 0x0000046B
_0810F7E8: .4byte 0x00000553
_0810F7EC: .4byte 0x030046A8
_0810F7F0: .4byte 0x030046AC
_0810F7F4:
	ldr r0, _0810F814 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_0810F804:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0810F818
	adds r0, #4
	b _0810F824
	.align 2, 0
_0810F814: .4byte 0x030046A4
_0810F818:
	ldr r0, _0810F838 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810F824:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0810F83C
	cmp r2, #2
	beq _0810F842
	b _0810F848
	.align 2, 0
_0810F838: .4byte 0x030046A4
_0810F83C:
	ldr r2, [sp, #0x1c]
	ldrb r0, [r2, #4]
	b _0810F846
_0810F842:
	ldr r3, [sp, #0x1c]
	ldrb r0, [r3]
_0810F846:
	subs r1, r1, r0
_0810F848:
	ldr r4, [sp, #0x1c]
	strh r1, [r4, #2]
	ldr r0, _0810F860 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0810F864
	movs r0, #1
	b _0810F866
	.align 2, 0
_0810F860: .4byte 0x030047A4
_0810F864:
	movs r0, #0
_0810F866:
	cmp r0, #0
	beq _0810F8A4
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0810F886
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0810F882
	adds r2, r0, #0
_0810F882:
	cmp r2, #0
	bge _0810F890
_0810F886:
	ldr r2, _0810F88C @ =0x000005C4
	adds r0, r7, r2
	b _0810FCE6
	.align 2, 0
_0810F88C: .4byte 0x000005C4
_0810F890:
	ldr r1, _0810F8A0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0810F8EC
	.align 2, 0
_0810F8A0: .4byte 0x03002BE0
_0810F8A4:
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
	blt _0810F8D0
	cmp r1, #0
	blt _0810F8D0
	ldr r0, _0810F8D4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810F8D0
	ldr r0, _0810F8D8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810F8DC
_0810F8D0:
	movs r5, #0
	b _0810F8EA
	.align 2, 0
_0810F8D4: .4byte 0x030046A8
_0810F8D8: .4byte 0x030046AC
_0810F8DC:
	ldr r0, _0810F97C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0810F8EA:
	movs r2, #0
_0810F8EC:
	ldr r4, _0810F980 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0810F90C
	ldr r1, _0810F984 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0810F90C
	b _0810FC24
_0810F90C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x48]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0810F920
	b _0810FF36
_0810F920:
	ldr r3, _0810F988 @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x48]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sl, r2
	cmp r3, #0
	beq _0810F98C
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x84]
	strb r2, [r3]
	ldr r6, [sp, #0x7c]
	strb r5, [r6]
	ldr r3, [sp, #0x60]
	strb r0, [r3]
	ldr r6, [sp, #0x68]
	str r1, [r6]
	ldr r0, [sp, #0x64]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0x70]
	strb r5, [r1]
	ldr r3, [sp, #0x74]
	strb r5, [r3]
	ldr r6, [sp, #0x78]
	strb r0, [r6]
	ldr r0, [sp, #0x8c]
	str r4, [r0]
	ldr r1, [sp, #0x80]
	strb r2, [r1]
	b _0810FADA
	.align 2, 0
_0810F97C: .4byte 0x030046A4
_0810F980: .4byte 0x00000256
_0810F984: .4byte 0x03002BE0
_0810F988: .4byte 0x00000222
_0810F98C:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r0, #1
	ldr r4, [sp, #0x84]
	strb r0, [r4]
	ldr r2, [sp, #0x7c]
	strb r5, [r2]
	ldr r4, [sp, #0x60]
	strb r0, [r4]
	ldr r2, [sp, #0x68]
	str r1, [r2]
	ldr r4, [sp, #0x64]
	strh r3, [r4]
	movs r1, #5
	ldr r2, [sp, #0x70]
	strb r5, [r2]
	ldr r4, [sp, #0x74]
	strb r5, [r4]
	ldr r2, [sp, #0x78]
	strb r1, [r2]
	ldr r4, [sp, #0x8c]
	str r3, [r4]
	ldr r1, [sp, #0x80]
	strb r0, [r1]
	ldr r5, [r6]
	mov r2, r8
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
	blt _0810F9F0
	cmp r1, #0
	blt _0810F9F0
	ldr r0, _0810F9F4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810F9F0
	ldr r0, _0810F9F8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810F9FC
_0810F9F0:
	movs r4, #0
	b _0810FA0A
	.align 2, 0
_0810F9F4: .4byte 0x030046A8
_0810F9F8: .4byte 0x030046AC
_0810F9FC:
	ldr r0, _0810FA1C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0810FA0A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0810FA20
	adds r0, #4
	b _0810FA2C
	.align 2, 0
_0810FA1C: .4byte 0x030046A4
_0810FA20:
	ldr r0, _0810FA40 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810FA2C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0810FA44
	cmp r2, #2
	beq _0810FA48
	b _0810FA4C
	.align 2, 0
_0810FA40: .4byte 0x030046A4
_0810FA44:
	ldrb r0, [r5, #4]
	b _0810FA4A
_0810FA48:
	ldrb r0, [r5]
_0810FA4A:
	subs r1, r1, r0
_0810FA4C:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0810FA74
	cmp r1, #0
	blt _0810FA74
	ldr r0, _0810FA78 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810FA74
	ldr r0, _0810FA7C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810FA80
_0810FA74:
	movs r4, #0
	b _0810FA8E
	.align 2, 0
_0810FA78: .4byte 0x030046A8
_0810FA7C: .4byte 0x030046AC
_0810FA80:
	ldr r0, _0810FAA0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0810FA8E:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0810FAA4
	adds r0, #4
	b _0810FAB0
	.align 2, 0
_0810FAA0: .4byte 0x030046A4
_0810FAA4:
	ldr r0, _0810FAC4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810FAB0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0810FAC8
	cmp r3, #2
	beq _0810FACC
	b _0810FAD0
	.align 2, 0
_0810FAC4: .4byte 0x030046A4
_0810FAC8:
	ldrb r0, [r5, #4]
	b _0810FACE
_0810FACC:
	ldrb r0, [r5]
_0810FACE:
	subs r2, r2, r0
_0810FAD0:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_0810FADA:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x20]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x48]
	ldrh r0, [r4]
	ands r0, r1
	mov sb, r3
	ldr r6, _0810FB04 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x88]
	cmp r0, #0
	bne _0810FBE8
	movs r1, #4
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0810FB08
	movs r0, #1
	b _0810FB0A
	.align 2, 0
_0810FB04: .4byte 0x00000482
_0810FB08:
	movs r0, #0
_0810FB0A:
	ldr r3, _0810FBF8 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x88]
	cmp r0, #0
	bne _0810FBE8
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r6, r7
	mov sl, r6
	ldr r0, _0810FBFC @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _0810FC00 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x54]
	ldr r2, _0810FC04 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x58]
	ldr r4, _0810FC08 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x5c]
	ldr r6, _0810FC0C @ =0x00000541
	adds r6, r7, r6
	str r6, [sp, #0x4c]
	ldr r0, _0810FC10 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x6c]
	ldr r1, _0810FC14 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x50]
	ldr r6, _0810FC18 @ =0x0203B400
	ldr r1, _0810FC1C @ =0x030046B8
	ldr r5, _0810FC20 @ =0x000003FF
	movs r4, #3
	mov r2, sb
_0810FB5A:
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
	bne _0810FB78
	adds r3, #1
	cmp r3, #3
	ble _0810FB5A
	mov r0, sb
_0810FB78:
	movs r3, #0
	mov r2, r8
	strb r0, [r2]
	ldr r4, [sp, #0x68]
	ldr r0, [r4]
	mov r6, sl
	str r0, [r6]
	ldr r1, [sp, #0x60]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x70]
	ldrb r0, [r4]
	ldr r6, [sp, #0x54]
	strb r0, [r6]
	ldr r1, [sp, #0x74]
	ldrb r0, [r1]
	ldr r2, [sp, #0x58]
	strb r0, [r2]
	ldr r4, [sp, #0x78]
	ldrb r0, [r4]
	ldr r6, [sp, #0x5c]
	strb r0, [r6]
	add r0, sp, #0x20
	ldrb r1, [r0]
	ldr r0, [sp, #0x4c]
	strb r1, [r0]
	ldr r1, [sp, #0x6c]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x84]
	strb r1, [r4]
	ldr r6, [sp, #0x7c]
	strb r3, [r6]
	ldr r4, [sp, #0x60]
	strb r0, [r4]
	ldr r6, [sp, #0x68]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x64]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x70]
	strb r0, [r4]
	ldr r6, [sp, #0x74]
	strb r1, [r6]
	ldr r0, [sp, #0x78]
	strb r2, [r0]
	ldr r2, [sp, #0x8c]
	str r3, [r2]
	ldr r3, [sp, #0x80]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x50]
	strb r0, [r4]
_0810FBE8:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r6, [sp, #0x88]
	strh r0, [r6]
	b _0810FF36
	.align 2, 0
_0810FBF8: .4byte 0x00000482
_0810FBFC: .4byte 0x0000054F
_0810FC00: .4byte 0x0000054C
_0810FC04: .4byte 0x0000054D
_0810FC08: .4byte 0x0000054E
_0810FC0C: .4byte 0x00000541
_0810FC10: .4byte 0x000005BC
_0810FC14: .4byte 0x00000542
_0810FC18: .4byte 0x0203B400
_0810FC1C: .4byte 0x030046B8
_0810FC20: .4byte 0x000003FF
_0810FC24:
	mov sb, sp
	ldr r6, _0810FC60 @ =0x030046A4
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
	beq _0810FC64
	adds r0, #4
	b _0810FC6E
	.align 2, 0
_0810FC60: .4byte 0x030046A4
_0810FC64:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0810FC6E:
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
	ldr r1, _0810FCA8 @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _0810FCB0
	ldr r0, _0810FCAC @ =0xFFFFFDFF
	ldr r2, [sp, #0x48]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0810FCDA
	.align 2, 0
_0810FCA8: .4byte 0x000004A4
_0810FCAC: .4byte 0xFFFFFDFF
_0810FCB0:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _0810FCD0
	cmp r0, #2
	beq _0810FCCC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0810FCCC:
	movs r0, #1
	b _0810FCDC
_0810FCD0:
	ldr r0, _0810FCF0 @ =0xFFFFFDFF
	ldr r3, [sp, #0x48]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0810FCDA:
	movs r0, #0
_0810FCDC:
	cmp r0, #0
	beq _0810FCE2
	b _0810FF36
_0810FCE2:
	ldr r4, _0810FCF4 @ =0x000005C4
	adds r0, r7, r4
_0810FCE6:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0810FF36
	.align 2, 0
_0810FCF0: .4byte 0xFFFFFDFF
_0810FCF4: .4byte 0x000005C4
_0810FCF8:
	movs r0, #3
	movs r1, #1
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x24]
	strb r0, [r6]
	ldr r0, _0810FDFC @ =0x00000469
	adds r0, r7, r0
	str r0, [sp, #0x28]
	strb r1, [r0]
	ldr r2, _0810FE00 @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	strb r3, [r2]
	ldr r4, _0810FE04 @ =0x00000484
	adds r4, r7, r4
	str r4, [sp, #0x30]
	str r3, [r4]
	ldr r6, _0810FE08 @ =0x0000046C
	adds r6, r7, r6
	str r6, [sp, #0x34]
	strb r1, [r6]
	ldr r2, _0810FE0C @ =FUN_080e6794
	movs r0, #0xe
	ldr r4, _0810FE10 @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0x38]
	strb r1, [r4]
	ldr r6, _0810FE14 @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x3c]
	strb r3, [r6]
	ldr r1, _0810FE18 @ =0x00000553
	adds r1, r7, r1
	str r1, [sp, #0x40]
	strb r0, [r1]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	str r2, [r4]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x44]
	movs r5, #0
	strh r3, [r6]
	ldr r1, _0810FE1C @ =0x000001DF
	adds r0, r7, r1
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r4, #7
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
	strb r5, [r0]
	ldr r2, _0810FE20 @ =0x00000551
	adds r0, r7, r2
	strb r5, [r0]
	ldr r3, _0810FE24 @ =0x00000552
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
	ldr r6, [sp, #0x34]
	str r6, [sp, #0x80]
	ldr r0, [sp, #0x24]
	str r0, [sp, #0x70]
	ldr r3, [sp, #0x28]
	str r3, [sp, #0x74]
	ldr r4, [sp, #0x2c]
	str r4, [sp, #0x78]
	ldr r6, [sp, #0x30]
	str r6, [sp, #0x8c]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0x84]
	ldr r3, [sp, #0x3c]
	str r3, [sp, #0x7c]
	ldr r4, [sp, #0x40]
	str r4, [sp, #0x60]
	mov r6, r8
	str r6, [sp, #0x68]
	ldr r0, [sp, #0x44]
	str r0, [sp, #0x64]
	cmp r2, #0
	blt _0810FDF6
	cmp r1, #0
	blt _0810FDF6
	ldr r0, _0810FE28 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0810FDF6
	ldr r0, _0810FE2C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0810FE30
_0810FDF6:
	movs r4, #0
	b _0810FE3E
	.align 2, 0
_0810FDFC: .4byte 0x00000469
_0810FE00: .4byte 0x0000046A
_0810FE04: .4byte 0x00000484
_0810FE08: .4byte 0x0000046C
_0810FE0C: .4byte FUN_080e6794
_0810FE10: .4byte 0x0000046D
_0810FE14: .4byte 0x0000046B
_0810FE18: .4byte 0x00000553
_0810FE1C: .4byte 0x000001DF
_0810FE20: .4byte 0x00000551
_0810FE24: .4byte 0x00000552
_0810FE28: .4byte 0x030046A8
_0810FE2C: .4byte 0x030046AC
_0810FE30:
	ldr r0, _0810FE50 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0810FE3E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0810FE54
	adds r0, #4
	b _0810FE60
	.align 2, 0
_0810FE50: .4byte 0x030046A4
_0810FE54:
	ldr r0, _0810FE74 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0810FE60:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0810FE78
	cmp r2, #2
	beq _0810FE7C
	b _0810FE80
	.align 2, 0
_0810FE74: .4byte 0x030046A4
_0810FE78:
	ldrb r0, [r5, #4]
	b _0810FE7E
_0810FE7C:
	ldrb r0, [r5]
_0810FE7E:
	subs r1, r1, r0
_0810FE80:
	strh r1, [r5, #2]
	ldr r1, _0810FEB0 @ =0x000004A4
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
	bne _0810FEB8
	ldr r0, _0810FEB4 @ =0xFFFFFDFF
	ldr r3, [sp, #0x48]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	b _0810FEE2
	.align 2, 0
_0810FEB0: .4byte 0x000004A4
_0810FEB4: .4byte 0xFFFFFDFF
_0810FEB8:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0810FED8
	cmp r0, #2
	beq _0810FED4
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0810FED4:
	movs r0, #1
	b _0810FEE4
_0810FED8:
	ldr r0, _0810FF1C @ =0xFFFFFDFF
	ldr r4, [sp, #0x48]
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
_0810FEE2:
	movs r0, #0
_0810FEE4:
	adds r3, r0, #0
	cmp r3, #0
	bne _0810FF24
	ldr r0, _0810FF20 @ =FUN_080e48d0
	movs r2, #1
	ldr r6, [sp, #0x84]
	strb r2, [r6]
	ldr r1, [sp, #0x7c]
	strb r3, [r1]
	ldr r4, [sp, #0x60]
	strb r3, [r4]
	ldr r6, [sp, #0x68]
	str r0, [r6]
	movs r1, #0
	ldr r0, [sp, #0x64]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x70]
	strb r0, [r4]
	ldr r6, [sp, #0x74]
	strb r1, [r6]
	ldr r0, [sp, #0x78]
	strb r1, [r0]
	ldr r1, [sp, #0x8c]
	str r3, [r1]
	ldr r3, [sp, #0x80]
	strb r2, [r3]
	b _0810FF36
	.align 2, 0
_0810FF1C: .4byte 0xFFFFFDFF
_0810FF20: .4byte FUN_080e48d0
_0810FF24:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	b _0810FF36

	non_word_aligned_thumb_func_start FUN_0810ff32
FUN_0810ff32: @ 0x0810FF32
	adds r0, #1
	str r0, [r1]
_0810FF36:
	add sp, #0x90
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0810ff48
FUN_0810ff48: @ 0x0810FF48
	movs r1, #0xc7
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, _0810FF54 @ =0x085AD524
	str r1, [r0]
	bx lr
	.align 2, 0
_0810FF54: .4byte 0x085AD524

	thumb_func_start FUN_0810ff58
FUN_0810ff58: @ 0x0810FF58
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	ldr r2, _0810FF78 @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810FF7C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810FF7E
	.align 2, 0
_0810FF78: .4byte 0x0000046C
_0810FF7C:
	movs r0, #0
_0810FF7E:
	cmp r0, #0
	beq _0810FFE8
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	movs r5, #0
	movs r7, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _0810FFA4 @ =0x000001DF
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #7
	bne _0810FFAC
	ldr r3, _0810FFA8 @ =FUN_0810a0a8
	b _0810FFAE
	.align 2, 0
_0810FFA4: .4byte 0x000001DF
_0810FFA8: .4byte FUN_0810a0a8
_0810FFAC:
	ldr r3, _08110008 @ =FUN_08109f88
_0810FFAE:
	movs r2, #3
	ldr r0, _0811000C @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08110010 @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r4, r2
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r7, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08103624
	ldr r2, _08110014 @ =0x0000074C
	adds r0, r6, r2
	ldrh r1, [r0]
	subs r2, #8
	adds r0, r6, r2
	strh r1, [r0]
_0810FFE8:
	ldr r1, _08110010 @ =0x0000046B
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0811001C
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r1, _08110018 @ =0xFFFFFEFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	adds r0, r4, #0
	bl FUN_08106648
	b _08110026
	.align 2, 0
_08110008: .4byte FUN_08109f88
_0811000C: .4byte 0x0000046D
_08110010: .4byte 0x0000046B
_08110014: .4byte 0x0000074C
_08110018: .4byte 0xFFFFFEFF
_0811001C:
	ldr r0, _0811002C @ =0x00000484
	adds r1, r4, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08110026:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0811002C: .4byte 0x00000484

	thumb_func_start FUN_08110030
FUN_08110030: @ 0x08110030
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _08110050 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08110054
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08110056
	.align 2, 0
_08110050: .4byte 0x0000046C
_08110054:
	movs r0, #0
_08110056:
	cmp r0, #0
	beq _081100AA
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _081100CC @ =FUN_0810a530
	movs r2, #0x26
	ldr r0, _081100D0 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081100D4 @ =0x0000046B
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
	ldr r2, _081100D8 @ =0x0000074E
	adds r0, r7, r2
	ldrh r1, [r0]
	subs r2, #8
	adds r0, r7, r2
	strh r1, [r0]
	adds r0, r6, #0
	movs r1, #2
	bl FUN_08103624
_081100AA:
	ldr r1, _081100D4 @ =0x0000046B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081100E0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r1, _081100DC @ =0xFFFFFEFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	adds r0, r6, #0
	bl FUN_08106648
	b _081100EA
	.align 2, 0
_081100CC: .4byte FUN_0810a530
_081100D0: .4byte 0x0000046D
_081100D4: .4byte 0x0000046B
_081100D8: .4byte 0x0000074E
_081100DC: .4byte 0xFFFFFEFF
_081100E0:
	ldr r0, _081100F0 @ =0x00000484
	adds r1, r6, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081100EA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081100F0: .4byte 0x00000484

	thumb_func_start FUN_081100f4
FUN_081100f4: @ 0x081100F4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _08110114 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08110118
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0811011A
	.align 2, 0
_08110114: .4byte 0x0000046C
_08110118:
	movs r0, #0
_0811011A:
	cmp r0, #0
	beq _08110170
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _08110190 @ =FUN_0810a8f8
	movs r2, #0x2a
	ldr r0, _08110194 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08110198 @ =0x0000046B
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
	movs r2, #0xea
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrh r1, [r0]
	subs r2, #8
	adds r0, r7, r2
	strh r1, [r0]
	adds r0, r6, #0
	movs r1, #3
	bl FUN_08103624
_08110170:
	ldr r1, _08110198 @ =0x0000046B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081101A0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r1, _0811019C @ =0xFFFFFEFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	adds r0, r6, #0
	bl FUN_08106648
	b _081101AA
	.align 2, 0
_08110190: .4byte FUN_0810a8f8
_08110194: .4byte 0x0000046D
_08110198: .4byte 0x0000046B
_0811019C: .4byte 0xFFFFFEFF
_081101A0:
	ldr r0, _081101B0 @ =0x00000484
	adds r1, r6, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081101AA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081101B0: .4byte 0x00000484

	thumb_func_start FUN_081101b4
FUN_081101b4: @ 0x081101B4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _081101D4 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081101D8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081101DA
	.align 2, 0
_081101D4: .4byte 0x0000046C
_081101D8:
	movs r0, #0
_081101DA:
	cmp r0, #0
	beq _08110240
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _08110260 @ =FUN_0810a9b0
	movs r2, #0x2b
	ldr r0, _08110264 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08110268 @ =0x0000046B
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
	ldr r0, _0811026C @ =0x00000764
	adds r2, r7, r0
	adds r1, #0x10
	adds r0, r6, r1
	ldr r0, [r0]
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _08110270 @ =0x0000074E
	adds r0, r7, r2
	ldrh r1, [r0]
	subs r2, #8
	adds r0, r7, r2
	strh r1, [r0]
	adds r0, r6, #0
	movs r1, #2
	bl FUN_08103624
_08110240:
	ldr r1, _08110268 @ =0x0000046B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08110278
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r1, _08110274 @ =0xFFFFFEFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	adds r0, r6, #0
	bl FUN_08106648
	b _08110282
	.align 2, 0
_08110260: .4byte FUN_0810a9b0
_08110264: .4byte 0x0000046D
_08110268: .4byte 0x0000046B
_0811026C: .4byte 0x00000764
_08110270: .4byte 0x0000074E
_08110274: .4byte 0xFFFFFEFF
_08110278:
	ldr r0, _08110288 @ =0x00000484
	adds r1, r6, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08110282:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08110288: .4byte 0x00000484

	thumb_func_start FUN_0811028c
FUN_0811028c: @ 0x0811028C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x70
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _081102B8 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081102BC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081102BE
	.align 2, 0
_081102B8: .4byte 0x0000046C
_081102BC:
	movs r0, #0
_081102BE:
	cmp r0, #0
	beq _081102EC
	ldr r4, _081103C0 @ =FUN_081091e4
	movs r3, #0x25
	ldr r6, _081103C4 @ =0x0000046D
	adds r1, r7, r6
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081103C8 @ =0x0000046B
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
_081102EC:
	ldr r0, [r7, #0x18]
	ldrb r1, [r0]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _081102FC
	b _0811090C
_081102FC:
	movs r0, #0xc
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x10]
	movs r1, #0
	strb r1, [r4]
	ldr r6, _081103CC @ =0x00000469
	adds r6, r7, r6
	str r6, [sp, #0x14]
	strb r1, [r6]
	ldr r2, _081103D0 @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x18]
	strb r0, [r2]
	ldr r4, _081103D4 @ =0x00000484
	adds r4, r7, r4
	str r4, [sp, #0x1c]
	str r1, [r4]
	ldr r6, _081103D8 @ =0x0000046C
	adds r6, r6, r7
	mov sl, r6
	strb r3, [r6]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r2, [r0]
	movs r0, #0x1a
	ldr r4, _081103C4 @ =0x0000046D
	adds r4, r4, r7
	mov sb, r4
	strb r3, [r4]
	ldr r6, _081103C8 @ =0x0000046B
	adds r6, r6, r7
	mov ip, r6
	strb r1, [r6]
	ldr r3, _081103DC @ =0x00000553
	adds r5, r7, r3
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r4, r7, r6
	str r2, [r4]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r3, r7, r0
	strh r1, [r3]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, [r1]
	str r2, [sp, #0x20]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x20]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r6, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov r0, sl
	str r0, [sp, #0x2c]
	mov r0, sb
	str r0, [sp, #0x30]
	mov r0, ip
	str r0, [sp, #0x28]
	str r5, [sp, #0x54]
	str r4, [sp, #0x58]
	str r3, [sp, #0x38]
	ldr r3, [sp, #0x10]
	str r3, [sp, #0x64]
	ldr r4, [sp, #0x14]
	str r4, [sp, #0x68]
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x6c]
	ldr r3, [sp, #0x1c]
	str r3, [sp, #0x34]
	mov sb, r2
	cmp r6, #0
	blt _081103BC
	cmp r1, #0
	blt _081103BC
	ldr r0, _081103E0 @ =0x030046A8
	ldr r0, [r0]
	cmp r6, r0
	bhs _081103BC
	ldr r0, _081103E4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081103E8
_081103BC:
	movs r4, #0
	b _081103F6
	.align 2, 0
_081103C0: .4byte FUN_081091e4
_081103C4: .4byte 0x0000046D
_081103C8: .4byte 0x0000046B
_081103CC: .4byte 0x00000469
_081103D0: .4byte 0x0000046A
_081103D4: .4byte 0x00000484
_081103D8: .4byte 0x0000046C
_081103DC: .4byte 0x00000553
_081103E0: .4byte 0x030046A8
_081103E4: .4byte 0x030046AC
_081103E8:
	ldr r0, _08110408 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r6
_081103F6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0811040C
	adds r0, #4
	b _08110418
	.align 2, 0
_08110408: .4byte 0x030046A4
_0811040C:
	ldr r0, _0811042C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08110418:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08110430
	cmp r2, #2
	beq _08110436
	b _0811043C
	.align 2, 0
_0811042C: .4byte 0x030046A4
_08110430:
	ldr r4, [sp, #0x20]
	ldrb r0, [r4, #4]
	b _0811043A
_08110436:
	ldr r6, [sp, #0x20]
	ldrb r0, [r6]
_0811043A:
	subs r1, r1, r0
_0811043C:
	ldr r0, [sp, #0x20]
	strh r1, [r0, #2]
	ldr r0, _08110454 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08110458
	movs r0, #1
	b _0811045A
	.align 2, 0
_08110454: .4byte 0x030047A4
_08110458:
	movs r0, #0
_0811045A:
	cmp r0, #0
	beq _081104A0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0811047A
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08110476
	adds r2, r0, #0
_08110476:
	cmp r2, #0
	bge _0811048C
_0811047A:
	ldr r2, _08110488 @ =0x000005C4
	adds r0, r7, r2
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081108EC
	.align 2, 0
_08110488: .4byte 0x000005C4
_0811048C:
	ldr r1, _0811049C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081104E8
	.align 2, 0
_0811049C: .4byte 0x03002BE0
_081104A0:
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
	blt _081104CC
	cmp r1, #0
	blt _081104CC
	ldr r0, _081104D0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081104CC
	ldr r0, _081104D4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081104D8
_081104CC:
	movs r5, #0
	b _081104E6
	.align 2, 0
_081104D0: .4byte 0x030046A8
_081104D4: .4byte 0x030046AC
_081104D8:
	ldr r0, _0811057C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081104E6:
	movs r2, #0
_081104E8:
	ldr r4, _08110580 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _08110508
	ldr r1, _08110584 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08110508
	b _08110828
_08110508:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r7, r6
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	adds r6, r2, #0
	cmp r4, #0
	beq _08110522
	b _081108EC
_08110522:
	ldr r0, _08110588 @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	str r2, [sp, #0x5c]
	cmp r3, #0
	beq _0811058C
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x30]
	strb r2, [r3]
	ldr r3, [sp, #0x28]
	strb r5, [r3]
	ldr r3, [sp, #0x54]
	strb r0, [r3]
	ldr r0, [sp, #0x58]
	str r1, [r0]
	ldr r1, [sp, #0x38]
	strh r4, [r1]
	movs r0, #0xc
	ldr r3, [sp, #0x64]
	strb r5, [r3]
	ldr r1, [sp, #0x68]
	strb r5, [r1]
	ldr r3, [sp, #0x6c]
	strb r0, [r3]
	ldr r0, [sp, #0x34]
	str r4, [r0]
	ldr r1, [sp, #0x2c]
	strb r2, [r1]
	b _081106EA
	.align 2, 0
_0811057C: .4byte 0x030046A4
_08110580: .4byte 0x00000256
_08110584: .4byte 0x03002BE0
_08110588: .4byte 0x00000222
_0811058C:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r0, #1
	ldr r4, [sp, #0x30]
	strb r0, [r4]
	ldr r2, [sp, #0x28]
	strb r5, [r2]
	ldr r4, [sp, #0x54]
	strb r0, [r4]
	ldr r2, [sp, #0x58]
	str r1, [r2]
	ldr r4, [sp, #0x38]
	strh r3, [r4]
	movs r1, #5
	ldr r2, [sp, #0x64]
	strb r5, [r2]
	ldr r4, [sp, #0x68]
	strb r5, [r4]
	ldr r2, [sp, #0x6c]
	strb r1, [r2]
	ldr r4, [sp, #0x34]
	str r3, [r4]
	ldr r1, [sp, #0x2c]
	strb r0, [r1]
	mov r2, r8
	ldr r5, [r2]
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
	blt _081105F2
	cmp r1, #0
	blt _081105F2
	ldr r0, _081105F8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081105F2
	ldr r0, _081105FC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08110600
_081105F2:
	movs r4, #0
	b _0811060E
	.align 2, 0
_081105F8: .4byte 0x030046A8
_081105FC: .4byte 0x030046AC
_08110600:
	ldr r0, _08110620 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811060E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08110624
	adds r0, #4
	b _08110630
	.align 2, 0
_08110620: .4byte 0x030046A4
_08110624:
	ldr r0, _08110644 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08110630:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08110648
	cmp r2, #2
	beq _0811064C
	b _08110650
	.align 2, 0
_08110644: .4byte 0x030046A4
_08110648:
	ldrb r0, [r5, #4]
	b _0811064E
_0811064C:
	ldrb r0, [r5]
_0811064E:
	subs r1, r1, r0
_08110650:
	strh r1, [r5, #2]
	mov r4, r8
	ldr r0, [r4]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811067A
	cmp r1, #0
	blt _0811067A
	ldr r0, _08110680 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811067A
	ldr r0, _08110684 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08110688
_0811067A:
	movs r4, #0
	b _08110696
	.align 2, 0
_08110680: .4byte 0x030046A8
_08110684: .4byte 0x030046AC
_08110688:
	ldr r0, _081106AC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08110696:
	mov r0, r8
	ldr r5, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081106B0
	adds r0, #4
	b _081106BC
	.align 2, 0
_081106AC: .4byte 0x030046A4
_081106B0:
	ldr r0, _081106D0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081106BC:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081106D4
	cmp r3, #2
	beq _081106D8
	b _081106DC
	.align 2, 0
_081106D0: .4byte 0x030046A4
_081106D4:
	ldrb r0, [r5, #4]
	b _081106DA
_081106D8:
	ldrb r0, [r5]
_081106DA:
	subs r2, r2, r0
_081106DC:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	mov r2, r8
	ldr r0, [r2]
	strh r1, [r0, #6]
_081106EA:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x24]
	movs r1, #0x80
	lsls r1, r1, #3
	ldrh r0, [r6]
	ands r0, r1
	mov sl, r3
	ldr r4, _08110710 @ =0x00000482
	adds r5, r7, r4
	cmp r0, #0
	bne _081107F4
	movs r1, #4
	ldr r6, [sp, #0x5c]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08110714
	movs r0, #1
	b _08110716
	.align 2, 0
_08110710: .4byte 0x00000482
_08110714:
	movs r0, #0
_08110716:
	ldr r1, _08110800 @ =0x00000482
	adds r5, r7, r1
	cmp r0, #0
	bne _081107F4
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r2, r2, r7
	mov sb, r2
	movs r4, #0xa9
	lsls r4, r4, #3
	adds r4, r4, r7
	mov ip, r4
	ldr r6, _08110804 @ =0x0000054F
	adds r6, r7, r6
	str r6, [sp, #0x50]
	ldr r0, _08110808 @ =0x0000054C
	adds r0, r7, r0
	str r0, [sp, #0x44]
	adds r1, #0xcb
	adds r1, r7, r1
	str r1, [sp, #0x48]
	ldr r2, _0811080C @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0x4c]
	ldr r4, _08110810 @ =0x00000541
	adds r4, r7, r4
	str r4, [sp, #0x3c]
	ldr r6, _08110814 @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0x60]
	ldr r0, _08110818 @ =0x00000542
	adds r0, r7, r0
	str r0, [sp, #0x40]
	ldr r1, _0811081C @ =0x0203B400
	mov r8, r1
	ldr r1, _08110820 @ =0x030046B8
	ldr r6, _08110824 @ =0x000003FF
	movs r4, #3
	mov r2, sl
_08110766:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	ands r0, r4
	lsls r0, r0, #6
	cmp r0, r2
	bne _08110784
	adds r3, #1
	cmp r3, #3
	ble _08110766
	mov r0, sl
_08110784:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x58]
	ldr r0, [r4]
	mov r6, ip
	str r0, [r6]
	ldr r1, [sp, #0x54]
	ldrb r0, [r1]
	ldr r2, [sp, #0x50]
	strb r0, [r2]
	ldr r4, [sp, #0x64]
	ldrb r0, [r4]
	ldr r6, [sp, #0x44]
	strb r0, [r6]
	ldr r1, [sp, #0x68]
	ldrb r0, [r1]
	ldr r2, [sp, #0x48]
	strb r0, [r2]
	ldr r4, [sp, #0x6c]
	ldrb r0, [r4]
	ldr r6, [sp, #0x4c]
	strb r0, [r6]
	add r0, sp, #0x24
	ldrb r1, [r0]
	ldr r0, [sp, #0x3c]
	strb r1, [r0]
	ldr r1, [sp, #0x60]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x30]
	strb r1, [r4]
	ldr r6, [sp, #0x28]
	strb r3, [r6]
	ldr r4, [sp, #0x54]
	strb r0, [r4]
	ldr r6, [sp, #0x58]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x38]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x64]
	strb r0, [r4]
	ldr r6, [sp, #0x68]
	strb r1, [r6]
	ldr r0, [sp, #0x6c]
	strb r2, [r0]
	ldr r2, [sp, #0x34]
	str r3, [r2]
	ldr r3, [sp, #0x2c]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x40]
	strb r0, [r4]
_081107F4:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	strh r0, [r5]
	b _081108EC
	.align 2, 0
_08110800: .4byte 0x00000482
_08110804: .4byte 0x0000054F
_08110808: .4byte 0x0000054C
_0811080C: .4byte 0x0000054E
_08110810: .4byte 0x00000541
_08110814: .4byte 0x000005BC
_08110818: .4byte 0x00000542
_0811081C: .4byte 0x0203B400
_08110820: .4byte 0x030046B8
_08110824: .4byte 0x000003FF
_08110828:
	mov sb, sp
	ldr r6, _08110864 @ =0x030046A4
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
	beq _08110868
	adds r0, #4
	b _08110872
	.align 2, 0
_08110864: .4byte 0x030046A4
_08110868:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08110872:
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
	ldr r1, _081108A8 @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081108AC
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	b _081108D2
	.align 2, 0
_081108A8: .4byte 0x000004A4
_081108AC:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081108CC
	cmp r0, #2
	beq _081108C8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081108C8:
	movs r0, #1
	b _081108DC
_081108CC:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
_081108D2:
	ldr r1, _08110904 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081108DC:
	cmp r0, #0
	bne _081108EC
	ldr r4, _08110908 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
_081108EC:
	movs r6, #0xe6
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r0, [r0]
	movs r1, #0x80
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	b _08110ABA
	.align 2, 0
_08110904: .4byte 0xFFFFFDFF
_08110908: .4byte 0x000005C4
_0811090C:
	add r2, sp, #8
	adds r4, r7, #0
	adds r4, #8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r7, #8]
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
	movs r4, #0
	ldrsh r0, [r2, r4]
	movs r6, #4
	ldrsh r1, [r2, r6]
	bl FUN_0823785c
	adds r6, r0, #0
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, _08110968 @ =0x0000075C
	add r1, r8
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _08110970
	adds r6, #0x80
	movs r0, #0xff
	ands r6, r0
	ldr r2, _0811096C @ =0x00000482
	adds r1, r7, r2
	movs r0, #2
	strh r0, [r1]
	b _08110986
	.align 2, 0
_08110968: .4byte 0x0000075C
_0811096C: .4byte 0x00000482
_08110970:
	movs r0, #0xec
	lsls r0, r0, #3
	add r0, r8
	ldr r0, [r0]
	cmp r2, r0
	bls _08110986
	ldr r3, _081109BC @ =0x00000482
	adds r1, r7, r3
	movs r0, #2
	strh r0, [r1]
	strb r6, [r7, #5]
_08110986:
	adds r0, r7, #0
	movs r1, #1
	bl FUN_080ef86c
	movs r4, #0xb1
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	mov sb, r0
	ldr r1, _081109C0 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081109C4
	ldr r3, _081109BC @ =0x00000482
	adds r1, r7, r3
	movs r0, #1
	strh r0, [r1]
	adds r5, r1, #0
	b _081109D4
	.align 2, 0
_081109BC: .4byte 0x00000482
_081109C0: .4byte 0x0000A02F
_081109C4:
	ldr r4, _081109F8 @ =0x00000482
	adds r0, r7, r4
	ldrh r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _081109D4
	movs r0, #1
	strh r0, [r5]
_081109D4:
	ldr r1, _081109FC @ =0x0000025D
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08110A00
	ldr r4, [r7, #0x44]
	adds r4, #0x48
	ldrh r1, [r5]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _08110A18
	.align 2, 0
_081109F8: .4byte 0x00000482
_081109FC: .4byte 0x0000025D
_08110A00:
	ldr r4, [r7, #0x44]
	adds r4, #0x20
	ldrh r1, [r5]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_08110A18:
	ldr r2, _08110A38 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r4, sb
	muls r4, r0, r4
	adds r0, r4, #0
	cmp r0, #0
	blt _08110A3C
	asrs r1, r0, #0x10
	b _08110A42
	.align 2, 0
_08110A38: .4byte 0x085B0A08
_08110A3C:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
_08110A42:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r1
	strh r0, [r7, #0x10]
	movs r0, #0xff
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _08110A62
	asrs r2, r0, #0x10
	b _08110A68
_08110A62:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r2, r0, #0
_08110A68:
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r4, #0xf2
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, _08110AAC @ =0x0000075C
	add r1, r8
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bls _08110AB0
	movs r0, #0xec
	lsls r0, r0, #3
	add r0, r8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08110AB0
	movs r0, #0x80
	movs r6, #0xc1
	lsls r6, r6, #1
	adds r2, r7, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _08110ABA
	.align 2, 0
_08110AAC: .4byte 0x0000075C
_08110AB0:
	ldr r0, _08110ACC @ =0x00000484
	adds r1, r7, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08110ABA:
	add sp, #0x70
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08110ACC: .4byte 0x00000484

	thumb_func_start FUN_08110ad0
FUN_08110ad0: @ 0x08110AD0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _08110AF8 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08110AFC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08110AFE
	.align 2, 0
_08110AF8: .4byte 0x0000046C
_08110AFC:
	movs r0, #0
_08110AFE:
	cmp r0, #0
	beq _08110B3E
	movs r0, #0x80
	lsls r0, r0, #1
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r6, r5
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _08110BB4 @ =FUN_0810ac88
	movs r2, #0x2e
	ldr r0, _08110BB8 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08110BBC @ =0x0000046B
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
_08110B3E:
	ldr r2, _08110BBC @ =0x0000046B
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08110B4A
	b _08110C64
_08110B4A:
	ldr r0, _08110BC0 @ =0x0000074C
	add r0, r8
	ldrh r1, [r0]
	ldr r0, _08110BC4 @ =0x00000744
	add r0, r8
	strh r1, [r0]
	ldr r1, _08110BC8 @ =0x00000746
	add r1, r8
	movs r0, #0x64
	strh r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r5, r6, r0
	ldr r0, _08110BCC @ =0xFFFFFEFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	adds r4, r6, #0
	adds r4, #8
	movs r3, #0x80
	lsls r3, r3, #0xb
	adds r0, r6, #0
	mov r1, sp
	adds r2, r4, #0
	bl FUN_081077a4
	ldr r1, _08110BD0 @ =0x000004A4
	adds r0, r6, r1
	ldr r7, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	beq _08110BD4
	adds r0, r7, #0
	adds r1, r4, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08110BD4
	cmp r0, #2
	beq _08110BAE
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08110BAE:
	movs r0, #1
	b _08110BDE
	.align 2, 0
_08110BB4: .4byte FUN_0810ac88
_08110BB8: .4byte 0x0000046D
_08110BBC: .4byte 0x0000046B
_08110BC0: .4byte 0x0000074C
_08110BC4: .4byte 0x00000744
_08110BC8: .4byte 0x00000746
_08110BCC: .4byte 0xFFFFFEFF
_08110BD0: .4byte 0x000004A4
_08110BD4:
	ldr r0, _08110BF0 @ =0xFFFFFDFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r0, #0
_08110BDE:
	cmp r0, #0
	bne _08110BF8
	ldr r2, _08110BF4 @ =0x000005C4
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	b _08110C6E
	.align 2, 0
_08110BF0: .4byte 0xFFFFFDFF
_08110BF4: .4byte 0x000005C4
_08110BF8:
	ldr r3, _08110C54 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r5, _08110C58 @ =0x0000046D
	adds r0, r6, r5
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	subs r5, #2
	adds r0, r6, r5
	strb r2, [r0]
	adds r5, #0xe8
	adds r0, r6, r5
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
	movs r3, #0x12
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r6, r5
	strb r1, [r0]
	adds r5, #1
	adds r0, r6, r5
	strb r1, [r0]
	ldr r1, _08110C5C @ =0x0000046A
	adds r0, r6, r1
	strb r3, [r0]
	adds r5, #0x1b
	adds r0, r6, r5
	str r2, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r4, [r0]
	ldr r1, _08110C60 @ =0x00000714
	add r1, r8
	movs r0, #0xa0
	lsls r0, r0, #1
	strh r0, [r1]
	b _08110C6E
	.align 2, 0
_08110C54: .4byte FUN_080e48d0
_08110C58: .4byte 0x0000046D
_08110C5C: .4byte 0x0000046A
_08110C60: .4byte 0x00000714
_08110C64:
	ldr r2, _08110C7C @ =0x00000484
	adds r1, r6, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08110C6E:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08110C7C: .4byte 0x00000484

	thumb_func_start FUN_08110c80
FUN_08110c80: @ 0x08110C80
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _08110CA8 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08110CAC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08110CAE
	.align 2, 0
_08110CA8: .4byte 0x0000046C
_08110CAC:
	movs r0, #0
_08110CAE:
	cmp r0, #0
	beq _08110CEE
	movs r0, #0x80
	lsls r0, r0, #1
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r6, r5
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _08110D64 @ =FUN_0810b7d4
	movs r2, #0x31
	ldr r0, _08110D68 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08110D6C @ =0x0000046B
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
_08110CEE:
	ldr r2, _08110D6C @ =0x0000046B
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08110CFA
	b _08110E14
_08110CFA:
	ldr r1, _08110D70 @ =0x00000744
	add r1, r8
	movs r0, #0x64
	strh r0, [r1]
	ldr r0, _08110D74 @ =0x0000074E
	add r0, r8
	ldrh r1, [r0]
	ldr r0, _08110D78 @ =0x00000746
	add r0, r8
	strh r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r5, r6, r0
	ldr r0, _08110D7C @ =0xFFFFFEFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	adds r4, r6, #0
	adds r4, #8
	movs r3, #0x80
	lsls r3, r3, #0xb
	adds r0, r6, #0
	mov r1, sp
	adds r2, r4, #0
	bl FUN_081077a4
	ldr r1, _08110D80 @ =0x000004A4
	adds r0, r6, r1
	ldr r7, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	beq _08110D84
	adds r0, r7, #0
	adds r1, r4, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08110D84
	cmp r0, #2
	beq _08110D5E
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08110D5E:
	movs r0, #1
	b _08110D8E
	.align 2, 0
_08110D64: .4byte FUN_0810b7d4
_08110D68: .4byte 0x0000046D
_08110D6C: .4byte 0x0000046B
_08110D70: .4byte 0x00000744
_08110D74: .4byte 0x0000074E
_08110D78: .4byte 0x00000746
_08110D7C: .4byte 0xFFFFFEFF
_08110D80: .4byte 0x000004A4
_08110D84:
	ldr r0, _08110DA0 @ =0xFFFFFDFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r0, #0
_08110D8E:
	cmp r0, #0
	bne _08110DA8
	ldr r2, _08110DA4 @ =0x000005C4
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	b _08110E1E
	.align 2, 0
_08110DA0: .4byte 0xFFFFFDFF
_08110DA4: .4byte 0x000005C4
_08110DA8:
	ldr r3, _08110E04 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r5, _08110E08 @ =0x0000046D
	adds r0, r6, r5
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	subs r5, #2
	adds r0, r6, r5
	strb r2, [r0]
	adds r5, #0xe8
	adds r0, r6, r5
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
	movs r3, #0x12
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r6, r5
	strb r1, [r0]
	adds r5, #1
	adds r0, r6, r5
	strb r1, [r0]
	ldr r1, _08110E0C @ =0x0000046A
	adds r0, r6, r1
	strb r3, [r0]
	adds r5, #0x1b
	adds r0, r6, r5
	str r2, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r4, [r0]
	ldr r1, _08110E10 @ =0x00000714
	add r1, r8
	movs r0, #0xa0
	lsls r0, r0, #1
	strh r0, [r1]
	b _08110E1E
	.align 2, 0
_08110E04: .4byte FUN_080e48d0
_08110E08: .4byte 0x0000046D
_08110E0C: .4byte 0x0000046A
_08110E10: .4byte 0x00000714
_08110E14:
	ldr r2, _08110E2C @ =0x00000484
	adds r1, r6, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08110E1E:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08110E2C: .4byte 0x00000484

	thumb_func_start FUN_08110e30
FUN_08110e30: @ 0x08110E30
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _08110E50 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08110E54
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08110E56
	.align 2, 0
_08110E50: .4byte 0x0000046C
_08110E54:
	movs r0, #0
_08110E56:
	cmp r0, #0
	beq _08110E96
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _08110EC8 @ =FUN_0810ba50
	movs r2, #0x35
	ldr r0, _08110ECC @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08110ED0 @ =0x0000046B
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
_08110E96:
	ldr r2, _08110ED0 @ =0x0000046B
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08110ED8
	movs r1, #0xea
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r2, #0xe9
	lsls r2, r2, #3
	adds r0, r7, r2
	strh r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, _08110ED4 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r6, #0
	bl FUN_081075dc
	b _08110EE2
	.align 2, 0
_08110EC8: .4byte FUN_0810ba50
_08110ECC: .4byte 0x0000046D
_08110ED0: .4byte 0x0000046B
_08110ED4: .4byte 0xFFFFFEFF
_08110ED8:
	ldr r2, _08110EE8 @ =0x00000484
	adds r1, r6, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08110EE2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08110EE8: .4byte 0x00000484

	thumb_func_start FUN_08110eec
FUN_08110eec: @ 0x08110EEC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _08110F14 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08110F18
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08110F1A
	.align 2, 0
_08110F14: .4byte 0x0000046C
_08110F18:
	movs r0, #0
_08110F1A:
	cmp r0, #0
	beq _08110F5A
	movs r0, #0x80
	lsls r0, r0, #1
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r6, r5
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _08110FC8 @ =FUN_0810b038
	movs r2, #0x3e
	ldr r0, _08110FCC @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08110FD0 @ =0x0000046B
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
_08110F5A:
	ldr r2, _08110FD0 @ =0x0000046B
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08110F66
	b _08111074
_08110F66:
	ldr r0, _08110FD4 @ =0x0000074C
	add r0, r8
	ldrh r1, [r0]
	ldr r0, _08110FD8 @ =0x00000744
	add r0, r8
	strh r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r5, r6, r0
	ldr r0, _08110FDC @ =0xFFFFFEFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	adds r4, r6, #0
	adds r4, #8
	movs r3, #0x80
	lsls r3, r3, #0xb
	adds r0, r6, #0
	mov r1, sp
	adds r2, r4, #0
	bl FUN_081077a4
	ldr r1, _08110FE0 @ =0x000004A4
	adds r0, r6, r1
	ldr r7, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	beq _08110FE4
	adds r0, r7, #0
	adds r1, r4, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08110FE4
	cmp r0, #2
	beq _08110FC2
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08110FC2:
	movs r0, #1
	b _08110FEE
	.align 2, 0
_08110FC8: .4byte FUN_0810b038
_08110FCC: .4byte 0x0000046D
_08110FD0: .4byte 0x0000046B
_08110FD4: .4byte 0x0000074C
_08110FD8: .4byte 0x00000744
_08110FDC: .4byte 0xFFFFFEFF
_08110FE0: .4byte 0x000004A4
_08110FE4:
	ldr r0, _08111000 @ =0xFFFFFDFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r0, #0
_08110FEE:
	cmp r0, #0
	bne _08111008
	ldr r2, _08111004 @ =0x000005C4
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	b _0811107E
	.align 2, 0
_08111000: .4byte 0xFFFFFDFF
_08111004: .4byte 0x000005C4
_08111008:
	ldr r3, _08111064 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r5, _08111068 @ =0x0000046D
	adds r0, r6, r5
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	subs r5, #2
	adds r0, r6, r5
	strb r2, [r0]
	adds r5, #0xe8
	adds r0, r6, r5
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
	movs r3, #0x12
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r6, r5
	strb r1, [r0]
	adds r5, #1
	adds r0, r6, r5
	strb r1, [r0]
	ldr r1, _0811106C @ =0x0000046A
	adds r0, r6, r1
	strb r3, [r0]
	adds r5, #0x1b
	adds r0, r6, r5
	str r2, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r4, [r0]
	ldr r1, _08111070 @ =0x00000714
	add r1, r8
	movs r0, #0xa0
	lsls r0, r0, #1
	strh r0, [r1]
	b _0811107E
	.align 2, 0
_08111064: .4byte FUN_080e48d0
_08111068: .4byte 0x0000046D
_0811106C: .4byte 0x0000046A
_08111070: .4byte 0x00000714
_08111074:
	ldr r2, _0811108C @ =0x00000484
	adds r1, r6, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0811107E:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0811108C: .4byte 0x00000484

	thumb_func_start FUN_08111090
FUN_08111090: @ 0x08111090
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _081110B8 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081110BC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081110BE
	.align 2, 0
_081110B8: .4byte 0x0000046C
_081110BC:
	movs r0, #0
_081110BE:
	cmp r0, #0
	beq _08111108
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _0811118C @ =FUN_0810b42c
	movs r2, #0x41
	ldr r7, _08111190 @ =0x0000046D
	adds r0, r6, r7
	movs r1, #1
	strb r1, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _08111194 @ =0x00000553
	adds r0, r6, r3
	strb r2, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r6, r7
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
	ldr r2, _08111198 @ =0x000006FC
	add r2, r8
	ldrh r0, [r2, #0x26]
	orrs r1, r0
	strh r1, [r2, #0x26]
_08111108:
	ldr r3, _0811119C @ =0x0000046B
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08111114
	b _0811124C
_08111114:
	ldr r2, _08111198 @ =0x000006FC
	add r2, r8
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r2, #0x26]
	ands r0, r1
	strh r0, [r2, #0x26]
	ldr r1, _081111A0 @ =0x00000744
	add r1, r8
	ldrh r0, [r1]
	adds r0, #0x64
	strh r0, [r1]
	ldr r0, _081111A4 @ =0x0000074E
	add r0, r8
	ldrh r1, [r0]
	ldr r0, _081111A8 @ =0x00000746
	add r0, r8
	strh r1, [r0]
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r5, r6, r7
	ldr r0, _081111AC @ =0xFFFFFEFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	adds r4, r6, #0
	adds r4, #8
	movs r3, #0x80
	lsls r3, r3, #0xb
	adds r0, r6, #0
	mov r1, sp
	adds r2, r4, #0
	bl FUN_081077a4
	ldr r1, _081111B0 @ =0x000004A4
	adds r0, r6, r1
	ldr r7, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	beq _081111B4
	adds r0, r7, #0
	adds r1, r4, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081111B4
	cmp r0, #2
	beq _08111188
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08111188:
	movs r0, #1
	b _081111BE
	.align 2, 0
_0811118C: .4byte FUN_0810b42c
_08111190: .4byte 0x0000046D
_08111194: .4byte 0x00000553
_08111198: .4byte 0x000006FC
_0811119C: .4byte 0x0000046B
_081111A0: .4byte 0x00000744
_081111A4: .4byte 0x0000074E
_081111A8: .4byte 0x00000746
_081111AC: .4byte 0xFFFFFEFF
_081111B0: .4byte 0x000004A4
_081111B4:
	ldr r0, _081111D0 @ =0xFFFFFDFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r0, #0
_081111BE:
	cmp r0, #0
	bne _081111D8
	ldr r2, _081111D4 @ =0x000005C4
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	b _08111256
	.align 2, 0
_081111D0: .4byte 0xFFFFFDFF
_081111D4: .4byte 0x000005C4
_081111D8:
	ldr r3, _08111230 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r5, _08111234 @ =0x0000046D
	adds r0, r6, r5
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r7, _08111238 @ =0x0000046B
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
	movs r3, #0x12
	subs r5, #0xeb
	adds r0, r6, r5
	strb r1, [r0]
	ldr r7, _0811123C @ =0x00000469
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _08111240 @ =0x0000046A
	adds r0, r6, r1
	strb r3, [r0]
	ldr r3, _08111244 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r6, r5
	strb r4, [r0]
	ldr r1, _08111248 @ =0x00000714
	add r1, r8
	movs r0, #0xa0
	lsls r0, r0, #1
	strh r0, [r1]
	b _08111256
	.align 2, 0
_08111230: .4byte FUN_080e48d0
_08111234: .4byte 0x0000046D
_08111238: .4byte 0x0000046B
_0811123C: .4byte 0x00000469
_08111240: .4byte 0x0000046A
_08111244: .4byte 0x00000484
_08111248: .4byte 0x00000714
_0811124C:
	ldr r7, _08111264 @ =0x00000484
	adds r1, r6, r7
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08111256:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08111264: .4byte 0x00000484

	thumb_func_start FUN_08111268
FUN_08111268: @ 0x08111268
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _08111290 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08111294
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08111296
	.align 2, 0
_08111290: .4byte 0x0000046C
_08111294:
	movs r0, #0
_08111296:
	cmp r0, #0
	beq _081112E2
	movs r0, #0x80
	lsls r0, r0, #1
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r6, r5
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _08111360 @ =FUN_0810b628
	movs r2, #0x44
	ldr r0, _08111364 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08111368 @ =0x0000046B
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
	ldr r2, _0811136C @ =0x000006FC
	add r2, r8
	movs r0, #2
	ldrh r1, [r2, #0x26]
	orrs r0, r1
	strh r0, [r2, #0x26]
_081112E2:
	ldr r2, _08111368 @ =0x0000046B
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081112EE
	b _08111408
_081112EE:
	ldr r2, _0811136C @ =0x000006FC
	add r2, r8
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2, #0x26]
	ands r0, r1
	strh r0, [r2, #0x26]
	movs r0, #0xea
	lsls r0, r0, #3
	add r0, r8
	ldrh r1, [r0]
	movs r0, #0xe9
	lsls r0, r0, #3
	add r0, r8
	strh r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r5, r6, r0
	ldr r0, _08111370 @ =0xFFFFFEFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	adds r4, r6, #0
	adds r4, #8
	movs r3, #0x80
	lsls r3, r3, #0xb
	adds r0, r6, #0
	mov r1, sp
	adds r2, r4, #0
	bl FUN_081077a4
	ldr r1, _08111374 @ =0x000004A4
	adds r0, r6, r1
	ldr r7, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	beq _08111378
	adds r0, r7, #0
	adds r1, r4, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08111378
	cmp r0, #2
	beq _0811135C
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811135C:
	movs r0, #1
	b _08111382
	.align 2, 0
_08111360: .4byte FUN_0810b628
_08111364: .4byte 0x0000046D
_08111368: .4byte 0x0000046B
_0811136C: .4byte 0x000006FC
_08111370: .4byte 0xFFFFFEFF
_08111374: .4byte 0x000004A4
_08111378:
	ldr r0, _08111394 @ =0xFFFFFDFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r0, #0
_08111382:
	cmp r0, #0
	bne _0811139C
	ldr r2, _08111398 @ =0x000005C4
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	b _08111412
	.align 2, 0
_08111394: .4byte 0xFFFFFDFF
_08111398: .4byte 0x000005C4
_0811139C:
	ldr r3, _081113F8 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r5, _081113FC @ =0x0000046D
	adds r0, r6, r5
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	subs r5, #2
	adds r0, r6, r5
	strb r2, [r0]
	adds r5, #0xe8
	adds r0, r6, r5
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
	movs r3, #0x12
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r6, r5
	strb r1, [r0]
	adds r5, #1
	adds r0, r6, r5
	strb r1, [r0]
	ldr r1, _08111400 @ =0x0000046A
	adds r0, r6, r1
	strb r3, [r0]
	adds r5, #0x1b
	adds r0, r6, r5
	str r2, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r4, [r0]
	ldr r1, _08111404 @ =0x00000714
	add r1, r8
	movs r0, #0xa0
	lsls r0, r0, #1
	strh r0, [r1]
	b _08111412
	.align 2, 0
_081113F8: .4byte FUN_080e48d0
_081113FC: .4byte 0x0000046D
_08111400: .4byte 0x0000046A
_08111404: .4byte 0x00000714
_08111408:
	ldr r2, _08111420 @ =0x00000484
	adds r1, r6, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08111412:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08111420: .4byte 0x00000484

	thumb_func_start FUN_08111424
FUN_08111424: @ 0x08111424
	ldr r1, _08111430 @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _08111434 @ =0x085AD52C
	str r1, [r0]
	bx lr
	.align 2, 0
_08111430: .4byte 0x0000063C
_08111434: .4byte 0x085AD52C

	thumb_func_start FUN_08111438
FUN_08111438: @ 0x08111438
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x104
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp, #0x18]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _08111484
	ldr r3, _08111474 @ =0x0000048A
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _0811147C
	ldr r0, _08111478 @ =0x00000211
	bl PlaySound_082406e0
	b _08111484
	.align 2, 0
_08111474: .4byte 0x0000048A
_08111478: .4byte 0x00000211
_0811147C:
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08111484:
	adds r0, r7, #0
	bl FUN_081086ac
	movs r0, #0x80
	lsls r0, r0, #6
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r1, r7, r4
	ldrh r3, [r1]
	adds r2, r3, #0
	ands r0, r2
	str r1, [sp, #0xf4]
	cmp r0, #0
	bne _081114A2
	b _08111C10
_081114A2:
	ldr r5, _0811152C @ =0x000001DD
	adds r0, r7, r5
	ldrb r0, [r0]
	adds r0, #0x80
	movs r4, #0
	strb r0, [r7, #5]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r0, _08111530 @ =0xFFFFDFDF
	ldr r6, [sp, #0xf4]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	ldr r0, _08111534 @ =0x00000544
	adds r1, r7, r0
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0x10
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r0, [r0]
	strh r4, [r0, #6]
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, _08111538 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r3, r7, r5
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
	str r3, [sp, #0xd4]
	str r2, [sp, #0xe8]
	cmp r5, #0
	blt _08111528
	cmp r1, #0
	blt _08111528
	ldr r0, _0811153C @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _08111528
	ldr r0, _08111540 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08111544
_08111528:
	movs r4, #0
	b _08111552
	.align 2, 0
_0811152C: .4byte 0x000001DD
_08111530: .4byte 0xFFFFDFDF
_08111534: .4byte 0x00000544
_08111538: .4byte 0x03002BE0
_0811153C: .4byte 0x030046A8
_08111540: .4byte 0x030046AC
_08111544:
	ldr r0, _08111564 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_08111552:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08111568
	adds r0, #4
	b _08111574
	.align 2, 0
_08111564: .4byte 0x030046A4
_08111568:
	ldr r0, _08111588 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08111574:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811158C
	cmp r2, #2
	beq _08111590
	b _08111594
	.align 2, 0
_08111588: .4byte 0x030046A4
_0811158C:
	ldrb r0, [r6, #4]
	b _08111592
_08111590:
	ldrb r0, [r6]
_08111592:
	subs r1, r1, r0
_08111594:
	strh r1, [r6, #2]
	ldr r0, _081115A8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081115AC
	movs r0, #1
	b _081115AE
	.align 2, 0
_081115A8: .4byte 0x030047A4
_081115AC:
	movs r0, #0
_081115AE:
	cmp r0, #0
	beq _081115EC
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081115CE
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081115CA
	adds r2, r0, #0
_081115CA:
	cmp r2, #0
	bge _081115D8
_081115CE:
	ldr r2, _081115D4 @ =0x000005C4
	adds r0, r7, r2
	b _08111B04
	.align 2, 0
_081115D4: .4byte 0x000005C4
_081115D8:
	ldr r1, _081115E8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08111634
	.align 2, 0
_081115E8: .4byte 0x03002BE0
_081115EC:
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
	blt _08111618
	cmp r1, #0
	blt _08111618
	ldr r0, _0811161C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08111618
	ldr r0, _08111620 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08111624
_08111618:
	movs r5, #0
	b _08111632
	.align 2, 0
_0811161C: .4byte 0x030046A8
_08111620: .4byte 0x030046AC
_08111624:
	ldr r0, _0811166C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08111632:
	movs r2, #0
_08111634:
	ldr r4, _08111670 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _08111654
	ldr r1, _08111674 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08111654
	b _08111A44
_08111654:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0xf4]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x1c]
	cmp r0, #0
	beq _08111678
	movs r0, #0
	b _08111B1A
	.align 2, 0
_0811166C: .4byte 0x030046A4
_08111670: .4byte 0x00000256
_08111674: .4byte 0x03002BE0
_08111678:
	ldr r6, _0811171C @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0xf4]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xfc]
	cmp r6, #0
	beq _08111730
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _08111720 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x20]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _08111724 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x24]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x28]
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x2c]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	mov r0, sp
	ldrh r0, [r0, #0x1c]
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r3, [r4]
	ldr r2, _08111728 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _0811172C @ =0x00000484
	adds r1, r7, r6
	ldr r0, [sp, #0x1c]
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x20]
	str r6, [sp, #0xcc]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0xc4]
	ldr r6, [sp, #0x28]
	str r6, [sp, #0xe4]
	ldr r6, [sp, #0x2c]
	str r6, [sp, #0xec]
	str r5, [sp, #0xf8]
	str r4, [sp, #0xb8]
	str r3, [sp, #0xbc]
	str r2, [sp, #0xc0]
	str r1, [sp, #0xd0]
	str r0, [sp, #0xc8]
	b _08111902
	.align 2, 0
_0811171C: .4byte 0x00000222
_08111720: .4byte 0x0000046D
_08111724: .4byte 0x0000046B
_08111728: .4byte 0x00000469
_0811172C: .4byte 0x00000484
_08111730:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _081117F4 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x30]
	strb r0, [r2]
	ldr r3, _081117F8 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x34]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _081117FC @ =0x00000553
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
	ldr r2, _08111800 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _08111804 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _08111808 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xd4]
	ldr r0, [r0]
	str r0, [sp, #0x48]
	ldr r1, [sp, #0xe8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x48]
	strh r1, [r6]
	ldr r6, [sp, #0xe8]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x48]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x30]
	str r0, [sp, #0xcc]
	ldr r6, [sp, #0x34]
	str r6, [sp, #0xc4]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0xe4]
	ldr r6, [sp, #0x3c]
	str r6, [sp, #0xec]
	ldr r0, [sp, #0x40]
	str r0, [sp, #0xf8]
	ldr r6, [sp, #0x44]
	str r6, [sp, #0xb8]
	str r5, [sp, #0xbc]
	str r4, [sp, #0xc0]
	str r3, [sp, #0xd0]
	str r2, [sp, #0xc8]
	mov r0, sl
	cmp r0, #0
	blt _081117EE
	cmp r1, #0
	blt _081117EE
	ldr r0, _0811180C @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _081117EE
	ldr r0, _08111810 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08111814
_081117EE:
	movs r4, #0
	b _08111824
	.align 2, 0
_081117F4: .4byte 0x0000046D
_081117F8: .4byte 0x0000046B
_081117FC: .4byte 0x00000553
_08111800: .4byte 0x00000469
_08111804: .4byte 0x00000484
_08111808: .4byte 0x0000046C
_0811180C: .4byte 0x030046A8
_08111810: .4byte 0x030046AC
_08111814:
	ldr r0, _08111834 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_08111824:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08111838
	adds r0, #4
	b _08111844
	.align 2, 0
_08111834: .4byte 0x030046A4
_08111838:
	ldr r0, _08111858 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08111844:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811185C
	cmp r2, #2
	beq _08111862
	b _08111868
	.align 2, 0
_08111858: .4byte 0x030046A4
_0811185C:
	ldr r2, [sp, #0x48]
	ldrb r0, [r2, #4]
	b _08111866
_08111862:
	ldr r3, [sp, #0x48]
	ldrb r0, [r3]
_08111866:
	subs r1, r1, r0
_08111868:
	ldr r4, [sp, #0x48]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xd4]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08111894
	cmp r1, #0
	blt _08111894
	ldr r0, _08111898 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08111894
	ldr r0, _0811189C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081118A0
_08111894:
	movs r4, #0
	b _081118AE
	.align 2, 0
_08111898: .4byte 0x030046A8
_0811189C: .4byte 0x030046AC
_081118A0:
	ldr r0, _081118C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081118AE:
	ldr r6, [sp, #0xd4]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081118C8
	adds r0, #4
	b _081118D4
	.align 2, 0
_081118C4: .4byte 0x030046A4
_081118C8:
	ldr r0, _081118E8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081118D4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081118EC
	cmp r3, #2
	beq _081118F0
	b _081118F4
	.align 2, 0
_081118E8: .4byte 0x030046A4
_081118EC:
	ldrb r0, [r5, #4]
	b _081118F2
_081118F0:
	ldrb r0, [r5]
_081118F2:
	subs r2, r2, r0
_081118F4:
	ldr r1, [sp, #0xd4]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xd4]
	ldr r0, [r2]
	strh r1, [r0, #6]
_08111902:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x4c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xf4]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r6, _0811192C @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _08111A0C
	movs r1, #4
	ldr r2, [sp, #0xfc]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08111930
	movs r0, #1
	b _08111932
	.align 2, 0
_0811192C: .4byte 0x00000482
_08111930:
	movs r0, #0
_08111932:
	ldr r3, _08111A1C @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _08111A0C
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _08111A20 @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _08111A24 @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _08111A28 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	ldr r0, _08111A2C @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xd8]
	ldr r1, _08111A30 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xf0]
	ldr r2, _08111A34 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xdc]
	ldr r1, _08111A38 @ =0x030046B8
	str r4, [sp, #0x100]
_08111978:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _08111A3C @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _08111A40 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x100]
	cmp r0, r2
	bne _0811199E
	adds r3, #1
	cmp r3, #3
	ble _08111978
	adds r0, r4, #0
_0811199E:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xec]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xe4]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xbc]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xc0]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe0]
	strb r0, [r6]
	add r0, sp, #0x4c
	ldrb r1, [r0]
	ldr r0, [sp, #0xd8]
	strb r1, [r0]
	ldr r1, [sp, #0xf0]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xcc]
	strb r1, [r4]
	ldr r6, [sp, #0xc4]
	strb r3, [r6]
	ldr r4, [sp, #0xe4]
	strb r0, [r4]
	ldr r6, [sp, #0xec]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0xf8]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xb8]
	strb r0, [r4]
	ldr r6, [sp, #0xbc]
	strb r1, [r6]
	ldr r0, [sp, #0xc0]
	strb r2, [r0]
	ldr r2, [sp, #0xd0]
	str r3, [r2]
	ldr r3, [sp, #0xc8]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xdc]
	strb r0, [r4]
_08111A0C:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _08111B1A
	.align 2, 0
_08111A1C: .4byte 0x00000482
_08111A20: .4byte 0x0000054F
_08111A24: .4byte 0x0000054D
_08111A28: .4byte 0x0000054E
_08111A2C: .4byte 0x00000541
_08111A30: .4byte 0x000005BC
_08111A34: .4byte 0x00000542
_08111A38: .4byte 0x030046B8
_08111A3C: .4byte 0x000003FF
_08111A40: .4byte 0x0203B400
_08111A44:
	mov sb, sp
	ldr r6, _08111A80 @ =0x030046A4
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
	beq _08111A84
	adds r0, #4
	b _08111A8E
	.align 2, 0
_08111A80: .4byte 0x030046A4
_08111A84:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08111A8E:
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
	ldr r6, _08111AC8 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _08111AD0
	ldr r0, _08111ACC @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08111AFA
	.align 2, 0
_08111AC8: .4byte 0x000004A4
_08111ACC: .4byte 0xFFFFFDFF
_08111AD0:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08111AF0
	cmp r0, #2
	beq _08111AEC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08111AEC:
	movs r0, #1
	b _08111AFC
_08111AF0:
	ldr r0, _08111B10 @ =0xFFFFFDFF
	ldr r3, [sp, #0xf4]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08111AFA:
	movs r0, #0
_08111AFC:
	cmp r0, #0
	bne _08111B18
	ldr r4, _08111B14 @ =0x000005C4
	adds r0, r7, r4
_08111B04:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _08111B1A
	.align 2, 0
_08111B10: .4byte 0xFFFFFDFF
_08111B14: .4byte 0x000005C4
_08111B18:
	movs r0, #1
_08111B1A:
	cmp r0, #0
	bne _08111BA0
	ldr r5, _08111B50 @ =0x000004A4
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
	bne _08111B58
	ldr r0, _08111B54 @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08111B82
	.align 2, 0
_08111B50: .4byte 0x000004A4
_08111B54: .4byte 0xFFFFFDFF
_08111B58:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08111B78
	cmp r0, #2
	beq _08111B74
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08111B74:
	movs r0, #1
	b _08111B84
_08111B78:
	ldr r0, _08111B98 @ =0xFFFFFDFF
	ldr r3, [sp, #0xf4]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08111B82:
	movs r0, #0
_08111B84:
	cmp r0, #0
	bne _08111BA0
	ldr r4, _08111B9C @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	bl _08112C40
	.align 2, 0
_08111B98: .4byte 0xFFFFFDFF
_08111B9C: .4byte 0x000005C4
_08111BA0:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _08111BFC @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _08111C00 @ =0x0000046B
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
	ldr r6, _08111C04 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08111C08 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _08111C0C @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #3
	bl FUN_08112498
	.align 2, 0
_08111BFC: .4byte 0x0000046D
_08111C00: .4byte 0x0000046B
_08111C04: .4byte 0x00000469
_08111C08: .4byte 0x0000046A
_08111C0C: .4byte 0x00000484
_08111C10:
	ldr r4, _08111C24 @ =0x00008002
	ands r4, r2
	cmp r4, #0
	beq _08111C28
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r3
	ldr r1, [sp, #0xf4]
	bl FUN_08112c3e
	.align 2, 0
_08111C24: .4byte 0x00008002
_08111C28:
	ldr r2, _08111C9C @ =0x0000049C
	adds r0, r7, r2
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _08111CC0
	ldr r3, _08111CA0 @ =0x000005CC
	adds r0, r7, r3
	ldr r2, [r0]
	movs r1, #0x12
	ldr r5, _08111CA4 @ =0x0000046D
	adds r0, r7, r5
	movs r3, #1
	strb r3, [r0]
	ldr r6, _08111CA8 @ =0x0000046B
	adds r0, r7, r6
	strb r4, [r0]
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
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _08111CAC @ =0x00000469
	adds r0, r7, r6
	strb r2, [r0]
	ldr r1, _08111CB0 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _08111CB4 @ =0x00000484
	adds r0, r7, r2
	str r4, [r0]
	ldr r4, _08111CB8 @ =0x0000046C
	adds r0, r7, r4
	strb r3, [r0]
	movs r5, #0xbe
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r1, _08111CBC @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #1
	bl _08112C42
	.align 2, 0
_08111C9C: .4byte 0x0000049C
_08111CA0: .4byte 0x000005CC
_08111CA4: .4byte 0x0000046D
_08111CA8: .4byte 0x0000046B
_08111CAC: .4byte 0x00000469
_08111CB0: .4byte 0x0000046A
_08111CB4: .4byte 0x00000484
_08111CB8: .4byte 0x0000046C
_08111CBC: .4byte 0xFEFFFFFF
_08111CC0:
	movs r4, #0x21
	rsbs r4, r4, #0
	ands r4, r3
	ldr r6, [sp, #0xf4]
	strh r4, [r6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _08111CD8
	bl _08112C40
_08111CD8:
	ldr r1, _08111D38 @ =0x000004BE
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08111CE6
	bl _08112C40
_08111CE6:
	movs r2, #0x80
	lsls r2, r2, #0x14
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _08111CFE
	bl _08112C40
_08111CFE:
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	bne _08111D08
	b _081124B0
_08111D08:
	ldr r4, _08111D3C @ =0x0000048D
	adds r2, r7, r4
	ldrb r0, [r2]
	cmp r0, #0
	bne _08111D44
	ldr r6, _08111D40 @ =0x0000048C
	adds r0, r7, r6
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08111D44
	ldr r1, _08111D38 @ =0x000004BE
	adds r0, r7, r1
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
	movs r0, #1
	b _08111D46
	.align 2, 0
_08111D38: .4byte 0x000004BE
_08111D3C: .4byte 0x0000048D
_08111D40: .4byte 0x0000048C
_08111D44:
	movs r0, #0
_08111D46:
	cmp r0, #0
	beq _08111D50
	ldr r0, _08111DC0 @ =0x000003A7
	bl PlaySound_082406e0
_08111D50:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r0, [r2]
	cmp r0, #0
	bne _08111D60
	bl _08112C40
_08111D60:
	movs r1, #0x80
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	movs r0, #4
	ldr r4, _08111DC4 @ =0x00000222
	adds r3, r7, r4
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _08111DC8 @ =0x03002BE0
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
	str r4, [sp, #0xd4]
	str r2, [sp, #0xe8]
	str r3, [sp, #0xfc]
	cmp r5, #0
	blt _08111DBA
	cmp r1, #0
	blt _08111DBA
	ldr r0, _08111DCC @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _08111DBA
	ldr r0, _08111DD0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08111DD4
_08111DBA:
	movs r4, #0
	b _08111DE2
	.align 2, 0
_08111DC0: .4byte 0x000003A7
_08111DC4: .4byte 0x00000222
_08111DC8: .4byte 0x03002BE0
_08111DCC: .4byte 0x030046A8
_08111DD0: .4byte 0x030046AC
_08111DD4:
	ldr r0, _08111DF4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_08111DE2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08111DF8
	adds r0, #4
	b _08111E04
	.align 2, 0
_08111DF4: .4byte 0x030046A4
_08111DF8:
	ldr r0, _08111E18 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08111E04:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08111E1C
	cmp r2, #2
	beq _08111E20
	b _08111E24
	.align 2, 0
_08111E18: .4byte 0x030046A4
_08111E1C:
	ldrb r0, [r6, #4]
	b _08111E22
_08111E20:
	ldrb r0, [r6]
_08111E22:
	subs r1, r1, r0
_08111E24:
	strh r1, [r6, #2]
	ldr r0, _08111E38 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08111E3C
	movs r0, #1
	b _08111E3E
	.align 2, 0
_08111E38: .4byte 0x030047A4
_08111E3C:
	movs r0, #0
_08111E3E:
	cmp r0, #0
	beq _08111E7C
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _08111E5E
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _08111E5A
	adds r2, r0, #0
_08111E5A:
	cmp r2, #0
	bge _08111E68
_08111E5E:
	ldr r1, _08111E64 @ =0x000005C4
	adds r0, r7, r1
	b _08112398
	.align 2, 0
_08111E64: .4byte 0x000005C4
_08111E68:
	ldr r1, _08111E78 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08111EC4
	.align 2, 0
_08111E78: .4byte 0x03002BE0
_08111E7C:
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
	blt _08111EA8
	cmp r1, #0
	blt _08111EA8
	ldr r0, _08111EAC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08111EA8
	ldr r0, _08111EB0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08111EB4
_08111EA8:
	movs r5, #0
	b _08111EC2
	.align 2, 0
_08111EAC: .4byte 0x030046A8
_08111EB0: .4byte 0x030046AC
_08111EB4:
	ldr r0, _08111EFC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08111EC2:
	movs r2, #0
_08111EC4:
	ldr r3, _08111F00 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _08111EE4
	ldr r1, _08111F04 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08111EE4
	b _081122D4
_08111EE4:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xf4]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x50]
	cmp r0, #0
	beq _08111F08
	movs r0, #0
	b _081123AE
	.align 2, 0
_08111EFC: .4byte 0x030046A4
_08111F00: .4byte 0x00000256
_08111F04: .4byte 0x03002BE0
_08111F08:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r5, [sp, #0xfc]
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	movs r1, #0x80
	ldr r6, [sp, #0xf4]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _08111FC4
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _08111FA8 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x54]
	movs r3, #1
	strb r3, [r2]
	ldr r4, _08111FAC @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x58]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _08111FB0 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x5c]
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x60]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	add r2, sp, #0x50
	ldrh r2, [r2]
	strh r2, [r5]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _08111FB4 @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _08111FB8 @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _08111FBC @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x50]
	str r6, [r1]
	ldr r6, _08111FC0 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x54]
	str r6, [sp, #0xcc]
	ldr r6, [sp, #0x58]
	str r6, [sp, #0xc4]
	ldr r6, [sp, #0x5c]
	str r6, [sp, #0xe4]
	ldr r6, [sp, #0x60]
	str r6, [sp, #0xec]
	str r5, [sp, #0xf8]
	str r4, [sp, #0xb8]
	str r3, [sp, #0xbc]
	str r2, [sp, #0xc0]
	str r1, [sp, #0xd0]
	str r0, [sp, #0xc8]
	b _08112192
	.align 2, 0
_08111FA8: .4byte 0x0000046D
_08111FAC: .4byte 0x0000046B
_08111FB0: .4byte 0x00000553
_08111FB4: .4byte 0x00000469
_08111FB8: .4byte 0x0000046A
_08111FBC: .4byte 0x00000484
_08111FC0: .4byte 0x0000046C
_08111FC4:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, _08112084 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x64]
	strb r0, [r3]
	ldr r4, _08112088 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x68]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _0811208C @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x6c]
	strb r0, [r6]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x70]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x74]
	strh r2, [r4]
	movs r1, #5
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x78]
	movs r6, #0
	strb r6, [r5]
	ldr r3, _08112090 @ =0x00000469
	adds r5, r7, r3
	strb r6, [r5]
	ldr r6, _08112094 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _08112098 @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xd4]
	ldr r0, [r0]
	str r0, [sp, #0x7c]
	ldr r1, [sp, #0xe8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x7c]
	strh r1, [r6]
	ldr r6, [sp, #0xe8]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x7c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x64]
	str r0, [sp, #0xcc]
	ldr r6, [sp, #0x68]
	str r6, [sp, #0xc4]
	ldr r0, [sp, #0x6c]
	str r0, [sp, #0xe4]
	ldr r6, [sp, #0x70]
	str r6, [sp, #0xec]
	ldr r0, [sp, #0x74]
	str r0, [sp, #0xf8]
	ldr r6, [sp, #0x78]
	str r6, [sp, #0xb8]
	str r5, [sp, #0xbc]
	str r4, [sp, #0xc0]
	str r3, [sp, #0xd0]
	str r2, [sp, #0xc8]
	mov r0, sb
	cmp r0, #0
	blt _08112080
	cmp r1, #0
	blt _08112080
	ldr r0, _0811209C @ =0x030046A8
	ldr r0, [r0]
	cmp sb, r0
	bhs _08112080
	ldr r0, _081120A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081120A4
_08112080:
	movs r4, #0
	b _081120B4
	.align 2, 0
_08112084: .4byte 0x0000046D
_08112088: .4byte 0x0000046B
_0811208C: .4byte 0x00000553
_08112090: .4byte 0x00000469
_08112094: .4byte 0x0000046A
_08112098: .4byte 0x00000484
_0811209C: .4byte 0x030046A8
_081120A0: .4byte 0x030046AC
_081120A4:
	ldr r0, _081120C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sb
	adds r4, r0, r1
_081120B4:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081120C8
	adds r0, #4
	b _081120D4
	.align 2, 0
_081120C4: .4byte 0x030046A4
_081120C8:
	ldr r0, _081120E8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081120D4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081120EC
	cmp r2, #2
	beq _081120F2
	b _081120F8
	.align 2, 0
_081120E8: .4byte 0x030046A4
_081120EC:
	ldr r2, [sp, #0x7c]
	ldrb r0, [r2, #4]
	b _081120F6
_081120F2:
	ldr r3, [sp, #0x7c]
	ldrb r0, [r3]
_081120F6:
	subs r1, r1, r0
_081120F8:
	ldr r4, [sp, #0x7c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xd4]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08112124
	cmp r1, #0
	blt _08112124
	ldr r0, _08112128 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08112124
	ldr r0, _0811212C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08112130
_08112124:
	movs r4, #0
	b _0811213E
	.align 2, 0
_08112128: .4byte 0x030046A8
_0811212C: .4byte 0x030046AC
_08112130:
	ldr r0, _08112154 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811213E:
	ldr r6, [sp, #0xd4]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08112158
	adds r0, #4
	b _08112164
	.align 2, 0
_08112154: .4byte 0x030046A4
_08112158:
	ldr r0, _08112178 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08112164:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0811217C
	cmp r3, #2
	beq _08112180
	b _08112184
	.align 2, 0
_08112178: .4byte 0x030046A4
_0811217C:
	ldrb r0, [r5, #4]
	b _08112182
_08112180:
	ldrb r0, [r5]
_08112182:
	subs r2, r2, r0
_08112184:
	ldr r1, [sp, #0xd4]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xd4]
	ldr r0, [r2]
	strh r1, [r0, #6]
_08112192:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x80]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xf4]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r6, _081121BC @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _0811229C
	movs r1, #4
	ldr r2, [sp, #0xfc]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081121C0
	movs r0, #1
	b _081121C2
	.align 2, 0
_081121BC: .4byte 0x00000482
_081121C0:
	movs r0, #0
_081121C2:
	ldr r3, _081122AC @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _0811229C
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _081122B0 @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _081122B4 @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _081122B8 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	ldr r0, _081122BC @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xd8]
	ldr r1, _081122C0 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xf0]
	ldr r2, _081122C4 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xdc]
	ldr r1, _081122C8 @ =0x030046B8
	str r4, [sp, #0x100]
_08112208:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _081122CC @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _081122D0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x100]
	cmp r0, r2
	bne _0811222E
	adds r3, #1
	cmp r3, #3
	ble _08112208
	adds r0, r4, #0
_0811222E:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xec]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xe4]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xbc]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xc0]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe0]
	strb r0, [r6]
	add r0, sp, #0x80
	ldrb r1, [r0]
	ldr r0, [sp, #0xd8]
	strb r1, [r0]
	ldr r1, [sp, #0xf0]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xcc]
	strb r1, [r4]
	ldr r6, [sp, #0xc4]
	strb r3, [r6]
	ldr r4, [sp, #0xe4]
	strb r0, [r4]
	ldr r6, [sp, #0xec]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0xf8]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xb8]
	strb r0, [r4]
	ldr r6, [sp, #0xbc]
	strb r1, [r6]
	ldr r0, [sp, #0xc0]
	strb r2, [r0]
	ldr r2, [sp, #0xd0]
	str r3, [r2]
	ldr r3, [sp, #0xc8]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xdc]
	strb r0, [r4]
_0811229C:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _081123AE
	.align 2, 0
_081122AC: .4byte 0x00000482
_081122B0: .4byte 0x0000054F
_081122B4: .4byte 0x0000054D
_081122B8: .4byte 0x0000054E
_081122BC: .4byte 0x00000541
_081122C0: .4byte 0x000005BC
_081122C4: .4byte 0x00000542
_081122C8: .4byte 0x030046B8
_081122CC: .4byte 0x000003FF
_081122D0: .4byte 0x0203B400
_081122D4:
	add r6, sp, #8
	ldr r0, _08112314 @ =0x030046A4
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
	beq _08112318
	adds r0, #4
	b _08112324
	.align 2, 0
_08112314: .4byte 0x030046A4
_08112318:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08112324:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0811235C @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _08112364
	ldr r0, _08112360 @ =0xFFFFFDFF
	ldr r6, [sp, #0xf4]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _0811238E
	.align 2, 0
_0811235C: .4byte 0x000004A4
_08112360: .4byte 0xFFFFFDFF
_08112364:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _08112384
	cmp r0, #2
	beq _08112380
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08112380:
	movs r0, #1
	b _08112390
_08112384:
	ldr r0, _081123A4 @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0811238E:
	movs r0, #0
_08112390:
	cmp r0, #0
	bne _081123AC
	ldr r3, _081123A8 @ =0x000005C4
	adds r0, r7, r3
_08112398:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081123AE
	.align 2, 0
_081123A4: .4byte 0xFFFFFDFF
_081123A8: .4byte 0x000005C4
_081123AC:
	movs r0, #1
_081123AE:
	adds r1, r0, #0
	cmp r1, #0
	bne _08112440
	ldr r4, [sp, #0x18]
	ldr r5, _081123EC @ =0x00000744
	adds r0, r4, r5
	strh r1, [r0]
	ldr r6, _081123F0 @ =0x000004A4
	adds r0, r7, r6
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
	bne _081123F8
	ldr r0, _081123F4 @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08112422
	.align 2, 0
_081123EC: .4byte 0x00000744
_081123F0: .4byte 0x000004A4
_081123F4: .4byte 0xFFFFFDFF
_081123F8:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08112418
	cmp r0, #2
	beq _08112414
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08112414:
	movs r0, #1
	b _08112424
_08112418:
	ldr r0, _08112438 @ =0xFFFFFDFF
	ldr r3, [sp, #0xf4]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08112422:
	movs r0, #0
_08112424:
	cmp r0, #0
	bne _08112440
	ldr r4, _0811243C @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	bl _08112C40
	.align 2, 0
_08112438: .4byte 0xFFFFFDFF
_0811243C: .4byte 0x000005C4
_08112440:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _081124A0 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _081124A4 @ =0x0000046B
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
	ldr r1, _081124A8 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _081124AC @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #2
FUN_08112498:
	strh r0, [r1]
	movs r0, #1
	b _08112C42
	.align 2, 0
_081124A0: .4byte 0x0000046D
_081124A4: .4byte 0x0000046B
_081124A8: .4byte 0x0000046A
_081124AC: .4byte 0x00000484
_081124B0:
	ldr r0, _081124E0 @ =0x0000048D
	adds r2, r7, r0
	ldrb r0, [r2]
	cmp r0, #0
	bne _081124EC
	ldr r1, _081124E4 @ =0x0000048C
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081124EC
	ldr r3, _081124E8 @ =0x000004BE
	adds r0, r7, r3
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
	movs r0, #1
	b _081124EE
	.align 2, 0
_081124E0: .4byte 0x0000048D
_081124E4: .4byte 0x0000048C
_081124E8: .4byte 0x000004BE
_081124EC:
	movs r0, #0
_081124EE:
	cmp r0, #0
	beq _081124F8
	ldr r0, _08112560 @ =0x000003A7
	bl PlaySound_082406e0
_081124F8:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	cmp r0, #0
	bne _08112506
	b _08112C40
_08112506:
	ldr r0, _08112564 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0x10
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #6]
	adds r3, r7, r5
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
	str r3, [sp, #0xd4]
	str r2, [sp, #0xe8]
	cmp r5, #0
	blt _0811255A
	cmp r1, #0
	blt _0811255A
	ldr r0, _08112568 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0811255A
	ldr r0, _0811256C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08112570
_0811255A:
	movs r4, #0
	b _0811257E
	.align 2, 0
_08112560: .4byte 0x000003A7
_08112564: .4byte 0x03002BE0
_08112568: .4byte 0x030046A8
_0811256C: .4byte 0x030046AC
_08112570:
	ldr r0, _08112590 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0811257E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08112594
	adds r0, #4
	b _081125A0
	.align 2, 0
_08112590: .4byte 0x030046A4
_08112594:
	ldr r0, _081125B4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081125A0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081125B8
	cmp r2, #2
	beq _081125BC
	b _081125C0
	.align 2, 0
_081125B4: .4byte 0x030046A4
_081125B8:
	ldrb r0, [r6, #4]
	b _081125BE
_081125BC:
	ldrb r0, [r6]
_081125BE:
	subs r1, r1, r0
_081125C0:
	strh r1, [r6, #2]
	ldr r0, _081125D4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081125D8
	movs r0, #1
	b _081125DA
	.align 2, 0
_081125D4: .4byte 0x030047A4
_081125D8:
	movs r0, #0
_081125DA:
	cmp r0, #0
	beq _08112618
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _081125FA
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081125F6
	adds r2, r0, #0
_081125F6:
	cmp r2, #0
	bge _08112604
_081125FA:
	ldr r1, _08112600 @ =0x000005C4
	adds r0, r7, r1
	b _08112B40
	.align 2, 0
_08112600: .4byte 0x000005C4
_08112604:
	ldr r1, _08112614 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _08112660
	.align 2, 0
_08112614: .4byte 0x03002BE0
_08112618:
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
	blt _08112644
	cmp r1, #0
	blt _08112644
	ldr r0, _08112648 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08112644
	ldr r0, _0811264C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08112650
_08112644:
	movs r5, #0
	b _0811265E
	.align 2, 0
_08112648: .4byte 0x030046A8
_0811264C: .4byte 0x030046AC
_08112650:
	ldr r0, _08112698 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0811265E:
	movs r2, #0
_08112660:
	ldr r3, _0811269C @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _08112680
	ldr r1, _081126A0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08112680
	b _08112A7C
_08112680:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xf4]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x84]
	cmp r0, #0
	beq _081126A4
	movs r0, #0
	b _08112B56
	.align 2, 0
_08112698: .4byte 0x030046A4
_0811269C: .4byte 0x00000256
_081126A0: .4byte 0x03002BE0
_081126A4:
	ldr r5, _08112748 @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r6, [sp, #0xf4]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	str r2, [sp, #0xfc]
	cmp r0, #0
	beq _08112768
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _0811274C @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x88]
	movs r3, #1
	strb r3, [r2]
	ldr r4, _08112750 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x8c]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _08112754 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x90]
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x94]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	add r2, sp, #0x84
	ldrh r2, [r2]
	strh r2, [r5]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _08112758 @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _0811275C @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _08112760 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x84]
	str r6, [r1]
	ldr r6, _08112764 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x88]
	str r6, [sp, #0xcc]
	ldr r6, [sp, #0x8c]
	str r6, [sp, #0xc4]
	ldr r6, [sp, #0x90]
	str r6, [sp, #0xe4]
	ldr r6, [sp, #0x94]
	str r6, [sp, #0xec]
	str r5, [sp, #0xf8]
	str r4, [sp, #0xb8]
	str r3, [sp, #0xbc]
	str r2, [sp, #0xc0]
	str r1, [sp, #0xd0]
	str r0, [sp, #0xc8]
	b _0811293A
	.align 2, 0
_08112748: .4byte 0x00000222
_0811274C: .4byte 0x0000046D
_08112750: .4byte 0x0000046B
_08112754: .4byte 0x00000553
_08112758: .4byte 0x00000469
_0811275C: .4byte 0x0000046A
_08112760: .4byte 0x00000484
_08112764: .4byte 0x0000046C
_08112768:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0811282C @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x98]
	strb r0, [r2]
	ldr r3, _08112830 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x9c]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _08112834 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0xa0]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xa8]
	mov r2, ip
	strh r2, [r1]
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xac]
	strb r4, [r3]
	ldr r4, _08112838 @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r2, _0811283C @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r6, _08112840 @ =0x00000484
	adds r3, r7, r6
	mov r1, ip
	str r1, [r3]
	subs r6, #0x18
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xd4]
	ldr r0, [r0]
	str r0, [sp, #0xb0]
	ldr r1, [sp, #0xe8]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0xb0]
	strh r1, [r6]
	ldr r6, [sp, #0xe8]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0xb0]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov r8, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x98]
	str r0, [sp, #0xcc]
	ldr r6, [sp, #0x9c]
	str r6, [sp, #0xc4]
	ldr r0, [sp, #0xa0]
	str r0, [sp, #0xe4]
	ldr r6, [sp, #0xa4]
	str r6, [sp, #0xec]
	ldr r0, [sp, #0xa8]
	str r0, [sp, #0xf8]
	ldr r6, [sp, #0xac]
	str r6, [sp, #0xb8]
	str r5, [sp, #0xbc]
	str r4, [sp, #0xc0]
	str r3, [sp, #0xd0]
	str r2, [sp, #0xc8]
	mov r0, r8
	cmp r0, #0
	blt _08112828
	cmp r1, #0
	blt _08112828
	ldr r0, _08112844 @ =0x030046A8
	ldr r0, [r0]
	cmp r8, r0
	bhs _08112828
	ldr r0, _08112848 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811284C
_08112828:
	movs r4, #0
	b _0811285C
	.align 2, 0
_0811282C: .4byte 0x0000046D
_08112830: .4byte 0x0000046B
_08112834: .4byte 0x00000553
_08112838: .4byte 0x00000469
_0811283C: .4byte 0x0000046A
_08112840: .4byte 0x00000484
_08112844: .4byte 0x030046A8
_08112848: .4byte 0x030046AC
_0811284C:
	ldr r0, _0811286C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, r8
	adds r4, r0, r1
_0811285C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08112870
	adds r0, #4
	b _0811287C
	.align 2, 0
_0811286C: .4byte 0x030046A4
_08112870:
	ldr r0, _08112890 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811287C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08112894
	cmp r2, #2
	beq _0811289A
	b _081128A0
	.align 2, 0
_08112890: .4byte 0x030046A4
_08112894:
	ldr r2, [sp, #0xb0]
	ldrb r0, [r2, #4]
	b _0811289E
_0811289A:
	ldr r3, [sp, #0xb0]
	ldrb r0, [r3]
_0811289E:
	subs r1, r1, r0
_081128A0:
	ldr r4, [sp, #0xb0]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xd4]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081128CC
	cmp r1, #0
	blt _081128CC
	ldr r0, _081128D0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081128CC
	ldr r0, _081128D4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081128D8
_081128CC:
	movs r4, #0
	b _081128E6
	.align 2, 0
_081128D0: .4byte 0x030046A8
_081128D4: .4byte 0x030046AC
_081128D8:
	ldr r0, _081128FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081128E6:
	ldr r6, [sp, #0xd4]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08112900
	adds r0, #4
	b _0811290C
	.align 2, 0
_081128FC: .4byte 0x030046A4
_08112900:
	ldr r0, _08112920 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811290C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08112924
	cmp r3, #2
	beq _08112928
	b _0811292C
	.align 2, 0
_08112920: .4byte 0x030046A4
_08112924:
	ldrb r0, [r5, #4]
	b _0811292A
_08112928:
	ldrb r0, [r5]
_0811292A:
	subs r2, r2, r0
_0811292C:
	ldr r1, [sp, #0xd4]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xd4]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0811293A:
	ldrb r3, [r7, #5]
	str r3, [sp, #0xb4]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xf4]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r6, _08112964 @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _08112A44
	movs r1, #4
	ldr r2, [sp, #0xfc]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08112968
	movs r0, #1
	b _0811296A
	.align 2, 0
_08112964: .4byte 0x00000482
_08112968:
	movs r0, #0
_0811296A:
	ldr r3, _08112A54 @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _08112A44
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _08112A58 @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _08112A5C @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _08112A60 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	ldr r0, _08112A64 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xd8]
	ldr r1, _08112A68 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xf0]
	ldr r2, _08112A6C @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xdc]
	ldr r1, _08112A70 @ =0x030046B8
	str r4, [sp, #0x100]
_081129B0:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _08112A74 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _08112A78 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x100]
	cmp r0, r2
	bne _081129D6
	adds r3, #1
	cmp r3, #3
	ble _081129B0
	adds r0, r4, #0
_081129D6:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xec]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xe4]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xbc]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xc0]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe0]
	strb r0, [r6]
	add r0, sp, #0xb4
	ldrb r1, [r0]
	ldr r0, [sp, #0xd8]
	strb r1, [r0]
	ldr r1, [sp, #0xf0]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xcc]
	strb r1, [r4]
	ldr r6, [sp, #0xc4]
	strb r3, [r6]
	ldr r4, [sp, #0xe4]
	strb r0, [r4]
	ldr r6, [sp, #0xec]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0xf8]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xb8]
	strb r0, [r4]
	ldr r6, [sp, #0xbc]
	strb r1, [r6]
	ldr r0, [sp, #0xc0]
	strb r2, [r0]
	ldr r2, [sp, #0xd0]
	str r3, [r2]
	ldr r3, [sp, #0xc8]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xdc]
	strb r0, [r4]
_08112A44:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _08112B56
	.align 2, 0
_08112A54: .4byte 0x00000482
_08112A58: .4byte 0x0000054F
_08112A5C: .4byte 0x0000054D
_08112A60: .4byte 0x0000054E
_08112A64: .4byte 0x00000541
_08112A68: .4byte 0x000005BC
_08112A6C: .4byte 0x00000542
_08112A70: .4byte 0x030046B8
_08112A74: .4byte 0x000003FF
_08112A78: .4byte 0x0203B400
_08112A7C:
	add r6, sp, #0x10
	ldr r0, _08112ABC @ =0x030046A4
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
	beq _08112AC0
	adds r0, #4
	b _08112ACC
	.align 2, 0
_08112ABC: .4byte 0x030046A4
_08112AC0:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08112ACC:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _08112B04 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _08112B0C
	ldr r0, _08112B08 @ =0xFFFFFDFF
	ldr r6, [sp, #0xf4]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _08112B36
	.align 2, 0
_08112B04: .4byte 0x000004A4
_08112B08: .4byte 0xFFFFFDFF
_08112B0C:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _08112B2C
	cmp r0, #2
	beq _08112B28
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08112B28:
	movs r0, #1
	b _08112B38
_08112B2C:
	ldr r0, _08112B4C @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08112B36:
	movs r0, #0
_08112B38:
	cmp r0, #0
	bne _08112B54
	ldr r3, _08112B50 @ =0x000005C4
	adds r0, r7, r3
_08112B40:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _08112B56
	.align 2, 0
_08112B4C: .4byte 0xFFFFFDFF
_08112B50: .4byte 0x000005C4
_08112B54:
	movs r0, #1
_08112B56:
	adds r1, r0, #0
	cmp r1, #0
	bne _08112BE8
	ldr r4, [sp, #0x18]
	ldr r5, _08112B94 @ =0x00000744
	adds r0, r4, r5
	strh r1, [r0]
	ldr r6, _08112B98 @ =0x000004A4
	adds r0, r7, r6
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
	bne _08112BA0
	ldr r0, _08112B9C @ =0xFFFFFDFF
	ldr r2, [sp, #0xf4]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08112BCA
	.align 2, 0
_08112B94: .4byte 0x00000744
_08112B98: .4byte 0x000004A4
_08112B9C: .4byte 0xFFFFFDFF
_08112BA0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08112BC0
	cmp r0, #2
	beq _08112BBC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08112BBC:
	movs r0, #1
	b _08112BCC
_08112BC0:
	ldr r0, _08112BE0 @ =0xFFFFFDFF
	ldr r3, [sp, #0xf4]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_08112BCA:
	movs r0, #0
_08112BCC:
	cmp r0, #0
	bne _08112BE8
	ldr r4, _08112BE4 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _08112C40
	.align 2, 0
_08112BE0: .4byte 0xFFFFFDFF
_08112BE4: .4byte 0x000005C4
_08112BE8:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _08112C54 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _08112C58 @ =0x0000046B
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
	ldr r6, _08112C5C @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _08112C60 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _08112C64 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #2
FUN_08112c3e:
	strh r0, [r1]
_08112C40:
	movs r0, #0
_08112C42:
	add sp, #0x104
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08112C54: .4byte 0x0000046D
_08112C58: .4byte 0x0000046B
_08112C5C: .4byte 0x00000469
_08112C60: .4byte 0x0000046A
_08112C64: .4byte 0x00000484

	thumb_func_start FUN_08112c68
FUN_08112c68: @ 0x08112C68
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r1, #7
	mov r0, sp
	strh r1, [r0]
	movs r0, #5
	mov r1, sp
	bl FUN_080ec79c
	movs r0, #6
	mov r1, sp
	bl FUN_080ec79c
	movs r0, #7
	mov r1, sp
	bl FUN_080ec79c
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #0x21
	rsbs r2, r2, #0
	ldrh r0, [r1]
	ands r2, r0
	strh r2, [r1]
	ldr r0, _08112CC8 @ =0x00008002
	ands r0, r2
	cmp r0, #0
	bne _08112CC2
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _08112CCC
_08112CC2:
	movs r0, #0
	b _08112D30
	.align 2, 0
_08112CC8: .4byte 0x00008002
_08112CCC:
	ldr r6, _08112D38 @ =0x00000744
	adds r1, r4, r6
	ldrh r2, [r1]
	movs r6, #0
	ldrsh r0, [r1, r6]
	cmp r0, #0
	ble _08112CE0
	adds r0, r2, #0
	subs r0, #0x1e
	strh r0, [r1]
_08112CE0:
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _08112CEA
	strh r3, [r1]
_08112CEA:
	ldr r6, _08112D3C @ =0x00000746
	adds r1, r4, r6
	ldrh r2, [r1]
	movs r6, #0
	ldrsh r0, [r1, r6]
	cmp r0, #0
	ble _08112CFE
	adds r0, r2, #0
	subs r0, #0x1e
	strh r0, [r1]
_08112CFE:
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _08112D08
	strh r3, [r1]
_08112D08:
	movs r6, #0xe9
	lsls r6, r6, #3
	adds r1, r4, r6
	ldrh r2, [r1]
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0
	ble _08112D1E
	adds r0, r2, #0
	subs r0, #0x1e
	strh r0, [r1]
_08112D1E:
	movs r6, #0
	ldrsh r0, [r1, r6]
	cmp r0, #0
	bge _08112D28
	strh r3, [r1]
_08112D28:
	adds r0, r5, #0
	bl FUN_08104220
	movs r0, #1
_08112D30:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08112D38: .4byte 0x00000744
_08112D3C: .4byte 0x00000746

	thumb_func_start FUN_08112d40
FUN_08112d40: @ 0x08112D40
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #0x21
	rsbs r2, r2, #0
	ldrh r0, [r1]
	ands r2, r0
	strh r2, [r1]
	ldr r0, _08112DCC @ =0x00008002
	ands r0, r2
	cmp r0, #0
	beq _08112DE0
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r2
	cmp r0, #0
	bne _08112D7A
	b _08112E78
_08112D7A:
	ldr r5, _08112DD0 @ =0x03002BE0
	ldr r0, [r5]
	adds r0, #0x2c
	bl FUN_081f9d10
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08112E78
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _08112DD4 @ =0x00000546
	adds r0, r4, r3
	movs r6, #0x3c
	ldrh r0, [r0]
	cmp r1, r0
	bgt _08112DA2
	movs r6, #0x28
_08112DA2:
	ldr r0, [r5]
	adds r0, #0x2c
	ldr r5, _08112DD8 @ =0x0000022A
	adds r1, r4, r5
	ldrh r2, [r1]
	ldr r3, _08112DDC @ =0x00000232
	adds r1, r4, r3
	ldrh r3, [r1]
	adds r5, #0x1e
	adds r1, r4, r5
	ldr r1, [r1]
	str r1, [sp]
	subs r5, #0xe
	adds r1, r4, r5
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r1, r6, #0
	bl FUN_081f9b20
	b _08112E78
	.align 2, 0
_08112DCC: .4byte 0x00008002
_08112DD0: .4byte 0x03002BE0
_08112DD4: .4byte 0x00000546
_08112DD8: .4byte 0x0000022A
_08112DDC: .4byte 0x00000232
_08112DE0:
	ldr r1, _08112DF4 @ =0x000006FC
	adds r0, r5, r1
	movs r1, #1
	ldrh r0, [r0, #0x26]
	ands r0, r1
	cmp r0, #0
	beq _08112DF8
	movs r0, #1
	b _08112DFA
	.align 2, 0
_08112DF4: .4byte 0x000006FC
_08112DF8:
	movs r0, #0
_08112DFA:
	cmp r0, #0
	bne _08112E4C
	ldr r5, _08112E68 @ =0x03002BE0
	ldr r0, [r5]
	adds r0, #0x2c
	bl FUN_081f9d10
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08112E4C
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r2, _08112E6C @ =0x00000546
	adds r0, r4, r2
	movs r6, #0x3c
	ldrh r0, [r0]
	cmp r1, r0
	bgt _08112E26
	movs r6, #0x28
_08112E26:
	ldr r0, [r5]
	adds r0, #0x2c
	ldr r3, _08112E70 @ =0x0000022A
	adds r1, r4, r3
	ldrh r2, [r1]
	ldr r5, _08112E74 @ =0x00000232
	adds r1, r4, r5
	ldrh r3, [r1]
	adds r5, #0x16
	adds r1, r4, r5
	ldr r1, [r1]
	str r1, [sp]
	subs r5, #0xe
	adds r1, r4, r5
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r1, r6, #0
	bl FUN_081f9b20
_08112E4C:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08112E78
	adds r0, r4, #0
	bl FUN_08103cb0
	movs r0, #1
	b _08112E7A
	.align 2, 0
_08112E68: .4byte 0x03002BE0
_08112E6C: .4byte 0x00000546
_08112E70: .4byte 0x0000022A
_08112E74: .4byte 0x00000232
_08112E78:
	movs r0, #0
_08112E7A:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08112e84
FUN_08112e84: @ 0x08112E84
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _08112EAC @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08112EB0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08112EB2
	.align 2, 0
_08112EAC: .4byte 0x0000046C
_08112EB0:
	movs r0, #0
_08112EB2:
	cmp r0, #0
	beq _08112EF0
	ldr r4, _08112F54 @ =FUN_0810dd10
	movs r3, #0x3a
	ldr r0, _08112F58 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08112F5C @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	movs r2, #0xe6
	lsls r2, r2, #3
	add r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08112EF0:
	adds r0, r5, #0
	bl FUN_081058f4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08112F20
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08112F12
	b _081130AA
_08112F12:
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08112F20
	b _081130AA
_08112F20:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r3, _08112F60 @ =0x00000482
	adds r1, r5, r3
	movs r0, #2
	strh r0, [r1]
	ldr r1, _08112F64 @ =0x0000A02F
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08112F68
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08112F78
	.align 2, 0
_08112F54: .4byte FUN_0810dd10
_08112F58: .4byte 0x0000046D
_08112F5C: .4byte 0x0000046B
_08112F60: .4byte 0x00000482
_08112F64: .4byte 0x0000A02F
_08112F68:
	ldr r1, _08112F9C @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08112F78
	movs r0, #1
	strh r0, [r2]
_08112F78:
	ldr r3, _08112FA0 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08112FA4
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
	b _08112FBC
	.align 2, 0
_08112F9C: .4byte 0x00000482
_08112FA0: .4byte 0x0000025D
_08112FA4:
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
_08112FBC:
	ldr r0, _08113030 @ =0x000004A4
	adds r4, r5, r0
	ldr r0, [r4]
	bl FUN_08235fd8
	adds r6, r0, #0
	cmp r6, #0
	beq _0811304C
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081130A0
	movs r2, #0x10
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08113034 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _08113038 @ =0x0000046A
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _0811303C @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r0, r5, r3
	movs r2, #1
	strb r2, [r0]
	ldr r4, _08113040 @ =0x000005A4
	adds r0, r5, r4
	ldr r3, [r0]
	ldr r4, _08113044 @ =0x0000046D
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08113048 @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r1, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	b _081130AA
	.align 2, 0
_08113030: .4byte 0x000004A4
_08113034: .4byte 0x00000469
_08113038: .4byte 0x0000046A
_0811303C: .4byte 0x00000484
_08113040: .4byte 0x000005A4
_08113044: .4byte 0x0000046D
_08113048: .4byte 0x0000046B
_0811304C:
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5ed4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081130A0
	movs r1, #3
	movs r2, #1
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _08113098 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	ldr r3, _0811309C @ =0x0000046A
	adds r0, r5, r3
	strb r6, [r0]
	adds r4, #0x1c
	adds r0, r5, r4
	str r6, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r2, #0xe6
	lsls r2, r2, #3
	add r2, r8
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _081130AA
	.align 2, 0
_08113098: .4byte 0x00000469
_0811309C: .4byte 0x0000046A
_081130A0:
	ldr r2, _081130B8 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081130AA:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081130B8: .4byte 0x00000484

	thumb_func_start FUN_081130bc
FUN_081130bc: @ 0x081130BC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081130D4 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081130D8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081130DA
	.align 2, 0
_081130D4: .4byte 0x0000046C
_081130D8:
	movs r0, #0
_081130DA:
	cmp r0, #0
	beq _0811310E
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _08113194 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08113198 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
_0811310E:
	adds r0, r5, #0
	bl FUN_081058f4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811313A
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081131B2
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081131B2
_0811313A:
	ldr r2, _08113198 @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081131A8
	movs r2, #0xf
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r4, _0811319C @ =0x00000469
	adds r0, r5, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r1, [r0]
	ldr r2, _081131A0 @ =0x0000046C
	adds r0, r5, r2
	movs r2, #1
	strb r2, [r0]
	ldr r3, _081131A4 @ =0x000005A4
	adds r0, r5, r3
	ldr r3, [r0]
	subs r4, #0x17
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08113198 @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r1, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	b _081131B2
	.align 2, 0
_08113194: .4byte 0x0000046D
_08113198: .4byte 0x0000046B
_0811319C: .4byte 0x00000469
_081131A0: .4byte 0x0000046C
_081131A4: .4byte 0x000005A4
_081131A8:
	ldr r4, _081131B8 @ =0x00000484
	adds r1, r5, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081131B2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081131B8: .4byte 0x00000484

	thumb_func_start FUN_081131bc
FUN_081131bc: @ 0x081131BC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081131D4 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081131D8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081131DA
	.align 2, 0
_081131D4: .4byte 0x0000046C
_081131D8:
	movs r0, #0
_081131DA:
	cmp r0, #0
	beq _0811320E
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _08113294 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _08113298 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _0811329C @ =0x00000553
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
_0811320E:
	adds r0, r5, #0
	bl FUN_081058f4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811323A
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081132B6
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081132B6
_0811323A:
	ldr r2, _08113298 @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081132AC
	movs r2, #3
	movs r1, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r3, #0
	strb r2, [r0]
	ldr r6, _081132A0 @ =0x00000469
	adds r0, r5, r6
	strb r1, [r0]
	ldr r2, _081132A4 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r3, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	ldr r4, _081132A8 @ =FUN_0810da64
	movs r2, #0x3b
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08113298 @ =0x0000046B
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r3, [r0]
	b _081132B6
	.align 2, 0
_08113294: .4byte 0x0000046D
_08113298: .4byte 0x0000046B
_0811329C: .4byte 0x00000553
_081132A0: .4byte 0x00000469
_081132A4: .4byte 0x0000046A
_081132A8: .4byte FUN_0810da64
_081132AC:
	ldr r3, _081132BC @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081132B6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081132BC: .4byte 0x00000484

	thumb_func_start FUN_081132c0
FUN_081132c0: @ 0x081132C0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _081132E4 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081132E8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081132EA
	.align 2, 0
_081132E4: .4byte 0x0000046C
_081132E8:
	movs r0, #0
_081132EA:
	cmp r0, #0
	beq _08113328
	ldr r4, _08113368 @ =FUN_0810dd10
	movs r3, #0x3a
	ldr r0, _0811336C @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08113370 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08113328:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	mov r8, r0
	ldr r4, _08113374 @ =0x00000482
	adds r1, r5, r4
	movs r0, #2
	strh r0, [r1]
	ldr r1, _08113378 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0811337C
	adds r1, r5, r4
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0811338C
	.align 2, 0
_08113368: .4byte FUN_0810dd10
_0811336C: .4byte 0x0000046D
_08113370: .4byte 0x0000046B
_08113374: .4byte 0x00000482
_08113378: .4byte 0x0000A02F
_0811337C:
	ldr r3, _081133B0 @ =0x00000482
	adds r0, r5, r3
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0811338C
	movs r0, #1
	strh r0, [r2]
_0811338C:
	ldr r4, _081133B4 @ =0x0000025D
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _081133B8
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
	b _081133D0
	.align 2, 0
_081133B0: .4byte 0x00000482
_081133B4: .4byte 0x0000025D
_081133B8:
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
_081133D0:
	ldr r0, _08113448 @ =0x000004A4
	adds r4, r5, r0
	ldr r0, [r4]
	bl FUN_08235fd8
	adds r6, r0, #0
	cmp r6, #0
	beq _0811345C
	ldr r1, [r4]
	mov r2, r8
	str r2, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081133F8
	b _0811352A
_081133F8:
	movs r2, #0x13
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r4, _0811344C @ =0x00000469
	adds r0, r5, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r1, [r0]
	ldr r2, _08113450 @ =0x0000046C
	adds r0, r5, r2
	movs r2, #1
	strb r2, [r0]
	ldr r3, _08113454 @ =0x000005A4
	adds r0, r5, r3
	ldr r3, [r0]
	subs r4, #0x17
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08113458 @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r1, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	b _08113534
	.align 2, 0
_08113448: .4byte 0x000004A4
_0811344C: .4byte 0x00000469
_08113450: .4byte 0x0000046C
_08113454: .4byte 0x000005A4
_08113458: .4byte 0x0000046B
_0811345C:
	ldr r1, [r4]
	mov r4, r8
	str r4, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5ed4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811352A
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r2, r7, r1
	ldrh r1, [r2]
	movs r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [r0]
	ldr r0, _081134A0 @ =0x0003FFFF
	cmp r1, r0
	bhi _081134A4
	movs r2, #0x80
	lsls r2, r2, #0xd
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08107468
	b _08113534
	.align 2, 0
_081134A0: .4byte 0x0003FFFF
_081134A4:
	movs r1, #0x14
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	strb r3, [r0]
	ldr r2, _08113500 @ =0x00000469
	adds r0, r5, r2
	strb r3, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _08113504 @ =0x00000484
	adds r0, r5, r1
	str r6, [r0]
	adds r2, #3
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r4, _08113508 @ =0x000005A4
	adds r0, r5, r4
	ldr r2, [r0]
	ldr r4, _0811350C @ =0x0000046D
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _08113510 @ =0x0000046B
	adds r0, r5, r1
	strb r3, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r6, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	blt _08113514
	asrs r0, r0, #5
	b _0811351A
	.align 2, 0
_08113500: .4byte 0x00000469
_08113504: .4byte 0x00000484
_08113508: .4byte 0x000005A4
_0811350C: .4byte 0x0000046D
_08113510: .4byte 0x0000046B
_08113514:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0811351A:
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r4, #0xee
	lsls r4, r4, #1
	adds r1, r5, r4
	strb r0, [r1]
	b _08113534
_0811352A:
	ldr r0, _08113540 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08113534:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08113540: .4byte 0x00000484

	thumb_func_start FUN_08113544
FUN_08113544: @ 0x08113544
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0811355C @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08113560
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08113562
	.align 2, 0
_0811355C: .4byte 0x0000046C
_08113560:
	movs r0, #0
_08113562:
	cmp r0, #0
	beq _08113596
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _08113600 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08113604 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
_08113596:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	ldr r2, _08113604 @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08113614
	movs r2, #0x12
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r4, _08113608 @ =0x00000469
	adds r0, r5, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r1, [r0]
	ldr r2, _0811360C @ =0x0000046C
	adds r0, r5, r2
	movs r2, #1
	strb r2, [r0]
	ldr r3, _08113610 @ =0x000005A4
	adds r0, r5, r3
	ldr r3, [r0]
	subs r4, #0x17
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08113604 @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r1, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	b _0811361E
	.align 2, 0
_08113600: .4byte 0x0000046D
_08113604: .4byte 0x0000046B
_08113608: .4byte 0x00000469
_0811360C: .4byte 0x0000046C
_08113610: .4byte 0x000005A4
_08113614:
	ldr r4, _08113624 @ =0x00000484
	adds r1, r5, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0811361E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08113624: .4byte 0x00000484

	thumb_func_start FUN_08113628
FUN_08113628: @ 0x08113628
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08113648 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0811364C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0811364E
	.align 2, 0
_08113648: .4byte 0x0000046C
_0811364C:
	movs r0, #0
_0811364E:
	cmp r0, #0
	beq _08113692
	movs r3, #0xb2
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r4, [r0]
	movs r3, #2
	ldr r7, _081136F8 @ =0x0000046D
	adds r1, r5, r7
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081136FC @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #3
	movs r7, #0xe6
	lsls r7, r7, #3
	adds r2, r6, r7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08113692:
	ldr r1, _081136FC @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08113710
	movs r2, #3
	movs r1, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r3, #0
	strb r2, [r0]
	ldr r7, _08113700 @ =0x00000469
	adds r0, r5, r7
	strb r1, [r0]
	ldr r2, _08113704 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r7, #0x1b
	adds r0, r5, r7
	str r3, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	ldr r4, _08113708 @ =FUN_0810dbb0
	movs r2, #0x3b
	subs r7, #0x17
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _081136FC @ =0x0000046B
	adds r0, r5, r1
	strb r3, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r3, [r0]
	movs r3, #0xe6
	lsls r3, r3, #3
	adds r2, r6, r3
	ldr r0, _0811370C @ =0xFFFFFBFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0811371A
	.align 2, 0
_081136F8: .4byte 0x0000046D
_081136FC: .4byte 0x0000046B
_08113700: .4byte 0x00000469
_08113704: .4byte 0x0000046A
_08113708: .4byte FUN_0810dbb0
_0811370C: .4byte 0xFFFFFBFF
_08113710:
	ldr r7, _08113720 @ =0x00000484
	adds r1, r5, r7
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0811371A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08113720: .4byte 0x00000484

	thumb_func_start FUN_08113724
FUN_08113724: @ 0x08113724
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08113744 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08113748
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0811374A
	.align 2, 0
_08113744: .4byte 0x0000046C
_08113748:
	movs r0, #0
_0811374A:
	cmp r0, #0
	beq _0811378C
	ldr r4, _081137C0 @ =FUN_0810dd10
	movs r3, #0x3a
	ldr r0, _081137C4 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081137C8 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	ldr r1, _081137CC @ =0xFFFFFEFF
	ands r0, r1
	strh r0, [r2]
_0811378C:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r3, _081137D0 @ =0x00000482
	adds r1, r5, r3
	movs r0, #2
	strh r0, [r1]
	ldr r1, _081137D4 @ =0x0000A02F
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081137D8
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081137E8
	.align 2, 0
_081137C0: .4byte FUN_0810dd10
_081137C4: .4byte 0x0000046D
_081137C8: .4byte 0x0000046B
_081137CC: .4byte 0xFFFFFEFF
_081137D0: .4byte 0x00000482
_081137D4: .4byte 0x0000A02F
_081137D8:
	ldr r1, _0811380C @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081137E8
	movs r0, #1
	strh r0, [r2]
_081137E8:
	ldr r3, _08113810 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08113814
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
	b _0811382C
	.align 2, 0
_0811380C: .4byte 0x00000482
_08113810: .4byte 0x0000025D
_08113814:
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
_0811382C:
	ldr r0, _081138A4 @ =0x000004A4
	adds r4, r5, r0
	ldr r0, [r4]
	bl FUN_08235fd8
	adds r6, r0, #0
	cmp r6, #0
	beq _081138C0
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08113852
	b _0811395A
_08113852:
	movs r2, #0x16
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081138A8 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _081138AC @ =0x0000046A
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _081138B0 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r0, r5, r3
	movs r2, #1
	strb r2, [r0]
	ldr r4, _081138B4 @ =0x000005A4
	adds r0, r5, r4
	ldr r3, [r0]
	ldr r4, _081138B8 @ =0x0000046D
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _081138BC @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r1, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	b _0811395A
	.align 2, 0
_081138A4: .4byte 0x000004A4
_081138A8: .4byte 0x00000469
_081138AC: .4byte 0x0000046A
_081138B0: .4byte 0x00000484
_081138B4: .4byte 0x000005A4
_081138B8: .4byte 0x0000046D
_081138BC: .4byte 0x0000046B
_081138C0:
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5ed4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811395A
	movs r1, #0x17
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	strb r6, [r0]
	ldr r2, _08113930 @ =0x00000469
	adds r0, r5, r2
	strb r6, [r0]
	ldr r3, _08113934 @ =0x0000046A
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, #0x1c
	adds r0, r5, r4
	str r6, [r0]
	ldr r1, _08113938 @ =0x0000046C
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _0811393C @ =0x000005A4
	adds r0, r5, r2
	ldr r2, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	subs r4, #0x19
	adds r0, r5, r4
	strb r6, [r0]
	ldr r1, _08113940 @ =0x00000553
	adds r0, r5, r1
	strb r6, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r2, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r6, [r0]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	blt _08113944
	asrs r0, r0, #5
	b _0811394A
	.align 2, 0
_08113930: .4byte 0x00000469
_08113934: .4byte 0x0000046A
_08113938: .4byte 0x0000046C
_0811393C: .4byte 0x000005A4
_08113940: .4byte 0x00000553
_08113944:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0811394A:
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	b _08113964
_0811395A:
	ldr r3, _0811396C @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08113964:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0811396C: .4byte 0x00000484

	thumb_func_start FUN_08113970
FUN_08113970: @ 0x08113970
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08113988 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0811398C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0811398E
	.align 2, 0
_08113988: .4byte 0x0000046C
_0811398C:
	movs r0, #0
_0811398E:
	cmp r0, #0
	beq _081139C2
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _08113A1C @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08113A20 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
_081139C2:
	ldr r1, _08113A20 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08113A30
	movs r2, #0x15
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r4, _08113A24 @ =0x00000469
	adds r0, r5, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r1, [r0]
	ldr r2, _08113A28 @ =0x0000046C
	adds r0, r5, r2
	movs r2, #1
	strb r2, [r0]
	ldr r3, _08113A2C @ =0x000005A4
	adds r0, r5, r3
	ldr r3, [r0]
	subs r4, #0x17
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08113A20 @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	adds r4, #0xe6
	adds r0, r5, r4
	strb r1, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	b _08113A3A
	.align 2, 0
_08113A1C: .4byte 0x0000046D
_08113A20: .4byte 0x0000046B
_08113A24: .4byte 0x00000469
_08113A28: .4byte 0x0000046C
_08113A2C: .4byte 0x000005A4
_08113A30:
	ldr r4, _08113A40 @ =0x00000484
	adds r1, r5, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08113A3A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08113A40: .4byte 0x00000484

	thumb_func_start FUN_08113a44
FUN_08113a44: @ 0x08113A44
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r3, _08113A64 @ =0x0000046C
	adds r1, r6, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _08113A68
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08113A6A
	.align 2, 0
_08113A64: .4byte 0x0000046C
_08113A68:
	movs r0, #0
_08113A6A:
	cmp r0, #0
	beq _08113AAE
	movs r4, #0xb2
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r4, [r0]
	movs r3, #2
	ldr r0, _08113ADC @ =0x0000046D
	adds r1, r6, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08113AE0 @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r6, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #3
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08113AAE:
	ldr r3, _08113AE0 @ =0x0000046B
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08113ABA
	b _08113C04
_08113ABA:
	movs r4, #0xe6
	lsls r4, r4, #3
	adds r2, r7, r4
	ldr r0, _08113AE4 @ =0xFFFFFBFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08113AE8 @ =0x000006FC
	adds r0, r7, r1
	movs r1, #8
	ldrh r0, [r0, #0x26]
	ands r0, r1
	cmp r0, #0
	beq _08113AEC
	movs r0, #1
	b _08113AEE
	.align 2, 0
_08113ADC: .4byte 0x0000046D
_08113AE0: .4byte 0x0000046B
_08113AE4: .4byte 0xFFFFFBFF
_08113AE8: .4byte 0x000006FC
_08113AEC:
	movs r0, #0
_08113AEE:
	cmp r0, #0
	beq _08113B68
	ldr r2, _08113B50 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r3, _08113B54 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _08113B58 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r0, #9
	mov ip, r0
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	ldr r1, _08113B5C @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	adds r4, #2
	adds r0, r6, r4
	mov r1, ip
	strb r1, [r0]
	adds r4, #0x1a
	adds r0, r6, r4
	str r3, [r0]
	ldr r1, _08113B60 @ =0x0000046C
	adds r0, r6, r1
	strb r5, [r0]
	ldr r3, _08113B64 @ =0x000006FC
	adds r2, r7, r3
	movs r0, #9
	rsbs r0, r0, #0
	b _08113BE2
	.align 2, 0
_08113B50: .4byte FUN_080e48d0
_08113B54: .4byte 0x0000046D
_08113B58: .4byte 0x0000046B
_08113B5C: .4byte 0x00000469
_08113B60: .4byte 0x0000046C
_08113B64: .4byte 0x000006FC
_08113B68:
	ldr r4, _08113B7C @ =0x000006FC
	adds r0, r7, r4
	movs r1, #4
	ldrh r0, [r0, #0x26]
	ands r0, r1
	cmp r0, #0
	beq _08113B80
	movs r0, #1
	b _08113B82
	.align 2, 0
_08113B7C: .4byte 0x000006FC
_08113B80:
	movs r0, #0
_08113B82:
	cmp r0, #0
	beq _08113C0E
	ldr r2, _08113BEC @ =FUN_080e48d0
	movs r1, #0x10
	ldr r3, _08113BF0 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _08113BF4 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r0, #8
	mov ip, r0
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	ldr r1, _08113BF8 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	adds r4, #2
	adds r0, r6, r4
	mov r1, ip
	strb r1, [r0]
	adds r4, #0x1a
	adds r0, r6, r4
	str r3, [r0]
	ldr r1, _08113BFC @ =0x0000046C
	adds r0, r6, r1
	strb r5, [r0]
	ldr r3, _08113C00 @ =0x000006FC
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
_08113BE2:
	ldrh r1, [r2, #0x26]
	ands r0, r1
	strh r0, [r2, #0x26]
	b _08113C0E
	.align 2, 0
_08113BEC: .4byte FUN_080e48d0
_08113BF0: .4byte 0x0000046D
_08113BF4: .4byte 0x0000046B
_08113BF8: .4byte 0x00000469
_08113BFC: .4byte 0x0000046C
_08113C00: .4byte 0x000006FC
_08113C04:
	ldr r4, _08113C14 @ =0x00000484
	adds r1, r6, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08113C0E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08113C14: .4byte 0x00000484

	thumb_func_start FUN_08113c18
FUN_08113c18: @ 0x08113C18
	ldr r1, _08113C24 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _08113C28 @ =0x085AD558
	str r1, [r0]
	bx lr
	.align 2, 0
_08113C24: .4byte 0x00000634
_08113C28: .4byte 0x085AD558

	thumb_func_start FUN_08113c2c
FUN_08113c2c: @ 0x08113C2C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	ldr r1, _08113C44 @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _08113C48
	adds r0, r5, #0
	bl FUN_08108828
	b _08113C4E
	.align 2, 0
_08113C44: .4byte 0x000001DF
_08113C48:
	adds r0, r5, #0
	bl FUN_081088a0
_08113C4E:
	movs r1, #0x80
	lsls r1, r1, #6
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08113C6A
	ldr r1, _08113C98 @ =0x000004BE
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08113C8A
_08113C6A:
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrb r0, [r0]
	ldr r2, _08113C9C @ =0x0000062C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e4964
_08113C8A:
	adds r0, r5, #0
	bl FUN_081088c8
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08113C98: .4byte 0x000004BE
_08113C9C: .4byte 0x0000062C

	thumb_func_start FUN_08113ca0
FUN_08113ca0: @ 0x08113CA0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _08113CF4 @ =0x030047A4
	ldr r1, _08113CF8 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _08113CBC
	b _08113DD8
_08113CBC:
	movs r1, #4
	ldr r0, _08113CFC @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08113CCA
	b _08113DD8
_08113CCA:
	movs r0, #2
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _08113D9C
	movs r0, #0x92
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _08113D00 @ =0x030046A0
	ldr r0, [r0]
	adds r2, #0xd0
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08113D04
	movs r0, #1
	b _08113D06
	.align 2, 0
_08113CF4: .4byte 0x030047A4
_08113CF8: .4byte 0x030047A0
_08113CFC: .4byte 0x03002BC0
_08113D00: .4byte 0x030046A0
_08113D04:
	movs r0, #0
_08113D06:
	cmp r0, #0
	bne _08113D14
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080f07d0
	b _08113DD8
_08113D14:
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08113D5A
	movs r1, #0x10
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08113D34
	movs r0, #1
	b _08113D36
_08113D34:
	movs r0, #0
_08113D36:
	cmp r0, #0
	bne _08113D5A
	ldr r1, _08113D98 @ =0x00000624
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08113D5A
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08113D5A:
	adds r0, r4, #0
	bl FUN_080eafdc
	adds r0, r4, #0
	bl FUN_080e1f48
	movs r0, #0xb0
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ldr r1, [r1]
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e35b4
	adds r0, r4, #0
	bl FUN_080e191c
	adds r0, r4, #0
	bl FUN_080eb168
	adds r0, r4, #0
	bl FUN_080f06ac
	movs r0, #1
	b _08113DDA
	.align 2, 0
_08113D98: .4byte 0x00000624
_08113D9C:
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _08113DD2
	movs r0, #0x92
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _08113DC0 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08113DC4
	movs r0, #1
	b _08113DC6
	.align 2, 0
_08113DC0: .4byte 0x030046A0
_08113DC4:
	movs r0, #0
_08113DC6:
	cmp r0, #0
	beq _08113DD2
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080f0914
_08113DD2:
	adds r0, r4, #0
	bl FUN_080f06ac
_08113DD8:
	movs r0, #0
_08113DDA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start EnemySkeleton_Destroy
EnemySkeleton_Destroy: @ 0x08113DE0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r4, r1
	bl FUN_08236424
	ldr r2, _08113E00 @ =0x0000025D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08113E04
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _08113E0C
	.align 2, 0
_08113E00: .4byte 0x0000025D
_08113E04:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_08113E0C:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _08113E28 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _08113E2C
	movs r0, #1
	b _08113E2E
	.align 2, 0
_08113E28: .4byte 0x00000474
_08113E2C:
	movs r0, #0
_08113E2E:
	cmp r0, #0
	beq _08113E3A
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_08113E3A:
	ldr r1, _08113E94 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _08113E52
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_08113E52:
	ldr r0, _08113E98 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _08113E6A
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_08113E6A:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08113E82
	adds r0, r4, #0
	bl FUN_08002a58
_08113E82:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08113E9C
	movs r0, #1
	b _08113E9E
	.align 2, 0
_08113E94: .4byte 0x0000044C
_08113E98: .4byte 0x0000044D
_08113E9C:
	movs r0, #0
_08113E9E:
	cmp r0, #0
	beq _08113EAA
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_08113EAA:
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

	thumb_func_start EnemySkeleton_Init
EnemySkeleton_Init: @ 0x08113EC8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1b4
	adds r7, r0, #0
	str r7, [sp, #0x24]
	str r7, [sp, #0x28]
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r6, #0
	strh r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #1
	bl FUN_080e37e8
	movs r0, #0x6b
	movs r1, #5
	bl VM_GetKeywordValue
	ldr r2, _08113F74 @ =0x000001DF
	adds r1, r7, r2
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bne _08113F12
	movs r0, #0x40
	movs r3, #0xe6
	lsls r3, r3, #3
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08113F12:
	adds r0, r7, #0
	bl FUN_0810388c
	ldr r4, _08113F78 @ =0x0000025D
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0x1a0]
	cmp r1, #0
	bne _08113F80
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _08113F7C @ =0x0000AE52
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080e3804
	ldr r6, _08113F74 @ =0x000001DF
	adds r0, r7, r6
	ldrb r1, [r0]
	str r0, [sp, #0xfc]
	cmp r1, #0x11
	beq _08113F62
	cmp r1, #0x17
	bne _08113F66
_08113F62:
	movs r0, #1
	strb r0, [r5, #7]
_08113F66:
	movs r0, #0xef
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
	b _08113FE6
	.align 2, 0
_08113F74: .4byte 0x000001DF
_08113F78: .4byte 0x0000025D
_08113F7C: .4byte 0x0000AE52
_08113F80:
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
	ldr r2, _08114064 @ =0x05000002
	bl CpuSet
	ldr r0, _08114068 @ =0x0000CB05
	ldr r1, _0811406C @ =0x0000AE52
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
	ldr r0, _08114070 @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _08114074 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0xfc]
_08113FE6:
	str r7, [sp, #0x2c]
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
	ldr r5, _08114078 @ =0x0000046F
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
	ldr r1, _0811407C @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _08114064 @ =0x05000002
	bl CpuSet
	ldr r3, _08114080 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1b0]
	bl VM_SeekToKeyword
	mov r1, sb
	str r1, [sp, #0x84]
	mov r3, r8
	str r3, [sp, #0x88]
	str r6, [sp, #0x58]
	ldr r2, [sp, #0x1b0]
	adds r6, r2, #0
	cmp r0, #0
	bne _08114052
	b _081141B4
_08114052:
	bl VM_GetPC
	cmp r0, #0
	beq _08114084
	bl Script_GetValue
	adds r1, r0, #0
	b _08114086
	.align 2, 0
_08114064: .4byte 0x05000002
_08114068: .4byte 0x0000CB05
_0811406C: .4byte 0x0000AE52
_08114070: .4byte 0x000004B7
_08114074: .4byte 0x000001DF
_08114078: .4byte 0x0000046F
_0811407C: .4byte 0x00000474
_08114080: .4byte 0x000004B6
_08114084:
	movs r1, #0
_08114086:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _081140AC @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x188]
	str r4, [sp, #0x18c]
	cmp r0, #0
	beq _081140B0
	bl Script_GetValue
	adds r1, r0, #0
	b _081140B2
	.align 2, 0
_081140AC: .4byte 0x00000251
_081140B0:
	movs r1, #0
_081140B2:
	ldr r2, _081140E8 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _081140EC @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0x188]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0x190]
	cmp r0, #0
	beq _081140F0
	bl Script_GetValue
	b _081140F4
	.align 2, 0
_081140E8: .4byte 0x00000252
_081140EC: .4byte 0x000004B4
_081140F0:
	ldr r4, [sp, #0x188]
	ldrb r0, [r4]
_081140F4:
	strb r0, [r6]
	ldr r5, [sp, #0x188]
	ldrb r1, [r5]
	ldr r6, [sp, #0x190]
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
	blt _0811412C
	cmp r1, #0
	blt _0811412C
	ldr r0, _08114130 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811412C
	ldr r0, _08114134 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08114138
_0811412C:
	movs r1, #0
	b _08114146
	.align 2, 0
_08114130: .4byte 0x030046A8
_08114134: .4byte 0x030046AC
_08114138:
	ldr r0, _08114160 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_08114146:
	ldr r2, _08114164 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08114168
	adds r0, #4
	b _08114174
	.align 2, 0
_08114160: .4byte 0x030046A4
_08114164: .4byte 0x00000256
_08114168:
	ldr r0, _08114188 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08114174:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811418C
	cmp r2, #2
	beq _08114190
	b _08114194
	.align 2, 0
_08114188: .4byte 0x030046A4
_0811418C:
	ldrb r0, [r4, #4]
	b _08114192
_08114190:
	ldrb r0, [r4]
_08114192:
	subs r1, r1, r0
_08114194:
	ldr r3, _081141AC @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _081141B0 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x30]
	b _081141F4
	.align 2, 0
_081141AC: .4byte 0x00000472
_081141B0: .4byte 0x0000FFFF
_081141B4:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _08114218 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _0811421C @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _08114220 @ =0x000004B4
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
	str r0, [sp, #0x30]
	str r5, [sp, #0x188]
	str r4, [sp, #0x18c]
	str r3, [sp, #0x190]
_081141F4:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0811423E
	bl VM_GetPC
	cmp r0, #0
	beq _08114224
	bl Script_GetValue
	adds r4, r0, #0
	b _08114226
	.align 2, 0
_08114218: .4byte 0x00000251
_0811421C: .4byte 0x00000252
_08114220: .4byte 0x000004B4
_08114224:
	movs r4, #0x30
_08114226:
	bl VM_GetPC
	cmp r0, #0
	beq _08114238
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _0811423A
_08114238:
	movs r5, #0x40
_0811423A:
	mov r8, r4
	b _08114244
_0811423E:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_08114244:
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0811427C
	bl VM_GetPC
	cmp r0, #0
	beq _0811425E
	bl Script_GetValue
	adds r6, r0, #0
	b _08114260
_0811425E:
	movs r6, #0
_08114260:
	bl VM_GetPC
	cmp r0, #0
	beq _08114270
	bl Script_GetValue
	adds r1, r0, #0
	b _08114272
_08114270:
	movs r1, #0
_08114272:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _08114286
_0811427C:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_08114286:
	movs r0, #0x61
	bl VM_SeekToKeyword
	movs r1, #0x93
	lsls r1, r1, #2
	adds r1, r7, r1
	str r1, [sp, #0x180]
	movs r2, #0xcb
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x98]
	movs r3, #0xca
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x94]
	movs r1, #0x95
	lsls r1, r1, #2
	adds r1, r7, r1
	str r1, [sp, #0x198]
	lsls r4, r4, #0x10
	str r4, [sp, #0x118]
	mov r2, r8
	lsls r2, r2, #0x10
	str r2, [sp, #0x128]
	lsls r6, r6, #0x10
	str r6, [sp, #0x12c]
	lsls r5, r5, #0x10
	str r5, [sp, #0x120]
	ldr r3, _08114510 @ =0x0000025A
	adds r3, r7, r3
	str r3, [sp, #0x19c]
	mov r4, sb
	lsls r4, r4, #0x10
	str r4, [sp, #0x110]
	adds r5, r7, #0
	adds r5, #0x8c
	str r5, [sp, #0x40]
	movs r6, #0xf4
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x108]
	movs r1, #0xf6
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x10c]
	adds r2, r7, #0
	adds r2, #0xa8
	str r2, [sp, #0x50]
	adds r3, r7, #0
	adds r3, #0xac
	str r3, [sp, #0x54]
	adds r4, r7, #0
	adds r4, #8
	str r4, [sp, #0x38]
	movs r5, #0x90
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x70]
	ldr r6, _08114514 @ =0x0000047A
	adds r6, r7, r6
	str r6, [sp, #0x64]
	ldr r1, _08114518 @ =0x0000047C
	adds r1, r7, r1
	str r1, [sp, #0x68]
	ldr r2, _0811451C @ =0x0000047E
	adds r2, r7, r2
	str r2, [sp, #0x6c]
	ldr r3, _08114520 @ =0x00000476
	adds r3, r7, r3
	str r3, [sp, #0x5c]
	movs r4, #0x8f
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x60]
	ldr r5, _08114524 @ =0x000004A4
	adds r5, r7, r5
	str r5, [sp, #0x7c]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x80]
	movs r1, #0xb0
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xd0]
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xdc]
	movs r3, #0xb2
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xe4]
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xf8]
	ldr r5, _08114528 @ =0x000005A4
	adds r5, r7, r5
	str r5, [sp, #0x100]
	movs r6, #0xb8
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x130]
	ldr r1, _0811452C @ =0x000005C4
	adds r1, r7, r1
	str r1, [sp, #0x134]
	ldr r2, _08114530 @ =0x000005CC
	adds r2, r7, r2
	str r2, [sp, #0x13c]
	movs r3, #0xba
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x140]
	ldr r4, _08114534 @ =0x000005D4
	adds r4, r7, r4
	str r4, [sp, #0x144]
	ldr r5, _08114538 @ =0x000005DC
	adds r5, r7, r5
	str r5, [sp, #0x14c]
	movs r6, #0xb9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x138]
	ldr r1, _0811453C @ =0x00000584
	adds r1, r7, r1
	str r1, [sp, #0xd8]
	ldr r2, _08114540 @ =0x00000604
	adds r2, r7, r2
	str r2, [sp, #0x174]
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x178]
	ldr r4, _08114544 @ =0x0000021D
	adds r4, r7, r4
	str r4, [sp, #0x154]
	ldr r5, _08114548 @ =0x0000060C
	adds r5, r7, r5
	str r5, [sp, #0x17c]
	movs r6, #0xbe
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x164]
	ldr r1, _0811454C @ =0x000005E4
	adds r1, r7, r1
	str r1, [sp, #0x158]
	movs r2, #0xbf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x168]
	ldr r3, _08114550 @ =0x000005FC
	adds r3, r7, r3
	str r3, [sp, #0x16c]
	movs r4, #0xc0
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x170]
	ldr r5, _08114554 @ =0x00000614
	adds r5, r7, r5
	str r5, [sp, #0x184]
	movs r6, #0xc3
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x194]
	ldr r1, _08114558 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0x124]
	movs r2, #0xbd
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x15c]
	movs r3, #0xbc
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x150]
	ldr r4, _0811455C @ =0x000005EC
	adds r4, r7, r4
	str r4, [sp, #0x160]
	movs r5, #0xbb
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x148]
	movs r6, #0xb5
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x104]
	ldr r1, _08114560 @ =0x00000624
	adds r1, r7, r1
	str r1, [sp, #0x1a4]
	ldr r2, _08114564 @ =0x0000058C
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	movs r3, #0xc5
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x1a8]
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x11c]
	ldr r5, _08114568 @ =0x00000594
	adds r5, r7, r5
	str r5, [sp, #0xe8]
	movs r6, #0xb3
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xec]
	ldr r1, _0811456C @ =0x0000059C
	adds r1, r7, r1
	str r1, [sp, #0xf4]
	ldr r2, _08114570 @ =0x000005B4
	adds r2, r7, r2
	str r2, [sp, #0x114]
	ldr r3, _08114574 @ =0x00000543
	adds r3, r7, r3
	str r3, [sp, #0x8c]
	ldr r4, [sp, #0x28]
	adds r4, #8
	str r4, [sp, #0x3c]
	movs r5, #0xcc
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0xa0]
	movs r6, #0xcd
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	ldr r1, _08114578 @ =0x00000496
	adds r1, r7, r1
	str r1, [sp, #0x78]
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x44]
	ldr r3, _0811457C @ =0x00000469
	adds r3, r7, r3
	str r3, [sp, #0x48]
	ldr r4, _08114580 @ =0x0000046A
	adds r4, r7, r4
	str r4, [sp, #0x4c]
	ldr r5, _08114584 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x90]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xcc]
	movs r1, #0x92
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x74]
	movs r2, #0xea
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xf0]
	ldr r3, _08114588 @ =0x00000572
	adds r3, r7, r3
	str r3, [sp, #0xc8]
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0xd4]
	movs r5, #0xae
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xc4]
	ldr r6, _0811458C @ =0x0000055C
	adds r6, r7, r6
	str r6, [sp, #0x9c]
	movs r1, #0xac
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xa8]
	ldr r2, _08114590 @ =0x00000564
	adds r2, r7, r2
	str r2, [sp, #0xac]
	ldr r3, _08114594 @ =0x00000565
	adds r3, r7, r3
	str r3, [sp, #0xb0]
	ldr r4, _08114598 @ =0x00000566
	adds r4, r7, r4
	str r4, [sp, #0xb4]
	ldr r5, _0811459C @ =0x00000567
	adds r5, r7, r5
	str r5, [sp, #0xb8]
	movs r6, #0xad
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xbc]
	ldr r1, _081145A0 @ =0x0000056C
	adds r1, r7, r1
	str r1, [sp, #0xc0]
	movs r3, #0xe6
	lsls r3, r3, #3
	ldr r2, [sp, #0x24]
	adds r3, r2, r3
	str r3, [sp, #0x34]
	cmp r0, #0
	bne _081144E0
	b _081145FA
_081144E0:
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
_08114500:
	bl VM_GetPC
	cmp r0, #0
	beq _081145A4
	bl Script_GetValue
	b _081145A6
	.align 2, 0
_08114510: .4byte 0x0000025A
_08114514: .4byte 0x0000047A
_08114518: .4byte 0x0000047C
_0811451C: .4byte 0x0000047E
_08114520: .4byte 0x00000476
_08114524: .4byte 0x000004A4
_08114528: .4byte 0x000005A4
_0811452C: .4byte 0x000005C4
_08114530: .4byte 0x000005CC
_08114534: .4byte 0x000005D4
_08114538: .4byte 0x000005DC
_0811453C: .4byte 0x00000584
_08114540: .4byte 0x00000604
_08114544: .4byte 0x0000021D
_08114548: .4byte 0x0000060C
_0811454C: .4byte 0x000005E4
_08114550: .4byte 0x000005FC
_08114554: .4byte 0x00000614
_08114558: .4byte 0x000005BC
_0811455C: .4byte 0x000005EC
_08114560: .4byte 0x00000624
_08114564: .4byte 0x0000058C
_08114568: .4byte 0x00000594
_0811456C: .4byte 0x0000059C
_08114570: .4byte 0x000005B4
_08114574: .4byte 0x00000543
_08114578: .4byte 0x00000496
_0811457C: .4byte 0x00000469
_08114580: .4byte 0x0000046A
_08114584: .4byte 0x00000553
_08114588: .4byte 0x00000572
_0811458C: .4byte 0x0000055C
_08114590: .4byte 0x00000564
_08114594: .4byte 0x00000565
_08114598: .4byte 0x00000566
_0811459C: .4byte 0x00000567
_081145A0: .4byte 0x0000056C
_081145A4:
	movs r0, #0x18
_081145A6:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _081145B8
	bl Script_GetValue
	b _081145BA
_081145B8:
	movs r0, #0x18
_081145BA:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _081145CC
	bl Script_GetValue
	b _081145CE
_081145CC:
	movs r0, #0
_081145CE:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _081145E0
	bl Script_GetValue
	b _081145E2
_081145E0:
	movs r0, #0
_081145E2:
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
	ble _08114500
_081145FA:
	movs r0, #0x6c
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08114646
	bl VM_GetPC
	cmp r0, #0
	beq _08114614
	bl Script_GetValue
	adds r4, r0, #0
	b _08114618
_08114614:
	movs r4, #0x96
	lsls r4, r4, #1
_08114618:
	bl VM_GetPC
	cmp r0, #0
	beq _08114628
	bl Script_GetValue
	adds r6, r0, #0
	b _0811462C
_08114628:
	movs r6, #0x96
	lsls r6, r6, #1
_0811462C:
	bl VM_GetPC
	cmp r0, #0
	beq _0811463A
	bl Script_GetValue
	b _08114640
_0811463A:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
_08114640:
	ldr r2, [sp, #0x180]
	strh r0, [r2]
	b _0811464E
_08114646:
	movs r4, #0
	movs r6, #0
	ldr r3, [sp, #0x180]
	strh r6, [r3]
_0811464E:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _08114666
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x88]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_08114666:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x98]
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, [sp, #0x94]
	strh r0, [r2]
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08114734
	bl VM_GetPC
	cmp r0, #0
	beq _08114696
	bl Script_GetValue
	b _08114698
_08114696:
	movs r0, #0
_08114698:
	ldr r3, [sp, #0x198]
	strh r0, [r3]
	ldrh r0, [r3]
	cmp r0, #0
	blt _081146A6
	asrs r1, r0, #1
	b _081146AC
_081146A6:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081146AC:
	ldr r5, _081146C0 @ =0x00000546
	adds r0, r7, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081146C4
	bl Script_GetValue
	b _081146C6
	.align 2, 0
_081146C0: .4byte 0x00000546
_081146C4:
	movs r0, #0
_081146C6:
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081146DC
	bl Script_GetValue
	b _081146DE
_081146DC:
	movs r0, #0
_081146DE:
	ldr r3, _081146F4 @ =0x00000187
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081146F8
	bl Script_GetValue
	adds r1, r0, #0
	b _081146FA
	.align 2, 0
_081146F4: .4byte 0x00000187
_081146F8:
	movs r1, #0
_081146FA:
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08114710
	bl Script_GetValue
	b _08114712
_08114710:
	movs r0, #0
_08114712:
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _0811472A
	bl Script_GetValue
	adds r1, r0, #0
	b _0811472C
_0811472A:
	movs r1, #0
_0811472C:
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_08114734:
	ldr r5, [sp, #0x198]
	ldrh r1, [r5]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r6, [sp, #0x118]
	lsrs r2, r6, #0x10
	ldr r0, [sp, #0x128]
	lsrs r3, r0, #0x10
	ldr r1, [sp, #0x12c]
	lsrs r0, r1, #0x10
	str r0, [sp]
	ldr r4, [sp, #0x120]
	lsrs r0, r4, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08114796
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r6, r7, r5
	bl VM_GetPC
	cmp r0, #0
	beq _0811477C
	bl Script_GetValue
	b _0811477E
_0811477C:
	movs r0, #0
_0811477E:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _0811478E
	bl Script_GetValue
	b _08114790
_0811478E:
	movs r0, #0
_08114790:
	ldr r6, _081147F8 @ =0x00000189
	adds r1, r7, r6
	strb r0, [r1]
_08114796:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x19c]
	strh r0, [r1]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081147BA
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x88]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_081147BA:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081147D2
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r3, [sp, #0x88]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081147D2:
	ldr r4, [sp, #0x110]
	lsrs r1, r4, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x2c]
	add r2, sp, #0x1c
	movs r3, #0
	bl FUN_0823b400
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x58]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081147FC
	movs r0, #1
	b _081147FE
	.align 2, 0
_081147F8: .4byte 0x00000189
_081147FC:
	movs r0, #0
_081147FE:
	cmp r0, #0
	beq _0811480E
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08114838 @ =FUN_080f48ac
	ldr r1, [sp, #0x2c]
	bl FUN_0807f558
_0811480E:
	ldr r6, [sp, #0x1a0]
	ldrb r0, [r6]
	movs r1, #0
	cmp r0, #0
	bne _0811481A
	ldr r1, [r7, #0x44]
_0811481A:
	ldr r0, [sp, #0x2c]
	bl FUN_0823b46c
	ldr r1, [sp, #0xfc]
	ldrb r0, [r1]
	cmp r0, #0x15
	bne _0811483C
	ldr r0, [sp, #0x2c]
	ldr r1, [sp, #0x40]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _08114848
	.align 2, 0
_08114838: .4byte FUN_080f48ac
_0811483C:
	ldr r0, [sp, #0x2c]
	ldr r1, [sp, #0x40]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_08114848:
	ldr r2, [sp, #0xfc]
	ldrb r1, [r2]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08114896
	adds r0, r1, #0
	cmp r0, #0xb
	beq _08114896
	cmp r0, #0x16
	beq _08114896
	cmp r0, #0x14
	beq _08114896
	cmp r0, #9
	beq _08114896
	cmp r0, #0x19
	beq _08114896
	cmp r0, #0x1a
	beq _08114896
	cmp r0, #0xd
	beq _08114896
	cmp r0, #0x1b
	beq _08114896
	cmp r0, #0x1f
	beq _08114896
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r3, [sp, #0x188]
	ldrb r2, [r3]
	ldr r4, [sp, #0x18c]
	ldrb r3, [r4]
	ldr r5, [sp, #0x190]
	ldrb r0, [r5]
	str r0, [sp]
	ldr r0, [sp, #0x2c]
	bl FUN_0823b490
_08114896:
	movs r1, #8
	ldr r6, [sp, #0x58]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081148A6
	movs r0, #1
	b _081148A8
_081148A6:
	movs r0, #0
_081148A8:
	cmp r0, #0
	beq _081148B6
	ldr r1, [sp, #0x10c]
	ldr r0, [r1]
	ldr r2, [sp, #0x108]
	str r0, [r2]
	b _081148C8
_081148B6:
	ldr r3, [sp, #0x10c]
	ldr r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r4, [sp, #0x108]
	str r0, [r4]
_081148C8:
	ldrh r0, [r7]
	ldr r5, [sp, #0x50]
	strh r0, [r5]
	ldr r6, [sp, #0x38]
	ldr r0, [sp, #0x54]
	str r6, [r0]
	ldr r1, [sp, #0x30]
	cmp r1, #0
	beq _081148F2
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
	ldr r2, [sp, #0x2c]
	strb r0, [r2, #5]
_081148F2:
	adds r0, r7, #0
	bl FUN_081055ac
	adds r0, r7, #0
	bl FUN_081065ec
	adds r0, r7, #0
	bl FUN_08108634
	movs r4, #0xf7
	ldr r5, _0811493C @ =0x00000101
	movs r0, #0x43
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r3, [sp, #0x70]
	strh r0, [r3]
	ldr r6, [sp, #0x64]
	strh r4, [r6]
	ldr r0, [sp, #0x68]
	strh r5, [r0]
	ldrh r0, [r3]
	adds r0, #0xf7
	ldr r1, [sp, #0x6c]
	strh r0, [r1]
	ldrh r1, [r6]
	ldrh r0, [r3]
	adds r1, r1, r0
	ldr r2, [sp, #0x1a0]
	ldrb r0, [r2]
	cmp r0, #0
	bne _08114940
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _0811494C
	.align 2, 0
_0811493C: .4byte 0x00000101
_08114940:
	ldr r2, [r7, #0x44]
	ldr r0, _08114984 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_0811494C:
	ldr r3, [sp, #0x1a0]
	ldrb r0, [r3]
	cmp r0, #1
	bne _0811499C
	ldr r4, [sp, #0xfc]
	ldrb r0, [r4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08114988
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
	b _08114992
	.align 2, 0
_08114984: .4byte 0x03003584
_08114988:
	ldr r5, [sp, #0xfc]
	ldrb r0, [r5]
	bl FUN_080ecf60
	adds r4, r0, #1
_08114992:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_0811499C:
	movs r4, #0
	ldr r6, [sp, #0x64]
	ldrh r0, [r6]
	adds r0, #6
	ldr r1, [sp, #0x5c]
	strh r0, [r1]
	ldrh r0, [r6]
	ldr r2, [sp, #0x60]
	strh r0, [r2]
	adds r0, r7, #0
	bl FUN_08106234
	adds r0, r7, #0
	bl FUN_08103504
	ldr r3, [sp, #0x24]
	ldr r5, _08114B44 @ =0x0000076C
	adds r0, r3, r5
	movs r6, #0xf2
	lsls r6, r6, #3
	adds r3, r3, r6
	mov r8, r3
	ldr r1, _08114B48 @ =FUN_08113c2c
	mov sb, r1
	ldr r2, _08114B4C @ =FUN_08105170
	mov sl, r2
	ldr r3, _08114B50 @ =FUN_0810bad8
	mov ip, r3
	ldr r5, _08114B54 @ =FUN_0810caa4
	ldr r3, _08114B58 @ =FUN_080f62b0
	ldr r6, _08114B5C @ =FUN_080f62ac
	str r6, [sp, #0x1ac]
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x84]
	ldr r1, [r6]
	orrs r1, r2
	str r1, [r6]
	ldr r1, [sp, #0x7c]
	str r0, [r1]
	mov r2, r8
	ldr r6, [sp, #0x80]
	str r2, [r6]
	mov r1, sb
	ldr r2, [sp, #0xd0]
	str r1, [r2]
	mov r6, sl
	ldr r1, [sp, #0xdc]
	str r6, [r1]
	mov r2, ip
	ldr r6, [sp, #0xe4]
	str r2, [r6]
	ldr r1, _08114B60 @ =FUN_081091cc
	ldr r2, [sp, #0xf8]
	str r1, [r2]
	ldr r6, _08114B64 @ =FUN_081091fc
	ldr r1, [sp, #0x100]
	str r6, [r1]
	ldr r2, _08114B68 @ =FUN_0810c1b0
	ldr r6, [sp, #0x130]
	str r2, [r6]
	ldr r1, [sp, #0x134]
	str r3, [r1]
	ldr r2, [sp, #0x13c]
	str r5, [r2]
	ldr r3, _08114B6C @ =FUN_0810e2a0
	ldr r5, [sp, #0x140]
	str r3, [r5]
	ldr r1, _08114B70 @ =FUN_080f44f4
	ldr r6, [sp, #0x144]
	str r1, [r6]
	ldr r1, _08114B74 @ =FUN_080f410c
	ldr r2, [sp, #0x14c]
	str r1, [r2]
	ldr r3, _08114B78 @ =FUN_0810c8dc
	ldr r5, [sp, #0x138]
	str r3, [r5]
	ldr r6, _08114B7C @ =FUN_0810c520
	ldr r1, [sp, #0xd8]
	str r6, [r1]
	ldr r2, [sp, #0x1ac]
	ldr r3, [sp, #0x174]
	str r2, [r3]
	ldr r1, _08114B80 @ =FUN_080f0430
	ldr r5, [sp, #0x178]
	str r1, [r5]
	movs r1, #1
	ldr r6, [sp, #0x154]
	strb r1, [r6]
	ldr r1, _08114B84 @ =0x085AD470
	ldr r2, [sp, #0x17c]
	str r1, [r2]
	ldr r1, _08114B88 @ =FUN_080e73c8
	ldr r3, [sp, #0x164]
	str r1, [r3]
	ldr r5, [sp, #0x158]
	str r4, [r5]
	ldr r6, [sp, #0x168]
	str r4, [r6]
	ldr r1, [sp, #0x16c]
	str r4, [r1]
	ldr r2, [sp, #0x170]
	str r4, [r2]
	ldr r3, [sp, #0x184]
	str r4, [r3]
	ldr r1, _08114B8C @ =FUN_080f0320
	ldr r5, [sp, #0x194]
	str r1, [r5]
	ldr r1, _08114B90 @ =FUN_080eff14
	ldr r6, [sp, #0x124]
	str r1, [r6]
	ldr r1, _08114B94 @ =FUN_080e72b0
	ldr r2, [sp, #0x15c]
	str r1, [r2]
	ldr r3, [sp, #0x150]
	str r4, [r3]
	ldr r1, _08114B98 @ =FUN_080f47c8
	ldr r5, [sp, #0x160]
	str r1, [r5]
	ldr r1, _08114B9C @ =FUN_080f54e4
	ldr r6, [sp, #0x148]
	str r1, [r6]
	ldr r1, [sp, #0x104]
	str r4, [r1]
	ldr r1, _08114BA0 @ =FUN_080f6e64
	ldr r2, [sp, #0x1a4]
	str r1, [r2]
	ldr r1, _08114BA4 @ =FUN_080f64f0
	ldr r3, [sp, #0xe0]
	str r1, [r3]
	ldr r1, _08114BA8 @ =FUN_080f84d4
	ldr r5, [sp, #0x1a8]
	str r1, [r5]
	ldr r1, _08114BAC @ =FUN_080f624c
	ldr r6, [sp, #0x11c]
	str r1, [r6]
	ldr r1, _08114BB0 @ =FUN_080f56ec
	ldr r2, [sp, #0xe8]
	str r1, [r2]
	ldr r1, _08114BB4 @ =FUN_080f5b34
	ldr r3, [sp, #0xec]
	str r1, [r3]
	ldr r1, _08114BB8 @ =FUN_080f5fac
	ldr r5, [sp, #0xf4]
	str r1, [r5]
	ldr r6, [sp, #0x114]
	str r4, [r6]
	movs r1, #0x28
	ldr r2, [sp, #0x8c]
	strb r1, [r2]
	ldr r1, [sp, #0x3c]
	bl FUN_082362fc
	adds r0, r7, #0
	bl FUN_080e6204
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _08114BBC @ =FUN_0810342c
	str r0, [r1]
	ldr r5, _08114BC0 @ =0x000005FC
	adds r0, r7, r5
	str r4, [r0]
	movs r6, #0xc3
	lsls r6, r6, #3
	adds r1, r7, r6
	ldr r0, _08114BC4 @ =FUN_0810608c
	str r0, [r1]
	ldr r1, _08114BC8 @ =0x000001DF
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #8
	beq _08114AFA
	b _08114C54
_08114AFA:
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #2
	bne _08114BEC
	subs r3, #0x4c
	adds r1, r7, r3
	ldr r0, _08114BCC @ =FUN_081061fc
	str r0, [r1]
	movs r4, #0xb6
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _08114BD0 @ =FUN_08106230
	str r0, [r1]
	subs r5, #0x70
	adds r1, r7, r5
	ldr r0, _08114BD4 @ =FUN_08112c68
	str r0, [r1]
	subs r6, #0x10
	adds r1, r7, r6
	ldr r0, _08114BD8 @ =FUN_081061b0
	str r0, [r1]
	ldr r0, _08114BDC @ =0x0000060C
	adds r1, r7, r0
	ldr r0, _08114BE0 @ =0x085AD5D8
	str r0, [r1]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, _08114BE4 @ =FUN_0810e000
	str r0, [r1]
	adds r3, #0x40
	adds r1, r7, r3
	ldr r0, _08114BE8 @ =FUN_081086f8
	b _08114C7E
	.align 2, 0
_08114B44: .4byte 0x0000076C
_08114B48: .4byte FUN_08113c2c
_08114B4C: .4byte FUN_08105170
_08114B50: .4byte FUN_0810bad8
_08114B54: .4byte FUN_0810caa4
_08114B58: .4byte FUN_080f62b0
_08114B5C: .4byte FUN_080f62ac
_08114B60: .4byte FUN_081091cc
_08114B64: .4byte FUN_081091fc
_08114B68: .4byte FUN_0810c1b0
_08114B6C: .4byte FUN_0810e2a0
_08114B70: .4byte FUN_080f44f4
_08114B74: .4byte FUN_080f410c
_08114B78: .4byte FUN_0810c8dc
_08114B7C: .4byte FUN_0810c520
_08114B80: .4byte FUN_080f0430
_08114B84: .4byte 0x085AD470
_08114B88: .4byte FUN_080e73c8
_08114B8C: .4byte FUN_080f0320
_08114B90: .4byte FUN_080eff14
_08114B94: .4byte FUN_080e72b0
_08114B98: .4byte FUN_080f47c8
_08114B9C: .4byte FUN_080f54e4
_08114BA0: .4byte FUN_080f6e64
_08114BA4: .4byte FUN_080f64f0
_08114BA8: .4byte FUN_080f84d4
_08114BAC: .4byte FUN_080f624c
_08114BB0: .4byte FUN_080f56ec
_08114BB4: .4byte FUN_080f5b34
_08114BB8: .4byte FUN_080f5fac
_08114BBC: .4byte FUN_0810342c
_08114BC0: .4byte 0x000005FC
_08114BC4: .4byte FUN_0810608c
_08114BC8: .4byte 0x000001DF
_08114BCC: .4byte FUN_081061fc
_08114BD0: .4byte FUN_08106230
_08114BD4: .4byte FUN_08112c68
_08114BD8: .4byte FUN_081061b0
_08114BDC: .4byte 0x0000060C
_08114BE0: .4byte 0x085AD5D8
_08114BE4: .4byte FUN_0810e000
_08114BE8: .4byte FUN_081086f8
_08114BEC:
	ldr r4, _08114C2C @ =0x000005AC
	adds r1, r7, r4
	ldr r0, _08114C30 @ =FUN_081061fc
	str r0, [r1]
	movs r5, #0xb6
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, _08114C34 @ =FUN_08106230
	str r0, [r1]
	ldr r6, _08114C38 @ =0x0000058C
	adds r1, r7, r6
	ldr r0, _08114C3C @ =FUN_08112d40
	str r0, [r1]
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _08114C40 @ =FUN_081061b0
	str r0, [r1]
	ldr r2, _08114C44 @ =0x0000060C
	adds r1, r7, r2
	ldr r0, _08114C48 @ =0x085AD5D8
	str r0, [r1]
	movs r3, #0xba
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _08114C4C @ =FUN_0810e000
	str r0, [r1]
	adds r4, #0x40
	adds r1, r7, r4
	ldr r0, _08114C50 @ =FUN_08108788
	b _08114C7E
	.align 2, 0
_08114C2C: .4byte 0x000005AC
_08114C30: .4byte FUN_081061fc
_08114C34: .4byte FUN_08106230
_08114C38: .4byte 0x0000058C
_08114C3C: .4byte FUN_08112d40
_08114C40: .4byte FUN_081061b0
_08114C44: .4byte 0x0000060C
_08114C48: .4byte 0x085AD5D8
_08114C4C: .4byte FUN_0810e000
_08114C50: .4byte FUN_08108788
_08114C54:
	ldr r5, _08114CBC @ =0x000005AC
	adds r1, r7, r5
	ldr r0, _08114CC0 @ =FUN_08104d70
	str r0, [r1]
	movs r6, #0xb6
	lsls r6, r6, #3
	adds r1, r7, r6
	ldr r0, _08114CC4 @ =FUN_08104ebc
	str r0, [r1]
	ldr r0, _08114CC8 @ =0x0000058C
	adds r1, r7, r0
	ldr r0, _08114CCC @ =FUN_08111438
	str r0, [r1]
	ldr r2, _08114CD0 @ =0x0000060C
	adds r1, r7, r2
	ldr r0, _08114CD4 @ =0x085AD5B8
	str r0, [r1]
	movs r3, #0xbb
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _08114CD8 @ =FUN_0810de10
_08114C7E:
	str r0, [r1]
	movs r4, #0xde
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r3, #0
	movs r0, #0
	strh r0, [r1]
	ldr r5, _08114CDC @ =0x000001DF
	adds r0, r7, r5
	ldrb r2, [r0]
	cmp r2, #8
	bne _08114CE0
	movs r1, #0xa0
	lsls r1, r1, #0xf
	ldr r6, [sp, #0x84]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r1, [sp, #0x88]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x80
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _08114D0E
	.align 2, 0
_08114CBC: .4byte 0x000005AC
_08114CC0: .4byte FUN_08104d70
_08114CC4: .4byte FUN_08104ebc
_08114CC8: .4byte 0x0000058C
_08114CCC: .4byte FUN_08111438
_08114CD0: .4byte 0x0000060C
_08114CD4: .4byte 0x085AD5B8
_08114CD8: .4byte FUN_0810de10
_08114CDC: .4byte 0x000001DF
_08114CE0:
	movs r1, #0xb8
	lsls r1, r1, #0x11
	ldr r4, [sp, #0x84]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r1, _08114D40 @ =0x08000008
	ldr r5, [sp, #0x88]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	movs r0, #0x80
	ldr r6, [sp, #0x58]
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	adds r2, r7, #0
	adds r2, #0xd8
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_08114D0E:
	adds r0, r7, #0
	bl Enemy_Init_080e5dd4
	movs r0, #0x49
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0xa0]
	strh r0, [r1]
	movs r0, #0x47
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08114D4E
	movs r2, #0xce
	lsls r2, r2, #1
	adds r5, r7, r2
	movs r4, #4
_08114D32:
	bl VM_GetPC
	cmp r0, #0
	beq _08114D44
	bl Script_GetValue
	b _08114D46
	.align 2, 0
_08114D40: .4byte 0x08000008
_08114D44:
	movs r0, #0
_08114D46:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _08114D32
_08114D4E:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r3, [sp, #0xa4]
	strh r0, [r3]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r4, [sp, #0x78]
	strh r0, [r4]
	cmp r2, #0
	beq _08114D86
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r5, [sp, #0x84]
	ldr r1, [r5]
	orrs r1, r0
	str r1, [r5]
	cmp r2, #2
	bne _08114D86
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r5]
_08114D86:
	movs r2, #0
	movs r1, #4
	ldr r6, [sp, #0x58]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08114D98
	movs r0, #1
	b _08114D9A
_08114D98:
	movs r0, #0
_08114D9A:
	cmp r0, #0
	beq _08114DAC
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r2, [sp, #0x88]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r2, #1
_08114DAC:
	cmp r2, #1
	beq _08114DEC
	movs r1, #0
	ldr r3, [sp, #0x44]
	strb r1, [r3]
	ldr r4, [sp, #0x48]
	strb r1, [r4]
	ldr r5, [sp, #0x4c]
	strb r1, [r5]
	ldr r6, _08114DFC @ =0x00000484
	adds r0, r7, r6
	str r1, [r0]
	ldr r2, _08114E00 @ =0x0000046C
	adds r0, r7, r2
	movs r2, #1
	strb r2, [r0]
	ldr r4, [sp, #0x100]
	ldr r3, [r4]
	ldr r5, _08114E04 @ =0x0000046D
	adds r0, r7, r5
	strb r2, [r0]
	subs r6, #0x19
	adds r0, r7, r6
	strb r1, [r0]
	ldr r0, [sp, #0x90]
	strb r1, [r0]
	ldr r2, [sp, #0xcc]
	str r3, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_08114DEC:
	movs r1, #2
	ldr r4, [sp, #0x58]
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08114E08
	movs r0, #1
	b _08114E0A
	.align 2, 0
_08114DFC: .4byte 0x00000484
_08114E00: .4byte 0x0000046C
_08114E04: .4byte 0x0000046D
_08114E08:
	movs r0, #0
_08114E0A:
	cmp r0, #0
	beq _08114E24
	ldr r0, _08114E20 @ =0x030046A0
	ldr r0, [r0]
	movs r5, #0x92
	lsls r5, r5, #2
	adds r0, r0, r5
	ldr r0, [r0]
	ldr r6, [sp, #0x74]
	strh r0, [r6]
	b _08114E2E
	.align 2, 0
_08114E20: .4byte 0x030046A0
_08114E24:
	ldr r0, [sp, #0x38]
	bl FUN_08241574
	ldr r1, [sp, #0x74]
	strh r0, [r1]
_08114E2E:
	movs r1, #0x40
	ldr r2, [sp, #0x58]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08114E3E
	movs r0, #1
	b _08114E40
_08114E3E:
	movs r0, #0
_08114E40:
	cmp r0, #0
	beq _08114E50
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _08114E74 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_08114E50:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	bne _08114E82
	ldr r0, _08114E78 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x74]
	ldrh r4, [r4]
	cmp r0, r4
	bne _08114E7C
	movs r0, #1
	b _08114E7E
	.align 2, 0
_08114E74: .4byte 0xFFFFFEFF
_08114E78: .4byte 0x030046A0
_08114E7C:
	movs r0, #0
_08114E7E:
	cmp r0, #0
	bne _08114E8A
_08114E82:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_08114E8A:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, [sp, #0x1a0]
	ldrb r0, [r5]
	cmp r0, #0
	bne _08114F72
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
	beq _08114ECC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08114ED4
_08114ECC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08114ED4:
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
	beq _08114EF8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08114F00
_08114EF8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08114F00:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _08114F38 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08114F7C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08114F3C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08114F30
	ldrb r0, [r4, #5]
_08114F30:
	subs r0, #1
	strh r0, [r4, #8]
	b _08114F4C
	.align 2, 0
_08114F38: .4byte 0x0000FFFF
_08114F3C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08114F4C
	strh r1, [r4, #8]
_08114F4C:
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
	bne _08114F7C
	movs r0, #1
	strb r0, [r4, #7]
	b _08114F7C
_08114F72:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_08114F7C:
	movs r0, #0
	ldr r3, [sp, #0xf0]
	str r0, [r3]
	ldr r0, _08114F94 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08114F98
	movs r0, #1
	b _08114F9A
	.align 2, 0
_08114F94: .4byte 0x030047A4
_08114F98:
	movs r0, #0
_08114F9A:
	cmp r0, #0
	bne _08114FDA
	ldr r4, [sp, #0xfc]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08114FC2
	adds r0, r1, #0
	cmp r0, #7
	beq _08114FC2
	cmp r0, #6
	beq _08114FC2
	cmp r0, #0x15
	beq _08114FC2
	cmp r0, #0x14
	beq _08114FC2
	cmp r0, #0x17
	bne _08114FDA
_08114FC2:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x58]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_08114FDA:
	adds r0, r7, #0
	bl FUN_08105690
	ldr r6, _08115088 @ =0x000001DF
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #8
	bne _08115000
	movs r0, #2
	ldr r2, [sp, #0x58]
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r0, r7, #0
	bl FUN_0810770c
	adds r0, r7, #0
	bl FUN_081075dc
_08115000:
	adds r0, r7, #0
	bl Enemy_Init_080f3680
	adds r0, r7, #0
	bl FUN_08113c18
	adds r0, r7, #0
	bl FUN_0810ff48
	adds r0, r7, #0
	bl FUN_08111424
	ldr r3, [sp, #0x58]
	ldrh r0, [r3]
	ldr r4, [sp, #0xc8]
	strh r0, [r4]
	ldr r5, [sp, #0xd4]
	ldrh r0, [r5]
	ldr r6, [sp, #0xc4]
	strh r0, [r6]
	ldr r1, [sp, #0x84]
	ldr r0, [r1]
	ldr r2, [sp, #0x9c]
	str r0, [r2]
	ldr r3, [sp, #0x88]
	ldr r0, [r3]
	ldr r4, [sp, #0xa8]
	str r0, [r4]
	ldrb r0, [r7, #5]
	ldr r5, [sp, #0xac]
	strb r0, [r5]
	ldr r6, [sp, #0x44]
	ldrb r0, [r6]
	ldr r1, [sp, #0xb0]
	strb r0, [r1]
	ldr r2, [sp, #0x48]
	ldrb r0, [r2]
	ldr r3, [sp, #0xb4]
	strb r0, [r3]
	ldr r4, [sp, #0x4c]
	ldrb r0, [r4]
	ldr r5, [sp, #0xb8]
	strb r0, [r5]
	ldr r6, [sp, #0xcc]
	ldr r0, [r6]
	ldr r1, [sp, #0xbc]
	str r0, [r1]
	ldr r2, [sp, #0x90]
	ldrb r0, [r2]
	ldr r3, [sp, #0xc0]
	strb r0, [r3]
	ldr r4, _0811508C @ =0x00000574
	adds r1, r7, r4
	ldr r5, [sp, #0x24]
	movs r6, #0xe6
	lsls r6, r6, #3
	adds r0, r5, r6
	ldrh r0, [r0]
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x34]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08115090
	movs r0, #1
	b _08115092
	.align 2, 0
_08115088: .4byte 0x000001DF
_0811508C: .4byte 0x00000574
_08115090:
	movs r0, #0
_08115092:
	cmp r0, #0
	bne _08115098
	b _0811521C
_08115098:
	ldr r3, _08115108 @ =FUN_0810c2dc
	movs r1, #0x3c
	ldr r4, _0811510C @ =0x0000046D
	adds r0, r7, r4
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _08115110 @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, [sp, #0x90]
	strb r1, [r6]
	ldr r0, [sp, #0xcc]
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r0, #3
	ldr r3, [sp, #0x44]
	strb r0, [r3]
	ldr r5, [sp, #0x48]
	strb r1, [r5]
	ldr r6, [sp, #0x4c]
	strb r1, [r6]
	ldr r1, _08115114 @ =0x00000484
	adds r0, r7, r1
	str r2, [r0]
	ldr r2, _08115118 @ =0x0000046C
	adds r0, r7, r2
	strb r4, [r0]
	movs r0, #0x10
	ldr r3, [sp, #0x34]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r0, #0xc0
	lsls r0, r0, #5
	ldr r4, [sp, #0x58]
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _081150FA
	b _08115288
_081150FA:
	bl VM_GetPC
	cmp r0, #0
	beq _0811511C
	bl Script_GetValue
	b _0811511E
	.align 2, 0
_08115108: .4byte FUN_0810c2dc
_0811510C: .4byte 0x0000046D
_08115110: .4byte 0x0000046B
_08115114: .4byte 0x00000484
_08115118: .4byte 0x0000046C
_0811511C:
	movs r0, #0
_0811511E:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _0811512E
	bl Script_GetValue
	b _08115130
_0811512E:
	movs r0, #0
_08115130:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _08115140
	bl Script_GetValue
	b _08115142
_08115140:
	movs r0, #0
_08115142:
	strh r0, [r7, #0xc]
	bl VM_GetPC
	cmp r0, #0
	beq _08115152
	bl Script_GetValue
	b _08115154
_08115152:
	movs r0, #0
_08115154:
	strb r0, [r7, #5]
	ldr r0, [r7, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	bl VM_GetPC
	cmp r0, #0
	beq _0811516C
	bl Script_GetValue
	adds r0, #0xdd
	b _0811516E
_0811516C:
	movs r0, #0xdd
_0811516E:
	strh r0, [r4, #0x3a]
	ldrh r0, [r7, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldr r5, [sp, #0x38]
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08115196
	cmp r1, #0
	blt _08115196
	ldr r0, _0811519C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08115196
	ldr r0, _081151A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081151A4
_08115196:
	movs r1, #0
	b _081151B2
	.align 2, 0
_0811519C: .4byte 0x030046A8
_081151A0: .4byte 0x030046AC
_081151A4:
	ldr r0, _081151CC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081151B2:
	ldr r6, _081151D0 @ =0x00000256
	adds r0, r7, r6
	strh r1, [r0]
	ldrh r4, [r0]
	ldr r5, [sp, #0x38]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081151D4
	adds r0, #4
	b _081151E0
	.align 2, 0
_081151CC: .4byte 0x030046A4
_081151D0: .4byte 0x00000256
_081151D4:
	ldr r0, _081151F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081151E0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081151F8
	cmp r3, #2
	beq _081151FC
	b _08115200
	.align 2, 0
_081151F4: .4byte 0x030046A4
_081151F8:
	ldrb r0, [r5, #4]
	b _081151FE
_081151FC:
	ldrb r0, [r5]
_081151FE:
	subs r2, r2, r0
_08115200:
	ldr r1, _08115218 @ =0x00000472
	adds r0, r7, r1
	strh r2, [r0]
	ldrh r1, [r7, #0xa]
	subs r1, r1, r2
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r2, r7, r3
	strh r1, [r2]
	ldrh r0, [r0]
	strh r0, [r7, #0xa]
	b _08115288
	.align 2, 0
_08115218: .4byte 0x00000472
_0811521C:
	movs r1, #8
	ldr r4, [sp, #0x34]
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0811522C
	movs r0, #1
	b _0811522E
_0811522C:
	movs r0, #0
_0811522E:
	cmp r0, #0
	beq _08115288
	ldr r3, _081152B4 @ =FUN_0810c464
	movs r1, #0x38
	ldr r5, _081152B8 @ =0x0000046D
	adds r0, r7, r5
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081152BC @ =0x0000046B
	adds r0, r7, r6
	strb r2, [r0]
	ldr r0, [sp, #0x90]
	strb r1, [r0]
	ldr r1, [sp, #0xcc]
	str r3, [r1]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #0
	strh r2, [r0]
	movs r0, #3
	ldr r5, [sp, #0x44]
	strb r0, [r5]
	ldr r6, [sp, #0x48]
	strb r1, [r6]
	ldr r0, [sp, #0x4c]
	strb r1, [r0]
	ldr r1, _081152C0 @ =0x00000484
	adds r0, r7, r1
	str r2, [r0]
	ldr r2, _081152C4 @ =0x0000046C
	adds r0, r7, r2
	strb r4, [r0]
	movs r0, #0xc0
	lsls r0, r0, #5
	ldr r3, [sp, #0x58]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r0, #0x10
	ldr r4, [sp, #0x34]
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
_08115288:
	ldr r5, _081152C8 @ =0x0000057C
	adds r1, r7, r5
	ldr r0, _081152CC @ =FUN_080f09e0
	str r0, [r1]
	ldr r6, _081152D0 @ =0x0000061C
	adds r1, r7, r6
	ldr r0, _081152D4 @ =FUN_08113ca0
	str r0, [r1]
	movs r0, #0xc4
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081152D8 @ =EnemySkeleton_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081152DC
	movs r0, #0
	b _081152E0
	.align 2, 0
_081152B4: .4byte FUN_0810c464
_081152B8: .4byte 0x0000046D
_081152BC: .4byte 0x0000046B
_081152C0: .4byte 0x00000484
_081152C4: .4byte 0x0000046C
_081152C8: .4byte 0x0000057C
_081152CC: .4byte FUN_080f09e0
_081152D0: .4byte 0x0000061C
_081152D4: .4byte FUN_08113ca0
_081152D8: .4byte EnemySkeleton_Destroy
_081152DC:
	movs r0, #1
	rsbs r0, r0, #0
_081152E0:
	add sp, #0x1b4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start EnemySkeleton_Create
EnemySkeleton_Create: @ 0x081152F0
	push {r4, r5, lr}
	movs r5, #0xf5
	lsls r5, r5, #3
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _0811531E
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemySkeleton_Init
	cmp r0, #0
	bge _0811531E
	adds r0, r4, #0
	bl EnemySkeleton_Destroy
	adds r0, r4, #0
	bl Free
_0811531E:
	pop {r4, r5}
	pop {r0}
	bx r0
