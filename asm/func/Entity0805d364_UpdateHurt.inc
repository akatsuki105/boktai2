	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0805CD32
	movs r0, #0
	strb r0, [r5]
	adds r2, r5, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, #0x2a
	bl Video_SetAuxSpritePltt
_0805CD32:
	ldrh r1, [r5, #4]
	movs r0, #0x14
	subs r0, r0, r1
	mov r3, sp
	ldrb r4, [r5, #6]
	lsls r6, r0, #1
	ldr r2, _0805CD5C @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805CD60
	asrs r1, r0, #0xc
	b _0805CD66
	.align 2, 0
_0805CD5C: .4byte gSineTable
_0805CD60:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805CD66:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805CD7E
	asrs r0, r0, #0xc
	b _0805CD84
_0805CD7E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805CD84:
	strh r0, [r3, #4]
	adds r1, r5, #0
	adds r1, #0x14
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r5, #0x14]
	adds r0, r0, r3
	strh r0, [r5, #0x14]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #1
	bl Entity0805d364_SetElemAnim
	ldrh r0, [r5, #4]
	cmp r0, #0x13
	bls _0805CDD0
	movs r0, #1
	strb r0, [r5, #1]
	strb r0, [r5]
	movs r0, #0
	strh r0, [r5, #4]
	adds r2, r5, #0
	adds r2, #0xdc
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	b _0805CE1E
_0805CDD0:
	cmp r0, #6
	bne _0805CDE8
	movs r3, #0x84
	lsls r3, r3, #1
	adds r4, r5, r3
	adds r0, r4, #0
	ldr r1, _0805CE04 @ =0x00000263
	bl Video_SetAuxSpritePltt
	ldr r1, _0805CE08 @ =0x00001688
	adds r0, r7, r1
	str r0, [r4, #0xc]
_0805CDE8:
	ldrh r0, [r5, #4]
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0805CE0C
	adds r0, r5, #0
	adds r0, #0xdc
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _0805CE16
	.align 2, 0
_0805CE04: .4byte 0x00000263
_0805CE08: .4byte 0x00001688
_0805CE0C:
	adds r0, r5, #0
	adds r0, #0xdc
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_0805CE16:
	str r1, [r0]
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
_0805CE1E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
