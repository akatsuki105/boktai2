	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r1, [sp, #0x3c]
	mov sl, r6
	movs r0, #0x95
	adds r0, r0, r6
	mov r8, r0
	movs r0, #0
	mov sb, r0
	mov r0, r8
	strb r3, [r0]
	adds r7, r6, #0
	adds r7, #0x96
	strb r2, [r7]
	adds r0, r6, #0
	adds r0, #0x94
	strb r1, [r0]
	add r5, sp, #0x10
	mov r0, sb
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	adds r1, r5, #0
	ldr r2, _080C50C4 @ =0x05000002
	bl CpuSet
	cmp r4, #0
	bne _080C50D0
	ldr r1, _080C50C8 @ =0x00008203
	ldr r2, _080C50CC @ =0x00005C4D
	str r5, [sp]
	adds r0, r6, #0
	movs r3, #0
	bl SpriteHolder_InitAux
	ldrb r1, [r7]
	mov r0, r8
	ldrb r2, [r0]
	movs r0, #1
	str r0, [sp]
	mov r0, sb
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
	b _080C50F6
	.align 2, 0
_080C50C4: .4byte 0x05000002
_080C50C8: .4byte 0x00008203
_080C50CC: .4byte 0x00005C4D
_080C50D0:
	ldr r1, _080C5120 @ =0x00009524
	adds r0, r6, #0
	movs r2, #0
	adds r3, r5, #0
	bl SpriteHolder_InitMain
	ldrb r1, [r7]
	mov r0, r8
	ldrb r2, [r0]
	movs r0, #1
	str r0, [sp]
	mov r0, sb
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C50F6:
	mov r0, sl
	ldr r1, [sp, #0x38]
	bl SpriteHolder_SetPriority
	adds r0, r6, #0
	adds r0, #0x94
	ldrb r0, [r0]
	cmp r0, #0
	bne _080C5110
	adds r0, r6, #0
	movs r1, #1
	bl SpriteHolder_SetFlags
_080C5110:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C5120: .4byte 0x00009524
