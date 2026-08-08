	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r4, [sp, #0x2c]
	ldr r5, [sp, #0x30]
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	str r3, [sp, #8]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	mov sl, r5
	ldr r0, _08240C58 @ =0x03001700
	ldr r5, [r0]
	cmp r5, #0
	beq _08240C8A
	ldr r0, _08240C5C @ =0xFFFF0000
	str r6, [sp]
	ldr r1, [sp, #4]
	ands r1, r0
	orrs r1, r7
	str r1, [sp, #4]
	mov r0, sp
	bl FUN_08240b00
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08240C8A
	movs r2, #0
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r0, r0, #0xf
	mov sb, r0
	movs r0, #4
	orrs r4, r0
	ldr r0, _08240C60 @ =0x030046A0
	mov ip, r0
	adds r1, r5, #0
	movs r3, #0
_08240C30:
	movs r5, #0x20
	ldrsh r0, [r1, r5]
	cmp r0, #0
	bge _08240C82
	strh r6, [r1, #0x18]
	strh r3, [r1, #0x1a]
	strh r7, [r1, #0x1c]
	mov r0, sl
	strh r0, [r1, #0x26]
	mov r2, ip
	ldr r0, [r2]
	ldr r5, _08240C64 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #0x80
	ands r0, r2
	cmp r0, #0
	beq _08240C68
	movs r0, #1
	b _08240C6A
	.align 2, 0
_08240C58: .4byte 0x03001700
_08240C5C: .4byte 0xFFFF0000
_08240C60: .4byte 0x030046A0
_08240C64: .4byte 0x00000934
_08240C68:
	movs r0, #0
_08240C6A:
	cmp r0, #0
	beq _08240C74
	mov r5, sb
	strh r5, [r1, #0x20]
	b _08240C78
_08240C74:
	mov r0, r8
	strh r0, [r1, #0x20]
_08240C78:
	mov r2, sp
	ldrh r2, [r2, #8]
	strh r2, [r1, #0x22]
	strh r4, [r1, #0x24]
	b _08240C8A
_08240C82:
	adds r1, #0x10
	adds r2, #1
	cmp r2, #7
	ble _08240C30
_08240C8A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
