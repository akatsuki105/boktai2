	push {r4, lr}
	adds r1, r0, #0
	ldr r0, _0807E3AC @ =0x000002EB
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0807E3A6
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r0, r1, r2
	bl FUN_08236400
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
_0807E3A6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807E3AC: .4byte 0x000002EB
