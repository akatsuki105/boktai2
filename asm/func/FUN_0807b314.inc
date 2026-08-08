	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B340 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _0807B33A
	ldr r1, _0807B344 @ =0x00000442
	adds r0, r2, r1
	movs r1, #0
	strh r1, [r0]
	ldr r3, _0807B348 @ =0x00000446
	adds r0, r2, r3
	strh r1, [r0]
	subs r3, #2
	adds r0, r2, r3
	strh r1, [r0]
_0807B33A:
	pop {r0}
	bx r0
	.align 2, 0
_0807B340: .4byte 0x03002BE0
_0807B344: .4byte 0x00000442
_0807B348: .4byte 0x00000446
