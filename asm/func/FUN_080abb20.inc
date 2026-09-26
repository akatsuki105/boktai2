	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r0
	mov r8, r1
	mov r7, sl
	adds r7, #0x20
	mov r1, sl
	ldrb r0, [r1, #0x18]
	cmp r0, #0
	bne _080ABB52
	movs r4, #0
	movs r2, #3
	str r2, [sp]
	adds r1, #0xb2
	movs r0, #0x1f
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x14
	b _080ABB6A
_080ABB52:
	movs r4, #6
	movs r0, #2
	str r0, [sp]
	mov r2, sl
	adds r2, #0xb2
	movs r0, #0
	movs r1, #0x14
	strb r1, [r2]
	mov r1, sl
	adds r1, #0xb3
	strb r0, [r1]
	adds r1, #1
_080ABB6A:
	strb r0, [r1]
	adds r6, r7, #0
	adds r6, #0x2c
	ldr r1, _080ABC0C @ =0x0000210E
	adds r0, r6, #0
	bl Video_GetAuxSprite
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r5, #1
	movs r1, #0
	mov sb, r1
	strh r5, [r7, #0x10]
	adds r1, r4, #0
	adds r1, #0x2c
	adds r0, r6, #0
	bl Video_SetAuxSpritePltt
	movs r0, #2
	strb r0, [r7, #7]
	ldr r0, [r7]
	orrs r0, r5
	str r0, [r7]
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	adds r4, r7, #0
	adds r4, #0x48
	adds r6, #0x48
	ldr r1, _080ABC10 @ =0x00008639
	adds r0, r6, #0
	bl Video_GetAuxSprite
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl AuxSprite_Add
	mov r0, sb
	strh r0, [r4, #0x10]
	ldr r2, [sp]
	ldr r0, _080ABC14 @ =0x00000113
	adds r1, r2, r0
	adds r0, r6, #0
	bl Video_SetAuxSpritePltt
	movs r1, #1
	strb r1, [r4, #7]
	ldr r0, [r7, #0x48]
	orrs r0, r5
	str r0, [r7, #0x48]
	adds r1, r7, #0
	adds r1, #0x95
	movs r0, #0x24
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0x9c
	mov r2, sl
	str r2, [r0]
	subs r0, #0xc
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, _080ABC18 @ =FUN_080ab9e0
	str r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080ABC0C: .4byte 0x0000210E
_080ABC10: .4byte 0x00008639
_080ABC14: .4byte 0x00000113
_080ABC18: .4byte FUN_080ab9e0
