	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r6, _08240488 @ =0x03004820
	ldrh r0, [r6, #0x14]
	cmp r0, #0
	beq _08240480
	ldr r1, _0824048C @ =gSongTable
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	ldr r1, _08240490 @ =gMPlayTable
	lsls r5, r0, #1
	adds r0, r5, r0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r4, #0
	bl m4aMPlayImmInit
	ldr r1, _08240494 @ =0x0000FFFF
	adds r0, r4, #0
	movs r2, #0xff
	bl m4aMPlayVolumeControl
	lsls r1, r7, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl m4aMPlayFadeOut
	adds r5, r5, r6
	movs r0, #0
	strh r0, [r5]
_08240480:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08240488: .4byte 0x03004820
_0824048C: .4byte gSongTable
_08240490: .4byte gMPlayTable
_08240494: .4byte 0x0000FFFF
