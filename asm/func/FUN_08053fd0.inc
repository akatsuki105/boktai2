	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _08054002
	movs r1, #0
	strb r1, [r4, #0xe]
	adds r2, r5, #0
	adds r2, #0x32
	movs r0, #1
	strb r0, [r2]
	str r1, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #4
	movs r3, #2
	bl BlackPantherElem_PlayAnim
	ldr r0, _08054030 @ =0x00000322
	bl PlaySound_082406e0
_08054002:
	adds r0, r4, #0
	adds r0, #0x7c
	bl SpriteHolder_IsAnimEnded
	cmp r0, #0
	beq _08054046
	ldr r1, [r5, #0x24]
	ldr r0, _08054034 @ =0x000003E7
	cmp r1, r0
	ble _08054038
	movs r0, #7
	movs r1, #0
	strb r0, [r4, #0xd]
	movs r2, #1
	strb r2, [r4, #0xe]
	str r1, [r4, #0x1c]
	adds r0, r5, #0
	adds r0, #0x30
	strb r1, [r0]
	adds r0, #0x16
	strh r2, [r0]
	b _0805404C
	.align 2, 0
_08054030: .4byte 0x00000322
_08054034: .4byte 0x000003E7
_08054038:
	movs r0, #3
	movs r1, #0
	strb r0, [r4, #0xd]
	movs r0, #1
	strb r0, [r4, #0xe]
	str r1, [r4, #0x1c]
	b _0805404C
_08054046:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
_0805404C:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
