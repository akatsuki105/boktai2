	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp]
	ldr r1, _080C2C08 @ =0x00001930
	adds r1, r0, r1
	str r1, [sp, #4]
	movs r0, #1
	strb r0, [r1]
	movs r2, #0
	mov r8, r2
	movs r3, #0xc0
	mov sl, r3
_080C2BC8:
	mov r1, r8
	lsls r0, r1, #2
	add r0, r8
	lsls r1, r0, #4
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #4
	ldr r2, [sp, #4]
	adds r4, r2, r0
	movs r3, #0
	strb r3, [r4]
	mov r0, r8
	strb r0, [r4, #1]
	strb r3, [r4, #2]
	movs r0, #0xa0
	lsls r0, r0, #3
	strh r0, [r4, #0x10]
	movs r0, #0xe0
	lsls r0, r0, #3
	strh r0, [r4, #0x12]
	movs r0, #0xd1
	lsls r0, r0, #2
	strh r0, [r4, #0x14]
	mov r1, r8
	cmp r1, #1
	beq _080C2C28
	cmp r1, #1
	bgt _080C2C0C
	cmp r1, #0
	beq _080C2C18
	b _080C2C54
	.align 2, 0
_080C2C08: .4byte 0x00001930
_080C2C0C:
	mov r2, r8
	cmp r2, #2
	beq _080C2C38
	cmp r2, #3
	beq _080C2C48
	b _080C2C54
_080C2C18:
	ldr r0, _080C2C24 @ =0x0000FFC8
	strh r0, [r4, #8]
	mov r3, sl
	strh r3, [r4, #0xa]
	subs r0, #0x10
	b _080C2C52
	.align 2, 0
_080C2C24: .4byte 0x0000FFC8
_080C2C28:
	ldr r0, _080C2C34 @ =0x0000FF98
	strh r0, [r4, #8]
	mov r0, sl
	strh r0, [r4, #0xa]
	movs r0, #0x58
	b _080C2C52
	.align 2, 0
_080C2C34: .4byte 0x0000FF98
_080C2C38:
	movs r0, #0x68
	strh r0, [r4, #8]
	mov r1, sl
	strh r1, [r4, #0xa]
	ldr r0, _080C2C44 @ =0x0000FFA0
	b _080C2C52
	.align 2, 0
_080C2C44: .4byte 0x0000FFA0
_080C2C48:
	movs r0, #0x38
	strh r0, [r4, #8]
	mov r2, sl
	strh r2, [r4, #0xa]
	movs r0, #0x48
_080C2C52:
	strh r0, [r4, #0xc]
_080C2C54:
	movs r3, #8
	ldrsh r0, [r4, r3]
	ldrh r1, [r4, #8]
	cmp r0, #0
	ble _080C2C78
	ldrh r2, [r4, #0xc]
	movs r3, #0xc
	ldrsh r0, [r4, r3]
	cmp r0, #0
	ble _080C2C78
	ldrh r0, [r4, #0x10]
	adds r0, #0x60
	adds r0, r1, r0
	strh r0, [r4, #0x10]
	ldrh r0, [r4, #0x14]
	subs r0, #0x60
	adds r0, r2, r0
	b _080C2CAE
_080C2C78:
	lsls r0, r1, #0x10
	cmp r0, #0
	bge _080C2C98
	ldrh r2, [r4, #0xc]
	movs r3, #0xc
	ldrsh r0, [r4, r3]
	cmp r0, #0
	bge _080C2C98
	ldrh r0, [r4, #0x10]
	subs r0, #0x30
	adds r0, r1, r0
	strh r0, [r4, #0x10]
	ldrh r0, [r4, #0x14]
	adds r0, #0x30
	adds r0, r2, r0
	b _080C2CAE
_080C2C98:
	movs r1, #8
	ldrsh r0, [r4, r1]
	lsls r0, r0, #2
	ldrh r2, [r4, #0x10]
	adds r0, r0, r2
	strh r0, [r4, #0x10]
	movs r3, #0xc
	ldrsh r0, [r4, r3]
	lsls r0, r0, #2
	ldrh r1, [r4, #0x14]
	adds r0, r0, r1
_080C2CAE:
	strh r0, [r4, #0x14]
	movs r3, #0
	movs r2, #1
	add r2, r8
	mov sb, r2
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r7, r4, r0
_080C2CBE:
	movs r0, #0x2c
	muls r0, r3, r0
	adds r0, #0x24
	adds r6, r4, r0
	cmp r3, #0
	bne _080C2CD8
	ldr r1, _080C2CD4 @ =0x00008205
	mov r5, r8
	adds r5, #0xd
	b _080C2CDC
	.align 2, 0
_080C2CD4: .4byte 0x00008205
_080C2CD8:
	ldr r1, _080C2D2C @ =0x00008207
	movs r5, #6
_080C2CDC:
	adds r0, r7, #0
	str r3, [sp, #8]
	bl Video_GetAuxSprite
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0
	bl AuxSprite_Add
	strh r5, [r6, #0x10]
	movs r0, #1
	strb r0, [r6, #7]
	adds r7, #0x1c
	ldr r3, [sp, #8]
	adds r3, #1
	cmp r3, #7
	ble _080C2CBE
	adds r0, r4, #0
	ldr r1, _080C2D30 @ =0x00000165
	bl FUN_080c2694
	ldr r1, [sp]
	ldr r2, _080C2D34 @ =0x00000424
	adds r0, r1, r2
	ldr r0, [r0]
	str r0, [r4, #0x18]
	mov r8, sb
	mov r3, r8
	cmp r3, #3
	bgt _080C2D1A
	b _080C2BC8
_080C2D1A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C2D2C: .4byte 0x00008207
_080C2D30: .4byte 0x00000165
_080C2D34: .4byte 0x00000424
