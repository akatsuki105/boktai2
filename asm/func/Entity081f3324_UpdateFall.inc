	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	adds r5, r1, #0
	adds r7, r5, #0
	adds r4, r5, #0
	adds r4, #0x2c
	adds r3, r5, #0
	adds r3, #0xf0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081F2E9C
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r2, r5, #0
	adds r2, #0xee
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	strb r1, [r3]
_081F2E9C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F2EC8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F2ED0
_081F2EC8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F2ED0:
	str r0, [r5]
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
	beq _081F2EF4
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081F2EFC
_081F2EF4:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F2EFC:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F2F34 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081F2F6C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F2F38
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F2F2C
	ldrb r0, [r4, #5]
_081F2F2C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F2F48
	.align 2, 0
_081F2F34: .4byte 0x0000FFFF
_081F2F38:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F2F48
	strh r1, [r4, #8]
_081F2F48:
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
	bne _081F2F6C
	movs r0, #1
	strb r0, [r4, #7]
_081F2F6C:
	adds r4, r5, #0
	adds r4, #0x8a
	ldrh r0, [r4]
	subs r0, #4
	strh r0, [r4]
	adds r2, r7, #0
	adds r2, #0x1c
	adds r3, r5, #0
	adds r3, #0x88
	ldrh r0, [r7, #0x1c]
	ldrh r1, [r3]
	adds r0, r0, r1
	strh r0, [r7, #0x1c]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	ldr r0, [r5, #0x1c]
	ldr r1, [r5, #0x20]
	str r0, [r5, #0x44]
	str r1, [r5, #0x48]
	adds r6, r2, #0
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov sb, r4
	mov r8, r3
	cmp r2, #0
	blt _081F2FC8
	cmp r1, #0
	blt _081F2FC8
	ldr r0, _081F2FCC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081F2FC8
	ldr r0, _081F2FD0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081F2FD4
_081F2FC8:
	movs r4, #0
	b _081F2FE2
	.align 2, 0
_081F2FCC: .4byte 0x030046A8
_081F2FD0: .4byte 0x030046AC
_081F2FD4:
	ldr r0, _081F2FF4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081F2FE2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F2FF8
	adds r0, #4
	b _081F3004
	.align 2, 0
_081F2FF4: .4byte 0x030046A4
_081F2FF8:
	ldr r0, _081F3018 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F3004:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081F301C
	cmp r2, #2
	beq _081F3020
	b _081F3024
	.align 2, 0
_081F3018: .4byte 0x030046A4
_081F301C:
	ldrb r0, [r6, #4]
	b _081F3022
_081F3020:
	ldrb r0, [r6]
_081F3022:
	subs r1, r1, r0
_081F3024:
	lsls r0, r1, #0x10
	lsrs r3, r0, #0x10
	adds r1, r5, #0
	adds r1, #0xee
	ldrh r0, [r1]
	adds r0, #1
	movs r2, #0
	strh r0, [r1]
	movs r0, #0x1e
	ldrsh r1, [r7, r0]
	cmp r1, #0
	bgt _081F3068
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
	str r0, [r7]
	adds r0, r5, #0
	adds r0, #0xeb
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r0
	mov r2, sl
	ldr r0, [r2, #0x38]
	bics r0, r1
	str r0, [r2, #0x38]
	adds r0, r5, #0
	bl AuxSprite_Remove
	adds r1, r5, #0
	adds r1, #0xea
	movs r0, #0
	strb r0, [r1]
	b _081F309C
_081F3068:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bgt _081F309C
	strh r3, [r7, #0x1e]
	mov r0, r8
	strh r2, [r0]
	mov r1, sb
	strh r2, [r1]
	adds r0, r5, #0
	adds r0, #0x8c
	strh r2, [r0]
	adds r1, r5, #0
	adds r1, #0xea
	movs r0, #3
	strb r0, [r1]
	adds r1, #6
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5, #0x1c]
	ldr r1, [r5, #0x20]
	str r0, [r5, #0x44]
	str r1, [r5, #0x48]
	movs r0, #0xf2
	bl PlaySound_082406e0
_081F309C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
