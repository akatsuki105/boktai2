	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	adds r7, r2, #0
	mov ip, r3
	ldr r2, [r0, #8]
	ldrh r3, [r2]
	ldr r1, _08235084 @ =0xFFFF0000
	adds r0, r1, #0
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r3
	ldrh r0, [r2, #2]
	ands r1, r5
	adds r5, r1, #0
	orrs r5, r0
	adds r2, r5, #0
	movs r0, #0
	ldrsh r1, [r6, r0]
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	subs r0, r1, r0
	cmp r0, #0
	bge _08235068
	rsbs r0, r0, #0
_08235068:
	cmp r0, r7
	bhi _08235088
	movs r0, #4
	ldrsh r1, [r6, r0]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	subs r0, r1, r0
	cmp r0, #0
	bge _0823507C
	rsbs r0, r0, #0
_0823507C:
	cmp r0, ip
	bhi _08235088
	movs r0, #0
	b _0823508A
	.align 2, 0
_08235084: .4byte 0xFFFF0000
_08235088:
	movs r0, #1
_0823508A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
