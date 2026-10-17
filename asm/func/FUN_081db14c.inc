	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _081DB17C @ =0x0000CB05
	ldr r1, _081DB180 @ =0x0000DCC1
	bl GetFile
	adds r1, r0, #0
	movs r2, #0xb8
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	subs r2, #0x20
	adds r0, r4, r2
	bl OpenMainSpriteFile
	movs r5, #0
_081DB16E:
	cmp r5, #6
	bhi _081DB1B4
	lsls r0, r5, #2
	ldr r1, _081DB184 @ =_081DB188
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081DB17C: .4byte 0x0000CB05
_081DB180: .4byte 0x0000DCC1
_081DB184: .4byte _081DB188
_081DB188: @ jump table
	.4byte _081DB1A4 @ case 0
	.4byte _081DB1A8 @ case 1
	.4byte _081DB1AC @ case 2
	.4byte _081DB1B4 @ case 3
	.4byte _081DB1B4 @ case 4
	.4byte _081DB1B4 @ case 5
	.4byte _081DB1B0 @ case 6
_081DB1A4:
	movs r2, #0x33
	b _081DB1B6
_081DB1A8:
	movs r2, #0x34
	b _081DB1B6
_081DB1AC:
	movs r2, #0x35
	b _081DB1B6
_081DB1B0:
	movs r2, #0x15
	b _081DB1B6
_081DB1B4:
	movs r2, #0
_081DB1B6:
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r3, r4, r0
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #5
	adds r0, #0x20
	adds r0, r4, r0
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	adds r1, r3, #0
	movs r3, #0x10
	bl MainSprite_Add
	adds r5, #1
	cmp r5, #6
	ble _081DB16E
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
