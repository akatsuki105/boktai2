	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov r8, r0
	movs r7, #0
	movs r0, #1
	mov sb, r0
	movs r1, #0
	mov sl, r1
_080B0D40:
	movs r0, #0x68
	muls r0, r7, r0
	movs r3, #0xea
	lsls r3, r3, #2
	adds r0, r0, r3
	mov r1, r8
	adds r5, r1, r0
	adds r6, r5, #0
	adds r4, r5, #0
	adds r4, #0x2c
	ldr r0, _080B0D80 @ =0x08251DD0
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r7, #0
	mov r3, sb
	ands r0, r3
	cmp r0, #0
	beq _080B0D84
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x80
	lsls r2, r2, #2
	bl AuxSprite_Add
	b _080B0D90
	.align 2, 0
_080B0D80: .4byte 0x08251DD0
_080B0D84:
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x80
	lsls r2, r2, #3
	bl AuxSprite_Add
_080B0D90:
	mov r0, sl
	strh r0, [r5, #0x10]
	cmp r7, #0
	bne _080B0D9E
	movs r0, #2
	strb r0, [r5, #7]
	b _080B0DA2
_080B0D9E:
	mov r1, sb
	strb r1, [r5, #7]
_080B0DA2:
	movs r0, #0xc3
	lsls r0, r0, #3
	add r0, r8
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	lsls r0, r7, #5
	adds r1, r6, #0
	adds r1, #0x66
	strh r0, [r1]
	ldr r2, _080B0E28 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080B0E2C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080B0E30 @ =0x0203B400
	adds r0, r0, r3
	ldrb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x64
	strh r1, [r0]
	ldr r0, _080B0E34 @ =0x08251DD4
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080B0E38 @ =0x0000922E
	bl GetFile
	adds r1, r0, #0
	str r1, [r6, #0x58]
	adds r0, r6, #0
	adds r0, #0x48
	adds r4, r7, #1
	asrs r3, r4, #1
	movs r2, #5
	subs r2, r2, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r3, sl
	str r3, [sp]
	movs r3, #0
	bl AuxAnim_SetAnim
	mov r0, sb
	ands r7, r0
	cmp r7, #0
	beq _080B0E12
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	str r0, [r5]
_080B0E12:
	adds r7, r4, #0
	cmp r7, #5
	ble _080B0D40
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B0E28: .4byte 0x030046B8
_080B0E2C: .4byte 0x000003FF
_080B0E30: .4byte 0x0203B400
_080B0E34: .4byte 0x08251DD4
_080B0E38: .4byte 0x0000922E
