	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x28
	movs r4, #7
_0820D226:
	ldm r5!, {r0}
	bl TextPanel_Hide
	subs r4, #1
	cmp r4, #0
	bge _0820D226
	ldr r0, _0820D24C @ =0x0000110E
	adds r2, r6, r0
	ldrh r1, [r2]
	movs r0, #1
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0
	bl ClearBGTilemapBuffer
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0820D24C: .4byte 0x0000110E
