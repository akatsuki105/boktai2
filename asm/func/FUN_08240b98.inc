	push {lr}
	adds r3, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _08240BC0 @ =0x03001700
	ldr r2, [r0]
	cmp r2, #0
	beq _08240BC4
	lsls r0, r1, #0x18
	asrs r0, r0, #0x14
	adds r0, r2, r0
	ldrh r1, [r0, #0x18]
	movs r2, #0
	strh r1, [r3]
	strh r2, [r3, #2]
	ldrh r1, [r0, #0x1c]
	strh r1, [r3, #4]
	ldrh r0, [r0, #0x26]
	b _08240BC6
	.align 2, 0
_08240BC0: .4byte 0x03001700
_08240BC4:
	movs r0, #0
_08240BC6:
	pop {r1}
	bx r1
	.align 2, 0
