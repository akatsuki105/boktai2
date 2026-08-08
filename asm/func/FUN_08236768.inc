	push {r4, r5, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r2, r0, #6
	cmp r2, #0
	bne _08236796
	ldrh r0, [r3, #0x1c]
	ldrh r3, [r3, #0x24]
	adds r0, r0, r3
	ldrh r1, [r5, #0x1c]
	adds r1, r1, r0
	ldrh r0, [r5, #0x24]
	subs r1, r1, r0
	strh r1, [r4]
	strh r2, [r4, #2]
	strh r2, [r4, #4]
	b _082367DE
_08236796:
	cmp r2, #1
	bne _082367AC
	movs r0, #0
	strh r0, [r4]
	strh r0, [r4, #2]
	ldrh r1, [r3, #0x20]
	ldrh r3, [r3, #0x28]
	adds r1, r1, r3
	ldrh r0, [r5, #0x20]
	adds r0, r0, r1
	b _082367D8
_082367AC:
	cmp r2, #2
	bne _082367C8
	ldrh r0, [r3, #0x24]
	ldrh r1, [r3, #0x1c]
	subs r0, r0, r1
	ldrh r1, [r5, #0x1c]
	subs r0, r0, r1
	ldrh r1, [r5, #0x24]
	subs r0, r0, r1
	movs r1, #0
	strh r0, [r4]
	strh r1, [r4, #2]
	strh r1, [r4, #4]
	b _082367DE
_082367C8:
	movs r0, #0
	strh r0, [r4]
	strh r0, [r4, #2]
	ldrh r0, [r3, #0x28]
	ldrh r1, [r3, #0x20]
	subs r0, r0, r1
	ldrh r1, [r5, #0x20]
	subs r0, r0, r1
_082367D8:
	ldrh r1, [r5, #0x28]
	subs r0, r0, r1
	strh r0, [r4, #4]
_082367DE:
	pop {r4, r5}
	pop {r0}
	bx r0
