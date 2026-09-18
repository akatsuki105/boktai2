	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r5, [r0]
	cmp r5, #0
	ble _0808458E
	adds r0, r4, #0
	movs r1, #8
	bl FUN_08080ec8
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0808458E
	subs r5, #1
	cmp r5, #0
	beq _08084586
	ldr r1, _08084594 @ =0x00000476
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08084586
	asrs r0, r5, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08084586
	adds r0, r4, #0
	movs r1, #5
	bl FUN_08080ec8
_08084586:
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
_0808458E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08084594: .4byte 0x00000476
