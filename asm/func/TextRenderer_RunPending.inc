	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	b _080498B4
_08049898:
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r0, r0, r5
	ldrb r1, [r0]
	lsls r1, r1, #2
	adds r0, r4, #0
	adds r0, #0xc4
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	bl Script_ExecById
	adds r5, #1
_080498B4:
	movs r1, #0xa6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r5, r0
	blo _08049898
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
