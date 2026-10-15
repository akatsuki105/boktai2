	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	adds r4, r6, #0
	adds r4, #8
	adds r1, r5, #0
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0x11
	bl AuxSprite_Add
	ldr r1, _0801ABF0 @ =0x085AA988
	movs r0, #3
	mov r2, r8
	ands r0, r2
	adds r0, r0, r1
	ldrb r0, [r0]
	strh r0, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #7]
	adds r0, r5, #0
	adds r1, r6, #0
	bl Entity78C9Elem_Respawn
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801ABF0: .4byte 0x085AA988
