	push {r4, lr}
	str r1, [r0, #0x5c]
	movs r3, #0
	str r3, [r0, #0x60]
	movs r2, #0x85
	lsls r2, r2, #3
	adds r4, r0, r2
	ldr r2, _08213670 @ =0x085AFA20
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	str r1, [r4]
	movs r2, #1
	ldr r1, [r0, #0x44]
	orrs r1, r2
	str r3, [r0, #0x64]
	str r3, [r0, #0x68]
	movs r2, #2
	orrs r1, r2
	str r1, [r0, #0x44]
	ldr r0, _08213674 @ =0x03004040
	str r3, [r0]
	ldr r0, _08213678 @ =0x0300445C
	str r3, [r0]
	ldr r2, _0821367C @ =0x03004454
	ldrh r0, [r2]
	movs r1, #3
	orrs r0, r1
	strh r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08213670: .4byte 0x085AFA20
_08213674: .4byte 0x03004040
_08213678: .4byte 0x0300445C
_0821367C: .4byte 0x03004454
