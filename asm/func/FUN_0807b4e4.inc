	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B514 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0807B510
	ldr r1, _0807B518 @ =0x0000038E
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r1, _0807B51C @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	bgt _0807B520
_0807B510:
	movs r0, #0
	b _0807B522
	.align 2, 0
_0807B514: .4byte 0x03002BE0
_0807B518: .4byte 0x0000038E
_0807B51C: .4byte 0x030046A0
_0807B520:
	movs r0, #1
_0807B522:
	pop {r1}
	bx r1
	.align 2, 0
