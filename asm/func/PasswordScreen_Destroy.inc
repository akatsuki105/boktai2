	push {r4, r5, lr}
	ldr r1, _08013078 @ =0x0000044C
	adds r5, r0, r1
	movs r4, #2
_08013064:
	ldm r5!, {r0}
	bl FUN_0804a16c
	subs r4, #1
	cmp r4, #0
	bge _08013064
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08013078: .4byte 0x0000044C
