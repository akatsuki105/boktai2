	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B3DC @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0807B3D6
	bl FUN_08063220
_0807B3D6:
	pop {r0}
	bx r0
	.align 2, 0
_0807B3DC: .4byte 0x03002BE0
