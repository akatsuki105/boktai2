	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r1, r0, #0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r4, [r0]
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r1, r1, r3
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	movs r3, #2
	ldrsh r0, [r1, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r2, r2, r0
	movs r3, #4
	ldrsh r0, [r1, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r2, r0
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r6, r0
	ble _08137A96
	movs r6, #0xff
	b _08137AA0
_08137A96:
	cmp r6, #0x80
	ble _08137A9E
	movs r6, #0x7f
	b _08137AA0
_08137A9E:
	movs r6, #0x3f
_08137AA0:
	movs r2, #0
	mov ip, r2
	ldr r3, _08137AD8 @ =0x00000B3A
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0xb3
	lsls r2, r2, #4
	adds r2, r2, r4
	mov r8, r2
	cmp ip, r0
	bge _08137B92
	movs r7, #0
	movs r3, #0xcb
	lsls r3, r3, #3
	mov sl, r3
	ldr r0, _08137ADC @ =0x030046B8
	mov sb, r0
_08137AC4:
	adds r0, r7, r4
	add r0, sl
	adds r0, #0xfd
	ldrb r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08137AE0
	movs r0, #1
	b _08137AE2
	.align 2, 0
_08137AD8: .4byte 0x00000B3A
_08137ADC: .4byte 0x030046B8
_08137AE0:
	movs r0, #0
_08137AE2:
	cmp r0, #0
	beq _08137B7C
	adds r0, r7, r4
	add r0, sl
	adds r0, #0xfd
	ldrb r0, [r0]
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq _08137AFA
	movs r0, #1
	b _08137AFC
_08137AFA:
	movs r0, #0
_08137AFC:
	cmp r0, #0
	bne _08137B7C
	mov r3, sb
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _08137B3C @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _08137B40 @ =0x0203B400
	adds r0, r0, r1
	ldrh r3, [r0]
	adds r2, r7, r4
	ldr r0, _08137B44 @ =0x0000076C
	adds r2, r2, r0
	ands r3, r6
	movs r5, #0xc
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r1, _08137B48 @ =gSineTable
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08137B4C
	asrs r1, r0, #0xc
	b _08137B52
	.align 2, 0
_08137B3C: .4byte 0x000003FF
_08137B40: .4byte 0x0203B400
_08137B44: .4byte 0x0000076C
_08137B48: .4byte gSineTable
_08137B4C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08137B52:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	ldr r3, _08137B70 @ =gSineTable
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08137B74
	asrs r0, r0, #0xc
	b _08137B7A
	.align 2, 0
_08137B70: .4byte gSineTable
_08137B74:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08137B7A:
	strh r0, [r2, #4]
_08137B7C:
	movs r2, #0x90
	lsls r2, r2, #1
	adds r7, r7, r2
	movs r3, #1
	add ip, r3
	ldr r1, _08137BA4 @ =0x00000B3A
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp ip, r0
	blt _08137AC4
_08137B92:
	movs r1, #4
	mov r3, r8
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08137BA8
	movs r0, #1
	b _08137BAA
	.align 2, 0
_08137BA4: .4byte 0x00000B3A
_08137BA8:
	movs r0, #0
_08137BAA:
	cmp r0, #0
	beq _08137BC2
	movs r0, #0xf5
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r0, #5
	rsbs r0, r0, #0
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08137BC2:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
