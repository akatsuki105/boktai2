	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08240540 @ =0x03004820
	ldrh r5, [r0, #0x18]
	cmp r5, #0
	beq _0824053A
	ldr r0, _08240544 @ =gSongTable
	lsls r1, r5, #3
	adds r1, r1, r0
	ldrh r0, [r1, #4]
	cmp r0, #0xc
	bne _0824053A
	ldr r0, _08240548 @ =gMPlayTable
	adds r0, #0x90
	ldr r4, [r0]
	adds r0, r4, #0
	bl m4aMPlayImmInit
	ldr r1, _0824054C @ =0x0000FFFF
	adds r0, r4, #0
	movs r2, #1
	bl m4aMPlayVolumeControl
	adds r0, r5, #0
	bl m4aSongNumStop
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl m4aMPlayFadeIn
_0824053A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08240540: .4byte 0x03004820
_08240544: .4byte gSongTable
_08240548: .4byte gMPlayTable
_0824054C: .4byte 0x0000FFFF
