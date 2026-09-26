	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	adds r4, r1, #0
	adds r7, r4, #0
	adds r0, r4, #0
	adds r0, #0x9c
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	adds r5, r4, #0
	adds r5, #0x40
	ldrh r1, [r5]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	cmp r6, #0
	beq _080DAF3E
	adds r0, r4, #0
	adds r0, #0x48
	ldrh r2, [r0]
	ldr r0, _080DAEAC @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r1, [r0]
	cmp r1, r2
	bge _080DAEB4
	ldr r3, _080DAEB0 @ =0xFFFFFF00
	adds r0, r2, r3
	subs r6, r1, r0
	b _080DAEB6
	.align 2, 0
_080DAEAC: .4byte 0x03002BE0
_080DAEB0: .4byte 0xFFFFFF00
_080DAEB4:
	subs r6, r1, r2
_080DAEB6:
	adds r0, r4, #0
	adds r0, #0x4a
	ldrh r1, [r0]
	adds r5, r4, #0
	adds r5, #0x40
	mov r8, r0
	cmp r1, r6
	beq _080DAED6
	movs r0, #4
	ands r0, r6
	cmp r0, #0
	beq _080DAED6
	ldrh r1, [r5]
	movs r0, #4
	orrs r0, r1
	strh r0, [r5]
_080DAED6:
	ldrb r0, [r7, #4]
	cmp r0, #0
	bne _080DAEE4
	adds r0, r7, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
_080DAEE4:
	ldrh r1, [r5]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080DAF14
	adds r1, r4, #0
	adds r1, #0x44
	movs r0, #0x3c
	strh r0, [r1]
	mov r0, sb
	adds r1, r4, #0
	bl FUN_080dac24
	adds r0, r4, #0
	adds r0, #0x1c
	bl FUN_0807a524
	mov r0, r8
	strh r6, [r0]
	ldrh r1, [r5]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strh r0, [r5]
_080DAF14:
	cmp r6, #9
	bgt _080DAF24
	ldrh r1, [r5]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080DAF24
	b _080DB020
_080DAF24:
	movs r0, #0
	strh r0, [r4, #0x3c]
	movs r0, #2
	strh r0, [r4, #0x3e]
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	ldrh r1, [r5]
	movs r0, #0x13
	rsbs r0, r0, #0
	b _080DB01A
_080DAF3E:
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080DAF88
	ldrb r0, [r4, #4]
	cmp r0, #0
	bne _080DAF54
	adds r0, r4, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
_080DAF54:
	ldrh r1, [r5]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080DAF70
	mov r0, sb
	adds r1, r4, #0
	bl FUN_080dac24
	ldrh r1, [r5]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strh r0, [r5]
_080DAF70:
	ldrh r1, [r5]
	movs r2, #2
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080DB020
	strh r6, [r4, #0x3c]
	strh r2, [r4, #0x3e]
	ldrh r1, [r5]
	movs r0, #3
	rsbs r0, r0, #0
	b _080DB01A
_080DAF88:
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, _080DAF9C @ =0x03002BE0
	ldr r0, [r0]
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _080DAFA0
	movs r0, #1
	b _080DAFA2
	.align 2, 0
_080DAF9C: .4byte 0x03002BE0
_080DAFA0:
	movs r0, #0
_080DAFA2:
	adds r5, r4, #0
	adds r5, #0x40
	cmp r0, #0
	bne _080DAFD0
	ldrh r1, [r5]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080DAFC4
	ldr r0, _080DAFE0 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080DAFE4 @ =0x00000942
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bgt _080DAFD0
_080DAFC4:
	adds r0, r4, #0
	bl FUN_080dad94
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080DAFE8
_080DAFD0:
	ldrb r0, [r7, #4]
	cmp r0, #0
	bne _080DAFF6
	adds r0, r7, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
	b _080DAFF6
	.align 2, 0
_080DAFE0: .4byte 0x030046A0
_080DAFE4: .4byte 0x00000942
_080DAFE8:
	ldrb r0, [r7, #4]
	cmp r0, #0
	beq _080DAFF6
	adds r0, r7, #0
	movs r1, #0
	bl Video_RemoveAuxSpriteFromDrawList
_080DAFF6:
	ldrh r1, [r5]
	movs r6, #2
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _080DB020
	ldrb r0, [r7, #4]
	cmp r0, #0
	bne _080DB010
	adds r0, r7, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
_080DB010:
	movs r0, #0
	strh r0, [r4, #0x3c]
	strh r6, [r4, #0x3e]
	ldrh r1, [r5]
	subs r0, #3
_080DB01A:
	ands r0, r1
	strh r0, [r5]
	b _080DB034
_080DB020:
	adds r0, r4, #0
	adds r0, #0x40
	ldrh r1, [r0]
	movs r0, #0x50
	ands r0, r1
	cmp r0, #0
	bne _080DB034
	adds r0, r4, #0
	bl FUN_080db0f8
_080DB034:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
