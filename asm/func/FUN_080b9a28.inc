	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0
	mov sl, r0
	mov sb, r3
	mov r8, r2
	ldr r3, [sp, #0x28]
	str r3, [sp, #4]
	adds r4, r5, #0
	adds r4, #0x20
	movs r7, #0
	str r7, [sp]
	adds r6, r1, #0
_080B9A4C:
	ldr r0, [r6]
	cmp r0, #0
	bne _080B9A5C
	ldr r0, [r4, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #8]
	b _080B9A9A
_080B9A5C:
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	ldr r0, [sp, #4]
	ldrh r2, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl MainSprite_SetPose
	adds r2, r5, #0
	adds r2, #0x40
	ldr r3, [sp]
	adds r2, r2, r3
	mov r7, sl
	lsls r3, r7, #3
	mov r7, r8
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r2, r5, #0
	adds r2, #0xe0
	adds r2, r2, r3
	mov r3, sb
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
_080B9A9A:
	movs r7, #8
	add sb, r7
	movs r0, #8
	add r8, r0
	ldr r3, [sp, #4]
	adds r3, #4
	str r3, [sp, #4]
	adds r4, #0x60
	ldr r7, [sp]
	adds r7, #0x60
	str r7, [sp]
	adds r6, #4
	movs r0, #1
	add sl, r0
	mov r3, sl
	cmp r3, #1
	ble _080B9A4C
	movs r1, #0
	adds r0, r5, #0
	adds r0, #0xf0
	strh r1, [r0]
	adds r1, r5, #0
	adds r1, #0xf2
	ldr r0, [sp, #0x30]
	strh r0, [r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
