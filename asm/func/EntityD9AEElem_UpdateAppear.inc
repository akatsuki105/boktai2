	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _080042DA
	movs r0, #0
	strb r0, [r4, #0x11]
	adds r0, r4, #0
	adds r0, #0x20
	movs r1, #3
	strb r1, [r0]
	adds r0, #0x6c
	strh r1, [r0, #0x10]
	movs r0, #0x9b
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080042DA:
	adds r3, r4, #0
	adds r3, #0x20
	ldrb r2, [r3]
	cmp r2, #0
	beq _08004306
	ldrh r0, [r4, #2]
	adds r1, r0, #1
	strh r1, [r4, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _08004318
	movs r0, #0
	strh r0, [r4, #2]
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
	ldrb r1, [r3]
	adds r0, r4, #0
	adds r0, #0x8c
	strh r1, [r0, #0x10]
	b _08004318
_08004306:
	ldr r0, _08004320 @ =EntityD9AEElem_UpdateIdle
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r1, r4, r3
	str r0, [r1]
	strh r2, [r4, #2]
	movs r0, #1
	strb r0, [r4, #0x11]
	strh r2, [r4, #4]
_08004318:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08004320: .4byte EntityD9AEElem_UpdateIdle
