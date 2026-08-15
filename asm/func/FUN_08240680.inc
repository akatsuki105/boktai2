	push {r4, lr}
	movs r0, #0x76
	bl prepare_08231510
	cmp r0, #0
	beq _082406CE
	bl Script_GetValue
	adds r4, r0, #0
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _082406A4
	bl Script_GetValue
	adds r3, r0, #0
	b _082406A6
_082406A4:
	movs r3, #0xff
_082406A6:
	ldr r0, _082406D4 @ =0x03004820
	ldrh r0, [r0, #0x14]
	cmp r0, #0
	beq _082406CE
	ldr r1, _082406D8 @ =gSongTable
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r1, [r0, #4]
	ldr r2, _082406DC @ =gMPlayTable
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r1, r3, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	bl m4aMPlayVolumeControl
_082406CE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_082406D4: .4byte 0x03004820
_082406D8: .4byte gSongTable
_082406DC: .4byte gMPlayTable
