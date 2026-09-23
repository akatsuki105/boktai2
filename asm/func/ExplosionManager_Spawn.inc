	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	adds r6, r1, #0
	mov sb, r2
	adds r7, r3, #0
	ldr r0, _08060840 @ =0x03000138
	ldr r0, [r0]
	cmp r0, #0
	bne _08060810
	movs r0, #0
	movs r1, #0
	bl ExplosionManager_Create
	cmp r0, #0
	beq _080608D0
_08060810:
	movs r3, #0
	ldr r5, _08060840 @ =0x03000138
_08060814:
	movs r0, #0x58
	muls r0, r3, r0
	adds r0, #0x18
	ldr r1, [r5]
	adds r2, r1, r0
	adds r4, r2, #0
	adds r4, #0x2c
	ldrb r0, [r2]
	cmp r0, #0
	bne _080608CA
	movs r0, #1
	strb r0, [r2]
	movs r0, #4
	ands r0, r6
	cmp r0, #0
	beq _08060844
	movs r0, #0xc0
	lsls r0, r0, #8
	ands r0, r6
	asrs r5, r0, #0xc
	b _08060846
	.align 2, 0
_08060840: .4byte 0x03000138
_08060844:
	movs r5, #1
_08060846:
	ldr r0, _08060890 @ =0xFFFF3FFF
	ands r6, r0
	movs r0, #0
	strb r6, [r2, #1]
	strh r0, [r2, #2]
	mov r0, sp
	ldrh r0, [r0, #0x1c]
	strh r0, [r2, #4]
	mov r1, sp
	ldrh r1, [r1, #0x20]
	strh r1, [r2, #6]
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	adds r0, r2, #0
	adds r0, #0x10
	ldr r1, _08060894 @ =0x00000113
	add r1, r8
	bl Video_SetAuxSpritePltt
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	strb r5, [r4, #7]
	movs r0, #1
	ands r0, r6
	cmp r0, #0
	beq _08060898
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	b _0806089E
	.align 2, 0
_08060890: .4byte 0xFFFF3FFF
_08060894: .4byte 0x00000113
_08060898:
	ldr r0, [r4]
	ldr r1, _080608B0 @ =0xFFFFFDFF
	ands r0, r1
_0806089E:
	str r0, [r4]
	movs r0, #2
	ands r0, r6
	cmp r0, #0
	beq _080608B4
	ldr r0, [r4]
	movs r1, #0x10
	orrs r0, r1
	b _080608BC
	.align 2, 0
_080608B0: .4byte 0xFFFFFDFF
_080608B4:
	ldr r0, [r4]
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r0, r1
_080608BC:
	str r0, [r4]
	adds r0, r4, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
	movs r0, #0
	b _080608D4
_080608CA:
	adds r3, #1
	cmp r3, #0xf
	ble _08060814
_080608D0:
	movs r0, #1
	rsbs r0, r0, #0
_080608D4:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
