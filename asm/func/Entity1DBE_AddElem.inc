	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	mov r8, r2
	ldr r7, [sp, #0x20]
	ldr r5, [sp, #0x24]
	ldr r6, [sp, #0x28]
	ldrh r2, [r4, #0x18]
	movs r0, #0xf4
	muls r0, r2, r0
	adds r0, #0x1c
	adds r4, r4, r0
	str r5, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	mov r2, r8
	bl Entity1DBEElem_InitParams
	adds r0, r4, #0
	mov r1, r8
	adds r2, r7, #0
	bl Entity1DBEElem_InitSprite
	adds r0, r4, #0
	bl Entity1DBEElem_InitHitbox
	adds r0, r4, #0
	bl Entity1DBEElem_InitState
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
