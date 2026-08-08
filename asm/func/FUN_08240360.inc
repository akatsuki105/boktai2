	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _082403A8 @ =0x03004820
	ldrh r0, [r1, #0x14]
	cmp r0, #0
	beq _082403A2
	adds r5, r0, #0
	ldr r1, _082403AC @ =gSongTable
	lsls r0, r5, #3
	adds r0, r0, r1
	ldrh r1, [r0, #4]
	ldr r2, _082403B0 @ =gMPlayTable
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r4, [r0]
	adds r0, r4, #0
	bl m4aMPlayImmInit
	ldr r1, _082403B4 @ =0x0000FFFF
	adds r0, r4, #0
	movs r2, #1
	bl m4aMPlayVolumeControl
	adds r0, r5, #0
	bl m4aSongNumStop
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl m4aMPlayFadeIn
_082403A2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_082403A8: .4byte 0x03004820
_082403AC: .4byte gSongTable
_082403B0: .4byte gMPlayTable
_082403B4: .4byte 0x0000FFFF
