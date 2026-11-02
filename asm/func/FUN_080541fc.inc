	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _0805421E
	movs r0, #0
	strb r0, [r4, #0xe]
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #2
	bl BlackPantherElem_PlayAnim
_0805421E:
	ldr r0, [r4, #0x1c]
	cmp r0, #0x20
	bne _08054282
	movs r5, #0
	ldr r0, [r4]
	subs r0, #2
	cmp r0, #4
	bhi _0805426E
	lsls r0, r0, #2
	ldr r1, _08054238 @ =_0805423C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08054238: .4byte _0805423C
_0805423C: @ jump table
	.4byte _08054250 @ case 0
	.4byte _08054260 @ case 1
	.4byte _08054264 @ case 2
	.4byte _08054268 @ case 3
	.4byte _0805426C @ case 4
_08054250:
	movs r5, #0xb
	ldr r0, _0805425C @ =0x000002E6
	bl PlaySound_082406e0
	b _0805426E
	.align 2, 0
_0805425C: .4byte 0x000002E6
_08054260:
	movs r5, #0xc
	b _0805426E
_08054264:
	movs r5, #0xd
	b _0805426E
_08054268:
	movs r5, #0xe
	b _0805426E
_0805426C:
	movs r5, #0
_0805426E:
	movs r0, #0
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #2
	bl BlackPantherElem_PlayAnim
_08054282:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
