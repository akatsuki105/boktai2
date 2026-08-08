	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B668 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0807B662
	bl FUN_0807e854
_0807B662:
	pop {r0}
	bx r0
	.align 2, 0
_0807B668: .4byte 0x03002BE0
