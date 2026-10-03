	push {lr}
	movs r2, #0
	ldr r3, _0804B354 @ =0x03005800
	ldr r0, [r3]
	ldrb r0, [r0, #2]
	movs r1, #1
	b _0804B368
	.align 2, 0
_0804B354: .4byte 0x03005800
_0804B358:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bhi _0804B36E
	ldr r0, [r3]
	ldrb r0, [r0, #2]
	asrs r0, r2
_0804B368:
	ands r0, r1
	cmp r0, #0
	beq _0804B358
_0804B36E:
	movs r0, #0x80
	lsls r0, r0, #0x11
	lsls r0, r2
	lsrs r0, r0, #0x18
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
	bl rfu_clearAllSlot
	movs r0, #0
	bl rfu_setREQCallback
	bl rfu_REQ_stopMode
	bl rfu_waitREQComplete
	pop {r0}
	bx r0
