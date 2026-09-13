	push {r4, r5, lr}
	adds r3, r0, #0
	movs r1, #0
	ldr r5, _0801521C @ =0x0300005C
	movs r4, #0
_080151EA:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	adds r0, r3, r0
	strb r4, [r0]
	adds r2, r1, #1
	movs r1, #5
	adds r0, #0x31
_08015200:
	strb r4, [r0]
	subs r0, #1
	subs r1, #1
	cmp r1, #0
	bge _08015200
	adds r1, r2, #0
	cmp r1, #3
	ble _080151EA
	movs r0, #0
	str r0, [r3, #0x18]
	str r3, [r5]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801521C: .4byte 0x0300005C
