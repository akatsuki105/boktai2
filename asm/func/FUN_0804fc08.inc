	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, [r4, #0x68]
	cmp r1, #0
	bne _0804FC1E
	b _0804FD1C
_0804FC1E:
	ldr r0, _0804FC78 @ =0x03002CF0
	ldr r0, [r0]
	bl Mod
	adds r5, r0, #0
	movs r0, #0
	str r0, [sp]
	ldr r6, [r4, #0x70]
	movs r7, #0
	ldr r1, _0804FC7C @ =0x030046A0
	mov sl, r1
	movs r2, #0xf
	mov sb, r2
_0804FC38:
	mov r1, sl
	ldr r0, [r1]
	lsls r1, r7, #1
	adds r0, r1, r0
	adds r0, #0x60
	mov ip, r0
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r2, #0
	mov r2, ip
	strh r0, [r2]
	adds r4, r5, #0
	mov r8, r1
	adds r1, r5, #0
	adds r1, #0x10
	adds r7, #1
	cmp r5, r1
	bge _0804FCA6
	adds r2, r5, #0
	mov r0, sb
	ands r2, r0
	movs r3, #1
	lsls r3, r2
	adds r0, r6, #0
	ands r0, r3
	cmp r0, #0
	beq _0804FC80
	mov r1, ip
	strh r2, [r1]
	bics r6, r3
	b _0804FCA6
	.align 2, 0
_0804FC78: .4byte 0x03002CF0
_0804FC7C: .4byte 0x030046A0
_0804FC80:
	adds r4, #1
	cmp r4, r1
	bge _0804FCA6
	adds r2, r4, #0
	mov r0, sb
	ands r2, r0
	movs r3, #1
	lsls r3, r2
	adds r0, r6, #0
	ands r0, r3
	cmp r0, #0
	beq _0804FC80
	mov r1, sl
	ldr r0, [r1]
	add r0, r8
	adds r0, #0x60
	strh r2, [r0]
	bics r6, r3
	adds r5, r4, #0
_0804FCA6:
	mov r2, sl
	ldr r0, [r2]
	add r0, r8
	adds r0, #0x60
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _0804FCBA
	movs r2, #1
	str r2, [sp]
_0804FCBA:
	ldr r1, _0804FD2C @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0804FD30 @ =0x000003FF
	ands r0, r1
	ldr r2, _0804FD2C @ =0x030046B8
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0804FD34 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r2, sb
	ands r0, r2
	adds r5, r5, r0
	cmp r7, #3
	ble _0804FC38
	ldr r0, [sp]
	cmp r0, #0
	beq _0804FD12
	movs r7, #0
	ldr r5, _0804FD38 @ =0x030046A0
_0804FCE4:
	ldr r0, [r5]
	lsls r4, r7, #1
	adds r0, r4, r0
	adds r1, r0, #0
	adds r1, #0x60
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _0804FD0C
	bl GetWeaponID
	cmp r0, #0
	bne _0804FD0C
	ldr r0, [r5]
	adds r0, r4, r0
	adds r0, #0x60
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	strh r1, [r0]
_0804FD0C:
	adds r7, #1
	cmp r7, #3
	ble _0804FCE4
_0804FD12:
	ldr r1, _0804FD38 @ =0x030046A0
	ldr r0, [r1]
	adds r0, #0x58
	movs r1, #0
	strh r1, [r0]
_0804FD1C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804FD2C: .4byte 0x030046B8
_0804FD30: .4byte 0x000003FF
_0804FD34: .4byte 0x0203B400
_0804FD38: .4byte 0x030046A0
