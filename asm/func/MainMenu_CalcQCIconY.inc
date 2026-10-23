	push {r4, r5, lr}
	adds r0, r1, #0
	adds r5, r3, #0
	ldr r4, [sp, #0xc]
	adds r0, r5, r0
	subs r0, r0, r2
	adds r1, r5, #0
	bl Mod
	lsls r2, r4, #1
	adds r2, r2, r4
	movs r3, #0x88
	subs r2, r3, r2
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	subs r2, r2, r1
	subs r1, r5, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	subs r3, r3, r0
	cmp r2, r3
	bge _0808D4D4
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r2, r2, r0
_0808D4D4:
	adds r0, r2, #0
	pop {r4, r5}
	pop {r1}
	bx r1
