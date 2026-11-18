	push {lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	movs r2, #3
	ldr r3, _0819EE3C @ =0x00000894
	adds r0, r0, r3
_0819EE2C:
	str r1, [r0]
	subs r0, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0819EE2C
	pop {r0}
	bx r0
	.align 2, 0
_0819EE3C: .4byte 0x00000894
