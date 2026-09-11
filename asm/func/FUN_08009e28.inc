	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _08009E36
	movs r0, #0
	strb r0, [r2, #7]
_08009E36:
	ldrh r0, [r2, #0xa]
	adds r1, r0, #1
	strh r1, [r2, #0xa]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1e
	bls _08009E50
	movs r0, #2
	movs r1, #0
	strb r0, [r2, #2]
	strh r1, [r2, #0xa]
	movs r0, #1
	strb r0, [r2, #7]
_08009E50:
	pop {r0}
	bx r0
