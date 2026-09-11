	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08014d94
FUN_08014d94: @ 0x08014D94
	ldr r1, _08014D9C @ =0x0300005C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08014D9C: .4byte 0x0300005C

	thumb_func_start FUN_08014da0
FUN_08014da0: @ 0x08014DA0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r0, [sp]
	adds r5, r1, #0
	str r2, [sp, #4]
	str r3, [sp, #8]
	ldr r0, _08014DD0 @ =0x0300005C
	ldr r0, [r0]
	cmp r0, #0
	bne _08014DD4
	movs r0, #0
	movs r1, #0
	bl FUN_08015220
	cmp r0, #0
	bne _08014DD4
_08014DC8:
	movs r0, #1
	rsbs r0, r0, #0
	b _08015062
	.align 2, 0
_08014DD0: .4byte 0x0300005C
_08014DD4:
	ldr r0, _08014E74 @ =0x0300005C
	ldr r0, [r0]
	ldr r1, [sp]
	cmp r1, #6
	ble _08014DE2
	movs r2, #6
	str r2, [sp]
_08014DE2:
	movs r1, #0
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #0x52
	adds r2, r2, r0
	mov sb, r2
	adds r2, r0, #0
	adds r2, #0x46
	str r2, [sp, #0x14]
	adds r4, r0, #0
	adds r4, #0x24
	mov r8, r7
_08014DFA:
	ldrb r0, [r7]
	cmp r0, #0
	beq _08014E02
	b _08015046
_08014E02:
	strb r5, [r7, #2]
	mov r0, sp
	ldrb r0, [r0]
	strb r0, [r7, #1]
	ldr r1, _08014E78 @ =0x085AA902
	ldrb r0, [r7, #2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl Video_GetActorSprite
	str r4, [sp, #0xc]
	cmp r0, #0
	beq _08014DC8
	ldrb r0, [r7, #2]
	cmp r0, #4
	beq _08014E2A
	cmp r0, #8
	bne _08014E34
_08014E2A:
	ldrh r1, [r7, #0xa]
	adds r1, #1
	adds r0, r4, #0
	bl Video_SetActorSpritePltt
_08014E34:
	movs r3, #0
	ldr r1, [sp]
	cmp r3, r1
	blt _08014E3E
	b _08015040
_08014E3E:
	ldr r6, _08014E7C @ =0x030046B8
	mov r0, r8
	adds r2, r0, #0
	str r2, [sp, #0x10]
	mov r5, r8
	adds r5, #0x40
	mov sl, sb
	ldr r1, [sp, #0x14]
	mov sb, r1
_08014E50:
	movs r0, #0x2c
	muls r0, r3, r0
	adds r0, #0x70
	mov r2, r8
	adds r4, r2, r0
	mov r0, r8
	adds r0, #0x20
	adds r0, r0, r3
	movs r1, #1
	strb r1, [r0]
	ldr r0, [sp, #0x40]
	cmp r0, #0
	bne _08014E80
	add r1, sp, #0x3c
	ldrb r2, [r1]
	mov r1, sb
	strb r2, [r1]
	b _08014EA4
	.align 2, 0
_08014E74: .4byte 0x0300005C
_08014E78: .4byte 0x085AA902
_08014E7C: .4byte 0x030046B8
_08014E80:
	ldr r0, [r6]
	adds r0, #1
	ldr r2, _08014EB4 @ =0x000003FF
	ands r0, r2
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _08014EB8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [sp, #0x40]
	str r3, [sp, #0x18]
	bl Mod
	ldr r2, [sp, #0x3c]
	adds r0, r2, r0
	mov r1, sb
	strb r0, [r1]
	ldr r3, [sp, #0x18]
_08014EA4:
	ldr r2, [sp, #0x48]
	cmp r2, #0
	bne _08014EBC
	add r0, sp, #0x44
	ldrh r1, [r0]
	mov r0, sl
	strh r1, [r0]
	b _08014EE0
	.align 2, 0
_08014EB4: .4byte 0x000003FF
_08014EB8: .4byte 0x0203B400
_08014EBC:
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _08014EEC @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _08014EF0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x48]
	str r3, [sp, #0x18]
	bl Mod
	ldr r1, [sp, #0x44]
	adds r0, r1, r0
	mov r2, sl
	strh r0, [r2]
	ldr r3, [sp, #0x18]
_08014EE0:
	ldr r0, [sp, #0x50]
	cmp r0, #0
	bne _08014EF4
	ldr r2, [sp, #0x4c]
	b _08014F14
	.align 2, 0
_08014EEC: .4byte 0x000003FF
_08014EF0: .4byte 0x0203B400
_08014EF4:
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _08014F40 @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _08014F44 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x50]
	str r3, [sp, #0x18]
	bl Mod
	ldr r1, [sp, #0x4c]
	adds r2, r1, r0
	ldr r3, [sp, #0x18]
_08014F14:
	ldr r0, _08014F48 @ =0x085B0A08
	mov ip, r0
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r5]
	ands r2, r1
	lsls r0, r2, #1
	add r0, ip
	ldrh r0, [r0]
	strh r0, [r5, #4]
	ldr r2, [sp, #0x58]
	cmp r2, #0
	bne _08014F4C
	add r0, sp, #0x54
	ldrh r0, [r0]
	strh r0, [r5, #2]
	b _08014F72
	.align 2, 0
_08014F40: .4byte 0x000003FF
_08014F44: .4byte 0x0203B400
_08014F48: .4byte 0x085B0A08
_08014F4C:
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _08014F98 @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _08014F9C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x58]
	str r3, [sp, #0x18]
	bl Mod
	ldr r1, [sp, #0x54]
	adds r0, r1, r0
	ldr r1, [sp, #0x10]
	adds r1, #0x42
	strh r0, [r1]
	ldr r3, [sp, #0x18]
_08014F72:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r2, [sp, #4]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	movs r1, #0
	ldrsh r0, [r5, r1]
	ldr r2, [sp, #8]
	muls r0, r2, r0
	cmp r0, #0
	blt _08014FA0
	asrs r1, r0, #0xc
	b _08014FA6
	.align 2, 0
_08014F98: .4byte 0x000003FF
_08014F9C: .4byte 0x0203B400
_08014FA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08014FA6:
	ldrh r0, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	movs r1, #4
	ldrsh r0, [r5, r1]
	ldr r2, [sp, #8]
	muls r0, r2, r0
	cmp r0, #0
	blt _08014FBC
	asrs r1, r0, #0xc
	b _08014FC2
_08014FBC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08014FC2:
	ldrh r0, [r4, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	adds r0, r4, #0
	ldr r1, [sp, #0xc]
	movs r2, #0x80
	lsls r2, r2, #2
	str r3, [sp, #0x18]
	bl FUN_0822a470
	ldr r1, _08015008 @ =0x085AA8F0
	ldrb r0, [r7, #2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x10]
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _0801500C @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _08015010 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xff
	ands r0, r1
	ldr r3, [sp, #0x18]
	cmp r0, #0x80
	bgt _08015014
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _0801501C
	.align 2, 0
_08015008: .4byte 0x085AA8F0
_0801500C: .4byte 0x000003FF
_08015010: .4byte 0x0203B400
_08015014:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0801501C:
	str r0, [r4]
	mov r0, r8
	adds r0, #0x2c
	adds r0, r0, r3
	movs r1, #1
	strb r1, [r0]
	ldr r2, [sp, #0x10]
	adds r2, #8
	str r2, [sp, #0x10]
	adds r5, #8
	movs r0, #2
	add sl, r0
	add sb, r1
	adds r3, #1
	ldr r1, [sp]
	cmp r3, r1
	bge _08015040
	b _08014E50
_08015040:
	movs r0, #1
	strb r0, [r7]
	b _08015060
_08015046:
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r7, r7, r2
	add sb, r2
	ldr r0, [sp, #0x14]
	adds r0, r0, r2
	str r0, [sp, #0x14]
	adds r4, r4, r2
	add r8, r2
	adds r1, #1
	cmp r1, #3
	bgt _08015060
	b _08014DFA
_08015060:
	movs r0, #0
_08015062:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08015074
FUN_08015074: @ 0x08015074
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r1, #0
	movs r0, #0
	strb r0, [r4, #1]
	mov r8, r0
	adds r7, r4, #0
	adds r7, #0x2c
	adds r5, r4, #0
	adds r5, #0x42
	mov sl, r0
	movs r0, #0x40
	adds r0, r0, r4
	mov sb, r0
_08015096:
	movs r0, #0x2c
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, #0x70
	adds r3, r4, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _08015124
	mov r6, sb
	movs r0, #0
	ldrsh r2, [r6, r0]
	adds r1, r4, #0
	adds r1, #0x32
	mov r6, sl
	adds r0, r1, r6
	ldrh r0, [r0]
	muls r0, r2, r0
	adds r6, r1, #0
	cmp r0, #0
	blt _080150C4
	asrs r2, r0, #0xc
	b _080150CA
_080150C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080150CA:
	ldrh r0, [r3, #0x1c]
	adds r0, r0, r2
	strh r0, [r3, #0x1c]
	ldrh r0, [r5]
	ldrh r1, [r3, #0x1e]
	adds r0, r0, r1
	strh r0, [r3, #0x1e]
	movs r2, #2
	ldrsh r1, [r5, r2]
	mov r2, sl
	adds r0, r6, r2
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080150EC
	asrs r1, r0, #0xc
	b _080150F2
_080150EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080150F2:
	ldrh r0, [r3, #0x20]
	adds r0, r0, r1
	movs r2, #0
	strh r0, [r3, #0x20]
	ldrh r0, [r5]
	subs r0, #2
	strh r0, [r5]
	adds r1, r4, #0
	adds r1, #0x26
	add r1, r8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0801511E
	strb r2, [r7]
	adds r0, r3, #0
	bl FUN_0822a4e0
	b _08015124
_0801511E:
	ldrb r0, [r4, #1]
	adds r0, #1
	strb r0, [r4, #1]
_08015124:
	adds r7, #1
	adds r5, #8
	movs r6, #2
	add sl, r6
	movs r0, #8
	add sb, r0
	movs r1, #1
	add r8, r1
	mov r2, r8
	cmp r2, #5
	ble _08015096
	ldrb r0, [r4, #1]
	cmp r0, #0
	bne _08015142
	strb r0, [r4]
_08015142:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08015150
FUN_08015150: @ 0x08015150
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x20
	movs r6, #3
_0801515A:
	ldrb r0, [r4]
	cmp r0, #0
	beq _08015168
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08015074
_08015168:
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r4, r4, r0
	subs r6, #1
	cmp r6, #0
	bge _0801515A
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08015184
FUN_08015184: @ 0x08015184
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r1, #0
_0801518E:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	mov r2, r8
	adds r5, r2, r0
	ldrb r0, [r5]
	adds r7, r1, #1
	cmp r0, #0
	beq _080151C6
	movs r4, #0
	adds r6, r5, #0
	adds r6, #0x2c
_080151AC:
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080151C0
	movs r0, #0x2c
	muls r0, r4, r0
	adds r0, #0x70
	adds r0, r5, r0
	bl FUN_0822a4e0
_080151C0:
	adds r4, #1
	cmp r4, #5
	ble _080151AC
_080151C6:
	adds r1, r7, #0
	cmp r1, #3
	ble _0801518E
	ldr r1, _080151DC @ =0x0300005C
	movs r0, #0
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080151DC: .4byte 0x0300005C

	thumb_func_start FUN_080151e0
FUN_080151e0: @ 0x080151E0
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r1, #0
	ldr r5, _0801521C @ =0x0300005C
	movs r4, #0
_080151EA:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	adds r0, r3, r0
	strb r4, [r0]
	adds r2, r1, #1
	movs r1, #5
	adds r0, #0x31
_08015200:
	strb r4, [r0]
	subs r0, #1
	subs r1, #1
	cmp r1, #0
	bge _08015200
	adds r1, r2, #0
	cmp r1, #3
	ble _080151EA
	movs r0, #0
	str r0, [r3, #0x18]
	str r3, [r5]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801521C: .4byte 0x0300005C

	thumb_func_start FUN_08015220
FUN_08015220: @ 0x08015220
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xc0
	lsls r1, r1, #3
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801525C
	ldr r1, _08015254 @ =FUN_08015150
	ldr r2, _08015258 @ =FUN_08015184
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080151e0
	cmp r0, #0
	bge _0801525C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801525E
	.align 2, 0
_08015254: .4byte FUN_08015150
_08015258: .4byte FUN_08015184
_0801525C:
	adds r0, r4, #0
_0801525E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08015264
FUN_08015264: @ 0x08015264
	ldr r1, _0801526C @ =0x03000060
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0801526C: .4byte 0x03000060

	thumb_func_start FUN_08015270
FUN_08015270: @ 0x08015270
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	adds r0, #0x60
	mov sl, r0
	ldr r1, [sp]
	adds r1, #0x24
	mov r8, r1
	mov sb, r8
	movs r2, #0x1f
	str r2, [sp, #4]
_0801528E:
	mov r3, r8
	ldrb r0, [r3]
	cmp r0, #0
	bne _08015298
	b _08015444
_08015298:
	mov r5, sb
	mov r7, sl
	ldrh r0, [r3, #2]
	ldrh r1, [r3, #0xc]
	cmp r0, r1
	blo _080152F0
	movs r2, #6
	ldrsh r1, [r3, r2]
	ldrh r0, [r3, #0xe]
	muls r0, r1, r0
	cmp r0, #0
	blt _080152B4
	asrs r0, r0, #8
	b _080152BA
_080152B4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080152BA:
	strh r0, [r5, #6]
	movs r3, #0x10
	ldrsh r1, [r5, r3]
	movs r2, #6
	ldrsh r0, [r5, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080152CE
	asrs r0, r0, #0xc
	b _080152D4
_080152CE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080152D4:
	strh r0, [r5, #0x18]
	movs r3, #0x14
	ldrsh r1, [r5, r3]
	movs r2, #6
	ldrsh r0, [r5, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080152E8
	asrs r0, r0, #0xc
	b _080152EE
_080152E8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080152EE:
	strh r0, [r5, #0x1c]
_080152F0:
	ldrh r0, [r5, #2]
	ldrh r3, [r5, #8]
	cmp r0, r3
	blo _0801532A
	movs r0, #4
	ldrsh r1, [r5, r0]
	ldrh r0, [r5, #0xa]
	muls r0, r1, r0
	cmp r0, #0
	blt _08015308
	asrs r0, r0, #8
	b _0801530E
_08015308:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801530E:
	strh r0, [r5, #4]
	movs r2, #0x12
	ldrsh r1, [r5, r2]
	movs r3, #4
	ldrsh r0, [r5, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _08015322
	asrs r0, r0, #0xc
	b _08015328
_08015322:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08015328:
	strh r0, [r5, #0x1a]
_0801532A:
	ldrh r0, [r5, #0x18]
	ldrh r1, [r7, #0x1c]
	adds r0, r0, r1
	strh r0, [r7, #0x1c]
	ldrh r0, [r5, #0x1a]
	ldrh r2, [r7, #0x1e]
	adds r0, r0, r2
	strh r0, [r7, #0x1e]
	ldr r0, [r7]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0801534C
	ldrh r0, [r5, #0x1c]
	ldrh r3, [r7, #0x20]
	adds r0, r0, r3
	strh r0, [r7, #0x20]
_0801534C:
	adds r4, r5, #0
	adds r4, #0x68
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x68]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r6]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r1, #1
	ands r0, r1
	cmp r2, r0
	beq _0801537C
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _08015384
_0801537C:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08015384:
	str r0, [r7]
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
	beq _080153A8
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080153B0
_080153A8:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080153B0:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _080153E8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0801542E
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080153F2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080153EC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08015408
	.align 2, 0
_080153E8: .4byte 0x0000FFFF
_080153EC:
	subs r0, #1
	strh r0, [r4, #8]
	b _08015406
_080153F2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08015406
	strh r1, [r4, #8]
	movs r2, #1
	b _08015408
_08015406:
	movs r2, #0
_08015408:
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
	bne _08015430
	movs r3, #1
	strb r3, [r4, #7]
	b _08015430
_0801542E:
	movs r2, #0
_08015430:
	cmp r2, #0
	beq _0801543E
	movs r0, #0
	strb r0, [r5]
	adds r0, r7, #0
	bl FUN_0822a4e0
_0801543E:
	ldrh r0, [r5, #2]
	adds r0, #1
	strh r0, [r5, #2]
_08015444:
	movs r0, #0x78
	add sl, r0
	add sb, r0
	add r8, r0
	ldr r1, [sp, #4]
	subs r1, #1
	str r1, [sp, #4]
	cmp r1, #0
	blt _08015458
	b _0801528E
_08015458:
	ldr r2, [sp]
	ldr r0, [r2, #0x20]
	adds r0, #1
	str r0, [r2, #0x20]
	movs r0, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08015474
FUN_08015474: @ 0x08015474
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r5, #0x60
	adds r4, r0, #0
	adds r4, #0x24
	movs r6, #0x1f
_08015480:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801548C
	adds r0, r5, #0
	bl FUN_0822a4e0
_0801548C:
	adds r5, #0x78
	adds r4, #0x78
	subs r6, #1
	cmp r6, #0
	bge _08015480
	movs r1, #0
	ldr r0, _080154A4 @ =0x03000060
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080154A4: .4byte 0x03000060

	thumb_func_start FUN_080154a8
FUN_080154a8: @ 0x080154A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sl, r0
	ldr r0, _0801551C @ =0x03000060
	mov r1, sl
	str r1, [r0]
	movs r0, #0
	str r0, [sp, #4]
	ldr r4, _08015520 @ =0x085AA914
	mov r7, sl
	adds r7, #0x18
_080154C6:
	ldrh r1, [r4]
	ldr r0, _08015524 @ =0x0000922E
	bl GetFile
	stm r7!, {r0}
	adds r4, #2
	ldr r1, [sp, #4]
	adds r1, #1
	str r1, [sp, #4]
	cmp r1, #1
	ble _080154C6
	ldr r0, _08015528 @ =0xFFFF0000
	movs r5, #0
	ands r6, r0
	movs r0, #0
	str r0, [sp, #4]
	mov sb, r0
	mov r1, sl
	adds r1, #0x8c
	str r1, [sp, #8]
	movs r0, #0x60
	add r0, sl
	mov r8, r0
	mov r7, sl
	adds r7, #0x44
	mov r4, sl
	adds r4, #0x24
_080154FC:
	mov r1, sb
	strb r1, [r4]
	mov r0, sb
	strh r0, [r4, #4]
	strh r0, [r4, #0x10]
	strh r0, [r4, #0x12]
	strh r0, [r4, #0x14]
	adds r0, r7, #0
	ldr r1, _0801552C @ =0x00004384
	bl Video_GetActorSprite
	cmp r0, #0
	bne _08015530
	movs r0, #1
	rsbs r0, r0, #0
	b _08015574
	.align 2, 0
_0801551C: .4byte 0x03000060
_08015520: .4byte 0x085AA914
_08015524: .4byte 0x0000922E
_08015528: .4byte 0xFFFF0000
_0801552C: .4byte 0x00004384
_08015530:
	mov r0, r8
	adds r1, r7, #0
	movs r2, #0
	bl FUN_0822a4b0
	mov r0, sl
	ldr r1, [r0, #0x18]
	mov r0, sb
	str r0, [sp]
	ldr r0, [sp, #8]
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	movs r0, #2
	mov r1, r8
	strb r0, [r1, #7]
	str r5, [r4, #0x58]
	str r6, [r4, #0x5c]
	ldr r0, [sp, #8]
	adds r0, #0x78
	str r0, [sp, #8]
	movs r1, #0x78
	add r8, r1
	adds r7, #0x78
	adds r4, #0x78
	ldr r0, [sp, #4]
	adds r0, #1
	str r0, [sp, #4]
	cmp r0, #0x1f
	ble _080154FC
	movs r0, #0
	mov r1, sl
	str r0, [r1, #0x20]
_08015574:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08015584
FUN_08015584: @ 0x08015584
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _080155B4 @ =0x00000F24
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080155C0
	ldr r1, _080155B8 @ =FUN_08015270
	ldr r2, _080155BC @ =FUN_08015474
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080154a8
	cmp r0, #0
	bge _080155C0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080155C2
	.align 2, 0
_080155B4: .4byte 0x00000F24
_080155B8: .4byte FUN_08015270
_080155BC: .4byte FUN_08015474
_080155C0:
	adds r0, r4, #0
_080155C2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080155c8
FUN_080155c8: @ 0x080155C8
	push {lr}
	movs r1, #0xf0
	lsls r1, r1, #8
	ands r0, r1
	asrs r0, r0, #0xc
	subs r0, #1
	movs r1, #2
	cmp r0, #3
	bhi _080155DC
	adds r1, r0, #0
_080155DC:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080155e4
FUN_080155e4: @ 0x080155E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r6, r2, #0
	ldr r0, _0801560C @ =0x03000060
	ldr r0, [r0]
	cmp r0, #0
	bne _08015614
	movs r0, #0
	movs r1, #0
	bl FUN_08015584
	cmp r0, #0
	bne _08015614
	b _08015A7A
	.align 2, 0
_0801560C: .4byte 0x03000060
_08015610:
	movs r0, #0
	b _08015A7E
_08015614:
	movs r0, #0
	str r0, [sp, #0x10]
	movs r1, #0
	str r1, [sp, #0xc]
	ldr r2, _0801565C @ =0x03000060
	mov sl, r2
	ldr r3, _08015660 @ =0x030046B8
	mov sb, r3
_08015624:
	ldr r1, [sp, #0xc]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x24
	mov r2, sl
	ldr r1, [r2]
	adds r5, r1, r0
	movs r3, #0x3c
	adds r3, r3, r5
	mov r8, r3
	ldrb r1, [r5]
	cmp r1, #0
	beq _08015642
	b _08015A6E
_08015642:
	movs r0, #1
	strb r0, [r5]
	ldrh r0, [r6]
	strb r0, [r5, #1]
	strh r1, [r5, #2]
	movs r1, #0xa
	ldrsh r0, [r6, r1]
	cmp r0, #0
	bne _08015664
	ldrh r0, [r6, #8]
	strh r0, [r5, #4]
	b _08015686
	.align 2, 0
_0801565C: .4byte 0x03000060
_08015660: .4byte 0x030046B8
_08015664:
	mov r2, sb
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08015694 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08015698 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r2, #0xa
	ldrsh r1, [r6, r2]
	bl Mod
	ldrh r1, [r6, #8]
	adds r1, r1, r0
	strh r1, [r5, #4]
_08015686:
	movs r3, #0xe
	ldrsh r0, [r6, r3]
	cmp r0, #0
	bne _0801569C
	ldrh r0, [r6, #0xc]
	strh r0, [r5, #6]
	b _080156C0
	.align 2, 0
_08015694: .4byte 0x000003FF
_08015698: .4byte 0x0203B400
_0801569C:
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _080156CC @ =0x000003FF
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080156D0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r2, #0xe
	ldrsh r1, [r6, r2]
	bl Mod
	ldrh r1, [r6, #0xc]
	adds r1, r1, r0
	strh r1, [r5, #6]
_080156C0:
	ldrh r0, [r6, #0x12]
	cmp r0, #0
	bne _080156D4
	ldrh r7, [r6, #0x10]
	b _080156F2
	.align 2, 0
_080156CC: .4byte 0x000003FF
_080156D0: .4byte 0x0203B400
_080156D4:
	mov r3, sb
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080156FC @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _08015700 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r6, #0x12]
	bl Mod
	ldrh r1, [r6, #0x10]
	adds r7, r1, r0
_080156F2:
	ldrh r0, [r6, #0x16]
	cmp r0, #0
	bne _08015704
	ldrh r4, [r6, #0x14]
	b _08015722
	.align 2, 0
_080156FC: .4byte 0x000003FF
_08015700: .4byte 0x0203B400
_08015704:
	mov r2, sb
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08015730 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08015734 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldrh r1, [r6, #0x16]
	bl Mod
	ldrh r1, [r6, #0x14]
	adds r4, r1, r0
_08015722:
	ldrh r0, [r6, #0x1a]
	cmp r0, #0
	bne _08015738
	ldrh r0, [r6, #0x18]
	strh r0, [r5, #8]
	b _0801575A
	.align 2, 0
_08015730: .4byte 0x000003FF
_08015734: .4byte 0x0203B400
_08015738:
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _08015768 @ =0x000003FF
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0801576C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldrh r1, [r6, #0x1a]
	bl Mod
	ldrh r1, [r6, #0x18]
	adds r1, r1, r0
	strh r1, [r5, #8]
_0801575A:
	ldrh r0, [r6, #0x22]
	cmp r0, #0
	bne _08015770
	ldrh r0, [r6, #0x20]
	strh r0, [r5, #0xc]
	b _08015792
	.align 2, 0
_08015768: .4byte 0x000003FF
_0801576C: .4byte 0x0203B400
_08015770:
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _080157AC @ =0x000003FF
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080157B0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldrh r1, [r6, #0x22]
	bl Mod
	ldrh r1, [r6, #0x20]
	adds r1, r1, r0
	strh r1, [r5, #0xc]
_08015792:
	ldrh r1, [r6, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080157B4
	mov r1, r8
	ldr r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	mov r2, r8
	str r0, [r2]
	b _080157C2
	.align 2, 0
_080157AC: .4byte 0x000003FF
_080157B0: .4byte 0x0203B400
_080157B4:
	mov r3, r8
	ldr r0, [r3]
	ldr r1, _080157DC @ =0xFFFFFDFF
	ands r0, r1
	ldr r1, _080157E0 @ =0xFFFFFBFF
	ands r0, r1
	str r0, [r3]
_080157C2:
	ldrh r1, [r6, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080157E4
	mov r1, r8
	ldr r0, [r1]
	movs r1, #0x10
	orrs r0, r1
	mov r2, r8
	str r0, [r2]
	b _080157F0
	.align 2, 0
_080157DC: .4byte 0xFFFFFDFF
_080157E0: .4byte 0xFFFFFBFF
_080157E4:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_080157F0:
	ldr r2, _08015828 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r5, #0x10]
	ands r7, r1
	lsls r0, r7, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r5, #0x12]
	ands r4, r1
	lsls r0, r4, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r5, #0x14]
	movs r0, #0x10
	ldrsh r1, [r5, r0]
	movs r2, #6
	ldrsh r0, [r5, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _0801582C
	asrs r0, r0, #0xc
	b _08015832
	.align 2, 0
_08015828: .4byte 0x085B0A08
_0801582C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08015832:
	strh r0, [r5, #0x18]
	movs r3, #0x12
	ldrsh r1, [r5, r3]
	movs r2, #4
	ldrsh r0, [r5, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _08015846
	asrs r0, r0, #0xc
	b _0801584C
_08015846:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0801584C:
	strh r0, [r5, #0x1a]
	movs r3, #0x14
	ldrsh r1, [r5, r3]
	movs r2, #6
	ldrsh r0, [r5, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _08015860
	asrs r0, r0, #0xc
	b _08015866
_08015860:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08015866:
	movs r7, #0
	strh r0, [r5, #0x1c]
	ldrb r0, [r5, #1]
	cmp r0, #5
	bne _080158A8
	adds r4, r5, #0
	adds r4, #0x20
	adds r0, r4, #0
	ldr r1, _080158A4 @ =0x000061F9
	bl Video_GetActorSprite
	adds r0, r4, #0
	movs r1, #0x89
	lsls r1, r1, #2
	bl Video_SetActorSpritePltt
	adds r1, r5, #0
	adds r1, #0x3c
	movs r0, #0x20
	strh r0, [r1, #0x10]
	adds r4, #0x48
	mov r3, sl
	ldr r0, [r3]
	ldr r1, [r0, #0x1c]
	str r7, [sp]
	adds r0, r4, #0
	movs r2, #6
	movs r3, #0
	bl FUN_08236fac
	b _0801594E
	.align 2, 0
_080158A4: .4byte 0x000061F9
_080158A8:
	cmp r0, #6
	bne _080158E4
	adds r4, r5, #0
	adds r4, #0x20
	adds r0, r4, #0
	ldr r1, _080158E0 @ =0x000061F9
	bl Video_GetActorSprite
	adds r0, r4, #0
	movs r1, #0x8b
	lsls r1, r1, #2
	bl Video_SetActorSpritePltt
	adds r1, r5, #0
	adds r1, #0x3c
	movs r0, #0x20
	strh r0, [r1, #0x10]
	adds r4, #0x48
	mov r1, sl
	ldr r0, [r1]
	ldr r1, [r0, #0x1c]
	str r7, [sp]
	adds r0, r4, #0
	movs r2, #6
	movs r3, #0
	bl FUN_08236fac
	b _0801594E
	.align 2, 0
_080158E0: .4byte 0x000061F9
_080158E4:
	cmp r0, #7
	bne _08015924
	adds r4, r5, #0
	adds r4, #0x20
	adds r0, r4, #0
	ldr r1, _0801591C @ =0x000061F9
	bl Video_GetActorSprite
	adds r0, r4, #0
	ldr r1, _08015920 @ =0x0000022B
	bl Video_SetActorSpritePltt
	adds r1, r5, #0
	adds r1, #0x3c
	movs r0, #0x2d
	strh r0, [r1, #0x10]
	adds r4, #0x48
	mov r2, sl
	ldr r0, [r2]
	ldr r1, [r0, #0x1c]
	str r7, [sp]
	adds r0, r4, #0
	movs r2, #8
	movs r3, #0
	bl FUN_08236fac
	b _0801594E
	.align 2, 0
_0801591C: .4byte 0x000061F9
_08015920: .4byte 0x0000022B
_08015924:
	adds r4, r5, #0
	adds r4, #0x20
	adds r0, r4, #0
	ldr r1, _08015988 @ =0x00004384
	bl Video_GetActorSprite
	ldrb r1, [r5, #1]
	adds r1, #0x7d
	adds r0, r4, #0
	bl Video_SetActorSpritePltt
	adds r4, #0x48
	mov r3, sl
	ldr r0, [r3]
	ldr r1, [r0, #0x18]
	str r7, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
_0801594E:
	adds r7, r4, #0
	adds r4, r7, #0
	ldrh r0, [r7, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x68]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r1, r8
	strh r0, [r1, #0x10]
	ldrb r0, [r7, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _0801598C
	mov r1, r8
	ldr r0, [r1]
	movs r1, #4
	orrs r0, r1
	mov r2, r8
	str r0, [r2]
	b _08015998
	.align 2, 0
_08015988: .4byte 0x00004384
_0801598C:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_08015998:
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
	beq _080159C0
	mov r1, r8
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	mov r2, r8
	str r0, [r2]
	b _080159CC
_080159C0:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_080159CC:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _08015A00 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08015A38
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08015A04
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080159FA
	ldrb r0, [r4, #5]
_080159FA:
	subs r0, #1
	strh r0, [r4, #8]
	b _08015A14
	.align 2, 0
_08015A00: .4byte 0x0000FFFF
_08015A04:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08015A14
	strh r1, [r4, #8]
_08015A14:
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
	bne _08015A38
	movs r3, #1
	strb r3, [r4, #7]
_08015A38:
	ldr r2, [sp, #8]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	mov r3, r8
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	ldrh r0, [r6, #2]
	bl FUN_080155c8
	mov r1, r8
	strb r0, [r1, #7]
	ldrh r1, [r6, #6]
	adds r0, r7, #0
	bl FUN_08237098
	mov r0, r8
	movs r1, #0
	bl FUN_0822a340
	ldr r0, [sp, #0x10]
	adds r2, r0, #0
	adds r2, #1
	str r2, [sp, #0x10]
	ldr r3, [sp, #4]
	cmp r0, r3
	blt _08015A6E
	b _08015610
_08015A6E:
	ldr r0, [sp, #0xc]
	adds r0, #1
	str r0, [sp, #0xc]
	cmp r0, #0x1f
	bgt _08015A7A
	b _08015624
_08015A7A:
	movs r0, #1
	rsbs r0, r0, #0
_08015A7E:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08015a90
FUN_08015a90: @ 0x08015A90
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x28
	mov r8, r0
	adds r7, r1, #0
	ldr r1, [sp, #0x40]
	ldr r5, [sp, #0x44]
	mov r0, sp
	movs r4, #0
	strh r2, [r0]
	strh r3, [r0, #2]
	strh r1, [r0, #6]
	strh r4, [r0, #8]
	strh r4, [r0, #0xa]
	strh r5, [r0, #0xc]
	strh r4, [r0, #0xe]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r7, #0
	bl Div
	adds r6, r0, #0
	mov r0, sp
	strh r4, [r0, #0x12]
	strh r4, [r0, #0x10]
	add r1, sp, #0x48
	ldrh r1, [r1]
	strh r1, [r0, #0x18]
	strh r4, [r0, #0x1a]
	add r2, sp, #0x4c
	ldrh r2, [r2]
	strh r2, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	add r1, sp, #0x48
	ldrh r1, [r1]
	strh r1, [r0, #0x20]
	strh r4, [r0, #0x22]
	add r2, sp, #0x4c
	ldrh r2, [r2]
	strh r2, [r0, #0x24]
	strh r4, [r0, #0x26]
	mov r1, sp
	movs r0, #0xa
	strh r0, [r1, #0x16]
	mov r0, sp
	strh r4, [r0, #0x14]
	cmp r7, #0
	ble _08015B0C
	mov r5, sp
	adds r4, r7, #0
_08015AF6:
	movs r0, #1
	mov r1, r8
	mov r2, sp
	bl FUN_080155e4
	ldrh r0, [r5, #0x14]
	adds r0, r0, r6
	strh r0, [r5, #0x14]
	subs r4, #1
	cmp r4, #0
	bne _08015AF6
_08015B0C:
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08015b18
FUN_08015b18: @ 0x08015B18
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	mov r8, r0
	str r1, [sp, #0x30]
	ldr r4, [sp, #0x58]
	ldr r5, [sp, #0x5c]
	ldr r6, [sp, #0x60]
	mov r0, sp
	movs r1, #0
	strh r4, [r0]
	strh r5, [r0, #2]
	strh r6, [r0, #6]
	strh r1, [r0, #8]
	strh r1, [r0, #0xa]
	add r4, sp, #0x64
	ldrh r4, [r4]
	strh r4, [r0, #0xc]
	strh r1, [r0, #0xe]
	strh r1, [r0, #0x10]
	strh r1, [r0, #0x12]
	strh r2, [r0, #0x14]
	strh r3, [r0, #0x16]
	add r5, sp, #0x68
	ldrh r5, [r5]
	strh r5, [r0, #0x18]
	strh r1, [r0, #0x1a]
	add r7, sp, #0x6c
	ldrh r7, [r7]
	strh r7, [r0, #0x1c]
	strh r1, [r0, #0x1e]
	add r2, sp, #0x68
	ldrh r2, [r2]
	strh r2, [r0, #0x20]
	strh r1, [r0, #0x22]
	add r3, sp, #0x6c
	ldrh r3, [r3]
	strh r3, [r0, #0x24]
	strh r1, [r0, #0x26]
	ldr r4, [sp, #0x54]
	cmp r4, #0
	ble _08015C04
	ldr r5, _08015C14 @ =0x0203B400
	mov sl, r5
	ldr r6, _08015C18 @ =0x030046B8
	ldr r7, _08015C1C @ =0x000003FF
	mov sb, r7
	adds r5, r4, #0
	add r4, sp, #0x28
_08015B80:
	ldr r2, [r6]
	adds r2, #1
	mov r0, sb
	ands r2, r0
	str r2, [r6]
	lsls r0, r2, #1
	add r0, sl
	ldrh r0, [r0]
	ldr r3, [sp, #0x30]
	ldrh r1, [r3]
	ands r0, r1
	mov r7, r8
	ldrh r7, [r7]
	adds r0, r0, r7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, [sp, #0x28]
	ldr r1, _08015C20 @ =0xFFFF0000
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #0x28]
	adds r2, #1
	mov r7, sb
	ands r2, r7
	str r2, [r6]
	lsls r0, r2, #1
	add r0, sl
	ldrh r1, [r0]
	ldr r7, [sp, #0x30]
	ldrh r0, [r7, #2]
	ands r1, r0
	mov r0, r8
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _08015C24 @ =0x0000FFFF
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x28]
	adds r2, #1
	mov r1, sb
	ands r2, r1
	str r2, [r6]
	lsls r2, r2, #1
	add r2, sl
	ldrh r1, [r2]
	ldrh r0, [r7, #4]
	ands r1, r0
	mov r2, r8
	ldrh r2, [r2, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r4, #4]
	ldr r3, _08015C20 @ =0xFFFF0000
	ands r0, r3
	orrs r0, r1
	str r0, [r4, #4]
	movs r0, #1
	adds r1, r4, #0
	mov r2, sp
	bl FUN_080155e4
	subs r5, #1
	cmp r5, #0
	bne _08015B80
_08015C04:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08015C14: .4byte 0x0203B400
_08015C18: .4byte 0x030046B8
_08015C1C: .4byte 0x000003FF
_08015C20: .4byte 0xFFFF0000
_08015C24: .4byte 0x0000FFFF

	thumb_func_start FUN_08015c28
FUN_08015c28: @ 0x08015C28
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x28
	mov r8, r0
	adds r0, r3, #0
	ldr r5, [sp, #0x40]
	ldr r6, [sp, #0x44]
	ldr r7, [sp, #0x48]
	mov r3, sp
	movs r4, #0
	strh r5, [r3]
	strh r6, [r3, #2]
	strh r7, [r3, #6]
	strh r4, [r3, #8]
	strh r4, [r3, #0xa]
	add r5, sp, #0x4c
	ldrh r5, [r5]
	strh r5, [r3, #0xc]
	strh r4, [r3, #0xe]
	strh r4, [r3, #0x10]
	strh r4, [r3, #0x12]
	strh r1, [r3, #0x14]
	mov r1, sp
	strh r2, [r1, #0x16]
	add r6, sp, #0x50
	ldrh r6, [r6]
	strh r6, [r1, #0x18]
	strh r4, [r1, #0x1a]
	add r2, sp, #0x54
	ldrh r2, [r2]
	strh r2, [r1, #0x1c]
	strh r4, [r1, #0x1e]
	add r3, sp, #0x50
	ldrh r3, [r3]
	strh r3, [r1, #0x20]
	strh r4, [r1, #0x22]
	add r5, sp, #0x54
	ldrh r5, [r5]
	strh r5, [r1, #0x24]
	strh r4, [r1, #0x26]
	mov r1, r8
	mov r2, sp
	bl FUN_080155e4
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08015c90
FUN_08015c90: @ 0x08015C90
	push {r4, r5, r6, lr}
	sub sp, #0x28
	ldr r6, [sp, #0x38]
	mov r4, sp
	movs r5, #0
	strh r1, [r4]
	mov r1, sp
	strh r2, [r1, #2]
	strh r3, [r1, #6]
	movs r2, #0xc
	strh r2, [r1, #8]
	strh r2, [r1, #0xa]
	movs r2, #4
	strh r2, [r1, #0xc]
	strh r2, [r1, #0xe]
	mov r2, sp
	movs r1, #0x3c
	strh r1, [r2, #0x10]
	movs r1, #8
	strh r1, [r2, #0x12]
	mov r1, sp
	strh r5, [r1, #0x14]
	movs r2, #0xff
	strh r2, [r1, #0x16]
	strh r2, [r1, #0x18]
	strh r5, [r1, #0x1a]
	strh r2, [r1, #0x1c]
	strh r5, [r1, #0x1e]
	strh r2, [r1, #0x20]
	strh r5, [r1, #0x22]
	strh r2, [r1, #0x24]
	strh r5, [r1, #0x26]
	adds r1, r6, #0
	mov r2, sp
	bl FUN_080155e4
	add sp, #0x28
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08015ce0
FUN_08015ce0: @ 0x08015CE0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	ldr r6, [sp, #0x4c]
	ldr r7, [sp, #0x50]
	mov r4, sp
	movs r5, #0
	strh r1, [r4]
	mov r1, sp
	strh r2, [r1, #2]
	strh r3, [r1, #6]
	strh r6, [r1, #8]
	strh r7, [r1, #0xa]
	add r2, sp, #0x44
	ldrh r2, [r2]
	strh r2, [r1, #0xc]
	add r3, sp, #0x48
	ldrh r3, [r3]
	strh r3, [r1, #0xe]
	mov r2, sp
	movs r1, #0x3c
	strh r1, [r2, #0x10]
	movs r1, #8
	strh r1, [r2, #0x12]
	mov r1, sp
	ldrh r4, [r1, #0x3c]
	strh r4, [r1, #0x14]
	add r2, sp, #0x40
	ldrh r2, [r2]
	strh r2, [r1, #0x16]
	movs r2, #0xff
	strh r2, [r1, #0x18]
	strh r5, [r1, #0x1a]
	strh r2, [r1, #0x1c]
	strh r5, [r1, #0x1e]
	strh r2, [r1, #0x20]
	strh r5, [r1, #0x22]
	strh r2, [r1, #0x24]
	strh r5, [r1, #0x26]
	ldr r1, [sp, #0x54]
	mov r2, sp
	bl FUN_080155e4
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08015d3c
FUN_08015d3c: @ 0x08015D3C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x28
	mov r8, r0
	ldr r5, [sp, #0x40]
	ldr r6, [sp, #0x44]
	ldr r7, [sp, #0x48]
	mov r0, sp
	movs r4, #0
	strh r1, [r0]
	strh r2, [r0, #2]
	strh r3, [r0, #6]
	strh r5, [r0, #8]
	strh r6, [r0, #0xa]
	strh r7, [r0, #0xc]
	add r1, sp, #0x4c
	ldrh r1, [r1]
	strh r1, [r0, #0xe]
	mov r1, sp
	movs r0, #0x3c
	strh r0, [r1, #0x10]
	movs r0, #8
	strh r0, [r1, #0x12]
	mov r0, sp
	strh r4, [r0, #0x14]
	movs r1, #0xff
	strh r1, [r0, #0x16]
	strh r1, [r0, #0x18]
	strh r4, [r0, #0x1a]
	strh r1, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	strh r1, [r0, #0x20]
	strh r4, [r0, #0x22]
	strh r1, [r0, #0x24]
	strh r4, [r0, #0x26]
	movs r0, #1
	mov r1, r8
	mov r2, sp
	bl FUN_080155e4
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08015d9c
FUN_08015d9c: @ 0x08015D9C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x28
	mov r8, r0
	ldr r5, [sp, #0x40]
	ldr r6, [sp, #0x44]
	ldr r7, [sp, #0x48]
	mov r0, sp
	movs r4, #0
	strh r1, [r0]
	strh r2, [r0, #2]
	strh r3, [r0, #6]
	strh r5, [r0, #8]
	strh r6, [r0, #0xa]
	strh r7, [r0, #0xc]
	add r1, sp, #0x4c
	ldrh r1, [r1]
	strh r1, [r0, #0xe]
	add r2, sp, #0x50
	ldrh r2, [r2]
	strh r2, [r0, #0x10]
	add r1, sp, #0x54
	ldrh r1, [r1]
	strh r1, [r0, #0x12]
	strh r4, [r0, #0x14]
	movs r1, #0xff
	strh r1, [r0, #0x16]
	strh r1, [r0, #0x18]
	strh r4, [r0, #0x1a]
	strh r1, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	strh r1, [r0, #0x20]
	strh r4, [r0, #0x22]
	strh r1, [r0, #0x24]
	strh r4, [r0, #0x26]
	movs r0, #1
	mov r1, r8
	mov r2, sp
	bl FUN_080155e4
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08015dfc
FUN_08015dfc: @ 0x08015DFC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x30
	adds r7, r0, #0
	ldr r1, [sp, #0x44]
	ldr r5, [sp, #0x4c]
	ldr r6, [sp, #0x50]
	mov r0, sp
	movs r4, #0
	strh r2, [r0]
	strh r3, [r0, #2]
	strh r1, [r0, #6]
	strh r4, [r0, #8]
	strh r4, [r0, #0xa]
	add r1, sp, #0x48
	ldrh r1, [r1]
	strh r1, [r0, #0xc]
	strh r4, [r0, #0xe]
	ldr r2, _08015E74 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08015E78 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08015E7C @ =0x0203B400
	adds r0, r0, r2
	mov r1, sp
	ldrb r0, [r0]
	strh r0, [r1, #0x14]
	mov r0, sp
	strh r4, [r0, #0x16]
	strh r4, [r0, #0x12]
	strh r4, [r0, #0x10]
	strh r5, [r0, #0x18]
	strh r4, [r0, #0x1a]
	strh r6, [r0, #0x1c]
	strh r4, [r0, #0x1e]
	strh r5, [r0, #0x20]
	strh r4, [r0, #0x22]
	strh r6, [r0, #0x24]
	strh r4, [r0, #0x26]
	ldr r2, _08015E80 @ =0x085B0A08
	ldrh r0, [r0, #0x14]
	adds r0, #0xc0
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r1, [sp, #0x48]
	muls r0, r1, r0
	cmp r0, #0
	blt _08015E84
	asrs r1, r0, #0xc
	b _08015E8A
	.align 2, 0
_08015E74: .4byte 0x030046B8
_08015E78: .4byte 0x000003FF
_08015E7C: .4byte 0x0203B400
_08015E80: .4byte 0x085B0A08
_08015E84:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08015E8A:
	ldrh r0, [r7]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldrh r1, [r7, #2]
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #0x28]
	mov r0, sp
	ldrh r0, [r0, #0x14]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r3, [sp, #0x48]
	muls r0, r3, r0
	cmp r0, #0
	blt _08015EBE
	asrs r0, r0, #0xc
	b _08015EC4
_08015EBE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08015EC4:
	ldrh r2, [r7, #4]
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _08015EE8 @ =0xFFFF0000
	add r1, sp, #0x28
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	movs r0, #1
	mov r2, sp
	bl FUN_080155e4
	add sp, #0x30
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08015EE8: .4byte 0xFFFF0000

	thumb_func_start FUN_08015eec
FUN_08015eec: @ 0x08015EEC
	push {r4, r5, lr}
	sub sp, #0x30
	movs r0, #0x6e
	movs r1, #1
	bl VM_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08015F44
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08015F3C @ =0xFFFF0000
	ldr r1, [sp, #0x28]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x28]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08015F40 @ =0x0000FFFF
	ldr r1, [sp, #0x28]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x28]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r2, sp, #0x28
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r2, #4]
	adds r4, r2, #0
	b _08015F52
	.align 2, 0
_08015F3C: .4byte 0xFFFF0000
_08015F40: .4byte 0x0000FFFF
_08015F44:
	ldr r2, _08015FA4 @ =0xFFFF0000
	str r0, [sp, #0x28]
	add r1, sp, #0x28
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r1, #0
_08015F52:
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	mov r1, sp
	strh r0, [r1]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	mov r1, sp
	strh r0, [r1, #2]
	movs r0, #0x61
	movs r1, #0x40
	bl VM_GetKeywordValue
	mov r1, sp
	strh r0, [r1, #6]
	movs r0, #0x73
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _08015FA8
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #8]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0xa]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0xc]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0xe]
	b _08015FB2
	.align 2, 0
_08015FA4: .4byte 0xFFFF0000
_08015FA8:
	mov r0, sp
	strh r1, [r0, #8]
	strh r1, [r0, #0xa]
	strh r1, [r0, #0xc]
	strh r1, [r0, #0xe]
_08015FB2:
	movs r0, #0x64
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _08015FE0
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x10]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x12]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x14]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x16]
	b _08015FEA
_08015FE0:
	mov r0, sp
	strh r1, [r0, #0x10]
	strh r1, [r0, #0x12]
	strh r1, [r0, #0x14]
	strh r1, [r0, #0x16]
_08015FEA:
	movs r0, #0x63
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	beq _08016038
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x18]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x1a]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x1c]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x1e]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x20]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x22]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x24]
	bl Script_GetValue
	mov r1, sp
	strh r0, [r1, #0x26]
	b _0801604C
_08016038:
	mov r0, sp
	movs r1, #0xff
	strh r1, [r0, #0x18]
	strh r2, [r0, #0x1a]
	strh r1, [r0, #0x1c]
	strh r2, [r0, #0x1e]
	strh r1, [r0, #0x20]
	strh r2, [r0, #0x22]
	strh r1, [r0, #0x24]
	strh r2, [r0, #0x26]
_0801604C:
	adds r0, r5, #0
	adds r1, r4, #0
	mov r2, sp
	bl FUN_080155e4
	add sp, #0x30
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08016060
FUN_08016060: @ 0x08016060
	ldr r1, _08016068 @ =0x03002B44
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08016068: .4byte 0x03002B44

	thumb_func_start FUN_0801606c
FUN_0801606c: @ 0x0801606C
	push {lr}
	ldrh r3, [r1, #0x3e]
	movs r1, #8
	ldr r0, [r0, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _0801607C
	lsls r3, r3, #1
_0801607C:
	ldrh r0, [r2, #0x16]
	subs r0, r0, r3
	strh r0, [r2, #0x16]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0801608C
	movs r0, #0
	strh r0, [r2, #0x16]
_0801608C:
	pop {r0}
	bx r0
_08016090:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_08016094
FUN_08016094: @ 0x08016094
	push {lr}
	adds r2, r0, #0
	movs r0, #0
	str r0, [r1, #0x78]
	ldr r0, [r2, #0x1c]
	str r0, [r1, #0x7c]
	cmp r0, #0
	beq _080160A6
	str r1, [r0, #0x78]
_080160A6:
	str r1, [r2, #0x1c]
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080160b0
FUN_080160b0: @ 0x080160B0
	push {lr}
	ldr r2, [r1, #0x78]
	ldr r1, [r1, #0x7c]
	cmp r2, #0
	beq _080160BE
	str r1, [r2, #0x7c]
	b _080160C0
_080160BE:
	str r1, [r0, #0x1c]
_080160C0:
	cmp r1, #0
	beq _080160C6
	str r2, [r1, #0x78]
_080160C6:
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_080160cc
FUN_080160cc: @ 0x080160CC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x3c
	bl FUN_0822a4e0
	ldr r0, _0801610C @ =0x03002B44
	ldr r0, [r0]
	cmp r0, #0
	beq _080160E4
	adds r1, r4, #0
	bl FUN_080160b0
_080160E4:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _080160F4
	bl FUN_08236424
	ldr r0, [r4, #0x18]
	bl Free
_080160F4:
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _080160FE
	bl Free
_080160FE:
	adds r0, r4, #0
	bl Free
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801610C: .4byte 0x03002B44

	thumb_func_start FUN_08016110
FUN_08016110: @ 0x08016110
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	ldr r0, _0801618C @ =0x03002B44
	ldr r0, [r0]
	cmp r0, #0
	bne _08016136
	ldr r0, _08016190 @ =0x0000C0DB
	movs r1, #0
	bl FUN_08016660
	cmp r0, #0
	bne _08016136
	b _0801630A
_08016136:
	movs r0, #0x80
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	bne _08016144
	b _0801630A
_08016144:
	adds r0, r4, #0
	movs r1, #0x80
	bl ClearMemory
	strb r5, [r4]
	strb r6, [r4, #3]
	strh r7, [r4, #8]
	ldr r0, [sp, #0x34]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #0xc]
	str r1, [r4, #0x10]
	adds r6, r4, #0
	adds r6, #0xc
	ldrh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r7, r6, #0
	cmp r2, #0
	blt _08016186
	cmp r1, #0
	blt _08016186
	ldr r0, _08016194 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08016186
	ldr r0, _08016198 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0801619C
_08016186:
	movs r5, #0
	b _080161AA
	.align 2, 0
_0801618C: .4byte 0x03002B44
_08016190: .4byte 0x0000C0DB
_08016194: .4byte 0x030046A8
_08016198: .4byte 0x030046AC
_0801619C:
	ldr r0, _080161BC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080161AA:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080161C0
	adds r0, #4
	b _080161CC
	.align 2, 0
_080161BC: .4byte 0x030046A4
_080161C0:
	ldr r0, _080161E0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080161CC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080161E4
	cmp r2, #2
	beq _080161E8
	b _080161EC
	.align 2, 0
_080161E0: .4byte 0x030046A4
_080161E4:
	ldrb r0, [r6, #4]
	b _080161EA
_080161E8:
	ldrb r0, [r6]
_080161EA:
	subs r1, r1, r0
_080161EC:
	strh r1, [r4, #0x14]
	mov r0, r8
	strh r0, [r4, #0x16]
	ldrb r0, [r4, #3]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _0801627C
	movs r0, #0x50
	bl Malloc
	str r0, [r4, #0x18]
	cmp r0, #0
	bne _0801620A
	b _0801630A
_0801620A:
	movs r1, #0x50
	bl ClearMemory
	ldr r2, _0801626C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x5a
	orrs r0, r3
	ldr r1, _08016270 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldr r0, [r4, #0x18]
	ldr r2, _08016274 @ =0x00004001
	movs r1, #0x10
	str r1, [sp]
	add r1, sp, #0xc
	str r1, [sp, #4]
	str r3, [sp, #8]
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r0, [r4, #0x18]
	ldr r1, _08016278 @ =FUN_0801606c
	adds r2, r4, #0
	bl FUN_0823651c
	ldr r0, [r4, #0x18]
	bl FUN_08236400
	ldr r0, [r4, #0x18]
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	b _0801627E
	.align 2, 0
_0801626C: .4byte 0xFFFF0000
_08016270: .4byte 0x0000FFFF
_08016274: .4byte 0x00004001
_08016278: .4byte FUN_0801606c
_0801627C:
	str r1, [r4, #0x18]
_0801627E:
	ldrb r0, [r4, #3]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _080162F8
	movs r0, #0x50
	bl Malloc
	str r0, [r4, #0x1c]
	cmp r0, #0
	beq _0801630A
	movs r1, #0x50
	bl ClearMemory
	movs r2, #0
	movs r3, #0x64
	add r0, sp, #0xc
	strh r3, [r0]
	adds r1, r0, #0
	movs r0, #0x78
	strh r0, [r1, #2]
	strh r3, [r1, #4]
	add r3, sp, #0x14
	strh r2, [r3]
	strh r2, [r3, #2]
	strh r2, [r3, #4]
	ldr r0, [r4, #0x1c]
	ldr r2, _080162F0 @ =0x00002001
	movs r1, #0x10
	str r1, [sp]
	add r1, sp, #0xc
	str r1, [sp, #4]
	str r3, [sp, #8]
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r0, [r4, #0x1c]
	ldr r1, _080162F4 @ =0x08016091
	adds r2, r4, #0
	bl FUN_0823651c
	ldr r0, [r4, #0x1c]
	movs r1, #0x32
	movs r2, #0x14
	bl FUN_082364f0
	ldr r0, [r4, #0x1c]
	bl FUN_08236400
	ldr r0, [r4, #0x1c]
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	b _080162FA
	.align 2, 0
_080162F0: .4byte 0x00002001
_080162F4: .4byte 0x08016091
_080162F8:
	str r1, [r4, #0x1c]
_080162FA:
	adds r5, r4, #0
	adds r5, #0x20
	ldr r1, _08016310 @ =0x0000863A
	adds r0, r5, #0
	bl Video_GetActorSprite
	cmp r0, #0
	bne _08016314
_0801630A:
	movs r0, #1
	rsbs r0, r0, #0
	b _0801637A
	.align 2, 0
_08016310: .4byte 0x0000863A
_08016314:
	adds r0, r4, #0
	adds r0, #0x3c
	adds r1, r5, #0
	movs r2, #1
	bl FUN_0822a470
	adds r1, r4, #0
	adds r1, #0x43
	movs r6, #0
	movs r0, #2
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x68
	ldr r1, _08016358 @ =0x03002B44
	ldr r1, [r1]
	ldr r1, [r1, #0x18]
	str r6, [sp]
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	ldrb r1, [r4]
	ldr r0, _0801635C @ =0x00000113
	adds r1, r1, r0
	adds r0, r5, #0
	bl Video_SetActorSpritePltt
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08016360
	movs r0, #1
	strb r0, [r4, #2]
	strh r6, [r4, #6]
	b _08016366
	.align 2, 0
_08016358: .4byte 0x03002B44
_0801635C: .4byte 0x00000113
_08016360:
	strb r6, [r4, #2]
	strh r6, [r4, #6]
	movs r0, #1
_08016366:
	strb r0, [r4, #1]
	movs r0, #0
	strb r0, [r4, #5]
	str r0, [r4, #0x78]
	str r0, [r4, #0x7c]
	ldr r0, _08016388 @ =0x03002B44
	ldr r0, [r0]
	adds r1, r4, #0
	bl FUN_08016094
_0801637A:
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08016388: .4byte 0x03002B44

	thumb_func_start FUN_0801638c
FUN_0801638c: @ 0x0801638C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	mov r8, r0
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x6c
	movs r1, #0
	bl VM_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08016404
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080163FC @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08016400 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _0801640E
	.align 2, 0
_080163FC: .4byte 0xFFFF0000
_08016400: .4byte 0x0000FFFF
_08016404:
	ldr r1, _0801642C @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_0801640E:
	add r0, sp, #4
	str r0, [sp]
	mov r0, r8
	adds r1, r7, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_08016110
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801642C: .4byte 0xFFFF0000

	thumb_func_start FUN_08016430
FUN_08016430: @ 0x08016430
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #6]
	adds r1, r0, #1
	strh r1, [r2, #6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r2, #8]
	cmp r0, r1
	bls _0801644E
	movs r1, #1
	movs r0, #0
	strb r1, [r2, #2]
	strh r0, [r2, #6]
	strb r1, [r2, #1]
_0801644E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08016454
FUN_08016454: @ 0x08016454
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08016482
	movs r2, #0
	strb r2, [r4, #1]
	ldr r0, [r4, #0x3c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x3c]
	adds r0, r4, #0
	adds r0, #0x68
	ldr r1, _08016498 @ =0x03002B44
	ldr r1, [r1]
	ldr r1, [r1, #0x18]
	str r2, [sp]
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
_08016482:
	movs r1, #0x16
	ldrsh r0, [r4, r1]
	cmp r0, #0
	ble _08016490
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _0801649C
_08016490:
	movs r0, #1
	strb r0, [r4, #5]
	b _080164C8
	.align 2, 0
_08016498: .4byte 0x03002B44
_0801649C:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _080164AC
	adds r1, r4, #0
	adds r1, #0xc
	movs r2, #0
	bl FUN_082364c4
_080164AC:
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _080164C2
	adds r1, r4, #0
	adds r1, #0xc
	movs r2, #0
	bl FUN_082364c4
	ldr r0, [r4, #0x1c]
	bl FUN_08236400
_080164C2:
	ldrh r0, [r4, #6]
	adds r0, #1
	strh r0, [r4, #6]
_080164C8:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080164d0
FUN_080164d0: @ 0x080164D0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r4, [r0, #0x1c]
	cmp r4, #0
	bne _080164E0
	b _08016602
_080164E0:
	movs r0, #1
	mov r8, r0
	movs r1, #2
	mov sb, r1
_080164E8:
	ldr r7, [r4, #0x7c]
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _080164F8
	adds r0, r4, #0
	bl FUN_080160cc
	b _080165FA
_080164F8:
	adds r6, r4, #0
	adds r6, #0x3c
	adds r3, r4, #0
	adds r3, #0x68
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r4, #0x68]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r3, #4]
	mov r2, r8
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r1, r8
	ands r0, r1
	cmp r2, r0
	beq _0801652C
	ldr r0, [r4, #0x3c]
	movs r1, #4
	orrs r0, r1
	b _08016534
_0801652C:
	ldr r0, [r4, #0x3c]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08016534:
	str r0, [r4, #0x3c]
	ldrb r0, [r3, #4]
	mov r1, sb
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sb
	ands r0, r2
	cmp r1, r0
	beq _08016558
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _08016560
_08016558:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08016560:
	str r0, [r6]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r5, _08016598 @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r3, #7]
	cmp r0, r5
	blo _080165DE
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080165A2
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _0801659C
	ldrb r0, [r3, #5]
	subs r0, #1
	strh r0, [r3, #8]
	movs r2, #1
	b _080165B8
	.align 2, 0
_08016598: .4byte 0x0000FFFF
_0801659C:
	subs r0, #1
	strh r0, [r3, #8]
	b _080165B6
_080165A2:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _080165B6
	strh r1, [r3, #8]
	movs r2, #1
	b _080165B8
_080165B6:
	movs r2, #0
_080165B8:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3, #6]
	ldrb r1, [r3, #6]
	ldrh r0, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080165E0
	mov r5, r8
	strb r5, [r3, #7]
	b _080165E0
_080165DE:
	movs r2, #0
_080165E0:
	strb r2, [r4, #4]
	ldr r0, [r4, #0xc]
	ldr r1, [r4, #0x10]
	str r0, [r4, #0x58]
	str r1, [r4, #0x5c]
	ldr r1, _08016610 @ =0x085AA918
	ldrb r0, [r4, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080165FA:
	adds r4, r7, #0
	cmp r4, #0
	beq _08016602
	b _080164E8
_08016602:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08016610: .4byte 0x085AA918

	thumb_func_start FUN_08016614
FUN_08016614: @ 0x08016614
	push {r4, lr}
	ldr r0, [r0, #0x1c]
	cmp r0, #0
	beq _08016628
_0801661C:
	ldr r4, [r0, #0x7c]
	bl FUN_080160cc
	adds r0, r4, #0
	cmp r0, #0
	bne _0801661C
_08016628:
	ldr r1, _08016634 @ =0x03002B44
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08016634: .4byte 0x03002B44

	thumb_func_start FUN_08016638
FUN_08016638: @ 0x08016638
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08016654 @ =0x03002B44
	str r4, [r0]
	ldr r0, _08016658 @ =0x0000922E
	ldr r1, _0801665C @ =0x0000931E
	bl GetFile
	str r0, [r4, #0x18]
	movs r0, #0
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08016654: .4byte 0x03002B44
_08016658: .4byte 0x0000922E
_0801665C: .4byte 0x0000931E

	thumb_func_start FUN_08016660
FUN_08016660: @ 0x08016660
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #8
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08016698
	ldr r1, _08016690 @ =FUN_080164d0
	ldr r2, _08016694 @ =FUN_08016614
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08016638
	cmp r0, #0
	bge _08016698
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801669A
	.align 2, 0
_08016690: .4byte FUN_080164d0
_08016694: .4byte FUN_08016614
_08016698:
	adds r0, r4, #0
_0801669A:
	pop {r4, r5}
	pop {r1}
	bx r1
_080166A0:
	.byte 0x01, 0x49, 0x00, 0x20, 0x08, 0x60, 0x70, 0x47, 0x64, 0x00, 0x00, 0x03

	thumb_func_start FUN_080166ac
FUN_080166ac: @ 0x080166AC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	ldr r0, _0801672C @ =0x03000064
	ldr r0, [r0]
	cmp r0, #0
	bne _080166D6
	movs r0, #0
	movs r1, #0
	bl FUN_08016ba4
	cmp r0, #0
	bne _080166D6
	b _08016862
_080166D6:
	movs r2, #0
	ldr r3, _0801672C @ =0x03000064
	movs r1, #0x24
_080166DC:
	ldr r0, [r3]
	adds r5, r0, r1
	ldrb r0, [r5]
	cmp r0, #0
	beq _080166E8
	b _08016854
_080166E8:
	movs r0, #1
	strb r0, [r5]
	strb r4, [r5, #1]
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bls _080166FA
	movs r0, #8
	strb r0, [r5, #1]
_080166FA:
	movs r0, #0
	mov sl, r0
	ldrb r1, [r5, #1]
	cmp sl, r1
	blt _08016706
	b _08016846
_08016706:
	ldr r6, _08016730 @ =0x030046B8
	ldr r2, _08016734 @ =0x000003FF
	mov sb, r2
	movs r3, #0x38
	adds r3, r3, r5
	mov r8, r3
	adds r7, r5, #0
	adds r7, #0x10
	adds r4, r5, #4
_08016718:
	movs r0, #1
	strb r0, [r4]
	ldr r0, [sp, #0xc]
	cmp r0, #0
	bne _08016738
	mov r1, sp
	ldrb r1, [r1, #8]
	strb r1, [r4, #1]
	b _08016756
	.align 2, 0
_0801672C: .4byte 0x03000064
_08016730: .4byte 0x030046B8
_08016734: .4byte 0x000003FF
_08016738:
	ldr r0, [r6]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r6]
	lsls r0, r0, #1
	ldr r3, _08016764 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #0xc]
	bl Mod
	ldr r1, [sp, #8]
	adds r0, r1, r0
	strb r0, [r4, #1]
_08016756:
	ldr r2, [sp, #0x34]
	cmp r2, #0
	bne _08016768
	mov r3, sp
	ldrh r3, [r3, #0x30]
	strh r3, [r4, #2]
	b _08016786
	.align 2, 0
_08016764: .4byte 0x0203B400
_08016768:
	ldr r0, [r6]
	adds r0, #1
	mov r1, sb
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _08016790 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x34]
	bl Mod
	ldr r3, [sp, #0x30]
	adds r0, r3, r0
	strh r0, [r4, #2]
_08016786:
	ldr r0, [sp, #0x3c]
	cmp r0, #0
	bne _08016794
	ldr r2, [sp, #0x38]
	b _080167B0
	.align 2, 0
_08016790: .4byte 0x0203B400
_08016794:
	ldr r0, [r6]
	adds r0, #1
	mov r1, sb
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _080167DC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x3c]
	bl Mod
	ldr r3, [sp, #0x38]
	adds r2, r3, r0
_080167B0:
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r3, _080167E0 @ =0x085B0A08
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r4, #4]
	ands r2, r1
	lsls r0, r2, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r4, #8]
	ldr r0, [sp, #0x44]
	cmp r0, #0
	bne _080167E4
	add r1, sp, #0x40
	ldrh r1, [r1]
	strh r1, [r4, #6]
	b _08016802
	.align 2, 0
_080167DC: .4byte 0x0203B400
_080167E0: .4byte 0x085B0A08
_080167E4:
	ldr r0, [r6]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r6]
	lsls r0, r0, #1
	ldr r3, _0801684C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #0x44]
	bl Mod
	ldr r1, [sp, #0x40]
	adds r0, r1, r0
	strh r0, [r4, #6]
_08016802:
	ldr r2, [sp, #4]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x24]
	str r1, [r4, #0x28]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_0822da50
	ldr r0, [r4, #0xc]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0xc]
	ldr r0, _08016850 @ =0x03000064
	ldr r0, [r0]
	ldr r1, [r0, #0x20]
	movs r0, #0
	str r0, [sp]
	mov r0, r8
	movs r2, #3
	movs r3, #0
	bl FUN_08236fac
	movs r3, #0x44
	add r8, r3
	adds r7, #0x44
	adds r4, #0x44
	movs r0, #1
	add sl, r0
	ldrb r1, [r5, #1]
	cmp sl, r1
	bge _08016846
	b _08016718
_08016846:
	movs r0, #0
	b _08016866
	.align 2, 0
_0801684C: .4byte 0x0203B400
_08016850: .4byte 0x03000064
_08016854:
	movs r0, #0x89
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r2, #1
	cmp r2, #5
	bgt _08016862
	b _080166DC
_08016862:
	movs r0, #1
	rsbs r0, r0, #0
_08016866:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08016878
FUN_08016878: @ 0x08016878
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	movs r0, #0
	str r0, [sp]
	mov sl, r0
	ldrb r1, [r7, #1]
	cmp sl, r1
	blt _08016894
	b _08016A3E
_08016894:
	adds r2, r7, #5
	mov sb, r2
	movs r3, #0x38
	adds r3, r3, r7
	mov r8, r3
	adds r0, r7, #6
	str r0, [sp, #4]
	adds r4, r7, #0
	adds r4, #8
_080168A6:
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	bne _080168B0
	b _08016A1C
_080168B0:
	ldr r2, [sp]
	adds r2, #1
	str r2, [sp]
	movs r3, #0
	ldrsh r1, [r4, r3]
	ldr r2, [sp, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080168CA
	asrs r1, r0, #0xc
	b _080168D0
_080168CA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080168D0:
	ldrh r0, [r4, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	ldrh r0, [r4, #2]
	ldrh r1, [r4, #0x22]
	adds r0, r0, r1
	strh r0, [r4, #0x22]
	movs r2, #4
	ldrsh r1, [r4, r2]
	ldr r3, [sp, #4]
	movs r2, #0
	ldrsh r0, [r3, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080168F2
	asrs r1, r0, #0xc
	b _080168F8
_080168F2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080168F8:
	ldrh r0, [r4, #0x24]
	adds r0, r0, r1
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #2]
	subs r0, #2
	strh r0, [r4, #2]
	mov r0, r8
	movs r1, #0x10
	bl FUN_08237098
	ldr r0, _08016950 @ =0x03000064
	ldr r0, [r0]
	ldr r3, [r0, #0x1c]
	mov r5, r8
	ldrh r0, [r4, #0x38]
	lsls r0, r0, #1
	ldr r1, [r4, #0x30]
	adds r6, r1, r0
	ldrh r2, [r6]
	lsrs r2, r2, #6
	ldrb r1, [r4, #0x12]
	lsrs r1, r1, #3
	ldrb r0, [r4, #0x13]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r4, #0x10]
	ldrb r0, [r5, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r6]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _08016954
	ldr r0, [r4, #8]
	movs r1, #4
	orrs r0, r1
	b _0801695C
	.align 2, 0
_08016950: .4byte 0x03000064
_08016954:
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0801695C:
	str r0, [r4, #8]
	ldrb r0, [r5, #4]
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
	beq _08016980
	ldr r0, [r4, #8]
	movs r1, #8
	orrs r0, r1
	b _08016988
_08016980:
	ldr r0, [r4, #8]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08016988:
	str r0, [r4, #8]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r5, #0xe]
	ldr r3, _080169C0 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r5, #7]
	cmp r0, r3
	blo _080169EA
	strh r1, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080169C4
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _080169B8
	ldrb r0, [r5, #5]
_080169B8:
	subs r0, #1
	strh r0, [r5, #8]
	b _080169D4
	.align 2, 0
_080169C0: .4byte 0x0000FFFF
_080169C4:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _080169D4
	strh r1, [r5, #8]
_080169D4:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
_080169EA:
	mov r3, sb
	ldrb r0, [r3]
	adds r1, r0, #0
	adds r2, r0, #0
	cmp r1, #8
	bls _080169FE
	ldrh r0, [r4, #0x38]
	cmp r0, #5
	bne _08016A06
	b _08016A02
_080169FE:
	cmp r1, #8
	bne _08016A06
_08016A02:
	movs r0, #0
	strh r0, [r4, #0x38]
_08016A06:
	subs r0, r2, #1
	mov r1, sb
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08016A24
	ldr r0, [r4, #8]
	movs r2, #1
	orrs r0, r2
	b _08016A22
_08016A1C:
	ldr r0, [r4, #8]
	movs r3, #1
	orrs r0, r3
_08016A22:
	str r0, [r4, #8]
_08016A24:
	movs r0, #0x44
	add sb, r0
	add r8, r0
	ldr r1, [sp, #4]
	adds r1, #0x44
	str r1, [sp, #4]
	adds r4, #0x44
	movs r2, #1
	add sl, r2
	ldrb r3, [r7, #1]
	cmp sl, r3
	bge _08016A3E
	b _080168A6
_08016A3E:
	ldr r0, [sp]
	cmp r0, #0
	bne _08016A6A
	strb r0, [r7]
	movs r2, #0
	mov sl, r2
	ldrb r3, [r7, #1]
	cmp sl, r3
	bge _08016A66
	adds r4, r7, #0
	adds r4, #0x10
_08016A54:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x44
	movs r0, #1
	add sl, r0
	ldrb r1, [r7, #1]
	cmp sl, r1
	blt _08016A54
_08016A66:
	movs r0, #0
	strb r0, [r7, #1]
_08016A6A:
	movs r0, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08016a7c
FUN_08016a7c: @ 0x08016A7C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r7, _08016AB0 @ =0x03000064
	movs r5, #0x24
	movs r4, #5
_08016A86:
	ldr r0, [r7]
	adds r1, r0, r5
	ldrb r0, [r1]
	cmp r0, #0
	beq _08016A96
	adds r0, r1, #0
	bl FUN_08016878
_08016A96:
	movs r0, #0x89
	lsls r0, r0, #2
	adds r5, r5, r0
	subs r4, #1
	cmp r4, #0
	bge _08016A86
	ldr r0, [r6, #0x18]
	adds r0, #1
	str r0, [r6, #0x18]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08016AB0: .4byte 0x03000064

	thumb_func_start FUN_08016ab4
FUN_08016ab4: @ 0x08016AB4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r1, #0
_08016ABE:
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0x24
	mov r2, r8
	adds r5, r2, r0
	ldrb r0, [r5]
	adds r7, r1, #1
	cmp r0, #0
	beq _08016AF2
	movs r6, #0
	ldrb r0, [r5, #1]
	cmp r6, r0
	bge _08016AF2
	adds r4, r5, #0
	adds r4, #0x10
_08016AE2:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x44
	adds r6, #1
	ldrb r2, [r5, #1]
	cmp r6, r2
	blt _08016AE2
_08016AF2:
	adds r1, r7, #0
	cmp r1, #5
	ble _08016ABE
	movs r1, #0
	ldr r0, _08016B0C @ =0x03000064
	str r1, [r0]
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08016B0C: .4byte 0x03000064

	thumb_func_start FUN_08016b10
FUN_08016b10: @ 0x08016B10
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _08016B94 @ =0x03000064
	str r7, [r0]
	ldr r0, _08016B98 @ =0x00001C1A
	bl GetParticleGroup
	str r0, [r7, #0x1c]
	ldr r0, _08016B9C @ =0x0000922E
	ldr r1, _08016BA0 @ =0x0000D1B8
	bl GetFile
	str r0, [r7, #0x20]
	movs r1, #0
	mov sb, r1
_08016B36:
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0x24
	adds r0, r7, r0
	mov r2, sb
	strb r2, [r0]
	adds r1, #1
	mov r8, r1
	adds r5, r0, #0
	adds r5, #0x38
	adds r4, r0, #0
	adds r4, #0x10
	movs r6, #7
_08016B56:
	ldr r1, [r7, #0x1c]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822da70
	ldr r1, [r7, #0x20]
	mov r0, sb
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #3
	movs r3, #0
	bl FUN_08236fac
	adds r5, #0x44
	adds r4, #0x44
	subs r6, #1
	cmp r6, #0
	bge _08016B56
	mov r1, r8
	cmp r1, #5
	ble _08016B36
	movs r0, #0
	str r0, [r7, #0x18]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08016B94: .4byte 0x03000064
_08016B98: .4byte 0x00001C1A
_08016B9C: .4byte 0x0000922E
_08016BA0: .4byte 0x0000D1B8

	thumb_func_start FUN_08016ba4
FUN_08016ba4: @ 0x08016BA4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08016BDC @ =0x03000064
	ldr r0, [r0]
	cmp r0, #0
	bne _08016BEE
	ldr r1, _08016BE0 @ =0x00000CFC
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08016BEC
	ldr r1, _08016BE4 @ =FUN_08016a7c
	ldr r2, _08016BE8 @ =FUN_08016ab4
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08016b10
	cmp r0, #0
	bge _08016BEC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08016BEE
	.align 2, 0
_08016BDC: .4byte 0x03000064
_08016BE0: .4byte 0x00000CFC
_08016BE4: .4byte FUN_08016a7c
_08016BE8: .4byte FUN_08016ab4
_08016BEC:
	adds r0, r4, #0
_08016BEE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08016bf4
FUN_08016bf4: @ 0x08016BF4
	ldr r1, _08016BFC @ =0x03000068
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08016BFC: .4byte 0x03000068

	thumb_func_start FUN_08016c00
FUN_08016c00: @ 0x08016C00
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r0, #0
	mov ip, r0
	movs r6, #0
	movs r1, #1
	mov r8, r1
_08016C12:
	adds r0, r4, #0
	adds r0, #0x2c
	adds r5, r0, r6
	movs r0, #0
	ldrsb r0, [r5, r0]
	lsls r1, r6, #2
	lsls r0, r1
	mov r1, ip
	orrs r1, r0
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	ldrb r0, [r4, #0x1b]
	asrs r0, r6
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _08016C82
	lsls r2, r6, #1
	adds r0, r4, #0
	adds r0, #0x1c
	adds r3, r0, r2
	ldrh r0, [r3]
	adds r0, #1
	movs r7, #0
	strh r0, [r3]
	adds r1, r4, #0
	adds r1, #0x24
	adds r1, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _08016C82
	strh r7, [r3]
	adds r0, r4, #0
	adds r0, #0x30
	adds r0, r0, r6
	ldrb r3, [r5]
	movs r1, #0
	ldrsb r1, [r5, r1]
	ldrb r2, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	blt _08016C7E
	strb r2, [r5]
	mov r1, r8
	lsls r1, r6
	ldrb r0, [r4, #0x1b]
	bics r0, r1
	strb r0, [r4, #0x1b]
	b _08016C82
_08016C7E:
	adds r0, r3, #1
	strb r0, [r5]
_08016C82:
	adds r6, #1
	cmp r6, #3
	ble _08016C12
	ldrb r1, [r4, #0x19]
	ldrb r2, [r4, #0x1a]
	mov r0, ip
	bl Video_SetMosaic
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	bne _08016C9A
	strb r0, [r4, #0x18]
_08016C9A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08016ca4
FUN_08016ca4: @ 0x08016CA4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r0, #0
	mov ip, r0
	movs r6, #0
	movs r1, #1
	mov r8, r1
_08016CB6:
	adds r0, r4, #0
	adds r0, #0x2c
	adds r5, r0, r6
	movs r0, #0
	ldrsb r0, [r5, r0]
	lsls r1, r6, #2
	lsls r0, r1
	mov r1, ip
	orrs r1, r0
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	ldrb r0, [r4, #0x1b]
	asrs r0, r6
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _08016D26
	lsls r2, r6, #1
	adds r0, r4, #0
	adds r0, #0x1c
	adds r3, r0, r2
	ldrh r0, [r3]
	adds r0, #1
	movs r7, #0
	strh r0, [r3]
	adds r1, r4, #0
	adds r1, #0x24
	adds r1, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _08016D26
	strh r7, [r3]
	adds r0, r4, #0
	adds r0, #0x30
	adds r0, r0, r6
	ldrb r3, [r5]
	movs r1, #0
	ldrsb r1, [r5, r1]
	ldrb r2, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bgt _08016D22
	strb r2, [r5]
	mov r1, r8
	lsls r1, r6
	ldrb r0, [r4, #0x1b]
	bics r0, r1
	strb r0, [r4, #0x1b]
	b _08016D26
_08016D22:
	subs r0, r3, #1
	strb r0, [r5]
_08016D26:
	adds r6, #1
	cmp r6, #3
	ble _08016CB6
	ldrb r1, [r4, #0x19]
	ldrb r2, [r4, #0x1a]
	mov r0, ip
	bl Video_SetMosaic
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	bne _08016D3E
	strb r0, [r4, #0x18]
_08016D3E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08016d48
FUN_08016d48: @ 0x08016D48
	push {lr}
	adds r3, r0, #0
	ldr r2, _08016D64 @ =0x085AA920
	ldrb r1, [r3, #0x18]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	cmp r1, #0
	beq _08016D5E
	bl _call_via_r1
_08016D5E:
	pop {r1}
	bx r1
	.align 2, 0
_08016D64: .4byte 0x085AA920

	thumb_func_start FUN_08016d68
FUN_08016d68: @ 0x08016D68
	push {lr}
	bl Video_ClearMosaic
	ldr r1, _08016D78 @ =0x03000068
	movs r0, #0
	str r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_08016D78: .4byte 0x03000068

	thumb_func_start FUN_08016d7c
FUN_08016d7c: @ 0x08016D7C
	push {r4, r5, r6, lr}
	adds r1, r0, #0
	ldr r2, _08016DB8 @ =0x03000068
	str r1, [r2]
	movs r2, #0
	strb r2, [r1, #0x18]
	strb r2, [r1, #0x19]
	strb r2, [r1, #0x1a]
	strb r2, [r1, #0x1b]
	movs r4, #0
	movs r6, #0
	movs r5, #0
	adds r3, r1, #0
	adds r3, #0x1c
	adds r2, r1, #0
	adds r2, #0x2c
	adds r1, #0x24
_08016D9E:
	strh r5, [r3]
	strh r5, [r1]
	strb r6, [r2]
	strb r6, [r2, #4]
	adds r3, #2
	adds r2, #1
	adds r1, #2
	adds r4, #1
	cmp r4, #3
	ble _08016D9E
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08016DB8: .4byte 0x03000068

	thumb_func_start FUN_08016dbc
FUN_08016dbc: @ 0x08016DBC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08016DF8 @ =0x03000068
	ldr r0, [r0]
	cmp r0, #0
	bne _08016E06
	movs r0, #9
	movs r1, #0x34
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08016E04
	ldr r1, _08016DFC @ =FUN_08016d48
	ldr r2, _08016E00 @ =FUN_08016d68
	bl SetEntityRoutine
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08016d7c
	cmp r0, #0
	bge _08016E04
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08016E06
	.align 2, 0
_08016DF8: .4byte 0x03000068
_08016DFC: .4byte FUN_08016d48
_08016E00: .4byte FUN_08016d68
_08016E04:
	adds r0, r4, #0
_08016E06:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08016e0c
FUN_08016e0c: @ 0x08016E0C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	mov sl, r3
	ldr r0, _08016E3C @ =0x03000068
	ldr r0, [r0]
	cmp r0, #0
	bne _08016E40
	movs r0, #0
	movs r1, #0
	bl FUN_08016dbc
	adds r1, r0, #0
	cmp r1, #0
	bne _08016E42
	movs r0, #1
	rsbs r0, r0, #0
	b _08016E9E
	.align 2, 0
_08016E3C: .4byte 0x03000068
_08016E40:
	adds r1, r0, #0
_08016E42:
	strb r4, [r1, #0x18]
	strb r5, [r1, #0x19]
	strb r6, [r1, #0x1a]
	movs r0, #0xf
	strb r0, [r1, #0x1b]
	movs r3, #0
	movs r0, #0x24
	adds r0, r0, r1
	mov r8, r0
	movs r0, #0x2c
	adds r0, r0, r1
	mov ip, r0
	adds r7, r1, #0
	adds r7, #0x30
	movs r6, #0xf
	ldr r5, [sp, #0x24]
	adds r4, r1, #0
	adds r4, #0x1c
	mov sb, r3
_08016E68:
	lsls r1, r3, #1
	mov r0, sb
	strh r0, [r4]
	add r1, r8
	ldrh r0, [r5]
	strh r0, [r1]
	mov r1, ip
	adds r2, r1, r3
	mov r1, sl
	adds r0, r1, r3
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	strb r0, [r2]
	adds r2, r7, r3
	ldr r1, [sp, #0x20]
	adds r0, r1, r3
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	strb r0, [r2]
	adds r5, #2
	adds r4, #2
	adds r3, #1
	cmp r3, #3
	ble _08016E68
	movs r0, #0
_08016E9E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08016eac
FUN_08016eac: @ 0x08016EAC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	mov sl, r0
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	mov r8, r0
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08016EFA
	movs r4, #0
	add r6, sp, #0xc
	add r7, sp, #0x10
_08016EE6:
	bl Script_GetValue
	mov r1, sp
	adds r1, r1, r4
	adds r1, #8
	strb r0, [r1]
	adds r4, #1
	cmp r4, #3
	ble _08016EE6
	b _08016F0E
_08016EFA:
	add r6, sp, #0xc
	add r7, sp, #0x10
	movs r1, #0
	mov r0, sp
	adds r0, #0xb
_08016F04:
	strb r1, [r0]
	subs r0, #1
	add r2, sp, #8
	cmp r0, r2
	bge _08016F04
_08016F0E:
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08016F2A
	movs r4, #0
_08016F1A:
	bl Script_GetValue
	adds r1, r6, r4
	strb r0, [r1]
	adds r4, #1
	cmp r4, #3
	ble _08016F1A
	b _08016F38
_08016F2A:
	adds r1, r6, #0
	movs r2, #0
	adds r0, r6, #3
_08016F30:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _08016F30
_08016F38:
	movs r0, #0x69
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08016F56
	adds r5, r7, #0
	movs r4, #3
_08016F46:
	bl Script_GetValue
	strh r0, [r5]
	adds r5, #2
	subs r4, #1
	cmp r4, #0
	bge _08016F46
	b _08016F64
_08016F56:
	adds r1, r7, #0
	movs r2, #0
	adds r0, r7, #6
_08016F5C:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _08016F5C
_08016F64:
	str r6, [sp]
	str r7, [sp, #4]
	mov r0, sl
	mov r1, sb
	mov r2, r8
	add r3, sp, #8
	bl FUN_08016e0c
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08016f84
FUN_08016f84: @ 0x08016F84
	push {r4, r5, r6, r7, lr}
	ldr r0, _08016FD4 @ =0x03000068
	ldr r4, [r0]
	cmp r4, #0
	beq _08016FCC
	bl Video_ClearMosaic
	movs r0, #0
	strb r0, [r4, #0x18]
	strb r0, [r4, #0x19]
	strb r0, [r4, #0x1a]
	strb r0, [r4, #0x1b]
	movs r3, #0
	movs r6, #0
	movs r5, #0
	adds r2, r4, #0
	adds r2, #0x1c
	movs r0, #0x2c
	adds r0, r0, r4
	mov ip, r0
	adds r7, r4, #0
	adds r7, #0x30
	adds r1, r4, #0
	adds r1, #0x24
_08016FB4:
	strh r5, [r2]
	strh r5, [r1]
	mov r4, ip
	adds r0, r4, r3
	strb r6, [r0]
	adds r0, r7, r3
	strb r6, [r0]
	adds r2, #2
	adds r1, #2
	adds r3, #1
	cmp r3, #3
	ble _08016FB4
_08016FCC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08016FD4: .4byte 0x03000068

	thumb_func_start FUN_08016fd8
FUN_08016fd8: @ 0x08016FD8
	ldr r1, _08016FE0 @ =0x0300006C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08016FE0: .4byte 0x0300006C

	thumb_func_start FUN_08016fe4
FUN_08016fe4: @ 0x08016FE4
	movs r1, #0
	str r1, [r0]
	movs r2, #1
	strb r2, [r0, #4]
	strb r1, [r0, #5]
	strb r1, [r0, #6]
	str r1, [r0, #0xc]
	ldr r1, [r0, #0x2c]
	orrs r1, r2
	subs r2, #4
	ands r1, r2
	str r1, [r0, #0x2c]
	bx lr
	.align 2, 0

	thumb_func_start FUN_08017000
FUN_08017000: @ 0x08017000
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r6, #0x24
	adds r5, r0, #0
	adds r5, #0x44
	adds r7, r0, #0
	adds r7, #0x18
	ldrh r0, [r0, #0x18]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0801702A
	asrs r0, r0, #8
	b _08017030
_0801702A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08017030:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08017042
	asrs r0, r0, #8
	b _08017048
_08017042:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08017048:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r7, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0801705C
	asrs r0, r0, #8
	b _08017062
_0801705C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08017062:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08017094 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	ldrh r0, [r6, #0x20]
	subs r0, #8
	strh r0, [r6, #0x20]
	ldrh r0, [r6, #0x22]
	subs r0, #8
	strh r0, [r6, #0x22]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08017094: .4byte 0x030047C8

	thumb_func_start FUN_08017098
FUN_08017098: @ 0x08017098
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _080170B0
	movs r0, #0
	strb r0, [r4, #5]
	ldr r0, [r4, #0x2c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x2c]
_080170B0:
	ldr r0, [r4, #0xc]
	cmp r0, #2
	bhi _080170BC
	ldrh r0, [r4, #0x1a]
	adds r0, #0x10
	b _080170C0
_080170BC:
	ldrh r0, [r4, #0x1a]
	subs r0, #0x10
_080170C0:
	strh r0, [r4, #0x1a]
	adds r0, r4, #0
	bl FUN_08017000
	ldr r0, [r4, #0xc]
	cmp r0, #3
	bls _080170DA
	movs r0, #1
	movs r1, #0
	strb r0, [r4, #4]
	strb r0, [r4, #5]
	str r1, [r4, #0xc]
	b _080170DE
_080170DA:
	adds r0, #1
	str r0, [r4, #0xc]
_080170DE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080170e4
FUN_080170e4: @ 0x080170E4
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _080170FC
	movs r0, #0
	strb r0, [r4, #5]
	ldr r0, [r4, #0x2c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x2c]
_080170FC:
	adds r0, r4, #0
	bl FUN_08017000
	ldr r0, [r4, #0xc]
	ldrh r1, [r4, #0x10]
	cmp r0, r1
	blo _08017156
	ldrb r2, [r4, #7]
	cmp r2, #0
	bne _08017134
	ldrb r0, [r4, #0x12]
	ldr r1, _08017124 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08017128
	movs r0, #6
	b _0801712A
	.align 2, 0
_08017124: .4byte 0x03002BE0
_08017128:
	movs r0, #5
_0801712A:
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	str r2, [r4, #0xc]
	b _0801715A
_08017134:
	cmp r2, #1
	bne _08017144
	movs r0, #2
	movs r1, #0
	strb r0, [r4, #4]
	strb r2, [r4, #5]
	str r1, [r4, #0xc]
	b _0801715A
_08017144:
	cmp r2, #3
	bne _0801715A
	movs r0, #6
	movs r1, #0
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #5]
	str r1, [r4, #0xc]
	b _0801715A
_08017156:
	adds r0, #1
	str r0, [r4, #0xc]
_0801715A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08017160
FUN_08017160: @ 0x08017160
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r4, r1, #0
	mov r8, r2
	adds r5, r4, #0
	adds r5, #0x24
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _08017190
	movs r2, #0
	strb r2, [r4, #5]
	ldr r0, [r5, #8]
	movs r1, #2
	orrs r0, r1
	str r0, [r5, #8]
	strh r2, [r5, #0x36]
	adds r0, r4, #0
	adds r0, #0x58
	movs r1, #0x40
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_08017190:
	adds r6, r4, #0
	adds r6, #0x58
	ldrb r0, [r6]
	cmp r0, #8
	bls _0801719E
	subs r0, #8
	strb r0, [r6]
_0801719E:
	ldrb r0, [r6]
	adds r1, r4, #0
	adds r1, #0x59
	strb r0, [r1]
	ldrh r0, [r5, #0x36]
	adds r0, #0x10
	strh r0, [r5, #0x36]
	ldrh r0, [r4, #0x18]
	adds r0, #8
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x1c]
	adds r0, #8
	strh r0, [r4, #0x1c]
	adds r0, r4, #0
	bl FUN_08017000
	ldrb r1, [r6]
	movs r0, #0x40
	subs r0, r0, r1
	asrs r0, r0, #3
	ldrh r1, [r5, #0x20]
	adds r0, r0, r1
	strh r0, [r5, #0x20]
	ldr r0, [r4, #0xc]
	cmp r0, #7
	bls _080171E6
	adds r0, r4, #0
	bl FUN_08016fe4
	movs r1, #1
	mov r0, r8
	lsls r1, r0
	ldr r0, [r7, #0x18]
	bics r0, r1
	str r0, [r7, #0x18]
	b _080171EA
_080171E6:
	adds r0, #1
	str r0, [r4, #0xc]
_080171EA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080171f4
FUN_080171f4: @ 0x080171F4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r1, #0
	ldrb r0, [r7, #5]
	cmp r0, #0
	beq _08017210
	movs r0, #0
	strb r0, [r7, #5]
	ldr r0, [r7, #0x2c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x2c]
_08017210:
	ldrb r0, [r7, #7]
	cmp r0, #3
	bne _08017228
	ldr r0, [r7, #0xc]
	cmp r0, #3
	bhi _08017222
	ldrh r0, [r7, #0x1a]
	adds r0, #0x40
	b _08017238
_08017222:
	ldrh r0, [r7, #0x1a]
	subs r0, #4
	b _08017238
_08017228:
	ldr r0, [r7, #0xc]
	cmp r0, #4
	bhi _08017234
	ldrh r0, [r7, #0x1a]
	adds r0, #0x40
	b _08017238
_08017234:
	ldrh r0, [r7, #0x1a]
	subs r0, #8
_08017238:
	strh r0, [r7, #0x1a]
	adds r0, r7, #0
	bl FUN_08017000
	ldrb r0, [r7, #7]
	cmp r0, #3
	bne _080172A8
	ldr r0, [r7, #0xc]
	cmp r0, #3
	bls _0801728C
	ldr r0, _0801729C @ =0x0203B400
	mov r8, r0
	ldr r4, _080172A0 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r6, _080172A4 @ =0x000003FF
	ands r1, r6
	str r1, [r4]
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	adds r3, r7, #0
	adds r3, #0x44
	ldrh r0, [r3]
	subs r0, #1
	movs r5, #3
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ands r1, r6
	str r1, [r4]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	adds r2, r7, #0
	adds r2, #0x46
	ldrh r0, [r2]
	subs r0, #1
	ands r1, r5
	adds r0, r0, r1
	strh r0, [r2]
_0801728C:
	ldrb r0, [r7, #7]
	cmp r0, #3
	bne _080172A8
	ldr r0, [r7, #0xc]
	cmp r0, #8
	bls _080172BC
	b _080172AE
	.align 2, 0
_0801729C: .4byte 0x0203B400
_080172A0: .4byte 0x030046B8
_080172A4: .4byte 0x000003FF
_080172A8:
	ldr r0, [r7, #0xc]
	cmp r0, #7
	bls _080172BC
_080172AE:
	movs r0, #4
	movs r1, #0
	strb r0, [r7, #4]
	movs r0, #1
	strb r0, [r7, #5]
	str r1, [r7, #0xc]
	b _080172C0
_080172BC:
	adds r0, #1
	str r0, [r7, #0xc]
_080172C0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080172cc
FUN_080172cc: @ 0x080172CC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r4, r1, #0
	mov r8, r2
	adds r6, r4, #0
	adds r6, #0x24
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _08017306
	movs r2, #0
	strb r2, [r4, #5]
	ldr r0, [r4, #0x2c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x2c]
	ldr r0, [r6, #8]
	movs r1, #2
	orrs r0, r1
	str r0, [r6, #8]
	strh r2, [r6, #0x36]
	adds r0, r4, #0
	adds r0, #0x58
	movs r1, #0x40
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_08017306:
	adds r5, r4, #0
	adds r5, #0x58
	ldrb r0, [r5]
	cmp r0, #0x10
	bls _08017314
	subs r0, #0x10
	strb r0, [r5]
_08017314:
	ldrh r0, [r4, #0x1a]
	adds r0, #0x40
	strh r0, [r4, #0x1a]
	adds r0, r4, #0
	bl FUN_08017000
	ldrb r1, [r5]
	movs r0, #0x40
	subs r0, r0, r1
	asrs r0, r0, #3
	ldrh r1, [r6, #0x20]
	adds r0, r0, r1
	strh r0, [r6, #0x20]
	ldr r0, [r4, #0xc]
	cmp r0, #3
	bls _08017348
	adds r0, r4, #0
	bl FUN_08016fe4
	movs r1, #1
	mov r0, r8
	lsls r1, r0
	ldr r0, [r7, #0x18]
	bics r0, r1
	str r0, [r7, #0x18]
	b _0801734C
_08017348:
	adds r0, #1
	str r0, [r4, #0xc]
_0801734C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08017358
FUN_08017358: @ 0x08017358
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	str r0, [sp, #0x10]
	adds r5, r1, #0
	str r2, [sp, #0x14]
	movs r0, #0x24
	adds r0, r0, r5
	mov ip, r0
	ldrb r0, [r5, #5]
	cmp r0, #0
	beq _0801739E
	movs r2, #0
	strb r2, [r5, #5]
	ldr r0, [r5, #0x2c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x2c]
	mov r1, ip
	ldr r0, [r1, #8]
	movs r1, #2
	orrs r0, r1
	mov r1, ip
	str r0, [r1, #8]
	strh r2, [r1, #0x36]
	adds r0, r5, #0
	adds r0, #0x58
	movs r1, #0x40
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_0801739E:
	ldr r2, [r5, #0xc]
	mov r8, r2
	movs r0, #0x10
	mov r1, r8
	subs r1, r0, r1
	mov sl, r1
	ldrb r0, [r5, #7]
	cmp r0, #0
	bne _08017410
	ldrb r0, [r5, #0x12]
	ldr r1, _080173DC @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov r6, sp
	adds r7, r0, #0
	adds r7, #0x2c
	ldrh r0, [r0, #0x2c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080173E0
	asrs r0, r0, #8
	b _080173E6
	.align 2, 0
_080173DC: .4byte 0x03002BE0
_080173E0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080173E6:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080173F8
	asrs r0, r0, #8
	b _080173FE
_080173F8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080173FE:
	adds r4, r0, #0
	movs r2, #2
	ldrsh r1, [r7, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _0801745E
	b _08017462
_08017410:
	mov r6, sp
	ldr r2, [r5, #0x20]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08017430
	asrs r0, r0, #8
	b _08017436
_08017430:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08017436:
	strh r0, [r6]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08017448
	asrs r0, r0, #8
	b _0801744E
_08017448:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801744E:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08017462
_0801745E:
	asrs r0, r0, #8
	b _08017468
_08017462:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08017468:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _080174AC @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	adds r7, r3, #0
	add r4, sp, #8
	adds r6, r5, #0
	adds r6, #0x18
	ldrh r0, [r5, #0x18]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	mov sb, r4
	cmp r0, #0
	blt _080174B0
	asrs r0, r0, #8
	b _080174B6
	.align 2, 0
_080174AC: .4byte 0x030047C8
_080174B0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080174B6:
	strh r0, [r4]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080174C8
	asrs r0, r0, #8
	b _080174CE
_080174C8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080174CE:
	adds r3, r0, #0
	movs r2, #2
	ldrsh r1, [r6, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080174E2
	asrs r0, r0, #8
	b _080174E8
_080174E2:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080174E8:
	subs r2, r3, r0
	strh r2, [r4, #2]
	adds r3, r3, r0
	strh r3, [r4, #4]
	ldrh r0, [r4]
	ldrh r1, [r7]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r4]
	ldrh r0, [r7, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r4, #2]
	ldrh r0, [r7, #4]
	subs r3, r3, r0
	strh r3, [r4, #4]
	mov r1, sp
	ldrh r0, [r1, #2]
	subs r0, #4
	strh r0, [r1, #2]
	mov r1, sb
	movs r2, #0
	ldrsh r0, [r1, r2]
	mov r1, sl
	muls r1, r0, r1
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	adds r0, r1, r0
	cmp r0, #0
	blt _08017530
	asrs r0, r0, #4
	b _08017536
_08017530:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_08017536:
	mov r1, ip
	strh r0, [r1, #0x20]
	mov r2, sb
	movs r1, #2
	ldrsh r0, [r2, r1]
	mov r1, sl
	muls r1, r0, r1
	mov r0, sp
	movs r2, #2
	ldrsh r0, [r0, r2]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	adds r0, r1, r0
	cmp r0, #0
	blt _0801755A
	asrs r0, r0, #4
	b _08017560
_0801755A:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_08017560:
	mov r1, ip
	strh r0, [r1, #0x22]
	mov r2, ip
	adds r2, #0x34
	ldrb r0, [r2]
	cmp r0, #0x20
	bls _08017572
	subs r0, #2
	strb r0, [r2]
_08017572:
	ldrb r0, [r2]
	mov r1, ip
	adds r1, #0x35
	strb r0, [r1]
	mov r1, ip
	ldrh r0, [r1, #0x36]
	adds r0, #8
	strh r0, [r1, #0x36]
	ldrh r1, [r1, #0x20]
	subs r1, #8
	ldrb r2, [r2]
	movs r0, #0x40
	subs r0, r0, r2
	asrs r0, r0, #3
	adds r1, r1, r0
	mov r2, ip
	strh r1, [r2, #0x20]
	ldrh r0, [r2, #0x22]
	subs r0, #8
	strh r0, [r2, #0x22]
	ldr r0, [r5, #0xc]
	cmp r0, #0xf
	bls _08017604
	ldrb r0, [r5, #6]
	cmp r0, #0
	bne _080175E0
	ldr r1, [r5, #8]
	adds r0, r1, #0
	subs r0, #0x40
	cmp r0, #3
	bhi _080175BC
	ldr r0, _080175B8 @ =0x00000183
	bl PlaySound_0824078c
	b _080175EA
	.align 2, 0
_080175B8: .4byte 0x00000183
_080175BC:
	adds r0, r1, #0
	bl IsValuable
	cmp r0, #1
	bne _080175D4
	ldr r0, _080175D0 @ =0x00000123
	bl PlaySound_0824078c
	b _080175EA
	.align 2, 0
_080175D0: .4byte 0x00000123
_080175D4:
	ldr r0, _080175DC @ =0x00000111
	bl PlaySound_0824078c
	b _080175EA
	.align 2, 0
_080175DC: .4byte 0x00000111
_080175E0:
	cmp r0, #3
	beq _080175EA
	ldr r0, _08017600 @ =0x00000123
	bl PlaySound_0824078c
_080175EA:
	adds r0, r5, #0
	bl FUN_08016fe4
	movs r1, #1
	ldr r0, [sp, #0x14]
	lsls r1, r0
	ldr r2, [sp, #0x10]
	ldr r0, [r2, #0x18]
	bics r0, r1
	str r0, [r2, #0x18]
	b _08017608
	.align 2, 0
_08017600: .4byte 0x00000123
_08017604:
	adds r0, #1
	str r0, [r5, #0xc]
_08017608:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08017618
FUN_08017618: @ 0x08017618
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r5, #0
	ldr r1, _08017668 @ =0x085AA92C
	mov r8, r1
	adds r4, r7, #0
	adds r4, #0x40
	adds r6, r7, #0
	adds r6, #0x3c
_0801762E:
	movs r2, #1
	lsls r2, r5
	ldr r1, [r7, #0x18]
	ands r1, r2
	cmp r1, #0
	beq _08017652
	ldrb r1, [r4]
	cmp r1, #6
	bhi _08017652
	adds r0, r1, #0
	lsls r0, r0, #2
	add r0, r8
	ldr r3, [r0]
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl _call_via_r3
_08017652:
	adds r4, #0x84
	adds r6, #0x84
	adds r5, #1
	cmp r5, #7
	ble _0801762E
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08017668: .4byte 0x085AA92C

	thumb_func_start FUN_0801766c
FUN_0801766c: @ 0x0801766C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x60
	movs r5, #7
_08017674:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x84
	subs r5, #1
	cmp r5, #0
	bge _08017674
	movs r2, #0
	ldr r1, _08017690 @ =0x0300006C
	str r2, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08017690: .4byte 0x0300006C

	thumb_func_start FUN_08017694
FUN_08017694: @ 0x08017694
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	ldr r0, _080176BC @ =0x0300006C
	str r7, [r0]
	ldr r0, _080176C0 @ =0x0000CB05
	ldr r1, _080176C4 @ =0x00005D04
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _080176C8
	movs r0, #1
	rsbs r0, r0, #0
	b _0801773A
	.align 2, 0
_080176BC: .4byte 0x0300006C
_080176C0: .4byte 0x0000CB05
_080176C4: .4byte 0x00005D04
_080176C8:
	adds r1, r7, #0
	adds r1, #0x1c
	adds r0, r2, #0
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r5, r7, #0
	adds r5, #0x1c
	adds r0, r5, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	movs r0, #0
	str r0, [r7, #0x18]
	add r4, sp, #0x14
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _0801774C @ =0x05000002
	bl CpuSet
	mov sb, r5
	mov sl, r4
	movs r6, #0
	movs r5, #1
	mov r8, r5
	adds r4, r7, #0
	adds r4, #0x60
	adds r5, r7, #0
	adds r5, #0x3c
	movs r7, #7
_0801770C:
	str r6, [r5]
	mov r0, r8
	strb r0, [r5, #4]
	strb r6, [r5, #6]
	str r6, [r5, #0xc]
	mov r3, r8
	str r3, [sp]
	str r6, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r0, sl
	str r0, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	movs r3, #0x11
	bl FUN_0822f3fc
	adds r4, #0x84
	adds r5, #0x84
	subs r7, #1
	cmp r7, #0
	bge _0801770C
_0801773A:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801774C: .4byte 0x05000002

	thumb_func_start FUN_08017750
FUN_08017750: @ 0x08017750
	push {r4, lr}
	ldr r0, _08017784 @ =0x0300006C
	ldr r0, [r0]
	cmp r0, #0
	bne _08017796
	ldr r1, _08017788 @ =0x0000045C
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08017794
	ldr r1, _0801778C @ =FUN_08017618
	ldr r2, _08017790 @ =FUN_0801766c
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08017694
	cmp r0, #0
	bge _08017794
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08017796
	.align 2, 0
_08017784: .4byte 0x0300006C
_08017788: .4byte 0x0000045C
_0801778C: .4byte FUN_08017618
_08017790: .4byte FUN_0801766c
_08017794:
	adds r0, r4, #0
_08017796:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801779c
FUN_0801779c: @ 0x0801779C
	push {lr}
	ldr r0, _080177B0 @ =0x0300006C
	ldr r0, [r0]
	cmp r0, #0
	bne _080177AA
	bl FUN_08017750
_080177AA:
	pop {r1}
	bx r1
	.align 2, 0
_080177B0: .4byte 0x0300006C

	thumb_func_start FUN_080177b4
FUN_080177b4: @ 0x080177B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp]
	mov r8, r1
	str r2, [sp, #4]
	mov sl, r3
	ldr r7, [sp, #0x38]
	bl FUN_0801779c
	mov sb, r0
	ldr r4, _08017818 @ =0x00FFFFFF
	ands r4, r7
	ldr r1, [sp]
	lsls r0, r1, #0x1c
	orrs r4, r0
	movs r5, #0
	movs r2, #1
	rsbs r2, r2, #0
	str r2, [sp, #8]
	movs r1, #0
	movs r6, #1
	mov r0, sb
	ldr r3, [r0, #0x18]
	mov r2, sb
	adds r2, #0x3c
_080177EE:
	adds r0, r6, #0
	lsls r0, r1
	ands r0, r3
	cmp r0, #0
	bne _08017806
	adds r5, r2, #0
	str r1, [sp, #8]
	cmp r7, #0
	beq _08017806
	ldr r0, [r5]
	cmp r0, r4
	beq _0801781C
_08017806:
	adds r2, #0x84
	adds r1, #1
	cmp r1, #7
	ble _080177EE
_0801780E:
	cmp r5, #0
	bne _08017832
	movs r0, #1
	rsbs r0, r0, #0
	b _08017996
	.align 2, 0
_08017818: .4byte 0x00FFFFFF
_0801781C:
	adds r0, r5, #0
	bl FUN_08016fe4
	adds r1, r6, #0
	mov r2, r8
	lsls r1, r2
	mov r2, sb
	ldr r0, [r2, #0x18]
	bics r0, r1
	str r0, [r2, #0x18]
	b _0801780E
_08017832:
	str r4, [r5]
	movs r2, #0
	mov r0, sl
	strb r0, [r5, #0x12]
	ldrb r0, [r5, #0x12]
	ldr r1, _08017864 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _0801784A
	strb r2, [r5, #0x12]
_0801784A:
	ldr r0, [sp, #0x34]
	strh r0, [r5, #0x10]
	mov r1, sp
	ldrb r1, [r1, #4]
	strb r1, [r5, #7]
	ldrb r1, [r5, #7]
	cmp r1, #1
	beq _08017878
	cmp r1, #1
	bgt _08017868
	cmp r1, #0
	beq _08017872
	b _0801788E
	.align 2, 0
_08017864: .4byte 0x03002BE0
_08017868:
	cmp r1, #2
	beq _08017880
	cmp r1, #3
	beq _08017886
	b _0801788E
_08017872:
	movs r0, #3
	strb r0, [r5, #4]
	b _08017888
_08017878:
	movs r0, #0
	strb r0, [r5, #4]
	strb r1, [r5, #5]
	b _0801788C
_08017880:
	movs r0, #3
	strb r0, [r5, #4]
	b _08017888
_08017886:
	strb r1, [r5, #4]
_08017888:
	movs r0, #1
	strb r0, [r5, #5]
_0801788C:
	str r2, [r5, #0xc]
_0801788E:
	mov r2, sp
	ldrb r2, [r2]
	strb r2, [r5, #6]
	mov r0, r8
	str r0, [r5, #8]
	ldrb r0, [r5, #6]
	cmp r0, #1
	beq _080178B8
	cmp r0, #1
	bgt _080178A8
	cmp r0, #0
	beq _080178B2
	b _080178C8
_080178A8:
	cmp r0, #2
	beq _080178BC
	cmp r0, #3
	beq _080178C2
	b _080178C8
_080178B2:
	mov r2, r8
	adds r2, #0x68
	b _080178CA
_080178B8:
	mov r2, r8
	b _080178CA
_080178BC:
	mov r2, r8
	adds r2, #0x43
	b _080178CA
_080178C2:
	mov r2, r8
	adds r2, #0xb6
	b _080178CA
_080178C8:
	movs r2, #0x68
_080178CA:
	adds r0, r5, #0
	adds r0, #0x24
	mov r1, sb
	adds r1, #0x1c
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r5, #0x2c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x2c]
	ldr r2, [sp, #0x2c]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x18]
	str r1, [r5, #0x1c]
	ldr r0, [sp, #0x30]
	str r0, [r5, #0x20]
	adds r6, r5, #0
	adds r6, #0x44
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r7, r6, #0
	cmp r0, #0
	blt _08017916
	asrs r0, r0, #8
	b _0801791C
_08017916:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0801791C:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0801792E
	asrs r0, r0, #8
	b _08017934
_0801792E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08017934:
	adds r4, r0, #0
	ldr r0, [sp, #0x2c]
	movs r2, #2
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0801794A
	asrs r0, r0, #8
	b _08017950
_0801794A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08017950:
	subs r2, r4, r0
	strh r2, [r6, #2]
	adds r4, r4, r0
	strh r4, [r6, #4]
	ldr r3, _080179A8 @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	ldrh r0, [r7]
	subs r0, #8
	strh r0, [r7]
	adds r1, r5, #0
	adds r1, #0x46
	ldrh r0, [r1]
	subs r0, #8
	strh r0, [r1]
	ldr r0, [sp, #8]
	cmp r0, #0
	blt _08017994
	movs r1, #1
	lsls r1, r0
	mov r2, sb
	ldr r0, [r2, #0x18]
	orrs r0, r1
	str r0, [r2, #0x18]
_08017994:
	movs r0, #0
_08017996:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080179A8: .4byte 0x030047C8

