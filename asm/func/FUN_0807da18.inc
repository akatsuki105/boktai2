	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807DA4C @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807DA44
	bl FUN_0807d164
	adds r4, r0, #0
	bl FUN_0807d180
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0807c5f0
	adds r0, r5, #0
	bl FUN_08072640
_0807DA44:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807DA4C: .4byte 0x03002BE0
