	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B5F0 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0807B5EA
	ldr r2, _0807B5F4 @ =0x00000285
	adds r1, r0, r2
	movs r0, #1
	strb r0, [r1]
_0807B5EA:
	pop {r0}
	bx r0
	.align 2, 0
_0807B5F0: .4byte 0x03002BE0
_0807B5F4: .4byte 0x00000285
