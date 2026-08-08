	push {lr}
	adds r3, r0, #0
	ldr r0, _0824070C @ =0x030044BC
	ldr r0, [r0]
	movs r1, #6
	ands r0, r1
	cmp r0, #0
	bne _08240700
	ldr r2, _08240710 @ =0x03004820
	ldr r1, _08240714 @ =gSongTable
	lsls r0, r3, #3
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	lsls r0, r0, #1
	adds r0, r0, r2
	strh r3, [r0]
_08240700:
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x10
	bl m4aSongNumStart
	pop {r0}
	bx r0
	.align 2, 0
_0824070C: .4byte 0x030044BC
_08240710: .4byte 0x03004820
_08240714: .4byte gSongTable
