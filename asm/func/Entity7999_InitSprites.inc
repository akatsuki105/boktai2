	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r4, _081DA3EC @ =0x0000CB05
	ldr r1, _081DA3F0 @ =0x0000DCC1
	adds r0, r4, #0
	bl GetFile
	adds r1, r0, #0
	movs r2, #0x90
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x40
	adds r0, r5, r2
	bl OpenMainSpriteFile
	ldr r1, _081DA3F4 @ =0x00005D04
	adds r0, r4, #0
	bl GetFile
	adds r1, r0, #0
	movs r2, #0x91
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x24
	adds r0, r5, r2
	bl OpenMainSpriteFile
	movs r4, #0
_081DA3DE:
	cmp r4, #4
	bhi _081DA434
	lsls r0, r4, #2
	ldr r1, _081DA3F8 @ =_081DA3FC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081DA3EC: .4byte 0x0000CB05
_081DA3F0: .4byte 0x0000DCC1
_081DA3F4: .4byte 0x00005D04
_081DA3F8: .4byte _081DA3FC
_081DA3FC: @ jump table
	.4byte _081DA410 @ case 0
	.4byte _081DA418 @ case 1
	.4byte _081DA420 @ case 2
	.4byte _081DA428 @ case 3
	.4byte _081DA42C @ case 4
_081DA410:
	movs r2, #0x33
	movs r0, #0x80
	lsls r0, r0, #2
	b _081DA43A
_081DA418:
	movs r2, #0x34
	movs r0, #0x80
	lsls r0, r0, #2
	b _081DA43A
_081DA420:
	movs r2, #0x35
	movs r0, #0x80
	lsls r0, r0, #2
	b _081DA43A
_081DA428:
	movs r2, #0xb6
	b _081DA436
_081DA42C:
	movs r2, #0x15
	movs r0, #0x80
	lsls r0, r0, #2
	b _081DA43A
_081DA434:
	movs r2, #0
_081DA436:
	movs r0, #0x88
	lsls r0, r0, #2
_081DA43A:
	adds r3, r5, r0
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #5
	adds r0, #0x20
	adds r0, r5, r0
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	adds r1, r3, #0
	movs r3, #0x10
	bl MainSprite_Add
	adds r4, #1
	cmp r4, #4
	ble _081DA3DE
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
