	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, [r6, #0x1c]
	cmp r4, #0
	beq _08044004
_08043FDE:
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r5, [r0]
	subs r1, #0xc
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _08043FF8
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
_08043FF8:
	adds r0, r4, #0
	bl FUN_0804114c
	adds r4, r5, #0
	cmp r4, #0
	bne _08043FDE
_08044004:
	ldr r1, _08044010 @ =0x03002B50
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08044010: .4byte 0x03002B50
