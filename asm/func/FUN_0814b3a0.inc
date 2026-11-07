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
	bls _0814B3BA
	cmp r0, #4
	bne _0814B3C0
_0814B3BA:
	movs r2, #0xd9
	lsls r2, r2, #3
	b _0814B3CE
_0814B3C0:
	movs r2, #0xd9
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0814B3D6
	adds r2, #2
_0814B3CE:
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _0814B3DA
_0814B3D6:
	movs r0, #1
	b _0814B3DC
_0814B3DA:
	movs r0, #0
_0814B3DC:
	pop {r1}
	bx r1
