	push {r4, r5, lr}
	adds r2, r0, #0
	ldr r4, _08002778 @ =0x0300445C
	ldrh r1, [r2, #0x20]
	lsls r1, r1, #6
	ldrh r0, [r2, #0x22]
	asrs r1, r0
	movs r0, #0x40
	subs r0, r0, r1
	str r0, [r4]
	ldrh r0, [r2, #0x20]
	adds r0, #1
	movs r3, #0
	strh r0, [r2, #0x20]
	ldrh r1, [r2, #0x20]
	movs r0, #1
	ldrh r5, [r2, #0x22]
	lsls r0, r5
	cmp r1, r0
	blt _08002780
	str r3, [r4]
	ldrh r0, [r2, #0x1e]
	cmp r0, #2
	bne _0800277C
	strh r3, [r2, #0x1e]
	b _08002780
	.align 2, 0
_08002778: .4byte 0x0300445C
_0800277C:
	movs r0, #5
	strh r0, [r2, #0x1e]
_08002780:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
