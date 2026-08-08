	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _082404EC @ =gSongTable
	lsls r1, r5, #3
	adds r4, r1, r0
	ldrh r0, [r4, #4]
	cmp r0, #0xc
	bne _082404E6
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	bl m4aSongNumStartOrContinue
	ldr r1, _082404F0 @ =gMPlayTable
	ldrh r0, [r4, #4]
	lsls r4, r0, #1
	adds r0, r4, r0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _082404F4 @ =0x0000FFFF
	movs r2, #0x80
	lsls r2, r2, #1
	bl m4aMPlayVolumeControl
	ldr r0, _082404F8 @ =0x03004820
	adds r4, r4, r0
	strh r5, [r4]
_082404E6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_082404EC: .4byte gSongTable
_082404F0: .4byte gMPlayTable
_082404F4: .4byte 0x0000FFFF
_082404F8: .4byte 0x03004820
