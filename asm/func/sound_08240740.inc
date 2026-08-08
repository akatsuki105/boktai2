	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0824075C @ =0x030044BC
	ldr r3, [r0]
	movs r0, #6
	ands r3, r0
	cmp r3, #0
	beq _08240760
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl m4aSongNumStop
	b _0824077E
	.align 2, 0
_0824075C: .4byte 0x030044BC
_08240760:
	ldr r2, _08240784 @ =0x03004820
	ldr r1, _08240788 @ =gSongTable
	lsls r0, r4, #3
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	cmp r4, r1
	bne _0824077E
	strh r3, [r0]
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl m4aSongNumStop
_0824077E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08240784: .4byte 0x03004820
_08240788: .4byte gSongTable
