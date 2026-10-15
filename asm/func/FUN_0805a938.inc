	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805A95A
	movs r2, #0
	strb r2, [r4]
	adds r0, r4, #0
	adds r0, #0xe8
	ldr r1, [r5, #0x20]
	str r2, [sp]
	movs r2, #1
	movs r3, #0
	bl AuxAnim_SetAnim
_0805A95A:
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _0805A978
	movs r0, #1
	movs r2, #0
	strb r0, [r4, #1]
	strb r0, [r4]
	strh r2, [r4, #6]
	adds r0, r4, #0
	adds r0, #0xe8
	ldr r1, [r5, #0x20]
	str r2, [sp]
	movs r3, #0
	bl AuxAnim_SetAnim
_0805A978:
	ldrh r0, [r4, #6]
	adds r0, #1
	strh r0, [r4, #6]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
