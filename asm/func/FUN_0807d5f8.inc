	push {r4, lr}
	bl FUN_0807afe8
	ldr r1, _0807D624 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807D61C
	bl FUN_0807d164
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_0807bd44
	adds r0, r4, #0
	bl FUN_08072640
_0807D61C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807D624: .4byte 0x03002BE0
