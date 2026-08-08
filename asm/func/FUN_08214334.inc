	push {r4, lr}
	sub sp, #4
	adds r2, r0, #0
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r3, r2, r0
	movs r4, #5
	ldr r0, [r3, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #8]
	ldr r0, [r2, #0x5c]
	cmp r0, #4
	bhi _082143A6
	lsls r0, r0, #2
	ldr r1, _0821435C @ =_08214360
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0821435C: .4byte _08214360
_08214360: @ jump table
	.4byte _08214374 @ case 0
	.4byte _0821437C @ case 1
	.4byte _08214384 @ case 2
	.4byte _08214390 @ case 3
	.4byte _0821439C @ case 4
_08214374:
	movs r4, #5
	movs r0, #0
	strh r0, [r3, #0x20]
	b _082143A4
_0821437C:
	movs r4, #6
	movs r0, #0
	strh r0, [r3, #0x20]
	b _082143A4
_08214384:
	movs r4, #6
	movs r1, #0
	movs r0, #0x30
	strh r0, [r3, #0x20]
	strh r1, [r3, #0x22]
	b _082143A6
_08214390:
	movs r4, #6
	ldr r0, _08214398 @ =0x0000FFE0
	b _082143A0
	.align 2, 0
_08214398: .4byte 0x0000FFE0
_0821439C:
	movs r4, #6
	movs r0, #0x10
_082143A0:
	strh r0, [r3, #0x20]
	movs r0, #0x20
_082143A4:
	strh r0, [r3, #0x22]
_082143A6:
	adds r1, r2, #0
	adds r1, #0x18
	movs r0, #0
	str r0, [sp]
	adds r0, r3, #0
	adds r2, r4, #0
	movs r3, #1
	bl FUN_082370cc
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
