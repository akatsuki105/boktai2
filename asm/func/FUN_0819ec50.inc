	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0819EC6A
	b _0819EDB0
_0819EC6A:
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r2, [r0]
	movs r1, #2
	ldr r3, _0819EC84 @ =0x00000E48
	adds r0, r2, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819EC88
	movs r0, #1
	b _0819EC8A
	.align 2, 0
_0819EC84: .4byte 0x00000E48
_0819EC88:
	movs r0, #0
_0819EC8A:
	cmp r0, #0
	bne _0819EC90
	b _0819EDB0
_0819EC90:
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r7, r2, r0
	ldrh r0, [r7, #0x20]
	cmp r0, #0
	bne _0819ECC4
	ldr r1, _0819ECC0 @ =0x02008000
	movs r0, #0xbc
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819ECAE
	b _0819EDB8
_0819ECAE:
	mov r1, r8
	ldr r0, [r1, #0x44]
	str r7, [r0, #0x38]
	mov r0, r8
	adds r1, r7, #0
	bl Ax_SetAfterimagePltt
	b _0819EDB8
	.align 2, 0
_0819ECC0: .4byte 0x02008000
_0819ECC4:
	movs r3, #0xbc
	lsls r3, r3, #1
	add r3, r8
	str r3, [sp]
	ldr r0, _0819ED28 @ =0x0000067C
	adds r0, r2, r0
	str r0, [sp, #4]
	ldr r1, _0819ED2C @ =0x000006DC
	adds r1, r2, r1
	str r1, [sp, #8]
	ldr r3, _0819ED30 @ =0x000006FC
	adds r3, r3, r2
	mov sl, r3
	ldr r0, _0819ED34 @ =0x0000071C
	adds r0, r0, r2
	mov sb, r0
	adds r5, r7, #0
	ldr r1, _0819ED38 @ =0x000006BC
	adds r4, r2, r1
	movs r3, #0
	mov ip, r3
	ldr r0, _0819ED3C @ =0x0000069C
	adds r3, r2, r0
_0819ECF2:
	ldr r1, [sp, #4]
	add r1, ip
	ldr r0, [sp, #8]
	add r0, ip
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	mov r0, sl
	add r0, ip
	ldrh r0, [r0]
	ldrh r2, [r3]
	adds r0, r0, r2
	strh r0, [r3]
	mov r0, sb
	add r0, ip
	ldrh r0, [r0]
	ldrh r2, [r4]
	adds r0, r0, r2
	strh r0, [r4]
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _0819ED40
	asrs r0, r0, #8
	b _0819ED46
	.align 2, 0
_0819ED28: .4byte 0x0000067C
_0819ED2C: .4byte 0x000006DC
_0819ED30: .4byte 0x000006FC
_0819ED34: .4byte 0x0000071C
_0819ED38: .4byte 0x000006BC
_0819ED3C: .4byte 0x0000069C
_0819ED40:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0819ED46:
	adds r6, r0, #0
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	blt _0819ED54
	asrs r0, r0, #8
	b _0819ED5A
_0819ED54:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0819ED5A:
	adds r2, r0, #0
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	blt _0819ED68
	asrs r1, r0, #8
	b _0819ED6E
_0819ED68:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0819ED6E:
	lsls r0, r2, #5
	orrs r0, r6
	lsls r1, r1, #0xa
	orrs r1, r0
	strh r1, [r5]
	adds r5, #2
	adds r4, #2
	movs r2, #2
	add ip, r2
	adds r3, #2
	adds r0, r7, #0
	adds r0, #0x1e
	cmp r5, r0
	ble _0819ECF2
	ldrh r0, [r7, #0x20]
	subs r0, #1
	strh r0, [r7, #0x20]
	ldr r1, _0819EDB4 @ =0x02008000
	ldr r3, [sp]
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _0819EDAA
	mov r1, r8
	ldr r0, [r1, #0x44]
	str r7, [r0, #0x38]
	mov r0, r8
	adds r1, r7, #0
	bl Ax_SetAfterimagePltt
_0819EDAA:
	ldrh r0, [r7, #0x20]
	cmp r0, #0
	beq _0819EDB8
_0819EDB0:
	movs r0, #0
	b _0819EDBA
	.align 2, 0
_0819EDB4: .4byte 0x02008000
_0819EDB8:
	movs r0, #1
_0819EDBA:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
