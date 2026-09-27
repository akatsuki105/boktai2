	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	mov r8, r0
	movs r0, #1
	bl FUN_08086978
	cmp r0, #0
	bne _081D3DE8
	b _081D3F9C
_081D3DE8:
	movs r2, #0x10
	mov r1, r8
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081D3DFC
	movs r0, #1
	b _081D3DFE
_081D3DFC:
	movs r0, #0
_081D3DFE:
	cmp r0, #0
	bne _081D3E04
	b _081D3F9C
_081D3E04:
	mov r4, sp
	mov r0, sp
	bl FUN_08086a28
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D3E32
	cmp r1, #0
	blt _081D3E32
	ldr r0, _081D3E38 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D3E32
	ldr r0, _081D3E3C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D3E40
_081D3E32:
	movs r4, #0
	b _081D3E4E
	.align 2, 0
_081D3E38: .4byte 0x030046A8
_081D3E3C: .4byte 0x030046AC
_081D3E40:
	ldr r0, _081D3E64 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081D3E4E:
	mov r0, sp
	movs r1, #2
	ldrsh r5, [r0, r1]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D3E68
	adds r0, #4
	b _081D3E74
	.align 2, 0
_081D3E64: .4byte 0x030046A4
_081D3E68:
	ldr r0, _081D3E90 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D3E74:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	cmp r5, r0
	bne _081D3EAA
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081D3E94
	adds r0, #4
	b _081D3EA0
	.align 2, 0
_081D3E90: .4byte 0x030046A4
_081D3E94:
	ldr r0, _081D3F2C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081D3EA0:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _081D3F9C
_081D3EAA:
	add r3, sp, #8
	mov r4, r8
	adds r4, #0xfc
	mov r5, sp
	mov r0, sp
	ldrh r1, [r0]
	ldrh r0, [r4]
	subs r1, r1, r0
	strh r1, [r3]
	ldrh r2, [r5, #2]
	ldrh r0, [r4, #2]
	subs r6, r2, r0
	strh r6, [r3, #2]
	ldrh r2, [r5, #4]
	ldrh r0, [r4, #4]
	subs r7, r2, r0
	strh r7, [r3, #4]
	ldr r0, _081D3F30 @ =0x085AE0D0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r5, #0
	ldrsh r2, [r0, r5]
	adds r5, r0, #0
	cmp r1, r2
	bgt _081D3F26
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmn r1, r0
	blt _081D3F18
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r6, #2
	ldrsh r1, [r5, r6]
	cmp r0, r1
	bgt _081D3F18
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r2, #2
	ldrsh r0, [r5, r2]
	cmn r1, r0
	blt _081D3F18
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	movs r6, #4
	ldrsh r1, [r5, r6]
	cmp r0, r1
	bgt _081D3F18
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	cmn r1, r0
	bge _081D3F9C
_081D3F18:
	movs r6, #0
	ldrsh r1, [r3, r6]
	ldrh r2, [r5]
	movs r6, #0
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _081D3F34
_081D3F26:
	ldrh r0, [r5]
	b _081D3F42
	.align 2, 0
_081D3F2C: .4byte 0x030046A4
_081D3F30: .4byte 0x085AE0D0
_081D3F34:
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r6, #0
	ldrsh r0, [r5, r6]
	cmn r1, r0
	bge _081D3F44
	rsbs r0, r2, #0
_081D3F42:
	strh r0, [r3]
_081D3F44:
	movs r0, #4
	ldrsh r1, [r3, r0]
	ldrh r2, [r5, #4]
	movs r6, #4
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _081D3F56
	strh r2, [r3, #4]
	b _081D3F66
_081D3F56:
	movs r0, #4
	ldrsh r1, [r3, r0]
	movs r6, #4
	ldrsh r0, [r5, r6]
	cmn r1, r0
	bge _081D3F66
	rsbs r0, r2, #0
	strh r0, [r3, #4]
_081D3F66:
	ldrh r0, [r3]
	ldrh r4, [r4]
	adds r0, r0, r4
	mov r1, sp
	strh r0, [r1]
	mov r0, r8
	adds r0, #0xfe
	ldrh r0, [r0]
	mov r2, sp
	strh r0, [r2, #2]
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, r8
	add r0, sp, #8
	ldrh r0, [r0, #4]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	bl FUN_08086a4c
	movs r0, #0x80
	lsls r0, r0, #2
	mov r2, sb
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081D3F9C:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
