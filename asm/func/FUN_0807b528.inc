	push {lr}
	bl FUN_0807afe8
	ldr r1, _0807B558 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0807B552
	ldr r1, _0807B55C @ =0x0000038E
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r1, _0807B560 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
_0807B552:
	pop {r0}
	bx r0
	.align 2, 0
_0807B558: .4byte 0x03002BE0
_0807B55C: .4byte 0x0000038E
_0807B560: .4byte 0x030046A0
