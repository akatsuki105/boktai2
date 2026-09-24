	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, [r6, #0x2c]
	cmp r0, #0
	beq _081D9AD0
	bl FUN_08238bf4
	movs r0, #1
	str r0, [r6, #0x30]
	ldr r0, [r6, #0x28]
	cmp r0, #0
	beq _081D9AB8
	ldr r3, [r6, #0x68]
	cmp r3, #0
	beq _081D9AC8
	ldr r0, [r6, #0x70]
	ldr r1, [r6, #0x24]
	ldr r2, [r6, #0x20]
	bl _call_via_r3
	b _081D9AC8
_081D9AB8:
	ldr r3, [r6, #0x6c]
	cmp r3, #0
	beq _081D9AC8
	ldr r0, [r6, #0x70]
	ldr r1, [r6, #0x24]
	ldr r2, [r6, #0x20]
	bl _call_via_r3
_081D9AC8:
	adds r0, r6, #0
	bl KillEntity
	b _081D9C82
_081D9AD0:
	movs r0, #0
	mov r8, r0
	movs r7, #0
	movs r1, #0
	mov sl, r1
	movs r4, #1
	mov sb, r4
	ldr r0, [r6, #0x24]
	cmp r0, #0
	bge _081D9B24
	ldr r0, [r6, #0x54]
	adds r0, #1
	str r0, [r6, #0x54]
	bl FUN_08238bc0
	str r0, [r6, #0x24]
	cmp r0, #0
	bge _081D9B0C
	ldr r0, [r6, #0x40]
	cmp r0, #0x1d
	ble _081D9B08
	bl FUN_08238cd4
	bl FUN_08238bc0
	str r0, [r6, #0x24]
	mov r0, sl
	b _081D9B0A
_081D9B08:
	adds r0, #1
_081D9B0A:
	str r0, [r6, #0x40]
_081D9B0C:
	adds r0, r6, #0
	bl LinkConnect_TickTimeout
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D9B1C
	movs r0, #1
	str r0, [r6, #0x2c]
_081D9B1C:
	movs r0, #0
	str r0, [r6, #0x3c]
	str r0, [r6, #0x38]
	b _081D9C5E
_081D9B24:
	adds r5, r6, #0
	adds r5, #0x5e
	adds r0, r5, #0
	bl FUN_08238da8
	str r0, [r6, #0x48]
	adds r4, r6, #0
	adds r4, #0x5c
	ldrh r0, [r4]
	bl FUN_08238e14
	str r0, [r6, #0x44]
	ldr r0, [r6, #0x2c]
	str r4, [sp]
	cmp r0, #0
	bne _081D9B4E
	ldr r0, [r6, #0x24]
	cmp r0, #0
	bne _081D9B4E
	bl FUN_08238d84
_081D9B4E:
	ldr r0, [r6, #0x48]
	cmp r0, #0
	blt _081D9BD8
	ldr r0, [r6, #0x58]
	adds r0, #1
	str r0, [r6, #0x58]
	movs r1, #0
	ldr r3, _081D9B78 @ =0x0000FFFF
	movs r2, #0xc9
	lsls r2, r2, #1
_081D9B62:
	ldrh r0, [r5]
	cmp r0, r3
	beq _081D9B8C
	mov r4, sb
	cmp r4, #0
	beq _081D9B86
	cmp r0, r2
	bne _081D9B7C
	adds r7, #1
	b _081D9B86
	.align 2, 0
_081D9B78: .4byte 0x0000FFFF
_081D9B7C:
	cmp r0, #0xe2
	bne _081D9B86
	adds r7, #1
	movs r0, #1
	add sl, r0
_081D9B86:
	movs r4, #1
	add r8, r4
	b _081D9B90
_081D9B8C:
	movs r0, #0
	mov sb, r0
_081D9B90:
	adds r5, #2
	adds r1, #1
	cmp r1, #3
	ble _081D9B62
	mov r1, r8
	cmp r1, #2
	bne _081D9BB8
	cmp r7, #2
	bne _081D9BB8
	ldr r0, [r6, #0x38]
	adds r0, #1
	str r0, [r6, #0x38]
	cmp r0, #0x77
	ble _081D9BB2
	movs r0, #0xe2
	ldr r4, [sp]
	strh r0, [r4]
_081D9BB2:
	movs r0, #0
	str r0, [r6, #0x34]
	b _081D9BCC
_081D9BB8:
	adds r0, r6, #0
	bl LinkConnect_TickTimeout
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D9BC8
	movs r0, #1
	str r0, [r6, #0x2c]
_081D9BC8:
	movs r0, #0
	str r0, [r6, #0x38]
_081D9BCC:
	mov r0, sl
	cmp r0, #2
	bne _081D9C5A
	movs r0, #1
	str r0, [r6, #0x28]
	b _081D9C58
_081D9BD8:
	movs r5, #0
	movs r0, #0xc9
	lsls r0, r0, #1
	ldr r1, [sp]
	strh r0, [r1]
	ldr r1, [r6, #0x48]
	movs r0, #3
	rsbs r0, r0, #0
	cmp r1, r0
	bne _081D9C26
	ldr r0, [r6, #0x4c]
	adds r0, #1
	str r0, [r6, #0x4c]
	ldr r0, [r6, #0x3c]
	cmp r0, #0x1d
	ble _081D9C10
	bl FUN_08238bf4
	bl FUN_08238cd4
	bl FUN_08238bc0
	str r0, [r6, #0x24]
	str r5, [r6, #0x38]
	str r5, [r6, #0x50]
	str r5, [r6, #0x3c]
	str r5, [r6, #0x40]
	b _081D9C14
_081D9C10:
	adds r0, #1
	str r0, [r6, #0x3c]
_081D9C14:
	adds r0, r6, #0
	bl LinkConnect_TickTimeout
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D9C5E
	movs r0, #1
	str r0, [r6, #0x2c]
	b _081D9C5E
_081D9C26:
	str r5, [r6, #0x38]
	ldr r0, [r6, #0x50]
	cmp r0, #0x1d
	ble _081D9C46
	bl FUN_08238bf4
	bl FUN_08238cd4
	bl FUN_08238bc0
	str r0, [r6, #0x24]
	str r5, [r6, #0x38]
	str r5, [r6, #0x50]
	str r5, [r6, #0x3c]
	str r5, [r6, #0x40]
	b _081D9C4A
_081D9C46:
	adds r0, #1
	str r0, [r6, #0x50]
_081D9C4A:
	adds r0, r6, #0
	bl LinkConnect_TickTimeout
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D9C5A
	movs r0, #1
_081D9C58:
	str r0, [r6, #0x2c]
_081D9C5A:
	movs r0, #0
	str r0, [r6, #0x3c]
_081D9C5E:
	ldr r0, [r6, #0x1c]
	cmp r0, #0
	beq _081D9C82
	ldr r0, [r6, #0x2c]
	cmp r0, #0
	bne _081D9C82
	ldr r2, [r6, #0x28]
	cmp r2, #0
	bne _081D9C82
	ldr r0, _081D9C94 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081D9C82
	movs r0, #1
	str r0, [r6, #0x2c]
	str r0, [r6, #0x20]
_081D9C82:
	movs r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D9C94: .4byte 0x030044E0
