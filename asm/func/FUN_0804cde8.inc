	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0804cd1c
	cmp r0, #0
	beq _0804CDFE
	adds r0, r4, #0
	adds r0, #0x21
	ldrb r0, [r0]
	bl rfu_UNI_readySendData
_0804CDFE:
	movs r0, #1
	bl rfu_LMAN_REQ_sendData
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
