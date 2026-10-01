	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	adds r7, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r0, r0, r7
	mov sl, r0
	mov r5, sl
	movs r1, #0
	str r1, [sp, #0x48]
	adds r0, r7, #0
	mov r1, sl
	bl FUN_0801b904
	adds r1, r7, #0
	adds r1, #0x98
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_0801bc98
	cmp r0, #0
	beq _0801BD1A
	mov r1, sl
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
_0801BD1A:
	adds r0, r7, #0
	adds r0, #0xa0
	ldr r1, [r0]
	str r0, [sp, #0x4c]
	movs r0, #0x41
	adds r0, r0, r7
	mov sb, r0
	movs r2, #0x42
	adds r2, r2, r7
	mov r8, r2
	cmp r1, #4
	bhi _0801BD34
	b _0801BE80
_0801BD34:
	adds r4, r7, #0
	adds r4, #0xa8
	ldr r0, [r4]
	cmp r0, #0
	bne _0801BD40
	b _0801BE80
_0801BD40:
	mov r3, sl
	ldrb r0, [r3, #1]
	bl GetWeaponSkillLevel
	asrs r0, r0, #2
	ldr r2, [r4]
	lsls r1, r2, #1
	adds r1, r1, r2
	adds r0, r0, r1
	adds r1, r7, #0
	adds r1, #0xb0
	ldr r2, [r1]
	lsls r1, r2, #2
	adds r1, r1, r2
	subs r6, r0, r1
	cmp r6, #0x64
	ble _0801BD66
	movs r6, #0x64
	b _0801BD6C
_0801BD66:
	cmp r6, #0
	bge _0801BD6C
	movs r6, #0
_0801BD6C:
	ldr r2, _0801BDA0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801BDA4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _0801BDA8 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x64
	bl Mod
	cmp r0, r6
	bgt _0801BDB0
	ldrb r0, [r5]
	bl FUN_0823d414
	ldrb r1, [r0, #0x18]
	cmp r1, #0
	beq _0801BDAC
	movs r1, #1
	str r1, [sp, #0x48]
	ldr r0, [r0, #0x18]
	str r0, [r5, #0x18]
	b _0801BDB4
	.align 2, 0
_0801BDA0: .4byte 0x030046B8
_0801BDA4: .4byte 0x000003FF
_0801BDA8: .4byte 0x0203B400
_0801BDAC:
	strb r1, [r5, #0x18]
	b _0801BDB4
_0801BDB0:
	movs r0, #0
	strb r0, [r5, #0x18]
_0801BDB4:
	ldr r2, _0801BDF8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801BDFC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0801BE00 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x64
	bl Mod
	cmp r0, r6
	bgt _0801BE0A
	adds r4, r7, #0
	adds r4, #0x41
	ldrb r0, [r4]
	mov r1, sp
	bl FUN_08242b14
	add r0, sp, #0x18
	ldrb r0, [r0]
	mov sb, r4
	cmp r0, #0
	beq _0801BE04
	ldrb r3, [r5, #0x18]
	cmp r0, r3
	beq _0801BE04
	ldr r0, [sp, #0x18]
	str r0, [r5, #0x1c]
	movs r4, #1
	str r4, [sp, #0x48]
	b _0801BE14
	.align 2, 0
_0801BDF8: .4byte 0x030046B8
_0801BDFC: .4byte 0x000003FF
_0801BE00: .4byte 0x0203B400
_0801BE04:
	movs r0, #0
	strb r0, [r5, #0x1c]
	b _0801BE14
_0801BE0A:
	movs r0, #0
	strb r0, [r5, #0x1c]
	movs r0, #0x41
	adds r0, r0, r7
	mov sb, r0
_0801BE14:
	ldr r2, _0801BE5C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801BE60 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0801BE64 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x64
	bl Mod
	cmp r0, r6
	bgt _0801BE72
	adds r4, r7, #0
	adds r4, #0x42
	ldrb r0, [r4]
	add r1, sp, #0x24
	bl FUN_08242b14
	add r0, sp, #0x3c
	ldrb r0, [r0]
	mov r8, r4
	cmp r0, #0
	beq _0801BE68
	ldrb r2, [r5, #0x18]
	cmp r0, r2
	beq _0801BE68
	ldrb r3, [r5, #0x1c]
	cmp r0, r3
	beq _0801BE68
	ldr r0, [sp, #0x3c]
	str r0, [r5, #0x20]
	b _0801BF16
	.align 2, 0
_0801BE5C: .4byte 0x030046B8
_0801BE60: .4byte 0x000003FF
_0801BE64: .4byte 0x0203B400
_0801BE68:
	adds r1, r5, #0
	adds r1, #0x20
	movs r0, #0
	strb r0, [r1]
	b _0801BE80
_0801BE72:
	adds r1, r5, #0
	adds r1, #0x20
	movs r0, #0
	strb r0, [r1]
	movs r4, #0x42
	adds r4, r4, r7
	mov r8, r4
_0801BE80:
	ldr r0, [sp, #0x48]
	cmp r0, #0
	bne _0801BF16
	ldr r1, [sp, #0x4c]
	ldr r0, [r1]
	movs r6, #2
	cmp r0, #9
	bls _0801BEAA
	movs r6, #3
	cmp r0, #0xe
	bls _0801BEAA
	movs r6, #8
	cmp r0, #0x13
	bls _0801BEAA
	movs r6, #0xf
	cmp r0, #0x18
	bls _0801BEAA
	movs r6, #0x28
	cmp r0, #0x1d
	bhi _0801BEAA
	movs r6, #0x19
_0801BEAA:
	ldrb r0, [r5, #1]
	bl FUN_0801b6a4
	adds r4, r0, #0
	ldr r2, [sp, #0x4c]
	ldr r1, [r2]
	movs r0, #0x64
	muls r0, r1, r0
	adds r1, r7, #0
	adds r1, #0xa4
	ldr r1, [r1]
	subs r0, r0, r1
	adds r1, r6, #0
	bl Div
	subs r4, r4, r0
	movs r3, #8
	ldrsh r0, [r5, r3]
	adds r4, r4, r0
	asrs r4, r4, #1
	ldr r1, [sp, #0x4c]
	ldr r0, [r1]
	cmp r0, #4
	bhi _0801BEE0
	movs r4, #0xa
	rsbs r4, r4, #0
	b _0801BEEA
_0801BEE0:
	cmp r0, #9
	bhi _0801BEEA
	cmp r4, #0
	ble _0801BEEA
	movs r4, #0
_0801BEEA:
	movs r0, #0xa
	rsbs r0, r0, #0
	cmp r4, r0
	bge _0801BEF6
	strh r0, [r5, #8]
	b _0801BF02
_0801BEF6:
	cmp r4, #0xa
	ble _0801BF00
	movs r0, #0xa
	strh r0, [r5, #8]
	b _0801BF02
_0801BF00:
	strh r4, [r5, #8]
_0801BF02:
	adds r6, r5, #0
	adds r6, #0xc
	movs r1, #0
	adds r0, r5, #0
	adds r0, #8
_0801BF0C:
	strb r1, [r0, #0x18]
	subs r0, #4
	cmp r0, r5
	bge _0801BF0C
	b _0801BF1E
_0801BF16:
	movs r0, #0
	strh r0, [r5, #8]
	adds r6, r5, #0
	adds r6, #0xc
_0801BF1E:
	mov r2, sb
	ldrb r0, [r2]
	bl FUN_08242c08
	mov r3, r8
	ldrb r0, [r3]
	bl FUN_08242c08
	ldr r4, _0801BF80 @ =0x030046A0
	ldr r1, [r4]
	movs r0, #0xf0
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r6, #0
	movs r2, #0xa
	bl CopyMemory
	movs r0, #0
	strb r0, [r5, #0x16]
	adds r0, r5, #0
	bl FUN_08242b88
	ldr r1, [r4]
	movs r2, #0xbf
	lsls r2, r2, #2
	adds r1, r1, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, [r4]
	adds r2, r0, r2
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldr r1, _0801BF84 @ =0x0000270F
	cmp r0, r1
	ble _0801BF68
	strh r1, [r2]
_0801BF68:
	adds r0, r7, #0
	mov r1, sl
	bl FUN_0801b688
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801BF80: .4byte 0x030046A0
_0801BF84: .4byte 0x0000270F
