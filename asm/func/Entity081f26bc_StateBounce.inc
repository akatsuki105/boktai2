	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r1, #0
	ldr r6, [r5]
	adds r3, r5, #0
	adds r3, #0x76
	ldrb r0, [r3]
	cmp r0, #0
	beq _081F1CF4
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r1, r5, #0
	adds r1, #0x74
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r3]
_081F1CF4:
	adds r2, r5, #0
	adds r2, #0x6c
	ldrh r1, [r2]
	movs r0, #0x80
	ands r0, r1
	movs r1, #0x74
	adds r1, r1, r5
	mov r8, r1
	mov sb, r2
	adds r7, r6, #0
	adds r7, #0x18
	cmp r0, #0
	bne _081F1D10
	b _081F1E2C
_081F1D10:
	subs r2, #0x58
	ldrh r0, [r6, #0x18]
	ldrh r3, [r5, #0x14]
	adds r0, r0, r3
	strh r0, [r6, #0x18]
	ldrh r0, [r7, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r7, #2]
	ldrh r1, [r7, #4]
	ldrh r3, [r2, #4]
	adds r1, r1, r3
	strh r1, [r7, #4]
	ldrh r0, [r6, #0x18]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov r8, r2
	cmp r3, #0
	blt _081F1D4E
	cmp r1, #0
	blt _081F1D4E
	ldr r0, _081F1D54 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _081F1D4E
	ldr r0, _081F1D58 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081F1D5C
_081F1D4E:
	movs r4, #0
	b _081F1D6A
	.align 2, 0
_081F1D54: .4byte 0x030046A8
_081F1D58: .4byte 0x030046AC
_081F1D5C:
	ldr r0, _081F1D7C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_081F1D6A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F1D80
	adds r0, #4
	b _081F1D8C
	.align 2, 0
_081F1D7C: .4byte 0x030046A4
_081F1D80:
	ldr r0, _081F1E0C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F1D8C:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	movs r2, #0x1a
	ldrsh r0, [r6, r2]
	cmp r0, r1
	bgt _081F1E14
	strh r1, [r6, #0x1a]
	movs r3, #0x14
	ldrsh r1, [r5, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xa
	bl Div
	strh r0, [r5, #0x14]
	movs r1, #0x16
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bge _081F1DB8
	rsbs r0, r0, #0
_081F1DB8:
	lsls r0, r0, #1
	movs r1, #0xa
	bl Div
	strh r0, [r5, #0x16]
	movs r2, #0x18
	ldrsh r1, [r5, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xa
	bl Div
	strh r0, [r5, #0x18]
	movs r3, #0x14
	ldrsh r0, [r5, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	mov r2, r8
	movs r3, #2
	ldrsh r0, [r2, r3]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	mov r3, r8
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	movs r2, #0x74
	adds r2, r2, r5
	mov r8, r2
	cmn r1, r0
	bne _081F1E2C
	mov r3, sb
	ldrh r1, [r3]
	ldr r0, _081F1E10 @ =0x0000FF7F
	ands r0, r1
	strh r0, [r3]
	b _081F1E2C
	.align 2, 0
_081F1E0C: .4byte 0x030046A4
_081F1E10: .4byte 0x0000FF7F
_081F1E14:
	adds r4, r5, #0
	adds r4, #0x74
	ldrh r0, [r4]
	movs r1, #4
	bl Mod
	mov r8, r4
	cmp r0, #0
	beq _081F1E2C
	ldrh r0, [r5, #0x16]
	subs r0, #2
	strh r0, [r5, #0x16]
_081F1E2C:
	adds r0, r5, #0
	adds r1, r7, #0
	bl Entity081f26bc_UpdateHitbox
	mov ip, r5
	mov r1, ip
	adds r1, #4
	mov ip, r1
	subs r1, #4
	ldm r1!, {r0}
	ldr r3, [r0, #0x28]
	ldrh r0, [r1, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #4]
	adds r4, r1, r0
	ldrh r2, [r4]
	lsrs r2, r2, #6
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r6, #8]
	mov r2, ip
	ldrb r0, [r2, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F1E80
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081F1E88
_081F1E80:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F1E88:
	str r0, [r6]
	mov r3, ip
	ldrb r0, [r3, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F1EAE
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081F1EB6
_081F1EAE:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F1EB6:
	str r0, [r6]
	mov r1, ip
	ldrh r0, [r1, #0xe]
	adds r0, #1
	strh r0, [r1, #0xe]
	ldr r3, _081F1EF4 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r1, #7]
	cmp r0, r1
	blo _081F1F32
	movs r0, #0
	mov r3, ip
	strh r0, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F1F00
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _081F1EF8
	ldrb r0, [r3, #5]
	subs r0, #1
	strh r0, [r3, #8]
	movs r2, #1
	b _081F1F18
	.align 2, 0
_081F1EF4: .4byte 0x0000FFFF
_081F1EF8:
	subs r0, #1
	mov r1, ip
	strh r0, [r1, #8]
	b _081F1F16
_081F1F00:
	mov r3, ip
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _081F1F16
	strh r1, [r3, #8]
	movs r2, #1
	b _081F1F18
_081F1F16:
	movs r2, #0
_081F1F18:
	mov r3, ip
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	b _081F1F34
_081F1F32:
	movs r2, #0
_081F1F34:
	adds r3, r2, #0
	adds r0, r5, #0
	adds r0, #0x70
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _081F1F5E
	ldrh r0, [r5, #0xc]
	cmp r0, #5
	bne _081F1F58
	ldrh r1, [r5, #0x12]
	ldrb r0, [r5, #0xb]
	subs r0, #1
	cmp r1, r0
	bne _081F1F58
	movs r0, #0
	strh r0, [r5, #0xc]
	strh r0, [r5, #0x12]
_081F1F58:
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
_081F1F5E:
	mov r1, r8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	cmp r3, #0
	beq _081F1FF0
	mov r2, sb
	ldrh r1, [r2]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _081F1FE0
	ldr r0, _081F1FBC @ =0x030001EC
	ldr r2, [r0]
	adds r3, r5, #0
	adds r3, #0x6f
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r1, r4, #0
	lsls r1, r0
	ldr r0, [r2, #0x18]
	bics r0, r1
	str r0, [r2, #0x18]
	adds r1, r5, #0
	adds r1, #0x6e
	movs r0, #0
	strb r0, [r1]
	mov r0, sb
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	adds r4, r3, #0
	cmp r0, #0
	beq _081F1FC0
	ldr r1, [r5]
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081F1FD4
	adds r0, r1, #0
	bl AuxSprite_Remove
	ldr r0, [r5]
	bl Free
	b _081F1FD4
	.align 2, 0
_081F1FBC: .4byte 0x030001EC
_081F1FC0:
	ldr r1, [r5]
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081F1FD4
	adds r0, r1, #0
	bl Particle_Remove
	ldr r0, [r5]
	bl Free
_081F1FD4:
	movs r0, #0xff
	strb r0, [r4]
	movs r0, #0
	mov r1, sb
	strh r0, [r1]
	b _081F1FE8
_081F1FE0:
	adds r1, r5, #0
	adds r1, #0x6e
	movs r0, #3
	strb r0, [r1]
_081F1FE8:
	adds r1, r5, #0
	adds r1, #0x76
	movs r0, #1
	strb r0, [r1]
_081F1FF0:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
