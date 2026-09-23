	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081dae74
FUN_081dae74: @ 0x081DAE74
	push {lr}
	adds r2, r0, #0
	ldr r0, _081DAE90 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DAE8A
	movs r3, #0xb1
	lsls r3, r3, #2
	adds r1, r0, r3
	cmp r1, #0
	bne _081DAE94
_081DAE8A:
	movs r0, #1
	rsbs r0, r0, #0
	b _081DAEAE
	.align 2, 0
_081DAE90: .4byte 0x03002C68
_081DAE94:
	ldr r3, _081DAEB4 @ =0x00000322
	adds r0, r2, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	strb r0, [r1, #1]
	adds r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	strb r0, [r1, #2]
	movs r0, #0
_081DAEAE:
	pop {r1}
	bx r1
	.align 2, 0
_081DAEB4: .4byte 0x00000322

	thumb_func_start FUN_081daeb8
FUN_081daeb8: @ 0x081DAEB8
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _081DAF30 @ =0x0000C091
	ldr r1, _081DAF34 @ =0x0000CD91
	bl GetFile
	adds r2, r0, #0
	str r2, [r5, #0x18]
	movs r0, #8
	str r0, [sp, #0xc]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _081DAF38 @ =0x000092B3
	ldr r1, _081DAF3C @ =0x000026BB
	bl GetFile
	adds r0, #0x14
	str r0, [r5, #0x1c]
	ldr r1, _081DAF40 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	movs r5, #3
_081DAF0A:
	adds r0, r4, #0
	adds r0, #0x19
	adds r1, r4, #0
	adds r1, #0x16
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl FUN_080e1238
	adds r4, #1
	cmp r4, #4
	ble _081DAF0A
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DAF30: .4byte 0x0000C091
_081DAF34: .4byte 0x0000CD91
_081DAF38: .4byte 0x000092B3
_081DAF3C: .4byte 0x000026BB
_081DAF40: .4byte 0x03004250

	thumb_func_start FUN_081daf44
FUN_081daf44: @ 0x081DAF44
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldr r1, _081DAF94 @ =0x0000032D
	adds r0, r3, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _081DAF98 @ =0x00000323
	adds r0, r3, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r3, r2
	strb r1, [r0]
	ldr r0, _081DAF9C @ =0x00000326
	adds r1, r3, r0
	movs r0, #3
	strb r0, [r1]
	adds r2, #3
	adds r1, r3, r2
	movs r0, #4
	strb r0, [r1]
	movs r6, #0
	ldr r0, _081DAFA0 @ =0x03002C68
	ldr r0, [r0]
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, #0
	beq _081DAF7C
	ldrh r5, [r0, #0x1a]
_081DAF7C:
	movs r1, #0
	cmp r6, r5
	bge _081DAFB6
	adds r2, r0, #0
	movs r4, #0xd2
	lsls r4, r4, #1
_081DAF88:
	cmp r2, #0
	beq _081DAF90
	cmp r1, #0
	bge _081DAFA4
_081DAF90:
	movs r0, #0
	b _081DAFA6
	.align 2, 0
_081DAF94: .4byte 0x0000032D
_081DAF98: .4byte 0x00000323
_081DAF9C: .4byte 0x00000326
_081DAFA0: .4byte 0x03002C68
_081DAFA4:
	adds r0, r2, r4
_081DAFA6:
	ldr r0, [r0, #0x18]
	cmp r0, #2
	bhi _081DAFAE
	movs r6, #1
_081DAFAE:
	adds r4, #0x48
	adds r1, #1
	cmp r1, r5
	blt _081DAF88
_081DAFB6:
	cmp r6, #0
	beq _081DAFD4
	ldr r1, _081DAFCC @ =0x00000325
	adds r0, r3, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _081DAFD0 @ =0x00000322
	adds r0, r3, r2
	strb r1, [r0]
	b _081DAFE2
	.align 2, 0
_081DAFCC: .4byte 0x00000325
_081DAFD0: .4byte 0x00000322
_081DAFD4:
	ldr r1, _081DAFE8 @ =0x00000325
	adds r0, r3, r1
	movs r1, #2
	strb r1, [r0]
	ldr r2, _081DAFEC @ =0x00000322
	adds r0, r3, r2
	strb r6, [r0]
_081DAFE2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DAFE8: .4byte 0x00000325
_081DAFEC: .4byte 0x00000322

	thumb_func_start FUN_081daff0
FUN_081daff0: @ 0x081DAFF0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _081DB008 @ =0x0000032D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DB020
	cmp r0, #1
	bgt _081DB00C
	cmp r0, #0
	beq _081DB012
	b _081DB03C
	.align 2, 0
_081DB008: .4byte 0x0000032D
_081DB00C:
	cmp r0, #2
	beq _081DB030
	b _081DB03C
_081DB012:
	ldr r1, _081DB01C @ =0x00000322
	adds r0, r5, r1
	ldrb r1, [r0]
	b _081DB03E
	.align 2, 0
_081DB01C: .4byte 0x00000322
_081DB020:
	ldr r1, _081DB02C @ =0x00000323
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r1, r0, #2
	b _081DB03E
	.align 2, 0
_081DB02C: .4byte 0x00000323
_081DB030:
	movs r1, #0xc9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r1, r0, #5
	b _081DB03E
_081DB03C:
	movs r1, #0
_081DB03E:
	ldr r0, _081DB070 @ =0x0000032B
	adds r6, r5, r0
	movs r0, #0
	ldrsb r0, [r6, r0]
	adds r4, r1, #0
	adds r4, #9
	cmp r0, r4
	beq _081DB06A
	bl FUN_08049e5c
	movs r1, #0xc3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	bl FUN_08049e30
	strb r4, [r6]
_081DB06A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DB070: .4byte 0x0000032B

	thumb_func_start FUN_081db074
FUN_081db074: @ 0x081DB074
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r0, #0x16
	movs r1, #4
	movs r2, #6
	movs r3, #2
	bl TextPanel_Create
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r5, r7, r1
	str r0, [r5]
	movs r0, #0x14
	movs r1, #0xc
	movs r2, #8
	movs r3, #2
	bl TextPanel_Create
	movs r2, #0xc7
	lsls r2, r2, #2
	adds r6, r7, r2
	str r0, [r6]
	bl FUN_08049e5c
	bl FUN_08049f84
	movs r0, #0xc4
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r7, #0
	bl FUN_081daf44
	ldr r0, [r5]
	movs r1, #0xc3
	lsls r1, r1, #2
	adds r1, r1, r7
	mov r8, r1
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r5]
	ldr r2, _081DB120 @ =0x00000322
	adds r4, r7, r2
	ldrb r1, [r4]
	bl TextPanel_SetMessage
	ldr r0, [r5]
	bl TextPanel_Start
	ldrb r1, [r4]
	movs r2, #0xca
	lsls r2, r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	ldr r0, [r6]
	mov r2, r8
	ldr r1, [r2]
	bl TextPanel_SetScript
	ldr r0, [r6]
	movs r1, #0xc9
	lsls r1, r1, #2
	adds r4, r7, r1
	ldrb r1, [r4]
	adds r1, #5
	bl TextPanel_SetMessage
	ldr r0, [r6]
	bl TextPanel_Start
	ldrb r1, [r4]
	ldr r2, _081DB124 @ =0x0000032A
	adds r0, r7, r2
	strb r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DB120: .4byte 0x00000322
_081DB124: .4byte 0x0000032A

	thumb_func_start FUN_081db128
FUN_081db128: @ 0x081DB128
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	movs r1, #0xc7
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081db14c
FUN_081db14c: @ 0x081DB14C
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _081DB17C @ =0x0000CB05
	ldr r1, _081DB180 @ =0x0000DCC1
	bl GetFile
	adds r1, r0, #0
	movs r2, #0xb8
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	subs r2, #0x20
	adds r0, r4, r2
	bl OpenMainSpriteFile
	movs r5, #0
_081DB16E:
	cmp r5, #6
	bhi _081DB1B4
	lsls r0, r5, #2
	ldr r1, _081DB184 @ =_081DB188
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081DB17C: .4byte 0x0000CB05
_081DB180: .4byte 0x0000DCC1
_081DB184: .4byte _081DB188
_081DB188: @ jump table
	.4byte _081DB1A4 @ case 0
	.4byte _081DB1A8 @ case 1
	.4byte _081DB1AC @ case 2
	.4byte _081DB1B4 @ case 3
	.4byte _081DB1B4 @ case 4
	.4byte _081DB1B4 @ case 5
	.4byte _081DB1B0 @ case 6
_081DB1A4:
	movs r2, #0x33
	b _081DB1B6
_081DB1A8:
	movs r2, #0x34
	b _081DB1B6
_081DB1AC:
	movs r2, #0x35
	b _081DB1B6
_081DB1B0:
	movs r2, #0x15
	b _081DB1B6
_081DB1B4:
	movs r2, #0
_081DB1B6:
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r3, r4, r0
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #5
	adds r0, #0x20
	adds r0, r4, r0
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	adds r1, r3, #0
	movs r3, #0x10
	bl MainSprite_Add
	adds r5, #1
	cmp r5, #6
	ble _081DB16E
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081db1e8
FUN_081db1e8: @ 0x081DB1E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r2, r0, #0
	movs r4, #0
	ldr r0, _081DB220 @ =0x085AE1B4
	mov sl, r0
	ldr r1, _081DB224 @ =0x0000032D
	adds r3, r2, r1
	movs r7, #4
	add r7, sl
	mov sb, r7
	ldr r6, _081DB228 @ =0x085AE1CC
	adds r0, r6, #4
	mov r8, r0
	ldr r5, _081DB22C @ =0x085AE1E4
	adds r1, r5, #4
	mov ip, r1
_081DB210:
	cmp r4, #1
	beq _081DB252
	cmp r4, #1
	bgt _081DB230
	cmp r4, #0
	beq _081DB236
	b _081DB28C
	.align 2, 0
_081DB220: .4byte 0x085AE1B4
_081DB224: .4byte 0x0000032D
_081DB228: .4byte 0x085AE1CC
_081DB22C: .4byte 0x085AE1E4
_081DB230:
	cmp r4, #2
	beq _081DB26E
	b _081DB28C
_081DB236:
	ldrb r0, [r3]
	lsls r0, r0, #3
	add r0, sl
	ldr r1, [r0]
	adds r0, r2, #0
	adds r0, #0x40
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #3
	add r0, sb
	ldr r0, [r0]
	adds r1, r2, #0
	adds r1, #0x42
	b _081DB28A
_081DB252:
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	adds r0, r2, #0
	adds r0, #0xa0
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #3
	add r0, r8
	ldr r0, [r0]
	adds r1, r2, #0
	adds r1, #0xa2
	b _081DB28A
_081DB26E:
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldr r1, [r0]
	movs r7, #0x80
	lsls r7, r7, #1
	adds r0, r2, r7
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #3
	add r0, ip
	ldr r0, [r0]
	adds r7, #2
	adds r1, r2, r7
_081DB28A:
	strh r0, [r1]
_081DB28C:
	adds r4, #1
	cmp r4, #6
	ble _081DB210
	adds r4, r2, #0
	adds r4, #0x88
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r3, r2, #0
	adds r3, #0xe8
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	ldr r1, _081DB2E8 @ =0x0000032D
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081DB2CA
	ldr r7, _081DB2EC @ =0x00000325
	adds r0, r2, r7
	ldrb r1, [r0]
	cmp r1, #1
	bne _081DB2CA
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081DB2CA:
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r2, r1
	movs r1, #0
	strh r1, [r0]
	ldr r3, _081DB2F0 @ =0x00000282
	adds r0, r2, r3
	strh r1, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DB2E8: .4byte 0x0000032D
_081DB2EC: .4byte 0x00000325
_081DB2F0: .4byte 0x00000282

	thumb_func_start FUN_081db2f4
FUN_081db2f4: @ 0x081DB2F4
	push {lr}
	movs r3, #1
	adds r1, r0, #0
	adds r1, #0x28
	movs r2, #6
_081DB2FE:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _081DB2FE
	pop {r0}
	bx r0

	thumb_func_start FUN_081db310
FUN_081db310: @ 0x081DB310
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x20
	movs r5, #6
_081DB318:
	adds r0, r4, #0
	bl MainSprite_Remove
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081DB318
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081db32c
FUN_081db32c: @ 0x081DB32C
	push {lr}
	mov ip, r0
	ldr r0, _081DB368 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _081DB36C @ =0x00005260
	adds r2, r0, r1
	movs r1, #0xb9
	lsls r1, r1, #2
	add r1, ip
	movs r3, #0xf
_081DB340:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _081DB340
	movs r0, #0xb9
	lsls r0, r0, #2
	add r0, ip
	mov r1, ip
	str r0, [r1, #0x68]
	movs r1, #0xc1
	lsls r1, r1, #2
	add r1, ip
	movs r0, #0
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_081DB368: .4byte 0x03003584
_081DB36C: .4byte 0x00005260

	thumb_func_start FUN_081db370
FUN_081db370: @ 0x081DB370
	push {lr}
	adds r3, r0, #0
	movs r1, #0xc1
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrh r0, [r0]
	movs r2, #0x1f
	cmp r0, #9
	bls _081DB39C
	movs r2, #0x1b
	cmp r0, #0x11
	bls _081DB39C
	movs r2, #0x12
	cmp r0, #0x19
	bls _081DB39C
	movs r2, #0xa
	cmp r0, #0x21
	bls _081DB39C
	movs r2, #0x1b
	cmp r0, #0x29
	bhi _081DB39C
	movs r2, #0x12
_081DB39C:
	movs r0, #0xc1
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x31
	bls _081DB3B4
	movs r0, #0
	strh r0, [r1]
_081DB3B4:
	movs r1, #0xbf
	lsls r1, r1, #2
	adds r0, r3, r1
	strh r2, [r0]
	pop {r0}
	bx r0

	thumb_func_start FUN_081db3c0
FUN_081db3c0: @ 0x081DB3C0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	cmp r4, #0x63
	ble _081DB410
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0xcc
	strh r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0x40
	strh r2, [r0]
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0xc4
	strh r0, [r1]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	adds r3, #0x60
	adds r1, r5, r3
	movs r0, #0xbc
	strh r0, [r1]
	ldr r1, _081DB40C @ =0x00000222
	adds r0, r5, r1
	strh r2, [r0]
	subs r3, #0x18
	adds r2, r5, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _081DB440
	.align 2, 0
_081DB40C: .4byte 0x00000222
_081DB410:
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0xc8
	strh r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0x40
	strh r2, [r0]
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0xc0
	strh r0, [r1]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	adds r3, #0x48
	adds r2, r5, r3
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
_081DB440:
	str r0, [r2]
	movs r2, #0
	cmp r4, #0x63
	ble _081DB450
_081DB448:
	adds r2, #1
	subs r4, #0x64
	cmp r4, #0x63
	bgt _081DB448
_081DB450:
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r3, #0xb0
	lsls r3, r3, #2
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	movs r2, #0
	cmp r4, #9
	ble _081DB472
_081DB46A:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081DB46A
_081DB472:
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r3, #0xb0
	lsls r3, r3, #2
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	movs r2, #0
	cmp r4, #0
	ble _081DB494
_081DB48C:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081DB48C
_081DB494:
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r3, #0xb0
	lsls r3, r3, #2
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081db4b0
FUN_081db4b0: @ 0x081DB4B0
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	ldr r1, _081DB4C8 @ =0x0000032D
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DB504
	cmp r0, #1
	bgt _081DB4CC
	cmp r0, #0
	beq _081DB4D2
	b _081DB572
	.align 2, 0
_081DB4C8: .4byte 0x0000032D
_081DB4CC:
	cmp r0, #2
	beq _081DB538
	b _081DB572
_081DB4D2:
	ldr r3, _081DB500 @ =0x00000322
	adds r5, r2, r3
	ldrb r1, [r5]
	movs r0, #0xca
	lsls r0, r0, #2
	adds r6, r2, r0
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r1, r0
	beq _081DB572
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r4, r2, r1
	ldr r0, [r4]
	subs r3, #0x16
	adds r1, r2, r3
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	ldrb r1, [r5]
	b _081DB564
	.align 2, 0
_081DB500: .4byte 0x00000322
_081DB504:
	ldr r0, _081DB52C @ =0x00000323
	adds r5, r2, r0
	ldrb r3, [r5]
	ldr r1, _081DB530 @ =0x00000329
	adds r4, r2, r1
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r3, r0
	beq _081DB572
	ldr r1, _081DB534 @ =0x085AE1FC
	lsls r0, r3, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r2, #0
	bl FUN_081db3c0
	ldrb r0, [r5]
	strb r0, [r4]
	b _081DB572
	.align 2, 0
_081DB52C: .4byte 0x00000323
_081DB530: .4byte 0x00000329
_081DB534: .4byte 0x085AE1FC
_081DB538:
	movs r3, #0xc9
	lsls r3, r3, #2
	adds r5, r2, r3
	ldrb r1, [r5]
	ldr r0, _081DB578 @ =0x0000032A
	adds r6, r2, r0
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r1, r0
	beq _081DB572
	movs r1, #0xc7
	lsls r1, r1, #2
	adds r4, r2, r1
	ldr r0, [r4]
	subs r3, #0x18
	adds r1, r2, r3
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	ldrb r1, [r5]
	adds r1, #5
_081DB564:
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	ldrb r0, [r5]
	strb r0, [r6]
_081DB572:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DB578: .4byte 0x0000032A

	thumb_func_start FUN_081db57c
FUN_081db57c: @ 0x081DB57C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xcb
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081DB5D0
	bl FUN_08049f5c
	movs r2, #1
	movs r0, #0xc4
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	bl FUN_08049e5c
	movs r1, #0xc3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #9
	bl Textbox_LookupString
	bl FUN_08049e30
	adds r0, r5, #0
	bl FUN_081db4b0
	ldr r2, _081DB5F0 @ =0x0000032D
	adds r0, r5, r2
	movs r2, #0
	strb r2, [r0]
	ldr r1, _081DB5F4 @ =0x0000032E
	adds r0, r5, r1
	movs r1, #0
	strh r2, [r0]
	strb r1, [r4]
_081DB5D0:
	ldr r2, _081DB5F4 @ =0x0000032E
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #0x1d
	bhi _081DB5F8
	adds r0, r5, #0
	bl FUN_081db370
	adds r0, r5, #0
	bl FUN_081daff0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _081DB8D0
	.align 2, 0
_081DB5F0: .4byte 0x0000032D
_081DB5F4: .4byte 0x0000032E
_081DB5F8:
	ldr r1, _081DB614 @ =0x0000032D
	adds r0, r5, r1
	ldrb r4, [r0]
	ldr r2, _081DB618 @ =0x00000321
	adds r6, r5, r2
	movs r3, #0
	ldr r1, _081DB61C @ =0x030044E0
	ldrh r2, [r1, #2]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _081DB620
	movs r3, #1
	b _081DB65A
	.align 2, 0
_081DB614: .4byte 0x0000032D
_081DB618: .4byte 0x00000321
_081DB61C: .4byte 0x030044E0
_081DB620:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _081DB62C
	movs r3, #2
	b _081DB65A
_081DB62C:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081DB638
	movs r3, #4
	b _081DB65A
_081DB638:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081DB644
	movs r3, #8
	b _081DB65A
_081DB644:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081DB650
	movs r3, #0x20
	b _081DB65A
_081DB650:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081DB65A
	movs r3, #0x10
_081DB65A:
	ldrh r2, [r1]
	movs r0, #0xf0
	ands r0, r2
	cmp r0, #0
	beq _081DB6A2
	ldrb r0, [r6]
	cmp r0, #0xb
	bls _081DB6A0
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _081DB676
	movs r0, #1
	b _081DB680
_081DB676:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _081DB682
	movs r0, #2
_081DB680:
	orrs r3, r0
_081DB682:
	ldrh r1, [r1]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _081DB690
	movs r0, #4
	b _081DB69A
_081DB690:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081DB69C
	movs r0, #8
_081DB69A:
	orrs r3, r0
_081DB69C:
	movs r0, #0
	b _081DB6A2
_081DB6A0:
	adds r0, #1
_081DB6A2:
	strb r0, [r6]
	movs r1, #0
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	beq _081DB6BA
	cmp r4, #0
	bne _081DB6B6
	movs r4, #2
	b _081DB83C
_081DB6B6:
	subs r4, #1
	b _081DB83C
_081DB6BA:
	movs r0, #2
	ands r0, r3
	cmp r0, #0
	beq _081DB6D8
	cmp r4, #2
	bne _081DB6CA
	movs r4, #0
	b _081DB6CC
_081DB6CA:
	adds r4, #1
_081DB6CC:
	ldr r2, _081DB6D4 @ =0x00000321
	adds r1, r5, r2
	b _081DB840
	.align 2, 0
_081DB6D4: .4byte 0x00000321
_081DB6D8:
	movs r0, #4
	ands r0, r3
	cmp r0, #0
	beq _081DB77A
	ldr r2, _081DB6F4 @ =0x0000032D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DB730
	cmp r0, #1
	bgt _081DB6F8
	cmp r0, #0
	beq _081DB6FE
	b _081DB82C
	.align 2, 0
_081DB6F4: .4byte 0x0000032D
_081DB6F8:
	cmp r0, #2
	beq _081DB750
	b _081DB82C
_081DB6FE:
	ldr r0, _081DB71C @ =0x00000325
	adds r2, r5, r0
	ldrb r0, [r2]
	cmp r0, #1
	bne _081DB70A
	b _081DB82C
_081DB70A:
	ldr r1, _081DB720 @ =0x00000322
	adds r0, r5, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _081DB724
	ldrb r0, [r2]
	subs r1, r0, #1
	b _081DB726
	.align 2, 0
_081DB71C: .4byte 0x00000325
_081DB720: .4byte 0x00000322
_081DB724:
	subs r1, #1
_081DB726:
	ldr r2, _081DB72C @ =0x00000322
	b _081DB7F8
	.align 2, 0
_081DB72C: .4byte 0x00000322
_081DB730:
	ldr r1, _081DB744 @ =0x00000323
	adds r0, r5, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _081DB74C
	ldr r2, _081DB748 @ =0x00000326
	adds r0, r5, r2
	ldrb r0, [r0]
	subs r1, r0, #1
	b _081DB7F6
	.align 2, 0
_081DB744: .4byte 0x00000323
_081DB748: .4byte 0x00000326
_081DB74C:
	subs r1, #1
	b _081DB7F6
_081DB750:
	movs r1, #0xc9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _081DB76C
	ldr r2, _081DB768 @ =0x00000327
	adds r0, r5, r2
	ldrb r0, [r0]
	subs r1, r0, #1
	b _081DB76E
	.align 2, 0
_081DB768: .4byte 0x00000327
_081DB76C:
	subs r1, #1
_081DB76E:
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	movs r1, #1
	b _081DB830
_081DB77A:
	movs r0, #8
	ands r0, r3
	cmp r0, #0
	beq _081DB84C
	ldr r2, _081DB798 @ =0x0000032D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DB7D4
	cmp r0, #1
	bgt _081DB79C
	cmp r0, #0
	beq _081DB7A2
	b _081DB82C
	.align 2, 0
_081DB798: .4byte 0x0000032D
_081DB79C:
	cmp r0, #2
	beq _081DB804
	b _081DB82C
_081DB7A2:
	ldr r0, _081DB7C0 @ =0x00000325
	adds r2, r5, r0
	ldrb r0, [r2]
	cmp r0, #1
	beq _081DB82C
	ldr r1, _081DB7C4 @ =0x00000322
	adds r0, r5, r1
	ldrb r1, [r0]
	ldrb r0, [r2]
	subs r0, #1
	cmp r1, r0
	bne _081DB7C8
	movs r1, #0
	b _081DB7CA
	.align 2, 0
_081DB7C0: .4byte 0x00000325
_081DB7C4: .4byte 0x00000322
_081DB7C8:
	adds r1, #1
_081DB7CA:
	ldr r2, _081DB7D0 @ =0x00000322
	b _081DB7F8
	.align 2, 0
_081DB7D0: .4byte 0x00000322
_081DB7D4:
	ldr r1, _081DB7EC @ =0x00000323
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _081DB7F0 @ =0x00000326
	adds r0, r5, r2
	ldrb r0, [r0]
	subs r0, #1
	cmp r1, r0
	bne _081DB7F4
	movs r1, #0
	b _081DB7F6
	.align 2, 0
_081DB7EC: .4byte 0x00000323
_081DB7F0: .4byte 0x00000326
_081DB7F4:
	adds r1, #1
_081DB7F6:
	ldr r2, _081DB800 @ =0x00000323
_081DB7F8:
	adds r0, r5, r2
	strb r1, [r0]
	b _081DB830
	.align 2, 0
_081DB800: .4byte 0x00000323
_081DB804:
	movs r1, #0xc9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _081DB81C @ =0x00000327
	adds r0, r5, r2
	ldrb r0, [r0]
	subs r0, #1
	cmp r1, r0
	bne _081DB820
	movs r1, #0
	b _081DB822
	.align 2, 0
_081DB81C: .4byte 0x00000327
_081DB820:
	adds r1, #1
_081DB822:
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	movs r1, #1
_081DB82C:
	cmp r1, #0
	beq _081DB83C
_081DB830:
	adds r0, r5, #0
	bl FUN_081db4b0
	movs r0, #0xdc
	bl PlaySound_082406e0
_081DB83C:
	ldr r0, _081DB848 @ =0x00000321
	adds r1, r5, r0
_081DB840:
	movs r0, #0
	strb r0, [r1]
	b _081DB8AC
	.align 2, 0
_081DB848: .4byte 0x00000321
_081DB84C:
	movs r0, #0x20
	ands r0, r3
	cmp r0, #0
	beq _081DB87E
	adds r0, r5, #0
	bl FUN_081dae74
	movs r0, #1
	bl FUN_081df95c
	movs r0, #0xdd
	bl PlaySound_082406e0
	bl FUN_08049fa8
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r5, #0
	bl FUN_081db2f4
	b _081DB8A4
_081DB87E:
	movs r0, #0x10
	ands r3, r0
	cmp r3, #0
	beq _081DB8AC
	movs r0, #2
	bl FUN_081df95c
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r5, #0
	bl FUN_081db2f4
	movs r0, #0xde
	bl PlaySound_082406e0
_081DB8A4:
	adds r0, r5, #0
	bl KillEntity
	b _081DB8D0
_081DB8AC:
	ldr r2, _081DB8D8 @ =0x0000032D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, r4
	beq _081DB8C4
	strb r4, [r1]
	adds r0, r5, #0
	bl FUN_081db1e8
	movs r0, #0xdc
	bl PlaySound_082406e0
_081DB8C4:
	adds r0, r5, #0
	bl FUN_081db370
	adds r0, r5, #0
	bl FUN_081daff0
_081DB8D0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DB8D8: .4byte 0x0000032D

	thumb_func_start Entity08F4_Update
Entity08F4_Update: @ 0x081DB8DC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dfa04
	cmp r0, #0
	bne _081DB8FE
	bl FUN_08049fa8
	adds r0, r4, #0
	bl FUN_081db2f4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #1
	rsbs r0, r0, #0
	b _081DB912
_081DB8FE:
	movs r1, #0xc2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081DB910
	adds r0, r4, #0
	bl _call_via_r1
_081DB910:
	movs r0, #1
_081DB912:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start Entity08F4_Destroy
Entity08F4_Destroy: @ 0x081DB918
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081db310
	adds r0, r4, #0
	bl FUN_081db128
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity08F4_Init
Entity08F4_Init: @ 0x081DB930
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081DB954
	bl FUN_0823d340
	movs r2, #0xc3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	bne _081DB954
	movs r0, #1
	rsbs r0, r0, #0
	b _081DB9A4
_081DB954:
	movs r0, #0
	bl ClearBGTilemapBuffer
	adds r0, r4, #0
	bl FUN_081daeb8
	adds r0, r4, #0
	bl FUN_081db074
	adds r0, r4, #0
	bl FUN_081db14c
	adds r0, r4, #0
	bl FUN_081db1e8
	adds r0, r4, #0
	bl FUN_081db32c
	adds r0, r4, #0
	movs r1, #0x3c
	bl FUN_081db3c0
	ldr r3, _081DB9AC @ =0x00000329
	adds r0, r4, r3
	movs r2, #0
	strb r2, [r0]
	ldr r1, _081DB9B0 @ =FUN_081db57c
	subs r3, #0x21
	adds r0, r4, r3
	str r1, [r0]
	movs r0, #0xcb
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xc8
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #1
_081DB9A4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DB9AC: .4byte 0x00000329
_081DB9B0: .4byte FUN_081db57c

	thumb_func_start Entity08F4_Create
Entity08F4_Create: @ 0x081DB9B4
	push {r4, lr}
	movs r1, #0xcc
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081DB9EC
	ldr r1, _081DB9E4 @ =Entity08F4_Update
	ldr r2, _081DB9E8 @ =Entity08F4_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity08F4_Init
	cmp r0, #0
	bge _081DB9EC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081DB9EE
	.align 2, 0
_081DB9E4: .4byte Entity08F4_Update
_081DB9E8: .4byte Entity08F4_Destroy
_081DB9EC:
	adds r0, r4, #0
_081DB9EE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081db9f4
FUN_081db9f4: @ 0x081DB9F4
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _081DBA40 @ =0x0000C091
	ldr r1, _081DBA44 @ =0x0000CD91
	bl GetFile
	adds r2, r0, #0
	str r2, [r4, #0x18]
	movs r0, #7
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	ldr r0, _081DBA48 @ =0x000092B3
	ldr r1, _081DBA4C @ =0x000026BB
	bl GetFile
	adds r0, #0x14
	str r0, [r4, #0x1c]
	ldr r1, _081DBA50 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DBA40: .4byte 0x0000C091
_081DBA44: .4byte 0x0000CD91
_081DBA48: .4byte 0x000092B3
_081DBA4C: .4byte 0x000026BB
_081DBA50: .4byte 0x03004250

	thumb_func_start FUN_081dba54
FUN_081dba54: @ 0x081DBA54
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x1c]
	adds r0, #0x40
	movs r2, #0xe2
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r2, #0x10
	bl CpuSet
	movs r0, #0xea
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dba78
FUN_081dba78: @ 0x081DBA78
	push {r4, lr}
	adds r2, r0, #0
	movs r1, #0xf2
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	bge _081DBAC0
	ldr r3, _081DBAB4 @ =0x0000039A
	adds r0, r2, r3
	ldr r1, _081DBAB8 @ =0x00006739
	strh r1, [r0]
	adds r3, #4
	adds r0, r2, r3
	strh r1, [r0]
	adds r3, #4
	adds r0, r2, r3
	strh r1, [r0]
	adds r3, #4
	adds r0, r2, r3
	strh r1, [r0]
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r1, _081DBABC @ =0x03004290
	movs r2, #0x10
	bl CpuSet
	b _081DBC08
	.align 2, 0
_081DBAB4: .4byte 0x0000039A
_081DBAB8: .4byte 0x00006739
_081DBABC: .4byte 0x03004290
_081DBAC0:
	movs r3, #0xea
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	movs r3, #0x1f
	cmp r0, #9
	bls _081DBAE8
	movs r3, #0x1b
	cmp r0, #0x11
	bls _081DBAE8
	movs r3, #0x12
	cmp r0, #0x19
	bls _081DBAE8
	movs r3, #0xa
	cmp r0, #0x21
	bls _081DBAE8
	movs r3, #0x1b
	cmp r0, #0x29
	bhi _081DBAE8
	movs r3, #0x12
_081DBAE8:
	movs r0, #0xea
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	movs r4, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x31
	bls _081DBB02
	movs r0, #0
	strh r0, [r1]
_081DBB02:
	movs r1, #0xeb
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081DBB20
	ldr r0, _081DBB18 @ =0x0000039A
	adds r1, r2, r0
	ldr r0, _081DBB1C @ =0x00006739
	b _081DBB26
	.align 2, 0
_081DBB18: .4byte 0x0000039A
_081DBB1C: .4byte 0x00006739
_081DBB20:
	ldr r0, _081DBB3C @ =0x0000039A
	adds r1, r2, r0
	ldr r0, _081DBB40 @ =0x000035B4
_081DBB26:
	strh r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081DBB4C
	ldr r0, _081DBB44 @ =0x0000039E
	adds r1, r2, r0
	ldr r0, _081DBB48 @ =0x00006739
	b _081DBB52
	.align 2, 0
_081DBB3C: .4byte 0x0000039A
_081DBB40: .4byte 0x000035B4
_081DBB44: .4byte 0x0000039E
_081DBB48: .4byte 0x00006739
_081DBB4C:
	ldr r0, _081DBB68 @ =0x0000039E
	adds r1, r2, r0
	ldr r0, _081DBB6C @ =0x000035B4
_081DBB52:
	strh r0, [r1]
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081DBB78
	ldr r0, _081DBB70 @ =0x000003A2
	adds r1, r2, r0
	ldr r0, _081DBB74 @ =0x00006739
	b _081DBB7E
	.align 2, 0
_081DBB68: .4byte 0x0000039E
_081DBB6C: .4byte 0x000035B4
_081DBB70: .4byte 0x000003A2
_081DBB74: .4byte 0x00006739
_081DBB78:
	ldr r0, _081DBB94 @ =0x000003A2
	adds r1, r2, r0
	ldr r0, _081DBB98 @ =0x000035B4
_081DBB7E:
	strh r0, [r1]
	movs r1, #0xee
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081DBBA4
	ldr r0, _081DBB9C @ =0x000003A6
	adds r1, r2, r0
	ldr r0, _081DBBA0 @ =0x00006739
	b _081DBBAA
	.align 2, 0
_081DBB94: .4byte 0x000003A2
_081DBB98: .4byte 0x000035B4
_081DBB9C: .4byte 0x000003A6
_081DBBA0: .4byte 0x00006739
_081DBBA4:
	ldr r0, _081DBBC4 @ =0x000003A6
	adds r1, r2, r0
	ldr r0, _081DBBC8 @ =0x000035B4
_081DBBAA:
	strh r0, [r1]
	movs r1, #0xf2
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #1
	beq _081DBBDC
	cmp r0, #1
	bgt _081DBBCC
	cmp r0, #0
	beq _081DBBD6
	b _081DBBFA
	.align 2, 0
_081DBBC4: .4byte 0x000003A6
_081DBBC8: .4byte 0x000035B4
_081DBBCC:
	cmp r0, #2
	beq _081DBBE2
	cmp r0, #3
	beq _081DBBE8
	b _081DBBFA
_081DBBD6:
	movs r1, #0xeb
	lsls r1, r1, #2
	b _081DBBEC
_081DBBDC:
	movs r1, #0xec
	lsls r1, r1, #2
	b _081DBBEC
_081DBBE2:
	movs r1, #0xed
	lsls r1, r1, #2
	b _081DBBEC
_081DBBE8:
	movs r1, #0xee
	lsls r1, r1, #2
_081DBBEC:
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081DBBFA
	subs r1, #0x12
	adds r0, r2, r1
	strh r3, [r0]
_081DBBFA:
	movs r3, #0xe2
	lsls r3, r3, #2
	adds r0, r2, r3
	ldr r1, _081DBC10 @ =0x03004290
	movs r2, #0x10
	bl CpuSet
_081DBC08:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DBC10: .4byte 0x03004290

	thumb_func_start FUN_081dbc14
FUN_081dbc14: @ 0x081DBC14
	movs r2, #0xd8
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #4
	strh r2, [r1]
	ldr r3, _081DBC58 @ =0x00000362
	adds r1, r0, r3
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r2, r0, r1
	movs r1, #0x3a
	strh r1, [r2]
	adds r3, #4
	adds r2, r0, r3
	movs r1, #0x3b
	strh r1, [r2]
	movs r1, #0xdb
	lsls r1, r1, #2
	adds r2, r0, r1
	movs r1, #0x3c
	strh r1, [r2]
	ldr r2, _081DBC5C @ =0x0000036E
	adds r0, r0, r2
	movs r1, #0x3d
	strh r1, [r0]
	bx lr
	.align 2, 0
_081DBC58: .4byte 0x00000362
_081DBC5C: .4byte 0x0000036E

