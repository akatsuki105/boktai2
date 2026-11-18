	push {r4, lr}
	adds r4, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0819EE6C @ =0x00000774
	adds r3, r0, r1
	subs r1, #6
	adds r0, r0, r1
	movs r1, #3
_0819EE56:
	strh r2, [r0]
	str r4, [r3]
	adds r3, #0x60
	adds r0, #0x60
	subs r1, #1
	cmp r1, #0
	bge _0819EE56
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0819EE6C: .4byte 0x00000774
