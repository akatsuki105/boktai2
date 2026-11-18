	push {lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r1, [r1]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #1
	bls _081C70E2
	cmp r0, #4
	bne _081C70E8
_081C70E2:
	movs r2, #0xd9
	lsls r2, r2, #3
	b _081C70F6
_081C70E8:
	movs r2, #0xd9
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _081C70FE
	adds r2, #2
_081C70F6:
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _081C7102
_081C70FE:
	movs r0, #1
	b _081C7104
_081C7102:
	movs r0, #0
_081C7104:
	pop {r1}
	bx r1
