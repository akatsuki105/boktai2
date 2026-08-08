	push {lr}
	adds r3, r0, #0
	ldr r1, _0824098C @ =gSongTable
	lsls r0, r3, #3
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	ldr r1, _08240990 @ =gMPlayTable
	lsls r2, r0, #1
	adds r0, r2, r0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #4]
	cmp r0, #0
	blt _08240998
	ldr r0, _08240994 @ =0x03004820
	adds r0, r2, r0
	ldrh r0, [r0]
	cmp r0, r3
	bne _08240998
	movs r0, #1
	b _0824099A
	.align 2, 0
_0824098C: .4byte gSongTable
_08240990: .4byte gMPlayTable
_08240994: .4byte 0x03004820
_08240998:
	movs r0, #0
_0824099A:
	pop {r1}
	bx r1
	.align 2, 0
