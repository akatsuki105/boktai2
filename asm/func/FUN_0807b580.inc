	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B5A0 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0807B59A
	ldr r2, _0807B5A4 @ =0x0000043A
	adds r1, r0, r2
	movs r0, #1
	strh r0, [r1]
_0807B59A:
	pop {r0}
	bx r0
	.align 2, 0
_0807B5A0: .4byte 0x03002BE0
_0807B5A4: .4byte 0x0000043A
