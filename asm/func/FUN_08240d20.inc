	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sl, r0
	mov sb, r1
	mov r8, r2
	ldr r0, [sp, #0x28]
	lsls r3, r3, #0x18
	lsrs r7, r3, #0x18
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, _08240D48 @ =0x03001700
	ldr r1, [r0]
	cmp r1, #0
	bne _08240D52
	b _08240DB2
	.align 2, 0
_08240D48: .4byte 0x03001700
_08240D4C:
	lsls r0, r5, #0x18
	asrs r0, r0, #0x18
	b _08240DB6
_08240D52:
	ldr r5, [sp, #0x2c]
	cmp r5, #7
	bgt _08240DB2
	lsls r0, r5, #4
	adds r0, #0x18
	adds r4, r0, r1
_08240D5E:
	ldrh r1, [r4, #0xc]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _08240DAA
	ldrh r0, [r4, #0xe]
	cmp r0, #0
	beq _08240D72
	cmp r0, r6
	beq _08240DAA
_08240D72:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _08240D4C
	movs r1, #8
	ldrsh r0, [r4, r1]
	cmp r0, #0
	blt _08240DAA
	ldrh r0, [r4, #0xc]
	ands r0, r7
	cmp r0, #0
	beq _08240DAA
	movs r2, #0
	ldrsh r0, [r4, r2]
	movs r3, #4
	ldrsh r1, [r4, r3]
	movs r3, #8
	ldrsh r2, [r4, r3]
	mov r3, sb
	str r3, [sp]
	mov r3, r8
	str r3, [sp, #4]
	mov r3, sl
	bl FUN_08240ad4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08240D4C
_08240DAA:
	adds r4, #0x10
	adds r5, #1
	cmp r5, #7
	ble _08240D5E
_08240DB2:
	movs r0, #1
	rsbs r0, r0, #0
_08240DB6:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
