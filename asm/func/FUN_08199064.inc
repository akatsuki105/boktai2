	push {lr}
	adds r2, r0, #0
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _0819908A
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r1, _08199090 @ =FUN_08199094
	str r1, [r0]
	movs r0, #0xb5
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0819908A:
	pop {r0}
	bx r0
	.align 2, 0
_08199090: .4byte FUN_08199094
