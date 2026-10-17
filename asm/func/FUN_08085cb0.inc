	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0xb0
	ldr r2, _08085CE8 @ =0x00000207
	adds r1, r1, r2
	bl Video_SetAuxSpritePltt
	adds r0, r4, #0
	adds r0, #0xbc
	adds r5, r4, #0
	adds r5, #0x20
	ldr r2, [r0]
	adds r1, r5, #0
	movs r3, #0xf
_08085CCC:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _08085CCC
	adds r0, r4, #0
	adds r0, #0xbc
	str r5, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08085CE8: .4byte 0x00000207
