	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	cmp r0, #0
	bne _08059A8C
	movs r0, #1
	rsbs r0, r0, #0
	b _08059B6C
_08059A8C:
	adds r6, r0, #0
	movs r0, #0x3c
	adds r0, r0, r6
	mov ip, r0
	movs r7, #0
	movs r3, #1
	mov r8, r3
	movs r5, #0x34
	adds r5, r5, r6
	mov sl, r5
_08059AA0:
	mov r0, r8
	lsls r0, r7
	ldr r3, [r6, #0x1c]
	ands r3, r0
	cmp r3, #0
	bne _08059B5E
	mov r4, ip
	adds r4, #0x34
	mov r5, r8
	mov r0, ip
	strb r5, [r0, #2]
	strh r3, [r0, #6]
	strb r5, [r0]
	strb r1, [r0, #1]
	strb r2, [r0, #3]
	ldrh r1, [r6, #0x24]
	adds r0, #0xfc
	strh r1, [r0]
	mov r3, ip
	adds r3, #0x50
	mov r0, ip
	ldrb r5, [r0, #1]
	movs r1, #0x80
	lsls r1, r1, #1
	mov sb, r1
	ldr r2, _08059AF0 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	cmp r0, #0
	blt _08059AF4
	asrs r1, r0, #0xc
	b _08059AFA
	.align 2, 0
_08059AF0: .4byte gSineTable
_08059AF4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08059AFA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r5, sb
	muls r5, r0, r5
	adds r0, r5, #0
	cmp r0, #0
	blt _08059B16
	asrs r0, r0, #0xc
	b _08059B1C
_08059B16:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08059B1C:
	strh r0, [r3, #4]
	adds r1, r4, #0
	adds r1, #0x1c
	ldrh r0, [r6, #0x34]
	ldrh r2, [r4, #0x1c]
	adds r0, r0, r2
	strh r0, [r4, #0x1c]
	mov r3, sl
	ldrh r0, [r3, #2]
	ldrh r5, [r1, #2]
	adds r0, r0, r5
	strh r0, [r1, #2]
	ldrh r0, [r3, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	movs r0, #0x88
	lsls r0, r0, #1
	add r0, ip
	bl ParticleShadow_Show
	movs r0, #0x29
	strh r0, [r4, #0x10]
	adds r0, r4, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
	mov r1, r8
	lsls r1, r7
	ldr r0, [r6, #0x1c]
	orrs r0, r1
	str r0, [r6, #0x1c]
	b _08059B6A
_08059B5E:
	adds r7, #1
	movs r3, #0xa8
	lsls r3, r3, #1
	add ip, r3
	cmp r7, #7
	ble _08059AA0
_08059B6A:
	movs r0, #0
_08059B6C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
