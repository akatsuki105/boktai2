	push {lr}
	adds r3, r0, #0
	ldr r0, _0824065C @ =0x03004820
	ldrh r0, [r0, #0x14]
	cmp r0, #0
	beq _08240658
	ldr r1, _08240660 @ =gSongTable
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r1, [r0, #4]
	ldr r2, _08240664 @ =gMPlayTable
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r1, r3, #0x10
	lsrs r1, r1, #0x10
	bl m4aMPlayTempoControl
_08240658:
	pop {r0}
	bx r0
	.align 2, 0
_0824065C: .4byte 0x03004820
_08240660: .4byte gSongTable
_08240664: .4byte gMPlayTable
