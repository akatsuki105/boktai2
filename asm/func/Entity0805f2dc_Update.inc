	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	mov r5, r8
	adds r5, #0x54
	movs r7, #0
	movs r0, #1
	mov sl, r0
	adds r4, r5, #0
	movs r1, #3
	mov sb, r1
_0805F10C:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805F20C
	movs r2, #0x68
	adds r2, r2, r5
	mov ip, r2
	adds r6, r5, #0
	adds r6, #0x18
	ldr r0, [r4, #4]
	cmp r0, #0x13
	bhi _0805F14C
	cmp r0, #0
	bne _0805F12C
	movs r0, #2
	strh r0, [r2, #0x10]
	b _0805F168
_0805F12C:
	cmp r0, #5
	bne _0805F134
	mov r0, sl
	b _0805F146
_0805F134:
	cmp r0, #0xa
	bne _0805F140
	mov r2, sb
	mov r1, ip
	strh r2, [r1, #0x10]
	b _0805F168
_0805F140:
	cmp r0, #0xf
	bne _0805F168
	movs r0, #0
_0805F146:
	mov r3, ip
	strh r0, [r3, #0x10]
	b _0805F168
_0805F14C:
	adds r1, r0, #0
	subs r1, #0x14
	movs r0, #7
	ands r1, r0
	cmp r1, #3
	bne _0805F15E
	mov r0, ip
	strh r1, [r0, #0x10]
	b _0805F168
_0805F15E:
	cmp r1, #7
	bne _0805F168
	movs r0, #0
	mov r1, ip
	strh r0, [r1, #0x10]
_0805F168:
	mov r1, ip
	adds r1, #0x1c
	ldrh r0, [r4, #0x10]
	mov r2, ip
	ldrh r2, [r2, #0x1c]
	adds r0, r0, r2
	mov r3, ip
	strh r0, [r3, #0x1c]
	ldrh r0, [r4, #0x12]
	ldrh r2, [r1, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	ldrh r0, [r4, #0x14]
	ldrh r3, [r1, #4]
	adds r0, r0, r3
	strh r0, [r1, #4]
	mov r0, r8
	ldr r3, [r0, #0x50]
	adds r0, r3, #0
	subs r0, #0x1e
	ldr r2, [r4, #4]
	cmp r2, r0
	bhs _0805F1C4
	cmp r2, #5
	bls _0805F206
	ldr r0, _0805F1C0 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0805F1AE
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _0805F206
_0805F1AE:
	adds r0, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r6, #0
	bl Hitbox_Register
	b _0805F206
	.align 2, 0
_0805F1C0: .4byte 0x03002BE0
_0805F1C4:
	adds r0, r3, #0
	subs r0, #0xf
	cmp r2, r0
	bhs _0805F1D6
	mov r3, sb
	ands r2, r3
	cmp r2, #0
	beq _0805F1E2
	b _0805F1EE
_0805F1D6:
	cmp r2, r3
	bhs _0805F1FC
	mov r0, sb
	ands r2, r0
	cmp r2, #1
	bhi _0805F1EE
_0805F1E2:
	mov r1, ip
	ldr r0, [r1]
	mov r2, sl
	orrs r0, r2
	str r0, [r1]
	b _0805F206
_0805F1EE:
	mov r3, ip
	ldr r0, [r3]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
	b _0805F206
_0805F1FC:
	mov r0, r8
	adds r1, r5, #0
	adds r2, r7, #0
	bl Entity0805f2dc_RemoveElem
_0805F206:
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
_0805F20C:
	adds r7, #1
	adds r4, #0x94
	adds r5, #0x94
	cmp r7, #0xb
	bgt _0805F218
	b _0805F10C
_0805F218:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
