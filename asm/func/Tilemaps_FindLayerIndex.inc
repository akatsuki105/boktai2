	push {r4, lr}
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldr r2, [r0, #0xc]
	movs r3, #0
	ldrh r0, [r0, #4]
	cmp r3, r0
	bge _08000CA8
	adds r1, r0, #0
_08000C96:
	ldrh r0, [r2, #4]
	cmp r0, r4
	bne _08000CA0
	adds r0, r3, #0
	b _08000CAA
_08000CA0:
	adds r2, #0xc
	adds r3, #1
	cmp r3, r1
	blt _08000C96
_08000CA8:
	movs r0, #0
_08000CAA:
	pop {r4}
	pop {r1}
	bx r1
