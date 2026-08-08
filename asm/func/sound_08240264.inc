	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08240280 @ =gSongTable
	lsls r1, r5, #3
	adds r1, r1, r0
	ldrh r0, [r1, #4]
	cmp r0, #0xa
	bne _08240284
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	bl m4aSongNumStartOrContinue
	b _0824028C
	.align 2, 0
_08240280: .4byte gSongTable
_08240284:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	bl m4aSongNumStart
_0824028C:
	ldr r2, _082402B8 @ =gMPlayTable
	ldr r1, _082402BC @ =gSongTable
	lsls r0, r5, #3
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	lsls r4, r0, #1
	adds r0, r4, r0
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r1, _082402C0 @ =0x0000FFFF
	movs r2, #0x80
	lsls r2, r2, #1
	bl m4aMPlayVolumeControl
	ldr r0, _082402C4 @ =0x03004820
	adds r4, r4, r0
	strh r5, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_082402B8: .4byte gMPlayTable
_082402BC: .4byte gSongTable
_082402C0: .4byte 0x0000FFFF
_082402C4: .4byte 0x03004820
