	push {r4, r5, lr}
	movs r1, #0xf8
	lsls r1, r1, #2
	adds r5, r0, r1
	movs r4, #1
_081DFF86:
	ldm r5!, {r0}
	bl TextPanel_Hide
	subs r4, #1
	cmp r4, #0
	bge _081DFF86
	pop {r4, r5}
	pop {r0}
	bx r0
