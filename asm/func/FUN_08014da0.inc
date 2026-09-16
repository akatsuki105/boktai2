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
	bl Entity08015220_Create
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
