	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldr r1, _081775D4 @ =0x00001012
	adds r0, r6, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r5, r0
	bge _081775CE
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r4, r6, r0
_081775B4:
	adds r0, r4, #0
	bl AuxSprite_Remove
	movs r1, #0x92
	lsls r1, r1, #1
	adds r4, r4, r1
	adds r5, #1
	ldr r1, _081775D4 @ =0x00001012
	adds r0, r6, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r5, r0
	blt _081775B4
_081775CE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081775D4: .4byte 0x00001012
