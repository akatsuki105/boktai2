	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r2, r0, #0
	movs r0, #1
	mov sb, r0
	adds r7, r2, #0
	adds r7, #0xdc
	adds r6, r2, #0
	adds r6, #0xfd
	adds r5, r2, #0
	adds r3, r2, #0
	adds r3, #0x2c
	ldr r1, _081F5DA8 @ =0x00000107
	adds r1, r1, r2
	mov r8, r1
_081F5D90:
	ldrb r1, [r6]
	mov r0, sb
	ands r0, r1
	cmp r0, #0
	beq _081F5DCA
	ldrb r0, [r6, #0xa]
	adds r4, r0, #0
	cmp r4, #0
	beq _081F5DAC
	subs r0, #1
	strb r0, [r6, #0xa]
	b _081F5DCA
	.align 2, 0
_081F5DA8: .4byte 0x00000107
_081F5DAC:
	adds r0, r3, #0
	movs r1, #0xd1
	lsls r1, r1, #1
	str r2, [sp]
	str r3, [sp, #4]
	bl Video_SetAuxSpritePltt
	mov r0, r8
	strb r4, [r0]
	ldrb r1, [r6]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6]
	ldr r3, [sp, #4]
	ldr r2, [sp]
_081F5DCA:
	ldrb r1, [r6]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081F5DE6
	ldrh r0, [r7]
	cmp r0, #0
	beq _081F5DDE
	subs r0, #1
	strh r0, [r7]
_081F5DDE:
	ldr r0, [r5]
	mov r1, sb
	orrs r0, r1
	b _081F5E22
_081F5DE6:
	adds r0, r5, #0
	adds r0, #0xdc
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _081F5E24
	lsrs r0, r0, #0x12
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq _081F5E06
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _081F5E0C
_081F5E06:
	ldr r0, [r5]
	mov r1, sb
	orrs r0, r1
_081F5E0C:
	str r0, [r5]
	ldrh r0, [r7]
	subs r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _081F5E24
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_081F5E22:
	str r0, [r5]
_081F5E24:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r7, r7, r0
	adds r6, r6, r0
	adds r5, r5, r0
	adds r3, r3, r0
	add r8, r0
	ldr r1, _081F5E48 @ =0x000005B4
	adds r0, r2, r1
	cmp r5, r0
	ble _081F5D90
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F5E48: .4byte 0x000005B4
