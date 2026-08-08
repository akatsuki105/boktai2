	push {r4, r5, lr}
	adds r2, r0, #0
	ldr r5, _0824059C @ =0x03004820
	ldrh r0, [r5, #0x18]
	cmp r0, #0
	beq _08240596
	ldr r1, _082405A0 @ =gSongTable
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	ldr r1, _082405A4 @ =gMPlayTable
	lsls r4, r0, #1
	adds r0, r4, r0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	lsls r1, r2, #0x10
	lsrs r1, r1, #0x10
	bl m4aMPlayFadeOutTemporarily
	adds r4, r4, r5
	movs r0, #0
	strh r0, [r4]
_08240596:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0824059C: .4byte 0x03004820
_082405A0: .4byte gSongTable
_082405A4: .4byte gMPlayTable
