	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	adds r0, r6, #0
	adds r0, #0x76
	ldrb r0, [r0]
	cmp r0, #0
	beq _081F19C6
	adds r0, r6, #0
	adds r0, #0x6c
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	ldr r0, [r6]
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	adds r0, r6, #0
	adds r0, #0x74
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strb r2, [r0]
_081F19C6:
	adds r0, r6, #0
	movs r1, #0
	bl Entity081f26bc_UpdateHitbox
	adds r2, r6, #0
	adds r2, #0x6c
	ldrh r1, [r2]
	movs r0, #8
	ands r0, r1
	adds r7, r2, #0
	cmp r0, #0
	bne _081F19E0
	b _081F1AE6
_081F19E0:
	mov ip, r6
	mov r0, ip
	adds r0, #4
	mov ip, r0
	subs r0, #4
	ldm r0!, {r4}
	ldrh r0, [r0, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r4, #0x10]
	mov r1, ip
	ldrb r0, [r1, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F1A1A
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _081F1A22
_081F1A1A:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F1A22:
	str r0, [r4]
	mov r2, ip
	ldrb r0, [r2, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F1A48
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _081F1A50
_081F1A48:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F1A50:
	str r0, [r4]
	mov r3, ip
	ldrh r0, [r3, #0xe]
	adds r0, #1
	strh r0, [r3, #0xe]
	ldr r4, _081F1A8C @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r3, #7]
	cmp r0, r1
	blo _081F1ADA
	movs r0, #0
	strh r0, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F1A98
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _081F1A90
	ldrb r0, [r3, #5]
	subs r0, #1
	strh r0, [r3, #8]
	movs r2, #1
	b _081F1AB0
	.align 2, 0
_081F1A8C: .4byte 0x0000FFFF
_081F1A90:
	subs r0, #1
	mov r2, ip
	strh r0, [r2, #8]
	b _081F1AAE
_081F1A98:
	mov r3, ip
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r4, [r3, #5]
	cmp r0, r4
	blo _081F1AAE
	strh r1, [r3, #8]
	movs r2, #1
	b _081F1AB0
_081F1AAE:
	movs r2, #0
_081F1AB0:
	mov r1, ip
	ldrh r0, [r1, #8]
	lsls r0, r0, #1
	ldr r1, [r1]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	mov r3, ip
	strb r0, [r3, #6]
	ldrb r1, [r3, #6]
	ldrh r0, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081F1ADC
	movs r0, #1
	strb r0, [r3, #7]
	b _081F1ADC
_081F1ADA:
	movs r2, #0
_081F1ADC:
	adds r3, r2, #0
	ldr r0, [r6]
	adds r2, r0, #0
	adds r2, #0x1c
	b _081F1BEE
_081F1AE6:
	mov ip, r6
	mov r0, ip
	adds r0, #4
	mov ip, r0
	subs r0, #4
	ldm r0!, {r4}
	ldr r3, [r4, #0x28]
	ldrh r0, [r0, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #4]
	adds r5, r1, r0
	ldrh r2, [r5]
	lsrs r2, r2, #6
	ldrb r1, [r4, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r4, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r4, #8]
	mov r1, ip
	ldrb r0, [r1, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F1B32
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _081F1B3A
_081F1B32:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F1B3A:
	str r0, [r4]
	mov r2, ip
	ldrb r0, [r2, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081F1B60
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _081F1B68
_081F1B60:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F1B68:
	str r0, [r4]
	mov r3, ip
	ldrh r0, [r3, #0xe]
	adds r0, #1
	strh r0, [r3, #0xe]
	ldr r4, _081F1BA4 @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r3, #7]
	cmp r0, r1
	blo _081F1BE4
	movs r0, #0
	strh r0, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F1BB0
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _081F1BA8
	ldrb r0, [r3, #5]
	subs r0, #1
	strh r0, [r3, #8]
	movs r2, #1
	b _081F1BC8
	.align 2, 0
_081F1BA4: .4byte 0x0000FFFF
_081F1BA8:
	subs r0, #1
	mov r2, ip
	strh r0, [r2, #8]
	b _081F1BC6
_081F1BB0:
	mov r3, ip
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r4, [r3, #5]
	cmp r0, r4
	blo _081F1BC6
	strh r1, [r3, #8]
	movs r2, #1
	b _081F1BC8
_081F1BC6:
	movs r2, #0
_081F1BC8:
	mov r1, ip
	ldrh r0, [r1, #8]
	lsls r0, r0, #1
	ldr r1, [r1]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	mov r3, ip
	ldrh r1, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	b _081F1BE6
_081F1BE4:
	movs r2, #0
_081F1BE6:
	adds r3, r2, #0
	ldr r0, [r6]
	adds r2, r0, #0
	adds r2, #0x18
_081F1BEE:
	ldrh r1, [r7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _081F1C14
	adds r1, r6, #0
	adds r1, #0x14
	ldrh r0, [r2]
	ldrh r4, [r6, #0x14]
	adds r0, r0, r4
	strh r0, [r2]
	ldrh r0, [r2, #2]
	ldrh r4, [r1, #2]
	adds r0, r0, r4
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
_081F1C14:
	adds r1, r6, #0
	adds r1, #0x74
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	cmp r3, #0
	beq _081F1CB0
	adds r0, r6, #0
	adds r0, #0x70
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081F1CBC
	ldrh r1, [r7]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _081F1C9E
	ldr r0, _081F1C7C @ =0x030001EC
	ldr r2, [r0]
	adds r3, r6, #0
	adds r3, #0x6f
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r1, r4, #0
	lsls r1, r0
	ldr r0, [r2, #0x18]
	bics r0, r1
	str r0, [r2, #0x18]
	adds r1, r6, #0
	adds r1, #0x6e
	movs r0, #0
	strb r0, [r1]
	ldrh r1, [r7]
	movs r0, #8
	ands r0, r1
	adds r4, r3, #0
	cmp r0, #0
	beq _081F1C80
	ldr r1, [r6]
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081F1C94
	adds r0, r1, #0
	bl AuxSprite_Remove
	ldr r0, [r6]
	bl Free
	b _081F1C94
	.align 2, 0
_081F1C7C: .4byte 0x030001EC
_081F1C80:
	ldr r1, [r6]
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081F1C94
	adds r0, r1, #0
	bl Particle_Remove
	ldr r0, [r6]
	bl Free
_081F1C94:
	movs r0, #0xff
	strb r0, [r4]
	movs r0, #0
	strh r0, [r7]
	b _081F1CA6
_081F1C9E:
	adds r1, r6, #0
	adds r1, #0x6e
	movs r0, #3
	strb r0, [r1]
_081F1CA6:
	adds r1, r6, #0
	adds r1, #0x76
	movs r0, #1
	strb r0, [r1]
	b _081F1CC2
_081F1CB0:
	adds r0, r6, #0
	adds r0, #0x70
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _081F1CC2
_081F1CBC:
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
_081F1CC2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
