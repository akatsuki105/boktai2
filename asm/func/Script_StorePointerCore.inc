	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	asrs r0, r5, #0x18
	movs r1, #0xf
	ands r0, r1
	subs r0, #1
	cmp r0, #8
	bhi _08231F80
	lsls r0, r0, #2
	ldr r1, _08231F0C @ =_08231F10
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08231F0C: .4byte _08231F10
_08231F10: @ jump table
	.4byte _08231F4C @ case 0
	.4byte _08231F54 @ case 1
	.4byte _08231F54 @ case 2
	.4byte _08231F5A @ case 3
	.4byte _08231F80 @ case 4
	.4byte _08231F4C @ case 5
	.4byte _08231F80 @ case 6
	.4byte _08231F3C @ case 7
	.4byte _08231F34 @ case 8
_08231F34:
	lsls r0, r2, #2
	adds r0, r4, r0
	str r3, [r0]
	b _08231F80
_08231F3C:
	lsls r0, r2, #2
	adds r0, r4, r0
	asrs r1, r3, #0x10
	strb r1, [r0, #2]
	asrs r1, r3, #8
	strb r1, [r0, #1]
	strb r3, [r0]
	b _08231F80
_08231F4C:
	lsls r0, r2, #1
	adds r0, r4, r0
	strh r3, [r0]
	b _08231F80
_08231F54:
	adds r0, r4, r2
	strb r3, [r0]
	b _08231F80
_08231F5A:
	asrs r0, r5, #0x10
	movs r1, #0xf
	ands r0, r1
	adds r2, r2, r0
	asrs r0, r2, #3
	adds r4, r4, r0
	movs r0, #7
	ands r0, r2
	movs r1, #1
	lsls r1, r0
	cmp r3, #0
	beq _08231F7A
	ldrb r0, [r4]
	orrs r1, r0
	strb r1, [r4]
	b _08231F80
_08231F7A:
	ldrb r0, [r4]
	bics r0, r1
	strb r0, [r4]
_08231F80:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
