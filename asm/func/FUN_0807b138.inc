	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B150 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0807B154
	bl FUN_0807a9d0
	b _0807B156
	.align 2, 0
_0807B150: .4byte 0x03002BE0
_0807B154:
	movs r0, #0
_0807B156:
	pop {r1}
	bx r1
	.align 2, 0
