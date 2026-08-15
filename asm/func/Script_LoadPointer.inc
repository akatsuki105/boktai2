	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	asrs r0, r5, #0x18
	movs r1, #0xf
	ands r0, r1
	subs r0, #1
	cmp r0, #8
	bhi _08231E4E
	lsls r0, r0, #2
	ldr r1, _08231DCC @ =_08231DD0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08231DCC: .4byte _08231DD0
_08231DD0: @ jump table
	.4byte _08231E1E @ case 0
	.4byte _08231E28 @ case 1
	.4byte _08231E28 @ case 2
	.4byte _08231E2E @ case 3
	.4byte _08231E4E @ case 4
	.4byte _08231E1E @ case 5
	.4byte _08231E4E @ case 6
	.4byte _08231E10 @ case 7
	.4byte _08231DF4 @ case 8
_08231DF4:
	lsls r0, r2, #2
	adds r4, r4, r0
	ldrb r1, [r4, #3]
	lsls r1, r1, #0x18
	ldrb r0, [r4, #2]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r4, #1]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r4]
	orrs r1, r0
	str r1, [r3]
	b _08231E4E
_08231E10:
	lsls r0, r2, #2
	adds r4, r4, r0
	ldrb r0, [r4, #1]
	lsls r0, r0, #8
	ldrb r1, [r4]
	orrs r0, r1
	b _08231E4C
_08231E1E:
	lsls r0, r2, #1
	adds r0, r4, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	b _08231E4C
_08231E28:
	adds r4, r4, r2
	ldrb r0, [r4]
	b _08231E4C
_08231E2E:
	asrs r0, r5, #0x10
	movs r1, #0xf
	ands r0, r1
	adds r2, r2, r0
	asrs r1, r2, #3
	adds r1, r4, r1
	movs r0, #7
	ands r0, r2
	movs r2, #1
	lsls r2, r0
	ldrb r1, [r1]
	ands r1, r2
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
_08231E4C:
	str r0, [r3]
_08231E4E:
	pop {r4, r5}
	pop {r0}
	bx r0
