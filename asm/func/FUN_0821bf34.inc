	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r0, _0821BFB0 @ =0x00000BEC
	adds r5, r4, r0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	ldr r1, _0821BFB4 @ =0x00000BEE
	adds r1, r1, r4
	mov r8, r1
	ldrh r1, [r1]
	ldrh r3, [r5]
	subs r6, r1, r3
	ldr r2, _0821BFB8 @ =0x00000BDC
	adds r0, r4, r2
	ldr r0, [r0]
	muls r0, r6, r0
	ldr r7, _0821BFBC @ =0x00000BD8
	adds r2, r4, r7
	ldr r2, [r2]
	muls r2, r3, r2
	adds r0, r0, r2
	bl Div
	ldr r1, _0821BFC0 @ =0x00000BD4
	adds r7, r4, r1
	str r0, [r7]
	ldr r2, _0821BFC4 @ =0x00000BE8
	adds r0, r4, r2
	ldr r0, [r0]
	muls r0, r6, r0
	subs r2, #4
	adds r1, r4, r2
	ldrh r2, [r5]
	ldr r1, [r1]
	muls r1, r2, r1
	adds r0, r0, r1
	mov r2, r8
	ldrh r1, [r2]
	bl Div
	movs r1, #0xbe
	lsls r1, r1, #4
	adds r4, r4, r1
	str r0, [r4]
	ldr r0, [r7]
	cmp r0, #0
	bge _0821BFA0
	movs r2, #0x80
	lsls r2, r2, #9
	adds r0, r0, r2
	str r0, [r7]
_0821BFA0:
	ldrh r0, [r7]
	str r0, [r7]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0821BFB0: .4byte 0x00000BEC
_0821BFB4: .4byte 0x00000BEE
_0821BFB8: .4byte 0x00000BDC
_0821BFBC: .4byte 0x00000BD8
_0821BFC0: .4byte 0x00000BD4
_0821BFC4: .4byte 0x00000BE8
