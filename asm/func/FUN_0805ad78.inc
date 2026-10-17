	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805ADA0
	movs r0, #0
	strb r0, [r4]
	adds r2, r4, #0
	adds r2, #0x98
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r1, #0xd4
	lsls r1, r1, #1
	adds r0, r4, r1
	subs r1, #0x76
	bl Video_SetAuxSpritePltt
_0805ADA0:
	ldrh r1, [r4, #6]
	movs r0, #0x14
	subs r0, r0, r1
	mov r3, sp
	ldrb r5, [r4, #0xa]
	lsls r6, r0, #1
	ldr r2, _0805ADC8 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805ADCC
	asrs r1, r0, #0xc
	b _0805ADD2
	.align 2, 0
_0805ADC8: .4byte gSineTable
_0805ADCC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805ADD2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805ADEA
	asrs r0, r0, #0xc
	b _0805ADF0
_0805ADEA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805ADF0:
	strh r0, [r3, #4]
	adds r1, r4, #0
	adds r1, #0x14
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r4, #0x14]
	adds r0, r0, r3
	strh r0, [r4, #0x14]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	ldrh r0, [r4, #6]
	cmp r0, #0x13
	bls _0805AE24
	movs r0, #2
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	movs r0, #0
	b _0805AE38
_0805AE24:
	cmp r0, #0xa
	bne _0805AE34
	movs r3, #0xd4
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r1, #0xc8
	bl Video_SetAuxSpritePltt
_0805AE34:
	ldrh r0, [r4, #6]
	adds r0, #1
_0805AE38:
	strh r0, [r4, #6]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
