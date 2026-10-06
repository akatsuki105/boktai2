	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	bl Crossover_GetMappingBuf
	adds r2, r0, #0
	movs r1, #0
_0804E682:
	lsls r0, r1, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, r4
	beq _0804E694
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	b _0804E682
_0804E694:
	adds r0, r1, #0
	pop {r4}
	pop {r1}
	bx r1
