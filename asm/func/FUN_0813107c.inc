	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x44]
	adds r3, r0, #0
	adds r3, #0x48
	ldrh r0, [r3, #0xe]
	cmp r0, #0
	beq _08131090
	movs r0, #0
	b _081310AE
_08131090:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _081310B4 @ =0x085AD70C
	ldrh r1, [r3, #8]
	movs r0, #1
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
_081310AE:
	pop {r1}
	bx r1
	.align 2, 0
_081310B4: .4byte 0x085AD70C
