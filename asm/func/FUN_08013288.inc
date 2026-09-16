	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	adds r6, r4, #0
	bl FUN_08236524
	ldrh r1, [r5, #0x3e]
	cmp r1, #0
	beq _080132E8
	ldrb r0, [r4, #0x1a]
	cmp r0, #0
	bne _080132AE
	movs r0, #0xa
	strb r0, [r4, #0x1e]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080132E4
_080132AE:
	ldrh r0, [r4, #0x1c]
	subs r0, r0, r1
	strh r0, [r4, #0x1c]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _080132CC
	movs r0, #1
	strb r0, [r4, #0x1b]
	movs r0, #0
	str r0, [r4, #0x20]
	movs r0, #0xa5
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080132E4
_080132CC:
	movs r0, #0xa
	strb r0, [r6, #0x1e]
	adds r0, r6, #0
	adds r0, #0x90
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetActorSpritePltt
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080132E4:
	movs r0, #0
	strh r0, [r5, #0x3e]
_080132E8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
