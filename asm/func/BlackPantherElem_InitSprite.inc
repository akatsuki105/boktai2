	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r7, r1, #0
	adds r1, r3, #0
	ldr r5, [sp, #0x24]
	ldr r3, [sp, #0x28]
	adds r4, r7, #0
	adds r4, #0x7c
	cmp r2, #2
	bne _0805342E
	adds r0, r4, #0
	adds r2, r5, #0
	bl SpriteHolder_InitMain
	adds r5, r0, #0
	adds r0, r7, #0
	adds r0, #0xa8
	ldr r1, [r7]
	cmp r1, #2
	bne _08053422
	movs r1, #0x27
	bl MainSprite_SetPlttID
	b _0805344E
_08053422:
	cmp r1, #1
	bne _0805344E
	movs r1, #0x26
	bl MainSprite_SetPlttID
	b _0805344E
_0805342E:
	str r3, [sp]
	adds r0, r4, #0
	ldr r2, [sp, #0x20]
	adds r3, r5, #0
	bl SpriteHolder_InitAux
	adds r5, r0, #0
	adds r1, r7, #0
	adds r1, #0x88
	ldr r0, [r7]
	cmp r0, #2
	bne _0805344E
	adds r0, r1, #0
	movs r1, #0x27
	bl Video_SetAuxSpritePltt
_0805344E:
	cmp r5, #0
	bge _08053458
	movs r0, #1
	rsbs r0, r0, #0
	b _080534CC
_08053458:
	adds r0, r4, #0
	movs r1, #2
	bl SpriteHolder_SetPriority
	movs r0, #0xc0
	movs r1, #0
	strb r0, [r7, #0xf]
	movs r0, #1
	strb r0, [r7, #0x11]
	movs r0, #3
	mov r8, r0
	movs r0, #0
	strb r0, [r7, #0x10]
	str r1, [sp]
	str r1, [sp, #4]
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #3
	movs r3, #1
	bl BlackPantherElem_PlayAnim
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r4, r7, r1
	movs r2, #0x84
	lsls r2, r2, #1
	adds r5, r7, r2
	ldr r1, [r5]
	adds r0, r4, #0
	movs r2, #1
	bl ParticleShadow_Init
	adds r0, r4, #0
	bl ParticleShadow_Show
	movs r0, #0x88
	lsls r0, r0, #1
	adds r4, r7, r0
	ldr r2, _080534D8 @ =0x000017EC
	adds r1, r6, r2
	adds r0, r4, #0
	movs r2, #1
	bl AuxSprite_Add
	movs r1, #7
	strh r1, [r4, #0x10]
	ldr r2, _080534DC @ =0x00000117
	adds r1, r7, r2
	mov r2, r8
	strb r2, [r1]
	movs r1, #0x96
	lsls r1, r1, #1
	adds r3, r7, r1
	ldr r1, [r5]
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r3]
	str r2, [r3, #4]
_080534CC:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080534D8: .4byte 0x000017EC
_080534DC: .4byte 0x00000117
