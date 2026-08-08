	push {r4, r5, lr}
	adds r5, r1, #0
	adds r4, r0, #0
	movs r1, #0
	subs r2, #1
_08231946:
	cmp r1, r2
	bge _08231960
	adds r0, r1, r2
	asrs r3, r0, #1
	lsls r0, r3, #3
	adds r0, r0, r4
	ldr r0, [r0]
	cmp r0, r5
	bhs _0823195C
	adds r1, r3, #1
	b _08231946
_0823195C:
	adds r2, r3, #0
	b _08231946
_08231960:
	lsls r0, r1, #3
	adds r2, r0, r4
	ldr r0, [r2]
	cmp r0, r5
	beq _0823196E
	movs r0, #0
	b _08231970
_0823196E:
	adds r0, r2, #0
_08231970:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
