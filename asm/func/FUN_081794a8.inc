	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r4, [r1]
	adds r2, #0x8a
	adds r1, r0, r2
	ldr r0, _081794D8 @ =0x00000FB8
	adds r2, r4, r0
	movs r3, #5
_081794BC:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _081794BC
	ldr r2, _081794DC @ =0x00000FB4
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081794D8: .4byte 0x00000FB8
_081794DC: .4byte 0x00000FB4
