	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B5C8 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0807B5C2
	ldr r2, _0807B5CC @ =0x000003BA
	adds r1, r0, r2
	movs r0, #1
	strh r0, [r1]
_0807B5C2:
	pop {r0}
	bx r0
	.align 2, 0
_0807B5C8: .4byte 0x03002BE0
_0807B5CC: .4byte 0x000003BA
