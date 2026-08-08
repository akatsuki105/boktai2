	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807DACC @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807DAC4
	bl FUN_0807d180
	adds r1, r0, #0
	adds r0, r5, #0
	bl FUN_0807cc84
	adds r4, r0, #0
	adds r0, r5, #0
	bl FUN_08072640
	cmp r4, #0
	bne _0807DAC4
	adds r0, r5, #0
	bl FUN_08072650
_0807DAC4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807DACC: .4byte 0x03002BE0
