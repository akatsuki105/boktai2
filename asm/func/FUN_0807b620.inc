	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B63C @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0807B644
	ldr r1, _0807B640 @ =0x00000A75
	adds r0, r0, r1
	ldrb r0, [r0]
	b _0807B646
	.align 2, 0
_0807B63C: .4byte 0x03002BE0
_0807B640: .4byte 0x00000A75
_0807B644:
	movs r0, #0
_0807B646:
	pop {r1}
	bx r1
	.align 2, 0
